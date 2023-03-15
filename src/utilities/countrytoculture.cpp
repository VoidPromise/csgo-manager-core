#include "countrytoculture.hpp"

namespace vp::utility
{
    vp::culture country_to_culture(const country_code& country)
    {
        switch (country)
        {
        case country_code::argentina:
        case country_code::chile:
        case country_code::uruguay:
            return vp::culture::argentinian;
        case country_code::australia:
        case country_code::new_zealand:
            return vp::culture::australian;
        case country_code::brazil:
            return vp::culture::brazilian;
        case country_code::china:
            return vp::culture::chinese;
        case country_code::czech_republic: // Need to include czech culture
        case country_code::poland:
        case country_code::hungary:  // Switch to czech
        case country_code::slovakia: // Switch to czech culture
            return vp::culture::polish;
        case country_code::denmark:
            return vp::culture::danish;
        case country_code::finland:
            return vp::culture::finnish;
        case country_code::france:
        case country_code::belgium:
            return vp::culture::french;
        case country_code::germany:
        case country_code::netherlands:
        case country_code::switzerland:
            return vp::culture::german;
        case country_code::mongolia: // Need to include mongolian culture
        case country_code::turkey:
        case country_code::bosnia:
        case country_code::kosovo:
            return vp::culture::turkish;
        case country_code::portugal:
            return vp::culture::portuguese;
        case country_code::russia:
        case country_code::estonia:
        case country_code::israel:
        case country_code::latvia:
            return vp::culture::russian;
        case country_code::sweden:
            return vp::culture::swedish;
        case country_code::ukraine:
            return vp::culture::ukrainian;
        case country_code::united_kingdom:
            return vp::culture::british;
        case country_code::united_states:
        case country_code::south_africa:
            return vp::culture::american;
        case country_code::bulgaria:
        case country_code::montenegro:
        case country_code::romania:
        case country_code::serbia:
            return vp::culture::bulgarian;
        case country_code::canada:
            return vp::culture::canadian;
        case country_code::kazakhstan:
            return vp::culture::kazakh;
        case country_code::mexico:
            return vp::culture::mexican;
        case country_code::norway:
            return vp::culture::norwegian;
        case country_code::spain:
            return vp::culture::spanish;
        default:
            return vp::culture::any;
        };
    }
} // namespace vp::utility