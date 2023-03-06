#pragma once

#include <string>

namespace vp::utility
{

// Converts a wide string to string. Undefined behavior for
// non supported characters. Use only for logging and debug.
std::string wstring_to_string(const std::wstring& wide_string);

} // namespace vp::utility
