#include "csgocore.hpp"
#include "generator.hpp"
#include "namegen.hpp"
#include "nicknamegen.hpp"
#include "jsonarchive.hpp"

namespace vp
{

    bool csgocore::initialize() const noexcept
    {
        plog::init(plog::verbose, "debug.txt");

        LOG_INFO << "Initializing core engine...";

        return load_configuration() && load_resources();
    }

    void csgocore::set_user_data(const component::user_data& data) noexcept
    {
        _registry.ctx().emplace<component::user_data>(data);
    }

    void csgocore::new_game() noexcept
    {
        helper::generate_metadata(_registry);
        /*helper::generate_countries(_registry);
        helper::generate_tournament_organizers(_registry);
        helper::generate_teams(_registry);*/
        helper::generate_players(_registry);
        helper::generate_coaches();
    }

    void csgocore::next_step() noexcept
    {
    }

    void csgocore::next_day() noexcept
    {
    }

    bool csgocore::load_state(
        const std::filesystem::path& origin) const noexcept
    {
        return false;
    }

    bool csgocore::save_state(const std::filesystem::path& destination) const noexcept
    {
        //entt::basic_snapshot<entt::registry> snapshot{_registry};

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