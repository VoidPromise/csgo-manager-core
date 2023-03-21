#pragma once

#include "pch.h"

#include <array>
#include <cstdint>

namespace vp::component
{
    struct generation_parameters
    {
        std::size_t _players_count;
        std::size_t _coaches_count;
    };
} // namespace vp::component