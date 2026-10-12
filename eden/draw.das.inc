var draw_disc : int = default<int>

[export, sideeffects]
def Draw_Init() {
    var i : int
    draw_chars = W_GetLumpName(715440)
    draw_disc = W_GetLumpName(715449)
    draw_backtile = W_GetLumpName(715454)
    r_rectdesc.width = int(uint(c2da_mem[draw_backtile]) | uint(c2da_mem[draw_backtile + 1]) << 0x8 | uint(c2da_mem[draw_backtile + 2]) << 0x10 | uint(c2da_mem[draw_backtile + 3]) << 0x18)
    r_rectdesc.height = int(uint(c2da_mem[draw_backtile + 4]) | uint(c2da_mem[draw_backtile + 5]) << 0x8 | uint(c2da_mem[draw_backtile + 6]) << 0x10 | uint(c2da_mem[draw_backtile + 7]) << 0x18)
    r_rectdesc.ptexbytes = draw_backtile + 8
    r_rectdesc.rowbytes = int(uint(c2da_mem[draw_backtile]) | uint(c2da_mem[draw_backtile + 1]) << 0x8 | uint(c2da_mem[draw_backtile + 2]) << 0x10 | uint(c2da_mem[draw_backtile + 3]) << 0x18)
    return
}
var draw_backtile : int = default<int>

var private r_rectdesc : rectdesc_t = default<rectdesc_t>

var draw_chars : int = default<int>

