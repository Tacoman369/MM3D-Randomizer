#include "location_access.hpp"

#include "item_list.hpp"
#include "item_location.hpp"
#include "item_pool.hpp"
#include "logic.hpp"
#include "settings.hpp"
#include "spoiler_log.hpp"

#include <unistd.h>

using namespace Logic;
using namespace Settings;

bool LocationAccess::CanBuy() const {
	//if its not a shop you dont need to check if it can  be bought
	if (!(Location(location)->IsCategory(Category::cShop))) {
		return true;
	}

	//Check if current walet is large enough 
	bool SufficientWallet = true;
	if (Location(location)->GetPrice() > 500) {
		SufficientWallet = Logic::ProgressiveWallet >= 3;
	}
	else if (Location(location)->GetPrice() > 200) {
		SufficientWallet = Logic::ProgressiveWallet >= 2;
	}
	else if (Location(location)->GetPrice() > 99) {
		SufficientWallet = Logic::ProgressiveWallet >= 1;
	}

	bool OtherCondition = true;
	u32 placed = Location(location)->GetPlacedItemKey();
	//Need bottle to buy bottle items
	if (placed == BUY_BLUE_POTION || placed == BUY_FAIRYS_SPIRIT || placed == BUY_GREEN_POTION) {
		OtherCondition = Logic::HasBottle;
	}
	//Need Bombbag to buy bombs/bombchus
	else if (placed == BUY_BOMBS_10 || placed == BUY_BOMBCHU_10 || placed == BUY_BOMBS_20 || placed == BUY_BOMBS_30) {
		OtherCondition = Logic::HasExplosives;
	}
	return SufficientWallet && OtherCondition;
}

Area::Area() = default;
Area::Area(std::string regionName_, std::string scene_, u32 hintKey_, std::vector<EventAccess> events_, std::vector<LocationAccess> locations_ )
	: regionName(std::move(regionName_)),
	scene(std::move(scene_)),
	hintKey(hintKey_),
	events(std::move(events_)),
	locations(std::move(locations_)) {}

Area::~Area() = default;

bool Area::UpdateEvents() {
	bool eventsUpdated = false;

	for (EventAccess& event : events)
	{
		//if event happened dont check it.
		if (event.GetEvent()) {
			continue;
		}
	}
	return eventsUpdated;
}

bool Area::CanPlantBeanCheck() const {
	return(Logic::MagicBean || Logic::MagicBeanPack);
}


bool Area::AllAccountedFor() const {
	for (const EventAccess& event : events) {
		if (!event.GetEvent()) {
			return false;
		}
	}

	for (const LocationAccess& loc : locations) {
		if (!(Location(loc.GetLocation())->IsAddedToPool())) {
			return false;
		}
	}

	return AllAccess();
}

bool Area::CheckAllAccess(const AreaKey exitKey) {
	if (!AllAccess()) {
		return false;
	}
	else { return true; }
}


void Area::ResetVariables() {
	addedToPool = false;
}

static std::array<Area, KEY_ENUM_MAX> areaTable;

bool Here(const AreaKey area, ConditionFn condition) {
	return areaTable[area].HereCheck(condition);
}

bool CanPlantBean(const AreaKey area) {
	return areaTable[area].CanPlantBeanCheck();
}

bool HasAccessTo(const AreaKey area) {
	return areaTable[area].HasAccess();
}

