#include "serializer.hpp"

#include "cerealfunctions.hpp"

#include <fstream>

namespace vp::helper
{
    bool load_registry(entt::registry& registry,
                       const std::filesystem::path& origin)
    {
        try
        {
            std::ifstream input_stream{origin};

            cereal::BinaryInputArchive input{input_stream};

            entt::snapshot_loader{registry}
                .entities(input)
                .component<component::metadata, component::user_data,
                           component::game_data>(input);

            return true;
        }
        catch (std::exception& e)
        {
            return false;
        }
    }

    bool save_registry(const entt::registry& registry,
                       const std::filesystem::path& destination)
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
                .entities(output)
                .component<component::metadata, component::user_data,
                           component::game_data>(output_info);

            return true;
        }
        catch (std::exception& e)
        {
            return false;
        }
    }
} // namespace vp::helper
