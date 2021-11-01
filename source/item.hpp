#pragma once

#include <3ds.h>
#include <string>
#include <variant>

#include "keys.hpp"
#include "hint_list.hpp"
#include "settings.hpp"
#include "region.hpp"
#include "item_category.hpp"


union ItemOverride_Value;



class Item {
public:
    Item() = default;
    Item(int startAdd_, int startIndex_, Text name_, Text locationName_, Region region_, HintKey hintKey_, int getItemIndex_, ItemCategory itemCat_, LocationCategory locCat_ );

    ~Item();

    int GetStartAdd() const {
        return startAdd;
    }
    int GetStartIndex() const {
        return startIndex;
    }
    const Text& GetName() const {
        return name;
    }
    const Text& GetLocationName() const {
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
    void SetAsPlaythrough() {
        playthrough = true;
    }

    bool IsPlaythrough() const {
        return playthrough;
    }

   /* bool IsBottleItem() const {
        return getItemId == 0x0F || //Empty Bottle
               getItemId == 0X14 || //Bottle with Milk
              (getItemId >= 0x8C && getItemId <= 0x94); //Rest of bottled contents
    } */


    bool operator== (const Item& right) const {
        return type == right.GetItemType() && getItemId == right.GetItemID();
    }

    bool operator!= (const Item& right) const {
        return !operator==(right);
    }
    Item(int startAdd_, int startIndex_, Text name_, Text locationName_, Region region_,
        HintKey hintKey_, int getItemIndex_, ItemCategory itemCat_, LocationCategory locCat_, )

private:
    int startAdd;
    int startIndex;
    Text name;
    Text locationName;
    Region region;
    HintKey hintKey;
    int getItemIndex;
    ItemCategory itemCat;
    LocationCategory locCat;
    bool playthrough = false;
};
