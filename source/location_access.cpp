#include "location_access.hpp"

#include "dungeon.hpp"
#include "item_list.hpp"
#include "item_location.hpp"
#include "item_pool.hpp"
#include "logic.hpp"
#include "settings.hpp"
#include "spoiler_log.hpp"
#include "entrance.hpp"

#include <unistd.h>

using namespace Logic;
using namespace Settings;

bool LocationAccess::CheckConditionAtDay(bool& day, bool& time) const{

	IsDay1Day = false;
	IsDay1Night =false;
	IsDay2Day = false;
	IsDay2Night =false;
	IsDay3Day = false;
	IsDay3Night =false;
	
	day = true;
	time = true;

	UpdateHelpers();
	return GetConditionsMet();
}

bool LocationAccess::ConditionsMet() const {
	Area* parentRegion = AreaTable(Location(location)->GetParentRegionKey());
	bool conditionsMet = false;
	
	if(
	(parentRegion->day1Day && CheckConditionAtDay(IsDay1Day, AtDay)) ||
	(parentRegion->day2Day && CheckConditionAtDay(IsDay2Day, AtDay)) ||
	(parentRegion->day3Day && CheckConditionAtDay(IsDay3Day, AtDay)) ||
	(parentRegion->day1Night && CheckConditionAtDay(IsDay1Night, AtNight)) ||
	(parentRegion->day2Night && CheckConditionAtDay(IsDay2Night, AtNight)) ||
	(parentRegion->day3Night && CheckConditionAtDay(IsDay3Night, AtNight)) )
	{
		conditionsMet = true;
	}
	
	return conditionsMet;// && CanBuy();
}

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
		OtherCondition = Logic::BombBag20;
	}
	return SufficientWallet && OtherCondition;
}

Area::Area() = default;
Area::Area(std::string regionName_, std::string scene_, u32 hintKey_, 
		std::vector<EventAccess> events_,
		std::vector<LocationAccess> locations_, 
		std::list<Entrance> exits_ )
	: regionName(std::move(regionName_)),
	scene(std::move(scene_)),
	hintKey(hintKey_),
	events(std::move(events_)),
	locations(std::move(locations_)),
	exits(std::move(exits_)) {}

Area::~Area() = default;

bool Area::UpdateEvents() {

	if (timePass) {
		if(Day1()){
			day1Day = true;
			day1Night = true;
			AreaTable(ROOT)->day1Day = true;
			AreaTable(ROOT)->day1Night = true;
		}
		if(Day2()){
			day2Day = true;
			day2Night = true;
			AreaTable(ROOT)->day2Day = true;
			AreaTable(ROOT)->day2Night = true;
		}
		if(Day3()){
			day3Day = true;
			day3Night = true;
			AreaTable(ROOT)->day3Day = true;
			AreaTable(ROOT)->day3Night = true;
		}
	}

	bool eventsUpdated = false;

	for (EventAccess& event : events)
	{
		//if event happened dont check it.
		if (event.GetEvent()) {
			continue;
		}
		//check condition on all days/nights
		if((day1Day && event.CheckConditionAtDay(day1Day, AtDay)) ||
		   (day2Day && event.CheckConditionAtDay(day2Day, AtDay)) ||
		   (day3Day && event.CheckConditionAtDay(day3Day, AtDay)) ||
		   (day1Night && event.CheckConditionAtDay(day1Night, AtNight)) ||
		   (day2Night && event.CheckConditionAtDay(day2Night, AtNight)) ||
		   (day3Night && event.CheckConditionAtDay(day3Night, AtNight)) ){
			event.EventOccurred();
			eventsUpdated=true;
		}
	}
	return eventsUpdated;
}

void Area::AddExit(AreaKey parentKey, AreaKey newExitKey, ConditionFn condition) {
  Entrance newExit = Entrance(newExitKey, {condition});
  newExit.SetParentRegion(parentKey);
  exits.push_front(newExit);
}

//The exit will be completely removed from this area
void Area::RemoveExit(Entrance* exitToRemove) {
  exits.remove_if([exitToRemove](const auto exit){return &exit == exitToRemove;});
}

//The exit will still exist in the area, but won't be accessible
void Area::DisconnectExit(AreaKey exitToDisconnect) {
  for (auto& exit : exits) {
    if (exit.GetAreaKey() == exitToDisconnect) {
      exit.Disconnect();
      return;
    }
  }
}

void Area::SetAsPrimary(AreaKey exitToBePrimary) {
  for (auto& exit : exits) {
    if (exit.GetAreaKey() == exitToBePrimary) {
      exit.SetAsPrimary();
      return;
    }
  }
}

Entrance* Area::GetExit(AreaKey exitToReturn) {
  for (auto& exit : exits) {
    if (exit.GetAreaKey() == exitToReturn) {
      return &exit;
    }
  }
  auto message = "ERROR: EXIT " + AreaTable(exitToReturn)->regionName + " DOES NOT EXIST IN " + this->regionName;
  CitraPrint(message);
  return nullptr;
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

	for (const auto& exit : exits) {
		if (!exit.GetConnectedRegion()->AllAccess()) {
		return false;
		}
	}

	return AllAccess();
}

bool Area::CheckAllAccess(const AreaKey exitKey) {
	if (!AllAccess()) {
		return false;
	}

	for(Entrance& exit: exits) {
		if(exit.GetAreaKey() == exitKey) {
			return exit.CheckConditionAtDayTime(Logic::IsDay1Day, Logic::AtDay) &&
			       exit.CheckConditionAtDayTime(Logic::IsDay2Day, Logic::AtDay) &&
				   exit.CheckConditionAtDayTime(Logic::IsDay2Day, Logic::AtDay) &&
				   exit.CheckConditionAtDayTime(Logic::IsDay1Night, Logic::AtNight) &&
			       exit.CheckConditionAtDayTime(Logic::IsDay2Night, Logic::AtNight) &&
				   exit.CheckConditionAtDayTime(Logic::IsDay3Night, Logic::AtNight);
		}
	}
	return false;
}


