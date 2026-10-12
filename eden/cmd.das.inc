[export, sideeffects]
def Cbuf_Init() {
    SZ_Alloc(194448, 8192)
    return
}
[export, sideeffects]
def Cbuf_AddText(var text : int) {
    var l : int = Q_strlen(text)
    if (int(uint(c2da_mem[194468]) | uint(c2da_mem[194469]) << 0x8 | uint(c2da_mem[194470]) << 0x10 | uint(c2da_mem[194471]) << 0x18) + l >= int(uint(c2da_mem[194464]) | uint(c2da_mem[194465]) << 0x8 | uint(c2da_mem[194466]) << 0x10 | uint(c2da_mem[194467]) << 0x18)) {
        Con_Printf(700624, [])
        return
    }
    SZ_Write(194448, text, Q_strlen(text))
    return
}
[export, sideeffects]
def Cbuf_InsertText(var text_0 : int) {
    var temp : int
    var templen : int = int(uint(c2da_mem[194468]) | uint(c2da_mem[194469]) << 0x8 | uint(c2da_mem[194470]) << 0x10 | uint(c2da_mem[194471]) << 0x18)
    if (templen != 0) {
        temp = Z_Malloc(templen)
        Q_memcpy(temp, int(uint(c2da_mem[194456]) | uint(c2da_mem[194457]) << 0x8 | uint(c2da_mem[194458]) << 0x10 | uint(c2da_mem[194459]) << 0x18), templen)
        SZ_Clear(194448)
    } else {
        temp = 0
    }
    Cbuf_AddText(text_0)
    if (templen != 0) {
        SZ_Write(194448, temp, templen)
        Z_Free(temp)
    }
    return
}
[export, sideeffects]
def Cbuf_Execute() {
    let c2da_saved_sp : int = c2da_lin_sp
    Cbuf_Execute_c2da_frame(c2da_lin_enter(1024))
    c2da_lin_sp = c2da_saved_sp
}
var cmd_wait : uint = default<uint>

[export, sideeffects]
def Cmd_ExecuteString(var text_2 : int; var src : uint) {
    var cmd_0 : int
    var a : int
    cmd_source = uint(src)  // nolint:PERF020
    Cmd_TokenizeString(text_2)
    if (Cmd_Argc() == 0) {
        return
    }
    cmd_0 = cmd_functions
    while (cmd_0 != 0) {
        if (Q_strcasecmp(cmd_argv[0], int(uint(c2da_mem[cmd_0 + 8]) | uint(c2da_mem[cmd_0 + 9]) << 0x8 | uint(c2da_mem[cmd_0 + 10]) << 0x10 | uint(c2da_mem[cmd_0 + 11]) << 0x18)) == 0) {
            invoke(c2da_fn_table0[int(uint(c2da_mem[cmd_0 + 16]) | uint(c2da_mem[cmd_0 + 17]) << 0x8 | uint(c2da_mem[cmd_0 + 18]) << 0x10 | uint(c2da_mem[cmd_0 + 19]) << 0x18)])
            return
        }
        cmd_0 = int(uint(c2da_mem[cmd_0]) | uint(c2da_mem[cmd_0 + 1]) << 0x8 | uint(c2da_mem[cmd_0 + 2]) << 0x10 | uint(c2da_mem[cmd_0 + 3]) << 0x18)
    }
    a = cmd_alias
    while (a != 0) {
        if (Q_strcasecmp(cmd_argv[0], a + 8) == 0) {
            Cbuf_InsertText(int(uint(c2da_mem[a + 40]) | uint(c2da_mem[a + 41]) << 0x8 | uint(c2da_mem[a + 42]) << 0x10 | uint(c2da_mem[a + 43]) << 0x18))
            return
        }
        a = int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18)
    }
    if (uint(Cvar_Command()) == 0u) {
        Con_Printf(700648, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(Cmd_Argv(0)))])
    }
    return
}
[export, sideeffects]
def Cmd_Argv(var arg : int) : int {
    if (uint(arg) >= uint(cmd_argc)) {
        return cmd_null_string
    }
    return cmd_argv[arg]
}
var private cmd_argv : int[80]

var private cmd_null_string : int = 700670

var private cmd_argc : int = default<int>

var cmd_alias : int = default<int>

var private cmd_functions : int = default<int>

