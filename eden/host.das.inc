var private Host_Shutdown__isdown : uint = 0u

var private Host_Error__inerror : uint = 0u

var private Host_Frame__timetotal : double = 0.0lf

var private Host_Frame__timecount : int = 0

var private _Host_Frame__time1 : double = 0.0lf

var private _Host_Frame__time2 : double = 0.0lf

var private _Host_Frame__time3 : double = 0.0lf

var host_client : int = default<int>

var host_time : double = default<double>

[export, sideeffects]
def SV_DropClient(var crash : uint) {
    var saveSelf : int
    var i : int
    var client : int
    if (crash == 0u) {
        if (uint(NET_CanSendMessage(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18))) != 0u) {
            MSG_WriteByte(host_client + 80, 2)
            NET_SendMessage(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18), host_client + 80)
        }
        if (int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18) != 0 && (uint(c2da_mem[host_client + 4]) | uint(c2da_mem[host_client + 5]) << 0x8 | uint(c2da_mem[host_client + 6]) << 0x10 | uint(c2da_mem[host_client + 7]) << 0x18) != 0x0) {
            saveSelf = int(uint(c2da_mem[pr_global_struct + 112]) | uint(c2da_mem[pr_global_struct + 113]) << 0x8 | uint(c2da_mem[pr_global_struct + 114]) << 0x10 | uint(c2da_mem[pr_global_struct + 115]) << 0x18)
            let c2da_fresh0 : int = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18) - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
            let c2da_fresh1 : uint = uint(c2da_fresh0)
            c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh1)
            c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh1 >> 0x8)
            c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh1 >> 0x10)
            c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh1 >> 0x18)
            PR_ExecuteProgram(int(uint(c2da_mem[pr_global_struct + 356]) | uint(c2da_mem[pr_global_struct + 357]) << 0x8 | uint(c2da_mem[pr_global_struct + 358]) << 0x10 | uint(c2da_mem[pr_global_struct + 359]) << 0x18))
            let c2da_fresh2 : uint = uint(saveSelf)
            c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh2)
            c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh2 >> 0x8)
            c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh2 >> 0x10)
            c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh2 >> 0x18)
        }
        Sys_Printf(717611, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(host_client + 8112))])
    }
    NET_Close(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18))
    let c2da_fresh3 : uint = 0u
    c2da_mem[host_client + 32] = uint8(c2da_fresh3)
    c2da_mem[host_client + 33] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[host_client + 34] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[host_client + 35] = uint8(c2da_fresh3 >> 0x18)
    c2da_mem[host_client + 36] = 0u8
    c2da_mem[host_client + 37] = 0u8
    c2da_mem[host_client + 38] = 0u8
    c2da_mem[host_client + 39] = 0u8
    let c2da_fresh4 : uint = 0u
    let c2da_fresh5 : uint = c2da_fresh4
    c2da_mem[host_client] = uint8(c2da_fresh5)
    c2da_mem[host_client + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[host_client + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[host_client + 3] = uint8(c2da_fresh5 >> 0x18)
    let c2da_fresh6 : int8 = int8(0)
    c2da_mem[host_client + 8112 + 0] = uint8(c2da_fresh6)
    let c2da_fresh7 : int = -999999
    let c2da_fresh8 : uint = uint(c2da_fresh7)
    c2da_mem[host_client + 8280] = uint8(c2da_fresh8)
    c2da_mem[host_client + 8281] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[host_client + 8282] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[host_client + 8283] = uint8(c2da_fresh8 >> 0x18)
    net_activeconnections = net_activeconnections - 1
    i = 0
    client = svs.clients
    while (i < svs.maxclients) {
        if ((uint(c2da_mem[client]) | uint(c2da_mem[client + 1]) << 0x8 | uint(c2da_mem[client + 2]) << 0x10 | uint(c2da_mem[client + 3]) << 0x18) == 0u) {
            i++
            client += 8288
            continue
        }
        MSG_WriteByte(client + 80, 13)
        MSG_WriteByte(client + 80, int(int64((host_client - svs.clients) / 8288)))
        MSG_WriteString(client + 80, 717630)
        MSG_WriteByte(client + 80, 14)
        MSG_WriteByte(client + 80, int(int64((host_client - svs.clients) / 8288)))
        MSG_WriteShort(client + 80, 0)
        MSG_WriteByte(client + 80, 17)
        MSG_WriteByte(client + 80, int(int64((host_client - svs.clients) / 8288)))
        MSG_WriteByte(client + 80, 0)
        i++
        client += 8288
    }
    return
}
[export, sideeffects]
def SV_ClientPrintf(var fmt_0 : int; c2da_va_args : array<C2daVaArg>) {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_ClientPrintf_c2da_frame(fmt_0, c2da_va_args, c2da_lin_enter(1024))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def SV_BroadcastPrintf(var fmt_1 : int; c2da_va_args : array<C2daVaArg>) {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_BroadcastPrintf_c2da_frame(fmt_1, c2da_va_args, c2da_lin_enter(1024))
    c2da_lin_sp = c2da_saved_sp
}
var host_parms : quakeparms_t = default<quakeparms_t>

var host_initialized : uint = default<uint>

var host_frametime : double = default<double>

var host_basepal : int = default<int>

var host_colormap : int = default<int>

var host_framecount : int = default<int>

var realtime : double = default<double>

[export, sideeffects]
def Host_ClearMemory() {
    Con_DPrintf(717631, [])
    D_FlushCaches()
    Mod_ClearAll()
    if (host_hunklevel != 0) {
        Hunk_FreeToLowMark(host_hunklevel)
    }
    let c2da_fresh12 : int = 0
    let c2da_fresh13 : uint = uint(c2da_fresh12)
    c2da_mem[7804] = uint8(c2da_fresh13)
    c2da_mem[7805] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[7806] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[7807] = uint8(c2da_fresh13 >> 0x18)
    c2da_lin_memset(225856, 0, 17168ul)
    c2da_lin_memset(208, 0, 4992ul)
    return
}
var host_hunklevel : int = default<int>

[export, sideeffects]
def Host_ServerFrame() {
    let c2da_fresh14 : float = float(host_frametime)
    let c2da_fresh15 : uint = float_bits_to_uint(c2da_fresh14)
    c2da_mem[pr_global_struct + 128] = uint8(c2da_fresh15)
    c2da_mem[pr_global_struct + 129] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[pr_global_struct + 130] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[pr_global_struct + 131] = uint8(c2da_fresh15 >> 0x18)
    SV_ClearDatagram()
    SV_CheckForNewClients()
    SV_RunClients()
    if ((uint(c2da_mem[225860]) | uint(c2da_mem[225861]) << 0x8 | uint(c2da_mem[225862]) << 0x10 | uint(c2da_mem[225863]) << 0x18) == 0u && (svs.maxclients > 1 || uint(key_dest) == 0u)) {
        SV_Physics()
    }
    SV_SendClientMessages()
    return
}
[export, sideeffects]
def Host_Init(var parms : int) {
    if (uint(standard_quake) != 0u) {
        minimum_memory = 5570560
    } else {
        minimum_memory = 5570560 + 1048576
    }
    if (COM_CheckParm(717648) != 0) {
        let c2da_fresh16 : uint = uint(minimum_memory)
        c2da_mem[parms + 40] = uint8(c2da_fresh16)
        c2da_mem[parms + 41] = uint8(c2da_fresh16 >> 0x8)
        c2da_mem[parms + 42] = uint8(c2da_fresh16 >> 0x10)
        c2da_mem[parms + 43] = uint8(c2da_fresh16 >> 0x18)
    }
    var c2da_fresh17 : quakeparms_t
    c2da_fresh17.basedir = int(uint(c2da_mem[parms]) | uint(c2da_mem[parms + 1]) << 0x8 | uint(c2da_mem[parms + 2]) << 0x10 | uint(c2da_mem[parms + 3]) << 0x18)
    c2da_fresh17.cachedir = int(uint(c2da_mem[parms + 8]) | uint(c2da_mem[parms + 9]) << 0x8 | uint(c2da_mem[parms + 10]) << 0x10 | uint(c2da_mem[parms + 11]) << 0x18)
    c2da_fresh17.argc = int(uint(c2da_mem[parms + 16]) | uint(c2da_mem[parms + 17]) << 0x8 | uint(c2da_mem[parms + 18]) << 0x10 | uint(c2da_mem[parms + 19]) << 0x18)
    c2da_fresh17.argv = int(uint(c2da_mem[parms + 24]) | uint(c2da_mem[parms + 25]) << 0x8 | uint(c2da_mem[parms + 26]) << 0x10 | uint(c2da_mem[parms + 27]) << 0x18)
    c2da_fresh17.membase = int(uint(c2da_mem[parms + 32]) | uint(c2da_mem[parms + 33]) << 0x8 | uint(c2da_mem[parms + 34]) << 0x10 | uint(c2da_mem[parms + 35]) << 0x18)
    c2da_fresh17.memsize = int(uint(c2da_mem[parms + 40]) | uint(c2da_mem[parms + 41]) << 0x8 | uint(c2da_mem[parms + 42]) << 0x10 | uint(c2da_mem[parms + 43]) << 0x18)
    host_parms = c2da_fresh17
    if (int(uint(c2da_mem[parms + 40]) | uint(c2da_mem[parms + 41]) << 0x8 | uint(c2da_mem[parms + 42]) << 0x10 | uint(c2da_mem[parms + 43]) << 0x18) < minimum_memory) {
        Sys_Error(717659, [C2daVaArg(tag = 2, i64 = 0, f64 = double(float(int(uint(c2da_mem[parms + 40]) | uint(c2da_mem[parms + 41]) << 0x8 | uint(c2da_mem[parms + 42]) << 0x10 | uint(c2da_mem[parms + 43]) << 0x18)) / 1048576.0), raw = 0x0)])
    }
    let c2da_fresh18 : int = int(uint(c2da_mem[parms + 16]) | uint(c2da_mem[parms + 17]) << 0x8 | uint(c2da_mem[parms + 18]) << 0x10 | uint(c2da_mem[parms + 19]) << 0x18)
    let c2da_fresh19 : uint = uint(c2da_fresh18)
    c2da_mem[243888] = uint8(c2da_fresh19)
    c2da_mem[243889] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[243890] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[243891] = uint8(c2da_fresh19 >> 0x18)
    com_argv = int(uint(c2da_mem[parms + 24]) | uint(c2da_mem[parms + 25]) << 0x8 | uint(c2da_mem[parms + 26]) << 0x10 | uint(c2da_mem[parms + 27]) << 0x18)
    Memory_Init(int(uint(c2da_mem[parms + 32]) | uint(c2da_mem[parms + 33]) << 0x8 | uint(c2da_mem[parms + 34]) << 0x10 | uint(c2da_mem[parms + 35]) << 0x18), int(uint(c2da_mem[parms + 40]) | uint(c2da_mem[parms + 41]) << 0x8 | uint(c2da_mem[parms + 42]) << 0x10 | uint(c2da_mem[parms + 43]) << 0x18))
    Cbuf_Init()
    Cmd_Init()
    V_Init()
    Chase_Init()
    Host_InitVCR(parms)
    COM_Init(int(uint(c2da_mem[parms]) | uint(c2da_mem[parms + 1]) << 0x8 | uint(c2da_mem[parms + 2]) << 0x10 | uint(c2da_mem[parms + 3]) << 0x18))
    Host_InitLocal()
    W_LoadWadFile(717715)
    Key_Init()
    Con_Init()
    M_Init()
    PR_Init()
    Mod_Init()
    NET_Init()
    SV_Init()
    Con_Printf(717723, [])
    Con_Printf(717750, [C2daVaArg(tag = 2, i64 = 0, f64 = double(int(uint(c2da_mem[parms + 40]) | uint(c2da_mem[parms + 41]) << 0x8 | uint(c2da_mem[parms + 42]) << 0x10 | uint(c2da_mem[parms + 43]) << 0x18)) / (1024.0lf * 1024.0lf), raw = 0x0)])
    R_InitTextures()
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) != 0u) {
        host_basepal = COM_LoadHunkFile(717771)
        if (host_basepal == 0) {
            Sys_Error(717787, [])
        }
        host_colormap = COM_LoadHunkFile(717817)
        if (host_colormap == 0) {
            Sys_Error(717834, [])
        }
        IN_Init()
        VID_Init(host_basepal)
        Draw_Init()
        SCR_Init()
        R_Init()
        S_Init()
        CDAudio_Init()
        Sbar_Init()
        CL_Init()
    }
    Cbuf_InsertText(717865)
    Hunk_AllocName(0, 717880)
    host_hunklevel = Hunk_LowMark()
    host_initialized = 1u
    Sys_Printf(717897, [])
    return
}
[export, sideeffects]
def Host_InitLocal() {
    Host_InitCommands()
    Cvar_RegisterVariable(243152)
    Cvar_RegisterVariable(243200)
    Cvar_RegisterVariable(243248)
    Cvar_RegisterVariable(243296)
    Cvar_RegisterVariable(243344)
    Cvar_RegisterVariable(243392)
    Cvar_RegisterVariable(243440)
    Cvar_RegisterVariable(243488)
    Cvar_RegisterVariable(243536)
    Cvar_RegisterVariable(243584)
    Cvar_RegisterVariable(243632)
    Cvar_RegisterVariable(243680)
    Cvar_RegisterVariable(243728)
    Cvar_RegisterVariable(243776)
    Cvar_RegisterVariable(243824)
    Host_FindMaxClients()
    host_time = 1.0lf
    return
}
[export, sideeffects]
def Host_FindMaxClients() {
    var i_1 : int
    svs.maxclients = 1
    i_1 = COM_CheckParm(717933)
    if (i_1 != 0) {
        let c2da_fresh20 : uint = 0u
        let c2da_fresh21 : uint = c2da_fresh20
        c2da_mem[5520] = uint8(c2da_fresh21)
        c2da_mem[5521] = uint8(c2da_fresh21 >> 0x8)
        c2da_mem[5522] = uint8(c2da_fresh21 >> 0x10)
        c2da_mem[5523] = uint8(c2da_fresh21 >> 0x18)
        if (i_1 != int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) - 1) {
            svs.maxclients = Q_atoi(int(uint(c2da_mem[com_argv + (i_1 + 1) * 8]) | uint(c2da_mem[com_argv + (i_1 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + (i_1 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + (i_1 + 1) * 8 + 3]) << 0x18))
        } else {
            svs.maxclients = 8
        }
    } else {
        let c2da_fresh22 : uint = 1u
        let c2da_fresh23 : uint = c2da_fresh22
        c2da_mem[5520] = uint8(c2da_fresh23)
        c2da_mem[5521] = uint8(c2da_fresh23 >> 0x8)
        c2da_mem[5522] = uint8(c2da_fresh23 >> 0x10)
        c2da_mem[5523] = uint8(c2da_fresh23 >> 0x18)
    }
    i_1 = COM_CheckParm(717944)
    if (i_1 != 0) {
        if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 0u) {
            Sys_Error(717952, [])
        }
        if (i_1 != int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) - 1) {
            svs.maxclients = Q_atoi(int(uint(c2da_mem[com_argv + (i_1 + 1) * 8]) | uint(c2da_mem[com_argv + (i_1 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + (i_1 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + (i_1 + 1) * 8 + 3]) << 0x18))
        } else {
            svs.maxclients = 8
        }
    }
    if (svs.maxclients < 1) {
        svs.maxclients = 8
    } elif (svs.maxclients > 16) {
        svs.maxclients = 16
    }
    svs.maxclientslimit = svs.maxclients
    if (svs.maxclientslimit < 4) {
        svs.maxclientslimit = 4
    }
    svs.clients = Hunk_AllocName(int(uint64(svs.maxclientslimit) * 8288ul), 718003)
    if (svs.maxclients > 1) {
        Cvar_SetValue(717580, 1.0)
    } else {
        Cvar_SetValue(717580, 0.0)
    }
    return
}
[export, sideeffects]
def Host_InitVCR(var parms_0 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    Host_InitVCR_c2da_frame(parms_0, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
var minimum_memory : int = default<int>

[export, sideeffects]
def Host_Shutdown() {
    if (Host_Shutdown__isdown != 0u) {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 718139, [])
        return
    }
    Host_Shutdown__isdown = 1u
    scr_disabled_for_loading = 1u
    Host_WriteConfiguration()
    CDAudio_Shutdown()
    NET_Shutdown()
    S_Shutdown()
    IN_Shutdown()
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) != 0u) {
        VID_Shutdown()
    }
    return
}
[export, sideeffects]
def Host_WriteConfiguration() {
    var f : int
    if ((host_initialized & (uint(isDedicated) == 0u ? 1u : 0u)) != 0x0) {
        f = c2da_lin_fopen(int(va(718159, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 5392ul)])), 718173)
        if (f == 0) {
            Con_Printf(718175, [])
            return
        }
        Key_WriteBindings(f)
        Cvar_WriteVariables(f)
        c2da_std_fclose(uint64(f))
    }
    return
}
[export, sideeffects]
def Host_Error(var error : int; c2da_va_args : array<C2daVaArg>) {
    let c2da_saved_sp : int = c2da_lin_sp
    Host_Error_c2da_frame(error, c2da_va_args, c2da_lin_enter(1024))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Host_ShutdownServer(var crash_0 : uint) {
    let c2da_saved_sp : int = c2da_lin_sp
    Host_ShutdownServer_c2da_frame(crash_0, c2da_lin_enter(48))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Host_EndGame(var message : int; c2da_va_args : array<C2daVaArg>) {
    let c2da_saved_sp : int = c2da_lin_sp
    Host_EndGame_c2da_frame(message, c2da_va_args, c2da_lin_enter(1024))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Host_Frame(var time : float) {
    var time1 : double
    var time2 : double
    var i_3 : int
    var c : int
    var m : int
    if (uint_bits_to_float(uint(c2da_mem[243320]) | uint(c2da_mem[243321]) << 0x8 | uint(c2da_mem[243322]) << 0x10 | uint(c2da_mem[243323]) << 0x18) == 0.0) {
        _Host_Frame(time)
        return
    }
    time1 = Sys_FloatTime()
    _Host_Frame(time)
    time2 = Sys_FloatTime()
    Host_Frame__timetotal += time2 - time1
    Host_Frame__timecount++
    if (Host_Frame__timecount < 1000) {
        return
    }
    m = int(Host_Frame__timetotal * 1000.0lf / double(Host_Frame__timecount))
    Host_Frame__timecount = 0
    Host_Frame__timetotal = 0.0lf
    c = 0
    i_3 = 0
    while (i_3 < svs.maxclients) {
        let c2da_fresh69 : int = svs.clients + i_3 * 8288
        if ((uint(c2da_mem[c2da_fresh69]) | uint(c2da_mem[c2da_fresh69 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh69 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh69 + 3]) << 0x18) != 0u) {
            c++
        }
        i_3++
    }
    Con_Printf(718327, [C2daVaArg(tag = 1, i64 = int64(c), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(m), f64 = 0.0lf, raw = 0x0)])
    return
}
[export, sideeffects]
def _Host_Frame(var time_0 : float) {
    var pass1 : int
    var pass2 : int
    var pass3 : int
    try {
        c2da_std_rand()
        if (Host_FilterTime(time_0) == 0u) {
            return
        }
        Sys_SendKeyEvents()
        IN_Commands()
        Cbuf_Execute()
        NET_Poll()
        if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) != 0u) {
            CL_SendCmd()
        }
        Host_GetConsoleCommands()
        if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) != 0u) {
            Host_ServerFrame()
        }
        if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u) {
            CL_SendCmd()
        }
        host_time += host_frametime
        if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 2u) {
            CL_ReadFromServer()
        }
        if (uint_bits_to_float(uint(c2da_mem[243224]) | uint(c2da_mem[243225]) << 0x8 | uint(c2da_mem[243226]) << 0x10 | uint(c2da_mem[243227]) << 0x18) != 0.0) {
            _Host_Frame__time1 = Sys_FloatTime()
        }
        SCR_UpdateScreen()
        if (uint_bits_to_float(uint(c2da_mem[243224]) | uint(c2da_mem[243225]) << 0x8 | uint(c2da_mem[243226]) << 0x10 | uint(c2da_mem[243227]) << 0x18) != 0.0) {
            _Host_Frame__time2 = Sys_FloatTime()
        }
        if (int(uint(c2da_mem[7804]) | uint(c2da_mem[7805]) << 0x8 | uint(c2da_mem[7806]) << 0x10 | uint(c2da_mem[7807]) << 0x18) == 4) {
            S_Update(244112, 244128, 244144, 244160)
            CL_DecayLights()
        } else {
            S_Update(194432, 194432, 194432, 194432)
        }
        CDAudio_Update()
        if (uint_bits_to_float(uint(c2da_mem[243224]) | uint(c2da_mem[243225]) << 0x8 | uint(c2da_mem[243226]) << 0x10 | uint(c2da_mem[243227]) << 0x18) != 0.0) {
            pass1 = int((_Host_Frame__time1 - _Host_Frame__time3) * 1000.0lf)
            _Host_Frame__time3 = Sys_FloatTime()
            pass2 = int((_Host_Frame__time2 - _Host_Frame__time1) * 1000.0lf)
            pass3 = int((_Host_Frame__time3 - _Host_Frame__time2) * 1000.0lf)
            Con_Printf(718364, [C2daVaArg(tag = 1, i64 = int64(pass1 + pass2 + pass3), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(pass1), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(pass2), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(pass3), f64 = 0.0lf, raw = 0x0)])
        }
        host_framecount++
        return
    } recover {
        c2da_std_setjmp_catch("host_abortserver")
        return
    }
}
[export, sideeffects]
def Host_GetConsoleCommands() {
    var cmd_0 : int
    while (true) {
        cmd_0 = Sys_ConsoleInput()
        if (cmd_0 == 0) {
            break
        }
        Cbuf_AddText(cmd_0)
    }
    return
}
[export, sideeffects]
def Host_FilterTime(var time_1 : float) : uint {
    realtime += double(time_1)
    if ((uint(c2da_mem[7776]) | uint(c2da_mem[7777]) << 0x8 | uint(c2da_mem[7778]) << 0x10 | uint(c2da_mem[7779]) << 0x18) == 0u && realtime - oldrealtime < 1.0lf / 72.0lf) {
        return 0u
    }
    host_frametime = realtime - oldrealtime
    oldrealtime = double(realtime)  // nolint:PERF020
    if (uint_bits_to_float(uint(c2da_mem[243176]) | uint(c2da_mem[243177]) << 0x8 | uint(c2da_mem[243178]) << 0x10 | uint(c2da_mem[243179]) << 0x18) > 0.0) {
        host_frametime = double(uint_bits_to_float(uint(c2da_mem[243176]) | uint(c2da_mem[243177]) << 0x8 | uint(c2da_mem[243178]) << 0x10 | uint(c2da_mem[243179]) << 0x18))
    } else {
        if (host_frametime > 0.1lf) {
            host_frametime = 0.1lf
        }
        if (host_frametime < 0.001lf) {
            host_frametime = 0.001lf
        }
    }
    return 1u
}
var oldrealtime : double = default<double>

