#include "countryChoiceFunctions.hpp"
#include "pch.h"

namespace vp::utility
{
    std::vector<int> playersGetCountriesByRankingRange(
        std::vector<int> sortedPlayerCountriesVector, int beginIndex,
        int endIndex, std::vector<availableCountries> countriesToDraw,
        int tierPlayer)
    {
        int countriesLimitVector = 0;
        int numberCountriesVector = 0;
        availableCountries randomCountry;

        for (beginIndex; beginIndex < endIndex; beginIndex++)
        {
            do
            {
                randomCountry = countriesToDraw.at(
                    effolkronium::random_thread_local::get<std::size_t>(
                        0, countriesToDraw.size() - 1));
                countriesLimitVector = (int)std::round(
                    sortedPlayerCountriesVector.size() *
                    playersCountryDistribution.at(randomCountry));
                numberCountriesVector =
                    (int)std::count(sortedPlayerCountriesVector.begin(),
                                    sortedPlayerCountriesVector.end(),
                                    magic_enum::enum_integer(randomCountry));

            } while (countriesLimitVector <= numberCountriesVector);

            sortedPlayerCountriesVector.at(beginIndex) =
                magic_enum::enum_integer(randomCountry);
            sortedPlayerCountriesVector.at(
                beginIndex + (sortedPlayerCountriesVector.size() / 2)) =
                tierPlayer;
        }

        return sortedPlayerCountriesVector;
    }

