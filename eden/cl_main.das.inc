[export, sideeffects]
def CL_AllocDlight(var key : int) : int {
    var i : int
    var dl : int
    if (key != 0) {
        dl = 8112
        i = 0
        while (i < 32) {
            if (int(uint(c2da_mem[dl + 28]) | uint(c2da_mem[dl + 29]) << 0x8 | uint(c2da_mem[dl + 30]) << 0x10 | uint(c2da_mem[dl + 31]) << 0x18) == key) {
                c2da_lin_memset(dl, 0, 32ul)
                let c2da_fresh0 : uint = uint(key)
                c2da_mem[dl + 28] = uint8(c2da_fresh0)
                c2da_mem[dl + 29] = uint8(c2da_fresh0 >> 0x8)
                c2da_mem[dl + 30] = uint8(c2da_fresh0 >> 0x10)
                c2da_mem[dl + 31] = uint8(c2da_fresh0 >> 0x18)
                return dl
            }
            i++
            dl += 32
        }
    }
    dl = 8112
    i = 0
    while (i < 32) {
        if (double(uint_bits_to_float(uint(c2da_mem[dl + 16]) | uint(c2da_mem[dl + 17]) << 0x8 | uint(c2da_mem[dl + 18]) << 0x10 | uint(c2da_mem[dl + 19]) << 0x18)) < uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20)) {
            c2da_lin_memset(dl, 0, 32ul)
            let c2da_fresh1 : uint = uint(key)
            c2da_mem[dl + 28] = uint8(c2da_fresh1)
            c2da_mem[dl + 29] = uint8(c2da_fresh1 >> 0x8)
            c2da_mem[dl + 30] = uint8(c2da_fresh1 >> 0x10)
            c2da_mem[dl + 31] = uint8(c2da_fresh1 >> 0x18)
            return dl
        }
        i++
        dl += 32
    }
    dl = 8112 + 0 * 32
    c2da_lin_memset(dl, 0, 32ul)
    let c2da_fresh2 : uint = uint(key)
    c2da_mem[dl + 28] = uint8(c2da_fresh2)
    c2da_mem[dl + 29] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[dl + 30] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[dl + 31] = uint8(c2da_fresh2 >> 0x18)
    return dl
}
[export, sideeffects]
def CL_DecayLights() {
    var i_0 : int
    var dl_0 : int
    var time : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - uint64_bits_to_double(uint64(uint(c2da_mem[792]) | uint(c2da_mem[793]) << 0x8 | uint(c2da_mem[794]) << 0x10 | uint(c2da_mem[795]) << 0x18) | uint64(uint(c2da_mem[796]) | uint(c2da_mem[797]) << 0x8 | uint(c2da_mem[798]) << 0x10 | uint(c2da_mem[799]) << 0x18) << 0x20))
    dl_0 = 8112
    i_0 = 0
    while (i_0 < 32) {
        if (double(uint_bits_to_float(uint(c2da_mem[dl_0 + 16]) | uint(c2da_mem[dl_0 + 17]) << 0x8 | uint(c2da_mem[dl_0 + 18]) << 0x10 | uint(c2da_mem[dl_0 + 19]) << 0x18)) < uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) || uint_bits_to_float(uint(c2da_mem[dl_0 + 12]) | uint(c2da_mem[dl_0 + 13]) << 0x8 | uint(c2da_mem[dl_0 + 14]) << 0x10 | uint(c2da_mem[dl_0 + 15]) << 0x18) == 0.0) {
            i_0++
            dl_0 += 32
            continue
        }
        let c2da_fresh3 : float = uint_bits_to_float(uint(c2da_mem[dl_0 + 12]) | uint(c2da_mem[dl_0 + 13]) << 0x8 | uint(c2da_mem[dl_0 + 14]) << 0x10 | uint(c2da_mem[dl_0 + 15]) << 0x18) - float(time * uint_bits_to_float(uint(c2da_mem[dl_0 + 20]) | uint(c2da_mem[dl_0 + 21]) << 0x8 | uint(c2da_mem[dl_0 + 22]) << 0x10 | uint(c2da_mem[dl_0 + 23]) << 0x18))
        let c2da_fresh4 : uint = float_bits_to_uint(c2da_fresh3)
        c2da_mem[dl_0 + 12] = uint8(c2da_fresh4)
        c2da_mem[dl_0 + 13] = uint8(c2da_fresh4 >> 0x8)
        c2da_mem[dl_0 + 14] = uint8(c2da_fresh4 >> 0x10)
        c2da_mem[dl_0 + 15] = uint8(c2da_fresh4 >> 0x18)
        if (uint_bits_to_float(uint(c2da_mem[dl_0 + 12]) | uint(c2da_mem[dl_0 + 13]) << 0x8 | uint(c2da_mem[dl_0 + 14]) << 0x10 | uint(c2da_mem[dl_0 + 15]) << 0x18) < 0.0) {
            let c2da_fresh5 : float = 0.0
            let c2da_fresh6 : uint = float_bits_to_uint(c2da_fresh5)
            c2da_mem[dl_0 + 12] = uint8(c2da_fresh6)
            c2da_mem[dl_0 + 13] = uint8(c2da_fresh6 >> 0x8)
            c2da_mem[dl_0 + 14] = uint8(c2da_fresh6 >> 0x10)
            c2da_mem[dl_0 + 15] = uint8(c2da_fresh6 >> 0x18)
        }
        i_0++
        dl_0 += 32
    }
    return
}
[export, sideeffects]
def CL_Init() {
    SZ_Alloc(7816, 1024)
    CL_InitInput()
    CL_InitTEnts()
    Cvar_RegisterVariable(9136)
    Cvar_RegisterVariable(9184)
    Cvar_RegisterVariable(9232)
    Cvar_RegisterVariable(9280)
    Cvar_RegisterVariable(9328)
    Cvar_RegisterVariable(9376)
    Cvar_RegisterVariable(9424)
    Cvar_RegisterVariable(9472)
    Cvar_RegisterVariable(9520)
    Cvar_RegisterVariable(9568)
    Cvar_RegisterVariable(9616)
    Cvar_RegisterVariable(9664)
    Cvar_RegisterVariable(9712)
    Cvar_RegisterVariable(9760)
    Cvar_RegisterVariable(9808)
    Cvar_RegisterVariable(9856)
    Cvar_RegisterVariable(9904)
    Cvar_RegisterVariable(9952)
    Cvar_RegisterVariable(10000)
    Cmd_AddCommand(698336, 36)
    Cmd_AddCommand(698345, 37)
    Cmd_AddCommand(698356, 38)
    Cmd_AddCommand(698363, 39)
    Cmd_AddCommand(698368, 40)
    Cmd_AddCommand(698377, 41)
    return
}
[export, sideeffects]
def CL_Disconnect_f() {
    CL_Disconnect()
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) != 0u) {
        Host_ShutdownServer(0u)
    }
    return
}
[export, sideeffects]
def CL_Disconnect() {
    S_StopAllSounds(1u)
    if ((uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) != 0u) {
        CL_StopPlayback()
    } elif ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 2u) {
        if ((uint(c2da_mem[7768]) | uint(c2da_mem[7769]) << 0x8 | uint(c2da_mem[7770]) << 0x10 | uint(c2da_mem[7771]) << 0x18) != 0u) {
            CL_Stop_f()
        }
        Con_DPrintf(698386, [])
        SZ_Clear(7816)
        MSG_WriteByte(7816, 2)
        NET_SendUnreliableMessage(int(uint(c2da_mem[7808]) | uint(c2da_mem[7809]) << 0x8 | uint(c2da_mem[7810]) << 0x10 | uint(c2da_mem[7811]) << 0x18), 7816)
        SZ_Clear(7816)
        NET_Close(int(uint(c2da_mem[7808]) | uint(c2da_mem[7809]) << 0x8 | uint(c2da_mem[7810]) << 0x10 | uint(c2da_mem[7811]) << 0x18))
        let c2da_fresh7 : uint = 1u
        let c2da_fresh8 : uint = c2da_fresh7
        c2da_mem[5520] = uint8(c2da_fresh8)
        c2da_mem[5521] = uint8(c2da_fresh8 >> 0x8)
        c2da_mem[5522] = uint8(c2da_fresh8 >> 0x10)
        c2da_mem[5523] = uint8(c2da_fresh8 >> 0x18)
        if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) != 0u) {
            Host_ShutdownServer(0u)
        }
    }
    let c2da_fresh9 : uint = 0u
    let c2da_fresh10 : uint = c2da_fresh9
    c2da_mem[7776] = uint8(c2da_fresh10)
    c2da_mem[7777] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[7778] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[7779] = uint8(c2da_fresh10 >> 0x18)
    let c2da_fresh11 : uint = c2da_fresh9
    c2da_mem[7772] = uint8(c2da_fresh11)
    c2da_mem[7773] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[7774] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[7775] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : int = 0
    let c2da_fresh13 : uint = uint(c2da_fresh12)
    c2da_mem[7804] = uint8(c2da_fresh13)
    c2da_mem[7805] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[7806] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[7807] = uint8(c2da_fresh13 >> 0x18)
    return
}
[export, sideeffects]
def CL_PrintEntities_f() {
    var ent : int
    var i_1 : int = 0
    ent = 10048
    while (i_1 < int(uint(c2da_mem[4976]) | uint(c2da_mem[4977]) << 0x8 | uint(c2da_mem[4978]) << 0x10 | uint(c2da_mem[4979]) << 0x18)) {
        Con_Printf(698410, [C2daVaArg(tag = 1, i64 = int64(i_1), f64 = 0.0lf, raw = 0x0)])
        if (int(uint(c2da_mem[ent + 136]) | uint(c2da_mem[ent + 137]) << 0x8 | uint(c2da_mem[ent + 138]) << 0x10 | uint(c2da_mem[ent + 139]) << 0x18) == 0) {
            Con_Printf(698415, [])
            i_1++
            ent += 200
            continue
        }
        Con_Printf(698422, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[ent + 136]) | uint(c2da_mem[ent + 137]) << 0x8 | uint(c2da_mem[ent + 138]) << 0x10 | uint(c2da_mem[ent + 139]) << 0x18))), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[ent + 152]) | uint(c2da_mem[ent + 153]) << 0x8 | uint(c2da_mem[ent + 154]) << 0x10 | uint(c2da_mem[ent + 155]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[ent + 88 + 0 * 4]) | uint(c2da_mem[ent + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 0 * 4 + 3]) << 0x18)), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[ent + 88 + 1 * 4]) | uint(c2da_mem[ent + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 1 * 4 + 3]) << 0x18)), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[ent + 88 + 2 * 4]) | uint(c2da_mem[ent + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 2 * 4 + 3]) << 0x18)), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[ent + 124 + 0 * 4]) | uint(c2da_mem[ent + 124 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 124 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 124 + 0 * 4 + 3]) << 0x18)), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[ent + 124 + 1 * 4]) | uint(c2da_mem[ent + 124 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 124 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 124 + 1 * 4 + 3]) << 0x18)), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[ent + 124 + 2 * 4]) | uint(c2da_mem[ent + 124 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 124 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 124 + 2 * 4 + 3]) << 0x18)), raw = 0x0)])
        i_1++
        ent += 200
    }
    return
}
[export, sideeffects]
def CL_EstablishConnection(var host : int) {
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 0u) {
        return
    }
    if ((uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) != 0u) {
        return
    }
    CL_Disconnect()
    let c2da_fresh14 : int = NET_Connect(host)
    let c2da_fresh15 : uint = uint(c2da_fresh14)
    c2da_mem[7808] = uint8(c2da_fresh15)
    c2da_mem[7809] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[7810] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[7811] = uint8(c2da_fresh15 >> 0x18)
    c2da_mem[7812] = 0u8
    c2da_mem[7813] = 0u8
    c2da_mem[7814] = 0u8
    c2da_mem[7815] = 0u8
    if (int(uint(c2da_mem[7808]) | uint(c2da_mem[7809]) << 0x8 | uint(c2da_mem[7810]) << 0x10 | uint(c2da_mem[7811]) << 0x18) == 0) {
        Host_Error(698471, [])
    }
    Con_DPrintf(698499, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(host))])
    let c2da_fresh16 : int = -1
    let c2da_fresh17 : uint = uint(c2da_fresh16)
    c2da_mem[7636] = uint8(c2da_fresh17)
    c2da_mem[7637] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[7638] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[7639] = uint8(c2da_fresh17 >> 0x18)
    let c2da_fresh18 : uint = 2u
    let c2da_fresh19 : uint = c2da_fresh18
    c2da_mem[5520] = uint8(c2da_fresh19)
    c2da_mem[5521] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[5522] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[5523] = uint8(c2da_fresh19 >> 0x18)
    let c2da_fresh20 : int = 0
    let c2da_fresh21 : uint = uint(c2da_fresh20)
    c2da_mem[7804] = uint8(c2da_fresh21)
    c2da_mem[7805] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[7806] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[7807] = uint8(c2da_fresh21 >> 0x18)
    return
}
[export, sideeffects]
def CL_NextDemo() {
    let c2da_saved_sp : int = c2da_lin_sp
    CL_NextDemo_c2da_frame(c2da_lin_enter(1024))
    c2da_lin_sp = c2da_saved_sp
}
var cl_numvisedicts : int = default<int>

