#pragma once

#include "countryenum.hpp"
#include "culture.hpp"

namespace vp::utility
{
    vp::culture country_to_culture(const country_code& country);
}