var private Con_Printf__inupdate : uint = 0u

var private Con_Print__cr : int = 0

var con_totallines : int = default<int>

var con_backscroll : int = default<int>

var con_forcedup : uint = default<uint>

var con_initialized : uint = default<uint>

var con_notifylines : int = default<int>

[export, sideeffects]
def Con_CheckResize() {
    let c2da_saved_sp : int = c2da_lin_sp
    Con_CheckResize_c2da_frame(c2da_lin_enter(16384))
    c2da_lin_sp = c2da_saved_sp
}
var con_current : int = default<int>

[export, sideeffects]
def Con_ClearNotify() {
    for (i_0 in range(0, 4)) {
        let c2da_fresh2 : float = 0.0
        let c2da_fresh3 : uint = float_bits_to_uint(c2da_fresh2)
        c2da_mem[196032 + i_0 * 4] = uint8(c2da_fresh3)
        c2da_mem[196032 + i_0 * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[196032 + i_0 * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[196032 + i_0 * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
    }
    return
}
var con_linewidth : int = default<int>

var con_text : int = 0

[export, sideeffects]
def Con_Init() {
    let c2da_saved_sp : int = c2da_lin_sp
    Con_Init_c2da_frame(c2da_lin_enter(1008))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Con_Clear_f() {
    if (con_text != 0) {
        Q_memset(con_text, 32, 16384)
    }
    return
}
[export, sideeffects]
def Con_MessageMode2_f() {
    key_dest = 2u
    team_message = 1u
    return
}
[export, sideeffects]
def Con_MessageMode_f() {
    key_dest = 2u
    team_message = 0u
    return
}
[export, sideeffects]
def Con_ToggleConsole_f() {
    if (uint(key_dest) == 1u) {
        if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 2u) {
            key_dest = 0u
            let c2da_fresh4 : int8 = int8(0)
            c2da_mem[196048 + int(edit_line) * 256 + 1] = uint8(c2da_fresh4)
            key_linepos = 1
        } else {
            M_Menu_Main_f()
        }
    } else {
        key_dest = 1u
    }
    SCR_EndLoadingPlaque()
    c2da_lin_memset(196032, 0, 16ul)
    return
}
[export, sideeffects]
def Con_Printf(var fmt_0 : int; c2da_va_args : array<C2daVaArg>) {
    let c2da_saved_sp : int = c2da_lin_sp
    Con_Printf_c2da_frame(fmt_0, c2da_va_args, c2da_lin_enter(4096))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Con_Print(var txt : int) {
    var y : int
    var c : int
    var l : int
    var mask : int
    con_backscroll = 0
    if (int(int8(c2da_mem[txt + 0])) == 1) {
        mask = 128
        S_LocalSound(706668)
        txt++
    } elif (int(int8(c2da_mem[txt + 0])) == 2) {
        mask = 128
        txt++
    } else {
        mask = 0
    }
    while (true) {
        c = int(int8(c2da_mem[txt]))
        if (c == 0) {
            break
        }
        l = 0
        while (l < con_linewidth) {
            if (int(int8(c2da_mem[txt + l])) <= 32) {
                break
            }
            l++
        }
        if (l != con_linewidth && con_x + l > con_linewidth) {
            con_x = 0
        }
        txt++
        if (Con_Print__cr != 0) {
            con_current--
            Con_Print__cr = 0
        }
        if (con_x == 0) {
            Con_Linefeed()
            if (con_current >= 0) {
                let c2da_fresh5 : int = 196032 + con_current % 4 * 4
                let c2da_fresh6 : float = float(realtime)
                let c2da_fresh7 : uint = float_bits_to_uint(c2da_fresh6)
                c2da_mem[c2da_fresh5] = uint8(c2da_fresh7)
                c2da_mem[c2da_fresh5 + 1] = uint8(c2da_fresh7 >> 0x8)
                c2da_mem[c2da_fresh5 + 2] = uint8(c2da_fresh7 >> 0x10)
                c2da_mem[c2da_fresh5 + 3] = uint8(c2da_fresh7 >> 0x18)
            }
        }
        if (c == 10) {
            con_x = 0
        } elif (c == 13) {
            con_x = 0
            Con_Print__cr = 1
        } else {
            y = con_current % con_totallines
            let c2da_fresh8 : int8 = int8(c | mask)
            c2da_mem[con_text + (y * con_linewidth + con_x)] = uint8(c2da_fresh8)
            con_x++
            if (con_x >= con_linewidth) {
                con_x = 0
            }
        }
    }
    return
}
var con_x : int = default<int>

[export, sideeffects]
def Con_Linefeed() {
    con_x = 0
    con_current++
    Q_memset(con_text + con_current % con_totallines * con_linewidth, 32, con_linewidth)
    return
}
[export, sideeffects]
def Con_DebugLog(var file : int; var fmt_1 : int; c2da_va_args : array<C2daVaArg>) {
    var argptr_0 : C2daVaCursor = C2daVaCursor(index = 0)
    var fd : int
    argptr_0.index = 0
    c2da_lin_vsnprintf(705504, 2147483647ul, fmt_1, argptr_0, c2da_va_args)
    argptr_0.index = -1
    fd = c2da_lin_fopen(file, 706682)
    c2da_lin_fwrite(705504, uint64(c2da_lin_strlen(705504)), 1ul, uint64(fd))
    c2da_std_fclose(uint64(fd))
    return
}
var con_debuglog : uint = default<uint>

[export, sideeffects]
def Con_DrawConsole(var lines : int; var drawinput : uint) {
    var i_1 : int
    var x : int
    var y_0 : int
    var rows : int
    var text : int
    var j_0 : int
    if (lines <= 0) {
        return
    }
    Draw_ConsoleBackground(lines)
    con_vislines = int(lines)  // nolint:PERF020
    rows = lines - 16 >> 3
    y_0 = lines - 16 - (rows << 3)
    i_1 = con_current - rows + 1
    while (i_1 <= con_current) {
        j_0 = i_1 - con_backscroll
        if (j_0 < 0) {
            j_0 = 0
        }
        text = con_text + j_0 % con_totallines * con_linewidth
        x = 0
        while (x < con_linewidth) {
            Draw_Character(x + 1 << 3, y_0, int(int8(c2da_mem[text + x])))
            x++
        }
        i_1++
        y_0 += 8
    }
    if (drawinput != 0u) {
        Con_DrawInput()
    }
    return
}
[export, sideeffects]
def Con_DrawInput() {
    var y_1 : int
    var i_2 : int
    var text_0 : int
    if (uint(key_dest) != 1u && con_forcedup == 0u) {
        return
    }
    text_0 = 196048 + int(edit_line) * 256
    let c2da_fresh9 : int8 = int8(10 + (int(realtime * double(con_cursorspeed)) & 1))
    c2da_mem[text_0 + int(key_linepos)] = uint8(c2da_fresh9)
    i_2 = key_linepos + 1
    while (i_2 < con_linewidth) {
        let c2da_fresh10 : int8 = int8(32)
        c2da_mem[text_0 + i_2] = uint8(c2da_fresh10)
        i_2++
    }
    if (key_linepos >= con_linewidth) {
        text_0 = text_0 + (1 + key_linepos - con_linewidth)
    }
    y_1 = con_vislines - 16
    i_2 = 0
    while (i_2 < con_linewidth) {
        Draw_Character(i_2 + 1 << 3, con_vislines - 16, int(int8(c2da_mem[text_0 + i_2])))
        i_2++
    }
    let c2da_fresh11 : int8 = int8(0)
    c2da_mem[196048 + int(edit_line) * 256 + int(key_linepos)] = uint8(c2da_fresh11)
    return
}
var con_vislines : int = default<int>

var con_cursorspeed : float = 4.0

[export, sideeffects]
def Con_DPrintf(var fmt_2 : int; c2da_va_args : array<C2daVaArg>) {
    let c2da_saved_sp : int = c2da_lin_sp
    Con_DPrintf_c2da_frame(fmt_2, c2da_va_args, c2da_lin_enter(4096))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Con_SafePrintf(var fmt_3 : int; c2da_va_args : array<C2daVaArg>) {
    let c2da_saved_sp : int = c2da_lin_sp
    Con_SafePrintf_c2da_frame(fmt_3, c2da_va_args, c2da_lin_enter(1024))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Con_DrawNotify() {
    var x_0 : int
    var v : int
    var text_1 : int
    var i_3 : int
    var time : float
    v = 0
    i_3 = con_current - 4 + 1
    while (i_3 <= con_current) {
        if (i_3 < 0) {
            i_3++
            continue
        }
        let c2da_fresh12 : int = 196032 + i_3 % 4 * 4
        time = uint_bits_to_float(uint(c2da_mem[c2da_fresh12]) | uint(c2da_mem[c2da_fresh12 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh12 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh12 + 3]) << 0x18)
        if (time == 0.0) {
            i_3++
            continue
        }
        time = float(realtime - double(time))
        if (time > uint_bits_to_float(uint(c2da_mem[196008]) | uint(c2da_mem[196009]) << 0x8 | uint(c2da_mem[196010]) << 0x10 | uint(c2da_mem[196011]) << 0x18)) {
            i_3++
            continue
        }
        text_1 = con_text + i_3 % con_totallines * con_linewidth
        clearnotify = 0
        scr_copytop = 1
        x_0 = 0
        while (x_0 < con_linewidth) {
            Draw_Character(x_0 + 1 << 3, v, int(int8(c2da_mem[text_1 + x_0])))
            x_0++
        }
        v += 8
        i_3++
    }
    if (uint(key_dest) == 2u) {
        clearnotify = 0
        scr_copytop = 1
        x_0 = 0
        Draw_String(8, v, 706685)
        while (int8(c2da_mem[246128 + x_0]) != 0) {
            Draw_Character(x_0 + 5 << 3, v, int(int8(c2da_mem[246128 + x_0])))
            x_0++
        }
        Draw_Character(x_0 + 5 << 3, v, 10 + (int(realtime * double(con_cursorspeed)) & 1))
        v += 8
    }
    if (v > con_notifylines) {
        con_notifylines = v
    }
    return
}
[export, sideeffects]
def Con_NotifyBox(var text_2 : int) {
    var t1 : double
    var t2_0 : double
    Con_Printf(706690, [])
    Con_Printf(text_2, [])
    Con_Printf(706731, [])
    Con_Printf(706745, [])
    key_count = -2
    key_dest = 1u
    while (true) {
        t1 = Sys_FloatTime()
        SCR_UpdateScreen()
        Sys_SendKeyEvents()
        t2_0 = Sys_FloatTime()
        realtime = realtime + (t2_0 - t1)
        if (key_count >= 0) {
            break
        }
    }
    Con_Printf(706784, [])
    key_dest = 0u
    realtime = 0.0lf
    return
}
[sideeffects]
def private Con_CheckResize_c2da_frame(c2da_fp : int) {
    var width : int
    var oldwidth : int
    var oldtotallines : int
    var numlines : int
    var numchars : int
    width = int((vid.width >> 3u) - 2u)
    if (width == con_linewidth) {
        return
    }
    if (width < 1) {
        con_linewidth = 38
        con_totallines = 16384 / con_linewidth
        Q_memset(con_text, 32, 16384)
    } else {
        oldwidth = con_linewidth
        con_linewidth = width
        oldtotallines = con_totallines
        con_totallines = 16384 / con_linewidth
        numlines = oldtotallines
        if (con_totallines < numlines) {
            numlines = con_totallines
        }
        numchars = oldwidth
        if (con_linewidth < numchars) {
            numchars = con_linewidth
        }
        Q_memcpy(c2da_fp, con_text, 16384)
        Q_memset(con_text, 32, 16384)
        for (i in range(0, numlines)) {
            for (j in range(0, numchars)) {
                let c2da_fresh0 : int = c2da_fp + ((con_current - i + oldtotallines) % oldtotallines * oldwidth + j)
                let c2da_fresh1 : int8 = int8(c2da_mem[c2da_fresh0])
                c2da_mem[con_text + ((con_totallines - 1 - i) * con_linewidth + j)] = uint8(c2da_fresh1)
            }
        }
        Con_ClearNotify()
    }
    con_backscroll = 0
    con_current = con_totallines - 1
    return
}
[sideeffects]
def private Con_Init_c2da_frame(c2da_fp : int) {
    var t2 : int = 706545
    con_debuglog = uint(COM_CheckParm(706559))
    if (con_debuglog != 0u) {
        if (c2da_lin_strlen(5392) < 1000ul - c2da_lin_strlen(t2)) {
            c2da_lin_snprintf(c2da_fp, 2147483647ul, 706569, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 5392ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(t2))])
            c2da_lin_remove(c2da_fp)
        }
    }
    con_text = Hunk_AllocName(16384, 706574)
    Q_memset(con_text, 32, 16384)
    con_linewidth = -1
    Con_CheckResize()
    Con_Printf(706582, [])
    Cvar_RegisterVariable(195984)
    Cmd_AddCommand(706604, 55)
    Cmd_AddCommand(706618, 56)
    Cmd_AddCommand(706630, 57)
    Cmd_AddCommand(706643, 58)
    con_initialized = 1u
    return
}
[sideeffects]
def private Con_Printf_c2da_frame(var fmt_0 : int; c2da_va_args : array<C2daVaArg>; c2da_fp : int) {
    var argptr : C2daVaCursor = C2daVaCursor(index = 0)
    argptr.index = 0
    c2da_lin_vsnprintf(c2da_fp, 2147483647ul, fmt_0, argptr, c2da_va_args)
    argptr.index = -1
    Sys_Printf(706649, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    if (con_debuglog != 0u) {
        Con_DebugLog(va(706652, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 5392ul)]), 706649, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    }
    if (con_initialized == 0u) {
        return
    }
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 0u) {
        return
    }
    Con_Print(c2da_fp)
    if (int(uint(c2da_mem[7804]) | uint(c2da_mem[7805]) << 0x8 | uint(c2da_mem[7806]) << 0x10 | uint(c2da_mem[7807]) << 0x18) != 4 && uint(scr_disabled_for_loading) == 0u) {
        if (Con_Printf__inupdate == 0u) {
            Con_Printf__inupdate = 1u
            SCR_UpdateScreen()
            Con_Printf__inupdate = 0u
        }
    }
    return
}
[sideeffects]
def private Con_DPrintf_c2da_frame(var fmt_2 : int; c2da_va_args : array<C2daVaArg>; c2da_fp : int) {
    var argptr_1 : C2daVaCursor = C2daVaCursor(index = 0)
    if (uint_bits_to_float(uint(c2da_mem[243656]) | uint(c2da_mem[243657]) << 0x8 | uint(c2da_mem[243658]) << 0x10 | uint(c2da_mem[243659]) << 0x18) == 0.0) {
        return
    }
    argptr_1.index = 0
    c2da_lin_vsnprintf(c2da_fp, 2147483647ul, fmt_2, argptr_1, c2da_va_args)
    argptr_1.index = -1
    Con_Printf(706649, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    return
}
[sideeffects]
def private Con_SafePrintf_c2da_frame(var fmt_3 : int; c2da_va_args : array<C2daVaArg>; c2da_fp : int) {
    var argptr_2 : C2daVaCursor = C2daVaCursor(index = 0)
    var temp : int
    argptr_2.index = 0
    c2da_lin_vsnprintf(c2da_fp, 2147483647ul, fmt_3, argptr_2, c2da_va_args)
    argptr_2.index = -1
    temp = int(scr_disabled_for_loading)
    scr_disabled_for_loading = 1u
    Con_Printf(706649, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    scr_disabled_for_loading = uint(temp)
    return
}

// This unit's static data, at heap offset 705504.
let private c2da_lin_static_console_seg = fixed_array<int>(706528, 257)
let private c2da_lin_static_console = fixed_array<uint64>(0x69746f6e5f6e6f63ul, 0x3300656d69747966ul, 0x6f736e6f63712f00ul, 0x2d00676f6c2e656cul, 0x67756265646e6f63ul, 0x6f63007325732500ul, 0x6f4300747865746eul, 0x6e6920656c6f736eul, 0x657a696c61697469ul, 0x67676f74000a2e64ul, 0x6c6f736e6f63656cul, 0x67617373656d0065ul, 0x656d0065646f6d65ul, 0x646f6d6567617373ul, 0x7261656c63003265ul, 0x712f732500732500ul, 0x2e656c6f736e6f63ul, 0x6373696d00676f6cul, 0x61772e6b6c61742ful, 0x7961730061770076ul, 0x1e1e1e1d0a0a003aul, 0x1e1e1e1e1e1e1e1eul, 0x1e1e1e1e1e1e1e1eul, 0x1e1e1e1e1e1e1e1eul, 0x1e1e1e1e1e1e1e1eul, 0x7373657250000a1ful, 0xa2e79656b206120ul, 0x1e1e1e1e1e1e1d00ul, 0x1e1e1e1e1e1e1e1eul, 0x1e1e1e1e1e1e1e1eul, 0x1e1e1e1e1e1e1e1eul, 0xa1f1e1e1e1e1eul, 0xaul)

[init]
def private c2da_lin_init_static_console() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_console_seg[s * 2]
        for (k in range(c2da_lin_static_console_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_console[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_console_0 = fixed_array<uint8>(0xe0, 0xc7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xef, 0xc7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_console() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[195984 + i] = c2da_lin_extern_console_0[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_console() {
    if (length(c2da_fn_table0) < 96) {
        resize(c2da_fn_table0, 96)
    }
    c2da_fn_table0[58] = @@Con_Clear_f
    c2da_fn_table0[57] = @@Con_MessageMode2_f
    c2da_fn_table0[56] = @@Con_MessageMode_f
    c2da_fn_table0[55] = @@Con_ToggleConsole_f
    if (length(c2da_fn_table4) < 96) {
        resize(c2da_fn_table4, 96)
    }
    c2da_fn_table4[95] = @@Con_Printf
}

[init]
def private c2da_lin_relink_init_console() {
    c2da_relink_console()
}