[export, sideeffects]
def Cmd_Argc() : int {
    return cmd_argc
}
[export, sideeffects]
def Cmd_TokenizeString(var text_3 : int) {
    var i_0 : int = 0
    while (i_0 < cmd_argc) {
        Z_Free(cmd_argv[i_0])
        i_0++
    }
    cmd_argc = 0
    cmd_args = 0
    while (true) {
        while (int(int8(c2da_mem[text_3])) != 0 && int(int8(c2da_mem[text_3])) <= 32 && int(int8(c2da_mem[text_3])) != 10) {
            text_3++
        }
        if (int(int8(c2da_mem[text_3])) == 10) {
            text_3++
            break
        }
        if (int8(c2da_mem[text_3]) == 0) {
            return
        }
        if (cmd_argc == 1) {
            cmd_args = int(text_3)  // nolint:PERF020
        }
        text_3 = COM_Parse(text_3)
        if (text_3 == 0) {
            return
        }
        if (cmd_argc < 80) {
            cmd_argv[cmd_argc] = Z_Malloc(Q_strlen(194480) + 1)
            Q_strcpy(cmd_argv[cmd_argc], 194480)
            cmd_argc++
        }
    }
    return
}
var private cmd_args : int = 0

var cmd_source : uint = default<uint>

[export, sideeffects]
def Cmd_Init() {
    Cmd_AddCommand(700671, 42)
    Cmd_AddCommand(700681, 43)
    Cmd_AddCommand(700686, 44)
    Cmd_AddCommand(700691, 45)
    Cmd_AddCommand(700697, 46)
    Cmd_AddCommand(700701, 47)
    return
}
[export, sideeffects]
def Cmd_Wait_f() {
    cmd_wait = 1u
    return
}
[export, sideeffects]
def Cmd_AddCommand(var cmd_name : int; var function_0 : xcommand_t) {
    var cmd_1 : int
    if (uint(host_initialized) != 0u) {
        Sys_Error(700706, [])
    }
    let c2da_fresh6 : int = Cvar_VariableString(cmd_name) + 0
    if (int8(c2da_mem[c2da_fresh6]) != 0) {
        Con_Printf(700744, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(cmd_name))])
        return
    }
    cmd_1 = cmd_functions
    while (cmd_1 != 0) {
        if (Q_strcmp(cmd_name, int(uint(c2da_mem[cmd_1 + 8]) | uint(c2da_mem[cmd_1 + 9]) << 0x8 | uint(c2da_mem[cmd_1 + 10]) << 0x10 | uint(c2da_mem[cmd_1 + 11]) << 0x18)) == 0) {
            Con_Printf(700789, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(cmd_name))])
            return
        }
        cmd_1 = int(uint(c2da_mem[cmd_1]) | uint(c2da_mem[cmd_1 + 1]) << 0x8 | uint(c2da_mem[cmd_1 + 2]) << 0x10 | uint(c2da_mem[cmd_1 + 3]) << 0x18)
    }
    cmd_1 = Hunk_Alloc(24)
    let c2da_fresh7 : uint = uint(cmd_name)
    c2da_mem[cmd_1 + 8] = uint8(c2da_fresh7)
    c2da_mem[cmd_1 + 9] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[cmd_1 + 10] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[cmd_1 + 11] = uint8(c2da_fresh7 >> 0x18)
    c2da_mem[cmd_1 + 12] = 0u8
    c2da_mem[cmd_1 + 13] = 0u8
    c2da_mem[cmd_1 + 14] = 0u8
    c2da_mem[cmd_1 + 15] = 0u8
    let c2da_fresh8 : uint = uint(function_0)
    c2da_mem[cmd_1 + 16] = uint8(c2da_fresh8)
    c2da_mem[cmd_1 + 17] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[cmd_1 + 18] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[cmd_1 + 19] = uint8(c2da_fresh8 >> 0x18)
    c2da_mem[cmd_1 + 20] = 0u8
    c2da_mem[cmd_1 + 21] = 0u8
    c2da_mem[cmd_1 + 22] = 0u8
    c2da_mem[cmd_1 + 23] = 0u8
    let c2da_fresh9 : uint = uint(cmd_functions)
    c2da_mem[cmd_1] = uint8(c2da_fresh9)
    c2da_mem[cmd_1 + 1] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[cmd_1 + 2] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[cmd_1 + 3] = uint8(c2da_fresh9 >> 0x18)
    c2da_mem[cmd_1 + 4] = 0u8
    c2da_mem[cmd_1 + 5] = 0u8
    c2da_mem[cmd_1 + 6] = 0u8
    c2da_mem[cmd_1 + 7] = 0u8
    cmd_functions = cmd_1
    return
}
[export, sideeffects]
def Cmd_ForwardToServer() {
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) != 2u) {
        Con_Printf(700825, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(Cmd_Argv(0)))])
        return
    }
    if ((uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) != 0u) {
        return
    }
    MSG_WriteByte(7816, 4)
    if (Q_strcasecmp(Cmd_Argv(0), 700697) != 0) {
        SZ_Print(7816, Cmd_Argv(0))
        SZ_Print(7816, 700852)
    }
    if (Cmd_Argc() > 1) {
        SZ_Print(7816, Cmd_Args())
    } else {
        SZ_Print(7816, 700854)
    }
    return
}
[export, sideeffects]
def Cmd_Args() : int {
    return cmd_args
}
[export, sideeffects]
def Cmd_Alias_f() {
    let c2da_saved_sp : int = c2da_lin_sp
    Cmd_Alias_f_c2da_frame(c2da_lin_enter(1024))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def CopyString(var in_0 : int) : int {
    var out : int = Z_Malloc(int(c2da_lin_strlen(in_0) + 1ul))
    c2da_lin_strcpy(out, in_0)
    return out
}
[export, sideeffects]
def Cmd_Echo_f() {
    var i_2 : int = 1
    while (i_2 < Cmd_Argc()) {
        Con_Printf(700914, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(Cmd_Argv(i_2)))])
        i_2++
    }
    Con_Printf(700854, [])
    return
}
[export, sideeffects]
def Cmd_Exec_f() {
    var f : int
    var mark : int
    if (Cmd_Argc() != 2) {
        Con_Printf(700918, [])
        return
    }
    mark = Hunk_LowMark()
    f = COM_LoadHunkFile(Cmd_Argv(1))
    if (f == 0) {
        Con_Printf(700959, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(Cmd_Argv(1)))])
        return
    }
    Con_Printf(700977, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(Cmd_Argv(1)))])
    Cbuf_InsertText(f)
    Hunk_FreeToLowMark(mark)
    return
}
[export, sideeffects]
def Cmd_StuffCmds_f() {
    var i_3 : int
    var j : int
    var s_0 : int
    var text_4 : int
    var build : int
    var c_0 : int8
    if (Cmd_Argc() != 1) {
        Con_Printf(700989, [])
        return
    }
    s_0 = 0
    i_3 = 1
    while (i_3 < int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18)) {
        if (int(uint(c2da_mem[com_argv + i_3 * 8]) | uint(c2da_mem[com_argv + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + i_3 * 8 + 3]) << 0x18) == 0) {
            i_3++
            continue
        }
        s_0 = s_0 + (Q_strlen(int(uint(c2da_mem[com_argv + i_3 * 8]) | uint(c2da_mem[com_argv + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + i_3 * 8 + 3]) << 0x18)) + 1)
        i_3++
    }
    if (s_0 == 0) {
        return
    }
    text_4 = Z_Malloc(s_0 + 1)
    let c2da_fresh14 : int8 = int8(0)
    c2da_mem[text_4 + 0] = uint8(c2da_fresh14)
    i_3 = 1
    while (i_3 < int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18)) {
        if (int(uint(c2da_mem[com_argv + i_3 * 8]) | uint(c2da_mem[com_argv + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + i_3 * 8 + 3]) << 0x18) == 0) {
            i_3++
            continue
        }
        Q_strcat(text_4, int(uint(c2da_mem[com_argv + i_3 * 8]) | uint(c2da_mem[com_argv + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + i_3 * 8 + 3]) << 0x18))
        if (i_3 != int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) - 1) {
            Q_strcat(text_4, 700852)
        }
        i_3++
    }
    build = Z_Malloc(s_0 + 1)
    let c2da_fresh15 : int8 = int8(0)
    c2da_mem[build + 0] = uint8(c2da_fresh15)
    i_3 = 0
    while (i_3 < s_0 - 1) {
        if (int(int8(c2da_mem[text_4 + i_3])) == 43) {
            i_3++
            j = i_3
            while (int(int8(c2da_mem[text_4 + j])) != 43 && int(int8(c2da_mem[text_4 + j])) != 45 && int(int8(c2da_mem[text_4 + j])) != 0) {
                j++
            }
            c_0 = int8(c2da_mem[text_4 + j])
            let c2da_fresh16 : int8 = int8(0)
            c2da_mem[text_4 + j] = uint8(c2da_fresh16)
            Q_strcat(build, text_4 + i_3)
            Q_strcat(build, 700854)
            c2da_mem[text_4 + j] = uint8(c_0)
            i_3 = j - 1
        }
        i_3++
    }
    if (int8(c2da_mem[build + 0]) != 0) {
        Cbuf_InsertText(build)
    }
    Z_Free(text_4)
    Z_Free(build)
    return
}
[export, sideeffects]
def Cmd_Exists(var cmd_name_0 : int) : uint {
    var cmd_2 : int = cmd_functions
    while (cmd_2 != 0) {
        if (Q_strcmp(cmd_name_0, int(uint(c2da_mem[cmd_2 + 8]) | uint(c2da_mem[cmd_2 + 9]) << 0x8 | uint(c2da_mem[cmd_2 + 10]) << 0x10 | uint(c2da_mem[cmd_2 + 11]) << 0x18)) == 0) {
            return 1u
        }
        cmd_2 = int(uint(c2da_mem[cmd_2]) | uint(c2da_mem[cmd_2 + 1]) << 0x8 | uint(c2da_mem[cmd_2 + 2]) << 0x10 | uint(c2da_mem[cmd_2 + 3]) << 0x18)
    }
    return 0u
}
[export, sideeffects]
def Cmd_CompleteCommand(var partial : int) : int {
    var cmd_3 : int
    var len : int = Q_strlen(partial)
    if (len == 0) {
        return 0
    }
    cmd_3 = cmd_functions
    while (cmd_3 != 0) {
        if (Q_strncmp(partial, int(uint(c2da_mem[cmd_3 + 8]) | uint(c2da_mem[cmd_3 + 9]) << 0x8 | uint(c2da_mem[cmd_3 + 10]) << 0x10 | uint(c2da_mem[cmd_3 + 11]) << 0x18), len) == 0) {
            return int(uint(c2da_mem[cmd_3 + 8]) | uint(c2da_mem[cmd_3 + 9]) << 0x8 | uint(c2da_mem[cmd_3 + 10]) << 0x10 | uint(c2da_mem[cmd_3 + 11]) << 0x18)
        }
        cmd_3 = int(uint(c2da_mem[cmd_3]) | uint(c2da_mem[cmd_3 + 1]) << 0x8 | uint(c2da_mem[cmd_3 + 2]) << 0x10 | uint(c2da_mem[cmd_3 + 3]) << 0x18)
    }
    return 0
}
[export, sideeffects]
def Cmd_CheckParm(var parm : int) : int {
    var i_4 : int
    if (parm == 0) {
        Sys_Error(701034, [])
    }
    i_4 = 1
    while (i_4 < Cmd_Argc()) {
        if (Q_strcasecmp(parm, Cmd_Argv(i_4)) == 0) {
            return i_4
        }
        i_4++
    }
    return 0
}
var trashtest : int = default<int>

