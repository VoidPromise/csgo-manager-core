#include "CppUnitTest.h"
#include "nicknamegen.hpp"
#include "pch.h"
#include "wstringutils.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace vp::ut
{
TEST_CLASS (nicknamegenerator)
{
  public:
    static inline std::filesystem::path _current_path =
        std::filesystem::current_path();

    TEST_CLASS_INITIALIZE(LoadResourcesFolder)
    {
        std::string nickname_resource_dir = PROJECTS_FOLDER;
        nickname_resource_dir.append(R"(nickname-generator\resources)");

        Logger::WriteMessage("Setting up the resources folder for "
                             "nickname generator tests at: ");

        Logger::WriteMessage(_current_path.c_str());

        try
        {
            if (!std::filesystem::exists(_current_path / "resources"))
            {
                Assert::IsTrue(std::filesystem::create_directory(_current_path /
                                                                 "resources"),
                               L"Failed to create temp directory");
            }

            std::filesystem::copy(
                nickname_resource_dir, _current_path / R"(resources/nickname)",
                std::filesystem::copy_options::overwrite_existing);

            Assert::IsTrue(
                std::filesystem::exists(_current_path /
                                        R"(resources/nickname/animals.words)"),
                L"Failed to copy resources");

            Assert::IsTrue(vp::helper::nng::instance().load(
                               _current_path / R"(resources/nickname)"),
                           L"Failed to load resources");

            Logger::WriteMessage("Success setting up the resources folder for "
                                 "nickname generator tests");
        }
        catch (std::exception& e)
        {
            Assert::Fail(L"Failed to setup resources folder");

            Logger::WriteMessage("Failure setting up the resources folder for "
                                 "nickname generator tests");
        }
    }

    TEST_METHOD (LoadSuccess)
    {
        Assert::IsTrue(vp::helper::nng::instance().load(
                           _current_path / R"(resources/nickname)"),
                       L"Loading method returned failure for valid path");
    }

    TEST_METHOD (LoadFailure)
    {
        Assert::IsFalse(vp::helper::nng::instance().load(L"./invalid-path"),
                        L"Loading method returned success for invalid path");
    }

    TEST_METHOD (NicknameFromName)
    {
        try
        {
            const std::wstring original_name{L"Diego"};

            std::wstring name{original_name};

            const std::wstring nickname =
                vp::helper::nng::instance().get_nickname(name);

            Logger::WriteMessage(
                (std::string("Original name: ") +
                 vp::utility::wstring_to_string(original_name) +
                 "\nOriginal name after execution: " +
                 vp::utility::wstring_to_string(name) +
                 " \nNickname: " + vp::utility::wstring_to_string(nickname))
                    .c_str());

            Assert::IsTrue(name == std::wstring(original_name),
                           L"Original name incorrectly modified");

            Assert::IsTrue(nickname != std::wstring(L""),
                           L"Failed to generate nickname");

            Assert::IsTrue(nickname != std::wstring(L"Diego"),
                           L"Nickname is equal to name");
        }
        catch (std::exception& e)
        {
            Assert::Fail(L"Unexpected exception");
        }
    }

    TEST_METHOD (NicknameFromRandomWord)
    {
        try
        {
            std::wstring random_word{L""};

            const std::wstring nickname =
                vp::helper::nng::instance().get_nickname(random_word);

            Logger::WriteMessage(
                (std::string("Random word: ") +
                 vp::utility::wstring_to_string(random_word) +
                 " \nNickname: " + vp::utility::wstring_to_string(nickname))
                    .c_str());

            Assert::IsTrue(random_word != std::wstring(L""),
                           L"Failed to retrieve original word");

            Assert::IsTrue(nickname != std::wstring(L""),
                           L"Failed to generate nickname");
        }
        catch (std::exception& e)
        {
            Assert::Fail(L"Unexpected exception");
        }
    }

    TEST_METHOD (NicknameSeeding)
    {
        try
        {
            effolkronium::random_thread_local::seed(10);

            std::wstring random_word{L""};

            const std::wstring nickname{
                vp::helper::nng::instance().get_nickname(random_word)};

            effolkronium::random_thread_local::seed(10);

            std::wstring random_word_2{L""};

            const std::wstring nickname_2{
                vp::helper::nng::instance().get_nickname(random_word_2)};

            Logger::WriteMessage(
                (std::string("Random word: ") +
                 vp::utility::wstring_to_string(random_word) +
                 " \nNickname: " + vp::utility::wstring_to_string(nickname))
                    .c_str());

            Logger::WriteMessage(
                (std::string("Random word no2: ") +
                 vp::utility::wstring_to_string(random_word_2) +
                 " \nNickname no2: " +
                 vp::utility::wstring_to_string(nickname_2))
                    .c_str());

            Assert::IsTrue(nickname != std::wstring(L""),
                           L"Failed to generate nickname");

            Assert::IsTrue(nickname_2 != std::wstring(L""),
                           L"Failed to generate second nickname");

            Assert::AreEqual(random_word, random_word_2,
                             L"Random words with same seed don't match");

            Assert::AreEqual(nickname, nickname_2,
                             L"Nicknames with same seed don't match");
        }
        catch (std::exception& e)
        {
            Assert::Fail(L"Unexpected exception");
        }
    }

    TEST_METHOD (NicknameRandomness)
    {
        try
        {
            std::wstring random_word{L""};

            const std::wstring nickname{
                vp::helper::nng::instance().get_nickname(random_word)};

            std::wstring random_word_2{L""};

            const std::wstring nickname_2{
                vp::helper::nng::instance().get_nickname(random_word_2)};

            Logger::WriteMessage(
                (std::string("Random word: ") +
                 vp::utility::wstring_to_string(random_word) +
                 " \nNickname: " + vp::utility::wstring_to_string(nickname))
                    .c_str());

            Logger::WriteMessage(
                (std::string("Random word no2: ") +
                 vp::utility::wstring_to_string(random_word_2) +
                 " \nNickname no2: " +
                 vp::utility::wstring_to_string(nickname_2))
                    .c_str());

            Assert::IsTrue(nickname != std::wstring(L""),
                           L"Failed to generate nickname");

            Assert::IsTrue(nickname_2 != std::wstring(L""),
                           L"Failed to generate second nickname");

            Assert::AreNotEqual(random_word, random_word_2,
                             L"Two random words are the same");

            Assert::AreNotEqual(nickname, nickname_2,
                             L"Two random nicknames are the same");
        }
        catch (std::exception& e)
        {
            Assert::Fail(L"Unexpected exception");
        }
    }

    TEST_CLASS_CLEANUP(CleanupResourcesFolder)
    {
        Logger::WriteMessage("Cleaning up the resources folder for "
                             "nickname generator tests at: ");

        Logger::WriteMessage(_current_path.c_str());

        try
        {
            Assert::IsTrue(
                std::filesystem::remove_all(_current_path / "resources") > 0,
                L"Failed to remove resources");
            Assert::IsFalse(std::filesystem::exists(_current_path /
                                                    R"(resources/nickname)"),
                            L"Nickname folder still exists");

            Logger::WriteMessage("Success cleaning up the resources folder for "
                                 "nickname generator tests");
        }
        catch (const std::exception&)
        {
            Assert::Fail(L"Exception cleaning up resources");
        }
    }
};
} // namespace vp::ut
