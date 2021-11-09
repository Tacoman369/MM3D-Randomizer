#include "fill.hpp"

#include "custom_messages.hpp"
#include "item_pool.hpp"
#include "logic.hpp"
#include "random.hpp"
#include "spoiler_log.hpp"
#include "starting_inventory.hpp"
#include "hints.hpp"
#include "hint_list.hpp"
#include "debug.hpp"
#include "item_list.hpp"

#include <vector>
/*
using namespace CustomMessages;
using namespace Logic;
using namespace Settings;

static void RemoveStartingItemsFromPool() {
	for (ItemKey startingItem : StartingInventory) {
		for (size_t i = 0; i < ItemPool.size();i++) {
			if (startingItem == ItemPool[i] || (ItemTable(startingItem).IsBottleItem() && ItemTable(ItemPool[i]).IsBottleItem())) {
				ItemPool[i] = GetJunkItem();
				break;
			}
		}
	}
}
*/
