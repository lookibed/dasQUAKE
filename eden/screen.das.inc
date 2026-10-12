var private SCR_UpdateScreen__oldscr_viewsize : float = 0.0

var private SCR_UpdateScreen__oldlcd_x : float = 0.0

var private SCR_DrawTurtle__count : int = 0

[export, sideeffects]
def SCR_Init() {
    Cvar_RegisterVariable(461104)
    Cvar_RegisterVariable(461152)
    Cvar_RegisterVariable(461200)
    Cvar_RegisterVariable(461248)
    Cvar_RegisterVariable(461296)
    Cvar_RegisterVariable(461344)
    Cvar_RegisterVariable(461392)
    Cvar_RegisterVariable(461440)
    Cmd_AddCommand(735880, 217)
    Cmd_AddCommand(735891, 218)
    Cmd_AddCommand(735898, 219)
    scr_ram = Draw_PicFromWad(735907)
    scr_net = Draw_PicFromWad(735911)
    scr_turtle = Draw_PicFromWad(735915)
    scr_initialized = 1u
    return
}
var scr_initialized : uint = default<uint>

var scr_turtle : int = default<int>

var scr_net : int = default<int>

var scr_ram : int = default<int>

[export, sideeffects]
def SCR_SizeDown_f() {
    Cvar_SetValue(735783, uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18) - 10.0)
    vid.recalc_refdef = 1
    return
}
[export, sideeffects]
def SCR_SizeUp_f() {
    Cvar_SetValue(735783, uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18) + 10.0)
    vid.recalc_refdef = 1
    return
}
[export, sideeffects]
def SCR_ScreenShot_f() {
    let c2da_saved_sp : int = c2da_lin_sp
    SCR_ScreenShot_f_c2da_frame(c2da_lin_enter(208))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def WritePCXfile(var filename : int; var data : int; var width : int; var height : int; var rowbytes : int; var palette : int) {
    var i_0 : int
    var pcx : int
    var pack : int
    pcx = Hunk_TempAlloc(width * height * 2 + 1000)
    if (pcx == 0) {
        Con_Printf(735996, [])
        return
    }
    let c2da_fresh2 : int8 = int8(10)
    c2da_mem[pcx] = uint8(c2da_fresh2)
    let c2da_fresh3 : int8 = int8(5)
    c2da_mem[pcx + 1] = uint8(c2da_fresh3)
    let c2da_fresh4 : int8 = int8(1)
    c2da_mem[pcx + 2] = uint8(c2da_fresh4)
    let c2da_fresh5 : int8 = int8(8)
    c2da_mem[pcx + 3] = uint8(c2da_fresh5)
    let c2da_fresh6 : uint16 = uint16(0)
    let c2da_fresh7 : uint = uint(c2da_fresh6)
    c2da_mem[pcx + 4] = uint8(c2da_fresh7)
    c2da_mem[pcx + 5] = uint8(c2da_fresh7 >> 0x8)
    let c2da_fresh8 : uint16 = uint16(0)
    let c2da_fresh9 : uint = uint(c2da_fresh8)
    c2da_mem[pcx + 6] = uint8(c2da_fresh9)
    c2da_mem[pcx + 7] = uint8(c2da_fresh9 >> 0x8)
    let c2da_fresh10 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(width - 1)))
    let c2da_fresh11 : uint = uint(c2da_fresh10)
    c2da_mem[pcx + 8] = uint8(c2da_fresh11)
    c2da_mem[pcx + 9] = uint8(c2da_fresh11 >> 0x8)
    let c2da_fresh12 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(height - 1)))
    let c2da_fresh13 : uint = uint(c2da_fresh12)
    c2da_mem[pcx + 10] = uint8(c2da_fresh13)
    c2da_mem[pcx + 11] = uint8(c2da_fresh13 >> 0x8)
    let c2da_fresh14 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(width)))
    let c2da_fresh15 : uint = uint(c2da_fresh14)
    c2da_mem[pcx + 12] = uint8(c2da_fresh15)
    c2da_mem[pcx + 13] = uint8(c2da_fresh15 >> 0x8)
    let c2da_fresh16 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(height)))
    let c2da_fresh17 : uint = uint(c2da_fresh16)
    c2da_mem[pcx + 14] = uint8(c2da_fresh17)
    c2da_mem[pcx + 15] = uint8(c2da_fresh17 >> 0x8)
    Q_memset(pcx + 16, 0, 48)
    let c2da_fresh18 : int8 = int8(1)
    c2da_mem[pcx + 65] = uint8(c2da_fresh18)
    let c2da_fresh19 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(width)))
    let c2da_fresh20 : uint = uint(c2da_fresh19)
    c2da_mem[pcx + 66] = uint8(c2da_fresh20)
    c2da_mem[pcx + 67] = uint8(c2da_fresh20 >> 0x8)
    let c2da_fresh21 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(2)))
    let c2da_fresh22 : uint = uint(c2da_fresh21)
    c2da_mem[pcx + 68] = uint8(c2da_fresh22)
    c2da_mem[pcx + 69] = uint8(c2da_fresh22 >> 0x8)
    Q_memset(pcx + 70, 0, 58)
    pack = pcx + 128
    i_0 = 0
    while (i_0 < height) {
        for (j in range(0, width)) {
            if ((int(c2da_mem[data]) & 192) != 192) {
                let c2da_fresh23 : int = pack
                pack++
                let c2da_fresh24 : int = data
                data++
                let c2da_fresh25 : uint8 = c2da_mem[c2da_fresh24]
                c2da_mem[c2da_fresh23] = c2da_fresh25
            } else {
                let c2da_fresh26 : int = pack
                pack++
                let c2da_fresh27 : uint8 = 0xc1u8
                c2da_mem[c2da_fresh26] = c2da_fresh27
                let c2da_fresh28 : int = pack
                pack++
                let c2da_fresh29 : int = data
                data++
                let c2da_fresh30 : uint8 = c2da_mem[c2da_fresh29]
                c2da_mem[c2da_fresh28] = c2da_fresh30
            }
        }
        data += rowbytes - width
        i_0++
    }
    let c2da_fresh31 : int = pack
    pack++
    let c2da_fresh32 : uint8 = 0xcu8
    c2da_mem[c2da_fresh31] = c2da_fresh32
    i_0 = 0
    for (c2da_i_0 in range(i_0, 768)) {
        let c2da_fresh33 : int = pack
        pack++
        let c2da_fresh34 : int = palette
        palette++
        let c2da_fresh35 : uint8 = c2da_mem[c2da_fresh34]
        c2da_mem[c2da_fresh33] = c2da_fresh35
    }
    COM_WriteFile(filename, pcx, pack - pcx)
    return
}
[export, sideeffects]
def SCR_UpdateScreen() {
    let c2da_saved_sp : int = c2da_lin_sp
    SCR_UpdateScreen_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
var scr_copytop : int = default<int>

var scr_copyeverything : int = default<int>

var pconupdate : int = default<int>

[export, sideeffects]
def SCR_DrawConsole() {
    if (scr_con_current != 0.0) {
        scr_copyeverything = 1
        Con_DrawConsole(int(scr_con_current), 1u)
        clearconsole = 0
    } elif (uint(key_dest) == 0u || uint(key_dest) == 2u) {
        Con_DrawNotify()
    }
    return
}
var clearconsole : int = default<int>

var scr_con_current : float = default<float>

[export, sideeffects]
def SCR_CheckDrawCenterString() {
    scr_copytop = 1
    if (scr_center_lines > scr_erase_lines) {
        scr_erase_lines = int(scr_center_lines)  // nolint:PERF020
    }
    scr_centertime_off = float(double(scr_centertime_off) - host_frametime)
    if (scr_centertime_off <= 0.0 && int(uint(c2da_mem[756]) | uint(c2da_mem[757]) << 0x8 | uint(c2da_mem[758]) << 0x10 | uint(c2da_mem[759]) << 0x18) == 0) {
        return
    }
    if (uint(key_dest) != 0u) {
        return
    }
    SCR_DrawCenterString()
    return
}
[export, sideeffects]
def SCR_DrawCenterString() {
    var start : int
    var l : int
    var j_0 : int
    var x : int
    var y : int
    var remaining : int
    if (int(uint(c2da_mem[756]) | uint(c2da_mem[757]) << 0x8 | uint(c2da_mem[758]) << 0x10 | uint(c2da_mem[759]) << 0x18) != 0) {
        remaining = int(double(uint_bits_to_float(uint(c2da_mem[461464]) | uint(c2da_mem[461465]) << 0x8 | uint(c2da_mem[461466]) << 0x10 | uint(c2da_mem[461467]) << 0x18)) * (uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - double(scr_centertime_start)))
    } else {
        remaining = 9999
    }
    scr_erase_center = 0
    start = 461488
    if (scr_center_lines <= 4) {
        y = int(double(vid.height) * 0.35lf)
    } else {
        y = 48
    }
    while (true) {
        l = 0
        while (l < 40) {
            if (int(int8(c2da_mem[start + l])) == 10 || int8(c2da_mem[start + l]) == 0) {
                break
            }
            l++
        }
        x = int((vid.width - uint(l * 8)) / 2u)
        j_0 = 0
        while (j_0 < l) {
            Draw_Character(x, y, int(int8(c2da_mem[start + j_0])))
            let c2da_postinc_0 : int = remaining
            remaining--
            if (c2da_postinc_0 == 0) {
                return
            }
            j_0++
            x += 8
        }
        y += 8
        while (int(int8(c2da_mem[start])) != 0 && int(int8(c2da_mem[start])) != 10) {
            start++
        }
        if (int8(c2da_mem[start]) == 0) {
            break
        }
        start++
    }
    return
}
var scr_center_lines : int = default<int>

var scr_erase_center : int = default<int>

var scr_centertime_start : float = default<float>

var scr_centertime_off : float = default<float>

var scr_erase_lines : int = default<int>

[export, sideeffects]
def SCR_DrawPause() {
    var pic : int
    if (uint_bits_to_float(uint(c2da_mem[461368]) | uint(c2da_mem[461369]) << 0x8 | uint(c2da_mem[461370]) << 0x10 | uint(c2da_mem[461371]) << 0x18) == 0.0) {
        return
    }
    if ((uint(c2da_mem[744]) | uint(c2da_mem[745]) << 0x8 | uint(c2da_mem[746]) << 0x10 | uint(c2da_mem[747]) << 0x18) == 0u) {
        return
    }
    pic = Draw_CachePic(736047)
    Draw_Pic(int((vid.width - uint(int(uint(c2da_mem[pic]) | uint(c2da_mem[pic + 1]) << 0x8 | uint(c2da_mem[pic + 2]) << 0x10 | uint(c2da_mem[pic + 3]) << 0x18))) / 2u), int((vid.height - 48u - uint(int(uint(c2da_mem[pic + 4]) | uint(c2da_mem[pic + 5]) << 0x8 | uint(c2da_mem[pic + 6]) << 0x10 | uint(c2da_mem[pic + 7]) << 0x18))) / 2u), pic)
    return
}
[export, sideeffects]
def SCR_DrawTurtle() {
    if (uint_bits_to_float(uint(c2da_mem[461320]) | uint(c2da_mem[461321]) << 0x8 | uint(c2da_mem[461322]) << 0x10 | uint(c2da_mem[461323]) << 0x18) == 0.0) {
        return
    }
    if (host_frametime < 0.1lf) {
        SCR_DrawTurtle__count = 0
        return
    }
    SCR_DrawTurtle__count++
    if (SCR_DrawTurtle__count < 3) {
        return
    }
    Draw_Pic(int(uint(c2da_mem[462512]) | uint(c2da_mem[462513]) << 0x8 | uint(c2da_mem[462514]) << 0x10 | uint(c2da_mem[462515]) << 0x18), int(uint(c2da_mem[462516]) | uint(c2da_mem[462517]) << 0x8 | uint(c2da_mem[462518]) << 0x10 | uint(c2da_mem[462519]) << 0x18), scr_turtle)
    return
}
[export, sideeffects]
def SCR_DrawNet() {
    if (realtime - double(uint_bits_to_float(uint(c2da_mem[800]) | uint(c2da_mem[801]) << 0x8 | uint(c2da_mem[802]) << 0x10 | uint(c2da_mem[803]) << 0x18)) < 0.3lf) {
        return
    }
    if ((uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) != 0u) {
        return
    }
    Draw_Pic(int(uint(c2da_mem[462512]) | uint(c2da_mem[462513]) << 0x8 | uint(c2da_mem[462514]) << 0x10 | uint(c2da_mem[462515]) << 0x18) + 64, int(uint(c2da_mem[462516]) | uint(c2da_mem[462517]) << 0x8 | uint(c2da_mem[462518]) << 0x10 | uint(c2da_mem[462519]) << 0x18), scr_net)
    return
}
[export, sideeffects]
def SCR_DrawRam() {
    if (uint_bits_to_float(uint(c2da_mem[461272]) | uint(c2da_mem[461273]) << 0x8 | uint(c2da_mem[461274]) << 0x10 | uint(c2da_mem[461275]) << 0x18) == 0.0) {
        return
    }
    if (uint(r_cache_thrash) == 0u) {
        return
    }
    Draw_Pic(int(uint(c2da_mem[462512]) | uint(c2da_mem[462513]) << 0x8 | uint(c2da_mem[462514]) << 0x10 | uint(c2da_mem[462515]) << 0x18) + 32, int(uint(c2da_mem[462516]) | uint(c2da_mem[462517]) << 0x8 | uint(c2da_mem[462518]) << 0x10 | uint(c2da_mem[462519]) << 0x18), scr_ram)
    return
}
[export, sideeffects]
def SCR_DrawLoading() {
    var pic_0 : int
    if (scr_drawloading == 0u) {
        return
    }
    pic_0 = Draw_CachePic(736061)
    Draw_Pic(int((vid.width - uint(int(uint(c2da_mem[pic_0]) | uint(c2da_mem[pic_0 + 1]) << 0x8 | uint(c2da_mem[pic_0 + 2]) << 0x10 | uint(c2da_mem[pic_0 + 3]) << 0x18))) / 2u), int((vid.height - 48u - uint(int(uint(c2da_mem[pic_0 + 4]) | uint(c2da_mem[pic_0 + 5]) << 0x8 | uint(c2da_mem[pic_0 + 6]) << 0x10 | uint(c2da_mem[pic_0 + 7]) << 0x18))) / 2u), pic_0)
    return
}
var scr_drawloading : uint = default<uint>

[export, sideeffects]
def SCR_DrawNotifyString() {
    var start_0 : int
    var l_0 : int
    var j_1 : int
    var x_0 : int
    var y_0 : int
    start_0 = scr_notifystring
    y_0 = int(double(vid.height) * 0.35lf)
    while (true) {
        l_0 = 0
        while (l_0 < 40) {
            if (int(int8(c2da_mem[start_0 + l_0])) == 10 || int8(c2da_mem[start_0 + l_0]) == 0) {
                break
            }
            l_0++
        }
        x_0 = int((vid.width - uint(l_0 * 8)) / 2u)
        j_1 = 0
        while (j_1 < l_0) {
            Draw_Character(x_0, y_0, int(int8(c2da_mem[start_0 + j_1])))
            j_1++
            x_0 += 8
        }
        y_0 += 8
        while (int(int8(c2da_mem[start_0])) != 0 && int(int8(c2da_mem[start_0])) != 10) {
            start_0++
        }
        if (int8(c2da_mem[start_0]) == 0) {
            break
        }
        start_0++
    }
    return
}
var scr_notifystring : int = default<int>

var scr_drawdialog : uint = default<uint>

[export, sideeffects]
def SCR_EraseCenterString() {
    var y_1 : int
    let c2da_postinc_1 : int = scr_erase_center
    scr_erase_center++
    if (c2da_postinc_1 > vid.numpages) {
        scr_erase_lines = 0
        return
    }
    if (scr_center_lines <= 4) {
        y_1 = int(double(vid.height) * 0.35lf)
    } else {
        y_1 = 48
    }
    scr_copytop = 1
    Draw_TileClear(0, y_1, int(vid.width), 8 * scr_erase_lines)
    return
}
[export, sideeffects]
def SCR_SetUpToDrawConsole() {
    Con_CheckResize()
    if (scr_drawloading != 0u) {
        return
    }
    con_forcedup = uint(int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) == 0 || int(uint(c2da_mem[7804]) | uint(c2da_mem[7805]) << 0x8 | uint(c2da_mem[7806]) << 0x10 | uint(c2da_mem[7807]) << 0x18) != 4 ? 1 : 0)
    if (uint(con_forcedup) != 0u) {
        scr_conlines = float(vid.height)
        scr_con_current = float(scr_conlines)  // nolint:PERF020
    } elif (uint(key_dest) == 1u) {
        scr_conlines = float(vid.height / 2u)
    } else {
        scr_conlines = 0.0
    }
    if (scr_conlines < scr_con_current) {
        scr_con_current = float(double(scr_con_current) - double(uint_bits_to_float(uint(c2da_mem[461224]) | uint(c2da_mem[461225]) << 0x8 | uint(c2da_mem[461226]) << 0x10 | uint(c2da_mem[461227]) << 0x18)) * host_frametime)
        if (scr_conlines > scr_con_current) {
            scr_con_current = float(scr_conlines)  // nolint:PERF020
        }
    } elif (scr_conlines > scr_con_current) {
        scr_con_current = float(double(scr_con_current) + double(uint_bits_to_float(uint(c2da_mem[461224]) | uint(c2da_mem[461225]) << 0x8 | uint(c2da_mem[461226]) << 0x10 | uint(c2da_mem[461227]) << 0x18)) * host_frametime)
        if (scr_conlines < scr_con_current) {
            scr_con_current = float(scr_conlines)  // nolint:PERF020
        }
    }
    let c2da_postinc_2 : int = clearconsole
    clearconsole++
    if (c2da_postinc_2 < vid.numpages) {
        scr_copytop = 1
        Draw_TileClear(0, int(scr_con_current), int(vid.width), int(vid.height - uint(int(scr_con_current))))
        Sbar_Changed()
    } else {
        let c2da_postinc_3 : int = clearnotify
        clearnotify++
        if (c2da_postinc_3 < vid.numpages) {
            scr_copytop = 1
            Draw_TileClear(0, 0, int(vid.width), con_notifylines)
        } else {
            con_notifylines = 0
        }
    }
    return
}
var clearnotify : int = default<int>

