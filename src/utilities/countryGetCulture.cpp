#include "countryGetCulture.hpp"

namespace vp::utility
{
    vp::culture countryGetCulture(availableCountries country)
    {
        switch (country)
        {
        case availableCountries::Argentina:
            return vp::culture::argentinian;
        case availableCountries::Australia:
            return vp::culture::australian;
        case availableCountries::Brazil:
            return vp::culture::brazilian;
        case availableCountries::China:
            return vp::culture::chinese;
        case availableCountries::Czech_Republic:
            return vp::culture::polish; // Need to include czech culture
        case availableCountries::Denmark:
            return vp::culture::danish;
        case availableCountries::Finland:
            return vp::culture::finnish;
        case availableCountries::France:
            return vp::culture::french;
        case availableCountries::Germany:
            return vp::culture::german;
        case availableCountries::Mongolia:
            return vp::culture::turkish; // Need to include mongolian culture
        case availableCountries::Poland:
            return vp::culture::polish;
        case availableCountries::Portugal:
            return vp::culture::portuguese;
        case availableCountries::Russia:
            return vp::culture::russian;
        case availableCountries::Sweden:
            return vp::culture::swedish;
        case availableCountries::Turkey:
            return vp::culture::turkish;
        case availableCountries::Ukraine:
            return vp::culture::ukrainian;
        case availableCountries::United_Kingdom:
            return vp::culture::british;
        case availableCountries::United_States:
            return vp::culture::american;
        case availableCountries::Belgium:
            return vp::culture::french;
        case availableCountries::Bosnia:
            return vp::culture::turkish;
        case availableCountries::Bulgaria:
            return vp::culture::bulgarian;
        case availableCountries::Canada:
            return vp::culture::canadian;
        case availableCountries::Chile:
            return vp::culture::argentinian;
        case availableCountries::Estonia:
            return vp::culture::russian;
        case availableCountries::Hungary:
            return vp::culture::polish; // Switch to czech
        case availableCountries::Israel:
            return vp::culture::russian;
        case availableCountries::Kazakhstan:
            return vp::culture::kazakh;
        case availableCountries::Kosovo:
            return vp::culture::turkish;
        case availableCountries::Latvia:
            return vp::culture::russian;
        case availableCountries::Mexico:
            return vp::culture::mexican;
        case availableCountries::Montenegro:
            return vp::culture::bulgarian;
        case availableCountries::Netherlands:
            return vp::culture::german;
        case availableCountries::New_Zealand:
            return vp::culture::australian;
        case availableCountries::Norway:
            return vp::culture::norwegian;
        case availableCountries::Romania:
            return vp::culture::bulgarian;
        case availableCountries::Serbia:
            return vp::culture::bulgarian;
        case availableCountries::Slovakia:
            return vp::culture::polish; // Switch to czech culture
        case availableCountries::South_Africa:
            return vp::culture::american;
        case availableCountries::Spain:
            return vp::culture::spanish;
        case availableCountries::Switzerland:
            return vp::culture::german;
        case availableCountries::Uruguay:
            return vp::culture::argentinian;
        default:
            return vp::culture::any;
        };
    }
}