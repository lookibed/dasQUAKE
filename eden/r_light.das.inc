[export, sideeffects]
def R_PushDlights() {
    var i : int
    var l : int
    r_dlightframecount = r_framecount + 1
    l = 8112
    i = 0
    while (i < 32) {
        if (double(uint_bits_to_float(uint(c2da_mem[l + 16]) | uint(c2da_mem[l + 17]) << 0x8 | uint(c2da_mem[l + 18]) << 0x10 | uint(c2da_mem[l + 19]) << 0x18)) < uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) || uint_bits_to_float(uint(c2da_mem[l + 12]) | uint(c2da_mem[l + 13]) << 0x8 | uint(c2da_mem[l + 14]) << 0x10 | uint(c2da_mem[l + 15]) << 0x18) == 0.0) {
            i++
            l += 32
            continue
        }
        let c2da_fresh0 : int = int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) + 208
        R_MarkLights(l, 1 << i, int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18))
        i++
        l += 32
    }
    return
}
[export, sideeffects]
def R_MarkLights(var light : int; var bit : int; var node : int) {
    var splitplane : int
    var dist : float
    var surf : int
    var i_0 : int
    if (int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18) < 0) {
        return
    }
    splitplane = int(uint(c2da_mem[node + 32]) | uint(c2da_mem[node + 33]) << 0x8 | uint(c2da_mem[node + 34]) << 0x10 | uint(c2da_mem[node + 35]) << 0x18)
    dist = uint_bits_to_float(uint(c2da_mem[light + 0 * 4]) | uint(c2da_mem[light + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[light + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[light + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[splitplane + 0 * 4]) | uint(c2da_mem[splitplane + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[light + 1 * 4]) | uint(c2da_mem[light + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[light + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[light + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[splitplane + 1 * 4]) | uint(c2da_mem[splitplane + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[light + 2 * 4]) | uint(c2da_mem[light + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[light + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[light + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[splitplane + 2 * 4]) | uint(c2da_mem[splitplane + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[splitplane + 12]) | uint(c2da_mem[splitplane + 13]) << 0x8 | uint(c2da_mem[splitplane + 14]) << 0x10 | uint(c2da_mem[splitplane + 15]) << 0x18)
    if (dist > uint_bits_to_float(uint(c2da_mem[light + 12]) | uint(c2da_mem[light + 13]) << 0x8 | uint(c2da_mem[light + 14]) << 0x10 | uint(c2da_mem[light + 15]) << 0x18)) {
        R_MarkLights(light, bit, int(uint(c2da_mem[node + 40 + 0 * 8]) | uint(c2da_mem[node + 40 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[node + 40 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[node + 40 + 0 * 8 + 3]) << 0x18))
        return
    }
    if (dist < -uint_bits_to_float(uint(c2da_mem[light + 12]) | uint(c2da_mem[light + 13]) << 0x8 | uint(c2da_mem[light + 14]) << 0x10 | uint(c2da_mem[light + 15]) << 0x18)) {
        R_MarkLights(light, bit, int(uint(c2da_mem[node + 40 + 1 * 8]) | uint(c2da_mem[node + 40 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[node + 40 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[node + 40 + 1 * 8 + 3]) << 0x18))
        return
    }
    let c2da_fresh1 : int = int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) + 240
    surf = int(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh1 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh1 + 3]) << 0x18) + int(uint16(uint(c2da_mem[node + 56]) | uint(c2da_mem[node + 57]) << 0x8)) * 104
    i_0 = 0
    while (i_0 < int(uint16(uint(c2da_mem[node + 58]) | uint(c2da_mem[node + 59]) << 0x8))) {
        if (int(uint(c2da_mem[surf + 4]) | uint(c2da_mem[surf + 5]) << 0x8 | uint(c2da_mem[surf + 6]) << 0x10 | uint(c2da_mem[surf + 7]) << 0x18) != r_dlightframecount) {
            let c2da_fresh2 : int = 0
            let c2da_fresh3 : uint = uint(c2da_fresh2)
            c2da_mem[surf + 8] = uint8(c2da_fresh3)
            c2da_mem[surf + 9] = uint8(c2da_fresh3 >> 0x8)
            c2da_mem[surf + 10] = uint8(c2da_fresh3 >> 0x10)
            c2da_mem[surf + 11] = uint8(c2da_fresh3 >> 0x18)
            let c2da_fresh4 : uint = uint(r_dlightframecount)
            c2da_mem[surf + 4] = uint8(c2da_fresh4)
            c2da_mem[surf + 5] = uint8(c2da_fresh4 >> 0x8)
            c2da_mem[surf + 6] = uint8(c2da_fresh4 >> 0x10)
            c2da_mem[surf + 7] = uint8(c2da_fresh4 >> 0x18)
        }
        let c2da_fresh5 : int = int(uint(c2da_mem[surf + 8]) | uint(c2da_mem[surf + 9]) << 0x8 | uint(c2da_mem[surf + 10]) << 0x10 | uint(c2da_mem[surf + 11]) << 0x18) | bit
        let c2da_fresh6 : uint = uint(c2da_fresh5)
        c2da_mem[surf + 8] = uint8(c2da_fresh6)
        c2da_mem[surf + 9] = uint8(c2da_fresh6 >> 0x8)
        c2da_mem[surf + 10] = uint8(c2da_fresh6 >> 0x10)
        c2da_mem[surf + 11] = uint8(c2da_fresh6 >> 0x18)
        i_0++
        surf += 104
    }
    R_MarkLights(light, bit, int(uint(c2da_mem[node + 40 + 0 * 8]) | uint(c2da_mem[node + 40 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[node + 40 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[node + 40 + 0 * 8 + 3]) << 0x18))
    R_MarkLights(light, bit, int(uint(c2da_mem[node + 40 + 1 * 8]) | uint(c2da_mem[node + 40 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[node + 40 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[node + 40 + 1 * 8 + 3]) << 0x18))
    return
}
var r_dlightframecount : int = default<int>

[export, sideeffects]
def R_AnimateLight() {
    var i_1 : int
    var k : int
    i_1 = int(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) * 10.0lf)
    for (j in range(0, 64)) {
        if (int(uint(c2da_mem[150528 + j * 68]) | uint(c2da_mem[150528 + j * 68 + 1]) << 0x8 | uint(c2da_mem[150528 + j * 68 + 2]) << 0x10 | uint(c2da_mem[150528 + j * 68 + 3]) << 0x18) == 0) {
            d_lightstylevalue[j] = 256
            continue
        }
        k = i_1 % int(uint(c2da_mem[150528 + j * 68]) | uint(c2da_mem[150528 + j * 68 + 1]) << 0x8 | uint(c2da_mem[150528 + j * 68 + 2]) << 0x10 | uint(c2da_mem[150528 + j * 68 + 3]) << 0x18)
        k = int(int8(c2da_mem[150528 + j * 68 + 4 + k])) - 97
        k *= 22
        d_lightstylevalue[j] = k
    }
    return
}
[export, sideeffects]
def R_LightPoint(var p : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = R_LightPoint_c2da_frame(p, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def RecursiveLightPoint(var node_0 : int; var start : int; var end : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = RecursiveLightPoint_c2da_frame(node_0, start, end, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[sideeffects]
def private R_LightPoint_c2da_frame(var p : int; c2da_fp : int) : int {
    var r : int
    let c2da_fresh7 : int = int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) + 512
    if (int(uint(c2da_mem[c2da_fresh7]) | uint(c2da_mem[c2da_fresh7 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh7 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh7 + 3]) << 0x18) == 0) {
        return 255
    }
    let c2da_fresh8 : float = uint_bits_to_float(uint(c2da_mem[p + 0 * 4]) | uint(c2da_mem[p + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 0 * 4 + 3]) << 0x18)
    let c2da_fresh9 : uint = float_bits_to_uint(c2da_fresh8)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh9)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh9 >> 0x18)
    let c2da_fresh10 : float = uint_bits_to_float(uint(c2da_mem[p + 1 * 4]) | uint(c2da_mem[p + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 1 * 4 + 3]) << 0x18)
    let c2da_fresh11 : uint = float_bits_to_uint(c2da_fresh10)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh11)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : float = uint_bits_to_float(uint(c2da_mem[p + 2 * 4]) | uint(c2da_mem[p + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 2 * 4 + 3]) << 0x18) - 2048.0
    let c2da_fresh13 : uint = float_bits_to_uint(c2da_fresh12)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh13)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh13 >> 0x18)
    let c2da_fresh14 : int = int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) + 208
    r = RecursiveLightPoint(int(uint(c2da_mem[c2da_fresh14]) | uint(c2da_mem[c2da_fresh14 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh14 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh14 + 3]) << 0x18), p, c2da_fp)
    if (r == -1) {
        r = 0
    }
    if (r < int(uint(c2da_mem[5352]) | uint(c2da_mem[5353]) << 0x8 | uint(c2da_mem[5354]) << 0x10 | uint(c2da_mem[5355]) << 0x18)) {
        r = int(uint(c2da_mem[5352]) | uint(c2da_mem[5353]) << 0x8 | uint(c2da_mem[5354]) << 0x10 | uint(c2da_mem[5355]) << 0x18)
    }
    return r
}
[sideeffects]
def private RecursiveLightPoint_c2da_frame(var node_0 : int; var start : int; var end : int; c2da_fp : int) : int {
    var r_0 : int
    var front : float
    var back : float
    var frac : float
    var side : int
    var plane : int
    var surf_0 : int
    var s : int
    var t : int
    var ds : int
    var dt : int
    var i_2 : int
    var tex : int
    var lightmap : int
    var maps : int
    if (int(uint(c2da_mem[node_0]) | uint(c2da_mem[node_0 + 1]) << 0x8 | uint(c2da_mem[node_0 + 2]) << 0x10 | uint(c2da_mem[node_0 + 3]) << 0x18) < 0) {
        return -1
    }
    plane = int(uint(c2da_mem[node_0 + 32]) | uint(c2da_mem[node_0 + 33]) << 0x8 | uint(c2da_mem[node_0 + 34]) << 0x10 | uint(c2da_mem[node_0 + 35]) << 0x18)
    front = uint_bits_to_float(uint(c2da_mem[start + 0 * 4]) | uint(c2da_mem[start + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 0 * 4]) | uint(c2da_mem[plane + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[start + 1 * 4]) | uint(c2da_mem[start + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 1 * 4]) | uint(c2da_mem[plane + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[start + 2 * 4]) | uint(c2da_mem[start + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 2 * 4]) | uint(c2da_mem[plane + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane + 12]) | uint(c2da_mem[plane + 13]) << 0x8 | uint(c2da_mem[plane + 14]) << 0x10 | uint(c2da_mem[plane + 15]) << 0x18)
    back = uint_bits_to_float(uint(c2da_mem[end + 0 * 4]) | uint(c2da_mem[end + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[end + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[end + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 0 * 4]) | uint(c2da_mem[plane + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[end + 1 * 4]) | uint(c2da_mem[end + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[end + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[end + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 1 * 4]) | uint(c2da_mem[plane + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[end + 2 * 4]) | uint(c2da_mem[end + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[end + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[end + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 2 * 4]) | uint(c2da_mem[plane + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane + 12]) | uint(c2da_mem[plane + 13]) << 0x8 | uint(c2da_mem[plane + 14]) << 0x10 | uint(c2da_mem[plane + 15]) << 0x18)
    side = front < 0.0 ? 1 : 0
    if ((back < 0.0 ? 1 : 0) == side) {
        return RecursiveLightPoint(int(uint(c2da_mem[node_0 + 40 + side * 8]) | uint(c2da_mem[node_0 + 40 + side * 8 + 1]) << 0x8 | uint(c2da_mem[node_0 + 40 + side * 8 + 2]) << 0x10 | uint(c2da_mem[node_0 + 40 + side * 8 + 3]) << 0x18), start, end)
    }
    frac = front / (front - back)
    let c2da_fresh15 : float = uint_bits_to_float(uint(c2da_mem[start + 0 * 4]) | uint(c2da_mem[start + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 0 * 4 + 3]) << 0x18) + (uint_bits_to_float(uint(c2da_mem[end + 0 * 4]) | uint(c2da_mem[end + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[end + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[end + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[start + 0 * 4]) | uint(c2da_mem[start + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 0 * 4 + 3]) << 0x18)) * frac
    let c2da_fresh16 : uint = float_bits_to_uint(c2da_fresh15)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh16)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh16 >> 0x18)
    let c2da_fresh17 : float = uint_bits_to_float(uint(c2da_mem[start + 1 * 4]) | uint(c2da_mem[start + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 1 * 4 + 3]) << 0x18) + (uint_bits_to_float(uint(c2da_mem[end + 1 * 4]) | uint(c2da_mem[end + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[end + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[end + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[start + 1 * 4]) | uint(c2da_mem[start + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 1 * 4 + 3]) << 0x18)) * frac
    let c2da_fresh18 : uint = float_bits_to_uint(c2da_fresh17)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh18)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh18 >> 0x18)
    let c2da_fresh19 : float = uint_bits_to_float(uint(c2da_mem[start + 2 * 4]) | uint(c2da_mem[start + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 2 * 4 + 3]) << 0x18) + (uint_bits_to_float(uint(c2da_mem[end + 2 * 4]) | uint(c2da_mem[end + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[end + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[end + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[start + 2 * 4]) | uint(c2da_mem[start + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 2 * 4 + 3]) << 0x18)) * frac
    let c2da_fresh20 : uint = float_bits_to_uint(c2da_fresh19)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh20)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh20 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh20 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh20 >> 0x18)
    r_0 = RecursiveLightPoint(int(uint(c2da_mem[node_0 + 40 + side * 8]) | uint(c2da_mem[node_0 + 40 + side * 8 + 1]) << 0x8 | uint(c2da_mem[node_0 + 40 + side * 8 + 2]) << 0x10 | uint(c2da_mem[node_0 + 40 + side * 8 + 3]) << 0x18), start, c2da_fp)
    if (r_0 >= 0) {
        return r_0
    }
    if ((back < 0.0 ? 1 : 0) == side) {
        return -1
    }
    let c2da_fresh21 : int = int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) + 240
    surf_0 = int(uint(c2da_mem[c2da_fresh21]) | uint(c2da_mem[c2da_fresh21 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh21 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh21 + 3]) << 0x18) + int(uint16(uint(c2da_mem[node_0 + 56]) | uint(c2da_mem[node_0 + 57]) << 0x8)) * 104
    i_2 = 0
    while (i_2 < int(uint16(uint(c2da_mem[node_0 + 58]) | uint(c2da_mem[node_0 + 59]) << 0x8))) {
        if ((int(uint(c2da_mem[surf_0 + 24]) | uint(c2da_mem[surf_0 + 25]) << 0x8 | uint(c2da_mem[surf_0 + 26]) << 0x10 | uint(c2da_mem[surf_0 + 27]) << 0x18) & 32) != 0) {
            i_2++
            surf_0 += 104
            continue
        }
        tex = int(uint(c2da_mem[surf_0 + 80]) | uint(c2da_mem[surf_0 + 81]) << 0x8 | uint(c2da_mem[surf_0 + 82]) << 0x10 | uint(c2da_mem[surf_0 + 83]) << 0x18)
        s = int(uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[tex + 0 * 16 + 0 * 4]) | uint(c2da_mem[tex + 0 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 0 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 0 * 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[tex + 0 * 16 + 1 * 4]) | uint(c2da_mem[tex + 0 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 0 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 0 * 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[tex + 0 * 16 + 2 * 4]) | uint(c2da_mem[tex + 0 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 0 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 0 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[tex + 0 * 16 + 3 * 4]) | uint(c2da_mem[tex + 0 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 0 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 0 * 16 + 3 * 4 + 3]) << 0x18))
        t = int(uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[tex + 1 * 16 + 0 * 4]) | uint(c2da_mem[tex + 1 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 1 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 1 * 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[tex + 1 * 16 + 1 * 4]) | uint(c2da_mem[tex + 1 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 1 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 1 * 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[tex + 1 * 16 + 2 * 4]) | uint(c2da_mem[tex + 1 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 1 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 1 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[tex + 1 * 16 + 3 * 4]) | uint(c2da_mem[tex + 1 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 1 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 1 * 16 + 3 * 4 + 3]) << 0x18))
        if (s < int(int16(uint(c2da_mem[surf_0 + 72 + 0 * 2]) | uint(c2da_mem[surf_0 + 72 + 0 * 2 + 1]) << 0x8)) || t < int(int16(uint(c2da_mem[surf_0 + 72 + 1 * 2]) | uint(c2da_mem[surf_0 + 72 + 1 * 2 + 1]) << 0x8))) {
            i_2++
            surf_0 += 104
            continue
        }
        ds = s - int(int16(uint(c2da_mem[surf_0 + 72 + 0 * 2]) | uint(c2da_mem[surf_0 + 72 + 0 * 2 + 1]) << 0x8))
        dt = t - int(int16(uint(c2da_mem[surf_0 + 72 + 1 * 2]) | uint(c2da_mem[surf_0 + 72 + 1 * 2 + 1]) << 0x8))
        if (ds > int(int16(uint(c2da_mem[surf_0 + 76 + 0 * 2]) | uint(c2da_mem[surf_0 + 76 + 0 * 2 + 1]) << 0x8)) || dt > int(int16(uint(c2da_mem[surf_0 + 76 + 1 * 2]) | uint(c2da_mem[surf_0 + 76 + 1 * 2 + 1]) << 0x8))) {
            i_2++
            surf_0 += 104
            continue
        }
        if (int(uint(c2da_mem[surf_0 + 96]) | uint(c2da_mem[surf_0 + 97]) << 0x8 | uint(c2da_mem[surf_0 + 98]) << 0x10 | uint(c2da_mem[surf_0 + 99]) << 0x18) == 0) {
            return 0
        }
        ds >>= 4
        dt >>= 4
        lightmap = int(uint(c2da_mem[surf_0 + 96]) | uint(c2da_mem[surf_0 + 97]) << 0x8 | uint(c2da_mem[surf_0 + 98]) << 0x10 | uint(c2da_mem[surf_0 + 99]) << 0x18)
        r_0 = 0
        if (lightmap != 0) {
            lightmap += dt * ((int(int16(uint(c2da_mem[surf_0 + 76 + 0 * 2]) | uint(c2da_mem[surf_0 + 76 + 0 * 2 + 1]) << 0x8)) >> 4) + 1) + ds
            maps = 0
            while (maps < 4 && int(c2da_mem[surf_0 + 88 + maps]) != 255) {
                r_0 = int(uint(r_0) + uint(c2da_mem[lightmap]) * uint(d_lightstylevalue[int(c2da_mem[surf_0 + 88 + maps])]))
                lightmap += ((int(int16(uint(c2da_mem[surf_0 + 76 + 0 * 2]) | uint(c2da_mem[surf_0 + 76 + 0 * 2 + 1]) << 0x8)) >> 4) + 1) * ((int(int16(uint(c2da_mem[surf_0 + 76 + 1 * 2]) | uint(c2da_mem[surf_0 + 76 + 1 * 2 + 1]) << 0x8)) >> 4) + 1)
                maps++
            }
            r_0 >>= 8
        }
        return r_0
    }
    let c2da_fresh22 : int = node_0 + 40 + (side == 0 ? 1 : 0) * 8
    return RecursiveLightPoint(int(uint(c2da_mem[c2da_fresh22]) | uint(c2da_mem[c2da_fresh22 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh22 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh22 + 3]) << 0x18), c2da_fp, end)
}