var scr_conlines : float = default<float>

var scr_fullupdate : int = default<int>

[sideeffects]
def private SCR_CalcRefdef() {
    let c2da_saved_sp : int = c2da_lin_sp
    SCR_CalcRefdef_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def CalcFov(var fov_x : float; var width_0 : float; var height_0 : float) : float {
    var a : float
    var x_1 : float
    if (fov_x < 1.0 || fov_x > 179.0) {
        Sys_Error(736091, [C2daVaArg(tag = 2, i64 = 0, f64 = double(fov_x), raw = 0x0)])
    }
    x_1 = float(double(width_0) / tan(double(fov_x / 360.0) * 3.141592653589793lf))
    a = float(atan(double(height_0 / x_1)))
    return float(double(a * 360.0) / 3.141592653589793lf)
}
var oldscreensize : float = default<float>

var oldfov : float = default<float>

var scr_disabled_for_loading : uint = default<uint>

var scr_disabled_time : float = default<float>

var block_drawing : uint = default<uint>

var scr_skipupdate : uint = default<uint>

[export, sideeffects]
def SCR_BringDownConsole() {
    var i_1 : int
    scr_centertime_off = 0.0
    i_1 = 0
    while (i_1 < 20 && scr_conlines != scr_con_current) {
        SCR_UpdateScreen()
        i_1++
    }
    let c2da_fresh79 : int = 0
    let c2da_fresh80 : uint = uint(c2da_fresh79)
    c2da_mem[500 + 0 * 16 + 12] = uint8(c2da_fresh80)
    c2da_mem[500 + 0 * 16 + 13] = uint8(c2da_fresh80 >> 0x8)
    c2da_mem[500 + 0 * 16 + 14] = uint8(c2da_fresh80 >> 0x10)
    c2da_mem[500 + 0 * 16 + 15] = uint8(c2da_fresh80 >> 0x18)
    VID_SetPalette(host_basepal)
    return
}
[export, sideeffects]
def SCR_CenterPrint(var str : int) {
    c2da_lin_strncpy(461488, str, 1024ul - 1ul)
    scr_centertime_off = uint_bits_to_float(uint(c2da_mem[461416]) | uint(c2da_mem[461417]) << 0x8 | uint(c2da_mem[461418]) << 0x10 | uint(c2da_mem[461419]) << 0x18)
    scr_centertime_start = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20))
    scr_center_lines = 1
    while (int8(c2da_mem[str]) != 0) {
        if (int(int8(c2da_mem[str])) == 10) {
            scr_center_lines++
        }
        str++
    }
    return
}
[export, sideeffects]
def SCR_BeginLoadingPlaque() {
    S_StopAllSounds(1u)
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) != 2u) {
        return
    }
    if (int(uint(c2da_mem[7804]) | uint(c2da_mem[7805]) << 0x8 | uint(c2da_mem[7806]) << 0x10 | uint(c2da_mem[7807]) << 0x18) != 4) {
        return
    }
    Con_ClearNotify()
    scr_centertime_off = 0.0
    scr_con_current = 0.0
    scr_drawloading = 1u
    scr_fullupdate = 0
    Sbar_Changed()
    SCR_UpdateScreen()
    scr_drawloading = 0u
    scr_disabled_for_loading = 1u
    scr_disabled_time = float(realtime)
    scr_fullupdate = 0
    return
}
[export, sideeffects]
def SCR_EndLoadingPlaque() {
    scr_disabled_for_loading = 0u
    scr_fullupdate = 0
    Con_ClearNotify()
    return
}
[export, sideeffects]
def SCR_ModalMessage(var text : int) : int {
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 0u) {
        return 1
    }
    scr_notifystring = int(text)  // nolint:PERF020
    scr_fullupdate = 0
    scr_drawdialog = 1u
    SCR_UpdateScreen()
    scr_drawdialog = 0u
    S_ClearBuffer()
    while (true) {
        key_count = -1
        Sys_SendKeyEvents()
        if (!(key_lastpress != 121 && key_lastpress != 110 && key_lastpress != 27)) {
            break
        }
    }
    scr_fullupdate = 0
    SCR_UpdateScreen()
    return key_lastpress == 121 ? 1 : 0
}
[export, sideeffects]
def SCR_UpdateWholeScreen() {
    scr_fullupdate = 0
    SCR_UpdateScreen()
    return
}
[sideeffects]
def private SCR_ScreenShot_f_c2da_frame(c2da_fp : int) {
    var i : int
    c2da_lin_strcpy(c2da_fp, 735922)
    i = 0
    while (i <= 99) {
        let c2da_fresh0 : int8 = int8(i / 10 + 48)
        c2da_mem[c2da_fp + 5] = uint8(c2da_fresh0)
        let c2da_fresh1 : int8 = int8(i % 10 + 48)
        c2da_mem[c2da_fp + 6] = uint8(c2da_fresh1)
        c2da_lin_snprintf(c2da_fp + 80, 2147483647ul, 735934, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 5392ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
        if (Sys_FileTime(c2da_fp + 80) == -1) {
            break
        }
        i++
    }
    if (i == 100) {
        Con_Printf(735940, [])
        return
    }
    D_EnableBackBufferAccess()
    WritePCXfile(c2da_fp, vid.buffer, int(vid.width), int(vid.height), int(vid.rowbytes), host_basepal)
    D_DisableBackBufferAccess()
    Con_Printf(735986, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    return
}
[sideeffects]
def private SCR_UpdateScreen_c2da_frame(c2da_fp : int) {
    if (scr_skipupdate != 0x0 || block_drawing != 0x0) {
        return
    }
    scr_copytop = 0
    scr_copyeverything = 0
    if (scr_disabled_for_loading != 0u) {
        if (realtime - double(scr_disabled_time) > 60.0lf) {
            scr_disabled_for_loading = 0u
            Con_Printf(736033, [])
        } else {
            return
        }
    }
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 0u) {
        return
    }
    if (scr_initialized == 0u || uint(con_initialized) == 0u) {
        return
    }
    let c2da_fresh63 : float = uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18)
    if (c2da_fresh63 != SCR_UpdateScreen__oldscr_viewsize) {
        SCR_UpdateScreen__oldscr_viewsize = c2da_fresh63
        vid.recalc_refdef = 1
    }
    let c2da_fresh64 : float = uint_bits_to_float(uint(c2da_mem[461128]) | uint(c2da_mem[461129]) << 0x8 | uint(c2da_mem[461130]) << 0x10 | uint(c2da_mem[461131]) << 0x18)
    if (oldfov != c2da_fresh64) {
        oldfov = c2da_fresh64
        vid.recalc_refdef = 1
    }
    let c2da_fresh65 : float = uint_bits_to_float(uint(c2da_mem[695816]) | uint(c2da_mem[695817]) << 0x8 | uint(c2da_mem[695818]) << 0x10 | uint(c2da_mem[695819]) << 0x18)
    if (SCR_UpdateScreen__oldlcd_x != c2da_fresh65) {
        SCR_UpdateScreen__oldlcd_x = c2da_fresh65
        vid.recalc_refdef = 1
    }
    let c2da_fresh66 : float = uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18)
    if (oldscreensize != c2da_fresh66) {
        oldscreensize = c2da_fresh66
        vid.recalc_refdef = 1
    }
    if (vid.recalc_refdef != 0) {
        SCR_CalcRefdef()
    }
    D_EnableBackBufferAccess()
    let c2da_postinc : int = scr_fullupdate
    scr_fullupdate++
    if (c2da_postinc < vid.numpages) {
        scr_copyeverything = 1
        Draw_TileClear(0, 0, int(vid.width), int(vid.height))
        Sbar_Changed()
    }
    pconupdate = 0
    SCR_SetUpToDrawConsole()
    SCR_EraseCenterString()
    D_DisableBackBufferAccess()
    V_RenderView()
    D_EnableBackBufferAccess()
    if (scr_drawdialog != 0u) {
        Sbar_Draw()
        Draw_FadeScreen()
        SCR_DrawNotifyString()
        scr_copyeverything = 1
    } elif (scr_drawloading != 0u) {
        SCR_DrawLoading()
        Sbar_Draw()
    } elif (int(uint(c2da_mem[756]) | uint(c2da_mem[757]) << 0x8 | uint(c2da_mem[758]) << 0x10 | uint(c2da_mem[759]) << 0x18) == 1 && uint(key_dest) == 0u) {
        Sbar_IntermissionOverlay()
    } elif (int(uint(c2da_mem[756]) | uint(c2da_mem[757]) << 0x8 | uint(c2da_mem[758]) << 0x10 | uint(c2da_mem[759]) << 0x18) == 2 && uint(key_dest) == 0u) {
        Sbar_FinaleOverlay()
        SCR_CheckDrawCenterString()
    } elif (int(uint(c2da_mem[756]) | uint(c2da_mem[757]) << 0x8 | uint(c2da_mem[758]) << 0x10 | uint(c2da_mem[759]) << 0x18) == 3 && uint(key_dest) == 0u) {
        SCR_CheckDrawCenterString()
    } else {
        SCR_DrawRam()
        SCR_DrawNet()
        SCR_DrawTurtle()
        SCR_DrawPause()
        SCR_CheckDrawCenterString()
        Sbar_Draw()
        SCR_DrawConsole()
        M_Draw()
    }
    D_DisableBackBufferAccess()
    if (pconupdate != 0) {
        D_UpdateRects(pconupdate)
    }
    V_UpdatePalette()
    if (scr_copyeverything != 0) {
        let c2da_fresh36 : int = 0
        let c2da_fresh37 : uint = uint(c2da_fresh36)
        c2da_mem[c2da_fp] = uint8(c2da_fresh37)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh37 >> 0x8)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh37 >> 0x10)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh37 >> 0x18)
        let c2da_fresh38 : int = 0
        let c2da_fresh39 : uint = uint(c2da_fresh38)
        c2da_mem[c2da_fp + 4] = uint8(c2da_fresh39)
        c2da_mem[c2da_fp + 5] = uint8(c2da_fresh39 >> 0x8)
        c2da_mem[c2da_fp + 6] = uint8(c2da_fresh39 >> 0x10)
        c2da_mem[c2da_fp + 7] = uint8(c2da_fresh39 >> 0x18)
        let c2da_fresh40 : int = int(vid.width)
        let c2da_fresh41 : uint = uint(c2da_fresh40)
        c2da_mem[c2da_fp + 8] = uint8(c2da_fresh41)
        c2da_mem[c2da_fp + 9] = uint8(c2da_fresh41 >> 0x8)
        c2da_mem[c2da_fp + 10] = uint8(c2da_fresh41 >> 0x10)
        c2da_mem[c2da_fp + 11] = uint8(c2da_fresh41 >> 0x18)
        let c2da_fresh42 : int = int(vid.height)
        let c2da_fresh43 : uint = uint(c2da_fresh42)
        c2da_mem[c2da_fp + 12] = uint8(c2da_fresh43)
        c2da_mem[c2da_fp + 13] = uint8(c2da_fresh43 >> 0x8)
        c2da_mem[c2da_fp + 14] = uint8(c2da_fresh43 >> 0x10)
        c2da_mem[c2da_fp + 15] = uint8(c2da_fresh43 >> 0x18)
        let c2da_fresh44 : uint = 0u
        c2da_mem[c2da_fp + 16] = uint8(c2da_fresh44)
        c2da_mem[c2da_fp + 17] = uint8(c2da_fresh44 >> 0x8)
        c2da_mem[c2da_fp + 18] = uint8(c2da_fresh44 >> 0x10)
        c2da_mem[c2da_fp + 19] = uint8(c2da_fresh44 >> 0x18)
        c2da_mem[c2da_fp + 20] = 0u8
        c2da_mem[c2da_fp + 21] = 0u8
        c2da_mem[c2da_fp + 22] = 0u8
        c2da_mem[c2da_fp + 23] = 0u8
        VID_Update(c2da_fp)
    } elif (scr_copytop != 0) {
        let c2da_fresh45 : int = 0
        let c2da_fresh46 : uint = uint(c2da_fresh45)
        c2da_mem[c2da_fp] = uint8(c2da_fresh46)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh46 >> 0x18)
        let c2da_fresh47 : int = 0
        let c2da_fresh48 : uint = uint(c2da_fresh47)
        c2da_mem[c2da_fp + 4] = uint8(c2da_fresh48)
        c2da_mem[c2da_fp + 5] = uint8(c2da_fresh48 >> 0x8)
        c2da_mem[c2da_fp + 6] = uint8(c2da_fresh48 >> 0x10)
        c2da_mem[c2da_fp + 7] = uint8(c2da_fresh48 >> 0x18)
        let c2da_fresh49 : int = int(vid.width)
        let c2da_fresh50 : uint = uint(c2da_fresh49)
        c2da_mem[c2da_fp + 8] = uint8(c2da_fresh50)
        c2da_mem[c2da_fp + 9] = uint8(c2da_fresh50 >> 0x8)
        c2da_mem[c2da_fp + 10] = uint8(c2da_fresh50 >> 0x10)
        c2da_mem[c2da_fp + 11] = uint8(c2da_fresh50 >> 0x18)
        let c2da_fresh51 : int = int(vid.height - uint(sb_lines))
        let c2da_fresh52 : uint = uint(c2da_fresh51)
        c2da_mem[c2da_fp + 12] = uint8(c2da_fresh52)
        c2da_mem[c2da_fp + 13] = uint8(c2da_fresh52 >> 0x8)
        c2da_mem[c2da_fp + 14] = uint8(c2da_fresh52 >> 0x10)
        c2da_mem[c2da_fp + 15] = uint8(c2da_fresh52 >> 0x18)
        let c2da_fresh53 : uint = 0u
        c2da_mem[c2da_fp + 16] = uint8(c2da_fresh53)
        c2da_mem[c2da_fp + 17] = uint8(c2da_fresh53 >> 0x8)
        c2da_mem[c2da_fp + 18] = uint8(c2da_fresh53 >> 0x10)
        c2da_mem[c2da_fp + 19] = uint8(c2da_fresh53 >> 0x18)
        c2da_mem[c2da_fp + 20] = 0u8
        c2da_mem[c2da_fp + 21] = 0u8
        c2da_mem[c2da_fp + 22] = 0u8
        c2da_mem[c2da_fp + 23] = 0u8
        VID_Update(c2da_fp)
    } else {
        let c2da_fresh54 : int = int(uint(c2da_mem[462512]) | uint(c2da_mem[462513]) << 0x8 | uint(c2da_mem[462514]) << 0x10 | uint(c2da_mem[462515]) << 0x18)
        let c2da_fresh55 : uint = uint(c2da_fresh54)
        c2da_mem[c2da_fp] = uint8(c2da_fresh55)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh55 >> 0x8)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh55 >> 0x10)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh55 >> 0x18)
        let c2da_fresh56 : int = int(uint(c2da_mem[462516]) | uint(c2da_mem[462517]) << 0x8 | uint(c2da_mem[462518]) << 0x10 | uint(c2da_mem[462519]) << 0x18)
        let c2da_fresh57 : uint = uint(c2da_fresh56)
        c2da_mem[c2da_fp + 4] = uint8(c2da_fresh57)
        c2da_mem[c2da_fp + 5] = uint8(c2da_fresh57 >> 0x8)
        c2da_mem[c2da_fp + 6] = uint8(c2da_fresh57 >> 0x10)
        c2da_mem[c2da_fp + 7] = uint8(c2da_fresh57 >> 0x18)
        let c2da_fresh58 : int = int(uint(c2da_mem[462520]) | uint(c2da_mem[462521]) << 0x8 | uint(c2da_mem[462522]) << 0x10 | uint(c2da_mem[462523]) << 0x18)
        let c2da_fresh59 : uint = uint(c2da_fresh58)
        c2da_mem[c2da_fp + 8] = uint8(c2da_fresh59)
        c2da_mem[c2da_fp + 9] = uint8(c2da_fresh59 >> 0x8)
        c2da_mem[c2da_fp + 10] = uint8(c2da_fresh59 >> 0x10)
        c2da_mem[c2da_fp + 11] = uint8(c2da_fresh59 >> 0x18)
        let c2da_fresh60 : int = int(uint(c2da_mem[462524]) | uint(c2da_mem[462525]) << 0x8 | uint(c2da_mem[462526]) << 0x10 | uint(c2da_mem[462527]) << 0x18)
        let c2da_fresh61 : uint = uint(c2da_fresh60)
        c2da_mem[c2da_fp + 12] = uint8(c2da_fresh61)
        c2da_mem[c2da_fp + 13] = uint8(c2da_fresh61 >> 0x8)
        c2da_mem[c2da_fp + 14] = uint8(c2da_fresh61 >> 0x10)
        c2da_mem[c2da_fp + 15] = uint8(c2da_fresh61 >> 0x18)
        let c2da_fresh62 : uint = 0u
        c2da_mem[c2da_fp + 16] = uint8(c2da_fresh62)
        c2da_mem[c2da_fp + 17] = uint8(c2da_fresh62 >> 0x8)
        c2da_mem[c2da_fp + 18] = uint8(c2da_fresh62 >> 0x10)
        c2da_mem[c2da_fp + 19] = uint8(c2da_fresh62 >> 0x18)
        c2da_mem[c2da_fp + 20] = 0u8
        c2da_mem[c2da_fp + 21] = 0u8
        c2da_mem[c2da_fp + 22] = 0u8
        c2da_mem[c2da_fp + 23] = 0u8
        VID_Update(c2da_fp)
    }
    return
}
[sideeffects]
def private SCR_CalcRefdef_c2da_frame(c2da_fp : int) {
    var size : float
    scr_fullupdate = 0
    vid.recalc_refdef = 0
    Sbar_Changed()
    if (uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18) < 30.0) {
        Cvar_Set(735783, 736077)
    }
    if (uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18) > 120.0) {
        Cvar_Set(735783, 736080)
    }
    if (uint_bits_to_float(uint(c2da_mem[461128]) | uint(c2da_mem[461129]) << 0x8 | uint(c2da_mem[461130]) << 0x10 | uint(c2da_mem[461131]) << 0x18) < 10.0) {
        Cvar_Set(735776, 736084)
    }
    if (uint_bits_to_float(uint(c2da_mem[461128]) | uint(c2da_mem[461129]) << 0x8 | uint(c2da_mem[461130]) << 0x10 | uint(c2da_mem[461131]) << 0x18) > 170.0) {
        Cvar_Set(735776, 736087)
    }
    let c2da_fresh67 : float = uint_bits_to_float(uint(c2da_mem[461128]) | uint(c2da_mem[461129]) << 0x8 | uint(c2da_mem[461130]) << 0x10 | uint(c2da_mem[461131]) << 0x18)
    let c2da_fresh68 : uint = float_bits_to_uint(c2da_fresh67)
    c2da_mem[5344] = uint8(c2da_fresh68)
    c2da_mem[5345] = uint8(c2da_fresh68 >> 0x8)
    c2da_mem[5346] = uint8(c2da_fresh68 >> 0x10)
    c2da_mem[5347] = uint8(c2da_fresh68 >> 0x18)
    let c2da_fresh69 : float = CalcFov(uint_bits_to_float(uint(c2da_mem[5344]) | uint(c2da_mem[5345]) << 0x8 | uint(c2da_mem[5346]) << 0x10 | uint(c2da_mem[5347]) << 0x18), float(int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18)), float(int(uint(c2da_mem[5212]) | uint(c2da_mem[5213]) << 0x8 | uint(c2da_mem[5214]) << 0x10 | uint(c2da_mem[5215]) << 0x18)))
    let c2da_fresh70 : uint = float_bits_to_uint(c2da_fresh69)
    c2da_mem[5348] = uint8(c2da_fresh70)
    c2da_mem[5349] = uint8(c2da_fresh70 >> 0x8)
    c2da_mem[5350] = uint8(c2da_fresh70 >> 0x10)
    c2da_mem[5351] = uint8(c2da_fresh70 >> 0x18)
    if (int(uint(c2da_mem[756]) | uint(c2da_mem[757]) << 0x8 | uint(c2da_mem[758]) << 0x10 | uint(c2da_mem[759]) << 0x18) != 0) {
        size = 120.0
    } else {
        size = uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18)
    }
    if (size >= 120.0) {
        sb_lines = 0
    } elif (size >= 110.0) {
        sb_lines = 24
    } else {
        sb_lines = 24 + 16 + 8
    }
    let c2da_fresh71 : int = 0
    let c2da_fresh72 : uint = uint(c2da_fresh71)
    c2da_mem[c2da_fp] = uint8(c2da_fresh72)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh72 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh72 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh72 >> 0x18)
    let c2da_fresh73 : int = 0
    let c2da_fresh74 : uint = uint(c2da_fresh73)
    c2da_mem[c2da_fp + 4] = uint8(c2da_fresh74)
    c2da_mem[c2da_fp + 5] = uint8(c2da_fresh74 >> 0x8)
    c2da_mem[c2da_fp + 6] = uint8(c2da_fresh74 >> 0x10)
    c2da_mem[c2da_fp + 7] = uint8(c2da_fresh74 >> 0x18)
    let c2da_fresh75 : int = int(vid.width)
    let c2da_fresh76 : uint = uint(c2da_fresh75)
    c2da_mem[c2da_fp + 8] = uint8(c2da_fresh76)
    c2da_mem[c2da_fp + 9] = uint8(c2da_fresh76 >> 0x8)
    c2da_mem[c2da_fp + 10] = uint8(c2da_fresh76 >> 0x10)
    c2da_mem[c2da_fp + 11] = uint8(c2da_fresh76 >> 0x18)
    let c2da_fresh77 : int = int(vid.height)
    let c2da_fresh78 : uint = uint(c2da_fresh77)
    c2da_mem[c2da_fp + 12] = uint8(c2da_fresh78)
    c2da_mem[c2da_fp + 13] = uint8(c2da_fresh78 >> 0x8)
    c2da_mem[c2da_fp + 14] = uint8(c2da_fresh78 >> 0x10)
    c2da_mem[c2da_fp + 15] = uint8(c2da_fresh78 >> 0x18)
    R_SetVrect(c2da_fp, 462512, sb_lines)
    if (scr_con_current > float(vid.height)) {
        scr_con_current = float(vid.height)
    }
    R_ViewChanged(c2da_fp, sb_lines, vid.aspect)
    return
}

