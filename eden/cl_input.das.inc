[export, sideeffects]
def CL_InitInput() {
    Cmd_AddCommand(697864, 1)
    Cmd_AddCommand(697872, 2)
    Cmd_AddCommand(697880, 3)
    Cmd_AddCommand(697890, 4)
    Cmd_AddCommand(697900, 5)
    Cmd_AddCommand(697906, 6)
    Cmd_AddCommand(697912, 7)
    Cmd_AddCommand(697919, 8)
    Cmd_AddCommand(697926, 9)
    Cmd_AddCommand(697935, 10)
    Cmd_AddCommand(697944, 11)
    Cmd_AddCommand(697950, 12)
    Cmd_AddCommand(697956, 13)
    Cmd_AddCommand(697964, 14)
    Cmd_AddCommand(697972, 15)
    Cmd_AddCommand(697982, 16)
    Cmd_AddCommand(697992, 17)
    Cmd_AddCommand(698000, 18)
    Cmd_AddCommand(698008, 19)
    Cmd_AddCommand(698018, 20)
    Cmd_AddCommand(698028, 21)
    Cmd_AddCommand(698039, 22)
    Cmd_AddCommand(698050, 23)
    Cmd_AddCommand(698057, 24)
    Cmd_AddCommand(698064, 25)
    Cmd_AddCommand(698072, 26)
    Cmd_AddCommand(698080, 27)
    Cmd_AddCommand(698085, 28)
    Cmd_AddCommand(698090, 29)
    Cmd_AddCommand(698096, 30)
    Cmd_AddCommand(698102, 31)
    Cmd_AddCommand(698110, 32)
    Cmd_AddCommand(698117, 33)
    Cmd_AddCommand(698124, 34)
    Cmd_AddCommand(698131, 35)
    return
}
[export, sideeffects]
def IN_MLookUp() {
    KeyUp(7840)
    if ((int(uint(c2da_mem[7848]) | uint(c2da_mem[7849]) << 0x8 | uint(c2da_mem[7850]) << 0x10 | uint(c2da_mem[7851]) << 0x18) & 1) == 0 && uint_bits_to_float(uint(c2da_mem[9736]) | uint(c2da_mem[9737]) << 0x8 | uint(c2da_mem[9738]) << 0x10 | uint(c2da_mem[9739]) << 0x18) != 0.0) {
        V_StartPitchDrift()
    }
    return
}
[export, sideeffects]
def KeyUp(var b : int) {
    var k : int
    var c : int = Cmd_Argv(1)
    if (int8(c2da_mem[c + 0]) != 0) {
        k = c2da_lin_atoi(c)
    } else {
        let c2da_fresh0 : int = 0
        let c2da_fresh1 : uint = uint(c2da_fresh0)
        c2da_mem[b + 1 * 4] = uint8(c2da_fresh1)
        c2da_mem[b + 1 * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[b + 1 * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[b + 1 * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
        let c2da_fresh2 : uint = uint(c2da_fresh0)
        c2da_mem[b + 0 * 4] = uint8(c2da_fresh2)
        c2da_mem[b + 0 * 4 + 1] = uint8(c2da_fresh2 >> 0x8)
        c2da_mem[b + 0 * 4 + 2] = uint8(c2da_fresh2 >> 0x10)
        c2da_mem[b + 0 * 4 + 3] = uint8(c2da_fresh2 >> 0x18)
        let c2da_fresh3 : int = 4
        let c2da_fresh4 : uint = uint(c2da_fresh3)
        c2da_mem[b + 8] = uint8(c2da_fresh4)
        c2da_mem[b + 9] = uint8(c2da_fresh4 >> 0x8)
        c2da_mem[b + 10] = uint8(c2da_fresh4 >> 0x10)
        c2da_mem[b + 11] = uint8(c2da_fresh4 >> 0x18)
        return
    }
    if (int(uint(c2da_mem[b + 0 * 4]) | uint(c2da_mem[b + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 0 * 4 + 3]) << 0x18) == k) {
        let c2da_fresh5 : int = 0
        let c2da_fresh6 : uint = uint(c2da_fresh5)
        c2da_mem[b + 0 * 4] = uint8(c2da_fresh6)
        c2da_mem[b + 0 * 4 + 1] = uint8(c2da_fresh6 >> 0x8)
        c2da_mem[b + 0 * 4 + 2] = uint8(c2da_fresh6 >> 0x10)
        c2da_mem[b + 0 * 4 + 3] = uint8(c2da_fresh6 >> 0x18)
    } elif (int(uint(c2da_mem[b + 1 * 4]) | uint(c2da_mem[b + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 1 * 4 + 3]) << 0x18) == k) {
        let c2da_fresh7 : int = 0
        let c2da_fresh8 : uint = uint(c2da_fresh7)
        c2da_mem[b + 1 * 4] = uint8(c2da_fresh8)
        c2da_mem[b + 1 * 4 + 1] = uint8(c2da_fresh8 >> 0x8)
        c2da_mem[b + 1 * 4 + 2] = uint8(c2da_fresh8 >> 0x10)
        c2da_mem[b + 1 * 4 + 3] = uint8(c2da_fresh8 >> 0x18)
    } else {
        return
    }
    if (int(uint(c2da_mem[b + 0 * 4]) | uint(c2da_mem[b + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 0 * 4 + 3]) << 0x18) != 0 || int(uint(c2da_mem[b + 1 * 4]) | uint(c2da_mem[b + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 1 * 4 + 3]) << 0x18) != 0) {
        return
    }
    if ((int(uint(c2da_mem[b + 8]) | uint(c2da_mem[b + 9]) << 0x8 | uint(c2da_mem[b + 10]) << 0x10 | uint(c2da_mem[b + 11]) << 0x18) & 1) == 0) {
        return
    }
    let c2da_fresh9 : int = int(uint(c2da_mem[b + 8]) | uint(c2da_mem[b + 9]) << 0x8 | uint(c2da_mem[b + 10]) << 0x10 | uint(c2da_mem[b + 11]) << 0x18) & ~1
    let c2da_fresh10 : uint = uint(c2da_fresh9)
    c2da_mem[b + 8] = uint8(c2da_fresh10)
    c2da_mem[b + 9] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[b + 10] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[b + 11] = uint8(c2da_fresh10 >> 0x18)
    let c2da_fresh11 : int = int(uint(c2da_mem[b + 8]) | uint(c2da_mem[b + 9]) << 0x8 | uint(c2da_mem[b + 10]) << 0x10 | uint(c2da_mem[b + 11]) << 0x18) | 4
    let c2da_fresh12 : uint = uint(c2da_fresh11)
    c2da_mem[b + 8] = uint8(c2da_fresh12)
    c2da_mem[b + 9] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[b + 10] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[b + 11] = uint8(c2da_fresh12 >> 0x18)
    return
}
[export, sideeffects]
def IN_MLookDown() {
    KeyDown(7840)
    return
}
[export, sideeffects]
def KeyDown(var b_0 : int) {
    var k_0 : int
    var c_0 : int = Cmd_Argv(1)
    if (int8(c2da_mem[c_0 + 0]) != 0) {
        k_0 = c2da_lin_atoi(c_0)
    } else {
        k_0 = -1
    }
    if (k_0 == int(uint(c2da_mem[b_0 + 0 * 4]) | uint(c2da_mem[b_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[b_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[b_0 + 0 * 4 + 3]) << 0x18) || k_0 == int(uint(c2da_mem[b_0 + 1 * 4]) | uint(c2da_mem[b_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[b_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[b_0 + 1 * 4 + 3]) << 0x18)) {
        return
    }
    if (int(uint(c2da_mem[b_0 + 0 * 4]) | uint(c2da_mem[b_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[b_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[b_0 + 0 * 4 + 3]) << 0x18) == 0) {
        let c2da_fresh13 : uint = uint(k_0)
        c2da_mem[b_0 + 0 * 4] = uint8(c2da_fresh13)
        c2da_mem[b_0 + 0 * 4 + 1] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[b_0 + 0 * 4 + 2] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[b_0 + 0 * 4 + 3] = uint8(c2da_fresh13 >> 0x18)
    } elif (int(uint(c2da_mem[b_0 + 1 * 4]) | uint(c2da_mem[b_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[b_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[b_0 + 1 * 4 + 3]) << 0x18) == 0) {
        let c2da_fresh14 : uint = uint(k_0)
        c2da_mem[b_0 + 1 * 4] = uint8(c2da_fresh14)
        c2da_mem[b_0 + 1 * 4 + 1] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[b_0 + 1 * 4 + 2] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[b_0 + 1 * 4 + 3] = uint8(c2da_fresh14 >> 0x18)
    } else {
        Con_Printf(698138, [])
        return
    }
    if ((int(uint(c2da_mem[b_0 + 8]) | uint(c2da_mem[b_0 + 9]) << 0x8 | uint(c2da_mem[b_0 + 10]) << 0x10 | uint(c2da_mem[b_0 + 11]) << 0x18) & 1) != 0) {
        return
    }
    let c2da_fresh15 : int = int(uint(c2da_mem[b_0 + 8]) | uint(c2da_mem[b_0 + 9]) << 0x8 | uint(c2da_mem[b_0 + 10]) << 0x10 | uint(c2da_mem[b_0 + 11]) << 0x18) | 1 + 2
    let c2da_fresh16 : uint = uint(c2da_fresh15)
    c2da_mem[b_0 + 8] = uint8(c2da_fresh16)
    c2da_mem[b_0 + 9] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[b_0 + 10] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[b_0 + 11] = uint8(c2da_fresh16 >> 0x18)
    return
}
[export, sideeffects]
def IN_KLookUp() {
    KeyUp(7856)
    return
}
[export, sideeffects]
def IN_KLookDown() {
    KeyDown(7856)
    return
}
[export, sideeffects]
def IN_Impulse() {
    in_impulse = Q_atoi(Cmd_Argv(1))
    return
}
var in_impulse : int = default<int>

[export, sideeffects]
def IN_JumpUp() {
    KeyUp(7872)
    return
}
[export, sideeffects]
def IN_JumpDown() {
    KeyDown(7872)
    return
}
[export, sideeffects]
def IN_UseUp() {
    KeyUp(7888)
    return
}
[export, sideeffects]
def IN_UseDown() {
    KeyDown(7888)
    return
}
[export, sideeffects]
def IN_AttackUp() {
    KeyUp(7904)
    return
}
[export, sideeffects]
def IN_AttackDown() {
    KeyDown(7904)
    return
}
[export, sideeffects]
def IN_SpeedUp() {
    KeyUp(7920)
    return
}
[export, sideeffects]
def IN_SpeedDown() {
    KeyDown(7920)
    return
}
[export, sideeffects]
def IN_MoverightUp() {
    KeyUp(7936)
    return
}
[export, sideeffects]
def IN_MoverightDown() {
    KeyDown(7936)
    return
}
[export, sideeffects]
def IN_MoveleftUp() {
    KeyUp(7952)
    return
}
[export, sideeffects]
def IN_MoveleftDown() {
    KeyDown(7952)
    return
}
[export, sideeffects]
def IN_StrafeUp() {
    KeyUp(7968)
    return
}
[export, sideeffects]
def IN_StrafeDown() {
    KeyDown(7968)
    return
}
[export, sideeffects]
def IN_LookdownUp() {
    KeyUp(7984)
    return
}
[export, sideeffects]
def IN_LookdownDown() {
    KeyDown(7984)
    return
}
[export, sideeffects]
def IN_LookupUp() {
    KeyUp(8000)
    return
}
[export, sideeffects]
def IN_LookupDown() {
    KeyDown(8000)
    return
}
[export, sideeffects]
def IN_BackUp() {
    KeyUp(8016)
    return
}
[export, sideeffects]
def IN_BackDown() {
    KeyDown(8016)
    return
}
[export, sideeffects]
def IN_ForwardUp() {
    KeyUp(8032)
    return
}
[export, sideeffects]
def IN_ForwardDown() {
    KeyDown(8032)
    return
}
[export, sideeffects]
def IN_RightUp() {
    KeyUp(8048)
    return
}
[export, sideeffects]
def IN_RightDown() {
    KeyDown(8048)
    return
}
[export, sideeffects]
def IN_LeftUp() {
    KeyUp(8064)
    return
}
[export, sideeffects]
def IN_LeftDown() {
    KeyDown(8064)
    return
}
[export, sideeffects]
def IN_DownUp() {
    KeyUp(8080)
    return
}
[export, sideeffects]
def IN_DownDown() {
    KeyDown(8080)
    return
}
[export, sideeffects]
def IN_UpUp() {
    KeyUp(8096)
    return
}
[export, sideeffects]
def IN_UpDown() {
    KeyDown(8096)
    return
}
[export, sideeffects]
def CL_SendMove(var cmd_0 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    CL_SendMove_c2da_frame(cmd_0, c2da_lin_enter(160))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def CL_BaseMove(var cmd_1 : int) {
    if (int(uint(c2da_mem[7804]) | uint(c2da_mem[7805]) << 0x8 | uint(c2da_mem[7806]) << 0x10 | uint(c2da_mem[7807]) << 0x18) != 4) {
        return
    }
    CL_AdjustAngles()
    Q_memset(cmd_1, 0, 24)
    if ((int(uint(c2da_mem[7976]) | uint(c2da_mem[7977]) << 0x8 | uint(c2da_mem[7978]) << 0x10 | uint(c2da_mem[7979]) << 0x18) & 1) != 0) {
        let c2da_fresh29 : float = uint_bits_to_float(uint(c2da_mem[cmd_1 + 16]) | uint(c2da_mem[cmd_1 + 17]) << 0x8 | uint(c2da_mem[cmd_1 + 18]) << 0x10 | uint(c2da_mem[cmd_1 + 19]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[9400]) | uint(c2da_mem[9401]) << 0x8 | uint(c2da_mem[9402]) << 0x10 | uint(c2da_mem[9403]) << 0x18) * CL_KeyState(8048))
        let c2da_fresh30 : uint = float_bits_to_uint(c2da_fresh29)
        c2da_mem[cmd_1 + 16] = uint8(c2da_fresh30)
        c2da_mem[cmd_1 + 17] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[cmd_1 + 18] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[cmd_1 + 19] = uint8(c2da_fresh30 >> 0x18)
        let c2da_fresh31 : float = uint_bits_to_float(uint(c2da_mem[cmd_1 + 16]) | uint(c2da_mem[cmd_1 + 17]) << 0x8 | uint(c2da_mem[cmd_1 + 18]) << 0x10 | uint(c2da_mem[cmd_1 + 19]) << 0x18) - float(uint_bits_to_float(uint(c2da_mem[9400]) | uint(c2da_mem[9401]) << 0x8 | uint(c2da_mem[9402]) << 0x10 | uint(c2da_mem[9403]) << 0x18) * CL_KeyState(8064))
        let c2da_fresh32 : uint = float_bits_to_uint(c2da_fresh31)
        c2da_mem[cmd_1 + 16] = uint8(c2da_fresh32)
        c2da_mem[cmd_1 + 17] = uint8(c2da_fresh32 >> 0x8)
        c2da_mem[cmd_1 + 18] = uint8(c2da_fresh32 >> 0x10)
        c2da_mem[cmd_1 + 19] = uint8(c2da_fresh32 >> 0x18)
    }
    let c2da_fresh33 : float = uint_bits_to_float(uint(c2da_mem[cmd_1 + 16]) | uint(c2da_mem[cmd_1 + 17]) << 0x8 | uint(c2da_mem[cmd_1 + 18]) << 0x10 | uint(c2da_mem[cmd_1 + 19]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[9400]) | uint(c2da_mem[9401]) << 0x8 | uint(c2da_mem[9402]) << 0x10 | uint(c2da_mem[9403]) << 0x18) * CL_KeyState(7936))
    let c2da_fresh34 : uint = float_bits_to_uint(c2da_fresh33)
    c2da_mem[cmd_1 + 16] = uint8(c2da_fresh34)
    c2da_mem[cmd_1 + 17] = uint8(c2da_fresh34 >> 0x8)
    c2da_mem[cmd_1 + 18] = uint8(c2da_fresh34 >> 0x10)
    c2da_mem[cmd_1 + 19] = uint8(c2da_fresh34 >> 0x18)
    let c2da_fresh35 : float = uint_bits_to_float(uint(c2da_mem[cmd_1 + 16]) | uint(c2da_mem[cmd_1 + 17]) << 0x8 | uint(c2da_mem[cmd_1 + 18]) << 0x10 | uint(c2da_mem[cmd_1 + 19]) << 0x18) - float(uint_bits_to_float(uint(c2da_mem[9400]) | uint(c2da_mem[9401]) << 0x8 | uint(c2da_mem[9402]) << 0x10 | uint(c2da_mem[9403]) << 0x18) * CL_KeyState(7952))
    let c2da_fresh36 : uint = float_bits_to_uint(c2da_fresh35)
    c2da_mem[cmd_1 + 16] = uint8(c2da_fresh36)
    c2da_mem[cmd_1 + 17] = uint8(c2da_fresh36 >> 0x8)
    c2da_mem[cmd_1 + 18] = uint8(c2da_fresh36 >> 0x10)
    c2da_mem[cmd_1 + 19] = uint8(c2da_fresh36 >> 0x18)
    let c2da_fresh37 : float = uint_bits_to_float(uint(c2da_mem[cmd_1 + 20]) | uint(c2da_mem[cmd_1 + 21]) << 0x8 | uint(c2da_mem[cmd_1 + 22]) << 0x10 | uint(c2da_mem[cmd_1 + 23]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[9256]) | uint(c2da_mem[9257]) << 0x8 | uint(c2da_mem[9258]) << 0x10 | uint(c2da_mem[9259]) << 0x18) * CL_KeyState(8096))
    let c2da_fresh38 : uint = float_bits_to_uint(c2da_fresh37)
    c2da_mem[cmd_1 + 20] = uint8(c2da_fresh38)
    c2da_mem[cmd_1 + 21] = uint8(c2da_fresh38 >> 0x8)
    c2da_mem[cmd_1 + 22] = uint8(c2da_fresh38 >> 0x10)
    c2da_mem[cmd_1 + 23] = uint8(c2da_fresh38 >> 0x18)
    let c2da_fresh39 : float = uint_bits_to_float(uint(c2da_mem[cmd_1 + 20]) | uint(c2da_mem[cmd_1 + 21]) << 0x8 | uint(c2da_mem[cmd_1 + 22]) << 0x10 | uint(c2da_mem[cmd_1 + 23]) << 0x18) - float(uint_bits_to_float(uint(c2da_mem[9256]) | uint(c2da_mem[9257]) << 0x8 | uint(c2da_mem[9258]) << 0x10 | uint(c2da_mem[9259]) << 0x18) * CL_KeyState(8080))
    let c2da_fresh40 : uint = float_bits_to_uint(c2da_fresh39)
    c2da_mem[cmd_1 + 20] = uint8(c2da_fresh40)
    c2da_mem[cmd_1 + 21] = uint8(c2da_fresh40 >> 0x8)
    c2da_mem[cmd_1 + 22] = uint8(c2da_fresh40 >> 0x10)
    c2da_mem[cmd_1 + 23] = uint8(c2da_fresh40 >> 0x18)
    if ((int(uint(c2da_mem[7864]) | uint(c2da_mem[7865]) << 0x8 | uint(c2da_mem[7866]) << 0x10 | uint(c2da_mem[7867]) << 0x18) & 1) == 0) {
        let c2da_fresh41 : float = uint_bits_to_float(uint(c2da_mem[cmd_1 + 12]) | uint(c2da_mem[cmd_1 + 13]) << 0x8 | uint(c2da_mem[cmd_1 + 14]) << 0x10 | uint(c2da_mem[cmd_1 + 15]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[9304]) | uint(c2da_mem[9305]) << 0x8 | uint(c2da_mem[9306]) << 0x10 | uint(c2da_mem[9307]) << 0x18) * CL_KeyState(8032))
        let c2da_fresh42 : uint = float_bits_to_uint(c2da_fresh41)
        c2da_mem[cmd_1 + 12] = uint8(c2da_fresh42)
        c2da_mem[cmd_1 + 13] = uint8(c2da_fresh42 >> 0x8)
        c2da_mem[cmd_1 + 14] = uint8(c2da_fresh42 >> 0x10)
        c2da_mem[cmd_1 + 15] = uint8(c2da_fresh42 >> 0x18)
        let c2da_fresh43 : float = uint_bits_to_float(uint(c2da_mem[cmd_1 + 12]) | uint(c2da_mem[cmd_1 + 13]) << 0x8 | uint(c2da_mem[cmd_1 + 14]) << 0x10 | uint(c2da_mem[cmd_1 + 15]) << 0x18) - float(uint_bits_to_float(uint(c2da_mem[9352]) | uint(c2da_mem[9353]) << 0x8 | uint(c2da_mem[9354]) << 0x10 | uint(c2da_mem[9355]) << 0x18) * CL_KeyState(8016))
        let c2da_fresh44 : uint = float_bits_to_uint(c2da_fresh43)
        c2da_mem[cmd_1 + 12] = uint8(c2da_fresh44)
        c2da_mem[cmd_1 + 13] = uint8(c2da_fresh44 >> 0x8)
        c2da_mem[cmd_1 + 14] = uint8(c2da_fresh44 >> 0x10)
        c2da_mem[cmd_1 + 15] = uint8(c2da_fresh44 >> 0x18)
    }
    if ((int(uint(c2da_mem[7928]) | uint(c2da_mem[7929]) << 0x8 | uint(c2da_mem[7930]) << 0x10 | uint(c2da_mem[7931]) << 0x18) & 1) != 0) {
        let c2da_fresh45 : float = uint_bits_to_float(uint(c2da_mem[cmd_1 + 12]) | uint(c2da_mem[cmd_1 + 13]) << 0x8 | uint(c2da_mem[cmd_1 + 14]) << 0x10 | uint(c2da_mem[cmd_1 + 15]) << 0x18) * float(uint_bits_to_float(uint(c2da_mem[9448]) | uint(c2da_mem[9449]) << 0x8 | uint(c2da_mem[9450]) << 0x10 | uint(c2da_mem[9451]) << 0x18))
        let c2da_fresh46 : uint = float_bits_to_uint(c2da_fresh45)
        c2da_mem[cmd_1 + 12] = uint8(c2da_fresh46)
        c2da_mem[cmd_1 + 13] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[cmd_1 + 14] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[cmd_1 + 15] = uint8(c2da_fresh46 >> 0x18)
        let c2da_fresh47 : float = uint_bits_to_float(uint(c2da_mem[cmd_1 + 16]) | uint(c2da_mem[cmd_1 + 17]) << 0x8 | uint(c2da_mem[cmd_1 + 18]) << 0x10 | uint(c2da_mem[cmd_1 + 19]) << 0x18) * float(uint_bits_to_float(uint(c2da_mem[9448]) | uint(c2da_mem[9449]) << 0x8 | uint(c2da_mem[9450]) << 0x10 | uint(c2da_mem[9451]) << 0x18))
        let c2da_fresh48 : uint = float_bits_to_uint(c2da_fresh47)
        c2da_mem[cmd_1 + 16] = uint8(c2da_fresh48)
        c2da_mem[cmd_1 + 17] = uint8(c2da_fresh48 >> 0x8)
        c2da_mem[cmd_1 + 18] = uint8(c2da_fresh48 >> 0x10)
        c2da_mem[cmd_1 + 19] = uint8(c2da_fresh48 >> 0x18)
        let c2da_fresh49 : float = uint_bits_to_float(uint(c2da_mem[cmd_1 + 20]) | uint(c2da_mem[cmd_1 + 21]) << 0x8 | uint(c2da_mem[cmd_1 + 22]) << 0x10 | uint(c2da_mem[cmd_1 + 23]) << 0x18) * float(uint_bits_to_float(uint(c2da_mem[9448]) | uint(c2da_mem[9449]) << 0x8 | uint(c2da_mem[9450]) << 0x10 | uint(c2da_mem[9451]) << 0x18))
        let c2da_fresh50 : uint = float_bits_to_uint(c2da_fresh49)
        c2da_mem[cmd_1 + 20] = uint8(c2da_fresh50)
        c2da_mem[cmd_1 + 21] = uint8(c2da_fresh50 >> 0x8)
        c2da_mem[cmd_1 + 22] = uint8(c2da_fresh50 >> 0x10)
        c2da_mem[cmd_1 + 23] = uint8(c2da_fresh50 >> 0x18)
    }
    return
}
[export, sideeffects]
def CL_KeyState(var key : int) : float {
    var val : float
    var impulsedown : uint
    var impulseup : uint
    var down : uint
    let c2da_fresh53 : int = int(uint(c2da_mem[key + 8]) | uint(c2da_mem[key + 9]) << 0x8 | uint(c2da_mem[key + 10]) << 0x10 | uint(c2da_mem[key + 11]) << 0x18)
    impulsedown = uint(c2da_fresh53 & 2)
    impulseup = uint(c2da_fresh53 & 4)
    down = uint(c2da_fresh53 & 1)
    val = 0.0
    if (impulsedown != 0x0 && impulseup == 0u) {
        if (down != 0u) {
            val = 0.5
        } else {
            val = 0.0
        }
    }
    if (impulseup != 0x0 && impulsedown == 0u) {
        if (down != 0u) {
            val = 0.0
        } else {
            val = 0.0
        }
    }
    if (impulsedown == 0u && impulseup == 0u) {
        if (down != 0u) {
            val = 1.0
        } else {
            val = 0.0
        }
    }
    if (impulsedown != 0x0 && impulseup != 0x0) {
        if (down != 0u) {
            val = 0.75
        } else {
            val = 0.25
        }
    }
    let c2da_fresh51 : int = int(uint(c2da_mem[key + 8]) | uint(c2da_mem[key + 9]) << 0x8 | uint(c2da_mem[key + 10]) << 0x10 | uint(c2da_mem[key + 11]) << 0x18) & 1
    let c2da_fresh52 : uint = uint(c2da_fresh51)
    c2da_mem[key + 8] = uint8(c2da_fresh52)
    c2da_mem[key + 9] = uint8(c2da_fresh52 >> 0x8)
    c2da_mem[key + 10] = uint8(c2da_fresh52 >> 0x10)
    c2da_mem[key + 11] = uint8(c2da_fresh52 >> 0x18)
    return val
}
[export, sideeffects]
def CL_AdjustAngles() {
    var speed : float
    var up_0 : float
    var down_0 : float
    if ((int(uint(c2da_mem[7928]) | uint(c2da_mem[7929]) << 0x8 | uint(c2da_mem[7930]) << 0x10 | uint(c2da_mem[7931]) << 0x18) & 1) != 0) {
        speed = float(host_frametime * double(uint_bits_to_float(uint(c2da_mem[9592]) | uint(c2da_mem[9593]) << 0x8 | uint(c2da_mem[9594]) << 0x10 | uint(c2da_mem[9595]) << 0x18)))
    } else {
        speed = float(host_frametime)
    }
    if ((int(uint(c2da_mem[7976]) | uint(c2da_mem[7977]) << 0x8 | uint(c2da_mem[7978]) << 0x10 | uint(c2da_mem[7979]) << 0x18) & 1) == 0) {
        let c2da_fresh54 : float = uint_bits_to_float(uint(c2da_mem[652 + 1 * 4]) | uint(c2da_mem[652 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 1 * 4 + 3]) << 0x18) - float(speed * uint_bits_to_float(uint(c2da_mem[9496]) | uint(c2da_mem[9497]) << 0x8 | uint(c2da_mem[9498]) << 0x10 | uint(c2da_mem[9499]) << 0x18) * CL_KeyState(8048))
        let c2da_fresh55 : uint = float_bits_to_uint(c2da_fresh54)
        c2da_mem[652 + 1 * 4] = uint8(c2da_fresh55)
        c2da_mem[652 + 1 * 4 + 1] = uint8(c2da_fresh55 >> 0x8)
        c2da_mem[652 + 1 * 4 + 2] = uint8(c2da_fresh55 >> 0x10)
        c2da_mem[652 + 1 * 4 + 3] = uint8(c2da_fresh55 >> 0x18)
        let c2da_fresh56 : float = uint_bits_to_float(uint(c2da_mem[652 + 1 * 4]) | uint(c2da_mem[652 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 1 * 4 + 3]) << 0x18) + float(speed * uint_bits_to_float(uint(c2da_mem[9496]) | uint(c2da_mem[9497]) << 0x8 | uint(c2da_mem[9498]) << 0x10 | uint(c2da_mem[9499]) << 0x18) * CL_KeyState(8064))
        let c2da_fresh57 : uint = float_bits_to_uint(c2da_fresh56)
        c2da_mem[652 + 1 * 4] = uint8(c2da_fresh57)
        c2da_mem[652 + 1 * 4 + 1] = uint8(c2da_fresh57 >> 0x8)
        c2da_mem[652 + 1 * 4 + 2] = uint8(c2da_fresh57 >> 0x10)
        c2da_mem[652 + 1 * 4 + 3] = uint8(c2da_fresh57 >> 0x18)
        let c2da_fresh58 : float = anglemod(uint_bits_to_float(uint(c2da_mem[652 + 1 * 4]) | uint(c2da_mem[652 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 1 * 4 + 3]) << 0x18))
        let c2da_fresh59 : uint = float_bits_to_uint(c2da_fresh58)
        c2da_mem[652 + 1 * 4] = uint8(c2da_fresh59)
        c2da_mem[652 + 1 * 4 + 1] = uint8(c2da_fresh59 >> 0x8)
        c2da_mem[652 + 1 * 4 + 2] = uint8(c2da_fresh59 >> 0x10)
        c2da_mem[652 + 1 * 4 + 3] = uint8(c2da_fresh59 >> 0x18)
    }
    if ((int(uint(c2da_mem[7864]) | uint(c2da_mem[7865]) << 0x8 | uint(c2da_mem[7866]) << 0x10 | uint(c2da_mem[7867]) << 0x18) & 1) != 0) {
        V_StopPitchDrift()
        let c2da_fresh60 : float = uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18) - float(speed * uint_bits_to_float(uint(c2da_mem[9544]) | uint(c2da_mem[9545]) << 0x8 | uint(c2da_mem[9546]) << 0x10 | uint(c2da_mem[9547]) << 0x18) * CL_KeyState(8032))
        let c2da_fresh61 : uint = float_bits_to_uint(c2da_fresh60)
        c2da_mem[652 + 0 * 4] = uint8(c2da_fresh61)
        c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh61 >> 0x8)
        c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh61 >> 0x10)
        c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh61 >> 0x18)
        let c2da_fresh62 : float = uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18) + float(speed * uint_bits_to_float(uint(c2da_mem[9544]) | uint(c2da_mem[9545]) << 0x8 | uint(c2da_mem[9546]) << 0x10 | uint(c2da_mem[9547]) << 0x18) * CL_KeyState(8016))
        let c2da_fresh63 : uint = float_bits_to_uint(c2da_fresh62)
        c2da_mem[652 + 0 * 4] = uint8(c2da_fresh63)
        c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh63 >> 0x8)
        c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh63 >> 0x10)
        c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh63 >> 0x18)
    }
    up_0 = CL_KeyState(8000)
    down_0 = CL_KeyState(7984)
    let c2da_fresh76 : float = uint_bits_to_float(uint(c2da_mem[9544]) | uint(c2da_mem[9545]) << 0x8 | uint(c2da_mem[9546]) << 0x10 | uint(c2da_mem[9547]) << 0x18)
    let c2da_fresh64 : float = uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18) - speed * c2da_fresh76 * up_0
    let c2da_fresh65 : uint = float_bits_to_uint(c2da_fresh64)
    c2da_mem[652 + 0 * 4] = uint8(c2da_fresh65)
    c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh65 >> 0x18)
    let c2da_fresh66 : float = c2da_fresh64 + speed * c2da_fresh76 * down_0
    let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
    c2da_mem[652 + 0 * 4] = uint8(c2da_fresh67)
    c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh67 >> 0x18)
    if (up_0 != 0.0 || down_0 != 0.0) {
        V_StopPitchDrift()
    }
    if (uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18) > 80.0) {
        let c2da_fresh68 : float = 80.0
        let c2da_fresh69 : uint = float_bits_to_uint(c2da_fresh68)
        c2da_mem[652 + 0 * 4] = uint8(c2da_fresh69)
        c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh69 >> 0x8)
        c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh69 >> 0x10)
        c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh69 >> 0x18)
    }
    if (uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18) < -70.0) {
        let c2da_fresh70 : float = -70.0
        let c2da_fresh71 : uint = float_bits_to_uint(c2da_fresh70)
        c2da_mem[652 + 0 * 4] = uint8(c2da_fresh71)
        c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh71 >> 0x8)
        c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh71 >> 0x10)
        c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh71 >> 0x18)
    }
    if (uint_bits_to_float(uint(c2da_mem[652 + 2 * 4]) | uint(c2da_mem[652 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 2 * 4 + 3]) << 0x18) > 50.0) {
        let c2da_fresh72 : float = 50.0
        let c2da_fresh73 : uint = float_bits_to_uint(c2da_fresh72)
        c2da_mem[652 + 2 * 4] = uint8(c2da_fresh73)
        c2da_mem[652 + 2 * 4 + 1] = uint8(c2da_fresh73 >> 0x8)
        c2da_mem[652 + 2 * 4 + 2] = uint8(c2da_fresh73 >> 0x10)
        c2da_mem[652 + 2 * 4 + 3] = uint8(c2da_fresh73 >> 0x18)
    }
    if (uint_bits_to_float(uint(c2da_mem[652 + 2 * 4]) | uint(c2da_mem[652 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 2 * 4 + 3]) << 0x18) < -50.0) {
        let c2da_fresh74 : float = -50.0
        let c2da_fresh75 : uint = float_bits_to_uint(c2da_fresh74)
        c2da_mem[652 + 2 * 4] = uint8(c2da_fresh75)
        c2da_mem[652 + 2 * 4 + 1] = uint8(c2da_fresh75 >> 0x8)
        c2da_mem[652 + 2 * 4 + 2] = uint8(c2da_fresh75 >> 0x10)
        c2da_mem[652 + 2 * 4 + 3] = uint8(c2da_fresh75 >> 0x18)
    }
    return
}
[sideeffects]
def private CL_SendMove_c2da_frame(var cmd_0 : int; c2da_fp : int) {
    var bits : int
    let c2da_fresh17 : int = 128
    let c2da_fresh18 : uint = uint(c2da_fresh17)
    c2da_mem[c2da_fp + 144] = uint8(c2da_fresh18)
    c2da_mem[c2da_fp + 145] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[c2da_fp + 146] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[c2da_fp + 147] = uint8(c2da_fresh18 >> 0x18)
    let c2da_fresh19 : int = 0
    let c2da_fresh20 : uint = uint(c2da_fresh19)
    c2da_mem[c2da_fp + 148] = uint8(c2da_fresh20)
    c2da_mem[c2da_fp + 149] = uint8(c2da_fresh20 >> 0x8)
    c2da_mem[c2da_fp + 150] = uint8(c2da_fresh20 >> 0x10)
    c2da_mem[c2da_fp + 151] = uint8(c2da_fresh20 >> 0x18)
    let c2da_fresh21 : uint = uint(c2da_fp)
    c2da_mem[c2da_fp + 136] = uint8(c2da_fresh21)
    c2da_mem[c2da_fp + 137] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[c2da_fp + 138] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[c2da_fp + 139] = uint8(c2da_fresh21 >> 0x18)
    c2da_mem[c2da_fp + 140] = 0u8
    c2da_mem[c2da_fp + 141] = 0u8
    c2da_mem[c2da_fp + 142] = 0u8
    c2da_mem[c2da_fp + 143] = 0u8
    c2da_lin_memmove(212, cmd_0, 24ul)
    MSG_WriteByte(c2da_fp + 128, 3)
    MSG_WriteFloat(c2da_fp + 128, float(uint64_bits_to_double(uint64(uint(c2da_mem[768 + 0 * 8]) | uint(c2da_mem[768 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 3]) << 0x18) | uint64(uint(c2da_mem[768 + 0 * 8 + 4]) | uint(c2da_mem[768 + 0 * 8 + 5]) << 0x8 | uint(c2da_mem[768 + 0 * 8 + 6]) << 0x10 | uint(c2da_mem[768 + 0 * 8 + 7]) << 0x18) << 0x20)))
    for (i in range(0, 3)) {
        MSG_WriteAngle(c2da_fp + 128, uint_bits_to_float(uint(c2da_mem[652 + i * 4]) | uint(c2da_mem[652 + i * 4 + 1]) << 0x8 | uint(c2da_mem[652 + i * 4 + 2]) << 0x10 | uint(c2da_mem[652 + i * 4 + 3]) << 0x18))
    }
    MSG_WriteShort(c2da_fp + 128, int(uint_bits_to_float(uint(c2da_mem[cmd_0 + 12]) | uint(c2da_mem[cmd_0 + 13]) << 0x8 | uint(c2da_mem[cmd_0 + 14]) << 0x10 | uint(c2da_mem[cmd_0 + 15]) << 0x18)))
    MSG_WriteShort(c2da_fp + 128, int(uint_bits_to_float(uint(c2da_mem[cmd_0 + 16]) | uint(c2da_mem[cmd_0 + 17]) << 0x8 | uint(c2da_mem[cmd_0 + 18]) << 0x10 | uint(c2da_mem[cmd_0 + 19]) << 0x18)))
    MSG_WriteShort(c2da_fp + 128, int(uint_bits_to_float(uint(c2da_mem[cmd_0 + 20]) | uint(c2da_mem[cmd_0 + 21]) << 0x8 | uint(c2da_mem[cmd_0 + 22]) << 0x10 | uint(c2da_mem[cmd_0 + 23]) << 0x18)))
    bits = 0
    if ((int(uint(c2da_mem[7912]) | uint(c2da_mem[7913]) << 0x8 | uint(c2da_mem[7914]) << 0x10 | uint(c2da_mem[7915]) << 0x18) & 3) != 0) {
        bits |= 1
    }
    let c2da_fresh22 : int = int(uint(c2da_mem[7912]) | uint(c2da_mem[7913]) << 0x8 | uint(c2da_mem[7914]) << 0x10 | uint(c2da_mem[7915]) << 0x18) & ~2
    let c2da_fresh23 : uint = uint(c2da_fresh22)
    c2da_mem[7912] = uint8(c2da_fresh23)
    c2da_mem[7913] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[7914] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[7915] = uint8(c2da_fresh23 >> 0x18)
    if ((int(uint(c2da_mem[7880]) | uint(c2da_mem[7881]) << 0x8 | uint(c2da_mem[7882]) << 0x10 | uint(c2da_mem[7883]) << 0x18) & 3) != 0) {
        bits |= 2
    }
    let c2da_fresh24 : int = int(uint(c2da_mem[7880]) | uint(c2da_mem[7881]) << 0x8 | uint(c2da_mem[7882]) << 0x10 | uint(c2da_mem[7883]) << 0x18) & ~2
    let c2da_fresh25 : uint = uint(c2da_fresh24)
    c2da_mem[7880] = uint8(c2da_fresh25)
    c2da_mem[7881] = uint8(c2da_fresh25 >> 0x8)
    c2da_mem[7882] = uint8(c2da_fresh25 >> 0x10)
    c2da_mem[7883] = uint8(c2da_fresh25 >> 0x18)
    MSG_WriteByte(c2da_fp + 128, bits)
    MSG_WriteByte(c2da_fp + 128, in_impulse)
    in_impulse = 0
    if ((uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) != 0u) {
        return
    }
    let c2da_fresh26 : int = int(uint(c2da_mem[208]) | uint(c2da_mem[209]) << 0x8 | uint(c2da_mem[210]) << 0x10 | uint(c2da_mem[211]) << 0x18)
    let c2da_fresh27 : int = c2da_fresh26 + 1
    let c2da_fresh28 : uint = uint(c2da_fresh27)
    c2da_mem[208] = uint8(c2da_fresh28)
    c2da_mem[209] = uint8(c2da_fresh28 >> 0x8)
    c2da_mem[210] = uint8(c2da_fresh28 >> 0x10)
    c2da_mem[211] = uint8(c2da_fresh28 >> 0x18)
    if (c2da_fresh27 <= 2) {
        return
    }
    if (NET_SendUnreliableMessage(int(uint(c2da_mem[7808]) | uint(c2da_mem[7809]) << 0x8 | uint(c2da_mem[7810]) << 0x10 | uint(c2da_mem[7811]) << 0x18), c2da_fp + 128) == -1) {
        Con_Printf(698169, [])
        CL_Disconnect()
    }
    return
}