[export, sideeffects]
def Host_ClientCommands(var fmt_2 : int; c2da_va_args : array<C2daVaArg>) {
    let c2da_saved_sp : int = c2da_lin_sp
    Host_ClientCommands_c2da_frame(fmt_2, c2da_va_args, c2da_lin_enter(1024))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private SV_ClientPrintf_c2da_frame(var fmt_0 : int; c2da_va_args : array<C2daVaArg>; c2da_fp : int) {
    var argptr : C2daVaCursor = C2daVaCursor(index = 0)
    argptr.index = 0
    c2da_lin_vsnprintf(c2da_fp, 2147483647ul, fmt_0, argptr, c2da_va_args)
    argptr.index = -1
    MSG_WriteByte(host_client + 80, 8)
    MSG_WriteString(host_client + 80, c2da_fp)
    return
}
[sideeffects]
def private SV_BroadcastPrintf_c2da_frame(var fmt_1 : int; c2da_va_args : array<C2daVaArg>; c2da_fp : int) {
    var argptr_0 : C2daVaCursor = C2daVaCursor(index = 0)
    var i_0 : int
    argptr_0.index = 0
    c2da_lin_vsnprintf(c2da_fp, 2147483647ul, fmt_1, argptr_0, c2da_va_args)
    argptr_0.index = -1
    i_0 = 0
    while (i_0 < svs.maxclients) {
        let c2da_fresh9 : int = svs.clients + i_0 * 8288
        var c2da_fresh11 : int = 0
        if ((uint(c2da_mem[c2da_fresh9]) | uint(c2da_mem[c2da_fresh9 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh9 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh9 + 3]) << 0x18) != 0x0) {
            let c2da_fresh10 : int = svs.clients + i_0 * 8288 + 4
            if ((uint(c2da_mem[c2da_fresh10]) | uint(c2da_mem[c2da_fresh10 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh10 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh10 + 3]) << 0x18) != 0x0) {
                c2da_fresh11 = 1
            }
        }
        if (c2da_fresh11 != 0) {
            MSG_WriteByte(svs.clients + i_0 * 8288 + 80, 8)
            MSG_WriteString(svs.clients + i_0 * 8288 + 80, c2da_fp)
        }
        i_0++
    }
    return
}
[sideeffects]
def private Host_InitVCR_c2da_frame(var parms_0 : int; c2da_fp : int) {
    var n : int
    var p : int
    if (COM_CheckParm(718011) != 0) {
        if (int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) != 2) {
            Sys_Error(718021, [])
        }
        Sys_FileOpenRead(718065, 243872)
        if (int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18) == -1) {
            Sys_Error(718075, [])
        }
        Sys_FileRead(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), c2da_fp, 4)
        if (int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) != 1447252529) {
            Sys_Error(718100, [])
        }
        Sys_FileRead(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), 243888, 4)
        com_argv = c2da_lin_malloc(uint64(int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18)) * 8ul)
        let c2da_fresh24 : int = int(uint(c2da_mem[parms_0 + 24]) | uint(c2da_mem[parms_0 + 25]) << 0x8 | uint(c2da_mem[parms_0 + 26]) << 0x10 | uint(c2da_mem[parms_0 + 27]) << 0x18) + 0 * 8
        let c2da_fresh25 : int = int(uint(c2da_mem[c2da_fresh24]) | uint(c2da_mem[c2da_fresh24 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh24 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh24 + 3]) << 0x18)
        let c2da_fresh26 : uint = uint(c2da_fresh25)
        c2da_mem[com_argv + 0 * 8] = uint8(c2da_fresh26)
        c2da_mem[com_argv + 0 * 8 + 1] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[com_argv + 0 * 8 + 2] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[com_argv + 0 * 8 + 3] = uint8(c2da_fresh26 >> 0x18)
        c2da_mem[com_argv + 0 * 8 + 4] = 0u8
        c2da_mem[com_argv + 0 * 8 + 5] = 0u8
        c2da_mem[com_argv + 0 * 8 + 6] = 0u8
        c2da_mem[com_argv + 0 * 8 + 7] = 0u8
        let c2da_fresh27 : int = 0
        let c2da_fresh28 : uint = uint(c2da_fresh27)
        c2da_mem[c2da_fp] = uint8(c2da_fresh28)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh28 >> 0x8)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh28 >> 0x10)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh28 >> 0x18)
        while (int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) < int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18)) {
            Sys_FileRead(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), c2da_fp + 16, 4)
            p = c2da_lin_malloc(uint64(int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18)))
            Sys_FileRead(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), p, int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18))
            let c2da_fresh29 : int = com_argv + (int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) + 1) * 8
            let c2da_fresh30 : uint = uint(p)
            c2da_mem[c2da_fresh29] = uint8(c2da_fresh30)
            c2da_mem[c2da_fresh29 + 1] = uint8(c2da_fresh30 >> 0x8)
            c2da_mem[c2da_fresh29 + 2] = uint8(c2da_fresh30 >> 0x10)
            c2da_mem[c2da_fresh29 + 3] = uint8(c2da_fresh30 >> 0x18)
            c2da_mem[c2da_fresh29 + 4] = 0u8
            c2da_mem[c2da_fresh29 + 5] = 0u8
            c2da_mem[c2da_fresh29 + 6] = 0u8
            c2da_mem[c2da_fresh29 + 7] = 0u8
            let c2da_fresh31 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18)
            let c2da_fresh32 : int = c2da_fresh31 + 1
            let c2da_fresh33 : uint = uint(c2da_fresh32)
            c2da_mem[c2da_fp] = uint8(c2da_fresh33)
            c2da_mem[c2da_fp + 1] = uint8(c2da_fresh33 >> 0x8)
            c2da_mem[c2da_fp + 2] = uint8(c2da_fresh33 >> 0x10)
            c2da_mem[c2da_fp + 3] = uint8(c2da_fresh33 >> 0x18)
        }
        let c2da_fresh34 : int = int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18)
        let c2da_fresh35 : int = c2da_fresh34 + 1
        let c2da_fresh36 : uint = uint(c2da_fresh35)
        c2da_mem[243888] = uint8(c2da_fresh36)
        c2da_mem[243889] = uint8(c2da_fresh36 >> 0x8)
        c2da_mem[243890] = uint8(c2da_fresh36 >> 0x10)
        c2da_mem[243891] = uint8(c2da_fresh36 >> 0x18)
        let c2da_fresh37 : int = int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18)
        let c2da_fresh38 : uint = uint(c2da_fresh37)
        c2da_mem[parms_0 + 16] = uint8(c2da_fresh38)
        c2da_mem[parms_0 + 17] = uint8(c2da_fresh38 >> 0x8)
        c2da_mem[parms_0 + 18] = uint8(c2da_fresh38 >> 0x10)
        c2da_mem[parms_0 + 19] = uint8(c2da_fresh38 >> 0x18)
        let c2da_fresh39 : uint = uint(com_argv)
        c2da_mem[parms_0 + 24] = uint8(c2da_fresh39)
        c2da_mem[parms_0 + 25] = uint8(c2da_fresh39 >> 0x8)
        c2da_mem[parms_0 + 26] = uint8(c2da_fresh39 >> 0x10)
        c2da_mem[parms_0 + 27] = uint8(c2da_fresh39 >> 0x18)
        c2da_mem[parms_0 + 28] = 0u8
        c2da_mem[parms_0 + 29] = 0u8
        c2da_mem[parms_0 + 30] = 0u8
        c2da_mem[parms_0 + 31] = 0u8
    }
    n = COM_CheckParm(718131)
    if (n != 0) {
        let c2da_fresh40 : int = Sys_FileOpenWrite(718065)
        let c2da_fresh41 : uint = uint(c2da_fresh40)
        c2da_mem[243872] = uint8(c2da_fresh41)
        c2da_mem[243873] = uint8(c2da_fresh41 >> 0x8)
        c2da_mem[243874] = uint8(c2da_fresh41 >> 0x10)
        c2da_mem[243875] = uint8(c2da_fresh41 >> 0x18)
        let c2da_fresh42 : int = 1447252529
        let c2da_fresh43 : uint = uint(c2da_fresh42)
        c2da_mem[c2da_fp] = uint8(c2da_fresh43)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh43 >> 0x8)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh43 >> 0x10)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh43 >> 0x18)
        Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), c2da_fp, 4)
        let c2da_fresh44 : int = int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) - 1
        let c2da_fresh45 : uint = uint(c2da_fresh44)
        c2da_mem[c2da_fp] = uint8(c2da_fresh45)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh45 >> 0x8)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh45 >> 0x10)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh45 >> 0x18)
        Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), c2da_fp, 4)
        let c2da_fresh46 : int = 1
        let c2da_fresh47 : uint = uint(c2da_fresh46)
        c2da_mem[c2da_fp] = uint8(c2da_fresh47)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh47 >> 0x8)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh47 >> 0x10)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh47 >> 0x18)
        while (int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) < int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18)) {
            if (int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) == n) {
                let c2da_fresh48 : int = 10
                let c2da_fresh49 : uint = uint(c2da_fresh48)
                c2da_mem[c2da_fp + 16] = uint8(c2da_fresh49)
                c2da_mem[c2da_fp + 17] = uint8(c2da_fresh49 >> 0x8)
                c2da_mem[c2da_fp + 18] = uint8(c2da_fresh49 >> 0x10)
                c2da_mem[c2da_fp + 19] = uint8(c2da_fresh49 >> 0x18)
                Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), c2da_fp + 16, 4)
                Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), 718011, int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18))
                let c2da_fresh50 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18)
                let c2da_fresh51 : int = c2da_fresh50 + 1
                let c2da_fresh52 : uint = uint(c2da_fresh51)
                c2da_mem[c2da_fp] = uint8(c2da_fresh52)
                c2da_mem[c2da_fp + 1] = uint8(c2da_fresh52 >> 0x8)
                c2da_mem[c2da_fp + 2] = uint8(c2da_fresh52 >> 0x10)
                c2da_mem[c2da_fp + 3] = uint8(c2da_fresh52 >> 0x18)
                continue
            }
            let c2da_fresh53 : int = com_argv + int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) * 8
            let c2da_fresh54 : int = Q_strlen(int(uint(c2da_mem[c2da_fresh53]) | uint(c2da_mem[c2da_fresh53 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh53 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh53 + 3]) << 0x18)) + 1
            let c2da_fresh55 : uint = uint(c2da_fresh54)
            c2da_mem[c2da_fp + 16] = uint8(c2da_fresh55)
            c2da_mem[c2da_fp + 17] = uint8(c2da_fresh55 >> 0x8)
            c2da_mem[c2da_fp + 18] = uint8(c2da_fresh55 >> 0x10)
            c2da_mem[c2da_fp + 19] = uint8(c2da_fresh55 >> 0x18)
            Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), c2da_fp + 16, 4)
            let c2da_fresh56 : int = com_argv + int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) * 8
            Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), int(uint(c2da_mem[c2da_fresh56]) | uint(c2da_mem[c2da_fresh56 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh56 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh56 + 3]) << 0x18), int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18))
            let c2da_fresh57 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18)
            let c2da_fresh58 : int = c2da_fresh57 + 1
            let c2da_fresh59 : uint = uint(c2da_fresh58)
            c2da_mem[c2da_fp] = uint8(c2da_fresh59)
            c2da_mem[c2da_fp + 1] = uint8(c2da_fresh59 >> 0x8)
            c2da_mem[c2da_fp + 2] = uint8(c2da_fresh59 >> 0x10)
            c2da_mem[c2da_fp + 3] = uint8(c2da_fresh59 >> 0x18)
        }
    }
    return
}
[sideeffects]
def private Host_Error_c2da_frame(var error : int; c2da_va_args : array<C2daVaArg>; c2da_fp : int) {
    var argptr_1 : C2daVaCursor = C2daVaCursor(index = 0)
    if (Host_Error__inerror != 0u) {
        Sys_Error(718203, [])
    }
    Host_Error__inerror = 1u
    SCR_EndLoadingPlaque()
    argptr_1.index = 0
    c2da_lin_vsnprintf(c2da_fp, 2147483647ul, error, argptr_1, c2da_va_args)
    argptr_1.index = -1
    Con_Printf(718235, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) != 0u) {
        Host_ShutdownServer(0u)
    }
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 0u) {
        Sys_Error(718235, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    }
    CL_Disconnect()
    let c2da_fresh60 : int = -1
    let c2da_fresh61 : uint = uint(c2da_fresh60)
    c2da_mem[7636] = uint8(c2da_fresh61)
    c2da_mem[7637] = uint8(c2da_fresh61 >> 0x8)
    c2da_mem[7638] = uint8(c2da_fresh61 >> 0x10)
    c2da_mem[7639] = uint8(c2da_fresh61 >> 0x18)
    Host_Error__inerror = 0u
    c2da_std_longjmp("host_abortserver", 1)
    return
}
[sideeffects]
def private Host_ShutdownServer_c2da_frame(var crash_0 : uint; c2da_fp : int) {
    var i_2 : int
    var count : int
    var start : double
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u) {
        return
    }
    let c2da_fresh62 : uint = 0u
    let c2da_fresh63 : uint = c2da_fresh62
    c2da_mem[225856] = uint8(c2da_fresh63)
    c2da_mem[225857] = uint8(c2da_fresh63 >> 0x8)
    c2da_mem[225858] = uint8(c2da_fresh63 >> 0x10)
    c2da_mem[225859] = uint8(c2da_fresh63 >> 0x18)
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 2u) {
        CL_Disconnect()
    }
    start = Sys_FloatTime()
    while (true) {
        count = 0
        i_2 = 0
        host_client = svs.clients
        while (i_2 < svs.maxclients) {
            if ((uint(c2da_mem[host_client]) | uint(c2da_mem[host_client + 1]) << 0x8 | uint(c2da_mem[host_client + 2]) << 0x10 | uint(c2da_mem[host_client + 3]) << 0x18) != 0x0 && int(uint(c2da_mem[host_client + 100]) | uint(c2da_mem[host_client + 101]) << 0x8 | uint(c2da_mem[host_client + 102]) << 0x10 | uint(c2da_mem[host_client + 103]) << 0x18) != 0) {
                if (uint(NET_CanSendMessage(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18))) != 0u) {
                    NET_SendMessage(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18), host_client + 80)
                    SZ_Clear(host_client + 80)
                } else {
                    NET_GetMessage(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18))
                    count++
                }
            }
            i_2++
            host_client += 8288
        }
        if (Sys_FloatTime() - start > 3.0lf) {
            break
        }
        if (count == 0) {
            break
        }
    }
    let c2da_fresh64 : uint = uint(c2da_fp)
    c2da_mem[c2da_fp + 24] = uint8(c2da_fresh64)
    c2da_mem[c2da_fp + 25] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[c2da_fp + 26] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[c2da_fp + 27] = uint8(c2da_fresh64 >> 0x18)
    c2da_mem[c2da_fp + 28] = 0u8
    c2da_mem[c2da_fp + 29] = 0u8
    c2da_mem[c2da_fp + 30] = 0u8
    c2da_mem[c2da_fp + 31] = 0u8
    let c2da_fresh65 : int = 4
    let c2da_fresh66 : uint = uint(c2da_fresh65)
    c2da_mem[c2da_fp + 32] = uint8(c2da_fresh66)
    c2da_mem[c2da_fp + 33] = uint8(c2da_fresh66 >> 0x8)
    c2da_mem[c2da_fp + 34] = uint8(c2da_fresh66 >> 0x10)
    c2da_mem[c2da_fp + 35] = uint8(c2da_fresh66 >> 0x18)
    let c2da_fresh67 : int = 0
    let c2da_fresh68 : uint = uint(c2da_fresh67)
    c2da_mem[c2da_fp + 36] = uint8(c2da_fresh68)
    c2da_mem[c2da_fp + 37] = uint8(c2da_fresh68 >> 0x8)
    c2da_mem[c2da_fp + 38] = uint8(c2da_fresh68 >> 0x10)
    c2da_mem[c2da_fp + 39] = uint8(c2da_fresh68 >> 0x18)
    MSG_WriteByte(c2da_fp + 16, 2)
    count = NET_SendToAll(c2da_fp + 16, 5)
    if (count != 0) {
        Con_Printf(718251, [C2daVaArg(tag = 1, i64 = int64(count), f64 = 0.0lf, raw = 0x0)])
    }
    i_2 = 0
    host_client = svs.clients
    while (i_2 < svs.maxclients) {
        if ((uint(c2da_mem[host_client]) | uint(c2da_mem[host_client + 1]) << 0x8 | uint(c2da_mem[host_client + 2]) << 0x10 | uint(c2da_mem[host_client + 3]) << 0x18) != 0u) {
            SV_DropClient(crash_0)
        }
        i_2++
        host_client += 8288
    }
    c2da_lin_memset(225856, 0, 17168ul)
    c2da_lin_memset(int(svs.clients), 0, uint64(svs.maxclientslimit) * 8288ul)
    return
}
[sideeffects]
def private Host_EndGame_c2da_frame(var message : int; c2da_va_args : array<C2daVaArg>; c2da_fp : int) {
    var argptr_2 : C2daVaCursor = C2daVaCursor(index = 0)
    argptr_2.index = 0
    c2da_lin_vsnprintf(c2da_fp, 2147483647ul, message, argptr_2, c2da_va_args)
    argptr_2.index = -1
    Con_DPrintf(718309, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) != 0u) {
        Host_ShutdownServer(0u)
    }
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 0u) {
        Sys_Error(718309, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    }
    if (int(uint(c2da_mem[7636]) | uint(c2da_mem[7637]) << 0x8 | uint(c2da_mem[7638]) << 0x10 | uint(c2da_mem[7639]) << 0x18) != -1) {
        CL_NextDemo()
    } else {
        CL_Disconnect()
    }
    c2da_std_longjmp("host_abortserver", 1)
    return
}
[sideeffects]
def private Host_ClientCommands_c2da_frame(var fmt_2 : int; c2da_va_args : array<C2daVaArg>; c2da_fp : int) {
    var argptr_3 : C2daVaCursor = C2daVaCursor(index = 0)
    argptr_3.index = 0
    c2da_lin_vsnprintf(c2da_fp, 2147483647ul, fmt_2, argptr_3, c2da_va_args)
    argptr_3.index = -1
    MSG_WriteByte(host_client + 80, 9)
    MSG_WriteString(host_client + 80, c2da_fp)
    return
}

