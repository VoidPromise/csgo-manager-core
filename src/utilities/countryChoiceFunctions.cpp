#include "countrychoicefunctions.hpp"

#include "coach.hpp"
#include "player.hpp"

namespace vp::utility
{
    country_skill_level choose_random_countries_for_tier(
        std::vector<country_and_skill_limit>& configs,
        const std::map<country_code, double>& countries_distribuiton,
        const std::size_t& c_people_count)
    {
        static std::uint8_t s_configs_index;

        static std::uint8_t s_people_count_tier;

        static std::map<country_code, std::size_t> s_countries_count{};

        static std::map<country_code, std::size_t> s_countries_limit{};

        static std::vector<country_code> s_blacklisted_countries{};

        static std::once_flag s_flag{};

        std::call_once(s_flag, [&countries_distribuiton, &c_people_count]() {
            std::transform(
                magic_enum::enum_values<country_code>().cbegin(),
                magic_enum::enum_values<country_code>().cend(),
                std::inserter(s_countries_count, s_countries_count.end()),
                [](const country_code& c_country) {
                    return std::make_pair(c_country, 0);
                });
            std::transform(
                magic_enum::enum_values<country_code>().cbegin(),
                magic_enum::enum_values<country_code>().cend(),
                std::inserter(s_countries_limit, s_countries_limit.end()),
                [&countries_distribuiton,
                 &c_people_count](const country_code& c_country) {
                    return std::make_pair(
                        c_country, static_cast<std::size_t>(std::lround(
                                       c_people_count *
                                       countries_distribuiton.at(c_country))));
                });
            s_configs_index = {0};
            s_people_count_tier = {0};
        });

        if (s_people_count_tier ==
            static_cast<std::size_t>(
                std::lround(configs.at(s_configs_index).c_distribuition_tier *
                            c_people_count)))
        {
            s_configs_index++;
            s_people_count_tier = {0};
            std::for_each(
                s_blacklisted_countries.begin(), s_blacklisted_countries.end(),
                [&configs](country_code& country_to_erase) {
                    std::erase(configs.at(s_configs_index)._countries_to_choose,
                               country_to_erase);
                });
        }

        country_skill_level country_skill_level = {
            *effolkronium::random_thread_local::get(
                configs.at(s_configs_index)._countries_to_choose.cbegin(),
                configs.at(s_configs_index)._countries_to_choose.cend()),
            effolkronium::random_thread_local::get<std::uint8_t>(
                configs.at(s_configs_index).c_begin_range,
                configs.at(s_configs_index).c_end_range)};

        s_countries_count.at(country_skill_level._country)++;

        if (s_countries_count.at(country_skill_level._country) ==
            s_countries_limit.at(country_skill_level._country))
        {
            s_blacklisted_countries.push_back(country_skill_level._country);
            std::erase(configs.at(s_configs_index)._countries_to_choose,
                       country_skill_level._country);
        }

        s_people_count_tier++;

        return country_skill_level;
    }

    country_skill_level get_country_skill_level(
        entt::registry& registry, const entt::entity& c_person,
        const std::size_t c_people_count)
    {
        if (registry.any_of<component::player>(c_person))
        {
            return choose_random_countries_for_tier(s_players_generator_configs,
                                                    PLAYERS_DISTRIBUTION,
                                                    c_people_count);
        }
        else if (registry.any_of<component::coach>(c_person))
        {
            return choose_random_countries_for_tier(s_coaches_generator_configs,
                                                    COACHES_DISTRIBUITON,
                                                    c_people_count);
        }
        else
        {
            return {country_code::brazil, 70};
        }
    }
} // namespace vp::utility