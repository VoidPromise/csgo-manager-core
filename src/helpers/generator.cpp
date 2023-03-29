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
#include "player.hpp"
#include "role.hpp"
#include "skill.hpp"

#include <chrono>
#include <execution>

namespace vp::helper
{
    namespace
    {
        void insert_player_components(
            entt::registry& registry,
            const std::vector<entt::entity>& c_players)
        {
            registry.insert<component::player>(c_players.cbegin(),
                                               c_players.cend());
            registry.insert<component::name>(c_players.cbegin(),
                                             c_players.cend());
            registry.insert<component::nickname>(c_players.cbegin(),
                                                 c_players.cend());
            registry.insert<component::country>(c_players.cbegin(),
                                                c_players.cend());
            registry.insert<component::age>(c_players.cbegin(),
                                            c_players.cend());
            registry.insert<component::role>(c_players.cbegin(),
                                             c_players.cend());
            registry.insert<component::skill>(c_players.cbegin(),
                                              c_players.cend());
        }

        void insert_coach_components(entt::registry& registry,
                                     const std::vector<entt::entity>& c_coaches)
        {
            registry.insert<component::coach>(c_coaches.cbegin(),
                                              c_coaches.cend());
            registry.insert<component::name>(c_coaches.cbegin(),
                                             c_coaches.cend());
            registry.insert<component::nickname>(c_coaches.cbegin(),
                                                 c_coaches.cend());
            registry.insert<component::country>(c_coaches.cbegin(),
                                                c_coaches.cend());
            registry.insert<component::age>(c_coaches.cbegin(),
                                            c_coaches.cend());
            registry.insert<component::skill>(c_coaches.cbegin(),
                                              c_coaches.cend());
        }

        void assign_roles(component::role& role)
        {           

            role._primary_role_ct = 
                *effolkronium::random_thread_local::get(magic_enum::enum_values<utility::roles_ct>().cbegin(), magic_enum::enum_values<utility::roles_ct>().cend());

            // Assign primary role for role_tr 
            // Create container with all roles - the primary
            // Get random with this container for secondary role.

            utility::roles random_role{};
            do
            {
                random_role = magic_enum::enum_value<utility::roles>(
                    effolkronium::random_thread_local::get<int>(0, 4));
            } while (role._primary_role_ct == random_role);
            role._secondary_role_ct = random_role;
            do
            {
                random_role = magic_enum::enum_value<utility::roles>(
                    effolkronium::random_thread_local::get<int>(5, 9));
            } while (role._primary_role_tr == random_role);
            role._secondary_role_tr = random_role;
        }

        void insert_person_country_skill_level_attributes(
            entt::registry& registry, const std::vector<entt::entity>& c_people,
            const std::vector<utility::country_skill_level>&
                c_countries_and_skill_level)
        {
            std::transform(
                c_countries_and_skill_level.cbegin(),
                c_countries_and_skill_level.cend(), c_people.cbegin(),
                [&registry](utility::country_skill_level& country_skill,
                            entt::entity& person) {
                    registry.patch<component::country>(
                        person, [&country_skill](component::country& country) {
                            country._country = country_skill._country;
                            country._culture = utility::country_to_culture(
                                country_skill._country);
                        });
                    registry.patch<component::skill>(
                        person, [&country_skill](component::skill& skill) {
                            skill._skill_level = country_skill._skill_level;
                        });
                });

            // for virou for_each que virou transform, confirma se tá certo, por
            // favor
            //
            // std::for_each(
            //    c_players.cbegin(), c_players.cend(),
            //    [&registry,
            //     &c_countries_and_skill_level](entt::entity& c_player) {
            //        int i = 0;
            //        registry.patch<component::country>(
            //            c_player, [&c_countries_and_skill_level,
            //                       i](component::country& country) {
            //                country._country =
            //                    c_countries_and_skill_level.at(i)._country;
            //                country._culture = utility::country_to_culture(
            //                    c_countries_and_skill_level.at(i)._country);
            //            });
            //        registry.patch<component::skill>(
            //            c_player, [&c_countries_and_skill_level,
            //                       i](component::skill& skill) {
            //                skill._skill_level =
            //                    c_countries_and_skill_level.at(i)._skill_level;
            //            });
            //    });
            //
            // for (int i = 0; i < c_players.size(); i++)
            //{
            //    registry.patch<component::country>(
            //        c_players.at(i), [c_countries_and_skill_level,
            //                          i](component::country& country) {
            //            country._country =
            //                c_countries_and_skill_level.at(i)._country;
            //            country._culture = utility::country_to_culture(
            //                c_countries_and_skill_level.at(i)._country);
            //        });
            //    registry.patch<component::skill>(
            //        c_players.at(i),
            //        [c_countries_and_skill_level, i](component::skill& skill)
            //        {
            //            skill._skill_level =
            //                c_countries_and_skill_level.at(i)._skill_level;
            //        });
            //}
        }

        void insert_person_name_nickname_attributes(
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

        void insert_player_role_attributes(
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

    void generate_metadata(entt::registry& registry)
    {
        registry.ctx().emplace<component::metadata>(
            std::array<std::uint8_t, 3>({0, 0, 0}),
            date::floor<date::days>(std::chrono::system_clock::now()),
            date::floor<date::days>(std::chrono::system_clock::now()),
            std::uint64_t{0});

        registry.ctx().emplace<component::generation_parameters>(
            std::size_t{600}, std::size_t{120});

        registry.ctx().emplace<component::game_data>(
            "CS:GO", "Counter Strike: Global Offensive",
            "Counter-Strike: Global Offensive (CS:GO) is a 2012 "
            "multiplayer "
            "tactical first-person shooter developed by Valve and Hidden "
            "Path "
            "Entertainment.",
            utility::cs_version::global_offensive, date::March / 01 / 2013);
    }

    void generate_players(entt::registry& registry)
    {
        const std::size_t c_players_count{
            registry.ctx()
                .get<component::generation_parameters>()
                ._players_count};
        const std::vector<entt::entity> c_players{c_players_count,
                                                  registry.create()};
        const std::vector<utility::country_skill_level>
            c_countries_and_skill_level{
                utility::vector_countries_and_tiers_for_players(
                    c_players_count)};

        insert_player_components(registry, c_players);
        insert_person_country_skill_level_attributes(
            registry, c_players, c_countries_and_skill_level);
        insert_person_name_nickname_attributes(registry, c_players);
        insert_player_role_attributes(registry, c_players);
    }

    void generate_coaches(entt::registry& registry)
    {
        const std::size_t c_coaches_count{
            registry.ctx()
                .get<component::generation_parameters>()
                ._coaches_count};
        const std::vector<entt::entity> c_coaches{c_coaches_count,
                                                  registry.create()};
        const std::vector<utility::country_skill_level>
            c_countries_and_skill_level{
                utility::vector_countries_and_tiers_for_coaches(
                    c_coaches_count)};

        insert_coach_components(registry, c_coaches);
        insert_person_country_skill_level_attributes(
            registry, c_coaches, c_countries_and_skill_level);
        insert_person_name_nickname_attributes(registry, c_coaches);
    }

} // namespace vp::helper