var wad_numlumps : int = default<int>

var wad_lumps : int = default<int>

var wad_base : int = default<int>

[export, sideeffects]
def W_LoadWadFile(var filename : int) {
    var lump_p : int
    var header : int
    var i : uint
    var infotableofs : int
    wad_base = COM_LoadHunkFile(filename)
    if (wad_base == 0) {
        Sys_Error(737728, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(filename))])
    }
    header = wad_base
    if (int(int8(c2da_mem[header + 0])) != 87 || int(int8(c2da_mem[header + 1])) != 65 || int(int8(c2da_mem[header + 2])) != 68 || int(int8(c2da_mem[header + 3])) != 50) {
        Sys_Error(737760, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(filename))])
    }
    wad_numlumps = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[header + 4]) | uint(c2da_mem[header + 5]) << 0x8 | uint(c2da_mem[header + 6]) << 0x10 | uint(c2da_mem[header + 7]) << 0x18))
    infotableofs = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[header + 8]) | uint(c2da_mem[header + 9]) << 0x8 | uint(c2da_mem[header + 10]) << 0x10 | uint(c2da_mem[header + 11]) << 0x18))
    wad_lumps = wad_base + infotableofs
    i = 0u
    lump_p = wad_lumps
    while (i < uint(wad_numlumps)) {
        let c2da_fresh0 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[lump_p]) | uint(c2da_mem[lump_p + 1]) << 0x8 | uint(c2da_mem[lump_p + 2]) << 0x10 | uint(c2da_mem[lump_p + 3]) << 0x18))
        let c2da_fresh1 : uint = uint(c2da_fresh0)
        c2da_mem[lump_p] = uint8(c2da_fresh1)
        c2da_mem[lump_p + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[lump_p + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[lump_p + 3] = uint8(c2da_fresh1 >> 0x18)
        let c2da_fresh2 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[lump_p + 8]) | uint(c2da_mem[lump_p + 9]) << 0x8 | uint(c2da_mem[lump_p + 10]) << 0x10 | uint(c2da_mem[lump_p + 11]) << 0x18))
        let c2da_fresh3 : uint = uint(c2da_fresh2)
        c2da_mem[lump_p + 8] = uint8(c2da_fresh3)
        c2da_mem[lump_p + 9] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[lump_p + 10] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[lump_p + 11] = uint8(c2da_fresh3 >> 0x18)
        W_CleanupName(lump_p + 16, lump_p + 16)
        if (int(int8(c2da_mem[lump_p + 12])) == 66) {
            SwapPic(wad_base + int(uint(c2da_mem[lump_p]) | uint(c2da_mem[lump_p + 1]) << 0x8 | uint(c2da_mem[lump_p + 2]) << 0x10 | uint(c2da_mem[lump_p + 3]) << 0x18))
        }
        i++
        lump_p += 32
    }
    return
}
[export, sideeffects]
def SwapPic(var pic : int) {
    let c2da_fresh4 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pic]) | uint(c2da_mem[pic + 1]) << 0x8 | uint(c2da_mem[pic + 2]) << 0x10 | uint(c2da_mem[pic + 3]) << 0x18))
    let c2da_fresh5 : uint = uint(c2da_fresh4)
    c2da_mem[pic] = uint8(c2da_fresh5)
    c2da_mem[pic + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[pic + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[pic + 3] = uint8(c2da_fresh5 >> 0x18)
    let c2da_fresh6 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pic + 4]) | uint(c2da_mem[pic + 5]) << 0x8 | uint(c2da_mem[pic + 6]) << 0x10 | uint(c2da_mem[pic + 7]) << 0x18))
    let c2da_fresh7 : uint = uint(c2da_fresh6)
    c2da_mem[pic + 4] = uint8(c2da_fresh7)
    c2da_mem[pic + 5] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[pic + 6] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[pic + 7] = uint8(c2da_fresh7 >> 0x18)
    return
}
[export, sideeffects]
def W_CleanupName(var in_0 : int; var out : int) {
    var i_0 : int
    var c : int
    i_0 = 0
    while (i_0 < 16) {
        c = int(int8(c2da_mem[in_0 + i_0]))
        if (c == 0) {
            break
        }
        if (c >= 65 && c <= 90) {
            c += 97 - 65
        }
        let c2da_fresh8 : int8 = int8(c)
        c2da_mem[out + i_0] = uint8(c2da_fresh8)
        i_0++
    }
    for (c2da_i_0 in range(i_0, 16)) {
        let c2da_fresh9 : int8 = int8(0)
        c2da_mem[out + c2da_i_0] = uint8(c2da_fresh9)
    }
    return
}
[export, sideeffects]
def W_GetLumpinfo(var name : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = W_GetLumpinfo_c2da_frame(name, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def W_GetLumpName(var name_0 : int) : int {
    var lump : int = W_GetLumpinfo(name_0)
    return wad_base + int(uint(c2da_mem[lump]) | uint(c2da_mem[lump + 1]) << 0x8 | uint(c2da_mem[lump + 2]) << 0x10 | uint(c2da_mem[lump + 3]) << 0x18)
}
[export, sideeffects]
def W_GetLumpNum(var num : int) : int {
    if (num < 0 || num > wad_numlumps) {
        Sys_Error(737822, [C2daVaArg(tag = 1, i64 = int64(num), f64 = 0.0lf, raw = 0x0)])
    }
    return wad_base + int(uint(c2da_mem[wad_lumps + num * 32]) | uint(c2da_mem[wad_lumps + num * 32 + 1]) << 0x8 | uint(c2da_mem[wad_lumps + num * 32 + 2]) << 0x10 | uint(c2da_mem[wad_lumps + num * 32 + 3]) << 0x18)
}
[sideeffects]
def private W_GetLumpinfo_c2da_frame(var name : int; c2da_fp : int) : int {
    var i_1 : int
    var lump_p_0 : int
    W_CleanupName(name, c2da_fp)
    lump_p_0 = wad_lumps
    i_1 = 0
    while (i_1 < wad_numlumps) {
        if (c2da_lin_strcmp(c2da_fp, lump_p_0 + 16) == 0) {
            return lump_p_0
        }
        i_1++
        lump_p_0 += 32
    }
    Sys_Error(737794, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(name))])
    return 0
}

// This unit's static data, at heap offset 737728.
let private c2da_lin_static_wad_seg = fixed_array<int>(737728, 122)
let private c2da_lin_static_wad = fixed_array<uint64>(0x615764616f4c5f57ul, 0x63203a656c694664ul, 0x2074276e646c756ful, 0x73252064616f6cul, 0x656c696620646157ul, 0x73656f6420732520ul, 0x657661682074276eul, 0x6469203244415720ul, 0x4c7465475f57000aul, 0x3a6f666e69706d75ul, 0x20746f6e20732520ul, 0x5f5700646e756f66ul, 0x4e706d754c746547ul, 0x20646162203a6d75ul, 0x203a7265626d756eul, 0x6925ul)

[init]
def private c2da_lin_init_static_wad() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_wad_seg[s * 2]
        for (k in range(c2da_lin_static_wad_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_wad[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
