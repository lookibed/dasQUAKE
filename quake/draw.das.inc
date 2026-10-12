var private c2da_str_draw_0 : array<int8> = [int8(99), int8(111), int8(110), int8(99), int8(104), int8(97), int8(114), int8(115), int8(0)]

var private c2da_str_draw_1 : array<int8> = [int8(100), int8(105), int8(115), int8(99), int8(0)]

var private c2da_str_draw_2 : array<int8> = [int8(98), int8(97), int8(99), int8(107), int8(116), int8(105), int8(108), int8(101), int8(0)]

var private c2da_str_draw_3 : array<int8> = [int8(68), int8(114), int8(97), int8(119), int8(95), int8(80), int8(105), int8(99), int8(58), int8(32), int8(98), int8(97), int8(100), int8(32), int8(99), int8(111), int8(111), int8(114), int8(100), int8(105), int8(110), int8(97), int8(116), int8(101), int8(115), int8(0)]

var private c2da_str_draw_4 : array<int8> = [int8(68), int8(114), int8(97), int8(119), int8(95), int8(84), int8(114), int8(97), int8(110), int8(115), int8(80), int8(105), int8(99), int8(58), int8(32), int8(98), int8(97), int8(100), int8(32), int8(99), int8(111), int8(111), int8(114), int8(100), int8(105), int8(110), int8(97), int8(116), int8(101), int8(115), int8(0)]

var private c2da_str_draw_5 : array<int8> = [int8(103), int8(102), int8(120), int8(47), int8(99), int8(111), int8(110), int8(98), int8(97), int8(99), int8(107), int8(46), int8(108), int8(109), int8(112), int8(0)]

var private c2da_str_draw_6 : array<int8> = [int8(37), int8(52), int8(46), int8(50), int8(102), int8(0)]

var private c2da_str_draw_7 : array<int8> = [int8(109), int8(101), int8(110), int8(117), int8(95), int8(110), int8(117), int8(109), int8(99), int8(97), int8(99), int8(104), int8(101), int8(112), int8(105), int8(99), int8(115), int8(32), int8(61), int8(61), int8(32), int8(77), int8(65), int8(88), int8(95), int8(67), int8(65), int8(67), int8(72), int8(69), int8(68), int8(95), int8(80), int8(73), int8(67), int8(83), int8(0)]

var private c2da_str_draw_8 : array<int8> = [int8(68), int8(114), int8(97), int8(119), int8(95), int8(67), int8(97), int8(99), int8(104), int8(101), int8(80), int8(105), int8(99), int8(58), int8(32), int8(102), int8(97), int8(105), int8(108), int8(101), int8(100), int8(32), int8(116), int8(111), int8(32), int8(108), int8(111), int8(97), int8(100), int8(32), int8(37), int8(115), int8(0)]

var draw_disc : qpic_t? = default<qpic_t?>

[export, sideeffects]
def Draw_Init() {
    var i : int
    draw_chars = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(W_GetLumpName(unsafe(addr<int8?>(c2da_str_draw_0[0])))))))
    draw_disc = unsafe(reinterpret<qpic_t?>(unsafe(reinterpret<qpic_t?>(W_GetLumpName(unsafe(addr<int8?>(c2da_str_draw_1[0])))))))
    draw_backtile = unsafe(reinterpret<qpic_t?>(unsafe(reinterpret<qpic_t?>(W_GetLumpName(unsafe(addr<int8?>(c2da_str_draw_2[0])))))))
    r_rectdesc.width = int(draw_backtile.width)  // nolint:PERF020
    r_rectdesc.height = int(draw_backtile.height)  // nolint:PERF020
    var c2da_fresh0 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(draw_backtile)) + 8ul))
    r_rectdesc.ptexbytes = unsafe(reinterpret<uint8?>(c2da_fresh0))
    r_rectdesc.rowbytes = int(draw_backtile.width)  // nolint:PERF020
    return
}
var draw_backtile : qpic_t? = default<qpic_t?>

var private r_rectdesc : rectdesc_t = default<rectdesc_t>

var draw_chars : uint8? = default<uint8?>

