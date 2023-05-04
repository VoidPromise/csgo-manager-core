#include "csgocore.hpp"

#include "generator.hpp"
#include "metadata.hpp"
#include "namegen.hpp"
#include "nicknamegen.hpp"
#include "pch.h"
#include "serializer.hpp"
#include "userdata.hpp"

#include <fstream>

namespace vp
{

    bool csgocore::initialize() const noexcept
    {
        try
        {
            plog::init(plog::verbose, "debug.txt");

            LOG_INFO << "Initializing core engine...";

            return load_resources();
        }
        catch (const std::exception&)
        {
            return false;
        }
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
        helper::generate_people(_registry);
    }

    void csgocore::next_step() noexcept
    {
    }

    void csgocore::next_day() noexcept
    {
    }

    bool csgocore::load_state(const std::filesystem::path& origin) noexcept
    {
        _registry.clear();

        return helper::load_game(_registry, origin);
    }

    bool csgocore::save_state(
        const std::filesystem::path& destination) const noexcept
    {
        return helper::save_game(_registry, destination);
    }

    helper::save_info csgocore::request_save_info(
        const std::filesystem::path& origin) const noexcept
    {
        return helper::load_save_info(origin);
    }

    bool csgocore::load_configuration() const noexcept
    {
        return false;
    }

    bool csgocore::load_resources() const noexcept
    {
        helper::nng::instance().load(
            "a_csmanager/nickname-generator/resources");
        helper::ng::instance().load("a_csmanager/name-generator/resources");

        return true;
    }

} // namespace vp