[export, sideeffects]
def IN_Init() {
    Cvar_RegisterVariable(244176)
    Cvar_RegisterVariable(244224)
    Cvar_RegisterVariable(244272)
    Cvar_RegisterVariable(244320)
    Cvar_RegisterVariable(244368)
    Cvar_RegisterVariable(244416)
    Cvar_RegisterVariable(244464)
    Cvar_RegisterVariable(244512)
    Cvar_RegisterVariable(244560)
    Cvar_RegisterVariable(244608)
    Cvar_RegisterVariable(244656)
    Cvar_RegisterVariable(244704)
    Cvar_RegisterVariable(244752)
    Cvar_RegisterVariable(244800)
    Cvar_RegisterVariable(244848)
    Cvar_RegisterVariable(244896)
    Cmd_AddCommand(718659, 97)
    joy_advancedinit = 0u
    return
}
var joy_advancedinit : uint = default<uint>

[export, sideeffects]
def Joy_AdvancedUpdate_f() {
    var dwTemp : int
    for (i in range(0, 6)) {
        dwAxisMap[i] = 0
        dwControlMap[i] = 0
    }
    if (double(uint_bits_to_float(uint(c2da_mem[244248]) | uint(c2da_mem[244249]) << 0x8 | uint(c2da_mem[244250]) << 0x10 | uint(c2da_mem[244251]) << 0x18)) == 0.0lf) {
        dwAxisMap[0] = 4
        dwAxisMap[1] = 1
    } else {
        dwTemp = int(uint_bits_to_float(uint(c2da_mem[244296]) | uint(c2da_mem[244297]) << 0x8 | uint(c2da_mem[244298]) << 0x10 | uint(c2da_mem[244299]) << 0x18))
        dwAxisMap[0] = dwTemp & 15
        dwControlMap[0] = dwTemp & 16
        dwTemp = int(uint_bits_to_float(uint(c2da_mem[244344]) | uint(c2da_mem[244345]) << 0x8 | uint(c2da_mem[244346]) << 0x10 | uint(c2da_mem[244347]) << 0x18))
        dwAxisMap[1] = dwTemp & 15
        dwControlMap[1] = dwTemp & 16
        dwTemp = int(uint_bits_to_float(uint(c2da_mem[244392]) | uint(c2da_mem[244393]) << 0x8 | uint(c2da_mem[244394]) << 0x10 | uint(c2da_mem[244395]) << 0x18))
        dwAxisMap[2] = dwTemp & 15
        dwControlMap[2] = dwTemp & 16
        dwTemp = int(uint_bits_to_float(uint(c2da_mem[244440]) | uint(c2da_mem[244441]) << 0x8 | uint(c2da_mem[244442]) << 0x10 | uint(c2da_mem[244443]) << 0x18))
        dwAxisMap[3] = dwTemp & 15
        dwControlMap[3] = dwTemp & 16
        dwTemp = int(uint_bits_to_float(uint(c2da_mem[244488]) | uint(c2da_mem[244489]) << 0x8 | uint(c2da_mem[244490]) << 0x10 | uint(c2da_mem[244491]) << 0x18))
        dwAxisMap[4] = dwTemp & 15
        dwControlMap[4] = dwTemp & 16
        dwTemp = int(uint_bits_to_float(uint(c2da_mem[244536]) | uint(c2da_mem[244537]) << 0x8 | uint(c2da_mem[244538]) << 0x10 | uint(c2da_mem[244539]) << 0x18))
        dwAxisMap[5] = dwTemp & 15
        dwControlMap[5] = dwTemp & 16
    }
    return
}
var dwControlMap : int[6]

var dwAxisMap : int[6]

