#include "CppUnitTest.h"
#include "nicknamegen.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace vp::ut
{
TEST_CLASS (nicknamegenerator)
{
  public:
    TEST_CLASS_INITIALIZE(LoadResourcesFolder)
    {
        std::string nickname_resource_dir = PROJECTS_FOLDER;
        nickname_resource_dir.append(R"(nickname-generator\resources)");

        std::filesystem::path current_path{std::filesystem::current_path()};

        try
        {
            if (!std::filesystem::exists(current_path / "resources"))
            {
                Assert::IsTrue(std::filesystem::create_directory(current_path /
                                                                 "resources"),
                               L"Failed to create temp directory");
            }

            std::filesystem::copy(
                nickname_resource_dir, current_path / R"(resources/nickname)",
                std::filesystem::copy_options::overwrite_existing);

            Assert::IsTrue(
                std::filesystem::exists(current_path /
                                        R"(resources/nickname/animals.words)"),
                L"Failed to copy resources");

            Assert::IsTrue(vp::helper::nng::instance().load(
                               current_path / R"(resources/nickname)"),
                           L"Failed to load resources");
        }
        catch (std::exception& e)
        {
            Assert::Fail(L"Failed to setup resources folder");
        }
    }

    TEST_METHOD (InvalidLoad)
    {
        Assert::IsFalse(vp::helper::nng::instance().load(L"./invalid-path"),
                        L"Loading method returned success for invalid path");
    }

    TEST_METHOD (NicknameFromWord)
    {
        try
        {
            std::wstring random_word{L""};

            const std::wstring nickname =
                vp::helper::nng::instance().get_nickname(random_word);

            Assert::IsTrue(random_word != std::wstring(L""),
                                L"Failed to retrieve original word");

            Assert::IsTrue(nickname != std::wstring(L""),
                                L"Failed to generate nickname");
        }
        catch (std::exception& e)
        {
            Assert::Fail(L"Failed to setup resources folder");
        }
    }

    TEST_CLASS_CLEANUP(CleanupResourcesFolder)
    {
        std::filesystem::path current_path{std::filesystem::current_path()};

        try
        {
            Assert::IsTrue(
                std::filesystem::remove_all(current_path / "resources") > 0,
                L"Failed to remove resources");
            Assert::IsFalse(
                std::filesystem::exists(current_path / R"(resources/nickname)"),
                L"Nickname folder still exists");
        }
        catch (const std::exception&)
        {
            Assert::Fail(L"Exception cleaning up resources");
        }
    }
};
} // namespace vp::ut
