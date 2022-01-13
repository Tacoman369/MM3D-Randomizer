#pragma once

#include <3ds.h>

#include <array>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <string_view>
#include <type_traits>
#include <variant>
#include <vector>

#include "../code/src/settings.h"
#include "category.hpp"
#include "cosmetics.hpp"
#include "debug.hpp"
#include "menu.hpp"
#include "pool_functions.hpp"

class Option {
public:
    static Option Bool(std::string name_, std::vector<std::string> options_, std::vector<std::string_view> optionDescriptions_, OptionCategory category_ = OptionCategory::Setting, u8 defaultOption_ = 0, bool defaultHidden_ = false) {
        return Option{false, std::move(name_), std::move(options_), std::move(optionDescriptions_), category_, defaultOption_, defaultHidden_};
    }

    static Option U8(std::string name_, std::vector<std::string> options_, std::vector<std::string_view> optionDescriptions_, OptionCategory category_  = OptionCategory::Setting, u8 defaultOption_ = 0, bool defaultHidden_ = false) {
        return Option{u8{0}, std::move(name_), std::move(options_), std::move(optionDescriptions_), category_, defaultOption_, defaultHidden_};
    }

    template <typename T>
    T Value() const {
        return std::get<T>(var);
    }

    template <typename T>
    bool Is(T other) const {
        static_assert(std::is_integral_v<T> || std::is_enum_v<T>,
                      "T must be an integral type or an enum.");

        if constexpr ((std::is_integral_v<T> && !std::is_same_v<bool, T>) || std::is_enum_v<T>) {
            return Value<u8>() == static_cast<u8>(other);
        } else {
            return Value<bool>() == static_cast<bool>(other);
        }
    }

    template <typename T>
    bool IsNot(T other) const {
        return !Is(other);
    }

    explicit operator bool() const {
        if (std::holds_alternative<bool>(var)) {
            return Value<bool>();
        } else {
            return Value<u8>() != 0;
        }
    }

    void SetOptions(std::vector<std::string> o) {
        options = std::move(o);
        SetToDefault();
    }

    size_t GetOptionCount() const {
        return options.size();
    }

    const std::string& GetName() const {
        return name;
    }

    const std::string& GetSelectedOptionText() const {
        return options[selectedOption];
    }

    void SetSelectedOptionText(std::string newText) {
        options[selectedOption] = std::move(newText);
    }

    bool IsDefaultSelected() {
      return selectedOption == defaultOption;
    }

    void SetToDefault() {
      SetSelectedIndex(defaultOption);
      hidden = defaultHidden;
    }

    std::string_view GetSelectedOptionDescription() const {
      //bounds checking
      if (selectedOption >= optionDescriptions.size()) {
        return optionDescriptions[optionDescriptions.size()-1];
      }
      return optionDescriptions[selectedOption];
    }

    u8 GetSelectedOptionIndex() const {
      return selectedOption;
    }

    void NextOptionIndex() {
        ++selectedOption;
    }

    void PrevOptionIndex() {
        --selectedOption;
    }

    void SanitizeSelectedOptionIndex() {
        if (selectedOption == options.size()) {
            selectedOption = 0;
        } else if (selectedOption == 0xFF) {
            selectedOption = static_cast<u8>(options.size() - 1);
        }
    }

    void SetVariable() {
      if (std::holds_alternative<bool>(var)) {
        var.emplace<bool>(selectedOption != 0);
      } else {
        var.emplace<u8>(selectedOption);
      }
    }

    void SetSelectedIndex(size_t idx) {
      selectedOption = idx;
      if (selectedOption >= options.size()) {
        printf("\x1b[30;0HERROR: Incompatible selection for %s\n", name.c_str());
        selectedOption = 0;
      }

      SetVariable();
    }

    void SetSelectedIndexByString(std::string newSetting) {
      using namespace Cosmetics;

      //Special case for custom cosmetic settings
      if (options.size() > CUSTOM_COLOR) {
        if (newSetting.compare(0, 8, CUSTOM_COLOR_PREFIX) == 0 && options[CUSTOM_COLOR].compare(0, 8, CUSTOM_COLOR_PREFIX) == 0) {
          SetSelectedIndex(CUSTOM_COLOR);
          SetSelectedOptionText(newSetting);
          return;
        }
      }

      for (size_t i = 0; i < options.size(); i++) {
        std::string settingName = options[i];
        if (settingName == newSetting) {
          SetSelectedIndex(i);
          return;
        }
      }
    }

    void Lock() {
      locked = true;
    }

    void Unlock() {
      locked = false;
    }

    bool IsLocked() const {
      return locked;
    }

    void Hide() {
      hidden = true;
    }

    void Unhide() {
      hidden = false;
    }

    bool IsHidden() const {
      return hidden;
    }

