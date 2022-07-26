#include "settings.hpp"

#include <unistd.h>

#include "cosmetics.hpp"
#include "dungeon.hpp"
#include "fill.hpp"
#include "item_location.hpp"
//#include "music.hpp"
#include "random.hpp"
#include "version.hpp"
#include "setting_descriptions.hpp"
#include "keys.hpp"

using namespace Cosmetics;
using namespace Dungeon;
using namespace rnd;
//using namespace Music;

namespace Settings {
  std::string seed;
  std::string version = RANDOMIZER_VERSION "-" COMMIT_NUMBER;
  std::array<u8, 5> hashIconIndexes;


  std::vector<std::string> bottleOptions = { "None", "Empty Bottle", "Red Potion", "Green Potion", "Blue Potion", "Fairy", "Fish", "Milk", "Bugs", "Big Poe", "Half Milk", "Poe" };
  std::vector<std::string> healthOptions = { "3 hearts",  "4 hearts",  "5 hearts",  "6 hearts",  "7 hearts",  "8 hearts",  "9 hearts", "10 hearts", "11 hearts", "12 hearts",
                                            "13 hearts", "14 hearts", "15 hearts", "16 hearts", "17 hearts", "18 hearts", "19 hearts", "20 hearts" };//,  "1 heart",   "2 hearts"}; // TODO: logic for lower health

  //Function to avoid accidentally naming the options wrong, as logic.cpp requires these exact names
  std::vector<std::string> GlitchDifficultyOptions(u8 enabledDifficulties) {
      static constexpr std::array glitchDifficulties{ "Novice", "Intermediate", "Advanced", "Expert", "Hero" };

      std::vector<std::string> selectableDifficulties;
      selectableDifficulties.push_back("Disabled");
      for (size_t i = 0; i < glitchDifficulties.size(); i++) {
          if ((enabledDifficulties >> i) & 1) {
              selectableDifficulties.push_back(glitchDifficulties[i]);
          }
      }

      return selectableDifficulties;
  }
  //                                Setting name,              Options,                                                                     Setting Descriptions (assigned in setting_descriptions.cpp)                                                 Category (default: Setting),Default index (default: 0), Default hidden (default: false)
  Option LinksPocketItem = Option::U8("Link's Pocket", { "Dungeon Reward", "Advancement", "Anything", "Nothing" }, { linksPocketDungeonReward, linksPocketAdvancement, linksPocketAnything, linksPocketNothing });

  /*MAIN SETTINGS*/
  
  //Mode/Logic Settings
  Option Logic = Option::U8("Logic", { "Glitchless", "No Logic", "Vanilla", "Glitched" }, { logicGlitchless, logicNoLogic, logicVanilla, logicGlitched });
  Option LocationsReachable = Option::Bool("All Locations Reachable", { "Off", "On" }, { locationsReachableDesc }, OptionCategory::Setting, 1); //All Locations Reachable On
  std::vector<Option*> logicOptions = {
    &Logic,
    &LocationsReachable
  };
  
  //TODO MM3D LOGIC TRICKS
  //Function to make defining logic tricks easier to read
  /*Option LogicTrick(std::string setting, std::string_view description) {
      return Option::Bool(setting, { "Disabled", "Enabled" }, { description });
  };*/
  
  //Detailed Logic Tricks                               ---------------------
  Option ToggleAllTricks                  = Option::U8("All Tricks", {"None", "Novice", "Intermediate", "Expert"},  {ToggleLogicNoneDesc, ToggleLogicNoviceDesc, ToggleLogicIntermediateDesc, ToggleLogicExpertDesc},                                           OptionCategory::Toggle, 0);
  //Option LogicGrottosWithoutAgony         = LogicTrick(" Grotto Access\n   w/o Shard of Agony",       LogicGrottosWithoutAgonyDesc);
  std::vector<Option *> trickOptions = {
    &ToggleAllTricks
    //&LogicGrottosWithoutAgony,
   };

