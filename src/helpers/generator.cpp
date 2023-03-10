#include "generator.hpp"
#include "age.hpp"
#include "country.hpp"
#include "countryChoiceFunctions.hpp"
#include "countryGetCulture.hpp"
#include "createRandomSkillLevelByTier.hpp"
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
    void generate_players(entt::registry& registry)
    {
        const std::size_t c_players_count{
            registry.ctx()
                .get<component::generation_parameters>()
                ._players_count};

        const std::vector<entt::entity> c_players{c_players_count,
                                                  registry.create()};

        registry.insert<component::player>(c_players.cbegin(),
                                           c_players.cend());

        registry.insert<component::name>(c_players.cbegin(), c_players.cend());

        registry.insert<component::nickname>(c_players.cbegin(),
                                             c_players.cend());

        registry.insert<component::country>(c_players.cbegin(),
                                            c_players.cend());

        registry.insert<component::age>(c_players.cbegin(), c_players.cend());

        registry.insert<component::role>(c_players.cbegin(), c_players.cend());

        registry.insert<component::skill>(c_players.cbegin(), c_players.cend());

        const std::vector<utility::country_code> c_countries_and_tier_skill{
            utility::players_countries_sort_by_skill_level(c_players_count)};

        std::for_each(
            std::execution::par_unseq, c_players.cbegin(), c_players.cend(),
            [&registry, &c_countries_and_tier_skill, &c_players_count,
             i = 0](const entt::entity& player) mutable {
                registry.patch<component::player>(
                    player, [](component::player& gender) {
                        gender._gender = vp::gender::m;
                    });
                registry.patch<component::country>(
                    player, [c_countries_and_tier_skill,
                             i](component::country& country) {
                        country._country = c_countries_and_tier_skill.at(i);
                        country._culture =
                            utility::to_culture(country._country);
                    });

                registry.patch<component::skill>(
                    player, [c_countries_and_tier_skill, i,
                             c_players_count](component::skill& skill) {
                        skill._skillLevel =
                            utility::createRandomSkillLevelByTier(
                                magic_enum::enum_integer(
                                    c_countries_and_tier_skill.at(
                                        i + c_players_count)));
                    });
                i++;
            });

        std::for_each(
            std::execution::par_unseq, c_players.cbegin(), c_players.cend(),
            [&registry](const entt::entity& player) {
                vp::gender gender =
                    registry.get<component::player>(player)._gender;
                vp::culture culture =
                    registry.get<component::country>(player)._culture;
                registry.patch<component::name>(player, [gender, culture](
                                                            component::name&
                                                                name) {
                    int random =
                        effolkronium::random_thread_local::get<int>(1, 30);
                    switch (random)
                    {
                    case 10:
                        name._first_name = vp::helper::ng::instance().get_name(
                                               gender, culture) +
                                           L" " +
                                           vp::helper::ng::instance().get_name(
                                               gender, culture);
                        name._last_name =
                            vp::helper::ng::instance().get_surname(culture);
                        name._internal_string =
                            name._first_name + L" " + name._last_name;
                        name._internal_container.push_back(name._first_name);
                        name._internal_container.push_back(name._last_name);
                        break;
                    case 20:
                        name._first_name = vp::helper::ng::instance().get_name(
                            gender, culture);
                        name._last_name =
                            vp::helper::ng::instance().get_surname(culture) +
                            L" " +
                            vp::helper::ng::instance().get_surname(culture);
                        name._internal_string =
                            name._first_name + L" " + name._last_name;
                        name._internal_container.push_back(name._first_name);
                        name._internal_container.push_back(name._last_name);
                        break;
                    case 30:
                        name._first_name = vp::helper::ng::instance().get_name(
                                               gender, culture) +
                                           L" " +
                                           vp::helper::ng::instance().get_name(
                                               gender, culture);
                        name._last_name =
                            vp::helper::ng::instance().get_surname(culture) +
                            L" " +
                            vp::helper::ng::instance().get_surname(culture);
                        name._internal_string =
                            name._first_name + L" " + name._last_name;
                        name._internal_container.push_back(name._first_name);
                        name._internal_container.push_back(name._last_name);
                        break;
                    default:
                        name._first_name = vp::helper::ng::instance().get_name(
                            gender, culture);
                        name._last_name =
                            vp::helper::ng::instance().get_surname(culture);
                        name._internal_string =
                            name._first_name + L" " + name._last_name;
                        name._internal_container.push_back(name._first_name);
                        name._internal_container.push_back(name._last_name);
                    }
                });
                registry.patch<component::nickname>(
                    player,
                    [&registry, &player](component::nickname& nickname) {
                        nickname._internal_string =
                            vp::helper::nng::instance().get_nickname(
                                registry.get<component::name>(player)
                                    ._internal_string);
                        nickname._original_string =
                            registry.get<component::name>(player)
                                ._internal_string;
                    });
            });

        std::for_each(
            c_players.cbegin(), c_players.cend(),
            [&registry](const entt::entity& player) {
                registry.patch<component::role>(player, [](component::role&
                                                               role) {
                    int randomRole;
                    role._primaryRoleCT =
                        magic_enum::enum_cast<utility::rolesCT>(
                            effolkronium::random_thread_local::get<int>(0, 4))
                            .value();
                    role._primaryRoleTR =
                        magic_enum::enum_cast<utility::rolesTR>(
                            effolkronium::random_thread_local::get<int>(0, 4))
                            .value();
                    do
                    {
                        randomRole =
                            effolkronium::random_thread_local::get<int>(0, 4);
                    } while (randomRole ==
                             magic_enum::enum_integer(role._primaryRoleCT));
                    role._secondaryRoleCT =
                        magic_enum::enum_cast<utility::rolesCT>(randomRole)
                            .value();
                    do
                    {
                        randomRole =
                            effolkronium::random_thread_local::get<int>(0, 4);
                    } while (randomRole ==
                             magic_enum::enum_integer(role._primaryRoleTR));
                    role._secondaryRoleTR =
                        magic_enum::enum_cast<utility::rolesTR>(randomRole)
                            .value();
                });
            });
    }

    void generate_metadata(entt::registry& registry)
    {
        registry.ctx().emplace<component::metadata>(
            std::array<std::uint8_t, 3>({0, 0, 0}),
            date::floor<date::days>(std::chrono::system_clock::now()),
            date::floor<date::days>(std::chrono::system_clock::now()),
            std::uint64_t{0});

        registry.ctx().emplace<component::generation_parameters>(
            std::size_t{600});

        registry.ctx().emplace<component::game_data>();
    }

} // namespace vp::helper