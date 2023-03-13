#pragma once

#include "csversion.hpp"

namespace vp::component
{
    struct game_data
    {
        std::string _title_short;
        std::string _title_long;
        std::string _description;
        utility::cs_version _version;
        date::year_month_day _first_day;
        date::year_month_day _current_day;
    };
} // namespace vp::component