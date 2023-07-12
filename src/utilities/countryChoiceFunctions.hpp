#pragma once

#include "countryenum.hpp"
#include "generatorconfigs.hpp"
#include "pch.h"

#include <map>
#include <vector>

namespace vp::utility
{
    struct country_skill_level
    {
        country_code _country;
        std::uint8_t _skill_level;
    };

    generation_limit_control fill_generation_limit(
        std::vector<parameters_for_generation>& configs,
        const std::map<country_code, double>& countries_distribuiton,
        const std::size_t& c_people_count);

    country_skill_level choose_random_countries_for_tier(
        std::vector<parameters_for_generation>& configs,
        generation_limit_control& limits);

    country_skill_level get_country_skill_level(
        entt::registry& registry, const entt::entity& c_person,
        const std::size_t c_people_count);
} // namespace vp::utility