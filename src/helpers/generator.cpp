#include "generator.hpp"

#include "age.hpp"
#include "coach.hpp"
#include "country.hpp"
#include "countrytoculture.hpp"
#include "gamedata.hpp"
#include "generationparameters.hpp"
#include "metadata.hpp"
#include "name.hpp"
#include "namegen.hpp"
#include "nickname.hpp"
#include "nicknamegen.hpp"
#include "physicaltrainer.hpp"
#include "player.hpp"
#include "psychologist.hpp"
#include "rolesenum.hpp"
#include "skill.hpp"

#include <chrono>
#include <execution>

namespace vp::helper
{
    namespace
    {
        void insert_people_components(entt::registry& registry,
                                      const std::vector<entt::entity>& c_people)
        {
            registry.insert<component::name>(c_people.cbegin(),
                                             c_people.cend());
            registry.insert<component::nickname>(c_people.cbegin(),
                                                 c_people.cend());
            registry.insert<component::country>(c_people.cbegin(),
                                                c_people.cend());
            registry.insert<component::age>(c_people.cbegin(), c_people.cend());
        }

        void insert_psychologists_components(
            entt::registry& registry,
            const std::vector<entt::entity>& c_psychologists)
        {
            registry.insert<component::psychologist>(c_psychologists.cbegin(),
                                                     c_psychologists.cend());
        }

        void insert_physical_trainers_components(
            entt::registry& registry,
            const std::vector<entt::entity>& c_physical_trainers)
        {
            registry.insert<component::physical_trainer>(
                c_physical_trainers.cbegin(), c_physical_trainers.cend());
        }

        void insert_players_components(
            entt::registry& registry,
            const std::vector<entt::entity>& c_players)
        {
            registry.insert<component::player>(c_players.cbegin(),
                                               c_players.cend());
            registry.insert<component::role>(c_players.cbegin(),
                                             c_players.cend());
            registry.insert<component::skill>(c_players.cbegin(),
                                              c_players.cend());
        }

        void insert_coaches_components(
            entt::registry& registry,
            const std::vector<entt::entity>& c_coaches)
        {
            registry.insert<component::coach>(c_coaches.cbegin(),
                                              c_coaches.cend());
            registry.insert<component::skill>(c_coaches.cbegin(),
                                              c_coaches.cend());
        }

        void assign_roles(component::role& role)
        {
            std::vector<utility::roles_ct> roles_ct_to_choose{
                magic_enum::enum_values<utility::roles_ct>().begin(),
                magic_enum::enum_values<utility::roles_ct>().end()};

            std::vector<utility::roles_tr> roles_tr_to_choose{
                magic_enum::enum_values<utility::roles_tr>().begin(),
                magic_enum::enum_values<utility::roles_tr>().end()};

            role._primary_role_ct =
                *effolkronium::random_thread_local::get(roles_ct_to_choose);
            std::erase(roles_ct_to_choose, role._primary_role_ct);
            role._secondary_role_ct =
                *effolkronium::random_thread_local::get(roles_ct_to_choose);
            role._primary_role_tr =
                *effolkronium::random_thread_local::get(roles_tr_to_choose);
            std::erase(roles_tr_to_choose, role._primary_role_tr);
            role._secondary_role_tr =
                *effolkronium::random_thread_local::get(roles_tr_to_choose);
        }

        void insert_people_country_skill_level_attributes(
            entt::registry& registry, const std::vector<entt::entity>& c_people)
        {
            const std::size_t c_people_count{c_people.size()};

            std::for_each(
                c_people.cbegin(), c_people.cend(),
                [&registry, &c_people_count](const entt::entity& c_person) {
                    utility::country_skill_level country_skill =
                        utility::get_country_skill_level(registry, c_person,
                                                         c_people_count);

                    registry.patch<component::country>(
                        c_person,
                        [&country_skill](component::country& country) {
                            country._country = country_skill._country;
                            country._culture =
                                utility::country_to_culture(country._country);
                        });

                    registry.patch<component::skill>(
                        c_person, [&country_skill](component::skill& skill) {
                            skill._skill_level = country_skill._skill_level;
                        });
                });
        }

