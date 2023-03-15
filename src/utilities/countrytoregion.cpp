#include "countrytoregion.hpp"

namespace vp::utility
{
    region_code country_to_region(const country_code& country)
    {
        switch (country)
        {
        case country_code::argentina:
        case country_code::brazil:
        case country_code::united_states:
        case country_code::canada:
        case country_code::chile:
        case country_code::mexico:
        case country_code::south_africa:
        case country_code::uruguay:
            return region_code::Americas;
        case country_code::australia:
        case country_code::new_zealand:
            return region_code::Oceania;
        case country_code::china:
        case country_code::mongolia:
            return region_code::Asia;
        case country_code::czech_republic:
        case country_code::poland:
        case country_code::turkey:
        case country_code::bosnia:
        case country_code::bulgaria:
        case country_code::estonia:
        case country_code::hungary:
        case country_code::israel:
        case country_code::kosovo:
        case country_code::latvia:
        case country_code::montenegro:
        case country_code::romania:
        case country_code::serbia:
        case country_code::slovakia:
            return region_code::Eastern_Europe;
        case country_code::denmark:
        case country_code::finland:
        case country_code::france:
        case country_code::germany:
        case country_code::portugal:
        case country_code::sweden:
        case country_code::united_kingdom:
        case country_code::belgium:
        case country_code::netherlands:
        case country_code::norway:
        case country_code::spain:
        case country_code::switzerland:
            return region_code::Western_Europe;
        case country_code::russia:
        case country_code::ukraine:
        case country_code::kazakhstan:
            return region_code::CIS;
        default:
            return region_code::Western_Europe;
        };
    }
} // namespace vp::utility