// This unit's static data, at heap offset 717456.
let private c2da_lin_static_host_seg = fixed_array<int>(717456, 943)
let private c2da_lin_static_host = fixed_array<uint64>(0x6172665f74736f68ul, 0x300065746172656dul, 0x70735f74736f6800ul, 0x7379730073646565ul, 0x657461726369745ful, 0x65730035302e3000ul, 0x666f727072657672ul, 0x6761726600656c69ul, 0x69740074696d696cul, 0x74696d696c656dul, 0x79616c706d616574ul, 0x76656c656d617300ul, 0x6978656f6e006c65ul, 0x6c6c696b730074ul, 0x6f6c657665640031ul, 0x7461656400726570ul, 0x6300686374616d68ul, 0x7375617000706f6ful, 0x6d657400656c6261ul, 0x6e65696c43003170ul, 0x6d65722073252074ul, 0x4300000a6465766ful, 0x20676e697261656cul, 0xa79726f6d656dul, 0x6f6d656d6e696d2dul, 0x20796c6e4f007972ul, 0x656d2066312e3425ul, 0x656d20666f207367ul, 0x6176612079726f6dul, 0x202c656c62616c69ul, 0x78652074276e6163ul, 0x6167206574756365ul, 0x772e78666700656dul, 0x203a657845006461ul, 0x39313a35353a3330ul, 0x2032312074634f20ul, 0x3425000a36323032ul, 0x6167656d2066312eul, 0x6165682065747962ul, 0x702f786667000a70ul, 0x6c2e657474656c61ul, 0x646c756f4300706dul, 0x64616f6c2074276eul, 0x6c61702f78666720ul, 0x706d6c2e65747465ul, 0x6c6f632f78666700ul, 0x6d6c2e70616d726ful, 0x6e646c756f430070ul, 0x2064616f6c207427ul, 0x6f6c6f632f786667ul, 0x706d6c2e70616d72ul, 0x7571206365786500ul, 0xa63722e656b61ul, 0x55485f54534f482dul, 0x2d4c4556454c4b4eul, 0x3d3d3d3d3d3d3d00ul, 0x4920656b6175513dul, 0x7a696c616974696eul, 0x3d3d3d3d3d3d6465ul, 0x65642d000a3d3d3dul, 0x64657461636964ul, 0x6e657473696c2dul, 0x656e6f20796c6e4ful, 0x6465642d20666f20ul, 0x6f20646574616369ul, 0x657473696c2d2072ul, 0x6562206e6163206eul, 0x6966696365707320ul, 0x6e65696c63006465ul, 0x79616c702d007374ul, 0x206f4e006b636162ul, 0x617020726568746ful, 0x73726574656d6172ul, 0x6465776f6c6c6120ul, 0x702d206874697720ul, 0xa6b63616279616cul, 0x762e656b61757100ul, 0x6279616c70007263ul, 0x656c6966206b6361ul, 0x756f6620746f6e20ul, 0x61766e49000a646eul, 0x6e6769732064696cul, 0x6e69206572757461ul, 0x6c69662072637620ul, 0x6f6365722d000a65ul, 0x7275636572006472ul, 0x7568732065766973ul, 0x25000a6e776f6474ul, 0x6769666e6f632f73ul, 0x430077006766632eul, 0x2074276e646c756ful, 0x6f63206574697277ul, 0x6766632e6769666eul, 0x5f74736f48000a2eul, 0x72203a726f727245ul, 0x6576697372756365ul, 0x7265746e6520796cul, 0x5f74736f48006465ul, 0x25203a726f727245ul, 0x5f74736f48000a73ul, 0x6e776f6474756853ul, 0x203a726576726553ul, 0x646e65535f54454eul, 0x6166206c6c416f54ul, 0x726f662064656c69ul, 0x65696c6320752520ul, 0x736f48000a73746eul, 0x6d6147646e455f74ul, 0x73000a7325203a65ul, 0x6f72707265767265ul, 0x3225203a656c6966ul, 0x746e65696c632069ul, 0x736d206932252073ul, 0x20693325000a6365ul, 0x2069332520746f74ul, 0x2520726576726573ul, 0x2520786667206933ul, 0xa646e73206933ul)

