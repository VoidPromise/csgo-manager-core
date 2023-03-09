#pragma once
#include <array>
#include <cstdint>

#include "pch.h"

namespace vp::component
{
    struct metadata
    {
        std::array<std::uint8_t, 3> _version;
        date::year_month_day _created;
        date::year_month_day _last_modification;
        std::uint64_t _current_tick;
    };
} // namespace vp::component