[export, sideeffects]
def Draw_Character(var x : int; var y : int; var num : int) {
    var dest : int
    var source : int
    var pusdest : int
    var drawline : int
    num &= 255
    if (y <= -8) {
        return
    }
    source = draw_chars + (num >> 4 << 10) + ((num & 15) << 3)
    if (y < 0) {
        drawline = 8 + y
        source -= 128 * y
        y = 0
    } else {
        drawline = 8
    }
    dest = vid.conbuffer + int(y * vid.conrowbytes) + x
    while (true) {
        let c2da_postinc : int = drawline
        drawline--
        if (c2da_postinc == 0) {
            break
        }
        if (c2da_mem[source + 0] != 0x0) {
            let c2da_fresh0 : uint8 = c2da_mem[source + 0]
            c2da_mem[dest + 0] = c2da_fresh0
        }
        if (c2da_mem[source + 1] != 0x0) {
            let c2da_fresh1 : uint8 = c2da_mem[source + 1]
            c2da_mem[dest + 1] = c2da_fresh1
        }
        if (c2da_mem[source + 2] != 0x0) {
            let c2da_fresh2 : uint8 = c2da_mem[source + 2]
            c2da_mem[dest + 2] = c2da_fresh2
        }
        if (c2da_mem[source + 3] != 0x0) {
            let c2da_fresh3 : uint8 = c2da_mem[source + 3]
            c2da_mem[dest + 3] = c2da_fresh3
        }
        if (c2da_mem[source + 4] != 0x0) {
            let c2da_fresh4 : uint8 = c2da_mem[source + 4]
            c2da_mem[dest + 4] = c2da_fresh4
        }
        if (c2da_mem[source + 5] != 0x0) {
            let c2da_fresh5 : uint8 = c2da_mem[source + 5]
            c2da_mem[dest + 5] = c2da_fresh5
        }
        if (c2da_mem[source + 6] != 0x0) {
            let c2da_fresh6 : uint8 = c2da_mem[source + 6]
            c2da_mem[dest + 6] = c2da_fresh6
        }
        if (c2da_mem[source + 7] != 0x0) {
            let c2da_fresh7 : uint8 = c2da_mem[source + 7]
            c2da_mem[dest + 7] = c2da_fresh7
        }
        source += 128
        dest += int(vid.conrowbytes)
    }
    return
}
[export, sideeffects]
def Draw_DebugChar(var num_0 : int8) {
    var dest_0 : int
    var source_0 : int
    var drawline_0 : int
    if (vid.direct == 0) {
        return
    }
    drawline_0 = 8
    source_0 = draw_chars + (int(num_0) >> 4 << 10) + ((int(num_0) & 15) << 3)
    dest_0 = vid.direct + 312
    while (true) {
        let c2da_postinc_0 : int = drawline_0
        drawline_0--
        if (c2da_postinc_0 == 0) {
            break
        }
        let c2da_fresh8 : uint8 = c2da_mem[source_0 + 0]
        c2da_mem[dest_0 + 0] = c2da_fresh8
        let c2da_fresh9 : uint8 = c2da_mem[source_0 + 1]
        c2da_mem[dest_0 + 1] = c2da_fresh9
        let c2da_fresh10 : uint8 = c2da_mem[source_0 + 2]
        c2da_mem[dest_0 + 2] = c2da_fresh10
        let c2da_fresh11 : uint8 = c2da_mem[source_0 + 3]
        c2da_mem[dest_0 + 3] = c2da_fresh11
        let c2da_fresh12 : uint8 = c2da_mem[source_0 + 4]
        c2da_mem[dest_0 + 4] = c2da_fresh12
        let c2da_fresh13 : uint8 = c2da_mem[source_0 + 5]
        c2da_mem[dest_0 + 5] = c2da_fresh13
        let c2da_fresh14 : uint8 = c2da_mem[source_0 + 6]
        c2da_mem[dest_0 + 6] = c2da_fresh14
        let c2da_fresh15 : uint8 = c2da_mem[source_0 + 7]
        c2da_mem[dest_0 + 7] = c2da_fresh15
        source_0 += 128
        dest_0 += 320
    }
    return
}
[export, sideeffects]
def Draw_Pic(var x_0 : int; var y_0 : int; var pic : int) {
    var dest_1 : int
    var source_1 : int
    var pusdest_0 : int
    var v : int
    var u : int
    if (x_0 < 0 || uint(x_0 + int(uint(c2da_mem[pic]) | uint(c2da_mem[pic + 1]) << 0x8 | uint(c2da_mem[pic + 2]) << 0x10 | uint(c2da_mem[pic + 3]) << 0x18)) > vid.width || y_0 < 0 || uint(y_0 + int(uint(c2da_mem[pic + 4]) | uint(c2da_mem[pic + 5]) << 0x8 | uint(c2da_mem[pic + 6]) << 0x10 | uint(c2da_mem[pic + 7]) << 0x18)) > vid.height) {
        Sys_Error(715463, [])
    }
    source_1 = pic + 8
    dest_1 = vid.buffer + int(uint(y_0) * vid.rowbytes) + x_0
    v = 0
    while (v < int(uint(c2da_mem[pic + 4]) | uint(c2da_mem[pic + 5]) << 0x8 | uint(c2da_mem[pic + 6]) << 0x10 | uint(c2da_mem[pic + 7]) << 0x18)) {
        Q_memcpy(dest_1, source_1, int(uint(c2da_mem[pic]) | uint(c2da_mem[pic + 1]) << 0x8 | uint(c2da_mem[pic + 2]) << 0x10 | uint(c2da_mem[pic + 3]) << 0x18))
        dest_1 += int(vid.rowbytes)
        source_1 += int(uint(c2da_mem[pic]) | uint(c2da_mem[pic + 1]) << 0x8 | uint(c2da_mem[pic + 2]) << 0x10 | uint(c2da_mem[pic + 3]) << 0x18)
        v++
    }
    return
}
[export, sideeffects]
def Draw_TransPic(var x_1 : int; var y_1 : int; var pic_0 : int) {
    var dest_2 : int
    var source_2 : int
    var tbyte : uint8
    var pusdest_1 : int
    var v_0 : int
    var u_0 : int
    if (x_1 < 0 || uint(x_1 + int(uint(c2da_mem[pic_0]) | uint(c2da_mem[pic_0 + 1]) << 0x8 | uint(c2da_mem[pic_0 + 2]) << 0x10 | uint(c2da_mem[pic_0 + 3]) << 0x18)) > vid.width || y_1 < 0 || uint(y_1 + int(uint(c2da_mem[pic_0 + 4]) | uint(c2da_mem[pic_0 + 5]) << 0x8 | uint(c2da_mem[pic_0 + 6]) << 0x10 | uint(c2da_mem[pic_0 + 7]) << 0x18)) > vid.height) {
        Sys_Error(715489, [])
    }
    source_2 = pic_0 + 8
    dest_2 = vid.buffer + int(uint(y_1) * vid.rowbytes) + x_1
    let c2da_fresh16 : int = int(uint(c2da_mem[pic_0]) | uint(c2da_mem[pic_0 + 1]) << 0x8 | uint(c2da_mem[pic_0 + 2]) << 0x10 | uint(c2da_mem[pic_0 + 3]) << 0x18)
    if ((c2da_fresh16 & 7) != 0) {
        v_0 = 0
        while (v_0 < int(uint(c2da_mem[pic_0 + 4]) | uint(c2da_mem[pic_0 + 5]) << 0x8 | uint(c2da_mem[pic_0 + 6]) << 0x10 | uint(c2da_mem[pic_0 + 7]) << 0x18)) {
            u_0 = 0
            while (u_0 < int(uint(c2da_mem[pic_0]) | uint(c2da_mem[pic_0 + 1]) << 0x8 | uint(c2da_mem[pic_0 + 2]) << 0x10 | uint(c2da_mem[pic_0 + 3]) << 0x18)) {
                tbyte = uint8(c2da_mem[source_2 + u_0])
                if (int(tbyte) != 255) {
                    c2da_mem[dest_2 + u_0] = tbyte
                }
                u_0++
            }
            dest_2 += int(vid.rowbytes)
            source_2 += int(uint(c2da_mem[pic_0]) | uint(c2da_mem[pic_0 + 1]) << 0x8 | uint(c2da_mem[pic_0 + 2]) << 0x10 | uint(c2da_mem[pic_0 + 3]) << 0x18)
            v_0++
        }
    } else {
        v_0 = 0
        while (v_0 < int(uint(c2da_mem[pic_0 + 4]) | uint(c2da_mem[pic_0 + 5]) << 0x8 | uint(c2da_mem[pic_0 + 6]) << 0x10 | uint(c2da_mem[pic_0 + 7]) << 0x18)) {
            u_0 = 0
            while (u_0 < int(uint(c2da_mem[pic_0]) | uint(c2da_mem[pic_0 + 1]) << 0x8 | uint(c2da_mem[pic_0 + 2]) << 0x10 | uint(c2da_mem[pic_0 + 3]) << 0x18)) {
                tbyte = uint8(c2da_mem[source_2 + u_0])
                if (int(tbyte) != 255) {
                    c2da_mem[dest_2 + u_0] = tbyte
                }
                tbyte = uint8(c2da_mem[source_2 + (u_0 + 1)])
                if (int(tbyte) != 255) {
                    c2da_mem[dest_2 + (u_0 + 1)] = tbyte
                }
                tbyte = uint8(c2da_mem[source_2 + (u_0 + 2)])
                if (int(tbyte) != 255) {
                    c2da_mem[dest_2 + (u_0 + 2)] = tbyte
                }
                tbyte = uint8(c2da_mem[source_2 + (u_0 + 3)])
                if (int(tbyte) != 255) {
                    c2da_mem[dest_2 + (u_0 + 3)] = tbyte
                }
                tbyte = uint8(c2da_mem[source_2 + (u_0 + 4)])
                if (int(tbyte) != 255) {
                    c2da_mem[dest_2 + (u_0 + 4)] = tbyte
                }
                tbyte = uint8(c2da_mem[source_2 + (u_0 + 5)])
                if (int(tbyte) != 255) {
                    c2da_mem[dest_2 + (u_0 + 5)] = tbyte
                }
                tbyte = uint8(c2da_mem[source_2 + (u_0 + 6)])
                if (int(tbyte) != 255) {
                    c2da_mem[dest_2 + (u_0 + 6)] = tbyte
                }
                tbyte = uint8(c2da_mem[source_2 + (u_0 + 7)])
                if (int(tbyte) != 255) {
                    c2da_mem[dest_2 + (u_0 + 7)] = tbyte
                }
                u_0 += 8
            }
            dest_2 += int(vid.rowbytes)
            source_2 += int(uint(c2da_mem[pic_0]) | uint(c2da_mem[pic_0 + 1]) << 0x8 | uint(c2da_mem[pic_0 + 2]) << 0x10 | uint(c2da_mem[pic_0 + 3]) << 0x18)
            v_0++
        }
    }
    return
}
[export, sideeffects]
def Draw_TransPicTranslate(var x_2 : int; var y_2 : int; var pic_1 : int; var translation : int) {
    var dest_3 : int
    var source_3 : int
    var tbyte_0 : uint8
    var pusdest_2 : int
    var v_1 : int
    var u_1 : int
    if (x_2 < 0 || uint(x_2 + int(uint(c2da_mem[pic_1]) | uint(c2da_mem[pic_1 + 1]) << 0x8 | uint(c2da_mem[pic_1 + 2]) << 0x10 | uint(c2da_mem[pic_1 + 3]) << 0x18)) > vid.width || y_2 < 0 || uint(y_2 + int(uint(c2da_mem[pic_1 + 4]) | uint(c2da_mem[pic_1 + 5]) << 0x8 | uint(c2da_mem[pic_1 + 6]) << 0x10 | uint(c2da_mem[pic_1 + 7]) << 0x18)) > vid.height) {
        Sys_Error(715489, [])
    }
    source_3 = pic_1 + 8
    dest_3 = vid.buffer + int(uint(y_2) * vid.rowbytes) + x_2
    let c2da_fresh26 : int = int(uint(c2da_mem[pic_1]) | uint(c2da_mem[pic_1 + 1]) << 0x8 | uint(c2da_mem[pic_1 + 2]) << 0x10 | uint(c2da_mem[pic_1 + 3]) << 0x18)
    if ((c2da_fresh26 & 7) != 0) {
        v_1 = 0
        while (v_1 < int(uint(c2da_mem[pic_1 + 4]) | uint(c2da_mem[pic_1 + 5]) << 0x8 | uint(c2da_mem[pic_1 + 6]) << 0x10 | uint(c2da_mem[pic_1 + 7]) << 0x18)) {
            u_1 = 0
            while (u_1 < int(uint(c2da_mem[pic_1]) | uint(c2da_mem[pic_1 + 1]) << 0x8 | uint(c2da_mem[pic_1 + 2]) << 0x10 | uint(c2da_mem[pic_1 + 3]) << 0x18)) {
                tbyte_0 = uint8(c2da_mem[source_3 + u_1])
                if (int(tbyte_0) != 255) {
                    let c2da_fresh17 : uint8 = c2da_mem[translation + int(tbyte_0)]
                    c2da_mem[dest_3 + u_1] = c2da_fresh17
                }
                u_1++
            }
            dest_3 += int(vid.rowbytes)
            source_3 += int(uint(c2da_mem[pic_1]) | uint(c2da_mem[pic_1 + 1]) << 0x8 | uint(c2da_mem[pic_1 + 2]) << 0x10 | uint(c2da_mem[pic_1 + 3]) << 0x18)
            v_1++
        }
    } else {
        v_1 = 0
        while (v_1 < int(uint(c2da_mem[pic_1 + 4]) | uint(c2da_mem[pic_1 + 5]) << 0x8 | uint(c2da_mem[pic_1 + 6]) << 0x10 | uint(c2da_mem[pic_1 + 7]) << 0x18)) {
            u_1 = 0
            while (u_1 < int(uint(c2da_mem[pic_1]) | uint(c2da_mem[pic_1 + 1]) << 0x8 | uint(c2da_mem[pic_1 + 2]) << 0x10 | uint(c2da_mem[pic_1 + 3]) << 0x18)) {
                tbyte_0 = uint8(c2da_mem[source_3 + u_1])
                if (int(tbyte_0) != 255) {
                    let c2da_fresh18 : uint8 = c2da_mem[translation + int(tbyte_0)]
                    c2da_mem[dest_3 + u_1] = c2da_fresh18
                }
                tbyte_0 = uint8(c2da_mem[source_3 + (u_1 + 1)])
                if (int(tbyte_0) != 255) {
                    let c2da_fresh19 : uint8 = c2da_mem[translation + int(tbyte_0)]
                    c2da_mem[dest_3 + (u_1 + 1)] = c2da_fresh19
                }
                tbyte_0 = uint8(c2da_mem[source_3 + (u_1 + 2)])
                if (int(tbyte_0) != 255) {
                    let c2da_fresh20 : uint8 = c2da_mem[translation + int(tbyte_0)]
                    c2da_mem[dest_3 + (u_1 + 2)] = c2da_fresh20
                }
                tbyte_0 = uint8(c2da_mem[source_3 + (u_1 + 3)])
                if (int(tbyte_0) != 255) {
                    let c2da_fresh21 : uint8 = c2da_mem[translation + int(tbyte_0)]
                    c2da_mem[dest_3 + (u_1 + 3)] = c2da_fresh21
                }
                tbyte_0 = uint8(c2da_mem[source_3 + (u_1 + 4)])
                if (int(tbyte_0) != 255) {
                    let c2da_fresh22 : uint8 = c2da_mem[translation + int(tbyte_0)]
                    c2da_mem[dest_3 + (u_1 + 4)] = c2da_fresh22
                }
                tbyte_0 = uint8(c2da_mem[source_3 + (u_1 + 5)])
                if (int(tbyte_0) != 255) {
                    let c2da_fresh23 : uint8 = c2da_mem[translation + int(tbyte_0)]
                    c2da_mem[dest_3 + (u_1 + 5)] = c2da_fresh23
                }
                tbyte_0 = uint8(c2da_mem[source_3 + (u_1 + 6)])
                if (int(tbyte_0) != 255) {
                    let c2da_fresh24 : uint8 = c2da_mem[translation + int(tbyte_0)]
                    c2da_mem[dest_3 + (u_1 + 6)] = c2da_fresh24
                }
                tbyte_0 = uint8(c2da_mem[source_3 + (u_1 + 7)])
                if (int(tbyte_0) != 255) {
                    let c2da_fresh25 : uint8 = c2da_mem[translation + int(tbyte_0)]
                    c2da_mem[dest_3 + (u_1 + 7)] = c2da_fresh25
                }
                u_1 += 8
            }
            dest_3 += int(vid.rowbytes)
            source_3 += int(uint(c2da_mem[pic_1]) | uint(c2da_mem[pic_1 + 1]) << 0x8 | uint(c2da_mem[pic_1 + 2]) << 0x10 | uint(c2da_mem[pic_1 + 3]) << 0x18)
            v_1++
        }
    }
    return
}
[export, sideeffects]
def Draw_ConsoleBackground(var lines : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    Draw_ConsoleBackground_c2da_frame(lines, c2da_lin_enter(112))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Draw_CharToConback(var num_1 : int; var dest_5 : int) {
    var source_4 : int
    var drawline_1 : int
    source_4 = draw_chars + (num_1 >> 4 << 10) + ((num_1 & 15) << 3)
    drawline_1 = 8
    while (true) {
        let c2da_postinc_1 : int = drawline_1
        drawline_1--
        if (c2da_postinc_1 == 0) {
            break
        }
        for (x_4 in range(0, 8)) {
            if (c2da_mem[source_4 + x_4] != 0x0) {
                let c2da_fresh35 : uint8 = uint8(96 + int(c2da_mem[source_4 + x_4]))
                c2da_mem[dest_5 + x_4] = c2da_fresh35
            }
        }
        source_4 += 128
        dest_5 += 320
    }
    return
}
[export, sideeffects]
def Draw_CachePic(var path : int) : int {
    var pic_2 : int
    var i_0 : int
    var dat : int
    pic_2 = 216640
    i_0 = 0
    while (i_0 < menu_numcachepics) {
        if (c2da_lin_strcmp(path, pic_2) == 0) {
            break
        }
        pic_2 += 72
        i_0++
    }
    if (i_0 == menu_numcachepics) {
        if (menu_numcachepics == 128) {
            Sys_Error(715542, [])
        }
        menu_numcachepics++
        c2da_lin_strcpy(pic_2, path)
    }
    dat = Cache_Check(pic_2 + 64)
    if (dat != 0) {
        return dat
    }
    COM_LoadCacheFile(path, pic_2 + 64)
    dat = int(uint(c2da_mem[pic_2 + 64]) | uint(c2da_mem[pic_2 + 65]) << 0x8 | uint(c2da_mem[pic_2 + 66]) << 0x10 | uint(c2da_mem[pic_2 + 67]) << 0x18)
    if (dat == 0) {
        Sys_Error(715579, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(path))])
    }
    SwapPic(dat)
    return dat
}
var menu_numcachepics : int = default<int>

