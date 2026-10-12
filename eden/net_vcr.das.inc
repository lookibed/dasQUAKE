[export, sideeffects]
def VCR_Init() : int {
    net_drivers[0].Init = 113
    net_drivers[0].SearchForHosts = 127
    net_drivers[0].Connect = 128
    net_drivers[0].CheckNewConnections = 129
    net_drivers[0].QGetMessage = 130
    net_drivers[0].QSendMessage = 131
    net_drivers[0].CanSendMessage = 132
    net_drivers[0].Close = 133
    net_drivers[0].Shutdown = 134
    Sys_FileRead(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), 728016, 24)
    return 0
}
[export, sideeffects]
def VCR_Shutdown() {
    return
}
[export, sideeffects]
def VCR_Close(var sock : int) {
    return
}
[export, sideeffects]
def VCR_CanSendMessage(var sock_0 : int) : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = VCR_CanSendMessage_c2da_frame(sock_0, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def VCR_ReadNext() {
    if (Sys_FileRead(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), 728016, 24) == 0) {
        let c2da_fresh0 : int = 255
        let c2da_fresh1 : uint = uint(c2da_fresh0)
        c2da_mem[728024] = uint8(c2da_fresh1)
        c2da_mem[728025] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[728026] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[728027] = uint8(c2da_fresh1 >> 0x18)
        Sys_Error(728054, [])
    }
    if (int(uint(c2da_mem[728024]) | uint(c2da_mem[728025]) << 0x8 | uint(c2da_mem[728026]) << 0x10 | uint(c2da_mem[728027]) << 0x18) < 1 || int(uint(c2da_mem[728024]) | uint(c2da_mem[728025]) << 0x8 | uint(c2da_mem[728026]) << 0x10 | uint(c2da_mem[728027]) << 0x18) > 4) {
        Sys_Error(728078, [])
    }
    return
}
[export, sideeffects]
def VCR_SendMessage(var sock_1 : int; var data : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = VCR_SendMessage_c2da_frame(sock_1, data, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def VCR_GetMessage(var sock_2 : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = VCR_GetMessage_c2da_frame(sock_2, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def VCR_CheckNewConnections() : int {
    var sock_3 : int
    if (host_time != uint64_bits_to_double(uint64(uint(c2da_mem[728016]) | uint(c2da_mem[728017]) << 0x8 | uint(c2da_mem[728018]) << 0x10 | uint(c2da_mem[728019]) << 0x18) | uint64(uint(c2da_mem[728020]) | uint(c2da_mem[728021]) << 0x8 | uint(c2da_mem[728022]) << 0x10 | uint(c2da_mem[728023]) << 0x18) << 0x20) || int(uint(c2da_mem[728024]) | uint(c2da_mem[728025]) << 0x8 | uint(c2da_mem[728026]) << 0x10 | uint(c2da_mem[728027]) << 0x18) != 1) {
        Sys_Error(728040, [])
    }
    if (int64(uint64(uint(c2da_mem[728032]) | uint(c2da_mem[728033]) << 0x8 | uint(c2da_mem[728034]) << 0x10 | uint(c2da_mem[728035]) << 0x18) | uint64(uint(c2da_mem[728036]) | uint(c2da_mem[728037]) << 0x8 | uint(c2da_mem[728038]) << 0x10 | uint(c2da_mem[728039]) << 0x18) << 0x20) == 0) {
        VCR_ReadNext()
        return 0
    }
    sock_3 = NET_NewQSocket()
    let c2da_fresh2 : int64 = int64(uint64(uint(c2da_mem[728032]) | uint(c2da_mem[728033]) << 0x8 | uint(c2da_mem[728034]) << 0x10 | uint(c2da_mem[728035]) << 0x18) | uint64(uint(c2da_mem[728036]) | uint(c2da_mem[728037]) << 0x8 | uint(c2da_mem[728038]) << 0x10 | uint(c2da_mem[728039]) << 0x18) << 0x20)
    let c2da_fresh3 : uint64 = uint64(c2da_fresh2)
    c2da_mem[sock_3 + 56] = uint8(c2da_fresh3)
    c2da_mem[sock_3 + 57] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[sock_3 + 58] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[sock_3 + 59] = uint8(c2da_fresh3 >> 0x18)
    c2da_mem[sock_3 + 60] = uint8(c2da_fresh3 >> 0x20)
    c2da_mem[sock_3 + 61] = uint8(c2da_fresh3 >> 0x28)
    c2da_mem[sock_3 + 62] = uint8(c2da_fresh3 >> 0x30)
    c2da_mem[sock_3 + 63] = uint8(c2da_fresh3 >> 0x38)
    Sys_FileRead(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), sock_3 + 16492, 64)
    VCR_ReadNext()
    return sock_3
}
[export, sideeffects]
def VCR_Connect(var host : int) : int {
    return 0
}
[export, sideeffects]
def VCR_SearchForHosts(var xmit : uint) {
    return
}
[export, sideeffects]
def VCR_Listen(var state : uint) {
    return
}
[sideeffects]
def private VCR_CanSendMessage_c2da_frame(var sock_0 : int; c2da_fp : int) : uint {
    if (host_time != uint64_bits_to_double(uint64(uint(c2da_mem[728016]) | uint(c2da_mem[728017]) << 0x8 | uint(c2da_mem[728018]) << 0x10 | uint(c2da_mem[728019]) << 0x18) | uint64(uint(c2da_mem[728020]) | uint(c2da_mem[728021]) << 0x8 | uint(c2da_mem[728022]) << 0x10 | uint(c2da_mem[728023]) << 0x18) << 0x20) || int(uint(c2da_mem[728024]) | uint(c2da_mem[728025]) << 0x8 | uint(c2da_mem[728026]) << 0x10 | uint(c2da_mem[728027]) << 0x18) != 4 || int64(uint64(uint(c2da_mem[728032]) | uint(c2da_mem[728033]) << 0x8 | uint(c2da_mem[728034]) << 0x10 | uint(c2da_mem[728035]) << 0x18) | uint64(uint(c2da_mem[728036]) | uint(c2da_mem[728037]) << 0x8 | uint(c2da_mem[728038]) << 0x10 | uint(c2da_mem[728039]) << 0x18) << 0x20) != int64(uint64(uint(c2da_mem[sock_0 + 56]) | uint(c2da_mem[sock_0 + 57]) << 0x8 | uint(c2da_mem[sock_0 + 58]) << 0x10 | uint(c2da_mem[sock_0 + 59]) << 0x18) | uint64(uint(c2da_mem[sock_0 + 60]) | uint(c2da_mem[sock_0 + 61]) << 0x8 | uint(c2da_mem[sock_0 + 62]) << 0x10 | uint(c2da_mem[sock_0 + 63]) << 0x18) << 0x20)) {
        Sys_Error(728040, [])
    }
    Sys_FileRead(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), c2da_fp, 4)
    VCR_ReadNext()
    return uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18
}
[sideeffects]
def private VCR_SendMessage_c2da_frame(var sock_1 : int; var data : int; c2da_fp : int) : int {
    if (host_time != uint64_bits_to_double(uint64(uint(c2da_mem[728016]) | uint(c2da_mem[728017]) << 0x8 | uint(c2da_mem[728018]) << 0x10 | uint(c2da_mem[728019]) << 0x18) | uint64(uint(c2da_mem[728020]) | uint(c2da_mem[728021]) << 0x8 | uint(c2da_mem[728022]) << 0x10 | uint(c2da_mem[728023]) << 0x18) << 0x20) || int(uint(c2da_mem[728024]) | uint(c2da_mem[728025]) << 0x8 | uint(c2da_mem[728026]) << 0x10 | uint(c2da_mem[728027]) << 0x18) != 3 || int64(uint64(uint(c2da_mem[728032]) | uint(c2da_mem[728033]) << 0x8 | uint(c2da_mem[728034]) << 0x10 | uint(c2da_mem[728035]) << 0x18) | uint64(uint(c2da_mem[728036]) | uint(c2da_mem[728037]) << 0x8 | uint(c2da_mem[728038]) << 0x10 | uint(c2da_mem[728039]) << 0x18) << 0x20) != int64(uint64(uint(c2da_mem[sock_1 + 56]) | uint(c2da_mem[sock_1 + 57]) << 0x8 | uint(c2da_mem[sock_1 + 58]) << 0x10 | uint(c2da_mem[sock_1 + 59]) << 0x18) | uint64(uint(c2da_mem[sock_1 + 60]) | uint(c2da_mem[sock_1 + 61]) << 0x8 | uint(c2da_mem[sock_1 + 62]) << 0x10 | uint(c2da_mem[sock_1 + 63]) << 0x18) << 0x20)) {
        Sys_Error(728040, [])
    }
    Sys_FileRead(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), c2da_fp, 4)
    VCR_ReadNext()
    return int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18)
}
[sideeffects]
def private VCR_GetMessage_c2da_frame(var sock_2 : int; c2da_fp : int) : int {
    if (host_time != uint64_bits_to_double(uint64(uint(c2da_mem[728016]) | uint(c2da_mem[728017]) << 0x8 | uint(c2da_mem[728018]) << 0x10 | uint(c2da_mem[728019]) << 0x18) | uint64(uint(c2da_mem[728020]) | uint(c2da_mem[728021]) << 0x8 | uint(c2da_mem[728022]) << 0x10 | uint(c2da_mem[728023]) << 0x18) << 0x20) || int(uint(c2da_mem[728024]) | uint(c2da_mem[728025]) << 0x8 | uint(c2da_mem[728026]) << 0x10 | uint(c2da_mem[728027]) << 0x18) != 2 || int64(uint64(uint(c2da_mem[728032]) | uint(c2da_mem[728033]) << 0x8 | uint(c2da_mem[728034]) << 0x10 | uint(c2da_mem[728035]) << 0x18) | uint64(uint(c2da_mem[728036]) | uint(c2da_mem[728037]) << 0x8 | uint(c2da_mem[728038]) << 0x10 | uint(c2da_mem[728039]) << 0x18) << 0x20) != int64(uint64(uint(c2da_mem[sock_2 + 56]) | uint(c2da_mem[sock_2 + 57]) << 0x8 | uint(c2da_mem[sock_2 + 58]) << 0x10 | uint(c2da_mem[sock_2 + 59]) << 0x18) | uint64(uint(c2da_mem[sock_2 + 60]) | uint(c2da_mem[sock_2 + 61]) << 0x8 | uint(c2da_mem[sock_2 + 62]) << 0x10 | uint(c2da_mem[sock_2 + 63]) << 0x18) << 0x20)) {
        Sys_Error(728040, [])
    }
    Sys_FileRead(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), c2da_fp, 4)
    if (int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) != 1) {
        VCR_ReadNext()
        return int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18)
    }
    Sys_FileRead(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), 5380, 4)
    Sys_FileRead(int(uint(c2da_mem[243872]) | uint(c2da_mem[243873]) << 0x8 | uint(c2da_mem[243874]) << 0x10 | uint(c2da_mem[243875]) << 0x18), int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18), int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18))
    VCR_ReadNext()
    return 1
}

