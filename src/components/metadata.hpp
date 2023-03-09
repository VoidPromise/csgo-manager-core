#pragma once
#include <cstdint>

namespace vp::component
{
    struct metadata
    {
        std::uint64_t _current_tick;
        date::year_month_day _created;
        date::year_month_day _last_modification;
    };
} // namespace vp::component