        void insert_people_name_nickname_attributes(
            entt::registry& registry, const std::vector<entt::entity>& c_people)
        {
            std::for_each(
                c_people.cbegin(), c_people.cend(),
                [&registry](const entt::entity& person) {
                    vp::culture culture =
                        registry.get<component::country>(person)._culture;
                    registry.patch<component::name>(
                        person, [&culture](component::name& name) {
                            vp::helper::patch_name(name, gender::m, culture, 1,
                                                   1);
                        });
                    std::wstring name =
                        registry.get<component::name>(person)._internal_string;
                    registry.patch<component::nickname>(
                        person, [&name](component::nickname& nick) {
                            nick._original_string =
                                helper::nng::instance().get_nickname(name);
                            nick._internal_string = nick._original_string;
                        });
                });
        }

        void insert_players_role_attributes(
            entt::registry& registry,
            const std::vector<entt::entity>& c_players)
        {
            std::for_each(c_players.cbegin(), c_players.cend(),
                          [&registry](const entt::entity& c_player) {
                              registry.patch<component::role>(c_player,
                                                              assign_roles);
                          });
        }

    } // namespace

    void generate_metadata(entt::registry& registry, std::size_t number_people)
    {
        registry.ctx().emplace<component::metadata>(
            std::array<std::uint8_t, 3>({0, 0, 0}),
            date::floor<date::days>(std::chrono::system_clock::now()),
            date::floor<date::days>(std::chrono::system_clock::now()),
            std::uint64_t{0});

        registry.ctx().emplace<component::generation_parameters>(
            number_people);

        registry.ctx().emplace<component::game_data>(
            "CS:GO", "Counter Strike: Global Offensive",
            "Counter-Strike: Global Offensive (CS:GO) is a 2012 "
            "multiplayer "
            "tactical first-person shooter developed by Valve and Hidden "
            "Path "
            "Entertainment.",
            utility::cs_version::global_offensive, date::March / 01 / 2013);
    }

    void generate_people(entt::registry& registry)
    {
        const std::size_t c_people_count{
            registry.ctx()
                .get<component::generation_parameters>()
                ._people_count};

        std::vector<entt::entity> c_people{c_people_count};
        std::generate_n(c_people.begin(), c_people_count,
                        [&registry]() { return registry.create(); });

        insert_people_components(registry, c_people);

        auto coaches_end_it{c_people.cbegin() +
                            static_cast<int>(c_people_count * 0.125)};
        auto psychologists_end_it{coaches_end_it +
                            static_cast<int>(c_people_count * 0.125)};
        auto psycphysical_traines_end_it{psychologists_end_it +
                                  static_cast<int>(c_people_count * 0.125)};

        generate_coaches(registry, {c_people.cbegin(), coaches_end_it});
        generate_psychologists(registry,
                               {coaches_end_it, psychologists_end_it});
        generate_physical_trainers(registry, {psychologists_end_it, psycphysical_traines_end_it});
        generate_players(registry,
                         {psycphysical_traines_end_it, c_people.cend()});
    }

    void generate_players(entt::registry& registry,
                          const std::vector<entt::entity>& c_players)
    {
        insert_players_components(registry, c_players);
        insert_people_country_skill_level_attributes(registry, c_players);
        insert_people_name_nickname_attributes(registry, c_players);
        insert_players_role_attributes(registry, c_players);
    }

    void generate_coaches(entt::registry& registry,
                          const std::vector<entt::entity>& c_coaches)
    {
        insert_coaches_components(registry, c_coaches);
        insert_people_country_skill_level_attributes(registry, c_coaches);
        insert_people_name_nickname_attributes(registry, c_coaches);
    }

    void generate_psychologists(
        entt::registry& registry,
        const std::vector<entt::entity>& c_psychologists)
    {
        insert_psychologists_components(registry, c_psychologists);
    }

    void generate_physical_trainers(
        entt::registry& registry,
        const std::vector<entt::entity>& c_physical_trainers)
    {
        insert_physical_trainers_components(registry, c_physical_trainers);
    }

} // namespace vp::helper