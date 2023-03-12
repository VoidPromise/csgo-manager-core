#pragma once

#include "metadata.hpp"
#include "name.hpp"
#include "pch.h"
#include "userdata.hpp"

namespace cereal
{
    template <typename Archive>
    void save(Archive& archive, const date::year_month_day& data)
    {
        archive(
            static_cast<short>(data.year().operator int()),
            static_cast<unsigned char>(data.month().operator unsigned int()),
            static_cast<unsigned char>(data.day().operator unsigned int()));
    }

    template <typename Archive>
    void load(Archive& archive, date::year_month_day& data)
    {
        short y{0};
        unsigned char m{0};
        unsigned char d{0};

        archive(y, m, d);

        data =
            date::year_month_day{date::year{y}, date::month{m}, date::day{d}};
    }

    template <typename Archive>
    void save(Archive& archive, const vp::component::name& data)
    {
        archive(data._internal_container);
    }

    template <typename Archive>
    void load(Archive& archive, vp::component::name& data)
    {
        archive(data._internal_container);
        data._first_name = data._internal_container.begin();
        data._last_name = data._internal_container.rbegin();
        data._internal_string =
            vp::helper::accumulate_name(data._internal_container);
    }

    template <typename Archive>
    void serialize(Archive& archive, vp::component::user_data& data)
    {
        archive(data._birth, data._country, data._name, data._nickname,
                data._username);
    }

    template <typename Archive>
    void serialize(Archive& archive, vp::component::metadata& data)
    {
        archive(data._created, data._current_tick, data._last_modification,
                data._version);
    }
} // namespace cereal