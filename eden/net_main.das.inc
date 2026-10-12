var net_activeSockets : int = 0

var net_freeSockets : int = 0

var net_numsockets : int = 0

var DEFAULTnet_hostport : int = 26000

var net_hostport : int = default<int>

var net_driverlevel : int = default<int>

var messagesSent : int = 0

var messagesReceived : int = 0

var unreliableMessagesSent : int = 0

var unreliableMessagesReceived : int = 0

[export, sideeffects]
def NET_NewQSocket() : int {
    var sock : int
    if (net_freeSockets == 0) {
        return 0
    }
    if (net_activeconnections >= svs.maxclients) {
        return 0
    }
    sock = net_freeSockets
    net_freeSockets = int(uint(c2da_mem[sock]) | uint(c2da_mem[sock + 1]) << 0x8 | uint(c2da_mem[sock + 2]) << 0x10 | uint(c2da_mem[sock + 3]) << 0x18)
    let c2da_fresh0 : uint = uint(net_activeSockets)
    c2da_mem[sock] = uint8(c2da_fresh0)
    c2da_mem[sock + 1] = uint8(c2da_fresh0 >> 0x8)
    c2da_mem[sock + 2] = uint8(c2da_fresh0 >> 0x10)
    c2da_mem[sock + 3] = uint8(c2da_fresh0 >> 0x18)
    c2da_mem[sock + 4] = 0u8
    c2da_mem[sock + 5] = 0u8
    c2da_mem[sock + 6] = 0u8
    c2da_mem[sock + 7] = 0u8
    net_activeSockets = sock
    let c2da_fresh1 : uint = 0u
    let c2da_fresh2 : uint = c2da_fresh1
    c2da_mem[sock + 32] = uint8(c2da_fresh2)
    c2da_mem[sock + 33] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[sock + 34] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[sock + 35] = uint8(c2da_fresh2 >> 0x18)
    let c2da_fresh3 : uint64 = double_bits_to_uint64(net_time)
    c2da_mem[sock + 8] = uint8(c2da_fresh3)
    c2da_mem[sock + 9] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[sock + 10] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[sock + 11] = uint8(c2da_fresh3 >> 0x18)
    c2da_mem[sock + 12] = uint8(c2da_fresh3 >> 0x20)
    c2da_mem[sock + 13] = uint8(c2da_fresh3 >> 0x28)
    c2da_mem[sock + 14] = uint8(c2da_fresh3 >> 0x30)
    c2da_mem[sock + 15] = uint8(c2da_fresh3 >> 0x38)
    Q_strcpy(sock + 16492, 727243)
    let c2da_fresh4 : uint = uint(net_driverlevel)
    c2da_mem[sock + 44] = uint8(c2da_fresh4)
    c2da_mem[sock + 45] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[sock + 46] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[sock + 47] = uint8(c2da_fresh4 >> 0x18)
    let c2da_fresh5 : int = 0
    let c2da_fresh6 : uint = uint(c2da_fresh5)
    c2da_mem[sock + 52] = uint8(c2da_fresh6)
    c2da_mem[sock + 53] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[sock + 54] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[sock + 55] = uint8(c2da_fresh6 >> 0x18)
    let c2da_fresh7 : uint = 0u
    c2da_mem[sock + 56] = uint8(c2da_fresh7)
    c2da_mem[sock + 57] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[sock + 58] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[sock + 59] = uint8(c2da_fresh7 >> 0x18)
    c2da_mem[sock + 60] = 0u8
    c2da_mem[sock + 61] = 0u8
    c2da_mem[sock + 62] = 0u8
    c2da_mem[sock + 63] = 0u8
    let c2da_fresh8 : uint = 1u
    let c2da_fresh9 : uint = c2da_fresh8
    c2da_mem[sock + 36] = uint8(c2da_fresh9)
    c2da_mem[sock + 37] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[sock + 38] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[sock + 39] = uint8(c2da_fresh9 >> 0x18)
    let c2da_fresh10 : uint = 0u
    let c2da_fresh11 : uint = c2da_fresh10
    c2da_mem[sock + 40] = uint8(c2da_fresh11)
    c2da_mem[sock + 41] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[sock + 42] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[sock + 43] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : uint64 = double_bits_to_uint64(net_time)
    c2da_mem[sock + 16] = uint8(c2da_fresh12)
    c2da_mem[sock + 17] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[sock + 18] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[sock + 19] = uint8(c2da_fresh12 >> 0x18)
    c2da_mem[sock + 20] = uint8(c2da_fresh12 >> 0x20)
    c2da_mem[sock + 21] = uint8(c2da_fresh12 >> 0x28)
    c2da_mem[sock + 22] = uint8(c2da_fresh12 >> 0x30)
    c2da_mem[sock + 23] = uint8(c2da_fresh12 >> 0x38)
    let c2da_fresh13 : uint = 0u
    let c2da_fresh14 : uint = c2da_fresh13
    c2da_mem[sock + 64] = uint8(c2da_fresh14)
    c2da_mem[sock + 65] = uint8(c2da_fresh14 >> 0x8)
    c2da_mem[sock + 66] = uint8(c2da_fresh14 >> 0x10)
    c2da_mem[sock + 67] = uint8(c2da_fresh14 >> 0x18)
    let c2da_fresh15 : uint = 0u
    let c2da_fresh16 : uint = c2da_fresh15
    c2da_mem[sock + 68] = uint8(c2da_fresh16)
    c2da_mem[sock + 69] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[sock + 70] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[sock + 71] = uint8(c2da_fresh16 >> 0x18)
    let c2da_fresh17 : uint = 0u
    let c2da_fresh18 : uint = c2da_fresh17
    c2da_mem[sock + 72] = uint8(c2da_fresh18)
    c2da_mem[sock + 73] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[sock + 74] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[sock + 75] = uint8(c2da_fresh18 >> 0x18)
    let c2da_fresh19 : int = 0
    let c2da_fresh20 : uint = uint(c2da_fresh19)
    c2da_mem[sock + 76] = uint8(c2da_fresh20)
    c2da_mem[sock + 77] = uint8(c2da_fresh20 >> 0x8)
    c2da_mem[sock + 78] = uint8(c2da_fresh20 >> 0x10)
    c2da_mem[sock + 79] = uint8(c2da_fresh20 >> 0x18)
    let c2da_fresh21 : uint = 0u
    let c2da_fresh22 : uint = c2da_fresh21
    c2da_mem[sock + 8272] = uint8(c2da_fresh22)
    c2da_mem[sock + 8273] = uint8(c2da_fresh22 >> 0x8)
    c2da_mem[sock + 8274] = uint8(c2da_fresh22 >> 0x10)
    c2da_mem[sock + 8275] = uint8(c2da_fresh22 >> 0x18)
    let c2da_fresh23 : uint = 0u
    let c2da_fresh24 : uint = c2da_fresh23
    c2da_mem[sock + 8276] = uint8(c2da_fresh24)
    c2da_mem[sock + 8277] = uint8(c2da_fresh24 >> 0x8)
    c2da_mem[sock + 8278] = uint8(c2da_fresh24 >> 0x10)
    c2da_mem[sock + 8279] = uint8(c2da_fresh24 >> 0x18)
    let c2da_fresh25 : int = 0
    let c2da_fresh26 : uint = uint(c2da_fresh25)
    c2da_mem[sock + 8280] = uint8(c2da_fresh26)
    c2da_mem[sock + 8281] = uint8(c2da_fresh26 >> 0x8)
    c2da_mem[sock + 8282] = uint8(c2da_fresh26 >> 0x10)
    c2da_mem[sock + 8283] = uint8(c2da_fresh26 >> 0x18)
    return sock
}
var net_time : double = default<double>

var net_activeconnections : int = 0

