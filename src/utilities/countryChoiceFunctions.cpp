#include "countrychoicefunctions.hpp"

#include "coach.hpp"
#include "player.hpp"

namespace vp::utility
{
    generation_limit_control fill_generation_limit(
        const std::map<country_code, double>& countries_distribuiton,
        const std::size_t& c_people_count)
    {
        generation_limit_control generation_limit_control;

        std::transform(
            magic_enum::enum_values<country_code>().cbegin(),
            magic_enum::enum_values<country_code>().cend(),
                       std::inserter(generation_limit_control.s_countries_count,
                          generation_limit_control.s_countries_count.end()),
            [](const country_code& c_country) {
                return std::make_pair(c_country, 0);
            });
        std::transform(
            magic_enum::enum_values<country_code>().cbegin(),
            magic_enum::enum_values<country_code>().cend(),
            std::inserter(generation_limit_control.s_countries_limit,
                          generation_limit_control.s_countries_limit.end()),
            [&countries_distribuiton,
             &c_people_count](const country_code& c_country) {
                return std::make_pair(
                    c_country, static_cast<std::size_t>(std::lround(
                                   c_people_count *
                                   countries_distribuiton.at(c_country))));
            });
        generation_limit_control.s_configs_index = {0};
        generation_limit_control.s_people_count_tier = {0};
        generation_limit_control.s_blacklisted_countries = {};

        return generation_limit_control;
    }

    country_skill_level choose_random_countries_for_tier(
        std::vector<parameters_for_generation>& configs,
        generation_limit_control& limits, const std::size_t& c_people_count)
    {
        if (limits.s_people_count_tier ==
            static_cast<std::size_t>(std::lround(
                configs.at(limits.s_configs_index).c_distribuition_tier *
                c_people_count)))
        {
            limits.s_configs_index++;
            limits.s_people_count_tier = {0};
            std::for_each(
                limits.s_blacklisted_countries.begin(),
                limits.s_blacklisted_countries.end(),
                [&configs, &limits](country_code& country_to_erase) {
                    std::erase(
                        configs.at(limits.s_configs_index)._countries_to_choose,
                        country_to_erase);
                });
        }

        country_skill_level country_skill_level = {
            *effolkronium::random_thread_local::get(
                configs.at(limits.s_configs_index)
                    ._countries_to_choose.cbegin(),
                configs.at(limits.s_configs_index)._countries_to_choose.cend()),
            effolkronium::random_thread_local::get<std::uint8_t>(
                configs.at(limits.s_configs_index).c_begin_range,
                configs.at(limits.s_configs_index).c_end_range)};

        limits.s_countries_count.at(country_skill_level._country)++;

        if (limits.s_countries_count.at(country_skill_level._country) ==
            limits.s_countries_limit.at(country_skill_level._country))
        {
            limits.s_blacklisted_countries.push_back(
                country_skill_level._country);
            std::erase(configs.at(limits.s_configs_index)._countries_to_choose,
                       country_skill_level._country);
        }

        limits.s_people_count_tier++;

        return country_skill_level;
    }

    country_skill_level get_country_skill_level(
        entt::registry& registry, const entt::entity& c_person,
        const std::size_t c_people_count)
    {
        static generation_limit_control s_generation_limit_control;

        static std::once_flag s_flag1{};
        static std::once_flag s_flag2{};

        if (registry.any_of<component::player>(c_person))
        {
            std::call_once(s_flag1, [&c_people_count]() {
                s_generation_limit_control =
                    fill_generation_limit(PLAYERS_DISTRIBUTION, c_people_count);
            });

            return choose_random_countries_for_tier(s_players_generator_configs,
                                                    s_generation_limit_control,
                                                    c_people_count);
        }
        else if (registry.any_of<component::coach>(c_person))
        {
            std::call_once(s_flag2, [&c_people_count]() {
                s_generation_limit_control =
                    fill_generation_limit(COACHES_DISTRIBUITON, c_people_count);
            });

            return choose_random_countries_for_tier(s_coaches_generator_configs,
                                                    s_generation_limit_control,
                                                    c_people_count);
        }
        else
        {
            return {country_code::brazil, 70};
        }
    }
} // namespace vp::utility