[init]
def private c2da_lin_init_static_host() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_host_seg[s * 2]
        for (k in range(c2da_lin_static_host_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_host[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_host_0 = fixed_array<uint8>(0x90, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_host_1 = fixed_array<uint8>(0xa1, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_host_2 = fixed_array<uint8>(0xad, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb9, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_host_3 = fixed_array<uint8>(0xbe, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_host_4 = fixed_array<uint8>(0xcc, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_host_5 = fixed_array<uint8>(0xd6, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_host_6 = fixed_array<uint8>(0xe0, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_host_7 = fixed_array<uint8>(0xe9, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_host_8 = fixed_array<uint8>(0xf3, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_host_9 = fixed_array<uint8>(0xfa, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_host_10 = fixed_array<uint8>(0x2, 0xf3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_host_11 = fixed_array<uint8>(0xc, 0xf3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_host_12 = fixed_array<uint8>(0x17, 0xf3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_host_13 = fixed_array<uint8>(0x1c, 0xf3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_host_14 = fixed_array<uint8>(0x25, 0xf3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf2, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_host() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[243152 + i] = c2da_lin_extern_host_0[i]
    }
    for (i in range(40)) {
        c2da_mem[243200 + i] = c2da_lin_extern_host_1[i]
    }
    for (i in range(40)) {
        c2da_mem[243248 + i] = c2da_lin_extern_host_2[i]
    }
    for (i in range(40)) {
        c2da_mem[243296 + i] = c2da_lin_extern_host_3[i]
    }
    for (i in range(40)) {
        c2da_mem[243344 + i] = c2da_lin_extern_host_4[i]
    }
    for (i in range(40)) {
        c2da_mem[243392 + i] = c2da_lin_extern_host_5[i]
    }
    for (i in range(40)) {
        c2da_mem[243440 + i] = c2da_lin_extern_host_6[i]
    }
    for (i in range(40)) {
        c2da_mem[243488 + i] = c2da_lin_extern_host_7[i]
    }
    for (i in range(40)) {
        c2da_mem[243536 + i] = c2da_lin_extern_host_8[i]
    }
    for (i in range(40)) {
        c2da_mem[243584 + i] = c2da_lin_extern_host_9[i]
    }
    for (i in range(40)) {
        c2da_mem[243632 + i] = c2da_lin_extern_host_10[i]
    }
    for (i in range(40)) {
        c2da_mem[243680 + i] = c2da_lin_extern_host_11[i]
    }
    for (i in range(40)) {
        c2da_mem[243728 + i] = c2da_lin_extern_host_12[i]
    }
    for (i in range(40)) {
        c2da_mem[243776 + i] = c2da_lin_extern_host_13[i]
    }
    for (i in range(40)) {
        c2da_mem[243824 + i] = c2da_lin_extern_host_14[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_host() {
    if (length(c2da_fn_table4) < 97) {
        resize(c2da_fn_table4, 97)
    }
    c2da_fn_table4[96] = @@SV_ClientPrintf
}

[init]
def private c2da_lin_relink_init_host() {
    c2da_relink_host()
}