  //Starting Inventory Toggles
  Option StartingConsumables = Option::Bool("Start with Consumables", { "No",               "Yes" }, { startWithConsumablesDesc });
  Option StartingMaxRupees = Option::Bool("Start with Max Rupees", { "No",               "Yes" }, { startWithMaxRupeesDesc });
  Option StartingInventoryToggle = Option::U8("Inventory", { "All Off",          "All On",           "Choose" }, { "" });
  Option StartingNutCapacity = Option::U8("  Deku Nuts", { "20 Deku Nuts",     "30 Deku Nuts",     "40 Deku Nuts" }, { "" });
  Option StartingOcarina = Option::U8("  Ocarina", { "None",             "Fairy Ocarina",    "Ocarina of Time" }, { "" });
  Option StartingBombBag = Option::U8("  Bomb Bag", { "None",             "Bomb Bag 20",      "Bomb Bag 30",      "Bomb Bag 40" }, { "" });
  Option StartingBombchus = Option::U8("  Bombchus", { "None",             "Bombchus" }, { "" });
  Option StartingHookshot = Option::U8("  Hookshot", { "None",             "Hookshot",         "Longshot" }, { "" });
  Option StartingBow = Option::U8("  Bow", { "None",             "Bow + Quiver 30",  "Bow + Quiver 40",  "Bow + Quiver 50" }, { "" });
  Option StartingFireArrows = Option::U8("  Fire Arrow", { "None",             "Fire Arrow" }, { "" });
  Option StartingIceArrows = Option::U8("  Ice Arrow", { "None",             "Ice Arrow" }, { "" });
  Option StartingLightArrows = Option::U8("  Light Arrow", { "None",             "Light Arrow" }, { "" });
  Option StartingLensOfTruth = Option::U8("  Lens of Truth", { "None",             "Lens of Truth" }, { "" });
  Option StartingMagicBean = Option::U8("  Magic Beans", { "None",             "Magic Beans" }, { "" });
  Option StartingBottle1 = Option::U8("  Bottle Slot 1", bottleOptions, { "" });
  Option StartingBottle2 = Option::U8("  Bottle Slot 2", bottleOptions, { "" });
  Option StartingBottle3 = Option::U8("  Bottle Slot 3", bottleOptions, { "" });
  Option StartingBottle4 = Option::U8("  Bottle Slot 4", bottleOptions, { "" });
  Option StartingBottle5 = Option::U8("  Bottle Slot 5", bottleOptions, { "" });
  Option StartingBottle6 = Option::U8("  Bottle Slot 6", bottleOptions, { "" });
  Option StartingBottle7 = Option::U8("  Bottle Slot 7", bottleOptions, { "" });
  Option StartingBottle8 = Option::U8("  Bottle Slot 8", bottleOptions, { "" });
  Option StartingSongsToggle = Option::U8("Ocarina Songs", { "All Off",          "All On",           "Choose" }, { "" });
  Option StartingOathToOrder = Option::U8("  Oath To Order", { "None",             "Oath to Order" }, { "" });
  Option StartingEponasSong = Option::U8("  Epona's Song", { "None",             "Epona's Song" }, { "" });
//  Option StartingInvertedSong = Option::U8("  Inverted Song of Time", { "None",             "I. Song of Time" }, { "" });
//  Option StartingDoubleSong = Option::U8("  Song of Double Time", { "None",             "Song of D. Time" }, { "" });
//  Option StartingSongOfTime = Option::U8("  Song of Time", { "None",             "Song of Time" }, { "" });
  Option StartingSongOfStorms = Option::U8("  Song of Storms", { "None",             "Song of Storms" }, { "" });
  Option StartingSonataOfAwakening = Option::U8("  Sonata of Awakening", { "None",             "Sonata of A." }, { "" });
  Option StartingGoronsLullaby = Option::U8("  Gorons Lullaby", { "None",             "Gorons Lullaby" }, { "" });
  Option StartingNewWaveBossaNova = Option::U8("  New Wave Bossa Nova", { "None",             "New Wave Bossa Nova" }, { "" });
  Option StartingElegyOfEmptiness = Option::U8("  Elegy of Emptiness", { "None",             "Elegy of Emptiness" }, { "" });
  Option StartingSongOfHealing = Option::U8("  Song of Healing", { "None",             "Song of Healing" }, { "" });
  Option StartingSongOfSoaring = Option::U8("  Song of Soaring", { "None",             "Song of Soaring" }, { "" });
  Option StartingUpgradesToggle = Option::U8("Equipment & Upgrades", { "All Off",          "All On",           "Choose" }, { "" });
  Option StartingKokiriSword = Option::U8("  Kokiri Sword", { "None",             "Kokiri Sword" }, { "" });
  Option StartingGreatFairySword = Option::U8("  Great Fairy Sword", { "None",             "Great Fairys Sword" }, { "" });
  Option StartingHerosShield = Option::U8("  Hero's Shield", { "None",             "Hero's Shield" }, { "" });
  Option StartingMirrorShield = Option::U8("  Mirror Shield", { "None",             "Mirror Shield" }, { "" });
  Option StartingWallet = Option::U8("  Wallet Upgrade", { "None",             "Adult's Wallet",   "Giant's Wallet" ,  "Tycoon's Wallet" }, { "" });
  Option StartingHealth = Option::U8("  Health", healthOptions, { "" });
  Option StartingMagicMeter = Option::U8("  Magic Meter", { "None",             "Single Magic",     "Double Magic" }, { "" });
  Option StartingDoubleDefense = Option::U8("  Double Defense", { "None",             "Double Defence" }, { "" });
  Option StartingQuestToggle = Option::U8("Quest Items", { "All Off",          "All On",           "Choose" }, { "" });
  Option StartingOdolwaRemains = Option::U8("  Odolwa's Remains", { "None",             "Odolwa's R." }, { "" });
  Option StartingGohtRemains = Option::U8("  Goht's Remains", { "None",             "Goht's R." }, { "" });
  Option StartingGyorgRemains = Option::U8("  Gyorg's Remains", { "None",             "Gyorg's R." }, { "" });
  Option StartingTwinmoldRemains = Option::U8("  Twinmold's Remains", { "None",             "TwinMold's R." }, { "" });
  Option StartingSwampToken = Option::U8("Swamp Skulltula Tokens", {/*Options 0-30 defined in InitSettings()*/ }, { "" }, OptionCategory::Setting, 0, false);
  Option StartingOceanToken = Option::U8("Ocean Skulltula Tokens", {/*Options 0-30 defined in InitSettings()*/ }, { "" }, OptionCategory::Setting, 0, false);
  //Starting Masks 
  Option StartingMaskToggle = Option::U8("Masks", { "All Off",          "All On",           "Choose" }, { "" });
  Option StartingDekuMask = Option::U8("  Deku Mask", { "None",             "Deku M." }, { "" });
  Option StartingGoronMask = Option::U8("  Goron Mask", { "None",             "Goron M." }, { "" });
  Option StartingZoraMask = Option::U8("  Zora Mask", { "None",             "Zora M." }, { "" });
  Option StartingBunnyHood = Option::U8("  Bunny Hood", { "None",             "Bunny H." }, { "" });
  Option StartingKeatonMask = Option::U8("  Keaton Mask", { "None",             "Keaton M." }, { "" });
  Option StartingPostmanHat = Option::U8("  Postman's Hat", { "None",             "Postman's H." }, { "" });
  Option StartingAllNightMask = Option::U8("  All-Night Mask", { "None",             "All-Night M." }, { "" });
  Option StartingBlastMask = Option::U8("  Blast Mask", { "None",             "Blast M." }, { "" });
  Option StartingStoneMask = Option::U8("  Stone Mask", { "None",             "Stone M." }, { "" });
  Option StartingGreatFairyMask = Option::U8("  Great Fairys Mask", { "None",             "G.F M." }, { "" });
  Option StartingBremenMask = Option::U8("  Bremen Mask", { "None",             "Bremen M." }, { "" });
  Option StartingDonGeroMask = Option::U8("  Don Gero's Mask", { "None",             "DonGero M." }, { "" });
  Option StartingMaskOfScents = Option::U8("  Mask of Scents", { "None",             "Scents M." }, { "" });
  Option StartingRomanisMask = Option::U8("  Romani's Mask", { "None",             "Romani M." }, { "" });
  Option StartingCircusLeaderMask = Option::U8("  Circus Leader's Mask", { "None",             "T.L M." }, { "" });
  Option StartingKafeiMask = Option::U8("  Kafei Mask", { "None",             "Kafei M." }, { "" });
  Option StartingCouplesMask = Option::U8("  Couples Mask", { "None",             "Couples M." }, { "" });
  Option StartingKamarosMask = Option::U8("  Kamaro's Mask", { "None",             "Kamaros M." }, { "" });
  Option StartingGibdosMask = Option::U8("  Gibdos Mask", { "None",             "Gibdos M." }, { "" });
  Option StartingCaptainsHat = Option::U8("  Captain's Mask", { "None",             "Captains M." }, { "" });
  Option StartingGiantsMask = Option::U8("  Giants Mask", { "None",             "Giants M." }, { "" });
  Option StartingFierceDietyMask = Option::U8("  Fierce Diety Mask", { "None",             "F.D M." }, { "" });
  Option StartingMaskOfTruth = Option::U8("  Mask of Truth", { "None",             "Truth M." }, { "" });

  Option StartingStickCapacity = Option::U8(" Stick Capacity", { "10 Sticks", "20 Sticks", "30 Sticks" }, { "" });
  Option StartingPictographBox = Option::U8(" Pictograph Box", { "None", "PictoBox" }, { "" });
  Option StartingPowderKeg = Option::U8(" Powder Keg", { "None", "Powder Keg" }, { "" });
  Option StartingRazorSword = Option::U8(" Razor Sword", { "None", "R. Sword" }, { "" });
  Option StartingGildedSword = Option::U8(" Gilded Sword", { "None", "G. Sword" }, { "" });

  std::vector<Option*> startingInventoryOptions = {
    &StartingConsumables,
    &StartingMaxRupees,
    &StartingInventoryToggle,
    &StartingNutCapacity,
    &StartingOcarina,
    &StartingBombBag,
    &StartingBombchus,
    &StartingHookshot,
    &StartingBow,
    &StartingFireArrows,
    &StartingIceArrows,
    &StartingLightArrows,
    &StartingLensOfTruth,
    &StartingMagicBean,
    &StartingBottle1,
    &StartingBottle2,
    &StartingBottle3,
    &StartingBottle4,
    &StartingBottle5,
    &StartingBottle6,
    &StartingBottle7,
    &StartingMaskToggle,
    &StartingDekuMask,
    &StartingGoronMask,
    &StartingZoraMask,
    &StartingBunnyHood,
    &StartingKeatonMask,
    &StartingPostmanHat,
    &StartingAllNightMask,
    &StartingBlastMask,
    &StartingStoneMask,
    &StartingGreatFairyMask,
    &StartingBremenMask,
    &StartingDonGeroMask,
    &StartingMaskOfScents,
    &StartingRomanisMask,
    &StartingCircusLeaderMask,
    &StartingKafeiMask,
    &StartingCouplesMask,
    &StartingKamarosMask,
    &StartingGibdosMask,
    &StartingCaptainsHat,
    &StartingGiantsMask,
    &StartingFierceDietyMask,
    &StartingMaskOfTruth,
    &StartingSongsToggle,
    &StartingOathToOrder,
    &StartingEponasSong,
    &StartingSongOfStorms,
    &StartingSonataOfAwakening,
    &StartingGoronsLullaby,
    &StartingNewWaveBossaNova,
    &StartingElegyOfEmptiness,
    &StartingSongOfHealing,
    &StartingSongOfSoaring,
    &StartingUpgradesToggle,
    &StartingKokiriSword,
    &StartingGreatFairySword,
    &StartingHerosShield,
    &StartingMirrorShield,
    &StartingWallet,
    &StartingHealth,
    &StartingMagicMeter,
    &StartingDoubleDefense,
    &StartingQuestToggle,
    &StartingOdolwaRemains,
    &StartingGohtRemains,
    &StartingGyorgRemains,
    &StartingTwinmoldRemains,
    &StartingSwampToken,
    &StartingOceanToken,
    
  };

  //Excluded Locations (Individual definitions made in ItemLocation class)
  std::vector<Option*> excludeLocationsOptions = {};

