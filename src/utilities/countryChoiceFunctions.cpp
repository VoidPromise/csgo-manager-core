#include "countrychoicefunctions.hpp"

#include "countryenum.hpp"
#include "pch.h"

namespace vp::utility
{
    std::vector<country_and_skill_level_limit_settings>
    set_settings_to_generate_players()
    {
        static const std::map<country_code, double> c_players_distribuiton{
            {country_code::argentina, 0.0322},
            {country_code::australia, 0.0456},
            {country_code::brazil, 0.0972},
            {country_code::china, 0.0231},
            {country_code::czech_republic, 0.0186},
            {country_code::denmark, 0.0722},
            {country_code::finland, 0.0309},
            {country_code::france, 0.0258},
            {country_code::germany, 0.0267},
            {country_code::mongolia, 0.0263},
            {country_code::poland, 0.0644},
            {country_code::portugal, 0.0276},
            {country_code::russia, 0.0733},
            {country_code::sweden, 0.0423},
            {country_code::turkey, 0.0204},
            {country_code::ukraine, 0.0332},
            {country_code::united_kingdom, 0.0267},
            {country_code::united_states, 0.0782},
            {country_code::belgium, 0.0093},
            {country_code::bosnia, 0.0093},
            {country_code::bulgaria, 0.0111},
            {country_code::canada, 0.0166},
            {country_code::chile, 0.0093},
            {country_code::estonia, 0.0093},
            {country_code::hungary, 0.0093},
            {country_code::israel, 0.0093},
            {country_code::kazakhstan, 0.0137},
            {country_code::kosovo, 0.0101},
            {country_code::latvia, 0.0093},
            {country_code::mexico, 0.0093},
            {country_code::montenegro, 0.0093},
            {country_code::netherlands, 0.0093},
            {country_code::new_zealand, 0.0147},
            {country_code::norway, 0.0093},
            {country_code::romania, 0.0111},
            {country_code::serbia, 0.0101},
            {country_code::slovakia, 0.0111},
            {country_code::south_africa, 0.0128},
            {country_code::spain, 0.0137},
            {country_code::switzerland, 0.0093},
            {country_code::uruguay, 0.0093}};

        std::vector<country_and_skill_level_limit_settings> configs{9};

        configs.at(0)._distribuition_tier = 0.00184;
        configs.at(0)._begin_range = 95;
        configs.at(0)._end_range = 100;
        configs.at(0)._people_distribuiton = c_players_distribuiton;
        configs.at(0)._countries_to_draw = {
            country_code::sweden, country_code::sweden,  country_code::france,
            country_code::france, country_code::ukraine, country_code::ukraine,
            country_code::brazil, country_code::brazil,  country_code::denmark,
            country_code::bosnia, country_code::slovakia};

        configs.at(1)._distribuition_tier = 0.00278;
        configs.at(1)._begin_range = 89;
        configs.at(1)._end_range = 93;
        configs.at(1)._people_distribuiton = c_players_distribuiton;
        configs.at(1)._countries_to_draw = {
            country_code::russia,  country_code::russia,
            country_code::russia,  country_code::denmark,
            country_code::denmark, country_code::denmark,
            country_code::bosnia,  country_code::bosnia,
            country_code::poland,  country_code::poland,
            country_code::sweden,  country_code::france,
            country_code::ukraine, country_code::brazil,
            country_code::norway,  country_code::united_states};

        configs.at(2)._distribuition_tier = 0.00463;
        configs.at(2)._begin_range = 92;
        configs.at(2)._end_range = 96;
        configs.at(2)._people_distribuiton = c_players_distribuiton;
        configs.at(2)._countries_to_draw = {
            country_code::sweden,        country_code::sweden,
            country_code::sweden,        country_code::france,
            country_code::france,        country_code::france,
            country_code::denmark,       country_code::denmark,
            country_code::russia,        country_code::russia,
            country_code::ukraine,       country_code::brazil,
            country_code::united_states, country_code::slovakia,
            country_code::canada,        country_code::latvia,
            country_code::estonia,       country_code::kazakhstan,
            country_code::belgium,       country_code::germany};

        configs.at(3)._distribuition_tier = 0.00927;
        configs.at(3)._begin_range = 85;
        configs.at(3)._end_range = 90;
        configs.at(3)._people_distribuiton = c_players_distribuiton;
        configs.at(3)._countries_to_draw = {
            country_code::denmark,        country_code::denmark,
            country_code::denmark,        country_code::sweden,
            country_code::sweden,         country_code::sweden,
            country_code::france,         country_code::france,
            country_code::brazil,         country_code::brazil,
            country_code::bosnia,         country_code::bosnia,
            country_code::united_states,  country_code::united_states,
            country_code::russia,         country_code::ukraine,
            country_code::poland,         country_code::slovakia,
            country_code::canada,         country_code::latvia,
            country_code::estonia,        country_code::norway,
            country_code::kazakhstan,     country_code::finland,
            country_code::israel,         country_code::australia,
            country_code::czech_republic, country_code::turkey,
            country_code::bulgaria};

        configs.at(4)._distribuition_tier = 0.02778;
        configs.at(4)._begin_range = 82;
        configs.at(4)._end_range = 87;
        configs.at(4)._people_distribuiton = c_players_distribuiton;
        configs.at(4)._countries_to_draw = {
            country_code::denmark,       country_code::sweden,
            country_code::france,        country_code::russia,
            country_code::ukraine,       country_code::brazil,
            country_code::bosnia,        country_code::poland,
            country_code::united_states, country_code::slovakia,
            country_code::canada,        country_code::latvia,
            country_code::estonia,       country_code::norway,
            country_code::kazakhstan,    country_code::israel,
            country_code::australia,     country_code::czech_republic,
            country_code::germany,       country_code::united_kingdom,
            country_code::hungary,       country_code::netherlands,
            country_code::serbia};

        configs.at(5)._distribuition_tier = 0.09261;
        configs.at(5)._begin_range = 78;
        configs.at(5)._end_range = 84;
        configs.at(5)._people_distribuiton = c_players_distribuiton;
        configs.at(5)._countries_to_draw = {
            country_code::argentina,     country_code::australia,
            country_code::brazil,        country_code::czech_republic,
            country_code::denmark,       country_code::finland,
            country_code::france,        country_code::germany,
            country_code::mongolia,      country_code::poland,
            country_code::portugal,      country_code::russia,
            country_code::sweden,        country_code::turkey,
            country_code::ukraine,       country_code::united_kingdom,
            country_code::united_states, country_code::belgium,
            country_code::bosnia,        country_code::bulgaria,
            country_code::canada,        country_code::chile,
            country_code::estonia,       country_code::hungary,
            country_code::israel,        country_code::kazakhstan,
            country_code::kosovo,        country_code::latvia,
            country_code::montenegro,    country_code::netherlands,
            country_code::norway,        country_code::romania,
            country_code::serbia,        country_code::slovakia,
            country_code::south_africa,  country_code::spain,
            country_code::switzerland,   country_code::uruguay};

        configs.at(6)._distribuition_tier = 0.46295;
        configs.at(6)._begin_range = 69;
        configs.at(6)._end_range = 80;
        configs.at(6)._people_distribuiton = c_players_distribuiton;
        configs.at(6)._countries_to_draw = {
            magic_enum::enum_values<country_code>().cbegin(),
            magic_enum::enum_values<country_code>().cend()};

        configs.at(7)._distribuition_tier = 0.23148;
        configs.at(7)._begin_range = 64;
        configs.at(7)._end_range = 72;
        configs.at(7)._people_distribuiton = c_players_distribuiton;
        configs.at(7)._countries_to_draw = {
            magic_enum::enum_values<country_code>().cbegin(),
            magic_enum::enum_values<country_code>().cend()};

        configs.at(8)._distribuition_tier = 1;
        configs.at(8)._begin_range = 55;
        configs.at(8)._end_range = 67;
        configs.at(8)._people_distribuiton = c_players_distribuiton;
        configs.at(8)._countries_to_draw = {
            magic_enum::enum_values<country_code>().cbegin(),
            magic_enum::enum_values<country_code>().cend()};

        return configs;
    }

