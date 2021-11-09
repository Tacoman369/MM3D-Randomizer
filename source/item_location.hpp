#pragma once

#include <algorithm>
#include <array>
#include <cstdio>
#include <functional>
#include <set>
#include <string>
#include <unistd.h>
#include <vector>

#include <3ds.h>

#include "../code/include/z3D/z3D.h"
#include "../code/src/item_override.h"
#include "../code/src/spoiler_data.h"
#include "category.hpp"
#include "item_list.hpp"
#include "hint_list.hpp"
#include "settings.hpp"
#include "keys.hpp"

class Entrance;

enum class ItemLocationType {
    Base,
    Chest,
    Collectable,
    SGSToken,
    OGSToken,
    GrottoScrub,
    StrayFairy,
    Delayed,
    TempleReward,
    HintStone,
    OtherHint
};

class ItemLocation {
public:
    ItemLocation() = default;
    ItemLocation(ItemLocationType type_, std::string name_, HintKey hintKey_, ItemKey vanillaItem_, std::vector<Category> categories_, u16 price_ = 0)
        : type(type_), name(std::move(name_)), hintKey(hintKey_), vanillaItem(vanillaItem_), categories(std::move(categories_)), price(price_) {}

    ItemOverride_Key Key() const {
        ItemOverride_Key key;
        key.all = 0;

        //key.scene = scene;
        key.type = static_cast<u8>(type); //TODO make sure these match up
        //key.flag = flag;
        return key;
    }
    /*
    u8 GetScene() const {
      return scene;
    }

    u8 GetFlag() const {
      return flag;
    }
    */
    bool IsAddedToPool() const {
        return addedToPool;
    }

    void AddToPool() {
        addedToPool = true;
    }

    void RemoveFromPool() {
        addedToPool = false;
    }

    const std::string& GetName() const {
        return name;
    }

    const Text& GetPlacedItemName() const {
        return ItemTable(placedItem).GetName();
    }

    const Item& GetPlacedItem() const {
        return ItemTable(placedItem);
    }

    ItemKey GetPlacedItemKey() const {
        return placedItem;
    }

    void SetPlacedItem(const ItemKey item) {
        placedItem = item;
        //SetPrice(ItemTable(placedItem).GetPrice());
    }

    //Saves an item to be set as placedItem later
    void SetDelayedItem(const ItemKey item) {
        delayedItem = item;
    }

    //Place the vanilla item in this location
    void PlaceVanillaItem() {
        placedItem = vanillaItem;
    }

    void ApplyPlacedItemEffect() {
        ItemTable(placedItem).ApplyEffect();
    }

    //Set placedItem as item saved in SetDelayedItem
    void SaveDelayedItem() {
        placedItem = delayedItem;
        delayedItem = NONE;
    }
    /*
    u16 GetPrice() const {
        //if (ItemTable(placedItem).GetItemType() == ITEMTYPE_SHOP) {
        return ItemTable(placedItem).GetPrice();
        //}
        //return price;
    }

    void SetPrice(u16 price_) {
        //don't override price if the price was set for shopsanity
        if (hasShopsanityPrice) {
            return;
        }
        price = price_;
    }

    void SetShopsanityPrice(u16 price_) {
        price = price_;
        hasShopsanityPrice = true;
    }

    bool HasShopsanityPrice() const {
        return hasShopsanityPrice;
    }
    */
    bool IsExcluded() const {
        return excludedOption.Value<bool>();
    }

    bool IsCategory(Category category) const {
        return std::any_of(categories.begin(), categories.end(),
            [category](auto entry) { return entry == category; });
    }

    bool IsDungeon() const  {return true;
        //return LocationCategory = Category::cWoodfallTemple;
            
            /*(type != ItemLocationType::OGSToken && LocationCategory = Category::cWoodfallTemple ||
            type != ItemLocationType::OGSToken && LocationCategory = Category::cSnowheadTemple ||
            type != ItemLocationType::OGSToken && LocationCategory = Category::cGreatBayTemple ||
            type != ItemLocationType::OGSToken && LocationCategory = Category::cStoneTowerTemple ||
            type != ItemLocationType::SGSToken && LocationCategory = Category::cWoodfallTemple ||
            type != ItemLocationType::SGSToken && LocationCategory = Category::cSnowheadTemple ||
            type != ItemLocationType::SGSToken && LocationCategory = Category::cGreatBayTemple ||
            type != ItemLocationType::SGSToken && LocationCategory = Category::cStoneTowerTemple ||
            );*/
    }