[export, sideeffects]
def NET_FreeQSocket(var sock_0 : int) {
    var s : int
    if (sock_0 == net_activeSockets) {
        net_activeSockets = int(uint(c2da_mem[net_activeSockets]) | uint(c2da_mem[net_activeSockets + 1]) << 0x8 | uint(c2da_mem[net_activeSockets + 2]) << 0x10 | uint(c2da_mem[net_activeSockets + 3]) << 0x18)
    } else {
        s = net_activeSockets
        while (s != 0) {
            if (int(uint(c2da_mem[s]) | uint(c2da_mem[s + 1]) << 0x8 | uint(c2da_mem[s + 2]) << 0x10 | uint(c2da_mem[s + 3]) << 0x18) == sock_0) {
                let c2da_fresh27 : int = int(uint(c2da_mem[sock_0]) | uint(c2da_mem[sock_0 + 1]) << 0x8 | uint(c2da_mem[sock_0 + 2]) << 0x10 | uint(c2da_mem[sock_0 + 3]) << 0x18)
                let c2da_fresh28 : uint = uint(c2da_fresh27)
                c2da_mem[s] = uint8(c2da_fresh28)
                c2da_mem[s + 1] = uint8(c2da_fresh28 >> 0x8)
                c2da_mem[s + 2] = uint8(c2da_fresh28 >> 0x10)
                c2da_mem[s + 3] = uint8(c2da_fresh28 >> 0x18)
                c2da_mem[s + 4] = 0u8
                c2da_mem[s + 5] = 0u8
                c2da_mem[s + 6] = 0u8
                c2da_mem[s + 7] = 0u8
                break
            }
            s = int(uint(c2da_mem[s]) | uint(c2da_mem[s + 1]) << 0x8 | uint(c2da_mem[s + 2]) << 0x10 | uint(c2da_mem[s + 3]) << 0x18)
        }
        if (s == 0) {
            Sys_Error(727257, [])
        }
    }
    let c2da_fresh29 : uint = uint(net_freeSockets)
    c2da_mem[sock_0] = uint8(c2da_fresh29)
    c2da_mem[sock_0 + 1] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[sock_0 + 2] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[sock_0 + 3] = uint8(c2da_fresh29 >> 0x18)
    c2da_mem[sock_0 + 4] = 0u8
    c2da_mem[sock_0 + 5] = 0u8
    c2da_mem[sock_0 + 6] = 0u8
    c2da_mem[sock_0 + 7] = 0u8
    net_freeSockets = int(sock_0)  // nolint:PERF020
    let c2da_fresh30 : uint = 1u
    let c2da_fresh31 : uint = c2da_fresh30
    c2da_mem[sock_0 + 32] = uint8(c2da_fresh31)
    c2da_mem[sock_0 + 33] = uint8(c2da_fresh31 >> 0x8)
    c2da_mem[sock_0 + 34] = uint8(c2da_fresh31 >> 0x10)
    c2da_mem[sock_0 + 35] = uint8(c2da_fresh31 >> 0x18)
    return
}
[export, sideeffects]
def SetNetTime() : double {
    net_time = Sys_FloatTime()
    return net_time
}
var hostCacheCount : int = 0

[export, sideeffects]
def NET_Init() {
    var i : int
    var controlSocket : int
    var s_0 : int
    if (COM_CheckParm(727286) != 0) {
        net_numdrivers = 1
        net_drivers[0].Init = 113
    }
    if (COM_CheckParm(727296) != 0) {
        recording = 1u
    }
    i = COM_CheckParm(727304)
    if (i == 0) {
        i = COM_CheckParm(727310)
    }
    if (i == 0) {
        i = COM_CheckParm(727319)
    }
    if (i != 0) {
        if (i < int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) - 1) {
            DEFAULTnet_hostport = Q_atoi(int(uint(c2da_mem[com_argv + (i + 1) * 8]) | uint(c2da_mem[com_argv + (i + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + (i + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + (i + 1) * 8 + 3]) << 0x18))
        } else {
            Sys_Error(727328, [])
        }
    }
    net_hostport = int(DEFAULTnet_hostport)  // nolint:PERF020
    if (COM_CheckParm(727376) != 0 || (uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 0u) {
        listening = 1u
    }
    net_numsockets = svs.maxclientslimit
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) != 0u) {
        net_numsockets++
    }
    SetNetTime()
    i = 0
    while (i < net_numsockets) {
        s_0 = Hunk_AllocName(16560, 727384)
        let c2da_fresh32 : uint = uint(net_freeSockets)
        c2da_mem[s_0] = uint8(c2da_fresh32)
        c2da_mem[s_0 + 1] = uint8(c2da_fresh32 >> 0x8)
        c2da_mem[s_0 + 2] = uint8(c2da_fresh32 >> 0x10)
        c2da_mem[s_0 + 3] = uint8(c2da_fresh32 >> 0x18)
        c2da_mem[s_0 + 4] = 0u8
        c2da_mem[s_0 + 5] = 0u8
        c2da_mem[s_0 + 6] = 0u8
        c2da_mem[s_0 + 7] = 0u8
        net_freeSockets = s_0
        let c2da_fresh33 : uint = 1u
        let c2da_fresh34 : uint = c2da_fresh33
        c2da_mem[s_0 + 32] = uint8(c2da_fresh34)
        c2da_mem[s_0 + 33] = uint8(c2da_fresh34 >> 0x8)
        c2da_mem[s_0 + 34] = uint8(c2da_fresh34 >> 0x10)
        c2da_mem[s_0 + 35] = uint8(c2da_fresh34 >> 0x18)
        i++
    }
    SZ_Alloc(5360, 8192)
    Cvar_RegisterVariable(386416)
    Cvar_RegisterVariable(386464)
    Cvar_RegisterVariable(386512)
    Cvar_RegisterVariable(386560)
    Cvar_RegisterVariable(386608)
    Cvar_RegisterVariable(386656)
    Cvar_RegisterVariable(386704)
    Cvar_RegisterVariable(386752)
    Cvar_RegisterVariable(386800)
    Cvar_RegisterVariable(386848)
    Cmd_AddCommand(727392, 114)
    Cmd_AddCommand(727398, 224)
    Cmd_AddCommand(727405, 225)
    Cmd_AddCommand(727416, 226)
    net_driverlevel = 0
    while (net_driverlevel < net_numdrivers) {
        controlSocket = invoke(c2da_fn_table8[net_drivers[net_driverlevel].Init])
        if (controlSocket == -1) {
            net_driverlevel++
            continue
        }
        net_drivers[net_driverlevel].initialized = 1u
        net_drivers[net_driverlevel].controlSock = controlSocket
        if (listening != 0u) {
            invoke(c2da_fn_table9[net_drivers[net_driverlevel].Listen], 1u)
        }
        net_driverlevel++
    }
    if (int8(c2da_mem[243088]) != 0) {
        Con_DPrintf(727421, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 243088ul)])
    }
    if (int8(c2da_mem[243024]) != 0) {
        Con_DPrintf(727437, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 243024ul)])
    }
    return
}
var private listening : uint = 0u

[sideeffects]
def private NET_Port_f() {
    var n : int
    if (Cmd_Argc() != 2) {
        Con_Printf(727456, [C2daVaArg(tag = 1, i64 = int64(net_hostport), f64 = 0.0lf, raw = 0x0)])
        return
    }
    n = Q_atoi(Cmd_Argv(1))
    if (n < 1 || n > 65534) {
        Con_Printf(727472, [])
        return
    }
    DEFAULTnet_hostport = n
    net_hostport = n
    if (listening != 0u) {
        Cbuf_AddText(727512)
        Cbuf_AddText(727522)
    }
    return
}
[sideeffects]
def private MaxPlayers_f() {
    var n_0 : int
    if (Cmd_Argc() != 2) {
        Con_Printf(727532, [C2daVaArg(tag = 1, i64 = int64(svs.maxclients), f64 = 0.0lf, raw = 0x0)])
        return
    }
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) != 0u) {
        Con_Printf(727554, [])
        return
    }
    n_0 = Q_atoi(Cmd_Argv(1))
    if (n_0 < 1) {
        n_0 = 1
    }
    if (n_0 > svs.maxclientslimit) {
        n_0 = svs.maxclientslimit
        Con_Printf(727612, [C2daVaArg(tag = 1, i64 = int64(n_0), f64 = 0.0lf, raw = 0x0)])
    }
    if (n_0 == 1 && listening != 0x0) {
        Cbuf_AddText(727512)
    }
    if (n_0 > 1 && listening == 0u) {
        Cbuf_AddText(727522)
    }
    svs.maxclients = n_0
    if (n_0 == 1) {
        Cvar_Set(727638, 727649)
    } else {
        Cvar_Set(727638, 727146)
    }
    return
}
[sideeffects]
def private NET_Listen_f() {
    if (Cmd_Argc() != 2) {
        Con_Printf(727651, [C2daVaArg(tag = 1, i64 = int64(listening != 0x0 ? 1 : 0), f64 = 0.0lf, raw = 0x0)])
        return
    }
    listening = uint(Q_atoi(Cmd_Argv(1)) != 0 ? 1 : 0)
    net_driverlevel = 0
    while (net_driverlevel < net_numdrivers) {
        if (uint(net_drivers[net_driverlevel].initialized) == 0u) {
            net_driverlevel++
            continue
        }
        invoke(c2da_fn_table9[net_drivers[net_driverlevel].Listen], listening)
        net_driverlevel++
    }
    return
}
[export, sideeffects]
def NET_Slist_f() {
    if (slistInProgress != 0u) {
        return
    }
    if (slistSilent == 0u) {
        Con_Printf(727669, [])
        PrintSlistHeader()
    }
    slistInProgress = 1u
    slistStartTime = Sys_FloatTime()
    SchedulePollProcedure(386896, 0.0lf)
    SchedulePollProcedure(386928, 0.1lf)
    hostCacheCount = 0
    return
}
[sideeffects]
def private Slist_Poll() {
    net_driverlevel = 0
    while (net_driverlevel < net_numdrivers) {
        if (slistLocal == 0u && net_driverlevel == 0) {
            net_driverlevel++
            continue
        }
        if (uint(net_drivers[net_driverlevel].initialized) == 0u) {
            net_driverlevel++
            continue
        }
        invoke(c2da_fn_table9[net_drivers[net_driverlevel].SearchForHosts], 0u)
        net_driverlevel++
    }
    if (slistSilent == 0u) {
        PrintSlist()
    }
    if (Sys_FloatTime() - slistStartTime < 1.5lf) {
        SchedulePollProcedure(386928, 0.1lf)
        return
    }
    if (slistSilent == 0u) {
        PrintSlistTrailer()
    }
    slistInProgress = 0u
    slistSilent = 0u
    slistLocal = 1u
    return
}
var slistLocal : uint = 1u

