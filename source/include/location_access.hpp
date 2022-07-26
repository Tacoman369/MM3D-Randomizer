#pragma once

#include <string>
#include <vector>
#include <list>

#include "logic.hpp"
#include "hint_list.hpp"
#include "keys.hpp"

typedef bool (*ConditionFn)();

class EventAccess {
public:

    explicit EventAccess(bool* event_, std::vector<ConditionFn> conditions_met_)
        : event(event_) {
        conditions_met.resize(2);
        for (size_t i = 0; i < conditions_met_.size(); i++) {
            conditions_met[i] = conditions_met_[i];
        }
    }

    bool ConditionsMet() const {
        if (Settings::Logic.Is(rnd::LogicSetting::LOGIC_NONE) || Settings::Logic.Is(rnd::LogicSetting::LOGIC_VANILLA)) {
            return true;
        } else if (Settings::Logic.Is(rnd::LogicSetting::LOGIC_GLITCHLESS)) {
            return conditions_met[0]();
        } else if (Settings::Logic.Is(rnd::LogicSetting::LOGIC_GLITCHED)) {
            if (conditions_met[0]()) {
                return true;
            } else if (conditions_met[1] != NULL) {
                return conditions_met[1]();
            }
        }
        return false;
    }

    bool CheckConditionAtDay(bool& day, bool& time) {
        
        Logic::IsDay1Day = false;
        Logic::IsDay1Night = false;
        Logic::IsDay2Day = false;
        Logic::IsDay2Night = false;
        Logic::IsDay3Day = false;
        Logic::IsDay3Night = false;
        Logic::AtDay = false;
        Logic::AtNight = false;

        day = true;
        time = true;

        Logic::UpdateHelpers();
        return ConditionsMet();
    }

    void EventOccurred() {
        *event = true;
    }

    bool GetEvent() const {
        return *event;
    }

private:
    bool* event;
    std::vector<ConditionFn> conditions_met;
};

//this class is meant to hold an item location with a boolean function to determine its accessibility from a specific area
class LocationAccess {
public:

    explicit LocationAccess(LocationKey location_, std::vector<ConditionFn> conditions_met_)
        : location(location_) {
        conditions_met.resize(2);
        for (size_t i = 0; i < conditions_met_.size(); i++) {
            conditions_met[i] = conditions_met_[i];
        }
    }

    bool GetConditionsMet() const {
        if (Settings::Logic.Is(rnd::LogicSetting::LOGIC_NONE) || Settings::Logic.Is(rnd::LogicSetting::LOGIC_VANILLA)) {
            return true;
        } else if (Settings::Logic.Is(rnd::LogicSetting::LOGIC_GLITCHLESS)) {
            return conditions_met[0]();
        } else if (Settings::Logic.Is(LogicSetting::LOGIC_GLITCHED)) {
            if (conditions_met[0]()) {
                return true;
            } else if (conditions_met[1] != NULL) {
                return conditions_met[1]();
            }
        }
        return false;
    }

    bool ConditionsMet() const;

    bool CheckConditionAtDay(bool& day, bool& time) const;

    LocationKey GetLocation() const {
        return location;
    }

private:
    LocationKey location;
    std::vector<ConditionFn> conditions_met;

    //Makes sure shop locations are buyable
    bool CanBuy() const;
};

class Entrance;
enum class EntranceType;

class Area {
public:
    Area();
    Area(std::string regionName_, std::string scene_, HintKey hintKey_,
         std::vector<EventAccess> events_,
         std::vector<LocationAccess> locations_,
         std::list<Entrance> exits_);
    ~Area();

    std::string regionName;
    std::string scene;
    HintKey     hintKey;
    std::vector<EventAccess> events;
    std::vector<LocationAccess> locations;
    std::list<Entrance> exits;
    //^ The above exits are now stored in a list instead of a vector because
    //the entrance randomization algorithm plays around with pointers to these
    //entrances a lot. By putting the entrances in a list, we don't have to
    //worry about a vector potentially reallocating itself and invalidating all our
    //entrance pointers.
    bool timePass = true;
    bool day1Day = false;
    bool day1Night = false;
    bool day2Day = false;
    bool day2Night = false;
    bool day3Day = false;
    bool day3Night = false;
   
    bool addedToPool = false;

    bool UpdateEvents();

    void AddExit(AreaKey parentKey, AreaKey newExitKey, ConditionFn condition);

    void RemoveExit(Entrance* exitToRemove);

    void DisconnectExit(AreaKey exitToDisconnect);

    void SetAsPrimary(AreaKey exitToBePrimary);

    Entrance* GetExit(AreaKey exit);


    bool HasAccess() const {
      return Day1() || Day2() || Day3();
    }

    bool AllAccess() const {
      return day1Day && day1Night && day2Day && day2Night && day3Day && day3Night;
    }

    bool Day1() const {
        return day1Day || day1Night;
    }

    bool Day2() const {
        return Day1() && (day2Day || day2Night);
    }

    bool Day3() const {
        return Day2() && (day3Day || day3Night);
    }

    bool AllDaysCheck() const {
        return Day1() && Day2() && Day3();
    }

    //Check to see if an exit can be access as both ages at both times of day
    bool CheckAllAccess(AreaKey exitKey);

    const HintText& GetHint() const {
      return Hint(hintKey);
    }
    
    bool HereCheck(ConditionFn condition) {

        //store past day variables
        bool pastDay1Day = Logic::IsDay1Day;
        bool pastDay2Day = Logic::IsDay2Day;
        bool pastDay3Day = Logic::IsDay3Day;
        bool pastDay1Night = Logic::IsDay1Night;
        bool pastDay2Night = Logic::IsDay2Night;
        bool pastDay3Night = Logic::IsDay3Night;

        //Set Day Access as this areas Days
        Logic::IsDay1Day = Day1();
        Logic::IsDay1Night = Day1();
        Logic::IsDay2Day = Day2();
        Logic::IsDay2Night = Day2();
        Logic::IsDay3Day = Day3();
        Logic::IsDay3Night = Day3();
        
        //update helpers and check condition
        Logic::UpdateHelpers();
        bool hereVal = condition();

        //set back age variables
        Logic::IsDay1Day = pastDay1Day;
        Logic::IsDay2Day = pastDay2Day;
        Logic::IsDay3Day = pastDay3Day;
        Logic::IsDay1Night = pastDay1Night;
        Logic::IsDay2Night = pastDay2Night;
        Logic::IsDay3Night = pastDay3Night;
        Logic::UpdateHelpers();

        return hereVal;
    }

    bool CanPlantBeanCheck() const;
    bool AllAccountedFor() const;

    void ResetVariables();

};

namespace Areas {

  extern void AccessReset();
  extern void ResetAllLocations();
  extern bool HasTimePassAccess(u8 age);
  extern bool HasDayAccess(u8 day);
} //namespace Exits

void  AreaTable_Init();
Area* AreaTable(const AreaKey areaKey);
std::vector<Entrance*> GetShuffleableEntrances(EntranceType type, bool onlyPrimary = true);
