var noclip_anglehack : uint = default<uint>

[export, sideeffects]
def Host_InitCommands() {
    Cmd_AddCommand(715616, 60)
    Cmd_AddCommand(715623, 61)
    Cmd_AddCommand(715628, 62)
    Cmd_AddCommand(715632, 63)
    Cmd_AddCommand(715641, 64)
    Cmd_AddCommand(715645, 65)
    Cmd_AddCommand(715649, 66)
    Cmd_AddCommand(715657, 67)
    Cmd_AddCommand(715669, 68)
    Cmd_AddCommand(715677, 69)
    Cmd_AddCommand(715687, 70)
    Cmd_AddCommand(715692, 71)
    Cmd_AddCommand(715699, 72)
    Cmd_AddCommand(715707, 73)
    Cmd_AddCommand(715711, 74)
    Cmd_AddCommand(715720, 75)
    Cmd_AddCommand(715725, 76)
    Cmd_AddCommand(715731, 77)
    Cmd_AddCommand(715736, 78)
    Cmd_AddCommand(715742, 79)
    Cmd_AddCommand(715748, 80)
    Cmd_AddCommand(715754, 81)
    Cmd_AddCommand(715763, 82)
    Cmd_AddCommand(715768, 83)
    Cmd_AddCommand(715773, 84)
    Cmd_AddCommand(715778, 85)
    Cmd_AddCommand(715783, 86)
    Cmd_AddCommand(715788, 87)
    Cmd_AddCommand(715799, 88)
    Cmd_AddCommand(715805, 89)
    Cmd_AddCommand(715814, 90)
    Cmd_AddCommand(715824, 91)
    Cmd_AddCommand(715834, 92)
    Cmd_AddCommand(715843, 93)
    Cmd_AddCommand(715852, 94)
    return
}
[export, sideeffects]
def Host_Viewprev_f() {
    var e : int
    var m : int
    e = FindViewthing()
    if (e == 0) {
        return
    }
    let c2da_fresh0 : int = 808 + int(uint_bits_to_float(uint(c2da_mem[e + 108]) | uint(c2da_mem[e + 109]) << 0x8 | uint(c2da_mem[e + 110]) << 0x10 | uint(c2da_mem[e + 111]) << 0x18)) * 8
    m = int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18)
    let c2da_fresh1 : float = uint_bits_to_float(uint(c2da_mem[e + 228]) | uint(c2da_mem[e + 229]) << 0x8 | uint(c2da_mem[e + 230]) << 0x10 | uint(c2da_mem[e + 231]) << 0x18) - 1.0
    let c2da_fresh2 : uint = float_bits_to_uint(c2da_fresh1)
    c2da_mem[e + 228] = uint8(c2da_fresh2)
    c2da_mem[e + 229] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[e + 230] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[e + 231] = uint8(c2da_fresh2 >> 0x18)
    if (c2da_fresh1 < 0.0) {
        let c2da_fresh3 : float = 0.0
        let c2da_fresh4 : uint = float_bits_to_uint(c2da_fresh3)
        c2da_mem[e + 228] = uint8(c2da_fresh4)
        c2da_mem[e + 229] = uint8(c2da_fresh4 >> 0x8)
        c2da_mem[e + 230] = uint8(c2da_fresh4 >> 0x10)
        c2da_mem[e + 231] = uint8(c2da_fresh4 >> 0x18)
    }
    PrintFrameName(m, int(uint_bits_to_float(uint(c2da_mem[e + 228]) | uint(c2da_mem[e + 229]) << 0x8 | uint(c2da_mem[e + 230]) << 0x10 | uint(c2da_mem[e + 231]) << 0x18)))
    return
}
[export, sideeffects]
def PrintFrameName(var m_0 : int; var frame : int) {
    var hdr : int
    var pframedesc : int
    hdr = Mod_Extradata(m_0)
    if (hdr == 0) {
        return
    }
    pframedesc = hdr + 16 + frame * 32
    Con_Printf(715859, [C2daVaArg(tag = 1, i64 = int64(frame), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pframedesc + 16))])
    return
}
[export, sideeffects]
def FindViewthing() : int {
    var i : int
    var e_0 : int
    i = 0
    while (i < int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        e_0 = EDICT_NUM(i)
        if (c2da_lin_strcmp(int(pr_strings + int(uint(c2da_mem[e_0 + 220]) | uint(c2da_mem[e_0 + 221]) << 0x8 | uint(c2da_mem[e_0 + 222]) << 0x10 | uint(c2da_mem[e_0 + 223]) << 0x18)), 715873) == 0) {
            return e_0
        }
        i++
    }
    Con_Printf(715883, [])
    return 0
}
[export, sideeffects]
def Host_Viewnext_f() {
    var e_1 : int
    var m_1 : int
    e_1 = FindViewthing()
    if (e_1 == 0) {
        return
    }
    let c2da_fresh5 : int = 808 + int(uint_bits_to_float(uint(c2da_mem[e_1 + 108]) | uint(c2da_mem[e_1 + 109]) << 0x8 | uint(c2da_mem[e_1 + 110]) << 0x10 | uint(c2da_mem[e_1 + 111]) << 0x18)) * 8
    m_1 = int(uint(c2da_mem[c2da_fresh5]) | uint(c2da_mem[c2da_fresh5 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh5 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh5 + 3]) << 0x18)
    let c2da_fresh6 : float = uint_bits_to_float(uint(c2da_mem[e_1 + 228]) | uint(c2da_mem[e_1 + 229]) << 0x8 | uint(c2da_mem[e_1 + 230]) << 0x10 | uint(c2da_mem[e_1 + 231]) << 0x18) + 1.0
    let c2da_fresh7 : uint = float_bits_to_uint(c2da_fresh6)
    c2da_mem[e_1 + 228] = uint8(c2da_fresh7)
    c2da_mem[e_1 + 229] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[e_1 + 230] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[e_1 + 231] = uint8(c2da_fresh7 >> 0x18)
    let c2da_fresh10 : int = int(uint(c2da_mem[m_1 + 72]) | uint(c2da_mem[m_1 + 73]) << 0x8 | uint(c2da_mem[m_1 + 74]) << 0x10 | uint(c2da_mem[m_1 + 75]) << 0x18)
    if (c2da_fresh6 >= float(c2da_fresh10)) {
        let c2da_fresh8 : float = float(c2da_fresh10 - 1)
        let c2da_fresh9 : uint = float_bits_to_uint(c2da_fresh8)
        c2da_mem[e_1 + 228] = uint8(c2da_fresh9)
        c2da_mem[e_1 + 229] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[e_1 + 230] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[e_1 + 231] = uint8(c2da_fresh9 >> 0x18)
    }
    PrintFrameName(m_1, int(uint_bits_to_float(uint(c2da_mem[e_1 + 228]) | uint(c2da_mem[e_1 + 229]) << 0x8 | uint(c2da_mem[e_1 + 230]) << 0x10 | uint(c2da_mem[e_1 + 231]) << 0x18)))
    return
}
[export, sideeffects]
def Host_Viewframe_f() {
    var e_2 : int
    var f : int
    var m_2 : int
    e_2 = FindViewthing()
    if (e_2 == 0) {
        return
    }
    let c2da_fresh11 : int = 808 + int(uint_bits_to_float(uint(c2da_mem[e_2 + 108]) | uint(c2da_mem[e_2 + 109]) << 0x8 | uint(c2da_mem[e_2 + 110]) << 0x10 | uint(c2da_mem[e_2 + 111]) << 0x18)) * 8
    m_2 = int(uint(c2da_mem[c2da_fresh11]) | uint(c2da_mem[c2da_fresh11 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh11 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh11 + 3]) << 0x18)
    f = c2da_lin_atoi(int(Cmd_Argv(1)))
    let c2da_fresh14 : int = int(uint(c2da_mem[m_2 + 72]) | uint(c2da_mem[m_2 + 73]) << 0x8 | uint(c2da_mem[m_2 + 74]) << 0x10 | uint(c2da_mem[m_2 + 75]) << 0x18)
    if (f >= c2da_fresh14) {
        f = c2da_fresh14 - 1
    }
    let c2da_fresh12 : float = float(f)
    let c2da_fresh13 : uint = float_bits_to_uint(c2da_fresh12)
    c2da_mem[e_2 + 228] = uint8(c2da_fresh13)
    c2da_mem[e_2 + 229] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[e_2 + 230] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[e_2 + 231] = uint8(c2da_fresh13 >> 0x18)
    return
}
[export, sideeffects]
def Host_Viewmodel_f() {
    var e_3 : int
    var m_3 : int
    e_3 = FindViewthing()
    if (e_3 == 0) {
        return
    }
    m_3 = Mod_ForName(Cmd_Argv(1), 0u)
    if (m_3 == 0) {
        Con_Printf(715904, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(Cmd_Argv(1)))])
        return
    }
    let c2da_fresh15 : float = 0.0
    let c2da_fresh16 : uint = float_bits_to_uint(c2da_fresh15)
    c2da_mem[e_3 + 228] = uint8(c2da_fresh16)
    c2da_mem[e_3 + 229] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[e_3 + 230] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[e_3 + 231] = uint8(c2da_fresh16 >> 0x18)
    let c2da_fresh17 : int = 808 + int(uint_bits_to_float(uint(c2da_mem[e_3 + 108]) | uint(c2da_mem[e_3 + 109]) << 0x8 | uint(c2da_mem[e_3 + 110]) << 0x10 | uint(c2da_mem[e_3 + 111]) << 0x18)) * 8
    let c2da_fresh18 : uint = uint(m_3)
    c2da_mem[c2da_fresh17] = uint8(c2da_fresh18)
    c2da_mem[c2da_fresh17 + 1] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[c2da_fresh17 + 2] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[c2da_fresh17 + 3] = uint8(c2da_fresh18 >> 0x18)
    c2da_mem[c2da_fresh17 + 4] = 0u8
    c2da_mem[c2da_fresh17 + 5] = 0u8
    c2da_mem[c2da_fresh17 + 6] = 0u8
    c2da_mem[c2da_fresh17 + 7] = 0u8
    return
}
[export, sideeffects]
def Host_Stopdemo_f() {
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 0u) {
        return
    }
    if ((uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) == 0u) {
        return
    }
    CL_StopPlayback()
    CL_Disconnect()
    return
}
[export, sideeffects]
def Host_Demos_f() {
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 0u) {
        return
    }
    if (int(uint(c2da_mem[7636]) | uint(c2da_mem[7637]) << 0x8 | uint(c2da_mem[7638]) << 0x10 | uint(c2da_mem[7639]) << 0x18) == -1) {
        let c2da_fresh19 : int = 1
        let c2da_fresh20 : uint = uint(c2da_fresh19)
        c2da_mem[7636] = uint8(c2da_fresh20)
        c2da_mem[7637] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[7638] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[7639] = uint8(c2da_fresh20 >> 0x18)
    }
    CL_Disconnect_f()
    CL_NextDemo()
    return
}
[export, sideeffects]
def Host_Startdemos_f() {
    var c : int
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 0u) {
        if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u) {
            Cbuf_AddText(715919)
        }
        return
    }
    c = Cmd_Argc() - 1
    if (c > 8) {
        Con_Printf(715930, [C2daVaArg(tag = 1, i64 = 8l, f64 = 0.0lf, raw = 0x0)])
        c = 8
    }
    Con_Printf(715956, [C2daVaArg(tag = 1, i64 = int64(c), f64 = 0.0lf, raw = 0x0)])
    for (i_0 in range(1, c + 1)) {
        c2da_lin_strncpy(7640 + (i_0 - 1) * 16, int(Cmd_Argv(i_0)), 16ul - 1ul)
    }
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u && int(uint(c2da_mem[7636]) | uint(c2da_mem[7637]) << 0x8 | uint(c2da_mem[7638]) << 0x10 | uint(c2da_mem[7639]) << 0x18) != -1 && (uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) == 0u) {
        let c2da_fresh21 : int = 0
        let c2da_fresh22 : uint = uint(c2da_fresh21)
        c2da_mem[7636] = uint8(c2da_fresh22)
        c2da_mem[7637] = uint8(c2da_fresh22 >> 0x8)
        c2da_mem[7638] = uint8(c2da_fresh22 >> 0x10)
        c2da_mem[7639] = uint8(c2da_fresh22 >> 0x18)
        CL_NextDemo()
    } else {
        let c2da_fresh23 : int = -1
        let c2da_fresh24 : uint = uint(c2da_fresh23)
        c2da_mem[7636] = uint8(c2da_fresh24)
        c2da_mem[7637] = uint8(c2da_fresh24 >> 0x8)
        c2da_mem[7638] = uint8(c2da_fresh24 >> 0x10)
        c2da_mem[7639] = uint8(c2da_fresh24 >> 0x18)
    }
    return
}
[export, sideeffects]
def Host_Give_f() {
    var c2da_fresh25 : int
    var t : int
    var v : int
    var w : int
    var val : int
    if (uint(cmd_source) == 1u) {
        Cmd_ForwardToServer()
        return
    }
    if (uint_bits_to_float(uint(c2da_mem[pr_global_struct + 140]) | uint(c2da_mem[pr_global_struct + 141]) << 0x8 | uint(c2da_mem[pr_global_struct + 142]) << 0x10 | uint(c2da_mem[pr_global_struct + 143]) << 0x18) != 0.0 && (uint(c2da_mem[host_client + 12]) | uint(c2da_mem[host_client + 13]) << 0x8 | uint(c2da_mem[host_client + 14]) << 0x10 | uint(c2da_mem[host_client + 15]) << 0x18) == 0u) {
        return
    }
    t = Cmd_Argv(1)
    v = c2da_lin_atoi(int(Cmd_Argv(2)))
    c2da_fresh25 = int(int8(c2da_mem[t + 0]))
    if (c2da_fresh25 < 57) {
        if (c2da_fresh25 >= 48 && c2da_fresh25 <= 56) {
            goto c2da_fresh25 - 44
        }
    } else {
        if (c2da_fresh25 < 109) {
            if (c2da_fresh25 == 57) {
                goto label 0
            } elif (c2da_fresh25 == 99) {
                goto label 3
            } elif (c2da_fresh25 == 104) {
                goto label 2
            } elif (c2da_fresh25 == 108) {
                goto label 1
            }
        } else {
            if (c2da_fresh25 >= 109 && c2da_fresh25 <= 115) {
                goto c2da_fresh25 - 96
            }
        }
    }
    return
    label 15:
    label 17:
    return
    label 0:
    label 4:
    label 5:
    label 6:
    label 7:
    label 8:
    label 9:
    label 10:
    label 11:
    label 12:
    if (uint(hipnotic) != 0u) {
        if (int(int8(c2da_mem[t + 0])) == 54) {
            if (int(int8(c2da_mem[t + 1])) == 97) {
                let c2da_fresh26 : float = float(int(uint_bits_to_float(uint(c2da_mem[sv_player + 340]) | uint(c2da_mem[sv_player + 341]) << 0x8 | uint(c2da_mem[sv_player + 342]) << 0x10 | uint(c2da_mem[sv_player + 343]) << 0x18)) | 1 << 16)
                let c2da_fresh27 : uint = float_bits_to_uint(c2da_fresh26)
                c2da_mem[sv_player + 340] = uint8(c2da_fresh27)
                c2da_mem[sv_player + 341] = uint8(c2da_fresh27 >> 0x8)
                c2da_mem[sv_player + 342] = uint8(c2da_fresh27 >> 0x10)
                c2da_mem[sv_player + 343] = uint8(c2da_fresh27 >> 0x18)
            } else {
                let c2da_fresh28 : float = float(int(uint_bits_to_float(uint(c2da_mem[sv_player + 340]) | uint(c2da_mem[sv_player + 341]) << 0x8 | uint(c2da_mem[sv_player + 342]) << 0x10 | uint(c2da_mem[sv_player + 343]) << 0x18)) | 16)
                let c2da_fresh29 : uint = float_bits_to_uint(c2da_fresh28)
                c2da_mem[sv_player + 340] = uint8(c2da_fresh29)
                c2da_mem[sv_player + 341] = uint8(c2da_fresh29 >> 0x8)
                c2da_mem[sv_player + 342] = uint8(c2da_fresh29 >> 0x10)
                c2da_mem[sv_player + 343] = uint8(c2da_fresh29 >> 0x18)
            }
        } elif (int(int8(c2da_mem[t + 0])) == 57) {
            let c2da_fresh30 : float = float(int(uint_bits_to_float(uint(c2da_mem[sv_player + 340]) | uint(c2da_mem[sv_player + 341]) << 0x8 | uint(c2da_mem[sv_player + 342]) << 0x10 | uint(c2da_mem[sv_player + 343]) << 0x18)) | 1 << 23)
            let c2da_fresh31 : uint = float_bits_to_uint(c2da_fresh30)
            c2da_mem[sv_player + 340] = uint8(c2da_fresh31)
            c2da_mem[sv_player + 341] = uint8(c2da_fresh31 >> 0x8)
            c2da_mem[sv_player + 342] = uint8(c2da_fresh31 >> 0x10)
            c2da_mem[sv_player + 343] = uint8(c2da_fresh31 >> 0x18)
        } elif (int(int8(c2da_mem[t + 0])) == 48) {
            let c2da_fresh32 : float = float(int(uint_bits_to_float(uint(c2da_mem[sv_player + 340]) | uint(c2da_mem[sv_player + 341]) << 0x8 | uint(c2da_mem[sv_player + 342]) << 0x10 | uint(c2da_mem[sv_player + 343]) << 0x18)) | 1 << 7)
            let c2da_fresh33 : uint = float_bits_to_uint(c2da_fresh32)
            c2da_mem[sv_player + 340] = uint8(c2da_fresh33)
            c2da_mem[sv_player + 341] = uint8(c2da_fresh33 >> 0x8)
            c2da_mem[sv_player + 342] = uint8(c2da_fresh33 >> 0x10)
            c2da_mem[sv_player + 343] = uint8(c2da_fresh33 >> 0x18)
        } elif (int(int8(c2da_mem[t + 0])) >= 50) {
            let c2da_fresh34 : float = float(int(uint_bits_to_float(uint(c2da_mem[sv_player + 340]) | uint(c2da_mem[sv_player + 341]) << 0x8 | uint(c2da_mem[sv_player + 342]) << 0x10 | uint(c2da_mem[sv_player + 343]) << 0x18)) | 1 << int(int8(c2da_mem[t + 0])) - 50)
            let c2da_fresh35 : uint = float_bits_to_uint(c2da_fresh34)
            c2da_mem[sv_player + 340] = uint8(c2da_fresh35)
            c2da_mem[sv_player + 341] = uint8(c2da_fresh35 >> 0x8)
            c2da_mem[sv_player + 342] = uint8(c2da_fresh35 >> 0x10)
            c2da_mem[sv_player + 343] = uint8(c2da_fresh35 >> 0x18)
        }
    } elif (int(int8(c2da_mem[t + 0])) >= 50) {
        let c2da_fresh36 : float = float(int(uint_bits_to_float(uint(c2da_mem[sv_player + 340]) | uint(c2da_mem[sv_player + 341]) << 0x8 | uint(c2da_mem[sv_player + 342]) << 0x10 | uint(c2da_mem[sv_player + 343]) << 0x18)) | 1 << int(int8(c2da_mem[t + 0])) - 50)
        let c2da_fresh37 : uint = float_bits_to_uint(c2da_fresh36)
        c2da_mem[sv_player + 340] = uint8(c2da_fresh37)
        c2da_mem[sv_player + 341] = uint8(c2da_fresh37 >> 0x8)
        c2da_mem[sv_player + 342] = uint8(c2da_fresh37 >> 0x10)
        c2da_mem[sv_player + 343] = uint8(c2da_fresh37 >> 0x18)
    }
    return
    label 19:
    if (uint(rogue) != 0u) {
        val = GetEdictFieldValue(sv_player, 715976)
        if (val != 0) {
            let c2da_fresh38 : float = float(v)
            let c2da_fresh39 : uint = float_bits_to_uint(c2da_fresh38)
            c2da_mem[val] = uint8(c2da_fresh39)
            c2da_mem[val + 1] = uint8(c2da_fresh39 >> 0x8)
            c2da_mem[val + 2] = uint8(c2da_fresh39 >> 0x10)
            c2da_mem[val + 3] = uint8(c2da_fresh39 >> 0x18)
        }
    }
    let c2da_fresh40 : float = float(v)
    let c2da_fresh41 : uint = float_bits_to_uint(c2da_fresh40)
    c2da_mem[sv_player + 324] = uint8(c2da_fresh41)
    c2da_mem[sv_player + 325] = uint8(c2da_fresh41 >> 0x8)
    c2da_mem[sv_player + 326] = uint8(c2da_fresh41 >> 0x10)
    c2da_mem[sv_player + 327] = uint8(c2da_fresh41 >> 0x18)
    return
    label 14:
    if (uint(rogue) != 0u) {
        val = GetEdictFieldValue(sv_player, 715989)
        if (val != 0) {
            let c2da_fresh42 : float = float(v)
            let c2da_fresh43 : uint = float_bits_to_uint(c2da_fresh42)
            c2da_mem[val] = uint8(c2da_fresh43)
            c2da_mem[val + 1] = uint8(c2da_fresh43 >> 0x8)
            c2da_mem[val + 2] = uint8(c2da_fresh43 >> 0x10)
            c2da_mem[val + 3] = uint8(c2da_fresh43 >> 0x18)
            if (uint_bits_to_float(uint(c2da_mem[sv_player + 308]) | uint(c2da_mem[sv_player + 309]) << 0x8 | uint(c2da_mem[sv_player + 310]) << 0x10 | uint(c2da_mem[sv_player + 311]) << 0x18) <= 64.0) {
                let c2da_fresh44 : float = float(v)
                let c2da_fresh45 : uint = float_bits_to_uint(c2da_fresh44)
                c2da_mem[sv_player + 328] = uint8(c2da_fresh45)
                c2da_mem[sv_player + 329] = uint8(c2da_fresh45 >> 0x8)
                c2da_mem[sv_player + 330] = uint8(c2da_fresh45 >> 0x10)
                c2da_mem[sv_player + 331] = uint8(c2da_fresh45 >> 0x18)
            }
        }
    } else {
        let c2da_fresh46 : float = float(v)
        let c2da_fresh47 : uint = float_bits_to_uint(c2da_fresh46)
        c2da_mem[sv_player + 328] = uint8(c2da_fresh47)
        c2da_mem[sv_player + 329] = uint8(c2da_fresh47 >> 0x8)
        c2da_mem[sv_player + 330] = uint8(c2da_fresh47 >> 0x10)
        c2da_mem[sv_player + 331] = uint8(c2da_fresh47 >> 0x18)
    }
    return
    label 1:
    if (uint(rogue) != 0u) {
        val = GetEdictFieldValue(sv_player, 716001)
        if (val != 0) {
            let c2da_fresh48 : float = float(v)
            let c2da_fresh49 : uint = float_bits_to_uint(c2da_fresh48)
            c2da_mem[val] = uint8(c2da_fresh49)
            c2da_mem[val + 1] = uint8(c2da_fresh49 >> 0x8)
            c2da_mem[val + 2] = uint8(c2da_fresh49 >> 0x10)
            c2da_mem[val + 3] = uint8(c2da_fresh49 >> 0x18)
            if (uint_bits_to_float(uint(c2da_mem[sv_player + 308]) | uint(c2da_mem[sv_player + 309]) << 0x8 | uint(c2da_mem[sv_player + 310]) << 0x10 | uint(c2da_mem[sv_player + 311]) << 0x18) > 64.0) {
                let c2da_fresh50 : float = float(v)
                let c2da_fresh51 : uint = float_bits_to_uint(c2da_fresh50)
                c2da_mem[sv_player + 328] = uint8(c2da_fresh51)
                c2da_mem[sv_player + 329] = uint8(c2da_fresh51 >> 0x8)
                c2da_mem[sv_player + 330] = uint8(c2da_fresh51 >> 0x10)
                c2da_mem[sv_player + 331] = uint8(c2da_fresh51 >> 0x18)
            }
        }
    }
    return
    label 18:
    if (uint(rogue) != 0u) {
        val = GetEdictFieldValue(sv_player, 716017)
        if (val != 0) {
            let c2da_fresh52 : float = float(v)
            let c2da_fresh53 : uint = float_bits_to_uint(c2da_fresh52)
            c2da_mem[val] = uint8(c2da_fresh53)
            c2da_mem[val + 1] = uint8(c2da_fresh53 >> 0x8)
            c2da_mem[val + 2] = uint8(c2da_fresh53 >> 0x10)
            c2da_mem[val + 3] = uint8(c2da_fresh53 >> 0x18)
            if (uint_bits_to_float(uint(c2da_mem[sv_player + 308]) | uint(c2da_mem[sv_player + 309]) << 0x8 | uint(c2da_mem[sv_player + 310]) << 0x10 | uint(c2da_mem[sv_player + 311]) << 0x18) <= 64.0) {
                let c2da_fresh54 : float = float(v)
                let c2da_fresh55 : uint = float_bits_to_uint(c2da_fresh54)
                c2da_mem[sv_player + 332] = uint8(c2da_fresh55)
                c2da_mem[sv_player + 333] = uint8(c2da_fresh55 >> 0x8)
                c2da_mem[sv_player + 334] = uint8(c2da_fresh55 >> 0x10)
                c2da_mem[sv_player + 335] = uint8(c2da_fresh55 >> 0x18)
            }
        }
    } else {
        let c2da_fresh56 : float = float(v)
        let c2da_fresh57 : uint = float_bits_to_uint(c2da_fresh56)
        c2da_mem[sv_player + 332] = uint8(c2da_fresh57)
        c2da_mem[sv_player + 333] = uint8(c2da_fresh57 >> 0x8)
        c2da_mem[sv_player + 334] = uint8(c2da_fresh57 >> 0x10)
        c2da_mem[sv_player + 335] = uint8(c2da_fresh57 >> 0x18)
    }
    return
    label 13:
    if (uint(rogue) != 0u) {
        val = GetEdictFieldValue(sv_player, 716031)
        if (val != 0) {
            let c2da_fresh58 : float = float(v)
            let c2da_fresh59 : uint = float_bits_to_uint(c2da_fresh58)
            c2da_mem[val] = uint8(c2da_fresh59)
            c2da_mem[val + 1] = uint8(c2da_fresh59 >> 0x8)
            c2da_mem[val + 2] = uint8(c2da_fresh59 >> 0x10)
            c2da_mem[val + 3] = uint8(c2da_fresh59 >> 0x18)
            if (uint_bits_to_float(uint(c2da_mem[sv_player + 308]) | uint(c2da_mem[sv_player + 309]) << 0x8 | uint(c2da_mem[sv_player + 310]) << 0x10 | uint(c2da_mem[sv_player + 311]) << 0x18) > 64.0) {
                let c2da_fresh60 : float = float(v)
                let c2da_fresh61 : uint = float_bits_to_uint(c2da_fresh60)
                c2da_mem[sv_player + 332] = uint8(c2da_fresh61)
                c2da_mem[sv_player + 333] = uint8(c2da_fresh61 >> 0x8)
                c2da_mem[sv_player + 334] = uint8(c2da_fresh61 >> 0x10)
                c2da_mem[sv_player + 335] = uint8(c2da_fresh61 >> 0x18)
            }
        }
    }
    return
    label 2:
    let c2da_fresh62 : float = float(v)
    let c2da_fresh63 : uint = float_bits_to_uint(c2da_fresh62)
    c2da_mem[sv_player + 300] = uint8(c2da_fresh63)
    c2da_mem[sv_player + 301] = uint8(c2da_fresh63 >> 0x8)
    c2da_mem[sv_player + 302] = uint8(c2da_fresh63 >> 0x10)
    c2da_mem[sv_player + 303] = uint8(c2da_fresh63 >> 0x18)
    return
    label 3:
    if (uint(rogue) != 0u) {
        val = GetEdictFieldValue(sv_player, 716050)
        if (val != 0) {
            let c2da_fresh64 : float = float(v)
            let c2da_fresh65 : uint = float_bits_to_uint(c2da_fresh64)
            c2da_mem[val] = uint8(c2da_fresh65)
            c2da_mem[val + 1] = uint8(c2da_fresh65 >> 0x8)
            c2da_mem[val + 2] = uint8(c2da_fresh65 >> 0x10)
            c2da_mem[val + 3] = uint8(c2da_fresh65 >> 0x18)
            if (uint_bits_to_float(uint(c2da_mem[sv_player + 308]) | uint(c2da_mem[sv_player + 309]) << 0x8 | uint(c2da_mem[sv_player + 310]) << 0x10 | uint(c2da_mem[sv_player + 311]) << 0x18) <= 64.0) {
                let c2da_fresh66 : float = float(v)
                let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
                c2da_mem[sv_player + 336] = uint8(c2da_fresh67)
                c2da_mem[sv_player + 337] = uint8(c2da_fresh67 >> 0x8)
                c2da_mem[sv_player + 338] = uint8(c2da_fresh67 >> 0x10)
                c2da_mem[sv_player + 339] = uint8(c2da_fresh67 >> 0x18)
            }
        }
    } else {
        let c2da_fresh68 : float = float(v)
        let c2da_fresh69 : uint = float_bits_to_uint(c2da_fresh68)
        c2da_mem[sv_player + 336] = uint8(c2da_fresh69)
        c2da_mem[sv_player + 337] = uint8(c2da_fresh69 >> 0x8)
        c2da_mem[sv_player + 338] = uint8(c2da_fresh69 >> 0x10)
        c2da_mem[sv_player + 339] = uint8(c2da_fresh69 >> 0x18)
    }
    return
    label 16:
    if (uint(rogue) != 0u) {
        val = GetEdictFieldValue(sv_player, 716062)
        if (val != 0) {
            let c2da_fresh70 : float = float(v)
            let c2da_fresh71 : uint = float_bits_to_uint(c2da_fresh70)
            c2da_mem[val] = uint8(c2da_fresh71)
            c2da_mem[val + 1] = uint8(c2da_fresh71 >> 0x8)
            c2da_mem[val + 2] = uint8(c2da_fresh71 >> 0x10)
            c2da_mem[val + 3] = uint8(c2da_fresh71 >> 0x18)
            if (uint_bits_to_float(uint(c2da_mem[sv_player + 308]) | uint(c2da_mem[sv_player + 309]) << 0x8 | uint(c2da_mem[sv_player + 310]) << 0x10 | uint(c2da_mem[sv_player + 311]) << 0x18) > 64.0) {
                let c2da_fresh72 : float = float(v)
                let c2da_fresh73 : uint = float_bits_to_uint(c2da_fresh72)
                c2da_mem[sv_player + 336] = uint8(c2da_fresh73)
                c2da_mem[sv_player + 337] = uint8(c2da_fresh73 >> 0x8)
                c2da_mem[sv_player + 338] = uint8(c2da_fresh73 >> 0x10)
                c2da_mem[sv_player + 339] = uint8(c2da_fresh73 >> 0x18)
            }
        }
    }
    return
}
[export, sideeffects]
def Host_Savegame_f() {
    let c2da_saved_sp : int = c2da_lin_sp
    Host_Savegame_f_c2da_frame(c2da_lin_enter(304))
    c2da_lin_sp = c2da_saved_sp
}
var current_skill : int = default<int>