var slistSilent : uint = 0u

var slistInProgress : uint = 0u

[sideeffects]
def private PrintSlistTrailer() {
    if (hostCacheCount != 0) {
        Con_Printf(727699, [])
    } else {
        Con_Printf(727716, [])
    }
    return
}
[export, sideeffects]
def SchedulePollProcedure(var proc : int; var timeOffset : double) {
    var pp : int
    var prev : int
    let c2da_fresh35 : double = Sys_FloatTime() + timeOffset
    let c2da_fresh36 : uint64 = double_bits_to_uint64(c2da_fresh35)
    c2da_mem[proc + 8] = uint8(c2da_fresh36)
    c2da_mem[proc + 9] = uint8(c2da_fresh36 >> 0x8)
    c2da_mem[proc + 10] = uint8(c2da_fresh36 >> 0x10)
    c2da_mem[proc + 11] = uint8(c2da_fresh36 >> 0x18)
    c2da_mem[proc + 12] = uint8(c2da_fresh36 >> 0x20)
    c2da_mem[proc + 13] = uint8(c2da_fresh36 >> 0x28)
    c2da_mem[proc + 14] = uint8(c2da_fresh36 >> 0x30)
    c2da_mem[proc + 15] = uint8(c2da_fresh36 >> 0x38)
    pp = pollProcedureList
    prev = 0
    while (pp != 0) {
        if (uint64_bits_to_double(uint64(uint(c2da_mem[pp + 8]) | uint(c2da_mem[pp + 9]) << 0x8 | uint(c2da_mem[pp + 10]) << 0x10 | uint(c2da_mem[pp + 11]) << 0x18) | uint64(uint(c2da_mem[pp + 12]) | uint(c2da_mem[pp + 13]) << 0x8 | uint(c2da_mem[pp + 14]) << 0x10 | uint(c2da_mem[pp + 15]) << 0x18) << 0x20) >= uint64_bits_to_double(uint64(uint(c2da_mem[proc + 8]) | uint(c2da_mem[proc + 9]) << 0x8 | uint(c2da_mem[proc + 10]) << 0x10 | uint(c2da_mem[proc + 11]) << 0x18) | uint64(uint(c2da_mem[proc + 12]) | uint(c2da_mem[proc + 13]) << 0x8 | uint(c2da_mem[proc + 14]) << 0x10 | uint(c2da_mem[proc + 15]) << 0x18) << 0x20)) {
            break
        }
        prev = pp
        pp = int(uint(c2da_mem[pp]) | uint(c2da_mem[pp + 1]) << 0x8 | uint(c2da_mem[pp + 2]) << 0x10 | uint(c2da_mem[pp + 3]) << 0x18)
    }
    if (prev == 0) {
        let c2da_fresh37 : uint = uint(pollProcedureList)
        c2da_mem[proc] = uint8(c2da_fresh37)
        c2da_mem[proc + 1] = uint8(c2da_fresh37 >> 0x8)
        c2da_mem[proc + 2] = uint8(c2da_fresh37 >> 0x10)
        c2da_mem[proc + 3] = uint8(c2da_fresh37 >> 0x18)
        c2da_mem[proc + 4] = 0u8
        c2da_mem[proc + 5] = 0u8
        c2da_mem[proc + 6] = 0u8
        c2da_mem[proc + 7] = 0u8
        pollProcedureList = int(proc)  // nolint:PERF020
        return
    }
    let c2da_fresh38 : uint = uint(pp)
    c2da_mem[proc] = uint8(c2da_fresh38)
    c2da_mem[proc + 1] = uint8(c2da_fresh38 >> 0x8)
    c2da_mem[proc + 2] = uint8(c2da_fresh38 >> 0x10)
    c2da_mem[proc + 3] = uint8(c2da_fresh38 >> 0x18)
    c2da_mem[proc + 4] = 0u8
    c2da_mem[proc + 5] = 0u8
    c2da_mem[proc + 6] = 0u8
    c2da_mem[proc + 7] = 0u8
    let c2da_fresh39 : uint = uint(proc)
    c2da_mem[prev] = uint8(c2da_fresh39)
    c2da_mem[prev + 1] = uint8(c2da_fresh39 >> 0x8)
    c2da_mem[prev + 2] = uint8(c2da_fresh39 >> 0x10)
    c2da_mem[prev + 3] = uint8(c2da_fresh39 >> 0x18)
    c2da_mem[prev + 4] = 0u8
    c2da_mem[prev + 5] = 0u8
    c2da_mem[prev + 6] = 0u8
    c2da_mem[prev + 7] = 0u8
    return
}
var private pollProcedureList : int = 0

var private slistStartTime : double = default<double>

[sideeffects]
def private PrintSlist() {
    var n_1 : int = slistLastShown
    while (n_1 < hostCacheCount) {
        if (int(uint(c2da_mem[246672 + n_1 * 96 + 68]) | uint(c2da_mem[246672 + n_1 * 96 + 69]) << 0x8 | uint(c2da_mem[246672 + n_1 * 96 + 70]) << 0x10 | uint(c2da_mem[246672 + n_1 * 96 + 71]) << 0x18) != 0) {
            Con_Printf(727742, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(246672 + n_1 * 96)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(246672 + n_1 * 96 + 16)), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[246672 + n_1 * 96 + 64]) | uint(c2da_mem[246672 + n_1 * 96 + 65]) << 0x8 | uint(c2da_mem[246672 + n_1 * 96 + 66]) << 0x10 | uint(c2da_mem[246672 + n_1 * 96 + 67]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[246672 + n_1 * 96 + 68]) | uint(c2da_mem[246672 + n_1 * 96 + 69]) << 0x8 | uint(c2da_mem[246672 + n_1 * 96 + 70]) << 0x10 | uint(c2da_mem[246672 + n_1 * 96 + 71]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
        } else {
            Con_Printf(727769, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(246672 + n_1 * 96)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(246672 + n_1 * 96 + 16))])
        }
        n_1++
    }
    slistLastShown = n_1
    return
}
var private slistLastShown : int = default<int>

[sideeffects]
def private Slist_Send() {
    net_driverlevel = 0
    while (net_driverlevel < net_numdrivers) {
        if (slistLocal == 0u && net_driverlevel == 0) {
            net_driverlevel++
            continue
        }
        if (uint(net_drivers[net_driverlevel].initialized) == 0u) {
            net_driverlevel++
            continue
        }
        invoke(c2da_fn_table9[net_drivers[net_driverlevel].SearchForHosts], 1u)
        net_driverlevel++
    }
    if (Sys_FloatTime() - slistStartTime < 0.5lf) {
        SchedulePollProcedure(386896, 0.75lf)
    }
    return
}
[sideeffects]
def private PrintSlistHeader() {
    Con_Printf(727788, [])
    Con_Printf(727827, [])
    slistLastShown = 0
    return
}
var recording : uint = 0u

