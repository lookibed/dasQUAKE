var private V_CalcRefdef__oldz : float = 0.0

var private CalcGunAngle__oldyaw : float = 0.0

var private CalcGunAngle__oldpitch : float = 0.0

var private V_CheckGamma__oldgammavalue : float = 0.0

[export, sideeffects]
def V_StartPitchDrift() {
    if (uint64_bits_to_double(uint64(uint(c2da_mem[728]) | uint(c2da_mem[729]) << 0x8 | uint(c2da_mem[730]) << 0x10 | uint(c2da_mem[731]) << 0x18) | uint64(uint(c2da_mem[732]) | uint(c2da_mem[733]) << 0x8 | uint(c2da_mem[734]) << 0x10 | uint(c2da_mem[735]) << 0x18) << 0x20) == uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20)) {
        return
    }
    if ((uint(c2da_mem[720]) | uint(c2da_mem[721]) << 0x8 | uint(c2da_mem[722]) << 0x10 | uint(c2da_mem[723]) << 0x18) != 0x0 || uint_bits_to_float(uint(c2da_mem[716]) | uint(c2da_mem[717]) << 0x8 | uint(c2da_mem[718]) << 0x10 | uint(c2da_mem[719]) << 0x18) == 0.0) {
        let c2da_fresh0 : float = uint_bits_to_float(uint(c2da_mem[695960]) | uint(c2da_mem[695961]) << 0x8 | uint(c2da_mem[695962]) << 0x10 | uint(c2da_mem[695963]) << 0x18)
        let c2da_fresh1 : uint = float_bits_to_uint(c2da_fresh0)
        c2da_mem[716] = uint8(c2da_fresh1)
        c2da_mem[717] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[718] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[719] = uint8(c2da_fresh1 >> 0x18)
        let c2da_fresh2 : uint = 0u
        let c2da_fresh3 : uint = c2da_fresh2
        c2da_mem[720] = uint8(c2da_fresh3)
        c2da_mem[721] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[722] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[723] = uint8(c2da_fresh3 >> 0x18)
        let c2da_fresh4 : float = 0.0
        let c2da_fresh5 : uint = float_bits_to_uint(c2da_fresh4)
        c2da_mem[724] = uint8(c2da_fresh5)
        c2da_mem[725] = uint8(c2da_fresh5 >> 0x8)
        c2da_mem[726] = uint8(c2da_fresh5 >> 0x10)
        c2da_mem[727] = uint8(c2da_fresh5 >> 0x18)
    }
    return
}
[export, sideeffects]
def V_StopPitchDrift() {
    let c2da_fresh6 : double = uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20)
    let c2da_fresh7 : uint64 = double_bits_to_uint64(c2da_fresh6)
    c2da_mem[728] = uint8(c2da_fresh7)
    c2da_mem[729] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[730] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[731] = uint8(c2da_fresh7 >> 0x18)
    c2da_mem[732] = uint8(c2da_fresh7 >> 0x20)
    c2da_mem[733] = uint8(c2da_fresh7 >> 0x28)
    c2da_mem[734] = uint8(c2da_fresh7 >> 0x30)
    c2da_mem[735] = uint8(c2da_fresh7 >> 0x38)
    let c2da_fresh8 : uint = 1u
    let c2da_fresh9 : uint = c2da_fresh8
    c2da_mem[720] = uint8(c2da_fresh9)
    c2da_mem[721] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[722] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[723] = uint8(c2da_fresh9 >> 0x18)
    let c2da_fresh10 : float = 0.0
    let c2da_fresh11 : uint = float_bits_to_uint(c2da_fresh10)
    c2da_mem[716] = uint8(c2da_fresh11)
    c2da_mem[717] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[718] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[719] = uint8(c2da_fresh11 >> 0x18)
    return
}
[export, sideeffects]
def V_RenderView() {
    var i : int
    if (uint(con_forcedup) != 0u) {
        return
    }
    if (int(uint(c2da_mem[4948]) | uint(c2da_mem[4949]) << 0x8 | uint(c2da_mem[4950]) << 0x10 | uint(c2da_mem[4951]) << 0x18) > 1) {
        Cvar_Set(737559, 737350)
        Cvar_Set(737568, 737350)
        Cvar_Set(737577, 737350)
    }
    if (int(uint(c2da_mem[756]) | uint(c2da_mem[757]) << 0x8 | uint(c2da_mem[758]) << 0x10 | uint(c2da_mem[759]) << 0x18) != 0) {
        V_CalcIntermissionRefdef()
    } elif ((uint(c2da_mem[744]) | uint(c2da_mem[745]) << 0x8 | uint(c2da_mem[746]) << 0x10 | uint(c2da_mem[747]) << 0x18) == 0u) {
        V_CalcRefdef()
    }
    R_PushDlights()
    if (uint_bits_to_float(uint(c2da_mem[695816]) | uint(c2da_mem[695817]) << 0x8 | uint(c2da_mem[695818]) << 0x10 | uint(c2da_mem[695819]) << 0x18) != 0.0) {
        vid.rowbytes = vid.rowbytes << 1u
        vid.aspect = float(double(vid.aspect) * 0.5lf)
        let c2da_fresh12 : float = uint_bits_to_float(uint(c2da_mem[5332 + 1 * 4]) | uint(c2da_mem[5332 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 1 * 4 + 3]) << 0x18) - float(uint_bits_to_float(uint(c2da_mem[695864]) | uint(c2da_mem[695865]) << 0x8 | uint(c2da_mem[695866]) << 0x10 | uint(c2da_mem[695867]) << 0x18))
        let c2da_fresh13 : uint = float_bits_to_uint(c2da_fresh12)
        c2da_mem[5332 + 1 * 4] = uint8(c2da_fresh13)
        c2da_mem[5332 + 1 * 4 + 1] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[5332 + 1 * 4 + 2] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[5332 + 1 * 4 + 3] = uint8(c2da_fresh13 >> 0x18)
        i = 0
        while (i < 3) {
            let c2da_fresh14 : float = uint_bits_to_float(uint(c2da_mem[5320 + i * 4]) | uint(c2da_mem[5320 + i * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + i * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + i * 4 + 3]) << 0x18) - float(uint_bits_to_float(uint(c2da_mem[695760 + i * 4]) | uint(c2da_mem[695760 + i * 4 + 1]) << 0x8 | uint(c2da_mem[695760 + i * 4 + 2]) << 0x10 | uint(c2da_mem[695760 + i * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[695816]) | uint(c2da_mem[695817]) << 0x8 | uint(c2da_mem[695818]) << 0x10 | uint(c2da_mem[695819]) << 0x18))
            let c2da_fresh15 : uint = float_bits_to_uint(c2da_fresh14)
            c2da_mem[5320 + i * 4] = uint8(c2da_fresh15)
            c2da_mem[5320 + i * 4 + 1] = uint8(c2da_fresh15 >> 0x8)
            c2da_mem[5320 + i * 4 + 2] = uint8(c2da_fresh15 >> 0x10)
            c2da_mem[5320 + i * 4 + 3] = uint8(c2da_fresh15 >> 0x18)
            i++
        }
        R_RenderView()
        vid.buffer = vid.buffer + int(vid.rowbytes >> 1u)
        R_PushDlights()
        let c2da_fresh16 : float = uint_bits_to_float(uint(c2da_mem[5332 + 1 * 4]) | uint(c2da_mem[5332 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 1 * 4 + 3]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[695864]) | uint(c2da_mem[695865]) << 0x8 | uint(c2da_mem[695866]) << 0x10 | uint(c2da_mem[695867]) << 0x18) * 2.0)
        let c2da_fresh17 : uint = float_bits_to_uint(c2da_fresh16)
        c2da_mem[5332 + 1 * 4] = uint8(c2da_fresh17)
        c2da_mem[5332 + 1 * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
        c2da_mem[5332 + 1 * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
        c2da_mem[5332 + 1 * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
        i = 0
        for (c2da_i in range(i, 3)) {
            let c2da_fresh18 : float = uint_bits_to_float(uint(c2da_mem[5320 + c2da_i * 4]) | uint(c2da_mem[5320 + c2da_i * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + c2da_i * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + c2da_i * 4 + 3]) << 0x18) + float(2.0 * uint_bits_to_float(uint(c2da_mem[695760 + c2da_i * 4]) | uint(c2da_mem[695760 + c2da_i * 4 + 1]) << 0x8 | uint(c2da_mem[695760 + c2da_i * 4 + 2]) << 0x10 | uint(c2da_mem[695760 + c2da_i * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[695816]) | uint(c2da_mem[695817]) << 0x8 | uint(c2da_mem[695818]) << 0x10 | uint(c2da_mem[695819]) << 0x18))
            let c2da_fresh19 : uint = float_bits_to_uint(c2da_fresh18)
            c2da_mem[5320 + c2da_i * 4] = uint8(c2da_fresh19)
            c2da_mem[5320 + c2da_i * 4 + 1] = uint8(c2da_fresh19 >> 0x8)
            c2da_mem[5320 + c2da_i * 4 + 2] = uint8(c2da_fresh19 >> 0x10)
            c2da_mem[5320 + c2da_i * 4 + 3] = uint8(c2da_fresh19 >> 0x18)
        }
        R_RenderView()
        vid.buffer = vid.buffer - int(vid.rowbytes >> 1u)
        let c2da_fresh20 : int = int(uint(c2da_mem[5212]) | uint(c2da_mem[5213]) << 0x8 | uint(c2da_mem[5214]) << 0x10 | uint(c2da_mem[5215]) << 0x18) << 1
        let c2da_fresh21 : uint = uint(c2da_fresh20)
        c2da_mem[5212] = uint8(c2da_fresh21)
        c2da_mem[5213] = uint8(c2da_fresh21 >> 0x8)
        c2da_mem[5214] = uint8(c2da_fresh21 >> 0x10)
        c2da_mem[5215] = uint8(c2da_fresh21 >> 0x18)
        vid.rowbytes = vid.rowbytes >> 1u
        vid.aspect = vid.aspect * 2.0
    } else {
        R_RenderView()
    }
    if (uint_bits_to_float(uint(c2da_mem[696344]) | uint(c2da_mem[696345]) << 0x8 | uint(c2da_mem[696346]) << 0x10 | uint(c2da_mem[696347]) << 0x18) != 0.0) {
        Draw_Character(int(float(int(uint(c2da_mem[462512]) | uint(c2da_mem[462513]) << 0x8 | uint(c2da_mem[462514]) << 0x10 | uint(c2da_mem[462515]) << 0x18) + int(uint(c2da_mem[462520]) | uint(c2da_mem[462521]) << 0x8 | uint(c2da_mem[462522]) << 0x10 | uint(c2da_mem[462523]) << 0x18) / 2) + uint_bits_to_float(uint(c2da_mem[696392]) | uint(c2da_mem[696393]) << 0x8 | uint(c2da_mem[696394]) << 0x10 | uint(c2da_mem[696395]) << 0x18)), int(float(int(uint(c2da_mem[462516]) | uint(c2da_mem[462517]) << 0x8 | uint(c2da_mem[462518]) << 0x10 | uint(c2da_mem[462519]) << 0x18) + int(uint(c2da_mem[462524]) | uint(c2da_mem[462525]) << 0x8 | uint(c2da_mem[462526]) << 0x10 | uint(c2da_mem[462527]) << 0x18) / 2) + uint_bits_to_float(uint(c2da_mem[696440]) | uint(c2da_mem[696441]) << 0x8 | uint(c2da_mem[696442]) << 0x10 | uint(c2da_mem[696443]) << 0x18)), 43)
    }
    return
}
[export, sideeffects]
def V_CalcRefdef() {
    let c2da_saved_sp : int = c2da_lin_sp
    V_CalcRefdef_c2da_frame(c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def CalcGunAngle() {
    var yaw : float
    var pitch : float
    var move : float
    yaw = uint_bits_to_float(uint(c2da_mem[5332 + 1 * 4]) | uint(c2da_mem[5332 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 1 * 4 + 3]) << 0x18)
    pitch = -uint_bits_to_float(uint(c2da_mem[5332 + 0 * 4]) | uint(c2da_mem[5332 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 0 * 4 + 3]) << 0x18)
    yaw = float(double(angledelta(yaw - uint_bits_to_float(uint(c2da_mem[5332 + 1 * 4]) | uint(c2da_mem[5332 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 1 * 4 + 3]) << 0x18))) * 0.4lf)
    if (yaw > 10.0) {
        yaw = 10.0
    }
    if (yaw < -10.0) {
        yaw = -10.0
    }
    pitch = float(double(angledelta(-pitch - uint_bits_to_float(uint(c2da_mem[5332 + 0 * 4]) | uint(c2da_mem[5332 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 0 * 4 + 3]) << 0x18))) * 0.4lf)
    if (pitch > 10.0) {
        pitch = 10.0
    }
    if (pitch < -10.0) {
        pitch = -10.0
    }
    move = float(host_frametime * 20.0lf)
    if (yaw > CalcGunAngle__oldyaw) {
        if (CalcGunAngle__oldyaw + move < yaw) {
            yaw = CalcGunAngle__oldyaw + move
        }
    } elif (CalcGunAngle__oldyaw - move > yaw) {
        yaw = CalcGunAngle__oldyaw - move
    }
    if (pitch > CalcGunAngle__oldpitch) {
        if (CalcGunAngle__oldpitch + move < pitch) {
            pitch = CalcGunAngle__oldpitch + move
        }
    } elif (CalcGunAngle__oldpitch - move > pitch) {
        pitch = CalcGunAngle__oldpitch - move
    }
    CalcGunAngle__oldyaw = yaw
    CalcGunAngle__oldpitch = pitch
    let c2da_fresh97 : float = uint_bits_to_float(uint(c2da_mem[5332 + 1 * 4]) | uint(c2da_mem[5332 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 1 * 4 + 3]) << 0x18) + yaw
    let c2da_fresh98 : uint = float_bits_to_uint(c2da_fresh97)
    c2da_mem[5108 + 1 * 4] = uint8(c2da_fresh98)
    c2da_mem[5108 + 1 * 4 + 1] = uint8(c2da_fresh98 >> 0x8)
    c2da_mem[5108 + 1 * 4 + 2] = uint8(c2da_fresh98 >> 0x10)
    c2da_mem[5108 + 1 * 4 + 3] = uint8(c2da_fresh98 >> 0x18)
    let c2da_fresh99 : float = -(uint_bits_to_float(uint(c2da_mem[5332 + 0 * 4]) | uint(c2da_mem[5332 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 0 * 4 + 3]) << 0x18) + pitch)
    let c2da_fresh100 : uint = float_bits_to_uint(c2da_fresh99)
    c2da_mem[5108 + 0 * 4] = uint8(c2da_fresh100)
    c2da_mem[5108 + 0 * 4 + 1] = uint8(c2da_fresh100 >> 0x8)
    c2da_mem[5108 + 0 * 4 + 2] = uint8(c2da_fresh100 >> 0x10)
    c2da_mem[5108 + 0 * 4 + 3] = uint8(c2da_fresh100 >> 0x18)
    let c2da_fresh101 : float = float(double(uint_bits_to_float(uint(c2da_mem[5108 + 2 * 4]) | uint(c2da_mem[5108 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[5108 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[5108 + 2 * 4 + 3]) << 0x18)) - double(double(uint_bits_to_float(uint(c2da_mem[696296]) | uint(c2da_mem[696297]) << 0x8 | uint(c2da_mem[696298]) << 0x10 | uint(c2da_mem[696299]) << 0x18)) * sin(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) * double(uint_bits_to_float(uint(c2da_mem[696056]) | uint(c2da_mem[696057]) << 0x8 | uint(c2da_mem[696058]) << 0x10 | uint(c2da_mem[696059]) << 0x18))) * double(uint_bits_to_float(uint(c2da_mem[696200]) | uint(c2da_mem[696201]) << 0x8 | uint(c2da_mem[696202]) << 0x10 | uint(c2da_mem[696203]) << 0x18))))
    let c2da_fresh102 : uint = float_bits_to_uint(c2da_fresh101)
    c2da_mem[5108 + 2 * 4] = uint8(c2da_fresh102)
    c2da_mem[5108 + 2 * 4 + 1] = uint8(c2da_fresh102 >> 0x8)
    c2da_mem[5108 + 2 * 4 + 2] = uint8(c2da_fresh102 >> 0x10)
    c2da_mem[5108 + 2 * 4 + 3] = uint8(c2da_fresh102 >> 0x18)
    let c2da_fresh103 : float = float(double(uint_bits_to_float(uint(c2da_mem[5108 + 0 * 4]) | uint(c2da_mem[5108 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[5108 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[5108 + 0 * 4 + 3]) << 0x18)) - double(double(uint_bits_to_float(uint(c2da_mem[696296]) | uint(c2da_mem[696297]) << 0x8 | uint(c2da_mem[696298]) << 0x10 | uint(c2da_mem[696299]) << 0x18)) * sin(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) * double(uint_bits_to_float(uint(c2da_mem[696104]) | uint(c2da_mem[696105]) << 0x8 | uint(c2da_mem[696106]) << 0x10 | uint(c2da_mem[696107]) << 0x18))) * double(uint_bits_to_float(uint(c2da_mem[696248]) | uint(c2da_mem[696249]) << 0x8 | uint(c2da_mem[696250]) << 0x10 | uint(c2da_mem[696251]) << 0x18))))
    let c2da_fresh104 : uint = float_bits_to_uint(c2da_fresh103)
    c2da_mem[5108 + 0 * 4] = uint8(c2da_fresh104)
    c2da_mem[5108 + 0 * 4 + 1] = uint8(c2da_fresh104 >> 0x8)
    c2da_mem[5108 + 0 * 4 + 2] = uint8(c2da_fresh104 >> 0x10)
    c2da_mem[5108 + 0 * 4 + 3] = uint8(c2da_fresh104 >> 0x18)
    let c2da_fresh105 : float = float(double(uint_bits_to_float(uint(c2da_mem[5108 + 1 * 4]) | uint(c2da_mem[5108 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[5108 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[5108 + 1 * 4 + 3]) << 0x18)) - double(double(uint_bits_to_float(uint(c2da_mem[696296]) | uint(c2da_mem[696297]) << 0x8 | uint(c2da_mem[696298]) << 0x10 | uint(c2da_mem[696299]) << 0x18)) * sin(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) * double(uint_bits_to_float(uint(c2da_mem[696008]) | uint(c2da_mem[696009]) << 0x8 | uint(c2da_mem[696010]) << 0x10 | uint(c2da_mem[696011]) << 0x18))) * double(uint_bits_to_float(uint(c2da_mem[696152]) | uint(c2da_mem[696153]) << 0x8 | uint(c2da_mem[696154]) << 0x10 | uint(c2da_mem[696155]) << 0x18))))
    let c2da_fresh106 : uint = float_bits_to_uint(c2da_fresh105)
    c2da_mem[5108 + 1 * 4] = uint8(c2da_fresh106)
    c2da_mem[5108 + 1 * 4 + 1] = uint8(c2da_fresh106 >> 0x8)
    c2da_mem[5108 + 1 * 4 + 2] = uint8(c2da_fresh106 >> 0x10)
    c2da_mem[5108 + 1 * 4 + 3] = uint8(c2da_fresh106 >> 0x18)
    return
}
[export, sideeffects]
def angledelta(var a : float) : float {
    a = anglemod(a)
    if (a > 180.0) {
        a -= 360.0
    }
    return a
}
[export, sideeffects]
def V_BoundOffsets() {
    var ent_0 : int = 10048 + int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18) * 200
    if (uint_bits_to_float(uint(c2da_mem[5320 + 0 * 4]) | uint(c2da_mem[5320 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 0 * 4 + 3]) << 0x18) < uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 0 * 4]) | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 3]) << 0x18) - 14.0) {
        let c2da_fresh107 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 0 * 4]) | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 3]) << 0x18) - 14.0
        let c2da_fresh108 : uint = float_bits_to_uint(c2da_fresh107)
        c2da_mem[5320 + 0 * 4] = uint8(c2da_fresh108)
        c2da_mem[5320 + 0 * 4 + 1] = uint8(c2da_fresh108 >> 0x8)
        c2da_mem[5320 + 0 * 4 + 2] = uint8(c2da_fresh108 >> 0x10)
        c2da_mem[5320 + 0 * 4 + 3] = uint8(c2da_fresh108 >> 0x18)
    } elif (uint_bits_to_float(uint(c2da_mem[5320 + 0 * 4]) | uint(c2da_mem[5320 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 0 * 4 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 0 * 4]) | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 3]) << 0x18) + 14.0) {
        let c2da_fresh109 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 0 * 4]) | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 0 * 4 + 3]) << 0x18) + 14.0
        let c2da_fresh110 : uint = float_bits_to_uint(c2da_fresh109)
        c2da_mem[5320 + 0 * 4] = uint8(c2da_fresh110)
        c2da_mem[5320 + 0 * 4 + 1] = uint8(c2da_fresh110 >> 0x8)
        c2da_mem[5320 + 0 * 4 + 2] = uint8(c2da_fresh110 >> 0x10)
        c2da_mem[5320 + 0 * 4 + 3] = uint8(c2da_fresh110 >> 0x18)
    }
    if (uint_bits_to_float(uint(c2da_mem[5320 + 1 * 4]) | uint(c2da_mem[5320 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 1 * 4 + 3]) << 0x18) < uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 1 * 4]) | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 3]) << 0x18) - 14.0) {
        let c2da_fresh111 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 1 * 4]) | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 3]) << 0x18) - 14.0
        let c2da_fresh112 : uint = float_bits_to_uint(c2da_fresh111)
        c2da_mem[5320 + 1 * 4] = uint8(c2da_fresh112)
        c2da_mem[5320 + 1 * 4 + 1] = uint8(c2da_fresh112 >> 0x8)
        c2da_mem[5320 + 1 * 4 + 2] = uint8(c2da_fresh112 >> 0x10)
        c2da_mem[5320 + 1 * 4 + 3] = uint8(c2da_fresh112 >> 0x18)
    } elif (uint_bits_to_float(uint(c2da_mem[5320 + 1 * 4]) | uint(c2da_mem[5320 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 1 * 4 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 1 * 4]) | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 3]) << 0x18) + 14.0) {
        let c2da_fresh113 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 1 * 4]) | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 1 * 4 + 3]) << 0x18) + 14.0
        let c2da_fresh114 : uint = float_bits_to_uint(c2da_fresh113)
        c2da_mem[5320 + 1 * 4] = uint8(c2da_fresh114)
        c2da_mem[5320 + 1 * 4 + 1] = uint8(c2da_fresh114 >> 0x8)
        c2da_mem[5320 + 1 * 4 + 2] = uint8(c2da_fresh114 >> 0x10)
        c2da_mem[5320 + 1 * 4 + 3] = uint8(c2da_fresh114 >> 0x18)
    }
    if (uint_bits_to_float(uint(c2da_mem[5320 + 2 * 4]) | uint(c2da_mem[5320 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 2 * 4 + 3]) << 0x18) < uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 2 * 4]) | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 3]) << 0x18) - 22.0) {
        let c2da_fresh115 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 2 * 4]) | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 3]) << 0x18) - 22.0
        let c2da_fresh116 : uint = float_bits_to_uint(c2da_fresh115)
        c2da_mem[5320 + 2 * 4] = uint8(c2da_fresh116)
        c2da_mem[5320 + 2 * 4 + 1] = uint8(c2da_fresh116 >> 0x8)
        c2da_mem[5320 + 2 * 4 + 2] = uint8(c2da_fresh116 >> 0x10)
        c2da_mem[5320 + 2 * 4 + 3] = uint8(c2da_fresh116 >> 0x18)
    } elif (uint_bits_to_float(uint(c2da_mem[5320 + 2 * 4]) | uint(c2da_mem[5320 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 2 * 4 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 2 * 4]) | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 3]) << 0x18) + 30.0) {
        let c2da_fresh117 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 88 + 2 * 4]) | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 88 + 2 * 4 + 3]) << 0x18) + 30.0
        let c2da_fresh118 : uint = float_bits_to_uint(c2da_fresh117)
        c2da_mem[5320 + 2 * 4] = uint8(c2da_fresh118)
        c2da_mem[5320 + 2 * 4 + 1] = uint8(c2da_fresh118 >> 0x8)
        c2da_mem[5320 + 2 * 4 + 2] = uint8(c2da_fresh118 >> 0x10)
        c2da_mem[5320 + 2 * 4 + 3] = uint8(c2da_fresh118 >> 0x18)
    }
    return
}
[export, sideeffects]
def V_AddIdle() {
    let c2da_fresh119 : float = float(double(uint_bits_to_float(uint(c2da_mem[5332 + 2 * 4]) | uint(c2da_mem[5332 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 2 * 4 + 3]) << 0x18)) + double(double(uint_bits_to_float(uint(c2da_mem[696296]) | uint(c2da_mem[696297]) << 0x8 | uint(c2da_mem[696298]) << 0x10 | uint(c2da_mem[696299]) << 0x18)) * sin(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) * double(uint_bits_to_float(uint(c2da_mem[696056]) | uint(c2da_mem[696057]) << 0x8 | uint(c2da_mem[696058]) << 0x10 | uint(c2da_mem[696059]) << 0x18))) * double(uint_bits_to_float(uint(c2da_mem[696200]) | uint(c2da_mem[696201]) << 0x8 | uint(c2da_mem[696202]) << 0x10 | uint(c2da_mem[696203]) << 0x18))))
    let c2da_fresh120 : uint = float_bits_to_uint(c2da_fresh119)
    c2da_mem[5332 + 2 * 4] = uint8(c2da_fresh120)
    c2da_mem[5332 + 2 * 4 + 1] = uint8(c2da_fresh120 >> 0x8)
    c2da_mem[5332 + 2 * 4 + 2] = uint8(c2da_fresh120 >> 0x10)
    c2da_mem[5332 + 2 * 4 + 3] = uint8(c2da_fresh120 >> 0x18)
    let c2da_fresh121 : float = float(double(uint_bits_to_float(uint(c2da_mem[5332 + 0 * 4]) | uint(c2da_mem[5332 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 0 * 4 + 3]) << 0x18)) + double(double(uint_bits_to_float(uint(c2da_mem[696296]) | uint(c2da_mem[696297]) << 0x8 | uint(c2da_mem[696298]) << 0x10 | uint(c2da_mem[696299]) << 0x18)) * sin(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) * double(uint_bits_to_float(uint(c2da_mem[696104]) | uint(c2da_mem[696105]) << 0x8 | uint(c2da_mem[696106]) << 0x10 | uint(c2da_mem[696107]) << 0x18))) * double(uint_bits_to_float(uint(c2da_mem[696248]) | uint(c2da_mem[696249]) << 0x8 | uint(c2da_mem[696250]) << 0x10 | uint(c2da_mem[696251]) << 0x18))))
    let c2da_fresh122 : uint = float_bits_to_uint(c2da_fresh121)
    c2da_mem[5332 + 0 * 4] = uint8(c2da_fresh122)
    c2da_mem[5332 + 0 * 4 + 1] = uint8(c2da_fresh122 >> 0x8)
    c2da_mem[5332 + 0 * 4 + 2] = uint8(c2da_fresh122 >> 0x10)
    c2da_mem[5332 + 0 * 4 + 3] = uint8(c2da_fresh122 >> 0x18)
    let c2da_fresh123 : float = float(double(uint_bits_to_float(uint(c2da_mem[5332 + 1 * 4]) | uint(c2da_mem[5332 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 1 * 4 + 3]) << 0x18)) + double(double(uint_bits_to_float(uint(c2da_mem[696296]) | uint(c2da_mem[696297]) << 0x8 | uint(c2da_mem[696298]) << 0x10 | uint(c2da_mem[696299]) << 0x18)) * sin(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) * double(uint_bits_to_float(uint(c2da_mem[696008]) | uint(c2da_mem[696009]) << 0x8 | uint(c2da_mem[696010]) << 0x10 | uint(c2da_mem[696011]) << 0x18))) * double(uint_bits_to_float(uint(c2da_mem[696152]) | uint(c2da_mem[696153]) << 0x8 | uint(c2da_mem[696154]) << 0x10 | uint(c2da_mem[696155]) << 0x18))))
    let c2da_fresh124 : uint = float_bits_to_uint(c2da_fresh123)
    c2da_mem[5332 + 1 * 4] = uint8(c2da_fresh124)
    c2da_mem[5332 + 1 * 4 + 1] = uint8(c2da_fresh124 >> 0x8)
    c2da_mem[5332 + 1 * 4 + 2] = uint8(c2da_fresh124 >> 0x10)
    c2da_mem[5332 + 1 * 4 + 3] = uint8(c2da_fresh124 >> 0x18)
    return
}
[export, sideeffects]
def V_CalcViewRoll() {
    var side : float = V_CalcRoll(10048 + int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18) * 200 + 124, 688)
    let c2da_fresh125 : float = uint_bits_to_float(uint(c2da_mem[5332 + 2 * 4]) | uint(c2da_mem[5332 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 2 * 4 + 3]) << 0x18) + side
    let c2da_fresh126 : uint = float_bits_to_uint(c2da_fresh125)
    c2da_mem[5332 + 2 * 4] = uint8(c2da_fresh126)
    c2da_mem[5332 + 2 * 4 + 1] = uint8(c2da_fresh126 >> 0x8)
    c2da_mem[5332 + 2 * 4 + 2] = uint8(c2da_fresh126 >> 0x10)
    c2da_mem[5332 + 2 * 4 + 3] = uint8(c2da_fresh126 >> 0x18)
    if (v_dmg_time > 0.0) {
        let c2da_fresh127 : float = uint_bits_to_float(uint(c2da_mem[5332 + 2 * 4]) | uint(c2da_mem[5332 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 2 * 4 + 3]) << 0x18) + float(v_dmg_time / uint_bits_to_float(uint(c2da_mem[696920]) | uint(c2da_mem[696921]) << 0x8 | uint(c2da_mem[696922]) << 0x10 | uint(c2da_mem[696923]) << 0x18) * v_dmg_roll)
        let c2da_fresh128 : uint = float_bits_to_uint(c2da_fresh127)
        c2da_mem[5332 + 2 * 4] = uint8(c2da_fresh128)
        c2da_mem[5332 + 2 * 4 + 1] = uint8(c2da_fresh128 >> 0x8)
        c2da_mem[5332 + 2 * 4 + 2] = uint8(c2da_fresh128 >> 0x10)
        c2da_mem[5332 + 2 * 4 + 3] = uint8(c2da_fresh128 >> 0x18)
        let c2da_fresh129 : float = uint_bits_to_float(uint(c2da_mem[5332 + 0 * 4]) | uint(c2da_mem[5332 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 0 * 4 + 3]) << 0x18) + float(v_dmg_time / uint_bits_to_float(uint(c2da_mem[696920]) | uint(c2da_mem[696921]) << 0x8 | uint(c2da_mem[696922]) << 0x10 | uint(c2da_mem[696923]) << 0x18) * v_dmg_pitch)
        let c2da_fresh130 : uint = float_bits_to_uint(c2da_fresh129)
        c2da_mem[5332 + 0 * 4] = uint8(c2da_fresh130)
        c2da_mem[5332 + 0 * 4 + 1] = uint8(c2da_fresh130 >> 0x8)
        c2da_mem[5332 + 0 * 4 + 2] = uint8(c2da_fresh130 >> 0x10)
        c2da_mem[5332 + 0 * 4 + 3] = uint8(c2da_fresh130 >> 0x18)
        v_dmg_time = float(double(v_dmg_time) - host_frametime)
    }
    if (int(uint(c2da_mem[236 + 0 * 4]) | uint(c2da_mem[236 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 0 * 4 + 3]) << 0x18) <= 0) {
        let c2da_fresh131 : float = 80.0
        let c2da_fresh132 : uint = float_bits_to_uint(c2da_fresh131)
        c2da_mem[5332 + 2 * 4] = uint8(c2da_fresh132)
        c2da_mem[5332 + 2 * 4 + 1] = uint8(c2da_fresh132 >> 0x8)
        c2da_mem[5332 + 2 * 4 + 2] = uint8(c2da_fresh132 >> 0x10)
        c2da_mem[5332 + 2 * 4 + 3] = uint8(c2da_fresh132 >> 0x18)
        return
    }
    return
}
var v_dmg_time : float = default<float>

