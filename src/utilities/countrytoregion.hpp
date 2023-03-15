#pragma once

#include "regionenum.hpp"
#include "countryenum.hpp"

namespace vp::utility
{
    region_code country_to_region(const country_code& country);
}