void AreaTable_Init() {
	//clear array from previous playthroughs
	areaTable.fill(Area("Invalid Area", "Invalid Area", NONE, {}, {}));
						//Name, Scene, hint text, events, locations
	areaTable[ROOT] = Area("Root", "", LINKS_POCKET, {}, { 
		LocationAccess(LINKS_POCKET, {[] {return true;}}) 
		});

	/*--------------------------
	|    OVERWORLD             |
	---------------------------*/
	areaTable[DEKU_PALACE] = Area("Deku Palace", "Deku Palace", DEKU_PALACE, {}, {
		//locations
		LocationAccess(DEKU_PALACE_BEAN_GROTTO, {[] {return PoisonSwampAccess && ((Hookshot && DekuMask) || (WaterForBeans && DekuMask));}}),
		LocationAccess(DEKU_PALACE_WEST_GARDEN, {[] {return PoisonSwampAccess && DekuMask;}}),
		LocationAccess(DEKU_PALACE_BUTLER_RACE, {[] {return WoodfallClear || (PoisonSwampAccess && DekuMask && DekuPrincess);}}),
		LocationAccess(DEKU_PALACE_IMPRISONED_MONKEY, {[] {return PoisonSwampAccess && DekuMask;}}),
		});

	areaTable[E_CLOCK_TOWN] = Area("East Clock Town", "East Clock Town", E_CLOCK_TOWN, {}, {
		//Locations
		LocationAccess(E_CLOCK_TOWN_AROMA_IN_BAR, {[] {return LetterMama && KafeisMask;}}),
		LocationAccess(E_CLOCK_TOWN_AROMA_IN_OFFICE, {[] {return true;}}),
		LocationAccess(E_CLOCK_TOWN_ARCHERY_1, {[] {return Arrows;}}),
		LocationAccess(E_CLOCK_TOWN_ARCHERY_2, {[] {return Arrows;}}),
		LocationAccess(E_CLOCK_TOWN_HONEY_DARLING_3DAYS, {[] {return Arrows && AnyBombBag;}}),
		LocationAccess(E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON, {[] {return GoronMask;}}),
		LocationAccess(E_CLOCK_TOWN_POSTMAN_FREEDOM, {[] {return LetterMama;}}),
		LocationAccess(E_CLOCK_TOWN_GORMAN, {[] {return DekuMask && GoronMask && ZoraMask && RomanisMask;}}),
		LocationAccess(E_CLOCK_TOWN_CHEST, {[] {return true;}}),
		LocationAccess(BOMBERS_HIDEOUT_CHEST, {[] {return HasExplosives || (DekuMask&&MagicMeter) || ZoraMask || Hookshot || Arrows;}}),

		});

	areaTable[GORON_VILLAGE] = Area("Goron Village", "Goron Village", GORON_VILLAGE, {}, {
		//Locations
		LocationAccess(GORON_VILLAGE_POWDER_KEG_CHALLENGE, {[] {return GoronMask && NorthAccess && (SnowheadClear || UseFireArrow);}}),
		LocationAccess(GORON_VILLAGE_BIGGEST_BOMB_BAG_BUY, {[] {return NorthAccess && AnyWallet && (GoronMask || (DekuMask && MoonsTear && LandTitle && SwampTitle));}}),
		LocationAccess(GORON_VILLAGE_LENS_OF_TRUTH_CHEST, {[] {return NorthAccess;}}),
		LocationAccess(GORON_VILLAGE_MOUNTAIN_TITLE_DEED, {[] {return DekuMask && NorthAccess && SwampTitle;}}),
		LocationAccess(GORON_VILLAGE_LEDGE, {[] {return DekuMask && NorthAccess && SwampTitle;}}),
		LocationAccess(GORON_VILLAGE_GORON_LULLABY, {[] {return NorthAccess && GoronMask;}}),
		LocationAccess(LENS_CAVE_RED_RUPEE, {[] {return NorthAccess && LensOfTruth && MagicMeter;}}),
		LocationAccess(LENS_CAVE_PURPLE_RUPEE, {[] {return NorthAccess && LensOfTruth && MagicMeter && HasExplosives;}}),

		});

	areaTable[GREAT_BAY_COAST] = Area("Great Bay Coast", "Great Bay Coast", GREAT_BAY_COAST, {}, {
		//Locations
		LocationAccess(GBC_OCEAN_SPIDER_DAY1, {[] {return WestAccess && AccessToAllOceanSpiders;}}),
		LocationAccess(GBC_FISHERMAN_GAME, {[] {return GreatBayClear && Hookshot;}}),
		LocationAccess(GBC_OCEAN_SPIDER_CHEST, {[] {return Arrows && OceanSkulltulas && CaptainsHat;}}),
		LocationAccess(GBC_LAB_FISH, {[] {return WestAccess && Fish;}}),
		LocationAccess(GBC_LEDGE, {[] {return WestAccess && Hookshot && AnyMagicBean && WaterForBeans;}}),
		LocationAccess(GBC_MIKAU, {[] {return SongOfHealing && WestAccess;}}),
		LocationAccess(GBC_BABY_ZORAS, {[] {return PiratesFortressAccess && ZoraEgg && ZoraMask && WestAccess && Hookshot;}}),
		LocationAccess(GBC_GROTTO, {[] {return WestAccess;}}),
		LocationAccess(GBC_FISHERMAN_PHOTO, {[] {return Pictobox && WestAccess && PiratesFortressAccess;}}),

		});

	areaTable[IKANA_CANYON] = Area("Ikana Canyon", "Ikana Canyon", IKANA_CANYON, {}, {
		//Locations
		LocationAccess(IKANA_CANYON_GREAT_FAIRY, {[] {return IkanaCanyonAccess && StoneTowerClear;}}),
		LocationAccess(IKANA_CANYON_POE_HUT, {[] {return IkanaCanyonAccess && Arrows && Fighting;}}),
		LocationAccess(IKANA_CANYON_LEDGE, {[] {return ZoraMask && OceanTitle && DekuMask && EastAccess;}}),
		LocationAccess(IKANA_CANYON_PAMELAS_FATHER, {[] {return SongOfHealing && SongOfStorms && IkanaCanyonAccess;}}),
		LocationAccess(IKANA_CANYON_SECRET_SHRINE_GROTTO, {[] {return EastAccess;}}),
		LocationAccess(IKANA_CANYON_SCRUB_TRADE, {[] {return EastAccess && ZoraMask && OceanTitle;}}),

		});

	areaTable[IKANA_GRAVEYARD] = Area("Ikana Graveyard", "Ikana Graveyard", IKANA_GRAVEYARD, {}, {
		//Locations
		LocationAccess(IKANA_GRAVEYARD_DAMPE_DIGGING, {[] {return CaptainsHat && IkanaGraveyardAccess;}}),
		LocationAccess(IKANA_GRAVEYARD_IRON_KNUCKLE_CHEST, {[] {return CaptainsHat && IkanaGraveyardAccess && Explosives && AnySword;}}),
		LocationAccess(IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST, {[] {return SonataOfAwakening && IkanaGraveyardAccess&&Fighting;}}),
		LocationAccess(IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET, {[] {return CaptainsHat && IkanaGraveyardAccess && (AnySword || GoronMask || ZoraMask);}}),
		LocationAccess(IKANA_GRAVEYARD_DAY_ONE_GRAVE_BATS, {[] {return CaptainsHat && IkanaGraveyardAccess && (Fighting || DekuMask);}}),
		LocationAccess(IKANA_GRAVEYARD_GROTTO, {[] {return Explosives && IkanaGraveyardAccess;}}),

		});

	areaTable[LAUNDRY_POOL] = Area("Laundry Pool", "Laundry Pool", LAUNDRY_POOL, {}, {
		//Locations
		LocationAccess(LAUNDRY_POOL_KAFEI, {[] {return LetterKafei;}}),
		LocationAccess(LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE, {[] {return LetterKafei;}}),
		LocationAccess(LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO, {[] {return LetterKafei;}}),
		LocationAccess(LAUNDRY_POOL_GURU_GURU, {[] {return true;}}), //No Reqs, Talk on night of day 1 or 2
		LocationAccess(LAUNDRY_POOL_SF, { [] {return true;}}),

		});

	areaTable[MILK_ROAD] = Area("Milk Road", "Milk Road", MILK_ROAD, {}, {
		//Locations
		LocationAccess(MILK_ROAD_GORMAN_RACE, {[] {return EponasSong;}}),

		});

	areaTable[MOUNTAIN_VILLAGE] = Area("Mountain Village", "Mountain Village", MOUNTAIN_VILLAGE, {}, {
		//Locations
		LocationAccess(MOUNTAIN_VILLAGE_SMITH_DAY_ONE, {[] {return NorthAccess && AnyWallet && ( HotSpringWater || SnowheadClear || UseFireArrow);}}),
		LocationAccess(MOUNTAIN_VILLAGE_SMITH_DAY_TWO, {[] {return NorthAccess && GoronRaceBottle && (HotSpringWater || SnowheadClear ||UseFireArrow);}}),
		LocationAccess(MOUNTAIN_VILLAGE_FROG_CHOIR, {[] {return NorthAccess && GoronMask && MagicMeter;}}),
		LocationAccess(MOUNTAIN_VILLAGE_DARMANI, {[] {return NorthAccess && MagicMeter && LensOfTruth && SongOfHealing;}}),
		LocationAccess(MOUNTAIN_VILLAGE_HUNGRY_GORON, {[] {return NorthAccess && GoronMask && MagicMeter;}}),
		LocationAccess(MOUNTAIN_WATERFALL_CHEST, {[] {return SnowheadClear && LensOfTruth && MagicMeter;}}),
		LocationAccess(MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO, {[] {return SnowheadClear;}}),

		});

	areaTable[N_CLOCK_TOWN] = Area("North Clock Town", "North Clock Town", N_CLOCK_TOWN, {}, {
		//Locations
		LocationAccess(N_CLOCK_TOWN_GREAT_FAIRY_DEKU, {[] {return ClockTownStrayFairy && (ZoraMask || GoronMask || DekuMask);}}),
		LocationAccess(N_CLOCK_TOWN_GREAT_FAIRY_HUMAN, {[] {return ClockTownStrayFairy;}}),
		LocationAccess(N_CLOCK_TOWN_KEATON_QUIZ, {[] {return KeatonMask;}}),
		LocationAccess(N_CLOCK_TOWN_DEKU_PLAYGROUND_3DAYS, {[] {return DekuMask;}}),
		LocationAccess(N_CLOCK_TOWN_TREE, {[] {return true;}}),
		LocationAccess(N_CLOCK_TOWN_OLD_LADY, {[] {return Fighting || Arrows;}}),

		});

	areaTable[ROAD_TO_SNOWHEAD] = Area("Road To Snowhead", "Road To Snowhead", ROAD_TO_SNOWHEAD, {}, {
		//Locations
		LocationAccess(ROAD_TO_SNOWHEAD_GROTTO, {[] {return NorthAccess && Explosives && GoronMask && MagicMeter;}}),
		LocationAccess(ROAD_TO_SNOWHEAD_PILLAR, {[] {return NorthAccess && GoronMask && Hookshot && MagicMeter && LensOfTruth;}}),

		});

	areaTable[PINNACLE_ROCK] = Area("Pinnacle Rock", "Pinnacle Rock", PINNACLE_ROCK, {}, {
		//Locations
		LocationAccess(PINNACLE_ROCK_SEAHORSES, {[] {return PinnacleRockAccess && WestAccess;}}),
		LocationAccess(PINNACLE_ROCK_UPPER_CHEST, {[] {return PinnacleRockAccess && WestAccess;}}),
		LocationAccess(PINNACLE_ROCK_LOWER_CHEST, {[] {return PinnacleRockAccess && WestAccess;}}),

		});

	areaTable[ROAD_TO_IKANA] = Area("Road To Ikana", "Road To Ikana", ROAD_TO_IKANA, {}, {
		//Locations
		LocationAccess(ROAD_TO_IKANA_GROTTO, {[] {return GoronMask;}}),
		LocationAccess(ROAD_TO_IKANA_INVISIBLE_SOLDIER, {[] {return LensOfTruth && MagicMeter && AnyHealingPotion && EastAccess;}}),
		LocationAccess(ROAD_TO_IKANA_PILLAR_CHEST, {[] {return Hookshot;}}),

		});

	areaTable[ROAD_TO_SOUTHERN_SWAMP] = Area("Road to Southern Swamp", "Road to Southern Swamp", ROAD_TO_SOUTHERN_SWAMP, {}, {
		//Locations
		LocationAccess(ROAD_TO_SS_ARCHERY_1, {[] {return Arrows;}}),
		LocationAccess(ROAD_TO_SS_ARCHERY_2, {[] {return Arrows;}}),
		LocationAccess(ROAD_TO_SS_TREE, {[] {return DekuMask && (MagicMeter || Arrows || Hookshot || ZoraMask);}}),
		LocationAccess(PATH_TO_SWAMP_GROTTO, {[] {return true;}}),

		});

	areaTable[ROMANI_RANCH] = Area("Romani Ranch", "Romani Ranch", ROMANI_RANCH, {}, {
		//Locations
		LocationAccess(ROMANI_RANCH_ALIEN_DEFENSE, {[] {return EponaAccess && Arrows;}}),
		LocationAccess(ROMANI_RANCH_DOG_RACE, {[] {return EponaAccess && MaskOfTruth;}}),
		LocationAccess(ROMANI_RANCH_GROG, {[] {return BremenMask && EponaAccess;}}),
		LocationAccess(ROMANI_RANCH_CREMIA_ESCORT, {[] {return EponaAccess && Arrows;}}),
		LocationAccess(ROMANI_RANCH_ROMANIS_GAME, {[] {return EponaAccess && Arrows;}}),
		LocationAccess(DOGGY_RACETRACK_ROOF_CHEST, {[] {return Hookshot || (WaterForBeans && AnyMagicBean) || ZoraMask;}}),

		});

	areaTable[S_CLOCK_TOWN] = Area("South Clock Town", "South Clock Town", S_CLOCK_TOWN, {}, {
		//Locations
		LocationAccess(S_CLOCK_TOWN_SCRUB_TRADE, {[] {return MoonsTear;}}),
		LocationAccess(S_CLOCK_TOWN_POSTBOX, {[] {return PostmansHat;}}),
		LocationAccess(S_CLOCK_TOWN_CLOCK_TOWER_ENTRANCE, {[] {return true;}}),
		LocationAccess(S_CLOCK_TOWN_STRAW_ROOF_CHEST, {[] {return Hookshot || (DekuMask && MoonsTear);}}),
		LocationAccess(S_CLOCK_TOWN_FINAL_DAY_CHEST, {[] {return Hookshot || (DekuMask && MoonsTear);}}),
		LocationAccess(S_CLOCK_TOWN_BANK_REWARD_1, {[] {return true;}}),
		LocationAccess(S_CLOCK_TOWN_BANK_REWARD_2, {[] {return AnyWallet;}}),
		LocationAccess(S_CLOCK_TOWN_BANK_REWARD_3, {[] {return AnyWallet;}}),

		});

	areaTable[SNOWHEAD] = Area("Snowhead", "Snowhead", SNOWHEAD, {}, {
		//Locations
		LocationAccess(SNOWHEAD_GREAT_FAIRY, {[] {return AllSnowheadStrays;}}),
		});

	areaTable[SOUTHERN_SWAMP] = Area("Southern Swamp", "Southern Swamp", SOUTHERN_SWAMP, {}, {
		//Locations
		LocationAccess(SOUTHERN_SWAMP_KOUME, {[] {return AnyHealingPotion;}}),
		LocationAccess(SOUTHERN_SWAMP_KOTAKE, {[] {return true;}}),
		LocationAccess(SOUTHERN_SWAMP_SCRUB_TRADE, {[] {return LandTitle;}}),
		LocationAccess(SOUTHERN_SWAMP_PICTOGRAPH_WINNER, {[] {return Pictobox;}}),
		LocationAccess(SOUTHERN_SWAMP_BOAT_ARCHERY, {[] {return WoodfallClear && AnyHealingPotion;}}),
		LocationAccess(SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD, {[] {return PoisonSwampAccess && AccessToAllSwampSpiders;}}),
		LocationAccess(SOUTHERN_SWAMP_MUSIC_STATUE, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO, {[] {return PoisonSwampAccess && DekuMask;}}),
		LocationAccess(SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO, {[] {return true;}}),
		LocationAccess(SOUTHERN_SWAMP_KOTAKE_MUSHROOM_SALE, {[] {return MaskOfScents && AnyBottle && Mushroom;}}),
		LocationAccess(SWAMP_TOURIST_CENTER_ROOF, {[] {return DekuMask && LandTitle;}}),

		});

	areaTable[STOCKPOTINN] = Area("Stock Pot Inn", "Stock Pot Inn", STOCKPOTINN, {}, {
		//Locations
		LocationAccess(STOCKPOTINN_RESERVATION, {[] {return GoronMask;}}),
		LocationAccess(STOCKPOTINN_MIDNIGHT_MEETING, {[] {return KafeisMask && NightInnAccess;}}),
		LocationAccess(STOCKPOTINN_TOILET_HAND, {[] {return NightInnAccess && AnyPaper;}}),
		LocationAccess(STOCKPOTINN_GRANDMA_SHORT_STORY, {[] {return AllNightMask;}}),
		LocationAccess(STOCKPOTINN_GRANDMA_LONG_STORY, {[] {return AllNightMask;}}),
		LocationAccess(STOCKPOTINN_ANJU_AND_KAFEI, {[] {return LetterKafei && PendantOfMemories;}}),
		LocationAccess(STOCKPOTINN_STAFF_ROOM_CHEST, {[] {return true;}}),
		LocationAccess(STOCKPOTINN_GUEST_ROOM_CHEST, {[] {return RoomKey;}}),

		});

	areaTable[STONE_TOWER] = Area("Stone Tower", "Stone Tower", STONE_TOWER, {}, {
		//Locations
		LocationAccess(STONE_TOWER_INVERTED_LEFT_CHEST, {[] {return InvertedStoneTowerTempleAccess && AnyMagicBean && WaterForBeans;}}),
		LocationAccess(STONE_TOWER_INVERTED_CENTER_CHEST, {[] {return InvertedStoneTowerTempleAccess && AnyMagicBean && WaterForBeans;}}),
		LocationAccess(STONE_TOWER_INVERTED_RIGHT_CHEST, {[] {return InvertedStoneTowerTempleAccess && AnyMagicBean && WaterForBeans;}}),

		});

	areaTable[TERMINA_FIELD] = Area("Termina Field", "Termina Field", TERMINA_FIELD, {}, {
		//Locations
		LocationAccess(TERMINA_FIELD_MOONS_TEAR, {[] {return true;}}),
		LocationAccess(TERMINA_FIELD_GOSSIP_STONES, {[] {return (GoronMask && GoronsLullaby) || (DekuMask && SonataOfAwakening && Explosives) || (DekuMask&&SonataOfAwakening&&GoronMask) || (ZoraMask && NewWaveBossaNova && Explosives) || (ZoraMask && GoronMask && NewWaveBossaNova);}}),
		LocationAccess(TERMINA_FIELD_BUSINESS_SCRUB, {[] {return AnyWallet;}}),
		LocationAccess(TERMINA_FIELD_PEAHAT_GROTTO, {[] {return Fighting||Arrows||DekuMask;}}),
		LocationAccess(TERMINA_FIELD_DODONGO_GROTTO, {[] {return Fighting || Arrows || AnyBombBag || GoronMask || AnySword || ZoraMask;}}),
		LocationAccess(TERMINA_FIELD_BIO_BABA_GROTTO, {[] {return (GoronMask && ZoraMask) || (Explosives && ZoraMask);}}),
		LocationAccess(TERMINA_FIELD_KAMARO, {[] {return SongOfHealing;}}),
		LocationAccess(TERMINA_FIELD_PILLAR_GROTTO, {[] {return true;}}),
		LocationAccess(TERMINA_FIELD_GRASS_GROTTO, {[] {return true;}}),
		LocationAccess(TERMINA_FIELD_UNDERWATER_CHEST, {[] {return ZoraMask;}}),
		LocationAccess(TERMINA_FIELD_GRASS_CHEST, {[] {return true;}}),
		LocationAccess(TERMINA_FIELD_STUMP_CHEST, {[] {return Hookshot || (AnyMagicBean && WaterForBeans);}}),

		});

	areaTable[TWIN_ISLANDS] = Area("Twin Islands", "Twin Islands", TWIN_ISLANDS, {}, {
		//Locations
		LocationAccess(HOT_SPRING_WATER_GROTTO, {[] {return NorthAccess && Explosives && ((SongOfSoaring && AnyBottle && HotSpringWater) || SnowheadClear || UseFireArrow);}}),
		LocationAccess(TWIN_ISLANDS_GORON_RACE, {[] {return SnowheadClear && GoronMask && MagicMeter;}}),
		LocationAccess(TWIN_ISLANDS_GORON_RACETRACK_GROTTO, {[] {return NorthAccess && Explosives && (GoronMask || (Hookshot && ScarecrowSong));}}),
		LocationAccess(TWIN_ISLANDS_UNDERWATER_RAMP_CHEST, {[] {return SnowheadClear && ZoraMask;}}),
		LocationAccess(TWIN_ISLANDS_CAVE_CHEST, {[] {return SnowheadClear && ZoraMask;}}),
		});

	areaTable[W_CLOCK_TOWN] = Area("West Clock Town", "West Clock Town", W_CLOCK_TOWN, {}, {
		//Locations
		LocationAccess(W_CLOCK_TOWN_BOMB_BAG_BUY, {[] {return true;}}),
		LocationAccess(W_CLOCK_TOWN_BIG_BOMB_BAG_BUY, {[] {return LetterKafei && PendantOfMemories;}}),
		LocationAccess(W_CLOCK_TOWN_POSTMANS_GAME, {[] {return BunnyHood;}}),
		LocationAccess(W_CLOCK_TOWN_ROSA_SISTERS, {[] {return KamarosMask;}}),
		LocationAccess(W_CLOCK_TOWN_SWORDSMANS_SCHOOL, {[] {return AnyBSword;}}),
		LocationAccess(W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY, {[] {return AnyWallet;}}),
		//LocationAccess(W_CLOCK_TOWN_LOTTERY, {[] {return;}}),

		});

	areaTable[WOODFALL] = Area("Woodfall", "Woodfall", WOODFALL, {}, {
		//Locations
		LocationAccess(WOODFALL_BRIDGE_CHEST, {[] {return PoisonSwampAccess && DekuMask;}}),
		LocationAccess(WOODFALL_BEHIND_OWL_CHEST, {[] {return PoisonSwampAccess && DekuMask;}}),
		LocationAccess(WOODFALL_GREAT_FAIRY, {[] {return AllWoodfallStrays && DekuMask && PoisonSwampAccess && GreatFairyMask;}}),
		LocationAccess(ENTRANCE_TO_WOODFALL_CHEST, {[] {return PoisonSwampAccess && DekuMask;}}),

		});

	areaTable[ZORA_CAPE] = Area("Zora Cape", "Zora Cape", ZORA_CAPE, {}, {
		//Locations
		LocationAccess(ZORA_CAPE_GREAT_FAIRY, {[] {return Explosives && WestAccess && Hookshot && AllGreatBayStrays;}}),
		LocationAccess(ZORA_CAPE_BEAVER_RACE_1, {[] {return Hookshot && ZoraMask && WestAccess;}}),
		LocationAccess(ZORA_CAPE_BEAVER_RACE_2, {[] {return Hookshot && ZoraMask && WestAccess;}}),
		LocationAccess(ZORA_CAPE_LIKE_LIKE, {[] {return PiratesFortressAccess;}}),
		LocationAccess(ZORA_CAPE_LEDGE_NO_TREE, {[] {return WestAccess && Hookshot;}}),
		LocationAccess(ZORA_CAPE_LEDGE_WITH_TREE, {[] {return WestAccess && Hookshot;}}),
		LocationAccess(ZORA_CAPE_GROTTO, {[] {return WestAccess && (GoronMask || Explosives);}}),
		LocationAccess(ZORA_CAPE_UNDERWATER_CHEST, {[] {return WestAccess && ZoraMask;}}),

		});

	areaTable[ZORA_HALL] = Area("Zora Hall", "Zora Hall", ZORA_HALL, {}, {
		//Locations
		LocationAccess(ZORA_HALL_SCRUB_TRADE, {[] {return GoronMask && ZoraMask && WestAccess && MountainTitle;}}),
		LocationAccess(ZORA_HALL_EVAN, {[] {return ZoraMask && WestAccess;}}),
		LocationAccess(ZORA_HALL_LULU_ROOM_LEDGE, {[] {return PiratesFortressAccess && GoronMask && DekuMask && MountainTitle;}}),
		//LocationAccess(ZORA_HALL_SCRUB_BUY, {[] {return;}}),
		//LocationAccess(ZORA_HALL, {[] {return;}}),

		});


	/*--------------------------
	|         DUNGEONS         |
	---------------------------*/

	areaTable[WOODFALL_TEMPLE] = Area("Woodfall Temple", "Woodfall Temple", WOODFALL_TEMPLE, {}, {
		//Locations
		LocationAccess(WOODFALL_TEMPLE_HEROS_BOW_CHEST, {[] {return DekuMask && WoodfallTempleAccess && OneWoodfallKey;}}),
		LocationAccess(WOODFALL_TEMPLE_MAP_CHEST, {[] {return WoodfallTempleAccess;}}),
		LocationAccess(WOODFALL_TEMPLE_COMPASS_CHEST, {[] {return WoodfallTempleAccess && (Arrows || OneWoodfallKey);}}),
		LocationAccess(WOODFALL_TEMPLE_BOSS_KEY_CHEST, {[] {return WoodfallTempleAccess && Arrows && DekuMask;}}),
		LocationAccess(WOODFALL_TEMPLE_SMALL_KEY_CHEST, {[] {return WoodfallTempleAccess && (DekuMask || Hookshot);}}),
		LocationAccess(ODOLWAS_REMAINS, {[] {return WoodfallTempleAccess && Arrows && BossKeyWoodfallTemple && DekuMask;}}),
		LocationAccess(ODOLWA_HEART_CONTAINER, {[] {return WoodfallTempleAccess && Arrows && BossKeyWoodfallTemple && DekuMask;}}),
		//StrayFairies
		LocationAccess(WF_SF_ENTRANCE_FAIRY, {[] {return WoodfallTempleAccess;}}),
		LocationAccess(WF_SF_ENTRANCE_PLATFORM, {[] {return WoodfallTempleAccess && (DekuMask || Hookshot);}}),
		LocationAccess(WF_SF_MAIN_ROOM_BUBBLE, {[] {return WoodfallTempleAccess && ((DekuMask && Arrows) || (DekuMask && OneWoodfallKey));}}),
		LocationAccess(WF_SF_MAIN_ROOM_SWITCH, {[] {return WoodfallTempleAccess && DekuMask && (Arrows || OneWoodfallKey);}}),
		LocationAccess(WF_SF_PRE_BOSS_LOWER_RIGHT_BUBBLE, {[] {return WoodfallTempleAccess && Arrows && DekuMask;}}),
		LocationAccess(WF_SF_PRE_BOSS_UPPER_RIGHT_BUBBLE, {[] {return WoodfallTempleAccess&& Arrows&& DekuMask;}}),
		LocationAccess(WF_SF_PRE_BOSS_UPPER_LEFT_BUBBLE, {[] {return WoodfallTempleAccess&& Arrows&& DekuMask;}}),
		LocationAccess(WF_SF_PRE_BOSS_PILLAR_BUBBLE, {[] {return WoodfallTempleAccess && Arrows && DekuMask;}}),
		LocationAccess(WF_SF_DEKU_BABA, {[] {return WoodfallTempleAccess && (DekuMask || Hookshot);}}),
		LocationAccess(WF_SF_POISON_WATER_BUBBLE, {[] {return WoodfallTempleAccess && Arrows && DekuMask && GreatFairyMask;}}),
		LocationAccess(WF_SF_SKULLTULA, {[] {return WoodfallTempleAccess && ((DekuMask && Arrows) || (DekuMask && OneWoodfallKey));}}),
		LocationAccess(WF_SF_DARK_ROOM, {[] {return WoodfallTempleAccess && ((DekuMask && Arrows) || (DekuMask && OneWoodfallKey));}}),
		LocationAccess(WF_SF_JAR_FAIRY, {[] {return WoodfallTempleAccess && DekuMask && Hookshot;}}),
		LocationAccess(WF_SF_BRIDGE_ROOM_BEEHIVE, {[] {return WoodfallTempleAccess && ((Arrows && DekuMask) || (DekuMask && OneWoodfallKey && MagicMeter));}}),
		LocationAccess(WF_SF_PLATFORM_ROOM_BEEHIVE, {[] {return WoodfallTempleAccess && ((Arrows && DekuMask) || (DekuMask && MagicMeter) || (Hookshot && GreatFairyMask) || (DekuMask && GreatFairyMask && ZoraMask));}}),

		});

	areaTable[SNOWHEAD_TEMPLE] = Area("Snowhead Temple", "Snowhead Temple", SNOWHEAD_TEMPLE, {}, {
		//Locations
		LocationAccess(SNOWHEAD_TEMPLE_FIRE_ARROW_CHEST, {[] {return true;}}),
		LocationAccess(SNOWHEAD_TEMPLE_MAP_CHEST, {[] {return SnowheadTempleAccess && EnterSnowheadTemple;}}),
		LocationAccess(SNOWHEAD_TEMPLE_COMPASS_CHEST, {[] {return SnowheadTempleAccess && EnterSnowheadTemple;}}),
		LocationAccess(SNOWHEAD_TEMPLE_BOSS_KEY_CHEST, {[] {return SnowheadTempleAccess && UseFireArrow;}}),
		LocationAccess(SNOWHEAD_TEMPLE_BLOCK_ROOM_CHEST, {[] {return SnowheadTempleAccess && EnterSnowheadTemple;}}),
		LocationAccess(SNOWHEAD_TEMPLE_ICICLE_ROOM_CHEST, {[] {return SnowheadTempleAccess && EnterSnowheadTemple;}}),
		LocationAccess(SNOWHEAD_TEMPLE_BRIDGE_ROOM_CHEST, {[] {return SnowheadTempleAccess && EnterSnowheadTemple;}}),
		LocationAccess(GOHTS_REMAINS, {[] {return SnowheadTempleAccess && GoronMask && BossKeySnowheadTemple && UseFireArrow && MagicMeter;}}),
		LocationAccess(GOHT_HEART_CONTAINER, {[] {return SnowheadTempleAccess && GoronMask && BossKeySnowheadTemple && UseFireArrow && MagicMeter;}}),
		//StrayFairies
		LocationAccess(SH_SF_SNOW_ROOM_BUBBLE, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && GreatFairyMask && LensOfTruth && ((GoronMask && UseFireArrow) || (Hookshot && ZoraMask && OneSnowheadKey && UseFireArrow) || (Hookshot && UseFireArrow && OneSnowheadKey && ScarecrowSong));}}),
		LocationAccess(SH_SF_CEILING_BUBBLE, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && GreatFairyMask && LensOfTruth && ((UseFireArrow) || (Explosives && Arrows && TwoSnowheadKeys) || (Hookshot && Explosives && OneSnowheadKey));}}),
		LocationAccess(SH_SF_DINOLFOS_1, {[] {return SnowheadTempleAccess && UseFireArrow && GoronMask;}}),
		LocationAccess(SH_SF_DINOLFOS_2, {[] {return SnowheadTempleAccess && UseFireArrow && GoronMask;}}),
		LocationAccess(SH_SF_BRIDGE_ROOM_LEDGE_BUBBLE, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && ((GreatFairyMask && Arrows) || (Hookshot && GreatFairyMask));}}),
		LocationAccess(SH_SF_BRIDGE_ROOM_PILLAR_BUBBLE, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && ((GreatFairyMask && Arrows) || (Hookshot && GreatFairyMask));}}),
		LocationAccess(SH_SF_MAP_ROOM_FAIRY, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && ((Hookshot) || (Explosives && TwoSnowheadKeys) || (GoronMask && MagicMeter));}}),
		LocationAccess(SH_SF_MAP_ROOM_LEDGE, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && ((Hookshot && ScarecrowSong) || (Hookshot && UseFireArrow) || (Hookshot && Explosives && TwoSnowheadKeys) || (Hookshot && ZoraMask && Explosives && OneSnowheadKey));}}),
		LocationAccess(SH_SF_BASEMENT, {[] {return SnowheadTempleAccess && GoronMask && MagicMeter && (Hookshot || (Explosives && TwoSnowheadKeys));}}),
		LocationAccess(SH_SF_TWIN_BLOCK, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && (Hookshot || (OneSnowheadKey && UseFireArrow));}}),
		LocationAccess(SH_SF_ICICLE_ROOM_WALL, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && ((Explosives && OneSnowheadKey) || (GoronMask && OneSnowheadKey && UseFireArrow) || (Hookshot && GoronMask && Explosives));}}),
		LocationAccess(SH_SF_MAIN_ROOM_WALL, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && (UseFireArrow || (Hookshot && ScarecrowSong));}}),
		LocationAccess(SH_SF_PILLAR_FREEZARDS, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && UseFireArrow;}}),
		LocationAccess(SH_SF_ICE_PUZZLE, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && UseFireArrow && (OneSnowheadKey || Hookshot || ZoraMask);}}),
		LocationAccess(SH_SF_CRATE, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && (Hookshot || (GoronMask && ZoraMask) || (ZoraMask && Explosives) || (GoronMask && OneSnowheadKey && AnyBombBag && UseFireArrow) || (GoronMask && GreatFairyMask && OneSnowheadKey && AnyBombBag));}}),

		});

	areaTable[GBT] = Area("Great Bay Temple", "Great Bay Temple", GBT, {}, {
		//Locations
		LocationAccess(GBT_ICE_ARROW_CHEST, {[] {return ZoraMask && Hookshot && GreatBayTempleAccess && OneGreatBayKey;}}),
		LocationAccess(GBT_MAP_CHEST, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot;}}),
		LocationAccess(GBT_COMPASS_CHEST, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot;}}),
		LocationAccess(GBT_BOSS_KEY_CHEST, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot;}}),
		LocationAccess(GBT_SMALL_KEY_CHEST, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot;}}),
		LocationAccess(GYORGS_REMAINS, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot && BossKeyGreatBayTemple && UseIceArrow && UseFireArrow && MagicMeter;}}),
		LocationAccess(GYORG_HEART_CONTAINER, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot && BossKeyGreatBayTemple && UseIceArrow && UseFireArrow && MagicMeter;}}),
		//StrayFairies
		LocationAccess(GBT_SF_SKULLTULA, {[] {return GreatBayTempleAccess && Hookshot;}}),
		LocationAccess(GBT_SF_WATER_CONTROL_UNDERWATER_BUBBLE, {[] {return GreatBayTempleAccess && Hookshot && (ZoraMask || GreatFairyMask);}}),
		LocationAccess(GBT_SF_WATERWHEEL_ROOM_LOWER, {[] {return GreatBayTempleAccess && Hookshot && ZoraMask && GBTReverseWaterDirection;}}),
		LocationAccess(GBT_SF_WATERWHEEL_ROOM_UPPER, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot && UseIceArrow;}}),
		LocationAccess(GBT_SF_GREEN_VALVE, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot && UseIceArrow;}}),
		LocationAccess(GBT_SF_SEESAW_ROOM, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot && GBTReverseWaterDirection && UseFireArrow;}}),
		LocationAccess(GBT_SF_ENTRANCE_TORCHES, {[] {return GreatBayTempleAccess && Hookshot;}}),
		LocationAccess(GBT_SF_BIO_BABAS, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot;}}),
		LocationAccess(GBT_SF_UNDERWATER_BARREL, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot && GBTReverseWaterDirection;}}),
		LocationAccess(GBT_SF_WHIRLPOOL_JAR, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot;}}),
		LocationAccess(GBT_SF_WHIRLPOOL_BARREL, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot;}}),
		LocationAccess(GBT_SF_DEXIHANDS_JAR, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot;}}),
		LocationAccess(GBT_SF_LEDGE_JAR, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot && (GreatFairyMask || UseIceArrow);}}),
		LocationAccess(GBT_SF_PRE_BOSS_ROOM_BUBBLE, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot && UseIceArrow;}}),
		LocationAccess(GBT_SF_PRE_BOSS_ROOM_UNDERWATER_BUBBLE, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot && UseIceArrow;}}),

		});

	areaTable[STONE_TOWER_TEMPLE] = Area("Stone Tower Temple", "Stone Tower Temple", STONE_TOWER_TEMPLE, {}, {
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_MAP_CHEST, {[] {return StoneTowerTempleAcccess && ((MirrorShield && Explosives &&GoronMask) || (GoronMask && Explosives && UseLightArrow) || (ZoraMask && OneStoneTowerKey && UseLightArrow));}}),
		LocationAccess(STONE_TOWER_TEMPLE_COMPASS_CHEST, {[] {return StoneTowerTempleAcccess && ((MirrorShield && OneStoneTowerKey && GoronMask && ZoraMask) || UseLightArrow);}}),
		LocationAccess(STONE_TOWER_TEMPLE_BOSS_KEY_CHEST, {[] {return InvertedStoneTowerTempleAccess && UseLightArrow && DekuMask && OneStoneTowerKey && Hookshot;}}),
		LocationAccess(STONE_TOWER_TEMPLE_ARMOS_ROOM_CHEST, {[] {return StoneTowerTempleAcccess && ((MirrorShield && Explosives && GoronMask) || (GoronMask && Explosives && UseLightArrow) || (ZoraMask && OneStoneTowerKey && UseLightArrow));}}),
		LocationAccess(STONE_TOWER_TEMPLE_EYEGORE_ROOM_CHEST, {[] {return StoneTowerTempleAcccess && ((ZoraMask && UseLightArrow) || (Explosives && OneStoneTowerKey && GoronMask));}}),
		LocationAccess(STONE_TOWER_TEMPLE_UPDRAFT_ROOM_CHEST, {[] {return InvertedStoneTowerTempleAccess && UseLightArrow && DekuMask;}}),
		LocationAccess(STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM_CHEST, {[] {return InvertedStoneTowerTempleAccess && Hookshot && OneStoneTowerKey && UseLightArrow && ElegyOfEmptiness;}}),
		LocationAccess(STONE_TOWER_TEMPLE_LIGHT_ARROW_CHEST, {[] {return StoneTowerTempleAcccess;}}),
		LocationAccess(STONE_TOWER_TEMPLE_GIANTS_MASK_CHEST, {[] {return InvertedStoneTowerTempleAccess && Hookshot && UseLightArrow && BossKeyStoneTowerTemple;}}),
		LocationAccess(TWINMOLDS_REMAINS, {[] {return InvertedStoneTowerTempleAccess && Hookshot && UseLightArrow && BossKeyStoneTowerTemple && GiantsMask;}}),
		LocationAccess(TWINMOLD_HEART_CONTAINER, {[] {return InvertedStoneTowerTempleAccess && Hookshot && UseLightArrow && BossKeyStoneTowerTemple && GiantsMask;}}),
		//StrayFairies
		LocationAccess(ST_SF_MIRROR_SUN_BLOCK, {[] {return StoneTowerTempleAcccess && ((MirrorShield && GoronMask && ZoraMask && Explosives && TwoStoneTowerKeys) || (OneStoneTowerKey && UseLightArrow));}}),
		LocationAccess(ST_SF_LAVA_ROOM_LEDGE, {[] {return StoneTowerTempleAcccess && DekuMask && ((OneStoneTowerKey && UseLightArrow) || (MirrorShield && GoronMask && ZoraMask && Explosives && TwoStoneTowerKeys));}}),
		LocationAccess(ST_SF_LAVA_ROOM_FIRE_RING, {[] {return StoneTowerTempleAcccess && GoronMask && ((DekuMask && MirrorShield && Explosives && TwoStoneTowerKeys) || (OneStoneTowerKey && UseLightArrow));}}),
		LocationAccess(ST_SF_EYEGORE, {[] {return StoneTowerTempleAcccess && ((DekuMask && MirrorShield && GoronMask && ZoraMask && Explosives && TwoStoneTowerKeys) || (OneStoneTowerKey && UseLightArrow));}}),
		LocationAccess(ST_SF_UPDRAFT_FIRE_RING, {[] {return StoneTowerTempleAcccess && InvertedStoneTowerTempleAccess && ZoraMask && DekuMask && UseLightArrow;}}),
		LocationAccess(ST_SF_MIRROR_SUN_SWITCH, {[] {return StoneTowerTempleAcccess && ((MirrorShield && Explosives && TwoStoneTowerKeys && GoronMask && ZoraMask) || (OneStoneTowerKey && UseLightArrow));}}),
		LocationAccess(ST_SF_BOSS_WARP, {[] {return InvertedStoneTowerTempleAccess && UseLightArrow && BossKeyStoneTowerTemple && GiantsMask;}}),
		LocationAccess(ST_SF_WIZZROBE, {[] {return InvertedStoneTowerTempleAccess && DekuMask && Hookshot && GoronMask && OneStoneTowerKey && UseLightArrow;}}),
		LocationAccess(ST_SF_DEATH_ARMOS, {[] {return InvertedStoneTowerTempleAccess && StoneTowerTempleAcccess && DekuMask && Hookshot && GoronMask && OneStoneTowerKey && UseLightArrow;}}),
		LocationAccess(ST_SF_UPDRAFT_FROZEN_EYE, {[] {return InvertedStoneTowerTempleAccess && UseFireArrow && UseLightArrow && (DekuMask || Hookshot);}}),
		LocationAccess(ST_SF_THIN_BRIDGE, {[] {return StoneTowerTempleAcccess && DekuMask && GoronMask && InvertedStoneTowerTempleAccess && ThreeStoneTowerKeys && UseLightArrow;}}),
		LocationAccess(ST_SF_BASEMENT_LEDGE, {[] {return StoneTowerTempleAcccess && ((GoronMask && Explosives) || (ZoraMask && OneStoneTowerKey && UseLightArrow));}}),
		LocationAccess(ST_SF_STATUE_EYE, {[] {return StoneTowerTempleAcccess && Arrows;}}),
		LocationAccess(ST_SF_UNDERWATER, {[] {return StoneTowerTempleAcccess && ZoraMask && UseLightArrow && InvertedStoneTowerTempleAccess && DekuMask;}}),
		LocationAccess(ST_SF_BRIDGE_CRYSTAL, {[] {return StoneTowerTempleAcccess && ZoraMask && UseLightArrow;}}),

		});

	areaTable[PIRATE_FORTRESS] = Area("Pirates Fortress", "Pirates Fortress", PIRATE_FORTRESS, {}, {
		//Locations
		LocationAccess(PF_INTERIOR_HOOKSHOT_CHEST, {[] {return PiratesFortressAccess;}}),
		LocationAccess(PF_INT_LOWER_CHEST, {[] {return PiratesFortressAccess && Hookshot ;}}),
		LocationAccess(PF_INT_UPPER_CHEST, {[] {return PiratesFortressAccess && Hookshot;}}),
		LocationAccess(PF_INT_TANK_CHEST, {[] {return PiratesFortressAccess && Hookshot;}}),
		LocationAccess(PF_INT_GUARD_ROOM_CHEST, {[] {return PiratesFortressAccess && Hookshot;}}),
		LocationAccess(PF_CAGE_ROOM_SHALLOW_CHEST, {[] {return PiratesFortressAccess && GoronMask;}}),
		LocationAccess(PF_MAZE_CHEST, {[] {return PiratesFortressAccess && GoronMask;}}),
		LocationAccess(PF_SEWER_CAGE, {[] {return PiratesFortressAccess && GoronMask;}}),
		LocationAccess(PF_EXTERIOR_LOG_CHEST, {[] {return PiratesFortressAccess;}}),
		LocationAccess(PF_EXTERIOR_SAND_CHEST, {[] {return PiratesFortressAccess;}}),
		LocationAccess(PF_EXTERIOR_CORNER_CHEST, {[] {return PiratesFortressAccess;}}),

		});

	areaTable[BENEATH_THE_WELL] = Area("Beneath The Well", "Beneath The Well", BENEATH_THE_WELL, {}, {
		//Locations
		LocationAccess(BENEATH_THE_WELL_MIRROR_SHIELD_CHEST, {[] {return IkanaCanyonAccess && ((GibdosMask && Bugs && AnyBottle && UseLightArrow) || (GibdosMask && Fish && BigPoe && AnyBottle && AnyMagicBean) || (UseFireArrow && UseLightArrow));}}),
		LocationAccess(WELL_LEFT_PATH_CHEST, {[] {return IkanaCanyonAccess && GibdosMask && Bugs && SpringWater && AnyBluePotion && LensOfTruth && MagicMeter;}}),
		LocationAccess(WELL_RIGHT_PATH_CHEST, {[] {return IkanaCanyonAccess && GibdosMask && Bugs && Fish && AnyMagicBean;}}),
		});

	areaTable[IKANA_CASTLE] = Area("Ikana Castle", "Ikana Castle", IKANA_CASTLE, {}, {
		//Locations
		LocationAccess(IKANA_CASTLE_PILLAR, {[] {return IkanaCanyonAccess && DekuMask && UseFireArrow && ((UseLightArrow && LensOfTruth) || (MirrorShield && LensOfTruth));}}),
		LocationAccess(IKANA_CASTLE_IKANA_KING, {[] {return IkanaCanyonAccess && MirrorShield && Fighting && UseFireArrow;}}),

		});

	areaTable[SECRET_SHRINE] = Area("Secret Shrine", "Secret Shrine", SECRET_SHRINE, {}, {
		//Locations
		LocationAccess(SECRET_SHRINE_DINOLFOS_CHEST, {[] {return EastAccess && Fighting && UseLightArrow;}}),
		LocationAccess(SECRET_SHRINE_WIZZROBE_CHEST, {[] {return EastAccess && Fighting && UseLightArrow;}}),
		LocationAccess(SECRET_SHRINE_WART_CHEST, {[] {return EastAccess && Fighting && UseLightArrow;}}),
		LocationAccess(SECRET_SHRINE_GARO_CHEST, {[] {return EastAccess && Fighting && UseLightArrow;}}),
		LocationAccess(SECRET_SHRINE_FINAL_CHEST, {[] {return EastAccess && Fighting && UseLightArrow;}}),

		});

	areaTable[THE_MOON] = Area("The Moon", "The Moon", THE_MOON, {}, {
		//Locations
		LocationAccess(THE_MOON_DEKU_TRIAL_BONUS, {[] {return MoonAccess && DekuMask && OneMask;}}),
		LocationAccess(THE_MOON_GORON_TRIAL_BONUS, {[] {return MoonAccess && GoronMask && TwoMasks && MagicMeter;}}),
		LocationAccess(THE_MOON_ZORA_TRIAL_BONUS, {[] {return MoonAccess && ZoraMask && ThreeMasks;}}),
		LocationAccess(THE_MOON_LINK_TRIAL_BONUS, {[] {return MoonAccess && Explosives && UseFireArrow && Hookshot && MagicMeter && Arrows && FourMasks;}}),
		LocationAccess(THE_MOON_GARO_CHEST, {[] {return MoonAccess && Hookshot;}}),
		LocationAccess(THE_MOON_IRON_KNUCKLE_CHEST, {[] {return MoonAccess && Hookshot;}}),
		LocationAccess(THE_MOON_MAJORA_CHILD, {[] {return MoonAccess && AllMasks;}}),

		});

	areaTable[SSH] = Area("Swamp Spider House", "Swamp Spider House", SSH, {}, {
		//Locations
		LocationAccess(SSH_MAIN_ROOM_NEAR_CEILING, {[] {return PoisonSwampAccess && (Hookshot || (DekuMask && Arrows) || (DekuMask && MagicMeter) || (ZoraMask) || (DekuMask && AnyBombBag));}}),
		LocationAccess(SSH_MAIN_ROOM_WATER, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_MAIN_ROOM_LOWER_LEFT_SOIL, {[] {return PoisonSwampAccess && Bugs;}}),
		LocationAccess(SSH_MAIN_ROOM_LOWER_RIGHT_SOIL, {[] {return PoisonSwampAccess && Bugs;}}),
		LocationAccess(SSH_MAIN_ROOM_UPPER_SOIL, {[] {return PoisonSwampAccess && Bugs;}}),
		LocationAccess(SSH_MAIN_ROOM_PILLAR, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_MAIN_ROOM_UPPER_PILLAR, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_MAIN_ROOM_JAR, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_MONUMENT_ROOM_CRATE_1, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_MONUMENT_ROOM_CRATE_2, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_MONUMENT_ROOM_TORCH, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_MONUMENT_ROOM_ON_MONUMENT, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_MONUMENT_ROOM_LOWER_WALL, {[] {return PoisonSwampAccess && (Hookshot || ZoraMask || (GoronMask && AnyMagicBean && WaterForBeans) || (Explosives && AnyMagicBean && WaterForBeans));}}),
		LocationAccess(SSH_GOLD_ROOM_NEAR_CEILING, {[] {return PoisonSwampAccess && (Hookshot || ZoraMask || (DekuMask && WaterForBeans));}}),
		LocationAccess(SSH_GOLD_ROOM_PILLAR, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_GOLD_ROOM_BEEHIVE, {[] {return PoisonSwampAccess && (Arrows || Hookshot || ZoraMask || (DekuMask && MagicMeter));}}),
		LocationAccess(SSH_GOLD_ROOM_WALL, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_POT_ROOM_JAR, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_POT_ROOM_POT_1, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_POT_ROOM_POT_2, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_POT_ROOM_BEHIND_VINES, {[] {return PoisonSwampAccess && AnySword;}}),
		LocationAccess(SSH_POT_ROOM_WALL, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_POT_ROOM_BEEHIVE_1, {[] {return PoisonSwampAccess && (Arrows || Hookshot || ZoraMask || (DekuMask && MagicMeter));}}),
		LocationAccess(SSH_POT_ROOM_BEEHIVE_2, {[] {return PoisonSwampAccess && (Arrows || Hookshot || ZoraMask || (DekuMask && MagicMeter));}}),
		LocationAccess(SSH_TREE_ROOM_TREE_1, {[] {return PoisonSwampAccess && SwampSpiderhouseTreeRoom;}}),
		LocationAccess(SSH_TREE_ROOM_TREE_2, {[] {return PoisonSwampAccess && SwampSpiderhouseTreeRoom;}}),
		LocationAccess(SSH_TREE_ROOM_TREE_3, {[] {return PoisonSwampAccess && SwampSpiderhouseTreeRoom;}}),
		LocationAccess(SSH_TREE_ROOM_GRASS_1, {[] {return PoisonSwampAccess && SwampSpiderhouseTreeRoom;}}),
		LocationAccess(SSH_TREE_ROOM_GRASS_2, {[] {return PoisonSwampAccess && SwampSpiderhouseTreeRoom;}}),
		LocationAccess(SSH_TREE_ROOM_BEEHIVE, {[] {return PoisonSwampAccess && SwampSpiderhouseTreeRoom && (Arrows || Hookshot || ZoraMask || (DekuMask && MagicMeter));}}),

		});

	areaTable[OSH] = Area("Ocean Spider House", "Ocean Spider House", OSH, {}, {
		//Locations
		LocationAccess(OSH_ENTRANCE_LEFT_WALL, {[] {return WestAccess && Explosives && ExitOceanSpiderHouse && (Hookshot || ZoraMask);}}),
		LocationAccess(OSH_ENTRANCE_RIGHT_WALL, {[] {return WestAccess && Explosives && ExitOceanSpiderHouse && (Hookshot || ZoraMask);}}),
		LocationAccess(OSH_ENTRANCE_WEB, {[] {return WestAccess && Explosives && ExitOceanSpiderHouse && ((Hookshot && UseFireArrow) || (ZoraMask && UseFireArrow));}}),
		LocationAccess(OSH_LIBRARY_HOLE_BEHIND_PICTURE, {[] {return OceanSkulltulas && Hookshot;}}),
		LocationAccess(OSH_LIBRARY_HOLE_BEHIND_CABINET, {[] {return OceanSkulltulas && (Hookshot || ZoraMask);}}),
		LocationAccess(OSH_LIBRARY_ON_CORNER_BOOKSHELF, {[] {return OceanSkulltulas;}}),
		LocationAccess(OSH_LIBRARY_CEILING_EDGE, {[] {return OceanSkulltulas && (Hookshot || ZoraMask);}}),
		LocationAccess(OSH_LIBRARY_BEHIND_BOOKCASE_1, {[] {return OceanSkulltulas;}}),
		LocationAccess(OSH_LIBRARY_BEHIND_BOOKCASE_2, {[] {return OceanSkulltulas;}}),
		LocationAccess(OSH_LIBRARY_BEHIND_PICTURE, {[] {return OceanSkulltulas;}}),
		LocationAccess(OSH_SECOND_ROOM_CEILING_EDGE, {[] {return OceanSkulltulas && (Hookshot || ZoraMask);}}),
		LocationAccess(OSH_SECOND_ROOM_CEILING_PLANK, {[] {return OceanSkulltulas && (Hookshot || ZoraMask);}}),
		LocationAccess(OSH_SECOND_ROOM_JAR, {[] {return OceanSkulltulas;}}),
		LocationAccess(OSH_SECOND_ROOM_WEBBED_HOLE, {[] {return OceanSkulltulas && Hookshot;}}),
		LocationAccess(OSH_SECOND_ROOM_WEBBED_POT, {[] {return OceanSkulltulas;}}),
		LocationAccess(OSH_SECOND_ROOM_UPPER_POT, {[] {return OceanSkulltulas;}}),
		LocationAccess(OSH_SECOND_ROOM_BEHIND_SKULL_1, {[] {return OceanSkulltulas && (Hookshot || ZoraMask);}}),
		LocationAccess(OSH_SECOND_ROOM_BEHIND_SKULL_2, {[] {return OceanSkulltulas && (Hookshot || ZoraMask);}}),
		LocationAccess(OSH_SECOND_ROOM_LOWER_POT, {[] {return OceanSkulltulas;}}),
		LocationAccess(OSH_STORAGE_ROOM_CEILING_WEB, {[] {return OceanSkulltulas && UseFireArrow;}}),
		LocationAccess(OSH_STORAGE_ROOM_BEHIND_CRATE, {[] {return OceanSkulltulas && (Hookshot || ZoraMask || GoronMask);}}),
		LocationAccess(OSH_STORAGE_ROOM_BEHIND_BOAT, {[] {return OceanSkulltulas;}}),
		LocationAccess(OSH_STORAGE_ROOM_CRATE, {[] {return OceanSkulltulas;}}),
		LocationAccess(OSH_STORAGE_ROOM_JAR, {[] {return OceanSkulltulas && Hookshot;}}),
		LocationAccess(OSH_COLORED_SKULLS_CEILING_EDGE, {[] {return OceanSkulltulas && (Hookshot || ZoraMask);}}),
		LocationAccess(OSH_COLORED_SKULLS_CHANDELIER_1, {[] {return OceanSkulltulas;}}),
		LocationAccess(OSH_COLORED_SKULLS_CHANDELIER_2, {[] {return OceanSkulltulas;}}),
		LocationAccess(OSH_COLORED_SKULLS_CHANDELIER_3, {[] {return OceanSkulltulas;}}),
		LocationAccess(OSH_COLORED_SKULLS_BEHIND_PICTURE, {[] {return OceanSkulltulas && (Hookshot || ZoraMask);}}),
		LocationAccess(OSH_COLORED_SKULLS_POT, {[] {return OceanSkulltulas;}}),

		});
}