    std::vector<country_and_skill_level_limit_settings>
    set_settings_to_generate_coaches()
    {
        std::vector<country_and_skill_level_limit_settings> configs{5};

        static const std::map<country_code, double> c_coaches_distribuiton{
            {country_code::argentina, 0.028},
            {country_code::australia, 0.042},
            {country_code::brazil, 0.109},
            {country_code::china, 0.020},
            {country_code::czech_republic, 0.020},
            {country_code::denmark, 0.086},
            {country_code::finland, 0.029},
            {country_code::france, 0.030},
            {country_code::germany, 0.029},
            {country_code::mongolia, 0.023},
            {country_code::poland, 0.064},
            {country_code::portugal, 0.023},
            {country_code::russia, 0.085},
            {country_code::sweden, 0.048},
            {country_code::turkey, 0.020},
            {country_code::ukraine, 0.035},
            {country_code::united_kingdom, 0.023},
            {country_code::united_states, 0.088},
            {country_code::belgium, 0.010},
            {country_code::bosnia, 0.011},
            {country_code::bulgaria, 0.011},
            {country_code::canada, 0.015},
            {country_code::chile, 0.010},
            {country_code::estonia, 0.011},
            {country_code::hungary, 0.011},
            {country_code::israel, 0.011},
            {country_code::kazakhstan, 0.015},
            {country_code::kosovo, 0.010},
            {country_code::latvia, 0.011},
            {country_code::mexico, 0.010},
            {country_code::montenegro, 0.011},
            {country_code::netherlands, 0.010},
            {country_code::new_zealand, 0.010},
            {country_code::norway, 0.011},
            {country_code::romania, 0.011},
            {country_code::serbia, 0.011},
            {country_code::slovakia, 0.011},
            {country_code::south_africa, 0.010},
            {country_code::spain, 0.011},
            {country_code::switzerland, 0.010},
            {country_code::uruguay, 0.010}};

        configs.at(0)._distribuition_tier = 0.047;
        configs.at(0)._begin_range = 82;
        configs.at(0)._end_range = 100;
        configs.at(0)._people_distribuiton = c_coaches_distribuiton;
        configs.at(0)._countries_to_draw = {
            country_code::australia,      country_code::brazil,
            country_code::czech_republic, country_code::denmark,
            country_code::finland,        country_code::france,
            country_code::germany,        country_code::poland,
            country_code::russia,         country_code::sweden,
            country_code::turkey,         country_code::ukraine,
            country_code::united_kingdom, country_code::united_states,
            country_code::belgium,        country_code::bosnia,
            country_code::bulgaria,       country_code::canada,
            country_code::estonia,        country_code::hungary,
            country_code::israel,         country_code::kazakhstan,
            country_code::latvia,         country_code::netherlands,
            country_code::norway,         country_code::serbia,
            country_code::slovakia};

        configs.at(1)._distribuition_tier = 0.094;
        configs.at(1)._begin_range = 78;
        configs.at(1)._end_range = 84;
        configs.at(1)._people_distribuiton = c_coaches_distribuiton;
        configs.at(1)._countries_to_draw = {
            country_code::argentina,     country_code::australia,
            country_code::brazil,        country_code::czech_republic,
            country_code::denmark,       country_code::finland,
            country_code::france,        country_code::germany,
            country_code::mongolia,      country_code::poland,
            country_code::portugal,      country_code::russia,
            country_code::sweden,        country_code::turkey,
            country_code::ukraine,       country_code::united_kingdom,
            country_code::united_states, country_code::belgium,
            country_code::bosnia,        country_code::bulgaria,
            country_code::canada,        country_code::chile,
            country_code::estonia,       country_code::hungary,
            country_code::israel,        country_code::kazakhstan,
            country_code::kosovo,        country_code::latvia,
            country_code::montenegro,    country_code::netherlands,
            country_code::norway,        country_code::romania,
            country_code::serbia,        country_code::slovakia,
            country_code::south_africa,  country_code::spain,
            country_code::switzerland,   country_code::uruguay};

        configs.at(2)._distribuition_tier = 0.464;
        configs.at(2)._begin_range = 69;
        configs.at(2)._end_range = 80;
        configs.at(2)._people_distribuiton = c_coaches_distribuiton;
        configs.at(2)._countries_to_draw = {
            magic_enum::enum_values<country_code>().cbegin(),
            magic_enum::enum_values<country_code>().cend()};

        configs.at(3)._distribuition_tier = 0.232;
        configs.at(3)._begin_range = 64;
        configs.at(3)._end_range = 72;
        configs.at(3)._people_distribuiton = c_coaches_distribuiton;
        configs.at(3)._countries_to_draw = {
            magic_enum::enum_values<country_code>().cbegin(),
            magic_enum::enum_values<country_code>().cend()};

        configs.at(4)._distribuition_tier = 1;
        configs.at(4)._begin_range = 55;
        configs.at(4)._end_range = 67;
        configs.at(4)._people_distribuiton = c_coaches_distribuiton;
        configs.at(4)._countries_to_draw = {
            magic_enum::enum_values<country_code>().cbegin(),
            magic_enum::enum_values<country_code>().cend()};

        return configs;
    }

