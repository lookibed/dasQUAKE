var private CL_KeepaliveMessage__lastmsg : float = 0.0

[export, sideeffects]
def CL_ParseServerMessage() {
    var cmd_0 : int
    var i : int
    if (uint_bits_to_float(uint(c2da_mem[9640]) | uint(c2da_mem[9641]) << 0x8 | uint(c2da_mem[9642]) << 0x10 | uint(c2da_mem[9643]) << 0x18) == 1.0) {
        Con_Printf(698784, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    } elif (uint_bits_to_float(uint(c2da_mem[9640]) | uint(c2da_mem[9641]) << 0x8 | uint(c2da_mem[9642]) << 0x10 | uint(c2da_mem[9643]) << 0x18) == 2.0) {
        Con_Printf(698788, [])
    }
    let c2da_fresh0 : uint = 0u
    let c2da_fresh1 : uint = c2da_fresh0
    c2da_mem[748] = uint8(c2da_fresh1)
    c2da_mem[749] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[750] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[751] = uint8(c2da_fresh1 >> 0x18)
    MSG_BeginReading()
    while (true) {
        if (uint(msg_badread) != 0u) {
            Host_Error(698808, [])
        }
        cmd_0 = MSG_ReadByte()
        if (cmd_0 == -1) {
            if (uint_bits_to_float(uint(c2da_mem[9640]) | uint(c2da_mem[9641]) << 0x8 | uint(c2da_mem[9642]) << 0x10 | uint(c2da_mem[9643]) << 0x18) == 2.0) {
                Con_Printf(698850, [C2daVaArg(tag = 1, i64 = int64(msg_readcount - 1), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 698858ul)])
            }
            return
        }
        if ((cmd_0 & 128) != 0) {
            if (uint_bits_to_float(uint(c2da_mem[9640]) | uint(c2da_mem[9641]) << 0x8 | uint(c2da_mem[9642]) << 0x10 | uint(c2da_mem[9643]) << 0x18) == 2.0) {
                Con_Printf(698850, [C2daVaArg(tag = 1, i64 = int64(msg_readcount - 1), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 698873ul)])
            }
            CL_ParseUpdate(cmd_0 & 127)
            continue
        }
        if (uint_bits_to_float(uint(c2da_mem[9640]) | uint(c2da_mem[9641]) << 0x8 | uint(c2da_mem[9642]) << 0x10 | uint(c2da_mem[9643]) << 0x18) == 2.0) {
            Con_Printf(698850, [C2daVaArg(tag = 1, i64 = int64(msg_readcount - 1), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(svc_strings[cmd_0]))])
        }
        if (cmd_0 >= 1 && cmd_0 <= 34) {
            goto cmd_0
        }
        goto label 0
        label 0:
        label 21:
        Host_Error(698885, [])
        continue
        label 1:
        continue
        label 7:
        let c2da_fresh2 : double = uint64_bits_to_double(uint64(uint(c2da_mem[768 + 0 * 8]) | uint(c2da_mem[768 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 3]) << 0x18) | uint64(uint(c2da_mem[768 + 0 * 8 + 4]) | uint(c2da_mem[768 + 0 * 8 + 5]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 6]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 7]) << 0x18) << 0x20)
        let c2da_fresh3 : uint64 = double_bits_to_uint64(c2da_fresh2)
        c2da_mem[768 + 1 * 8] = uint8(c2da_fresh3)
        c2da_mem[768 + 1 * 8 + 1] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[768 + 1 * 8 + 2] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[768 + 1 * 8 + 3] = uint8(c2da_fresh3 >> 0x18)
        c2da_mem[768 + 1 * 8 + 4] = uint8(c2da_fresh3 >> 0x20)
        c2da_mem[768 + 1 * 8 + 5] = uint8(c2da_fresh3 >> 0x28)
        c2da_mem[768 + 1 * 8 + 6] = uint8(c2da_fresh3 >> 0x30)
        c2da_mem[768 + 1 * 8 + 7] = uint8(c2da_fresh3 >> 0x38)
        let c2da_fresh4 : double = double(MSG_ReadFloat())
        let c2da_fresh5 : uint64 = double_bits_to_uint64(c2da_fresh4)
        c2da_mem[768 + 0 * 8] = uint8(c2da_fresh5)
        c2da_mem[768 + 0 * 8 + 1] = uint8(c2da_fresh5 >> 0x8)
        c2da_mem[768 + 0 * 8 + 2] = uint8(c2da_fresh5 >> 0x10)
        c2da_mem[768 + 0 * 8 + 3] = uint8(c2da_fresh5 >> 0x18)
        c2da_mem[768 + 0 * 8 + 4] = uint8(c2da_fresh5 >> 0x20)
        c2da_mem[768 + 0 * 8 + 5] = uint8(c2da_fresh5 >> 0x28)
        c2da_mem[768 + 0 * 8 + 6] = uint8(c2da_fresh5 >> 0x30)
        c2da_mem[768 + 0 * 8 + 7] = uint8(c2da_fresh5 >> 0x38)
        continue
        label 15:
        i = MSG_ReadShort()
        CL_ParseClientdata(i)
        continue
        label 4:
        i = MSG_ReadLong()
        if (i != 15) {
            Host_Error(698934, [C2daVaArg(tag = 1, i64 = int64(i), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = 15l, f64 = 0.0lf, raw = 0x0)])
        }
        continue
        label 2:
        Host_EndGame(698994, [])
        label 8:
        Con_Printf(699015, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(MSG_ReadString()))])
        continue
        label 26:
        SCR_CenterPrint(MSG_ReadString())
        continue
        label 9:
        Cbuf_AddText(MSG_ReadString())
        continue
        label 19:
        V_ParseDamage()
        continue
        label 11:
        CL_ParseServerInfo()
        vid.recalc_refdef = 1
        continue
        label 10:
        i = 0
        while (i < 3) {
            let c2da_fresh6 : float = MSG_ReadAngle()
            let c2da_fresh7 : uint = float_bits_to_uint(c2da_fresh6)
            c2da_mem[652 + i * 4] = uint8(c2da_fresh7)
            c2da_mem[652 + i * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
            c2da_mem[652 + i * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
            c2da_mem[652 + i * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
            i++
        }
        continue
        label 5:
        let c2da_fresh8 : int = MSG_ReadShort()
        let c2da_fresh9 : uint = uint(c2da_fresh8)
        c2da_mem[4944] = uint8(c2da_fresh9)
        c2da_mem[4945] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[4946] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[4947] = uint8(c2da_fresh9 >> 0x18)
        continue
        label 12:
        i = MSG_ReadByte()
        if (i >= 64) {
            Sys_Error(699018, [])
        }
        Q_strcpy(150528 + i * 68 + 4, MSG_ReadString())
        let c2da_fresh10 : int = Q_strlen(150528 + i * 68 + 4)
        let c2da_fresh11 : uint = uint(c2da_fresh10)
        c2da_mem[150528 + i * 68] = uint8(c2da_fresh11)
        c2da_mem[150528 + i * 68 + 1] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[150528 + i * 68 + 2] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[150528 + i * 68 + 3] = uint8(c2da_fresh11 >> 0x18)
        continue
        label 6:
        CL_ParseStartSoundPacket()
        continue
        label 16:
        i = MSG_ReadShort()
        S_StopSound(i >> 3, i & 7)
        continue
        label 13:
        Sbar_Changed()
        i = MSG_ReadByte()
        if (i >= int(uint(c2da_mem[4948]) | uint(c2da_mem[4949]) << 0x8 | uint(c2da_mem[4950]) << 0x10 | uint(c2da_mem[4951]) << 0x18)) {
            Host_Error(699051, [])
        }
        c2da_lin_strcpy(int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + i * 16428, int(MSG_ReadString()))
        continue
        label 14:
        Sbar_Changed()
        i = MSG_ReadByte()
        if (i >= int(uint(c2da_mem[4948]) | uint(c2da_mem[4949]) << 0x8 | uint(c2da_mem[4950]) << 0x10 | uint(c2da_mem[4951]) << 0x18)) {
            Host_Error(699106, [])
        }
        let c2da_fresh12 : int = int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + i * 16428 + 36
        let c2da_fresh13 : int = MSG_ReadShort()
        let c2da_fresh14 : uint = uint(c2da_fresh13)
        c2da_mem[c2da_fresh12] = uint8(c2da_fresh14)
        c2da_mem[c2da_fresh12 + 1] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[c2da_fresh12 + 2] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[c2da_fresh12 + 3] = uint8(c2da_fresh14 >> 0x18)
        continue
        label 17:
        Sbar_Changed()
        i = MSG_ReadByte()
        if (i >= int(uint(c2da_mem[4948]) | uint(c2da_mem[4949]) << 0x8 | uint(c2da_mem[4950]) << 0x10 | uint(c2da_mem[4951]) << 0x18)) {
            Host_Error(699162, [])
        }
        let c2da_fresh15 : int = int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + i * 16428 + 40
        let c2da_fresh16 : int = MSG_ReadByte()
        let c2da_fresh17 : uint = uint(c2da_fresh16)
        c2da_mem[c2da_fresh15] = uint8(c2da_fresh17)
        c2da_mem[c2da_fresh15 + 1] = uint8(c2da_fresh17 >> 0x8)
        c2da_mem[c2da_fresh15 + 2] = uint8(c2da_fresh17 >> 0x10)
        c2da_mem[c2da_fresh15 + 3] = uint8(c2da_fresh17 >> 0x18)
        CL_NewTranslation(i)
        continue
        label 18:
        R_ParseParticleEffect()
        continue
        label 22:
        i = MSG_ReadShort()
        CL_ParseBaseline(CL_EntityNum(i))
        continue
        label 20:
        CL_ParseStatic()
        continue
        label 23:
        CL_ParseTEnt()
        continue
        label 24:
        let c2da_fresh18 : uint = uint(MSG_ReadByte())
        let c2da_fresh19 : uint = c2da_fresh18
        c2da_mem[744] = uint8(c2da_fresh19)
        c2da_mem[745] = uint8(c2da_fresh19 >> 0x8)
        c2da_mem[746] = uint8(c2da_fresh19 >> 0x10)
        c2da_mem[747] = uint8(c2da_fresh19 >> 0x18)
        if ((uint(c2da_mem[744]) | uint(c2da_mem[745]) << 0x8 | uint(c2da_mem[746]) << 0x10 | uint(c2da_mem[747]) << 0x18) != 0u) {
            CDAudio_Pause()
        } else {
            CDAudio_Resume()
        }
        continue
        label 25:
        i = MSG_ReadByte()
        if (i <= int(uint(c2da_mem[7804]) | uint(c2da_mem[7805]) << 0x8 | uint(c2da_mem[7806]) << 0x10 | uint(c2da_mem[7807]) << 0x18)) {
            Host_Error(699219, [C2daVaArg(tag = 1, i64 = int64(i), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[7804]) | uint(c2da_mem[7805]) << 0x8 | uint(c2da_mem[7806]) << 0x10 | uint(c2da_mem[7807]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
        }
        let c2da_fresh20 : uint = uint(i)
        c2da_mem[7804] = uint8(c2da_fresh20)
        c2da_mem[7805] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[7806] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[7807] = uint8(c2da_fresh20 >> 0x18)
        CL_SignonReply()
        continue
        label 27:
        let c2da_fresh21 : int = int(uint(c2da_mem[236 + 14 * 4]) | uint(c2da_mem[236 + 14 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 14 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 14 * 4 + 3]) << 0x18)
        let c2da_fresh22 : int = c2da_fresh21 + 1
        let c2da_fresh23 : uint = uint(c2da_fresh22)
        c2da_mem[236 + 14 * 4] = uint8(c2da_fresh23)
        c2da_mem[236 + 14 * 4 + 1] = uint8(c2da_fresh23 >> 0x8)
        c2da_mem[236 + 14 * 4 + 2] = uint8(c2da_fresh23 >> 0x10)
        c2da_mem[236 + 14 * 4 + 3] = uint8(c2da_fresh23 >> 0x18)
        continue
        label 28:
        let c2da_fresh24 : int = int(uint(c2da_mem[236 + 13 * 4]) | uint(c2da_mem[236 + 13 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 13 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 13 * 4 + 3]) << 0x18)
        let c2da_fresh25 : int = c2da_fresh24 + 1
        let c2da_fresh26 : uint = uint(c2da_fresh25)
        c2da_mem[236 + 13 * 4] = uint8(c2da_fresh26)
        c2da_mem[236 + 13 * 4 + 1] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[236 + 13 * 4 + 2] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[236 + 13 * 4 + 3] = uint8(c2da_fresh26 >> 0x18)
        continue
        label 3:
        i = MSG_ReadByte()
        if (i < 0 || i >= 32) {
            Sys_Error(699249, [C2daVaArg(tag = 1, i64 = int64(i), f64 = 0.0lf, raw = 0x0)])
        }
        let c2da_fresh27 : int = MSG_ReadLong()
        let c2da_fresh28 : uint = uint(c2da_fresh27)
        c2da_mem[236 + i * 4] = uint8(c2da_fresh28)
        c2da_mem[236 + i * 4 + 1] = uint8(c2da_fresh28 >> 0x8)
        c2da_mem[236 + i * 4 + 2] = uint8(c2da_fresh28 >> 0x10)
        c2da_mem[236 + i * 4 + 3] = uint8(c2da_fresh28 >> 0x18)
        continue
        label 29:
        CL_ParseStaticSound()
        continue
        label 32:
        let c2da_fresh29 : int = MSG_ReadByte()
        let c2da_fresh30 : uint = uint(c2da_fresh29)
        c2da_mem[5184] = uint8(c2da_fresh30)
        c2da_mem[5185] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[5186] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[5187] = uint8(c2da_fresh30 >> 0x18)
        let c2da_fresh31 : int = MSG_ReadByte()
        let c2da_fresh32 : uint = uint(c2da_fresh31)
        c2da_mem[5188] = uint8(c2da_fresh32)
        c2da_mem[5189] = uint8(c2da_fresh32 >> 0x8)
        c2da_mem[5190] = uint8(c2da_fresh32 >> 0x10)
        c2da_mem[5191] = uint8(c2da_fresh32 >> 0x18)
        if (((uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) != 0x0 || (uint(c2da_mem[7768]) | uint(c2da_mem[7769]) << 0x8 | uint(c2da_mem[7770]) << 0x10 | uint(c2da_mem[7771]) << 0x18) != 0x0) && int(uint(c2da_mem[7780]) | uint(c2da_mem[7781]) << 0x8 | uint(c2da_mem[7782]) << 0x10 | uint(c2da_mem[7783]) << 0x18) != -1) {
            CDAudio_Play(uint8(int(uint(c2da_mem[7780]) | uint(c2da_mem[7781]) << 0x8 | uint(c2da_mem[7782]) << 0x10 | uint(c2da_mem[7783]) << 0x18)), 1u)
        } else {
            CDAudio_Play(uint8(int(uint(c2da_mem[5184]) | uint(c2da_mem[5185]) << 0x8 | uint(c2da_mem[5186]) << 0x10 | uint(c2da_mem[5187]) << 0x18)), 1u)
        }
        continue
        label 30:
        let c2da_fresh33 : int = 1
        let c2da_fresh34 : uint = uint(c2da_fresh33)
        c2da_mem[756] = uint8(c2da_fresh34)
        c2da_mem[757] = uint8(c2da_fresh34 >> 0x8)
        c2da_mem[758] = uint8(c2da_fresh34 >> 0x10)
        c2da_mem[759] = uint8(c2da_fresh34 >> 0x18)
        let c2da_fresh35 : int = int(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20))
        let c2da_fresh36 : uint = uint(c2da_fresh35)
        c2da_mem[760] = uint8(c2da_fresh36)
        c2da_mem[761] = uint8(c2da_fresh36 >> 0x8)
        c2da_mem[762] = uint8(c2da_fresh36 >> 0x10)
        c2da_mem[763] = uint8(c2da_fresh36 >> 0x18)
        vid.recalc_refdef = 1
        continue
        label 31:
        let c2da_fresh37 : int = 2
        let c2da_fresh38 : uint = uint(c2da_fresh37)
        c2da_mem[756] = uint8(c2da_fresh38)
        c2da_mem[757] = uint8(c2da_fresh38 >> 0x8)
        c2da_mem[758] = uint8(c2da_fresh38 >> 0x10)
        c2da_mem[759] = uint8(c2da_fresh38 >> 0x18)
        let c2da_fresh39 : int = int(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20))
        let c2da_fresh40 : uint = uint(c2da_fresh39)
        c2da_mem[760] = uint8(c2da_fresh40)
        c2da_mem[761] = uint8(c2da_fresh40 >> 0x8)
        c2da_mem[762] = uint8(c2da_fresh40 >> 0x10)
        c2da_mem[763] = uint8(c2da_fresh40 >> 0x18)
        vid.recalc_refdef = 1
        SCR_CenterPrint(MSG_ReadString())
        continue
        label 34:
        let c2da_fresh41 : int = 3
        let c2da_fresh42 : uint = uint(c2da_fresh41)
        c2da_mem[756] = uint8(c2da_fresh42)
        c2da_mem[757] = uint8(c2da_fresh42 >> 0x8)
        c2da_mem[758] = uint8(c2da_fresh42 >> 0x10)
        c2da_mem[759] = uint8(c2da_fresh42 >> 0x18)
        let c2da_fresh43 : int = int(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20))
        let c2da_fresh44 : uint = uint(c2da_fresh43)
        c2da_mem[760] = uint8(c2da_fresh44)
        c2da_mem[761] = uint8(c2da_fresh44 >> 0x8)
        c2da_mem[762] = uint8(c2da_fresh44 >> 0x10)
        c2da_mem[763] = uint8(c2da_fresh44 >> 0x18)
        vid.recalc_refdef = 1
        SCR_CenterPrint(MSG_ReadString())
        continue
        label 33:
        Cmd_ExecuteString(699279, 1u)
    }
}
[export, sideeffects]
def CL_ParseStaticSound() {
    let c2da_saved_sp : int = c2da_lin_sp
    CL_ParseStaticSound_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def CL_ParseStatic() {
    var ent : int
    var i_1 : int = int(uint(c2da_mem[4980]) | uint(c2da_mem[4981]) << 0x8 | uint(c2da_mem[4982]) << 0x10 | uint(c2da_mem[4983]) << 0x18)
    if (i_1 >= 128) {
        Host_Error(699284, [])
    }
    ent = 168832 + i_1 * 200
    let c2da_fresh47 : int = int(uint(c2da_mem[4980]) | uint(c2da_mem[4981]) << 0x8 | uint(c2da_mem[4982]) << 0x10 | uint(c2da_mem[4983]) << 0x18)
    let c2da_fresh48 : int = c2da_fresh47 + 1
    let c2da_fresh49 : uint = uint(c2da_fresh48)
    c2da_mem[4980] = uint8(c2da_fresh49)
    c2da_mem[4981] = uint8(c2da_fresh49 >> 0x8)
    c2da_mem[4982] = uint8(c2da_fresh49 >> 0x10)
    c2da_mem[4983] = uint8(c2da_fresh49 >> 0x18)
    CL_ParseBaseline(ent)
    let c2da_fresh50 : int = 808 + int(uint(c2da_mem[ent + 32]) | uint(c2da_mem[ent + 33]) << 0x8 | uint(c2da_mem[ent + 34]) << 0x10 | uint(c2da_mem[ent + 35]) << 0x18) * 8
    let c2da_fresh51 : int = int(uint(c2da_mem[c2da_fresh50]) | uint(c2da_mem[c2da_fresh50 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh50 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh50 + 3]) << 0x18)
    let c2da_fresh52 : uint = uint(c2da_fresh51)
    c2da_mem[ent + 136] = uint8(c2da_fresh52)
    c2da_mem[ent + 137] = uint8(c2da_fresh52 >> 0x8)
    c2da_mem[ent + 138] = uint8(c2da_fresh52 >> 0x10)
    c2da_mem[ent + 139] = uint8(c2da_fresh52 >> 0x18)
    c2da_mem[ent + 140] = 0u8
    c2da_mem[ent + 141] = 0u8
    c2da_mem[ent + 142] = 0u8
    c2da_mem[ent + 143] = 0u8
    let c2da_fresh53 : int = int(uint(c2da_mem[ent + 36]) | uint(c2da_mem[ent + 37]) << 0x8 | uint(c2da_mem[ent + 38]) << 0x10 | uint(c2da_mem[ent + 39]) << 0x18)
    let c2da_fresh54 : uint = uint(c2da_fresh53)
    c2da_mem[ent + 152] = uint8(c2da_fresh54)
    c2da_mem[ent + 153] = uint8(c2da_fresh54 >> 0x8)
    c2da_mem[ent + 154] = uint8(c2da_fresh54 >> 0x10)
    c2da_mem[ent + 155] = uint8(c2da_fresh54 >> 0x18)
    let c2da_fresh55 : int = vid.colormap
    let c2da_fresh56 : uint = uint(c2da_fresh55)
    c2da_mem[ent + 160] = uint8(c2da_fresh56)
    c2da_mem[ent + 161] = uint8(c2da_fresh56 >> 0x8)
    c2da_mem[ent + 162] = uint8(c2da_fresh56 >> 0x10)
    c2da_mem[ent + 163] = uint8(c2da_fresh56 >> 0x18)
    c2da_mem[ent + 164] = 0u8
    c2da_mem[ent + 165] = 0u8
    c2da_mem[ent + 166] = 0u8
    c2da_mem[ent + 167] = 0u8
    let c2da_fresh57 : int = int(uint(c2da_mem[ent + 44]) | uint(c2da_mem[ent + 45]) << 0x8 | uint(c2da_mem[ent + 46]) << 0x10 | uint(c2da_mem[ent + 47]) << 0x18)
    let c2da_fresh58 : uint = uint(c2da_fresh57)
    c2da_mem[ent + 172] = uint8(c2da_fresh58)
    c2da_mem[ent + 173] = uint8(c2da_fresh58 >> 0x8)
    c2da_mem[ent + 174] = uint8(c2da_fresh58 >> 0x10)
    c2da_mem[ent + 175] = uint8(c2da_fresh58 >> 0x18)
    let c2da_fresh59 : int = int(uint(c2da_mem[ent + 48]) | uint(c2da_mem[ent + 49]) << 0x8 | uint(c2da_mem[ent + 50]) << 0x10 | uint(c2da_mem[ent + 51]) << 0x18)
    let c2da_fresh60 : uint = uint(c2da_fresh59)
    c2da_mem[ent + 168] = uint8(c2da_fresh60)
    c2da_mem[ent + 169] = uint8(c2da_fresh60 >> 0x8)
    c2da_mem[ent + 170] = uint8(c2da_fresh60 >> 0x10)
    c2da_mem[ent + 171] = uint8(c2da_fresh60 >> 0x18)
    let c2da_fresh61 : float = uint_bits_to_float(uint(c2da_mem[ent + 8 + 0 * 4]) | uint(c2da_mem[ent + 8 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 8 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 8 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh62 : uint = float_bits_to_uint(c2da_fresh61)
    c2da_mem[ent + 88 + 0 * 4] = uint8(c2da_fresh62)
    c2da_mem[ent + 88 + 0 * 4 + 1] = uint8(c2da_fresh62 >> 0x8)
    c2da_mem[ent + 88 + 0 * 4 + 2] = uint8(c2da_fresh62 >> 0x10)
    c2da_mem[ent + 88 + 0 * 4 + 3] = uint8(c2da_fresh62 >> 0x18)
    let c2da_fresh63 : float = uint_bits_to_float(uint(c2da_mem[ent + 8 + 1 * 4]) | uint(c2da_mem[ent + 8 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 8 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 8 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh64 : uint = float_bits_to_uint(c2da_fresh63)
    c2da_mem[ent + 88 + 1 * 4] = uint8(c2da_fresh64)
    c2da_mem[ent + 88 + 1 * 4 + 1] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[ent + 88 + 1 * 4 + 2] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[ent + 88 + 1 * 4 + 3] = uint8(c2da_fresh64 >> 0x18)
    let c2da_fresh65 : float = uint_bits_to_float(uint(c2da_mem[ent + 8 + 2 * 4]) | uint(c2da_mem[ent + 8 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 8 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 8 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh66 : uint = float_bits_to_uint(c2da_fresh65)
    c2da_mem[ent + 88 + 2 * 4] = uint8(c2da_fresh66)
    c2da_mem[ent + 88 + 2 * 4 + 1] = uint8(c2da_fresh66 >> 0x8)
    c2da_mem[ent + 88 + 2 * 4 + 2] = uint8(c2da_fresh66 >> 0x10)
    c2da_mem[ent + 88 + 2 * 4 + 3] = uint8(c2da_fresh66 >> 0x18)
    let c2da_fresh67 : float = uint_bits_to_float(uint(c2da_mem[ent + 20 + 0 * 4]) | uint(c2da_mem[ent + 20 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 20 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 20 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh68 : uint = float_bits_to_uint(c2da_fresh67)
    c2da_mem[ent + 124 + 0 * 4] = uint8(c2da_fresh68)
    c2da_mem[ent + 124 + 0 * 4 + 1] = uint8(c2da_fresh68 >> 0x8)
    c2da_mem[ent + 124 + 0 * 4 + 2] = uint8(c2da_fresh68 >> 0x10)
    c2da_mem[ent + 124 + 0 * 4 + 3] = uint8(c2da_fresh68 >> 0x18)
    let c2da_fresh69 : float = uint_bits_to_float(uint(c2da_mem[ent + 20 + 1 * 4]) | uint(c2da_mem[ent + 20 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 20 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 20 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh70 : uint = float_bits_to_uint(c2da_fresh69)
    c2da_mem[ent + 124 + 1 * 4] = uint8(c2da_fresh70)
    c2da_mem[ent + 124 + 1 * 4 + 1] = uint8(c2da_fresh70 >> 0x8)
    c2da_mem[ent + 124 + 1 * 4 + 2] = uint8(c2da_fresh70 >> 0x10)
    c2da_mem[ent + 124 + 1 * 4 + 3] = uint8(c2da_fresh70 >> 0x18)
    let c2da_fresh71 : float = uint_bits_to_float(uint(c2da_mem[ent + 20 + 2 * 4]) | uint(c2da_mem[ent + 20 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 20 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 20 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh72 : uint = float_bits_to_uint(c2da_fresh71)
    c2da_mem[ent + 124 + 2 * 4] = uint8(c2da_fresh72)
    c2da_mem[ent + 124 + 2 * 4 + 1] = uint8(c2da_fresh72 >> 0x8)
    c2da_mem[ent + 124 + 2 * 4 + 2] = uint8(c2da_fresh72 >> 0x10)
    c2da_mem[ent + 124 + 2 * 4 + 3] = uint8(c2da_fresh72 >> 0x18)
    R_AddEfrags(ent)
    return
}
[export, sideeffects]
def CL_ParseBaseline(var ent_0 : int) {
    let c2da_fresh73 : int = MSG_ReadByte()
    let c2da_fresh74 : uint = uint(c2da_fresh73)
    c2da_mem[ent_0 + 32] = uint8(c2da_fresh74)
    c2da_mem[ent_0 + 33] = uint8(c2da_fresh74 >> 0x8)
    c2da_mem[ent_0 + 34] = uint8(c2da_fresh74 >> 0x10)
    c2da_mem[ent_0 + 35] = uint8(c2da_fresh74 >> 0x18)
    let c2da_fresh75 : int = MSG_ReadByte()
    let c2da_fresh76 : uint = uint(c2da_fresh75)
    c2da_mem[ent_0 + 36] = uint8(c2da_fresh76)
    c2da_mem[ent_0 + 37] = uint8(c2da_fresh76 >> 0x8)
    c2da_mem[ent_0 + 38] = uint8(c2da_fresh76 >> 0x10)
    c2da_mem[ent_0 + 39] = uint8(c2da_fresh76 >> 0x18)
    let c2da_fresh77 : int = MSG_ReadByte()
    let c2da_fresh78 : uint = uint(c2da_fresh77)
    c2da_mem[ent_0 + 40] = uint8(c2da_fresh78)
    c2da_mem[ent_0 + 41] = uint8(c2da_fresh78 >> 0x8)
    c2da_mem[ent_0 + 42] = uint8(c2da_fresh78 >> 0x10)
    c2da_mem[ent_0 + 43] = uint8(c2da_fresh78 >> 0x18)
    let c2da_fresh79 : int = MSG_ReadByte()
    let c2da_fresh80 : uint = uint(c2da_fresh79)
    c2da_mem[ent_0 + 44] = uint8(c2da_fresh80)
    c2da_mem[ent_0 + 45] = uint8(c2da_fresh80 >> 0x8)
    c2da_mem[ent_0 + 46] = uint8(c2da_fresh80 >> 0x10)
    c2da_mem[ent_0 + 47] = uint8(c2da_fresh80 >> 0x18)
    for (i_2 in range(0, 3)) {
        let c2da_fresh81 : float = MSG_ReadCoord()
        let c2da_fresh82 : uint = float_bits_to_uint(c2da_fresh81)
        c2da_mem[ent_0 + 8 + i_2 * 4] = uint8(c2da_fresh82)
        c2da_mem[ent_0 + 8 + i_2 * 4 + 1] = uint8(c2da_fresh82 >> 0x8)
        c2da_mem[ent_0 + 8 + i_2 * 4 + 2] = uint8(c2da_fresh82 >> 0x10)
        c2da_mem[ent_0 + 8 + i_2 * 4 + 3] = uint8(c2da_fresh82 >> 0x18)
        let c2da_fresh83 : float = MSG_ReadAngle()
        let c2da_fresh84 : uint = float_bits_to_uint(c2da_fresh83)
        c2da_mem[ent_0 + 20 + i_2 * 4] = uint8(c2da_fresh84)
        c2da_mem[ent_0 + 20 + i_2 * 4 + 1] = uint8(c2da_fresh84 >> 0x8)
        c2da_mem[ent_0 + 20 + i_2 * 4 + 2] = uint8(c2da_fresh84 >> 0x10)
        c2da_mem[ent_0 + 20 + i_2 * 4 + 3] = uint8(c2da_fresh84 >> 0x18)
    }
    return
}
[export, sideeffects]
def CL_EntityNum(var num : int) : int {
    if (num >= int(uint(c2da_mem[4976]) | uint(c2da_mem[4977]) << 0x8 | uint(c2da_mem[4978]) << 0x10 | uint(c2da_mem[4979]) << 0x18)) {
        if (num >= 600) {
            Host_Error(699309, [C2daVaArg(tag = 1, i64 = int64(num), f64 = 0.0lf, raw = 0x0)])
        }
        while (int(uint(c2da_mem[4976]) | uint(c2da_mem[4977]) << 0x8 | uint(c2da_mem[4978]) << 0x10 | uint(c2da_mem[4979]) << 0x18) <= num) {
            let c2da_fresh85 : int = 10048 + int(uint(c2da_mem[4976]) | uint(c2da_mem[4977]) << 0x8 | uint(c2da_mem[4978]) << 0x10 | uint(c2da_mem[4979]) << 0x18) * 200 + 160
            let c2da_fresh86 : int = vid.colormap
            let c2da_fresh87 : uint = uint(c2da_fresh86)
            c2da_mem[c2da_fresh85] = uint8(c2da_fresh87)
            c2da_mem[c2da_fresh85 + 1] = uint8(c2da_fresh87 >> 0x8)
            c2da_mem[c2da_fresh85 + 2] = uint8(c2da_fresh87 >> 0x10)
            c2da_mem[c2da_fresh85 + 3] = uint8(c2da_fresh87 >> 0x18)
            c2da_mem[c2da_fresh85 + 4] = 0u8
            c2da_mem[c2da_fresh85 + 5] = 0u8
            c2da_mem[c2da_fresh85 + 6] = 0u8
            c2da_mem[c2da_fresh85 + 7] = 0u8
            let c2da_fresh88 : int = int(uint(c2da_mem[4976]) | uint(c2da_mem[4977]) << 0x8 | uint(c2da_mem[4978]) << 0x10 | uint(c2da_mem[4979]) << 0x18)
            let c2da_fresh89 : int = c2da_fresh88 + 1
            let c2da_fresh90 : uint = uint(c2da_fresh89)
            c2da_mem[4976] = uint8(c2da_fresh90)
            c2da_mem[4977] = uint8(c2da_fresh90 >> 0x8)
            c2da_mem[4978] = uint8(c2da_fresh90 >> 0x10)
            c2da_mem[4979] = uint8(c2da_fresh90 >> 0x18)
        }
    }
    return 10048 + num * 200
}
[export, sideeffects]
def CL_NewTranslation(var slot : int) {
    var i_3 : int
    var j : int
    var top : int
    var bottom : int
    var dest : int
    var source : int
    if (slot > int(uint(c2da_mem[4948]) | uint(c2da_mem[4949]) << 0x8 | uint(c2da_mem[4950]) << 0x10 | uint(c2da_mem[4951]) << 0x18)) {
        Sys_Error(699347, [])
    }
    dest = int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + slot * 16428 + 44
    source = vid.colormap
    c2da_lin_memcpy(dest, int(vid.colormap), 16384ul)
    let c2da_fresh91 : int = int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + slot * 16428 + 40
    top = int(uint(c2da_mem[c2da_fresh91]) | uint(c2da_mem[c2da_fresh91 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh91 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh91 + 3]) << 0x18) & 240
    let c2da_fresh92 : int = int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + slot * 16428 + 40
    bottom = (int(uint(c2da_mem[c2da_fresh92]) | uint(c2da_mem[c2da_fresh92 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh92 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh92 + 3]) << 0x18) & 15) << 4
    i_3 = 0
    while (i_3 < 1 << 6) {
        if (top < 128) {
            c2da_lin_memcpy(dest + 16, source + top, 16ul)
        } else {
            j = 0
            while (j < 16) {
                let c2da_fresh93 : uint8 = c2da_mem[source + (top + 15 - j)]
                c2da_mem[dest + (16 + j)] = c2da_fresh93
                j++
            }
        }
        if (bottom < 128) {
            c2da_lin_memcpy(dest + 96, source + bottom, 16ul)
        } else {
            j = 0
            while (j < 16) {
                let c2da_fresh94 : uint8 = c2da_mem[source + (bottom + 15 - j)]
                c2da_mem[dest + (96 + j)] = c2da_fresh94
                j++
            }
        }
        i_3++
        dest += 256
        source += 256
    }
    return
}
[export, sideeffects]
def CL_ParseStartSoundPacket() {
    let c2da_saved_sp : int = c2da_lin_sp
    CL_ParseStartSoundPacket_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def CL_ParseServerInfo() {
    let c2da_saved_sp : int = c2da_lin_sp
    CL_ParseServerInfo_c2da_frame(c2da_lin_enter(32768))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def CL_KeepaliveMessage() {
    let c2da_saved_sp : int = c2da_lin_sp
    CL_KeepaliveMessage_c2da_frame(c2da_lin_enter(8192))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def CL_ParseClientdata(var bits : int) {
    var i_6 : int
    var j_0 : int
    if ((bits & 1 << 0) != 0) {
        let c2da_fresh116 : float = float(MSG_ReadChar())
        let c2da_fresh117 : uint = float_bits_to_uint(c2da_fresh116)
        c2da_mem[736] = uint8(c2da_fresh117)
        c2da_mem[737] = uint8(c2da_fresh117 >> 0x8)
        c2da_mem[738] = uint8(c2da_fresh117 >> 0x10)
        c2da_mem[739] = uint8(c2da_fresh117 >> 0x18)
    } else {
        let c2da_fresh118 : float = 22.0
        let c2da_fresh119 : uint = float_bits_to_uint(c2da_fresh118)
        c2da_mem[736] = uint8(c2da_fresh119)
        c2da_mem[737] = uint8(c2da_fresh119 >> 0x8)
        c2da_mem[738] = uint8(c2da_fresh119 >> 0x10)
        c2da_mem[739] = uint8(c2da_fresh119 >> 0x18)
    }
    if ((bits & 1 << 1) != 0) {
        let c2da_fresh120 : float = float(MSG_ReadChar())
        let c2da_fresh121 : uint = float_bits_to_uint(c2da_fresh120)
        c2da_mem[712] = uint8(c2da_fresh121)
        c2da_mem[713] = uint8(c2da_fresh121 >> 0x8)
        c2da_mem[714] = uint8(c2da_fresh121 >> 0x10)
        c2da_mem[715] = uint8(c2da_fresh121 >> 0x18)
    } else {
        let c2da_fresh122 : float = 0.0
        let c2da_fresh123 : uint = float_bits_to_uint(c2da_fresh122)
        c2da_mem[712] = uint8(c2da_fresh123)
        c2da_mem[713] = uint8(c2da_fresh123 >> 0x8)
        c2da_mem[714] = uint8(c2da_fresh123 >> 0x10)
        c2da_mem[715] = uint8(c2da_fresh123 >> 0x18)
    }
    let c2da_fresh124 : float = uint_bits_to_float(uint(c2da_mem[664 + 0 * 12 + 0 * 4]) | uint(c2da_mem[664 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[664 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[664 + 0 * 12 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh125 : uint = float_bits_to_uint(c2da_fresh124)
    c2da_mem[664 + 1 * 12 + 0 * 4] = uint8(c2da_fresh125)
    c2da_mem[664 + 1 * 12 + 0 * 4 + 1] = uint8(c2da_fresh125 >> 0x8)
    c2da_mem[664 + 1 * 12 + 0 * 4 + 2] = uint8(c2da_fresh125 >> 0x10)
    c2da_mem[664 + 1 * 12 + 0 * 4 + 3] = uint8(c2da_fresh125 >> 0x18)
    let c2da_fresh126 : float = uint_bits_to_float(uint(c2da_mem[664 + 0 * 12 + 1 * 4]) | uint(c2da_mem[664 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[664 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[664 + 0 * 12 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh127 : uint = float_bits_to_uint(c2da_fresh126)
    c2da_mem[664 + 1 * 12 + 1 * 4] = uint8(c2da_fresh127)
    c2da_mem[664 + 1 * 12 + 1 * 4 + 1] = uint8(c2da_fresh127 >> 0x8)
    c2da_mem[664 + 1 * 12 + 1 * 4 + 2] = uint8(c2da_fresh127 >> 0x10)
    c2da_mem[664 + 1 * 12 + 1 * 4 + 3] = uint8(c2da_fresh127 >> 0x18)
    let c2da_fresh128 : float = uint_bits_to_float(uint(c2da_mem[664 + 0 * 12 + 2 * 4]) | uint(c2da_mem[664 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[664 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[664 + 0 * 12 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh129 : uint = float_bits_to_uint(c2da_fresh128)
    c2da_mem[664 + 1 * 12 + 2 * 4] = uint8(c2da_fresh129)
    c2da_mem[664 + 1 * 12 + 2 * 4 + 1] = uint8(c2da_fresh129 >> 0x8)
    c2da_mem[664 + 1 * 12 + 2 * 4 + 2] = uint8(c2da_fresh129 >> 0x10)
    c2da_mem[664 + 1 * 12 + 2 * 4 + 3] = uint8(c2da_fresh129 >> 0x18)
    i_6 = 0
    for (c2da_i_6 in range(i_6, 3)) {
        if ((bits & 1 << 2 << c2da_i_6) != 0) {
            let c2da_fresh130 : float = float(MSG_ReadChar())
            let c2da_fresh131 : uint = float_bits_to_uint(c2da_fresh130)
            c2da_mem[700 + c2da_i_6 * 4] = uint8(c2da_fresh131)
            c2da_mem[700 + c2da_i_6 * 4 + 1] = uint8(c2da_fresh131 >> 0x8)
            c2da_mem[700 + c2da_i_6 * 4 + 2] = uint8(c2da_fresh131 >> 0x10)
            c2da_mem[700 + c2da_i_6 * 4 + 3] = uint8(c2da_fresh131 >> 0x18)
        } else {
            let c2da_fresh132 : float = 0.0
            let c2da_fresh133 : uint = float_bits_to_uint(c2da_fresh132)
            c2da_mem[700 + c2da_i_6 * 4] = uint8(c2da_fresh133)
            c2da_mem[700 + c2da_i_6 * 4 + 1] = uint8(c2da_fresh133 >> 0x8)
            c2da_mem[700 + c2da_i_6 * 4 + 2] = uint8(c2da_fresh133 >> 0x10)
            c2da_mem[700 + c2da_i_6 * 4 + 3] = uint8(c2da_fresh133 >> 0x18)
        }
        if ((bits & 1 << 5 << c2da_i_6) != 0) {
            let c2da_fresh134 : float = float(MSG_ReadChar() * 16)
            let c2da_fresh135 : uint = float_bits_to_uint(c2da_fresh134)
            c2da_mem[664 + 0 * 12 + c2da_i_6 * 4] = uint8(c2da_fresh135)
            c2da_mem[664 + 0 * 12 + c2da_i_6 * 4 + 1] = uint8(c2da_fresh135 >> 0x8)
            c2da_mem[664 + 0 * 12 + c2da_i_6 * 4 + 2] = uint8(c2da_fresh135 >> 0x10)
            c2da_mem[664 + 0 * 12 + c2da_i_6 * 4 + 3] = uint8(c2da_fresh135 >> 0x18)
        } else {
            let c2da_fresh136 : float = 0.0
            let c2da_fresh137 : uint = float_bits_to_uint(c2da_fresh136)
            c2da_mem[664 + 0 * 12 + c2da_i_6 * 4] = uint8(c2da_fresh137)
            c2da_mem[664 + 0 * 12 + c2da_i_6 * 4 + 1] = uint8(c2da_fresh137 >> 0x8)
            c2da_mem[664 + 0 * 12 + c2da_i_6 * 4 + 2] = uint8(c2da_fresh137 >> 0x10)
            c2da_mem[664 + 0 * 12 + c2da_i_6 * 4 + 3] = uint8(c2da_fresh137 >> 0x18)
        }
    }
    i_6 = MSG_ReadLong()
    if (int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) != i_6) {
        Sbar_Changed()
        j_0 = 0
        while (j_0 < 32) {
            if ((i_6 & 1 << j_0) != 0 && (int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 1 << j_0) == 0) {
                let c2da_fresh138 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20))
                let c2da_fresh139 : uint = float_bits_to_uint(c2da_fresh138)
                c2da_mem[368 + j_0 * 4] = uint8(c2da_fresh139)
                c2da_mem[368 + j_0 * 4 + 1] = uint8(c2da_fresh139 >> 0x8)
                c2da_mem[368 + j_0 * 4 + 2] = uint8(c2da_fresh139 >> 0x10)
                c2da_mem[368 + j_0 * 4 + 3] = uint8(c2da_fresh139 >> 0x18)
            }
            j_0++
        }
        let c2da_fresh140 : uint = uint(i_6)
        c2da_mem[364] = uint8(c2da_fresh140)
        c2da_mem[365] = uint8(c2da_fresh140 >> 0x8)
        c2da_mem[366] = uint8(c2da_fresh140 >> 0x10)
        c2da_mem[367] = uint8(c2da_fresh140 >> 0x18)
    }
    let c2da_fresh141 : uint = uint((bits & 1 << 10) != 0 ? 1 : 0)
    let c2da_fresh142 : uint = c2da_fresh141
    c2da_mem[748] = uint8(c2da_fresh142)
    c2da_mem[749] = uint8(c2da_fresh142 >> 0x8)
    c2da_mem[750] = uint8(c2da_fresh142 >> 0x10)
    c2da_mem[751] = uint8(c2da_fresh142 >> 0x18)
    let c2da_fresh143 : uint = uint((bits & 1 << 11) != 0 ? 1 : 0)
    let c2da_fresh144 : uint = c2da_fresh143
    c2da_mem[752] = uint8(c2da_fresh144)
    c2da_mem[753] = uint8(c2da_fresh144 >> 0x8)
    c2da_mem[754] = uint8(c2da_fresh144 >> 0x10)
    c2da_mem[755] = uint8(c2da_fresh144 >> 0x18)
    if ((bits & 1 << 12) != 0) {
        let c2da_fresh145 : int = MSG_ReadByte()
        let c2da_fresh146 : uint = uint(c2da_fresh145)
        c2da_mem[236 + 5 * 4] = uint8(c2da_fresh146)
        c2da_mem[236 + 5 * 4 + 1] = uint8(c2da_fresh146 >> 0x8)
        c2da_mem[236 + 5 * 4 + 2] = uint8(c2da_fresh146 >> 0x10)
        c2da_mem[236 + 5 * 4 + 3] = uint8(c2da_fresh146 >> 0x18)
    } else {
        let c2da_fresh147 : int = 0
        let c2da_fresh148 : uint = uint(c2da_fresh147)
        c2da_mem[236 + 5 * 4] = uint8(c2da_fresh148)
        c2da_mem[236 + 5 * 4 + 1] = uint8(c2da_fresh148 >> 0x8)
        c2da_mem[236 + 5 * 4 + 2] = uint8(c2da_fresh148 >> 0x10)
        c2da_mem[236 + 5 * 4 + 3] = uint8(c2da_fresh148 >> 0x18)
    }
    if ((bits & 1 << 13) != 0) {
        i_6 = MSG_ReadByte()
    } else {
        i_6 = 0
    }
    if (int(uint(c2da_mem[236 + 4 * 4]) | uint(c2da_mem[236 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 4 * 4 + 3]) << 0x18) != i_6) {
        let c2da_fresh149 : uint = uint(i_6)
        c2da_mem[236 + 4 * 4] = uint8(c2da_fresh149)
        c2da_mem[236 + 4 * 4 + 1] = uint8(c2da_fresh149 >> 0x8)
        c2da_mem[236 + 4 * 4 + 2] = uint8(c2da_fresh149 >> 0x10)
        c2da_mem[236 + 4 * 4 + 3] = uint8(c2da_fresh149 >> 0x18)
        Sbar_Changed()
    }
    if ((bits & 1 << 14) != 0) {
        i_6 = MSG_ReadByte()
    } else {
        i_6 = 0
    }
    if (int(uint(c2da_mem[236 + 2 * 4]) | uint(c2da_mem[236 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 2 * 4 + 3]) << 0x18) != i_6) {
        let c2da_fresh150 : uint = uint(i_6)
        c2da_mem[236 + 2 * 4] = uint8(c2da_fresh150)
        c2da_mem[236 + 2 * 4 + 1] = uint8(c2da_fresh150 >> 0x8)
        c2da_mem[236 + 2 * 4 + 2] = uint8(c2da_fresh150 >> 0x10)
        c2da_mem[236 + 2 * 4 + 3] = uint8(c2da_fresh150 >> 0x18)
        Sbar_Changed()
    }
    i_6 = MSG_ReadShort()
    if (int(uint(c2da_mem[236 + 0 * 4]) | uint(c2da_mem[236 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 0 * 4 + 3]) << 0x18) != i_6) {
        let c2da_fresh151 : uint = uint(i_6)
        c2da_mem[236 + 0 * 4] = uint8(c2da_fresh151)
        c2da_mem[236 + 0 * 4 + 1] = uint8(c2da_fresh151 >> 0x8)
        c2da_mem[236 + 0 * 4 + 2] = uint8(c2da_fresh151 >> 0x10)
        c2da_mem[236 + 0 * 4 + 3] = uint8(c2da_fresh151 >> 0x18)
        Sbar_Changed()
    }
    i_6 = MSG_ReadByte()
    if (int(uint(c2da_mem[236 + 3 * 4]) | uint(c2da_mem[236 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 3 * 4 + 3]) << 0x18) != i_6) {
        let c2da_fresh152 : uint = uint(i_6)
        c2da_mem[236 + 3 * 4] = uint8(c2da_fresh152)
        c2da_mem[236 + 3 * 4 + 1] = uint8(c2da_fresh152 >> 0x8)
        c2da_mem[236 + 3 * 4 + 2] = uint8(c2da_fresh152 >> 0x10)
        c2da_mem[236 + 3 * 4 + 3] = uint8(c2da_fresh152 >> 0x18)
        Sbar_Changed()
    }
    i_6 = 0
    for (c2da_i_6_0 in range(i_6, 4)) {
        j_0 = MSG_ReadByte()
        if (int(uint(c2da_mem[236 + (6 + c2da_i_6_0) * 4]) | uint(c2da_mem[236 + (6 + c2da_i_6_0) * 4 + 1]) << 0x8 | uint(c2da_mem[236 + (6 + c2da_i_6_0) * 4 + 2]) << 0x10 | uint(c2da_mem[236 + (6 + c2da_i_6_0) * 4 + 3]) << 0x18) != j_0) {
            let c2da_fresh153 : uint = uint(j_0)
            c2da_mem[236 + (6 + c2da_i_6_0) * 4] = uint8(c2da_fresh153)
            c2da_mem[236 + (6 + c2da_i_6_0) * 4 + 1] = uint8(c2da_fresh153 >> 0x8)
            c2da_mem[236 + (6 + c2da_i_6_0) * 4 + 2] = uint8(c2da_fresh153 >> 0x10)
            c2da_mem[236 + (6 + c2da_i_6_0) * 4 + 3] = uint8(c2da_fresh153 >> 0x18)
            Sbar_Changed()
        }
    }
    i_6 = MSG_ReadByte()
    if (uint(standard_quake) != 0u) {
        if (int(uint(c2da_mem[236 + 10 * 4]) | uint(c2da_mem[236 + 10 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 10 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 10 * 4 + 3]) << 0x18) != i_6) {
            let c2da_fresh154 : uint = uint(i_6)
            c2da_mem[236 + 10 * 4] = uint8(c2da_fresh154)
            c2da_mem[236 + 10 * 4 + 1] = uint8(c2da_fresh154 >> 0x8)
            c2da_mem[236 + 10 * 4 + 2] = uint8(c2da_fresh154 >> 0x10)
            c2da_mem[236 + 10 * 4 + 3] = uint8(c2da_fresh154 >> 0x18)
            Sbar_Changed()
        }
    } elif (int(uint(c2da_mem[236 + 10 * 4]) | uint(c2da_mem[236 + 10 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 10 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 10 * 4 + 3]) << 0x18) != 1 << i_6) {
        let c2da_fresh155 : int = 1 << i_6
        let c2da_fresh156 : uint = uint(c2da_fresh155)
        c2da_mem[236 + 10 * 4] = uint8(c2da_fresh156)
        c2da_mem[236 + 10 * 4 + 1] = uint8(c2da_fresh156 >> 0x8)
        c2da_mem[236 + 10 * 4 + 2] = uint8(c2da_fresh156 >> 0x10)
        c2da_mem[236 + 10 * 4 + 3] = uint8(c2da_fresh156 >> 0x18)
        Sbar_Changed()
    }
    return
}
var svc_strings : int[35] = fixed_array<int>(699827, 699835, 699843, 699858, 699873, 699885, 699897, 699907, 699916, 699926, 699940, 699953, 699968, 699983, 699998, 700014, 700029, 700043, 700060, 700073, 700084, 700100, 700125, 700143, 700159, 700172, 700186, 700202, 700220, 700236, 700257, 700274, 700285, 700297, 700312)

[export, sideeffects]
def CL_ParseUpdate(var bits_0 : int) {
    var i_7 : int
    var model : int
    var modnum : int
    var forcelink : uint
    var ent_2 : int
    var num_0 : int
    var skin : int
    if (int(uint(c2da_mem[7804]) | uint(c2da_mem[7805]) << 0x8 | uint(c2da_mem[7806]) << 0x10 | uint(c2da_mem[7807]) << 0x18) == 4 - 1) {
        let c2da_fresh157 : int = 4
        let c2da_fresh158 : uint = uint(c2da_fresh157)
        c2da_mem[7804] = uint8(c2da_fresh158)
        c2da_mem[7805] = uint8(c2da_fresh158 >> 0x8)
        c2da_mem[7806] = uint8(c2da_fresh158 >> 0x10)
        c2da_mem[7807] = uint8(c2da_fresh158 >> 0x18)
        CL_SignonReply()
    }
    if ((bits_0 & 1 << 0) != 0) {
        i_7 = MSG_ReadByte()
        bits_0 |= i_7 << 8
    }
    if ((bits_0 & 1 << 14) != 0) {
        num_0 = MSG_ReadShort()
    } else {
        num_0 = MSG_ReadByte()
    }
    ent_2 = CL_EntityNum(num_0)
    i_7 = 0
    while (i_7 < 16) {
        if ((bits_0 & 1 << i_7) != 0) {
            bitcounts[i_7]++
        }
        i_7++
    }
    if (uint64_bits_to_double(uint64(uint(c2da_mem[ent_2 + 56]) | uint(c2da_mem[ent_2 + 57]) << 0x8 | uint(c2da_mem[ent_2 + 58]) << 0x10 | uint(c2da_mem[ent_2 + 59]) << 0x18) | uint64(uint(c2da_mem[ent_2 + 60]) | uint(c2da_mem[ent_2 + 61]) << 0x8 | uint(c2da_mem[ent_2 + 62]) << 0x10 | uint(c2da_mem[ent_2 + 63]) << 0x18) << 0x20) != uint64_bits_to_double(uint64(uint(c2da_mem[768 + 1 * 8]) | uint(c2da_mem[768 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[768 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[768 + 1 * 8 + 3]) << 0x18) | uint64(uint(c2da_mem[768 + 1 * 8 + 4]) | uint(c2da_mem[768 + 1 * 8 + 5]) << 0x8 | uint(c2da_mem[768 + 1 * 8 + 6]) << 0x10 | uint(c2da_mem[768 + 1 * 8 + 7]) << 0x18) << 0x20)) {
        forcelink = 1u
    } else {
        forcelink = 0u
    }
    let c2da_fresh159 : double = uint64_bits_to_double(uint64(uint(c2da_mem[768 + 0 * 8]) | uint(c2da_mem[768 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 3]) << 0x18) | uint64(uint(c2da_mem[768 + 0 * 8 + 4]) | uint(c2da_mem[768 + 0 * 8 + 5]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 6]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 7]) << 0x18) << 0x20)
    let c2da_fresh160 : uint64 = double_bits_to_uint64(c2da_fresh159)
    c2da_mem[ent_2 + 56] = uint8(c2da_fresh160)
    c2da_mem[ent_2 + 57] = uint8(c2da_fresh160 >> 0x8)
    c2da_mem[ent_2 + 58] = uint8(c2da_fresh160 >> 0x10)
    c2da_mem[ent_2 + 59] = uint8(c2da_fresh160 >> 0x18)
    c2da_mem[ent_2 + 60] = uint8(c2da_fresh160 >> 0x20)
    c2da_mem[ent_2 + 61] = uint8(c2da_fresh160 >> 0x28)
    c2da_mem[ent_2 + 62] = uint8(c2da_fresh160 >> 0x30)
    c2da_mem[ent_2 + 63] = uint8(c2da_fresh160 >> 0x38)
    if ((bits_0 & 1 << 10) != 0) {
        modnum = MSG_ReadByte()
        if (modnum >= 256) {
            Host_Error(700325, [])
        }
    } else {
        modnum = int(uint(c2da_mem[ent_2 + 32]) | uint(c2da_mem[ent_2 + 33]) << 0x8 | uint(c2da_mem[ent_2 + 34]) << 0x10 | uint(c2da_mem[ent_2 + 35]) << 0x18)
    }
    model = int(uint(c2da_mem[808 + modnum * 8]) | uint(c2da_mem[808 + modnum * 8 + 1]) << 0x8 | uint(c2da_mem[808 + modnum * 8 + 2]) << 0x10 | uint(c2da_mem[808 + modnum * 8 + 3]) << 0x18)
    if (model != int(uint(c2da_mem[ent_2 + 136]) | uint(c2da_mem[ent_2 + 137]) << 0x8 | uint(c2da_mem[ent_2 + 138]) << 0x10 | uint(c2da_mem[ent_2 + 139]) << 0x18)) {
        let c2da_fresh161 : uint = uint(model)
        c2da_mem[ent_2 + 136] = uint8(c2da_fresh161)
        c2da_mem[ent_2 + 137] = uint8(c2da_fresh161 >> 0x8)
        c2da_mem[ent_2 + 138] = uint8(c2da_fresh161 >> 0x10)
        c2da_mem[ent_2 + 139] = uint8(c2da_fresh161 >> 0x18)
        c2da_mem[ent_2 + 140] = 0u8
        c2da_mem[ent_2 + 141] = 0u8
        c2da_mem[ent_2 + 142] = 0u8
        c2da_mem[ent_2 + 143] = 0u8
        if (model != 0) {
            if ((uint(c2da_mem[model + 76]) | uint(c2da_mem[model + 77]) << 0x8 | uint(c2da_mem[model + 78]) << 0x10 | uint(c2da_mem[model + 79]) << 0x18) == 1u) {
                let c2da_fresh162 : float = float(c2da_std_rand() & 32767) / 32767.0
                let c2da_fresh163 : uint = float_bits_to_uint(c2da_fresh162)
                c2da_mem[ent_2 + 156] = uint8(c2da_fresh163)
                c2da_mem[ent_2 + 157] = uint8(c2da_fresh163 >> 0x8)
                c2da_mem[ent_2 + 158] = uint8(c2da_fresh163 >> 0x10)
                c2da_mem[ent_2 + 159] = uint8(c2da_fresh163 >> 0x18)
            } else {
                let c2da_fresh164 : float = 0.0
                let c2da_fresh165 : uint = float_bits_to_uint(c2da_fresh164)
                c2da_mem[ent_2 + 156] = uint8(c2da_fresh165)
                c2da_mem[ent_2 + 157] = uint8(c2da_fresh165 >> 0x8)
                c2da_mem[ent_2 + 158] = uint8(c2da_fresh165 >> 0x10)
                c2da_mem[ent_2 + 159] = uint8(c2da_fresh165 >> 0x18)
            }
        } else {
            forcelink = 1u
        }
    }
    if ((bits_0 & 1 << 6) != 0) {
        let c2da_fresh166 : int = MSG_ReadByte()
        let c2da_fresh167 : uint = uint(c2da_fresh166)
        c2da_mem[ent_2 + 152] = uint8(c2da_fresh167)
        c2da_mem[ent_2 + 153] = uint8(c2da_fresh167 >> 0x8)
        c2da_mem[ent_2 + 154] = uint8(c2da_fresh167 >> 0x10)
        c2da_mem[ent_2 + 155] = uint8(c2da_fresh167 >> 0x18)
    } else {
        let c2da_fresh168 : int = int(uint(c2da_mem[ent_2 + 36]) | uint(c2da_mem[ent_2 + 37]) << 0x8 | uint(c2da_mem[ent_2 + 38]) << 0x10 | uint(c2da_mem[ent_2 + 39]) << 0x18)
        let c2da_fresh169 : uint = uint(c2da_fresh168)
        c2da_mem[ent_2 + 152] = uint8(c2da_fresh169)
        c2da_mem[ent_2 + 153] = uint8(c2da_fresh169 >> 0x8)
        c2da_mem[ent_2 + 154] = uint8(c2da_fresh169 >> 0x10)
        c2da_mem[ent_2 + 155] = uint8(c2da_fresh169 >> 0x18)
    }
    if ((bits_0 & 1 << 11) != 0) {
        i_7 = MSG_ReadByte()
    } else {
        i_7 = int(uint(c2da_mem[ent_2 + 40]) | uint(c2da_mem[ent_2 + 41]) << 0x8 | uint(c2da_mem[ent_2 + 42]) << 0x10 | uint(c2da_mem[ent_2 + 43]) << 0x18)
    }
    if (i_7 == 0) {
        let c2da_fresh170 : int = vid.colormap
        let c2da_fresh171 : uint = uint(c2da_fresh170)
        c2da_mem[ent_2 + 160] = uint8(c2da_fresh171)
        c2da_mem[ent_2 + 161] = uint8(c2da_fresh171 >> 0x8)
        c2da_mem[ent_2 + 162] = uint8(c2da_fresh171 >> 0x10)
        c2da_mem[ent_2 + 163] = uint8(c2da_fresh171 >> 0x18)
        c2da_mem[ent_2 + 164] = 0u8
        c2da_mem[ent_2 + 165] = 0u8
        c2da_mem[ent_2 + 166] = 0u8
        c2da_mem[ent_2 + 167] = 0u8
    } else {
        if (i_7 > int(uint(c2da_mem[4948]) | uint(c2da_mem[4949]) << 0x8 | uint(c2da_mem[4950]) << 0x10 | uint(c2da_mem[4951]) << 0x18)) {
            Sys_Error(700351, [])
        }
        let c2da_fresh172 : int = int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + (i_7 - 1) * 16428 + 44
        let c2da_fresh173 : uint = uint(c2da_fresh172)
        c2da_mem[ent_2 + 160] = uint8(c2da_fresh173)
        c2da_mem[ent_2 + 161] = uint8(c2da_fresh173 >> 0x8)
        c2da_mem[ent_2 + 162] = uint8(c2da_fresh173 >> 0x10)
        c2da_mem[ent_2 + 163] = uint8(c2da_fresh173 >> 0x18)
        c2da_mem[ent_2 + 164] = 0u8
        c2da_mem[ent_2 + 165] = 0u8
        c2da_mem[ent_2 + 166] = 0u8
        c2da_mem[ent_2 + 167] = 0u8
    }
    if ((bits_0 & 1 << 12) != 0) {
        let c2da_fresh174 : int = MSG_ReadByte()
        let c2da_fresh175 : uint = uint(c2da_fresh174)
        c2da_mem[ent_2 + 172] = uint8(c2da_fresh175)
        c2da_mem[ent_2 + 173] = uint8(c2da_fresh175 >> 0x8)
        c2da_mem[ent_2 + 174] = uint8(c2da_fresh175 >> 0x10)
        c2da_mem[ent_2 + 175] = uint8(c2da_fresh175 >> 0x18)
    } else {
        let c2da_fresh176 : int = int(uint(c2da_mem[ent_2 + 44]) | uint(c2da_mem[ent_2 + 45]) << 0x8 | uint(c2da_mem[ent_2 + 46]) << 0x10 | uint(c2da_mem[ent_2 + 47]) << 0x18)
        let c2da_fresh177 : uint = uint(c2da_fresh176)
        c2da_mem[ent_2 + 172] = uint8(c2da_fresh177)
        c2da_mem[ent_2 + 173] = uint8(c2da_fresh177 >> 0x8)
        c2da_mem[ent_2 + 174] = uint8(c2da_fresh177 >> 0x10)
        c2da_mem[ent_2 + 175] = uint8(c2da_fresh177 >> 0x18)
    }
    if ((bits_0 & 1 << 13) != 0) {
        let c2da_fresh178 : int = MSG_ReadByte()
        let c2da_fresh179 : uint = uint(c2da_fresh178)
        c2da_mem[ent_2 + 168] = uint8(c2da_fresh179)
        c2da_mem[ent_2 + 169] = uint8(c2da_fresh179 >> 0x8)
        c2da_mem[ent_2 + 170] = uint8(c2da_fresh179 >> 0x10)
        c2da_mem[ent_2 + 171] = uint8(c2da_fresh179 >> 0x18)
    } else {
        let c2da_fresh180 : int = int(uint(c2da_mem[ent_2 + 48]) | uint(c2da_mem[ent_2 + 49]) << 0x8 | uint(c2da_mem[ent_2 + 50]) << 0x10 | uint(c2da_mem[ent_2 + 51]) << 0x18)
        let c2da_fresh181 : uint = uint(c2da_fresh180)
        c2da_mem[ent_2 + 168] = uint8(c2da_fresh181)
        c2da_mem[ent_2 + 169] = uint8(c2da_fresh181 >> 0x8)
        c2da_mem[ent_2 + 170] = uint8(c2da_fresh181 >> 0x10)
        c2da_mem[ent_2 + 171] = uint8(c2da_fresh181 >> 0x18)
    }
    let c2da_fresh182 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4]) | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh183 : uint = float_bits_to_uint(c2da_fresh182)
    c2da_mem[ent_2 + 64 + 1 * 12 + 0 * 4] = uint8(c2da_fresh183)
    c2da_mem[ent_2 + 64 + 1 * 12 + 0 * 4 + 1] = uint8(c2da_fresh183 >> 0x8)
    c2da_mem[ent_2 + 64 + 1 * 12 + 0 * 4 + 2] = uint8(c2da_fresh183 >> 0x10)
    c2da_mem[ent_2 + 64 + 1 * 12 + 0 * 4 + 3] = uint8(c2da_fresh183 >> 0x18)
    let c2da_fresh184 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4]) | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh185 : uint = float_bits_to_uint(c2da_fresh184)
    c2da_mem[ent_2 + 64 + 1 * 12 + 1 * 4] = uint8(c2da_fresh185)
    c2da_mem[ent_2 + 64 + 1 * 12 + 1 * 4 + 1] = uint8(c2da_fresh185 >> 0x8)
    c2da_mem[ent_2 + 64 + 1 * 12 + 1 * 4 + 2] = uint8(c2da_fresh185 >> 0x10)
    c2da_mem[ent_2 + 64 + 1 * 12 + 1 * 4 + 3] = uint8(c2da_fresh185 >> 0x18)
    let c2da_fresh186 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4]) | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh187 : uint = float_bits_to_uint(c2da_fresh186)
    c2da_mem[ent_2 + 64 + 1 * 12 + 2 * 4] = uint8(c2da_fresh187)
    c2da_mem[ent_2 + 64 + 1 * 12 + 2 * 4 + 1] = uint8(c2da_fresh187 >> 0x8)
    c2da_mem[ent_2 + 64 + 1 * 12 + 2 * 4 + 2] = uint8(c2da_fresh187 >> 0x10)
    c2da_mem[ent_2 + 64 + 1 * 12 + 2 * 4 + 3] = uint8(c2da_fresh187 >> 0x18)
    let c2da_fresh188 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4]) | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh189 : uint = float_bits_to_uint(c2da_fresh188)
    c2da_mem[ent_2 + 100 + 1 * 12 + 0 * 4] = uint8(c2da_fresh189)
    c2da_mem[ent_2 + 100 + 1 * 12 + 0 * 4 + 1] = uint8(c2da_fresh189 >> 0x8)
    c2da_mem[ent_2 + 100 + 1 * 12 + 0 * 4 + 2] = uint8(c2da_fresh189 >> 0x10)
    c2da_mem[ent_2 + 100 + 1 * 12 + 0 * 4 + 3] = uint8(c2da_fresh189 >> 0x18)
    let c2da_fresh190 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4]) | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh191 : uint = float_bits_to_uint(c2da_fresh190)
    c2da_mem[ent_2 + 100 + 1 * 12 + 1 * 4] = uint8(c2da_fresh191)
    c2da_mem[ent_2 + 100 + 1 * 12 + 1 * 4 + 1] = uint8(c2da_fresh191 >> 0x8)
    c2da_mem[ent_2 + 100 + 1 * 12 + 1 * 4 + 2] = uint8(c2da_fresh191 >> 0x10)
    c2da_mem[ent_2 + 100 + 1 * 12 + 1 * 4 + 3] = uint8(c2da_fresh191 >> 0x18)
    let c2da_fresh192 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4]) | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh193 : uint = float_bits_to_uint(c2da_fresh192)
    c2da_mem[ent_2 + 100 + 1 * 12 + 2 * 4] = uint8(c2da_fresh193)
    c2da_mem[ent_2 + 100 + 1 * 12 + 2 * 4 + 1] = uint8(c2da_fresh193 >> 0x8)
    c2da_mem[ent_2 + 100 + 1 * 12 + 2 * 4 + 2] = uint8(c2da_fresh193 >> 0x10)
    c2da_mem[ent_2 + 100 + 1 * 12 + 2 * 4 + 3] = uint8(c2da_fresh193 >> 0x18)
    if ((bits_0 & 1 << 1) != 0) {
        let c2da_fresh194 : float = MSG_ReadCoord()
        let c2da_fresh195 : uint = float_bits_to_uint(c2da_fresh194)
        c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4] = uint8(c2da_fresh195)
        c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 1] = uint8(c2da_fresh195 >> 0x8)
        c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 2] = uint8(c2da_fresh195 >> 0x10)
        c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 3] = uint8(c2da_fresh195 >> 0x18)
    } else {
        let c2da_fresh196 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 8 + 0 * 4]) | uint(c2da_mem[ent_2 + 8 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 8 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 8 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh197 : uint = float_bits_to_uint(c2da_fresh196)
        c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4] = uint8(c2da_fresh197)
        c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 1] = uint8(c2da_fresh197 >> 0x8)
        c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 2] = uint8(c2da_fresh197 >> 0x10)
        c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 3] = uint8(c2da_fresh197 >> 0x18)
    }
    if ((bits_0 & 1 << 8) != 0) {
        let c2da_fresh198 : float = MSG_ReadAngle()
        let c2da_fresh199 : uint = float_bits_to_uint(c2da_fresh198)
        c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4] = uint8(c2da_fresh199)
        c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 1] = uint8(c2da_fresh199 >> 0x8)
        c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 2] = uint8(c2da_fresh199 >> 0x10)
        c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 3] = uint8(c2da_fresh199 >> 0x18)
    } else {
        let c2da_fresh200 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 20 + 0 * 4]) | uint(c2da_mem[ent_2 + 20 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 20 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 20 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh201 : uint = float_bits_to_uint(c2da_fresh200)
        c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4] = uint8(c2da_fresh201)
        c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 1] = uint8(c2da_fresh201 >> 0x8)
        c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 2] = uint8(c2da_fresh201 >> 0x10)
        c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 3] = uint8(c2da_fresh201 >> 0x18)
    }
    if ((bits_0 & 1 << 2) != 0) {
        let c2da_fresh202 : float = MSG_ReadCoord()
        let c2da_fresh203 : uint = float_bits_to_uint(c2da_fresh202)
        c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4] = uint8(c2da_fresh203)
        c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 1] = uint8(c2da_fresh203 >> 0x8)
        c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 2] = uint8(c2da_fresh203 >> 0x10)
        c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 3] = uint8(c2da_fresh203 >> 0x18)
    } else {
        let c2da_fresh204 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 8 + 1 * 4]) | uint(c2da_mem[ent_2 + 8 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 8 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 8 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh205 : uint = float_bits_to_uint(c2da_fresh204)
        c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4] = uint8(c2da_fresh205)
        c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 1] = uint8(c2da_fresh205 >> 0x8)
        c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 2] = uint8(c2da_fresh205 >> 0x10)
        c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 3] = uint8(c2da_fresh205 >> 0x18)
    }
    if ((bits_0 & 1 << 4) != 0) {
        let c2da_fresh206 : float = MSG_ReadAngle()
        let c2da_fresh207 : uint = float_bits_to_uint(c2da_fresh206)
        c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4] = uint8(c2da_fresh207)
        c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 1] = uint8(c2da_fresh207 >> 0x8)
        c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 2] = uint8(c2da_fresh207 >> 0x10)
        c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 3] = uint8(c2da_fresh207 >> 0x18)
    } else {
        let c2da_fresh208 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 20 + 1 * 4]) | uint(c2da_mem[ent_2 + 20 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 20 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 20 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh209 : uint = float_bits_to_uint(c2da_fresh208)
        c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4] = uint8(c2da_fresh209)
        c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 1] = uint8(c2da_fresh209 >> 0x8)
        c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 2] = uint8(c2da_fresh209 >> 0x10)
        c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 3] = uint8(c2da_fresh209 >> 0x18)
    }
    if ((bits_0 & 1 << 3) != 0) {
        let c2da_fresh210 : float = MSG_ReadCoord()
        let c2da_fresh211 : uint = float_bits_to_uint(c2da_fresh210)
        c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4] = uint8(c2da_fresh211)
        c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 1] = uint8(c2da_fresh211 >> 0x8)
        c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 2] = uint8(c2da_fresh211 >> 0x10)
        c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 3] = uint8(c2da_fresh211 >> 0x18)
    } else {
        let c2da_fresh212 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 8 + 2 * 4]) | uint(c2da_mem[ent_2 + 8 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 8 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 8 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh213 : uint = float_bits_to_uint(c2da_fresh212)
        c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4] = uint8(c2da_fresh213)
        c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 1] = uint8(c2da_fresh213 >> 0x8)
        c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 2] = uint8(c2da_fresh213 >> 0x10)
        c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 3] = uint8(c2da_fresh213 >> 0x18)
    }
    if ((bits_0 & 1 << 9) != 0) {
        let c2da_fresh214 : float = MSG_ReadAngle()
        let c2da_fresh215 : uint = float_bits_to_uint(c2da_fresh214)
        c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4] = uint8(c2da_fresh215)
        c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 1] = uint8(c2da_fresh215 >> 0x8)
        c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 2] = uint8(c2da_fresh215 >> 0x10)
        c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 3] = uint8(c2da_fresh215 >> 0x18)
    } else {
        let c2da_fresh216 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 20 + 2 * 4]) | uint(c2da_mem[ent_2 + 20 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 20 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 20 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh217 : uint = float_bits_to_uint(c2da_fresh216)
        c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4] = uint8(c2da_fresh217)
        c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 1] = uint8(c2da_fresh217 >> 0x8)
        c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 2] = uint8(c2da_fresh217 >> 0x10)
        c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 3] = uint8(c2da_fresh217 >> 0x18)
    }
    if ((bits_0 & 1 << 5) != 0) {
        let c2da_fresh218 : uint = 1u
        let c2da_fresh219 : uint = c2da_fresh218
        c2da_mem[ent_2] = uint8(c2da_fresh219)
        c2da_mem[ent_2 + 1] = uint8(c2da_fresh219 >> 0x8)
        c2da_mem[ent_2 + 2] = uint8(c2da_fresh219 >> 0x10)
        c2da_mem[ent_2 + 3] = uint8(c2da_fresh219 >> 0x18)
    }
    if (forcelink != 0u) {
        let c2da_fresh220 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4]) | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh221 : uint = float_bits_to_uint(c2da_fresh220)
        c2da_mem[ent_2 + 64 + 1 * 12 + 0 * 4] = uint8(c2da_fresh221)
        c2da_mem[ent_2 + 64 + 1 * 12 + 0 * 4 + 1] = uint8(c2da_fresh221 >> 0x8)
        c2da_mem[ent_2 + 64 + 1 * 12 + 0 * 4 + 2] = uint8(c2da_fresh221 >> 0x10)
        c2da_mem[ent_2 + 64 + 1 * 12 + 0 * 4 + 3] = uint8(c2da_fresh221 >> 0x18)
        let c2da_fresh222 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4]) | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh223 : uint = float_bits_to_uint(c2da_fresh222)
        c2da_mem[ent_2 + 64 + 1 * 12 + 1 * 4] = uint8(c2da_fresh223)
        c2da_mem[ent_2 + 64 + 1 * 12 + 1 * 4 + 1] = uint8(c2da_fresh223 >> 0x8)
        c2da_mem[ent_2 + 64 + 1 * 12 + 1 * 4 + 2] = uint8(c2da_fresh223 >> 0x10)
        c2da_mem[ent_2 + 64 + 1 * 12 + 1 * 4 + 3] = uint8(c2da_fresh223 >> 0x18)
        let c2da_fresh224 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4]) | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh225 : uint = float_bits_to_uint(c2da_fresh224)
        c2da_mem[ent_2 + 64 + 1 * 12 + 2 * 4] = uint8(c2da_fresh225)
        c2da_mem[ent_2 + 64 + 1 * 12 + 2 * 4 + 1] = uint8(c2da_fresh225 >> 0x8)
        c2da_mem[ent_2 + 64 + 1 * 12 + 2 * 4 + 2] = uint8(c2da_fresh225 >> 0x10)
        c2da_mem[ent_2 + 64 + 1 * 12 + 2 * 4 + 3] = uint8(c2da_fresh225 >> 0x18)
        let c2da_fresh226 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4]) | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh227 : uint = float_bits_to_uint(c2da_fresh226)
        c2da_mem[ent_2 + 88 + 0 * 4] = uint8(c2da_fresh227)
        c2da_mem[ent_2 + 88 + 0 * 4 + 1] = uint8(c2da_fresh227 >> 0x8)
        c2da_mem[ent_2 + 88 + 0 * 4 + 2] = uint8(c2da_fresh227 >> 0x10)
        c2da_mem[ent_2 + 88 + 0 * 4 + 3] = uint8(c2da_fresh227 >> 0x18)
        let c2da_fresh228 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4]) | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh229 : uint = float_bits_to_uint(c2da_fresh228)
        c2da_mem[ent_2 + 88 + 1 * 4] = uint8(c2da_fresh229)
        c2da_mem[ent_2 + 88 + 1 * 4 + 1] = uint8(c2da_fresh229 >> 0x8)
        c2da_mem[ent_2 + 88 + 1 * 4 + 2] = uint8(c2da_fresh229 >> 0x10)
        c2da_mem[ent_2 + 88 + 1 * 4 + 3] = uint8(c2da_fresh229 >> 0x18)
        let c2da_fresh230 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4]) | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 64 + 0 * 12 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh231 : uint = float_bits_to_uint(c2da_fresh230)
        c2da_mem[ent_2 + 88 + 2 * 4] = uint8(c2da_fresh231)
        c2da_mem[ent_2 + 88 + 2 * 4 + 1] = uint8(c2da_fresh231 >> 0x8)
        c2da_mem[ent_2 + 88 + 2 * 4 + 2] = uint8(c2da_fresh231 >> 0x10)
        c2da_mem[ent_2 + 88 + 2 * 4 + 3] = uint8(c2da_fresh231 >> 0x18)
        let c2da_fresh232 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4]) | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh233 : uint = float_bits_to_uint(c2da_fresh232)
        c2da_mem[ent_2 + 100 + 1 * 12 + 0 * 4] = uint8(c2da_fresh233)
        c2da_mem[ent_2 + 100 + 1 * 12 + 0 * 4 + 1] = uint8(c2da_fresh233 >> 0x8)
        c2da_mem[ent_2 + 100 + 1 * 12 + 0 * 4 + 2] = uint8(c2da_fresh233 >> 0x10)
        c2da_mem[ent_2 + 100 + 1 * 12 + 0 * 4 + 3] = uint8(c2da_fresh233 >> 0x18)
        let c2da_fresh234 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4]) | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh235 : uint = float_bits_to_uint(c2da_fresh234)
        c2da_mem[ent_2 + 100 + 1 * 12 + 1 * 4] = uint8(c2da_fresh235)
        c2da_mem[ent_2 + 100 + 1 * 12 + 1 * 4 + 1] = uint8(c2da_fresh235 >> 0x8)
        c2da_mem[ent_2 + 100 + 1 * 12 + 1 * 4 + 2] = uint8(c2da_fresh235 >> 0x10)
        c2da_mem[ent_2 + 100 + 1 * 12 + 1 * 4 + 3] = uint8(c2da_fresh235 >> 0x18)
        let c2da_fresh236 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4]) | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh237 : uint = float_bits_to_uint(c2da_fresh236)
        c2da_mem[ent_2 + 100 + 1 * 12 + 2 * 4] = uint8(c2da_fresh237)
        c2da_mem[ent_2 + 100 + 1 * 12 + 2 * 4 + 1] = uint8(c2da_fresh237 >> 0x8)
        c2da_mem[ent_2 + 100 + 1 * 12 + 2 * 4 + 2] = uint8(c2da_fresh237 >> 0x10)
        c2da_mem[ent_2 + 100 + 1 * 12 + 2 * 4 + 3] = uint8(c2da_fresh237 >> 0x18)
        let c2da_fresh238 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4]) | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh239 : uint = float_bits_to_uint(c2da_fresh238)
        c2da_mem[ent_2 + 124 + 0 * 4] = uint8(c2da_fresh239)
        c2da_mem[ent_2 + 124 + 0 * 4 + 1] = uint8(c2da_fresh239 >> 0x8)
        c2da_mem[ent_2 + 124 + 0 * 4 + 2] = uint8(c2da_fresh239 >> 0x10)
        c2da_mem[ent_2 + 124 + 0 * 4 + 3] = uint8(c2da_fresh239 >> 0x18)
        let c2da_fresh240 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4]) | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh241 : uint = float_bits_to_uint(c2da_fresh240)
        c2da_mem[ent_2 + 124 + 1 * 4] = uint8(c2da_fresh241)
        c2da_mem[ent_2 + 124 + 1 * 4 + 1] = uint8(c2da_fresh241 >> 0x8)
        c2da_mem[ent_2 + 124 + 1 * 4 + 2] = uint8(c2da_fresh241 >> 0x10)
        c2da_mem[ent_2 + 124 + 1 * 4 + 3] = uint8(c2da_fresh241 >> 0x18)
        let c2da_fresh242 : float = uint_bits_to_float(uint(c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4]) | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 100 + 0 * 12 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh243 : uint = float_bits_to_uint(c2da_fresh242)
        c2da_mem[ent_2 + 124 + 2 * 4] = uint8(c2da_fresh243)
        c2da_mem[ent_2 + 124 + 2 * 4 + 1] = uint8(c2da_fresh243 >> 0x8)
        c2da_mem[ent_2 + 124 + 2 * 4 + 2] = uint8(c2da_fresh243 >> 0x10)
        c2da_mem[ent_2 + 124 + 2 * 4 + 3] = uint8(c2da_fresh243 >> 0x18)
        let c2da_fresh244 : uint = 1u
        let c2da_fresh245 : uint = c2da_fresh244
        c2da_mem[ent_2] = uint8(c2da_fresh245)
        c2da_mem[ent_2 + 1] = uint8(c2da_fresh245 >> 0x8)
        c2da_mem[ent_2 + 2] = uint8(c2da_fresh245 >> 0x10)
        c2da_mem[ent_2 + 3] = uint8(c2da_fresh245 >> 0x18)
    }
    return
}
var bitcounts : int[16]

