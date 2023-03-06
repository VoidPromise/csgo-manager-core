#include "wstringutils.hpp"

#include <filesystem>

namespace vp::utility
{

std::string wstring_to_string(const std::wstring& wide_string)
{
    return std::filesystem::path(wide_string).string();
}

} // namespace vp::utility