[export, sideeffects]
def Host_SavegameComment(var text : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    Host_SavegameComment_c2da_frame(text, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Host_Loadgame_f() {
    let c2da_saved_sp : int = c2da_lin_sp
    Host_Loadgame_f_c2da_frame(c2da_lin_enter(33072))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Host_Reconnect_f() {
    SCR_BeginLoadingPlaque()
    let c2da_fresh100 : int = 0
    let c2da_fresh101 : uint = uint(c2da_fresh100)
    c2da_mem[7804] = uint8(c2da_fresh101)
    c2da_mem[7805] = uint8(c2da_fresh101 >> 0x8)
    c2da_mem[7806] = uint8(c2da_fresh101 >> 0x10)
    c2da_mem[7807] = uint8(c2da_fresh101 >> 0x18)
    return
}
[export, sideeffects]
def Host_Ping_f() {
    var i_4 : int
    var total : float
    var client : int
    if (uint(cmd_source) == 1u) {
        Cmd_ForwardToServer()
        return
    }
    SV_ClientPrintf(716539, [])
    i_4 = 0
    client = svs.clients
    while (i_4 < svs.maxclients) {
        if ((uint(c2da_mem[client]) | uint(c2da_mem[client + 1]) << 0x8 | uint(c2da_mem[client + 2]) << 0x10 | uint(c2da_mem[client + 3]) << 0x18) == 0u) {
            i_4++
            client += 8288
            continue
        }
        total = 0.0
        for (j in range(0, 16)) {
            total = total + uint_bits_to_float(uint(c2da_mem[client + 8148 + j * 4]) | uint(c2da_mem[client + 8148 + j * 4 + 1]) << 0x8 | uint(c2da_mem[client + 8148 + j * 4 + 2]) << 0x10 | uint(c2da_mem[client + 8148 + j * 4 + 3]) << 0x18)
        }
        total /= 16.0
        SV_ClientPrintf(716559, [C2daVaArg(tag = 1, i64 = int64(int(total * 1000.0)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(client + 8112))])
        i_4++
        client += 8288
    }
    return
}
[export, sideeffects]
def Host_Kick_f() {
    var who : int
    var message : int
    var save : int
    var i_5 : int
    var byNumber : uint
    message = 0
    byNumber = 0u
    if (uint(cmd_source) == 1u) {
        if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u) {
            Cmd_ForwardToServer()
            return
        }
    } elif (uint_bits_to_float(uint(c2da_mem[pr_global_struct + 140]) | uint(c2da_mem[pr_global_struct + 141]) << 0x8 | uint(c2da_mem[pr_global_struct + 142]) << 0x10 | uint(c2da_mem[pr_global_struct + 143]) << 0x18) != 0.0 && (uint(c2da_mem[host_client + 12]) | uint(c2da_mem[host_client + 13]) << 0x8 | uint(c2da_mem[host_client + 14]) << 0x10 | uint(c2da_mem[host_client + 15]) << 0x18) == 0u) {
        return
    }
    save = host_client
    if (Cmd_Argc() > 2 && Q_strcmp(Cmd_Argv(1), 716567) == 0) {
        i_5 = int(Q_atof(Cmd_Argv(2)) - 1.0)
        if (i_5 < 0 || i_5 >= svs.maxclients) {
            return
        }
        let c2da_fresh102 : int = svs.clients + i_5 * 8288
        if ((uint(c2da_mem[c2da_fresh102]) | uint(c2da_mem[c2da_fresh102 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh102 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh102 + 3]) << 0x18) == 0u) {
            return
        }
        host_client = svs.clients + i_5 * 8288
        byNumber = 1u
    } else {
        i_5 = 0
        host_client = svs.clients
        while (i_5 < svs.maxclients) {
            if ((uint(c2da_mem[host_client]) | uint(c2da_mem[host_client + 1]) << 0x8 | uint(c2da_mem[host_client + 2]) << 0x10 | uint(c2da_mem[host_client + 3]) << 0x18) == 0u) {
                i_5++
                host_client = host_client + 8288
                continue
            }
            if (Q_strcasecmp(host_client + 8112, Cmd_Argv(1)) == 0) {
                break
            }
            i_5++
            host_client = host_client + 8288
        }
    }
    if (i_5 < svs.maxclients) {
        if (uint(cmd_source) == 1u) {
            if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 0u) {
                who = 716569
            } else {
                who = int(uint(c2da_mem[9144]) | uint(c2da_mem[9145]) << 0x8 | uint(c2da_mem[9146]) << 0x10 | uint(c2da_mem[9147]) << 0x18)
            }
        } else {
            who = save + 8112
        }
        if (host_client == save) {
            return
        }
        if (Cmd_Argc() > 2) {
            message = COM_Parse(Cmd_Args())
            if (byNumber != 0u) {
                message++
                while (int(int8(c2da_mem[message])) == 32) {
                    message++
                }
                message = message + int(Q_strlen(Cmd_Argv(2)))
            }
            while (int(int8(c2da_mem[message])) != 0 && int(int8(c2da_mem[message])) == 32) {
                message++
            }
        }
        if (message != 0) {
            SV_ClientPrintf(716577, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(who)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(message))])
        } else {
            SV_ClientPrintf(716595, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(who))])
        }
        SV_DropClient(0u)
    }
    host_client = save
    return
}
[export, sideeffects]
def Host_PreSpawn_f() {
    if (uint(cmd_source) == 1u) {
        Con_Printf(716609, [])
        return
    }
    if ((uint(c2da_mem[host_client + 4]) | uint(c2da_mem[host_client + 5]) << 0x8 | uint(c2da_mem[host_client + 6]) << 0x10 | uint(c2da_mem[host_client + 7]) << 0x18) != 0u) {
        Con_Printf(716649, [])
        return
    }
    SZ_Write(host_client + 80, int(uint(c2da_mem[234816]) | uint(c2da_mem[234817]) << 0x8 | uint(c2da_mem[234818]) << 0x10 | uint(c2da_mem[234819]) << 0x18), int(uint(c2da_mem[234828]) | uint(c2da_mem[234829]) << 0x8 | uint(c2da_mem[234830]) << 0x10 | uint(c2da_mem[234831]) << 0x18))
    MSG_WriteByte(host_client + 80, 25)
    MSG_WriteByte(host_client + 80, 2)
    let c2da_fresh103 : uint = 1u
    let c2da_fresh104 : uint = c2da_fresh103
    c2da_mem[host_client + 16] = uint8(c2da_fresh104)
    c2da_mem[host_client + 17] = uint8(c2da_fresh104 >> 0x8)
    c2da_mem[host_client + 18] = uint8(c2da_fresh104 >> 0x10)
    c2da_mem[host_client + 19] = uint8(c2da_fresh104 >> 0x18)
    return
}
[export, sideeffects]
def Host_Begin_f() {
    if (uint(cmd_source) == 1u) {
        Con_Printf(716689, [])
        return
    }
    let c2da_fresh105 : uint = 1u
    let c2da_fresh106 : uint = c2da_fresh105
    c2da_mem[host_client + 4] = uint8(c2da_fresh106)
    c2da_mem[host_client + 5] = uint8(c2da_fresh106 >> 0x8)
    c2da_mem[host_client + 6] = uint8(c2da_fresh106 >> 0x10)
    c2da_mem[host_client + 7] = uint8(c2da_fresh106 >> 0x18)
    return
}
[export, sideeffects]
def Host_Spawn_f() {
    var i_6 : int
    var client_0 : int
    var ent_0 : int
    if (uint(cmd_source) == 1u) {
        Con_Printf(716726, [])
        return
    }
    if ((uint(c2da_mem[host_client + 4]) | uint(c2da_mem[host_client + 5]) << 0x8 | uint(c2da_mem[host_client + 6]) << 0x10 | uint(c2da_mem[host_client + 7]) << 0x18) != 0u) {
        Con_Printf(716763, [])
        return
    }
    if ((uint(c2da_mem[225864]) | uint(c2da_mem[225865]) << 0x8 | uint(c2da_mem[225866]) << 0x10 | uint(c2da_mem[225867]) << 0x18) != 0u) {
        let c2da_fresh107 : uint = 0u
        let c2da_fresh108 : uint = c2da_fresh107
        c2da_mem[225860] = uint8(c2da_fresh108)
        c2da_mem[225861] = uint8(c2da_fresh108 >> 0x8)
        c2da_mem[225862] = uint8(c2da_fresh108 >> 0x10)
        c2da_mem[225863] = uint8(c2da_fresh108 >> 0x18)
    } else {
        ent_0 = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18)
        c2da_lin_memset(ent_0 + 108, 0, uint64(int(uint(c2da_mem[progs + 56]) | uint(c2da_mem[progs + 57]) << 0x8 | uint(c2da_mem[progs + 58]) << 0x10 | uint(c2da_mem[progs + 59]) << 0x18) * 4))
        let c2da_fresh109 : float = float(NUM_FOR_EDICT(ent_0))
        let c2da_fresh110 : uint = float_bits_to_uint(c2da_fresh109)
        c2da_mem[ent_0 + 416] = uint8(c2da_fresh110)
        c2da_mem[ent_0 + 417] = uint8(c2da_fresh110 >> 0x8)
        c2da_mem[ent_0 + 418] = uint8(c2da_fresh110 >> 0x10)
        c2da_mem[ent_0 + 419] = uint8(c2da_fresh110 >> 0x18)
        let c2da_fresh111 : float = float((int(uint(c2da_mem[host_client + 8144]) | uint(c2da_mem[host_client + 8145]) << 0x8 | uint(c2da_mem[host_client + 8146]) << 0x10 | uint(c2da_mem[host_client + 8147]) << 0x18) & 15) + 1)
        let c2da_fresh112 : uint = float_bits_to_uint(c2da_fresh111)
        c2da_mem[ent_0 + 420] = uint8(c2da_fresh112)
        c2da_mem[ent_0 + 421] = uint8(c2da_fresh112 >> 0x8)
        c2da_mem[ent_0 + 422] = uint8(c2da_fresh112 >> 0x10)
        c2da_mem[ent_0 + 423] = uint8(c2da_fresh112 >> 0x18)
        let c2da_fresh113 : int = int(int64(host_client + 8112 - pr_strings))
        let c2da_fresh114 : uint = uint(c2da_fresh113)
        c2da_mem[ent_0 + 404] = uint8(c2da_fresh114)
        c2da_mem[ent_0 + 405] = uint8(c2da_fresh114 >> 0x8)
        c2da_mem[ent_0 + 406] = uint8(c2da_fresh114 >> 0x10)
        c2da_mem[ent_0 + 407] = uint8(c2da_fresh114 >> 0x18)
        i_6 = 0
        while (i_6 < 16) {
            let c2da_fresh115 : float = uint_bits_to_float(uint(c2da_mem[host_client + 8216 + i_6 * 4]) | uint(c2da_mem[host_client + 8216 + i_6 * 4 + 1]) << 0x8 | uint(c2da_mem[host_client + 8216 + i_6 * 4 + 2]) << 0x10 | uint(c2da_mem[host_client + 8216 + i_6 * 4 + 3]) << 0x18)
            let c2da_fresh116 : uint = float_bits_to_uint(c2da_fresh115)
            c2da_mem[pr_global_struct + 172 + i_6 * 4] = uint8(c2da_fresh116)
            c2da_mem[pr_global_struct + 172 + i_6 * 4 + 1] = uint8(c2da_fresh116 >> 0x8)
            c2da_mem[pr_global_struct + 172 + i_6 * 4 + 2] = uint8(c2da_fresh116 >> 0x10)
            c2da_mem[pr_global_struct + 172 + i_6 * 4 + 3] = uint8(c2da_fresh116 >> 0x18)
            i_6++
        }
        let c2da_fresh117 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20))
        let c2da_fresh118 : uint = float_bits_to_uint(c2da_fresh117)
        c2da_mem[pr_global_struct + 124] = uint8(c2da_fresh118)
        c2da_mem[pr_global_struct + 125] = uint8(c2da_fresh118 >> 0x8)
        c2da_mem[pr_global_struct + 126] = uint8(c2da_fresh118 >> 0x10)
        c2da_mem[pr_global_struct + 127] = uint8(c2da_fresh118 >> 0x18)
        let c2da_fresh119 : int = int(int64(sv_player - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)))
        let c2da_fresh120 : uint = uint(c2da_fresh119)
        c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh120)
        c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh120 >> 0x8)
        c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh120 >> 0x10)
        c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh120 >> 0x18)
        PR_ExecuteProgram(int(uint(c2da_mem[pr_global_struct + 348]) | uint(c2da_mem[pr_global_struct + 349]) << 0x8 | uint(c2da_mem[pr_global_struct + 350]) << 0x10 | uint(c2da_mem[pr_global_struct + 351]) << 0x18))
        let c2da_fresh121 : int = int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18) + 8
        if (Sys_FloatTime() - uint64_bits_to_double(uint64(uint(c2da_mem[c2da_fresh121]) | uint(c2da_mem[c2da_fresh121 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh121 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh121 + 3]) << 0x18) | uint64(uint(c2da_mem[c2da_fresh121 + 4]) | uint(c2da_mem[c2da_fresh121 + 5]) << 0x8 | uint(c2da_mem[c2da_fresh121 + 6]) << 0x10 | uint(c2da_mem[c2da_fresh121 + 7]) << 0x18) << 0x20) <= uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20)) {
            Sys_Printf(716800, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(host_client + 8112))])
        }
        PR_ExecuteProgram(int(uint(c2da_mem[pr_global_struct + 352]) | uint(c2da_mem[pr_global_struct + 353]) << 0x8 | uint(c2da_mem[pr_global_struct + 354]) << 0x10 | uint(c2da_mem[pr_global_struct + 355]) << 0x18))
    }
    SZ_Clear(host_client + 80)
    MSG_WriteByte(host_client + 80, 7)
    MSG_WriteFloat(host_client + 80, float(uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20)))
    i_6 = 0
    client_0 = svs.clients
    while (i_6 < svs.maxclients) {
        MSG_WriteByte(host_client + 80, 13)
        MSG_WriteByte(host_client + 80, i_6)
        MSG_WriteString(host_client + 80, client_0 + 8112)
        MSG_WriteByte(host_client + 80, 14)
        MSG_WriteByte(host_client + 80, i_6)
        MSG_WriteShort(host_client + 80, int(uint(c2da_mem[client_0 + 8280]) | uint(c2da_mem[client_0 + 8281]) << 0x8 | uint(c2da_mem[client_0 + 8282]) << 0x10 | uint(c2da_mem[client_0 + 8283]) << 0x18))
        MSG_WriteByte(host_client + 80, 17)
        MSG_WriteByte(host_client + 80, i_6)
        MSG_WriteByte(host_client + 80, int(uint(c2da_mem[client_0 + 8144]) | uint(c2da_mem[client_0 + 8145]) << 0x8 | uint(c2da_mem[client_0 + 8146]) << 0x10 | uint(c2da_mem[client_0 + 8147]) << 0x18))
        i_6++
        client_0 += 8288
    }
    i_6 = 0
    while (i_6 < 64) {
        MSG_WriteByte(host_client + 80, 12)
        MSG_WriteByte(host_client + 80, int(int8(i_6)))
        MSG_WriteString(host_client + 80, int(uint(c2da_mem[232176 + i_6 * 8]) | uint(c2da_mem[232176 + i_6 * 8 + 1]) << 0x8 | uint(c2da_mem[232176 + i_6 * 8 + 2]) << 0x10 | uint(c2da_mem[232176 + i_6 * 8 + 3]) << 0x18))
        i_6++
    }
    MSG_WriteByte(host_client + 80, 3)
    MSG_WriteByte(host_client + 80, 11)
    MSG_WriteLong(host_client + 80, int(uint_bits_to_float(uint(c2da_mem[pr_global_struct + 156]) | uint(c2da_mem[pr_global_struct + 157]) << 0x8 | uint(c2da_mem[pr_global_struct + 158]) << 0x10 | uint(c2da_mem[pr_global_struct + 159]) << 0x18)))
    MSG_WriteByte(host_client + 80, 3)
    MSG_WriteByte(host_client + 80, 12)
    MSG_WriteLong(host_client + 80, int(uint_bits_to_float(uint(c2da_mem[pr_global_struct + 160]) | uint(c2da_mem[pr_global_struct + 161]) << 0x8 | uint(c2da_mem[pr_global_struct + 162]) << 0x10 | uint(c2da_mem[pr_global_struct + 163]) << 0x18)))
    MSG_WriteByte(host_client + 80, 3)
    MSG_WriteByte(host_client + 80, 13)
    MSG_WriteLong(host_client + 80, int(uint_bits_to_float(uint(c2da_mem[pr_global_struct + 164]) | uint(c2da_mem[pr_global_struct + 165]) << 0x8 | uint(c2da_mem[pr_global_struct + 166]) << 0x10 | uint(c2da_mem[pr_global_struct + 167]) << 0x18)))
    MSG_WriteByte(host_client + 80, 3)
    MSG_WriteByte(host_client + 80, 14)
    MSG_WriteLong(host_client + 80, int(uint_bits_to_float(uint(c2da_mem[pr_global_struct + 168]) | uint(c2da_mem[pr_global_struct + 169]) << 0x8 | uint(c2da_mem[pr_global_struct + 170]) << 0x10 | uint(c2da_mem[pr_global_struct + 171]) << 0x18)))
    ent_0 = EDICT_NUM(int(1l + int64((host_client - svs.clients) / 8288)))
    MSG_WriteByte(host_client + 80, 10)
    i_6 = 0
    for (c2da_i_6 in range(i_6, 2)) {
        MSG_WriteAngle(host_client + 80, uint_bits_to_float(uint(c2da_mem[ent_0 + 184 + c2da_i_6 * 4]) | uint(c2da_mem[ent_0 + 184 + c2da_i_6 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 184 + c2da_i_6 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 184 + c2da_i_6 * 4 + 3]) << 0x18))
    }
    MSG_WriteAngle(host_client + 80, 0.0)
    SV_WriteClientdataToMessage(sv_player, host_client + 80)
    MSG_WriteByte(host_client + 80, 25)
    MSG_WriteByte(host_client + 80, 3)
    let c2da_fresh122 : uint = 1u
    let c2da_fresh123 : uint = c2da_fresh122
    c2da_mem[host_client + 16] = uint8(c2da_fresh123)
    c2da_mem[host_client + 17] = uint8(c2da_fresh123 >> 0x8)
    c2da_mem[host_client + 18] = uint8(c2da_fresh123 >> 0x10)
    c2da_mem[host_client + 19] = uint8(c2da_fresh123 >> 0x18)
    return
}
[export, sideeffects]
def Host_Pause_f() {
    if (uint(cmd_source) == 1u) {
        Cmd_ForwardToServer()
        return
    }
    if (uint_bits_to_float(uint(c2da_mem[243800]) | uint(c2da_mem[243801]) << 0x8 | uint(c2da_mem[243802]) << 0x10 | uint(c2da_mem[243803]) << 0x18) == 0.0) {
        SV_ClientPrintf(716821, [])
    } else {
        let c2da_fresh124 : uint = (uint(c2da_mem[225860]) | uint(c2da_mem[225861]) << 0x8 | uint(c2da_mem[225862]) << 0x10 | uint(c2da_mem[225863]) << 0x18) ^ 1u
        let c2da_fresh125 : uint = c2da_fresh124
        c2da_mem[225860] = uint8(c2da_fresh125)
        c2da_mem[225861] = uint8(c2da_fresh125 >> 0x8)
        c2da_mem[225862] = uint8(c2da_fresh125 >> 0x10)
        c2da_mem[225863] = uint8(c2da_fresh125 >> 0x18)
        if ((uint(c2da_mem[225860]) | uint(c2da_mem[225861]) << 0x8 | uint(c2da_mem[225862]) << 0x10 | uint(c2da_mem[225863]) << 0x18) != 0u) {
            SV_BroadcastPrintf(716841, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[sv_player + 404]) | uint(c2da_mem[sv_player + 405]) << 0x8 | uint(c2da_mem[sv_player + 406]) << 0x10 | uint(c2da_mem[sv_player + 407]) << 0x18)))])
        } else {
            SV_BroadcastPrintf(716861, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[sv_player + 404]) | uint(c2da_mem[sv_player + 405]) << 0x8 | uint(c2da_mem[sv_player + 406]) << 0x10 | uint(c2da_mem[sv_player + 407]) << 0x18)))])
        }
        MSG_WriteByte(233760, 24)
        MSG_WriteByte(233760, int(uint(c2da_mem[225860]) | uint(c2da_mem[225861]) << 0x8 | uint(c2da_mem[225862]) << 0x10 | uint(c2da_mem[225863]) << 0x18))
    }
    return
}
[export, sideeffects]
def Host_Kill_f() {
    if (uint(cmd_source) == 1u) {
        Cmd_ForwardToServer()
        return
    }
    if (uint_bits_to_float(uint(c2da_mem[sv_player + 300]) | uint(c2da_mem[sv_player + 301]) << 0x8 | uint(c2da_mem[sv_player + 302]) << 0x10 | uint(c2da_mem[sv_player + 303]) << 0x18) <= 0.0) {
        SV_ClientPrintf(716883, [])
        return
    }
    let c2da_fresh126 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20))
    let c2da_fresh127 : uint = float_bits_to_uint(c2da_fresh126)
    c2da_mem[pr_global_struct + 124] = uint8(c2da_fresh127)
    c2da_mem[pr_global_struct + 125] = uint8(c2da_fresh127 >> 0x8)
    c2da_mem[pr_global_struct + 126] = uint8(c2da_fresh127 >> 0x10)
    c2da_mem[pr_global_struct + 127] = uint8(c2da_fresh127 >> 0x18)
    let c2da_fresh128 : int = int(int64(sv_player - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)))
    let c2da_fresh129 : uint = uint(c2da_fresh128)
    c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh129)
    c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh129 >> 0x8)
    c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh129 >> 0x10)
    c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh129 >> 0x18)
    PR_ExecuteProgram(int(uint(c2da_mem[pr_global_struct + 344]) | uint(c2da_mem[pr_global_struct + 345]) << 0x8 | uint(c2da_mem[pr_global_struct + 346]) << 0x10 | uint(c2da_mem[pr_global_struct + 347]) << 0x18))
    return
}
[export, sideeffects]
def Host_Color_f() {
    var top : int
    var bottom : int
    var playercolor : int
    if (Cmd_Argc() == 1) {
        Con_Printf(716916, [C2daVaArg(tag = 1, i64 = int64(int(uint_bits_to_float(uint(c2da_mem[9208]) | uint(c2da_mem[9209]) << 0x8 | uint(c2da_mem[9210]) << 0x10 | uint(c2da_mem[9211]) << 0x18)) >> 4), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint_bits_to_float(uint(c2da_mem[9208]) | uint(c2da_mem[9209]) << 0x8 | uint(c2da_mem[9210]) << 0x10 | uint(c2da_mem[9211]) << 0x18)) & 15), f64 = 0.0lf, raw = 0x0)])
        Con_Printf(716936, [])
        return
    }
    if (Cmd_Argc() == 2) {
        bottom = c2da_lin_atoi(int(Cmd_Argv(1)))
        top = bottom
    } else {
        top = c2da_lin_atoi(int(Cmd_Argv(1)))
        bottom = c2da_lin_atoi(int(Cmd_Argv(2)))
    }
    top &= 15
    if (top > 13) {
        top = 13
    }
    bottom &= 15
    if (bottom > 13) {
        bottom = 13
    }
    playercolor = top * 16 + bottom
    if (uint(cmd_source) == 1u) {
        Cvar_SetValue(716957, float(playercolor))
        if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 2u) {
            Cmd_ForwardToServer()
        }
        return
    }
    let c2da_fresh130 : uint = uint(playercolor)
    c2da_mem[host_client + 8144] = uint8(c2da_fresh130)
    c2da_mem[host_client + 8145] = uint8(c2da_fresh130 >> 0x8)
    c2da_mem[host_client + 8146] = uint8(c2da_fresh130 >> 0x10)
    c2da_mem[host_client + 8147] = uint8(c2da_fresh130 >> 0x18)
    let c2da_fresh131 : int = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18) + 420
    let c2da_fresh132 : float = float(bottom + 1)
    let c2da_fresh133 : uint = float_bits_to_uint(c2da_fresh132)
    c2da_mem[c2da_fresh131] = uint8(c2da_fresh133)
    c2da_mem[c2da_fresh131 + 1] = uint8(c2da_fresh133 >> 0x8)
    c2da_mem[c2da_fresh131 + 2] = uint8(c2da_fresh133 >> 0x10)
    c2da_mem[c2da_fresh131 + 3] = uint8(c2da_fresh133 >> 0x18)
    MSG_WriteByte(233760, 17)
    MSG_WriteByte(233760, int(int64((host_client - svs.clients) / 8288)))
    MSG_WriteByte(233760, int(uint(c2da_mem[host_client + 8144]) | uint(c2da_mem[host_client + 8145]) << 0x8 | uint(c2da_mem[host_client + 8146]) << 0x10 | uint(c2da_mem[host_client + 8147]) << 0x18))
    return
}
[export, sideeffects]
def Host_Tell_f() {
    let c2da_saved_sp : int = c2da_lin_sp
    Host_Tell_f_c2da_frame(c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Host_Say_Team_f() {
    Host_Say(1u)
    return
}
[export, sideeffects]
def Host_Say(var teamonly : uint) {
    let c2da_saved_sp : int = c2da_lin_sp
    Host_Say_c2da_frame(teamonly, c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Host_Say_f() {
    Host_Say(0u)
    return
}
[export, sideeffects]
def Host_Version_f() {
    Con_Printf(716990, [C2daVaArg(tag = 2, i64 = 0, f64 = 1.09lf, raw = 0x0)])
    Con_Printf(717005, [])
    return
}
[export, sideeffects]
def Host_Noclip_f() {
    if (uint(cmd_source) == 1u) {
        Cmd_ForwardToServer()
        return
    }
    if (uint_bits_to_float(uint(c2da_mem[pr_global_struct + 140]) | uint(c2da_mem[pr_global_struct + 141]) << 0x8 | uint(c2da_mem[pr_global_struct + 142]) << 0x10 | uint(c2da_mem[pr_global_struct + 143]) << 0x18) != 0.0 && (uint(c2da_mem[host_client + 12]) | uint(c2da_mem[host_client + 13]) << 0x8 | uint(c2da_mem[host_client + 14]) << 0x10 | uint(c2da_mem[host_client + 15]) << 0x18) == 0u) {
        return
    }
    if (uint_bits_to_float(uint(c2da_mem[sv_player + 140]) | uint(c2da_mem[sv_player + 141]) << 0x8 | uint(c2da_mem[sv_player + 142]) << 0x10 | uint(c2da_mem[sv_player + 143]) << 0x18) != 8.0) {
        noclip_anglehack = 1u
        let c2da_fresh143 : float = 8.0
        let c2da_fresh144 : uint = float_bits_to_uint(c2da_fresh143)
        c2da_mem[sv_player + 140] = uint8(c2da_fresh144)
        c2da_mem[sv_player + 141] = uint8(c2da_fresh144 >> 0x8)
        c2da_mem[sv_player + 142] = uint8(c2da_fresh144 >> 0x10)
        c2da_mem[sv_player + 143] = uint8(c2da_fresh144 >> 0x18)
        SV_ClientPrintf(717032, [])
    } else {
        noclip_anglehack = 0u
        let c2da_fresh145 : float = 3.0
        let c2da_fresh146 : uint = float_bits_to_uint(c2da_fresh145)
        c2da_mem[sv_player + 140] = uint8(c2da_fresh146)
        c2da_mem[sv_player + 141] = uint8(c2da_fresh146 >> 0x8)
        c2da_mem[sv_player + 142] = uint8(c2da_fresh146 >> 0x10)
        c2da_mem[sv_player + 143] = uint8(c2da_fresh146 >> 0x18)
        SV_ClientPrintf(717043, [])
    }
    return
}
[export, sideeffects]
def Host_Name_f() {
    var newName : int
    if (Cmd_Argc() == 1) {
        Con_Printf(717055, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[9144]) | uint(c2da_mem[9145]) << 0x8 | uint(c2da_mem[9146]) << 0x10 | uint(c2da_mem[9147]) << 0x18)))])
        return
    }
    if (Cmd_Argc() == 2) {
        newName = Cmd_Argv(1)
    } else {
        newName = Cmd_Args()
    }
    let c2da_fresh147 : int8 = int8(0)
    c2da_mem[newName + 15] = uint8(c2da_fresh147)
    if (uint(cmd_source) == 1u) {
        if (Q_strcmp(int(uint(c2da_mem[9144]) | uint(c2da_mem[9145]) << 0x8 | uint(c2da_mem[9146]) << 0x10 | uint(c2da_mem[9147]) << 0x18), newName) == 0) {
            return
        }
        Cvar_Set(717071, newName)
        if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 2u) {
            Cmd_ForwardToServer()
        }
        return
    }
    if (int(int8(c2da_mem[host_client + 8112 + 0])) != 0 && c2da_lin_strcmp(int(host_client + 8112), 717080) != 0) {
        if (Q_strcmp(host_client + 8112, newName) != 0) {
            Con_Printf(717092, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(host_client + 8112)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(newName))])
        }
    }
    Q_strcpy(host_client + 8112, newName)
    let c2da_fresh148 : int = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18) + 404
    let c2da_fresh149 : int = int(int64(host_client + 8112 - pr_strings))
    let c2da_fresh150 : uint = uint(c2da_fresh149)
    c2da_mem[c2da_fresh148] = uint8(c2da_fresh150)
    c2da_mem[c2da_fresh148 + 1] = uint8(c2da_fresh150 >> 0x8)
    c2da_mem[c2da_fresh148 + 2] = uint8(c2da_fresh150 >> 0x10)
    c2da_mem[c2da_fresh148 + 3] = uint8(c2da_fresh150 >> 0x18)
    MSG_WriteByte(233760, 13)
    MSG_WriteByte(233760, int(int64((host_client - svs.clients) / 8288)))
    MSG_WriteString(233760, host_client + 8112)
    return
}
[export, sideeffects]
def Host_Connect_f() {
    let c2da_saved_sp : int = c2da_lin_sp
    Host_Connect_f_c2da_frame(c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Host_Changelevel_f() {
    let c2da_saved_sp : int = c2da_lin_sp
    Host_Changelevel_f_c2da_frame(c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Host_Restart_f() {
    let c2da_saved_sp : int = c2da_lin_sp
    Host_Restart_f_c2da_frame(c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Host_Map_f() {
    let c2da_saved_sp : int = c2da_lin_sp
    Host_Map_f_c2da_frame(c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Host_Fly_f() {
    if (uint(cmd_source) == 1u) {
        Cmd_ForwardToServer()
        return
    }
    if (uint_bits_to_float(uint(c2da_mem[pr_global_struct + 140]) | uint(c2da_mem[pr_global_struct + 141]) << 0x8 | uint(c2da_mem[pr_global_struct + 142]) << 0x10 | uint(c2da_mem[pr_global_struct + 143]) << 0x18) != 0.0 && (uint(c2da_mem[host_client + 12]) | uint(c2da_mem[host_client + 13]) << 0x8 | uint(c2da_mem[host_client + 14]) << 0x10 | uint(c2da_mem[host_client + 15]) << 0x18) == 0u) {
        return
    }
    if (uint_bits_to_float(uint(c2da_mem[sv_player + 140]) | uint(c2da_mem[sv_player + 141]) << 0x8 | uint(c2da_mem[sv_player + 142]) << 0x10 | uint(c2da_mem[sv_player + 143]) << 0x18) != 5.0) {
        let c2da_fresh156 : float = 5.0
        let c2da_fresh157 : uint = float_bits_to_uint(c2da_fresh156)
        c2da_mem[sv_player + 140] = uint8(c2da_fresh157)
        c2da_mem[sv_player + 141] = uint8(c2da_fresh157 >> 0x8)
        c2da_mem[sv_player + 142] = uint8(c2da_fresh157 >> 0x10)
        c2da_mem[sv_player + 143] = uint8(c2da_fresh157 >> 0x18)
        SV_ClientPrintf(717216, [])
    } else {
        let c2da_fresh158 : float = 3.0
        let c2da_fresh159 : uint = float_bits_to_uint(c2da_fresh158)
        c2da_mem[sv_player + 140] = uint8(c2da_fresh159)
        c2da_mem[sv_player + 141] = uint8(c2da_fresh159 >> 0x8)
        c2da_mem[sv_player + 142] = uint8(c2da_fresh159 >> 0x10)
        c2da_mem[sv_player + 143] = uint8(c2da_fresh159 >> 0x18)
        SV_ClientPrintf(717228, [])
    }
    return
}
[export, sideeffects]
def Host_Notarget_f() {
    if (uint(cmd_source) == 1u) {
        Cmd_ForwardToServer()
        return
    }
    if (uint_bits_to_float(uint(c2da_mem[pr_global_struct + 140]) | uint(c2da_mem[pr_global_struct + 141]) << 0x8 | uint(c2da_mem[pr_global_struct + 142]) << 0x10 | uint(c2da_mem[pr_global_struct + 143]) << 0x18) != 0.0 && (uint(c2da_mem[host_client + 12]) | uint(c2da_mem[host_client + 13]) << 0x8 | uint(c2da_mem[host_client + 14]) << 0x10 | uint(c2da_mem[host_client + 15]) << 0x18) == 0u) {
        return
    }
    let c2da_fresh160 : float = float(int(uint_bits_to_float(uint(c2da_mem[sv_player + 412]) | uint(c2da_mem[sv_player + 413]) << 0x8 | uint(c2da_mem[sv_player + 414]) << 0x10 | uint(c2da_mem[sv_player + 415]) << 0x18)) ^ 128)
    let c2da_fresh161 : uint = float_bits_to_uint(c2da_fresh160)
    c2da_mem[sv_player + 412] = uint8(c2da_fresh161)
    c2da_mem[sv_player + 413] = uint8(c2da_fresh161 >> 0x8)
    c2da_mem[sv_player + 414] = uint8(c2da_fresh161 >> 0x10)
    c2da_mem[sv_player + 415] = uint8(c2da_fresh161 >> 0x18)
    if ((int(c2da_fresh160) & 128) == 0) {
        SV_ClientPrintf(717241, [])
    } else {
        SV_ClientPrintf(717255, [])
    }
    return
}
[export, sideeffects]
def Host_God_f() {
    if (uint(cmd_source) == 1u) {
        Cmd_ForwardToServer()
        return
    }
    if (uint_bits_to_float(uint(c2da_mem[pr_global_struct + 140]) | uint(c2da_mem[pr_global_struct + 141]) << 0x8 | uint(c2da_mem[pr_global_struct + 142]) << 0x10 | uint(c2da_mem[pr_global_struct + 143]) << 0x18) != 0.0 && (uint(c2da_mem[host_client + 12]) | uint(c2da_mem[host_client + 13]) << 0x8 | uint(c2da_mem[host_client + 14]) << 0x10 | uint(c2da_mem[host_client + 15]) << 0x18) == 0u) {
        return
    }
    let c2da_fresh162 : float = float(int(uint_bits_to_float(uint(c2da_mem[sv_player + 412]) | uint(c2da_mem[sv_player + 413]) << 0x8 | uint(c2da_mem[sv_player + 414]) << 0x10 | uint(c2da_mem[sv_player + 415]) << 0x18)) ^ 64)
    let c2da_fresh163 : uint = float_bits_to_uint(c2da_fresh162)
    c2da_mem[sv_player + 412] = uint8(c2da_fresh163)
    c2da_mem[sv_player + 413] = uint8(c2da_fresh163 >> 0x8)
    c2da_mem[sv_player + 414] = uint8(c2da_fresh163 >> 0x10)
    c2da_mem[sv_player + 415] = uint8(c2da_fresh163 >> 0x18)
    if ((int(c2da_fresh162) & 64) == 0) {
        SV_ClientPrintf(717268, [])
    } else {
        SV_ClientPrintf(717281, [])
    }
    return
}
[export, sideeffects]
def Host_Quit_f() {
    if (uint(key_dest) != 1u && (uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) != 0u) {
        M_Menu_Quit_f()
        return
    }
    CL_Disconnect()
    Host_ShutdownServer(0u)
    Sys_Quit()
    return
}
[export, sideeffects]
def Host_Status_f() {
    var client_3 : int
    var seconds : int
    var minutes : int
    var hours : int
    var j_2 : int
    var print_0 : int
    hours = 0
    if (uint(cmd_source) == 1u) {
        if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u) {
            Cmd_ForwardToServer()
            return
        }
        print_0 = 95
    } else {
        print_0 = 96
    }
    invoke(c2da_fn_table4[print_0], 717293, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(Cvar_VariableString(717306)))])
    invoke(c2da_fn_table4[print_0], 717315, [C2daVaArg(tag = 2, i64 = 0, f64 = 1.09lf, raw = 0x0)])
    if (uint(tcpipAvailable) != 0u) {
        invoke(c2da_fn_table4[print_0], 717331, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 243024ul)])
    }
    if (uint(ipxAvailable) != 0u) {
        invoke(c2da_fn_table4[print_0], 717344, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 243088ul)])
    }
    invoke(c2da_fn_table4[print_0], 717357, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 225896ul)])
    invoke(c2da_fn_table4[print_0], 717370, [C2daVaArg(tag = 1, i64 = int64(net_activeconnections), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(svs.maxclients), f64 = 0.0lf, raw = 0x0)])
    j_2 = 0
    client_3 = svs.clients
    while (j_2 < svs.maxclients) {
        if ((uint(c2da_mem[client_3]) | uint(c2da_mem[client_3 + 1]) << 0x8 | uint(c2da_mem[client_3 + 2]) << 0x10 | uint(c2da_mem[client_3 + 3]) << 0x18) == 0u) {
            j_2++
            client_3 += 8288
            continue
        }
        let c2da_fresh164 : int = int(uint(c2da_mem[client_3 + 32]) | uint(c2da_mem[client_3 + 33]) << 0x8 | uint(c2da_mem[client_3 + 34]) << 0x10 | uint(c2da_mem[client_3 + 35]) << 0x18) + 8
        seconds = int(net_time - uint64_bits_to_double(uint64(uint(c2da_mem[c2da_fresh164]) | uint(c2da_mem[c2da_fresh164 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh164 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh164 + 3]) << 0x18) | uint64(uint(c2da_mem[c2da_fresh164 + 4]) | uint(c2da_mem[c2da_fresh164 + 5]) << 0x8 | uint(c2da_mem[c2da_fresh164 + 6]) << 0x10 | uint(c2da_mem[c2da_fresh164 + 7]) << 0x18) << 0x20))
        minutes = seconds / 60
        if (minutes != 0) {
            seconds -= minutes * 60
            hours = minutes / 60
            if (hours != 0) {
                minutes -= hours * 60
            }
        } else {
            hours = 0
        }
        let c2da_fresh165 : int = int(uint(c2da_mem[client_3 + 8104]) | uint(c2da_mem[client_3 + 8105]) << 0x8 | uint(c2da_mem[client_3 + 8106]) << 0x10 | uint(c2da_mem[client_3 + 8107]) << 0x18) + 304
        invoke(c2da_fn_table4[print_0], 717400, [C2daVaArg(tag = 1, i64 = int64(j_2 + 1), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(client_3 + 8112)), C2daVaArg(tag = 1, i64 = int64(int(uint_bits_to_float(uint(c2da_mem[c2da_fresh165]) | uint(c2da_mem[c2da_fresh165 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh165 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh165 + 3]) << 0x18))), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(hours), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(minutes), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(seconds), f64 = 0.0lf, raw = 0x0)])
        invoke(c2da_fn_table4[print_0], 717436, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[client_3 + 32]) | uint(c2da_mem[client_3 + 33]) << 0x8 | uint(c2da_mem[client_3 + 34]) << 0x10 | uint(c2da_mem[client_3 + 35]) << 0x18) + 16492))])
        j_2++
        client_3 += 8288
    }
    return
}
[sideeffects]
def private Host_Savegame_f_c2da_frame(c2da_fp : int) {
    var f_0 : int
    var i_1 : int
    if (uint(cmd_source) != 1u) {
        return
    }
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u) {
        Con_Printf(716074, [])
        return
    }
    if (int(uint(c2da_mem[756]) | uint(c2da_mem[757]) << 0x8 | uint(c2da_mem[758]) << 0x10 | uint(c2da_mem[759]) << 0x18) != 0) {
        Con_Printf(716101, [])
        return
    }
    if (svs.maxclients != 1) {
        Con_Printf(716130, [])
        return
    }
    if (Cmd_Argc() != 2) {
        Con_Printf(716161, [])
        return
    }
    if (c2da_lin_strstr(int(Cmd_Argv(1)), 716192) != 0) {
        Con_Printf(716195, [])
        return
    }
    i_1 = 0
    while (i_1 < svs.maxclients) {
        let c2da_fresh74 : int = svs.clients + i_1 * 8288
        var c2da_fresh77 : int = 0
        if ((uint(c2da_mem[c2da_fresh74]) | uint(c2da_mem[c2da_fresh74 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh74 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh74 + 3]) << 0x18) != 0x0) {
            let c2da_fresh75 : int = svs.clients + i_1 * 8288 + 8104
            let c2da_fresh76 : int = int(uint(c2da_mem[c2da_fresh75]) | uint(c2da_mem[c2da_fresh75 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh75 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh75 + 3]) << 0x18) + 300
            if (uint_bits_to_float(uint(c2da_mem[c2da_fresh76]) | uint(c2da_mem[c2da_fresh76 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh76 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh76 + 3]) << 0x18) <= 0.0) {
                c2da_fresh77 = 1
            }
        }
        if (c2da_fresh77 != 0) {
            Con_Printf(716232, [])
            return
        }
        i_1++
    }
    c2da_lin_snprintf(c2da_fp, 2147483647ul, 716267, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 5392ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(Cmd_Argv(1)))])
    COM_DefaultExtension(c2da_fp, 716273)
    Con_Printf(716278, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    f_0 = c2da_lin_fopen(c2da_fp, 716300)
    if (f_0 == 0) {
        Con_Printf(716302, [])
        return
    }
    c2da_lin_printf(uint64(f_0), 716325, [C2daVaArg(tag = 1, i64 = 5l, f64 = 0.0lf, raw = 0x0)])
    Host_SavegameComment(c2da_fp + 256)
    c2da_lin_printf(uint64(f_0), 716329, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp + 256))])
    i_1 = 0
    while (i_1 < 16) {
        let c2da_fresh78 : int = svs.clients + 8216 + i_1 * 4
        c2da_lin_printf(uint64(f_0), 716333, [C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[c2da_fresh78]) | uint(c2da_mem[c2da_fresh78 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh78 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh78 + 3]) << 0x18)), raw = 0x0)])
        i_1++
    }
    c2da_lin_printf(uint64(f_0), 716337, [C2daVaArg(tag = 1, i64 = int64(current_skill), f64 = 0.0lf, raw = 0x0)])
    c2da_lin_printf(uint64(f_0), 716329, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 225896ul)])
    c2da_lin_printf(uint64(f_0), 716333, [C2daVaArg(tag = 2, i64 = 0, f64 = uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20), raw = 0x0)])
    i_1 = 0
    while (i_1 < 64) {
        if (int(uint(c2da_mem[232176 + i_1 * 8]) | uint(c2da_mem[232176 + i_1 * 8 + 1]) << 0x8 | uint(c2da_mem[232176 + i_1 * 8 + 2]) << 0x10 | uint(c2da_mem[232176 + i_1 * 8 + 3]) << 0x18) != 0) {
            c2da_lin_printf(uint64(f_0), 716329, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[232176 + i_1 * 8]) | uint(c2da_mem[232176 + i_1 * 8 + 1]) << 0x8 | uint(c2da_mem[232176 + i_1 * 8 + 2]) << 0x10 | uint(c2da_mem[232176 + i_1 * 8 + 3]) << 0x18)))])
        } else {
            c2da_lin_printf(uint64(f_0), 716341, [])
        }
        i_1++
    }
    ED_WriteGlobals(f_0)
    i_1 = 0
    while (i_1 < int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        ED_Write(f_0, EDICT_NUM(i_1))
        c2da_std_fflush(uint64(f_0))
        i_1++
    }
    c2da_std_fclose(uint64(f_0))
    Con_Printf(716344, [])
    return
}
[sideeffects]
def private Host_SavegameComment_c2da_frame(var text : int; c2da_fp : int) {
    var i_2 : int = 0
    while (i_2 < 39) {
        let c2da_fresh79 : int8 = int8(32)
        c2da_mem[text + i_2] = uint8(c2da_fresh79)
        i_2++
    }
    c2da_lin_memcpy(text, 4904, uint64(c2da_lin_strlen(4904)))
    c2da_lin_snprintf(c2da_fp, 2147483647ul, 716351, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[236 + 14 * 4]) | uint(c2da_mem[236 + 14 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 14 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 14 * 4 + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[236 + 12 * 4]) | uint(c2da_mem[236 + 12 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 12 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 12 * 4 + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    c2da_lin_memcpy(text + 22, c2da_fp, uint64(c2da_lin_strlen(c2da_fp)))
    i_2 = 0
    for (c2da_i_2 in range(i_2, 39)) {
        if (int(int8(c2da_mem[text + c2da_i_2])) == 32) {
            let c2da_fresh80 : int8 = int8(95)
            c2da_mem[text + c2da_i_2] = uint8(c2da_fresh80)
        }
    }
    let c2da_fresh81 : int8 = int8(0)
    c2da_mem[text + 39] = uint8(c2da_fresh81)
    return
}
[sideeffects]
def private Host_Loadgame_f_c2da_frame(c2da_fp : int) {
    var f_1 : int
    var start : int
    var i_3 : int
    var r : int
    var ent : int
    var entnum : int
    if (uint(cmd_source) != 1u) {
        return
    }
    if (Cmd_Argc() != 2) {
        Con_Printf(716365, [])
        return
    }
    let c2da_fresh82 : int = -1
    let c2da_fresh83 : uint = uint(c2da_fresh82)
    c2da_mem[7636] = uint8(c2da_fresh83)
    c2da_mem[7637] = uint8(c2da_fresh83 >> 0x8)
    c2da_mem[7638] = uint8(c2da_fresh83 >> 0x10)
    c2da_mem[7639] = uint8(c2da_fresh83 >> 0x18)
    c2da_lin_snprintf(c2da_fp, 2147483647ul, 716267, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 5392ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(Cmd_Argv(1)))])
    COM_DefaultExtension(c2da_fp, 716273)
    Con_Printf(716396, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    f_1 = c2da_lin_fopen(c2da_fp, 716421)
    if (f_1 == 0) {
        Con_Printf(716302, [])
        return
    }
    c2da_lin_fscanf(uint64(f_1), 716325, [c2da_fp + 128])
    if (int(uint(c2da_mem[c2da_fp + 128]) | uint(c2da_mem[c2da_fp + 129]) << 0x8 | uint(c2da_mem[c2da_fp + 130]) << 0x10 | uint(c2da_mem[c2da_fp + 131]) << 0x18) != 5) {
        c2da_std_fclose(uint64(f_1))
        Con_Printf(716423, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[c2da_fp + 128]) | uint(c2da_mem[c2da_fp + 129]) << 0x8 | uint(c2da_mem[c2da_fp + 130]) << 0x10 | uint(c2da_mem[c2da_fp + 131]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = 5l, f64 = 0.0lf, raw = 0x0)])
        return
    }
    c2da_lin_fscanf(uint64(f_1), 716329, [c2da_fp + 144])
    i_3 = 0
    while (i_3 < 16) {
        c2da_lin_fscanf(uint64(f_1), 716333, [c2da_fp + 32912 + i_3 * 4])
        i_3++
    }
    c2da_lin_fscanf(uint64(f_1), 716333, [c2da_fp + 32976])
    current_skill = int(double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 32976]) | uint(c2da_mem[c2da_fp + 32977]) << 0x8 | uint(c2da_mem[c2da_fp + 32978]) << 0x10 | uint(c2da_mem[c2da_fp + 32979]) << 0x18)) + 0.1lf)
    Cvar_SetValue(716455, float(current_skill))
    c2da_lin_fscanf(uint64(f_1), 716329, [c2da_fp + 32992])
    c2da_lin_fscanf(uint64(f_1), 716333, [c2da_fp + 33056])
    CL_Disconnect_f()
    SV_SpawnServer(c2da_fp + 32992)
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u) {
        Con_Printf(716461, [])
        return
    }
    let c2da_fresh84 : uint = 1u
    let c2da_fresh85 : uint = c2da_fresh84
    c2da_mem[225860] = uint8(c2da_fresh85)
    c2da_mem[225861] = uint8(c2da_fresh85 >> 0x8)
    c2da_mem[225862] = uint8(c2da_fresh85 >> 0x10)
    c2da_mem[225863] = uint8(c2da_fresh85 >> 0x18)
    let c2da_fresh86 : uint = 1u
    let c2da_fresh87 : uint = c2da_fresh86
    c2da_mem[225864] = uint8(c2da_fresh87)
    c2da_mem[225865] = uint8(c2da_fresh87 >> 0x8)
    c2da_mem[225866] = uint8(c2da_fresh87 >> 0x10)
    c2da_mem[225867] = uint8(c2da_fresh87 >> 0x18)
    i_3 = 0
    while (i_3 < 64) {
        c2da_lin_fscanf(uint64(f_1), 716329, [c2da_fp + 144])
        let c2da_fresh88 : int = Hunk_Alloc(int(c2da_lin_strlen(c2da_fp + 144) + 1ul))
        let c2da_fresh89 : uint = uint(c2da_fresh88)
        c2da_mem[232176 + i_3 * 8] = uint8(c2da_fresh89)
        c2da_mem[232176 + i_3 * 8 + 1] = uint8(c2da_fresh89 >> 0x8)
        c2da_mem[232176 + i_3 * 8 + 2] = uint8(c2da_fresh89 >> 0x10)
        c2da_mem[232176 + i_3 * 8 + 3] = uint8(c2da_fresh89 >> 0x18)
        c2da_mem[232176 + i_3 * 8 + 4] = 0u8
        c2da_mem[232176 + i_3 * 8 + 5] = 0u8
        c2da_mem[232176 + i_3 * 8 + 6] = 0u8
        c2da_mem[232176 + i_3 * 8 + 7] = 0u8
        c2da_lin_strcpy(int(uint(c2da_mem[232176 + i_3 * 8]) | uint(c2da_mem[232176 + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[232176 + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[232176 + i_3 * 8 + 3]) << 0x18), c2da_fp + 144)
        i_3++
    }
    entnum = -1
    while (c2da_std_feof(uint64(f_1)) == 0) {
        i_3 = 0
        while (uint64(i_3) < 32768ul - 1ul) {
            r = c2da_lin_fgetc(uint64(f_1))
            if (r == -1 || r == 0) {
                break
            }
            let c2da_fresh90 : int8 = int8(r)
            c2da_mem[c2da_fp + 144 + i_3] = uint8(c2da_fresh90)
            if (r == 125) {
                i_3++
                break
            }
            i_3++
        }
        if (uint64(i_3) == 32768ul - 1ul) {
            Sys_Error(716480, [])
        }
        let c2da_fresh91 : int8 = int8(0)
        c2da_mem[c2da_fp + 144 + i_3] = uint8(c2da_fresh91)
        start = c2da_fp + 144
        start = COM_Parse(c2da_fp + 144)
        if (int8(c2da_mem[194480 + 0]) == 0) {
            break
        }
        if (c2da_lin_strcmp(194480, 716505) != 0) {
            Sys_Error(716507, [])
        }
        if (entnum == -1) {
            ED_ParseGlobals(start)
        } else {
            ent = EDICT_NUM(entnum)
            c2da_lin_memset(ent + 108, 0, uint64(int(uint(c2da_mem[progs + 56]) | uint(c2da_mem[progs + 57]) << 0x8 | uint(c2da_mem[progs + 58]) << 0x10 | uint(c2da_mem[progs + 59]) << 0x18) * 4))
            let c2da_fresh92 : uint = 0u
            let c2da_fresh93 : uint = c2da_fresh92
            c2da_mem[ent] = uint8(c2da_fresh93)
            c2da_mem[ent + 1] = uint8(c2da_fresh93 >> 0x8)
            c2da_mem[ent + 2] = uint8(c2da_fresh93 >> 0x10)
            c2da_mem[ent + 3] = uint8(c2da_fresh93 >> 0x18)
            ED_ParseEdict(start, ent)
            if ((uint(c2da_mem[ent]) | uint(c2da_mem[ent + 1]) << 0x8 | uint(c2da_mem[ent + 2]) << 0x10 | uint(c2da_mem[ent + 3]) << 0x18) == 0u) {
                SV_LinkEdict(ent, 0u)
            }
        }
        entnum++
    }
    let c2da_fresh94 : uint = uint(entnum)
    c2da_mem[232688] = uint8(c2da_fresh94)
    c2da_mem[232689] = uint8(c2da_fresh94 >> 0x8)
    c2da_mem[232690] = uint8(c2da_fresh94 >> 0x10)
    c2da_mem[232691] = uint8(c2da_fresh94 >> 0x18)
    let c2da_fresh95 : double = double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 33056]) | uint(c2da_mem[c2da_fp + 33057]) << 0x8 | uint(c2da_mem[c2da_fp + 33058]) << 0x10 | uint(c2da_mem[c2da_fp + 33059]) << 0x18))
    let c2da_fresh96 : uint64 = double_bits_to_uint64(c2da_fresh95)
    c2da_mem[225872] = uint8(c2da_fresh96)
    c2da_mem[225873] = uint8(c2da_fresh96 >> 0x8)
    c2da_mem[225874] = uint8(c2da_fresh96 >> 0x10)
    c2da_mem[225875] = uint8(c2da_fresh96 >> 0x18)
    c2da_mem[225876] = uint8(c2da_fresh96 >> 0x20)
    c2da_mem[225877] = uint8(c2da_fresh96 >> 0x28)
    c2da_mem[225878] = uint8(c2da_fresh96 >> 0x30)
    c2da_mem[225879] = uint8(c2da_fresh96 >> 0x38)
    c2da_std_fclose(uint64(f_1))
    i_3 = 0
    for (c2da_i_3 in range(i_3, 16)) {
        let c2da_fresh97 : int = svs.clients + 8216 + c2da_i_3 * 4
        let c2da_fresh98 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32912 + c2da_i_3 * 4]) | uint(c2da_mem[c2da_fp + 32912 + c2da_i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32912 + c2da_i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32912 + c2da_i_3 * 4 + 3]) << 0x18)
        let c2da_fresh99 : uint = float_bits_to_uint(c2da_fresh98)
        c2da_mem[c2da_fresh97] = uint8(c2da_fresh99)
        c2da_mem[c2da_fresh97 + 1] = uint8(c2da_fresh99 >> 0x8)
        c2da_mem[c2da_fresh97 + 2] = uint8(c2da_fresh99 >> 0x10)
        c2da_mem[c2da_fresh97 + 3] = uint8(c2da_fresh99 >> 0x18)
    }
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) != 0u) {
        CL_EstablishConnection(716533)
        Host_Reconnect_f()
    }
    return
}
[sideeffects]
def private Host_Tell_f_c2da_frame(c2da_fp : int) {
    var client_1 : int
    var save_0 : int
    var j_0 : int
    var p : int
    if (uint(cmd_source) == 1u) {
        Cmd_ForwardToServer()
        return
    }
    if (Cmd_Argc() < 3) {
        return
    }
    Q_strcpy(c2da_fp, host_client + 8112)
    Q_strcat(c2da_fp, 716967)
    p = Cmd_Args()
    if (int(int8(c2da_mem[p])) == 34) {
        p++
        let c2da_fresh134 : int = p + int(Q_strlen(p) - 1)
        let c2da_fresh135 : int8 = int8(0)
        c2da_mem[c2da_fresh134] = uint8(c2da_fresh135)
    }
    j_0 = int(64ul - 2ul - uint64(Q_strlen(c2da_fp)))
    if (Q_strlen(p) > j_0) {
        let c2da_fresh136 : int8 = int8(0)
        c2da_mem[p + j_0] = uint8(c2da_fresh136)
    }
    c2da_lin_strcat(c2da_fp, p)
    c2da_lin_strcat(c2da_fp, 716970)
    save_0 = host_client
    j_0 = 0
    client_1 = svs.clients
    while (j_0 < svs.maxclients) {
        if ((uint(c2da_mem[client_1]) | uint(c2da_mem[client_1 + 1]) << 0x8 | uint(c2da_mem[client_1 + 2]) << 0x10 | uint(c2da_mem[client_1 + 3]) << 0x18) == 0u || (uint(c2da_mem[client_1 + 4]) | uint(c2da_mem[client_1 + 5]) << 0x8 | uint(c2da_mem[client_1 + 6]) << 0x10 | uint(c2da_mem[client_1 + 7]) << 0x18) == 0u) {
            j_0++
            client_1 += 8288
            continue
        }
        if (Q_strcasecmp(client_1 + 8112, Cmd_Argv(1)) != 0) {
            j_0++
            client_1 += 8288
            continue
        }
        host_client = client_1
        SV_ClientPrintf(716972, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
        break
    }
    host_client = save_0
    return
}
[sideeffects]
def private Host_Say_c2da_frame(var teamonly : uint; c2da_fp : int) {
    var client_2 : int
    var save_1 : int
    var j_1 : int
    var p_0 : int
    var fromServer : uint = 0u
    if (uint(cmd_source) == 1u) {
        if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 0u) {
            fromServer = 1u
            teamonly = 0u
        } else {
            Cmd_ForwardToServer()
            return
        }
    }
    if (Cmd_Argc() < 2) {
        return
    }
    save_1 = host_client
    p_0 = Cmd_Args()
    if (int(int8(c2da_mem[p_0])) == 34) {
        p_0++
        let c2da_fresh137 : int = p_0 + int(Q_strlen(p_0) - 1)
        let c2da_fresh138 : int8 = int8(0)
        c2da_mem[c2da_fresh137] = uint8(c2da_fresh138)
    }
    if (fromServer == 0u) {
        c2da_lin_snprintf(c2da_fp, 2147483647ul, 716975, [C2daVaArg(tag = 1, i64 = 1l, f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(save_1 + 8112))])
    } else {
        c2da_lin_snprintf(c2da_fp, 2147483647ul, 716982, [C2daVaArg(tag = 1, i64 = 1l, f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[386472]) | uint(c2da_mem[386473]) << 0x8 | uint(c2da_mem[386474]) << 0x10 | uint(c2da_mem[386475]) << 0x18)))])
    }
    j_1 = int(64ul - 2ul - uint64(Q_strlen(c2da_fp)))
    if (Q_strlen(p_0) > j_1) {
        let c2da_fresh139 : int8 = int8(0)
        c2da_mem[p_0 + j_1] = uint8(c2da_fresh139)
    }
    c2da_lin_strcat(c2da_fp, p_0)
    c2da_lin_strcat(c2da_fp, 716970)
    j_1 = 0
    client_2 = svs.clients
    while (j_1 < svs.maxclients) {
        if (client_2 == 0 || (uint(c2da_mem[client_2]) | uint(c2da_mem[client_2 + 1]) << 0x8 | uint(c2da_mem[client_2 + 2]) << 0x10 | uint(c2da_mem[client_2 + 3]) << 0x18) == 0u || (uint(c2da_mem[client_2 + 4]) | uint(c2da_mem[client_2 + 5]) << 0x8 | uint(c2da_mem[client_2 + 6]) << 0x10 | uint(c2da_mem[client_2 + 7]) << 0x18) == 0u) {
            j_1++
            client_2 += 8288
            continue
        }
        var c2da_fresh142 : int = 0
        if (uint_bits_to_float(uint(c2da_mem[243464]) | uint(c2da_mem[243465]) << 0x8 | uint(c2da_mem[243466]) << 0x10 | uint(c2da_mem[243467]) << 0x18) != 0.0 && teamonly != 0x0) {
            let c2da_fresh140 : int = int(uint(c2da_mem[client_2 + 8104]) | uint(c2da_mem[client_2 + 8105]) << 0x8 | uint(c2da_mem[client_2 + 8106]) << 0x10 | uint(c2da_mem[client_2 + 8107]) << 0x18) + 420
            let c2da_fresh141 : int = int(uint(c2da_mem[save_1 + 8104]) | uint(c2da_mem[save_1 + 8105]) << 0x8 | uint(c2da_mem[save_1 + 8106]) << 0x10 | uint(c2da_mem[save_1 + 8107]) << 0x18) + 420
            if (uint_bits_to_float(uint(c2da_mem[c2da_fresh140]) | uint(c2da_mem[c2da_fresh140 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh140 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh140 + 3]) << 0x18) != uint_bits_to_float(uint(c2da_mem[c2da_fresh141]) | uint(c2da_mem[c2da_fresh141 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh141 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh141 + 3]) << 0x18)) {
                c2da_fresh142 = 1
            }
        }
        if (c2da_fresh142 != 0) {
            j_1++
            client_2 += 8288
            continue
        }
        host_client = client_2
        SV_ClientPrintf(716972, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
        j_1++
        client_2 += 8288
    }
    host_client = save_1
    Sys_Printf(716972, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp + 1))])
    return
}
[sideeffects]
def private Host_Connect_f_c2da_frame(c2da_fp : int) {
    let c2da_fresh151 : int = -1
    let c2da_fresh152 : uint = uint(c2da_fresh151)
    c2da_mem[7636] = uint8(c2da_fresh152)
    c2da_mem[7637] = uint8(c2da_fresh152 >> 0x8)
    c2da_mem[7638] = uint8(c2da_fresh152 >> 0x10)
    c2da_mem[7639] = uint8(c2da_fresh152 >> 0x18)
    if ((uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) != 0u) {
        CL_StopPlayback()
        CL_Disconnect()
    }
    c2da_lin_strcpy(c2da_fp, int(Cmd_Argv(1)))
    CL_EstablishConnection(c2da_fp)
    Host_Reconnect_f()
    return
}
[sideeffects]
def private Host_Changelevel_f_c2da_frame(c2da_fp : int) {
    if (Cmd_Argc() != 2) {
        Con_Printf(717110, [])
        return
    }
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u || (uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) != 0x0) {
        Con_Printf(717166, [])
        return
    }
    SV_SaveSpawnparms()
    c2da_lin_strcpy(c2da_fp, int(Cmd_Argv(1)))
    SV_SpawnServer(c2da_fp)
    return
}
[sideeffects]
def private Host_Restart_f_c2da_frame(c2da_fp : int) {
    if ((uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) != 0x0 || (uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u) {
        return
    }
    if (uint(cmd_source) != 1u) {
        return
    }
    c2da_lin_strcpy(c2da_fp, 225896)
    SV_SpawnServer(c2da_fp)
    return
}
[sideeffects]
def private Host_Map_f_c2da_frame(c2da_fp : int) {
    var i_7 : int
    if (uint(cmd_source) != 1u) {
        return
    }
    let c2da_fresh153 : int = -1
    let c2da_fresh154 : uint = uint(c2da_fresh153)
    c2da_mem[7636] = uint8(c2da_fresh154)
    c2da_mem[7637] = uint8(c2da_fresh154 >> 0x8)
    c2da_mem[7638] = uint8(c2da_fresh154 >> 0x10)
    c2da_mem[7639] = uint8(c2da_fresh154 >> 0x18)
    CL_Disconnect()
    Host_ShutdownServer(0u)
    key_dest = 0u
    SCR_BeginLoadingPlaque()
    let c2da_fresh155 : int8 = int8(0)
    c2da_mem[5524 + 0] = uint8(c2da_fresh155)
    i_7 = 0
    while (i_7 < Cmd_Argc()) {
        c2da_lin_strcat(5524, int(Cmd_Argv(i_7)))
        c2da_lin_strcat(5524, 717199)
        i_7++
    }
    c2da_lin_strcat(5524, 716970)
    svs.serverflags = 0
    c2da_lin_strcpy(c2da_fp, int(Cmd_Argv(1)))
    SV_SpawnServer(c2da_fp)
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u) {
        return
    }
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) != 0u) {
        c2da_lin_strcpy(5588, 717201)
        i_7 = 2
        while (i_7 < Cmd_Argc()) {
            c2da_lin_strcat(5588, int(Cmd_Argv(i_7)))
            c2da_lin_strcat(5588, 717199)
            i_7++
        }
        Cmd_ExecuteString(717202, 1u)
    }
    return
}

