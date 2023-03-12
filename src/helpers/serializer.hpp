#pragma once
#include "pch.h"

#include <filesystem>

namespace vp::helper
{
    bool load_registry(entt::registry& registry,
                       const std::filesystem::path& origin);

    bool save_registry(const entt::registry& registry,
                       const std::filesystem::path& destination);
} // namespace vp::helper