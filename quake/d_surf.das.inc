var private c2da_str_d_surf_0 : array<int8> = [int8(45), int8(115), int8(117), int8(114), int8(102), int8(99), int8(97), int8(99), int8(104), int8(101), int8(115), int8(105), int8(122), int8(101), int8(0)]

var private c2da_str_d_surf_1 : array<int8> = [int8(37), int8(105), int8(107), int8(32), int8(115), int8(117), int8(114), int8(102), int8(97), int8(99), int8(101), int8(32), int8(99), int8(97), int8(99), int8(104), int8(101), int8(10), int8(0)]

var private c2da_str_d_surf_2 : array<int8> = [int8(68), int8(95), int8(83), int8(67), int8(65), int8(108), int8(108), int8(111), int8(99), int8(58), int8(32), int8(98), int8(97), int8(100), int8(32), int8(99), int8(97), int8(99), int8(104), int8(101), int8(32), int8(119), int8(105), int8(100), int8(116), int8(104), int8(32), int8(37), int8(100), int8(10), int8(0)]

var private c2da_str_d_surf_3 : array<int8> = [int8(68), int8(95), int8(83), int8(67), int8(65), int8(108), int8(108), int8(111), int8(99), int8(58), int8(32), int8(98), int8(97), int8(100), int8(32), int8(99), int8(97), int8(99), int8(104), int8(101), int8(32), int8(115), int8(105), int8(122), int8(101), int8(32), int8(37), int8(100), int8(10), int8(0)]

var private c2da_str_d_surf_4 : array<int8> = [int8(68), int8(95), int8(83), int8(67), int8(65), int8(108), int8(108), int8(111), int8(99), int8(58), int8(32), int8(37), int8(105), int8(32), int8(62), int8(32), int8(99), int8(97), int8(99), int8(104), int8(101), int8(32), int8(115), int8(105), int8(122), int8(101), int8(0)]

var private c2da_str_d_surf_5 : array<int8> = [int8(68), int8(95), int8(83), int8(67), int8(65), int8(108), int8(108), int8(111), int8(99), int8(58), int8(32), int8(104), int8(105), int8(116), int8(32), int8(116), int8(104), int8(101), int8(32), int8(101), int8(110), int8(100), int8(32), int8(111), int8(102), int8(32), int8(109), int8(101), int8(109), int8(111), int8(114), int8(121), int8(0)]

var private c2da_str_d_surf_6 : array<int8> = [int8(68), int8(95), int8(67), int8(104), int8(101), int8(99), int8(107), int8(67), int8(97), int8(99), int8(104), int8(101), int8(71), int8(117), int8(97), int8(114), int8(100), int8(58), int8(32), int8(102), int8(97), int8(105), int8(108), int8(101), int8(100), int8(0)]

var private c2da_str_d_surf_7 : array<int8> = [int8(82), int8(79), int8(86), int8(69), int8(82), int8(58), int8(10), int8(0)]

var private c2da_str_d_surf_8 : array<int8> = [int8(37), int8(112), int8(32), int8(58), int8(32), int8(37), int8(105), int8(32), int8(98), int8(121), int8(116), int8(101), int8(115), int8(32), int8(32), int8(32), int8(32), int8(32), int8(37), int8(105), int8(32), int8(119), int8(105), int8(100), int8(116), int8(104), int8(10), int8(0)]

var r_cache_thrash : qboolean = default<qboolean>

