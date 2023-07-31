#pragma once

#include "countrychoicefunctions.hpp"
#include "pch.h"
#include "role.hpp"

namespace vp::helper
{
    namespace
    {
        void insert_people_components(
            entt::registry& registry,
            const std::vector<entt::entity>& c_people);

        void insert_psychologists_components(
            entt::registry& registry,
            const std::vector<entt::entity>& c_psychologists);

        void insert_physical_trainers_components(
            entt::registry& registry,
            const std::vector<entt::entity>& c_physical_trainers);

        void insert_players_components(
            entt::registry& registry,
            const std::vector<entt::entity>& c_players);

        void insert_coaches_components(
            entt::registry& registry,
            const std::vector<entt::entity>& c_coaches);

        void assign_roles(component::role& role);

        void insert_people_country_skill_level_attributes(
            entt::registry& registry,
            const std::vector<entt::entity>& c_people);

        void insert_people_name_nickname_attributes(
            entt::registry& registry,
            const std::vector<entt::entity>& c_people);

        void insert_players_role_attributes(
            entt::registry& registry,
            const std::vector<entt::entity>& c_players);
    } // namespace

    void generate_metadata(entt::registry& registry, std::size_t number_people);

    void generate_people(entt::registry& registry);

    void generate_players(entt::registry& registry,
                          const std::vector<entt::entity>& c_players);

    void generate_coaches(entt::registry& registry,
                          const std::vector<entt::entity>& c_coaches);

    void generate_psychologists(
        entt::registry& registry,
        const std::vector<entt::entity>& c_psychologists);

    void generate_physical_trainers(
        entt::registry& registry,
        const std::vector<entt::entity>& c_physical_trainers);

} // namespace vp::helper