[export, sideeffects]
def Draw_Character(var x : int; var y : int; var num : int) {
    var dest : uint8?
    var source : uint8?
    var pusdest : uint16?
    var drawline : int
    num &= 255
    if (y <= -8) {
        return
    }
    source = unsafe(reinterpret<uint8?>(unsafe(unsafe(draw_chars + int64(num >> 4 << 10)) + int64((num & 15) << 3))))
    if (y < 0) {
        drawline = 8 + y
        unsafe {  // nolint:STYLE025
            source -= 128 * y
        }
        y = 0
    } else {
        drawline = 8
    }
    dest = unsafe(reinterpret<uint8?>(unsafe(unsafe(vid.conbuffer + int64(y * vid.conrowbytes)) + x)))
    var c2da_source_addr : uint64 = unsafe(reinterpret<uint64>(source))
    while (true) {
        let c2da_postinc : int = drawline
        drawline--
        if (c2da_postinc == 0) {
            break
        }
        if (unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[0]) != 0x0) {
            unsafe(dest[0]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[0]))  // nolint:PERF020
        }
        if (unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[1]) != 0x0) {
            unsafe(dest[1]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[1]))  // nolint:PERF020
        }
        if (unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[2]) != 0x0) {
            unsafe(dest[2]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[2]))  // nolint:PERF020
        }
        if (unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[3]) != 0x0) {
            unsafe(dest[3]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[3]))  // nolint:PERF020
        }
        if (unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[4]) != 0x0) {
            unsafe(dest[4]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[4]))  // nolint:PERF020
        }
        if (unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[5]) != 0x0) {
            unsafe(dest[5]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[5]))  // nolint:PERF020
        }
        if (unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[6]) != 0x0) {
            unsafe(dest[6]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[6]))  // nolint:PERF020
        }
        if (unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[7]) != 0x0) {
            unsafe(dest[7]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_addr))[7]))  // nolint:PERF020
        }
        c2da_source_addr += 128ul
        unsafe {  // nolint:STYLE025
            dest += int64(vid.conrowbytes)
        }
    }
    return
}
[export, sideeffects]
def Draw_DebugChar(var num_0 : int8) {
    var dest_0 : uint8?
    var source_0 : uint8?
    var drawline_0 : int
    if (vid.direct == null) {
        return
    }
    drawline_0 = 8
    source_0 = unsafe(reinterpret<uint8?>(unsafe(unsafe(draw_chars + (int(num_0) >> 4 << 10)) + ((int(num_0) & 15) << 3))))
    dest_0 = unsafe(reinterpret<uint8?>(unsafe(vid.direct + 312)))
    var c2da_source_0_addr : uint64 = unsafe(reinterpret<uint64>(source_0))
    var c2da_dest_0_addr : uint64 = unsafe(reinterpret<uint64>(dest_0))
    while (true) {
        let c2da_postinc_0 : int = drawline_0
        drawline_0--
        if (c2da_postinc_0 == 0) {
            break
        }
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_0_addr))[0]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_0_addr))[0]))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_0_addr))[1]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_0_addr))[1]))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_0_addr))[2]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_0_addr))[2]))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_0_addr))[3]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_0_addr))[3]))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_0_addr))[4]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_0_addr))[4]))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_0_addr))[5]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_0_addr))[5]))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_0_addr))[6]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_0_addr))[6]))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_0_addr))[7]) = uint8(unsafe(unsafe(reinterpret<uint8?>(c2da_source_0_addr))[7]))  // nolint:PERF020
        c2da_source_0_addr += 128ul
        c2da_dest_0_addr += 320ul
    }
    return
}
[export, sideeffects]
def Draw_Pic(var x_0 : int; var y_0 : int; var pic : qpic_t?) {
    var dest_1 : uint8?
    var source_1 : uint8?
    var pusdest_0 : uint16?
    var v : int
    var u : int
    if (x_0 < 0 || uint(x_0 + pic.width) > vid.width || y_0 < 0 || uint(y_0 + pic.height) > vid.height) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_draw_3[0])), [])
    }
    var c2da_fresh1 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pic)) + 8ul))
    source_1 = unsafe(reinterpret<uint8?>(c2da_fresh1))
    dest_1 = unsafe(reinterpret<uint8?>(unsafe(unsafe(vid.buffer + int64(uint(y_0) * vid.rowbytes)) + x_0)))
    v = 0
    while (v < pic.height) {
        Q_memcpy(unsafe(reinterpret<uint8?>(dest_1)), unsafe(reinterpret<uint8?>(source_1)), pic.width)
        unsafe {  // nolint:STYLE025
            dest_1 += int64(vid.rowbytes)
        }
        unsafe {  // nolint:STYLE025
            source_1 += int64(pic.width)
        }
        v++
    }
    return
}
[export, sideeffects]
def Draw_TransPic(var x_1 : int; var y_1 : int; var pic_0 : qpic_t?) {
    var dest_2 : uint8?
    var source_2 : uint8?
    var tbyte : uint8
    var pusdest_1 : uint16?
    var v_0 : int
    var u_0 : int
    if (x_1 < 0 || uint(x_1 + pic_0.width) > vid.width || y_1 < 0 || uint(y_1 + pic_0.height) > vid.height) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_draw_4[0])), [])
    }
    var c2da_fresh2 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pic_0)) + 8ul))
    source_2 = unsafe(reinterpret<uint8?>(c2da_fresh2))
    dest_2 = unsafe(reinterpret<uint8?>(unsafe(unsafe(vid.buffer + int64(uint(y_1) * vid.rowbytes)) + x_1)))
    if ((pic_0.width & 7) != 0) {
        v_0 = 0
        while (v_0 < pic_0.height) {
            u_0 = 0
            while (u_0 < pic_0.width) {
                tbyte = unsafe(source_2[u_0])
                if (int(tbyte) != 255) {
                    unsafe(dest_2[u_0]) = tbyte
                }
                u_0++
            }
            unsafe {  // nolint:STYLE025
                dest_2 += int64(vid.rowbytes)
            }
            unsafe {  // nolint:STYLE025
                source_2 += int64(pic_0.width)
            }
            v_0++
        }
    } else {
        v_0 = 0
        while (v_0 < pic_0.height) {
            u_0 = 0
            while (u_0 < pic_0.width) {
                tbyte = unsafe(source_2[u_0])
                if (int(tbyte) != 255) {
                    unsafe(dest_2[u_0]) = tbyte
                }
                tbyte = unsafe(source_2[u_0 + 1])
                if (int(tbyte) != 255) {
                    unsafe(dest_2[u_0 + 1]) = tbyte
                }
                tbyte = unsafe(source_2[u_0 + 2])
                if (int(tbyte) != 255) {
                    unsafe(dest_2[u_0 + 2]) = tbyte
                }
                tbyte = unsafe(source_2[u_0 + 3])
                if (int(tbyte) != 255) {
                    unsafe(dest_2[u_0 + 3]) = tbyte
                }
                tbyte = unsafe(source_2[u_0 + 4])
                if (int(tbyte) != 255) {
                    unsafe(dest_2[u_0 + 4]) = tbyte
                }
                tbyte = unsafe(source_2[u_0 + 5])
                if (int(tbyte) != 255) {
                    unsafe(dest_2[u_0 + 5]) = tbyte
                }
                tbyte = unsafe(source_2[u_0 + 6])
                if (int(tbyte) != 255) {
                    unsafe(dest_2[u_0 + 6]) = tbyte
                }
                tbyte = unsafe(source_2[u_0 + 7])
                if (int(tbyte) != 255) {
                    unsafe(dest_2[u_0 + 7]) = tbyte
                }
                u_0 += 8
            }
            unsafe {  // nolint:STYLE025
                dest_2 += int64(vid.rowbytes)
            }
            unsafe {  // nolint:STYLE025
                source_2 += int64(pic_0.width)
            }
            v_0++
        }
    }
    return
}
[export, sideeffects]
def Draw_TransPicTranslate(var x_2 : int; var y_2 : int; var pic_1 : qpic_t?; var translation : uint8?) {
    var dest_3 : uint8?
    var source_3 : uint8?
    var tbyte_0 : uint8
    var pusdest_2 : uint16?
    var v_1 : int
    var u_1 : int
    if (x_2 < 0 || uint(x_2 + pic_1.width) > vid.width || y_2 < 0 || uint(y_2 + pic_1.height) > vid.height) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_draw_4[0])), [])
    }
    var c2da_fresh3 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pic_1)) + 8ul))
    source_3 = unsafe(reinterpret<uint8?>(c2da_fresh3))
    dest_3 = unsafe(reinterpret<uint8?>(unsafe(unsafe(vid.buffer + int64(uint(y_2) * vid.rowbytes)) + x_2)))
    if ((pic_1.width & 7) != 0) {
        v_1 = 0
        while (v_1 < pic_1.height) {
            u_1 = 0
            while (u_1 < pic_1.width) {
                tbyte_0 = unsafe(source_3[u_1])
                if (int(tbyte_0) != 255) {
                    unsafe(dest_3[u_1]) = uint8(unsafe(translation[int(tbyte_0)]))  // nolint:PERF020
                }
                u_1++
            }
            unsafe {  // nolint:STYLE025
                dest_3 += int64(vid.rowbytes)
            }
            unsafe {  // nolint:STYLE025
                source_3 += int64(pic_1.width)
            }
            v_1++
        }
    } else {
        v_1 = 0
        while (v_1 < pic_1.height) {
            u_1 = 0
            while (u_1 < pic_1.width) {
                tbyte_0 = unsafe(source_3[u_1])
                if (int(tbyte_0) != 255) {
                    unsafe(dest_3[u_1]) = uint8(unsafe(translation[int(tbyte_0)]))  // nolint:PERF020
                }
                tbyte_0 = unsafe(source_3[u_1 + 1])
                if (int(tbyte_0) != 255) {
                    unsafe(dest_3[u_1 + 1]) = uint8(unsafe(translation[int(tbyte_0)]))  // nolint:PERF020
                }
                tbyte_0 = unsafe(source_3[u_1 + 2])
                if (int(tbyte_0) != 255) {
                    unsafe(dest_3[u_1 + 2]) = uint8(unsafe(translation[int(tbyte_0)]))  // nolint:PERF020
                }
                tbyte_0 = unsafe(source_3[u_1 + 3])
                if (int(tbyte_0) != 255) {
                    unsafe(dest_3[u_1 + 3]) = uint8(unsafe(translation[int(tbyte_0)]))  // nolint:PERF020
                }
                tbyte_0 = unsafe(source_3[u_1 + 4])
                if (int(tbyte_0) != 255) {
                    unsafe(dest_3[u_1 + 4]) = uint8(unsafe(translation[int(tbyte_0)]))  // nolint:PERF020
                }
                tbyte_0 = unsafe(source_3[u_1 + 5])
                if (int(tbyte_0) != 255) {
                    unsafe(dest_3[u_1 + 5]) = uint8(unsafe(translation[int(tbyte_0)]))  // nolint:PERF020
                }
                tbyte_0 = unsafe(source_3[u_1 + 6])
                if (int(tbyte_0) != 255) {
                    unsafe(dest_3[u_1 + 6]) = uint8(unsafe(translation[int(tbyte_0)]))  // nolint:PERF020
                }
                tbyte_0 = unsafe(source_3[u_1 + 7])
                if (int(tbyte_0) != 255) {
                    unsafe(dest_3[u_1 + 7]) = uint8(unsafe(translation[int(tbyte_0)]))  // nolint:PERF020
                }
                u_1 += 8
            }
            unsafe {  // nolint:STYLE025
                dest_3 += int64(vid.rowbytes)
            }
            unsafe {  // nolint:STYLE025
                source_3 += int64(pic_1.width)
            }
            v_1++
        }
    }
    return
}
[export, sideeffects]
def Draw_ConsoleBackground(var lines : int) {
    var x_3 : int
    var y_3 : int
    var src : uint8?
    var dest_4 : uint8?
    var pusdest_3 : uint16?
    var f : int
    var fstep : int
    var conback : qpic_t?
    var ver : int8[100]
    conback = unsafe(reinterpret<qpic_t?>(unsafe(reinterpret<qpic_t?>(Draw_CachePic(unsafe(addr<int8?>(c2da_str_draw_5[0])))))))
    var c2da_fresh4 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(conback)) + 8ul))
    dest_4 = unsafe(reinterpret<uint8?>(unsafe(unsafe(unsafe(c2da_fresh4 + 320) + -43) + 320 * 186)))
    c2da_std_sprintf(unsafe(reinterpret<uint64>(unsafe(addr(ver[0])))), unsafe(addr<int8 const?>(c2da_str_draw_6[0])), [C2daVaArg(tag = 2, i64 = 0, f64 = 1.09lf, raw = 0x0)])
    x_3 = 0
    while (uint64(x_3) < c2da_std_strlen(unsafe(reinterpret<uint64>(unsafe(addr(ver[0])))))) {
        Draw_CharToConback(int(ver[x_3]), unsafe(reinterpret<uint8?>(unsafe(dest_4 + int64(x_3 << 3)))))
        x_3++
    }
    dest_4 = unsafe(reinterpret<uint8?>(vid.conbuffer))
    y_3 = 0
    while (y_3 < lines) {
        var c2da_fresh5 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(conback)) + 8ul))
        src = unsafe(reinterpret<uint8?>(unsafe(c2da_fresh5 + int((vid.conheight - uint(lines) + uint(y_3)) * 200u / vid.conheight) * 320)))
        if (vid.conwidth == 320u) {
            let c2da_fresh6 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(dest_4))))
            let c2da_fresh7 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(src))))
            let c2da_fresh8 : uint64 = uint64(vid.conwidth)
            if (c2da_fresh8 != 0x0) {
                unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh6)), unsafe(reinterpret<void?>(c2da_fresh7)), c2da_fresh8))
            }
        } else {
            f = 0
            fstep = int(uint(320 * 65536) / vid.conwidth)
            x_3 = 0
            while (uint(x_3) < vid.conwidth) {
                unsafe(dest_4[x_3]) = uint8(unsafe(src[f >> 16]))  // nolint:PERF020
                f += fstep
                unsafe(dest_4[x_3 + 1]) = uint8(unsafe(src[f >> 16]))  // nolint:PERF020
                f += fstep
                unsafe(dest_4[x_3 + 2]) = uint8(unsafe(src[f >> 16]))  // nolint:PERF020
                f += fstep
                unsafe(dest_4[x_3 + 3]) = uint8(unsafe(src[f >> 16]))  // nolint:PERF020
                f += fstep
                x_3 += 4
            }
        }
        y_3++
        unsafe {  // nolint:STYLE025
            dest_4 += int64(vid.conrowbytes)
        }
    }
    return
}
[export, sideeffects]
def Draw_CharToConback(var num_1 : int; var dest_5 : uint8?) {
    var source_4 : uint8?
    var drawline_1 : int
    source_4 = unsafe(reinterpret<uint8?>(unsafe(unsafe(draw_chars + int64(num_1 >> 4 << 10)) + int64((num_1 & 15) << 3))))
    drawline_1 = 8
    var c2da_source_4_addr : uint64 = unsafe(reinterpret<uint64>(source_4))
    var c2da_dest_5_addr : uint64 = unsafe(reinterpret<uint64>(dest_5))
    while (true) {
        let c2da_postinc_1 : int = drawline_1
        drawline_1--
        if (c2da_postinc_1 == 0) {
            break
        }
        for (x_4 in range(0, 8)) {
            if (unsafe(unsafe(reinterpret<uint8?>(c2da_source_4_addr))[x_4]) != 0x0) {
                unsafe(unsafe(reinterpret<uint8?>(c2da_dest_5_addr))[x_4]) = uint8(96 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_source_4_addr))[x_4])))
            }
        }
        c2da_source_4_addr += 128ul
        c2da_dest_5_addr += 320ul
    }
    return
}
[export, sideeffects]
def Draw_CachePic(var path : int8?) : qpic_t? {
    var pic_2 : cachepic_s?
    var i_0 : int
    var dat : qpic_t?
    pic_2 = unsafe(addr<cachepic_s?>(menu_cachepics[0]))
    i_0 = 0
    while (i_0 < menu_numcachepics) {
        var c2da_fresh9 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(pic_2))))
        if (c2da_std_strcmp(unsafe(reinterpret<uint64>(path)), unsafe(reinterpret<uint64>(c2da_fresh9))) == 0) {
            break
        }
        unsafe {  // nolint:STYLE025
            pic_2 += 1
        }
        i_0++
    }
    if (i_0 == menu_numcachepics) {
        if (menu_numcachepics == 128) {
            Sys_Error(unsafe(addr<int8?>(c2da_str_draw_7[0])), [])
        }
        menu_numcachepics++
        var c2da_fresh10 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(pic_2))))
        unsafe(reinterpret<int8?>(c2da_std_strcpy(unsafe(reinterpret<uint64>(c2da_fresh10)), unsafe(reinterpret<uint64>(path)))))
    }
    var c2da_fresh11 : cache_user_s? = unsafe(reinterpret<cache_user_s?>(unsafe(reinterpret<uint64>(pic_2)) + 64ul))
    dat = unsafe(reinterpret<qpic_t?>(unsafe(reinterpret<qpic_t?>(Cache_Check(unsafe(reinterpret<cache_user_s?>(c2da_fresh11)))))))
    if (dat != null) {
        return unsafe(reinterpret<qpic_t?>(dat))
    }
    var c2da_fresh12 : cache_user_s? = unsafe(reinterpret<cache_user_s?>(unsafe(reinterpret<uint64>(pic_2)) + 64ul))
    COM_LoadCacheFile(path, unsafe(reinterpret<cache_user_s?>(c2da_fresh12)))
    dat = unsafe(reinterpret<qpic_t?>(unsafe(reinterpret<qpic_t?>(pic_2.cache.data))))
    if (dat == null) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_draw_8[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(path)))])
    }
    SwapPic(dat)
    return unsafe(reinterpret<qpic_t?>(dat))
}
var menu_numcachepics : int = default<int>