var cl_visedicts : int[256]

[export, sideeffects]
def CL_SendCmd() {
    let c2da_saved_sp : int = c2da_lin_sp
    CL_SendCmd_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def CL_ClearState() {
    var i_2 : int
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u) {
        Host_ClearMemory()
    }
    c2da_lin_memset(208, 0, 4992ul)
    SZ_Clear(7816)
    c2da_lin_memset(130048, 0, 20480ul)
    c2da_lin_memset(10048, 0, 120000ul)
    c2da_lin_memset(8112, 0, 1024ul)
    c2da_lin_memset(150528, 0, 4352ul)
    c2da_lin_memset(154880, 0, 12800ul)
    c2da_lin_memset(167680, 0, 1152ul)
    let c2da_fresh31 : uint = 130048u
    c2da_mem[4968] = uint8(c2da_fresh31)
    c2da_mem[4969] = uint8(c2da_fresh31 >> 0x8)
    c2da_mem[4970] = uint8(c2da_fresh31 >> 0x10)
    c2da_mem[4971] = uint8(c2da_fresh31 >> 0x18)
    c2da_mem[4972] = 0u8
    c2da_mem[4973] = 0u8
    c2da_mem[4974] = 0u8
    c2da_mem[4975] = 0u8
    i_2 = 0
    while (i_2 < 640 - 1) {
        let c2da_fresh32 : int = int(uint(c2da_mem[4968]) | uint(c2da_mem[4969]) << 0x8 | uint(c2da_mem[4970]) << 0x10 | uint(c2da_mem[4971]) << 0x18) + i_2 * 32 + 24
        let c2da_fresh33 : int = int(uint(c2da_mem[4968]) | uint(c2da_mem[4969]) << 0x8 | uint(c2da_mem[4970]) << 0x10 | uint(c2da_mem[4971]) << 0x18) + (i_2 + 1) * 32
        let c2da_fresh34 : uint = uint(c2da_fresh33)
        c2da_mem[c2da_fresh32] = uint8(c2da_fresh34)
        c2da_mem[c2da_fresh32 + 1] = uint8(c2da_fresh34 >> 0x8)
        c2da_mem[c2da_fresh32 + 2] = uint8(c2da_fresh34 >> 0x10)
        c2da_mem[c2da_fresh32 + 3] = uint8(c2da_fresh34 >> 0x18)
        c2da_mem[c2da_fresh32 + 4] = 0u8
        c2da_mem[c2da_fresh32 + 5] = 0u8
        c2da_mem[c2da_fresh32 + 6] = 0u8
        c2da_mem[c2da_fresh32 + 7] = 0u8
        i_2++
    }
    let c2da_fresh35 : int = int(uint(c2da_mem[4968]) | uint(c2da_mem[4969]) << 0x8 | uint(c2da_mem[4970]) << 0x10 | uint(c2da_mem[4971]) << 0x18) + i_2 * 32 + 24
    let c2da_fresh36 : uint = 0u
    c2da_mem[c2da_fresh35] = uint8(c2da_fresh36)
    c2da_mem[c2da_fresh35 + 1] = uint8(c2da_fresh36 >> 0x8)
    c2da_mem[c2da_fresh35 + 2] = uint8(c2da_fresh36 >> 0x10)
    c2da_mem[c2da_fresh35 + 3] = uint8(c2da_fresh36 >> 0x18)
    c2da_mem[c2da_fresh35 + 4] = 0u8
    c2da_mem[c2da_fresh35 + 5] = 0u8
    c2da_mem[c2da_fresh35 + 6] = 0u8
    c2da_mem[c2da_fresh35 + 7] = 0u8
    return
}
[export, sideeffects]
def CL_ReadFromServer() : int {
    var ret : int
    let c2da_fresh37 : double = uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20)
    let c2da_fresh38 : uint64 = double_bits_to_uint64(c2da_fresh37)
    c2da_mem[792] = uint8(c2da_fresh38)
    c2da_mem[793] = uint8(c2da_fresh38 >> 0x8)
    c2da_mem[794] = uint8(c2da_fresh38 >> 0x10)
    c2da_mem[795] = uint8(c2da_fresh38 >> 0x18)
    c2da_mem[796] = uint8(c2da_fresh38 >> 0x20)
    c2da_mem[797] = uint8(c2da_fresh38 >> 0x28)
    c2da_mem[798] = uint8(c2da_fresh38 >> 0x30)
    c2da_mem[799] = uint8(c2da_fresh38 >> 0x38)
    let c2da_fresh39 : double = uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + double(host_frametime)
    let c2da_fresh40 : uint64 = double_bits_to_uint64(c2da_fresh39)
    c2da_mem[784] = uint8(c2da_fresh40)
    c2da_mem[785] = uint8(c2da_fresh40 >> 0x8)
    c2da_mem[786] = uint8(c2da_fresh40 >> 0x10)
    c2da_mem[787] = uint8(c2da_fresh40 >> 0x18)
    c2da_mem[788] = uint8(c2da_fresh40 >> 0x20)
    c2da_mem[789] = uint8(c2da_fresh40 >> 0x28)
    c2da_mem[790] = uint8(c2da_fresh40 >> 0x30)
    c2da_mem[791] = uint8(c2da_fresh40 >> 0x38)
    while (true) {
        ret = CL_GetMessage()
        if (ret == -1) {
            Host_Error(698657, [])
        }
        if (ret == 0) {
            break
        }
        let c2da_fresh41 : float = float(realtime)
        let c2da_fresh42 : uint = float_bits_to_uint(c2da_fresh41)
        c2da_mem[800] = uint8(c2da_fresh42)
        c2da_mem[801] = uint8(c2da_fresh42 >> 0x8)
        c2da_mem[802] = uint8(c2da_fresh42 >> 0x10)
        c2da_mem[803] = uint8(c2da_fresh42 >> 0x18)
        CL_ParseServerMessage()
        if (!(ret != 0 && (uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 2u)) {
            break
        }
    }
    if (uint_bits_to_float(uint(c2da_mem[9640]) | uint(c2da_mem[9641]) << 0x8 | uint(c2da_mem[9642]) << 0x10 | uint(c2da_mem[9643]) << 0x18) != 0.0) {
        Con_Printf(698699, [])
    }
    CL_RelinkEntities()
    CL_UpdateTEnts()
    return 0
}
[export, sideeffects]
def CL_RelinkEntities() {
    let c2da_saved_sp : int = c2da_lin_sp
    CL_RelinkEntities_c2da_frame(c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def CL_LerpPoint() : float {
    var f_0 : float
    var frac_0 : float
    f_0 = float(uint64_bits_to_double(uint64(uint(c2da_mem[768 + 0 * 8]) | uint(c2da_mem[768 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 3]) << 0x18) | uint64(uint(c2da_mem[768 + 0 * 8 + 4]) | uint(c2da_mem[768 + 0 * 8 + 5]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 6]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 7]) << 0x18) << 0x20) - uint64_bits_to_double(uint64(uint(c2da_mem[768 + 1 * 8]) | uint(c2da_mem[768 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[768 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[768 + 1 * 8 + 3]) << 0x18) | uint64(uint(c2da_mem[768 + 1 * 8 + 4]) | uint(c2da_mem[768 + 1 * 8 + 5]) << 0x8 | uint(c2da_mem[768 + 1 * 8 + 6]) << 0x10 | uint(c2da_mem[768 + 1 * 8 + 7]) << 0x18) << 0x20))
    if (f_0 == 0.0 || uint_bits_to_float(uint(c2da_mem[9688]) | uint(c2da_mem[9689]) << 0x8 | uint(c2da_mem[9690]) << 0x10 | uint(c2da_mem[9691]) << 0x18) != 0.0 || (uint(c2da_mem[7776]) | uint(c2da_mem[7777]) << 0x8 | uint(c2da_mem[7778]) << 0x10 | uint(c2da_mem[7779]) << 0x18) != 0x0 || (uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) != 0x0) {
        let c2da_fresh127 : double = uint64_bits_to_double(uint64(uint(c2da_mem[768 + 0 * 8]) | uint(c2da_mem[768 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 3]) << 0x18) | uint64(uint(c2da_mem[768 + 0 * 8 + 4]) | uint(c2da_mem[768 + 0 * 8 + 5]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 6]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 7]) << 0x18) << 0x20)
        let c2da_fresh128 : uint64 = double_bits_to_uint64(c2da_fresh127)
        c2da_mem[784] = uint8(c2da_fresh128)
        c2da_mem[785] = uint8(c2da_fresh128 >> 0x8)
        c2da_mem[786] = uint8(c2da_fresh128 >> 0x10)
        c2da_mem[787] = uint8(c2da_fresh128 >> 0x18)
        c2da_mem[788] = uint8(c2da_fresh128 >> 0x20)
        c2da_mem[789] = uint8(c2da_fresh128 >> 0x28)
        c2da_mem[790] = uint8(c2da_fresh128 >> 0x30)
        c2da_mem[791] = uint8(c2da_fresh128 >> 0x38)
        return 1.0
    }
    if (double(f_0) > 0.1lf) {
        let c2da_fresh129 : double = uint64_bits_to_double(uint64(uint(c2da_mem[768 + 0 * 8]) | uint(c2da_mem[768 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 3]) << 0x18) | uint64(uint(c2da_mem[768 + 0 * 8 + 4]) | uint(c2da_mem[768 + 0 * 8 + 5]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 6]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 7]) << 0x18) << 0x20) - 0.1lf
        let c2da_fresh130 : uint64 = double_bits_to_uint64(c2da_fresh129)
        c2da_mem[768 + 1 * 8] = uint8(c2da_fresh130)
        c2da_mem[768 + 1 * 8 + 1] = uint8(c2da_fresh130 >> 0x8)
        c2da_mem[768 + 1 * 8 + 2] = uint8(c2da_fresh130 >> 0x10)
        c2da_mem[768 + 1 * 8 + 3] = uint8(c2da_fresh130 >> 0x18)
        c2da_mem[768 + 1 * 8 + 4] = uint8(c2da_fresh130 >> 0x20)
        c2da_mem[768 + 1 * 8 + 5] = uint8(c2da_fresh130 >> 0x28)
        c2da_mem[768 + 1 * 8 + 6] = uint8(c2da_fresh130 >> 0x30)
        c2da_mem[768 + 1 * 8 + 7] = uint8(c2da_fresh130 >> 0x38)
        f_0 = float(0.1lf)
    }
    frac_0 = float((uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - uint64_bits_to_double(uint64(uint(c2da_mem[768 + 1 * 8]) | uint(c2da_mem[768 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[768 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[768 + 1 * 8 + 3]) << 0x18) | uint64(uint(c2da_mem[768 + 1 * 8 + 4]) | uint(c2da_mem[768 + 1 * 8 + 5]) << 0x8 | uint(c2da_mem[768 + 1 * 8 + 6]) << 0x10 | uint(c2da_mem[768 + 1 * 8 + 7]) << 0x18) << 0x20)) / double(f_0))
    if (frac_0 < 0.0) {
        if (double(frac_0) < -0.01lf) {
            SetPal(1)
            let c2da_fresh131 : double = uint64_bits_to_double(uint64(uint(c2da_mem[768 + 1 * 8]) | uint(c2da_mem[768 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[768 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[768 + 1 * 8 + 3]) << 0x18) | uint64(uint(c2da_mem[768 + 1 * 8 + 4]) | uint(c2da_mem[768 + 1 * 8 + 5]) << 0x8 | uint(c2da_mem[768 + 1 * 8 + 6]) << 0x10 | uint(c2da_mem[768 + 1 * 8 + 7]) << 0x18) << 0x20)
            let c2da_fresh132 : uint64 = double_bits_to_uint64(c2da_fresh131)
            c2da_mem[784] = uint8(c2da_fresh132)
            c2da_mem[785] = uint8(c2da_fresh132 >> 0x8)
            c2da_mem[786] = uint8(c2da_fresh132 >> 0x10)
            c2da_mem[787] = uint8(c2da_fresh132 >> 0x18)
            c2da_mem[788] = uint8(c2da_fresh132 >> 0x20)
            c2da_mem[789] = uint8(c2da_fresh132 >> 0x28)
            c2da_mem[790] = uint8(c2da_fresh132 >> 0x30)
            c2da_mem[791] = uint8(c2da_fresh132 >> 0x38)
        }
        frac_0 = 0.0
    } elif (frac_0 > 1.0) {
        if (double(frac_0) > 1.01lf) {
            SetPal(2)
            let c2da_fresh133 : double = uint64_bits_to_double(uint64(uint(c2da_mem[768 + 0 * 8]) | uint(c2da_mem[768 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 3]) << 0x18) | uint64(uint(c2da_mem[768 + 0 * 8 + 4]) | uint(c2da_mem[768 + 0 * 8 + 5]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 6]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 7]) << 0x18) << 0x20)
            let c2da_fresh134 : uint64 = double_bits_to_uint64(c2da_fresh133)
            c2da_mem[784] = uint8(c2da_fresh134)
            c2da_mem[785] = uint8(c2da_fresh134 >> 0x8)
            c2da_mem[786] = uint8(c2da_fresh134 >> 0x10)
            c2da_mem[787] = uint8(c2da_fresh134 >> 0x18)
            c2da_mem[788] = uint8(c2da_fresh134 >> 0x20)
            c2da_mem[789] = uint8(c2da_fresh134 >> 0x28)
            c2da_mem[790] = uint8(c2da_fresh134 >> 0x30)
            c2da_mem[791] = uint8(c2da_fresh134 >> 0x38)
        }
        frac_0 = 1.0
    } else {
        SetPal(0)
    }
    return frac_0
}
[export, sideeffects]
def SetPal(var i_4 : int) {
    return
}
[export, sideeffects]
def CL_SignonReply() {
    let c2da_saved_sp : int = c2da_lin_sp
    CL_SignonReply_c2da_frame(c2da_lin_enter(8192))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private CL_NextDemo_c2da_frame(c2da_fp : int) {
    if (int(uint(c2da_mem[7636]) | uint(c2da_mem[7637]) << 0x8 | uint(c2da_mem[7638]) << 0x10 | uint(c2da_mem[7639]) << 0x18) == -1) {
        return
    }
    SCR_BeginLoadingPlaque()
    let c2da_fresh22 : int = 7640 + int(uint(c2da_mem[7636]) | uint(c2da_mem[7637]) << 0x8 | uint(c2da_mem[7638]) << 0x10 | uint(c2da_mem[7639]) << 0x18) * 16 + 0
    if (int8(c2da_mem[c2da_fresh22]) == 0 || int(uint(c2da_mem[7636]) | uint(c2da_mem[7637]) << 0x8 | uint(c2da_mem[7638]) << 0x10 | uint(c2da_mem[7639]) << 0x18) == 8) {
        let c2da_fresh23 : int = 0
        let c2da_fresh24 : uint = uint(c2da_fresh23)
        c2da_mem[7636] = uint8(c2da_fresh24)
        c2da_mem[7637] = uint8(c2da_fresh24 >> 0x8)
        c2da_mem[7638] = uint8(c2da_fresh24 >> 0x10)
        c2da_mem[7639] = uint8(c2da_fresh24 >> 0x18)
        let c2da_fresh25 : int = 7640 + int(uint(c2da_mem[7636]) | uint(c2da_mem[7637]) << 0x8 | uint(c2da_mem[7638]) << 0x10 | uint(c2da_mem[7639]) << 0x18) * 16 + 0
        if (int8(c2da_mem[c2da_fresh25]) == 0) {
            Con_Printf(698540, [])
            let c2da_fresh26 : int = -1
            let c2da_fresh27 : uint = uint(c2da_fresh26)
            c2da_mem[7636] = uint8(c2da_fresh27)
            c2da_mem[7637] = uint8(c2da_fresh27 >> 0x8)
            c2da_mem[7638] = uint8(c2da_fresh27 >> 0x10)
            c2da_mem[7639] = uint8(c2da_fresh27 >> 0x18)
            return
        }
    }
    c2da_lin_snprintf(c2da_fp, 2147483647ul, 698573, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(7640 + int(uint(c2da_mem[7636]) | uint(c2da_mem[7637]) << 0x8 | uint(c2da_mem[7638]) << 0x10 | uint(c2da_mem[7639]) << 0x18) * 16))])
    Cbuf_InsertText(c2da_fp)
    let c2da_fresh28 : int = int(uint(c2da_mem[7636]) | uint(c2da_mem[7637]) << 0x8 | uint(c2da_mem[7638]) << 0x10 | uint(c2da_mem[7639]) << 0x18)
    let c2da_fresh29 : int = c2da_fresh28 + 1
    let c2da_fresh30 : uint = uint(c2da_fresh29)
    c2da_mem[7636] = uint8(c2da_fresh30)
    c2da_mem[7637] = uint8(c2da_fresh30 >> 0x8)
    c2da_mem[7638] = uint8(c2da_fresh30 >> 0x10)
    c2da_mem[7639] = uint8(c2da_fresh30 >> 0x18)
    return
}
[sideeffects]
def private CL_SendCmd_c2da_frame(c2da_fp : int) {
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) != 2u) {
        return
    }
    if (int(uint(c2da_mem[7804]) | uint(c2da_mem[7805]) << 0x8 | uint(c2da_mem[7806]) << 0x10 | uint(c2da_mem[7807]) << 0x18) == 4) {
        CL_BaseMove(c2da_fp)
        IN_Move(c2da_fp)
        CL_SendMove(c2da_fp)
    }
    if ((uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) != 0u) {
        SZ_Clear(7816)
        return
    }
    if (int(uint(c2da_mem[7836]) | uint(c2da_mem[7837]) << 0x8 | uint(c2da_mem[7838]) << 0x10 | uint(c2da_mem[7839]) << 0x18) == 0) {
        return
    }
    if (uint(NET_CanSendMessage(int(uint(c2da_mem[7808]) | uint(c2da_mem[7809]) << 0x8 | uint(c2da_mem[7810]) << 0x10 | uint(c2da_mem[7811]) << 0x18))) == 0u) {
        Con_DPrintf(698586, [])
        return
    }
    if (NET_SendMessage(int(uint(c2da_mem[7808]) | uint(c2da_mem[7809]) << 0x8 | uint(c2da_mem[7810]) << 0x10 | uint(c2da_mem[7811]) << 0x18), 7816) == -1) {
        Host_Error(698616, [])
    }
    SZ_Clear(7816)
    return
}
[sideeffects]
def private CL_RelinkEntities_c2da_frame(c2da_fp : int) {
    var ent_0 : int
    var i_3 : int
    var j : int
    var frac : float
    var f : float
    var d : float
    var delta : vec3_t
    var bobjrotate : float
    var dl_1 : int
    frac = CL_LerpPoint()
    cl_numvisedicts = 0
    i_3 = 0
    while (i_3 < 3) {
        let c2da_fresh43 : float = uint_bits_to_float(uint(c2da_mem[664 + 1 * 12 + i_3 * 4]) | uint(c2da_mem[664 + 1 * 12 + i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[664 + 1 * 12 + i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[664 + 1 * 12 + i_3 * 4 + 3]) << 0x18) + frac * (uint_bits_to_float(uint(c2da_mem[664 + 0 * 12 + i_3 * 4]) | uint(c2da_mem[664 + 0 * 12 + i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[664 + 0 * 12 + i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[664 + 0 * 12 + i_3 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[664 + 1 * 12 + i_3 * 4]) | uint(c2da_mem[664 + 1 * 12 + i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[664 + 1 * 12 + i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[664 + 1 * 12 + i_3 * 4 + 3]) << 0x18))
        let c2da_fresh44 : uint = float_bits_to_uint(c2da_fresh43)
        c2da_mem[688 + i_3 * 4] = uint8(c2da_fresh44)
        c2da_mem[688 + i_3 * 4 + 1] = uint8(c2da_fresh44 >> 0x8)
        c2da_mem[688 + i_3 * 4 + 2] = uint8(c2da_fresh44 >> 0x10)
        c2da_mem[688 + i_3 * 4 + 3] = uint8(c2da_fresh44 >> 0x18)
        i_3++
    }
    if ((uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) != 0u) {
        j = 0
        while (j < 3) {
            d = uint_bits_to_float(uint(c2da_mem[628 + 0 * 12 + j * 4]) | uint(c2da_mem[628 + 0 * 12 + j * 4 + 1]) << 0x8 | uint(c2da_mem[628 + 0 * 12 + j * 4 + 2]) << 0x10 | uint(c2da_mem[628 + 0 * 12 + j * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[628 + 1 * 12 + j * 4]) | uint(c2da_mem[628 + 1 * 12 + j * 4 + 1]) << 0x8 | uint(c2da_mem[628 + 1 * 12 + j * 4 + 2]) << 0x10 | uint(c2da_mem[628 + 1 * 12 + j * 4 + 3]) << 0x18)
            if (d > 180.0) {
                d -= 360.0
            } elif (d < -180.0) {
                d += 360.0
            }
            let c2da_fresh45 : float = uint_bits_to_float(uint(c2da_mem[628 + 1 * 12 + j * 4]) | uint(c2da_mem[628 + 1 * 12 + j * 4 + 1]) << 0x8 | uint(c2da_mem[628 + 1 * 12 + j * 4 + 2]) << 0x10 | uint(c2da_mem[628 + 1 * 12 + j * 4 + 3]) << 0x18) + frac * d
            let c2da_fresh46 : uint = float_bits_to_uint(c2da_fresh45)
            c2da_mem[652 + j * 4] = uint8(c2da_fresh46)
            c2da_mem[652 + j * 4 + 1] = uint8(c2da_fresh46 >> 0x8)
            c2da_mem[652 + j * 4 + 2] = uint8(c2da_fresh46 >> 0x10)
            c2da_mem[652 + j * 4 + 3] = uint8(c2da_fresh46 >> 0x18)
            j++
        }
    }
    bobjrotate = anglemod(float(100.0lf * uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20)))
    i_3 = 1
    ent_0 = 10048 + 1 * 200
    while (i_3 < int(uint(c2da_mem[4976]) | uint(c2da_mem[4977]) << 0x8 | uint(c2da_mem[4978]) << 0x10 | uint(c2da_mem[4979]) << 0x18)) {
        if (int(uint(c2da_mem[ent_0 + 136]) | uint(c2da_mem[ent_0 + 137]) << 0x8 | uint(c2da_mem[ent_0 + 138]) << 0x10 | uint(c2da_mem[ent_0 + 139]) << 0x18) == 0) {
            if ((uint(c2da_mem[ent_0]) | uint(c2da_mem[ent_0 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 3]) << 0x18) != 0u) {
                R_RemoveEfrags(ent_0)
            }
            i_3++
            ent_0 += 200
            continue
        }
        if (uint64_bits_to_double(uint64(uint(c2da_mem[ent_0 + 56]) | uint(c2da_mem[ent_0 + 57]) << 0x8 | uint(c2da_mem[ent_0 + 58]) << 0x10 | uint(c2da_mem[ent_0 + 59]) << 0x18) | uint64(uint(c2da_mem[ent_0 + 60]) | uint(c2da_mem[ent_0 + 61]) << 0x8 | uint(c2da_mem[ent_0 + 62]) << 0x10 | uint(c2da_mem[ent_0 + 63]) << 0x18) << 0x20) != uint64_bits_to_double(uint64(uint(c2da_mem[768 + 0 * 8]) | uint(c2da_mem[768 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 3]) << 0x18) | uint64(uint(c2da_mem[768 + 0 * 8 + 4]) | uint(c2da_mem[768 + 0 * 8 + 5]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 6]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 7]) << 0x18) << 0x20)) {
            let c2da_fresh47 : uint = 0u
            c2da_mem[ent_0 + 136] = uint8(c2da_fresh47)
            c2da_mem[ent_0 + 137] = uint8(c2da_fresh47 >> 0x8)
            c2da_mem[ent_0 + 138] = uint8(c2da_fresh47 >> 0x10)
            c2da_mem[ent_0 + 139] = uint8(c2da_fresh47 >> 0x18)
            c2da_mem[ent_0 + 140] = 0u8
            c2da_mem[ent_0 + 141] = 0u8
            c2da_mem[ent_0 + 142] = 0u8
            c2da_mem[ent_0 + 143] = 0u8
            i_3++
            ent_0 += 200
            continue
        }
        let c2da_fresh48 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 0 * 4]) | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh49 : uint = float_bits_to_uint(c2da_fresh48)
        c2da_mem[c2da_fp + 48 + 0 * 4] = uint8(c2da_fresh49)
        c2da_mem[c2da_fp + 48 + 0 * 4 + 1] = uint8(c2da_fresh49 >> 0x8)
        c2da_mem[c2da_fp + 48 + 0 * 4 + 2] = uint8(c2da_fresh49 >> 0x10)
        c2da_mem[c2da_fp + 48 + 0 * 4 + 3] = uint8(c2da_fresh49 >> 0x18)
        let c2da_fresh50 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 1 * 4]) | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh51 : uint = float_bits_to_uint(c2da_fresh50)
        c2da_mem[c2da_fp + 48 + 1 * 4] = uint8(c2da_fresh51)
        c2da_mem[c2da_fp + 48 + 1 * 4 + 1] = uint8(c2da_fresh51 >> 0x8)
        c2da_mem[c2da_fp + 48 + 1 * 4 + 2] = uint8(c2da_fresh51 >> 0x10)
        c2da_mem[c2da_fp + 48 + 1 * 4 + 3] = uint8(c2da_fresh51 >> 0x18)
        let c2da_fresh52 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 2 * 4]) | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh53 : uint = float_bits_to_uint(c2da_fresh52)
        c2da_mem[c2da_fp + 48 + 2 * 4] = uint8(c2da_fresh53)
        c2da_mem[c2da_fp + 48 + 2 * 4 + 1] = uint8(c2da_fresh53 >> 0x8)
        c2da_mem[c2da_fp + 48 + 2 * 4 + 2] = uint8(c2da_fresh53 >> 0x10)
        c2da_mem[c2da_fp + 48 + 2 * 4 + 3] = uint8(c2da_fresh53 >> 0x18)
        if ((uint(c2da_mem[ent_0]) | uint(c2da_mem[ent_0 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 3]) << 0x18) != 0u) {
            let c2da_fresh54 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 64 + 0 * 12 + 0 * 4]) | uint(c2da_mem[ent_0 + 64 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 64 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 64 + 0 * 12 + 0 * 4 + 3]) << 0x18)
            let c2da_fresh55 : uint = float_bits_to_uint(c2da_fresh54)
            c2da_mem[ent_0 + 88 + 0 * 4] = uint8(c2da_fresh55)
            c2da_mem[ent_0 + 88 + 0 * 4 + 1] = uint8(c2da_fresh55 >> 0x8)
            c2da_mem[ent_0 + 88 + 0 * 4 + 2] = uint8(c2da_fresh55 >> 0x10)
            c2da_mem[ent_0 + 88 + 0 * 4 + 3] = uint8(c2da_fresh55 >> 0x18)
            let c2da_fresh56 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 64 + 0 * 12 + 1 * 4]) | uint(c2da_mem[ent_0 + 64 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 64 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 64 + 0 * 12 + 1 * 4 + 3]) << 0x18)
            let c2da_fresh57 : uint = float_bits_to_uint(c2da_fresh56)
            c2da_mem[ent_0 + 88 + 1 * 4] = uint8(c2da_fresh57)
            c2da_mem[ent_0 + 88 + 1 * 4 + 1] = uint8(c2da_fresh57 >> 0x8)
            c2da_mem[ent_0 + 88 + 1 * 4 + 2] = uint8(c2da_fresh57 >> 0x10)
            c2da_mem[ent_0 + 88 + 1 * 4 + 3] = uint8(c2da_fresh57 >> 0x18)
            let c2da_fresh58 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 64 + 0 * 12 + 2 * 4]) | uint(c2da_mem[ent_0 + 64 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 64 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 64 + 0 * 12 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh59 : uint = float_bits_to_uint(c2da_fresh58)
            c2da_mem[ent_0 + 88 + 2 * 4] = uint8(c2da_fresh59)
            c2da_mem[ent_0 + 88 + 2 * 4 + 1] = uint8(c2da_fresh59 >> 0x8)
            c2da_mem[ent_0 + 88 + 2 * 4 + 2] = uint8(c2da_fresh59 >> 0x10)
            c2da_mem[ent_0 + 88 + 2 * 4 + 3] = uint8(c2da_fresh59 >> 0x18)
            let c2da_fresh60 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 100 + 0 * 12 + 0 * 4]) | uint(c2da_mem[ent_0 + 100 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 100 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 100 + 0 * 12 + 0 * 4 + 3]) << 0x18)
            let c2da_fresh61 : uint = float_bits_to_uint(c2da_fresh60)
            c2da_mem[ent_0 + 124 + 0 * 4] = uint8(c2da_fresh61)
            c2da_mem[ent_0 + 124 + 0 * 4 + 1] = uint8(c2da_fresh61 >> 0x8)
            c2da_mem[ent_0 + 124 + 0 * 4 + 2] = uint8(c2da_fresh61 >> 0x10)
            c2da_mem[ent_0 + 124 + 0 * 4 + 3] = uint8(c2da_fresh61 >> 0x18)
            let c2da_fresh62 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 100 + 0 * 12 + 1 * 4]) | uint(c2da_mem[ent_0 + 100 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 100 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 100 + 0 * 12 + 1 * 4 + 3]) << 0x18)
            let c2da_fresh63 : uint = float_bits_to_uint(c2da_fresh62)
            c2da_mem[ent_0 + 124 + 1 * 4] = uint8(c2da_fresh63)
            c2da_mem[ent_0 + 124 + 1 * 4 + 1] = uint8(c2da_fresh63 >> 0x8)
            c2da_mem[ent_0 + 124 + 1 * 4 + 2] = uint8(c2da_fresh63 >> 0x10)
            c2da_mem[ent_0 + 124 + 1 * 4 + 3] = uint8(c2da_fresh63 >> 0x18)
            let c2da_fresh64 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 100 + 0 * 12 + 2 * 4]) | uint(c2da_mem[ent_0 + 100 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 100 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 100 + 0 * 12 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh65 : uint = float_bits_to_uint(c2da_fresh64)
            c2da_mem[ent_0 + 124 + 2 * 4] = uint8(c2da_fresh65)
            c2da_mem[ent_0 + 124 + 2 * 4 + 1] = uint8(c2da_fresh65 >> 0x8)
            c2da_mem[ent_0 + 124 + 2 * 4 + 2] = uint8(c2da_fresh65 >> 0x10)
            c2da_mem[ent_0 + 124 + 2 * 4 + 3] = uint8(c2da_fresh65 >> 0x18)
        } else {
            f = frac
            j = 0
            while (j < 3) {
                delta[j] = uint_bits_to_float(uint(c2da_mem[ent_0 + 64 + 0 * 12 + j * 4]) | uint(c2da_mem[ent_0 + 64 + 0 * 12 + j * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 64 + 0 * 12 + j * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 64 + 0 * 12 + j * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[ent_0 + 64 + 1 * 12 + j * 4]) | uint(c2da_mem[ent_0 + 64 + 1 * 12 + j * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 64 + 1 * 12 + j * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 64 + 1 * 12 + j * 4 + 3]) << 0x18)
                if (delta[j] > 100.0 || delta[j] < -100.0) {
                    f = 1.0
                }
                j++
            }
            j = 0
            while (j < 3) {
                let c2da_fresh66 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 64 + 1 * 12 + j * 4]) | uint(c2da_mem[ent_0 + 64 + 1 * 12 + j * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 64 + 1 * 12 + j * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 64 + 1 * 12 + j * 4 + 3]) << 0x18) + f * delta[j]
                let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
                c2da_mem[ent_0 + 88 + j * 4] = uint8(c2da_fresh67)
                c2da_mem[ent_0 + 88 + j * 4 + 1] = uint8(c2da_fresh67 >> 0x8)
                c2da_mem[ent_0 + 88 + j * 4 + 2] = uint8(c2da_fresh67 >> 0x10)
                c2da_mem[ent_0 + 88 + j * 4 + 3] = uint8(c2da_fresh67 >> 0x18)
                d = uint_bits_to_float(uint(c2da_mem[ent_0 + 100 + 0 * 12 + j * 4]) | uint(c2da_mem[ent_0 + 100 + 0 * 12 + j * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 100 + 0 * 12 + j * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 100 + 0 * 12 + j * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[ent_0 + 100 + 1 * 12 + j * 4]) | uint(c2da_mem[ent_0 + 100 + 1 * 12 + j * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 100 + 1 * 12 + j * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 100 + 1 * 12 + j * 4 + 3]) << 0x18)
                if (d > 180.0) {
                    d -= 360.0
                } elif (d < -180.0) {
                    d += 360.0
                }
                let c2da_fresh68 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 100 + 1 * 12 + j * 4]) | uint(c2da_mem[ent_0 + 100 + 1 * 12 + j * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 100 + 1 * 12 + j * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 100 + 1 * 12 + j * 4 + 3]) << 0x18) + f * d
                let c2da_fresh69 : uint = float_bits_to_uint(c2da_fresh68)
                c2da_mem[ent_0 + 124 + j * 4] = uint8(c2da_fresh69)
                c2da_mem[ent_0 + 124 + j * 4 + 1] = uint8(c2da_fresh69 >> 0x8)
                c2da_mem[ent_0 + 124 + j * 4 + 2] = uint8(c2da_fresh69 >> 0x10)
                c2da_mem[ent_0 + 124 + j * 4 + 3] = uint8(c2da_fresh69 >> 0x18)
                j++
            }
        }
        let c2da_fresh70 : int = int(uint(c2da_mem[ent_0 + 136]) | uint(c2da_mem[ent_0 + 137]) << 0x8 | uint(c2da_mem[ent_0 + 138]) << 0x10 | uint(c2da_mem[ent_0 + 139]) << 0x18) + 80
        if ((int(uint(c2da_mem[c2da_fresh70]) | uint(c2da_mem[c2da_fresh70 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh70 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh70 + 3]) << 0x18) & 8) != 0) {
            let c2da_fresh71 : uint = float_bits_to_uint(bobjrotate)
            c2da_mem[ent_0 + 124 + 1 * 4] = uint8(c2da_fresh71)
            c2da_mem[ent_0 + 124 + 1 * 4 + 1] = uint8(c2da_fresh71 >> 0x8)
            c2da_mem[ent_0 + 124 + 1 * 4 + 2] = uint8(c2da_fresh71 >> 0x10)
            c2da_mem[ent_0 + 124 + 1 * 4 + 3] = uint8(c2da_fresh71 >> 0x18)
        }
        if ((int(uint(c2da_mem[ent_0 + 168]) | uint(c2da_mem[ent_0 + 169]) << 0x8 | uint(c2da_mem[ent_0 + 170]) << 0x10 | uint(c2da_mem[ent_0 + 171]) << 0x18) & 1) != 0) {
            R_EntityParticles(ent_0)
        }
        if ((int(uint(c2da_mem[ent_0 + 168]) | uint(c2da_mem[ent_0 + 169]) << 0x8 | uint(c2da_mem[ent_0 + 170]) << 0x10 | uint(c2da_mem[ent_0 + 171]) << 0x18) & 2) != 0) {
            dl_1 = CL_AllocDlight(i_3)
            let c2da_fresh72 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 0 * 4]) | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 3]) << 0x18)
            let c2da_fresh73 : uint = float_bits_to_uint(c2da_fresh72)
            c2da_mem[dl_1 + 0 * 4] = uint8(c2da_fresh73)
            c2da_mem[dl_1 + 0 * 4 + 1] = uint8(c2da_fresh73 >> 0x8)
            c2da_mem[dl_1 + 0 * 4 + 2] = uint8(c2da_fresh73 >> 0x10)
            c2da_mem[dl_1 + 0 * 4 + 3] = uint8(c2da_fresh73 >> 0x18)
            let c2da_fresh74 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 1 * 4]) | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 3]) << 0x18)
            let c2da_fresh75 : uint = float_bits_to_uint(c2da_fresh74)
            c2da_mem[dl_1 + 1 * 4] = uint8(c2da_fresh75)
            c2da_mem[dl_1 + 1 * 4 + 1] = uint8(c2da_fresh75 >> 0x8)
            c2da_mem[dl_1 + 1 * 4 + 2] = uint8(c2da_fresh75 >> 0x10)
            c2da_mem[dl_1 + 1 * 4 + 3] = uint8(c2da_fresh75 >> 0x18)
            let c2da_fresh76 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 2 * 4]) | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh77 : uint = float_bits_to_uint(c2da_fresh76)
            c2da_mem[dl_1 + 2 * 4] = uint8(c2da_fresh77)
            c2da_mem[dl_1 + 2 * 4 + 1] = uint8(c2da_fresh77 >> 0x8)
            c2da_mem[dl_1 + 2 * 4 + 2] = uint8(c2da_fresh77 >> 0x10)
            c2da_mem[dl_1 + 2 * 4 + 3] = uint8(c2da_fresh77 >> 0x18)
            let c2da_fresh78 : float = uint_bits_to_float(uint(c2da_mem[dl_1 + 2 * 4]) | uint(c2da_mem[dl_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[dl_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[dl_1 + 2 * 4 + 3]) << 0x18) + 16.0
            let c2da_fresh79 : uint = float_bits_to_uint(c2da_fresh78)
            c2da_mem[dl_1 + 2 * 4] = uint8(c2da_fresh79)
            c2da_mem[dl_1 + 2 * 4 + 1] = uint8(c2da_fresh79 >> 0x8)
            c2da_mem[dl_1 + 2 * 4 + 2] = uint8(c2da_fresh79 >> 0x10)
            c2da_mem[dl_1 + 2 * 4 + 3] = uint8(c2da_fresh79 >> 0x18)
            AngleVectors(ent_0 + 124, c2da_fp, c2da_fp + 16, c2da_fp + 32)
            VectorMA(dl_1, 18.0, c2da_fp, dl_1)
            let c2da_fresh80 : float = float(200 + (c2da_std_rand() & 31))
            let c2da_fresh81 : uint = float_bits_to_uint(c2da_fresh80)
            c2da_mem[dl_1 + 12] = uint8(c2da_fresh81)
            c2da_mem[dl_1 + 13] = uint8(c2da_fresh81 >> 0x8)
            c2da_mem[dl_1 + 14] = uint8(c2da_fresh81 >> 0x10)
            c2da_mem[dl_1 + 15] = uint8(c2da_fresh81 >> 0x18)
            let c2da_fresh82 : float = 32.0
            let c2da_fresh83 : uint = float_bits_to_uint(c2da_fresh82)
            c2da_mem[dl_1 + 24] = uint8(c2da_fresh83)
            c2da_mem[dl_1 + 25] = uint8(c2da_fresh83 >> 0x8)
            c2da_mem[dl_1 + 26] = uint8(c2da_fresh83 >> 0x10)
            c2da_mem[dl_1 + 27] = uint8(c2da_fresh83 >> 0x18)
            let c2da_fresh84 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.1lf)
            let c2da_fresh85 : uint = float_bits_to_uint(c2da_fresh84)
            c2da_mem[dl_1 + 16] = uint8(c2da_fresh85)
            c2da_mem[dl_1 + 17] = uint8(c2da_fresh85 >> 0x8)
            c2da_mem[dl_1 + 18] = uint8(c2da_fresh85 >> 0x10)
            c2da_mem[dl_1 + 19] = uint8(c2da_fresh85 >> 0x18)
        }
        if ((int(uint(c2da_mem[ent_0 + 168]) | uint(c2da_mem[ent_0 + 169]) << 0x8 | uint(c2da_mem[ent_0 + 170]) << 0x10 | uint(c2da_mem[ent_0 + 171]) << 0x18) & 4) != 0) {
            dl_1 = CL_AllocDlight(i_3)
            let c2da_fresh86 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 0 * 4]) | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 3]) << 0x18)
            let c2da_fresh87 : uint = float_bits_to_uint(c2da_fresh86)
            c2da_mem[dl_1 + 0 * 4] = uint8(c2da_fresh87)
            c2da_mem[dl_1 + 0 * 4 + 1] = uint8(c2da_fresh87 >> 0x8)
            c2da_mem[dl_1 + 0 * 4 + 2] = uint8(c2da_fresh87 >> 0x10)
            c2da_mem[dl_1 + 0 * 4 + 3] = uint8(c2da_fresh87 >> 0x18)
            let c2da_fresh88 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 1 * 4]) | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 3]) << 0x18)
            let c2da_fresh89 : uint = float_bits_to_uint(c2da_fresh88)
            c2da_mem[dl_1 + 1 * 4] = uint8(c2da_fresh89)
            c2da_mem[dl_1 + 1 * 4 + 1] = uint8(c2da_fresh89 >> 0x8)
            c2da_mem[dl_1 + 1 * 4 + 2] = uint8(c2da_fresh89 >> 0x10)
            c2da_mem[dl_1 + 1 * 4 + 3] = uint8(c2da_fresh89 >> 0x18)
            let c2da_fresh90 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 2 * 4]) | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh91 : uint = float_bits_to_uint(c2da_fresh90)
            c2da_mem[dl_1 + 2 * 4] = uint8(c2da_fresh91)
            c2da_mem[dl_1 + 2 * 4 + 1] = uint8(c2da_fresh91 >> 0x8)
            c2da_mem[dl_1 + 2 * 4 + 2] = uint8(c2da_fresh91 >> 0x10)
            c2da_mem[dl_1 + 2 * 4 + 3] = uint8(c2da_fresh91 >> 0x18)
            let c2da_fresh92 : float = uint_bits_to_float(uint(c2da_mem[dl_1 + 2 * 4]) | uint(c2da_mem[dl_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[dl_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[dl_1 + 2 * 4 + 3]) << 0x18) + 16.0
            let c2da_fresh93 : uint = float_bits_to_uint(c2da_fresh92)
            c2da_mem[dl_1 + 2 * 4] = uint8(c2da_fresh93)
            c2da_mem[dl_1 + 2 * 4 + 1] = uint8(c2da_fresh93 >> 0x8)
            c2da_mem[dl_1 + 2 * 4 + 2] = uint8(c2da_fresh93 >> 0x10)
            c2da_mem[dl_1 + 2 * 4 + 3] = uint8(c2da_fresh93 >> 0x18)
            let c2da_fresh94 : float = float(400 + (c2da_std_rand() & 31))
            let c2da_fresh95 : uint = float_bits_to_uint(c2da_fresh94)
            c2da_mem[dl_1 + 12] = uint8(c2da_fresh95)
            c2da_mem[dl_1 + 13] = uint8(c2da_fresh95 >> 0x8)
            c2da_mem[dl_1 + 14] = uint8(c2da_fresh95 >> 0x10)
            c2da_mem[dl_1 + 15] = uint8(c2da_fresh95 >> 0x18)
            let c2da_fresh96 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.001lf)
            let c2da_fresh97 : uint = float_bits_to_uint(c2da_fresh96)
            c2da_mem[dl_1 + 16] = uint8(c2da_fresh97)
            c2da_mem[dl_1 + 17] = uint8(c2da_fresh97 >> 0x8)
            c2da_mem[dl_1 + 18] = uint8(c2da_fresh97 >> 0x10)
            c2da_mem[dl_1 + 19] = uint8(c2da_fresh97 >> 0x18)
        }
        if ((int(uint(c2da_mem[ent_0 + 168]) | uint(c2da_mem[ent_0 + 169]) << 0x8 | uint(c2da_mem[ent_0 + 170]) << 0x10 | uint(c2da_mem[ent_0 + 171]) << 0x18) & 8) != 0) {
            dl_1 = CL_AllocDlight(i_3)
            let c2da_fresh98 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 0 * 4]) | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 3]) << 0x18)
            let c2da_fresh99 : uint = float_bits_to_uint(c2da_fresh98)
            c2da_mem[dl_1 + 0 * 4] = uint8(c2da_fresh99)
            c2da_mem[dl_1 + 0 * 4 + 1] = uint8(c2da_fresh99 >> 0x8)
            c2da_mem[dl_1 + 0 * 4 + 2] = uint8(c2da_fresh99 >> 0x10)
            c2da_mem[dl_1 + 0 * 4 + 3] = uint8(c2da_fresh99 >> 0x18)
            let c2da_fresh100 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 1 * 4]) | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 3]) << 0x18)
            let c2da_fresh101 : uint = float_bits_to_uint(c2da_fresh100)
            c2da_mem[dl_1 + 1 * 4] = uint8(c2da_fresh101)
            c2da_mem[dl_1 + 1 * 4 + 1] = uint8(c2da_fresh101 >> 0x8)
            c2da_mem[dl_1 + 1 * 4 + 2] = uint8(c2da_fresh101 >> 0x10)
            c2da_mem[dl_1 + 1 * 4 + 3] = uint8(c2da_fresh101 >> 0x18)
            let c2da_fresh102 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 2 * 4]) | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh103 : uint = float_bits_to_uint(c2da_fresh102)
            c2da_mem[dl_1 + 2 * 4] = uint8(c2da_fresh103)
            c2da_mem[dl_1 + 2 * 4 + 1] = uint8(c2da_fresh103 >> 0x8)
            c2da_mem[dl_1 + 2 * 4 + 2] = uint8(c2da_fresh103 >> 0x10)
            c2da_mem[dl_1 + 2 * 4 + 3] = uint8(c2da_fresh103 >> 0x18)
            let c2da_fresh104 : float = float(200 + (c2da_std_rand() & 31))
            let c2da_fresh105 : uint = float_bits_to_uint(c2da_fresh104)
            c2da_mem[dl_1 + 12] = uint8(c2da_fresh105)
            c2da_mem[dl_1 + 13] = uint8(c2da_fresh105 >> 0x8)
            c2da_mem[dl_1 + 14] = uint8(c2da_fresh105 >> 0x10)
            c2da_mem[dl_1 + 15] = uint8(c2da_fresh105 >> 0x18)
            let c2da_fresh106 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.001lf)
            let c2da_fresh107 : uint = float_bits_to_uint(c2da_fresh106)
            c2da_mem[dl_1 + 16] = uint8(c2da_fresh107)
            c2da_mem[dl_1 + 17] = uint8(c2da_fresh107 >> 0x8)
            c2da_mem[dl_1 + 18] = uint8(c2da_fresh107 >> 0x10)
            c2da_mem[dl_1 + 19] = uint8(c2da_fresh107 >> 0x18)
        }
        let c2da_fresh108 : int = int(uint(c2da_mem[ent_0 + 136]) | uint(c2da_mem[ent_0 + 137]) << 0x8 | uint(c2da_mem[ent_0 + 138]) << 0x10 | uint(c2da_mem[ent_0 + 139]) << 0x18) + 80
        if ((int(uint(c2da_mem[c2da_fresh108]) | uint(c2da_mem[c2da_fresh108 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh108 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh108 + 3]) << 0x18) & 4) != 0) {
            R_RocketTrail(c2da_fp + 48, ent_0 + 88, 2)
        } else {
            let c2da_fresh109 : int = int(uint(c2da_mem[ent_0 + 136]) | uint(c2da_mem[ent_0 + 137]) << 0x8 | uint(c2da_mem[ent_0 + 138]) << 0x10 | uint(c2da_mem[ent_0 + 139]) << 0x18) + 80
            if ((int(uint(c2da_mem[c2da_fresh109]) | uint(c2da_mem[c2da_fresh109 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh109 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh109 + 3]) << 0x18) & 32) != 0) {
                R_RocketTrail(c2da_fp + 48, ent_0 + 88, 4)
            } else {
                let c2da_fresh110 : int = int(uint(c2da_mem[ent_0 + 136]) | uint(c2da_mem[ent_0 + 137]) << 0x8 | uint(c2da_mem[ent_0 + 138]) << 0x10 | uint(c2da_mem[ent_0 + 139]) << 0x18) + 80
                if ((int(uint(c2da_mem[c2da_fresh110]) | uint(c2da_mem[c2da_fresh110 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh110 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh110 + 3]) << 0x18) & 16) != 0) {
                    R_RocketTrail(c2da_fp + 48, ent_0 + 88, 3)
                } else {
                    let c2da_fresh111 : int = int(uint(c2da_mem[ent_0 + 136]) | uint(c2da_mem[ent_0 + 137]) << 0x8 | uint(c2da_mem[ent_0 + 138]) << 0x10 | uint(c2da_mem[ent_0 + 139]) << 0x18) + 80
                    if ((int(uint(c2da_mem[c2da_fresh111]) | uint(c2da_mem[c2da_fresh111 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh111 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh111 + 3]) << 0x18) & 64) != 0) {
                        R_RocketTrail(c2da_fp + 48, ent_0 + 88, 5)
                    } else {
                        let c2da_fresh112 : int = int(uint(c2da_mem[ent_0 + 136]) | uint(c2da_mem[ent_0 + 137]) << 0x8 | uint(c2da_mem[ent_0 + 138]) << 0x10 | uint(c2da_mem[ent_0 + 139]) << 0x18) + 80
                        if ((int(uint(c2da_mem[c2da_fresh112]) | uint(c2da_mem[c2da_fresh112 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh112 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh112 + 3]) << 0x18) & 1) != 0) {
                            R_RocketTrail(c2da_fp + 48, ent_0 + 88, 0)
                            dl_1 = CL_AllocDlight(i_3)
                            let c2da_fresh113 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 0 * 4]) | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 3]) << 0x18)
                            let c2da_fresh114 : uint = float_bits_to_uint(c2da_fresh113)
                            c2da_mem[dl_1 + 0 * 4] = uint8(c2da_fresh114)
                            c2da_mem[dl_1 + 0 * 4 + 1] = uint8(c2da_fresh114 >> 0x8)
                            c2da_mem[dl_1 + 0 * 4 + 2] = uint8(c2da_fresh114 >> 0x10)
                            c2da_mem[dl_1 + 0 * 4 + 3] = uint8(c2da_fresh114 >> 0x18)
                            let c2da_fresh115 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 1 * 4]) | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 3]) << 0x18)
                            let c2da_fresh116 : uint = float_bits_to_uint(c2da_fresh115)
                            c2da_mem[dl_1 + 1 * 4] = uint8(c2da_fresh116)
                            c2da_mem[dl_1 + 1 * 4 + 1] = uint8(c2da_fresh116 >> 0x8)
                            c2da_mem[dl_1 + 1 * 4 + 2] = uint8(c2da_fresh116 >> 0x10)
                            c2da_mem[dl_1 + 1 * 4 + 3] = uint8(c2da_fresh116 >> 0x18)
                            let c2da_fresh117 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 2 * 4]) | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 3]) << 0x18)
                            let c2da_fresh118 : uint = float_bits_to_uint(c2da_fresh117)
                            c2da_mem[dl_1 + 2 * 4] = uint8(c2da_fresh118)
                            c2da_mem[dl_1 + 2 * 4 + 1] = uint8(c2da_fresh118 >> 0x8)
                            c2da_mem[dl_1 + 2 * 4 + 2] = uint8(c2da_fresh118 >> 0x10)
                            c2da_mem[dl_1 + 2 * 4 + 3] = uint8(c2da_fresh118 >> 0x18)
                            let c2da_fresh119 : float = 200.0
                            let c2da_fresh120 : uint = float_bits_to_uint(c2da_fresh119)
                            c2da_mem[dl_1 + 12] = uint8(c2da_fresh120)
                            c2da_mem[dl_1 + 13] = uint8(c2da_fresh120 >> 0x8)
                            c2da_mem[dl_1 + 14] = uint8(c2da_fresh120 >> 0x10)
                            c2da_mem[dl_1 + 15] = uint8(c2da_fresh120 >> 0x18)
                            let c2da_fresh121 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.01lf)
                            let c2da_fresh122 : uint = float_bits_to_uint(c2da_fresh121)
                            c2da_mem[dl_1 + 16] = uint8(c2da_fresh122)
                            c2da_mem[dl_1 + 17] = uint8(c2da_fresh122 >> 0x8)
                            c2da_mem[dl_1 + 18] = uint8(c2da_fresh122 >> 0x10)
                            c2da_mem[dl_1 + 19] = uint8(c2da_fresh122 >> 0x18)
                        } else {
                            let c2da_fresh123 : int = int(uint(c2da_mem[ent_0 + 136]) | uint(c2da_mem[ent_0 + 137]) << 0x8 | uint(c2da_mem[ent_0 + 138]) << 0x10 | uint(c2da_mem[ent_0 + 139]) << 0x18) + 80
                            if ((int(uint(c2da_mem[c2da_fresh123]) | uint(c2da_mem[c2da_fresh123 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh123 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh123 + 3]) << 0x18) & 2) != 0) {
                                R_RocketTrail(c2da_fp + 48, ent_0 + 88, 1)
                            } else {
                                let c2da_fresh124 : int = int(uint(c2da_mem[ent_0 + 136]) | uint(c2da_mem[ent_0 + 137]) << 0x8 | uint(c2da_mem[ent_0 + 138]) << 0x10 | uint(c2da_mem[ent_0 + 139]) << 0x18) + 80
                                if ((int(uint(c2da_mem[c2da_fresh124]) | uint(c2da_mem[c2da_fresh124 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh124 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh124 + 3]) << 0x18) & 128) != 0) {
                                    R_RocketTrail(c2da_fp + 48, ent_0 + 88, 6)
                                }
                            }
                        }
                    }
                }
            }
        }
        let c2da_fresh125 : uint = 0u
        let c2da_fresh126 : uint = c2da_fresh125
        c2da_mem[ent_0] = uint8(c2da_fresh126)
        c2da_mem[ent_0 + 1] = uint8(c2da_fresh126 >> 0x8)
        c2da_mem[ent_0 + 2] = uint8(c2da_fresh126 >> 0x10)
        c2da_mem[ent_0 + 3] = uint8(c2da_fresh126 >> 0x18)
        if (i_3 == int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18) && uint_bits_to_float(uint(c2da_mem[184]) | uint(c2da_mem[185]) << 0x8 | uint(c2da_mem[186]) << 0x10 | uint(c2da_mem[187]) << 0x18) == 0.0) {
            i_3++
            ent_0 += 200
            continue
        }
        if (cl_numvisedicts < 256) {
            cl_visedicts[cl_numvisedicts] = ent_0
            cl_numvisedicts++
        }
        i_3++
        ent_0 += 200
    }
    return
}
[sideeffects]
def private CL_SignonReply_c2da_frame(c2da_fp : int) {
    var c2da_fresh135 : int
    Con_DPrintf(698701, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[7804]) | uint(c2da_mem[7805]) << 0x8 | uint(c2da_mem[7806]) << 0x10 | uint(c2da_mem[7807]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    c2da_fresh135 = int(uint(c2da_mem[7804]) | uint(c2da_mem[7805]) << 0x8 | uint(c2da_mem[7806]) << 0x10 | uint(c2da_mem[7807]) << 0x18)
    if (c2da_fresh135 == 1) {
        MSG_WriteByte(7816, 4)
        MSG_WriteString(7816, 698721)
    } elif (c2da_fresh135 == 2) {
        MSG_WriteByte(7816, 4)
        MSG_WriteString(7816, va(698730, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[9144]) | uint(c2da_mem[9145]) << 0x8 | uint(c2da_mem[9146]) << 0x10 | uint(c2da_mem[9147]) << 0x18)))]))
        MSG_WriteByte(7816, 4)
        MSG_WriteString(7816, va(698741, [C2daVaArg(tag = 1, i64 = int64(int(uint_bits_to_float(uint(c2da_mem[9208]) | uint(c2da_mem[9209]) << 0x8 | uint(c2da_mem[9210]) << 0x10 | uint(c2da_mem[9211]) << 0x18)) >> 4), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint_bits_to_float(uint(c2da_mem[9208]) | uint(c2da_mem[9209]) << 0x8 | uint(c2da_mem[9210]) << 0x10 | uint(c2da_mem[9211]) << 0x18)) & 15), f64 = 0.0lf, raw = 0x0)]))
        MSG_WriteByte(7816, 4)
        c2da_lin_snprintf(c2da_fp, 2147483647ul, 698754, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 5588ul)])
        MSG_WriteString(7816, c2da_fp)
    } elif (c2da_fresh135 == 3) {
        MSG_WriteByte(7816, 4)
        MSG_WriteString(7816, 698763)
        Cache_Report()
    } elif (c2da_fresh135 == 4) {
        SCR_EndLoadingPlaque()
    }
    return
}

