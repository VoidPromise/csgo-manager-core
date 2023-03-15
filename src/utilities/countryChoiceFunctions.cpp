#include "countrychoicefunctions.hpp"

#include "countryenum.hpp"
#include "pch.h"

namespace vp::utility
{
    std::uint8_t tier_get_skill_level(const char& tier)
    {
        switch (tier)
        {
        case 'a':
            return effolkronium::random_thread_local::get<int>(95, 100);
        case 'b':
            return effolkronium::random_thread_local::get<int>(92, 96);
        case 'c':
            return effolkronium::random_thread_local::get<int>(89, 93);
        case 'd':
            return effolkronium::random_thread_local::get<int>(85, 90);
        case 'e':
            return effolkronium::random_thread_local::get<int>(82, 87);
        case 'f':
            return effolkronium::random_thread_local::get<int>(78, 84);
        case 'g':
            return effolkronium::random_thread_local::get<int>(69, 80);
        case 'h':
            return effolkronium::random_thread_local::get<int>(64, 72);
        case 'i':
            return effolkronium::random_thread_local::get<int>(55, 67);
        default:
            return 0;
        }
    }

    void choose_random_countries_for_tier(
        std::vector<country_skill_level>& sorted_countries_tiers_vector,
        int& begin_index, const int& c_end_index,
        const std::vector<country_code>& c_countries_to_draw,
        const char& c_tier_player)
    {
        int countries_limit_vector{0};
        int number_countries_vector{0};
        country_code random_country{};

        for (; begin_index < c_end_index; begin_index++)
        {
            do
            {
                random_country = c_countries_to_draw.at(
                    effolkronium::random_thread_local::get<std::size_t>(
                        0, c_countries_to_draw.size() - 1));
                countries_limit_vector =
                    (int)std::round((int)sorted_countries_tiers_vector.size() *
                                    PLAYERS_DISTRIBUTION.at(random_country));
                number_countries_vector = (int)std::count(
                    sorted_countries_tiers_vector.begin(),
                    sorted_countries_tiers_vector.end(), random_country);

            } while (countries_limit_vector <= number_countries_vector);

            sorted_countries_tiers_vector.at(begin_index)._country =
                random_country;
            sorted_countries_tiers_vector.at(begin_index)._skill_level =
                tier_get_skill_level(c_tier_player);
        }
    }

