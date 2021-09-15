#pragma once

#include <3ds.h>
#include <array>
#include <string>
#include <vector>

#include "keys.hpp"

namespace Dungeon {
class DungeonInfo {
public:
    DungeonInfo(std::string name_, ItemKey map_, ItemKey compass_,
                ItemKey smallKey_, ItemKey bossKey_, u8 vanillaKeyCount_, u8 mqKeyCount_,
                std::vector<LocationKey> vanillaLocations_,
                std::vector<LocationKey> mqLocations_,
                std::vector<LocationKey> sharedLocations_);
    ~DungeonInfo();

    const std::string& GetName() const {
        return name;
    }

    void SetMQ() {
        masterQuest = true;
    }

    void ClearMQ() {
        masterQuest = false;
    }

    bool IsMQ() const {
        return masterQuest;
    }

    bool IsVanilla() const {
        return !masterQuest;
    }

    u8 GetSmallKeyCount() const {
        return (masterQuest) ? mqKeyCount : vanillaKeyCount;
    }

    ItemKey GetSmallKey() const;
    ItemKey GetMap() const;
    ItemKey GetCompass() const;
    ItemKey GetBossKey() const;

    void PlaceVanillaMap();
    void PlaceVanillaCompass();
    void PlaceVanillaBossKey();
    void PlaceVanillaSmallKeys();

    // Gets the chosen dungeon locations for a playthrough (so either MQ or Vanilla)
    std::vector<LocationKey> GetDungeonLocations() const;

    // Gets all dungeon locations (MQ + Vanilla)
    std::vector<LocationKey> GetEveryLocation() const;

private:
    std::string name;
    ItemKey map;
    ItemKey compass;
    ItemKey smallKey;
    ItemKey bossKey;
    u8 vanillaKeyCount;
    std::vector<LocationKey> vanillaLocations;
};

extern DungeonInfo WoodfallTemple;
extern DungeonInfo SnowheadTemple;
extern DungeonInfo GreatBayTemple;
extern DungeonInfo StoneTowerTemple;
extern DungeonInfo SwampSpiderHouse;
extern DungeonInfo OceansideSpiderHouse;
extern DungeonInfo PiratesFortress;
extern DungeonInfo BeneathTheWell;
extern DungeonInfo AncientCastleOfIkana;
extern DungeonInfo SecretShrine;
extern DungeonInfo TheMoon;

using DungeonArray = std::array<DungeonInfo*, 11>;

extern const DungeonArray dungeonList;
} // namespace Dungeon
