[export, sideeffects]
def SV_Physics() {
    var i : int
    var ent : int
    let c2da_fresh0 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    let c2da_fresh1 : uint = uint(c2da_fresh0)
    c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh1)
    c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    let c2da_fresh3 : uint = uint(c2da_fresh2)
    c2da_mem[pr_global_struct + 116] = uint8(c2da_fresh3)
    c2da_mem[pr_global_struct + 117] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[pr_global_struct + 118] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[pr_global_struct + 119] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20))
    let c2da_fresh5 : uint = float_bits_to_uint(c2da_fresh4)
    c2da_mem[pr_global_struct + 124] = uint8(c2da_fresh5)
    c2da_mem[pr_global_struct + 125] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[pr_global_struct + 126] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[pr_global_struct + 127] = uint8(c2da_fresh5 >> 0x18)
    PR_ExecuteProgram(int(uint(c2da_mem[pr_global_struct + 332]) | uint(c2da_mem[pr_global_struct + 333]) << 0x8 | uint(c2da_mem[pr_global_struct + 334]) << 0x10 | uint(c2da_mem[pr_global_struct + 335]) << 0x18))
    ent = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    i = 0
    while (i < int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        if ((uint(c2da_mem[ent]) | uint(c2da_mem[ent + 1]) << 0x8 | uint(c2da_mem[ent + 2]) << 0x10 | uint(c2da_mem[ent + 3]) << 0x18) != 0u) {
            i++
            ent += int(pr_edict_size)
            continue
        }
        if (uint_bits_to_float(uint(c2da_mem[pr_global_struct + 132]) | uint(c2da_mem[pr_global_struct + 133]) << 0x8 | uint(c2da_mem[pr_global_struct + 134]) << 0x10 | uint(c2da_mem[pr_global_struct + 135]) << 0x18) != 0.0) {
            SV_LinkEdict(ent, 1u)
        }
        if (i > 0 && i <= svs.maxclients) {
            SV_Physics_Client(ent, i)
        } elif (uint_bits_to_float(uint(c2da_mem[ent + 140]) | uint(c2da_mem[ent + 141]) << 0x8 | uint(c2da_mem[ent + 142]) << 0x10 | uint(c2da_mem[ent + 143]) << 0x18) == 7.0) {
            SV_Physics_Pusher(ent)
        } elif (uint_bits_to_float(uint(c2da_mem[ent + 140]) | uint(c2da_mem[ent + 141]) << 0x8 | uint(c2da_mem[ent + 142]) << 0x10 | uint(c2da_mem[ent + 143]) << 0x18) == 0.0) {
            SV_Physics_None(ent)
        } elif (uint_bits_to_float(uint(c2da_mem[ent + 140]) | uint(c2da_mem[ent + 141]) << 0x8 | uint(c2da_mem[ent + 142]) << 0x10 | uint(c2da_mem[ent + 143]) << 0x18) == 8.0) {
            SV_Physics_Noclip(ent)
        } elif (uint_bits_to_float(uint(c2da_mem[ent + 140]) | uint(c2da_mem[ent + 141]) << 0x8 | uint(c2da_mem[ent + 142]) << 0x10 | uint(c2da_mem[ent + 143]) << 0x18) == 4.0) {
            SV_Physics_Step(ent)
        } elif (uint_bits_to_float(uint(c2da_mem[ent + 140]) | uint(c2da_mem[ent + 141]) << 0x8 | uint(c2da_mem[ent + 142]) << 0x10 | uint(c2da_mem[ent + 143]) << 0x18) == 6.0 || uint_bits_to_float(uint(c2da_mem[ent + 140]) | uint(c2da_mem[ent + 141]) << 0x8 | uint(c2da_mem[ent + 142]) << 0x10 | uint(c2da_mem[ent + 143]) << 0x18) == 10.0 || uint_bits_to_float(uint(c2da_mem[ent + 140]) | uint(c2da_mem[ent + 141]) << 0x8 | uint(c2da_mem[ent + 142]) << 0x10 | uint(c2da_mem[ent + 143]) << 0x18) == 5.0 || uint_bits_to_float(uint(c2da_mem[ent + 140]) | uint(c2da_mem[ent + 141]) << 0x8 | uint(c2da_mem[ent + 142]) << 0x10 | uint(c2da_mem[ent + 143]) << 0x18) == 9.0) {
            SV_Physics_Toss(ent)
        } else {
            Sys_Error(736670, [C2daVaArg(tag = 1, i64 = int64(int(uint_bits_to_float(uint(c2da_mem[ent + 140]) | uint(c2da_mem[ent + 141]) << 0x8 | uint(c2da_mem[ent + 142]) << 0x10 | uint(c2da_mem[ent + 143]) << 0x18))), f64 = 0.0lf, raw = 0x0)])
        }
        i++
        ent += int(pr_edict_size)
    }
    if (uint_bits_to_float(uint(c2da_mem[pr_global_struct + 132]) | uint(c2da_mem[pr_global_struct + 133]) << 0x8 | uint(c2da_mem[pr_global_struct + 134]) << 0x10 | uint(c2da_mem[pr_global_struct + 135]) << 0x18) != 0.0) {
        let c2da_fresh6 : float = uint_bits_to_float(uint(c2da_mem[pr_global_struct + 132]) | uint(c2da_mem[pr_global_struct + 133]) << 0x8 | uint(c2da_mem[pr_global_struct + 134]) << 0x10 | uint(c2da_mem[pr_global_struct + 135]) << 0x18)
        let c2da_fresh7 : float = c2da_fresh6 - 1.0
        let c2da_fresh8 : uint = float_bits_to_uint(c2da_fresh7)
        c2da_mem[pr_global_struct + 132] = uint8(c2da_fresh8)
        c2da_mem[pr_global_struct + 133] = uint8(c2da_fresh8 >> 0x8)
        c2da_mem[pr_global_struct + 134] = uint8(c2da_fresh8 >> 0x10)
        c2da_mem[pr_global_struct + 135] = uint8(c2da_fresh8 >> 0x18)
    }
    let c2da_fresh9 : double = uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20) + double(host_frametime)
    let c2da_fresh10 : uint64 = double_bits_to_uint64(c2da_fresh9)
    c2da_mem[225872] = uint8(c2da_fresh10)
    c2da_mem[225873] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[225874] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[225875] = uint8(c2da_fresh10 >> 0x18)
    c2da_mem[225876] = uint8(c2da_fresh10 >> 0x20)
    c2da_mem[225877] = uint8(c2da_fresh10 >> 0x28)
    c2da_mem[225878] = uint8(c2da_fresh10 >> 0x30)
    c2da_mem[225879] = uint8(c2da_fresh10 >> 0x38)
    return
}
[export, sideeffects]
def SV_Physics_Toss(var ent_0 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_Physics_Toss_c2da_frame(ent_0, c2da_lin_enter(80))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def SV_CheckWaterTransition(var ent_1 : int) {
    var cont : int = SV_PointContents(ent_1 + 148)
    if (uint_bits_to_float(uint(c2da_mem[ent_1 + 444]) | uint(c2da_mem[ent_1 + 445]) << 0x8 | uint(c2da_mem[ent_1 + 446]) << 0x10 | uint(c2da_mem[ent_1 + 447]) << 0x18) == 0.0) {
        let c2da_fresh41 : float = float(cont)
        let c2da_fresh42 : uint = float_bits_to_uint(c2da_fresh41)
        c2da_mem[ent_1 + 444] = uint8(c2da_fresh42)
        c2da_mem[ent_1 + 445] = uint8(c2da_fresh42 >> 0x8)
        c2da_mem[ent_1 + 446] = uint8(c2da_fresh42 >> 0x10)
        c2da_mem[ent_1 + 447] = uint8(c2da_fresh42 >> 0x18)
        let c2da_fresh43 : float = 1.0
        let c2da_fresh44 : uint = float_bits_to_uint(c2da_fresh43)
        c2da_mem[ent_1 + 440] = uint8(c2da_fresh44)
        c2da_mem[ent_1 + 441] = uint8(c2da_fresh44 >> 0x8)
        c2da_mem[ent_1 + 442] = uint8(c2da_fresh44 >> 0x10)
        c2da_mem[ent_1 + 443] = uint8(c2da_fresh44 >> 0x18)
        return
    }
    if (cont <= -3) {
        if (uint_bits_to_float(uint(c2da_mem[ent_1 + 444]) | uint(c2da_mem[ent_1 + 445]) << 0x8 | uint(c2da_mem[ent_1 + 446]) << 0x10 | uint(c2da_mem[ent_1 + 447]) << 0x18) == -1.0) {
            SV_StartSound(ent_1, 0, 736698, 255, 1.0)
        }
        let c2da_fresh45 : float = float(cont)
        let c2da_fresh46 : uint = float_bits_to_uint(c2da_fresh45)
        c2da_mem[ent_1 + 444] = uint8(c2da_fresh46)
        c2da_mem[ent_1 + 445] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[ent_1 + 446] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[ent_1 + 447] = uint8(c2da_fresh46 >> 0x18)
        let c2da_fresh47 : float = 1.0
        let c2da_fresh48 : uint = float_bits_to_uint(c2da_fresh47)
        c2da_mem[ent_1 + 440] = uint8(c2da_fresh48)
        c2da_mem[ent_1 + 441] = uint8(c2da_fresh48 >> 0x8)
        c2da_mem[ent_1 + 442] = uint8(c2da_fresh48 >> 0x10)
        c2da_mem[ent_1 + 443] = uint8(c2da_fresh48 >> 0x18)
    } else {
        if (uint_bits_to_float(uint(c2da_mem[ent_1 + 444]) | uint(c2da_mem[ent_1 + 445]) << 0x8 | uint(c2da_mem[ent_1 + 446]) << 0x10 | uint(c2da_mem[ent_1 + 447]) << 0x18) != -1.0) {
            SV_StartSound(ent_1, 0, 736698, 255, 1.0)
        }
        let c2da_fresh49 : float = -1.0
        let c2da_fresh50 : uint = float_bits_to_uint(c2da_fresh49)
        c2da_mem[ent_1 + 444] = uint8(c2da_fresh50)
        c2da_mem[ent_1 + 445] = uint8(c2da_fresh50 >> 0x8)
        c2da_mem[ent_1 + 446] = uint8(c2da_fresh50 >> 0x10)
        c2da_mem[ent_1 + 447] = uint8(c2da_fresh50 >> 0x18)
        let c2da_fresh51 : float = float(cont)
        let c2da_fresh52 : uint = float_bits_to_uint(c2da_fresh51)
        c2da_mem[ent_1 + 440] = uint8(c2da_fresh52)
        c2da_mem[ent_1 + 441] = uint8(c2da_fresh52 >> 0x8)
        c2da_mem[ent_1 + 442] = uint8(c2da_fresh52 >> 0x10)
        c2da_mem[ent_1 + 443] = uint8(c2da_fresh52 >> 0x18)
    }
    return
}
[export, sideeffects]
def ClipVelocity(var in_0 : int; var normal : int; var out : int; var overbounce : float) : int {
    var backoff_0 : float
    var blocked : int = 0
    if (uint_bits_to_float(uint(c2da_mem[normal + 2 * 4]) | uint(c2da_mem[normal + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[normal + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[normal + 2 * 4 + 3]) << 0x18) > 0.0) {
        blocked |= 1
    }
    if (uint_bits_to_float(uint(c2da_mem[normal + 2 * 4]) | uint(c2da_mem[normal + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[normal + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[normal + 2 * 4 + 3]) << 0x18) == 0.0) {
        blocked |= 2
    }
    backoff_0 = (uint_bits_to_float(uint(c2da_mem[in_0 + 0 * 4]) | uint(c2da_mem[in_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[normal + 0 * 4]) | uint(c2da_mem[normal + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[normal + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[normal + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in_0 + 1 * 4]) | uint(c2da_mem[in_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[normal + 1 * 4]) | uint(c2da_mem[normal + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[normal + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[normal + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in_0 + 2 * 4]) | uint(c2da_mem[in_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[normal + 2 * 4]) | uint(c2da_mem[normal + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[normal + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[normal + 2 * 4 + 3]) << 0x18)) * overbounce
    for (i_0 in range(0, 3)) {
        let c2da_fresh53 : float = uint_bits_to_float(uint(c2da_mem[in_0 + i_0 * 4]) | uint(c2da_mem[in_0 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + i_0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[normal + i_0 * 4]) | uint(c2da_mem[normal + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[normal + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[normal + i_0 * 4 + 3]) << 0x18) * backoff_0
        let c2da_fresh54 : uint = float_bits_to_uint(c2da_fresh53)
        c2da_mem[out + i_0 * 4] = uint8(c2da_fresh54)
        c2da_mem[out + i_0 * 4 + 1] = uint8(c2da_fresh54 >> 0x8)
        c2da_mem[out + i_0 * 4 + 2] = uint8(c2da_fresh54 >> 0x10)
        c2da_mem[out + i_0 * 4 + 3] = uint8(c2da_fresh54 >> 0x18)
        if (double(uint_bits_to_float(uint(c2da_mem[out + i_0 * 4]) | uint(c2da_mem[out + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[out + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[out + i_0 * 4 + 3]) << 0x18)) > -0.1lf && double(uint_bits_to_float(uint(c2da_mem[out + i_0 * 4]) | uint(c2da_mem[out + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[out + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[out + i_0 * 4 + 3]) << 0x18)) < 0.1lf) {
            let c2da_fresh55 : float = 0.0
            let c2da_fresh56 : uint = float_bits_to_uint(c2da_fresh55)
            c2da_mem[out + i_0 * 4] = uint8(c2da_fresh56)
            c2da_mem[out + i_0 * 4 + 1] = uint8(c2da_fresh56 >> 0x8)
            c2da_mem[out + i_0 * 4 + 2] = uint8(c2da_fresh56 >> 0x10)
            c2da_mem[out + i_0 * 4 + 3] = uint8(c2da_fresh56 >> 0x18)
        }
    }
    return blocked
}
[export, sideeffects]
def SV_PushEntity(var ent_2 : int; var push_0 : int) : trace_t {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : trace_t = SV_PushEntity_c2da_frame(ent_2, push_0, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def SV_Impact(var e1 : int; var e2 : int) {
    var old_self : int
    var old_other : int
    old_self = int(uint(c2da_mem[pr_global_struct + 112]) | uint(c2da_mem[pr_global_struct + 113]) << 0x8 | uint(c2da_mem[pr_global_struct + 114]) << 0x10 | uint(c2da_mem[pr_global_struct + 115]) << 0x18)
    old_other = int(uint(c2da_mem[pr_global_struct + 116]) | uint(c2da_mem[pr_global_struct + 117]) << 0x8 | uint(c2da_mem[pr_global_struct + 118]) << 0x10 | uint(c2da_mem[pr_global_struct + 119]) << 0x18)
    let c2da_fresh69 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20))
    let c2da_fresh70 : uint = float_bits_to_uint(c2da_fresh69)
    c2da_mem[pr_global_struct + 124] = uint8(c2da_fresh70)
    c2da_mem[pr_global_struct + 125] = uint8(c2da_fresh70 >> 0x8)
    c2da_mem[pr_global_struct + 126] = uint8(c2da_fresh70 >> 0x10)
    c2da_mem[pr_global_struct + 127] = uint8(c2da_fresh70 >> 0x18)
    if (int(uint(c2da_mem[e1 + 276]) | uint(c2da_mem[e1 + 277]) << 0x8 | uint(c2da_mem[e1 + 278]) << 0x10 | uint(c2da_mem[e1 + 279]) << 0x18) != 0 && uint_bits_to_float(uint(c2da_mem[e1 + 144]) | uint(c2da_mem[e1 + 145]) << 0x8 | uint(c2da_mem[e1 + 146]) << 0x10 | uint(c2da_mem[e1 + 147]) << 0x18) != 0.0) {
        let c2da_fresh71 : int = e1 - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh72 : uint = uint(c2da_fresh71)
        c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh72)
        c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh72 >> 0x8)
        c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh72 >> 0x10)
        c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh72 >> 0x18)
        let c2da_fresh73 : int = e2 - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh74 : uint = uint(c2da_fresh73)
        c2da_mem[pr_global_struct + 116] = uint8(c2da_fresh74)
        c2da_mem[pr_global_struct + 117] = uint8(c2da_fresh74 >> 0x8)
        c2da_mem[pr_global_struct + 118] = uint8(c2da_fresh74 >> 0x10)
        c2da_mem[pr_global_struct + 119] = uint8(c2da_fresh74 >> 0x18)
        PR_ExecuteProgram(int(uint(c2da_mem[e1 + 276]) | uint(c2da_mem[e1 + 277]) << 0x8 | uint(c2da_mem[e1 + 278]) << 0x10 | uint(c2da_mem[e1 + 279]) << 0x18))
    }
    if (int(uint(c2da_mem[e2 + 276]) | uint(c2da_mem[e2 + 277]) << 0x8 | uint(c2da_mem[e2 + 278]) << 0x10 | uint(c2da_mem[e2 + 279]) << 0x18) != 0 && uint_bits_to_float(uint(c2da_mem[e2 + 144]) | uint(c2da_mem[e2 + 145]) << 0x8 | uint(c2da_mem[e2 + 146]) << 0x10 | uint(c2da_mem[e2 + 147]) << 0x18) != 0.0) {
        let c2da_fresh75 : int = e2 - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh76 : uint = uint(c2da_fresh75)
        c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh76)
        c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh76 >> 0x8)
        c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh76 >> 0x10)
        c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh76 >> 0x18)
        let c2da_fresh77 : int = e1 - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh78 : uint = uint(c2da_fresh77)
        c2da_mem[pr_global_struct + 116] = uint8(c2da_fresh78)
        c2da_mem[pr_global_struct + 117] = uint8(c2da_fresh78 >> 0x8)
        c2da_mem[pr_global_struct + 118] = uint8(c2da_fresh78 >> 0x10)
        c2da_mem[pr_global_struct + 119] = uint8(c2da_fresh78 >> 0x18)
        PR_ExecuteProgram(int(uint(c2da_mem[e2 + 276]) | uint(c2da_mem[e2 + 277]) << 0x8 | uint(c2da_mem[e2 + 278]) << 0x10 | uint(c2da_mem[e2 + 279]) << 0x18))
    }
    let c2da_fresh79 : uint = uint(old_self)
    c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh79)
    c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh79 >> 0x8)
    c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh79 >> 0x10)
    c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh79 >> 0x18)
    let c2da_fresh80 : uint = uint(old_other)
    c2da_mem[pr_global_struct + 116] = uint8(c2da_fresh80)
    c2da_mem[pr_global_struct + 117] = uint8(c2da_fresh80 >> 0x8)
    c2da_mem[pr_global_struct + 118] = uint8(c2da_fresh80 >> 0x10)
    c2da_mem[pr_global_struct + 119] = uint8(c2da_fresh80 >> 0x18)
    return
}
[export, sideeffects]
def SV_AddGravity(var ent_3 : int) {
    var ent_gravity : float
    var val : int = GetEdictFieldValue(ent_3, 736715)
    if (val != 0 && uint_bits_to_float(uint(c2da_mem[val]) | uint(c2da_mem[val + 1]) << 0x8 | uint(c2da_mem[val + 2]) << 0x10 | uint(c2da_mem[val + 3]) << 0x18) != 0.0) {
        ent_gravity = uint_bits_to_float(uint(c2da_mem[val]) | uint(c2da_mem[val + 1]) << 0x8 | uint(c2da_mem[val + 2]) << 0x10 | uint(c2da_mem[val + 3]) << 0x18)
    } else {
        ent_gravity = 1.0
    }
    let c2da_fresh81 : float = float(double(uint_bits_to_float(uint(c2da_mem[ent_3 + 172 + 2 * 4]) | uint(c2da_mem[ent_3 + 172 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_3 + 172 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_3 + 172 + 2 * 4 + 3]) << 0x18)) - double(double(ent_gravity * uint_bits_to_float(uint(c2da_mem[462616]) | uint(c2da_mem[462617]) << 0x8 | uint(c2da_mem[462618]) << 0x10 | uint(c2da_mem[462619]) << 0x18)) * host_frametime))
    let c2da_fresh82 : uint = float_bits_to_uint(c2da_fresh81)
    c2da_mem[ent_3 + 172 + 2 * 4] = uint8(c2da_fresh82)
    c2da_mem[ent_3 + 172 + 2 * 4 + 1] = uint8(c2da_fresh82 >> 0x8)
    c2da_mem[ent_3 + 172 + 2 * 4 + 2] = uint8(c2da_fresh82 >> 0x10)
    c2da_mem[ent_3 + 172 + 2 * 4 + 3] = uint8(c2da_fresh82 >> 0x18)
    return
}
[export, sideeffects]
def SV_CheckVelocity(var ent_4 : int) {
    for (i_1 in range(0, 3)) {
        if ((int(uint(c2da_mem[ent_4 + 172 + i_1 * 4]) | uint(c2da_mem[ent_4 + 172 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_4 + 172 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_4 + 172 + i_1 * 4 + 3]) << 0x18) & nanmask) == nanmask) {
            Con_Printf(736723, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[ent_4 + 220]) | uint(c2da_mem[ent_4 + 221]) << 0x8 | uint(c2da_mem[ent_4 + 222]) << 0x10 | uint(c2da_mem[ent_4 + 223]) << 0x18)))])
            let c2da_fresh83 : float = 0.0
            let c2da_fresh84 : uint = float_bits_to_uint(c2da_fresh83)
            c2da_mem[ent_4 + 172 + i_1 * 4] = uint8(c2da_fresh84)
            c2da_mem[ent_4 + 172 + i_1 * 4 + 1] = uint8(c2da_fresh84 >> 0x8)
            c2da_mem[ent_4 + 172 + i_1 * 4 + 2] = uint8(c2da_fresh84 >> 0x10)
            c2da_mem[ent_4 + 172 + i_1 * 4 + 3] = uint8(c2da_fresh84 >> 0x18)
        }
        if ((int(uint(c2da_mem[ent_4 + 148 + i_1 * 4]) | uint(c2da_mem[ent_4 + 148 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_4 + 148 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_4 + 148 + i_1 * 4 + 3]) << 0x18) & nanmask) == nanmask) {
            Con_Printf(736749, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[ent_4 + 220]) | uint(c2da_mem[ent_4 + 221]) << 0x8 | uint(c2da_mem[ent_4 + 222]) << 0x10 | uint(c2da_mem[ent_4 + 223]) << 0x18)))])
            let c2da_fresh85 : float = 0.0
            let c2da_fresh86 : uint = float_bits_to_uint(c2da_fresh85)
            c2da_mem[ent_4 + 148 + i_1 * 4] = uint8(c2da_fresh86)
            c2da_mem[ent_4 + 148 + i_1 * 4 + 1] = uint8(c2da_fresh86 >> 0x8)
            c2da_mem[ent_4 + 148 + i_1 * 4 + 2] = uint8(c2da_fresh86 >> 0x10)
            c2da_mem[ent_4 + 148 + i_1 * 4 + 3] = uint8(c2da_fresh86 >> 0x18)
        }
        if (uint_bits_to_float(uint(c2da_mem[ent_4 + 172 + i_1 * 4]) | uint(c2da_mem[ent_4 + 172 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_4 + 172 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_4 + 172 + i_1 * 4 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[462568]) | uint(c2da_mem[462569]) << 0x8 | uint(c2da_mem[462570]) << 0x10 | uint(c2da_mem[462571]) << 0x18)) {
            let c2da_fresh87 : float = uint_bits_to_float(uint(c2da_mem[462568]) | uint(c2da_mem[462569]) << 0x8 | uint(c2da_mem[462570]) << 0x10 | uint(c2da_mem[462571]) << 0x18)
            let c2da_fresh88 : uint = float_bits_to_uint(c2da_fresh87)
            c2da_mem[ent_4 + 172 + i_1 * 4] = uint8(c2da_fresh88)
            c2da_mem[ent_4 + 172 + i_1 * 4 + 1] = uint8(c2da_fresh88 >> 0x8)
            c2da_mem[ent_4 + 172 + i_1 * 4 + 2] = uint8(c2da_fresh88 >> 0x10)
            c2da_mem[ent_4 + 172 + i_1 * 4 + 3] = uint8(c2da_fresh88 >> 0x18)
        } elif (uint_bits_to_float(uint(c2da_mem[ent_4 + 172 + i_1 * 4]) | uint(c2da_mem[ent_4 + 172 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_4 + 172 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_4 + 172 + i_1 * 4 + 3]) << 0x18) < -uint_bits_to_float(uint(c2da_mem[462568]) | uint(c2da_mem[462569]) << 0x8 | uint(c2da_mem[462570]) << 0x10 | uint(c2da_mem[462571]) << 0x18)) {
            let c2da_fresh89 : float = -uint_bits_to_float(uint(c2da_mem[462568]) | uint(c2da_mem[462569]) << 0x8 | uint(c2da_mem[462570]) << 0x10 | uint(c2da_mem[462571]) << 0x18)
            let c2da_fresh90 : uint = float_bits_to_uint(c2da_fresh89)
            c2da_mem[ent_4 + 172 + i_1 * 4] = uint8(c2da_fresh90)
            c2da_mem[ent_4 + 172 + i_1 * 4 + 1] = uint8(c2da_fresh90 >> 0x8)
            c2da_mem[ent_4 + 172 + i_1 * 4 + 2] = uint8(c2da_fresh90 >> 0x10)
            c2da_mem[ent_4 + 172 + i_1 * 4 + 3] = uint8(c2da_fresh90 >> 0x18)
        }
    }
    return
}
[export, sideeffects]
def SV_RunThink(var ent_5 : int) : uint {
    var thinktime : float = uint_bits_to_float(uint(c2da_mem[ent_5 + 292]) | uint(c2da_mem[ent_5 + 293]) << 0x8 | uint(c2da_mem[ent_5 + 294]) << 0x10 | uint(c2da_mem[ent_5 + 295]) << 0x18)
    if (thinktime <= 0.0 || double(thinktime) > uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20) + host_frametime) {
        return 1u
    }
    if (double(thinktime) < uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20)) {
        thinktime = float(uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20))
    }
    let c2da_fresh91 : float = 0.0
    let c2da_fresh92 : uint = float_bits_to_uint(c2da_fresh91)
    c2da_mem[ent_5 + 292] = uint8(c2da_fresh92)
    c2da_mem[ent_5 + 293] = uint8(c2da_fresh92 >> 0x8)
    c2da_mem[ent_5 + 294] = uint8(c2da_fresh92 >> 0x10)
    c2da_mem[ent_5 + 295] = uint8(c2da_fresh92 >> 0x18)
    let c2da_fresh93 : uint = float_bits_to_uint(thinktime)
    c2da_mem[pr_global_struct + 124] = uint8(c2da_fresh93)
    c2da_mem[pr_global_struct + 125] = uint8(c2da_fresh93 >> 0x8)
    c2da_mem[pr_global_struct + 126] = uint8(c2da_fresh93 >> 0x10)
    c2da_mem[pr_global_struct + 127] = uint8(c2da_fresh93 >> 0x18)
    let c2da_fresh94 : int = ent_5 - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    let c2da_fresh95 : uint = uint(c2da_fresh94)
    c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh95)
    c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh95 >> 0x8)
    c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh95 >> 0x10)
    c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh95 >> 0x18)
    let c2da_fresh96 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    let c2da_fresh97 : uint = uint(c2da_fresh96)
    c2da_mem[pr_global_struct + 116] = uint8(c2da_fresh97)
    c2da_mem[pr_global_struct + 117] = uint8(c2da_fresh97 >> 0x8)
    c2da_mem[pr_global_struct + 118] = uint8(c2da_fresh97 >> 0x10)
    c2da_mem[pr_global_struct + 119] = uint8(c2da_fresh97 >> 0x18)
    PR_ExecuteProgram(int(uint(c2da_mem[ent_5 + 284]) | uint(c2da_mem[ent_5 + 285]) << 0x8 | uint(c2da_mem[ent_5 + 286]) << 0x10 | uint(c2da_mem[ent_5 + 287]) << 0x18))
    return (uint(c2da_mem[ent_5]) | uint(c2da_mem[ent_5 + 1]) << 0x8 | uint(c2da_mem[ent_5 + 2]) << 0x10 | uint(c2da_mem[ent_5 + 3]) << 0x18) == 0u ? 1u : 0u
}
[export, sideeffects]
def SV_Physics_Step(var ent_6 : int) {
    var hitsound : uint
    if ((int(uint_bits_to_float(uint(c2da_mem[ent_6 + 412]) | uint(c2da_mem[ent_6 + 413]) << 0x8 | uint(c2da_mem[ent_6 + 414]) << 0x10 | uint(c2da_mem[ent_6 + 415]) << 0x18)) & (512 | 1 | 2)) == 0) {
        if (double(uint_bits_to_float(uint(c2da_mem[ent_6 + 172 + 2 * 4]) | uint(c2da_mem[ent_6 + 172 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_6 + 172 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_6 + 172 + 2 * 4 + 3]) << 0x18)) < double(uint_bits_to_float(uint(c2da_mem[462616]) | uint(c2da_mem[462617]) << 0x8 | uint(c2da_mem[462618]) << 0x10 | uint(c2da_mem[462619]) << 0x18)) * -0.1lf) {
            hitsound = 1u
        } else {
            hitsound = 0u
        }
        SV_AddGravity(ent_6)
        SV_CheckVelocity(ent_6)
        SV_FlyMove(ent_6, float(host_frametime), 0)
        SV_LinkEdict(ent_6, 1u)
        if ((int(uint_bits_to_float(uint(c2da_mem[ent_6 + 412]) | uint(c2da_mem[ent_6 + 413]) << 0x8 | uint(c2da_mem[ent_6 + 414]) << 0x10 | uint(c2da_mem[ent_6 + 415]) << 0x18)) & 512) != 0) {
            if (hitsound != 0u) {
                SV_StartSound(ent_6, 0, 736773, 255, 1.0)
            }
        }
    }
    SV_RunThink(ent_6)
    SV_CheckWaterTransition(ent_6)
    return
}
[export, sideeffects]
def SV_FlyMove(var ent_7 : int; var time : float; var steptrace : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = SV_FlyMove_c2da_frame(ent_7, time, steptrace, c2da_lin_enter(128))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def SV_Physics_Noclip(var ent_8 : int) {
    if (SV_RunThink(ent_8) == 0u) {
        return
    }
    VectorMA(ent_8 + 184, float(host_frametime), ent_8 + 196, ent_8 + 184)
    VectorMA(ent_8 + 148, float(host_frametime), ent_8 + 172, ent_8 + 148)
    SV_LinkEdict(ent_8, 0u)
    return
}
[export, sideeffects]
def SV_Physics_None(var ent_9 : int) {
    SV_RunThink(ent_9)
    return
}
[export, sideeffects]
def SV_Physics_Pusher(var ent_10 : int) {
    var thinktime_0 : float
    var oldltime : float
    var movetime : float
    oldltime = uint_bits_to_float(uint(c2da_mem[ent_10 + 136]) | uint(c2da_mem[ent_10 + 137]) << 0x8 | uint(c2da_mem[ent_10 + 138]) << 0x10 | uint(c2da_mem[ent_10 + 139]) << 0x18)
    thinktime_0 = uint_bits_to_float(uint(c2da_mem[ent_10 + 292]) | uint(c2da_mem[ent_10 + 293]) << 0x8 | uint(c2da_mem[ent_10 + 294]) << 0x10 | uint(c2da_mem[ent_10 + 295]) << 0x18)
    if (double(thinktime_0) < double(uint_bits_to_float(uint(c2da_mem[ent_10 + 136]) | uint(c2da_mem[ent_10 + 137]) << 0x8 | uint(c2da_mem[ent_10 + 138]) << 0x10 | uint(c2da_mem[ent_10 + 139]) << 0x18)) + host_frametime) {
        movetime = thinktime_0 - uint_bits_to_float(uint(c2da_mem[ent_10 + 136]) | uint(c2da_mem[ent_10 + 137]) << 0x8 | uint(c2da_mem[ent_10 + 138]) << 0x10 | uint(c2da_mem[ent_10 + 139]) << 0x18)
        if (movetime < 0.0) {
            movetime = 0.0
        }
    } else {
        movetime = float(host_frametime)
    }
    if (movetime != 0.0) {
        SV_PushMove(ent_10, movetime)
    }
    if (thinktime_0 > oldltime && thinktime_0 <= uint_bits_to_float(uint(c2da_mem[ent_10 + 136]) | uint(c2da_mem[ent_10 + 137]) << 0x8 | uint(c2da_mem[ent_10 + 138]) << 0x10 | uint(c2da_mem[ent_10 + 139]) << 0x18)) {
        let c2da_fresh172 : float = 0.0
        let c2da_fresh173 : uint = float_bits_to_uint(c2da_fresh172)
        c2da_mem[ent_10 + 292] = uint8(c2da_fresh173)
        c2da_mem[ent_10 + 293] = uint8(c2da_fresh173 >> 0x8)
        c2da_mem[ent_10 + 294] = uint8(c2da_fresh173 >> 0x10)
        c2da_mem[ent_10 + 295] = uint8(c2da_fresh173 >> 0x18)
        let c2da_fresh174 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20))
        let c2da_fresh175 : uint = float_bits_to_uint(c2da_fresh174)
        c2da_mem[pr_global_struct + 124] = uint8(c2da_fresh175)
        c2da_mem[pr_global_struct + 125] = uint8(c2da_fresh175 >> 0x8)
        c2da_mem[pr_global_struct + 126] = uint8(c2da_fresh175 >> 0x10)
        c2da_mem[pr_global_struct + 127] = uint8(c2da_fresh175 >> 0x18)
        let c2da_fresh176 : int = ent_10 - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh177 : uint = uint(c2da_fresh176)
        c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh177)
        c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh177 >> 0x8)
        c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh177 >> 0x10)
        c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh177 >> 0x18)
        let c2da_fresh178 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh179 : uint = uint(c2da_fresh178)
        c2da_mem[pr_global_struct + 116] = uint8(c2da_fresh179)
        c2da_mem[pr_global_struct + 117] = uint8(c2da_fresh179 >> 0x8)
        c2da_mem[pr_global_struct + 118] = uint8(c2da_fresh179 >> 0x10)
        c2da_mem[pr_global_struct + 119] = uint8(c2da_fresh179 >> 0x18)
        PR_ExecuteProgram(int(uint(c2da_mem[ent_10 + 284]) | uint(c2da_mem[ent_10 + 285]) << 0x8 | uint(c2da_mem[ent_10 + 286]) << 0x10 | uint(c2da_mem[ent_10 + 287]) << 0x18))
        if ((uint(c2da_mem[ent_10]) | uint(c2da_mem[ent_10 + 1]) << 0x8 | uint(c2da_mem[ent_10 + 2]) << 0x10 | uint(c2da_mem[ent_10 + 3]) << 0x18) != 0u) {
            return
        }
    }
    return
}
[export, sideeffects]
def SV_PushMove(var pusher : int; var movetime_0 : float) {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_PushMove_c2da_frame(pusher, movetime_0, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def SV_Physics_Client(var ent_11 : int; var num : int) {
    var c2da_fresh239 : int
    let c2da_fresh234 : int = svs.clients + (num - 1) * 8288
    if ((uint(c2da_mem[c2da_fresh234]) | uint(c2da_mem[c2da_fresh234 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh234 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh234 + 3]) << 0x18) == 0u) {
        return
    }
    let c2da_fresh235 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20))
    let c2da_fresh236 : uint = float_bits_to_uint(c2da_fresh235)
    c2da_mem[pr_global_struct + 124] = uint8(c2da_fresh236)
    c2da_mem[pr_global_struct + 125] = uint8(c2da_fresh236 >> 0x8)
    c2da_mem[pr_global_struct + 126] = uint8(c2da_fresh236 >> 0x10)
    c2da_mem[pr_global_struct + 127] = uint8(c2da_fresh236 >> 0x18)
    let c2da_fresh237 : int = ent_11 - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    let c2da_fresh238 : uint = uint(c2da_fresh237)
    c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh238)
    c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh238 >> 0x8)
    c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh238 >> 0x10)
    c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh238 >> 0x18)
    PR_ExecuteProgram(int(uint(c2da_mem[pr_global_struct + 336]) | uint(c2da_mem[pr_global_struct + 337]) << 0x8 | uint(c2da_mem[pr_global_struct + 338]) << 0x10 | uint(c2da_mem[pr_global_struct + 339]) << 0x18))
    SV_CheckVelocity(ent_11)
    c2da_fresh239 = int(uint_bits_to_float(uint(c2da_mem[ent_11 + 140]) | uint(c2da_mem[ent_11 + 141]) << 0x8 | uint(c2da_mem[ent_11 + 142]) << 0x10 | uint(c2da_mem[ent_11 + 143]) << 0x18))
    if (c2da_fresh239 == 0) {
        if (SV_RunThink(ent_11) == 0u) {
            return
        }
    } elif (c2da_fresh239 == 3) {
        if (SV_RunThink(ent_11) == 0u) {
            return
        }
        if (SV_CheckWater(ent_11) == 0u && (int(uint_bits_to_float(uint(c2da_mem[ent_11 + 412]) | uint(c2da_mem[ent_11 + 413]) << 0x8 | uint(c2da_mem[ent_11 + 414]) << 0x10 | uint(c2da_mem[ent_11 + 415]) << 0x18)) & 2048) == 0) {
            SV_AddGravity(ent_11)
        }
        SV_CheckStuck(ent_11)
        SV_WalkMove(ent_11)
    } elif (c2da_fresh239 == 6 || c2da_fresh239 == 10) {
        SV_Physics_Toss(ent_11)
    } elif (c2da_fresh239 == 5) {
        if (SV_RunThink(ent_11) == 0u) {
            return
        }
        SV_FlyMove(ent_11, float(host_frametime), 0)
    } elif (c2da_fresh239 == 8) {
        if (SV_RunThink(ent_11) == 0u) {
            return
        }
        VectorMA(ent_11 + 148, float(host_frametime), ent_11 + 172, ent_11 + 148)
    } else {
        Sys_Error(736813, [C2daVaArg(tag = 1, i64 = int64(int(uint_bits_to_float(uint(c2da_mem[ent_11 + 140]) | uint(c2da_mem[ent_11 + 141]) << 0x8 | uint(c2da_mem[ent_11 + 142]) << 0x10 | uint(c2da_mem[ent_11 + 143]) << 0x18))), f64 = 0.0lf, raw = 0x0)])
    }
    SV_LinkEdict(ent_11, 1u)
    let c2da_fresh240 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20))
    let c2da_fresh241 : uint = float_bits_to_uint(c2da_fresh240)
    c2da_mem[pr_global_struct + 124] = uint8(c2da_fresh241)
    c2da_mem[pr_global_struct + 125] = uint8(c2da_fresh241 >> 0x8)
    c2da_mem[pr_global_struct + 126] = uint8(c2da_fresh241 >> 0x10)
    c2da_mem[pr_global_struct + 127] = uint8(c2da_fresh241 >> 0x18)
    let c2da_fresh242 : int = ent_11 - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    let c2da_fresh243 : uint = uint(c2da_fresh242)
    c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh243)
    c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh243 >> 0x8)
    c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh243 >> 0x10)
    c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh243 >> 0x18)
    PR_ExecuteProgram(int(uint(c2da_mem[pr_global_struct + 340]) | uint(c2da_mem[pr_global_struct + 341]) << 0x8 | uint(c2da_mem[pr_global_struct + 342]) << 0x10 | uint(c2da_mem[pr_global_struct + 343]) << 0x18))
    return
}
[export, sideeffects]
def SV_WalkMove(var ent_12 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_WalkMove_c2da_frame(ent_12, c2da_lin_enter(112))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def SV_WallFriction(var ent_13 : int; var trace_1 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_WallFriction_c2da_frame(ent_13, trace_1, c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def SV_TryUnstick(var ent_14 : int; var oldvel : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = SV_TryUnstick_c2da_frame(ent_14, oldvel, c2da_lin_enter(80))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def SV_CheckStuck(var ent_15 : int) {
    var i_6 : int
    var j_0 : int
    var org : vec3_t
    if (SV_TestEntityPosition(ent_15) == 0) {
        let c2da_fresh356 : float = uint_bits_to_float(uint(c2da_mem[ent_15 + 148 + 0 * 4]) | uint(c2da_mem[ent_15 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_15 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_15 + 148 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh357 : uint = float_bits_to_uint(c2da_fresh356)
        c2da_mem[ent_15 + 160 + 0 * 4] = uint8(c2da_fresh357)
        c2da_mem[ent_15 + 160 + 0 * 4 + 1] = uint8(c2da_fresh357 >> 0x8)
        c2da_mem[ent_15 + 160 + 0 * 4 + 2] = uint8(c2da_fresh357 >> 0x10)
        c2da_mem[ent_15 + 160 + 0 * 4 + 3] = uint8(c2da_fresh357 >> 0x18)
        let c2da_fresh358 : float = uint_bits_to_float(uint(c2da_mem[ent_15 + 148 + 1 * 4]) | uint(c2da_mem[ent_15 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_15 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_15 + 148 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh359 : uint = float_bits_to_uint(c2da_fresh358)
        c2da_mem[ent_15 + 160 + 1 * 4] = uint8(c2da_fresh359)
        c2da_mem[ent_15 + 160 + 1 * 4 + 1] = uint8(c2da_fresh359 >> 0x8)
        c2da_mem[ent_15 + 160 + 1 * 4 + 2] = uint8(c2da_fresh359 >> 0x10)
        c2da_mem[ent_15 + 160 + 1 * 4 + 3] = uint8(c2da_fresh359 >> 0x18)
        let c2da_fresh360 : float = uint_bits_to_float(uint(c2da_mem[ent_15 + 148 + 2 * 4]) | uint(c2da_mem[ent_15 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_15 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_15 + 148 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh361 : uint = float_bits_to_uint(c2da_fresh360)
        c2da_mem[ent_15 + 160 + 2 * 4] = uint8(c2da_fresh361)
        c2da_mem[ent_15 + 160 + 2 * 4 + 1] = uint8(c2da_fresh361 >> 0x8)
        c2da_mem[ent_15 + 160 + 2 * 4 + 2] = uint8(c2da_fresh361 >> 0x10)
        c2da_mem[ent_15 + 160 + 2 * 4 + 3] = uint8(c2da_fresh361 >> 0x18)
        return
    }
    org[0] = uint_bits_to_float(uint(c2da_mem[ent_15 + 148 + 0 * 4]) | uint(c2da_mem[ent_15 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_15 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_15 + 148 + 0 * 4 + 3]) << 0x18)
    org[1] = uint_bits_to_float(uint(c2da_mem[ent_15 + 148 + 1 * 4]) | uint(c2da_mem[ent_15 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_15 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_15 + 148 + 1 * 4 + 3]) << 0x18)
    org[2] = uint_bits_to_float(uint(c2da_mem[ent_15 + 148 + 2 * 4]) | uint(c2da_mem[ent_15 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_15 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_15 + 148 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh362 : float = uint_bits_to_float(uint(c2da_mem[ent_15 + 160 + 0 * 4]) | uint(c2da_mem[ent_15 + 160 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_15 + 160 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_15 + 160 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh363 : uint = float_bits_to_uint(c2da_fresh362)
    c2da_mem[ent_15 + 148 + 0 * 4] = uint8(c2da_fresh363)
    c2da_mem[ent_15 + 148 + 0 * 4 + 1] = uint8(c2da_fresh363 >> 0x8)
    c2da_mem[ent_15 + 148 + 0 * 4 + 2] = uint8(c2da_fresh363 >> 0x10)
    c2da_mem[ent_15 + 148 + 0 * 4 + 3] = uint8(c2da_fresh363 >> 0x18)
    let c2da_fresh364 : float = uint_bits_to_float(uint(c2da_mem[ent_15 + 160 + 1 * 4]) | uint(c2da_mem[ent_15 + 160 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_15 + 160 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_15 + 160 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh365 : uint = float_bits_to_uint(c2da_fresh364)
    c2da_mem[ent_15 + 148 + 1 * 4] = uint8(c2da_fresh365)
    c2da_mem[ent_15 + 148 + 1 * 4 + 1] = uint8(c2da_fresh365 >> 0x8)
    c2da_mem[ent_15 + 148 + 1 * 4 + 2] = uint8(c2da_fresh365 >> 0x10)
    c2da_mem[ent_15 + 148 + 1 * 4 + 3] = uint8(c2da_fresh365 >> 0x18)
    let c2da_fresh366 : float = uint_bits_to_float(uint(c2da_mem[ent_15 + 160 + 2 * 4]) | uint(c2da_mem[ent_15 + 160 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_15 + 160 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_15 + 160 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh367 : uint = float_bits_to_uint(c2da_fresh366)
    c2da_mem[ent_15 + 148 + 2 * 4] = uint8(c2da_fresh367)
    c2da_mem[ent_15 + 148 + 2 * 4 + 1] = uint8(c2da_fresh367 >> 0x8)
    c2da_mem[ent_15 + 148 + 2 * 4 + 2] = uint8(c2da_fresh367 >> 0x10)
    c2da_mem[ent_15 + 148 + 2 * 4 + 3] = uint8(c2da_fresh367 >> 0x18)
    if (SV_TestEntityPosition(ent_15) == 0) {
        Con_DPrintf(736848, [])
        SV_LinkEdict(ent_15, 1u)
        return
    }
    for (z in range(0, 18)) {
        i_6 = -1
        while (i_6 <= 1) {
            j_0 = -1
            while (j_0 <= 1) {
                let c2da_fresh368 : float = org[0] + float(i_6)
                let c2da_fresh369 : uint = float_bits_to_uint(c2da_fresh368)
                c2da_mem[ent_15 + 148 + 0 * 4] = uint8(c2da_fresh369)
                c2da_mem[ent_15 + 148 + 0 * 4 + 1] = uint8(c2da_fresh369 >> 0x8)
                c2da_mem[ent_15 + 148 + 0 * 4 + 2] = uint8(c2da_fresh369 >> 0x10)
                c2da_mem[ent_15 + 148 + 0 * 4 + 3] = uint8(c2da_fresh369 >> 0x18)
                let c2da_fresh370 : float = org[1] + float(j_0)
                let c2da_fresh371 : uint = float_bits_to_uint(c2da_fresh370)
                c2da_mem[ent_15 + 148 + 1 * 4] = uint8(c2da_fresh371)
                c2da_mem[ent_15 + 148 + 1 * 4 + 1] = uint8(c2da_fresh371 >> 0x8)
                c2da_mem[ent_15 + 148 + 1 * 4 + 2] = uint8(c2da_fresh371 >> 0x10)
                c2da_mem[ent_15 + 148 + 1 * 4 + 3] = uint8(c2da_fresh371 >> 0x18)
                let c2da_fresh372 : float = org[2] + float(z)
                let c2da_fresh373 : uint = float_bits_to_uint(c2da_fresh372)
                c2da_mem[ent_15 + 148 + 2 * 4] = uint8(c2da_fresh373)
                c2da_mem[ent_15 + 148 + 2 * 4 + 1] = uint8(c2da_fresh373 >> 0x8)
                c2da_mem[ent_15 + 148 + 2 * 4 + 2] = uint8(c2da_fresh373 >> 0x10)
                c2da_mem[ent_15 + 148 + 2 * 4 + 3] = uint8(c2da_fresh373 >> 0x18)
                if (SV_TestEntityPosition(ent_15) == 0) {
                    Con_DPrintf(736848, [])
                    SV_LinkEdict(ent_15, 1u)
                    return
                }
                j_0++
            }
            i_6++
        }
    }
    let c2da_fresh374 : float = org[0]
    let c2da_fresh375 : uint = float_bits_to_uint(c2da_fresh374)
    c2da_mem[ent_15 + 148 + 0 * 4] = uint8(c2da_fresh375)
    c2da_mem[ent_15 + 148 + 0 * 4 + 1] = uint8(c2da_fresh375 >> 0x8)
    c2da_mem[ent_15 + 148 + 0 * 4 + 2] = uint8(c2da_fresh375 >> 0x10)
    c2da_mem[ent_15 + 148 + 0 * 4 + 3] = uint8(c2da_fresh375 >> 0x18)
    let c2da_fresh376 : float = org[1]
    let c2da_fresh377 : uint = float_bits_to_uint(c2da_fresh376)
    c2da_mem[ent_15 + 148 + 1 * 4] = uint8(c2da_fresh377)
    c2da_mem[ent_15 + 148 + 1 * 4 + 1] = uint8(c2da_fresh377 >> 0x8)
    c2da_mem[ent_15 + 148 + 1 * 4 + 2] = uint8(c2da_fresh377 >> 0x10)
    c2da_mem[ent_15 + 148 + 1 * 4 + 3] = uint8(c2da_fresh377 >> 0x18)
    let c2da_fresh378 : float = org[2]
    let c2da_fresh379 : uint = float_bits_to_uint(c2da_fresh378)
    c2da_mem[ent_15 + 148 + 2 * 4] = uint8(c2da_fresh379)
    c2da_mem[ent_15 + 148 + 2 * 4 + 1] = uint8(c2da_fresh379 >> 0x8)
    c2da_mem[ent_15 + 148 + 2 * 4 + 2] = uint8(c2da_fresh379 >> 0x10)
    c2da_mem[ent_15 + 148 + 2 * 4 + 3] = uint8(c2da_fresh379 >> 0x18)
    Con_DPrintf(736858, [])
    return
}
[export, sideeffects]
def SV_CheckWater(var ent_16 : int) : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = SV_CheckWater_c2da_frame(ent_16, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def SV_CheckAllEnts() {
    var e_0 : int
    var check_0 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(pr_edict_size)
    e_0 = 1
    while (e_0 < int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        if ((uint(c2da_mem[check_0]) | uint(c2da_mem[check_0 + 1]) << 0x8 | uint(c2da_mem[check_0 + 2]) << 0x10 | uint(c2da_mem[check_0 + 3]) << 0x18) != 0u) {
            e_0++
            check_0 += int(pr_edict_size)
            continue
        }
        if (uint_bits_to_float(uint(c2da_mem[check_0 + 140]) | uint(c2da_mem[check_0 + 141]) << 0x8 | uint(c2da_mem[check_0 + 142]) << 0x10 | uint(c2da_mem[check_0 + 143]) << 0x18) == 7.0 || uint_bits_to_float(uint(c2da_mem[check_0 + 140]) | uint(c2da_mem[check_0 + 141]) << 0x8 | uint(c2da_mem[check_0 + 142]) << 0x10 | uint(c2da_mem[check_0 + 143]) << 0x18) == 0.0 || uint_bits_to_float(uint(c2da_mem[check_0 + 140]) | uint(c2da_mem[check_0 + 141]) << 0x8 | uint(c2da_mem[check_0 + 142]) << 0x10 | uint(c2da_mem[check_0 + 143]) << 0x18) == 8.0) {
            e_0++
            check_0 += int(pr_edict_size)
            continue
        }
        if (SV_TestEntityPosition(check_0) != 0) {
            Con_Printf(736876, [])
        }
        e_0++
        check_0 += int(pr_edict_size)
    }
    return
}
[sideeffects]
def private SV_Physics_Toss_c2da_frame(var ent_0 : int; c2da_fp : int) {
    var backoff : float
    if (SV_RunThink(ent_0) == 0u) {
        return
    }
    if ((int(uint_bits_to_float(uint(c2da_mem[ent_0 + 412]) | uint(c2da_mem[ent_0 + 413]) << 0x8 | uint(c2da_mem[ent_0 + 414]) << 0x10 | uint(c2da_mem[ent_0 + 415]) << 0x18)) & 512) != 0) {
        return
    }
    SV_CheckVelocity(ent_0)
    if (uint_bits_to_float(uint(c2da_mem[ent_0 + 140]) | uint(c2da_mem[ent_0 + 141]) << 0x8 | uint(c2da_mem[ent_0 + 142]) << 0x10 | uint(c2da_mem[ent_0 + 143]) << 0x18) != 5.0 && uint_bits_to_float(uint(c2da_mem[ent_0 + 140]) | uint(c2da_mem[ent_0 + 141]) << 0x8 | uint(c2da_mem[ent_0 + 142]) << 0x10 | uint(c2da_mem[ent_0 + 143]) << 0x18) != 9.0) {
        SV_AddGravity(ent_0)
    }
    VectorMA(ent_0 + 184, float(host_frametime), ent_0 + 196, ent_0 + 184)
    VectorScale(ent_0 + 172, float(host_frametime), c2da_fp)
    var c2da_fresh11 : trace_t = SV_PushEntity(ent_0, c2da_fp)
    let c2da_fresh12 : uint = c2da_fresh11.allsolid
    c2da_mem[c2da_fp + 16] = uint8(c2da_fresh12)
    c2da_mem[c2da_fp + 17] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[c2da_fp + 18] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[c2da_fp + 19] = uint8(c2da_fresh12 >> 0x18)
    let c2da_fresh13 : uint = c2da_fresh11.startsolid
    c2da_mem[c2da_fp + 20] = uint8(c2da_fresh13)
    c2da_mem[c2da_fp + 21] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[c2da_fp + 22] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[c2da_fp + 23] = uint8(c2da_fresh13 >> 0x18)
    let c2da_fresh14 : uint = c2da_fresh11.inopen
    c2da_mem[c2da_fp + 24] = uint8(c2da_fresh14)
    c2da_mem[c2da_fp + 25] = uint8(c2da_fresh14 >> 0x8)
    c2da_mem[c2da_fp + 26] = uint8(c2da_fresh14 >> 0x10)
    c2da_mem[c2da_fp + 27] = uint8(c2da_fresh14 >> 0x18)
    let c2da_fresh15 : uint = c2da_fresh11.inwater
    c2da_mem[c2da_fp + 28] = uint8(c2da_fresh15)
    c2da_mem[c2da_fp + 29] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[c2da_fp + 30] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[c2da_fp + 31] = uint8(c2da_fresh15 >> 0x18)
    let c2da_fresh16 : uint = float_bits_to_uint(c2da_fresh11.fraction)
    c2da_mem[c2da_fp + 32] = uint8(c2da_fresh16)
    c2da_mem[c2da_fp + 33] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[c2da_fp + 34] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[c2da_fp + 35] = uint8(c2da_fresh16 >> 0x18)
    let c2da_fresh17 : uint = float_bits_to_uint(c2da_fresh11.endpos[0])
    c2da_mem[c2da_fp + 36] = uint8(c2da_fresh17)
    c2da_mem[c2da_fp + 37] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[c2da_fp + 38] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[c2da_fp + 39] = uint8(c2da_fresh17 >> 0x18)
    let c2da_fresh18 : uint = float_bits_to_uint(c2da_fresh11.endpos[1])
    c2da_mem[c2da_fp + 40] = uint8(c2da_fresh18)
    c2da_mem[c2da_fp + 41] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[c2da_fp + 42] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[c2da_fp + 43] = uint8(c2da_fresh18 >> 0x18)
    let c2da_fresh19 : uint = float_bits_to_uint(c2da_fresh11.endpos[2])
    c2da_mem[c2da_fp + 44] = uint8(c2da_fresh19)
    c2da_mem[c2da_fp + 45] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[c2da_fp + 46] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[c2da_fp + 47] = uint8(c2da_fresh19 >> 0x18)
    let c2da_fresh20 : uint = float_bits_to_uint(c2da_fresh11.plane.normal[0])
    c2da_mem[c2da_fp + 48] = uint8(c2da_fresh20)
    c2da_mem[c2da_fp + 49] = uint8(c2da_fresh20 >> 0x8)
    c2da_mem[c2da_fp + 50] = uint8(c2da_fresh20 >> 0x10)
    c2da_mem[c2da_fp + 51] = uint8(c2da_fresh20 >> 0x18)
    let c2da_fresh21 : uint = float_bits_to_uint(c2da_fresh11.plane.normal[1])
    c2da_mem[c2da_fp + 52] = uint8(c2da_fresh21)
    c2da_mem[c2da_fp + 53] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[c2da_fp + 54] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[c2da_fp + 55] = uint8(c2da_fresh21 >> 0x18)
    let c2da_fresh22 : uint = float_bits_to_uint(c2da_fresh11.plane.normal[2])
    c2da_mem[c2da_fp + 56] = uint8(c2da_fresh22)
    c2da_mem[c2da_fp + 57] = uint8(c2da_fresh22 >> 0x8)
    c2da_mem[c2da_fp + 58] = uint8(c2da_fresh22 >> 0x10)
    c2da_mem[c2da_fp + 59] = uint8(c2da_fresh22 >> 0x18)
    let c2da_fresh23 : uint = float_bits_to_uint(c2da_fresh11.plane.dist)
    c2da_mem[c2da_fp + 60] = uint8(c2da_fresh23)
    c2da_mem[c2da_fp + 61] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[c2da_fp + 62] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[c2da_fp + 63] = uint8(c2da_fresh23 >> 0x18)
    let c2da_fresh24 : uint = uint(c2da_fresh11.ent)
    c2da_mem[c2da_fp + 64] = uint8(c2da_fresh24)
    c2da_mem[c2da_fp + 65] = uint8(c2da_fresh24 >> 0x8)
    c2da_mem[c2da_fp + 66] = uint8(c2da_fresh24 >> 0x10)
    c2da_mem[c2da_fp + 67] = uint8(c2da_fresh24 >> 0x18)
    c2da_mem[c2da_fp + 68] = 0u8
    c2da_mem[c2da_fp + 69] = 0u8
    c2da_mem[c2da_fp + 70] = 0u8
    c2da_mem[c2da_fp + 71] = 0u8
    if (uint_bits_to_float(uint(c2da_mem[c2da_fp + 32]) | uint(c2da_mem[c2da_fp + 33]) << 0x8 | uint(c2da_mem[c2da_fp + 34]) << 0x10 | uint(c2da_mem[c2da_fp + 35]) << 0x18) == 1.0) {
        return
    }
    if ((uint(c2da_mem[ent_0]) | uint(c2da_mem[ent_0 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 3]) << 0x18) != 0u) {
        return
    }
    if (uint_bits_to_float(uint(c2da_mem[ent_0 + 140]) | uint(c2da_mem[ent_0 + 141]) << 0x8 | uint(c2da_mem[ent_0 + 142]) << 0x10 | uint(c2da_mem[ent_0 + 143]) << 0x18) == 10.0) {
        backoff = 1.5
    } else {
        backoff = 1.0
    }
    ClipVelocity(ent_0 + 172, c2da_fp + 48, ent_0 + 172, backoff)
    if (double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 2 * 4]) | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 3]) << 0x18)) > 0.7lf) {
        if (uint_bits_to_float(uint(c2da_mem[ent_0 + 172 + 2 * 4]) | uint(c2da_mem[ent_0 + 172 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 172 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 172 + 2 * 4 + 3]) << 0x18) < 60.0 || uint_bits_to_float(uint(c2da_mem[ent_0 + 140]) | uint(c2da_mem[ent_0 + 141]) << 0x8 | uint(c2da_mem[ent_0 + 142]) << 0x10 | uint(c2da_mem[ent_0 + 143]) << 0x18) != 10.0) {
            let c2da_fresh25 : float = float(int(uint_bits_to_float(uint(c2da_mem[ent_0 + 412]) | uint(c2da_mem[ent_0 + 413]) << 0x8 | uint(c2da_mem[ent_0 + 414]) << 0x10 | uint(c2da_mem[ent_0 + 415]) << 0x18)) | 512)
            let c2da_fresh26 : uint = float_bits_to_uint(c2da_fresh25)
            c2da_mem[ent_0 + 412] = uint8(c2da_fresh26)
            c2da_mem[ent_0 + 413] = uint8(c2da_fresh26 >> 0x8)
            c2da_mem[ent_0 + 414] = uint8(c2da_fresh26 >> 0x10)
            c2da_mem[ent_0 + 415] = uint8(c2da_fresh26 >> 0x18)
            let c2da_fresh27 : int = int(uint(c2da_mem[c2da_fp + 64]) | uint(c2da_mem[c2da_fp + 65]) << 0x8 | uint(c2da_mem[c2da_fp + 66]) << 0x10 | uint(c2da_mem[c2da_fp + 67]) << 0x18) - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
            let c2da_fresh28 : uint = uint(c2da_fresh27)
            c2da_mem[ent_0 + 296] = uint8(c2da_fresh28)
            c2da_mem[ent_0 + 297] = uint8(c2da_fresh28 >> 0x8)
            c2da_mem[ent_0 + 298] = uint8(c2da_fresh28 >> 0x10)
            c2da_mem[ent_0 + 299] = uint8(c2da_fresh28 >> 0x18)
            let c2da_fresh29 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18)
            let c2da_fresh30 : uint = float_bits_to_uint(c2da_fresh29)
            c2da_mem[ent_0 + 172 + 0 * 4] = uint8(c2da_fresh30)
            c2da_mem[ent_0 + 172 + 0 * 4 + 1] = uint8(c2da_fresh30 >> 0x8)
            c2da_mem[ent_0 + 172 + 0 * 4 + 2] = uint8(c2da_fresh30 >> 0x10)
            c2da_mem[ent_0 + 172 + 0 * 4 + 3] = uint8(c2da_fresh30 >> 0x18)
            let c2da_fresh31 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18)
            let c2da_fresh32 : uint = float_bits_to_uint(c2da_fresh31)
            c2da_mem[ent_0 + 172 + 1 * 4] = uint8(c2da_fresh32)
            c2da_mem[ent_0 + 172 + 1 * 4 + 1] = uint8(c2da_fresh32 >> 0x8)
            c2da_mem[ent_0 + 172 + 1 * 4 + 2] = uint8(c2da_fresh32 >> 0x10)
            c2da_mem[ent_0 + 172 + 1 * 4 + 3] = uint8(c2da_fresh32 >> 0x18)
            let c2da_fresh33 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh34 : uint = float_bits_to_uint(c2da_fresh33)
            c2da_mem[ent_0 + 172 + 2 * 4] = uint8(c2da_fresh34)
            c2da_mem[ent_0 + 172 + 2 * 4 + 1] = uint8(c2da_fresh34 >> 0x8)
            c2da_mem[ent_0 + 172 + 2 * 4 + 2] = uint8(c2da_fresh34 >> 0x10)
            c2da_mem[ent_0 + 172 + 2 * 4 + 3] = uint8(c2da_fresh34 >> 0x18)
            let c2da_fresh35 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18)
            let c2da_fresh36 : uint = float_bits_to_uint(c2da_fresh35)
            c2da_mem[ent_0 + 196 + 0 * 4] = uint8(c2da_fresh36)
            c2da_mem[ent_0 + 196 + 0 * 4 + 1] = uint8(c2da_fresh36 >> 0x8)
            c2da_mem[ent_0 + 196 + 0 * 4 + 2] = uint8(c2da_fresh36 >> 0x10)
            c2da_mem[ent_0 + 196 + 0 * 4 + 3] = uint8(c2da_fresh36 >> 0x18)
            let c2da_fresh37 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18)
            let c2da_fresh38 : uint = float_bits_to_uint(c2da_fresh37)
            c2da_mem[ent_0 + 196 + 1 * 4] = uint8(c2da_fresh38)
            c2da_mem[ent_0 + 196 + 1 * 4 + 1] = uint8(c2da_fresh38 >> 0x8)
            c2da_mem[ent_0 + 196 + 1 * 4 + 2] = uint8(c2da_fresh38 >> 0x10)
            c2da_mem[ent_0 + 196 + 1 * 4 + 3] = uint8(c2da_fresh38 >> 0x18)
            let c2da_fresh39 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh40 : uint = float_bits_to_uint(c2da_fresh39)
            c2da_mem[ent_0 + 196 + 2 * 4] = uint8(c2da_fresh40)
            c2da_mem[ent_0 + 196 + 2 * 4 + 1] = uint8(c2da_fresh40 >> 0x8)
            c2da_mem[ent_0 + 196 + 2 * 4 + 2] = uint8(c2da_fresh40 >> 0x10)
            c2da_mem[ent_0 + 196 + 2 * 4 + 3] = uint8(c2da_fresh40 >> 0x18)
        }
    }
    SV_CheckWaterTransition(ent_0)
    return
}
[sideeffects]
def private SV_PushEntity_c2da_frame(var ent_2 : int; var push_0 : int; c2da_fp : int) : trace_t {
    var trace : trace_t
    let c2da_fresh57 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 148 + 0 * 4]) | uint(c2da_mem[ent_2 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 148 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[push_0 + 0 * 4]) | uint(c2da_mem[push_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[push_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[push_0 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh58 : uint = float_bits_to_uint(c2da_fresh57)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh58)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh58 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh58 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh58 >> 0x18)
    let c2da_fresh59 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 148 + 1 * 4]) | uint(c2da_mem[ent_2 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 148 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[push_0 + 1 * 4]) | uint(c2da_mem[push_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[push_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[push_0 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh60 : uint = float_bits_to_uint(c2da_fresh59)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh60)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh60 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh60 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh60 >> 0x18)
    let c2da_fresh61 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 148 + 2 * 4]) | uint(c2da_mem[ent_2 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[push_0 + 2 * 4]) | uint(c2da_mem[push_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[push_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[push_0 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh62 : uint = float_bits_to_uint(c2da_fresh61)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh62)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh62 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh62 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh62 >> 0x18)
    if (uint_bits_to_float(uint(c2da_mem[ent_2 + 140]) | uint(c2da_mem[ent_2 + 141]) << 0x8 | uint(c2da_mem[ent_2 + 142]) << 0x10 | uint(c2da_mem[ent_2 + 143]) << 0x18) == 9.0) {
        trace = SV_Move(ent_2 + 148, ent_2 + 240, ent_2 + 252, c2da_fp, 2, ent_2)
    } elif (uint_bits_to_float(uint(c2da_mem[ent_2 + 144]) | uint(c2da_mem[ent_2 + 145]) << 0x8 | uint(c2da_mem[ent_2 + 146]) << 0x10 | uint(c2da_mem[ent_2 + 147]) << 0x18) == 1.0 || uint_bits_to_float(uint(c2da_mem[ent_2 + 144]) | uint(c2da_mem[ent_2 + 145]) << 0x8 | uint(c2da_mem[ent_2 + 146]) << 0x10 | uint(c2da_mem[ent_2 + 147]) << 0x18) == 0.0) {
        trace = SV_Move(ent_2 + 148, ent_2 + 240, ent_2 + 252, c2da_fp, 1, ent_2)
    } else {
        trace = SV_Move(ent_2 + 148, ent_2 + 240, ent_2 + 252, c2da_fp, 0, ent_2)
    }
    let c2da_fresh63 : float = trace.endpos[0]
    let c2da_fresh64 : uint = float_bits_to_uint(c2da_fresh63)
    c2da_mem[ent_2 + 148 + 0 * 4] = uint8(c2da_fresh64)
    c2da_mem[ent_2 + 148 + 0 * 4 + 1] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[ent_2 + 148 + 0 * 4 + 2] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[ent_2 + 148 + 0 * 4 + 3] = uint8(c2da_fresh64 >> 0x18)
    let c2da_fresh65 : float = trace.endpos[1]
    let c2da_fresh66 : uint = float_bits_to_uint(c2da_fresh65)
    c2da_mem[ent_2 + 148 + 1 * 4] = uint8(c2da_fresh66)
    c2da_mem[ent_2 + 148 + 1 * 4 + 1] = uint8(c2da_fresh66 >> 0x8)
    c2da_mem[ent_2 + 148 + 1 * 4 + 2] = uint8(c2da_fresh66 >> 0x10)
    c2da_mem[ent_2 + 148 + 1 * 4 + 3] = uint8(c2da_fresh66 >> 0x18)
    let c2da_fresh67 : float = trace.endpos[2]
    let c2da_fresh68 : uint = float_bits_to_uint(c2da_fresh67)
    c2da_mem[ent_2 + 148 + 2 * 4] = uint8(c2da_fresh68)
    c2da_mem[ent_2 + 148 + 2 * 4 + 1] = uint8(c2da_fresh68 >> 0x8)
    c2da_mem[ent_2 + 148 + 2 * 4 + 2] = uint8(c2da_fresh68 >> 0x10)
    c2da_mem[ent_2 + 148 + 2 * 4 + 3] = uint8(c2da_fresh68 >> 0x18)
    SV_LinkEdict(ent_2, 1u)
    if (trace.ent != 0) {
        SV_Impact(ent_2, trace.ent)
    }
    return trace
}
[sideeffects]
def private SV_FlyMove_c2da_frame(var ent_7 : int; var time : float; var steptrace : int; c2da_fp : int) : int {
    var numbumps : int
    var d : float
    var numplanes : int
    var primal_velocity : vec3_t
    var i_2 : int
    var j : int
    var trace_0 : trace_t
    var time_left : float
    var blocked_0 : int
    numbumps = 4
    blocked_0 = 0
    let c2da_fresh98 : float = uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 0 * 4]) | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh99 : uint = float_bits_to_uint(c2da_fresh98)
    c2da_mem[c2da_fp + 16 + 0 * 4] = uint8(c2da_fresh99)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 1] = uint8(c2da_fresh99 >> 0x8)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 2] = uint8(c2da_fresh99 >> 0x10)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 3] = uint8(c2da_fresh99 >> 0x18)
    let c2da_fresh100 : float = uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 1 * 4]) | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh101 : uint = float_bits_to_uint(c2da_fresh100)
    c2da_mem[c2da_fp + 16 + 1 * 4] = uint8(c2da_fresh101)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 1] = uint8(c2da_fresh101 >> 0x8)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 2] = uint8(c2da_fresh101 >> 0x10)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 3] = uint8(c2da_fresh101 >> 0x18)
    let c2da_fresh102 : float = uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 2 * 4]) | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh103 : uint = float_bits_to_uint(c2da_fresh102)
    c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh103)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh103 >> 0x8)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh103 >> 0x10)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh103 >> 0x18)
    primal_velocity[0] = uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 0 * 4]) | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 3]) << 0x18)
    primal_velocity[1] = uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 1 * 4]) | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 3]) << 0x18)
    primal_velocity[2] = uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 2 * 4]) | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 3]) << 0x18)
    numplanes = 0
    time_left = time
    for (bumpcount in range(0, numbumps)) {
        if (uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 0 * 4]) | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 3]) << 0x18) == 0.0 && uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 1 * 4]) | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 3]) << 0x18) == 0.0 && uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 2 * 4]) | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 3]) << 0x18) == 0.0) {
            break
        }
        i_2 = 0
        while (i_2 < 3) {
            let c2da_fresh104 : float = uint_bits_to_float(uint(c2da_mem[ent_7 + 148 + i_2 * 4]) | uint(c2da_mem[ent_7 + 148 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 148 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 148 + i_2 * 4 + 3]) << 0x18) + time_left * uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + i_2 * 4]) | uint(c2da_mem[ent_7 + 172 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + i_2 * 4 + 3]) << 0x18)
            let c2da_fresh105 : uint = float_bits_to_uint(c2da_fresh104)
            c2da_mem[c2da_fp + i_2 * 4] = uint8(c2da_fresh105)
            c2da_mem[c2da_fp + i_2 * 4 + 1] = uint8(c2da_fresh105 >> 0x8)
            c2da_mem[c2da_fp + i_2 * 4 + 2] = uint8(c2da_fresh105 >> 0x10)
            c2da_mem[c2da_fp + i_2 * 4 + 3] = uint8(c2da_fresh105 >> 0x18)
            i_2++
        }
        trace_0 = SV_Move(ent_7 + 148, ent_7 + 240, ent_7 + 252, c2da_fp, 0, ent_7)
        if (trace_0.allsolid != 0u) {
            let c2da_fresh106 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18)
            let c2da_fresh107 : uint = float_bits_to_uint(c2da_fresh106)
            c2da_mem[ent_7 + 172 + 0 * 4] = uint8(c2da_fresh107)
            c2da_mem[ent_7 + 172 + 0 * 4 + 1] = uint8(c2da_fresh107 >> 0x8)
            c2da_mem[ent_7 + 172 + 0 * 4 + 2] = uint8(c2da_fresh107 >> 0x10)
            c2da_mem[ent_7 + 172 + 0 * 4 + 3] = uint8(c2da_fresh107 >> 0x18)
            let c2da_fresh108 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18)
            let c2da_fresh109 : uint = float_bits_to_uint(c2da_fresh108)
            c2da_mem[ent_7 + 172 + 1 * 4] = uint8(c2da_fresh109)
            c2da_mem[ent_7 + 172 + 1 * 4 + 1] = uint8(c2da_fresh109 >> 0x8)
            c2da_mem[ent_7 + 172 + 1 * 4 + 2] = uint8(c2da_fresh109 >> 0x10)
            c2da_mem[ent_7 + 172 + 1 * 4 + 3] = uint8(c2da_fresh109 >> 0x18)
            let c2da_fresh110 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh111 : uint = float_bits_to_uint(c2da_fresh110)
            c2da_mem[ent_7 + 172 + 2 * 4] = uint8(c2da_fresh111)
            c2da_mem[ent_7 + 172 + 2 * 4 + 1] = uint8(c2da_fresh111 >> 0x8)
            c2da_mem[ent_7 + 172 + 2 * 4 + 2] = uint8(c2da_fresh111 >> 0x10)
            c2da_mem[ent_7 + 172 + 2 * 4 + 3] = uint8(c2da_fresh111 >> 0x18)
            return 3
        }
        if (trace_0.fraction > 0.0) {
            let c2da_fresh112 : float = trace_0.endpos[0]
            let c2da_fresh113 : uint = float_bits_to_uint(c2da_fresh112)
            c2da_mem[ent_7 + 148 + 0 * 4] = uint8(c2da_fresh113)
            c2da_mem[ent_7 + 148 + 0 * 4 + 1] = uint8(c2da_fresh113 >> 0x8)
            c2da_mem[ent_7 + 148 + 0 * 4 + 2] = uint8(c2da_fresh113 >> 0x10)
            c2da_mem[ent_7 + 148 + 0 * 4 + 3] = uint8(c2da_fresh113 >> 0x18)
            let c2da_fresh114 : float = trace_0.endpos[1]
            let c2da_fresh115 : uint = float_bits_to_uint(c2da_fresh114)
            c2da_mem[ent_7 + 148 + 1 * 4] = uint8(c2da_fresh115)
            c2da_mem[ent_7 + 148 + 1 * 4 + 1] = uint8(c2da_fresh115 >> 0x8)
            c2da_mem[ent_7 + 148 + 1 * 4 + 2] = uint8(c2da_fresh115 >> 0x10)
            c2da_mem[ent_7 + 148 + 1 * 4 + 3] = uint8(c2da_fresh115 >> 0x18)
            let c2da_fresh116 : float = trace_0.endpos[2]
            let c2da_fresh117 : uint = float_bits_to_uint(c2da_fresh116)
            c2da_mem[ent_7 + 148 + 2 * 4] = uint8(c2da_fresh117)
            c2da_mem[ent_7 + 148 + 2 * 4 + 1] = uint8(c2da_fresh117 >> 0x8)
            c2da_mem[ent_7 + 148 + 2 * 4 + 2] = uint8(c2da_fresh117 >> 0x10)
            c2da_mem[ent_7 + 148 + 2 * 4 + 3] = uint8(c2da_fresh117 >> 0x18)
            let c2da_fresh118 : float = uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 0 * 4]) | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 3]) << 0x18)
            let c2da_fresh119 : uint = float_bits_to_uint(c2da_fresh118)
            c2da_mem[c2da_fp + 16 + 0 * 4] = uint8(c2da_fresh119)
            c2da_mem[c2da_fp + 16 + 0 * 4 + 1] = uint8(c2da_fresh119 >> 0x8)
            c2da_mem[c2da_fp + 16 + 0 * 4 + 2] = uint8(c2da_fresh119 >> 0x10)
            c2da_mem[c2da_fp + 16 + 0 * 4 + 3] = uint8(c2da_fresh119 >> 0x18)
            let c2da_fresh120 : float = uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 1 * 4]) | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 3]) << 0x18)
            let c2da_fresh121 : uint = float_bits_to_uint(c2da_fresh120)
            c2da_mem[c2da_fp + 16 + 1 * 4] = uint8(c2da_fresh121)
            c2da_mem[c2da_fp + 16 + 1 * 4 + 1] = uint8(c2da_fresh121 >> 0x8)
            c2da_mem[c2da_fp + 16 + 1 * 4 + 2] = uint8(c2da_fresh121 >> 0x10)
            c2da_mem[c2da_fp + 16 + 1 * 4 + 3] = uint8(c2da_fresh121 >> 0x18)
            let c2da_fresh122 : float = uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 2 * 4]) | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh123 : uint = float_bits_to_uint(c2da_fresh122)
            c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh123)
            c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh123 >> 0x8)
            c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh123 >> 0x10)
            c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh123 >> 0x18)
            numplanes = 0
        }
        if (trace_0.fraction == 1.0) {
            break
        }
        if (trace_0.ent == 0) {
            Sys_Error(736790, [])
        }
        if (double(trace_0.plane.normal[2]) > 0.7lf) {
            blocked_0 |= 1
            let c2da_fresh124 : int = trace_0.ent + 144
            if (uint_bits_to_float(uint(c2da_mem[c2da_fresh124]) | uint(c2da_mem[c2da_fresh124 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh124 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh124 + 3]) << 0x18) == 4.0) {
                let c2da_fresh125 : float = float(int(uint_bits_to_float(uint(c2da_mem[ent_7 + 412]) | uint(c2da_mem[ent_7 + 413]) << 0x8 | uint(c2da_mem[ent_7 + 414]) << 0x10 | uint(c2da_mem[ent_7 + 415]) << 0x18)) | 512)
                let c2da_fresh126 : uint = float_bits_to_uint(c2da_fresh125)
                c2da_mem[ent_7 + 412] = uint8(c2da_fresh126)
                c2da_mem[ent_7 + 413] = uint8(c2da_fresh126 >> 0x8)
                c2da_mem[ent_7 + 414] = uint8(c2da_fresh126 >> 0x10)
                c2da_mem[ent_7 + 415] = uint8(c2da_fresh126 >> 0x18)
                let c2da_fresh127 : int = trace_0.ent - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
                let c2da_fresh128 : uint = uint(c2da_fresh127)
                c2da_mem[ent_7 + 296] = uint8(c2da_fresh128)
                c2da_mem[ent_7 + 297] = uint8(c2da_fresh128 >> 0x8)
                c2da_mem[ent_7 + 298] = uint8(c2da_fresh128 >> 0x10)
                c2da_mem[ent_7 + 299] = uint8(c2da_fresh128 >> 0x18)
            }
        }
        if (trace_0.plane.normal[2] == 0.0) {
            blocked_0 |= 2
            if (steptrace != 0) {
                let c2da_fresh129 : uint = trace_0.allsolid
                c2da_mem[steptrace] = uint8(c2da_fresh129)
                c2da_mem[steptrace + 1] = uint8(c2da_fresh129 >> 0x8)
                c2da_mem[steptrace + 2] = uint8(c2da_fresh129 >> 0x10)
                c2da_mem[steptrace + 3] = uint8(c2da_fresh129 >> 0x18)
                let c2da_fresh130 : uint = trace_0.startsolid
                c2da_mem[steptrace + 4] = uint8(c2da_fresh130)
                c2da_mem[steptrace + 5] = uint8(c2da_fresh130 >> 0x8)
                c2da_mem[steptrace + 6] = uint8(c2da_fresh130 >> 0x10)
                c2da_mem[steptrace + 7] = uint8(c2da_fresh130 >> 0x18)
                let c2da_fresh131 : uint = trace_0.inopen
                c2da_mem[steptrace + 8] = uint8(c2da_fresh131)
                c2da_mem[steptrace + 9] = uint8(c2da_fresh131 >> 0x8)
                c2da_mem[steptrace + 10] = uint8(c2da_fresh131 >> 0x10)
                c2da_mem[steptrace + 11] = uint8(c2da_fresh131 >> 0x18)
                let c2da_fresh132 : uint = trace_0.inwater
                c2da_mem[steptrace + 12] = uint8(c2da_fresh132)
                c2da_mem[steptrace + 13] = uint8(c2da_fresh132 >> 0x8)
                c2da_mem[steptrace + 14] = uint8(c2da_fresh132 >> 0x10)
                c2da_mem[steptrace + 15] = uint8(c2da_fresh132 >> 0x18)
                let c2da_fresh133 : uint = float_bits_to_uint(trace_0.fraction)
                c2da_mem[steptrace + 16] = uint8(c2da_fresh133)
                c2da_mem[steptrace + 17] = uint8(c2da_fresh133 >> 0x8)
                c2da_mem[steptrace + 18] = uint8(c2da_fresh133 >> 0x10)
                c2da_mem[steptrace + 19] = uint8(c2da_fresh133 >> 0x18)
                let c2da_fresh134 : uint = float_bits_to_uint(trace_0.endpos[0])
                c2da_mem[steptrace + 20] = uint8(c2da_fresh134)
                c2da_mem[steptrace + 21] = uint8(c2da_fresh134 >> 0x8)
                c2da_mem[steptrace + 22] = uint8(c2da_fresh134 >> 0x10)
                c2da_mem[steptrace + 23] = uint8(c2da_fresh134 >> 0x18)
                let c2da_fresh135 : uint = float_bits_to_uint(trace_0.endpos[1])
                c2da_mem[steptrace + 24] = uint8(c2da_fresh135)
                c2da_mem[steptrace + 25] = uint8(c2da_fresh135 >> 0x8)
                c2da_mem[steptrace + 26] = uint8(c2da_fresh135 >> 0x10)
                c2da_mem[steptrace + 27] = uint8(c2da_fresh135 >> 0x18)
                let c2da_fresh136 : uint = float_bits_to_uint(trace_0.endpos[2])
                c2da_mem[steptrace + 28] = uint8(c2da_fresh136)
                c2da_mem[steptrace + 29] = uint8(c2da_fresh136 >> 0x8)
                c2da_mem[steptrace + 30] = uint8(c2da_fresh136 >> 0x10)
                c2da_mem[steptrace + 31] = uint8(c2da_fresh136 >> 0x18)
                let c2da_fresh137 : uint = float_bits_to_uint(trace_0.plane.normal[0])
                c2da_mem[steptrace + 32] = uint8(c2da_fresh137)
                c2da_mem[steptrace + 33] = uint8(c2da_fresh137 >> 0x8)
                c2da_mem[steptrace + 34] = uint8(c2da_fresh137 >> 0x10)
                c2da_mem[steptrace + 35] = uint8(c2da_fresh137 >> 0x18)
                let c2da_fresh138 : uint = float_bits_to_uint(trace_0.plane.normal[1])
                c2da_mem[steptrace + 36] = uint8(c2da_fresh138)
                c2da_mem[steptrace + 37] = uint8(c2da_fresh138 >> 0x8)
                c2da_mem[steptrace + 38] = uint8(c2da_fresh138 >> 0x10)
                c2da_mem[steptrace + 39] = uint8(c2da_fresh138 >> 0x18)
                let c2da_fresh139 : uint = float_bits_to_uint(trace_0.plane.normal[2])
                c2da_mem[steptrace + 40] = uint8(c2da_fresh139)
                c2da_mem[steptrace + 41] = uint8(c2da_fresh139 >> 0x8)
                c2da_mem[steptrace + 42] = uint8(c2da_fresh139 >> 0x10)
                c2da_mem[steptrace + 43] = uint8(c2da_fresh139 >> 0x18)
                let c2da_fresh140 : uint = float_bits_to_uint(trace_0.plane.dist)
                c2da_mem[steptrace + 44] = uint8(c2da_fresh140)
                c2da_mem[steptrace + 45] = uint8(c2da_fresh140 >> 0x8)
                c2da_mem[steptrace + 46] = uint8(c2da_fresh140 >> 0x10)
                c2da_mem[steptrace + 47] = uint8(c2da_fresh140 >> 0x18)
                let c2da_fresh141 : uint = uint(trace_0.ent)
                c2da_mem[steptrace + 48] = uint8(c2da_fresh141)
                c2da_mem[steptrace + 49] = uint8(c2da_fresh141 >> 0x8)
                c2da_mem[steptrace + 50] = uint8(c2da_fresh141 >> 0x10)
                c2da_mem[steptrace + 51] = uint8(c2da_fresh141 >> 0x18)
                c2da_mem[steptrace + 52] = 0u8
                c2da_mem[steptrace + 53] = 0u8
                c2da_mem[steptrace + 54] = 0u8
                c2da_mem[steptrace + 55] = 0u8
            }
        }
        SV_Impact(ent_7, trace_0.ent)
        if ((uint(c2da_mem[ent_7]) | uint(c2da_mem[ent_7 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 3]) << 0x18) != 0u) {
            break
        }
        time_left -= time_left * trace_0.fraction
        if (numplanes >= 5) {
            let c2da_fresh142 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18)
            let c2da_fresh143 : uint = float_bits_to_uint(c2da_fresh142)
            c2da_mem[ent_7 + 172 + 0 * 4] = uint8(c2da_fresh143)
            c2da_mem[ent_7 + 172 + 0 * 4 + 1] = uint8(c2da_fresh143 >> 0x8)
            c2da_mem[ent_7 + 172 + 0 * 4 + 2] = uint8(c2da_fresh143 >> 0x10)
            c2da_mem[ent_7 + 172 + 0 * 4 + 3] = uint8(c2da_fresh143 >> 0x18)
            let c2da_fresh144 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18)
            let c2da_fresh145 : uint = float_bits_to_uint(c2da_fresh144)
            c2da_mem[ent_7 + 172 + 1 * 4] = uint8(c2da_fresh145)
            c2da_mem[ent_7 + 172 + 1 * 4 + 1] = uint8(c2da_fresh145 >> 0x8)
            c2da_mem[ent_7 + 172 + 1 * 4 + 2] = uint8(c2da_fresh145 >> 0x10)
            c2da_mem[ent_7 + 172 + 1 * 4 + 3] = uint8(c2da_fresh145 >> 0x18)
            let c2da_fresh146 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh147 : uint = float_bits_to_uint(c2da_fresh146)
            c2da_mem[ent_7 + 172 + 2 * 4] = uint8(c2da_fresh147)
            c2da_mem[ent_7 + 172 + 2 * 4 + 1] = uint8(c2da_fresh147 >> 0x8)
            c2da_mem[ent_7 + 172 + 2 * 4 + 2] = uint8(c2da_fresh147 >> 0x10)
            c2da_mem[ent_7 + 172 + 2 * 4 + 3] = uint8(c2da_fresh147 >> 0x18)
            return 3
        }
        let c2da_fresh148 : float = trace_0.plane.normal[0]
        let c2da_fresh149 : uint = float_bits_to_uint(c2da_fresh148)
        c2da_mem[c2da_fp + 32 + numplanes * 12 + 0 * 4] = uint8(c2da_fresh149)
        c2da_mem[c2da_fp + 32 + numplanes * 12 + 0 * 4 + 1] = uint8(c2da_fresh149 >> 0x8)
        c2da_mem[c2da_fp + 32 + numplanes * 12 + 0 * 4 + 2] = uint8(c2da_fresh149 >> 0x10)
        c2da_mem[c2da_fp + 32 + numplanes * 12 + 0 * 4 + 3] = uint8(c2da_fresh149 >> 0x18)
        let c2da_fresh150 : float = trace_0.plane.normal[1]
        let c2da_fresh151 : uint = float_bits_to_uint(c2da_fresh150)
        c2da_mem[c2da_fp + 32 + numplanes * 12 + 1 * 4] = uint8(c2da_fresh151)
        c2da_mem[c2da_fp + 32 + numplanes * 12 + 1 * 4 + 1] = uint8(c2da_fresh151 >> 0x8)
        c2da_mem[c2da_fp + 32 + numplanes * 12 + 1 * 4 + 2] = uint8(c2da_fresh151 >> 0x10)
        c2da_mem[c2da_fp + 32 + numplanes * 12 + 1 * 4 + 3] = uint8(c2da_fresh151 >> 0x18)
        let c2da_fresh152 : float = trace_0.plane.normal[2]
        let c2da_fresh153 : uint = float_bits_to_uint(c2da_fresh152)
        c2da_mem[c2da_fp + 32 + numplanes * 12 + 2 * 4] = uint8(c2da_fresh153)
        c2da_mem[c2da_fp + 32 + numplanes * 12 + 2 * 4 + 1] = uint8(c2da_fresh153 >> 0x8)
        c2da_mem[c2da_fp + 32 + numplanes * 12 + 2 * 4 + 2] = uint8(c2da_fresh153 >> 0x10)
        c2da_mem[c2da_fp + 32 + numplanes * 12 + 2 * 4 + 3] = uint8(c2da_fresh153 >> 0x18)
        numplanes++
        i_2 = 0
        while (i_2 < numplanes) {
            ClipVelocity(c2da_fp + 16, c2da_fp + 32 + i_2 * 12, c2da_fp + 96, 1.0)
            j = 0
            while (j < numplanes) {
                if (j != i_2) {
                    if (uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + 0 * 4]) | uint(c2da_mem[c2da_fp + 96 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + j * 12 + 0 * 4]) | uint(c2da_mem[c2da_fp + 32 + j * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + j * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + j * 12 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + 1 * 4]) | uint(c2da_mem[c2da_fp + 96 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + j * 12 + 1 * 4]) | uint(c2da_mem[c2da_fp + 32 + j * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + j * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + j * 12 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + 2 * 4]) | uint(c2da_mem[c2da_fp + 96 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + j * 12 + 2 * 4]) | uint(c2da_mem[c2da_fp + 32 + j * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + j * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + j * 12 + 2 * 4 + 3]) << 0x18) < 0.0) {
                        break
                    }
                }
                j++
            }
            if (j == numplanes) {
                break
            }
            i_2++
        }
        if (i_2 != numplanes) {
            let c2da_fresh154 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + 0 * 4]) | uint(c2da_mem[c2da_fp + 96 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + 0 * 4 + 3]) << 0x18)
            let c2da_fresh155 : uint = float_bits_to_uint(c2da_fresh154)
            c2da_mem[ent_7 + 172 + 0 * 4] = uint8(c2da_fresh155)
            c2da_mem[ent_7 + 172 + 0 * 4 + 1] = uint8(c2da_fresh155 >> 0x8)
            c2da_mem[ent_7 + 172 + 0 * 4 + 2] = uint8(c2da_fresh155 >> 0x10)
            c2da_mem[ent_7 + 172 + 0 * 4 + 3] = uint8(c2da_fresh155 >> 0x18)
            let c2da_fresh156 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + 1 * 4]) | uint(c2da_mem[c2da_fp + 96 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + 1 * 4 + 3]) << 0x18)
            let c2da_fresh157 : uint = float_bits_to_uint(c2da_fresh156)
            c2da_mem[ent_7 + 172 + 1 * 4] = uint8(c2da_fresh157)
            c2da_mem[ent_7 + 172 + 1 * 4 + 1] = uint8(c2da_fresh157 >> 0x8)
            c2da_mem[ent_7 + 172 + 1 * 4 + 2] = uint8(c2da_fresh157 >> 0x10)
            c2da_mem[ent_7 + 172 + 1 * 4 + 3] = uint8(c2da_fresh157 >> 0x18)
            let c2da_fresh158 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + 2 * 4]) | uint(c2da_mem[c2da_fp + 96 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh159 : uint = float_bits_to_uint(c2da_fresh158)
            c2da_mem[ent_7 + 172 + 2 * 4] = uint8(c2da_fresh159)
            c2da_mem[ent_7 + 172 + 2 * 4 + 1] = uint8(c2da_fresh159 >> 0x8)
            c2da_mem[ent_7 + 172 + 2 * 4 + 2] = uint8(c2da_fresh159 >> 0x10)
            c2da_mem[ent_7 + 172 + 2 * 4 + 3] = uint8(c2da_fresh159 >> 0x18)
        } else {
            if (numplanes != 2) {
                let c2da_fresh160 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18)
                let c2da_fresh161 : uint = float_bits_to_uint(c2da_fresh160)
                c2da_mem[ent_7 + 172 + 0 * 4] = uint8(c2da_fresh161)
                c2da_mem[ent_7 + 172 + 0 * 4 + 1] = uint8(c2da_fresh161 >> 0x8)
                c2da_mem[ent_7 + 172 + 0 * 4 + 2] = uint8(c2da_fresh161 >> 0x10)
                c2da_mem[ent_7 + 172 + 0 * 4 + 3] = uint8(c2da_fresh161 >> 0x18)
                let c2da_fresh162 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18)
                let c2da_fresh163 : uint = float_bits_to_uint(c2da_fresh162)
                c2da_mem[ent_7 + 172 + 1 * 4] = uint8(c2da_fresh163)
                c2da_mem[ent_7 + 172 + 1 * 4 + 1] = uint8(c2da_fresh163 >> 0x8)
                c2da_mem[ent_7 + 172 + 1 * 4 + 2] = uint8(c2da_fresh163 >> 0x10)
                c2da_mem[ent_7 + 172 + 1 * 4 + 3] = uint8(c2da_fresh163 >> 0x18)
                let c2da_fresh164 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18)
                let c2da_fresh165 : uint = float_bits_to_uint(c2da_fresh164)
                c2da_mem[ent_7 + 172 + 2 * 4] = uint8(c2da_fresh165)
                c2da_mem[ent_7 + 172 + 2 * 4 + 1] = uint8(c2da_fresh165 >> 0x8)
                c2da_mem[ent_7 + 172 + 2 * 4 + 2] = uint8(c2da_fresh165 >> 0x10)
                c2da_mem[ent_7 + 172 + 2 * 4 + 3] = uint8(c2da_fresh165 >> 0x18)
                return 7
            }
            CrossProduct(c2da_fp + 32 + 0 * 12, c2da_fp + 32 + 1 * 12, c2da_fp + 112)
            d = uint_bits_to_float(uint(c2da_mem[c2da_fp + 112 + 0 * 4]) | uint(c2da_mem[c2da_fp + 112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 112 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 0 * 4]) | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 112 + 1 * 4]) | uint(c2da_mem[c2da_fp + 112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 112 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 1 * 4]) | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 112 + 2 * 4]) | uint(c2da_mem[c2da_fp + 112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 112 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 2 * 4]) | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 3]) << 0x18)
            VectorScale(c2da_fp + 112, d, ent_7 + 172)
        }
        if (uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 0 * 4]) | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 0 * 4 + 3]) << 0x18) * primal_velocity[0] + uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 1 * 4]) | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 1 * 4 + 3]) << 0x18) * primal_velocity[1] + uint_bits_to_float(uint(c2da_mem[ent_7 + 172 + 2 * 4]) | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_7 + 172 + 2 * 4 + 3]) << 0x18) * primal_velocity[2] <= 0.0) {
            let c2da_fresh166 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18)
            let c2da_fresh167 : uint = float_bits_to_uint(c2da_fresh166)
            c2da_mem[ent_7 + 172 + 0 * 4] = uint8(c2da_fresh167)
            c2da_mem[ent_7 + 172 + 0 * 4 + 1] = uint8(c2da_fresh167 >> 0x8)
            c2da_mem[ent_7 + 172 + 0 * 4 + 2] = uint8(c2da_fresh167 >> 0x10)
            c2da_mem[ent_7 + 172 + 0 * 4 + 3] = uint8(c2da_fresh167 >> 0x18)
            let c2da_fresh168 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18)
            let c2da_fresh169 : uint = float_bits_to_uint(c2da_fresh168)
            c2da_mem[ent_7 + 172 + 1 * 4] = uint8(c2da_fresh169)
            c2da_mem[ent_7 + 172 + 1 * 4 + 1] = uint8(c2da_fresh169 >> 0x8)
            c2da_mem[ent_7 + 172 + 1 * 4 + 2] = uint8(c2da_fresh169 >> 0x10)
            c2da_mem[ent_7 + 172 + 1 * 4 + 3] = uint8(c2da_fresh169 >> 0x18)
            let c2da_fresh170 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh171 : uint = float_bits_to_uint(c2da_fresh170)
            c2da_mem[ent_7 + 172 + 2 * 4] = uint8(c2da_fresh171)
            c2da_mem[ent_7 + 172 + 2 * 4 + 1] = uint8(c2da_fresh171 >> 0x8)
            c2da_mem[ent_7 + 172 + 2 * 4 + 2] = uint8(c2da_fresh171 >> 0x10)
            c2da_mem[ent_7 + 172 + 2 * 4 + 3] = uint8(c2da_fresh171 >> 0x18)
            return blocked_0
        }
    }
    return blocked_0
}
[sideeffects]
def private SV_PushMove_c2da_frame(var pusher : int; var movetime_0 : float; c2da_fp : int) {
    var i_3 : int
    var e : int
    var check : int
    var block_0 : int
    var mins : vec3_t
    var maxs : vec3_t
    var entorig : vec3_t
    var pushorig : vec3_t
    var num_moved : int
    var moved_edict : int[600]
    var moved_from : vec3_t[600]
    if (uint_bits_to_float(uint(c2da_mem[pusher + 172 + 0 * 4]) | uint(c2da_mem[pusher + 172 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pusher + 172 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pusher + 172 + 0 * 4 + 3]) << 0x18) == 0.0 && uint_bits_to_float(uint(c2da_mem[pusher + 172 + 1 * 4]) | uint(c2da_mem[pusher + 172 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pusher + 172 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pusher + 172 + 1 * 4 + 3]) << 0x18) == 0.0 && uint_bits_to_float(uint(c2da_mem[pusher + 172 + 2 * 4]) | uint(c2da_mem[pusher + 172 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pusher + 172 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pusher + 172 + 2 * 4 + 3]) << 0x18) == 0.0) {
        let c2da_fresh180 : float = uint_bits_to_float(uint(c2da_mem[pusher + 136]) | uint(c2da_mem[pusher + 137]) << 0x8 | uint(c2da_mem[pusher + 138]) << 0x10 | uint(c2da_mem[pusher + 139]) << 0x18) + movetime_0
        let c2da_fresh181 : uint = float_bits_to_uint(c2da_fresh180)
        c2da_mem[pusher + 136] = uint8(c2da_fresh181)
        c2da_mem[pusher + 137] = uint8(c2da_fresh181 >> 0x8)
        c2da_mem[pusher + 138] = uint8(c2da_fresh181 >> 0x10)
        c2da_mem[pusher + 139] = uint8(c2da_fresh181 >> 0x18)
        return
    }
    i_3 = 0
    while (i_3 < 3) {
        let c2da_fresh182 : float = uint_bits_to_float(uint(c2da_mem[pusher + 172 + i_3 * 4]) | uint(c2da_mem[pusher + 172 + i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[pusher + 172 + i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[pusher + 172 + i_3 * 4 + 3]) << 0x18) * movetime_0
        let c2da_fresh183 : uint = float_bits_to_uint(c2da_fresh182)
        c2da_mem[c2da_fp + i_3 * 4] = uint8(c2da_fresh183)
        c2da_mem[c2da_fp + i_3 * 4 + 1] = uint8(c2da_fresh183 >> 0x8)
        c2da_mem[c2da_fp + i_3 * 4 + 2] = uint8(c2da_fresh183 >> 0x10)
        c2da_mem[c2da_fp + i_3 * 4 + 3] = uint8(c2da_fresh183 >> 0x18)
        mins[i_3] = uint_bits_to_float(uint(c2da_mem[pusher + 112 + i_3 * 4]) | uint(c2da_mem[pusher + 112 + i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[pusher + 112 + i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[pusher + 112 + i_3 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + i_3 * 4]) | uint(c2da_mem[c2da_fp + i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + i_3 * 4 + 3]) << 0x18)
        maxs[i_3] = uint_bits_to_float(uint(c2da_mem[pusher + 124 + i_3 * 4]) | uint(c2da_mem[pusher + 124 + i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[pusher + 124 + i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[pusher + 124 + i_3 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + i_3 * 4]) | uint(c2da_mem[c2da_fp + i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + i_3 * 4 + 3]) << 0x18)
        i_3++
    }
    pushorig[0] = uint_bits_to_float(uint(c2da_mem[pusher + 148 + 0 * 4]) | uint(c2da_mem[pusher + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pusher + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pusher + 148 + 0 * 4 + 3]) << 0x18)
    pushorig[1] = uint_bits_to_float(uint(c2da_mem[pusher + 148 + 1 * 4]) | uint(c2da_mem[pusher + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pusher + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pusher + 148 + 1 * 4 + 3]) << 0x18)
    pushorig[2] = uint_bits_to_float(uint(c2da_mem[pusher + 148 + 2 * 4]) | uint(c2da_mem[pusher + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pusher + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pusher + 148 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh184 : float = uint_bits_to_float(uint(c2da_mem[pusher + 148 + 0 * 4]) | uint(c2da_mem[pusher + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pusher + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pusher + 148 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
    let c2da_fresh185 : uint = float_bits_to_uint(c2da_fresh184)
    c2da_mem[pusher + 148 + 0 * 4] = uint8(c2da_fresh185)
    c2da_mem[pusher + 148 + 0 * 4 + 1] = uint8(c2da_fresh185 >> 0x8)
    c2da_mem[pusher + 148 + 0 * 4 + 2] = uint8(c2da_fresh185 >> 0x10)
    c2da_mem[pusher + 148 + 0 * 4 + 3] = uint8(c2da_fresh185 >> 0x18)
    let c2da_fresh186 : float = uint_bits_to_float(uint(c2da_mem[pusher + 148 + 1 * 4]) | uint(c2da_mem[pusher + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pusher + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pusher + 148 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
    let c2da_fresh187 : uint = float_bits_to_uint(c2da_fresh186)
    c2da_mem[pusher + 148 + 1 * 4] = uint8(c2da_fresh187)
    c2da_mem[pusher + 148 + 1 * 4 + 1] = uint8(c2da_fresh187 >> 0x8)
    c2da_mem[pusher + 148 + 1 * 4 + 2] = uint8(c2da_fresh187 >> 0x10)
    c2da_mem[pusher + 148 + 1 * 4 + 3] = uint8(c2da_fresh187 >> 0x18)
    let c2da_fresh188 : float = uint_bits_to_float(uint(c2da_mem[pusher + 148 + 2 * 4]) | uint(c2da_mem[pusher + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pusher + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pusher + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
    let c2da_fresh189 : uint = float_bits_to_uint(c2da_fresh188)
    c2da_mem[pusher + 148 + 2 * 4] = uint8(c2da_fresh189)
    c2da_mem[pusher + 148 + 2 * 4 + 1] = uint8(c2da_fresh189 >> 0x8)
    c2da_mem[pusher + 148 + 2 * 4 + 2] = uint8(c2da_fresh189 >> 0x10)
    c2da_mem[pusher + 148 + 2 * 4 + 3] = uint8(c2da_fresh189 >> 0x18)
    let c2da_fresh190 : float = uint_bits_to_float(uint(c2da_mem[pusher + 136]) | uint(c2da_mem[pusher + 137]) << 0x8 | uint(c2da_mem[pusher + 138]) << 0x10 | uint(c2da_mem[pusher + 139]) << 0x18) + movetime_0
    let c2da_fresh191 : uint = float_bits_to_uint(c2da_fresh190)
    c2da_mem[pusher + 136] = uint8(c2da_fresh191)
    c2da_mem[pusher + 137] = uint8(c2da_fresh191 >> 0x8)
    c2da_mem[pusher + 138] = uint8(c2da_fresh191 >> 0x10)
    c2da_mem[pusher + 139] = uint8(c2da_fresh191 >> 0x18)
    SV_LinkEdict(pusher, 0u)
    num_moved = 0
    check = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(pr_edict_size)
    e = 1
    while (e < int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        if ((uint(c2da_mem[check]) | uint(c2da_mem[check + 1]) << 0x8 | uint(c2da_mem[check + 2]) << 0x10 | uint(c2da_mem[check + 3]) << 0x18) != 0u) {
            e++
            check += int(pr_edict_size)
            continue
        }
        if (uint_bits_to_float(uint(c2da_mem[check + 140]) | uint(c2da_mem[check + 141]) << 0x8 | uint(c2da_mem[check + 142]) << 0x10 | uint(c2da_mem[check + 143]) << 0x18) == 7.0 || uint_bits_to_float(uint(c2da_mem[check + 140]) | uint(c2da_mem[check + 141]) << 0x8 | uint(c2da_mem[check + 142]) << 0x10 | uint(c2da_mem[check + 143]) << 0x18) == 0.0 || uint_bits_to_float(uint(c2da_mem[check + 140]) | uint(c2da_mem[check + 141]) << 0x8 | uint(c2da_mem[check + 142]) << 0x10 | uint(c2da_mem[check + 143]) << 0x18) == 8.0) {
            e++
            check += int(pr_edict_size)
            continue
        }
        if (!((int(uint_bits_to_float(uint(c2da_mem[check + 412]) | uint(c2da_mem[check + 413]) << 0x8 | uint(c2da_mem[check + 414]) << 0x10 | uint(c2da_mem[check + 415]) << 0x18)) & 512) != 0 && int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[check + 296]) | uint(c2da_mem[check + 297]) << 0x8 | uint(c2da_mem[check + 298]) << 0x10 | uint(c2da_mem[check + 299]) << 0x18) == pusher)) {
            if (uint_bits_to_float(uint(c2da_mem[check + 112 + 0 * 4]) | uint(c2da_mem[check + 112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 112 + 0 * 4 + 3]) << 0x18) >= maxs[0] || uint_bits_to_float(uint(c2da_mem[check + 112 + 1 * 4]) | uint(c2da_mem[check + 112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 112 + 1 * 4 + 3]) << 0x18) >= maxs[1] || uint_bits_to_float(uint(c2da_mem[check + 112 + 2 * 4]) | uint(c2da_mem[check + 112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 112 + 2 * 4 + 3]) << 0x18) >= maxs[2] || uint_bits_to_float(uint(c2da_mem[check + 124 + 0 * 4]) | uint(c2da_mem[check + 124 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 124 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 124 + 0 * 4 + 3]) << 0x18) <= mins[0] || uint_bits_to_float(uint(c2da_mem[check + 124 + 1 * 4]) | uint(c2da_mem[check + 124 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 124 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 124 + 1 * 4 + 3]) << 0x18) <= mins[1] || uint_bits_to_float(uint(c2da_mem[check + 124 + 2 * 4]) | uint(c2da_mem[check + 124 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 124 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 124 + 2 * 4 + 3]) << 0x18) <= mins[2]) {
                e++
                check += int(pr_edict_size)
                continue
            }
            if (SV_TestEntityPosition(check) == 0) {
                e++
                check += int(pr_edict_size)
                continue
            }
        }
        if (uint_bits_to_float(uint(c2da_mem[check + 140]) | uint(c2da_mem[check + 141]) << 0x8 | uint(c2da_mem[check + 142]) << 0x10 | uint(c2da_mem[check + 143]) << 0x18) != 3.0) {
            let c2da_fresh192 : float = float(int(uint_bits_to_float(uint(c2da_mem[check + 412]) | uint(c2da_mem[check + 413]) << 0x8 | uint(c2da_mem[check + 414]) << 0x10 | uint(c2da_mem[check + 415]) << 0x18)) & ~512)
            let c2da_fresh193 : uint = float_bits_to_uint(c2da_fresh192)
            c2da_mem[check + 412] = uint8(c2da_fresh193)
            c2da_mem[check + 413] = uint8(c2da_fresh193 >> 0x8)
            c2da_mem[check + 414] = uint8(c2da_fresh193 >> 0x10)
            c2da_mem[check + 415] = uint8(c2da_fresh193 >> 0x18)
        }
        entorig[0] = uint_bits_to_float(uint(c2da_mem[check + 148 + 0 * 4]) | uint(c2da_mem[check + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 148 + 0 * 4 + 3]) << 0x18)
        entorig[1] = uint_bits_to_float(uint(c2da_mem[check + 148 + 1 * 4]) | uint(c2da_mem[check + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 148 + 1 * 4 + 3]) << 0x18)
        entorig[2] = uint_bits_to_float(uint(c2da_mem[check + 148 + 2 * 4]) | uint(c2da_mem[check + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 148 + 2 * 4 + 3]) << 0x18)
        moved_from[num_moved][0] = uint_bits_to_float(uint(c2da_mem[check + 148 + 0 * 4]) | uint(c2da_mem[check + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 148 + 0 * 4 + 3]) << 0x18)
        moved_from[num_moved][1] = uint_bits_to_float(uint(c2da_mem[check + 148 + 1 * 4]) | uint(c2da_mem[check + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 148 + 1 * 4 + 3]) << 0x18)
        moved_from[num_moved][2] = uint_bits_to_float(uint(c2da_mem[check + 148 + 2 * 4]) | uint(c2da_mem[check + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 148 + 2 * 4 + 3]) << 0x18)
        moved_edict[num_moved] = check
        num_moved++
        let c2da_fresh194 : float = 0.0
        let c2da_fresh195 : uint = float_bits_to_uint(c2da_fresh194)
        c2da_mem[pusher + 144] = uint8(c2da_fresh195)
        c2da_mem[pusher + 145] = uint8(c2da_fresh195 >> 0x8)
        c2da_mem[pusher + 146] = uint8(c2da_fresh195 >> 0x10)
        c2da_mem[pusher + 147] = uint8(c2da_fresh195 >> 0x18)
        SV_PushEntity(check, c2da_fp)
        let c2da_fresh196 : float = 4.0
        let c2da_fresh197 : uint = float_bits_to_uint(c2da_fresh196)
        c2da_mem[pusher + 144] = uint8(c2da_fresh197)
        c2da_mem[pusher + 145] = uint8(c2da_fresh197 >> 0x8)
        c2da_mem[pusher + 146] = uint8(c2da_fresh197 >> 0x10)
        c2da_mem[pusher + 147] = uint8(c2da_fresh197 >> 0x18)
        block_0 = SV_TestEntityPosition(check)
        if (block_0 != 0) {
            if (uint_bits_to_float(uint(c2da_mem[check + 240 + 0 * 4]) | uint(c2da_mem[check + 240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 240 + 0 * 4 + 3]) << 0x18) == uint_bits_to_float(uint(c2da_mem[check + 252 + 0 * 4]) | uint(c2da_mem[check + 252 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 252 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 252 + 0 * 4 + 3]) << 0x18)) {
                e++
                check += int(pr_edict_size)
                continue
            }
            if (uint_bits_to_float(uint(c2da_mem[check + 144]) | uint(c2da_mem[check + 145]) << 0x8 | uint(c2da_mem[check + 146]) << 0x10 | uint(c2da_mem[check + 147]) << 0x18) == 0.0 || uint_bits_to_float(uint(c2da_mem[check + 144]) | uint(c2da_mem[check + 145]) << 0x8 | uint(c2da_mem[check + 146]) << 0x10 | uint(c2da_mem[check + 147]) << 0x18) == 1.0) {
                let c2da_fresh198 : float = 0.0
                let c2da_fresh199 : uint = float_bits_to_uint(c2da_fresh198)
                c2da_mem[check + 240 + 1 * 4] = uint8(c2da_fresh199)
                c2da_mem[check + 240 + 1 * 4 + 1] = uint8(c2da_fresh199 >> 0x8)
                c2da_mem[check + 240 + 1 * 4 + 2] = uint8(c2da_fresh199 >> 0x10)
                c2da_mem[check + 240 + 1 * 4 + 3] = uint8(c2da_fresh199 >> 0x18)
                let c2da_fresh200 : uint = float_bits_to_uint(c2da_fresh198)
                c2da_mem[check + 240 + 0 * 4] = uint8(c2da_fresh200)
                c2da_mem[check + 240 + 0 * 4 + 1] = uint8(c2da_fresh200 >> 0x8)
                c2da_mem[check + 240 + 0 * 4 + 2] = uint8(c2da_fresh200 >> 0x10)
                c2da_mem[check + 240 + 0 * 4 + 3] = uint8(c2da_fresh200 >> 0x18)
                let c2da_fresh201 : float = uint_bits_to_float(uint(c2da_mem[check + 240 + 0 * 4]) | uint(c2da_mem[check + 240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 240 + 0 * 4 + 3]) << 0x18)
                let c2da_fresh202 : uint = float_bits_to_uint(c2da_fresh201)
                c2da_mem[check + 252 + 0 * 4] = uint8(c2da_fresh202)
                c2da_mem[check + 252 + 0 * 4 + 1] = uint8(c2da_fresh202 >> 0x8)
                c2da_mem[check + 252 + 0 * 4 + 2] = uint8(c2da_fresh202 >> 0x10)
                c2da_mem[check + 252 + 0 * 4 + 3] = uint8(c2da_fresh202 >> 0x18)
                let c2da_fresh203 : float = uint_bits_to_float(uint(c2da_mem[check + 240 + 1 * 4]) | uint(c2da_mem[check + 240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 240 + 1 * 4 + 3]) << 0x18)
                let c2da_fresh204 : uint = float_bits_to_uint(c2da_fresh203)
                c2da_mem[check + 252 + 1 * 4] = uint8(c2da_fresh204)
                c2da_mem[check + 252 + 1 * 4 + 1] = uint8(c2da_fresh204 >> 0x8)
                c2da_mem[check + 252 + 1 * 4 + 2] = uint8(c2da_fresh204 >> 0x10)
                c2da_mem[check + 252 + 1 * 4 + 3] = uint8(c2da_fresh204 >> 0x18)
                let c2da_fresh205 : float = uint_bits_to_float(uint(c2da_mem[check + 240 + 2 * 4]) | uint(c2da_mem[check + 240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[check + 240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[check + 240 + 2 * 4 + 3]) << 0x18)
                let c2da_fresh206 : uint = float_bits_to_uint(c2da_fresh205)
                c2da_mem[check + 252 + 2 * 4] = uint8(c2da_fresh206)
                c2da_mem[check + 252 + 2 * 4 + 1] = uint8(c2da_fresh206 >> 0x8)
                c2da_mem[check + 252 + 2 * 4 + 2] = uint8(c2da_fresh206 >> 0x10)
                c2da_mem[check + 252 + 2 * 4 + 3] = uint8(c2da_fresh206 >> 0x18)
                e++
                check += int(pr_edict_size)
                continue
            }
            let c2da_fresh207 : float = entorig[0]
            let c2da_fresh208 : uint = float_bits_to_uint(c2da_fresh207)
            c2da_mem[check + 148 + 0 * 4] = uint8(c2da_fresh208)
            c2da_mem[check + 148 + 0 * 4 + 1] = uint8(c2da_fresh208 >> 0x8)
            c2da_mem[check + 148 + 0 * 4 + 2] = uint8(c2da_fresh208 >> 0x10)
            c2da_mem[check + 148 + 0 * 4 + 3] = uint8(c2da_fresh208 >> 0x18)
            let c2da_fresh209 : float = entorig[1]
            let c2da_fresh210 : uint = float_bits_to_uint(c2da_fresh209)
            c2da_mem[check + 148 + 1 * 4] = uint8(c2da_fresh210)
            c2da_mem[check + 148 + 1 * 4 + 1] = uint8(c2da_fresh210 >> 0x8)
            c2da_mem[check + 148 + 1 * 4 + 2] = uint8(c2da_fresh210 >> 0x10)
            c2da_mem[check + 148 + 1 * 4 + 3] = uint8(c2da_fresh210 >> 0x18)
            let c2da_fresh211 : float = entorig[2]
            let c2da_fresh212 : uint = float_bits_to_uint(c2da_fresh211)
            c2da_mem[check + 148 + 2 * 4] = uint8(c2da_fresh212)
            c2da_mem[check + 148 + 2 * 4 + 1] = uint8(c2da_fresh212 >> 0x8)
            c2da_mem[check + 148 + 2 * 4 + 2] = uint8(c2da_fresh212 >> 0x10)
            c2da_mem[check + 148 + 2 * 4 + 3] = uint8(c2da_fresh212 >> 0x18)
            SV_LinkEdict(check, 1u)
            let c2da_fresh213 : float = pushorig[0]
            let c2da_fresh214 : uint = float_bits_to_uint(c2da_fresh213)
            c2da_mem[pusher + 148 + 0 * 4] = uint8(c2da_fresh214)
            c2da_mem[pusher + 148 + 0 * 4 + 1] = uint8(c2da_fresh214 >> 0x8)
            c2da_mem[pusher + 148 + 0 * 4 + 2] = uint8(c2da_fresh214 >> 0x10)
            c2da_mem[pusher + 148 + 0 * 4 + 3] = uint8(c2da_fresh214 >> 0x18)
            let c2da_fresh215 : float = pushorig[1]
            let c2da_fresh216 : uint = float_bits_to_uint(c2da_fresh215)
            c2da_mem[pusher + 148 + 1 * 4] = uint8(c2da_fresh216)
            c2da_mem[pusher + 148 + 1 * 4 + 1] = uint8(c2da_fresh216 >> 0x8)
            c2da_mem[pusher + 148 + 1 * 4 + 2] = uint8(c2da_fresh216 >> 0x10)
            c2da_mem[pusher + 148 + 1 * 4 + 3] = uint8(c2da_fresh216 >> 0x18)
            let c2da_fresh217 : float = pushorig[2]
            let c2da_fresh218 : uint = float_bits_to_uint(c2da_fresh217)
            c2da_mem[pusher + 148 + 2 * 4] = uint8(c2da_fresh218)
            c2da_mem[pusher + 148 + 2 * 4 + 1] = uint8(c2da_fresh218 >> 0x8)
            c2da_mem[pusher + 148 + 2 * 4 + 2] = uint8(c2da_fresh218 >> 0x10)
            c2da_mem[pusher + 148 + 2 * 4 + 3] = uint8(c2da_fresh218 >> 0x18)
            SV_LinkEdict(pusher, 0u)
            let c2da_fresh219 : float = uint_bits_to_float(uint(c2da_mem[pusher + 136]) | uint(c2da_mem[pusher + 137]) << 0x8 | uint(c2da_mem[pusher + 138]) << 0x10 | uint(c2da_mem[pusher + 139]) << 0x18) - movetime_0
            let c2da_fresh220 : uint = float_bits_to_uint(c2da_fresh219)
            c2da_mem[pusher + 136] = uint8(c2da_fresh220)
            c2da_mem[pusher + 137] = uint8(c2da_fresh220 >> 0x8)
            c2da_mem[pusher + 138] = uint8(c2da_fresh220 >> 0x10)
            c2da_mem[pusher + 139] = uint8(c2da_fresh220 >> 0x18)
            if (int(uint(c2da_mem[pusher + 288]) | uint(c2da_mem[pusher + 289]) << 0x8 | uint(c2da_mem[pusher + 290]) << 0x10 | uint(c2da_mem[pusher + 291]) << 0x18) != 0) {
                let c2da_fresh221 : int = pusher - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
                let c2da_fresh222 : uint = uint(c2da_fresh221)
                c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh222)
                c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh222 >> 0x8)
                c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh222 >> 0x10)
                c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh222 >> 0x18)
                let c2da_fresh223 : int = check - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
                let c2da_fresh224 : uint = uint(c2da_fresh223)
                c2da_mem[pr_global_struct + 116] = uint8(c2da_fresh224)
                c2da_mem[pr_global_struct + 117] = uint8(c2da_fresh224 >> 0x8)
                c2da_mem[pr_global_struct + 118] = uint8(c2da_fresh224 >> 0x10)
                c2da_mem[pr_global_struct + 119] = uint8(c2da_fresh224 >> 0x18)
                PR_ExecuteProgram(int(uint(c2da_mem[pusher + 288]) | uint(c2da_mem[pusher + 289]) << 0x8 | uint(c2da_mem[pusher + 290]) << 0x10 | uint(c2da_mem[pusher + 291]) << 0x18))
            }
            i_3 = 0
            for (c2da_i_3 in range(i_3, num_moved)) {
                let c2da_fresh225 : int = moved_edict[c2da_i_3] + 148 + 0 * 4
                let c2da_fresh226 : float = moved_from[c2da_i_3][0]
                let c2da_fresh227 : uint = float_bits_to_uint(c2da_fresh226)
                c2da_mem[c2da_fresh225] = uint8(c2da_fresh227)
                c2da_mem[c2da_fresh225 + 1] = uint8(c2da_fresh227 >> 0x8)
                c2da_mem[c2da_fresh225 + 2] = uint8(c2da_fresh227 >> 0x10)
                c2da_mem[c2da_fresh225 + 3] = uint8(c2da_fresh227 >> 0x18)
                let c2da_fresh228 : int = moved_edict[c2da_i_3] + 148 + 1 * 4
                let c2da_fresh229 : float = moved_from[c2da_i_3][1]
                let c2da_fresh230 : uint = float_bits_to_uint(c2da_fresh229)
                c2da_mem[c2da_fresh228] = uint8(c2da_fresh230)
                c2da_mem[c2da_fresh228 + 1] = uint8(c2da_fresh230 >> 0x8)
                c2da_mem[c2da_fresh228 + 2] = uint8(c2da_fresh230 >> 0x10)
                c2da_mem[c2da_fresh228 + 3] = uint8(c2da_fresh230 >> 0x18)
                let c2da_fresh231 : int = moved_edict[c2da_i_3] + 148 + 2 * 4
                let c2da_fresh232 : float = moved_from[c2da_i_3][2]
                let c2da_fresh233 : uint = float_bits_to_uint(c2da_fresh232)
                c2da_mem[c2da_fresh231] = uint8(c2da_fresh233)
                c2da_mem[c2da_fresh231 + 1] = uint8(c2da_fresh233 >> 0x8)
                c2da_mem[c2da_fresh231 + 2] = uint8(c2da_fresh233 >> 0x10)
                c2da_mem[c2da_fresh231 + 3] = uint8(c2da_fresh233 >> 0x18)
                SV_LinkEdict(moved_edict[c2da_i_3], 0u)
            }
            return
        }
        e++
        check += int(pr_edict_size)
    }
    return
}
[sideeffects]
def private SV_WalkMove_c2da_frame(var ent_12 : int; c2da_fp : int) {
    var oldorg : vec3_t
    var nosteporg : vec3_t
    var nostepvel : vec3_t
    var clip : int
    var oldonground : int
    var downtrace : trace_t
    oldonground = int(uint_bits_to_float(uint(c2da_mem[ent_12 + 412]) | uint(c2da_mem[ent_12 + 413]) << 0x8 | uint(c2da_mem[ent_12 + 414]) << 0x10 | uint(c2da_mem[ent_12 + 415]) << 0x18)) & 512
    let c2da_fresh244 : float = float(int(uint_bits_to_float(uint(c2da_mem[ent_12 + 412]) | uint(c2da_mem[ent_12 + 413]) << 0x8 | uint(c2da_mem[ent_12 + 414]) << 0x10 | uint(c2da_mem[ent_12 + 415]) << 0x18)) & ~512)
    let c2da_fresh245 : uint = float_bits_to_uint(c2da_fresh244)
    c2da_mem[ent_12 + 412] = uint8(c2da_fresh245)
    c2da_mem[ent_12 + 413] = uint8(c2da_fresh245 >> 0x8)
    c2da_mem[ent_12 + 414] = uint8(c2da_fresh245 >> 0x10)
    c2da_mem[ent_12 + 415] = uint8(c2da_fresh245 >> 0x18)
    oldorg[0] = uint_bits_to_float(uint(c2da_mem[ent_12 + 148 + 0 * 4]) | uint(c2da_mem[ent_12 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_12 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_12 + 148 + 0 * 4 + 3]) << 0x18)
    oldorg[1] = uint_bits_to_float(uint(c2da_mem[ent_12 + 148 + 1 * 4]) | uint(c2da_mem[ent_12 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_12 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_12 + 148 + 1 * 4 + 3]) << 0x18)
    oldorg[2] = uint_bits_to_float(uint(c2da_mem[ent_12 + 148 + 2 * 4]) | uint(c2da_mem[ent_12 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_12 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_12 + 148 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh246 : float = uint_bits_to_float(uint(c2da_mem[ent_12 + 172 + 0 * 4]) | uint(c2da_mem[ent_12 + 172 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_12 + 172 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_12 + 172 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh247 : uint = float_bits_to_uint(c2da_fresh246)
    c2da_mem[c2da_fp + 80 + 0 * 4] = uint8(c2da_fresh247)
    c2da_mem[c2da_fp + 80 + 0 * 4 + 1] = uint8(c2da_fresh247 >> 0x8)
    c2da_mem[c2da_fp + 80 + 0 * 4 + 2] = uint8(c2da_fresh247 >> 0x10)
    c2da_mem[c2da_fp + 80 + 0 * 4 + 3] = uint8(c2da_fresh247 >> 0x18)
    let c2da_fresh248 : float = uint_bits_to_float(uint(c2da_mem[ent_12 + 172 + 1 * 4]) | uint(c2da_mem[ent_12 + 172 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_12 + 172 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_12 + 172 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh249 : uint = float_bits_to_uint(c2da_fresh248)
    c2da_mem[c2da_fp + 80 + 1 * 4] = uint8(c2da_fresh249)
    c2da_mem[c2da_fp + 80 + 1 * 4 + 1] = uint8(c2da_fresh249 >> 0x8)
    c2da_mem[c2da_fp + 80 + 1 * 4 + 2] = uint8(c2da_fresh249 >> 0x10)
    c2da_mem[c2da_fp + 80 + 1 * 4 + 3] = uint8(c2da_fresh249 >> 0x18)
    let c2da_fresh250 : float = uint_bits_to_float(uint(c2da_mem[ent_12 + 172 + 2 * 4]) | uint(c2da_mem[ent_12 + 172 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_12 + 172 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_12 + 172 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh251 : uint = float_bits_to_uint(c2da_fresh250)
    c2da_mem[c2da_fp + 80 + 2 * 4] = uint8(c2da_fresh251)
    c2da_mem[c2da_fp + 80 + 2 * 4 + 1] = uint8(c2da_fresh251 >> 0x8)
    c2da_mem[c2da_fp + 80 + 2 * 4 + 2] = uint8(c2da_fresh251 >> 0x10)
    c2da_mem[c2da_fp + 80 + 2 * 4 + 3] = uint8(c2da_fresh251 >> 0x18)
    clip = SV_FlyMove(ent_12, float(host_frametime), c2da_fp)
    if ((clip & 2) == 0) {
        return
    }
    if (oldonground == 0 && uint_bits_to_float(uint(c2da_mem[ent_12 + 440]) | uint(c2da_mem[ent_12 + 441]) << 0x8 | uint(c2da_mem[ent_12 + 442]) << 0x10 | uint(c2da_mem[ent_12 + 443]) << 0x18) == 0.0) {
        return
    }
    if (uint_bits_to_float(uint(c2da_mem[ent_12 + 140]) | uint(c2da_mem[ent_12 + 141]) << 0x8 | uint(c2da_mem[ent_12 + 142]) << 0x10 | uint(c2da_mem[ent_12 + 143]) << 0x18) != 3.0) {
        return
    }
    if (uint_bits_to_float(uint(c2da_mem[463000]) | uint(c2da_mem[463001]) << 0x8 | uint(c2da_mem[463002]) << 0x10 | uint(c2da_mem[463003]) << 0x18) != 0.0) {
        return
    }
    if ((int(uint_bits_to_float(uint(c2da_mem[sv_player + 412]) | uint(c2da_mem[sv_player + 413]) << 0x8 | uint(c2da_mem[sv_player + 414]) << 0x10 | uint(c2da_mem[sv_player + 415]) << 0x18)) & 2048) != 0) {
        return
    }
    nosteporg[0] = uint_bits_to_float(uint(c2da_mem[ent_12 + 148 + 0 * 4]) | uint(c2da_mem[ent_12 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_12 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_12 + 148 + 0 * 4 + 3]) << 0x18)
    nosteporg[1] = uint_bits_to_float(uint(c2da_mem[ent_12 + 148 + 1 * 4]) | uint(c2da_mem[ent_12 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_12 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_12 + 148 + 1 * 4 + 3]) << 0x18)
    nosteporg[2] = uint_bits_to_float(uint(c2da_mem[ent_12 + 148 + 2 * 4]) | uint(c2da_mem[ent_12 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_12 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_12 + 148 + 2 * 4 + 3]) << 0x18)
    nostepvel[0] = uint_bits_to_float(uint(c2da_mem[ent_12 + 172 + 0 * 4]) | uint(c2da_mem[ent_12 + 172 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_12 + 172 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_12 + 172 + 0 * 4 + 3]) << 0x18)
    nostepvel[1] = uint_bits_to_float(uint(c2da_mem[ent_12 + 172 + 1 * 4]) | uint(c2da_mem[ent_12 + 172 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_12 + 172 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_12 + 172 + 1 * 4 + 3]) << 0x18)
    nostepvel[2] = uint_bits_to_float(uint(c2da_mem[ent_12 + 172 + 2 * 4]) | uint(c2da_mem[ent_12 + 172 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_12 + 172 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_12 + 172 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh252 : float = oldorg[0]
    let c2da_fresh253 : uint = float_bits_to_uint(c2da_fresh252)
    c2da_mem[ent_12 + 148 + 0 * 4] = uint8(c2da_fresh253)
    c2da_mem[ent_12 + 148 + 0 * 4 + 1] = uint8(c2da_fresh253 >> 0x8)
    c2da_mem[ent_12 + 148 + 0 * 4 + 2] = uint8(c2da_fresh253 >> 0x10)
    c2da_mem[ent_12 + 148 + 0 * 4 + 3] = uint8(c2da_fresh253 >> 0x18)
    let c2da_fresh254 : float = oldorg[1]
    let c2da_fresh255 : uint = float_bits_to_uint(c2da_fresh254)
    c2da_mem[ent_12 + 148 + 1 * 4] = uint8(c2da_fresh255)
    c2da_mem[ent_12 + 148 + 1 * 4 + 1] = uint8(c2da_fresh255 >> 0x8)
    c2da_mem[ent_12 + 148 + 1 * 4 + 2] = uint8(c2da_fresh255 >> 0x10)
    c2da_mem[ent_12 + 148 + 1 * 4 + 3] = uint8(c2da_fresh255 >> 0x18)
    let c2da_fresh256 : float = oldorg[2]
    let c2da_fresh257 : uint = float_bits_to_uint(c2da_fresh256)
    c2da_mem[ent_12 + 148 + 2 * 4] = uint8(c2da_fresh257)
    c2da_mem[ent_12 + 148 + 2 * 4 + 1] = uint8(c2da_fresh257 >> 0x8)
    c2da_mem[ent_12 + 148 + 2 * 4 + 2] = uint8(c2da_fresh257 >> 0x10)
    c2da_mem[ent_12 + 148 + 2 * 4 + 3] = uint8(c2da_fresh257 >> 0x18)
    let c2da_fresh258 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh259 : uint = float_bits_to_uint(c2da_fresh258)
    c2da_mem[c2da_fp + 64 + 0 * 4] = uint8(c2da_fresh259)
    c2da_mem[c2da_fp + 64 + 0 * 4 + 1] = uint8(c2da_fresh259 >> 0x8)
    c2da_mem[c2da_fp + 64 + 0 * 4 + 2] = uint8(c2da_fresh259 >> 0x10)
    c2da_mem[c2da_fp + 64 + 0 * 4 + 3] = uint8(c2da_fresh259 >> 0x18)
    let c2da_fresh260 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh261 : uint = float_bits_to_uint(c2da_fresh260)
    c2da_mem[c2da_fp + 64 + 1 * 4] = uint8(c2da_fresh261)
    c2da_mem[c2da_fp + 64 + 1 * 4 + 1] = uint8(c2da_fresh261 >> 0x8)
    c2da_mem[c2da_fp + 64 + 1 * 4 + 2] = uint8(c2da_fresh261 >> 0x10)
    c2da_mem[c2da_fp + 64 + 1 * 4 + 3] = uint8(c2da_fresh261 >> 0x18)
    let c2da_fresh262 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh263 : uint = float_bits_to_uint(c2da_fresh262)
    c2da_mem[c2da_fp + 64 + 2 * 4] = uint8(c2da_fresh263)
    c2da_mem[c2da_fp + 64 + 2 * 4 + 1] = uint8(c2da_fresh263 >> 0x8)
    c2da_mem[c2da_fp + 64 + 2 * 4 + 2] = uint8(c2da_fresh263 >> 0x10)
    c2da_mem[c2da_fp + 64 + 2 * 4 + 3] = uint8(c2da_fresh263 >> 0x18)
    let c2da_fresh264 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh265 : uint = float_bits_to_uint(c2da_fresh264)
    c2da_mem[c2da_fp + 96 + 0 * 4] = uint8(c2da_fresh265)
    c2da_mem[c2da_fp + 96 + 0 * 4 + 1] = uint8(c2da_fresh265 >> 0x8)
    c2da_mem[c2da_fp + 96 + 0 * 4 + 2] = uint8(c2da_fresh265 >> 0x10)
    c2da_mem[c2da_fp + 96 + 0 * 4 + 3] = uint8(c2da_fresh265 >> 0x18)
    let c2da_fresh266 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh267 : uint = float_bits_to_uint(c2da_fresh266)
    c2da_mem[c2da_fp + 96 + 1 * 4] = uint8(c2da_fresh267)
    c2da_mem[c2da_fp + 96 + 1 * 4 + 1] = uint8(c2da_fresh267 >> 0x8)
    c2da_mem[c2da_fp + 96 + 1 * 4 + 2] = uint8(c2da_fresh267 >> 0x10)
    c2da_mem[c2da_fp + 96 + 1 * 4 + 3] = uint8(c2da_fresh267 >> 0x18)
    let c2da_fresh268 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh269 : uint = float_bits_to_uint(c2da_fresh268)
    c2da_mem[c2da_fp + 96 + 2 * 4] = uint8(c2da_fresh269)
    c2da_mem[c2da_fp + 96 + 2 * 4 + 1] = uint8(c2da_fresh269 >> 0x8)
    c2da_mem[c2da_fp + 96 + 2 * 4 + 2] = uint8(c2da_fresh269 >> 0x10)
    c2da_mem[c2da_fp + 96 + 2 * 4 + 3] = uint8(c2da_fresh269 >> 0x18)
    let c2da_fresh270 : float = 18.0
    let c2da_fresh271 : uint = float_bits_to_uint(c2da_fresh270)
    c2da_mem[c2da_fp + 64 + 2 * 4] = uint8(c2da_fresh271)
    c2da_mem[c2da_fp + 64 + 2 * 4 + 1] = uint8(c2da_fresh271 >> 0x8)
    c2da_mem[c2da_fp + 64 + 2 * 4 + 2] = uint8(c2da_fresh271 >> 0x10)
    c2da_mem[c2da_fp + 64 + 2 * 4 + 3] = uint8(c2da_fresh271 >> 0x18)
    let c2da_fresh272 : float = float(-18.0lf + double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 80 + 2 * 4]) | uint(c2da_mem[c2da_fp + 80 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 80 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 80 + 2 * 4 + 3]) << 0x18)) * host_frametime)
    let c2da_fresh273 : uint = float_bits_to_uint(c2da_fresh272)
    c2da_mem[c2da_fp + 96 + 2 * 4] = uint8(c2da_fresh273)
    c2da_mem[c2da_fp + 96 + 2 * 4 + 1] = uint8(c2da_fresh273 >> 0x8)
    c2da_mem[c2da_fp + 96 + 2 * 4 + 2] = uint8(c2da_fresh273 >> 0x10)
    c2da_mem[c2da_fp + 96 + 2 * 4 + 3] = uint8(c2da_fresh273 >> 0x18)
    SV_PushEntity(ent_12, c2da_fp + 64)
    let c2da_fresh274 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 80 + 0 * 4]) | uint(c2da_mem[c2da_fp + 80 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 80 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 80 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh275 : uint = float_bits_to_uint(c2da_fresh274)
    c2da_mem[ent_12 + 172 + 0 * 4] = uint8(c2da_fresh275)
    c2da_mem[ent_12 + 172 + 0 * 4 + 1] = uint8(c2da_fresh275 >> 0x8)
    c2da_mem[ent_12 + 172 + 0 * 4 + 2] = uint8(c2da_fresh275 >> 0x10)
    c2da_mem[ent_12 + 172 + 0 * 4 + 3] = uint8(c2da_fresh275 >> 0x18)
    let c2da_fresh276 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 80 + 1 * 4]) | uint(c2da_mem[c2da_fp + 80 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 80 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 80 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh277 : uint = float_bits_to_uint(c2da_fresh276)
    c2da_mem[ent_12 + 172 + 1 * 4] = uint8(c2da_fresh277)
    c2da_mem[ent_12 + 172 + 1 * 4 + 1] = uint8(c2da_fresh277 >> 0x8)
    c2da_mem[ent_12 + 172 + 1 * 4 + 2] = uint8(c2da_fresh277 >> 0x10)
    c2da_mem[ent_12 + 172 + 1 * 4 + 3] = uint8(c2da_fresh277 >> 0x18)
    let c2da_fresh278 : float = 0.0
    let c2da_fresh279 : uint = float_bits_to_uint(c2da_fresh278)
    c2da_mem[ent_12 + 172 + 2 * 4] = uint8(c2da_fresh279)
    c2da_mem[ent_12 + 172 + 2 * 4 + 1] = uint8(c2da_fresh279 >> 0x8)
    c2da_mem[ent_12 + 172 + 2 * 4 + 2] = uint8(c2da_fresh279 >> 0x10)
    c2da_mem[ent_12 + 172 + 2 * 4 + 3] = uint8(c2da_fresh279 >> 0x18)
    clip = SV_FlyMove(ent_12, float(host_frametime), c2da_fp)
    if (clip != 0) {
        if (c2da_std_fabs(double(oldorg[1] - uint_bits_to_float(uint(c2da_mem[ent_12 + 148 + 1 * 4]) | uint(c2da_mem[ent_12 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_12 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_12 + 148 + 1 * 4 + 3]) << 0x18))) < 0.03125lf && c2da_std_fabs(double(oldorg[0] - uint_bits_to_float(uint(c2da_mem[ent_12 + 148 + 0 * 4]) | uint(c2da_mem[ent_12 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_12 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_12 + 148 + 0 * 4 + 3]) << 0x18))) < 0.03125lf) {
            clip = SV_TryUnstick(ent_12, c2da_fp + 80)
        }
    }
    if ((clip & 2) != 0) {
        SV_WallFriction(ent_12, c2da_fp)
    }
    downtrace = SV_PushEntity(ent_12, c2da_fp + 96)
    if (double(downtrace.plane.normal[2]) > 0.7lf) {
        if (uint_bits_to_float(uint(c2da_mem[ent_12 + 144]) | uint(c2da_mem[ent_12 + 145]) << 0x8 | uint(c2da_mem[ent_12 + 146]) << 0x10 | uint(c2da_mem[ent_12 + 147]) << 0x18) == 4.0) {
            let c2da_fresh280 : float = float(int(uint_bits_to_float(uint(c2da_mem[ent_12 + 412]) | uint(c2da_mem[ent_12 + 413]) << 0x8 | uint(c2da_mem[ent_12 + 414]) << 0x10 | uint(c2da_mem[ent_12 + 415]) << 0x18)) | 512)
            let c2da_fresh281 : uint = float_bits_to_uint(c2da_fresh280)
            c2da_mem[ent_12 + 412] = uint8(c2da_fresh281)
            c2da_mem[ent_12 + 413] = uint8(c2da_fresh281 >> 0x8)
            c2da_mem[ent_12 + 414] = uint8(c2da_fresh281 >> 0x10)
            c2da_mem[ent_12 + 415] = uint8(c2da_fresh281 >> 0x18)
            let c2da_fresh282 : int = downtrace.ent - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
            let c2da_fresh283 : uint = uint(c2da_fresh282)
            c2da_mem[ent_12 + 296] = uint8(c2da_fresh283)
            c2da_mem[ent_12 + 297] = uint8(c2da_fresh283 >> 0x8)
            c2da_mem[ent_12 + 298] = uint8(c2da_fresh283 >> 0x10)
            c2da_mem[ent_12 + 299] = uint8(c2da_fresh283 >> 0x18)
        }
    } else {
        let c2da_fresh284 : float = nosteporg[0]
        let c2da_fresh285 : uint = float_bits_to_uint(c2da_fresh284)
        c2da_mem[ent_12 + 148 + 0 * 4] = uint8(c2da_fresh285)
        c2da_mem[ent_12 + 148 + 0 * 4 + 1] = uint8(c2da_fresh285 >> 0x8)
        c2da_mem[ent_12 + 148 + 0 * 4 + 2] = uint8(c2da_fresh285 >> 0x10)
        c2da_mem[ent_12 + 148 + 0 * 4 + 3] = uint8(c2da_fresh285 >> 0x18)
        let c2da_fresh286 : float = nosteporg[1]
        let c2da_fresh287 : uint = float_bits_to_uint(c2da_fresh286)
        c2da_mem[ent_12 + 148 + 1 * 4] = uint8(c2da_fresh287)
        c2da_mem[ent_12 + 148 + 1 * 4 + 1] = uint8(c2da_fresh287 >> 0x8)
        c2da_mem[ent_12 + 148 + 1 * 4 + 2] = uint8(c2da_fresh287 >> 0x10)
        c2da_mem[ent_12 + 148 + 1 * 4 + 3] = uint8(c2da_fresh287 >> 0x18)
        let c2da_fresh288 : float = nosteporg[2]
        let c2da_fresh289 : uint = float_bits_to_uint(c2da_fresh288)
        c2da_mem[ent_12 + 148 + 2 * 4] = uint8(c2da_fresh289)
        c2da_mem[ent_12 + 148 + 2 * 4 + 1] = uint8(c2da_fresh289 >> 0x8)
        c2da_mem[ent_12 + 148 + 2 * 4 + 2] = uint8(c2da_fresh289 >> 0x10)
        c2da_mem[ent_12 + 148 + 2 * 4 + 3] = uint8(c2da_fresh289 >> 0x18)
        let c2da_fresh290 : float = nostepvel[0]
        let c2da_fresh291 : uint = float_bits_to_uint(c2da_fresh290)
        c2da_mem[ent_12 + 172 + 0 * 4] = uint8(c2da_fresh291)
        c2da_mem[ent_12 + 172 + 0 * 4 + 1] = uint8(c2da_fresh291 >> 0x8)
        c2da_mem[ent_12 + 172 + 0 * 4 + 2] = uint8(c2da_fresh291 >> 0x10)
        c2da_mem[ent_12 + 172 + 0 * 4 + 3] = uint8(c2da_fresh291 >> 0x18)
        let c2da_fresh292 : float = nostepvel[1]
        let c2da_fresh293 : uint = float_bits_to_uint(c2da_fresh292)
        c2da_mem[ent_12 + 172 + 1 * 4] = uint8(c2da_fresh293)
        c2da_mem[ent_12 + 172 + 1 * 4 + 1] = uint8(c2da_fresh293 >> 0x8)
        c2da_mem[ent_12 + 172 + 1 * 4 + 2] = uint8(c2da_fresh293 >> 0x10)
        c2da_mem[ent_12 + 172 + 1 * 4 + 3] = uint8(c2da_fresh293 >> 0x18)
        let c2da_fresh294 : float = nostepvel[2]
        let c2da_fresh295 : uint = float_bits_to_uint(c2da_fresh294)
        c2da_mem[ent_12 + 172 + 2 * 4] = uint8(c2da_fresh295)
        c2da_mem[ent_12 + 172 + 2 * 4 + 1] = uint8(c2da_fresh295 >> 0x8)
        c2da_mem[ent_12 + 172 + 2 * 4 + 2] = uint8(c2da_fresh295 >> 0x10)
        c2da_mem[ent_12 + 172 + 2 * 4 + 3] = uint8(c2da_fresh295 >> 0x18)
    }
    return
}
[sideeffects]
def private SV_WallFriction_c2da_frame(var ent_13 : int; var trace_1 : int; c2da_fp : int) {
    var d_0 : float
    var i_4 : float
    var side : vec3_t
    AngleVectors(ent_13 + 388, c2da_fp, c2da_fp + 16, c2da_fp + 32)
    d_0 = uint_bits_to_float(uint(c2da_mem[trace_1 + 32 + 0 * 4]) | uint(c2da_mem[trace_1 + 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[trace_1 + 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[trace_1 + 32 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[trace_1 + 32 + 1 * 4]) | uint(c2da_mem[trace_1 + 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[trace_1 + 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[trace_1 + 32 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[trace_1 + 32 + 2 * 4]) | uint(c2da_mem[trace_1 + 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[trace_1 + 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[trace_1 + 32 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
    d_0 = float(double(d_0) + 0.5lf)
    if (d_0 >= 0.0) {
        return
    }
    i_4 = uint_bits_to_float(uint(c2da_mem[trace_1 + 32 + 0 * 4]) | uint(c2da_mem[trace_1 + 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[trace_1 + 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[trace_1 + 32 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[ent_13 + 172 + 0 * 4]) | uint(c2da_mem[ent_13 + 172 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_13 + 172 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_13 + 172 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[trace_1 + 32 + 1 * 4]) | uint(c2da_mem[trace_1 + 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[trace_1 + 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[trace_1 + 32 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[ent_13 + 172 + 1 * 4]) | uint(c2da_mem[ent_13 + 172 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_13 + 172 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_13 + 172 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[trace_1 + 32 + 2 * 4]) | uint(c2da_mem[trace_1 + 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[trace_1 + 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[trace_1 + 32 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[ent_13 + 172 + 2 * 4]) | uint(c2da_mem[ent_13 + 172 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_13 + 172 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_13 + 172 + 2 * 4 + 3]) << 0x18)
    VectorScale(trace_1 + 32, i_4, c2da_fp + 48)
    side[0] = uint_bits_to_float(uint(c2da_mem[ent_13 + 172 + 0 * 4]) | uint(c2da_mem[ent_13 + 172 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_13 + 172 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_13 + 172 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 0 * 4]) | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 3]) << 0x18)
    side[1] = uint_bits_to_float(uint(c2da_mem[ent_13 + 172 + 1 * 4]) | uint(c2da_mem[ent_13 + 172 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_13 + 172 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_13 + 172 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 1 * 4]) | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 3]) << 0x18)
    side[2] = uint_bits_to_float(uint(c2da_mem[ent_13 + 172 + 2 * 4]) | uint(c2da_mem[ent_13 + 172 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_13 + 172 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_13 + 172 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 2 * 4]) | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh296 : float = side[0] * (1.0 + d_0)
    let c2da_fresh297 : uint = float_bits_to_uint(c2da_fresh296)
    c2da_mem[ent_13 + 172 + 0 * 4] = uint8(c2da_fresh297)
    c2da_mem[ent_13 + 172 + 0 * 4 + 1] = uint8(c2da_fresh297 >> 0x8)
    c2da_mem[ent_13 + 172 + 0 * 4 + 2] = uint8(c2da_fresh297 >> 0x10)
    c2da_mem[ent_13 + 172 + 0 * 4 + 3] = uint8(c2da_fresh297 >> 0x18)
    let c2da_fresh298 : float = side[1] * (1.0 + d_0)
    let c2da_fresh299 : uint = float_bits_to_uint(c2da_fresh298)
    c2da_mem[ent_13 + 172 + 1 * 4] = uint8(c2da_fresh299)
    c2da_mem[ent_13 + 172 + 1 * 4 + 1] = uint8(c2da_fresh299 >> 0x8)
    c2da_mem[ent_13 + 172 + 1 * 4 + 2] = uint8(c2da_fresh299 >> 0x10)
    c2da_mem[ent_13 + 172 + 1 * 4 + 3] = uint8(c2da_fresh299 >> 0x18)
    return
}
[sideeffects]
def private SV_TryUnstick_c2da_frame(var ent_14 : int; var oldvel : int; c2da_fp : int) : int {
    var oldorg_0 : vec3_t
    var clip_0 : int
    oldorg_0[0] = uint_bits_to_float(uint(c2da_mem[ent_14 + 148 + 0 * 4]) | uint(c2da_mem[ent_14 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_14 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_14 + 148 + 0 * 4 + 3]) << 0x18)
    oldorg_0[1] = uint_bits_to_float(uint(c2da_mem[ent_14 + 148 + 1 * 4]) | uint(c2da_mem[ent_14 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_14 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_14 + 148 + 1 * 4 + 3]) << 0x18)
    oldorg_0[2] = uint_bits_to_float(uint(c2da_mem[ent_14 + 148 + 2 * 4]) | uint(c2da_mem[ent_14 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_14 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_14 + 148 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh300 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh301 : uint = float_bits_to_uint(c2da_fresh300)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh301)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh301 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh301 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh301 >> 0x18)
    let c2da_fresh302 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh303 : uint = float_bits_to_uint(c2da_fresh302)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh303)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh303 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh303 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh303 >> 0x18)
    let c2da_fresh304 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh305 : uint = float_bits_to_uint(c2da_fresh304)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh305)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh305 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh305 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh305 >> 0x18)
    for (i_5 in range(0, 8)) {
        if (i_5 == 0) {
            let c2da_fresh306 : float = 2.0
            let c2da_fresh307 : uint = float_bits_to_uint(c2da_fresh306)
            c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh307)
            c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh307 >> 0x8)
            c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh307 >> 0x10)
            c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh307 >> 0x18)
            let c2da_fresh308 : float = 0.0
            let c2da_fresh309 : uint = float_bits_to_uint(c2da_fresh308)
            c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh309)
            c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh309 >> 0x8)
            c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh309 >> 0x10)
            c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh309 >> 0x18)
        } elif (i_5 == 1) {
            let c2da_fresh310 : float = 0.0
            let c2da_fresh311 : uint = float_bits_to_uint(c2da_fresh310)
            c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh311)
            c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh311 >> 0x8)
            c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh311 >> 0x10)
            c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh311 >> 0x18)
            let c2da_fresh312 : float = 2.0
            let c2da_fresh313 : uint = float_bits_to_uint(c2da_fresh312)
            c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh313)
            c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh313 >> 0x8)
            c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh313 >> 0x10)
            c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh313 >> 0x18)
        } elif (i_5 == 2) {
            let c2da_fresh314 : float = -2.0
            let c2da_fresh315 : uint = float_bits_to_uint(c2da_fresh314)
            c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh315)
            c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh315 >> 0x8)
            c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh315 >> 0x10)
            c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh315 >> 0x18)
            let c2da_fresh316 : float = 0.0
            let c2da_fresh317 : uint = float_bits_to_uint(c2da_fresh316)
            c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh317)
            c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh317 >> 0x8)
            c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh317 >> 0x10)
            c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh317 >> 0x18)
        } elif (i_5 == 3) {
            let c2da_fresh318 : float = 0.0
            let c2da_fresh319 : uint = float_bits_to_uint(c2da_fresh318)
            c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh319)
            c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh319 >> 0x8)
            c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh319 >> 0x10)
            c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh319 >> 0x18)
            let c2da_fresh320 : float = -2.0
            let c2da_fresh321 : uint = float_bits_to_uint(c2da_fresh320)
            c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh321)
            c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh321 >> 0x8)
            c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh321 >> 0x10)
            c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh321 >> 0x18)
        } elif (i_5 == 4) {
            let c2da_fresh322 : float = 2.0
            let c2da_fresh323 : uint = float_bits_to_uint(c2da_fresh322)
            c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh323)
            c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh323 >> 0x8)
            c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh323 >> 0x10)
            c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh323 >> 0x18)
            let c2da_fresh324 : float = 2.0
            let c2da_fresh325 : uint = float_bits_to_uint(c2da_fresh324)
            c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh325)
            c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh325 >> 0x8)
            c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh325 >> 0x10)
            c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh325 >> 0x18)
        } elif (i_5 == 5) {
            let c2da_fresh326 : float = -2.0
            let c2da_fresh327 : uint = float_bits_to_uint(c2da_fresh326)
            c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh327)
            c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh327 >> 0x8)
            c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh327 >> 0x10)
            c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh327 >> 0x18)
            let c2da_fresh328 : float = 2.0
            let c2da_fresh329 : uint = float_bits_to_uint(c2da_fresh328)
            c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh329)
            c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh329 >> 0x8)
            c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh329 >> 0x10)
            c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh329 >> 0x18)
        } elif (i_5 == 6) {
            let c2da_fresh330 : float = 2.0
            let c2da_fresh331 : uint = float_bits_to_uint(c2da_fresh330)
            c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh331)
            c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh331 >> 0x8)
            c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh331 >> 0x10)
            c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh331 >> 0x18)
            let c2da_fresh332 : float = -2.0
            let c2da_fresh333 : uint = float_bits_to_uint(c2da_fresh332)
            c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh333)
            c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh333 >> 0x8)
            c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh333 >> 0x10)
            c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh333 >> 0x18)
        } elif (i_5 == 7) {
            let c2da_fresh334 : float = -2.0
            let c2da_fresh335 : uint = float_bits_to_uint(c2da_fresh334)
            c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh335)
            c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh335 >> 0x8)
            c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh335 >> 0x10)
            c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh335 >> 0x18)
            let c2da_fresh336 : float = -2.0
            let c2da_fresh337 : uint = float_bits_to_uint(c2da_fresh336)
            c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh337)
            c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh337 >> 0x8)
            c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh337 >> 0x10)
            c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh337 >> 0x18)
        }
        SV_PushEntity(ent_14, c2da_fp)
        let c2da_fresh338 : float = uint_bits_to_float(uint(c2da_mem[oldvel + 0 * 4]) | uint(c2da_mem[oldvel + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[oldvel + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[oldvel + 0 * 4 + 3]) << 0x18)
        let c2da_fresh339 : uint = float_bits_to_uint(c2da_fresh338)
        c2da_mem[ent_14 + 172 + 0 * 4] = uint8(c2da_fresh339)
        c2da_mem[ent_14 + 172 + 0 * 4 + 1] = uint8(c2da_fresh339 >> 0x8)
        c2da_mem[ent_14 + 172 + 0 * 4 + 2] = uint8(c2da_fresh339 >> 0x10)
        c2da_mem[ent_14 + 172 + 0 * 4 + 3] = uint8(c2da_fresh339 >> 0x18)
        let c2da_fresh340 : float = uint_bits_to_float(uint(c2da_mem[oldvel + 1 * 4]) | uint(c2da_mem[oldvel + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[oldvel + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[oldvel + 1 * 4 + 3]) << 0x18)
        let c2da_fresh341 : uint = float_bits_to_uint(c2da_fresh340)
        c2da_mem[ent_14 + 172 + 1 * 4] = uint8(c2da_fresh341)
        c2da_mem[ent_14 + 172 + 1 * 4 + 1] = uint8(c2da_fresh341 >> 0x8)
        c2da_mem[ent_14 + 172 + 1 * 4 + 2] = uint8(c2da_fresh341 >> 0x10)
        c2da_mem[ent_14 + 172 + 1 * 4 + 3] = uint8(c2da_fresh341 >> 0x18)
        let c2da_fresh342 : float = 0.0
        let c2da_fresh343 : uint = float_bits_to_uint(c2da_fresh342)
        c2da_mem[ent_14 + 172 + 2 * 4] = uint8(c2da_fresh343)
        c2da_mem[ent_14 + 172 + 2 * 4 + 1] = uint8(c2da_fresh343 >> 0x8)
        c2da_mem[ent_14 + 172 + 2 * 4 + 2] = uint8(c2da_fresh343 >> 0x10)
        c2da_mem[ent_14 + 172 + 2 * 4 + 3] = uint8(c2da_fresh343 >> 0x18)
        clip_0 = SV_FlyMove(ent_14, float(0.1lf), c2da_fp + 16)
        if (c2da_std_fabs(double(oldorg_0[1] - uint_bits_to_float(uint(c2da_mem[ent_14 + 148 + 1 * 4]) | uint(c2da_mem[ent_14 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_14 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_14 + 148 + 1 * 4 + 3]) << 0x18))) > 4.0lf || c2da_std_fabs(double(oldorg_0[0] - uint_bits_to_float(uint(c2da_mem[ent_14 + 148 + 0 * 4]) | uint(c2da_mem[ent_14 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_14 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_14 + 148 + 0 * 4 + 3]) << 0x18))) > 4.0lf) {
            return clip_0
        }
        let c2da_fresh344 : float = oldorg_0[0]
        let c2da_fresh345 : uint = float_bits_to_uint(c2da_fresh344)
        c2da_mem[ent_14 + 148 + 0 * 4] = uint8(c2da_fresh345)
        c2da_mem[ent_14 + 148 + 0 * 4 + 1] = uint8(c2da_fresh345 >> 0x8)
        c2da_mem[ent_14 + 148 + 0 * 4 + 2] = uint8(c2da_fresh345 >> 0x10)
        c2da_mem[ent_14 + 148 + 0 * 4 + 3] = uint8(c2da_fresh345 >> 0x18)
        let c2da_fresh346 : float = oldorg_0[1]
        let c2da_fresh347 : uint = float_bits_to_uint(c2da_fresh346)
        c2da_mem[ent_14 + 148 + 1 * 4] = uint8(c2da_fresh347)
        c2da_mem[ent_14 + 148 + 1 * 4 + 1] = uint8(c2da_fresh347 >> 0x8)
        c2da_mem[ent_14 + 148 + 1 * 4 + 2] = uint8(c2da_fresh347 >> 0x10)
        c2da_mem[ent_14 + 148 + 1 * 4 + 3] = uint8(c2da_fresh347 >> 0x18)
        let c2da_fresh348 : float = oldorg_0[2]
        let c2da_fresh349 : uint = float_bits_to_uint(c2da_fresh348)
        c2da_mem[ent_14 + 148 + 2 * 4] = uint8(c2da_fresh349)
        c2da_mem[ent_14 + 148 + 2 * 4 + 1] = uint8(c2da_fresh349 >> 0x8)
        c2da_mem[ent_14 + 148 + 2 * 4 + 2] = uint8(c2da_fresh349 >> 0x10)
        c2da_mem[ent_14 + 148 + 2 * 4 + 3] = uint8(c2da_fresh349 >> 0x18)
    }
    let c2da_fresh350 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh351 : uint = float_bits_to_uint(c2da_fresh350)
    c2da_mem[ent_14 + 172 + 0 * 4] = uint8(c2da_fresh351)
    c2da_mem[ent_14 + 172 + 0 * 4 + 1] = uint8(c2da_fresh351 >> 0x8)
    c2da_mem[ent_14 + 172 + 0 * 4 + 2] = uint8(c2da_fresh351 >> 0x10)
    c2da_mem[ent_14 + 172 + 0 * 4 + 3] = uint8(c2da_fresh351 >> 0x18)
    let c2da_fresh352 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh353 : uint = float_bits_to_uint(c2da_fresh352)
    c2da_mem[ent_14 + 172 + 1 * 4] = uint8(c2da_fresh353)
    c2da_mem[ent_14 + 172 + 1 * 4 + 1] = uint8(c2da_fresh353 >> 0x8)
    c2da_mem[ent_14 + 172 + 1 * 4 + 2] = uint8(c2da_fresh353 >> 0x10)
    c2da_mem[ent_14 + 172 + 1 * 4 + 3] = uint8(c2da_fresh353 >> 0x18)
    let c2da_fresh354 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh355 : uint = float_bits_to_uint(c2da_fresh354)
    c2da_mem[ent_14 + 172 + 2 * 4] = uint8(c2da_fresh355)
    c2da_mem[ent_14 + 172 + 2 * 4 + 1] = uint8(c2da_fresh355 >> 0x8)
    c2da_mem[ent_14 + 172 + 2 * 4 + 2] = uint8(c2da_fresh355 >> 0x10)
    c2da_mem[ent_14 + 172 + 2 * 4 + 3] = uint8(c2da_fresh355 >> 0x18)
    return 7
}
[sideeffects]
def private SV_CheckWater_c2da_frame(var ent_16 : int; c2da_fp : int) : uint {
    var cont_0 : int
    let c2da_fresh380 : float = uint_bits_to_float(uint(c2da_mem[ent_16 + 148 + 0 * 4]) | uint(c2da_mem[ent_16 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_16 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_16 + 148 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh381 : uint = float_bits_to_uint(c2da_fresh380)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh381)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh381 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh381 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh381 >> 0x18)
    let c2da_fresh382 : float = uint_bits_to_float(uint(c2da_mem[ent_16 + 148 + 1 * 4]) | uint(c2da_mem[ent_16 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_16 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_16 + 148 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh383 : uint = float_bits_to_uint(c2da_fresh382)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh383)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh383 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh383 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh383 >> 0x18)
    let c2da_fresh384 : float = uint_bits_to_float(uint(c2da_mem[ent_16 + 148 + 2 * 4]) | uint(c2da_mem[ent_16 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_16 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_16 + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_16 + 240 + 2 * 4]) | uint(c2da_mem[ent_16 + 240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_16 + 240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_16 + 240 + 2 * 4 + 3]) << 0x18) + 1.0
    let c2da_fresh385 : uint = float_bits_to_uint(c2da_fresh384)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh385)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh385 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh385 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh385 >> 0x18)
    let c2da_fresh386 : float = 0.0
    let c2da_fresh387 : uint = float_bits_to_uint(c2da_fresh386)
    c2da_mem[ent_16 + 440] = uint8(c2da_fresh387)
    c2da_mem[ent_16 + 441] = uint8(c2da_fresh387 >> 0x8)
    c2da_mem[ent_16 + 442] = uint8(c2da_fresh387 >> 0x10)
    c2da_mem[ent_16 + 443] = uint8(c2da_fresh387 >> 0x18)
    let c2da_fresh388 : float = -1.0
    let c2da_fresh389 : uint = float_bits_to_uint(c2da_fresh388)
    c2da_mem[ent_16 + 444] = uint8(c2da_fresh389)
    c2da_mem[ent_16 + 445] = uint8(c2da_fresh389 >> 0x8)
    c2da_mem[ent_16 + 446] = uint8(c2da_fresh389 >> 0x10)
    c2da_mem[ent_16 + 447] = uint8(c2da_fresh389 >> 0x18)
    cont_0 = SV_PointContents(c2da_fp)
    if (cont_0 <= -3) {
        let c2da_fresh390 : float = float(cont_0)
        let c2da_fresh391 : uint = float_bits_to_uint(c2da_fresh390)
        c2da_mem[ent_16 + 444] = uint8(c2da_fresh391)
        c2da_mem[ent_16 + 445] = uint8(c2da_fresh391 >> 0x8)
        c2da_mem[ent_16 + 446] = uint8(c2da_fresh391 >> 0x10)
        c2da_mem[ent_16 + 447] = uint8(c2da_fresh391 >> 0x18)
        let c2da_fresh392 : float = 1.0
        let c2da_fresh393 : uint = float_bits_to_uint(c2da_fresh392)
        c2da_mem[ent_16 + 440] = uint8(c2da_fresh393)
        c2da_mem[ent_16 + 441] = uint8(c2da_fresh393 >> 0x8)
        c2da_mem[ent_16 + 442] = uint8(c2da_fresh393 >> 0x10)
        c2da_mem[ent_16 + 443] = uint8(c2da_fresh393 >> 0x18)
        let c2da_fresh394 : float = float(double(uint_bits_to_float(uint(c2da_mem[ent_16 + 148 + 2 * 4]) | uint(c2da_mem[ent_16 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_16 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_16 + 148 + 2 * 4 + 3]) << 0x18)) + double(uint_bits_to_float(uint(c2da_mem[ent_16 + 240 + 2 * 4]) | uint(c2da_mem[ent_16 + 240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_16 + 240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_16 + 240 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_16 + 252 + 2 * 4]) | uint(c2da_mem[ent_16 + 252 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_16 + 252 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_16 + 252 + 2 * 4 + 3]) << 0x18)) * 0.5lf)
        let c2da_fresh395 : uint = float_bits_to_uint(c2da_fresh394)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh395)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh395 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh395 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh395 >> 0x18)
        cont_0 = SV_PointContents(c2da_fp)
        if (cont_0 <= -3) {
            let c2da_fresh396 : float = 2.0
            let c2da_fresh397 : uint = float_bits_to_uint(c2da_fresh396)
            c2da_mem[ent_16 + 440] = uint8(c2da_fresh397)
            c2da_mem[ent_16 + 441] = uint8(c2da_fresh397 >> 0x8)
            c2da_mem[ent_16 + 442] = uint8(c2da_fresh397 >> 0x10)
            c2da_mem[ent_16 + 443] = uint8(c2da_fresh397 >> 0x18)
            let c2da_fresh398 : float = uint_bits_to_float(uint(c2da_mem[ent_16 + 148 + 2 * 4]) | uint(c2da_mem[ent_16 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_16 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_16 + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_16 + 356 + 2 * 4]) | uint(c2da_mem[ent_16 + 356 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_16 + 356 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_16 + 356 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh399 : uint = float_bits_to_uint(c2da_fresh398)
            c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh399)
            c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh399 >> 0x8)
            c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh399 >> 0x10)
            c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh399 >> 0x18)
            cont_0 = SV_PointContents(c2da_fp)
            if (cont_0 <= -3) {
                let c2da_fresh400 : float = 3.0
                let c2da_fresh401 : uint = float_bits_to_uint(c2da_fresh400)
                c2da_mem[ent_16 + 440] = uint8(c2da_fresh401)
                c2da_mem[ent_16 + 441] = uint8(c2da_fresh401 >> 0x8)
                c2da_mem[ent_16 + 442] = uint8(c2da_fresh401 >> 0x10)
                c2da_mem[ent_16 + 443] = uint8(c2da_fresh401 >> 0x18)
            }
        }
    }
    return uint(uint_bits_to_float(uint(c2da_mem[ent_16 + 440]) | uint(c2da_mem[ent_16 + 441]) << 0x8 | uint(c2da_mem[ent_16 + 442]) << 0x10 | uint(c2da_mem[ent_16 + 443]) << 0x18) > 1.0 ? 1 : 0)
}