    bool IsCategory(OptionCategory category) const {
      return category == this->category;
    }

private:
    Option(u8 var_, std::string name_, std::vector<std::string> options_, std::vector<std::string_view> optionDescriptions_, OptionCategory category_, u8 defaultOption_, bool defaultHidden_)
          : var(var_), name(std::move(name_)), options(std::move(options_)), optionDescriptions(std::move(optionDescriptions_)), category(category_), defaultOption(defaultOption_), defaultHidden(defaultHidden_) {
        selectedOption = defaultOption;
        hidden = defaultHidden;
        SetVariable();
    }

    Option(bool var_, std::string name_, std::vector<std::string> options_, std::vector<std::string_view> optionDescriptions_, OptionCategory category_, u8 defaultOption_, bool defaultHidden_)
          : var(var_), name(std::move(name_)),  options(std::move(options_)), optionDescriptions(std::move(optionDescriptions_)), category(category_), defaultOption(defaultOption_), defaultHidden(defaultHidden_) {
        selectedOption = defaultOption;
        hidden = defaultHidden;
        SetVariable();
    }

  std::variant<bool, u8> var;
  std::string name;
  std::vector<std::string> options;
  std::vector<std::string_view> optionDescriptions;
  u8 selectedOption = 0;
  bool locked = false;
  bool hidden = false;
  OptionCategory category;
  u8 defaultOption = 0;
  bool defaultHidden = false;
};

enum class MenuType {
  MainMenu,
  SubMenu,
  Action,
};

class Menu {
  public:

    static Menu SubMenu(std::string name_, std::vector<Option *>* settingsList_, bool printInSpoiler_ = true) {
      return Menu{std::move(name_), MenuType::SubMenu, std::move(settingsList_), OPTION_SUB_MENU, printInSpoiler_};
    }

    static Menu SubMenu(std::string name_, std::vector<Menu *>* itemsList_, bool printInSpoiler_ = true) {
      return Menu{std::move(name_), MenuType::SubMenu, std::move(itemsList_), SUB_MENU, printInSpoiler_};
    }

    static Menu Action(std::string name_, u8 mode_) {
      return Menu{std::move(name_), MenuType::Action, std::move(mode_)};
    }

    Menu(std::string name_, MenuType type_, std::vector<Option *>* settingsList_, u8 mode_, bool printInSpoiler_ = true)
        : name(std::move(name_)), type(type_), settingsList(std::move(settingsList_)), mode(mode_), printInSpoiler(printInSpoiler_) {}

    Menu(std::string name_, MenuType type_, std::vector<Menu *>* itemsList_, u8 mode_, bool printInSpoiler_ = true)
        : name(std::move(name_)), type(type_), itemsList(std::move(itemsList_)), mode(mode_), printInSpoiler(printInSpoiler_) {}

    Menu(std::string name_, MenuType type_, u8 mode_)
        : name(std::move(name_)), type(type_), mode(mode_) {}

    std::string name;
    MenuType type;
    std::vector<Option *>* settingsList;
    std::vector<Menu *>* itemsList;
    u8 mode;
    u16 menuIdx = 0;
    int selectedSetting = 0;
    bool printInSpoiler = true;
};

namespace Settings {
  void UpdateSettings();
  SettingsContext FillContext();
  void InitSettings();
  void SetDefaultSettings();
  void RandomizeAllSettings(const bool selectOptions = false);
  void ForceChange(u32 kDown, Option* currentSetting);
  const std::vector<Menu*> GetAllMenus();


  extern std::string seed;
  extern std::string version;
  extern std::array<u8, 5> hashIconIndexes;
  
  //Logic Sttings
  extern Option Logic;
  extern Option LocationsReachable;
  extern std::vector<Option*> logicOptions;
  extern Option LogicTrick;
 
  //Trick Settings
  extern Option ToggleAllTricks;
  extern Option LogicGrottosWithoutAgony;
  extern std::vector<Option*> trickOptions;

