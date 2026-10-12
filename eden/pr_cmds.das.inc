var pr_builtins : int = 387056

[export, sideeffects]
def PF_setspawnparms() {
    var ent : int
    var i : int
    var client : int
    ent = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    i = NUM_FOR_EDICT(ent)
    if (i < 1 || i > svs.maxclients) {
        PR_RunError(728380, [])
    }
    client = svs.clients + (i - 1) * 8288
    i = 0
    for (c2da_i in range(i, 16)) {
        let c2da_fresh0 : float = uint_bits_to_float(uint(c2da_mem[client + 8216 + c2da_i * 4]) | uint(c2da_mem[client + 8216 + c2da_i * 4 + 1]) << 0x8 | uint(c2da_mem[client + 8216 + c2da_i * 4 + 2]) << 0x10 | uint(c2da_mem[client + 8216 + c2da_i * 4 + 3]) << 0x18)
        let c2da_fresh1 : uint = float_bits_to_uint(c2da_fresh0)
        c2da_mem[pr_global_struct + 172 + c2da_i * 4] = uint8(c2da_fresh1)
        c2da_mem[pr_global_struct + 172 + c2da_i * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[pr_global_struct + 172 + c2da_i * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[pr_global_struct + 172 + c2da_i * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
    }
    return
}
[export, sideeffects]
def PF_precache_file() {
    let c2da_fresh2 : int = int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    let c2da_fresh3 : uint = uint(c2da_fresh2)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh3)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
    return
}
[export, sideeffects]
def PF_precache_sound() {
    var s : int
    if ((uint(c2da_mem[232704]) | uint(c2da_mem[232705]) << 0x8 | uint(c2da_mem[232706]) << 0x10 | uint(c2da_mem[232707]) << 0x18) != 0u) {
        PR_RunError(728403, [])
    }
    s = pr_strings + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    let c2da_fresh4 : int = int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    let c2da_fresh5 : uint = uint(c2da_fresh4)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh5)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh5 >> 0x18)
    PR_CheckEmptyString(s)
    for (i_0 in range(0, 256)) {
        if (int(uint(c2da_mem[230128 + i_0 * 8]) | uint(c2da_mem[230128 + i_0 * 8 + 1]) << 0x8 | uint(c2da_mem[230128 + i_0 * 8 + 2]) << 0x10 | uint(c2da_mem[230128 + i_0 * 8 + 3]) << 0x18) == 0) {
            let c2da_fresh6 : uint = uint(s)
            c2da_mem[230128 + i_0 * 8] = uint8(c2da_fresh6)
            c2da_mem[230128 + i_0 * 8 + 1] = uint8(c2da_fresh6 >> 0x8)
            c2da_mem[230128 + i_0 * 8 + 2] = uint8(c2da_fresh6 >> 0x10)
            c2da_mem[230128 + i_0 * 8 + 3] = uint8(c2da_fresh6 >> 0x18)
            c2da_mem[230128 + i_0 * 8 + 4] = 0u8
            c2da_mem[230128 + i_0 * 8 + 5] = 0u8
            c2da_mem[230128 + i_0 * 8 + 6] = 0u8
            c2da_mem[230128 + i_0 * 8 + 7] = 0u8
            return
        }
        if (c2da_lin_strcmp(int(uint(c2da_mem[230128 + i_0 * 8]) | uint(c2da_mem[230128 + i_0 * 8 + 1]) << 0x8 | uint(c2da_mem[230128 + i_0 * 8 + 2]) << 0x10 | uint(c2da_mem[230128 + i_0 * 8 + 3]) << 0x18), s) == 0) {
            return
        }
    }
    PR_RunError(728463, [])
    return
}
[export, sideeffects]
def PR_CheckEmptyString(var s_0 : int) {
    if (int(int8(c2da_mem[s_0 + 0])) <= 32) {
        PR_RunError(728491, [])
    }
    return
}
[export, sideeffects]
def PF_precache_model() {
    var s_1 : int
    if ((uint(c2da_mem[232704]) | uint(c2da_mem[232705]) << 0x8 | uint(c2da_mem[232706]) << 0x10 | uint(c2da_mem[232707]) << 0x18) != 0u) {
        PR_RunError(728403, [])
    }
    s_1 = pr_strings + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    let c2da_fresh7 : int = int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    let c2da_fresh8 : uint = uint(c2da_fresh7)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh8)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh8 >> 0x18)
    PR_CheckEmptyString(s_1)
    for (i_1 in range(0, 256)) {
        if (int(uint(c2da_mem[226032 + i_1 * 8]) | uint(c2da_mem[226032 + i_1 * 8 + 1]) << 0x8 | uint(c2da_mem[226032 + i_1 * 8 + 2]) << 0x10 | uint(c2da_mem[226032 + i_1 * 8 + 3]) << 0x18) == 0) {
            let c2da_fresh9 : uint = uint(s_1)
            c2da_mem[226032 + i_1 * 8] = uint8(c2da_fresh9)
            c2da_mem[226032 + i_1 * 8 + 1] = uint8(c2da_fresh9 >> 0x8)
            c2da_mem[226032 + i_1 * 8 + 2] = uint8(c2da_fresh9 >> 0x10)
            c2da_mem[226032 + i_1 * 8 + 3] = uint8(c2da_fresh9 >> 0x18)
            c2da_mem[226032 + i_1 * 8 + 4] = 0u8
            c2da_mem[226032 + i_1 * 8 + 5] = 0u8
            c2da_mem[226032 + i_1 * 8 + 6] = 0u8
            c2da_mem[226032 + i_1 * 8 + 7] = 0u8
            let c2da_fresh10 : int = Mod_ForName(s_1, 1u)
            let c2da_fresh11 : uint = uint(c2da_fresh10)
            c2da_mem[228080 + i_1 * 8] = uint8(c2da_fresh11)
            c2da_mem[228080 + i_1 * 8 + 1] = uint8(c2da_fresh11 >> 0x8)
            c2da_mem[228080 + i_1 * 8 + 2] = uint8(c2da_fresh11 >> 0x10)
            c2da_mem[228080 + i_1 * 8 + 3] = uint8(c2da_fresh11 >> 0x18)
            c2da_mem[228080 + i_1 * 8 + 4] = 0u8
            c2da_mem[228080 + i_1 * 8 + 5] = 0u8
            c2da_mem[228080 + i_1 * 8 + 6] = 0u8
            c2da_mem[228080 + i_1 * 8 + 7] = 0u8
            return
        }
        if (c2da_lin_strcmp(int(uint(c2da_mem[226032 + i_1 * 8]) | uint(c2da_mem[226032 + i_1 * 8 + 1]) << 0x8 | uint(c2da_mem[226032 + i_1 * 8 + 2]) << 0x10 | uint(c2da_mem[226032 + i_1 * 8 + 3]) << 0x18), s_1) == 0) {
            return
        }
    }
    PR_RunError(728502, [])
    return
}
[export, sideeffects]
def PF_ambientsound() {
    var check : int
    var samp : int
    var pos : int
    var vol : float
    var attenuation : float
    var soundnum : int
    pos = pr_globals + 4 * 4
    samp = pr_strings + int(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18)
    vol = uint_bits_to_float(uint(c2da_mem[pr_globals + 10 * 4]) | uint(c2da_mem[pr_globals + 10 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 10 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 10 * 4 + 3]) << 0x18)
    attenuation = uint_bits_to_float(uint(c2da_mem[pr_globals + 13 * 4]) | uint(c2da_mem[pr_globals + 13 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 13 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 13 * 4 + 3]) << 0x18)
    soundnum = 0
    check = 230128
    while (int(uint(c2da_mem[check]) | uint(c2da_mem[check + 1]) << 0x8 | uint(c2da_mem[check + 2]) << 0x10 | uint(c2da_mem[check + 3]) << 0x18) != 0) {
        if (c2da_lin_strcmp(int(uint(c2da_mem[check]) | uint(c2da_mem[check + 1]) << 0x8 | uint(c2da_mem[check + 2]) << 0x10 | uint(c2da_mem[check + 3]) << 0x18), samp) == 0) {
            break
        }
        check += 8
        soundnum++
    }
    if (int(uint(c2da_mem[check]) | uint(c2da_mem[check + 1]) << 0x8 | uint(c2da_mem[check + 2]) << 0x10 | uint(c2da_mem[check + 3]) << 0x18) == 0) {
        Con_Printf(728530, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(samp))])
        return
    }
    MSG_WriteByte(234808, 29)
    for (i_2 in range(0, 3)) {
        MSG_WriteCoord(234808, uint_bits_to_float(uint(c2da_mem[pos + i_2 * 4]) | uint(c2da_mem[pos + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[pos + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[pos + i_2 * 4 + 3]) << 0x18))
    }
    MSG_WriteByte(234808, soundnum)
    MSG_WriteByte(234808, int(vol * 255.0))
    MSG_WriteByte(234808, int(attenuation * 64.0))
    return
}
[export, sideeffects]
def PF_centerprint() {
    var s_2 : int
    var client_0 : int
    var entnum : int = NUM_FOR_EDICT(int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18))
    s_2 = PF_VarString(1)
    if (entnum < 1 || entnum > svs.maxclients) {
        Con_Printf(728547, [])
        return
    }
    client_0 = svs.clients + (entnum - 1) * 8288
    MSG_WriteChar(client_0 + 80, 26)
    MSG_WriteString(client_0 + 80, s_2)
    return
}
[export, sideeffects]
def PF_VarString(var first : int) : int {
    var i_3 : int
    let c2da_fresh12 : int8 = int8(0)
    c2da_mem[728112 + 0] = uint8(c2da_fresh12)
    i_3 = first
    while (i_3 < pr_argc) {
        c2da_lin_strcat(728112, int(pr_strings + int(uint(c2da_mem[pr_globals + (4 + i_3 * 3) * 4]) | uint(c2da_mem[pr_globals + (4 + i_3 * 3) * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + (4 + i_3 * 3) * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + (4 + i_3 * 3) * 4 + 3]) << 0x18)))
        i_3++
    }
    return 728112
}
[export, sideeffects]
def PF_cvar_set() {
    var var_0 : int
    var val : int
    var_0 = pr_strings + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    val = pr_strings + int(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18)
    Cvar_Set(var_0, val)
    return
}
[export, sideeffects]
def PF_Fixme() {
    PR_RunError(728580, [])
    return
}
[export, sideeffects]
def PF_changelevel() {
    var s_3 : int
    if (uint(svs.changelevel_issued) != 0u) {
        return
    }
    svs.changelevel_issued = 1u
    s_3 = pr_strings + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    Cbuf_AddText(va(728602, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(s_3))]))
    return
}
[export, sideeffects]
def PF_makestatic() {
    var ent_0 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    MSG_WriteByte(234808, 20)
    MSG_WriteByte(234808, SV_ModelIndex(pr_strings + int(uint(c2da_mem[ent_0 + 224]) | uint(c2da_mem[ent_0 + 225]) << 0x8 | uint(c2da_mem[ent_0 + 226]) << 0x10 | uint(c2da_mem[ent_0 + 227]) << 0x18)))
    MSG_WriteByte(234808, int(uint_bits_to_float(uint(c2da_mem[ent_0 + 228]) | uint(c2da_mem[ent_0 + 229]) << 0x8 | uint(c2da_mem[ent_0 + 230]) << 0x10 | uint(c2da_mem[ent_0 + 231]) << 0x18)))
    MSG_WriteByte(234808, int(uint_bits_to_float(uint(c2da_mem[ent_0 + 416]) | uint(c2da_mem[ent_0 + 417]) << 0x8 | uint(c2da_mem[ent_0 + 418]) << 0x10 | uint(c2da_mem[ent_0 + 419]) << 0x18)))
    MSG_WriteByte(234808, int(uint_bits_to_float(uint(c2da_mem[ent_0 + 232]) | uint(c2da_mem[ent_0 + 233]) << 0x8 | uint(c2da_mem[ent_0 + 234]) << 0x10 | uint(c2da_mem[ent_0 + 235]) << 0x18)))
    for (i_4 in range(0, 3)) {
        MSG_WriteCoord(234808, uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + i_4 * 4]) | uint(c2da_mem[ent_0 + 148 + i_4 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + i_4 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + i_4 * 4 + 3]) << 0x18))
        MSG_WriteAngle(234808, uint_bits_to_float(uint(c2da_mem[ent_0 + 184 + i_4 * 4]) | uint(c2da_mem[ent_0 + 184 + i_4 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 184 + i_4 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 184 + i_4 * 4 + 3]) << 0x18))
    }
    ED_Free(ent_0)
    return
}
[export, sideeffects]
def PF_WriteEntity() {
    MSG_WriteShort(WriteDest(), NUM_FOR_EDICT(int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18)))
    return
}
[export, sideeffects]
def WriteDest() : int {
    var c2da_fresh13 : int
    var entnum_0 : int
    var ent_1 : int
    c2da_fresh13 = int(uint_bits_to_float(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18))
    if (c2da_fresh13 == 0) {
        return 232712
    } elif (c2da_fresh13 == 1) {
        ent_1 = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_global_struct + 324]) | uint(c2da_mem[pr_global_struct + 325]) << 0x8 | uint(c2da_mem[pr_global_struct + 326]) << 0x10 | uint(c2da_mem[pr_global_struct + 327]) << 0x18)
        entnum_0 = NUM_FOR_EDICT(ent_1)
        if (entnum_0 < 1 || entnum_0 > svs.maxclients) {
            PR_RunError(728618, [])
        }
        return svs.clients + (entnum_0 - 1) * 8288 + 80
    } elif (c2da_fresh13 == 2) {
        return 233760
    } elif (c2da_fresh13 == 3) {
        return 234808
    } else {
        PR_RunError(728642, [])
    }
    return 0
}
[export, sideeffects]
def PF_WriteString() {
    MSG_WriteString(WriteDest(), pr_strings + int(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18))
    return
}
[export, sideeffects]
def PF_WriteAngle() {
    MSG_WriteAngle(WriteDest(), uint_bits_to_float(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18))
    return
}
[export, sideeffects]
def PF_WriteCoord() {
    MSG_WriteCoord(WriteDest(), uint_bits_to_float(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18))
    return
}
[export, sideeffects]
def PF_WriteLong() {
    MSG_WriteLong(WriteDest(), int(uint_bits_to_float(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18)))
    return
}
[export, sideeffects]
def PF_WriteShort() {
    MSG_WriteShort(WriteDest(), int(uint_bits_to_float(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18)))
    return
}
[export, sideeffects]
def PF_WriteChar() {
    MSG_WriteChar(WriteDest(), int(uint_bits_to_float(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18)))
    return
}
[export, sideeffects]
def PF_WriteByte() {
    MSG_WriteByte(WriteDest(), int(uint_bits_to_float(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18)))
    return
}
[export, sideeffects]
def PF_vectoangles() {
    var value1 : int
    var forward_0 : float
    var yaw : float
    var pitch : float
    value1 = pr_globals + 4 * 4
    if (uint_bits_to_float(uint(c2da_mem[value1 + 1 * 4]) | uint(c2da_mem[value1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[value1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[value1 + 1 * 4 + 3]) << 0x18) == 0.0 && uint_bits_to_float(uint(c2da_mem[value1 + 0 * 4]) | uint(c2da_mem[value1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[value1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[value1 + 0 * 4 + 3]) << 0x18) == 0.0) {
        yaw = 0.0
        if (uint_bits_to_float(uint(c2da_mem[value1 + 2 * 4]) | uint(c2da_mem[value1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[value1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[value1 + 2 * 4 + 3]) << 0x18) > 0.0) {
            pitch = 90.0
        } else {
            pitch = 270.0
        }
    } else {
        yaw = float(int(atan2(double(uint_bits_to_float(uint(c2da_mem[value1 + 1 * 4]) | uint(c2da_mem[value1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[value1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[value1 + 1 * 4 + 3]) << 0x18)), double(uint_bits_to_float(uint(c2da_mem[value1 + 0 * 4]) | uint(c2da_mem[value1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[value1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[value1 + 0 * 4 + 3]) << 0x18))) * 180.0lf / 3.141592653589793lf))
        if (yaw < 0.0) {
            yaw += 360.0
        }
        forward_0 = float(sqrt(double(uint_bits_to_float(uint(c2da_mem[value1 + 0 * 4]) | uint(c2da_mem[value1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[value1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[value1 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[value1 + 0 * 4]) | uint(c2da_mem[value1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[value1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[value1 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[value1 + 1 * 4]) | uint(c2da_mem[value1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[value1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[value1 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[value1 + 1 * 4]) | uint(c2da_mem[value1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[value1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[value1 + 1 * 4 + 3]) << 0x18))))
        pitch = float(int(atan2(double(uint_bits_to_float(uint(c2da_mem[value1 + 2 * 4]) | uint(c2da_mem[value1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[value1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[value1 + 2 * 4 + 3]) << 0x18)), double(forward_0)) * 180.0lf / 3.141592653589793lf))
        if (pitch < 0.0) {
            pitch += 360.0
        }
    }
    let c2da_fresh14 : uint = float_bits_to_uint(pitch)
    c2da_mem[pr_globals + (1 + 0) * 4] = uint8(c2da_fresh14)
    c2da_mem[pr_globals + (1 + 0) * 4 + 1] = uint8(c2da_fresh14 >> 0x8)
    c2da_mem[pr_globals + (1 + 0) * 4 + 2] = uint8(c2da_fresh14 >> 0x10)
    c2da_mem[pr_globals + (1 + 0) * 4 + 3] = uint8(c2da_fresh14 >> 0x18)
    let c2da_fresh15 : uint = float_bits_to_uint(yaw)
    c2da_mem[pr_globals + (1 + 1) * 4] = uint8(c2da_fresh15)
    c2da_mem[pr_globals + (1 + 1) * 4 + 1] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[pr_globals + (1 + 1) * 4 + 2] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[pr_globals + (1 + 1) * 4 + 3] = uint8(c2da_fresh15 >> 0x18)
    let c2da_fresh16 : float = 0.0
    let c2da_fresh17 : uint = float_bits_to_uint(c2da_fresh16)
    c2da_mem[pr_globals + (1 + 2) * 4] = uint8(c2da_fresh17)
    c2da_mem[pr_globals + (1 + 2) * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[pr_globals + (1 + 2) * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[pr_globals + (1 + 2) * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
    return
}
[export, sideeffects]
def PF_changeyaw() {
    var ent_2 : int
    var ideal : float
    var current : float
    var move : float
    var speed : float
    ent_2 = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_global_struct + 112]) | uint(c2da_mem[pr_global_struct + 113]) << 0x8 | uint(c2da_mem[pr_global_struct + 114]) << 0x10 | uint(c2da_mem[pr_global_struct + 115]) << 0x18)
    current = anglemod(uint_bits_to_float(uint(c2da_mem[ent_2 + 184 + 1 * 4]) | uint(c2da_mem[ent_2 + 184 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 184 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 184 + 1 * 4 + 3]) << 0x18))
    ideal = uint_bits_to_float(uint(c2da_mem[ent_2 + 448]) | uint(c2da_mem[ent_2 + 449]) << 0x8 | uint(c2da_mem[ent_2 + 450]) << 0x10 | uint(c2da_mem[ent_2 + 451]) << 0x18)
    speed = uint_bits_to_float(uint(c2da_mem[ent_2 + 452]) | uint(c2da_mem[ent_2 + 453]) << 0x8 | uint(c2da_mem[ent_2 + 454]) << 0x10 | uint(c2da_mem[ent_2 + 455]) << 0x18)
    if (current == ideal) {
        return
    }
    move = ideal - current
    if (ideal > current) {
        if (move >= 180.0) {
            move -= 360.0
        }
    } elif (move <= -180.0) {
        move += 360.0
    }
    if (move > 0.0) {
        if (move > speed) {
            move = speed
        }
    } elif (move < -speed) {
        move = -speed
    }
    let c2da_fresh18 : float = anglemod(current + move)
    let c2da_fresh19 : uint = float_bits_to_uint(c2da_fresh18)
    c2da_mem[ent_2 + 184 + 1 * 4] = uint8(c2da_fresh19)
    c2da_mem[ent_2 + 184 + 1 * 4 + 1] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[ent_2 + 184 + 1 * 4 + 2] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[ent_2 + 184 + 1 * 4 + 3] = uint8(c2da_fresh19 >> 0x18)
    return
}
[export, sideeffects]
def PF_particle() {
    var org : int
    var dir : int
    var color : float
    var count : float
    org = pr_globals + 4 * 4
    dir = pr_globals + 7 * 4
    color = uint_bits_to_float(uint(c2da_mem[pr_globals + 10 * 4]) | uint(c2da_mem[pr_globals + 10 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 10 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 10 * 4 + 3]) << 0x18)
    count = uint_bits_to_float(uint(c2da_mem[pr_globals + 13 * 4]) | uint(c2da_mem[pr_globals + 13 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 13 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 13 * 4 + 3]) << 0x18)
    SV_StartParticle(org, dir, int(color), int(count))
    return
}
[export, sideeffects]
def PF_nextent() {
    var i_5 : int
    var ent_3 : int
    i_5 = NUM_FOR_EDICT(int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18))
    while (true) {
        i_5++
        if (i_5 == int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
            let c2da_fresh20 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
            let c2da_fresh21 : uint = uint(c2da_fresh20)
            c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh21)
            c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh21 >> 0x8)
            c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh21 >> 0x10)
            c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh21 >> 0x18)
            return
        }
        ent_3 = EDICT_NUM(i_5)
        if ((uint(c2da_mem[ent_3]) | uint(c2da_mem[ent_3 + 1]) << 0x8 | uint(c2da_mem[ent_3 + 2]) << 0x10 | uint(c2da_mem[ent_3 + 3]) << 0x18) == 0u) {
            let c2da_fresh22 : int = ent_3 - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
            let c2da_fresh23 : uint = uint(c2da_fresh22)
            c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh23)
            c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh23 >> 0x8)
            c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh23 >> 0x10)
            c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh23 >> 0x18)
            return
        }
    }
}
[export, sideeffects]
def PF_localcmd() {
    var str : int = pr_strings + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    Cbuf_AddText(str)
    return
}
[export, sideeffects]
def PF_cvar() {
    var str_0 : int = pr_strings + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    let c2da_fresh24 : float = Cvar_VariableValue(str_0)
    let c2da_fresh25 : uint = float_bits_to_uint(c2da_fresh24)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh25)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh25 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh25 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh25 >> 0x18)
    return
}
[export, sideeffects]
def PF_aim() {
    let c2da_saved_sp : int = c2da_lin_sp
    PF_aim_c2da_frame(c2da_lin_enter(48))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def PF_fabs() {
    var v : float = uint_bits_to_float(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    let c2da_fresh79 : float = float(c2da_std_fabs(double(v)))
    let c2da_fresh80 : uint = float_bits_to_uint(c2da_fresh79)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh80)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh80 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh80 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh80 >> 0x18)
    return
}
[export, sideeffects]
def PF_pointcontents() {
    var v_0 : int = pr_globals + 4 * 4
    let c2da_fresh81 : float = float(SV_PointContents(v_0))
    let c2da_fresh82 : uint = float_bits_to_uint(c2da_fresh81)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh82)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh82 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh82 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh82 >> 0x18)
    return
}
[export, sideeffects]
def PF_checkbottom() {
    var ent_5 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    let c2da_fresh83 : float = float(uint(SV_CheckBottom(ent_5)))
    let c2da_fresh84 : uint = float_bits_to_uint(c2da_fresh83)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh84)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh84 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh84 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh84 >> 0x18)
    return
}
[export, sideeffects]
def PF_ceil() {
    let c2da_fresh85 : float = float(ceil(double(uint_bits_to_float(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18))))
    let c2da_fresh86 : uint = float_bits_to_uint(c2da_fresh85)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh86)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh86 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh86 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh86 >> 0x18)
    return
}
[export, sideeffects]
def PF_floor() {
    let c2da_fresh87 : float = float(floor(double(uint_bits_to_float(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18))))
    let c2da_fresh88 : uint = float_bits_to_uint(c2da_fresh87)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh88)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh88 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh88 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh88 >> 0x18)
    return
}
[export, sideeffects]
def PF_rint() {
    var f : float = uint_bits_to_float(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    if (f > 0.0) {
        let c2da_fresh89 : float = float(int(double(f) + 0.5lf))
        let c2da_fresh90 : uint = float_bits_to_uint(c2da_fresh89)
        c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh90)
        c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh90 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh90 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh90 >> 0x18)
    } else {
        let c2da_fresh91 : float = float(int(double(f) - 0.5lf))
        let c2da_fresh92 : uint = float_bits_to_uint(c2da_fresh91)
        c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh92)
        c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh92 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh92 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh92 >> 0x18)
    }
    return
}
[export, sideeffects]
def PF_lightstyle() {
    var style : int
    var val_0 : int
    var client_1 : int
    var j_0 : int
    style = int(uint_bits_to_float(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18))
    val_0 = pr_strings + int(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18)
    let c2da_fresh93 : uint = uint(val_0)
    c2da_mem[232176 + style * 8] = uint8(c2da_fresh93)
    c2da_mem[232176 + style * 8 + 1] = uint8(c2da_fresh93 >> 0x8)
    c2da_mem[232176 + style * 8 + 2] = uint8(c2da_fresh93 >> 0x10)
    c2da_mem[232176 + style * 8 + 3] = uint8(c2da_fresh93 >> 0x18)
    c2da_mem[232176 + style * 8 + 4] = 0u8
    c2da_mem[232176 + style * 8 + 5] = 0u8
    c2da_mem[232176 + style * 8 + 6] = 0u8
    c2da_mem[232176 + style * 8 + 7] = 0u8
    if ((uint(c2da_mem[232704]) | uint(c2da_mem[232705]) << 0x8 | uint(c2da_mem[232706]) << 0x10 | uint(c2da_mem[232707]) << 0x18) != 1u) {
        return
    }
    j_0 = 0
    client_1 = svs.clients
    while (j_0 < svs.maxclients) {
        if ((uint(c2da_mem[client_1]) | uint(c2da_mem[client_1 + 1]) << 0x8 | uint(c2da_mem[client_1 + 2]) << 0x10 | uint(c2da_mem[client_1 + 3]) << 0x18) != 0x0 || (uint(c2da_mem[client_1 + 4]) | uint(c2da_mem[client_1 + 5]) << 0x8 | uint(c2da_mem[client_1 + 6]) << 0x10 | uint(c2da_mem[client_1 + 7]) << 0x18) != 0x0) {
            MSG_WriteChar(client_1 + 80, 12)
            MSG_WriteChar(client_1 + 80, style)
            MSG_WriteString(client_1 + 80, val_0)
        }
        j_0++
        client_1 += 8288
    }
    return
}
[export, sideeffects]
def PF_droptofloor() {
    let c2da_saved_sp : int = c2da_lin_sp
    PF_droptofloor_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def PF_walkmove() {
    let c2da_saved_sp : int = c2da_lin_sp
    PF_walkmove_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def PF_eprint() {
    ED_PrintNum(NUM_FOR_EDICT(int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)))
    return
}
[export, sideeffects]
def PF_traceoff() {
    pr_trace = 0u
    return
}
[export, sideeffects]
def PF_traceon() {
    pr_trace = 1u
    return
}
[export, sideeffects]
def PF_coredump() {
    ED_PrintEdicts()
    return
}
[export, sideeffects]
def PF_vtos() {
    c2da_lin_snprintf(387696, 2147483647ul, 728669, [C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[pr_globals + 4 * 4 + 0 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 0 * 4 + 3]) << 0x18)), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[pr_globals + 4 * 4 + 1 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 1 * 4 + 3]) << 0x18)), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[pr_globals + 4 * 4 + 2 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 2 * 4 + 3]) << 0x18)), raw = 0x0)])
    let c2da_fresh127 : int = int(int64(387696 - pr_strings))
    let c2da_fresh128 : uint = uint(c2da_fresh127)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh128)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh128 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh128 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh128 >> 0x18)
    return
}
[export, sideeffects]
def PF_ftos() {
    var v_1 : float = uint_bits_to_float(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    if (v_1 == float(int(v_1))) {
        c2da_lin_snprintf(387696, 2147483647ul, 728689, [C2daVaArg(tag = 1, i64 = int64(int(v_1)), f64 = 0.0lf, raw = 0x0)])
    } else {
        c2da_lin_snprintf(387696, 2147483647ul, 728692, [C2daVaArg(tag = 2, i64 = 0, f64 = double(v_1), raw = 0x0)])
    }
    let c2da_fresh129 : int = int(int64(387696 - pr_strings))
    let c2da_fresh130 : uint = uint(c2da_fresh129)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh130)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh130 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh130 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh130 >> 0x18)
    return
}
[export, sideeffects]
def PF_dprint() {
    Con_DPrintf(728698, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(PF_VarString(0)))])
    return
}
[export, sideeffects]
def PF_sprint() {
    var s_4 : int
    var client_2 : int
    var entnum_1 : int = NUM_FOR_EDICT(int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18))
    s_4 = PF_VarString(1)
    if (entnum_1 < 1 || entnum_1 > svs.maxclients) {
        Con_Printf(728547, [])
        return
    }
    client_2 = svs.clients + (entnum_1 - 1) * 8288
    MSG_WriteChar(client_2 + 80, 8)
    MSG_WriteString(client_2 + 80, s_4)
    return
}
[export, sideeffects]
def PF_bprint() {
    var s_5 : int = PF_VarString(0)
    SV_BroadcastPrintf(728698, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(s_5))])
    return
}
[export, sideeffects]
def PF_findradius() {
    let c2da_saved_sp : int = c2da_lin_sp
    PF_findradius_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def PF_stuffcmd() {
    var entnum_2 : int
    var str_1 : int
    var old : int
    entnum_2 = NUM_FOR_EDICT(int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18))
    if (entnum_2 < 1 || entnum_2 > svs.maxclients) {
        PR_RunError(728701, [])
    }
    str_1 = pr_strings + int(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18)
    old = host_client
    host_client = svs.clients + (entnum_2 - 1) * 8288
    Host_ClientCommands(728698, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(str_1))])
    host_client = old
    return
}
[export, sideeffects]
def PF_Find() {
    var e : int
    var f_0 : int
    var s_6 : int
    var t : int
    var ed : int
    e = NUM_FOR_EDICT(int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18))
    f_0 = int(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18)
    s_6 = pr_strings + int(uint(c2da_mem[pr_globals + 10 * 4]) | uint(c2da_mem[pr_globals + 10 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 10 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 10 * 4 + 3]) << 0x18)
    if (s_6 == 0) {
        PR_RunError(728721, [])
    }
    e++
    while (e < int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        ed = EDICT_NUM(e)
        if ((uint(c2da_mem[ed]) | uint(c2da_mem[ed + 1]) << 0x8 | uint(c2da_mem[ed + 2]) << 0x10 | uint(c2da_mem[ed + 3]) << 0x18) != 0u) {
            e++
            continue
        }
        t = pr_strings + int(uint(c2da_mem[ed + 108 + f_0 * 4]) | uint(c2da_mem[ed + 108 + f_0 * 4 + 1]) << 0x8 | uint(c2da_mem[ed + 108 + f_0 * 4 + 2]) << 0x10 | uint(c2da_mem[ed + 108 + f_0 * 4 + 3]) << 0x18)
        if (t == 0) {
            e++
            continue
        }
        if (c2da_lin_strcmp(t, s_6) == 0) {
            let c2da_fresh137 : int = ed - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
            let c2da_fresh138 : uint = uint(c2da_fresh137)
            c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh138)
            c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh138 >> 0x8)
            c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh138 >> 0x10)
            c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh138 >> 0x18)
            return
        }
        e++
    }
    let c2da_fresh139 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    let c2da_fresh140 : uint = uint(c2da_fresh139)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh140)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh140 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh140 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh140 >> 0x18)
    return
}
[export, sideeffects]
def PF_checkclient() {
    let c2da_saved_sp : int = c2da_lin_sp
    PF_checkclient_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
var c_invis : int = default<int>

var c_notvis : int = default<int>

[export, sideeffects]
def PF_newcheckclient(var check_1 : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = PF_newcheckclient_c2da_frame(check_1, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def PF_traceline() {
    var v1 : int
    var v2 : int
    var trace_0 : trace_t
    var nomonsters_0 : int
    var ent_11 : int
    v1 = pr_globals + 4 * 4
    v2 = pr_globals + 7 * 4
    nomonsters_0 = int(uint_bits_to_float(uint(c2da_mem[pr_globals + 10 * 4]) | uint(c2da_mem[pr_globals + 10 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 10 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 10 * 4 + 3]) << 0x18))
    ent_11 = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 13 * 4]) | uint(c2da_mem[pr_globals + 13 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 13 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 13 * 4 + 3]) << 0x18)
    trace_0 = SV_Move(v1, 194432, 194432, v2, nomonsters_0, ent_11)
    let c2da_fresh167 : float = float(trace_0.allsolid)
    let c2da_fresh168 : uint = float_bits_to_uint(c2da_fresh167)
    c2da_mem[pr_global_struct + 272] = uint8(c2da_fresh168)
    c2da_mem[pr_global_struct + 273] = uint8(c2da_fresh168 >> 0x8)
    c2da_mem[pr_global_struct + 274] = uint8(c2da_fresh168 >> 0x10)
    c2da_mem[pr_global_struct + 275] = uint8(c2da_fresh168 >> 0x18)
    let c2da_fresh169 : float = float(trace_0.startsolid)
    let c2da_fresh170 : uint = float_bits_to_uint(c2da_fresh169)
    c2da_mem[pr_global_struct + 276] = uint8(c2da_fresh170)
    c2da_mem[pr_global_struct + 277] = uint8(c2da_fresh170 >> 0x8)
    c2da_mem[pr_global_struct + 278] = uint8(c2da_fresh170 >> 0x10)
    c2da_mem[pr_global_struct + 279] = uint8(c2da_fresh170 >> 0x18)
    let c2da_fresh171 : float = trace_0.fraction
    let c2da_fresh172 : uint = float_bits_to_uint(c2da_fresh171)
    c2da_mem[pr_global_struct + 280] = uint8(c2da_fresh172)
    c2da_mem[pr_global_struct + 281] = uint8(c2da_fresh172 >> 0x8)
    c2da_mem[pr_global_struct + 282] = uint8(c2da_fresh172 >> 0x10)
    c2da_mem[pr_global_struct + 283] = uint8(c2da_fresh172 >> 0x18)
    let c2da_fresh173 : float = float(trace_0.inwater)
    let c2da_fresh174 : uint = float_bits_to_uint(c2da_fresh173)
    c2da_mem[pr_global_struct + 320] = uint8(c2da_fresh174)
    c2da_mem[pr_global_struct + 321] = uint8(c2da_fresh174 >> 0x8)
    c2da_mem[pr_global_struct + 322] = uint8(c2da_fresh174 >> 0x10)
    c2da_mem[pr_global_struct + 323] = uint8(c2da_fresh174 >> 0x18)
    let c2da_fresh175 : float = float(trace_0.inopen)
    let c2da_fresh176 : uint = float_bits_to_uint(c2da_fresh175)
    c2da_mem[pr_global_struct + 316] = uint8(c2da_fresh176)
    c2da_mem[pr_global_struct + 317] = uint8(c2da_fresh176 >> 0x8)
    c2da_mem[pr_global_struct + 318] = uint8(c2da_fresh176 >> 0x10)
    c2da_mem[pr_global_struct + 319] = uint8(c2da_fresh176 >> 0x18)
    let c2da_fresh177 : float = trace_0.endpos[0]
    let c2da_fresh178 : uint = float_bits_to_uint(c2da_fresh177)
    c2da_mem[pr_global_struct + 284 + 0 * 4] = uint8(c2da_fresh178)
    c2da_mem[pr_global_struct + 284 + 0 * 4 + 1] = uint8(c2da_fresh178 >> 0x8)
    c2da_mem[pr_global_struct + 284 + 0 * 4 + 2] = uint8(c2da_fresh178 >> 0x10)
    c2da_mem[pr_global_struct + 284 + 0 * 4 + 3] = uint8(c2da_fresh178 >> 0x18)
    let c2da_fresh179 : float = trace_0.endpos[1]
    let c2da_fresh180 : uint = float_bits_to_uint(c2da_fresh179)
    c2da_mem[pr_global_struct + 284 + 1 * 4] = uint8(c2da_fresh180)
    c2da_mem[pr_global_struct + 284 + 1 * 4 + 1] = uint8(c2da_fresh180 >> 0x8)
    c2da_mem[pr_global_struct + 284 + 1 * 4 + 2] = uint8(c2da_fresh180 >> 0x10)
    c2da_mem[pr_global_struct + 284 + 1 * 4 + 3] = uint8(c2da_fresh180 >> 0x18)
    let c2da_fresh181 : float = trace_0.endpos[2]
    let c2da_fresh182 : uint = float_bits_to_uint(c2da_fresh181)
    c2da_mem[pr_global_struct + 284 + 2 * 4] = uint8(c2da_fresh182)
    c2da_mem[pr_global_struct + 284 + 2 * 4 + 1] = uint8(c2da_fresh182 >> 0x8)
    c2da_mem[pr_global_struct + 284 + 2 * 4 + 2] = uint8(c2da_fresh182 >> 0x10)
    c2da_mem[pr_global_struct + 284 + 2 * 4 + 3] = uint8(c2da_fresh182 >> 0x18)
    let c2da_fresh183 : float = trace_0.plane.normal[0]
    let c2da_fresh184 : uint = float_bits_to_uint(c2da_fresh183)
    c2da_mem[pr_global_struct + 296 + 0 * 4] = uint8(c2da_fresh184)
    c2da_mem[pr_global_struct + 296 + 0 * 4 + 1] = uint8(c2da_fresh184 >> 0x8)
    c2da_mem[pr_global_struct + 296 + 0 * 4 + 2] = uint8(c2da_fresh184 >> 0x10)
    c2da_mem[pr_global_struct + 296 + 0 * 4 + 3] = uint8(c2da_fresh184 >> 0x18)
    let c2da_fresh185 : float = trace_0.plane.normal[1]
    let c2da_fresh186 : uint = float_bits_to_uint(c2da_fresh185)
    c2da_mem[pr_global_struct + 296 + 1 * 4] = uint8(c2da_fresh186)
    c2da_mem[pr_global_struct + 296 + 1 * 4 + 1] = uint8(c2da_fresh186 >> 0x8)
    c2da_mem[pr_global_struct + 296 + 1 * 4 + 2] = uint8(c2da_fresh186 >> 0x10)
    c2da_mem[pr_global_struct + 296 + 1 * 4 + 3] = uint8(c2da_fresh186 >> 0x18)
    let c2da_fresh187 : float = trace_0.plane.normal[2]
    let c2da_fresh188 : uint = float_bits_to_uint(c2da_fresh187)
    c2da_mem[pr_global_struct + 296 + 2 * 4] = uint8(c2da_fresh188)
    c2da_mem[pr_global_struct + 296 + 2 * 4 + 1] = uint8(c2da_fresh188 >> 0x8)
    c2da_mem[pr_global_struct + 296 + 2 * 4 + 2] = uint8(c2da_fresh188 >> 0x10)
    c2da_mem[pr_global_struct + 296 + 2 * 4 + 3] = uint8(c2da_fresh188 >> 0x18)
    let c2da_fresh189 : float = trace_0.plane.dist
    let c2da_fresh190 : uint = float_bits_to_uint(c2da_fresh189)
    c2da_mem[pr_global_struct + 308] = uint8(c2da_fresh190)
    c2da_mem[pr_global_struct + 309] = uint8(c2da_fresh190 >> 0x8)
    c2da_mem[pr_global_struct + 310] = uint8(c2da_fresh190 >> 0x10)
    c2da_mem[pr_global_struct + 311] = uint8(c2da_fresh190 >> 0x18)
    if (trace_0.ent != 0) {
        let c2da_fresh191 : int = trace_0.ent - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh192 : uint = uint(c2da_fresh191)
        c2da_mem[pr_global_struct + 312] = uint8(c2da_fresh192)
        c2da_mem[pr_global_struct + 313] = uint8(c2da_fresh192 >> 0x8)
        c2da_mem[pr_global_struct + 314] = uint8(c2da_fresh192 >> 0x10)
        c2da_mem[pr_global_struct + 315] = uint8(c2da_fresh192 >> 0x18)
    } else {
        let c2da_fresh193 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh194 : uint = uint(c2da_fresh193)
        c2da_mem[pr_global_struct + 312] = uint8(c2da_fresh194)
        c2da_mem[pr_global_struct + 313] = uint8(c2da_fresh194 >> 0x8)
        c2da_mem[pr_global_struct + 314] = uint8(c2da_fresh194 >> 0x10)
        c2da_mem[pr_global_struct + 315] = uint8(c2da_fresh194 >> 0x18)
    }
    return
}
[export, sideeffects]
def PF_Remove() {
    var ed_0 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    ED_Free(ed_0)
    return
}
[export, sideeffects]
def PF_Spawn() {
    var ed_1 : int = ED_Alloc()
    let c2da_fresh195 : int = ed_1 - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    let c2da_fresh196 : uint = uint(c2da_fresh195)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh196)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh196 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh196 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh196 >> 0x18)
    return
}
[export, sideeffects]
def PF_vectoyaw() {
    var value1_0 : int
    var yaw_1 : float
    value1_0 = pr_globals + 4 * 4
    if (uint_bits_to_float(uint(c2da_mem[value1_0 + 1 * 4]) | uint(c2da_mem[value1_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_0 + 1 * 4 + 3]) << 0x18) == 0.0 && uint_bits_to_float(uint(c2da_mem[value1_0 + 0 * 4]) | uint(c2da_mem[value1_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_0 + 0 * 4 + 3]) << 0x18) == 0.0) {
        yaw_1 = 0.0
    } else {
        yaw_1 = float(int(atan2(double(uint_bits_to_float(uint(c2da_mem[value1_0 + 1 * 4]) | uint(c2da_mem[value1_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_0 + 1 * 4 + 3]) << 0x18)), double(uint_bits_to_float(uint(c2da_mem[value1_0 + 0 * 4]) | uint(c2da_mem[value1_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_0 + 0 * 4 + 3]) << 0x18))) * 180.0lf / 3.141592653589793lf))
        if (yaw_1 < 0.0) {
            yaw_1 += 360.0
        }
    }
    let c2da_fresh197 : uint = float_bits_to_uint(yaw_1)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh197)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh197 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh197 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh197 >> 0x18)
    return
}
[export, sideeffects]
def PF_vlen() {
    var value1_1 : int
    var new_0 : float
    value1_1 = pr_globals + 4 * 4
    new_0 = uint_bits_to_float(uint(c2da_mem[value1_1 + 0 * 4]) | uint(c2da_mem[value1_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_1 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[value1_1 + 0 * 4]) | uint(c2da_mem[value1_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_1 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[value1_1 + 1 * 4]) | uint(c2da_mem[value1_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_1 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[value1_1 + 1 * 4]) | uint(c2da_mem[value1_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_1 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[value1_1 + 2 * 4]) | uint(c2da_mem[value1_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_1 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[value1_1 + 2 * 4]) | uint(c2da_mem[value1_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_1 + 2 * 4 + 3]) << 0x18)
    new_0 = float(sqrt(double(new_0)))
    let c2da_fresh198 : uint = float_bits_to_uint(new_0)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh198)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh198 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh198 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh198 >> 0x18)
    return
}
[export, sideeffects]
def PF_objerror() {
    var s_7 : int
    var ed_2 : int
    s_7 = PF_VarString(0)
    Con_Printf(728748, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[pr_xfunction + 16]) | uint(c2da_mem[pr_xfunction + 17]) << 0x8 | uint(c2da_mem[pr_xfunction + 18]) << 0x10 | uint(c2da_mem[pr_xfunction + 19]) << 0x18))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(s_7))])
    ed_2 = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_global_struct + 112]) | uint(c2da_mem[pr_global_struct + 113]) << 0x8 | uint(c2da_mem[pr_global_struct + 114]) << 0x10 | uint(c2da_mem[pr_global_struct + 115]) << 0x18)
    ED_Print(ed_2)
    ED_Free(ed_2)
    Host_Error(728778, [])
    return
}
[export, sideeffects]
def PF_error() {
    var s_8 : int
    var ed_3 : int
    s_8 = PF_VarString(0)
    Con_Printf(728792, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[pr_xfunction + 16]) | uint(c2da_mem[pr_xfunction + 17]) << 0x8 | uint(c2da_mem[pr_xfunction + 18]) << 0x10 | uint(c2da_mem[pr_xfunction + 19]) << 0x18))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(s_8))])
    ed_3 = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_global_struct + 112]) | uint(c2da_mem[pr_global_struct + 113]) << 0x8 | uint(c2da_mem[pr_global_struct + 114]) << 0x10 | uint(c2da_mem[pr_global_struct + 115]) << 0x18)
    ED_Print(ed_3)
    Host_Error(728778, [])
    return
}
[export, sideeffects]
def PF_normalize() {
    var value1_2 : int
    var newvalue : vec3_t
    var new_1 : float
    value1_2 = pr_globals + 4 * 4
    new_1 = uint_bits_to_float(uint(c2da_mem[value1_2 + 0 * 4]) | uint(c2da_mem[value1_2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_2 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[value1_2 + 0 * 4]) | uint(c2da_mem[value1_2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_2 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[value1_2 + 1 * 4]) | uint(c2da_mem[value1_2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_2 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[value1_2 + 1 * 4]) | uint(c2da_mem[value1_2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_2 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[value1_2 + 2 * 4]) | uint(c2da_mem[value1_2 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_2 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_2 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[value1_2 + 2 * 4]) | uint(c2da_mem[value1_2 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_2 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_2 + 2 * 4 + 3]) << 0x18)
    new_1 = float(sqrt(double(new_1)))
    if (new_1 == 0.0) {
        newvalue[2] = 0.0
        newvalue[1] = float(newvalue[2])  // nolint:PERF020
        newvalue[0] = float(newvalue[1])  // nolint:PERF020
    } else {
        new_1 = 1.0 / new_1
        newvalue[0] = uint_bits_to_float(uint(c2da_mem[value1_2 + 0 * 4]) | uint(c2da_mem[value1_2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_2 + 0 * 4 + 3]) << 0x18) * new_1
        newvalue[1] = uint_bits_to_float(uint(c2da_mem[value1_2 + 1 * 4]) | uint(c2da_mem[value1_2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_2 + 1 * 4 + 3]) << 0x18) * new_1
        newvalue[2] = uint_bits_to_float(uint(c2da_mem[value1_2 + 2 * 4]) | uint(c2da_mem[value1_2 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[value1_2 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[value1_2 + 2 * 4 + 3]) << 0x18) * new_1
    }
    let c2da_fresh199 : float = newvalue[0]
    let c2da_fresh200 : uint = float_bits_to_uint(c2da_fresh199)
    c2da_mem[pr_globals + 1 * 4 + 0 * 4] = uint8(c2da_fresh200)
    c2da_mem[pr_globals + 1 * 4 + 0 * 4 + 1] = uint8(c2da_fresh200 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 0 * 4 + 2] = uint8(c2da_fresh200 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 0 * 4 + 3] = uint8(c2da_fresh200 >> 0x18)
    let c2da_fresh201 : float = newvalue[1]
    let c2da_fresh202 : uint = float_bits_to_uint(c2da_fresh201)
    c2da_mem[pr_globals + 1 * 4 + 1 * 4] = uint8(c2da_fresh202)
    c2da_mem[pr_globals + 1 * 4 + 1 * 4 + 1] = uint8(c2da_fresh202 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 1 * 4 + 2] = uint8(c2da_fresh202 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 1 * 4 + 3] = uint8(c2da_fresh202 >> 0x18)
    let c2da_fresh203 : float = newvalue[2]
    let c2da_fresh204 : uint = float_bits_to_uint(c2da_fresh203)
    c2da_mem[pr_globals + 1 * 4 + 2 * 4] = uint8(c2da_fresh204)
    c2da_mem[pr_globals + 1 * 4 + 2 * 4 + 1] = uint8(c2da_fresh204 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2 * 4 + 2] = uint8(c2da_fresh204 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 2 * 4 + 3] = uint8(c2da_fresh204 >> 0x18)
    return
}
[export, sideeffects]
def PF_sound() {
    var sample : int
    var channel : int
    var entity : int
    var volume : int
    var attenuation_0 : float
    entity = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    channel = int(uint_bits_to_float(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18))
    sample = pr_strings + int(uint(c2da_mem[pr_globals + 10 * 4]) | uint(c2da_mem[pr_globals + 10 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 10 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 10 * 4 + 3]) << 0x18)
    volume = int(uint_bits_to_float(uint(c2da_mem[pr_globals + 13 * 4]) | uint(c2da_mem[pr_globals + 13 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 13 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 13 * 4 + 3]) << 0x18) * 255.0)
    attenuation_0 = uint_bits_to_float(uint(c2da_mem[pr_globals + 16 * 4]) | uint(c2da_mem[pr_globals + 16 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 16 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 16 * 4 + 3]) << 0x18)
    if (volume < 0 || volume > 255) {
        Sys_Error(728822, [C2daVaArg(tag = 1, i64 = int64(volume), f64 = 0.0lf, raw = 0x0)])
    }
    if (attenuation_0 < 0.0 || attenuation_0 > 4.0) {
        Sys_Error(728849, [C2daVaArg(tag = 2, i64 = 0, f64 = double(attenuation_0), raw = 0x0)])
    }
    if (channel < 0 || channel > 7) {
        Sys_Error(728881, [C2daVaArg(tag = 1, i64 = int64(channel), f64 = 0.0lf, raw = 0x0)])
    }
    SV_StartSound(entity, channel, sample, volume, attenuation_0)
    return
}
[export, sideeffects]
def PF_random() {
    var num : float = float(c2da_std_rand() & 32767) / 32767.0
    let c2da_fresh205 : uint = float_bits_to_uint(num)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh205)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh205 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh205 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh205 >> 0x18)
    return
}
[export, sideeffects]
def PF_break() {
    Con_Printf(728909, [])
    let c2da_fresh206 : int = -4
    let c2da_fresh207 : int = 0
    let c2da_fresh208 : uint = uint(c2da_fresh207)
    c2da_mem[c2da_fresh206] = uint8(c2da_fresh208)
    c2da_mem[c2da_fresh206 + 1] = uint8(c2da_fresh208 >> 0x8)
    c2da_mem[c2da_fresh206 + 2] = uint8(c2da_fresh208 >> 0x10)
    c2da_mem[c2da_fresh206 + 3] = uint8(c2da_fresh208 >> 0x18)
    return
}
[export, sideeffects]
def PF_setsize() {
    var e_0 : int
    var min : int
    var max : int
    e_0 = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    min = pr_globals + 7 * 4
    max = pr_globals + 10 * 4
    SetMinMaxSize(e_0, min, max, 0u)
    return
}
[export, sideeffects]
def SetMinMaxSize(var e_1 : int; var min_0 : int; var max_0 : int; var rotate : uint) {
    var rmin : vec3_t
    var rmax : vec3_t
    var bounds : float[2][3]
    var xvector : float[2]
    var yvector : float[2]
    var a : float
    var base : vec3_t
    var transformed : vec3_t
    var i_9 : int
    var j_2 : int
    var k : int
    i_9 = 0
    while (i_9 < 3) {
        if (uint_bits_to_float(uint(c2da_mem[min_0 + i_9 * 4]) | uint(c2da_mem[min_0 + i_9 * 4 + 1]) << 0x8 | uint(c2da_mem[min_0 + i_9 * 4 + 2]) << 0x10 | uint(c2da_mem[min_0 + i_9 * 4 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[max_0 + i_9 * 4]) | uint(c2da_mem[max_0 + i_9 * 4 + 1]) << 0x8 | uint(c2da_mem[max_0 + i_9 * 4 + 2]) << 0x10 | uint(c2da_mem[max_0 + i_9 * 4 + 3]) << 0x18)) {
            PR_RunError(728926, [])
        }
        i_9++
    }
    rotate = 0u
    if (rotate == 0u) {
        rmin[0] = uint_bits_to_float(uint(c2da_mem[min_0 + 0 * 4]) | uint(c2da_mem[min_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[min_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[min_0 + 0 * 4 + 3]) << 0x18)
        rmin[1] = uint_bits_to_float(uint(c2da_mem[min_0 + 1 * 4]) | uint(c2da_mem[min_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[min_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[min_0 + 1 * 4 + 3]) << 0x18)
        rmin[2] = uint_bits_to_float(uint(c2da_mem[min_0 + 2 * 4]) | uint(c2da_mem[min_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[min_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[min_0 + 2 * 4 + 3]) << 0x18)
        rmax[0] = uint_bits_to_float(uint(c2da_mem[max_0 + 0 * 4]) | uint(c2da_mem[max_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[max_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[max_0 + 0 * 4 + 3]) << 0x18)
        rmax[1] = uint_bits_to_float(uint(c2da_mem[max_0 + 1 * 4]) | uint(c2da_mem[max_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[max_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[max_0 + 1 * 4 + 3]) << 0x18)
        rmax[2] = uint_bits_to_float(uint(c2da_mem[max_0 + 2 * 4]) | uint(c2da_mem[max_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[max_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[max_0 + 2 * 4 + 3]) << 0x18)
    } else {
        a = float(double(uint_bits_to_float(uint(c2da_mem[e_1 + 184 + 1 * 4]) | uint(c2da_mem[e_1 + 184 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[e_1 + 184 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[e_1 + 184 + 1 * 4 + 3]) << 0x18) / 180.0) * 3.141592653589793lf)
        xvector[0] = float(cos(double(a)))
        xvector[1] = float(sin(double(a)))
        yvector[0] = float(-sin(double(a)))
        yvector[1] = float(cos(double(a)))
        bounds[0][0] = uint_bits_to_float(uint(c2da_mem[min_0 + 0 * 4]) | uint(c2da_mem[min_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[min_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[min_0 + 0 * 4 + 3]) << 0x18)
        bounds[0][1] = uint_bits_to_float(uint(c2da_mem[min_0 + 1 * 4]) | uint(c2da_mem[min_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[min_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[min_0 + 1 * 4 + 3]) << 0x18)
        bounds[0][2] = uint_bits_to_float(uint(c2da_mem[min_0 + 2 * 4]) | uint(c2da_mem[min_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[min_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[min_0 + 2 * 4 + 3]) << 0x18)
        bounds[1][0] = uint_bits_to_float(uint(c2da_mem[max_0 + 0 * 4]) | uint(c2da_mem[max_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[max_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[max_0 + 0 * 4 + 3]) << 0x18)
        bounds[1][1] = uint_bits_to_float(uint(c2da_mem[max_0 + 1 * 4]) | uint(c2da_mem[max_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[max_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[max_0 + 1 * 4 + 3]) << 0x18)
        bounds[1][2] = uint_bits_to_float(uint(c2da_mem[max_0 + 2 * 4]) | uint(c2da_mem[max_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[max_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[max_0 + 2 * 4 + 3]) << 0x18)
        rmin[2] = 9999.0
        rmin[1] = float(rmin[2])  // nolint:PERF020
        rmin[0] = float(rmin[1])  // nolint:PERF020
        rmax[2] = -9999.0
        rmax[1] = float(rmax[2])  // nolint:PERF020
        rmax[0] = float(rmax[1])  // nolint:PERF020
        i_9 = 0
        while (i_9 <= 1) {
            base[0] = float(bounds[i_9][0])  // nolint:PERF020
            j_2 = 0
            while (j_2 <= 1) {
                base[1] = float(bounds[j_2][1])  // nolint:PERF020
                k = 0
                while (k <= 1) {
                    base[2] = float(bounds[k][2])  // nolint:PERF020
                    transformed[0] = xvector[0] * base[0] + yvector[0] * base[1]
                    transformed[1] = xvector[1] * base[0] + yvector[1] * base[1]
                    transformed[2] = float(base[2])  // nolint:PERF020
                    for (l_0 in range(0, 3)) {
                        if (transformed[l_0] < rmin[l_0]) {
                            rmin[l_0] = float(transformed[l_0])  // nolint:PERF020
                        }
                        if (transformed[l_0] > rmax[l_0]) {
                            rmax[l_0] = float(transformed[l_0])  // nolint:PERF020
                        }
                    }
                    k++
                }
                j_2++
            }
            i_9++
        }
    }
    let c2da_fresh209 : float = rmin[0]
    let c2da_fresh210 : uint = float_bits_to_uint(c2da_fresh209)
    c2da_mem[e_1 + 240 + 0 * 4] = uint8(c2da_fresh210)
    c2da_mem[e_1 + 240 + 0 * 4 + 1] = uint8(c2da_fresh210 >> 0x8)
    c2da_mem[e_1 + 240 + 0 * 4 + 2] = uint8(c2da_fresh210 >> 0x10)
    c2da_mem[e_1 + 240 + 0 * 4 + 3] = uint8(c2da_fresh210 >> 0x18)
    let c2da_fresh211 : float = rmin[1]
    let c2da_fresh212 : uint = float_bits_to_uint(c2da_fresh211)
    c2da_mem[e_1 + 240 + 1 * 4] = uint8(c2da_fresh212)
    c2da_mem[e_1 + 240 + 1 * 4 + 1] = uint8(c2da_fresh212 >> 0x8)
    c2da_mem[e_1 + 240 + 1 * 4 + 2] = uint8(c2da_fresh212 >> 0x10)
    c2da_mem[e_1 + 240 + 1 * 4 + 3] = uint8(c2da_fresh212 >> 0x18)
    let c2da_fresh213 : float = rmin[2]
    let c2da_fresh214 : uint = float_bits_to_uint(c2da_fresh213)
    c2da_mem[e_1 + 240 + 2 * 4] = uint8(c2da_fresh214)
    c2da_mem[e_1 + 240 + 2 * 4 + 1] = uint8(c2da_fresh214 >> 0x8)
    c2da_mem[e_1 + 240 + 2 * 4 + 2] = uint8(c2da_fresh214 >> 0x10)
    c2da_mem[e_1 + 240 + 2 * 4 + 3] = uint8(c2da_fresh214 >> 0x18)
    let c2da_fresh215 : float = rmax[0]
    let c2da_fresh216 : uint = float_bits_to_uint(c2da_fresh215)
    c2da_mem[e_1 + 252 + 0 * 4] = uint8(c2da_fresh216)
    c2da_mem[e_1 + 252 + 0 * 4 + 1] = uint8(c2da_fresh216 >> 0x8)
    c2da_mem[e_1 + 252 + 0 * 4 + 2] = uint8(c2da_fresh216 >> 0x10)
    c2da_mem[e_1 + 252 + 0 * 4 + 3] = uint8(c2da_fresh216 >> 0x18)
    let c2da_fresh217 : float = rmax[1]
    let c2da_fresh218 : uint = float_bits_to_uint(c2da_fresh217)
    c2da_mem[e_1 + 252 + 1 * 4] = uint8(c2da_fresh218)
    c2da_mem[e_1 + 252 + 1 * 4 + 1] = uint8(c2da_fresh218 >> 0x8)
    c2da_mem[e_1 + 252 + 1 * 4 + 2] = uint8(c2da_fresh218 >> 0x10)
    c2da_mem[e_1 + 252 + 1 * 4 + 3] = uint8(c2da_fresh218 >> 0x18)
    let c2da_fresh219 : float = rmax[2]
    let c2da_fresh220 : uint = float_bits_to_uint(c2da_fresh219)
    c2da_mem[e_1 + 252 + 2 * 4] = uint8(c2da_fresh220)
    c2da_mem[e_1 + 252 + 2 * 4 + 1] = uint8(c2da_fresh220 >> 0x8)
    c2da_mem[e_1 + 252 + 2 * 4 + 2] = uint8(c2da_fresh220 >> 0x10)
    c2da_mem[e_1 + 252 + 2 * 4 + 3] = uint8(c2da_fresh220 >> 0x18)
    let c2da_fresh221 : float = uint_bits_to_float(uint(c2da_mem[max_0 + 0 * 4]) | uint(c2da_mem[max_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[max_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[max_0 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[min_0 + 0 * 4]) | uint(c2da_mem[min_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[min_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[min_0 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh222 : uint = float_bits_to_uint(c2da_fresh221)
    c2da_mem[e_1 + 264 + 0 * 4] = uint8(c2da_fresh222)
    c2da_mem[e_1 + 264 + 0 * 4 + 1] = uint8(c2da_fresh222 >> 0x8)
    c2da_mem[e_1 + 264 + 0 * 4 + 2] = uint8(c2da_fresh222 >> 0x10)
    c2da_mem[e_1 + 264 + 0 * 4 + 3] = uint8(c2da_fresh222 >> 0x18)
    let c2da_fresh223 : float = uint_bits_to_float(uint(c2da_mem[max_0 + 1 * 4]) | uint(c2da_mem[max_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[max_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[max_0 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[min_0 + 1 * 4]) | uint(c2da_mem[min_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[min_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[min_0 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh224 : uint = float_bits_to_uint(c2da_fresh223)
    c2da_mem[e_1 + 264 + 1 * 4] = uint8(c2da_fresh224)
    c2da_mem[e_1 + 264 + 1 * 4 + 1] = uint8(c2da_fresh224 >> 0x8)
    c2da_mem[e_1 + 264 + 1 * 4 + 2] = uint8(c2da_fresh224 >> 0x10)
    c2da_mem[e_1 + 264 + 1 * 4 + 3] = uint8(c2da_fresh224 >> 0x18)
    let c2da_fresh225 : float = uint_bits_to_float(uint(c2da_mem[max_0 + 2 * 4]) | uint(c2da_mem[max_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[max_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[max_0 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[min_0 + 2 * 4]) | uint(c2da_mem[min_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[min_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[min_0 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh226 : uint = float_bits_to_uint(c2da_fresh225)
    c2da_mem[e_1 + 264 + 2 * 4] = uint8(c2da_fresh226)
    c2da_mem[e_1 + 264 + 2 * 4 + 1] = uint8(c2da_fresh226 >> 0x8)
    c2da_mem[e_1 + 264 + 2 * 4 + 2] = uint8(c2da_fresh226 >> 0x10)
    c2da_mem[e_1 + 264 + 2 * 4 + 3] = uint8(c2da_fresh226 >> 0x18)
    SV_LinkEdict(e_1, 0u)
    return
}
[export, sideeffects]
def PF_setmodel() {
    var e_2 : int
    var m : int
    var check_2 : int
    var mod : int
    var i_10 : int
    e_2 = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    m = pr_strings + int(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18)
    i_10 = 0
    check_2 = 226032
    while (int(uint(c2da_mem[check_2]) | uint(c2da_mem[check_2 + 1]) << 0x8 | uint(c2da_mem[check_2 + 2]) << 0x10 | uint(c2da_mem[check_2 + 3]) << 0x18) != 0) {
        if (c2da_lin_strcmp(int(uint(c2da_mem[check_2]) | uint(c2da_mem[check_2 + 1]) << 0x8 | uint(c2da_mem[check_2 + 2]) << 0x10 | uint(c2da_mem[check_2 + 3]) << 0x18), m) == 0) {
            break
        }
        i_10++
        check_2 += 8
    }
    if (int(uint(c2da_mem[check_2]) | uint(c2da_mem[check_2 + 1]) << 0x8 | uint(c2da_mem[check_2 + 2]) << 0x10 | uint(c2da_mem[check_2 + 3]) << 0x18) == 0) {
        PR_RunError(728530, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(m))])
    }
    let c2da_fresh227 : int = int(int64(m - pr_strings))
    let c2da_fresh228 : uint = uint(c2da_fresh227)
    c2da_mem[e_2 + 224] = uint8(c2da_fresh228)
    c2da_mem[e_2 + 225] = uint8(c2da_fresh228 >> 0x8)
    c2da_mem[e_2 + 226] = uint8(c2da_fresh228 >> 0x10)
    c2da_mem[e_2 + 227] = uint8(c2da_fresh228 >> 0x18)
    let c2da_fresh229 : float = float(i_10)
    let c2da_fresh230 : uint = float_bits_to_uint(c2da_fresh229)
    c2da_mem[e_2 + 108] = uint8(c2da_fresh230)
    c2da_mem[e_2 + 109] = uint8(c2da_fresh230 >> 0x8)
    c2da_mem[e_2 + 110] = uint8(c2da_fresh230 >> 0x10)
    c2da_mem[e_2 + 111] = uint8(c2da_fresh230 >> 0x18)
    let c2da_fresh231 : int = 228080 + int(uint_bits_to_float(uint(c2da_mem[e_2 + 108]) | uint(c2da_mem[e_2 + 109]) << 0x8 | uint(c2da_mem[e_2 + 110]) << 0x10 | uint(c2da_mem[e_2 + 111]) << 0x18)) * 8
    mod = int(uint(c2da_mem[c2da_fresh231]) | uint(c2da_mem[c2da_fresh231 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh231 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh231 + 3]) << 0x18)
    if (mod != 0) {
        SetMinMaxSize(e_2, mod + 84, mod + 96, 1u)
    } else {
        SetMinMaxSize(e_2, 194432, 194432, 1u)
    }
    return
}
[export, sideeffects]
def PF_setorigin() {
    var e_3 : int
    var org_1 : int
    e_3 = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    org_1 = pr_globals + 7 * 4
    let c2da_fresh232 : float = uint_bits_to_float(uint(c2da_mem[org_1 + 0 * 4]) | uint(c2da_mem[org_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[org_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[org_1 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh233 : uint = float_bits_to_uint(c2da_fresh232)
    c2da_mem[e_3 + 148 + 0 * 4] = uint8(c2da_fresh233)
    c2da_mem[e_3 + 148 + 0 * 4 + 1] = uint8(c2da_fresh233 >> 0x8)
    c2da_mem[e_3 + 148 + 0 * 4 + 2] = uint8(c2da_fresh233 >> 0x10)
    c2da_mem[e_3 + 148 + 0 * 4 + 3] = uint8(c2da_fresh233 >> 0x18)
    let c2da_fresh234 : float = uint_bits_to_float(uint(c2da_mem[org_1 + 1 * 4]) | uint(c2da_mem[org_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[org_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[org_1 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh235 : uint = float_bits_to_uint(c2da_fresh234)
    c2da_mem[e_3 + 148 + 1 * 4] = uint8(c2da_fresh235)
    c2da_mem[e_3 + 148 + 1 * 4 + 1] = uint8(c2da_fresh235 >> 0x8)
    c2da_mem[e_3 + 148 + 1 * 4 + 2] = uint8(c2da_fresh235 >> 0x10)
    c2da_mem[e_3 + 148 + 1 * 4 + 3] = uint8(c2da_fresh235 >> 0x18)
    let c2da_fresh236 : float = uint_bits_to_float(uint(c2da_mem[org_1 + 2 * 4]) | uint(c2da_mem[org_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[org_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[org_1 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh237 : uint = float_bits_to_uint(c2da_fresh236)
    c2da_mem[e_3 + 148 + 2 * 4] = uint8(c2da_fresh237)
    c2da_mem[e_3 + 148 + 2 * 4 + 1] = uint8(c2da_fresh237 >> 0x8)
    c2da_mem[e_3 + 148 + 2 * 4 + 2] = uint8(c2da_fresh237 >> 0x10)
    c2da_mem[e_3 + 148 + 2 * 4 + 3] = uint8(c2da_fresh237 >> 0x18)
    SV_LinkEdict(e_3, 0u)
    return
}
[export, sideeffects]
def PF_makevectors() {
    AngleVectors(pr_globals + 4 * 4, pr_global_struct + 236, pr_global_struct + 260, pr_global_struct + 248)
    return
}
var pr_numbuiltins : int = int(632ul / 8ul)

[export, sideeffects]
def PF_checkpos() {
    return
}
[sideeffects]
def private PF_aim_c2da_frame(c2da_fp : int) {
    var ent_4 : int
    var check_0 : int
    var bestent : int
    var bestdir : vec3_t
    var i_6 : int
    var tr : trace_t
    var dist : float
    var bestdist : float
    var speed_0 : float
    ent_4 = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    speed_0 = uint_bits_to_float(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18)
    let c2da_fresh26 : float = uint_bits_to_float(uint(c2da_mem[ent_4 + 148 + 0 * 4]) | uint(c2da_mem[ent_4 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_4 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_4 + 148 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh27 : uint = float_bits_to_uint(c2da_fresh26)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh27)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh27 >> 0x18)
    let c2da_fresh28 : float = uint_bits_to_float(uint(c2da_mem[ent_4 + 148 + 1 * 4]) | uint(c2da_mem[ent_4 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_4 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_4 + 148 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh29 : uint = float_bits_to_uint(c2da_fresh28)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh29)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh29 >> 0x18)
    let c2da_fresh30 : float = uint_bits_to_float(uint(c2da_mem[ent_4 + 148 + 2 * 4]) | uint(c2da_mem[ent_4 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_4 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_4 + 148 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh31 : uint = float_bits_to_uint(c2da_fresh30)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh31)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh31 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh31 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh31 >> 0x18)
    let c2da_fresh32 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) + 20.0
    let c2da_fresh33 : uint = float_bits_to_uint(c2da_fresh32)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh33)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh33 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh33 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh33 >> 0x18)
    let c2da_fresh34 : float = uint_bits_to_float(uint(c2da_mem[pr_global_struct + 236 + 0 * 4]) | uint(c2da_mem[pr_global_struct + 236 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_global_struct + 236 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_global_struct + 236 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh35 : uint = float_bits_to_uint(c2da_fresh34)
    c2da_mem[c2da_fp + 16 + 0 * 4] = uint8(c2da_fresh35)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 1] = uint8(c2da_fresh35 >> 0x8)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 2] = uint8(c2da_fresh35 >> 0x10)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 3] = uint8(c2da_fresh35 >> 0x18)
    let c2da_fresh36 : float = uint_bits_to_float(uint(c2da_mem[pr_global_struct + 236 + 1 * 4]) | uint(c2da_mem[pr_global_struct + 236 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_global_struct + 236 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_global_struct + 236 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh37 : uint = float_bits_to_uint(c2da_fresh36)
    c2da_mem[c2da_fp + 16 + 1 * 4] = uint8(c2da_fresh37)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 1] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 2] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 3] = uint8(c2da_fresh37 >> 0x18)
    let c2da_fresh38 : float = uint_bits_to_float(uint(c2da_mem[pr_global_struct + 236 + 2 * 4]) | uint(c2da_mem[pr_global_struct + 236 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_global_struct + 236 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_global_struct + 236 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh39 : uint = float_bits_to_uint(c2da_fresh38)
    c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh39)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh39 >> 0x8)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh39 >> 0x10)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh39 >> 0x18)
    VectorMA(c2da_fp, 2048.0, c2da_fp + 16, c2da_fp + 32)
    tr = SV_Move(c2da_fp, 194432, 194432, c2da_fp + 32, 0, ent_4)
    var c2da_fresh41 : int = 0
    if (tr.ent != 0) {
        let c2da_fresh40 : int = tr.ent + 344
        if (uint_bits_to_float(uint(c2da_mem[c2da_fresh40]) | uint(c2da_mem[c2da_fresh40 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh40 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh40 + 3]) << 0x18) == 2.0) {
            c2da_fresh41 = 1
        }
    }
    var c2da_fresh44 : int = 0
    if (c2da_fresh41 != 0) {
        var c2da_fresh43 : int = 1
        if (!(uint_bits_to_float(uint(c2da_mem[243464]) | uint(c2da_mem[243465]) << 0x8 | uint(c2da_mem[243466]) << 0x10 | uint(c2da_mem[243467]) << 0x18) == 0.0 || uint_bits_to_float(uint(c2da_mem[ent_4 + 420]) | uint(c2da_mem[ent_4 + 421]) << 0x8 | uint(c2da_mem[ent_4 + 422]) << 0x10 | uint(c2da_mem[ent_4 + 423]) << 0x18) <= 0.0)) {
            let c2da_fresh42 : int = tr.ent + 420
            if (!(uint_bits_to_float(uint(c2da_mem[ent_4 + 420]) | uint(c2da_mem[ent_4 + 421]) << 0x8 | uint(c2da_mem[ent_4 + 422]) << 0x10 | uint(c2da_mem[ent_4 + 423]) << 0x18) != uint_bits_to_float(uint(c2da_mem[c2da_fresh42]) | uint(c2da_mem[c2da_fresh42 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh42 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh42 + 3]) << 0x18))) {
                c2da_fresh43 = 0
            }
        }
        if (c2da_fresh43 != 0) {
            c2da_fresh44 = 1
        }
    }
    if (c2da_fresh44 != 0) {
        let c2da_fresh45 : float = uint_bits_to_float(uint(c2da_mem[pr_global_struct + 236 + 0 * 4]) | uint(c2da_mem[pr_global_struct + 236 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_global_struct + 236 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_global_struct + 236 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh46 : uint = float_bits_to_uint(c2da_fresh45)
        c2da_mem[pr_globals + 1 * 4 + 0 * 4] = uint8(c2da_fresh46)
        c2da_mem[pr_globals + 1 * 4 + 0 * 4 + 1] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 0 * 4 + 2] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 0 * 4 + 3] = uint8(c2da_fresh46 >> 0x18)
        let c2da_fresh47 : float = uint_bits_to_float(uint(c2da_mem[pr_global_struct + 236 + 1 * 4]) | uint(c2da_mem[pr_global_struct + 236 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_global_struct + 236 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_global_struct + 236 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh48 : uint = float_bits_to_uint(c2da_fresh47)
        c2da_mem[pr_globals + 1 * 4 + 1 * 4] = uint8(c2da_fresh48)
        c2da_mem[pr_globals + 1 * 4 + 1 * 4 + 1] = uint8(c2da_fresh48 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 1 * 4 + 2] = uint8(c2da_fresh48 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 1 * 4 + 3] = uint8(c2da_fresh48 >> 0x18)
        let c2da_fresh49 : float = uint_bits_to_float(uint(c2da_mem[pr_global_struct + 236 + 2 * 4]) | uint(c2da_mem[pr_global_struct + 236 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_global_struct + 236 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_global_struct + 236 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh50 : uint = float_bits_to_uint(c2da_fresh49)
        c2da_mem[pr_globals + 1 * 4 + 2 * 4] = uint8(c2da_fresh50)
        c2da_mem[pr_globals + 1 * 4 + 2 * 4 + 1] = uint8(c2da_fresh50 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 2 * 4 + 2] = uint8(c2da_fresh50 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 2 * 4 + 3] = uint8(c2da_fresh50 >> 0x18)
        return
    }
    bestdir[0] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18)
    bestdir[1] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18)
    bestdir[2] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18)
    bestdist = uint_bits_to_float(uint(c2da_mem[462952]) | uint(c2da_mem[462953]) << 0x8 | uint(c2da_mem[462954]) << 0x10 | uint(c2da_mem[462955]) << 0x18)
    bestent = 0
    check_0 = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(pr_edict_size)
    i_6 = 1
    while (i_6 < int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        if (uint_bits_to_float(uint(c2da_mem[check_0 + 344]) | uint(c2da_mem[check_0 + 345]) << 0x8 | uint(c2da_mem[check_0 + 346]) << 0x10 | uint(c2da_mem[check_0 + 347]) << 0x18) != 2.0) {
            i_6++
            check_0 += int(pr_edict_size)
            continue
        }
        if (check_0 == ent_4) {
            i_6++
            check_0 += int(pr_edict_size)
            continue
        }
        if (uint_bits_to_float(uint(c2da_mem[243464]) | uint(c2da_mem[243465]) << 0x8 | uint(c2da_mem[243466]) << 0x10 | uint(c2da_mem[243467]) << 0x18) != 0.0 && uint_bits_to_float(uint(c2da_mem[ent_4 + 420]) | uint(c2da_mem[ent_4 + 421]) << 0x8 | uint(c2da_mem[ent_4 + 422]) << 0x10 | uint(c2da_mem[ent_4 + 423]) << 0x18) > 0.0 && uint_bits_to_float(uint(c2da_mem[ent_4 + 420]) | uint(c2da_mem[ent_4 + 421]) << 0x8 | uint(c2da_mem[ent_4 + 422]) << 0x10 | uint(c2da_mem[ent_4 + 423]) << 0x18) == uint_bits_to_float(uint(c2da_mem[check_0 + 420]) | uint(c2da_mem[check_0 + 421]) << 0x8 | uint(c2da_mem[check_0 + 422]) << 0x10 | uint(c2da_mem[check_0 + 423]) << 0x18)) {
            i_6++
            check_0 += int(pr_edict_size)
            continue
        }
        for (j in range(0, 3)) {
            let c2da_fresh51 : float = float(double(uint_bits_to_float(uint(c2da_mem[check_0 + 148 + j * 4]) | uint(c2da_mem[check_0 + 148 + j * 4 + 1]) << 0x8 | uint(c2da_mem[check_0 + 148 + j * 4 + 2]) << 0x10 | uint(c2da_mem[check_0 + 148 + j * 4 + 3]) << 0x18)) + 0.5lf * double(uint_bits_to_float(uint(c2da_mem[check_0 + 240 + j * 4]) | uint(c2da_mem[check_0 + 240 + j * 4 + 1]) << 0x8 | uint(c2da_mem[check_0 + 240 + j * 4 + 2]) << 0x10 | uint(c2da_mem[check_0 + 240 + j * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[check_0 + 252 + j * 4]) | uint(c2da_mem[check_0 + 252 + j * 4 + 1]) << 0x8 | uint(c2da_mem[check_0 + 252 + j * 4 + 2]) << 0x10 | uint(c2da_mem[check_0 + 252 + j * 4 + 3]) << 0x18)))
            let c2da_fresh52 : uint = float_bits_to_uint(c2da_fresh51)
            c2da_mem[c2da_fp + 32 + j * 4] = uint8(c2da_fresh52)
            c2da_mem[c2da_fp + 32 + j * 4 + 1] = uint8(c2da_fresh52 >> 0x8)
            c2da_mem[c2da_fp + 32 + j * 4 + 2] = uint8(c2da_fresh52 >> 0x10)
            c2da_mem[c2da_fp + 32 + j * 4 + 3] = uint8(c2da_fresh52 >> 0x18)
        }
        let c2da_fresh53 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 0 * 4]) | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
        let c2da_fresh54 : uint = float_bits_to_uint(c2da_fresh53)
        c2da_mem[c2da_fp + 16 + 0 * 4] = uint8(c2da_fresh54)
        c2da_mem[c2da_fp + 16 + 0 * 4 + 1] = uint8(c2da_fresh54 >> 0x8)
        c2da_mem[c2da_fp + 16 + 0 * 4 + 2] = uint8(c2da_fresh54 >> 0x10)
        c2da_mem[c2da_fp + 16 + 0 * 4 + 3] = uint8(c2da_fresh54 >> 0x18)
        let c2da_fresh55 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 1 * 4]) | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
        let c2da_fresh56 : uint = float_bits_to_uint(c2da_fresh55)
        c2da_mem[c2da_fp + 16 + 1 * 4] = uint8(c2da_fresh56)
        c2da_mem[c2da_fp + 16 + 1 * 4 + 1] = uint8(c2da_fresh56 >> 0x8)
        c2da_mem[c2da_fp + 16 + 1 * 4 + 2] = uint8(c2da_fresh56 >> 0x10)
        c2da_mem[c2da_fp + 16 + 1 * 4 + 3] = uint8(c2da_fresh56 >> 0x18)
        let c2da_fresh57 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 2 * 4]) | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
        let c2da_fresh58 : uint = float_bits_to_uint(c2da_fresh57)
        c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh58)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh58 >> 0x8)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh58 >> 0x10)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh58 >> 0x18)
        VectorNormalize(c2da_fp + 16)
        dist = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pr_global_struct + 236 + 0 * 4]) | uint(c2da_mem[pr_global_struct + 236 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_global_struct + 236 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_global_struct + 236 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pr_global_struct + 236 + 1 * 4]) | uint(c2da_mem[pr_global_struct + 236 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_global_struct + 236 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_global_struct + 236 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pr_global_struct + 236 + 2 * 4]) | uint(c2da_mem[pr_global_struct + 236 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_global_struct + 236 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_global_struct + 236 + 2 * 4 + 3]) << 0x18)
        if (dist < bestdist) {
            i_6++
            check_0 += int(pr_edict_size)
            continue
        }
        tr = SV_Move(c2da_fp, 194432, 194432, c2da_fp + 32, 0, ent_4)
        if (tr.ent == check_0) {
            bestdist = dist
            bestent = check_0
        }
        i_6++
        check_0 += int(pr_edict_size)
    }
    if (bestent != 0) {
        let c2da_fresh59 : float = uint_bits_to_float(uint(c2da_mem[bestent + 148 + 0 * 4]) | uint(c2da_mem[bestent + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[bestent + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[bestent + 148 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[ent_4 + 148 + 0 * 4]) | uint(c2da_mem[ent_4 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_4 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_4 + 148 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh60 : uint = float_bits_to_uint(c2da_fresh59)
        c2da_mem[c2da_fp + 16 + 0 * 4] = uint8(c2da_fresh60)
        c2da_mem[c2da_fp + 16 + 0 * 4 + 1] = uint8(c2da_fresh60 >> 0x8)
        c2da_mem[c2da_fp + 16 + 0 * 4 + 2] = uint8(c2da_fresh60 >> 0x10)
        c2da_mem[c2da_fp + 16 + 0 * 4 + 3] = uint8(c2da_fresh60 >> 0x18)
        let c2da_fresh61 : float = uint_bits_to_float(uint(c2da_mem[bestent + 148 + 1 * 4]) | uint(c2da_mem[bestent + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[bestent + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[bestent + 148 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[ent_4 + 148 + 1 * 4]) | uint(c2da_mem[ent_4 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_4 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_4 + 148 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh62 : uint = float_bits_to_uint(c2da_fresh61)
        c2da_mem[c2da_fp + 16 + 1 * 4] = uint8(c2da_fresh62)
        c2da_mem[c2da_fp + 16 + 1 * 4 + 1] = uint8(c2da_fresh62 >> 0x8)
        c2da_mem[c2da_fp + 16 + 1 * 4 + 2] = uint8(c2da_fresh62 >> 0x10)
        c2da_mem[c2da_fp + 16 + 1 * 4 + 3] = uint8(c2da_fresh62 >> 0x18)
        let c2da_fresh63 : float = uint_bits_to_float(uint(c2da_mem[bestent + 148 + 2 * 4]) | uint(c2da_mem[bestent + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[bestent + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[bestent + 148 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[ent_4 + 148 + 2 * 4]) | uint(c2da_mem[ent_4 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_4 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_4 + 148 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh64 : uint = float_bits_to_uint(c2da_fresh63)
        c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh64)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh64 >> 0x8)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh64 >> 0x10)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh64 >> 0x18)
        dist = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pr_global_struct + 236 + 0 * 4]) | uint(c2da_mem[pr_global_struct + 236 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_global_struct + 236 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_global_struct + 236 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pr_global_struct + 236 + 1 * 4]) | uint(c2da_mem[pr_global_struct + 236 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_global_struct + 236 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_global_struct + 236 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pr_global_struct + 236 + 2 * 4]) | uint(c2da_mem[pr_global_struct + 236 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_global_struct + 236 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_global_struct + 236 + 2 * 4 + 3]) << 0x18)
        VectorScale(pr_global_struct + 236, dist, c2da_fp + 32)
        let c2da_fresh65 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh66 : uint = float_bits_to_uint(c2da_fresh65)
        c2da_mem[c2da_fp + 32 + 2 * 4] = uint8(c2da_fresh66)
        c2da_mem[c2da_fp + 32 + 2 * 4 + 1] = uint8(c2da_fresh66 >> 0x8)
        c2da_mem[c2da_fp + 32 + 2 * 4 + 2] = uint8(c2da_fresh66 >> 0x10)
        c2da_mem[c2da_fp + 32 + 2 * 4 + 3] = uint8(c2da_fresh66 >> 0x18)
        VectorNormalize(c2da_fp + 32)
        let c2da_fresh67 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 0 * 4]) | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh68 : uint = float_bits_to_uint(c2da_fresh67)
        c2da_mem[pr_globals + 1 * 4 + 0 * 4] = uint8(c2da_fresh68)
        c2da_mem[pr_globals + 1 * 4 + 0 * 4 + 1] = uint8(c2da_fresh68 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 0 * 4 + 2] = uint8(c2da_fresh68 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 0 * 4 + 3] = uint8(c2da_fresh68 >> 0x18)
        let c2da_fresh69 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 1 * 4]) | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh70 : uint = float_bits_to_uint(c2da_fresh69)
        c2da_mem[pr_globals + 1 * 4 + 1 * 4] = uint8(c2da_fresh70)
        c2da_mem[pr_globals + 1 * 4 + 1 * 4 + 1] = uint8(c2da_fresh70 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 1 * 4 + 2] = uint8(c2da_fresh70 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 1 * 4 + 3] = uint8(c2da_fresh70 >> 0x18)
        let c2da_fresh71 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 2 * 4]) | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh72 : uint = float_bits_to_uint(c2da_fresh71)
        c2da_mem[pr_globals + 1 * 4 + 2 * 4] = uint8(c2da_fresh72)
        c2da_mem[pr_globals + 1 * 4 + 2 * 4 + 1] = uint8(c2da_fresh72 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 2 * 4 + 2] = uint8(c2da_fresh72 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 2 * 4 + 3] = uint8(c2da_fresh72 >> 0x18)
    } else {
        let c2da_fresh73 : float = bestdir[0]
        let c2da_fresh74 : uint = float_bits_to_uint(c2da_fresh73)
        c2da_mem[pr_globals + 1 * 4 + 0 * 4] = uint8(c2da_fresh74)
        c2da_mem[pr_globals + 1 * 4 + 0 * 4 + 1] = uint8(c2da_fresh74 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 0 * 4 + 2] = uint8(c2da_fresh74 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 0 * 4 + 3] = uint8(c2da_fresh74 >> 0x18)
        let c2da_fresh75 : float = bestdir[1]
        let c2da_fresh76 : uint = float_bits_to_uint(c2da_fresh75)
        c2da_mem[pr_globals + 1 * 4 + 1 * 4] = uint8(c2da_fresh76)
        c2da_mem[pr_globals + 1 * 4 + 1 * 4 + 1] = uint8(c2da_fresh76 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 1 * 4 + 2] = uint8(c2da_fresh76 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 1 * 4 + 3] = uint8(c2da_fresh76 >> 0x18)
        let c2da_fresh77 : float = bestdir[2]
        let c2da_fresh78 : uint = float_bits_to_uint(c2da_fresh77)
        c2da_mem[pr_globals + 1 * 4 + 2 * 4] = uint8(c2da_fresh78)
        c2da_mem[pr_globals + 1 * 4 + 2 * 4 + 1] = uint8(c2da_fresh78 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 2 * 4 + 2] = uint8(c2da_fresh78 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 2 * 4 + 3] = uint8(c2da_fresh78 >> 0x18)
    }
    return
}
[sideeffects]
def private PF_droptofloor_c2da_frame(c2da_fp : int) {
    var ent_6 : int
    var trace : trace_t
    ent_6 = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_global_struct + 112]) | uint(c2da_mem[pr_global_struct + 113]) << 0x8 | uint(c2da_mem[pr_global_struct + 114]) << 0x10 | uint(c2da_mem[pr_global_struct + 115]) << 0x18)
    let c2da_fresh94 : float = uint_bits_to_float(uint(c2da_mem[ent_6 + 148 + 0 * 4]) | uint(c2da_mem[ent_6 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_6 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_6 + 148 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh95 : uint = float_bits_to_uint(c2da_fresh94)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh95)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh95 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh95 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh95 >> 0x18)
    let c2da_fresh96 : float = uint_bits_to_float(uint(c2da_mem[ent_6 + 148 + 1 * 4]) | uint(c2da_mem[ent_6 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_6 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_6 + 148 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh97 : uint = float_bits_to_uint(c2da_fresh96)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh97)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh97 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh97 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh97 >> 0x18)
    let c2da_fresh98 : float = uint_bits_to_float(uint(c2da_mem[ent_6 + 148 + 2 * 4]) | uint(c2da_mem[ent_6 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_6 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_6 + 148 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh99 : uint = float_bits_to_uint(c2da_fresh98)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh99)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh99 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh99 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh99 >> 0x18)
    let c2da_fresh100 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) - 256.0
    let c2da_fresh101 : uint = float_bits_to_uint(c2da_fresh100)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh101)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh101 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh101 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh101 >> 0x18)
    trace = SV_Move(ent_6 + 148, ent_6 + 240, ent_6 + 252, c2da_fp, 0, ent_6)
    if (trace.fraction == 1.0 || trace.allsolid != 0x0) {
        let c2da_fresh102 : float = 0.0
        let c2da_fresh103 : uint = float_bits_to_uint(c2da_fresh102)
        c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh103)
        c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh103 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh103 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh103 >> 0x18)
    } else {
        let c2da_fresh104 : float = trace.endpos[0]
        let c2da_fresh105 : uint = float_bits_to_uint(c2da_fresh104)
        c2da_mem[ent_6 + 148 + 0 * 4] = uint8(c2da_fresh105)
        c2da_mem[ent_6 + 148 + 0 * 4 + 1] = uint8(c2da_fresh105 >> 0x8)
        c2da_mem[ent_6 + 148 + 0 * 4 + 2] = uint8(c2da_fresh105 >> 0x10)
        c2da_mem[ent_6 + 148 + 0 * 4 + 3] = uint8(c2da_fresh105 >> 0x18)
        let c2da_fresh106 : float = trace.endpos[1]
        let c2da_fresh107 : uint = float_bits_to_uint(c2da_fresh106)
        c2da_mem[ent_6 + 148 + 1 * 4] = uint8(c2da_fresh107)
        c2da_mem[ent_6 + 148 + 1 * 4 + 1] = uint8(c2da_fresh107 >> 0x8)
        c2da_mem[ent_6 + 148 + 1 * 4 + 2] = uint8(c2da_fresh107 >> 0x10)
        c2da_mem[ent_6 + 148 + 1 * 4 + 3] = uint8(c2da_fresh107 >> 0x18)
        let c2da_fresh108 : float = trace.endpos[2]
        let c2da_fresh109 : uint = float_bits_to_uint(c2da_fresh108)
        c2da_mem[ent_6 + 148 + 2 * 4] = uint8(c2da_fresh109)
        c2da_mem[ent_6 + 148 + 2 * 4 + 1] = uint8(c2da_fresh109 >> 0x8)
        c2da_mem[ent_6 + 148 + 2 * 4 + 2] = uint8(c2da_fresh109 >> 0x10)
        c2da_mem[ent_6 + 148 + 2 * 4 + 3] = uint8(c2da_fresh109 >> 0x18)
        SV_LinkEdict(ent_6, 0u)
        let c2da_fresh110 : float = float(int(uint_bits_to_float(uint(c2da_mem[ent_6 + 412]) | uint(c2da_mem[ent_6 + 413]) << 0x8 | uint(c2da_mem[ent_6 + 414]) << 0x10 | uint(c2da_mem[ent_6 + 415]) << 0x18)) | 512)
        let c2da_fresh111 : uint = float_bits_to_uint(c2da_fresh110)
        c2da_mem[ent_6 + 412] = uint8(c2da_fresh111)
        c2da_mem[ent_6 + 413] = uint8(c2da_fresh111 >> 0x8)
        c2da_mem[ent_6 + 414] = uint8(c2da_fresh111 >> 0x10)
        c2da_mem[ent_6 + 415] = uint8(c2da_fresh111 >> 0x18)
        let c2da_fresh112 : int = trace.ent - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh113 : uint = uint(c2da_fresh112)
        c2da_mem[ent_6 + 296] = uint8(c2da_fresh113)
        c2da_mem[ent_6 + 297] = uint8(c2da_fresh113 >> 0x8)
        c2da_mem[ent_6 + 298] = uint8(c2da_fresh113 >> 0x10)
        c2da_mem[ent_6 + 299] = uint8(c2da_fresh113 >> 0x18)
        let c2da_fresh114 : float = 1.0
        let c2da_fresh115 : uint = float_bits_to_uint(c2da_fresh114)
        c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh115)
        c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh115 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh115 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh115 >> 0x18)
    }
    return
}
[sideeffects]
def private PF_walkmove_c2da_frame(c2da_fp : int) {
    var ent_7 : int
    var yaw_0 : float
    var dist_0 : float
    var oldf : int
    var oldself : int
    ent_7 = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_global_struct + 112]) | uint(c2da_mem[pr_global_struct + 113]) << 0x8 | uint(c2da_mem[pr_global_struct + 114]) << 0x10 | uint(c2da_mem[pr_global_struct + 115]) << 0x18)
    yaw_0 = uint_bits_to_float(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    dist_0 = uint_bits_to_float(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18)
    if ((int(uint_bits_to_float(uint(c2da_mem[ent_7 + 412]) | uint(c2da_mem[ent_7 + 413]) << 0x8 | uint(c2da_mem[ent_7 + 414]) << 0x10 | uint(c2da_mem[ent_7 + 415]) << 0x18)) & (512 | 1 | 2)) == 0) {
        let c2da_fresh116 : float = 0.0
        let c2da_fresh117 : uint = float_bits_to_uint(c2da_fresh116)
        c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh117)
        c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh117 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh117 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh117 >> 0x18)
        return
    }
    yaw_0 = float(double(yaw_0) * 3.141592653589793lf * 2.0lf / 360.0lf)
    let c2da_fresh118 : float = float(cos(double(yaw_0)) * double(dist_0))
    let c2da_fresh119 : uint = float_bits_to_uint(c2da_fresh118)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh119)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh119 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh119 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh119 >> 0x18)
    let c2da_fresh120 : float = float(sin(double(yaw_0)) * double(dist_0))
    let c2da_fresh121 : uint = float_bits_to_uint(c2da_fresh120)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh121)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh121 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh121 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh121 >> 0x18)
    let c2da_fresh122 : float = 0.0
    let c2da_fresh123 : uint = float_bits_to_uint(c2da_fresh122)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh123)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh123 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh123 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh123 >> 0x18)
    oldf = pr_xfunction
    oldself = int(uint(c2da_mem[pr_global_struct + 112]) | uint(c2da_mem[pr_global_struct + 113]) << 0x8 | uint(c2da_mem[pr_global_struct + 114]) << 0x10 | uint(c2da_mem[pr_global_struct + 115]) << 0x18)
    let c2da_fresh124 : float = float(uint(SV_movestep(ent_7, c2da_fp, 1u)))
    let c2da_fresh125 : uint = float_bits_to_uint(c2da_fresh124)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh125)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh125 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh125 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh125 >> 0x18)
    pr_xfunction = oldf
    let c2da_fresh126 : uint = uint(oldself)
    c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh126)
    c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh126 >> 0x8)
    c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh126 >> 0x10)
    c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh126 >> 0x18)
    return
}
[sideeffects]
def private PF_findradius_c2da_frame(c2da_fp : int) {
    var ent_8 : int
    var chain : int
    var rad : float
    var org_0 : int
    var i_7 : int
    chain = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    org_0 = pr_globals + 4 * 4
    rad = uint_bits_to_float(uint(c2da_mem[pr_globals + 7 * 4]) | uint(c2da_mem[pr_globals + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 7 * 4 + 3]) << 0x18)
    ent_8 = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(pr_edict_size)
    i_7 = 1
    while (i_7 < int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        if ((uint(c2da_mem[ent_8]) | uint(c2da_mem[ent_8 + 1]) << 0x8 | uint(c2da_mem[ent_8 + 2]) << 0x10 | uint(c2da_mem[ent_8 + 3]) << 0x18) != 0u) {
            i_7++
            ent_8 += int(pr_edict_size)
            continue
        }
        if (uint_bits_to_float(uint(c2da_mem[ent_8 + 144]) | uint(c2da_mem[ent_8 + 145]) << 0x8 | uint(c2da_mem[ent_8 + 146]) << 0x10 | uint(c2da_mem[ent_8 + 147]) << 0x18) == 0.0) {
            i_7++
            ent_8 += int(pr_edict_size)
            continue
        }
        for (j_1 in range(0, 3)) {
            let c2da_fresh131 : float = float(double(uint_bits_to_float(uint(c2da_mem[org_0 + j_1 * 4]) | uint(c2da_mem[org_0 + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[org_0 + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[org_0 + j_1 * 4 + 3]) << 0x18)) - (double(uint_bits_to_float(uint(c2da_mem[ent_8 + 148 + j_1 * 4]) | uint(c2da_mem[ent_8 + 148 + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_8 + 148 + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_8 + 148 + j_1 * 4 + 3]) << 0x18)) + double(uint_bits_to_float(uint(c2da_mem[ent_8 + 240 + j_1 * 4]) | uint(c2da_mem[ent_8 + 240 + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_8 + 240 + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_8 + 240 + j_1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_8 + 252 + j_1 * 4]) | uint(c2da_mem[ent_8 + 252 + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_8 + 252 + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_8 + 252 + j_1 * 4 + 3]) << 0x18)) * 0.5lf))
            let c2da_fresh132 : uint = float_bits_to_uint(c2da_fresh131)
            c2da_mem[c2da_fp + j_1 * 4] = uint8(c2da_fresh132)
            c2da_mem[c2da_fp + j_1 * 4 + 1] = uint8(c2da_fresh132 >> 0x8)
            c2da_mem[c2da_fp + j_1 * 4 + 2] = uint8(c2da_fresh132 >> 0x10)
            c2da_mem[c2da_fp + j_1 * 4 + 3] = uint8(c2da_fresh132 >> 0x18)
        }
        if (Length(c2da_fp) > rad) {
            i_7++
            ent_8 += int(pr_edict_size)
            continue
        }
        let c2da_fresh133 : int = chain - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh134 : uint = uint(c2da_fresh133)
        c2da_mem[ent_8 + 348] = uint8(c2da_fresh134)
        c2da_mem[ent_8 + 349] = uint8(c2da_fresh134 >> 0x8)
        c2da_mem[ent_8 + 350] = uint8(c2da_fresh134 >> 0x10)
        c2da_mem[ent_8 + 351] = uint8(c2da_fresh134 >> 0x18)
        chain = ent_8
        i_7++
        ent_8 += int(pr_edict_size)
    }
    let c2da_fresh135 : int = chain - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    let c2da_fresh136 : uint = uint(c2da_fresh135)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh136)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh136 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh136 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh136 >> 0x18)
    return
}
[sideeffects]
def private PF_checkclient_c2da_frame(c2da_fp : int) {
    var ent_9 : int
    var self : int
    var leaf : int
    var l : int
    if (uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20) - uint64_bits_to_double(uint64(uint(c2da_mem[225888]) | uint(c2da_mem[225889]) << 0x8 | uint(c2da_mem[225890]) << 0x10 | uint(c2da_mem[225891]) << 0x18) | uint64(uint(c2da_mem[225892]) | uint(c2da_mem[225893]) << 0x8 | uint(c2da_mem[225894]) << 0x10 | uint(c2da_mem[225895]) << 0x18) << 0x20) >= 0.1lf) {
        let c2da_fresh141 : int = PF_newcheckclient(int(uint(c2da_mem[225880]) | uint(c2da_mem[225881]) << 0x8 | uint(c2da_mem[225882]) << 0x10 | uint(c2da_mem[225883]) << 0x18))
        let c2da_fresh142 : uint = uint(c2da_fresh141)
        c2da_mem[225880] = uint8(c2da_fresh142)
        c2da_mem[225881] = uint8(c2da_fresh142 >> 0x8)
        c2da_mem[225882] = uint8(c2da_fresh142 >> 0x10)
        c2da_mem[225883] = uint8(c2da_fresh142 >> 0x18)
        let c2da_fresh143 : double = uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20)
        let c2da_fresh144 : uint64 = double_bits_to_uint64(c2da_fresh143)
        c2da_mem[225888] = uint8(c2da_fresh144)
        c2da_mem[225889] = uint8(c2da_fresh144 >> 0x8)
        c2da_mem[225890] = uint8(c2da_fresh144 >> 0x10)
        c2da_mem[225891] = uint8(c2da_fresh144 >> 0x18)
        c2da_mem[225892] = uint8(c2da_fresh144 >> 0x20)
        c2da_mem[225893] = uint8(c2da_fresh144 >> 0x28)
        c2da_mem[225894] = uint8(c2da_fresh144 >> 0x30)
        c2da_mem[225895] = uint8(c2da_fresh144 >> 0x38)
    }
    ent_9 = EDICT_NUM(int(uint(c2da_mem[225880]) | uint(c2da_mem[225881]) << 0x8 | uint(c2da_mem[225882]) << 0x10 | uint(c2da_mem[225883]) << 0x18))
    if ((uint(c2da_mem[ent_9]) | uint(c2da_mem[ent_9 + 1]) << 0x8 | uint(c2da_mem[ent_9 + 2]) << 0x10 | uint(c2da_mem[ent_9 + 3]) << 0x18) != 0x0 || uint_bits_to_float(uint(c2da_mem[ent_9 + 300]) | uint(c2da_mem[ent_9 + 301]) << 0x8 | uint(c2da_mem[ent_9 + 302]) << 0x10 | uint(c2da_mem[ent_9 + 303]) << 0x18) <= 0.0) {
        let c2da_fresh145 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh146 : uint = uint(c2da_fresh145)
        c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh146)
        c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh146 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh146 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh146 >> 0x18)
        return
    }
    self = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_global_struct + 112]) | uint(c2da_mem[pr_global_struct + 113]) << 0x8 | uint(c2da_mem[pr_global_struct + 114]) << 0x10 | uint(c2da_mem[pr_global_struct + 115]) << 0x18)
    let c2da_fresh147 : float = uint_bits_to_float(uint(c2da_mem[self + 148 + 0 * 4]) | uint(c2da_mem[self + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[self + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[self + 148 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[self + 356 + 0 * 4]) | uint(c2da_mem[self + 356 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[self + 356 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[self + 356 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh148 : uint = float_bits_to_uint(c2da_fresh147)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh148)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh148 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh148 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh148 >> 0x18)
    let c2da_fresh149 : float = uint_bits_to_float(uint(c2da_mem[self + 148 + 1 * 4]) | uint(c2da_mem[self + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[self + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[self + 148 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[self + 356 + 1 * 4]) | uint(c2da_mem[self + 356 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[self + 356 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[self + 356 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh150 : uint = float_bits_to_uint(c2da_fresh149)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh150)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh150 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh150 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh150 >> 0x18)
    let c2da_fresh151 : float = uint_bits_to_float(uint(c2da_mem[self + 148 + 2 * 4]) | uint(c2da_mem[self + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[self + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[self + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[self + 356 + 2 * 4]) | uint(c2da_mem[self + 356 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[self + 356 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[self + 356 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh152 : uint = float_bits_to_uint(c2da_fresh151)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh152)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh152 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh152 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh152 >> 0x18)
    leaf = Mod_PointInLeaf(c2da_fp, int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18))
    let c2da_fresh153 : int = int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) + 160
    l = int(int64((leaf - int(uint(c2da_mem[c2da_fresh153]) | uint(c2da_mem[c2da_fresh153 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh153 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh153 + 3]) << 0x18)) / 72) - 1l)
    var c2da_fresh155 : int = 1
    if (!(l < 0)) {
        let c2da_fresh154 : int = 387824 + (l >> 3)
        if (!((int(c2da_mem[c2da_fresh154]) & 1 << (l & 7)) == 0)) {
            c2da_fresh155 = 0
        }
    }
    if (c2da_fresh155 != 0) {
        c_notvis++
        let c2da_fresh156 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh157 : uint = uint(c2da_fresh156)
        c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh157)
        c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh157 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh157 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh157 >> 0x18)
        return
    }
    c_invis++
    let c2da_fresh158 : int = ent_9 - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    let c2da_fresh159 : uint = uint(c2da_fresh158)
    c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh159)
    c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh159 >> 0x8)
    c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh159 >> 0x10)
    c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh159 >> 0x18)
    return
}
[sideeffects]
def private PF_newcheckclient_c2da_frame(var check_1 : int; c2da_fp : int) : int {
    var i_8 : int
    var pvs : int
    var ent_10 : int
    var leaf_0 : int
    if (check_1 < 1) {
        check_1 = 1
    }
    if (check_1 > svs.maxclients) {
        check_1 = svs.maxclients
    }
    if (check_1 == svs.maxclients) {
        i_8 = 1
    } else {
        i_8 = check_1 + 1
    }
    while (true) {
        if (i_8 == svs.maxclients + 1) {
            i_8 = 1
        }
        ent_10 = EDICT_NUM(i_8)
        if (i_8 == check_1) {
            break
        }
        if ((uint(c2da_mem[ent_10]) | uint(c2da_mem[ent_10 + 1]) << 0x8 | uint(c2da_mem[ent_10 + 2]) << 0x10 | uint(c2da_mem[ent_10 + 3]) << 0x18) != 0u) {
            i_8++
            continue
        }
        if (uint_bits_to_float(uint(c2da_mem[ent_10 + 300]) | uint(c2da_mem[ent_10 + 301]) << 0x8 | uint(c2da_mem[ent_10 + 302]) << 0x10 | uint(c2da_mem[ent_10 + 303]) << 0x18) <= 0.0) {
            i_8++
            continue
        }
        if ((int(uint_bits_to_float(uint(c2da_mem[ent_10 + 412]) | uint(c2da_mem[ent_10 + 413]) << 0x8 | uint(c2da_mem[ent_10 + 414]) << 0x10 | uint(c2da_mem[ent_10 + 415]) << 0x18)) & 128) != 0) {
            i_8++
            continue
        }
        break
    }
    let c2da_fresh160 : float = uint_bits_to_float(uint(c2da_mem[ent_10 + 148 + 0 * 4]) | uint(c2da_mem[ent_10 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_10 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_10 + 148 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_10 + 356 + 0 * 4]) | uint(c2da_mem[ent_10 + 356 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_10 + 356 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_10 + 356 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh161 : uint = float_bits_to_uint(c2da_fresh160)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh161)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh161 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh161 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh161 >> 0x18)
    let c2da_fresh162 : float = uint_bits_to_float(uint(c2da_mem[ent_10 + 148 + 1 * 4]) | uint(c2da_mem[ent_10 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_10 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_10 + 148 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_10 + 356 + 1 * 4]) | uint(c2da_mem[ent_10 + 356 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_10 + 356 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_10 + 356 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh163 : uint = float_bits_to_uint(c2da_fresh162)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh163)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh163 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh163 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh163 >> 0x18)
    let c2da_fresh164 : float = uint_bits_to_float(uint(c2da_mem[ent_10 + 148 + 2 * 4]) | uint(c2da_mem[ent_10 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_10 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_10 + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_10 + 356 + 2 * 4]) | uint(c2da_mem[ent_10 + 356 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_10 + 356 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_10 + 356 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh165 : uint = float_bits_to_uint(c2da_fresh164)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh165)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh165 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh165 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh165 >> 0x18)
    leaf_0 = Mod_PointInLeaf(c2da_fp, int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18))
    pvs = Mod_LeafPVS(leaf_0, int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18))
    let c2da_fresh166 : int = int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) + 152
    c2da_lin_memcpy(387824, pvs, uint64(int(uint(c2da_mem[c2da_fresh166]) | uint(c2da_mem[c2da_fresh166 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh166 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh166 + 3]) << 0x18) + 7 >> 3))
    return i_8
}

// This unit's static data, at heap offset 728112.
let private c2da_lin_static_pr_cmds_seg = fixed_array<int>(728368, 577)
let private c2da_lin_static_pr_cmds = fixed_array<uint64>(0x30006d69615f7673ul, 0x69746e450033392eul, 0x6f6e207369207974ul, 0x65696c6320612074ul, 0x72505f465000746eul, 0x2a5f656863616365ul, 0x636163657250203aul, 0x6f206e6163206568ul, 0x6420656220796c6eul, 0x73206e6920656e6ful, 0x6e7566206e776170ul, 0x5000736e6f697463ul, 0x6361636572705f46ul, 0x646e756f735f6568ul, 0x6c667265766f203aul, 0x732064614200776ful, 0x465000676e697274ul, 0x686361636572705ful, 0x3a6c65646f6d5f65ul, 0x6f6c667265766f20ul, 0x657270206f6e0077ul, 0x25203a6568636163ul, 0x6465697274000a73ul, 0x69727073206f7420ul, 0x2061206f7420746eul, 0x65696c632d6e6f6eul, 0x6d696e75000a746eul, 0x65746e656d656c70ul, 0x6974696c75622064ul, 0x65676e616863006eul, 0x7325206c6576656cul, 0x446574697257000aul, 0x746f6e203a747365ul, 0x6e65696c63206120ul, 0x4465746972570074ul, 0x646162203a747365ul, 0x616e697473656420ul, 0x352527006e6f6974ul, 0x312e35252066312eul, 0x2766312e35252066ul, 0x312e352500642500ul, 0x7261500073250066ul, 0x20746f6e2030206dul, 0x746e65696c632061ul, 0x646e69465f465000ul, 0x657320646162203aul, 0x7274732068637261ul, 0x3d3d3d3d00676e69ul, 0x5443454a424f3d3dul, 0x6920524f52524520ul, 0x73250a3a7325206eul, 0x6172676f7250000aul, 0x726f727265206dul, 0x45533d3d3d3d3d3dul, 0x5252452052455652ul, 0x7325206e6920524ful, 0x5653000a73250a3aul, 0x6f5374726174535ful, 0x6c6f76203a646e75ul, 0x6925203d20656d75ul, 0x726174535f565300ul, 0x203a646e756f5374ul, 0x7461756e65747461ul, 0x6625203d206e6f69ul, 0x726174535f565300ul, 0x203a646e756f5374ul, 0x206c656e6e616863ul, 0x657262006925203dul, 0x6574617473206b61ul, 0x6162000a746e656dul, 0x2073647261776b63ul, 0x78616d2f736e696dul, 0x73ul)

[init]
def private c2da_lin_init_static_pr_cmds() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_pr_cmds_seg[s * 2]
        for (k in range(c2da_lin_static_pr_cmds_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_pr_cmds[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_pr_cmds_0 = fixed_array<uint8>(0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x88, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x89, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x91, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x92, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x93, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x94, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x95, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x96, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x97, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x98, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x99, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xab, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xac, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xad, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xae, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xba, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x99, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_pr_cmds_1 = fixed_array<uint8>(0x30, 0x1d, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x37, 0x1d, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_pr_cmds() {
    c2da_lin_setup()
    for (i in range(632)) {
        c2da_mem[387056 + i] = c2da_lin_extern_pr_cmds_0[i]
    }
    for (i in range(40)) {
        c2da_mem[462928 + i] = c2da_lin_extern_pr_cmds_1[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_pr_cmds() {
    if (length(c2da_fn_table0) < 198) {
        resize(c2da_fn_table0, 198)
    }
    c2da_fn_table0[197] = @@PF_setspawnparms
    c2da_fn_table0[191] = @@PF_precache_file
    c2da_fn_table0[153] = @@PF_precache_sound
    c2da_fn_table0[154] = @@PF_precache_model
    c2da_fn_table0[196] = @@PF_ambientsound
    c2da_fn_table0[195] = @@PF_centerprint
    c2da_fn_table0[194] = @@PF_cvar_set
    c2da_fn_table0[135] = @@PF_Fixme
    c2da_fn_table0[193] = @@PF_changelevel
    c2da_fn_table0[192] = @@PF_makestatic
    c2da_fn_table0[189] = @@PF_WriteEntity
    c2da_fn_table0[188] = @@PF_WriteString
    c2da_fn_table0[187] = @@PF_WriteAngle
    c2da_fn_table0[186] = @@PF_WriteCoord
    c2da_fn_table0[185] = @@PF_WriteLong
    c2da_fn_table0[184] = @@PF_WriteShort
    c2da_fn_table0[183] = @@PF_WriteChar
    c2da_fn_table0[182] = @@PF_WriteByte
    c2da_fn_table0[181] = @@PF_vectoangles
    c2da_fn_table0[180] = @@PF_changeyaw
    c2da_fn_table0[179] = @@PF_particle
    c2da_fn_table0[178] = @@PF_nextent
    c2da_fn_table0[177] = @@PF_localcmd
    c2da_fn_table0[176] = @@PF_cvar
    c2da_fn_table0[175] = @@PF_aim
    c2da_fn_table0[174] = @@PF_fabs
    c2da_fn_table0[173] = @@PF_pointcontents
    c2da_fn_table0[172] = @@PF_checkbottom
    c2da_fn_table0[171] = @@PF_ceil
    c2da_fn_table0[170] = @@PF_floor
    c2da_fn_table0[169] = @@PF_rint
    c2da_fn_table0[168] = @@PF_lightstyle
    c2da_fn_table0[167] = @@PF_droptofloor
    c2da_fn_table0[166] = @@PF_walkmove
    c2da_fn_table0[165] = @@PF_eprint
    c2da_fn_table0[164] = @@PF_traceoff
    c2da_fn_table0[163] = @@PF_traceon
    c2da_fn_table0[162] = @@PF_coredump
    c2da_fn_table0[161] = @@PF_vtos
    c2da_fn_table0[160] = @@PF_ftos
    c2da_fn_table0[159] = @@PF_dprint
    c2da_fn_table0[158] = @@PF_sprint
    c2da_fn_table0[157] = @@PF_bprint
    c2da_fn_table0[156] = @@PF_findradius
    c2da_fn_table0[155] = @@PF_stuffcmd
    c2da_fn_table0[152] = @@PF_Find
    c2da_fn_table0[151] = @@PF_checkclient
    c2da_fn_table0[150] = @@PF_traceline
    c2da_fn_table0[149] = @@PF_Remove
    c2da_fn_table0[148] = @@PF_Spawn
    c2da_fn_table0[147] = @@PF_vectoyaw
    c2da_fn_table0[146] = @@PF_vlen
    c2da_fn_table0[145] = @@PF_objerror
    c2da_fn_table0[144] = @@PF_error
    c2da_fn_table0[143] = @@PF_normalize
    c2da_fn_table0[142] = @@PF_sound
    c2da_fn_table0[141] = @@PF_random
    c2da_fn_table0[140] = @@PF_break
    c2da_fn_table0[139] = @@PF_setsize
    c2da_fn_table0[138] = @@PF_setmodel
    c2da_fn_table0[137] = @@PF_setorigin
    c2da_fn_table0[136] = @@PF_makevectors
}

[init]
def private c2da_lin_relink_init_pr_cmds() {
    c2da_relink_pr_cmds()
}
