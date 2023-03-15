#pragma once

#include "age.hpp"
#include "country.hpp"
#include "gamedata.hpp"
#include "metadata.hpp"
#include "name.hpp"
#include "nickname.hpp"
#include "pch.h"
#include "player.hpp"
#include "role.hpp"
#include "skill.hpp"
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
        data._first_name = *data._internal_container.begin();
        data._last_name = *data._internal_container.rbegin();
        data._internal_string =
            vp::helper::accumulate_name(data._internal_container);
    }

    template <typename Archive>
    void serialize(Archive& archive, vp::component::age& data)
    {
        archive(data._birth, data._value);
    }

    template <typename Archive>
    void serialize(Archive& archive, vp::component::country& data)
    {
        archive(data._country, data._culture);
    }

    template <typename Archive>
    void serialize(Archive& archive, vp::component::game_data& data)
    {
        archive(data._current_day, data._description, data._first_day,
                data._title_long, data._title_short, data._version);
    }

    template <typename Archive>
    void serialize(Archive& archive, vp::component::metadata& data)
    {
        archive(data._created, data._current_tick, data._last_modification,
                data._version);
    }

    template <typename Archive>
    void serialize(Archive& archive, vp::component::nickname& data)
    {
        archive(data._internal_string, data._original_string);
    }

    template <typename Archive>
    void serialize(Archive& archive, vp::component::role& data)
    {
        archive(data._primary_role_ct, data._primary_role_tr, data._secondary_role_ct,
                data._secondary_role_tr);
    }

    template <typename Archive>
    void serialize(Archive& archive, vp::component::skill& data)
    {
        archive(data._ancient_positions, data._anubis_positions,
                data._cache_positions, data._cobblestone_positions,
                data._dust2_positions, data._general_attributes,
                data._guns_proficiency, data._inferno_positions,
                data._map_knowledge, data._mirage_positions, data._nuke_positions,
                data._overpass_positions, data._role_knowledge, data._skill_level,
                data._train_positions, data._grenades_proficiency,
                data._vertigo_positions);
    }

    template <typename Archive>
    void serialize(Archive& archive, vp::component::user_data& data)
    {
        archive(data._birth, data._country, data._name, data._nickname,
                data._username);
    }
} // namespace cereal