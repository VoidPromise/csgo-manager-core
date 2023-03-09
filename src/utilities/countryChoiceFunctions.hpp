#pragma once

#include "countriesRegionsEnums.hpp"
#include <vector>

namespace vp::utility
{
    std::vector<int> playersGetCountriesByRankingRange(
        std::vector<int> sortedPlayerCountriesVector, int beginIndex,
        int endIndex, std::vector<availableCountries> countriesToDraw,
        int tierPlayer);

    std::vector<int> playersCountriesSortBySkillLevel(const int numPlayers);
}