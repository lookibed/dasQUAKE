[export, sideeffects]
def Memory_Init(var buf : int; var size : int) {
    var p : int
    var zonesize : int = 49152
    hunk_base = int(buf)  // nolint:PERF020
    hunk_size = int(size)  // nolint:PERF020
    hunk_low_used = 0
    hunk_high_used = 0
    Cache_Init()
    p = COM_CheckParm(740064)
    if (p != 0) {
        if (p < int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) - 1) {
            zonesize = Q_atoi(int(uint(c2da_mem[com_argv + (p + 1) * 8]) | uint(c2da_mem[com_argv + (p + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + (p + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + (p + 1) * 8 + 3]) << 0x18)) * 1024
        } else {
            Sys_Error(740070, [])
        }
    }
    mainzone = Hunk_AllocName(zonesize, 740125)
    Z_ClearZone(mainzone, zonesize)
    return
}
var mainzone : int = default<int>

[export, sideeffects]
def Z_ClearZone(var zone : int; var size_0 : int) {
    var block_0 : int = zone + 56
    let c2da_fresh0 : uint = uint(block_0)
    c2da_mem[zone + 32] = uint8(c2da_fresh0)
    c2da_mem[zone + 33] = uint8(c2da_fresh0 >> 0x8)
    c2da_mem[zone + 34] = uint8(c2da_fresh0 >> 0x10)
    c2da_mem[zone + 35] = uint8(c2da_fresh0 >> 0x18)
    c2da_mem[zone + 36] = 0u8
    c2da_mem[zone + 37] = 0u8
    c2da_mem[zone + 38] = 0u8
    c2da_mem[zone + 39] = 0u8
    let c2da_fresh1 : uint = uint(block_0)
    c2da_mem[zone + 24] = uint8(c2da_fresh1)
    c2da_mem[zone + 25] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[zone + 26] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[zone + 27] = uint8(c2da_fresh1 >> 0x18)
    c2da_mem[zone + 28] = 0u8
    c2da_mem[zone + 29] = 0u8
    c2da_mem[zone + 30] = 0u8
    c2da_mem[zone + 31] = 0u8
    let c2da_fresh2 : int = 1
    let c2da_fresh3 : uint = uint(c2da_fresh2)
    c2da_mem[zone + 12] = uint8(c2da_fresh3)
    c2da_mem[zone + 13] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[zone + 14] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[zone + 15] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : int = 0
    let c2da_fresh5 : uint = uint(c2da_fresh4)
    c2da_mem[zone + 16] = uint8(c2da_fresh5)
    c2da_mem[zone + 17] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[zone + 18] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[zone + 19] = uint8(c2da_fresh5 >> 0x18)
    let c2da_fresh6 : int = 0
    let c2da_fresh7 : uint = uint(c2da_fresh6)
    c2da_mem[zone + 8] = uint8(c2da_fresh7)
    c2da_mem[zone + 9] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[zone + 10] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[zone + 11] = uint8(c2da_fresh7 >> 0x18)
    let c2da_fresh8 : uint = uint(block_0)
    c2da_mem[zone + 48] = uint8(c2da_fresh8)
    c2da_mem[zone + 49] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[zone + 50] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[zone + 51] = uint8(c2da_fresh8 >> 0x18)
    c2da_mem[zone + 52] = 0u8
    c2da_mem[zone + 53] = 0u8
    c2da_mem[zone + 54] = 0u8
    c2da_mem[zone + 55] = 0u8
    let c2da_fresh9 : int = zone + 8
    let c2da_fresh10 : uint = uint(c2da_fresh9)
    c2da_mem[block_0 + 16] = uint8(c2da_fresh10)
    c2da_mem[block_0 + 17] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[block_0 + 18] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[block_0 + 19] = uint8(c2da_fresh10 >> 0x18)
    c2da_mem[block_0 + 20] = 0u8
    c2da_mem[block_0 + 21] = 0u8
    c2da_mem[block_0 + 22] = 0u8
    c2da_mem[block_0 + 23] = 0u8
    let c2da_fresh11 : uint = uint(c2da_fresh9)
    c2da_mem[block_0 + 24] = uint8(c2da_fresh11)
    c2da_mem[block_0 + 25] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[block_0 + 26] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[block_0 + 27] = uint8(c2da_fresh11 >> 0x18)
    c2da_mem[block_0 + 28] = 0u8
    c2da_mem[block_0 + 29] = 0u8
    c2da_mem[block_0 + 30] = 0u8
    c2da_mem[block_0 + 31] = 0u8
    let c2da_fresh12 : int = 0
    let c2da_fresh13 : uint = uint(c2da_fresh12)
    c2da_mem[block_0 + 4] = uint8(c2da_fresh13)
    c2da_mem[block_0 + 5] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[block_0 + 6] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[block_0 + 7] = uint8(c2da_fresh13 >> 0x18)
    let c2da_fresh14 : int = 1919505
    let c2da_fresh15 : uint = uint(c2da_fresh14)
    c2da_mem[block_0 + 8] = uint8(c2da_fresh15)
    c2da_mem[block_0 + 9] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[block_0 + 10] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[block_0 + 11] = uint8(c2da_fresh15 >> 0x18)
    let c2da_fresh16 : int = int(uint64(size_0) - 56ul)
    let c2da_fresh17 : uint = uint(c2da_fresh16)
    c2da_mem[block_0] = uint8(c2da_fresh17)
    c2da_mem[block_0 + 1] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[block_0 + 2] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[block_0 + 3] = uint8(c2da_fresh17 >> 0x18)
    return
}
[export, sideeffects]
def Hunk_AllocName(var size_1 : int; var name : int) : int {
    var h : int
    if (size_1 < 0) {
        Sys_Error(740130, [C2daVaArg(tag = 1, i64 = int64(size_1), f64 = 0.0lf, raw = 0x0)])
    }
    size_1 = int(16ul + uint64(size_1 + 15 & ~15))
    if (hunk_size - hunk_low_used - hunk_high_used < size_1) {
        Sys_Error(740155, [C2daVaArg(tag = 1, i64 = int64(size_1), f64 = 0.0lf, raw = 0x0)])
    }
    h = hunk_base + hunk_low_used
    hunk_low_used += size_1
    Cache_FreeLow(hunk_low_used)
    c2da_lin_memset(h, 0, uint64(size_1))
    let c2da_fresh18 : uint = uint(size_1)
    c2da_mem[h + 4] = uint8(c2da_fresh18)
    c2da_mem[h + 5] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[h + 6] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[h + 7] = uint8(c2da_fresh18 >> 0x18)
    let c2da_fresh19 : int = 502268397
    let c2da_fresh20 : uint = uint(c2da_fresh19)
    c2da_mem[h] = uint8(c2da_fresh20)
    c2da_mem[h + 1] = uint8(c2da_fresh20 >> 0x8)
    c2da_mem[h + 2] = uint8(c2da_fresh20 >> 0x10)
    c2da_mem[h + 3] = uint8(c2da_fresh20 >> 0x18)
    Q_strncpy(h + 8, name, 8)
    return h + 1 * 16
}
var hunk_low_used : int = default<int>

[export, sideeffects]
def Cache_FreeLow(var new_low_hunk : int) {
    var c : int
    while (true) {
        c = int(uint(c2da_mem[697128]) | uint(c2da_mem[697129]) << 0x8 | uint(c2da_mem[697130]) << 0x10 | uint(c2da_mem[697131]) << 0x18)
        if (c == 697088) {
            return
        }
        if (c >= hunk_base + new_low_hunk) {
            return
        }
        Cache_Move(c)
    }
}
[export, sideeffects]
def Cache_Move(var c_0 : int) {
    var new_0 : int = Cache_TryAlloc(int(uint(c2da_mem[c_0]) | uint(c2da_mem[c_0 + 1]) << 0x8 | uint(c2da_mem[c_0 + 2]) << 0x10 | uint(c2da_mem[c_0 + 3]) << 0x18), 1u)
    if (new_0 != 0) {
        Q_memcpy(new_0 + 1 * 64, c_0 + 1 * 64, int(uint64(int(uint(c2da_mem[c_0]) | uint(c2da_mem[c_0 + 1]) << 0x8 | uint(c2da_mem[c_0 + 2]) << 0x10 | uint(c2da_mem[c_0 + 3]) << 0x18)) - 64ul))
        let c2da_fresh21 : int = int(uint(c2da_mem[c_0 + 8]) | uint(c2da_mem[c_0 + 9]) << 0x8 | uint(c2da_mem[c_0 + 10]) << 0x10 | uint(c2da_mem[c_0 + 11]) << 0x18)
        let c2da_fresh22 : uint = uint(c2da_fresh21)
        c2da_mem[new_0 + 8] = uint8(c2da_fresh22)
        c2da_mem[new_0 + 9] = uint8(c2da_fresh22 >> 0x8)
        c2da_mem[new_0 + 10] = uint8(c2da_fresh22 >> 0x10)
        c2da_mem[new_0 + 11] = uint8(c2da_fresh22 >> 0x18)
        c2da_mem[new_0 + 12] = 0u8
        c2da_mem[new_0 + 13] = 0u8
        c2da_mem[new_0 + 14] = 0u8
        c2da_mem[new_0 + 15] = 0u8
        Q_memcpy(new_0 + 16, c_0 + 16, 16)
        Cache_Free(int(uint(c2da_mem[c_0 + 8]) | uint(c2da_mem[c_0 + 9]) << 0x8 | uint(c2da_mem[c_0 + 10]) << 0x10 | uint(c2da_mem[c_0 + 11]) << 0x18))
        let c2da_fresh23 : int = int(uint(c2da_mem[new_0 + 8]) | uint(c2da_mem[new_0 + 9]) << 0x8 | uint(c2da_mem[new_0 + 10]) << 0x10 | uint(c2da_mem[new_0 + 11]) << 0x18)
        let c2da_fresh24 : int = new_0 + 1 * 64
        let c2da_fresh25 : uint = uint(c2da_fresh24)
        c2da_mem[c2da_fresh23] = uint8(c2da_fresh25)
        c2da_mem[c2da_fresh23 + 1] = uint8(c2da_fresh25 >> 0x8)
        c2da_mem[c2da_fresh23 + 2] = uint8(c2da_fresh25 >> 0x10)
        c2da_mem[c2da_fresh23 + 3] = uint8(c2da_fresh25 >> 0x18)
        c2da_mem[c2da_fresh23 + 4] = 0u8
        c2da_mem[c2da_fresh23 + 5] = 0u8
        c2da_mem[c2da_fresh23 + 6] = 0u8
        c2da_mem[c2da_fresh23 + 7] = 0u8
    } else {
        Cache_Free(int(uint(c2da_mem[c_0 + 8]) | uint(c2da_mem[c_0 + 9]) << 0x8 | uint(c2da_mem[c_0 + 10]) << 0x10 | uint(c2da_mem[c_0 + 11]) << 0x18))
    }
    return
}
[export, sideeffects]
def Cache_Free(var c_1 : int) {
    var cs : int
    if (int(uint(c2da_mem[c_1]) | uint(c2da_mem[c_1 + 1]) << 0x8 | uint(c2da_mem[c_1 + 2]) << 0x10 | uint(c2da_mem[c_1 + 3]) << 0x18) == 0) {
        Sys_Error(740186, [])
    }
    cs = int(uint(c2da_mem[c_1]) | uint(c2da_mem[c_1 + 1]) << 0x8 | uint(c2da_mem[c_1 + 2]) << 0x10 | uint(c2da_mem[c_1 + 3]) << 0x18) - 1 * 64
    let c2da_fresh26 : int = int(uint(c2da_mem[cs + 32]) | uint(c2da_mem[cs + 33]) << 0x8 | uint(c2da_mem[cs + 34]) << 0x10 | uint(c2da_mem[cs + 35]) << 0x18) + 40
    let c2da_fresh27 : int = int(uint(c2da_mem[cs + 40]) | uint(c2da_mem[cs + 41]) << 0x8 | uint(c2da_mem[cs + 42]) << 0x10 | uint(c2da_mem[cs + 43]) << 0x18)
    let c2da_fresh28 : uint = uint(c2da_fresh27)
    c2da_mem[c2da_fresh26] = uint8(c2da_fresh28)
    c2da_mem[c2da_fresh26 + 1] = uint8(c2da_fresh28 >> 0x8)
    c2da_mem[c2da_fresh26 + 2] = uint8(c2da_fresh28 >> 0x10)
    c2da_mem[c2da_fresh26 + 3] = uint8(c2da_fresh28 >> 0x18)
    c2da_mem[c2da_fresh26 + 4] = 0u8
    c2da_mem[c2da_fresh26 + 5] = 0u8
    c2da_mem[c2da_fresh26 + 6] = 0u8
    c2da_mem[c2da_fresh26 + 7] = 0u8
    let c2da_fresh29 : int = int(uint(c2da_mem[cs + 40]) | uint(c2da_mem[cs + 41]) << 0x8 | uint(c2da_mem[cs + 42]) << 0x10 | uint(c2da_mem[cs + 43]) << 0x18) + 32
    let c2da_fresh30 : int = int(uint(c2da_mem[cs + 32]) | uint(c2da_mem[cs + 33]) << 0x8 | uint(c2da_mem[cs + 34]) << 0x10 | uint(c2da_mem[cs + 35]) << 0x18)
    let c2da_fresh31 : uint = uint(c2da_fresh30)
    c2da_mem[c2da_fresh29] = uint8(c2da_fresh31)
    c2da_mem[c2da_fresh29 + 1] = uint8(c2da_fresh31 >> 0x8)
    c2da_mem[c2da_fresh29 + 2] = uint8(c2da_fresh31 >> 0x10)
    c2da_mem[c2da_fresh29 + 3] = uint8(c2da_fresh31 >> 0x18)
    c2da_mem[c2da_fresh29 + 4] = 0u8
    c2da_mem[c2da_fresh29 + 5] = 0u8
    c2da_mem[c2da_fresh29 + 6] = 0u8
    c2da_mem[c2da_fresh29 + 7] = 0u8
    let c2da_fresh32 : uint = 0u
    c2da_mem[cs + 32] = uint8(c2da_fresh32)
    c2da_mem[cs + 33] = uint8(c2da_fresh32 >> 0x8)
    c2da_mem[cs + 34] = uint8(c2da_fresh32 >> 0x10)
    c2da_mem[cs + 35] = uint8(c2da_fresh32 >> 0x18)
    c2da_mem[cs + 36] = 0u8
    c2da_mem[cs + 37] = 0u8
    c2da_mem[cs + 38] = 0u8
    c2da_mem[cs + 39] = 0u8
    let c2da_fresh33 : uint = 0u
    c2da_mem[cs + 40] = uint8(c2da_fresh33)
    c2da_mem[cs + 41] = uint8(c2da_fresh33 >> 0x8)
    c2da_mem[cs + 42] = uint8(c2da_fresh33 >> 0x10)
    c2da_mem[cs + 43] = uint8(c2da_fresh33 >> 0x18)
    c2da_mem[cs + 44] = 0u8
    c2da_mem[cs + 45] = 0u8
    c2da_mem[cs + 46] = 0u8
    c2da_mem[cs + 47] = 0u8
    let c2da_fresh34 : uint = 0u
    c2da_mem[c_1] = uint8(c2da_fresh34)
    c2da_mem[c_1 + 1] = uint8(c2da_fresh34 >> 0x8)
    c2da_mem[c_1 + 2] = uint8(c2da_fresh34 >> 0x10)
    c2da_mem[c_1 + 3] = uint8(c2da_fresh34 >> 0x18)
    c2da_mem[c_1 + 4] = 0u8
    c2da_mem[c_1 + 5] = 0u8
    c2da_mem[c_1 + 6] = 0u8
    c2da_mem[c_1 + 7] = 0u8
    Cache_UnlinkLRU(cs)
    return
}
[export, sideeffects]
def Cache_UnlinkLRU(var cs_0 : int) {
    if (int(uint(c2da_mem[cs_0 + 56]) | uint(c2da_mem[cs_0 + 57]) << 0x8 | uint(c2da_mem[cs_0 + 58]) << 0x10 | uint(c2da_mem[cs_0 + 59]) << 0x18) == 0 || int(uint(c2da_mem[cs_0 + 48]) | uint(c2da_mem[cs_0 + 49]) << 0x8 | uint(c2da_mem[cs_0 + 50]) << 0x10 | uint(c2da_mem[cs_0 + 51]) << 0x18) == 0) {
        Sys_Error(740212, [])
    }
    let c2da_fresh35 : int = int(uint(c2da_mem[cs_0 + 56]) | uint(c2da_mem[cs_0 + 57]) << 0x8 | uint(c2da_mem[cs_0 + 58]) << 0x10 | uint(c2da_mem[cs_0 + 59]) << 0x18) + 48
    let c2da_fresh36 : int = int(uint(c2da_mem[cs_0 + 48]) | uint(c2da_mem[cs_0 + 49]) << 0x8 | uint(c2da_mem[cs_0 + 50]) << 0x10 | uint(c2da_mem[cs_0 + 51]) << 0x18)
    let c2da_fresh37 : uint = uint(c2da_fresh36)
    c2da_mem[c2da_fresh35] = uint8(c2da_fresh37)
    c2da_mem[c2da_fresh35 + 1] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[c2da_fresh35 + 2] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[c2da_fresh35 + 3] = uint8(c2da_fresh37 >> 0x18)
    c2da_mem[c2da_fresh35 + 4] = 0u8
    c2da_mem[c2da_fresh35 + 5] = 0u8
    c2da_mem[c2da_fresh35 + 6] = 0u8
    c2da_mem[c2da_fresh35 + 7] = 0u8
    let c2da_fresh38 : int = int(uint(c2da_mem[cs_0 + 48]) | uint(c2da_mem[cs_0 + 49]) << 0x8 | uint(c2da_mem[cs_0 + 50]) << 0x10 | uint(c2da_mem[cs_0 + 51]) << 0x18) + 56
    let c2da_fresh39 : int = int(uint(c2da_mem[cs_0 + 56]) | uint(c2da_mem[cs_0 + 57]) << 0x8 | uint(c2da_mem[cs_0 + 58]) << 0x10 | uint(c2da_mem[cs_0 + 59]) << 0x18)
    let c2da_fresh40 : uint = uint(c2da_fresh39)
    c2da_mem[c2da_fresh38] = uint8(c2da_fresh40)
    c2da_mem[c2da_fresh38 + 1] = uint8(c2da_fresh40 >> 0x8)
    c2da_mem[c2da_fresh38 + 2] = uint8(c2da_fresh40 >> 0x10)
    c2da_mem[c2da_fresh38 + 3] = uint8(c2da_fresh40 >> 0x18)
    c2da_mem[c2da_fresh38 + 4] = 0u8
    c2da_mem[c2da_fresh38 + 5] = 0u8
    c2da_mem[c2da_fresh38 + 6] = 0u8
    c2da_mem[c2da_fresh38 + 7] = 0u8
    let c2da_fresh41 : uint = 0u
    c2da_mem[cs_0 + 56] = uint8(c2da_fresh41)
    c2da_mem[cs_0 + 57] = uint8(c2da_fresh41 >> 0x8)
    c2da_mem[cs_0 + 58] = uint8(c2da_fresh41 >> 0x10)
    c2da_mem[cs_0 + 59] = uint8(c2da_fresh41 >> 0x18)
    c2da_mem[cs_0 + 60] = 0u8
    c2da_mem[cs_0 + 61] = 0u8
    c2da_mem[cs_0 + 62] = 0u8
    c2da_mem[cs_0 + 63] = 0u8
    let c2da_fresh42 : uint = 0u
    c2da_mem[cs_0 + 48] = uint8(c2da_fresh42)
    c2da_mem[cs_0 + 49] = uint8(c2da_fresh42 >> 0x8)
    c2da_mem[cs_0 + 50] = uint8(c2da_fresh42 >> 0x10)
    c2da_mem[cs_0 + 51] = uint8(c2da_fresh42 >> 0x18)
    c2da_mem[cs_0 + 52] = 0u8
    c2da_mem[cs_0 + 53] = 0u8
    c2da_mem[cs_0 + 54] = 0u8
    c2da_mem[cs_0 + 55] = 0u8
    return
}
[export, sideeffects]
def Cache_TryAlloc(var size_2 : int; var nobottom : uint) : int {
    var cs_1 : int
    var new_1 : int
    if (nobottom == 0u && int(uint(c2da_mem[697120]) | uint(c2da_mem[697121]) << 0x8 | uint(c2da_mem[697122]) << 0x10 | uint(c2da_mem[697123]) << 0x18) == 697088) {
        if (hunk_size - hunk_high_used - hunk_low_used < size_2) {
            Sys_Error(740239, [C2daVaArg(tag = 1, i64 = int64(size_2), f64 = 0.0lf, raw = 0x0)])
        }
        new_1 = hunk_base + hunk_low_used
        c2da_lin_memset(new_1, 0, 64ul)
        let c2da_fresh43 : uint = uint(size_2)
        c2da_mem[new_1] = uint8(c2da_fresh43)
        c2da_mem[new_1 + 1] = uint8(c2da_fresh43 >> 0x8)
        c2da_mem[new_1 + 2] = uint8(c2da_fresh43 >> 0x10)
        c2da_mem[new_1 + 3] = uint8(c2da_fresh43 >> 0x18)
        let c2da_fresh44 : uint = uint(new_1)
        c2da_mem[697128] = uint8(c2da_fresh44)
        c2da_mem[697129] = uint8(c2da_fresh44 >> 0x8)
        c2da_mem[697130] = uint8(c2da_fresh44 >> 0x10)
        c2da_mem[697131] = uint8(c2da_fresh44 >> 0x18)
        c2da_mem[697132] = 0u8
        c2da_mem[697133] = 0u8
        c2da_mem[697134] = 0u8
        c2da_mem[697135] = 0u8
        let c2da_fresh45 : uint = uint(new_1)
        c2da_mem[697120] = uint8(c2da_fresh45)
        c2da_mem[697121] = uint8(c2da_fresh45 >> 0x8)
        c2da_mem[697122] = uint8(c2da_fresh45 >> 0x10)
        c2da_mem[697123] = uint8(c2da_fresh45 >> 0x18)
        c2da_mem[697124] = 0u8
        c2da_mem[697125] = 0u8
        c2da_mem[697126] = 0u8
        c2da_mem[697127] = 0u8
        let c2da_fresh46 : uint = 697088u
        c2da_mem[new_1 + 40] = uint8(c2da_fresh46)
        c2da_mem[new_1 + 41] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[new_1 + 42] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[new_1 + 43] = uint8(c2da_fresh46 >> 0x18)
        c2da_mem[new_1 + 44] = 0u8
        c2da_mem[new_1 + 45] = 0u8
        c2da_mem[new_1 + 46] = 0u8
        c2da_mem[new_1 + 47] = 0u8
        let c2da_fresh47 : uint = 697088u
        c2da_mem[new_1 + 32] = uint8(c2da_fresh47)
        c2da_mem[new_1 + 33] = uint8(c2da_fresh47 >> 0x8)
        c2da_mem[new_1 + 34] = uint8(c2da_fresh47 >> 0x10)
        c2da_mem[new_1 + 35] = uint8(c2da_fresh47 >> 0x18)
        c2da_mem[new_1 + 36] = 0u8
        c2da_mem[new_1 + 37] = 0u8
        c2da_mem[new_1 + 38] = 0u8
        c2da_mem[new_1 + 39] = 0u8
        Cache_MakeLRU(new_1)
        return new_1
    }
    new_1 = hunk_base + hunk_low_used
    cs_1 = int(uint(c2da_mem[697128]) | uint(c2da_mem[697129]) << 0x8 | uint(c2da_mem[697130]) << 0x10 | uint(c2da_mem[697131]) << 0x18)
    while (true) {
        if (nobottom == 0u || cs_1 != int(uint(c2da_mem[697128]) | uint(c2da_mem[697129]) << 0x8 | uint(c2da_mem[697130]) << 0x10 | uint(c2da_mem[697131]) << 0x18)) {
            if (int64(cs_1 - new_1) >= int64(size_2)) {
                c2da_lin_memset(new_1, 0, 64ul)
                let c2da_fresh48 : uint = uint(size_2)
                c2da_mem[new_1] = uint8(c2da_fresh48)
                c2da_mem[new_1 + 1] = uint8(c2da_fresh48 >> 0x8)
                c2da_mem[new_1 + 2] = uint8(c2da_fresh48 >> 0x10)
                c2da_mem[new_1 + 3] = uint8(c2da_fresh48 >> 0x18)
                let c2da_fresh49 : uint = uint(cs_1)
                c2da_mem[new_1 + 40] = uint8(c2da_fresh49)
                c2da_mem[new_1 + 41] = uint8(c2da_fresh49 >> 0x8)
                c2da_mem[new_1 + 42] = uint8(c2da_fresh49 >> 0x10)
                c2da_mem[new_1 + 43] = uint8(c2da_fresh49 >> 0x18)
                c2da_mem[new_1 + 44] = 0u8
                c2da_mem[new_1 + 45] = 0u8
                c2da_mem[new_1 + 46] = 0u8
                c2da_mem[new_1 + 47] = 0u8
                let c2da_fresh50 : int = int(uint(c2da_mem[cs_1 + 32]) | uint(c2da_mem[cs_1 + 33]) << 0x8 | uint(c2da_mem[cs_1 + 34]) << 0x10 | uint(c2da_mem[cs_1 + 35]) << 0x18)
                let c2da_fresh51 : uint = uint(c2da_fresh50)
                c2da_mem[new_1 + 32] = uint8(c2da_fresh51)
                c2da_mem[new_1 + 33] = uint8(c2da_fresh51 >> 0x8)
                c2da_mem[new_1 + 34] = uint8(c2da_fresh51 >> 0x10)
                c2da_mem[new_1 + 35] = uint8(c2da_fresh51 >> 0x18)
                c2da_mem[new_1 + 36] = 0u8
                c2da_mem[new_1 + 37] = 0u8
                c2da_mem[new_1 + 38] = 0u8
                c2da_mem[new_1 + 39] = 0u8
                let c2da_fresh52 : int = int(uint(c2da_mem[cs_1 + 32]) | uint(c2da_mem[cs_1 + 33]) << 0x8 | uint(c2da_mem[cs_1 + 34]) << 0x10 | uint(c2da_mem[cs_1 + 35]) << 0x18) + 40
                let c2da_fresh53 : uint = uint(new_1)
                c2da_mem[c2da_fresh52] = uint8(c2da_fresh53)
                c2da_mem[c2da_fresh52 + 1] = uint8(c2da_fresh53 >> 0x8)
                c2da_mem[c2da_fresh52 + 2] = uint8(c2da_fresh53 >> 0x10)
                c2da_mem[c2da_fresh52 + 3] = uint8(c2da_fresh53 >> 0x18)
                c2da_mem[c2da_fresh52 + 4] = 0u8
                c2da_mem[c2da_fresh52 + 5] = 0u8
                c2da_mem[c2da_fresh52 + 6] = 0u8
                c2da_mem[c2da_fresh52 + 7] = 0u8
                let c2da_fresh54 : uint = uint(new_1)
                c2da_mem[cs_1 + 32] = uint8(c2da_fresh54)
                c2da_mem[cs_1 + 33] = uint8(c2da_fresh54 >> 0x8)
                c2da_mem[cs_1 + 34] = uint8(c2da_fresh54 >> 0x10)
                c2da_mem[cs_1 + 35] = uint8(c2da_fresh54 >> 0x18)
                c2da_mem[cs_1 + 36] = 0u8
                c2da_mem[cs_1 + 37] = 0u8
                c2da_mem[cs_1 + 38] = 0u8
                c2da_mem[cs_1 + 39] = 0u8
                Cache_MakeLRU(new_1)
                return new_1
            }
        }
        new_1 = cs_1 + int(uint(c2da_mem[cs_1]) | uint(c2da_mem[cs_1 + 1]) << 0x8 | uint(c2da_mem[cs_1 + 2]) << 0x10 | uint(c2da_mem[cs_1 + 3]) << 0x18)
        cs_1 = int(uint(c2da_mem[cs_1 + 40]) | uint(c2da_mem[cs_1 + 41]) << 0x8 | uint(c2da_mem[cs_1 + 42]) << 0x10 | uint(c2da_mem[cs_1 + 43]) << 0x18)
        if (cs_1 == 697088) {
            break
        }
    }
    if (int64(hunk_base + hunk_size - hunk_high_used - new_1) >= int64(size_2)) {
        c2da_lin_memset(new_1, 0, 64ul)
        let c2da_fresh55 : uint = uint(size_2)
        c2da_mem[new_1] = uint8(c2da_fresh55)
        c2da_mem[new_1 + 1] = uint8(c2da_fresh55 >> 0x8)
        c2da_mem[new_1 + 2] = uint8(c2da_fresh55 >> 0x10)
        c2da_mem[new_1 + 3] = uint8(c2da_fresh55 >> 0x18)
        let c2da_fresh56 : uint = 697088u
        c2da_mem[new_1 + 40] = uint8(c2da_fresh56)
        c2da_mem[new_1 + 41] = uint8(c2da_fresh56 >> 0x8)
        c2da_mem[new_1 + 42] = uint8(c2da_fresh56 >> 0x10)
        c2da_mem[new_1 + 43] = uint8(c2da_fresh56 >> 0x18)
        c2da_mem[new_1 + 44] = 0u8
        c2da_mem[new_1 + 45] = 0u8
        c2da_mem[new_1 + 46] = 0u8
        c2da_mem[new_1 + 47] = 0u8
        let c2da_fresh57 : int = int(uint(c2da_mem[697120]) | uint(c2da_mem[697121]) << 0x8 | uint(c2da_mem[697122]) << 0x10 | uint(c2da_mem[697123]) << 0x18)
        let c2da_fresh58 : uint = uint(c2da_fresh57)
        c2da_mem[new_1 + 32] = uint8(c2da_fresh58)
        c2da_mem[new_1 + 33] = uint8(c2da_fresh58 >> 0x8)
        c2da_mem[new_1 + 34] = uint8(c2da_fresh58 >> 0x10)
        c2da_mem[new_1 + 35] = uint8(c2da_fresh58 >> 0x18)
        c2da_mem[new_1 + 36] = 0u8
        c2da_mem[new_1 + 37] = 0u8
        c2da_mem[new_1 + 38] = 0u8
        c2da_mem[new_1 + 39] = 0u8
        let c2da_fresh59 : int = int(uint(c2da_mem[697120]) | uint(c2da_mem[697121]) << 0x8 | uint(c2da_mem[697122]) << 0x10 | uint(c2da_mem[697123]) << 0x18) + 40
        let c2da_fresh60 : uint = uint(new_1)
        c2da_mem[c2da_fresh59] = uint8(c2da_fresh60)
        c2da_mem[c2da_fresh59 + 1] = uint8(c2da_fresh60 >> 0x8)
        c2da_mem[c2da_fresh59 + 2] = uint8(c2da_fresh60 >> 0x10)
        c2da_mem[c2da_fresh59 + 3] = uint8(c2da_fresh60 >> 0x18)
        c2da_mem[c2da_fresh59 + 4] = 0u8
        c2da_mem[c2da_fresh59 + 5] = 0u8
        c2da_mem[c2da_fresh59 + 6] = 0u8
        c2da_mem[c2da_fresh59 + 7] = 0u8
        let c2da_fresh61 : uint = uint(new_1)
        c2da_mem[697120] = uint8(c2da_fresh61)
        c2da_mem[697121] = uint8(c2da_fresh61 >> 0x8)
        c2da_mem[697122] = uint8(c2da_fresh61 >> 0x10)
        c2da_mem[697123] = uint8(c2da_fresh61 >> 0x18)
        c2da_mem[697124] = 0u8
        c2da_mem[697125] = 0u8
        c2da_mem[697126] = 0u8
        c2da_mem[697127] = 0u8
        Cache_MakeLRU(new_1)
        return new_1
    }
    return 0
}
[export, sideeffects]
def Cache_MakeLRU(var cs_2 : int) {
    if (int(uint(c2da_mem[cs_2 + 56]) | uint(c2da_mem[cs_2 + 57]) << 0x8 | uint(c2da_mem[cs_2 + 58]) << 0x10 | uint(c2da_mem[cs_2 + 59]) << 0x18) != 0 || int(uint(c2da_mem[cs_2 + 48]) | uint(c2da_mem[cs_2 + 49]) << 0x8 | uint(c2da_mem[cs_2 + 50]) << 0x10 | uint(c2da_mem[cs_2 + 51]) << 0x18) != 0) {
        Sys_Error(740284, [])
    }
    let c2da_fresh62 : int = int(uint(c2da_mem[697144]) | uint(c2da_mem[697145]) << 0x8 | uint(c2da_mem[697146]) << 0x10 | uint(c2da_mem[697147]) << 0x18) + 48
    let c2da_fresh63 : uint = uint(cs_2)
    c2da_mem[c2da_fresh62] = uint8(c2da_fresh63)
    c2da_mem[c2da_fresh62 + 1] = uint8(c2da_fresh63 >> 0x8)
    c2da_mem[c2da_fresh62 + 2] = uint8(c2da_fresh63 >> 0x10)
    c2da_mem[c2da_fresh62 + 3] = uint8(c2da_fresh63 >> 0x18)
    c2da_mem[c2da_fresh62 + 4] = 0u8
    c2da_mem[c2da_fresh62 + 5] = 0u8
    c2da_mem[c2da_fresh62 + 6] = 0u8
    c2da_mem[c2da_fresh62 + 7] = 0u8
    let c2da_fresh64 : int = int(uint(c2da_mem[697144]) | uint(c2da_mem[697145]) << 0x8 | uint(c2da_mem[697146]) << 0x10 | uint(c2da_mem[697147]) << 0x18)
    let c2da_fresh65 : uint = uint(c2da_fresh64)
    c2da_mem[cs_2 + 56] = uint8(c2da_fresh65)
    c2da_mem[cs_2 + 57] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[cs_2 + 58] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[cs_2 + 59] = uint8(c2da_fresh65 >> 0x18)
    c2da_mem[cs_2 + 60] = 0u8
    c2da_mem[cs_2 + 61] = 0u8
    c2da_mem[cs_2 + 62] = 0u8
    c2da_mem[cs_2 + 63] = 0u8
    let c2da_fresh66 : uint = 697088u
    c2da_mem[cs_2 + 48] = uint8(c2da_fresh66)
    c2da_mem[cs_2 + 49] = uint8(c2da_fresh66 >> 0x8)
    c2da_mem[cs_2 + 50] = uint8(c2da_fresh66 >> 0x10)
    c2da_mem[cs_2 + 51] = uint8(c2da_fresh66 >> 0x18)
    c2da_mem[cs_2 + 52] = 0u8
    c2da_mem[cs_2 + 53] = 0u8
    c2da_mem[cs_2 + 54] = 0u8
    c2da_mem[cs_2 + 55] = 0u8
    let c2da_fresh67 : uint = uint(cs_2)
    c2da_mem[697144] = uint8(c2da_fresh67)
    c2da_mem[697145] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[697146] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[697147] = uint8(c2da_fresh67 >> 0x18)
    c2da_mem[697148] = 0u8
    c2da_mem[697149] = 0u8
    c2da_mem[697150] = 0u8
    c2da_mem[697151] = 0u8
    return
}
var hunk_high_used : int = default<int>

var hunk_size : int = default<int>

var hunk_base : int = default<int>

[export, sideeffects]
def Cache_Init() {
    let c2da_fresh68 : uint = 697088u
    c2da_mem[697120] = uint8(c2da_fresh68)
    c2da_mem[697121] = uint8(c2da_fresh68 >> 0x8)
    c2da_mem[697122] = uint8(c2da_fresh68 >> 0x10)
    c2da_mem[697123] = uint8(c2da_fresh68 >> 0x18)
    c2da_mem[697124] = 0u8
    c2da_mem[697125] = 0u8
    c2da_mem[697126] = 0u8
    c2da_mem[697127] = 0u8
    let c2da_fresh69 : uint = 697088u
    c2da_mem[697128] = uint8(c2da_fresh69)
    c2da_mem[697129] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[697130] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[697131] = uint8(c2da_fresh69 >> 0x18)
    c2da_mem[697132] = 0u8
    c2da_mem[697133] = 0u8
    c2da_mem[697134] = 0u8
    c2da_mem[697135] = 0u8
    let c2da_fresh70 : uint = 697088u
    c2da_mem[697136] = uint8(c2da_fresh70)
    c2da_mem[697137] = uint8(c2da_fresh70 >> 0x8)
    c2da_mem[697138] = uint8(c2da_fresh70 >> 0x10)
    c2da_mem[697139] = uint8(c2da_fresh70 >> 0x18)
    c2da_mem[697140] = 0u8
    c2da_mem[697141] = 0u8
    c2da_mem[697142] = 0u8
    c2da_mem[697143] = 0u8
    let c2da_fresh71 : uint = 697088u
    c2da_mem[697144] = uint8(c2da_fresh71)
    c2da_mem[697145] = uint8(c2da_fresh71 >> 0x8)
    c2da_mem[697146] = uint8(c2da_fresh71 >> 0x10)
    c2da_mem[697147] = uint8(c2da_fresh71 >> 0x18)
    c2da_mem[697148] = 0u8
    c2da_mem[697149] = 0u8
    c2da_mem[697150] = 0u8
    c2da_mem[697151] = 0u8
    Cmd_AddCommand(740311, 223)
    return
}
[export, sideeffects]
def Cache_Flush() {
    while (int(uint(c2da_mem[697128]) | uint(c2da_mem[697129]) << 0x8 | uint(c2da_mem[697130]) << 0x10 | uint(c2da_mem[697131]) << 0x18) != 697088) {
        let c2da_fresh72 : int = int(uint(c2da_mem[697128]) | uint(c2da_mem[697129]) << 0x8 | uint(c2da_mem[697130]) << 0x10 | uint(c2da_mem[697131]) << 0x18) + 8
        Cache_Free(int(uint(c2da_mem[c2da_fresh72]) | uint(c2da_mem[c2da_fresh72 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh72 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh72 + 3]) << 0x18))
    }
    return
}
[export, sideeffects]
def Z_Free(var ptr : int) {
    var block_1 : int
    var other : int
    if (ptr == 0) {
        Sys_Error(740317, [])
    }
    block_1 = ptr - 40
    if (int(uint(c2da_mem[block_1 + 8]) | uint(c2da_mem[block_1 + 9]) << 0x8 | uint(c2da_mem[block_1 + 10]) << 0x10 | uint(c2da_mem[block_1 + 11]) << 0x18) != 1919505) {
        Sys_Error(740338, [])
    }
    if (int(uint(c2da_mem[block_1 + 4]) | uint(c2da_mem[block_1 + 5]) << 0x8 | uint(c2da_mem[block_1 + 6]) << 0x10 | uint(c2da_mem[block_1 + 7]) << 0x18) == 0) {
        Sys_Error(740377, [])
    }
    let c2da_fresh73 : int = 0
    let c2da_fresh74 : uint = uint(c2da_fresh73)
    c2da_mem[block_1 + 4] = uint8(c2da_fresh74)
    c2da_mem[block_1 + 5] = uint8(c2da_fresh74 >> 0x8)
    c2da_mem[block_1 + 6] = uint8(c2da_fresh74 >> 0x10)
    c2da_mem[block_1 + 7] = uint8(c2da_fresh74 >> 0x18)
    other = int(uint(c2da_mem[block_1 + 24]) | uint(c2da_mem[block_1 + 25]) << 0x8 | uint(c2da_mem[block_1 + 26]) << 0x10 | uint(c2da_mem[block_1 + 27]) << 0x18)
    if (int(uint(c2da_mem[other + 4]) | uint(c2da_mem[other + 5]) << 0x8 | uint(c2da_mem[other + 6]) << 0x10 | uint(c2da_mem[other + 7]) << 0x18) == 0) {
        let c2da_fresh75 : int = int(uint(c2da_mem[other]) | uint(c2da_mem[other + 1]) << 0x8 | uint(c2da_mem[other + 2]) << 0x10 | uint(c2da_mem[other + 3]) << 0x18) + int(uint(c2da_mem[block_1]) | uint(c2da_mem[block_1 + 1]) << 0x8 | uint(c2da_mem[block_1 + 2]) << 0x10 | uint(c2da_mem[block_1 + 3]) << 0x18)
        let c2da_fresh76 : uint = uint(c2da_fresh75)
        c2da_mem[other] = uint8(c2da_fresh76)
        c2da_mem[other + 1] = uint8(c2da_fresh76 >> 0x8)
        c2da_mem[other + 2] = uint8(c2da_fresh76 >> 0x10)
        c2da_mem[other + 3] = uint8(c2da_fresh76 >> 0x18)
        let c2da_fresh77 : int = int(uint(c2da_mem[block_1 + 16]) | uint(c2da_mem[block_1 + 17]) << 0x8 | uint(c2da_mem[block_1 + 18]) << 0x10 | uint(c2da_mem[block_1 + 19]) << 0x18)
        let c2da_fresh78 : uint = uint(c2da_fresh77)
        c2da_mem[other + 16] = uint8(c2da_fresh78)
        c2da_mem[other + 17] = uint8(c2da_fresh78 >> 0x8)
        c2da_mem[other + 18] = uint8(c2da_fresh78 >> 0x10)
        c2da_mem[other + 19] = uint8(c2da_fresh78 >> 0x18)
        c2da_mem[other + 20] = 0u8
        c2da_mem[other + 21] = 0u8
        c2da_mem[other + 22] = 0u8
        c2da_mem[other + 23] = 0u8
        let c2da_fresh79 : int = int(uint(c2da_mem[other + 16]) | uint(c2da_mem[other + 17]) << 0x8 | uint(c2da_mem[other + 18]) << 0x10 | uint(c2da_mem[other + 19]) << 0x18) + 24
        let c2da_fresh80 : uint = uint(other)
        c2da_mem[c2da_fresh79] = uint8(c2da_fresh80)
        c2da_mem[c2da_fresh79 + 1] = uint8(c2da_fresh80 >> 0x8)
        c2da_mem[c2da_fresh79 + 2] = uint8(c2da_fresh80 >> 0x10)
        c2da_mem[c2da_fresh79 + 3] = uint8(c2da_fresh80 >> 0x18)
        c2da_mem[c2da_fresh79 + 4] = 0u8
        c2da_mem[c2da_fresh79 + 5] = 0u8
        c2da_mem[c2da_fresh79 + 6] = 0u8
        c2da_mem[c2da_fresh79 + 7] = 0u8
        if (block_1 == int(uint(c2da_mem[mainzone + 48]) | uint(c2da_mem[mainzone + 49]) << 0x8 | uint(c2da_mem[mainzone + 50]) << 0x10 | uint(c2da_mem[mainzone + 51]) << 0x18)) {
            let c2da_fresh81 : uint = uint(other)
            c2da_mem[mainzone + 48] = uint8(c2da_fresh81)
            c2da_mem[mainzone + 49] = uint8(c2da_fresh81 >> 0x8)
            c2da_mem[mainzone + 50] = uint8(c2da_fresh81 >> 0x10)
            c2da_mem[mainzone + 51] = uint8(c2da_fresh81 >> 0x18)
            c2da_mem[mainzone + 52] = 0u8
            c2da_mem[mainzone + 53] = 0u8
            c2da_mem[mainzone + 54] = 0u8
            c2da_mem[mainzone + 55] = 0u8
        }
        block_1 = other
    }
    other = int(uint(c2da_mem[block_1 + 16]) | uint(c2da_mem[block_1 + 17]) << 0x8 | uint(c2da_mem[block_1 + 18]) << 0x10 | uint(c2da_mem[block_1 + 19]) << 0x18)
    if (int(uint(c2da_mem[other + 4]) | uint(c2da_mem[other + 5]) << 0x8 | uint(c2da_mem[other + 6]) << 0x10 | uint(c2da_mem[other + 7]) << 0x18) == 0) {
        let c2da_fresh82 : int = int(uint(c2da_mem[block_1]) | uint(c2da_mem[block_1 + 1]) << 0x8 | uint(c2da_mem[block_1 + 2]) << 0x10 | uint(c2da_mem[block_1 + 3]) << 0x18) + int(uint(c2da_mem[other]) | uint(c2da_mem[other + 1]) << 0x8 | uint(c2da_mem[other + 2]) << 0x10 | uint(c2da_mem[other + 3]) << 0x18)
        let c2da_fresh83 : uint = uint(c2da_fresh82)
        c2da_mem[block_1] = uint8(c2da_fresh83)
        c2da_mem[block_1 + 1] = uint8(c2da_fresh83 >> 0x8)
        c2da_mem[block_1 + 2] = uint8(c2da_fresh83 >> 0x10)
        c2da_mem[block_1 + 3] = uint8(c2da_fresh83 >> 0x18)
        let c2da_fresh84 : int = int(uint(c2da_mem[other + 16]) | uint(c2da_mem[other + 17]) << 0x8 | uint(c2da_mem[other + 18]) << 0x10 | uint(c2da_mem[other + 19]) << 0x18)
        let c2da_fresh85 : uint = uint(c2da_fresh84)
        c2da_mem[block_1 + 16] = uint8(c2da_fresh85)
        c2da_mem[block_1 + 17] = uint8(c2da_fresh85 >> 0x8)
        c2da_mem[block_1 + 18] = uint8(c2da_fresh85 >> 0x10)
        c2da_mem[block_1 + 19] = uint8(c2da_fresh85 >> 0x18)
        c2da_mem[block_1 + 20] = 0u8
        c2da_mem[block_1 + 21] = 0u8
        c2da_mem[block_1 + 22] = 0u8
        c2da_mem[block_1 + 23] = 0u8
        let c2da_fresh86 : int = int(uint(c2da_mem[block_1 + 16]) | uint(c2da_mem[block_1 + 17]) << 0x8 | uint(c2da_mem[block_1 + 18]) << 0x10 | uint(c2da_mem[block_1 + 19]) << 0x18) + 24
        let c2da_fresh87 : uint = uint(block_1)
        c2da_mem[c2da_fresh86] = uint8(c2da_fresh87)
        c2da_mem[c2da_fresh86 + 1] = uint8(c2da_fresh87 >> 0x8)
        c2da_mem[c2da_fresh86 + 2] = uint8(c2da_fresh87 >> 0x10)
        c2da_mem[c2da_fresh86 + 3] = uint8(c2da_fresh87 >> 0x18)
        c2da_mem[c2da_fresh86 + 4] = 0u8
        c2da_mem[c2da_fresh86 + 5] = 0u8
        c2da_mem[c2da_fresh86 + 6] = 0u8
        c2da_mem[c2da_fresh86 + 7] = 0u8
        if (other == int(uint(c2da_mem[mainzone + 48]) | uint(c2da_mem[mainzone + 49]) << 0x8 | uint(c2da_mem[mainzone + 50]) << 0x10 | uint(c2da_mem[mainzone + 51]) << 0x18)) {
            let c2da_fresh88 : uint = uint(block_1)
            c2da_mem[mainzone + 48] = uint8(c2da_fresh88)
            c2da_mem[mainzone + 49] = uint8(c2da_fresh88 >> 0x8)
            c2da_mem[mainzone + 50] = uint8(c2da_fresh88 >> 0x10)
            c2da_mem[mainzone + 51] = uint8(c2da_fresh88 >> 0x18)
            c2da_mem[mainzone + 52] = 0u8
            c2da_mem[mainzone + 53] = 0u8
            c2da_mem[mainzone + 54] = 0u8
            c2da_mem[mainzone + 55] = 0u8
        }
    }
    return
}
[export, sideeffects]
def Z_Malloc(var size_3 : int) : int {
    var buf_0 : int
    Z_CheckHeap()
    buf_0 = Z_TagMalloc(size_3, 1)
    if (buf_0 == 0) {
        Sys_Error(740407, [C2daVaArg(tag = 1, i64 = int64(size_3), f64 = 0.0lf, raw = 0x0)])
    }
    Q_memset(buf_0, 0, size_3)
    return buf_0
}
[export, sideeffects]
def Z_TagMalloc(var size_4 : int; var tag : int) : int {
    var extra : int
    var start : int
    var rover : int
    var new_2 : int
    var base : int
    if (tag == 0) {
        Sys_Error(740450, [])
    }
    size_4 = int(uint64(size_4) + 40ul)
    size_4 += 4
    size_4 = size_4 + 7 & ~7
    rover = int(uint(c2da_mem[mainzone + 48]) | uint(c2da_mem[mainzone + 49]) << 0x8 | uint(c2da_mem[mainzone + 50]) << 0x10 | uint(c2da_mem[mainzone + 51]) << 0x18)
    base = rover
    start = int(uint(c2da_mem[base + 24]) | uint(c2da_mem[base + 25]) << 0x8 | uint(c2da_mem[base + 26]) << 0x10 | uint(c2da_mem[base + 27]) << 0x18)
    while (true) {
        if (rover == start) {
            return 0
        }
        if (int(uint(c2da_mem[rover + 4]) | uint(c2da_mem[rover + 5]) << 0x8 | uint(c2da_mem[rover + 6]) << 0x10 | uint(c2da_mem[rover + 7]) << 0x18) != 0) {
            rover = int(uint(c2da_mem[rover + 16]) | uint(c2da_mem[rover + 17]) << 0x8 | uint(c2da_mem[rover + 18]) << 0x10 | uint(c2da_mem[rover + 19]) << 0x18)
            base = rover
        } else {
            rover = int(uint(c2da_mem[rover + 16]) | uint(c2da_mem[rover + 17]) << 0x8 | uint(c2da_mem[rover + 18]) << 0x10 | uint(c2da_mem[rover + 19]) << 0x18)
        }
        if (!(int(uint(c2da_mem[base + 4]) | uint(c2da_mem[base + 5]) << 0x8 | uint(c2da_mem[base + 6]) << 0x10 | uint(c2da_mem[base + 7]) << 0x18) != 0 || int(uint(c2da_mem[base]) | uint(c2da_mem[base + 1]) << 0x8 | uint(c2da_mem[base + 2]) << 0x10 | uint(c2da_mem[base + 3]) << 0x18) < size_4)) {
            break
        }
    }
    extra = int(uint(c2da_mem[base]) | uint(c2da_mem[base + 1]) << 0x8 | uint(c2da_mem[base + 2]) << 0x10 | uint(c2da_mem[base + 3]) << 0x18) - size_4
    if (extra > 64) {
        new_2 = base + size_4
        let c2da_fresh89 : uint = uint(extra)
        c2da_mem[new_2] = uint8(c2da_fresh89)
        c2da_mem[new_2 + 1] = uint8(c2da_fresh89 >> 0x8)
        c2da_mem[new_2 + 2] = uint8(c2da_fresh89 >> 0x10)
        c2da_mem[new_2 + 3] = uint8(c2da_fresh89 >> 0x18)
        let c2da_fresh90 : int = 0
        let c2da_fresh91 : uint = uint(c2da_fresh90)
        c2da_mem[new_2 + 4] = uint8(c2da_fresh91)
        c2da_mem[new_2 + 5] = uint8(c2da_fresh91 >> 0x8)
        c2da_mem[new_2 + 6] = uint8(c2da_fresh91 >> 0x10)
        c2da_mem[new_2 + 7] = uint8(c2da_fresh91 >> 0x18)
        let c2da_fresh92 : uint = uint(base)
        c2da_mem[new_2 + 24] = uint8(c2da_fresh92)
        c2da_mem[new_2 + 25] = uint8(c2da_fresh92 >> 0x8)
        c2da_mem[new_2 + 26] = uint8(c2da_fresh92 >> 0x10)
        c2da_mem[new_2 + 27] = uint8(c2da_fresh92 >> 0x18)
        c2da_mem[new_2 + 28] = 0u8
        c2da_mem[new_2 + 29] = 0u8
        c2da_mem[new_2 + 30] = 0u8
        c2da_mem[new_2 + 31] = 0u8
        let c2da_fresh93 : int = 1919505
        let c2da_fresh94 : uint = uint(c2da_fresh93)
        c2da_mem[new_2 + 8] = uint8(c2da_fresh94)
        c2da_mem[new_2 + 9] = uint8(c2da_fresh94 >> 0x8)
        c2da_mem[new_2 + 10] = uint8(c2da_fresh94 >> 0x10)
        c2da_mem[new_2 + 11] = uint8(c2da_fresh94 >> 0x18)
        let c2da_fresh95 : int = int(uint(c2da_mem[base + 16]) | uint(c2da_mem[base + 17]) << 0x8 | uint(c2da_mem[base + 18]) << 0x10 | uint(c2da_mem[base + 19]) << 0x18)
        let c2da_fresh96 : uint = uint(c2da_fresh95)
        c2da_mem[new_2 + 16] = uint8(c2da_fresh96)
        c2da_mem[new_2 + 17] = uint8(c2da_fresh96 >> 0x8)
        c2da_mem[new_2 + 18] = uint8(c2da_fresh96 >> 0x10)
        c2da_mem[new_2 + 19] = uint8(c2da_fresh96 >> 0x18)
        c2da_mem[new_2 + 20] = 0u8
        c2da_mem[new_2 + 21] = 0u8
        c2da_mem[new_2 + 22] = 0u8
        c2da_mem[new_2 + 23] = 0u8
        let c2da_fresh97 : int = int(uint(c2da_mem[new_2 + 16]) | uint(c2da_mem[new_2 + 17]) << 0x8 | uint(c2da_mem[new_2 + 18]) << 0x10 | uint(c2da_mem[new_2 + 19]) << 0x18) + 24
        let c2da_fresh98 : uint = uint(new_2)
        c2da_mem[c2da_fresh97] = uint8(c2da_fresh98)
        c2da_mem[c2da_fresh97 + 1] = uint8(c2da_fresh98 >> 0x8)
        c2da_mem[c2da_fresh97 + 2] = uint8(c2da_fresh98 >> 0x10)
        c2da_mem[c2da_fresh97 + 3] = uint8(c2da_fresh98 >> 0x18)
        c2da_mem[c2da_fresh97 + 4] = 0u8
        c2da_mem[c2da_fresh97 + 5] = 0u8
        c2da_mem[c2da_fresh97 + 6] = 0u8
        c2da_mem[c2da_fresh97 + 7] = 0u8
        let c2da_fresh99 : uint = uint(new_2)
        c2da_mem[base + 16] = uint8(c2da_fresh99)
        c2da_mem[base + 17] = uint8(c2da_fresh99 >> 0x8)
        c2da_mem[base + 18] = uint8(c2da_fresh99 >> 0x10)
        c2da_mem[base + 19] = uint8(c2da_fresh99 >> 0x18)
        c2da_mem[base + 20] = 0u8
        c2da_mem[base + 21] = 0u8
        c2da_mem[base + 22] = 0u8
        c2da_mem[base + 23] = 0u8
        let c2da_fresh100 : uint = uint(size_4)
        c2da_mem[base] = uint8(c2da_fresh100)
        c2da_mem[base + 1] = uint8(c2da_fresh100 >> 0x8)
        c2da_mem[base + 2] = uint8(c2da_fresh100 >> 0x10)
        c2da_mem[base + 3] = uint8(c2da_fresh100 >> 0x18)
    }
    let c2da_fresh101 : uint = uint(tag)
    c2da_mem[base + 4] = uint8(c2da_fresh101)
    c2da_mem[base + 5] = uint8(c2da_fresh101 >> 0x8)
    c2da_mem[base + 6] = uint8(c2da_fresh101 >> 0x10)
    c2da_mem[base + 7] = uint8(c2da_fresh101 >> 0x18)
    let c2da_fresh102 : int = int(uint(c2da_mem[base + 16]) | uint(c2da_mem[base + 17]) << 0x8 | uint(c2da_mem[base + 18]) << 0x10 | uint(c2da_mem[base + 19]) << 0x18)
    let c2da_fresh103 : uint = uint(c2da_fresh102)
    c2da_mem[mainzone + 48] = uint8(c2da_fresh103)
    c2da_mem[mainzone + 49] = uint8(c2da_fresh103 >> 0x8)
    c2da_mem[mainzone + 50] = uint8(c2da_fresh103 >> 0x10)
    c2da_mem[mainzone + 51] = uint8(c2da_fresh103 >> 0x18)
    c2da_mem[mainzone + 52] = 0u8
    c2da_mem[mainzone + 53] = 0u8
    c2da_mem[mainzone + 54] = 0u8
    c2da_mem[mainzone + 55] = 0u8
    let c2da_fresh104 : int = 1919505
    let c2da_fresh105 : uint = uint(c2da_fresh104)
    c2da_mem[base + 8] = uint8(c2da_fresh105)
    c2da_mem[base + 9] = uint8(c2da_fresh105 >> 0x8)
    c2da_mem[base + 10] = uint8(c2da_fresh105 >> 0x10)
    c2da_mem[base + 11] = uint8(c2da_fresh105 >> 0x18)
    let c2da_fresh106 : int = base + int(uint(c2da_mem[base]) | uint(c2da_mem[base + 1]) << 0x8 | uint(c2da_mem[base + 2]) << 0x10 | uint(c2da_mem[base + 3]) << 0x18) - 4
    let c2da_fresh107 : int = 1919505
    let c2da_fresh108 : uint = uint(c2da_fresh107)
    c2da_mem[c2da_fresh106] = uint8(c2da_fresh108)
    c2da_mem[c2da_fresh106 + 1] = uint8(c2da_fresh108 >> 0x8)
    c2da_mem[c2da_fresh106 + 2] = uint8(c2da_fresh108 >> 0x10)
    c2da_mem[c2da_fresh106 + 3] = uint8(c2da_fresh108 >> 0x18)
    return base + 40
}
[export, sideeffects]
def Z_CheckHeap() {
    var block_2 : int = int(uint(c2da_mem[mainzone + 24]) | uint(c2da_mem[mainzone + 25]) << 0x8 | uint(c2da_mem[mainzone + 26]) << 0x10 | uint(c2da_mem[mainzone + 27]) << 0x18)
    while (true) {
        if (int(uint(c2da_mem[block_2 + 16]) | uint(c2da_mem[block_2 + 17]) << 0x8 | uint(c2da_mem[block_2 + 18]) << 0x10 | uint(c2da_mem[block_2 + 19]) << 0x18) == mainzone + 8) {
            break
        }
        if (block_2 + int(uint(c2da_mem[block_2]) | uint(c2da_mem[block_2 + 1]) << 0x8 | uint(c2da_mem[block_2 + 2]) << 0x10 | uint(c2da_mem[block_2 + 3]) << 0x18) != int(uint(c2da_mem[block_2 + 16]) | uint(c2da_mem[block_2 + 17]) << 0x8 | uint(c2da_mem[block_2 + 18]) << 0x10 | uint(c2da_mem[block_2 + 19]) << 0x18)) {
            Sys_Error(740484, [])
        }
        let c2da_fresh109 : int = int(uint(c2da_mem[block_2 + 16]) | uint(c2da_mem[block_2 + 17]) << 0x8 | uint(c2da_mem[block_2 + 18]) << 0x10 | uint(c2da_mem[block_2 + 19]) << 0x18) + 24
        if (int(uint(c2da_mem[c2da_fresh109]) | uint(c2da_mem[c2da_fresh109 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh109 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh109 + 3]) << 0x18) != block_2) {
            Sys_Error(740539, [])
        }
        var c2da_fresh111 : int = 0
        if (int(uint(c2da_mem[block_2 + 4]) | uint(c2da_mem[block_2 + 5]) << 0x8 | uint(c2da_mem[block_2 + 6]) << 0x10 | uint(c2da_mem[block_2 + 7]) << 0x18) == 0) {
            let c2da_fresh110 : int = int(uint(c2da_mem[block_2 + 16]) | uint(c2da_mem[block_2 + 17]) << 0x8 | uint(c2da_mem[block_2 + 18]) << 0x10 | uint(c2da_mem[block_2 + 19]) << 0x18) + 4
            if (int(uint(c2da_mem[c2da_fresh110]) | uint(c2da_mem[c2da_fresh110 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh110 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh110 + 3]) << 0x18) == 0) {
                c2da_fresh111 = 1
            }
        }
        if (c2da_fresh111 != 0) {
            Sys_Error(740594, [])
        }
        block_2 = int(uint(c2da_mem[block_2 + 16]) | uint(c2da_mem[block_2 + 17]) << 0x8 | uint(c2da_mem[block_2 + 18]) << 0x10 | uint(c2da_mem[block_2 + 19]) << 0x18)
    }
    return
}
[export, sideeffects]
def Hunk_Alloc(var size_5 : int) : int {
    return Hunk_AllocName(size_5, 740636)
}
[export, sideeffects]
def Hunk_HighAllocName(var size_6 : int; var name_0 : int) : int {
    var h_0 : int
    if (size_6 < 0) {
        Sys_Error(740644, [C2daVaArg(tag = 1, i64 = int64(size_6), f64 = 0.0lf, raw = 0x0)])
    }
    if (hunk_tempactive != 0u) {
        Hunk_FreeToHighMark(hunk_tempmark)
        hunk_tempactive = 0u
    }
    size_6 = int(16ul + uint64(size_6 + 15 & ~15))
    if (hunk_size - hunk_low_used - hunk_high_used < size_6) {
        Con_Printf(740677, [C2daVaArg(tag = 1, i64 = int64(size_6), f64 = 0.0lf, raw = 0x0)])
        return 0
    }
    hunk_high_used += size_6
    Cache_FreeHigh(hunk_high_used)
    h_0 = hunk_base + hunk_size - hunk_high_used
    c2da_lin_memset(h_0, 0, uint64(size_6))
    let c2da_fresh112 : uint = uint(size_6)
    c2da_mem[h_0 + 4] = uint8(c2da_fresh112)
    c2da_mem[h_0 + 5] = uint8(c2da_fresh112 >> 0x8)
    c2da_mem[h_0 + 6] = uint8(c2da_fresh112 >> 0x10)
    c2da_mem[h_0 + 7] = uint8(c2da_fresh112 >> 0x18)
    let c2da_fresh113 : int = 502268397
    let c2da_fresh114 : uint = uint(c2da_fresh113)
    c2da_mem[h_0] = uint8(c2da_fresh114)
    c2da_mem[h_0 + 1] = uint8(c2da_fresh114 >> 0x8)
    c2da_mem[h_0 + 2] = uint8(c2da_fresh114 >> 0x10)
    c2da_mem[h_0 + 3] = uint8(c2da_fresh114 >> 0x18)
    Q_strncpy(h_0 + 8, name_0, 8)
    return h_0 + 1 * 16
}
[export, sideeffects]
def Cache_FreeHigh(var new_high_hunk : int) {
    var c_2 : int
    var prev : int = 0
    while (true) {
        c_2 = int(uint(c2da_mem[697120]) | uint(c2da_mem[697121]) << 0x8 | uint(c2da_mem[697122]) << 0x10 | uint(c2da_mem[697123]) << 0x18)
        if (c_2 == 697088) {
            return
        }
        if (c_2 + int(uint(c2da_mem[c_2]) | uint(c2da_mem[c_2 + 1]) << 0x8 | uint(c2da_mem[c_2 + 2]) << 0x10 | uint(c2da_mem[c_2 + 3]) << 0x18) <= hunk_base + hunk_size - new_high_hunk) {
            return
        }
        if (c_2 == prev) {
            Cache_Free(int(uint(c2da_mem[c_2 + 8]) | uint(c2da_mem[c_2 + 9]) << 0x8 | uint(c2da_mem[c_2 + 10]) << 0x10 | uint(c2da_mem[c_2 + 11]) << 0x18))
        } else {
            Cache_Move(c_2)
            prev = c_2
        }
    }
}
var hunk_tempactive : uint = default<uint>

var hunk_tempmark : int = default<int>

[export, sideeffects]
def Hunk_FreeToHighMark(var mark : int) {
    if (hunk_tempactive != 0u) {
        hunk_tempactive = 0u
        Hunk_FreeToHighMark(hunk_tempmark)
    }
    if (mark < 0 || mark > hunk_high_used) {
        Sys_Error(740713, [C2daVaArg(tag = 1, i64 = int64(mark), f64 = 0.0lf, raw = 0x0)])
    }
    c2da_lin_memset(hunk_base + hunk_size - hunk_high_used, 0, uint64(hunk_high_used - mark))
    hunk_high_used = int(mark)  // nolint:PERF020
    return
}
[export, sideeffects]
def Hunk_LowMark() : int {
    return hunk_low_used
}
[export, sideeffects]
def Hunk_FreeToLowMark(var mark_0 : int) {
    if (mark_0 < 0 || mark_0 > hunk_low_used) {
        Sys_Error(740746, [C2daVaArg(tag = 1, i64 = int64(mark_0), f64 = 0.0lf, raw = 0x0)])
    }
    c2da_lin_memset(hunk_base + mark_0, 0, uint64(hunk_low_used - mark_0))
    hunk_low_used = int(mark_0)  // nolint:PERF020
    return
}
[export, sideeffects]
def Hunk_HighMark() : int {
    if (hunk_tempactive != 0u) {
        hunk_tempactive = 0u
        Hunk_FreeToHighMark(hunk_tempmark)
    }
    return hunk_high_used
}
[export, sideeffects]
def Hunk_TempAlloc(var size_7 : int) : int {
    var buf_1 : int
    size_7 = size_7 + 15 & ~15
    if (hunk_tempactive != 0u) {
        Hunk_FreeToHighMark(hunk_tempmark)
        hunk_tempactive = 0u
    }
    hunk_tempmark = Hunk_HighMark()
    buf_1 = Hunk_HighAllocName(size_7, 740778)
    hunk_tempactive = 1u
    return buf_1
}
[export, sideeffects]
def Hunk_Check() {
    var h_1 : int = hunk_base
    while (h_1 != hunk_base + hunk_low_used) {
        if (int(uint(c2da_mem[h_1]) | uint(c2da_mem[h_1 + 1]) << 0x8 | uint(c2da_mem[h_1 + 2]) << 0x10 | uint(c2da_mem[h_1 + 3]) << 0x18) != 502268397) {
            Sys_Error(740783, [])
        }
        if (int(uint(c2da_mem[h_1 + 4]) | uint(c2da_mem[h_1 + 5]) << 0x8 | uint(c2da_mem[h_1 + 6]) << 0x10 | uint(c2da_mem[h_1 + 7]) << 0x18) < 16 || int64(h_1 + int(uint(c2da_mem[h_1 + 4]) | uint(c2da_mem[h_1 + 5]) << 0x8 | uint(c2da_mem[h_1 + 6]) << 0x10 | uint(c2da_mem[h_1 + 7]) << 0x18) - hunk_base) > int64(hunk_size)) {
            Sys_Error(740812, [])
        }
        h_1 += int(uint(c2da_mem[h_1 + 4]) | uint(c2da_mem[h_1 + 5]) << 0x8 | uint(c2da_mem[h_1 + 6]) << 0x10 | uint(c2da_mem[h_1 + 7]) << 0x18)
    }
    return
}
[export, sideeffects]
def Cache_Check(var c_3 : int) : int {
    var cs_3 : int
    if (int(uint(c2da_mem[c_3]) | uint(c2da_mem[c_3 + 1]) << 0x8 | uint(c2da_mem[c_3 + 2]) << 0x10 | uint(c2da_mem[c_3 + 3]) << 0x18) == 0) {
        return 0
    }
    cs_3 = int(uint(c2da_mem[c_3]) | uint(c2da_mem[c_3 + 1]) << 0x8 | uint(c2da_mem[c_3 + 2]) << 0x10 | uint(c2da_mem[c_3 + 3]) << 0x18) - 1 * 64
    Cache_UnlinkLRU(cs_3)
    Cache_MakeLRU(cs_3)
    return int(uint(c2da_mem[c_3]) | uint(c2da_mem[c_3 + 1]) << 0x8 | uint(c2da_mem[c_3 + 2]) << 0x10 | uint(c2da_mem[c_3 + 3]) << 0x18)
}
[export, sideeffects]
def Cache_Alloc(var c_4 : int; var size_8 : int; var name_1 : int) : int {
    var cs_4 : int
    if (int(uint(c2da_mem[c_4]) | uint(c2da_mem[c_4 + 1]) << 0x8 | uint(c2da_mem[c_4 + 2]) << 0x10 | uint(c2da_mem[c_4 + 3]) << 0x18) != 0) {
        Sys_Error(740833, [])
    }
    if (size_8 <= 0) {
        Sys_Error(740865, [C2daVaArg(tag = 1, i64 = int64(size_8), f64 = 0.0lf, raw = 0x0)])
    }
    size_8 = int(uint64(size_8) + 64ul + 15ul & uint64(~15))
    while (true) {
        cs_4 = Cache_TryAlloc(size_8, 0u)
        if (cs_4 != 0) {
            c2da_lin_strncpy(cs_4 + 16, name_1, 16ul - 1ul)
            let c2da_fresh115 : int = cs_4 + 1 * 64
            let c2da_fresh116 : uint = uint(c2da_fresh115)
            c2da_mem[c_4] = uint8(c2da_fresh116)
            c2da_mem[c_4 + 1] = uint8(c2da_fresh116 >> 0x8)
            c2da_mem[c_4 + 2] = uint8(c2da_fresh116 >> 0x10)
            c2da_mem[c_4 + 3] = uint8(c2da_fresh116 >> 0x18)
            c2da_mem[c_4 + 4] = 0u8
            c2da_mem[c_4 + 5] = 0u8
            c2da_mem[c_4 + 6] = 0u8
            c2da_mem[c_4 + 7] = 0u8
            let c2da_fresh117 : uint = uint(c_4)
            c2da_mem[cs_4 + 8] = uint8(c2da_fresh117)
            c2da_mem[cs_4 + 9] = uint8(c2da_fresh117 >> 0x8)
            c2da_mem[cs_4 + 10] = uint8(c2da_fresh117 >> 0x10)
            c2da_mem[cs_4 + 11] = uint8(c2da_fresh117 >> 0x18)
            c2da_mem[cs_4 + 12] = 0u8
            c2da_mem[cs_4 + 13] = 0u8
            c2da_mem[cs_4 + 14] = 0u8
            c2da_mem[cs_4 + 15] = 0u8
            break
        }
        if (int(uint(c2da_mem[697136]) | uint(c2da_mem[697137]) << 0x8 | uint(c2da_mem[697138]) << 0x10 | uint(c2da_mem[697139]) << 0x18) == 697088) {
            Sys_Error(740886, [])
        }
        let c2da_fresh118 : int = int(uint(c2da_mem[697136]) | uint(c2da_mem[697137]) << 0x8 | uint(c2da_mem[697138]) << 0x10 | uint(c2da_mem[697139]) << 0x18) + 8
        Cache_Free(int(uint(c2da_mem[c2da_fresh118]) | uint(c2da_mem[c2da_fresh118 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh118 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh118 + 3]) << 0x18))
    }
    return Cache_Check(c_4)
}
[export, sideeffects]
def Cache_Report() {
    Con_DPrintf(740913, [C2daVaArg(tag = 2, i64 = 0, f64 = double(float(hunk_size - hunk_high_used - hunk_low_used) / float(1024 * 1024)), raw = 0x0)])
    return
}
[export, sideeffects]
def Z_Print(var zone_0 : int) {
    var block_3 : int
    Con_Printf(740940, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[mainzone]) | uint(c2da_mem[mainzone + 1]) << 0x8 | uint(c2da_mem[mainzone + 2]) << 0x10 | uint(c2da_mem[mainzone + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(mainzone))])
    block_3 = int(uint(c2da_mem[zone_0 + 24]) | uint(c2da_mem[zone_0 + 25]) << 0x8 | uint(c2da_mem[zone_0 + 26]) << 0x10 | uint(c2da_mem[zone_0 + 27]) << 0x18)
    while (true) {
        Con_Printf(740969, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(block_3)), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[block_3]) | uint(c2da_mem[block_3 + 1]) << 0x8 | uint(c2da_mem[block_3 + 2]) << 0x10 | uint(c2da_mem[block_3 + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[block_3 + 4]) | uint(c2da_mem[block_3 + 5]) << 0x8 | uint(c2da_mem[block_3 + 6]) << 0x10 | uint(c2da_mem[block_3 + 7]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
        if (int(uint(c2da_mem[block_3 + 16]) | uint(c2da_mem[block_3 + 17]) << 0x8 | uint(c2da_mem[block_3 + 18]) << 0x10 | uint(c2da_mem[block_3 + 19]) << 0x18) == zone_0 + 8) {
            break
        }
        if (block_3 + int(uint(c2da_mem[block_3]) | uint(c2da_mem[block_3 + 1]) << 0x8 | uint(c2da_mem[block_3 + 2]) << 0x10 | uint(c2da_mem[block_3 + 3]) << 0x18) != int(uint(c2da_mem[block_3 + 16]) | uint(c2da_mem[block_3 + 17]) << 0x8 | uint(c2da_mem[block_3 + 18]) << 0x10 | uint(c2da_mem[block_3 + 19]) << 0x18)) {
            Con_Printf(741002, [])
        }
        let c2da_fresh119 : int = int(uint(c2da_mem[block_3 + 16]) | uint(c2da_mem[block_3 + 17]) << 0x8 | uint(c2da_mem[block_3 + 18]) << 0x10 | uint(c2da_mem[block_3 + 19]) << 0x18) + 24
        if (int(uint(c2da_mem[c2da_fresh119]) | uint(c2da_mem[c2da_fresh119 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh119 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh119 + 3]) << 0x18) != block_3) {
            Con_Printf(741051, [])
        }
        var c2da_fresh121 : int = 0
        if (int(uint(c2da_mem[block_3 + 4]) | uint(c2da_mem[block_3 + 5]) << 0x8 | uint(c2da_mem[block_3 + 6]) << 0x10 | uint(c2da_mem[block_3 + 7]) << 0x18) == 0) {
            let c2da_fresh120 : int = int(uint(c2da_mem[block_3 + 16]) | uint(c2da_mem[block_3 + 17]) << 0x8 | uint(c2da_mem[block_3 + 18]) << 0x10 | uint(c2da_mem[block_3 + 19]) << 0x18) + 4
            if (int(uint(c2da_mem[c2da_fresh120]) | uint(c2da_mem[c2da_fresh120 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh120 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh120 + 3]) << 0x18) == 0) {
                c2da_fresh121 = 1
            }
        }
        if (c2da_fresh121 != 0) {
            Con_Printf(741100, [])
        }
        block_3 = int(uint(c2da_mem[block_3 + 16]) | uint(c2da_mem[block_3 + 17]) << 0x8 | uint(c2da_mem[block_3 + 18]) << 0x10 | uint(c2da_mem[block_3 + 19]) << 0x18)
    }
    return
}
[export, sideeffects]
def Hunk_Print(var all : uint) {
    let c2da_saved_sp : int = c2da_lin_sp
    Hunk_Print_c2da_frame(all, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Cache_Print() {
    var cd : int = int(uint(c2da_mem[697128]) | uint(c2da_mem[697129]) << 0x8 | uint(c2da_mem[697130]) << 0x10 | uint(c2da_mem[697131]) << 0x18)
    while (cd != 697088) {
        Con_Printf(741281, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[cd]) | uint(c2da_mem[cd + 1]) << 0x8 | uint(c2da_mem[cd + 2]) << 0x10 | uint(c2da_mem[cd + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(cd + 16))])
        cd = int(uint(c2da_mem[cd + 40]) | uint(c2da_mem[cd + 41]) << 0x8 | uint(c2da_mem[cd + 42]) << 0x10 | uint(c2da_mem[cd + 43]) << 0x18)
    }
    return
}
[export, sideeffects]
def Cache_Compact() {
    return
}
[sideeffects]
def private Hunk_Print_c2da_frame(var all : uint; c2da_fp : int) {
    var h_2 : int
    var next : int
    var endlow : int
    var starthigh : int
    var endhigh : int
    var count : int
    var sum : int
    var totalblocks : int
    let c2da_fresh122 : int8 = int8(0)
    c2da_mem[c2da_fp + 8] = uint8(c2da_fresh122)
    count = 0
    sum = 0
    totalblocks = 0
    h_2 = hunk_base
    endlow = hunk_base + hunk_low_used
    starthigh = hunk_base + hunk_size - hunk_high_used
    endhigh = hunk_base + hunk_size
    Con_Printf(741136, [C2daVaArg(tag = 1, i64 = int64(hunk_size), f64 = 0.0lf, raw = 0x0)])
    Con_Printf(741168, [])
    while (true) {
        if (h_2 == endlow) {
            Con_Printf(741168, [])
            Con_Printf(741195, [C2daVaArg(tag = 1, i64 = int64(hunk_size - hunk_low_used - hunk_high_used), f64 = 0.0lf, raw = 0x0)])
            Con_Printf(741168, [])
            h_2 = starthigh
        }
        if (h_2 == endhigh) {
            break
        }
        if (int(uint(c2da_mem[h_2]) | uint(c2da_mem[h_2 + 1]) << 0x8 | uint(c2da_mem[h_2 + 2]) << 0x10 | uint(c2da_mem[h_2 + 3]) << 0x18) != 502268397) {
            Sys_Error(740783, [])
        }
        if (int(uint(c2da_mem[h_2 + 4]) | uint(c2da_mem[h_2 + 5]) << 0x8 | uint(c2da_mem[h_2 + 6]) << 0x10 | uint(c2da_mem[h_2 + 7]) << 0x18) < 16 || int64(h_2 + int(uint(c2da_mem[h_2 + 4]) | uint(c2da_mem[h_2 + 5]) << 0x8 | uint(c2da_mem[h_2 + 6]) << 0x10 | uint(c2da_mem[h_2 + 7]) << 0x18) - hunk_base) > int64(hunk_size)) {
            Sys_Error(740812, [])
        }
        next = h_2 + int(uint(c2da_mem[h_2 + 4]) | uint(c2da_mem[h_2 + 5]) << 0x8 | uint(c2da_mem[h_2 + 6]) << 0x10 | uint(c2da_mem[h_2 + 7]) << 0x18)
        count++
        totalblocks++
        sum += int(uint(c2da_mem[h_2 + 4]) | uint(c2da_mem[h_2 + 5]) << 0x8 | uint(c2da_mem[h_2 + 6]) << 0x10 | uint(c2da_mem[h_2 + 7]) << 0x18)
        c2da_lin_memcpy(c2da_fp, h_2 + 8, 8ul)
        if (all != 0u) {
            Con_Printf(741221, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(h_2)), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[h_2 + 4]) | uint(c2da_mem[h_2 + 5]) << 0x8 | uint(c2da_mem[h_2 + 6]) << 0x10 | uint(c2da_mem[h_2 + 7]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
        }
        if (next == endlow || next == endhigh || c2da_lin_strncmp(h_2 + 8, next + 8, 8ul) != 0) {
            if (all == 0u) {
                Con_Printf(741235, [C2daVaArg(tag = 1, i64 = int64(sum), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
            }
            count = 0
            sum = 0
        }
        h_2 = next
    }
    Con_Printf(741168, [])
    Con_Printf(741263, [C2daVaArg(tag = 1, i64 = int64(totalblocks), f64 = 0.0lf, raw = 0x0)])
    return
}

// This unit's static data, at heap offset 740064.
let private c2da_lin_static_zone_seg = fixed_array<int>(740064, 1226)
let private c2da_lin_static_zone = fixed_array<uint64>(0x654d00656e6f7a2dul, 0x696e495f79726f6dul, 0x6d20756f79203a74ul, 0x6365707320747375ul, 0x6973206120796669ul, 0x424b206e6920657aul, 0x2d20726574666120ul, 0x6e6f7a00656e6f7aul, 0x415f6b6e75480065ul, 0x6162203a636f6c6cul, 0x203a657a69732064ul, 0x5f6b6e7548006925ul, 0x66203a636f6c6c41ul, 0x6e6f2064656c6961ul, 0x6574796220692520ul, 0x5f65686361430073ul, 0x6f6e203a65657246ul, 0x61636f6c6c612074ul, 0x6863614300646574ul, 0x6b6e696c6e555f65ul, 0x4c554e203a55524cul, 0x43006b6e696c204cul, 0x7972545f65686361ul, 0x25203a636f6c6c41ul, 0x6572672073692069ul, 0x6568742072657461ul, 0x682065657266206eul, 0x68636143006b6e75ul, 0x524c656b614d5f65ul, 0x7669746361203a55ul, 0x66006b6e696c2065ul, 0x465f5a006873756cul, 0x4c554e203a656572ul, 0x65746e696f70204cul, 0x656572465f5a0072ul, 0x206465657266203aul, 0x65746e696f702061ul, 0x756f687469772072ul, 0x4449454e4f5a2074ul, 0x3a656572465f5a00ul, 0x6120646565726620ul, 0x7020646565726620ul, 0x5a007265746e696ful, 0x3a636f6c6c614d5ful, 0x2064656c69616620ul, 0x636f6c6c61206e6ful, 0x666f206e6f697461ul, 0x6574796220692520ul, 0x4d6761545f5a0073ul, 0x74203a636f6c6c61ul, 0x206f742064656972ul, 0x2030206120657375ul, 0x68435f5a00676174ul, 0x3a706165486b6365ul, 0x73206b636f6c6220ul, 0x73656f6420657a69ul, 0x756f7420746f6e20ul, 0x6e20656874206863ul, 0x636f6c6220747865ul, 0x6568435f5a000a6bul, 0x203a706165486b63ul, 0x6f6c62207478656eul, 0x6e73656f64206b63ul, 0x2065766168207427ul, 0x62207265706f7270ul, 0x6b6e696c206b6361ul, 0x636568435f5a000aul, 0x74203a706165486bul, 0x65736e6f63206f77ul, 0x6620657669747563ul, 0x636f6c6220656572ul, 0x6e6b6e75000a736bul, 0x6b6e7548006e776ful, 0x6c6c41686769485ful, 0x203a656d614e636ful, 0x657a697320646162ul, 0x6e7548006925203aul, 0x6c41686769485f6bul, 0x696166203a636f6cul, 0x25206e6f2064656cul, 0xa73657479622069ul, 0x72465f6b6e754800ul, 0x686769486f546565ul, 0x6162203a6b72614dul, 0x25206b72616d2064ul, 0x465f6b6e75480069ul, 0x776f4c6f54656572ul, 0x6162203a6b72614dul, 0x25206b72616d2064ul, 0x4800706d65740069ul, 0x636568435f6b6e75ul, 0x7368617274203a6bul, 0x69746e6573206465ul, 0x6b6e7548006c616eul, 0x203a6b636568435ful, 0x657a697320646162ul, 0x415f656863614300ul, 0x6c61203a636f6c6cul, 0x612079646165726cul, 0x64657461636f6c6cul, 0x415f656863614300ul, 0x6973203a636f6c6cul, 0x614300692520657aul, 0x6f6c6c415f656863ul, 0x6f2074756f203a63ul, 0x79726f6d656d2066ul, 0x6d2066312e342500ul, 0x2065747962616765ul, 0x6361632061746164ul, 0x656e6f7a000a6568ul, 0x25203a657a697320ul, 0x7461636f6c202069ul, 0xa7025203a6e6f69ul, 0x253a6b636f6c6200ul, 0x7a69732020202070ul, 0x2020206937253a65ul, 0x6933253a67617420ul, 0x3a524f525245000aul, 0x73206b636f6c6220ul, 0x73656f6420657a69ul, 0x756f7420746f6e20ul, 0x6e20656874206863ul, 0x636f6c6220747865ul, 0x524f525245000a6bul, 0x62207478656e203aul, 0x656f64206b636f6cul, 0x7661682074276e73ul, 0x7265706f72702065ul, 0x696c206b63616220ul, 0x4f525245000a6b6eul, 0x63206f7774203a52ul, 0x6974756365736e6ful, 0x2065657266206576ul, 0xa736b636f6c62ul, 0x2020202020202020ul, 0x74206938253a2020ul, 0x6e7568206c61746ful, 0xa657a6973206bul, 0x2d2d2d2d2d2d2d2dul, 0x2d2d2d2d2d2d2d2dul, 0x2d2d2d2d2d2d2d2dul, 0x2020202020000a2dul, 0x38253a2020202020ul, 0x4e49414d45522069ul, 0x703825000a474e49ul, 0x3825206938253a20ul, 0x2020202020000a73ul, 0x38253a2020202020ul, 0x5428207338252069ul, 0x25000a294c41544ful, 0x6c61746f74206938ul, 0xa736b636f6c6220ul, 0x25203a2069382500ul, 0xa73ul)

[init]
def private c2da_lin_init_static_zone() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_zone_seg[s * 2]
        for (k in range(c2da_lin_static_zone_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_zone[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_zone() {
    if (length(c2da_fn_table0) < 224) {
        resize(c2da_fn_table0, 224)
    }
    c2da_fn_table0[223] = @@Cache_Flush
}

[init]
def private c2da_lin_relink_init_zone() {
    c2da_relink_zone()
}
