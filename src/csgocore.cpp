#include "csgocore.hpp"
#include "generator.hpp"
#include "namegen.hpp"
#include "nicknamegen.hpp"

namespace vp
{

bool csgocore::initialize() const noexcept
{
    plog::init(plog::verbose, "debug.txt");

    LOG_INFO << "Initializing core engine...";

    return load_configuration() && load_resources();
}

void csgocore::new_game() noexcept
{
    helper::generate_players(_registry);
    helper::generate_coaches();
}

bool csgocore::load_state(const std::filesystem::path& origin) const noexcept
{
    return false;
}

bool csgocore::save_state(
    const std::filesystem::path& destination) const noexcept
{
    return false;
}

bool csgocore::load_configuration() const noexcept
{
    return false;
}

bool csgocore::load_resources() const noexcept
{
    helper::nng::instance().load("");
    helper::ng::instance().load("");

    return true;
}

} // namespace vp