[sideeffects]
def private CL_ParseStaticSound_c2da_frame(c2da_fp : int) {
    var sound_num : int
    var vol : int
    var atten : int
    for (i_0 in range(0, 3)) {
        let c2da_fresh45 : float = MSG_ReadCoord()
        let c2da_fresh46 : uint = float_bits_to_uint(c2da_fresh45)
        c2da_mem[c2da_fp + i_0 * 4] = uint8(c2da_fresh46)
        c2da_mem[c2da_fp + i_0 * 4 + 1] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[c2da_fp + i_0 * 4 + 2] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[c2da_fp + i_0 * 4 + 3] = uint8(c2da_fresh46 >> 0x18)
    }
    sound_num = MSG_ReadByte()
    vol = MSG_ReadByte()
    atten = MSG_ReadByte()
    S_StaticSound(int(uint(c2da_mem[2856 + sound_num * 8]) | uint(c2da_mem[2856 + sound_num * 8 + 1]) << 0x8 | uint(c2da_mem[2856 + sound_num * 8 + 2]) << 0x10 | uint(c2da_mem[2856 + sound_num * 8 + 3]) << 0x18), c2da_fp, float(vol), float(atten))
    return
}
[sideeffects]
def private CL_ParseStartSoundPacket_c2da_frame(c2da_fp : int) {
    var channel : int
    var ent_1 : int
    var sound_num_0 : int
    var volume : int
    var field_mask : int
    var attenuation : float
    field_mask = MSG_ReadByte()
    if ((field_mask & 1 << 0) != 0) {
        volume = MSG_ReadByte()
    } else {
        volume = 255
    }
    if ((field_mask & 1 << 1) != 0) {
        attenuation = float(double(MSG_ReadByte()) / 64.0lf)
    } else {
        attenuation = 1.0
    }
    channel = MSG_ReadShort()
    sound_num_0 = MSG_ReadByte()
    ent_1 = channel >> 3
    channel &= 7
    if (ent_1 > 600) {
        Host_Error(699387, [C2daVaArg(tag = 1, i64 = int64(ent_1), f64 = 0.0lf, raw = 0x0)])
    }
    for (i_4 in range(0, 3)) {
        let c2da_fresh95 : float = MSG_ReadCoord()
        let c2da_fresh96 : uint = float_bits_to_uint(c2da_fresh95)
        c2da_mem[c2da_fp + i_4 * 4] = uint8(c2da_fresh96)
        c2da_mem[c2da_fp + i_4 * 4 + 1] = uint8(c2da_fresh96 >> 0x8)
        c2da_mem[c2da_fp + i_4 * 4 + 2] = uint8(c2da_fresh96 >> 0x10)
        c2da_mem[c2da_fp + i_4 * 4 + 3] = uint8(c2da_fresh96 >> 0x18)
    }
    S_StartSound(ent_1, channel, int(uint(c2da_mem[2856 + sound_num_0 * 8]) | uint(c2da_mem[2856 + sound_num_0 * 8 + 1]) << 0x8 | uint(c2da_mem[2856 + sound_num_0 * 8 + 2]) << 0x10 | uint(c2da_mem[2856 + sound_num_0 * 8 + 3]) << 0x18), c2da_fp, float(double(volume) / 255.0lf), attenuation)
    return
}
[sideeffects]
def private CL_ParseServerInfo_c2da_frame(c2da_fp : int) {
    var str : int
    var i_5 : int
    var nummodels : int
    var numsounds : int
    Con_DPrintf(699422, [])
    CL_ClearState()
    i_5 = MSG_ReadLong()
    if (i_5 != 15) {
        Con_Printf(699451, [C2daVaArg(tag = 1, i64 = int64(i_5), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = 15l, f64 = 0.0lf, raw = 0x0)])
        return
    }
    let c2da_fresh97 : int = MSG_ReadByte()
    let c2da_fresh98 : uint = uint(c2da_fresh97)
    c2da_mem[4948] = uint8(c2da_fresh98)
    c2da_mem[4949] = uint8(c2da_fresh98 >> 0x8)
    c2da_mem[4950] = uint8(c2da_fresh98 >> 0x10)
    c2da_mem[4951] = uint8(c2da_fresh98 >> 0x18)
    if (int(uint(c2da_mem[4948]) | uint(c2da_mem[4949]) << 0x8 | uint(c2da_mem[4950]) << 0x10 | uint(c2da_mem[4951]) << 0x18) < 1 || int(uint(c2da_mem[4948]) | uint(c2da_mem[4949]) << 0x8 | uint(c2da_mem[4950]) << 0x10 | uint(c2da_mem[4951]) << 0x18) > 16) {
        Con_Printf(699486, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[4948]) | uint(c2da_mem[4949]) << 0x8 | uint(c2da_mem[4950]) << 0x10 | uint(c2da_mem[4951]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
        return
    }
    let c2da_fresh99 : int = Hunk_AllocName(int(uint64(int(uint(c2da_mem[4948]) | uint(c2da_mem[4949]) << 0x8 | uint(c2da_mem[4950]) << 0x10 | uint(c2da_mem[4951]) << 0x18)) * 16428ul), 699519)
    let c2da_fresh100 : uint = uint(c2da_fresh99)
    c2da_mem[5192] = uint8(c2da_fresh100)
    c2da_mem[5193] = uint8(c2da_fresh100 >> 0x8)
    c2da_mem[5194] = uint8(c2da_fresh100 >> 0x10)
    c2da_mem[5195] = uint8(c2da_fresh100 >> 0x18)
    c2da_mem[5196] = 0u8
    c2da_mem[5197] = 0u8
    c2da_mem[5198] = 0u8
    c2da_mem[5199] = 0u8
    let c2da_fresh101 : int = MSG_ReadByte()
    let c2da_fresh102 : uint = uint(c2da_fresh101)
    c2da_mem[4952] = uint8(c2da_fresh102)
    c2da_mem[4953] = uint8(c2da_fresh102 >> 0x8)
    c2da_mem[4954] = uint8(c2da_fresh102 >> 0x10)
    c2da_mem[4955] = uint8(c2da_fresh102 >> 0x18)
    str = MSG_ReadString()
    c2da_lin_strncpy(4904, str, 40ul - 1ul)
    Con_Printf(699526, [])
    Con_Printf(699568, [C2daVaArg(tag = 1, i64 = 2l, f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(str))])
    c2da_lin_memset(808, 0, 2048ul)
    nummodels = 1
    while (true) {
        str = MSG_ReadString()
        if (int8(c2da_mem[str + 0]) == 0) {
            break
        }
        if (nummodels == 256) {
            Con_Printf(699574, [])
            return
        }
        c2da_lin_strcpy(c2da_fp + nummodels * 64, str)
        Mod_TouchModel(str)
        nummodels++
    }
    c2da_lin_memset(2856, 0, 2048ul)
    numsounds = 1
    while (true) {
        str = MSG_ReadString()
        if (int8(c2da_mem[str + 0]) == 0) {
            break
        }
        if (numsounds == 256) {
            Con_Printf(699612, [])
            return
        }
        c2da_lin_strcpy(c2da_fp + 16384 + numsounds * 64, str)
        S_TouchSound(str)
        numsounds++
    }
    i_5 = 1
    while (i_5 < nummodels) {
        let c2da_fresh103 : int = Mod_ForName(c2da_fp + i_5 * 64, 0u)
        let c2da_fresh104 : uint = uint(c2da_fresh103)
        c2da_mem[808 + i_5 * 8] = uint8(c2da_fresh104)
        c2da_mem[808 + i_5 * 8 + 1] = uint8(c2da_fresh104 >> 0x8)
        c2da_mem[808 + i_5 * 8 + 2] = uint8(c2da_fresh104 >> 0x10)
        c2da_mem[808 + i_5 * 8 + 3] = uint8(c2da_fresh104 >> 0x18)
        c2da_mem[808 + i_5 * 8 + 4] = 0u8
        c2da_mem[808 + i_5 * 8 + 5] = 0u8
        c2da_mem[808 + i_5 * 8 + 6] = 0u8
        c2da_mem[808 + i_5 * 8 + 7] = 0u8
        if (int(uint(c2da_mem[808 + i_5 * 8]) | uint(c2da_mem[808 + i_5 * 8 + 1]) << 0x8 | uint(c2da_mem[808 + i_5 * 8 + 2]) << 0x10 | uint(c2da_mem[808 + i_5 * 8 + 3]) << 0x18) == 0) {
            Con_Printf(699650, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp + i_5 * 64))])
            return
        }
        CL_KeepaliveMessage()
        i_5++
    }
    S_BeginPrecaching()
    i_5 = 1
    for (c2da_i_5 in range(i_5, numsounds)) {
        let c2da_fresh105 : int = S_PrecacheSound(c2da_fp + 16384 + c2da_i_5 * 64)
        let c2da_fresh106 : uint = uint(c2da_fresh105)
        c2da_mem[2856 + c2da_i_5 * 8] = uint8(c2da_fresh106)
        c2da_mem[2856 + c2da_i_5 * 8 + 1] = uint8(c2da_fresh106 >> 0x8)
        c2da_mem[2856 + c2da_i_5 * 8 + 2] = uint8(c2da_fresh106 >> 0x10)
        c2da_mem[2856 + c2da_i_5 * 8 + 3] = uint8(c2da_fresh106 >> 0x18)
        c2da_mem[2856 + c2da_i_5 * 8 + 4] = 0u8
        c2da_mem[2856 + c2da_i_5 * 8 + 5] = 0u8
        c2da_mem[2856 + c2da_i_5 * 8 + 6] = 0u8
        c2da_mem[2856 + c2da_i_5 * 8 + 7] = 0u8
        CL_KeepaliveMessage()
    }
    S_EndPrecaching()
    let c2da_fresh107 : int = int(uint(c2da_mem[808 + 1 * 8]) | uint(c2da_mem[808 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[808 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[808 + 1 * 8 + 3]) << 0x18)
    let c2da_fresh108 : uint = uint(c2da_fresh107)
    c2da_mem[4960] = uint8(c2da_fresh108)
    c2da_mem[4961] = uint8(c2da_fresh108 >> 0x8)
    c2da_mem[4962] = uint8(c2da_fresh108 >> 0x10)
    c2da_mem[4963] = uint8(c2da_fresh108 >> 0x18)
    c2da_mem[4964] = 0u8
    c2da_mem[4965] = 0u8
    c2da_mem[4966] = 0u8
    c2da_mem[4967] = 0u8
    let c2da_fresh109 : uint = uint(c2da_fresh107)
    c2da_mem[10048 + 0 * 200 + 136] = uint8(c2da_fresh109)
    c2da_mem[10048 + 0 * 200 + 137] = uint8(c2da_fresh109 >> 0x8)
    c2da_mem[10048 + 0 * 200 + 138] = uint8(c2da_fresh109 >> 0x10)
    c2da_mem[10048 + 0 * 200 + 139] = uint8(c2da_fresh109 >> 0x18)
    c2da_mem[10048 + 0 * 200 + 140] = 0u8
    c2da_mem[10048 + 0 * 200 + 141] = 0u8
    c2da_mem[10048 + 0 * 200 + 142] = 0u8
    c2da_mem[10048 + 0 * 200 + 143] = 0u8
    R_NewMap()
    Hunk_Check()
    noclip_anglehack = 0u
    return
}
[sideeffects]
def private CL_KeepaliveMessage_c2da_frame(c2da_fp : int) {
    var time : float
    var ret : int
    var old : sizebuf_s
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) != 0u) {
        return
    }
    if ((uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) != 0u) {
        return
    }
    var c2da_fresh110 : sizebuf_s
    c2da_fresh110.allowoverflow = uint(c2da_mem[5360]) | uint(c2da_mem[5361]) << 0x8 | uint(c2da_mem[5362]) << 0x10 | uint(c2da_mem[5363]) << 0x18
    c2da_fresh110.overflowed = uint(c2da_mem[5364]) | uint(c2da_mem[5365]) << 0x8 | uint(c2da_mem[5366]) << 0x10 | uint(c2da_mem[5367]) << 0x18
    c2da_fresh110.data = int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18)
    c2da_fresh110.maxsize = int(uint(c2da_mem[5376]) | uint(c2da_mem[5377]) << 0x8 | uint(c2da_mem[5378]) << 0x10 | uint(c2da_mem[5379]) << 0x18)
    c2da_fresh110.cursize = int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18)
    old = c2da_fresh110
    c2da_lin_memcpy(c2da_fp, int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18), uint64(int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18)))
    while (true) {
        ret = CL_GetMessage()
        if (ret == 0) {
            goto label 1
        } elif (ret == 1) {
            goto label 2
        } elif (ret == 2) {
            goto label 3
        } else {
            goto label 0
        }
        label 0:
        Host_Error(699670, [])
        label 1:
        goto label 4
        label 2:
        Host_Error(699712, [])
        goto label 4
        label 3:
        if (MSG_ReadByte() != 1) {
            Host_Error(699752, [])
        }
        label 4:
        if (ret == 0) {
            break
        }
    }
    let c2da_fresh111 : uint = old.allowoverflow
    c2da_mem[5360] = uint8(c2da_fresh111)
    c2da_mem[5361] = uint8(c2da_fresh111 >> 0x8)
    c2da_mem[5362] = uint8(c2da_fresh111 >> 0x10)
    c2da_mem[5363] = uint8(c2da_fresh111 >> 0x18)
    let c2da_fresh112 : uint = old.overflowed
    c2da_mem[5364] = uint8(c2da_fresh112)
    c2da_mem[5365] = uint8(c2da_fresh112 >> 0x8)
    c2da_mem[5366] = uint8(c2da_fresh112 >> 0x10)
    c2da_mem[5367] = uint8(c2da_fresh112 >> 0x18)
    let c2da_fresh113 : uint = uint(old.data)
    c2da_mem[5368] = uint8(c2da_fresh113)
    c2da_mem[5369] = uint8(c2da_fresh113 >> 0x8)
    c2da_mem[5370] = uint8(c2da_fresh113 >> 0x10)
    c2da_mem[5371] = uint8(c2da_fresh113 >> 0x18)
    c2da_mem[5372] = 0u8
    c2da_mem[5373] = 0u8
    c2da_mem[5374] = 0u8
    c2da_mem[5375] = 0u8
    let c2da_fresh114 : uint = uint(old.maxsize)
    c2da_mem[5376] = uint8(c2da_fresh114)
    c2da_mem[5377] = uint8(c2da_fresh114 >> 0x8)
    c2da_mem[5378] = uint8(c2da_fresh114 >> 0x10)
    c2da_mem[5379] = uint8(c2da_fresh114 >> 0x18)
    let c2da_fresh115 : uint = uint(old.cursize)
    c2da_mem[5380] = uint8(c2da_fresh115)
    c2da_mem[5381] = uint8(c2da_fresh115 >> 0x8)
    c2da_mem[5382] = uint8(c2da_fresh115 >> 0x10)
    c2da_mem[5383] = uint8(c2da_fresh115 >> 0x18)
    c2da_lin_memcpy(int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18), c2da_fp, uint64(int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18)))
    time = float(Sys_FloatTime())
    if (time - CL_KeepaliveMessage__lastmsg < 5.0) {
        return
    }
    CL_KeepaliveMessage__lastmsg = time
    Con_Printf(699795, [])
    MSG_WriteByte(7816, 1)
    NET_SendMessage(int(uint(c2da_mem[7808]) | uint(c2da_mem[7809]) << 0x8 | uint(c2da_mem[7810]) << 0x10 | uint(c2da_mem[7811]) << 0x18), 7816)
    SZ_Clear(7816)
    return
}