    std::vector<int> playersCountriesSortBySkillLevel(const int numPlayers)
    {
        std::vector<int> sortedPlayerCountriesVector(numPlayers * 2);

        int beginIndex = 0;
        int endIndex = (int)std::round(
            numPlayers * 0.00184); // tier 1 = define 2 highest overall for 1080
                                   // players or 180 teams
        std::vector<availableCountries> availableCountriesForTier = {
            availableCountries::Sweden,  availableCountries::Sweden,
            availableCountries::France,  availableCountries::France,
            availableCountries::Ukraine, availableCountries::Ukraine,
            availableCountries::Brazil,  availableCountries::Brazil,
            availableCountries::Denmark, availableCountries::Bosnia,
            availableCountries::Slovakia};
        sortedPlayerCountriesVector = playersGetCountriesByRankingRange(
            sortedPlayerCountriesVector, beginIndex, endIndex,
            availableCountriesForTier, 100);

        beginIndex = endIndex;
        endIndex += (int)std::round(
            numPlayers *
            0.00278); // tier 1 = define 3-5 for 1080 players or 180 teams
        availableCountriesForTier = {
            availableCountries::Russia,  availableCountries::Russia,
            availableCountries::Russia,  availableCountries::Denmark,
            availableCountries::Denmark, availableCountries::Denmark,
            availableCountries::Bosnia,  availableCountries::Bosnia,
            availableCountries::Poland,  availableCountries::Poland,
            availableCountries::Sweden,  availableCountries::France,
            availableCountries::Ukraine, availableCountries::Brazil,
            availableCountries::Norway,  availableCountries::United_States};
        sortedPlayerCountriesVector = playersGetCountriesByRankingRange(
            sortedPlayerCountriesVector, beginIndex, endIndex,
            availableCountriesForTier, 200);

        beginIndex = endIndex;
        endIndex += (int)std::round(
            numPlayers *
            0.00463); // tier 1 = define 6-10 for 1080 players or 180 teams
        availableCountriesForTier = {
            availableCountries::Sweden,        availableCountries::Sweden,
            availableCountries::Sweden,        availableCountries::France,
            availableCountries::France,        availableCountries::France,
            availableCountries::Denmark,       availableCountries::Denmark,
            availableCountries::Russia,        availableCountries::Russia,
            availableCountries::Ukraine,       availableCountries::Brazil,
            availableCountries::United_States, availableCountries::Slovakia,
            availableCountries::Canada,        availableCountries::Latvia,
            availableCountries::Estonia,       availableCountries::Kazakhstan,
            availableCountries::Belgium,       availableCountries::Germany};
        sortedPlayerCountriesVector = playersGetCountriesByRankingRange(
            sortedPlayerCountriesVector, beginIndex, endIndex,
            availableCountriesForTier, 300);

        beginIndex = endIndex;
        endIndex += (int)std::round(
            numPlayers *
            0.00927); // tier 1 = define 11 - 20 for 1080 players or 180 teams
        availableCountriesForTier = {availableCountries::Denmark,
                                     availableCountries::Denmark,
                                     availableCountries::Denmark,
                                     availableCountries::Sweden,
                                     availableCountries::Sweden,
                                     availableCountries::Sweden,
                                     availableCountries::France,
                                     availableCountries::France,
                                     availableCountries::Brazil,
                                     availableCountries::Brazil,
                                     availableCountries::Bosnia,
                                     availableCountries::Bosnia,
                                     availableCountries::United_States,
                                     availableCountries::United_States,
                                     availableCountries::Russia,
                                     availableCountries::Ukraine,
                                     availableCountries::Poland,
                                     availableCountries::Slovakia,
                                     availableCountries::Canada,
                                     availableCountries::Latvia,
                                     availableCountries::Estonia,
                                     availableCountries::Norway,
                                     availableCountries::Kazakhstan,
                                     availableCountries::Finland,
                                     availableCountries::Israel,
                                     availableCountries::Australia,
                                     availableCountries::Czech_Republic,
                                     availableCountries::Turkey,
                                     availableCountries::Bulgaria};
        sortedPlayerCountriesVector = playersGetCountriesByRankingRange(
            sortedPlayerCountriesVector, beginIndex, endIndex,
            availableCountriesForTier, 400);

        beginIndex = endIndex;
        endIndex += (int)std::round(
            numPlayers *
            0.02778); // tier 1 = define 21 - 50 for 1080 players or 180 teams
        availableCountriesForTier = {availableCountries::Denmark,
                                     availableCountries::Sweden,
                                     availableCountries::France,
                                     availableCountries::Russia,
                                     availableCountries::Ukraine,
                                     availableCountries::Brazil,
                                     availableCountries::Bosnia,
                                     availableCountries::Poland,
                                     availableCountries::United_States,
                                     availableCountries::Slovakia,
                                     availableCountries::Canada,
                                     availableCountries::Latvia,
                                     availableCountries::Estonia,
                                     availableCountries::Norway,
                                     availableCountries::Kazakhstan,
                                     availableCountries::Israel,
                                     availableCountries::Australia,
                                     availableCountries::Czech_Republic,
                                     availableCountries::Germany,
                                     availableCountries::United_Kingdom,
                                     availableCountries::Hungary,
                                     availableCountries::Netherlands,
                                     availableCountries::Serbia};
        sortedPlayerCountriesVector = playersGetCountriesByRankingRange(
            sortedPlayerCountriesVector, beginIndex, endIndex,
            availableCountriesForTier, 500);

        beginIndex = endIndex;
        endIndex += (int)std::round(
            numPlayers *
            0.09261); // tier 2 = define 51 - 150 for 1080 players or 180 teams
        availableCountriesForTier = {
            availableCountries::Argentina,
            availableCountries::Australia,
            availableCountries::Brazil,
            availableCountries::Czech_Republic,
            availableCountries::Denmark,
            availableCountries::Finland,
            availableCountries::France,
            availableCountries::Germany,
            availableCountries::Mongolia,
            availableCountries::Poland,
            availableCountries::Portugal,
            availableCountries::Russia,
            availableCountries::Sweden,
            availableCountries::Turkey,
            availableCountries::Ukraine,
            availableCountries::United_Kingdom,
            availableCountries::United_States,
            availableCountries::Belgium,
            availableCountries::Bosnia,
            availableCountries::Bulgaria,
            availableCountries::Canada,
            availableCountries::Chile,
            availableCountries::Estonia,
            availableCountries::Hungary,
            availableCountries::Israel,
            availableCountries::Kazakhstan,
            availableCountries::Kosovo,
            availableCountries::Latvia,
            availableCountries::Montenegro,
            availableCountries::Netherlands,
            availableCountries::Norway,
            availableCountries::Romania,
            availableCountries::Serbia,
            availableCountries::Slovakia,
            availableCountries::South_Africa,
            availableCountries::Spain,
            availableCountries::Switzerland,
            availableCountries::Uruguay}; // whitout China, Mexico and
                                          // New Zealand
        sortedPlayerCountriesVector = playersGetCountriesByRankingRange(
            sortedPlayerCountriesVector, beginIndex, endIndex,
            availableCountriesForTier, 600);

        beginIndex = endIndex;
        endIndex += (int)std::round(
            numPlayers *
            0.46295); // tier 3 = define 151 - 650 for 1080 players or 180 teams
        availableCountriesForTier = {availableCountries::Argentina,
                                     availableCountries::Australia,
                                     availableCountries::Brazil,
                                     availableCountries::China,
                                     availableCountries::Czech_Republic,
                                     availableCountries::Denmark,
                                     availableCountries::Finland,
                                     availableCountries::France,
                                     availableCountries::Germany,
                                     availableCountries::Mongolia,
                                     availableCountries::Poland,
                                     availableCountries::Portugal,
                                     availableCountries::Russia,
                                     availableCountries::Sweden,
                                     availableCountries::Turkey,
                                     availableCountries::Ukraine,
                                     availableCountries::United_Kingdom,
                                     availableCountries::United_States,
                                     availableCountries::Belgium,
                                     availableCountries::Bosnia,
                                     availableCountries::Bulgaria,
                                     availableCountries::Canada,
                                     availableCountries::Chile,
                                     availableCountries::Estonia,
                                     availableCountries::Hungary,
                                     availableCountries::Israel,
                                     availableCountries::Kazakhstan,
                                     availableCountries::Kosovo,
                                     availableCountries::Latvia,
                                     availableCountries::Mexico,
                                     availableCountries::Montenegro,
                                     availableCountries::Netherlands,
                                     availableCountries::New_Zealand,
                                     availableCountries::Norway,
                                     availableCountries::Romania,
                                     availableCountries::Serbia,
                                     availableCountries::Slovakia,
                                     availableCountries::South_Africa,
                                     availableCountries::Spain,
                                     availableCountries::Switzerland,
                                     availableCountries::Uruguay};
        sortedPlayerCountriesVector = playersGetCountriesByRankingRange(
            sortedPlayerCountriesVector, beginIndex, endIndex,
            availableCountriesForTier, 700);

        beginIndex = endIndex;
        endIndex += (int)std::round(
            numPlayers *
            0.23148); // tier 4 = define 651 - 900 for 1080 players or 180 teams
        sortedPlayerCountriesVector = playersGetCountriesByRankingRange(
            sortedPlayerCountriesVector, beginIndex, endIndex,
            availableCountriesForTier, 800);

        beginIndex = endIndex;
        endIndex = numPlayers; // tier 5 = define 901 - 1080 for 1080 players or
                               // 180 teams
        sortedPlayerCountriesVector = playersGetCountriesByRankingRange(
            sortedPlayerCountriesVector, beginIndex, endIndex,
            availableCountriesForTier, 900);

        return sortedPlayerCountriesVector;
    }
} // namespace vp::utility