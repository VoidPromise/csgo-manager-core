#include "countryGetCulture.hpp"

namespace vp::utility
{
    vp::culture to_culture(country_code country)
    {
        switch (country)
        {
        case country_code::Argentina:
            return vp::culture::argentinian;
        case country_code::Australia:
            return vp::culture::australian;
        case country_code::Brazil:
            return vp::culture::brazilian;
        case country_code::China:
            return vp::culture::chinese;
        case country_code::Czech_Republic:
            return vp::culture::polish; // Need to include czech culture
        case country_code::Denmark:
            return vp::culture::danish;
        case country_code::Finland:
            return vp::culture::finnish;
        case country_code::France:
            return vp::culture::french;
        case country_code::Germany:
            return vp::culture::german;
        case country_code::Mongolia:
            return vp::culture::turkish; // Need to include mongolian culture
        case country_code::Poland:
            return vp::culture::polish;
        case country_code::Portugal:
            return vp::culture::portuguese;
        case country_code::Russia:
            return vp::culture::russian;
        case country_code::Sweden:
            return vp::culture::swedish;
        case country_code::Turkey:
            return vp::culture::turkish;
        case country_code::Ukraine:
            return vp::culture::ukrainian;
        case country_code::United_Kingdom:
            return vp::culture::british;
        case country_code::United_States:
            return vp::culture::american;
        case country_code::Belgium:
            return vp::culture::french;
        case country_code::Bosnia:
            return vp::culture::turkish;
        case country_code::Bulgaria:
            return vp::culture::bulgarian;
        case country_code::Canada:
            return vp::culture::canadian;
        case country_code::Chile:
            return vp::culture::argentinian;
        case country_code::Estonia:
            return vp::culture::russian;
        case country_code::Hungary:
            return vp::culture::polish; // Switch to czech
        case country_code::Israel:
            return vp::culture::russian;
        case country_code::Kazakhstan:
            return vp::culture::kazakh;
        case country_code::Kosovo:
            return vp::culture::turkish;
        case country_code::Latvia:
            return vp::culture::russian;
        case country_code::Mexico:
            return vp::culture::mexican;
        case country_code::Montenegro:
            return vp::culture::bulgarian;
        case country_code::Netherlands:
            return vp::culture::german;
        case country_code::New_Zealand:
            return vp::culture::australian;
        case country_code::Norway:
            return vp::culture::norwegian;
        case country_code::Romania:
        case country_code::Serbia:
            return vp::culture::bulgarian;
        case country_code::Slovakia:
            return vp::culture::polish; // Switch to czech culture
        case country_code::South_Africa:
            return vp::culture::american;
        case country_code::Spain:
            return vp::culture::spanish;
        case country_code::Switzerland:
            return vp::culture::german;
        case country_code::Uruguay:
            return vp::culture::argentinian;
        default:
            return vp::culture::any;
        };
    }
} // namespace vp::utility