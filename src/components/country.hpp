#pragma once

#include "countriesRegionsEnums.hpp"
#include "culture.hpp"

namespace vp::component
{
	struct country
	{
		utility::availableCountries _country;
        vp::culture _culture;
	};
}
