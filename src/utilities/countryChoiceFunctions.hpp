#pragma once
#include <vector>

#include "country_and_region.hpp"

namespace vp::utility
{
    std::vector<country_code> players_get_countries_by_ranking_range(
        std::vector<country_code> sorted_player_countries_vector,
        int begin_index, int end_index,
        std::vector<country_code> countries_to_draw, int tier_player);

    std::vector<country_code> players_countries_sort_by_skill_level(
        const std::size_t players_count);
} // namespace vp::utility