// This unit's static data, at heap offset 728016.
let private c2da_lin_static_net_vcr_seg = fixed_array<int>(728040, 58)
let private c2da_lin_static_net_vcr = fixed_array<uint64>(0x7373696d20524356ul, 0x3d3d00686374616dul, 0x464f20444e45203dul, 0x43414259414c5020ul, 0x4356000a3d3d3d4bul, 0x654e646165525f52ul, 0x20646162203a7478ul, 0x706ful)

[init]
def private c2da_lin_init_static_net_vcr() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_net_vcr_seg[s * 2]
        for (k in range(c2da_lin_static_net_vcr_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_net_vcr[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_net_vcr() {
    if (length(c2da_fn_table0) < 135) {
        resize(c2da_fn_table0, 135)
    }
    c2da_fn_table0[134] = @@VCR_Shutdown
    if (length(c2da_fn_table2) < 135) {
        resize(c2da_fn_table2, 135)
    }
    c2da_fn_table2[130] = @@VCR_GetMessage
    c2da_fn_table2[128] = @@VCR_Connect
    if (length(c2da_fn_table5) < 135) {
        resize(c2da_fn_table5, 135)
    }
    c2da_fn_table5[133] = @@VCR_Close
    if (length(c2da_fn_table8) < 135) {
        resize(c2da_fn_table8, 135)
    }
    c2da_fn_table8[113] = @@VCR_Init
    c2da_fn_table8[129] = @@VCR_CheckNewConnections
    if (length(c2da_fn_table9) < 135) {
        resize(c2da_fn_table9, 135)
    }
    c2da_fn_table9[127] = @@VCR_SearchForHosts
    if (length(c2da_fn_table10) < 135) {
        resize(c2da_fn_table10, 135)
    }
    c2da_fn_table10[131] = @@VCR_SendMessage
    if (length(c2da_fn_table11) < 135) {
        resize(c2da_fn_table11, 135)
    }
    c2da_fn_table11[132] = @@VCR_CanSendMessage
}

[init]
def private c2da_lin_relink_init_net_vcr() {
    c2da_relink_net_vcr()
}
