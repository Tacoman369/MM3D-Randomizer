#pragma once

#include <3ds.h>

using HintKey		= u32;
using ItemKey		= u32;
using LocationKey	= u32;
using AreaKey		= u32;

typedef enum {
NONE, 

//Items
	KOKIRI_SWORD,
	RAZOR_SWORD,
	GILDED_SWORD,
	GREAT_FAIRYS_SWORD,
	HEROS_SHIELD,
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
	MAGIC_BEAN_PACK,
	DOUBLE_DEFENSE,
	OCARINA_OF_TIME,
	PICTOGRAPH_BOX,
	POWDER_KEG,
	KEATON_MASK,
	BUNNY_HOOD,
	GORON_MASK,
	ZORA_MASK,
	DEKU_MASK,
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
	SWAMP_SKULLTULA_TOKEN,
	OCEANSIDE_SKULLTULA_TOKEN,

//Stray Fairies
	CT_STRAY_FAIRY,
	WF_STRAY_FAIRY,
	SH_STRAY_FAIRY,
	GBT_STRAY_FAIRY,
	ST_STRAY_FAIRY,
	
	PROGRESSIVE_SWORD,
	PROGRESSIVE_BOMB_BAG,
	PROGRESSIVE_BOW,
	PROGRESSIVE_WALLET,
	PROGRESSIVE_MAGIC_METER,
	PROGRESSIVE_BOMBCHUS,
	
	EMPTY_BOTTLE,
	BOTTLE_WITH_MILK,
	BOTTLE_WITH_RED_POTION,
	BOTTLE_WITH_GREEN_POTION,
	BOTTLE_WITH_BLUE_POTION,
	BOTTLE_WITH_FAIRY,
	BOTTLE_WITH_FISH,
	CHATEAU_ROMANI,
	BOTTLE_WITH_BUGS,
	BOTTLE_WITH_POE,
	BOTTLE_WITH_BIG_POE,
	HOT_SPRING_WATER,
	SPRING_WATER,
	DEKU_PRINCESS,
	GOLD_DUST,
	ZORA_EGG,
	SEAHORSE,
	
	SONG_OF_TIME,
	SONG_OF_STORMS,
	SONG_OF_HEALING,
	SONG-OF_SOARING,
	SONG_OF_DOUBLE_TIME,
	INVERTED_SONG_OF_TIME,
	EPONAS_SONG,
	SONATA_OF_AWAKENING,
	GORONS_LULLABY,
	NEW_WAVE_BOSSA_NOVA,
	ELEGY_OF_EMPTINESS,
	OATH_TO_ORDER,
	
	MAP,
	WOODFALL_TEMPLE_MAP,
	SNOWHEAD_TEMPLE_MAP,
	GBT_MAP,
	STONE_TOWER_TEMPLE_MAP,
	CLOCK_TOWN_MAP,
	WOODFALL_MAP,
	SNOWHEAD_MAP,
	GREAT_BAY_MAP,
	STONE_TOWER_MAP,
	
	COMPASS,
	WOODFALL_TEMPLE_COMPASS,
	SNOWHEAD_TEMPLE_COMPASS,
	GBT_COMPASS,
	STONE_TOWER_COMPASS,
	
	BOSS_KEY,
	WOODFALL_BOSS_KEY,
	SNOWHEAD_BOSS_KEY,
	GBT_BOSS_KEY,
	STONE_TOWER_TEMPLE_BOSS_KEY,
	
	SMALL_KEY,
	WOODFALL_TEMPLE_SMALL_KEY,
	SNOWHEAD_TEMPLE_SMALL_KEY,
	GBT_SMALL_KEY,
	STONE_TOWER_SMALL_KEY,
	
	ODOLWAS_REMAINS,
	GOHTS_REMAINS,
	GYORGS_REMAINS,
	TWINMOLDS_REMAINS,
	
	RECOVERY_HEART,
    GREEN_RUPEE,
    BLUE_RUPEE,
    RED_RUPEE,
    PURPLE_RUPEE,
	SILVER_RUPEE,
    HUGE_RUPEE,
    PIECE_OF_HEART,
    HEART_CONTAINER,
    ICE_TRAP,
    MILK,

    BOMBS_5,
    BOMBS_10,
    BOMBS_20,
    BOMBCHU_5,
    BOMBCHU_10,
    BOMBCHU_20,
    BOMBCHU_DROP,
    ARROWS_5,
    ARROWS_10,
    ARROWS_30,
    DEKU_NUTS_5,
    DEKU_NUTS_10,
    RED_POTION_REFILL,
    GREEN_POTION_REFILL,
    BLUE_POTION_REFILL,
	
	EPONA,
	HINT,
	
	//shop items
	BUY_DEKU_NUT_5,
    BUY_ARROWS_30,
    BUY_ARROWS_50,
    BUY_BOMBS_525,
    BUY_DEKU_NUT_10,
    BUY_BOMBS_10,
    BUY_FISH,
    BUY_RED_POTION_30,
    BUY_GREEN_POTION,
    BUY_BLUE_POTION,
    BUY_HEART,
    BUY_BOMBCHU_10,
    BUY_BOMBCHU_20,
    BUY_BOMBCHU_5,
    SOLD_OUT,
	BUY_BOTTLE_BUG,
	BUY_POE,
	BUY_FAIRYS_SPIRIT,
	BUY_ARROWS_10,
	BUY_BOMBS_20,
	BUY_BOMBS_30,
	BUY_BOMBS_535,
	BUY_RED_POTION_40,
	BUY_RED_POTION_50,
	
	//ITEMLOCATIONS
	
	//DUNGEON REWARDS
	LINKS_POCKET,
	WOODFALL_TEMPLE_ODOLWAS_REMAINS,
	SNOWHEAD_TEMPLE_GOHT_REMAINS,
	GBT_GYORGS_REMAINS,
	STONE_TOWER_TEMPLE_TWINMOLDS_REMAINS,
	
	//OVERWORLD LOCATIONS
	
	HMS_SONG_OF_HEALING,
	HMS_OCARINA_OF_TIME,
	HMS_DEKU_MASK,
	HMS_BOMBERS_NOTEBOOK,
	HMS_KOKIRI_SWORD,
	HMS_HEROS_SHIELD,

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
	
	//Dungeons
	
	//Woodfall Temple
	WOODFALL_TEMPLE_HEROS_BOW_CHEST,
	WOODFALL_TEMPLE_MAP_CHEST,
	WOODFALL_TEMPLE_COMPASS_CHEST,
	WOODFALL_TEMPLE_BOSS_KEY_CHEST,
	WOODFALL_TEMPLE_SMALL_KEY_CHEST,

	//Snowhead Temple
	SNOWHEAD_TEMPLE_FIRE_ARROW_CHEST,
	SNOWHEAD_TEMPLE_MAP_CHEST,
	SNOWHEAD_TEMPLE_COMPASS_CHEST,
	SNOWHEAD_TEMPLE_BOSS_KEY_CHEST,
	SNOWHEAD_TEMPLE_BLOCK_ROOM_CHEST,
	SNOWHEAD_TEMPLE_ICICLE_ROOM_CHEST,
	SNOWHEAD_TEMPLE_BRIDGE_ROOM_CHEST,

	//Great Bay Temple
	GBT_ICE_ARROW_CHEST,
	GBT_MAP_CHEST,
	GBT_COMPASS_CHEST,
	GBT_BOSS_KEY_CHEST,
	GBT_SMALL_KEY_CHEST,

	//Stone Tower Temple
	STONE_TOWER_TEMPLE_MAP_CHEST,
	STONE_TOWER_TEMPLE_COMPASSS_CHEST,
	STONE_TOWER_TEMPLE_BOSS_KEY_CHEST,
	STONE_TOWER_TEMPLE_ARMOS_ROOM_CHEST,
	STONE_TOWER_TEMPLE_EYEGORE_ROOM_CHEST,
	STONE_TOWER_TEMPLE_UPDRAFT_ROOM_CHEST,
	STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM_CHEST,
	STONE_TOWER_TEMPLE_LIGHT_ARROW_CHEST,
	STONE_TOWER_TEMPLE_GIANTS_MASK_CHEST,

	//Pirate's Fortress
	PIRATE_FORTRESS_INTERIOR_HOOKSHOT_CHEST,
	PIRATE_FORTRESS_INTERIOR_LOWER_CHEST,
	PIRATE_FORTRESS_INTERIOR_UPPER_CHEST,
	PIRATE_FORTRESS_INTERIOR_TANK_CHEST,
	PIRATE_FORTRESS_INTERIOR_GUARD_ROOM_CHEST,
	PIRATE_FORTRESS_SEWER_CAGE_ROOM_SHALLOW_CHEST,
	PIRATE_FORTRESS_SEWER_CAGE_ROOM_DEEP_CHEST,
	PIRATE_FORTRESS_MAZE_CHEST,
	PIRATE_FORTRESS_SEWER_CAGE,
	PIRATE_FORTRESS_EXTERIOR_LOG_CHEST,
	PIRATE_FORTRESS_EXTERIOR_SAND_CHEST,
	PIRATE_FORTRESS_EXTERIOR_CORNER_CHEST,

	//Beneath the Well
	BENEATH_THE_WELL_MIRROR_SHIELD_CHEST,
	BENEATH_THE_WELL_LEFT_PATH_CHEST,
	BENEATH_THE_WELL_RIGHT_PATH_CHEST,

	//Ikana Castle
	IKANA_CASTLE_PILLAR,
	IKANA_CASTLE_IKANA_KING,

	//Secret Shrine
	SECRET_SHRINE_DINOLFOS_CHEST,
	SECRET_SHRINE_WIZZROBE_CHEST,
	SECRET_SHRINE_WART_CHEST,
	SECRET_SHRINE_GARO_CHEST,
	SECRET_SHRINE_FINAL_CHEST,

	//The Moon
	THE_MOON_DEKU_TRIAL_BONUS,
	THE_MOON_GORON_TRIAL_BONUS,
	THE_MOON_ZORA_TRIAL_BONUS,
	THE_MOON_LINK_TRIAL_BONUS,
	THE_MOON_MAJORA_CHILD,

	//SKULLTULAS
	
	//Swamp Spider House
	SSH_MAIN_ROOM_NEAR_CEILING,
	SSH_MAIN_ROOM_WATER,
	SSH_MAIN_ROOM_LOWER_LEFT_SOIL,
	SSH_MAIN_ROOM_LOWER_RIGHT_SOIL,
	SSH_MAIN_ROOM_UPPER_SOIL,
	SSH_MAIN_ROOM_PILLAR,
	SSH_MAIN_ROOM_UPPER_PILLAR,
	SSH_MAIN_ROOM_JAR,
	SSH_MONUMENT_ROOM_CRATE_1,
	SSH_MONUMENT_ROOM_CRATE_2,
	SSH_MONUMENT_ROOM_TORCH,
	SSH_MONUMENT_ROOM_ON_MONUMENT,
	SSH_MONUMENT_ROOM_LOWER_WALL,
	SSH_GOLD_ROOM_NEAR_CEILING,
	SSH_GOLD_ROOM_PILLAR,
	SSH_GOLD_ROOM_BEEHIVE,
	SSH_GOLD_ROOM_WALL,
	SSH_POT_ROOM_JAR,
	SSH_POT_ROOM_POT_1,
	SSH_POT_ROOM_POT_2,
	SSH_POT_ROOM_BEHIND_VINES,
	SSH_POT_ROOM_WALL,
	SSH_POT_ROOM_BEEHIVE_1,
	SSH_POT_ROOM_BEEHIVE_2,
	SSH_TREE_ROOM_TREE_1,
	SSH_TREE_ROOM_TREE_2,
	SSH_TREE_ROOM_TREE_3,
	SSH_TREE_ROOM_GRASS_1,
	SSH_TREE_ROOM_GRASS_2,
	SSH_TREE_ROOM_BEEHIVE,

	//Ocean Spider House
	OSH_ENTRANCE_LEFT_WALL,
	OSH_ENTRANCE_RIGHT_WALL,
	OSH_ENTRANCE_WEB,
	OSH_LIBRARY_HOLE_BEHIND_PICTURE,
	OSH_LIBRARY_HOLE_BEHIND_CABINET,
	OSH_LIBRARY_ON_CORNER_BOOKSHELF,
	OSH_LIBRARY_CEILING_EDGE,
	OSH_LIBRARY_BEHIND_BOOKCASE_1,
	OSH_LIBRARY_BEHIND_BOOKCASE_2,
	OSH_LIBRARY_BEHIND_PICTURE,
	OSH_SECOND_ROOM_CEILING_EDGE,
	OSH_SECOND_ROOM_CEILING_PLANK,
	OSH_SECOND_ROOM_JAR,
	OSH_SECOND_ROOM_WEBBED_HOLE,
	OSH_SECOND_ROOM_WEBBED_POT,
	OSH_SECOND_ROOM_UPPER_POT,
	OSH_SECOND_ROOM_BEHIND_SKULL_1,
	OSH_SECOND_ROOM_BEHIND_SKULL_2,
	OSH_SECOND_ROOM_LOWER_POT,
	OSH_STORAGE_ROOM_CEILING_WEB,
	OSH_STORAGE_ROOM_BEHIND_CRATE,
	OSH_STORAGE_ROOM_BEHIND_BOAT,
	OSH_STORAGE_ROOM_CRATE,
	OSH_STORAGE_ROOM_JAR,
	OSH_COLORED_SKULLS_CEILING_EDGE,
	OSH_COLORED_SKULLS_CHANDELIER_1,
	OSH_COLORED_SKULLS_CHANDELIER_2,
	OSH_COLORED_SKULLS_CHANDELIER_3,
	OSH_COLORED_SKULLS_BEHIND_PICTURE,
	OSH_COLORED_SKULLS_POT,

	//STRAY FAIRIES
	
	//Clock Town Stray Fairy
	LAUNDRY_POOL_SF,

	//Woodfall Stray Fairy
	WF_SF_ENTRANCE_FAIRY,
	WF_SF_ENTRANCE_PLATFORM,
	WF_SF_MAIN_ROOM_BUBBLE,
	WF_SF_MAIN_ROOM_SWITCH,
	WF_SF_PRE_BOSS_LOWER_RIGHT_BUBBLE,
	WF_SF_PRE_BOSS_UPPER_RIGHT_BUBBLE,
	WF_SF_PRE_BOSS_UPPER_LEFT_BUBBLE,
	WF_SF_PRE_BOSS_PILLAR_BUBBLE,
	WF_SF_DEKU_BABA,
	WF_SF_POISON_WATER_BUBBLE,
	WF_SF_SKULLTULA,
	WF_SF_DARK_ROOM,
	WF_SF_JAR_FAIRY,
	WF_SF_BRIDGE_ROOM_BEEHIVE,
	WF_SF_PLATFORM_ROOM_BEEHIVE,

	//Snowhead Stray Fairy
	SH_SF_SNOW_ROOM_BUBBLE,
	SH_SF_CEILING_BUBBLE,
	SH_SF_DINOLFOS_1,
	SH_SF_DINOLFOS_2,
	SH_SF_BRIDGE_ROOM_LEDGE_BUBBLE,
	SH_SF_BRIDGE_ROOM_PILLAR_BUBBLE,
	SH_SF_MAP_ROOM_FAIRY,
	SH_SF_MAP_ROOM_LEDGE,
	SH_SF_BASEMENT,
	SH_SF_TWIN_BLOCK,
	SH_SF_ICICLE_ROOM_WALL,
	SH_SF_MAIN_ROOM_WALL,
	SH_SF_PILLAR_FREEZARDS,
	SH_SF_ICE_PUZZLE,
	SH_SF_CRATE,

	//Great Bay Temple Stray Fairies
	GBT_SF_SKULLTULA,
	GBT_SF_WATER_CONTROL_UNDERWATER_BUBBLE,
	GBT_SF_WATERWHEEL_ROOM_LOWER,
	GBT_SF_WATERWHEEL_ROOM_UPPER,
	GBT_SF_GREEN_VALVE,
	GBT_SF_SEESAW_ROOM,
	GBT_SF_ENTRANCE_TORCHES,
	GBT_SF_BIO_BABAS,
	GBT_SF_UNDERWATER_BARREL,
	GBT_SF_WHIRLPOOL_JAR,
	GBT_SF_WHIRLPOOL_BARREL,
	GBT_SF_DEXIHANDS_JAR,
	GBT_SF_LEDGE_JAR,
	GBT_SF_PRE_BOSS_ROOM_BUBBLE,
	GBT_SF_PRE_BOSS_ROOM_UNDERWATER_BUBBLE,

	//Stone Tower Stray Fairies
	ST_SF_MIRROR_SUN_BLOCK,
	ST_SF_LAVA_ROOM_LEDGE,
	ST_SF_LAVA_ROOM_FIRE_RING,
	ST_SF_EYEGORE,
	ST_SF_UPDRAFT_FIRE_RING,
	ST_SF_MIRROR_SUN_SWITCH,
	ST_SF_BOSS_WARP,
	ST_SF_WIZZROBE,
	ST_SF_DEATH_ARMOS,
	ST_SF_UPDRAFT_FROZEN_EYE,
	ST_SF_THIN_BRIDGE,
	ST_SF_BASEMENT_LEDGE,
	ST_SF_STATUE_EYE,
	ST_SF_UNDERWATER,
	ST_SF_BRIDGE_CRYSTAL,


	//AREAS
	ROOT,
	ROOT_EXITS,
	CLOCK_TOWN,
	CLOCK_TOWER,
	N_CLOCK_TOWN,
	E_CLOCK_TOWN,
	W_CLOCK_TOWN,
	S_CLOCK_TOWN,
	CLOCK_TOWN_BAR,
	CLOCK_TOWN_ARCHREY,
	CLOCK_TOWN_MAYOR_HOUSE,
	CLOCK_TOWN_HONEY_DARLING,
	CLOCK_TOWN_TREASURE_CHEST_GAME,
	CLOCK_TOWN_POSTMAN_HOUSE,
	CLOCK_TOWN_BOMBERS_HIDEOUT,
	CLOCK_TOWN_OBSERVATORY,
	CLOCK_TOWN_FAIRY_FOUNTAIN,
	CLOCK_TOWN_SWORDSMANS_SCHOOL,
	CLOCK_TOWN_BOMB_SHOP,
	CLOCK_TOWN_TRADING_POST,
	CLOCK_TOWN_CURIOSITY_SHOP,
	CLOCK_TOWN_BANK,
	CLOCK_TOWN_DEKU_PLAYGROUND,
	CUCCO_SHACK,
	DOGGY_RACETRACK,
	GORMAN_TRACK,
	SWAMP_TOURIST_CENTER,
	HAGS_POTION_SHOP,
	MYSTERY_WOODS,
	DEKU_PALACE,
	DEKU_PALACE_BEAN_GROTTO,
	DEKU_PALACE_WEST_GARDEN,
	DEKU_PALACE_INTERIOR,
	DEKU_SHRINE,
	MOUNTAIN_SMITHY,
	GORON_GRAVEYARD,
	GORON_RACETRACK,
	GORON_KEG_SHOP,
	GORON_SHOP,
	FISHERMAN_HUT,
	MARINE_LAB,
	ZORA_SHOP,
	WATERFALL_RAPIDS,
	SPRING_WATER_CAVE,
	MUSIC_BOX_HOUSE,
	SPIRIT_HOUSE,
	SAKONS_HIDEOUT,
	IKANA_FAIRY_FOUNTAIN,
	GREAT_BAY_FAIRY_FOUNTAIN,
	WOODFALL_FAIRY_FOUNTAIN,
	WOODFALL_TEMPLE,
	WOODFALL_TEMPLE_ENTRANCE,
	WOODFALL_TEMPLE_MAIN_ROOM,
	WOODFALL_TEMPLE_PRE_BOSS_ROOM,
	WOODFALL_TEMPLE_BRIDGE_ROOM,
	WOODFALL_TEMPLE_PLATFORM_ROOM,
	WOODFALL_TEMPLE_BOW_ROOM,
	WOODFALL_TEMPLE_MINI_BOSS_ROOM,
	WOODFALL_TEMPLE_BOSS_ROOM,
	SNOWHEAD_TEMPLE,
	SNOWHEAD_TEMPLE_ENTRANCE,
	SNOWHEAD_TEMPLE_BLOCK_ROOM,
	SNOWHEAD_TEMPLE_ICICLE_ROOM,
	SNOWHEAD_TEMPLE_BRIDGE_ROOM,
	SNOWHEAD_DINOLFOS_ROOM,
	SNOWHEAD_TEMPLE_MAP_ROOM,
	SNOWHEAD_TEMPLE_BASEMENT,
	SNOWHEAD_TEMPLE_PILLAR,
	SNOWHEAD_TEMPLE_ICE_PUZZLE,
	SNOWHEAD_TEMPLE_WIZZROBE_ROOM,
	SNOWHEAD_TEMPLE_BOSS_ROOM,
	SNOWHEAD_FAIRY_FOUNTAIN,
	GBT,
	GBT_WATER_CONTROL_ROOM,
	GBT_BOSS_ROOM,
	GBT_MINI_BOSS_ROOM,
	GBT_SEESAW_ROOM,
	GBT_ENTRANCE,
	GBT_WHIRLPOOL_ROOM,
	GBT_PRE_BOSS_ROOM,
	GBT_BIO_BABA_ROOM,
	GBT_WATER_WHEEL_ROOM,
	GREAT_BAY_TEMPLE_WATER_CONTROL_ROOM,
	GREAT_BAY_TEMPLE,
	GREAT_BAY_TEMPLE_BOSS_ROOM,
	GREAT_BAY_TEMPLE_MINI_BOSS_ROOM,
	GREAT_BAY_TEMPLE_SEESAW_ROOM,
	GREAT_BAY_TEMPLE_ENTRANCE,
	GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM,
	GREAT_BAY_TEMPLE_PRE_BOSS_ROOM,
	GREAT_BAY_TEMPLE_BIO_BABA_ROOM,
	GREAT_BAY_TEMPLE_WATER_WHEEL_ROOM,
	STONE_TOWER_TEMPLE,
	STONE_TOWER_TEMPLE_BOSS_ROOM,
	STONE_TOWER_TEMPLE_LAVA_ROOM,
	STONE_TOWER_TEMPLE_BLOCK_ROOM,
	STONE_TOWER_TEMPLE_WATER_ROOM,
	STONE_TOWER_TEMPLE_BASEMENT,
	STONE_TOWER_TEMPLE_PRE_BOSS_ROOM,
	STONE_TOWER_TEMPLE_UPDRAFT_ROOM,
	STONE_TOWER_TEMPLE_GARO_ROOM,
	STONE_TOWER_TEMPLE_ENTRANCE,
	STOCKPOTINN,
	STOCKPOTINN_GUEST_ROOM,
	STOCKPOTINN_GRANDMA_ROOM,
	STOCKPOTINN_STAFF_ROOM,
	STOCKPOTINN_BATHROOM,
	LAUNDRY_POOL,
	LAUNDRY_POOL_KAFEI_HIDEOUT,
	FAIRY_FOUNTAIN,
	WOODFALL,
	SNOWHEAD,
	GORON_VILLAGE,
	GORON_VILLAGE_INTERIOR,
	GORON_VILLAGE_LENS_CAVE,
	GORON_VILLAGE_SHOP,
	GREAT_BAY_COAST,
	GREAT_BAY_COAST_GROTTO,
	GREAT_BAY_COAST_FISHERMAN_HUT,
	GREAT_BAY_COAST_MARINE_LAB,
	IKANA_CANYON,
	IKANA_CANYON_POE_HUT,
	IKANA_CANYON_MUSIC_HOUSE,
	IKANA_CANYON_SECRET_SHRINE_GROTTO,
	GROTTO,
	IKANA_GRAVEYARD,
	IKANA_GRAVEYARD_IRON_KNUCKLE_ROOM,
	IKANA_GRAVEYARD_KEESE_ROOM,
	IKANA_GRAVEYARD_BELOW_GRAVE,
	IKANA_GRAVEYARD_GROTTO,
	MILK_ROAD,
	MILK_ROAD_GORMAN_TRACK,
	MOUNTAIN_VILLAGE,
	MOUNTAIN_VILLAGE_SMITH,
	MOUNTAIN_VILLAGE_GRAVEYARD,
	MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO,
	ROAD_TO_SNOWHEAD,
	ROAD_TO_SNOWHEAD_GROTTO,
	ROAD_TO_IKANA,
	ROAD_TO_IKANA_GROTTO,
	ROAD_TO_SOUTHERN_SWAMP,
	ROAD_TO_SOUTHERN_SWAMP_ARCHERY,
	PINNACLE_ROCK,
	ROMANI_RANCH,
	ROMANI_RANCH_DOGGY_RACETRACK,
	SOUTHERN_SWAMP,
	SOUTHERN_SWAMP_HAGS_POTION_SHOP,
	SOUTHERN_SWAMP_TOURIST_CENTER,
	SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO,
	SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO,
	STONE_TOWER,
	TERMINA_FIELD,
	TERMINA_FIELD_OBSERVATORY,
	TERMINA_FIELD_GOSSIP_STONES_GROTTO,
	TERMINA_FIELD_BUSINESS_SCRUB_GROTTO,
	TERMINA_FIELD_PEAHAT_GROTTO,
	TERMINA_FIELD_DODONGO_GROTTO,
	TERMINA_FIELD_BIO_BABA_GROTTO,
	TERMINA_FIELD_PILLAR_GROTTO,
	TERMINA_FIELD_GRASS_GROTTO,
	TERMINA_FIELD_COW_GROTTO,
	TWIN_ISLANDS,
	TWIN_ISLANDS_SPRING_WATER_GROTTO,
	TWIN_ISLANDS_GORON_RACETRACK,
	TWIN_ISLANDS_GORON_RACETRACK_GROTTO,
	ZORA_CAPE,
	ZORA_CAPE_FAIRY_FOUNTAIN,
	ZORA_CAPE_WATERFALL_RAPIDS,
	ZORA_CAPE_GROTTO,
	ZORA_HALL,
	ZORA_HALL_SHOP,
	ZORA_HALL_LULUS_ROOM,
	ZORA_HALL_EVANS_ROOM,
	PIRATE_FORTRESS,
	PIRATE_FORTRESS_INTERIOR,
	PIRATE_FORTRESS_EXTERIOR,
	PIRATE_FORTRESS_SEWER,
	PIRATE_FORTRESS_MAZE,
	SECRET_SHRINE,
	SECRET_SHRINE_DINOLFOS_ROOM,
	SECRET_SHRINE_WIZZROBE_ROOM,
	SECRET_SHRINE_WART_ROOM,
	SECRET_SHRINE_GARO_ROOM,
	BENEATH_THE_WELL,
	BENEATH_THE_WELL_MIRROR_SHIELD_ROOM,
	BENEATH_THE_WELL_LEFT_PATH_ROOM,
	BENEATH_THE_WELL_RIGHT_PATH_ROOM,
	IKANA_CASTLE,
	IKANA_CASTLE_INTERIOR,
	IKANA_CASTLE_EXTERIOR,
	THE_MOON,
	THE_MOON_ZORA_TRIAL,
	THE_MOON_LINK_TRIAL,
	THE_MOON_GORON_TRIAL,
	THE_MOON_DEKU_TRIAL,
	THE_MOON_ENTRANCE,
	THE_MOON_BOSS_ROOM,
	SWAMP_SKULLTULA_HOUSE,
	SWAMP_SKULLTULA_HOUSE_MAIN_ROOM,
	SWAMP_SKULLTULA_HOUSE_MONUMENT_ROOM,
	SWAMP_SKULLTULA_HOUSE_GOLD_ROOM,
	SWAMP_SKULLTULA_HOUSE_POT_ROOM,
	SWAMP_SKULLTULA_HOUSE_TREE_ROOM,
	OCEANSIDE_SKULLTULA_HOUSE,
	OCEANSIDE_SKULLTULA_HOUSE_ENTRANCE,
	OCEANSIDE_SKULLTULA_HOUSE_LIBRARY,
	OCEANSIDE_SKULLTULA_HOUSE_SECOND_ROOM,
	OCEANSIDE_SKULLTULA_HOUSE_STORAGE_ROOM,
	OCEANSIDE_SKULLTULA_HOUSE_COLORED_SKULLS,
	SSH,
	SSH_MAIN_ROOM,
	SSH_MONUMENT_ROOM,
	SSH_GOLD_ROOM,
	SSH_POT_ROOM,
	SSH_TREE_ROOM.
	OSH,
	OSH_ENTRANCE,
	OSH_LIBRARY,
	OSH_SECOND_ROOM,
	OSH_STORAGE_ROOM,
	OSH_COLORED_SKULLS,
	//HINTS
	  PREFIX,
	  WAY_OF_THE_HERO,
	  PLUNDERING,
	  FOOLISH,
	  CAN_BE_FOUND_AT,
	  HOARDS,

	  JUNK01,
	  JUNK02,
	  JUNK03,
	  JUNK04,
	  JUNK05,
	  JUNK06,
	  JUNK07,
	  JUNK08,
	  JUNK09,
	  JUNK10,
	  JUNK11,
	  JUNK12,
	  JUNK13,
	  JUNK14,
	  JUNK15,
	  JUNK16,
	  JUNK17,
	  JUNK18,
	  JUNK19,
	  JUNK20,
	  JUNK21,
	  JUNK22,
	  JUNK23,
	  JUNK24,
	  JUNK25,
	  JUNK26,
	  JUNK27,
	  JUNK28,
	  JUNK29,
	  JUNK30,
	  JUNK31,
	  JUNK32,
	  JUNK33,
	  JUNK34,
	  JUNK35,
	  JUNK36,
	  JUNK37,
	  JUNK38,
	  JUNK39,
	  JUNK40,
	  JUNK41,
	  JUNK42,
	  JUNK43,
	  JUNK44,
	  JUNK45,
	  JUNK46,
	  JUNK47,
	  JUNK48,
	  JUNK49,
	  JUNK50,
	  JUNK51,
	  JUNK52,
	  JUNK53,
	  JUNK54,
	  JUNK55,
	  JUNK56,
	  JUNK57,
	  JUNK58,
	  JUNK59,
	  JUNK60,
	  JUNK61,
	  JUNK62,
	  JUNK63,
	  JUNK64,
	  JUNK65,
	  JUNK66,
	  JUNK67,
	  JUNK68,
	  JUNK69,
	  JUNK70,
	  JUNK71,
	  JUNK72,
	  JUNK73,
	  JUNK74,
	  JUNK75,
	  JUNK76,
	  JUNK77,
	  
	  KEY_ENUM_MAX,
} Key;