  //Starting Inventory
  extern Option StartingConsumables;
  extern Option StartingMaxRupees;
  extern Option StartingNutCapacity;
  extern Option StartingBombBag;
  extern Option StartingBombchus;
  extern Option StartingBow;
  extern Option StartingFireArrows;
  extern Option StartingIceArrows;
  extern Option StartingLightArrows;
  extern Option StartingLensOfTruth;
  extern Option StartingMagicBean;
  extern Option StartingHookshot;
  extern Option StartingBottle1;
  extern Option StartingBottle2;
  extern Option StartingBottle3;
  extern Option StartingBottle4;
  extern Option StartingBottle5;
  extern Option StartingBottle6;
  extern Option StartingBottle7;
  extern Option StartingOcarina;
  extern Option StartingOathToOrder;
  extern Option StartingEponasSong;
  extern Option StartingInvertedSong;
  extern Option StartingDoubleTime;
  extern Option StartingSongOfTime;
  extern Option StartingSongOfStorms;
  extern Option StartingSonataOfAwakening;
  extern Option StartingGoronsLullaby;
  extern Option StartingNewWaveBossaNova;
  extern Option StartingElegyOfEmptiness;
  extern Option StartingSongOfHealing;
  extern Option StartingSongOfSoaring;
  extern Option StartingKokiriSword;
  extern Option StartingGreatFairySword;
  extern Option StartingHerosShield;
  extern Option StartingMirrorShield;
  extern Option StartingMagicMeter;
  extern Option StartingWallet;
  extern Option StartingDoubleDefense;
  extern Option StartingHealth;
  extern Option StartingOdolwaRemains;
  extern Option StartingGohtRemains;
  extern Option StartingGyorgRemains;
  extern Option StartingTwinmoldRemains;
  extern Option StartingSwampToken;
  extern Option StartingOceanToken;
  extern std::vector<Option*> startingInventoryOptions;

  //Excluded Locations
  extern std::vector<Option*> excludeLocationsOptions;

  //Shuffle Dungeon Items
  extern Option RandomizeDungeon;
  extern Option MapsAndCompasses;
  extern Option Keysanity;
  extern Option BossKeysanity;
  extern Option StrayFairysanity;
  extern Option ShuffleRewards;
  extern Option ShuffleMagicBeans;
  extern Option ShuffleKokiriSword;
//  extern Option Shopsanity;
//  extern Option Tokensanity;
//  extern Option Scrubsanity;
//  extern Option ShuffleCows;
//  extern Option ShuffleOcarinas;
  extern std::vector<Option*> shuffleItemOptions;

  //Other Settings
  extern Option ShuffleSongs;
  extern Option GossipStoneHints; 
  extern Option ClearerHints;
  extern Option HintDistribution;
 /*extern Option DamageMultiplier;
  extern Option ChestAnimations;
  extern Option ChestSize;*/
  extern Option ChangeOverworldItems;
  extern Option GenerateSpoilerLog;
  extern Option IngameSpoilers;
  extern Option MenuOpeningButton;
  extern Option RandomTrapDmg;
  extern std::vector<Option*>otherSettingsOptions;

  //Gimmicks
  extern Option ItemPoolValue;
  extern Option IceTrapValue;
  extern Option RemoveDoubleDefense;
  extern Option BlastMaskCooldown;
  extern Option UnderwaterOcarina;
  extern Option FierceDietyAnywhere;
  extern std::vector<Option*>gimmickOptions;

  //Comfort||Timesaver Options
  
  extern Option SkipMinigamePhases;
  extern Option FastLabFish;
  extern Option FastBank;
  extern Option FastDogRace;
  extern Option GoodDampeRNG;
  extern Option IncreasePushSpeed;
  extern Option FastArrowSwitch;
  extern Option FastElegyStatues;
  extern Option SkipSongReplays;

  //Cosmetics
  
  extern Option CustomTunicColors;
  extern Option ChildTunicColor;
  extern std::string finalChildTunicColor;

  extern Option ColoredKeys;
  extern Option ColoredBossKeys;
//  extern Option ShuffleMusic;
//  extern Option ShuffleBGM;
//  extern Option ShuffleFanfares;
//  extern Option ShuffleOcaMusic;
  extern std::vector<Option*>cosmeticOptions;

  //Glitches
  extern Option FakeGlitch;
  extern std::vector<Option*>glitchOptions;
  
  //Presets
  extern Menu loadSettingPreset;
  extern Menu saveSettingPreset;
  extern Menu deleteSettingsPreset;
  extern Menu resetToDefaultSettings;
  extern std::vector<Menu*>settingsPresetItems;

  //detailed Logic options submenu
  extern Menu logicSettings;
  extern Menu tricks;
  extern Menu startingInventory;
  extern Menu excludeLocations;
  extern Menu glitchSettings;
  extern Menu itemSettings;
  extern Menu otherSettings;
  
  //Main Menu
  extern std::vector<Menu *> mainSettingsOptions;
  extern Menu mainSettings;
  extern Menu gimmicks;
  extern Menu timeSaverSettings;
  extern Menu settingsPresets;
  extern Menu cosmetics;
  extern Menu generateRandomizer;
  extern std::vector<Menu *> mainMenu;


  extern Option LinksPocketItem;
  //extern bool ShuffleInteriorEntrances;
  //extern bool ShuffleSpecialIndoorEntrances;

  extern u32 LinksPocketRewardBitMask;
  extern std::array<u32, 9> rDungeonRewardOverrides;

  extern u8 PlayOption;
}
  