// This unit's static data, at heap offset 736592.
let private c2da_lin_static_sv_phys_seg = fixed_array<int>(736592, 311)
let private c2da_lin_static_sv_phys = fixed_array<uint64>(0x69766172675f7673ul, 0x7300303038007974ul, 0x6c657678616d5f76ul, 0x303200797469636ful, 0x6f6e5f7673003030ul, 0x7300300070657473ul, 0x6974636972665f76ul, 0x5f76730034006e6ful, 0x65657073706f7473ul, 0x5653003030310064ul, 0x736369737968505ful, 0x6f6d20646162203aul, 0x2520657079746576ul, 0x682f6373696d0069ul, 0x772e317469686f32ul, 0x6976617267007661ul, 0x6120746f47007974ul, 0x6c6576204e614e20ul, 0x6e6f20797469636ful, 0x746f47000a732520ul, 0x6f204e614e206120ul, 0x6e6f206e69676972ul, 0x6d6564000a732520ul, 0x646e616c642f6e6ful, 0x5653007661772e32ul, 0x65766f4d796c465ful, 0x656361727421203aul, 0x5f565300746e652eul, 0x5f73636973796850ul, 0x203a746e65696c63ul, 0x65766f6d20646162ul, 0x69252065707974ul, 0x2e6b637574736e55ul, 0x726579616c70000aul, 0x6375747320736920ul, 0x69746e65000a2e6bul, 0x6e69206e69207974ul, 0x6f702064696c6176ul, 0xa6e6f69746973ul)

