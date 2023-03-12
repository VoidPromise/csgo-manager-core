#pragma once
#include "country_and_region.hpp"
#include "name.hpp"
#include "pch.h"

#include <string>

namespace vp::component
{
    struct user_data
    {
        std::wstring _username;
        component::name _name;
        std::wstring _nickname;
        date::year_month_day _birth;
        utility::country_code _country;
    };
} // namespace vp::component