[export, sideeffects]
def D_SurfaceCacheForRes(var width : int; var height : int) : int {
    var size : int
    var pix : int
    if (COM_CheckParm(unsafe(addr<int8?>(c2da_str_d_surf_0[0]))) != 0) {
        size = Q_atoi(unsafe(reinterpret<int8?>(unsafe(com_argv[int(COM_CheckParm(unsafe(addr<int8?>(c2da_str_d_surf_0[0]))) + 1)])))) * 1024
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
    var c : surfcache_s?
    if (sc_base == null) {
        return
    }
    c = unsafe(reinterpret<surfcache_s?>(sc_base))
    while (c != null) {
        if (c.owner != null) {
            *c.owner = null
        }
        c = unsafe(reinterpret<surfcache_s?>(c.next))
    }
    sc_rover = unsafe(reinterpret<surfcache_s?>(sc_base))
    sc_base.next = null
    sc_base.owner = null
    sc_base.size = int(sc_size)  // nolint:PERF020
    return
}
var sc_size : int = default<int>

var sc_base : surfcache_s? = default<surfcache_s?>

var sc_rover : surfcache_s? = default<surfcache_s?>

[export, sideeffects]
def D_InitCaches(var buffer : uint8?; var size_0 : int) {
    if (uint(msg_suppress_1) == 0u) {
        Con_Printf(unsafe(addr<int8?>(c2da_str_d_surf_1[0])), [C2daVaArg(tag = 1, i64 = int64(size_0 / 1024), f64 = 0.0lf, raw = 0x0)])
    }
    sc_size = size_0 - 4
    sc_base = unsafe(reinterpret<surfcache_s?>(unsafe(reinterpret<surfcache_s?>(buffer))))
    sc_rover = unsafe(reinterpret<surfcache_s?>(sc_base))
    sc_base.next = null
    sc_base.owner = null
    sc_base.size = int(sc_size)  // nolint:PERF020
    D_ClearCacheGuard()
    return
}
[export, sideeffects]
def D_ClearCacheGuard() {
    var s : uint8? = unsafe(reinterpret<uint8?>(unsafe(unsafe(reinterpret<uint8?>(sc_base)) + sc_size)))
    for (i in range(0, 4)) {
        unsafe(s[i]) = uint8(i)
    }
    return
}
[export, sideeffects]
def D_CacheSurface(var surface : msurface_s?; var miplevel_0 : int) : surfcache_s? {
    var cache : surfcache_s?
    r_drawsurf.texture = unsafe(reinterpret<texture_s?>(unsafe(reinterpret<texture_s?>(R_TextureAnimation(surface.texinfo.texture)))))
    var c2da_fresh0 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(surface)) + 88ul))
    unsafe(unsafe(addr(r_drawsurf.lightadj[0]))[0]) = d_lightstylevalue[int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh0))[0]))]
    var c2da_fresh1 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(surface)) + 88ul))
    unsafe(unsafe(addr(r_drawsurf.lightadj[0]))[1]) = d_lightstylevalue[int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh1))[1]))]
    var c2da_fresh2 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(surface)) + 88ul))
    unsafe(unsafe(addr(r_drawsurf.lightadj[0]))[2]) = d_lightstylevalue[int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh2))[2]))]
    var c2da_fresh3 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(surface)) + 88ul))
    unsafe(unsafe(addr(r_drawsurf.lightadj[0]))[3]) = d_lightstylevalue[int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh3))[3]))]
    var c2da_fresh4 : surfcache_s?? = unsafe(reinterpret<surfcache_s??>(unsafe(reinterpret<uint64>(surface)) + 40ul))
    cache = unsafe(reinterpret<surfcache_s?>(unsafe(unsafe(reinterpret<surfcache_s??>(c2da_fresh4))[miplevel_0])))
    var c2da_fresh6 : int = 0
    if (cache != null && cache.dlight == 0 && surface.dlightframe != r_framecount && cache.texture == r_drawsurf.texture) {
        var c2da_fresh5 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(cache)) + 16ul))
        if (unsafe(unsafe(reinterpret<int?>(c2da_fresh5))[0]) == unsafe(unsafe(addr(r_drawsurf.lightadj[0]))[0])) {
            c2da_fresh6 = 1
        }
    }
    var c2da_fresh8 : int = 0
    if (c2da_fresh6 != 0) {
        var c2da_fresh7 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(cache)) + 16ul))
        if (unsafe(unsafe(reinterpret<int?>(c2da_fresh7))[1]) == unsafe(unsafe(addr(r_drawsurf.lightadj[0]))[1])) {
            c2da_fresh8 = 1
        }
    }
    var c2da_fresh10 : int = 0
    if (c2da_fresh8 != 0) {
        var c2da_fresh9 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(cache)) + 16ul))
        if (unsafe(unsafe(reinterpret<int?>(c2da_fresh9))[2]) == unsafe(unsafe(addr(r_drawsurf.lightadj[0]))[2])) {
            c2da_fresh10 = 1
        }
    }
    var c2da_fresh12 : int = 0
    if (c2da_fresh10 != 0) {
        var c2da_fresh11 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(cache)) + 16ul))
        if (unsafe(unsafe(reinterpret<int?>(c2da_fresh11))[3]) == unsafe(unsafe(addr(r_drawsurf.lightadj[0]))[3])) {
            c2da_fresh12 = 1
        }
    }
    if (c2da_fresh12 != 0) {
        return unsafe(reinterpret<surfcache_s?>(cache))
    }
    surfscale = float(1.0lf / double(1 << miplevel_0))
    r_drawsurf.surfmip = miplevel_0
    var c2da_fresh13 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(surface)) + 76ul))
    r_drawsurf.surfwidth = int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh13))[0])) >> miplevel_0
    r_drawsurf.rowbytes = r_drawsurf.surfwidth
    var c2da_fresh14 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(surface)) + 76ul))
    r_drawsurf.surfheight = int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh14))[1])) >> miplevel_0
    if (cache == null) {
        cache = unsafe(reinterpret<surfcache_s?>(unsafe(reinterpret<surfcache_s?>(D_SCAlloc(r_drawsurf.surfwidth, r_drawsurf.surfwidth * r_drawsurf.surfheight)))))
        var c2da_fresh15 : surfcache_s?? = unsafe(reinterpret<surfcache_s??>(unsafe(reinterpret<uint64>(surface)) + 40ul))
        unsafe(unsafe(reinterpret<surfcache_s??>(c2da_fresh15))[miplevel_0]) = unsafe(reinterpret<surfcache_s?>(cache))
        var c2da_fresh16 : surfcache_s?? = unsafe(reinterpret<surfcache_s??>(unsafe(reinterpret<uint64>(surface)) + 40ul))
        cache.owner = unsafe(addr(unsafe(unsafe(reinterpret<surfcache_s??>(c2da_fresh16))[miplevel_0])))
        cache.mipscale = float(surfscale)  // nolint:PERF020
    }
    if (surface.dlightframe == r_framecount) {
        cache.dlight = 1
    } else {
        cache.dlight = 0
    }
    var c2da_fresh17 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(cache)) + 64ul))
    r_drawsurf.surfdat = unsafe(reinterpret<uint8?>(c2da_fresh17))
    cache.texture = r_drawsurf.texture
    var c2da_fresh18 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(cache)) + 16ul))
    unsafe(unsafe(reinterpret<int?>(c2da_fresh18))[0]) = unsafe(unsafe(addr(r_drawsurf.lightadj[0]))[0])
    var c2da_fresh19 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(cache)) + 16ul))
    unsafe(unsafe(reinterpret<int?>(c2da_fresh19))[1]) = unsafe(unsafe(addr(r_drawsurf.lightadj[0]))[1])
    var c2da_fresh20 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(cache)) + 16ul))
    unsafe(unsafe(reinterpret<int?>(c2da_fresh20))[2]) = unsafe(unsafe(addr(r_drawsurf.lightadj[0]))[2])
    var c2da_fresh21 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(cache)) + 16ul))
    unsafe(unsafe(reinterpret<int?>(c2da_fresh21))[3]) = unsafe(unsafe(addr(r_drawsurf.lightadj[0]))[3])
    r_drawsurf.surf = unsafe(reinterpret<msurface_s?>(surface))
    c_surf = c_surf + 1
    R_DrawSurface()
    var c2da_fresh22 : surfcache_s?? = unsafe(reinterpret<surfcache_s??>(unsafe(reinterpret<uint64>(surface)) + 40ul))
    return unsafe(reinterpret<surfcache_s?>(unsafe(unsafe(reinterpret<surfcache_s??>(c2da_fresh22))[miplevel_0])))
}
var surfscale : float = default<float>