    std::vector<country_skill_level> vector_countries_and_tiers_for_players(
        const int c_players_count)
    {
        std::vector<country_skill_level> sorted_player_countries_vector{
            (std::size_t)c_players_count};
        int begin_index = 0;
        int end_index = (int)std::round(
            c_players_count * 0.00184); // tier 1 = define 2 highest overall for
                                        // 1080 players or 180 teams
        std::vector<country_code> available_countries_for_tier = {
            country_code::sweden, country_code::sweden,  country_code::france,
            country_code::france, country_code::ukraine, country_code::ukraine,
            country_code::brazil, country_code::brazil,  country_code::denmark,
            country_code::bosnia, country_code::slovakia};
        choose_random_countries_for_tier(sorted_player_countries_vector,
                                         begin_index, end_index,
                                         available_countries_for_tier, 'a');
        begin_index++;
        end_index += (int)std::round(
            c_players_count *
            0.00278); // tier 1 = define 3-5 for 1080 players or 180 teams
        available_countries_for_tier = {
            country_code::russia,  country_code::russia,
            country_code::russia,  country_code::denmark,
            country_code::denmark, country_code::denmark,
            country_code::bosnia,  country_code::bosnia,
            country_code::poland,  country_code::poland,
            country_code::sweden,  country_code::france,
            country_code::ukraine, country_code::brazil,
            country_code::norway,  country_code::united_states};
        choose_random_countries_for_tier(sorted_player_countries_vector,
                                         begin_index, end_index,
                                         available_countries_for_tier, 'b');
        begin_index++;
        end_index += (int)std::round(
            c_players_count *
            0.00463); // tier 1 = define 6-10 for 1080 players or 180 teams
        available_countries_for_tier = {
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
        choose_random_countries_for_tier(sorted_player_countries_vector,
                                         begin_index, end_index,
                                         available_countries_for_tier, 'c');
        begin_index++;
        end_index += (int)std::round(
            c_players_count *
            0.00927); // tier 1 = define 11 - 20 for 1080 players or 180 teams
        available_countries_for_tier = {
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
        choose_random_countries_for_tier(sorted_player_countries_vector,
                                         begin_index, end_index,
                                         available_countries_for_tier, 'd');
        begin_index++;
        end_index += (int)std::round(
            c_players_count *
            0.02778); // tier 1 = define 21 - 50 for 1080 players or 180 teams
        available_countries_for_tier = {
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
        choose_random_countries_for_tier(sorted_player_countries_vector,
                                         begin_index, end_index,
                                         available_countries_for_tier, 'e');
        begin_index++;
        end_index += (int)std::round(
            c_players_count *
            0.09261); // tier 2 = define 51 - 150 for 1080 players or 180 teams
        available_countries_for_tier = {
            country_code::argentina,
            country_code::australia,
            country_code::brazil,
            country_code::czech_republic,
            country_code::denmark,
            country_code::finland,
            country_code::france,
            country_code::germany,
            country_code::mongolia,
            country_code::poland,
            country_code::portugal,
            country_code::russia,
            country_code::sweden,
            country_code::turkey,
            country_code::ukraine,
            country_code::united_kingdom,
            country_code::united_states,
            country_code::belgium,
            country_code::bosnia,
            country_code::bulgaria,
            country_code::canada,
            country_code::chile,
            country_code::estonia,
            country_code::hungary,
            country_code::israel,
            country_code::kazakhstan,
            country_code::kosovo,
            country_code::latvia,
            country_code::montenegro,
            country_code::netherlands,
            country_code::norway,
            country_code::romania,
            country_code::serbia,
            country_code::slovakia,
            country_code::south_africa,
            country_code::spain,
            country_code::switzerland,
            country_code::uruguay}; // whitout china, mexico and
                                    // New Zealand
        choose_random_countries_for_tier(sorted_player_countries_vector,
                                         begin_index, end_index,
                                         available_countries_for_tier, 'f');
        begin_index++;
        end_index += (int)std::round(
            c_players_count *
            0.46295); // tier 3 = define 151 - 650 for 1080 players or 180 teams
        available_countries_for_tier = {
            country_code::argentina,      country_code::australia,
            country_code::brazil,         country_code::china,
            country_code::czech_republic, country_code::denmark,
            country_code::finland,        country_code::france,
            country_code::germany,        country_code::mongolia,
            country_code::poland,         country_code::portugal,
            country_code::russia,         country_code::sweden,
            country_code::turkey,         country_code::ukraine,
            country_code::united_kingdom, country_code::united_states,
            country_code::belgium,        country_code::bosnia,
            country_code::bulgaria,       country_code::canada,
            country_code::chile,          country_code::estonia,
            country_code::hungary,        country_code::israel,
            country_code::kazakhstan,     country_code::kosovo,
            country_code::latvia,         country_code::mexico,
            country_code::montenegro,     country_code::netherlands,
            country_code::new_zealand,    country_code::norway,
            country_code::romania,        country_code::serbia,
            country_code::slovakia,       country_code::south_africa,
            country_code::spain,          country_code::switzerland,
            country_code::uruguay};
        choose_random_countries_for_tier(sorted_player_countries_vector,
                                         begin_index, end_index,
                                         available_countries_for_tier, 'g');
        begin_index++;
        end_index += (int)std::round(
            c_players_count *
            0.23148); // tier 4 = define 651 - 900 for 1080 players or 180 teams
        choose_random_countries_for_tier(sorted_player_countries_vector,
                                         begin_index, end_index,
                                         available_countries_for_tier, 'h');
        begin_index++;
        end_index = c_players_count; // tier 5 = define 901 - 1080 for 1080
                                     // players or 180 teams
        choose_random_countries_for_tier(sorted_player_countries_vector,
                                         begin_index, end_index,
                                         available_countries_for_tier, 'i');
        return sorted_player_countries_vector;
    }
} // namespace vp::utility