// This unit's static data, at heap offset 735776.
let private c2da_lin_static_screen_seg = fixed_array<int>(735776, 326)
let private c2da_lin_static_screen = fixed_array<uint64>(0x7600303900766f66ul, 0x657a6973776569ul, 0x5f72637300303031ul, 0x64656570736e6f63ul, 0x6f68730030303300ul, 0x730031006d617277ul, 0x6c74727574776f68ul, 0x776f687300300065ul, 0x6373006573756170ul, 0x7265746e65635f72ul, 0x73003200656d6974ul, 0x746e6972705f7263ul, 0x38006465657073ul, 0x68736e6565726373ul, 0x75657a697300746ful, 0x6f64657a69730070ul, 0x6e006d6172006e77ul, 0x6c74727574007465ul, 0x30656b6175710065ul, 0x7325007863702e30ul, 0x5f5243530073252ful, 0x68536e6565726353ul, 0x6f43203a665f746ful, 0x632074276e646c75ul, 0x2061206574616572ul, 0x656c696620584350ul, 0x2065746f7257000aul, 0x5f524353000a7325ul, 0x68536e6565726353ul, 0x6f6e203a665f746ful, 0x6867756f6e652074ul, 0xa79726f6d656d20ul, 0x61662064616f6c00ul, 0x67000a2e64656c69ul, 0x65737561702f7866ul, 0x78666700706d6c2eul, 0x676e6964616f6c2ful, 0x303300706d6c2eul, 0x3100303100303231ul, 0x6620646142003037ul, 0x6625203a766ful)

