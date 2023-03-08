#include "generator.hpp"
#include "metadata.hpp"
#include "name.hpp"
#include "namegen.hpp"
#include "nickname.hpp"
#include "nicknamegen.hpp"
#include "player.hpp"

#include <execution>

namespace vp::helper
{
    void generate_players(entt::registry& registry)
    {
        const std::vector<entt::entity> players{1000, registry.create()};

        std::for_each(std::execution::seq, players.cbegin(), players.cend(),
                      [&registry](const entt::entity& player) {
                          registry.emplace<component::player>(player);
                          registry.emplace<component::name>(player);
                          registry.emplace<component::nickname>(player);
                      });

        std::for_each(
            std::execution::par_unseq, players.cbegin(), players.cend(),
            [&registry](const entt::entity& player) {
                registry.patch<component::name>(
                    player, [](component::name& name) {
                        name._first_name =
                            vp::helper::ng::instance().get_name();
                        name._last_name =
                            vp::helper::ng::instance().get_surname();
                        name._internal_string =
                            name._first_name + L" " + name._last_name;
                        name._internal_container.push_back(name._first_name);
                        name._internal_container.push_back(name._last_name);
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
    }

    void generate_metadata(entt::registry& registry)
    {
        registry.ctx().emplace<component::metadata>(0);
    }

} // namespace vp::helper