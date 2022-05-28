#pragma once

#include <3ds.h>
#include <array>
#include <string>
#include <vector>

#include "keys.hpp"
#include "item.hpp"

namespace Dungeon {
class DungeonInfo {
public:
    DungeonInfo(std::string name_, ItemKey map_, ItemKey compass_,
                ItemKey smallKey_, ItemKey bossKey_, u8 vanillaKeyCount_, 
                std::vector<LocationKey> vanillaLocations_);
    ~DungeonInfo();

    const std::string& GetName() const {
        return name;
    }

    u8 GetSmallKeyCount() const {
        return vanillaKeyCount;
    }

    ItemKey GetSmallKey() const;
    ItemKey GetMap() const;
    ItemKey GetCompass() const;
    ItemKey GetBossKey() const;

    void PlaceVanillaMap();
    void PlaceVanillaCompass();
    void PlaceVanillaBossKey();
    void PlaceVanillaSmallKeys();

    // Gets the chosen dungeon locations for a playthrough
    std::vector<LocationKey> GetDungeonLocations() const;

    // Gets all dungeon locations 
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