[export, sideeffects]
def NET_Shutdown() {
    var sock_1 : int
    SetNetTime()
    sock_1 = net_activeSockets
    while (sock_1 != 0) {
        NET_Close(sock_1)
        sock_1 = int(uint(c2da_mem[sock_1]) | uint(c2da_mem[sock_1 + 1]) << 0x8 | uint(c2da_mem[sock_1 + 2]) << 0x10 | uint(c2da_mem[sock_1 + 3]) << 0x18)
    }
    net_driverlevel = 0
    while (net_driverlevel < net_numdrivers) {
        if (uint(net_drivers[net_driverlevel].initialized) == 1u) {
            invoke(c2da_fn_table0[net_drivers[net_driverlevel].Shutdown])
            net_drivers[net_driverlevel].initialized = 0u
        }
        net_driverlevel++
    }
    let c2da_fresh40 : int = int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18)
    if (c2da_fresh40 != -1) {
        Con_Printf(727866, [])
        Sys_FileClose(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18))
    }
    return
}
[export, sideeffects]
def NET_Close(var sock_2 : int) {
    if (sock_2 == 0) {
        return
    }
    if ((uint(c2da_mem[sock_2 + 32]) | uint(c2da_mem[sock_2 + 33]) << 0x8 | uint(c2da_mem[sock_2 + 34]) << 0x10 | uint(c2da_mem[sock_2 + 35]) << 0x18) != 0u) {
        return
    }
    SetNetTime()
    invoke(c2da_fn_table5[net_drivers[int(uint(c2da_mem[sock_2 + 44]) | uint(c2da_mem[sock_2 + 45]) << 0x8 | uint(c2da_mem[sock_2 + 46]) << 0x10 | uint(c2da_mem[sock_2 + 47]) << 0x18)].Close], sock_2)
    NET_FreeQSocket(sock_2)
    return
}
[export, sideeffects]
def NET_CheckNewConnections() : int {
    var ret : int
    SetNetTime()
    net_driverlevel = 0
    while (net_driverlevel < net_numdrivers) {
        if (uint(net_drivers[net_driverlevel].initialized) == 0u) {
            net_driverlevel++
            continue
        }
        if (net_driverlevel != 0 && listening == 0u) {
            net_driverlevel++
            continue
        }
        ret = invoke(c2da_fn_table8[net_drivers[net_driverlevel].CheckNewConnections])
        if (ret != 0) {
            if (recording != 0u) {
                let c2da_fresh41 : uint64 = double_bits_to_uint64(host_time)
                c2da_mem[386960] = uint8(c2da_fresh41)
                c2da_mem[386961] = uint8(c2da_fresh41 >> 0x8)
                c2da_mem[386962] = uint8(c2da_fresh41 >> 0x10)
                c2da_mem[386963] = uint8(c2da_fresh41 >> 0x18)
                c2da_mem[386964] = uint8(c2da_fresh41 >> 0x20)
                c2da_mem[386965] = uint8(c2da_fresh41 >> 0x28)
                c2da_mem[386966] = uint8(c2da_fresh41 >> 0x30)
                c2da_mem[386967] = uint8(c2da_fresh41 >> 0x38)
                let c2da_fresh42 : int = 1
                let c2da_fresh43 : uint = uint(c2da_fresh42)
                c2da_mem[386968] = uint8(c2da_fresh43)
                c2da_mem[386969] = uint8(c2da_fresh43 >> 0x8)
                c2da_mem[386970] = uint8(c2da_fresh43 >> 0x10)
                c2da_mem[386971] = uint8(c2da_fresh43 >> 0x18)
                let c2da_fresh44 : int64 = int64(ret)
                let c2da_fresh45 : uint64 = uint64(c2da_fresh44)
                c2da_mem[386976] = uint8(c2da_fresh45)
                c2da_mem[386977] = uint8(c2da_fresh45 >> 0x8)
                c2da_mem[386978] = uint8(c2da_fresh45 >> 0x10)
                c2da_mem[386979] = uint8(c2da_fresh45 >> 0x18)
                c2da_mem[386980] = uint8(c2da_fresh45 >> 0x20)
                c2da_mem[386981] = uint8(c2da_fresh45 >> 0x28)
                c2da_mem[386982] = uint8(c2da_fresh45 >> 0x30)
                c2da_mem[386983] = uint8(c2da_fresh45 >> 0x38)
                Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), 386960, 24)
                Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), ret + 16492, 64)
            }
            return ret
        }
        net_driverlevel++
    }
    if (recording != 0u) {
        let c2da_fresh46 : uint64 = double_bits_to_uint64(host_time)
        c2da_mem[386960] = uint8(c2da_fresh46)
        c2da_mem[386961] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[386962] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[386963] = uint8(c2da_fresh46 >> 0x18)
        c2da_mem[386964] = uint8(c2da_fresh46 >> 0x20)
        c2da_mem[386965] = uint8(c2da_fresh46 >> 0x28)
        c2da_mem[386966] = uint8(c2da_fresh46 >> 0x30)
        c2da_mem[386967] = uint8(c2da_fresh46 >> 0x38)
        let c2da_fresh47 : int = 1
        let c2da_fresh48 : uint = uint(c2da_fresh47)
        c2da_mem[386968] = uint8(c2da_fresh48)
        c2da_mem[386969] = uint8(c2da_fresh48 >> 0x8)
        c2da_mem[386970] = uint8(c2da_fresh48 >> 0x10)
        c2da_mem[386971] = uint8(c2da_fresh48 >> 0x18)
        let c2da_fresh49 : int64 = 0l
        let c2da_fresh50 : uint64 = uint64(c2da_fresh49)
        c2da_mem[386976] = uint8(c2da_fresh50)
        c2da_mem[386977] = uint8(c2da_fresh50 >> 0x8)
        c2da_mem[386978] = uint8(c2da_fresh50 >> 0x10)
        c2da_mem[386979] = uint8(c2da_fresh50 >> 0x18)
        c2da_mem[386980] = uint8(c2da_fresh50 >> 0x20)
        c2da_mem[386981] = uint8(c2da_fresh50 >> 0x28)
        c2da_mem[386982] = uint8(c2da_fresh50 >> 0x30)
        c2da_mem[386983] = uint8(c2da_fresh50 >> 0x38)
        Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), 386960, 24)
    }
    return 0
}
[export, sideeffects]
def NET_Connect(var host : int) : int {
    var ret_0 : int
    var n_2 : int
    var numdrivers : int = net_numdrivers
    SetNetTime()
    if (host != 0 && int(int8(c2da_mem[host])) == 0) {
        goto label 30
    }
    label 0:
    if (host != 0) {
        goto label 21
    }
    label 1:
    slistSilent = uint(host != 0 ? 1 : 0)
    NET_Slist_f()
    label 2:
    if (slistInProgress != 0u) {
        goto label 20
    }
    if (host == 0) {
        goto label 18
    }
    label 3:
    if (hostCacheCount != 0) {
        goto label 13
    }
    label 4:
    label 5:
    net_driverlevel = 0
    label 6:
    if (net_driverlevel < numdrivers) {
        goto label 9
    }
    if (host != 0) {
        goto label 8
    }
    label 7:
    return 0
    label 8:
    Con_Printf(727917, [])
    PrintSlistHeader()
    PrintSlist()
    PrintSlistTrailer()
    goto label 7
    label 9:
    if (uint(net_drivers[net_driverlevel].initialized) == 0u) {
        goto label 12
    }
    ret_0 = invoke(c2da_fn_table2[net_drivers[net_driverlevel].Connect], host)
    if (ret_0 != 0) {
        goto label 11
    }
    label 10:
    net_driverlevel++
    goto label 6
    label 11:
    return ret_0
    label 12:
    goto label 10
    label 13:
    n_2 = 0
    label 14:
    if (n_2 < hostCacheCount) {
        goto label 16
    }
    label 15:
    goto label 4
    label 16:
    if (Q_strcasecmp(host, 246672 + n_2 * 96) == 0) {
        goto label 17
    }
    n_2++
    goto label 14
    label 17:
    host = 246672 + n_2 * 96 + 32
    goto label 15
    label 18:
    if (hostCacheCount != 1) {
        goto label 19
    }
    host = 246672 + 0 * 96 + 32
    Con_Printf(727890, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(246672 + 0 * 96)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(host))])
    goto label 3
    label 19:
    return 0
    label 20:
    NET_Poll()
    goto label 2
    label 21:
    if (Q_strcasecmp(host, 727884) == 0) {
        goto label 29
    }
    if (hostCacheCount != 0) {
        goto label 23
    }
    label 22:
    goto label 1
    label 23:
    n_2 = 0
    label 24:
    if (n_2 < hostCacheCount) {
        goto label 27
    }
    label 25:
    if (n_2 < hostCacheCount) {
        goto label 26
    }
    goto label 22
    label 26:
    goto label 5
    label 27:
    if (Q_strcasecmp(host, 246672 + n_2 * 96) == 0) {
        goto label 28
    }
    n_2++
    goto label 24
    label 28:
    host = 246672 + n_2 * 96 + 32
    goto label 25
    label 29:
    numdrivers = 1
    goto label 5
    label 30:
    host = 0
    goto label 0
    panic("unreachable: fell out of a translated control-flow graph")
}
[export, sideeffects]
def NET_Poll() {
    var pp_0 : int
    var useModem : uint
    if (configRestored == 0u) {
        if (serialAvailable != 0u) {
            if (double(uint_bits_to_float(uint(c2da_mem[386680]) | uint(c2da_mem[386681]) << 0x8 | uint(c2da_mem[386682]) << 0x10 | uint(c2da_mem[386683]) << 0x18)) == 1.0lf) {
                useModem = 1u
            } else {
                useModem = 0u
            }
            invoke(c2da_fn_table7[SetComPortConfig], 0, int(uint_bits_to_float(uint(c2da_mem[386536]) | uint(c2da_mem[386537]) << 0x8 | uint(c2da_mem[386538]) << 0x10 | uint(c2da_mem[386539]) << 0x18)), int(uint_bits_to_float(uint(c2da_mem[386584]) | uint(c2da_mem[386585]) << 0x8 | uint(c2da_mem[386586]) << 0x10 | uint(c2da_mem[386587]) << 0x18)), int(uint_bits_to_float(uint(c2da_mem[386632]) | uint(c2da_mem[386633]) << 0x8 | uint(c2da_mem[386634]) << 0x10 | uint(c2da_mem[386635]) << 0x18)), useModem)
            invoke(c2da_fn_table6[SetModemConfig], 0, int(uint(c2da_mem[386712]) | uint(c2da_mem[386713]) << 0x8 | uint(c2da_mem[386714]) << 0x10 | uint(c2da_mem[386715]) << 0x18), int(uint(c2da_mem[386760]) | uint(c2da_mem[386761]) << 0x8 | uint(c2da_mem[386762]) << 0x10 | uint(c2da_mem[386763]) << 0x18), int(uint(c2da_mem[386808]) | uint(c2da_mem[386809]) << 0x8 | uint(c2da_mem[386810]) << 0x10 | uint(c2da_mem[386811]) << 0x18), int(uint(c2da_mem[386856]) | uint(c2da_mem[386857]) << 0x8 | uint(c2da_mem[386858]) << 0x10 | uint(c2da_mem[386859]) << 0x18))
        }
        configRestored = 1u
    }
    SetNetTime()
    pp_0 = pollProcedureList
    while (pp_0 != 0) {
        if (uint64_bits_to_double(uint64(uint(c2da_mem[pp_0 + 8]) | uint(c2da_mem[pp_0 + 9]) << 0x8 | uint(c2da_mem[pp_0 + 10]) << 0x10 | uint(c2da_mem[pp_0 + 11]) << 0x18) | uint64(uint(c2da_mem[pp_0 + 12]) | uint(c2da_mem[pp_0 + 13]) << 0x8 | uint(c2da_mem[pp_0 + 14]) << 0x10 | uint(c2da_mem[pp_0 + 15]) << 0x18) << 0x20) > net_time) {
            break
        }
        pollProcedureList = int(uint(c2da_mem[pp_0]) | uint(c2da_mem[pp_0 + 1]) << 0x8 | uint(c2da_mem[pp_0 + 2]) << 0x10 | uint(c2da_mem[pp_0 + 3]) << 0x18)
        invoke(c2da_fn_table5[int(uint(c2da_mem[pp_0 + 16]) | uint(c2da_mem[pp_0 + 17]) << 0x8 | uint(c2da_mem[pp_0 + 18]) << 0x10 | uint(c2da_mem[pp_0 + 19]) << 0x18)], int(uint(c2da_mem[pp_0 + 24]) | uint(c2da_mem[pp_0 + 25]) << 0x8 | uint(c2da_mem[pp_0 + 26]) << 0x10 | uint(c2da_mem[pp_0 + 27]) << 0x18))
        pp_0 = int(uint(c2da_mem[pp_0]) | uint(c2da_mem[pp_0 + 1]) << 0x8 | uint(c2da_mem[pp_0 + 2]) << 0x10 | uint(c2da_mem[pp_0 + 3]) << 0x18)
    }
    return
}
var configRestored : uint = 0u

