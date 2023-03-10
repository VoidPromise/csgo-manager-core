#pragma once

#include "country_and_region.hpp"
#include "culture.hpp"

namespace vp::utility
{
    vp::culture to_culture(country_code country);
}