  //Shuffle Dungeon Items
  Option RandomizeDungeon    = Option::U8("Randomize Settings", {"No","Yes"}, {dungeonRandomize},OptionCategory::Toggle);
  Option MapsAndCompasses = Option::U8("Maps/Compasses", { "Start With", "Vanilla", "Own Dungeon", "Any Dungeon", "Overworld", "Anywhere" },
      { mapCompassStartWith, mapCompassVanilla, mapCompassOwnDungeon, mapCompassAnyDungeon, mapCompassOverworld, mapCompassAnywhere }, OptionCategory::Setting, (u8)MapsAndCompassesSetting::MAPSANDCOMPASSES_VANILLA);

  Option Keysanity = Option::U8("Small Keys", { "Start With", "Vanilla", "Own Dungeon", "Any Dungeon", "Overworld", "Anywhere" },
      { smallKeyStartWith, smallKeyVanilla, smallKeyOwnDungeon, smallKeyAnyDungeon, smallKeyOverworld, smallKeyAnywhere }, OptionCategory::Setting, (u8)KeysanitySetting::KEYSANITY_VANILLA);

  Option BossKeysanity = Option::U8("Boss Keys", { "Start With", "Vanilla", "Own Dungeon", "Any Dungeon", "Overworld", "Anywhere" },
      { bossKeyStartWith, bossKeyVanilla, bossKeyOwnDungeon, bossKeyAnyDungeon, bossKeyOverworld, bossKeyAnywhere }, OptionCategory::Setting, (u8)BossKeysanitySetting::BOSSKEYSANITY_VANILLA);
  
  Option StrayFairysanity = Option::U8("Stray Fairies", { "Start With", "Vanilla", "Own Dungeon", "Any Dungeon", "Overworld", "Anywhere" },
      { fairyVanilla, fairyStartWith, fairyOwnDungeon, fairyAnyDungeon, fairyOverworld, fairyAnywhere }, OptionCategory::Setting, (u8)StrayFairySanitySetting::STRAYFAIRYSANITY_VANILLA);
 
  Option ShuffleRewards = Option::U8("Shuffle Dungeon Rewards", { "End of Dungeons", "Any Dungeon", "Overworld", "Anywhere" }, { shuffleRewardsEndOfDungeon, shuffleRewardsAnyDungeon, shuffleRewardsOverworld, shuffleRewardsAnywhere });
  Option ShuffleMagicBeans = Option::Bool("Shuffle Magic Beans", { "Off", "On" }, { magicBeansDesc });
  Option ShuffleKokiriSword = Option::Bool("Shuffle Kokiri Sword", { "Off", "On" }, { kokiriSwordDesc });
  Option Shopsanity             = Option::U8("Shopsanity",             {"Off", "0", "1", "2", "3", "4", "Random"},                        {shopsOff, shopsZero, shopsOne, shopsTwo, shopsThree, shopsFour, shopsRandom});
  Option Tokensanity            = Option::U8("Tokensanity",            {"Off", "Dungeons", "Overworld", "All Tokens"},                    {tokensOff, tokensDungeon, tokensOverworld, tokensAllTokens});
  Option Scrubsanity            = Option::U8("Scrub Shuffle",          {"Off", "Affordable", "Expensive", "Random Prices"},               {scrubsOff, scrubsAffordable, scrubsExpensive, scrubsRandomPrices});
  //Option ShuffleCows            = Option::Bool("Shuffle Cows",           {"Off", "On"},                                                     {shuffleCowsDesc});
  //Option ShuffleOcarinas        = Option::Bool("Shuffle Ocarinas",       {"Off", "On"},                                                     {ocarinasDesc});
  Option ShuffleChests = Option::Bool("Shuffle Chest Items", {"Vanilla", "Random"}, { shuffleChestItemsVanilla, shuffleChestItemsRandom }, OptionCategory::Toggle, (u8)ShuffleChestsSetting::SHUFFLECHESTS_RANDOM);
  Option ShuffleGFRewards = Option::U8("Shuffle Great Fairy Rewards", { "Vanilla", "Great Fairies", "Anywhere" }, { shuffleGFVanilla, shuffleGFSelf, shuffleGFAnywhere }, OptionCategory::Setting, (u8)GreatFairyRewardShuffleSetting::GFREWARDSHUFFLE_VANILLA);
  Option ShuffleMerchants = Option::Bool("Shuffle Merchants", { "Off", "On" }, { shuffleMerchantsDesc });

  std::vector<Option*> shuffleItemOptions = {
      &ShuffleChests,
         //&RandomizeDungeon,
         //&MapsAndCompasses,
         //&Keysanity,
         //&BossKeysanity,
         //&ShuffleRewards,
         //&StrayFairysanity,
         //&ShuffleKokiriSword,
         //&ShuffleMagicBeans,
         //&Shopsanity,
         //&Tokensanity,
         //&Scrubsanity,
         //&ShuffleCows,
         //&ShuffleOcarinas,
  };
  Option ShuffleSongs = Option::U8("Shuffle Songs", { "Song Locations", "Dungeon Rewards", "Anywhere" }, { songsSongLocations, songsDungeonRewards, songsAllLocations });
  Option GossipStoneHints = Option::U8("Gossip Stone Hints", { "No Hints", "Need Nothing", "Mask of Truth", "Shard of Agony" }, { gossipStonesHintsDesc }, OptionCategory::Setting, (u8)GossipStoneHintsSetting::HINTS_NEED_NOTHING);
  Option ClearerHints = Option::Bool("  Clearer Hints", { "Off", "On" }, { clearerHintsDesc });
  Option HintDistribution = Option::U8("  Hint Distribution", { "Useless", "Balanced", "Strong", "Very Strong" }, { uselessHintsDesc, balancedHintsDesc, strongHintsDesc, veryStrongHintsDesc }, OptionCategory::Setting, 1); // Balanced
  Option DamageMultiplier    = Option::U8  ("Damage Multiplier",      {"x1/2", "x1", "x2", "x4", "x8", "x16", "OHKO"},                        {damageMultiDesc},                                                                                                OptionCategory::Setting,   (u8)DamageMultiplierSetting::DAMAGEMULTIPLIER_DEFAULT);
  Option ChestAnimations     = Option::Bool("Chest Animations",       {"Always Fast", "Match Contents"},                                      {chestAnimDesc});
  Option ChestSize           = Option::Bool("Chest Size and Color",   {"Vanilla", "Match Contents"},                                          {chestSizeDesc});
  Option ChangeOverworldItems = Option::Bool("Change Overworld Items", { "Vanilla", "Match Contents" }, { changeOverworldItemsDesc });
  Option GenerateSpoilerLog = Option::Bool("Generate Spoiler Log", { "No", "Yes" }, { "", "" }, OptionCategory::Setting, 1); // On
  Option IngameSpoilers = Option::Bool("Ingame Spoilers", { "Hide", "Show" }, { ingameSpoilersHideDesc, ingameSpoilersShowDesc });
  Option MenuOpeningButton = Option::U8("Open Info Menu with", { "Select","Start","D-Pad Up","D-Pad Down","D-Pad Right","D-Pad Left", }, { menuButtonDesc });
  Option RandomTrapDmg = Option::U8("Random Trap Damage", { "Off", "Basic", "Advanced" }, { randomTrapDmgDesc, basicTrapDmgDesc, advancedTrapDmgDesc });
  Option RsDurability = Option::U8("Razor Sword Durability", { "Vanilla", "Infinite" }, { rsDurabilityVanilla, });
  
  std::vector<Option*>otherSettingsOptions = {
      &ShuffleSongs,
      &GossipStoneHints,
      &ClearerHints,
      &HintDistribution,
      &DamageMultiplier,
      &ChestAnimations,
      &ChestSize,
      &ChangeOverworldItems,
      &GenerateSpoilerLog,
      &IngameSpoilers,
      &MenuOpeningButton,
      &RandomTrapDmg,
  };
  
  /*GIMMICKS*/

