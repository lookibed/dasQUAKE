var r_cache_thrash : uint = default<uint>

[export, sideeffects]
def D_SurfaceCacheForRes(var width : int; var height : int) : int {
    var size : int
    var pix : int
    if (COM_CheckParm(715216) != 0) {
        let c2da_fresh0 : int = com_argv + int(COM_CheckParm(715216) + 1) * 8
        size = Q_atoi(int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18)) * 1024
        return size
    }
    size = 600 * 1024
    pix = width * height
    if (pix > 64000) {
        size += (pix - 64000) * 3
    }
    return size
}
[export, sideeffects]
def D_FlushCaches() {
    var c : int
    if (sc_base == 0) {
        return
    }
    c = sc_base
    while (c != 0) {
        let c2da_fresh6 : int = int(uint(c2da_mem[c + 8]) | uint(c2da_mem[c + 9]) << 0x8 | uint(c2da_mem[c + 10]) << 0x10 | uint(c2da_mem[c + 11]) << 0x18)
        if (c2da_fresh6 != 0) {
            let c2da_fresh1 : int = c2da_fresh6
            let c2da_fresh2 : uint = 0u
            c2da_mem[c2da_fresh1] = uint8(c2da_fresh2)
            c2da_mem[c2da_fresh1 + 1] = uint8(c2da_fresh2 >> 0x8)
            c2da_mem[c2da_fresh1 + 2] = uint8(c2da_fresh2 >> 0x10)
            c2da_mem[c2da_fresh1 + 3] = uint8(c2da_fresh2 >> 0x18)
            c2da_mem[c2da_fresh1 + 4] = 0u8
            c2da_mem[c2da_fresh1 + 5] = 0u8
            c2da_mem[c2da_fresh1 + 6] = 0u8
            c2da_mem[c2da_fresh1 + 7] = 0u8
        }
        c = int(uint(c2da_mem[c]) | uint(c2da_mem[c + 1]) << 0x8 | uint(c2da_mem[c + 2]) << 0x10 | uint(c2da_mem[c + 3]) << 0x18)
    }
    sc_rover = int(sc_base)  // nolint:PERF020
    let c2da_fresh3 : uint = 0u
    c2da_mem[sc_base] = uint8(c2da_fresh3)
    c2da_mem[sc_base + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[sc_base + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[sc_base + 3] = uint8(c2da_fresh3 >> 0x18)
    c2da_mem[sc_base + 4] = 0u8
    c2da_mem[sc_base + 5] = 0u8
    c2da_mem[sc_base + 6] = 0u8
    c2da_mem[sc_base + 7] = 0u8
    let c2da_fresh4 : uint = 0u
    c2da_mem[sc_base + 8] = uint8(c2da_fresh4)
    c2da_mem[sc_base + 9] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[sc_base + 10] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[sc_base + 11] = uint8(c2da_fresh4 >> 0x18)
    c2da_mem[sc_base + 12] = 0u8
    c2da_mem[sc_base + 13] = 0u8
    c2da_mem[sc_base + 14] = 0u8
    c2da_mem[sc_base + 15] = 0u8
    let c2da_fresh5 : uint = uint(sc_size)
    c2da_mem[sc_base + 36] = uint8(c2da_fresh5)
    c2da_mem[sc_base + 37] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[sc_base + 38] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[sc_base + 39] = uint8(c2da_fresh5 >> 0x18)
    return
}
var sc_size : int = default<int>

var sc_base : int = default<int>

var sc_rover : int = default<int>

[export, sideeffects]
def D_InitCaches(var buffer : int; var size_0 : int) {
    if (uint(msg_suppress_1) == 0u) {
        Con_Printf(715231, [C2daVaArg(tag = 1, i64 = int64(size_0 / 1024), f64 = 0.0lf, raw = 0x0)])
    }
    sc_size = size_0 - 4
    sc_base = int(buffer)  // nolint:PERF020
    sc_rover = int(sc_base)  // nolint:PERF020
    let c2da_fresh7 : uint = 0u
    c2da_mem[sc_base] = uint8(c2da_fresh7)
    c2da_mem[sc_base + 1] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[sc_base + 2] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[sc_base + 3] = uint8(c2da_fresh7 >> 0x18)
    c2da_mem[sc_base + 4] = 0u8
    c2da_mem[sc_base + 5] = 0u8
    c2da_mem[sc_base + 6] = 0u8
    c2da_mem[sc_base + 7] = 0u8
    let c2da_fresh8 : uint = 0u
    c2da_mem[sc_base + 8] = uint8(c2da_fresh8)
    c2da_mem[sc_base + 9] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[sc_base + 10] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[sc_base + 11] = uint8(c2da_fresh8 >> 0x18)
    c2da_mem[sc_base + 12] = 0u8
    c2da_mem[sc_base + 13] = 0u8
    c2da_mem[sc_base + 14] = 0u8
    c2da_mem[sc_base + 15] = 0u8
    let c2da_fresh9 : uint = uint(sc_size)
    c2da_mem[sc_base + 36] = uint8(c2da_fresh9)
    c2da_mem[sc_base + 37] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[sc_base + 38] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[sc_base + 39] = uint8(c2da_fresh9 >> 0x18)
    D_ClearCacheGuard()
    return
}
[export, sideeffects]
def D_ClearCacheGuard() {
    var s : int = sc_base + sc_size
    for (i in range(0, 4)) {
        let c2da_fresh10 : uint8 = uint8(i)
        c2da_mem[s + i] = c2da_fresh10
    }
    return
}
[export, sideeffects]
def D_CacheSurface(var surface : int; var miplevel_0 : int) : int {
    var cache : int
    let c2da_fresh11 : int = int(uint(c2da_mem[surface + 80]) | uint(c2da_mem[surface + 81]) << 0x8 | uint(c2da_mem[surface + 82]) << 0x10 | uint(c2da_mem[surface + 83]) << 0x18) + 40
    r_drawsurf.texture = R_TextureAnimation(int(uint(c2da_mem[c2da_fresh11]) | uint(c2da_mem[c2da_fresh11 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh11 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh11 + 3]) << 0x18))
    r_drawsurf.lightadj[0] = d_lightstylevalue[int(c2da_mem[surface + 88 + 0])]
    r_drawsurf.lightadj[1] = d_lightstylevalue[int(c2da_mem[surface + 88 + 1])]
    r_drawsurf.lightadj[2] = d_lightstylevalue[int(c2da_mem[surface + 88 + 2])]
    r_drawsurf.lightadj[3] = d_lightstylevalue[int(c2da_mem[surface + 88 + 3])]
    cache = int(uint(c2da_mem[surface + 40 + miplevel_0 * 8]) | uint(c2da_mem[surface + 40 + miplevel_0 * 8 + 1]) << 0x8 | uint(c2da_mem[surface + 40 + miplevel_0 * 8 + 2]) << 0x10 | uint(c2da_mem[surface + 40 + miplevel_0 * 8 + 3]) << 0x18)
    if (cache != 0 && int(uint(c2da_mem[cache + 32]) | uint(c2da_mem[cache + 33]) << 0x8 | uint(c2da_mem[cache + 34]) << 0x10 | uint(c2da_mem[cache + 35]) << 0x18) == 0 && int(uint(c2da_mem[surface + 4]) | uint(c2da_mem[surface + 5]) << 0x8 | uint(c2da_mem[surface + 6]) << 0x10 | uint(c2da_mem[surface + 7]) << 0x18) != r_framecount && int(uint(c2da_mem[cache + 56]) | uint(c2da_mem[cache + 57]) << 0x8 | uint(c2da_mem[cache + 58]) << 0x10 | uint(c2da_mem[cache + 59]) << 0x18) == r_drawsurf.texture && int(uint(c2da_mem[cache + 16 + 0 * 4]) | uint(c2da_mem[cache + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[cache + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[cache + 16 + 0 * 4 + 3]) << 0x18) == r_drawsurf.lightadj[0] && int(uint(c2da_mem[cache + 16 + 1 * 4]) | uint(c2da_mem[cache + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[cache + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[cache + 16 + 1 * 4 + 3]) << 0x18) == r_drawsurf.lightadj[1] && int(uint(c2da_mem[cache + 16 + 2 * 4]) | uint(c2da_mem[cache + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[cache + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[cache + 16 + 2 * 4 + 3]) << 0x18) == r_drawsurf.lightadj[2] && int(uint(c2da_mem[cache + 16 + 3 * 4]) | uint(c2da_mem[cache + 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[cache + 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[cache + 16 + 3 * 4 + 3]) << 0x18) == r_drawsurf.lightadj[3]) {
        return cache
    }
    surfscale = float(1.0lf / double(1 << miplevel_0))
    r_drawsurf.surfmip = miplevel_0
    r_drawsurf.surfwidth = int(int16(uint(c2da_mem[surface + 76 + 0 * 2]) | uint(c2da_mem[surface + 76 + 0 * 2 + 1]) << 0x8)) >> miplevel_0
    r_drawsurf.rowbytes = r_drawsurf.surfwidth
    r_drawsurf.surfheight = int(int16(uint(c2da_mem[surface + 76 + 1 * 2]) | uint(c2da_mem[surface + 76 + 1 * 2 + 1]) << 0x8)) >> miplevel_0
    if (cache == 0) {
        cache = D_SCAlloc(r_drawsurf.surfwidth, r_drawsurf.surfwidth * r_drawsurf.surfheight)
        let c2da_fresh12 : uint = uint(cache)
        c2da_mem[surface + 40 + miplevel_0 * 8] = uint8(c2da_fresh12)
        c2da_mem[surface + 40 + miplevel_0 * 8 + 1] = uint8(c2da_fresh12 >> 0x8)
        c2da_mem[surface + 40 + miplevel_0 * 8 + 2] = uint8(c2da_fresh12 >> 0x10)
        c2da_mem[surface + 40 + miplevel_0 * 8 + 3] = uint8(c2da_fresh12 >> 0x18)
        c2da_mem[surface + 40 + miplevel_0 * 8 + 4] = 0u8
        c2da_mem[surface + 40 + miplevel_0 * 8 + 5] = 0u8
        c2da_mem[surface + 40 + miplevel_0 * 8 + 6] = 0u8
        c2da_mem[surface + 40 + miplevel_0 * 8 + 7] = 0u8
        let c2da_fresh13 : int = surface + 40 + miplevel_0 * 8
        let c2da_fresh14 : uint = uint(c2da_fresh13)
        c2da_mem[cache + 8] = uint8(c2da_fresh14)
        c2da_mem[cache + 9] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[cache + 10] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[cache + 11] = uint8(c2da_fresh14 >> 0x18)
        c2da_mem[cache + 12] = 0u8
        c2da_mem[cache + 13] = 0u8
        c2da_mem[cache + 14] = 0u8
        c2da_mem[cache + 15] = 0u8
        let c2da_fresh15 : uint = float_bits_to_uint(surfscale)
        c2da_mem[cache + 48] = uint8(c2da_fresh15)
        c2da_mem[cache + 49] = uint8(c2da_fresh15 >> 0x8)
        c2da_mem[cache + 50] = uint8(c2da_fresh15 >> 0x10)
        c2da_mem[cache + 51] = uint8(c2da_fresh15 >> 0x18)
    }
    if (int(uint(c2da_mem[surface + 4]) | uint(c2da_mem[surface + 5]) << 0x8 | uint(c2da_mem[surface + 6]) << 0x10 | uint(c2da_mem[surface + 7]) << 0x18) == r_framecount) {
        let c2da_fresh16 : int = 1
        let c2da_fresh17 : uint = uint(c2da_fresh16)
        c2da_mem[cache + 32] = uint8(c2da_fresh17)
        c2da_mem[cache + 33] = uint8(c2da_fresh17 >> 0x8)
        c2da_mem[cache + 34] = uint8(c2da_fresh17 >> 0x10)
        c2da_mem[cache + 35] = uint8(c2da_fresh17 >> 0x18)
    } else {
        let c2da_fresh18 : int = 0
        let c2da_fresh19 : uint = uint(c2da_fresh18)
        c2da_mem[cache + 32] = uint8(c2da_fresh19)
        c2da_mem[cache + 33] = uint8(c2da_fresh19 >> 0x8)
        c2da_mem[cache + 34] = uint8(c2da_fresh19 >> 0x10)
        c2da_mem[cache + 35] = uint8(c2da_fresh19 >> 0x18)
    }
    r_drawsurf.surfdat = cache + 64
    let c2da_fresh20 : int = r_drawsurf.texture
    let c2da_fresh21 : uint = uint(c2da_fresh20)
    c2da_mem[cache + 56] = uint8(c2da_fresh21)
    c2da_mem[cache + 57] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[cache + 58] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[cache + 59] = uint8(c2da_fresh21 >> 0x18)
    c2da_mem[cache + 60] = 0u8
    c2da_mem[cache + 61] = 0u8
    c2da_mem[cache + 62] = 0u8
    c2da_mem[cache + 63] = 0u8
    let c2da_fresh22 : int = r_drawsurf.lightadj[0]
    let c2da_fresh23 : uint = uint(c2da_fresh22)
    c2da_mem[cache + 16 + 0 * 4] = uint8(c2da_fresh23)
    c2da_mem[cache + 16 + 0 * 4 + 1] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[cache + 16 + 0 * 4 + 2] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[cache + 16 + 0 * 4 + 3] = uint8(c2da_fresh23 >> 0x18)
    let c2da_fresh24 : int = r_drawsurf.lightadj[1]
    let c2da_fresh25 : uint = uint(c2da_fresh24)
    c2da_mem[cache + 16 + 1 * 4] = uint8(c2da_fresh25)
    c2da_mem[cache + 16 + 1 * 4 + 1] = uint8(c2da_fresh25 >> 0x8)
    c2da_mem[cache + 16 + 1 * 4 + 2] = uint8(c2da_fresh25 >> 0x10)
    c2da_mem[cache + 16 + 1 * 4 + 3] = uint8(c2da_fresh25 >> 0x18)
    let c2da_fresh26 : int = r_drawsurf.lightadj[2]
    let c2da_fresh27 : uint = uint(c2da_fresh26)
    c2da_mem[cache + 16 + 2 * 4] = uint8(c2da_fresh27)
    c2da_mem[cache + 16 + 2 * 4 + 1] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[cache + 16 + 2 * 4 + 2] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[cache + 16 + 2 * 4 + 3] = uint8(c2da_fresh27 >> 0x18)
    let c2da_fresh28 : int = r_drawsurf.lightadj[3]
    let c2da_fresh29 : uint = uint(c2da_fresh28)
    c2da_mem[cache + 16 + 3 * 4] = uint8(c2da_fresh29)
    c2da_mem[cache + 16 + 3 * 4 + 1] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[cache + 16 + 3 * 4 + 2] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[cache + 16 + 3 * 4 + 3] = uint8(c2da_fresh29 >> 0x18)
    r_drawsurf.surf = surface
    c_surf = c_surf + 1
    R_DrawSurface()
    return int(uint(c2da_mem[surface + 40 + miplevel_0 * 8]) | uint(c2da_mem[surface + 40 + miplevel_0 * 8 + 1]) << 0x8 | uint(c2da_mem[surface + 40 + miplevel_0 * 8 + 2]) << 0x10 | uint(c2da_mem[surface + 40 + miplevel_0 * 8 + 3]) << 0x18)
}
var surfscale : float = default<float>

[export, sideeffects]
def D_SCAlloc(var width_0 : int; var size_1 : int) : int {
    var new_0 : int
    var wrapped_this_time : uint
    if (width_0 < 0 || width_0 > 256) {
        Sys_Error(715250, [C2daVaArg(tag = 1, i64 = int64(width_0), f64 = 0.0lf, raw = 0x0)])
    }
    if (size_1 <= 0 || size_1 > 65536) {
        Sys_Error(715281, [C2daVaArg(tag = 1, i64 = int64(size_1), f64 = 0.0lf, raw = 0x0)])
    }
    size_1 = 64 + size_1
    size_1 = size_1 + 3 & ~3
    if (size_1 > sc_size) {
        Sys_Error(715311, [C2daVaArg(tag = 1, i64 = int64(size_1), f64 = 0.0lf, raw = 0x0)])
    }
    wrapped_this_time = 0u
    if (sc_rover == 0 || int64(sc_rover - sc_base) > int64(sc_size - size_1)) {
        if (sc_rover != 0) {
            wrapped_this_time = 1u
        }
        sc_rover = int(sc_base)  // nolint:PERF020
    }
    new_0 = sc_rover
    let c2da_fresh52 : int = int(uint(c2da_mem[sc_rover + 8]) | uint(c2da_mem[sc_rover + 9]) << 0x8 | uint(c2da_mem[sc_rover + 10]) << 0x10 | uint(c2da_mem[sc_rover + 11]) << 0x18)
    if (c2da_fresh52 != 0) {
        let c2da_fresh30 : int = c2da_fresh52
        let c2da_fresh31 : uint = 0u
        c2da_mem[c2da_fresh30] = uint8(c2da_fresh31)
        c2da_mem[c2da_fresh30 + 1] = uint8(c2da_fresh31 >> 0x8)
        c2da_mem[c2da_fresh30 + 2] = uint8(c2da_fresh31 >> 0x10)
        c2da_mem[c2da_fresh30 + 3] = uint8(c2da_fresh31 >> 0x18)
        c2da_mem[c2da_fresh30 + 4] = 0u8
        c2da_mem[c2da_fresh30 + 5] = 0u8
        c2da_mem[c2da_fresh30 + 6] = 0u8
        c2da_mem[c2da_fresh30 + 7] = 0u8
    }
    while (int(uint(c2da_mem[new_0 + 36]) | uint(c2da_mem[new_0 + 37]) << 0x8 | uint(c2da_mem[new_0 + 38]) << 0x10 | uint(c2da_mem[new_0 + 39]) << 0x18) < size_1) {
        sc_rover = int(uint(c2da_mem[sc_rover]) | uint(c2da_mem[sc_rover + 1]) << 0x8 | uint(c2da_mem[sc_rover + 2]) << 0x10 | uint(c2da_mem[sc_rover + 3]) << 0x18)
        if (sc_rover == 0) {
            Sys_Error(715338, [])
        }
        let c2da_fresh54 : int = int(uint(c2da_mem[sc_rover + 8]) | uint(c2da_mem[sc_rover + 9]) << 0x8 | uint(c2da_mem[sc_rover + 10]) << 0x10 | uint(c2da_mem[sc_rover + 11]) << 0x18)
        if (c2da_fresh54 != 0) {
            let c2da_fresh32 : int = c2da_fresh54
            let c2da_fresh33 : uint = 0u
            c2da_mem[c2da_fresh32] = uint8(c2da_fresh33)
            c2da_mem[c2da_fresh32 + 1] = uint8(c2da_fresh33 >> 0x8)
            c2da_mem[c2da_fresh32 + 2] = uint8(c2da_fresh33 >> 0x10)
            c2da_mem[c2da_fresh32 + 3] = uint8(c2da_fresh33 >> 0x18)
            c2da_mem[c2da_fresh32 + 4] = 0u8
            c2da_mem[c2da_fresh32 + 5] = 0u8
            c2da_mem[c2da_fresh32 + 6] = 0u8
            c2da_mem[c2da_fresh32 + 7] = 0u8
        }
        let c2da_fresh34 : int = int(uint(c2da_mem[new_0 + 36]) | uint(c2da_mem[new_0 + 37]) << 0x8 | uint(c2da_mem[new_0 + 38]) << 0x10 | uint(c2da_mem[new_0 + 39]) << 0x18) + int(uint(c2da_mem[sc_rover + 36]) | uint(c2da_mem[sc_rover + 37]) << 0x8 | uint(c2da_mem[sc_rover + 38]) << 0x10 | uint(c2da_mem[sc_rover + 39]) << 0x18)
        let c2da_fresh35 : uint = uint(c2da_fresh34)
        c2da_mem[new_0 + 36] = uint8(c2da_fresh35)
        c2da_mem[new_0 + 37] = uint8(c2da_fresh35 >> 0x8)
        c2da_mem[new_0 + 38] = uint8(c2da_fresh35 >> 0x10)
        c2da_mem[new_0 + 39] = uint8(c2da_fresh35 >> 0x18)
        let c2da_fresh36 : int = int(uint(c2da_mem[sc_rover]) | uint(c2da_mem[sc_rover + 1]) << 0x8 | uint(c2da_mem[sc_rover + 2]) << 0x10 | uint(c2da_mem[sc_rover + 3]) << 0x18)
        let c2da_fresh37 : uint = uint(c2da_fresh36)
        c2da_mem[new_0] = uint8(c2da_fresh37)
        c2da_mem[new_0 + 1] = uint8(c2da_fresh37 >> 0x8)
        c2da_mem[new_0 + 2] = uint8(c2da_fresh37 >> 0x10)
        c2da_mem[new_0 + 3] = uint8(c2da_fresh37 >> 0x18)
        c2da_mem[new_0 + 4] = 0u8
        c2da_mem[new_0 + 5] = 0u8
        c2da_mem[new_0 + 6] = 0u8
        c2da_mem[new_0 + 7] = 0u8
    }
    let c2da_fresh53 : int = int(uint(c2da_mem[new_0 + 36]) | uint(c2da_mem[new_0 + 37]) << 0x8 | uint(c2da_mem[new_0 + 38]) << 0x10 | uint(c2da_mem[new_0 + 39]) << 0x18)
    if (c2da_fresh53 - size_1 > 256) {
        sc_rover = new_0 + size_1
        let c2da_fresh38 : int = c2da_fresh53 - size_1
        let c2da_fresh39 : uint = uint(c2da_fresh38)
        c2da_mem[sc_rover + 36] = uint8(c2da_fresh39)
        c2da_mem[sc_rover + 37] = uint8(c2da_fresh39 >> 0x8)
        c2da_mem[sc_rover + 38] = uint8(c2da_fresh39 >> 0x10)
        c2da_mem[sc_rover + 39] = uint8(c2da_fresh39 >> 0x18)
        let c2da_fresh40 : int = int(uint(c2da_mem[new_0]) | uint(c2da_mem[new_0 + 1]) << 0x8 | uint(c2da_mem[new_0 + 2]) << 0x10 | uint(c2da_mem[new_0 + 3]) << 0x18)
        let c2da_fresh41 : uint = uint(c2da_fresh40)
        c2da_mem[sc_rover] = uint8(c2da_fresh41)
        c2da_mem[sc_rover + 1] = uint8(c2da_fresh41 >> 0x8)
        c2da_mem[sc_rover + 2] = uint8(c2da_fresh41 >> 0x10)
        c2da_mem[sc_rover + 3] = uint8(c2da_fresh41 >> 0x18)
        c2da_mem[sc_rover + 4] = 0u8
        c2da_mem[sc_rover + 5] = 0u8
        c2da_mem[sc_rover + 6] = 0u8
        c2da_mem[sc_rover + 7] = 0u8
        let c2da_fresh42 : uint = 0u
        let c2da_fresh43 : uint = c2da_fresh42
        c2da_mem[sc_rover + 40] = uint8(c2da_fresh43)
        c2da_mem[sc_rover + 41] = uint8(c2da_fresh43 >> 0x8)
        c2da_mem[sc_rover + 42] = uint8(c2da_fresh43 >> 0x10)
        c2da_mem[sc_rover + 43] = uint8(c2da_fresh43 >> 0x18)
        let c2da_fresh44 : uint = 0u
        c2da_mem[sc_rover + 8] = uint8(c2da_fresh44)
        c2da_mem[sc_rover + 9] = uint8(c2da_fresh44 >> 0x8)
        c2da_mem[sc_rover + 10] = uint8(c2da_fresh44 >> 0x10)
        c2da_mem[sc_rover + 11] = uint8(c2da_fresh44 >> 0x18)
        c2da_mem[sc_rover + 12] = 0u8
        c2da_mem[sc_rover + 13] = 0u8
        c2da_mem[sc_rover + 14] = 0u8
        c2da_mem[sc_rover + 15] = 0u8
        let c2da_fresh45 : uint = uint(sc_rover)
        c2da_mem[new_0] = uint8(c2da_fresh45)
        c2da_mem[new_0 + 1] = uint8(c2da_fresh45 >> 0x8)
        c2da_mem[new_0 + 2] = uint8(c2da_fresh45 >> 0x10)
        c2da_mem[new_0 + 3] = uint8(c2da_fresh45 >> 0x18)
        c2da_mem[new_0 + 4] = 0u8
        c2da_mem[new_0 + 5] = 0u8
        c2da_mem[new_0 + 6] = 0u8
        c2da_mem[new_0 + 7] = 0u8
        let c2da_fresh46 : uint = uint(size_1)
        c2da_mem[new_0 + 36] = uint8(c2da_fresh46)
        c2da_mem[new_0 + 37] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[new_0 + 38] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[new_0 + 39] = uint8(c2da_fresh46 >> 0x18)
    } else {
        sc_rover = int(uint(c2da_mem[new_0]) | uint(c2da_mem[new_0 + 1]) << 0x8 | uint(c2da_mem[new_0 + 2]) << 0x10 | uint(c2da_mem[new_0 + 3]) << 0x18)
    }
    let c2da_fresh47 : uint = uint(width_0)
    let c2da_fresh48 : uint = c2da_fresh47
    c2da_mem[new_0 + 40] = uint8(c2da_fresh48)
    c2da_mem[new_0 + 41] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[new_0 + 42] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[new_0 + 43] = uint8(c2da_fresh48 >> 0x18)
    if (width_0 > 0) {
        let c2da_fresh49 : uint = uint((uint64(size_1) - 72ul + 4ul) / uint64(width_0))
        let c2da_fresh50 : uint = c2da_fresh49
        c2da_mem[new_0 + 44] = uint8(c2da_fresh50)
        c2da_mem[new_0 + 45] = uint8(c2da_fresh50 >> 0x8)
        c2da_mem[new_0 + 46] = uint8(c2da_fresh50 >> 0x10)
        c2da_mem[new_0 + 47] = uint8(c2da_fresh50 >> 0x18)
    }
    let c2da_fresh51 : uint = 0u
    c2da_mem[new_0 + 8] = uint8(c2da_fresh51)
    c2da_mem[new_0 + 9] = uint8(c2da_fresh51 >> 0x8)
    c2da_mem[new_0 + 10] = uint8(c2da_fresh51 >> 0x10)
    c2da_mem[new_0 + 11] = uint8(c2da_fresh51 >> 0x18)
    c2da_mem[new_0 + 12] = 0u8
    c2da_mem[new_0 + 13] = 0u8
    c2da_mem[new_0 + 14] = 0u8
    c2da_mem[new_0 + 15] = 0u8
    if (uint(d_roverwrapped) != 0u) {
        if (wrapped_this_time != 0x0 || sc_rover >= d_initial_rover) {
            r_cache_thrash = 1u
        }
    } elif (wrapped_this_time != 0u) {
        d_roverwrapped = 1u
    }
    D_CheckCacheGuard()
    return new_0
}
[export, sideeffects]
def D_CheckCacheGuard() {
    var s_0 : int = sc_base + sc_size
    for (i_0 in range(0, 4)) {
        if (int(c2da_mem[s_0 + i_0]) != int(uint8(i_0))) {
            Sys_Error(715371, [])
        }
    }
    return
}
[export, sideeffects]
def D_SCDump() {
    var test : int = sc_base
    while (test != 0) {
        if (test == sc_rover) {
            Sys_Printf(715397, [])
        }
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 715405, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(test)), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[test + 36]) | uint(c2da_mem[test + 37]) << 0x8 | uint(c2da_mem[test + 38]) << 0x10 | uint(c2da_mem[test + 39]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[test + 40]) | uint(c2da_mem[test + 41]) << 0x8 | uint(c2da_mem[test + 42]) << 0x10 | uint(c2da_mem[test + 43]) << 0x18), f64 = 0.0lf, raw = 0x0)])
        test = int(uint(c2da_mem[test]) | uint(c2da_mem[test + 1]) << 0x8 | uint(c2da_mem[test + 2]) << 0x10 | uint(c2da_mem[test + 3]) << 0x18)
    }
    return
}
[export, sideeffects]
def MaskForNum(var num : int) : int {
    if (num == 128) {
        return 127
    }
    if (num == 64) {
        return 63
    }
    if (num == 32) {
        return 31
    }
    if (num == 16) {
        return 15
    }
    return 255
}
[export, sideeffects]
def D_log2(var num_0 : int) : int {
    var c_0 : int = 0
    while (true) {
        num_0 >>= 1
        if (num_0 == 0) {
            break
        }
        c_0++
    }
    return c_0
}

// This unit's static data, at heap offset 715216.
let private c2da_lin_static_d_surf_seg = fixed_array<int>(715216, 216)
let private c2da_lin_static_d_surf = fixed_array<uint64>(0x636163667275732dul, 0x2500657a69736568ul, 0x6166727573206b69ul, 0x6568636163206563ul, 0x6c4143535f44000aul, 0x646162203a636f6cul, 0x7720656863616320ul, 0xa64252068746469ul, 0x6c6c4143535f4400ul, 0x20646162203a636ful, 0x6973206568636163ul, 0x44000a642520657aul, 0x636f6c6c4143535ful, 0x63203e206925203aul, 0x7a69732065686361ul, 0x6c4143535f440065ul, 0x746968203a636f6cul, 0x646e652065687420ul, 0x6f6d656d20666f20ul, 0x6568435f44007972ul, 0x4765686361436b63ul, 0x6166203a64726175ul, 0x564f520064656c69ul, 0x207025000a3a5245ul, 0x747962206925203aul, 0x2520202020207365ul, 0xa68746469772069ul)

[init]
def private c2da_lin_init_static_d_surf() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_d_surf_seg[s * 2]
        for (k in range(c2da_lin_static_d_surf_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_d_surf[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