var SetModemConfig : int = default<int>

var SetComPortConfig : int = default<int>

var serialAvailable : uint = 0u

[export, sideeffects]
def NET_CanSendMessage(var sock_3 : int) : uint {
    var r : int
    if (sock_3 == 0) {
        return 0u
    }
    if ((uint(c2da_mem[sock_3 + 32]) | uint(c2da_mem[sock_3 + 33]) << 0x8 | uint(c2da_mem[sock_3 + 34]) << 0x10 | uint(c2da_mem[sock_3 + 35]) << 0x18) != 0u) {
        return 0u
    }
    SetNetTime()
    r = int(invoke(c2da_fn_table11[net_drivers[int(uint(c2da_mem[sock_3 + 44]) | uint(c2da_mem[sock_3 + 45]) << 0x8 | uint(c2da_mem[sock_3 + 46]) << 0x10 | uint(c2da_mem[sock_3 + 47]) << 0x18)].CanSendMessage], sock_3))
    if (recording != 0u) {
        let c2da_fresh51 : uint64 = double_bits_to_uint64(host_time)
        c2da_mem[386992] = uint8(c2da_fresh51)
        c2da_mem[386993] = uint8(c2da_fresh51 >> 0x8)
        c2da_mem[386994] = uint8(c2da_fresh51 >> 0x10)
        c2da_mem[386995] = uint8(c2da_fresh51 >> 0x18)
        c2da_mem[386996] = uint8(c2da_fresh51 >> 0x20)
        c2da_mem[386997] = uint8(c2da_fresh51 >> 0x28)
        c2da_mem[386998] = uint8(c2da_fresh51 >> 0x30)
        c2da_mem[386999] = uint8(c2da_fresh51 >> 0x38)
        let c2da_fresh52 : int = 4
        let c2da_fresh53 : uint = uint(c2da_fresh52)
        c2da_mem[387000] = uint8(c2da_fresh53)
        c2da_mem[387001] = uint8(c2da_fresh53 >> 0x8)
        c2da_mem[387002] = uint8(c2da_fresh53 >> 0x10)
        c2da_mem[387003] = uint8(c2da_fresh53 >> 0x18)
        let c2da_fresh54 : int64 = int64(sock_3)
        let c2da_fresh55 : uint64 = uint64(c2da_fresh54)
        c2da_mem[387008] = uint8(c2da_fresh55)
        c2da_mem[387009] = uint8(c2da_fresh55 >> 0x8)
        c2da_mem[387010] = uint8(c2da_fresh55 >> 0x10)
        c2da_mem[387011] = uint8(c2da_fresh55 >> 0x18)
        c2da_mem[387012] = uint8(c2da_fresh55 >> 0x20)
        c2da_mem[387013] = uint8(c2da_fresh55 >> 0x28)
        c2da_mem[387014] = uint8(c2da_fresh55 >> 0x30)
        c2da_mem[387015] = uint8(c2da_fresh55 >> 0x38)
        let c2da_fresh56 : uint = uint(r)
        c2da_mem[387016] = uint8(c2da_fresh56)
        c2da_mem[387017] = uint8(c2da_fresh56 >> 0x8)
        c2da_mem[387018] = uint8(c2da_fresh56 >> 0x10)
        c2da_mem[387019] = uint8(c2da_fresh56 >> 0x18)
        Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), 386992, 20)
    }
    return uint(r)
}
[export, sideeffects]
def NET_GetMessage(var sock_4 : int) : int {
    var ret_1 : int
    if (sock_4 == 0) {
        return -1
    }
    if ((uint(c2da_mem[sock_4 + 32]) | uint(c2da_mem[sock_4 + 33]) << 0x8 | uint(c2da_mem[sock_4 + 34]) << 0x10 | uint(c2da_mem[sock_4 + 35]) << 0x18) != 0u) {
        Con_Printf(727919, [])
        return -1
    }
    SetNetTime()
    ret_1 = invoke(c2da_fn_table2[net_drivers[int(uint(c2da_mem[sock_4 + 44]) | uint(c2da_mem[sock_4 + 45]) << 0x8 | uint(c2da_mem[sock_4 + 46]) << 0x10 | uint(c2da_mem[sock_4 + 47]) << 0x18)].QGetMessage], sock_4)
    if (ret_1 == 0 && int(uint(c2da_mem[sock_4 + 44]) | uint(c2da_mem[sock_4 + 45]) << 0x8 | uint(c2da_mem[sock_4 + 46]) << 0x10 | uint(c2da_mem[sock_4 + 47]) << 0x18) != 0) {
        if (net_time - uint64_bits_to_double(uint64(uint(c2da_mem[sock_4 + 16]) | uint(c2da_mem[sock_4 + 17]) << 0x8 | uint(c2da_mem[sock_4 + 18]) << 0x10 | uint(c2da_mem[sock_4 + 19]) << 0x18) | uint64(uint(c2da_mem[sock_4 + 20]) | uint(c2da_mem[sock_4 + 21]) << 0x8 | uint(c2da_mem[sock_4 + 22]) << 0x10 | uint(c2da_mem[sock_4 + 23]) << 0x18) << 0x20) > double(uint_bits_to_float(uint(c2da_mem[386440]) | uint(c2da_mem[386441]) << 0x8 | uint(c2da_mem[386442]) << 0x10 | uint(c2da_mem[386443]) << 0x18))) {
            NET_Close(sock_4)
            return -1
        }
    }
    if (ret_1 > 0) {
        if (int(uint(c2da_mem[sock_4 + 44]) | uint(c2da_mem[sock_4 + 45]) << 0x8 | uint(c2da_mem[sock_4 + 46]) << 0x10 | uint(c2da_mem[sock_4 + 47]) << 0x18) != 0) {
            let c2da_fresh57 : uint64 = double_bits_to_uint64(net_time)
            c2da_mem[sock_4 + 16] = uint8(c2da_fresh57)
            c2da_mem[sock_4 + 17] = uint8(c2da_fresh57 >> 0x8)
            c2da_mem[sock_4 + 18] = uint8(c2da_fresh57 >> 0x10)
            c2da_mem[sock_4 + 19] = uint8(c2da_fresh57 >> 0x18)
            c2da_mem[sock_4 + 20] = uint8(c2da_fresh57 >> 0x20)
            c2da_mem[sock_4 + 21] = uint8(c2da_fresh57 >> 0x28)
            c2da_mem[sock_4 + 22] = uint8(c2da_fresh57 >> 0x30)
            c2da_mem[sock_4 + 23] = uint8(c2da_fresh57 >> 0x38)
            if (ret_1 == 1) {
                messagesReceived++
            } elif (ret_1 == 2) {
                unreliableMessagesReceived++
            }
        }
        if (recording != 0u) {
            let c2da_fresh58 : uint64 = double_bits_to_uint64(host_time)
            c2da_mem[387024] = uint8(c2da_fresh58)
            c2da_mem[387025] = uint8(c2da_fresh58 >> 0x8)
            c2da_mem[387026] = uint8(c2da_fresh58 >> 0x10)
            c2da_mem[387027] = uint8(c2da_fresh58 >> 0x18)
            c2da_mem[387028] = uint8(c2da_fresh58 >> 0x20)
            c2da_mem[387029] = uint8(c2da_fresh58 >> 0x28)
            c2da_mem[387030] = uint8(c2da_fresh58 >> 0x30)
            c2da_mem[387031] = uint8(c2da_fresh58 >> 0x38)
            let c2da_fresh59 : int = 2
            let c2da_fresh60 : uint = uint(c2da_fresh59)
            c2da_mem[387032] = uint8(c2da_fresh60)
            c2da_mem[387033] = uint8(c2da_fresh60 >> 0x8)
            c2da_mem[387034] = uint8(c2da_fresh60 >> 0x10)
            c2da_mem[387035] = uint8(c2da_fresh60 >> 0x18)
            let c2da_fresh61 : int64 = int64(sock_4)
            let c2da_fresh62 : uint64 = uint64(c2da_fresh61)
            c2da_mem[387040] = uint8(c2da_fresh62)
            c2da_mem[387041] = uint8(c2da_fresh62 >> 0x8)
            c2da_mem[387042] = uint8(c2da_fresh62 >> 0x10)
            c2da_mem[387043] = uint8(c2da_fresh62 >> 0x18)
            c2da_mem[387044] = uint8(c2da_fresh62 >> 0x20)
            c2da_mem[387045] = uint8(c2da_fresh62 >> 0x28)
            c2da_mem[387046] = uint8(c2da_fresh62 >> 0x30)
            c2da_mem[387047] = uint8(c2da_fresh62 >> 0x38)
            let c2da_fresh63 : uint = uint(ret_1)
            c2da_mem[387048] = uint8(c2da_fresh63)
            c2da_mem[387049] = uint8(c2da_fresh63 >> 0x8)
            c2da_mem[387050] = uint8(c2da_fresh63 >> 0x10)
            c2da_mem[387051] = uint8(c2da_fresh63 >> 0x18)
            let c2da_fresh64 : int = int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18)
            let c2da_fresh65 : uint = uint(c2da_fresh64)
            c2da_mem[387052] = uint8(c2da_fresh65)
            c2da_mem[387053] = uint8(c2da_fresh65 >> 0x8)
            c2da_mem[387054] = uint8(c2da_fresh65 >> 0x10)
            c2da_mem[387055] = uint8(c2da_fresh65 >> 0x18)
            Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), 387024, 24)
            Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18), int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18))
        }
    } elif (recording != 0u) {
        let c2da_fresh66 : uint64 = double_bits_to_uint64(host_time)
        c2da_mem[387024] = uint8(c2da_fresh66)
        c2da_mem[387025] = uint8(c2da_fresh66 >> 0x8)
        c2da_mem[387026] = uint8(c2da_fresh66 >> 0x10)
        c2da_mem[387027] = uint8(c2da_fresh66 >> 0x18)
        c2da_mem[387028] = uint8(c2da_fresh66 >> 0x20)
        c2da_mem[387029] = uint8(c2da_fresh66 >> 0x28)
        c2da_mem[387030] = uint8(c2da_fresh66 >> 0x30)
        c2da_mem[387031] = uint8(c2da_fresh66 >> 0x38)
        let c2da_fresh67 : int = 2
        let c2da_fresh68 : uint = uint(c2da_fresh67)
        c2da_mem[387032] = uint8(c2da_fresh68)
        c2da_mem[387033] = uint8(c2da_fresh68 >> 0x8)
        c2da_mem[387034] = uint8(c2da_fresh68 >> 0x10)
        c2da_mem[387035] = uint8(c2da_fresh68 >> 0x18)
        let c2da_fresh69 : int64 = int64(sock_4)
        let c2da_fresh70 : uint64 = uint64(c2da_fresh69)
        c2da_mem[387040] = uint8(c2da_fresh70)
        c2da_mem[387041] = uint8(c2da_fresh70 >> 0x8)
        c2da_mem[387042] = uint8(c2da_fresh70 >> 0x10)
        c2da_mem[387043] = uint8(c2da_fresh70 >> 0x18)
        c2da_mem[387044] = uint8(c2da_fresh70 >> 0x20)
        c2da_mem[387045] = uint8(c2da_fresh70 >> 0x28)
        c2da_mem[387046] = uint8(c2da_fresh70 >> 0x30)
        c2da_mem[387047] = uint8(c2da_fresh70 >> 0x38)
        let c2da_fresh71 : uint = uint(ret_1)
        c2da_mem[387048] = uint8(c2da_fresh71)
        c2da_mem[387049] = uint8(c2da_fresh71 >> 0x8)
        c2da_mem[387050] = uint8(c2da_fresh71 >> 0x10)
        c2da_mem[387051] = uint8(c2da_fresh71 >> 0x18)
        Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), 387024, 20)
    }
    return ret_1
}
[export, sideeffects]
def NET_SendMessage(var sock_5 : int; var data : int) : int {
    var r_0 : int
    if (sock_5 == 0) {
        return -1
    }
    if ((uint(c2da_mem[sock_5 + 32]) | uint(c2da_mem[sock_5 + 33]) << 0x8 | uint(c2da_mem[sock_5 + 34]) << 0x10 | uint(c2da_mem[sock_5 + 35]) << 0x18) != 0u) {
        Con_Printf(727956, [])
        return -1
    }
    SetNetTime()
    r_0 = invoke(c2da_fn_table10[net_drivers[int(uint(c2da_mem[sock_5 + 44]) | uint(c2da_mem[sock_5 + 45]) << 0x8 | uint(c2da_mem[sock_5 + 46]) << 0x10 | uint(c2da_mem[sock_5 + 47]) << 0x18)].QSendMessage], sock_5, data)
    if (r_0 == 1 && int(uint(c2da_mem[sock_5 + 44]) | uint(c2da_mem[sock_5 + 45]) << 0x8 | uint(c2da_mem[sock_5 + 46]) << 0x10 | uint(c2da_mem[sock_5 + 47]) << 0x18) != 0) {
        messagesSent++
    }
    if (recording != 0u) {
        let c2da_fresh72 : uint64 = double_bits_to_uint64(host_time)
        c2da_mem[386992] = uint8(c2da_fresh72)
        c2da_mem[386993] = uint8(c2da_fresh72 >> 0x8)
        c2da_mem[386994] = uint8(c2da_fresh72 >> 0x10)
        c2da_mem[386995] = uint8(c2da_fresh72 >> 0x18)
        c2da_mem[386996] = uint8(c2da_fresh72 >> 0x20)
        c2da_mem[386997] = uint8(c2da_fresh72 >> 0x28)
        c2da_mem[386998] = uint8(c2da_fresh72 >> 0x30)
        c2da_mem[386999] = uint8(c2da_fresh72 >> 0x38)
        let c2da_fresh73 : int = 3
        let c2da_fresh74 : uint = uint(c2da_fresh73)
        c2da_mem[387000] = uint8(c2da_fresh74)
        c2da_mem[387001] = uint8(c2da_fresh74 >> 0x8)
        c2da_mem[387002] = uint8(c2da_fresh74 >> 0x10)
        c2da_mem[387003] = uint8(c2da_fresh74 >> 0x18)
        let c2da_fresh75 : int64 = int64(sock_5)
        let c2da_fresh76 : uint64 = uint64(c2da_fresh75)
        c2da_mem[387008] = uint8(c2da_fresh76)
        c2da_mem[387009] = uint8(c2da_fresh76 >> 0x8)
        c2da_mem[387010] = uint8(c2da_fresh76 >> 0x10)
        c2da_mem[387011] = uint8(c2da_fresh76 >> 0x18)
        c2da_mem[387012] = uint8(c2da_fresh76 >> 0x20)
        c2da_mem[387013] = uint8(c2da_fresh76 >> 0x28)
        c2da_mem[387014] = uint8(c2da_fresh76 >> 0x30)
        c2da_mem[387015] = uint8(c2da_fresh76 >> 0x38)
        let c2da_fresh77 : uint = uint(r_0)
        c2da_mem[387016] = uint8(c2da_fresh77)
        c2da_mem[387017] = uint8(c2da_fresh77 >> 0x8)
        c2da_mem[387018] = uint8(c2da_fresh77 >> 0x10)
        c2da_mem[387019] = uint8(c2da_fresh77 >> 0x18)
        Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), 386992, 20)
    }
    return r_0
}
[export, sideeffects]
def NET_SendUnreliableMessage(var sock_6 : int; var data_0 : int) : int {
    var r_1 : int
    if (sock_6 == 0) {
        return -1
    }
    if ((uint(c2da_mem[sock_6 + 32]) | uint(c2da_mem[sock_6 + 33]) << 0x8 | uint(c2da_mem[sock_6 + 34]) << 0x10 | uint(c2da_mem[sock_6 + 35]) << 0x18) != 0u) {
        Con_Printf(727956, [])
        return -1
    }
    SetNetTime()
    r_1 = invoke(c2da_fn_table10[net_drivers[int(uint(c2da_mem[sock_6 + 44]) | uint(c2da_mem[sock_6 + 45]) << 0x8 | uint(c2da_mem[sock_6 + 46]) << 0x10 | uint(c2da_mem[sock_6 + 47]) << 0x18)].SendUnreliableMessage], sock_6, data_0)
    if (r_1 == 1 && int(uint(c2da_mem[sock_6 + 44]) | uint(c2da_mem[sock_6 + 45]) << 0x8 | uint(c2da_mem[sock_6 + 46]) << 0x10 | uint(c2da_mem[sock_6 + 47]) << 0x18) != 0) {
        unreliableMessagesSent++
    }
    if (recording != 0u) {
        let c2da_fresh78 : uint64 = double_bits_to_uint64(host_time)
        c2da_mem[386992] = uint8(c2da_fresh78)
        c2da_mem[386993] = uint8(c2da_fresh78 >> 0x8)
        c2da_mem[386994] = uint8(c2da_fresh78 >> 0x10)
        c2da_mem[386995] = uint8(c2da_fresh78 >> 0x18)
        c2da_mem[386996] = uint8(c2da_fresh78 >> 0x20)
        c2da_mem[386997] = uint8(c2da_fresh78 >> 0x28)
        c2da_mem[386998] = uint8(c2da_fresh78 >> 0x30)
        c2da_mem[386999] = uint8(c2da_fresh78 >> 0x38)
        let c2da_fresh79 : int = 3
        let c2da_fresh80 : uint = uint(c2da_fresh79)
        c2da_mem[387000] = uint8(c2da_fresh80)
        c2da_mem[387001] = uint8(c2da_fresh80 >> 0x8)
        c2da_mem[387002] = uint8(c2da_fresh80 >> 0x10)
        c2da_mem[387003] = uint8(c2da_fresh80 >> 0x18)
        let c2da_fresh81 : int64 = int64(sock_6)
        let c2da_fresh82 : uint64 = uint64(c2da_fresh81)
        c2da_mem[387008] = uint8(c2da_fresh82)
        c2da_mem[387009] = uint8(c2da_fresh82 >> 0x8)
        c2da_mem[387010] = uint8(c2da_fresh82 >> 0x10)
        c2da_mem[387011] = uint8(c2da_fresh82 >> 0x18)
        c2da_mem[387012] = uint8(c2da_fresh82 >> 0x20)
        c2da_mem[387013] = uint8(c2da_fresh82 >> 0x28)
        c2da_mem[387014] = uint8(c2da_fresh82 >> 0x30)
        c2da_mem[387015] = uint8(c2da_fresh82 >> 0x38)
        let c2da_fresh83 : uint = uint(r_1)
        c2da_mem[387016] = uint8(c2da_fresh83)
        c2da_mem[387017] = uint8(c2da_fresh83 >> 0x8)
        c2da_mem[387018] = uint8(c2da_fresh83 >> 0x10)
        c2da_mem[387019] = uint8(c2da_fresh83 >> 0x18)
        Sys_FileWrite(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), 386992, 20)
    }
    return r_1
}
[export, sideeffects]
def NET_SendToAll(var data_1 : int; var blocktime : int) : int {
    var start : double
    var i_0 : int
    var count : int
    var state1 : uint[16]
    var state2 : uint[16]
    count = 0
    i_0 = 0
    host_client = svs.clients
    while (i_0 < svs.maxclients) {
        if (int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18) == 0) {
            i_0++
            host_client = host_client + 8288
            continue
        }
        if ((uint(c2da_mem[host_client]) | uint(c2da_mem[host_client + 1]) << 0x8 | uint(c2da_mem[host_client + 2]) << 0x10 | uint(c2da_mem[host_client + 3]) << 0x18) != 0u) {
            let c2da_fresh85 : int = int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18)
            let c2da_fresh84 : int = c2da_fresh85 + 44
            if (int(uint(c2da_mem[c2da_fresh84]) | uint(c2da_mem[c2da_fresh84 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh84 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh84 + 3]) << 0x18) == 0) {
                NET_SendMessage(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18), data_1)
                state1[i_0] = 1u
                state2[i_0] = 1u
                i_0++
                host_client = host_client + 8288
                continue
            }
            count++
            state1[i_0] = 0u
            state2[i_0] = 0u
        } else {
            state1[i_0] = 1u
            state2[i_0] = 1u
        }
        i_0++
        host_client = host_client + 8288
    }
    start = Sys_FloatTime()
    while (count != 0) {
        count = 0
        i_0 = 0
        host_client = svs.clients
        while (i_0 < svs.maxclients) {
            if (state1[i_0] == 0u) {
                if (NET_CanSendMessage(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18)) != 0u) {
                    state1[i_0] = 1u
                    NET_SendMessage(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18), data_1)
                } else {
                    NET_GetMessage(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18))
                }
                count++
                i_0++
                host_client = host_client + 8288
                continue
            }
            if (state2[i_0] == 0u) {
                if (NET_CanSendMessage(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18)) != 0u) {
                    state2[i_0] = 1u
                } else {
                    NET_GetMessage(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18))
                }
                count++
                i_0++
                host_client = host_client + 8288
                continue
            }
            i_0++
            host_client = host_client + 8288
        }
        if (Sys_FloatTime() - start > double(blocktime)) {
            break
        }
    }
    return count
}
var ipxAvailable : uint = 0u