// This unit's static data, at heap offset 715616.
let private c2da_lin_static_host_cmd_seg = fixed_array<int>(715616, 1826)
let private c2da_lin_static_host_cmd = fixed_array<uint64>(0x7100737574617473ul, 0x646f6700746975ul, 0x7465677261746f6eul, 0x70616d00796c6600ul, 0x7472617473657200ul, 0x6c65676e61686300ul, 0x6e6f63006c657665ul, 0x636572007463656eul, 0x6e007463656e6e6ful, 0x6c636f6e00656d61ul, 0x6973726576007069ul, 0x7300796173006e6ful, 0x6d6165745f7961ul, 0x6c6f63006c6c6574ul, 0x6c6c696b00726ful, 0x7073006573756170ul, 0x69676562006e7761ul, 0x617073657270006eul, 0x6b63696b006e77ul, 0x616f6c00676e6970ul, 0x6700657661730064ul, 0x7261747300657669ul, 0x6400736f6d656474ul, 0x6f747300736f6d65ul, 0x6976006f6d656470ul, 0x6c65646f6d7765ul, 0x6d61726677656976ul, 0x656e776569760065ul, 0x7077656976007478ul, 0x6361636d00766572ul, 0x656d617266006568ul, 0xa7325203a692520ul, 0x6968747765697600ul, 0x6976206f4e00676eul, 0x20676e6968747765ul, 0xa70616d206e6ful, 0x6f6c2074276e6143ul, 0x6d000a7325206461ul, 0x7472617473207061ul, 0x69252078614d000aul, 0x6920736f6d656420ul, 0x6f6c6f6d6564206eul, 0x64206925000a706ful, 0x69202973286f6d65ul, 0xa706f6f6c206eul, 0x6568735f6f6d6d61ul, 0x6d6d610031736c6cul, 0x31736c69616e5f6ful, 0x616c5f6f6d6d6100ul, 0x736c69616e5f6176ul, 0x6f725f6f6d6d6100ul, 0x6100317374656b63ul, 0x746c756d5f6f6d6dul, 0x74656b636f725f69ul, 0x635f6f6d6d610073ul, 0x6d610031736c6c65ul, 0x6d73616c705f6f6dul, 0x6c7020746f4e0061ul, 0x206120676e697961ul, 0x6167206c61636f6cul, 0x6e6143000a2e656dul, 0x2065766173207427ul, 0x7265746e69206e69ul, 0x2e6e6f697373696dul, 0x2074276e6143000aul, 0x6c756d2065766173ul, 0x726579616c706974ul, 0xa2e73656d616720ul, 0x733c206576617300ul, 0x3e656d616e657661ul, 0x2065766173203a20ul, 0xa656d61672061ul, 0x74616c6552002e2eul, 0x6874617020657669ul, 0x72612073656d616eul, 0x6c6120746f6e2065ul, 0xa2e6465776f6cul, 0x61732074276e6143ul, 0x7720656d61676576ul, 0x6564206120687469ul, 0x6579616c70206461ul, 0x73252f7325000a72ul, 0x6153007661732e00ul, 0x6d616720676e6976ul, 0x2e7325206f742065ul, 0x52450077000a2e2eul, 0x756f63203a524f52ul, 0x706f2074276e646cul, 0xa6925000a2e6e65ul, 0xa6625000a732500ul, 0xa6d000a642500ul, 0x6b000a2e656e6f64ul, 0x6933253a736c6c69ul, 0x616f6c006933252ful, 0x6e657661733c2064ul, 0x6c203a203e656d61ul, 0x616720612064616ful, 0x64616f4c000a656dul, 0x656d616720676e69ul, 0x7325206d6f726620ul, 0x530072000a2e2e2eul, 0x20656d6167657661ul, 0x6973726576207369ul, 0x6e202c6925206e6ful, 0x73000a692520746ful, 0x756f43006c6c696bul, 0x6f6c2074276e646cul, 0xa70616d206461ul, 0x656d616764616f4cul, 0x2072656666756220ul, 0x776f6c667265766ful, 0x7473726946007b00ul, 0x69206e656b6f7420ul, 0x6220612074276e73ul, 0x636f6c0065636172ul, 0x6e65696c43006c61ul, 0x7420676e69702074ul, 0x25000a3a73656d69ul, 0x23000a7325206934ul, 0x656c6f736e6f4300ul, 0x2064656b63694b00ul, 0x25203a7325207962ul, 0x656b63694b000a73ul, 0xa73252079622064ul, 0x7761707365727000ul, 0x746f6e207369206eul, 0x662064696c617620ul, 0x20656874206d6f72ul, 0xa656c6f736e6f63ul, 0x7761707365727000ul, 0x617620746f6e206eul, 0x61202d2d2064696cul, 0x2079646165726c6cul, 0xa64656e77617073ul, 0x69206e6967656200ul, 0x617620746f6e2073ul, 0x6d6f72662064696cul, 0x6e6f632065687420ul, 0x7073000a656c6f73ul, 0x6e207369206e7761ul, 0x64696c617620746ful, 0x6874206d6f726620ul, 0x6c6f736e6f632065ul, 0x6e77617053000a65ul, 0x6c617620746f6e20ul, 0x6c61202d2d206469ul, 0x732079646165726cul, 0xa64656e776170ul, 0x7265746e65207325ul, 0x6720656874206465ul, 0x756150000a656d61ul, 0x6120746f6e206573ul, 0xa2e6465776f6c6cul, 0x7375617020732500ul, 0x6720656874206465ul, 0x207325000a656d61ul, 0x6465737561706e75ul, 0x6d61672065687420ul, 0x74276e6143000a65ul, 0x6564696369757320ul, 0x726c6c61202d2d20ul, 0x6165642079646165ul, 0x6c6f6322000a2164ul, 0x222073692022726ful, 0xa226925206925ul, 0x303c20726f6c6f63ul, 0x2d305b203e33312dul, 0x6c635f000a5d3331ul, 0x3a00726f6c6f635ful, 0x25007325000a0020ul, 0x632500203a732563ul, 0x655600203e73253cul, 0x3425206e6f697372ul, 0x657845000a66322eul, 0x3a30353a3430203aul, 0x312074634f203632ul, 0xa363230322032ul, 0x4f2070696c636f6eul, 0x696c636f6e000a4eul, 0x22000a46464f2070ul, 0x73692022656d616eul, 0x5f000a2273252220ul, 0x656d616e5f6c63ul, 0x63656e6e6f636e75ul, 0x7220732500646574ul, 0x742064656d616e65ul, 0x6863000a7325206ful, 0x6576656c65676e61ul, 0x6c6576656c3c206cul, 0x203a203e656d616eul, 0x65756e69746e6f63ul, 0x6e6f20656d616720ul, 0x6c2077656e206120ul, 0x6e4f000a6c657665ul, 0x732065687420796cul, 0x616d207265767265ul, 0x65676e6168632079ul, 0x20000a6c6576656cul, 0x63656e6e6f630000ul, 0x6c61636f6c2074ul, 0x2065646f6d796c66ul, 0x6d796c66000a4e4ful, 0xa46464f2065646ful, 0x65677261746f6e00ul, 0x6e000a46464f2074ul, 0x207465677261746ful, 0x6d646f67000a4e4ful, 0xa46464f2065646ful, 0x65646f6d646f6700ul, 0x736f68000a4e4f20ul, 0x7325202020203a74ul, 0x616e74736f68000aul, 0x697372657600656dul, 0x322e3425203a6e6ful, 0x692f706374000a66ul, 0xa732520203a70ul, 0x202020203a787069ul, 0x70616d000a732520ul, 0x732520202020203aul, 0x726579616c70000aul, 0x6361206925203a73ul, 0x6925282065766974ul, 0xa0a2978616d20ul, 0x2d252075322d2523ul, 0x20207336312e3631ul, 0x6932252020693325ul, 0x30253a693230253aul, 0x25202020000a6932ul, 0xa73ul)