  Option ItemPoolValue = Option::U8("Item Pool", { "Plentiful", "Balanced", "Scarce", "Minimal" }, { itemPoolPlentiful, itemPoolBalanced, itemPoolScarce, itemPoolMinimal }, OptionCategory::Setting, (u8)ItemPoolSetting::ITEMPOOL_BALANCED);
  Option IceTrapValue = Option::U8("Ice Traps", { "Off", "Normal", "Extra", "Mayhem", "Onslaught" }, { iceTrapsOff, iceTrapsNormal, iceTrapsExtra, iceTrapsMayhem, iceTrapsOnslaught }, OptionCategory::Setting, (u8)IceTrapSetting::ICETRAPS_NORMAL);
  Option RemoveDoubleDefense = Option::Bool("Remove Double Defense", { "No", "Yes" }, { removeDDDesc });
  Option BlastMaskCooldown = Option::U8("Blast Mask Cooldown", { "Default", "Instant", "Very Short", "Short", "Long", "Very Long" }, { blastDefault, blastInstant, blastVeryShort, blastShort, blastLong, blastVeryLong });
  Option UnderwaterOcarina = Option::Bool("Underwater Ocarina", { "No","Yes" }, { underwaterOcarinaDesc }, OptionCategory::Toggle);
  Option FierceDietyAnywhere = Option::Bool("Fierce Diety Anywhere", { "No","Yes" }, { fierceDietyAnywhereDesc }, OptionCategory::Toggle);
  
  Option ProgressiveGildedSword = Option::Bool("Progressive Gilded Sword", { "Off", "On" }, { progressiveGildedSwordDesc });
  Option StartingSpin = Option::U8("Starting Spin", { "Vanilla", "Upgraded" }, { startingSpinDesc });
  Option AmmoDrops = Option::U8("Ammo Drops", { "Off", "On" }, { ammoDropDesc });
  Option HeartDropRefills = Option::U8("Heart Drops", { "Off", "On" }, { heartDropDesc });
  Option BombchusInLogic = Option::U8("Bombchus In Logic", { "Off", "On" }, { bombchuInLogicDesc });

  std::vector<Option*> gimmickOptions = {
     &ItemPoolValue,
     &IceTrapValue,
     &RemoveDoubleDefense,
     &BlastMaskCooldown,
     &UnderwaterOcarina,
     &FierceDietyAnywhere,
     &ProgressiveGildedSword,
     &StartingSpin,
     &AmmoDrops,
     &HeartDropRefills,
     &BombchusInLogic,
  };

  /*COMFORT*/
 
  //Timesaver Settings
  Option SkipMinigamePhases  = Option::Bool("Minigames repetitions",  {"Don't Skip", "Skip"},  {skipMinigamePhasesDesc});
  Option FastLabFish = Option::Bool("Fast Lab Fish", { "No", "Yes" }, { fastLabFishDesc });
  Option FastBank = Option::Bool("Fast Bank Rewards", { "No","Yes" }, { fastBankDesc });
  Option FastDogRace = Option::Bool("Fast Dog Race", { "No","Yes" }, { fastDogRaceDesc });
  Option GoodDampeRNG = Option::Bool("Good Dampe RNG", { "No","Yes" }, { goodDampeRNGDesc });
  Option IncreasePushSpeed = Option::Bool("Increased Push Speed", { "No", "Yes" }, { increasePushSpeedDesc });
  Option FastArrowSwitch = Option::Bool("Fast Arrow Switching", { "No", "Yes" }, { fastArrowSwitchDesc });
  Option FastElegyStatues = Option::Bool("Fast Elegy Statues", { "No", "Yes" }, { fastElegyStatuesDesc });
  Option SkipSongReplays = Option::U8("  Skip Song Replays", { "Don't Skip", "Skip (No SFX)", "Skip (Keep SFX)" },{skipSongReplaysDesc});
  Option SkipEponaRace = Option::Bool("Skip Epona Race", { "No", "Yes" }, { skipEponaRaceDesc });

  std::vector<Option *> timesaverOptions = {
    &SkipMinigamePhases,
    &FastLabFish,
    &FastBank,
    &FastDogRace,
    &GoodDampeRNG,
    &IncreasePushSpeed,
    &FastArrowSwitch,
    &FastElegyStatues,
    &SkipSongReplays,
  };

  /*TRIAL SKIPS*/
  Option OdolwaTrialSkip = Option::Bool("Odolwa Trial Skip", { "Don't Skip", "Skip" }, { odolwaTrialSkipDesc });
  Option GohtTrialSkip = Option::Bool("Goht Trial Skip", { "Don't Skip", "Skip" }, { gohtTrialSkipDesc });
  Option GyorgTrialSkip = Option::Bool("Gyorg Trial Skip", { "Don't Skip", "Skip" }, { gyorgTrialSkipDesc });
  Option TwinmoldTrialSkip = Option::Bool("Twinmold Trial Skip", { "Don't Skip", "Skip" }, { twinmoldTrialSkipDesc });

  std::vector<Option *> trialSkipOptions = {
      &OdolwaTrialSkip,
      &GohtTrialSkip,
      &GyorgTrialSkip,
      &TwinmoldTrialSkip,
  };

  /*Entrance Randomizer Stuff*/
  Option ShuffleDungeonEntrances = Option::Bool("Shuffle Dungeon Entrances", { "Off", "On" }, { shuffleDungeonEntrancesDesc });

  /*COSMETICS*/

  static std::vector<std::string> tunicOptions = {
    std::string(RANDOM_CHOICE_STR),
    std::string(RANDOM_COLOR_STR),
    std::string(CUSTOM_COLOR_STR),
    "Kokiri Green",
    "Goron Red",
    "Zora Blue",
    "Black",
    "White",
    "Azure Blue",
    "Vivid Cyan",
    "Light Red",
    "Fuchsia",
    "Purple",
    "Majora Purple",
    "Twitch Purple",
    "Magenta",
    "Violet",
    "Persian Rose",
    "Dirty Yellow",
    "Blush Pink",
    "Hot Pink",
    "Rose Pink",
    "Orange",
    "Gray",
    "Yellow",
    "Silver",
    "Beige",
    "Teal",
    "Blood Red",
    "Blood Orange",
    "Royal Blue",
    "NES Green",
    "Dark Green",
    "Lumen",
  };
  static std::vector<std::string_view> cosmeticDescriptions = {
    RANDOM_CHOICE_DESC,
    RANDOM_COLOR_DESC,
    CUSTOM_COLOR_DESC,
    "This will only affect the color on Link's model.",
  };

  Option CustomTunicColors          = Option::Bool("Custom Tunic Colors",    {"Off", "On"},   {""},  OptionCategory::Cosmetic);
  Option ChildTunicColor = Option::U8("   Tunic Color", { tunicOptions }, cosmeticDescriptions, OptionCategory::Cosmetic, 3); // Kokiri Green
  std::string finalChildTunicColor      = ChildTunicColor.GetSelectedOptionText();

  Option ColoredKeys =     Option::Bool("Colored Small Keys", {"Off", "On"}, {coloredKeysDesc}, OptionCategory::Cosmetic);
  Option ColoredBossKeys = Option::Bool("Colored Boss Keys",  {"Off", "On"}, {coloredBossKeysDesc},  OptionCategory::Cosmetic);

  static std::vector<std::string> fanfareOptions = {"Off", "Only Fanfares", "Fanfares +\n                         Ocarina Music"};
  static std::vector<std::string_view> fanfareDescriptions = {fanfaresOffDesc, onlyFanfaresDesc, fanfaresOcarinaDesc};
  //TO-DO MUSIC RANDO
//  Option ShuffleMusic =    Option::Bool("Shuffle Music",           {"Off", "On"},    {musicRandoDesc},                                                                                                                                                          OptionCategory::Cosmetic,               0); // Off
//  Option ShuffleBGM =      Option::Bool("  Shuffle BGM",           {"Off", "On"},    {shuffleBGMDesc},                                                                                                                                                          OptionCategory::Cosmetic,               1); // On
//  Option ShuffleFanfares = Option::U8  ("  Shuffle Fanfares",      {fanfareOptions}, {fanfareDescriptions},                                                                                                                                                     OptionCategory::Cosmetic,               1); // Fanfares only
//  Option ShuffleOcaMusic = Option::Bool("  Shuffle Ocarina Music", {"Off", "On"},    {shuffleOcaMusicDesc},                                                                                                                                                     OptionCategory::Cosmetic,               1); // On
  
//TO-DO Heart Color, Magic Color, Tatl Color
  std::vector<Option *> cosmeticOptions = {
    &CustomTunicColors,
    &ChildTunicColor,
    &ColoredKeys,
    &ColoredBossKeys,
 //   &ShuffleMusic,
 //   &ShuffleBGM,
 //   &ShuffleFanfares,
 //   &ShuffleOcaMusic,
  };

