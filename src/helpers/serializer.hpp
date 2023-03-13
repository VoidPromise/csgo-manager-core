#pragma once
#include "csversion.hpp"
#include "pch.h"

#include <filesystem>

namespace vp::helper
{
    struct save_info
    {
        bool _valid;
        std::array<std::uint8_t, 3> _version;
        date::year_month_day _created;
        date::year_month_day _last_modification;
        utility::cs_version _cs_version;
        std::string _title_short;
        date::year_month_day _current_day;
        std::wstring _username;
    };

    bool load_registry(entt::registry& registry,
                       const std::filesystem::path& origin) noexcept;

    bool save_registry(const entt::registry& registry,
                       const std::filesystem::path& destination) noexcept;

    save_info load_save_info(const std::filesystem::path& origin) noexcept;
} // namespace vp::helper