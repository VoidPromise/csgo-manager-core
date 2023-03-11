#include "serializer.hpp"

#include <fstream>

#include "metadata.hpp"
#include "userdata.hpp"

namespace vp::helper
{
    template <typename Archive> void serialize(Archive& archive, component::user_data& data)
    {
        archive(data._birth, data._country, data._name, data._nickname, data._username);
    }

    template <typename Archive>
    void serialize(Archive& archive, component::metadata& data)
    {
        archive(data._created, data._current_tick, data._last_modification, data._version);
    }

    bool load_registry(entt::registry& registry,
                       const std::filesystem::path& origin)
    {
        try
        {
            std::ifstream input_stream{origin};

            cereal::JSONInputArchive input{input_stream};

            entt::snapshot_loader{registry}
                .entities(input)
                .component<component::user_data, component::metadata>(input);

            return true;
        }
        catch (std::exception& e)
        {
            return false;
        }
    }

    bool save_registry(const entt::registry& registry,
                       const std::filesystem::path& destination,
                       save_format format)
    {
        try
        {
            std::ofstream output_stream{destination};

            cereal::JSONOutputArchive output{output_stream};

            entt::snapshot{registry}
                .entities(output)
                .component<component::user_data, component::metadata>(output);

            return true;
        }
        catch (std::exception& e)
        {
            return false;
        }
    }
} // namespace vp::helper
