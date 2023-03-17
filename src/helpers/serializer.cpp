#include "serializer.hpp"

namespace vp::helper
{
    bool load_game(entt::registry& registry,
                   const std::filesystem::path& origin) noexcept
    {
        try
        {
            std::ifstream input_stream{origin, std::ios::binary};

            cereal::BinaryInputArchive input{input_stream};

            entt::snapshot_loader{registry}
                .entities(input)
                .component<component::age, component::country,
                           component::game_data, component::metadata,
                           component::name, component::nickname,
                           component::player, component::role, component::skill,
                           component::user_data>(input);

            return true;
        }
        catch (std::exception&)
        {
            return false;
        }
    }

    bool save_game(const entt::registry& registry,
                   const std::filesystem::path& destination) noexcept
    {
        try
        {
            std::filesystem::path info_path{destination};

            info_path.replace_extension("saveinfo");

            std::ofstream output_stream{destination, std::ios::binary};

            cereal::BinaryOutputArchive output{output_stream};

            entt::snapshot{registry}
                .entities(output)
                .component<component::age, component::country,
                           component::game_data, component::metadata,
                           component::name, component::nickname,
                           component::player, component::role, component::skill,
                           component::user_data>(output);

            std::ofstream output_info_stream{destination, std::ios::binary};

            cereal::BinaryOutputArchive output_info{output_info_stream};

            const auto c_info_view{
                registry.view<component::metadata, component::user_data,
                              component::game_data>()};

            entt::snapshot{registry}
                .component<component::metadata, component::user_data,
                           component::game_data>(output_info, c_info_view.begin(),
                                                 c_info_view.end());

            return true;
        }
        catch (std::exception&)
        {
            return false;
        }
    }

    bool import_players(entt::registry& registry,
                        const std::filesystem::path& origin) noexcept
    {
        try
        {
            std::ifstream input_stream{origin, std::ios::binary};

            cereal::BinaryInputArchive input{input_stream};

            entt::registry temp_registry{};

            entt::snapshot_loader{temp_registry}
                .entities(input)
                .component<component::age, component::country, component::name,
                           component::nickname, component::player,
                           component::role, component::skill>(input)
                .orphans();

            temp_registry.each([&registry](const entt::entity c_entity) {
                const entt::entity c_new_entity{registry.create()};
                registry.emplace<component::player>(c_new_entity);
                registry.emplace<component::age>(
                    c_new_entity, registry.get<component::age>(c_entity));
                registry.emplace<component::country>(
                    c_new_entity, registry.get<component::country>(c_entity));
                registry.emplace<component::name>(
                    c_new_entity, registry.get<component::name>(c_entity));
                registry.emplace<component::nickname>(
                    c_new_entity, registry.get<component::nickname>(c_entity));
                registry.emplace<component::role>(
                    c_new_entity, registry.get<component::role>(c_entity));
                registry.emplace<component::skill>(
                    c_new_entity, registry.get<component::skill>(c_entity));
            });

            return true;
        }
        catch (std::exception&)
        {
            return false;
        }
    }

    bool export_players(const entt::registry& registry,
                        const std::filesystem::path& destination) noexcept
    {
        try
        {
            std::filesystem::path save_path{destination};

            save_path.replace_extension("player");

            std::ofstream output_stream{save_path, std::ios::binary};

            cereal::BinaryOutputArchive output{output_stream};

            entt::snapshot{registry}
                .component<component::age, component::country, component::name,
                           component::nickname, component::player,
                           component::role, component::skill>(output);

            return true;
        }
        catch (std::exception&)
        {
            return false;
        }
    }

    save_info load_save_info(const std::filesystem::path& origin) noexcept
    {
        try
        {
            std::filesystem::path info_path{origin};

            info_path.replace_extension("saveinfo");

            std::ifstream input_info_stream{info_path, std::ios::binary};

            cereal::BinaryInputArchive input_info{input_info_stream};

            entt::registry temp_registry{};

            entt::snapshot_loader{temp_registry}
                .entities(input_info)
                .component<component::metadata, component::user_data,
                           component::game_data>(input_info);

            const component::metadata c_metadata{
                temp_registry.ctx().get<component::metadata>()};

            const component::user_data c_user_data{
                temp_registry.ctx().get<component::user_data>()};

            const component::game_data c_game_data{
                temp_registry.ctx().get<component::game_data>()};

            return {true,
                    c_metadata._version,
                    c_metadata._created,
                    c_metadata._last_modification,
                    c_game_data._version,
                    c_game_data._title_short,
                    c_game_data._current_day,
                    c_user_data._username};
        }
        catch (const std::exception&)
        {
            return save_info{};
        }
    }
} // namespace vp::helper
