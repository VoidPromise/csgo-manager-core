#pragma once

#include "rolesenum.hpp"

namespace vp::component
{
    struct role
    {
        utility::roles _primary_role_ct;
        utility::roles _secondary_role_ct;
        utility::roles _primary_role_tr;
        utility::roles _secondary_role_tr;
    };
} // namespace vp::component