[export, sideeffects]
def IN_Shutdown() {
    return
}
[export, sideeffects]
def IN_Commands() {
    let c2da_saved_sp : int = c2da_lin_sp
    IN_Commands_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def IN_Move(var cmd_0 : int) {
    IN_MouseMove(cmd_0)
    IN_JoyMove(cmd_0)
    return
}
[export, sideeffects]
def IN_JoyMove(var cmd_1 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    IN_JoyMove_c2da_frame(cmd_1, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def IN_MouseMove(var cmd_2 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    IN_MouseMove_c2da_frame(cmd_2, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
var mouse_y : float = default<float>

var mouse_x : float = default<float>

[sideeffects]
def private IN_Commands_c2da_frame(c2da_fp : int) {
    while (QG_GetKey(c2da_fp, c2da_fp + 16) != 0) {
        Key_Event(int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18), uint(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18)))
    }
    return
}
[sideeffects]
def private IN_JoyMove_c2da_frame(var cmd_1 : int; c2da_fp : int) {
    var c2da_fresh0 : int
    var speed : float
    var aspeed : float
    var fAxisValue : float
    var fTemp : float
    c2da_mem[c2da_fp] = 0u8
    c2da_mem[c2da_fp + 1] = 0u8
    c2da_mem[c2da_fp + 2] = 0u8
    c2da_mem[c2da_fp + 3] = 0u8
    c2da_mem[c2da_fp + 4] = 0u8
    c2da_mem[c2da_fp + 5] = 0u8
    c2da_mem[c2da_fp + 6] = 0u8
    c2da_mem[c2da_fp + 7] = 0u8
    c2da_mem[c2da_fp + 8] = 0u8
    c2da_mem[c2da_fp + 9] = 0u8
    c2da_mem[c2da_fp + 10] = 0u8
    c2da_mem[c2da_fp + 11] = 0u8
    c2da_mem[c2da_fp + 12] = 0u8
    c2da_mem[c2da_fp + 13] = 0u8
    c2da_mem[c2da_fp + 14] = 0u8
    c2da_mem[c2da_fp + 15] = 0u8
    c2da_mem[c2da_fp + 16] = 0u8
    c2da_mem[c2da_fp + 17] = 0u8
    c2da_mem[c2da_fp + 18] = 0u8
    c2da_mem[c2da_fp + 19] = 0u8
    c2da_mem[c2da_fp + 20] = 0u8
    c2da_mem[c2da_fp + 21] = 0u8
    c2da_mem[c2da_fp + 22] = 0u8
    c2da_mem[c2da_fp + 23] = 0u8
    if (joy_advancedinit != 1u) {
        Joy_AdvancedUpdate_f()
        joy_advancedinit = 1u
    }
    if (uint_bits_to_float(uint(c2da_mem[244200]) | uint(c2da_mem[244201]) << 0x8 | uint(c2da_mem[244202]) << 0x10 | uint(c2da_mem[244203]) << 0x18) == 0.0) {
        return
    }
    QG_GetJoyAxes(c2da_fp)
    if ((int(uint(c2da_mem[7928]) | uint(c2da_mem[7929]) << 0x8 | uint(c2da_mem[7930]) << 0x10 | uint(c2da_mem[7931]) << 0x18) & 1) != 0) {
        speed = uint_bits_to_float(uint(c2da_mem[9448]) | uint(c2da_mem[9449]) << 0x8 | uint(c2da_mem[9450]) << 0x10 | uint(c2da_mem[9451]) << 0x18)
    } else {
        speed = 1.0
    }
    aspeed = float(double(speed) * host_frametime)
    for (i_0 in range(0, 6)) {
        fAxisValue = uint_bits_to_float(uint(c2da_mem[c2da_fp + i_0 * 4]) | uint(c2da_mem[c2da_fp + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + i_0 * 4 + 3]) << 0x18)
        c2da_fresh0 = dwAxisMap[i_0]
        if (c2da_fresh0 == 1) {
            if (double(uint_bits_to_float(uint(c2da_mem[244248]) | uint(c2da_mem[244249]) << 0x8 | uint(c2da_mem[244250]) << 0x10 | uint(c2da_mem[244251]) << 0x18)) == 0.0lf && (int(uint(c2da_mem[7848]) | uint(c2da_mem[7849]) << 0x8 | uint(c2da_mem[7850]) << 0x10 | uint(c2da_mem[7851]) << 0x18) & 1) != 0) {
                if (c2da_std_fabs(double(fAxisValue)) > double(uint_bits_to_float(uint(c2da_mem[244680]) | uint(c2da_mem[244681]) << 0x8 | uint(c2da_mem[244682]) << 0x10 | uint(c2da_mem[244683]) << 0x18))) {
                    if (double(uint_bits_to_float(uint(c2da_mem[9880]) | uint(c2da_mem[9881]) << 0x8 | uint(c2da_mem[9882]) << 0x10 | uint(c2da_mem[9883]) << 0x18)) < 0.0lf) {
                        let c2da_fresh1 : float = uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18) - float(fAxisValue * uint_bits_to_float(uint(c2da_mem[244872]) | uint(c2da_mem[244873]) << 0x8 | uint(c2da_mem[244874]) << 0x10 | uint(c2da_mem[244875]) << 0x18) * aspeed * uint_bits_to_float(uint(c2da_mem[9544]) | uint(c2da_mem[9545]) << 0x8 | uint(c2da_mem[9546]) << 0x10 | uint(c2da_mem[9547]) << 0x18))
                        let c2da_fresh2 : uint = float_bits_to_uint(c2da_fresh1)
                        c2da_mem[652 + 0 * 4] = uint8(c2da_fresh2)
                        c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh2 >> 0x8)
                        c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh2 >> 0x10)
                        c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh2 >> 0x18)
                    } else {
                        let c2da_fresh3 : float = uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18) + float(fAxisValue * uint_bits_to_float(uint(c2da_mem[244872]) | uint(c2da_mem[244873]) << 0x8 | uint(c2da_mem[244874]) << 0x10 | uint(c2da_mem[244875]) << 0x18) * aspeed * uint_bits_to_float(uint(c2da_mem[9544]) | uint(c2da_mem[9545]) << 0x8 | uint(c2da_mem[9546]) << 0x10 | uint(c2da_mem[9547]) << 0x18))
                        let c2da_fresh4 : uint = float_bits_to_uint(c2da_fresh3)
                        c2da_mem[652 + 0 * 4] = uint8(c2da_fresh4)
                        c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh4 >> 0x8)
                        c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh4 >> 0x10)
                        c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh4 >> 0x18)
                    }
                    V_StopPitchDrift()
                } elif (double(uint_bits_to_float(uint(c2da_mem[9736]) | uint(c2da_mem[9737]) << 0x8 | uint(c2da_mem[9738]) << 0x10 | uint(c2da_mem[9739]) << 0x18)) == 0.0lf) {
                    V_StopPitchDrift()
                }
            } elif (c2da_std_fabs(double(fAxisValue)) > double(uint_bits_to_float(uint(c2da_mem[244584]) | uint(c2da_mem[244585]) << 0x8 | uint(c2da_mem[244586]) << 0x10 | uint(c2da_mem[244587]) << 0x18))) {
                let c2da_fresh5 : float = uint_bits_to_float(uint(c2da_mem[cmd_1 + 12]) | uint(c2da_mem[cmd_1 + 13]) << 0x8 | uint(c2da_mem[cmd_1 + 14]) << 0x10 | uint(c2da_mem[cmd_1 + 15]) << 0x18) + float(fAxisValue * uint_bits_to_float(uint(c2da_mem[244776]) | uint(c2da_mem[244777]) << 0x8 | uint(c2da_mem[244778]) << 0x10 | uint(c2da_mem[244779]) << 0x18) * speed * uint_bits_to_float(uint(c2da_mem[9304]) | uint(c2da_mem[9305]) << 0x8 | uint(c2da_mem[9306]) << 0x10 | uint(c2da_mem[9307]) << 0x18))
                let c2da_fresh6 : uint = float_bits_to_uint(c2da_fresh5)
                c2da_mem[cmd_1 + 12] = uint8(c2da_fresh6)
                c2da_mem[cmd_1 + 13] = uint8(c2da_fresh6 >> 0x8)
                c2da_mem[cmd_1 + 14] = uint8(c2da_fresh6 >> 0x10)
                c2da_mem[cmd_1 + 15] = uint8(c2da_fresh6 >> 0x18)
            }
        } elif (c2da_fresh0 == 3) {
            if (c2da_std_fabs(double(fAxisValue)) > double(uint_bits_to_float(uint(c2da_mem[244632]) | uint(c2da_mem[244633]) << 0x8 | uint(c2da_mem[244634]) << 0x10 | uint(c2da_mem[244635]) << 0x18))) {
                let c2da_fresh7 : float = uint_bits_to_float(uint(c2da_mem[cmd_1 + 16]) | uint(c2da_mem[cmd_1 + 17]) << 0x8 | uint(c2da_mem[cmd_1 + 18]) << 0x10 | uint(c2da_mem[cmd_1 + 19]) << 0x18) + float(fAxisValue * uint_bits_to_float(uint(c2da_mem[244824]) | uint(c2da_mem[244825]) << 0x8 | uint(c2da_mem[244826]) << 0x10 | uint(c2da_mem[244827]) << 0x18) * speed * uint_bits_to_float(uint(c2da_mem[9400]) | uint(c2da_mem[9401]) << 0x8 | uint(c2da_mem[9402]) << 0x10 | uint(c2da_mem[9403]) << 0x18))
                let c2da_fresh8 : uint = float_bits_to_uint(c2da_fresh7)
                c2da_mem[cmd_1 + 16] = uint8(c2da_fresh8)
                c2da_mem[cmd_1 + 17] = uint8(c2da_fresh8 >> 0x8)
                c2da_mem[cmd_1 + 18] = uint8(c2da_fresh8 >> 0x10)
                c2da_mem[cmd_1 + 19] = uint8(c2da_fresh8 >> 0x18)
            }
        } elif (c2da_fresh0 == 4) {
            if ((int(uint(c2da_mem[7976]) | uint(c2da_mem[7977]) << 0x8 | uint(c2da_mem[7978]) << 0x10 | uint(c2da_mem[7979]) << 0x18) & 1) != 0 || uint_bits_to_float(uint(c2da_mem[9784]) | uint(c2da_mem[9785]) << 0x8 | uint(c2da_mem[9786]) << 0x10 | uint(c2da_mem[9787]) << 0x18) != 0.0 && (int(uint(c2da_mem[7848]) | uint(c2da_mem[7849]) << 0x8 | uint(c2da_mem[7850]) << 0x10 | uint(c2da_mem[7851]) << 0x18) & 1) != 0) {
                if (c2da_std_fabs(double(fAxisValue)) > double(uint_bits_to_float(uint(c2da_mem[244632]) | uint(c2da_mem[244633]) << 0x8 | uint(c2da_mem[244634]) << 0x10 | uint(c2da_mem[244635]) << 0x18))) {
                    let c2da_fresh9 : float = uint_bits_to_float(uint(c2da_mem[cmd_1 + 16]) | uint(c2da_mem[cmd_1 + 17]) << 0x8 | uint(c2da_mem[cmd_1 + 18]) << 0x10 | uint(c2da_mem[cmd_1 + 19]) << 0x18) - float(fAxisValue * uint_bits_to_float(uint(c2da_mem[244824]) | uint(c2da_mem[244825]) << 0x8 | uint(c2da_mem[244826]) << 0x10 | uint(c2da_mem[244827]) << 0x18) * speed * uint_bits_to_float(uint(c2da_mem[9400]) | uint(c2da_mem[9401]) << 0x8 | uint(c2da_mem[9402]) << 0x10 | uint(c2da_mem[9403]) << 0x18))
                    let c2da_fresh10 : uint = float_bits_to_uint(c2da_fresh9)
                    c2da_mem[cmd_1 + 16] = uint8(c2da_fresh10)
                    c2da_mem[cmd_1 + 17] = uint8(c2da_fresh10 >> 0x8)
                    c2da_mem[cmd_1 + 18] = uint8(c2da_fresh10 >> 0x10)
                    c2da_mem[cmd_1 + 19] = uint8(c2da_fresh10 >> 0x18)
                }
            } elif (c2da_std_fabs(double(fAxisValue)) > double(uint_bits_to_float(uint(c2da_mem[244728]) | uint(c2da_mem[244729]) << 0x8 | uint(c2da_mem[244730]) << 0x10 | uint(c2da_mem[244731]) << 0x18))) {
                if (dwControlMap[i_0] == 0) {
                    let c2da_fresh11 : float = uint_bits_to_float(uint(c2da_mem[652 + 1 * 4]) | uint(c2da_mem[652 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 1 * 4 + 3]) << 0x18) + float(fAxisValue * uint_bits_to_float(uint(c2da_mem[244920]) | uint(c2da_mem[244921]) << 0x8 | uint(c2da_mem[244922]) << 0x10 | uint(c2da_mem[244923]) << 0x18) * aspeed * uint_bits_to_float(uint(c2da_mem[9496]) | uint(c2da_mem[9497]) << 0x8 | uint(c2da_mem[9498]) << 0x10 | uint(c2da_mem[9499]) << 0x18))
                    let c2da_fresh12 : uint = float_bits_to_uint(c2da_fresh11)
                    c2da_mem[652 + 1 * 4] = uint8(c2da_fresh12)
                    c2da_mem[652 + 1 * 4 + 1] = uint8(c2da_fresh12 >> 0x8)
                    c2da_mem[652 + 1 * 4 + 2] = uint8(c2da_fresh12 >> 0x10)
                    c2da_mem[652 + 1 * 4 + 3] = uint8(c2da_fresh12 >> 0x18)
                } else {
                    let c2da_fresh13 : float = float(double(uint_bits_to_float(uint(c2da_mem[652 + 1 * 4]) | uint(c2da_mem[652 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 1 * 4 + 3]) << 0x18)) + double(fAxisValue * uint_bits_to_float(uint(c2da_mem[244920]) | uint(c2da_mem[244921]) << 0x8 | uint(c2da_mem[244922]) << 0x10 | uint(c2da_mem[244923]) << 0x18) * speed) * 180.0lf)
                    let c2da_fresh14 : uint = float_bits_to_uint(c2da_fresh13)
                    c2da_mem[652 + 1 * 4] = uint8(c2da_fresh14)
                    c2da_mem[652 + 1 * 4 + 1] = uint8(c2da_fresh14 >> 0x8)
                    c2da_mem[652 + 1 * 4 + 2] = uint8(c2da_fresh14 >> 0x10)
                    c2da_mem[652 + 1 * 4 + 3] = uint8(c2da_fresh14 >> 0x18)
                }
            }
        } elif (c2da_fresh0 == 2) {
            if ((int(uint(c2da_mem[7848]) | uint(c2da_mem[7849]) << 0x8 | uint(c2da_mem[7850]) << 0x10 | uint(c2da_mem[7851]) << 0x18) & 1) != 0) {
                if (c2da_std_fabs(double(fAxisValue)) > double(uint_bits_to_float(uint(c2da_mem[244680]) | uint(c2da_mem[244681]) << 0x8 | uint(c2da_mem[244682]) << 0x10 | uint(c2da_mem[244683]) << 0x18))) {
                    if (dwControlMap[i_0] == 0) {
                        let c2da_fresh15 : float = uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18) + float(fAxisValue * uint_bits_to_float(uint(c2da_mem[244872]) | uint(c2da_mem[244873]) << 0x8 | uint(c2da_mem[244874]) << 0x10 | uint(c2da_mem[244875]) << 0x18) * aspeed * uint_bits_to_float(uint(c2da_mem[9544]) | uint(c2da_mem[9545]) << 0x8 | uint(c2da_mem[9546]) << 0x10 | uint(c2da_mem[9547]) << 0x18))
                        let c2da_fresh16 : uint = float_bits_to_uint(c2da_fresh15)
                        c2da_mem[652 + 0 * 4] = uint8(c2da_fresh16)
                        c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh16 >> 0x8)
                        c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh16 >> 0x10)
                        c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh16 >> 0x18)
                    } else {
                        let c2da_fresh17 : float = float(double(uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18)) + double(fAxisValue * uint_bits_to_float(uint(c2da_mem[244872]) | uint(c2da_mem[244873]) << 0x8 | uint(c2da_mem[244874]) << 0x10 | uint(c2da_mem[244875]) << 0x18) * speed) * 180.0lf)
                        let c2da_fresh18 : uint = float_bits_to_uint(c2da_fresh17)
                        c2da_mem[652 + 0 * 4] = uint8(c2da_fresh18)
                        c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh18 >> 0x8)
                        c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh18 >> 0x10)
                        c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh18 >> 0x18)
                    }
                    V_StopPitchDrift()
                } elif (double(uint_bits_to_float(uint(c2da_mem[9736]) | uint(c2da_mem[9737]) << 0x8 | uint(c2da_mem[9738]) << 0x10 | uint(c2da_mem[9739]) << 0x18)) == 0.0lf) {
                    V_StopPitchDrift()
                }
            }
        }
    }
    if (double(uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18)) > 80.0lf) {
        let c2da_fresh19 : float = 80.0
        let c2da_fresh20 : uint = float_bits_to_uint(c2da_fresh19)
        c2da_mem[652 + 0 * 4] = uint8(c2da_fresh20)
        c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh20 >> 0x18)
    }
    if (double(uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18)) < -70.0lf) {
        let c2da_fresh21 : float = float(-70.0lf)
        let c2da_fresh22 : uint = float_bits_to_uint(c2da_fresh21)
        c2da_mem[652 + 0 * 4] = uint8(c2da_fresh22)
        c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh22 >> 0x8)
        c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh22 >> 0x10)
        c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh22 >> 0x18)
    }
    return
}
[sideeffects]
def private IN_MouseMove_c2da_frame(var cmd_2 : int; c2da_fp : int) {
    QG_GetMouseMove(c2da_fp, c2da_fp + 16)
    mouse_x = float(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18))
    mouse_y = float(int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18))
    let c2da_fresh37 : float = uint_bits_to_float(uint(c2da_mem[9832]) | uint(c2da_mem[9833]) << 0x8 | uint(c2da_mem[9834]) << 0x10 | uint(c2da_mem[9835]) << 0x18)
    mouse_x *= c2da_fresh37
    mouse_y *= c2da_fresh37
    if ((int(uint(c2da_mem[7976]) | uint(c2da_mem[7977]) << 0x8 | uint(c2da_mem[7978]) << 0x10 | uint(c2da_mem[7979]) << 0x18) & 1) != 0 || uint_bits_to_float(uint(c2da_mem[9784]) | uint(c2da_mem[9785]) << 0x8 | uint(c2da_mem[9786]) << 0x10 | uint(c2da_mem[9787]) << 0x18) != 0.0 && (int(uint(c2da_mem[7848]) | uint(c2da_mem[7849]) << 0x8 | uint(c2da_mem[7850]) << 0x10 | uint(c2da_mem[7851]) << 0x18) & 1) != 0) {
        let c2da_fresh23 : float = uint_bits_to_float(uint(c2da_mem[cmd_2 + 16]) | uint(c2da_mem[cmd_2 + 17]) << 0x8 | uint(c2da_mem[cmd_2 + 18]) << 0x10 | uint(c2da_mem[cmd_2 + 19]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[10024]) | uint(c2da_mem[10025]) << 0x8 | uint(c2da_mem[10026]) << 0x10 | uint(c2da_mem[10027]) << 0x18) * mouse_x)
        let c2da_fresh24 : uint = float_bits_to_uint(c2da_fresh23)
        c2da_mem[cmd_2 + 16] = uint8(c2da_fresh24)
        c2da_mem[cmd_2 + 17] = uint8(c2da_fresh24 >> 0x8)
        c2da_mem[cmd_2 + 18] = uint8(c2da_fresh24 >> 0x10)
        c2da_mem[cmd_2 + 19] = uint8(c2da_fresh24 >> 0x18)
    } else {
        let c2da_fresh25 : float = uint_bits_to_float(uint(c2da_mem[652 + 1 * 4]) | uint(c2da_mem[652 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 1 * 4 + 3]) << 0x18) - float(uint_bits_to_float(uint(c2da_mem[9928]) | uint(c2da_mem[9929]) << 0x8 | uint(c2da_mem[9930]) << 0x10 | uint(c2da_mem[9931]) << 0x18) * mouse_x)
        let c2da_fresh26 : uint = float_bits_to_uint(c2da_fresh25)
        c2da_mem[652 + 1 * 4] = uint8(c2da_fresh26)
        c2da_mem[652 + 1 * 4 + 1] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[652 + 1 * 4 + 2] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[652 + 1 * 4 + 3] = uint8(c2da_fresh26 >> 0x18)
    }
    if ((int(uint(c2da_mem[7848]) | uint(c2da_mem[7849]) << 0x8 | uint(c2da_mem[7850]) << 0x10 | uint(c2da_mem[7851]) << 0x18) & 1) != 0) {
        V_StopPitchDrift()
    }
    if ((int(uint(c2da_mem[7848]) | uint(c2da_mem[7849]) << 0x8 | uint(c2da_mem[7850]) << 0x10 | uint(c2da_mem[7851]) << 0x18) & 1) != 0 && (int(uint(c2da_mem[7976]) | uint(c2da_mem[7977]) << 0x8 | uint(c2da_mem[7978]) << 0x10 | uint(c2da_mem[7979]) << 0x18) & 1) == 0) {
        let c2da_fresh27 : float = uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[9880]) | uint(c2da_mem[9881]) << 0x8 | uint(c2da_mem[9882]) << 0x10 | uint(c2da_mem[9883]) << 0x18) * mouse_y)
        let c2da_fresh28 : uint = float_bits_to_uint(c2da_fresh27)
        c2da_mem[652 + 0 * 4] = uint8(c2da_fresh28)
        c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh28 >> 0x8)
        c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh28 >> 0x10)
        c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh28 >> 0x18)
        if (c2da_fresh27 > 80.0) {
            let c2da_fresh29 : float = 80.0
            let c2da_fresh30 : uint = float_bits_to_uint(c2da_fresh29)
            c2da_mem[652 + 0 * 4] = uint8(c2da_fresh30)
            c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh30 >> 0x8)
            c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh30 >> 0x10)
            c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh30 >> 0x18)
        }
        if (uint_bits_to_float(uint(c2da_mem[652 + 0 * 4]) | uint(c2da_mem[652 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[652 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[652 + 0 * 4 + 3]) << 0x18) < -70.0) {
            let c2da_fresh31 : float = -70.0
            let c2da_fresh32 : uint = float_bits_to_uint(c2da_fresh31)
            c2da_mem[652 + 0 * 4] = uint8(c2da_fresh32)
            c2da_mem[652 + 0 * 4 + 1] = uint8(c2da_fresh32 >> 0x8)
            c2da_mem[652 + 0 * 4 + 2] = uint8(c2da_fresh32 >> 0x10)
            c2da_mem[652 + 0 * 4 + 3] = uint8(c2da_fresh32 >> 0x18)
        }
    } elif ((int(uint(c2da_mem[7976]) | uint(c2da_mem[7977]) << 0x8 | uint(c2da_mem[7978]) << 0x10 | uint(c2da_mem[7979]) << 0x18) & 1) != 0 && uint(noclip_anglehack) != 0x0) {
        let c2da_fresh33 : float = uint_bits_to_float(uint(c2da_mem[cmd_2 + 20]) | uint(c2da_mem[cmd_2 + 21]) << 0x8 | uint(c2da_mem[cmd_2 + 22]) << 0x10 | uint(c2da_mem[cmd_2 + 23]) << 0x18) - float(uint_bits_to_float(uint(c2da_mem[9976]) | uint(c2da_mem[9977]) << 0x8 | uint(c2da_mem[9978]) << 0x10 | uint(c2da_mem[9979]) << 0x18) * mouse_y)
        let c2da_fresh34 : uint = float_bits_to_uint(c2da_fresh33)
        c2da_mem[cmd_2 + 20] = uint8(c2da_fresh34)
        c2da_mem[cmd_2 + 21] = uint8(c2da_fresh34 >> 0x8)
        c2da_mem[cmd_2 + 22] = uint8(c2da_fresh34 >> 0x10)
        c2da_mem[cmd_2 + 23] = uint8(c2da_fresh34 >> 0x18)
    } else {
        let c2da_fresh35 : float = uint_bits_to_float(uint(c2da_mem[cmd_2 + 12]) | uint(c2da_mem[cmd_2 + 13]) << 0x8 | uint(c2da_mem[cmd_2 + 14]) << 0x10 | uint(c2da_mem[cmd_2 + 15]) << 0x18) - float(uint_bits_to_float(uint(c2da_mem[9976]) | uint(c2da_mem[9977]) << 0x8 | uint(c2da_mem[9978]) << 0x10 | uint(c2da_mem[9979]) << 0x18) * mouse_y)
        let c2da_fresh36 : uint = float_bits_to_uint(c2da_fresh35)
        c2da_mem[cmd_2 + 12] = uint8(c2da_fresh36)
        c2da_mem[cmd_2 + 13] = uint8(c2da_fresh36 >> 0x8)
        c2da_mem[cmd_2 + 14] = uint8(c2da_fresh36 >> 0x10)
        c2da_mem[cmd_2 + 15] = uint8(c2da_fresh36 >> 0x18)
    }
    return
}

