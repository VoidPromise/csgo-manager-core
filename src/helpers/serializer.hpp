#pragma once
#include "pch.h"

#include <filesystem>

namespace vp::helper
{
    enum class save_format
    {
        binary,
        json
    };

    bool load_registry(entt::registry& registry,
                       const std::filesystem::path& origin);

    bool save_registry(const entt::registry& registry,
                       const std::filesystem::path& destination,
                       save_format format);
} // namespace vp::helper