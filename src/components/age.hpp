#pragma once

#include "pch.h"

namespace vp::component
{
    struct age
    {
        std::uint8_t _value;
        date::year_month_day _birth;
    };
} // namespace vp::component