// This unit's static data, at heap offset 718400.
let private c2da_lin_static_in_null_seg = fixed_array<int>(718400, 276)
let private c2da_lin_static_in_null = fixed_array<uint64>(0x6b63697473796f6aul, 0x6461796f6a003000ul, 0x6a006465636e6176ul, 0x697861766461796ful, 0x6461796f6a007873ul, 0x6a00797369786176ul, 0x697861766461796ful, 0x6461796f6a007a73ul, 0x6a00727369786176ul, 0x697861766461796ful, 0x6461796f6a007573ul, 0x6a00767369786176ul, 0x726177726f66796ful, 0x6f68736572687464ul, 0x35312e3000646cul, 0x7465646973796f6aul, 0x646c6f6873657268ul, 0x63746970796f6a00ul, 0x6f68736572687468ul, 0x6179796f6a00646cul, 0x6f68736572687477ul, 0x6f66796f6a00646cul, 0x6e65736472617772ul, 0x7974697669746973ul, 0x6f6a00302e312d00ul, 0x6e65736564697379ul, 0x7974697669746973ul, 0x63746970796f6a00ul, 0x697469736e657368ul, 0x302e310079746976ul, 0x73776179796f6a00ul, 0x6976697469736e65ul, 0x6461796f6a007974ul, 0x70756465636e6176ul, 0x65746164ul)

