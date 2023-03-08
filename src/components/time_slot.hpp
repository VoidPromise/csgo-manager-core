#pragma once

namespace vp::component
{
    struct time_slot
    {
        date::year_month_day _begin;
        date::year_month_day _end;
        std::uint16_t _duration;
    };
} // namespace vp::component