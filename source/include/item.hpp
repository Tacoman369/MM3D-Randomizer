#pragma once

#include <3ds.h>
#include <string>
#include <variant>
#include "text.hpp"
#include "keys.hpp"
#include "hint_list.hpp"
#include "settings.hpp"
#include "region.hpp"
#include "item_category.hpp"
#include "rnd/item_override.h"

using namespace std;
using namespace rnd;

//union ItemOverride_Value;

class Item {
public:
    Item() = default;
    Item(bool advancement_, int startAdd_, bool* logicVar_, Text name_, string locationName_, Region region_, HintKey hintKey_, u32 getItemId_, ItemCategory itemCat_, LocationCategory locCat_);
    Item(bool advancement_, int startAdd_, u8* logicVar_, Text name_, string locationName_, Region region_, HintKey hintKey_, u32 getItemId_, ItemCategory itemCat_, LocationCategory locCat_);
    ~Item();

    void ApplyEffect();
    void UndoEffect();

    union ItemOverride_Value Value() const;

    int GetStartAdd() const {
        return startAdd;
    }
    bool IsAdvancement() const {
        return advancement;
    }
    const Text& GetName() const {
        return name;
    }
    const string GetLocationName() const {
        return locationName;
    }
    const Region GetRegion() const {
        return region;
    }
    const HintKey GetHintKey() const {
        return hintKey;
    }
    const HintText& GetHint() const {
        return Hint(hintKey);
    }
    u32 GetItemId() const {
        return (u32)getItemId;
    }
    const ItemCategory GetItemCategory() const {
        return itemCat;
    }
    const LocationCategory GetLocationCategory() const {
        return locCat;
    }
    
    u16 GetPrice() const {
        return price;
    }

    void SetPrice(u16 price_) {
        price = price_;
    }
    void SetAsPlaythrough() {
        playthrough = true;
    }

    bool IsPlaythrough() const {
        return playthrough;
    }
    bool IsMajorItem() const {
        return IsAdvancement();
    }
    bool IsBottleItem() const {
        return getItemId == (u32)GetItemID::GI_BOTTLE_EMPTY || //Empty Bottle1
            getItemId == (u32)GetItemID::GI_BOTTLE_EMPTY || //Empty Bottle 2
            getItemId == (u32)GetItemID::GI_BOTTLE_MILK || //Bottle with Milk
            getItemId == (u32)GetItemID::GI_BOTTLE_POTION_RED || //Red Potion
            getItemId == (u32)GetItemID::GI_BOTTLE_GOLD_DUST || //Gold Dust
            getItemId == (u32)GetItemID::GI_BOTTLE_CHATEAU_ROMANI || //Chateau Romani
            getItemId == (u32)GetItemID::GI_DEKU_PRINCESS_FAIRY || //Deku Princess
            getItemId == (u32)GetItemID::GI_FAIRY || //Fairy
            getItemId == (u32)GetItemID::GI_BOTTLE_BUG || //Bugs
            getItemId == (u32)GetItemID::GI_BOTTLE_POE_TEXT || //Poe
            getItemId == (u32)GetItemID::GI_BOTTLE_BIG_POE || //Big Poe
            getItemId == (u32)GetItemID::GI_BOTTLE_SPRING_WATER || //Spring Water
            getItemId == (u32)GetItemID::GI_BOTTLE_HOT_SPRING_WATER || //Hot Spring Water
            getItemId == (u32)GetItemID::GI_BOTTLE_ZORA_EGG || //Zora Egg
            getItemId == (u32)GetItemID::GI_BOTTLE_MAGIC_MUSHROOM;   //Mushroom

    } 

  //  Item(bool advancement_, int startAdd_, bool* logicVar_, Text name_, string locationName_, Region region_, HintKey hintKey_, int getItemId_, ItemCategory itemCat_, LocationCategory locCat_);
  //  Item(bool advancement_, int startAdd_, u8* logicVar_, Text name_, string locationName_, Region region_, HintKey hintKey, int getItemId_, ItemCategory itemCat_, LocationCategory locCat_);

private:
    bool advancement;  
    int startAdd;
    std::variant<bool*, u8*> logicVar;
    Text name;
    string locationName;
    Region region;
    HintKey hintKey;
    u32 getItemId;
    ItemCategory itemCat;
    LocationCategory locCat;
    bool playthrough = false;
    int price;
};