// This unit's static data, at heap offset 698208.
let private c2da_lin_static_cl_main_seg = fixed_array<int>(698208, 560)
let private c2da_lin_static_cl_main = fixed_array<uint64>(0x656d616e5f6c635ful, 0x726579616c7000ul, 0x6f6c6f635f6c635ful, 0x735f6c6300300072ul, 0x630074656e776f68ul, 0x7072656c6f6e5f6cul, 0x7270736b6f6f6c00ul, 0x6b6f6f6c00676e69ul, 0x7300656661727473ul, 0x6976697469736e65ul, 0x705f6d0033007974ul, 0x302e300068637469ul, 0x7761795f6d003232ul, 0x6177726f665f6d00ul, 0x735f6d0031006472ul, 0x382e3000656469ul, 0x7365697469746e65ul, 0x6e6e6f6373696400ul, 0x6f63657200746365ul, 0x706f7473006472ul, 0x6f6d656479616c70ul, 0x6d6564656d697400ul, 0x6e69646e6553006ful, 0x69645f636c632067ul, 0x7463656e6e6f6373ul, 0x45003a693325000aul, 0x7325000a5954504dul, 0x252820206932253aul, 0x2e35252c66312e35ul, 0x66312e35252c6631ul, 0x66312e35255b2029ul, 0x252066312e352520ul, 0x43000a5d66312e35ul, 0x63656e6e6f435f4cul, 0x656e6e6f63203a74ul, 0x656c696166207463ul, 0x73455f4c43000a64ul, 0x436873696c626174ul, 0x6f697463656e6e6ful, 0x656e6e6f63203a6eul, 0x206f742064657463ul, 0x64206f4e000a7325ul, 0x73696c20736f6d65ul, 0x6874697720646574ul, 0x6564747261747320ul, 0x616c70000a736f6dul, 0x7325206f6d656479ul, 0x6972575f4c43000aul, 0x767265536f546574ul, 0x276e6163203a7265ul, 0xa646e65732074ul, 0x65746972575f4c43ul, 0x7265767265536f54ul, 0x732074736f6c203aul, 0x6f63207265767265ul, 0x6e6f697463656e6eul, 0x646165525f4c4300ul, 0x767265536d6f7246ul, 0x74736f6c203a7265ul, 0x2072657672657320ul, 0x697463656e6e6f63ul, 0x5f4c43000a006e6ful, 0x65526e6f6e676953ul, 0xa6925203a796c70ul, 0x7761707365727000ul, 0x2220656d616e006eul, 0x6c6f63000a227325ul, 0x692520692520726ful, 0x206e77617073000aul, 0x6e69676562007325ul)

