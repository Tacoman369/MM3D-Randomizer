#pragma once

#include <array>
#include <string>
#include <string_view>
#include "rnd/spoiler_data.h"

using RandomizerHash = std::array<std::string, 5>;

void GenerateHash();
const RandomizerHash& GetRandomizerHash();

bool SpoilerLog_Write();
const rnd::SpoilerData& GetSpoilerData();

void PlacementLog_Msg(std::string_view msg);
void PlacementLog_Clear();
bool PlacementLog_Write();
