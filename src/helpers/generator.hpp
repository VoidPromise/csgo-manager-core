#pragma once

#include "countrychoicefunctions.hpp"
#include "pch.h"
#include "role.hpp"

namespace vp::helper
{
    namespace
    {
        void insert_player_components(
            entt::registry& registry,
            const std::vector<entt::entity>& c_players);

        void insert_coach_components(
            entt::registry& registry,
            const std::vector<entt::entity>& c_coaches);

        void assign_roles(component::role& role);

        void insert_person_country_skill_level_attributes(
            entt::registry& registry, const std::vector<entt::entity>& c_people,
            const std::vector<utility::country_skill_level>&
                c_countries_and_skill_level);

        void insert_person_name_nickname_attributes(
            entt::registry& registry,
            const std::vector<entt::entity>& c_people);

        void insert_player_role_attributes(
            entt::registry& registry,
            const std::vector<entt::entity>& c_players);
    } // namespace

    void generate_metadata(entt::registry& registry);

    void generate_players(entt::registry& registry);

    void generate_coaches(entt::registry& registry);

} // namespace vp::helper
