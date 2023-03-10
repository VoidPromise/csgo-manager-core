#pragma once

namespace vp::utility::skills
{
    enum class general
    {
        motor,
        soft,
        cognitive,
        memory,
        karma,
        accuracy,
        reflex,
        spray_control,
        movement,
        positioning,
        aim_placement,
        peeking,
        strafe,
        pre_fire,
        concentration,
        fortitude,
        creativity,
        aggressiveness,
        game_sense,
        commitment,
        modesty,
        teamwork,
        leadership,
        charisma,
        initiative
    };

    enum class gun
    {
        knife,
        zeus_x27,
        usp_s,
        p2000,
        glock_18,
        dual_berettas,
        p250,
        five_seven,
        tec_9,
        cz75_auto,
        desert_eagle,
        r8_revolver, // pistols
        nova,
        xm114,
        mag_7,
        sawed_off,
        m249,
        negev, // heavys
        mp9,
        mac_10,
        mp7,
        mp5_sd,
        ump_45,
        p90,
        pp_bizon, // SMGs
        famas,
        galil_ar,
        m4a1_s,
        m4a4,
        ssg_08,
        aug,
        sg_553,
        awp,
        scar_20,
        g3sg1 // rifles
    };

    enum class utility
    {
        he_grenade,
        flashbang,
        smoke_grenade,
        decoy_grenade,
        incendiary,
        molotov
    };

    enum class role
    {
        ct_mid,
        ct_rotator,
        ct_anchor_a,
        ct_anchor_b,
        ct_joker,
        tr_entry,
        tr_support,
        tr_lurker,
        tr_trader,
        tr_joker
    };

    enum class map
    {
        ancient,
        anubis,
        inferno,
        mirage,
        nuke,
        overpass,
        vertigo,
        cache,
        cobblestone,
        dust2,
        train
    };

    enum class ancienct_positions
    {
        ct_spawn,
        t_spawn,
        bomb_a,
        bomb_b,
        snake,
        main,
        totem,
        mid,
        red,
        square,
        cave,
        secret,
        banana,
        ramp,
        doors,
        temple
    };

    enum class anubis_positions
    {
        ct_spawn,
        t_spawn,
        bomb_a,
        bomb_b,
        tunnel,
        palace,
        alley,
        mid,
        walkway,
        main,
        boat,
        connector,
        long_,
        street,
        bridge,
        ruins
    };

    enum class inferno_positions
    {
        ct_spawn,
        t_spawn,
        bomb_a,
        bomb_b,
        ramp,
        banana,
        mid,
        second_mid,
        construction,
        library,
        long_,
        top_mid,
        pit,
        underpass,
        apartments,
        short_,
        alley
    };

    enum class mirage_positions
    {
        ct_spawn,
        t_spawn,
        bomb_a,
        bomb_b,
        market,
        apartments,
        house,
        palace,
        ramp,
        connector,
        window,
        mid,
        top_mid,
        short_,
        underpass
    };

    enum class nuke_positions
    {
        ct_spawn,
        t_spawn,
        bomb_a,
        bomb_b,
        silo,
        outside,
        garage,
        secret,
        main,
        catwalk,
        heaven,
        hell,
        lobby,
        squeaky,
        radio,
        ramp,
        hut,
        vent,
        window,
        double_doors,
        single_door
    };

    enum class overpass_positions
    {
        ct_spawn,
        t_spawn,
        bomb_a,
        bomb_b,
        bank,
        heaven,
        hell,
        canals,
        monster,
        water,
        connector,
        short_,
        long_,
        toilets,
        party,
        stairs,
        fountain,
        playground
    };

    enum class vertigo_positions
    {
        ct_spawn,
        t_spawn,
        bomb_a,
        bomb_b,
        connector,
        mid,
        stairs,
        elevators,
        top_mid,
        yellow,
        ramp,
        heaven,
        ladder,
        main,
        tunnels,
        big_box
    };

    enum class cache_positions
    {
        ct_spawn,
        t_spawn,
        bomb_a,
        bomb_b,
        hell,
        car,
        highway,
        mid,
        window,
        heaven,
        boxes,
        garage,
        checkers,
        vent,
        halls,
        main,
        boost,
        squeaky,
        long_
    };

    enum class cobblestone_positions
    {
        ct_spawn,
        t_spawn,
        bomb_a,
        bomb_b,
        statue,
        dragon_lore,
        t_ramp,
        mid,
        ct_ramp,
        catwalk,
        a_long,
        connector,
        sky,
        drop,
        b_long,
        doors,
        plat
    };

    enum class dust2_positions
    {
        ct_spawn,
        t_spawn,
        bomb_a,
        bomb_b,
        ct_mid,
        upper,
        lower,
        short_,
        ramp,
        car,
        long_,
        pit,
        mid,
        t_mid,
        suicide,
        football,
        outside_long,
        long_doors
    };

    enum class train_positions
    {
        ct_spawn,
        t_spawn,
        bomb_a,
        bomb_b,
        stairs,
        back_site,
        sidewalk,
        catwalk,
        upper,
        lower,
        halls,
        pop,
        showers,
        main,
        connector,
        heaven,
        hell,
        olof,
        old_bomb,
        tunnel,
        ivy,
        pigeons,
        alley
    };
} // namespace vp::utility::skills