[init]
def private c2da_lin_init_static_sv_phys() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_sv_phys_seg[s * 2]
        for (k in range(c2da_lin_static_sv_phys_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_sv_phys[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_sv_phys_0 = fixed_array<uint8>(0x50, 0x3d, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5b, 0x3d, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_sv_phys_1 = fixed_array<uint8>(0x5f, 0x3d, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6e, 0x3d, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_sv_phys_2 = fixed_array<uint8>(0x73, 0x3d, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7d, 0x3d, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_sv_phys_3 = fixed_array<uint8>(0x7f, 0x3d, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8b, 0x3d, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_sv_phys_4 = fixed_array<uint8>(0x8d, 0x3d, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9a, 0x3d, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_sv_phys() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[462592 + i] = c2da_lin_extern_sv_phys_0[i]
    }
    for (i in range(40)) {
        c2da_mem[462544 + i] = c2da_lin_extern_sv_phys_1[i]
    }
    for (i in range(40)) {
        c2da_mem[462976 + i] = c2da_lin_extern_sv_phys_2[i]
    }
    for (i in range(40)) {
        c2da_mem[462640 + i] = c2da_lin_extern_sv_phys_3[i]
    }
    for (i in range(40)) {
        c2da_mem[462736 + i] = c2da_lin_extern_sv_phys_4[i]
    }
}