namespace Areas {
	static std::array < const AreaKey, 38> allAreas = {
		ROOT,
		DEKU_PALACE,
		E_CLOCK_TOWN,
		GORON_VILLAGE,
		GREAT_BAY_COAST,
		IKANA_CANYON,
		IKANA_GRAVEYARD,
		LAUNDRY_POOL,
		MILK_ROAD,
		MOUNTAIN_VILLAGE,
		N_CLOCK_TOWN,
		ROAD_TO_SNOWHEAD,
		PINNACLE_ROCK,
		ROAD_TO_IKANA,
		ROAD_TO_SOUTHERN_SWAMP,
		ROMANI_RANCH,
		S_CLOCK_TOWN,
		SNOWHEAD,
		SOUTHERN_SWAMP,
		STOCKPOTINN,
		STONE_TOWER,
		TERMINA_FIELD,
		TWIN_ISLANDS,
		W_CLOCK_TOWN,
		WOODFALL,
		ZORA_CAPE,
		ZORA_HALL,
		WOODFALL_TEMPLE,
		SNOWHEAD_TEMPLE,
		GBT,
		STONE_TOWER_TEMPLE,
		PIRATE_FORTRESS,
		BENEATH_THE_WELL,
		IKANA_CASTLE,
		SECRET_SHRINE,
		THE_MOON,
		SSH,
		OSH,
	};

	void AccessReset() {
		for (const AreaKey area : allAreas) {
			AreaTable(area)->ResetVariables();
		}
	}

	void ResetAllLocations() {
		for (const AreaKey area : allAreas) {
			AreaTable(area)->ResetVariables();
			//Erase item from every locatoin in this area
			for (LocationAccess& locPair : AreaTable(area)->locations) {
				LocationKey location = locPair.GetLocation();
				Location(location)->ResetVariables();
			}
		}
	}
}//namespace Areas

	Area* AreaTable(const AreaKey areaKey) {
		if (areaKey > KEY_ENUM_MAX) {
			printf("\x1b[1;1HERROR: AREAKEY TOO BIG");
		}
		return &(areaTable[areaKey]);
	}