var tcpipAvailable : uint = 0u

var GetComPortConfig : int = default<int>

var GetModemConfig : int = default<int>


// This unit's static data, at heap offset 727024.
let private c2da_lin_static_net_main_seg = fixed_array<int>(727024, 969)
let private c2da_lin_static_net_main = fixed_array<uint64>(0x7373656d5f74656eul, 0x6f656d6974656761ul, 0x6800303033007475ul, 0x656d616e74736ful, 0x44454d414e4e55ul, 0x5f6769666e6f635ful, 0x74726f705f6d6f63ul, 0x5f00386633783000ul, 0x635f6769666e6f63ul, 0x34007172695f6d6ful, 0x6769666e6f635f00ul, 0x7561625f6d6f635ful, 0x30303637350064ul, 0x5f6769666e6f635ful, 0x65646f6d5f6d6f63ul, 0x6e6f635f0031006dul, 0x65646f6d5f676966ul, 0x79746c6169645f6dul, 0x6f635f0054006570ul, 0x646f6d5f6769666eul, 0x7261656c635f6d65ul, 0x6f635f005a544100ul, 0x646f6d5f6769666eul, 0x74696e695f6d65ul, 0x6769666e6f635f00ul, 0x685f6d65646f6d5ful, 0x5441007075676e61ul, 0x5445534e55004820ul, 0x5353455244444120ul, 0x6572465f54454e00ul, 0x74656b636f535165ul, 0x636120746f6e203aul, 0x702d000a65766974ul, 0x6b63616279616cul, 0x64726f6365722dul, 0x752d0074726f702dul, 0x2d0074726f707064ul, 0x74726f70787069ul, 0x74696e495f54454eul, 0x756d20756f79203aul, 0x6963657073207473ul, 0x6d756e2061207966ul, 0x6574666120726562ul, 0x74726f702d2072ul, 0x6e657473696c2dul, 0x74656b636f7371ul, 0x696c007473696c73ul, 0x78616d006e657473ul, 0x73726579616c70ul, 0x5850490074726f70ul, 0x7373657264646120ul, 0x504354000a732520ul, 0x726464612050492ful, 0xa732520737365ul, 0x69202274726f7022ul, 0xa227525222073ul, 0x756c617620646142ul, 0x207473756d202c65ul, 0x6577746562206562ul, 0x646e612031206e65ul, 0xa343335353620ul, 0x30206e657473696cul, 0x6e657473696c000aul, 0x78616d22000a3120ul, 0x2273726579616c70ul, 0x2275252220736920ul, 0x616c7078616d000aul, 0x6e61632073726579ul, 0x20656220746f6e20ul, 0x206465676e616863ul, 0x206120656c696877ul, 0x6920726576726573ul, 0x6e696e6e75722073ul, 0x78616d22000a2e67ul, 0x2273726579616c70ul, 0x206f742074657320ul, 0x6564000a22752522ul, 0x686374616d687461ul, 0x7473696c22003000ul, 0x2220736920226e65ul, 0x6f6f4c000a227525ul, 0x726f6620676e696bul, 0x7320656b61755120ul, 0x2e2e737265767265ul, 0x6e65203d3d000a2eul, 0x3d207473696c2064ul, 0x51206f4e000a0a3dul, 0x72657320656b6175ul, 0x756f662073726576ul, 0x2d25000a0a2e646eul, 0x25207335312e3531ul, 0x207335312e35312dul, 0xa7532252f753225ul, 0x35312e35312d2500ul, 0x312e35312d252073ul, 0x76726553000a7335ul, 0x2020202020207265ul, 0x2070614d20202020ul, 0x2020202020202020ul, 0x7265735520202020ul, 0x2d2d2d2d2d000a73ul, 0x2d2d2d2d2d2d2d2dul, 0x2d2d2d2d2d202d2dul, 0x2d2d2d2d2d2d2d2dul, 0x2d2d2d2d2d202d2dul, 0x6e69736f6c43000aul, 0x6c69667263762067ul, 0x61636f6c000a2e65ul, 0x63656e6e6f43006cul, 0x2e6f7420676e6974ul, 0x20402073250a2e2eul, 0x4e000a000a0a7325ul, 0x654d7465475f5445ul, 0x64203a6567617373ul, 0x63656e6e6f637369ul, 0x6b636f7320646574ul, 0x5f54454e000a7465ul, 0x7373654d646e6553ul, 0x736964203a656761ul, 0x657463656e6e6f63ul, 0x74656b636f732064ul, 0xaul)