  /*To-Do Glitches*/
  Option FakeGlitch = Option::U8("Fake Glitch", { "Fake" }, { "This Is Here to not break things" });
  std::vector<Option *> glitchOptions = {
      &FakeGlitch,
  };

  Menu loadSettingsPreset       = Menu::Action("Load Settings Preset",       LOAD_PRESET);
  Menu saveSettingsPreset       = Menu::Action("Save Settings Preset",       SAVE_PRESET);
  Menu deleteSettingsPreset     = Menu::Action("Delete Settings Preset",     DELETE_PRESET);
  Menu resetToDefaultSettings   = Menu::Action("Reset to Default Settings",  RESET_TO_DEFAULTS);

  std::vector<Menu *> settingsPresetItems = {
    &loadSettingsPreset,
    &saveSettingsPreset,
    &deleteSettingsPreset,
    &resetToDefaultSettings,
  };

  //Main Settings Options Submenu
  Menu logicSettings    = Menu::SubMenu("Logic Options",     &logicOptions);
  Menu tricks = Menu::SubMenu("Logical Tricks", &trickOptions, false);
  Menu startingInventory = Menu::SubMenu("Starting Inventory", &startingInventoryOptions, false);
  Menu excludeLocations = Menu::SubMenu("Exclude Locations", &excludeLocationsOptions, false);
  Menu glitchSettings   = Menu::SubMenu("Glitch Options",    &glitchOptions, false);
  Menu itemSettings = Menu::SubMenu("Detailed Item Settings", &shuffleItemOptions);
  Menu otherSettings = Menu::SubMenu("Other Settings", &otherSettingsOptions, false);
  
  std::vector<Menu *> mainSettingsOptions = {
      &logicSettings,
      //&tricks,
      //&startingInventory,
      //&excludeLocations,
      //&glitchSettings,
      &itemSettings,
      //&otherSettings,
  };

  Menu mainSettings = Menu::SubMenu("Main Settings", &mainSettingsOptions);
  Menu gimmicks = Menu::SubMenu("Gimmicks", &gimmickOptions);
  Menu timeSaverSettings = Menu::SubMenu("Comfort", &timesaverOptions);
  Menu settingsPresets          = Menu::SubMenu("Settings Presets",           &settingsPresetItems);
  Menu cosmetics                = Menu::SubMenu("Cosmetic Settings",          &cosmeticOptions);
  Menu generateRandomizer       = Menu::Action ("Generate Randomizer",        GENERATE_MODE);

  //adding a menu with no options crashes, might fix later
  std::vector<Menu *> mainMenu = {
    &mainSettings,
    //&gimmicks,
    //&timeSaverSettings,
    //&cosmetics,
    &settingsPresets,
    &generateRandomizer,
  };

  //declared here, set in fill.cpp
  u32 LinksPocketRewardBitMask = 0;
  std::array<u32, 9> rDungeonRewardOverrides{};

  //declared here, set in menu.cpp
  u8 PlayOption;

