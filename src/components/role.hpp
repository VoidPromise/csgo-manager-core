#pragma once

#include "countriesRolesSkills.hpp"

namespace vp::component
{
	struct role
	{
		utility::rolesCT _primaryRoleCT;
		utility::rolesCT _secondaryRoleCT;
		utility::rolesCT _primaryRoleTR;
		utility::rolesCT _secondaryRoleTR;
	};
}