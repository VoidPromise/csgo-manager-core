#pragma once

#include <cstdint>
#include <vector>

namespace vp::component
{
	struct skill
	{
		std::uint8_t _skillLevel;
		std::vector<int> _generalAttributes; //the index define which skill
		std::vector<int> _gunsProficiency;
		std::vector<int> _utilityProficiency;
		std::vector<int> _roleKnowledge;
		std::vector<int> _mapKnowledge;
		std::vector<int> _ancientPositions;
		std::vector<int> _anubisPositions;
		std::vector<int> _cachePositions;
		std::vector<int> _cobblestonePositions;
		std::vector<int> _dust2Positions;
		std::vector<int> _infernoPositions;
		std::vector<int> _miragePositions;
		std::vector<int> _nukePositions;
		std::vector<int> _overpassPositions;
		std::vector<int> _trainPositions;
		std::vector<int> _vertigoPositions;
	};
}