// This unit's static data, at heap offset 697728.
let private c2da_lin_static_cl_input_seg = fixed_array<int>(697728, 477)
let private c2da_lin_static_cl_input = fixed_array<uint64>(0x65707370755f6c63ul, 0x6300303032006465ul, 0x726177726f665f6cul, 0x6300646565707364ul, 0x70736b6361625f6cul, 0x735f6c6300646565ul, 0x6465657073656469ul, 0x5f6c630030353300ul, 0x6565707365766f6dul, 0x302e320079656b64ul, 0x737761795f6c6300ul, 0x3034310064656570ul, 0x637469705f6c6300ul, 0x3100646565707368ul, 0x6e615f6c63003035ul, 0x6465657073656c67ul, 0x352e310079656bul, 0x707565766f6d2bul, 0x707565766f6d2dul, 0x776f6465766f6d2bul, 0x6465766f6d2d006eul, 0x66656c2b006e776ful, 0x7466656c2d0074ul, 0x2d0074686769722bul, 0x662b007468676972ul, 0x2d0064726177726ful, 0x64726177726f66ul, 0x622d006b6361622bul, 0x6f6f6c2b006b6361ul, 0x6f6f6c2d0070756bul, 0x6f6f6c2b0070756bul, 0x6c2d006e776f646bul, 0x6e776f646b6f6ful, 0x6566617274732bul, 0x6566617274732dul, 0x66656c65766f6d2bul, 0x6c65766f6d2d0074ul, 0x766f6d2b00746665ul, 0x2d00746867697265ul, 0x6867697265766f6dul, 0x64656570732b0074ul, 0x64656570732d00ul, 0x6b63617474612bul, 0x6b63617474612dul, 0x73752d006573752bul, 0x706d756a2b0065ul, 0x6d6900706d756a2dul, 0x6b2b0065736c7570ul, 0x6c6b2d006b6f6f6cul, 0x6f6c6d2b006b6f6ful, 0x6f6f6c6d2d006b6ful, 0x206565726854006bul, 0x776f64207379656bul, 0x206120726f66206eul, 0xa216e6f74747562ul, 0x646e65535f4c4300ul, 0x6f6c203a65766f4dul, 0x6576726573207473ul, 0x63656e6e6f632072ul, 0xa6e6f6974ul)

