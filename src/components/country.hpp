#pragma once

#include "countryenum.hpp"
#include "culture.hpp"

namespace vp::component
{
    struct country
    {
        utility::country_code _country;
        vp::culture _culture;
    };
} // namespace vp::component
