#pragma once

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

  private:
    // Initialize csgocore, no complicated processes.
    csgocore() = default;

    // We don't manage any resource, all should gracefully deallocate by itself.
    ~csgocore() = default;
};
} // namespace vp