[init]
def private c2da_lin_init_static_cl_input() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_cl_input_seg[s * 2]
        for (k in range(c2da_lin_static_cl_input_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_cl_input[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_cl_input_0 = fixed_array<uint8>(0x80, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8b, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_input_1 = fixed_array<uint8>(0x8f, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8b, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_input_2 = fixed_array<uint8>(0x9f, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8b, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_input_3 = fixed_array<uint8>(0xac, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb9, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_input_4 = fixed_array<uint8>(0xbd, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xcd, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_input_5 = fixed_array<uint8>(0xd1, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xdd, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_input_6 = fixed_array<uint8>(0xe1, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xef, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_cl_input_7 = fixed_array<uint8>(0xf3, 0xa5, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0xa6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_cl_input() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[9232 + i] = c2da_lin_extern_cl_input_0[i]
    }
    for (i in range(40)) {
        c2da_mem[9280 + i] = c2da_lin_extern_cl_input_1[i]
    }
    for (i in range(40)) {
        c2da_mem[9328 + i] = c2da_lin_extern_cl_input_2[i]
    }
    for (i in range(40)) {
        c2da_mem[9376 + i] = c2da_lin_extern_cl_input_3[i]
    }
    for (i in range(40)) {
        c2da_mem[9424 + i] = c2da_lin_extern_cl_input_4[i]
    }
    for (i in range(40)) {
        c2da_mem[9472 + i] = c2da_lin_extern_cl_input_5[i]
    }
    for (i in range(40)) {
        c2da_mem[9520 + i] = c2da_lin_extern_cl_input_6[i]
    }
    for (i in range(40)) {
        c2da_mem[9568 + i] = c2da_lin_extern_cl_input_7[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_cl_input() {
    if (length(c2da_fn_table0) < 36) {
        resize(c2da_fn_table0, 36)
    }
    c2da_fn_table0[35] = @@IN_MLookUp
    c2da_fn_table0[34] = @@IN_MLookDown
    c2da_fn_table0[33] = @@IN_KLookUp
    c2da_fn_table0[32] = @@IN_KLookDown
    c2da_fn_table0[31] = @@IN_Impulse
    c2da_fn_table0[30] = @@IN_JumpUp
    c2da_fn_table0[29] = @@IN_JumpDown
    c2da_fn_table0[28] = @@IN_UseUp
    c2da_fn_table0[27] = @@IN_UseDown
    c2da_fn_table0[26] = @@IN_AttackUp
    c2da_fn_table0[25] = @@IN_AttackDown
    c2da_fn_table0[24] = @@IN_SpeedUp
    c2da_fn_table0[23] = @@IN_SpeedDown
    c2da_fn_table0[22] = @@IN_MoverightUp
    c2da_fn_table0[21] = @@IN_MoverightDown
    c2da_fn_table0[20] = @@IN_MoveleftUp
    c2da_fn_table0[19] = @@IN_MoveleftDown
    c2da_fn_table0[18] = @@IN_StrafeUp
    c2da_fn_table0[17] = @@IN_StrafeDown
    c2da_fn_table0[16] = @@IN_LookdownUp
    c2da_fn_table0[15] = @@IN_LookdownDown
    c2da_fn_table0[14] = @@IN_LookupUp
    c2da_fn_table0[13] = @@IN_LookupDown
    c2da_fn_table0[12] = @@IN_BackUp
    c2da_fn_table0[11] = @@IN_BackDown
    c2da_fn_table0[10] = @@IN_ForwardUp
    c2da_fn_table0[9] = @@IN_ForwardDown
    c2da_fn_table0[8] = @@IN_RightUp
    c2da_fn_table0[7] = @@IN_RightDown
    c2da_fn_table0[6] = @@IN_LeftUp
    c2da_fn_table0[5] = @@IN_LeftDown
    c2da_fn_table0[4] = @@IN_DownUp
    c2da_fn_table0[3] = @@IN_DownDown
    c2da_fn_table0[2] = @@IN_UpUp
    c2da_fn_table0[1] = @@IN_UpDown
}

[init]
def private c2da_lin_relink_init_cl_input() {
    c2da_relink_cl_input()
}