[init]
def private c2da_lin_init_static_cl_main() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_cl_main_seg[s * 2]
        for (k in range(c2da_lin_static_cl_main_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_cl_main[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_cl_main_0 = fixed_array<uint8>(0x60, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x69, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_main_1 = fixed_array<uint8>(0x70, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7a, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_main_2 = fixed_array<uint8>(0x7c, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7a, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_main_3 = fixed_array<uint8>(0x87, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7a, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_main_4 = fixed_array<uint8>(0x91, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7a, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_main_5 = fixed_array<uint8>(0x9c, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7a, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_main_6 = fixed_array<uint8>(0xa7, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb3, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_main_7 = fixed_array<uint8>(0xb5, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbd, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_main_8 = fixed_array<uint8>(0xc3, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbd, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_main_9 = fixed_array<uint8>(0xc9, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xd3, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_main_10 = fixed_array<uint8>(0xd5, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xdc, 0xa7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_cl_main() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[9136 + i] = c2da_lin_extern_cl_main_0[i]
    }
    for (i in range(40)) {
        c2da_mem[9184 + i] = c2da_lin_extern_cl_main_1[i]
    }
    for (i in range(40)) {
        c2da_mem[9616 + i] = c2da_lin_extern_cl_main_2[i]
    }
    for (i in range(40)) {
        c2da_mem[9664 + i] = c2da_lin_extern_cl_main_3[i]
    }
    for (i in range(40)) {
        c2da_mem[9712 + i] = c2da_lin_extern_cl_main_4[i]
    }
    for (i in range(40)) {
        c2da_mem[9760 + i] = c2da_lin_extern_cl_main_5[i]
    }
    for (i in range(40)) {
        c2da_mem[9808 + i] = c2da_lin_extern_cl_main_6[i]
    }
    for (i in range(40)) {
        c2da_mem[9856 + i] = c2da_lin_extern_cl_main_7[i]
    }
    for (i in range(40)) {
        c2da_mem[9904 + i] = c2da_lin_extern_cl_main_8[i]
    }
    for (i in range(40)) {
        c2da_mem[9952 + i] = c2da_lin_extern_cl_main_9[i]
    }
    for (i in range(40)) {
        c2da_mem[10000 + i] = c2da_lin_extern_cl_main_10[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_cl_main() {
    if (length(c2da_fn_table0) < 38) {
        resize(c2da_fn_table0, 38)
    }
    c2da_fn_table0[37] = @@CL_Disconnect_f
    c2da_fn_table0[36] = @@CL_PrintEntities_f
}

[init]
def private c2da_lin_relink_init_cl_main() {
    c2da_relink_cl_main()
}