[export, sideeffects]
def Draw_BeginDisc() {
    D_BeginDirectRect(int(vid.width - 24u), 0, draw_disc + 8, 24, 24)
    return
}
[export, sideeffects]
def Draw_EndDisc() {
    D_EndDirectRect(int(vid.width - 24u), 0, 24, 24)
    return
}
[export, sideeffects]
def Draw_TileClear(var x_5 : int; var y_4 : int; var w : int; var h : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    Draw_TileClear_c2da_frame(x_5, y_4, w, h, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_DrawRect(var prect : int; var rowbytes : int; var psrc_0 : int; var transparent : int) {
    var t : uint8
    var i_1 : int
    var j : int
    var srcdelta : int
    var destdelta : int
    var pdest : int = vid.buffer + int(uint(int(uint(c2da_mem[prect + 4]) | uint(c2da_mem[prect + 5]) << 0x8 | uint(c2da_mem[prect + 6]) << 0x10 | uint(c2da_mem[prect + 7]) << 0x18)) * vid.rowbytes) + int(uint(c2da_mem[prect]) | uint(c2da_mem[prect + 1]) << 0x8 | uint(c2da_mem[prect + 2]) << 0x10 | uint(c2da_mem[prect + 3]) << 0x18)
    let c2da_fresh56 : int = int(uint(c2da_mem[prect + 8]) | uint(c2da_mem[prect + 9]) << 0x8 | uint(c2da_mem[prect + 10]) << 0x10 | uint(c2da_mem[prect + 11]) << 0x18)
    srcdelta = rowbytes - c2da_fresh56
    destdelta = int(vid.rowbytes - uint(c2da_fresh56))
    if (transparent != 0) {
        i_1 = 0
        while (i_1 < int(uint(c2da_mem[prect + 12]) | uint(c2da_mem[prect + 13]) << 0x8 | uint(c2da_mem[prect + 14]) << 0x10 | uint(c2da_mem[prect + 15]) << 0x18)) {
            j = 0
            while (j < int(uint(c2da_mem[prect + 8]) | uint(c2da_mem[prect + 9]) << 0x8 | uint(c2da_mem[prect + 10]) << 0x10 | uint(c2da_mem[prect + 11]) << 0x18)) {
                t = uint8(c2da_mem[psrc_0])
                if (int(t) != 255) {
                    c2da_mem[pdest] = t
                }
                psrc_0++
                pdest++
                j++
            }
            psrc_0 += srcdelta
            pdest += destdelta
            i_1++
        }
    } else {
        i_1 = 0
        while (i_1 < int(uint(c2da_mem[prect + 12]) | uint(c2da_mem[prect + 13]) << 0x8 | uint(c2da_mem[prect + 14]) << 0x10 | uint(c2da_mem[prect + 15]) << 0x18)) {
            c2da_lin_memcpy(pdest, psrc_0, uint64(int(uint(c2da_mem[prect + 8]) | uint(c2da_mem[prect + 9]) << 0x8 | uint(c2da_mem[prect + 10]) << 0x10 | uint(c2da_mem[prect + 11]) << 0x18)))
            psrc_0 += rowbytes
            pdest += int(vid.rowbytes)
            i_1++
        }
    }
    return
}
[export, sideeffects]
def Draw_Fill(var x_6 : int; var y_5 : int; var w_0 : int; var h_0 : int; var c : int) {
    var dest_6 : int
    var pusdest_4 : int
    var uc : uint
    var v_3 : int
    dest_6 = vid.buffer + int(uint(y_5) * vid.rowbytes) + x_6
    v_3 = 0
    while (v_3 < h_0) {
        for (u_2 in range(0, w_0)) {
            let c2da_fresh57 : uint8 = uint8(c)
            c2da_mem[dest_6 + u_2] = c2da_fresh57
        }
        v_3++
        dest_6 += int(vid.rowbytes)
    }
    return
}
[export, sideeffects]
def Draw_FadeScreen() {
    var x_7 : int
    var y_6 : int
    var pbuf : int
    var t_0 : int
    S_ExtraUpdate()
    y_6 = 0
    while (uint(y_6) < vid.height) {
        pbuf = vid.buffer + int(vid.rowbytes * uint(y_6))
        t_0 = (y_6 & 1) << 1
        x_7 = 0
        while (uint(x_7) < vid.width) {
            if ((x_7 & 3) != t_0) {
                let c2da_fresh58 : uint8 = 0u8
                c2da_mem[pbuf + x_7] = c2da_fresh58
            }
            x_7++
        }
        y_6++
    }
    S_ExtraUpdate()
    return
}
[export, sideeffects]
def Draw_String(var x_8 : int; var y_7 : int; var str : int) {
    while (int8(c2da_mem[str]) != 0) {
        Draw_Character(x_8, y_7, int(int8(c2da_mem[str])))
        str++
        x_8 += 8
    }
    return
}
[export, sideeffects]
def Draw_PicFromWad(var name : int) : int {
    return W_GetLumpName(name)
}
[sideeffects]
def private Draw_ConsoleBackground_c2da_frame(var lines : int; c2da_fp : int) {
    var x_3 : int
    var y_3 : int
    var src : int
    var dest_4 : int
    var pusdest_3 : int
    var f : int
    var fstep : int
    var conback : int = Draw_CachePic(715520)
    dest_4 = conback + 8 + 320 - 43 + 320 * 186
    c2da_lin_snprintf(c2da_fp, 2147483647ul, 715536, [C2daVaArg(tag = 2, i64 = 0, f64 = 1.09lf, raw = 0x0)])
    x_3 = 0
    while (uint64(x_3) < c2da_lin_strlen(c2da_fp)) {
        Draw_CharToConback(int(int8(c2da_mem[c2da_fp + x_3])), dest_4 + (x_3 << 3))
        x_3++
    }
    dest_4 = vid.conbuffer
    y_3 = 0
    while (y_3 < lines) {
        src = conback + 8 + int((vid.conheight - uint(lines) + uint(y_3)) * 200u / vid.conheight) * 320
        if (vid.conwidth == 320u) {
            c2da_lin_memcpy(dest_4, src, uint64(vid.conwidth))
        } else {
            f = 0
            fstep = int(uint(320 * 65536) / vid.conwidth)
            x_3 = 0
            while (uint(x_3) < vid.conwidth) {
                let c2da_fresh27 : int = src + (f >> 16)
                let c2da_fresh28 : uint8 = c2da_mem[c2da_fresh27]
                c2da_mem[dest_4 + x_3] = c2da_fresh28
                f += fstep
                let c2da_fresh29 : int = src + (f >> 16)
                let c2da_fresh30 : uint8 = c2da_mem[c2da_fresh29]
                c2da_mem[dest_4 + (x_3 + 1)] = c2da_fresh30
                f += fstep
                let c2da_fresh31 : int = src + (f >> 16)
                let c2da_fresh32 : uint8 = c2da_mem[c2da_fresh31]
                c2da_mem[dest_4 + (x_3 + 2)] = c2da_fresh32
                f += fstep
                let c2da_fresh33 : int = src + (f >> 16)
                let c2da_fresh34 : uint8 = c2da_mem[c2da_fresh33]
                c2da_mem[dest_4 + (x_3 + 3)] = c2da_fresh34
                f += fstep
                x_3 += 4
            }
        }
        y_3++
        dest_4 += int(vid.conrowbytes)
    }
    return
}
[sideeffects]
def private Draw_TileClear_c2da_frame(var x_5 : int; var y_4 : int; var w : int; var h : int; c2da_fp : int) {
    var width : int
    var height : int
    var tileoffsetx : int
    var tileoffsety : int
    var psrc : int
    r_rectdesc.rect.x = int(x_5)  // nolint:PERF020
    r_rectdesc.rect.y = int(y_4)  // nolint:PERF020
    r_rectdesc.rect.width = int(w)  // nolint:PERF020
    r_rectdesc.rect.height = int(h)  // nolint:PERF020
    let c2da_fresh36 : int = r_rectdesc.rect.y
    let c2da_fresh37 : uint = uint(c2da_fresh36)
    c2da_mem[c2da_fp + 4] = uint8(c2da_fresh37)
    c2da_mem[c2da_fp + 5] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[c2da_fp + 6] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[c2da_fp + 7] = uint8(c2da_fresh37 >> 0x18)
    height = r_rectdesc.rect.height
    tileoffsety = int(uint(c2da_mem[c2da_fp + 4]) | uint(c2da_mem[c2da_fp + 5]) << 0x8 | uint(c2da_mem[c2da_fp + 6]) << 0x10 | uint(c2da_mem[c2da_fp + 7]) << 0x18) % r_rectdesc.height
    while (height > 0) {
        let c2da_fresh38 : int = r_rectdesc.rect.x
        let c2da_fresh39 : uint = uint(c2da_fresh38)
        c2da_mem[c2da_fp] = uint8(c2da_fresh39)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh39 >> 0x8)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh39 >> 0x10)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh39 >> 0x18)
        width = r_rectdesc.rect.width
        if (tileoffsety != 0) {
            let c2da_fresh40 : int = r_rectdesc.height - tileoffsety
            let c2da_fresh41 : uint = uint(c2da_fresh40)
            c2da_mem[c2da_fp + 12] = uint8(c2da_fresh41)
            c2da_mem[c2da_fp + 13] = uint8(c2da_fresh41 >> 0x8)
            c2da_mem[c2da_fp + 14] = uint8(c2da_fresh41 >> 0x10)
            c2da_mem[c2da_fp + 15] = uint8(c2da_fresh41 >> 0x18)
        } else {
            let c2da_fresh42 : int = r_rectdesc.height
            let c2da_fresh43 : uint = uint(c2da_fresh42)
            c2da_mem[c2da_fp + 12] = uint8(c2da_fresh43)
            c2da_mem[c2da_fp + 13] = uint8(c2da_fresh43 >> 0x8)
            c2da_mem[c2da_fp + 14] = uint8(c2da_fresh43 >> 0x10)
            c2da_mem[c2da_fp + 15] = uint8(c2da_fresh43 >> 0x18)
        }
        if (int(uint(c2da_mem[c2da_fp + 12]) | uint(c2da_mem[c2da_fp + 13]) << 0x8 | uint(c2da_mem[c2da_fp + 14]) << 0x10 | uint(c2da_mem[c2da_fp + 15]) << 0x18) > height) {
            let c2da_fresh44 : uint = uint(height)
            c2da_mem[c2da_fp + 12] = uint8(c2da_fresh44)
            c2da_mem[c2da_fp + 13] = uint8(c2da_fresh44 >> 0x8)
            c2da_mem[c2da_fp + 14] = uint8(c2da_fresh44 >> 0x10)
            c2da_mem[c2da_fp + 15] = uint8(c2da_fresh44 >> 0x18)
        }
        tileoffsetx = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) % r_rectdesc.width
        while (width > 0) {
            if (tileoffsetx != 0) {
                let c2da_fresh45 : int = r_rectdesc.width - tileoffsetx
                let c2da_fresh46 : uint = uint(c2da_fresh45)
                c2da_mem[c2da_fp + 8] = uint8(c2da_fresh46)
                c2da_mem[c2da_fp + 9] = uint8(c2da_fresh46 >> 0x8)
                c2da_mem[c2da_fp + 10] = uint8(c2da_fresh46 >> 0x10)
                c2da_mem[c2da_fp + 11] = uint8(c2da_fresh46 >> 0x18)
            } else {
                let c2da_fresh47 : int = r_rectdesc.width
                let c2da_fresh48 : uint = uint(c2da_fresh47)
                c2da_mem[c2da_fp + 8] = uint8(c2da_fresh48)
                c2da_mem[c2da_fp + 9] = uint8(c2da_fresh48 >> 0x8)
                c2da_mem[c2da_fp + 10] = uint8(c2da_fresh48 >> 0x10)
                c2da_mem[c2da_fp + 11] = uint8(c2da_fresh48 >> 0x18)
            }
            if (int(uint(c2da_mem[c2da_fp + 8]) | uint(c2da_mem[c2da_fp + 9]) << 0x8 | uint(c2da_mem[c2da_fp + 10]) << 0x10 | uint(c2da_mem[c2da_fp + 11]) << 0x18) > width) {
                let c2da_fresh49 : uint = uint(width)
                c2da_mem[c2da_fp + 8] = uint8(c2da_fresh49)
                c2da_mem[c2da_fp + 9] = uint8(c2da_fresh49 >> 0x8)
                c2da_mem[c2da_fp + 10] = uint8(c2da_fresh49 >> 0x10)
                c2da_mem[c2da_fp + 11] = uint8(c2da_fresh49 >> 0x18)
            }
            psrc = r_rectdesc.ptexbytes + tileoffsety * r_rectdesc.rowbytes + tileoffsetx
            R_DrawRect(c2da_fp, r_rectdesc.rowbytes, psrc, 0)
            let c2da_fresh55 : int = int(uint(c2da_mem[c2da_fp + 8]) | uint(c2da_mem[c2da_fp + 9]) << 0x8 | uint(c2da_mem[c2da_fp + 10]) << 0x10 | uint(c2da_mem[c2da_fp + 11]) << 0x18)
            let c2da_fresh50 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) + c2da_fresh55
            let c2da_fresh51 : uint = uint(c2da_fresh50)
            c2da_mem[c2da_fp] = uint8(c2da_fresh51)
            c2da_mem[c2da_fp + 1] = uint8(c2da_fresh51 >> 0x8)
            c2da_mem[c2da_fp + 2] = uint8(c2da_fresh51 >> 0x10)
            c2da_mem[c2da_fp + 3] = uint8(c2da_fresh51 >> 0x18)
            width -= c2da_fresh55
            tileoffsetx = 0
        }
        let c2da_fresh54 : int = int(uint(c2da_mem[c2da_fp + 12]) | uint(c2da_mem[c2da_fp + 13]) << 0x8 | uint(c2da_mem[c2da_fp + 14]) << 0x10 | uint(c2da_mem[c2da_fp + 15]) << 0x18)
        let c2da_fresh52 : int = int(uint(c2da_mem[c2da_fp + 4]) | uint(c2da_mem[c2da_fp + 5]) << 0x8 | uint(c2da_mem[c2da_fp + 6]) << 0x10 | uint(c2da_mem[c2da_fp + 7]) << 0x18) + c2da_fresh54
        let c2da_fresh53 : uint = uint(c2da_fresh52)
        c2da_mem[c2da_fp + 4] = uint8(c2da_fresh53)
        c2da_mem[c2da_fp + 5] = uint8(c2da_fresh53 >> 0x8)
        c2da_mem[c2da_fp + 6] = uint8(c2da_fresh53 >> 0x10)
        c2da_mem[c2da_fp + 7] = uint8(c2da_fresh53 >> 0x18)
        height -= c2da_fresh54
        tileoffsety = 0
    }
    return
}

// This unit's static data, at heap offset 715440.
let private c2da_lin_static_draw_seg = fixed_array<int>(715440, 171)
let private c2da_lin_static_draw = fixed_array<uint64>(0x73726168636e6f63ul, 0x6162006373696400ul, 0x4400656c69746b63ul, 0x3a6369505f776172ul, 0x6f6f632064616220ul, 0x736574616e696472ul, 0x72545f7761724400ul, 0x203a636950736e61ul, 0x726f6f6320646162ul, 0x736574616e6964ul, 0x626e6f632f786667ul, 0x706d6c2e6b6361ul, 0x656d0066322e3425ul, 0x61636d756e5f756eul, 0x2073636970656863ul, 0x435f58414d203d3dul, 0x49505f4445484341ul, 0x5f77617244005343ul, 0x6369506568636143ul, 0x64656c696166203aul, 0x64616f6c206f7420ul, 0x732520ul)

[init]
def private c2da_lin_init_static_draw() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_draw_seg[s * 2]
        for (k in range(c2da_lin_static_draw_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_draw[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
