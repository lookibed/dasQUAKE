var private c2da_str_wad_0 : array<int8> = [int8(87), int8(95), int8(76), int8(111), int8(97), int8(100), int8(87), int8(97), int8(100), int8(70), int8(105), int8(108), int8(101), int8(58), int8(32), int8(99), int8(111), int8(117), int8(108), int8(100), int8(110), int8(39), int8(116), int8(32), int8(108), int8(111), int8(97), int8(100), int8(32), int8(37), int8(115), int8(0)]

var private c2da_str_wad_1 : array<int8> = [int8(87), int8(97), int8(100), int8(32), int8(102), int8(105), int8(108), int8(101), int8(32), int8(37), int8(115), int8(32), int8(100), int8(111), int8(101), int8(115), int8(110), int8(39), int8(116), int8(32), int8(104), int8(97), int8(118), int8(101), int8(32), int8(87), int8(65), int8(68), int8(50), int8(32), int8(105), int8(100), int8(10), int8(0)]

var private c2da_str_wad_2 : array<int8> = [int8(87), int8(95), int8(71), int8(101), int8(116), int8(76), int8(117), int8(109), int8(112), int8(105), int8(110), int8(102), int8(111), int8(58), int8(32), int8(37), int8(115), int8(32), int8(110), int8(111), int8(116), int8(32), int8(102), int8(111), int8(117), int8(110), int8(100), int8(0)]

var private c2da_str_wad_3 : array<int8> = [int8(87), int8(95), int8(71), int8(101), int8(116), int8(76), int8(117), int8(109), int8(112), int8(78), int8(117), int8(109), int8(58), int8(32), int8(98), int8(97), int8(100), int8(32), int8(110), int8(117), int8(109), int8(98), int8(101), int8(114), int8(58), int8(32), int8(37), int8(105), int8(0)]

var wad_numlumps : int = default<int>

var wad_lumps : lumpinfo_t? = default<lumpinfo_t?>

var wad_base : uint8? = default<uint8?>