[init]
def private c2da_lin_init_static_host_cmd() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_host_cmd_seg[s * 2]
        for (k in range(c2da_lin_static_host_cmd_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_host_cmd[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_host_cmd() {
    if (length(c2da_fn_table0) < 94) {
        resize(c2da_fn_table0, 94)
    }
    c2da_fn_table0[93] = @@Host_Viewprev_f
    c2da_fn_table0[92] = @@Host_Viewnext_f
    c2da_fn_table0[91] = @@Host_Viewframe_f
    c2da_fn_table0[90] = @@Host_Viewmodel_f
    c2da_fn_table0[89] = @@Host_Stopdemo_f
    c2da_fn_table0[88] = @@Host_Demos_f
    c2da_fn_table0[87] = @@Host_Startdemos_f
    c2da_fn_table0[86] = @@Host_Give_f
    c2da_fn_table0[85] = @@Host_Savegame_f
    c2da_fn_table0[84] = @@Host_Loadgame_f
    c2da_fn_table0[69] = @@Host_Reconnect_f
    c2da_fn_table0[83] = @@Host_Ping_f
    c2da_fn_table0[82] = @@Host_Kick_f
    c2da_fn_table0[81] = @@Host_PreSpawn_f
    c2da_fn_table0[80] = @@Host_Begin_f
    c2da_fn_table0[79] = @@Host_Spawn_f
    c2da_fn_table0[78] = @@Host_Pause_f
    c2da_fn_table0[77] = @@Host_Kill_f
    c2da_fn_table0[76] = @@Host_Color_f
    c2da_fn_table0[75] = @@Host_Tell_f
    c2da_fn_table0[74] = @@Host_Say_Team_f
    c2da_fn_table0[73] = @@Host_Say_f
    c2da_fn_table0[72] = @@Host_Version_f
    c2da_fn_table0[71] = @@Host_Noclip_f
    c2da_fn_table0[70] = @@Host_Name_f
    c2da_fn_table0[68] = @@Host_Connect_f
    c2da_fn_table0[67] = @@Host_Changelevel_f
    c2da_fn_table0[66] = @@Host_Restart_f
    c2da_fn_table0[65] = @@Host_Map_f
    c2da_fn_table0[64] = @@Host_Fly_f
    c2da_fn_table0[63] = @@Host_Notarget_f
    c2da_fn_table0[62] = @@Host_God_f
    c2da_fn_table0[61] = @@Host_Quit_f
    c2da_fn_table0[60] = @@Host_Status_f
}

[init]
def private c2da_lin_relink_init_host_cmd() {
    c2da_relink_host_cmd()
}
