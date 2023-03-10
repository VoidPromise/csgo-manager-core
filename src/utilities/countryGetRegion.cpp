#include "countryGetRegion.hpp"

namespace vp::utility
{
    region_code countryGetRegion(country_code& country)
    {
        switch (country)
        {
        case country_code::Argentina:
        case country_code::Brazil:
        case country_code::United_States:
        case country_code::Canada:
        case country_code::Chile:
        case country_code::Mexico:
        case country_code::South_Africa:
        case country_code::Uruguay:
            return region_code::Americas;
        case country_code::Australia:
        case country_code::New_Zealand:
            return region_code::Oceania;
        case country_code::China:
        case country_code::Mongolia:
            return region_code::Asia;
        case country_code::Czech_Republic:
        case country_code::Poland:
        case country_code::Turkey:
        case country_code::Bosnia:
        case country_code::Bulgaria:
        case country_code::Estonia:
        case country_code::Hungary:
        case country_code::Israel:
        case country_code::Kosovo:
        case country_code::Latvia:
        case country_code::Montenegro:
        case country_code::Romania:
        case country_code::Serbia:
        case country_code::Slovakia:
            return region_code::Eastern_Europe;
        case country_code::Denmark:
        case country_code::Finland:
        case country_code::France:
        case country_code::Germany:
        case country_code::Portugal:
        case country_code::Sweden:
        case country_code::United_Kingdom:
        case country_code::Belgium:
        case country_code::Netherlands:
        case country_code::Norway:
        case country_code::Spain:
        case country_code::Switzerland:
            return region_code::Western_Europe;
        case country_code::Russia:
        case country_code::Ukraine:
        case country_code::Kazakhstan:
            return region_code::CIS;
        default:
            return region_code::Western_Europe;
        };
    }
} // namespace vp::utility