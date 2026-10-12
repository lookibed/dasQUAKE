[export, sideeffects]
def Mod_Init() {
    c2da_lin_memset(248144, 255, 1024ul)
    return
}
[export, sideeffects]
def Mod_ClearAll() {
    var i : int
    var mod : int
    i = 0
    mod = 249168
    while (i < mod_numknown) {
        let c2da_fresh0 : uint = 2u
        let c2da_fresh1 : uint = c2da_fresh0
        c2da_mem[mod + 64] = uint8(c2da_fresh1)
        c2da_mem[mod + 65] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[mod + 66] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[mod + 67] = uint8(c2da_fresh1 >> 0x18)
        if ((uint(c2da_mem[mod + 68]) | uint(c2da_mem[mod + 69]) << 0x8 | uint(c2da_mem[mod + 70]) << 0x10 | uint(c2da_mem[mod + 71]) << 0x18) == 1u) {
            let c2da_fresh2 : uint = 0u
            c2da_mem[mod + 528] = uint8(c2da_fresh2)
            c2da_mem[mod + 529] = uint8(c2da_fresh2 >> 0x8)
            c2da_mem[mod + 530] = uint8(c2da_fresh2 >> 0x10)
            c2da_mem[mod + 531] = uint8(c2da_fresh2 >> 0x18)
            c2da_mem[mod + 532] = 0u8
            c2da_mem[mod + 533] = 0u8
            c2da_mem[mod + 534] = 0u8
            c2da_mem[mod + 535] = 0u8
        }
        i++
        mod += 536
    }
    return
}
var mod_numknown : int = default<int>

[export, sideeffects]
def Mod_ForName(var name : int; var crash : uint) : int {
    var mod_0 : int = Mod_FindName(name)
    return Mod_LoadModel(mod_0, crash)
}
[export, sideeffects]
def Mod_LoadModel(var mod_1 : int; var crash_0 : uint) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = Mod_LoadModel_c2da_frame(mod_1, crash_0, c2da_lin_enter(1024))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def Mod_LoadBrushModel(var mod_2 : int; var buffer : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    Mod_LoadBrushModel_c2da_frame(mod_2, buffer, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
var loadmodel : int = default<int>

[export, sideeffects]
def Mod_FindName(var name_0 : int) : int {
    var i_1 : int
    var mod_3 : int
    var avail : int = 0
    if (int8(c2da_mem[name_0 + 0]) == 0) {
        Sys_Error(726115, [])
    }
    i_1 = 0
    mod_3 = 249168
    while (i_1 < mod_numknown) {
        if (c2da_lin_strcmp(mod_3, name_0) == 0) {
            break
        }
        if ((uint(c2da_mem[mod_3 + 64]) | uint(c2da_mem[mod_3 + 65]) << 0x8 | uint(c2da_mem[mod_3 + 66]) << 0x10 | uint(c2da_mem[mod_3 + 67]) << 0x18) == 2u) {
            if (avail == 0 || (uint(c2da_mem[mod_3 + 68]) | uint(c2da_mem[mod_3 + 69]) << 0x8 | uint(c2da_mem[mod_3 + 70]) << 0x10 | uint(c2da_mem[mod_3 + 71]) << 0x18) != 2u) {
                avail = mod_3
            }
        }
        i_1++
        mod_3 += 536
    }
    if (i_1 == mod_numknown) {
        if (mod_numknown == 256) {
            if (avail != 0) {
                mod_3 = avail
                if ((uint(c2da_mem[mod_3 + 68]) | uint(c2da_mem[mod_3 + 69]) << 0x8 | uint(c2da_mem[mod_3 + 70]) << 0x10 | uint(c2da_mem[mod_3 + 71]) << 0x18) == 2u) {
                    if (Cache_Check(mod_3 + 528) != 0) {
                        Cache_Free(mod_3 + 528)
                    }
                }
            } else {
                Sys_Error(726138, [])
            }
        } else {
            mod_numknown++
        }
        c2da_lin_strcpy(mod_3, name_0)
        let c2da_fresh42 : uint = 1u
        let c2da_fresh43 : uint = c2da_fresh42
        c2da_mem[mod_3 + 64] = uint8(c2da_fresh43)
        c2da_mem[mod_3 + 65] = uint8(c2da_fresh43 >> 0x8)
        c2da_mem[mod_3 + 66] = uint8(c2da_fresh43 >> 0x10)
        c2da_mem[mod_3 + 67] = uint8(c2da_fresh43 >> 0x18)
    }
    return mod_3
}
[export, sideeffects]
def RadiusFromBounds(var mins : int; var maxs : int) : float {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : float = RadiusFromBounds_c2da_frame(mins, maxs, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def Mod_MakeHull0() {
    var in_0 : int
    var child : int
    var out : int
    var i_3 : int
    var count : int
    var hull : int = loadmodel + 296 + 0 * 48
    in_0 = int(uint(c2da_mem[loadmodel + 208]) | uint(c2da_mem[loadmodel + 209]) << 0x8 | uint(c2da_mem[loadmodel + 210]) << 0x10 | uint(c2da_mem[loadmodel + 211]) << 0x18)
    count = int(uint(c2da_mem[loadmodel + 200]) | uint(c2da_mem[loadmodel + 201]) << 0x8 | uint(c2da_mem[loadmodel + 202]) << 0x10 | uint(c2da_mem[loadmodel + 203]) << 0x18)
    out = Hunk_AllocName(int(uint64(count) * 8ul), 386384)
    let c2da_fresh46 : uint = uint(out)
    c2da_mem[hull] = uint8(c2da_fresh46)
    c2da_mem[hull + 1] = uint8(c2da_fresh46 >> 0x8)
    c2da_mem[hull + 2] = uint8(c2da_fresh46 >> 0x10)
    c2da_mem[hull + 3] = uint8(c2da_fresh46 >> 0x18)
    c2da_mem[hull + 4] = 0u8
    c2da_mem[hull + 5] = 0u8
    c2da_mem[hull + 6] = 0u8
    c2da_mem[hull + 7] = 0u8
    let c2da_fresh47 : int = 0
    let c2da_fresh48 : uint = uint(c2da_fresh47)
    c2da_mem[hull + 16] = uint8(c2da_fresh48)
    c2da_mem[hull + 17] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[hull + 18] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[hull + 19] = uint8(c2da_fresh48 >> 0x18)
    let c2da_fresh49 : int = count - 1
    let c2da_fresh50 : uint = uint(c2da_fresh49)
    c2da_mem[hull + 20] = uint8(c2da_fresh50)
    c2da_mem[hull + 21] = uint8(c2da_fresh50 >> 0x8)
    c2da_mem[hull + 22] = uint8(c2da_fresh50 >> 0x10)
    c2da_mem[hull + 23] = uint8(c2da_fresh50 >> 0x18)
    let c2da_fresh51 : int = int(uint(c2da_mem[loadmodel + 144]) | uint(c2da_mem[loadmodel + 145]) << 0x8 | uint(c2da_mem[loadmodel + 146]) << 0x10 | uint(c2da_mem[loadmodel + 147]) << 0x18)
    let c2da_fresh52 : uint = uint(c2da_fresh51)
    c2da_mem[hull + 8] = uint8(c2da_fresh52)
    c2da_mem[hull + 9] = uint8(c2da_fresh52 >> 0x8)
    c2da_mem[hull + 10] = uint8(c2da_fresh52 >> 0x10)
    c2da_mem[hull + 11] = uint8(c2da_fresh52 >> 0x18)
    c2da_mem[hull + 12] = 0u8
    c2da_mem[hull + 13] = 0u8
    c2da_mem[hull + 14] = 0u8
    c2da_mem[hull + 15] = 0u8
    i_3 = 0
    while (i_3 < count) {
        let c2da_fresh53 : int = (int(uint(c2da_mem[in_0 + 32]) | uint(c2da_mem[in_0 + 33]) << 0x8 | uint(c2da_mem[in_0 + 34]) << 0x10 | uint(c2da_mem[in_0 + 35]) << 0x18) - int(uint(c2da_mem[loadmodel + 144]) | uint(c2da_mem[loadmodel + 145]) << 0x8 | uint(c2da_mem[loadmodel + 146]) << 0x10 | uint(c2da_mem[loadmodel + 147]) << 0x18)) / 20
        let c2da_fresh54 : uint = uint(c2da_fresh53)
        c2da_mem[out] = uint8(c2da_fresh54)
        c2da_mem[out + 1] = uint8(c2da_fresh54 >> 0x8)
        c2da_mem[out + 2] = uint8(c2da_fresh54 >> 0x10)
        c2da_mem[out + 3] = uint8(c2da_fresh54 >> 0x18)
        for (j_0 in range(0, 2)) {
            child = int(uint(c2da_mem[in_0 + 40 + j_0 * 8]) | uint(c2da_mem[in_0 + 40 + j_0 * 8 + 1]) << 0x8 | uint(c2da_mem[in_0 + 40 + j_0 * 8 + 2]) << 0x10 | uint(c2da_mem[in_0 + 40 + j_0 * 8 + 3]) << 0x18)
            let c2da_fresh59 : int = int(uint(c2da_mem[child]) | uint(c2da_mem[child + 1]) << 0x8 | uint(c2da_mem[child + 2]) << 0x10 | uint(c2da_mem[child + 3]) << 0x18)
            if (c2da_fresh59 < 0) {
                let c2da_fresh55 : int16 = int16(c2da_fresh59)
                let c2da_fresh56 : uint = uint(c2da_fresh55)
                c2da_mem[out + 4 + j_0 * 2] = uint8(c2da_fresh56)
                c2da_mem[out + 4 + j_0 * 2 + 1] = uint8(c2da_fresh56 >> 0x8)
            } else {
                let c2da_fresh57 : int16 = int16((child - int(uint(c2da_mem[loadmodel + 208]) | uint(c2da_mem[loadmodel + 209]) << 0x8 | uint(c2da_mem[loadmodel + 210]) << 0x10 | uint(c2da_mem[loadmodel + 211]) << 0x18)) / 64)
                let c2da_fresh58 : uint = uint(c2da_fresh57)
                c2da_mem[out + 4 + j_0 * 2] = uint8(c2da_fresh58)
                c2da_mem[out + 4 + j_0 * 2 + 1] = uint8(c2da_fresh58 >> 0x8)
            }
        }
        i_3++
        out += 8
        in_0 += 64
    }
    return
}
[export, sideeffects]
def Mod_LoadSubmodels(var l : int) {
    var in_1 : int
    var out_0 : int
    var i_4 : int
    var j_1 : int
    var count_0 : int
    in_1 = mod_base + int(uint(c2da_mem[l]) | uint(c2da_mem[l + 1]) << 0x8 | uint(c2da_mem[l + 2]) << 0x10 | uint(c2da_mem[l + 3]) << 0x18)
    if (uint64(int(uint(c2da_mem[l + 4]) | uint(c2da_mem[l + 5]) << 0x8 | uint(c2da_mem[l + 6]) << 0x10 | uint(c2da_mem[l + 7]) << 0x18)) % 64ul != 0x0) {
        Sys_Error(726168, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(loadmodel))])
    }
    count_0 = int(uint64(int(uint(c2da_mem[l + 4]) | uint(c2da_mem[l + 5]) << 0x8 | uint(c2da_mem[l + 6]) << 0x10 | uint(c2da_mem[l + 7]) << 0x18)) / 64ul)
    out_0 = Hunk_AllocName(int(uint64(count_0) * 64ul), 386384)
    let c2da_fresh60 : uint = uint(out_0)
    c2da_mem[loadmodel + 128] = uint8(c2da_fresh60)
    c2da_mem[loadmodel + 129] = uint8(c2da_fresh60 >> 0x8)
    c2da_mem[loadmodel + 130] = uint8(c2da_fresh60 >> 0x10)
    c2da_mem[loadmodel + 131] = uint8(c2da_fresh60 >> 0x18)
    c2da_mem[loadmodel + 132] = 0u8
    c2da_mem[loadmodel + 133] = 0u8
    c2da_mem[loadmodel + 134] = 0u8
    c2da_mem[loadmodel + 135] = 0u8
    let c2da_fresh61 : uint = uint(count_0)
    c2da_mem[loadmodel + 120] = uint8(c2da_fresh61)
    c2da_mem[loadmodel + 121] = uint8(c2da_fresh61 >> 0x8)
    c2da_mem[loadmodel + 122] = uint8(c2da_fresh61 >> 0x10)
    c2da_mem[loadmodel + 123] = uint8(c2da_fresh61 >> 0x18)
    i_4 = 0
    while (i_4 < count_0) {
        j_1 = 0
        while (j_1 < 3) {
            let c2da_fresh62 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[in_1 + j_1 * 4]) | uint(c2da_mem[in_1 + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[in_1 + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[in_1 + j_1 * 4 + 3]) << 0x18)) - 1.0
            let c2da_fresh63 : uint = float_bits_to_uint(c2da_fresh62)
            c2da_mem[out_0 + j_1 * 4] = uint8(c2da_fresh63)
            c2da_mem[out_0 + j_1 * 4 + 1] = uint8(c2da_fresh63 >> 0x8)
            c2da_mem[out_0 + j_1 * 4 + 2] = uint8(c2da_fresh63 >> 0x10)
            c2da_mem[out_0 + j_1 * 4 + 3] = uint8(c2da_fresh63 >> 0x18)
            let c2da_fresh64 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[in_1 + 12 + j_1 * 4]) | uint(c2da_mem[in_1 + 12 + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[in_1 + 12 + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[in_1 + 12 + j_1 * 4 + 3]) << 0x18)) + 1.0
            let c2da_fresh65 : uint = float_bits_to_uint(c2da_fresh64)
            c2da_mem[out_0 + 12 + j_1 * 4] = uint8(c2da_fresh65)
            c2da_mem[out_0 + 12 + j_1 * 4 + 1] = uint8(c2da_fresh65 >> 0x8)
            c2da_mem[out_0 + 12 + j_1 * 4 + 2] = uint8(c2da_fresh65 >> 0x10)
            c2da_mem[out_0 + 12 + j_1 * 4 + 3] = uint8(c2da_fresh65 >> 0x18)
            let c2da_fresh66 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[in_1 + 24 + j_1 * 4]) | uint(c2da_mem[in_1 + 24 + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[in_1 + 24 + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[in_1 + 24 + j_1 * 4 + 3]) << 0x18))
            let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
            c2da_mem[out_0 + 24 + j_1 * 4] = uint8(c2da_fresh67)
            c2da_mem[out_0 + 24 + j_1 * 4 + 1] = uint8(c2da_fresh67 >> 0x8)
            c2da_mem[out_0 + 24 + j_1 * 4 + 2] = uint8(c2da_fresh67 >> 0x10)
            c2da_mem[out_0 + 24 + j_1 * 4 + 3] = uint8(c2da_fresh67 >> 0x18)
            j_1++
        }
        j_1 = 0
        while (j_1 < 4) {
            let c2da_fresh68 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[in_1 + 36 + j_1 * 4]) | uint(c2da_mem[in_1 + 36 + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[in_1 + 36 + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[in_1 + 36 + j_1 * 4 + 3]) << 0x18))
            let c2da_fresh69 : uint = uint(c2da_fresh68)
            c2da_mem[out_0 + 36 + j_1 * 4] = uint8(c2da_fresh69)
            c2da_mem[out_0 + 36 + j_1 * 4 + 1] = uint8(c2da_fresh69 >> 0x8)
            c2da_mem[out_0 + 36 + j_1 * 4 + 2] = uint8(c2da_fresh69 >> 0x10)
            c2da_mem[out_0 + 36 + j_1 * 4 + 3] = uint8(c2da_fresh69 >> 0x18)
            j_1++
        }
        let c2da_fresh70 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[in_1 + 52]) | uint(c2da_mem[in_1 + 53]) << 0x8 | uint(c2da_mem[in_1 + 54]) << 0x10 | uint(c2da_mem[in_1 + 55]) << 0x18))
        let c2da_fresh71 : uint = uint(c2da_fresh70)
        c2da_mem[out_0 + 52] = uint8(c2da_fresh71)
        c2da_mem[out_0 + 53] = uint8(c2da_fresh71 >> 0x8)
        c2da_mem[out_0 + 54] = uint8(c2da_fresh71 >> 0x10)
        c2da_mem[out_0 + 55] = uint8(c2da_fresh71 >> 0x18)
        let c2da_fresh72 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[in_1 + 56]) | uint(c2da_mem[in_1 + 57]) << 0x8 | uint(c2da_mem[in_1 + 58]) << 0x10 | uint(c2da_mem[in_1 + 59]) << 0x18))
        let c2da_fresh73 : uint = uint(c2da_fresh72)
        c2da_mem[out_0 + 56] = uint8(c2da_fresh73)
        c2da_mem[out_0 + 57] = uint8(c2da_fresh73 >> 0x8)
        c2da_mem[out_0 + 58] = uint8(c2da_fresh73 >> 0x10)
        c2da_mem[out_0 + 59] = uint8(c2da_fresh73 >> 0x18)
        let c2da_fresh74 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[in_1 + 60]) | uint(c2da_mem[in_1 + 61]) << 0x8 | uint(c2da_mem[in_1 + 62]) << 0x10 | uint(c2da_mem[in_1 + 63]) << 0x18))
        let c2da_fresh75 : uint = uint(c2da_fresh74)
        c2da_mem[out_0 + 60] = uint8(c2da_fresh75)
        c2da_mem[out_0 + 61] = uint8(c2da_fresh75 >> 0x8)
        c2da_mem[out_0 + 62] = uint8(c2da_fresh75 >> 0x10)
        c2da_mem[out_0 + 63] = uint8(c2da_fresh75 >> 0x18)
        i_4++
        in_1 += 64
        out_0 += 64
    }
    return
}
var mod_base : int = default<int>