[init]
def private c2da_lin_init_static_in_null() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_in_null_seg[s * 2]
        for (k in range(c2da_lin_static_in_null_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_in_null[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_in_null_0 = fixed_array<uint8>(0x40, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x49, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_1 = fixed_array<uint8>(0x4b, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x49, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_2 = fixed_array<uint8>(0x57, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x49, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_3 = fixed_array<uint8>(0x63, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x49, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_4 = fixed_array<uint8>(0x6f, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x49, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_5 = fixed_array<uint8>(0x7b, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x49, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_6 = fixed_array<uint8>(0x87, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x49, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_7 = fixed_array<uint8>(0x93, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x49, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_8 = fixed_array<uint8>(0x9f, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb3, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_9 = fixed_array<uint8>(0xb8, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb3, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_10 = fixed_array<uint8>(0xc9, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb3, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_11 = fixed_array<uint8>(0xdb, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb3, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_12 = fixed_array<uint8>(0xeb, 0xf6, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xf7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_13 = fixed_array<uint8>(0x6, 0xf7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xf7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_14 = fixed_array<uint8>(0x19, 0xf7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2d, 0xf7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_in_null_15 = fixed_array<uint8>(0x31, 0xf7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xf7, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_in_null() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[244176 + i] = c2da_lin_extern_in_null_0[i]
    }
    for (i in range(40)) {
        c2da_mem[244224 + i] = c2da_lin_extern_in_null_1[i]
    }
    for (i in range(40)) {
        c2da_mem[244272 + i] = c2da_lin_extern_in_null_2[i]
    }
    for (i in range(40)) {
        c2da_mem[244320 + i] = c2da_lin_extern_in_null_3[i]
    }
    for (i in range(40)) {
        c2da_mem[244368 + i] = c2da_lin_extern_in_null_4[i]
    }
    for (i in range(40)) {
        c2da_mem[244416 + i] = c2da_lin_extern_in_null_5[i]
    }
    for (i in range(40)) {
        c2da_mem[244464 + i] = c2da_lin_extern_in_null_6[i]
    }
    for (i in range(40)) {
        c2da_mem[244512 + i] = c2da_lin_extern_in_null_7[i]
    }
    for (i in range(40)) {
        c2da_mem[244560 + i] = c2da_lin_extern_in_null_8[i]
    }
    for (i in range(40)) {
        c2da_mem[244608 + i] = c2da_lin_extern_in_null_9[i]
    }
    for (i in range(40)) {
        c2da_mem[244656 + i] = c2da_lin_extern_in_null_10[i]
    }
    for (i in range(40)) {
        c2da_mem[244704 + i] = c2da_lin_extern_in_null_11[i]
    }
    for (i in range(40)) {
        c2da_mem[244752 + i] = c2da_lin_extern_in_null_12[i]
    }
    for (i in range(40)) {
        c2da_mem[244800 + i] = c2da_lin_extern_in_null_13[i]
    }
    for (i in range(40)) {
        c2da_mem[244848 + i] = c2da_lin_extern_in_null_14[i]
    }
    for (i in range(40)) {
        c2da_mem[244896 + i] = c2da_lin_extern_in_null_15[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_in_null() {
    if (length(c2da_fn_table0) < 98) {
        resize(c2da_fn_table0, 98)
    }
    c2da_fn_table0[97] = @@Joy_AdvancedUpdate_f
}

[init]
def private c2da_lin_relink_init_in_null() {
    c2da_relink_in_null()
}
