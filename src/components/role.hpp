#pragma once

#include "rolesEnum.hpp"

namespace vp::component
{
	struct role
	{
		utility::rolesCT _primaryRoleCT;
		utility::rolesCT _secondaryRoleCT;
		utility::rolesTR _primaryRoleTR;
		utility::rolesTR _secondaryRoleTR;
	};
}