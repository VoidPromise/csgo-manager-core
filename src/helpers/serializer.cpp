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
                .component<component::metadata>(input);

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
            std::ofstream output_stream{destination, std::ios::binary};

            cereal::BinaryOutputArchive output{output_stream};

            entt::snapshot{registry}
                .entities(output)
                .component<component::metadata>(output);

            return true;
        }
        catch (std::exception& e)
        {
            return false;
        }
    }
} // namespace vp::helper