  //Fills and returns a SettingsContext struct.
  //This struct is written to the code.ips patch and allows the game
  //to read what settings the player selected to make in game decisions.
    rnd::SettingsContext FillContext() {
    rnd::SettingsContext ctx = {};
    ctx.hashIndexes[0] = hashIconIndexes[0];
    ctx.hashIndexes[1] = hashIconIndexes[1];
    ctx.hashIndexes[2] = hashIconIndexes[2];
    ctx.hashIndexes[3] = hashIconIndexes[3];
    ctx.hashIndexes[4] = hashIconIndexes[4];

    ctx.logic                = Logic.Value<u8>();
    ctx.locationsReachable = (LocationsReachable) ? 1 : 0;

    ctx.shuffleDungeonEntrances = (ShuffleDungeonEntrances) ? 1 : 0;
    ctx.bombchusInLogic = (BombchusInLogic) ? 1 : 0;
    ctx.ammoDrops = (AmmoDrops) ? 1 : 0;
    ctx.heartDropRefill = (HeartDropRefills) ? 1 : 0;

    ctx.shuffleChests = (ShuffleChests) ? 1 : 0;
    ctx.shuffleRewards = ShuffleRewards.Value<u8>();
    ctx.shuffleGreatFairyRewards = ShuffleGFRewards.Value<u8>();
    ctx.linksPocketItem = LinksPocketItem.Value<u8>();
    ctx.shuffleSongs = ShuffleSongs.Value<u8>();
    ctx.tokensanity          = Tokensanity.Value<u8>();
    ctx.scrubsanity          = Scrubsanity.Value<u8>();
    ctx.shopsanity = Shopsanity.Value<u8>();
    ctx.shuffleMagicBeans = (ShuffleMagicBeans) ? 1 : 0;
    ctx.shuffleKokiriSword = (ShuffleKokiriSword) ? 1 : 0;
    ctx.shuffleMerchants = (ShuffleMerchants) ? 1 : 0;
    
    ctx.mapsAndCompasses = MapsAndCompasses.Value<u8>();
    ctx.keysanity = Keysanity.Value<u8>();
    ctx.bossKeysanity = BossKeysanity.Value<u8>();

    ctx.skipMinigamePhases = (SkipMinigamePhases) ? 1 : 0;
    ctx.skipEponaRace = (SkipEponaRace) ? 1 : 0;

    ctx.damageMultiplier     = DamageMultiplier.Value<u8>();
    ctx.gossipStoneHints = GossipStoneHints.Value<u8>();
    ctx.chestAnimations      = (ChestAnimations) ? 1 : 0;
    ctx.chestSize            = (ChestSize) ? 1 : 0;
    ctx.generateSpoilerLog = (GenerateSpoilerLog) ? 1 : 0;
    ctx.ingameSpoilers = (IngameSpoilers) ? 1 : 0;
    ctx.menuOpeningButton = MenuOpeningButton.Value<u8>();
    ctx.randomTrapDmg = RandomTrapDmg.Value<u8>();

    ctx.rsDurability = RsDurability.Value<u8>();

    ctx.itemPoolValue = ItemPoolValue.Value<u8>();
    ctx.iceTrapValue = IceTrapValue.Value<u8>();

    ctx.customTunicColors = (CustomTunicColors) ? 1 : 0;
    ctx.coloredKeys = (ColoredKeys) ? 1 : 0;
    ctx.coloredBossKeys = (ColoredBossKeys) ? 1 : 0;
    
    ctx.odolwaTrialSkip = (OdolwaTrialSkip) ? 1 : 0;
    ctx.gohtTrialSkip = (GohtTrialSkip) ? 1 : 0;
    ctx.gyorgTrialSkip = (GyorgTrialSkip) ? 1 : 0;
    ctx.twinmoldTrialSkip = (TwinmoldTrialSkip) ? 1 : 0;

    ctx.progressiveGildedSword = (ProgressiveGildedSword) ? 1 : 0;
    ctx.startingSpinSettting = (StartingSpin) ? 1 : 0;

    //Starting Inventory
    ctx.startingConsumables = (StartingConsumables) ? 1 : 0;
    ctx.startingMaxRupees = (StartingMaxRupees) ? 1 : 0;
    ctx.startingOcarina = StartingOcarina.Value<u8>();
    ctx.startingHerosBow = StartingBow.Value<u8>();
    ctx.startingFireArrows = StartingFireArrows.Value<u8>();
    ctx.startingIceArrows = StartingIceArrows.Value<u8>();
    ctx.startingLightArrows = StartingLightArrows.Value<u8>();
    ctx.startingBombBag = StartingBombBag.Value<u8>();
    ctx.startingBombchus = StartingBombchus.Value<u8>();
    ctx.startingStickCapacity = StartingStickCapacity.Value<u8>();
    ctx.startingNutCapacity = StartingNutCapacity.Value<u8>();
    ctx.startingMagicBean = StartingMagicBean.Value<u8>();
    ctx.startingPowderKeg = StartingPowderKeg.Value<u8>();
    ctx.startingPictographBox = StartingPictographBox.Value<u8>();
    ctx.startingLensOfTruth = StartingLensOfTruth.Value<u8>();
    ctx.startingHookshot = StartingHookshot.Value<u8>();
    ctx.startingGreatFairySword = StartingGreatFairySword.Value<u8>();
    ctx.startingBottle1 = StartingBottle1.Value<u8>();
    ctx.startingBottle2 = StartingBottle2.Value<u8>();
    ctx.startingBottle3 = StartingBottle3.Value<u8>();
    ctx.startingBottle4 = StartingBottle4.Value<u8>();
    ctx.startingBottle5 = StartingBottle5.Value<u8>();
    ctx.startingBottle6 = StartingBottle6.Value<u8>();
    ctx.startingBottle7 = StartingBottle7.Value<u8>();
    
    ctx.startingKokiriSword = StartingKokiriSword.Value<u8>();
    ctx.startingRazorSword = StartingRazorSword.Value<u8>();
    ctx.startingGildedSword = StartingGildedSword.Value<u8>();
    ctx.startingMagicMeter = StartingMagicMeter.Value<u8>();
    ctx.startingDoubleDefense = StartingDoubleDefense.Value<u8>();
    ctx.startingHealth        = (StartingHealth.Value<u8>() + 2) % 20 + 1;

    //TODO: 
    //startingQuestItems;
    //startingDungeonRewards;
    //startingEquipment;
    //startingUpgrades;
    /*ctx.toggleAllTricks = ToggleAllTricks.Value<u8>();
    //ctx.logicGrottosWithoutAgony = LogicGrottosWithoutAgony.Value<u8>();

    
    ctx.randomizeDungeon = (RandomizeDungeon) ? 1 : 0;
    ctx.strayFairysanity     = StrayFairysanity.Value<u8>();
    //    ctx.shuffleCows          = (ShuffleCows) ? 1 : 0;
    //    ctx.shuffleOcarinas      = (ShuffleOcarinas) ? 1 : 0;
    
    ctx.clearHints = (ClearerHints) ? 1 : 0;
    ctx.hintDistribution = HintDistribution.Value<u8>();
    ctx.changeOverworldItems = (ChangeOverworldItems) ? 1 : 0;
    
    ctx.removeDDValue = (RemoveDoubleDefense) ? 1 : 0;
    ctx.blastMaskCooldown = BlastMaskCooldown.Value<u8>();
    ctx.underwaterOcarina = (UnderwaterOcarina) ? 1 : 0;
    ctx.fierceDietyAnywhere = (FierceDietyAnywhere) ? 1 : 0;

    ctx.fastLabFish = (FastLabFish) ? 1 : 0;
    ctx.fastBank = (FastBank) ? 1 : 0;
    ctx.fastDogRace = (FastDogRace) ? 1 : 0;
    ctx.goodDampeRNG = (GoodDampeRNG) ? 1 : 0;
    ctx.increasePushSpeed = (IncreasePushSpeed) ? 1 : 0;
    ctx.fastArrowSwitch = (FastArrowSwitch) ? 1 : 0;
    ctx.fastElegyStatues = (FastElegyStatues) ? 1 : 0;
    ctx.skipSongReplays = SkipSongReplays.Value<u8>();

    //ctx.shuffleMusic = (ShuffleMusic)?1:0;
    //ctx.shuffleBGM = (ShuffleBGM)?1:0;
    //ctx.shuffleFanfare = ShuffleFanfares.Value<u8>();
    //ctx.shuffleOcaMusic = (ShuffleOcaMusic)?1:0;

    
    //Starting Quest Items
    ctx.startingQuestItems |= StartingSonataOfAwakening.Value<u8>()   << 6;
    ctx.startingQuestItems |= StartingGoronsLullaby.Value<u8>()     << 7;
    ctx.startingQuestItems |= StartingNewWaveBossaNova.Value<u8>()  << 8;
    ctx.startingQuestItems |= StartingElegyOfEmptiness.Value<u8>()  << 9;
    ctx.startingQuestItems |= StartingSongOfHealing.Value<u8>() << 10;
    ctx.startingQuestItems |= StartingSongOfSoaring.Value<u8>()   << 11;
    ctx.startingQuestItems |= StartingOathToOrder.Value<u8>()    << 12;
    ctx.startingQuestItems |= StartingEponasSong.Value<u8>()       << 13;
    //ctx.startingQuestItems |= StartingDoubleSong.Value<u8>()       << 14;
    //ctx.startingQuestItems |= StartingInvertedSong.Value<u8>()      << 15;
    //ctx.startingQuestItems |= StartingSongOfTime.Value<u8>()       << 16;
    ctx.startingQuestItems |= StartingSongOfStorms.Value<u8>()     << 17;
    ctx.startingDungeonReward |= StartingOdolwaRemains.Value<u8>()    << 18;
    ctx.startingDungeonReward |= StartingGohtRemains.Value<u8>()        << 19;
    ctx.startingDungeonReward |= StartingGyorgRemains.Value<u8>()     << 20;
    ctx.startingDungeonReward |= StartingTwinmoldRemains.Value<u8>()   << 5;

//    ctx.startingTokens        = StartingSwampToken.Value<u8>();
//    ctx.startingTokens        = StartingOceanToken.Value<u8>();

    //Starting Masks
    //To-DO
    //Starting Equipment
    ctx.startingEquipment |= StartingKokiriSword.Value<u8>();
    ctx.startingEquipment |= (StartingGreatFairySword.Value<u8>() ? 1: 0) << 2;
    ctx.startingEquipment |= StartingHerosShield.Value<u8>()  << 5;
    ctx.startingEquipment |= StartingMirrorShield.Value<u8>()  << 6;
 
    //Starting Upgrades
    ctx.startingUpgrades |= StartingWallet.Value<u8>() << 12;
    */
    return ctx;
  }

  //Set default cosmetics where the default is not the first option
  static void SetDefaultCosmetics() {
    for (auto op : cosmeticOptions) {
      op->SetToDefault();
    }
  }

  //One-time initialization
  void InitSettings() {
    //Set up token options
    //TODO: Create new 'number range' option type so this isn't necessary
    std::vector<std::string> StokenOptions;
    StokenOptions.reserve(31);
    for (int i = 0; i <= 30; i++) {
      StokenOptions.push_back(std::to_string(i));
    }
    std::vector<std::string> OtokenOptions;
    OtokenOptions.reserve(31);
    for (int i = 0; i <= 30; i++) {
      OtokenOptions.push_back(std::to_string(i));
    }
	StartingSwampToken.SetOptions(StokenOptions);
    StartingOceanToken.SetOptions(OtokenOptions);
    
    //Create Location Exclude settings
    AddExcludedOptions();

    SetDefaultSettings();
  }

  //Set default settings for all settings
  void SetDefaultSettings() {
      
      for (auto op : gimmickOptions) {
          op->SetToDefault();
      }
      for (auto op : timesaverOptions) {
          op->SetToDefault();
      }
      for (auto op : cosmeticOptions) {
          op->SetToDefault();
      }
    for (auto op : excludeLocationsOptions) {
      op->SetToDefault();
    }
    for (auto op : startingInventoryOptions) {
      op->SetToDefault();
    }
    for (auto op : logicOptions) {
      op->SetToDefault();
    }
    for (auto op : trickOptions) {
     op->SetToDefault();
    }
    for (auto op : glitchOptions) {
      op->SetToDefault();
    }
    for (auto op : shuffleItemOptions) {
        op->SetToDefault();
    }
    for (auto op : otherSettingsOptions) {
        op->SetToDefault();
    }

      for (auto loc : allLocations) {
      Location(loc)->GetExcludedOption()->SetToDefault();
    }
    //Don't let users exclude these locations
    //TODO: Make sure the defaults are set appropriately for these?
	//Also TODO: make sure some checks cant be skpped?
//    Location(HC_ZELDAS_LETTER)->GetExcludedOption()->Hide();
//    Location(MARKET_BOMBCHU_BOWLING_BOMBCHUS)->GetExcludedOption()->Hide();
    //Location(GANON)->GetExcludedOption()->Hide();

    SetDefaultCosmetics();
  }
  
