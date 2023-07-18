#include "CppUnitTest.h"
#include "csgocore.hpp"
#include "namegen.hpp"
#include "nicknamegen.hpp"
#include "pch.h"

#include "age.hpp"
#include "coach.hpp"
#include "player.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace vp::ut
{
TEST_CLASS (generatepeople)
{
  public:
    static inline std::filesystem::path _current_path =
        std::filesystem::current_path();

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
        Assert::IsTrue(vp::csgocore::instance().new_game(),
                       L"Failed to instantiate a new game");

        auto entity = vp::csgocore::instance()._registry.create();

        auto& reg = vp::csgocore::instance()._registry;

        reg.any_of<vp::component::player, vp::component::coach>(entity);

        auto players = reg.view<vp::component::player>();
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
