#include "item_pool.hpp"

#include "dungeon.hpp"
#include "fill.hpp"
#include "item_list.hpp"
#include "item_location.hpp"
#include "pool_functions.hpp"
#include "random.hpp"
#include "settings.hpp"
#include "spoiler_log.hpp"

using namespace Settings;
using namespace Dungeon;

std::vector<ItemKey> ItemPool = {};
std::vector<ItemKey> PendingJunkPool = {};
std::vector<u8> IceTrapModels = {};
const std::array<ItemKey, 4> dungeonRewards = {
	ODOLWAS_REMAINS,
	GOHTS_REMAINS,
	GYORGS_REMAINS,
	TWINMOLDS_REMAINS,
};
const std::array<ItemKey, 16> JunkPoolItems = {
	BOMBS_5,
	BOMBS_10,
	BOMBS_20,
	DEKU_NUTS_5,
	BOMBCHU_5,
	BOMBCHU_10,
	RECOVERY_HEART,
	ARROWS_5,
	ARROWS_10,
	ARROWS_30,
	BLUE_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
	HUGE_RUPEE,
	DEKU_NUTS_10,
	ICE_TRAP,
};
const std::array<ItemKey, 81> alwaysItems = {
	GREAT_FAIRYS_SWORD,
	HEROS_SHEILD,
	MIRROR_SHIELD,
	LAND_TITLE,
	SWAMP_TITLE,
	MOUNTAIN_TITLE,
	OCEAN_TITLE,
	BOMBERS_NOTEBOOK,
	ROOM_KEY,
	LETTER_KAFEI,
	PENDANT_MEMORIES,
	LETTER_MAMA,
	MOONS_TEAR,
	SPIN_ATTACK,
	LENS_OF_TRUTH,
	FIRE_ARROWS,
	ICE_ARROWS,
	LIGHT_ARROWS,
	HOOKSHOT,
	MAGIC_BEAN,
	DOUBLE_DEFENSE,
	OCARINA_OF_TIME,
	PICTOGRAPH_BOX,
	POWDER_KEG,
	KEATON_MASK,
	BUNNY_HOOD,
	DEKU_MASK,
	GORON_MASK,
	ZORA_MASK,
	POSTMANS_HAT,
	ALL_NIGHT_MASK,
	BLAST_MASK,
	STONE_MASK,
	GREAT_FAIRYS_MASK,
	BREMEN_MASK,
	DON_GEROS_MASK,
	MASK_OF_SCENTS,
	ROMANIS_MASK,
	CIRCUS_LEADERS_MASK,
	KAFEIS_MASK,
	COUPLES_MASK,
	KAMAROS_MASK,
	GIBDOS_MASK,
	GAROS_MASK,
	CAPTAINS_HAT,
	GIANTS_MASK,
	FIERCE_DIETY_MASK,
	MASK_OF_TRUTH,
	PROGRESSIVE_SWORD, //3 Progressive Swords
	PROGRESSIVE_SWORD,
	PROGRESSIVE_SWORD,
	PROGRESSIVE_BOMB_BAG, //3 Progressive Bomb Bags
	PROGRESSIVE_BOMB_BAG,
	PROGRESSIVE_BOMB_BAG,
	PROGRESSIVE_BOW, //3 Progressive Bows
	PROGRESSIVE_BOW,
	PROGRESSIVE_BOW,
	PROGRESSIVE_WALLET, //2 Progressive wallets
	PROGRESSIVE_WALLET,
	PROGRESSIVE_MAGIC_METER,// 2 Progressive Magic Meters
	PROGRESSIVE_MAGIC_METER,
	OCEANSIDE_SKULLTULA_TOKEN,
	SWAMP_SKULLTULA_TOKEN,
	CT_STRAY_FAIRY,
	WF_STRAY_FAIRY,
	SH_STRAY_FAIRY,
	GBT_STRAY_FAIRY,
	ST_STRAY_FAIRY,
	MAGIC_BEAN,
	BOMBS_10,
	BOMBS_5,
	BOMBS_5,
	BOMBS_20,
	ARROWS_10,
	ARROWS_30,
	ARROWS_10,
	RECOVERY_HEART,
	RECOVERY_HEART,
	RECOVERY_HEART,
	RECOVERY_HEART,
	RECOVERY_HEART,
	
}
const std::array<ItemKey, 54> easyItems = {
	GREAT_FAIRYS_SWORD,
	PROGRESSIVE_SWORD,
	LENS_OF_TRUTH,
	PROGRESSIVE_MAGIC_METER,
	PROGRESSIVE_BOW,
	PROGRESSIVE_BOMB_BAG,
	PROGRESSIVE_WALLET,
	HOOKSHOT,
	DOUBLE_DEFENSE,
	HEROS_SHEILD,
	MIRROR_SHIELD,
	LAND_TITLE,
	SWAMP_TITLE,
	MOUNTAIN_TITLE,
	OCEAN_TITLE,
	BOMBERS_NOTEBOOK,
	ROOM_KEY,
	LETTER_KAFEI,
	PENDANT_MEMORIES,
	LETTER_MAMA,
	MOONS_TEAR,	
	FIRE_ARROWS,
	ICE_ARROWS,
	LIGHT_ARROWS,
	DEKU_MASK,
	ZORA_MASK,
	GORON_MASK,
	GREAT_FAIRYS_MASK,
	FIERCE_DIETY_MASK,
	CT_STRAY_FAIRY,
	WF_STRAY_FAIRY,
	SH_STRAY_FAIRY,
	GBT_STRAY_FAIRY,
	ST_STRAY_FAIRY,
	HEART_CONTAINER, //all 4 heart containers
	HEART_CONTAINER,
	HEART_CONTAINER,
	HEART_CONTAINER,
	PIECE_OF_HEART, //16 heart pieces = 4 heart containers
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
}
const std::array<ItemKey, 41> normalItems = {
	PIECE_OF_HEART, //34 pieces of heart
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	HEART_CONTAINER, //4 HEART_CONTAINER
	HEART_CONTAINER,
	HEART_CONTAINER,
	HEART_CONTAINER,
}

