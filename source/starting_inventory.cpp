#include "starting_inventory.hpp"

#include <unistd.h>

#include "debug.hpp"
#include "dungeon.hpp"
#include "item_list.hpp"
#include "settings.hpp"

using namespace Settings;
using namespace Dungeon;
using namespace rnd;

std::vector<ItemKey> StartingInventory;
u8 AdditionalHeartContainers;

static void AddItemToInventory(ItemKey item, size_t count = 1) {
  StartingInventory.insert(StartingInventory.end(), count, item);
}

void GenerateStartingInventory() {
  StartingInventory.clear();
  
  if (MapsAndCompasses.Is((u8)MapsAndCompassesSetting::MAPSANDCOMPASSES_START_WITH)) {
    for (auto* dungeon : dungeonList) {
      if (dungeon->GetMap() != NONE) {
        AddItemToInventory(dungeon->GetMap());
      }

      if (dungeon->GetCompass() != NONE) {
        AddItemToInventory(dungeon->GetCompass());
      }
    }
  }
  
  if (Keysanity.Is((u8)KeysanitySetting::KEYSANITY_START_WITH)) {
    for (auto* dungeon : dungeonList) {
      if (dungeon->GetSmallKeyCount() > 0) {
        AddItemToInventory(dungeon->GetSmallKey(), dungeon->GetSmallKeyCount());
      }
    }
  } else if (Keysanity.Is((u8)KeysanitySetting::KEYSANITY_VANILLA)) {
    // Logic cannot handle vanilla key layout in some dungeons
    // this is because vanilla expects the dungeon major item to be
    // locked behind the keys, which is not always true in rando.
    // We can resolve this by starting with some extra keys
    // - OoT Randomizer
    }
  
  
/*
  if (BossKeysanity.Is(BOSSKEYSANITY_START_WITH)) {
    AddItemToInventory(WOODFALL_TEMPLE_BOSS_KEY);
    AddItemToInventory(SNOWHEAD_TEMPLE_BOSS_KEY);
    AddItemToInventory(GBT_BOSS_KEY);
    AddItemToInventory(STONE_TOWER_TEMPLE_BOSS_KEY);
  }*/
  
  //Starting Inventory Menu
  //Values are associated so that the count of items matches the index of
  //the option selected. If None is selected, the value will be zero and
  //zero of the item will be added to the starting inventory.
  AddItemToInventory(PROGRESSIVE_BOMB_BAG,      StartingBombBag.Value<u8>());
 // AddItemToInventory((BombchusInLogic ? PROGRESSIVE_BOMBCHUS : BOMBCHU_20), StartingBombchus.Value<u8>());
  AddItemToInventory(PROGRESSIVE_BOW,           StartingBow.Value<u8>());
  AddItemToInventory(FIRE_ARROWS,               StartingFireArrows.Value<u8>());
  AddItemToInventory(ICE_ARROWS,                StartingIceArrows.Value<u8>());
  AddItemToInventory(LIGHT_ARROWS,              StartingLightArrows.Value<u8>());
  AddItemToInventory(LENS_OF_TRUTH,             StartingLensOfTruth.Value<u8>());
  AddItemToInventory(MAGIC_BEAN_PACK,           StartingMagicBean.Value<u8>());
  AddItemToInventory(HOOKSHOT,     				StartingHookshot.Value<u8>());
  AddItemToInventory(EMPTY_BOTTLE1,				StartingBottle1.Value<u8>());
  AddItemToInventory(EMPTY_BOTTLE2,				StartingBottle2.Value<u8>());
  //AddItemToInventory(BOTTLE_WITH_MILK,			StartingBottle3.Value<u8<());
  //AddItemToInventory(BOTTLE_WITH_RED_POTION,	StartingBottle4.Value<u8<());
  //AddItemToInventory(GOLD_DUST,				    StartingBottle5.Value<u8<());
  //AddItemToInventory(CHATEAU_ROMANI,			StartingBottle6.Value<u8<());
  //AddItemToInventory(EMPTY_BOTTLE1,				StartingBottle7.Value<u8<());
  
  AddItemToInventory(OCARINA_OF_TIME,     		StartingOcarina.Value<u8>());
  AddItemToInventory(OATH_TO_ORDER,             StartingOathToOrder.Value<u8>());
  AddItemToInventory(EPONAS_SONG,               StartingEponasSong.Value<u8>());
  //AddItemToInventory(INVERTED_SONG_OF_TIME,     StartingInvertedSong.Value<u8>());
  //AddItemToInventory(SONG_OF_DOUBLE_TIME,       StartingDoubleSong.Value<u8>());
  //AddItemToInventory(SONG_OF_TIME,              StartingSongOfTime.Value<u8>());
  AddItemToInventory(SONG_OF_STORMS,            StartingSongOfStorms.Value<u8>());
  AddItemToInventory(SONATA_OF_AWAKENING,       StartingSonataOfAwakening.Value<u8>());
  AddItemToInventory(GORONS_LULLABY,            StartingGoronsLullaby.Value<u8>());
  AddItemToInventory(NEW_WAVE_BOSSA_NOVA,       StartingNewWaveBossaNova.Value<u8>());
  AddItemToInventory(ELEGY_OF_EMPTINESS,        StartingElegyOfEmptiness.Value<u8>());
  AddItemToInventory(SONG_OF_HEALING,           StartingSongOfHealing.Value<u8>());
  AddItemToInventory(SONG_OF_SOARING,           StartingSongOfSoaring.Value<u8>());
  AddItemToInventory(KOKIRI_SWORD,              StartingKokiriSword.Value<u8>());
  AddItemToInventory(HEROS_SHIELD,              StartingHerosShield.Value<u8>());
  AddItemToInventory(MIRROR_SHIELD,             StartingMirrorShield.Value<u8>());
  AddItemToInventory(PROGRESSIVE_MAGIC_METER,   StartingMagicMeter.Value<u8>());
  AddItemToInventory(PROGRESSIVE_WALLET,        StartingWallet.Value<u8>());
  AddItemToInventory(DOUBLE_DEFENSE,            StartingDoubleDefense.Value<u8>());
  AddItemToInventory(ODOLWAS_REMAINS,           StartingOdolwaRemains.Value<u8>());
  AddItemToInventory(GOHTS_REMAINS,             StartingGohtRemains.Value<u8>());
  AddItemToInventory(GYORGS_REMAINS,            StartingGyorgRemains.Value<u8>());
  AddItemToInventory(TWINMOLDS_REMAINS,         StartingTwinmoldRemains.Value<u8>());
  //AddItemToInventory(SWAMP_SKULLTULA_TOKEN,     StartingSwampToken.Value<u8>());
  //AddItemToInventory(OCEANSIDE_SKULLTULA_TOKEN, StartingOceanToken.Value<u8>());

  
  s8 hearts = (StartingHealth.Value<u8>() + 2) % 20 - 2;
  AdditionalHeartContainers = 0;
  if (hearts < 0) {
    AddItemToInventory(PIECE_OF_HEART, 4);
    // Plentiful and minimal have less than 4 standard pieces of heart so also replace the winner heart
   

    AdditionalHeartContainers = 1 - hearts;
  } 
  else if (hearts > 0) {
    // 16 containers in plentiful, 8 in balanced and 0 in the others
    u8 maxContainers = 8 * std::max(0, 2 - ItemPoolValue.Value<u8>());
    
    if (hearts <= maxContainers) {
      AddItemToInventory(HEART_CONTAINER, hearts);
    } else {
      AddItemToInventory(HEART_CONTAINER, maxContainers);
      AddItemToInventory(PIECE_OF_HEART, (hearts - maxContainers) * 4);
    }
  }
}

void ApplyStartingInventory() {
  for (ItemKey item : StartingInventory) {
    ItemTable(item).ApplyEffect();
  }
}