var trashspot : int = default<int>

[sideeffects]
def private Cbuf_Execute_c2da_frame(c2da_fp : int) {
    var i : int
    var text_1 : int
    var quotes : int
    while (int(uint(c2da_mem[194468]) | uint(c2da_mem[194469]) << 0x8 | uint(c2da_mem[194470]) << 0x10 | uint(c2da_mem[194471]) << 0x18) != 0) {
        text_1 = int(uint(c2da_mem[194456]) | uint(c2da_mem[194457]) << 0x8 | uint(c2da_mem[194458]) << 0x10 | uint(c2da_mem[194459]) << 0x18)
        quotes = 0
        i = 0
        while (i < int(uint(c2da_mem[194468]) | uint(c2da_mem[194469]) << 0x8 | uint(c2da_mem[194470]) << 0x10 | uint(c2da_mem[194471]) << 0x18)) {
            if (int(int8(c2da_mem[text_1 + i])) == 34) {
                quotes++
            }
            if ((quotes & 1) == 0 && int(int8(c2da_mem[text_1 + i])) == 59) {
                break
            }
            if (int(int8(c2da_mem[text_1 + i])) == 10) {
                break
            }
            i++
        }
        c2da_lin_memcpy(c2da_fp, text_1, uint64(i))
        let c2da_fresh0 : int8 = int8(0)
        c2da_mem[c2da_fp + i] = uint8(c2da_fresh0)
        let c2da_fresh5 : int = int(uint(c2da_mem[194468]) | uint(c2da_mem[194469]) << 0x8 | uint(c2da_mem[194470]) << 0x10 | uint(c2da_mem[194471]) << 0x18)
        if (i == c2da_fresh5) {
            let c2da_fresh1 : int = 0
            let c2da_fresh2 : uint = uint(c2da_fresh1)
            c2da_mem[194468] = uint8(c2da_fresh2)
            c2da_mem[194469] = uint8(c2da_fresh2 >> 0x8)
            c2da_mem[194470] = uint8(c2da_fresh2 >> 0x10)
            c2da_mem[194471] = uint8(c2da_fresh2 >> 0x18)
        } else {
            i++
            let c2da_fresh3 : int = c2da_fresh5 - i
            let c2da_fresh4 : uint = uint(c2da_fresh3)
            c2da_mem[194468] = uint8(c2da_fresh4)
            c2da_mem[194469] = uint8(c2da_fresh4 >> 0x8)
            c2da_mem[194470] = uint8(c2da_fresh4 >> 0x10)
            c2da_mem[194471] = uint8(c2da_fresh4 >> 0x18)
            Q_memcpy(text_1, text_1 + i, int(uint(c2da_mem[194468]) | uint(c2da_mem[194469]) << 0x8 | uint(c2da_mem[194470]) << 0x10 | uint(c2da_mem[194471]) << 0x18))
        }
        Cmd_ExecuteString(c2da_fp, 1u)
        if (cmd_wait != 0u) {
            cmd_wait = 0u
            break
        }
    }
    return
}
[sideeffects]
def private Cmd_Alias_f_c2da_frame(c2da_fp : int) {
    var a_0 : int
    var c : int
    var s : int
    if (Cmd_Argc() == 1) {
        Con_Printf(700856, [])
        a_0 = cmd_alias
        while (a_0 != 0) {
            Con_Printf(700881, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(a_0 + 8)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[a_0 + 40]) | uint(c2da_mem[a_0 + 41]) << 0x8 | uint(c2da_mem[a_0 + 42]) << 0x10 | uint(c2da_mem[a_0 + 43]) << 0x18)))])
            a_0 = int(uint(c2da_mem[a_0]) | uint(c2da_mem[a_0 + 1]) << 0x8 | uint(c2da_mem[a_0 + 2]) << 0x10 | uint(c2da_mem[a_0 + 3]) << 0x18)
        }
        return
    }
    s = Cmd_Argv(1)
    if (c2da_lin_strlen(s) >= 32ul) {
        Con_Printf(700890, [])
        return
    }
    a_0 = cmd_alias
    while (a_0 != 0) {
        if (c2da_lin_strcmp(s, a_0 + 8) == 0) {
            Z_Free(int(uint(c2da_mem[a_0 + 40]) | uint(c2da_mem[a_0 + 41]) << 0x8 | uint(c2da_mem[a_0 + 42]) << 0x10 | uint(c2da_mem[a_0 + 43]) << 0x18))
            break
        }
        a_0 = int(uint(c2da_mem[a_0]) | uint(c2da_mem[a_0 + 1]) << 0x8 | uint(c2da_mem[a_0 + 2]) << 0x10 | uint(c2da_mem[a_0 + 3]) << 0x18)
    }
    if (a_0 == 0) {
        a_0 = Z_Malloc(48)
        let c2da_fresh10 : uint = uint(cmd_alias)
        c2da_mem[a_0] = uint8(c2da_fresh10)
        c2da_mem[a_0 + 1] = uint8(c2da_fresh10 >> 0x8)
        c2da_mem[a_0 + 2] = uint8(c2da_fresh10 >> 0x10)
        c2da_mem[a_0 + 3] = uint8(c2da_fresh10 >> 0x18)
        c2da_mem[a_0 + 4] = 0u8
        c2da_mem[a_0 + 5] = 0u8
        c2da_mem[a_0 + 6] = 0u8
        c2da_mem[a_0 + 7] = 0u8
        cmd_alias = a_0
    }
    c2da_lin_strcpy(a_0 + 8, s)
    let c2da_fresh11 : int8 = int8(0)
    c2da_mem[c2da_fp + 0] = uint8(c2da_fresh11)
    c = Cmd_Argc()
    for (i_1 in range(2, c)) {
        c2da_lin_strcat(c2da_fp, Cmd_Argv(i_1))
        if (i_1 != c) {
            c2da_lin_strcat(c2da_fp, 700852)
        }
    }
    c2da_lin_strcat(c2da_fp, 700854)
    let c2da_fresh12 : int = CopyString(c2da_fp)
    let c2da_fresh13 : uint = uint(c2da_fresh12)
    c2da_mem[a_0 + 40] = uint8(c2da_fresh13)
    c2da_mem[a_0 + 41] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[a_0 + 42] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[a_0 + 43] = uint8(c2da_fresh13 >> 0x18)
    c2da_mem[a_0 + 44] = 0u8
    c2da_mem[a_0 + 45] = 0u8
    c2da_mem[a_0 + 46] = 0u8
    c2da_mem[a_0 + 47] = 0u8
    return
}