[export, sideeffects]
def D_SCAlloc(var width_0 : int; var size_1 : int) : surfcache_s? {
    var new_0 : surfcache_s?
    var wrapped_this_time : qboolean = qboolean()
    if (width_0 < 0 || width_0 > 256) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_d_surf_2[0])), [C2daVaArg(tag = 1, i64 = int64(width_0), f64 = 0.0lf, raw = 0x0)])
    }
    if (size_1 <= 0 || size_1 > 65536) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_d_surf_3[0])), [C2daVaArg(tag = 1, i64 = int64(size_1), f64 = 0.0lf, raw = 0x0)])
    }
    var c2da_fresh23 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(null)) + 64ul))
    size_1 = int(unsafe(reinterpret<uint64>(unsafe(addr(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh23))[size_1]))))))
    size_1 = size_1 + 3 & ~3
    if (size_1 > sc_size) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_d_surf_4[0])), [C2daVaArg(tag = 1, i64 = int64(size_1), f64 = 0.0lf, raw = 0x0)])
    }
    wrapped_this_time = unsafe(reinterpret<qboolean>(0u))
    if (sc_rover == null || unsafe(unsafe(reinterpret<uint8?>(sc_rover)) - unsafe(reinterpret<uint8?>(sc_base))) > int64(sc_size - size_1)) {
        if (sc_rover != null) {
            wrapped_this_time = unsafe(reinterpret<qboolean>(1u))
        }
        sc_rover = unsafe(reinterpret<surfcache_s?>(sc_base))
    }
    new_0 = unsafe(reinterpret<surfcache_s?>(sc_rover))
    if (sc_rover.owner != null) {
        *sc_rover.owner = null
    }
    while (new_0.size < size_1) {
        sc_rover = unsafe(reinterpret<surfcache_s?>(sc_rover.next))
        if (sc_rover == null) {
            Sys_Error(unsafe(addr<int8?>(c2da_str_d_surf_5[0])), [])
        }
        if (sc_rover.owner != null) {
            *sc_rover.owner = null
        }
        new_0.size += sc_rover.size
        new_0.next = sc_rover.next
    }
    if (new_0.size - size_1 > 256) {
        sc_rover = unsafe(reinterpret<surfcache_s?>(unsafe(reinterpret<surfcache_s?>(unsafe(unsafe(reinterpret<uint8?>(new_0)) + size_1)))))
        sc_rover.size = new_0.size - size_1
        sc_rover.next = new_0.next
        sc_rover.width = 0u
        sc_rover.owner = null
        new_0.next = sc_rover
        new_0.size = int(size_1)  // nolint:PERF020
    } else {
        sc_rover = unsafe(reinterpret<surfcache_s?>(new_0.next))
    }
    new_0.width = uint(width_0)
    if (width_0 > 0) {
        new_0.height = uint((uint64(size_1) - 72ul + 4ul) / uint64(width_0))
    }
    new_0.owner = null
    if (uint(d_roverwrapped) != 0u) {
        if (uint(wrapped_this_time) != 0x0 || unsafe(reinterpret<uint64>(sc_rover)) >= unsafe(reinterpret<uint64>(d_initial_rover))) {
            r_cache_thrash = unsafe(reinterpret<qboolean>(1u))
        }
    } elif (uint(wrapped_this_time) != 0u) {
        d_roverwrapped = unsafe(reinterpret<qboolean>(1u))
    }
    D_CheckCacheGuard()
    return unsafe(reinterpret<surfcache_s?>(new_0))
}
[export, sideeffects]
def D_CheckCacheGuard() {
    var s_0 : uint8? = unsafe(reinterpret<uint8?>(unsafe(unsafe(reinterpret<uint8?>(sc_base)) + sc_size)))
    for (i_0 in range(0, 4)) {
        if (int(unsafe(s_0[i_0])) != int(uint8(i_0))) {
            Sys_Error(unsafe(addr<int8?>(c2da_str_d_surf_6[0])), [])
        }
    }
    return
}
[export, sideeffects]
def D_SCDump() {
    var test : surfcache_s? = unsafe(reinterpret<surfcache_s?>(sc_base))
    while (test != null) {
        if (test == sc_rover) {
            Sys_Printf(unsafe(addr<int8?>(c2da_str_d_surf_7[0])), [])
        }
        c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_d_surf_8[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(test))), C2daVaArg(tag = 1, i64 = int64(test.size), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(test.width), f64 = 0.0lf, raw = 0x0)])
        test = unsafe(reinterpret<surfcache_s?>(test.next))
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
[sideeffects]
def private c2da_layout_proofs_17() {
    static_assert(typeinfo sizeof(type<_IO_FILE>) == 216, "C layout of _IO_FILE: sizeof")
    static_assert(typeinfo alignof(type<_IO_FILE>) == 8, "C layout of _IO_FILE: alignof")
    static_assert(typeinfo offsetof<_flags>(type<_IO_FILE>) == 0, "C layout of _IO_FILE: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<_IO_FILE>) == 8, "C layout of _IO_FILE: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<_IO_FILE>) == 16, "C layout of _IO_FILE: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<_IO_FILE>) == 24, "C layout of _IO_FILE: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<_IO_FILE>) == 32, "C layout of _IO_FILE: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<_IO_FILE>) == 40, "C layout of _IO_FILE: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<_IO_FILE>) == 48, "C layout of _IO_FILE: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<_IO_FILE>) == 56, "C layout of _IO_FILE: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<_IO_FILE>) == 64, "C layout of _IO_FILE: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<_IO_FILE>) == 72, "C layout of _IO_FILE: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<_IO_FILE>) == 80, "C layout of _IO_FILE: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<_IO_FILE>) == 88, "C layout of _IO_FILE: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<_IO_FILE>) == 96, "C layout of _IO_FILE: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<_IO_FILE>) == 104, "C layout of _IO_FILE: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<_IO_FILE>) == 112, "C layout of _IO_FILE: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<_IO_FILE>) == 116, "C layout of _IO_FILE: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<_IO_FILE>) == 120, "C layout of _IO_FILE: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<_IO_FILE>) == 128, "C layout of _IO_FILE: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<_IO_FILE>) == 130, "C layout of _IO_FILE: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<_IO_FILE>) == 131, "C layout of _IO_FILE: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<_IO_FILE>) == 136, "C layout of _IO_FILE: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<_IO_FILE>) == 144, "C layout of _IO_FILE: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<_IO_FILE>) == 152, "C layout of _IO_FILE: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<_IO_FILE>) == 160, "C layout of _IO_FILE: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<_IO_FILE>) == 168, "C layout of _IO_FILE: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<_IO_FILE>) == 176, "C layout of _IO_FILE: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<_IO_FILE>) == 184, "C layout of _IO_FILE: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<_IO_FILE>) == 192, "C layout of _IO_FILE: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<_IO_FILE>) == 196, "C layout of _IO_FILE: offsetof _unused2")
    static_assert(typeinfo sizeof(type<FILE_0>) == 216, "C layout of FILE_0: sizeof")
    static_assert(typeinfo alignof(type<FILE_0>) == 8, "C layout of FILE_0: alignof")
    static_assert(typeinfo offsetof<_flags>(type<FILE_0>) == 0, "C layout of FILE_0: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<FILE_0>) == 8, "C layout of FILE_0: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<FILE_0>) == 16, "C layout of FILE_0: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<FILE_0>) == 24, "C layout of FILE_0: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<FILE_0>) == 32, "C layout of FILE_0: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<FILE_0>) == 40, "C layout of FILE_0: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<FILE_0>) == 48, "C layout of FILE_0: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<FILE_0>) == 56, "C layout of FILE_0: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<FILE_0>) == 64, "C layout of FILE_0: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<FILE_0>) == 72, "C layout of FILE_0: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<FILE_0>) == 80, "C layout of FILE_0: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<FILE_0>) == 88, "C layout of FILE_0: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<FILE_0>) == 96, "C layout of FILE_0: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<FILE_0>) == 104, "C layout of FILE_0: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<FILE_0>) == 112, "C layout of FILE_0: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<FILE_0>) == 116, "C layout of FILE_0: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<FILE_0>) == 120, "C layout of FILE_0: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<FILE_0>) == 128, "C layout of FILE_0: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<FILE_0>) == 130, "C layout of FILE_0: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<FILE_0>) == 131, "C layout of FILE_0: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<FILE_0>) == 136, "C layout of FILE_0: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<FILE_0>) == 144, "C layout of FILE_0: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<FILE_0>) == 152, "C layout of FILE_0: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<FILE_0>) == 160, "C layout of FILE_0: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<FILE_0>) == 168, "C layout of FILE_0: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<FILE_0>) == 176, "C layout of FILE_0: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<FILE_0>) == 184, "C layout of FILE_0: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<FILE_0>) == 192, "C layout of FILE_0: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<FILE_0>) == 196, "C layout of FILE_0: offsetof _unused2")
    static_assert(typeinfo sizeof(type<mplane_s>) == 20, "C layout of mplane_s: sizeof")
    static_assert(typeinfo alignof(type<mplane_s>) == 4, "C layout of mplane_s: alignof")
    static_assert(typeinfo offsetof<normal>(type<mplane_s>) == 0, "C layout of mplane_s: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<mplane_s>) == 12, "C layout of mplane_s: offsetof dist")
    static_assert(typeinfo offsetof<type_0>(type<mplane_s>) == 16, "C layout of mplane_s: offsetof type_0")
    static_assert(typeinfo offsetof<signbits>(type<mplane_s>) == 17, "C layout of mplane_s: offsetof signbits")
    static_assert(typeinfo offsetof<pad>(type<mplane_s>) == 18, "C layout of mplane_s: offsetof pad")
    static_assert(typeinfo sizeof(type<mplane_t>) == 20, "C layout of mplane_t: sizeof")
    static_assert(typeinfo alignof(type<mplane_t>) == 4, "C layout of mplane_t: alignof")
    static_assert(typeinfo offsetof<normal>(type<mplane_t>) == 0, "C layout of mplane_t: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<mplane_t>) == 12, "C layout of mplane_t: offsetof dist")
    static_assert(typeinfo offsetof<type_0>(type<mplane_t>) == 16, "C layout of mplane_t: offsetof type_0")
    static_assert(typeinfo offsetof<signbits>(type<mplane_t>) == 17, "C layout of mplane_t: offsetof signbits")
    static_assert(typeinfo offsetof<pad>(type<mplane_t>) == 18, "C layout of mplane_t: offsetof pad")
    static_assert(typeinfo sizeof(type<texture_t>) == 72, "C layout of texture_t: sizeof")
    static_assert(typeinfo alignof(type<texture_t>) == 8, "C layout of texture_t: alignof")
    static_assert(typeinfo offsetof<name>(type<texture_t>) == 0, "C layout of texture_t: offsetof name")
    static_assert(typeinfo offsetof<width>(type<texture_t>) == 16, "C layout of texture_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<texture_t>) == 20, "C layout of texture_t: offsetof height")
    static_assert(typeinfo offsetof<anim_total>(type<texture_t>) == 24, "C layout of texture_t: offsetof anim_total")
    static_assert(typeinfo offsetof<anim_min>(type<texture_t>) == 28, "C layout of texture_t: offsetof anim_min")
    static_assert(typeinfo offsetof<anim_max>(type<texture_t>) == 32, "C layout of texture_t: offsetof anim_max")
    static_assert(typeinfo offsetof<anim_next>(type<texture_t>) == 40, "C layout of texture_t: offsetof anim_next")
    static_assert(typeinfo offsetof<alternate_anims>(type<texture_t>) == 48, "C layout of texture_t: offsetof alternate_anims")
    static_assert(typeinfo offsetof<offsets>(type<texture_t>) == 56, "C layout of texture_t: offsetof offsets")
    static_assert(typeinfo sizeof(type<texture_s>) == 72, "C layout of texture_s: sizeof")
    static_assert(typeinfo alignof(type<texture_s>) == 8, "C layout of texture_s: alignof")
    static_assert(typeinfo offsetof<name>(type<texture_s>) == 0, "C layout of texture_s: offsetof name")
    static_assert(typeinfo offsetof<width>(type<texture_s>) == 16, "C layout of texture_s: offsetof width")
    static_assert(typeinfo offsetof<height>(type<texture_s>) == 20, "C layout of texture_s: offsetof height")
    static_assert(typeinfo offsetof<anim_total>(type<texture_s>) == 24, "C layout of texture_s: offsetof anim_total")
    static_assert(typeinfo offsetof<anim_min>(type<texture_s>) == 28, "C layout of texture_s: offsetof anim_min")
    static_assert(typeinfo offsetof<anim_max>(type<texture_s>) == 32, "C layout of texture_s: offsetof anim_max")
    static_assert(typeinfo offsetof<anim_next>(type<texture_s>) == 40, "C layout of texture_s: offsetof anim_next")
    static_assert(typeinfo offsetof<alternate_anims>(type<texture_s>) == 48, "C layout of texture_s: offsetof alternate_anims")
    static_assert(typeinfo offsetof<offsets>(type<texture_s>) == 56, "C layout of texture_s: offsetof offsets")
    static_assert(typeinfo sizeof(type<msurface_t>) == 104, "C layout of msurface_t: sizeof")
    static_assert(typeinfo alignof(type<msurface_t>) == 8, "C layout of msurface_t: alignof")
    static_assert(typeinfo offsetof<visframe>(type<msurface_t>) == 0, "C layout of msurface_t: offsetof visframe")
    static_assert(typeinfo offsetof<dlightframe>(type<msurface_t>) == 4, "C layout of msurface_t: offsetof dlightframe")
    static_assert(typeinfo offsetof<dlightbits>(type<msurface_t>) == 8, "C layout of msurface_t: offsetof dlightbits")
    static_assert(typeinfo offsetof<plane>(type<msurface_t>) == 16, "C layout of msurface_t: offsetof plane")
    static_assert(typeinfo offsetof<flags>(type<msurface_t>) == 24, "C layout of msurface_t: offsetof flags")
    static_assert(typeinfo offsetof<firstedge>(type<msurface_t>) == 28, "C layout of msurface_t: offsetof firstedge")
    static_assert(typeinfo offsetof<numedges>(type<msurface_t>) == 32, "C layout of msurface_t: offsetof numedges")
    static_assert(typeinfo offsetof<cachespots>(type<msurface_t>) == 40, "C layout of msurface_t: offsetof cachespots")
    static_assert(typeinfo offsetof<texturemins>(type<msurface_t>) == 72, "C layout of msurface_t: offsetof texturemins")
    static_assert(typeinfo offsetof<extents>(type<msurface_t>) == 76, "C layout of msurface_t: offsetof extents")
    static_assert(typeinfo offsetof<texinfo>(type<msurface_t>) == 80, "C layout of msurface_t: offsetof texinfo")
    static_assert(typeinfo offsetof<styles>(type<msurface_t>) == 88, "C layout of msurface_t: offsetof styles")
    static_assert(typeinfo offsetof<samples>(type<msurface_t>) == 96, "C layout of msurface_t: offsetof samples")
    static_assert(typeinfo sizeof(type<msurface_s>) == 104, "C layout of msurface_s: sizeof")
    static_assert(typeinfo alignof(type<msurface_s>) == 8, "C layout of msurface_s: alignof")
    static_assert(typeinfo offsetof<visframe>(type<msurface_s>) == 0, "C layout of msurface_s: offsetof visframe")
    static_assert(typeinfo offsetof<dlightframe>(type<msurface_s>) == 4, "C layout of msurface_s: offsetof dlightframe")
    static_assert(typeinfo offsetof<dlightbits>(type<msurface_s>) == 8, "C layout of msurface_s: offsetof dlightbits")
    static_assert(typeinfo offsetof<plane>(type<msurface_s>) == 16, "C layout of msurface_s: offsetof plane")
    static_assert(typeinfo offsetof<flags>(type<msurface_s>) == 24, "C layout of msurface_s: offsetof flags")
    static_assert(typeinfo offsetof<firstedge>(type<msurface_s>) == 28, "C layout of msurface_s: offsetof firstedge")
    static_assert(typeinfo offsetof<numedges>(type<msurface_s>) == 32, "C layout of msurface_s: offsetof numedges")
    static_assert(typeinfo offsetof<cachespots>(type<msurface_s>) == 40, "C layout of msurface_s: offsetof cachespots")
    static_assert(typeinfo offsetof<texturemins>(type<msurface_s>) == 72, "C layout of msurface_s: offsetof texturemins")
    static_assert(typeinfo offsetof<extents>(type<msurface_s>) == 76, "C layout of msurface_s: offsetof extents")
    static_assert(typeinfo offsetof<texinfo>(type<msurface_s>) == 80, "C layout of msurface_s: offsetof texinfo")
    static_assert(typeinfo offsetof<styles>(type<msurface_s>) == 88, "C layout of msurface_s: offsetof styles")
    static_assert(typeinfo offsetof<samples>(type<msurface_s>) == 96, "C layout of msurface_s: offsetof samples")
    static_assert(typeinfo sizeof(type<mtexinfo_t>) == 56, "C layout of mtexinfo_t: sizeof")
    static_assert(typeinfo alignof(type<mtexinfo_t>) == 8, "C layout of mtexinfo_t: alignof")
    static_assert(typeinfo offsetof<vecs>(type<mtexinfo_t>) == 0, "C layout of mtexinfo_t: offsetof vecs")
    static_assert(typeinfo offsetof<mipadjust>(type<mtexinfo_t>) == 32, "C layout of mtexinfo_t: offsetof mipadjust")
    static_assert(typeinfo offsetof<texture>(type<mtexinfo_t>) == 40, "C layout of mtexinfo_t: offsetof texture")
    static_assert(typeinfo offsetof<flags>(type<mtexinfo_t>) == 48, "C layout of mtexinfo_t: offsetof flags")
    static_assert(typeinfo sizeof(type<surfcache_s>) == 72, "C layout of surfcache_s: sizeof")
    static_assert(typeinfo alignof(type<surfcache_s>) == 8, "C layout of surfcache_s: alignof")
    static_assert(typeinfo offsetof<next>(type<surfcache_s>) == 0, "C layout of surfcache_s: offsetof next")
    static_assert(typeinfo offsetof<owner>(type<surfcache_s>) == 8, "C layout of surfcache_s: offsetof owner")
    static_assert(typeinfo offsetof<lightadj>(type<surfcache_s>) == 16, "C layout of surfcache_s: offsetof lightadj")
    static_assert(typeinfo offsetof<dlight>(type<surfcache_s>) == 32, "C layout of surfcache_s: offsetof dlight")
    static_assert(typeinfo offsetof<size>(type<surfcache_s>) == 36, "C layout of surfcache_s: offsetof size")
    static_assert(typeinfo offsetof<width>(type<surfcache_s>) == 40, "C layout of surfcache_s: offsetof width")
    static_assert(typeinfo offsetof<height>(type<surfcache_s>) == 44, "C layout of surfcache_s: offsetof height")
    static_assert(typeinfo offsetof<mipscale>(type<surfcache_s>) == 48, "C layout of surfcache_s: offsetof mipscale")
    static_assert(typeinfo offsetof<texture>(type<surfcache_s>) == 56, "C layout of surfcache_s: offsetof texture")
    static_assert(typeinfo offsetof<data>(type<surfcache_s>) == 64, "C layout of surfcache_s: offsetof data")
    static_assert(typeinfo sizeof(type<surfcache_t>) == 72, "C layout of surfcache_t: sizeof")
    static_assert(typeinfo alignof(type<surfcache_t>) == 8, "C layout of surfcache_t: alignof")
    static_assert(typeinfo offsetof<next>(type<surfcache_t>) == 0, "C layout of surfcache_t: offsetof next")
    static_assert(typeinfo offsetof<owner>(type<surfcache_t>) == 8, "C layout of surfcache_t: offsetof owner")
    static_assert(typeinfo offsetof<lightadj>(type<surfcache_t>) == 16, "C layout of surfcache_t: offsetof lightadj")
    static_assert(typeinfo offsetof<dlight>(type<surfcache_t>) == 32, "C layout of surfcache_t: offsetof dlight")
    static_assert(typeinfo offsetof<size>(type<surfcache_t>) == 36, "C layout of surfcache_t: offsetof size")
    static_assert(typeinfo offsetof<width>(type<surfcache_t>) == 40, "C layout of surfcache_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<surfcache_t>) == 44, "C layout of surfcache_t: offsetof height")
    static_assert(typeinfo offsetof<mipscale>(type<surfcache_t>) == 48, "C layout of surfcache_t: offsetof mipscale")
    static_assert(typeinfo offsetof<texture>(type<surfcache_t>) == 56, "C layout of surfcache_t: offsetof texture")
    static_assert(typeinfo offsetof<data>(type<surfcache_t>) == 64, "C layout of surfcache_t: offsetof data")
    static_assert(typeinfo sizeof(type<drawsurf_t>) == 64, "C layout of drawsurf_t: sizeof")
    static_assert(typeinfo alignof(type<drawsurf_t>) == 8, "C layout of drawsurf_t: alignof")
    static_assert(typeinfo offsetof<surfdat>(type<drawsurf_t>) == 0, "C layout of drawsurf_t: offsetof surfdat")
    static_assert(typeinfo offsetof<rowbytes>(type<drawsurf_t>) == 8, "C layout of drawsurf_t: offsetof rowbytes")
    static_assert(typeinfo offsetof<surf>(type<drawsurf_t>) == 16, "C layout of drawsurf_t: offsetof surf")
    static_assert(typeinfo offsetof<lightadj>(type<drawsurf_t>) == 24, "C layout of drawsurf_t: offsetof lightadj")
    static_assert(typeinfo offsetof<texture>(type<drawsurf_t>) == 40, "C layout of drawsurf_t: offsetof texture")
    static_assert(typeinfo offsetof<surfmip>(type<drawsurf_t>) == 48, "C layout of drawsurf_t: offsetof surfmip")
    static_assert(typeinfo offsetof<surfwidth>(type<drawsurf_t>) == 52, "C layout of drawsurf_t: offsetof surfwidth")
    static_assert(typeinfo offsetof<surfheight>(type<drawsurf_t>) == 56, "C layout of drawsurf_t: offsetof surfheight")
}
