options gen2
options stack = 4194304
module mathlib public

require dasquake_runtime
require sys_null
require strings
require math
require daslib/math_bits
var nanmask : int = 255 << 23

[export, sideeffects]
def VectorMA(var veca : int; var scale : float; var vecb : int; var vecc : int) {
    let c2da_fresh0 : float = uint_bits_to_float(uint(c2da_mem[veca + 0 * 4]) | uint(c2da_mem[veca + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[veca + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[veca + 0 * 4 + 3]) << 0x18) + scale * uint_bits_to_float(uint(c2da_mem[vecb + 0 * 4]) | uint(c2da_mem[vecb + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[vecb + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[vecb + 0 * 4 + 3]) << 0x18)
    let c2da_fresh1 : uint = float_bits_to_uint(c2da_fresh0)
    c2da_mem[vecc + 0 * 4] = uint8(c2da_fresh1)
    c2da_mem[vecc + 0 * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[vecc + 0 * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[vecc + 0 * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : float = uint_bits_to_float(uint(c2da_mem[veca + 1 * 4]) | uint(c2da_mem[veca + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[veca + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[veca + 1 * 4 + 3]) << 0x18) + scale * uint_bits_to_float(uint(c2da_mem[vecb + 1 * 4]) | uint(c2da_mem[vecb + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[vecb + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[vecb + 1 * 4 + 3]) << 0x18)
    let c2da_fresh3 : uint = float_bits_to_uint(c2da_fresh2)
    c2da_mem[vecc + 1 * 4] = uint8(c2da_fresh3)
    c2da_mem[vecc + 1 * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[vecc + 1 * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[vecc + 1 * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : float = uint_bits_to_float(uint(c2da_mem[veca + 2 * 4]) | uint(c2da_mem[veca + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[veca + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[veca + 2 * 4 + 3]) << 0x18) + scale * uint_bits_to_float(uint(c2da_mem[vecb + 2 * 4]) | uint(c2da_mem[vecb + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[vecb + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[vecb + 2 * 4 + 3]) << 0x18)
    let c2da_fresh5 : uint = float_bits_to_uint(c2da_fresh4)
    c2da_mem[vecc + 2 * 4] = uint8(c2da_fresh5)
    c2da_mem[vecc + 2 * 4 + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[vecc + 2 * 4 + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[vecc + 2 * 4 + 3] = uint8(c2da_fresh5 >> 0x18)
    return
}
[export, sideeffects]
def _DotProduct(var v1 : int; var v2 : int) : float {
    return uint_bits_to_float(uint(c2da_mem[v1 + 0 * 4]) | uint(c2da_mem[v1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[v1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[v1 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[v2 + 0 * 4]) | uint(c2da_mem[v2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[v2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[v2 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[v1 + 1 * 4]) | uint(c2da_mem[v1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[v1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[v1 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[v2 + 1 * 4]) | uint(c2da_mem[v2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[v2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[v2 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[v1 + 2 * 4]) | uint(c2da_mem[v1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[v1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[v1 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[v2 + 2 * 4]) | uint(c2da_mem[v2 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[v2 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[v2 + 2 * 4 + 3]) << 0x18)
}
[export, sideeffects]
def _VectorSubtract(var veca_0 : int; var vecb_0 : int; var out : int) {
    let c2da_fresh6 : float = uint_bits_to_float(uint(c2da_mem[veca_0 + 0 * 4]) | uint(c2da_mem[veca_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[veca_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[veca_0 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[vecb_0 + 0 * 4]) | uint(c2da_mem[vecb_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[vecb_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[vecb_0 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh7 : uint = float_bits_to_uint(c2da_fresh6)
    c2da_mem[out + 0 * 4] = uint8(c2da_fresh7)
    c2da_mem[out + 0 * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[out + 0 * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[out + 0 * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
    let c2da_fresh8 : float = uint_bits_to_float(uint(c2da_mem[veca_0 + 1 * 4]) | uint(c2da_mem[veca_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[veca_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[veca_0 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[vecb_0 + 1 * 4]) | uint(c2da_mem[vecb_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[vecb_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[vecb_0 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh9 : uint = float_bits_to_uint(c2da_fresh8)
    c2da_mem[out + 1 * 4] = uint8(c2da_fresh9)
    c2da_mem[out + 1 * 4 + 1] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[out + 1 * 4 + 2] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[out + 1 * 4 + 3] = uint8(c2da_fresh9 >> 0x18)
    let c2da_fresh10 : float = uint_bits_to_float(uint(c2da_mem[veca_0 + 2 * 4]) | uint(c2da_mem[veca_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[veca_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[veca_0 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[vecb_0 + 2 * 4]) | uint(c2da_mem[vecb_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[vecb_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[vecb_0 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh11 : uint = float_bits_to_uint(c2da_fresh10)
    c2da_mem[out + 2 * 4] = uint8(c2da_fresh11)
    c2da_mem[out + 2 * 4 + 1] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[out + 2 * 4 + 2] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[out + 2 * 4 + 3] = uint8(c2da_fresh11 >> 0x18)
    return
}
[export, sideeffects]
def _VectorAdd(var veca_1 : int; var vecb_1 : int; var out_0 : int) {
    let c2da_fresh12 : float = uint_bits_to_float(uint(c2da_mem[veca_1 + 0 * 4]) | uint(c2da_mem[veca_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[veca_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[veca_1 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[vecb_1 + 0 * 4]) | uint(c2da_mem[vecb_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[vecb_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[vecb_1 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh13 : uint = float_bits_to_uint(c2da_fresh12)
    c2da_mem[out_0 + 0 * 4] = uint8(c2da_fresh13)
    c2da_mem[out_0 + 0 * 4 + 1] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[out_0 + 0 * 4 + 2] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[out_0 + 0 * 4 + 3] = uint8(c2da_fresh13 >> 0x18)
    let c2da_fresh14 : float = uint_bits_to_float(uint(c2da_mem[veca_1 + 1 * 4]) | uint(c2da_mem[veca_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[veca_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[veca_1 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[vecb_1 + 1 * 4]) | uint(c2da_mem[vecb_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[vecb_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[vecb_1 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh15 : uint = float_bits_to_uint(c2da_fresh14)
    c2da_mem[out_0 + 1 * 4] = uint8(c2da_fresh15)
    c2da_mem[out_0 + 1 * 4 + 1] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[out_0 + 1 * 4 + 2] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[out_0 + 1 * 4 + 3] = uint8(c2da_fresh15 >> 0x18)
    let c2da_fresh16 : float = uint_bits_to_float(uint(c2da_mem[veca_1 + 2 * 4]) | uint(c2da_mem[veca_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[veca_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[veca_1 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[vecb_1 + 2 * 4]) | uint(c2da_mem[vecb_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[vecb_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[vecb_1 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh17 : uint = float_bits_to_uint(c2da_fresh16)
    c2da_mem[out_0 + 2 * 4] = uint8(c2da_fresh17)
    c2da_mem[out_0 + 2 * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[out_0 + 2 * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[out_0 + 2 * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
    return
}
[export, sideeffects]
def _VectorCopy(var in_0 : int; var out_1 : int) {
    let c2da_fresh18 : float = uint_bits_to_float(uint(c2da_mem[in_0 + 0 * 4]) | uint(c2da_mem[in_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh19 : uint = float_bits_to_uint(c2da_fresh18)
    c2da_mem[out_1 + 0 * 4] = uint8(c2da_fresh19)
    c2da_mem[out_1 + 0 * 4 + 1] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[out_1 + 0 * 4 + 2] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[out_1 + 0 * 4 + 3] = uint8(c2da_fresh19 >> 0x18)
    let c2da_fresh20 : float = uint_bits_to_float(uint(c2da_mem[in_0 + 1 * 4]) | uint(c2da_mem[in_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh21 : uint = float_bits_to_uint(c2da_fresh20)
    c2da_mem[out_1 + 1 * 4] = uint8(c2da_fresh21)
    c2da_mem[out_1 + 1 * 4 + 1] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[out_1 + 1 * 4 + 2] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[out_1 + 1 * 4 + 3] = uint8(c2da_fresh21 >> 0x18)
    let c2da_fresh22 : float = uint_bits_to_float(uint(c2da_mem[in_0 + 2 * 4]) | uint(c2da_mem[in_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh23 : uint = float_bits_to_uint(c2da_fresh22)
    c2da_mem[out_1 + 2 * 4] = uint8(c2da_fresh23)
    c2da_mem[out_1 + 2 * 4 + 1] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[out_1 + 2 * 4 + 2] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[out_1 + 2 * 4 + 3] = uint8(c2da_fresh23 >> 0x18)
    return
}
[export, sideeffects]
def VectorCompare(var v1_0 : int; var v2_0 : int) : int {
    for (i in range(0, 3)) {
        if (uint_bits_to_float(uint(c2da_mem[v1_0 + i * 4]) | uint(c2da_mem[v1_0 + i * 4 + 1]) << 0x8 | uint(c2da_mem[v1_0 + i * 4 + 2]) << 0x10 | uint(c2da_mem[v1_0 + i * 4 + 3]) << 0x18) != uint_bits_to_float(uint(c2da_mem[v2_0 + i * 4]) | uint(c2da_mem[v2_0 + i * 4 + 1]) << 0x8 | uint(c2da_mem[v2_0 + i * 4 + 2]) << 0x10 | uint(c2da_mem[v2_0 + i * 4 + 3]) << 0x18)) {
            return 0
        }
    }
    return 1
}
[export, sideeffects]
def Length(var v : int) : float {
    var length_0 : float = 0.0
    for (i_0 in range(0, 3)) {
        let c2da_fresh24 : float = uint_bits_to_float(uint(c2da_mem[v + i_0 * 4]) | uint(c2da_mem[v + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[v + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[v + i_0 * 4 + 3]) << 0x18)
        length_0 += c2da_fresh24 * c2da_fresh24
    }
    length_0 = float(sqrt(double(length_0)))
    return length_0
}
[export, sideeffects]
def CrossProduct(var v1_1 : int; var v2_1 : int; var cross : int) {
    let c2da_fresh25 : float = uint_bits_to_float(uint(c2da_mem[v1_1 + 1 * 4]) | uint(c2da_mem[v1_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[v1_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[v1_1 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[v2_1 + 2 * 4]) | uint(c2da_mem[v2_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[v2_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[v2_1 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[v1_1 + 2 * 4]) | uint(c2da_mem[v1_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[v1_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[v1_1 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[v2_1 + 1 * 4]) | uint(c2da_mem[v2_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[v2_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[v2_1 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh26 : uint = float_bits_to_uint(c2da_fresh25)
    c2da_mem[cross + 0 * 4] = uint8(c2da_fresh26)
    c2da_mem[cross + 0 * 4 + 1] = uint8(c2da_fresh26 >> 0x8)
    c2da_mem[cross + 0 * 4 + 2] = uint8(c2da_fresh26 >> 0x10)
    c2da_mem[cross + 0 * 4 + 3] = uint8(c2da_fresh26 >> 0x18)
    let c2da_fresh27 : float = uint_bits_to_float(uint(c2da_mem[v1_1 + 2 * 4]) | uint(c2da_mem[v1_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[v1_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[v1_1 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[v2_1 + 0 * 4]) | uint(c2da_mem[v2_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[v2_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[v2_1 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[v1_1 + 0 * 4]) | uint(c2da_mem[v1_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[v1_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[v1_1 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[v2_1 + 2 * 4]) | uint(c2da_mem[v2_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[v2_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[v2_1 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh28 : uint = float_bits_to_uint(c2da_fresh27)
    c2da_mem[cross + 1 * 4] = uint8(c2da_fresh28)
    c2da_mem[cross + 1 * 4 + 1] = uint8(c2da_fresh28 >> 0x8)
    c2da_mem[cross + 1 * 4 + 2] = uint8(c2da_fresh28 >> 0x10)
    c2da_mem[cross + 1 * 4 + 3] = uint8(c2da_fresh28 >> 0x18)
    let c2da_fresh29 : float = uint_bits_to_float(uint(c2da_mem[v1_1 + 0 * 4]) | uint(c2da_mem[v1_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[v1_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[v1_1 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[v2_1 + 1 * 4]) | uint(c2da_mem[v2_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[v2_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[v2_1 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[v1_1 + 1 * 4]) | uint(c2da_mem[v1_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[v1_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[v1_1 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[v2_1 + 0 * 4]) | uint(c2da_mem[v2_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[v2_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[v2_1 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh30 : uint = float_bits_to_uint(c2da_fresh29)
    c2da_mem[cross + 2 * 4] = uint8(c2da_fresh30)
    c2da_mem[cross + 2 * 4 + 1] = uint8(c2da_fresh30 >> 0x8)
    c2da_mem[cross + 2 * 4 + 2] = uint8(c2da_fresh30 >> 0x10)
    c2da_mem[cross + 2 * 4 + 3] = uint8(c2da_fresh30 >> 0x18)
    return
}
[export, sideeffects]
def VectorNormalize(var v_0 : int) : float {
    var length_1 : float
    var ilength : float
    let c2da_fresh37 : float = uint_bits_to_float(uint(c2da_mem[v_0 + 0 * 4]) | uint(c2da_mem[v_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[v_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[v_0 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh38 : float = uint_bits_to_float(uint(c2da_mem[v_0 + 1 * 4]) | uint(c2da_mem[v_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[v_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[v_0 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh39 : float = uint_bits_to_float(uint(c2da_mem[v_0 + 2 * 4]) | uint(c2da_mem[v_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[v_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[v_0 + 2 * 4 + 3]) << 0x18)
    length_1 = c2da_fresh37 * c2da_fresh37 + c2da_fresh38 * c2da_fresh38 + c2da_fresh39 * c2da_fresh39
    length_1 = float(sqrt(double(length_1)))
    if (length_1 != 0.0) {
        ilength = 1.0 / length_1
        let c2da_fresh31 : float = uint_bits_to_float(uint(c2da_mem[v_0 + 0 * 4]) | uint(c2da_mem[v_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[v_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[v_0 + 0 * 4 + 3]) << 0x18) * ilength
        let c2da_fresh32 : uint = float_bits_to_uint(c2da_fresh31)
        c2da_mem[v_0 + 0 * 4] = uint8(c2da_fresh32)
        c2da_mem[v_0 + 0 * 4 + 1] = uint8(c2da_fresh32 >> 0x8)
        c2da_mem[v_0 + 0 * 4 + 2] = uint8(c2da_fresh32 >> 0x10)
        c2da_mem[v_0 + 0 * 4 + 3] = uint8(c2da_fresh32 >> 0x18)
        let c2da_fresh33 : float = uint_bits_to_float(uint(c2da_mem[v_0 + 1 * 4]) | uint(c2da_mem[v_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[v_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[v_0 + 1 * 4 + 3]) << 0x18) * ilength
        let c2da_fresh34 : uint = float_bits_to_uint(c2da_fresh33)
        c2da_mem[v_0 + 1 * 4] = uint8(c2da_fresh34)
        c2da_mem[v_0 + 1 * 4 + 1] = uint8(c2da_fresh34 >> 0x8)
        c2da_mem[v_0 + 1 * 4 + 2] = uint8(c2da_fresh34 >> 0x10)
        c2da_mem[v_0 + 1 * 4 + 3] = uint8(c2da_fresh34 >> 0x18)
        let c2da_fresh35 : float = uint_bits_to_float(uint(c2da_mem[v_0 + 2 * 4]) | uint(c2da_mem[v_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[v_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[v_0 + 2 * 4 + 3]) << 0x18) * ilength
        let c2da_fresh36 : uint = float_bits_to_uint(c2da_fresh35)
        c2da_mem[v_0 + 2 * 4] = uint8(c2da_fresh36)
        c2da_mem[v_0 + 2 * 4 + 1] = uint8(c2da_fresh36 >> 0x8)
        c2da_mem[v_0 + 2 * 4 + 2] = uint8(c2da_fresh36 >> 0x10)
        c2da_mem[v_0 + 2 * 4 + 3] = uint8(c2da_fresh36 >> 0x18)
    }
    return length_1
}
[export, sideeffects]
def VectorInverse(var v_1 : int) {
    let c2da_fresh40 : float = -uint_bits_to_float(uint(c2da_mem[v_1 + 0 * 4]) | uint(c2da_mem[v_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[v_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[v_1 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh41 : uint = float_bits_to_uint(c2da_fresh40)
    c2da_mem[v_1 + 0 * 4] = uint8(c2da_fresh41)
    c2da_mem[v_1 + 0 * 4 + 1] = uint8(c2da_fresh41 >> 0x8)
    c2da_mem[v_1 + 0 * 4 + 2] = uint8(c2da_fresh41 >> 0x10)
    c2da_mem[v_1 + 0 * 4 + 3] = uint8(c2da_fresh41 >> 0x18)
    let c2da_fresh42 : float = -uint_bits_to_float(uint(c2da_mem[v_1 + 1 * 4]) | uint(c2da_mem[v_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[v_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[v_1 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh43 : uint = float_bits_to_uint(c2da_fresh42)
    c2da_mem[v_1 + 1 * 4] = uint8(c2da_fresh43)
    c2da_mem[v_1 + 1 * 4 + 1] = uint8(c2da_fresh43 >> 0x8)
    c2da_mem[v_1 + 1 * 4 + 2] = uint8(c2da_fresh43 >> 0x10)
    c2da_mem[v_1 + 1 * 4 + 3] = uint8(c2da_fresh43 >> 0x18)
    let c2da_fresh44 : float = -uint_bits_to_float(uint(c2da_mem[v_1 + 2 * 4]) | uint(c2da_mem[v_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[v_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[v_1 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh45 : uint = float_bits_to_uint(c2da_fresh44)
    c2da_mem[v_1 + 2 * 4] = uint8(c2da_fresh45)
    c2da_mem[v_1 + 2 * 4 + 1] = uint8(c2da_fresh45 >> 0x8)
    c2da_mem[v_1 + 2 * 4 + 2] = uint8(c2da_fresh45 >> 0x10)
    c2da_mem[v_1 + 2 * 4 + 3] = uint8(c2da_fresh45 >> 0x18)
    return
}
[export, sideeffects]
def VectorScale(var in_1 : int; var scale_0 : float; var out_2 : int) {
    let c2da_fresh46 : float = uint_bits_to_float(uint(c2da_mem[in_1 + 0 * 4]) | uint(c2da_mem[in_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in_1 + 0 * 4 + 3]) << 0x18) * scale_0
    let c2da_fresh47 : uint = float_bits_to_uint(c2da_fresh46)
    c2da_mem[out_2 + 0 * 4] = uint8(c2da_fresh47)
    c2da_mem[out_2 + 0 * 4 + 1] = uint8(c2da_fresh47 >> 0x8)
    c2da_mem[out_2 + 0 * 4 + 2] = uint8(c2da_fresh47 >> 0x10)
    c2da_mem[out_2 + 0 * 4 + 3] = uint8(c2da_fresh47 >> 0x18)
    let c2da_fresh48 : float = uint_bits_to_float(uint(c2da_mem[in_1 + 1 * 4]) | uint(c2da_mem[in_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in_1 + 1 * 4 + 3]) << 0x18) * scale_0
    let c2da_fresh49 : uint = float_bits_to_uint(c2da_fresh48)
    c2da_mem[out_2 + 1 * 4] = uint8(c2da_fresh49)
    c2da_mem[out_2 + 1 * 4 + 1] = uint8(c2da_fresh49 >> 0x8)
    c2da_mem[out_2 + 1 * 4 + 2] = uint8(c2da_fresh49 >> 0x10)
    c2da_mem[out_2 + 1 * 4 + 3] = uint8(c2da_fresh49 >> 0x18)
    let c2da_fresh50 : float = uint_bits_to_float(uint(c2da_mem[in_1 + 2 * 4]) | uint(c2da_mem[in_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in_1 + 2 * 4 + 3]) << 0x18) * scale_0
    let c2da_fresh51 : uint = float_bits_to_uint(c2da_fresh50)
    c2da_mem[out_2 + 2 * 4] = uint8(c2da_fresh51)
    c2da_mem[out_2 + 2 * 4 + 1] = uint8(c2da_fresh51 >> 0x8)
    c2da_mem[out_2 + 2 * 4 + 2] = uint8(c2da_fresh51 >> 0x10)
    c2da_mem[out_2 + 2 * 4 + 3] = uint8(c2da_fresh51 >> 0x18)
    return
}
[export, sideeffects]
def Q_log2(var val : int) : int {
    var answer : int = 0
    while (true) {
        val >>= 1
        if (val == 0) {
            break
        }
        answer++
    }
    return answer
}
[export, sideeffects]
def R_ConcatRotations(var in1 : int; var in2 : int; var out_3 : int) {
    let c2da_fresh52 : float = uint_bits_to_float(uint(c2da_mem[in1 + 0 * 12 + 0 * 4]) | uint(c2da_mem[in1 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 0 * 12 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 0 * 12 + 0 * 4]) | uint(c2da_mem[in2 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 0 * 12 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 0 * 12 + 1 * 4]) | uint(c2da_mem[in1 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 0 * 12 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 1 * 12 + 0 * 4]) | uint(c2da_mem[in2 + 1 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 1 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 1 * 12 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 0 * 12 + 2 * 4]) | uint(c2da_mem[in1 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 0 * 12 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 2 * 12 + 0 * 4]) | uint(c2da_mem[in2 + 2 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 2 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 2 * 12 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh53 : uint = float_bits_to_uint(c2da_fresh52)
    c2da_mem[out_3 + 0 * 12 + 0 * 4] = uint8(c2da_fresh53)
    c2da_mem[out_3 + 0 * 12 + 0 * 4 + 1] = uint8(c2da_fresh53 >> 0x8)
    c2da_mem[out_3 + 0 * 12 + 0 * 4 + 2] = uint8(c2da_fresh53 >> 0x10)
    c2da_mem[out_3 + 0 * 12 + 0 * 4 + 3] = uint8(c2da_fresh53 >> 0x18)
    let c2da_fresh54 : float = uint_bits_to_float(uint(c2da_mem[in1 + 0 * 12 + 0 * 4]) | uint(c2da_mem[in1 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 0 * 12 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 0 * 12 + 1 * 4]) | uint(c2da_mem[in2 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 0 * 12 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 0 * 12 + 1 * 4]) | uint(c2da_mem[in1 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 0 * 12 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 1 * 12 + 1 * 4]) | uint(c2da_mem[in2 + 1 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 1 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 1 * 12 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 0 * 12 + 2 * 4]) | uint(c2da_mem[in1 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 0 * 12 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 2 * 12 + 1 * 4]) | uint(c2da_mem[in2 + 2 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 2 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 2 * 12 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh55 : uint = float_bits_to_uint(c2da_fresh54)
    c2da_mem[out_3 + 0 * 12 + 1 * 4] = uint8(c2da_fresh55)
    c2da_mem[out_3 + 0 * 12 + 1 * 4 + 1] = uint8(c2da_fresh55 >> 0x8)
    c2da_mem[out_3 + 0 * 12 + 1 * 4 + 2] = uint8(c2da_fresh55 >> 0x10)
    c2da_mem[out_3 + 0 * 12 + 1 * 4 + 3] = uint8(c2da_fresh55 >> 0x18)
    let c2da_fresh56 : float = uint_bits_to_float(uint(c2da_mem[in1 + 0 * 12 + 0 * 4]) | uint(c2da_mem[in1 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 0 * 12 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 0 * 12 + 2 * 4]) | uint(c2da_mem[in2 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 0 * 12 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 0 * 12 + 1 * 4]) | uint(c2da_mem[in1 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 0 * 12 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 1 * 12 + 2 * 4]) | uint(c2da_mem[in2 + 1 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 1 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 1 * 12 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 0 * 12 + 2 * 4]) | uint(c2da_mem[in1 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 0 * 12 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 2 * 12 + 2 * 4]) | uint(c2da_mem[in2 + 2 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 2 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 2 * 12 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh57 : uint = float_bits_to_uint(c2da_fresh56)
    c2da_mem[out_3 + 0 * 12 + 2 * 4] = uint8(c2da_fresh57)
    c2da_mem[out_3 + 0 * 12 + 2 * 4 + 1] = uint8(c2da_fresh57 >> 0x8)
    c2da_mem[out_3 + 0 * 12 + 2 * 4 + 2] = uint8(c2da_fresh57 >> 0x10)
    c2da_mem[out_3 + 0 * 12 + 2 * 4 + 3] = uint8(c2da_fresh57 >> 0x18)
    let c2da_fresh58 : float = uint_bits_to_float(uint(c2da_mem[in1 + 1 * 12 + 0 * 4]) | uint(c2da_mem[in1 + 1 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 1 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 1 * 12 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 0 * 12 + 0 * 4]) | uint(c2da_mem[in2 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 0 * 12 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 1 * 12 + 1 * 4]) | uint(c2da_mem[in1 + 1 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 1 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 1 * 12 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 1 * 12 + 0 * 4]) | uint(c2da_mem[in2 + 1 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 1 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 1 * 12 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 1 * 12 + 2 * 4]) | uint(c2da_mem[in1 + 1 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 1 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 1 * 12 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 2 * 12 + 0 * 4]) | uint(c2da_mem[in2 + 2 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 2 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 2 * 12 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh59 : uint = float_bits_to_uint(c2da_fresh58)
    c2da_mem[out_3 + 1 * 12 + 0 * 4] = uint8(c2da_fresh59)
    c2da_mem[out_3 + 1 * 12 + 0 * 4 + 1] = uint8(c2da_fresh59 >> 0x8)
    c2da_mem[out_3 + 1 * 12 + 0 * 4 + 2] = uint8(c2da_fresh59 >> 0x10)
    c2da_mem[out_3 + 1 * 12 + 0 * 4 + 3] = uint8(c2da_fresh59 >> 0x18)
    let c2da_fresh60 : float = uint_bits_to_float(uint(c2da_mem[in1 + 1 * 12 + 0 * 4]) | uint(c2da_mem[in1 + 1 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 1 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 1 * 12 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 0 * 12 + 1 * 4]) | uint(c2da_mem[in2 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 0 * 12 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 1 * 12 + 1 * 4]) | uint(c2da_mem[in1 + 1 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 1 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 1 * 12 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 1 * 12 + 1 * 4]) | uint(c2da_mem[in2 + 1 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 1 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 1 * 12 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 1 * 12 + 2 * 4]) | uint(c2da_mem[in1 + 1 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 1 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 1 * 12 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 2 * 12 + 1 * 4]) | uint(c2da_mem[in2 + 2 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 2 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 2 * 12 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh61 : uint = float_bits_to_uint(c2da_fresh60)
    c2da_mem[out_3 + 1 * 12 + 1 * 4] = uint8(c2da_fresh61)
    c2da_mem[out_3 + 1 * 12 + 1 * 4 + 1] = uint8(c2da_fresh61 >> 0x8)
    c2da_mem[out_3 + 1 * 12 + 1 * 4 + 2] = uint8(c2da_fresh61 >> 0x10)
    c2da_mem[out_3 + 1 * 12 + 1 * 4 + 3] = uint8(c2da_fresh61 >> 0x18)
    let c2da_fresh62 : float = uint_bits_to_float(uint(c2da_mem[in1 + 1 * 12 + 0 * 4]) | uint(c2da_mem[in1 + 1 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 1 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 1 * 12 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 0 * 12 + 2 * 4]) | uint(c2da_mem[in2 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 0 * 12 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 1 * 12 + 1 * 4]) | uint(c2da_mem[in1 + 1 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 1 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 1 * 12 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 1 * 12 + 2 * 4]) | uint(c2da_mem[in2 + 1 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 1 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 1 * 12 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 1 * 12 + 2 * 4]) | uint(c2da_mem[in1 + 1 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 1 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 1 * 12 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 2 * 12 + 2 * 4]) | uint(c2da_mem[in2 + 2 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 2 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 2 * 12 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh63 : uint = float_bits_to_uint(c2da_fresh62)
    c2da_mem[out_3 + 1 * 12 + 2 * 4] = uint8(c2da_fresh63)
    c2da_mem[out_3 + 1 * 12 + 2 * 4 + 1] = uint8(c2da_fresh63 >> 0x8)
    c2da_mem[out_3 + 1 * 12 + 2 * 4 + 2] = uint8(c2da_fresh63 >> 0x10)
    c2da_mem[out_3 + 1 * 12 + 2 * 4 + 3] = uint8(c2da_fresh63 >> 0x18)
    let c2da_fresh64 : float = uint_bits_to_float(uint(c2da_mem[in1 + 2 * 12 + 0 * 4]) | uint(c2da_mem[in1 + 2 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 2 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 2 * 12 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 0 * 12 + 0 * 4]) | uint(c2da_mem[in2 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 0 * 12 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 2 * 12 + 1 * 4]) | uint(c2da_mem[in1 + 2 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 2 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 2 * 12 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 1 * 12 + 0 * 4]) | uint(c2da_mem[in2 + 1 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 1 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 1 * 12 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 2 * 12 + 2 * 4]) | uint(c2da_mem[in1 + 2 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 2 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 2 * 12 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 2 * 12 + 0 * 4]) | uint(c2da_mem[in2 + 2 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 2 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 2 * 12 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh65 : uint = float_bits_to_uint(c2da_fresh64)
    c2da_mem[out_3 + 2 * 12 + 0 * 4] = uint8(c2da_fresh65)
    c2da_mem[out_3 + 2 * 12 + 0 * 4 + 1] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[out_3 + 2 * 12 + 0 * 4 + 2] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[out_3 + 2 * 12 + 0 * 4 + 3] = uint8(c2da_fresh65 >> 0x18)
    let c2da_fresh66 : float = uint_bits_to_float(uint(c2da_mem[in1 + 2 * 12 + 0 * 4]) | uint(c2da_mem[in1 + 2 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 2 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 2 * 12 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 0 * 12 + 1 * 4]) | uint(c2da_mem[in2 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 0 * 12 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 2 * 12 + 1 * 4]) | uint(c2da_mem[in1 + 2 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 2 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 2 * 12 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 1 * 12 + 1 * 4]) | uint(c2da_mem[in2 + 1 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 1 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 1 * 12 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 2 * 12 + 2 * 4]) | uint(c2da_mem[in1 + 2 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 2 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 2 * 12 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 2 * 12 + 1 * 4]) | uint(c2da_mem[in2 + 2 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 2 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 2 * 12 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
    c2da_mem[out_3 + 2 * 12 + 1 * 4] = uint8(c2da_fresh67)
    c2da_mem[out_3 + 2 * 12 + 1 * 4 + 1] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[out_3 + 2 * 12 + 1 * 4 + 2] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[out_3 + 2 * 12 + 1 * 4 + 3] = uint8(c2da_fresh67 >> 0x18)
    let c2da_fresh68 : float = uint_bits_to_float(uint(c2da_mem[in1 + 2 * 12 + 0 * 4]) | uint(c2da_mem[in1 + 2 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 2 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 2 * 12 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 0 * 12 + 2 * 4]) | uint(c2da_mem[in2 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 0 * 12 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 2 * 12 + 1 * 4]) | uint(c2da_mem[in1 + 2 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 2 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 2 * 12 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 1 * 12 + 2 * 4]) | uint(c2da_mem[in2 + 1 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 1 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 1 * 12 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1 + 2 * 12 + 2 * 4]) | uint(c2da_mem[in1 + 2 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1 + 2 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1 + 2 * 12 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2 + 2 * 12 + 2 * 4]) | uint(c2da_mem[in2 + 2 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2 + 2 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2 + 2 * 12 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh69 : uint = float_bits_to_uint(c2da_fresh68)
    c2da_mem[out_3 + 2 * 12 + 2 * 4] = uint8(c2da_fresh69)
    c2da_mem[out_3 + 2 * 12 + 2 * 4 + 1] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[out_3 + 2 * 12 + 2 * 4 + 2] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[out_3 + 2 * 12 + 2 * 4 + 3] = uint8(c2da_fresh69 >> 0x18)
    return
}
[export, sideeffects]
def R_ConcatTransforms(var in1_0 : int; var in2_0 : int; var out_4 : int) {
    let c2da_fresh70 : float = uint_bits_to_float(uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4]) | uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 0 * 16 + 0 * 4]) | uint(c2da_mem[in2_0 + 0 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 0 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 0 * 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4]) | uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 1 * 16 + 0 * 4]) | uint(c2da_mem[in2_0 + 1 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 1 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 1 * 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4]) | uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 2 * 16 + 0 * 4]) | uint(c2da_mem[in2_0 + 2 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 2 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 2 * 16 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh71 : uint = float_bits_to_uint(c2da_fresh70)
    c2da_mem[out_4 + 0 * 16 + 0 * 4] = uint8(c2da_fresh71)
    c2da_mem[out_4 + 0 * 16 + 0 * 4 + 1] = uint8(c2da_fresh71 >> 0x8)
    c2da_mem[out_4 + 0 * 16 + 0 * 4 + 2] = uint8(c2da_fresh71 >> 0x10)
    c2da_mem[out_4 + 0 * 16 + 0 * 4 + 3] = uint8(c2da_fresh71 >> 0x18)
    let c2da_fresh72 : float = uint_bits_to_float(uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4]) | uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 0 * 16 + 1 * 4]) | uint(c2da_mem[in2_0 + 0 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 0 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 0 * 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4]) | uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 1 * 16 + 1 * 4]) | uint(c2da_mem[in2_0 + 1 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 1 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 1 * 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4]) | uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 2 * 16 + 1 * 4]) | uint(c2da_mem[in2_0 + 2 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 2 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 2 * 16 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh73 : uint = float_bits_to_uint(c2da_fresh72)
    c2da_mem[out_4 + 0 * 16 + 1 * 4] = uint8(c2da_fresh73)
    c2da_mem[out_4 + 0 * 16 + 1 * 4 + 1] = uint8(c2da_fresh73 >> 0x8)
    c2da_mem[out_4 + 0 * 16 + 1 * 4 + 2] = uint8(c2da_fresh73 >> 0x10)
    c2da_mem[out_4 + 0 * 16 + 1 * 4 + 3] = uint8(c2da_fresh73 >> 0x18)
    let c2da_fresh74 : float = uint_bits_to_float(uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4]) | uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 0 * 16 + 2 * 4]) | uint(c2da_mem[in2_0 + 0 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 0 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 0 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4]) | uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 1 * 16 + 2 * 4]) | uint(c2da_mem[in2_0 + 1 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 1 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 1 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4]) | uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 2 * 16 + 2 * 4]) | uint(c2da_mem[in2_0 + 2 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 2 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 2 * 16 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh75 : uint = float_bits_to_uint(c2da_fresh74)
    c2da_mem[out_4 + 0 * 16 + 2 * 4] = uint8(c2da_fresh75)
    c2da_mem[out_4 + 0 * 16 + 2 * 4 + 1] = uint8(c2da_fresh75 >> 0x8)
    c2da_mem[out_4 + 0 * 16 + 2 * 4 + 2] = uint8(c2da_fresh75 >> 0x10)
    c2da_mem[out_4 + 0 * 16 + 2 * 4 + 3] = uint8(c2da_fresh75 >> 0x18)
    let c2da_fresh76 : float = uint_bits_to_float(uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4]) | uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 0 * 16 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 0 * 16 + 3 * 4]) | uint(c2da_mem[in2_0 + 0 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 0 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 0 * 16 + 3 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4]) | uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 0 * 16 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 1 * 16 + 3 * 4]) | uint(c2da_mem[in2_0 + 1 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 1 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 1 * 16 + 3 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4]) | uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 0 * 16 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 2 * 16 + 3 * 4]) | uint(c2da_mem[in2_0 + 2 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 2 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 2 * 16 + 3 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 0 * 16 + 3 * 4]) | uint(c2da_mem[in1_0 + 0 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 0 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 0 * 16 + 3 * 4 + 3]) << 0x18)
    let c2da_fresh77 : uint = float_bits_to_uint(c2da_fresh76)
    c2da_mem[out_4 + 0 * 16 + 3 * 4] = uint8(c2da_fresh77)
    c2da_mem[out_4 + 0 * 16 + 3 * 4 + 1] = uint8(c2da_fresh77 >> 0x8)
    c2da_mem[out_4 + 0 * 16 + 3 * 4 + 2] = uint8(c2da_fresh77 >> 0x10)
    c2da_mem[out_4 + 0 * 16 + 3 * 4 + 3] = uint8(c2da_fresh77 >> 0x18)
    let c2da_fresh78 : float = uint_bits_to_float(uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4]) | uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 0 * 16 + 0 * 4]) | uint(c2da_mem[in2_0 + 0 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 0 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 0 * 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4]) | uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 1 * 16 + 0 * 4]) | uint(c2da_mem[in2_0 + 1 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 1 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 1 * 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4]) | uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 2 * 16 + 0 * 4]) | uint(c2da_mem[in2_0 + 2 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 2 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 2 * 16 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh79 : uint = float_bits_to_uint(c2da_fresh78)
    c2da_mem[out_4 + 1 * 16 + 0 * 4] = uint8(c2da_fresh79)
    c2da_mem[out_4 + 1 * 16 + 0 * 4 + 1] = uint8(c2da_fresh79 >> 0x8)
    c2da_mem[out_4 + 1 * 16 + 0 * 4 + 2] = uint8(c2da_fresh79 >> 0x10)
    c2da_mem[out_4 + 1 * 16 + 0 * 4 + 3] = uint8(c2da_fresh79 >> 0x18)
    let c2da_fresh80 : float = uint_bits_to_float(uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4]) | uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 0 * 16 + 1 * 4]) | uint(c2da_mem[in2_0 + 0 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 0 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 0 * 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4]) | uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 1 * 16 + 1 * 4]) | uint(c2da_mem[in2_0 + 1 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 1 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 1 * 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4]) | uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 2 * 16 + 1 * 4]) | uint(c2da_mem[in2_0 + 2 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 2 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 2 * 16 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh81 : uint = float_bits_to_uint(c2da_fresh80)
    c2da_mem[out_4 + 1 * 16 + 1 * 4] = uint8(c2da_fresh81)
    c2da_mem[out_4 + 1 * 16 + 1 * 4 + 1] = uint8(c2da_fresh81 >> 0x8)
    c2da_mem[out_4 + 1 * 16 + 1 * 4 + 2] = uint8(c2da_fresh81 >> 0x10)
    c2da_mem[out_4 + 1 * 16 + 1 * 4 + 3] = uint8(c2da_fresh81 >> 0x18)
    let c2da_fresh82 : float = uint_bits_to_float(uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4]) | uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 0 * 16 + 2 * 4]) | uint(c2da_mem[in2_0 + 0 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 0 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 0 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4]) | uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 1 * 16 + 2 * 4]) | uint(c2da_mem[in2_0 + 1 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 1 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 1 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4]) | uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 2 * 16 + 2 * 4]) | uint(c2da_mem[in2_0 + 2 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 2 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 2 * 16 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh83 : uint = float_bits_to_uint(c2da_fresh82)
    c2da_mem[out_4 + 1 * 16 + 2 * 4] = uint8(c2da_fresh83)
    c2da_mem[out_4 + 1 * 16 + 2 * 4 + 1] = uint8(c2da_fresh83 >> 0x8)
    c2da_mem[out_4 + 1 * 16 + 2 * 4 + 2] = uint8(c2da_fresh83 >> 0x10)
    c2da_mem[out_4 + 1 * 16 + 2 * 4 + 3] = uint8(c2da_fresh83 >> 0x18)
    let c2da_fresh84 : float = uint_bits_to_float(uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4]) | uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 1 * 16 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 0 * 16 + 3 * 4]) | uint(c2da_mem[in2_0 + 0 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 0 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 0 * 16 + 3 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4]) | uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 1 * 16 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 1 * 16 + 3 * 4]) | uint(c2da_mem[in2_0 + 1 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 1 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 1 * 16 + 3 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4]) | uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 1 * 16 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 2 * 16 + 3 * 4]) | uint(c2da_mem[in2_0 + 2 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 2 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 2 * 16 + 3 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 1 * 16 + 3 * 4]) | uint(c2da_mem[in1_0 + 1 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 1 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 1 * 16 + 3 * 4 + 3]) << 0x18)
    let c2da_fresh85 : uint = float_bits_to_uint(c2da_fresh84)
    c2da_mem[out_4 + 1 * 16 + 3 * 4] = uint8(c2da_fresh85)
    c2da_mem[out_4 + 1 * 16 + 3 * 4 + 1] = uint8(c2da_fresh85 >> 0x8)
    c2da_mem[out_4 + 1 * 16 + 3 * 4 + 2] = uint8(c2da_fresh85 >> 0x10)
    c2da_mem[out_4 + 1 * 16 + 3 * 4 + 3] = uint8(c2da_fresh85 >> 0x18)
    let c2da_fresh86 : float = uint_bits_to_float(uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4]) | uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 0 * 16 + 0 * 4]) | uint(c2da_mem[in2_0 + 0 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 0 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 0 * 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4]) | uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 1 * 16 + 0 * 4]) | uint(c2da_mem[in2_0 + 1 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 1 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 1 * 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4]) | uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 2 * 16 + 0 * 4]) | uint(c2da_mem[in2_0 + 2 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 2 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 2 * 16 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh87 : uint = float_bits_to_uint(c2da_fresh86)
    c2da_mem[out_4 + 2 * 16 + 0 * 4] = uint8(c2da_fresh87)
    c2da_mem[out_4 + 2 * 16 + 0 * 4 + 1] = uint8(c2da_fresh87 >> 0x8)
    c2da_mem[out_4 + 2 * 16 + 0 * 4 + 2] = uint8(c2da_fresh87 >> 0x10)
    c2da_mem[out_4 + 2 * 16 + 0 * 4 + 3] = uint8(c2da_fresh87 >> 0x18)
    let c2da_fresh88 : float = uint_bits_to_float(uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4]) | uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 0 * 16 + 1 * 4]) | uint(c2da_mem[in2_0 + 0 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 0 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 0 * 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4]) | uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 1 * 16 + 1 * 4]) | uint(c2da_mem[in2_0 + 1 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 1 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 1 * 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4]) | uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 2 * 16 + 1 * 4]) | uint(c2da_mem[in2_0 + 2 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 2 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 2 * 16 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh89 : uint = float_bits_to_uint(c2da_fresh88)
    c2da_mem[out_4 + 2 * 16 + 1 * 4] = uint8(c2da_fresh89)
    c2da_mem[out_4 + 2 * 16 + 1 * 4 + 1] = uint8(c2da_fresh89 >> 0x8)
    c2da_mem[out_4 + 2 * 16 + 1 * 4 + 2] = uint8(c2da_fresh89 >> 0x10)
    c2da_mem[out_4 + 2 * 16 + 1 * 4 + 3] = uint8(c2da_fresh89 >> 0x18)
    let c2da_fresh90 : float = uint_bits_to_float(uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4]) | uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 0 * 16 + 2 * 4]) | uint(c2da_mem[in2_0 + 0 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 0 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 0 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4]) | uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 1 * 16 + 2 * 4]) | uint(c2da_mem[in2_0 + 1 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 1 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 1 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4]) | uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 2 * 16 + 2 * 4]) | uint(c2da_mem[in2_0 + 2 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 2 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 2 * 16 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh91 : uint = float_bits_to_uint(c2da_fresh90)
    c2da_mem[out_4 + 2 * 16 + 2 * 4] = uint8(c2da_fresh91)
    c2da_mem[out_4 + 2 * 16 + 2 * 4 + 1] = uint8(c2da_fresh91 >> 0x8)
    c2da_mem[out_4 + 2 * 16 + 2 * 4 + 2] = uint8(c2da_fresh91 >> 0x10)
    c2da_mem[out_4 + 2 * 16 + 2 * 4 + 3] = uint8(c2da_fresh91 >> 0x18)
    let c2da_fresh92 : float = uint_bits_to_float(uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4]) | uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 2 * 16 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 0 * 16 + 3 * 4]) | uint(c2da_mem[in2_0 + 0 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 0 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 0 * 16 + 3 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4]) | uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 2 * 16 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 1 * 16 + 3 * 4]) | uint(c2da_mem[in2_0 + 1 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 1 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 1 * 16 + 3 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4]) | uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 2 * 16 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[in2_0 + 2 * 16 + 3 * 4]) | uint(c2da_mem[in2_0 + 2 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[in2_0 + 2 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[in2_0 + 2 * 16 + 3 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in1_0 + 2 * 16 + 3 * 4]) | uint(c2da_mem[in1_0 + 2 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[in1_0 + 2 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[in1_0 + 2 * 16 + 3 * 4 + 3]) << 0x18)
    let c2da_fresh93 : uint = float_bits_to_uint(c2da_fresh92)
    c2da_mem[out_4 + 2 * 16 + 3 * 4] = uint8(c2da_fresh93)
    c2da_mem[out_4 + 2 * 16 + 3 * 4 + 1] = uint8(c2da_fresh93 >> 0x8)
    c2da_mem[out_4 + 2 * 16 + 3 * 4 + 2] = uint8(c2da_fresh93 >> 0x10)
    c2da_mem[out_4 + 2 * 16 + 3 * 4 + 3] = uint8(c2da_fresh93 >> 0x18)
    return
}
[export, sideeffects]
def FloorDivMod(var numer : double; var denom : double; var quotient : int; var rem : int) {
    var q : int
    var r : int
    var x : double
    if (denom <= 0.0lf) {
        Sys_Error(719424, [C2daVaArg(tag = 2, i64 = 0, f64 = denom, raw = 0x0)])
    }
    if (numer >= 0.0lf) {
        x = floor(numer / denom)
        q = int(x)
        r = int(floor(numer - x * denom))
    } else {
        x = floor(-numer / denom)
        q = -int(x)
        r = int(floor(-numer - x * denom))
        if (r != 0) {
            q--
            r = int(denom) - r
        }
    }
    let c2da_fresh94 : uint = uint(q)
    c2da_mem[quotient] = uint8(c2da_fresh94)
    c2da_mem[quotient + 1] = uint8(c2da_fresh94 >> 0x8)
    c2da_mem[quotient + 2] = uint8(c2da_fresh94 >> 0x10)
    c2da_mem[quotient + 3] = uint8(c2da_fresh94 >> 0x18)
    let c2da_fresh95 : uint = uint(r)
    c2da_mem[rem] = uint8(c2da_fresh95)
    c2da_mem[rem + 1] = uint8(c2da_fresh95 >> 0x8)
    c2da_mem[rem + 2] = uint8(c2da_fresh95 >> 0x10)
    c2da_mem[rem + 3] = uint8(c2da_fresh95 >> 0x18)
    return
}
[export, sideeffects]
def Invert24To16(var val_0 : int) : int {
    if (val_0 < 256) {
        return -1
    }
    return int(65536.0lf * 16777216.0lf / double(val_0) + 0.5lf)
}
[export, sideeffects]
def GreatestCommonDivisor(var i1 : int; var i2 : int) : int {
    if (i1 > i2) {
        if (i2 == 0) {
            return i1
        }
        return GreatestCommonDivisor(i2, i1 % i2)
    } else {
        if (i1 == 0) {
            return i2
        }
        return GreatestCommonDivisor(i1, i2 % i1)
    }
}
[export, sideeffects]
def AngleVectors(var angles : int; var forward : int; var right : int; var up : int) {
    var angle : float
    var sr : float
    var sp : float
    var sy : float
    var cr : float
    var cp : float
    var cy : float
    angle = float(double(uint_bits_to_float(uint(c2da_mem[angles + 1 * 4]) | uint(c2da_mem[angles + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[angles + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[angles + 1 * 4 + 3]) << 0x18)) * (3.141592653589793lf * 2.0lf / 360.0lf))
    sy = float(sin(double(angle)))
    cy = float(cos(double(angle)))
    angle = float(double(uint_bits_to_float(uint(c2da_mem[angles + 0 * 4]) | uint(c2da_mem[angles + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[angles + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[angles + 0 * 4 + 3]) << 0x18)) * (3.141592653589793lf * 2.0lf / 360.0lf))
    sp = float(sin(double(angle)))
    cp = float(cos(double(angle)))
    angle = float(double(uint_bits_to_float(uint(c2da_mem[angles + 2 * 4]) | uint(c2da_mem[angles + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[angles + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[angles + 2 * 4 + 3]) << 0x18)) * (3.141592653589793lf * 2.0lf / 360.0lf))
    sr = float(sin(double(angle)))
    cr = float(cos(double(angle)))
    let c2da_fresh96 : float = cp * cy
    let c2da_fresh97 : uint = float_bits_to_uint(c2da_fresh96)
    c2da_mem[forward + 0 * 4] = uint8(c2da_fresh97)
    c2da_mem[forward + 0 * 4 + 1] = uint8(c2da_fresh97 >> 0x8)
    c2da_mem[forward + 0 * 4 + 2] = uint8(c2da_fresh97 >> 0x10)
    c2da_mem[forward + 0 * 4 + 3] = uint8(c2da_fresh97 >> 0x18)
    let c2da_fresh98 : float = cp * sy
    let c2da_fresh99 : uint = float_bits_to_uint(c2da_fresh98)
    c2da_mem[forward + 1 * 4] = uint8(c2da_fresh99)
    c2da_mem[forward + 1 * 4 + 1] = uint8(c2da_fresh99 >> 0x8)
    c2da_mem[forward + 1 * 4 + 2] = uint8(c2da_fresh99 >> 0x10)
    c2da_mem[forward + 1 * 4 + 3] = uint8(c2da_fresh99 >> 0x18)
    let c2da_fresh100 : float = -sp
    let c2da_fresh101 : uint = float_bits_to_uint(c2da_fresh100)
    c2da_mem[forward + 2 * 4] = uint8(c2da_fresh101)
    c2da_mem[forward + 2 * 4 + 1] = uint8(c2da_fresh101 >> 0x8)
    c2da_mem[forward + 2 * 4 + 2] = uint8(c2da_fresh101 >> 0x10)
    c2da_mem[forward + 2 * 4 + 3] = uint8(c2da_fresh101 >> 0x18)
    let c2da_fresh102 : float = -1.0 * sr * sp * cy + -1.0 * cr * -sy
    let c2da_fresh103 : uint = float_bits_to_uint(c2da_fresh102)
    c2da_mem[right + 0 * 4] = uint8(c2da_fresh103)
    c2da_mem[right + 0 * 4 + 1] = uint8(c2da_fresh103 >> 0x8)
    c2da_mem[right + 0 * 4 + 2] = uint8(c2da_fresh103 >> 0x10)
    c2da_mem[right + 0 * 4 + 3] = uint8(c2da_fresh103 >> 0x18)
    let c2da_fresh104 : float = -1.0 * sr * sp * sy + -1.0 * cr * cy
    let c2da_fresh105 : uint = float_bits_to_uint(c2da_fresh104)
    c2da_mem[right + 1 * 4] = uint8(c2da_fresh105)
    c2da_mem[right + 1 * 4 + 1] = uint8(c2da_fresh105 >> 0x8)
    c2da_mem[right + 1 * 4 + 2] = uint8(c2da_fresh105 >> 0x10)
    c2da_mem[right + 1 * 4 + 3] = uint8(c2da_fresh105 >> 0x18)
    let c2da_fresh106 : float = -1.0 * sr * cp
    let c2da_fresh107 : uint = float_bits_to_uint(c2da_fresh106)
    c2da_mem[right + 2 * 4] = uint8(c2da_fresh107)
    c2da_mem[right + 2 * 4 + 1] = uint8(c2da_fresh107 >> 0x8)
    c2da_mem[right + 2 * 4 + 2] = uint8(c2da_fresh107 >> 0x10)
    c2da_mem[right + 2 * 4 + 3] = uint8(c2da_fresh107 >> 0x18)
    let c2da_fresh108 : float = cr * sp * cy + -sr * -sy
    let c2da_fresh109 : uint = float_bits_to_uint(c2da_fresh108)
    c2da_mem[up + 0 * 4] = uint8(c2da_fresh109)
    c2da_mem[up + 0 * 4 + 1] = uint8(c2da_fresh109 >> 0x8)
    c2da_mem[up + 0 * 4 + 2] = uint8(c2da_fresh109 >> 0x10)
    c2da_mem[up + 0 * 4 + 3] = uint8(c2da_fresh109 >> 0x18)
    let c2da_fresh110 : float = cr * sp * sy + -sr * cy
    let c2da_fresh111 : uint = float_bits_to_uint(c2da_fresh110)
    c2da_mem[up + 1 * 4] = uint8(c2da_fresh111)
    c2da_mem[up + 1 * 4 + 1] = uint8(c2da_fresh111 >> 0x8)
    c2da_mem[up + 1 * 4 + 2] = uint8(c2da_fresh111 >> 0x10)
    c2da_mem[up + 1 * 4 + 3] = uint8(c2da_fresh111 >> 0x18)
    let c2da_fresh112 : float = cr * cp
    let c2da_fresh113 : uint = float_bits_to_uint(c2da_fresh112)
    c2da_mem[up + 2 * 4] = uint8(c2da_fresh113)
    c2da_mem[up + 2 * 4 + 1] = uint8(c2da_fresh113 >> 0x8)
    c2da_mem[up + 2 * 4 + 2] = uint8(c2da_fresh113 >> 0x10)
    c2da_mem[up + 2 * 4 + 3] = uint8(c2da_fresh113 >> 0x18)
    return
}
[export, sideeffects]
def BoxOnPlaneSide(var emins : int; var emaxs : int; var p : int) : int {
    var c2da_fresh114 : int
    var dist1 : float
    var dist2 : float
    var sides : int
    c2da_fresh114 = int(c2da_mem[p + 17])
    if (c2da_fresh114 == 0) {
        let c2da_fresh115 : float = uint_bits_to_float(uint(c2da_mem[p + 0 * 4]) | uint(c2da_mem[p + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 0 * 4 + 3]) << 0x18)
        let c2da_fresh116 : float = uint_bits_to_float(uint(c2da_mem[p + 1 * 4]) | uint(c2da_mem[p + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 1 * 4 + 3]) << 0x18)
        let c2da_fresh117 : float = uint_bits_to_float(uint(c2da_mem[p + 2 * 4]) | uint(c2da_mem[p + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 2 * 4 + 3]) << 0x18)
        dist1 = c2da_fresh115 * uint_bits_to_float(uint(c2da_mem[emaxs + 0 * 4]) | uint(c2da_mem[emaxs + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 0 * 4 + 3]) << 0x18) + c2da_fresh116 * uint_bits_to_float(uint(c2da_mem[emaxs + 1 * 4]) | uint(c2da_mem[emaxs + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 1 * 4 + 3]) << 0x18) + c2da_fresh117 * uint_bits_to_float(uint(c2da_mem[emaxs + 2 * 4]) | uint(c2da_mem[emaxs + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 2 * 4 + 3]) << 0x18)
        dist2 = c2da_fresh115 * uint_bits_to_float(uint(c2da_mem[emins + 0 * 4]) | uint(c2da_mem[emins + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 0 * 4 + 3]) << 0x18) + c2da_fresh116 * uint_bits_to_float(uint(c2da_mem[emins + 1 * 4]) | uint(c2da_mem[emins + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 1 * 4 + 3]) << 0x18) + c2da_fresh117 * uint_bits_to_float(uint(c2da_mem[emins + 2 * 4]) | uint(c2da_mem[emins + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 2 * 4 + 3]) << 0x18)
    } elif (c2da_fresh114 == 1) {
        let c2da_fresh118 : float = uint_bits_to_float(uint(c2da_mem[p + 0 * 4]) | uint(c2da_mem[p + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 0 * 4 + 3]) << 0x18)
        let c2da_fresh119 : float = uint_bits_to_float(uint(c2da_mem[p + 1 * 4]) | uint(c2da_mem[p + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 1 * 4 + 3]) << 0x18)
        let c2da_fresh120 : float = uint_bits_to_float(uint(c2da_mem[p + 2 * 4]) | uint(c2da_mem[p + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 2 * 4 + 3]) << 0x18)
        dist1 = c2da_fresh118 * uint_bits_to_float(uint(c2da_mem[emins + 0 * 4]) | uint(c2da_mem[emins + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 0 * 4 + 3]) << 0x18) + c2da_fresh119 * uint_bits_to_float(uint(c2da_mem[emaxs + 1 * 4]) | uint(c2da_mem[emaxs + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 1 * 4 + 3]) << 0x18) + c2da_fresh120 * uint_bits_to_float(uint(c2da_mem[emaxs + 2 * 4]) | uint(c2da_mem[emaxs + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 2 * 4 + 3]) << 0x18)
        dist2 = c2da_fresh118 * uint_bits_to_float(uint(c2da_mem[emaxs + 0 * 4]) | uint(c2da_mem[emaxs + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 0 * 4 + 3]) << 0x18) + c2da_fresh119 * uint_bits_to_float(uint(c2da_mem[emins + 1 * 4]) | uint(c2da_mem[emins + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 1 * 4 + 3]) << 0x18) + c2da_fresh120 * uint_bits_to_float(uint(c2da_mem[emins + 2 * 4]) | uint(c2da_mem[emins + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 2 * 4 + 3]) << 0x18)
    } elif (c2da_fresh114 == 2) {
        let c2da_fresh121 : float = uint_bits_to_float(uint(c2da_mem[p + 0 * 4]) | uint(c2da_mem[p + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 0 * 4 + 3]) << 0x18)
        let c2da_fresh122 : float = uint_bits_to_float(uint(c2da_mem[p + 1 * 4]) | uint(c2da_mem[p + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 1 * 4 + 3]) << 0x18)
        let c2da_fresh123 : float = uint_bits_to_float(uint(c2da_mem[p + 2 * 4]) | uint(c2da_mem[p + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 2 * 4 + 3]) << 0x18)
        dist1 = c2da_fresh121 * uint_bits_to_float(uint(c2da_mem[emaxs + 0 * 4]) | uint(c2da_mem[emaxs + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 0 * 4 + 3]) << 0x18) + c2da_fresh122 * uint_bits_to_float(uint(c2da_mem[emins + 1 * 4]) | uint(c2da_mem[emins + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 1 * 4 + 3]) << 0x18) + c2da_fresh123 * uint_bits_to_float(uint(c2da_mem[emaxs + 2 * 4]) | uint(c2da_mem[emaxs + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 2 * 4 + 3]) << 0x18)
        dist2 = c2da_fresh121 * uint_bits_to_float(uint(c2da_mem[emins + 0 * 4]) | uint(c2da_mem[emins + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 0 * 4 + 3]) << 0x18) + c2da_fresh122 * uint_bits_to_float(uint(c2da_mem[emaxs + 1 * 4]) | uint(c2da_mem[emaxs + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 1 * 4 + 3]) << 0x18) + c2da_fresh123 * uint_bits_to_float(uint(c2da_mem[emins + 2 * 4]) | uint(c2da_mem[emins + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 2 * 4 + 3]) << 0x18)
    } elif (c2da_fresh114 == 3) {
        let c2da_fresh124 : float = uint_bits_to_float(uint(c2da_mem[p + 0 * 4]) | uint(c2da_mem[p + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 0 * 4 + 3]) << 0x18)
        let c2da_fresh125 : float = uint_bits_to_float(uint(c2da_mem[p + 1 * 4]) | uint(c2da_mem[p + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 1 * 4 + 3]) << 0x18)
        let c2da_fresh126 : float = uint_bits_to_float(uint(c2da_mem[p + 2 * 4]) | uint(c2da_mem[p + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 2 * 4 + 3]) << 0x18)
        dist1 = c2da_fresh124 * uint_bits_to_float(uint(c2da_mem[emins + 0 * 4]) | uint(c2da_mem[emins + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 0 * 4 + 3]) << 0x18) + c2da_fresh125 * uint_bits_to_float(uint(c2da_mem[emins + 1 * 4]) | uint(c2da_mem[emins + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 1 * 4 + 3]) << 0x18) + c2da_fresh126 * uint_bits_to_float(uint(c2da_mem[emaxs + 2 * 4]) | uint(c2da_mem[emaxs + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 2 * 4 + 3]) << 0x18)
        dist2 = c2da_fresh124 * uint_bits_to_float(uint(c2da_mem[emaxs + 0 * 4]) | uint(c2da_mem[emaxs + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 0 * 4 + 3]) << 0x18) + c2da_fresh125 * uint_bits_to_float(uint(c2da_mem[emaxs + 1 * 4]) | uint(c2da_mem[emaxs + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 1 * 4 + 3]) << 0x18) + c2da_fresh126 * uint_bits_to_float(uint(c2da_mem[emins + 2 * 4]) | uint(c2da_mem[emins + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 2 * 4 + 3]) << 0x18)
    } elif (c2da_fresh114 == 4) {
        let c2da_fresh127 : float = uint_bits_to_float(uint(c2da_mem[p + 0 * 4]) | uint(c2da_mem[p + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 0 * 4 + 3]) << 0x18)
        let c2da_fresh128 : float = uint_bits_to_float(uint(c2da_mem[p + 1 * 4]) | uint(c2da_mem[p + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 1 * 4 + 3]) << 0x18)
        let c2da_fresh129 : float = uint_bits_to_float(uint(c2da_mem[p + 2 * 4]) | uint(c2da_mem[p + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 2 * 4 + 3]) << 0x18)
        dist1 = c2da_fresh127 * uint_bits_to_float(uint(c2da_mem[emaxs + 0 * 4]) | uint(c2da_mem[emaxs + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 0 * 4 + 3]) << 0x18) + c2da_fresh128 * uint_bits_to_float(uint(c2da_mem[emaxs + 1 * 4]) | uint(c2da_mem[emaxs + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 1 * 4 + 3]) << 0x18) + c2da_fresh129 * uint_bits_to_float(uint(c2da_mem[emins + 2 * 4]) | uint(c2da_mem[emins + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 2 * 4 + 3]) << 0x18)
        dist2 = c2da_fresh127 * uint_bits_to_float(uint(c2da_mem[emins + 0 * 4]) | uint(c2da_mem[emins + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 0 * 4 + 3]) << 0x18) + c2da_fresh128 * uint_bits_to_float(uint(c2da_mem[emins + 1 * 4]) | uint(c2da_mem[emins + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 1 * 4 + 3]) << 0x18) + c2da_fresh129 * uint_bits_to_float(uint(c2da_mem[emaxs + 2 * 4]) | uint(c2da_mem[emaxs + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 2 * 4 + 3]) << 0x18)
    } elif (c2da_fresh114 == 5) {
        let c2da_fresh130 : float = uint_bits_to_float(uint(c2da_mem[p + 0 * 4]) | uint(c2da_mem[p + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 0 * 4 + 3]) << 0x18)
        let c2da_fresh131 : float = uint_bits_to_float(uint(c2da_mem[p + 1 * 4]) | uint(c2da_mem[p + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 1 * 4 + 3]) << 0x18)
        let c2da_fresh132 : float = uint_bits_to_float(uint(c2da_mem[p + 2 * 4]) | uint(c2da_mem[p + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 2 * 4 + 3]) << 0x18)
        dist1 = c2da_fresh130 * uint_bits_to_float(uint(c2da_mem[emins + 0 * 4]) | uint(c2da_mem[emins + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 0 * 4 + 3]) << 0x18) + c2da_fresh131 * uint_bits_to_float(uint(c2da_mem[emaxs + 1 * 4]) | uint(c2da_mem[emaxs + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 1 * 4 + 3]) << 0x18) + c2da_fresh132 * uint_bits_to_float(uint(c2da_mem[emins + 2 * 4]) | uint(c2da_mem[emins + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 2 * 4 + 3]) << 0x18)
        dist2 = c2da_fresh130 * uint_bits_to_float(uint(c2da_mem[emaxs + 0 * 4]) | uint(c2da_mem[emaxs + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 0 * 4 + 3]) << 0x18) + c2da_fresh131 * uint_bits_to_float(uint(c2da_mem[emins + 1 * 4]) | uint(c2da_mem[emins + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 1 * 4 + 3]) << 0x18) + c2da_fresh132 * uint_bits_to_float(uint(c2da_mem[emaxs + 2 * 4]) | uint(c2da_mem[emaxs + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 2 * 4 + 3]) << 0x18)
    } elif (c2da_fresh114 == 6) {
        let c2da_fresh133 : float = uint_bits_to_float(uint(c2da_mem[p + 0 * 4]) | uint(c2da_mem[p + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 0 * 4 + 3]) << 0x18)
        let c2da_fresh134 : float = uint_bits_to_float(uint(c2da_mem[p + 1 * 4]) | uint(c2da_mem[p + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 1 * 4 + 3]) << 0x18)
        let c2da_fresh135 : float = uint_bits_to_float(uint(c2da_mem[p + 2 * 4]) | uint(c2da_mem[p + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 2 * 4 + 3]) << 0x18)
        dist1 = c2da_fresh133 * uint_bits_to_float(uint(c2da_mem[emaxs + 0 * 4]) | uint(c2da_mem[emaxs + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 0 * 4 + 3]) << 0x18) + c2da_fresh134 * uint_bits_to_float(uint(c2da_mem[emins + 1 * 4]) | uint(c2da_mem[emins + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 1 * 4 + 3]) << 0x18) + c2da_fresh135 * uint_bits_to_float(uint(c2da_mem[emins + 2 * 4]) | uint(c2da_mem[emins + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 2 * 4 + 3]) << 0x18)
        dist2 = c2da_fresh133 * uint_bits_to_float(uint(c2da_mem[emins + 0 * 4]) | uint(c2da_mem[emins + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 0 * 4 + 3]) << 0x18) + c2da_fresh134 * uint_bits_to_float(uint(c2da_mem[emaxs + 1 * 4]) | uint(c2da_mem[emaxs + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 1 * 4 + 3]) << 0x18) + c2da_fresh135 * uint_bits_to_float(uint(c2da_mem[emaxs + 2 * 4]) | uint(c2da_mem[emaxs + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 2 * 4 + 3]) << 0x18)
    } elif (c2da_fresh114 == 7) {
        let c2da_fresh136 : float = uint_bits_to_float(uint(c2da_mem[p + 0 * 4]) | uint(c2da_mem[p + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 0 * 4 + 3]) << 0x18)
        let c2da_fresh137 : float = uint_bits_to_float(uint(c2da_mem[p + 1 * 4]) | uint(c2da_mem[p + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 1 * 4 + 3]) << 0x18)
        let c2da_fresh138 : float = uint_bits_to_float(uint(c2da_mem[p + 2 * 4]) | uint(c2da_mem[p + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 2 * 4 + 3]) << 0x18)
        dist1 = c2da_fresh136 * uint_bits_to_float(uint(c2da_mem[emins + 0 * 4]) | uint(c2da_mem[emins + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 0 * 4 + 3]) << 0x18) + c2da_fresh137 * uint_bits_to_float(uint(c2da_mem[emins + 1 * 4]) | uint(c2da_mem[emins + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 1 * 4 + 3]) << 0x18) + c2da_fresh138 * uint_bits_to_float(uint(c2da_mem[emins + 2 * 4]) | uint(c2da_mem[emins + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emins + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emins + 2 * 4 + 3]) << 0x18)
        dist2 = c2da_fresh136 * uint_bits_to_float(uint(c2da_mem[emaxs + 0 * 4]) | uint(c2da_mem[emaxs + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 0 * 4 + 3]) << 0x18) + c2da_fresh137 * uint_bits_to_float(uint(c2da_mem[emaxs + 1 * 4]) | uint(c2da_mem[emaxs + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 1 * 4 + 3]) << 0x18) + c2da_fresh138 * uint_bits_to_float(uint(c2da_mem[emaxs + 2 * 4]) | uint(c2da_mem[emaxs + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[emaxs + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[emaxs + 2 * 4 + 3]) << 0x18)
    } else {
        dist2 = 0.0
        dist1 = dist2
        BOPS_Error()
    }
    sides = 0
    if (dist1 >= uint_bits_to_float(uint(c2da_mem[p + 12]) | uint(c2da_mem[p + 13]) << 0x8 | uint(c2da_mem[p + 14]) << 0x10 | uint(c2da_mem[p + 15]) << 0x18)) {
        sides = 1
    }
    if (dist2 < uint_bits_to_float(uint(c2da_mem[p + 12]) | uint(c2da_mem[p + 13]) << 0x8 | uint(c2da_mem[p + 14]) << 0x10 | uint(c2da_mem[p + 15]) << 0x18)) {
        sides |= 2
    }
    return sides
}
[export, sideeffects]
def BOPS_Error() {
    Sys_Error(719457, [])
    return
}
[export, sideeffects]
def anglemod(var a : float) : float {
    a = float(360.0lf / 65536.0lf * double(int(double(a) * (65536.0lf / 360.0lf)) & 65535))
    return a
}
[export, sideeffects]
def ProjectPointOnPlane(var dst : int; var p_0 : int; var normal : int) {
    var d : float
    var n : vec3_t
    let c2da_fresh145 : float = uint_bits_to_float(uint(c2da_mem[normal + 0 * 4]) | uint(c2da_mem[normal + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[normal + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[normal + 0 * 4 + 3]) << 0x18)
    let c2da_fresh146 : float = uint_bits_to_float(uint(c2da_mem[normal + 1 * 4]) | uint(c2da_mem[normal + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[normal + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[normal + 1 * 4 + 3]) << 0x18)
    let c2da_fresh147 : float = uint_bits_to_float(uint(c2da_mem[normal + 2 * 4]) | uint(c2da_mem[normal + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[normal + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[normal + 2 * 4 + 3]) << 0x18)
    var inv_denom : float = 1.0 / (c2da_fresh145 * c2da_fresh145 + c2da_fresh146 * c2da_fresh146 + c2da_fresh147 * c2da_fresh147)
    d = (c2da_fresh145 * uint_bits_to_float(uint(c2da_mem[p_0 + 0 * 4]) | uint(c2da_mem[p_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p_0 + 0 * 4 + 3]) << 0x18) + c2da_fresh146 * uint_bits_to_float(uint(c2da_mem[p_0 + 1 * 4]) | uint(c2da_mem[p_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p_0 + 1 * 4 + 3]) << 0x18) + c2da_fresh147 * uint_bits_to_float(uint(c2da_mem[p_0 + 2 * 4]) | uint(c2da_mem[p_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p_0 + 2 * 4 + 3]) << 0x18)) * inv_denom
    n[0] = uint_bits_to_float(uint(c2da_mem[normal + 0 * 4]) | uint(c2da_mem[normal + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[normal + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[normal + 0 * 4 + 3]) << 0x18) * inv_denom
    n[1] = uint_bits_to_float(uint(c2da_mem[normal + 1 * 4]) | uint(c2da_mem[normal + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[normal + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[normal + 1 * 4 + 3]) << 0x18) * inv_denom
    n[2] = uint_bits_to_float(uint(c2da_mem[normal + 2 * 4]) | uint(c2da_mem[normal + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[normal + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[normal + 2 * 4 + 3]) << 0x18) * inv_denom
    let c2da_fresh139 : float = uint_bits_to_float(uint(c2da_mem[p_0 + 0 * 4]) | uint(c2da_mem[p_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p_0 + 0 * 4 + 3]) << 0x18) - d * n[0]
    let c2da_fresh140 : uint = float_bits_to_uint(c2da_fresh139)
    c2da_mem[dst + 0 * 4] = uint8(c2da_fresh140)
    c2da_mem[dst + 0 * 4 + 1] = uint8(c2da_fresh140 >> 0x8)
    c2da_mem[dst + 0 * 4 + 2] = uint8(c2da_fresh140 >> 0x10)
    c2da_mem[dst + 0 * 4 + 3] = uint8(c2da_fresh140 >> 0x18)
    let c2da_fresh141 : float = uint_bits_to_float(uint(c2da_mem[p_0 + 1 * 4]) | uint(c2da_mem[p_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p_0 + 1 * 4 + 3]) << 0x18) - d * n[1]
    let c2da_fresh142 : uint = float_bits_to_uint(c2da_fresh141)
    c2da_mem[dst + 1 * 4] = uint8(c2da_fresh142)
    c2da_mem[dst + 1 * 4 + 1] = uint8(c2da_fresh142 >> 0x8)
    c2da_mem[dst + 1 * 4 + 2] = uint8(c2da_fresh142 >> 0x10)
    c2da_mem[dst + 1 * 4 + 3] = uint8(c2da_fresh142 >> 0x18)
    let c2da_fresh143 : float = uint_bits_to_float(uint(c2da_mem[p_0 + 2 * 4]) | uint(c2da_mem[p_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p_0 + 2 * 4 + 3]) << 0x18) - d * n[2]
    let c2da_fresh144 : uint = float_bits_to_uint(c2da_fresh143)
    c2da_mem[dst + 2 * 4] = uint8(c2da_fresh144)
    c2da_mem[dst + 2 * 4 + 1] = uint8(c2da_fresh144 >> 0x8)
    c2da_mem[dst + 2 * 4 + 2] = uint8(c2da_fresh144 >> 0x10)
    c2da_mem[dst + 2 * 4 + 3] = uint8(c2da_fresh144 >> 0x18)
    return
}
[export, sideeffects]
def PerpendicularVector(var dst_0 : int; var src : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    PerpendicularVector_c2da_frame(dst_0, src, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def RotatePointAroundVector(var dst_1 : int; var dir : int; var point : int; var degrees : float) {
    let c2da_saved_sp : int = c2da_lin_sp
    RotatePointAroundVector_c2da_frame(dst_1, dir, point, degrees, c2da_lin_enter(288))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private PerpendicularVector_c2da_frame(var dst_0 : int; var src : int; c2da_fp : int) {
    var pos : int
    var i_1 : int
    var minelem : float = 1.0
    pos = 0
    i_1 = 0
    while (i_1 < 3) {
        if (c2da_std_fabs(double(uint_bits_to_float(uint(c2da_mem[src + i_1 * 4]) | uint(c2da_mem[src + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[src + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[src + i_1 * 4 + 3]) << 0x18))) < double(minelem)) {
            pos = i_1
            minelem = float(c2da_std_fabs(double(uint_bits_to_float(uint(c2da_mem[src + i_1 * 4]) | uint(c2da_mem[src + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[src + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[src + i_1 * 4 + 3]) << 0x18))))
        }
        i_1++
    }
    let c2da_fresh148 : float = 0.0
    let c2da_fresh149 : uint = float_bits_to_uint(c2da_fresh148)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh149)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh149 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh149 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh149 >> 0x18)
    let c2da_fresh150 : uint = float_bits_to_uint(c2da_fresh148)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh150)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh150 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh150 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh150 >> 0x18)
    let c2da_fresh151 : uint = float_bits_to_uint(c2da_fresh148)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh151)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh151 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh151 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh151 >> 0x18)
    let c2da_fresh152 : float = 1.0
    let c2da_fresh153 : uint = float_bits_to_uint(c2da_fresh152)
    c2da_mem[c2da_fp + pos * 4] = uint8(c2da_fresh153)
    c2da_mem[c2da_fp + pos * 4 + 1] = uint8(c2da_fresh153 >> 0x8)
    c2da_mem[c2da_fp + pos * 4 + 2] = uint8(c2da_fresh153 >> 0x10)
    c2da_mem[c2da_fp + pos * 4 + 3] = uint8(c2da_fresh153 >> 0x18)
    ProjectPointOnPlane(dst_0, c2da_fp, src)
    VectorNormalize(dst_0)
    return
}
[sideeffects]
def private RotatePointAroundVector_c2da_frame(var dst_1 : int; var dir : int; var point : int; var degrees : float; c2da_fp : int) {
    let c2da_fresh154 : float = uint_bits_to_float(uint(c2da_mem[dir + 0 * 4]) | uint(c2da_mem[dir + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[dir + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[dir + 0 * 4 + 3]) << 0x18)
    let c2da_fresh155 : uint = float_bits_to_uint(c2da_fresh154)
    c2da_mem[c2da_fp + 16 + 0 * 4] = uint8(c2da_fresh155)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 1] = uint8(c2da_fresh155 >> 0x8)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 2] = uint8(c2da_fresh155 >> 0x10)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 3] = uint8(c2da_fresh155 >> 0x18)
    let c2da_fresh156 : float = uint_bits_to_float(uint(c2da_mem[dir + 1 * 4]) | uint(c2da_mem[dir + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[dir + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[dir + 1 * 4 + 3]) << 0x18)
    let c2da_fresh157 : uint = float_bits_to_uint(c2da_fresh156)
    c2da_mem[c2da_fp + 16 + 1 * 4] = uint8(c2da_fresh157)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 1] = uint8(c2da_fresh157 >> 0x8)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 2] = uint8(c2da_fresh157 >> 0x10)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 3] = uint8(c2da_fresh157 >> 0x18)
    let c2da_fresh158 : float = uint_bits_to_float(uint(c2da_mem[dir + 2 * 4]) | uint(c2da_mem[dir + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[dir + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[dir + 2 * 4 + 3]) << 0x18)
    let c2da_fresh159 : uint = float_bits_to_uint(c2da_fresh158)
    c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh159)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh159 >> 0x8)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh159 >> 0x10)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh159 >> 0x18)
    PerpendicularVector(c2da_fp, dir)
    CrossProduct(c2da_fp, c2da_fp + 16, c2da_fp + 32)
    let c2da_fresh160 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
    let c2da_fresh161 : uint = float_bits_to_uint(c2da_fresh160)
    c2da_mem[c2da_fp + 96 + 0 * 12 + 0 * 4] = uint8(c2da_fresh161)
    c2da_mem[c2da_fp + 96 + 0 * 12 + 0 * 4 + 1] = uint8(c2da_fresh161 >> 0x8)
    c2da_mem[c2da_fp + 96 + 0 * 12 + 0 * 4 + 2] = uint8(c2da_fresh161 >> 0x10)
    c2da_mem[c2da_fp + 96 + 0 * 12 + 0 * 4 + 3] = uint8(c2da_fresh161 >> 0x18)
    let c2da_fresh162 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
    let c2da_fresh163 : uint = float_bits_to_uint(c2da_fresh162)
    c2da_mem[c2da_fp + 96 + 1 * 12 + 0 * 4] = uint8(c2da_fresh163)
    c2da_mem[c2da_fp + 96 + 1 * 12 + 0 * 4 + 1] = uint8(c2da_fresh163 >> 0x8)
    c2da_mem[c2da_fp + 96 + 1 * 12 + 0 * 4 + 2] = uint8(c2da_fresh163 >> 0x10)
    c2da_mem[c2da_fp + 96 + 1 * 12 + 0 * 4 + 3] = uint8(c2da_fresh163 >> 0x18)
    let c2da_fresh164 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
    let c2da_fresh165 : uint = float_bits_to_uint(c2da_fresh164)
    c2da_mem[c2da_fp + 96 + 2 * 12 + 0 * 4] = uint8(c2da_fresh165)
    c2da_mem[c2da_fp + 96 + 2 * 12 + 0 * 4 + 1] = uint8(c2da_fresh165 >> 0x8)
    c2da_mem[c2da_fp + 96 + 2 * 12 + 0 * 4 + 2] = uint8(c2da_fresh165 >> 0x10)
    c2da_mem[c2da_fp + 96 + 2 * 12 + 0 * 4 + 3] = uint8(c2da_fresh165 >> 0x18)
    let c2da_fresh166 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 0 * 4]) | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh167 : uint = float_bits_to_uint(c2da_fresh166)
    c2da_mem[c2da_fp + 96 + 0 * 12 + 1 * 4] = uint8(c2da_fresh167)
    c2da_mem[c2da_fp + 96 + 0 * 12 + 1 * 4 + 1] = uint8(c2da_fresh167 >> 0x8)
    c2da_mem[c2da_fp + 96 + 0 * 12 + 1 * 4 + 2] = uint8(c2da_fresh167 >> 0x10)
    c2da_mem[c2da_fp + 96 + 0 * 12 + 1 * 4 + 3] = uint8(c2da_fresh167 >> 0x18)
    let c2da_fresh168 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 1 * 4]) | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh169 : uint = float_bits_to_uint(c2da_fresh168)
    c2da_mem[c2da_fp + 96 + 1 * 12 + 1 * 4] = uint8(c2da_fresh169)
    c2da_mem[c2da_fp + 96 + 1 * 12 + 1 * 4 + 1] = uint8(c2da_fresh169 >> 0x8)
    c2da_mem[c2da_fp + 96 + 1 * 12 + 1 * 4 + 2] = uint8(c2da_fresh169 >> 0x10)
    c2da_mem[c2da_fp + 96 + 1 * 12 + 1 * 4 + 3] = uint8(c2da_fresh169 >> 0x18)
    let c2da_fresh170 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 2 * 4]) | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh171 : uint = float_bits_to_uint(c2da_fresh170)
    c2da_mem[c2da_fp + 96 + 2 * 12 + 1 * 4] = uint8(c2da_fresh171)
    c2da_mem[c2da_fp + 96 + 2 * 12 + 1 * 4 + 1] = uint8(c2da_fresh171 >> 0x8)
    c2da_mem[c2da_fp + 96 + 2 * 12 + 1 * 4 + 2] = uint8(c2da_fresh171 >> 0x10)
    c2da_mem[c2da_fp + 96 + 2 * 12 + 1 * 4 + 3] = uint8(c2da_fresh171 >> 0x18)
    let c2da_fresh172 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh173 : uint = float_bits_to_uint(c2da_fresh172)
    c2da_mem[c2da_fp + 96 + 0 * 12 + 2 * 4] = uint8(c2da_fresh173)
    c2da_mem[c2da_fp + 96 + 0 * 12 + 2 * 4 + 1] = uint8(c2da_fresh173 >> 0x8)
    c2da_mem[c2da_fp + 96 + 0 * 12 + 2 * 4 + 2] = uint8(c2da_fresh173 >> 0x10)
    c2da_mem[c2da_fp + 96 + 0 * 12 + 2 * 4 + 3] = uint8(c2da_fresh173 >> 0x18)
    let c2da_fresh174 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh175 : uint = float_bits_to_uint(c2da_fresh174)
    c2da_mem[c2da_fp + 96 + 1 * 12 + 2 * 4] = uint8(c2da_fresh175)
    c2da_mem[c2da_fp + 96 + 1 * 12 + 2 * 4 + 1] = uint8(c2da_fresh175 >> 0x8)
    c2da_mem[c2da_fp + 96 + 1 * 12 + 2 * 4 + 2] = uint8(c2da_fresh175 >> 0x10)
    c2da_mem[c2da_fp + 96 + 1 * 12 + 2 * 4 + 3] = uint8(c2da_fresh175 >> 0x18)
    let c2da_fresh176 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh177 : uint = float_bits_to_uint(c2da_fresh176)
    c2da_mem[c2da_fp + 96 + 2 * 12 + 2 * 4] = uint8(c2da_fresh177)
    c2da_mem[c2da_fp + 96 + 2 * 12 + 2 * 4 + 1] = uint8(c2da_fresh177 >> 0x8)
    c2da_mem[c2da_fp + 96 + 2 * 12 + 2 * 4 + 2] = uint8(c2da_fresh177 >> 0x10)
    c2da_mem[c2da_fp + 96 + 2 * 12 + 2 * 4 + 3] = uint8(c2da_fresh177 >> 0x18)
    c2da_lin_memcpy(c2da_fp + 48, c2da_fp + 96, 36ul)
    let c2da_fresh178 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + 1 * 12 + 0 * 4]) | uint(c2da_mem[c2da_fp + 96 + 1 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + 1 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + 1 * 12 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh179 : uint = float_bits_to_uint(c2da_fresh178)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 1 * 4] = uint8(c2da_fresh179)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 1 * 4 + 1] = uint8(c2da_fresh179 >> 0x8)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 1 * 4 + 2] = uint8(c2da_fresh179 >> 0x10)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 1 * 4 + 3] = uint8(c2da_fresh179 >> 0x18)
    let c2da_fresh180 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + 2 * 12 + 0 * 4]) | uint(c2da_mem[c2da_fp + 96 + 2 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + 2 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + 2 * 12 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh181 : uint = float_bits_to_uint(c2da_fresh180)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 2 * 4] = uint8(c2da_fresh181)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 2 * 4 + 1] = uint8(c2da_fresh181 >> 0x8)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 2 * 4 + 2] = uint8(c2da_fresh181 >> 0x10)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 2 * 4 + 3] = uint8(c2da_fresh181 >> 0x18)
    let c2da_fresh182 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + 0 * 12 + 1 * 4]) | uint(c2da_mem[c2da_fp + 96 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + 0 * 12 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh183 : uint = float_bits_to_uint(c2da_fresh182)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 0 * 4] = uint8(c2da_fresh183)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 0 * 4 + 1] = uint8(c2da_fresh183 >> 0x8)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 0 * 4 + 2] = uint8(c2da_fresh183 >> 0x10)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 0 * 4 + 3] = uint8(c2da_fresh183 >> 0x18)
    let c2da_fresh184 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + 2 * 12 + 1 * 4]) | uint(c2da_mem[c2da_fp + 96 + 2 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + 2 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + 2 * 12 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh185 : uint = float_bits_to_uint(c2da_fresh184)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 2 * 4] = uint8(c2da_fresh185)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 2 * 4 + 1] = uint8(c2da_fresh185 >> 0x8)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 2 * 4 + 2] = uint8(c2da_fresh185 >> 0x10)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 2 * 4 + 3] = uint8(c2da_fresh185 >> 0x18)
    let c2da_fresh186 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + 0 * 12 + 2 * 4]) | uint(c2da_mem[c2da_fp + 96 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + 0 * 12 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh187 : uint = float_bits_to_uint(c2da_fresh186)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 0 * 4] = uint8(c2da_fresh187)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 0 * 4 + 1] = uint8(c2da_fresh187 >> 0x8)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 0 * 4 + 2] = uint8(c2da_fresh187 >> 0x10)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 0 * 4 + 3] = uint8(c2da_fresh187 >> 0x18)
    let c2da_fresh188 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + 1 * 12 + 2 * 4]) | uint(c2da_mem[c2da_fp + 96 + 1 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + 1 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + 1 * 12 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh189 : uint = float_bits_to_uint(c2da_fresh188)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 1 * 4] = uint8(c2da_fresh189)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 1 * 4 + 1] = uint8(c2da_fresh189 >> 0x8)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 1 * 4 + 2] = uint8(c2da_fresh189 >> 0x10)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 1 * 4 + 3] = uint8(c2da_fresh189 >> 0x18)
    c2da_lin_memset(c2da_fp + 144, 0, 36ul)
    let c2da_fresh190 : float = 1.0
    let c2da_fresh191 : uint = float_bits_to_uint(c2da_fresh190)
    c2da_mem[c2da_fp + 144 + 2 * 12 + 2 * 4] = uint8(c2da_fresh191)
    c2da_mem[c2da_fp + 144 + 2 * 12 + 2 * 4 + 1] = uint8(c2da_fresh191 >> 0x8)
    c2da_mem[c2da_fp + 144 + 2 * 12 + 2 * 4 + 2] = uint8(c2da_fresh191 >> 0x10)
    c2da_mem[c2da_fp + 144 + 2 * 12 + 2 * 4 + 3] = uint8(c2da_fresh191 >> 0x18)
    let c2da_fresh192 : uint = float_bits_to_uint(c2da_fresh190)
    c2da_mem[c2da_fp + 144 + 1 * 12 + 1 * 4] = uint8(c2da_fresh192)
    c2da_mem[c2da_fp + 144 + 1 * 12 + 1 * 4 + 1] = uint8(c2da_fresh192 >> 0x8)
    c2da_mem[c2da_fp + 144 + 1 * 12 + 1 * 4 + 2] = uint8(c2da_fresh192 >> 0x10)
    c2da_mem[c2da_fp + 144 + 1 * 12 + 1 * 4 + 3] = uint8(c2da_fresh192 >> 0x18)
    let c2da_fresh193 : uint = float_bits_to_uint(c2da_fresh190)
    c2da_mem[c2da_fp + 144 + 0 * 12 + 0 * 4] = uint8(c2da_fresh193)
    c2da_mem[c2da_fp + 144 + 0 * 12 + 0 * 4 + 1] = uint8(c2da_fresh193 >> 0x8)
    c2da_mem[c2da_fp + 144 + 0 * 12 + 0 * 4 + 2] = uint8(c2da_fresh193 >> 0x10)
    c2da_mem[c2da_fp + 144 + 0 * 12 + 0 * 4 + 3] = uint8(c2da_fresh193 >> 0x18)
    let c2da_fresh194 : float = float(cos(double(degrees) * 3.141592653589793lf / 180.0lf))
    let c2da_fresh195 : uint = float_bits_to_uint(c2da_fresh194)
    c2da_mem[c2da_fp + 144 + 0 * 12 + 0 * 4] = uint8(c2da_fresh195)
    c2da_mem[c2da_fp + 144 + 0 * 12 + 0 * 4 + 1] = uint8(c2da_fresh195 >> 0x8)
    c2da_mem[c2da_fp + 144 + 0 * 12 + 0 * 4 + 2] = uint8(c2da_fresh195 >> 0x10)
    c2da_mem[c2da_fp + 144 + 0 * 12 + 0 * 4 + 3] = uint8(c2da_fresh195 >> 0x18)
    let c2da_fresh196 : float = float(sin(double(degrees) * 3.141592653589793lf / 180.0lf))
    let c2da_fresh197 : uint = float_bits_to_uint(c2da_fresh196)
    c2da_mem[c2da_fp + 144 + 0 * 12 + 1 * 4] = uint8(c2da_fresh197)
    c2da_mem[c2da_fp + 144 + 0 * 12 + 1 * 4 + 1] = uint8(c2da_fresh197 >> 0x8)
    c2da_mem[c2da_fp + 144 + 0 * 12 + 1 * 4 + 2] = uint8(c2da_fresh197 >> 0x10)
    c2da_mem[c2da_fp + 144 + 0 * 12 + 1 * 4 + 3] = uint8(c2da_fresh197 >> 0x18)
    let c2da_fresh198 : float = float(-sin(double(degrees) * 3.141592653589793lf / 180.0lf))
    let c2da_fresh199 : uint = float_bits_to_uint(c2da_fresh198)
    c2da_mem[c2da_fp + 144 + 1 * 12 + 0 * 4] = uint8(c2da_fresh199)
    c2da_mem[c2da_fp + 144 + 1 * 12 + 0 * 4 + 1] = uint8(c2da_fresh199 >> 0x8)
    c2da_mem[c2da_fp + 144 + 1 * 12 + 0 * 4 + 2] = uint8(c2da_fresh199 >> 0x10)
    c2da_mem[c2da_fp + 144 + 1 * 12 + 0 * 4 + 3] = uint8(c2da_fresh199 >> 0x18)
    let c2da_fresh200 : float = float(cos(double(degrees) * 3.141592653589793lf / 180.0lf))
    let c2da_fresh201 : uint = float_bits_to_uint(c2da_fresh200)
    c2da_mem[c2da_fp + 144 + 1 * 12 + 1 * 4] = uint8(c2da_fresh201)
    c2da_mem[c2da_fp + 144 + 1 * 12 + 1 * 4 + 1] = uint8(c2da_fresh201 >> 0x8)
    c2da_mem[c2da_fp + 144 + 1 * 12 + 1 * 4 + 2] = uint8(c2da_fresh201 >> 0x10)
    c2da_mem[c2da_fp + 144 + 1 * 12 + 1 * 4 + 3] = uint8(c2da_fresh201 >> 0x18)
    R_ConcatRotations(c2da_fp + 96, c2da_fp + 144, c2da_fp + 192)
    R_ConcatRotations(c2da_fp + 192, c2da_fp + 48, c2da_fp + 240)
    for (i_2 in range(0, 3)) {
        let c2da_fresh202 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 240 + i_2 * 12 + 0 * 4]) | uint(c2da_mem[c2da_fp + 240 + i_2 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 240 + i_2 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 240 + i_2 * 12 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[point + 0 * 4]) | uint(c2da_mem[point + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[point + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[point + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 240 + i_2 * 12 + 1 * 4]) | uint(c2da_mem[c2da_fp + 240 + i_2 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 240 + i_2 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 240 + i_2 * 12 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[point + 1 * 4]) | uint(c2da_mem[point + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[point + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[point + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 240 + i_2 * 12 + 2 * 4]) | uint(c2da_mem[c2da_fp + 240 + i_2 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 240 + i_2 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 240 + i_2 * 12 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[point + 2 * 4]) | uint(c2da_mem[point + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[point + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[point + 2 * 4 + 3]) << 0x18)
        let c2da_fresh203 : uint = float_bits_to_uint(c2da_fresh202)
        c2da_mem[dst_1 + i_2 * 4] = uint8(c2da_fresh203)
        c2da_mem[dst_1 + i_2 * 4 + 1] = uint8(c2da_fresh203 >> 0x8)
        c2da_mem[dst_1 + i_2 * 4 + 2] = uint8(c2da_fresh203 >> 0x10)
        c2da_mem[dst_1 + i_2 * 4 + 3] = uint8(c2da_fresh203 >> 0x18)
    }
    return
}

// This unit's static data, at heap offset 719424.
let private c2da_lin_static_mathlib_seg = fixed_array<int>(719424, 62)
let private c2da_lin_static_mathlib = fixed_array<uint64>(0x766944726f6f6c46ul, 0x646162203a646f4dul, 0x6e696d6f6e656420ul, 0xa642520726f7461ul, 0x6c506e4f786f4200ul, 0x3a65646953656e61ul, 0x6973206461422020ul, 0x737469626e67ul)

[init]
def private c2da_lin_init_static_mathlib() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_mathlib_seg[s * 2]
        for (k in range(c2da_lin_static_mathlib_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_mathlib[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