    bool IsOverworld() const {
        return !IsDungeon();
    }

    bool IsShop() const {
        return (scene >= 0x2C && scene <= 0x32);
    }

    Option* GetExcludedOption() {
        return &excludedOption;
    }

    const HintKey GetHintKey() const {
        return hintKey;
    }

    const HintText& GetHint() const {
        return Hint(hintKey);
    }

    bool IsHintedAt() const {
        return hintedAt;
    }

    void SetAsHinted() {
        hintedAt = true;
    }

    bool IsHintable() const {
        return isHintable;
    }

    void SetAsHintable() {
        isHintable = true;
    }

    void SetParentRegion(AreaKey region) {
        parentRegion = region;
    }

    AreaKey GetParentRegionKey() const {
        return parentRegion;
    }

    void AddExcludeOption() {
        //setting description  /*--------------------------------------------------*/
        std::string_view desc = "Decide which locations you want to exclude from\n"
            "the location pool. Locations that require an item\n"
            "to be placed at them based on your current\n"
            "settings cannot be excluded and won't be shown\n"
            "unless you change your settings.\n"
            "\n"
            "If you exclude too many locations, it might not\n"
            "be possible to fill the world.";

        //add option to forbid any location from progress items
        if (name.length() < 23) {
            excludedOption = Option::Bool(name, { "Include", "Exclude" }, { desc });
        }
        else {
            //insert a newline character if the text is too long for one row
            size_t lastSpace = name.rfind(' ', 23);
            std::string settingText = name;
            settingText.replace(lastSpace, 1, "\n ");

            excludedOption = Option::Bool(settingText, { "Include", "Exclude" }, { desc });
        }

        Settings::excludeLocationsOptions.push_back(&excludedOption);
    }

    static auto Base(std::string&& name, const HintKey hintKey, const ItemKey vanillaItem, std::vector<Category>&& categories) {
        return ItemLocation{ ItemLocationType::Base, std::move(name), hintKey, vanillaItem, std::move(categories),0 };
    }

    static auto Chest(std::string&& name, const HintKey hintKey, const ItemKey vanillaItem, std::vector<Category>&& categories) {
        return ItemLocation{ ItemLocationType::Chest, std::move(name), hintKey, vanillaItem, std::move(categories), 0 };
    }

    static auto Collectable(std::string&& name, const HintKey hintKey, const ItemKey vanillaItem, std::vector<Category>&& categories) {
        return ItemLocation{ ItemLocationType::Collectable, std::move(name), hintKey, vanillaItem, std::move(categories),0 };
    }

    static auto OGSToken(std::string&& name, const HintKey hintKey, const ItemKey vanillaItem, std::vector<Category>&& categories) {
        return ItemLocation{ ItemLocationType::OGSToken, std::move(name), hintKey, vanillaItem, std::move(categories), 0 };
    }
    static auto SGSToken(std::string&& name, const HintKey hintKey, const ItemKey vanillaItem, std::vector<Category>&& categories) {
        return ItemLocation{ ItemLocationType::SGSToken, std::move(name), hintKey, vanillaItem, std::move(categories), 0 };
    }
    static auto StrayFairy(std::string&& name, const HintKey hintKey, const ItemKey vanillaItem, std::vector<Category>&& categories) {
        return ItemLocation{ ItemLocationType::StrayFairy, std::move(name), hintKey, vanillaItem, std::move(categories),0 };
    }
    static auto GrottoScrub(std::string&& name, const HintKey hintKey, const ItemKey vanillaItem, std::vector<Category>&& categories) {
        return ItemLocation{ ItemLocationType::GrottoScrub, std::move(name), hintKey, vanillaItem, std::move(categories), 0 };
    }

    static auto Delayed(std::string&& name, const HintKey hintKey, const ItemKey vanillaItem, std::vector<Category>&& categories) {
        return ItemLocation{ ItemLocationType::Delayed, std::move(name), hintKey, vanillaItem, std::move(categories), 0 };
    }

    static auto Reward(std::string&& name, const HintKey hintKey, const ItemKey vanillaItem, std::vector<Category>&& categories) {
        return ItemLocation{ ItemLocationType::TempleReward, std::move(name), hintKey, vanillaItem, std::move(categories), 0 };
    }

    static auto OtherHint(std::string&& name, std::vector<Category>&& categories) {
        return ItemLocation{ ItemLocationType::OtherHint, std::move(name), NONE, NONE, std::move(categories) };
    }

