#include "item.hpp"

#include <array>
#include <string>
#include "logic.hpp"
#include "random.hpp"
#include "item_pool.hpp"
#include "settings.hpp"
#include "rnd/item_override.h"
#include "region.hpp"
#include "item_category.hpp"
#include "text.hpp"

using namespace rnd;

Item::Item(bool advancement_,int startAdd_, bool* logicVar_, Text name_, string locationName_, Region region_, HintKey hintKey_, u32 getItemId_, ItemCategory itemCat_, LocationCategory locCat_)
    : 
    advancement(advancement_),
    startAdd(startAdd_),
    logicVar(logicVar_),
    name(std::move(name_)),
    locationName(locationName_),
    region(region_),
    hintKey(hintKey_),
    getItemId(getItemId_),
    itemCat(itemCat_),
    locCat(locCat_) {}

Item::Item(bool advancement_, int startAdd_, u8* logicVar_, Text name_, string locationName_, Region region_, HintKey hintKey_, u32 getItemId_, ItemCategory itemCat_, LocationCategory locCat_)
    :
    advancement(advancement_),
    startAdd(startAdd_),
    logicVar(logicVar_),
    name(std::move(name_)),
    locationName(locationName_),
    region(region_),
    hintKey(hintKey_),
    getItemId(getItemId_),
    itemCat(itemCat_),
    locCat(locCat_) {}

Item::~Item() = default;

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
    val.getItemId = getItemId;
    
   // if (getItemId == rnd::GetItemID::GI_ICE_TRAP) {
   //     val.looksLikeItemId = RandomElement(IceTrapModels);
   // }
    if (!Settings::ColoredBossKeys && (getItemId >= 0x95 && getItemId <= 0x9A)) { //Boss keys
        val.looksLikeItemId = (u32)GetItemID::GI_KEY_BOSS;
    }
    if (!Settings::ColoredKeys && (getItemId >= 0xAF && getItemId <= 0xB7)) { //Small keys
        val.looksLikeItemId = (u32)GetItemID::GI_KEY_SMALL;
    }
    //if (type == ITEMTYPE_SHOP) {
    //    // With the current shopsanity implementation, we need a way to detect
    //    // regular shop items. This method should have no unintended side effects
    //    // unless there was a multiworld with 256 players... so, it should be fine.
    //    val.player = 0xFF;
    //}
    return val; 
    
}

