#pragma once

#include <3ds.h>

#include "keys.hpp"

#include <vector>

enum class SearchMode {
    ReachabilitySearch,
    GeneratePlaythrough,
    CheckBeatable,
    AllLocationsReachable,
};

void VanillaFill();
int Fill();

std::vector<LocationKey> GetAccessibleLocations(const std::vector<LocationKey>& allowedLocations,
                                                  SearchMode mode = SearchMode::ReachabilitySearch);