const std::array<ItemKey, 4> MOON_Vanilla = {
	BLUE_RUPEE,
	BLUE_RUPEE,
	BLUE_RUPEE,
	BLUE_RUPEE,
}
const std::array<ItemKey, 17> normalBottles = {
  EMPTY_BOTTLE,
  BOTTLE_WITH_MILK,
  BOTTLE_WITH_RED_POTION,
  BOTTLE_WITH_GREEN_POTION,
  BOTTLE_WITH_BLUE_POTION,
  BOTTLE_WITH_FAIRY,
  BOTTLE_WITH_FISH,
  BOTTLE_WITH_BUGS,
  BOTTLE_WITH_POE,
  BOTTLE_WITH_BIG_POE,
  DEKU_PRINCESS,
  CHATEAU_ROMANI,
  HOT_SPRING_WATER,
  SPRING_WATER,
  GOLD_DUST,
  ZORA_EGG,
  SEAHORSE,
};
const std::array<ItemKey, 39> normalRupees ={
	RED_RUPEE,
	SILVER_RUPEE,
	SILVER_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
	PURPLE_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	HUGE_RUPEE,
	PURPLE_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
	BLUE_RUPEE,
	PURPLE_RUPEE,
	RED_RUPEE,
	SILVER_RUPEE,
	SILVER_RUPEE,
	SILVER_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
	BLUE_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
	BLUE_RUPEE,
	
}
const std::array<ItemKey, 4> dekuScrubItems = {
	HUGE_RUPEE,
	BLUE_POTION_REFILL,
	MAGIC_BEAN,
	GREEN_POTION_REFILL,
}
const std:array<ItemKey, 12> songList = {
	SONG_OF_TIME,
	SONG_OF_DOUBLE_TIME,
	INVERTED_SONG_OF_TIME,
	SONG_OF_STORMS,
	EPONAS_SONG,
	SONG_OF_HEALING,
	SONG_OF_SOARING,
	SONATA_OF_AWAKENING,
	GORONS_LULLABY,
	NEW_WAVE_BOSSA_NOVA,
	ELEGY_OF_EMPTINESS,
	OATH_TO_ORDER
}


void AddItemToPool(std::vector<ItemKey>& pool, ItemKey item, size_t count /*= 1*/) {
  pool.insert(pool.end(), count, item);
}

template <typename FromPool>
static void AddItemsToPool(std::vector<ItemKey>& toPool, const FromPool& fromPool) {
  AddElementsToPool(toPool, fromPool);
}

static void AddItemToMainPool(const ItemKey item, size_t count = 1) {
  ItemPool.insert(ItemPool.end(), count, item);
}

static void AddRandomBottle(std::vector<ItemKey>& bottlePool) {
  AddItemToMainPool(RandomElement(bottlePool, true));
}

