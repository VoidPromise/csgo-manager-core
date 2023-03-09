#pragma once

#include "gender.hpp"

namespace vp::component
{
    struct player
    {
        vp::gender _gender;//criei pq no namegen já tinha um arquivo gender.hpp, dai não quis criar um componente com o mesmo nome, depois tu decide o que fazer
    };
} // namespace vp::component