  //Include and Lock the desired locations
  static void IncludeAndHide(std::vector<LocationKey> locations) {
    for (LocationKey loc : locations) {
      Location(loc)->GetExcludedOption()->SetSelectedIndex((u8)ExcludeLocationSetting::INCLUDE);
      Location(loc)->GetExcludedOption()->Hide();
   }
  }

  //Unlock the desired locations
  static void Unhide(std::vector<LocationKey> locations) {
    for (LocationKey loc : locations) {
      Location(loc)->GetExcludedOption()->Unhide();
    }
  }
  

  //Used for Starting Inventory options, enables/disables the options or expands/collapses each category based on their index number
  void CollapseCategory(Option startingInventorySections, int startNum, int endNum) {
    for(int i = startNum; i < endNum ;++i){
      switch(startingInventorySections.Value<u8>()) {
        case 0:
          startingInventoryOptions[i]->Hide();
          startingInventoryOptions[i]->SetSelectedIndex(0);
          break;
        case 1:
          startingInventoryOptions[i]->Hide();
          startingInventoryOptions[i]->SetSelectedIndex((startingInventoryOptions[i]->GetOptionCount())-1);
          break;
        case 2:
          startingInventoryOptions[i]->Unhide();
          break;
      }
    }
  }

  //This function will hide certain locations from the Excluded Locations
  //menu if the player's current settings would require non-junk to be placed
  //at those locations. Excluded locations will have junk placed at them.
  
  static void ResolveExcludedLocationConflicts() {

      //std::vector<LocationKey> shopLocations = GetLocations(everyPossibleLocation, Category::cShop);
      //For now, just always hide shop locations, as not sure how to handle hiding them-
      //1-4 should always be hidden, while the others should be settings dependent, but random shopsanity makes that more complicated...
      //Excluded shop locations are also wonky
      //IncludeAndHide(shopLocations);

      //Force include song locations
     std::vector<LocationKey> songLocations = GetLocations(everyPossibleLocation, Category::cSong);
     std::vector<LocationKey> DungeonRewards = GetLocations(everyPossibleLocation, Category::cDungeonReward);

      //Unhide all song locations, then lock necessary ones
      Unhide(songLocations);
      Unhide(DungeonRewards);

      if (ShuffleSongs.Is((u8)SongShuffleSetting::SONGSHUFFLE_SONG_LOCATIONS)) {
          IncludeAndHide(songLocations);
      }
      else if (ShuffleSongs.Is((u8)SongShuffleSetting::SONGSHUFFLE_DUNGEON_REWARDS)) {
          IncludeAndHide(DungeonRewards);
      }

      //Force Include Vanilla Skulltula locations
      /*std::vector<LocationKey> SwampSkulltulaLocations = GetLocations(everyPossibleLocation, Category::cSwampSkulltula);
      std::vector<LocationKey> OceanSkulltulaLocations = GetLocations(everyPossibleLocation, Category::cOceanSkulltula);
      Unhide(SwampSkulltulaLocations);
      Unhide(OceanSkulltulaLocations);
      if (Tokensanity.IsNot(TOKENSANITY_ALL_TOKENS)) {
          if (Tokensanity.Is(TOKENSANITY_OVERWORLD)) {
              //filter overworld skulls so we're just left with dungeons
              FilterAndEraseFromPool(SwampSkulltulaLocations, [](const LocationKey loc1) {return Location(loc1)->GetScene() >= 0x0A;});
              FilterAndEraseFromPool(OceanSkulltulaLocations, [](const LocationKey loc2) {return Location(loc2)->GetScene() >= 0x0A;});
          }
          else if (Tokensanity.Is(TOKENSANITY_DUNGEONS)) {
              //filter dungeon skulls so we're just left with overworld
              FilterAndEraseFromPool(SwampSkulltulaLocations, [](const LocationKey loc1) {return Location(loc1)->GetScene() < 0x0A;});
              FilterAndEraseFromPool(OceanSkulltulaLocations, [](const LocationKey loc2) {return Location(loc2)->GetScene() < 0x0A;});
          }
          IncludeAndHide(SwampSkulltulaLocations);
          IncludeAndHide(OceanSkulltulaLocations);
      }
      
      //Force Include scrubs if Scrubsanity is Off
      std::vector<LocationKey> scrubLocations = GetLocations(everyPossibleLocation, Category::cDekuScrub, Category::cDekuScrubUpgrades);
      if (Scrubsanity.Is(OFF)) {
          IncludeAndHide(scrubLocations);
      }
      else {
          Unhide(scrubLocations);
      }

      //Force include Cows if Shuffle Cows is Off
      std::vector<LocationKey> cowLocations = GetLocations(everyPossibleLocation, Category::cCow);
      if (ShuffleCows) {
          Unhide(cowLocations);
      }
      else {
          IncludeAndHide(cowLocations);
      }
      */
      //Force include the Kokiri Sword Chest if Shuffle Kokiri Sword is Off
      if (ShuffleKokiriSword) {
          Unhide({ HMS_STARTING_SWORD });
      }
      else {
          IncludeAndHide({ HMS_STARTING_SWORD });
      }

      //Force include the ocarina locations if Shuffle Ocarinas is Off
   //   std::vector<LocationKey> ocarinaLocations = {LW_GIFT_FROM_SARIA, HF_OCARINA_OF_TIME_ITEM};
  //    if (ShuffleOcarinas) {
  //      Unhide(ocarinaLocations);
  //    } else {
  //      IncludeAndHide(ocarinaLocations);
  //    }

      //Force include Magic Bean salesman if Shuffle Magic Beans is off
      if (ShuffleMagicBeans) {
          Unhide({ DEKU_PALACE_BEAN_DADDY });
      }
      else {
          IncludeAndHide({ DEKU_PALACE_BEAN_DADDY });
      }

      //Force include Map and Compass Chests when Vanilla
      std::vector<LocationKey> mapChests = GetLocations(everyPossibleLocation, Category::cVanillaMap);
      std::vector<LocationKey> compassChests = GetLocations(everyPossibleLocation, Category::cVanillaCompass);
      if (MapsAndCompasses.Is((u8)MapsAndCompassesSetting::MAPSANDCOMPASSES_VANILLA)) {
          IncludeAndHide(mapChests);
          IncludeAndHide(compassChests);
      }
      else {
          Unhide(mapChests);
          Unhide(compassChests);
      }
      
      //Force include Vanilla Small Key Locations (except gerudo Fortress) on Vanilla Keys
      std::vector<LocationKey> smallKeyChests = GetLocations(everyPossibleLocation, Category::cVanillaSmallKey);
      if (Keysanity.Is((u8)KeysanitySetting::KEYSANITY_VANILLA)) {
          IncludeAndHide(smallKeyChests);
      }
      else {
          Unhide(smallKeyChests);
      }

      //Force include Boss Key Chests if Boss Keys are Vanilla
      std::vector<LocationKey> bossKeyChests = GetLocations(everyPossibleLocation, Category::cVanillaBossKey);
      if (BossKeysanity.Is((u8)BossKeysanitySetting::BOSSKEYSANITY_VANILLA)) {
          IncludeAndHide(bossKeyChests);
      }
      else {
          Unhide(bossKeyChests);
      }
      
  }
  //Hide certain settings if they aren't relevant or Lock settings if they
  //can't be changed due to another setting that was chosen. (i.e. Closed Forest
  //will force Starting Age to Child).
  void ForceChange(u32 kDown, Option* currentSetting) {

    //Groups the item categories; bottles are handled separately because the proper item is Empty Bottle (1)
      CollapseCategory(StartingInventoryToggle, 3, 14);
      CollapseCategory(StartingMaskToggle, 22, 45);
      CollapseCategory(StartingSongsToggle, 46, 55);
      CollapseCategory(StartingUpgradesToggle, 56, 64);
      CollapseCategory(StartingQuestToggle, 65, 69);
    for(int i = 14; i < 21 ;++i){
      switch(StartingInventoryToggle.Value<u8>()) {
        case 0:
          startingInventoryOptions[i]->Hide();
          startingInventoryOptions[i]->SetSelectedIndex(0);
          break;
        case 1:
          startingInventoryOptions[i]->Hide();
          startingInventoryOptions[i]->SetSelectedIndex(1);
          break;
        case 2:
          startingInventoryOptions[i]->Unhide();
          break;
      }
    }

    //Only hide the options for now, select them later in UpdateSettings()
    //RandomizeAllSettings();
      

    //Force Link's Pocket Item to be a dungeon reward if Shuffle Rewards is end of dungeons
   /* if (ShuffleRewards.Is(REWARDSHUFFLE_END_OF_DUNGEON)) {
      LinksPocketItem.Lock();
      LinksPocketItem.SetSelectedIndex(LINKSPOCKETITEM_DUNGEON_REWARD);
      if (RandomizeShuffle) {
        //Even if it is supposed to be locked, still hide it to keep the surprise
        LinksPocketItem.Unlock();
        LinksPocketItem.Hide();
      }
    } else {
      LinksPocketItem.Unlock();
    }*/

    //Only show hint options if hints are enabled
    /*if (GossipStoneHints.Is(HINTS_NO_HINTS)) {
      ClearerHints.Hide();
      HintDistribution.Hide();
    } else {
      ClearerHints.Unhide();
      HintDistribution.Unhide();
    }*/

    if (RemoveDoubleDefense) {
      StartingDoubleDefense.SetSelectedIndex(0);
      StartingDoubleDefense.Lock();
    } else {
      StartingDoubleDefense.Unlock();
    }


    //Tunic Colors
    if (CustomTunicColors) {
      ChildTunicColor.Unhide();
      
    } else {
      ChildTunicColor.Hide();
      ChildTunicColor.SetSelectedIndex(3);  //Kokiri Green
     }

    // Music
//    if (ShuffleMusic) {
//      ShuffleBGM.Unhide();
//      ShuffleFanfares.Unhide();
//      if(ShuffleFanfares.Is(2)) // Fanfares + ocarina
//        ShuffleOcaMusic.Hide();
//      else
//        ShuffleOcaMusic.Unhide();
//    } else {
//      ShuffleBGM.Hide();
//      ShuffleFanfares.Hide();
//      ShuffleOcaMusic.Hide();
//    }

    ResolveExcludedLocationConflicts();
  }