[init]
def private c2da_lin_init_static_screen() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_screen_seg[s * 2]
        for (k in range(c2da_lin_static_screen_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_screen[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_screen_0 = fixed_array<uint8>(0x20, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x24, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_screen_1 = fixed_array<uint8>(0x27, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_screen_2 = fixed_array<uint8>(0x34, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x41, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_screen_3 = fixed_array<uint8>(0x45, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4d, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_screen_4 = fixed_array<uint8>(0x4f, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5a, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_screen_5 = fixed_array<uint8>(0x5c, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4d, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_screen_6 = fixed_array<uint8>(0x66, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x75, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_screen_7 = fixed_array<uint8>(0x77, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x86, 0x3a, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_screen() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[461104 + i] = c2da_lin_extern_screen_0[i]
    }
    for (i in range(40)) {
        c2da_mem[461152 + i] = c2da_lin_extern_screen_1[i]
    }
    for (i in range(40)) {
        c2da_mem[461200 + i] = c2da_lin_extern_screen_2[i]
    }
    for (i in range(40)) {
        c2da_mem[461248 + i] = c2da_lin_extern_screen_3[i]
    }
    for (i in range(40)) {
        c2da_mem[461296 + i] = c2da_lin_extern_screen_4[i]
    }
    for (i in range(40)) {
        c2da_mem[461344 + i] = c2da_lin_extern_screen_5[i]
    }
    for (i in range(40)) {
        c2da_mem[461392 + i] = c2da_lin_extern_screen_6[i]
    }
    for (i in range(40)) {
        c2da_mem[461440 + i] = c2da_lin_extern_screen_7[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_screen() {
    if (length(c2da_fn_table0) < 220) {
        resize(c2da_fn_table0, 220)
    }
    c2da_fn_table0[219] = @@SCR_SizeDown_f
    c2da_fn_table0[218] = @@SCR_SizeUp_f
    c2da_fn_table0[217] = @@SCR_ScreenShot_f
}

[init]
def private c2da_lin_relink_init_screen() {
    c2da_relink_screen()
}
