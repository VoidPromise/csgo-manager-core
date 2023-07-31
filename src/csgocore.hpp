#pragma once

#include "pch.h"

#include <filesystem>

namespace vp
{
    namespace helper
    {
        struct save_info;
    }

    namespace component
    {
        struct user_data;
    }

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

        // Save user data to registry.
        void set_user_data(const component::user_data& data) noexcept;

        // Initialize all necessary resources.
        bool new_game(const std::size_t number_people) noexcept;

        // Update game state by one step.
        void next_step() noexcept;

        // Update game state by necessary number of steps to reach next day.
        void next_day() noexcept;

        // Load a saved state from filesystem,
        [[nodiscard]] bool load_state(
            const std::filesystem::path& origin) noexcept;

        // Save iternal state of the engine.
        [[nodiscard]] bool save_state(
            const std::filesystem::path& destination) const noexcept;

        // Save iternal state of the engine.
        [[nodiscard]] helper::save_info request_save_info(
            const std::filesystem::path& origin) const noexcept;

        // Csgocore registry, holds all entities/components.
        entt::registry _registry;

      private:

        // Initialize csgocore, no complicated processes.
        csgocore() = default;

        // We don't manage any resource, all should gracefully deallocate by
        // itself.
        ~csgocore() = default;

        // Load all configuration files and set internal parameters.
        bool load_configuration() const noexcept;

        // Load all csgocore relevant resource files, such as images and
        // strings.
        bool load_resources() const noexcept;
    };
} // namespace vp
