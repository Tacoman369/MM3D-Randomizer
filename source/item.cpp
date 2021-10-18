#include "item.hpp"

#include <array>

#include "logic.hpp"
#include "random.hpp"
#include "item_pool.hpp"
#include "settings.hpp"
#include "../code/src/item_override.h"
#include "region.hpp"
#include "item_category.hpp"

Item::Item(int startAdd_, int startIndex_, Text name_, Text locationName_, Region region_, HintKey hintKey_, int getItemIndex_, ItemCategory itemCat_, LocationCategory locCat_, )
    : startAdd(startAdd_),
    startIndex(startIndex_),
    name(std::move(name_)),
    locationName(std::move(locationName_)),
    region(region_),
    hintKey(hintKey_),
    getItemIndex(getItemIndex_),
    itemCat(itemCat_),
    locCat(locCat_) {}

Item::~Item() = default;
/*
void Item::ApplyEffect() {
    if (std::holds_alternative<bool*>(logicVar)) {
        *std::get<bool*>(logicVar) = true;
    } else {
        *std::get<u8*>(logicVar) += 1;
    }
    Logic::UpdateHelpers();
}

void Item::UndoEffect() {
    if (std::holds_alternative<bool*>(logicVar)) {
        *std::get<bool*>(logicVar) = false;
    } else {
        *std::get<u8*>(logicVar) -= 1;
    }
    Logic::UpdateHelpers();
}

ItemOverride_Value Item::Value() const {
    ItemOverride_Value val;
    val.all = 0;
    val.itemId = getItemId;
    if (getItemId == GI_ICE_TRAP) {
        val.looksLikeItemId = RandomElement(IceTrapModels);
    }
    if (!Settings::ColoredBossKeys && (getItemId >= 0x95 && getItemId <= 0x9A)) { //Boss keys
        val.looksLikeItemId = GI_KEY_BOSS;
    }
    if (!Settings::ColoredKeys && (getItemId >= 0xAF && getItemId <= 0xB7)) { //Small keys
        val.looksLikeItemId = GI_KEY_SMALL;
    }
    if (type == ITEMTYPE_SHOP) {
        // With the current shopsanity implementation, we need a way to detect
        // regular shop items. This method should have no unintended side effects
        // unless there was a multiworld with 256 players... so, it should be fine.
        val.player = 0xFF;
    }
    return val; 
    */
}
