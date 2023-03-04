#include "csgocore.hpp"

bool vp::csgocore::initialize() const noexcept
{
    return load_configuration() && load_resources();
}

bool vp::csgocore::load_state(
    const std::filesystem::path& origin) const noexcept
{
    return false;
}

bool vp::csgocore::save_state(
    const std::filesystem::path& destination) const noexcept
{
    return false;
}

bool vp::csgocore::load_configuration() const noexcept
{
    return false;
}

bool vp::csgocore::load_resources() const noexcept
{
    return false;
}
