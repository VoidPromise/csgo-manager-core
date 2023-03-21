#pragma once

#include "countryenum.hpp"

#include <vector>
#include <map>

namespace vp::utility
{
    struct country_skill_level
    {
        country_code _country;
        std::uint8_t _skill_level;
    };

    struct country_and_skill_level_limit_settings
    {
        double _distribuition_tier;
        std::uint8_t _begin_range;
        std::uint8_t _end_range;
        std::vector<country_code> _countries_to_draw;
        std::map<country_code, double> _people_distribuiton;
    };

    std::vector<country_and_skill_level_limit_settings>
    set_settings_to_generate_players();

    std::vector<country_and_skill_level_limit_settings>
    set_settings_to_generate_coaches();

    void choose_random_countries_for_tier(
        std::vector<country_skill_level>& sorted_countries_tiers_vector,
        country_and_skill_level_limit_settings& configs);

    std::vector<country_skill_level> vector_countries_and_tiers_for_players(
        const std::size_t c_players_count);

    std::vector<country_skill_level> vector_countries_and_tiers_for_coaches(
        const std::size_t c_coaches_count);

} // namespace vp::utility