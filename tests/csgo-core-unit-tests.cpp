#include "CppUnitTest.h"
#include "csgocore.hpp"
#include "namegen.hpp"
#include "nicknamegen.hpp"
#include "pch.h"

#include "age.hpp"
#include "coach.hpp"
#include "country.hpp"
#include "physicaltrainer.hpp"
#include "player.hpp"
#include "psychologist.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace vp::ut
{
TEST_CLASS (generatepeople)
{
  public:
    static const inline std::filesystem::path _current_path =
        std::filesystem::current_path();

    static const inline std::size_t number_people = 960;

    static const inline entt::registry& reg =
        vp::csgocore::instance()._registry;

    static inline auto players = reg.view<component::player>();
    static inline auto coachs = reg.view<component::coach>();
    static inline auto psychologists = reg.view<component::psychologist>();
    static inline auto physicaltrainers =
        reg.view<component::physical_trainer>();

    TEST_CLASS_INITIALIZE(NewGame)
    {
        std::string namegen_resource_dir = PROJECTS_FOLDER;
        std::string nickgen_resource_dir = PROJECTS_FOLDER;
        namegen_resource_dir.append(R"(name-generator\resources)");
        nickgen_resource_dir.append(R"(nickname-generator\resources)");

        Logger::WriteMessage("Trying to load the resources from the name "
                             "generator and the nickname generator");

        try
        {
            if (!std::filesystem::exists(_current_path / "resources"))
            {
                Assert::IsTrue(std::filesystem::create_directory(_current_path /
                                                                 "resources"),
                               L"Failed to create temp directory");
            }

            std::filesystem::copy(namegen_resource_dir,
                                  _current_path / R"(resources/name)",
                                  std::filesystem::copy_options::recursive);
            std::filesystem::copy(nickgen_resource_dir,
                                  _current_path / R"(resources/nickname)",
                                  std::filesystem::copy_options::recursive);

            Assert::IsTrue(
                std::filesystem::exists(
                    _current_path / R"(resources/name/brazilian/male.names)"),
                L"Failed to copy resources");
            Assert::IsTrue(
                std::filesystem::exists(_current_path /
                                        R"(resources/nickname/animals.words)"),
                L"Failed to copy resources");

            Assert::IsTrue(vp::helper::ng::instance().load(_current_path /
                                                           R"(resources/name)"),
                           L"Failed to load resources");
            Assert::IsTrue(vp::helper::nng::instance().load(
                               _current_path / R"(resources/nickname)"),
                           L"Failed to load resources");

            Logger::WriteMessage("Success setting up the resources folder for "
                                 "name and nickname generator tests");
        }
        catch (std::exception& e)
        {

            Logger::WriteMessage("Failure setting up the resources folder for "
                                 "name generator tests");
            Assert::Fail(L"Failed to setup resources folder");
        }
    }

    TEST_METHOD (Initialization)
    {
        Assert::IsTrue(vp::csgocore::instance().initialize(),
                       L"Failed to initialize csgo-core");
        Assert::IsTrue(vp::csgocore::instance().new_game(number_people),
                       L"Failed to instantiate a new game");
        players = reg.view<component::player>();
        coachs = reg.view<component::coach>();
        psychologists = reg.view<component::psychologist>();
        physicaltrainers = reg.view<component::physical_trainer>();
    }

    TEST_METHOD (NumberOfPeople)
    {
        Assert::IsTrue(players.size() >= number_people * 0.625);
        Assert::IsTrue(coachs.size() <= number_people * 0.125);
        Assert::IsTrue(psychologists.size() <= number_people * 0.125);
        Assert::IsTrue(physicaltrainers.size() <= number_people * 0.125);

        Logger::WriteMessage(
            ("The number of players is " + std::to_string(players.size()))
                .c_str());
        Logger::WriteMessage(
            ("The number of coachs is " + std::to_string(coachs.size()))
                .c_str());
        Logger::WriteMessage(("The number of psychologists is " +
                              std::to_string(psychologists.size()))
                                 .c_str());
        Logger::WriteMessage(("The number of physicaltrainers is " +
                              std::to_string(physicaltrainers.size()))
                                 .c_str());
    }

    TEST_METHOD (NoInternationalPeople)
    {
        auto people =
            reg.view<component::player, component::coach, component::country>();
        for (auto person : people)
        {
            auto country = people.get<component::country>(person)._country;
            auto country_string = magic_enum::enum_name(country);
            Assert::IsTrue(country == utility::country_code::brazil);
            Logger::WriteMessage(
                ("testando" + std::string(country_string)).c_str());
        }
    }

    TEST_CLASS_CLEANUP(CleanupResourcesFolder)
    {
        Logger::WriteMessage("Cleaning up the resources folder for "
                             "name generator tests at: ");

        Logger::WriteMessage(_current_path.c_str());

        try
        {
            Assert::IsTrue(std::filesystem::remove_all(_current_path /
                                                       "resources/name") > 0,
                           L"Failed to remove resources");
            Assert::IsFalse(
                std::filesystem::exists(_current_path / R"(resources/name)"),
                L"Name folder still exists");

            Assert::IsTrue(std::filesystem::remove_all(
                               _current_path / "resources/nickname") > 0,
                           L"Failed to remove resources");

            Assert::IsFalse(std::filesystem::exists(_current_path /
                                                    R"(resources/nickname)"),
                            L"Nickname folder still exists");

            Logger::WriteMessage("Success cleaning up the resources folder for "
                                 "name and nickname");
        }
        catch (const std::exception&)
        {
            Assert::Fail(L"Exception cleaning up resources");
        }
    }
};
} // namespace vp::ut

// testar que criou x peoples, x players, x coaches, etc
// testar que não há nomes iguais
// testar numero de paises
// testar numero de rating
