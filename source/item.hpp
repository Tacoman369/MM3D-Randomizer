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

union ItemOverride_Value;
using namespace std;
class Item {
public:
    Item() = default;
    Item(int startAdd_, int startIndex_, Text name_, string locationName_, Region region_, HintKey hintKey_,
        int getItemIndex_, ItemCategory itemCat_, LocationCategory locCat_);
    
    ~Item();

    void ApplyEffect();
    void UndoEffect();

    int GetStartAdd() const {
        return startAdd;
    }
    int GetStartIndex() const {
        return startIndex;
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
    int GetItemIndex() const {
        return getItemIndex;
    }
    const ItemCategory GetItemCategory() const {
        return itemCat;
    }
    const LocationCategory GetLocationCategory() const {
        return locCat;
    }
    /*
    u16 GetPrice() const {
        return price;
    }

    void SetPrice(u16 price_) {
        price = price_;
    }*/
    void SetAsPlaythrough() {
        playthrough = true;
    }

    bool IsPlaythrough() const {
        return playthrough;
    }
    
    bool IsBottleItem() const {
        return getItemIndex == 0x5A || //Empty Bottle1
            getItemIndex == 0x64 || //Empty Bottle 2
            getItemIndex == 0x60 || //Bottle with Milk
            getItemIndex == 0x59 || //Red Potion
            getItemIndex == 0x6A || //Gold Dust
            getItemIndex == 0x6F || //Chateau Romani
            getItemIndex == 0x08 || //Deku Princess
            getItemIndex == 0x0D || //Fairy
            getItemIndex == 0x03 || //Bugs
            getItemIndex == 0x0B || //Poe
            getItemIndex == 0x0C || //Big Poe
            getItemIndex == 0x04 || //Spring Water
            getItemIndex == 0x06 || //Hot Spring Water
            getItemIndex == 0x07 || //Zora Egg
            getItemIndex == 0x0A;   //Mushroom

    } 


  //  Item(int startAdd_, int startIndex_, Text name_, Text locationName_, Region region_, HintKey hintKey_, int getItemIndex_, ItemCategory itemCat_, LocationCategory locCat_ );

private:
    int startAdd;
    int startIndex;
    Text name;
    string locationName;
    Region region;
    HintKey hintKey;
    int getItemIndex;
    ItemCategory itemCat;
    LocationCategory locCat;
    bool playthrough = false;
};