void Area::ResetVariables() {
	day1Day = false;
	day2Day = false;
	day3Day = false;
	day1Night = false;
	day2Night = false;
	day3Night = false;
	addedToPool = false;
	for (auto& exit : exits) {
		exit.RemoveFromPool();
	}
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
	areaTable.fill(Area("Invalid Area", "Invalid Area", NONE, {}, {}, {}));
						//Name,          Scene,      hint text, events, locations, exits
	areaTable[ROOT] = Area("Root", "", LINKS_POCKET, {}, { 
			//Locations
			LocationAccess(LINKS_POCKET, {[] {return true;}})
		}, 
		{
			//Exits
			Entrance(ROOT_EXITS, {[]{return true;}})
		});

	areaTable[ROOT_EXITS] = Area("Root Exits", "", NONE, {}, {}, {
		//Exits
		Entrance(S_CLOCK_TOWN, {[]{return IsDay1Day;}}),
	});

	/*--------------------------
	|    OVERWORLD             |
	---------------------------*/

	/*--------------------------
	|    Clock Town            |
	---------------------------*/
	
	areaTable[N_CLOCK_TOWN] = Area("North Clock Town", "North Clock Town", N_CLOCK_TOWN, {
		//Events
	}, 
	{
		//Locations
		//LocationAccess(N_CLOCK_TOWN_KEATON_QUIZ, {[] {return KeatonMask;}}),
		//LocationAccess(N_CLOCK_TOWN_TREE, {[] {return true;}}),
		LocationAccess(N_CLOCK_TOWN_OLD_LADY, {[] {return IsDay1Night && AtNight && (KokiriSword || HerosBow);}}),

	},
	{
		//Exits
		Entrance(CLOCK_TOWN_FAIRY_FOUNTAIN, {[]{return true;}}),
		Entrance(CLOCK_TOWN_DEKU_PLAYGROUND, {[]{return DekuMask;}}),
		Entrance(TERMINA_FIELD, {[]{return true;}}),//to-do add variables depending on future settings
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_FAIRY_FOUNTAIN] = Area("Clock Town Fairy Fountain", "Clock Town Fairy Fountain", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(N_CLOCK_TOWN_GREAT_FAIRY_DEKU, {[] {return ClockTownStrayFairy && (ZoraMask || DekuMask || GoronMask );}}),
		//LocationAccess(N_CLOCK_TOWN_GREAT_FAIRY_HUMAN, {[] {return ClockTownStrayFairy;}}),
		
	},
	{
		//Exits
		Entrance(N_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_DEKU_PLAYGROUND] = Area("Clock Town Deku Playground", "Clock Town Deku Playground", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(N_CLOCK_TOWN_DEKU_PLAYGROUND_3DAYS, {[] {return IsDay3Day && DekuMask;}}),
	},
	{
		//Exits
		Entrance(N_CLOCK_TOWN, {[]{return true;}})
	});

	areaTable[E_CLOCK_TOWN] = Area("East Clock Town", "East Clock Town", E_CLOCK_TOWN, {
		//Events
	}, 
	{
		//Locations
		LocationAccess(E_CLOCK_TOWN_CHEST, {[] {return true;}}),

	},
	{
		//Exits
		Entrance(N_CLOCK_TOWN, {[]{return true;}}),
		Entrance(TERMINA_FIELD, {[]{return true;}}),
		Entrance(CLOCK_TOWN_OBSERVATORY, {[]{return true;}}),
		Entrance(STOCKPOTINN, {[]{return true;}}),//to-Do StockPotInn Night Access
		Entrance(CLOCK_TOWN_BAR, {[]{return RomanisMask;}}),
		Entrance(CLOCK_TOWN_HONEY_DARLING, {[]{return true;}}),
		Entrance(CLOCK_TOWN_TREASURE_CHEST_GAME, {[]{return true;}}),
		Entrance(CLOCK_TOWN_ARCHERY, {[]{return true;}}),
		Entrance(CLOCK_TOWN_MAYOR_HOUSE, {[]{return true;}}),
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
	});
	
	areaTable[STOCKPOTINN] = Area("Stock Pot Inn", "Stock Pot Inn", STOCKPOTINN, {
		//Events
	}, 
	{
		//Locations
		//LocationAccess(STOCKPOTINN_RESERVATION, {[] {return GoronMask;}}),
		//LocationAccess(STOCKPOTINN_TOILET_HAND, {[] {return NightInnAccess && AnyPaper;}}),
	},
	{
		//Exits
		Entrance(STOCKPOTINN_GUEST_ROOM, {[]{return RoomKey;}}),
		Entrance(STOCKPOTINN_STAFF_ROOM, {[]{return IsDay3Night && AtNight;}}),
		Entrance(STOCKPOTINN_GRANDMA_ROOM, {[]{return true;}}),
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[STOCKPOTINN_GUEST_ROOM] = Area("StockPotInn Guest Room", "StockPotInn Guest Room", NONE, {
		//Events
		//Listen to Anju?
	},
	{
		//Locations
		LocationAccess(STOCKPOTINN_GUEST_ROOM_CHEST, {[] {return RoomKey;}}),
	},
	{
		//Exits
		Entrance(STOCKPOTINN, {[]{return true;}}),
	});

	areaTable[STOCKPOTINN_STAFF_ROOM] = Area("StockPotInn Staff Room", "StockPotInn Staff Room", NONE, {
		//Events
		//Anju & Kafei Reunited
		//Midnight Meeting
	},
	{
		//Locations
		//LocationAccess(STOCKPOTINN_MIDNIGHT_MEETING, {[] {return KafeisMask && NightInnAccess;}}),
		//LocationAccess(STOCKPOTINN_ANJU_AND_KAFEI, {[] {return LetterKafei && PendantOfMemories;}}),
		LocationAccess(STOCKPOTINN_STAFF_ROOM_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(STOCKPOTINN, {[]{return true;}}),
	});

	areaTable[STOCKPOTINN_GRANDMA_ROOM] = Area("StockPotInn Grandma's Room", "StockPotInn Grandma's Room", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(STOCKPOTINN_GRANDMA_SHORT_STORY, {[] {return AllNightMask;}}),
		//LocationAccess(STOCKPOTINN_GRANDMA_LONG_STORY, {[] {return AllNightMask;}}),
	},
	{
		//Exits
		Entrance(STOCKPOTINN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_OBSERVATORY] = Area("Astral Observatory/Bombers Hideout", "Astral Obseravtory/Bombers Hideout", NONE, {
		//Events
		//Watch Moon Tear Fall
	},
	{
		//Locations
		LocationAccess(BOMBERS_HIDEOUT_CHEST, {[] {return BombBag20;}}),
	},
	{
		//Exits
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
		Entrance(TERMINA_FIELD, {[]{return (DekuMask && MagicMeter) || Hookshot || HerosBow || ZoraMask;}}),
	});

	areaTable[CLOCK_TOWN_BAR] = Area("Milk Bar", "Milk Bar", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(E_CLOCK_TOWN_GORMAN, {[] {return DekuMask && GoronMask && ZoraMask && RomanisMask;}}),
		//LocationAccess(E_CLOCK_TOWN_AROMA_IN_BAR, {[] {return LetterMama && KafeisMask;}}),
		//LocationAccess(E_CLOCK_TOWN_POSTMAN_FREEDOM, {[] {return LetterMama;}}),
	},
	{
		//Exits
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
	});
	areaTable[CLOCK_TOWN_HONEY_DARLING] = Area("Honey And Darling Shop", "Honey And Darling Shop", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(E_CLOCK_TOWN_HONEY_DARLING_3DAYS, {[] {return Arrows && AnyBombBag;}}),
	},
	{
		//Exits
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
	});
	areaTable[CLOCK_TOWN_TREASURE_CHEST_GAME] = Area("Treasure Chest Game", "Treasure Chest Game", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON, {[] {return GoronMask;}}),
	},
	{
		//Exits
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
	});
	areaTable[CLOCK_TOWN_ARCHERY] = Area("Clock Town Archery", "Clock Town Archery", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(E_CLOCK_TOWN_ARCHERY_1, {[] {return Arrows;}}),
		//LocationAccess(E_CLOCK_TOWN_ARCHERY_2, {[] {return Arrows;}}),
	},
	{
		//Exits
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
	});
	areaTable[CLOCK_TOWN_MAYOR_HOUSE] = Area("Mayor's House", "Mayor's House", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(E_CLOCK_TOWN_AROMA_IN_OFFICE, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
	});
	
		
	areaTable[W_CLOCK_TOWN] = Area("West Clock Town", "West Clock Town", W_CLOCK_TOWN, {
		//Events
		EventAccess(&BugRock, {[]{return BugRock;}}),
		EventAccess(&BugShrub,{[]{return BugShrub;}}),
		EventAccess(&LoneFish, {[]{return LoneFish;}}),
		EventAccess(&SpringWater, {[]{return SpringWater;}}),
	}, 
	{
		//Locations
		//LocationAccess(W_CLOCK_TOWN_ROSA_SISTERS, {[] {return KamarosMask;}}),

	},
	{
		//Exits
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
		Entrance(TERMINA_FIELD, {[]{return true;}}),
		Entrance(CLOCK_TOWN_SWORDSMANS_SCHOOL, {[]{return true;}}),
		Entrance(CLOCK_TOWN_POSTMAN_HOUSE, {[]{return true;}}),
		Entrance(CLOCK_TOWN_LOTTERY, {[]{return true;}}),
		Entrance(CLOCK_TOWN_BOMB_SHOP, {[]{return true;}}),
		Entrance(CLOCK_TOWN_TRADING_POST, {[]{return true;}}),
		Entrance(CLOCK_TOWN_CURIOSITY_SHOP, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_SWORDSMANS_SCHOOL] = Area("Swordmans' School", "Swordsmans' School", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(W_CLOCK_TOWN_SWORDSMANS_SCHOOL, {[] {return AnyBSword;}}),
		
	},
	{
		//Exits
		Entrance(W_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_POSTMAN_HOUSE] = Area("Post Office", "Post Office", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(W_CLOCK_TOWN_POSTMANS_GAME, {[] {return BunnyHood;}}),
		
	},
	{
		//Exits
		Entrance(W_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_LOTTERY] = Area("Lottery Shop", "Lottery Shop", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(W_CLOCK_TOWN_LOTTERY, {[] {return;}}),

	},
	{
		//Exits
		Entrance(W_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_BOMB_SHOP] = Area("Clock Town Bomb Shop", "Clock Town Bomb Shop", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(W_CLOCK_TOWN_BOMB_BAG_BUY, {[] {return true;}}),
		//LocationAccess(W_CLOCK_TOWN_BIG_BOMB_BAG_BUY, {[] {return LetterKafei && PendantOfMemories;}}),
	},
	{
		//Exits
		Entrance(W_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_TRADING_POST] = Area("Trading Post", "Trading Post", NONE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(W_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_CURIOSITY_SHOP] = Area("Curiosity Shop", "Curiosity Shop", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY, {[] {return AnyWallet;}}),
	},
	{
		//Exits
		Entrance(W_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[S_CLOCK_TOWN] = Area("South Clock Town", "South Clock Town", S_CLOCK_TOWN, {
		//Events
	}, 
	{
		//Locations
		//LocationAccess(S_CLOCK_TOWN_SCRUB_TRADE, {[] {return MoonsTear;}}),
		//LocationAccess(S_CLOCK_TOWN_POSTBOX, {[] {return PostmansHat;}}),
		//LocationAccess(S_CLOCK_TOWN_CLOCK_TOWER_ENTRANCE, {[] {return true;}}),
		LocationAccess(S_CLOCK_TOWN_STRAW_ROOF_CHEST, {[] {return Hookshot || (DekuMask && MoonsTear);}}),
		LocationAccess(S_CLOCK_TOWN_FINAL_DAY_CHEST, {[] {return Hookshot || (DekuMask && MoonsTear);}}),
		//LocationAccess(S_CLOCK_TOWN_BANK_REWARD_1, {[] {return true;}}),
		//LocationAccess(S_CLOCK_TOWN_BANK_REWARD_2, {[] {return AnyWallet;}}),
		//LocationAccess(S_CLOCK_TOWN_BANK_REWARD_3, {[] {return AnyWallet;}}),
	},
	{
		//Exits
		Entrance(N_CLOCK_TOWN,  {[]{return true;}}),
		Entrance(E_CLOCK_TOWN,  {[]{return true;}}),
		Entrance(W_CLOCK_TOWN,  {[]{return true;}}),
		Entrance(LAUNDRY_POOL,  {[]{return true;}}),
		Entrance(CLOCK_TOWER,   {[]{return true;}}),
		Entrance(CLOCK_TOWER_ROOF, {[]{return true;}}),
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWER] = Area("Clock Tower Interior", "Clock Tower Interior", CLOCK_TOWER, {
		//Events
	},
	{
		//Locations
		LocationAccess(HMS_SONG_OF_HEALING, {[]{return true;}}),
		//LocationAccess(HMS_BOMBERS_NOTEBOOK, {[]{return true;}}),
		LocationAccess(HMS_DEKU_MASK, {[]{return true;}}),
		LocationAccess(HMS_STARTING_SWORD, {[]{return true;}}),
		//LocationAccess(HMS_STARTING_SHIELD, {[]{return true;}}),
	},
	{
		//Exits
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWER_ROOF] = Area("Clock Tower Roof", "Clock Tower Roof", CLOCK_TOWER_ROOF, {
		//Events
		//Ocarina Event?
		//Moon Transport
	},
	{
		//Locations
		LocationAccess(CLOCK_TOWER_OCARINA_OF_TIME, {[]{return true;}}),
	},
	{
		//Exits
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
		Entrance(THE_MOON, {[]{return WoodfallClear && SnowheadClear && GreatBayClear && StoneTowerClear && OathToOrder;}}),
	});

	areaTable[LAUNDRY_POOL] = Area("Laundry Pool", "Laundry Pool", LAUNDRY_POOL, {
		//Events
		//Kafei Letter?
	}, 
	{
		//Locations
		//LocationAccess(LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE, {[] {return LetterKafei;}}),
		//LocationAccess(LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO, {[] {return LetterKafei;}}),
		//LocationAccess(LAUNDRY_POOL_GURU_GURU, {[] {return true;}}), //No Reqs, Talk on night of day 1 or 2
		//LocationAccess(LAUNDRY_POOL_SF, { [] {return true;}}),
	},
	{
		//Exits
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
		Entrance(LAUNDRY_POOL_KAFEI_HIDEOUT, {[]{return LetterKafei;}}),
	});

	areaTable[LAUNDRY_POOL_KAFEI_HIDEOUT] = Area("Kafei's Hideout", "Kafei's Hideout", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(LAUNDRY_POOL_KAFEI, {[] {return LetterKafei;}}),
		
	},
	{
		//Exits
		Entrance(LAUNDRY_POOL, {[]{return true;}}),
	});
	areaTable[TERMINA_FIELD] = Area("Termina Field", "Termina Field", TERMINA_FIELD, {
		//Events
		EventAccess(&DekuBabaNuts, {[]{return DekuBabaNuts;}}),
		EventAccess(&DekuBabaSticks, {[]{return DekuBabaSticks;}}),
		//Moons Tear Event
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_MOONS_TEAR, {[] {return BombBag20;}}),//Should be event not Bombs but event doesnt exist yet
		//LocationAccess(TERMINA_FIELD_KAMARO, {[] {return SongOfHealing;}}),
		LocationAccess(TERMINA_FIELD_UNDERWATER_CHEST, {[] {return ZoraMask;}}),
		LocationAccess(TERMINA_FIELD_GRASS_CHEST, {[] {return true;}}),
		LocationAccess(TERMINA_FIELD_STUMP_CHEST, {[] {return Hookshot || (MagicBean && WitchBottle);}}),

	},
	{
		//Exits
		Entrance(N_CLOCK_TOWN, {[]{return true;}}),
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
		Entrance(W_CLOCK_TOWN, {[]{return true;}}),
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
		Entrance(TERMINA_FIELD_PEAHAT_GROTTO, {[]{return true;}}),
		Entrance(TERMINA_FIELD_DODONGO_GROTTO, {[]{return true;}}),
		Entrance(TERMINA_FIELD_BIO_BABA_GROTTO, {[]{return true;}}),
		Entrance(TERMINA_FIELD_PILLAR_GROTTO, {[]{return MagicBean && WitchBottle;}}),
		Entrance(TERMINA_FIELD_GRASS_GROTTO, {[]{return true;}}),
		Entrance(TERMINA_FIELD_BUSINESS_SCRUB_GROTTO, {[]{return true;}}),
		Entrance(TERMINA_FIELD_COW_GROTTO, {[]{return true;}}),
		Entrance(TERMINA_FIELD_GOSSIP_STONES_GROTTO, {[]{return BombBag20 || BlastMask || GoronMask;}}),//Something to break rocks
		Entrance(ROAD_TO_SOUTHERN_SWAMP, {[]{return true;}}),
		Entrance(PATH_TO_MOUNTAIN_VILLAGE, {[]{return HerosBow;}}),
		Entrance(MILK_ROAD, {[]{return true;}}),
		Entrance(GREAT_BAY_COAST, {[]{return EponasSong;}}),
		Entrance(ROAD_TO_IKANA, {[]{return true;}}),
	});

	areaTable[TERMINA_FIELD_PEAHAT_GROTTO] = Area("Termina Field Peahat Grotto","Termina Field Peahat Grotto", NONE,{
		//Events
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_PEAHAT_GROTTO_CHEST, {[] {return KokiriSword || HerosBow;}}),
		
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});
	areaTable[TERMINA_FIELD_DODONGO_GROTTO] = Area("Termina Field Dodongo Grotto","Termina Field Dodongo Grotto", NONE,{
		//Events
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_DODONGO_GROTTO_CHEST, {[] {return KokiriSword || HerosBow || BombBag20;}}),
		
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});
	areaTable[TERMINA_FIELD_BIO_BABA_GROTTO] = Area("Termina Field Bio Baba Grotto","Termina Field Bio Baba Grotto", NONE,{
		//Events
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_BIO_BABA_GROTTO_BEEHIVE, {[] {return ZoraMask;}}),
		
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});
	areaTable[TERMINA_FIELD_PILLAR_GROTTO] = Area("Termina Field Pillar Grotto","Termina Field Pillar Grotto", NONE,{
		//Events
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_PILLAR_GROTTO_CHEST, {[] {return MagicBean && WitchBottle;}}),
		
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});
	areaTable[TERMINA_FIELD_GRASS_GROTTO] = Area("Termina Field Grass Grotto","Termina Field Grass Grotto", NONE,{
		//Events
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_GRASS_GROTTO_CHEST, {[] {return true;}}),
		
	},
	{
		//Exits
	});
	areaTable[TERMINA_FIELD_BUSINESS_SCRUB_GROTTO] = Area("Termina Field Business Scrub Grotto","Termina Field Business Scrub Grotto", NONE,{
		//Events
	},
	{
		//Locations
		//LocationAccess(TERMINA_FIELD_BUSINESS_SCRUB, {[] {return AnyWallet;}}),
		
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});
	areaTable[TERMINA_FIELD_COW_GROTTO] = Area("Termina Field Cow Grotto","Termina Field Cow Grotto", NONE,{
		//Events
	},
	{
		//Locations
		//LocationAccess(TERMINA_FIELD_GROTTO_COW1, {[]{return EponasSong;}}),
		//LocationAccess(TERMINA_FIELD_GROTTO_COW2, {[]{return EponasSong;}}),
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});
	areaTable[TERMINA_FIELD_GOSSIP_STONES_GROTTO] = Area("Termina Field Gossip Stones Grotto","Termina Field Gossip Stones Grotto", NONE,{
		//Events
	},
	{
		//Locations
		//LocationAccess(TERMINA_FIELD_GOSSIP_STONES, {[] {return (GoronMask && GoronsLullaby) || (DekuMask && SonataOfAwakening && Explosives) || (DekuMask&&SonataOfAwakening&&GoronMask) || (ZoraMask && NewWaveBossaNova && Explosives) || (ZoraMask && GoronMask && NewWaveBossaNova);}}),
		
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});

	areaTable[ROAD_TO_SOUTHERN_SWAMP] = Area("Road to Southern Swamp", "Road to Southern Swamp", ROAD_TO_SOUTHERN_SWAMP, {
		//Events
	}, 
	{
		//Locations
		//LocationAccess(ROAD_TO_SS_TREE, {[] {return DekuMask && (MagicMeter || Arrows || Hookshot || ZoraMask);}}),

	},
	{
		//Exits
		Entrance(TERMINA_FIELD,{[]{return true;}}),
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),
		Entrance(ROAD_TO_SOUTHERN_SWAMP_ARCHERY, {[]{return true;}}),
		Entrance(ROAD_TO_SWAMP_GROTTO, {[]{return true;}}),
		//Entrance(ROAD_TO_SWAMP_FISHING_HOLE, {[]{return true;}}), //eventually add?
	});

	areaTable[ROAD_TO_SOUTHERN_SWAMP_ARCHERY] = Area("Road To Southern Swamp Archery", "Road to Southern Swamp Archery", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(ROAD_TO_SS_ARCHERY_1, {[] {return HerosBow;}}),
		//LocationAccess(ROAD_TO_SS_ARCHERY_2, {[] {return HerosBow;}}),
		
	},
	{
		//Exits
		Entrance(ROAD_TO_SOUTHERN_SWAMP, {[]{return true;}}),
	});

	areaTable[ROAD_TO_SWAMP_GROTTO] = Area("Road To Southen Swamp Grotto", "Road To Southern Swamp Grotto", NONE, {
		//Events
	},
	{
		//Locations		
		LocationAccess(ROAD_TO_SWAMP_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
	});

	
	areaTable[SOUTHERN_SWAMP] = Area("Southern Swamp", "Southern Swamp", SOUTHERN_SWAMP, {
		//Events
	}, 
	{
		//Locations
		//LocationAccess(SOUTHERN_SWAMP_SCRUB_TRADE, {[] {return LandTitle;}}),
		//LocationAccess(SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD, {[] {return PoisonSwampAccess && AccessToAllSwampSpiders;}}),
		LocationAccess(SOUTHERN_SWAMP_MUSIC_STATUE, {[] {return true;}}),
		//LocationAccess(SWAMP_TOURIST_CENTER_ROOF, {[] {return DekuMask && LandTitle;}}),

	},
	{
		//Exits
		Entrance(ROAD_TO_SOUTHERN_SWAMP, {[]{return true;}}),
		Entrance(MYSTERY_WOODS, {[]{return true;}}),
		Entrance(SWAMP_TOURIST_CENTER, {[]{return true;}}),
		Entrance(SOUTHERN_SWAMP_HAGS_POTION_SHOP, {[]{return true;}}),
		Entrance(DEKU_PALACE, {[]{return DekuMask && WitchBottle;}}),
		Entrance(SOUTHERN_SWAMP_TOP, {[]{return false;}}),//Only accessable From top route falling down
		Entrance(SSH, {[]{return DekuMask && WitchBottle;}}),
		Entrance(SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO, {[]{return DekuMask && WitchBottle;}}),
	});

	areaTable[SWAMP_TOURIST_CENTER] = Area("Swamp Tourist Center", "Swamp Tourist Center", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SOUTHERN_SWAMP_KOUME, {[] {return WitchBottle && DekuMask;}}),
		//LocationAccess(SOUTHERN_SWAMP_PICTOGRAPH_WINNER, {[] {return Pictobox;}}),
		//LocationAccess(SOUTHERN_SWAMP_BOAT_ARCHERY, {[] {return WoodfallClear && AnyHealingPotion;}}),
		
	},
	{
		//Exits
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),
	});

	areaTable[SOUTHERN_SWAMP_HAGS_POTION_SHOP] = Area("Swamp Potion Shop", "Swamp Potion Shop", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SOUTHERN_SWAMP_KOTAKE, {[] {return true;}}),
		//LocationAccess(SOUTHERN_SWAMP_KOTAKE_MUSHROOM_SALE, {[] {return MaskOfScents && WitchBottle && Mushroom;}}),
		
	},
	{
		//Exits
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),
	});

	areaTable[MYSTERY_WOODS] = Area("Mystery Woods", "Mystery Woods", MYSTERY_WOODS, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),
		Entrance(SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO, {[]{return true;}}),
	});

	areaTable[SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO] = Area("Mystery Woods Grotto", "Mystery Woods Grotto", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(MYSTERY_WOODS, {[]{return true;}}),
	});

	areaTable[SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO] = Area("Near Swamp Spider House Grotto", "Near Swamp Spider House Grotto", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO_CHEST, {[] {return DekuMask && WitchBottle;}}),
	},
	{
		//Exits
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),
	});

	areaTable[SOUTHERN_SWAMP_TOP] = Area("Southern Swamp Top Route", "Southern Swamp Top Route", SOUTHERN_SWAMP, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),//just fall off 
		Entrance(WOODFALL, {[]{return DekuMask;}}),
		Entrance(DEKU_PALACE, {[]{return DekuMask;}}),
	});

	areaTable[DEKU_PALACE] = Area("Deku Palace", "Deku Palace", DEKU_PALACE, {
		//Events
	}, 
	{
		//locations
		//LocationAccess(DEKU_PALACE_WEST_GARDEN, {[] {return PoisonSwampAccess && DekuMask;}}),
	},
	{
		//Exits
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),
		//SOUTHERN_SWAMP_TOP might not be needed but theres two entrances/exits from deku palace that lead to southern swamp
		//BUT only the top route can reach woodfall
		Entrance(SOUTHERN_SWAMP_TOP, {[]{return DekuMask;}}),
		Entrance(DEKU_PALACE_INTERIOR, {[]{return DekuMask && WitchBottle && MagicBean;}}), 
		Entrance(DEKU_PALACE_BEAN_GROTTO, {[]{return DekuMask;}}),
		Entrance(DEKU_SHRINE, {[]{return DekuMask;}}),
	});

	areaTable[DEKU_PALACE_INTERIOR] = Area("Deku Palace Throne Room", "Deku Palace Throne Room", NONE, {
		//Events
		//turned in deku princess - enables getting deku shrine reward
	},
	{
		//Locations
		LocationAccess(DEKU_PALACE_IMPRISONED_MONKEY, {[] {return DekuMask && MagicBean && WitchBottle;}}),
	},
	{
		//Exits
		Entrance(DEKU_PALACE, {[]{return true;}}),
	});

	areaTable[DEKU_PALACE_BEAN_GROTTO] = Area("Deku Palace Bean Grotto", "Deku Palace Bean Grotto", NONE, {
		//Events
		EventAccess(&LimitlessBeans, {[]{return LimitlessBeans;}}), 
	},
	{
		//Locations
		LocationAccess(DEKU_PALACE_BEAN_DADDY, {[] {return DekuMask;}}),
		LocationAccess(DEKU_PALACE_BEAN_GROTTO_CHEST, {[] {return DekuMask && ((MagicBean && WitchBottle) || Hookshot);}}),
	},
	{
		//Exits
		Entrance(DEKU_PALACE, {[] {return true;}}),
	});

	areaTable[DEKU_SHRINE] = Area("Deku Shrine", "Deku Shrine", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(DEKU_PALACE_BUTLER_RACE, {[] {return WoodfallClear || (PoisonSwampAccess && DekuMask && DekuPrincess);}}),
	
	},
	{
		//Exits
		Entrance(DEKU_PALACE, {[]{return true;}}),
	});

	areaTable[WOODFALL] = Area("Woodfall", "Woodfall", WOODFALL, {
		//Events
		//Woodfall Temple Raised?
	}, 
	{
		//Locations
		LocationAccess(WOODFALL_BRIDGE_CHEST, {[] {return DekuMask;}}),
		LocationAccess(WOODFALL_BEHIND_OWL_CHEST, {[] {return DekuMask;}}),
		LocationAccess(ENTRANCE_TO_WOODFALL_CHEST, {[] {return DekuMask;}}),

	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE, {[]{return DekuMask && SonataOfAwakening;}}),
		Entrance(SOUTHERN_SWAMP_TOP, {[]{return true;}}),
		Entrance(WOODFALL_FAIRY_FOUNTAIN, {[]{return DekuMask;}}),
		Entrance(WOODFALL_TEMPLE_PRINCESS_ROOM, {[]{return WoodfallClear;}}),
	});

	areaTable[WOODFALL_FAIRY_FOUNTAIN] = Area("Woodfall Great Fairy Fountain", "Woodfall Great Fairy Fountain", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(WOODFALL_GREAT_FAIRY, {[] {return AllWoodfallStrays && DekuMask && PoisonSwampAccess && GreatFairyMask;}}),
	},
	{
		//Exits
		Entrance(WOODFALL, {[]{return true;}}),
	});

	areaTable[PATH_TO_MOUNTAIN_VILLAGE] = Area("Path to Mountain Village", "Path to Mountain Village", PATH_TO_MOUNTAIN_VILLAGE, {
		//Events
	},
	{
		//Locations
		//Path Grotto - requires Bombs & (maybe)Mask of Truth? - has no items just freestanding money
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
		Entrance(MOUNTAIN_VILLAGE, {[]{return BombBag20;}}),
	});

	areaTable[MOUNTAIN_VILLAGE] = Area("Mountain Village", "Mountain Village", MOUNTAIN_VILLAGE, {
		//Events
	}, 
	{
		//Locations
		//LocationAccess(MOUNTAIN_VILLAGE_FROG_CHOIR, {[] {return NorthAccess && GoronMask && MagicMeter;}}),
		//LocationAccess(MOUNTAIN_VILLAGE_HUNGRY_GORON, {[] {return NorthAccess && GoronMask && MagicMeter;}}),
		LocationAccess(MOUNTAIN_WATERFALL_CHEST, {[] {return SnowheadClear;}}),

	},
	{
		//Exits
		Entrance(PATH_TO_MOUNTAIN_VILLAGE, {[]{return true;}}),
		Entrance(TWIN_ISLANDS, {[]{return true;}}),
		Entrance(GORON_GRAVEYARD, {[]{return LensOfTruth && MagicMeter;}}),
		Entrance(ROAD_TO_SNOWHEAD, {[]{return true;}}),
		Entrance(MOUNTAIN_SMITHY, {[]{return true;}}),
		Entrance(MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO, {[]{return SnowheadClear;}}),
	});

	areaTable[GORON_GRAVEYARD] = Area("Goron Graveyard", "Goron Graveyard", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(MOUNTAIN_VILLAGE_DARMANI, {[] {return LensOfTruth && SongOfHealing && MagicMeter;}}),
	},
	{
		//Exits
		Entrance(MOUNTAIN_VILLAGE, {[]{return true;}}),
	});

	areaTable[MOUNTAIN_SMITHY] = Area("Mountain Smith", "Mountain Smith", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(MOUNTAIN_VILLAGE_SMITH_DAY_ONE, {[] {return AnyWallet && ( HotSpringWater || SnowheadClear || UseFireArrow);}}),
		//LocationAccess(MOUNTAIN_VILLAGE_SMITH_DAY_TWO, {[] {return GoronRaceBottle && (HotSpringWater || SnowheadClear || UseFireArrow);}}),
	},
	{
		//Exits
		Entrance(MOUNTAIN_VILLAGE, {[]{return true;}}),
	});

	areaTable[MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO] = Area("Mountain Village Spring Water Grotto", "Mountain Village Spring Water Grotto", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(MOUNTAIN_VILLAGE, {[]{return true;}}),
	});

	areaTable[TWIN_ISLANDS] = Area("Twin Islands", "Twin Islands", TWIN_ISLANDS, {
		//Events
		//Goron Elder song part?
	},
	 {
		//Locations
		LocationAccess(TWIN_ISLANDS_UNDERWATER_RAMP_CHEST, {[] {return SnowheadClear && ZoraMask;}}),
		LocationAccess(TWIN_ISLANDS_CAVE_CHEST, {[] {return SnowheadClear && ZoraMask;}}),
	},
	{
		//Exits
		Entrance(MOUNTAIN_VILLAGE, {[]{return true;}}),
		Entrance(GORON_RACETRACK, {[]{return PowderKeg && GoronMask && BombBag20;}}),
		Entrance(TWIN_ISLANDS_SPRING_WATER_GROTTO, {[]{return (HerosBow && FireArrows && MagicMeter) || SnowheadClear;}}),
		Entrance(GORON_VILLAGE, {[]{return true;}}),
	});

	areaTable[GORON_RACETRACK] = Area("Goron Racetrack", "Goron Racetrack", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(TWIN_ISLANDS_GORON_RACE, {[] {return SnowheadClear && GoronMask && MagicMeter;}}),
	},
	{
		//Exits
		Entrance(TWIN_ISLANDS, {[]{return true;}}),
		Entrance(TWIN_ISLANDS_GORON_RACETRACK_GROTTO, {[]{return BombBag20;}}),
	});

	areaTable[TWIN_ISLANDS_GORON_RACETRACK_GROTTO] = Area("Goron Racetrack Grotto", "Goron Racetrack Grotto", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(TWIN_ISLANDS_GORON_RACETRACK_GROTTO_CHEST, {[] {return HerosBow && BombBag20 && ((GoronMask || Hookshot));}}),
	},
	{
		//Exits
		Entrance(GORON_RACETRACK, {[]{return true;}}),
	});

	areaTable[TWIN_ISLANDS_SPRING_WATER_GROTTO] = Area("Twin Islands Hot Spring Water Grotto", "Twin Islands Hot Spring Water Grotto", NONE, {
		//Events
		EventAccess(&HotSpringWater, {[]{return HotSpringWater;}}),
	},
	{
		//Locations
		LocationAccess(HOT_SPRING_WATER_GROTTO_CHEST, {[] {return SnowheadClear || ((FireArrows && HerosBow && MagicMeter && BombBag20));}}),
	},
	{
		//Exits
		Entrance(TWIN_ISLANDS, {[]{return true;}}),
	});

	areaTable[GORON_VILLAGE] = Area("Goron Village", "Goron Village", GORON_VILLAGE, {
		//Events
		//Owl talk?
	}, 
	{
		//Locations
		LocationAccess(GORON_VILLAGE_POWDER_KEG_CHALLENGE, {[] {return GoronMask && (SnowheadClear || (FireArrows && MagicMeter));}}),
		//LocationAccess(GORON_VILLAGE_BIGGEST_BOMB_BAG_BUY, {[] {return NorthAccess && AnyWallet && (GoronMask || (DekuMask && MoonsTear && LandTitle && SwampTitle));}}),
		//LocationAccess(GORON_VILLAGE_MOUNTAIN_TITLE_DEED, {[] {return DekuMask && NorthAccess && SwampTitle;}}),
		//LocationAccess(GORON_VILLAGE_LEDGE, {[] {return DekuMask && NorthAccess && SwampTitle;}}),
		
	},
	{
		//Exits
		Entrance(GORON_VILLAGE_LENS_CAVE, {[]{return true;}}),
		Entrance(GORON_VILLAGE_INTERIOR, {[]{return (WitchBottle && HotSpringWater) || GoronMask;}}),
		Entrance(TWIN_ISLANDS, {[]{return true;}}),
	});

	areaTable[GORON_VILLAGE_LENS_CAVE] = Area("Lens of Truth Cave", "Lens of Truth Cave", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GORON_VILLAGE_LENS_OF_TRUTH_CHEST, {[] {return true;}}),
		LocationAccess(LENS_CAVE_RED_RUPEE, {[] {return LensOfTruth && MagicMeter;}}),
		LocationAccess(LENS_CAVE_PURPLE_RUPEE, {[] {return BombBag20 && LensOfTruth && MagicMeter;}}),

	},
	{
		//Exits
		Entrance(GORON_VILLAGE, {[]{return true;}}),
	});

	areaTable[GORON_VILLAGE_INTERIOR] = Area("Goron Village Interior", "Goron Village Interior", GORON_VILLAGE, {
		//Events
		//Light Torches?
		//Rock Roast?
		//Stop Baby Crying?
	},
	{
		//Locations
		LocationAccess(GORON_VILLAGE_GORON_LULLABY, {[]{return GoronMask;}}),
	},
	{
		//Exits
		Entrance(GORON_VILLAGE, {[]{return GoronMask;}}),
		Entrance(GORON_VILLAGE_SHOP, {[]{return true;}}),
	});

	areaTable[GORON_VILLAGE_SHOP] = Area("Goron Village Shop", "Goron Village Shop", NONE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(GORON_VILLAGE_INTERIOR, {[]{return true;}}),
	});

	areaTable[ROAD_TO_SNOWHEAD] = Area("Road To Snowhead", "Road To Snowhead", ROAD_TO_SNOWHEAD, {
		//Events
	}, 
	{
		//Locations
		//LocationAccess(ROAD_TO_SNOWHEAD_PILLAR, {[] {return NorthAccess && GoronMask && Hookshot && MagicMeter && LensOfTruth;}}),

	},
	{
		//Exits
		Entrance(ROAD_TO_SNOWHEAD_GROTTO, {[]{return GoronMask && MagicMeter && BombBag20;}}),
		Entrance(MOUNTAIN_VILLAGE, {[]{return true;}}),
		Entrance(SNOWHEAD, {[]{return GoronMask && MagicMeter;}}),
	});

	areaTable[ROAD_TO_SNOWHEAD_GROTTO] = Area("Road To Snowhead Grotto", "Road to Snowhead Grotto", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ROAD_TO_SNOWHEAD_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(ROAD_TO_SNOWHEAD, {[]{return true;}}),
	});

	areaTable[SNOWHEAD] = Area("Snowhead", "Snowhead", SNOWHEAD, {
		//Events
		//SleepyGoron
	}, 
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_ENTRANCE, {[]{return GoronMask && MagicMeter && GoronsLullaby;}}),
		Entrance(SNOWHEAD_FAIRY_FOUNTAIN, {[]{return GoronMask && MagicMeter && GoronsLullaby;}}),
		Entrance(ROAD_TO_SNOWHEAD, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_FAIRY_FOUNTAIN] = Area("Snowhead Fairy Fountain", "Snowhead Fairy Fountain", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(SNOWHEAD_GREAT_FAIRY, {[] {return AllSnowheadStrays;}}),
	},
	{
		//Exits
	});

	areaTable[MILK_ROAD] = Area("Milk Road", "Milk Road", MILK_ROAD, {
		//Events
	}, 
	{
		//Locations
		//Tingle Maps?
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
		Entrance(GORMAN_TRACK, {[]{return true;}}),
		Entrance(ROMANI_RANCH, {[]{return true;}}), //Set to True because its open on Day 3 for one potential early check, checks for days 1 and 2 require powderkeg
	});

	areaTable[GORMAN_TRACK] = Area("Gorman Track", "Gorman Track", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(MILK_ROAD_GORMAN_RACE, {[] {return EponasSong;}}),
	},
	{
		//Exits
		Entrance(MILK_ROAD, {[]{return true;}}),
	});

	areaTable[ROMANI_RANCH] = Area("Romani Ranch", "Romani Ranch", ROMANI_RANCH, {
		EventAccess(&Epona, {[]{return Epona || EponasSong;}}),
	}, 
	{
		//Locations
		//LocationAccess(ROMANI_RANCH_ALIEN_DEFENSE, {[] {return EponaAccess && Arrows;}}),
		//LocationAccess(ROMANI_RANCH_CREMIA_ESCORT, {[] {return EponaAccess && Arrows;}}),
		LocationAccess(ROMANI_RANCH_ROMANIS_GAME, {[] {return GoronMask && PowderKeg && HerosBow;}}),
	},
	{
		//Exits
		Entrance(MILK_ROAD, {[]{return true;}}),
		Entrance(DOGGY_RACETRACK, {[]{return true;}}),
		Entrance(CUCCO_SHACK, {[]{return true;}}),
		Entrance(ROMANI_RANCH_HOUSE, {[]{return true;}}),
	});

	areaTable[DOGGY_RACETRACK] = Area("Doggy Racetrack", "Doggy Racetrack", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(ROMANI_RANCH_DOG_RACE, {[] {return EponaAccess && MaskOfTruth;}}),
		LocationAccess(DOGGY_RACETRACK_ROOF_CHEST, {[] {return Hookshot || (WitchBottle && MagicBean);}}),
	},
	{
		//Exits
		Entrance(ROMANI_RANCH, {[]{return true;}}),
	});

	areaTable[CUCCO_SHACK] = Area("Cucco Shack", "Cucco Shack", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(ROMANI_RANCH_GROG, {[] {return BremenMask && EponaAccess;}}),
	},
	{
		//Exits
		Entrance(ROMANI_RANCH, {[]{return true;}}),
	});

	areaTable[ROMANI_RANCH_HOUSE] = Area("Romani Ranch House", "Romani Ranch House", NONE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(ROMANI_RANCH, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_COAST] = Area("Great Bay Coast", "Great Bay Coast", GREAT_BAY_COAST, {
		//Events
	}, 
	{
		//Locations
		//LocationAccess(GBC_OCEAN_SPIDER_DAY1, {[] {return WestAccess && AccessToAllOceanSpiders;}}),
		//LocationAccess(GBC_FISHERMAN_GAME, {[] {return GreatBayClear && Hookshot;}}),
		LocationAccess(GBC_OCEAN_SPIDER_CHEST, {[] {return HerosBow && BombBag20 && Hookshot && CaptainsHat && GoronMask;}}),
		//LocationAccess(GBC_LEDGE, {[] {return WestAccess && Hookshot && MagicBean && WitchBottle;}}),
		LocationAccess(GBC_MIKAU, {[] {return SongOfHealing && EponasSong;}}),

	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return EponasSong;}}),
		Entrance(OSH, {[]{return true;}}),
		Entrance(GREAT_BAY_COAST_MARINE_LAB, {[]{return true;}}),
		Entrance(ZORA_CAPE,  {[]{return true;}}),
		Entrance(GREAT_BAY_COAST_GROTTO, {[]{return true;}}),
		Entrance(PIRATE_FORTRESS, {[]{return ZoraMask;}}),
		Entrance(PINNACLE_ROCK, {[]{return ZoraMask;}}),
		Entrance(FISHERMAN_HUT, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_COAST_MARINE_LAB] = Area("Great Bay Marine Lab", "Great Bay Marine Lab", NONE, {
		//Events
		//Zora Eggs?
	},
	{
		//Locations
		//LocationAccess(GBC_LAB_FISH, {[] {return WestAccess && Fish;}}),
		LocationAccess(GBC_BABY_ZORAS, {[] {return  ZoraMask && EponasSong && Hookshot && ZoraEgg;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_COAST, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_COAST_GROTTO] = Area("Great Bay Coast Grotto", "Great Bay Coast Grotto", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBC_GROTTO_CHEST, {[] {return EponasSong;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_COAST, {[]{return true;}}),
	});

	areaTable[FISHERMAN_HUT] = Area("Fisherman's Hut", "Fisherman's Hut", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBC_FISHERMAN_PHOTO, {[] {return Pictobox && EponasSong && ZoraMask;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_COAST, {[]{return true;}}),
	});

	areaTable[PINNACLE_ROCK] = Area("Pinnacle Rock", "Pinnacle Rock", PINNACLE_ROCK, {
		//Events
	}, 
	{
		//Locations
		//LocationAccess(PINNACLE_ROCK_SEAHORSES, {[] {return EponasSong && WitchBottle && ZoraMask && MagicMeter && Pictobox;}}),
		LocationAccess(PINNACLE_ROCK_UPPER_CHEST, {[] {return EponasSong && WitchBottle && ZoraMask && MagicMeter && Pictobox && Seahorse;}}),
		LocationAccess(PINNACLE_ROCK_LOWER_CHEST, {[] {return EponasSong && WitchBottle && ZoraMask && MagicMeter && Pictobox && Seahorse;}}),

	},
	{
		//Exits
		Entrance(GREAT_BAY_COAST, {[]{return ZoraMask;}}),
	});

	areaTable[ZORA_CAPE] = Area("Zora Cape", "Zora Cape", ZORA_CAPE, {
		//Events
	}, 
	{
		//Locations
		//LocationAccess(ZORA_CAPE_LIKE_LIKE, {[] {return PiratesFortressAccess;}}),
		LocationAccess(ZORA_CAPE_LEDGE_NO_TREE, {[] {return Hookshot;}}),
		LocationAccess(ZORA_CAPE_LEDGE_WITH_TREE, {[] {return Hookshot;}}),
		LocationAccess(ZORA_CAPE_UNDERWATER_CHEST, {[] {return ZoraMask;}}),

	},
	{
		//Exits
		Entrance(GREAT_BAY_COAST, {[]{return true;}}),
		Entrance(ZORA_HALL, {[]{return ZoraMask;}}),
		Entrance(WATERFALL_RAPIDS, {[]{return Hookshot;}}),
		Entrance(GREAT_BAY_FAIRY_FOUNTAIN, {[]{return Hookshot;}}),
		Entrance(ZORA_CAPE_GROTTO, {[]{return Hookshot && BombBag20;}}),
		Entrance(GREAT_BAY_TEMPLE_ENTRANCE, {[]{return Hookshot && ZoraMask && SonataOfAwakening;}}),
		Entrance(ZORA_HALL_BACK_ENTRANCE, {[]{return ZoraMask;}}),
	});

	areaTable[WATERFALL_RAPIDS] = Area("Waterfall Rapids", "Waterfall Rapids", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(ZORA_CAPE_BEAVER_RACE_1, {[] {return Hookshot && ZoraMask && WestAccess;}}),
		//LocationAccess(ZORA_CAPE_BEAVER_RACE_2, {[] {return Hookshot && ZoraMask && WestAccess;}}),
	},
	{
		//Exits
		Entrance(ZORA_CAPE, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_FAIRY_FOUNTAIN] = Area("Great Bay Fairy Fountain", "Great Bay Fairy Fountain", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(ZORA_CAPE_GREAT_FAIRY, {[] {return Explosives && WestAccess && Hookshot && AllGreatBayStrays;}}),
	},
	{
		//Exits
		Entrance(ZORA_CAPE, {[]{return true;}}),
	});

	areaTable[ZORA_CAPE_GROTTO] = Area("Zora Cape Grotto", "Zora Cape Grotto", NONE, {
		//Events
	},
	{
		//Loactions
		LocationAccess(ZORA_CAPE_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(ZORA_CAPE, {[]{return true;}}),
	});

	
	areaTable[ZORA_HALL] = Area("Zora Hall", "Zora Hall", ZORA_HALL, {
		//Events
	}, 
	{
		//Locations
		//LocationAccess(ZORA_HALL_STAGE_LIGHTS, {[] {return;}}),
		//ZORA_HALL_BAD_PHOTO_LULU
		//ZORA_HALL_GOOD_PHOTO_LULU

	},
	{
		//Exits
		Entrance(ZORA_CAPE, {[]{return ZoraMask;}}),
		Entrance(ZORA_HALL_BACK_ENTRANCE, {[]{return true;}}),
		Entrance(ZORA_HALL_EVANS_ROOM, {[]{return ZoraMask;}}),
		Entrance(ZORA_HALL_LULUS_ROOM, {[]{return ZoraMask;}}),
		Entrance(ZORA_HALL_JAPAS_ROOM, {[]{return ZoraMask;}}),
		Entrance(ZORA_HALL_TIJOS_ROOM, {[]{return ZoraMask;}}),
		Entrance(ZORA_HALL_SHOP, {[]{return true;}}),
	});

	areaTable[ZORA_HALL_EVANS_ROOM] = Area("Zora Hall Evan's Room", "Zora Hall Evan's Room", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(ZORA_HALL_EVAN, {[] {return ZoraMask && WestAccess;}}),
	},
	{
		//Exits
		Entrance(ZORA_HALL, {[]{return true;}}),
	});

	areaTable[ZORA_HALL_LULUS_ROOM] = Area("Zora Hall Lulu's Room", "Zora Hall Lulu's Room", NONE,{
		//Events
	},
	{
		//Locations
		//LocationAccess(ZORA_HALL_SCRUB_TRADE, {[] {return GoronMask && ZoraMask && WestAccess && MountainTitle;}}),
		//LocationAccess(ZORA_HALL_LULU_ROOM_LEDGE, {[] {return PiratesFortressAccess && GoronMask && DekuMask && MountainTitle;}}),
		//LocationAccess(ZORA_HALL_SCRUB_BUY, {[] {return;}}),
	},
	{
		//Exits
		Entrance(ZORA_HALL, {[]{return true;}}),
	});

	areaTable[ZORA_HALL_JAPAS_ROOM] = Area("Zora Hall Japas' Room", "Zora Hall Japas' Room", NONE,{
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(ZORA_HALL, {[]{return true;}}),
	});

	areaTable[ZORA_HALL_TIJOS_ROOM] = Area("Zora Hall Tijo's Room", "Zora Hall Tijo's Room", NONE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(ZORA_HALL, {[]{return true;}}),
	});

	areaTable[ZORA_HALL_SHOP] = Area("Zora Hall Shop", "Zora Hall Shop", NONE, {
		//Events
	},
	{
		//Locations
		//Shield
		//Arrows
		//Potion?
	},
	{
		//Exits
		Entrance(ZORA_HALL, {[]{return true;}}),
	});

	//This one might not be needed?? but there's two entrances/exits to Zora Hall that both go to Zora Cape
	areaTable[ZORA_HALL_BACK_ENTRANCE] = Area("Zora Hall Back Entrance", "Zora Hall Back Entrance", ZORA_HALL, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(ZORA_CAPE, {[]{return true;}}),
		Entrance(ZORA_HALL, {[]{return true;}}),
	});

	areaTable[ROAD_TO_IKANA] = Area("Road To Ikana", "Road To Ikana", ROAD_TO_IKANA, {
		//Events
	}, 
	{
		//Locations
		LocationAccess(ROAD_TO_IKANA_PILLAR_CHEST, {[] {return Hookshot;}}),

	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return EponasSong;}}),
		Entrance(IKANA_GRAVEYARD, {[]{return EponasSong;}}),
		Entrance(IKANA_CANYON, {[]{return Hookshot && GarosMask && EponasSong;}}),
		Entrance(ROAD_TO_IKANA_GROTTO, {[]{return EponasSong && GoronMask;}}),
	});

	areaTable[ROAD_TO_IKANA_GROTTO] = Area("Road To Ikana Grotto", "Road to Ikana Grotto", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ROAD_TO_IKANA_GROTTO_CHEST, {[] {return GoronMask;}}),
	},
	{
		//Exits
	});

	areaTable[IKANA_GRAVEYARD] = Area("Ikana Graveyard", "Ikana Graveyard", IKANA_GRAVEYARD, {
		//Events
		//Captain Keeta fight??
	}, 
	{
		//Locations
		LocationAccess(IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST, {[] {return SonataOfAwakening && EponasSong && KokiriSword;}}),
	},
	{
		//Exits
		Entrance(ROAD_TO_IKANA, {[]{return true;}}),
		Entrance(IKANA_GRAVEYARD_BELOW_GRAVE1, {[]{return CaptainsHat;}}),
		Entrance(IKANA_GRAVEYARD_BELOW_GRAVE2, {[]{return CaptainsHat;}}),
		Entrance(IKANA_GRAVEYARD_BELOW_GRAVE3, {[]{return CaptainsHat;}}),
		Entrance(IKANA_GRAVEYARD_GROTTO, {[]{return BombBag20;}}),
	});

	areaTable[IKANA_GRAVEYARD_GROTTO] = Area("Ikana Graveyard Grotto", "Ikana Graveyard Grotto", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(IKANA_GRAVEYARD_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD, {[]{return true;}}),
	});

	areaTable[IKANA_GRAVEYARD_BELOW_GRAVE1] = Area("Ikana Graveyard Below Grave Day 1", "Ikana Graveyard Below Grave Day 1", NONE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD, {[]{return true;}}),
		Entrance(IKANA_GRAVEYARD_BATS_ROOM, {[]{return true;}}),
	});

	areaTable[IKANA_GRAVEYARD_BATS_ROOM] = Area("Ikana Graveyard Below Graves Bats Room", "Ikana Graveyard Below Graves Bats Room", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(IKANA_GRAVEYARD_DAY_ONE_GRAVE_BATS, {[] {return CaptainsHat && EponasSong && KokiriSword;}}),
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD_BELOW_GRAVE1, {[]{return true;}}),
		Entrance(IKANA_GRAVEYARD_TABLET_ROOM, {[]{return KokiriSword || DekuMask || ZoraMask || GoronMask;}}),//Fighting
	});

	areaTable[IKANA_GRAVEYARD_TABLET_ROOM] = Area("Ikana Graveyard Below Graves Tablet Room", "Ikana Graveyard Below Graves Tablet Room", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET, {[] {return CaptainsHat && EponasSong && KokiriSword;}}),
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD_BATS_ROOM, {[]{return true;}}),
	});

	areaTable[IKANA_GRAVEYARD_BELOW_GRAVE2] = Area("Ikana Graveyard Below Graves Day 2", "Ikana Graveyard Below Graves Day 2", NONE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD, {[]{return true;}}),
		Entrance(IKANA_GRAVEYARD_IRON_KNUCKLE_ROOM, {[]{return true;}}),
	});

	areaTable[IKANA_GRAVEYARD_IRON_KNUCKLE_ROOM] = Area("Ikana Graveyard Below Graves Iron Knuckle Room", "Ikana Graveyard Below Graves Iron Knuckle Room", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(IKANA_GRAVEYARD_IRON_KNUCKLE_CHEST, {[] {return CaptainsHat && BombBag20 && KokiriSword;}}), //Kokiri sword can be replaced with Fighting later & shouldnt need bombs???
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD_BELOW_GRAVE2, {[]{return true;}}),
	});

	areaTable[IKANA_GRAVEYARD_BELOW_GRAVE3] = Area("Ikana Graveyard Below Graves Day 3", "Ikana Graveyard Below Graves Day 3", NONE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD, {[]{return true;}}),
		Entrance(DAMPES_HUT, {[]{return true;}}),
	});

	areaTable[DAMPES_HUT] = Area("Dampe's Hut", "Dampe's Hut", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(IKANA_GRAVEYARD_DAMPE_DIGGING, {[] {return CaptainsHat && IkanaGraveyardAccess;}}),
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD, {[]{return true;}}),
		Entrance(IKANA_GRAVEYARD_BELOW_GRAVE3, {[]{return false;}}),//I think this one is one way? if not easy fix
	});

	areaTable[IKANA_CANYON] = Area("Lower Ikana Canyon", "Lower Ikana Canyon", IKANA_CANYON, {
		//Events
		EventAccess(&EnterSakonHideout, {[]{return LetterKafei && LetterMama && PendantOfMemories && KafeisMask;}}),//probably missing a req
	}, 
	{
		//Locations
		//LocationAccess(IKANA_CANYON_LEDGE, {[] {return ZoraMask && OceanTitle && DekuMask && EastAccess;}}),
		//LocationAccess(IKANA_CANYON_SCRUB_TRADE, {[] {return EastAccess && ZoraMask && OceanTitle;}}),
	},
	{
		//Exits
		Entrance(ROAD_TO_IKANA, {[]{return true;}}),
		Entrance(SAKONS_HIDEOUT, {[]{return EnterSakonHideout;}}),//need event for sakon hideout opening - no item check currently added
		Entrance(SECRET_SHRINE, {[]{return true;}}),//slow swim but don't NEED zora mask
		Entrance(IKANA_CANYON_SECRET_SHRINE_GROTTO, {[]{return true;}}),
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),//end of river
		Entrance(IKANA_CANYON_UPPER, {[]{return IceArrows && MagicMeter && HerosBow && Hookshot;}}),
	});

	areaTable[IKANA_CANYON_UPPER] = Area("Upper Ikana Canyon", "Upper Ikana Canyon", IKANA_CANYON, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(MUSIC_BOX_HOUSE, {[]{return MusicBoxOn;}}),
		Entrance(IKANA_CANYON_GREAT_FAIRY_FOUNTAIN, {[]{return true;}}),
		Entrance(IKANA_CANYON_POE_HUT, {[]{return true;}}),
		Entrance(STONE_TOWER, {[]{return true;}}),
		Entrance(IKANA_CANYON_CAVE, {[]{return true;}}),
		Entrance(IKANA_CASTLE, {[]{return MirrorShield;}}),
		Entrance(BENEATH_THE_WELL_ENTRANCE, {[]{return true;}}),
		Entrance(IKANA_CANYON, {[]{return true;}}),
	});

	areaTable[IKANA_CANYON_CAVE] = Area("Ikana Canyon Cave", "Ikana Canyon Cave", NONE, {
		//Events
		EventAccess(&MusicBoxOn, {[]{return SongOfStorms;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CANYON_UPPER, {[]{return true;}}),
	});

	areaTable[SAKONS_HIDEOUT] = Area("Sakon's Hideout", "Sakon's Hideout", SAKONS_HIDEOUT, {
		//Events
	},
	{
		//Locations
		//SUN MASK?
	},
	{
		//Exits
		Entrance(IKANA_CANYON, {[]{return true;}}),
	});

	areaTable[MUSIC_BOX_HOUSE] = Area("Music Box House", "Music Box House", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(IKANA_CANYON_PAMELAS_FATHER, {[] {return SongOfHealing;}}),
	},
	{
		//Exits
		Entrance(IKANA_CANYON_UPPER, {[]{return true;}}),
	});
	
	areaTable[IKANA_CANYON_POE_HUT] = Area("Ikana Canyon Poe Hut", "Ikana Canyon Poe Hut", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(IKANA_CANYON_POE_HUT_HP, {[] {return IkanaCanyonAccess && Arrows && KokiriSword;}}),
	},
	{
		//Exits
		Entrance(IKANA_CANYON_UPPER, {[]{return true;}}),
	});

	areaTable[IKANA_CANYON_GREAT_FAIRY_FOUNTAIN] = Area("Ikana Canyon Great Fairy Fountain", "Ikana Canyon Great Fairy Fountain", NONE,{
		//Events
	},
	{
		//Locations
		//LocationAccess(IKANA_CANYON_GREAT_FAIRY, {[] {return IkanaCanyonAccess && StoneTowerClear;}}),
	},
	{
		//Exits
		Entrance(IKANA_CANYON_UPPER, {[]{return true;}}),
	});

	areaTable[IKANA_CANYON_SECRET_SHRINE_GROTTO] = Area("Ikana Canyon Near Secret Shrine Grotto", "Ikana Canyon Near Secret Shrine Grotto", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(IKANA_CANYON_SECRET_SHRINE_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(IKANA_CANYON, {[]{return true;}}),
	});

	areaTable[STONE_TOWER] = Area("Stone Tower", "Stone Tower", STONE_TOWER, {
		//Events
	}, 
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CANYON_UPPER, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_ENTRANCE, {[]{return ElegyOfEmptiness && GoronMask && ZoraMask && DekuMask && Hookshot;}}),
		Entrance(INVERTED_STONE_TOWER, {[]{return ElegyOfEmptiness && GoronMask && ZoraMask && DekuMask && Hookshot && HerosBow && LightArrows && MagicMeter;}}),
	});

	areaTable[INVERTED_STONE_TOWER] = Area("Inverted Stone Tower", "Inverted Stone Tower", INVERTED_STONE_TOWER, {
		//Events
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_INVERTED_LEFT_CHEST, {[] {return MagicBean && WitchBottle;}}),
		LocationAccess(STONE_TOWER_INVERTED_CENTER_CHEST, {[] {return MagicBean && WitchBottle;}}),
		LocationAccess(STONE_TOWER_INVERTED_RIGHT_CHEST, {[] {return MagicBean && WitchBottle;}}),

	},
	{
		//Exits
		Entrance(STONE_TOWER, {[]{return LightArrows && HerosBow && MagicMeter;}}),
		Entrance(STONE_TOWER_TEMPLE_INVERTED_ENTRANCE, {[]{return true;}}),
	});

	/*--------------------------
	|         DUNGEONS         |
	---------------------------*/

	/*--------------------------
	|      WOODFALL TEMPLE     |
	---------------------------*/

	areaTable[WOODFALL_TEMPLE_ENTRANCE] = Area("Woodfall Temple Entrance", "Woodfall Temple Entrance", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(WF_SF_ENTRANCE_FAIRY, {[] {return WoodfallTempleAccess;}}),
		//LocationAccess(WF_SF_ENTRANCE_PLATFORM, {[] {return WoodfallTempleAccess && (DekuMask || Hookshot);}}),
	},
	{
		//Exits
		Entrance(WOODFALL, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_MAIN_ROOM, {[]{return DekuMask;}}),
	});

	areaTable[WOODFALL_TEMPLE_MAIN_ROOM] = Area("Woodfall Temple Main Room", "Woodfall Temple Main Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(WF_SF_MAIN_ROOM_BUBBLE, {[] {return HerosBow && GreatFairyMask;}}),
		//LocationAccess(WF_SF_JAR_FAIRY, {[] {return true;}}),
		//LocationAccess(WF_SF_DEKU_BABA, {[] {return true;}}),//Fighting? need to be able to kill the deku baba
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_ENTRANCE, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_BRIDGE_ROOM, {[]{return SmallKeys(WoodfallTempleKeys, 1);}}),
		Entrance(WOODFALL_TEMPLE_PLATFORM_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_UPPER_MAIN_ROOM, {[]{return SmallKeys(WoodfallTempleKeys, 1) && HerosBow && DekuMask;}}),//Main Room 2F switch pressed OR Hookshot trick OR Zora Jump?
	});

	areaTable[WOODFALL_TEMPLE_UPPER_MAIN_ROOM] = Area("Woodfall Temple Main Room 2F", "Woodfall Temple Main Room 2F", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(WF_SF_MAIN_ROOM_SWITCH, {[] {return DekuMask;}}),//or hookshot, ability to get over to tree and press switch
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_MAIN_ROOM, {[]{return true;}}),//just jump
		Entrance(WOODFALL_TEMPLE_UPPER_PLATFORM_ROOM, {[]{return true;}}), 
		Entrance(WOODFALL_TEMPLE_DRAGONFLY_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_PRE_BOSS_ROOM, {[]{return HerosBow;}}),
	});

	areaTable[WOODFALL_TEMPLE_PLATFORM_ROOM] = Area("Woodfall Temple Platform Room", "Woodfall Temple Platform Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(WOODFALL_TEMPLE_SMALL_KEY_CHEST, {[] {return DekuMask;}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_MAIN_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_UPPER_PLATFORM_ROOM, {[]{return HerosBow && DekuMask;}}),
		Entrance(WOODFALL_TEMPLE_MAP_ROOM, {[]{return DekuMask;}}),
	}),

	areaTable[WOODFALL_TEMPLE_MAP_ROOM] = Area("Woodfall Temple Map Room", "Woodfall Temple Map Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(WOODFALL_TEMPLE_MAP_CHEST, {[] {return WoodfallTempleAccess;}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_PLATFORM_ROOM, {[]{return true;}}),
	});

	areaTable[WOODFALL_TEMPLE_UPPER_PLATFORM_ROOM] = Area("Woodfall Temple Upper Platform Room", "Woodfall Temple Upper Platform Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(WF_SF_PLATFORM_ROOM_BEEHIVE, {[] {return HerosBow || Hookshot || ZoraMask || (DekuMask && MagicMeter);}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_BOSS_KEY_ROOM, {[]{return HerosBow && DekuMask;}}),
		Entrance(WOODFALL_TEMPLE_BOW_ROOM, {[]{return DekuMask;}}),
		Entrance(WOODFALL_TEMPLE_UPPER_MAIN_ROOM, {[]{return DekuMask;}}),
	});

	areaTable[WOODFALL_TEMPLE_BOSS_KEY_ROOM] = Area("Woodfall Temple Boss Key Room", "Woodfall Temple Boss Key Room", WOODFALL_TEMPLE, {
		//Events
		//Frog
	},
	{
		//Locations
		LocationAccess(WOODFALL_TEMPLE_BOSS_KEY_CHEST, {[] {return DekuMask && KokiriSword && HerosBow;}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_UPPER_PLATFORM_ROOM, {[]{return true;}}),
	});

	areaTable[WOODFALL_TEMPLE_BOW_ROOM] = Area("Woodfall Temple Bow Room", "Woodfall Temple Bow Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(WOODFALL_TEMPLE_HEROS_BOW_CHEST, {[] {return DekuMask && KokiriSword ;}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_UPPER_PLATFORM_ROOM, {[]{return true;}}),
	});

	areaTable[WOODFALL_TEMPLE_BRIDGE_ROOM] = Area("Woodfall Temple Bridge Room", "Woodfall Temple Bridge Room", WOODFALL_TEMPLE, {
		//Events
		//DekuBabaSticks
		//Torch for firesource?
	},
	{
		//Locations
		//LocationAccess(WF_SF_BRIDGE_ROOM_BEEHIVE, {[] {return WoodfallTempleAccess && ((Arrows && DekuMask) || (DekuMask && OneWoodfallKey && MagicMeter));}}),
		//LocationAccess(WF_SF_SKULLTULA, {[] {return WoodfallTempleAccess && ((DekuMask && Arrows) || (DekuMask && OneWoodfallKey));}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_MAIN_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_COMPASS_ROOM, {[]{return true;}}),//HasFireSource || HasFireWithTorch
		Entrance(WOODFALL_TEMPLE_DARK_ROOM, {[]{return true;}}),//HasFireSource || HasFireWithTorch
	});

	areaTable[WOODFALL_TEMPLE_COMPASS_ROOM] = Area("Woodfall Temple Compass Room", "Woodfall Temple Compass Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(WOODFALL_TEMPLE_COMPASS_CHEST, {[] {return Fighting || DekuMask;}}),//Something to hurt the dragonflys
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_BRIDGE_ROOM, {[]{return true;}}),
	});

	areaTable[WOODFALL_TEMPLE_DARK_ROOM] = Area("Woodfall Temple Dark Room", "Woodfall Temple Dark Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(WF_SF_DARK_ROOM, {[] {return HasFireWithTorch && Fighting;}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_BRIDGE_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_DRAGONFLY_ROOM, {[]{return true;}})//Fighting || HasFireSource || HasFireWithTorch
	});

	areaTable[WOODFALL_TEMPLE_DRAGONFLY_ROOM] = Area("Woodfall Temple Dragonfly Platform Room", "Woodfall Temple Dragonfly Platform Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(WF_SF_DRAGONFLY_ROOM_BUBBLE, {[] {return HerosBow && DekuMask && GreatFairyMask;}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_DARK_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_UPPER_MAIN_ROOM, {[]{return DekuMask;}}),
	});

	areaTable[WOODFALL_TEMPLE_PRE_BOSS_ROOM] = Area("Woodfall Temple Pre-Boss Room", "Woodfall Temple Pre-Boss Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(WF_SF_PRE_BOSS_LOWER_RIGHT_BUBBLE, {[] {return GreatFairyMask;}}),
		//LocationAccess(WF_SF_PRE_BOSS_UPPER_RIGHT_BUBBLE, {[] {return GreatFairyMask;}}),
		//LocationAccess(WF_SF_PRE_BOSS_UPPER_LEFT_BUBBLE, {[] {return GreatFairyMask;}}),
		//LocationAccess(WF_SF_PRE_BOSS_PILLAR_BUBBLE, {[] {return GreatFairyMask && (HerosBow || Hookshot);}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_UPPER_MAIN_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_BOSS_ROOM, {[]{return DekuMask && HerosBow && BossKeyWoodfallTemple;}}),
	});

	areaTable[WOODFALL_TEMPLE_BOSS_ROOM] = Area("Woodfall Temple Boss Room", "Woodfall Temple Boss Room", WOODFALL_TEMPLE, {
		//Events
		EventAccess(&WoodfallClear, {[]{return WoodfallClear || (BossKeyWoodfallTemple && DekuMask && HerosBow);}}),
	}, 
	{
		//Locations
		LocationAccess(ODOLWA, {[] {return DekuMask && KokiriSword && BossKeyWoodfallTemple;}}),// && SmallKeys(WoodfallTempleKeys, 1) 
		//LocationAccess(ODOLWA_HEART_CONTAINER, {[] {return WoodfallTempleAccess && Arrows && BossKeyWoodfallTemple && DekuMask;}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_PRE_BOSS_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_PRINCESS_ROOM, {[]{return WoodfallClear;}}),
	});

	areaTable[WOODFALL_TEMPLE_PRINCESS_ROOM] = Area("Deku Princess Room", "Deku Princess Room", WOODFALL_TEMPLE, {
		//Events
		//DekuPrincess access
	},
	{
		//Locations
		//LocationAccess(DEKU_PRINCESS, {[]{return WoodfallClear && WitchBottle;}}),//HasBottle
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_BOSS_ROOM, {[]{return false;}}),//One Way from warp
		Entrance(WOODFALL, {[]{return true;}}),
	});

	/*--------------------------
	|    SNOWHEAD TEMPLE       |
	---------------------------*/

	areaTable[SNOWHEAD_TEMPLE_ENTRANCE] = Area("Snowhead Temple Entrance", "Snowhead Temple Entrance", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_BRIDGE_ROOM, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_COMPASS_ROOM, {[]{return SmallKeys(SnowheadTempleKeys, 1);}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_1F, {[]{return FireArrows && HerosBow && MagicMeter;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_BRIDGE_ROOM] = Area("Snowhead Temple Bridge Room", "Snowhead Temple Bridge Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SNOWHEAD_TEMPLE_BRIDGE_ROOM_CHEST, {[] {return BombBag20 && HerosBow && GoronMask && GoronsLullaby && MagicMeter;}}),
		//StrayFairies
		//LocationAccess(SH_SF_BRIDGE_ROOM_LEDGE_BUBBLE, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && ((GreatFairyMask && Arrows) || (Hookshot && GreatFairyMask));}}),
		//LocationAccess(SH_SF_BRIDGE_ROOM_PILLAR_BUBBLE, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && ((GreatFairyMask && Arrows) || (Hookshot && GreatFairyMask));}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_ENTRANCE, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_1F, {[]{return GoronMask;}}),
		Entrance(SNOWHEAD_TEMPLE_LOWER_MAP_ROOM, {[]{return GoronMask;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_LOWER_MAP_ROOM] = Area("Snowhead Temple Lower Map Room", "Snowhead Temple Lower Map Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(SH_SF_MAP_ROOM_FAIRY, {[] {return true;}}),//its free floating in the corner
		//LocationAccess(SNOWHEAD_TEMPLE_MAP_CHEST, {[] {return SnowheadTempleAccess && EnterSnowheadTemple;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_BRIDGE_ROOM, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_UPPER_MAP_ROOM, {[]{return FireArrows && HerosBow && MagicMeter;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_UPPER_MAP_ROOM] = Area("Snowhead Temple Upper Map Room", "Snowhead Temple Upper Map Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		///LocationAccess(SH_SF_MAP_ROOM_LEDGE, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && ((Hookshot && ScarecrowSong) || (Hookshot && UseFireArrow) || (Hookshot && Explosives && TwoSnowheadKeys) || (Hookshot && ZoraMask && Explosives && OneSnowheadKey));}}),
		
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_LOWER_MAP_ROOM, {[]{return true;}}),//Just jump down
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_2F, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_MAIN_ROOM_1F] = Area("Snowhead Temple Main Room 1F", "Snowhead Temple Main Room 1F", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_BASEMENT, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_LOWER, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_ENTRANCE, {[]{return FireArrows && HerosBow && MagicMeter;}}),
		Entrance(SNOWHEAD_TEMPLE_PILLAR_FREEZARDS_ROOM, {[]{return FireArrows && HerosBow && MagicMeter;}}),//Has 2 entrances, left and right both need fire arrows though
	});

	areaTable[SNOWHEAD_TEMPLE_BASEMENT]= Area("Snowhead Temple Basement", "Snowhead Temple Basement", SNOWHEAD_TEMPLE, {
		//Events
		//Pillar Lowering Switch
	},
	{
		//Locations
		//LocationAccess(SH_SF_BASEMENT, {[] {return SnowheadTempleAccess && GoronMask && MagicMeter && (Hookshot || (Explosives && TwoSnowheadKeys));}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_1F, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_LOWER_PILLAR_FREEZARDS_ROOM, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_LOWER_PILLAR_FREEZARDS_ROOM] = Area("Snowhead Temple Lower Pillar Freezards Room", "Snowhead Temple Lower Pillar Freezards Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_BASEMENT, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_PILLAR_FREEZARDS_ROOM, {[]{return DekuMask && FireArrows && MagicMeter && HerosBow;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_LOWER] = Area("Snowhead Temple Double Block Room Lower", "Snowhead Temple Block Room Lower", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SNOWHEAD_TEMPLE_BLOCK_ROOM_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_1F, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_UPPER, {[]{return false;}}),//cant get up unless hookshot on SF chest?
	});

	areaTable[SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_UPPER] = Area("Snowhead Temple Double Block Room Upper", "Snowhead Temple Double Block Room Upper", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations	
		//LocationAccess(SH_SF_TWIN_BLOCK, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_COMPASS_ROOM, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_LOWER, {[]{return true;}}),//jump lol
	});

	areaTable[SNOWHEAD_TEMPLE_COMPASS_ROOM] = Area("Snowhead Temple Compass Room", "Snowhead Temple Compass Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(SNOWHEAD_TEMPLE_COMPASS_CHEST, {[] {return SnowheadTempleAccess && EnterSnowheadTemple;}}),
		
		//Stray Fairies
		//LocationAccess(SH_SF_ICE_PUZZLE, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && UseFireArrow && (OneSnowheadKey || Hookshot || ZoraMask);}}),
		//LocationAccess(SH_SF_CRATE, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && (Hookshot || (GoronMask && ZoraMask) || (ZoraMask && Explosives) || (GoronMask && OneSnowheadKey && AnyBombBag && UseFireArrow) || (GoronMask && GreatFairyMask && OneSnowheadKey && AnyBombBag));}}),
		
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_ENTRANCE, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_UPPER, {[]{return FireArrows && MagicMeter && HerosBow;}}),
		Entrance(SNOWHEAD_TEMPLE_ICICLE_ROOM, {[]{return BombBag20;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_ICICLE_ROOM] = Area("Snowhead Temple Icicle Room", "Snowhead Temple Icicle Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SNOWHEAD_TEMPLE_ICICLE_ROOM_CHEST, {[] {return HerosBow;}}),
		//LocationAccess(SH_SF_ICICLE_ROOM_WALL, {[] {return HerosBow;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_COMPASS_ROOM, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_GORON_SWITCH_PUZZLE_ROOM, {[]{return SmallKeys(SnowheadTempleKeys, 2);}}),
	});

	areaTable[SNOWHEAD_TEMPLE_GORON_SWITCH_PUZZLE_ROOM] = Area("Snowhead Temple Goron Switch Puzzle Room", "Snowhead Temple Goron Switch Puzzle Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(SH_SF_CEILING_BUBBLE, {[] {return (Hookshot || HerosBow) && GreatFairyMask;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_ICICLE_ROOM, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_2F, {[]{return GoronMask || (FireArrows && MagicMeter && HerosBow);}}),
	});

	areaTable[SNOWHEAD_TEMPLE_MAIN_ROOM_2F] = Area("Snowhead Temple Main Room 2F", "Snowhead Temple Main Room 2F", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(SH_SF_MAIN_ROOM_WALL, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && (UseFireArrow || (Hookshot && ScarecrowSong));}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_GORON_SWITCH_PUZZLE_ROOM, {[]{return GoronMask;}}),
		Entrance(SNOWHEAD_TEMPLE_UPPER_MAP_ROOM, {[]{return GoronMask;}}),
		Entrance(SNOWHEAD_TEMPLE_MINIBOSS_ROOM, {[]{return GoronMask;}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_3F, {[]{return GoronMask && FireArrows && HerosBow && MagicMeter;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_MINIBOSS_ROOM] = Area("Snowhead Temple Miniboss Room", "Snowhead Temple Miniboss Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SNOWHEAD_TEMPLE_FIRE_ARROW_CHEST, {[] {return HerosBow || KokiriSword || GoronMask || Hookshot;}}),//Fighting
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_2F, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_PILLAR_FREEZARDS_ROOM] = Area("Snowhead Temple Pillar Freezards Room", "Snowhead Temple Pillar Freezards Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(SH_SF_PILLAR_FREEZARDS, {[] {return UseFireArrow;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_1F, {[]{return FireArrows && MagicMeter && HerosBow;}}),
		Entrance(SNOWHEAD_TEMPLE_PILLAR_SWITCH_ROOM, {[]{return FireArrows && MagicMeter && HerosBow;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_PILLAR_SWITCH_ROOM] = Area("Snowhead Temple Pillar Switch Room", "Snowhead Temple Pillar Switch Room", SNOWHEAD_TEMPLE, {
		//Events
		EventAccess(&SHSwitchPress, {[]{return SHSwitchPress;}}),//Raise Pillar
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_PILLAR_FREEZARDS_ROOM, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_MAIN_ROOM_3F] = Area("Snowhead Temple Main Room 3F", "Snowhead Temple Main Room 3F", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_4F, {[]{return SHSwitchPress && GoronMask;}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_2F, {[]{return GoronMask;}}),
		Entrance(SNOWHEAD_TEMPLE_SNOW_ROOM, {[]{return SmallKeys(SnowheadTempleKeys, 3) && GoronMask;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_SNOW_ROOM] = Area("Snowhead Temple Snow Room", "Snowhead Temple Snow Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(SH_SF_SNOW_ROOM_BUBBLE, {[] {return SnowheadTempleAccess && EnterSnowheadTemple && GreatFairyMask && LensOfTruth && ((GoronMask && UseFireArrow) || (Hookshot && ZoraMask && OneSnowheadKey && UseFireArrow) || (Hookshot && UseFireArrow && OneSnowheadKey && ScarecrowSong));}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_3F, {[]{return SmallKeys(SnowheadTempleKeys, 3);}}),
		Entrance(SNOWHEAD_TEMPLE_DINOLFOS_ROOM, {[]{return true;}})//maybe FireArrows?
	});

	areaTable[SNOWHEAD_TEMPLE_MAIN_ROOM_4F] = Area("Snowhead Temple Main Room 4F", "Snowhead Temple Main Room 4F", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Location
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_BOSS_ROOM, {[]{return BossKeySnowheadTemple && GoronMask;}}),
		Entrance(SNOWHEAD_TEMPLE_WIZZROBE_ROOM, {[]{return true;}}),//jump or use deku mask to fly over
		Entrance(SNOWHEAD_TEMPLE_BOSS_KEY_ROOM, {[]{return false;}}),//One Way Door
		Entrance(SNOWHEAD_TEMPLE_DINOLFOS_ROOM, {[]{return true;}}),//jump or use deku mask to fly over
	});

	areaTable[SNOWHEAD_TEMPLE_DINOLFOS_ROOM] = Area("Snowhead Temple Dinolfos Room", "Snowhead Temple Dinolfos Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(SH_SF_DINOLFOS_1, {[] {return Fighting;}}),
		//LocationAccess(SH_SF_DINOLFOS_2, {[] {return Fighting;}}),//gotta kill em to get their juices
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_SNOW_ROOM, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_4F, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_WIZZROBE_ROOM] = Area("Snowhead Temple Wizzrobe Room", "Snowhead Temple Wizzrobe Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_4F, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_BOSS_KEY_ROOM, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_BOSS_KEY_ROOM] = Area("Snowhead Temple Boss Key Rom", "Snowhead Temple Boss Key Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SNOWHEAD_TEMPLE_BOSS_KEY_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_WIZZROBE_ROOM, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_4F, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_BOSS_ROOM] = Area("Snowhead Temple Boss Room", "Snowhead Temple Boss Room", SNOWHEAD_TEMPLE, {
		//Events
		EventAccess(&SnowheadClear, {[]{return SnowheadClear || (BossKeySnowheadTemple && GoronMask && FireArrows && HerosBow && MagicMeter);}}),
	}, 
	{
		//Locations
		LocationAccess(GOHT, {[] {return GoronMask && FireArrows && HerosBow && MagicMeter && BossKeySnowheadTemple;}}),
		//LocationAccess(GOHT_HEART_CONTAINER, {[] {return SnowheadTempleAccess && GoronMask && BossKeySnowheadTemple && UseFireArrow && MagicMeter;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_4F, {[]{return true;}}),
		Entrance(SNOWHEAD, {[]{return GoronMask && FireArrows && HerosBow && MagicMeter;}}),//gotta kill boss to leave
	});

	/*--------------------------
	|    GREAT BAY TEMPLE     |
	---------------------------*/
	
	areaTable[GREAT_BAY_TEMPLE_ENTRANCE] = Area("Great Bay Temple Entrance", "Great Bay Temple Entrance", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(GBT_SF_ENTRANCE_TORCHES, {[] {return FireArrows;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_WATER_CONTROL_ROOM, {[]{return true;}}),
		Entrance(ZORA_CAPE, {[]{return Hookshot;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_WATER_CONTROL_ROOM] = Area("Great Bay Temple Water Control Room", "Great Bay Temple Water Control Room", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&ReverseWaterFlow, {[]{return RedSwitch && RedSwitch2;}}),
	},
	{
		//Locations
		//LocationAccess(GBT_SF_SKULLTULA, {[] {return GreatBayTempleAccess && Hookshot;}}),
		//LocationAccess(GBT_SF_WATER_CONTROL_UNDERWATER_BUBBLE, {[] {return GreatBayTempleAccess && Hookshot && (ZoraMask || GreatFairyMask);}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_ENTRANCE, {[]{return true;}}),
		Entrance(GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM, {[]{return ZoraMask;}}),//Needed to trun yellow switch
	});

	areaTable[GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM] = Area("Great Bay Temple Whirlpool Room", "Great Bay Temple Whirlpool Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(GBT_SF_WHIRLPOOL_JAR, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot;}}),
		//LocationAccess(GBT_SF_WHIRLPOOL_BARREL, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_RED_SWITCH_ROOM, {[]{return ZoraMask;}}),
		Entrance(GREAT_BAY_TEMPLE_MAP_ROOM, {[]{return ZoraMask;}}),
		Entrance(GREAT_BAY_TEMPLE_GREEN_SWITCH_ROOM, {[]{return IceArrows && HerosBow && MagicMeter;}}),
		Entrance(GREAT_BAY_TEMPLE_PRE_BOSS_ROOM, {[]{return ReverseWaterFlow && ZoraMask;}}),
		Entrance(GREAT_BAY_TEMPLE_COMPASS_ROOM, {[]{return ReverseWaterFlow && ZoraMask;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_RED_SWITCH_ROOM] = Area("Great Bay Temple Red Switch Room", "Great Bay Temple Red Switch Room", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&RedSwitch, {[]{return IceArrows && MagicMeter && HerosBow;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM, {[]{return ZoraMask;}}),
		Entrance(GREAT_BAY_TEMPLE_PRE_MINIBOSS_ROOM, {[]{return ZoraMask && SmallKeys(GreatBayTempleKeys, 1);}}),
	});

	areaTable[GREAT_BAY_TEMPLE_MAP_ROOM] = Area("Great Bay Temple Map Room", "Great Bay Temple Map Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(GBT_MAP_CHEST, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot;}}),
		//LocationAccess(GBT_SF_LEDGE_JAR, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot && (GreatFairyMask || UseIceArrow);}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_RED_SWITCH2_ROOM, {[]{return ZoraMask && IceArrows && MagicMeter && HerosBow;}}),
		Entrance(GREAT_BAY_TEMPLE_BIO_BABA_ROOM, {[]{return ZoraMask;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_RED_SWITCH2_ROOM] = Area("Great Bay Temple 2nd Red Switch Room", "Great Bay Temple 2nd Red Switch Room", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&RedSwitch2, {[]{return IceArrows && MagicMeter && HerosBow;}}),//Need to freeze chu to get to switch
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_MAP_ROOM, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_BIO_BABA_ROOM] = Area("Great Bay Temple Bio Baba Room", "Great Bay Temple Bio Baba Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(GBT_SF_BIO_BABAS, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_MAP_ROOM, {[]{return ZoraMask;}}),//just swim back, no current
		Entrance(GREAT_BAY_TEMPLE_COMPASS_ROOM, {[]{return ZoraMask;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_COMPASS_ROOM] = Area("Great Bay Temple Compass/Key Room", "Great Bay Temple Compass/Key Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(GBT_COMPASS_CHEST, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot;}}),
		LocationAccess(GBT_SMALL_KEY_CHEST, {[] {return EponasSong && NewWaveBossaNova && ZoraMask && Hookshot;}}),
		//LocationAccess(GBT_SF_DEXIHANDS_JAR, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot;}}),
		
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_BIO_BABA_ROOM, {[]{return true;}}),
		Entrance(GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM, {[]{return !ReverseWaterFlow;}}),
		Entrance(GREAT_BAY_TEMPLE_FROG_MINIBOSS_ROOM, {[]{return IceArrows && HerosBow && MagicMeter && FireArrows;}}),
		Entrance(GREAT_BAY_TEMPLE_WATER_WHEEL_ROOM, {[]{return ReverseWaterFlow;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_FROG_MINIBOSS_ROOM] = Area("Great Bay Temple Frog MiniBoss", "Great Bay Temple Frog MiniBoss", GREAT_BAY_TEMPLE, {
		//Events
		//Frog
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_COMPASS_ROOM, {[]{return true;}}),
		Entrance(GREAT_BAY_TEMPLE_BOSS_KEY_ROOM, {[]{return IceArrows && HerosBow && MagicMeter;}}),//need to beat frog to leave
	});

	areaTable[GREAT_BAY_TEMPLE_BOSS_KEY_ROOM] = Area("Great Bay Temple Boss Key Room", "Great Bay Temple Boss Key Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBT_BOSS_KEY_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_FROG_MINIBOSS_ROOM, {[]{return true;}}),
		Entrance(GREAT_BAY_TEMPLE_COMPASS_ROOM, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_PRE_MINIBOSS_ROOM] = Area("Great Bay Temple Pre-Miniboss Room", "Great Bay Temple Pre-Miniboss Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_RED_SWITCH_ROOM, {[]{return true;}}),
		Entrance(GREAT_BAY_TEMPLE_MINI_BOSS_ROOM, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_MINI_BOSS_ROOM] = Area("Great Bay Temple Miniboss Room", "Great Bay Temple Miniboss Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBT_ICE_ARROW_CHEST, {[] {return ZoraMask && Hookshot;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_PRE_MINIBOSS_ROOM, {[]{return ZoraMask || Hookshot || KokiriSword || HerosBow;}}),//some kind of fighting
	});

	areaTable[GREAT_BAY_TEMPLE_GREEN_SWITCH_ROOM] = Area("Great Bay Temple Green Switch Room", "Great Bay Temple Green Switch Room", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&GreenSwitch, {[]{return ZoraMask && IceArrows && HerosBow && MagicMeter;}}),
	},
	{
		//Locations
		//LocationAccess(GBT_SF_GREEN_VALVE, {[] {return Hookshot && UseIceArrow;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_WATER_WHEEL_ROOM] = Area("Great Bay Temple Waterwheel Room", "Great Bay Temple Waterwheel Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(GBT_SF_WATERWHEEL_ROOM_LOWER, {[] {return Hookshot && ZoraMask && GBTReverseWaterDirection;}}),
		//LocationAccess(GBT_SF_WATERWHEEL_ROOM_UPPER, {[] {return ZoraMask && Hookshot && UseIceArrow;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_COMPASS_ROOM, {[]{return false;}}),//Cant go back against current
		Entrance(GREAT_BAY_TEMPLE_SEESAW_ROOM, {[]{return IceArrows && FireArrows && HerosBow && MagicMeter;}}),//FireArrows included to avoid potential softlock
	});

	areaTable[GREAT_BAY_TEMPLE_SEESAW_ROOM] = Area("Great Bay Temple Seesaw Room", "Great Bay Temple Seesaw Room", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&GreenSwitch2, {[]{return FireArrows && IceArrows && HerosBow && MagicMeter;}}),
	},
	{
		//Locations
		//LocationAccess(GBT_SF_SEESAW_ROOM, {[] {return UseFireArrow;}}),
		//LocationAccess(GBT_SF_UNDERWATER_BARREL, {[] {return ZoraMask;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_WATER_WHEEL_ROOM, {[]{return true;}}),
		Entrance(GREAT_BAY_TEMPLE_MAP_ROOM, {[]{return FireArrows && IceArrows && HerosBow && MagicMeter;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_PRE_BOSS_ROOM] = Area("Great Bay Temple Pre-Boss Room", "Great Bay Temple Pre-Boss Room", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&GreenValve, {[]{return GreenSwitch && GreenSwitch2;}}),
	},
	{
		//Locations
		//LocationAccess(GBT_SF_PRE_BOSS_ROOM_BUBBLE, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot && UseIceArrow;}}),
		//LocationAccess(GBT_SF_PRE_BOSS_ROOM_UNDERWATER_BUBBLE, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot && UseIceArrow;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM, {[]{return ZoraMask;}}),
		Entrance(GREAT_BAY_TEMPLE_BOSS_ROOM, {[]{return BossKeyGreatBayTemple && GreenValve;}}),
	});
	
	areaTable[GREAT_BAY_TEMPLE_BOSS_ROOM] = Area("Great Bay Temple Boss Room", "Great Bay Temple Boss Room", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&GreatBayClear, {[]{return GreatBayClear || (BossKeyGreatBayTemple && ZoraMask && IceArrows && HerosBow && MagicMeter);}}),
	},
	{
		//Locations
		LocationAccess(GYORG, {[] {return EponasSong && NewWaveBossaNova && ZoraMask && Hookshot && BossKeyGreatBayTemple && IceArrows && FireArrows && HerosBow && MagicMeter;}}),
		//LocationAccess(GYORG_HEART_CONTAINER, {[] {return GreatBayTempleAccess && ZoraMask && Hookshot && BossKeyGreatBayTemple && UseIceArrow && UseFireArrow && MagicMeter;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_PRE_BOSS_ROOM, {[]{return true;}}),
		Entrance(ZORA_CAPE, {[]{return IceArrows && ZoraMask && HerosBow && MagicMeter;}}),
	});

	/*--------------------------
	|   STONE TOWER TEMPLE     |
	---------------------------*/

	areaTable[STONE_TOWER_TEMPLE_ENTRANCE] = Area("Stone Tower Temple Entrance", "Stone Tower Temple Entrance", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(ST_SF_STATUE_EYE, {[] {return StoneTowerTempleAcccess && Arrows;}}),
		//LocationAccess(ST_SF_DEATH_ARMOS, {[] {return InvertedStoneTowerTempleAccess && StoneTowerTempleAcccess && DekuMask && Hookshot && GoronMask && OneStoneTowerKey && UseLightArrow;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_UPRIGHT_DEATH_ARMOS_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_UPRIGHT_UPDRAFT_ROOM, {[]{return LightArrows && HerosBow && MagicMeter;}}),
		Entrance(STONE_TOWER_TEMPLE_EYEGORE_ROOM, {[]{return false;}}),//OneWay
	});

	areaTable[STONE_TOWER_TEMPLE_UPRIGHT_DEATH_ARMOS_ROOM] = Area("Stone Tower Temple Upright Death Armos Room", "Stone Tower Temple Upright Death Armos Room", STONE_TOWER_TEMPLE, {
		//Events
		EventAccess(&ArmosRoomLightHole, {[]{return ElegyOfEmptiness && ZoraMask && GoronMask && BombBag20;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_ENTRANCE, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_ARMOS_ROOM, {[]{return ElegyOfEmptiness && ZoraMask && GoronMask;}}),
		Entrance(STONE_TOWER_TEMPLE_WATER_BRIDGE_ROOM, {[]{return ElegyOfEmptiness && ZoraMask && GoronMask && SmallKeys(StoneTowerTempleKeys, 1);}}), 
	});

	areaTable[STONE_TOWER_TEMPLE_ARMOS_ROOM] = Area("Stone Tower Temple Armos Room", "Stone Tower Temple Armos Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(STONE_TOWER_TEMPLE_MAP_CHEST, {[] {return true;}}),
		LocationAccess(STONE_TOWER_TEMPLE_ARMOS_ROOM_CHEST, {[] {return ArmosRoomLightHole && (MirrorShield || (LightArrows && MagicMeter && HerosBow));}}), // || (GoronMask && Explosives && UseLightArrow) || (ZoraMask && OneStoneTowerKey && UseLightArrow))
		//LocationAccess(ST_SF_BASEMENT_LEDGE, {[] {return Hookshot;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_UPRIGHT_DEATH_ARMOS_ROOM, {[]{return true;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_WATER_BRIDGE_ROOM] = Area("Stone Tower Temple Water Bridge Room", "Stone Tower Temple Water Bridge Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_BRIDGE_SWITCH_CHEST, {[] {return DekuMask && ZoraMask;}}), //|| ((ZoraMask && UseLightArrow))
		//StrayFairies
		//LocationAccess(ST_SF_BRIDGE_CRYSTAL, {[] {return StoneTowerTempleAcccess && ZoraMask && UseLightArrow;}}),
		
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_ARMOS_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_UPRIGHT_UPDRAFT_ROOM, {[]{return ZoraMask;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_UPRIGHT_UPDRAFT_ROOM] = Area("Stone Tower Temple Upright Updraft Room", "Stone Tower Temple Upright Updraft Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(STONE_TOWER_TEMPLE_COMPASS_CHEST, {[] {return MirrorShield || UseLightArrow);}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_ENTRANCE, {[]{return MirrorShield || (LightArrows && MagicMeter && HerosBow);}}),
		Entrance(STONE_TOWER_TEMPLE_SUN_BLOCK_PUZZLE_ROOM, {[]{return ZoraMask && SmallKeys(StoneTowerTempleKeys, 2);}}),
	});

	areaTable[STONE_TOWER_TEMPLE_SUN_BLOCK_PUZZLE_ROOM] = Area("Stone Tower Temple Sun Block Puzzle Room", "Stone Tower Temple Sun Block Puzzle Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(ST_SF_MIRROR_SUN_BLOCK, {[] {return ((MirrorShield && GoronMask) || (UseLightArrow));}}),
		//LocationAccess(ST_SF_MIRROR_SUN_SWITCH, {[] {return ((MirrorShield && GoronMask) || (UseLightArrow));}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_UPRIGHT_UPDRAFT_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_LAVA_ROOM, {[]{return ((MirrorShield && GoronMask) || (LightArrows && MagicMeter && HerosBow));}}),
	});

	areaTable[STONE_TOWER_TEMPLE_LAVA_ROOM] = Area("Stone Tower Temple Lava Room", "Stone Tower Temple Lava Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(ST_SF_LAVA_ROOM_LEDGE, {[] {return DekuMask;}}),
		//LocationAccess(ST_SF_LAVA_ROOM_FIRE_RING, {[] {return GoronMask && DekuMask;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_SUN_BLOCK_PUZZLE_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_GARO_ROOM, {[]{return DekuMask;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_GARO_ROOM] = Area("Stone Tower Temple Garo Miniboss Room", "Stone Tower Temple Garo Miniboss Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_LIGHT_ARROW_CHEST, {[] {return KokiriSword;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_THIN_BRIDGE_ROOM, {[]{return KokiriSword;}}),
		Entrance(STONE_TOWER_TEMPLE_LAVA_ROOM, {[]{return false;}}),//OneWay Door
	});

	areaTable[STONE_TOWER_TEMPLE_THIN_BRIDGE_ROOM] = Area("Stone Tower Temple Thin Bridge Room", "Stone Tower Temple Thin Bridge Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(ST_SF_THIN_BRIDGE, {[] {return InvertedStoneTowerTempleAccess && ThreeStoneTowerKeys && UseLightArrow;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_EYEGORE_ROOM, {[]{return Hookshot;}}),
		Entrance(STONE_TOWER_TEMPLE_GARO_ROOM, {[]{return false;}})//One Way Door
	});

	areaTable[STONE_TOWER_TEMPLE_EYEGORE_ROOM] = Area("Stone Tower Temple Eyegore Room", "Stone Tower Temple Eyegore Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(ST_SF_EYEGORE, {[] {return Hookshot || HerosBow;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_ENTRANCE, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_THIN_BRIDGE_ROOM, {[]{return false;}}),//One Way Door
	});

	areaTable[STONE_TOWER_TEMPLE_INVERTED_ENTRANCE] = Area("Inverted Stone Tower Temple Entrance Room", "Inverted Stone Tower Temple Entrance Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(ST_SF_BOSS_WARP, {[] {return InvertedChestSpawn;}}),//replaces the boss warp one from 64?
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_UPDRAFT_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_INVERTED_THIN_BRIDGE_ROOM, {[]{return Hookshot && InvertedChestSpawn;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_UPDRAFT_ROOM] = Area("Inverted Stone Tower Temple Updraft Room", "Inverted Stone Tower Temple Updraft Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_UPDRAFT_ROOM_CHEST, {[] {return DekuMask;}}),		
		//LocationAccess(ST_SF_UPDRAFT_FROZEN_EYE, {[] {return InvertedStoneTowerTempleAccess && UseFireArrow && UseLightArrow && (DekuMask || Hookshot);}}),
		//LocationAccess(ST_SF_UNDERWATER, {[] {return StoneTowerTempleAcccess && ZoraMask && UseLightArrow && InvertedStoneTowerTempleAccess && DekuMask;}}),
		//LocationAccess(ST_SF_UPDRAFT_FIRE_RING, {[] {return StoneTowerTempleAcccess && InvertedStoneTowerTempleAccess && ZoraMask && DekuMask && UseLightArrow;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_INVERTED_ENTRANCE, {[]{return DekuMask;}}),
		Entrance(STONE_TOWER_TEMPLE_FLIPPING_LAVA_ROOM, {[]{return DekuMask && SmallKeys(StoneTowerTempleKeys, 3);}}),
	});

	areaTable[STONE_TOWER_TEMPLE_FLIPPING_LAVA_ROOM] = Area("Inverted Stone Tower Temple Flipping Lava Room", "Inverted Stone Tower Temple Flipping Lava Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_UPDRAFT_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_FLIPPING_BLOCK_PUZZLE, {[]{return LightArrows && HerosBow && MagicMeter;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_FLIPPING_BLOCK_PUZZLE] = Area("Inverted Stone Tower Flipping Block Puzzle", "Inverted Stone Tower Flipping Block Puzzle", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_FLIPPING_LAVA_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_WIZZROBE_ROOM, {[]{return LightArrows && HerosBow && MagicMeter;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_WIZZROBE_ROOM] = Area("Inverted Stone Tower Temple Wizzrobe Room", "Inverted Stone Tower Temple Wizzrobe Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(ST_SF_WIZZROBE, {[] {return InvertedStoneTowerTempleAccess && DekuMask && Hookshot && GoronMask && OneStoneTowerKey && UseLightArrow;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_FLIPPING_BLOCK_PUZZLE, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM, {[]{return Hookshot;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM] = Area("Inverted Stone Tower Temple Death Armos Room", "Inverted Stone Tower Temple Death Armos Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM_CHEST, {[] {return DekuMask && LightArrows && HerosBow && MagicMeter;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_WIZZROBE_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_INVERTED_BRIDGE_ROOM, {[]{return DekuMask;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_INVERTED_BRIDGE_ROOM] = Area("Inverted Stone Tower Temple Bridge Room", "Inverted Stone Tower Temple Bridge Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_INVERTED_ENTRANCE_DEATH_ARMOS_LEDGE, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_PRE_GOMESS_ROOM, {[]{return DekuMask && HerosBow;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_INVERTED_ENTRANCE_DEATH_ARMOS_LEDGE] = Area("Inverted Stone Tower Temple Entrance Death Armos Ledge", "Inverted Stone Tower Temple Entrance Death Armos Ledge", STONE_TOWER_TEMPLE, {
		//Events
		EventAccess(&InvertedChestSpawn, {[]{return true;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_INVERTED_BRIDGE_ROOM, {[]{return true;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_PRE_GOMESS_ROOM] = Area("Inverted Stone Tower Temple Pre-Gomess Hallway", "Inverted Stone Tower Temple Pre-Gomess Hallway", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_INVERTED_BRIDGE_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_GOMESS_ROOM, {[]{return true;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_GOMESS_ROOM] = Area("Inverted Stone Tower Temple Gomess Room", "Inverted Stone Tower Temple Gomess Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_BOSS_KEY_CHEST, {[] {return LightArrows && HerosBow && MagicMeter;}}),
		
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_PRE_GOMESS_ROOM, {[]{return LightArrows && HerosBow && MagicMeter;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_INVERTED_THIN_BRIDGE_ROOM] = Area("Inverted Stone Tower Thin Bridge Room", "Inverted Stone Tower Thin Bridge Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_INVERTED_ENTRANCE, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_PRE_BOSS_ROOM, {[]{return BossKeyStoneTowerTemple && Hookshot;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_PRE_BOSS_ROOM] = Area("Stone Tower Temple Pre-Boss Room", "Stone Tower Temple Pre-Boss Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_BOSS_ROOM, {[]{return true;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_BOSS_ROOM] = Area("Stone Tower Temple Boss Room", "Stone Tower Temple Boss Room", STONE_TOWER_TEMPLE, {
		//Events
		EventAccess(&StoneTowerClear, {[]{return StoneTowerClear || (BossKeyStoneTowerTemple && GiantsMask && LightArrows && HerosBow && MagicMeter);}}),
	}, 
	{
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_GIANTS_MASK_CHEST, {[] {return LightArrows && HerosBow && MagicMeter && BossKeyStoneTowerTemple;}}),
		
		LocationAccess(TWINMOLD, {[] {return LightArrows && HerosBow && MagicMeter && BossKeyStoneTowerTemple && GiantsMask;}}),
		//LocationAccess(TWINMOLD_HEART_CONTAINER, {[] {return InvertedStoneTowerTempleAccess && Hookshot && UseLightArrow && BossKeyStoneTowerTemple && GiantsMask;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE, {[]{return LightArrows && HerosBow && MagicMeter && BossKeyStoneTowerTemple && GiantsMask;}}),
	});

	areaTable[PIRATE_FORTRESS_EXTERIOR] = Area("Pirates Fortress Exterior", "Pirates Fortress Exterior", PIRATE_FORTRESS, {
		//Events
	},
	{
		//Locations
		LocationAccess(PF_EXTERIOR_LOG_CHEST, {[] {return ZoraMask;}}),
		LocationAccess(PF_EXTERIOR_SAND_CHEST, {[] {return ZoraMask;}}),
		LocationAccess(PF_EXTERIOR_CORNER_CHEST, {[] {return ZoraMask;}}),
	},
	{
		//Exits
		Entrance(ZORA_CAPE, {[]{return ZoraMask;}}),
		Entrance(PIRATE_FORTRESS_MAZE_ROOM, {[]{return ZoraMask && GoronMask;}}),
	});

	areaTable[PIRATE_FORTRESS_MAZE_ROOM] = Area("Pirates Fortress Maze Room", "Pirates Fortress Maze Room", PIRATE_FORTRESS, {
		//Events
	},
	{
		//Locations
		LocationAccess(PF_MAZE_CHEST, {[] {return ZoraMask;}}),
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_INTERIOR, {[]{return ZoraMask;}}),
		Entrance(PIRATE_FORTRESS_CAGE_ROOM, {[]{return ZoraMask;}}),
	});

	areaTable[PIRATE_FORTRESS_CAGE_ROOM] = Area("Pirates Fortress Cage Room", "Pirates Fortress Cage Room", PIRATE_FORTRESS, {
		//Events
	},
	{
		//Locations
		LocationAccess(PF_CAGE_ROOM_SHALLOW_CHEST, {[] {return ZoraMask;}}),
		LocationAccess(PF_CAGE_ROOM_DEEP_CHEST, {[]{return ZoraMask;}}),
		//LocationAccess(PF_SEWER_CAGE, {[] {return ZoraMask;}}),
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_MAZE_ROOM, {[]{return ZoraMask;}}),
		Entrance(PIRATE_FORTRESS_EXTERIOR_TOP, {[]{return ZoraMask;}}),
	});

	areaTable[PIRATE_FORTRESS_EXTERIOR_TOP] = Area("Pirates Fortress Exterior Top", "Pirates Fortress Exterior Top", PIRATE_FORTRESS, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_CAGE_ROOM, {[]{return true;}}),
		Entrance(PIRATE_FORTRESS_EXTERIOR, {[]{return true;}}),
		Entrance(PIRATE_FORTRESS_INTERIOR, {[]{return true;}}),
	});

	areaTable[PIRATE_FORTRESS_INTERIOR] = Area("Pirates Fortress Interior", "Pirates Fortress Interior", PIRATE_FORTRESS, {
		//Events
	},
	{
		//Locations
		LocationAccess(PF_INT_LOWER_CHEST, {[] {return ZoraMask && Hookshot;}}),
		LocationAccess(PF_INT_UPPER_CHEST, {[] {return ZoraMask && Hookshot;}}),
		//LocationAccess(PF_INT_INVISIBLE_SOLDIER, {[] {return LensOfTruth && MagicMeter && AnyHealingPotion;}}),
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_EXTERIOR_TOP, {[]{return true;}}),
		Entrance(PIRATE_FORTRESS_HOOKSHOT_ROOM, {[]{return true;}}),
		Entrance(PIRATE_FORTRESS_HOOKSHOT_ROOM_TOP, {[]{return HerosBow || Hookshot;}}),
		Entrance(PIRATE_FORTRESS_BARREL_MAZE, {[]{return Hookshot;}}),
		Entrance(PIRATE_FORTRESS_LAVA_ROOM, {[]{return Hookshot;}}),
		Entrance(PIRATE_FORTRESS_GUARD_ROOM, {[]{return Hookshot;}}),
	});

	areaTable[PIRATE_FORTRESS_HOOKSHOT_ROOM] = Area("Pirates Fortress Hookshot Room", "Pirates Fortress Hookshot Room", PIRATE_FORTRESS, {
		//Events
		//ZoraEgg1
	},
	{
		//Locations
		LocationAccess(PF_INTERIOR_HOOKSHOT_CHEST, {[] {return PirateBees;}}),
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_INTERIOR, {[]{return true;}}),
	});

	areaTable[PIRATE_FORTRESS_HOOKSHOT_ROOM_TOP] = Area("Pirates Fortress Upper Hookshot Room", "Pirates Fortress Upper Hookshot Room", PIRATE_FORTRESS, {
		//Events
		EventAccess(&PirateBees, {[]{return HerosBow || Hookshot;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_INTERIOR, {[]{return true;}}),
		Entrance(PIRATE_FORTRESS_HOOKSHOT_ROOM, {[]{return PirateBees;}}),
	});

	areaTable[PIRATE_FORTRESS_BARREL_MAZE] = Area("Pirates Fortress Barrel Maze", "Pirates Fortress Barrel Maze", PIRATE_FORTRESS, {
		//Events
	},
	{
		//Locations
		//ZoraEgg2
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_INTERIOR, {[]{return Hookshot && KokiriSword;}}),
	});

	areaTable[PIRATE_FORTRESS_LAVA_ROOM] = Area("Pirate Fortress Lava Room", "Pirate Fortress Lava Room", PIRATE_FORTRESS, {
		//Events
	}, 
	{
		//Locations
		LocationAccess(PF_INT_TANK_CHEST, {[] {return ZoraMask && EponasSong && Hookshot;}}),
		//ZoraEgg3
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_INTERIOR, {[]{return Hookshot && KokiriSword;}}),
	});

	areaTable[PIRATE_FORTRESS_GUARD_ROOM] = Area("Pirates Fortress Guard Room", "Pirates Fortress Guard Room", PIRATE_FORTRESS, {
		//Events
	}, 
	{
		//Locations
		LocationAccess(PF_INT_GUARD_ROOM_CHEST, {[] {return Hookshot || HerosBow;}}),//StoneMask
		//ZoraEgg4
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_INTERIOR, {[]{return Hookshot && KokiriSword;}}),
	});

	areaTable[BENEATH_THE_WELL_ENTRANCE] = Area("Beneath The Well Entrance", "Beneath The Well Entrance", BENEATH_THE_WELL, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CANYON_UPPER, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_LEFT_PATH_ROOM, {[]{return WitchBottle && GibdosMask;}}),
		Entrance(BENEATH_THE_WELL_RIGHT_PATH_ROOM, {[]{return GibdosMask && MagicBean;}}),
	});

	areaTable[BENEATH_THE_WELL_LEFT_PATH_ROOM] = Area("Beneath The Well Left Path", "Beneath The Well Left Path", BENEATH_THE_WELL, {
		//Events
		EventAccess(&LoneFish, {[]{return WitchBottle;}}),
		EventAccess(&SpringWater, {[]{return WitchBottle;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_ENTRANCE, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_LEFT_PATH_HOT_WATER_ROOM, {[]{return GibdosMask && WitchBottle && FishAccess;}}),
		Entrance(BENEATH_THE_WELL_LEFT_PATH_RIGHT_DOOR_ROOM, {[]{return GibdosMask && WitchBottle && SpringWater;}}),
	});

	areaTable[BENEATH_THE_WELL_LEFT_PATH_HOT_WATER_ROOM] = Area("Beneath The Well Hot Water Room", "Beneath The Well Hot Water Room", BENEATH_THE_WELL, {
		//Events
		EventAccess(&FishGroup, {[]{return WitchBottle;}}),
		EventAccess(&HotSpringWater, {[]{return WitchBottle;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_LEFT_PATH_ROOM, {[]{return true;}}),
	});

	areaTable[BENEATH_THE_WELL_LEFT_PATH_RIGHT_DOOR_ROOM] = Area("Beneath The Well Left Path Right Room", "Beneath The Well Left Path Right Room", BENEATH_THE_WELL, {
		//Events
		EventAccess(&WanderingBugs, {[]{return WitchBottle;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_LEFT_PATH_ROOM, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_LEFT_PATH_FAIRY_FOUNTAIN, {[]{return GibdosMask && BugsAccess && WitchBottle;}}),
		Entrance(BENEATH_THE_WELL_LEFT_PATH_CHEST_ROOM, {[]{return GibdosMask && BugsAccess && WitchBottle;}}),
	});

	areaTable[BENEATH_THE_WELL_LEFT_PATH_FAIRY_FOUNTAIN] = Area("Beneath The Well Fairy Fountain", "Beneath The Well Fairy Fountain", BENEATH_THE_WELL, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_LEFT_PATH_RIGHT_DOOR_ROOM, {[]{return true;}}),
	});

	areaTable[BENEATH_THE_WELL_LEFT_PATH_CHEST_ROOM] = Area("Beneath The Well Left Path Chest", "Beneath The Well Left Path Chest", BENEATH_THE_WELL, {
		//Events
	},
	{
		//Locations
		LocationAccess(WELL_LEFT_PATH_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_LEFT_PATH_RIGHT_DOOR_ROOM, {[]{return true;}}),
	});

	areaTable[BENEATH_THE_WELL_RIGHT_PATH_ROOM] = Area("Beneath The Well Right Path", "Beneath The Well Right Path", BENEATH_THE_WELL, {
		//Events
		EventAccess(&DekuBabaNuts, {[]{return KokiriSword;}}),
		EventAccess(&DekuBabaSticks, {[]{return KokiriSword;}}),
		EventAccess(&SpringWater, {[]{return WitchBottle;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_ENTRANCE, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_RIGHT_PATH_LEFT_DOOR_ROOM, {[]{return GibdosMask && WitchBottle && FishAccess;}}),
		Entrance(BENEATH_THE_WELL_PRE_COW_AND_BIG_POE_ROOM, {[]{return GibdosMask && DekuBabaNuts;}}),
	});

	areaTable[BENEATH_THE_WELL_PRE_COW_AND_BIG_POE_ROOM] = Area("Beneath The Well Before Cow/Big Poe Room", "Beneath The Well Before Cow/Big Poe Room", BENEATH_THE_WELL, {
		//Events
		EventAccess(&WanderingBugs, {[]{return WitchBottle;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_RIGHT_PATH_ROOM, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_COW_ROOM, {[]{return GibdosMask && HotSpringWater && WitchBottle;}}),
		Entrance(BENEATH_THE_WELL_BIG_POE_ROOM, {[]{return GibdosMask && BombBag20;}}),
	});

	areaTable[BENEATH_THE_WELL_COW_ROOM] = Area("Beneath The Well Cow Room", "Beneath The Well Cow Room", BENEATH_THE_WELL, {
		//Events
		//Milk?
	},
	{
		//Locations
		//LocationAccess(BENEATH_THE_WELL_COW, {[]{return EponasSong && AnyBottle;}}),
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_PRE_COW_AND_BIG_POE_ROOM, {[]{return true;}}),
	});

	areaTable[BENEATH_THE_WELL_BIG_POE_ROOM] = Area("Beneath The Well Big Poe Room", "Beneath The Well Big Poe Room", BENEATH_THE_WELL, {
		//Events
		EventAccess(&BigPoe, {[]{return HerosBow && WitchBottle;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_PRE_COW_AND_BIG_POE_ROOM, {[]{return true;}}),
	});

	areaTable[BENEATH_THE_WELL_RIGHT_PATH_LEFT_DOOR_ROOM] = Area("Beneath The Well Right Path Left Door Room", "Beneath The Well Right Path Left Door Room", BENEATH_THE_WELL, {
		//Events
		EventAccess(&DekuBabaNuts, {[]{return KokiriSword;}}),
		EventAccess(&DekuBabaSticks, {[]{return KokiriSword;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_RIGHT_PATH_ROOM, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_RIGHT_PATH_CHEST_ROOM, {[]{return GibdosMask && WitchBottle && BugsAccess;}}),
		Entrance(BENEATH_THE_WELL_PRE_MIRROR_SHIELD_ROOM, {[]{return GibdosMask && WitchBottle && BigPoe;}}),
	});

	areaTable[BENEATH_THE_WELL_RIGHT_PATH_CHEST_ROOM] = Area("Beneath The Well Right Path Chest Room", "Beneath The Well Right Path Chest Room", BENEATH_THE_WELL, {
		//Events
	},
	{
		//Locations
		LocationAccess(WELL_RIGHT_PATH_CHEST, {[] {return FireArrows && MagicMeter && HerosBow;}}),
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_RIGHT_PATH_LEFT_DOOR_ROOM, {[]{return true;}}),
	});

	areaTable[BENEATH_THE_WELL_PRE_MIRROR_SHIELD_ROOM] = Area("Beneath The Well Pre Mirror Shield Room", "Beneath The Well Pre Mirror Shield Room", BENEATH_THE_WELL, {
		//Events
		EventAccess(&WanderingBugs, {[]{return WitchBottle;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_RIGHT_PATH_LEFT_DOOR_ROOM, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_MIRROR_SHIELD_ROOM, {[]{return WitchBottle;}}),
	});

	areaTable[BENEATH_THE_WELL_MIRROR_SHIELD_ROOM] = Area("Beneath The Well Mirror Shield Room", "Beneath The Well Mirror Shield Room", BENEATH_THE_WELL, {
		//Events
	}, 
	{
		//Locations
		LocationAccess(BENEATH_THE_WELL_MIRROR_SHIELD_CHEST, {[] {return FireArrows && HerosBow && MagicMeter;}}),// || (UseFireArrow && UseLightArrow))
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_PRE_MIRROR_SHIELD_ROOM, {[]{return true;}}),
		Entrance(IKANA_CASTLE_EXTERIOR_LOWER, {[]{return MirrorShield || (LightArrows && MagicMeter && HerosBow);}}),
	});

	areaTable[IKANA_CASTLE_EXTERIOR_LOWER] = Area("Ikana Castle Lower Exterior", "Ikana Castle Lower Exterior", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CANYON_UPPER, {[]{return LightArrows && HerosBow && MagicMeter;}}),
		Entrance(BENEATH_THE_WELL_MIRROR_SHIELD_ROOM, {[]{return true;}}),
		Entrance(IKANA_CASTLE_ENTRANCE, {[]{return true;}}),
	});

	areaTable[IKANA_CASTLE_ENTRANCE] = Area("Ikana Castle Entrance", "Ikana Castle Entrance", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_LAVA_BLOCKS_ROOM, {[]{return FireArrows && HerosBow && MagicMeter;}}),
		Entrance(IKANA_CASTLE_RIGHT_ROOM, {[]{return FireArrows && HerosBow && MagicMeter;}}),
		Entrance(IKANA_CASTLE_THRONE_ROOM, {[]{return IkanaCastleRoofHole;}}),
	});

	areaTable[IKANA_CASTLE_LAVA_BLOCKS_ROOM] = Area("Ikana Castle Lava Blocks Room", "Ikana Castle Lava Blocks Room", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_ENTRANCE, {[]{return true;}}),
		Entrance(IKANA_CASTLE_NO_FLOOR_ROOM, {[]{return DekuMask;}}),
	});

	areaTable[IKANA_CASTLE_NO_FLOOR_ROOM] = Area("Ikana Castle No Floor Room", "Ikana Castle No Floor Room", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_LAVA_BLOCKS_ROOM, {[]{return DekuMask;}}),
		Entrance(IKANA_CASTLE_LEFT_STAIRWELL, {[]{return DekuMask;}}),
	});

	areaTable[IKANA_CASTLE_LEFT_STAIRWELL] = Area("Ikana Castle Left Stairwell", "Ikana Castle Left Stairwell", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_NO_FLOOR_ROOM, {[]{return true;}}),
		Entrance(IKANA_CASTLE_EXTERIOR_UPPER_LEFT, {[]{return true;}}),
	});

	areaTable[IKANA_CASTLE_EXTERIOR_UPPER_LEFT] = Area("Ikana Castle Exterior Upper Left", "Ikana Castle Exterior Upper Left", IKANA_CASTLE, {
		//Events
		EventAccess(&IkanaLightSwitch, {[]{return DekuMask;}}),
	},
	{
		//Locations
		//LocationAccess(IKANA_CASTLE_PILLAR, {[] {return DekuMask;}}),
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_LEFT_STAIRWELL, {[]{return true;}}),
		Entrance(IKANA_CASTLE_EXTERIOR_LOWER, {[]{return true;}}),
	});

	areaTable[IKANA_CASTLE_RIGHT_ROOM] = Area("Ikana Castle Right Room", "Ikana Castle Right Room", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_ENTRANCE, {[]{return true;}}),
		Entrance(IKANA_CASTLE_WIZZROBE_ROOM, {[]{return (MirrorShield && IkanaLightSwitch) || (LightArrows && MagicMeter && HerosBow);}})
	});

	areaTable[IKANA_CASTLE_WIZZROBE_ROOM] = Area("Ikana Castle Wizzrobe Room", "Ikana Castle Wizzrobe Room", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_RIGHT_ROOM, {[]{return true;}}),
		Entrance(IKANA_CASTLE_RIGHT_STAIRWELL, {[]{return HerosBow;}}),
	});

	areaTable[IKANA_CASTLE_RIGHT_STAIRWELL] = Area("Ikana Castle Right Stairwell", "Ikana Castle Right Starwell", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_WIZZROBE_ROOM, {[]{return true;}}),
		Entrance(IKANA_CASTLE_EXTERIOR_UPPER_RIGHT, {[]{return true;}}),
	});

	areaTable[IKANA_CASTLE_EXTERIOR_UPPER_RIGHT] = Area("Ikana Castle Exterior Upper Right", "Ikana Caastle Exterior Upper Right", IKANA_CASTLE, {
		//Events
		EventAccess(&IkanaCastleRoofHole, {[]{return PowderKeg;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_RIGHT_STAIRWELL, {[]{return true;}}),
		Entrance(IKANA_CASTLE_ENTRANCE, {[]{return IkanaCastleRoofHole;}}),
		Entrance(IKANA_CASTLE_EXTERIOR_LOWER, {[]{return true;}}),
	});

	areaTable[IKANA_CASTLE_THRONE_ROOM] = Area("Ikana Castle Throne Room", "Ikana Castle Throne Room", IKANA_CASTLE, {
		//Events
	}, 
	{
		//Locations
		LocationAccess(IKANA_CASTLE_IKANA_KING, {[] {return (LightArrows || MirrorShield) && KokiriSword && FireArrows && HerosBow && MagicMeter;}}),
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_ENTRANCE, {[]{return true;}}),
	});


	areaTable[SECRET_SHRINE] = Area("Secret Shrine", "Secret Shrine", SECRET_SHRINE, {
		//Events
	}, 
	{
		//Locations
		LocationAccess(SECRET_SHRINE_DINOLFOS_CHEST, {[] {return KokiriSword && LightArrows && HerosBow && MagicMeter;}}),
		LocationAccess(SECRET_SHRINE_WIZZROBE_CHEST, {[] {return KokiriSword && LightArrows && HerosBow && MagicMeter;}}),
		LocationAccess(SECRET_SHRINE_WART_CHEST, {[] {return KokiriSword && LightArrows && HerosBow && MagicMeter;}}),
		LocationAccess(SECRET_SHRINE_GARO_CHEST, {[] {return KokiriSword && LightArrows && HerosBow && MagicMeter;}}),
		LocationAccess(SECRET_SHRINE_FINAL_CHEST, {[] {return KokiriSword && LightArrows && HerosBow && MagicMeter;}}),
	},
	{
		//Exits
		Entrance(IKANA_CANYON, {[]{return true;}}),
	});

	areaTable[THE_MOON] = Area("The Moon", "The Moon", THE_MOON, {
		//Events
	}, 
	{
		//Locations
		/*
		LocationAccess(THE_MOON_DEKU_TRIAL_BONUS, {[] {return MoonAccess && DekuMask && OneMask;}}),
		LocationAccess(THE_MOON_GORON_TRIAL_BONUS, {[] {return MoonAccess && GoronMask && TwoMasks && MagicMeter;}}),
		LocationAccess(THE_MOON_ZORA_TRIAL_BONUS, {[] {return MoonAccess && ZoraMask && ThreeMasks;}}),
		LocationAccess(THE_MOON_LINK_TRIAL_BONUS, {[] {return MoonAccess && Explosives && UseFireArrow && Hookshot && MagicMeter && Arrows && FourMasks;}}),
		LocationAccess(THE_MOON_GARO_CHEST, {[] {return MoonAccess && Hookshot;}}),
		LocationAccess(THE_MOON_IRON_KNUCKLE_CHEST, {[] {return MoonAccess && Hookshot;}}),
		LocationAccess(THE_MOON_MAJORA_CHILD, {[] {return MoonAccess && AllMasks;}}),
		*/
		LocationAccess(MAJORA,{[] {return WoodfallClear && SnowheadClear && GreatBayClear && StoneTowerClear;}}),
	},
	{
		//Exits
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
	});


	areaTable[SSH] = Area("Swamp Spider House", "Swamp Spider House", SSH, {}, {
		//Locations
		/*
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
		LocationAccess(SSH_MONUMENT_ROOM_LOWER_WALL, {[] {return PoisonSwampAccess && (Hookshot || ZoraMask || (GoronMask && MagicBean && WitchBottle) || (Explosives && MagicBean && WitchBottle));}}),
		LocationAccess(SSH_GOLD_ROOM_NEAR_CEILING, {[] {return PoisonSwampAccess && (Hookshot || ZoraMask || (DekuMask && WitchBottle));}}),
		LocationAccess(SSH_GOLD_ROOM_PILLAR, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_GOLD_ROOM_BEEHIVE, {[] {return PoisonSwampAccess && (Arrows || Hookshot || ZoraMask || (DekuMask && MagicMeter));}}),
		LocationAccess(SSH_GOLD_ROOM_WALL, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_POT_ROOM_JAR, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_POT_ROOM_POT_1, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_POT_ROOM_POT_2, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_POT_ROOM_BEHIND_VINES, {[] {return PoisonSwampAccess && KokiriSword;}}),
		LocationAccess(SSH_POT_ROOM_WALL, {[] {return PoisonSwampAccess;}}),
		LocationAccess(SSH_POT_ROOM_BEEHIVE_1, {[] {return PoisonSwampAccess && (Arrows || Hookshot || ZoraMask || (DekuMask && MagicMeter));}}),
		LocationAccess(SSH_POT_ROOM_BEEHIVE_2, {[] {return PoisonSwampAccess && (Arrows || Hookshot || ZoraMask || (DekuMask && MagicMeter));}}),
		LocationAccess(SSH_TREE_ROOM_TREE_1, {[] {return PoisonSwampAccess && SwampSpiderhouseTreeRoom;}}),
		LocationAccess(SSH_TREE_ROOM_TREE_2, {[] {return PoisonSwampAccess && SwampSpiderhouseTreeRoom;}}),
		LocationAccess(SSH_TREE_ROOM_TREE_3, {[] {return PoisonSwampAccess && SwampSpiderhouseTreeRoom;}}),
		LocationAccess(SSH_TREE_ROOM_GRASS_1, {[] {return PoisonSwampAccess && SwampSpiderhouseTreeRoom;}}),
		LocationAccess(SSH_TREE_ROOM_GRASS_2, {[] {return PoisonSwampAccess && SwampSpiderhouseTreeRoom;}}),
		LocationAccess(SSH_TREE_ROOM_BEEHIVE, {[] {return PoisonSwampAccess && SwampSpiderhouseTreeRoom && (Arrows || Hookshot || ZoraMask || (DekuMask && MagicMeter));}}),
		*/
		},
		{
			//Exits
			Entrance(SOUTHERN_SWAMP, {[]{return true;}}),
		});


	areaTable[OSH] = Area("Ocean Spider House", "Ocean Spider House", OSH, {}, {
		//Locations
		/*
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
		*/
		},
		{
			//Exits
			Entrance(GREAT_BAY_COAST, {[]{return GoronMask;}}),
		});

}

namespace Areas {
	static std::array < const AreaKey, 230> allAreas = {
		ROOT,
		ROOT_EXITS,
		N_CLOCK_TOWN,
		CLOCK_TOWN_FAIRY_FOUNTAIN,
		CLOCK_TOWN_DEKU_PLAYGROUND,
		E_CLOCK_TOWN,
		STOCKPOTINN,
		STOCKPOTINN_GUEST_ROOM,
		STOCKPOTINN_STAFF_ROOM,
		STOCKPOTINN_GRANDMA_ROOM,
		CLOCK_TOWN_OBSERVATORY,
		CLOCK_TOWN_BAR,
		CLOCK_TOWN_HONEY_DARLING,
		CLOCK_TOWN_TREASURE_CHEST_GAME,
		CLOCK_TOWN_ARCHERY,
		CLOCK_TOWN_MAYOR_HOUSE,
		W_CLOCK_TOWN,
		CLOCK_TOWN_SWORDSMANS_SCHOOL,
		CLOCK_TOWN_POSTMAN_HOUSE,
		CLOCK_TOWN_LOTTERY,
		CLOCK_TOWN_BOMB_SHOP,
		CLOCK_TOWN_TRADING_POST,
		CLOCK_TOWN_CURIOSITY_SHOP,
		S_CLOCK_TOWN,
		CLOCK_TOWER,
		CLOCK_TOWER_ROOF,
		LAUNDRY_POOL,
		LAUNDRY_POOL_KAFEI_HIDEOUT,
		TERMINA_FIELD,
		TERMINA_FIELD_PEAHAT_GROTTO,
		TERMINA_FIELD_DODONGO_GROTTO,
		TERMINA_FIELD_BIO_BABA_GROTTO,
		TERMINA_FIELD_PILLAR_GROTTO,
		TERMINA_FIELD_GRASS_GROTTO,
		TERMINA_FIELD_BUSINESS_SCRUB_GROTTO,
		TERMINA_FIELD_COW_GROTTO,
		TERMINA_FIELD_GOSSIP_STONES_GROTTO,
		ROAD_TO_SOUTHERN_SWAMP,
		ROAD_TO_SOUTHERN_SWAMP_ARCHERY,
		ROAD_TO_SWAMP_GROTTO,
		SOUTHERN_SWAMP,
		SWAMP_TOURIST_CENTER,
		SOUTHERN_SWAMP_HAGS_POTION_SHOP,
		MYSTERY_WOODS,
		SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO,
		SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO,
		SOUTHERN_SWAMP_TOP,
		DEKU_PALACE,
		DEKU_PALACE_INTERIOR,
		DEKU_PALACE_BEAN_GROTTO,
		DEKU_SHRINE,
		WOODFALL,
		WOODFALL_FAIRY_FOUNTAIN,
		PATH_TO_MOUNTAIN_VILLAGE,
		MOUNTAIN_VILLAGE,
		GORON_GRAVEYARD,
		MOUNTAIN_SMITHY,
		MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO,
		TWIN_ISLANDS,
		GORON_RACETRACK,
		TWIN_ISLANDS_GORON_RACETRACK_GROTTO,
		TWIN_ISLANDS_SPRING_WATER_GROTTO,
		GORON_VILLAGE,
		GORON_VILLAGE_LENS_CAVE,
		GORON_VILLAGE_INTERIOR,
		GORON_VILLAGE_SHOP,
		ROAD_TO_SNOWHEAD,
		ROAD_TO_SNOWHEAD_GROTTO,
		SNOWHEAD,
		SNOWHEAD_FAIRY_FOUNTAIN,
		MILK_ROAD,
		GORMAN_TRACK,
		ROMANI_RANCH,
		DOGGY_RACETRACK,
		CUCCO_SHACK,
		ROMANI_RANCH_HOUSE,
		GREAT_BAY_COAST,
		GREAT_BAY_COAST_MARINE_LAB,
		GREAT_BAY_COAST_GROTTO,
		FISHERMAN_HUT,
		PINNACLE_ROCK,
		ZORA_CAPE,
		WATERFALL_RAPIDS,
		GREAT_BAY_FAIRY_FOUNTAIN,
		ZORA_CAPE_GROTTO,
		ZORA_HALL,
		ZORA_HALL_EVANS_ROOM,
		ZORA_HALL_LULUS_ROOM,
		ZORA_HALL_JAPAS_ROOM,
		ZORA_HALL_TIJOS_ROOM,
		ZORA_HALL_SHOP,
		ZORA_HALL_BACK_ENTRANCE,
		ROAD_TO_IKANA,
		ROAD_TO_IKANA_GROTTO,
		IKANA_GRAVEYARD,
		IKANA_GRAVEYARD_GROTTO,
		IKANA_GRAVEYARD_BELOW_GRAVE1,
		IKANA_GRAVEYARD_BATS_ROOM,
		IKANA_GRAVEYARD_TABLET_ROOM,
		IKANA_GRAVEYARD_BELOW_GRAVE2,
		IKANA_GRAVEYARD_IRON_KNUCKLE_ROOM,
		IKANA_GRAVEYARD_BELOW_GRAVE3,
		DAMPES_HUT,
		IKANA_CANYON,
		IKANA_CANYON_UPPER,
		IKANA_CANYON_CAVE,
		SAKONS_HIDEOUT,
		MUSIC_BOX_HOUSE,
		IKANA_CANYON_POE_HUT,
		IKANA_CANYON_GREAT_FAIRY_FOUNTAIN,
		IKANA_CANYON_SECRET_SHRINE_GROTTO,
		STONE_TOWER,
		INVERTED_STONE_TOWER,
		WOODFALL_TEMPLE_ENTRANCE,
		WOODFALL_TEMPLE_MAIN_ROOM,
		WOODFALL_TEMPLE_UPPER_MAIN_ROOM,
		WOODFALL_TEMPLE_PLATFORM_ROOM,
		WOODFALL_TEMPLE_MAP_ROOM,
		WOODFALL_TEMPLE_UPPER_PLATFORM_ROOM,
		WOODFALL_TEMPLE_BOSS_KEY_ROOM,
		WOODFALL_TEMPLE_BOW_ROOM,
		WOODFALL_TEMPLE_BRIDGE_ROOM,
		WOODFALL_TEMPLE_COMPASS_ROOM,
		WOODFALL_TEMPLE_DARK_ROOM,
		WOODFALL_TEMPLE_DRAGONFLY_ROOM,
		WOODFALL_TEMPLE_PRE_BOSS_ROOM,
		WOODFALL_TEMPLE_BOSS_ROOM,
		WOODFALL_TEMPLE_PRINCESS_ROOM,
		SNOWHEAD_TEMPLE_ENTRANCE,
		SNOWHEAD_TEMPLE_BRIDGE_ROOM,
		SNOWHEAD_TEMPLE_LOWER_MAP_ROOM,
		SNOWHEAD_TEMPLE_UPPER_MAP_ROOM,
		SNOWHEAD_TEMPLE_MAIN_ROOM_1F,
		SNOWHEAD_TEMPLE_BASEMENT,
		SNOWHEAD_TEMPLE_LOWER_PILLAR_FREEZARDS_ROOM,
		SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_LOWER,
		SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_UPPER,
		SNOWHEAD_TEMPLE_COMPASS_ROOM,
		SNOWHEAD_TEMPLE_ICICLE_ROOM,
		SNOWHEAD_TEMPLE_GORON_SWITCH_PUZZLE_ROOM,
		SNOWHEAD_TEMPLE_MAIN_ROOM_2F,
		SNOWHEAD_TEMPLE_MINIBOSS_ROOM,
		SNOWHEAD_TEMPLE_PILLAR_FREEZARDS_ROOM,
		SNOWHEAD_TEMPLE_PILLAR_SWITCH_ROOM,
		SNOWHEAD_TEMPLE_MAIN_ROOM_3F,
		SNOWHEAD_TEMPLE_SNOW_ROOM,
		SNOWHEAD_TEMPLE_MAIN_ROOM_4F,
		SNOWHEAD_TEMPLE_DINOLFOS_ROOM,
		SNOWHEAD_TEMPLE_WIZZROBE_ROOM,
		SNOWHEAD_TEMPLE_BOSS_KEY_ROOM,
		SNOWHEAD_TEMPLE_BOSS_ROOM,
		GREAT_BAY_TEMPLE_ENTRANCE,
		GREAT_BAY_TEMPLE_WATER_CONTROL_ROOM,
		GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM,
		GREAT_BAY_TEMPLE_RED_SWITCH_ROOM,
		GREAT_BAY_TEMPLE_MAP_ROOM,
		GREAT_BAY_TEMPLE_RED_SWITCH2_ROOM,
		GREAT_BAY_TEMPLE_BIO_BABA_ROOM,
		GREAT_BAY_TEMPLE_COMPASS_ROOM,
		GREAT_BAY_TEMPLE_FROG_MINIBOSS_ROOM,
		GREAT_BAY_TEMPLE_BOSS_KEY_ROOM,
		GREAT_BAY_TEMPLE_PRE_MINIBOSS_ROOM,
		GREAT_BAY_TEMPLE_MINI_BOSS_ROOM,
		GREAT_BAY_TEMPLE_GREEN_SWITCH_ROOM,
		GREAT_BAY_TEMPLE_WATER_WHEEL_ROOM,
		GREAT_BAY_TEMPLE_SEESAW_ROOM,
		GREAT_BAY_TEMPLE_PRE_BOSS_ROOM,
		GREAT_BAY_TEMPLE_BOSS_ROOM,
		STONE_TOWER_TEMPLE_ENTRANCE,
		STONE_TOWER_TEMPLE_UPRIGHT_DEATH_ARMOS_ROOM,
		STONE_TOWER_TEMPLE_ARMOS_ROOM,
		STONE_TOWER_TEMPLE_WATER_BRIDGE_ROOM,
		STONE_TOWER_TEMPLE_UPRIGHT_UPDRAFT_ROOM,
		STONE_TOWER_TEMPLE_SUN_BLOCK_PUZZLE_ROOM,
		STONE_TOWER_TEMPLE_LAVA_ROOM,
		STONE_TOWER_TEMPLE_GARO_ROOM,
		STONE_TOWER_TEMPLE_THIN_BRIDGE_ROOM,
		STONE_TOWER_TEMPLE_EYEGORE_ROOM,
		STONE_TOWER_TEMPLE_INVERTED_ENTRANCE,
		STONE_TOWER_TEMPLE_UPDRAFT_ROOM,
		STONE_TOWER_TEMPLE_FLIPPING_LAVA_ROOM,
		STONE_TOWER_TEMPLE_FLIPPING_BLOCK_PUZZLE,
		STONE_TOWER_TEMPLE_WIZZROBE_ROOM,
		STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM,
		STONE_TOWER_TEMPLE_INVERTED_BRIDGE_ROOM,
		STONE_TOWER_TEMPLE_INVERTED_ENTRANCE_DEATH_ARMOS_LEDGE,
		STONE_TOWER_TEMPLE_PRE_GOMESS_ROOM,
		STONE_TOWER_TEMPLE_GOMESS_ROOM,
		STONE_TOWER_TEMPLE_INVERTED_THIN_BRIDGE_ROOM,
		STONE_TOWER_TEMPLE_PRE_BOSS_ROOM,
		STONE_TOWER_TEMPLE_BOSS_ROOM,
		PIRATE_FORTRESS_EXTERIOR,
		PIRATE_FORTRESS_MAZE_ROOM,
		PIRATE_FORTRESS_CAGE_ROOM,
		PIRATE_FORTRESS_EXTERIOR_TOP,
		PIRATE_FORTRESS_INTERIOR,
		PIRATE_FORTRESS_HOOKSHOT_ROOM,
		PIRATE_FORTRESS_HOOKSHOT_ROOM_TOP,
		PIRATE_FORTRESS_BARREL_MAZE,
		PIRATE_FORTRESS_LAVA_ROOM,
		PIRATE_FORTRESS_GUARD_ROOM,
		BENEATH_THE_WELL_ENTRANCE,
		BENEATH_THE_WELL_LEFT_PATH_ROOM,
		BENEATH_THE_WELL_LEFT_PATH_HOT_WATER_ROOM,
		BENEATH_THE_WELL_LEFT_PATH_RIGHT_DOOR_ROOM,
		BENEATH_THE_WELL_LEFT_PATH_FAIRY_FOUNTAIN,
		BENEATH_THE_WELL_LEFT_PATH_CHEST_ROOM,
		BENEATH_THE_WELL_RIGHT_PATH_ROOM,
		BENEATH_THE_WELL_PRE_COW_AND_BIG_POE_ROOM,
		BENEATH_THE_WELL_COW_ROOM,
		BENEATH_THE_WELL_BIG_POE_ROOM,
		BENEATH_THE_WELL_RIGHT_PATH_LEFT_DOOR_ROOM,
		BENEATH_THE_WELL_RIGHT_PATH_CHEST_ROOM,
		BENEATH_THE_WELL_PRE_MIRROR_SHIELD_ROOM,
		BENEATH_THE_WELL_MIRROR_SHIELD_ROOM,
		IKANA_CASTLE_EXTERIOR_LOWER,
		IKANA_CASTLE_ENTRANCE,
		IKANA_CASTLE_LAVA_BLOCKS_ROOM,
		IKANA_CASTLE_NO_FLOOR_ROOM,
		IKANA_CASTLE_LEFT_STAIRWELL,
		IKANA_CASTLE_EXTERIOR_UPPER_LEFT,
		IKANA_CASTLE_RIGHT_ROOM,
		IKANA_CASTLE_WIZZROBE_ROOM,
		IKANA_CASTLE_RIGHT_STAIRWELL,
		IKANA_CASTLE_EXTERIOR_UPPER_RIGHT,
		IKANA_CASTLE_THRONE_ROOM,
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
			printf("\x1b[1;1HERROR: AREAKEY TOO BIG\n");
			//printf("\x1b[1;1HAREAKEY SIZE: %ld", areaKey);
			//needs error handling eventually
			return 0;
		}
		return &(areaTable[areaKey]);
	}