ItemKey GetJunkItem() {
  if (IceTrapValue.Is(ICETRAPS_MAYHEM) || IceTrapValue.Is(ICETRAPS_ONSLAUGHT)) {
    return ICE_TRAP;
  } else if (IceTrapValue.Is(ICETRAPS_EXTRA)) {
      return RandomElement(JunkPoolItems);
  }
  //Ice Trap is the last item in JunkPoolItems, so subtract 1 to never hit that index
  u8 idx = Random(0, JunkPoolItems.size() - 1);
  return JunkPoolItems[idx];
}

static ItemKey GetPendingJunkItem() {
  if (PendingJunkPool.empty()) {
    return GetJunkItem();
  }

  return RandomElement(PendingJunkPool, true);
}

//Replace junk items in the pool with pending junk
static void ReplaceMaxItem(const ItemKey itemToReplace, int max) {
  int itemCount = 0;
  for (size_t i = 0; i < ItemPool.size(); i++) {
    if (ItemPool[i] == itemToReplace) {
      if (itemCount >= max) {
        ItemPool[i] = GetJunkItem();
      }
      itemCount++;
    }
  }
}

void PlaceJunkInExcludedLocation(const LocationKey il) {
  //place a non-advancement item in this location
  for (size_t i = 0; i < ItemPool.size(); i++) {
    if (!ItemTable(ItemPool[i]).IsAdvancement()) {
      PlaceItemInLocation(il, ItemPool[i]);
      ItemPool.erase(ItemPool.begin() + i);
      return;
    }
  }
  printf("ERROR: No Junk to Place!!!\n");
}

static void PlaceVanillaDekuScrubItems() {
	PlaceItemInLocation(IKANA_CANYON_SCRUB_PURCHASE,	BLUE_POTION_REFILL);
	PlaceItemInLocation(SOUTHERN_SWAMP_SCRUB_PURCHASE,	MAGIC_BEAN);
	
}

static void PlaceVanillaMapsAndCompasses() {
  for (auto dungeon : dungeonList) {
    dungeon->PlaceVanillaMap();
    dungeon->PlaceVanillaCompass();
  }
}

static void PlaceVanillaSmallKeys() {
  for (auto dungeon : dungeonList) {
    dungeon->PlaceVanillaSmallKeys();
  }
}

static void PlaceVanillaBossKeys() {
  for (auto dungeon : dungeonList) {
    dungeon->PlaceVanillaBossKey();
  }
}
static void PlaceVanillaCowMilk() {
	PlaceItemInLocation(GBC_GROTTO_COW1, MILK);
	PlaceItemInLocation(GBC_GROTTO_COW2, MILK);
	PlaceItemInLocation(ROMANI_RANCH_COW_1, MILK);
	PlaceItemInLocation(ROMANI_RANCH_COW_2, MILK);
	PlaceItemInLocation(ROMANI_RANCH_COW_3, MILK);
	PlaceItemInLocation(TERMINA_FIELD_GROTTO_COW_1, MILK);
	PlaceItemInLocation(TERMINA_FIELD_GROTTO_COW_2, MILK);
	PlaceItemInLocation(BENEATH_THE_WELL_COW, MILK);
}
static void SetScarceItemPool() {
	//todo
}
static void SetMinimalItemPool{
	//todo
}

