#pragma once

#include "countryenum.hpp"

#include <vector>

namespace vp::utility
{
    struct country_skill_level
    {
        country_code _country;
        std::uint8_t _skill_level;
    };

    std::uint8_t tier_get_skill_level(const char& tier);

    void choose_random_countries_for_tier(
        std::vector<country_skill_level>& sorted_countries_tiers_vector,
        int& begin_index, const int& c_end_index,
        const std::vector<country_code>& c_countries_to_draw,
        const char& c_tier_player);

    std::vector<country_skill_level> vector_countries_and_tiers_for_players(
        const int c_players_count);

} // namespace vp::utility