    static auto HintStone(std::string&& name, std::vector<Category>&& categories) {
        return ItemLocation{ ItemLocationType::HintStone, std::move(name), NONE, NONE, std::move(categories) };
    }

    void ResetVariables() {
        checked = false;
        addedToPool = false;
        placedItem = NONE;
        delayedItem = NONE;
        hintedAt = false;
        isHintable = false;
        price = 0;
        hasShopsanityPrice = false;
    }

private:
    u8 scene;
    ItemLocationType type;
    u8 flag;
    bool checked = false;

    std::string name;
    HintKey hintKey = NONE;
    ItemKey vanillaItem = NONE;
    bool hintedAt = false;
    std::vector<Category> categories;
    bool addedToPool = false;
    ItemKey placedItem = NONE;
    ItemKey delayedItem = NONE;
    Option excludedOption = Option::Bool(name, { "Include", "Exclude" }, { "", "" });
    u16 price = 0;
    bool isHintable = false;
    AreaKey parentRegion = NONE;
    bool hasShopsanityPrice = false;
};

class ItemOverride_Compare {
public:
    bool operator()(ItemOverride lhs, ItemOverride rhs) const {
        return lhs.key.all < rhs.key.all;
    }
};

void LocationTable_Init();

ItemLocation* Location(LocationKey locKey);

//extern std::vector<std::vector<LocationKey>> ShopLocationLists;

//extern std::vector<LocationKey> gossipStoneLocations;

//extern std::vector<LocationKey> dungeonRewardLocations;
//extern std::vector<LocationKey> overworldLocations;
//extern std::vector<LocationKey> allLocations;
//extern std::vector<LocationKey> everyPossibleLocation;

//set of overrides to write to the patch
//extern std::set<ItemOverride, ItemOverride_Compare> overrides;

//extern std::vector<std::vector<LocationKey>> playthroughLocations;
//extern std::vector<LocationKey> wothLocations;
//extern bool playthroughBeatable;
//extern bool allLocationsReachable;
//extern bool showItemProgress;

//extern u16 itemsPlaced;

void GenerateLocationPool();
void PlaceItemInLocation(LocationKey loc, ItemKey item, bool applyEffectImmediately = false);
std::vector<LocationKey> GetLocations(const std::vector<LocationKey>& locationPool, Category categoryInclude, Category categoryExclude = Category::cNull);
void LocationReset();
void ItemReset();
void HintReset();
void AddExcludedOptions();
void CreateItemOverrides();
/*
class SpoilerCollectionCheck {
public:
  SpoilerCollectionCheckType type = SpoilerCollectionCheckType::SPOILER_CHK_NONE;
  u8 scene = 0;
  u8 flag = 0;

  SpoilerCollectionCheck() {}
  SpoilerCollectionCheck(SpoilerCollectionCheckType type_, u8 scene_, u8 flag_) : type(type_), scene(scene_), flag(flag_) {}

  static auto None() {
    return SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_NONE, 0x00, 0x00);
  }

  static auto AlwaysCollected() {
    return SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_ALWAYS_COLLECTED, 0x00, 0x00);
  }

  static auto ItemGetInf(u8 slot) {
    return SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_ITEM_GET_INF, 0x00, slot);
  }

  static auto EventChkInf(u8 flag) {
    return SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_EVENT_CHK_INF, 0xFF, flag);
  }

  static auto InfTable(u8 offset, u8 bit) {
    return SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_INF_TABLE, offset, bit);
  }

  static auto Collectable(u8 scene, u8 flag) {
    return SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_COLLECTABLE, scene, flag);
  }

  static auto Chest(u8 scene, u8 flag) {
    return SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_CHEST, scene, flag);
  }

  static auto Cow(u8 scene, u8 flag) {
    return SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_COW, scene, flag);
  }

  static auto Fishing(u8 bit) {
    return SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_MINIGAME, 0x00, bit);
  }

  static auto Scrub(u8 scene, u8 bit) {
    return SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_SCRUB, scene, bit);
  }

  static auto GerudoToken() {
    return SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_GERUDO_TOKEN, 0x00, 0x00);
  }

  static auto ShopItem(u8 scene, u8 itemSlot) {
    return SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_SHOP_ITEM, scene, itemSlot);
  }

  static auto MagicBeans(u8 scene, u8 flag) {
      return SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_MAGIC_BEANS, scene, flag);
  }
};

    SpoilerCollectionCheck GetCollectionCheck() const {
      return collectionCheck;
    }

    SpoilerCollectionCheckGroup GetCollectionCheckGroup() const {
      return collectionCheckGroup;
    }
    */