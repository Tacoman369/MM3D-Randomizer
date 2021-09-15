#include "item_location.hpp"

#include "dungeon.hpp"
#include "settings.hpp"
#include "spoiler_log.hpp"
#include "shops.hpp"
#include "debug.hpp"
#include "keys.hpp"

//Location definitions
static std::array<ItemLocation, KEY_ENUM_MAX> locationTable;

void LocationTable_Init() {
    locationTable[NONE]                                  = ItemLocation::Base       (0xFF, 0xFF, "Invalid Location",                     NONE,                                  NONE,                      {},                                                                                                                   SpoilerCollectionCheck::None());
    //LocationTable                                                             itemlocation::type      scene  flag  name                                   				hint key (hint_list.cpp)               vanilla item             categories                                                                                                            collection check (if needed)                             collection check group
    
	//Happy Mask Salesman - Starting Items
	locationTable[HMS_SONG_OF_HEALING]										   = ItemLocationBase		(Scene,Flag, "Happy Mask Salesman Song of Healing",					HMS_SONG_OF_HEALING,				SONG_OF_HEALING,			{Category::cClockTower, },																												 	SpoilerCollectionCheckGroup::GROUP_CLOCK_TOWER);
	locationTable[HMS_OCARINA_OF_TIME]										   = ItemLocationBase		(Scene,Flag, "Happy Mask Salesman Ocarina of Time",					HMS_OCARINA_OF_TIME,				OCARINA_OF_TIME,			{Category::cClockTower, },																												 	SpoilerCollectionCheckGroup::GROUP_CLOCK_TOWER);
	locationTable[HMS_DEKU_MASK]											   = ItemLocationBase		(Scene,Flag, "Happy Mask Salesman Deku Mask",						HMS_DEKU_MASK,						DEKU_MASK,					{Category::cClockTower, },																												 	SpoilerCollectionCheckGroup::GROUP_CLOCK_TOWER);
	locationTable[HMS_BOMBERS_NOTEBOOK]										   = ItemLocationBase		(Scene,Flag, "Happy Mask Salesman Bombers Notebook",				HMS_BOMBERS_NOTEBOOK,				BOMBERS_NOTEBOOK,			{Category::cClockTower, },																												 	SpoilerCollectionCheckGroup::GROUP_CLOCK_TOWER);
	locationTable[HMS_KOKIRI_SWORD]											   = ItemLocationBase		(Scene,Flag, "Happy Mask Salesman Kokiri Sword",					HMS_KOKIRI_SWORD,					PROGRESSIVE_SWORD,			{Category::cClockTower, },																												 	SpoilerCollectionCheckGroup::GROUP_CLOCK_TOWER);
	locationTable[HMS_HEROS_SHEILD]											   = ItemLocationBase		(Scene,Flag, "Happy Mask Salesman Heros Shield",					HMS_HEROS_SHEILD,					HEROS_SHIELD,				{Category::cClockTower, },																												 	SpoilerCollectionCheckGroup::GROUP_CLOCK_TOWER);
	
	
	//Deku Palace
	locationTable[DEKU_PALACE_BEAN_DADDY]									   = ItemLocation::Base		(Scene,Flag, "Deku Palace Bean Daddy",								DEKU_PALACE_BEAN_DADDY,				MAGIC_BEAN,					{Category::cDekuPalace,Category::cWoodfall,},																													SpoilerCollectionCheckGroup::GROUP_DEKU_PALACE);
	locationTable[DEKU_PALACE_WEST_GARDEN]									   = ItemLocation::Collectable(Scene,Flag, "Deku Palace West Garden",							DEKU_PALACE_WEST_GARDEN,			PIECE_OF_HEART,				{Category::cDekuPalace,Category::cWoodfall,},																													SpoilerCollectionCheckGroup::GROUP_DEKU_PALACE);
	locationTable[DEKU_PALACE_BUTLER_RACE]									   = ItemLocation::Base		(Scene,Flag, "Deku Palace Butler Race",								DEKU_PALACE_BUTLER_RACE,			MASK_OF_SCENTS,				{Category::cDekuPalace,Category::cWoodfall,},																													SpoilerCollectionCheckGroup::GROUP_DEKU_PALACE);
	locationTable[DEKU_PALACE_IMPRISONED_MONKEY]							   = ItemLocation::Base		(Scene,Flag, "Deku Palace Imprisoned Monkey",						DEKU_PALACE_IMPRISONED_MONKEY,		SONATA_OF_AWAKENING,		{Category::cDekuPalace,Category::cSong,Category::cWoodfall,},																													SpoilerCollectionCheckGroup::GROUP_DEKU_PALACE);
	locationTable[DEKU_PALACE_BEAN_GROTTO]									   = ItemLocation::Chest	(Scene,Flag, "Deku Palace Bean Grotto Chest",						DEKU_PALACE_BEAN_GROTTO,			RED_RUPEE,					{Category::cDekuPalace,Category::cGrotto,Category::cWoodfall,},																													SpoilerCollectionCheckGroup::GROUP_DEKU_PALACE);
	
	//East Clock Town
	locationTable[E_CLOCK_TOWN_AROMA_IN_BAR]								   = ItemLocation::Base		(Scene,Flag, "Madame Aroma in the Bar",								E_CLOCK_TOWN_AROMA_IN_BAR,			CHATEAU_ROMANI,				{Category::cEClockTown,},																													SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	locationTable[E_CLOCK_TOWN_ARCHERY_1]									   = ItemLocation::Base		(Scene,Flag, "Clock Town Archery #1",								E_CLOCK_TOWN_ARCHERY_1,				PROGRESSIVE_BOW,			{Category::cEClockTown, Category::cMinigame,},																								SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	locationTable[E_CLOCK_TOWN_MAYOR]										   = ItemLocation::Base		(Scene,Flag, "Mayor Check",											E_CLOCK_TOWN_MAYOR,					PIECE_OF_HEART,				{Category::cEClockTown,},																													SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	locationTable[E_CLOCK_TOWN_ARCHERY_2]									   = ItemLocation::Base		(Scene,Flag, "Clock Town Archery #2",								E_CLOCK_TOWN_ARCHERY_2,				PIECE_OF_HEART,				{Category::cEClockTown, Category::cMinigame,},																								SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	locationTable[E_CLOCK_TOWN_HONEY_DARLING_3DAYS]							   = ItemLocation::Base		(Scene,Flag, "Honey and Darling 3 Days",							E_CLOCK_TOWN_HONEY_DARLING_3DAYS,	PIECE_OF_HEART,				{Category::cEClockTown, Category::cMinigame,},																								SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	locationTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON]					   = ItemLocation::Base		(Scene,Flag, "Treasure Chest Game (Goron)",							E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON,	PIECE_OF_HEART,			{Category::cEClockTown, Category::cMinigame,},																								SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	locationTable[E_CLOCK_TOWN_POSTMAN_FREEDOM]								   = ItemLocation::Base		(Scene,Flag, "Postman's Freedom",									E_CLOCK_TOWN_POSTMAN_FREEDOM,		POSTMANS_HAT,				{Category::cEClockTown,},																													SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	locationTable[E_CLOCK_TOWN_GORMAN]										   = ItemLocation::Base		(Scene,Flag, "Gorman in the Bar",									E_CLOCK_TOWN_GORMAN,				CIRCUS_LEADERS_MASK,		{Category::cEClockTown,},																													SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	locationTable[E_CLOCK_TOWN_AROMA_IN_OFFICE]								   = ItemLocation::Base		(Scene,Flag, "Madame Aroma in the Mayor's Office",					E_CLOCK_TOWN_AROMA_IN_OFFICE,		KAFEIS_MASK,				{Category::cEClockTown,},																													SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	locationTable[E_CLOCK_TOWN_BOMBERS_HIDEOUT_CHEST]						   = ItemLocation::Chest	(Scene,Flag, "Bombers' Hideout Chest",								E_CLOCK_TOWN_BOMBERS_HIDEOUT_CHEST,	SILVER_RUPEE,				{Category::cEClockTown,},																													SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	locationTable[E_CLOCK_TOWN_CHEST]										   = ItemLocation::Chest	(Scene,Flag, "East Clock Town Chest",								E_CLOCK_TOWN_CHEST,					SILVER_RUPEE,				{Category::cEClockTown,},																													SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	locationTable[E_CLOCK_TOWN_MILK_BAR_CHATEAU]							   = ItemLocation::Base		(Scene,Flag, "Milk Bar Chateau Buy",								E_CLOCK_TOWN_MILK_BAR_CHATEAU,		CHATEAU_ROMANI,				{Category::cEClockTown,},																													SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	locationTable[E_CLOCK_TOWN_MILK_BAR_MILK]								   = ItemLocation::Base		(Scene,Flag, "Milk Bar Milk Buy",									E_CLOCK_TOWN_MILK_BAR_MILK,			MILK,						{Category::cEClockTown,},																													SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	locationTable[E_CLOCK_TOWN_GORMAN_QUEST]								   = ItemLocation::Base		(Scene,Flag, "Gorman's Mystery Milk Quest",							E_CLOCK_TOWN_GORMAN_QUEST,			EMPTY_BOTTLE,				{Category::cEClockTown,},																													SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	//locationTable[E_CLOCK_TOWN_HONEY_DARLING_ANY_DAY]						   = ItemLocation::Base		(Scene,Flag, "Honey and Darling Any Day",							E_CLOCK_TOWN_HONEY_DARLING_ANY_DAY,	PURPLE_RUPEE,				{Category::cEClockTown,Category::cMinigame,},																								SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	//locationTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_HUMAN]					   = ItemLocation::Base		(Scene,Flag, "Treasure Chest Game (Human)",						E_CLOCK_TOWN_TREASURE_CHEST_GAME_HUMAN	PURPLE_RUPEE,				{Category::cEClockTown,Category::cMinigame,},																								SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	//locationTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_ZORA]					   = ItemLocation::Base		(Scene,Flag, "Treasure Chest Game (Zora)",							E_CLOCK_TOWN_TREASURE_CHEST_GAME_ZORA,	RED_RUPEE,				{Category::cEClockTown,Category::cMinigame,},																								SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);
	//locationTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_DEKU]					   = ItemLocation::Base		(Scene,Flag, "Treasure Chest Game (Deku)",							E_CLOCK_TOWN_TREASURE_CHEST_GAME_DEKU,	DEKU_NUTS_10,			{Category::cEClockTown,Category::cMinigame,},																								SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN);

	//Goron Village
	locationTable[GORON_VILLAGE_POWDER_KEG_CHALLENGE]						   = ItemLocation::Base		(Scene,Flag, "Powder Keg Challenge",								GORON_VILLAGE_POWDER_KEG_CHALLENGE,		POWDER_KEG,				{Category::cGoronVillage,},																													SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE);
	locationTable[GORON_VILLAGE_BIGGEST_BOMB_BAG_BUY]						   = ItemLocation::Base		(Scene,Flag, "Biggest Bomb Bag Buy",								GORON_VILLAGE_BIGGEST_BOMB_BAG_BUY,		PROGRESSIVE_BOMB_BAG,	{Category::cGoronVillage,},																													SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE);
	locationTable[GORON_VILLAGE_LENS_OF_TRUTH_CHEST]						   = ItemLocation::Chest	(Scene,Flag, "Lens of Truth Chest",									GORON_VILLAGE_LENS_OF_TRUTH_CHEST,		LENS_OF_TRUTH,			{Category::cGoronVillage,},																													SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE);
	locationTable[GORON_VILLAGE_MOUNTAIN_TITLE_DEED]						   = ItemLocation::Base		(Scene,Flag, "Mountain Title Deed",									GORON_VILLAGE_MOUNTAIN_TITLE_DEED,		MOUNTAIN_TITLE,			{Category::cGoronVillage,},																													SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE);
	locationTable[GORON_VILLAGE_PIECE_OF_HEART]								   = ItemLocation::Collectable(Scene,Flag, "Goron Village Piece of Heart",						GORON_VILLAGE_PIECE_OF_HEART,			PIECE_OF_HEART,			{Category::cGoronVillage,},																													SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE);
	locationTable[GORON_VILLAGE_GORON_LULLABY]								   = ItemLocation::Base		(Scene,Flag, "Goron Lullaby",										GORON_VILLAGE_GORON_LULLABY,				GORONS_LULLABY,		{Category::cGoronVillage, Category::cSong,},																												SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE);
	locationTable[GORON_VILLAGE_LENS_CAVE_INVISIBLE_CHEST]					   = ItemLocation::Chest	(Scene,Flag, "Lens Cave Invisible Chest",							GORON_VILLAGE_LENS_CAVE_INVISIBLE_CHEST,	RED_RUPEE,			{Category::cGoronVillage,},																												SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE);
	locationTable[GORON_VILLAGE_LENS_CAVE_ROCK_CHEST]						   = ItemLocation::Chest	(Scene,Flag, "Lens Cave Rock Chest",								GORON_VILLAGE_LENS_CAVE_ROCK_CHEST,		PURPLE_RUPEE,			{Category::cGoronVillage,},																												SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE);

	//Great Bay Coast
	locationTable[GBC_OCEAN_SPIDER_DAY1]									   = ItemLocation::Base		(Scene,Flag, "Oceanside Spider House Day 1 Reward",					GBC_OCEAN_SPIDER_DAY1,				PROGRESSIVE_WALLET,			{Category::cGreatBayCoast,},																												SpoilerCollectionCheckGroup::GROUP_GBC);
	locationTable[GBC_OCEAN_SPIDER_DAY2]									   = ItemLocation::Base		(Scene,Flag, "Oceanside Spider House Day 2 Reward",					GBC_OCEAN_SPIDER_DAY2,				PURPLE_RUPEE,				{Category::cGreatBayCoast,},																												SpoilerCollectionCheckGroup::GROUP_GBC);
	locationTable[GBC_OCEAN_SPIDER_DAY3]									   = ItemLocation::Base		(Scene,Flag, "Oceanside Spider House Day 3 Reward",					GBC_OCEAN_SPIDER_DAY3,				RED_RUPEE,					{Category::cGreatBayCoast,},																												SpoilerCollectionCheckGroup::GROUP_GBC);
	locationTable[GBC_FISHERMAN_GAME]										   = ItemLocation::Base		(Scene,Flag, "Great Bay Coast Fisherman's Game",					GBC_FISHERMAN_GAME,					PIECE_OF_HEART,				{Category::cGreatBayCoast, Category::cMinigame,},																							SpoilerCollectionCheckGroup::GROUP_GBC);
	locationTable[GBC_OCEAN_SPIDER_CHEST]									   = ItemLocation::Chest	(Scene,Flag, "Oceanside Spider House Chest",						GBC_OCEAN_SPIDER_CHEST,				PIECE_OF_HEART,				{Category::cGreatBayCoast,},																												SpoilerCollectionCheckGroup::GROUP_GBC);
	locationTable[GBC_LAB_FISH]												   = ItemLocation::Base		(Scene,Flag, "Greay Bay Lab Fish",									GBC_LAB_FISH,						PIECE_OF_HEART,				{Category::cGreatBayCoast,},																												SpoilerCollectionCheckGroup::GROUP_GBC);
	locationTable[GBC_LEDGE]												   = ItemLocation::Base		(Scene,Flag, "Great Bay Coast Ledge",								GBC_LEDGE,							PIECE_OF_HEART,				{Category::cGreatBayCoast,},																												SpoilerCollectionCheckGroup::GROUP_GBC);
	locationTable[GBC_MIKAU]												   = ItemLocation::Base		(Scene,Flag, "Great Bay Coast Mikau",								GBC_MIKAU,							ZORA_MASK,					{Category::cGreatBayCoast, Category::cVanillaMask},																												SpoilerCollectionCheckGroup::GROUP_GBC);
	locationTable[GBC_BABY_ZORAS]											   = ItemLocation::Base		(Scene,Flag, "Great Bay Coast Baby Zoras",							GBC_BABY_ZORAS,						NEW_WAVE_BOSSA_NOVA,		{Category::cGreatBayCoast, Category::cSong,},																												SpoilerCollectionCheckGroup::GROUP_GBC);
	locationTable[GBC_STONE_TOWER_BUY]										   = ItemLocation::Base		(Scene,Flag, "Great Bay Coast Stone Tower Map Buy",					GBC_STONE_TOWER_BUY,				STONE_TOWER_MAP,			{Category::cGreatBayCoast, Category::cVanillaMap},																												SpoilerCollectionCheckGroup::GROUP_GBC);
	locationTable[GBC_GROTTO]												   = ItemLocation::Chest	(Scene,Flag, "Great Bay Coast Grotto Chest",						GBC_GROTTO,							RED_RUPEE,					{Category::cGreatBayCoast,Category::cGrotto},																												SpoilerCollectionCheckGroup::GROUP_GBC);
	locationTable[GBC_FISHERMAN_PHOTO]										   = ItemLocation::Base		(Scene,Flag, "Great Bay Coast FIsherman Photo",						GBC_FISHERMAN_PHOTO,				SEAHORSE,					{Category::cGreatBayCoast,},																												SpoilerCollectionCheckGroup::GROUP_GBC);
	   
	//Ikana Canyon
	locationTable[IKANA_CANYON_GREAT_FAIRY]									   = ItemLocation::Base 	  (Scene,Flag, "Ikana Canyon Great Fairy",							IKANA_CANYON_GREAT_FAIRY,			GREAT_FAIRYS_SWORD,				{Category::cIkanaCanyon,},																													SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON);
	locationTable[IKANA_CANYON_POE_HUT]										   = ItemLocation::Base 	  (Scene,Flag, "Ikana Canyon Poe Hut",								IKANA_CANYON_POE_HUT,				PIECE_OF_HEART,					{Category::cIkanaCanyon,},																													SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON);
	locationTable[IKANA_CANYON_LEDGE]										   = ItemLocation::Collectable(Scene,Flag, "Ikana Canyon Ledge",								IKANA_CANYON_LEDGE,					PIECE_OF_HEART,					{Category::cIkanaCanyon,},																													SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON);
	locationTable[IKANA_CANYON_PAMELAS_FATHER]								   = ItemLocation::Base 	  (Scene,Flag, "Ikana Canyon Pamela's Father",						IKANA_CANYON_PAMELAS_FATHER,		GIBDO_MASK,						{Category::cIkanaCanyon,},																													SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON);
	locationTable[IKANA_CANYON_SECRET_SHRINE_GROTTO]						   = ItemLocation::Chest 	  (Scene,Flag, "Ikana Canyon Secret Shrine Grotto",					IKANA_CANYON_SECRET_SHRINE_GROTTO,	BOMBCHU_5,						{Category::cIkanaCanyon, Category::cGrotto},																								SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON);
	locationTable[IKANA_CANYON_SCRUB_TRADE]									   = ItemLocation::Base 	  (Scene,Flag, "Ikana Canyon Scrub Trade",							IKANA_CANYON_SCRUB_TRADE,			HUGE_RUPEE,						{Category::cIkanaCanyon, Category::cDekuScrub},																								SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON);
	locationTable[IKANA_CANYON_SCRUB_PURCHASE]								   = ItemLocation::Base 	  (Scene,Flag, "Ikana Canyon Scrub Purchase",						IKANA_CANYON_SCRUB_PURCHASE,		POTION_BLUE_REFILL,				{Category::cIkanaCanyon, Category::cDekuScrub},																								SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON);
	
	//Ikana Graveyard
	locationTable[IKANA_GRAVEYARD_DAMPE_DIGGING]							   = ItemLocation::Base 	  (Scene,Flag, "Ikana Graveyard Dampe Digging",						IKANA_GRAVEYARD_DAMPE_DIGGING,		EMPTY_BOTTLE,					{Category::cIkanaGraveyard, Category::cMinigame},																							SpoilerCollectionCheckGroup::GROUP_IKANA_GRAVEYARD);
	locationTable[IKANA_GRAVEYARD_IRON_KNUCKLE_CHEST]						   = ItemLocation::Chest 	  (Scene,Flag, "Ikana Graveyard Iron Knuckle Chest",				IKANA_GRAVEYARD_IRON_KNUCKLE_CHEST,	PIECE_OF_HEART,					{Category::cIkanaGraveyard, },																												SpoilerCollectionCheckGroup::GROUP_IKANA_GRAVEYARD);
	locationTable[IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST]						   = ItemLocation::Chest 	  (Scene,Flag, "Ikana Graveyard Captain Keeta's Chest",				IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST,CAPTAINS_HAT,					{Category::cIkanaGraveyard, },																												SpoilerCollectionCheckGroup::GROUP_IKANA_GRAVEYARD);
	locationTable[IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET]						   = ItemLocation::Base 	  (Scene,Flag, "Ikana Graveyard Day 1 Grave Tablet",				IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET,SONG_OF_STORMS,				{Category::cIkanaGraveyard, Category::cSong,},																								SpoilerCollectionCheckGroup::GROUP_IKANA_GRAVEYARD);
	locationTable[IKANA_GRAVEYARD_DAY_ONE_GRAVE_BATS]						   = ItemLocation::Chest 	  (Scene,Flag, "Ikana Graveyard Day 1 Grave Bats",					IKANA_GRAVEYARD_DAY_ONE_GRAVE_BATS,	PURPLE_RUPEE,					{Category::cIkanaGraveyard, },																												SpoilerCollectionCheckGroup::GROUP_IKANA_GRAVEYARD);
	locationTable[IKANA_GRAVEYARD_GROTTO]									   = ItemLocation::Chest 	  (Scene,Flag, "Ikana Graveyard Grotto",							IKANA_GRAVEYARD_GROTTO,				BOMBCHU_5,						{Category::cIkanaGraveyard, Category::cGrotto},																								SpoilerCollectionCheckGroup::GROUP_IKANA_GRAVEYARD);
	
	//Laundry Pool
	locationTable[LAUNDRY_POOL_KAFEI]										   = ItemLocation::Base		  (Scene,Flag, "Laundry Pool Kafei",								LAUNDRY_POOL_KAFEI,					PENDANT_OF_MEMORIES,			{Category::cLaundryPool,},																													SpoilerCollectionCheckGroup::GROUP_LAUNDRY_POOL);
	locationTable[LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE]						   = ItemLocation::Base		  (Scene,Flag, "Laundry Pool Curiosity Shop Man 1",					LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE,KEATON_MASK,					{Category::cLaundryPool,},																													SpoilerCollectionCheckGroup::GROUP_LAUNDRY_POOL);
	locationTable[LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO]						   = ItemLocation::Base		  (Scene,Flag, "Laundry Pool Curiosity Shop Man 2",					LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO,LETTER_MAMA,					{Category::cLaundryPool,},																													SpoilerCollectionCheckGroup::GROUP_LAUNDRY_POOL);
	locationTable[LAUNDRY_POOL_GURU_GURU]									   = ItemLocation::Base		  (Scene,Flag, "Laundry Pool Guru Guru",							LAUNDRY_POOL_GURU_GURU,				BREMEN_MASK,					{Category::cLaundryPool,},																													SpoilerCollectionCheckGroup::GROUP_LAUNDRY_POOL);
	
	//Milk Road
	locationTable[MILK_ROAD_GORMAN_RACE]									   = ItemLocation::Base 	   (Scene,Flag, "Milk Road Gorman Bros Race",						MILK_ROAD_GORMAN_RACE,				GAROS_MASK,						{Category::cMilkRoad, Category::cMinigame},																									SpoilerCollectionCheckGroup:;GROUP_MILK_ROAD);
	locationTable[MILK_ROAD_ROMANI_RANCH_MAP_BUY]							   = ItemLocation::Base 	   (Scene,Flag, "Milk Road Romani Ranch Map Purchase",				MILK_ROAD_ROMANI_RANCH_MAP_BUY,		ROMANI_RANCH_MAP,				{Category::cMilkRoad, Category::cVanillaMap},																								SpoilerCollectionCheckGroup:;GROUP_MILK_ROAD);
	locationTable[MILK_ROAD_GREAT_BAY_MAP_BUY]								   = ItemLocation::Base 	   (Scene,Flag, "Milk Road Great Bay Map Purchase",					MILK_ROAD_GREAT_BAY_MAP_BUY,		GREAT_BAY_MAP,					{Category::cMilkRoad, Category::cVanillaMap},																								SpoilerCollectionCheckGroup:;GROUP_MILK_ROAD);
	//locationTable[MILK_ROAD_GORMAN_MILK_BUY]								   = ItemLocation::Base 	   (Scene,Flag, "Milk Road Gorman Bros Milk Purchase",				MILK_ROAD_GORMAN_MILK_BUY,			MILK,							{Category::cMilkRoad, },																													SpoilerCollectionCheckGroup:;GROUP_MILK_ROAD);
		
	//Mountain Village
	locationTable[MOUNTAIN_VILLAGE_SMITH_DAY_ONE]							   = ItemLocation::Base		   (Scene,Flag, "Mountain Village Smith Day 1",						MOUNTAIN_VILLAGE_SMITH_DAY_ONE,		PROGRESSIVE_SWORD,				{Category::cMountainVillage,},																												SpoilerCollectionCheckGroup::GROUP_MOUNTAIN_VILLAGE);
	locationTable[MOUNTAIN_VILLAGE_SMITH_DAY_TWO]							   = ItemLocation::Base		   (Scene,Flag, "Mountain Village Smith Day 2",						MOUNTAIN_VILLAGE_SMITH_DAY_TWO,		PROGRESSIVE_SWORD,				{Category::cMountainVillage,},																												SpoilerCollectionCheckGroup::GROUP_MOUNTAIN_VILLAGE);
	locationTable[MOUNTAIN_VILLAGE_FROG_CHOIR]								   = ItemLocation::Base		   (Scene,Flag, "Mountain Village Frog Choir",						MOUNTAIN_VILLAGE_FROG_CHOIR,		PIECE_OF_HEART,					{Category::cMountainVillage,},																												SpoilerCollectionCheckGroup::GROUP_MOUNTAIN_VILLAGE);
	locationTable[MOUNTAIN_VILLAGE_DARMANI]									   = ItemLocation::Base		   (Scene,Flag, "Mountain Village Darmani",							MOUNTAIN_VILLAGE_DARMANI,			GORON_MASK,						{Category::cMountainVillage, Category::cVanillaMask},																						SpoilerCollectionCheckGroup::GROUP_MOUNTAIN_VILLAGE);
	locationTable[MOUNTAIN_VILLAGE_HUNGRY_GORON]							   = ItemLocation::Base		   (Scene,Flag, "Mountain Village Hungry Goron",					MOUNTAIN_VILLAGE_HUNGRY_GORON,		DON_GEROS_MASK,					{Category::cMountainVillage,},																												SpoilerCollectionCheckGroup::GROUP_MOUNTAIN_VILLAGE);
	locationTable[MOUNTAIN_VILLAGE_WATERFALL_CHEST]							   = ItemLocation::Chest	   (Scene,Flag, "Mountain Village Waterfall Chest",					MOUNTAIN_VILLAGE_WATERFALL_CHEST,	RED_RUPEE,						{Category::cMountainVillage,},																												SpoilerCollectionCheckGroup::GROUP_MOUNTAIN_VILLAGE);
	locationTable[MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO]						   = ItemLocation::Chest	   (Scene,Flag, "Mountain Village Spring Water Grotto",				MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO,RED_RUPEE,						{Category::cMountainVillage, Category::cGrotto},																							SpoilerCollectionCheckGroup::GROUP_MOUNTAIN_VILLAGE);
	
	//N Clock Town
	locationTable[N_CLOCK_TOWN_GREAT_FAIRY_DEKU]							   = ItemLocation::Base		   (Scene,Flag, "N Clock Town Great Fairy (Deku)",					N_CLOCK_TOWN_GREAT_FAIRY_DEKU,		PROGRESSIVE_MAGIC_METER,		{Category::cNClockTown, Category::cFairyFountain},																							SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN);
	//locationTable[N_CLOCK_TOWN_BOMBERS_HIDE_SEEK]							   = ItemLocation::Base		   (Scene,Flag, "N Clock Town Bombers Hide n Seek",					N_CLOCK_TOWN_BOMBERS_HIDE_SEEK,		BOMBERS_NOTEBOOK,				{Category::cNClockTown, },																												SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN);
	locationTable[N_CLOCK_TOWN_KEATON_QUIZ]									   = ItemLocation::Base		   (Scene,Flag, "N Clock Town Keaton Quiz",							N_CLOCK_TOWN_KEATON_QUIZ,			PIECE_OF_HEART,					{Category::cNClockTown, Category::cMinigame},																							SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN);
	locationTable[N_CLOCK_TOWN_DEKU_PLAYGROUND_3DAYS]						   = ItemLocation::Base		   (Scene,Flag, "N Clock Town Deku Playground 3 Days Reward",		N_CLOCK_TOWN_DEKU_PLAYGROUND_3DAYS,	PIECE_OF_HEART,					{Category::cNClockTown, Category::cMinigame},																							SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN);
	locationTable[N_CLOCK_TOWN_TREE]										   = ItemLocation::Collectable (Scene,Flag, "N Clock Town Tree",								N_CLOCK_TOWN_TREE,					PIECE_OF_HEART,					{Category::cNClockTown, },																												SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN);
	locationTable[N_CLOCK_TOWN_OLD_LADY]									   = ItemLocation::Base		   (Scene,Flag, "N Clock Town Old Lady",							N_CLOCK_TOWN_OLD_LADY,				BLAST_MASK,						{Category::cNClockTown, },																												SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN);
	locationTable[N_CLOCK_TOWN_GREAT_FAIRY_HUMAN]							   = ItemLocation::Base		   (Scene,Flag, "N Clock Town Great Fairy (Human)",					N_CLOCK_TOWN_GREAT_FAIRY_HUMAN,		GREAT_FAIRYS_MASK,				{Category::cNClockTown, Category::cFairyFountain},																						SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN);
	locationTable[N_CLOCK_TOWN_MAP_PURCHASE]								   = ItemLocation::Base		   (Scene,Flag, "N Clock Town Map Purchase",						N_CLOCK_TOWN_MAP_PURCHASE,			CLOCK_TOWN_MAP,					{Category::cNClockTown, Category::cVanillaMap},																							SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN);
	//locationTable[N_CLOCK_TOWN_DEKU_PLAYGROUND_ADAY]						   = ItemLocation::Base		   (Scene,Flag, "N Clock Town Deku Playground Any Day Reward",		N_CLOCK_TOWN_DEKU_PLAYGROUND_ADAY,	PURPLE_RUPEE,					{Category::cNClockTown, Category::cMinigame},																							SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN);
	
	//Path to Snowhead
	locationTable[ROAD_TO_SNOWHEAD_PILLAR]									   = ItemLocation::Collectable (Scene,Flag, "Road to Snowhead Pillar",							ROAD_TO_SNOWHEAD_PILLAR,			PIECE_OF_HEART,					{Category::cRoadToSnowhead,},																											SpoilerCollectionCheckGroup::GROUP_ROAD_TO_SNOWHEAD);
	locationTable[ROAD_TO_SNOWHEAD_GROTTO]									   = ItemLocation::Chest 	   (Scene,Flag, "Road to Snowhead Grotto",							ROAD_TO_SNOWHEAD_GROTTO,			RED_RUPEE,						{Category::cRoadToSnowhead,Category::cGrotto},																							SpoilerCollectionCheckGroup::GROUP_ROAD_TO_SNOWHEAD);
	
	//Pinnacle Rock
	locationTable[PINNACLE_ROCK_SEAHORSES]									   = ItemLocation::Base		   (Scene,Flag, "Pinnacle Rock Seahorses",							PINNACLE_ROCK_SEAHORSES,			PIECE_OF_HEART,					{Category::cPinnacleRock, },																											SpoilerCollectionCheckGroup::GROUP_PINNACLE_ROCK);
	locationTable[PINNACLE_ROCK_UPPER_CHEST]								   = ItemLocation::Chest	   (Scene,Flag, "Pinnacle Rock Upper Chest",						PINNACLE_ROCK_UPPER_CHEST,			RED_RUPEE,						{Category::cPinnacleRock, },																											SpoilerCollectionCheckGroup::GROUP_PINNACLE_ROCK);
	locationTable[PINNACLE_ROCK_LOWER_CHEST]								   = ItemLocation::Chest	   (Scene,Flag, "Pinnacle Rock Lower Chest",						PINNACLE_ROCK_LOWER_CHEST,			RED_RUPEE,						{Category::cPinnacleRock, },																											SpoilerCollectionCheckGroup::GROUP_PINNACLE_ROCK);
	
	//Road to Ikana
	locationTable[ROAD_TO_IKANA_INVISIBLE_SOLDIER]							   = ItemLocation::Base	   (Scene,Flag, "Road to Ikana Invisible Soldier",						ROAD_TO_IKANA_INVISIBLE_SOLDIER,		STONE_MASK,				{Category::cRoadToIkana,},																											SpoilerCollectionCheckGroup::GROUP_ROAD_TO_IKANA);
	locationTable[ROAD_TO_IKANA_PILLAR_CHEST]								   = ItemLocation::Chest   (Scene,Flag, "Road to Ikana Pillar Chest",							ROAD_TO_IKANA_PILLAR_CHEST,				RED_RUPEE,				{Category::cRoadToIkana,},																											SpoilerCollectionCheckGroup::GROUP_ROAD_TO_IKANA);
	locationTable[ROAD_TO_IKANA_GROTTO]										   = ItemLocation::Base	   (Scene,Flag, "Road to Ikana Grotto",									ROAD_TO_IKANA_GROTTO,					BOMBCHU_5,				{Category::cRoadToIkana,Category::cGrotto},																											SpoilerCollectionCheckGroup::GROUP_ROAD_TO_IKANA);
	
	//Road to Southern Swamp
	locationTable[ROAD_TO_SS_ARCHERY_1]										   = ItemLocation::Base	   (Scene,Flag, "Road to Southern Swamp Archery 1",						ROAD_TO_SS_ARCHERY_1,					PROGRESSIVE_BOW,		{Category::cRoadToSouthernSwamp,Category::cMinigame},																											SpoilerCollectionCheckGroup::GROUP_ROAD_TO_SS);
	locationTable[ROAD_TO_SS_ARCHERY_2]										   = ItemLocation::Base	   (Scene,Flag, "Road to Southern Swamp Archery 2",						ROAD_TO_SS_ARCHERY_2,					PIECE_OF_HEART,			{Category::cRoadToSouthernSwamp,Category::cMinigame},																											SpoilerCollectionCheckGroup::GROUP_ROAD_TO_SS);
	locationTable[ROAD_TO_SS_TREE]											   = ItemLocation::Collectable(Scene,Flag, "Road to Southern Swamp Tree",						ROAD_TO_SS_TREE,						PIECE_OF_HEART,			{Category::cRoadToSouthernSwamp,},																											SpoilerCollectionCheckGroup::GROUP_ROAD_TO_SS);
	locationTable[ROAD_TO_SS_WOODFALL_MAP_BUY]								   = ItemLocation::Base	   (Scene,Flag, "Road to Southern Swamp Woodfall Map Purchase",			ROAD_TO_SS_WOODFALL_MAP_BUY,			WOODFALL_MAP,			{Category::cRoadToSouthernSwamp,Category::cVanillaMap},																											SpoilerCollectionCheckGroup::GROUP_ROAD_TO_SS);
	locationTable[ROAD_TO_SS_SNOWHEAD_MAP_BUY]								   = ItemLocation::Base	   (Scene,Flag, "Road to Southern Swamp Snowhead Map Purchase",			ROAD_TO_SS_SNOWHEAD_MAP_BUY,			SNOWHEAD_MAP,			{Category::cRoadToSouthernSwamp,Category::cVanillaMap},																											SpoilerCollectionCheckGroup::GROUP_ROAD_TO_SS);
	locationTable[ROAD_TO_SS_GROTTO]										   = ItemLocation::Base	   (Scene,Flag, "Road to Southern Swamp Grotto",						ROAD_TO_SS_GROTTO,						RED_RUPEE,			{Category::cRoadToSouthernSwamp,Category::cGrotto},																											SpoilerCollectionCheckGroup::GROUP_ROAD_TO_SS);
	
	//Romani Ranch
	locationTable[ROMANI_RANCH_ALIEN_DEFENSE]								   = ItemLocation::Base		(Scene,Flag, "Romani Ranch Alien Defense",							ROMANI_RANCH_ALIEN_DEFENSE,				BOTTLE_WITH_MILK,		{Category::cRomaniRanch,},																													SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH);
	locationTable[ROMANI_RANCH_DOG_RACE]									   = ItemLocation::Base		(Scene,Flag, "Romani Ranch Dog Race",								ROMANI_RANCH_DOG_RACE,					PIECE_OF_HEART,			{Category::cRomaniRanch,Category::cMinigame},																													SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH);
	locationTable[ROMANI_RANCH_GROG]										   = ItemLocation::Base		(Scene,Flag, "Romani Ranch Grog",									ROMANI_RANCH_GROG,						BUNNY_HOOD,				{Category::cRomaniRanch,},																													SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH);
	locationTable[ROMANI_RANCH_CREMIA_ESCORT]								   = ItemLocation::Base		(Scene,Flag, "Romani Ranch Cremia Escort",							ROMANI_RANCH_CREMIA_ESCORT,				ROMANIS_MASK,			{Category::cRomaniRanch,},																													SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH);
	locationTable[ROMANI_RANCH_ROMANIS_GAME]								   = ItemLocation::Base		(Scene,Flag, "Romani Ranch Romani's Game",							ROMANI_RANCH_ROMANIS_GAME,				EPONAS_SONG,			{Category::cRomaniRanch,Category::cSong,},																													SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH);
	locationTable[ROMANI_RANCH_DOGGY_RACETRACK_ROOF_CHEST]					   = ItemLocation::Cheset	(Scene,Flag, "Romani Ranch Doggy Racetrack Roof Chest",				ROMANI_RANCH_DOGGY_RACETRACK_ROOF_CHEST,PURPLE_RUPEE,			{Category::cRomaniRanch,},																													SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH);
	
	//S Clock Town
	locationTable[S_CLOCK_TOWN_SCRUB_TRADE]									   = ItemLocation::Base		(Scene,Flag, "S Clock Town Scrub Trade",							S_CLOCK_TOWN_SCRUB_TRADE,				LAND_TITLE,				{Category::cSClockTown,Category::cDekuScrub},																								SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN);
	locationTable[S_CLOCK_TOWN_POSTBOX]										   = ItemLocation::Base		(Scene,Flag, "S Clock Town Postbox",								S_CLOCK_TOWN_POSTBOX,					PIECE_OF_HEART,			{Category::cSClockTown,},																								SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN);
	locationTable[S_CLOCK_TOWN_CLOCK_TOWER_ENTRANCE]						   = ItemLocation::Collectable(Scene,Flag, "S Clock Town Clock Tower Entrance",					S_CLOCK_TOWN_CLOCK_TOWER_ENTRANCE,		PIECE_OF_HEART,			{Category::cSClockTown,},																								SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN);
	locationTable[S_CLOCK_TOWN_STRAW_ROOF_CHEST]							   = ItemLocation::Chest	(Scene,Flag, "S Clock Town Straw Roof Chest",						S_CLOCK_TOWN_STRAW_ROOF_CHEST,			RED_RUPEE,				{Category::cSClockTown,},																								SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN);
	locationTable[S_CLOCK_TOWN_FINAL_DAY_CHEST]								   = ItemLocation::Chest	(Scene,Flag, "S Clock Town Final Day Chest",						S_CLOCK_TOWN_FINAL_DAY_CHEST,			PURPLE_RUPEE,			{Category::cSClockTown,},																								SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN);
	locationTable[S_CLOCK_TOWN_BANK_REWARD_1]								   = ItemLocation:Base		(Scene,Flag, "S Clock Town Bank Reward 1",							S_CLOCK_TOWN_BANK_REWARD_1,				PROGRESSIVE_WALLET,		{Category::cSClockTown,},																													SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN);
	locationTable[S_CLOCK_TOWN_BANK_REWARD_2]								   = ItemLocation:Base		(Scene,Flag, "S Clock Town Bank Reward 2",							S_CLOCK_TOWN_BANK_REWARD_2,				BLUE_RUPEE,				{Category::cSClockTown,},																													SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN);
	locationTable[S_CLOCK_TOWN_BANK_REWARD_3]								   = ItemLocation:Base		(Scene,Flag, "S Clock Town Bank Reward 3",							S_CLOCK_TOWN_BANK_REWARD_3,				PIECE_OF_HEART,			{Category::cSClockTown,},																													SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN);
	
	//Snowhead
	locationTable[SNOWHEAD_GREAT_FAIRY]									   	   = ItemLocation::Base	(Scene,Flag, "Snowhead Great Fairy",									SNOWHEAD_GREAT_FAIRY,					PROGRESSIVE_MAGIC_METER,{Category::cSnowhead, Category::cFairyFountain},																		SpoilerCollectionCheckGroup::GROUP_SNOWHEAD);
	
	//Southern Swamp
	locationTable[SOUTHERN_SWAMP_KOUME]										   = ItemLocation::Base (Scene,Flag, "Southern Swamp Koume",										SOUTHERN_SWAMP_KOUME,				PICTOGRAPH_BOX,			{Category::cSouthernSwamp,},																												SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
	locationTable[SOUTHERN_SWAMP_KOTAKE]									   = ItemLocation::Base (Scene,Flag, "Southern Swamp Kotake",										SOUTHERN_SWAMP_KOTAKE,				BOTTLE_WITH_RED_POTION,	{Category::cSouthernSwamp,},																												SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
	locationTable[SOUTHERN_SWAMP_SCRUB_TRADE]								   = ItemLocation::Base (Scene,Flag, "Southern Swamp Scrub Trade",									SOUTHERN_SWAMP_SCRUB_TRADE,			SWAMP_TITLE,			{Category::cSouthernSwamp,},																												SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
	locationTable[SOUTHERN_SWAMP_PICTOGRAPH_WINNER]							   = ItemLocation::Base (Scene,Flag, "Southern Swamp Pictograph Contest Winner",					SOUTHERN_SWAMP_PICTOGRAPH_WINNER,	PIECE_OF_HEART,			{Category::cSouthernSwamp,},																												SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
	locationTable[SOUTHERN_SWAMP_BOAT_ARCHERY]								   = ItemLocation::Base (Scene,Flag, "Southern Swamp Boat Archery",									SOUTHERN_SWAMP_BOAT_ARCHERY,		PIECE_OF_HEART,			{Category::cSouthernSwamp, Category::cMinigame,},																							SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
	locationTable[SOUTHERN_SWAMP_TOURIST_ROOF]								   = ItemLocation::Collectable (Scene,Flag, "Southern Swamp Tourist Center Roof",					SOUTHERN_SWAMP_TOURIST_ROOF,		PIECE_OF_HEART,			{Category::cSouthernSwamp,},																												SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
	locationTable[SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD]						   = ItemLocation::Base (Scene,Flag, "Southern Swamp Spider House Reward",							SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD,	MASK_OF_TRUTH,			{Category::cSouthernSwamp,},																												SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
	locationTable[SOUTHERN_SWAMP_MUSIC_STATUE]								   = ItemLocation::Base (Scene,Flag, "Southern Swamp Music Statue",									SOUTHERN_SWAMP_MUSIC_STATUE,		SONG_OF_SOARING,		{Category::cSouthernSwamp, Category::cSong,},																								SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
	locationTable[SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO]					   = ItemLocation::Chest (Scene,Flag, "Southern Swamp Near Spider House Grotto",					SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO,RED_RUPEE,			{Category::cSouthernSwamp,Category::cGrotto,},																								SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
	locationTable[SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO]						   = ItemLocation::Chest (Scene,Flag, "Southern Swamp Mystery Woods Grotto",						SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO,PURPLE_RUPEE,			{Category::cSouthernSwamp, Category::cGrotto},																								SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
	locationTable[SOUTHERN_SWAMP_KOTAKE_MUSHROOM_SALE]						   = ItemLocation::Base (Scene,Flag, "Southern Swamp Kotake Mushroom Sale",							SOUTHERN_SWAMP_KOTAKE_MUSHROOM_SALE,RED_RUPEE,				{Category::cSouthernSwamp,},																												SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
	//locationTable[SOUTHERN_SWAMP_PICTOGRAPH_STANDARD]					 	   = ItemLocation::Base (Scene,Flag, "Southern Swamp Pictograph Standard",							SOUTHERN_SWAMP_PICTOGRAPH_STANDARD,	BLUE_RUPEE,				{Category::cSouthernSwamp, Category::cMinigame,},																							SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
	//locationTable[SOUTHERN_SWAMP_PICTOGRAPH_GOOD]							   = ItemLocation::Base (Scene,Flag, "Southern Swamp Pictograph Good",								SOUTHERN_SWAMP_PICTOGRAPH_GOOD,		RED_RUPEE,				{Category::cSouthernSwamp,Category::cMinigame,},																							SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
	locationTable[SOUTHERN_SWAMP_SCRUB_PURCHASE]							   = ItemLocation::Base (Scene,Flag, "Southern Swamp Scrub Purchase",								SOUTHERN_SWAMP_SCRUB_PURCHASE,		MAGIC_BEAN,				{Category::cSouthernSwamp, Category::cDekuScrub},																							SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);

	//Stock Pot Inn
	locationTable[STOCKPOTINN_RESERVATION]									   = ItemLocation::Base		(Scene,Flag, "Stock Pot Inn Reservation",							STOCKPOTINN_RESERVATION,				ROOM_KEY,				{Category::cStockPotInn,},																													SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN);
	locationTable[STOCKPOTINN_MIDNIGHT_MEETING]								   = ItemLocation::Base		(Scene,Flag, "Stock Pot Inn Midnight Meeting",						STOCKPOTINN_MIDNIGHT_MEETING,			LETTER_KAFEI,			{Category::cStockPotInn,},																													SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN);
	locationTable[STOCKPOTINN_TOILET_HAND]									   = ItemLocation::Base		(Scene,Flag, "Stock Pot Inn Toilet Hand",							STOCKPOTINN_TOILET_HAND,				PIECE_OF_HEART,			{Category::cStockPotInn,},																													SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN);
	locationTable[STOCKPOTINN_GRANDMA_SHORT_STORY]							   = ItemLocation::Base		(Scene,Flag, "Stock Pot Inn Grandma Short Story",					STOCKPOTINN_GRANDMA_SHORT_STORY,		PIECE_OF_HEART,			{Category::cStockPotInn,},																													SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN);
	locationTable[STOCKPOTINN_GRANDMA_LONG_STORY]							   = ItemLocation::Base		(Scene,Flag, "Stock Pot Inn Grandma Long Story",					STOCKPOTINN_GRANDMA_LONG_STORY,			PIECE_OF_HEART,			{Category::cStockPotInn,},																													SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN);
	locationTable[STOCKPOTINN_ANJU_AND_KAFEI]								   = ItemLocation::Base		(Scene,Flag, "Stock Pot Inn Anju And Kafei",						STOCKPOTINN_ANJU_AND_KAFEI,				COUPLES_MASK,			{Category::cStockPotInn,},																													SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN);
	locationTable[STOCKPOTINN_STAFF_ROOM_CHEST]				   			 	   = ItemLocation::Chest	(Scene,Flag, "Stock Pot Inn Staff Room Chest",						STOCKPOTINN_STAFF_ROOM_CHEST,			SILVER_RUPEE,			{Category::cStockPotInn,},																													SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN);
	locationTable[STOCKPOTINN_GUEST_ROOM_CHEST]								   = ItemLocation::Chest	(Scene,Flag, "Stock Pot Inn Guest Room Chest",						STOCKPOTINN_GUEST_ROOM_CHEST,			SILVER_RUPEE,			{Category::cStockPotInn,},																													SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN);
	
	//Stone Tower
	locationTable[STONE_TOWER_INVERTED_RIGHT_CHEST]							   = ItemLocation::Chest	(Scene,Flag, "Inverted Stone Tower Right Chest",					STONE_TOWER_INVERTED_RIGHT_CHEST,		SILVER_RUPEE,			{Category::cStoneTower,},																													SpoilerCollectionCheckGroup::GROUP_STONE_TOWER);
	locationTable[STONE_TOWER_INVERTED_CENTER_CHEST]						   = ItemLocation::Chest	(Scene,Flag, "Inverted Stone Tower Center Chest",					STONE_TOWER_INVERTED_CENTER_CHEST,		BOMBCHU_10,				{Category::cStoneTower,},																													SpoilerCollectionCheckGroup::GROUP_STONE_TOWER);
	locationTable[STONE_TOWER_INVERTED_LEFT_CHEST]							   = ItemLocation::Chest	(Scene,Flag, "Inverted Stone Tower Left Chest",						STONE_TOWER_INVERTED_LEFT_CHEST,		MAGIC_BEAN,				{Category::cStoneTower,},																													SpoilerCollectionCheckGroup::GROUP_STONE_TOWER);
	
	//Termina Field
	locationTable[TERMINA_FIELD_MOONS_TEAR]									   = ItemLocation::Collectable(Scene,Flag, "Termina Field Moon's Tear",							TERMINA_FIELD_MOONS_TEAR,			MOONS_TEAR,					{Category::cTerminaField,},																													SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
	locationTable[TERMINA_FIELD_GOSSIP_STONES]								   = ItemLocation::Base		(Scene,Flag, "Termina Field Gossip Stones",							TERMINA_FIELD_GOSSIP_STONES,		PIECE_OF_HEART,				{Category::cTerminaField,Category::cGrotto},																								SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
	locationTable[TERMINA_FIELD_BUSINESS_SCRUB]								   = ItemLocation::Base		(Scene,Flag, "Termina Field Business Scrub",						TERMINA_FIELD_BUSINESS_SCRUB,		PIECE_OF_HEART,				{Category::cTerminaField,Category::cGrotto,Category::cDekuScrub},																			SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
	locationTable[TERMINA_FIELD_PEAHAT_GROTTO]								   = ItemLocation::Chest	(Scene,Flag, "Termina Field Peahat Grotto",							TERMINA_FIELD_PEAHAT_GROTTO,		PIECE_OF_HEART,				{Category::cTerminaField,Category::cGrotto,},																								SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
	locationTable[TERMINA_FIELD_DODONGO_GROTTO]								   = ItemLocation::Chest 	(Scene,Flag, "Termina Field Dodongo Grotto",						TERMINA_FIELD_DODONGO_GROTTO,		PIECE_OF_HEART,				{Category::cTerminaField,Category::cGrotto,},																								SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
	locationTable[TERMINA_FIELD_BIO_BABA_GROTTO]							   = ItemLocation::Collectable(Scene,Flag, "Termina Field Bio Baba Grotto",						TERMINA_FIELD_BIO_BABA_GROTTO,		PIECE_OF_HEART,				{Category::cTerminaField,Category::cGrotto,},																								SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
	locationTable[TERMINA_FIELD_KAMARO]										   = ItemLocation::Base		(Scene,Flag, "Termina Field Kamaro",								TERMINA_FIELD_KAMARO,				KAMAROS_MASK,				{Category::cTerminaField,},																													SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
	locationTable[TERMINA_FIELD_PILLAR_GROTTO]								   = ItemLocation::Chest	(Scene,Flag, "Termina Field Pillar Grotto",							TERMINA_FIELD_PILLAR_GROTTO,		BOMBCHU_5,					{Category::cTerminaField,Category::cGrotto,},																								SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
	locationTable[TERMINA_FIELD_GRASS_GROTTO]								   = ItemLocation::Chest	(Scene,Flag, "Termina Field Grass Grotto",							TERMINA_FIELD_GRASS_GROTTO,			RED_RUPEE,					{Category::cTerminaField,Category::cGrotto,},																								SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
	locationTable[TERMINA_FIELD_UNDERWATER_CHEST]							   = ItemLocation::Chest	(Scene,Flag, "Termina Field Underwater Chest",						TERMINA_FIELD_UNDERWATER_CHEST,		RED_RUPEE,					{Category::cTerminaField,},																													SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
	locationTable[TERMINA_FIELD_GRASS_CHEST]								   = ItemLocation::Chest	(Scene,Flag, "Termina Field Grass Chest",							TERMINA_FIELD_GRASS_CHEST,			RED_RUPEE,					{Category::cTerminaField,},																													SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
	locationTable[TERMINA_FIELD_STUMP_CHEST]								   = ItemLocation::Chest	(Scene,Flag, "Termina Field Stump Chest",							TERMINA_FIELD_STUMP_CHEST,			RED_RUPEE,					{Category::cTerminaField,},																													SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
	
	//Twin Islands
	locationTable[TWIN_ISLANDS_HOT_SPRING_WATER_GROTTO]						   = ItemLocation::Chest	 (Scene,Flag, "Twin Islands Hot Spring Water Grotto",				TWIN_ISLANDS_HOT_SPRING_WATER_GROTTO,	RED_RUPEE,				{Category::cTwinIslands, Category::cGrotto},																								SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS);
	locationTable[TWIN_ISLANDS_GORON_RACE]									   = ItemLocation::Base		 (Scene,Flag, "Twin Islands Goron Race",							TWIN_ISLANDS_GORON_RACE,				GOLD_DUST,				{Category::cTwinIslands, },																													SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS);
	locationTable[TWIN_ISLANDS_GORON_RACETRACK_GROTTO]						   = ItemLocation::Chest	 (Scene,Flag, "Twin Islands Goron Racetrack Grotto",				TWIN_ISLANDS_GORON_RACETRACK_GROTTO,	BOMBCHU_5,				{Category::cTwinIslands, Category::cGrotto},																								SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS);
	locationTable[TWIN_ISLANDS_UNDERWATER_RAMP_CHEST]						   = ItemLocation::Chest	 (Scene,Flag, "Twin Islands Underwater Ramp",						TWIN_ISLANDS_UNDERWATER_RAMP_CHEST,		PIECE_OF_HEART,			{Category::cTwinIslands,},																													SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS);
	locationTable[TWIN_ISLANDS_CAVE_CHEST]									   = ItemLocation::Chest	 (Scene,Flag, "Twin Islands Cave",									TWIN_ISLANDS_CAVE_CHEST,				RED_RUPEE,				{Category::cTwinIslands,},																													SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS);
	
	//W Clock Town
	locationTable[W_CLOCK_TOWN_BOMB_BAG_BUY]								   = ItemLocation:Base		(Scene,Flag, "W Clock Town Bomb Bag Purchase",						W_CLOCK_TOWN_BOMB_BAG_BUY,			PROGRESSIVE_BOMB_BAG,		{Category::cWClockTown,},																													SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
	locationTable[W_CLOCK_TOWN_BIG_BOMB_BAG_BUY]							   = ItemLocation:Base		(Scene,Flag, "W Clock Town Big Bomb Bag Purchase",					W_CLOCK_TOWN_BIG_BOMB_BAG_BUY,		PROGRESSIVE_BOMB_BAG,		{Category::cWClockTown,},																													SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
	locationTable[W_CLOCK_TOWN_POSTMANS_GAME]								   = ItemLocation:Base		(Scene,Flag, "W Clock Town Postman's Game",							W_CLOCK_TOWN_POSTMANS_GAME,			PIECE_OF_HEART,				{Category::cWClockTown,},																													SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
	locationTable[W_CLOCK_TOWN_ROSA_SISTERS]								   = ItemLocation:Base		(Scene,Flag, "W Clock Town Rosa Sisters",							W_CLOCK_TOWN_ROSA_SISTERS,			PIECE_OF_HEART,				{Category::cWClockTown,},																													SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
	locationTable[W_CLOCK_TOWN_SWORDSMANS_SCHOOL]							   = ItemLocation:Base		(Scene,Flag, "W Clock Town Swordsman's School",						W_CLOCK_TOWN_SWORDSMANS_SCHOOL,		PIECE_OF_HEART,				{Category::cWClockTown,},																													SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
	locationTable[W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY]							   = ItemLocation:Base		(Scene,Flag, "W Clock Town All-Night Mask Purchase",				W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY,	ALL_NIGHT_MASK,				{Category::cWClockTown,},																													SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
	locationTable[W_CLOCK_TOWN_LOTTERY]										   = ItemLocation:Base		(Scene,Flag, "W Clock Town Lottery",								W_CLOCK_TOWN_LOTTERY,				PURPLE_RUPEE,				{Category::cWClockTown,},																													SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
	
	//Woodfall
	locationTable[WOODFALL_BRIDGE_CHEST]									   = ItemLocation::Chest	(Scene,Flag, "Woodfall Bridge Chest",								WOODFALL_BRIDGE_CHEST,				PIECE_OF_HEART,				{Category::cWoodfall,},																														SpoilerCollectionCheckGroup::GROUP_WOODFALL);
	locationTable[WOODFALL_BEHIND_OWL_CHEST]								   = ItemLocation::Chest	(Scene,Flag, "Woodfall Behind Owl Chest",							WOODFALL_BEHIND_OWL_CHEST,			BLUE_RUPEE,					{Category::cWoodfall,},																														SpoilerCollectionCheckGroup::GROUP_WOODFALL);
	locationTable[WOODFALL_ENTRANCE_TO_WOODFALL_CHEST]						   = ItemLocation::Chest	(Scene,Flag, "Woodfall Entrance to Woodfall Chest",					WOODFALL_ENTRANCE_TO_WOODFALL_CHEST,RED_RUPEE,					{Category::cWoodfall,},																														SpoilerCollectionCheckGroup::GROUP_WOODFALL);
	locationTable[WOODFALL_GREAT_FAIRY]										   = ItemLocation::Base		(Scene,Flag, "Woodfall Great Fairy",								WOODFALL_GREAT_FAIRY,				SPIN_ATTACK,				{Category::cWoodfall, Category::cFairyFountain},																							SpoilerCollectionCheckGroup::GROUP_WOODFALL);
	
	//Zora Cape
	locationTable[ZORA_CAPE_GREAT_FAIRY]									   = ItemLocation::Base		(Scene,Flag, "Zora Cape Great Fairy",									ZORA_CAPE_GREAT_FAIRY,				DOUBLE_DEFENSE,				{Category::cZoraCape,Category::cFairyFountain},																								SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE);
	locationTable[ZORA_CAPE_BEAVER_RACE_1]									   = ItemLocation::Base		(Scene,Flag, "Zora Cape Beaver Race 1",									ZORA_CAPE_BEAVER_RACE_1,			EMPTY_BOTTLE,				{Category::cZoraCape,Category::cMinigame},																									SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE);
	locationTable[ZORA_CAPE_BEAVER_RACE_2]									   = ItemLocation::Base		(Scene,Flag, "Zora Cape Beaver Race 2",									ZORA_CAPE_BEAVER_RACE_2,			PIECE_OF_HEART,				{Category::cZoraCape,Category::cMinigame},																									SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE);
	locationTable[ZORA_CAPE_LIKE_LIKE]										   = ItemLocation::Base		(Scene,Flag, "Zora Cape Like Like",										ZORA_CAPE_LIKE_LIKE,				PIECE_OF_HEART,				{Category::cZoraCape,},																														SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE);
	locationTable[ZORA_CAPE_LEDGE_NO_TREE]									   = ItemLocation::Chest	(Scene,Flag, "Zora Cape Ledge Without Tree",							ZORA_CAPE_LEDGE_NO_TREE,			RED_RUPEE,					{Category::cZoraCape,},																														SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE);
	locationTable[ZORA_CAPE_LEDGE_WITH_TREE]								   = ItemLocation::Chest	(Scene,Flag, "Zora Cape Ledge With Tree",								ZORA_CAPE_LEDGE_WITH_TREE,			RED_RUPEE,					{Category::cZoraCape,},																														SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE);
	locationTable[ZORA_CAPE_GROTTO]											   = ItemLocation::Chest	(Scene,Flag, "Zora Cape Grotto",								 		ZORA_CAPE_GROTTO,					BOMBCHU_5,					{Category::cZoraCape,Category::cGrotto},																									SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE);
	locationTable[ZORA_CAPE_UNDERWATER_CHEST]								   = ItemLocation::Chest	(Scene,Flag, "Zora Cape Underwater Chest",								ZORA_CAPE_UNDERWATER_CHEST,			PURPLE_RUPEE,				{Category::cZoraCape,},																														SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE);
	
	//Zora Hall
	locationTable[ZORA_HALL_SCRUB_TRADE]									   = ItemLocation::Base		(Scene,Flag, "Zora Hall Deku Scrub Trade",								ZORA_HALL_SCRUB_TRADE,				OCEAN_TITLE,				{Category::cZoraHall, Category::cDekuScrub},																								SpoilerCollectionCheckGroup::GROUP_ZORA_HALL);
	locationTable[ZORA_HALL_EVAN]											   = ItemLocation::Base		(Scene,Flag, "Zora Hall Deku Evan",										ZORA_HALL_EVAN,						PIECE_OF_HEART,				{Category::cZoraHall, },																													SpoilerCollectionCheckGroup::GROUP_ZORA_HALL);
	locationTable[ZORA_HALL_LULU_ROOM_LEDGE]								   = ItemLocation::Collectable	(Scene,Flag, "Zora Hall Lulu's Room Ledge",							ZORA_HALL_LULU_ROOM_LEDGE,			PIECE_OF_HEART,				{Category::cZoraHall, },																													SpoilerCollectionCheckGroup::GROUP_ZORA_HALL);
	locationTable[ZORA_HALL_SCRUB_BUY]										   = ItemLocation::Base		(Scene,Flag, "Zora Hall Deku Scrub Purchase",							ZORA_HALL_SCRUB_BUY,				GREEN_POTION_REFILL,		{Category::cZoraHall, Category::cDekuScrub},																								SpoilerCollectionCheckGroup::GROUP_ZORA_HALL);
	locationTable[ZORA_HALL_STAGE_LIGHTS]									   = ItemLocation::Base		(Scene,Flag, "Zora Hall Stage Lights",									ZORA_HALL_STAGE_LIGHTS,				BLUE_RUPEE,					{Category::cZoraHall,},																														SpoilerCollectionCheckGroup::GROUP_ZORA_HALL);
	//locationTable[ZORA_HALL_BAD_PHOTO_LULU]									   = ItemLocation::Base		(Scene,Flag, "Zora Hall Bad Photograph of Lulu",								ZORA_HALL_SCRUB_TRADE,				OCEAN_TITLE,				{Category::cZoraHall, Category::cDekuScrub},																								SpoilerCollectionCheckGroup::GROUP_ZORA_HALL);
	//locationTable[ZORA_HALL_GOOD_PHOTO_LULU]									   = ItemLocation::Base		(Scene,Flag, "Zora Hall Good Photograph of Lulu",								ZORA_HALL_SCRUB_TRADE,				OCEAN_TITLE,				{Category::cZoraHall, Category::cDekuScrub},																								SpoilerCollectionCheckGroup::GROUP_ZORA_HALL);
	
	
	/*-------------------
       --- DUNGEONS --
      -------------------*/
	

	//Woodfall Temple
	locationTable[WOODFALL_TEMPLE_HEROS_BOW_CHEST]							   = ItemLocation::Chest	(Scene,Flag, "Woodfall Temple Hero's Bow Chest",					WOODFALL_TEMPLE_HEROS_BOW_CHEST,	PROGRESSIVE_BOW,			{Category::cWoodfall, Category::cWoodfallTemple,},																							SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WOODFALL_TEMPLE_MAP_CHEST]								   = ItemLocation::Chest	(Scene,Flag, "Woodfall Temple Map Chest",							WOODFALL_TEMPLE_MAP_CHEST,			WOODFALL_MAP,				{Category::cWoodfall, Category::cWoodfallTemple,Category::cVanillaMap},																		SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WOODFALL_TEMPLE_COMPASS_CHEST]							   = ItemLocation::Chest	(Scene,Flag, "Woodfall Temple Compass Chest",						WOODFALL_TEMPLE_COMPASS_CHEST,		WOODFALL_COMPASS,			{Category::cWoodfall, Category::cWoodfallTemple,Category::cVanillaCompass},																	SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WOODFALL_TEMPLE_BOSS_KEY_CHEST]							   = ItemLocation::Chest	(Scene,Flag, "Woodfall Temple Boss Key Chest",						WOODFALL_TEMPLE_BOSS_KEY_CHEST,		WOODFALL_BOSS_KEY,			{Category::cWoodfall, Category::cWoodfallTemple,Category::cVanillaBossKey},																	SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WOODFALL_TEMPLE_SMALL_KEY_CHEST]							   = ItemLocation::Chest	(Scene,Flag, "Woodfall Temple Small Key Chest",						WOODFALL_TEMPLE_SMALL_KEY_CHEST,	WOODFALL_SMALL_KEY,			{Category::cWoodfall, Category::cWoodfallTemple,Category::cVanillaSmallKey},																SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);

	//Snowhead Temple
	locationTable[SNOWHEAD_TEMPLE_FIRE_ARROW_CHEST]						   	   = ItemLocation::Chest	(Scene,Flag, "Snowhead Temple Fire Arrow Chest",						SNOWHEAD_TEMPLE_FIRE_ARROW_CHEST,		FIRE_ARROWS,			{Category::cSnowhead, Category::cSnowheadTemple},																		SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SNOWHEAD_TEMPLE_MAP_CHEST]							   	   = ItemLocation::Chest	(Scene,Flag, "Snowhead Temple Map Chest",								SNOWHEAD_TEMPLE_MAP_CHEST,				SNOWHEAD_TEMPLE_MAP,	{Category::cSnowhead, Category::cSnowheadTemple Category::cVanillaMap},													SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SNOWHEAD_TEMPLE_COMPASS_CHEST]						   	   = ItemLocation::Chest	(Scene,Flag, "Snowhead Temple Compass Chest",							SNOWHEAD_TEMPLE_COMPASS_CHEST,			SNOWHEAD_TEMPLE_COMPASS,{Category::cSnowhead, Category::cSnowheadTemple, Category::cVanillaCompass},											SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SNOWHEAD_TEMPLE_BOSS_KEY_CHEST]						   	   = ItemLocation::Chest	(Scene,Flag, "Snowhead Temple Boss Key Chest",							SNOWHEAD_TEMPLE_BOSS_KEY_CHEST,			SNOWHEAD_TEMPLE_BOSS_KEY,{Category::cSnowhead, Category::cSnowheadTemple, Category::cVanillaBossKey},											SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SNOWHEAD_TEMPLE_BLOCK_ROOM_CHEST]						   	   = ItemLocation::Chest	(Scene,Flag, "Snowhead Temple Block Room Chest",						SNOWHEAD_TEMPLE_BLOCK_ROOM_CHEST,		SNOWHEAD_TEMPLE_SMALL_KEY,{Category::cSnowhead, Category::cSnowheadTemple, Category::cVanillaSmallKey},											SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SNOWHEAD_TEMPLE_ICICLE_ROOM_CHEST]					   	   = ItemLocation::Chest	(Scene,Flag, "Snowhead Temple Icicle Room Chest",						SNOWHEAD_TEMPLE_ICICLE_ROOM_CHEST,		SNOWHEAD_TEMPLE_SMALL_KEY,{Category::cSnowhead, Category::cSnowheadTemple, Category::cVanillaSmallKey},											SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SNOWHEAD_TEMPLE_BRIDGE_ROOM_CHEST]					   	   = ItemLocation::Chest	(Scene,Flag, "Snowhead Temple Bridge Room Chest",						SNOWHEAD_TEMPLE_BRIDGE_ROOM_CHEST,		SNOWHEAD_TEMPLE_SMALL_KEY,{Category::cSnowhead, Category::cSnowheadTemple, Category::cVanillaSmallKey},											SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	
	//Great Bay Temple
	locationTable[GBT_ICE_ARROW_CHEST]										   = ItemLocation::Chest	(Scene,Flag, "Great Bay Temple Ice Arrow Chest",					GBT_ICE_ARROW_CHEST,				ICE_ARROWS,					{Category::cGreatBayTemple,},																												SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_MAP_CHEST]											   = ItemLocation::Chest	(Scene,Flag, "Great Bay Temple Map Chest",							GBT_MAP_CHEST,						GBT_MAP,					{Category::cGreatBayTemple, Category::cVanillaMap,},																						SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_COMPASS_CHEST]										   = ItemLocation::Chest	(Scene,Flag, "Great Bay Temple Compass Chest",						GBT_COMPASS_CHEST,					GBT_COMPASS,				{Category::cGreatBayTemple, Category::cVanillaCompass,},																					SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_BOSS_KEY_CHEST]										   = ItemLocation::Chest	(Scene,Flag, "Great Bay Temple Boss Key Chest",						GBT_BOSS_KEY_CHEST,					GBT_BOSS_KEY,				{Category::cGreatBayTemple, Category::cVanillaBossKey,},																					SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SMALL_KEY_CHEST]										   = ItemLocation::Chest	(Scene,Flag, "Great Bay Temple Small Key Chest",					GBT_SMALL_KEY_CHEST,				GBT_SMALL_KEY,				{Category::cGreatBayTemple, Category::cVanillaSmallKey,},																					SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	
	//Stone Tower Temple
	locationTable[STONE_TOWER_TEMPLE_MAP_CHEST]								   = ItemLocation::Chest	(Scene,Flag, "Stone Tower Temple Map Chest",						STONE_TOWER_TEMPLE_MAP_CHEST,			STONE_TOWER_TEMPLE_MAP,	{Category::cStoneTowerTemple, Category::cVanillaMap,},																						SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[STONE_TOWER_TEMPLE_COMPASSS_CHEST]						   = ItemLocation::Chest	(Scene,Flag, "Stone Tower Temple Compass Chest",					STONE_TOWER_TEMPLE_COMPASSS_CHEST,		STONE_TOWER_TEMPLE_COMPASS,{Category::cStoneTowerTemple, Category::cVanillaCompass,},																				SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[STONE_TOWER_TEMPLE_BOSS_KEY_CHEST]						   = ItemLocation::Chest	(Scene,Flag, "Stone Tower Temple Boss Key Chest",					STONE_TOWER_TEMPLE_BOSS_KEY_CHEST,		STONE_TOWER_TEMPLE_BOSS_KEY,{Category::cStoneTowerTemple, Category::cVanillaBossKey,},																				SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[STONE_TOWER_TEMPLE_ARMOS_ROOM_CHEST]						   = ItemLocation::Chest	(Scene,Flag, "Stone Tower Temple Armos Room Chest",					STONE_TOWER_TEMPLE_ARMOS_ROOM_CHEST,	STONE_TOWER_TEMPLE_SMALL_KEY,{Category::cStoneTowerTemple, Category::cVanillaSmallKey,},																			SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[STONE_TOWER_TEMPLE_EYEGORE_ROOM_CHEST]					   = ItemLocation::Chest	(Scene,Flag, "Stone Tower Temple Eyegore Room Chest",				STONE_TOWER_TEMPLE_EYEGORE_ROOM_CHEST,	STONE_TOWER_TEMPLE_SMALL_KEY,{Category::cStoneTowerTemple, Category::cVanillaSmallKey,},																			SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[STONE_TOWER_TEMPLE_UPDRAFT_ROOM_CHEST]					   = ItemLocation::Chest	(Scene,Flag, "Stone Tower Temple Updraft Room Chest",				STONE_TOWER_TEMPLE_UPDRAFT_ROOM_CHEST,	STONE_TOWER_TEMPLE_SMALL_KEY,{Category::cStoneTowerTemple, Category::cVanillaSmallKey,},																			SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM_CHEST]				   = ItemLocation::Chest	(Scene,Flag, "Stone Tower Temple Death Armos Room Chest",			STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM_CHEST,STONE_TOWER_TEMPLE_SMALL_KEY,{Category::cStoneTowerTemple, Category::cVanillaSmallKey,},																			SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[STONE_TOWER_TEMPLE_LIGHT_ARROW_CHEST]						   = ItemLocation::Chest	(Scene,Flag, "Stone Tower Temple Light Arrow Chest",				STONE_TOWER_TEMPLE_LIGHT_ARROW_CHEST,	LIGHT_ARROWS,				{Category::cStoneTowerTemple,},																											SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[STONE_TOWER_TEMPLE_GIANTS_MASK_CHEST]						   = ItemLocation::Chest	(Scene,Flag, "Stone Tower Temple Giant's Mask Chest",				STONE_TOWER_TEMPLE_GIANTS_MASK_CHEST,	GIANTS_MASK,				{Category::cStoneTowerTemple,},																											SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	
	//Pirate Fortress 
	locationTable[PIRATE_FORTRESS_INTERIOR_HOOKSHOT_CHEST]					   = ItemLocation::Chest	   (Scene,Flag, "Pirate's Fortress Interior Hookshot Chest",		PIRATE_FORTRESS_INTERIOR_HOOKSHOT_CHEST,	HOOKSHOT,				{Category::cPiratesFortress,},																											SpoilerCollectionCheckGroup::GROUP_PIRATES_FORTRESS);
	locationTable[PIRATE_FORTRESS_INTERIOR_LOWER_CHEST]					  	   = ItemLocation::Chest	   (Scene,Flag, "Pirate's Fortress Interior Lower Chest",			PIRATE_FORTRESS_INTERIOR_LOWER_CHEST,		RED_RUPEE,				{Category::cPiratesFortress,},																											SpoilerCollectionCheckGroup::GROUP_PIRATES_FORTRESS);
	locationTable[PIRATE_FORTRESS_INTERIOR_UPPER_CHEST]						   = ItemLocation::Chest	   (Scene,Flag, "Pirate's Fortress Interior Upper Chest",			PIRATE_FORTRESS_INTERIOR_UPPER_CHEST,		RED_RUPEE,				{Category::cPiratesFortress,},																											SpoilerCollectionCheckGroup::GROUP_PIRATES_FORTRESS);
	locationTable[PIRATE_FORTRESS_INTERIOR_TANK_CHEST]						   = ItemLocation::Chest	   (Scene,Flag, "Pirate's Fortress Interior Tank Chest",			PIRATE_FORTRESS_INTERIOR_TANK_CHEST,		RED_RUPEE,				{Category::cPiratesFortress,},																											SpoilerCollectionCheckGroup::GROUP_PIRATES_FORTRESS);
	locationTable[PIRATE_FORTRESS_INTERIOR_GUARD_ROOM_CHEST]				   = ItemLocation::Chest	   (Scene,Flag, "Pirate's Fortress Interior Guard Room Chest",		PIRATE_FORTRESS_INTERIOR_GUARD_ROOM_CHEST,	SILVER_RUPEE,			{Category::cPiratesFortress,},																											SpoilerCollectionCheckGroup::GROUP_PIRATES_FORTRESS);
	locationTable[PIRATE_FORTRESS_SEWER_CAGE_ROOM_SHALLOW_CHEST]			   = ItemLocation::Chest	   (Scene,Flag, "Pirate's Fortress Sewer Cage Room Shallow Chest",	PIRATE_FORTRESS_SEWER_CAGE_ROOM_SHALLOW_CHEST,	RED_RUPEE,			{Category::cPiratesFortress,},																											SpoilerCollectionCheckGroup::GROUP_PIRATES_FORTRESS);
	locationTable[PIRATE_FORTRESS_SEWER_CAGE_ROOM_DEEP_CHEST]				   = ItemLocation::Chest	   (Scene,Flag, "Pirate's Fortress Sewer Cage Room Deep Chest",		PIRATE_FORTRESS_SEWER_CAGE_ROOM_DEEP_CHEST,	BLUE_RUPEE,				{Category::cPiratesFortress,},																											SpoilerCollectionCheckGroup::GROUP_PIRATES_FORTRESS);
	locationTable[PIRATE_FORTRESS_MAZE_CHEST]								   = ItemLocation::Chest	   (Scene,Flag, "Pirate's Fortress Sewer Maze Chest",				PIRATE_FORTRESS_MAZE_CHEST,					RED_RUPEE,				{Category::cPiratesFortress,},																											SpoilerCollectionCheckGroup::GROUP_PIRATES_FORTRESS);
	locationTable[PIRATE_FORTRESS_SEWER_CAGE]								   = ItemLocation::Collectable (Scene,Flag, "Pirate's Fortress Sewer Cage",						PIRATE_FORTRESS_SEWER_CAGE,					PIECE_OF_HEART,			{Category::cPiratesFortress,},																											SpoilerCollectionCheckGroup::GROUP_PIRATES_FORTRESS);
	locationTable[PIRATE_FORTRESS_EXTERIOR_LOG_CHEST]						   = ItemLocation::Chest	   (Scene,Flag, "Pirate's Fortress Exterior Log Chest",				PIRATE_FORTRESS_EXTERIOR_LOG_CHEST,			RED_RUPEE,				{Category::cPiratesFortress,},																											SpoilerCollectionCheckGroup::GROUP_PIRATES_FORTRESS);
	locationTable[PIRATE_FORTRESS_EXTERIOR_SAND_CHEST]						   = ItemLocation::Chest	   (Scene,Flag, "Pirate's Fortress Exterior Sand Chest",			PIRATE_FORTRESS_EXTERIOR_SAND_CHEST,		RED_RUPEE,				{Category::cPiratesFortress,},																											SpoilerCollectionCheckGroup::GROUP_PIRATES_FORTRESS);
	locationTable[PIRATE_FORTRESS_EXTERIOR_CORNER_CHEST]					   = ItemLocation::Chest	   (Scene,Flag, "Pirate's Fortress Exterior Corner Chest",			PIRATE_FORTRESS_EXTERIOR_CORNER_CHEST,		RED_RUPEE,				{Category::cPiratesFortress,},																											SpoilerCollectionCheckGroup::GROUP_PIRATES_FORTRESS);
	
	//Beneath The Well
	locationTable[BENEATH_THE_WELL_MIRROR_SHIELD_CHEST]						   = ItemLocation::Chest	(Scene,Flag, "Beneath the Well Mirror Shield Chest"	,				BENEATH_THE_WELL_MIRROR_SHIELD_CHEST,	MIRROR_SHIELD,			{Category::cBeneathTheWell,},																													SpoilerCollectionCheckGroup::GROUP_DUNGEON_BENEATH_THE_WELL);
	locationTable[BENEATH_THE_WELL_LEFT_PATH_CHEST]						  	   = ItemLocation::Chest	(Scene,Flag, "Beneath the Well Left Path Chest"	,				    BENEATH_THE_WELL_LEFT_PATH_CHEST,	    PURPLE_RUPEE,			{Category::cBeneathTheWell,},																													SpoilerCollectionCheckGroup::GROUP_DUNGEON_BENEATH_THE_WELL);
	locationTable[BENEATH_THE_WELL_RIGHT_PATH_CHEST]						   = ItemLocation::Chest	(Scene,Flag, "Beneath the Well Right Path Chest",					BENEATH_THE_WELL_RIGHT_PATH_CHEST,   	PURPLE_RUPEE,			{Category::cBeneathTheWell,},																													SpoilerCollectionCheckGroup::GROUP_DUNGEON_BENEATH_THE_WELL);
	
	//Ikana Castle
	locationTable[IKANA_CASTLE_PILLAR]										   = ItemLocation::Collectable(Scene,Flag, "Ikana Castle Pillar",								IKANA_CASTLE_PILLAR,				PIECE_OF_HEART,					{Category::cIkanaCastle,},																													SpoilerCollectionCheckGroup::GROUP_IKANA_CASTLE);
	locationTable[IKANA_CASTLE_IKANA_KING]									   = ItemLocation::Base 	  (Scene,Flag, "Ikana Castle Ikana King",							IKANA_CASTLE_IKANA_KING,			ELEGY_OF_EMPTINESS,				{Category::cIkanaCastle,Category::cSong,},																									SpoilerCollectionCheckGroup::GROUP_IKANA_CASTLE);
	
	//Secret Shrine
	locationTable[SECRET_SHRINE_DINOLFOS_CHEST]							   	   = ItemLocation::Chest	(Scene,Flag, "Secret Shrine Dinolfos Chest",						SECRET_SHRINE_DINOLFOS_CHEST,			SILVER_RUPEE,			{Category::cSecretShrine,},																								SpoilerCollectionCheckGroup::GROUP_SECRET_SHRINE);
	locationTable[SECRET_SHRINE_WIZZROBE_CHEST]							   	   = ItemLocation::Chest	(Scene,Flag, "Secret Shrine Wizzrobe Chest",						SECRET_SHRINE_WIZZROBE_CHEST,			SILVER_RUPEE,			{Category::cSecretShrine,},																								SpoilerCollectionCheckGroup::GROUP_SECRET_SHRINE);
	locationTable[SECRET_SHRINE_WART_CHEST]								   	   = ItemLocation::Chest	(Scene,Flag, "Secret Shrine Wart Chest",							SECRET_SHRINE_WART_CHEST,				SILVER_RUPEE,			{Category::cSecretShrine,},																								SpoilerCollectionCheckGroup::GROUP_SECRET_SHRINE);
	locationTable[SECRET_SHRINE_GARO_CHEST]								   	   = ItemLocation::Chest	(Scene,Flag, "Secret Shrine Garo Chest",							SECRET_SHRINE_GARO_CHEST,				SILVER_RUPEE,			{Category::cSecretShrine,},																								SpoilerCollectionCheckGroup::GROUP_SECRET_SHRINE);
	locationTable[SECRET_SHRINE_FINAL_CHEST]							   	   = ItemLocation::Chest	(Scene,Flag, "Secret Shrine Final Chest",							SECRET_SHRINE_FINAL_CHEST,				PIECE_OF_HEART,			{Category::cSecretShrine,},																								SpoilerCollectionCheckGroup::GROUP_SECRET_SHRINE);
	
	//The Moon
	locationTable[THE_MOON_DEKU_TRIAL_BONUS]								   = ItemLocation:Base		(Scene,Flag, "The Moon Deku Trial Bonus",							THE_MOON_DEKU_TRIAL_BONUS,			PIECE_OF_HEART,				{Category::cTheMoon,},																														SpoilerCollectionCheckGroup::GROUP_THE_MOON);
	locationTable[THE_MOON_GORON_TRIAL_BONUS]								   = ItemLocation:Base		(Scene,Flag, "The Moon Goron Trial Bonus",							THE_MOON_GORON_TRIAL_BONUS,			PIECE_OF_HEART,				{Category::cTheMoon,},																														SpoilerCollectionCheckGroup::GROUP_THE_MOON);
	locationTable[THE_MOON_ZORA_TRIAL_BONUS]								   = ItemLocation:Base		(Scene,Flag, "The Moon Zora Trial Bonus",							THE_MOON_ZORA_TRIAL_BONUS,			PIECE_OF_HEART,				{Category::cTheMoon,},																														SpoilerCollectionCheckGroup::GROUP_THE_MOON);
	locationTable[THE_MOON_LINK_TRIAL_BONUS]								   = ItemLocation:Base		(Scene,Flag, "The Moon Link Trial Bonus",							THE_MOON_LINK_TRIAL_BONUS,			PIECE_OF_HEART,				{Category::cTheMoon,},																														SpoilerCollectionCheckGroup::GROUP_THE_MOON);
	locationTable[THE_MOON_MAJORA_CHILD]									   = ItemLocation:Base		(Scene,Flag, "The Moon Majora Child",								THE_MOON_MAJORA_CHILD,				FIERCE_DIETY_MASK,			{Category::cTheMoon,},																														SpoilerCollectionCheckGroup::GROUP_THE_MOON);
	
	/*-------------------------------
       --- GOLD SKULLTULA TOKENS ---
      -------------------------------*/
	
	//Southern Swamp Skulltla House
	locationTable[SSH_MAIN_ROOM_NEAR_CEILING]								   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Main Room Near Ceiling",			SSH_MAIN_ROOM_NEAR_CEILING,				SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_MAIN_ROOM_WATER]										   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Main Room Water",					SSH_MAIN_ROOM_WATER,					SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_MAIN_ROOM_LOWER_LEFT_SOIL]							   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Main Room Lower Left Soil",		SSH_MAIN_ROOM_LOWER_LEFT_SOIL,			SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_MAIN_ROOM_LOWER_RIGHT_SOIL]							   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Main Room Lower Right Soil",		SSH_MAIN_ROOM_LOWER_RIGHT_SOIL,			SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_MAIN_ROOM_UPPER_SOIL]									   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Main Room Upper Soil",				SSH_MAIN_ROOM_UPPER_SOIL,				SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_MAIN_ROOM_PILLAR]										   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Main Room Pillar",					SSH_MAIN_ROOM_PILLAR,					SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_MAIN_ROOM_UPPER_PILLAR]								   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Main Room Upper Pillar",			SSH_MAIN_ROOM_UPPER_PILLAR,				SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_MAIN_ROOM_JAR]										   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Main Room Jar",					SSH_MAIN_ROOM_JAR,						SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_MONUMENT_ROOM_CRATE_1]								   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Monument Room Crate 1",			SSH_MONUMENT_ROOM_CRATE_1,				SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_MONUMENT_ROOM_CRATE_2]								   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Monument Room Crate 2",			SSH_MONUMENT_ROOM_CRATE_2,				SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_MONUMENT_ROOM_TORCH]									   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Monument Room Torch",				SSH_MONUMENT_ROOM_TORCH,				SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_MONUMENT_ROOM_ON_MONUMENT]							   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Monument Room On Monument",		SSH_MONUMENT_ROOM_ON_MONUMENT,			SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_MONUMENT_ROOM_LOWER_WALL]								   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Monument Room Lower Wall",			SSH_MONUMENT_ROOM_LOWER_WALL,			SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_GOLD_ROOM_NEAR_CEILING]								   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Gold Room Near Ceiling",			SSH_GOLD_ROOM_NEAR_CEILING,				SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_GOLD_ROOM_PILLAR]										   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Gold Room Pillar",					SSH_GOLD_ROOM_PILLAR,					SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_GOLD_ROOM_BEEHIVE]									   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Gold Room Beehive",				SSH_GOLD_ROOM_BEEHIVE,					SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_GOLD_ROOM_WALL]										   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Gold Room Wall",					SSH_GOLD_ROOM_WALL,						SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_POT_ROOM_JAR]											   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Pot Room Jar",						SSH_POT_ROOM_JAR,						SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_POT_ROOM_POT_1]										   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Pot Room Pot 1",					SSH_POT_ROOM_POT_1,						SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_POT_ROOM_POT_2]										   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Pot Room Pot 2",					SSH_POT_ROOM_POT_2,						SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_POT_ROOM_BEHIND_VINES]								   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Pot Room Behind Vines",			SSH_POT_ROOM_BEHIND_VINES,				SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_POT_ROOM_WALL]										   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Pot Room Wall",					SSH_POT_ROOM_WALL,						SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_POT_ROOM_BEEHIVE_1]									   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Pot Room Beehive 1",				SSH_POT_ROOM_BEEHIVE_1,					SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_POT_ROOM_BEEHIVE_2]									   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Pot Room Beehive 2",				SSH_POT_ROOM_BEEHIVE_2,					SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_TREE_ROOM_TREE_1]										   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Tree Room Tree 1",					SSH_TREE_ROOM_TREE_1,					SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_TREE_ROOM_TREE_2]										   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Tree Room Tree 2",					SSH_TREE_ROOM_TREE_2,					SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_TREE_ROOM_TREE_3]										   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Tree Room Tree 3",					SSH_TREE_ROOM_TREE_3,					SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_TREE_ROOM_GRASS_1]									   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Tree Room Grass 1",				SSH_TREE_ROOM_GRASS_1,					SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_TREE_ROOM_GRASS_2]									   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Tree Room Grass 2",				SSH_TREE_ROOM_GRASS_2,					SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	locationTable[SSH_TREE_ROOM_BEEHIVE]									   = ItemLocation::SGSToken (Scene,Flag, "Swamp Spider House Tree Room Beehive",				SSH_TREE_ROOM_BEEHIVE,					SWAMP_SKULLTULA_TOKEN,	{Category::cSouthernSwamp, Category::cSwampSkulltula,},																						SpoilerCollectionCheckGroup::GROUP_SSH);
	
	//Oceanside Spider House
	locationTable[OSH_ENTRANCE_LEFT_WALL]									   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Entrance Left Wall",			OSH_ENTRANCE_LEFT_WALL,				OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_ENTRANCE_RIGHT_WALL]									   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Entrance Right Wall",			OSH_ENTRANCE_RIGHT_WALL,			OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_ENTRANCE_WEB]											   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Entrance Web",					OSH_ENTRANCE_WEB,					OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_LIBRARY_HOLE_BEHIND_PICTURE]							   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Library Hole Behind Picture",	OSH_LIBRARY_HOLE_BEHIND_PICTURE,	OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_LIBRARY_HOLE_BEHIND_CABINET]							   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Library Hole Behind Cabinet",	OSH_LIBRARY_HOLE_BEHIND_CABINET,	OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_LIBRARY_ON_CORNER_BOOKSHELF]							   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Library On Corner Bookshelf",	OSH_LIBRARY_ON_CORNER_BOOKSHELF,	OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_LIBRARY_CEILING_EDGE]									   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Library Ceiling Edge",			OSH_LIBRARY_CEILING_EDGE,			OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_LIBRARY_BEHIND_BOOKCASE_1]							   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Library Behind Bookcase 1",	OSH_LIBRARY_BEHIND_BOOKCASE_1,		OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_LIBRARY_BEHIND_BOOKCASE_2]							   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Library Behind Bookacse 2",	OSH_LIBRARY_BEHIND_BOOKCASE_2,		OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_LIBRARY_BEHIND_PICTURE]								   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Library  Behind Picture",		OSH_LIBRARY_BEHIND_PICTURE,			OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_SECOND_ROOM_CEILING_EDGE]								   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Second Room Ceiling Edge",		OSH_SECOND_ROOM_CEILING_EDGE,		OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_SECOND_ROOM_CEILING_PLANK]							   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Second Room Ceiling Plank",	OSH_SECOND_ROOM_CEILING_PLANK,		OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_SECOND_ROOM_JAR]										   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Second Room Jar",				OSH_SECOND_ROOM_JAR,				OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_SECOND_ROOM_WEBBED_HOLE]								   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Second Room Webbed Hole",		OSH_SECOND_ROOM_WEBBED_HOLE,		OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_SECOND_ROOM_WEBBED_POT]								   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Second Room Webbed Pot",		OSH_SECOND_ROOM_WEBBED_POT,			OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_SECOND_ROOM_UPPER_POT]								   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Second Room Upper Pot",		OSH_SECOND_ROOM_UPPER_POT,			OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_SECOND_ROOM_BEHIND_SKULL_1]							   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Second Room Behind Skull 1",	OSH_SECOND_ROOM_BEHIND_SKULL_1,		OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_SECOND_ROOM_BEHIND_SKULL_2]							   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Second Room Behind Skull 2",	OSH_SECOND_ROOM_BEHIND_SKULL_2,		OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_SECOND_ROOM_LOWER_POT]								   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Second Room Lower Pot",		OSH_SECOND_ROOM_LOWER_POT,			OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_STORAGE_ROOM_CEILING_WEB]								   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Storage Room Ceiling Web",		OSH_STORAGE_ROOM_CEILING_WEB,		OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_STORAGE_ROOM_BEHIND_CRATE]							   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Storage Room Behind Crate",	OSH_STORAGE_ROOM_BEHIND_CRATE,		OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_STORAGE_ROOM_BEHIND_BOAT]								   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Storage Room Behind Boat",		OSH_STORAGE_ROOM_BEHIND_BOAT,		OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_STORAGE_ROOM_CRATE]									   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Storage Room Crate",			OSH_STORAGE_ROOM_CRATE,				OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_STORAGE_ROOM_JAR]										   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Storage Room Jar",				OSH_STORAGE_ROOM_JAR,				OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_COLORED_SKULLS_CEILING_EDGE]							   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Colored Skulls Ceiling Edge",	OSH_COLORED_SKULLS_CEILING_EDGE,	OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_COLORED_SKULLS_CHANDELIER_1]							   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Colored Skulls Chandelier 1",	OSH_COLORED_SKULLS_CHANDELIER_1,	OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_COLORED_SKULLS_CHANDELIER_2]							   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Colored Skulls Chandelier 2",	OSH_COLORED_SKULLS_CHANDELIER_2,	OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_COLORED_SKULLS_CHANDELIER_3]							   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Colored Skulls Chandelier 3",	OSH_COLORED_SKULLS_CHANDELIER_3,	OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_COLORED_SKULLS_BEHIND_PICTURE]						   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Colored Skulls Behind Picture",OSH_COLORED_SKULLS_BEHIND_PICTURE,	OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
    locationTable[OSH_COLORED_SKULLS_POT]									   = ItemLocation::OGSToken	(Scene,Flag, "Oceanside Spider House Colored Skulls Pot",			OSH_COLORED_SKULLS_POT,				OCEANSIDE_SKULLTULA_TOKEN,	{Category::cGreatBayCoast, Category::cOceanSkulltula},																						SpoilerCollectionCheckGroup::GROUP_OSH);
 
    /*--------------------------------
			--Stray Fairies---
	  -------------------------------*/
	
	//Clock Town Stray Fairy
	locationTable[LAUNDRY_POOL_SF]											   = ItemLocation::StrayFairy(Scene,Flag, "Laundry Pool Stray Fairy",								LAUNDRY_POOL_SF,					CT_STRAY_FAIRY,				{Category::cLaundryPool, Category::cVanillaStrayFairy, Category::cCTStray,},																						SpoilerCollectionCheckGroup::GROUP_LAUNDRY_POOL);
	
	
	//Woodfall Stray Faries
	locationTable[WF_SF_ENTRANCE_FAIRY]										   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Entrance",					WF_SF_ENTRANCE_FAIRY,				WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WF_SF_ENTRANCE_PLATFORM]									   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Entrance Platform",			WF_SF_ENTRANCE_PLATFORM,			WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WF_SF_MAIN_ROOM_BUBBLE]									   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Main Room Bubble",			WF_SF_MAIN_ROOM_BUBBLE,				WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WF_SF_MAIN_ROOM_SWITCH]									   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Main Room Switch",			WF_SF_MAIN_ROOM_SWITCH,				WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray,  Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WF_SF_PRE_BOSS_LOWER_RIGHT_BUBBLE]						   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Pre-Boss Lower Right Bubble",WF_SF_PRE_BOSS_LOWER_RIGHT_BUBBLE,	WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray,  Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WF_SF_PRE_BOSS_UPPER_RIGHT_BUBBLE]						   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Pre-Boss Upper Left Bubble",	WF_SF_PRE_BOSS_UPPER_LEFT_BUBBLE,	WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WF_SF_PRE_BOSS_UPPER_LEFT_BUBBLE]							   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Pre-Boss Upper Right Bubble",WF_SF_PRE_BOSS_UPPER_RIGHT_BUBBLE,	WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WF_SF_PRE_BOSS_PILLAR_BUBBLE]								   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Pre-Boss Pillar Bubble",		WF_SF_PRE_BOSS_PILLAR_BUBBLE,		WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray,  Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WF_SF_DEKU_BABA]											   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Deku Baba",					WF_SF_DEKU_BABA,					WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray,  Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WF_SF_POISON_WATER_BUBBLE]								   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Poison Water Bubble",		WF_SF_POISON_WATER_BUBBLE,			WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray,  Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WF_SF_SKULLTULA]											   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Skulltula",					WF_SF_SKULLTULA,					WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WF_SF_DARK_ROOM]											   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Dark Room",					WF_SF_DARK_ROOM,					WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WF_SF_JAR_FAIRY]											   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Jar Fairy",					WF_SF_JAR_FAIRY,					WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WF_SF_BRIDGE_ROOM_BEEHIVE]								   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Bridge Room Beehive",		WF_SF_BRIDGE_ROOM_BEEHIVE,			WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[WF_SF_PLATFORM_ROOM_BEEHIVE]								   = ItemLocation::StrayFairy(Scene,Flag, "Woodfall Temple Stray Fairy Platform Room Beehive",		WF_SF_PLATFORM_ROOM_BEEHIVE,		WF_STRAY_FAIRY,				{Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray,  Category::cVanillaStrayFairy,},									SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	
	//Snowhead Stray Faries
	locationTable[SH_SF_SNOW_ROOM_BUBBLE]									   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Snow Room Bubble",			SH_SF_SNOW_ROOM_BUBBLE,				SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SH_SF_CEILING_BUBBLE]										   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Ceiling Bubble",			SH_SF_CEILING_BUBBLE,				SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SH_SF_DINOLFOS_1]											   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Dinolfos 1",				SH_SF_DINOLFOS_1,					SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SH_SF_DINOLFOS_2]											   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Dinolfos 2",				SH_SF_DINOLFOS_2,					SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SH_SF_BRIDGE_ROOM_LEDGE_BUBBLE]							   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Bridge Room Ledge Bubble",	SH_SF_BRIDGE_ROOM_LEDGE_BUBBLE,		SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SH_SF_BRIDGE_ROOM_PILLAR_BUBBLE]							   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Bridge Room Pillar Bubble",	SH_SF_BRIDGE_ROOM_PILLAR_BUBBLE,	SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SH_SF_MAP_ROOM_FAIRY]										   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Map Room Fairy",			SH_SF_MAP_ROOM_FAIRY,				SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SH_SF_MAP_ROOM_LEDGE]										   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Map Room Ledge",			SH_SF_MAP_ROOM_LEDGE,				SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SH_SF_BASEMENT]											   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Basement",					SH_SF_BASEMENT,						SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SH_SF_TWIN_BLOCK]											   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Twin Block",				SH_SF_TWIN_BLOCK,					SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SH_SF_ICICLE_ROOM_WALL]									   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Icicle Room Wall",			SH_SF_ICICLE_ROOM_WALL,				SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SH_SF_MAIN_ROOM_WALL]										   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Main Room Wall",			SH_SF_MAIN_ROOM_WALL,				SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SH_SF_PILLAR_FREEZARDS]									   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Pillar Freezards",			SH_SF_PILLAR_FREEZARDS,				SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SH_SF_ICE_PUZZLE]											   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Ice Puzzle",				SH_SF_ICE_PUZZLE,					SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[SH_SF_CRATE]												   = ItemLocation::StrayFairy (Scene,Flag, "Snowhead Temple Stray Fairy Crate",						SH_SF_CRATE,						SH_STRAY_FAIRY,			{Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,},																SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	
	//Great Bay Stray Fairies
	locationTable[GBT_SF_SKULLTULA]											   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Skulltula",			GBT_SF_SKULLTULA,					GBT_STRAY_FAIRY,				{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},															SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SF_WATER_CONTROL_UNDERWATER_BUBBLE]					   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Water Control Room Underwater Bubble",	GBT_SF_WATER_CONTROL_UNDERWATER_BUBBLE,	GBT_STRAY_FAIRY,{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},														SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SF_WATERWHEEL_ROOM_LOWER]								   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Waterwheel Room Lower",GBT_SF_WATERWHEEL_ROOM_LOWER,		GBT_STRAY_FAIRY,				{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},															SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SF_WATERWHEEL_ROOM_UPPER]								   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Waterwheel Room Upper",GBT_SF_WATERWHEEL_ROOM_UPPER,		GBT_STRAY_FAIRY,				{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},															SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SF_GREEN_VALVE]										   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Green Valve",			GBT_SF_GREEN_VALVE,					GBT_STRAY_FAIRY,				{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},															SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SF_SEESAW_ROOM]										   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Seesaw Room",			GBT_SF_SEESAW_ROOM,					GBT_STRAY_FAIRY,				{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},															SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SF_ENTRANCE_TORCHES]									   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Entrance Torches",		GBT_SF_ENTRANCE_TORCHES,			GBT_STRAY_FAIRY,				{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},															SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SF_BIO_BABAS]											   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Bio Babas",			GBT_SF_BIO_BABAS,					GBT_STRAY_FAIRY,				{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},															SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SF_UNDERWATER_BARREL]									   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Underwater Barrel",	GBT_SF_UNDERWATER_BARREL,			GBT_STRAY_FAIRY,				{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},															SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SF_WHIRLPOOL_JAR]										   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Whirlpool Jar",		GBT_SF_WHIRLPOOL_JAR,				GBT_STRAY_FAIRY,				{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},															SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SF_WHIRLPOOL_BARREL]									   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Whirlpool Barrel",		GBT_SF_WHIRLPOOL_BARREL,			GBT_STRAY_FAIRY,				{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},															SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SF_DEXIHANDS_JAR]										   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Dexihands Jar",		GBT_SF_DEXIHANDS_JAR,				GBT_STRAY_FAIRY,				{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},															SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SF_LEDGE_JAR]											   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Ledge Jar",			GBT_SF_LEDGE_JAR,					GBT_STRAY_FAIRY,				{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},															SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SF_PRE_BOSS_ROOM_BUBBLE]								   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Pre-Boss Room Bubble",	GBT_SF_PRE_BOSS_ROOM_BUBBLE,		GBT_STRAY_FAIRY,				{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},															SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[GBT_SF_PRE_BOSS_ROOM_UNDERWATER_BUBBLE]					   = ItemLocation::StrayFairy (Scene,Flag, "Great Bay Temple Stray Fairy Pre-Boss Room Underwater Bubble",GBT_SF_PRE_BOSS_ROOM_UNDERWATER_BUBBLE,GBT_STRAY_FAIRY,	{Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,},															SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	
	//Stone Tower Temple Stray Fairies 
	locationTable[ST_SF_MIRROR_SUN_BLOCK]									   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Mirror Sun Block",	ST_SF_MIRROR_SUN_BLOCK,				ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[ST_SF_LAVA_ROOM_LEDGE]									   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Lava Room Ledge",		ST_SF_LAVA_ROOM_LEDGE,				ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[ST_SF_LAVA_ROOM_FIRE_RING]								   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Lava Room Fire Ring",	ST_SF_LAVA_ROOM_FIRE_RING,			ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[ST_SF_EYEGORE]											   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Eyegore",				ST_SF_EYEGORE,						ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[ST_SF_UPDRAFT_FIRE_RING]									   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Updraft Fire Ring",	ST_SF_UPDRAFT_FIRE_RING,			ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[ST_SF_MIRROR_SUN_SWITCH]									   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Mirror Sun Switch",	ST_SF_MIRROR_SUN_SWITCH,			ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[ST_SF_BOSS_WARP]											   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Boss Warp",			ST_SF_BOSS_WARP,					ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[ST_SF_WIZZROBE]											   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Wizzrobe",			ST_SF_WIZZROBE,						ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[ST_SF_DEATH_ARMOS]										   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Death Armos",			ST_SF_DEATH_ARMOS,					ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[ST_SF_UPDRAFT_FROZEN_EYE]									   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Updraft Frozen Eye",	ST_SF_UPDRAFT_FROZEN_EYE,			ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[ST_SF_THIN_BRIDGE]										   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Thin Bridge",			ST_SF_THIN_BRIDGE,					ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[ST_SF_BASEMENT_LEDGE]										   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Basement Ledge",		ST_SF_BASEMENT_LEDGE,				ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[ST_SF_STATUE_EYE]											   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Statue Eye",			ST_SF_STATUE_EYE,					ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[ST_SF_UNDERWATER]											   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Underwater",			ST_SF_UNDERWATER,					ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[ST_SF_BRIDGE_CRYSTAL]										   = ItemLocation::StrayFairy(Scene,Flag, "Stone Tower Temple Stray Fairy Bridge Crystal",		ST_SF_BRIDGE_CRYSTAL,				ST_STRAY_FAIRY,				{Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	
	
    /*-------------------------------
              --- BOSSES ---
      -------------------------------*/

    locationTable[LINKS_POCKET]                                  = ItemLocation::Reward (0xFF, 0xFF,                    "Link's Pocket", LINKS_POCKET,  LIGHT_MEDALLION,   {},                                                                                                                                                   SpoilerCollectionCheck::AlwaysCollected(),             SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN);
    locationTable[WOODFALL_TEMPLE_ODOLWAS_REMAINS]							   = ItemLocation::Reward	(Scene,Flag, "Woodfall Temple Odolwa's Remains",					WOODFALL_TEMPLE_ODOLWAS_REMAINS,	ODOLWAS_REMAINS,			{},																																			SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[SNOWHEAD_TEMPLE_GOHT_REMAINS]							   	   = ItemLocation::Reward	(Scene,Flag, "Snowhead Temple Goht's Remains",						SNOWHEAD_TEMPLE_GOHT_REMAINS,		GOHTS_REMAINS,				{},																																			SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[GBT_GYORGS_REMAINS]										   = ItemLocation::Reward	(Scene,Flag, "Great Bay Temple Gyorg's Remains",					GBT_GYORGS_REMAINS,					GYORGS_REMAINS,				{},																																			SpoilerCollectionCheckGroup::GROUP_DUNGEON_GBT);
	locationTable[STONE_TOWER_TEMPLE_TWINMOLDS_REMAINS]						   = ItemLocation::Reward	(Scene,Flag, "Stone Tower Temple Twinmold's Remains",				STONE_TOWER_TEMPLE_TWINMOLDS_REMAINS,TWINMOLDS_REMAINS,			{},																																   			SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	locationTable[GANON]                                         = ItemLocation::Reward (0xFF, 0xF0,                    "Ganon",         NONE,          TRIFORCE,          {},                                                                                                                                                   SpoilerCollectionCheck::None(),                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);

    /*-------------------------------
          ---HEART CONTAINERS ---
      -------------------------------*/
	locationTable[WOODFALL_TEMPLE_ODOLWAS_HEART]							   = ItemLocation::Collectable(Scene,Flag, "Woodfall Temple Hero's Bow Chest",					WOODFALL_TEMPLE_ODOLWAS_HEART,		HEART_CONTAINER,			{Category::cWoodfall, Category::cWoodfallTemple,Category::cBossHeart, Category::cSongDungeonReward},										SpoilerCollectionCheckGroup::GROUP_WOODFALL_TEMPLE);
	locationTable[SNOWHEAD_TEMPLE_GOHT_HEART]							   	   = ItemLocation::Collectable(Scene,Flag, "Snowhead Temple Goht Heart Container",				SNOWHEAD_TEMPLE_GOHT_HEART,			HEART_CONTAINER,			{Category::cSnowhead, Category::cSnowheadTemple, Category::cBossHeart, Category::cSongDungeonReward},										SpoilerCollectionCheckGroup::GROUP_SNOWHEAD_TEMPLE);
	locationTable[GBT_GYORG_HEART]											   = ItemLocation::Base		(Scene,Flag, "Great Bay Temple Gyorg Heart Container",				GBT_GYORG_HEART,					HEART_CONTAINER,			{Category::cGreatBayTemple, Category::cBossHeart, Category::cSongDungeonReward},															SpoilerCollectionCheckGroup::GROUP_DUNEGON_GBT);
	locationTable[STONE_TOWER_TEMPLE_TWINMOLD_HEART]						   = ItemLocation::Collectable(Scene,Flag, "Stone Tower Temple Twinmold Heart Container",		STONE_TOWER_TEMPLE_TWINMOLD_HEART,	HEART_CONTAINER,			{Category::cStoneTowerTemple,Category::cBossHeart, Category::cSongDungeonReward},															SpoilerCollectionCheckGroup::GROUP_STONE_TOWER_TEMPLE);
	
    /*-------------------------------
            --- CUTSCENES ---
      -------------------------------*/
/*TODO--CUTSCENE SKIPS FOR MM3D - EXAMPLES FROM OOT3D BELOW

    locationTable[TOT_LIGHT_ARROWS_CUTSCENE]                     = ItemLocation::Delayed(0xFF, 0x01, "ToT Light Arrow Cutscene",                       TOT_LIGHT_ARROWS_CUTSCENE,   LIGHT_ARROWS,              {Category::cTempleOfTime, Category::cMarket},                                                                     SpoilerCollectionCheck::EventChkInf(0xC4),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[LW_GIFT_FROM_SARIA]                            = ItemLocation::Delayed(0xFF, 0x02, "LW Gift From Saria",                             LW_GIFT_FROM_SARIA,          PROGRESSIVE_OCARINA,       {Category::cLostWoods, Category::cForest},                                                                        SpoilerCollectionCheck::EventChkInf(0xC1),               SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    locationTable[ZF_GREAT_FAIRY_REWARD]                         = ItemLocation::Delayed(0xFF, 0x10, "ZF Great Fairy Reward",                          ZF_GREAT_FAIRY_REWARD,       FARORES_WIND,              {Category::cZorasFountain, Category::cFairies},                                                                   SpoilerCollectionCheck::ItemGetInf(16),                  SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    locationTable[HC_GREAT_FAIRY_REWARD]                         = ItemLocation::Delayed(0xFF, 0x11, "HC Great Fairy Reward",                          HC_GREAT_FAIRY_REWARD,       DINS_FIRE,                 {Category::cHyruleCastle, Category::cMarket, Category::cFairies},                                                 SpoilerCollectionCheck::ItemGetInf(17),                  SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[COLOSSUS_GREAT_FAIRY_REWARD]                   = ItemLocation::Delayed(0xFF, 0x12, "Colossus Great Fairy Reward",                    COLOSSUS_GREAT_FAIRY_REWARD, NAYRUS_LOVE,               {Category::cDesertColossus, Category::cFairies},                                                                  SpoilerCollectionCheck::ItemGetInf(18),                  SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    locationTable[DMT_GREAT_FAIRY_REWARD]                        = ItemLocation::Delayed(0xFF, 0x13, "DMT Great Fairy Reward",                         DMT_GREAT_FAIRY_REWARD,      PROGRESSIVE_MAGIC_METER,   {Category::cDeathMountainTrail, Category::cDeathMountain, Category::cFairies},                                    SpoilerCollectionCheck::Chest(0x3B, 0x00),               SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN);
    locationTable[DMC_GREAT_FAIRY_REWARD]                        = ItemLocation::Delayed(0xFF, 0x14, "DMC Great Fairy Reward",                         DMC_GREAT_FAIRY_REWARD,      PROGRESSIVE_MAGIC_METER,   {Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFairies},                                   SpoilerCollectionCheck::Chest(0x3B, 0x01),               SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN);
    locationTable[OGC_GREAT_FAIRY_REWARD]                        = ItemLocation::Delayed(0xFF, 0x15, "OGC Great Fairy Reward",                         OGC_GREAT_FAIRY_REWARD,      DOUBLE_DEFENSE,            {Category::cOutsideGanonsCastle, Category::cFairies},                                                             SpoilerCollectionCheck::Chest(0x3B, 0x02),               SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
                                                                                                                                                                                                               
    locationTable[SHEIK_IN_FOREST]                               = ItemLocation::Delayed(0xFF, 0x20, "Sheik in Forest",                                SHEIK_IN_FOREST,             MINUET_OF_FOREST,          {Category::cSacredForestMeadow, Category::cForest, Category::cSong,},                                             SpoilerCollectionCheck::EventChkInf(0x50),               SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    locationTable[SHEIK_IN_CRATER]                               = ItemLocation::Delayed(0xFF, 0x21, "Sheik in Crater",                                SHEIK_IN_CRATER,             BOLERO_OF_FIRE,            {Category::cDeathMountainCrater, Category::cDeathMountain, Category::cSong,},                                     SpoilerCollectionCheck::EventChkInf(0x51),               SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN);
    locationTable[SHEIK_IN_ICE_CAVERN]                           = ItemLocation::Delayed(0xFF, 0x22, "Sheik in Ice Cavern",                            SHEIK_IN_ICE_CAVERN,         SERENADE_OF_WATER,         {Category::cIceCavern, Category::cSong, Category::cSongDungeonReward},                                            SpoilerCollectionCheck::EventChkInf(0x52),               SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    locationTable[SHEIK_AT_COLOSSUS]                             = ItemLocation::Delayed(0xFF, 0x23, "Sheik at Colossus",                              SHEIK_AT_COLOSSUS,           REQUIEM_OF_SPIRIT,         {Category::cDesertColossus, Category::cSong,},                                                                    SpoilerCollectionCheck::EventChkInf(0xAC),               SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    locationTable[SHEIK_IN_KAKARIKO]                             = ItemLocation::Delayed(0xFF, 0x24, "Sheik in Kakariko",                              SHEIK_IN_KAKARIKO,           NOCTURNE_OF_SHADOW,        {Category::cKakarikoVillage, Category::cKakariko, Category::cSong,},                                              SpoilerCollectionCheck::EventChkInf(0xAA),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[SHEIK_AT_TEMPLE]                               = ItemLocation::Delayed(0xFF, 0x25, "Sheik at Temple",                                SHEIK_AT_TEMPLE,             PRELUDE_OF_LIGHT,          {Category::cTempleOfTime, Category::cMarket, Category::cSong,},                                                   SpoilerCollectionCheck::EventChkInf(0x55),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[SONG_FROM_IMPA]                                = ItemLocation::Delayed(0xFF, 0x26, "Song from Impa",                                 SONG_FROM_IMPA,              ZELDAS_LULLABY,            {Category::cHyruleCastle, Category::cMarket, Category::cSong, Category::cSongDungeonReward},                      SpoilerCollectionCheck::EventChkInf(0x59),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[SONG_FROM_MALON]                               = ItemLocation::Delayed(0xFF, 0x27, "Song from Malon",                                SONG_FROM_MALON,             EPONAS_SONG,               {Category::cLonLonRanch, Category::cSong,},                                                                       SpoilerCollectionCheck::EventChkInf(0x58),               SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
    locationTable[SONG_FROM_SARIA]                               = ItemLocation::Delayed(0xFF, 0x28, "Song from Saria",                                SONG_FROM_SARIA,             SARIAS_SONG,               {Category::cSacredForestMeadow, Category::cForest, Category::cSong,},                                             SpoilerCollectionCheck::EventChkInf(0x57),               SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    locationTable[SONG_FROM_COMPOSERS_GRAVE]                     = ItemLocation::Delayed(0xFF, 0x29, "Song from Composers Grave",                      SONG_FROM_COMPOSERS_GRAVE,   SUNS_SONG,                 {Category::cGraveyard, Category::cKakariko, Category::cSong,},                                                    SpoilerCollectionCheck::EventChkInf(0x5A),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[SONG_FROM_OCARINA_OF_TIME]                     = ItemLocation::Delayed(0xFF, 0x2A, "Song from Ocarina of Time",                      SONG_FROM_OCARINA_OF_TIME,   SONG_OF_TIME,              {Category::cHyruleField, Category::cSong, Category::cNeedSpiritualStones,},                                       SpoilerCollectionCheck::EventChkInf(0xA9),               SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    locationTable[SONG_FROM_WINDMILL]                            = ItemLocation::Delayed(0xFF, 0x2B, "Song from Windmill",                             SONG_FROM_WINDMILL,          SONG_OF_STORMS,            {Category::cKakarikoVillage, Category::cKakariko, Category::cSong,},                                              SpoilerCollectionCheck::EventChkInf(0x5B),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
*/
    /*-------------------------------
               --- COWS ---
      -------------------------------*/
	locationTable[GBC_GROTTO_COW1]											   = ItemLocation::Base		(Scene,Flag, "Great Bay Coast Cow 1",								GBC_GROTTO_COW1,					MILK,						{Category::cGreatBayCoast,Category::cCow, Category::cGrotto,},																									SpoilerCollectionCheckGroup::GROUP_GBC);
	locationTable[GBC_GROTTO_COW2]											   = ItemLocation::Base		(Scene,Flag, "Great Bay Coast Cow 2",								GBC_GROTTO_COW2,					MILK,						{Category::cGreatBayCoast,Category::cCow, Category::cGrotto,},																									SpoilerCollectionCheckGroup::GROUP_GBC);
	locationTable[ROMANI_RANCH_RANCH_COW_1]									   = ItemLocation::Base		(Scene,Flag, "Romani Ranch Cow 1",									ROMANI_RANCH_COW_1,						MILK,					{Category::cRomaniRanch, Category::cCow},																													SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH);
	locationTable[ROMANI_RANCH_RANCH_COW_2]									   = ItemLocation::Base		(Scene,Flag, "Romani Ranch Cow 2",									ROMANI_RANCH_COW_2,						MILK,					{Category::cRomaniRanch, Category::cCow},																													SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH);
	locationTable[ROMANI_RANCH_RANCH_COW_3]									   = ItemLocation::Base		(Scene,Flag, "Romani Ranch Cow 3",									ROMANI_RANCH_COW_3,						MILK,					{Category::cRomaniRanch, Category::cCow},																													SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH);
	locationTable[TERMINA_FIELD_GROTTO_COW_1]								   = ItemLocation::Base		(Scene,Flag, "Termina Field Grotto Cow 1",							TERMINA_FIELD_GROTTO_COW_1,			MILK,						{Category::cTerminaField,Category::cCow,},																									SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
	locationTable[TERMINA_FIELD_GROTTO_COW_2]								   = ItemLocation::Base		(Scene,Flag, "Termina Field Grotto Cow 2",							TERMINA_FIELD_GROTTO_COW_2,			MILK,						{Category::cTerminaField,Category::cCow,},																									SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
	locationTable[BENEATH_THE_WELL_COW]						   = ItemLocation::Chest	(Scene,Flag, "Beneath the Well Mirror Shield Chest"					BENEATH_THE_WELL_MIRROR_SHIELD_CHEST,	MIRROR_SHIELD,			{Category::cBeneathTheWell,cCow},																													SpoilerCollectionCheckGroup::GROUP_DUNGEON_BENEATH_THE_WELL);
	
    /*-------------------------------
              --- SHOPS ---
      8     6               2     4

      7     5               1     3
      -------------------------------*/
/*TODO -- SHOP SANITY -- EXAMPLES FROM OOT3D BELOW
    locationTable[KF_SHOP_ITEM_1]                                = ItemLocation::Base(0x2D, 0x30, "KF Shop Item 1",                                    KF_SHOP_ITEM_1,              BUY_DEKU_SHIELD,           {Category::cKokiriForest, Category::cForest, Category::cShop},                                                    SpoilerCollectionCheck::ShopItem(0x2D, 0),               SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    locationTable[KF_SHOP_ITEM_2]                                = ItemLocation::Base(0x2D, 0x31, "KF Shop Item 2",                                    KF_SHOP_ITEM_2,              BUY_DEKU_NUT_5,            {Category::cKokiriForest, Category::cForest, Category::cShop},                                                    SpoilerCollectionCheck::ShopItem(0x2D, 1),               SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    locationTable[KF_SHOP_ITEM_3]                                = ItemLocation::Base(0x2D, 0x32, "KF Shop Item 3",                                    KF_SHOP_ITEM_3,              BUY_DEKU_NUT_10,           {Category::cKokiriForest, Category::cForest, Category::cShop},                                                    SpoilerCollectionCheck::ShopItem(0x2D, 2),               SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    locationTable[KF_SHOP_ITEM_4]                                = ItemLocation::Base(0x2D, 0x33, "KF Shop Item 4",                                    KF_SHOP_ITEM_4,              BUY_DEKU_STICK_1,          {Category::cKokiriForest, Category::cForest, Category::cShop},                                                    SpoilerCollectionCheck::ShopItem(0x2D, 3),               SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    locationTable[KF_SHOP_ITEM_5]                                = ItemLocation::Base(0x2D, 0x34, "KF Shop Item 5",                                    KF_SHOP_ITEM_5,              BUY_DEKU_SEEDS_30,         {Category::cKokiriForest, Category::cForest, Category::cShop},                                                    SpoilerCollectionCheck::ShopItem(0x2D, 4),               SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    locationTable[KF_SHOP_ITEM_6]                                = ItemLocation::Base(0x2D, 0x35, "KF Shop Item 6",                                    KF_SHOP_ITEM_6,              BUY_ARROWS_10,             {Category::cKokiriForest, Category::cForest, Category::cShop},                                                    SpoilerCollectionCheck::ShopItem(0x2D, 5),               SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    locationTable[KF_SHOP_ITEM_7]                                = ItemLocation::Base(0x2D, 0x36, "KF Shop Item 7",                                    KF_SHOP_ITEM_7,              BUY_ARROWS_30,             {Category::cKokiriForest, Category::cForest, Category::cShop},                                                    SpoilerCollectionCheck::ShopItem(0x2D, 6),               SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    locationTable[KF_SHOP_ITEM_8]                                = ItemLocation::Base(0x2D, 0x37, "KF Shop Item 8",                                    KF_SHOP_ITEM_8,              BUY_HEART,                 {Category::cKokiriForest, Category::cForest, Category::cShop},                                                    SpoilerCollectionCheck::ShopItem(0x2D, 7),               SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);

    locationTable[KAK_POTION_SHOP_ITEM_1]                        = ItemLocation::Base(0x30, 0x30, "Kak Potion Shop Item 1",                            KAK_POTION_SHOP_ITEM_1,      BUY_DEKU_NUT_5,            {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x30, 0),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[KAK_POTION_SHOP_ITEM_2]                        = ItemLocation::Base(0x30, 0x31, "Kak Potion Shop Item 2",                            KAK_POTION_SHOP_ITEM_2,      BUY_FISH,                  {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x30, 1),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[KAK_POTION_SHOP_ITEM_3]                        = ItemLocation::Base(0x30, 0x32, "Kak Potion Shop Item 3",                            KAK_POTION_SHOP_ITEM_3,      BUY_RED_POTION_30,         {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x30, 2),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[KAK_POTION_SHOP_ITEM_4]                        = ItemLocation::Base(0x30, 0x33, "Kak Potion Shop Item 4",                            KAK_POTION_SHOP_ITEM_4,      BUY_GREEN_POTION,          {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x30, 3),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[KAK_POTION_SHOP_ITEM_5]                        = ItemLocation::Base(0x30, 0x34, "Kak Potion Shop Item 5",                            KAK_POTION_SHOP_ITEM_5,      BUY_BLUE_FIRE,             {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x30, 4),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[KAK_POTION_SHOP_ITEM_6]                        = ItemLocation::Base(0x30, 0x35, "Kak Potion Shop Item 6",                            KAK_POTION_SHOP_ITEM_6,      BUY_BOTTLE_BUG,            {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x30, 5),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[KAK_POTION_SHOP_ITEM_7]                        = ItemLocation::Base(0x30, 0x36, "Kak Potion Shop Item 7",                            KAK_POTION_SHOP_ITEM_7,      BUY_POE,                   {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x30, 6),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[KAK_POTION_SHOP_ITEM_8]                        = ItemLocation::Base(0x30, 0x37, "Kak Potion Shop Item 8",                            KAK_POTION_SHOP_ITEM_8,      BUY_FAIRYS_SPIRIT,         {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x30, 7),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);

    locationTable[MARKET_BOMBCHU_SHOP_ITEM_1]                    = ItemLocation::Base(0x32, 0x30, "MK Bombchu Shop Item 1",                            MARKET_BOMBCHU_SHOP_ITEM_1,  BUY_BOMBCHU_5,             {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x32, 0),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_BOMBCHU_SHOP_ITEM_2]                    = ItemLocation::Base(0x32, 0x31, "MK Bombchu Shop Item 2",                            MARKET_BOMBCHU_SHOP_ITEM_2,  BUY_BOMBCHU_10,            {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x32, 1),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_BOMBCHU_SHOP_ITEM_3]                    = ItemLocation::Base(0x32, 0x32, "MK Bombchu Shop Item 3",                            MARKET_BOMBCHU_SHOP_ITEM_3,  BUY_BOMBCHU_10,            {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x32, 2),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_BOMBCHU_SHOP_ITEM_4]                    = ItemLocation::Base(0x32, 0x33, "MK Bombchu Shop Item 4",                            MARKET_BOMBCHU_SHOP_ITEM_4,  BUY_BOMBCHU_10,            {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x32, 3),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_BOMBCHU_SHOP_ITEM_5]                    = ItemLocation::Base(0x32, 0x34, "MK Bombchu Shop Item 5",                            MARKET_BOMBCHU_SHOP_ITEM_5,  BUY_BOMBCHU_20,            {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x32, 4),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_BOMBCHU_SHOP_ITEM_6]                    = ItemLocation::Base(0x32, 0x35, "MK Bombchu Shop Item 6",                            MARKET_BOMBCHU_SHOP_ITEM_6,  BUY_BOMBCHU_20,            {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x32, 5),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_BOMBCHU_SHOP_ITEM_7]                    = ItemLocation::Base(0x32, 0x36, "MK Bombchu Shop Item 7",                            MARKET_BOMBCHU_SHOP_ITEM_7,  BUY_BOMBCHU_20,            {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x32, 6),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_BOMBCHU_SHOP_ITEM_8]                    = ItemLocation::Base(0x32, 0x37, "MK Bombchu Shop Item 8",                            MARKET_BOMBCHU_SHOP_ITEM_8,  BUY_BOMBCHU_20,            {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x32, 7),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);

    locationTable[MARKET_POTION_SHOP_ITEM_1]                     = ItemLocation::Base(0x31, 0x30, "MK Potion Shop Item 1",                             MARKET_POTION_SHOP_ITEM_1,   BUY_GREEN_POTION,          {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x31, 0),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_POTION_SHOP_ITEM_2]                     = ItemLocation::Base(0x31, 0x31, "MK Potion Shop Item 2",                             MARKET_POTION_SHOP_ITEM_2,   BUY_BLUE_FIRE,             {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x31, 1),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_POTION_SHOP_ITEM_3]                     = ItemLocation::Base(0x31, 0x32, "MK Potion Shop Item 3",                             MARKET_POTION_SHOP_ITEM_3,   BUY_RED_POTION_30,         {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x31, 2),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_POTION_SHOP_ITEM_4]                     = ItemLocation::Base(0x31, 0x33, "MK Potion Shop Item 4",                             MARKET_POTION_SHOP_ITEM_4,   BUY_FAIRYS_SPIRIT,         {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x31, 3),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_POTION_SHOP_ITEM_5]                     = ItemLocation::Base(0x31, 0x34, "MK Potion Shop Item 5",                             MARKET_POTION_SHOP_ITEM_5,   BUY_DEKU_NUT_5,            {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x31, 4),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_POTION_SHOP_ITEM_6]                     = ItemLocation::Base(0x31, 0x35, "MK Potion Shop Item 6",                             MARKET_POTION_SHOP_ITEM_6,   BUY_BOTTLE_BUG,            {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x31, 5),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_POTION_SHOP_ITEM_7]                     = ItemLocation::Base(0x31, 0x36, "MK Potion Shop Item 7",                             MARKET_POTION_SHOP_ITEM_7,   BUY_POE,                   {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x31, 6),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_POTION_SHOP_ITEM_8]                     = ItemLocation::Base(0x31, 0x37, "MK Potion Shop Item 8",                             MARKET_POTION_SHOP_ITEM_8,   BUY_FISH,                  {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x31, 7),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);

    locationTable[MARKET_BAZAAR_ITEM_1]                          = ItemLocation::Base(0x2C, 0x30, "MK Bazaar Item 1",                                  MARKET_BAZAAR_ITEM_1,        BUY_HYLIAN_SHIELD,         {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x2C, 0),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_BAZAAR_ITEM_2]                          = ItemLocation::Base(0x2C, 0x31, "MK Bazaar Item 2",                                  MARKET_BAZAAR_ITEM_2,        BUY_BOMBS_535,             {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x2C, 1),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_BAZAAR_ITEM_3]                          = ItemLocation::Base(0x2C, 0x32, "MK Bazaar Item 3",                                  MARKET_BAZAAR_ITEM_3,        BUY_DEKU_NUT_5,            {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x2C, 2),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_BAZAAR_ITEM_4]                          = ItemLocation::Base(0x2C, 0x33, "MK Bazaar Item 4",                                  MARKET_BAZAAR_ITEM_4,        BUY_HEART,                 {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x2C, 3),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_BAZAAR_ITEM_5]                          = ItemLocation::Base(0x2C, 0x34, "MK Bazaar Item 5",                                  MARKET_BAZAAR_ITEM_5,        BUY_ARROWS_10,             {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x2C, 4),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_BAZAAR_ITEM_6]                          = ItemLocation::Base(0x2C, 0x35, "MK Bazaar Item 6",                                  MARKET_BAZAAR_ITEM_6,        BUY_ARROWS_50,             {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x2C, 5),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_BAZAAR_ITEM_7]                          = ItemLocation::Base(0x2C, 0x36, "MK Bazaar Item 7",                                  MARKET_BAZAAR_ITEM_7,        BUY_DEKU_STICK_1,          {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x2C, 6),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    locationTable[MARKET_BAZAAR_ITEM_8]                          = ItemLocation::Base(0x2C, 0x37, "MK Bazaar Item 8",                                  MARKET_BAZAAR_ITEM_8,        BUY_ARROWS_30,             {Category::cInnerMarket, Category::cMarket, Category::cShop},                                                     SpoilerCollectionCheck::ShopItem(0x2C, 7),               SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);

    locationTable[KAK_BAZAAR_ITEM_1]                             = ItemLocation::Base(0x2C, 0x38, "Kak Bazaar Item 1",                                 KAK_BAZAAR_ITEM_1,           BUY_HYLIAN_SHIELD,         {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x33, 0),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[KAK_BAZAAR_ITEM_2]                             = ItemLocation::Base(0x2C, 0x39, "Kak Bazaar Item 2",                                 KAK_BAZAAR_ITEM_2,           BUY_BOMBS_535,             {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x33, 1),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[KAK_BAZAAR_ITEM_3]                             = ItemLocation::Base(0x2C, 0x3A, "Kak Bazaar Item 3",                                 KAK_BAZAAR_ITEM_3,           BUY_DEKU_NUT_5,            {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x33, 2),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[KAK_BAZAAR_ITEM_4]                             = ItemLocation::Base(0x2C, 0x3B, "Kak Bazaar Item 4",                                 KAK_BAZAAR_ITEM_4,           BUY_HEART,                 {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x33, 3),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[KAK_BAZAAR_ITEM_5]                             = ItemLocation::Base(0x2C, 0x3C, "Kak Bazaar Item 5",                                 KAK_BAZAAR_ITEM_5,           BUY_ARROWS_10,             {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x33, 4),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[KAK_BAZAAR_ITEM_6]                             = ItemLocation::Base(0x2C, 0x3D, "Kak Bazaar Item 6",                                 KAK_BAZAAR_ITEM_6,           BUY_ARROWS_50,             {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x33, 5),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[KAK_BAZAAR_ITEM_7]                             = ItemLocation::Base(0x2C, 0x3E, "Kak Bazaar Item 7",                                 KAK_BAZAAR_ITEM_7,           BUY_DEKU_STICK_1,          {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x33, 6),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    locationTable[KAK_BAZAAR_ITEM_8]                             = ItemLocation::Base(0x2C, 0x3F, "Kak Bazaar Item 8",                                 KAK_BAZAAR_ITEM_8,           BUY_ARROWS_30,             {Category::cKakarikoVillage, Category::cKakariko, Category::cShop},                                               SpoilerCollectionCheck::ShopItem(0x33, 7),               SpoilerCollectionCheckGroup::GROUP_KAKARIKO);

    locationTable[ZD_SHOP_ITEM_1]                                = ItemLocation::Base(0x2F, 0x30, "ZD Shop Item 1",                                    ZD_SHOP_ITEM_1,              BUY_ZORA_TUNIC,            {Category::cZorasDomain, Category::cShop},                                                                        SpoilerCollectionCheck::ShopItem(0x2F, 0),               SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    locationTable[ZD_SHOP_ITEM_2]                                = ItemLocation::Base(0x2F, 0x31, "ZD Shop Item 2",                                    ZD_SHOP_ITEM_2,              BUY_ARROWS_10,             {Category::cZorasDomain, Category::cShop},                                                                        SpoilerCollectionCheck::ShopItem(0x2F, 1),               SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    locationTable[ZD_SHOP_ITEM_3]                                = ItemLocation::Base(0x2F, 0x32, "ZD Shop Item 3",                                    ZD_SHOP_ITEM_3,              BUY_HEART,                 {Category::cZorasDomain, Category::cShop},                                                                        SpoilerCollectionCheck::ShopItem(0x2F, 2),               SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    locationTable[ZD_SHOP_ITEM_4]                                = ItemLocation::Base(0x2F, 0x33, "ZD Shop Item 4",                                    ZD_SHOP_ITEM_4,              BUY_ARROWS_30,             {Category::cZorasDomain, Category::cShop},                                                                        SpoilerCollectionCheck::ShopItem(0x2F, 3),               SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    locationTable[ZD_SHOP_ITEM_5]                                = ItemLocation::Base(0x2F, 0x34, "ZD Shop Item 5",                                    ZD_SHOP_ITEM_5,              BUY_DEKU_NUT_5,            {Category::cZorasDomain, Category::cShop},                                                                        SpoilerCollectionCheck::ShopItem(0x2F, 4),               SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    locationTable[ZD_SHOP_ITEM_6]                                = ItemLocation::Base(0x2F, 0x35, "ZD Shop Item 6",                                    ZD_SHOP_ITEM_6,              BUY_ARROWS_50,             {Category::cZorasDomain, Category::cShop},                                                                        SpoilerCollectionCheck::ShopItem(0x2F, 5),               SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    locationTable[ZD_SHOP_ITEM_7]                                = ItemLocation::Base(0x2F, 0x36, "ZD Shop Item 7",                                    ZD_SHOP_ITEM_7,              BUY_FISH,                  {Category::cZorasDomain, Category::cShop},                                                                        SpoilerCollectionCheck::ShopItem(0x2F, 6),               SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    locationTable[ZD_SHOP_ITEM_8]                                = ItemLocation::Base(0x2F, 0x37, "ZD Shop Item 8",                                    ZD_SHOP_ITEM_8,              BUY_RED_POTION_50,         {Category::cZorasDomain, Category::cShop},                                                                        SpoilerCollectionCheck::ShopItem(0x2F, 7),               SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);

    locationTable[GC_SHOP_ITEM_1]                                = ItemLocation::Base(0x2E, 0x30, "GC Shop Item 1",                                    GC_SHOP_ITEM_1,              BUY_BOMBS_525,             {Category::cGoronCity, Category::cShop},                                                                          SpoilerCollectionCheck::ShopItem(0x2E, 0),               SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    locationTable[GC_SHOP_ITEM_2]                                = ItemLocation::Base(0x2E, 0x31, "GC Shop Item 2",                                    GC_SHOP_ITEM_2,              BUY_BOMBS_10,              {Category::cGoronCity, Category::cShop},                                                                          SpoilerCollectionCheck::ShopItem(0x2E, 1),               SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    locationTable[GC_SHOP_ITEM_3]                                = ItemLocation::Base(0x2E, 0x32, "GC Shop Item 3",                                    GC_SHOP_ITEM_3,              BUY_BOMBS_20,              {Category::cGoronCity, Category::cShop},                                                                          SpoilerCollectionCheck::ShopItem(0x2E, 2),               SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    locationTable[GC_SHOP_ITEM_4]                                = ItemLocation::Base(0x2E, 0x33, "GC Shop Item 4",                                    GC_SHOP_ITEM_4,              BUY_BOMBS_30,              {Category::cGoronCity, Category::cShop},                                                                          SpoilerCollectionCheck::ShopItem(0x2E, 3),               SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    locationTable[GC_SHOP_ITEM_5]                                = ItemLocation::Base(0x2E, 0x34, "GC Shop Item 5",                                    GC_SHOP_ITEM_5,              BUY_GORON_TUNIC,           {Category::cGoronCity, Category::cShop},                                                                          SpoilerCollectionCheck::ShopItem(0x2E, 4),               SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    locationTable[GC_SHOP_ITEM_6]                                = ItemLocation::Base(0x2E, 0x35, "GC Shop Item 6",                                    GC_SHOP_ITEM_6,              BUY_HEART,                 {Category::cGoronCity, Category::cShop},                                                                          SpoilerCollectionCheck::ShopItem(0x2E, 5),               SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    locationTable[GC_SHOP_ITEM_7]                                = ItemLocation::Base(0x2E, 0x36, "GC Shop Item 7",                                    GC_SHOP_ITEM_7,              BUY_RED_POTION_40,         {Category::cGoronCity, Category::cShop},                                                                          SpoilerCollectionCheck::ShopItem(0x2E, 6),               SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    locationTable[GC_SHOP_ITEM_8]                                = ItemLocation::Base(0x2E, 0x37, "GC Shop Item 8",                                    GC_SHOP_ITEM_8,              BUY_HEART,                 {Category::cGoronCity, Category::cShop},                                                                          SpoilerCollectionCheck::ShopItem(0x2E, 7),               SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
*/
    /*-------------------------------
          --- GOSSIP STONES ---
      -------------------------------*/
    // These are not actual locations, but are filler spots used for hint reachability. - OoT Randomizer
    //                                                                                        flag + 0x400 = message ID
/*TODO -- HINTS EXAMPLES FROM OOT3D BELOW
    locationTable[DMC_GOSSIP_STONE]                              = ItemLocation::HintStone(0x00, 0x05, "DMC Gossip Stone",                            {});
    locationTable[DMT_GOSSIP_STONE]                              = ItemLocation::HintStone(0x00, 0x04, "DMT Gossip Stone",                            {});
    locationTable[COLOSSUS_GOSSIP_STONE]                         = ItemLocation::HintStone(0x00, 0x1A, "Colossus Gossip Stone",                       {});
    locationTable[DODONGOS_CAVERN_GOSSIP_STONE]                  = ItemLocation::HintStone(0x00, 0x14, "Dodongo's Cavern Gossip Stone",               {});
    locationTable[GV_GOSSIP_STONE]                               = ItemLocation::HintStone(0x00, 0x11, "GV Gossip Stone",                             {});
    locationTable[GC_MAZE_GOSSIP_STONE]                          = ItemLocation::HintStone(0x00, 0x15, "GC Maze Gossip Stone",                        {});
    locationTable[GC_MEDIGORON_GOSSIP_STONE]                     = ItemLocation::HintStone(0x00, 0x19, "GC Medigoron Gossip Stone",                   {});
    locationTable[GRAVEYARD_GOSSIP_STONE]                        = ItemLocation::HintStone(0x00, 0x0A, "GY Gossip Stone",                             {});
    locationTable[HC_MALON_GOSSIP_STONE]                         = ItemLocation::HintStone(0x00, 0x12, "HC Malon Gossip Stone",                       {});
    locationTable[HC_ROCK_WALL_GOSSIP_STONE]                     = ItemLocation::HintStone(0x00, 0x0B, "HC Rock Wall Gossip Stone",                   {});
    locationTable[HC_STORMS_GROTTO_GOSSIP_STONE]                 = ItemLocation::HintStone(0x00, 0x13, "HC Storms Grotto Gossip Stone",               {});
    locationTable[KF_DEKU_TREE_GOSSIP_STONE_LEFT]                = ItemLocation::HintStone(0x00, 0x1F, "KF Deku Tree Left Gossip Stone",              {});
    locationTable[KF_DEKU_TREE_GOSSIP_STONE_RIGHT]               = ItemLocation::HintStone(0x00, 0x20, "KF Deku Tree Right Gossip Stone",             {});
    locationTable[KF_GOSSIP_STONE]                               = ItemLocation::HintStone(0x00, 0x1E, "KF Gossip Stone",                             {});
    locationTable[LH_LAB_GOSSIP_STONE]                           = ItemLocation::HintStone(0x00, 0x03, "LH Lab Gossip Stone",                         {});
    locationTable[LH_GOSSIP_STONE_SOUTHEAST]                     = ItemLocation::HintStone(0x00, 0x0F, "LH Southeast Gossip Stone",                   {});
    locationTable[LH_GOSSIP_STONE_SOUTHWEST]                     = ItemLocation::HintStone(0x00, 0x08, "LH Southwest Gossip Stone",                   {});
    locationTable[LW_GOSSIP_STONE]                               = ItemLocation::HintStone(0x00, 0x1D, "LW Gossip Stone",                             {});
    locationTable[SFM_MAZE_GOSSIP_STONE_LOWER]                   = ItemLocation::HintStone(0x00, 0x16, "SFM Maze Lower Gossip Stone",                 {});
    locationTable[SFM_MAZE_GOSSIP_STONE_UPPER]                   = ItemLocation::HintStone(0x00, 0x17, "SFM Maze Upper Gossip Stone",                 {});
    locationTable[SFM_SARIA_GOSSIP_STONE]                        = ItemLocation::HintStone(0x00, 0x1C, "SFM Saria Gossip Stone",                      {});
    locationTable[TOT_GOSSIP_STONE_LEFT]                         = ItemLocation::HintStone(0x00, 0x06, "ToT Left Gossip Stone",                       {});
    locationTable[TOT_GOSSIP_STONE_RIGHT]                        = ItemLocation::HintStone(0x00, 0x07, "ToT Left Center Gossip Stone",                {});
    locationTable[TOT_GOSSIP_STONE_RIGHT_CENTER]                 = ItemLocation::HintStone(0x00, 0x10, "ToT Right Center Gossip Stone",               {});
    locationTable[TOT_GOSSIP_STONE_LEFT_CENTER]                  = ItemLocation::HintStone(0x00, 0x0E, "ToT Right Gossip Stone",                      {});
    locationTable[ZD_GOSSIP_STONE]                               = ItemLocation::HintStone(0x00, 0x09, "ZD Gossip Stone",                             {});
    locationTable[ZF_FAIRY_GOSSIP_STONE]                         = ItemLocation::HintStone(0x00, 0x01, "Fairy Gossip Stone",                          {});
    locationTable[ZF_JABU_GOSSIP_STONE]                          = ItemLocation::HintStone(0x00, 0x02, "Jabu Gossip Stone",                           {});
    locationTable[ZR_NEAR_GROTTOS_GOSSIP_STONE]                  = ItemLocation::HintStone(0x00, 0x0D, "ZR Near Grottos Gossip Stone",                {});
    locationTable[ZR_NEAR_DOMAIN_GOSSIP_STONE]                   = ItemLocation::HintStone(0x00, 0x0C, "ZR Near Domain Gossip Stone",                 {});
    locationTable[HF_COW_GROTTO_GOSSIP_STONE]                    = ItemLocation::HintStone(0x00, 0x1B, "HF Cow Grotto Gossip Stone",                  {});

    locationTable[HF_NEAR_MARKET_GROTTO_GOSSIP_STONE]            = ItemLocation::HintStone(0x00, 0x30, "HF Near Market Gossip Stone",                 {});
    locationTable[HF_SOUTHEAST_GROTTO_GOSSIP_STONE]              = ItemLocation::HintStone(0x00, 0x32, "HF Southeast Gossip Stone",                   {});
    locationTable[HF_OPEN_GROTTO_GOSSIP_STONE]                   = ItemLocation::HintStone(0x00, 0x33, "HF Open Grotto Gossip Stone",                 {});
    locationTable[KAK_OPEN_GROTTO_GOSSIP_STONE]                  = ItemLocation::HintStone(0x00, 0x38, "Kak Open Grotto Gossip Stone",                {});
    locationTable[ZR_OPEN_GROTTO_GOSSIP_STONE]                   = ItemLocation::HintStone(0x00, 0x39, "ZR Open Grotto Gossip Stone",                 {});
    locationTable[KF_STORMS_GROTTO_GOSSIP_STONE]                 = ItemLocation::HintStone(0x00, 0x3C, "KF Storms Gossip Stone",                      {});
    locationTable[LW_NEAR_SHORTCUTS_GROTTO_GOSSIP_STONE]         = ItemLocation::HintStone(0x00, 0x34, "LW Near Shortcuts Gossip Stone",              {});
    locationTable[DMT_STORMS_GROTTO_GOSSIP_STONE]                = ItemLocation::HintStone(0x00, 0x37, "DMT Storms Grotto Gossip Stone",              {});
    locationTable[DMC_UPPER_GROTTO_GOSSIP_STONE]                 = ItemLocation::HintStone(0x00, 0x3A, "DMC Upper Grotto Gossip Stone",               {});

    locationTable[GANONDORF_HINT]                                = ItemLocation::OtherHint(0x00, 0x00, "Ganondorf Hint",                              {});
*/
}

/* TODO-- SHOP VECTORS FOR ASSIGNING ITEMS TO SHOP PLACEMENTS
std::vector<LocationKey> KF_ShopLocations = {
  KF_SHOP_ITEM_1,
  KF_SHOP_ITEM_2,
  KF_SHOP_ITEM_3,
  KF_SHOP_ITEM_4,
  KF_SHOP_ITEM_5,
  KF_SHOP_ITEM_6,
  KF_SHOP_ITEM_7,
  KF_SHOP_ITEM_8,
};
std::vector<LocationKey> Kak_PotionShopLocations = {
  KAK_POTION_SHOP_ITEM_1,
  KAK_POTION_SHOP_ITEM_2,
  KAK_POTION_SHOP_ITEM_3,
  KAK_POTION_SHOP_ITEM_4,
  KAK_POTION_SHOP_ITEM_5,
  KAK_POTION_SHOP_ITEM_6,
  KAK_POTION_SHOP_ITEM_7,
  KAK_POTION_SHOP_ITEM_8,
};
std::vector<LocationKey> MK_BombchuShopLocations = {
  MARKET_BOMBCHU_SHOP_ITEM_1,
  MARKET_BOMBCHU_SHOP_ITEM_2,
  MARKET_BOMBCHU_SHOP_ITEM_3,
  MARKET_BOMBCHU_SHOP_ITEM_4,
  MARKET_BOMBCHU_SHOP_ITEM_5,
  MARKET_BOMBCHU_SHOP_ITEM_6,
  MARKET_BOMBCHU_SHOP_ITEM_7,
  MARKET_BOMBCHU_SHOP_ITEM_8,
};
std::vector<LocationKey> MK_PotionShopLocations = {
  MARKET_POTION_SHOP_ITEM_1,
  MARKET_POTION_SHOP_ITEM_2,
  MARKET_POTION_SHOP_ITEM_3,
  MARKET_POTION_SHOP_ITEM_4,
  MARKET_POTION_SHOP_ITEM_5,
  MARKET_POTION_SHOP_ITEM_6,
  MARKET_POTION_SHOP_ITEM_7,
  MARKET_POTION_SHOP_ITEM_8,
};
std::vector<LocationKey> MK_BazaarLocations = {
  MARKET_BAZAAR_ITEM_1,
  MARKET_BAZAAR_ITEM_2,
  MARKET_BAZAAR_ITEM_3,
  MARKET_BAZAAR_ITEM_4,
  MARKET_BAZAAR_ITEM_5,
  MARKET_BAZAAR_ITEM_6,
  MARKET_BAZAAR_ITEM_7,
  MARKET_BAZAAR_ITEM_8,
};
std::vector<LocationKey> Kak_BazaarLocations = {
  KAK_BAZAAR_ITEM_1,
  KAK_BAZAAR_ITEM_2,
  KAK_BAZAAR_ITEM_3,
  KAK_BAZAAR_ITEM_4,
  KAK_BAZAAR_ITEM_5,
  KAK_BAZAAR_ITEM_6,
  KAK_BAZAAR_ITEM_7,
  KAK_BAZAAR_ITEM_8,
};
std::vector<LocationKey> ZD_ShopLocations = {
  ZD_SHOP_ITEM_1,
  ZD_SHOP_ITEM_2,
  ZD_SHOP_ITEM_3,
  ZD_SHOP_ITEM_4,
  ZD_SHOP_ITEM_5,
  ZD_SHOP_ITEM_6,
  ZD_SHOP_ITEM_7,
  ZD_SHOP_ITEM_8,
};
std::vector<LocationKey> GC_ShopLocations = {
  GC_SHOP_ITEM_1,
  GC_SHOP_ITEM_2,
  GC_SHOP_ITEM_3,
  GC_SHOP_ITEM_4,
  GC_SHOP_ITEM_5,
  GC_SHOP_ITEM_6,
  GC_SHOP_ITEM_7,
  GC_SHOP_ITEM_8,
};
//List of shop location lists, used for shop shuffle
std::vector<std::vector<LocationKey>> ShopLocationLists = {
  KF_ShopLocations,
  Kak_PotionShopLocations,
  MK_BombchuShopLocations,
  MK_PotionShopLocations,
  MK_BazaarLocations,
  Kak_BazaarLocations,
  ZD_ShopLocations,
  GC_ShopLocations,
};
*/

/*TODO--GOSSIP STONE LOCATION VECTOR FOR ASSIGNING HINTS TO STONES
//List of gossip stone locations for hints
std::vector<LocationKey> gossipStoneLocations = {
  DMC_GOSSIP_STONE,
  DMT_GOSSIP_STONE,
  COLOSSUS_GOSSIP_STONE,
  DODONGOS_CAVERN_GOSSIP_STONE,
  GV_GOSSIP_STONE,
  GC_MAZE_GOSSIP_STONE,
  GC_MEDIGORON_GOSSIP_STONE,
  GRAVEYARD_GOSSIP_STONE,
  HC_MALON_GOSSIP_STONE,
  HC_ROCK_WALL_GOSSIP_STONE,
  HC_STORMS_GROTTO_GOSSIP_STONE,
  KF_DEKU_TREE_GOSSIP_STONE_LEFT,
  KF_DEKU_TREE_GOSSIP_STONE_RIGHT,
  KF_GOSSIP_STONE,
  LH_LAB_GOSSIP_STONE,
  LH_GOSSIP_STONE_SOUTHEAST,
  LH_GOSSIP_STONE_SOUTHWEST,
  LW_GOSSIP_STONE,
  SFM_MAZE_GOSSIP_STONE_LOWER,
  SFM_MAZE_GOSSIP_STONE_UPPER,
  SFM_SARIA_GOSSIP_STONE,
  TOT_GOSSIP_STONE_LEFT,
  TOT_GOSSIP_STONE_RIGHT,
  TOT_GOSSIP_STONE_RIGHT_CENTER,
  TOT_GOSSIP_STONE_LEFT_CENTER,
  ZD_GOSSIP_STONE,
  ZF_FAIRY_GOSSIP_STONE,
  ZF_JABU_GOSSIP_STONE,
  ZR_NEAR_GROTTOS_GOSSIP_STONE,
  ZR_NEAR_DOMAIN_GOSSIP_STONE,
  HF_COW_GROTTO_GOSSIP_STONE,
  HF_NEAR_MARKET_GROTTO_GOSSIP_STONE,
  HF_SOUTHEAST_GROTTO_GOSSIP_STONE,
  HF_OPEN_GROTTO_GOSSIP_STONE,
  KAK_OPEN_GROTTO_GOSSIP_STONE,
  ZR_OPEN_GROTTO_GOSSIP_STONE,
  KF_STORMS_GROTTO_GOSSIP_STONE,
  LW_NEAR_SHORTCUTS_GROTTO_GOSSIP_STONE,
  DMT_STORMS_GROTTO_GOSSIP_STONE,
  DMC_UPPER_GROTTO_GOSSIP_STONE,
};
*/
std::vector<LocationKey> dungeonRewardLocations = {
  //Bosses
  WOODFALL_TEMPLE_ODOLWAS_REMAINS,
  SNOWHEAD_TEMPLE_GOHT_REMAINS,
  GBT_GYORGS_REMAINS,
  STONE_TOWER_TEMPLE_TWINMOLDS_REMAINS,
  LINKS_POCKET,
};
std:vector<LocationKey> overworldLocations = {
	//Deku Palace
	DEKU_PALACE_BEAN_DADDY,
	DEKU_PALACE_WEST_GARDEN,
	DEKU_PALACE_BUTLER_RACE,
	DEKU_PALACE_BEAN_GROTTO,
	
	//East Clock Town
	E_CLOCK_TOWN_AROMA_IN_BAR,
	E_CLOCK_TOWN_ARCHERY_1,
	E_CLOCK_TOWN_MAYOR,
	E_CLOCK_TOWN_ARCHERY_2,
	E_CLOCK_TOWN_HONEY_DARLING_3DAYS,
	E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON,
	E_CLOCK_TOWN_POSTMAN_FREEDOM,
	E_CLOCK_TOWN_GORMAN,
	E_CLOCK_TOWN_AROMA_IN_OFFICE,
	E_CLOCK_TOWN_BOMBERS_HIDEOUT_CHEST,
	E_CLOCK_TOWN_CHEST,
	E_CLOCK_TOWN_MILK_BAR_CHATEAU,
	E_CLOCK_TOWN_MILK_BAR_MILK,
	E_CLOCK_TOWN_GORMAN_QUEST,
	//E_CLOCK_TOWN_HONEY_DARLING_ANY_DAY,
	//E_CLOCK_TOWN_TREASURE_CHEST_GAME_HUMAN
	//E_CLOCK_TOWN_TREASURE_CHEST_GAME_ZORA
	//E_CLOCK_TOWN_TREASURE_CHEST_GAME_DEKU

	//Goron Village
	GORON_VILLAGE_POWDER_KEG_CHALLENGE,
	GORON_VILLAGE_BIGGEST_BOMB_BAG_BUY,
	GORON_VILLAGE_LENS_OF_TRUTH_CHEST,
	GORON_VILLAGE_MOUNTAIN_TITLE_DEED,
	GORON_VILLAGE_PIECE_OF_HEART,
	GORON_VILLAGE_GORON_LULLABY,
	GORON_VILLAGE_LENS_CAVE_INVISIBLE_CHEST,
	GORON_VILLAGE_LENS_CAVE_ROCK_CHEST,

	//Great Bay Coast
	GBC_OCEAN_SPIDER_DAY1,
	GBC_OCEAN_SPIDER_DAY2,
	GBC_OCEAN_SPIDER_DAY3,
	GBC_FISHERMAN_GAME,
	GBC_OCEAN_SPIDER_CHEST,
	GBC_LAB_FISH,
	GBC_LEDGE,
	GBC_MIKAU,
	GBC_BABY_ZORAS,
	GBC_STONE_TOWER_BUY,
	GBC_GROTTO,
	GBC_FISHERMAN_PHOTO,

	//Ikana Canyon
	IKANA_CANYON_GREAT_FAIRY,
	IKANA_CANYON_POE_HUT,
	IKANA_CANYON_LEDGE,
	IKANA_CANYON_PAMELAS_FATHER,
	IKANA_CANYON_SECRET_SHRINE_GROTTO,
	IKANA_CANYON_SCRUB_TRADE,
	IKANA_CANYON_SCRUB_PURCHASE,

	//Ikana Graveyard
	IKANA_GRAVEYARD_DAMPE_DIGGING,
	IKANA_GRAVEYARD_IRON_KNUCKLE_CHEST,
	IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST,
	IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET,
	IKANA_GRAVEYARD_DAY_ONE_GRAVE_BATS,
	IKANA_GRAVEYARD_GROTTO,

	//Laundry Pool
	LAUNDRY_POOL_KAFEI
	LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE,
	LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO,
	LAUNDRY_POOL_GURU_GURU,
	LAUNDRY_POOL_SF,

	//Milk Road
	MILK_ROAD_GORMAN_RACE,
	MILK_ROAD_ROMANI_RANCH_MAP_BUY,
	MILK_ROAD_GREAT_BAY_MAP_BUY,
	//MILK_ROAD_GORMAN_MILK_BUY,

	//Mountain Village
	MOUNTAIN_VILLAGE_SMITH_DAY_ONE,
	MOUNTAIN_VILLAGE_SMITH_DAY_TWO,
	MOUNTAIN_VILLAGE_FROG_CHOIR,
	MOUNTAIN_VILLAGE_DARMANI,
	MOUNTAIN_VILLAGE_HUNGRY_GORON,
	MOUNTAIN_VILLAGE_WATERFALL_CHEST,
	MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO,

	//N Clock Town
	N_CLOCK_TOWN_GREAT_FAIRY_DEKU,
	N_CLOCK_TOWN_BOMBERS_HIDE_SEEK,
	N_CLOCK_TOWN_KEATON_QUIZ,
	N_CLOCK_TOWN_DEKU_PLAYGROUND_3DAYS,
	N_CLOCK_TOWN_TREE,
	N_CLOCK_TOWN_OLD_LADY,
	N_CLOCK_TOWN_GREAT_FAIRY_HUMAN,
	N_CLOCK_TOWN_MAP_PURCHASE,
	//N_CLOCK_TOWN_DEKU_PLAYGROUND_ADAY

	//Road to Snowhead
	ROAD_TO_SNOWHEAD_PILLAR,
	ROAD_TO_SNOWHEAD_GROTTO,

	//Pinnacle Rock
	PINNACLE_ROCK_SEAHORSES,
	PINNACLE_ROCK_UPPER_CHEST,
	PINNACLE_ROCK_LOWER_CHEST,

	//Road to Ikana
	ROAD_TO_IKANA_INVISIBLE_SOLDIER,
	ROAD_TO_IKANA_PILLAR_CHEST,
	ROAD_TO_IKANA_GROTTO,

	//Road to Southern Swamp
	ROAD_TO_SS_ARCHERY_1,
	ROAD_TO_SS_ARCHERY_2,
	ROAD_TO_SS_TREE,
	ROAD_TO_SS_WOODFALL_MAP_BUY,
	ROAD_TO_SS_SNOWHEAD_MAP_BUY,
	ROAD_TO_SS_GROTTO,

	//Romani Ranch
	ROMANI_RANCH_ALIEN_DEFENSE,
	ROMANI_RANCH_DOG_RACE,
	ROMANI_RANCH_GROG,
	ROMANI_RANCH_CREMIA_ESCORT,
	ROMANI_RANCH_ROMANIS_GAME,
	ROMANI_RANCH_DOGGY_RACETRACK_ROOF_CHEST,

	//S Clock Town
	S_CLOCK_TOWN_SCRUB_TRADE,
	S_CLOCK_TOWN_POSTBOX,
	S_CLOCK_TOWN_CLOCK_TOWER_ENTRANCE,
	S_CLOCK_TOWN_STRAW_ROOF_CHEST,
	S_CLOCK_TOWN_FINAL_DAY_CHEST,
	S_CLOCK_TOWN_BANK_REWARD_1,
	S_CLOCK_TOWN_BANK_REWARD_2,
	S_CLOCK_TOWN_BANK_REWARD_3,

	//Snowhead
	SNOWHEAD_GREAT_FAIRY,

	//Southern Swamp
	SOUTHERN_SWAMP_KOUME,
	SOUTHERN_SWAMP_KOTAKE,
	SOUTHERN_SWAMP_SCRUB_TRADE,
	SOUTHERN_SWAMP_PICTOGRAPH_WINNER,
	SOUTHERN_SWAMP_BOAT_ARCHERY,
	SOUTHERN_SWAMP_TOURIST_ROOF,
	SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD,
	SOUTHERN_SWAMP_MUSIC_STATUE,
	SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO,
	SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO,
	SOUTHERN_SWAMP_KOTAKE_MUSHROOM_SALE,
	//SOUTHERN_SWAMP_PICTOGRAPH_STANDARD,
	//SOUTHERN_SWAMP_PICTOGRAPH_GOOD,
	SOUTHERN_SWAMP_SCRUB_PURCHASE,

	//Stock Pot Inn
	STOCKPOTINN_RESERVATION,
	STOCKPOTINN_MIDNIGHT_MEETING,
	STOCKPOTINN_TOILET_HAND,
	STOCKPOTINN_GRANDMA_SHORT_STORY,
	STOCKPOTINN_GRANDMA_LONG_STORY,
	STOCKPOTINN_ANJU_AND_KAFEI,
	STOCKPOTINN_STAFF_ROOM_CHEST,
	STOCKPOTINN_GUEST_ROOM_CHEST,

	//Stone Tower
	STONE_TOWER_INVERTED_RIGHT_CHEST,
	STONE_TOWER_INVERTED_CENTER_CHEST,
	STONE_TOWER_INVERTED_LEFT_CHEST,

	//Termina Field
	TERMINA_FIELD_MOONS_TEAR,
	TERMINA_FIELD_GOSSIP_STONES,
	TERMINA_FIELD_BUSINESS_SCRUB,
	TERMINA_FIELD_PEAHAT_GROTTO,
	TERMINA_FIELD_DODONGO_GROTTO,
	TERMINA_FIELD_BIO_BABA_GROTTO,
	TERMINA_FIELD_KAMARO,
	TERMINA_FIELD_PILLAR_GROTTO,
	TERMINA_FIELD_GRASS_GROTTO,
	TERMINA_FIELD_UNDERWATER_CHEST,
	TERMINA_FIELD_GRASS_CHEST,
	TERMINA_FIELD_STUMP_CHEST,

	//Twin Islands
	TWIN_ISLANDS_HOT_SPRING_WATER_GROTTO,
	TWIN_ISLANDS_GORON_RACE,
	TWIN_ISLANDS_GORON_RACETRACK_GROTTO,
	TWIN_ISLANDS_UNDERWATER_RAMP_CHEST,
	TWIN_ISLANDS_CAVE_CHEST,

	//W Clock Town
	W_CLOCK_TOWN_BOMB_BAG_BUY,
	W_CLOCK_TOWN_BIG_BOMB_BAG_BUY,
	W_CLOCK_TOWN_POSTMANS_GAME,
	W_CLOCK_TOWN_ROSA_SISTERS,
	W_CLOCK_TOWN_SWORDSMANS_SCHOOL,
	W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY,
	W_CLOCK_TOWN_LOTTERY,

	//Woodfall
	WOODFALL_BRIDGE_CHEST,
	WOODFALL_BEHIND_OWL_CHEST,
	WOODFALL_ENTRANCE_TO_WOODFALL_CHEST,
	WOODFALL_GREAT_FAIRY,

	//Zora Cape
	ZORA_CAPE_GREAT_FAIRY,
	ZORA_CAPE_BEAVER_RACE_1,
	ZORA_CAPE_BEAVER_RACE_2,
	ZORA_CAPE_LIKE_LIKE,
	ZORA_CAPE_LEDGE_NO_TREE,
	ZORA_CAPE_LEDGE_WITH_TREE,
	ZORA_CAPE_GROTTO,
	ZORA_CAPE_UNDERWATER_CHEST,

	//Zora Hall
	ZORA_HALL_SCRUB_TRADE,
	ZORA_HALL_EVAN,
	ZORA_HALL_LULU_ROOM_LEDGE,
	ZORA_HALL_SCRUB_BUY,
	ZORA_HALL_STAGE_LIGHTS,
	//ZORA_HALL_BAD_PHOTO_LULU,
	//ZORA_HALL_GOOD_PHOTO_LULU,

};

ItemLocation* Location(LocationKey locKey) {
    return &(locationTable[locKey]);
}

std::vector<LocationKey> allLocations = {};
std::vector<LocationKey> everyPossibleLocation = {};

//set of overrides to write to the patch
std::set<ItemOverride, ItemOverride_Compare> overrides = {};

std::vector<std::vector<LocationKey>> playthroughLocations;
std::vector<LocationKey> wothLocations;
bool playthroughBeatable = false;
bool allLocationsReachable = false;
bool showItemProgress = false;

u16 itemsPlaced = 0;

void AddLocation(LocationKey loc, std::vector<LocationKey>* destination = &allLocations) {
  destination->push_back(loc);
}

template <typename Container>
void AddLocations(const Container& locations, std::vector<LocationKey>* destination = &allLocations) {
  destination->insert(destination->end(), std::cbegin(locations), std::cend(locations));
}

//sort through Vanilla and MQ dungeon locations
void GenerateLocationPool() {

  allLocations.clear();
  AddLocation(LINKS_POCKET);
  AddLocations(overworldLocations);

  for (auto dungeon : Dungeon::dungeonList) {
    AddLocations(dungeon->GetDungeonLocations());
  }
}

void PlaceItemInLocation(LocationKey locKey, ItemKey item, bool applyEffectImmediately /*= false*/) {
  auto loc = Location(locKey);
  PlacementLog_Msg("\n");
  PlacementLog_Msg(ItemTable(item).GetName().GetEnglish());
  PlacementLog_Msg(" placed at ");
  PlacementLog_Msg(loc->GetName());
  PlacementLog_Msg("\n\n");

  if (applyEffectImmediately || Settings::Logic.Is(LOGIC_NONE) || Settings::Logic.Is(LOGIC_VANILLA)) {
    ItemTable(item).ApplyEffect();
  }

  itemsPlaced++;
  if (showItemProgress) {
    double completion = (double) itemsPlaced / (double)(allLocations.size() + dungeonRewardLocations.size());
    printf("\x1b[8;10HPlacing Items.");
    if (completion > 0.25) printf(".");
    if (completion > 0.50) printf(".");
  }

  //If we're placing a non-shop item in a shop location, we want to record it for custom messages
  if (ItemTable(item).GetItemType() != ITEMTYPE_SHOP && loc->IsCategory(Category::cShop)) {
    int index = TransformShopIndex(GetShopIndex(locKey));
    NonShopItems[index].Name = ItemTable(item).GetName();
    NonShopItems[index].Repurchaseable = ItemTable(item).GetItemType() == ITEMTYPE_REFILL || ItemTable(item).GetHintKey() == PROGRESSIVE_BOMBCHUS;
  }

  loc->SetPlacedItem(item);
}

std::vector<LocationKey> GetLocations(const std::vector<LocationKey>& locationPool, Category categoryInclude, Category categoryExclude /*= Category::cNull*/) {
  std::vector<LocationKey> locationsInCategory;
  for (LocationKey locKey : locationPool) {
    if (Location(locKey)->IsCategory(categoryInclude) && !Location(locKey)->IsCategory(categoryExclude)) {
      locationsInCategory.push_back(locKey);
    }
  }
  return locationsInCategory;
}

void LocationReset() {
  for (LocationKey il : allLocations) {
    Location(il)->RemoveFromPool();
  }

  for (LocationKey il : dungeonRewardLocations) {
    Location(il)->RemoveFromPool();
  }

  for (LocationKey il : gossipStoneLocations) {
    Location(il)->RemoveFromPool();
  }

  Location(GANONDORF_HINT)->RemoveFromPool();
}

void ItemReset() {
  for (LocationKey il : allLocations) {
    Location(il)->ResetVariables();
  }

  for (LocationKey il : dungeonRewardLocations) {
    Location(il)->ResetVariables();
  }

  itemsPlaced = 0;
}

void HintReset() {
  for (LocationKey il : gossipStoneLocations) {
    Location(il)->ResetVariables();
  }
}

//Fills everyPossibleLocation and creates an exclusion option for each location.
//everyPossibleLocation is used in the menu to lock/hide excluding locations
void AddExcludedOptions() {
  AddLocations(overworldLocations, &everyPossibleLocation);

  for (auto dungeon : Dungeon::dungeonList) {
    AddLocations(dungeon->GetEveryLocation(), &everyPossibleLocation);
  }

  for (LocationKey il: everyPossibleLocation) {
    Location(il)->AddExcludeOption();
  }
}

void CreateItemOverrides() {
  PlacementLog_Msg("NOW CREATING OVERRIDES\n\n");
  for (LocationKey locKey : allLocations) {
    auto loc = Location(locKey);
    ItemOverride_Value val = ItemTable(loc->GetPlacedItemKey()).Value();
    //If this is an ice trap in a shop, change the name based on what the model will look like
    if (loc->GetPlacedItemKey() == ICE_TRAP && loc->IsCategory(Category::cShop)) {
      NonShopItems[TransformShopIndex(GetShopIndex(locKey))].Name = GetIceTrapName(val.looksLikeItemId);
    }
    overrides.insert({
      .key = loc->Key(),
      .value = val,
    });
    PlacementLog_Msg("\tScene: ");
    PlacementLog_Msg(std::to_string(loc->Key().scene));
    PlacementLog_Msg("\tType: ");
    PlacementLog_Msg(std::to_string(loc->Key().type));
    PlacementLog_Msg("\tFlag:  ");
    PlacementLog_Msg(std::to_string(loc->Key().flag));
    PlacementLog_Msg("\t");
    PlacementLog_Msg(loc->GetName());
    PlacementLog_Msg(": ");
    PlacementLog_Msg(loc->GetPlacedItemName().GetEnglish());
    PlacementLog_Msg("\n");
  }
  PlacementLog_Msg("Overrides Created: ");
  PlacementLog_Msg(std::to_string(overrides.size()));
}
