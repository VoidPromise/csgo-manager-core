#include "CppUnitTest.h"
#include "namegen.hpp"
#include "pch.h"
#include "wstringutils.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace vp::ut
{
TEST_CLASS (namegenerator)
{
  public:
    static inline std::filesystem::path _current_path =
        std::filesystem::current_path();

    TEST_CLASS_INITIALIZE(LoadResourcesFolder)
    {
        std::string name_resource_dir = PROJECTS_FOLDER;
        name_resource_dir.append(R"(name-generator\resources)");

        Logger::WriteMessage("Setting up the resources folder for "
                             "name generator tests at: ");

        Logger::WriteMessage(_current_path.c_str());

        try
        {
            if (!std::filesystem::exists(_current_path / "resources"))
            {
                Assert::IsTrue(std::filesystem::create_directory(_current_path /
                                                                 "resources"),
                               L"Failed to create temp directory");

                std::filesystem::copy(name_resource_dir,
                                      _current_path / R"(resources/name)",
                                      std::filesystem::copy_options::recursive);
            }

            Assert::IsTrue(
                std::filesystem::exists(
                    _current_path / R"(resources/name/brazilian/male.names)"),
                L"Failed to copy resources");

            Assert::IsTrue(vp::helper::ng::instance().load(_current_path /
                                                           R"(resources/name)"),
                           L"Failed to load resources");

            Logger::WriteMessage("Success setting up the resources folder for "
                                 "name generator tests");
        }
        catch (std::exception& e)
        {

            Logger::WriteMessage("Failure setting up the resources folder for "
                                 "name generator tests");
            Assert::Fail(L"Failed to setup resources folder");
        }
    }

    TEST_METHOD (LoadSuccess)
    {
        Assert::IsTrue(vp::helper::ng::instance().load(_current_path /
                                                       R"(resources/name)"),
                       L"Loading method returned failure for valid path");
    }

    TEST_METHOD (LoadFailure)
    {
        Assert::IsFalse(vp::helper::ng::instance().load(L"./invalid-path"),
                        L"Loading method returned success for invalid path");
    }

    TEST_METHOD (Name)
    {
        try
        {
            const std::wstring name{vp::helper::ng::instance().get_name()};
            const std::wstring surname{
                vp::helper::ng::instance().get_surname()};

            Logger::WriteMessage(
                (std::string("Name: ") + vp::utility::wstring_to_string(name) +
                 " \nSurname: " + vp::utility::wstring_to_string(surname))
                    .c_str());

            Assert::IsTrue(name != std::wstring(L""),
                           L"Failed to generate name");

            Assert::IsTrue(surname != std::wstring(L""),
                           L"Failed to generate surname");
        }
        catch (std::exception& e)
        {
            Assert::Fail(L"Unexpected exception");
        }
    }

    TEST_METHOD (NameSeeding)
    {
        try
        {
            effolkronium::random_thread_local::seed(10);

            const std::wstring name{vp::helper::ng::instance().get_name()};

            const std::wstring surname{
                vp::helper::ng::instance().get_surname()};

            effolkronium::random_thread_local::seed(10);

            const std::wstring name_2{vp::helper::ng::instance().get_name()};

            const std::wstring surname_2{
                vp::helper::ng::instance().get_surname()};

            Logger::WriteMessage(
                (std::string("Name: ") + vp::utility::wstring_to_string(name) +
                 " \nName no2: " + vp::utility::wstring_to_string(name_2))
                    .c_str());

            Logger::WriteMessage(
                (std::string("Surname: ") +
                 vp::utility::wstring_to_string(surname) +
                 " \nSurname no2: " + vp::utility::wstring_to_string(surname_2))
                    .c_str());

            Assert::AreEqual(name, name_2, L"Names with same seed don't match");

            Assert::AreEqual(surname, surname_2,
                             L"Surnames with same seed don't match");
        }
        catch (std::exception& e)
        {
            Assert::Fail(L"Unexpected exception");
        }
    }

    TEST_METHOD (NameRandomness)
    {
        try
        {
            const std::wstring name{vp::helper::ng::instance().get_name()};

            const std::wstring name_2{vp::helper::ng::instance().get_name()};

            const std::wstring surname{
                vp::helper::ng::instance().get_surname()};

            const std::wstring surname_2{
                vp::helper::ng::instance().get_surname()};

            Logger::WriteMessage(
                (std::string("Name: ") + vp::utility::wstring_to_string(name) +
                 " \nName no2: " + vp::utility::wstring_to_string(name_2))
                    .c_str());

            Logger::WriteMessage(
                (std::string("Surname: ") +
                 vp::utility::wstring_to_string(surname) +
                 " \nSurname no2: " + vp::utility::wstring_to_string(surname_2))
                    .c_str());

            Assert::AreNotEqual(name, name_2, L"Two random names are the same");

            Assert::AreNotEqual(surname, surname_2,
                                L"Two random surnames are the same");
        }
        catch (std::exception& e)
        {
            Assert::Fail(L"Unexpected exception");
        }
    }

    TEST_CLASS_CLEANUP(CleanupResourcesFolder)
    {
        Logger::WriteMessage("Cleaning up the resources folder for "
                             "name generator tests at: ");

        Logger::WriteMessage(_current_path.c_str());

        try
        {
            if (std::filesystem::exists(_current_path / "resources/name"))
            {
                Assert::IsTrue(std::filesystem::remove_all(
                                   _current_path / "resources/name") > 0,
                               L"Failed to remove resources");
                Assert::IsFalse(std::filesystem::exists(_current_path /
                                                        R"(resources/name)"),
                                L"Name folder still exists");

                Logger::WriteMessage(
                    "Success cleaning up the resources folder for "
                    "name generator tests");
            }
            else
            {
                Logger::WriteMessage(
                    "Resources already deleted by csgo-core-unit-tests");
            }
        }
        catch (const std::exception&)
        {
            Assert::Fail(L"Exception cleaning up resources");
        }
    }
};
} // namespace vp::ut
