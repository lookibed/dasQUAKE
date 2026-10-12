[export, sideeffects]
def CL_StopPlayback() {
    if ((uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) == 0u) {
        return
    }
    c2da_std_fclose(uint64(int(uint(c2da_mem[7784]) | uint(c2da_mem[7785]) << 0x8 | uint(c2da_mem[7786]) << 0x10 | uint(c2da_mem[7787]) << 0x18)))
    let c2da_fresh0 : uint = 0u
    let c2da_fresh1 : uint = c2da_fresh0
    c2da_mem[7772] = uint8(c2da_fresh1)
    c2da_mem[7773] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[7774] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[7775] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : uint = 0u
    c2da_mem[7784] = uint8(c2da_fresh2)
    c2da_mem[7785] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[7786] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[7787] = uint8(c2da_fresh2 >> 0x18)
    c2da_mem[7788] = 0u8
    c2da_mem[7789] = 0u8
    c2da_mem[7790] = 0u8
    c2da_mem[7791] = 0u8
    let c2da_fresh3 : uint = 1u
    let c2da_fresh4 : uint = c2da_fresh3
    c2da_mem[5520] = uint8(c2da_fresh4)
    c2da_mem[5521] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[5522] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[5523] = uint8(c2da_fresh4 >> 0x18)
    if ((uint(c2da_mem[7776]) | uint(c2da_mem[7777]) << 0x8 | uint(c2da_mem[7778]) << 0x10 | uint(c2da_mem[7779]) << 0x18) != 0u) {
        CL_FinishTimeDemo()
    }
    return
}
[export, sideeffects]
def CL_FinishTimeDemo() {
    var frames : int
    var time : float
    let c2da_fresh5 : uint = 0u
    let c2da_fresh6 : uint = c2da_fresh5
    c2da_mem[7776] = uint8(c2da_fresh6)
    c2da_mem[7777] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[7778] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[7779] = uint8(c2da_fresh6 >> 0x18)
    frames = host_framecount - int(uint(c2da_mem[7796]) | uint(c2da_mem[7797]) << 0x8 | uint(c2da_mem[7798]) << 0x10 | uint(c2da_mem[7799]) << 0x18) - 1
    time = float(realtime - double(uint_bits_to_float(uint(c2da_mem[7800]) | uint(c2da_mem[7801]) << 0x8 | uint(c2da_mem[7802]) << 0x10 | uint(c2da_mem[7803]) << 0x18)))
    if (time == 0.0) {
        time = 1.0
    }
    Con_Printf(697216, [C2daVaArg(tag = 1, i64 = int64(frames), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(time), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(float(frames) / time), raw = 0x0)])
    return
}
[export, sideeffects]
def CL_GetMessage() : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = CL_GetMessage_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def CL_WriteDemoMessage() {
    let c2da_saved_sp : int = c2da_lin_sp
    CL_WriteDemoMessage_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def CL_Stop_f() {
    if (uint(cmd_source) != 1u) {
        return
    }
    if ((uint(c2da_mem[7768]) | uint(c2da_mem[7769]) << 0x8 | uint(c2da_mem[7770]) << 0x10 | uint(c2da_mem[7771]) << 0x18) == 0u) {
        Con_Printf(697309, [])
        return
    }
    SZ_Clear(5360)
    MSG_WriteByte(5360, 2)
    CL_WriteDemoMessage()
    c2da_std_fclose(uint64(int(uint(c2da_mem[7784]) | uint(c2da_mem[7785]) << 0x8 | uint(c2da_mem[7786]) << 0x10 | uint(c2da_mem[7787]) << 0x18)))
    let c2da_fresh26 : uint = 0u
    c2da_mem[7784] = uint8(c2da_fresh26)
    c2da_mem[7785] = uint8(c2da_fresh26 >> 0x8)
    c2da_mem[7786] = uint8(c2da_fresh26 >> 0x10)
    c2da_mem[7787] = uint8(c2da_fresh26 >> 0x18)
    c2da_mem[7788] = 0u8
    c2da_mem[7789] = 0u8
    c2da_mem[7790] = 0u8
    c2da_mem[7791] = 0u8
    let c2da_fresh27 : uint = 0u
    let c2da_fresh28 : uint = c2da_fresh27
    c2da_mem[7768] = uint8(c2da_fresh28)
    c2da_mem[7769] = uint8(c2da_fresh28 >> 0x8)
    c2da_mem[7770] = uint8(c2da_fresh28 >> 0x10)
    c2da_mem[7771] = uint8(c2da_fresh28 >> 0x18)
    Con_Printf(697332, [])
    return
}
[export, sideeffects]
def CL_Record_f() {
    let c2da_saved_sp : int = c2da_lin_sp
    CL_Record_f_c2da_frame(c2da_lin_enter(128))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def CL_PlayDemo_f() {
    let c2da_saved_sp : int = c2da_lin_sp
    CL_PlayDemo_f_c2da_frame(c2da_lin_enter(256))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def CL_TimeDemo_f() {
    if (uint(cmd_source) != 1u) {
        return
    }
    if (Cmd_Argc() != 2) {
        Con_Printf(697673, [])
        return
    }
    CL_PlayDemo_f()
    let c2da_fresh46 : uint = 1u
    let c2da_fresh47 : uint = c2da_fresh46
    c2da_mem[7776] = uint8(c2da_fresh47)
    c2da_mem[7777] = uint8(c2da_fresh47 >> 0x8)
    c2da_mem[7778] = uint8(c2da_fresh47 >> 0x10)
    c2da_mem[7779] = uint8(c2da_fresh47 >> 0x18)
    let c2da_fresh48 : uint = uint(host_framecount)
    c2da_mem[7796] = uint8(c2da_fresh48)
    c2da_mem[7797] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[7798] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[7799] = uint8(c2da_fresh48 >> 0x18)
    let c2da_fresh49 : int = -1
    let c2da_fresh50 : uint = uint(c2da_fresh49)
    c2da_mem[7792] = uint8(c2da_fresh50)
    c2da_mem[7793] = uint8(c2da_fresh50 >> 0x8)
    c2da_mem[7794] = uint8(c2da_fresh50 >> 0x10)
    c2da_mem[7795] = uint8(c2da_fresh50 >> 0x18)
    return
}
[sideeffects]
def private CL_GetMessage_c2da_frame(c2da_fp : int) : int {
    var r : int
    if ((uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) != 0u) {
        if (int(uint(c2da_mem[7804]) | uint(c2da_mem[7805]) << 0x8 | uint(c2da_mem[7806]) << 0x10 | uint(c2da_mem[7807]) << 0x18) == 4) {
            if ((uint(c2da_mem[7776]) | uint(c2da_mem[7777]) << 0x8 | uint(c2da_mem[7778]) << 0x10 | uint(c2da_mem[7779]) << 0x18) != 0u) {
                if (host_framecount == int(uint(c2da_mem[7792]) | uint(c2da_mem[7793]) << 0x8 | uint(c2da_mem[7794]) << 0x10 | uint(c2da_mem[7795]) << 0x18)) {
                    return 0
                }
                let c2da_fresh7 : uint = uint(host_framecount)
                c2da_mem[7792] = uint8(c2da_fresh7)
                c2da_mem[7793] = uint8(c2da_fresh7 >> 0x8)
                c2da_mem[7794] = uint8(c2da_fresh7 >> 0x10)
                c2da_mem[7795] = uint8(c2da_fresh7 >> 0x18)
                if (host_framecount == int(uint(c2da_mem[7796]) | uint(c2da_mem[7797]) << 0x8 | uint(c2da_mem[7798]) << 0x10 | uint(c2da_mem[7799]) << 0x18) + 1) {
                    let c2da_fresh8 : float = float(realtime)
                    let c2da_fresh9 : uint = float_bits_to_uint(c2da_fresh8)
                    c2da_mem[7800] = uint8(c2da_fresh9)
                    c2da_mem[7801] = uint8(c2da_fresh9 >> 0x8)
                    c2da_mem[7802] = uint8(c2da_fresh9 >> 0x10)
                    c2da_mem[7803] = uint8(c2da_fresh9 >> 0x18)
                }
            } elif (uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) <= uint64_bits_to_double(uint64(uint(c2da_mem[768 + 0 * 8]) | uint(c2da_mem[768 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 3]) << 0x18) | uint64(uint(c2da_mem[768 + 0 * 8 + 4]) | uint(c2da_mem[768 + 0 * 8 + 5]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 6]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 7]) << 0x18) << 0x20)) {
                return 0
            }
        }
        c2da_lin_fread(5380, 4ul, 1ul, uint64(int(uint(c2da_mem[7784]) | uint(c2da_mem[7785]) << 0x8 | uint(c2da_mem[7786]) << 0x10 | uint(c2da_mem[7787]) << 0x18)))
        let c2da_fresh10 : float = uint_bits_to_float(uint(c2da_mem[628 + 0 * 12 + 0 * 4]) | uint(c2da_mem[628 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[628 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[628 + 0 * 12 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh11 : uint = float_bits_to_uint(c2da_fresh10)
        c2da_mem[628 + 1 * 12 + 0 * 4] = uint8(c2da_fresh11)
        c2da_mem[628 + 1 * 12 + 0 * 4 + 1] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[628 + 1 * 12 + 0 * 4 + 2] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[628 + 1 * 12 + 0 * 4 + 3] = uint8(c2da_fresh11 >> 0x18)
        let c2da_fresh12 : float = uint_bits_to_float(uint(c2da_mem[628 + 0 * 12 + 1 * 4]) | uint(c2da_mem[628 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[628 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[628 + 0 * 12 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh13 : uint = float_bits_to_uint(c2da_fresh12)
        c2da_mem[628 + 1 * 12 + 1 * 4] = uint8(c2da_fresh13)
        c2da_mem[628 + 1 * 12 + 1 * 4 + 1] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[628 + 1 * 12 + 1 * 4 + 2] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[628 + 1 * 12 + 1 * 4 + 3] = uint8(c2da_fresh13 >> 0x18)
        let c2da_fresh14 : float = uint_bits_to_float(uint(c2da_mem[628 + 0 * 12 + 2 * 4]) | uint(c2da_mem[628 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[628 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[628 + 0 * 12 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh15 : uint = float_bits_to_uint(c2da_fresh14)
        c2da_mem[628 + 1 * 12 + 2 * 4] = uint8(c2da_fresh15)
        c2da_mem[628 + 1 * 12 + 2 * 4 + 1] = uint8(c2da_fresh15 >> 0x8)
        c2da_mem[628 + 1 * 12 + 2 * 4 + 2] = uint8(c2da_fresh15 >> 0x10)
        c2da_mem[628 + 1 * 12 + 2 * 4 + 3] = uint8(c2da_fresh15 >> 0x18)
        for (i in range(0, 3)) {
            r = int(c2da_lin_fread(c2da_fp, 4ul, 1ul, uint64(int(uint(c2da_mem[7784]) | uint(c2da_mem[7785]) << 0x8 | uint(c2da_mem[7786]) << 0x10 | uint(c2da_mem[7787]) << 0x18))))
            let c2da_fresh16 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18))
            let c2da_fresh17 : uint = float_bits_to_uint(c2da_fresh16)
            c2da_mem[628 + 0 * 12 + i * 4] = uint8(c2da_fresh17)
            c2da_mem[628 + 0 * 12 + i * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
            c2da_mem[628 + 0 * 12 + i * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
            c2da_mem[628 + 0 * 12 + i * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
        }
        let c2da_fresh18 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18))
        let c2da_fresh19 : uint = uint(c2da_fresh18)
        c2da_mem[5380] = uint8(c2da_fresh19)
        c2da_mem[5381] = uint8(c2da_fresh19 >> 0x8)
        c2da_mem[5382] = uint8(c2da_fresh19 >> 0x10)
        c2da_mem[5383] = uint8(c2da_fresh19 >> 0x18)
        if (int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18) > 8000) {
            Sys_Error(697251, [])
        }
        r = int(c2da_lin_fread(int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18), uint64(int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18)), 1ul, uint64(int(uint(c2da_mem[7784]) | uint(c2da_mem[7785]) << 0x8 | uint(c2da_mem[7786]) << 0x10 | uint(c2da_mem[7787]) << 0x18))))
        if (r != 1) {
            CL_StopPlayback()
            return 0
        }
        return 1
    }
    while (true) {
        r = NET_GetMessage(int(uint(c2da_mem[7808]) | uint(c2da_mem[7809]) << 0x8 | uint(c2da_mem[7810]) << 0x10 | uint(c2da_mem[7811]) << 0x18))
        if (r != 1 && r != 2) {
            return r
        }
        var c2da_fresh21 : int = 0
        if (int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18) == 1) {
            let c2da_fresh20 : int = int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18) + 0
            if (int(c2da_mem[c2da_fresh20]) == 1) {
                c2da_fresh21 = 1
            }
        }
        if (c2da_fresh21 != 0) {
            Con_Printf(697277, [])
        } else {
            break
        }
    }
    if ((uint(c2da_mem[7768]) | uint(c2da_mem[7769]) << 0x8 | uint(c2da_mem[7770]) << 0x10 | uint(c2da_mem[7771]) << 0x18) != 0u) {
        CL_WriteDemoMessage()
    }
    return r
}
[sideeffects]
def private CL_WriteDemoMessage_c2da_frame(c2da_fp : int) {
    let c2da_fresh22 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18))
    let c2da_fresh23 : uint = uint(c2da_fresh22)
    c2da_mem[c2da_fp] = uint8(c2da_fresh23)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh23 >> 0x18)
    c2da_lin_fwrite(c2da_fp, 4ul, 1ul, uint64(int(uint(c2da_mem[7784]) | uint(c2da_mem[7785]) << 0x8 | uint(c2da_mem[7786]) << 0x10 | uint(c2da_mem[7787]) << 0x18)))
    for (i_0 in range(0, 3)) {
        let c2da_fresh24 : float = invoke(c2da_fn_table1[LittleFloat], uint_bits_to_float(uint(c2da_mem[652 + i_0 * 4]) | uint(c2da_mem[652 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + i_0 * 4 + 3]) << 0x18))
        let c2da_fresh25 : uint = float_bits_to_uint(c2da_fresh24)
        c2da_mem[c2da_fp + 16] = uint8(c2da_fresh25)
        c2da_mem[c2da_fp + 17] = uint8(c2da_fresh25 >> 0x8)
        c2da_mem[c2da_fp + 18] = uint8(c2da_fresh25 >> 0x10)
        c2da_mem[c2da_fp + 19] = uint8(c2da_fresh25 >> 0x18)
        c2da_lin_fwrite(c2da_fp + 16, 4ul, 1ul, uint64(int(uint(c2da_mem[7784]) | uint(c2da_mem[7785]) << 0x8 | uint(c2da_mem[7786]) << 0x10 | uint(c2da_mem[7787]) << 0x18)))
    }
    c2da_lin_fwrite(int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18), uint64(int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18)), 1ul, uint64(int(uint(c2da_mem[7784]) | uint(c2da_mem[7785]) << 0x8 | uint(c2da_mem[7786]) << 0x10 | uint(c2da_mem[7787]) << 0x18)))
    c2da_std_fflush(uint64(int(uint(c2da_mem[7784]) | uint(c2da_mem[7785]) << 0x8 | uint(c2da_mem[7786]) << 0x10 | uint(c2da_mem[7787]) << 0x18)))
    return
}
[sideeffects]
def private CL_Record_f_c2da_frame(c2da_fp : int) {
    var c : int
    var track : int
    if (uint(cmd_source) != 1u) {
        return
    }
    c = Cmd_Argc()
    if (c != 2 && c != 3 && c != 4) {
        Con_Printf(697348, [])
        return
    }
    if (c2da_lin_strstr(int(Cmd_Argv(1)), 697386) != 0) {
        Con_Printf(697389, [])
        return
    }
    if (c == 2 && (uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 2u) {
        Con_Printf(697426, [])
        return
    }
    if (c == 4) {
        track = c2da_lin_atoi(int(Cmd_Argv(3)))
        Con_Printf(697528, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[7780]) | uint(c2da_mem[7781]) << 0x8 | uint(c2da_mem[7782]) << 0x10 | uint(c2da_mem[7783]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    } else {
        track = -1
    }
    c2da_lin_snprintf(c2da_fp, 2147483647ul, 697552, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 5392ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(Cmd_Argv(1)))])
    if (c > 2) {
        Cmd_ExecuteString(va(697558, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(Cmd_Argv(2)))]), 1u)
    }
    COM_DefaultExtension(c2da_fp, 697565)
    Con_Printf(697570, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    let c2da_fresh29 : int = c2da_lin_fopen(c2da_fp, 697588)
    let c2da_fresh30 : uint = uint(c2da_fresh29)
    c2da_mem[7784] = uint8(c2da_fresh30)
    c2da_mem[7785] = uint8(c2da_fresh30 >> 0x8)
    c2da_mem[7786] = uint8(c2da_fresh30 >> 0x10)
    c2da_mem[7787] = uint8(c2da_fresh30 >> 0x18)
    c2da_mem[7788] = 0u8
    c2da_mem[7789] = 0u8
    c2da_mem[7790] = 0u8
    c2da_mem[7791] = 0u8
    if (int(uint(c2da_mem[7784]) | uint(c2da_mem[7785]) << 0x8 | uint(c2da_mem[7786]) << 0x10 | uint(c2da_mem[7787]) << 0x18) == 0) {
        Con_Printf(697591, [])
        return
    }
    let c2da_fresh31 : uint = uint(track)
    c2da_mem[7780] = uint8(c2da_fresh31)
    c2da_mem[7781] = uint8(c2da_fresh31 >> 0x8)
    c2da_mem[7782] = uint8(c2da_fresh31 >> 0x10)
    c2da_mem[7783] = uint8(c2da_fresh31 >> 0x18)
    c2da_lin_printf(uint64(int(uint(c2da_mem[7784]) | uint(c2da_mem[7785]) << 0x8 | uint(c2da_mem[7786]) << 0x10 | uint(c2da_mem[7787]) << 0x18)), 697614, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[7780]) | uint(c2da_mem[7781]) << 0x8 | uint(c2da_mem[7782]) << 0x10 | uint(c2da_mem[7783]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    let c2da_fresh32 : uint = 1u
    let c2da_fresh33 : uint = c2da_fresh32
    c2da_mem[7768] = uint8(c2da_fresh33)
    c2da_mem[7769] = uint8(c2da_fresh33 >> 0x8)
    c2da_mem[7770] = uint8(c2da_fresh33 >> 0x10)
    c2da_mem[7771] = uint8(c2da_fresh33 >> 0x18)
    return
}
[sideeffects]
def private CL_PlayDemo_f_c2da_frame(c2da_fp : int) {
    var c_0 : int
    var neg : uint = 0u
    if (uint(cmd_source) != 1u) {
        return
    }
    if (Cmd_Argc() != 2) {
        Con_Printf(697618, [])
        return
    }
    CL_Disconnect()
    c2da_lin_strcpy(c2da_fp, int(Cmd_Argv(1)))
    COM_DefaultExtension(c2da_fp, 697565)
    Con_Printf(697650, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    COM_FOpenFile(c2da_fp, 7784)
    if (int(uint(c2da_mem[7784]) | uint(c2da_mem[7785]) << 0x8 | uint(c2da_mem[7786]) << 0x10 | uint(c2da_mem[7787]) << 0x18) == 0) {
        Con_Printf(697591, [])
        let c2da_fresh34 : int = -1
        let c2da_fresh35 : uint = uint(c2da_fresh34)
        c2da_mem[7636] = uint8(c2da_fresh35)
        c2da_mem[7637] = uint8(c2da_fresh35 >> 0x8)
        c2da_mem[7638] = uint8(c2da_fresh35 >> 0x10)
        c2da_mem[7639] = uint8(c2da_fresh35 >> 0x18)
        return
    }
    let c2da_fresh36 : uint = 1u
    let c2da_fresh37 : uint = c2da_fresh36
    c2da_mem[7772] = uint8(c2da_fresh37)
    c2da_mem[7773] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[7774] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[7775] = uint8(c2da_fresh37 >> 0x18)
    let c2da_fresh38 : uint = 2u
    let c2da_fresh39 : uint = c2da_fresh38
    c2da_mem[5520] = uint8(c2da_fresh39)
    c2da_mem[5521] = uint8(c2da_fresh39 >> 0x8)
    c2da_mem[5522] = uint8(c2da_fresh39 >> 0x10)
    c2da_mem[5523] = uint8(c2da_fresh39 >> 0x18)
    let c2da_fresh40 : int = 0
    let c2da_fresh41 : uint = uint(c2da_fresh40)
    c2da_mem[7780] = uint8(c2da_fresh41)
    c2da_mem[7781] = uint8(c2da_fresh41 >> 0x8)
    c2da_mem[7782] = uint8(c2da_fresh41 >> 0x10)
    c2da_mem[7783] = uint8(c2da_fresh41 >> 0x18)
    while (true) {
        c_0 = c2da_lin_fgetc(uint64(int(uint(c2da_mem[7784]) | uint(c2da_mem[7785]) << 0x8 | uint(c2da_mem[7786]) << 0x10 | uint(c2da_mem[7787]) << 0x18)))
        if (c_0 == 10) {
            break
        }
        if (c_0 == 45) {
            neg = 1u
        } else {
            let c2da_fresh42 : int = int(uint(c2da_mem[7780]) | uint(c2da_mem[7781]) << 0x8 | uint(c2da_mem[7782]) << 0x10 | uint(c2da_mem[7783]) << 0x18) * 10 + (c_0 - 48)
            let c2da_fresh43 : uint = uint(c2da_fresh42)
            c2da_mem[7780] = uint8(c2da_fresh43)
            c2da_mem[7781] = uint8(c2da_fresh43 >> 0x8)
            c2da_mem[7782] = uint8(c2da_fresh43 >> 0x10)
            c2da_mem[7783] = uint8(c2da_fresh43 >> 0x18)
        }
    }
    if (neg != 0u) {
        let c2da_fresh44 : int = -int(uint(c2da_mem[7780]) | uint(c2da_mem[7781]) << 0x8 | uint(c2da_mem[7782]) << 0x10 | uint(c2da_mem[7783]) << 0x18)
        let c2da_fresh45 : uint = uint(c2da_fresh44)
        c2da_mem[7780] = uint8(c2da_fresh45)
        c2da_mem[7781] = uint8(c2da_fresh45 >> 0x8)
        c2da_mem[7782] = uint8(c2da_fresh45 >> 0x10)
        c2da_mem[7783] = uint8(c2da_fresh45 >> 0x18)
    }
    return
}

// This unit's static data, at heap offset 697216.
let private c2da_lin_static_cl_demo_seg = fixed_array<int>(697216, 496)
let private c2da_lin_static_cl_demo = fixed_array<uint64>(0x656d617266206925ul, 0x2066312e35252073ul, 0x2073646e6f636573ul, 0x70662066312e3525ul, 0x206f6d6544000a73ul, 0x206567617373656dul, 0x534d5f58414d203eul, 0x2d2d3c004e454c47ul, 0x2072657672657320ul, 0x6e65696c63206f74ul, 0x6c617065656b2074ul, 0x746f4e000a657669ul, 0x6964726f63657220ul, 0x6d6564206120676eul, 0x706d6f43000a2e6ful, 0x656420646574656cul, 0x6f636572000a6f6dul, 0x6f6d65643c206472ul, 0x3c5b203e656d616eul, 0x64635b203e70616dul, 0x5d5d6b6361727420ul, 0x6c6552002e2e000aul, 0x6170206576697461ul, 0x2073656d616e6874ul, 0x20746f6e20657261ul, 0x2e6465776f6c6c61ul, 0x6f6e206e6143000aul, 0x64726f6365722074ul, 0x6165726c61202d20ul, 0x656e6e6f63207964ul, 0x206f742064657463ul, 0x430a726576726573ul, 0x656420746e65696cul, 0x726f636572206f6dul, 0x73756d20676e6964ul, 0x6174732065622074ul, 0x6665622064657472ul, 0x6e6e6f632065726ful, 0xa676e69746365ul, 0x20676e6963726f46ul, 0x6b63617274204443ul, 0xa6925206f7420ul, 0x616d0073252f7325ul, 0x65642e0073252070ul, 0x64726f636572006dul, 0x25206f7420676e69ul, 0x45006277000a2e73ul, 0x6f63203a524f5252ul, 0x6f2074276e646c75ul, 0x6925000a2e6e6570ul, 0x3c2079616c70000aul, 0x656d616e6f6d6564ul, 0x79616c70203a203eul, 0x6f6d656420612073ul, 0x6e6979616c50000aul, 0x66206f6d65642067ul, 0xa2e7325206d6f72ul, 0x6d6564656d697400ul, 0x6e6f6d65643c206ful, 0x67203a203e656d61ul, 0x6f6d656420737465ul, 0xa73646565707320ul)

[init]
def private c2da_lin_init_static_cl_demo() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_cl_demo_seg[s * 2]
        for (k in range(c2da_lin_static_cl_demo_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_cl_demo[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_cl_demo() {
    if (length(c2da_fn_table0) < 42) {
        resize(c2da_fn_table0, 42)
    }
    c2da_fn_table0[39] = @@CL_Stop_f
    c2da_fn_table0[38] = @@CL_Record_f
    c2da_fn_table0[40] = @@CL_PlayDemo_f
    c2da_fn_table0[41] = @@CL_TimeDemo_f
}

[init]
def private c2da_lin_relink_init_cl_demo() {
    c2da_relink_cl_demo()
}