    void choose_random_countries_for_tier(
        std::vector<country_skill_level>& sorted_countries_tiers_vector,
        country_and_skill_level_limit_settings& configs)
    {
        country_code random_country{};

        static std::vector<country_skill_level>::iterator s_it_begin{};

        static std::map<country_code, std::size_t> s_person_count{};

        static std::map<country_code, std::size_t> s_person_limit{};

        static std::vector<country_code> s_blacklisted_countries{};

        static std::once_flag s_flag{};

        std::call_once(s_flag, [&sorted_countries_tiers_vector, &configs]() {
            std::transform(magic_enum::enum_values<country_code>().cbegin(),
                           magic_enum::enum_values<country_code>().cend(),
                           std::inserter(s_person_count, s_person_count.end()),
                           [](const country_code& c_country) {
                               return std::make_pair(c_country, 0);
                           });
            std::transform(
                magic_enum::enum_values<country_code>().cbegin(),
                magic_enum::enum_values<country_code>().cend(),
                std::inserter(s_person_limit, s_person_limit.end()),
                [&sorted_countries_tiers_vector,
                 &configs](const country_code& c_country) {
                    return std::make_pair(
                        c_country,
                        static_cast<std::size_t>(std::lround(
                            sorted_countries_tiers_vector.size() *
                            configs._people_distribuiton.at(c_country))));
                });
            s_it_begin = sorted_countries_tiers_vector.begin();
        });

        const std::vector<country_skill_level>::iterator c_it_end =
            s_it_begin + std::lround(sorted_countries_tiers_vector.size() *
                                     configs._distribuition_tier);

        std::for_each(
            s_blacklisted_countries.begin(), s_blacklisted_countries.end(),
            [&configs](country_code& country_to_erase) {
                std::erase(configs._countries_to_draw, country_to_erase);
            });

        std::for_each(
            s_it_begin, c_it_end - 1,
            [&random_country,
             &configs](country_skill_level& country_skill_level) {
                random_country = *effolkronium::random_thread_local::get(
                    configs._countries_to_draw.cbegin(),
                    configs._countries_to_draw.cend());
                country_skill_level._country = random_country;
                country_skill_level._skill_level =
                    effolkronium::random_thread_local::get<std::size_t>(
                        configs._begin_range, configs._end_range);

                s_person_count.at(random_country)++;

                if (s_person_count.at(random_country) ==
                    s_person_limit.at(random_country))
                {
                    s_blacklisted_countries.push_back(random_country);
                    std::erase(configs._countries_to_draw, random_country);
                }
            });
        s_it_begin = c_it_end;
    }

