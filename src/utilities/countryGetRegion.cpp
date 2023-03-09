#include "countryGetRegion.hpp"

namespace vp::utility
{
    availableRegions countryGetRegion(availableCountries& country)
    {
        switch (country)
        {
        case availableCountries::Argentina:
        case availableCountries::Brazil:
        case availableCountries::United_States:
        case availableCountries::Canada:
        case availableCountries::Chile:
        case availableCountries::Mexico:
        case availableCountries::South_Africa:
        case availableCountries::Uruguay:
            return availableRegions::Americas;
        case availableCountries::Australia:
        case availableCountries::New_Zealand:
            return availableRegions::Oceania;
        case availableCountries::China:
        case availableCountries::Mongolia:
            return availableRegions::Asia;
        case availableCountries::Czech_Republic:
        case availableCountries::Poland:
        case availableCountries::Turkey:
        case availableCountries::Bosnia:
        case availableCountries::Bulgaria:
        case availableCountries::Estonia:
        case availableCountries::Hungary:
        case availableCountries::Israel:
        case availableCountries::Kosovo:
        case availableCountries::Latvia:
        case availableCountries::Montenegro:
        case availableCountries::Romania:
        case availableCountries::Serbia:
        case availableCountries::Slovakia:
            return availableRegions::Eastern_Europe;
        case availableCountries::Denmark:
        case availableCountries::Finland:
        case availableCountries::France:
        case availableCountries::Germany:
        case availableCountries::Portugal:
        case availableCountries::Sweden:
        case availableCountries::United_Kingdom:
        case availableCountries::Belgium:
        case availableCountries::Netherlands:
        case availableCountries::Norway:
        case availableCountries::Spain:
        case availableCountries::Switzerland:
            return availableRegions::Western_Europe;
        case availableCountries::Russia:
        case availableCountries::Ukraine:
        case availableCountries::Kazakhstan:
            return availableRegions::CIS;
        default:
            return availableRegions::Western_Europe;
        };
    }
} // namespace vp::utility