  // Randomizes all settings in a category if chosen
  // Hides all relevant options
  void RandomizeAllSettings(const bool selectOptions /*= false*/) {
  /*
    // Open Settings
    if (RandomizeOpen) {
      // Skip RandomizeOpen Option
      for (size_t i = 1; i < openOptions.size(); i++) {
        //hide options
        openOptions[i]->Hide();

        //randomize options
        if (selectOptions) {
          openOptions[i]->SetSelectedIndex(Random(0,openOptions[i]->GetOptionCount()));
        }
      }
      
    }
    else {
      for (size_t i = 1; i < openOptions.size(); i++) {
        openOptions[i]->Unhide();
      }
    }

   
    // Shuffle Settings
    if (RandomizeShuffle) {
      // Still displays if previously locked
      LinksPocketItem.Unlock();
      // Skip RandomizeShuffle Option
      for (size_t i=1; i < shuffleOptions.size(); i++) {
        shuffleOptions[i]->Hide();
        //randomize options
        if (selectOptions) {
          shuffleOptions[i]->SetSelectedIndex(Random(0,shuffleOptions[i]->GetOptionCount()));
        }
      }
      // Double check that this is the case in case of randomization on init
      if (ShuffleRewards.Is(REWARDSHUFFLE_END_OF_DUNGEON)) {
        LinksPocketItem.SetSelectedIndex(LINKSPOCKETITEM_DUNGEON_REWARD);
      }
    }
    else {
      for (size_t i=1; i < shuffleOptions.size(); i++) {
        shuffleOptions[i]->Unhide();
      }
    }

    // Dungeon Shuffle Settings
    if (RandomizeDungeon) {
      // Skip RandomizeDungeon Option
      for (size_t i=1; i < shuffleDungeonItemOptions.size(); i++) {
        shuffleDungeonItemOptions[i]->Hide();
        //randomize options
        if (selectOptions) {
          shuffleDungeonItemOptions[i]->SetSelectedIndex(Random(0,shuffleDungeonItemOptions[i]->GetOptionCount()));
        }
      }
    }
    else {
      for (size_t i=1; i < shuffleDungeonItemOptions.size(); i++) {
        shuffleDungeonItemOptions[i]->Unhide();
      }
    }

    //resolve any settings that need to change
    if (selectOptions) {
      ForceChange(0, nullptr);
    }*/
  }

  //eventual settings
  bool ShuffleInteriorEntrances         = false;
  bool ShuffleSpecialIndoorEntrances    = false;

  template <typename colorsArray>
  static void ChooseFinalColor(const Option& cosmeticOption, std::string& colorStr, const colorsArray& colors) {
    if (cosmeticOption.Is(CUSTOM_COLOR)) {
      colorStr = GetCustomColor(cosmeticOption.GetSelectedOptionText());
    } else if (cosmeticOption.Is(RANDOM_CHOICE)) {
      colorStr = colors[rand() % colors.size()]; //use default rand to not interfere with seed
    } else if (cosmeticOption.Is(RANDOM_COLOR)) {
      colorStr = RandomColor();
    } else {
      colorStr = colors[cosmeticOption.GetSelectedOptionIndex() - NON_COLOR_COUNT];
    }
  }

  //Function to update cosmetics options depending on choices
  /*static void UpdateCosmetics() {

    ChooseFinalColor(ChildTunicColor, finalChildTunicColor, tunicColors);
    }
  */
  //Function to set flags depending on settings
  void UpdateSettings() {

    //RandomizeAllSettings(true); //now select any random options instead of just hiding them

    //shuffle the dungeons 
   /* auto dungeons = dungeonList;
    if (SetDungeonTypes) {
        u8 dungeonCount = 0;
        for (size_t i = 0; i < dungeons.size(); i++) {
            dungeonOptions[i]->Value<u8>());
        }
    }*/
	//UpdateCosmetics();

    //If vanilla logic, we want to set all settings which unnecessarily modify vanilla behavior to off
    //if (Logic.Is((u8)LogicSetting::LOGIC_VANILLA)) {
     // ShuffleChests.SetSelectedIndex(0);
      //ShuffleRewards.SetSelectedIndex(0);
      //LinksPocketItem.SetSelectedIndex(0);
      //ShuffleSongs.SetSelectedIndex(0);
      //Scrubsanity.SetSelectedIndex(0);
      //ShuffleCows.SetSelectedIndex(0);
      //ShuffleMagicBeans.SetSelectedIndex(0);
      //Keysanity.SetSelectedIndex(3); //Set small keys to any dungeon
      //GossipStoneHints.SetSelectedIndex(0);
    //}
    /*
    InitMusicRandomizer();
    if (ShuffleMusic) {
      if (ShuffleBGM) {
        ShuffleSequences(SeqType::SEQ_BGM);
      }

      if (ShuffleFanfares.Is(2)) {
        ShuffleSequences(SeqType::SEQ_FANFARE | SeqType::SEQ_OCARINA);
      } else {
        if (ShuffleFanfares.Is(1)) {
          ShuffleSequences(SeqType::SEQ_FANFARE);
        }

        if (ShuffleOcaMusic) {
          ShuffleSequences(SeqType::SEQ_OCARINA);
        }
      }
    }*/
  }
  
  //If this is an option menu, return th options
  //Else, recursively call each sub menu of this sub menu
  const std::vector<Menu*> GetMenusRecursive(Menu* menu) {
    std::vector<Menu*> menus;
    if (menu->mode == OPTION_SUB_MENU) {
      menus.push_back(menu);
    } else if (menu->mode == SUB_MENU) {
        for (Menu* subMenu : *menu->itemsList) {
          std::vector<Menu*> foundMenus = GetMenusRecursive(subMenu);
          menus.insert(menus.end(), foundMenus.begin(), foundMenus.end());
        }
    }
    return menus;
  }

  //Recursively look through each menu from the main menu to get all settings
  const std::vector<Menu*> GetAllMenus() {
    std::vector<Menu*> allMenus;
    for (Menu* menu : Settings::mainMenu) {
      std::vector<Menu*> foundMenus = GetMenusRecursive(menu);
      allMenus.insert(allMenus.end(), foundMenus.begin(), foundMenus.end());
    }
    return allMenus;
  }
  
} // namespace Settings
