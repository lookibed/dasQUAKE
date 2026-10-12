var private R_TimeGraph__timex : int = 0

var private R_TimeGraph__r_timings : uint8[100] = fixed_array<uint8>(0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8)

var private R_CheckVariables__oldbright : float = 0.0

[export, sideeffects]
def TransformVector(var in_0 : int; var out : int) {
    let c2da_fresh0 : float = uint_bits_to_float(uint(c2da_mem[in_0 + 0 * 4]) | uint(c2da_mem[in_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[244144 + 0 * 4]) | uint(c2da_mem[244144 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in_0 + 1 * 4]) | uint(c2da_mem[in_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[244144 + 1 * 4]) | uint(c2da_mem[244144 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in_0 + 2 * 4]) | uint(c2da_mem[in_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[244144 + 2 * 4]) | uint(c2da_mem[244144 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh1 : uint = float_bits_to_uint(c2da_fresh0)
    c2da_mem[out + 0 * 4] = uint8(c2da_fresh1)
    c2da_mem[out + 0 * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[out + 0 * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[out + 0 * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : float = uint_bits_to_float(uint(c2da_mem[in_0 + 0 * 4]) | uint(c2da_mem[in_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[244160 + 0 * 4]) | uint(c2da_mem[244160 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in_0 + 1 * 4]) | uint(c2da_mem[in_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[244160 + 1 * 4]) | uint(c2da_mem[244160 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in_0 + 2 * 4]) | uint(c2da_mem[in_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[244160 + 2 * 4]) | uint(c2da_mem[244160 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh3 : uint = float_bits_to_uint(c2da_fresh2)
    c2da_mem[out + 1 * 4] = uint8(c2da_fresh3)
    c2da_mem[out + 1 * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[out + 1 * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[out + 1 * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : float = uint_bits_to_float(uint(c2da_mem[in_0 + 0 * 4]) | uint(c2da_mem[in_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[244128 + 0 * 4]) | uint(c2da_mem[244128 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in_0 + 1 * 4]) | uint(c2da_mem[in_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[244128 + 1 * 4]) | uint(c2da_mem[244128 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in_0 + 2 * 4]) | uint(c2da_mem[in_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[244128 + 2 * 4]) | uint(c2da_mem[244128 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh5 : uint = float_bits_to_uint(c2da_fresh4)
    c2da_mem[out + 2 * 4] = uint8(c2da_fresh5)
    c2da_mem[out + 2 * 4 + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[out + 2 * 4 + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[out + 2 * 4 + 3] = uint8(c2da_fresh5 >> 0x18)
    return
}
[export, sideeffects]
def R_TransformPlane(var p : int; var normal : int; var dist : int) {
    let c2da_fresh6 : float = uint_bits_to_float(uint(c2da_mem[p + 12]) | uint(c2da_mem[p + 13]) << 0x8 | uint(c2da_mem[p + 14]) << 0x10 | uint(c2da_mem[p + 15]) << 0x18) - (uint_bits_to_float(uint(c2da_mem[244112 + 0 * 4]) | uint(c2da_mem[244112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[p + 0 * 4]) | uint(c2da_mem[p + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[244112 + 1 * 4]) | uint(c2da_mem[244112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[p + 1 * 4]) | uint(c2da_mem[p + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[244112 + 2 * 4]) | uint(c2da_mem[244112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[p + 2 * 4]) | uint(c2da_mem[p + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 2 * 4 + 3]) << 0x18))
    let c2da_fresh7 : uint = float_bits_to_uint(c2da_fresh6)
    c2da_mem[dist] = uint8(c2da_fresh7)
    c2da_mem[dist + 1] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[dist + 2] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[dist + 3] = uint8(c2da_fresh7 >> 0x18)
    TransformVector(p, normal)
    return
}
[export, sideeffects]
def R_TransformFrustum() {
    var v : vec3_t
    var v2 : vec3_t
    for (i in range(0, 4)) {
        v[0] = uint_bits_to_float(uint(c2da_mem[392976 + i * 20 + 2 * 4]) | uint(c2da_mem[392976 + i * 20 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[392976 + i * 20 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[392976 + i * 20 + 2 * 4 + 3]) << 0x18)
        v[1] = -uint_bits_to_float(uint(c2da_mem[392976 + i * 20 + 0 * 4]) | uint(c2da_mem[392976 + i * 20 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[392976 + i * 20 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[392976 + i * 20 + 0 * 4 + 3]) << 0x18)
        v[2] = uint_bits_to_float(uint(c2da_mem[392976 + i * 20 + 1 * 4]) | uint(c2da_mem[392976 + i * 20 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[392976 + i * 20 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[392976 + i * 20 + 1 * 4 + 3]) << 0x18)
        v2[0] = v[1] * uint_bits_to_float(uint(c2da_mem[244144 + 0 * 4]) | uint(c2da_mem[244144 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 0 * 4 + 3]) << 0x18) + v[2] * uint_bits_to_float(uint(c2da_mem[244160 + 0 * 4]) | uint(c2da_mem[244160 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 0 * 4 + 3]) << 0x18) + v[0] * uint_bits_to_float(uint(c2da_mem[244128 + 0 * 4]) | uint(c2da_mem[244128 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 0 * 4 + 3]) << 0x18)
        v2[1] = v[1] * uint_bits_to_float(uint(c2da_mem[244144 + 1 * 4]) | uint(c2da_mem[244144 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 1 * 4 + 3]) << 0x18) + v[2] * uint_bits_to_float(uint(c2da_mem[244160 + 1 * 4]) | uint(c2da_mem[244160 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 1 * 4 + 3]) << 0x18) + v[0] * uint_bits_to_float(uint(c2da_mem[244128 + 1 * 4]) | uint(c2da_mem[244128 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 1 * 4 + 3]) << 0x18)
        v2[2] = v[1] * uint_bits_to_float(uint(c2da_mem[244144 + 2 * 4]) | uint(c2da_mem[244144 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 2 * 4 + 3]) << 0x18) + v[2] * uint_bits_to_float(uint(c2da_mem[244160 + 2 * 4]) | uint(c2da_mem[244160 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 2 * 4 + 3]) << 0x18) + v[0] * uint_bits_to_float(uint(c2da_mem[244128 + 2 * 4]) | uint(c2da_mem[244128 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh8 : float = v2[0]
        let c2da_fresh9 : uint = float_bits_to_uint(c2da_fresh8)
        c2da_mem[391440 + i * 32 + 0 * 4] = uint8(c2da_fresh9)
        c2da_mem[391440 + i * 32 + 0 * 4 + 1] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[391440 + i * 32 + 0 * 4 + 2] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[391440 + i * 32 + 0 * 4 + 3] = uint8(c2da_fresh9 >> 0x18)
        let c2da_fresh10 : float = v2[1]
        let c2da_fresh11 : uint = float_bits_to_uint(c2da_fresh10)
        c2da_mem[391440 + i * 32 + 1 * 4] = uint8(c2da_fresh11)
        c2da_mem[391440 + i * 32 + 1 * 4 + 1] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[391440 + i * 32 + 1 * 4 + 2] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[391440 + i * 32 + 1 * 4 + 3] = uint8(c2da_fresh11 >> 0x18)
        let c2da_fresh12 : float = v2[2]
        let c2da_fresh13 : uint = float_bits_to_uint(c2da_fresh12)
        c2da_mem[391440 + i * 32 + 2 * 4] = uint8(c2da_fresh13)
        c2da_mem[391440 + i * 32 + 2 * 4 + 1] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[391440 + i * 32 + 2 * 4 + 2] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[391440 + i * 32 + 2 * 4 + 3] = uint8(c2da_fresh13 >> 0x18)
        let c2da_fresh14 : float = uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18) * v2[0] + uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18) * v2[1] + uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18) * v2[2]
        let c2da_fresh15 : uint = float_bits_to_uint(c2da_fresh14)
        c2da_mem[391440 + i * 32 + 12] = uint8(c2da_fresh15)
        c2da_mem[391440 + i * 32 + 13] = uint8(c2da_fresh15 >> 0x8)
        c2da_mem[391440 + i * 32 + 14] = uint8(c2da_fresh15 >> 0x10)
        c2da_mem[391440 + i * 32 + 15] = uint8(c2da_fresh15 >> 0x18)
    }
    return
}
[export, sideeffects]
def R_TimeRefresh_f() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_TimeRefresh_f_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_TimeGraph() {
    var a : int
    var r_time2 : float
    var x : int
    r_time2 = float(Sys_FloatTime())
    R_TimeGraph__r_timings[R_TimeGraph__timex] = uint8(int(double(r_time2 - r_time1) / 0.01lf))
    a = R_TimeGraph__timex
    let c2da_fresh29 : int = int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18)
    if (c2da_fresh29 <= 100) {
        x = c2da_fresh29 - 1
    } else {
        x = c2da_fresh29 - (c2da_fresh29 - 100) / 2
    }
    while (true) {
        R_LineGraph(x, int(uint(c2da_mem[5212]) | uint(c2da_mem[5213]) << 0x8 | uint(c2da_mem[5214]) << 0x10 | uint(c2da_mem[5215]) << 0x18) - 2, int(R_TimeGraph__r_timings[a]))
        if (x == 0) {
            break
        }
        x--
        a--
        if (a == -1) {
            a = 100 - 1
        }
        if (a == R_TimeGraph__timex) {
            break
        }
    }
    R_TimeGraph__timex = (R_TimeGraph__timex + 1) % 100
    return
}
[export, sideeffects]
def R_LineGraph(var x_0 : int; var y : int; var h : int) {
    var i_1 : int
    var dest : int
    var s : int
    x_0 += int(uint(c2da_mem[5200]) | uint(c2da_mem[5201]) << 0x8 | uint(c2da_mem[5202]) << 0x10 | uint(c2da_mem[5203]) << 0x18)
    y += int(uint(c2da_mem[5204]) | uint(c2da_mem[5205]) << 0x8 | uint(c2da_mem[5206]) << 0x10 | uint(c2da_mem[5207]) << 0x18)
    dest = vid.buffer + int(vid.rowbytes * uint(y)) + x_0
    s = int(uint_bits_to_float(uint(c2da_mem[392088]) | uint(c2da_mem[392089]) << 0x8 | uint(c2da_mem[392090]) << 0x10 | uint(c2da_mem[392091]) << 0x18))
    if (h > s) {
        h = s
    }
    i_1 = 0
    while (i_1 < h) {
        let c2da_fresh30 : uint8 = 0xffu8
        c2da_mem[dest + 0] = c2da_fresh30
        let c2da_fresh31 : int = dest - int(vid.rowbytes)
        let c2da_fresh32 : uint8 = 0x30u8
        c2da_mem[c2da_fresh31] = c2da_fresh32
        i_1++
        dest -= int(vid.rowbytes * 2u)
    }
    while (i_1 < s) {
        let c2da_fresh33 : uint8 = 0x30u8
        c2da_mem[dest + 0] = c2da_fresh33
        let c2da_fresh34 : int = dest - int(vid.rowbytes)
        let c2da_fresh35 : uint8 = 0x30u8
        c2da_mem[c2da_fresh34] = c2da_fresh35
        i_1++
        dest -= int(vid.rowbytes * 2u)
    }
    return
}
[export, sideeffects]
def R_PrintAliasStats() {
    Con_Printf(733285, [C2daVaArg(tag = 1, i64 = int64(r_amodels_drawn), f64 = 0.0lf, raw = 0x0)])
    return
}
[export, sideeffects]
def R_PrintTimes() {
    var r_time2_0 : float
    var ms : float
    r_time2_0 = float(Sys_FloatTime())
    ms = 1000.0 * (r_time2_0 - r_time1)
    Con_Printf(733310, [C2daVaArg(tag = 2, i64 = 0, f64 = double(ms), raw = 0x0), C2daVaArg(tag = 1, i64 = int64(c_faceclip), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(r_polycount), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(r_drawnpolycount), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(c_surf), f64 = 0.0lf, raw = 0x0)])
    c_surf = 0
    return
}
[export, sideeffects]
def R_PrintDSpeeds() {
    var ms_0 : float
    var dp_time : float
    var r_time2_1 : float
    var rw_time : float
    var db_time : float
    var se_time : float
    var de_time : float
    var dv_time : float
    r_time2_1 = float(Sys_FloatTime())
    dp_time = (dp_time2 - dp_time1) * 1000.0
    rw_time = (rw_time2 - rw_time1) * 1000.0
    db_time = (db_time2 - db_time1) * 1000.0
    se_time = (se_time2 - se_time1) * 1000.0
    de_time = (de_time2 - de_time1) * 1000.0
    dv_time = (dv_time2 - dv_time1) * 1000.0
    ms_0 = (r_time2_1 - r_time1) * 1000.0
    Con_Printf(733346, [C2daVaArg(tag = 1, i64 = int64(int(ms_0)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(dp_time), raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(rw_time)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(db_time), raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(se_time)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(de_time), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(dv_time), raw = 0x0)])
    return
}
[export, sideeffects]
def R_SetupFrame() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_SetupFrame_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_SetUpFrustumIndexes() {
    var pindex : int = 393056
    for (i_2 in range(0, 4)) {
        for (j in range(0, 3)) {
            if (uint_bits_to_float(uint(c2da_mem[391440 + i_2 * 32 + j * 4]) | uint(c2da_mem[391440 + i_2 * 32 + j * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + i_2 * 32 + j * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + i_2 * 32 + j * 4 + 3]) << 0x18) < 0.0) {
                let c2da_fresh81 : uint = uint(j)
                c2da_mem[pindex + j * 4] = uint8(c2da_fresh81)
                c2da_mem[pindex + j * 4 + 1] = uint8(c2da_fresh81 >> 0x8)
                c2da_mem[pindex + j * 4 + 2] = uint8(c2da_fresh81 >> 0x10)
                c2da_mem[pindex + j * 4 + 3] = uint8(c2da_fresh81 >> 0x18)
                let c2da_fresh82 : int = j + 3
                let c2da_fresh83 : uint = uint(c2da_fresh82)
                c2da_mem[pindex + (j + 3) * 4] = uint8(c2da_fresh83)
                c2da_mem[pindex + (j + 3) * 4 + 1] = uint8(c2da_fresh83 >> 0x8)
                c2da_mem[pindex + (j + 3) * 4 + 2] = uint8(c2da_fresh83 >> 0x10)
                c2da_mem[pindex + (j + 3) * 4 + 3] = uint8(c2da_fresh83 >> 0x18)
            } else {
                let c2da_fresh84 : int = j + 3
                let c2da_fresh85 : uint = uint(c2da_fresh84)
                c2da_mem[pindex + j * 4] = uint8(c2da_fresh85)
                c2da_mem[pindex + j * 4 + 1] = uint8(c2da_fresh85 >> 0x8)
                c2da_mem[pindex + j * 4 + 2] = uint8(c2da_fresh85 >> 0x10)
                c2da_mem[pindex + j * 4 + 3] = uint8(c2da_fresh85 >> 0x18)
                let c2da_fresh86 : uint = uint(j)
                c2da_mem[pindex + (j + 3) * 4] = uint8(c2da_fresh86)
                c2da_mem[pindex + (j + 3) * 4 + 1] = uint8(c2da_fresh86 >> 0x8)
                c2da_mem[pindex + (j + 3) * 4 + 2] = uint8(c2da_fresh86 >> 0x10)
                c2da_mem[pindex + (j + 3) * 4 + 3] = uint8(c2da_fresh86 >> 0x18)
            }
        }
        pfrustum_indexes[i_2] = pindex
        pindex += 6 * 4
    }
    return
}
[export, sideeffects]
def R_CheckVariables() {
    let c2da_fresh87 : float = uint_bits_to_float(uint(c2da_mem[392328]) | uint(c2da_mem[392329]) << 0x8 | uint(c2da_mem[392330]) << 0x10 | uint(c2da_mem[392331]) << 0x18)
    if (c2da_fresh87 != R_CheckVariables__oldbright) {
        R_CheckVariables__oldbright = c2da_fresh87
        D_FlushCaches()
    }
    return
}
[export, sideeffects]
def Show() {
    let c2da_saved_sp : int = c2da_lin_sp
    Show_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def WarpPalette() {
    let c2da_saved_sp : int = c2da_lin_sp
    WarpPalette_c2da_frame(c2da_lin_enter(768))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private R_TimeRefresh_f_c2da_frame(c2da_fp : int) {
    var start : float
    var stop : float
    var time : float
    var startangle : int = int(uint_bits_to_float(uint(c2da_mem[5332 + 1 * 4]) | uint(c2da_mem[5332 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[5332 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[5332 + 1 * 4 + 3]) << 0x18))
    start = float(Sys_FloatTime())
    for (i_0 in range(0, 128)) {
        let c2da_fresh16 : float = float(double(i_0) / 128.0lf * 360.0lf)
        let c2da_fresh17 : uint = float_bits_to_uint(c2da_fresh16)
        c2da_mem[5332 + 1 * 4] = uint8(c2da_fresh17)
        c2da_mem[5332 + 1 * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
        c2da_mem[5332 + 1 * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
        c2da_mem[5332 + 1 * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
        R_RenderView()
        let c2da_fresh18 : int = int(uint(c2da_mem[5200]) | uint(c2da_mem[5201]) << 0x8 | uint(c2da_mem[5202]) << 0x10 | uint(c2da_mem[5203]) << 0x18)
        let c2da_fresh19 : uint = uint(c2da_fresh18)
        c2da_mem[c2da_fp] = uint8(c2da_fresh19)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh19 >> 0x8)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh19 >> 0x10)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh19 >> 0x18)
        let c2da_fresh20 : int = int(uint(c2da_mem[5204]) | uint(c2da_mem[5205]) << 0x8 | uint(c2da_mem[5206]) << 0x10 | uint(c2da_mem[5207]) << 0x18)
        let c2da_fresh21 : uint = uint(c2da_fresh20)
        c2da_mem[c2da_fp + 4] = uint8(c2da_fresh21)
        c2da_mem[c2da_fp + 5] = uint8(c2da_fresh21 >> 0x8)
        c2da_mem[c2da_fp + 6] = uint8(c2da_fresh21 >> 0x10)
        c2da_mem[c2da_fp + 7] = uint8(c2da_fresh21 >> 0x18)
        let c2da_fresh22 : int = int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18)
        let c2da_fresh23 : uint = uint(c2da_fresh22)
        c2da_mem[c2da_fp + 8] = uint8(c2da_fresh23)
        c2da_mem[c2da_fp + 9] = uint8(c2da_fresh23 >> 0x8)
        c2da_mem[c2da_fp + 10] = uint8(c2da_fresh23 >> 0x10)
        c2da_mem[c2da_fp + 11] = uint8(c2da_fresh23 >> 0x18)
        let c2da_fresh24 : int = int(uint(c2da_mem[5212]) | uint(c2da_mem[5213]) << 0x8 | uint(c2da_mem[5214]) << 0x10 | uint(c2da_mem[5215]) << 0x18)
        let c2da_fresh25 : uint = uint(c2da_fresh24)
        c2da_mem[c2da_fp + 12] = uint8(c2da_fresh25)
        c2da_mem[c2da_fp + 13] = uint8(c2da_fresh25 >> 0x8)
        c2da_mem[c2da_fp + 14] = uint8(c2da_fresh25 >> 0x10)
        c2da_mem[c2da_fp + 15] = uint8(c2da_fresh25 >> 0x18)
        let c2da_fresh26 : uint = 0u
        c2da_mem[c2da_fp + 16] = uint8(c2da_fresh26)
        c2da_mem[c2da_fp + 17] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[c2da_fp + 18] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[c2da_fp + 19] = uint8(c2da_fresh26 >> 0x18)
        c2da_mem[c2da_fp + 20] = 0u8
        c2da_mem[c2da_fp + 21] = 0u8
        c2da_mem[c2da_fp + 22] = 0u8
        c2da_mem[c2da_fp + 23] = 0u8
        VID_Update(c2da_fp)
    }
    stop = float(Sys_FloatTime())
    time = stop - start
    Con_Printf(733264, [C2daVaArg(tag = 2, i64 = 0, f64 = double(time), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(128.0 / time), raw = 0x0)])
    let c2da_fresh27 : float = float(startangle)
    let c2da_fresh28 : uint = float_bits_to_uint(c2da_fresh27)
    c2da_mem[5332 + 1 * 4] = uint8(c2da_fresh28)
    c2da_mem[5332 + 1 * 4 + 1] = uint8(c2da_fresh28 >> 0x8)
    c2da_mem[5332 + 1 * 4 + 2] = uint8(c2da_fresh28 >> 0x10)
    c2da_mem[5332 + 1 * 4 + 3] = uint8(c2da_fresh28 >> 0x18)
    return
}
[sideeffects]
def private R_SetupFrame_c2da_frame(c2da_fp : int) {
    var edgecount : int
    var w : float
    var h_0 : float
    if (int(uint(c2da_mem[4948]) | uint(c2da_mem[4949]) << 0x8 | uint(c2da_mem[4950]) << 0x10 | uint(c2da_mem[4951]) << 0x18) > 1) {
        Cvar_Set(733389, 733401)
        Cvar_Set(733403, 733401)
        Cvar_Set(733416, 733401)
        Cvar_Set(733426, 733401)
    }
    if (uint_bits_to_float(uint(c2da_mem[392664]) | uint(c2da_mem[392665]) << 0x8 | uint(c2da_mem[392666]) << 0x10 | uint(c2da_mem[392667]) << 0x18) != 0.0) {
        if (int64((surface_p - surfaces) / 88) > int64(r_maxsurfsseen)) {
            r_maxsurfsseen = int(int64((surface_p - surfaces) / 88))
        }
        Con_Printf(733437, [C2daVaArg(tag = 1, i64 = int64((surface_p - surfaces) / 88), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64((surf_max - surfaces) / 88), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(r_maxsurfsseen), f64 = 0.0lf, raw = 0x0)])
    }
    if (uint_bits_to_float(uint(c2da_mem[392808]) | uint(c2da_mem[392809]) << 0x8 | uint(c2da_mem[392810]) << 0x10 | uint(c2da_mem[392811]) << 0x18) != 0.0) {
        edgecount = int(int64((edge_p - r_edges) / 56))
        if (edgecount > r_maxedgesseen) {
            r_maxedgesseen = edgecount
        }
        Con_Printf(733466, [C2daVaArg(tag = 1, i64 = int64(edgecount), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(r_numallocatededges), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(r_maxedgesseen), f64 = 0.0lf, raw = 0x0)])
    }
    let c2da_fresh36 : int = int(uint_bits_to_float(uint(c2da_mem[392184]) | uint(c2da_mem[392185]) << 0x8 | uint(c2da_mem[392186]) << 0x10 | uint(c2da_mem[392187]) << 0x18))
    let c2da_fresh37 : uint = uint(c2da_fresh36)
    c2da_mem[5352] = uint8(c2da_fresh37)
    c2da_mem[5353] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[5354] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[5355] = uint8(c2da_fresh37 >> 0x18)
    if (int(uint(c2da_mem[5352]) | uint(c2da_mem[5353]) << 0x8 | uint(c2da_mem[5354]) << 0x10 | uint(c2da_mem[5355]) << 0x18) < 0) {
        let c2da_fresh38 : int = 0
        let c2da_fresh39 : uint = uint(c2da_fresh38)
        c2da_mem[5352] = uint8(c2da_fresh39)
        c2da_mem[5353] = uint8(c2da_fresh39 >> 0x8)
        c2da_mem[5354] = uint8(c2da_fresh39 >> 0x10)
        c2da_mem[5355] = uint8(c2da_fresh39 >> 0x18)
    }
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u) {
        let c2da_fresh40 : float = 0.0
        let c2da_fresh41 : uint = float_bits_to_uint(c2da_fresh40)
        c2da_mem[391944] = uint8(c2da_fresh41)
        c2da_mem[391945] = uint8(c2da_fresh41 >> 0x8)
        c2da_mem[391946] = uint8(c2da_fresh41 >> 0x10)
        c2da_mem[391947] = uint8(c2da_fresh41 >> 0x18)
    }
    R_CheckVariables()
    R_AnimateLight()
    r_framecount = r_framecount + 1
    numbtofpolys = 0
    let c2da_fresh78 : float = uint_bits_to_float(uint(c2da_mem[5320 + 0 * 4]) | uint(c2da_mem[5320 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh42 : float = c2da_fresh78
    let c2da_fresh43 : uint = float_bits_to_uint(c2da_fresh42)
    c2da_mem[204240 + 0 * 4] = uint8(c2da_fresh43)
    c2da_mem[204240 + 0 * 4 + 1] = uint8(c2da_fresh43 >> 0x8)
    c2da_mem[204240 + 0 * 4 + 2] = uint8(c2da_fresh43 >> 0x10)
    c2da_mem[204240 + 0 * 4 + 3] = uint8(c2da_fresh43 >> 0x18)
    let c2da_fresh79 : float = uint_bits_to_float(uint(c2da_mem[5320 + 1 * 4]) | uint(c2da_mem[5320 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh44 : float = c2da_fresh79
    let c2da_fresh45 : uint = float_bits_to_uint(c2da_fresh44)
    c2da_mem[204240 + 1 * 4] = uint8(c2da_fresh45)
    c2da_mem[204240 + 1 * 4 + 1] = uint8(c2da_fresh45 >> 0x8)
    c2da_mem[204240 + 1 * 4 + 2] = uint8(c2da_fresh45 >> 0x10)
    c2da_mem[204240 + 1 * 4 + 3] = uint8(c2da_fresh45 >> 0x18)
    let c2da_fresh80 : float = uint_bits_to_float(uint(c2da_mem[5320 + 2 * 4]) | uint(c2da_mem[5320 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[5320 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[5320 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh46 : float = c2da_fresh80
    let c2da_fresh47 : uint = float_bits_to_uint(c2da_fresh46)
    c2da_mem[204240 + 2 * 4] = uint8(c2da_fresh47)
    c2da_mem[204240 + 2 * 4 + 1] = uint8(c2da_fresh47 >> 0x8)
    c2da_mem[204240 + 2 * 4 + 2] = uint8(c2da_fresh47 >> 0x10)
    c2da_mem[204240 + 2 * 4 + 3] = uint8(c2da_fresh47 >> 0x18)
    let c2da_fresh48 : float = c2da_fresh78
    let c2da_fresh49 : uint = float_bits_to_uint(c2da_fresh48)
    c2da_mem[244112 + 0 * 4] = uint8(c2da_fresh49)
    c2da_mem[244112 + 0 * 4 + 1] = uint8(c2da_fresh49 >> 0x8)
    c2da_mem[244112 + 0 * 4 + 2] = uint8(c2da_fresh49 >> 0x10)
    c2da_mem[244112 + 0 * 4 + 3] = uint8(c2da_fresh49 >> 0x18)
    let c2da_fresh50 : float = c2da_fresh79
    let c2da_fresh51 : uint = float_bits_to_uint(c2da_fresh50)
    c2da_mem[244112 + 1 * 4] = uint8(c2da_fresh51)
    c2da_mem[244112 + 1 * 4 + 1] = uint8(c2da_fresh51 >> 0x8)
    c2da_mem[244112 + 1 * 4 + 2] = uint8(c2da_fresh51 >> 0x10)
    c2da_mem[244112 + 1 * 4 + 3] = uint8(c2da_fresh51 >> 0x18)
    let c2da_fresh52 : float = c2da_fresh80
    let c2da_fresh53 : uint = float_bits_to_uint(c2da_fresh52)
    c2da_mem[244112 + 2 * 4] = uint8(c2da_fresh53)
    c2da_mem[244112 + 2 * 4 + 1] = uint8(c2da_fresh53 >> 0x8)
    c2da_mem[244112 + 2 * 4 + 2] = uint8(c2da_fresh53 >> 0x10)
    c2da_mem[244112 + 2 * 4 + 3] = uint8(c2da_fresh53 >> 0x18)
    AngleVectors(5332, 244128, 244144, 244160)
    r_oldviewleaf = r_viewleaf
    r_viewleaf = Mod_PointInLeaf(244112, int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18))
    r_dowarpold = r_dowarp
    r_dowarp = uint(uint_bits_to_float(uint(c2da_mem[392280]) | uint(c2da_mem[392281]) << 0x8 | uint(c2da_mem[392282]) << 0x10 | uint(c2da_mem[392283]) << 0x18) != 0.0 && int(uint(c2da_mem[r_viewleaf]) | uint(c2da_mem[r_viewleaf + 1]) << 0x8 | uint(c2da_mem[r_viewleaf + 2]) << 0x10 | uint(c2da_mem[r_viewleaf + 3]) << 0x18) <= -3 ? 1 : 0)
    if (uint(r_dowarp) != uint(r_dowarpold) || uint(r_viewchanged) != 0x0 || uint_bits_to_float(uint(c2da_mem[695816]) | uint(c2da_mem[695817]) << 0x8 | uint(c2da_mem[695818]) << 0x10 | uint(c2da_mem[695819]) << 0x18) != 0.0) {
        if (uint(r_dowarp) != 0u) {
            if (vid.width <= uint(vid.maxwarpwidth) && vid.height <= uint(vid.maxwarpheight)) {
                let c2da_fresh54 : int = 0
                let c2da_fresh55 : uint = uint(c2da_fresh54)
                c2da_mem[c2da_fp] = uint8(c2da_fresh55)
                c2da_mem[c2da_fp + 1] = uint8(c2da_fresh55 >> 0x8)
                c2da_mem[c2da_fp + 2] = uint8(c2da_fresh55 >> 0x10)
                c2da_mem[c2da_fp + 3] = uint8(c2da_fresh55 >> 0x18)
                let c2da_fresh56 : int = 0
                let c2da_fresh57 : uint = uint(c2da_fresh56)
                c2da_mem[c2da_fp + 4] = uint8(c2da_fresh57)
                c2da_mem[c2da_fp + 5] = uint8(c2da_fresh57 >> 0x8)
                c2da_mem[c2da_fp + 6] = uint8(c2da_fresh57 >> 0x10)
                c2da_mem[c2da_fp + 7] = uint8(c2da_fresh57 >> 0x18)
                let c2da_fresh58 : int = int(vid.width)
                let c2da_fresh59 : uint = uint(c2da_fresh58)
                c2da_mem[c2da_fp + 8] = uint8(c2da_fresh59)
                c2da_mem[c2da_fp + 9] = uint8(c2da_fresh59 >> 0x8)
                c2da_mem[c2da_fp + 10] = uint8(c2da_fresh59 >> 0x10)
                c2da_mem[c2da_fp + 11] = uint8(c2da_fresh59 >> 0x18)
                let c2da_fresh60 : int = int(vid.height)
                let c2da_fresh61 : uint = uint(c2da_fresh60)
                c2da_mem[c2da_fp + 12] = uint8(c2da_fresh61)
                c2da_mem[c2da_fp + 13] = uint8(c2da_fresh61 >> 0x8)
                c2da_mem[c2da_fp + 14] = uint8(c2da_fresh61 >> 0x10)
                c2da_mem[c2da_fp + 15] = uint8(c2da_fresh61 >> 0x18)
                R_ViewChanged(c2da_fp, sb_lines, vid.aspect)
            } else {
                w = float(vid.width)
                h_0 = float(vid.height)
                if (w > float(vid.maxwarpwidth)) {
                    h_0 *= float(vid.maxwarpwidth) / w
                    w = float(vid.maxwarpwidth)
                }
                if (h_0 > float(vid.maxwarpheight)) {
                    h_0 = float(vid.maxwarpheight)
                    w *= float(vid.maxwarpheight) / h_0
                }
                let c2da_fresh62 : int = 0
                let c2da_fresh63 : uint = uint(c2da_fresh62)
                c2da_mem[c2da_fp] = uint8(c2da_fresh63)
                c2da_mem[c2da_fp + 1] = uint8(c2da_fresh63 >> 0x8)
                c2da_mem[c2da_fp + 2] = uint8(c2da_fresh63 >> 0x10)
                c2da_mem[c2da_fp + 3] = uint8(c2da_fresh63 >> 0x18)
                let c2da_fresh64 : int = 0
                let c2da_fresh65 : uint = uint(c2da_fresh64)
                c2da_mem[c2da_fp + 4] = uint8(c2da_fresh65)
                c2da_mem[c2da_fp + 5] = uint8(c2da_fresh65 >> 0x8)
                c2da_mem[c2da_fp + 6] = uint8(c2da_fresh65 >> 0x10)
                c2da_mem[c2da_fp + 7] = uint8(c2da_fresh65 >> 0x18)
                let c2da_fresh66 : int = int(w)
                let c2da_fresh67 : uint = uint(c2da_fresh66)
                c2da_mem[c2da_fp + 8] = uint8(c2da_fresh67)
                c2da_mem[c2da_fp + 9] = uint8(c2da_fresh67 >> 0x8)
                c2da_mem[c2da_fp + 10] = uint8(c2da_fresh67 >> 0x10)
                c2da_mem[c2da_fp + 11] = uint8(c2da_fresh67 >> 0x18)
                let c2da_fresh68 : int = int(h_0)
                let c2da_fresh69 : uint = uint(c2da_fresh68)
                c2da_mem[c2da_fp + 12] = uint8(c2da_fresh69)
                c2da_mem[c2da_fp + 13] = uint8(c2da_fresh69 >> 0x8)
                c2da_mem[c2da_fp + 14] = uint8(c2da_fresh69 >> 0x10)
                c2da_mem[c2da_fp + 15] = uint8(c2da_fresh69 >> 0x18)
                R_ViewChanged(c2da_fp, int(float(sb_lines) * (h_0 / float(vid.height))), vid.aspect * (h_0 / w) * (float(vid.width) / float(vid.height)))
            }
        } else {
            let c2da_fresh70 : int = 0
            let c2da_fresh71 : uint = uint(c2da_fresh70)
            c2da_mem[c2da_fp] = uint8(c2da_fresh71)
            c2da_mem[c2da_fp + 1] = uint8(c2da_fresh71 >> 0x8)
            c2da_mem[c2da_fp + 2] = uint8(c2da_fresh71 >> 0x10)
            c2da_mem[c2da_fp + 3] = uint8(c2da_fresh71 >> 0x18)
            let c2da_fresh72 : int = 0
            let c2da_fresh73 : uint = uint(c2da_fresh72)
            c2da_mem[c2da_fp + 4] = uint8(c2da_fresh73)
            c2da_mem[c2da_fp + 5] = uint8(c2da_fresh73 >> 0x8)
            c2da_mem[c2da_fp + 6] = uint8(c2da_fresh73 >> 0x10)
            c2da_mem[c2da_fp + 7] = uint8(c2da_fresh73 >> 0x18)
            let c2da_fresh74 : int = int(vid.width)
            let c2da_fresh75 : uint = uint(c2da_fresh74)
            c2da_mem[c2da_fp + 8] = uint8(c2da_fresh75)
            c2da_mem[c2da_fp + 9] = uint8(c2da_fresh75 >> 0x8)
            c2da_mem[c2da_fp + 10] = uint8(c2da_fresh75 >> 0x10)
            c2da_mem[c2da_fp + 11] = uint8(c2da_fresh75 >> 0x18)
            let c2da_fresh76 : int = int(vid.height)
            let c2da_fresh77 : uint = uint(c2da_fresh76)
            c2da_mem[c2da_fp + 12] = uint8(c2da_fresh77)
            c2da_mem[c2da_fp + 13] = uint8(c2da_fresh77 >> 0x8)
            c2da_mem[c2da_fp + 14] = uint8(c2da_fresh77 >> 0x10)
            c2da_mem[c2da_fp + 15] = uint8(c2da_fresh77 >> 0x18)
            R_ViewChanged(c2da_fp, sb_lines, vid.aspect)
        }
        r_viewchanged = 0u
    }
    R_TransformFrustum()
    base_vpn[0] = uint_bits_to_float(uint(c2da_mem[244128 + 0 * 4]) | uint(c2da_mem[244128 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 0 * 4 + 3]) << 0x18)
    base_vpn[1] = uint_bits_to_float(uint(c2da_mem[244128 + 1 * 4]) | uint(c2da_mem[244128 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 1 * 4 + 3]) << 0x18)
    base_vpn[2] = uint_bits_to_float(uint(c2da_mem[244128 + 2 * 4]) | uint(c2da_mem[244128 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 2 * 4 + 3]) << 0x18)
    base_vright[0] = uint_bits_to_float(uint(c2da_mem[244144 + 0 * 4]) | uint(c2da_mem[244144 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 0 * 4 + 3]) << 0x18)
    base_vright[1] = uint_bits_to_float(uint(c2da_mem[244144 + 1 * 4]) | uint(c2da_mem[244144 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 1 * 4 + 3]) << 0x18)
    base_vright[2] = uint_bits_to_float(uint(c2da_mem[244144 + 2 * 4]) | uint(c2da_mem[244144 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 2 * 4 + 3]) << 0x18)
    base_vup[0] = uint_bits_to_float(uint(c2da_mem[244160 + 0 * 4]) | uint(c2da_mem[244160 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 0 * 4 + 3]) << 0x18)
    base_vup[1] = uint_bits_to_float(uint(c2da_mem[244160 + 1 * 4]) | uint(c2da_mem[244160 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 1 * 4 + 3]) << 0x18)
    base_vup[2] = uint_bits_to_float(uint(c2da_mem[244160 + 2 * 4]) | uint(c2da_mem[244160 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 2 * 4 + 3]) << 0x18)
    base_modelorg[0] = uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18)
    base_modelorg[1] = uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18)
    base_modelorg[2] = uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18)
    R_SetSkyFrame()
    R_SetUpFrustumIndexes()
    r_cache_thrash = 0u
    c_faceclip = 0
    d_spanpixcount = 0
    r_polycount = 0
    r_drawnpolycount = 0
    r_wholepolycount = 0
    r_amodels_drawn = 0
    r_outofsurfaces = 0
    r_outofedges = 0
    D_SetupFrame()
    return
}
[sideeffects]
def private Show_c2da_frame(c2da_fp : int) {
    let c2da_fresh88 : int = 0
    let c2da_fresh89 : uint = uint(c2da_fresh88)
    c2da_mem[c2da_fp + 4] = uint8(c2da_fresh89)
    c2da_mem[c2da_fp + 5] = uint8(c2da_fresh89 >> 0x8)
    c2da_mem[c2da_fp + 6] = uint8(c2da_fresh89 >> 0x10)
    c2da_mem[c2da_fp + 7] = uint8(c2da_fresh89 >> 0x18)
    let c2da_fresh90 : uint = uint(c2da_fresh88)
    c2da_mem[c2da_fp] = uint8(c2da_fresh90)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh90 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh90 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh90 >> 0x18)
    let c2da_fresh91 : int = int(vid.width)
    let c2da_fresh92 : uint = uint(c2da_fresh91)
    c2da_mem[c2da_fp + 8] = uint8(c2da_fresh92)
    c2da_mem[c2da_fp + 9] = uint8(c2da_fresh92 >> 0x8)
    c2da_mem[c2da_fp + 10] = uint8(c2da_fresh92 >> 0x10)
    c2da_mem[c2da_fp + 11] = uint8(c2da_fresh92 >> 0x18)
    let c2da_fresh93 : int = int(vid.height)
    let c2da_fresh94 : uint = uint(c2da_fresh93)
    c2da_mem[c2da_fp + 12] = uint8(c2da_fresh94)
    c2da_mem[c2da_fp + 13] = uint8(c2da_fresh94 >> 0x8)
    c2da_mem[c2da_fp + 14] = uint8(c2da_fresh94 >> 0x10)
    c2da_mem[c2da_fp + 15] = uint8(c2da_fresh94 >> 0x18)
    let c2da_fresh95 : uint = 0u
    c2da_mem[c2da_fp + 16] = uint8(c2da_fresh95)
    c2da_mem[c2da_fp + 17] = uint8(c2da_fresh95 >> 0x8)
    c2da_mem[c2da_fp + 18] = uint8(c2da_fresh95 >> 0x10)
    c2da_mem[c2da_fp + 19] = uint8(c2da_fresh95 >> 0x18)
    c2da_mem[c2da_fp + 20] = 0u8
    c2da_mem[c2da_fp + 21] = 0u8
    c2da_mem[c2da_fp + 22] = 0u8
    c2da_mem[c2da_fp + 23] = 0u8
    VID_Update(c2da_fp)
    return
}
[sideeffects]
def private WarpPalette_c2da_frame(c2da_fp : int) {
    var basecolor : int[3]
    basecolor[0] = 130
    basecolor[1] = 80
    basecolor[2] = 50
    for (i_3 in range(0, 256)) {
        for (j_0 in range(0, 3)) {
            let c2da_fresh96 : uint8 = uint8((int(c2da_mem[host_basepal + (i_3 * 3 + j_0)]) + basecolor[j_0]) / 2)
            c2da_mem[c2da_fp + (i_3 * 3 + j_0)] = c2da_fresh96
        }
    }
    VID_ShiftPalette(c2da_fp)
    return
}

// This unit's static data, at heap offset 733264.
let private c2da_lin_static_r_misc_seg = fixed_array<int>(733264, 230)
let private c2da_lin_static_r_misc = fixed_array<uint64>(0x6e6f636573206625ul, 0x6620662528207364ul, 0x693325000a297370ul, 0x6e6f67796c6f7020ul, 0x64206c65646f6d20ul, 0x3525000a6e776172ul, 0x2520736d2066312eul, 0x252f6933252f6933ul, 0x20796c6f70206933ul, 0x6672757320693325ul, 0x342520693325000aul, 0x693325207066312eul, 0x6266312e34252077ul, 0x3425207369332520ul, 0x2e3425206566312eul, 0x645f72000a766631ul, 0x726564726f776172ul, 0x6c75665f72003000ul, 0x7468676972626cul, 0x6e6569626d615f72ul, 0x776172645f720074ul, 0x6573550074616c66ul, 0x20666f2064252064ul, 0x7366727573206425ul, 0x78616d206425203bul, 0x252064657355000aul, 0x20642520666f2064ul, 0x25203b7365676465ul, 0xa78616d2064ul)

[init]
def private c2da_lin_init_static_r_misc() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_misc_seg[s * 2]
        for (k in range(c2da_lin_static_r_misc_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_misc[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_r_misc() {
    if (length(c2da_fn_table0) < 210) {
        resize(c2da_fn_table0, 210)
    }
    c2da_fn_table0[209] = @@R_TimeRefresh_f
}

[init]
def private c2da_lin_relink_init_r_misc() {
    c2da_relink_r_misc()
}
