#include "generator.hpp"
#include "metadata.hpp"
#include "name.hpp"
#include "namegen.hpp"
#include "nickname.hpp"
#include "nicknamegen.hpp"
#include "player.hpp"

#include "age.hpp"
#include "country.hpp"
#include "role.hpp"
#include "skill.hpp"

#include <execution>

#include "countryChoiceFunctions.hpp"
#include "countryGetCulture.hpp"
#include "createRandomSkillLevelByTier.hpp"

namespace vp::helper
{
    void generate_players(entt::registry& registry)
    {
        const int numberPlayersToCreate = 600;

        const std::vector<entt::entity> players{numberPlayersToCreate,
                                                registry.create()};

        const std::vector<int> countriesAndTierSkill =
            utility::playersCountriesSortBySkillLevel(numberPlayersToCreate);

        std::for_each(
            players.cbegin(), players.cend(),
            [&registry, countriesAndTierSkill, numberPlayersToCreate,
             i = 0](const entt::entity& player) mutable {
                registry.emplace<component::player>(player);
                registry.emplace<component::name>(player);
                registry.emplace<component::nickname>(player);
                registry.emplace<component::country>(player);
                registry.emplace<component::age>(player);
                registry.emplace<component::role>(player);
                registry.emplace<component::skill>(player);
                registry.patch<component::player>(
                    player, [](component::player& gender) {
                        gender._gender = vp::gender::m;
                    });
                registry.patch<component::country>(
                    player,
                    [countriesAndTierSkill, i](component::country& country) {
                        country._country =
                            magic_enum::enum_cast<utility::availableCountries>(
                                countriesAndTierSkill.at(i))
                                .value();
                        country._culture =
                            utility::countryGetCulture(country._country);
                    });

                registry.patch<component::skill>(
                    player, [countriesAndTierSkill, i,
                             numberPlayersToCreate](component::skill& skill) {
                        skill._skillLevel =
                            utility::createRandomSkillLevelByTier(
                                countriesAndTierSkill.at(
                                    i + numberPlayersToCreate));
                    });
                i++;
            });

        std::for_each(
            std::execution::par_unseq, players.cbegin(), players.cend(),
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
            players.cbegin(), players.cend(),
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
                registry.ctx().emplace<component::metadata>(std::uint64_t{0});
    }

} // namespace vp::helper