    std::vector<country_skill_level> vector_countries_and_tiers_for_players(
        const std::size_t c_players_count)
    {
        std::vector<country_skill_level> sorted_player_countries_vector{
            c_players_count};
        std::vector<country_and_skill_level_limit_settings>
            settings_to_generate = set_settings_to_generate_players();

        std::for_each(settings_to_generate.begin(), settings_to_generate.end(),
                      [&sorted_player_countries_vector](
                          country_and_skill_level_limit_settings& c_setting) {
                          choose_random_countries_for_tier(
                              sorted_player_countries_vector, c_setting);
                      });

        return sorted_player_countries_vector;
    }

    std::vector<country_skill_level> vector_countries_and_tiers_for_coaches(
        const std::size_t c_coaches_count)
    {
        std::vector<country_skill_level> sorted_coach_countries_vector{
            c_coaches_count};
        std::vector<country_and_skill_level_limit_settings>
            settings_to_generate = set_settings_to_generate_coaches();

        std::for_each(settings_to_generate.begin(), settings_to_generate.end(),
                      [&sorted_coach_countries_vector](
                          country_and_skill_level_limit_settings& c_setting) {
                          choose_random_countries_for_tier(
                              sorted_coach_countries_vector, c_setting);
                      });

        return sorted_coach_countries_vector;
    }
} // namespace vp::utility