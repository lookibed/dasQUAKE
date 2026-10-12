var svs : server_static_t = default<server_static_t>

[export, sideeffects]
def SV_Init() {
    Cvar_RegisterVariable(462544)
    Cvar_RegisterVariable(462592)
    Cvar_RegisterVariable(462640)
    Cvar_RegisterVariable(462688)
    Cvar_RegisterVariable(462736)
    Cvar_RegisterVariable(462784)
    Cvar_RegisterVariable(462832)
    Cvar_RegisterVariable(462880)
    Cvar_RegisterVariable(462928)
    Cvar_RegisterVariable(462976)
    for (i in range(0, 256)) {
        c2da_lin_snprintf(463024 + i * 5, 2147483647ul, 736144, [C2daVaArg(tag = 1, i64 = int64(i), f64 = 0.0lf, raw = 0x0)])
    }
    return
}
[export, sideeffects]
def SV_StartParticle(var org : int; var dir : int; var color : int; var count : int) {
    var v : int
    if (int(uint(c2da_mem[232732]) | uint(c2da_mem[232733]) << 0x8 | uint(c2da_mem[232734]) << 0x10 | uint(c2da_mem[232735]) << 0x18) > 1024 - 16) {
        return
    }
    MSG_WriteByte(232712, 18)
    MSG_WriteCoord(232712, uint_bits_to_float(uint(c2da_mem[org + 0 * 4]) | uint(c2da_mem[org + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[org + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[org + 0 * 4 + 3]) << 0x18))
    MSG_WriteCoord(232712, uint_bits_to_float(uint(c2da_mem[org + 1 * 4]) | uint(c2da_mem[org + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[org + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[org + 1 * 4 + 3]) << 0x18))
    MSG_WriteCoord(232712, uint_bits_to_float(uint(c2da_mem[org + 2 * 4]) | uint(c2da_mem[org + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[org + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[org + 2 * 4 + 3]) << 0x18))
    for (i_0 in range(0, 3)) {
        v = int(uint_bits_to_float(uint(c2da_mem[dir + i_0 * 4]) | uint(c2da_mem[dir + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[dir + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[dir + i_0 * 4 + 3]) << 0x18) * 16.0)
        if (v > 127) {
            v = 127
        } elif (v < -128) {
            v = -128
        }
        MSG_WriteChar(232712, v)
    }
    MSG_WriteByte(232712, count)
    MSG_WriteByte(232712, color)
    return
}
[export, sideeffects]
def SV_StartSound(var entity : int; var channel : int; var sample : int; var volume : int; var attenuation : float) {
    var sound_num : int
    var field_mask : int
    var ent : int
    if (volume < 0 || volume > 255) {
        Sys_Error(736148, [C2daVaArg(tag = 1, i64 = int64(volume), f64 = 0.0lf, raw = 0x0)])
    }
    if (attenuation < 0.0 || attenuation > 4.0) {
        Sys_Error(736175, [C2daVaArg(tag = 2, i64 = 0, f64 = double(attenuation), raw = 0x0)])
    }
    if (channel < 0 || channel > 7) {
        Sys_Error(736207, [C2daVaArg(tag = 1, i64 = int64(channel), f64 = 0.0lf, raw = 0x0)])
    }
    if (int(uint(c2da_mem[232732]) | uint(c2da_mem[232733]) << 0x8 | uint(c2da_mem[232734]) << 0x10 | uint(c2da_mem[232735]) << 0x18) > 1024 - 16) {
        return
    }
    sound_num = 1
    while (sound_num < 256 && int(uint(c2da_mem[230128 + sound_num * 8]) | uint(c2da_mem[230128 + sound_num * 8 + 1]) << 0x8 | uint(c2da_mem[230128 + sound_num * 8 + 2]) << 0x10 | uint(c2da_mem[230128 + sound_num * 8 + 3]) << 0x18) != 0) {
        if (c2da_lin_strcmp(sample, int(uint(c2da_mem[230128 + sound_num * 8]) | uint(c2da_mem[230128 + sound_num * 8 + 1]) << 0x8 | uint(c2da_mem[230128 + sound_num * 8 + 2]) << 0x10 | uint(c2da_mem[230128 + sound_num * 8 + 3]) << 0x18)) == 0) {
            break
        }
        sound_num++
    }
    if (sound_num == 256 || int(uint(c2da_mem[230128 + sound_num * 8]) | uint(c2da_mem[230128 + sound_num * 8 + 1]) << 0x8 | uint(c2da_mem[230128 + sound_num * 8 + 2]) << 0x10 | uint(c2da_mem[230128 + sound_num * 8 + 3]) << 0x18) == 0) {
        Con_Printf(736235, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(sample))])
        return
    }
    ent = NUM_FOR_EDICT(entity)
    channel = ent << 3 | channel
    field_mask = 0
    if (volume != 255) {
        field_mask |= 1 << 0
    }
    if (double(attenuation) != 1.0lf) {
        field_mask |= 1 << 1
    }
    MSG_WriteByte(232712, 6)
    MSG_WriteByte(232712, field_mask)
    if ((field_mask & 1 << 0) != 0) {
        MSG_WriteByte(232712, volume)
    }
    if ((field_mask & 1 << 1) != 0) {
        MSG_WriteByte(232712, int(attenuation * 64.0))
    }
    MSG_WriteShort(232712, channel)
    MSG_WriteByte(232712, sound_num)
    for (i_1 in range(0, 3)) {
        MSG_WriteCoord(232712, float(double(uint_bits_to_float(uint(c2da_mem[entity + 148 + i_1 * 4]) | uint(c2da_mem[entity + 148 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[entity + 148 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[entity + 148 + i_1 * 4 + 3]) << 0x18)) + 0.5lf * double(uint_bits_to_float(uint(c2da_mem[entity + 240 + i_1 * 4]) | uint(c2da_mem[entity + 240 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[entity + 240 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[entity + 240 + i_1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[entity + 252 + i_1 * 4]) | uint(c2da_mem[entity + 252 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[entity + 252 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[entity + 252 + i_1 * 4 + 3]) << 0x18))))
    }
    return
}
[export, sideeffects]
def SV_SendClientMessages() {
    var i_2 : int
    SV_UpdateToReliableMessages()
    i_2 = 0
    host_client = svs.clients
    while (i_2 < svs.maxclients) {
        if ((uint(c2da_mem[host_client]) | uint(c2da_mem[host_client + 1]) << 0x8 | uint(c2da_mem[host_client + 2]) << 0x10 | uint(c2da_mem[host_client + 3]) << 0x18) == 0u) {
            i_2++
            host_client = host_client + 8288
            continue
        }
        if ((uint(c2da_mem[host_client + 4]) | uint(c2da_mem[host_client + 5]) << 0x8 | uint(c2da_mem[host_client + 6]) << 0x10 | uint(c2da_mem[host_client + 7]) << 0x18) != 0u) {
            if (uint(SV_SendClientDatagram(host_client)) == 0u) {
                i_2++
                host_client = host_client + 8288
                continue
            }
        } elif ((uint(c2da_mem[host_client + 16]) | uint(c2da_mem[host_client + 17]) << 0x8 | uint(c2da_mem[host_client + 18]) << 0x10 | uint(c2da_mem[host_client + 19]) << 0x18) == 0u) {
            if (realtime - uint64_bits_to_double(uint64(uint(c2da_mem[host_client + 24]) | uint(c2da_mem[host_client + 25]) << 0x8 | uint(c2da_mem[host_client + 26]) << 0x10 | uint(c2da_mem[host_client + 27]) << 0x18) | uint64(uint(c2da_mem[host_client + 28]) | uint(c2da_mem[host_client + 29]) << 0x8 | uint(c2da_mem[host_client + 30]) << 0x10 | uint(c2da_mem[host_client + 31]) << 0x18) << 0x20) > 5.0lf) {
                SV_SendNop(host_client)
            }
            i_2++
            host_client = host_client + 8288
            continue
        }
        if ((uint(c2da_mem[host_client + 84]) | uint(c2da_mem[host_client + 85]) << 0x8 | uint(c2da_mem[host_client + 86]) << 0x10 | uint(c2da_mem[host_client + 87]) << 0x18) != 0u) {
            SV_DropClient(1u)
            let c2da_fresh0 : uint = 0u
            let c2da_fresh1 : uint = c2da_fresh0
            c2da_mem[host_client + 84] = uint8(c2da_fresh1)
            c2da_mem[host_client + 85] = uint8(c2da_fresh1 >> 0x8)
            c2da_mem[host_client + 86] = uint8(c2da_fresh1 >> 0x10)
            c2da_mem[host_client + 87] = uint8(c2da_fresh1 >> 0x18)
            i_2++
            host_client = host_client + 8288
            continue
        }
        if (int(uint(c2da_mem[host_client + 100]) | uint(c2da_mem[host_client + 101]) << 0x8 | uint(c2da_mem[host_client + 102]) << 0x10 | uint(c2da_mem[host_client + 103]) << 0x18) != 0 || (uint(c2da_mem[host_client + 8]) | uint(c2da_mem[host_client + 9]) << 0x8 | uint(c2da_mem[host_client + 10]) << 0x10 | uint(c2da_mem[host_client + 11]) << 0x18) != 0x0) {
            if (uint(NET_CanSendMessage(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18))) == 0u) {
                i_2++
                host_client = host_client + 8288
                continue
            }
            if ((uint(c2da_mem[host_client + 8]) | uint(c2da_mem[host_client + 9]) << 0x8 | uint(c2da_mem[host_client + 10]) << 0x10 | uint(c2da_mem[host_client + 11]) << 0x18) != 0u) {
                SV_DropClient(0u)
            } else {
                if (NET_SendMessage(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18), host_client + 80) == -1) {
                    SV_DropClient(1u)
                }
                SZ_Clear(host_client + 80)
                let c2da_fresh2 : uint64 = double_bits_to_uint64(realtime)
                c2da_mem[host_client + 24] = uint8(c2da_fresh2)
                c2da_mem[host_client + 25] = uint8(c2da_fresh2 >> 0x8)
                c2da_mem[host_client + 26] = uint8(c2da_fresh2 >> 0x10)
                c2da_mem[host_client + 27] = uint8(c2da_fresh2 >> 0x18)
                c2da_mem[host_client + 28] = uint8(c2da_fresh2 >> 0x20)
                c2da_mem[host_client + 29] = uint8(c2da_fresh2 >> 0x28)
                c2da_mem[host_client + 30] = uint8(c2da_fresh2 >> 0x30)
                c2da_mem[host_client + 31] = uint8(c2da_fresh2 >> 0x38)
                let c2da_fresh3 : uint = 0u
                let c2da_fresh4 : uint = c2da_fresh3
                c2da_mem[host_client + 16] = uint8(c2da_fresh4)
                c2da_mem[host_client + 17] = uint8(c2da_fresh4 >> 0x8)
                c2da_mem[host_client + 18] = uint8(c2da_fresh4 >> 0x10)
                c2da_mem[host_client + 19] = uint8(c2da_fresh4 >> 0x18)
            }
        }
        i_2++
        host_client = host_client + 8288
    }
    SV_CleanupEnts()
    return
}
[export, sideeffects]
def SV_CleanupEnts() {
    var e : int
    var ent_0 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(pr_edict_size)
    e = 1
    while (e < int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        let c2da_fresh5 : float = float(int(uint_bits_to_float(uint(c2da_mem[ent_0 + 236]) | uint(c2da_mem[ent_0 + 237]) << 0x8 | uint(c2da_mem[ent_0 + 238]) << 0x10 | uint(c2da_mem[ent_0 + 239]) << 0x18)) & ~2)
        let c2da_fresh6 : uint = float_bits_to_uint(c2da_fresh5)
        c2da_mem[ent_0 + 236] = uint8(c2da_fresh6)
        c2da_mem[ent_0 + 237] = uint8(c2da_fresh6 >> 0x8)
        c2da_mem[ent_0 + 238] = uint8(c2da_fresh6 >> 0x10)
        c2da_mem[ent_0 + 239] = uint8(c2da_fresh6 >> 0x18)
        e++
        ent_0 += int(pr_edict_size)
    }
    return
}
[export, sideeffects]
def SV_SendNop(var client : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_SendNop_c2da_frame(client, c2da_lin_enter(48))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def SV_SendClientDatagram(var client_0 : int) : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = SV_SendClientDatagram_c2da_frame(client_0, c2da_lin_enter(1056))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def SV_WriteEntitiesToClient(var clent : int; var msg : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_WriteEntitiesToClient_c2da_frame(clent, msg, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def SV_FatPVS(var org_0 : int) : int {
    let c2da_fresh27 : int = int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) + 152
    fatbytes = int(uint(c2da_mem[c2da_fresh27]) | uint(c2da_mem[c2da_fresh27 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh27 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh27 + 3]) << 0x18) + 31 >> 3
    Q_memset(464304, 0, fatbytes)
    let c2da_fresh28 : int = int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) + 208
    SV_AddToFatPVS(org_0, int(uint(c2da_mem[c2da_fresh28]) | uint(c2da_mem[c2da_fresh28 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh28 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh28 + 3]) << 0x18))
    return 464304
}
[export, sideeffects]
def SV_AddToFatPVS(var org_1 : int; var node : int) {
    var i_4 : int
    var pvs_0 : int
    var plane : int
    var d : float
    while (true) {
        if (int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18) < 0) {
            if (int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18) != -2) {
                pvs_0 = Mod_LeafPVS(node, int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18))
                i_4 = 0
                while (i_4 < fatbytes) {
                    let c2da_fresh29 : uint8 = uint8(int(c2da_mem[464304 + i_4]) | int(c2da_mem[pvs_0 + i_4]))
                    c2da_mem[464304 + i_4] = c2da_fresh29
                    i_4++
                }
            }
            return
        }
        plane = int(uint(c2da_mem[node + 32]) | uint(c2da_mem[node + 33]) << 0x8 | uint(c2da_mem[node + 34]) << 0x10 | uint(c2da_mem[node + 35]) << 0x18)
        d = uint_bits_to_float(uint(c2da_mem[org_1 + 0 * 4]) | uint(c2da_mem[org_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[org_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[org_1 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 0 * 4]) | uint(c2da_mem[plane + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[org_1 + 1 * 4]) | uint(c2da_mem[org_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[org_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[org_1 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 1 * 4]) | uint(c2da_mem[plane + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[org_1 + 2 * 4]) | uint(c2da_mem[org_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[org_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[org_1 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 2 * 4]) | uint(c2da_mem[plane + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane + 12]) | uint(c2da_mem[plane + 13]) << 0x8 | uint(c2da_mem[plane + 14]) << 0x10 | uint(c2da_mem[plane + 15]) << 0x18)
        if (d > 8.0) {
            node = int(uint(c2da_mem[node + 40 + 0 * 8]) | uint(c2da_mem[node + 40 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[node + 40 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[node + 40 + 0 * 8 + 3]) << 0x18)
        } elif (d < -8.0) {
            node = int(uint(c2da_mem[node + 40 + 1 * 8]) | uint(c2da_mem[node + 40 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[node + 40 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[node + 40 + 1 * 8 + 3]) << 0x18)
        } else {
            SV_AddToFatPVS(org_1, int(uint(c2da_mem[node + 40 + 0 * 8]) | uint(c2da_mem[node + 40 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[node + 40 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[node + 40 + 0 * 8 + 3]) << 0x18))
            node = int(uint(c2da_mem[node + 40 + 1 * 8]) | uint(c2da_mem[node + 40 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[node + 40 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[node + 40 + 1 * 8 + 3]) << 0x18)
        }
    }
}
var fatbytes : int = default<int>

[export, sideeffects]
def SV_WriteClientdataToMessage(var ent_2 : int; var msg_0 : int) {
    var bits_0 : int
    var i_5 : int
    var other : int
    var items : int
    var val : int
    if (uint_bits_to_float(uint(c2da_mem[ent_2 + 476]) | uint(c2da_mem[ent_2 + 477]) << 0x8 | uint(c2da_mem[ent_2 + 478]) << 0x10 | uint(c2da_mem[ent_2 + 479]) << 0x18) != 0.0 || uint_bits_to_float(uint(c2da_mem[ent_2 + 480]) | uint(c2da_mem[ent_2 + 481]) << 0x8 | uint(c2da_mem[ent_2 + 482]) << 0x10 | uint(c2da_mem[ent_2 + 483]) << 0x18) != 0.0) {
        other = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[ent_2 + 484]) | uint(c2da_mem[ent_2 + 485]) << 0x8 | uint(c2da_mem[ent_2 + 486]) << 0x10 | uint(c2da_mem[ent_2 + 487]) << 0x18)
        MSG_WriteByte(msg_0, 19)
        MSG_WriteByte(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 480]) | uint(c2da_mem[ent_2 + 481]) << 0x8 | uint(c2da_mem[ent_2 + 482]) << 0x10 | uint(c2da_mem[ent_2 + 483]) << 0x18)))
        MSG_WriteByte(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 476]) | uint(c2da_mem[ent_2 + 477]) << 0x8 | uint(c2da_mem[ent_2 + 478]) << 0x10 | uint(c2da_mem[ent_2 + 479]) << 0x18)))
        i_5 = 0
        while (i_5 < 3) {
            MSG_WriteCoord(msg_0, float(double(uint_bits_to_float(uint(c2da_mem[other + 148 + i_5 * 4]) | uint(c2da_mem[other + 148 + i_5 * 4 + 1]) << 0x8 | uint(c2da_mem[other + 148 + i_5 * 4 + 2]) << 0x10 | uint(c2da_mem[other + 148 + i_5 * 4 + 3]) << 0x18)) + 0.5lf * double(uint_bits_to_float(uint(c2da_mem[other + 240 + i_5 * 4]) | uint(c2da_mem[other + 240 + i_5 * 4 + 1]) << 0x8 | uint(c2da_mem[other + 240 + i_5 * 4 + 2]) << 0x10 | uint(c2da_mem[other + 240 + i_5 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[other + 252 + i_5 * 4]) | uint(c2da_mem[other + 252 + i_5 * 4 + 1]) << 0x8 | uint(c2da_mem[other + 252 + i_5 * 4 + 2]) << 0x10 | uint(c2da_mem[other + 252 + i_5 * 4 + 3]) << 0x18))))
            i_5++
        }
        let c2da_fresh30 : float = 0.0
        let c2da_fresh31 : uint = float_bits_to_uint(c2da_fresh30)
        c2da_mem[ent_2 + 476] = uint8(c2da_fresh31)
        c2da_mem[ent_2 + 477] = uint8(c2da_fresh31 >> 0x8)
        c2da_mem[ent_2 + 478] = uint8(c2da_fresh31 >> 0x10)
        c2da_mem[ent_2 + 479] = uint8(c2da_fresh31 >> 0x18)
        let c2da_fresh32 : float = 0.0
        let c2da_fresh33 : uint = float_bits_to_uint(c2da_fresh32)
        c2da_mem[ent_2 + 480] = uint8(c2da_fresh33)
        c2da_mem[ent_2 + 481] = uint8(c2da_fresh33 >> 0x8)
        c2da_mem[ent_2 + 482] = uint8(c2da_fresh33 >> 0x10)
        c2da_mem[ent_2 + 483] = uint8(c2da_fresh33 >> 0x18)
    }
    SV_SetIdealPitch()
    if (uint_bits_to_float(uint(c2da_mem[ent_2 + 384]) | uint(c2da_mem[ent_2 + 385]) << 0x8 | uint(c2da_mem[ent_2 + 386]) << 0x10 | uint(c2da_mem[ent_2 + 387]) << 0x18) != 0.0) {
        MSG_WriteByte(msg_0, 10)
        i_5 = 0
        while (i_5 < 3) {
            MSG_WriteAngle(msg_0, uint_bits_to_float(uint(c2da_mem[ent_2 + 184 + i_5 * 4]) | uint(c2da_mem[ent_2 + 184 + i_5 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 184 + i_5 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 184 + i_5 * 4 + 3]) << 0x18))
            i_5++
        }
        let c2da_fresh34 : float = 0.0
        let c2da_fresh35 : uint = float_bits_to_uint(c2da_fresh34)
        c2da_mem[ent_2 + 384] = uint8(c2da_fresh35)
        c2da_mem[ent_2 + 385] = uint8(c2da_fresh35 >> 0x8)
        c2da_mem[ent_2 + 386] = uint8(c2da_fresh35 >> 0x10)
        c2da_mem[ent_2 + 387] = uint8(c2da_fresh35 >> 0x18)
    }
    bits_0 = 0
    if (uint_bits_to_float(uint(c2da_mem[ent_2 + 356 + 2 * 4]) | uint(c2da_mem[ent_2 + 356 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 356 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 356 + 2 * 4 + 3]) << 0x18) != 22.0) {
        bits_0 |= 1 << 0
    }
    if (uint_bits_to_float(uint(c2da_mem[ent_2 + 400]) | uint(c2da_mem[ent_2 + 401]) << 0x8 | uint(c2da_mem[ent_2 + 402]) << 0x10 | uint(c2da_mem[ent_2 + 403]) << 0x18) != 0.0) {
        bits_0 |= 1 << 1
    }
    val = GetEdictFieldValue(ent_2, 736286)
    if (val != 0) {
        items = int(uint_bits_to_float(uint(c2da_mem[ent_2 + 340]) | uint(c2da_mem[ent_2 + 341]) << 0x8 | uint(c2da_mem[ent_2 + 342]) << 0x10 | uint(c2da_mem[ent_2 + 343]) << 0x18)) | int(uint_bits_to_float(uint(c2da_mem[val]) | uint(c2da_mem[val + 1]) << 0x8 | uint(c2da_mem[val + 2]) << 0x10 | uint(c2da_mem[val + 3]) << 0x18)) << 23
    } else {
        items = int(uint_bits_to_float(uint(c2da_mem[ent_2 + 340]) | uint(c2da_mem[ent_2 + 341]) << 0x8 | uint(c2da_mem[ent_2 + 342]) << 0x10 | uint(c2da_mem[ent_2 + 343]) << 0x18)) | int(uint_bits_to_float(uint(c2da_mem[pr_global_struct + 152]) | uint(c2da_mem[pr_global_struct + 153]) << 0x8 | uint(c2da_mem[pr_global_struct + 154]) << 0x10 | uint(c2da_mem[pr_global_struct + 155]) << 0x18)) << 28
    }
    bits_0 |= 1 << 9
    if ((int(uint_bits_to_float(uint(c2da_mem[ent_2 + 412]) | uint(c2da_mem[ent_2 + 413]) << 0x8 | uint(c2da_mem[ent_2 + 414]) << 0x10 | uint(c2da_mem[ent_2 + 415]) << 0x18)) & 512) != 0) {
        bits_0 |= 1 << 10
    }
    if (uint_bits_to_float(uint(c2da_mem[ent_2 + 440]) | uint(c2da_mem[ent_2 + 441]) << 0x8 | uint(c2da_mem[ent_2 + 442]) << 0x10 | uint(c2da_mem[ent_2 + 443]) << 0x18) >= 2.0) {
        bits_0 |= 1 << 11
    }
    i_5 = 0
    while (i_5 < 3) {
        if (uint_bits_to_float(uint(c2da_mem[ent_2 + 208 + i_5 * 4]) | uint(c2da_mem[ent_2 + 208 + i_5 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 208 + i_5 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 208 + i_5 * 4 + 3]) << 0x18) != 0.0) {
            bits_0 |= 1 << 2 << i_5
        }
        if (uint_bits_to_float(uint(c2da_mem[ent_2 + 172 + i_5 * 4]) | uint(c2da_mem[ent_2 + 172 + i_5 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 172 + i_5 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 172 + i_5 * 4 + 3]) << 0x18) != 0.0) {
            bits_0 |= 1 << 5 << i_5
        }
        i_5++
    }
    if (uint_bits_to_float(uint(c2da_mem[ent_2 + 316]) | uint(c2da_mem[ent_2 + 317]) << 0x8 | uint(c2da_mem[ent_2 + 318]) << 0x10 | uint(c2da_mem[ent_2 + 319]) << 0x18) != 0.0) {
        bits_0 |= 1 << 12
    }
    if (uint_bits_to_float(uint(c2da_mem[ent_2 + 436]) | uint(c2da_mem[ent_2 + 437]) << 0x8 | uint(c2da_mem[ent_2 + 438]) << 0x10 | uint(c2da_mem[ent_2 + 439]) << 0x18) != 0.0) {
        bits_0 |= 1 << 13
    }
    bits_0 |= 1 << 14
    MSG_WriteByte(msg_0, 15)
    MSG_WriteShort(msg_0, bits_0)
    if ((bits_0 & 1 << 0) != 0) {
        MSG_WriteChar(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 356 + 2 * 4]) | uint(c2da_mem[ent_2 + 356 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 356 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 356 + 2 * 4 + 3]) << 0x18)))
    }
    if ((bits_0 & 1 << 1) != 0) {
        MSG_WriteChar(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 400]) | uint(c2da_mem[ent_2 + 401]) << 0x8 | uint(c2da_mem[ent_2 + 402]) << 0x10 | uint(c2da_mem[ent_2 + 403]) << 0x18)))
    }
    i_5 = 0
    while (i_5 < 3) {
        if ((bits_0 & 1 << 2 << i_5) != 0) {
            MSG_WriteChar(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 208 + i_5 * 4]) | uint(c2da_mem[ent_2 + 208 + i_5 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 208 + i_5 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 208 + i_5 * 4 + 3]) << 0x18)))
        }
        if ((bits_0 & 1 << 5 << i_5) != 0) {
            MSG_WriteChar(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 172 + i_5 * 4]) | uint(c2da_mem[ent_2 + 172 + i_5 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 172 + i_5 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 172 + i_5 * 4 + 3]) << 0x18) / 16.0))
        }
        i_5++
    }
    MSG_WriteLong(msg_0, items)
    if ((bits_0 & 1 << 12) != 0) {
        MSG_WriteByte(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 316]) | uint(c2da_mem[ent_2 + 317]) << 0x8 | uint(c2da_mem[ent_2 + 318]) << 0x10 | uint(c2da_mem[ent_2 + 319]) << 0x18)))
    }
    if ((bits_0 & 1 << 13) != 0) {
        MSG_WriteByte(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 436]) | uint(c2da_mem[ent_2 + 437]) << 0x8 | uint(c2da_mem[ent_2 + 438]) << 0x10 | uint(c2da_mem[ent_2 + 439]) << 0x18)))
    }
    if ((bits_0 & 1 << 14) != 0) {
        MSG_WriteByte(msg_0, SV_ModelIndex(pr_strings + int(uint(c2da_mem[ent_2 + 312]) | uint(c2da_mem[ent_2 + 313]) << 0x8 | uint(c2da_mem[ent_2 + 314]) << 0x10 | uint(c2da_mem[ent_2 + 315]) << 0x18)))
    }
    MSG_WriteShort(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 300]) | uint(c2da_mem[ent_2 + 301]) << 0x8 | uint(c2da_mem[ent_2 + 302]) << 0x10 | uint(c2da_mem[ent_2 + 303]) << 0x18)))
    MSG_WriteByte(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 320]) | uint(c2da_mem[ent_2 + 321]) << 0x8 | uint(c2da_mem[ent_2 + 322]) << 0x10 | uint(c2da_mem[ent_2 + 323]) << 0x18)))
    MSG_WriteByte(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 324]) | uint(c2da_mem[ent_2 + 325]) << 0x8 | uint(c2da_mem[ent_2 + 326]) << 0x10 | uint(c2da_mem[ent_2 + 327]) << 0x18)))
    MSG_WriteByte(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 328]) | uint(c2da_mem[ent_2 + 329]) << 0x8 | uint(c2da_mem[ent_2 + 330]) << 0x10 | uint(c2da_mem[ent_2 + 331]) << 0x18)))
    MSG_WriteByte(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 332]) | uint(c2da_mem[ent_2 + 333]) << 0x8 | uint(c2da_mem[ent_2 + 334]) << 0x10 | uint(c2da_mem[ent_2 + 335]) << 0x18)))
    MSG_WriteByte(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 336]) | uint(c2da_mem[ent_2 + 337]) << 0x8 | uint(c2da_mem[ent_2 + 338]) << 0x10 | uint(c2da_mem[ent_2 + 339]) << 0x18)))
    if (uint(standard_quake) != 0u) {
        MSG_WriteByte(msg_0, int(uint_bits_to_float(uint(c2da_mem[ent_2 + 308]) | uint(c2da_mem[ent_2 + 309]) << 0x8 | uint(c2da_mem[ent_2 + 310]) << 0x10 | uint(c2da_mem[ent_2 + 311]) << 0x18)))
    } else {
        i_5 = 0
        for (c2da_i_5 in range(i_5, 32)) {
            if ((int(uint_bits_to_float(uint(c2da_mem[ent_2 + 308]) | uint(c2da_mem[ent_2 + 309]) << 0x8 | uint(c2da_mem[ent_2 + 310]) << 0x10 | uint(c2da_mem[ent_2 + 311]) << 0x18)) & 1 << c2da_i_5) != 0) {
                MSG_WriteByte(msg_0, c2da_i_5)
                break
            }
        }
    }
    return
}
[export, sideeffects]
def SV_ModelIndex(var name : int) : int {
    var i_6 : int
    if (name == 0 || int8(c2da_mem[name + 0]) == 0) {
        return 0
    }
    i_6 = 0
    while (i_6 < 256 && int(uint(c2da_mem[226032 + i_6 * 8]) | uint(c2da_mem[226032 + i_6 * 8 + 1]) << 0x8 | uint(c2da_mem[226032 + i_6 * 8 + 2]) << 0x10 | uint(c2da_mem[226032 + i_6 * 8 + 3]) << 0x18) != 0) {
        if (c2da_lin_strcmp(int(uint(c2da_mem[226032 + i_6 * 8]) | uint(c2da_mem[226032 + i_6 * 8 + 1]) << 0x8 | uint(c2da_mem[226032 + i_6 * 8 + 2]) << 0x10 | uint(c2da_mem[226032 + i_6 * 8 + 3]) << 0x18), name) == 0) {
            return i_6
        }
        i_6++
    }
    if (i_6 == 256 || int(uint(c2da_mem[226032 + i_6 * 8]) | uint(c2da_mem[226032 + i_6 * 8 + 1]) << 0x8 | uint(c2da_mem[226032 + i_6 * 8 + 2]) << 0x10 | uint(c2da_mem[226032 + i_6 * 8 + 3]) << 0x18) == 0) {
        Sys_Error(736293, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(name))])
    }
    return i_6
}
[export, sideeffects]
def SV_UpdateToReliableMessages() {
    var i_7 : int
    var j : int
    var client_1 : int
    i_7 = 0
    host_client = svs.clients
    while (i_7 < svs.maxclients) {
        let c2da_fresh36 : int = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18) + 304
        if (float(int(uint(c2da_mem[host_client + 8280]) | uint(c2da_mem[host_client + 8281]) << 0x8 | uint(c2da_mem[host_client + 8282]) << 0x10 | uint(c2da_mem[host_client + 8283]) << 0x18)) != uint_bits_to_float(uint(c2da_mem[c2da_fresh36]) | uint(c2da_mem[c2da_fresh36 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh36 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh36 + 3]) << 0x18)) {
            j = 0
            client_1 = svs.clients
            while (j < svs.maxclients) {
                if ((uint(c2da_mem[client_1]) | uint(c2da_mem[client_1 + 1]) << 0x8 | uint(c2da_mem[client_1 + 2]) << 0x10 | uint(c2da_mem[client_1 + 3]) << 0x18) == 0u) {
                    j++
                    client_1 += 8288
                    continue
                }
                MSG_WriteByte(client_1 + 80, 14)
                MSG_WriteByte(client_1 + 80, i_7)
                let c2da_fresh37 : int = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18) + 304
                MSG_WriteShort(client_1 + 80, int(uint_bits_to_float(uint(c2da_mem[c2da_fresh37]) | uint(c2da_mem[c2da_fresh37 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh37 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh37 + 3]) << 0x18)))
                j++
                client_1 += 8288
            }
            let c2da_fresh38 : int = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18) + 304
            let c2da_fresh39 : int = int(uint_bits_to_float(uint(c2da_mem[c2da_fresh38]) | uint(c2da_mem[c2da_fresh38 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh38 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh38 + 3]) << 0x18))
            let c2da_fresh40 : uint = uint(c2da_fresh39)
            c2da_mem[host_client + 8280] = uint8(c2da_fresh40)
            c2da_mem[host_client + 8281] = uint8(c2da_fresh40 >> 0x8)
            c2da_mem[host_client + 8282] = uint8(c2da_fresh40 >> 0x10)
            c2da_mem[host_client + 8283] = uint8(c2da_fresh40 >> 0x18)
        }
        i_7++
        host_client = host_client + 8288
    }
    j = 0
    client_1 = svs.clients
    while (j < svs.maxclients) {
        if ((uint(c2da_mem[client_1]) | uint(c2da_mem[client_1 + 1]) << 0x8 | uint(c2da_mem[client_1 + 2]) << 0x10 | uint(c2da_mem[client_1 + 3]) << 0x18) == 0u) {
            j++
            client_1 += 8288
            continue
        }
        SZ_Write(client_1 + 80, int(uint(c2da_mem[233768]) | uint(c2da_mem[233769]) << 0x8 | uint(c2da_mem[233770]) << 0x10 | uint(c2da_mem[233771]) << 0x18), int(uint(c2da_mem[233780]) | uint(c2da_mem[233781]) << 0x8 | uint(c2da_mem[233782]) << 0x10 | uint(c2da_mem[233783]) << 0x18))
        j++
        client_1 += 8288
    }
    SZ_Clear(233760)
    return
}
[export, sideeffects]
def SV_ClearDatagram() {
    SZ_Clear(232712)
    return
}
[export, sideeffects]
def SV_CheckForNewClients() {
    var ret : int
    var i_8 : int
    while (true) {
        ret = NET_CheckNewConnections()
        if (ret == 0) {
            break
        }
        i_8 = 0
        while (i_8 < svs.maxclients) {
            let c2da_fresh41 : int = svs.clients + i_8 * 8288
            if ((uint(c2da_mem[c2da_fresh41]) | uint(c2da_mem[c2da_fresh41 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh41 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh41 + 3]) << 0x18) == 0u) {
                break
            }
            i_8++
        }
        if (i_8 == svs.maxclients) {
            Sys_Error(736331, [])
        }
        let c2da_fresh42 : int = svs.clients + i_8 * 8288 + 32
        let c2da_fresh43 : uint = uint(ret)
        c2da_mem[c2da_fresh42] = uint8(c2da_fresh43)
        c2da_mem[c2da_fresh42 + 1] = uint8(c2da_fresh43 >> 0x8)
        c2da_mem[c2da_fresh42 + 2] = uint8(c2da_fresh43 >> 0x10)
        c2da_mem[c2da_fresh42 + 3] = uint8(c2da_fresh43 >> 0x18)
        c2da_mem[c2da_fresh42 + 4] = 0u8
        c2da_mem[c2da_fresh42 + 5] = 0u8
        c2da_mem[c2da_fresh42 + 6] = 0u8
        c2da_mem[c2da_fresh42 + 7] = 0u8
        SV_ConnectClient(i_8)
        net_activeconnections = net_activeconnections + 1
    }
    return
}
[export, sideeffects]
def SV_ConnectClient(var clientnum : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_ConnectClient_c2da_frame(clientnum, c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def SV_SendServerinfo(var client_3 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_SendServerinfo_c2da_frame(client_3, c2da_lin_enter(2048))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def SV_SaveSpawnparms() {
    var i_10 : int
    svs.serverflags = int(uint_bits_to_float(uint(c2da_mem[pr_global_struct + 152]) | uint(c2da_mem[pr_global_struct + 153]) << 0x8 | uint(c2da_mem[pr_global_struct + 154]) << 0x10 | uint(c2da_mem[pr_global_struct + 155]) << 0x18))
    i_10 = 0
    host_client = svs.clients
    while (i_10 < svs.maxclients) {
        if ((uint(c2da_mem[host_client]) | uint(c2da_mem[host_client + 1]) << 0x8 | uint(c2da_mem[host_client + 2]) << 0x10 | uint(c2da_mem[host_client + 3]) << 0x18) == 0u) {
            i_10++
            host_client = host_client + 8288
            continue
        }
        let c2da_fresh67 : int = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18) - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh68 : uint = uint(c2da_fresh67)
        c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh68)
        c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh68 >> 0x8)
        c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh68 >> 0x10)
        c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh68 >> 0x18)
        PR_ExecuteProgram(int(uint(c2da_mem[pr_global_struct + 364]) | uint(c2da_mem[pr_global_struct + 365]) << 0x8 | uint(c2da_mem[pr_global_struct + 366]) << 0x10 | uint(c2da_mem[pr_global_struct + 367]) << 0x18))
        for (j_0 in range(0, 16)) {
            let c2da_fresh69 : float = uint_bits_to_float(uint(c2da_mem[pr_global_struct + 172 + j_0 * 4]) | uint(c2da_mem[pr_global_struct + 172 + j_0 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_global_struct + 172 + j_0 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_global_struct + 172 + j_0 * 4 + 3]) << 0x18)
            let c2da_fresh70 : uint = float_bits_to_uint(c2da_fresh69)
            c2da_mem[host_client + 8216 + j_0 * 4] = uint8(c2da_fresh70)
            c2da_mem[host_client + 8216 + j_0 * 4 + 1] = uint8(c2da_fresh70 >> 0x8)
            c2da_mem[host_client + 8216 + j_0 * 4 + 2] = uint8(c2da_fresh70 >> 0x10)
            c2da_mem[host_client + 8216 + j_0 * 4 + 3] = uint8(c2da_fresh70 >> 0x18)
        }
        i_10++
        host_client = host_client + 8288
    }
    return
}
[export, sideeffects]
def SV_SpawnServer(var server : int) {
    var ent_4 : int
    var i_11 : int
    let c2da_fresh71 : int = int(uint(c2da_mem[386472]) | uint(c2da_mem[386473]) << 0x8 | uint(c2da_mem[386474]) << 0x10 | uint(c2da_mem[386475]) << 0x18) + 0
    if (int(int8(c2da_mem[c2da_fresh71])) == 0) {
        Cvar_Set(736438, 736447)
    }
    scr_centertime_off = 0.0
    Con_DPrintf(736455, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(server))])
    svs.changelevel_issued = 0u
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) != 0u) {
        SV_SendReconnect()
    }
    if (uint_bits_to_float(uint(c2da_mem[243752]) | uint(c2da_mem[243753]) << 0x8 | uint(c2da_mem[243754]) << 0x10 | uint(c2da_mem[243755]) << 0x18) != 0.0) {
        Cvar_SetValue(736472, 0.0)
    }
    current_skill = int(double(uint_bits_to_float(uint(c2da_mem[243608]) | uint(c2da_mem[243609]) << 0x8 | uint(c2da_mem[243610]) << 0x10 | uint(c2da_mem[243611]) << 0x18)) + 0.5lf)
    if (current_skill < 0) {
        current_skill = 0
    }
    if (current_skill > 3) {
        current_skill = 3
    }
    Cvar_SetValue(736483, float(current_skill))
    Host_ClearMemory()
    c2da_lin_memset(225856, 0, 17168ul)
    c2da_lin_strcpy(225896, server)
    PR_LoadProgs()
    let c2da_fresh72 : int = 600
    let c2da_fresh73 : uint = uint(c2da_fresh72)
    c2da_mem[232692] = uint8(c2da_fresh73)
    c2da_mem[232693] = uint8(c2da_fresh73 >> 0x8)
    c2da_mem[232694] = uint8(c2da_fresh73 >> 0x10)
    c2da_mem[232695] = uint8(c2da_fresh73 >> 0x18)
    let c2da_fresh74 : int = Hunk_AllocName(int(uint(c2da_mem[232692]) | uint(c2da_mem[232693]) << 0x8 | uint(c2da_mem[232694]) << 0x10 | uint(c2da_mem[232695]) << 0x18) * pr_edict_size, 736489)
    let c2da_fresh75 : uint = uint(c2da_fresh74)
    c2da_mem[232696] = uint8(c2da_fresh75)
    c2da_mem[232697] = uint8(c2da_fresh75 >> 0x8)
    c2da_mem[232698] = uint8(c2da_fresh75 >> 0x10)
    c2da_mem[232699] = uint8(c2da_fresh75 >> 0x18)
    c2da_mem[232700] = 0u8
    c2da_mem[232701] = 0u8
    c2da_mem[232702] = 0u8
    c2da_mem[232703] = 0u8
    let c2da_fresh76 : int = 1024
    let c2da_fresh77 : uint = uint(c2da_fresh76)
    c2da_mem[232728] = uint8(c2da_fresh77)
    c2da_mem[232729] = uint8(c2da_fresh77 >> 0x8)
    c2da_mem[232730] = uint8(c2da_fresh77 >> 0x10)
    c2da_mem[232731] = uint8(c2da_fresh77 >> 0x18)
    let c2da_fresh78 : int = 0
    let c2da_fresh79 : uint = uint(c2da_fresh78)
    c2da_mem[232732] = uint8(c2da_fresh79)
    c2da_mem[232733] = uint8(c2da_fresh79 >> 0x8)
    c2da_mem[232734] = uint8(c2da_fresh79 >> 0x10)
    c2da_mem[232735] = uint8(c2da_fresh79 >> 0x18)
    let c2da_fresh80 : uint = 232736u
    c2da_mem[232720] = uint8(c2da_fresh80)
    c2da_mem[232721] = uint8(c2da_fresh80 >> 0x8)
    c2da_mem[232722] = uint8(c2da_fresh80 >> 0x10)
    c2da_mem[232723] = uint8(c2da_fresh80 >> 0x18)
    c2da_mem[232724] = 0u8
    c2da_mem[232725] = 0u8
    c2da_mem[232726] = 0u8
    c2da_mem[232727] = 0u8
    let c2da_fresh81 : int = 1024
    let c2da_fresh82 : uint = uint(c2da_fresh81)
    c2da_mem[233776] = uint8(c2da_fresh82)
    c2da_mem[233777] = uint8(c2da_fresh82 >> 0x8)
    c2da_mem[233778] = uint8(c2da_fresh82 >> 0x10)
    c2da_mem[233779] = uint8(c2da_fresh82 >> 0x18)
    let c2da_fresh83 : int = 0
    let c2da_fresh84 : uint = uint(c2da_fresh83)
    c2da_mem[233780] = uint8(c2da_fresh84)
    c2da_mem[233781] = uint8(c2da_fresh84 >> 0x8)
    c2da_mem[233782] = uint8(c2da_fresh84 >> 0x10)
    c2da_mem[233783] = uint8(c2da_fresh84 >> 0x18)
    let c2da_fresh85 : uint = 233784u
    c2da_mem[233768] = uint8(c2da_fresh85)
    c2da_mem[233769] = uint8(c2da_fresh85 >> 0x8)
    c2da_mem[233770] = uint8(c2da_fresh85 >> 0x10)
    c2da_mem[233771] = uint8(c2da_fresh85 >> 0x18)
    c2da_mem[233772] = 0u8
    c2da_mem[233773] = 0u8
    c2da_mem[233774] = 0u8
    c2da_mem[233775] = 0u8
    let c2da_fresh86 : int = 8192
    let c2da_fresh87 : uint = uint(c2da_fresh86)
    c2da_mem[234824] = uint8(c2da_fresh87)
    c2da_mem[234825] = uint8(c2da_fresh87 >> 0x8)
    c2da_mem[234826] = uint8(c2da_fresh87 >> 0x10)
    c2da_mem[234827] = uint8(c2da_fresh87 >> 0x18)
    let c2da_fresh88 : int = 0
    let c2da_fresh89 : uint = uint(c2da_fresh88)
    c2da_mem[234828] = uint8(c2da_fresh89)
    c2da_mem[234829] = uint8(c2da_fresh89 >> 0x8)
    c2da_mem[234830] = uint8(c2da_fresh89 >> 0x10)
    c2da_mem[234831] = uint8(c2da_fresh89 >> 0x18)
    let c2da_fresh90 : uint = 234832u
    c2da_mem[234816] = uint8(c2da_fresh90)
    c2da_mem[234817] = uint8(c2da_fresh90 >> 0x8)
    c2da_mem[234818] = uint8(c2da_fresh90 >> 0x10)
    c2da_mem[234819] = uint8(c2da_fresh90 >> 0x18)
    c2da_mem[234820] = 0u8
    c2da_mem[234821] = 0u8
    c2da_mem[234822] = 0u8
    c2da_mem[234823] = 0u8
    let c2da_fresh91 : int = svs.maxclients + 1
    let c2da_fresh92 : uint = uint(c2da_fresh91)
    c2da_mem[232688] = uint8(c2da_fresh92)
    c2da_mem[232689] = uint8(c2da_fresh92 >> 0x8)
    c2da_mem[232690] = uint8(c2da_fresh92 >> 0x10)
    c2da_mem[232691] = uint8(c2da_fresh92 >> 0x18)
    i_11 = 0
    while (i_11 < svs.maxclients) {
        ent_4 = EDICT_NUM(i_11 + 1)
        let c2da_fresh93 : int = svs.clients + i_11 * 8288 + 8104
        let c2da_fresh94 : uint = uint(ent_4)
        c2da_mem[c2da_fresh93] = uint8(c2da_fresh94)
        c2da_mem[c2da_fresh93 + 1] = uint8(c2da_fresh94 >> 0x8)
        c2da_mem[c2da_fresh93 + 2] = uint8(c2da_fresh94 >> 0x10)
        c2da_mem[c2da_fresh93 + 3] = uint8(c2da_fresh94 >> 0x18)
        c2da_mem[c2da_fresh93 + 4] = 0u8
        c2da_mem[c2da_fresh93 + 5] = 0u8
        c2da_mem[c2da_fresh93 + 6] = 0u8
        c2da_mem[c2da_fresh93 + 7] = 0u8
        i_11++
    }
    let c2da_fresh95 : uint = 0u
    let c2da_fresh96 : uint = c2da_fresh95
    c2da_mem[232704] = uint8(c2da_fresh96)
    c2da_mem[232705] = uint8(c2da_fresh96 >> 0x8)
    c2da_mem[232706] = uint8(c2da_fresh96 >> 0x10)
    c2da_mem[232707] = uint8(c2da_fresh96 >> 0x18)
    let c2da_fresh97 : uint = 0u
    let c2da_fresh98 : uint = c2da_fresh97
    c2da_mem[225860] = uint8(c2da_fresh98)
    c2da_mem[225861] = uint8(c2da_fresh98 >> 0x8)
    c2da_mem[225862] = uint8(c2da_fresh98 >> 0x10)
    c2da_mem[225863] = uint8(c2da_fresh98 >> 0x18)
    let c2da_fresh99 : double = 1.0lf
    let c2da_fresh100 : uint64 = double_bits_to_uint64(c2da_fresh99)
    c2da_mem[225872] = uint8(c2da_fresh100)
    c2da_mem[225873] = uint8(c2da_fresh100 >> 0x8)
    c2da_mem[225874] = uint8(c2da_fresh100 >> 0x10)
    c2da_mem[225875] = uint8(c2da_fresh100 >> 0x18)
    c2da_mem[225876] = uint8(c2da_fresh100 >> 0x20)
    c2da_mem[225877] = uint8(c2da_fresh100 >> 0x28)
    c2da_mem[225878] = uint8(c2da_fresh100 >> 0x30)
    c2da_mem[225879] = uint8(c2da_fresh100 >> 0x38)
    c2da_lin_strcpy(225896, server)
    c2da_lin_snprintf(225960, 2147483647ul, 736496, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(server))])
    let c2da_fresh101 : int = Mod_ForName(225960, 0u)
    let c2da_fresh102 : uint = uint(c2da_fresh101)
    c2da_mem[226024] = uint8(c2da_fresh102)
    c2da_mem[226025] = uint8(c2da_fresh102 >> 0x8)
    c2da_mem[226026] = uint8(c2da_fresh102 >> 0x10)
    c2da_mem[226027] = uint8(c2da_fresh102 >> 0x18)
    c2da_mem[226028] = 0u8
    c2da_mem[226029] = 0u8
    c2da_mem[226030] = 0u8
    c2da_mem[226031] = 0u8
    if (int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) == 0) {
        Con_Printf(736508, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 225960ul)])
        let c2da_fresh103 : uint = 0u
        let c2da_fresh104 : uint = c2da_fresh103
        c2da_mem[225856] = uint8(c2da_fresh104)
        c2da_mem[225857] = uint8(c2da_fresh104 >> 0x8)
        c2da_mem[225858] = uint8(c2da_fresh104 >> 0x10)
        c2da_mem[225859] = uint8(c2da_fresh104 >> 0x18)
        return
    }
    let c2da_fresh105 : int = int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18)
    let c2da_fresh106 : uint = uint(c2da_fresh105)
    c2da_mem[228080 + 1 * 8] = uint8(c2da_fresh106)
    c2da_mem[228080 + 1 * 8 + 1] = uint8(c2da_fresh106 >> 0x8)
    c2da_mem[228080 + 1 * 8 + 2] = uint8(c2da_fresh106 >> 0x10)
    c2da_mem[228080 + 1 * 8 + 3] = uint8(c2da_fresh106 >> 0x18)
    c2da_mem[228080 + 1 * 8 + 4] = 0u8
    c2da_mem[228080 + 1 * 8 + 5] = 0u8
    c2da_mem[228080 + 1 * 8 + 6] = 0u8
    c2da_mem[228080 + 1 * 8 + 7] = 0u8
    SV_ClearWorld()
    let c2da_fresh107 : uint = uint(pr_strings)
    c2da_mem[230128 + 0 * 8] = uint8(c2da_fresh107)
    c2da_mem[230128 + 0 * 8 + 1] = uint8(c2da_fresh107 >> 0x8)
    c2da_mem[230128 + 0 * 8 + 2] = uint8(c2da_fresh107 >> 0x10)
    c2da_mem[230128 + 0 * 8 + 3] = uint8(c2da_fresh107 >> 0x18)
    c2da_mem[230128 + 0 * 8 + 4] = 0u8
    c2da_mem[230128 + 0 * 8 + 5] = 0u8
    c2da_mem[230128 + 0 * 8 + 6] = 0u8
    c2da_mem[230128 + 0 * 8 + 7] = 0u8
    let c2da_fresh108 : uint = uint(pr_strings)
    c2da_mem[226032 + 0 * 8] = uint8(c2da_fresh108)
    c2da_mem[226032 + 0 * 8 + 1] = uint8(c2da_fresh108 >> 0x8)
    c2da_mem[226032 + 0 * 8 + 2] = uint8(c2da_fresh108 >> 0x10)
    c2da_mem[226032 + 0 * 8 + 3] = uint8(c2da_fresh108 >> 0x18)
    c2da_mem[226032 + 0 * 8 + 4] = 0u8
    c2da_mem[226032 + 0 * 8 + 5] = 0u8
    c2da_mem[226032 + 0 * 8 + 6] = 0u8
    c2da_mem[226032 + 0 * 8 + 7] = 0u8
    let c2da_fresh109 : uint = 225960u
    c2da_mem[226032 + 1 * 8] = uint8(c2da_fresh109)
    c2da_mem[226032 + 1 * 8 + 1] = uint8(c2da_fresh109 >> 0x8)
    c2da_mem[226032 + 1 * 8 + 2] = uint8(c2da_fresh109 >> 0x10)
    c2da_mem[226032 + 1 * 8 + 3] = uint8(c2da_fresh109 >> 0x18)
    c2da_mem[226032 + 1 * 8 + 4] = 0u8
    c2da_mem[226032 + 1 * 8 + 5] = 0u8
    c2da_mem[226032 + 1 * 8 + 6] = 0u8
    c2da_mem[226032 + 1 * 8 + 7] = 0u8
    i_11 = 1
    while (true) {
        let c2da_fresh110 : int = int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) + 120
        if (i_11 >= int(uint(c2da_mem[c2da_fresh110]) | uint(c2da_mem[c2da_fresh110 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh110 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh110 + 3]) << 0x18)) {
            break
        }
        let c2da_fresh111 : int = 463024 + i_11 * 5
        let c2da_fresh112 : uint = uint(c2da_fresh111)
        c2da_mem[226032 + (1 + i_11) * 8] = uint8(c2da_fresh112)
        c2da_mem[226032 + (1 + i_11) * 8 + 1] = uint8(c2da_fresh112 >> 0x8)
        c2da_mem[226032 + (1 + i_11) * 8 + 2] = uint8(c2da_fresh112 >> 0x10)
        c2da_mem[226032 + (1 + i_11) * 8 + 3] = uint8(c2da_fresh112 >> 0x18)
        c2da_mem[226032 + (1 + i_11) * 8 + 4] = 0u8
        c2da_mem[226032 + (1 + i_11) * 8 + 5] = 0u8
        c2da_mem[226032 + (1 + i_11) * 8 + 6] = 0u8
        c2da_mem[226032 + (1 + i_11) * 8 + 7] = 0u8
        let c2da_fresh113 : int = Mod_ForName(463024 + i_11 * 5, 0u)
        let c2da_fresh114 : uint = uint(c2da_fresh113)
        c2da_mem[228080 + (i_11 + 1) * 8] = uint8(c2da_fresh114)
        c2da_mem[228080 + (i_11 + 1) * 8 + 1] = uint8(c2da_fresh114 >> 0x8)
        c2da_mem[228080 + (i_11 + 1) * 8 + 2] = uint8(c2da_fresh114 >> 0x10)
        c2da_mem[228080 + (i_11 + 1) * 8 + 3] = uint8(c2da_fresh114 >> 0x18)
        c2da_mem[228080 + (i_11 + 1) * 8 + 4] = 0u8
        c2da_mem[228080 + (i_11 + 1) * 8 + 5] = 0u8
        c2da_mem[228080 + (i_11 + 1) * 8 + 6] = 0u8
        c2da_mem[228080 + (i_11 + 1) * 8 + 7] = 0u8
        i_11++
    }
    ent_4 = EDICT_NUM(0)
    c2da_lin_memset(ent_4 + 108, 0, uint64(int(uint(c2da_mem[progs + 56]) | uint(c2da_mem[progs + 57]) << 0x8 | uint(c2da_mem[progs + 58]) << 0x10 | uint(c2da_mem[progs + 59]) << 0x18) * 4))
    let c2da_fresh115 : uint = 0u
    let c2da_fresh116 : uint = c2da_fresh115
    c2da_mem[ent_4] = uint8(c2da_fresh116)
    c2da_mem[ent_4 + 1] = uint8(c2da_fresh116 >> 0x8)
    c2da_mem[ent_4 + 2] = uint8(c2da_fresh116 >> 0x10)
    c2da_mem[ent_4 + 3] = uint8(c2da_fresh116 >> 0x18)
    let c2da_fresh117 : int = int(int64(int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) - pr_strings))
    let c2da_fresh118 : uint = uint(c2da_fresh117)
    c2da_mem[ent_4 + 224] = uint8(c2da_fresh118)
    c2da_mem[ent_4 + 225] = uint8(c2da_fresh118 >> 0x8)
    c2da_mem[ent_4 + 226] = uint8(c2da_fresh118 >> 0x10)
    c2da_mem[ent_4 + 227] = uint8(c2da_fresh118 >> 0x18)
    let c2da_fresh119 : float = 1.0
    let c2da_fresh120 : uint = float_bits_to_uint(c2da_fresh119)
    c2da_mem[ent_4 + 108] = uint8(c2da_fresh120)
    c2da_mem[ent_4 + 109] = uint8(c2da_fresh120 >> 0x8)
    c2da_mem[ent_4 + 110] = uint8(c2da_fresh120 >> 0x10)
    c2da_mem[ent_4 + 111] = uint8(c2da_fresh120 >> 0x18)
    let c2da_fresh121 : float = 4.0
    let c2da_fresh122 : uint = float_bits_to_uint(c2da_fresh121)
    c2da_mem[ent_4 + 144] = uint8(c2da_fresh122)
    c2da_mem[ent_4 + 145] = uint8(c2da_fresh122 >> 0x8)
    c2da_mem[ent_4 + 146] = uint8(c2da_fresh122 >> 0x10)
    c2da_mem[ent_4 + 147] = uint8(c2da_fresh122 >> 0x18)
    let c2da_fresh123 : float = 7.0
    let c2da_fresh124 : uint = float_bits_to_uint(c2da_fresh123)
    c2da_mem[ent_4 + 140] = uint8(c2da_fresh124)
    c2da_mem[ent_4 + 141] = uint8(c2da_fresh124 >> 0x8)
    c2da_mem[ent_4 + 142] = uint8(c2da_fresh124 >> 0x10)
    c2da_mem[ent_4 + 143] = uint8(c2da_fresh124 >> 0x18)
    if (uint_bits_to_float(uint(c2da_mem[243752]) | uint(c2da_mem[243753]) << 0x8 | uint(c2da_mem[243754]) << 0x10 | uint(c2da_mem[243755]) << 0x18) != 0.0) {
        let c2da_fresh125 : float = uint_bits_to_float(uint(c2da_mem[243752]) | uint(c2da_mem[243753]) << 0x8 | uint(c2da_mem[243754]) << 0x10 | uint(c2da_mem[243755]) << 0x18)
        let c2da_fresh126 : uint = float_bits_to_uint(c2da_fresh125)
        c2da_mem[pr_global_struct + 144] = uint8(c2da_fresh126)
        c2da_mem[pr_global_struct + 145] = uint8(c2da_fresh126 >> 0x8)
        c2da_mem[pr_global_struct + 146] = uint8(c2da_fresh126 >> 0x10)
        c2da_mem[pr_global_struct + 147] = uint8(c2da_fresh126 >> 0x18)
    } else {
        let c2da_fresh127 : float = uint_bits_to_float(uint(c2da_mem[243704]) | uint(c2da_mem[243705]) << 0x8 | uint(c2da_mem[243706]) << 0x10 | uint(c2da_mem[243707]) << 0x18)
        let c2da_fresh128 : uint = float_bits_to_uint(c2da_fresh127)
        c2da_mem[pr_global_struct + 140] = uint8(c2da_fresh128)
        c2da_mem[pr_global_struct + 141] = uint8(c2da_fresh128 >> 0x8)
        c2da_mem[pr_global_struct + 142] = uint8(c2da_fresh128 >> 0x10)
        c2da_mem[pr_global_struct + 143] = uint8(c2da_fresh128 >> 0x18)
    }
    let c2da_fresh129 : int = int(int64(225896 - pr_strings))
    let c2da_fresh130 : uint = uint(c2da_fresh129)
    c2da_mem[pr_global_struct + 136] = uint8(c2da_fresh130)
    c2da_mem[pr_global_struct + 137] = uint8(c2da_fresh130 >> 0x8)
    c2da_mem[pr_global_struct + 138] = uint8(c2da_fresh130 >> 0x10)
    c2da_mem[pr_global_struct + 139] = uint8(c2da_fresh130 >> 0x18)
    let c2da_fresh131 : float = float(svs.serverflags)
    let c2da_fresh132 : uint = float_bits_to_uint(c2da_fresh131)
    c2da_mem[pr_global_struct + 152] = uint8(c2da_fresh132)
    c2da_mem[pr_global_struct + 153] = uint8(c2da_fresh132 >> 0x8)
    c2da_mem[pr_global_struct + 154] = uint8(c2da_fresh132 >> 0x10)
    c2da_mem[pr_global_struct + 155] = uint8(c2da_fresh132 >> 0x18)
    let c2da_fresh133 : int = int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) + 520
    ED_LoadFromFile(int(uint(c2da_mem[c2da_fresh133]) | uint(c2da_mem[c2da_fresh133 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh133 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh133 + 3]) << 0x18))
    let c2da_fresh134 : uint = 1u
    let c2da_fresh135 : uint = c2da_fresh134
    c2da_mem[225856] = uint8(c2da_fresh135)
    c2da_mem[225857] = uint8(c2da_fresh135 >> 0x8)
    c2da_mem[225858] = uint8(c2da_fresh135 >> 0x10)
    c2da_mem[225859] = uint8(c2da_fresh135 >> 0x18)
    let c2da_fresh136 : uint = 1u
    let c2da_fresh137 : uint = c2da_fresh136
    c2da_mem[232704] = uint8(c2da_fresh137)
    c2da_mem[232705] = uint8(c2da_fresh137 >> 0x8)
    c2da_mem[232706] = uint8(c2da_fresh137 >> 0x10)
    c2da_mem[232707] = uint8(c2da_fresh137 >> 0x18)
    host_frametime = 0.1lf
    SV_Physics()
    SV_Physics()
    SV_CreateBaseline()
    i_11 = 0
    host_client = svs.clients
    while (i_11 < svs.maxclients) {
        if ((uint(c2da_mem[host_client]) | uint(c2da_mem[host_client + 1]) << 0x8 | uint(c2da_mem[host_client + 2]) << 0x10 | uint(c2da_mem[host_client + 3]) << 0x18) != 0u) {
            SV_SendServerinfo(host_client)
        }
        i_11++
        host_client = host_client + 8288
    }
    Con_DPrintf(736534, [])
    return
}
[export, sideeffects]
def SV_CreateBaseline() {
    var svent : int
    var entnum : int = 0
    while (entnum < int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        svent = EDICT_NUM(entnum)
        if ((uint(c2da_mem[svent]) | uint(c2da_mem[svent + 1]) << 0x8 | uint(c2da_mem[svent + 2]) << 0x10 | uint(c2da_mem[svent + 3]) << 0x18) != 0u) {
            entnum++
            continue
        }
        if (entnum > svs.maxclients && uint_bits_to_float(uint(c2da_mem[svent + 108]) | uint(c2da_mem[svent + 109]) << 0x8 | uint(c2da_mem[svent + 110]) << 0x10 | uint(c2da_mem[svent + 111]) << 0x18) == 0.0) {
            entnum++
            continue
        }
        let c2da_fresh138 : float = uint_bits_to_float(uint(c2da_mem[svent + 148 + 0 * 4]) | uint(c2da_mem[svent + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[svent + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[svent + 148 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh139 : uint = float_bits_to_uint(c2da_fresh138)
        c2da_mem[svent + 60 + 0 * 4] = uint8(c2da_fresh139)
        c2da_mem[svent + 60 + 0 * 4 + 1] = uint8(c2da_fresh139 >> 0x8)
        c2da_mem[svent + 60 + 0 * 4 + 2] = uint8(c2da_fresh139 >> 0x10)
        c2da_mem[svent + 60 + 0 * 4 + 3] = uint8(c2da_fresh139 >> 0x18)
        let c2da_fresh140 : float = uint_bits_to_float(uint(c2da_mem[svent + 148 + 1 * 4]) | uint(c2da_mem[svent + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[svent + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[svent + 148 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh141 : uint = float_bits_to_uint(c2da_fresh140)
        c2da_mem[svent + 60 + 1 * 4] = uint8(c2da_fresh141)
        c2da_mem[svent + 60 + 1 * 4 + 1] = uint8(c2da_fresh141 >> 0x8)
        c2da_mem[svent + 60 + 1 * 4 + 2] = uint8(c2da_fresh141 >> 0x10)
        c2da_mem[svent + 60 + 1 * 4 + 3] = uint8(c2da_fresh141 >> 0x18)
        let c2da_fresh142 : float = uint_bits_to_float(uint(c2da_mem[svent + 148 + 2 * 4]) | uint(c2da_mem[svent + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[svent + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[svent + 148 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh143 : uint = float_bits_to_uint(c2da_fresh142)
        c2da_mem[svent + 60 + 2 * 4] = uint8(c2da_fresh143)
        c2da_mem[svent + 60 + 2 * 4 + 1] = uint8(c2da_fresh143 >> 0x8)
        c2da_mem[svent + 60 + 2 * 4 + 2] = uint8(c2da_fresh143 >> 0x10)
        c2da_mem[svent + 60 + 2 * 4 + 3] = uint8(c2da_fresh143 >> 0x18)
        let c2da_fresh144 : float = uint_bits_to_float(uint(c2da_mem[svent + 184 + 0 * 4]) | uint(c2da_mem[svent + 184 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[svent + 184 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[svent + 184 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh145 : uint = float_bits_to_uint(c2da_fresh144)
        c2da_mem[svent + 72 + 0 * 4] = uint8(c2da_fresh145)
        c2da_mem[svent + 72 + 0 * 4 + 1] = uint8(c2da_fresh145 >> 0x8)
        c2da_mem[svent + 72 + 0 * 4 + 2] = uint8(c2da_fresh145 >> 0x10)
        c2da_mem[svent + 72 + 0 * 4 + 3] = uint8(c2da_fresh145 >> 0x18)
        let c2da_fresh146 : float = uint_bits_to_float(uint(c2da_mem[svent + 184 + 1 * 4]) | uint(c2da_mem[svent + 184 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[svent + 184 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[svent + 184 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh147 : uint = float_bits_to_uint(c2da_fresh146)
        c2da_mem[svent + 72 + 1 * 4] = uint8(c2da_fresh147)
        c2da_mem[svent + 72 + 1 * 4 + 1] = uint8(c2da_fresh147 >> 0x8)
        c2da_mem[svent + 72 + 1 * 4 + 2] = uint8(c2da_fresh147 >> 0x10)
        c2da_mem[svent + 72 + 1 * 4 + 3] = uint8(c2da_fresh147 >> 0x18)
        let c2da_fresh148 : float = uint_bits_to_float(uint(c2da_mem[svent + 184 + 2 * 4]) | uint(c2da_mem[svent + 184 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[svent + 184 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[svent + 184 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh149 : uint = float_bits_to_uint(c2da_fresh148)
        c2da_mem[svent + 72 + 2 * 4] = uint8(c2da_fresh149)
        c2da_mem[svent + 72 + 2 * 4 + 1] = uint8(c2da_fresh149 >> 0x8)
        c2da_mem[svent + 72 + 2 * 4 + 2] = uint8(c2da_fresh149 >> 0x10)
        c2da_mem[svent + 72 + 2 * 4 + 3] = uint8(c2da_fresh149 >> 0x18)
        let c2da_fresh150 : int = int(uint_bits_to_float(uint(c2da_mem[svent + 228]) | uint(c2da_mem[svent + 229]) << 0x8 | uint(c2da_mem[svent + 230]) << 0x10 | uint(c2da_mem[svent + 231]) << 0x18))
        let c2da_fresh151 : uint = uint(c2da_fresh150)
        c2da_mem[svent + 88] = uint8(c2da_fresh151)
        c2da_mem[svent + 89] = uint8(c2da_fresh151 >> 0x8)
        c2da_mem[svent + 90] = uint8(c2da_fresh151 >> 0x10)
        c2da_mem[svent + 91] = uint8(c2da_fresh151 >> 0x18)
        let c2da_fresh152 : int = int(uint_bits_to_float(uint(c2da_mem[svent + 232]) | uint(c2da_mem[svent + 233]) << 0x8 | uint(c2da_mem[svent + 234]) << 0x10 | uint(c2da_mem[svent + 235]) << 0x18))
        let c2da_fresh153 : uint = uint(c2da_fresh152)
        c2da_mem[svent + 96] = uint8(c2da_fresh153)
        c2da_mem[svent + 97] = uint8(c2da_fresh153 >> 0x8)
        c2da_mem[svent + 98] = uint8(c2da_fresh153 >> 0x10)
        c2da_mem[svent + 99] = uint8(c2da_fresh153 >> 0x18)
        if (entnum > 0 && entnum <= svs.maxclients) {
            let c2da_fresh154 : uint = uint(entnum)
            c2da_mem[svent + 92] = uint8(c2da_fresh154)
            c2da_mem[svent + 93] = uint8(c2da_fresh154 >> 0x8)
            c2da_mem[svent + 94] = uint8(c2da_fresh154 >> 0x10)
            c2da_mem[svent + 95] = uint8(c2da_fresh154 >> 0x18)
            let c2da_fresh155 : int = SV_ModelIndex(736551)
            let c2da_fresh156 : uint = uint(c2da_fresh155)
            c2da_mem[svent + 84] = uint8(c2da_fresh156)
            c2da_mem[svent + 85] = uint8(c2da_fresh156 >> 0x8)
            c2da_mem[svent + 86] = uint8(c2da_fresh156 >> 0x10)
            c2da_mem[svent + 87] = uint8(c2da_fresh156 >> 0x18)
        } else {
            let c2da_fresh157 : int = 0
            let c2da_fresh158 : uint = uint(c2da_fresh157)
            c2da_mem[svent + 92] = uint8(c2da_fresh158)
            c2da_mem[svent + 93] = uint8(c2da_fresh158 >> 0x8)
            c2da_mem[svent + 94] = uint8(c2da_fresh158 >> 0x10)
            c2da_mem[svent + 95] = uint8(c2da_fresh158 >> 0x18)
            let c2da_fresh159 : int = SV_ModelIndex(pr_strings + int(uint(c2da_mem[svent + 224]) | uint(c2da_mem[svent + 225]) << 0x8 | uint(c2da_mem[svent + 226]) << 0x10 | uint(c2da_mem[svent + 227]) << 0x18))
            let c2da_fresh160 : uint = uint(c2da_fresh159)
            c2da_mem[svent + 84] = uint8(c2da_fresh160)
            c2da_mem[svent + 85] = uint8(c2da_fresh160 >> 0x8)
            c2da_mem[svent + 86] = uint8(c2da_fresh160 >> 0x10)
            c2da_mem[svent + 87] = uint8(c2da_fresh160 >> 0x18)
        }
        MSG_WriteByte(234808, 22)
        MSG_WriteShort(234808, entnum)
        MSG_WriteByte(234808, int(uint(c2da_mem[svent + 84]) | uint(c2da_mem[svent + 85]) << 0x8 | uint(c2da_mem[svent + 86]) << 0x10 | uint(c2da_mem[svent + 87]) << 0x18))
        MSG_WriteByte(234808, int(uint(c2da_mem[svent + 88]) | uint(c2da_mem[svent + 89]) << 0x8 | uint(c2da_mem[svent + 90]) << 0x10 | uint(c2da_mem[svent + 91]) << 0x18))
        MSG_WriteByte(234808, int(uint(c2da_mem[svent + 92]) | uint(c2da_mem[svent + 93]) << 0x8 | uint(c2da_mem[svent + 94]) << 0x10 | uint(c2da_mem[svent + 95]) << 0x18))
        MSG_WriteByte(234808, int(uint(c2da_mem[svent + 96]) | uint(c2da_mem[svent + 97]) << 0x8 | uint(c2da_mem[svent + 98]) << 0x10 | uint(c2da_mem[svent + 99]) << 0x18))
        for (i_12 in range(0, 3)) {
            MSG_WriteCoord(234808, uint_bits_to_float(uint(c2da_mem[svent + 60 + i_12 * 4]) | uint(c2da_mem[svent + 60 + i_12 * 4 + 1]) << 0x8 | uint(c2da_mem[svent + 60 + i_12 * 4 + 2]) << 0x10 | uint(c2da_mem[svent + 60 + i_12 * 4 + 3]) << 0x18))
            MSG_WriteAngle(234808, uint_bits_to_float(uint(c2da_mem[svent + 72 + i_12 * 4]) | uint(c2da_mem[svent + 72 + i_12 * 4 + 1]) << 0x8 | uint(c2da_mem[svent + 72 + i_12 * 4 + 2]) << 0x10 | uint(c2da_mem[svent + 72 + i_12 * 4 + 3]) << 0x18))
        }
        entnum++
    }
    return
}
[export, sideeffects]
def SV_SendReconnect() {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_SendReconnect_c2da_frame(c2da_lin_enter(160))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private SV_SendNop_c2da_frame(var client : int; c2da_fp : int) {
    let c2da_fresh7 : uint = uint(c2da_fp)
    c2da_mem[c2da_fp + 24] = uint8(c2da_fresh7)
    c2da_mem[c2da_fp + 25] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[c2da_fp + 26] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[c2da_fp + 27] = uint8(c2da_fresh7 >> 0x18)
    c2da_mem[c2da_fp + 28] = 0u8
    c2da_mem[c2da_fp + 29] = 0u8
    c2da_mem[c2da_fp + 30] = 0u8
    c2da_mem[c2da_fp + 31] = 0u8
    let c2da_fresh8 : int = 4
    let c2da_fresh9 : uint = uint(c2da_fresh8)
    c2da_mem[c2da_fp + 32] = uint8(c2da_fresh9)
    c2da_mem[c2da_fp + 33] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[c2da_fp + 34] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[c2da_fp + 35] = uint8(c2da_fresh9 >> 0x18)
    let c2da_fresh10 : int = 0
    let c2da_fresh11 : uint = uint(c2da_fresh10)
    c2da_mem[c2da_fp + 36] = uint8(c2da_fresh11)
    c2da_mem[c2da_fp + 37] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[c2da_fp + 38] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[c2da_fp + 39] = uint8(c2da_fresh11 >> 0x18)
    MSG_WriteChar(c2da_fp + 16, 1)
    if (NET_SendUnreliableMessage(int(uint(c2da_mem[client + 32]) | uint(c2da_mem[client + 33]) << 0x8 | uint(c2da_mem[client + 34]) << 0x10 | uint(c2da_mem[client + 35]) << 0x18), c2da_fp + 16) == -1) {
        SV_DropClient(1u)
    }
    let c2da_fresh12 : uint64 = double_bits_to_uint64(realtime)
    c2da_mem[client + 24] = uint8(c2da_fresh12)
    c2da_mem[client + 25] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[client + 26] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[client + 27] = uint8(c2da_fresh12 >> 0x18)
    c2da_mem[client + 28] = uint8(c2da_fresh12 >> 0x20)
    c2da_mem[client + 29] = uint8(c2da_fresh12 >> 0x28)
    c2da_mem[client + 30] = uint8(c2da_fresh12 >> 0x30)
    c2da_mem[client + 31] = uint8(c2da_fresh12 >> 0x38)
    return
}
[sideeffects]
def private SV_SendClientDatagram_c2da_frame(var client_0 : int; c2da_fp : int) : uint {
    let c2da_fresh13 : uint = uint(c2da_fp)
    c2da_mem[c2da_fp + 1032] = uint8(c2da_fresh13)
    c2da_mem[c2da_fp + 1033] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[c2da_fp + 1034] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[c2da_fp + 1035] = uint8(c2da_fresh13 >> 0x18)
    c2da_mem[c2da_fp + 1036] = 0u8
    c2da_mem[c2da_fp + 1037] = 0u8
    c2da_mem[c2da_fp + 1038] = 0u8
    c2da_mem[c2da_fp + 1039] = 0u8
    let c2da_fresh14 : int = 1024
    let c2da_fresh15 : uint = uint(c2da_fresh14)
    c2da_mem[c2da_fp + 1040] = uint8(c2da_fresh15)
    c2da_mem[c2da_fp + 1041] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[c2da_fp + 1042] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[c2da_fp + 1043] = uint8(c2da_fresh15 >> 0x18)
    let c2da_fresh16 : int = 0
    let c2da_fresh17 : uint = uint(c2da_fresh16)
    c2da_mem[c2da_fp + 1044] = uint8(c2da_fresh17)
    c2da_mem[c2da_fp + 1045] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[c2da_fp + 1046] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[c2da_fp + 1047] = uint8(c2da_fresh17 >> 0x18)
    MSG_WriteByte(c2da_fp + 1024, 7)
    MSG_WriteFloat(c2da_fp + 1024, float(uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20)))
    SV_WriteClientdataToMessage(int(uint(c2da_mem[client_0 + 8104]) | uint(c2da_mem[client_0 + 8105]) << 0x8 | uint(c2da_mem[client_0 + 8106]) << 0x10 | uint(c2da_mem[client_0 + 8107]) << 0x18), c2da_fp + 1024)
    SV_WriteEntitiesToClient(int(uint(c2da_mem[client_0 + 8104]) | uint(c2da_mem[client_0 + 8105]) << 0x8 | uint(c2da_mem[client_0 + 8106]) << 0x10 | uint(c2da_mem[client_0 + 8107]) << 0x18), c2da_fp + 1024)
    if (int(uint(c2da_mem[c2da_fp + 1044]) | uint(c2da_mem[c2da_fp + 1045]) << 0x8 | uint(c2da_mem[c2da_fp + 1046]) << 0x10 | uint(c2da_mem[c2da_fp + 1047]) << 0x18) + int(uint(c2da_mem[232732]) | uint(c2da_mem[232733]) << 0x8 | uint(c2da_mem[232734]) << 0x10 | uint(c2da_mem[232735]) << 0x18) < int(uint(c2da_mem[c2da_fp + 1040]) | uint(c2da_mem[c2da_fp + 1041]) << 0x8 | uint(c2da_mem[c2da_fp + 1042]) << 0x10 | uint(c2da_mem[c2da_fp + 1043]) << 0x18)) {
        SZ_Write(c2da_fp + 1024, int(uint(c2da_mem[232720]) | uint(c2da_mem[232721]) << 0x8 | uint(c2da_mem[232722]) << 0x10 | uint(c2da_mem[232723]) << 0x18), int(uint(c2da_mem[232732]) | uint(c2da_mem[232733]) << 0x8 | uint(c2da_mem[232734]) << 0x10 | uint(c2da_mem[232735]) << 0x18))
    }
    if (NET_SendUnreliableMessage(int(uint(c2da_mem[client_0 + 32]) | uint(c2da_mem[client_0 + 33]) << 0x8 | uint(c2da_mem[client_0 + 34]) << 0x10 | uint(c2da_mem[client_0 + 35]) << 0x18), c2da_fp + 1024) == -1) {
        SV_DropClient(1u)
        return 0u
    }
    return 1u
}
[sideeffects]
def private SV_WriteEntitiesToClient_c2da_frame(var clent : int; var msg : int; c2da_fp : int) {
    var e_0 : int
    var i_3 : int
    var bits : int
    var pvs : int
    var miss : float
    var ent_1 : int
    let c2da_fresh18 : float = uint_bits_to_float(uint(c2da_mem[clent + 148 + 0 * 4]) | uint(c2da_mem[clent + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[clent + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[clent + 148 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[clent + 356 + 0 * 4]) | uint(c2da_mem[clent + 356 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[clent + 356 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[clent + 356 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh19 : uint = float_bits_to_uint(c2da_fresh18)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh19)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh19 >> 0x18)
    let c2da_fresh20 : float = uint_bits_to_float(uint(c2da_mem[clent + 148 + 1 * 4]) | uint(c2da_mem[clent + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[clent + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[clent + 148 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[clent + 356 + 1 * 4]) | uint(c2da_mem[clent + 356 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[clent + 356 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[clent + 356 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh21 : uint = float_bits_to_uint(c2da_fresh20)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh21)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh21 >> 0x18)
    let c2da_fresh22 : float = uint_bits_to_float(uint(c2da_mem[clent + 148 + 2 * 4]) | uint(c2da_mem[clent + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[clent + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[clent + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[clent + 356 + 2 * 4]) | uint(c2da_mem[clent + 356 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[clent + 356 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[clent + 356 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh23 : uint = float_bits_to_uint(c2da_fresh22)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh23)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh23 >> 0x18)
    pvs = SV_FatPVS(c2da_fp)
    ent_1 = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(pr_edict_size)
    e_0 = 1
    while (e_0 < int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        if (ent_1 != clent) {
            var c2da_fresh25 : int = 1
            if (!(uint_bits_to_float(uint(c2da_mem[ent_1 + 108]) | uint(c2da_mem[ent_1 + 109]) << 0x8 | uint(c2da_mem[ent_1 + 110]) << 0x10 | uint(c2da_mem[ent_1 + 111]) << 0x18) == 0.0)) {
                let c2da_fresh24 : int = pr_strings + int(uint(c2da_mem[ent_1 + 224]) | uint(c2da_mem[ent_1 + 225]) << 0x8 | uint(c2da_mem[ent_1 + 226]) << 0x10 | uint(c2da_mem[ent_1 + 227]) << 0x18)
                if (!(int8(c2da_mem[c2da_fresh24]) == 0)) {
                    c2da_fresh25 = 0
                }
            }
            if (c2da_fresh25 != 0) {
                e_0++
                ent_1 += int(pr_edict_size)
                continue
            }
            i_3 = 0
            while (i_3 < int(uint(c2da_mem[ent_1 + 24]) | uint(c2da_mem[ent_1 + 25]) << 0x8 | uint(c2da_mem[ent_1 + 26]) << 0x10 | uint(c2da_mem[ent_1 + 27]) << 0x18)) {
                let c2da_fresh26 : int = pvs + (int(int16(uint(c2da_mem[ent_1 + 28 + i_3 * 2]) | uint(c2da_mem[ent_1 + 28 + i_3 * 2 + 1]) << 0x8)) >> 3)
                if ((int(c2da_mem[c2da_fresh26]) & 1 << (int(int16(uint(c2da_mem[ent_1 + 28 + i_3 * 2]) | uint(c2da_mem[ent_1 + 28 + i_3 * 2 + 1]) << 0x8)) & 7)) != 0) {
                    break
                }
                i_3++
            }
            if (i_3 == int(uint(c2da_mem[ent_1 + 24]) | uint(c2da_mem[ent_1 + 25]) << 0x8 | uint(c2da_mem[ent_1 + 26]) << 0x10 | uint(c2da_mem[ent_1 + 27]) << 0x18)) {
                e_0++
                ent_1 += int(pr_edict_size)
                continue
            }
        }
        if (int(uint(c2da_mem[msg + 16]) | uint(c2da_mem[msg + 17]) << 0x8 | uint(c2da_mem[msg + 18]) << 0x10 | uint(c2da_mem[msg + 19]) << 0x18) - int(uint(c2da_mem[msg + 20]) | uint(c2da_mem[msg + 21]) << 0x8 | uint(c2da_mem[msg + 22]) << 0x10 | uint(c2da_mem[msg + 23]) << 0x18) < 16) {
            Con_Printf(736269, [])
            return
        }
        bits = 0
        i_3 = 0
        while (i_3 < 3) {
            miss = uint_bits_to_float(uint(c2da_mem[ent_1 + 148 + i_3 * 4]) | uint(c2da_mem[ent_1 + 148 + i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 148 + i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 148 + i_3 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[ent_1 + 60 + i_3 * 4]) | uint(c2da_mem[ent_1 + 60 + i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 60 + i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 60 + i_3 * 4 + 3]) << 0x18)
            if (double(miss) < -0.1lf || double(miss) > 0.1lf) {
                bits |= 1 << 1 << i_3
            }
            i_3++
        }
        if (uint_bits_to_float(uint(c2da_mem[ent_1 + 184 + 0 * 4]) | uint(c2da_mem[ent_1 + 184 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 184 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 184 + 0 * 4 + 3]) << 0x18) != uint_bits_to_float(uint(c2da_mem[ent_1 + 72 + 0 * 4]) | uint(c2da_mem[ent_1 + 72 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 72 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 72 + 0 * 4 + 3]) << 0x18)) {
            bits |= 1 << 8
        }
        if (uint_bits_to_float(uint(c2da_mem[ent_1 + 184 + 1 * 4]) | uint(c2da_mem[ent_1 + 184 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 184 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 184 + 1 * 4 + 3]) << 0x18) != uint_bits_to_float(uint(c2da_mem[ent_1 + 72 + 1 * 4]) | uint(c2da_mem[ent_1 + 72 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 72 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 72 + 1 * 4 + 3]) << 0x18)) {
            bits |= 1 << 4
        }
        if (uint_bits_to_float(uint(c2da_mem[ent_1 + 184 + 2 * 4]) | uint(c2da_mem[ent_1 + 184 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 184 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 184 + 2 * 4 + 3]) << 0x18) != uint_bits_to_float(uint(c2da_mem[ent_1 + 72 + 2 * 4]) | uint(c2da_mem[ent_1 + 72 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 72 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 72 + 2 * 4 + 3]) << 0x18)) {
            bits |= 1 << 9
        }
        if (uint_bits_to_float(uint(c2da_mem[ent_1 + 140]) | uint(c2da_mem[ent_1 + 141]) << 0x8 | uint(c2da_mem[ent_1 + 142]) << 0x10 | uint(c2da_mem[ent_1 + 143]) << 0x18) == 4.0) {
            bits |= 1 << 5
        }
        if (float(int(uint(c2da_mem[ent_1 + 92]) | uint(c2da_mem[ent_1 + 93]) << 0x8 | uint(c2da_mem[ent_1 + 94]) << 0x10 | uint(c2da_mem[ent_1 + 95]) << 0x18)) != uint_bits_to_float(uint(c2da_mem[ent_1 + 416]) | uint(c2da_mem[ent_1 + 417]) << 0x8 | uint(c2da_mem[ent_1 + 418]) << 0x10 | uint(c2da_mem[ent_1 + 419]) << 0x18)) {
            bits |= 1 << 11
        }
        if (float(int(uint(c2da_mem[ent_1 + 96]) | uint(c2da_mem[ent_1 + 97]) << 0x8 | uint(c2da_mem[ent_1 + 98]) << 0x10 | uint(c2da_mem[ent_1 + 99]) << 0x18)) != uint_bits_to_float(uint(c2da_mem[ent_1 + 232]) | uint(c2da_mem[ent_1 + 233]) << 0x8 | uint(c2da_mem[ent_1 + 234]) << 0x10 | uint(c2da_mem[ent_1 + 235]) << 0x18)) {
            bits |= 1 << 12
        }
        if (float(int(uint(c2da_mem[ent_1 + 88]) | uint(c2da_mem[ent_1 + 89]) << 0x8 | uint(c2da_mem[ent_1 + 90]) << 0x10 | uint(c2da_mem[ent_1 + 91]) << 0x18)) != uint_bits_to_float(uint(c2da_mem[ent_1 + 228]) | uint(c2da_mem[ent_1 + 229]) << 0x8 | uint(c2da_mem[ent_1 + 230]) << 0x10 | uint(c2da_mem[ent_1 + 231]) << 0x18)) {
            bits |= 1 << 6
        }
        if (float(int(uint(c2da_mem[ent_1 + 100]) | uint(c2da_mem[ent_1 + 101]) << 0x8 | uint(c2da_mem[ent_1 + 102]) << 0x10 | uint(c2da_mem[ent_1 + 103]) << 0x18)) != uint_bits_to_float(uint(c2da_mem[ent_1 + 236]) | uint(c2da_mem[ent_1 + 237]) << 0x8 | uint(c2da_mem[ent_1 + 238]) << 0x10 | uint(c2da_mem[ent_1 + 239]) << 0x18)) {
            bits |= 1 << 13
        }
        if (float(int(uint(c2da_mem[ent_1 + 84]) | uint(c2da_mem[ent_1 + 85]) << 0x8 | uint(c2da_mem[ent_1 + 86]) << 0x10 | uint(c2da_mem[ent_1 + 87]) << 0x18)) != uint_bits_to_float(uint(c2da_mem[ent_1 + 108]) | uint(c2da_mem[ent_1 + 109]) << 0x8 | uint(c2da_mem[ent_1 + 110]) << 0x10 | uint(c2da_mem[ent_1 + 111]) << 0x18)) {
            bits |= 1 << 10
        }
        if (e_0 >= 256) {
            bits |= 1 << 14
        }
        if (bits >= 256) {
            bits |= 1 << 0
        }
        MSG_WriteByte(msg, bits | 1 << 7)
        if ((bits & 1 << 0) != 0) {
            MSG_WriteByte(msg, bits >> 8)
        }
        if ((bits & 1 << 14) != 0) {
            MSG_WriteShort(msg, e_0)
        } else {
            MSG_WriteByte(msg, e_0)
        }
        if ((bits & 1 << 10) != 0) {
            MSG_WriteByte(msg, int(uint_bits_to_float(uint(c2da_mem[ent_1 + 108]) | uint(c2da_mem[ent_1 + 109]) << 0x8 | uint(c2da_mem[ent_1 + 110]) << 0x10 | uint(c2da_mem[ent_1 + 111]) << 0x18)))
        }
        if ((bits & 1 << 6) != 0) {
            MSG_WriteByte(msg, int(uint_bits_to_float(uint(c2da_mem[ent_1 + 228]) | uint(c2da_mem[ent_1 + 229]) << 0x8 | uint(c2da_mem[ent_1 + 230]) << 0x10 | uint(c2da_mem[ent_1 + 231]) << 0x18)))
        }
        if ((bits & 1 << 11) != 0) {
            MSG_WriteByte(msg, int(uint_bits_to_float(uint(c2da_mem[ent_1 + 416]) | uint(c2da_mem[ent_1 + 417]) << 0x8 | uint(c2da_mem[ent_1 + 418]) << 0x10 | uint(c2da_mem[ent_1 + 419]) << 0x18)))
        }
        if ((bits & 1 << 12) != 0) {
            MSG_WriteByte(msg, int(uint_bits_to_float(uint(c2da_mem[ent_1 + 232]) | uint(c2da_mem[ent_1 + 233]) << 0x8 | uint(c2da_mem[ent_1 + 234]) << 0x10 | uint(c2da_mem[ent_1 + 235]) << 0x18)))
        }
        if ((bits & 1 << 13) != 0) {
            MSG_WriteByte(msg, int(uint_bits_to_float(uint(c2da_mem[ent_1 + 236]) | uint(c2da_mem[ent_1 + 237]) << 0x8 | uint(c2da_mem[ent_1 + 238]) << 0x10 | uint(c2da_mem[ent_1 + 239]) << 0x18)))
        }
        if ((bits & 1 << 1) != 0) {
            MSG_WriteCoord(msg, uint_bits_to_float(uint(c2da_mem[ent_1 + 148 + 0 * 4]) | uint(c2da_mem[ent_1 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 148 + 0 * 4 + 3]) << 0x18))
        }
        if ((bits & 1 << 8) != 0) {
            MSG_WriteAngle(msg, uint_bits_to_float(uint(c2da_mem[ent_1 + 184 + 0 * 4]) | uint(c2da_mem[ent_1 + 184 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 184 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 184 + 0 * 4 + 3]) << 0x18))
        }
        if ((bits & 1 << 2) != 0) {
            MSG_WriteCoord(msg, uint_bits_to_float(uint(c2da_mem[ent_1 + 148 + 1 * 4]) | uint(c2da_mem[ent_1 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 148 + 1 * 4 + 3]) << 0x18))
        }
        if ((bits & 1 << 4) != 0) {
            MSG_WriteAngle(msg, uint_bits_to_float(uint(c2da_mem[ent_1 + 184 + 1 * 4]) | uint(c2da_mem[ent_1 + 184 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 184 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 184 + 1 * 4 + 3]) << 0x18))
        }
        if ((bits & 1 << 3) != 0) {
            MSG_WriteCoord(msg, uint_bits_to_float(uint(c2da_mem[ent_1 + 148 + 2 * 4]) | uint(c2da_mem[ent_1 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 148 + 2 * 4 + 3]) << 0x18))
        }
        if ((bits & 1 << 9) != 0) {
            MSG_WriteAngle(msg, uint_bits_to_float(uint(c2da_mem[ent_1 + 184 + 2 * 4]) | uint(c2da_mem[ent_1 + 184 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 184 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 184 + 2 * 4 + 3]) << 0x18))
        }
        e_0++
        ent_1 += int(pr_edict_size)
    }
    return
}
[sideeffects]
def private SV_ConnectClient_c2da_frame(var clientnum : int; c2da_fp : int) {
    var ent_3 : int
    var client_2 : int
    var netconnection : int
    client_2 = svs.clients + clientnum * 8288
    Con_DPrintf(736372, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[client_2 + 32]) | uint(c2da_mem[client_2 + 33]) << 0x8 | uint(c2da_mem[client_2 + 34]) << 0x10 | uint(c2da_mem[client_2 + 35]) << 0x18) + 16492))])
    ent_3 = EDICT_NUM(clientnum + 1)
    netconnection = int(uint(c2da_mem[client_2 + 32]) | uint(c2da_mem[client_2 + 33]) << 0x8 | uint(c2da_mem[client_2 + 34]) << 0x10 | uint(c2da_mem[client_2 + 35]) << 0x18)
    if ((uint(c2da_mem[225864]) | uint(c2da_mem[225865]) << 0x8 | uint(c2da_mem[225866]) << 0x10 | uint(c2da_mem[225867]) << 0x18) != 0u) {
        c2da_lin_memcpy(c2da_fp, client_2 + 8216, 64ul)
    }
    c2da_lin_memset(client_2, 0, 8288ul)
    let c2da_fresh44 : uint = uint(netconnection)
    c2da_mem[client_2 + 32] = uint8(c2da_fresh44)
    c2da_mem[client_2 + 33] = uint8(c2da_fresh44 >> 0x8)
    c2da_mem[client_2 + 34] = uint8(c2da_fresh44 >> 0x10)
    c2da_mem[client_2 + 35] = uint8(c2da_fresh44 >> 0x18)
    c2da_mem[client_2 + 36] = 0u8
    c2da_mem[client_2 + 37] = 0u8
    c2da_mem[client_2 + 38] = 0u8
    c2da_mem[client_2 + 39] = 0u8
    c2da_lin_strcpy(client_2 + 8112, 736393)
    let c2da_fresh45 : uint = 1u
    let c2da_fresh46 : uint = c2da_fresh45
    c2da_mem[client_2] = uint8(c2da_fresh46)
    c2da_mem[client_2 + 1] = uint8(c2da_fresh46 >> 0x8)
    c2da_mem[client_2 + 2] = uint8(c2da_fresh46 >> 0x10)
    c2da_mem[client_2 + 3] = uint8(c2da_fresh46 >> 0x18)
    let c2da_fresh47 : uint = 0u
    let c2da_fresh48 : uint = c2da_fresh47
    c2da_mem[client_2 + 4] = uint8(c2da_fresh48)
    c2da_mem[client_2 + 5] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[client_2 + 6] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[client_2 + 7] = uint8(c2da_fresh48 >> 0x18)
    let c2da_fresh49 : uint = uint(ent_3)
    c2da_mem[client_2 + 8104] = uint8(c2da_fresh49)
    c2da_mem[client_2 + 8105] = uint8(c2da_fresh49 >> 0x8)
    c2da_mem[client_2 + 8106] = uint8(c2da_fresh49 >> 0x10)
    c2da_mem[client_2 + 8107] = uint8(c2da_fresh49 >> 0x18)
    c2da_mem[client_2 + 8108] = 0u8
    c2da_mem[client_2 + 8109] = 0u8
    c2da_mem[client_2 + 8110] = 0u8
    c2da_mem[client_2 + 8111] = 0u8
    let c2da_fresh50 : int = client_2 + 104
    let c2da_fresh51 : uint = uint(c2da_fresh50)
    c2da_mem[client_2 + 88] = uint8(c2da_fresh51)
    c2da_mem[client_2 + 89] = uint8(c2da_fresh51 >> 0x8)
    c2da_mem[client_2 + 90] = uint8(c2da_fresh51 >> 0x10)
    c2da_mem[client_2 + 91] = uint8(c2da_fresh51 >> 0x18)
    c2da_mem[client_2 + 92] = 0u8
    c2da_mem[client_2 + 93] = 0u8
    c2da_mem[client_2 + 94] = 0u8
    c2da_mem[client_2 + 95] = 0u8
    let c2da_fresh52 : int = 8000
    let c2da_fresh53 : uint = uint(c2da_fresh52)
    c2da_mem[client_2 + 96] = uint8(c2da_fresh53)
    c2da_mem[client_2 + 97] = uint8(c2da_fresh53 >> 0x8)
    c2da_mem[client_2 + 98] = uint8(c2da_fresh53 >> 0x10)
    c2da_mem[client_2 + 99] = uint8(c2da_fresh53 >> 0x18)
    let c2da_fresh54 : uint = 1u
    let c2da_fresh55 : uint = c2da_fresh54
    c2da_mem[client_2 + 80] = uint8(c2da_fresh55)
    c2da_mem[client_2 + 81] = uint8(c2da_fresh55 >> 0x8)
    c2da_mem[client_2 + 82] = uint8(c2da_fresh55 >> 0x10)
    c2da_mem[client_2 + 83] = uint8(c2da_fresh55 >> 0x18)
    let c2da_fresh56 : uint = 0u
    let c2da_fresh57 : uint = c2da_fresh56
    c2da_mem[client_2 + 12] = uint8(c2da_fresh57)
    c2da_mem[client_2 + 13] = uint8(c2da_fresh57 >> 0x8)
    c2da_mem[client_2 + 14] = uint8(c2da_fresh57 >> 0x10)
    c2da_mem[client_2 + 15] = uint8(c2da_fresh57 >> 0x18)
    if ((uint(c2da_mem[225864]) | uint(c2da_mem[225865]) << 0x8 | uint(c2da_mem[225866]) << 0x10 | uint(c2da_mem[225867]) << 0x18) != 0u) {
        c2da_lin_memcpy(client_2 + 8216, c2da_fp, 64ul)
    } else {
        PR_ExecuteProgram(int(uint(c2da_mem[pr_global_struct + 360]) | uint(c2da_mem[pr_global_struct + 361]) << 0x8 | uint(c2da_mem[pr_global_struct + 362]) << 0x10 | uint(c2da_mem[pr_global_struct + 363]) << 0x18))
        for (i_9 in range(0, 16)) {
            let c2da_fresh58 : float = uint_bits_to_float(uint(c2da_mem[pr_global_struct + 172 + i_9 * 4]) | uint(c2da_mem[pr_global_struct + 172 + i_9 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_global_struct + 172 + i_9 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_global_struct + 172 + i_9 * 4 + 3]) << 0x18)
            let c2da_fresh59 : uint = float_bits_to_uint(c2da_fresh58)
            c2da_mem[client_2 + 8216 + i_9 * 4] = uint8(c2da_fresh59)
            c2da_mem[client_2 + 8216 + i_9 * 4 + 1] = uint8(c2da_fresh59 >> 0x8)
            c2da_mem[client_2 + 8216 + i_9 * 4 + 2] = uint8(c2da_fresh59 >> 0x10)
            c2da_mem[client_2 + 8216 + i_9 * 4 + 3] = uint8(c2da_fresh59 >> 0x18)
        }
    }
    SV_SendServerinfo(client_2)
    return
}
[sideeffects]
def private SV_SendServerinfo_c2da_frame(var client_3 : int; c2da_fp : int) {
    var s : int
    MSG_WriteByte(client_3 + 80, 8)
    c2da_lin_snprintf(c2da_fp, 2147483647ul, 736405, [C2daVaArg(tag = 1, i64 = 2l, f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = 1.09lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(uint16(uint(c2da_mem[389376]) | uint(c2da_mem[389377]) << 0x8)), f64 = 0.0lf, raw = 0x0)])
    MSG_WriteString(client_3 + 80, c2da_fp)
    MSG_WriteByte(client_3 + 80, 11)
    MSG_WriteLong(client_3 + 80, 15)
    MSG_WriteByte(client_3 + 80, svs.maxclients)
    if (uint_bits_to_float(uint(c2da_mem[243752]) | uint(c2da_mem[243753]) << 0x8 | uint(c2da_mem[243754]) << 0x10 | uint(c2da_mem[243755]) << 0x18) == 0.0 && uint_bits_to_float(uint(c2da_mem[243704]) | uint(c2da_mem[243705]) << 0x8 | uint(c2da_mem[243706]) << 0x10 | uint(c2da_mem[243707]) << 0x18) != 0.0) {
        MSG_WriteByte(client_3 + 80, 1)
    } else {
        MSG_WriteByte(client_3 + 80, 0)
    }
    let c2da_fresh60 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + 504
    c2da_lin_snprintf(c2da_fp, 2147483647ul, int(pr_strings + int(uint(c2da_mem[c2da_fresh60]) | uint(c2da_mem[c2da_fresh60 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh60 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh60 + 3]) << 0x18)), [])
    MSG_WriteString(client_3 + 80, c2da_fp)
    s = 226032 + 1 * 8
    while (int(uint(c2da_mem[s]) | uint(c2da_mem[s + 1]) << 0x8 | uint(c2da_mem[s + 2]) << 0x10 | uint(c2da_mem[s + 3]) << 0x18) != 0) {
        MSG_WriteString(client_3 + 80, int(uint(c2da_mem[s]) | uint(c2da_mem[s + 1]) << 0x8 | uint(c2da_mem[s + 2]) << 0x10 | uint(c2da_mem[s + 3]) << 0x18))
        s += 8
    }
    MSG_WriteByte(client_3 + 80, 0)
    s = 230128 + 1 * 8
    while (int(uint(c2da_mem[s]) | uint(c2da_mem[s + 1]) << 0x8 | uint(c2da_mem[s + 2]) << 0x10 | uint(c2da_mem[s + 3]) << 0x18) != 0) {
        MSG_WriteString(client_3 + 80, int(uint(c2da_mem[s]) | uint(c2da_mem[s + 1]) << 0x8 | uint(c2da_mem[s + 2]) << 0x10 | uint(c2da_mem[s + 3]) << 0x18))
        s += 8
    }
    MSG_WriteByte(client_3 + 80, 0)
    MSG_WriteByte(client_3 + 80, 32)
    let c2da_fresh61 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + 508
    MSG_WriteByte(client_3 + 80, int(uint_bits_to_float(uint(c2da_mem[c2da_fresh61]) | uint(c2da_mem[c2da_fresh61 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh61 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh61 + 3]) << 0x18)))
    let c2da_fresh62 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + 508
    MSG_WriteByte(client_3 + 80, int(uint_bits_to_float(uint(c2da_mem[c2da_fresh62]) | uint(c2da_mem[c2da_fresh62 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh62 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh62 + 3]) << 0x18)))
    MSG_WriteByte(client_3 + 80, 5)
    MSG_WriteShort(client_3 + 80, NUM_FOR_EDICT(int(uint(c2da_mem[client_3 + 8104]) | uint(c2da_mem[client_3 + 8105]) << 0x8 | uint(c2da_mem[client_3 + 8106]) << 0x10 | uint(c2da_mem[client_3 + 8107]) << 0x18)))
    MSG_WriteByte(client_3 + 80, 25)
    MSG_WriteByte(client_3 + 80, 1)
    let c2da_fresh63 : uint = 1u
    let c2da_fresh64 : uint = c2da_fresh63
    c2da_mem[client_3 + 16] = uint8(c2da_fresh64)
    c2da_mem[client_3 + 17] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[client_3 + 18] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[client_3 + 19] = uint8(c2da_fresh64 >> 0x18)
    let c2da_fresh65 : uint = 0u
    let c2da_fresh66 : uint = c2da_fresh65
    c2da_mem[client_3 + 4] = uint8(c2da_fresh66)
    c2da_mem[client_3 + 5] = uint8(c2da_fresh66 >> 0x8)
    c2da_mem[client_3 + 6] = uint8(c2da_fresh66 >> 0x10)
    c2da_mem[client_3 + 7] = uint8(c2da_fresh66 >> 0x18)
    return
}
[sideeffects]
def private SV_SendReconnect_c2da_frame(c2da_fp : int) {
    let c2da_fresh161 : uint = uint(c2da_fp)
    c2da_mem[c2da_fp + 136] = uint8(c2da_fresh161)
    c2da_mem[c2da_fp + 137] = uint8(c2da_fresh161 >> 0x8)
    c2da_mem[c2da_fp + 138] = uint8(c2da_fresh161 >> 0x10)
    c2da_mem[c2da_fp + 139] = uint8(c2da_fresh161 >> 0x18)
    c2da_mem[c2da_fp + 140] = 0u8
    c2da_mem[c2da_fp + 141] = 0u8
    c2da_mem[c2da_fp + 142] = 0u8
    c2da_mem[c2da_fp + 143] = 0u8
    let c2da_fresh162 : int = 0
    let c2da_fresh163 : uint = uint(c2da_fresh162)
    c2da_mem[c2da_fp + 148] = uint8(c2da_fresh163)
    c2da_mem[c2da_fp + 149] = uint8(c2da_fresh163 >> 0x8)
    c2da_mem[c2da_fp + 150] = uint8(c2da_fresh163 >> 0x10)
    c2da_mem[c2da_fp + 151] = uint8(c2da_fresh163 >> 0x18)
    let c2da_fresh164 : int = 128
    let c2da_fresh165 : uint = uint(c2da_fresh164)
    c2da_mem[c2da_fp + 144] = uint8(c2da_fresh165)
    c2da_mem[c2da_fp + 145] = uint8(c2da_fresh165 >> 0x8)
    c2da_mem[c2da_fp + 146] = uint8(c2da_fresh165 >> 0x10)
    c2da_mem[c2da_fp + 147] = uint8(c2da_fresh165 >> 0x18)
    MSG_WriteChar(c2da_fp + 128, 9)
    MSG_WriteString(c2da_fp + 128, 736568)
    NET_SendToAll(c2da_fp + 128, 5)
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) != 0u) {
        Cmd_ExecuteString(736568, 1u)
    }
    return
}

// This unit's static data, at heap offset 736144.
let private c2da_lin_static_sv_main_seg = fixed_array<int>(736144, 434)
let private c2da_lin_static_sv_main = fixed_array<uint64>(0x535f56530069252aul, 0x6e756f5374726174ul, 0x6d756c6f76203a64ul, 0x53006925203d2065ul, 0x5374726174535f56ul, 0x7461203a646e756ful, 0x6f697461756e6574ul, 0x53006625203d206eul, 0x5374726174535f56ul, 0x6863203a646e756ful, 0x203d206c656e6e61ul, 0x74535f5653006925ul, 0x646e756f53747261ul, 0x746f6e207325203aul, 0x6863616365727020ul, 0x636170000a646565ul, 0x7265766f2074656bul, 0x7469000a776f6c66ul, 0x5f56530032736d65ul, 0x646e496c65646f4dul, 0x65646f6d203a7865ul, 0x746f6e207325206cul, 0x6863616365727020ul, 0x5f74736f48006465ul, 0x726f466b63656843ul, 0x6e65696c4377654eul, 0x66206f6e203a7374ul, 0x65696c6320656572ul, 0x65696c430073746eul, 0x6f6320732520746eul, 0xa64657463656e6eul, 0x656e6e6f636e7500ul, 0xa63250064657463ul, 0x204e4f4953524556ul, 0x45532066322e3425ul, 0x6925282052455652ul, 0x6f68002943524320ul, 0x5500656d616e7473ul, 0x530044454d414e4eul, 0x767265536e776170ul, 0xa7325203a7265ul, 0x74616d6874616564ul, 0x6c6c696b73006863ul, 0x73746369646500ul, 0x2e73252f7370616dul, 0x6c756f4300707362ul, 0x6170732074276e64ul, 0x6576726573206e77ul, 0x6553000a73252072ul, 0x6170732072657672ul, 0x70000a2e64656e77ul, 0x616c702f73676f72ul, 0x6c646d2e726579ul, 0x63656e6e6f636572ul, 0xa74ul)

[init]
def private c2da_lin_init_static_sv_main() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_sv_main_seg[s * 2]
        for (k in range(c2da_lin_static_sv_main_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_sv_main[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
