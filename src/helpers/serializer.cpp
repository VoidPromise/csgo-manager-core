#include "serializer.hpp"

#include "cerealfunctions.hpp"

#include <fstream>

namespace vp::helper
{
    bool load_registry(entt::registry& registry,
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
        catch (std::exception& e)
        {
            return false;
        }
    }

    bool save_registry(const entt::registry& registry,
                       const std::filesystem::path& destination) noexcept
    {
        try
        {
            std::filesystem::path info_path{destination};

            info_path.replace_extension("saveinfo");

            std::ofstream output_stream{destination, std::ios::binary};

            std::ofstream output_info_stream{destination, std::ios::binary};

            cereal::BinaryOutputArchive output{output_stream};

            cereal::BinaryOutputArchive output_info{output_info_stream};

            entt::snapshot{registry}
                .entities(output)
                .component<component::age, component::country,
                           component::game_data, component::metadata,
                           component::name, component::nickname,
                           component::player, component::role, component::skill,
                           component::user_data>(output);

            entt::snapshot{registry}
                .entities(output_info)
                .component<component::metadata, component::user_data,
                           component::game_data>(output_info);

            return true;
        }
        catch (std::exception& e)
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
        catch (const std::exception& e)
        {
            return save_info{};
        }
    }
} // namespace vp::helper
