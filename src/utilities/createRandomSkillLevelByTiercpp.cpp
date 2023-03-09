#include "createRandomSkillLevelByTier.hpp"

#include "pch.h"

namespace vp::utility
{
    std::uint8_t createRandomSkillLevelByTier(int tier)
    {
        switch (tier)
        {
        case 100:
            return effolkronium::random_thread_local::get<int>(95, 100);
        case 200:
            return effolkronium::random_thread_local::get<int>(92, 96);
        case 300:
            return effolkronium::random_thread_local::get<int>(89, 93);
        case 400:
            return effolkronium::random_thread_local::get<int>(85, 90);
        case 500:
            return effolkronium::random_thread_local::get<int>(82, 87);
        case 600:
            return effolkronium::random_thread_local::get<int>(78, 84);
        case 700:
            return effolkronium::random_thread_local::get<int>(69, 80);
        case 800:
            return effolkronium::random_thread_local::get<int>(64, 72);
        case 900:
            return effolkronium::random_thread_local::get<int>(55, 67);
        }
        return 0;
    }
} // namespace vp::utility