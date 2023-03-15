#pragma once

#include <cstdint>
#include <vector>

namespace vp::component
{
    struct skill
    {
        std::uint8_t _skill_level;
        std::vector<std::uint8_t>
            _general_attributes; // the index define which skill
        std::vector<std::uint8_t> _guns_proficiency;
        std::vector<std::uint8_t> _grenades_proficiency;
        std::vector<std::uint8_t> _role_knowledge;
        std::vector<std::uint8_t> _map_knowledge;
        std::vector<std::uint8_t> _ancient_positions;
        std::vector<std::uint8_t> _anubis_positions;
        std::vector<std::uint8_t> _cache_positions;
        std::vector<std::uint8_t> _cobblestone_positions;
        std::vector<std::uint8_t> _dust2_positions;
        std::vector<std::uint8_t> _inferno_positions;
        std::vector<std::uint8_t> _mirage_positions;
        std::vector<std::uint8_t> _nuke_positions;
        std::vector<std::uint8_t> _overpass_positions;
        std::vector<std::uint8_t> _train_positions;
        std::vector<std::uint8_t> _vertigo_positions;
    };
} // namespace vp::component
