#include "CppUnitTest.h"
#include "csgocore.hpp"
#include "namegen.hpp"
#include "nicknamegen.hpp"
#include "pch.h"

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
        Logger::WriteMessage("tentando carregar recursos no ng e nng");

        try
        {
            if (!std::filesystem::exists(_current_path / "resources"))
            {
                Assert::IsTrue(std::filesystem::create_directory(_current_path /
                                                                 "resources"),
                               L"Failed to create temp directory");
            }

            std::filesystem::copy("a_csmanager/name-generator/resources",
                                  _current_path / R"(resources/name)",
                                  std::filesystem::copy_options::recursive);
            std::filesystem::copy("a_csmanager/nickname-generator/resources",
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
        vp::csgocore::instance().initialize();
        vp::csgocore::instance().new_game();
    }
};
} // namespace vp::ut

// carregar recursos do namegen e nickgen no initialize do csgocore
//
//
// copiar recursos dos mesmos na pasta de execução do teste
// limpar as cópias
//
// testar que carregou tudo certo
// testar que criou x peoples, x players, x coaches, etc
// testar que não há nomes iguais
// testar numero de paises
// tetar numero de rating
