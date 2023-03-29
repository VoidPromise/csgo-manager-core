#pragma once

#include "rolesenum.hpp"

namespace vp::component
{
    struct role
    {
        utility::roles_ct _primary_role_ct;
        utility::roles_ct _secondary_role_ct;
        utility::roles_tr _primary_role_tr;
        utility::roles_tr _secondary_role_tr;
    };
} // namespace vp::component