[export, sideeffects]
def Mod_LoadEntities(var l_0 : int) {
    if (int(uint(c2da_mem[l_0 + 4]) | uint(c2da_mem[l_0 + 5]) << 0x8 | uint(c2da_mem[l_0 + 6]) << 0x10 | uint(c2da_mem[l_0 + 7]) << 0x18) == 0) {
        let c2da_fresh76 : uint = 0u
        c2da_mem[loadmodel + 520] = uint8(c2da_fresh76)
        c2da_mem[loadmodel + 521] = uint8(c2da_fresh76 >> 0x8)
        c2da_mem[loadmodel + 522] = uint8(c2da_fresh76 >> 0x10)
        c2da_mem[loadmodel + 523] = uint8(c2da_fresh76 >> 0x18)
        c2da_mem[loadmodel + 524] = 0u8
        c2da_mem[loadmodel + 525] = 0u8
        c2da_mem[loadmodel + 526] = 0u8
        c2da_mem[loadmodel + 527] = 0u8
        return
    }
    let c2da_fresh77 : int = Hunk_AllocName(int(uint(c2da_mem[l_0 + 4]) | uint(c2da_mem[l_0 + 5]) << 0x8 | uint(c2da_mem[l_0 + 6]) << 0x10 | uint(c2da_mem[l_0 + 7]) << 0x18), 386384)
    let c2da_fresh78 : uint = uint(c2da_fresh77)
    c2da_mem[loadmodel + 520] = uint8(c2da_fresh78)
    c2da_mem[loadmodel + 521] = uint8(c2da_fresh78 >> 0x8)
    c2da_mem[loadmodel + 522] = uint8(c2da_fresh78 >> 0x10)
    c2da_mem[loadmodel + 523] = uint8(c2da_fresh78 >> 0x18)
    c2da_mem[loadmodel + 524] = 0u8
    c2da_mem[loadmodel + 525] = 0u8
    c2da_mem[loadmodel + 526] = 0u8
    c2da_mem[loadmodel + 527] = 0u8
    c2da_lin_memcpy(int(uint(c2da_mem[loadmodel + 520]) | uint(c2da_mem[loadmodel + 521]) << 0x8 | uint(c2da_mem[loadmodel + 522]) << 0x10 | uint(c2da_mem[loadmodel + 523]) << 0x18), mod_base + int(uint(c2da_mem[l_0]) | uint(c2da_mem[l_0 + 1]) << 0x8 | uint(c2da_mem[l_0 + 2]) << 0x10 | uint(c2da_mem[l_0 + 3]) << 0x18), uint64(int(uint(c2da_mem[l_0 + 4]) | uint(c2da_mem[l_0 + 5]) << 0x8 | uint(c2da_mem[l_0 + 6]) << 0x10 | uint(c2da_mem[l_0 + 7]) << 0x18)))
    return
}
[export, sideeffects]
def Mod_LoadClipnodes(var l_1 : int) {
    var in_2 : int
    var out_1 : int
    var i_5 : int
    var count_1 : int
    var hull_0 : int
    in_2 = mod_base + int(uint(c2da_mem[l_1]) | uint(c2da_mem[l_1 + 1]) << 0x8 | uint(c2da_mem[l_1 + 2]) << 0x10 | uint(c2da_mem[l_1 + 3]) << 0x18)
    if (uint64(int(uint(c2da_mem[l_1 + 4]) | uint(c2da_mem[l_1 + 5]) << 0x8 | uint(c2da_mem[l_1 + 6]) << 0x10 | uint(c2da_mem[l_1 + 7]) << 0x18)) % 8ul != 0x0) {
        Sys_Error(726168, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(loadmodel))])
    }
    count_1 = int(uint64(int(uint(c2da_mem[l_1 + 4]) | uint(c2da_mem[l_1 + 5]) << 0x8 | uint(c2da_mem[l_1 + 6]) << 0x10 | uint(c2da_mem[l_1 + 7]) << 0x18)) / 8ul)
    out_1 = Hunk_AllocName(int(uint64(count_1) * 8ul), 386384)
    let c2da_fresh79 : uint = uint(out_1)
    c2da_mem[loadmodel + 272] = uint8(c2da_fresh79)
    c2da_mem[loadmodel + 273] = uint8(c2da_fresh79 >> 0x8)
    c2da_mem[loadmodel + 274] = uint8(c2da_fresh79 >> 0x10)
    c2da_mem[loadmodel + 275] = uint8(c2da_fresh79 >> 0x18)
    c2da_mem[loadmodel + 276] = 0u8
    c2da_mem[loadmodel + 277] = 0u8
    c2da_mem[loadmodel + 278] = 0u8
    c2da_mem[loadmodel + 279] = 0u8
    let c2da_fresh80 : uint = uint(count_1)
    c2da_mem[loadmodel + 264] = uint8(c2da_fresh80)
    c2da_mem[loadmodel + 265] = uint8(c2da_fresh80 >> 0x8)
    c2da_mem[loadmodel + 266] = uint8(c2da_fresh80 >> 0x10)
    c2da_mem[loadmodel + 267] = uint8(c2da_fresh80 >> 0x18)
    hull_0 = loadmodel + 296 + 1 * 48
    let c2da_fresh81 : uint = uint(out_1)
    c2da_mem[hull_0] = uint8(c2da_fresh81)
    c2da_mem[hull_0 + 1] = uint8(c2da_fresh81 >> 0x8)
    c2da_mem[hull_0 + 2] = uint8(c2da_fresh81 >> 0x10)
    c2da_mem[hull_0 + 3] = uint8(c2da_fresh81 >> 0x18)
    c2da_mem[hull_0 + 4] = 0u8
    c2da_mem[hull_0 + 5] = 0u8
    c2da_mem[hull_0 + 6] = 0u8
    c2da_mem[hull_0 + 7] = 0u8
    let c2da_fresh82 : int = 0
    let c2da_fresh83 : uint = uint(c2da_fresh82)
    c2da_mem[hull_0 + 16] = uint8(c2da_fresh83)
    c2da_mem[hull_0 + 17] = uint8(c2da_fresh83 >> 0x8)
    c2da_mem[hull_0 + 18] = uint8(c2da_fresh83 >> 0x10)
    c2da_mem[hull_0 + 19] = uint8(c2da_fresh83 >> 0x18)
    let c2da_fresh84 : int = count_1 - 1
    let c2da_fresh85 : uint = uint(c2da_fresh84)
    c2da_mem[hull_0 + 20] = uint8(c2da_fresh85)
    c2da_mem[hull_0 + 21] = uint8(c2da_fresh85 >> 0x8)
    c2da_mem[hull_0 + 22] = uint8(c2da_fresh85 >> 0x10)
    c2da_mem[hull_0 + 23] = uint8(c2da_fresh85 >> 0x18)
    let c2da_fresh86 : int = int(uint(c2da_mem[loadmodel + 144]) | uint(c2da_mem[loadmodel + 145]) << 0x8 | uint(c2da_mem[loadmodel + 146]) << 0x10 | uint(c2da_mem[loadmodel + 147]) << 0x18)
    let c2da_fresh87 : uint = uint(c2da_fresh86)
    c2da_mem[hull_0 + 8] = uint8(c2da_fresh87)
    c2da_mem[hull_0 + 9] = uint8(c2da_fresh87 >> 0x8)
    c2da_mem[hull_0 + 10] = uint8(c2da_fresh87 >> 0x10)
    c2da_mem[hull_0 + 11] = uint8(c2da_fresh87 >> 0x18)
    c2da_mem[hull_0 + 12] = 0u8
    c2da_mem[hull_0 + 13] = 0u8
    c2da_mem[hull_0 + 14] = 0u8
    c2da_mem[hull_0 + 15] = 0u8
    let c2da_fresh88 : float = -16.0
    let c2da_fresh89 : uint = float_bits_to_uint(c2da_fresh88)
    c2da_mem[hull_0 + 24 + 0 * 4] = uint8(c2da_fresh89)
    c2da_mem[hull_0 + 24 + 0 * 4 + 1] = uint8(c2da_fresh89 >> 0x8)
    c2da_mem[hull_0 + 24 + 0 * 4 + 2] = uint8(c2da_fresh89 >> 0x10)
    c2da_mem[hull_0 + 24 + 0 * 4 + 3] = uint8(c2da_fresh89 >> 0x18)
    let c2da_fresh90 : float = -16.0
    let c2da_fresh91 : uint = float_bits_to_uint(c2da_fresh90)
    c2da_mem[hull_0 + 24 + 1 * 4] = uint8(c2da_fresh91)
    c2da_mem[hull_0 + 24 + 1 * 4 + 1] = uint8(c2da_fresh91 >> 0x8)
    c2da_mem[hull_0 + 24 + 1 * 4 + 2] = uint8(c2da_fresh91 >> 0x10)
    c2da_mem[hull_0 + 24 + 1 * 4 + 3] = uint8(c2da_fresh91 >> 0x18)
    let c2da_fresh92 : float = -24.0
    let c2da_fresh93 : uint = float_bits_to_uint(c2da_fresh92)
    c2da_mem[hull_0 + 24 + 2 * 4] = uint8(c2da_fresh93)
    c2da_mem[hull_0 + 24 + 2 * 4 + 1] = uint8(c2da_fresh93 >> 0x8)
    c2da_mem[hull_0 + 24 + 2 * 4 + 2] = uint8(c2da_fresh93 >> 0x10)
    c2da_mem[hull_0 + 24 + 2 * 4 + 3] = uint8(c2da_fresh93 >> 0x18)
    let c2da_fresh94 : float = 16.0
    let c2da_fresh95 : uint = float_bits_to_uint(c2da_fresh94)
    c2da_mem[hull_0 + 36 + 0 * 4] = uint8(c2da_fresh95)
    c2da_mem[hull_0 + 36 + 0 * 4 + 1] = uint8(c2da_fresh95 >> 0x8)
    c2da_mem[hull_0 + 36 + 0 * 4 + 2] = uint8(c2da_fresh95 >> 0x10)
    c2da_mem[hull_0 + 36 + 0 * 4 + 3] = uint8(c2da_fresh95 >> 0x18)
    let c2da_fresh96 : float = 16.0
    let c2da_fresh97 : uint = float_bits_to_uint(c2da_fresh96)
    c2da_mem[hull_0 + 36 + 1 * 4] = uint8(c2da_fresh97)
    c2da_mem[hull_0 + 36 + 1 * 4 + 1] = uint8(c2da_fresh97 >> 0x8)
    c2da_mem[hull_0 + 36 + 1 * 4 + 2] = uint8(c2da_fresh97 >> 0x10)
    c2da_mem[hull_0 + 36 + 1 * 4 + 3] = uint8(c2da_fresh97 >> 0x18)
    let c2da_fresh98 : float = 32.0
    let c2da_fresh99 : uint = float_bits_to_uint(c2da_fresh98)
    c2da_mem[hull_0 + 36 + 2 * 4] = uint8(c2da_fresh99)
    c2da_mem[hull_0 + 36 + 2 * 4 + 1] = uint8(c2da_fresh99 >> 0x8)
    c2da_mem[hull_0 + 36 + 2 * 4 + 2] = uint8(c2da_fresh99 >> 0x10)
    c2da_mem[hull_0 + 36 + 2 * 4 + 3] = uint8(c2da_fresh99 >> 0x18)
    hull_0 = loadmodel + 296 + 2 * 48
    let c2da_fresh100 : uint = uint(out_1)
    c2da_mem[hull_0] = uint8(c2da_fresh100)
    c2da_mem[hull_0 + 1] = uint8(c2da_fresh100 >> 0x8)
    c2da_mem[hull_0 + 2] = uint8(c2da_fresh100 >> 0x10)
    c2da_mem[hull_0 + 3] = uint8(c2da_fresh100 >> 0x18)
    c2da_mem[hull_0 + 4] = 0u8
    c2da_mem[hull_0 + 5] = 0u8
    c2da_mem[hull_0 + 6] = 0u8
    c2da_mem[hull_0 + 7] = 0u8
    let c2da_fresh101 : int = 0
    let c2da_fresh102 : uint = uint(c2da_fresh101)
    c2da_mem[hull_0 + 16] = uint8(c2da_fresh102)
    c2da_mem[hull_0 + 17] = uint8(c2da_fresh102 >> 0x8)
    c2da_mem[hull_0 + 18] = uint8(c2da_fresh102 >> 0x10)
    c2da_mem[hull_0 + 19] = uint8(c2da_fresh102 >> 0x18)
    let c2da_fresh103 : int = count_1 - 1
    let c2da_fresh104 : uint = uint(c2da_fresh103)
    c2da_mem[hull_0 + 20] = uint8(c2da_fresh104)
    c2da_mem[hull_0 + 21] = uint8(c2da_fresh104 >> 0x8)
    c2da_mem[hull_0 + 22] = uint8(c2da_fresh104 >> 0x10)
    c2da_mem[hull_0 + 23] = uint8(c2da_fresh104 >> 0x18)
    let c2da_fresh105 : int = int(uint(c2da_mem[loadmodel + 144]) | uint(c2da_mem[loadmodel + 145]) << 0x8 | uint(c2da_mem[loadmodel + 146]) << 0x10 | uint(c2da_mem[loadmodel + 147]) << 0x18)
    let c2da_fresh106 : uint = uint(c2da_fresh105)
    c2da_mem[hull_0 + 8] = uint8(c2da_fresh106)
    c2da_mem[hull_0 + 9] = uint8(c2da_fresh106 >> 0x8)
    c2da_mem[hull_0 + 10] = uint8(c2da_fresh106 >> 0x10)
    c2da_mem[hull_0 + 11] = uint8(c2da_fresh106 >> 0x18)
    c2da_mem[hull_0 + 12] = 0u8
    c2da_mem[hull_0 + 13] = 0u8
    c2da_mem[hull_0 + 14] = 0u8
    c2da_mem[hull_0 + 15] = 0u8
    let c2da_fresh107 : float = -32.0
    let c2da_fresh108 : uint = float_bits_to_uint(c2da_fresh107)
    c2da_mem[hull_0 + 24 + 0 * 4] = uint8(c2da_fresh108)
    c2da_mem[hull_0 + 24 + 0 * 4 + 1] = uint8(c2da_fresh108 >> 0x8)
    c2da_mem[hull_0 + 24 + 0 * 4 + 2] = uint8(c2da_fresh108 >> 0x10)
    c2da_mem[hull_0 + 24 + 0 * 4 + 3] = uint8(c2da_fresh108 >> 0x18)
    let c2da_fresh109 : float = -32.0
    let c2da_fresh110 : uint = float_bits_to_uint(c2da_fresh109)
    c2da_mem[hull_0 + 24 + 1 * 4] = uint8(c2da_fresh110)
    c2da_mem[hull_0 + 24 + 1 * 4 + 1] = uint8(c2da_fresh110 >> 0x8)
    c2da_mem[hull_0 + 24 + 1 * 4 + 2] = uint8(c2da_fresh110 >> 0x10)
    c2da_mem[hull_0 + 24 + 1 * 4 + 3] = uint8(c2da_fresh110 >> 0x18)
    let c2da_fresh111 : float = -24.0
    let c2da_fresh112 : uint = float_bits_to_uint(c2da_fresh111)
    c2da_mem[hull_0 + 24 + 2 * 4] = uint8(c2da_fresh112)
    c2da_mem[hull_0 + 24 + 2 * 4 + 1] = uint8(c2da_fresh112 >> 0x8)
    c2da_mem[hull_0 + 24 + 2 * 4 + 2] = uint8(c2da_fresh112 >> 0x10)
    c2da_mem[hull_0 + 24 + 2 * 4 + 3] = uint8(c2da_fresh112 >> 0x18)
    let c2da_fresh113 : float = 32.0
    let c2da_fresh114 : uint = float_bits_to_uint(c2da_fresh113)
    c2da_mem[hull_0 + 36 + 0 * 4] = uint8(c2da_fresh114)
    c2da_mem[hull_0 + 36 + 0 * 4 + 1] = uint8(c2da_fresh114 >> 0x8)
    c2da_mem[hull_0 + 36 + 0 * 4 + 2] = uint8(c2da_fresh114 >> 0x10)
    c2da_mem[hull_0 + 36 + 0 * 4 + 3] = uint8(c2da_fresh114 >> 0x18)
    let c2da_fresh115 : float = 32.0
    let c2da_fresh116 : uint = float_bits_to_uint(c2da_fresh115)
    c2da_mem[hull_0 + 36 + 1 * 4] = uint8(c2da_fresh116)
    c2da_mem[hull_0 + 36 + 1 * 4 + 1] = uint8(c2da_fresh116 >> 0x8)
    c2da_mem[hull_0 + 36 + 1 * 4 + 2] = uint8(c2da_fresh116 >> 0x10)
    c2da_mem[hull_0 + 36 + 1 * 4 + 3] = uint8(c2da_fresh116 >> 0x18)
    let c2da_fresh117 : float = 64.0
    let c2da_fresh118 : uint = float_bits_to_uint(c2da_fresh117)
    c2da_mem[hull_0 + 36 + 2 * 4] = uint8(c2da_fresh118)
    c2da_mem[hull_0 + 36 + 2 * 4 + 1] = uint8(c2da_fresh118 >> 0x8)
    c2da_mem[hull_0 + 36 + 2 * 4 + 2] = uint8(c2da_fresh118 >> 0x10)
    c2da_mem[hull_0 + 36 + 2 * 4 + 3] = uint8(c2da_fresh118 >> 0x18)
    i_5 = 0
    while (i_5 < count_1) {
        let c2da_fresh119 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[in_2]) | uint(c2da_mem[in_2 + 1]) << 0x8 | uint(c2da_mem[in_2 + 2]) << 0x10 | uint(c2da_mem[in_2 + 3]) << 0x18))
        let c2da_fresh120 : uint = uint(c2da_fresh119)
        c2da_mem[out_1] = uint8(c2da_fresh120)
        c2da_mem[out_1 + 1] = uint8(c2da_fresh120 >> 0x8)
        c2da_mem[out_1 + 2] = uint8(c2da_fresh120 >> 0x10)
        c2da_mem[out_1 + 3] = uint8(c2da_fresh120 >> 0x18)
        let c2da_fresh121 : int16 = invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[in_2 + 4 + 0 * 2]) | uint(c2da_mem[in_2 + 4 + 0 * 2 + 1]) << 0x8))
        let c2da_fresh122 : uint = uint(c2da_fresh121)
        c2da_mem[out_1 + 4 + 0 * 2] = uint8(c2da_fresh122)
        c2da_mem[out_1 + 4 + 0 * 2 + 1] = uint8(c2da_fresh122 >> 0x8)
        let c2da_fresh123 : int16 = invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[in_2 + 4 + 1 * 2]) | uint(c2da_mem[in_2 + 4 + 1 * 2 + 1]) << 0x8))
        let c2da_fresh124 : uint = uint(c2da_fresh123)
        c2da_mem[out_1 + 4 + 1 * 2] = uint8(c2da_fresh124)
        c2da_mem[out_1 + 4 + 1 * 2 + 1] = uint8(c2da_fresh124 >> 0x8)
        i_5++
        out_1 += 8
        in_2 += 8
    }
    return
}
[export, sideeffects]
def Mod_LoadNodes(var l_2 : int) {
    var i_6 : int
    var j_2 : int
    var count_2 : int
    var p : int
    var in_3 : int
    var out_2 : int
    in_3 = mod_base + int(uint(c2da_mem[l_2]) | uint(c2da_mem[l_2 + 1]) << 0x8 | uint(c2da_mem[l_2 + 2]) << 0x10 | uint(c2da_mem[l_2 + 3]) << 0x18)
    if (uint64(int(uint(c2da_mem[l_2 + 4]) | uint(c2da_mem[l_2 + 5]) << 0x8 | uint(c2da_mem[l_2 + 6]) << 0x10 | uint(c2da_mem[l_2 + 7]) << 0x18)) % 24ul != 0x0) {
        Sys_Error(726168, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(loadmodel))])
    }
    count_2 = int(uint64(int(uint(c2da_mem[l_2 + 4]) | uint(c2da_mem[l_2 + 5]) << 0x8 | uint(c2da_mem[l_2 + 6]) << 0x10 | uint(c2da_mem[l_2 + 7]) << 0x18)) / 24ul)
    out_2 = Hunk_AllocName(int(uint64(count_2) * 64ul), 386384)
    let c2da_fresh125 : uint = uint(out_2)
    c2da_mem[loadmodel + 208] = uint8(c2da_fresh125)
    c2da_mem[loadmodel + 209] = uint8(c2da_fresh125 >> 0x8)
    c2da_mem[loadmodel + 210] = uint8(c2da_fresh125 >> 0x10)
    c2da_mem[loadmodel + 211] = uint8(c2da_fresh125 >> 0x18)
    c2da_mem[loadmodel + 212] = 0u8
    c2da_mem[loadmodel + 213] = 0u8
    c2da_mem[loadmodel + 214] = 0u8
    c2da_mem[loadmodel + 215] = 0u8
    let c2da_fresh126 : uint = uint(count_2)
    c2da_mem[loadmodel + 200] = uint8(c2da_fresh126)
    c2da_mem[loadmodel + 201] = uint8(c2da_fresh126 >> 0x8)
    c2da_mem[loadmodel + 202] = uint8(c2da_fresh126 >> 0x10)
    c2da_mem[loadmodel + 203] = uint8(c2da_fresh126 >> 0x18)
    i_6 = 0
    while (i_6 < count_2) {
        j_2 = 0
        while (j_2 < 3) {
            let c2da_fresh127 : int16 = invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[in_3 + 8 + j_2 * 2]) | uint(c2da_mem[in_3 + 8 + j_2 * 2 + 1]) << 0x8))
            let c2da_fresh128 : uint = uint(c2da_fresh127)
            c2da_mem[out_2 + 8 + j_2 * 2] = uint8(c2da_fresh128)
            c2da_mem[out_2 + 8 + j_2 * 2 + 1] = uint8(c2da_fresh128 >> 0x8)
            let c2da_fresh129 : int16 = invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[in_3 + 14 + j_2 * 2]) | uint(c2da_mem[in_3 + 14 + j_2 * 2 + 1]) << 0x8))
            let c2da_fresh130 : uint = uint(c2da_fresh129)
            c2da_mem[out_2 + 8 + (3 + j_2) * 2] = uint8(c2da_fresh130)
            c2da_mem[out_2 + 8 + (3 + j_2) * 2 + 1] = uint8(c2da_fresh130 >> 0x8)
            j_2++
        }
        p = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[in_3]) | uint(c2da_mem[in_3 + 1]) << 0x8 | uint(c2da_mem[in_3 + 2]) << 0x10 | uint(c2da_mem[in_3 + 3]) << 0x18))
        let c2da_fresh131 : int = int(uint(c2da_mem[loadmodel + 144]) | uint(c2da_mem[loadmodel + 145]) << 0x8 | uint(c2da_mem[loadmodel + 146]) << 0x10 | uint(c2da_mem[loadmodel + 147]) << 0x18) + p * 20
        let c2da_fresh132 : uint = uint(c2da_fresh131)
        c2da_mem[out_2 + 32] = uint8(c2da_fresh132)
        c2da_mem[out_2 + 33] = uint8(c2da_fresh132 >> 0x8)
        c2da_mem[out_2 + 34] = uint8(c2da_fresh132 >> 0x10)
        c2da_mem[out_2 + 35] = uint8(c2da_fresh132 >> 0x18)
        c2da_mem[out_2 + 36] = 0u8
        c2da_mem[out_2 + 37] = 0u8
        c2da_mem[out_2 + 38] = 0u8
        c2da_mem[out_2 + 39] = 0u8
        let c2da_fresh133 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(uint16(uint(c2da_mem[in_3 + 20]) | uint(c2da_mem[in_3 + 21]) << 0x8))))
        let c2da_fresh134 : uint = uint(c2da_fresh133)
        c2da_mem[out_2 + 56] = uint8(c2da_fresh134)
        c2da_mem[out_2 + 57] = uint8(c2da_fresh134 >> 0x8)
        let c2da_fresh135 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(uint16(uint(c2da_mem[in_3 + 22]) | uint(c2da_mem[in_3 + 23]) << 0x8))))
        let c2da_fresh136 : uint = uint(c2da_fresh135)
        c2da_mem[out_2 + 58] = uint8(c2da_fresh136)
        c2da_mem[out_2 + 59] = uint8(c2da_fresh136 >> 0x8)
        j_2 = 0
        while (j_2 < 2) {
            p = int(invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[in_3 + 4 + j_2 * 2]) | uint(c2da_mem[in_3 + 4 + j_2 * 2 + 1]) << 0x8)))
            if (p >= 0) {
                let c2da_fresh137 : int = int(uint(c2da_mem[loadmodel + 208]) | uint(c2da_mem[loadmodel + 209]) << 0x8 | uint(c2da_mem[loadmodel + 210]) << 0x10 | uint(c2da_mem[loadmodel + 211]) << 0x18) + p * 64
                let c2da_fresh138 : uint = uint(c2da_fresh137)
                c2da_mem[out_2 + 40 + j_2 * 8] = uint8(c2da_fresh138)
                c2da_mem[out_2 + 40 + j_2 * 8 + 1] = uint8(c2da_fresh138 >> 0x8)
                c2da_mem[out_2 + 40 + j_2 * 8 + 2] = uint8(c2da_fresh138 >> 0x10)
                c2da_mem[out_2 + 40 + j_2 * 8 + 3] = uint8(c2da_fresh138 >> 0x18)
                c2da_mem[out_2 + 40 + j_2 * 8 + 4] = 0u8
                c2da_mem[out_2 + 40 + j_2 * 8 + 5] = 0u8
                c2da_mem[out_2 + 40 + j_2 * 8 + 6] = 0u8
                c2da_mem[out_2 + 40 + j_2 * 8 + 7] = 0u8
            } else {
                let c2da_fresh139 : int = int(uint(c2da_mem[loadmodel + 160]) | uint(c2da_mem[loadmodel + 161]) << 0x8 | uint(c2da_mem[loadmodel + 162]) << 0x10 | uint(c2da_mem[loadmodel + 163]) << 0x18) + (-1 - p) * 72
                let c2da_fresh140 : uint = uint(c2da_fresh139)
                c2da_mem[out_2 + 40 + j_2 * 8] = uint8(c2da_fresh140)
                c2da_mem[out_2 + 40 + j_2 * 8 + 1] = uint8(c2da_fresh140 >> 0x8)
                c2da_mem[out_2 + 40 + j_2 * 8 + 2] = uint8(c2da_fresh140 >> 0x10)
                c2da_mem[out_2 + 40 + j_2 * 8 + 3] = uint8(c2da_fresh140 >> 0x18)
                c2da_mem[out_2 + 40 + j_2 * 8 + 4] = 0u8
                c2da_mem[out_2 + 40 + j_2 * 8 + 5] = 0u8
                c2da_mem[out_2 + 40 + j_2 * 8 + 6] = 0u8
                c2da_mem[out_2 + 40 + j_2 * 8 + 7] = 0u8
            }
            j_2++
        }
        i_6++
        in_3 += 24
        out_2 += 64
    }
    Mod_SetParent(int(uint(c2da_mem[loadmodel + 208]) | uint(c2da_mem[loadmodel + 209]) << 0x8 | uint(c2da_mem[loadmodel + 210]) << 0x10 | uint(c2da_mem[loadmodel + 211]) << 0x18), 0)
    return
}
[export, sideeffects]
def Mod_SetParent(var node : int; var parent : int) {
    let c2da_fresh141 : uint = uint(parent)
    c2da_mem[node + 24] = uint8(c2da_fresh141)
    c2da_mem[node + 25] = uint8(c2da_fresh141 >> 0x8)
    c2da_mem[node + 26] = uint8(c2da_fresh141 >> 0x10)
    c2da_mem[node + 27] = uint8(c2da_fresh141 >> 0x18)
    c2da_mem[node + 28] = 0u8
    c2da_mem[node + 29] = 0u8
    c2da_mem[node + 30] = 0u8
    c2da_mem[node + 31] = 0u8
    if (int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18) < 0) {
        return
    }
    Mod_SetParent(int(uint(c2da_mem[node + 40 + 0 * 8]) | uint(c2da_mem[node + 40 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[node + 40 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[node + 40 + 0 * 8 + 3]) << 0x18), node)
    Mod_SetParent(int(uint(c2da_mem[node + 40 + 1 * 8]) | uint(c2da_mem[node + 40 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[node + 40 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[node + 40 + 1 * 8 + 3]) << 0x18), node)
    return
}
[export, sideeffects]
def Mod_LoadLeafs(var l_3 : int) {
    var in_4 : int
    var out_3 : int
    var i_7 : int
    var j_3 : int
    var count_3 : int
    var p_0 : int
    in_4 = mod_base + int(uint(c2da_mem[l_3]) | uint(c2da_mem[l_3 + 1]) << 0x8 | uint(c2da_mem[l_3 + 2]) << 0x10 | uint(c2da_mem[l_3 + 3]) << 0x18)
    if (uint64(int(uint(c2da_mem[l_3 + 4]) | uint(c2da_mem[l_3 + 5]) << 0x8 | uint(c2da_mem[l_3 + 6]) << 0x10 | uint(c2da_mem[l_3 + 7]) << 0x18)) % 28ul != 0x0) {
        Sys_Error(726168, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(loadmodel))])
    }
    count_3 = int(uint64(int(uint(c2da_mem[l_3 + 4]) | uint(c2da_mem[l_3 + 5]) << 0x8 | uint(c2da_mem[l_3 + 6]) << 0x10 | uint(c2da_mem[l_3 + 7]) << 0x18)) / 28ul)
    out_3 = Hunk_AllocName(int(uint64(count_3) * 72ul), 386384)
    let c2da_fresh142 : uint = uint(out_3)
    c2da_mem[loadmodel + 160] = uint8(c2da_fresh142)
    c2da_mem[loadmodel + 161] = uint8(c2da_fresh142 >> 0x8)
    c2da_mem[loadmodel + 162] = uint8(c2da_fresh142 >> 0x10)
    c2da_mem[loadmodel + 163] = uint8(c2da_fresh142 >> 0x18)
    c2da_mem[loadmodel + 164] = 0u8
    c2da_mem[loadmodel + 165] = 0u8
    c2da_mem[loadmodel + 166] = 0u8
    c2da_mem[loadmodel + 167] = 0u8
    let c2da_fresh143 : uint = uint(count_3)
    c2da_mem[loadmodel + 152] = uint8(c2da_fresh143)
    c2da_mem[loadmodel + 153] = uint8(c2da_fresh143 >> 0x8)
    c2da_mem[loadmodel + 154] = uint8(c2da_fresh143 >> 0x10)
    c2da_mem[loadmodel + 155] = uint8(c2da_fresh143 >> 0x18)
    i_7 = 0
    while (i_7 < count_3) {
        j_3 = 0
        while (j_3 < 3) {
            let c2da_fresh144 : int16 = invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[in_4 + 8 + j_3 * 2]) | uint(c2da_mem[in_4 + 8 + j_3 * 2 + 1]) << 0x8))
            let c2da_fresh145 : uint = uint(c2da_fresh144)
            c2da_mem[out_3 + 8 + j_3 * 2] = uint8(c2da_fresh145)
            c2da_mem[out_3 + 8 + j_3 * 2 + 1] = uint8(c2da_fresh145 >> 0x8)
            let c2da_fresh146 : int16 = invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[in_4 + 14 + j_3 * 2]) | uint(c2da_mem[in_4 + 14 + j_3 * 2 + 1]) << 0x8))
            let c2da_fresh147 : uint = uint(c2da_fresh146)
            c2da_mem[out_3 + 8 + (3 + j_3) * 2] = uint8(c2da_fresh147)
            c2da_mem[out_3 + 8 + (3 + j_3) * 2 + 1] = uint8(c2da_fresh147 >> 0x8)
            j_3++
        }
        p_0 = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[in_4]) | uint(c2da_mem[in_4 + 1]) << 0x8 | uint(c2da_mem[in_4 + 2]) << 0x10 | uint(c2da_mem[in_4 + 3]) << 0x18))
        let c2da_fresh148 : uint = uint(p_0)
        c2da_mem[out_3] = uint8(c2da_fresh148)
        c2da_mem[out_3 + 1] = uint8(c2da_fresh148 >> 0x8)
        c2da_mem[out_3 + 2] = uint8(c2da_fresh148 >> 0x10)
        c2da_mem[out_3 + 3] = uint8(c2da_fresh148 >> 0x18)
        let c2da_fresh149 : int = int(uint(c2da_mem[loadmodel + 288]) | uint(c2da_mem[loadmodel + 289]) << 0x8 | uint(c2da_mem[loadmodel + 290]) << 0x10 | uint(c2da_mem[loadmodel + 291]) << 0x18) + int(invoke(c2da_fn_table3[LittleShort], int16(uint16(uint(c2da_mem[in_4 + 20]) | uint(c2da_mem[in_4 + 21]) << 0x8)))) * 8
        let c2da_fresh150 : uint = uint(c2da_fresh149)
        c2da_mem[out_3 + 48] = uint8(c2da_fresh150)
        c2da_mem[out_3 + 49] = uint8(c2da_fresh150 >> 0x8)
        c2da_mem[out_3 + 50] = uint8(c2da_fresh150 >> 0x10)
        c2da_mem[out_3 + 51] = uint8(c2da_fresh150 >> 0x18)
        c2da_mem[out_3 + 52] = 0u8
        c2da_mem[out_3 + 53] = 0u8
        c2da_mem[out_3 + 54] = 0u8
        c2da_mem[out_3 + 55] = 0u8
        let c2da_fresh151 : int = int(invoke(c2da_fn_table3[LittleShort], int16(uint16(uint(c2da_mem[in_4 + 22]) | uint(c2da_mem[in_4 + 23]) << 0x8))))
        let c2da_fresh152 : uint = uint(c2da_fresh151)
        c2da_mem[out_3 + 56] = uint8(c2da_fresh152)
        c2da_mem[out_3 + 57] = uint8(c2da_fresh152 >> 0x8)
        c2da_mem[out_3 + 58] = uint8(c2da_fresh152 >> 0x10)
        c2da_mem[out_3 + 59] = uint8(c2da_fresh152 >> 0x18)
        p_0 = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[in_4 + 4]) | uint(c2da_mem[in_4 + 5]) << 0x8 | uint(c2da_mem[in_4 + 6]) << 0x10 | uint(c2da_mem[in_4 + 7]) << 0x18))
        if (p_0 == -1) {
            let c2da_fresh153 : uint = 0u
            c2da_mem[out_3 + 32] = uint8(c2da_fresh153)
            c2da_mem[out_3 + 33] = uint8(c2da_fresh153 >> 0x8)
            c2da_mem[out_3 + 34] = uint8(c2da_fresh153 >> 0x10)
            c2da_mem[out_3 + 35] = uint8(c2da_fresh153 >> 0x18)
            c2da_mem[out_3 + 36] = 0u8
            c2da_mem[out_3 + 37] = 0u8
            c2da_mem[out_3 + 38] = 0u8
            c2da_mem[out_3 + 39] = 0u8
        } else {
            let c2da_fresh154 : int = int(uint(c2da_mem[loadmodel + 504]) | uint(c2da_mem[loadmodel + 505]) << 0x8 | uint(c2da_mem[loadmodel + 506]) << 0x10 | uint(c2da_mem[loadmodel + 507]) << 0x18) + p_0
            let c2da_fresh155 : uint = uint(c2da_fresh154)
            c2da_mem[out_3 + 32] = uint8(c2da_fresh155)
            c2da_mem[out_3 + 33] = uint8(c2da_fresh155 >> 0x8)
            c2da_mem[out_3 + 34] = uint8(c2da_fresh155 >> 0x10)
            c2da_mem[out_3 + 35] = uint8(c2da_fresh155 >> 0x18)
            c2da_mem[out_3 + 36] = 0u8
            c2da_mem[out_3 + 37] = 0u8
            c2da_mem[out_3 + 38] = 0u8
            c2da_mem[out_3 + 39] = 0u8
        }
        let c2da_fresh156 : uint = 0u
        c2da_mem[out_3 + 40] = uint8(c2da_fresh156)
        c2da_mem[out_3 + 41] = uint8(c2da_fresh156 >> 0x8)
        c2da_mem[out_3 + 42] = uint8(c2da_fresh156 >> 0x10)
        c2da_mem[out_3 + 43] = uint8(c2da_fresh156 >> 0x18)
        c2da_mem[out_3 + 44] = 0u8
        c2da_mem[out_3 + 45] = 0u8
        c2da_mem[out_3 + 46] = 0u8
        c2da_mem[out_3 + 47] = 0u8
        j_3 = 0
        while (j_3 < 4) {
            let c2da_fresh157 : uint8 = c2da_mem[in_4 + 24 + j_3]
            c2da_mem[out_3 + 64 + j_3] = c2da_fresh157
            j_3++
        }
        i_7++
        in_4 += 28
        out_3 += 72
    }
    return
}
[export, sideeffects]
def Mod_LoadVisibility(var l_4 : int) {
    if (int(uint(c2da_mem[l_4 + 4]) | uint(c2da_mem[l_4 + 5]) << 0x8 | uint(c2da_mem[l_4 + 6]) << 0x10 | uint(c2da_mem[l_4 + 7]) << 0x18) == 0) {
        let c2da_fresh158 : uint = 0u
        c2da_mem[loadmodel + 504] = uint8(c2da_fresh158)
        c2da_mem[loadmodel + 505] = uint8(c2da_fresh158 >> 0x8)
        c2da_mem[loadmodel + 506] = uint8(c2da_fresh158 >> 0x10)
        c2da_mem[loadmodel + 507] = uint8(c2da_fresh158 >> 0x18)
        c2da_mem[loadmodel + 508] = 0u8
        c2da_mem[loadmodel + 509] = 0u8
        c2da_mem[loadmodel + 510] = 0u8
        c2da_mem[loadmodel + 511] = 0u8
        return
    }
    let c2da_fresh159 : int = Hunk_AllocName(int(uint(c2da_mem[l_4 + 4]) | uint(c2da_mem[l_4 + 5]) << 0x8 | uint(c2da_mem[l_4 + 6]) << 0x10 | uint(c2da_mem[l_4 + 7]) << 0x18), 386384)
    let c2da_fresh160 : uint = uint(c2da_fresh159)
    c2da_mem[loadmodel + 504] = uint8(c2da_fresh160)
    c2da_mem[loadmodel + 505] = uint8(c2da_fresh160 >> 0x8)
    c2da_mem[loadmodel + 506] = uint8(c2da_fresh160 >> 0x10)
    c2da_mem[loadmodel + 507] = uint8(c2da_fresh160 >> 0x18)
    c2da_mem[loadmodel + 508] = 0u8
    c2da_mem[loadmodel + 509] = 0u8
    c2da_mem[loadmodel + 510] = 0u8
    c2da_mem[loadmodel + 511] = 0u8
    c2da_lin_memcpy(int(uint(c2da_mem[loadmodel + 504]) | uint(c2da_mem[loadmodel + 505]) << 0x8 | uint(c2da_mem[loadmodel + 506]) << 0x10 | uint(c2da_mem[loadmodel + 507]) << 0x18), mod_base + int(uint(c2da_mem[l_4]) | uint(c2da_mem[l_4 + 1]) << 0x8 | uint(c2da_mem[l_4 + 2]) << 0x10 | uint(c2da_mem[l_4 + 3]) << 0x18), uint64(int(uint(c2da_mem[l_4 + 4]) | uint(c2da_mem[l_4 + 5]) << 0x8 | uint(c2da_mem[l_4 + 6]) << 0x10 | uint(c2da_mem[l_4 + 7]) << 0x18)))
    return
}
[export, sideeffects]
def Mod_LoadMarksurfaces(var l_5 : int) {
    var j_4 : int
    var count_4 : int
    var in_5 : int
    var out_4 : int
    in_5 = mod_base + int(uint(c2da_mem[l_5]) | uint(c2da_mem[l_5 + 1]) << 0x8 | uint(c2da_mem[l_5 + 2]) << 0x10 | uint(c2da_mem[l_5 + 3]) << 0x18)
    if (uint64(int(uint(c2da_mem[l_5 + 4]) | uint(c2da_mem[l_5 + 5]) << 0x8 | uint(c2da_mem[l_5 + 6]) << 0x10 | uint(c2da_mem[l_5 + 7]) << 0x18)) % 2ul != 0x0) {
        Sys_Error(726168, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(loadmodel))])
    }
    count_4 = int(uint64(int(uint(c2da_mem[l_5 + 4]) | uint(c2da_mem[l_5 + 5]) << 0x8 | uint(c2da_mem[l_5 + 6]) << 0x10 | uint(c2da_mem[l_5 + 7]) << 0x18)) / 2ul)
    out_4 = Hunk_AllocName(int(uint64(count_4) * 8ul), 386384)
    let c2da_fresh161 : uint = uint(out_4)
    c2da_mem[loadmodel + 288] = uint8(c2da_fresh161)
    c2da_mem[loadmodel + 289] = uint8(c2da_fresh161 >> 0x8)
    c2da_mem[loadmodel + 290] = uint8(c2da_fresh161 >> 0x10)
    c2da_mem[loadmodel + 291] = uint8(c2da_fresh161 >> 0x18)
    c2da_mem[loadmodel + 292] = 0u8
    c2da_mem[loadmodel + 293] = 0u8
    c2da_mem[loadmodel + 294] = 0u8
    c2da_mem[loadmodel + 295] = 0u8
    let c2da_fresh162 : uint = uint(count_4)
    c2da_mem[loadmodel + 280] = uint8(c2da_fresh162)
    c2da_mem[loadmodel + 281] = uint8(c2da_fresh162 >> 0x8)
    c2da_mem[loadmodel + 282] = uint8(c2da_fresh162 >> 0x10)
    c2da_mem[loadmodel + 283] = uint8(c2da_fresh162 >> 0x18)
    for (i_8 in range(0, count_4)) {
        j_4 = int(invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[in_5 + i_8 * 2]) | uint(c2da_mem[in_5 + i_8 * 2 + 1]) << 0x8)))
        if (j_4 >= int(uint(c2da_mem[loadmodel + 232]) | uint(c2da_mem[loadmodel + 233]) << 0x8 | uint(c2da_mem[loadmodel + 234]) << 0x10 | uint(c2da_mem[loadmodel + 235]) << 0x18)) {
            Sys_Error(726206, [])
        }
        let c2da_fresh163 : int = int(uint(c2da_mem[loadmodel + 240]) | uint(c2da_mem[loadmodel + 241]) << 0x8 | uint(c2da_mem[loadmodel + 242]) << 0x10 | uint(c2da_mem[loadmodel + 243]) << 0x18) + j_4 * 104
        let c2da_fresh164 : uint = uint(c2da_fresh163)
        c2da_mem[out_4 + i_8 * 8] = uint8(c2da_fresh164)
        c2da_mem[out_4 + i_8 * 8 + 1] = uint8(c2da_fresh164 >> 0x8)
        c2da_mem[out_4 + i_8 * 8 + 2] = uint8(c2da_fresh164 >> 0x10)
        c2da_mem[out_4 + i_8 * 8 + 3] = uint8(c2da_fresh164 >> 0x18)
        c2da_mem[out_4 + i_8 * 8 + 4] = 0u8
        c2da_mem[out_4 + i_8 * 8 + 5] = 0u8
        c2da_mem[out_4 + i_8 * 8 + 6] = 0u8
        c2da_mem[out_4 + i_8 * 8 + 7] = 0u8
    }
    return
}
[export, sideeffects]
def Mod_LoadFaces(var l_6 : int) {
    var in_6 : int
    var out_5 : int
    var i_9 : int
    var count_5 : int
    var surfnum : int
    var planenum : int
    var side : int
    in_6 = mod_base + int(uint(c2da_mem[l_6]) | uint(c2da_mem[l_6 + 1]) << 0x8 | uint(c2da_mem[l_6 + 2]) << 0x10 | uint(c2da_mem[l_6 + 3]) << 0x18)
    if (uint64(int(uint(c2da_mem[l_6 + 4]) | uint(c2da_mem[l_6 + 5]) << 0x8 | uint(c2da_mem[l_6 + 6]) << 0x10 | uint(c2da_mem[l_6 + 7]) << 0x18)) % 20ul != 0x0) {
        Sys_Error(726168, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(loadmodel))])
    }
    count_5 = int(uint64(int(uint(c2da_mem[l_6 + 4]) | uint(c2da_mem[l_6 + 5]) << 0x8 | uint(c2da_mem[l_6 + 6]) << 0x10 | uint(c2da_mem[l_6 + 7]) << 0x18)) / 20ul)
    out_5 = Hunk_AllocName(int(uint64(count_5) * 104ul), 386384)
    let c2da_fresh165 : uint = uint(out_5)
    c2da_mem[loadmodel + 240] = uint8(c2da_fresh165)
    c2da_mem[loadmodel + 241] = uint8(c2da_fresh165 >> 0x8)
    c2da_mem[loadmodel + 242] = uint8(c2da_fresh165 >> 0x10)
    c2da_mem[loadmodel + 243] = uint8(c2da_fresh165 >> 0x18)
    c2da_mem[loadmodel + 244] = 0u8
    c2da_mem[loadmodel + 245] = 0u8
    c2da_mem[loadmodel + 246] = 0u8
    c2da_mem[loadmodel + 247] = 0u8
    let c2da_fresh166 : uint = uint(count_5)
    c2da_mem[loadmodel + 232] = uint8(c2da_fresh166)
    c2da_mem[loadmodel + 233] = uint8(c2da_fresh166 >> 0x8)
    c2da_mem[loadmodel + 234] = uint8(c2da_fresh166 >> 0x10)
    c2da_mem[loadmodel + 235] = uint8(c2da_fresh166 >> 0x18)
    surfnum = 0
    while (surfnum < count_5) {
        let c2da_fresh167 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[in_6 + 4]) | uint(c2da_mem[in_6 + 5]) << 0x8 | uint(c2da_mem[in_6 + 6]) << 0x10 | uint(c2da_mem[in_6 + 7]) << 0x18))
        let c2da_fresh168 : uint = uint(c2da_fresh167)
        c2da_mem[out_5 + 28] = uint8(c2da_fresh168)
        c2da_mem[out_5 + 29] = uint8(c2da_fresh168 >> 0x8)
        c2da_mem[out_5 + 30] = uint8(c2da_fresh168 >> 0x10)
        c2da_mem[out_5 + 31] = uint8(c2da_fresh168 >> 0x18)
        let c2da_fresh169 : int = int(invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[in_6 + 8]) | uint(c2da_mem[in_6 + 9]) << 0x8)))
        let c2da_fresh170 : uint = uint(c2da_fresh169)
        c2da_mem[out_5 + 32] = uint8(c2da_fresh170)
        c2da_mem[out_5 + 33] = uint8(c2da_fresh170 >> 0x8)
        c2da_mem[out_5 + 34] = uint8(c2da_fresh170 >> 0x10)
        c2da_mem[out_5 + 35] = uint8(c2da_fresh170 >> 0x18)
        let c2da_fresh171 : int = 0
        let c2da_fresh172 : uint = uint(c2da_fresh171)
        c2da_mem[out_5 + 24] = uint8(c2da_fresh172)
        c2da_mem[out_5 + 25] = uint8(c2da_fresh172 >> 0x8)
        c2da_mem[out_5 + 26] = uint8(c2da_fresh172 >> 0x10)
        c2da_mem[out_5 + 27] = uint8(c2da_fresh172 >> 0x18)
        planenum = int(invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[in_6]) | uint(c2da_mem[in_6 + 1]) << 0x8)))
        side = int(invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[in_6 + 2]) | uint(c2da_mem[in_6 + 3]) << 0x8)))
        if (side != 0) {
            let c2da_fresh173 : int = int(uint(c2da_mem[out_5 + 24]) | uint(c2da_mem[out_5 + 25]) << 0x8 | uint(c2da_mem[out_5 + 26]) << 0x10 | uint(c2da_mem[out_5 + 27]) << 0x18) | 2
            let c2da_fresh174 : uint = uint(c2da_fresh173)
            c2da_mem[out_5 + 24] = uint8(c2da_fresh174)
            c2da_mem[out_5 + 25] = uint8(c2da_fresh174 >> 0x8)
            c2da_mem[out_5 + 26] = uint8(c2da_fresh174 >> 0x10)
            c2da_mem[out_5 + 27] = uint8(c2da_fresh174 >> 0x18)
        }
        let c2da_fresh175 : int = int(uint(c2da_mem[loadmodel + 144]) | uint(c2da_mem[loadmodel + 145]) << 0x8 | uint(c2da_mem[loadmodel + 146]) << 0x10 | uint(c2da_mem[loadmodel + 147]) << 0x18) + planenum * 20
        let c2da_fresh176 : uint = uint(c2da_fresh175)
        c2da_mem[out_5 + 16] = uint8(c2da_fresh176)
        c2da_mem[out_5 + 17] = uint8(c2da_fresh176 >> 0x8)
        c2da_mem[out_5 + 18] = uint8(c2da_fresh176 >> 0x10)
        c2da_mem[out_5 + 19] = uint8(c2da_fresh176 >> 0x18)
        c2da_mem[out_5 + 20] = 0u8
        c2da_mem[out_5 + 21] = 0u8
        c2da_mem[out_5 + 22] = 0u8
        c2da_mem[out_5 + 23] = 0u8
        let c2da_fresh177 : int = int(uint(c2da_mem[loadmodel + 224]) | uint(c2da_mem[loadmodel + 225]) << 0x8 | uint(c2da_mem[loadmodel + 226]) << 0x10 | uint(c2da_mem[loadmodel + 227]) << 0x18) + int(invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[in_6 + 10]) | uint(c2da_mem[in_6 + 11]) << 0x8))) * 56
        let c2da_fresh178 : uint = uint(c2da_fresh177)
        c2da_mem[out_5 + 80] = uint8(c2da_fresh178)
        c2da_mem[out_5 + 81] = uint8(c2da_fresh178 >> 0x8)
        c2da_mem[out_5 + 82] = uint8(c2da_fresh178 >> 0x10)
        c2da_mem[out_5 + 83] = uint8(c2da_fresh178 >> 0x18)
        c2da_mem[out_5 + 84] = 0u8
        c2da_mem[out_5 + 85] = 0u8
        c2da_mem[out_5 + 86] = 0u8
        c2da_mem[out_5 + 87] = 0u8
        CalcSurfaceExtents(out_5)
        i_9 = 0
        for (c2da_i_9 in range(i_9, 4)) {
            let c2da_fresh179 : uint8 = c2da_mem[in_6 + 12 + c2da_i_9]
            c2da_mem[out_5 + 88 + c2da_i_9] = c2da_fresh179
        }
        i_9 = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[in_6 + 16]) | uint(c2da_mem[in_6 + 17]) << 0x8 | uint(c2da_mem[in_6 + 18]) << 0x10 | uint(c2da_mem[in_6 + 19]) << 0x18))
        if (i_9 == -1) {
            let c2da_fresh180 : uint = 0u
            c2da_mem[out_5 + 96] = uint8(c2da_fresh180)
            c2da_mem[out_5 + 97] = uint8(c2da_fresh180 >> 0x8)
            c2da_mem[out_5 + 98] = uint8(c2da_fresh180 >> 0x10)
            c2da_mem[out_5 + 99] = uint8(c2da_fresh180 >> 0x18)
            c2da_mem[out_5 + 100] = 0u8
            c2da_mem[out_5 + 101] = 0u8
            c2da_mem[out_5 + 102] = 0u8
            c2da_mem[out_5 + 103] = 0u8
        } else {
            let c2da_fresh181 : int = int(uint(c2da_mem[loadmodel + 512]) | uint(c2da_mem[loadmodel + 513]) << 0x8 | uint(c2da_mem[loadmodel + 514]) << 0x10 | uint(c2da_mem[loadmodel + 515]) << 0x18) + i_9
            let c2da_fresh182 : uint = uint(c2da_fresh181)
            c2da_mem[out_5 + 96] = uint8(c2da_fresh182)
            c2da_mem[out_5 + 97] = uint8(c2da_fresh182 >> 0x8)
            c2da_mem[out_5 + 98] = uint8(c2da_fresh182 >> 0x10)
            c2da_mem[out_5 + 99] = uint8(c2da_fresh182 >> 0x18)
            c2da_mem[out_5 + 100] = 0u8
            c2da_mem[out_5 + 101] = 0u8
            c2da_mem[out_5 + 102] = 0u8
            c2da_mem[out_5 + 103] = 0u8
        }
        let c2da_fresh183 : int = int(uint(c2da_mem[out_5 + 80]) | uint(c2da_mem[out_5 + 81]) << 0x8 | uint(c2da_mem[out_5 + 82]) << 0x10 | uint(c2da_mem[out_5 + 83]) << 0x18) + 40
        if (Q_strncmp(int(uint(c2da_mem[c2da_fresh183]) | uint(c2da_mem[c2da_fresh183 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh183 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh183 + 3]) << 0x18), 726248, 3) == 0) {
            let c2da_fresh184 : int = int(uint(c2da_mem[out_5 + 24]) | uint(c2da_mem[out_5 + 25]) << 0x8 | uint(c2da_mem[out_5 + 26]) << 0x10 | uint(c2da_mem[out_5 + 27]) << 0x18) | (4 | 32)
            let c2da_fresh185 : uint = uint(c2da_fresh184)
            c2da_mem[out_5 + 24] = uint8(c2da_fresh185)
            c2da_mem[out_5 + 25] = uint8(c2da_fresh185 >> 0x8)
            c2da_mem[out_5 + 26] = uint8(c2da_fresh185 >> 0x10)
            c2da_mem[out_5 + 27] = uint8(c2da_fresh185 >> 0x18)
            surfnum++
            in_6 += 20
            out_5 += 104
            continue
        }
        let c2da_fresh186 : int = int(uint(c2da_mem[out_5 + 80]) | uint(c2da_mem[out_5 + 81]) << 0x8 | uint(c2da_mem[out_5 + 82]) << 0x10 | uint(c2da_mem[out_5 + 83]) << 0x18) + 40
        if (Q_strncmp(int(uint(c2da_mem[c2da_fresh186]) | uint(c2da_mem[c2da_fresh186 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh186 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh186 + 3]) << 0x18), 726252, 1) == 0) {
            let c2da_fresh187 : int = int(uint(c2da_mem[out_5 + 24]) | uint(c2da_mem[out_5 + 25]) << 0x8 | uint(c2da_mem[out_5 + 26]) << 0x10 | uint(c2da_mem[out_5 + 27]) << 0x18) | (16 | 32)
            let c2da_fresh188 : uint = uint(c2da_fresh187)
            c2da_mem[out_5 + 24] = uint8(c2da_fresh188)
            c2da_mem[out_5 + 25] = uint8(c2da_fresh188 >> 0x8)
            c2da_mem[out_5 + 26] = uint8(c2da_fresh188 >> 0x10)
            c2da_mem[out_5 + 27] = uint8(c2da_fresh188 >> 0x18)
            i_9 = 0
            while (i_9 < 2) {
                let c2da_fresh189 : int16 = int16(16384)
                let c2da_fresh190 : uint = uint(c2da_fresh189)
                c2da_mem[out_5 + 76 + i_9 * 2] = uint8(c2da_fresh190)
                c2da_mem[out_5 + 76 + i_9 * 2 + 1] = uint8(c2da_fresh190 >> 0x8)
                let c2da_fresh191 : int16 = int16(-8192)
                let c2da_fresh192 : uint = uint(c2da_fresh191)
                c2da_mem[out_5 + 72 + i_9 * 2] = uint8(c2da_fresh192)
                c2da_mem[out_5 + 72 + i_9 * 2 + 1] = uint8(c2da_fresh192 >> 0x8)
                i_9++
            }
            surfnum++
            in_6 += 20
            out_5 += 104
            continue
        }
        surfnum++
        in_6 += 20
        out_5 += 104
    }
    return
}
[export, sideeffects]
def CalcSurfaceExtents(var s : int) {
    var mins_0 : float[2]
    var maxs_0 : float[2]
    var val : float
    var i_10 : int
    var e : int
    var v : int
    var tex : int
    var bmins : int[2]
    var bmaxs : int[2]
    mins_0[1] = 999999.0
    mins_0[0] = float(mins_0[1])  // nolint:PERF020
    maxs_0[1] = -99999.0
    maxs_0[0] = float(maxs_0[1])  // nolint:PERF020
    tex = int(uint(c2da_mem[s + 80]) | uint(c2da_mem[s + 81]) << 0x8 | uint(c2da_mem[s + 82]) << 0x10 | uint(c2da_mem[s + 83]) << 0x18)
    i_10 = 0
    while (i_10 < int(uint(c2da_mem[s + 32]) | uint(c2da_mem[s + 33]) << 0x8 | uint(c2da_mem[s + 34]) << 0x10 | uint(c2da_mem[s + 35]) << 0x18)) {
        let c2da_fresh193 : int = int(uint(c2da_mem[loadmodel + 256]) | uint(c2da_mem[loadmodel + 257]) << 0x8 | uint(c2da_mem[loadmodel + 258]) << 0x10 | uint(c2da_mem[loadmodel + 259]) << 0x18) + (int(uint(c2da_mem[s + 28]) | uint(c2da_mem[s + 29]) << 0x8 | uint(c2da_mem[s + 30]) << 0x10 | uint(c2da_mem[s + 31]) << 0x18) + i_10) * 4
        e = int(uint(c2da_mem[c2da_fresh193]) | uint(c2da_mem[c2da_fresh193 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh193 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh193 + 3]) << 0x18)
        if (e >= 0) {
            let c2da_fresh194 : int = int(uint(c2da_mem[loadmodel + 192]) | uint(c2da_mem[loadmodel + 193]) << 0x8 | uint(c2da_mem[loadmodel + 194]) << 0x10 | uint(c2da_mem[loadmodel + 195]) << 0x18) + e * 8 + 0 * 2
            v = int(uint(c2da_mem[loadmodel + 176]) | uint(c2da_mem[loadmodel + 177]) << 0x8 | uint(c2da_mem[loadmodel + 178]) << 0x10 | uint(c2da_mem[loadmodel + 179]) << 0x18) + int(uint16(uint(c2da_mem[c2da_fresh194]) | uint(c2da_mem[c2da_fresh194 + 1]) << 0x8)) * 12
        } else {
            let c2da_fresh195 : int = int(uint(c2da_mem[loadmodel + 192]) | uint(c2da_mem[loadmodel + 193]) << 0x8 | uint(c2da_mem[loadmodel + 194]) << 0x10 | uint(c2da_mem[loadmodel + 195]) << 0x18) + -e * 8 + 1 * 2
            v = int(uint(c2da_mem[loadmodel + 176]) | uint(c2da_mem[loadmodel + 177]) << 0x8 | uint(c2da_mem[loadmodel + 178]) << 0x10 | uint(c2da_mem[loadmodel + 179]) << 0x18) + int(uint16(uint(c2da_mem[c2da_fresh195]) | uint(c2da_mem[c2da_fresh195 + 1]) << 0x8)) * 12
        }
        for (j_5 in range(0, 2)) {
            val = uint_bits_to_float(uint(c2da_mem[v + 0 * 4]) | uint(c2da_mem[v + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[v + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[v + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[tex + j_5 * 16 + 0 * 4]) | uint(c2da_mem[tex + j_5 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + j_5 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + j_5 * 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[v + 1 * 4]) | uint(c2da_mem[v + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[v + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[v + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[tex + j_5 * 16 + 1 * 4]) | uint(c2da_mem[tex + j_5 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + j_5 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + j_5 * 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[v + 2 * 4]) | uint(c2da_mem[v + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[v + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[v + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[tex + j_5 * 16 + 2 * 4]) | uint(c2da_mem[tex + j_5 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + j_5 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + j_5 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[tex + j_5 * 16 + 3 * 4]) | uint(c2da_mem[tex + j_5 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + j_5 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + j_5 * 16 + 3 * 4 + 3]) << 0x18)
            if (val < mins_0[j_5]) {
                mins_0[j_5] = val
            }
            if (val > maxs_0[j_5]) {
                maxs_0[j_5] = val
            }
        }
        i_10++
    }
    i_10 = 0
    for (c2da_i_10 in range(i_10, 2)) {
        bmins[c2da_i_10] = int(floor(double(mins_0[c2da_i_10] / 16.0)))
        bmaxs[c2da_i_10] = int(ceil(double(maxs_0[c2da_i_10] / 16.0)))
        let c2da_fresh196 : int16 = int16(bmins[c2da_i_10] * 16)
        let c2da_fresh197 : uint = uint(c2da_fresh196)
        c2da_mem[s + 72 + c2da_i_10 * 2] = uint8(c2da_fresh197)
        c2da_mem[s + 72 + c2da_i_10 * 2 + 1] = uint8(c2da_fresh197 >> 0x8)
        let c2da_fresh198 : int16 = int16((bmaxs[c2da_i_10] - bmins[c2da_i_10]) * 16)
        let c2da_fresh199 : uint = uint(c2da_fresh198)
        c2da_mem[s + 76 + c2da_i_10 * 2] = uint8(c2da_fresh199)
        c2da_mem[s + 76 + c2da_i_10 * 2 + 1] = uint8(c2da_fresh199 >> 0x8)
        if ((int(uint(c2da_mem[tex + 48]) | uint(c2da_mem[tex + 49]) << 0x8 | uint(c2da_mem[tex + 50]) << 0x10 | uint(c2da_mem[tex + 51]) << 0x18) & 1) == 0 && int(int16(uint(c2da_mem[s + 76 + c2da_i_10 * 2]) | uint(c2da_mem[s + 76 + c2da_i_10 * 2 + 1]) << 0x8)) > 256) {
            Sys_Error(726254, [])
        }
    }
    return
}
[export, sideeffects]
def Mod_LoadTexinfo(var l_7 : int) {
    var in_7 : int
    var out_6 : int
    var i_11 : int
    var count_6 : int
    var miptex : int
    var len1 : float
    var len2 : float
    in_7 = mod_base + int(uint(c2da_mem[l_7]) | uint(c2da_mem[l_7 + 1]) << 0x8 | uint(c2da_mem[l_7 + 2]) << 0x10 | uint(c2da_mem[l_7 + 3]) << 0x18)
    if (uint64(int(uint(c2da_mem[l_7 + 4]) | uint(c2da_mem[l_7 + 5]) << 0x8 | uint(c2da_mem[l_7 + 6]) << 0x10 | uint(c2da_mem[l_7 + 7]) << 0x18)) % 40ul != 0x0) {
        Sys_Error(726168, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(loadmodel))])
    }
    count_6 = int(uint64(int(uint(c2da_mem[l_7 + 4]) | uint(c2da_mem[l_7 + 5]) << 0x8 | uint(c2da_mem[l_7 + 6]) << 0x10 | uint(c2da_mem[l_7 + 7]) << 0x18)) / 40ul)
    out_6 = Hunk_AllocName(int(uint64(count_6) * 56ul), 386384)
    let c2da_fresh200 : uint = uint(out_6)
    c2da_mem[loadmodel + 224] = uint8(c2da_fresh200)
    c2da_mem[loadmodel + 225] = uint8(c2da_fresh200 >> 0x8)
    c2da_mem[loadmodel + 226] = uint8(c2da_fresh200 >> 0x10)
    c2da_mem[loadmodel + 227] = uint8(c2da_fresh200 >> 0x18)
    c2da_mem[loadmodel + 228] = 0u8
    c2da_mem[loadmodel + 229] = 0u8
    c2da_mem[loadmodel + 230] = 0u8
    c2da_mem[loadmodel + 231] = 0u8
    let c2da_fresh201 : uint = uint(count_6)
    c2da_mem[loadmodel + 216] = uint8(c2da_fresh201)
    c2da_mem[loadmodel + 217] = uint8(c2da_fresh201 >> 0x8)
    c2da_mem[loadmodel + 218] = uint8(c2da_fresh201 >> 0x10)
    c2da_mem[loadmodel + 219] = uint8(c2da_fresh201 >> 0x18)
    i_11 = 0
    while (i_11 < count_6) {
        for (j_6 in range(0, 8)) {
            let c2da_fresh202 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[in_7 + 0 * 16 + j_6 * 4]) | uint(c2da_mem[in_7 + 0 * 16 + j_6 * 4 + 1]) << 0x8 | uint(c2da_mem[in_7 + 0 * 16 + j_6 * 4 + 2]) << 0x10 | uint(c2da_mem[in_7 + 0 * 16 + j_6 * 4 + 3]) << 0x18))
            let c2da_fresh203 : uint = float_bits_to_uint(c2da_fresh202)
            c2da_mem[out_6 + 0 * 16 + j_6 * 4] = uint8(c2da_fresh203)
            c2da_mem[out_6 + 0 * 16 + j_6 * 4 + 1] = uint8(c2da_fresh203 >> 0x8)
            c2da_mem[out_6 + 0 * 16 + j_6 * 4 + 2] = uint8(c2da_fresh203 >> 0x10)
            c2da_mem[out_6 + 0 * 16 + j_6 * 4 + 3] = uint8(c2da_fresh203 >> 0x18)
        }
        len1 = Length(out_6 + 0 * 16)
        len2 = Length(out_6 + 1 * 16)
        len1 = (len1 + len2) / 2.0
        if (double(len1) < 0.32lf) {
            let c2da_fresh204 : float = 4.0
            let c2da_fresh205 : uint = float_bits_to_uint(c2da_fresh204)
            c2da_mem[out_6 + 32] = uint8(c2da_fresh205)
            c2da_mem[out_6 + 33] = uint8(c2da_fresh205 >> 0x8)
            c2da_mem[out_6 + 34] = uint8(c2da_fresh205 >> 0x10)
            c2da_mem[out_6 + 35] = uint8(c2da_fresh205 >> 0x18)
        } elif (double(len1) < 0.49lf) {
            let c2da_fresh206 : float = 3.0
            let c2da_fresh207 : uint = float_bits_to_uint(c2da_fresh206)
            c2da_mem[out_6 + 32] = uint8(c2da_fresh207)
            c2da_mem[out_6 + 33] = uint8(c2da_fresh207 >> 0x8)
            c2da_mem[out_6 + 34] = uint8(c2da_fresh207 >> 0x10)
            c2da_mem[out_6 + 35] = uint8(c2da_fresh207 >> 0x18)
        } elif (double(len1) < 0.99lf) {
            let c2da_fresh208 : float = 2.0
            let c2da_fresh209 : uint = float_bits_to_uint(c2da_fresh208)
            c2da_mem[out_6 + 32] = uint8(c2da_fresh209)
            c2da_mem[out_6 + 33] = uint8(c2da_fresh209 >> 0x8)
            c2da_mem[out_6 + 34] = uint8(c2da_fresh209 >> 0x10)
            c2da_mem[out_6 + 35] = uint8(c2da_fresh209 >> 0x18)
        } else {
            let c2da_fresh210 : float = 1.0
            let c2da_fresh211 : uint = float_bits_to_uint(c2da_fresh210)
            c2da_mem[out_6 + 32] = uint8(c2da_fresh211)
            c2da_mem[out_6 + 33] = uint8(c2da_fresh211 >> 0x8)
            c2da_mem[out_6 + 34] = uint8(c2da_fresh211 >> 0x10)
            c2da_mem[out_6 + 35] = uint8(c2da_fresh211 >> 0x18)
        }
        miptex = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[in_7 + 32]) | uint(c2da_mem[in_7 + 33]) << 0x8 | uint(c2da_mem[in_7 + 34]) << 0x10 | uint(c2da_mem[in_7 + 35]) << 0x18))
        let c2da_fresh212 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[in_7 + 36]) | uint(c2da_mem[in_7 + 37]) << 0x8 | uint(c2da_mem[in_7 + 38]) << 0x10 | uint(c2da_mem[in_7 + 39]) << 0x18))
        let c2da_fresh213 : uint = uint(c2da_fresh212)
        c2da_mem[out_6 + 48] = uint8(c2da_fresh213)
        c2da_mem[out_6 + 49] = uint8(c2da_fresh213 >> 0x8)
        c2da_mem[out_6 + 50] = uint8(c2da_fresh213 >> 0x10)
        c2da_mem[out_6 + 51] = uint8(c2da_fresh213 >> 0x18)
        let c2da_fresh223 : int = int(uint(c2da_mem[loadmodel + 496]) | uint(c2da_mem[loadmodel + 497]) << 0x8 | uint(c2da_mem[loadmodel + 498]) << 0x10 | uint(c2da_mem[loadmodel + 499]) << 0x18)
        if (c2da_fresh223 == 0) {
            let c2da_fresh214 : uint = uint(r_notexture_mip)
            c2da_mem[out_6 + 40] = uint8(c2da_fresh214)
            c2da_mem[out_6 + 41] = uint8(c2da_fresh214 >> 0x8)
            c2da_mem[out_6 + 42] = uint8(c2da_fresh214 >> 0x10)
            c2da_mem[out_6 + 43] = uint8(c2da_fresh214 >> 0x18)
            c2da_mem[out_6 + 44] = 0u8
            c2da_mem[out_6 + 45] = 0u8
            c2da_mem[out_6 + 46] = 0u8
            c2da_mem[out_6 + 47] = 0u8
            let c2da_fresh215 : int = 0
            let c2da_fresh216 : uint = uint(c2da_fresh215)
            c2da_mem[out_6 + 48] = uint8(c2da_fresh216)
            c2da_mem[out_6 + 49] = uint8(c2da_fresh216 >> 0x8)
            c2da_mem[out_6 + 50] = uint8(c2da_fresh216 >> 0x10)
            c2da_mem[out_6 + 51] = uint8(c2da_fresh216 >> 0x18)
        } else {
            if (miptex >= int(uint(c2da_mem[loadmodel + 488]) | uint(c2da_mem[loadmodel + 489]) << 0x8 | uint(c2da_mem[loadmodel + 490]) << 0x10 | uint(c2da_mem[loadmodel + 491]) << 0x18)) {
                Sys_Error(726274, [])
            }
            let c2da_fresh217 : int = int(uint(c2da_mem[loadmodel + 496]) | uint(c2da_mem[loadmodel + 497]) << 0x8 | uint(c2da_mem[loadmodel + 498]) << 0x10 | uint(c2da_mem[loadmodel + 499]) << 0x18) + miptex * 8
            let c2da_fresh218 : int = int(uint(c2da_mem[c2da_fresh217]) | uint(c2da_mem[c2da_fresh217 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh217 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh217 + 3]) << 0x18)
            let c2da_fresh219 : uint = uint(c2da_fresh218)
            c2da_mem[out_6 + 40] = uint8(c2da_fresh219)
            c2da_mem[out_6 + 41] = uint8(c2da_fresh219 >> 0x8)
            c2da_mem[out_6 + 42] = uint8(c2da_fresh219 >> 0x10)
            c2da_mem[out_6 + 43] = uint8(c2da_fresh219 >> 0x18)
            c2da_mem[out_6 + 44] = 0u8
            c2da_mem[out_6 + 45] = 0u8
            c2da_mem[out_6 + 46] = 0u8
            c2da_mem[out_6 + 47] = 0u8
            if (int(uint(c2da_mem[out_6 + 40]) | uint(c2da_mem[out_6 + 41]) << 0x8 | uint(c2da_mem[out_6 + 42]) << 0x10 | uint(c2da_mem[out_6 + 43]) << 0x18) == 0) {
                let c2da_fresh220 : uint = uint(r_notexture_mip)
                c2da_mem[out_6 + 40] = uint8(c2da_fresh220)
                c2da_mem[out_6 + 41] = uint8(c2da_fresh220 >> 0x8)
                c2da_mem[out_6 + 42] = uint8(c2da_fresh220 >> 0x10)
                c2da_mem[out_6 + 43] = uint8(c2da_fresh220 >> 0x18)
                c2da_mem[out_6 + 44] = 0u8
                c2da_mem[out_6 + 45] = 0u8
                c2da_mem[out_6 + 46] = 0u8
                c2da_mem[out_6 + 47] = 0u8
                let c2da_fresh221 : int = 0
                let c2da_fresh222 : uint = uint(c2da_fresh221)
                c2da_mem[out_6 + 48] = uint8(c2da_fresh222)
                c2da_mem[out_6 + 49] = uint8(c2da_fresh222 >> 0x8)
                c2da_mem[out_6 + 50] = uint8(c2da_fresh222 >> 0x10)
                c2da_mem[out_6 + 51] = uint8(c2da_fresh222 >> 0x18)
            }
        }
        i_11++
        in_7 += 40
        out_6 += 56
    }
    return
}
[export, sideeffects]
def Mod_LoadPlanes(var l_8 : int) {
    var i_12 : int
    var out_7 : int
    var in_8 : int
    var count_7 : int
    var bits : int
    in_8 = mod_base + int(uint(c2da_mem[l_8]) | uint(c2da_mem[l_8 + 1]) << 0x8 | uint(c2da_mem[l_8 + 2]) << 0x10 | uint(c2da_mem[l_8 + 3]) << 0x18)
    if (uint64(int(uint(c2da_mem[l_8 + 4]) | uint(c2da_mem[l_8 + 5]) << 0x8 | uint(c2da_mem[l_8 + 6]) << 0x10 | uint(c2da_mem[l_8 + 7]) << 0x18)) % 20ul != 0x0) {
        Sys_Error(726168, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(loadmodel))])
    }
    count_7 = int(uint64(int(uint(c2da_mem[l_8 + 4]) | uint(c2da_mem[l_8 + 5]) << 0x8 | uint(c2da_mem[l_8 + 6]) << 0x10 | uint(c2da_mem[l_8 + 7]) << 0x18)) / 20ul)
    out_7 = Hunk_AllocName(int(uint64(count_7 * 2) * 20ul), 386384)
    let c2da_fresh224 : uint = uint(out_7)
    c2da_mem[loadmodel + 144] = uint8(c2da_fresh224)
    c2da_mem[loadmodel + 145] = uint8(c2da_fresh224 >> 0x8)
    c2da_mem[loadmodel + 146] = uint8(c2da_fresh224 >> 0x10)
    c2da_mem[loadmodel + 147] = uint8(c2da_fresh224 >> 0x18)
    c2da_mem[loadmodel + 148] = 0u8
    c2da_mem[loadmodel + 149] = 0u8
    c2da_mem[loadmodel + 150] = 0u8
    c2da_mem[loadmodel + 151] = 0u8
    let c2da_fresh225 : uint = uint(count_7)
    c2da_mem[loadmodel + 136] = uint8(c2da_fresh225)
    c2da_mem[loadmodel + 137] = uint8(c2da_fresh225 >> 0x8)
    c2da_mem[loadmodel + 138] = uint8(c2da_fresh225 >> 0x10)
    c2da_mem[loadmodel + 139] = uint8(c2da_fresh225 >> 0x18)
    i_12 = 0
    while (i_12 < count_7) {
        bits = 0
        for (j_7 in range(0, 3)) {
            let c2da_fresh226 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[in_8 + j_7 * 4]) | uint(c2da_mem[in_8 + j_7 * 4 + 1]) << 0x8 | uint(c2da_mem[in_8 + j_7 * 4 + 2]) << 0x10 | uint(c2da_mem[in_8 + j_7 * 4 + 3]) << 0x18))
            let c2da_fresh227 : uint = float_bits_to_uint(c2da_fresh226)
            c2da_mem[out_7 + j_7 * 4] = uint8(c2da_fresh227)
            c2da_mem[out_7 + j_7 * 4 + 1] = uint8(c2da_fresh227 >> 0x8)
            c2da_mem[out_7 + j_7 * 4 + 2] = uint8(c2da_fresh227 >> 0x10)
            c2da_mem[out_7 + j_7 * 4 + 3] = uint8(c2da_fresh227 >> 0x18)
            if (c2da_fresh226 < 0.0) {
                bits |= 1 << j_7
            }
        }
        let c2da_fresh228 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[in_8 + 12]) | uint(c2da_mem[in_8 + 13]) << 0x8 | uint(c2da_mem[in_8 + 14]) << 0x10 | uint(c2da_mem[in_8 + 15]) << 0x18))
        let c2da_fresh229 : uint = float_bits_to_uint(c2da_fresh228)
        c2da_mem[out_7 + 12] = uint8(c2da_fresh229)
        c2da_mem[out_7 + 13] = uint8(c2da_fresh229 >> 0x8)
        c2da_mem[out_7 + 14] = uint8(c2da_fresh229 >> 0x10)
        c2da_mem[out_7 + 15] = uint8(c2da_fresh229 >> 0x18)
        let c2da_fresh230 : uint8 = uint8(invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[in_8 + 16]) | uint(c2da_mem[in_8 + 17]) << 0x8 | uint(c2da_mem[in_8 + 18]) << 0x10 | uint(c2da_mem[in_8 + 19]) << 0x18)))
        c2da_mem[out_7 + 16] = c2da_fresh230
        let c2da_fresh231 : uint8 = uint8(bits)
        c2da_mem[out_7 + 17] = c2da_fresh231
        i_12++
        in_8 += 20
        out_7 += 20
    }
    return
}
[export, sideeffects]
def Mod_LoadLighting(var l_9 : int) {
    if (int(uint(c2da_mem[l_9 + 4]) | uint(c2da_mem[l_9 + 5]) << 0x8 | uint(c2da_mem[l_9 + 6]) << 0x10 | uint(c2da_mem[l_9 + 7]) << 0x18) == 0) {
        let c2da_fresh232 : uint = 0u
        c2da_mem[loadmodel + 512] = uint8(c2da_fresh232)
        c2da_mem[loadmodel + 513] = uint8(c2da_fresh232 >> 0x8)
        c2da_mem[loadmodel + 514] = uint8(c2da_fresh232 >> 0x10)
        c2da_mem[loadmodel + 515] = uint8(c2da_fresh232 >> 0x18)
        c2da_mem[loadmodel + 516] = 0u8
        c2da_mem[loadmodel + 517] = 0u8
        c2da_mem[loadmodel + 518] = 0u8
        c2da_mem[loadmodel + 519] = 0u8
        return
    }
    let c2da_fresh233 : int = Hunk_AllocName(int(uint(c2da_mem[l_9 + 4]) | uint(c2da_mem[l_9 + 5]) << 0x8 | uint(c2da_mem[l_9 + 6]) << 0x10 | uint(c2da_mem[l_9 + 7]) << 0x18), 386384)
    let c2da_fresh234 : uint = uint(c2da_fresh233)
    c2da_mem[loadmodel + 512] = uint8(c2da_fresh234)
    c2da_mem[loadmodel + 513] = uint8(c2da_fresh234 >> 0x8)
    c2da_mem[loadmodel + 514] = uint8(c2da_fresh234 >> 0x10)
    c2da_mem[loadmodel + 515] = uint8(c2da_fresh234 >> 0x18)
    c2da_mem[loadmodel + 516] = 0u8
    c2da_mem[loadmodel + 517] = 0u8
    c2da_mem[loadmodel + 518] = 0u8
    c2da_mem[loadmodel + 519] = 0u8
    c2da_lin_memcpy(int(uint(c2da_mem[loadmodel + 512]) | uint(c2da_mem[loadmodel + 513]) << 0x8 | uint(c2da_mem[loadmodel + 514]) << 0x10 | uint(c2da_mem[loadmodel + 515]) << 0x18), mod_base + int(uint(c2da_mem[l_9]) | uint(c2da_mem[l_9 + 1]) << 0x8 | uint(c2da_mem[l_9 + 2]) << 0x10 | uint(c2da_mem[l_9 + 3]) << 0x18), uint64(int(uint(c2da_mem[l_9 + 4]) | uint(c2da_mem[l_9 + 5]) << 0x8 | uint(c2da_mem[l_9 + 6]) << 0x10 | uint(c2da_mem[l_9 + 7]) << 0x18)))
    return
}
[export, sideeffects]
def Mod_LoadTextures(var l_10 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    Mod_LoadTextures_c2da_frame(l_10, c2da_lin_enter(160))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Mod_LoadSurfedges(var l_11 : int) {
    var count_8 : int
    var in_9 : int
    var out_8 : int
    in_9 = mod_base + int(uint(c2da_mem[l_11]) | uint(c2da_mem[l_11 + 1]) << 0x8 | uint(c2da_mem[l_11 + 2]) << 0x10 | uint(c2da_mem[l_11 + 3]) << 0x18)
    if (uint64(int(uint(c2da_mem[l_11 + 4]) | uint(c2da_mem[l_11 + 5]) << 0x8 | uint(c2da_mem[l_11 + 6]) << 0x10 | uint(c2da_mem[l_11 + 7]) << 0x18)) % 4ul != 0x0) {
        Sys_Error(726168, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(loadmodel))])
    }
    count_8 = int(uint64(int(uint(c2da_mem[l_11 + 4]) | uint(c2da_mem[l_11 + 5]) << 0x8 | uint(c2da_mem[l_11 + 6]) << 0x10 | uint(c2da_mem[l_11 + 7]) << 0x18)) / 4ul)
    out_8 = Hunk_AllocName(int(uint64(count_8) * 4ul), 386384)
    let c2da_fresh286 : uint = uint(out_8)
    c2da_mem[loadmodel + 256] = uint8(c2da_fresh286)
    c2da_mem[loadmodel + 257] = uint8(c2da_fresh286 >> 0x8)
    c2da_mem[loadmodel + 258] = uint8(c2da_fresh286 >> 0x10)
    c2da_mem[loadmodel + 259] = uint8(c2da_fresh286 >> 0x18)
    c2da_mem[loadmodel + 260] = 0u8
    c2da_mem[loadmodel + 261] = 0u8
    c2da_mem[loadmodel + 262] = 0u8
    c2da_mem[loadmodel + 263] = 0u8
    let c2da_fresh287 : uint = uint(count_8)
    c2da_mem[loadmodel + 248] = uint8(c2da_fresh287)
    c2da_mem[loadmodel + 249] = uint8(c2da_fresh287 >> 0x8)
    c2da_mem[loadmodel + 250] = uint8(c2da_fresh287 >> 0x10)
    c2da_mem[loadmodel + 251] = uint8(c2da_fresh287 >> 0x18)
    for (i_14 in range(0, count_8)) {
        let c2da_fresh288 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[in_9 + i_14 * 4]) | uint(c2da_mem[in_9 + i_14 * 4 + 1]) << 0x8 | uint(c2da_mem[in_9 + i_14 * 4 + 2]) << 0x10 | uint(c2da_mem[in_9 + i_14 * 4 + 3]) << 0x18))
        let c2da_fresh289 : uint = uint(c2da_fresh288)
        c2da_mem[out_8 + i_14 * 4] = uint8(c2da_fresh289)
        c2da_mem[out_8 + i_14 * 4 + 1] = uint8(c2da_fresh289 >> 0x8)
        c2da_mem[out_8 + i_14 * 4 + 2] = uint8(c2da_fresh289 >> 0x10)
        c2da_mem[out_8 + i_14 * 4 + 3] = uint8(c2da_fresh289 >> 0x18)
    }
    return
}
[export, sideeffects]
def Mod_LoadEdges(var l_12 : int) {
    var in_10 : int
    var out_9 : int
    var i_15 : int
    var count_9 : int
    in_10 = mod_base + int(uint(c2da_mem[l_12]) | uint(c2da_mem[l_12 + 1]) << 0x8 | uint(c2da_mem[l_12 + 2]) << 0x10 | uint(c2da_mem[l_12 + 3]) << 0x18)
    if (uint64(int(uint(c2da_mem[l_12 + 4]) | uint(c2da_mem[l_12 + 5]) << 0x8 | uint(c2da_mem[l_12 + 6]) << 0x10 | uint(c2da_mem[l_12 + 7]) << 0x18)) % 4ul != 0x0) {
        Sys_Error(726168, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(loadmodel))])
    }
    count_9 = int(uint64(int(uint(c2da_mem[l_12 + 4]) | uint(c2da_mem[l_12 + 5]) << 0x8 | uint(c2da_mem[l_12 + 6]) << 0x10 | uint(c2da_mem[l_12 + 7]) << 0x18)) / 4ul)
    out_9 = Hunk_AllocName(int(uint64(count_9 + 1) * 8ul), 386384)
    let c2da_fresh290 : uint = uint(out_9)
    c2da_mem[loadmodel + 192] = uint8(c2da_fresh290)
    c2da_mem[loadmodel + 193] = uint8(c2da_fresh290 >> 0x8)
    c2da_mem[loadmodel + 194] = uint8(c2da_fresh290 >> 0x10)
    c2da_mem[loadmodel + 195] = uint8(c2da_fresh290 >> 0x18)
    c2da_mem[loadmodel + 196] = 0u8
    c2da_mem[loadmodel + 197] = 0u8
    c2da_mem[loadmodel + 198] = 0u8
    c2da_mem[loadmodel + 199] = 0u8
    let c2da_fresh291 : uint = uint(count_9)
    c2da_mem[loadmodel + 184] = uint8(c2da_fresh291)
    c2da_mem[loadmodel + 185] = uint8(c2da_fresh291 >> 0x8)
    c2da_mem[loadmodel + 186] = uint8(c2da_fresh291 >> 0x10)
    c2da_mem[loadmodel + 187] = uint8(c2da_fresh291 >> 0x18)
    i_15 = 0
    while (i_15 < count_9) {
        let c2da_fresh292 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(uint16(uint(c2da_mem[in_10 + 0 * 2]) | uint(c2da_mem[in_10 + 0 * 2 + 1]) << 0x8))))
        let c2da_fresh293 : uint = uint(c2da_fresh292)
        c2da_mem[out_9 + 0 * 2] = uint8(c2da_fresh293)
        c2da_mem[out_9 + 0 * 2 + 1] = uint8(c2da_fresh293 >> 0x8)
        let c2da_fresh294 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(uint16(uint(c2da_mem[in_10 + 1 * 2]) | uint(c2da_mem[in_10 + 1 * 2 + 1]) << 0x8))))
        let c2da_fresh295 : uint = uint(c2da_fresh294)
        c2da_mem[out_9 + 1 * 2] = uint8(c2da_fresh295)
        c2da_mem[out_9 + 1 * 2 + 1] = uint8(c2da_fresh295 >> 0x8)
        i_15++
        in_10 += 4
        out_9 += 8
    }
    return
}
[export, sideeffects]
def Mod_LoadVertexes(var l_13 : int) {
    var in_11 : int
    var out_10 : int
    var i_16 : int
    var count_10 : int
    in_11 = mod_base + int(uint(c2da_mem[l_13]) | uint(c2da_mem[l_13 + 1]) << 0x8 | uint(c2da_mem[l_13 + 2]) << 0x10 | uint(c2da_mem[l_13 + 3]) << 0x18)
    if (uint64(int(uint(c2da_mem[l_13 + 4]) | uint(c2da_mem[l_13 + 5]) << 0x8 | uint(c2da_mem[l_13 + 6]) << 0x10 | uint(c2da_mem[l_13 + 7]) << 0x18)) % 12ul != 0x0) {
        Sys_Error(726168, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(loadmodel))])
    }
    count_10 = int(uint64(int(uint(c2da_mem[l_13 + 4]) | uint(c2da_mem[l_13 + 5]) << 0x8 | uint(c2da_mem[l_13 + 6]) << 0x10 | uint(c2da_mem[l_13 + 7]) << 0x18)) / 12ul)
    out_10 = Hunk_AllocName(int(uint64(count_10) * 12ul), 386384)
    let c2da_fresh296 : uint = uint(out_10)
    c2da_mem[loadmodel + 176] = uint8(c2da_fresh296)
    c2da_mem[loadmodel + 177] = uint8(c2da_fresh296 >> 0x8)
    c2da_mem[loadmodel + 178] = uint8(c2da_fresh296 >> 0x10)
    c2da_mem[loadmodel + 179] = uint8(c2da_fresh296 >> 0x18)
    c2da_mem[loadmodel + 180] = 0u8
    c2da_mem[loadmodel + 181] = 0u8
    c2da_mem[loadmodel + 182] = 0u8
    c2da_mem[loadmodel + 183] = 0u8
    let c2da_fresh297 : uint = uint(count_10)
    c2da_mem[loadmodel + 168] = uint8(c2da_fresh297)
    c2da_mem[loadmodel + 169] = uint8(c2da_fresh297 >> 0x8)
    c2da_mem[loadmodel + 170] = uint8(c2da_fresh297 >> 0x10)
    c2da_mem[loadmodel + 171] = uint8(c2da_fresh297 >> 0x18)
    i_16 = 0
    while (i_16 < count_10) {
        let c2da_fresh298 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[in_11 + 0 * 4]) | uint(c2da_mem[in_11 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in_11 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in_11 + 0 * 4 + 3]) << 0x18))
        let c2da_fresh299 : uint = float_bits_to_uint(c2da_fresh298)
        c2da_mem[out_10 + 0 * 4] = uint8(c2da_fresh299)
        c2da_mem[out_10 + 0 * 4 + 1] = uint8(c2da_fresh299 >> 0x8)
        c2da_mem[out_10 + 0 * 4 + 2] = uint8(c2da_fresh299 >> 0x10)
        c2da_mem[out_10 + 0 * 4 + 3] = uint8(c2da_fresh299 >> 0x18)
        let c2da_fresh300 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[in_11 + 1 * 4]) | uint(c2da_mem[in_11 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in_11 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in_11 + 1 * 4 + 3]) << 0x18))
        let c2da_fresh301 : uint = float_bits_to_uint(c2da_fresh300)
        c2da_mem[out_10 + 1 * 4] = uint8(c2da_fresh301)
        c2da_mem[out_10 + 1 * 4 + 1] = uint8(c2da_fresh301 >> 0x8)
        c2da_mem[out_10 + 1 * 4 + 2] = uint8(c2da_fresh301 >> 0x10)
        c2da_mem[out_10 + 1 * 4 + 3] = uint8(c2da_fresh301 >> 0x18)
        let c2da_fresh302 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[in_11 + 2 * 4]) | uint(c2da_mem[in_11 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in_11 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in_11 + 2 * 4 + 3]) << 0x18))
        let c2da_fresh303 : uint = float_bits_to_uint(c2da_fresh302)
        c2da_mem[out_10 + 2 * 4] = uint8(c2da_fresh303)
        c2da_mem[out_10 + 2 * 4 + 1] = uint8(c2da_fresh303 >> 0x8)
        c2da_mem[out_10 + 2 * 4 + 2] = uint8(c2da_fresh303 >> 0x10)
        c2da_mem[out_10 + 2 * 4 + 3] = uint8(c2da_fresh303 >> 0x18)
        i_16++
        in_11 += 12
        out_10 += 12
    }
    return
}
[export, sideeffects]
def Mod_LoadSpriteModel(var mod_4 : int; var buffer_0 : int) {
    var version : int
    var pin : int
    var psprite : int
    var numframes : int
    var pframetype : int
    var frametype : uint
    pin = buffer_0
    version = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pin + 4]) | uint(c2da_mem[pin + 5]) << 0x8 | uint(c2da_mem[pin + 6]) << 0x10 | uint(c2da_mem[pin + 7]) << 0x18))
    if (version != 1) {
        Sys_Error(726384, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(mod_4)), C2daVaArg(tag = 1, i64 = int64(version), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = 1l, f64 = 0.0lf, raw = 0x0)])
    }
    numframes = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pin + 24]) | uint(c2da_mem[pin + 25]) << 0x8 | uint(c2da_mem[pin + 26]) << 0x10 | uint(c2da_mem[pin + 27]) << 0x18))
    psprite = Hunk_AllocName(int(48ul + uint64(numframes - 1) * 16ul), 386384)
    let c2da_fresh304 : uint = uint(psprite)
    c2da_mem[mod_4 + 528] = uint8(c2da_fresh304)
    c2da_mem[mod_4 + 529] = uint8(c2da_fresh304 >> 0x8)
    c2da_mem[mod_4 + 530] = uint8(c2da_fresh304 >> 0x10)
    c2da_mem[mod_4 + 531] = uint8(c2da_fresh304 >> 0x18)
    c2da_mem[mod_4 + 532] = 0u8
    c2da_mem[mod_4 + 533] = 0u8
    c2da_mem[mod_4 + 534] = 0u8
    c2da_mem[mod_4 + 535] = 0u8
    let c2da_fresh305 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pin + 8]) | uint(c2da_mem[pin + 9]) << 0x8 | uint(c2da_mem[pin + 10]) << 0x10 | uint(c2da_mem[pin + 11]) << 0x18))
    let c2da_fresh306 : uint = uint(c2da_fresh305)
    c2da_mem[psprite] = uint8(c2da_fresh306)
    c2da_mem[psprite + 1] = uint8(c2da_fresh306 >> 0x8)
    c2da_mem[psprite + 2] = uint8(c2da_fresh306 >> 0x10)
    c2da_mem[psprite + 3] = uint8(c2da_fresh306 >> 0x18)
    let c2da_fresh307 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pin + 16]) | uint(c2da_mem[pin + 17]) << 0x8 | uint(c2da_mem[pin + 18]) << 0x10 | uint(c2da_mem[pin + 19]) << 0x18))
    let c2da_fresh308 : uint = uint(c2da_fresh307)
    c2da_mem[psprite + 4] = uint8(c2da_fresh308)
    c2da_mem[psprite + 5] = uint8(c2da_fresh308 >> 0x8)
    c2da_mem[psprite + 6] = uint8(c2da_fresh308 >> 0x10)
    c2da_mem[psprite + 7] = uint8(c2da_fresh308 >> 0x18)
    let c2da_fresh309 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pin + 20]) | uint(c2da_mem[pin + 21]) << 0x8 | uint(c2da_mem[pin + 22]) << 0x10 | uint(c2da_mem[pin + 23]) << 0x18))
    let c2da_fresh310 : uint = uint(c2da_fresh309)
    c2da_mem[psprite + 8] = uint8(c2da_fresh310)
    c2da_mem[psprite + 9] = uint8(c2da_fresh310 >> 0x8)
    c2da_mem[psprite + 10] = uint8(c2da_fresh310 >> 0x10)
    c2da_mem[psprite + 11] = uint8(c2da_fresh310 >> 0x18)
    let c2da_fresh311 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[pin + 28]) | uint(c2da_mem[pin + 29]) << 0x8 | uint(c2da_mem[pin + 30]) << 0x10 | uint(c2da_mem[pin + 31]) << 0x18))
    let c2da_fresh312 : uint = float_bits_to_uint(c2da_fresh311)
    c2da_mem[psprite + 16] = uint8(c2da_fresh312)
    c2da_mem[psprite + 17] = uint8(c2da_fresh312 >> 0x8)
    c2da_mem[psprite + 18] = uint8(c2da_fresh312 >> 0x10)
    c2da_mem[psprite + 19] = uint8(c2da_fresh312 >> 0x18)
    let c2da_fresh313 : uint = uint(invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pin + 32]) | uint(c2da_mem[pin + 33]) << 0x8 | uint(c2da_mem[pin + 34]) << 0x10 | uint(c2da_mem[pin + 35]) << 0x18)))
    let c2da_fresh314 : uint = c2da_fresh313
    c2da_mem[mod_4 + 76] = uint8(c2da_fresh314)
    c2da_mem[mod_4 + 77] = uint8(c2da_fresh314 >> 0x8)
    c2da_mem[mod_4 + 78] = uint8(c2da_fresh314 >> 0x10)
    c2da_mem[mod_4 + 79] = uint8(c2da_fresh314 >> 0x18)
    let c2da_fresh315 : uint = uint(numframes)
    c2da_mem[psprite + 12] = uint8(c2da_fresh315)
    c2da_mem[psprite + 13] = uint8(c2da_fresh315 >> 0x8)
    c2da_mem[psprite + 14] = uint8(c2da_fresh315 >> 0x10)
    c2da_mem[psprite + 15] = uint8(c2da_fresh315 >> 0x18)
    let c2da_fresh316 : float = float(-int(uint(c2da_mem[psprite + 4]) | uint(c2da_mem[psprite + 5]) << 0x8 | uint(c2da_mem[psprite + 6]) << 0x10 | uint(c2da_mem[psprite + 7]) << 0x18) / 2)
    let c2da_fresh317 : uint = float_bits_to_uint(c2da_fresh316)
    c2da_mem[mod_4 + 84 + 1 * 4] = uint8(c2da_fresh317)
    c2da_mem[mod_4 + 84 + 1 * 4 + 1] = uint8(c2da_fresh317 >> 0x8)
    c2da_mem[mod_4 + 84 + 1 * 4 + 2] = uint8(c2da_fresh317 >> 0x10)
    c2da_mem[mod_4 + 84 + 1 * 4 + 3] = uint8(c2da_fresh317 >> 0x18)
    let c2da_fresh318 : uint = float_bits_to_uint(c2da_fresh316)
    c2da_mem[mod_4 + 84 + 0 * 4] = uint8(c2da_fresh318)
    c2da_mem[mod_4 + 84 + 0 * 4 + 1] = uint8(c2da_fresh318 >> 0x8)
    c2da_mem[mod_4 + 84 + 0 * 4 + 2] = uint8(c2da_fresh318 >> 0x10)
    c2da_mem[mod_4 + 84 + 0 * 4 + 3] = uint8(c2da_fresh318 >> 0x18)
    let c2da_fresh319 : float = float(int(uint(c2da_mem[psprite + 4]) | uint(c2da_mem[psprite + 5]) << 0x8 | uint(c2da_mem[psprite + 6]) << 0x10 | uint(c2da_mem[psprite + 7]) << 0x18) / 2)
    let c2da_fresh320 : uint = float_bits_to_uint(c2da_fresh319)
    c2da_mem[mod_4 + 96 + 1 * 4] = uint8(c2da_fresh320)
    c2da_mem[mod_4 + 96 + 1 * 4 + 1] = uint8(c2da_fresh320 >> 0x8)
    c2da_mem[mod_4 + 96 + 1 * 4 + 2] = uint8(c2da_fresh320 >> 0x10)
    c2da_mem[mod_4 + 96 + 1 * 4 + 3] = uint8(c2da_fresh320 >> 0x18)
    let c2da_fresh321 : uint = float_bits_to_uint(c2da_fresh319)
    c2da_mem[mod_4 + 96 + 0 * 4] = uint8(c2da_fresh321)
    c2da_mem[mod_4 + 96 + 0 * 4 + 1] = uint8(c2da_fresh321 >> 0x8)
    c2da_mem[mod_4 + 96 + 0 * 4 + 2] = uint8(c2da_fresh321 >> 0x10)
    c2da_mem[mod_4 + 96 + 0 * 4 + 3] = uint8(c2da_fresh321 >> 0x18)
    let c2da_fresh322 : float = float(-int(uint(c2da_mem[psprite + 8]) | uint(c2da_mem[psprite + 9]) << 0x8 | uint(c2da_mem[psprite + 10]) << 0x10 | uint(c2da_mem[psprite + 11]) << 0x18) / 2)
    let c2da_fresh323 : uint = float_bits_to_uint(c2da_fresh322)
    c2da_mem[mod_4 + 84 + 2 * 4] = uint8(c2da_fresh323)
    c2da_mem[mod_4 + 84 + 2 * 4 + 1] = uint8(c2da_fresh323 >> 0x8)
    c2da_mem[mod_4 + 84 + 2 * 4 + 2] = uint8(c2da_fresh323 >> 0x10)
    c2da_mem[mod_4 + 84 + 2 * 4 + 3] = uint8(c2da_fresh323 >> 0x18)
    let c2da_fresh324 : float = float(int(uint(c2da_mem[psprite + 8]) | uint(c2da_mem[psprite + 9]) << 0x8 | uint(c2da_mem[psprite + 10]) << 0x10 | uint(c2da_mem[psprite + 11]) << 0x18) / 2)
    let c2da_fresh325 : uint = float_bits_to_uint(c2da_fresh324)
    c2da_mem[mod_4 + 96 + 2 * 4] = uint8(c2da_fresh325)
    c2da_mem[mod_4 + 96 + 2 * 4 + 1] = uint8(c2da_fresh325 >> 0x8)
    c2da_mem[mod_4 + 96 + 2 * 4 + 2] = uint8(c2da_fresh325 >> 0x10)
    c2da_mem[mod_4 + 96 + 2 * 4 + 3] = uint8(c2da_fresh325 >> 0x18)
    if (numframes < 1) {
        Sys_Error(726430, [C2daVaArg(tag = 1, i64 = int64(numframes), f64 = 0.0lf, raw = 0x0)])
    }
    let c2da_fresh326 : uint = uint(numframes)
    c2da_mem[mod_4 + 72] = uint8(c2da_fresh326)
    c2da_mem[mod_4 + 73] = uint8(c2da_fresh326 >> 0x8)
    c2da_mem[mod_4 + 74] = uint8(c2da_fresh326 >> 0x10)
    c2da_mem[mod_4 + 75] = uint8(c2da_fresh326 >> 0x18)
    let c2da_fresh327 : int = 0
    let c2da_fresh328 : uint = uint(c2da_fresh327)
    c2da_mem[mod_4 + 80] = uint8(c2da_fresh328)
    c2da_mem[mod_4 + 81] = uint8(c2da_fresh328 >> 0x8)
    c2da_mem[mod_4 + 82] = uint8(c2da_fresh328 >> 0x10)
    c2da_mem[mod_4 + 83] = uint8(c2da_fresh328 >> 0x18)
    pframetype = pin + 1 * 36
    for (i_17 in range(0, numframes)) {
        frametype = uint(invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pframetype]) | uint(c2da_mem[pframetype + 1]) << 0x8 | uint(c2da_mem[pframetype + 2]) << 0x10 | uint(c2da_mem[pframetype + 3]) << 0x18)))
        let c2da_fresh329 : uint = frametype
        c2da_mem[psprite + 32 + i_17 * 16] = uint8(c2da_fresh329)
        c2da_mem[psprite + 32 + i_17 * 16 + 1] = uint8(c2da_fresh329 >> 0x8)
        c2da_mem[psprite + 32 + i_17 * 16 + 2] = uint8(c2da_fresh329 >> 0x10)
        c2da_mem[psprite + 32 + i_17 * 16 + 3] = uint8(c2da_fresh329 >> 0x18)
        if (frametype == 0u) {
            pframetype = Mod_LoadSpriteFrame(pframetype + 1 * 4, psprite + 32 + i_17 * 16 + 8)
        } else {
            pframetype = Mod_LoadSpriteGroup(pframetype + 1 * 4, psprite + 32 + i_17 * 16 + 8)
        }
    }
    let c2da_fresh330 : uint = 1u
    let c2da_fresh331 : uint = c2da_fresh330
    c2da_mem[mod_4 + 68] = uint8(c2da_fresh331)
    c2da_mem[mod_4 + 69] = uint8(c2da_fresh331 >> 0x8)
    c2da_mem[mod_4 + 70] = uint8(c2da_fresh331 >> 0x10)
    c2da_mem[mod_4 + 71] = uint8(c2da_fresh331 >> 0x18)
    return
}
[export, sideeffects]
def Mod_LoadSpriteGroup(var pin_0 : int; var ppframe : int) : int {
    var pingroup : int
    var pspritegroup : int
    var i_18 : int
    var numframes_0 : int
    var pin_intervals : int
    var poutintervals : int
    var ptemp : int
    pingroup = pin_0
    numframes_0 = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pingroup]) | uint(c2da_mem[pingroup + 1]) << 0x8 | uint(c2da_mem[pingroup + 2]) << 0x10 | uint(c2da_mem[pingroup + 3]) << 0x18))
    pspritegroup = Hunk_AllocName(int(24ul + uint64(numframes_0 - 1) * 8ul), 386384)
    let c2da_fresh332 : uint = uint(numframes_0)
    c2da_mem[pspritegroup] = uint8(c2da_fresh332)
    c2da_mem[pspritegroup + 1] = uint8(c2da_fresh332 >> 0x8)
    c2da_mem[pspritegroup + 2] = uint8(c2da_fresh332 >> 0x10)
    c2da_mem[pspritegroup + 3] = uint8(c2da_fresh332 >> 0x18)
    let c2da_fresh333 : uint = uint(pspritegroup)
    c2da_mem[ppframe] = uint8(c2da_fresh333)
    c2da_mem[ppframe + 1] = uint8(c2da_fresh333 >> 0x8)
    c2da_mem[ppframe + 2] = uint8(c2da_fresh333 >> 0x10)
    c2da_mem[ppframe + 3] = uint8(c2da_fresh333 >> 0x18)
    c2da_mem[ppframe + 4] = 0u8
    c2da_mem[ppframe + 5] = 0u8
    c2da_mem[ppframe + 6] = 0u8
    c2da_mem[ppframe + 7] = 0u8
    pin_intervals = pingroup + 1 * 4
    poutintervals = Hunk_AllocName(int(uint64(numframes_0) * 4ul), 386384)
    let c2da_fresh334 : uint = uint(poutintervals)
    c2da_mem[pspritegroup + 8] = uint8(c2da_fresh334)
    c2da_mem[pspritegroup + 9] = uint8(c2da_fresh334 >> 0x8)
    c2da_mem[pspritegroup + 10] = uint8(c2da_fresh334 >> 0x10)
    c2da_mem[pspritegroup + 11] = uint8(c2da_fresh334 >> 0x18)
    c2da_mem[pspritegroup + 12] = 0u8
    c2da_mem[pspritegroup + 13] = 0u8
    c2da_mem[pspritegroup + 14] = 0u8
    c2da_mem[pspritegroup + 15] = 0u8
    i_18 = 0
    while (i_18 < numframes_0) {
        let c2da_fresh335 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[pin_intervals]) | uint(c2da_mem[pin_intervals + 1]) << 0x8 | uint(c2da_mem[pin_intervals + 2]) << 0x10 | uint(c2da_mem[pin_intervals + 3]) << 0x18))
        let c2da_fresh336 : uint = float_bits_to_uint(c2da_fresh335)
        c2da_mem[poutintervals] = uint8(c2da_fresh336)
        c2da_mem[poutintervals + 1] = uint8(c2da_fresh336 >> 0x8)
        c2da_mem[poutintervals + 2] = uint8(c2da_fresh336 >> 0x10)
        c2da_mem[poutintervals + 3] = uint8(c2da_fresh336 >> 0x18)
        if (double(c2da_fresh335) <= 0.0lf) {
            Sys_Error(726476, [])
        }
        poutintervals += 4
        pin_intervals += 4
        i_18++
    }
    ptemp = pin_intervals
    i_18 = 0
    for (c2da_i_18 in range(i_18, numframes_0)) {
        ptemp = Mod_LoadSpriteFrame(ptemp, pspritegroup + 16 + c2da_i_18 * 8)
    }
    return ptemp
}
[export, sideeffects]
def Mod_LoadSpriteFrame(var pin_1 : int; var ppframe_0 : int) : int {
    var pinframe : int
    var pspriteframe : int
    var i_19 : int
    var width : int
    var height : int
    var size_0 : int
    var origin_0 : int[2]
    var ppixout : int
    var ppixin : int
    pinframe = pin_1
    width = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinframe + 8]) | uint(c2da_mem[pinframe + 9]) << 0x8 | uint(c2da_mem[pinframe + 10]) << 0x10 | uint(c2da_mem[pinframe + 11]) << 0x18))
    height = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinframe + 12]) | uint(c2da_mem[pinframe + 13]) << 0x8 | uint(c2da_mem[pinframe + 14]) << 0x10 | uint(c2da_mem[pinframe + 15]) << 0x18))
    size_0 = width * height
    pspriteframe = Hunk_AllocName(int(40ul + uint64(size_0)), 386384)
    Q_memset(pspriteframe, 0, int(40ul + uint64(size_0)))
    let c2da_fresh337 : uint = uint(pspriteframe)
    c2da_mem[ppframe_0] = uint8(c2da_fresh337)
    c2da_mem[ppframe_0 + 1] = uint8(c2da_fresh337 >> 0x8)
    c2da_mem[ppframe_0 + 2] = uint8(c2da_fresh337 >> 0x10)
    c2da_mem[ppframe_0 + 3] = uint8(c2da_fresh337 >> 0x18)
    c2da_mem[ppframe_0 + 4] = 0u8
    c2da_mem[ppframe_0 + 5] = 0u8
    c2da_mem[ppframe_0 + 6] = 0u8
    c2da_mem[ppframe_0 + 7] = 0u8
    let c2da_fresh338 : uint = uint(width)
    c2da_mem[pspriteframe] = uint8(c2da_fresh338)
    c2da_mem[pspriteframe + 1] = uint8(c2da_fresh338 >> 0x8)
    c2da_mem[pspriteframe + 2] = uint8(c2da_fresh338 >> 0x10)
    c2da_mem[pspriteframe + 3] = uint8(c2da_fresh338 >> 0x18)
    let c2da_fresh339 : uint = uint(height)
    c2da_mem[pspriteframe + 4] = uint8(c2da_fresh339)
    c2da_mem[pspriteframe + 5] = uint8(c2da_fresh339 >> 0x8)
    c2da_mem[pspriteframe + 6] = uint8(c2da_fresh339 >> 0x10)
    c2da_mem[pspriteframe + 7] = uint8(c2da_fresh339 >> 0x18)
    origin_0[0] = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinframe + 0 * 4]) | uint(c2da_mem[pinframe + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pinframe + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pinframe + 0 * 4 + 3]) << 0x18))
    origin_0[1] = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinframe + 1 * 4]) | uint(c2da_mem[pinframe + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pinframe + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pinframe + 1 * 4 + 3]) << 0x18))
    let c2da_fresh340 : float = float(origin_0[1])
    let c2da_fresh341 : uint = float_bits_to_uint(c2da_fresh340)
    c2da_mem[pspriteframe + 16] = uint8(c2da_fresh341)
    c2da_mem[pspriteframe + 17] = uint8(c2da_fresh341 >> 0x8)
    c2da_mem[pspriteframe + 18] = uint8(c2da_fresh341 >> 0x10)
    c2da_mem[pspriteframe + 19] = uint8(c2da_fresh341 >> 0x18)
    let c2da_fresh342 : float = float(origin_0[1] - height)
    let c2da_fresh343 : uint = float_bits_to_uint(c2da_fresh342)
    c2da_mem[pspriteframe + 20] = uint8(c2da_fresh343)
    c2da_mem[pspriteframe + 21] = uint8(c2da_fresh343 >> 0x8)
    c2da_mem[pspriteframe + 22] = uint8(c2da_fresh343 >> 0x10)
    c2da_mem[pspriteframe + 23] = uint8(c2da_fresh343 >> 0x18)
    let c2da_fresh344 : float = float(origin_0[0])
    let c2da_fresh345 : uint = float_bits_to_uint(c2da_fresh344)
    c2da_mem[pspriteframe + 24] = uint8(c2da_fresh345)
    c2da_mem[pspriteframe + 25] = uint8(c2da_fresh345 >> 0x8)
    c2da_mem[pspriteframe + 26] = uint8(c2da_fresh345 >> 0x10)
    c2da_mem[pspriteframe + 27] = uint8(c2da_fresh345 >> 0x18)
    let c2da_fresh346 : float = float(width + origin_0[0])
    let c2da_fresh347 : uint = float_bits_to_uint(c2da_fresh346)
    c2da_mem[pspriteframe + 28] = uint8(c2da_fresh347)
    c2da_mem[pspriteframe + 29] = uint8(c2da_fresh347 >> 0x8)
    c2da_mem[pspriteframe + 30] = uint8(c2da_fresh347 >> 0x10)
    c2da_mem[pspriteframe + 31] = uint8(c2da_fresh347 >> 0x18)
    Q_memcpy(pspriteframe + 32 + 0, pinframe + 1 * 16, size_0)
    return pinframe + 16 + size_0
}
[export, sideeffects]
def Mod_LoadAliasModel(var mod_5 : int; var buffer_1 : int) {
    var i_20 : int
    var pmodel : int
    var pinmodel : int
    var pstverts : int
    var pinstverts : int
    var pheader : int
    var ptri : int
    var pintriangles : int
    var version_0 : int
    var numframes_1 : int
    var numskins : int
    var size_1 : int
    var pframetype_0 : int
    var pskintype : int
    var pskindesc : int
    var skinsize : int
    var start : int
    var end : int
    var total : int
    var skintype : uint
    var frametype_0 : uint
    start = Hunk_LowMark()
    pinmodel = buffer_1
    version_0 = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinmodel + 4]) | uint(c2da_mem[pinmodel + 5]) << 0x8 | uint(c2da_mem[pinmodel + 6]) << 0x10 | uint(c2da_mem[pinmodel + 7]) << 0x18))
    if (version_0 != 6) {
        Sys_Error(726384, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(mod_5)), C2daVaArg(tag = 1, i64 = int64(version_0), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = 6l, f64 = 0.0lf, raw = 0x0)])
    }
    size_1 = int(48ul + uint64(invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinmodel + 68]) | uint(c2da_mem[pinmodel + 69]) << 0x8 | uint(c2da_mem[pinmodel + 70]) << 0x10 | uint(c2da_mem[pinmodel + 71]) << 0x18)) - 1) * 32ul + 84ul + uint64(invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinmodel + 60]) | uint(c2da_mem[pinmodel + 61]) << 0x8 | uint(c2da_mem[pinmodel + 62]) << 0x10 | uint(c2da_mem[pinmodel + 63]) << 0x18))) * 12ul + uint64(invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinmodel + 64]) | uint(c2da_mem[pinmodel + 65]) << 0x8 | uint(c2da_mem[pinmodel + 66]) << 0x10 | uint(c2da_mem[pinmodel + 67]) << 0x18))) * 16ul)
    pheader = Hunk_AllocName(size_1, 386384)
    pmodel = pheader + 1 * 48 + int(uint64(invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinmodel + 68]) | uint(c2da_mem[pinmodel + 69]) << 0x8 | uint(c2da_mem[pinmodel + 70]) << 0x10 | uint(c2da_mem[pinmodel + 71]) << 0x18)) - 1) * 32ul)
    let c2da_fresh348 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinmodel + 76]) | uint(c2da_mem[pinmodel + 77]) << 0x8 | uint(c2da_mem[pinmodel + 78]) << 0x10 | uint(c2da_mem[pinmodel + 79]) << 0x18))
    let c2da_fresh349 : uint = uint(c2da_fresh348)
    c2da_mem[mod_5 + 80] = uint8(c2da_fresh349)
    c2da_mem[mod_5 + 81] = uint8(c2da_fresh349 >> 0x8)
    c2da_mem[mod_5 + 82] = uint8(c2da_fresh349 >> 0x10)
    c2da_mem[mod_5 + 83] = uint8(c2da_fresh349 >> 0x18)
    let c2da_fresh350 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[pinmodel + 32]) | uint(c2da_mem[pinmodel + 33]) << 0x8 | uint(c2da_mem[pinmodel + 34]) << 0x10 | uint(c2da_mem[pinmodel + 35]) << 0x18))
    let c2da_fresh351 : uint = float_bits_to_uint(c2da_fresh350)
    c2da_mem[pmodel + 32] = uint8(c2da_fresh351)
    c2da_mem[pmodel + 33] = uint8(c2da_fresh351 >> 0x8)
    c2da_mem[pmodel + 34] = uint8(c2da_fresh351 >> 0x10)
    c2da_mem[pmodel + 35] = uint8(c2da_fresh351 >> 0x18)
    let c2da_fresh352 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinmodel + 48]) | uint(c2da_mem[pinmodel + 49]) << 0x8 | uint(c2da_mem[pinmodel + 50]) << 0x10 | uint(c2da_mem[pinmodel + 51]) << 0x18))
    let c2da_fresh353 : uint = uint(c2da_fresh352)
    c2da_mem[pmodel + 48] = uint8(c2da_fresh353)
    c2da_mem[pmodel + 49] = uint8(c2da_fresh353 >> 0x8)
    c2da_mem[pmodel + 50] = uint8(c2da_fresh353 >> 0x10)
    c2da_mem[pmodel + 51] = uint8(c2da_fresh353 >> 0x18)
    let c2da_fresh354 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinmodel + 52]) | uint(c2da_mem[pinmodel + 53]) << 0x8 | uint(c2da_mem[pinmodel + 54]) << 0x10 | uint(c2da_mem[pinmodel + 55]) << 0x18))
    let c2da_fresh355 : uint = uint(c2da_fresh354)
    c2da_mem[pmodel + 52] = uint8(c2da_fresh355)
    c2da_mem[pmodel + 53] = uint8(c2da_fresh355 >> 0x8)
    c2da_mem[pmodel + 54] = uint8(c2da_fresh355 >> 0x10)
    c2da_mem[pmodel + 55] = uint8(c2da_fresh355 >> 0x18)
    let c2da_fresh356 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinmodel + 56]) | uint(c2da_mem[pinmodel + 57]) << 0x8 | uint(c2da_mem[pinmodel + 58]) << 0x10 | uint(c2da_mem[pinmodel + 59]) << 0x18))
    let c2da_fresh357 : uint = uint(c2da_fresh356)
    c2da_mem[pmodel + 56] = uint8(c2da_fresh357)
    c2da_mem[pmodel + 57] = uint8(c2da_fresh357 >> 0x8)
    c2da_mem[pmodel + 58] = uint8(c2da_fresh357 >> 0x10)
    c2da_mem[pmodel + 59] = uint8(c2da_fresh357 >> 0x18)
    if (int(uint(c2da_mem[pmodel + 56]) | uint(c2da_mem[pmodel + 57]) << 0x8 | uint(c2da_mem[pmodel + 58]) << 0x10 | uint(c2da_mem[pmodel + 59]) << 0x18) > 480) {
        Sys_Error(726509, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(mod_5)), C2daVaArg(tag = 1, i64 = 480l, f64 = 0.0lf, raw = 0x0)])
    }
    let c2da_fresh358 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinmodel + 60]) | uint(c2da_mem[pinmodel + 61]) << 0x8 | uint(c2da_mem[pinmodel + 62]) << 0x10 | uint(c2da_mem[pinmodel + 63]) << 0x18))
    let c2da_fresh359 : uint = uint(c2da_fresh358)
    c2da_mem[pmodel + 60] = uint8(c2da_fresh359)
    c2da_mem[pmodel + 61] = uint8(c2da_fresh359 >> 0x8)
    c2da_mem[pmodel + 62] = uint8(c2da_fresh359 >> 0x10)
    c2da_mem[pmodel + 63] = uint8(c2da_fresh359 >> 0x18)
    if (int(uint(c2da_mem[pmodel + 60]) | uint(c2da_mem[pmodel + 61]) << 0x8 | uint(c2da_mem[pmodel + 62]) << 0x10 | uint(c2da_mem[pmodel + 63]) << 0x18) <= 0) {
        Sys_Error(726544, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(mod_5))])
    }
    if (int(uint(c2da_mem[pmodel + 60]) | uint(c2da_mem[pmodel + 61]) << 0x8 | uint(c2da_mem[pmodel + 62]) << 0x10 | uint(c2da_mem[pmodel + 63]) << 0x18) > 2000) {
        Sys_Error(726569, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(mod_5))])
    }
    let c2da_fresh360 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinmodel + 64]) | uint(c2da_mem[pinmodel + 65]) << 0x8 | uint(c2da_mem[pinmodel + 66]) << 0x10 | uint(c2da_mem[pinmodel + 67]) << 0x18))
    let c2da_fresh361 : uint = uint(c2da_fresh360)
    c2da_mem[pmodel + 64] = uint8(c2da_fresh361)
    c2da_mem[pmodel + 65] = uint8(c2da_fresh361 >> 0x8)
    c2da_mem[pmodel + 66] = uint8(c2da_fresh361 >> 0x10)
    c2da_mem[pmodel + 67] = uint8(c2da_fresh361 >> 0x18)
    if (int(uint(c2da_mem[pmodel + 64]) | uint(c2da_mem[pmodel + 65]) << 0x8 | uint(c2da_mem[pmodel + 66]) << 0x10 | uint(c2da_mem[pmodel + 67]) << 0x18) <= 0) {
        Sys_Error(726600, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(mod_5))])
    }
    let c2da_fresh362 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinmodel + 68]) | uint(c2da_mem[pinmodel + 69]) << 0x8 | uint(c2da_mem[pinmodel + 70]) << 0x10 | uint(c2da_mem[pinmodel + 71]) << 0x18))
    let c2da_fresh363 : uint = uint(c2da_fresh362)
    c2da_mem[pmodel + 68] = uint8(c2da_fresh363)
    c2da_mem[pmodel + 69] = uint8(c2da_fresh363 >> 0x8)
    c2da_mem[pmodel + 70] = uint8(c2da_fresh363 >> 0x10)
    c2da_mem[pmodel + 71] = uint8(c2da_fresh363 >> 0x18)
    let c2da_fresh364 : float = float(double(invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[pinmodel + 80]) | uint(c2da_mem[pinmodel + 81]) << 0x8 | uint(c2da_mem[pinmodel + 82]) << 0x10 | uint(c2da_mem[pinmodel + 83]) << 0x18))) * (1.0lf / 11.0lf))
    let c2da_fresh365 : uint = float_bits_to_uint(c2da_fresh364)
    c2da_mem[pmodel + 80] = uint8(c2da_fresh365)
    c2da_mem[pmodel + 81] = uint8(c2da_fresh365 >> 0x8)
    c2da_mem[pmodel + 82] = uint8(c2da_fresh365 >> 0x10)
    c2da_mem[pmodel + 83] = uint8(c2da_fresh365 >> 0x18)
    let c2da_fresh366 : uint = uint(invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinmodel + 72]) | uint(c2da_mem[pinmodel + 73]) << 0x8 | uint(c2da_mem[pinmodel + 74]) << 0x10 | uint(c2da_mem[pinmodel + 75]) << 0x18)))
    let c2da_fresh367 : uint = c2da_fresh366
    c2da_mem[mod_5 + 76] = uint8(c2da_fresh367)
    c2da_mem[mod_5 + 77] = uint8(c2da_fresh367 >> 0x8)
    c2da_mem[mod_5 + 78] = uint8(c2da_fresh367 >> 0x10)
    c2da_mem[mod_5 + 79] = uint8(c2da_fresh367 >> 0x18)
    let c2da_fresh368 : int = int(uint(c2da_mem[pmodel + 68]) | uint(c2da_mem[pmodel + 69]) << 0x8 | uint(c2da_mem[pmodel + 70]) << 0x10 | uint(c2da_mem[pmodel + 71]) << 0x18)
    let c2da_fresh369 : uint = uint(c2da_fresh368)
    c2da_mem[mod_5 + 72] = uint8(c2da_fresh369)
    c2da_mem[mod_5 + 73] = uint8(c2da_fresh369 >> 0x8)
    c2da_mem[mod_5 + 74] = uint8(c2da_fresh369 >> 0x10)
    c2da_mem[mod_5 + 75] = uint8(c2da_fresh369 >> 0x18)
    i_20 = 0
    while (i_20 < 3) {
        let c2da_fresh370 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[pinmodel + 8 + i_20 * 4]) | uint(c2da_mem[pinmodel + 8 + i_20 * 4 + 1]) << 0x8 | uint(c2da_mem[pinmodel + 8 + i_20 * 4 + 2]) << 0x10 | uint(c2da_mem[pinmodel + 8 + i_20 * 4 + 3]) << 0x18))
        let c2da_fresh371 : uint = float_bits_to_uint(c2da_fresh370)
        c2da_mem[pmodel + 8 + i_20 * 4] = uint8(c2da_fresh371)
        c2da_mem[pmodel + 8 + i_20 * 4 + 1] = uint8(c2da_fresh371 >> 0x8)
        c2da_mem[pmodel + 8 + i_20 * 4 + 2] = uint8(c2da_fresh371 >> 0x10)
        c2da_mem[pmodel + 8 + i_20 * 4 + 3] = uint8(c2da_fresh371 >> 0x18)
        let c2da_fresh372 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[pinmodel + 20 + i_20 * 4]) | uint(c2da_mem[pinmodel + 20 + i_20 * 4 + 1]) << 0x8 | uint(c2da_mem[pinmodel + 20 + i_20 * 4 + 2]) << 0x10 | uint(c2da_mem[pinmodel + 20 + i_20 * 4 + 3]) << 0x18))
        let c2da_fresh373 : uint = float_bits_to_uint(c2da_fresh372)
        c2da_mem[pmodel + 20 + i_20 * 4] = uint8(c2da_fresh373)
        c2da_mem[pmodel + 20 + i_20 * 4 + 1] = uint8(c2da_fresh373 >> 0x8)
        c2da_mem[pmodel + 20 + i_20 * 4 + 2] = uint8(c2da_fresh373 >> 0x10)
        c2da_mem[pmodel + 20 + i_20 * 4 + 3] = uint8(c2da_fresh373 >> 0x18)
        let c2da_fresh374 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[pinmodel + 36 + i_20 * 4]) | uint(c2da_mem[pinmodel + 36 + i_20 * 4 + 1]) << 0x8 | uint(c2da_mem[pinmodel + 36 + i_20 * 4 + 2]) << 0x10 | uint(c2da_mem[pinmodel + 36 + i_20 * 4 + 3]) << 0x18))
        let c2da_fresh375 : uint = float_bits_to_uint(c2da_fresh374)
        c2da_mem[pmodel + 36 + i_20 * 4] = uint8(c2da_fresh375)
        c2da_mem[pmodel + 36 + i_20 * 4 + 1] = uint8(c2da_fresh375 >> 0x8)
        c2da_mem[pmodel + 36 + i_20 * 4 + 2] = uint8(c2da_fresh375 >> 0x10)
        c2da_mem[pmodel + 36 + i_20 * 4 + 3] = uint8(c2da_fresh375 >> 0x18)
        i_20++
    }
    numskins = int(uint(c2da_mem[pmodel + 48]) | uint(c2da_mem[pmodel + 49]) << 0x8 | uint(c2da_mem[pmodel + 50]) << 0x10 | uint(c2da_mem[pmodel + 51]) << 0x18)
    numframes_1 = int(uint(c2da_mem[pmodel + 68]) | uint(c2da_mem[pmodel + 69]) << 0x8 | uint(c2da_mem[pmodel + 70]) << 0x10 | uint(c2da_mem[pmodel + 71]) << 0x18)
    if ((int(uint(c2da_mem[pmodel + 52]) | uint(c2da_mem[pmodel + 53]) << 0x8 | uint(c2da_mem[pmodel + 54]) << 0x10 | uint(c2da_mem[pmodel + 55]) << 0x18) & 3) != 0) {
        Sys_Error(726626, [])
    }
    let c2da_fresh376 : int = pmodel - pheader
    let c2da_fresh377 : uint = uint(c2da_fresh376)
    c2da_mem[pheader] = uint8(c2da_fresh377)
    c2da_mem[pheader + 1] = uint8(c2da_fresh377 >> 0x8)
    c2da_mem[pheader + 2] = uint8(c2da_fresh377 >> 0x10)
    c2da_mem[pheader + 3] = uint8(c2da_fresh377 >> 0x18)
    skinsize = int(uint(c2da_mem[pmodel + 56]) | uint(c2da_mem[pmodel + 57]) << 0x8 | uint(c2da_mem[pmodel + 58]) << 0x10 | uint(c2da_mem[pmodel + 59]) << 0x18) * int(uint(c2da_mem[pmodel + 52]) | uint(c2da_mem[pmodel + 53]) << 0x8 | uint(c2da_mem[pmodel + 54]) << 0x10 | uint(c2da_mem[pmodel + 55]) << 0x18)
    if (numskins < 1) {
        Sys_Error(726674, [C2daVaArg(tag = 1, i64 = int64(numskins), f64 = 0.0lf, raw = 0x0)])
    }
    pskintype = pinmodel + 1 * 84
    pskindesc = Hunk_AllocName(int(uint64(numskins) * 24ul), 386384)
    let c2da_fresh378 : int = pskindesc - pheader
    let c2da_fresh379 : uint = uint(c2da_fresh378)
    c2da_mem[pheader + 8] = uint8(c2da_fresh379)
    c2da_mem[pheader + 9] = uint8(c2da_fresh379 >> 0x8)
    c2da_mem[pheader + 10] = uint8(c2da_fresh379 >> 0x10)
    c2da_mem[pheader + 11] = uint8(c2da_fresh379 >> 0x18)
    i_20 = 0
    while (i_20 < numskins) {
        skintype = uint(invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pskintype]) | uint(c2da_mem[pskintype + 1]) << 0x8 | uint(c2da_mem[pskintype + 2]) << 0x10 | uint(c2da_mem[pskintype + 3]) << 0x18)))
        let c2da_fresh380 : uint = skintype
        c2da_mem[pskindesc + i_20 * 24] = uint8(c2da_fresh380)
        c2da_mem[pskindesc + i_20 * 24 + 1] = uint8(c2da_fresh380 >> 0x8)
        c2da_mem[pskindesc + i_20 * 24 + 2] = uint8(c2da_fresh380 >> 0x10)
        c2da_mem[pskindesc + i_20 * 24 + 3] = uint8(c2da_fresh380 >> 0x18)
        if (skintype == 0u) {
            pskintype = Mod_LoadAliasSkin(pskintype + 1 * 4, pskindesc + i_20 * 24 + 16, skinsize, pheader)
        } else {
            pskintype = Mod_LoadAliasSkinGroup(pskintype + 1 * 4, pskindesc + i_20 * 24 + 16, skinsize, pheader)
        }
        i_20++
    }
    pstverts = pmodel + 1 * 84
    pinstverts = pskintype
    let c2da_fresh381 : int = pstverts - pheader
    let c2da_fresh382 : uint = uint(c2da_fresh381)
    c2da_mem[pheader + 4] = uint8(c2da_fresh382)
    c2da_mem[pheader + 5] = uint8(c2da_fresh382 >> 0x8)
    c2da_mem[pheader + 6] = uint8(c2da_fresh382 >> 0x10)
    c2da_mem[pheader + 7] = uint8(c2da_fresh382 >> 0x18)
    i_20 = 0
    while (i_20 < int(uint(c2da_mem[pmodel + 60]) | uint(c2da_mem[pmodel + 61]) << 0x8 | uint(c2da_mem[pmodel + 62]) << 0x10 | uint(c2da_mem[pmodel + 63]) << 0x18)) {
        let c2da_fresh383 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinstverts + i_20 * 12]) | uint(c2da_mem[pinstverts + i_20 * 12 + 1]) << 0x8 | uint(c2da_mem[pinstverts + i_20 * 12 + 2]) << 0x10 | uint(c2da_mem[pinstverts + i_20 * 12 + 3]) << 0x18))
        let c2da_fresh384 : uint = uint(c2da_fresh383)
        c2da_mem[pstverts + i_20 * 12] = uint8(c2da_fresh384)
        c2da_mem[pstverts + i_20 * 12 + 1] = uint8(c2da_fresh384 >> 0x8)
        c2da_mem[pstverts + i_20 * 12 + 2] = uint8(c2da_fresh384 >> 0x10)
        c2da_mem[pstverts + i_20 * 12 + 3] = uint8(c2da_fresh384 >> 0x18)
        let c2da_fresh385 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinstverts + i_20 * 12 + 4]) | uint(c2da_mem[pinstverts + i_20 * 12 + 5]) << 0x8 | uint(c2da_mem[pinstverts + i_20 * 12 + 6]) << 0x10 | uint(c2da_mem[pinstverts + i_20 * 12 + 7]) << 0x18)) << 16
        let c2da_fresh386 : uint = uint(c2da_fresh385)
        c2da_mem[pstverts + i_20 * 12 + 4] = uint8(c2da_fresh386)
        c2da_mem[pstverts + i_20 * 12 + 5] = uint8(c2da_fresh386 >> 0x8)
        c2da_mem[pstverts + i_20 * 12 + 6] = uint8(c2da_fresh386 >> 0x10)
        c2da_mem[pstverts + i_20 * 12 + 7] = uint8(c2da_fresh386 >> 0x18)
        let c2da_fresh387 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinstverts + i_20 * 12 + 8]) | uint(c2da_mem[pinstverts + i_20 * 12 + 9]) << 0x8 | uint(c2da_mem[pinstverts + i_20 * 12 + 10]) << 0x10 | uint(c2da_mem[pinstverts + i_20 * 12 + 11]) << 0x18)) << 16
        let c2da_fresh388 : uint = uint(c2da_fresh387)
        c2da_mem[pstverts + i_20 * 12 + 8] = uint8(c2da_fresh388)
        c2da_mem[pstverts + i_20 * 12 + 9] = uint8(c2da_fresh388 >> 0x8)
        c2da_mem[pstverts + i_20 * 12 + 10] = uint8(c2da_fresh388 >> 0x10)
        c2da_mem[pstverts + i_20 * 12 + 11] = uint8(c2da_fresh388 >> 0x18)
        i_20++
    }
    let c2da_fresh406 : int = int(uint(c2da_mem[pmodel + 60]) | uint(c2da_mem[pmodel + 61]) << 0x8 | uint(c2da_mem[pmodel + 62]) << 0x10 | uint(c2da_mem[pmodel + 63]) << 0x18)
    ptri = pstverts + c2da_fresh406 * 12
    pintriangles = pinstverts + c2da_fresh406 * 12
    let c2da_fresh389 : int = ptri - pheader
    let c2da_fresh390 : uint = uint(c2da_fresh389)
    c2da_mem[pheader + 12] = uint8(c2da_fresh390)
    c2da_mem[pheader + 13] = uint8(c2da_fresh390 >> 0x8)
    c2da_mem[pheader + 14] = uint8(c2da_fresh390 >> 0x10)
    c2da_mem[pheader + 15] = uint8(c2da_fresh390 >> 0x18)
    i_20 = 0
    while (i_20 < int(uint(c2da_mem[pmodel + 64]) | uint(c2da_mem[pmodel + 65]) << 0x8 | uint(c2da_mem[pmodel + 66]) << 0x10 | uint(c2da_mem[pmodel + 67]) << 0x18)) {
        let c2da_fresh391 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pintriangles + i_20 * 16]) | uint(c2da_mem[pintriangles + i_20 * 16 + 1]) << 0x8 | uint(c2da_mem[pintriangles + i_20 * 16 + 2]) << 0x10 | uint(c2da_mem[pintriangles + i_20 * 16 + 3]) << 0x18))
        let c2da_fresh392 : uint = uint(c2da_fresh391)
        c2da_mem[ptri + i_20 * 16] = uint8(c2da_fresh392)
        c2da_mem[ptri + i_20 * 16 + 1] = uint8(c2da_fresh392 >> 0x8)
        c2da_mem[ptri + i_20 * 16 + 2] = uint8(c2da_fresh392 >> 0x10)
        c2da_mem[ptri + i_20 * 16 + 3] = uint8(c2da_fresh392 >> 0x18)
        for (j_9 in range(0, 3)) {
            let c2da_fresh393 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pintriangles + i_20 * 16 + 4 + j_9 * 4]) | uint(c2da_mem[pintriangles + i_20 * 16 + 4 + j_9 * 4 + 1]) << 0x8 | uint(c2da_mem[pintriangles + i_20 * 16 + 4 + j_9 * 4 + 2]) << 0x10 | uint(c2da_mem[pintriangles + i_20 * 16 + 4 + j_9 * 4 + 3]) << 0x18))
            let c2da_fresh394 : uint = uint(c2da_fresh393)
            c2da_mem[ptri + i_20 * 16 + 4 + j_9 * 4] = uint8(c2da_fresh394)
            c2da_mem[ptri + i_20 * 16 + 4 + j_9 * 4 + 1] = uint8(c2da_fresh394 >> 0x8)
            c2da_mem[ptri + i_20 * 16 + 4 + j_9 * 4 + 2] = uint8(c2da_fresh394 >> 0x10)
            c2da_mem[ptri + i_20 * 16 + 4 + j_9 * 4 + 3] = uint8(c2da_fresh394 >> 0x18)
        }
        i_20++
    }
    if (numframes_1 < 1) {
        Sys_Error(726718, [C2daVaArg(tag = 1, i64 = int64(numframes_1), f64 = 0.0lf, raw = 0x0)])
    }
    pframetype_0 = pintriangles + int(uint(c2da_mem[pmodel + 64]) | uint(c2da_mem[pmodel + 65]) << 0x8 | uint(c2da_mem[pmodel + 66]) << 0x10 | uint(c2da_mem[pmodel + 67]) << 0x18) * 16
    i_20 = 0
    for (c2da_i_20 in range(i_20, numframes_1)) {
        frametype_0 = uint(invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pframetype_0]) | uint(c2da_mem[pframetype_0 + 1]) << 0x8 | uint(c2da_mem[pframetype_0 + 2]) << 0x10 | uint(c2da_mem[pframetype_0 + 3]) << 0x18)))
        let c2da_fresh395 : uint = frametype_0
        c2da_mem[pheader + 16 + c2da_i_20 * 32] = uint8(c2da_fresh395)
        c2da_mem[pheader + 16 + c2da_i_20 * 32 + 1] = uint8(c2da_fresh395 >> 0x8)
        c2da_mem[pheader + 16 + c2da_i_20 * 32 + 2] = uint8(c2da_fresh395 >> 0x10)
        c2da_mem[pheader + 16 + c2da_i_20 * 32 + 3] = uint8(c2da_fresh395 >> 0x18)
        if (frametype_0 == 0u) {
            pframetype_0 = Mod_LoadAliasFrame(pframetype_0 + 1 * 4, pheader + 16 + c2da_i_20 * 32 + 12, int(uint(c2da_mem[pmodel + 60]) | uint(c2da_mem[pmodel + 61]) << 0x8 | uint(c2da_mem[pmodel + 62]) << 0x10 | uint(c2da_mem[pmodel + 63]) << 0x18), pheader + 16 + c2da_i_20 * 32 + 4, pheader + 16 + c2da_i_20 * 32 + 8, pheader, pheader + 16 + c2da_i_20 * 32 + 16)
        } else {
            pframetype_0 = Mod_LoadAliasGroup(pframetype_0 + 1 * 4, pheader + 16 + c2da_i_20 * 32 + 12, int(uint(c2da_mem[pmodel + 60]) | uint(c2da_mem[pmodel + 61]) << 0x8 | uint(c2da_mem[pmodel + 62]) << 0x10 | uint(c2da_mem[pmodel + 63]) << 0x18), pheader + 16 + c2da_i_20 * 32 + 4, pheader + 16 + c2da_i_20 * 32 + 8, pheader, pheader + 16 + c2da_i_20 * 32 + 16)
        }
    }
    let c2da_fresh396 : uint = 2u
    let c2da_fresh397 : uint = c2da_fresh396
    c2da_mem[mod_5 + 68] = uint8(c2da_fresh397)
    c2da_mem[mod_5 + 69] = uint8(c2da_fresh397 >> 0x8)
    c2da_mem[mod_5 + 70] = uint8(c2da_fresh397 >> 0x10)
    c2da_mem[mod_5 + 71] = uint8(c2da_fresh397 >> 0x18)
    let c2da_fresh398 : float = -16.0
    let c2da_fresh399 : uint = float_bits_to_uint(c2da_fresh398)
    c2da_mem[mod_5 + 84 + 2 * 4] = uint8(c2da_fresh399)
    c2da_mem[mod_5 + 84 + 2 * 4 + 1] = uint8(c2da_fresh399 >> 0x8)
    c2da_mem[mod_5 + 84 + 2 * 4 + 2] = uint8(c2da_fresh399 >> 0x10)
    c2da_mem[mod_5 + 84 + 2 * 4 + 3] = uint8(c2da_fresh399 >> 0x18)
    let c2da_fresh400 : uint = float_bits_to_uint(c2da_fresh398)
    c2da_mem[mod_5 + 84 + 1 * 4] = uint8(c2da_fresh400)
    c2da_mem[mod_5 + 84 + 1 * 4 + 1] = uint8(c2da_fresh400 >> 0x8)
    c2da_mem[mod_5 + 84 + 1 * 4 + 2] = uint8(c2da_fresh400 >> 0x10)
    c2da_mem[mod_5 + 84 + 1 * 4 + 3] = uint8(c2da_fresh400 >> 0x18)
    let c2da_fresh401 : uint = float_bits_to_uint(c2da_fresh398)
    c2da_mem[mod_5 + 84 + 0 * 4] = uint8(c2da_fresh401)
    c2da_mem[mod_5 + 84 + 0 * 4 + 1] = uint8(c2da_fresh401 >> 0x8)
    c2da_mem[mod_5 + 84 + 0 * 4 + 2] = uint8(c2da_fresh401 >> 0x10)
    c2da_mem[mod_5 + 84 + 0 * 4 + 3] = uint8(c2da_fresh401 >> 0x18)
    let c2da_fresh402 : float = 16.0
    let c2da_fresh403 : uint = float_bits_to_uint(c2da_fresh402)
    c2da_mem[mod_5 + 96 + 2 * 4] = uint8(c2da_fresh403)
    c2da_mem[mod_5 + 96 + 2 * 4 + 1] = uint8(c2da_fresh403 >> 0x8)
    c2da_mem[mod_5 + 96 + 2 * 4 + 2] = uint8(c2da_fresh403 >> 0x10)
    c2da_mem[mod_5 + 96 + 2 * 4 + 3] = uint8(c2da_fresh403 >> 0x18)
    let c2da_fresh404 : uint = float_bits_to_uint(c2da_fresh402)
    c2da_mem[mod_5 + 96 + 1 * 4] = uint8(c2da_fresh404)
    c2da_mem[mod_5 + 96 + 1 * 4 + 1] = uint8(c2da_fresh404 >> 0x8)
    c2da_mem[mod_5 + 96 + 1 * 4 + 2] = uint8(c2da_fresh404 >> 0x10)
    c2da_mem[mod_5 + 96 + 1 * 4 + 3] = uint8(c2da_fresh404 >> 0x18)
    let c2da_fresh405 : uint = float_bits_to_uint(c2da_fresh402)
    c2da_mem[mod_5 + 96 + 0 * 4] = uint8(c2da_fresh405)
    c2da_mem[mod_5 + 96 + 0 * 4 + 1] = uint8(c2da_fresh405 >> 0x8)
    c2da_mem[mod_5 + 96 + 0 * 4 + 2] = uint8(c2da_fresh405 >> 0x10)
    c2da_mem[mod_5 + 96 + 0 * 4 + 3] = uint8(c2da_fresh405 >> 0x18)
    end = Hunk_LowMark()
    total = end - start
    Cache_Alloc(mod_5 + 528, total, 386384)
    if (int(uint(c2da_mem[mod_5 + 528]) | uint(c2da_mem[mod_5 + 529]) << 0x8 | uint(c2da_mem[mod_5 + 530]) << 0x10 | uint(c2da_mem[mod_5 + 531]) << 0x18) == 0) {
        return
    }
    c2da_lin_memcpy(int(uint(c2da_mem[mod_5 + 528]) | uint(c2da_mem[mod_5 + 529]) << 0x8 | uint(c2da_mem[mod_5 + 530]) << 0x10 | uint(c2da_mem[mod_5 + 531]) << 0x18), pheader, uint64(total))
    Hunk_FreeToLowMark(start)
    return
}
[export, sideeffects]
def Mod_LoadAliasGroup(var pin_2 : int; var pframeindex : int; var numv : int; var pbboxmin : int; var pbboxmax : int; var pheader_0 : int; var name_1 : int) : int {
    var pingroup_0 : int
    var paliasgroup : int
    var i_21 : int
    var numframes_2 : int
    var pin_intervals_0 : int
    var poutintervals_0 : int
    var ptemp_0 : int
    pingroup_0 = pin_2
    numframes_2 = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pingroup_0]) | uint(c2da_mem[pingroup_0 + 1]) << 0x8 | uint(c2da_mem[pingroup_0 + 2]) << 0x10 | uint(c2da_mem[pingroup_0 + 3]) << 0x18))
    paliasgroup = Hunk_AllocName(int(20ul + uint64(numframes_2 - 1) * 12ul), 386384)
    let c2da_fresh407 : uint = uint(numframes_2)
    c2da_mem[paliasgroup] = uint8(c2da_fresh407)
    c2da_mem[paliasgroup + 1] = uint8(c2da_fresh407 >> 0x8)
    c2da_mem[paliasgroup + 2] = uint8(c2da_fresh407 >> 0x10)
    c2da_mem[paliasgroup + 3] = uint8(c2da_fresh407 >> 0x18)
    i_21 = 0
    while (i_21 < 3) {
        let c2da_fresh408 : uint8 = c2da_mem[pingroup_0 + 4 + i_21]
        c2da_mem[pbboxmin + i_21] = c2da_fresh408
        let c2da_fresh409 : uint8 = c2da_mem[pingroup_0 + 8 + i_21]
        c2da_mem[pbboxmax + i_21] = c2da_fresh409
        i_21++
    }
    let c2da_fresh410 : int = paliasgroup - pheader_0
    let c2da_fresh411 : uint = uint(c2da_fresh410)
    c2da_mem[pframeindex] = uint8(c2da_fresh411)
    c2da_mem[pframeindex + 1] = uint8(c2da_fresh411 >> 0x8)
    c2da_mem[pframeindex + 2] = uint8(c2da_fresh411 >> 0x10)
    c2da_mem[pframeindex + 3] = uint8(c2da_fresh411 >> 0x18)
    pin_intervals_0 = pingroup_0 + 1 * 12
    poutintervals_0 = Hunk_AllocName(int(uint64(numframes_2) * 4ul), 386384)
    let c2da_fresh412 : int = poutintervals_0 - pheader_0
    let c2da_fresh413 : uint = uint(c2da_fresh412)
    c2da_mem[paliasgroup + 4] = uint8(c2da_fresh413)
    c2da_mem[paliasgroup + 5] = uint8(c2da_fresh413 >> 0x8)
    c2da_mem[paliasgroup + 6] = uint8(c2da_fresh413 >> 0x10)
    c2da_mem[paliasgroup + 7] = uint8(c2da_fresh413 >> 0x18)
    i_21 = 0
    while (i_21 < numframes_2) {
        let c2da_fresh414 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[pin_intervals_0]) | uint(c2da_mem[pin_intervals_0 + 1]) << 0x8 | uint(c2da_mem[pin_intervals_0 + 2]) << 0x10 | uint(c2da_mem[pin_intervals_0 + 3]) << 0x18))
        let c2da_fresh415 : uint = float_bits_to_uint(c2da_fresh414)
        c2da_mem[poutintervals_0] = uint8(c2da_fresh415)
        c2da_mem[poutintervals_0 + 1] = uint8(c2da_fresh415 >> 0x8)
        c2da_mem[poutintervals_0 + 2] = uint8(c2da_fresh415 >> 0x10)
        c2da_mem[poutintervals_0 + 3] = uint8(c2da_fresh415 >> 0x18)
        if (double(c2da_fresh414) <= 0.0lf) {
            Sys_Error(726763, [])
        }
        poutintervals_0 += 4
        pin_intervals_0 += 4
        i_21++
    }
    ptemp_0 = pin_intervals_0
    i_21 = 0
    for (c2da_i_21 in range(i_21, numframes_2)) {
        ptemp_0 = Mod_LoadAliasFrame(ptemp_0, paliasgroup + 8 + c2da_i_21 * 12 + 8, numv, paliasgroup + 8 + c2da_i_21 * 12, paliasgroup + 8 + c2da_i_21 * 12 + 4, pheader_0, name_1)
    }
    return ptemp_0
}
[export, sideeffects]
def Mod_LoadAliasFrame(var pin_3 : int; var pframeindex_0 : int; var numv_0 : int; var pbboxmin_0 : int; var pbboxmax_0 : int; var pheader_1 : int; var name_2 : int) : int {
    var pframe : int
    var pinframe_0 : int
    var pdaliasframe : int = pin_3
    c2da_lin_strcpy(name_2, pdaliasframe + 8)
    for (i_22 in range(0, 3)) {
        let c2da_fresh416 : uint8 = c2da_mem[pdaliasframe + i_22]
        c2da_mem[pbboxmin_0 + i_22] = c2da_fresh416
        let c2da_fresh417 : uint8 = c2da_mem[pdaliasframe + 4 + i_22]
        c2da_mem[pbboxmax_0 + i_22] = c2da_fresh417
    }
    pinframe_0 = pdaliasframe + 1 * 24
    pframe = Hunk_AllocName(int(uint64(numv_0) * 4ul), 386384)
    let c2da_fresh418 : int = pframe - pheader_1
    let c2da_fresh419 : uint = uint(c2da_fresh418)
    c2da_mem[pframeindex_0] = uint8(c2da_fresh419)
    c2da_mem[pframeindex_0 + 1] = uint8(c2da_fresh419 >> 0x8)
    c2da_mem[pframeindex_0 + 2] = uint8(c2da_fresh419 >> 0x10)
    c2da_mem[pframeindex_0 + 3] = uint8(c2da_fresh419 >> 0x18)
    for (j_10 in range(0, numv_0)) {
        let c2da_fresh420 : uint8 = c2da_mem[pinframe_0 + j_10 * 4 + 3]
        c2da_mem[pframe + j_10 * 4 + 3] = c2da_fresh420
        for (k in range(0, 3)) {
            let c2da_fresh421 : uint8 = c2da_mem[pinframe_0 + j_10 * 4 + k]
            c2da_mem[pframe + j_10 * 4 + k] = c2da_fresh421
        }
    }
    pinframe_0 += numv_0 * 4
    return pinframe_0
}
[export, sideeffects]
def Mod_LoadAliasSkinGroup(var pin_4 : int; var pskinindex : int; var skinsize_0 : int; var pheader_2 : int) : int {
    var pinskingroup : int
    var paliasskingroup : int
    var i_23 : int
    var numskins_0 : int
    var pinskinintervals : int
    var poutskinintervals : int
    var ptemp_1 : int
    pinskingroup = pin_4
    numskins_0 = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pinskingroup]) | uint(c2da_mem[pinskingroup + 1]) << 0x8 | uint(c2da_mem[pinskingroup + 2]) << 0x10 | uint(c2da_mem[pinskingroup + 3]) << 0x18))
    paliasskingroup = Hunk_AllocName(int(32ul + uint64(numskins_0 - 1) * 24ul), 386384)
    let c2da_fresh422 : uint = uint(numskins_0)
    c2da_mem[paliasskingroup] = uint8(c2da_fresh422)
    c2da_mem[paliasskingroup + 1] = uint8(c2da_fresh422 >> 0x8)
    c2da_mem[paliasskingroup + 2] = uint8(c2da_fresh422 >> 0x10)
    c2da_mem[paliasskingroup + 3] = uint8(c2da_fresh422 >> 0x18)
    let c2da_fresh423 : int = paliasskingroup - pheader_2
    let c2da_fresh424 : uint = uint(c2da_fresh423)
    c2da_mem[pskinindex] = uint8(c2da_fresh424)
    c2da_mem[pskinindex + 1] = uint8(c2da_fresh424 >> 0x8)
    c2da_mem[pskinindex + 2] = uint8(c2da_fresh424 >> 0x10)
    c2da_mem[pskinindex + 3] = uint8(c2da_fresh424 >> 0x18)
    pinskinintervals = pinskingroup + 1 * 4
    poutskinintervals = Hunk_AllocName(int(uint64(numskins_0) * 4ul), 386384)
    let c2da_fresh425 : int = poutskinintervals - pheader_2
    let c2da_fresh426 : uint = uint(c2da_fresh425)
    c2da_mem[paliasskingroup + 4] = uint8(c2da_fresh426)
    c2da_mem[paliasskingroup + 5] = uint8(c2da_fresh426 >> 0x8)
    c2da_mem[paliasskingroup + 6] = uint8(c2da_fresh426 >> 0x10)
    c2da_mem[paliasskingroup + 7] = uint8(c2da_fresh426 >> 0x18)
    i_23 = 0
    while (i_23 < numskins_0) {
        let c2da_fresh427 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[pinskinintervals]) | uint(c2da_mem[pinskinintervals + 1]) << 0x8 | uint(c2da_mem[pinskinintervals + 2]) << 0x10 | uint(c2da_mem[pinskinintervals + 3]) << 0x18))
        let c2da_fresh428 : uint = float_bits_to_uint(c2da_fresh427)
        c2da_mem[poutskinintervals] = uint8(c2da_fresh428)
        c2da_mem[poutskinintervals + 1] = uint8(c2da_fresh428 >> 0x8)
        c2da_mem[poutskinintervals + 2] = uint8(c2da_fresh428 >> 0x10)
        c2da_mem[poutskinintervals + 3] = uint8(c2da_fresh428 >> 0x18)
        if (c2da_fresh427 <= 0.0) {
            Sys_Error(726795, [])
        }
        poutskinintervals += 4
        pinskinintervals += 4
        i_23++
    }
    ptemp_1 = pinskinintervals
    i_23 = 0
    for (c2da_i_23 in range(i_23, numskins_0)) {
        ptemp_1 = Mod_LoadAliasSkin(ptemp_1, paliasskingroup + 8 + c2da_i_23 * 24 + 16, skinsize_0, pheader_2)
    }
    return ptemp_1
}
[export, sideeffects]
def Mod_LoadAliasSkin(var pin_5 : int; var pskinindex_0 : int; var skinsize_1 : int; var pheader_3 : int) : int {
    var i_24 : int
    var pskin : int
    var pinskin : int
    var pusskin : int
    pskin = Hunk_AllocName(skinsize_1, 386384)
    pinskin = pin_5
    let c2da_fresh429 : int = pskin - pheader_3
    let c2da_fresh430 : uint = uint(c2da_fresh429)
    c2da_mem[pskinindex_0] = uint8(c2da_fresh430)
    c2da_mem[pskinindex_0 + 1] = uint8(c2da_fresh430 >> 0x8)
    c2da_mem[pskinindex_0 + 2] = uint8(c2da_fresh430 >> 0x10)
    c2da_mem[pskinindex_0 + 3] = uint8(c2da_fresh430 >> 0x18)
    Q_memcpy(pskin, pinskin, skinsize_1)
    pinskin += skinsize_1
    return pinskin
}
[export, sideeffects]
def Mod_Extradata(var mod_6 : int) : int {
    var r : int = Cache_Check(mod_6 + 528)
    if (r != 0) {
        return r
    }
    Mod_LoadModel(mod_6, 1u)
    if (int(uint(c2da_mem[mod_6 + 528]) | uint(c2da_mem[mod_6 + 529]) << 0x8 | uint(c2da_mem[mod_6 + 530]) << 0x10 | uint(c2da_mem[mod_6 + 531]) << 0x18) == 0) {
        Sys_Error(726831, [])
    }
    return int(uint(c2da_mem[mod_6 + 528]) | uint(c2da_mem[mod_6 + 529]) << 0x8 | uint(c2da_mem[mod_6 + 530]) << 0x10 | uint(c2da_mem[mod_6 + 531]) << 0x18)
}
[export, sideeffects]
def Mod_TouchModel(var name_3 : int) {
    var mod_7 : int = Mod_FindName(name_3)
    if ((uint(c2da_mem[mod_7 + 64]) | uint(c2da_mem[mod_7 + 65]) << 0x8 | uint(c2da_mem[mod_7 + 66]) << 0x10 | uint(c2da_mem[mod_7 + 67]) << 0x18) == 0u) {
        if ((uint(c2da_mem[mod_7 + 68]) | uint(c2da_mem[mod_7 + 69]) << 0x8 | uint(c2da_mem[mod_7 + 70]) << 0x10 | uint(c2da_mem[mod_7 + 71]) << 0x18) == 2u) {
            Cache_Check(mod_7 + 528)
        }
    }
    return
}
[export, sideeffects]
def Mod_PointInLeaf(var p_1 : int; var model : int) : int {
    var node_0 : int
    var plane : int
    if (model == 0 || int(uint(c2da_mem[model + 208]) | uint(c2da_mem[model + 209]) << 0x8 | uint(c2da_mem[model + 210]) << 0x10 | uint(c2da_mem[model + 211]) << 0x18) == 0) {
        Sys_Error(726861, [])
    }
    node_0 = int(uint(c2da_mem[model + 208]) | uint(c2da_mem[model + 209]) << 0x8 | uint(c2da_mem[model + 210]) << 0x10 | uint(c2da_mem[model + 211]) << 0x18)
    while (true) {
        if (int(uint(c2da_mem[node_0]) | uint(c2da_mem[node_0 + 1]) << 0x8 | uint(c2da_mem[node_0 + 2]) << 0x10 | uint(c2da_mem[node_0 + 3]) << 0x18) < 0) {
            return node_0
        }
        plane = int(uint(c2da_mem[node_0 + 32]) | uint(c2da_mem[node_0 + 33]) << 0x8 | uint(c2da_mem[node_0 + 34]) << 0x10 | uint(c2da_mem[node_0 + 35]) << 0x18)
        if (uint_bits_to_float(uint(c2da_mem[p_1 + 0 * 4]) | uint(c2da_mem[p_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p_1 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 0 * 4]) | uint(c2da_mem[plane + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[p_1 + 1 * 4]) | uint(c2da_mem[p_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p_1 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 1 * 4]) | uint(c2da_mem[plane + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[p_1 + 2 * 4]) | uint(c2da_mem[p_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p_1 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 2 * 4]) | uint(c2da_mem[plane + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane + 12]) | uint(c2da_mem[plane + 13]) << 0x8 | uint(c2da_mem[plane + 14]) << 0x10 | uint(c2da_mem[plane + 15]) << 0x18) > 0.0) {
            node_0 = int(uint(c2da_mem[node_0 + 40 + 0 * 8]) | uint(c2da_mem[node_0 + 40 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[node_0 + 40 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[node_0 + 40 + 0 * 8 + 3]) << 0x18)
        } else {
            node_0 = int(uint(c2da_mem[node_0 + 40 + 1 * 8]) | uint(c2da_mem[node_0 + 40 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[node_0 + 40 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[node_0 + 40 + 1 * 8 + 3]) << 0x18)
        }
    }
    panic("control reached the end of a non-void function")
    return 0
}
[export, sideeffects]
def Mod_LeafPVS(var leaf : int; var model_0 : int) : int {
    if (leaf == int(uint(c2da_mem[model_0 + 160]) | uint(c2da_mem[model_0 + 161]) << 0x8 | uint(c2da_mem[model_0 + 162]) << 0x10 | uint(c2da_mem[model_0 + 163]) << 0x18)) {
        return 248144
    }
    return Mod_DecompressVis(int(uint(c2da_mem[leaf + 32]) | uint(c2da_mem[leaf + 33]) << 0x8 | uint(c2da_mem[leaf + 34]) << 0x10 | uint(c2da_mem[leaf + 35]) << 0x18), model_0)
}
[export, sideeffects]
def Mod_DecompressVis(var in_12 : int; var model_1 : int) : int {
    var c : int
    var out_11 : int
    var row : int = int(uint(c2da_mem[model_1 + 152]) | uint(c2da_mem[model_1 + 153]) << 0x8 | uint(c2da_mem[model_1 + 154]) << 0x10 | uint(c2da_mem[model_1 + 155]) << 0x18) + 7 >> 3
    out_11 = 724992
    if (in_12 == 0) {
        while (row != 0) {
            let c2da_fresh431 : int = out_11
            out_11++
            let c2da_fresh432 : uint8 = 0xffu8
            c2da_mem[c2da_fresh431] = c2da_fresh432
            row--
        }
        return 724992
    }
    while (true) {
        if (c2da_mem[in_12] != 0x0) {
            let c2da_fresh433 : int = out_11
            out_11++
            let c2da_fresh434 : int = in_12
            in_12++
            let c2da_fresh435 : uint8 = c2da_mem[c2da_fresh434]
            c2da_mem[c2da_fresh433] = c2da_fresh435
            if (int64(out_11 - 724992) >= int64(row)) {
                break
            }
            continue
        }
        c = int(c2da_mem[in_12 + 1])
        in_12 += 2
        while (c != 0) {
            let c2da_fresh436 : int = out_11
            out_11++
            let c2da_fresh437 : uint8 = 0u8
            c2da_mem[c2da_fresh436] = c2da_fresh437
            c--
        }
        if (int64(out_11 - 724992) >= int64(row)) {
            break
        }
    }
    return 724992
}
[export, sideeffects]
def Mod_Print() {
    var i_25 : int
    var mod_8 : int
    Con_Printf(726888, [])
    i_25 = 0
    mod_8 = 249168
    while (i_25 < mod_numknown) {
        Con_Printf(726904, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[mod_8 + 528]) | uint(c2da_mem[mod_8 + 529]) << 0x8 | uint(c2da_mem[mod_8 + 530]) << 0x10 | uint(c2da_mem[mod_8 + 531]) << 0x18))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(mod_8))])
        if (((uint(c2da_mem[mod_8 + 64]) | uint(c2da_mem[mod_8 + 65]) << 0x8 | uint(c2da_mem[mod_8 + 66]) << 0x10 | uint(c2da_mem[mod_8 + 67]) << 0x18) & 2u) != 0x0) {
            Con_Printf(726913, [])
        }
        if (((uint(c2da_mem[mod_8 + 64]) | uint(c2da_mem[mod_8 + 65]) << 0x8 | uint(c2da_mem[mod_8 + 66]) << 0x10 | uint(c2da_mem[mod_8 + 67]) << 0x18) & 1u) != 0x0) {
            Con_Printf(726919, [])
        }
        Con_Printf(726925, [])
        i_25++
        mod_8 += 536
    }
    return
}
[sideeffects]
def private Mod_LoadModel_c2da_frame(var mod_1 : int; var crash_0 : uint; c2da_fp : int) : int {
    var c2da_fresh7 : int
    var buf : int
    if ((uint(c2da_mem[mod_1 + 68]) | uint(c2da_mem[mod_1 + 69]) << 0x8 | uint(c2da_mem[mod_1 + 70]) << 0x10 | uint(c2da_mem[mod_1 + 71]) << 0x18) == 2u) {
        if (Cache_Check(mod_1 + 528) != 0) {
            let c2da_fresh3 : uint = 0u
            let c2da_fresh4 : uint = c2da_fresh3
            c2da_mem[mod_1 + 64] = uint8(c2da_fresh4)
            c2da_mem[mod_1 + 65] = uint8(c2da_fresh4 >> 0x8)
            c2da_mem[mod_1 + 66] = uint8(c2da_fresh4 >> 0x10)
            c2da_mem[mod_1 + 67] = uint8(c2da_fresh4 >> 0x18)
            return mod_1
        }
    } elif ((uint(c2da_mem[mod_1 + 64]) | uint(c2da_mem[mod_1 + 65]) << 0x8 | uint(c2da_mem[mod_1 + 66]) << 0x10 | uint(c2da_mem[mod_1 + 67]) << 0x18) == 0u) {
        return mod_1
    }
    buf = COM_LoadStackFile(mod_1, c2da_fp, 1024)
    if (buf == 0) {
        if (crash_0 != 0u) {
            Sys_Error(726016, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(mod_1))])
        }
        return 0
    }
    COM_FileBase(mod_1, 386384, 32ul)
    loadmodel = int(mod_1)  // nolint:PERF020
    let c2da_fresh5 : uint = 0u
    let c2da_fresh6 : uint = c2da_fresh5
    c2da_mem[mod_1 + 64] = uint8(c2da_fresh6)
    c2da_mem[mod_1 + 65] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[mod_1 + 66] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[mod_1 + 67] = uint8(c2da_fresh6 >> 0x18)
    c2da_fresh7 = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[buf]) | uint(c2da_mem[buf + 1]) << 0x8 | uint(c2da_mem[buf + 2]) << 0x10 | uint(c2da_mem[buf + 3]) << 0x18))
    if (c2da_fresh7 == 1330660425) {
        Mod_LoadAliasModel(mod_1, buf)
    } elif (c2da_fresh7 == 1347634249) {
        Mod_LoadSpriteModel(mod_1, buf)
    } else {
        Mod_LoadBrushModel(mod_1, buf)
    }
    return mod_1
}
[sideeffects]
def private Mod_LoadBrushModel_c2da_frame(var mod_2 : int; var buffer : int; c2da_fp : int) {
    var i_0 : int
    var header : int
    var bm : int
    let c2da_fresh8 : uint = 0u
    let c2da_fresh9 : uint = c2da_fresh8
    c2da_mem[loadmodel + 68] = uint8(c2da_fresh9)
    c2da_mem[loadmodel + 69] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[loadmodel + 70] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[loadmodel + 71] = uint8(c2da_fresh9 >> 0x18)
    header = buffer
    i_0 = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[header]) | uint(c2da_mem[header + 1]) << 0x8 | uint(c2da_mem[header + 2]) << 0x10 | uint(c2da_mem[header + 3]) << 0x18))
    if (i_0 != 29) {
        Sys_Error(726045, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(mod_2)), C2daVaArg(tag = 1, i64 = int64(i_0), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = 29l, f64 = 0.0lf, raw = 0x0)])
    }
    mod_base = header
    i_0 = 0
    while (uint64(i_0) < 124ul / 4ul) {
        let c2da_fresh10 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[header + i_0 * 4]) | uint(c2da_mem[header + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[header + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[header + i_0 * 4 + 3]) << 0x18))
        let c2da_fresh11 : uint = uint(c2da_fresh10)
        c2da_mem[header + i_0 * 4] = uint8(c2da_fresh11)
        c2da_mem[header + i_0 * 4 + 1] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[header + i_0 * 4 + 2] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[header + i_0 * 4 + 3] = uint8(c2da_fresh11 >> 0x18)
        i_0++
    }
    Mod_LoadVertexes(header + 4 + 3 * 8)
    Mod_LoadEdges(header + 4 + 12 * 8)
    Mod_LoadSurfedges(header + 4 + 13 * 8)
    Mod_LoadTextures(header + 4 + 2 * 8)
    Mod_LoadLighting(header + 4 + 8 * 8)
    Mod_LoadPlanes(header + 4 + 1 * 8)
    Mod_LoadTexinfo(header + 4 + 6 * 8)
    Mod_LoadFaces(header + 4 + 7 * 8)
    Mod_LoadMarksurfaces(header + 4 + 11 * 8)
    Mod_LoadVisibility(header + 4 + 4 * 8)
    Mod_LoadLeafs(header + 4 + 10 * 8)
    Mod_LoadNodes(header + 4 + 5 * 8)
    Mod_LoadClipnodes(header + 4 + 9 * 8)
    Mod_LoadEntities(header + 4 + 0 * 8)
    Mod_LoadSubmodels(header + 4 + 14 * 8)
    Mod_MakeHull0()
    let c2da_fresh12 : int = 2
    let c2da_fresh13 : uint = uint(c2da_fresh12)
    c2da_mem[mod_2 + 72] = uint8(c2da_fresh13)
    c2da_mem[mod_2 + 73] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[mod_2 + 74] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[mod_2 + 75] = uint8(c2da_fresh13 >> 0x18)
    let c2da_fresh14 : int = 0
    let c2da_fresh15 : uint = uint(c2da_fresh14)
    c2da_mem[mod_2 + 80] = uint8(c2da_fresh15)
    c2da_mem[mod_2 + 81] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[mod_2 + 82] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[mod_2 + 83] = uint8(c2da_fresh15 >> 0x18)
    i_0 = 0
    while (i_0 < int(uint(c2da_mem[mod_2 + 120]) | uint(c2da_mem[mod_2 + 121]) << 0x8 | uint(c2da_mem[mod_2 + 122]) << 0x10 | uint(c2da_mem[mod_2 + 123]) << 0x18)) {
        bm = int(uint(c2da_mem[mod_2 + 128]) | uint(c2da_mem[mod_2 + 129]) << 0x8 | uint(c2da_mem[mod_2 + 130]) << 0x10 | uint(c2da_mem[mod_2 + 131]) << 0x18) + i_0 * 64
        let c2da_fresh16 : int = int(uint(c2da_mem[bm + 36 + 0 * 4]) | uint(c2da_mem[bm + 36 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[bm + 36 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[bm + 36 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh17 : uint = uint(c2da_fresh16)
        c2da_mem[mod_2 + 296 + 0 * 48 + 16] = uint8(c2da_fresh17)
        c2da_mem[mod_2 + 296 + 0 * 48 + 17] = uint8(c2da_fresh17 >> 0x8)
        c2da_mem[mod_2 + 296 + 0 * 48 + 18] = uint8(c2da_fresh17 >> 0x10)
        c2da_mem[mod_2 + 296 + 0 * 48 + 19] = uint8(c2da_fresh17 >> 0x18)
        for (j in range(1, 4)) {
            let c2da_fresh18 : int = int(uint(c2da_mem[bm + 36 + j * 4]) | uint(c2da_mem[bm + 36 + j * 4 + 1]) << 0x8 | uint(c2da_mem[bm + 36 + j * 4 + 2]) << 0x10 | uint(c2da_mem[bm + 36 + j * 4 + 3]) << 0x18)
            let c2da_fresh19 : uint = uint(c2da_fresh18)
            c2da_mem[mod_2 + 296 + j * 48 + 16] = uint8(c2da_fresh19)
            c2da_mem[mod_2 + 296 + j * 48 + 17] = uint8(c2da_fresh19 >> 0x8)
            c2da_mem[mod_2 + 296 + j * 48 + 18] = uint8(c2da_fresh19 >> 0x10)
            c2da_mem[mod_2 + 296 + j * 48 + 19] = uint8(c2da_fresh19 >> 0x18)
            let c2da_fresh20 : int = int(uint(c2da_mem[mod_2 + 264]) | uint(c2da_mem[mod_2 + 265]) << 0x8 | uint(c2da_mem[mod_2 + 266]) << 0x10 | uint(c2da_mem[mod_2 + 267]) << 0x18) - 1
            let c2da_fresh21 : uint = uint(c2da_fresh20)
            c2da_mem[mod_2 + 296 + j * 48 + 20] = uint8(c2da_fresh21)
            c2da_mem[mod_2 + 296 + j * 48 + 21] = uint8(c2da_fresh21 >> 0x8)
            c2da_mem[mod_2 + 296 + j * 48 + 22] = uint8(c2da_fresh21 >> 0x10)
            c2da_mem[mod_2 + 296 + j * 48 + 23] = uint8(c2da_fresh21 >> 0x18)
        }
        let c2da_fresh22 : int = int(uint(c2da_mem[bm + 56]) | uint(c2da_mem[bm + 57]) << 0x8 | uint(c2da_mem[bm + 58]) << 0x10 | uint(c2da_mem[bm + 59]) << 0x18)
        let c2da_fresh23 : uint = uint(c2da_fresh22)
        c2da_mem[mod_2 + 112] = uint8(c2da_fresh23)
        c2da_mem[mod_2 + 113] = uint8(c2da_fresh23 >> 0x8)
        c2da_mem[mod_2 + 114] = uint8(c2da_fresh23 >> 0x10)
        c2da_mem[mod_2 + 115] = uint8(c2da_fresh23 >> 0x18)
        let c2da_fresh24 : int = int(uint(c2da_mem[bm + 60]) | uint(c2da_mem[bm + 61]) << 0x8 | uint(c2da_mem[bm + 62]) << 0x10 | uint(c2da_mem[bm + 63]) << 0x18)
        let c2da_fresh25 : uint = uint(c2da_fresh24)
        c2da_mem[mod_2 + 116] = uint8(c2da_fresh25)
        c2da_mem[mod_2 + 117] = uint8(c2da_fresh25 >> 0x8)
        c2da_mem[mod_2 + 118] = uint8(c2da_fresh25 >> 0x10)
        c2da_mem[mod_2 + 119] = uint8(c2da_fresh25 >> 0x18)
        let c2da_fresh26 : float = uint_bits_to_float(uint(c2da_mem[bm + 12 + 0 * 4]) | uint(c2da_mem[bm + 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[bm + 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[bm + 12 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh27 : uint = float_bits_to_uint(c2da_fresh26)
        c2da_mem[mod_2 + 96 + 0 * 4] = uint8(c2da_fresh27)
        c2da_mem[mod_2 + 96 + 0 * 4 + 1] = uint8(c2da_fresh27 >> 0x8)
        c2da_mem[mod_2 + 96 + 0 * 4 + 2] = uint8(c2da_fresh27 >> 0x10)
        c2da_mem[mod_2 + 96 + 0 * 4 + 3] = uint8(c2da_fresh27 >> 0x18)
        let c2da_fresh28 : float = uint_bits_to_float(uint(c2da_mem[bm + 12 + 1 * 4]) | uint(c2da_mem[bm + 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[bm + 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[bm + 12 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh29 : uint = float_bits_to_uint(c2da_fresh28)
        c2da_mem[mod_2 + 96 + 1 * 4] = uint8(c2da_fresh29)
        c2da_mem[mod_2 + 96 + 1 * 4 + 1] = uint8(c2da_fresh29 >> 0x8)
        c2da_mem[mod_2 + 96 + 1 * 4 + 2] = uint8(c2da_fresh29 >> 0x10)
        c2da_mem[mod_2 + 96 + 1 * 4 + 3] = uint8(c2da_fresh29 >> 0x18)
        let c2da_fresh30 : float = uint_bits_to_float(uint(c2da_mem[bm + 12 + 2 * 4]) | uint(c2da_mem[bm + 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[bm + 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[bm + 12 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh31 : uint = float_bits_to_uint(c2da_fresh30)
        c2da_mem[mod_2 + 96 + 2 * 4] = uint8(c2da_fresh31)
        c2da_mem[mod_2 + 96 + 2 * 4 + 1] = uint8(c2da_fresh31 >> 0x8)
        c2da_mem[mod_2 + 96 + 2 * 4 + 2] = uint8(c2da_fresh31 >> 0x10)
        c2da_mem[mod_2 + 96 + 2 * 4 + 3] = uint8(c2da_fresh31 >> 0x18)
        let c2da_fresh32 : float = uint_bits_to_float(uint(c2da_mem[bm + 0 * 4]) | uint(c2da_mem[bm + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[bm + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[bm + 0 * 4 + 3]) << 0x18)
        let c2da_fresh33 : uint = float_bits_to_uint(c2da_fresh32)
        c2da_mem[mod_2 + 84 + 0 * 4] = uint8(c2da_fresh33)
        c2da_mem[mod_2 + 84 + 0 * 4 + 1] = uint8(c2da_fresh33 >> 0x8)
        c2da_mem[mod_2 + 84 + 0 * 4 + 2] = uint8(c2da_fresh33 >> 0x10)
        c2da_mem[mod_2 + 84 + 0 * 4 + 3] = uint8(c2da_fresh33 >> 0x18)
        let c2da_fresh34 : float = uint_bits_to_float(uint(c2da_mem[bm + 1 * 4]) | uint(c2da_mem[bm + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[bm + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[bm + 1 * 4 + 3]) << 0x18)
        let c2da_fresh35 : uint = float_bits_to_uint(c2da_fresh34)
        c2da_mem[mod_2 + 84 + 1 * 4] = uint8(c2da_fresh35)
        c2da_mem[mod_2 + 84 + 1 * 4 + 1] = uint8(c2da_fresh35 >> 0x8)
        c2da_mem[mod_2 + 84 + 1 * 4 + 2] = uint8(c2da_fresh35 >> 0x10)
        c2da_mem[mod_2 + 84 + 1 * 4 + 3] = uint8(c2da_fresh35 >> 0x18)
        let c2da_fresh36 : float = uint_bits_to_float(uint(c2da_mem[bm + 2 * 4]) | uint(c2da_mem[bm + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[bm + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[bm + 2 * 4 + 3]) << 0x18)
        let c2da_fresh37 : uint = float_bits_to_uint(c2da_fresh36)
        c2da_mem[mod_2 + 84 + 2 * 4] = uint8(c2da_fresh37)
        c2da_mem[mod_2 + 84 + 2 * 4 + 1] = uint8(c2da_fresh37 >> 0x8)
        c2da_mem[mod_2 + 84 + 2 * 4 + 2] = uint8(c2da_fresh37 >> 0x10)
        c2da_mem[mod_2 + 84 + 2 * 4 + 3] = uint8(c2da_fresh37 >> 0x18)
        let c2da_fresh38 : float = RadiusFromBounds(mod_2 + 84, mod_2 + 96)
        let c2da_fresh39 : uint = float_bits_to_uint(c2da_fresh38)
        c2da_mem[mod_2 + 108] = uint8(c2da_fresh39)
        c2da_mem[mod_2 + 109] = uint8(c2da_fresh39 >> 0x8)
        c2da_mem[mod_2 + 110] = uint8(c2da_fresh39 >> 0x10)
        c2da_mem[mod_2 + 111] = uint8(c2da_fresh39 >> 0x18)
        let c2da_fresh40 : int = int(uint(c2da_mem[bm + 52]) | uint(c2da_mem[bm + 53]) << 0x8 | uint(c2da_mem[bm + 54]) << 0x10 | uint(c2da_mem[bm + 55]) << 0x18)
        let c2da_fresh41 : uint = uint(c2da_fresh40)
        c2da_mem[mod_2 + 152] = uint8(c2da_fresh41)
        c2da_mem[mod_2 + 153] = uint8(c2da_fresh41 >> 0x8)
        c2da_mem[mod_2 + 154] = uint8(c2da_fresh41 >> 0x10)
        c2da_mem[mod_2 + 155] = uint8(c2da_fresh41 >> 0x18)
        if (i_0 < int(uint(c2da_mem[mod_2 + 120]) | uint(c2da_mem[mod_2 + 121]) << 0x8 | uint(c2da_mem[mod_2 + 122]) << 0x10 | uint(c2da_mem[mod_2 + 123]) << 0x18) - 1) {
            c2da_lin_snprintf(c2da_fp, 2147483647ul, 726111, [C2daVaArg(tag = 1, i64 = int64(i_0 + 1), f64 = 0.0lf, raw = 0x0)])
            loadmodel = Mod_FindName(c2da_fp)
            c2da_lin_memmove(loadmodel, mod_2, 536ul)
            c2da_lin_strcpy(loadmodel, c2da_fp)
            mod_2 = int(loadmodel)  // nolint:PERF020
        }
        i_0++
    }
    return
}
[sideeffects]
def private RadiusFromBounds_c2da_frame(var mins : int; var maxs : int; c2da_fp : int) : float {
    for (i_2 in range(0, 3)) {
        let c2da_fresh44 : float = float(c2da_std_fabs(double(uint_bits_to_float(uint(c2da_mem[mins + i_2 * 4]) | uint(c2da_mem[mins + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[mins + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[mins + i_2 * 4 + 3]) << 0x18))) > c2da_std_fabs(double(uint_bits_to_float(uint(c2da_mem[maxs + i_2 * 4]) | uint(c2da_mem[maxs + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs + i_2 * 4 + 3]) << 0x18))) ? c2da_std_fabs(double(uint_bits_to_float(uint(c2da_mem[mins + i_2 * 4]) | uint(c2da_mem[mins + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[mins + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[mins + i_2 * 4 + 3]) << 0x18))) : c2da_std_fabs(double(uint_bits_to_float(uint(c2da_mem[maxs + i_2 * 4]) | uint(c2da_mem[maxs + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs + i_2 * 4 + 3]) << 0x18))))
        let c2da_fresh45 : uint = float_bits_to_uint(c2da_fresh44)
        c2da_mem[c2da_fp + i_2 * 4] = uint8(c2da_fresh45)
        c2da_mem[c2da_fp + i_2 * 4 + 1] = uint8(c2da_fresh45 >> 0x8)
        c2da_mem[c2da_fp + i_2 * 4 + 2] = uint8(c2da_fresh45 >> 0x10)
        c2da_mem[c2da_fp + i_2 * 4 + 3] = uint8(c2da_fresh45 >> 0x18)
    }
    return Length(c2da_fp)
}
[sideeffects]
def private Mod_LoadTextures_c2da_frame(var l_10 : int; c2da_fp : int) {
    var i_13 : int
    var j_8 : int
    var pixels : int
    var num : int
    var max : int
    var altmax : int
    var mt : int
    var tx : int
    var tx2 : int
    var m : int
    if (int(uint(c2da_mem[l_10 + 4]) | uint(c2da_mem[l_10 + 5]) << 0x8 | uint(c2da_mem[l_10 + 6]) << 0x10 | uint(c2da_mem[l_10 + 7]) << 0x18) == 0) {
        let c2da_fresh235 : uint = 0u
        c2da_mem[loadmodel + 496] = uint8(c2da_fresh235)
        c2da_mem[loadmodel + 497] = uint8(c2da_fresh235 >> 0x8)
        c2da_mem[loadmodel + 498] = uint8(c2da_fresh235 >> 0x10)
        c2da_mem[loadmodel + 499] = uint8(c2da_fresh235 >> 0x18)
        c2da_mem[loadmodel + 500] = 0u8
        c2da_mem[loadmodel + 501] = 0u8
        c2da_mem[loadmodel + 502] = 0u8
        c2da_mem[loadmodel + 503] = 0u8
        return
    }
    m = mod_base + int(uint(c2da_mem[l_10]) | uint(c2da_mem[l_10 + 1]) << 0x8 | uint(c2da_mem[l_10 + 2]) << 0x10 | uint(c2da_mem[l_10 + 3]) << 0x18)
    let c2da_fresh236 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[m]) | uint(c2da_mem[m + 1]) << 0x8 | uint(c2da_mem[m + 2]) << 0x10 | uint(c2da_mem[m + 3]) << 0x18))
    let c2da_fresh237 : uint = uint(c2da_fresh236)
    c2da_mem[m] = uint8(c2da_fresh237)
    c2da_mem[m + 1] = uint8(c2da_fresh237 >> 0x8)
    c2da_mem[m + 2] = uint8(c2da_fresh237 >> 0x10)
    c2da_mem[m + 3] = uint8(c2da_fresh237 >> 0x18)
    let c2da_fresh238 : int = int(uint(c2da_mem[m]) | uint(c2da_mem[m + 1]) << 0x8 | uint(c2da_mem[m + 2]) << 0x10 | uint(c2da_mem[m + 3]) << 0x18)
    let c2da_fresh239 : uint = uint(c2da_fresh238)
    c2da_mem[loadmodel + 488] = uint8(c2da_fresh239)
    c2da_mem[loadmodel + 489] = uint8(c2da_fresh239 >> 0x8)
    c2da_mem[loadmodel + 490] = uint8(c2da_fresh239 >> 0x10)
    c2da_mem[loadmodel + 491] = uint8(c2da_fresh239 >> 0x18)
    let c2da_fresh240 : int = Hunk_AllocName(int(uint64(int(uint(c2da_mem[m]) | uint(c2da_mem[m + 1]) << 0x8 | uint(c2da_mem[m + 2]) << 0x10 | uint(c2da_mem[m + 3]) << 0x18)) * 8ul), 386384)
    let c2da_fresh241 : uint = uint(c2da_fresh240)
    c2da_mem[loadmodel + 496] = uint8(c2da_fresh241)
    c2da_mem[loadmodel + 497] = uint8(c2da_fresh241 >> 0x8)
    c2da_mem[loadmodel + 498] = uint8(c2da_fresh241 >> 0x10)
    c2da_mem[loadmodel + 499] = uint8(c2da_fresh241 >> 0x18)
    c2da_mem[loadmodel + 500] = 0u8
    c2da_mem[loadmodel + 501] = 0u8
    c2da_mem[loadmodel + 502] = 0u8
    c2da_mem[loadmodel + 503] = 0u8
    i_13 = 0
    while (i_13 < int(uint(c2da_mem[m]) | uint(c2da_mem[m + 1]) << 0x8 | uint(c2da_mem[m + 2]) << 0x10 | uint(c2da_mem[m + 3]) << 0x18)) {
        let c2da_fresh242 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[m + 4 + i_13 * 4]) | uint(c2da_mem[m + 4 + i_13 * 4 + 1]) << 0x8 | uint(c2da_mem[m + 4 + i_13 * 4 + 2]) << 0x10 | uint(c2da_mem[m + 4 + i_13 * 4 + 3]) << 0x18))
        let c2da_fresh243 : uint = uint(c2da_fresh242)
        c2da_mem[m + 4 + i_13 * 4] = uint8(c2da_fresh243)
        c2da_mem[m + 4 + i_13 * 4 + 1] = uint8(c2da_fresh243 >> 0x8)
        c2da_mem[m + 4 + i_13 * 4 + 2] = uint8(c2da_fresh243 >> 0x10)
        c2da_mem[m + 4 + i_13 * 4 + 3] = uint8(c2da_fresh243 >> 0x18)
        if (int(uint(c2da_mem[m + 4 + i_13 * 4]) | uint(c2da_mem[m + 4 + i_13 * 4 + 1]) << 0x8 | uint(c2da_mem[m + 4 + i_13 * 4 + 2]) << 0x10 | uint(c2da_mem[m + 4 + i_13 * 4 + 3]) << 0x18) == -1) {
            i_13++
            continue
        }
        mt = m + int(uint(c2da_mem[m + 4 + i_13 * 4]) | uint(c2da_mem[m + 4 + i_13 * 4 + 1]) << 0x8 | uint(c2da_mem[m + 4 + i_13 * 4 + 2]) << 0x10 | uint(c2da_mem[m + 4 + i_13 * 4 + 3]) << 0x18)
        let c2da_fresh244 : uint = uint(invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[mt + 16]) | uint(c2da_mem[mt + 17]) << 0x8 | uint(c2da_mem[mt + 18]) << 0x10 | uint(c2da_mem[mt + 19]) << 0x18)))
        let c2da_fresh245 : uint = c2da_fresh244
        c2da_mem[mt + 16] = uint8(c2da_fresh245)
        c2da_mem[mt + 17] = uint8(c2da_fresh245 >> 0x8)
        c2da_mem[mt + 18] = uint8(c2da_fresh245 >> 0x10)
        c2da_mem[mt + 19] = uint8(c2da_fresh245 >> 0x18)
        let c2da_fresh246 : uint = uint(invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[mt + 20]) | uint(c2da_mem[mt + 21]) << 0x8 | uint(c2da_mem[mt + 22]) << 0x10 | uint(c2da_mem[mt + 23]) << 0x18)))
        let c2da_fresh247 : uint = c2da_fresh246
        c2da_mem[mt + 20] = uint8(c2da_fresh247)
        c2da_mem[mt + 21] = uint8(c2da_fresh247 >> 0x8)
        c2da_mem[mt + 22] = uint8(c2da_fresh247 >> 0x10)
        c2da_mem[mt + 23] = uint8(c2da_fresh247 >> 0x18)
        j_8 = 0
        while (j_8 < 4) {
            let c2da_fresh248 : uint = uint(invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[mt + 24 + j_8 * 4]) | uint(c2da_mem[mt + 24 + j_8 * 4 + 1]) << 0x8 | uint(c2da_mem[mt + 24 + j_8 * 4 + 2]) << 0x10 | uint(c2da_mem[mt + 24 + j_8 * 4 + 3]) << 0x18)))
            let c2da_fresh249 : uint = c2da_fresh248
            c2da_mem[mt + 24 + j_8 * 4] = uint8(c2da_fresh249)
            c2da_mem[mt + 24 + j_8 * 4 + 1] = uint8(c2da_fresh249 >> 0x8)
            c2da_mem[mt + 24 + j_8 * 4 + 2] = uint8(c2da_fresh249 >> 0x10)
            c2da_mem[mt + 24 + j_8 * 4 + 3] = uint8(c2da_fresh249 >> 0x18)
            j_8++
        }
        if (((uint(c2da_mem[mt + 16]) | uint(c2da_mem[mt + 17]) << 0x8 | uint(c2da_mem[mt + 18]) << 0x10 | uint(c2da_mem[mt + 19]) << 0x18) & 15u) != 0x0 || ((uint(c2da_mem[mt + 20]) | uint(c2da_mem[mt + 21]) << 0x8 | uint(c2da_mem[mt + 22]) << 0x10 | uint(c2da_mem[mt + 23]) << 0x18) & 15u) != 0x0) {
            Sys_Error(726307, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(mt))])
        }
        pixels = int((uint(c2da_mem[mt + 16]) | uint(c2da_mem[mt + 17]) << 0x8 | uint(c2da_mem[mt + 18]) << 0x10 | uint(c2da_mem[mt + 19]) << 0x18) * (uint(c2da_mem[mt + 20]) | uint(c2da_mem[mt + 21]) << 0x8 | uint(c2da_mem[mt + 22]) << 0x10 | uint(c2da_mem[mt + 23]) << 0x18) / 64u * 85u)
        tx = Hunk_AllocName(int(72ul + uint64(pixels)), 386384)
        let c2da_fresh250 : int = int(uint(c2da_mem[loadmodel + 496]) | uint(c2da_mem[loadmodel + 497]) << 0x8 | uint(c2da_mem[loadmodel + 498]) << 0x10 | uint(c2da_mem[loadmodel + 499]) << 0x18) + i_13 * 8
        let c2da_fresh251 : uint = uint(tx)
        c2da_mem[c2da_fresh250] = uint8(c2da_fresh251)
        c2da_mem[c2da_fresh250 + 1] = uint8(c2da_fresh251 >> 0x8)
        c2da_mem[c2da_fresh250 + 2] = uint8(c2da_fresh251 >> 0x10)
        c2da_mem[c2da_fresh250 + 3] = uint8(c2da_fresh251 >> 0x18)
        c2da_mem[c2da_fresh250 + 4] = 0u8
        c2da_mem[c2da_fresh250 + 5] = 0u8
        c2da_mem[c2da_fresh250 + 6] = 0u8
        c2da_mem[c2da_fresh250 + 7] = 0u8
        c2da_lin_memcpy(tx, mt, 16ul)
        let c2da_fresh252 : uint = uint(c2da_mem[mt + 16]) | uint(c2da_mem[mt + 17]) << 0x8 | uint(c2da_mem[mt + 18]) << 0x10 | uint(c2da_mem[mt + 19]) << 0x18
        let c2da_fresh253 : uint = c2da_fresh252
        c2da_mem[tx + 16] = uint8(c2da_fresh253)
        c2da_mem[tx + 17] = uint8(c2da_fresh253 >> 0x8)
        c2da_mem[tx + 18] = uint8(c2da_fresh253 >> 0x10)
        c2da_mem[tx + 19] = uint8(c2da_fresh253 >> 0x18)
        let c2da_fresh254 : uint = uint(c2da_mem[mt + 20]) | uint(c2da_mem[mt + 21]) << 0x8 | uint(c2da_mem[mt + 22]) << 0x10 | uint(c2da_mem[mt + 23]) << 0x18
        let c2da_fresh255 : uint = c2da_fresh254
        c2da_mem[tx + 20] = uint8(c2da_fresh255)
        c2da_mem[tx + 21] = uint8(c2da_fresh255 >> 0x8)
        c2da_mem[tx + 22] = uint8(c2da_fresh255 >> 0x10)
        c2da_mem[tx + 23] = uint8(c2da_fresh255 >> 0x18)
        j_8 = 0
        while (j_8 < 4) {
            let c2da_fresh256 : uint = uint(uint64(uint(c2da_mem[mt + 24 + j_8 * 4]) | uint(c2da_mem[mt + 24 + j_8 * 4 + 1]) << 0x8 | uint(c2da_mem[mt + 24 + j_8 * 4 + 2]) << 0x10 | uint(c2da_mem[mt + 24 + j_8 * 4 + 3]) << 0x18) + 72ul - 40ul)
            let c2da_fresh257 : uint = c2da_fresh256
            c2da_mem[tx + 56 + j_8 * 4] = uint8(c2da_fresh257)
            c2da_mem[tx + 56 + j_8 * 4 + 1] = uint8(c2da_fresh257 >> 0x8)
            c2da_mem[tx + 56 + j_8 * 4 + 2] = uint8(c2da_fresh257 >> 0x10)
            c2da_mem[tx + 56 + j_8 * 4 + 3] = uint8(c2da_fresh257 >> 0x18)
            j_8++
        }
        c2da_lin_memcpy(tx + 1 * 72, mt + 1 * 40, uint64(pixels))
        if (Q_strncmp(mt, 726248, 3) == 0) {
            R_InitSky(tx)
        }
        i_13++
    }
    i_13 = 0
    while (i_13 < int(uint(c2da_mem[m]) | uint(c2da_mem[m + 1]) << 0x8 | uint(c2da_mem[m + 2]) << 0x10 | uint(c2da_mem[m + 3]) << 0x18)) {
        let c2da_fresh258 : int = int(uint(c2da_mem[loadmodel + 496]) | uint(c2da_mem[loadmodel + 497]) << 0x8 | uint(c2da_mem[loadmodel + 498]) << 0x10 | uint(c2da_mem[loadmodel + 499]) << 0x18) + i_13 * 8
        tx = int(uint(c2da_mem[c2da_fresh258]) | uint(c2da_mem[c2da_fresh258 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh258 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh258 + 3]) << 0x18)
        if (tx == 0 || int(int8(c2da_mem[tx + 0])) != 43) {
            i_13++
            continue
        }
        if (int(uint(c2da_mem[tx + 40]) | uint(c2da_mem[tx + 41]) << 0x8 | uint(c2da_mem[tx + 42]) << 0x10 | uint(c2da_mem[tx + 43]) << 0x18) != 0) {
            i_13++
            continue
        }
        c2da_lin_memset(c2da_fp, 0, 80ul)
        c2da_lin_memset(c2da_fp + 80, 0, 80ul)
        max = int(int8(c2da_mem[tx + 1]))
        altmax = 0
        if (max >= 97 && max <= 122) {
            max -= 97 - 65
        }
        if (max >= 48 && max <= 57) {
            max -= 48
            altmax = 0
            let c2da_fresh259 : uint = uint(tx)
            c2da_mem[c2da_fp + max * 8] = uint8(c2da_fresh259)
            c2da_mem[c2da_fp + max * 8 + 1] = uint8(c2da_fresh259 >> 0x8)
            c2da_mem[c2da_fp + max * 8 + 2] = uint8(c2da_fresh259 >> 0x10)
            c2da_mem[c2da_fp + max * 8 + 3] = uint8(c2da_fresh259 >> 0x18)
            c2da_mem[c2da_fp + max * 8 + 4] = 0u8
            c2da_mem[c2da_fp + max * 8 + 5] = 0u8
            c2da_mem[c2da_fp + max * 8 + 6] = 0u8
            c2da_mem[c2da_fp + max * 8 + 7] = 0u8
            max++
        } elif (max >= 65 && max <= 74) {
            altmax = max - 65
            max = 0
            let c2da_fresh260 : uint = uint(tx)
            c2da_mem[c2da_fp + 80 + altmax * 8] = uint8(c2da_fresh260)
            c2da_mem[c2da_fp + 80 + altmax * 8 + 1] = uint8(c2da_fresh260 >> 0x8)
            c2da_mem[c2da_fp + 80 + altmax * 8 + 2] = uint8(c2da_fresh260 >> 0x10)
            c2da_mem[c2da_fp + 80 + altmax * 8 + 3] = uint8(c2da_fresh260 >> 0x18)
            c2da_mem[c2da_fp + 80 + altmax * 8 + 4] = 0u8
            c2da_mem[c2da_fp + 80 + altmax * 8 + 5] = 0u8
            c2da_mem[c2da_fp + 80 + altmax * 8 + 6] = 0u8
            c2da_mem[c2da_fp + 80 + altmax * 8 + 7] = 0u8
            altmax++
        } else {
            Sys_Error(726336, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(tx))])
        }
        j_8 = i_13 + 1
        while (j_8 < int(uint(c2da_mem[m]) | uint(c2da_mem[m + 1]) << 0x8 | uint(c2da_mem[m + 2]) << 0x10 | uint(c2da_mem[m + 3]) << 0x18)) {
            let c2da_fresh261 : int = int(uint(c2da_mem[loadmodel + 496]) | uint(c2da_mem[loadmodel + 497]) << 0x8 | uint(c2da_mem[loadmodel + 498]) << 0x10 | uint(c2da_mem[loadmodel + 499]) << 0x18) + j_8 * 8
            tx2 = int(uint(c2da_mem[c2da_fresh261]) | uint(c2da_mem[c2da_fresh261 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh261 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh261 + 3]) << 0x18)
            if (tx2 == 0 || int(int8(c2da_mem[tx2 + 0])) != 43) {
                j_8++
                continue
            }
            if (c2da_lin_strcmp(tx2 + 2, tx + 2) != 0) {
                j_8++
                continue
            }
            num = int(int8(c2da_mem[tx2 + 1]))
            if (num >= 97 && num <= 122) {
                num -= 97 - 65
            }
            if (num >= 48 && num <= 57) {
                num -= 48
                let c2da_fresh262 : uint = uint(tx2)
                c2da_mem[c2da_fp + num * 8] = uint8(c2da_fresh262)
                c2da_mem[c2da_fp + num * 8 + 1] = uint8(c2da_fresh262 >> 0x8)
                c2da_mem[c2da_fp + num * 8 + 2] = uint8(c2da_fresh262 >> 0x10)
                c2da_mem[c2da_fp + num * 8 + 3] = uint8(c2da_fresh262 >> 0x18)
                c2da_mem[c2da_fp + num * 8 + 4] = 0u8
                c2da_mem[c2da_fp + num * 8 + 5] = 0u8
                c2da_mem[c2da_fp + num * 8 + 6] = 0u8
                c2da_mem[c2da_fp + num * 8 + 7] = 0u8
                if (num + 1 > max) {
                    max = num + 1
                }
            } elif (num >= 65 && num <= 74) {
                num -= 65
                let c2da_fresh263 : uint = uint(tx2)
                c2da_mem[c2da_fp + 80 + num * 8] = uint8(c2da_fresh263)
                c2da_mem[c2da_fp + 80 + num * 8 + 1] = uint8(c2da_fresh263 >> 0x8)
                c2da_mem[c2da_fp + 80 + num * 8 + 2] = uint8(c2da_fresh263 >> 0x10)
                c2da_mem[c2da_fp + 80 + num * 8 + 3] = uint8(c2da_fresh263 >> 0x18)
                c2da_mem[c2da_fp + 80 + num * 8 + 4] = 0u8
                c2da_mem[c2da_fp + 80 + num * 8 + 5] = 0u8
                c2da_mem[c2da_fp + 80 + num * 8 + 6] = 0u8
                c2da_mem[c2da_fp + 80 + num * 8 + 7] = 0u8
                if (num + 1 > altmax) {
                    altmax = num + 1
                }
            } else {
                Sys_Error(726336, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(tx))])
            }
            j_8++
        }
        j_8 = 0
        while (j_8 < max) {
            tx2 = int(uint(c2da_mem[c2da_fp + j_8 * 8]) | uint(c2da_mem[c2da_fp + j_8 * 8 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + j_8 * 8 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + j_8 * 8 + 3]) << 0x18)
            if (tx2 == 0) {
                Sys_Error(726361, [C2daVaArg(tag = 1, i64 = int64(j_8), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(tx))])
            }
            let c2da_fresh264 : int = max * 2
            let c2da_fresh265 : uint = uint(c2da_fresh264)
            c2da_mem[tx2 + 24] = uint8(c2da_fresh265)
            c2da_mem[tx2 + 25] = uint8(c2da_fresh265 >> 0x8)
            c2da_mem[tx2 + 26] = uint8(c2da_fresh265 >> 0x10)
            c2da_mem[tx2 + 27] = uint8(c2da_fresh265 >> 0x18)
            let c2da_fresh266 : int = j_8 * 2
            let c2da_fresh267 : uint = uint(c2da_fresh266)
            c2da_mem[tx2 + 28] = uint8(c2da_fresh267)
            c2da_mem[tx2 + 29] = uint8(c2da_fresh267 >> 0x8)
            c2da_mem[tx2 + 30] = uint8(c2da_fresh267 >> 0x10)
            c2da_mem[tx2 + 31] = uint8(c2da_fresh267 >> 0x18)
            let c2da_fresh268 : int = (j_8 + 1) * 2
            let c2da_fresh269 : uint = uint(c2da_fresh268)
            c2da_mem[tx2 + 32] = uint8(c2da_fresh269)
            c2da_mem[tx2 + 33] = uint8(c2da_fresh269 >> 0x8)
            c2da_mem[tx2 + 34] = uint8(c2da_fresh269 >> 0x10)
            c2da_mem[tx2 + 35] = uint8(c2da_fresh269 >> 0x18)
            let c2da_fresh270 : int = c2da_fp + (j_8 + 1) % max * 8
            let c2da_fresh271 : int = int(uint(c2da_mem[c2da_fresh270]) | uint(c2da_mem[c2da_fresh270 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh270 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh270 + 3]) << 0x18)
            let c2da_fresh272 : uint = uint(c2da_fresh271)
            c2da_mem[tx2 + 40] = uint8(c2da_fresh272)
            c2da_mem[tx2 + 41] = uint8(c2da_fresh272 >> 0x8)
            c2da_mem[tx2 + 42] = uint8(c2da_fresh272 >> 0x10)
            c2da_mem[tx2 + 43] = uint8(c2da_fresh272 >> 0x18)
            c2da_mem[tx2 + 44] = 0u8
            c2da_mem[tx2 + 45] = 0u8
            c2da_mem[tx2 + 46] = 0u8
            c2da_mem[tx2 + 47] = 0u8
            if (altmax != 0) {
                let c2da_fresh273 : int = int(uint(c2da_mem[c2da_fp + 80 + 0 * 8]) | uint(c2da_mem[c2da_fp + 80 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 80 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 80 + 0 * 8 + 3]) << 0x18)
                let c2da_fresh274 : uint = uint(c2da_fresh273)
                c2da_mem[tx2 + 48] = uint8(c2da_fresh274)
                c2da_mem[tx2 + 49] = uint8(c2da_fresh274 >> 0x8)
                c2da_mem[tx2 + 50] = uint8(c2da_fresh274 >> 0x10)
                c2da_mem[tx2 + 51] = uint8(c2da_fresh274 >> 0x18)
                c2da_mem[tx2 + 52] = 0u8
                c2da_mem[tx2 + 53] = 0u8
                c2da_mem[tx2 + 54] = 0u8
                c2da_mem[tx2 + 55] = 0u8
            }
            j_8++
        }
        j_8 = 0
        while (j_8 < altmax) {
            tx2 = int(uint(c2da_mem[c2da_fp + 80 + j_8 * 8]) | uint(c2da_mem[c2da_fp + 80 + j_8 * 8 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 80 + j_8 * 8 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 80 + j_8 * 8 + 3]) << 0x18)
            if (tx2 == 0) {
                Sys_Error(726361, [C2daVaArg(tag = 1, i64 = int64(j_8), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(tx))])
            }
            let c2da_fresh275 : int = altmax * 2
            let c2da_fresh276 : uint = uint(c2da_fresh275)
            c2da_mem[tx2 + 24] = uint8(c2da_fresh276)
            c2da_mem[tx2 + 25] = uint8(c2da_fresh276 >> 0x8)
            c2da_mem[tx2 + 26] = uint8(c2da_fresh276 >> 0x10)
            c2da_mem[tx2 + 27] = uint8(c2da_fresh276 >> 0x18)
            let c2da_fresh277 : int = j_8 * 2
            let c2da_fresh278 : uint = uint(c2da_fresh277)
            c2da_mem[tx2 + 28] = uint8(c2da_fresh278)
            c2da_mem[tx2 + 29] = uint8(c2da_fresh278 >> 0x8)
            c2da_mem[tx2 + 30] = uint8(c2da_fresh278 >> 0x10)
            c2da_mem[tx2 + 31] = uint8(c2da_fresh278 >> 0x18)
            let c2da_fresh279 : int = (j_8 + 1) * 2
            let c2da_fresh280 : uint = uint(c2da_fresh279)
            c2da_mem[tx2 + 32] = uint8(c2da_fresh280)
            c2da_mem[tx2 + 33] = uint8(c2da_fresh280 >> 0x8)
            c2da_mem[tx2 + 34] = uint8(c2da_fresh280 >> 0x10)
            c2da_mem[tx2 + 35] = uint8(c2da_fresh280 >> 0x18)
            let c2da_fresh281 : int = c2da_fp + 80 + (j_8 + 1) % altmax * 8
            let c2da_fresh282 : int = int(uint(c2da_mem[c2da_fresh281]) | uint(c2da_mem[c2da_fresh281 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh281 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh281 + 3]) << 0x18)
            let c2da_fresh283 : uint = uint(c2da_fresh282)
            c2da_mem[tx2 + 40] = uint8(c2da_fresh283)
            c2da_mem[tx2 + 41] = uint8(c2da_fresh283 >> 0x8)
            c2da_mem[tx2 + 42] = uint8(c2da_fresh283 >> 0x10)
            c2da_mem[tx2 + 43] = uint8(c2da_fresh283 >> 0x18)
            c2da_mem[tx2 + 44] = 0u8
            c2da_mem[tx2 + 45] = 0u8
            c2da_mem[tx2 + 46] = 0u8
            c2da_mem[tx2 + 47] = 0u8
            if (max != 0) {
                let c2da_fresh284 : int = int(uint(c2da_mem[c2da_fp + 0 * 8]) | uint(c2da_mem[c2da_fp + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 8 + 3]) << 0x18)
                let c2da_fresh285 : uint = uint(c2da_fresh284)
                c2da_mem[tx2 + 48] = uint8(c2da_fresh285)
                c2da_mem[tx2 + 49] = uint8(c2da_fresh285 >> 0x8)
                c2da_mem[tx2 + 50] = uint8(c2da_fresh285 >> 0x10)
                c2da_mem[tx2 + 51] = uint8(c2da_fresh285 >> 0x18)
                c2da_mem[tx2 + 52] = 0u8
                c2da_mem[tx2 + 53] = 0u8
                c2da_mem[tx2 + 54] = 0u8
                c2da_mem[tx2 + 55] = 0u8
            }
            j_8++
        }
        i_13++
    }
    return
}

// This unit's static data, at heap offset 724992.
let private c2da_lin_static_model_seg = fixed_array<int>(726016, 910)
let private c2da_lin_static_model = fixed_array<uint64>(0x466d754e5f646f4dul, 0x203a656d614e726ful, 0x6620746f6e207325ul, 0x646f4d00646e756ful, 0x75724264616f4c5ful, 0x3a6c65646f4d6873ul, 0x2073616820732520ul, 0x657620676e6f7277ul, 0x756e206e6f697372ul, 0x692528207265626dul, 0x20646c756f687320ul, 0x2a00296925206562ul, 0x465f646f4d006925ul, 0x203a656d614e726ful, 0x6d616e204c4c554eul, 0x756e5f646f6d0065ul, 0x3d206e776f6e6b6dul, 0x4f4d5f58414d203dul, 0x4e574f4e4b5f44ul, 0x64616f4c5f444f4dul, 0x203a6c65646f6d42ul, 0x756c20796e6e7566ul, 0x20657a697320706dul, 0x6f4d007325206e69ul, 0x4d65737261505f64ul, 0x61667275736b7261ul, 0x646162203a736563ul, 0x6563616672757320ul, 0x7265626d756e20ul, 0x6142002a00796b73ul, 0x6361667275732064ul, 0x746e657478652065ul, 0x78657470696d0073ul, 0x64616f6c203d3e20ul, 0x6e3e2d6c65646f6dul, 0x7275747865746d75ul, 0x7574786554007365ul, 0x7369207325206572ul, 0x20363120746f6e20ul, 0x64656e67696c61ul, 0x6d696e6120646142ul, 0x657420676e697461ul, 0x7325206572757478ul, 0x676e697373694d00ul, 0x2520656d61726620ul, 0x732520666f2069ul, 0x7720736168207325ul, 0x72657620676e6f72ul, 0x6d756e206e6f6973ul, 0x2069252820726562ul, 0x6220646c756f6873ul, 0x6f4d002969252065ul, 0x705364616f4c5f64ul, 0x65646f4d65746972ul, 0x6c61766e49203a6cul, 0x20666f2023206469ul, 0x203a73656d617266ul, 0x5f646f4d000a6425ul, 0x6972705364616f4cul, 0x3a70756f72476574ul, 0x61767265746e6920ul, 0x646f6d00303d3c6cul, 0x6168207325206c65ul, 0x6e696b7320612073ul, 0x2072656c6c617420ul, 0x6425206e616874ul, 0x7325206c65646f6dul, 0x206f6e2073616820ul, 0x7365636974726576ul, 0x25206c65646f6d00ul, 0x6f74207361682073ul, 0x7620796e616d206ful, 0x73656369747265ul, 0x7325206c65646f6dul, 0x206f6e2073616820ul, 0x656c676e61697274ul, 0x6f4c5f646f4d0073ul, 0x4d7361696c416461ul, 0x6b73203a6c65646ful, 0x2068746469776e69ul, 0x746c756d20746f6eul, 0x20666f20656c7069ul, 0x6f4c5f646f4d0034ul, 0x4d7361696c416461ul, 0x6e49203a6c65646ful, 0x20232064696c6176ul, 0x736e696b7320666ful, 0x6f4d000a6425203aul, 0x6c4164616f4c5f64ul, 0x6c65646f4d736169ul, 0x696c61766e49203aul, 0x6620666f20232064ul, 0x25203a73656d6172ul, 0x4c5f646f4d000a64ul, 0x7361696c4164616ful, 0x69203a70756f7247ul, 0x3c6c61767265746eul, 0x4c5f646f4d00303dul, 0x7361696c4164616ful, 0x756f72476e696b53ul, 0x7265746e69203a70ul, 0x4d00303d3c6c6176ul, 0x61727478455f646ful, 0x6163203a61746164ul, 0x616620676e696863ul, 0x646f4d0064656c69ul, 0x6e49746e696f505ful, 0x6162203a6661654cul, 0x6c65646f6d2064ul, 0x6d20646568636143ul, 0xa3a736c65646ful, 0x7325203a20703825ul, 0x2000295221282000ul, 0xa0029502128ul)

[init]
def private c2da_lin_init_static_model() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_model_seg[s * 2]
        for (k in range(c2da_lin_static_model_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_model[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_model() {
    if (length(c2da_fn_table0) < 95) {
        resize(c2da_fn_table0, 95)
    }
    c2da_fn_table0[94] = @@Mod_Print
}

[init]
def private c2da_lin_relink_init_model() {
    c2da_relink_model()
}
