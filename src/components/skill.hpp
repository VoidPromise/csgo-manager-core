#pragma once

#include <cstdint>
#include <vector>

namespace vp::component
{
    struct skill
    {
        std::uint8_t _skillLevel;
        std::vector<std::uint8_t>
            _generalAttributes; // the index define which skill
        std::vector<std::uint8_t> _gunsProficiency;
        std::vector<std::uint8_t> _utilityProficiency;
        std::vector<std::uint8_t> _roleKnowledge;
        std::vector<std::uint8_t> _mapKnowledge;
        std::vector<std::uint8_t> _ancientPositions;
        std::vector<std::uint8_t> _anubisPositions;
        std::vector<std::uint8_t> _cachePositions;
        std::vector<std::uint8_t> _cobblestonePositions;
        std::vector<std::uint8_t> _dust2Positions;
        std::vector<std::uint8_t> _infernoPositions;
        std::vector<std::uint8_t> _miragePositions;
        std::vector<std::uint8_t> _nukePositions;
        std::vector<std::uint8_t> _overpassPositions;
        std::vector<std::uint8_t> _trainPositions;
        std::vector<std::uint8_t> _vertigoPositions;
    };
} // namespace vp::component
