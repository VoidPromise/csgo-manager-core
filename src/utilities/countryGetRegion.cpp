#include "countryGetRegion.hpp"

namespace vp::utility
{
	availableRegions countryGetRegion(availableCountries& country)
	{
		switch (country)
		{
			case availableCountries::Argentina:
				return availableRegions::Americas;
			case availableCountries::Australia:
				return availableRegions::Oceania;
			case availableCountries::Brazil:
				return availableRegions::Americas;
			case availableCountries::China:
				return availableRegions::Asia;
			case availableCountries::Czech_Republic:
				return availableRegions::Eastern_Europe;
			case availableCountries::Denmark:
				return availableRegions::Western_Europe;
			case availableCountries::Finland:
				return availableRegions::Western_Europe;
			case availableCountries::France:
				return availableRegions::Western_Europe;
			case availableCountries::Germany:
				return availableRegions::Western_Europe;
			case availableCountries::Mongolia:
				return availableRegions::Asia;
			case availableCountries::Poland:
				return availableRegions::Eastern_Europe;
			case availableCountries::Portugal:
				return availableRegions::Western_Europe;
			case availableCountries::Russia:
				return availableRegions::CIS;
			case availableCountries::Sweden:
				return availableRegions::Western_Europe;
			case availableCountries::Turkey:
				return availableRegions::Eastern_Europe;
			case availableCountries::Ukraine:
				return availableRegions::CIS;
			case availableCountries::United_Kingdom:
				return availableRegions::Western_Europe;
			case availableCountries::United_States:
				return availableRegions::Americas;
			case availableCountries::Belgium:
				return availableRegions::Western_Europe;
			case availableCountries::Bosnia:
				return availableRegions::Eastern_Europe;
			case availableCountries::Bulgaria:
				return availableRegions::Eastern_Europe;
			case availableCountries::Canada:
				return availableRegions::Americas;
			case availableCountries::Chile:
				return availableRegions::Americas;
			case availableCountries::Estonia:
				return availableRegions::Eastern_Europe;
			case availableCountries::Hungary:
				return availableRegions::Eastern_Europe;
			case availableCountries::Israel:
				return availableRegions::Eastern_Europe;
			case availableCountries::Kazakhstan:
				return availableRegions::CIS;
			case availableCountries::Kosovo:
				return availableRegions::Eastern_Europe;
			case availableCountries::Latvia:
				return availableRegions::Eastern_Europe;
			case availableCountries::Mexico:
				return availableRegions::Americas;
			case availableCountries::Montenegro:
				return availableRegions::Eastern_Europe;
			case availableCountries::Netherlands:
				return availableRegions::Western_Europe;
			case availableCountries::New_Zealand:
				return availableRegions::Oceania;
			case availableCountries::Norway:
				return availableRegions::Western_Europe;
			case availableCountries::Romania:
				return availableRegions::Eastern_Europe;
			case availableCountries::Serbia:
				return availableRegions::Eastern_Europe;
			case availableCountries::Slovakia:
				return availableRegions::Eastern_Europe;
			case availableCountries::South_Africa:
				return availableRegions::Americas;
			case availableCountries::Spain:
				return availableRegions::Western_Europe;
			case availableCountries::Switzerland:
				return availableRegions::Western_Europe;
			case availableCountries::Uruguay:
				return availableRegions::Americas;
			default:
				return availableRegions::Western_Europe;
		};
	}
}