var menu_cachepics : cachepic_s[128]

[export, sideeffects]
def Draw_BeginDisc() {
    var c2da_fresh13 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(draw_disc)) + 8ul))
    D_BeginDirectRect(int(vid.width - 24u), 0, unsafe(reinterpret<uint8?>(c2da_fresh13)), 24, 24)
    return
}
[export, sideeffects]
def Draw_EndDisc() {
    D_EndDirectRect(int(vid.width - 24u), 0, 24, 24)
    return
}
[export, sideeffects]
def Draw_TileClear(var x_5 : int; var y_4 : int; var w : int; var h : int) {
    var width : int
    var height : int
    var tileoffsetx : int
    var tileoffsety : int
    var psrc : uint8?
    var vr : vrect_s
    r_rectdesc.rect.x = int(x_5)  // nolint:PERF020
    r_rectdesc.rect.y = int(y_4)  // nolint:PERF020
    r_rectdesc.rect.width = int(w)  // nolint:PERF020
    r_rectdesc.rect.height = int(h)  // nolint:PERF020
    vr.y = r_rectdesc.rect.y
    height = r_rectdesc.rect.height
    tileoffsety = vr.y % r_rectdesc.height
    while (height > 0) {
        vr.x = r_rectdesc.rect.x
        width = r_rectdesc.rect.width
        if (tileoffsety != 0) {
            vr.height = r_rectdesc.height - tileoffsety
        } else {
            vr.height = r_rectdesc.height
        }
        if (vr.height > height) {
            vr.height = height
        }
        tileoffsetx = vr.x % r_rectdesc.width
        while (width > 0) {
            if (tileoffsetx != 0) {
                vr.width = r_rectdesc.width - tileoffsetx
            } else {
                vr.width = r_rectdesc.width
            }
            if (vr.width > width) {
                vr.width = width
            }
            psrc = unsafe(reinterpret<uint8?>(unsafe(unsafe(r_rectdesc.ptexbytes + int64(tileoffsety * r_rectdesc.rowbytes)) + tileoffsetx)))
            R_DrawRect(unsafe(addr<vrect_s?>(vr)), r_rectdesc.rowbytes, psrc, 0)
            vr.x += vr.width
            width -= vr.width
            tileoffsetx = 0
        }
        vr.y += vr.height
        height -= vr.height
        tileoffsety = 0
    }
    return
}
[export, sideeffects]
def R_DrawRect(var prect : vrect_s?; var rowbytes : int; var psrc_0 : uint8?; var transparent : int) {
    var t : uint8
    var i_1 : int
    var j : int
    var srcdelta : int
    var destdelta : int
    var pdest : uint8? = unsafe(reinterpret<uint8?>(unsafe(unsafe(vid.buffer + int64(uint(prect.y) * vid.rowbytes)) + prect.x)))
    srcdelta = rowbytes - prect.width
    destdelta = int(vid.rowbytes - uint(prect.width))
    if (transparent != 0) {
        i_1 = 0
        while (i_1 < prect.height) {
            var c2da_psrc_0_addr : uint64 = unsafe(reinterpret<uint64>(psrc_0))
            var c2da_pdest_addr : uint64 = unsafe(reinterpret<uint64>(pdest))
            j = 0
            while (j < prect.width) {
                t = *unsafe(reinterpret<uint8?>(c2da_psrc_0_addr))
                if (int(t) != 255) {
                    *unsafe(reinterpret<uint8?>(c2da_pdest_addr)) = t
                }
                c2da_psrc_0_addr++
                c2da_pdest_addr++
                j++
            }
            psrc_0 = unsafe(reinterpret<uint8?>(c2da_psrc_0_addr))
            pdest = unsafe(reinterpret<uint8?>(c2da_pdest_addr))
            unsafe {  // nolint:STYLE025
                psrc_0 += int64(srcdelta)
            }
            unsafe {  // nolint:STYLE025
                pdest += int64(destdelta)
            }
            i_1++
        }
    } else {
        i_1 = 0
        while (i_1 < prect.height) {
            let c2da_fresh14 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(pdest))))
            let c2da_fresh15 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(psrc_0))))
            let c2da_fresh16 : uint64 = uint64(prect.width)
            if (c2da_fresh16 != 0x0) {
                unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh14)), unsafe(reinterpret<void?>(c2da_fresh15)), c2da_fresh16))
            }
            unsafe {  // nolint:STYLE025
                psrc_0 += int64(rowbytes)
            }
            unsafe {  // nolint:STYLE025
                pdest += int64(vid.rowbytes)
            }
            i_1++
        }
    }
    return
}
[export, sideeffects]
def Draw_Fill(var x_6 : int; var y_5 : int; var w_0 : int; var h_0 : int; var c : int) {
    var dest_6 : uint8?
    var pusdest_4 : uint16?
    var uc : uint
    var v_3 : int
    dest_6 = unsafe(reinterpret<uint8?>(unsafe(unsafe(vid.buffer + int64(uint(y_5) * vid.rowbytes)) + x_6)))
    v_3 = 0
    while (v_3 < h_0) {
        for (u_2 in range(0, w_0)) {
            unsafe(dest_6[u_2]) = uint8(c)
        }
        v_3++
        unsafe {  // nolint:STYLE025
            dest_6 += int64(vid.rowbytes)
        }
    }
    return
}
[export, sideeffects]
def Draw_FadeScreen() {
    var x_7 : int
    var y_6 : int
    var pbuf : uint8?
    var t_0 : int
    S_ExtraUpdate()
    y_6 = 0
    while (uint(y_6) < vid.height) {
        pbuf = unsafe(reinterpret<uint8?>(unsafe(vid.buffer + int64(vid.rowbytes * uint(y_6)))))
        t_0 = (y_6 & 1) << 1
        x_7 = 0
        while (uint(x_7) < vid.width) {
            if ((x_7 & 3) != t_0) {
                unsafe(pbuf[x_7]) = 0u8
            }
            x_7++
        }
        y_6++
    }
    S_ExtraUpdate()
    return
}
[export, sideeffects]
def Draw_String(var x_8 : int; var y_7 : int; var str : int8?) {
    var c2da_str_addr : uint64 = unsafe(reinterpret<uint64>(str))
    while (*unsafe(reinterpret<int8?>(c2da_str_addr)) != 0) {
        Draw_Character(x_8, y_7, int(*unsafe(reinterpret<int8?>(c2da_str_addr))))
        c2da_str_addr++
        x_8 += 8
    }
    return
}
[export, sideeffects]
def Draw_PicFromWad(var name : int8?) : qpic_t? {
    return unsafe(reinterpret<qpic_t?>(unsafe(reinterpret<qpic_t?>(W_GetLumpName(name)))))
}
[sideeffects]
def private c2da_layout_proofs_18() {
    static_assert(typeinfo sizeof(type<cache_user_s>) == 8, "C layout of cache_user_s: sizeof")
    static_assert(typeinfo alignof(type<cache_user_s>) == 8, "C layout of cache_user_s: alignof")
    static_assert(typeinfo offsetof<data>(type<cache_user_s>) == 0, "C layout of cache_user_s: offsetof data")
    static_assert(typeinfo sizeof(type<vrect_s>) == 24, "C layout of vrect_s: sizeof")
    static_assert(typeinfo alignof(type<vrect_s>) == 8, "C layout of vrect_s: alignof")
    static_assert(typeinfo offsetof<x>(type<vrect_s>) == 0, "C layout of vrect_s: offsetof x")
    static_assert(typeinfo offsetof<y>(type<vrect_s>) == 4, "C layout of vrect_s: offsetof y")
    static_assert(typeinfo offsetof<width>(type<vrect_s>) == 8, "C layout of vrect_s: offsetof width")
    static_assert(typeinfo offsetof<height>(type<vrect_s>) == 12, "C layout of vrect_s: offsetof height")
    static_assert(typeinfo offsetof<pnext>(type<vrect_s>) == 16, "C layout of vrect_s: offsetof pnext")
    static_assert(typeinfo sizeof(type<vrect_t>) == 24, "C layout of vrect_t: sizeof")
    static_assert(typeinfo alignof(type<vrect_t>) == 8, "C layout of vrect_t: alignof")
    static_assert(typeinfo offsetof<x>(type<vrect_t>) == 0, "C layout of vrect_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<vrect_t>) == 4, "C layout of vrect_t: offsetof y")
    static_assert(typeinfo offsetof<width>(type<vrect_t>) == 8, "C layout of vrect_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<vrect_t>) == 12, "C layout of vrect_t: offsetof height")
    static_assert(typeinfo offsetof<pnext>(type<vrect_t>) == 16, "C layout of vrect_t: offsetof pnext")
    static_assert(typeinfo sizeof(type<viddef_t>) == 96, "C layout of viddef_t: sizeof")
    static_assert(typeinfo alignof(type<viddef_t>) == 8, "C layout of viddef_t: alignof")
    static_assert(typeinfo offsetof<buffer>(type<viddef_t>) == 0, "C layout of viddef_t: offsetof buffer")
    static_assert(typeinfo offsetof<colormap>(type<viddef_t>) == 8, "C layout of viddef_t: offsetof colormap")
    static_assert(typeinfo offsetof<colormap16>(type<viddef_t>) == 16, "C layout of viddef_t: offsetof colormap16")
    static_assert(typeinfo offsetof<fullbright>(type<viddef_t>) == 24, "C layout of viddef_t: offsetof fullbright")
    static_assert(typeinfo offsetof<rowbytes>(type<viddef_t>) == 28, "C layout of viddef_t: offsetof rowbytes")
    static_assert(typeinfo offsetof<width>(type<viddef_t>) == 32, "C layout of viddef_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<viddef_t>) == 36, "C layout of viddef_t: offsetof height")
    static_assert(typeinfo offsetof<aspect>(type<viddef_t>) == 40, "C layout of viddef_t: offsetof aspect")
    static_assert(typeinfo offsetof<numpages>(type<viddef_t>) == 44, "C layout of viddef_t: offsetof numpages")
    static_assert(typeinfo offsetof<recalc_refdef>(type<viddef_t>) == 48, "C layout of viddef_t: offsetof recalc_refdef")
    static_assert(typeinfo offsetof<conbuffer>(type<viddef_t>) == 56, "C layout of viddef_t: offsetof conbuffer")
    static_assert(typeinfo offsetof<conrowbytes>(type<viddef_t>) == 64, "C layout of viddef_t: offsetof conrowbytes")
    static_assert(typeinfo offsetof<conwidth>(type<viddef_t>) == 68, "C layout of viddef_t: offsetof conwidth")
    static_assert(typeinfo offsetof<conheight>(type<viddef_t>) == 72, "C layout of viddef_t: offsetof conheight")
    static_assert(typeinfo offsetof<maxwarpwidth>(type<viddef_t>) == 76, "C layout of viddef_t: offsetof maxwarpwidth")
    static_assert(typeinfo offsetof<maxwarpheight>(type<viddef_t>) == 80, "C layout of viddef_t: offsetof maxwarpheight")
    static_assert(typeinfo offsetof<direct>(type<viddef_t>) == 88, "C layout of viddef_t: offsetof direct")
    static_assert(typeinfo sizeof(type<cache_user_t>) == 8, "C layout of cache_user_t: sizeof")
    static_assert(typeinfo alignof(type<cache_user_t>) == 8, "C layout of cache_user_t: alignof")
    static_assert(typeinfo offsetof<data>(type<cache_user_t>) == 0, "C layout of cache_user_t: offsetof data")
    static_assert(typeinfo sizeof(type<qpic_t>) == 12, "C layout of qpic_t: sizeof")
    static_assert(typeinfo alignof(type<qpic_t>) == 4, "C layout of qpic_t: alignof")
    static_assert(typeinfo offsetof<width>(type<qpic_t>) == 0, "C layout of qpic_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<qpic_t>) == 4, "C layout of qpic_t: offsetof height")
    static_assert(typeinfo offsetof<data>(type<qpic_t>) == 8, "C layout of qpic_t: offsetof data")
    static_assert(typeinfo sizeof(type<rectdesc_t>) == 48, "C layout of rectdesc_t: sizeof")
    static_assert(typeinfo alignof(type<rectdesc_t>) == 8, "C layout of rectdesc_t: alignof")
    static_assert(typeinfo offsetof<rect>(type<rectdesc_t>) == 0, "C layout of rectdesc_t: offsetof rect")
    static_assert(typeinfo offsetof<width>(type<rectdesc_t>) == 24, "C layout of rectdesc_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<rectdesc_t>) == 28, "C layout of rectdesc_t: offsetof height")
    static_assert(typeinfo offsetof<ptexbytes>(type<rectdesc_t>) == 32, "C layout of rectdesc_t: offsetof ptexbytes")
    static_assert(typeinfo offsetof<rowbytes>(type<rectdesc_t>) == 40, "C layout of rectdesc_t: offsetof rowbytes")
    static_assert(typeinfo sizeof(type<cachepic_t>) == 72, "C layout of cachepic_t: sizeof")
    static_assert(typeinfo alignof(type<cachepic_t>) == 8, "C layout of cachepic_t: alignof")
    static_assert(typeinfo offsetof<name>(type<cachepic_t>) == 0, "C layout of cachepic_t: offsetof name")
    static_assert(typeinfo offsetof<cache>(type<cachepic_t>) == 64, "C layout of cachepic_t: offsetof cache")
    static_assert(typeinfo sizeof(type<cachepic_s>) == 72, "C layout of cachepic_s: sizeof")
    static_assert(typeinfo alignof(type<cachepic_s>) == 8, "C layout of cachepic_s: alignof")
    static_assert(typeinfo offsetof<name>(type<cachepic_s>) == 0, "C layout of cachepic_s: offsetof name")
    static_assert(typeinfo offsetof<cache>(type<cachepic_s>) == 64, "C layout of cachepic_s: offsetof cache")
}