[init]
def private c2da_lin_init_static_net_main() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_net_main_seg[s * 2]
        for (k in range(c2da_lin_static_net_main_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_net_main[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_net_main_0 = fixed_array<uint8>(0xf0, 0x17, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_net_main_1 = fixed_array<uint8>(0x7, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_net_main_2 = fixed_array<uint8>(0x18, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x29, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_net_main_3 = fixed_array<uint8>(0x2f, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_net_main_4 = fixed_array<uint8>(0x41, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x52, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_net_main_5 = fixed_array<uint8>(0x58, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6a, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_net_main_6 = fixed_array<uint8>(0x6c, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x83, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_net_main_7 = fixed_array<uint8>(0x85, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x99, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_net_main_8 = fixed_array<uint8>(0x9d, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb0, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_net_main_9 = fixed_array<uint8>(0xb1, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc6, 0x18, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_net_main_10 = fixed_array<uint8>(0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_net_main_11 = fixed_array<uint8>(0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_net_main_12 = fixed_array<uint8>(0xff, 0xff, 0xff, 0xff)

[init]
def private c2da_lin_init_externs_net_main() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[386416 + i] = c2da_lin_extern_net_main_0[i]
    }
    for (i in range(40)) {
        c2da_mem[386464 + i] = c2da_lin_extern_net_main_1[i]
    }
    for (i in range(40)) {
        c2da_mem[386512 + i] = c2da_lin_extern_net_main_2[i]
    }
    for (i in range(40)) {
        c2da_mem[386560 + i] = c2da_lin_extern_net_main_3[i]
    }
    for (i in range(40)) {
        c2da_mem[386608 + i] = c2da_lin_extern_net_main_4[i]
    }
    for (i in range(40)) {
        c2da_mem[386656 + i] = c2da_lin_extern_net_main_5[i]
    }
    for (i in range(40)) {
        c2da_mem[386704 + i] = c2da_lin_extern_net_main_6[i]
    }
    for (i in range(40)) {
        c2da_mem[386752 + i] = c2da_lin_extern_net_main_7[i]
    }
    for (i in range(40)) {
        c2da_mem[386800 + i] = c2da_lin_extern_net_main_8[i]
    }
    for (i in range(40)) {
        c2da_mem[386848 + i] = c2da_lin_extern_net_main_9[i]
    }
    for (i in range(32)) {
        c2da_mem[386896 + i] = c2da_lin_extern_net_main_10[i]
    }
    for (i in range(32)) {
        c2da_mem[386928 + i] = c2da_lin_extern_net_main_11[i]
    }
    for (i in range(4)) {
        c2da_mem[243872 + i] = c2da_lin_extern_net_main_12[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_net_main() {
    if (length(c2da_fn_table0) < 229) {
        resize(c2da_fn_table0, 229)
    }
    c2da_fn_table0[114] = @@NET_Slist_f
    c2da_fn_table0[224] = @@NET_Listen_f
    c2da_fn_table0[225] = @@MaxPlayers_f
    c2da_fn_table0[226] = @@NET_Port_f
    c2da_fn_table0[227] = @@Slist_Poll
    c2da_fn_table0[228] = @@Slist_Send
}

[init]
def private c2da_lin_relink_init_net_main() {
    c2da_relink_net_main()
}
