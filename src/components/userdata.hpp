#pragma once
#include <string>

#include "countriesRegionsEnums.hpp"
#include "name.hpp"
#include "pch.h"

namespace vp::component
{
    struct userdata
    {
        std::wstring _username;
        component::name _name;
        std::wstring _nickname;
        date::year_month_day _birth;
        utility::availableCountries _country;
    };
} // namespace vp::component