[export, sideeffects]
def W_LoadWadFile(var filename : int8?) {
    var lump_p : lumpinfo_t?
    var header : wadinfo_t?
    var i : uint
    var infotableofs : int
    wad_base = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(COM_LoadHunkFile(filename)))))
    if (wad_base == null) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_wad_0[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(filename)))])
    }
    header = unsafe(reinterpret<wadinfo_t?>(unsafe(reinterpret<wadinfo_t?>(wad_base))))
    var c2da_fresh0 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(header))))
    var c2da_fresh2 : int = 1
    if (!(int(unsafe(unsafe(reinterpret<int8?>(c2da_fresh0))[0])) != 87)) {
        var c2da_fresh1 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(header))))
        if (!(int(unsafe(unsafe(reinterpret<int8?>(c2da_fresh1))[1])) != 65)) {
            c2da_fresh2 = 0
        }
    }
    var c2da_fresh4 : int = 1
    if (!(c2da_fresh2 != 0)) {
        var c2da_fresh3 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(header))))
        if (!(int(unsafe(unsafe(reinterpret<int8?>(c2da_fresh3))[2])) != 68)) {
            c2da_fresh4 = 0
        }
    }
    var c2da_fresh6 : int = 1
    if (!(c2da_fresh4 != 0)) {
        var c2da_fresh5 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(header))))
        if (!(int(unsafe(unsafe(reinterpret<int8?>(c2da_fresh5))[3])) != 50)) {
            c2da_fresh6 = 0
        }
    }
    if (c2da_fresh6 != 0) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_wad_1[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(filename)))])
    }
    wad_numlumps = invoke(LittleLong, header.numlumps)
    infotableofs = invoke(LittleLong, header.infotableofs)
    wad_lumps = unsafe(reinterpret<lumpinfo_t?>(unsafe(reinterpret<lumpinfo_t?>(unsafe(wad_base + infotableofs)))))
    i = 0u
    lump_p = unsafe(reinterpret<lumpinfo_t?>(wad_lumps))
    while (i < uint(wad_numlumps)) {
        lump_p.filepos = invoke(LittleLong, lump_p.filepos)
        lump_p.size = invoke(LittleLong, lump_p.size)
        var c2da_fresh7 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(lump_p)) + 16ul))
        var c2da_fresh8 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(lump_p)) + 16ul))
        W_CleanupName(unsafe(reinterpret<int8?>(c2da_fresh7)), unsafe(reinterpret<int8?>(c2da_fresh8)))
        if (int(lump_p.type_0) == 66) {
            SwapPic(unsafe(reinterpret<qpic_t?>(unsafe(wad_base + lump_p.filepos))))
        }
        i++
        unsafe {  // nolint:STYLE025
            lump_p += 1
        }
    }
    return
}
[export, sideeffects]
def SwapPic(var pic : qpic_t?) {
    pic.width = invoke(LittleLong, pic.width)
    pic.height = invoke(LittleLong, pic.height)
    return
}
[export, sideeffects]
def W_CleanupName(var in_0 : int8?; var out : int8?) {
    var i_0 : int
    var c : int
    i_0 = 0
    while (i_0 < 16) {
        c = int(unsafe(in_0[i_0]))
        if (c == 0) {
            break
        }
        if (c >= 65 && c <= 90) {
            c += 97 - 65
        }
        unsafe(out[i_0]) = int8(c)
        i_0++
    }
    for (c2da_i_0 in range(i_0, 16)) {
        unsafe(out[c2da_i_0]) = int8(0)
    }
    return
}
[export, sideeffects]
def W_GetLumpinfo(var name : int8?) : lumpinfo_t? {
    var i_1 : int
    var lump_p_0 : lumpinfo_t?
    var clean : int8[16]
    W_CleanupName(name, unsafe(addr<int8?>(clean[0])))
    lump_p_0 = unsafe(reinterpret<lumpinfo_t?>(wad_lumps))
    i_1 = 0
    while (i_1 < wad_numlumps) {
        var c2da_fresh9 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(lump_p_0)) + 16ul))
        if (c2da_std_strcmp(unsafe(reinterpret<uint64>(unsafe(addr(clean[0])))), unsafe(reinterpret<uint64>(c2da_fresh9))) == 0) {
            return unsafe(reinterpret<lumpinfo_t?>(lump_p_0))
        }
        i_1++
        unsafe {  // nolint:STYLE025
            lump_p_0 += 1
        }
    }
    Sys_Error(unsafe(addr<int8?>(c2da_str_wad_2[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(name)))])
    return unsafe(reinterpret<lumpinfo_t?>(null))
}
[export, sideeffects]
def W_GetLumpName(var name_0 : int8?) : uint8? {
    var lump : lumpinfo_t? = unsafe(reinterpret<lumpinfo_t?>(unsafe(reinterpret<lumpinfo_t?>(W_GetLumpinfo(name_0)))))
    return unsafe(reinterpret<uint8?>(unsafe(wad_base + lump.filepos)))
}
[export, sideeffects]
def W_GetLumpNum(var num : int) : uint8? {
    if (num < 0 || num > wad_numlumps) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_wad_3[0])), [C2daVaArg(tag = 1, i64 = int64(num), f64 = 0.0lf, raw = 0x0)])
    }
    return unsafe(reinterpret<uint8?>(unsafe(wad_base + unsafe(reinterpret<lumpinfo_t?>(unsafe(wad_lumps + num))).filepos)))
}
[sideeffects]
def private c2da_layout_proofs_53() {
    static_assert(typeinfo sizeof(type<qpic_t>) == 12, "C layout of qpic_t: sizeof")
    static_assert(typeinfo alignof(type<qpic_t>) == 4, "C layout of qpic_t: alignof")
    static_assert(typeinfo offsetof<width>(type<qpic_t>) == 0, "C layout of qpic_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<qpic_t>) == 4, "C layout of qpic_t: offsetof height")
    static_assert(typeinfo offsetof<data>(type<qpic_t>) == 8, "C layout of qpic_t: offsetof data")
    static_assert(typeinfo sizeof(type<wadinfo_t>) == 12, "C layout of wadinfo_t: sizeof")
    static_assert(typeinfo alignof(type<wadinfo_t>) == 4, "C layout of wadinfo_t: alignof")
    static_assert(typeinfo offsetof<identification>(type<wadinfo_t>) == 0, "C layout of wadinfo_t: offsetof identification")
    static_assert(typeinfo offsetof<numlumps>(type<wadinfo_t>) == 4, "C layout of wadinfo_t: offsetof numlumps")
    static_assert(typeinfo offsetof<infotableofs>(type<wadinfo_t>) == 8, "C layout of wadinfo_t: offsetof infotableofs")
    static_assert(typeinfo sizeof(type<lumpinfo_t>) == 32, "C layout of lumpinfo_t: sizeof")
    static_assert(typeinfo alignof(type<lumpinfo_t>) == 4, "C layout of lumpinfo_t: alignof")
    static_assert(typeinfo offsetof<filepos>(type<lumpinfo_t>) == 0, "C layout of lumpinfo_t: offsetof filepos")
    static_assert(typeinfo offsetof<disksize>(type<lumpinfo_t>) == 4, "C layout of lumpinfo_t: offsetof disksize")
    static_assert(typeinfo offsetof<size>(type<lumpinfo_t>) == 8, "C layout of lumpinfo_t: offsetof size")
    static_assert(typeinfo offsetof<type_0>(type<lumpinfo_t>) == 12, "C layout of lumpinfo_t: offsetof type_0")
    static_assert(typeinfo offsetof<compression>(type<lumpinfo_t>) == 13, "C layout of lumpinfo_t: offsetof compression")
    static_assert(typeinfo offsetof<pad1>(type<lumpinfo_t>) == 14, "C layout of lumpinfo_t: offsetof pad1")
    static_assert(typeinfo offsetof<pad2>(type<lumpinfo_t>) == 15, "C layout of lumpinfo_t: offsetof pad2")
    static_assert(typeinfo offsetof<name>(type<lumpinfo_t>) == 16, "C layout of lumpinfo_t: offsetof name")
}