void GenerateItemPool() {

  ItemPool.clear();

  //Initialize ice trap models to always major items
  IceTrapModels = {
    GI_SWORD_GFS,
    GI_SHIELD_MIRROR,
    GI_HOOKSHOT,
    GI_LENS,
    GI_LAND_TITLE,
    GI_BEAN,
    GI_PICTOGRAPH_BOX,
    GI_POWDER_KEG,
    GI_MASK_FIERCE,
    GI_SWAMP_TOKEN,
    GI_NAYRUS_LOVE,
    GI_ARROW_FIRE,
    GI_ARROW_ICE,
    GI_ARROW_LIGHT,
    0xB8, //Double defense
    GI_OCEANSIDE_TOKEN,
    GI_SWAMP_TITLE, //Progressive hookshot
    GI_OCEAN_TITLE, //Progressive strength
    0x82, //Progressive bomb bag
    0x83, //Progressive bow
    GI_MOUNTAIN_TITLE, //Progressive slingshot
    0x85, //Progressive wallet
    GI_SPIN_ATTACK, //Progressive scale
    0x8A, //Progressive magic
  };
  //Check song shuffle and dungeon reward shuffle just for ice traps
  if (ShuffleSongs.Is(SONGSHUFFLE_ANYWHERE)) {
    //Push item ids for songs
    IceTrapModels.push_back(0xC1);
    IceTrapModels.push_back(0xC2);
    IceTrapModels.push_back(0xC3);
    IceTrapModels.push_back(0xC4);
    IceTrapModels.push_back(0xC5);
    IceTrapModels.push_back(0xC6);
    IceTrapModels.push_back(0xBB);
    IceTrapModels.push_back(0xBC);
    IceTrapModels.push_back(0xBD);
  }
  if (ShuffleRewards.Is(REWARDSHUFFLE_ANYWHERE)) {
    //Push item ids for dungeon rewards
    IceTrapModels.push_back(0xCB);
    IceTrapModels.push_back(0xCC);
    IceTrapModels.push_back(0xCD);
    IceTrapModels.push_back(0xCE);
  }

	//fixed item locations?
	
	if (ShuffleKokiriSword) {
		AddItemToMainPool(KOKIRI_SWORD);
		IceTrapModels.push_back(GI_SWORD_KOKIRI);
	}else{
		PlaceItemInLocation(LINKS_POCKET, KOKIRI_SWORD);
	}
	
  if (ShuffleCows) {
    //9 total cow locations
    for (u8 i = 0; i < 8; i++) {
      AddItemToMainPool(GetJunkItem());
    }
  } else {
    PlaceVanillaCowMilk();
  }
  
  if (ShuffleMagicBeans) {
    AddItemToMainPool(MAGIC_BEAN_PACK);
    if (ItemPoolValue.Is(ITEMPOOL_PLENTIFUL)) {
      AddItemToPool(PendingJunkPool, MAGIC_BEAN_PACK);
    }
    IceTrapModels.push_back(0xC9); //Magic bean pack
  } else {
    PlaceItemInLocation(DEKU_PALACE_BEAN_DADDY, MAGIC_BEAN);
  }
  //TOKEN SANITY
  if (Tokensanity.Is(TOKENSANITY_OFF)) {
    for (LocationKey loc : GetLocations(allLocations, Category::cSwampSkulltula) && 
		 LocationKey loc2 : GetLocations(allLocations, Category::cOceanSkulltula)) {
      PlaceItemInLocation(loc, SWAMP_SKULLTULA_TOKEN);
	  PlaceItemInLocation(loc2, OCEANSIDE_SKULLTULA_TOKEN);
    }
  }  
  else if (Tokensanity.Is(TOKENSANITY_OVERWORLD)) {
    for (LocationKey loc : GetLocations(allLocations, Category::cSwampSkulltula) && 
		 LocationKey loc2 : GetLocations(allLocations, Category::cOceanSkulltula)) {
      if (Location(loc)->IsDungeon()) {
        PlaceItemInLocation(loc, SWAMP_SKULLTULA_TOKEN);
      } else {
        AddItemToMainPool(SWAMP_SKULLTULA_TOKEN);
      }
	  if (Location(loc2)->IsDungeon()) {
		  PlaceItemInLocation(loc2, OCEANSIDE_SKULLTULA_TOKEN);
	  }	else {
		  AddItemToMainPool(OCEANSIDE_SKULLTULA_TOKEN);
	  }
    }
  } 
  else {
    AddItemToMainPool(SWAMP_SKULLTULA_TOKEN, 30);
	AddItemToMainPool(OCEANSIDE_SKULLTULA_TOKEN, 30);
  }
  
  //STRAY FAIRY SANITY
  if (Straysanity.IS(STRAYSANITY_OFF)) {//if off place in vanilla locations
	for (LocationKey loc1 : GetLocations(allLocations, Category::cCTStray) &&
		 LocationKey loc2 : GetLocations(allLocations, Category::cWFStray) &&
		 LocationKey loc3 : GetLocations(allLocations, Category::cSHStray) &&
		 LocationKey loc4 : GetLocations(allLocations, Category::cGBTStray) &&
		 LocationKey loc5 : GetLocations(allLocations, Category::cSTStray) )
		 {
			PlaceItemInLocation(loc1, CT_STRAY_FAIRY);
			PlaceItemInLocation(loc2, WF_STRAY_FAIRY);
			PlaceItemInLocation(loc3, SH_STRAY_FAIRY);
			PlaceItemInLocation(loc4, GBT_STRAY_FAIRY);
			PlaceItemInLocation(loc5, ST_STRAY_FAIRY);
		 }
  }
  else if (Straysanity.IS(STRAYSANITY_OVERWORLD) { //if overworld place wherever
	  for (LocationKey loc1 : GetLocations(allLocations, Category::cCTStray) &&
		 LocationKey loc2 : GetLocations(allLocations, Category::cWFStray) &&
		 LocationKey loc3 : GetLocations(allLocations, Category::cSHStray) &&
		 LocationKey loc4 : GetLocations(allLocations, Category::cGBTStray) &&
		 LocationKey loc5 : GetLocations(allLocations, Category::cSTStray) )
		 {
			 if (Location(loc1)->IsDungeon()) {PlaceItemInLocation(loc1, CT_STRAY_FAIRY);} 
			 else {AddItemToMainPool(CT_STRAY_FAIRY);}
			 
			 if (Location(loc2)->IsDungeon()) {PlaceItemInLocation(loc2, WF_STRAY_FAIRY);}
			 else {AddItemToMainPool(WF_STRAY_FAIRY);}
			 
			 if (Location(loc3)->IsDungeon()) {PlaceItemInLocation(loc3, SH_STRAY_FAIRY);}
			 else {AddItemToMainPool(SH_STRAY_FAIRY);}
			 
			 if (Location(loc4)->IsDungeon()) {PlaceItemInLocation(loc4, GBT_STRAY_FAIRY);}
			 else {AddItemToMainPool(GBT_STRAY_FAIRY);}
			 
			 if (Location(loc5)->IsDungeon()) {PlaceItemInLocation(loc5, ST_STRAY_FAIRY);}
			 else {AddItemToMainPool(ST_STRAY_FAIRY);}					 
		 }
  }
  else { AddItemToMainPool(CT_STRAY_FAIRY,1); //if no selection or error ??
		 AddItemToMainPool(WF_STRAY_FAIRY,15);
		 AddItemToMainPool(SH_STRAY_FAIRY,15);
		 AddItemToMainPool(GBT_STRAY_FAIRY,15);
		 AddItemToMainPool(ST_STRAY_FAIRY,15);
	}
  
  if (BombchusInLogic) {
    AddItemToMainPool(PROGRESSIVE_BOMBCHUS, 5);
  } else {
    AddItemToMainPool(BOMBCHU_5);
    AddItemToMainPool(BOMBCHU_10, 3);
    AddItemToMainPool(BOMBCHU_20);
  }
  
  //Ice Traps
  AddItemToMainPool(ICE_TRAP);
  if (GerudoTrainingGrounds.IsVanilla()) {
    AddItemToMainPool(ICE_TRAP);
  }
  if (GanonsCastle.IsVanilla()) {
    AddItemToMainPool(ICE_TRAP, 4);
  }
  
  if (ItemPoolValue.Is(ITEMPOOL_PLENTIFUL)) {
    
    //Plentiful small keys
    if (Keysanity.Is(KEYSANITY_ANYWHERE)) {
      AddItemToPool(PendingJunkPool, WOODFALL_TEMPLE_SMALL_KEY);
      AddItemToPool(PendingJunkPool, SNOWHEAD_TEMPLE_SMALL_KEY);
      AddItemToPool(PendingJunkPool, GBT_SMALL_KEY);
      AddItemToPool(PendingJunkPool, STONE_TOWER_TEMPLE_SMALL_KEY);
    }

    if (BossKeysanity.Is(BOSSKEYSANITY_ANYWHERE)) {
      AddItemToPool(PendingJunkPool, WOODFALL_TEMPLE_BOSS_KEY);
      AddItemToPool(PendingJunkPool, SNOWHEAD_TEMPLE_BOSS_KEY);
      AddItemToPool(PendingJunkPool, GBT_TEMPLE_BOSS_KEY);
      AddItemToPool(PendingJunkPool, STONE_TOWER_TEMPLE_BOSS_KEY);
    }

  }
  
  if (Settings::Scrubsanity.IsNot(SCRUBSANITY.OFF)){
	   AddItemsToPool(ItemPool, dekuScrubItems);
	   //I'm not sure what this is for, but it was in ootr3d so I copied it
    for (u8 i = 0; i < 7; i++) {
      if (Random(0, 3)) {
        AddItemToMainPool(ARROWS_30);
      } else {
        AddItemToMainPool(DEKU_SEEDS_30);
      }
    }
  } else {
    PlaceVanillaDekuScrubItems();
  }
  
  AddItemsToPool(ItemPool, alwaysItems);
  AddItemsToPool(ItemPool, dungeonRewards);
  
  //Add 7 total bottles
  u8 bottleCount = 7;
  std::vector<ItemKey> bottles;
  bottles.assign(normalBottles.begin(), normalBottles.end());
  IceTrapModels.push_back(ItemTable(RandomElement(bottles)).GetItemID()); //Get one random bottle type for ice traps
  for (u8 i = 0; i < bottleCount; i++) {
      AddRandomBottle(bottles);
    }
  
  //add extra songs only if song shuffle is anywhere
  AddItemsToPool(ItemPool, songList);
  if (ShuffleSongs.Is(SONGSHUFFLE_ANYWHERE) && ItemPoolValue.Is(ITEMPOOL_PLENTIFUL)) {
    AddItemsToPool(PendingJunkPool, songList);
  }

  /*For item pool generation, dungeon items are either placed in their vanilla
  | location, or added to the pool now and filtered out later depending on when
  | they need to get placed or removed in fill.cpp. These items are kept in the
  | pool until removal because the filling algorithm needs to know all of the
  | advancement items that haven't been placed yet for placing higher priority
  | items like stones/medallions.*/

  if (MapsAndCompasses.Is(MAPSANDCOMPASSES_VANILLA)) {
    PlaceVanillaMapsAndCompasses();
  } else  {
    for (auto dungeon : dungeonList) {
      if (dungeon->GetMap() != NONE) {
        AddItemToMainPool(dungeon->GetMap());
      }

      if (dungeon->GetCompass() != NONE) {
        AddItemToMainPool(dungeon->GetCompass());
      }
    }
  }

  if (Keysanity.Is(KEYSANITY_VANILLA)) {
    PlaceVanillaSmallKeys();
  } else {
    for (auto dungeon : dungeonList) {
      if (dungeon->GetSmallKeyCount() > 0) {
        AddItemToMainPool(dungeon->GetSmallKey(), dungeon->GetSmallKeyCount());
      }
    }
  }

  if (BossKeysanity.Is(BOSSKEYSANITY_VANILLA)) {
    PlaceVanillaBossKeys();
  } else {
    AddItemToMainPool(WOODFALL_TEMPLE_BOSS_KEY);
    AddItemToMainPool(SNOWHEAD_TEMPLE_BOSS_KEY);
    AddItemToMainPool(GBT_BOSS_KEY);
    AddItemToMainPool(STONE_TOWER_TEMPLE_BOSS_KEY);
  }

	if (ItemPoolValue.Is(ITEMPOOL_PLENTIFUL)) {
    AddItemsToPool(ItemPool, easyItems);
  } else {
    AddItemsToPool(ItemPool, normalItems);
  }

  if (!ShuffleKokiriSword) {
    ReplaceMaxItem(KOKIRI_SWORD, 0);
  }

	//Replace ice traps with junk from the pending junk pool if necessary
  if (IceTrapValue.Is(ICETRAPS_OFF)) {
    ReplaceMaxItem(ICE_TRAP, 0);
  }
  //Replace all junk items with ice traps for onslaught mode
  else if (IceTrapValue.Is(ICETRAPS_ONSLAUGHT)) {
    for (u8 i = 0; i < JunkPoolItems.size() - 3; i++) { // -3 Omits Huge Rupees and Deku Nuts 10
      ReplaceMaxItem(JunkPoolItems[i], 0);
    }
  }
	
	if (ItemPoolValue.Is(ITEMPOOL_SCARCE)) {//TO DO 
    SetScarceItemPool();
  } else if (ItemPoolValue.Is(ITEMPOOL_MINIMAL)) {
    SetMinimalItemPool();
  } else if (RemoveDoubleDefense) {
    ReplaceMaxItem(DOUBLE_DEFENSE, 0);
  }
	
	//this feels ugly and there's probably a better way, but
  //it replaces random junk with pending junk.
  bool junkSet;
  for (ItemKey pendingJunk : PendingJunkPool) {
    junkSet = false;
    for (ItemKey& item : ItemPool) {
      for (ItemKey junk : JunkPoolItems) {
        if (item == junk && item != HUGE_RUPEE && item != DEKU_NUTS_10) {
          item = pendingJunk;
          junkSet = true;
          break;
        }
      }
      if (junkSet) break;
    }
  }

void AddJunk() {
  PlacementLog_Msg("HAD TO PLACE EXTRA JUNK ");
  AddItemToMainPool(GetPendingJunkItem());
}

	
}