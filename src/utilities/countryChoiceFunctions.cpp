#include "countryChoiceFunctions.hpp"

#include "pch.h"

namespace vp::utility
{
    std::vector<country_code> players_get_countries_by_ranking_range(
        std::vector<country_code> sorted_player_countries_vector,
        int begin_index, int end_index,
        std::vector<country_code> countries_to_draw, int tier_player)
    {
        int countries_limit_vector{0};
        int number_countries_vector{0};
        country_code random_country{};

        for (begin_index; begin_index < end_index; begin_index++)
        {
            do
            {
                random_country = countries_to_draw.at(
                    effolkronium::random_thread_local::get<std::size_t>(
                        0, countries_to_draw.size() - 1));
                countries_limit_vector =
                    (int)std::round(sorted_player_countries_vector.size() *
                                    players_distribution.at(random_country));
                number_countries_vector = (int)std::count(
                    sorted_player_countries_vector.begin(),
                    sorted_player_countries_vector.end(), random_country);

            } while (countries_limit_vector <= number_countries_vector);

            sorted_player_countries_vector.at(begin_index) = random_country;
            sorted_player_countries_vector.at(
                begin_index + (sorted_player_countries_vector.size() / 2)) =
                (country_code)tier_player; // FIX!
        }

        return sorted_player_countries_vector;
    }

