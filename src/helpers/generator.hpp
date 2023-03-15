#pragma once

#include "pch.h"
#include "countrychoicefunctions.hpp"

namespace vp::helper
{
    namespace
    {
        void insert_player_components(
            entt::registry& registry,
            const std::vector<entt::entity>& c_players);

        void insert_player_country_skill_level_attributes(
            entt::registry& registry,
            const std::vector<entt::entity>& c_players,
            const std::vector<utility::country_skill_level>&
                c_countries_and_skill_level);

        void insert_player_name_nickname_attributes(
            entt::registry& registry,
            const std::vector<entt::entity>& c_players);

        void insert_player_role_attributes(
            entt::registry& registry,
            const std::vector<entt::entity>& c_players);
    } // namespace

    void generate_coaches();

    void generate_metadata(entt::registry& registry);

    void generate_players(entt::registry& registry);

} // namespace vp::helper
