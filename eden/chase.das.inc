[export, sideeffects]
def Chase_Init() {
    Cvar_RegisterVariable(16)
    Cvar_RegisterVariable(64)
    Cvar_RegisterVariable(112)
    Cvar_RegisterVariable(160)
    return
}
[export, sideeffects]
def Chase_Reset() {
    return
}
[export, sideeffects]
def Chase_Update() {
    let c2da_saved_sp : int = c2da_lin_sp
    Chase_Update_c2da_frame(c2da_lin_enter(80))
    c2da_lin_sp = c2da_saved_sp
}
var chase_dest : vec3_t = default<vec3_t>

[export, sideeffects]
def TraceLine(var start : int; var end : int; var impact : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    TraceLine_c2da_frame(start, end, impact, c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
var chase_pos : vec3_t = default<vec3_t>

var chase_angles : vec3_t = default<vec3_t>

var chase_dest_angles : vec3_t = default<vec3_t>

[sideeffects]
def private Chase_Update_c2da_frame(c2da_fp : int) {
    var dist : float
    AngleVectors(652, c2da_fp, c2da_fp + 16, c2da_fp + 32)
    for (i in range(0, 3)) {
        chase_dest[i] = uint_bits_to_float(uint(c2da_mem[5320 + i * 4]) | uint(c2da_mem[5320 + i * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + i * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + i * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + i * 4]) | uint(c2da_mem[c2da_fp + i * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + i * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + i * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[40]) | uint(c2da_mem[41]) << 0x8 | uint(c2da_mem[42]) << 0x10 | uint(c2da_mem[43]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + i * 4]) | uint(c2da_mem[c2da_fp + 16 + i * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + i * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + i * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[136]) | uint(c2da_mem[137]) << 0x8 | uint(c2da_mem[138]) << 0x10 | uint(c2da_mem[139]) << 0x18)
    }
    chase_dest[2] = uint_bits_to_float(uint(c2da_mem[5320 + 2 * 4]) | uint(c2da_mem[5320 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[88]) | uint(c2da_mem[89]) << 0x8 | uint(c2da_mem[90]) << 0x10 | uint(c2da_mem[91]) << 0x18)
    VectorMA(5320, 4096.0, c2da_fp, c2da_fp + 48)
    TraceLine(5320, c2da_fp + 48, c2da_fp + 64)
    let c2da_fresh0 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 0 * 4]) | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[5320 + 0 * 4]) | uint(c2da_mem[5320 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh1 : uint = float_bits_to_uint(c2da_fresh0)
    c2da_mem[c2da_fp + 64 + 0 * 4] = uint8(c2da_fresh1)
    c2da_mem[c2da_fp + 64 + 0 * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[c2da_fp + 64 + 0 * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[c2da_fp + 64 + 0 * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 1 * 4]) | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[5320 + 1 * 4]) | uint(c2da_mem[5320 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh3 : uint = float_bits_to_uint(c2da_fresh2)
    c2da_mem[c2da_fp + 64 + 1 * 4] = uint8(c2da_fresh3)
    c2da_mem[c2da_fp + 64 + 1 * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[c2da_fp + 64 + 1 * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[c2da_fp + 64 + 1 * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 2 * 4]) | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[5320 + 2 * 4]) | uint(c2da_mem[5320 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh5 : uint = float_bits_to_uint(c2da_fresh4)
    c2da_mem[c2da_fp + 64 + 2 * 4] = uint8(c2da_fresh5)
    c2da_mem[c2da_fp + 64 + 2 * 4 + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[c2da_fp + 64 + 2 * 4 + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[c2da_fp + 64 + 2 * 4 + 3] = uint8(c2da_fresh5 >> 0x18)
    dist = uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 0 * 4]) | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 1 * 4]) | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 2 * 4]) | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
    if (dist < 1.0) {
        dist = 1.0
    }
    let c2da_fresh6 : float = float(-atan(double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 2 * 4]) | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 3]) << 0x18) / dist)) / 3.141592653589793lf * 180.0lf)
    let c2da_fresh7 : uint = float_bits_to_uint(c2da_fresh6)
    c2da_mem[5332 + 0 * 4] = uint8(c2da_fresh7)
    c2da_mem[5332 + 0 * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[5332 + 0 * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[5332 + 0 * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
    let c2da_fresh8 : float = chase_dest[0]
    let c2da_fresh9 : uint = float_bits_to_uint(c2da_fresh8)
    c2da_mem[5320 + 0 * 4] = uint8(c2da_fresh9)
    c2da_mem[5320 + 0 * 4 + 1] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[5320 + 0 * 4 + 2] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[5320 + 0 * 4 + 3] = uint8(c2da_fresh9 >> 0x18)
    let c2da_fresh10 : float = chase_dest[1]
    let c2da_fresh11 : uint = float_bits_to_uint(c2da_fresh10)
    c2da_mem[5320 + 1 * 4] = uint8(c2da_fresh11)
    c2da_mem[5320 + 1 * 4 + 1] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[5320 + 1 * 4 + 2] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[5320 + 1 * 4 + 3] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : float = chase_dest[2]
    let c2da_fresh13 : uint = float_bits_to_uint(c2da_fresh12)
    c2da_mem[5320 + 2 * 4] = uint8(c2da_fresh13)
    c2da_mem[5320 + 2 * 4 + 1] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[5320 + 2 * 4 + 2] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[5320 + 2 * 4 + 3] = uint8(c2da_fresh13 >> 0x18)
    return
}
[sideeffects]
def private TraceLine_c2da_frame(var start : int; var end : int; var impact : int; c2da_fp : int) {
    c2da_lin_memset(c2da_fp, 0, 56ul)
    SV_RecursiveHullCheck(int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) + 296, 0, 0.0, 1.0, start, end, c2da_fp)
    let c2da_fresh14 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 20 + 0 * 4]) | uint(c2da_mem[c2da_fp + 20 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 20 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 20 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh15 : uint = float_bits_to_uint(c2da_fresh14)
    c2da_mem[impact + 0 * 4] = uint8(c2da_fresh15)
    c2da_mem[impact + 0 * 4 + 1] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[impact + 0 * 4 + 2] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[impact + 0 * 4 + 3] = uint8(c2da_fresh15 >> 0x18)
    let c2da_fresh16 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 20 + 1 * 4]) | uint(c2da_mem[c2da_fp + 20 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 20 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 20 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh17 : uint = float_bits_to_uint(c2da_fresh16)
    c2da_mem[impact + 1 * 4] = uint8(c2da_fresh17)
    c2da_mem[impact + 1 * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[impact + 1 * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[impact + 1 * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
    let c2da_fresh18 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 20 + 2 * 4]) | uint(c2da_mem[c2da_fp + 20 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 20 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 20 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh19 : uint = float_bits_to_uint(c2da_fresh18)
    c2da_mem[impact + 2 * 4] = uint8(c2da_fresh19)
    c2da_mem[impact + 2 * 4 + 1] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[impact + 2 * 4 + 2] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[impact + 2 * 4 + 3] = uint8(c2da_fresh19 >> 0x18)
    return
}

// This unit's static data, at heap offset 697152.
let private c2da_lin_static_chase_seg = fixed_array<int>(697152, 53)
let private c2da_lin_static_chase = fixed_array<uint64>(0x61625f6573616863ul, 0x6300303031006b63ul, 0x70755f65736168ul, 0x6573616863003631ul, 0x300074686769725ful, 0x615f657361686300ul, 0x6576697463ul)

[init]
def private c2da_lin_init_static_chase() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_chase_seg[s * 2]
        for (k in range(c2da_lin_static_chase_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_chase[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_chase_0 = fixed_array<uint8>(0x40, 0xa3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4b, 0xa3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_chase_1 = fixed_array<uint8>(0x4f, 0xa3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x58, 0xa3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_chase_2 = fixed_array<uint8>(0x5b, 0xa3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x67, 0xa3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_chase_3 = fixed_array<uint8>(0x69, 0xa3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x67, 0xa3, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_chase() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[16 + i] = c2da_lin_extern_chase_0[i]
    }
    for (i in range(40)) {
        c2da_mem[64 + i] = c2da_lin_extern_chase_1[i]
    }
    for (i in range(40)) {
        c2da_mem[112 + i] = c2da_lin_extern_chase_2[i]
    }
    for (i in range(40)) {
        c2da_mem[160 + i] = c2da_lin_extern_chase_3[i]
    }
}