var v_dmg_pitch : float = default<float>

var v_dmg_roll : float = default<float>

[export, sideeffects]
def V_CalcRoll(var angles_0 : int; var velocity_0 : int) : float {
    var sign : float
    var side_0 : float
    var value : float
    AngleVectors(angles_0, 695744, 695760, 695776)
    side_0 = uint_bits_to_float(uint(c2da_mem[velocity_0 + 0 * 4]) | uint(c2da_mem[velocity_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[velocity_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[velocity_0 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[695760 + 0 * 4]) | uint(c2da_mem[695760 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[695760 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[695760 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[velocity_0 + 1 * 4]) | uint(c2da_mem[velocity_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[velocity_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[velocity_0 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[695760 + 1 * 4]) | uint(c2da_mem[695760 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[695760 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[695760 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[velocity_0 + 2 * 4]) | uint(c2da_mem[velocity_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[velocity_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[velocity_0 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[695760 + 2 * 4]) | uint(c2da_mem[695760 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[695760 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[695760 + 2 * 4 + 3]) << 0x18)
    sign = float(side_0 < 0.0 ? -1 : 1)
    side_0 = float(c2da_std_fabs(double(side_0)))
    value = uint_bits_to_float(uint(c2da_mem[696728]) | uint(c2da_mem[696729]) << 0x8 | uint(c2da_mem[696730]) << 0x10 | uint(c2da_mem[696731]) << 0x18)
    if (side_0 < uint_bits_to_float(uint(c2da_mem[696680]) | uint(c2da_mem[696681]) << 0x8 | uint(c2da_mem[696682]) << 0x10 | uint(c2da_mem[696683]) << 0x18)) {
        side_0 = side_0 * value / uint_bits_to_float(uint(c2da_mem[696680]) | uint(c2da_mem[696681]) << 0x8 | uint(c2da_mem[696682]) << 0x10 | uint(c2da_mem[696683]) << 0x18)
    } else {
        side_0 = value
    }
    return side_0 * sign
}
[export, sideeffects]
def V_CalcBob() : float {
    var bob_0 : float
    var cycle : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - double(float(int(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) / double(uint_bits_to_float(uint(c2da_mem[696824]) | uint(c2da_mem[696825]) << 0x8 | uint(c2da_mem[696826]) << 0x10 | uint(c2da_mem[696827]) << 0x18)))) * uint_bits_to_float(uint(c2da_mem[696824]) | uint(c2da_mem[696825]) << 0x8 | uint(c2da_mem[696826]) << 0x10 | uint(c2da_mem[696827]) << 0x18)))
    cycle = cycle / uint_bits_to_float(uint(c2da_mem[696824]) | uint(c2da_mem[696825]) << 0x8 | uint(c2da_mem[696826]) << 0x10 | uint(c2da_mem[696827]) << 0x18)
    if (cycle < uint_bits_to_float(uint(c2da_mem[696872]) | uint(c2da_mem[696873]) << 0x8 | uint(c2da_mem[696874]) << 0x10 | uint(c2da_mem[696875]) << 0x18)) {
        cycle = float(3.141592653589793lf * double(cycle) / double(uint_bits_to_float(uint(c2da_mem[696872]) | uint(c2da_mem[696873]) << 0x8 | uint(c2da_mem[696874]) << 0x10 | uint(c2da_mem[696875]) << 0x18)))
    } else {
        cycle = float(3.141592653589793lf + 3.141592653589793lf * double(cycle - uint_bits_to_float(uint(c2da_mem[696872]) | uint(c2da_mem[696873]) << 0x8 | uint(c2da_mem[696874]) << 0x10 | uint(c2da_mem[696875]) << 0x18)) / (1.0lf - double(uint_bits_to_float(uint(c2da_mem[696872]) | uint(c2da_mem[696873]) << 0x8 | uint(c2da_mem[696874]) << 0x10 | uint(c2da_mem[696875]) << 0x18))))
    }
    bob_0 = float(sqrt(double(uint_bits_to_float(uint(c2da_mem[688 + 0 * 4]) | uint(c2da_mem[688 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[688 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[688 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[688 + 0 * 4]) | uint(c2da_mem[688 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[688 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[688 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[688 + 1 * 4]) | uint(c2da_mem[688 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[688 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[688 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[688 + 1 * 4]) | uint(c2da_mem[688 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[688 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[688 + 1 * 4 + 3]) << 0x18))) * double(uint_bits_to_float(uint(c2da_mem[696776]) | uint(c2da_mem[696777]) << 0x8 | uint(c2da_mem[696778]) << 0x10 | uint(c2da_mem[696779]) << 0x18)))
    bob_0 = float(double(bob_0) * 0.3lf + double(bob_0) * 0.7lf * sin(double(cycle)))
    if (bob_0 > 4.0) {
        bob_0 = 4.0
    } elif (bob_0 < -7.0) {
        bob_0 = -7.0
    }
    return bob_0
}
[export, sideeffects]
def V_DriftPitch() {
    var delta : float
    var move_0 : float
    if (uint(noclip_anglehack) != 0x0 || (uint(c2da_mem[748]) | uint(c2da_mem[749]) << 0x8 | uint(c2da_mem[750]) << 0x10 | uint(c2da_mem[751]) << 0x18) == 0u || (uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) != 0x0) {
        let c2da_fresh133 : float = 0.0
        let c2da_fresh134 : uint = float_bits_to_uint(c2da_fresh133)
        c2da_mem[724] = uint8(c2da_fresh134)
        c2da_mem[725] = uint8(c2da_fresh134 >> 0x8)
        c2da_mem[726] = uint8(c2da_fresh134 >> 0x10)
        c2da_mem[727] = uint8(c2da_fresh134 >> 0x18)
        let c2da_fresh135 : float = 0.0
        let c2da_fresh136 : uint = float_bits_to_uint(c2da_fresh135)
        c2da_mem[716] = uint8(c2da_fresh136)
        c2da_mem[717] = uint8(c2da_fresh136 >> 0x8)
        c2da_mem[718] = uint8(c2da_fresh136 >> 0x10)
        c2da_mem[719] = uint8(c2da_fresh136 >> 0x18)
        return
    }
    if ((uint(c2da_mem[720]) | uint(c2da_mem[721]) << 0x8 | uint(c2da_mem[722]) << 0x10 | uint(c2da_mem[723]) << 0x18) != 0u) {
        if (c2da_std_fabs(double(uint_bits_to_float(uint(c2da_mem[224]) | uint(c2da_mem[225]) << 0x8 | uint(c2da_mem[226]) << 0x10 | uint(c2da_mem[227]) << 0x18))) < double(uint_bits_to_float(uint(c2da_mem[9304]) | uint(c2da_mem[9305]) << 0x8 | uint(c2da_mem[9306]) << 0x10 | uint(c2da_mem[9307]) << 0x18))) {
            let c2da_fresh137 : float = 0.0
            let c2da_fresh138 : uint = float_bits_to_uint(c2da_fresh137)
            c2da_mem[724] = uint8(c2da_fresh138)
            c2da_mem[725] = uint8(c2da_fresh138 >> 0x8)
            c2da_mem[726] = uint8(c2da_fresh138 >> 0x10)
            c2da_mem[727] = uint8(c2da_fresh138 >> 0x18)
        } else {
            let c2da_fresh139 : float = float(double(uint_bits_to_float(uint(c2da_mem[724]) | uint(c2da_mem[725]) << 0x8 | uint(c2da_mem[726]) << 0x10 | uint(c2da_mem[727]) << 0x18)) + double(host_frametime))
            let c2da_fresh140 : uint = float_bits_to_uint(c2da_fresh139)
            c2da_mem[724] = uint8(c2da_fresh140)
            c2da_mem[725] = uint8(c2da_fresh140 >> 0x8)
            c2da_mem[726] = uint8(c2da_fresh140 >> 0x10)
            c2da_mem[727] = uint8(c2da_fresh140 >> 0x18)
        }
        if (uint_bits_to_float(uint(c2da_mem[724]) | uint(c2da_mem[725]) << 0x8 | uint(c2da_mem[726]) << 0x10 | uint(c2da_mem[727]) << 0x18) > uint_bits_to_float(uint(c2da_mem[695912]) | uint(c2da_mem[695913]) << 0x8 | uint(c2da_mem[695914]) << 0x10 | uint(c2da_mem[695915]) << 0x18)) {
            V_StartPitchDrift()
        }
        return
    }
    delta = uint_bits_to_float(uint(c2da_mem[712]) | uint(c2da_mem[713]) << 0x8 | uint(c2da_mem[714]) << 0x10 | uint(c2da_mem[715]) << 0x18) - uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18)
    if (delta == 0.0) {
        let c2da_fresh141 : float = 0.0
        let c2da_fresh142 : uint = float_bits_to_uint(c2da_fresh141)
        c2da_mem[716] = uint8(c2da_fresh142)
        c2da_mem[717] = uint8(c2da_fresh142 >> 0x8)
        c2da_mem[718] = uint8(c2da_fresh142 >> 0x10)
        c2da_mem[719] = uint8(c2da_fresh142 >> 0x18)
        return
    }
    move_0 = float(host_frametime * double(uint_bits_to_float(uint(c2da_mem[716]) | uint(c2da_mem[717]) << 0x8 | uint(c2da_mem[718]) << 0x10 | uint(c2da_mem[719]) << 0x18)))
    let c2da_fresh143 : float = float(double(uint_bits_to_float(uint(c2da_mem[716]) | uint(c2da_mem[717]) << 0x8 | uint(c2da_mem[718]) << 0x10 | uint(c2da_mem[719]) << 0x18)) + double(host_frametime * double(uint_bits_to_float(uint(c2da_mem[695960]) | uint(c2da_mem[695961]) << 0x8 | uint(c2da_mem[695962]) << 0x10 | uint(c2da_mem[695963]) << 0x18))))
    let c2da_fresh144 : uint = float_bits_to_uint(c2da_fresh143)
    c2da_mem[716] = uint8(c2da_fresh144)
    c2da_mem[717] = uint8(c2da_fresh144 >> 0x8)
    c2da_mem[718] = uint8(c2da_fresh144 >> 0x10)
    c2da_mem[719] = uint8(c2da_fresh144 >> 0x18)
    if (delta > 0.0) {
        if (move_0 > delta) {
            let c2da_fresh145 : float = 0.0
            let c2da_fresh146 : uint = float_bits_to_uint(c2da_fresh145)
            c2da_mem[716] = uint8(c2da_fresh146)
            c2da_mem[717] = uint8(c2da_fresh146 >> 0x8)
            c2da_mem[718] = uint8(c2da_fresh146 >> 0x10)
            c2da_mem[719] = uint8(c2da_fresh146 >> 0x18)
            move_0 = delta
        }
        let c2da_fresh147 : float = uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18) + move_0
        let c2da_fresh148 : uint = float_bits_to_uint(c2da_fresh147)
        c2da_mem[652 + 0 * 4] = uint8(c2da_fresh148)
        c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh148 >> 0x8)
        c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh148 >> 0x10)
        c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh148 >> 0x18)
    } elif (delta < 0.0) {
        if (move_0 > -delta) {
            let c2da_fresh149 : float = 0.0
            let c2da_fresh150 : uint = float_bits_to_uint(c2da_fresh149)
            c2da_mem[716] = uint8(c2da_fresh150)
            c2da_mem[717] = uint8(c2da_fresh150 >> 0x8)
            c2da_mem[718] = uint8(c2da_fresh150 >> 0x10)
            c2da_mem[719] = uint8(c2da_fresh150 >> 0x18)
            move_0 = -delta
        }
        let c2da_fresh151 : float = uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18) - move_0
        let c2da_fresh152 : uint = float_bits_to_uint(c2da_fresh151)
        c2da_mem[652 + 0 * 4] = uint8(c2da_fresh152)
        c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh152 >> 0x8)
        c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh152 >> 0x10)
        c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh152 >> 0x18)
    }
    return
}
[export, sideeffects]
def V_CalcIntermissionRefdef() {
    var ent_1 : int
    var view_0 : int
    var old : float
    ent_1 = 10048 + int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18) * 200
    view_0 = 4984
    let c2da_fresh153 : float = uint_bits_to_float(uint(c2da_mem[ent_1 + 88 + 0 * 4]) | uint(c2da_mem[ent_1 + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 88 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh154 : uint = float_bits_to_uint(c2da_fresh153)
    c2da_mem[5320 + 0 * 4] = uint8(c2da_fresh154)
    c2da_mem[5320 + 0 * 4 + 1] = uint8(c2da_fresh154 >> 0x8)
    c2da_mem[5320 + 0 * 4 + 2] = uint8(c2da_fresh154 >> 0x10)
    c2da_mem[5320 + 0 * 4 + 3] = uint8(c2da_fresh154 >> 0x18)
    let c2da_fresh155 : float = uint_bits_to_float(uint(c2da_mem[ent_1 + 88 + 1 * 4]) | uint(c2da_mem[ent_1 + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 88 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh156 : uint = float_bits_to_uint(c2da_fresh155)
    c2da_mem[5320 + 1 * 4] = uint8(c2da_fresh156)
    c2da_mem[5320 + 1 * 4 + 1] = uint8(c2da_fresh156 >> 0x8)
    c2da_mem[5320 + 1 * 4 + 2] = uint8(c2da_fresh156 >> 0x10)
    c2da_mem[5320 + 1 * 4 + 3] = uint8(c2da_fresh156 >> 0x18)
    let c2da_fresh157 : float = uint_bits_to_float(uint(c2da_mem[ent_1 + 88 + 2 * 4]) | uint(c2da_mem[ent_1 + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 88 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh158 : uint = float_bits_to_uint(c2da_fresh157)
    c2da_mem[5320 + 2 * 4] = uint8(c2da_fresh158)
    c2da_mem[5320 + 2 * 4 + 1] = uint8(c2da_fresh158 >> 0x8)
    c2da_mem[5320 + 2 * 4 + 2] = uint8(c2da_fresh158 >> 0x10)
    c2da_mem[5320 + 2 * 4 + 3] = uint8(c2da_fresh158 >> 0x18)
    let c2da_fresh159 : float = uint_bits_to_float(uint(c2da_mem[ent_1 + 124 + 0 * 4]) | uint(c2da_mem[ent_1 + 124 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 124 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 124 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh160 : uint = float_bits_to_uint(c2da_fresh159)
    c2da_mem[5332 + 0 * 4] = uint8(c2da_fresh160)
    c2da_mem[5332 + 0 * 4 + 1] = uint8(c2da_fresh160 >> 0x8)
    c2da_mem[5332 + 0 * 4 + 2] = uint8(c2da_fresh160 >> 0x10)
    c2da_mem[5332 + 0 * 4 + 3] = uint8(c2da_fresh160 >> 0x18)
    let c2da_fresh161 : float = uint_bits_to_float(uint(c2da_mem[ent_1 + 124 + 1 * 4]) | uint(c2da_mem[ent_1 + 124 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 124 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 124 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh162 : uint = float_bits_to_uint(c2da_fresh161)
    c2da_mem[5332 + 1 * 4] = uint8(c2da_fresh162)
    c2da_mem[5332 + 1 * 4 + 1] = uint8(c2da_fresh162 >> 0x8)
    c2da_mem[5332 + 1 * 4 + 2] = uint8(c2da_fresh162 >> 0x10)
    c2da_mem[5332 + 1 * 4 + 3] = uint8(c2da_fresh162 >> 0x18)
    let c2da_fresh163 : float = uint_bits_to_float(uint(c2da_mem[ent_1 + 124 + 2 * 4]) | uint(c2da_mem[ent_1 + 124 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 124 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 124 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh164 : uint = float_bits_to_uint(c2da_fresh163)
    c2da_mem[5332 + 2 * 4] = uint8(c2da_fresh164)
    c2da_mem[5332 + 2 * 4 + 1] = uint8(c2da_fresh164 >> 0x8)
    c2da_mem[5332 + 2 * 4 + 2] = uint8(c2da_fresh164 >> 0x10)
    c2da_mem[5332 + 2 * 4 + 3] = uint8(c2da_fresh164 >> 0x18)
    let c2da_fresh165 : uint = 0u
    c2da_mem[view_0 + 136] = uint8(c2da_fresh165)
    c2da_mem[view_0 + 137] = uint8(c2da_fresh165 >> 0x8)
    c2da_mem[view_0 + 138] = uint8(c2da_fresh165 >> 0x10)
    c2da_mem[view_0 + 139] = uint8(c2da_fresh165 >> 0x18)
    c2da_mem[view_0 + 140] = 0u8
    c2da_mem[view_0 + 141] = 0u8
    c2da_mem[view_0 + 142] = 0u8
    c2da_mem[view_0 + 143] = 0u8
    old = uint_bits_to_float(uint(c2da_mem[696296]) | uint(c2da_mem[696297]) << 0x8 | uint(c2da_mem[696298]) << 0x10 | uint(c2da_mem[696299]) << 0x18)
    let c2da_fresh166 : float = 1.0
    let c2da_fresh167 : uint = float_bits_to_uint(c2da_fresh166)
    c2da_mem[696296] = uint8(c2da_fresh167)
    c2da_mem[696297] = uint8(c2da_fresh167 >> 0x8)
    c2da_mem[696298] = uint8(c2da_fresh167 >> 0x10)
    c2da_mem[696299] = uint8(c2da_fresh167 >> 0x18)
    V_AddIdle()
    let c2da_fresh168 : uint = float_bits_to_uint(old)
    c2da_mem[696296] = uint8(c2da_fresh168)
    c2da_mem[696297] = uint8(c2da_fresh168 >> 0x8)
    c2da_mem[696298] = uint8(c2da_fresh168 >> 0x10)
    c2da_mem[696299] = uint8(c2da_fresh168 >> 0x18)
    return
}
[export, sideeffects]
def V_UpdatePalette() {
    let c2da_saved_sp : int = c2da_lin_sp
    V_UpdatePalette_c2da_frame(c2da_lin_enter(768))
    c2da_lin_sp = c2da_saved_sp
}
var gammatable : uint8[256]

[export, sideeffects]
def V_CheckGamma() : uint {
    if (uint_bits_to_float(uint(c2da_mem[697064]) | uint(c2da_mem[697065]) << 0x8 | uint(c2da_mem[697066]) << 0x10 | uint(c2da_mem[697067]) << 0x18) == V_CheckGamma__oldgammavalue) {
        return 0u
    }
    V_CheckGamma__oldgammavalue = uint_bits_to_float(uint(c2da_mem[697064]) | uint(c2da_mem[697065]) << 0x8 | uint(c2da_mem[697066]) << 0x10 | uint(c2da_mem[697067]) << 0x18)
    BuildGammaTable(uint_bits_to_float(uint(c2da_mem[697064]) | uint(c2da_mem[697065]) << 0x8 | uint(c2da_mem[697066]) << 0x10 | uint(c2da_mem[697067]) << 0x18))
    vid.recalc_refdef = 1
    return 1u
}
[export, sideeffects]
def BuildGammaTable(var g_0 : float) {
    var i_2 : int
    var inf : int
    if (double(g_0) == 1.0lf) {
        i_2 = 0
        for (c2da_i_2 in range(i_2, 256)) {
            gammatable[c2da_i_2] = uint8(c2da_i_2)
        }
        return
    }
    i_2 = 0
    for (c2da_i_2_0 in range(i_2, 256)) {
        inf = int(255.0lf * pow((double(c2da_i_2_0) + 0.5lf) / 255.5lf, double(g_0)) + 0.5lf)
        if (inf < 0) {
            inf = 0
        }
        if (inf > 255) {
            inf = 255
        }
        gammatable[c2da_i_2_0] = uint8(inf)
    }
    return
}
[export, sideeffects]
def V_CalcPowerupCshift() {
    if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 4194304) != 0) {
        let c2da_fresh184 : int = 0
        let c2da_fresh185 : uint = uint(c2da_fresh184)
        c2da_mem[500 + 3 * 16 + 0 * 4] = uint8(c2da_fresh185)
        c2da_mem[500 + 3 * 16 + 0 * 4 + 1] = uint8(c2da_fresh185 >> 0x8)
        c2da_mem[500 + 3 * 16 + 0 * 4 + 2] = uint8(c2da_fresh185 >> 0x10)
        c2da_mem[500 + 3 * 16 + 0 * 4 + 3] = uint8(c2da_fresh185 >> 0x18)
        let c2da_fresh186 : int = 0
        let c2da_fresh187 : uint = uint(c2da_fresh186)
        c2da_mem[500 + 3 * 16 + 1 * 4] = uint8(c2da_fresh187)
        c2da_mem[500 + 3 * 16 + 1 * 4 + 1] = uint8(c2da_fresh187 >> 0x8)
        c2da_mem[500 + 3 * 16 + 1 * 4 + 2] = uint8(c2da_fresh187 >> 0x10)
        c2da_mem[500 + 3 * 16 + 1 * 4 + 3] = uint8(c2da_fresh187 >> 0x18)
        let c2da_fresh188 : int = 255
        let c2da_fresh189 : uint = uint(c2da_fresh188)
        c2da_mem[500 + 3 * 16 + 2 * 4] = uint8(c2da_fresh189)
        c2da_mem[500 + 3 * 16 + 2 * 4 + 1] = uint8(c2da_fresh189 >> 0x8)
        c2da_mem[500 + 3 * 16 + 2 * 4 + 2] = uint8(c2da_fresh189 >> 0x10)
        c2da_mem[500 + 3 * 16 + 2 * 4 + 3] = uint8(c2da_fresh189 >> 0x18)
        let c2da_fresh190 : int = 30
        let c2da_fresh191 : uint = uint(c2da_fresh190)
        c2da_mem[500 + 3 * 16 + 12] = uint8(c2da_fresh191)
        c2da_mem[500 + 3 * 16 + 13] = uint8(c2da_fresh191 >> 0x8)
        c2da_mem[500 + 3 * 16 + 14] = uint8(c2da_fresh191 >> 0x10)
        c2da_mem[500 + 3 * 16 + 15] = uint8(c2da_fresh191 >> 0x18)
    } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 2097152) != 0) {
        let c2da_fresh192 : int = 0
        let c2da_fresh193 : uint = uint(c2da_fresh192)
        c2da_mem[500 + 3 * 16 + 0 * 4] = uint8(c2da_fresh193)
        c2da_mem[500 + 3 * 16 + 0 * 4 + 1] = uint8(c2da_fresh193 >> 0x8)
        c2da_mem[500 + 3 * 16 + 0 * 4 + 2] = uint8(c2da_fresh193 >> 0x10)
        c2da_mem[500 + 3 * 16 + 0 * 4 + 3] = uint8(c2da_fresh193 >> 0x18)
        let c2da_fresh194 : int = 255
        let c2da_fresh195 : uint = uint(c2da_fresh194)
        c2da_mem[500 + 3 * 16 + 1 * 4] = uint8(c2da_fresh195)
        c2da_mem[500 + 3 * 16 + 1 * 4 + 1] = uint8(c2da_fresh195 >> 0x8)
        c2da_mem[500 + 3 * 16 + 1 * 4 + 2] = uint8(c2da_fresh195 >> 0x10)
        c2da_mem[500 + 3 * 16 + 1 * 4 + 3] = uint8(c2da_fresh195 >> 0x18)
        let c2da_fresh196 : int = 0
        let c2da_fresh197 : uint = uint(c2da_fresh196)
        c2da_mem[500 + 3 * 16 + 2 * 4] = uint8(c2da_fresh197)
        c2da_mem[500 + 3 * 16 + 2 * 4 + 1] = uint8(c2da_fresh197 >> 0x8)
        c2da_mem[500 + 3 * 16 + 2 * 4 + 2] = uint8(c2da_fresh197 >> 0x10)
        c2da_mem[500 + 3 * 16 + 2 * 4 + 3] = uint8(c2da_fresh197 >> 0x18)
        let c2da_fresh198 : int = 20
        let c2da_fresh199 : uint = uint(c2da_fresh198)
        c2da_mem[500 + 3 * 16 + 12] = uint8(c2da_fresh199)
        c2da_mem[500 + 3 * 16 + 13] = uint8(c2da_fresh199 >> 0x8)
        c2da_mem[500 + 3 * 16 + 14] = uint8(c2da_fresh199 >> 0x10)
        c2da_mem[500 + 3 * 16 + 15] = uint8(c2da_fresh199 >> 0x18)
    } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 524288) != 0) {
        let c2da_fresh200 : int = 100
        let c2da_fresh201 : uint = uint(c2da_fresh200)
        c2da_mem[500 + 3 * 16 + 0 * 4] = uint8(c2da_fresh201)
        c2da_mem[500 + 3 * 16 + 0 * 4 + 1] = uint8(c2da_fresh201 >> 0x8)
        c2da_mem[500 + 3 * 16 + 0 * 4 + 2] = uint8(c2da_fresh201 >> 0x10)
        c2da_mem[500 + 3 * 16 + 0 * 4 + 3] = uint8(c2da_fresh201 >> 0x18)
        let c2da_fresh202 : int = 100
        let c2da_fresh203 : uint = uint(c2da_fresh202)
        c2da_mem[500 + 3 * 16 + 1 * 4] = uint8(c2da_fresh203)
        c2da_mem[500 + 3 * 16 + 1 * 4 + 1] = uint8(c2da_fresh203 >> 0x8)
        c2da_mem[500 + 3 * 16 + 1 * 4 + 2] = uint8(c2da_fresh203 >> 0x10)
        c2da_mem[500 + 3 * 16 + 1 * 4 + 3] = uint8(c2da_fresh203 >> 0x18)
        let c2da_fresh204 : int = 100
        let c2da_fresh205 : uint = uint(c2da_fresh204)
        c2da_mem[500 + 3 * 16 + 2 * 4] = uint8(c2da_fresh205)
        c2da_mem[500 + 3 * 16 + 2 * 4 + 1] = uint8(c2da_fresh205 >> 0x8)
        c2da_mem[500 + 3 * 16 + 2 * 4 + 2] = uint8(c2da_fresh205 >> 0x10)
        c2da_mem[500 + 3 * 16 + 2 * 4 + 3] = uint8(c2da_fresh205 >> 0x18)
        let c2da_fresh206 : int = 100
        let c2da_fresh207 : uint = uint(c2da_fresh206)
        c2da_mem[500 + 3 * 16 + 12] = uint8(c2da_fresh207)
        c2da_mem[500 + 3 * 16 + 13] = uint8(c2da_fresh207 >> 0x8)
        c2da_mem[500 + 3 * 16 + 14] = uint8(c2da_fresh207 >> 0x10)
        c2da_mem[500 + 3 * 16 + 15] = uint8(c2da_fresh207 >> 0x18)
    } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 1048576) != 0) {
        let c2da_fresh208 : int = 255
        let c2da_fresh209 : uint = uint(c2da_fresh208)
        c2da_mem[500 + 3 * 16 + 0 * 4] = uint8(c2da_fresh209)
        c2da_mem[500 + 3 * 16 + 0 * 4 + 1] = uint8(c2da_fresh209 >> 0x8)
        c2da_mem[500 + 3 * 16 + 0 * 4 + 2] = uint8(c2da_fresh209 >> 0x10)
        c2da_mem[500 + 3 * 16 + 0 * 4 + 3] = uint8(c2da_fresh209 >> 0x18)
        let c2da_fresh210 : int = 255
        let c2da_fresh211 : uint = uint(c2da_fresh210)
        c2da_mem[500 + 3 * 16 + 1 * 4] = uint8(c2da_fresh211)
        c2da_mem[500 + 3 * 16 + 1 * 4 + 1] = uint8(c2da_fresh211 >> 0x8)
        c2da_mem[500 + 3 * 16 + 1 * 4 + 2] = uint8(c2da_fresh211 >> 0x10)
        c2da_mem[500 + 3 * 16 + 1 * 4 + 3] = uint8(c2da_fresh211 >> 0x18)
        let c2da_fresh212 : int = 0
        let c2da_fresh213 : uint = uint(c2da_fresh212)
        c2da_mem[500 + 3 * 16 + 2 * 4] = uint8(c2da_fresh213)
        c2da_mem[500 + 3 * 16 + 2 * 4 + 1] = uint8(c2da_fresh213 >> 0x8)
        c2da_mem[500 + 3 * 16 + 2 * 4 + 2] = uint8(c2da_fresh213 >> 0x10)
        c2da_mem[500 + 3 * 16 + 2 * 4 + 3] = uint8(c2da_fresh213 >> 0x18)
        let c2da_fresh214 : int = 30
        let c2da_fresh215 : uint = uint(c2da_fresh214)
        c2da_mem[500 + 3 * 16 + 12] = uint8(c2da_fresh215)
        c2da_mem[500 + 3 * 16 + 13] = uint8(c2da_fresh215 >> 0x8)
        c2da_mem[500 + 3 * 16 + 14] = uint8(c2da_fresh215 >> 0x10)
        c2da_mem[500 + 3 * 16 + 15] = uint8(c2da_fresh215 >> 0x18)
    } else {
        let c2da_fresh216 : int = 0
        let c2da_fresh217 : uint = uint(c2da_fresh216)
        c2da_mem[500 + 3 * 16 + 12] = uint8(c2da_fresh217)
        c2da_mem[500 + 3 * 16 + 13] = uint8(c2da_fresh217 >> 0x8)
        c2da_mem[500 + 3 * 16 + 14] = uint8(c2da_fresh217 >> 0x10)
        c2da_mem[500 + 3 * 16 + 15] = uint8(c2da_fresh217 >> 0x18)
    }
    return
}
[export, sideeffects]
def V_ParseDamage() {
    let c2da_saved_sp : int = c2da_lin_sp
    V_ParseDamage_c2da_frame(c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def V_SetContentsColor(var contents : int) {
    if (contents == -1 || contents == -2) {
        let c2da_fresh252 : uint = uint(cshift_empty.destcolor[0])
        c2da_mem[500 + 0 * 16] = uint8(c2da_fresh252)
        c2da_mem[500 + 0 * 16 + 1] = uint8(c2da_fresh252 >> 0x8)
        c2da_mem[500 + 0 * 16 + 2] = uint8(c2da_fresh252 >> 0x10)
        c2da_mem[500 + 0 * 16 + 3] = uint8(c2da_fresh252 >> 0x18)
        let c2da_fresh253 : uint = uint(cshift_empty.destcolor[1])
        c2da_mem[500 + 0 * 16 + 4] = uint8(c2da_fresh253)
        c2da_mem[500 + 0 * 16 + 5] = uint8(c2da_fresh253 >> 0x8)
        c2da_mem[500 + 0 * 16 + 6] = uint8(c2da_fresh253 >> 0x10)
        c2da_mem[500 + 0 * 16 + 7] = uint8(c2da_fresh253 >> 0x18)
        let c2da_fresh254 : uint = uint(cshift_empty.destcolor[2])
        c2da_mem[500 + 0 * 16 + 8] = uint8(c2da_fresh254)
        c2da_mem[500 + 0 * 16 + 9] = uint8(c2da_fresh254 >> 0x8)
        c2da_mem[500 + 0 * 16 + 10] = uint8(c2da_fresh254 >> 0x10)
        c2da_mem[500 + 0 * 16 + 11] = uint8(c2da_fresh254 >> 0x18)
        let c2da_fresh255 : uint = uint(cshift_empty.percent)
        c2da_mem[500 + 0 * 16 + 12] = uint8(c2da_fresh255)
        c2da_mem[500 + 0 * 16 + 13] = uint8(c2da_fresh255 >> 0x8)
        c2da_mem[500 + 0 * 16 + 14] = uint8(c2da_fresh255 >> 0x10)
        c2da_mem[500 + 0 * 16 + 15] = uint8(c2da_fresh255 >> 0x18)
    } elif (contents == -5) {
        let c2da_fresh256 : uint = uint(cshift_lava.destcolor[0])
        c2da_mem[500 + 0 * 16] = uint8(c2da_fresh256)
        c2da_mem[500 + 0 * 16 + 1] = uint8(c2da_fresh256 >> 0x8)
        c2da_mem[500 + 0 * 16 + 2] = uint8(c2da_fresh256 >> 0x10)
        c2da_mem[500 + 0 * 16 + 3] = uint8(c2da_fresh256 >> 0x18)
        let c2da_fresh257 : uint = uint(cshift_lava.destcolor[1])
        c2da_mem[500 + 0 * 16 + 4] = uint8(c2da_fresh257)
        c2da_mem[500 + 0 * 16 + 5] = uint8(c2da_fresh257 >> 0x8)
        c2da_mem[500 + 0 * 16 + 6] = uint8(c2da_fresh257 >> 0x10)
        c2da_mem[500 + 0 * 16 + 7] = uint8(c2da_fresh257 >> 0x18)
        let c2da_fresh258 : uint = uint(cshift_lava.destcolor[2])
        c2da_mem[500 + 0 * 16 + 8] = uint8(c2da_fresh258)
        c2da_mem[500 + 0 * 16 + 9] = uint8(c2da_fresh258 >> 0x8)
        c2da_mem[500 + 0 * 16 + 10] = uint8(c2da_fresh258 >> 0x10)
        c2da_mem[500 + 0 * 16 + 11] = uint8(c2da_fresh258 >> 0x18)
        let c2da_fresh259 : uint = uint(cshift_lava.percent)
        c2da_mem[500 + 0 * 16 + 12] = uint8(c2da_fresh259)
        c2da_mem[500 + 0 * 16 + 13] = uint8(c2da_fresh259 >> 0x8)
        c2da_mem[500 + 0 * 16 + 14] = uint8(c2da_fresh259 >> 0x10)
        c2da_mem[500 + 0 * 16 + 15] = uint8(c2da_fresh259 >> 0x18)
    } elif (contents == -4) {
        let c2da_fresh260 : uint = uint(cshift_slime.destcolor[0])
        c2da_mem[500 + 0 * 16] = uint8(c2da_fresh260)
        c2da_mem[500 + 0 * 16 + 1] = uint8(c2da_fresh260 >> 0x8)
        c2da_mem[500 + 0 * 16 + 2] = uint8(c2da_fresh260 >> 0x10)
        c2da_mem[500 + 0 * 16 + 3] = uint8(c2da_fresh260 >> 0x18)
        let c2da_fresh261 : uint = uint(cshift_slime.destcolor[1])
        c2da_mem[500 + 0 * 16 + 4] = uint8(c2da_fresh261)
        c2da_mem[500 + 0 * 16 + 5] = uint8(c2da_fresh261 >> 0x8)
        c2da_mem[500 + 0 * 16 + 6] = uint8(c2da_fresh261 >> 0x10)
        c2da_mem[500 + 0 * 16 + 7] = uint8(c2da_fresh261 >> 0x18)
        let c2da_fresh262 : uint = uint(cshift_slime.destcolor[2])
        c2da_mem[500 + 0 * 16 + 8] = uint8(c2da_fresh262)
        c2da_mem[500 + 0 * 16 + 9] = uint8(c2da_fresh262 >> 0x8)
        c2da_mem[500 + 0 * 16 + 10] = uint8(c2da_fresh262 >> 0x10)
        c2da_mem[500 + 0 * 16 + 11] = uint8(c2da_fresh262 >> 0x18)
        let c2da_fresh263 : uint = uint(cshift_slime.percent)
        c2da_mem[500 + 0 * 16 + 12] = uint8(c2da_fresh263)
        c2da_mem[500 + 0 * 16 + 13] = uint8(c2da_fresh263 >> 0x8)
        c2da_mem[500 + 0 * 16 + 14] = uint8(c2da_fresh263 >> 0x10)
        c2da_mem[500 + 0 * 16 + 15] = uint8(c2da_fresh263 >> 0x18)
    } else {
        let c2da_fresh264 : uint = uint(cshift_water.destcolor[0])
        c2da_mem[500 + 0 * 16] = uint8(c2da_fresh264)
        c2da_mem[500 + 0 * 16 + 1] = uint8(c2da_fresh264 >> 0x8)
        c2da_mem[500 + 0 * 16 + 2] = uint8(c2da_fresh264 >> 0x10)
        c2da_mem[500 + 0 * 16 + 3] = uint8(c2da_fresh264 >> 0x18)
        let c2da_fresh265 : uint = uint(cshift_water.destcolor[1])
        c2da_mem[500 + 0 * 16 + 4] = uint8(c2da_fresh265)
        c2da_mem[500 + 0 * 16 + 5] = uint8(c2da_fresh265 >> 0x8)
        c2da_mem[500 + 0 * 16 + 6] = uint8(c2da_fresh265 >> 0x10)
        c2da_mem[500 + 0 * 16 + 7] = uint8(c2da_fresh265 >> 0x18)
        let c2da_fresh266 : uint = uint(cshift_water.destcolor[2])
        c2da_mem[500 + 0 * 16 + 8] = uint8(c2da_fresh266)
        c2da_mem[500 + 0 * 16 + 9] = uint8(c2da_fresh266 >> 0x8)
        c2da_mem[500 + 0 * 16 + 10] = uint8(c2da_fresh266 >> 0x10)
        c2da_mem[500 + 0 * 16 + 11] = uint8(c2da_fresh266 >> 0x18)
        let c2da_fresh267 : uint = uint(cshift_water.percent)
        c2da_mem[500 + 0 * 16 + 12] = uint8(c2da_fresh267)
        c2da_mem[500 + 0 * 16 + 13] = uint8(c2da_fresh267 >> 0x8)
        c2da_mem[500 + 0 * 16 + 14] = uint8(c2da_fresh267 >> 0x10)
        c2da_mem[500 + 0 * 16 + 15] = uint8(c2da_fresh267 >> 0x18)
    }
    return
}
var cshift_water : cshift_t = cshift_t(destcolor = fixed_array<int>(130, 80, 50), percent = 128)

var cshift_slime : cshift_t = cshift_t(destcolor = fixed_array<int>(0, 25, 5), percent = 150)

var cshift_lava : cshift_t = cshift_t(destcolor = fixed_array<int>(255, 80, 0), percent = 150)

var cshift_empty : cshift_t = cshift_t(destcolor = fixed_array<int>(130, 80, 50), percent = 0)

[export, sideeffects]
def V_Init() {
    Cmd_AddCommand(737697, 220)
    Cmd_AddCommand(737706, 221)
    Cmd_AddCommand(737709, 222)
    Cvar_RegisterVariable(695792)
    Cvar_RegisterVariable(695840)
    Cvar_RegisterVariable(695888)
    Cvar_RegisterVariable(695936)
    Cvar_RegisterVariable(695984)
    Cvar_RegisterVariable(696032)
    Cvar_RegisterVariable(696080)
    Cvar_RegisterVariable(696128)
    Cvar_RegisterVariable(696176)
    Cvar_RegisterVariable(696224)
    Cvar_RegisterVariable(696272)
    Cvar_RegisterVariable(696320)
    Cvar_RegisterVariable(696368)
    Cvar_RegisterVariable(696416)
    Cvar_RegisterVariable(696464)
    Cvar_RegisterVariable(696512)
    Cvar_RegisterVariable(696560)
    Cvar_RegisterVariable(696608)
    Cvar_RegisterVariable(696656)
    Cvar_RegisterVariable(696704)
    Cvar_RegisterVariable(696752)
    Cvar_RegisterVariable(696800)
    Cvar_RegisterVariable(696848)
    Cvar_RegisterVariable(696896)
    Cvar_RegisterVariable(696944)
    Cvar_RegisterVariable(696992)
    BuildGammaTable(1.0)
    Cvar_RegisterVariable(697040)
    return
}
[export, sideeffects]
def V_BonusFlash_f() {
    let c2da_fresh268 : int = 215
    let c2da_fresh269 : uint = uint(c2da_fresh268)
    c2da_mem[500 + 2 * 16 + 0 * 4] = uint8(c2da_fresh269)
    c2da_mem[500 + 2 * 16 + 0 * 4 + 1] = uint8(c2da_fresh269 >> 0x8)
    c2da_mem[500 + 2 * 16 + 0 * 4 + 2] = uint8(c2da_fresh269 >> 0x10)
    c2da_mem[500 + 2 * 16 + 0 * 4 + 3] = uint8(c2da_fresh269 >> 0x18)
    let c2da_fresh270 : int = 186
    let c2da_fresh271 : uint = uint(c2da_fresh270)
    c2da_mem[500 + 2 * 16 + 1 * 4] = uint8(c2da_fresh271)
    c2da_mem[500 + 2 * 16 + 1 * 4 + 1] = uint8(c2da_fresh271 >> 0x8)
    c2da_mem[500 + 2 * 16 + 1 * 4 + 2] = uint8(c2da_fresh271 >> 0x10)
    c2da_mem[500 + 2 * 16 + 1 * 4 + 3] = uint8(c2da_fresh271 >> 0x18)
    let c2da_fresh272 : int = 69
    let c2da_fresh273 : uint = uint(c2da_fresh272)
    c2da_mem[500 + 2 * 16 + 2 * 4] = uint8(c2da_fresh273)
    c2da_mem[500 + 2 * 16 + 2 * 4 + 1] = uint8(c2da_fresh273 >> 0x8)
    c2da_mem[500 + 2 * 16 + 2 * 4 + 2] = uint8(c2da_fresh273 >> 0x10)
    c2da_mem[500 + 2 * 16 + 2 * 4 + 3] = uint8(c2da_fresh273 >> 0x18)
    let c2da_fresh274 : int = 50
    let c2da_fresh275 : uint = uint(c2da_fresh274)
    c2da_mem[500 + 2 * 16 + 12] = uint8(c2da_fresh275)
    c2da_mem[500 + 2 * 16 + 13] = uint8(c2da_fresh275 >> 0x8)
    c2da_mem[500 + 2 * 16 + 14] = uint8(c2da_fresh275 >> 0x10)
    c2da_mem[500 + 2 * 16 + 15] = uint8(c2da_fresh275 >> 0x18)
    return
}
[export, sideeffects]
def V_cshift_f() {
    cshift_empty.destcolor[0] = c2da_lin_atoi(int(Cmd_Argv(1)))
    cshift_empty.destcolor[1] = c2da_lin_atoi(int(Cmd_Argv(2)))
    cshift_empty.destcolor[2] = c2da_lin_atoi(int(Cmd_Argv(3)))
    cshift_empty.percent = c2da_lin_atoi(int(Cmd_Argv(4)))
    return
}
[sideeffects]
def private V_CalcRefdef_c2da_frame(c2da_fp : int) {
    var ent : int
    var view : int
    var i_0 : int
    var bob : float
    var steptime : float
    V_DriftPitch()
    ent = 10048 + int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18) * 200
    view = 4984
    let c2da_fresh22 : float = uint_bits_to_float(uint(c2da_mem[652 + 1 * 4]) | uint(c2da_mem[652 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh23 : uint = float_bits_to_uint(c2da_fresh22)
    c2da_mem[ent + 124 + 1 * 4] = uint8(c2da_fresh23)
    c2da_mem[ent + 124 + 1 * 4 + 1] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[ent + 124 + 1 * 4 + 2] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[ent + 124 + 1 * 4 + 3] = uint8(c2da_fresh23 >> 0x18)
    let c2da_fresh24 : float = -uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh25 : uint = float_bits_to_uint(c2da_fresh24)
    c2da_mem[ent + 124 + 0 * 4] = uint8(c2da_fresh25)
    c2da_mem[ent + 124 + 0 * 4 + 1] = uint8(c2da_fresh25 >> 0x8)
    c2da_mem[ent + 124 + 0 * 4 + 2] = uint8(c2da_fresh25 >> 0x10)
    c2da_mem[ent + 124 + 0 * 4 + 3] = uint8(c2da_fresh25 >> 0x18)
    bob = V_CalcBob()
    let c2da_fresh26 : float = uint_bits_to_float(uint(c2da_mem[ent + 88 + 0 * 4]) | uint(c2da_mem[ent + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh27 : uint = float_bits_to_uint(c2da_fresh26)
    c2da_mem[5320 + 0 * 4] = uint8(c2da_fresh27)
    c2da_mem[5320 + 0 * 4 + 1] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[5320 + 0 * 4 + 2] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[5320 + 0 * 4 + 3] = uint8(c2da_fresh27 >> 0x18)
    let c2da_fresh28 : float = uint_bits_to_float(uint(c2da_mem[ent + 88 + 1 * 4]) | uint(c2da_mem[ent + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh29 : uint = float_bits_to_uint(c2da_fresh28)
    c2da_mem[5320 + 1 * 4] = uint8(c2da_fresh29)
    c2da_mem[5320 + 1 * 4 + 1] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[5320 + 1 * 4 + 2] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[5320 + 1 * 4 + 3] = uint8(c2da_fresh29 >> 0x18)
    let c2da_fresh30 : float = uint_bits_to_float(uint(c2da_mem[ent + 88 + 2 * 4]) | uint(c2da_mem[ent + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh31 : uint = float_bits_to_uint(c2da_fresh30)
    c2da_mem[5320 + 2 * 4] = uint8(c2da_fresh31)
    c2da_mem[5320 + 2 * 4 + 1] = uint8(c2da_fresh31 >> 0x8)
    c2da_mem[5320 + 2 * 4 + 2] = uint8(c2da_fresh31 >> 0x10)
    c2da_mem[5320 + 2 * 4 + 3] = uint8(c2da_fresh31 >> 0x18)
    let c2da_fresh32 : float = uint_bits_to_float(uint(c2da_mem[5320 + 2 * 4]) | uint(c2da_mem[5320 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 2 * 4 + 3]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[736]) | uint(c2da_mem[737]) << 0x8 | uint(c2da_mem[738]) << 0x10 | uint(c2da_mem[739]) << 0x18) + bob)
    let c2da_fresh33 : uint = float_bits_to_uint(c2da_fresh32)
    c2da_mem[5320 + 2 * 4] = uint8(c2da_fresh33)
    c2da_mem[5320 + 2 * 4 + 1] = uint8(c2da_fresh33 >> 0x8)
    c2da_mem[5320 + 2 * 4 + 2] = uint8(c2da_fresh33 >> 0x10)
    c2da_mem[5320 + 2 * 4 + 3] = uint8(c2da_fresh33 >> 0x18)
    let c2da_fresh34 : float = float(double(uint_bits_to_float(uint(c2da_mem[5320 + 0 * 4]) | uint(c2da_mem[5320 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 0 * 4 + 3]) << 0x18)) + 1.0lf / 32.0lf)
    let c2da_fresh35 : uint = float_bits_to_uint(c2da_fresh34)
    c2da_mem[5320 + 0 * 4] = uint8(c2da_fresh35)
    c2da_mem[5320 + 0 * 4 + 1] = uint8(c2da_fresh35 >> 0x8)
    c2da_mem[5320 + 0 * 4 + 2] = uint8(c2da_fresh35 >> 0x10)
    c2da_mem[5320 + 0 * 4 + 3] = uint8(c2da_fresh35 >> 0x18)
    let c2da_fresh36 : float = float(double(uint_bits_to_float(uint(c2da_mem[5320 + 1 * 4]) | uint(c2da_mem[5320 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 1 * 4 + 3]) << 0x18)) + 1.0lf / 32.0lf)
    let c2da_fresh37 : uint = float_bits_to_uint(c2da_fresh36)
    c2da_mem[5320 + 1 * 4] = uint8(c2da_fresh37)
    c2da_mem[5320 + 1 * 4 + 1] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[5320 + 1 * 4 + 2] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[5320 + 1 * 4 + 3] = uint8(c2da_fresh37 >> 0x18)
    let c2da_fresh38 : float = float(double(uint_bits_to_float(uint(c2da_mem[5320 + 2 * 4]) | uint(c2da_mem[5320 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 2 * 4 + 3]) << 0x18)) + 1.0lf / 32.0lf)
    let c2da_fresh39 : uint = float_bits_to_uint(c2da_fresh38)
    c2da_mem[5320 + 2 * 4] = uint8(c2da_fresh39)
    c2da_mem[5320 + 2 * 4 + 1] = uint8(c2da_fresh39 >> 0x8)
    c2da_mem[5320 + 2 * 4 + 2] = uint8(c2da_fresh39 >> 0x10)
    c2da_mem[5320 + 2 * 4 + 3] = uint8(c2da_fresh39 >> 0x18)
    let c2da_fresh40 : float = uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh41 : uint = float_bits_to_uint(c2da_fresh40)
    c2da_mem[5332 + 0 * 4] = uint8(c2da_fresh41)
    c2da_mem[5332 + 0 * 4 + 1] = uint8(c2da_fresh41 >> 0x8)
    c2da_mem[5332 + 0 * 4 + 2] = uint8(c2da_fresh41 >> 0x10)
    c2da_mem[5332 + 0 * 4 + 3] = uint8(c2da_fresh41 >> 0x18)
    let c2da_fresh42 : float = uint_bits_to_float(uint(c2da_mem[652 + 1 * 4]) | uint(c2da_mem[652 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh43 : uint = float_bits_to_uint(c2da_fresh42)
    c2da_mem[5332 + 1 * 4] = uint8(c2da_fresh43)
    c2da_mem[5332 + 1 * 4 + 1] = uint8(c2da_fresh43 >> 0x8)
    c2da_mem[5332 + 1 * 4 + 2] = uint8(c2da_fresh43 >> 0x10)
    c2da_mem[5332 + 1 * 4 + 3] = uint8(c2da_fresh43 >> 0x18)
    let c2da_fresh44 : float = uint_bits_to_float(uint(c2da_mem[652 + 2 * 4]) | uint(c2da_mem[652 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh45 : uint = float_bits_to_uint(c2da_fresh44)
    c2da_mem[5332 + 2 * 4] = uint8(c2da_fresh45)
    c2da_mem[5332 + 2 * 4 + 1] = uint8(c2da_fresh45 >> 0x8)
    c2da_mem[5332 + 2 * 4 + 2] = uint8(c2da_fresh45 >> 0x10)
    c2da_mem[5332 + 2 * 4 + 3] = uint8(c2da_fresh45 >> 0x18)
    V_CalcViewRoll()
    V_AddIdle()
    let c2da_fresh46 : float = -uint_bits_to_float(uint(c2da_mem[ent + 124 + 0 * 4]) | uint(c2da_mem[ent + 124 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 124 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 124 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh47 : uint = float_bits_to_uint(c2da_fresh46)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh47)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh47 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh47 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh47 >> 0x18)
    let c2da_fresh48 : float = uint_bits_to_float(uint(c2da_mem[ent + 124 + 1 * 4]) | uint(c2da_mem[ent + 124 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 124 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 124 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh49 : uint = float_bits_to_uint(c2da_fresh48)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh49)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh49 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh49 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh49 >> 0x18)
    let c2da_fresh50 : float = uint_bits_to_float(uint(c2da_mem[ent + 124 + 2 * 4]) | uint(c2da_mem[ent + 124 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 124 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 124 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh51 : uint = float_bits_to_uint(c2da_fresh50)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh51)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh51 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh51 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh51 >> 0x18)
    AngleVectors(c2da_fp, c2da_fp + 16, c2da_fp + 32, c2da_fp + 48)
    i_0 = 0
    while (i_0 < 3) {
        let c2da_fresh52 : float = uint_bits_to_float(uint(c2da_mem[5320 + i_0 * 4]) | uint(c2da_mem[5320 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + i_0 * 4 + 3]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[696536]) | uint(c2da_mem[696537]) << 0x8 | uint(c2da_mem[696538]) << 0x10 | uint(c2da_mem[696539]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + i_0 * 4]) | uint(c2da_mem[c2da_fp + 16 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + i_0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[696584]) | uint(c2da_mem[696585]) << 0x8 | uint(c2da_mem[696586]) << 0x10 | uint(c2da_mem[696587]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + i_0 * 4]) | uint(c2da_mem[c2da_fp + 32 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + i_0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[696632]) | uint(c2da_mem[696633]) << 0x8 | uint(c2da_mem[696634]) << 0x10 | uint(c2da_mem[696635]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + i_0 * 4]) | uint(c2da_mem[c2da_fp + 48 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + i_0 * 4 + 3]) << 0x18))
        let c2da_fresh53 : uint = float_bits_to_uint(c2da_fresh52)
        c2da_mem[5320 + i_0 * 4] = uint8(c2da_fresh53)
        c2da_mem[5320 + i_0 * 4 + 1] = uint8(c2da_fresh53 >> 0x8)
        c2da_mem[5320 + i_0 * 4 + 2] = uint8(c2da_fresh53 >> 0x10)
        c2da_mem[5320 + i_0 * 4 + 3] = uint8(c2da_fresh53 >> 0x18)
        i_0++
    }
    V_BoundOffsets()
    let c2da_fresh54 : float = uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh55 : uint = float_bits_to_uint(c2da_fresh54)
    c2da_mem[view + 124 + 0 * 4] = uint8(c2da_fresh55)
    c2da_mem[view + 124 + 0 * 4 + 1] = uint8(c2da_fresh55 >> 0x8)
    c2da_mem[view + 124 + 0 * 4 + 2] = uint8(c2da_fresh55 >> 0x10)
    c2da_mem[view + 124 + 0 * 4 + 3] = uint8(c2da_fresh55 >> 0x18)
    let c2da_fresh56 : float = uint_bits_to_float(uint(c2da_mem[652 + 1 * 4]) | uint(c2da_mem[652 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh57 : uint = float_bits_to_uint(c2da_fresh56)
    c2da_mem[view + 124 + 1 * 4] = uint8(c2da_fresh57)
    c2da_mem[view + 124 + 1 * 4 + 1] = uint8(c2da_fresh57 >> 0x8)
    c2da_mem[view + 124 + 1 * 4 + 2] = uint8(c2da_fresh57 >> 0x10)
    c2da_mem[view + 124 + 1 * 4 + 3] = uint8(c2da_fresh57 >> 0x18)
    let c2da_fresh58 : float = uint_bits_to_float(uint(c2da_mem[652 + 2 * 4]) | uint(c2da_mem[652 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh59 : uint = float_bits_to_uint(c2da_fresh58)
    c2da_mem[view + 124 + 2 * 4] = uint8(c2da_fresh59)
    c2da_mem[view + 124 + 2 * 4 + 1] = uint8(c2da_fresh59 >> 0x8)
    c2da_mem[view + 124 + 2 * 4 + 2] = uint8(c2da_fresh59 >> 0x10)
    c2da_mem[view + 124 + 2 * 4 + 3] = uint8(c2da_fresh59 >> 0x18)
    CalcGunAngle()
    let c2da_fresh60 : float = uint_bits_to_float(uint(c2da_mem[ent + 88 + 0 * 4]) | uint(c2da_mem[ent + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh61 : uint = float_bits_to_uint(c2da_fresh60)
    c2da_mem[view + 88 + 0 * 4] = uint8(c2da_fresh61)
    c2da_mem[view + 88 + 0 * 4 + 1] = uint8(c2da_fresh61 >> 0x8)
    c2da_mem[view + 88 + 0 * 4 + 2] = uint8(c2da_fresh61 >> 0x10)
    c2da_mem[view + 88 + 0 * 4 + 3] = uint8(c2da_fresh61 >> 0x18)
    let c2da_fresh62 : float = uint_bits_to_float(uint(c2da_mem[ent + 88 + 1 * 4]) | uint(c2da_mem[ent + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh63 : uint = float_bits_to_uint(c2da_fresh62)
    c2da_mem[view + 88 + 1 * 4] = uint8(c2da_fresh63)
    c2da_mem[view + 88 + 1 * 4 + 1] = uint8(c2da_fresh63 >> 0x8)
    c2da_mem[view + 88 + 1 * 4 + 2] = uint8(c2da_fresh63 >> 0x10)
    c2da_mem[view + 88 + 1 * 4 + 3] = uint8(c2da_fresh63 >> 0x18)
    let c2da_fresh64 : float = uint_bits_to_float(uint(c2da_mem[ent + 88 + 2 * 4]) | uint(c2da_mem[ent + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh65 : uint = float_bits_to_uint(c2da_fresh64)
    c2da_mem[view + 88 + 2 * 4] = uint8(c2da_fresh65)
    c2da_mem[view + 88 + 2 * 4 + 1] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[view + 88 + 2 * 4 + 2] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[view + 88 + 2 * 4 + 3] = uint8(c2da_fresh65 >> 0x18)
    let c2da_fresh66 : float = uint_bits_to_float(uint(c2da_mem[view + 88 + 2 * 4]) | uint(c2da_mem[view + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[view + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[view + 88 + 2 * 4 + 3]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[736]) | uint(c2da_mem[737]) << 0x8 | uint(c2da_mem[738]) << 0x10 | uint(c2da_mem[739]) << 0x18))
    let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
    c2da_mem[view + 88 + 2 * 4] = uint8(c2da_fresh67)
    c2da_mem[view + 88 + 2 * 4 + 1] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[view + 88 + 2 * 4 + 2] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[view + 88 + 2 * 4 + 3] = uint8(c2da_fresh67 >> 0x18)
    i_0 = 0
    for (c2da_i_0 in range(i_0, 3)) {
        let c2da_fresh68 : float = float(double(uint_bits_to_float(uint(c2da_mem[view + 88 + c2da_i_0 * 4]) | uint(c2da_mem[view + 88 + c2da_i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[view + 88 + c2da_i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[view + 88 + c2da_i_0 * 4 + 3]) << 0x18)) + double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + c2da_i_0 * 4]) | uint(c2da_mem[c2da_fp + 16 + c2da_i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + c2da_i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + c2da_i_0 * 4 + 3]) << 0x18) * bob) * 0.4lf)
        let c2da_fresh69 : uint = float_bits_to_uint(c2da_fresh68)
        c2da_mem[view + 88 + c2da_i_0 * 4] = uint8(c2da_fresh69)
        c2da_mem[view + 88 + c2da_i_0 * 4 + 1] = uint8(c2da_fresh69 >> 0x8)
        c2da_mem[view + 88 + c2da_i_0 * 4 + 2] = uint8(c2da_fresh69 >> 0x10)
        c2da_mem[view + 88 + c2da_i_0 * 4 + 3] = uint8(c2da_fresh69 >> 0x18)
    }
    let c2da_fresh70 : float = uint_bits_to_float(uint(c2da_mem[view + 88 + 2 * 4]) | uint(c2da_mem[view + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[view + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[view + 88 + 2 * 4 + 3]) << 0x18) + bob
    let c2da_fresh71 : uint = float_bits_to_uint(c2da_fresh70)
    c2da_mem[view + 88 + 2 * 4] = uint8(c2da_fresh71)
    c2da_mem[view + 88 + 2 * 4 + 1] = uint8(c2da_fresh71 >> 0x8)
    c2da_mem[view + 88 + 2 * 4 + 2] = uint8(c2da_fresh71 >> 0x10)
    c2da_mem[view + 88 + 2 * 4 + 3] = uint8(c2da_fresh71 >> 0x18)
    if (uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18) == 110.0) {
        let c2da_fresh72 : float = uint_bits_to_float(uint(c2da_mem[view + 88 + 2 * 4]) | uint(c2da_mem[view + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[view + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[view + 88 + 2 * 4 + 3]) << 0x18) + 1.0
        let c2da_fresh73 : uint = float_bits_to_uint(c2da_fresh72)
        c2da_mem[view + 88 + 2 * 4] = uint8(c2da_fresh73)
        c2da_mem[view + 88 + 2 * 4 + 1] = uint8(c2da_fresh73 >> 0x8)
        c2da_mem[view + 88 + 2 * 4 + 2] = uint8(c2da_fresh73 >> 0x10)
        c2da_mem[view + 88 + 2 * 4 + 3] = uint8(c2da_fresh73 >> 0x18)
    } elif (uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18) == 100.0) {
        let c2da_fresh74 : float = uint_bits_to_float(uint(c2da_mem[view + 88 + 2 * 4]) | uint(c2da_mem[view + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[view + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[view + 88 + 2 * 4 + 3]) << 0x18) + 2.0
        let c2da_fresh75 : uint = float_bits_to_uint(c2da_fresh74)
        c2da_mem[view + 88 + 2 * 4] = uint8(c2da_fresh75)
        c2da_mem[view + 88 + 2 * 4 + 1] = uint8(c2da_fresh75 >> 0x8)
        c2da_mem[view + 88 + 2 * 4 + 2] = uint8(c2da_fresh75 >> 0x10)
        c2da_mem[view + 88 + 2 * 4 + 3] = uint8(c2da_fresh75 >> 0x18)
    } elif (uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18) == 90.0) {
        let c2da_fresh76 : float = uint_bits_to_float(uint(c2da_mem[view + 88 + 2 * 4]) | uint(c2da_mem[view + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[view + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[view + 88 + 2 * 4 + 3]) << 0x18) + 1.0
        let c2da_fresh77 : uint = float_bits_to_uint(c2da_fresh76)
        c2da_mem[view + 88 + 2 * 4] = uint8(c2da_fresh77)
        c2da_mem[view + 88 + 2 * 4 + 1] = uint8(c2da_fresh77 >> 0x8)
        c2da_mem[view + 88 + 2 * 4 + 2] = uint8(c2da_fresh77 >> 0x10)
        c2da_mem[view + 88 + 2 * 4 + 3] = uint8(c2da_fresh77 >> 0x18)
    } elif (uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18) == 80.0) {
        let c2da_fresh78 : float = float(double(uint_bits_to_float(uint(c2da_mem[view + 88 + 2 * 4]) | uint(c2da_mem[view + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[view + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[view + 88 + 2 * 4 + 3]) << 0x18)) + 0.5lf)
        let c2da_fresh79 : uint = float_bits_to_uint(c2da_fresh78)
        c2da_mem[view + 88 + 2 * 4] = uint8(c2da_fresh79)
        c2da_mem[view + 88 + 2 * 4 + 1] = uint8(c2da_fresh79 >> 0x8)
        c2da_mem[view + 88 + 2 * 4 + 2] = uint8(c2da_fresh79 >> 0x10)
        c2da_mem[view + 88 + 2 * 4 + 3] = uint8(c2da_fresh79 >> 0x18)
    }
    let c2da_fresh80 : int = 808 + int(uint(c2da_mem[236 + 2 * 4]) | uint(c2da_mem[236 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 2 * 4 + 3]) << 0x18) * 8
    let c2da_fresh81 : int = int(uint(c2da_mem[c2da_fresh80]) | uint(c2da_mem[c2da_fresh80 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh80 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh80 + 3]) << 0x18)
    let c2da_fresh82 : uint = uint(c2da_fresh81)
    c2da_mem[view + 136] = uint8(c2da_fresh82)
    c2da_mem[view + 137] = uint8(c2da_fresh82 >> 0x8)
    c2da_mem[view + 138] = uint8(c2da_fresh82 >> 0x10)
    c2da_mem[view + 139] = uint8(c2da_fresh82 >> 0x18)
    c2da_mem[view + 140] = 0u8
    c2da_mem[view + 141] = 0u8
    c2da_mem[view + 142] = 0u8
    c2da_mem[view + 143] = 0u8
    let c2da_fresh83 : int = int(uint(c2da_mem[236 + 5 * 4]) | uint(c2da_mem[236 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 5 * 4 + 3]) << 0x18)
    let c2da_fresh84 : uint = uint(c2da_fresh83)
    c2da_mem[view + 152] = uint8(c2da_fresh84)
    c2da_mem[view + 153] = uint8(c2da_fresh84 >> 0x8)
    c2da_mem[view + 154] = uint8(c2da_fresh84 >> 0x10)
    c2da_mem[view + 155] = uint8(c2da_fresh84 >> 0x18)
    let c2da_fresh85 : int = vid.colormap
    let c2da_fresh86 : uint = uint(c2da_fresh85)
    c2da_mem[view + 160] = uint8(c2da_fresh86)
    c2da_mem[view + 161] = uint8(c2da_fresh86 >> 0x8)
    c2da_mem[view + 162] = uint8(c2da_fresh86 >> 0x10)
    c2da_mem[view + 163] = uint8(c2da_fresh86 >> 0x18)
    c2da_mem[view + 164] = 0u8
    c2da_mem[view + 165] = 0u8
    c2da_mem[view + 166] = 0u8
    c2da_mem[view + 167] = 0u8
    let c2da_fresh87 : float = uint_bits_to_float(uint(c2da_mem[5332 + 0 * 4]) | uint(c2da_mem[5332 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[700 + 0 * 4]) | uint(c2da_mem[700 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[700 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[700 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh88 : uint = float_bits_to_uint(c2da_fresh87)
    c2da_mem[5332 + 0 * 4] = uint8(c2da_fresh88)
    c2da_mem[5332 + 0 * 4 + 1] = uint8(c2da_fresh88 >> 0x8)
    c2da_mem[5332 + 0 * 4 + 2] = uint8(c2da_fresh88 >> 0x10)
    c2da_mem[5332 + 0 * 4 + 3] = uint8(c2da_fresh88 >> 0x18)
    let c2da_fresh89 : float = uint_bits_to_float(uint(c2da_mem[5332 + 1 * 4]) | uint(c2da_mem[5332 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[700 + 1 * 4]) | uint(c2da_mem[700 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[700 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[700 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh90 : uint = float_bits_to_uint(c2da_fresh89)
    c2da_mem[5332 + 1 * 4] = uint8(c2da_fresh90)
    c2da_mem[5332 + 1 * 4 + 1] = uint8(c2da_fresh90 >> 0x8)
    c2da_mem[5332 + 1 * 4 + 2] = uint8(c2da_fresh90 >> 0x10)
    c2da_mem[5332 + 1 * 4 + 3] = uint8(c2da_fresh90 >> 0x18)
    let c2da_fresh91 : float = uint_bits_to_float(uint(c2da_mem[5332 + 2 * 4]) | uint(c2da_mem[5332 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[700 + 2 * 4]) | uint(c2da_mem[700 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[700 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[700 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh92 : uint = float_bits_to_uint(c2da_fresh91)
    c2da_mem[5332 + 2 * 4] = uint8(c2da_fresh92)
    c2da_mem[5332 + 2 * 4 + 1] = uint8(c2da_fresh92 >> 0x8)
    c2da_mem[5332 + 2 * 4 + 2] = uint8(c2da_fresh92 >> 0x10)
    c2da_mem[5332 + 2 * 4 + 3] = uint8(c2da_fresh92 >> 0x18)
    if ((uint(c2da_mem[748]) | uint(c2da_mem[749]) << 0x8 | uint(c2da_mem[750]) << 0x10 | uint(c2da_mem[751]) << 0x18) != 0x0 && uint_bits_to_float(uint(c2da_mem[ent + 88 + 2 * 4]) | uint(c2da_mem[ent + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 2 * 4 + 3]) << 0x18) - V_CalcRefdef__oldz > 0.0) {
        steptime = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - uint64_bits_to_double(uint64(uint(c2da_mem[792]) | uint(c2da_mem[793]) << 0x8 | uint(c2da_mem[794]) << 0x10 | uint(c2da_mem[795]) << 0x18) | uint64(uint(c2da_mem[796]) | uint(c2da_mem[797]) << 0x8 | uint(c2da_mem[798]) << 0x10 | uint(c2da_mem[799]) << 0x18) << 0x20))
        if (steptime < 0.0) {
            steptime = 0.0
        }
        V_CalcRefdef__oldz += steptime * 80.0
        if (V_CalcRefdef__oldz > uint_bits_to_float(uint(c2da_mem[ent + 88 + 2 * 4]) | uint(c2da_mem[ent + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 2 * 4 + 3]) << 0x18)) {
            V_CalcRefdef__oldz = uint_bits_to_float(uint(c2da_mem[ent + 88 + 2 * 4]) | uint(c2da_mem[ent + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 2 * 4 + 3]) << 0x18)
        }
        if (uint_bits_to_float(uint(c2da_mem[ent + 88 + 2 * 4]) | uint(c2da_mem[ent + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 2 * 4 + 3]) << 0x18) - V_CalcRefdef__oldz > 12.0) {
            V_CalcRefdef__oldz = uint_bits_to_float(uint(c2da_mem[ent + 88 + 2 * 4]) | uint(c2da_mem[ent + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 2 * 4 + 3]) << 0x18) - 12.0
        }
        let c2da_fresh93 : float = uint_bits_to_float(uint(c2da_mem[5320 + 2 * 4]) | uint(c2da_mem[5320 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 2 * 4 + 3]) << 0x18) + float(V_CalcRefdef__oldz - uint_bits_to_float(uint(c2da_mem[ent + 88 + 2 * 4]) | uint(c2da_mem[ent + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 2 * 4 + 3]) << 0x18))
        let c2da_fresh94 : uint = float_bits_to_uint(c2da_fresh93)
        c2da_mem[5320 + 2 * 4] = uint8(c2da_fresh94)
        c2da_mem[5320 + 2 * 4 + 1] = uint8(c2da_fresh94 >> 0x8)
        c2da_mem[5320 + 2 * 4 + 2] = uint8(c2da_fresh94 >> 0x10)
        c2da_mem[5320 + 2 * 4 + 3] = uint8(c2da_fresh94 >> 0x18)
        let c2da_fresh95 : float = uint_bits_to_float(uint(c2da_mem[view + 88 + 2 * 4]) | uint(c2da_mem[view + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[view + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[view + 88 + 2 * 4 + 3]) << 0x18) + float(V_CalcRefdef__oldz - uint_bits_to_float(uint(c2da_mem[ent + 88 + 2 * 4]) | uint(c2da_mem[ent + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 2 * 4 + 3]) << 0x18))
        let c2da_fresh96 : uint = float_bits_to_uint(c2da_fresh95)
        c2da_mem[view + 88 + 2 * 4] = uint8(c2da_fresh96)
        c2da_mem[view + 88 + 2 * 4 + 1] = uint8(c2da_fresh96 >> 0x8)
        c2da_mem[view + 88 + 2 * 4 + 2] = uint8(c2da_fresh96 >> 0x10)
        c2da_mem[view + 88 + 2 * 4 + 3] = uint8(c2da_fresh96 >> 0x18)
    } else {
        V_CalcRefdef__oldz = uint_bits_to_float(uint(c2da_mem[ent + 88 + 2 * 4]) | uint(c2da_mem[ent + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 2 * 4 + 3]) << 0x18)
    }
    if (uint_bits_to_float(uint(c2da_mem[184]) | uint(c2da_mem[185]) << 0x8 | uint(c2da_mem[186]) << 0x10 | uint(c2da_mem[187]) << 0x18) != 0.0) {
        Chase_Update()
    }
    return
}
[sideeffects]
def private V_UpdatePalette_c2da_frame(c2da_fp : int) {
    var i_1 : int
    var j : int
    var new_0 : uint
    var basepal : int
    var newpal : int
    var r : int
    var g : int
    var b : int
    var force : uint
    V_CalcPowerupCshift()
    new_0 = 0u
    i_1 = 0
    while (i_1 < 4) {
        if (int(uint(c2da_mem[500 + i_1 * 16 + 12]) | uint(c2da_mem[500 + i_1 * 16 + 13]) << 0x8 | uint(c2da_mem[500 + i_1 * 16 + 14]) << 0x10 | uint(c2da_mem[500 + i_1 * 16 + 15]) << 0x18) != int(uint(c2da_mem[564 + i_1 * 16 + 12]) | uint(c2da_mem[564 + i_1 * 16 + 13]) << 0x8 | uint(c2da_mem[564 + i_1 * 16 + 14]) << 0x10 | uint(c2da_mem[564 + i_1 * 16 + 15]) << 0x18)) {
            new_0 = 1u
            let c2da_fresh169 : int = int(uint(c2da_mem[500 + i_1 * 16 + 12]) | uint(c2da_mem[500 + i_1 * 16 + 13]) << 0x8 | uint(c2da_mem[500 + i_1 * 16 + 14]) << 0x10 | uint(c2da_mem[500 + i_1 * 16 + 15]) << 0x18)
            let c2da_fresh170 : uint = uint(c2da_fresh169)
            c2da_mem[564 + i_1 * 16 + 12] = uint8(c2da_fresh170)
            c2da_mem[564 + i_1 * 16 + 13] = uint8(c2da_fresh170 >> 0x8)
            c2da_mem[564 + i_1 * 16 + 14] = uint8(c2da_fresh170 >> 0x10)
            c2da_mem[564 + i_1 * 16 + 15] = uint8(c2da_fresh170 >> 0x18)
        }
        j = 0
        while (j < 3) {
            if (int(uint(c2da_mem[500 + i_1 * 16 + j * 4]) | uint(c2da_mem[500 + i_1 * 16 + j * 4 + 1]) << 0x8 | uint(c2da_mem[500 + i_1 * 16 + j * 4 + 2]) << 0x10 | uint(c2da_mem[500 + i_1 * 16 + j * 4 + 3]) << 0x18) != int(uint(c2da_mem[564 + i_1 * 16 + j * 4]) | uint(c2da_mem[564 + i_1 * 16 + j * 4 + 1]) << 0x8 | uint(c2da_mem[564 + i_1 * 16 + j * 4 + 2]) << 0x10 | uint(c2da_mem[564 + i_1 * 16 + j * 4 + 3]) << 0x18)) {
                new_0 = 1u
                let c2da_fresh171 : int = int(uint(c2da_mem[500 + i_1 * 16 + j * 4]) | uint(c2da_mem[500 + i_1 * 16 + j * 4 + 1]) << 0x8 | uint(c2da_mem[500 + i_1 * 16 + j * 4 + 2]) << 0x10 | uint(c2da_mem[500 + i_1 * 16 + j * 4 + 3]) << 0x18)
                let c2da_fresh172 : uint = uint(c2da_fresh171)
                c2da_mem[564 + i_1 * 16 + j * 4] = uint8(c2da_fresh172)
                c2da_mem[564 + i_1 * 16 + j * 4 + 1] = uint8(c2da_fresh172 >> 0x8)
                c2da_mem[564 + i_1 * 16 + j * 4 + 2] = uint8(c2da_fresh172 >> 0x10)
                c2da_mem[564 + i_1 * 16 + j * 4 + 3] = uint8(c2da_fresh172 >> 0x18)
            }
            j++
        }
        i_1++
    }
    let c2da_fresh173 : int = int(double(int(uint(c2da_mem[500 + 1 * 16 + 12]) | uint(c2da_mem[500 + 1 * 16 + 13]) << 0x8 | uint(c2da_mem[500 + 1 * 16 + 14]) << 0x10 | uint(c2da_mem[500 + 1 * 16 + 15]) << 0x18)) - double(host_frametime * 150.0lf))
    let c2da_fresh174 : uint = uint(c2da_fresh173)
    c2da_mem[500 + 1 * 16 + 12] = uint8(c2da_fresh174)
    c2da_mem[500 + 1 * 16 + 13] = uint8(c2da_fresh174 >> 0x8)
    c2da_mem[500 + 1 * 16 + 14] = uint8(c2da_fresh174 >> 0x10)
    c2da_mem[500 + 1 * 16 + 15] = uint8(c2da_fresh174 >> 0x18)
    if (int(uint(c2da_mem[500 + 1 * 16 + 12]) | uint(c2da_mem[500 + 1 * 16 + 13]) << 0x8 | uint(c2da_mem[500 + 1 * 16 + 14]) << 0x10 | uint(c2da_mem[500 + 1 * 16 + 15]) << 0x18) <= 0) {
        let c2da_fresh175 : int = 0
        let c2da_fresh176 : uint = uint(c2da_fresh175)
        c2da_mem[500 + 1 * 16 + 12] = uint8(c2da_fresh176)
        c2da_mem[500 + 1 * 16 + 13] = uint8(c2da_fresh176 >> 0x8)
        c2da_mem[500 + 1 * 16 + 14] = uint8(c2da_fresh176 >> 0x10)
        c2da_mem[500 + 1 * 16 + 15] = uint8(c2da_fresh176 >> 0x18)
    }
    let c2da_fresh177 : int = int(double(int(uint(c2da_mem[500 + 2 * 16 + 12]) | uint(c2da_mem[500 + 2 * 16 + 13]) << 0x8 | uint(c2da_mem[500 + 2 * 16 + 14]) << 0x10 | uint(c2da_mem[500 + 2 * 16 + 15]) << 0x18)) - double(host_frametime * 100.0lf))
    let c2da_fresh178 : uint = uint(c2da_fresh177)
    c2da_mem[500 + 2 * 16 + 12] = uint8(c2da_fresh178)
    c2da_mem[500 + 2 * 16 + 13] = uint8(c2da_fresh178 >> 0x8)
    c2da_mem[500 + 2 * 16 + 14] = uint8(c2da_fresh178 >> 0x10)
    c2da_mem[500 + 2 * 16 + 15] = uint8(c2da_fresh178 >> 0x18)
    if (int(uint(c2da_mem[500 + 2 * 16 + 12]) | uint(c2da_mem[500 + 2 * 16 + 13]) << 0x8 | uint(c2da_mem[500 + 2 * 16 + 14]) << 0x10 | uint(c2da_mem[500 + 2 * 16 + 15]) << 0x18) <= 0) {
        let c2da_fresh179 : int = 0
        let c2da_fresh180 : uint = uint(c2da_fresh179)
        c2da_mem[500 + 2 * 16 + 12] = uint8(c2da_fresh180)
        c2da_mem[500 + 2 * 16 + 13] = uint8(c2da_fresh180 >> 0x8)
        c2da_mem[500 + 2 * 16 + 14] = uint8(c2da_fresh180 >> 0x10)
        c2da_mem[500 + 2 * 16 + 15] = uint8(c2da_fresh180 >> 0x18)
    }
    force = V_CheckGamma()
    if (new_0 == 0u && force == 0u) {
        return
    }
    basepal = host_basepal
    newpal = c2da_fp
    i_1 = 0
    for (c2da_i_1 in range(i_1, 256)) {
        r = int(c2da_mem[basepal + 0])
        g = int(c2da_mem[basepal + 1])
        b = int(c2da_mem[basepal + 2])
        basepal += 3
        j = 0
        while (j < 4) {
            r += int(uint(c2da_mem[500 + j * 16 + 12]) | uint(c2da_mem[500 + j * 16 + 13]) << 0x8 | uint(c2da_mem[500 + j * 16 + 14]) << 0x10 | uint(c2da_mem[500 + j * 16 + 15]) << 0x18) * (int(uint(c2da_mem[500 + j * 16 + 0 * 4]) | uint(c2da_mem[500 + j * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[500 + j * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[500 + j * 16 + 0 * 4 + 3]) << 0x18) - r) >> 8
            g += int(uint(c2da_mem[500 + j * 16 + 12]) | uint(c2da_mem[500 + j * 16 + 13]) << 0x8 | uint(c2da_mem[500 + j * 16 + 14]) << 0x10 | uint(c2da_mem[500 + j * 16 + 15]) << 0x18) * (int(uint(c2da_mem[500 + j * 16 + 1 * 4]) | uint(c2da_mem[500 + j * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[500 + j * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[500 + j * 16 + 1 * 4 + 3]) << 0x18) - g) >> 8
            b += int(uint(c2da_mem[500 + j * 16 + 12]) | uint(c2da_mem[500 + j * 16 + 13]) << 0x8 | uint(c2da_mem[500 + j * 16 + 14]) << 0x10 | uint(c2da_mem[500 + j * 16 + 15]) << 0x18) * (int(uint(c2da_mem[500 + j * 16 + 2 * 4]) | uint(c2da_mem[500 + j * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[500 + j * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[500 + j * 16 + 2 * 4 + 3]) << 0x18) - b) >> 8
            j++
        }
        let c2da_fresh181 : uint8 = gammatable[r]
        c2da_mem[newpal + 0] = c2da_fresh181
        let c2da_fresh182 : uint8 = gammatable[g]
        c2da_mem[newpal + 1] = c2da_fresh182
        let c2da_fresh183 : uint8 = gammatable[b]
        c2da_mem[newpal + 2] = c2da_fresh183
        newpal += 3
    }
    VID_ShiftPalette(c2da_fp)
    return
}
[sideeffects]
def private V_ParseDamage_c2da_frame(c2da_fp : int) {
    var armor : int
    var blood : int
    var ent_2 : int
    var count : float
    armor = MSG_ReadByte()
    blood = MSG_ReadByte()
    for (i_3 in range(0, 3)) {
        let c2da_fresh218 : float = MSG_ReadCoord()
        let c2da_fresh219 : uint = float_bits_to_uint(c2da_fresh218)
        c2da_mem[c2da_fp + i_3 * 4] = uint8(c2da_fresh219)
        c2da_mem[c2da_fp + i_3 * 4 + 1] = uint8(c2da_fresh219 >> 0x8)
        c2da_mem[c2da_fp + i_3 * 4 + 2] = uint8(c2da_fresh219 >> 0x10)
        c2da_mem[c2da_fp + i_3 * 4 + 3] = uint8(c2da_fresh219 >> 0x18)
    }
    count = float(double(blood) * 0.5lf + double(armor) * 0.5lf)
    if (count < 10.0) {
        count = 10.0
    }
    let c2da_fresh220 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.2lf)
    let c2da_fresh221 : uint = float_bits_to_uint(c2da_fresh220)
    c2da_mem[496] = uint8(c2da_fresh221)
    c2da_mem[497] = uint8(c2da_fresh221 >> 0x8)
    c2da_mem[498] = uint8(c2da_fresh221 >> 0x10)
    c2da_mem[499] = uint8(c2da_fresh221 >> 0x18)
    let c2da_fresh222 : int = int(float(int(uint(c2da_mem[500 + 1 * 16 + 12]) | uint(c2da_mem[500 + 1 * 16 + 13]) << 0x8 | uint(c2da_mem[500 + 1 * 16 + 14]) << 0x10 | uint(c2da_mem[500 + 1 * 16 + 15]) << 0x18)) + 3.0 * count)
    let c2da_fresh223 : uint = uint(c2da_fresh222)
    c2da_mem[500 + 1 * 16 + 12] = uint8(c2da_fresh223)
    c2da_mem[500 + 1 * 16 + 13] = uint8(c2da_fresh223 >> 0x8)
    c2da_mem[500 + 1 * 16 + 14] = uint8(c2da_fresh223 >> 0x10)
    c2da_mem[500 + 1 * 16 + 15] = uint8(c2da_fresh223 >> 0x18)
    if (int(uint(c2da_mem[500 + 1 * 16 + 12]) | uint(c2da_mem[500 + 1 * 16 + 13]) << 0x8 | uint(c2da_mem[500 + 1 * 16 + 14]) << 0x10 | uint(c2da_mem[500 + 1 * 16 + 15]) << 0x18) < 0) {
        let c2da_fresh224 : int = 0
        let c2da_fresh225 : uint = uint(c2da_fresh224)
        c2da_mem[500 + 1 * 16 + 12] = uint8(c2da_fresh225)
        c2da_mem[500 + 1 * 16 + 13] = uint8(c2da_fresh225 >> 0x8)
        c2da_mem[500 + 1 * 16 + 14] = uint8(c2da_fresh225 >> 0x10)
        c2da_mem[500 + 1 * 16 + 15] = uint8(c2da_fresh225 >> 0x18)
    }
    if (int(uint(c2da_mem[500 + 1 * 16 + 12]) | uint(c2da_mem[500 + 1 * 16 + 13]) << 0x8 | uint(c2da_mem[500 + 1 * 16 + 14]) << 0x10 | uint(c2da_mem[500 + 1 * 16 + 15]) << 0x18) > 150) {
        let c2da_fresh226 : int = 150
        let c2da_fresh227 : uint = uint(c2da_fresh226)
        c2da_mem[500 + 1 * 16 + 12] = uint8(c2da_fresh227)
        c2da_mem[500 + 1 * 16 + 13] = uint8(c2da_fresh227 >> 0x8)
        c2da_mem[500 + 1 * 16 + 14] = uint8(c2da_fresh227 >> 0x10)
        c2da_mem[500 + 1 * 16 + 15] = uint8(c2da_fresh227 >> 0x18)
    }
    if (armor > blood) {
        let c2da_fresh228 : int = 200
        let c2da_fresh229 : uint = uint(c2da_fresh228)
        c2da_mem[500 + 1 * 16 + 0 * 4] = uint8(c2da_fresh229)
        c2da_mem[500 + 1 * 16 + 0 * 4 + 1] = uint8(c2da_fresh229 >> 0x8)
        c2da_mem[500 + 1 * 16 + 0 * 4 + 2] = uint8(c2da_fresh229 >> 0x10)
        c2da_mem[500 + 1 * 16 + 0 * 4 + 3] = uint8(c2da_fresh229 >> 0x18)
        let c2da_fresh230 : int = 100
        let c2da_fresh231 : uint = uint(c2da_fresh230)
        c2da_mem[500 + 1 * 16 + 1 * 4] = uint8(c2da_fresh231)
        c2da_mem[500 + 1 * 16 + 1 * 4 + 1] = uint8(c2da_fresh231 >> 0x8)
        c2da_mem[500 + 1 * 16 + 1 * 4 + 2] = uint8(c2da_fresh231 >> 0x10)
        c2da_mem[500 + 1 * 16 + 1 * 4 + 3] = uint8(c2da_fresh231 >> 0x18)
        let c2da_fresh232 : int = 100
        let c2da_fresh233 : uint = uint(c2da_fresh232)
        c2da_mem[500 + 1 * 16 + 2 * 4] = uint8(c2da_fresh233)
        c2da_mem[500 + 1 * 16 + 2 * 4 + 1] = uint8(c2da_fresh233 >> 0x8)
        c2da_mem[500 + 1 * 16 + 2 * 4 + 2] = uint8(c2da_fresh233 >> 0x10)
        c2da_mem[500 + 1 * 16 + 2 * 4 + 3] = uint8(c2da_fresh233 >> 0x18)
    } elif (armor != 0) {
        let c2da_fresh234 : int = 220
        let c2da_fresh235 : uint = uint(c2da_fresh234)
        c2da_mem[500 + 1 * 16 + 0 * 4] = uint8(c2da_fresh235)
        c2da_mem[500 + 1 * 16 + 0 * 4 + 1] = uint8(c2da_fresh235 >> 0x8)
        c2da_mem[500 + 1 * 16 + 0 * 4 + 2] = uint8(c2da_fresh235 >> 0x10)
        c2da_mem[500 + 1 * 16 + 0 * 4 + 3] = uint8(c2da_fresh235 >> 0x18)
        let c2da_fresh236 : int = 50
        let c2da_fresh237 : uint = uint(c2da_fresh236)
        c2da_mem[500 + 1 * 16 + 1 * 4] = uint8(c2da_fresh237)
        c2da_mem[500 + 1 * 16 + 1 * 4 + 1] = uint8(c2da_fresh237 >> 0x8)
        c2da_mem[500 + 1 * 16 + 1 * 4 + 2] = uint8(c2da_fresh237 >> 0x10)
        c2da_mem[500 + 1 * 16 + 1 * 4 + 3] = uint8(c2da_fresh237 >> 0x18)
        let c2da_fresh238 : int = 50
        let c2da_fresh239 : uint = uint(c2da_fresh238)
        c2da_mem[500 + 1 * 16 + 2 * 4] = uint8(c2da_fresh239)
        c2da_mem[500 + 1 * 16 + 2 * 4 + 1] = uint8(c2da_fresh239 >> 0x8)
        c2da_mem[500 + 1 * 16 + 2 * 4 + 2] = uint8(c2da_fresh239 >> 0x10)
        c2da_mem[500 + 1 * 16 + 2 * 4 + 3] = uint8(c2da_fresh239 >> 0x18)
    } else {
        let c2da_fresh240 : int = 255
        let c2da_fresh241 : uint = uint(c2da_fresh240)
        c2da_mem[500 + 1 * 16 + 0 * 4] = uint8(c2da_fresh241)
        c2da_mem[500 + 1 * 16 + 0 * 4 + 1] = uint8(c2da_fresh241 >> 0x8)
        c2da_mem[500 + 1 * 16 + 0 * 4 + 2] = uint8(c2da_fresh241 >> 0x10)
        c2da_mem[500 + 1 * 16 + 0 * 4 + 3] = uint8(c2da_fresh241 >> 0x18)
        let c2da_fresh242 : int = 0
        let c2da_fresh243 : uint = uint(c2da_fresh242)
        c2da_mem[500 + 1 * 16 + 1 * 4] = uint8(c2da_fresh243)
        c2da_mem[500 + 1 * 16 + 1 * 4 + 1] = uint8(c2da_fresh243 >> 0x8)
        c2da_mem[500 + 1 * 16 + 1 * 4 + 2] = uint8(c2da_fresh243 >> 0x10)
        c2da_mem[500 + 1 * 16 + 1 * 4 + 3] = uint8(c2da_fresh243 >> 0x18)
        let c2da_fresh244 : int = 0
        let c2da_fresh245 : uint = uint(c2da_fresh244)
        c2da_mem[500 + 1 * 16 + 2 * 4] = uint8(c2da_fresh245)
        c2da_mem[500 + 1 * 16 + 2 * 4 + 1] = uint8(c2da_fresh245 >> 0x8)
        c2da_mem[500 + 1 * 16 + 2 * 4 + 2] = uint8(c2da_fresh245 >> 0x10)
        c2da_mem[500 + 1 * 16 + 2 * 4 + 3] = uint8(c2da_fresh245 >> 0x18)
    }
    ent_2 = 10048 + int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18) * 200
    let c2da_fresh246 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[ent_2 + 88 + 0 * 4]) | uint(c2da_mem[ent_2 + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 88 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh247 : uint = float_bits_to_uint(c2da_fresh246)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh247)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh247 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh247 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh247 >> 0x18)
    let c2da_fresh248 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[ent_2 + 88 + 1 * 4]) | uint(c2da_mem[ent_2 + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 88 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh249 : uint = float_bits_to_uint(c2da_fresh248)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh249)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh249 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh249 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh249 >> 0x18)
    let c2da_fresh250 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[ent_2 + 88 + 2 * 4]) | uint(c2da_mem[ent_2 + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_2 + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_2 + 88 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh251 : uint = float_bits_to_uint(c2da_fresh250)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh251)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh251 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh251 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh251 >> 0x18)
    VectorNormalize(c2da_fp)
    AngleVectors(ent_2 + 124, c2da_fp + 16, c2da_fp + 32, c2da_fp + 48)
    v_dmg_roll = count * (uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 0 * 4]) | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 1 * 4]) | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 2 * 4]) | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 3]) << 0x18)) * uint_bits_to_float(uint(c2da_mem[696968]) | uint(c2da_mem[696969]) << 0x8 | uint(c2da_mem[696970]) << 0x10 | uint(c2da_mem[696971]) << 0x18)
    v_dmg_pitch = count * (uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18)) * uint_bits_to_float(uint(c2da_mem[697016]) | uint(c2da_mem[697017]) << 0x8 | uint(c2da_mem[697018]) << 0x10 | uint(c2da_mem[697019]) << 0x18)
    v_dmg_time = uint_bits_to_float(uint(c2da_mem[696920]) | uint(c2da_mem[696921]) << 0x8 | uint(c2da_mem[696922]) << 0x10 | uint(c2da_mem[696923]) << 0x18)
    return
}

// This unit's static data, at heap offset 737344.
let private c2da_lin_static_view_seg = fixed_array<int>(737344, 375)
let private c2da_lin_static_view = fixed_array<uint64>(0x3000785f64636cul, 0x7761795f64636cul, 0x7265746e65635f76ul, 0x312e300065766f6dul, 0x746e65635f760035ul, 0x64656570737265ul, 0x79695f7600303035ul, 0x656c6379635f7761ul, 0x6f72695f76003200ul, 0x656c6379635f6c6cul, 0x695f7600352e3000ul, 0x79635f6863746970ul, 0x5f76003100656c63ul, 0x76656c5f77617969ul, 0x7600332e30006c65ul, 0x6c5f6c6c6f72695ful, 0x312e30006c657665ul, 0x63746970695f7600ul, 0x6c6576656c5f68ul, 0x6373656c64695f76ul, 0x736f726300656c61ul, 0x6c63007269616873ul, 0x7873736f72635ful, 0x73736f72635f6c63ul, 0x6873635f6c670079ul, 0x6563726570746669ul, 0x730030303100746eul, 0x7873666f5f7263ul, 0x7973666f5f726373ul, 0x73666f5f72637300ul, 0x6c6f725f6c63007aul, 0x320064656570736cul, 0x6f725f6c63003030ul, 0x656c676e616c6cul, 0x625f6c6300302e32ul, 0x32302e3000626ful, 0x7963626f625f6c63ul, 0x362e3000656c63ul, 0x7075626f625f6c63ul, 0x746b63696b5f7600ul, 0x696b5f7600656d69ul, 0x76006c6c6f726b63ul, 0x7469706b63696b5ful, 0x616d6d6167006863ul, 0x66696873635f7600ul, 0x6e65630066620074ul, 0x77656976726574ul)

[init]
def private c2da_lin_init_static_view() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_view_seg[s * 2]
        for (k in range(c2da_lin_static_view_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_view[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_view_0 = fixed_array<uint8>(0x40, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_1 = fixed_array<uint8>(0x48, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_2 = fixed_array<uint8>(0x50, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5d, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_3 = fixed_array<uint8>(0x62, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_4 = fixed_array<uint8>(0x74, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x81, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_5 = fixed_array<uint8>(0x83, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x91, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_6 = fixed_array<uint8>(0x95, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa4, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_7 = fixed_array<uint8>(0xa6, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb3, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_8 = fixed_array<uint8>(0xb7, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc5, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_9 = fixed_array<uint8>(0xc9, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb3, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_10 = fixed_array<uint8>(0xd8, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_11 = fixed_array<uint8>(0xe4, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_12 = fixed_array<uint8>(0xee, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_13 = fixed_array<uint8>(0xf8, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_14 = fixed_array<uint8>(0x2, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x13, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_15 = fixed_array<uint8>(0x17, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_16 = fixed_array<uint8>(0x20, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_17 = fixed_array<uint8>(0x29, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_18 = fixed_array<uint8>(0x32, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_19 = fixed_array<uint8>(0x43, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x50, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_20 = fixed_array<uint8>(0x54, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5b, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_21 = fixed_array<uint8>(0x60, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6c, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_22 = fixed_array<uint8>(0x70, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x91, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_23 = fixed_array<uint8>(0x79, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x91, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_24 = fixed_array<uint8>(0x84, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6c, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_25 = fixed_array<uint8>(0x8f, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6c, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_view_26 = fixed_array<uint8>(0x9b, 0x41, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa4, 0x40, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_view() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[695792 + i] = c2da_lin_extern_view_0[i]
    }
    for (i in range(40)) {
        c2da_mem[695840 + i] = c2da_lin_extern_view_1[i]
    }
    for (i in range(40)) {
        c2da_mem[695888 + i] = c2da_lin_extern_view_2[i]
    }
    for (i in range(40)) {
        c2da_mem[695936 + i] = c2da_lin_extern_view_3[i]
    }
    for (i in range(40)) {
        c2da_mem[695984 + i] = c2da_lin_extern_view_4[i]
    }
    for (i in range(40)) {
        c2da_mem[696032 + i] = c2da_lin_extern_view_5[i]
    }
    for (i in range(40)) {
        c2da_mem[696080 + i] = c2da_lin_extern_view_6[i]
    }
    for (i in range(40)) {
        c2da_mem[696128 + i] = c2da_lin_extern_view_7[i]
    }
    for (i in range(40)) {
        c2da_mem[696176 + i] = c2da_lin_extern_view_8[i]
    }
    for (i in range(40)) {
        c2da_mem[696224 + i] = c2da_lin_extern_view_9[i]
    }
    for (i in range(40)) {
        c2da_mem[696272 + i] = c2da_lin_extern_view_10[i]
    }
    for (i in range(40)) {
        c2da_mem[696320 + i] = c2da_lin_extern_view_11[i]
    }
    for (i in range(40)) {
        c2da_mem[696368 + i] = c2da_lin_extern_view_12[i]
    }
    for (i in range(40)) {
        c2da_mem[696416 + i] = c2da_lin_extern_view_13[i]
    }
    for (i in range(40)) {
        c2da_mem[696464 + i] = c2da_lin_extern_view_14[i]
    }
    for (i in range(40)) {
        c2da_mem[696512 + i] = c2da_lin_extern_view_15[i]
    }
    for (i in range(40)) {
        c2da_mem[696560 + i] = c2da_lin_extern_view_16[i]
    }
    for (i in range(40)) {
        c2da_mem[696608 + i] = c2da_lin_extern_view_17[i]
    }
    for (i in range(40)) {
        c2da_mem[696656 + i] = c2da_lin_extern_view_18[i]
    }
    for (i in range(40)) {
        c2da_mem[696704 + i] = c2da_lin_extern_view_19[i]
    }
    for (i in range(40)) {
        c2da_mem[696752 + i] = c2da_lin_extern_view_20[i]
    }
    for (i in range(40)) {
        c2da_mem[696800 + i] = c2da_lin_extern_view_21[i]
    }
    for (i in range(40)) {
        c2da_mem[696848 + i] = c2da_lin_extern_view_22[i]
    }
    for (i in range(40)) {
        c2da_mem[696896 + i] = c2da_lin_extern_view_23[i]
    }
    for (i in range(40)) {
        c2da_mem[696944 + i] = c2da_lin_extern_view_24[i]
    }
    for (i in range(40)) {
        c2da_mem[696992 + i] = c2da_lin_extern_view_25[i]
    }
    for (i in range(40)) {
        c2da_mem[697040 + i] = c2da_lin_extern_view_26[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_view() {
    if (length(c2da_fn_table0) < 223) {
        resize(c2da_fn_table0, 223)
    }
    c2da_fn_table0[222] = @@V_StartPitchDrift
    c2da_fn_table0[221] = @@V_BonusFlash_f
    c2da_fn_table0[220] = @@V_cshift_f
}

[init]
def private c2da_lin_relink_init_view() {
    c2da_relink_view()
}