    std::vector<country_code> players_countries_sort_by_skill_level(
        const std::size_t c_players_count)
    {
        std::vector<country_code> sorted_player_countries_vector(
            c_players_count * 2);

        int begin_index = 0;
        int end_index = (int)std::round(
            c_players_count * 0.00184); // tier 1 = define 2 highest overall for
                                        // 1080 players or 180 teams
        std::vector<country_code> available_countries_for_tier = {
            country_code::Sweden, country_code::Sweden,  country_code::France,
            country_code::France, country_code::Ukraine, country_code::Ukraine,
            country_code::Brazil, country_code::Brazil,  country_code::Denmark,
            country_code::Bosnia, country_code::Slovakia};

        sorted_player_countries_vector = players_get_countries_by_ranking_range(
            sorted_player_countries_vector, begin_index, end_index,
            available_countries_for_tier, 100);

        begin_index = end_index;
        end_index += (int)std::round(
            c_players_count *
            0.00278); // tier 1 = define 3-5 for 1080 players or 180 teams
        available_countries_for_tier = {
            country_code::Russia,  country_code::Russia,
            country_code::Russia,  country_code::Denmark,
            country_code::Denmark, country_code::Denmark,
            country_code::Bosnia,  country_code::Bosnia,
            country_code::Poland,  country_code::Poland,
            country_code::Sweden,  country_code::France,
            country_code::Ukraine, country_code::Brazil,
            country_code::Norway,  country_code::United_States};
        sorted_player_countries_vector = players_get_countries_by_ranking_range(
            sorted_player_countries_vector, begin_index, end_index,
            available_countries_for_tier, 200);

        begin_index = end_index;
        end_index += (int)std::round(
            c_players_count *
            0.00463); // tier 1 = define 6-10 for 1080 players or 180 teams
        available_countries_for_tier = {
            country_code::Sweden,        country_code::Sweden,
            country_code::Sweden,        country_code::France,
            country_code::France,        country_code::France,
            country_code::Denmark,       country_code::Denmark,
            country_code::Russia,        country_code::Russia,
            country_code::Ukraine,       country_code::Brazil,
            country_code::United_States, country_code::Slovakia,
            country_code::Canada,        country_code::Latvia,
            country_code::Estonia,       country_code::Kazakhstan,
            country_code::Belgium,       country_code::Germany};
        sorted_player_countries_vector = players_get_countries_by_ranking_range(
            sorted_player_countries_vector, begin_index, end_index,
            available_countries_for_tier, 300);

        begin_index = end_index;
        end_index += (int)std::round(
            c_players_count *
            0.00927); // tier 1 = define 11 - 20 for 1080 players or 180 teams
        available_countries_for_tier = {
            country_code::Denmark,        country_code::Denmark,
            country_code::Denmark,        country_code::Sweden,
            country_code::Sweden,         country_code::Sweden,
            country_code::France,         country_code::France,
            country_code::Brazil,         country_code::Brazil,
            country_code::Bosnia,         country_code::Bosnia,
            country_code::United_States,  country_code::United_States,
            country_code::Russia,         country_code::Ukraine,
            country_code::Poland,         country_code::Slovakia,
            country_code::Canada,         country_code::Latvia,
            country_code::Estonia,        country_code::Norway,
            country_code::Kazakhstan,     country_code::Finland,
            country_code::Israel,         country_code::Australia,
            country_code::Czech_Republic, country_code::Turkey,
            country_code::Bulgaria};
        sorted_player_countries_vector = players_get_countries_by_ranking_range(
            sorted_player_countries_vector, begin_index, end_index,
            available_countries_for_tier, 400);

        begin_index = end_index;
        end_index += (int)std::round(
            c_players_count *
            0.02778); // tier 1 = define 21 - 50 for 1080 players or 180 teams
        available_countries_for_tier = {
            country_code::Denmark,       country_code::Sweden,
            country_code::France,        country_code::Russia,
            country_code::Ukraine,       country_code::Brazil,
            country_code::Bosnia,        country_code::Poland,
            country_code::United_States, country_code::Slovakia,
            country_code::Canada,        country_code::Latvia,
            country_code::Estonia,       country_code::Norway,
            country_code::Kazakhstan,    country_code::Israel,
            country_code::Australia,     country_code::Czech_Republic,
            country_code::Germany,       country_code::United_Kingdom,
            country_code::Hungary,       country_code::Netherlands,
            country_code::Serbia};
        sorted_player_countries_vector = players_get_countries_by_ranking_range(
            sorted_player_countries_vector, begin_index, end_index,
            available_countries_for_tier, 500);

        begin_index = end_index;
        end_index += (int)std::round(
            c_players_count *
            0.09261); // tier 2 = define 51 - 150 for 1080 players or 180 teams
        available_countries_for_tier = {
            country_code::Argentina,
            country_code::Australia,
            country_code::Brazil,
            country_code::Czech_Republic,
            country_code::Denmark,
            country_code::Finland,
            country_code::France,
            country_code::Germany,
            country_code::Mongolia,
            country_code::Poland,
            country_code::Portugal,
            country_code::Russia,
            country_code::Sweden,
            country_code::Turkey,
            country_code::Ukraine,
            country_code::United_Kingdom,
            country_code::United_States,
            country_code::Belgium,
            country_code::Bosnia,
            country_code::Bulgaria,
            country_code::Canada,
            country_code::Chile,
            country_code::Estonia,
            country_code::Hungary,
            country_code::Israel,
            country_code::Kazakhstan,
            country_code::Kosovo,
            country_code::Latvia,
            country_code::Montenegro,
            country_code::Netherlands,
            country_code::Norway,
            country_code::Romania,
            country_code::Serbia,
            country_code::Slovakia,
            country_code::South_Africa,
            country_code::Spain,
            country_code::Switzerland,
            country_code::Uruguay}; // whitout China, Mexico and
                                    // New Zealand
        sorted_player_countries_vector = players_get_countries_by_ranking_range(
            sorted_player_countries_vector, begin_index, end_index,
            available_countries_for_tier, 600);

        begin_index = end_index;
        end_index += (int)std::round(
            c_players_count *
            0.46295); // tier 3 = define 151 - 650 for 1080 players or 180 teams
        available_countries_for_tier = {
            country_code::Argentina,      country_code::Australia,
            country_code::Brazil,         country_code::China,
            country_code::Czech_Republic, country_code::Denmark,
            country_code::Finland,        country_code::France,
            country_code::Germany,        country_code::Mongolia,
            country_code::Poland,         country_code::Portugal,
            country_code::Russia,         country_code::Sweden,
            country_code::Turkey,         country_code::Ukraine,
            country_code::United_Kingdom, country_code::United_States,
            country_code::Belgium,        country_code::Bosnia,
            country_code::Bulgaria,       country_code::Canada,
            country_code::Chile,          country_code::Estonia,
            country_code::Hungary,        country_code::Israel,
            country_code::Kazakhstan,     country_code::Kosovo,
            country_code::Latvia,         country_code::Mexico,
            country_code::Montenegro,     country_code::Netherlands,
            country_code::New_Zealand,    country_code::Norway,
            country_code::Romania,        country_code::Serbia,
            country_code::Slovakia,       country_code::South_Africa,
            country_code::Spain,          country_code::Switzerland,
            country_code::Uruguay};
        sorted_player_countries_vector = players_get_countries_by_ranking_range(
            sorted_player_countries_vector, begin_index, end_index,
            available_countries_for_tier, 700);

        begin_index = end_index;
        end_index += (int)std::round(
            c_players_count *
            0.23148); // tier 4 = define 651 - 900 for 1080 players or 180 teams
        sorted_player_countries_vector = players_get_countries_by_ranking_range(
            sorted_player_countries_vector, begin_index, end_index,
            available_countries_for_tier, 800);

        begin_index = end_index;
        end_index = c_players_count; // tier 5 = define 901 - 1080 for 1080
                                     // players or 180 teams
        sorted_player_countries_vector = players_get_countries_by_ranking_range(
            sorted_player_countries_vector, begin_index, end_index,
            available_countries_for_tier, 900);

        return sorted_player_countries_vector;
    }
} // namespace vp::utility