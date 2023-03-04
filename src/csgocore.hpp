#pragma once

#include <filesystem>

#include "pch.h"

namespace vp
{
class csgocore
{
  public:
    // Copy/move constructors can be deleted since they are not going to be
    // used due to singleton pattern.
    csgocore(const csgocore&) = delete;
    csgocore(csgocore&&) = delete;
    csgocore& operator=(const csgocore&) = delete;
    csgocore& operator=(csgocore&&) = delete;

    // Thread safe access to csgocore singleton.
    static inline csgocore& instance() noexcept
    {
        static csgocore instance{};
        return instance;
    }

    // Initialize all necessary resources.
    [[nodiscard]] bool initialize() const noexcept;

    // Initialize all necessary resources.
    [[nodiscard]] void new_game() noexcept;

    // Load a saved state from filesystem,
    [[nodiscard]] bool load_state(
        const std::filesystem::path& origin) const noexcept;

    // Save iternal state of the engine.
    [[nodiscard]] bool save_state(
        const std::filesystem::path& destination) const noexcept;

  private:
    // Csgocore registry, holds all entities/components.
    entt::registry _registry;

    // Initialize csgocore, no complicated processes.
    csgocore() = default;

    // We don't manage any resource, all should gracefully deallocate by itself.
    ~csgocore() = default;

    // Load all configuration files and set internal parameters.
    bool load_configuration() const noexcept;

    // Load all csgocore relevant resource files, such as images and strings.
    bool load_resources() const noexcept;
};
} // namespace vp