// This unit's static data, at heap offset 698784.
let private c2da_lin_static_cl_parse_seg = fixed_array<int>(698784, 1585)
let private c2da_lin_static_cl_parse = fixed_array<uint64>(0x2d2d2d2d00206925ul, 0x2d2d2d2d2d2d2d2dul, 0xa2d2d2d2d2d2dul, 0x65737261505f4c43ul, 0x654d726576726553ul, 0x42203a6567617373ul, 0x6576726573206461ul, 0x67617373656d2072ul, 0x73253a6933250065ul, 0x464f20444e45000aul, 0x4547415353454d20ul, 0x7075207473616600ul, 0x5f4c430065746164ul, 0x7265536573726150ul, 0x617373654d726576ul, 0x656c6c49203a6567ul, 0x657320656c626967ul, 0x73656d2072657672ul, 0x4c43000a65676173ul, 0x655365737261505ful, 0x7373654d72657672ul, 0x726553203a656761ul, 0x7020736920726576ul, 0x206c6f636f746f72ul, 0x6574736e69206925ul, 0x692520666f206461ul, 0x726576726553000aul, 0x6e6e6f6373696420ul, 0x25000a6465746365ul, 0x696c5f6376730073ul, 0x656c797473746867ul, 0x4c5f58414d203e20ul, 0x4c59545354484749ul, 0x61505f4c43005345ul, 0x6576726553657372ul, 0x6567617373654d72ul, 0x70755f637673203aul, 0x656d616e65746164ul, 0x535f58414d203e20ul, 0x52414f4245524f43ul, 0x7261505f4c430044ul, 0x7265767265536573ul, 0x3a6567617373654dul, 0x6470755f63767320ul, 0x7367617266657461ul, 0x535f58414d203e20ul, 0x52414f4245524f43ul, 0x7261505f4c430044ul, 0x7265767265536573ul, 0x3a6567617373654dul, 0x6470755f63767320ul, 0x726f6c6f63657461ul, 0x5f58414d203e2073ul, 0x414f4245524f4353ul, 0x6965636552004452ul, 0x6e67697320646576ul, 0x6877206925206e6ful, 0x6925207461206e65ul, 0x6470755f63767300ul, 0x3a74617473657461ul, 0x6920736920692520ul, 0x680064696c61766eul, 0x206f6f5400706c65ul, 0x61747320796e616dul, 0x69746e6520636974ul, 0x5f4c430073656974ul, 0x754e797469746e45ul, 0x7369206925203a6dul, 0x61766e69206e6120ul, 0x626d756e2064696cul, 0x654e5f4c43007265ul, 0x616c736e61725477ul, 0x6c73203a6e6f6974ul, 0x2e6c63203e20746ful, 0x6e65696c6378616dul, 0x61505f4c43007374ul, 0x7472617453657372ul, 0x636150646e756f53ul, 0x746e65203a74656bul, 0x6553006925203d20ul, 0x6f666e6972657672ul, 0x2074656b63617020ul, 0x6465766965636572ul, 0x6576726553000a2eul, 0x6e72757465722072ul, 0x6973726576206465ul, 0x6e202c6925206e6ful, 0x614200692520746ful, 0x696c6378616d2064ul, 0x7525282073746e65ul, 0x73206d6f72662029ul, 0x73000a7265767265ul, 0xa0a007365726f63ul, 0x1e1e1e1e1e1e1e1dul, 0x1e1e1e1e1e1e1e1eul, 0x1e1e1e1e1e1e1e1eul, 0x1e1e1e1e1e1e1e1eul, 0xa0a1f1e1e1e1eul, 0x6553000a73256325ul, 0x6e65732072657672ul, 0x616d206f6f742074ul, 0x6c65646f6d20796eul, 0x6863616365727020ul, 0x76726553000a7365ul, 0x20746e6573207265ul, 0x796e616d206f6f74ul, 0x7020646e756f7320ul, 0x7365686361636572ul, 0x206c65646f4d000aul, 0x6620746f6e207325ul, 0x4c43000a646e756ful, 0x696c617065654b5ful, 0x67617373654d6576ul, 0x65475f4c43203a65ul, 0x6567617373654d74ul, 0x64656c69616620ul, 0x617065654b5f4c43ul, 0x7373654d6576696cul, 0x636572203a656761ul, 0x2061206465766965ul, 0x6567617373656dul, 0x617065654b5f4c43ul, 0x7373654d6576696cul, 0x746164203a656761ul, 0x6177206d61726761ul, 0x6e20612074276e73ul, 0x63203e2d2d00706ful, 0x6f7420746e65696cul, 0x2072657672657320ul, 0x76696c617065656bul, 0x625f637673000a65ul, 0x6e5f637673006461ul, 0x645f63767300706ful, 0x63656e6e6f637369ul, 0x70755f6376730074ul, 0x7461747365746164ul, 0x7265765f63767300ul, 0x637673006e6f6973ul, 0x776569767465735ful, 0x756f735f63767300ul, 0x745f63767300646eul, 0x5f63767300656d69ul, 0x767300746e697270ul, 0x7466667574735f63ul, 0x5f63767300747865ul, 0x656c676e61746573ul, 0x7265735f63767300ul, 0x6f666e69726576ul, 0x6867696c5f637673ul, 0x7300656c79747374ul, 0x74616470755f6376ul, 0x767300656d616e65ul, 0x6574616470755f63ul, 0x7673007367617266ul, 0x746e65696c635f63ul, 0x6376730061746164ul, 0x756f73706f74735ful, 0x755f63767300646eul, 0x6c6f636574616470ul, 0x5f6376730073726ful, 0x656c636974726170ul, 0x6d61645f63767300ul, 0x5f63767300656761ul, 0x6174736e77617073ul, 0x4f53424f00636974ul, 0x637673204554454cul, 0x69626e776170735ful, 0x637673007972616eul, 0x61626e776170735ful, 0x7300656e696c6573ul, 0x5f706d65745f6376ul, 0x7300797469746e65ul, 0x61707465735f6376ul, 0x5f63767300657375ul, 0x756e6e6f6e676973ul, 0x65635f637673006dul, 0x6e6972707265746eul, 0x696b5f6376730074ul, 0x736e6f6d64656c6cul, 0x5f63767300726574ul, 0x636573646e756f66ul, 0x5f63767300746572ul, 0x6174736e77617073ul, 0x646e756f73636974ul, 0x746e695f63767300ul, 0x6f697373696d7265ul, 0x69665f637673006eul, 0x63767300656c616eul, 0x6b6361727464635ful, 0x6c65735f63767300ul, 0x6e65657263736cul, 0x737475635f637673ul, 0x5f4c4300656e6563ul, 0x646f4d6573726150ul, 0x20646162203a6c65ul, 0x69006d756e646f6dul, 0x6d2e6c63203d3e20ul, 0x746e65696c637861ul, 0x73ul)

[init]
def private c2da_lin_init_static_cl_parse() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_cl_parse_seg[s * 2]
        for (k in range(c2da_lin_static_cl_parse_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_cl_parse[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
