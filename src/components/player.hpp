#pragma once

#include "gender.hpp"

namespace vp::component
{
    struct player
    {
        vp::gender _gender;//criei pq no namegen j� tinha um arquivo gender.hpp, dai n�o quis criar um componente com o mesmo nome, depois tu decide o que fazer
    };
} // namespace vp::component