// This unit's static data, at heap offset 700624.
let private c2da_lin_static_cmd_seg = fixed_array<int>(700624, 429)
let private c2da_lin_static_cmd = fixed_array<uint64>(0x6464415f66756243ul, 0x766f203a74786554ul, 0xa776f6c667265ul, 0x206e776f6e6b6e55ul, 0x20646e616d6d6f63ul, 0x7300000a22732522ul, 0x73646d6366667574ul, 0x6365006365786500ul, 0x7361696c61006f68ul, 0x69617700646d6300ul, 0x64415f646d430074ul, 0x646e616d6d6f4364ul, 0x6820726574666120ul, 0x74696e695f74736ful, 0x64657a696c6169ul, 0x436464415f646d43ul, 0x203a646e616d6d6ful, 0x6165726c61207325ul, 0x6e69666564207964ul, 0x2061207361206465ul, 0x646d43000a726176ul, 0x6d6d6f436464415ful, 0x207325203a646e61ul, 0x2079646165726c61ul, 0xa64656e69666564ul, 0x222074276e614300ul, 0x746f6e202c227325ul, 0x7463656e6e6f6320ul, 0xa0020000a6465ul, 0x20746e6572727543ul, 0x6f63207361696c61ul, 0xa3a73646e616d6dul, 0x7325203a20732500ul, 0x207361696c41000aul, 0x20736920656d616eul, 0x676e6f6c206f6f74ul, 0x786500207325000aul, 0x656c69663c206365ul, 0x203a203e656d616eul, 0x2065747563657865ul, 0x7470697263732061ul, 0x63000a656c696620ul, 0x2074276e646c756ful, 0xa73252063657865ul, 0x676e696365786500ul, 0x757473000a732520ul, 0x3a2073646d636666ul, 0x6574756365786520ul, 0x646e616d6d6f6320ul, 0x617020656e696c20ul, 0x73726574656d6172ul, 0x68435f646d43000aul, 0x3a6d7261506b6365ul, 0x4c4c554e20ul)

[init]
def private c2da_lin_init_static_cmd() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_cmd_seg[s * 2]
        for (k in range(c2da_lin_static_cmd_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_cmd[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_cmd() {
    if (length(c2da_fn_table0) < 48) {
        resize(c2da_fn_table0, 48)
    }
    c2da_fn_table0[47] = @@Cmd_Wait_f
    c2da_fn_table0[46] = @@Cmd_ForwardToServer
    c2da_fn_table0[45] = @@Cmd_Alias_f
    c2da_fn_table0[44] = @@Cmd_Echo_f
    c2da_fn_table0[43] = @@Cmd_Exec_f
    c2da_fn_table0[42] = @@Cmd_StuffCmds_f
}

[init]
def private c2da_lin_relink_init_cmd() {
    c2da_relink_cmd()
}
