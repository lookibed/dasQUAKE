var surfaces : int = default<int>

var surface_p : int = default<int>

var surf_max : int = default<int>

[export, sideeffects]
def R_BeginEdgeFrame() {
    var v : int
    edge_p = int(r_edges)  // nolint:PERF020
    edge_max = r_edges + int(r_numallocatededges) * 56
    surface_p = surfaces + 2 * 88
    let c2da_fresh0 : uint = 0u
    c2da_mem[surfaces + 1 * 88 + 16] = uint8(c2da_fresh0)
    c2da_mem[surfaces + 1 * 88 + 17] = uint8(c2da_fresh0 >> 0x8)
    c2da_mem[surfaces + 1 * 88 + 18] = uint8(c2da_fresh0 >> 0x10)
    c2da_mem[surfaces + 1 * 88 + 19] = uint8(c2da_fresh0 >> 0x18)
    c2da_mem[surfaces + 1 * 88 + 20] = 0u8
    c2da_mem[surfaces + 1 * 88 + 21] = 0u8
    c2da_mem[surfaces + 1 * 88 + 22] = 0u8
    c2da_mem[surfaces + 1 * 88 + 23] = 0u8
    let c2da_fresh1 : int = 64
    let c2da_fresh2 : uint = uint(c2da_fresh1)
    c2da_mem[surfaces + 1 * 88 + 36] = uint8(c2da_fresh2)
    c2da_mem[surfaces + 1 * 88 + 37] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[surfaces + 1 * 88 + 38] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[surfaces + 1 * 88 + 39] = uint8(c2da_fresh2 >> 0x18)
    if (uint_bits_to_float(uint(c2da_mem[391944]) | uint(c2da_mem[391945]) << 0x8 | uint(c2da_mem[391946]) << 0x10 | uint(c2da_mem[391947]) << 0x18) != 0.0) {
        pdrawfunc = 207
        let c2da_fresh3 : int = 0
        let c2da_fresh4 : uint = uint(c2da_fresh3)
        c2da_mem[surfaces + 1 * 88 + 24] = uint8(c2da_fresh4)
        c2da_mem[surfaces + 1 * 88 + 25] = uint8(c2da_fresh4 >> 0x8)
        c2da_mem[surfaces + 1 * 88 + 26] = uint8(c2da_fresh4 >> 0x10)
        c2da_mem[surfaces + 1 * 88 + 27] = uint8(c2da_fresh4 >> 0x18)
        r_currentkey = 1
    } else {
        pdrawfunc = 208
        let c2da_fresh5 : int = 2147483647
        let c2da_fresh6 : uint = uint(c2da_fresh5)
        c2da_mem[surfaces + 1 * 88 + 24] = uint8(c2da_fresh6)
        c2da_mem[surfaces + 1 * 88 + 25] = uint8(c2da_fresh6 >> 0x8)
        c2da_mem[surfaces + 1 * 88 + 26] = uint8(c2da_fresh6 >> 0x10)
        c2da_mem[surfaces + 1 * 88 + 27] = uint8(c2da_fresh6 >> 0x18)
        r_currentkey = 0
    }
    v = int(uint(c2da_mem[5204]) | uint(c2da_mem[5205]) << 0x8 | uint(c2da_mem[5206]) << 0x10 | uint(c2da_mem[5207]) << 0x18)
    while (v < int(uint(c2da_mem[5252]) | uint(c2da_mem[5253]) << 0x8 | uint(c2da_mem[5254]) << 0x10 | uint(c2da_mem[5255]) << 0x18)) {
        removeedges[v] = 0
        newedges[v] = int(removeedges[v])  // nolint:PERF020
        v++
    }
    return
}
var removeedges : int[1024]

var newedges : int[1024]

var r_currentkey : int = default<int>

[export, sideeffects]
def R_GenerateSpans() {
    var edge : int
    var surf : int
    r_bmodelactive = 0
    let c2da_fresh7 : int = surfaces + 1 * 88
    let c2da_fresh8 : uint = uint(c2da_fresh7)
    c2da_mem[surfaces + 1 * 88 + 8] = uint8(c2da_fresh8)
    c2da_mem[surfaces + 1 * 88 + 9] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[surfaces + 1 * 88 + 10] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[surfaces + 1 * 88 + 11] = uint8(c2da_fresh8 >> 0x18)
    c2da_mem[surfaces + 1 * 88 + 12] = 0u8
    c2da_mem[surfaces + 1 * 88 + 13] = 0u8
    c2da_mem[surfaces + 1 * 88 + 14] = 0u8
    c2da_mem[surfaces + 1 * 88 + 15] = 0u8
    let c2da_fresh9 : uint = uint(c2da_fresh7)
    c2da_mem[surfaces + 1 * 88] = uint8(c2da_fresh9)
    c2da_mem[surfaces + 1 * 88 + 1] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[surfaces + 1 * 88 + 2] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[surfaces + 1 * 88 + 3] = uint8(c2da_fresh9 >> 0x18)
    c2da_mem[surfaces + 1 * 88 + 4] = 0u8
    c2da_mem[surfaces + 1 * 88 + 5] = 0u8
    c2da_mem[surfaces + 1 * 88 + 6] = 0u8
    c2da_mem[surfaces + 1 * 88 + 7] = 0u8
    let c2da_fresh10 : uint = uint(edge_head_u_shift20)
    c2da_mem[surfaces + 1 * 88 + 28] = uint8(c2da_fresh10)
    c2da_mem[surfaces + 1 * 88 + 29] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[surfaces + 1 * 88 + 30] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[surfaces + 1 * 88 + 31] = uint8(c2da_fresh10 >> 0x18)
    edge = int(uint(c2da_mem[391712]) | uint(c2da_mem[391713]) << 0x8 | uint(c2da_mem[391714]) << 0x10 | uint(c2da_mem[391715]) << 0x18)
    while (edge != 391632) {
        if (uint16(uint(c2da_mem[edge + 24 + 0 * 2]) | uint(c2da_mem[edge + 24 + 0 * 2 + 1]) << 0x8) != 0x0) {
            surf = surfaces + int(uint16(uint(c2da_mem[edge + 24 + 0 * 2]) | uint(c2da_mem[edge + 24 + 0 * 2 + 1]) << 0x8)) * 88
            R_TrailingEdge(surf, edge)
            if (uint16(uint(c2da_mem[edge + 24 + 1 * 2]) | uint(c2da_mem[edge + 24 + 1 * 2 + 1]) << 0x8) == 0) {
                edge = int(uint(c2da_mem[edge + 16]) | uint(c2da_mem[edge + 17]) << 0x8 | uint(c2da_mem[edge + 18]) << 0x10 | uint(c2da_mem[edge + 19]) << 0x18)
                continue
            }
        }
        R_LeadingEdge(edge)
        edge = int(uint(c2da_mem[edge + 16]) | uint(c2da_mem[edge + 17]) << 0x8 | uint(c2da_mem[edge + 18]) << 0x10 | uint(c2da_mem[edge + 19]) << 0x18)
    }
    R_CleanupSpan()
    return
}
[export, sideeffects]
def R_CleanupSpan() {
    var surf_0 : int
    var iu : int
    var span : int
    surf_0 = int(uint(c2da_mem[surfaces + 1 * 88]) | uint(c2da_mem[surfaces + 1 * 88 + 1]) << 0x8 | uint(c2da_mem[surfaces + 1 * 88 + 2]) << 0x10 | uint(c2da_mem[surfaces + 1 * 88 + 3]) << 0x18)
    iu = edge_tail_u_shift20
    if (iu > int(uint(c2da_mem[surf_0 + 28]) | uint(c2da_mem[surf_0 + 29]) << 0x8 | uint(c2da_mem[surf_0 + 30]) << 0x10 | uint(c2da_mem[surf_0 + 31]) << 0x18)) {
        let c2da_fresh11 : int = span_p
        span_p += 24
        span = c2da_fresh11
        let c2da_fresh12 : int = int(uint(c2da_mem[surf_0 + 28]) | uint(c2da_mem[surf_0 + 29]) << 0x8 | uint(c2da_mem[surf_0 + 30]) << 0x10 | uint(c2da_mem[surf_0 + 31]) << 0x18)
        let c2da_fresh13 : uint = uint(c2da_fresh12)
        c2da_mem[span] = uint8(c2da_fresh13)
        c2da_mem[span + 1] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[span + 2] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[span + 3] = uint8(c2da_fresh13 >> 0x18)
        let c2da_fresh14 : int = iu - int(uint(c2da_mem[span]) | uint(c2da_mem[span + 1]) << 0x8 | uint(c2da_mem[span + 2]) << 0x10 | uint(c2da_mem[span + 3]) << 0x18)
        let c2da_fresh15 : uint = uint(c2da_fresh14)
        c2da_mem[span + 8] = uint8(c2da_fresh15)
        c2da_mem[span + 9] = uint8(c2da_fresh15 >> 0x8)
        c2da_mem[span + 10] = uint8(c2da_fresh15 >> 0x10)
        c2da_mem[span + 11] = uint8(c2da_fresh15 >> 0x18)
        let c2da_fresh16 : uint = uint(current_iv)
        c2da_mem[span + 4] = uint8(c2da_fresh16)
        c2da_mem[span + 5] = uint8(c2da_fresh16 >> 0x8)
        c2da_mem[span + 6] = uint8(c2da_fresh16 >> 0x10)
        c2da_mem[span + 7] = uint8(c2da_fresh16 >> 0x18)
        let c2da_fresh17 : int = int(uint(c2da_mem[surf_0 + 16]) | uint(c2da_mem[surf_0 + 17]) << 0x8 | uint(c2da_mem[surf_0 + 18]) << 0x10 | uint(c2da_mem[surf_0 + 19]) << 0x18)
        let c2da_fresh18 : uint = uint(c2da_fresh17)
        c2da_mem[span + 16] = uint8(c2da_fresh18)
        c2da_mem[span + 17] = uint8(c2da_fresh18 >> 0x8)
        c2da_mem[span + 18] = uint8(c2da_fresh18 >> 0x10)
        c2da_mem[span + 19] = uint8(c2da_fresh18 >> 0x18)
        c2da_mem[span + 20] = 0u8
        c2da_mem[span + 21] = 0u8
        c2da_mem[span + 22] = 0u8
        c2da_mem[span + 23] = 0u8
        let c2da_fresh19 : uint = uint(span)
        c2da_mem[surf_0 + 16] = uint8(c2da_fresh19)
        c2da_mem[surf_0 + 17] = uint8(c2da_fresh19 >> 0x8)
        c2da_mem[surf_0 + 18] = uint8(c2da_fresh19 >> 0x10)
        c2da_mem[surf_0 + 19] = uint8(c2da_fresh19 >> 0x18)
        c2da_mem[surf_0 + 20] = 0u8
        c2da_mem[surf_0 + 21] = 0u8
        c2da_mem[surf_0 + 22] = 0u8
        c2da_mem[surf_0 + 23] = 0u8
    }
    while (true) {
        let c2da_fresh20 : int = 0
        let c2da_fresh21 : uint = uint(c2da_fresh20)
        c2da_mem[surf_0 + 32] = uint8(c2da_fresh21)
        c2da_mem[surf_0 + 33] = uint8(c2da_fresh21 >> 0x8)
        c2da_mem[surf_0 + 34] = uint8(c2da_fresh21 >> 0x10)
        c2da_mem[surf_0 + 35] = uint8(c2da_fresh21 >> 0x18)
        surf_0 = int(uint(c2da_mem[surf_0]) | uint(c2da_mem[surf_0 + 1]) << 0x8 | uint(c2da_mem[surf_0 + 2]) << 0x10 | uint(c2da_mem[surf_0 + 3]) << 0x18)
        if (surf_0 == surfaces + 1 * 88) {
            break
        }
    }
    return
}
var current_iv : int = default<int>

var span_p : int = default<int>

var edge_tail_u_shift20 : int = default<int>

[export, sideeffects]
def R_LeadingEdge(var edge_0 : int) {
    var span_0 : int
    var surf_1 : int
    var surf2 : int
    var iu_0 : int
    var fu : double
    var newzi : double
    var testzi : double
    var newzitop : double
    var newzibottom : double
    if (uint16(uint(c2da_mem[edge_0 + 24 + 1 * 2]) | uint(c2da_mem[edge_0 + 24 + 1 * 2 + 1]) << 0x8) != 0x0) {
        goto label 1
    }
    label 0:
    return
    label 1:
    surf_1 = surfaces + int(uint16(uint(c2da_mem[edge_0 + 24 + 1 * 2]) | uint(c2da_mem[edge_0 + 24 + 1 * 2 + 1]) << 0x8)) * 88
    let c2da_fresh22 : int = int(uint(c2da_mem[surf_1 + 32]) | uint(c2da_mem[surf_1 + 33]) << 0x8 | uint(c2da_mem[surf_1 + 34]) << 0x10 | uint(c2da_mem[surf_1 + 35]) << 0x18)
    let c2da_fresh23 : int = c2da_fresh22 + 1
    let c2da_fresh24 : uint = uint(c2da_fresh23)
    c2da_mem[surf_1 + 32] = uint8(c2da_fresh24)
    c2da_mem[surf_1 + 33] = uint8(c2da_fresh24 >> 0x8)
    c2da_mem[surf_1 + 34] = uint8(c2da_fresh24 >> 0x10)
    c2da_mem[surf_1 + 35] = uint8(c2da_fresh24 >> 0x18)
    if (c2da_fresh23 == 1) {
        goto label 3
    }
    label 2:
    goto label 0
    label 3:
    if ((uint(c2da_mem[surf_1 + 60]) | uint(c2da_mem[surf_1 + 61]) << 0x8 | uint(c2da_mem[surf_1 + 62]) << 0x10 | uint(c2da_mem[surf_1 + 63]) << 0x18) != 0u) {
        goto label 24
    }
    label 4:
    surf2 = int(uint(c2da_mem[surfaces + 1 * 88]) | uint(c2da_mem[surfaces + 1 * 88 + 1]) << 0x8 | uint(c2da_mem[surfaces + 1 * 88 + 2]) << 0x10 | uint(c2da_mem[surfaces + 1 * 88 + 3]) << 0x18)
    if (int(uint(c2da_mem[surf_1 + 24]) | uint(c2da_mem[surf_1 + 25]) << 0x8 | uint(c2da_mem[surf_1 + 26]) << 0x10 | uint(c2da_mem[surf_1 + 27]) << 0x18) < int(uint(c2da_mem[surf2 + 24]) | uint(c2da_mem[surf2 + 25]) << 0x8 | uint(c2da_mem[surf2 + 26]) << 0x10 | uint(c2da_mem[surf2 + 27]) << 0x18)) {
        goto label 23
    }
    if ((uint(c2da_mem[surf_1 + 60]) | uint(c2da_mem[surf_1 + 61]) << 0x8 | uint(c2da_mem[surf_1 + 62]) << 0x10 | uint(c2da_mem[surf_1 + 63]) << 0x18) != 0x0 && int(uint(c2da_mem[surf_1 + 24]) | uint(c2da_mem[surf_1 + 25]) << 0x8 | uint(c2da_mem[surf_1 + 26]) << 0x10 | uint(c2da_mem[surf_1 + 27]) << 0x18) == int(uint(c2da_mem[surf2 + 24]) | uint(c2da_mem[surf2 + 25]) << 0x8 | uint(c2da_mem[surf2 + 26]) << 0x10 | uint(c2da_mem[surf2 + 27]) << 0x18)) {
        goto label 15
    }
    label 5:
    label 6:
    label 7:
    surf2 = int(uint(c2da_mem[surf2]) | uint(c2da_mem[surf2 + 1]) << 0x8 | uint(c2da_mem[surf2 + 2]) << 0x10 | uint(c2da_mem[surf2 + 3]) << 0x18)
    if (int(uint(c2da_mem[surf_1 + 24]) | uint(c2da_mem[surf_1 + 25]) << 0x8 | uint(c2da_mem[surf_1 + 26]) << 0x10 | uint(c2da_mem[surf_1 + 27]) << 0x18) > int(uint(c2da_mem[surf2 + 24]) | uint(c2da_mem[surf2 + 25]) << 0x8 | uint(c2da_mem[surf2 + 26]) << 0x10 | uint(c2da_mem[surf2 + 27]) << 0x18)) {
        goto label 7
    }
    if (int(uint(c2da_mem[surf_1 + 24]) | uint(c2da_mem[surf_1 + 25]) << 0x8 | uint(c2da_mem[surf_1 + 26]) << 0x10 | uint(c2da_mem[surf_1 + 27]) << 0x18) == int(uint(c2da_mem[surf2 + 24]) | uint(c2da_mem[surf2 + 25]) << 0x8 | uint(c2da_mem[surf2 + 26]) << 0x10 | uint(c2da_mem[surf2 + 27]) << 0x18)) {
        goto label 9
    }
    label 8:
    let c2da_fresh35 : uint = uint(surf2)
    c2da_mem[surf_1] = uint8(c2da_fresh35)
    c2da_mem[surf_1 + 1] = uint8(c2da_fresh35 >> 0x8)
    c2da_mem[surf_1 + 2] = uint8(c2da_fresh35 >> 0x10)
    c2da_mem[surf_1 + 3] = uint8(c2da_fresh35 >> 0x18)
    c2da_mem[surf_1 + 4] = 0u8
    c2da_mem[surf_1 + 5] = 0u8
    c2da_mem[surf_1 + 6] = 0u8
    c2da_mem[surf_1 + 7] = 0u8
    let c2da_fresh36 : int = int(uint(c2da_mem[surf2 + 8]) | uint(c2da_mem[surf2 + 9]) << 0x8 | uint(c2da_mem[surf2 + 10]) << 0x10 | uint(c2da_mem[surf2 + 11]) << 0x18)
    let c2da_fresh37 : uint = uint(c2da_fresh36)
    c2da_mem[surf_1 + 8] = uint8(c2da_fresh37)
    c2da_mem[surf_1 + 9] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[surf_1 + 10] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[surf_1 + 11] = uint8(c2da_fresh37 >> 0x18)
    c2da_mem[surf_1 + 12] = 0u8
    c2da_mem[surf_1 + 13] = 0u8
    c2da_mem[surf_1 + 14] = 0u8
    c2da_mem[surf_1 + 15] = 0u8
    let c2da_fresh38 : int = int(uint(c2da_mem[surf2 + 8]) | uint(c2da_mem[surf2 + 9]) << 0x8 | uint(c2da_mem[surf2 + 10]) << 0x10 | uint(c2da_mem[surf2 + 11]) << 0x18)
    let c2da_fresh39 : uint = uint(surf_1)
    c2da_mem[c2da_fresh38] = uint8(c2da_fresh39)
    c2da_mem[c2da_fresh38 + 1] = uint8(c2da_fresh39 >> 0x8)
    c2da_mem[c2da_fresh38 + 2] = uint8(c2da_fresh39 >> 0x10)
    c2da_mem[c2da_fresh38 + 3] = uint8(c2da_fresh39 >> 0x18)
    c2da_mem[c2da_fresh38 + 4] = 0u8
    c2da_mem[c2da_fresh38 + 5] = 0u8
    c2da_mem[c2da_fresh38 + 6] = 0u8
    c2da_mem[c2da_fresh38 + 7] = 0u8
    let c2da_fresh40 : uint = uint(surf_1)
    c2da_mem[surf2 + 8] = uint8(c2da_fresh40)
    c2da_mem[surf2 + 9] = uint8(c2da_fresh40 >> 0x8)
    c2da_mem[surf2 + 10] = uint8(c2da_fresh40 >> 0x10)
    c2da_mem[surf2 + 11] = uint8(c2da_fresh40 >> 0x18)
    c2da_mem[surf2 + 12] = 0u8
    c2da_mem[surf2 + 13] = 0u8
    c2da_mem[surf2 + 14] = 0u8
    c2da_mem[surf2 + 15] = 0u8
    goto label 2
    label 9:
    if ((uint(c2da_mem[surf_1 + 60]) | uint(c2da_mem[surf_1 + 61]) << 0x8 | uint(c2da_mem[surf_1 + 62]) << 0x10 | uint(c2da_mem[surf_1 + 63]) << 0x18) == 0u) {
        goto label 14
    }
    fu = double(float(int(uint(c2da_mem[edge_0]) | uint(c2da_mem[edge_0 + 1]) << 0x8 | uint(c2da_mem[edge_0 + 2]) << 0x10 | uint(c2da_mem[edge_0 + 3]) << 0x18) - 1048575)) * (1.0lf / 1048576.0lf)
    newzi = double(uint_bits_to_float(uint(c2da_mem[surf_1 + 64]) | uint(c2da_mem[surf_1 + 65]) << 0x8 | uint(c2da_mem[surf_1 + 66]) << 0x10 | uint(c2da_mem[surf_1 + 67]) << 0x18) + fv * uint_bits_to_float(uint(c2da_mem[surf_1 + 72]) | uint(c2da_mem[surf_1 + 73]) << 0x8 | uint(c2da_mem[surf_1 + 74]) << 0x10 | uint(c2da_mem[surf_1 + 75]) << 0x18)) + fu * double(uint_bits_to_float(uint(c2da_mem[surf_1 + 68]) | uint(c2da_mem[surf_1 + 69]) << 0x8 | uint(c2da_mem[surf_1 + 70]) << 0x10 | uint(c2da_mem[surf_1 + 71]) << 0x18))
    newzibottom = newzi * 0.99lf
    testzi = double(uint_bits_to_float(uint(c2da_mem[surf2 + 64]) | uint(c2da_mem[surf2 + 65]) << 0x8 | uint(c2da_mem[surf2 + 66]) << 0x10 | uint(c2da_mem[surf2 + 67]) << 0x18) + fv * uint_bits_to_float(uint(c2da_mem[surf2 + 72]) | uint(c2da_mem[surf2 + 73]) << 0x8 | uint(c2da_mem[surf2 + 74]) << 0x10 | uint(c2da_mem[surf2 + 75]) << 0x18)) + fu * double(uint_bits_to_float(uint(c2da_mem[surf2 + 68]) | uint(c2da_mem[surf2 + 69]) << 0x8 | uint(c2da_mem[surf2 + 70]) << 0x10 | uint(c2da_mem[surf2 + 71]) << 0x18))
    if (newzibottom >= testzi) {
        goto label 13
    }
    newzitop = newzi * 1.01lf
    if (newzitop >= testzi) {
        goto label 11
    }
    label 10:
    goto label 6
    label 11:
    if (uint_bits_to_float(uint(c2da_mem[surf_1 + 68]) | uint(c2da_mem[surf_1 + 69]) << 0x8 | uint(c2da_mem[surf_1 + 70]) << 0x10 | uint(c2da_mem[surf_1 + 71]) << 0x18) >= uint_bits_to_float(uint(c2da_mem[surf2 + 68]) | uint(c2da_mem[surf2 + 69]) << 0x8 | uint(c2da_mem[surf2 + 70]) << 0x10 | uint(c2da_mem[surf2 + 71]) << 0x18)) {
        goto label 12
    }
    goto label 10
    label 12:
    goto label 8
    label 13:
    goto label 8
    label 14:
    goto label 6
    label 15:
    fu = double(float(int(uint(c2da_mem[edge_0]) | uint(c2da_mem[edge_0 + 1]) << 0x8 | uint(c2da_mem[edge_0 + 2]) << 0x10 | uint(c2da_mem[edge_0 + 3]) << 0x18) - 1048575)) * (1.0lf / 1048576.0lf)
    newzi = double(uint_bits_to_float(uint(c2da_mem[surf_1 + 64]) | uint(c2da_mem[surf_1 + 65]) << 0x8 | uint(c2da_mem[surf_1 + 66]) << 0x10 | uint(c2da_mem[surf_1 + 67]) << 0x18) + fv * uint_bits_to_float(uint(c2da_mem[surf_1 + 72]) | uint(c2da_mem[surf_1 + 73]) << 0x8 | uint(c2da_mem[surf_1 + 74]) << 0x10 | uint(c2da_mem[surf_1 + 75]) << 0x18)) + fu * double(uint_bits_to_float(uint(c2da_mem[surf_1 + 68]) | uint(c2da_mem[surf_1 + 69]) << 0x8 | uint(c2da_mem[surf_1 + 70]) << 0x10 | uint(c2da_mem[surf_1 + 71]) << 0x18))
    newzibottom = newzi * 0.99lf
    testzi = double(uint_bits_to_float(uint(c2da_mem[surf2 + 64]) | uint(c2da_mem[surf2 + 65]) << 0x8 | uint(c2da_mem[surf2 + 66]) << 0x10 | uint(c2da_mem[surf2 + 67]) << 0x18) + fv * uint_bits_to_float(uint(c2da_mem[surf2 + 72]) | uint(c2da_mem[surf2 + 73]) << 0x8 | uint(c2da_mem[surf2 + 74]) << 0x10 | uint(c2da_mem[surf2 + 75]) << 0x18)) + fu * double(uint_bits_to_float(uint(c2da_mem[surf2 + 68]) | uint(c2da_mem[surf2 + 69]) << 0x8 | uint(c2da_mem[surf2 + 70]) << 0x10 | uint(c2da_mem[surf2 + 71]) << 0x18))
    if (newzibottom >= testzi) {
        goto label 22
    }
    newzitop = newzi * 1.01lf
    if (newzitop >= testzi) {
        goto label 17
    }
    label 16:
    goto label 5
    label 17:
    if (uint_bits_to_float(uint(c2da_mem[surf_1 + 68]) | uint(c2da_mem[surf_1 + 69]) << 0x8 | uint(c2da_mem[surf_1 + 70]) << 0x10 | uint(c2da_mem[surf_1 + 71]) << 0x18) >= uint_bits_to_float(uint(c2da_mem[surf2 + 68]) | uint(c2da_mem[surf2 + 69]) << 0x8 | uint(c2da_mem[surf2 + 70]) << 0x10 | uint(c2da_mem[surf2 + 71]) << 0x18)) {
        goto label 18
    }
    goto label 16
    label 18:
    label 19:
    iu_0 = int(uint(c2da_mem[edge_0]) | uint(c2da_mem[edge_0 + 1]) << 0x8 | uint(c2da_mem[edge_0 + 2]) << 0x10 | uint(c2da_mem[edge_0 + 3]) << 0x18) >> 20
    if (iu_0 > int(uint(c2da_mem[surf2 + 28]) | uint(c2da_mem[surf2 + 29]) << 0x8 | uint(c2da_mem[surf2 + 30]) << 0x10 | uint(c2da_mem[surf2 + 31]) << 0x18)) {
        goto label 21
    }
    label 20:
    let c2da_fresh34 : uint = uint(iu_0)
    c2da_mem[surf_1 + 28] = uint8(c2da_fresh34)
    c2da_mem[surf_1 + 29] = uint8(c2da_fresh34 >> 0x8)
    c2da_mem[surf_1 + 30] = uint8(c2da_fresh34 >> 0x10)
    c2da_mem[surf_1 + 31] = uint8(c2da_fresh34 >> 0x18)
    goto label 8
    label 21:
    let c2da_fresh25 : int = span_p
    span_p += 24
    span_0 = c2da_fresh25
    let c2da_fresh26 : int = int(uint(c2da_mem[surf2 + 28]) | uint(c2da_mem[surf2 + 29]) << 0x8 | uint(c2da_mem[surf2 + 30]) << 0x10 | uint(c2da_mem[surf2 + 31]) << 0x18)
    let c2da_fresh27 : uint = uint(c2da_fresh26)
    c2da_mem[span_0] = uint8(c2da_fresh27)
    c2da_mem[span_0 + 1] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[span_0 + 2] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[span_0 + 3] = uint8(c2da_fresh27 >> 0x18)
    let c2da_fresh28 : int = iu_0 - int(uint(c2da_mem[span_0]) | uint(c2da_mem[span_0 + 1]) << 0x8 | uint(c2da_mem[span_0 + 2]) << 0x10 | uint(c2da_mem[span_0 + 3]) << 0x18)
    let c2da_fresh29 : uint = uint(c2da_fresh28)
    c2da_mem[span_0 + 8] = uint8(c2da_fresh29)
    c2da_mem[span_0 + 9] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[span_0 + 10] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[span_0 + 11] = uint8(c2da_fresh29 >> 0x18)
    let c2da_fresh30 : uint = uint(current_iv)
    c2da_mem[span_0 + 4] = uint8(c2da_fresh30)
    c2da_mem[span_0 + 5] = uint8(c2da_fresh30 >> 0x8)
    c2da_mem[span_0 + 6] = uint8(c2da_fresh30 >> 0x10)
    c2da_mem[span_0 + 7] = uint8(c2da_fresh30 >> 0x18)
    let c2da_fresh31 : int = int(uint(c2da_mem[surf2 + 16]) | uint(c2da_mem[surf2 + 17]) << 0x8 | uint(c2da_mem[surf2 + 18]) << 0x10 | uint(c2da_mem[surf2 + 19]) << 0x18)
    let c2da_fresh32 : uint = uint(c2da_fresh31)
    c2da_mem[span_0 + 16] = uint8(c2da_fresh32)
    c2da_mem[span_0 + 17] = uint8(c2da_fresh32 >> 0x8)
    c2da_mem[span_0 + 18] = uint8(c2da_fresh32 >> 0x10)
    c2da_mem[span_0 + 19] = uint8(c2da_fresh32 >> 0x18)
    c2da_mem[span_0 + 20] = 0u8
    c2da_mem[span_0 + 21] = 0u8
    c2da_mem[span_0 + 22] = 0u8
    c2da_mem[span_0 + 23] = 0u8
    let c2da_fresh33 : uint = uint(span_0)
    c2da_mem[surf2 + 16] = uint8(c2da_fresh33)
    c2da_mem[surf2 + 17] = uint8(c2da_fresh33 >> 0x8)
    c2da_mem[surf2 + 18] = uint8(c2da_fresh33 >> 0x10)
    c2da_mem[surf2 + 19] = uint8(c2da_fresh33 >> 0x18)
    c2da_mem[surf2 + 20] = 0u8
    c2da_mem[surf2 + 21] = 0u8
    c2da_mem[surf2 + 22] = 0u8
    c2da_mem[surf2 + 23] = 0u8
    goto label 20
    label 22:
    goto label 19
    label 23:
    goto label 19
    label 24:
    r_bmodelactive = r_bmodelactive + 1
    goto label 4
    panic("unreachable: fell out of a translated control-flow graph")
}
var fv : float = default<float>

[export, sideeffects]
def R_TrailingEdge(var surf_2 : int; var edge_1 : int) {
    var span_1 : int
    var iu_1 : int
    let c2da_fresh41 : int = int(uint(c2da_mem[surf_2 + 32]) | uint(c2da_mem[surf_2 + 33]) << 0x8 | uint(c2da_mem[surf_2 + 34]) << 0x10 | uint(c2da_mem[surf_2 + 35]) << 0x18)
    let c2da_fresh42 : int = c2da_fresh41 - 1
    let c2da_fresh43 : uint = uint(c2da_fresh42)
    c2da_mem[surf_2 + 32] = uint8(c2da_fresh43)
    c2da_mem[surf_2 + 33] = uint8(c2da_fresh43 >> 0x8)
    c2da_mem[surf_2 + 34] = uint8(c2da_fresh43 >> 0x10)
    c2da_mem[surf_2 + 35] = uint8(c2da_fresh43 >> 0x18)
    if (c2da_fresh42 == 0) {
        if ((uint(c2da_mem[surf_2 + 60]) | uint(c2da_mem[surf_2 + 61]) << 0x8 | uint(c2da_mem[surf_2 + 62]) << 0x10 | uint(c2da_mem[surf_2 + 63]) << 0x18) != 0u) {
            r_bmodelactive = r_bmodelactive - 1
        }
        if (surf_2 == int(uint(c2da_mem[surfaces + 1 * 88]) | uint(c2da_mem[surfaces + 1 * 88 + 1]) << 0x8 | uint(c2da_mem[surfaces + 1 * 88 + 2]) << 0x10 | uint(c2da_mem[surfaces + 1 * 88 + 3]) << 0x18)) {
            iu_1 = int(uint(c2da_mem[edge_1]) | uint(c2da_mem[edge_1 + 1]) << 0x8 | uint(c2da_mem[edge_1 + 2]) << 0x10 | uint(c2da_mem[edge_1 + 3]) << 0x18) >> 20
            if (iu_1 > int(uint(c2da_mem[surf_2 + 28]) | uint(c2da_mem[surf_2 + 29]) << 0x8 | uint(c2da_mem[surf_2 + 30]) << 0x10 | uint(c2da_mem[surf_2 + 31]) << 0x18)) {
                let c2da_fresh44 : int = span_p
                span_p += 24
                span_1 = c2da_fresh44
                let c2da_fresh45 : int = int(uint(c2da_mem[surf_2 + 28]) | uint(c2da_mem[surf_2 + 29]) << 0x8 | uint(c2da_mem[surf_2 + 30]) << 0x10 | uint(c2da_mem[surf_2 + 31]) << 0x18)
                let c2da_fresh46 : uint = uint(c2da_fresh45)
                c2da_mem[span_1] = uint8(c2da_fresh46)
                c2da_mem[span_1 + 1] = uint8(c2da_fresh46 >> 0x8)
                c2da_mem[span_1 + 2] = uint8(c2da_fresh46 >> 0x10)
                c2da_mem[span_1 + 3] = uint8(c2da_fresh46 >> 0x18)
                let c2da_fresh47 : int = iu_1 - int(uint(c2da_mem[span_1]) | uint(c2da_mem[span_1 + 1]) << 0x8 | uint(c2da_mem[span_1 + 2]) << 0x10 | uint(c2da_mem[span_1 + 3]) << 0x18)
                let c2da_fresh48 : uint = uint(c2da_fresh47)
                c2da_mem[span_1 + 8] = uint8(c2da_fresh48)
                c2da_mem[span_1 + 9] = uint8(c2da_fresh48 >> 0x8)
                c2da_mem[span_1 + 10] = uint8(c2da_fresh48 >> 0x10)
                c2da_mem[span_1 + 11] = uint8(c2da_fresh48 >> 0x18)
                let c2da_fresh49 : uint = uint(current_iv)
                c2da_mem[span_1 + 4] = uint8(c2da_fresh49)
                c2da_mem[span_1 + 5] = uint8(c2da_fresh49 >> 0x8)
                c2da_mem[span_1 + 6] = uint8(c2da_fresh49 >> 0x10)
                c2da_mem[span_1 + 7] = uint8(c2da_fresh49 >> 0x18)
                let c2da_fresh50 : int = int(uint(c2da_mem[surf_2 + 16]) | uint(c2da_mem[surf_2 + 17]) << 0x8 | uint(c2da_mem[surf_2 + 18]) << 0x10 | uint(c2da_mem[surf_2 + 19]) << 0x18)
                let c2da_fresh51 : uint = uint(c2da_fresh50)
                c2da_mem[span_1 + 16] = uint8(c2da_fresh51)
                c2da_mem[span_1 + 17] = uint8(c2da_fresh51 >> 0x8)
                c2da_mem[span_1 + 18] = uint8(c2da_fresh51 >> 0x10)
                c2da_mem[span_1 + 19] = uint8(c2da_fresh51 >> 0x18)
                c2da_mem[span_1 + 20] = 0u8
                c2da_mem[span_1 + 21] = 0u8
                c2da_mem[span_1 + 22] = 0u8
                c2da_mem[span_1 + 23] = 0u8
                let c2da_fresh52 : uint = uint(span_1)
                c2da_mem[surf_2 + 16] = uint8(c2da_fresh52)
                c2da_mem[surf_2 + 17] = uint8(c2da_fresh52 >> 0x8)
                c2da_mem[surf_2 + 18] = uint8(c2da_fresh52 >> 0x10)
                c2da_mem[surf_2 + 19] = uint8(c2da_fresh52 >> 0x18)
                c2da_mem[surf_2 + 20] = 0u8
                c2da_mem[surf_2 + 21] = 0u8
                c2da_mem[surf_2 + 22] = 0u8
                c2da_mem[surf_2 + 23] = 0u8
            }
            let c2da_fresh53 : int = int(uint(c2da_mem[surf_2]) | uint(c2da_mem[surf_2 + 1]) << 0x8 | uint(c2da_mem[surf_2 + 2]) << 0x10 | uint(c2da_mem[surf_2 + 3]) << 0x18) + 28
            let c2da_fresh54 : uint = uint(iu_1)
            c2da_mem[c2da_fresh53] = uint8(c2da_fresh54)
            c2da_mem[c2da_fresh53 + 1] = uint8(c2da_fresh54 >> 0x8)
            c2da_mem[c2da_fresh53 + 2] = uint8(c2da_fresh54 >> 0x10)
            c2da_mem[c2da_fresh53 + 3] = uint8(c2da_fresh54 >> 0x18)
        }
        let c2da_fresh55 : int = int(uint(c2da_mem[surf_2 + 8]) | uint(c2da_mem[surf_2 + 9]) << 0x8 | uint(c2da_mem[surf_2 + 10]) << 0x10 | uint(c2da_mem[surf_2 + 11]) << 0x18)
        let c2da_fresh56 : int = int(uint(c2da_mem[surf_2]) | uint(c2da_mem[surf_2 + 1]) << 0x8 | uint(c2da_mem[surf_2 + 2]) << 0x10 | uint(c2da_mem[surf_2 + 3]) << 0x18)
        let c2da_fresh57 : uint = uint(c2da_fresh56)
        c2da_mem[c2da_fresh55] = uint8(c2da_fresh57)
        c2da_mem[c2da_fresh55 + 1] = uint8(c2da_fresh57 >> 0x8)
        c2da_mem[c2da_fresh55 + 2] = uint8(c2da_fresh57 >> 0x10)
        c2da_mem[c2da_fresh55 + 3] = uint8(c2da_fresh57 >> 0x18)
        c2da_mem[c2da_fresh55 + 4] = 0u8
        c2da_mem[c2da_fresh55 + 5] = 0u8
        c2da_mem[c2da_fresh55 + 6] = 0u8
        c2da_mem[c2da_fresh55 + 7] = 0u8
        let c2da_fresh58 : int = int(uint(c2da_mem[surf_2]) | uint(c2da_mem[surf_2 + 1]) << 0x8 | uint(c2da_mem[surf_2 + 2]) << 0x10 | uint(c2da_mem[surf_2 + 3]) << 0x18) + 8
        let c2da_fresh59 : int = int(uint(c2da_mem[surf_2 + 8]) | uint(c2da_mem[surf_2 + 9]) << 0x8 | uint(c2da_mem[surf_2 + 10]) << 0x10 | uint(c2da_mem[surf_2 + 11]) << 0x18)
        let c2da_fresh60 : uint = uint(c2da_fresh59)
        c2da_mem[c2da_fresh58] = uint8(c2da_fresh60)
        c2da_mem[c2da_fresh58 + 1] = uint8(c2da_fresh60 >> 0x8)
        c2da_mem[c2da_fresh58 + 2] = uint8(c2da_fresh60 >> 0x10)
        c2da_mem[c2da_fresh58 + 3] = uint8(c2da_fresh60 >> 0x18)
        c2da_mem[c2da_fresh58 + 4] = 0u8
        c2da_mem[c2da_fresh58 + 5] = 0u8
        c2da_mem[c2da_fresh58 + 6] = 0u8
        c2da_mem[c2da_fresh58 + 7] = 0u8
    }
    return
}
var edge_head_u_shift20 : int = default<int>

var private pdrawfunc : int = default<int>

[export, sideeffects]
def R_GenerateSpansBackward() {
    var edge_2 : int
    r_bmodelactive = 0
    let c2da_fresh61 : int = surfaces + 1 * 88
    let c2da_fresh62 : uint = uint(c2da_fresh61)
    c2da_mem[surfaces + 1 * 88 + 8] = uint8(c2da_fresh62)
    c2da_mem[surfaces + 1 * 88 + 9] = uint8(c2da_fresh62 >> 0x8)
    c2da_mem[surfaces + 1 * 88 + 10] = uint8(c2da_fresh62 >> 0x10)
    c2da_mem[surfaces + 1 * 88 + 11] = uint8(c2da_fresh62 >> 0x18)
    c2da_mem[surfaces + 1 * 88 + 12] = 0u8
    c2da_mem[surfaces + 1 * 88 + 13] = 0u8
    c2da_mem[surfaces + 1 * 88 + 14] = 0u8
    c2da_mem[surfaces + 1 * 88 + 15] = 0u8
    let c2da_fresh63 : uint = uint(c2da_fresh61)
    c2da_mem[surfaces + 1 * 88] = uint8(c2da_fresh63)
    c2da_mem[surfaces + 1 * 88 + 1] = uint8(c2da_fresh63 >> 0x8)
    c2da_mem[surfaces + 1 * 88 + 2] = uint8(c2da_fresh63 >> 0x10)
    c2da_mem[surfaces + 1 * 88 + 3] = uint8(c2da_fresh63 >> 0x18)
    c2da_mem[surfaces + 1 * 88 + 4] = 0u8
    c2da_mem[surfaces + 1 * 88 + 5] = 0u8
    c2da_mem[surfaces + 1 * 88 + 6] = 0u8
    c2da_mem[surfaces + 1 * 88 + 7] = 0u8
    let c2da_fresh64 : uint = uint(edge_head_u_shift20)
    c2da_mem[surfaces + 1 * 88 + 28] = uint8(c2da_fresh64)
    c2da_mem[surfaces + 1 * 88 + 29] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[surfaces + 1 * 88 + 30] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[surfaces + 1 * 88 + 31] = uint8(c2da_fresh64 >> 0x18)
    edge_2 = int(uint(c2da_mem[391712]) | uint(c2da_mem[391713]) << 0x8 | uint(c2da_mem[391714]) << 0x10 | uint(c2da_mem[391715]) << 0x18)
    while (edge_2 != 391632) {
        if (uint16(uint(c2da_mem[edge_2 + 24 + 0 * 2]) | uint(c2da_mem[edge_2 + 24 + 0 * 2 + 1]) << 0x8) != 0x0) {
            R_TrailingEdge(surfaces + int(uint16(uint(c2da_mem[edge_2 + 24 + 0 * 2]) | uint(c2da_mem[edge_2 + 24 + 0 * 2 + 1]) << 0x8)) * 88, edge_2)
        }
        if (uint16(uint(c2da_mem[edge_2 + 24 + 1 * 2]) | uint(c2da_mem[edge_2 + 24 + 1 * 2 + 1]) << 0x8) != 0x0) {
            R_LeadingEdgeBackwards(edge_2)
        }
        edge_2 = int(uint(c2da_mem[edge_2 + 16]) | uint(c2da_mem[edge_2 + 17]) << 0x8 | uint(c2da_mem[edge_2 + 18]) << 0x10 | uint(c2da_mem[edge_2 + 19]) << 0x18)
    }
    R_CleanupSpan()
    return
}
[export, sideeffects]
def R_LeadingEdgeBackwards(var edge_3 : int) {
    var span_2 : int
    var surf_3 : int
    var surf2_0 : int
    var iu_2 : int
    surf_3 = surfaces + int(uint16(uint(c2da_mem[edge_3 + 24 + 1 * 2]) | uint(c2da_mem[edge_3 + 24 + 1 * 2 + 1]) << 0x8)) * 88
    let c2da_fresh65 : int = int(uint(c2da_mem[surf_3 + 32]) | uint(c2da_mem[surf_3 + 33]) << 0x8 | uint(c2da_mem[surf_3 + 34]) << 0x10 | uint(c2da_mem[surf_3 + 35]) << 0x18)
    let c2da_fresh66 : int = c2da_fresh65 + 1
    let c2da_fresh67 : uint = uint(c2da_fresh66)
    c2da_mem[surf_3 + 32] = uint8(c2da_fresh67)
    c2da_mem[surf_3 + 33] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[surf_3 + 34] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[surf_3 + 35] = uint8(c2da_fresh67 >> 0x18)
    if (c2da_fresh66 == 1) {
        goto label 1
    }
    label 0:
    return
    label 1:
    surf2_0 = int(uint(c2da_mem[surfaces + 1 * 88]) | uint(c2da_mem[surfaces + 1 * 88 + 1]) << 0x8 | uint(c2da_mem[surfaces + 1 * 88 + 2]) << 0x10 | uint(c2da_mem[surfaces + 1 * 88 + 3]) << 0x18)
    if (int(uint(c2da_mem[surf_3 + 24]) | uint(c2da_mem[surf_3 + 25]) << 0x8 | uint(c2da_mem[surf_3 + 26]) << 0x10 | uint(c2da_mem[surf_3 + 27]) << 0x18) > int(uint(c2da_mem[surf2_0 + 24]) | uint(c2da_mem[surf2_0 + 25]) << 0x8 | uint(c2da_mem[surf2_0 + 26]) << 0x10 | uint(c2da_mem[surf2_0 + 27]) << 0x18)) {
        goto label 12
    }
    if ((uint(c2da_mem[surf_3 + 60]) | uint(c2da_mem[surf_3 + 61]) << 0x8 | uint(c2da_mem[surf_3 + 62]) << 0x10 | uint(c2da_mem[surf_3 + 63]) << 0x18) != 0x0 && int(uint(c2da_mem[surf_3 + 24]) | uint(c2da_mem[surf_3 + 25]) << 0x8 | uint(c2da_mem[surf_3 + 26]) << 0x10 | uint(c2da_mem[surf_3 + 27]) << 0x18) == int(uint(c2da_mem[surf2_0 + 24]) | uint(c2da_mem[surf2_0 + 25]) << 0x8 | uint(c2da_mem[surf2_0 + 26]) << 0x10 | uint(c2da_mem[surf2_0 + 27]) << 0x18)) {
        goto label 8
    }
    label 2:
    label 3:
    surf2_0 = int(uint(c2da_mem[surf2_0]) | uint(c2da_mem[surf2_0 + 1]) << 0x8 | uint(c2da_mem[surf2_0 + 2]) << 0x10 | uint(c2da_mem[surf2_0 + 3]) << 0x18)
    if (int(uint(c2da_mem[surf_3 + 24]) | uint(c2da_mem[surf_3 + 25]) << 0x8 | uint(c2da_mem[surf_3 + 26]) << 0x10 | uint(c2da_mem[surf_3 + 27]) << 0x18) < int(uint(c2da_mem[surf2_0 + 24]) | uint(c2da_mem[surf2_0 + 25]) << 0x8 | uint(c2da_mem[surf2_0 + 26]) << 0x10 | uint(c2da_mem[surf2_0 + 27]) << 0x18)) {
        goto label 3
    }
    if (int(uint(c2da_mem[surf_3 + 24]) | uint(c2da_mem[surf_3 + 25]) << 0x8 | uint(c2da_mem[surf_3 + 26]) << 0x10 | uint(c2da_mem[surf_3 + 27]) << 0x18) == int(uint(c2da_mem[surf2_0 + 24]) | uint(c2da_mem[surf2_0 + 25]) << 0x8 | uint(c2da_mem[surf2_0 + 26]) << 0x10 | uint(c2da_mem[surf2_0 + 27]) << 0x18)) {
        goto label 6
    }
    label 4:
    label 5:
    let c2da_fresh78 : uint = uint(surf2_0)
    c2da_mem[surf_3] = uint8(c2da_fresh78)
    c2da_mem[surf_3 + 1] = uint8(c2da_fresh78 >> 0x8)
    c2da_mem[surf_3 + 2] = uint8(c2da_fresh78 >> 0x10)
    c2da_mem[surf_3 + 3] = uint8(c2da_fresh78 >> 0x18)
    c2da_mem[surf_3 + 4] = 0u8
    c2da_mem[surf_3 + 5] = 0u8
    c2da_mem[surf_3 + 6] = 0u8
    c2da_mem[surf_3 + 7] = 0u8
    let c2da_fresh79 : int = int(uint(c2da_mem[surf2_0 + 8]) | uint(c2da_mem[surf2_0 + 9]) << 0x8 | uint(c2da_mem[surf2_0 + 10]) << 0x10 | uint(c2da_mem[surf2_0 + 11]) << 0x18)
    let c2da_fresh80 : uint = uint(c2da_fresh79)
    c2da_mem[surf_3 + 8] = uint8(c2da_fresh80)
    c2da_mem[surf_3 + 9] = uint8(c2da_fresh80 >> 0x8)
    c2da_mem[surf_3 + 10] = uint8(c2da_fresh80 >> 0x10)
    c2da_mem[surf_3 + 11] = uint8(c2da_fresh80 >> 0x18)
    c2da_mem[surf_3 + 12] = 0u8
    c2da_mem[surf_3 + 13] = 0u8
    c2da_mem[surf_3 + 14] = 0u8
    c2da_mem[surf_3 + 15] = 0u8
    let c2da_fresh81 : int = int(uint(c2da_mem[surf2_0 + 8]) | uint(c2da_mem[surf2_0 + 9]) << 0x8 | uint(c2da_mem[surf2_0 + 10]) << 0x10 | uint(c2da_mem[surf2_0 + 11]) << 0x18)
    let c2da_fresh82 : uint = uint(surf_3)
    c2da_mem[c2da_fresh81] = uint8(c2da_fresh82)
    c2da_mem[c2da_fresh81 + 1] = uint8(c2da_fresh82 >> 0x8)
    c2da_mem[c2da_fresh81 + 2] = uint8(c2da_fresh82 >> 0x10)
    c2da_mem[c2da_fresh81 + 3] = uint8(c2da_fresh82 >> 0x18)
    c2da_mem[c2da_fresh81 + 4] = 0u8
    c2da_mem[c2da_fresh81 + 5] = 0u8
    c2da_mem[c2da_fresh81 + 6] = 0u8
    c2da_mem[c2da_fresh81 + 7] = 0u8
    let c2da_fresh83 : uint = uint(surf_3)
    c2da_mem[surf2_0 + 8] = uint8(c2da_fresh83)
    c2da_mem[surf2_0 + 9] = uint8(c2da_fresh83 >> 0x8)
    c2da_mem[surf2_0 + 10] = uint8(c2da_fresh83 >> 0x10)
    c2da_mem[surf2_0 + 11] = uint8(c2da_fresh83 >> 0x18)
    c2da_mem[surf2_0 + 12] = 0u8
    c2da_mem[surf2_0 + 13] = 0u8
    c2da_mem[surf2_0 + 14] = 0u8
    c2da_mem[surf2_0 + 15] = 0u8
    goto label 0
    label 6:
    if ((uint(c2da_mem[surf_3 + 60]) | uint(c2da_mem[surf_3 + 61]) << 0x8 | uint(c2da_mem[surf_3 + 62]) << 0x10 | uint(c2da_mem[surf_3 + 63]) << 0x18) == 0u) {
        goto label 7
    }
    goto label 4
    label 7:
    goto label 2
    label 8:
    label 9:
    iu_2 = int(uint(c2da_mem[edge_3]) | uint(c2da_mem[edge_3 + 1]) << 0x8 | uint(c2da_mem[edge_3 + 2]) << 0x10 | uint(c2da_mem[edge_3 + 3]) << 0x18) >> 20
    if (iu_2 > int(uint(c2da_mem[surf2_0 + 28]) | uint(c2da_mem[surf2_0 + 29]) << 0x8 | uint(c2da_mem[surf2_0 + 30]) << 0x10 | uint(c2da_mem[surf2_0 + 31]) << 0x18)) {
        goto label 11
    }
    label 10:
    let c2da_fresh77 : uint = uint(iu_2)
    c2da_mem[surf_3 + 28] = uint8(c2da_fresh77)
    c2da_mem[surf_3 + 29] = uint8(c2da_fresh77 >> 0x8)
    c2da_mem[surf_3 + 30] = uint8(c2da_fresh77 >> 0x10)
    c2da_mem[surf_3 + 31] = uint8(c2da_fresh77 >> 0x18)
    goto label 5
    label 11:
    let c2da_fresh68 : int = span_p
    span_p += 24
    span_2 = c2da_fresh68
    let c2da_fresh69 : int = int(uint(c2da_mem[surf2_0 + 28]) | uint(c2da_mem[surf2_0 + 29]) << 0x8 | uint(c2da_mem[surf2_0 + 30]) << 0x10 | uint(c2da_mem[surf2_0 + 31]) << 0x18)
    let c2da_fresh70 : uint = uint(c2da_fresh69)
    c2da_mem[span_2] = uint8(c2da_fresh70)
    c2da_mem[span_2 + 1] = uint8(c2da_fresh70 >> 0x8)
    c2da_mem[span_2 + 2] = uint8(c2da_fresh70 >> 0x10)
    c2da_mem[span_2 + 3] = uint8(c2da_fresh70 >> 0x18)
    let c2da_fresh71 : int = iu_2 - int(uint(c2da_mem[span_2]) | uint(c2da_mem[span_2 + 1]) << 0x8 | uint(c2da_mem[span_2 + 2]) << 0x10 | uint(c2da_mem[span_2 + 3]) << 0x18)
    let c2da_fresh72 : uint = uint(c2da_fresh71)
    c2da_mem[span_2 + 8] = uint8(c2da_fresh72)
    c2da_mem[span_2 + 9] = uint8(c2da_fresh72 >> 0x8)
    c2da_mem[span_2 + 10] = uint8(c2da_fresh72 >> 0x10)
    c2da_mem[span_2 + 11] = uint8(c2da_fresh72 >> 0x18)
    let c2da_fresh73 : uint = uint(current_iv)
    c2da_mem[span_2 + 4] = uint8(c2da_fresh73)
    c2da_mem[span_2 + 5] = uint8(c2da_fresh73 >> 0x8)
    c2da_mem[span_2 + 6] = uint8(c2da_fresh73 >> 0x10)
    c2da_mem[span_2 + 7] = uint8(c2da_fresh73 >> 0x18)
    let c2da_fresh74 : int = int(uint(c2da_mem[surf2_0 + 16]) | uint(c2da_mem[surf2_0 + 17]) << 0x8 | uint(c2da_mem[surf2_0 + 18]) << 0x10 | uint(c2da_mem[surf2_0 + 19]) << 0x18)
    let c2da_fresh75 : uint = uint(c2da_fresh74)
    c2da_mem[span_2 + 16] = uint8(c2da_fresh75)
    c2da_mem[span_2 + 17] = uint8(c2da_fresh75 >> 0x8)
    c2da_mem[span_2 + 18] = uint8(c2da_fresh75 >> 0x10)
    c2da_mem[span_2 + 19] = uint8(c2da_fresh75 >> 0x18)
    c2da_mem[span_2 + 20] = 0u8
    c2da_mem[span_2 + 21] = 0u8
    c2da_mem[span_2 + 22] = 0u8
    c2da_mem[span_2 + 23] = 0u8
    let c2da_fresh76 : uint = uint(span_2)
    c2da_mem[surf2_0 + 16] = uint8(c2da_fresh76)
    c2da_mem[surf2_0 + 17] = uint8(c2da_fresh76 >> 0x8)
    c2da_mem[surf2_0 + 18] = uint8(c2da_fresh76 >> 0x10)
    c2da_mem[surf2_0 + 19] = uint8(c2da_fresh76 >> 0x18)
    c2da_mem[surf2_0 + 20] = 0u8
    c2da_mem[surf2_0 + 21] = 0u8
    c2da_mem[surf2_0 + 22] = 0u8
    c2da_mem[surf2_0 + 23] = 0u8
    goto label 10
    label 12:
    goto label 9
    panic("unreachable: fell out of a translated control-flow graph")
}
var r_edges : int = default<int>

var edge_max : int = default<int>

var edge_p : int = default<int>

[export, sideeffects]
def R_ScanEdges() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_ScanEdges_c2da_frame(c2da_lin_enter(72032))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_DrawCulledPolys() {
    var s_0 : int
    var pface : int
    currententity = 10048 + 0 * 200
    if (uint(r_worldpolysbacktofront) != 0u) {
        s_0 = surface_p - 1 * 88
        while (s_0 > surfaces + 1 * 88) {
            if (int(uint(c2da_mem[s_0 + 16]) | uint(c2da_mem[s_0 + 17]) << 0x8 | uint(c2da_mem[s_0 + 18]) << 0x10 | uint(c2da_mem[s_0 + 19]) << 0x18) == 0) {
                s_0 -= 88
                continue
            }
            if ((int(uint(c2da_mem[s_0 + 36]) | uint(c2da_mem[s_0 + 37]) << 0x8 | uint(c2da_mem[s_0 + 38]) << 0x10 | uint(c2da_mem[s_0 + 39]) << 0x18) & 64) == 0) {
                pface = int(uint(c2da_mem[s_0 + 40]) | uint(c2da_mem[s_0 + 41]) << 0x8 | uint(c2da_mem[s_0 + 42]) << 0x10 | uint(c2da_mem[s_0 + 43]) << 0x18)
                R_RenderPoly(pface, 15)
            }
            s_0 -= 88
        }
    } else {
        s_0 = surfaces + 1 * 88
        while (s_0 < surface_p) {
            if (int(uint(c2da_mem[s_0 + 16]) | uint(c2da_mem[s_0 + 17]) << 0x8 | uint(c2da_mem[s_0 + 18]) << 0x10 | uint(c2da_mem[s_0 + 19]) << 0x18) == 0) {
                s_0 += 88
                continue
            }
            if ((int(uint(c2da_mem[s_0 + 36]) | uint(c2da_mem[s_0 + 37]) << 0x8 | uint(c2da_mem[s_0 + 38]) << 0x10 | uint(c2da_mem[s_0 + 39]) << 0x18) & 64) == 0) {
                pface = int(uint(c2da_mem[s_0 + 40]) | uint(c2da_mem[s_0 + 41]) << 0x8 | uint(c2da_mem[s_0 + 42]) << 0x10 | uint(c2da_mem[s_0 + 43]) << 0x18)
                R_RenderPoly(pface, 15)
            }
            s_0 += 88
        }
    }
    return
}
[export, sideeffects]
def R_InsertNewEdges(var edgestoadd : int; var edgelist : int) {
    var next_edge : int
    label 0:
    next_edge = int(uint(c2da_mem[edgestoadd + 16]) | uint(c2da_mem[edgestoadd + 17]) << 0x8 | uint(c2da_mem[edgestoadd + 18]) << 0x10 | uint(c2da_mem[edgestoadd + 19]) << 0x18)
    label 1:
    if (int(uint(c2da_mem[edgelist]) | uint(c2da_mem[edgelist + 1]) << 0x8 | uint(c2da_mem[edgelist + 2]) << 0x10 | uint(c2da_mem[edgelist + 3]) << 0x18) >= int(uint(c2da_mem[edgestoadd]) | uint(c2da_mem[edgestoadd + 1]) << 0x8 | uint(c2da_mem[edgestoadd + 2]) << 0x10 | uint(c2da_mem[edgestoadd + 3]) << 0x18)) {
        goto label 6
    }
    edgelist = int(uint(c2da_mem[edgelist + 16]) | uint(c2da_mem[edgelist + 17]) << 0x8 | uint(c2da_mem[edgelist + 18]) << 0x10 | uint(c2da_mem[edgelist + 19]) << 0x18)
    if (int(uint(c2da_mem[edgelist]) | uint(c2da_mem[edgelist + 1]) << 0x8 | uint(c2da_mem[edgelist + 2]) << 0x10 | uint(c2da_mem[edgelist + 3]) << 0x18) >= int(uint(c2da_mem[edgestoadd]) | uint(c2da_mem[edgestoadd + 1]) << 0x8 | uint(c2da_mem[edgestoadd + 2]) << 0x10 | uint(c2da_mem[edgestoadd + 3]) << 0x18)) {
        goto label 5
    }
    edgelist = int(uint(c2da_mem[edgelist + 16]) | uint(c2da_mem[edgelist + 17]) << 0x8 | uint(c2da_mem[edgelist + 18]) << 0x10 | uint(c2da_mem[edgelist + 19]) << 0x18)
    if (int(uint(c2da_mem[edgelist]) | uint(c2da_mem[edgelist + 1]) << 0x8 | uint(c2da_mem[edgelist + 2]) << 0x10 | uint(c2da_mem[edgelist + 3]) << 0x18) >= int(uint(c2da_mem[edgestoadd]) | uint(c2da_mem[edgestoadd + 1]) << 0x8 | uint(c2da_mem[edgestoadd + 2]) << 0x10 | uint(c2da_mem[edgestoadd + 3]) << 0x18)) {
        goto label 4
    }
    edgelist = int(uint(c2da_mem[edgelist + 16]) | uint(c2da_mem[edgelist + 17]) << 0x8 | uint(c2da_mem[edgelist + 18]) << 0x10 | uint(c2da_mem[edgelist + 19]) << 0x18)
    if (int(uint(c2da_mem[edgelist]) | uint(c2da_mem[edgelist + 1]) << 0x8 | uint(c2da_mem[edgelist + 2]) << 0x10 | uint(c2da_mem[edgelist + 3]) << 0x18) >= int(uint(c2da_mem[edgestoadd]) | uint(c2da_mem[edgestoadd + 1]) << 0x8 | uint(c2da_mem[edgestoadd + 2]) << 0x10 | uint(c2da_mem[edgestoadd + 3]) << 0x18)) {
        goto label 2
    }
    edgelist = int(uint(c2da_mem[edgelist + 16]) | uint(c2da_mem[edgelist + 17]) << 0x8 | uint(c2da_mem[edgelist + 18]) << 0x10 | uint(c2da_mem[edgelist + 19]) << 0x18)
    goto label 1
    label 2:
    label 3:
    let c2da_fresh118 : uint = uint(edgelist)
    c2da_mem[edgestoadd + 16] = uint8(c2da_fresh118)
    c2da_mem[edgestoadd + 17] = uint8(c2da_fresh118 >> 0x8)
    c2da_mem[edgestoadd + 18] = uint8(c2da_fresh118 >> 0x10)
    c2da_mem[edgestoadd + 19] = uint8(c2da_fresh118 >> 0x18)
    c2da_mem[edgestoadd + 20] = 0u8
    c2da_mem[edgestoadd + 21] = 0u8
    c2da_mem[edgestoadd + 22] = 0u8
    c2da_mem[edgestoadd + 23] = 0u8
    let c2da_fresh119 : int = int(uint(c2da_mem[edgelist + 8]) | uint(c2da_mem[edgelist + 9]) << 0x8 | uint(c2da_mem[edgelist + 10]) << 0x10 | uint(c2da_mem[edgelist + 11]) << 0x18)
    let c2da_fresh120 : uint = uint(c2da_fresh119)
    c2da_mem[edgestoadd + 8] = uint8(c2da_fresh120)
    c2da_mem[edgestoadd + 9] = uint8(c2da_fresh120 >> 0x8)
    c2da_mem[edgestoadd + 10] = uint8(c2da_fresh120 >> 0x10)
    c2da_mem[edgestoadd + 11] = uint8(c2da_fresh120 >> 0x18)
    c2da_mem[edgestoadd + 12] = 0u8
    c2da_mem[edgestoadd + 13] = 0u8
    c2da_mem[edgestoadd + 14] = 0u8
    c2da_mem[edgestoadd + 15] = 0u8
    let c2da_fresh121 : int = int(uint(c2da_mem[edgelist + 8]) | uint(c2da_mem[edgelist + 9]) << 0x8 | uint(c2da_mem[edgelist + 10]) << 0x10 | uint(c2da_mem[edgelist + 11]) << 0x18) + 16
    let c2da_fresh122 : uint = uint(edgestoadd)
    c2da_mem[c2da_fresh121] = uint8(c2da_fresh122)
    c2da_mem[c2da_fresh121 + 1] = uint8(c2da_fresh122 >> 0x8)
    c2da_mem[c2da_fresh121 + 2] = uint8(c2da_fresh122 >> 0x10)
    c2da_mem[c2da_fresh121 + 3] = uint8(c2da_fresh122 >> 0x18)
    c2da_mem[c2da_fresh121 + 4] = 0u8
    c2da_mem[c2da_fresh121 + 5] = 0u8
    c2da_mem[c2da_fresh121 + 6] = 0u8
    c2da_mem[c2da_fresh121 + 7] = 0u8
    let c2da_fresh123 : uint = uint(edgestoadd)
    c2da_mem[edgelist + 8] = uint8(c2da_fresh123)
    c2da_mem[edgelist + 9] = uint8(c2da_fresh123 >> 0x8)
    c2da_mem[edgelist + 10] = uint8(c2da_fresh123 >> 0x10)
    c2da_mem[edgelist + 11] = uint8(c2da_fresh123 >> 0x18)
    c2da_mem[edgelist + 12] = 0u8
    c2da_mem[edgelist + 13] = 0u8
    c2da_mem[edgelist + 14] = 0u8
    c2da_mem[edgelist + 15] = 0u8
    edgestoadd = next_edge
    if (edgestoadd != 0) {
        goto label 0
    }
    return
    label 4:
    goto label 3
    label 5:
    goto label 3
    label 6:
    goto label 3
    panic("unreachable: fell out of a translated control-flow graph")
}
[export, sideeffects]
def R_StepActiveU(var pedge : int) {
    var pnext_edge : int
    var pwedge : int
    label 0:
    goto label 1
    return
    label 1:
    label 2:
    let c2da_fresh124 : int = int(uint(c2da_mem[pedge]) | uint(c2da_mem[pedge + 1]) << 0x8 | uint(c2da_mem[pedge + 2]) << 0x10 | uint(c2da_mem[pedge + 3]) << 0x18) + int(uint(c2da_mem[pedge + 4]) | uint(c2da_mem[pedge + 5]) << 0x8 | uint(c2da_mem[pedge + 6]) << 0x10 | uint(c2da_mem[pedge + 7]) << 0x18)
    let c2da_fresh125 : uint = uint(c2da_fresh124)
    c2da_mem[pedge] = uint8(c2da_fresh125)
    c2da_mem[pedge + 1] = uint8(c2da_fresh125 >> 0x8)
    c2da_mem[pedge + 2] = uint8(c2da_fresh125 >> 0x10)
    c2da_mem[pedge + 3] = uint8(c2da_fresh125 >> 0x18)
    let c2da_fresh126 : int = int(uint(c2da_mem[pedge + 8]) | uint(c2da_mem[pedge + 9]) << 0x8 | uint(c2da_mem[pedge + 10]) << 0x10 | uint(c2da_mem[pedge + 11]) << 0x18)
    if (int(uint(c2da_mem[pedge]) | uint(c2da_mem[pedge + 1]) << 0x8 | uint(c2da_mem[pedge + 2]) << 0x10 | uint(c2da_mem[pedge + 3]) << 0x18) < int(uint(c2da_mem[c2da_fresh126]) | uint(c2da_mem[c2da_fresh126 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh126 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh126 + 3]) << 0x18)) {
        goto label 11
    }
    pedge = int(uint(c2da_mem[pedge + 16]) | uint(c2da_mem[pedge + 17]) << 0x8 | uint(c2da_mem[pedge + 18]) << 0x10 | uint(c2da_mem[pedge + 19]) << 0x18)
    let c2da_fresh127 : int = int(uint(c2da_mem[pedge]) | uint(c2da_mem[pedge + 1]) << 0x8 | uint(c2da_mem[pedge + 2]) << 0x10 | uint(c2da_mem[pedge + 3]) << 0x18) + int(uint(c2da_mem[pedge + 4]) | uint(c2da_mem[pedge + 5]) << 0x8 | uint(c2da_mem[pedge + 6]) << 0x10 | uint(c2da_mem[pedge + 7]) << 0x18)
    let c2da_fresh128 : uint = uint(c2da_fresh127)
    c2da_mem[pedge] = uint8(c2da_fresh128)
    c2da_mem[pedge + 1] = uint8(c2da_fresh128 >> 0x8)
    c2da_mem[pedge + 2] = uint8(c2da_fresh128 >> 0x10)
    c2da_mem[pedge + 3] = uint8(c2da_fresh128 >> 0x18)
    let c2da_fresh129 : int = int(uint(c2da_mem[pedge + 8]) | uint(c2da_mem[pedge + 9]) << 0x8 | uint(c2da_mem[pedge + 10]) << 0x10 | uint(c2da_mem[pedge + 11]) << 0x18)
    if (int(uint(c2da_mem[pedge]) | uint(c2da_mem[pedge + 1]) << 0x8 | uint(c2da_mem[pedge + 2]) << 0x10 | uint(c2da_mem[pedge + 3]) << 0x18) < int(uint(c2da_mem[c2da_fresh129]) | uint(c2da_mem[c2da_fresh129 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh129 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh129 + 3]) << 0x18)) {
        goto label 10
    }
    pedge = int(uint(c2da_mem[pedge + 16]) | uint(c2da_mem[pedge + 17]) << 0x8 | uint(c2da_mem[pedge + 18]) << 0x10 | uint(c2da_mem[pedge + 19]) << 0x18)
    let c2da_fresh130 : int = int(uint(c2da_mem[pedge]) | uint(c2da_mem[pedge + 1]) << 0x8 | uint(c2da_mem[pedge + 2]) << 0x10 | uint(c2da_mem[pedge + 3]) << 0x18) + int(uint(c2da_mem[pedge + 4]) | uint(c2da_mem[pedge + 5]) << 0x8 | uint(c2da_mem[pedge + 6]) << 0x10 | uint(c2da_mem[pedge + 7]) << 0x18)
    let c2da_fresh131 : uint = uint(c2da_fresh130)
    c2da_mem[pedge] = uint8(c2da_fresh131)
    c2da_mem[pedge + 1] = uint8(c2da_fresh131 >> 0x8)
    c2da_mem[pedge + 2] = uint8(c2da_fresh131 >> 0x10)
    c2da_mem[pedge + 3] = uint8(c2da_fresh131 >> 0x18)
    let c2da_fresh132 : int = int(uint(c2da_mem[pedge + 8]) | uint(c2da_mem[pedge + 9]) << 0x8 | uint(c2da_mem[pedge + 10]) << 0x10 | uint(c2da_mem[pedge + 11]) << 0x18)
    if (int(uint(c2da_mem[pedge]) | uint(c2da_mem[pedge + 1]) << 0x8 | uint(c2da_mem[pedge + 2]) << 0x10 | uint(c2da_mem[pedge + 3]) << 0x18) < int(uint(c2da_mem[c2da_fresh132]) | uint(c2da_mem[c2da_fresh132 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh132 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh132 + 3]) << 0x18)) {
        goto label 9
    }
    pedge = int(uint(c2da_mem[pedge + 16]) | uint(c2da_mem[pedge + 17]) << 0x8 | uint(c2da_mem[pedge + 18]) << 0x10 | uint(c2da_mem[pedge + 19]) << 0x18)
    let c2da_fresh133 : int = int(uint(c2da_mem[pedge]) | uint(c2da_mem[pedge + 1]) << 0x8 | uint(c2da_mem[pedge + 2]) << 0x10 | uint(c2da_mem[pedge + 3]) << 0x18) + int(uint(c2da_mem[pedge + 4]) | uint(c2da_mem[pedge + 5]) << 0x8 | uint(c2da_mem[pedge + 6]) << 0x10 | uint(c2da_mem[pedge + 7]) << 0x18)
    let c2da_fresh134 : uint = uint(c2da_fresh133)
    c2da_mem[pedge] = uint8(c2da_fresh134)
    c2da_mem[pedge + 1] = uint8(c2da_fresh134 >> 0x8)
    c2da_mem[pedge + 2] = uint8(c2da_fresh134 >> 0x10)
    c2da_mem[pedge + 3] = uint8(c2da_fresh134 >> 0x18)
    let c2da_fresh135 : int = int(uint(c2da_mem[pedge + 8]) | uint(c2da_mem[pedge + 9]) << 0x8 | uint(c2da_mem[pedge + 10]) << 0x10 | uint(c2da_mem[pedge + 11]) << 0x18)
    if (int(uint(c2da_mem[pedge]) | uint(c2da_mem[pedge + 1]) << 0x8 | uint(c2da_mem[pedge + 2]) << 0x10 | uint(c2da_mem[pedge + 3]) << 0x18) < int(uint(c2da_mem[c2da_fresh135]) | uint(c2da_mem[c2da_fresh135 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh135 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh135 + 3]) << 0x18)) {
        goto label 3
    }
    pedge = int(uint(c2da_mem[pedge + 16]) | uint(c2da_mem[pedge + 17]) << 0x8 | uint(c2da_mem[pedge + 18]) << 0x10 | uint(c2da_mem[pedge + 19]) << 0x18)
    goto label 2
    label 3:
    label 4:
    if (pedge == 391760) {
        goto label 8
    }
    pnext_edge = int(uint(c2da_mem[pedge + 16]) | uint(c2da_mem[pedge + 17]) << 0x8 | uint(c2da_mem[pedge + 18]) << 0x10 | uint(c2da_mem[pedge + 19]) << 0x18)
    let c2da_fresh136 : int = int(uint(c2da_mem[pedge + 16]) | uint(c2da_mem[pedge + 17]) << 0x8 | uint(c2da_mem[pedge + 18]) << 0x10 | uint(c2da_mem[pedge + 19]) << 0x18) + 8
    let c2da_fresh137 : int = int(uint(c2da_mem[pedge + 8]) | uint(c2da_mem[pedge + 9]) << 0x8 | uint(c2da_mem[pedge + 10]) << 0x10 | uint(c2da_mem[pedge + 11]) << 0x18)
    let c2da_fresh138 : uint = uint(c2da_fresh137)
    c2da_mem[c2da_fresh136] = uint8(c2da_fresh138)
    c2da_mem[c2da_fresh136 + 1] = uint8(c2da_fresh138 >> 0x8)
    c2da_mem[c2da_fresh136 + 2] = uint8(c2da_fresh138 >> 0x10)
    c2da_mem[c2da_fresh136 + 3] = uint8(c2da_fresh138 >> 0x18)
    c2da_mem[c2da_fresh136 + 4] = 0u8
    c2da_mem[c2da_fresh136 + 5] = 0u8
    c2da_mem[c2da_fresh136 + 6] = 0u8
    c2da_mem[c2da_fresh136 + 7] = 0u8
    let c2da_fresh139 : int = int(uint(c2da_mem[pedge + 8]) | uint(c2da_mem[pedge + 9]) << 0x8 | uint(c2da_mem[pedge + 10]) << 0x10 | uint(c2da_mem[pedge + 11]) << 0x18) + 16
    let c2da_fresh140 : int = int(uint(c2da_mem[pedge + 16]) | uint(c2da_mem[pedge + 17]) << 0x8 | uint(c2da_mem[pedge + 18]) << 0x10 | uint(c2da_mem[pedge + 19]) << 0x18)
    let c2da_fresh141 : uint = uint(c2da_fresh140)
    c2da_mem[c2da_fresh139] = uint8(c2da_fresh141)
    c2da_mem[c2da_fresh139 + 1] = uint8(c2da_fresh141 >> 0x8)
    c2da_mem[c2da_fresh139 + 2] = uint8(c2da_fresh141 >> 0x10)
    c2da_mem[c2da_fresh139 + 3] = uint8(c2da_fresh141 >> 0x18)
    c2da_mem[c2da_fresh139 + 4] = 0u8
    c2da_mem[c2da_fresh139 + 5] = 0u8
    c2da_mem[c2da_fresh139 + 6] = 0u8
    c2da_mem[c2da_fresh139 + 7] = 0u8
    let c2da_fresh142 : int = int(uint(c2da_mem[pedge + 8]) | uint(c2da_mem[pedge + 9]) << 0x8 | uint(c2da_mem[pedge + 10]) << 0x10 | uint(c2da_mem[pedge + 11]) << 0x18) + 8
    pwedge = int(uint(c2da_mem[c2da_fresh142]) | uint(c2da_mem[c2da_fresh142 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh142 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh142 + 3]) << 0x18)
    label 5:
    if (int(uint(c2da_mem[pwedge]) | uint(c2da_mem[pwedge + 1]) << 0x8 | uint(c2da_mem[pwedge + 2]) << 0x10 | uint(c2da_mem[pwedge + 3]) << 0x18) > int(uint(c2da_mem[pedge]) | uint(c2da_mem[pedge + 1]) << 0x8 | uint(c2da_mem[pedge + 2]) << 0x10 | uint(c2da_mem[pedge + 3]) << 0x18)) {
        goto label 7
    }
    let c2da_fresh143 : int = int(uint(c2da_mem[pwedge + 16]) | uint(c2da_mem[pwedge + 17]) << 0x8 | uint(c2da_mem[pwedge + 18]) << 0x10 | uint(c2da_mem[pwedge + 19]) << 0x18)
    let c2da_fresh144 : uint = uint(c2da_fresh143)
    c2da_mem[pedge + 16] = uint8(c2da_fresh144)
    c2da_mem[pedge + 17] = uint8(c2da_fresh144 >> 0x8)
    c2da_mem[pedge + 18] = uint8(c2da_fresh144 >> 0x10)
    c2da_mem[pedge + 19] = uint8(c2da_fresh144 >> 0x18)
    c2da_mem[pedge + 20] = 0u8
    c2da_mem[pedge + 21] = 0u8
    c2da_mem[pedge + 22] = 0u8
    c2da_mem[pedge + 23] = 0u8
    let c2da_fresh145 : uint = uint(pwedge)
    c2da_mem[pedge + 8] = uint8(c2da_fresh145)
    c2da_mem[pedge + 9] = uint8(c2da_fresh145 >> 0x8)
    c2da_mem[pedge + 10] = uint8(c2da_fresh145 >> 0x10)
    c2da_mem[pedge + 11] = uint8(c2da_fresh145 >> 0x18)
    c2da_mem[pedge + 12] = 0u8
    c2da_mem[pedge + 13] = 0u8
    c2da_mem[pedge + 14] = 0u8
    c2da_mem[pedge + 15] = 0u8
    let c2da_fresh146 : int = int(uint(c2da_mem[pedge + 16]) | uint(c2da_mem[pedge + 17]) << 0x8 | uint(c2da_mem[pedge + 18]) << 0x10 | uint(c2da_mem[pedge + 19]) << 0x18) + 8
    let c2da_fresh147 : uint = uint(pedge)
    c2da_mem[c2da_fresh146] = uint8(c2da_fresh147)
    c2da_mem[c2da_fresh146 + 1] = uint8(c2da_fresh147 >> 0x8)
    c2da_mem[c2da_fresh146 + 2] = uint8(c2da_fresh147 >> 0x10)
    c2da_mem[c2da_fresh146 + 3] = uint8(c2da_fresh147 >> 0x18)
    c2da_mem[c2da_fresh146 + 4] = 0u8
    c2da_mem[c2da_fresh146 + 5] = 0u8
    c2da_mem[c2da_fresh146 + 6] = 0u8
    c2da_mem[c2da_fresh146 + 7] = 0u8
    let c2da_fresh148 : uint = uint(pedge)
    c2da_mem[pwedge + 16] = uint8(c2da_fresh148)
    c2da_mem[pwedge + 17] = uint8(c2da_fresh148 >> 0x8)
    c2da_mem[pwedge + 18] = uint8(c2da_fresh148 >> 0x10)
    c2da_mem[pwedge + 19] = uint8(c2da_fresh148 >> 0x18)
    c2da_mem[pwedge + 20] = 0u8
    c2da_mem[pwedge + 21] = 0u8
    c2da_mem[pwedge + 22] = 0u8
    c2da_mem[pwedge + 23] = 0u8
    pedge = pnext_edge
    if (pedge == 391632) {
        goto label 6
    }
    goto label 0
    label 6:
    return
    label 7:
    pwedge = int(uint(c2da_mem[pwedge + 8]) | uint(c2da_mem[pwedge + 9]) << 0x8 | uint(c2da_mem[pwedge + 10]) << 0x10 | uint(c2da_mem[pwedge + 11]) << 0x18)
    goto label 5
    label 8:
    return
    label 9:
    goto label 4
    label 10:
    goto label 4
    label 11:
    goto label 4
    panic("unreachable: fell out of a translated control-flow graph")
}
[export, sideeffects]
def R_RemoveEdges(var pedge_0 : int) {
    while (true) {
        let c2da_fresh149 : int = int(uint(c2da_mem[pedge_0 + 16]) | uint(c2da_mem[pedge_0 + 17]) << 0x8 | uint(c2da_mem[pedge_0 + 18]) << 0x10 | uint(c2da_mem[pedge_0 + 19]) << 0x18) + 8
        let c2da_fresh150 : int = int(uint(c2da_mem[pedge_0 + 8]) | uint(c2da_mem[pedge_0 + 9]) << 0x8 | uint(c2da_mem[pedge_0 + 10]) << 0x10 | uint(c2da_mem[pedge_0 + 11]) << 0x18)
        let c2da_fresh151 : uint = uint(c2da_fresh150)
        c2da_mem[c2da_fresh149] = uint8(c2da_fresh151)
        c2da_mem[c2da_fresh149 + 1] = uint8(c2da_fresh151 >> 0x8)
        c2da_mem[c2da_fresh149 + 2] = uint8(c2da_fresh151 >> 0x10)
        c2da_mem[c2da_fresh149 + 3] = uint8(c2da_fresh151 >> 0x18)
        c2da_mem[c2da_fresh149 + 4] = 0u8
        c2da_mem[c2da_fresh149 + 5] = 0u8
        c2da_mem[c2da_fresh149 + 6] = 0u8
        c2da_mem[c2da_fresh149 + 7] = 0u8
        let c2da_fresh152 : int = int(uint(c2da_mem[pedge_0 + 8]) | uint(c2da_mem[pedge_0 + 9]) << 0x8 | uint(c2da_mem[pedge_0 + 10]) << 0x10 | uint(c2da_mem[pedge_0 + 11]) << 0x18) + 16
        let c2da_fresh153 : int = int(uint(c2da_mem[pedge_0 + 16]) | uint(c2da_mem[pedge_0 + 17]) << 0x8 | uint(c2da_mem[pedge_0 + 18]) << 0x10 | uint(c2da_mem[pedge_0 + 19]) << 0x18)
        let c2da_fresh154 : uint = uint(c2da_fresh153)
        c2da_mem[c2da_fresh152] = uint8(c2da_fresh154)
        c2da_mem[c2da_fresh152 + 1] = uint8(c2da_fresh154 >> 0x8)
        c2da_mem[c2da_fresh152 + 2] = uint8(c2da_fresh154 >> 0x10)
        c2da_mem[c2da_fresh152 + 3] = uint8(c2da_fresh154 >> 0x18)
        c2da_mem[c2da_fresh152 + 4] = 0u8
        c2da_mem[c2da_fresh152 + 5] = 0u8
        c2da_mem[c2da_fresh152 + 6] = 0u8
        c2da_mem[c2da_fresh152 + 7] = 0u8
        pedge_0 = int(uint(c2da_mem[pedge_0 + 32]) | uint(c2da_mem[pedge_0 + 33]) << 0x8 | uint(c2da_mem[pedge_0 + 34]) << 0x10 | uint(c2da_mem[pedge_0 + 35]) << 0x18)
        if (pedge_0 == 0) {
            break
        }
    }
    return
}
var max_span_p : int = default<int>

var auxedges : int = default<int>

[sideeffects]
def private R_ScanEdges_c2da_frame(c2da_fp : int) {
    var iv : int
    var bottom : int
    var basespan_p : int
    var s : int
    basespan_p = int(int64(c2da_fp + 32 - 1) & int64(~(32 - 1)))
    max_span_p = basespan_p + (3000 - int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18)) * 24
    span_p = basespan_p
    let c2da_fresh84 : int = int(uint(c2da_mem[5200]) | uint(c2da_mem[5201]) << 0x8 | uint(c2da_mem[5202]) << 0x10 | uint(c2da_mem[5203]) << 0x18) << 20
    let c2da_fresh85 : uint = uint(c2da_fresh84)
    c2da_mem[391696] = uint8(c2da_fresh85)
    c2da_mem[391697] = uint8(c2da_fresh85 >> 0x8)
    c2da_mem[391698] = uint8(c2da_fresh85 >> 0x10)
    c2da_mem[391699] = uint8(c2da_fresh85 >> 0x18)
    edge_head_u_shift20 = int(uint(c2da_mem[391696]) | uint(c2da_mem[391697]) << 0x8 | uint(c2da_mem[391698]) << 0x10 | uint(c2da_mem[391699]) << 0x18) >> 20
    let c2da_fresh86 : int = 0
    let c2da_fresh87 : uint = uint(c2da_fresh86)
    c2da_mem[391700] = uint8(c2da_fresh87)
    c2da_mem[391701] = uint8(c2da_fresh87 >> 0x8)
    c2da_mem[391702] = uint8(c2da_fresh87 >> 0x10)
    c2da_mem[391703] = uint8(c2da_fresh87 >> 0x18)
    let c2da_fresh88 : uint = 0u
    c2da_mem[391704] = uint8(c2da_fresh88)
    c2da_mem[391705] = uint8(c2da_fresh88 >> 0x8)
    c2da_mem[391706] = uint8(c2da_fresh88 >> 0x10)
    c2da_mem[391707] = uint8(c2da_fresh88 >> 0x18)
    c2da_mem[391708] = 0u8
    c2da_mem[391709] = 0u8
    c2da_mem[391710] = 0u8
    c2da_mem[391711] = 0u8
    let c2da_fresh89 : uint = 391632u
    c2da_mem[391712] = uint8(c2da_fresh89)
    c2da_mem[391713] = uint8(c2da_fresh89 >> 0x8)
    c2da_mem[391714] = uint8(c2da_fresh89 >> 0x10)
    c2da_mem[391715] = uint8(c2da_fresh89 >> 0x18)
    c2da_mem[391716] = 0u8
    c2da_mem[391717] = 0u8
    c2da_mem[391718] = 0u8
    c2da_mem[391719] = 0u8
    let c2da_fresh90 : uint16 = uint16(0)
    let c2da_fresh91 : uint = uint(c2da_fresh90)
    c2da_mem[391720 + 0 * 2] = uint8(c2da_fresh91)
    c2da_mem[391720 + 0 * 2 + 1] = uint8(c2da_fresh91 >> 0x8)
    let c2da_fresh92 : uint16 = uint16(1)
    let c2da_fresh93 : uint = uint(c2da_fresh92)
    c2da_mem[391720 + 1 * 2] = uint8(c2da_fresh93)
    c2da_mem[391720 + 1 * 2 + 1] = uint8(c2da_fresh93 >> 0x8)
    let c2da_fresh94 : int = (int(uint(c2da_mem[5248]) | uint(c2da_mem[5249]) << 0x8 | uint(c2da_mem[5250]) << 0x10 | uint(c2da_mem[5251]) << 0x18) << 20) + 1048575
    let c2da_fresh95 : uint = uint(c2da_fresh94)
    c2da_mem[391632] = uint8(c2da_fresh95)
    c2da_mem[391633] = uint8(c2da_fresh95 >> 0x8)
    c2da_mem[391634] = uint8(c2da_fresh95 >> 0x10)
    c2da_mem[391635] = uint8(c2da_fresh95 >> 0x18)
    edge_tail_u_shift20 = int(uint(c2da_mem[391632]) | uint(c2da_mem[391633]) << 0x8 | uint(c2da_mem[391634]) << 0x10 | uint(c2da_mem[391635]) << 0x18) >> 20
    let c2da_fresh96 : int = 0
    let c2da_fresh97 : uint = uint(c2da_fresh96)
    c2da_mem[391636] = uint8(c2da_fresh97)
    c2da_mem[391637] = uint8(c2da_fresh97 >> 0x8)
    c2da_mem[391638] = uint8(c2da_fresh97 >> 0x10)
    c2da_mem[391639] = uint8(c2da_fresh97 >> 0x18)
    let c2da_fresh98 : uint = 391696u
    c2da_mem[391640] = uint8(c2da_fresh98)
    c2da_mem[391641] = uint8(c2da_fresh98 >> 0x8)
    c2da_mem[391642] = uint8(c2da_fresh98 >> 0x10)
    c2da_mem[391643] = uint8(c2da_fresh98 >> 0x18)
    c2da_mem[391644] = 0u8
    c2da_mem[391645] = 0u8
    c2da_mem[391646] = 0u8
    c2da_mem[391647] = 0u8
    let c2da_fresh99 : uint = 391760u
    c2da_mem[391648] = uint8(c2da_fresh99)
    c2da_mem[391649] = uint8(c2da_fresh99 >> 0x8)
    c2da_mem[391650] = uint8(c2da_fresh99 >> 0x10)
    c2da_mem[391651] = uint8(c2da_fresh99 >> 0x18)
    c2da_mem[391652] = 0u8
    c2da_mem[391653] = 0u8
    c2da_mem[391654] = 0u8
    c2da_mem[391655] = 0u8
    let c2da_fresh100 : uint16 = uint16(1)
    let c2da_fresh101 : uint = uint(c2da_fresh100)
    c2da_mem[391656 + 0 * 2] = uint8(c2da_fresh101)
    c2da_mem[391656 + 0 * 2 + 1] = uint8(c2da_fresh101 >> 0x8)
    let c2da_fresh102 : uint16 = uint16(0)
    let c2da_fresh103 : uint = uint(c2da_fresh102)
    c2da_mem[391656 + 1 * 2] = uint8(c2da_fresh103)
    c2da_mem[391656 + 1 * 2 + 1] = uint8(c2da_fresh103 >> 0x8)
    let c2da_fresh104 : int = -1
    let c2da_fresh105 : uint = uint(c2da_fresh104)
    c2da_mem[391760] = uint8(c2da_fresh105)
    c2da_mem[391761] = uint8(c2da_fresh105 >> 0x8)
    c2da_mem[391762] = uint8(c2da_fresh105 >> 0x10)
    c2da_mem[391763] = uint8(c2da_fresh105 >> 0x18)
    let c2da_fresh106 : int = 0
    let c2da_fresh107 : uint = uint(c2da_fresh106)
    c2da_mem[391764] = uint8(c2da_fresh107)
    c2da_mem[391765] = uint8(c2da_fresh107 >> 0x8)
    c2da_mem[391766] = uint8(c2da_fresh107 >> 0x10)
    c2da_mem[391767] = uint8(c2da_fresh107 >> 0x18)
    let c2da_fresh108 : uint = 391824u
    c2da_mem[391776] = uint8(c2da_fresh108)
    c2da_mem[391777] = uint8(c2da_fresh108 >> 0x8)
    c2da_mem[391778] = uint8(c2da_fresh108 >> 0x10)
    c2da_mem[391779] = uint8(c2da_fresh108 >> 0x18)
    c2da_mem[391780] = 0u8
    c2da_mem[391781] = 0u8
    c2da_mem[391782] = 0u8
    c2da_mem[391783] = 0u8
    let c2da_fresh109 : uint = 391632u
    c2da_mem[391768] = uint8(c2da_fresh109)
    c2da_mem[391769] = uint8(c2da_fresh109 >> 0x8)
    c2da_mem[391770] = uint8(c2da_fresh109 >> 0x10)
    c2da_mem[391771] = uint8(c2da_fresh109 >> 0x18)
    c2da_mem[391772] = 0u8
    c2da_mem[391773] = 0u8
    c2da_mem[391774] = 0u8
    c2da_mem[391775] = 0u8
    let c2da_fresh110 : int = 2000 << 24
    let c2da_fresh111 : uint = uint(c2da_fresh110)
    c2da_mem[391824] = uint8(c2da_fresh111)
    c2da_mem[391825] = uint8(c2da_fresh111 >> 0x8)
    c2da_mem[391826] = uint8(c2da_fresh111 >> 0x10)
    c2da_mem[391827] = uint8(c2da_fresh111 >> 0x18)
    let c2da_fresh112 : uint = 391760u
    c2da_mem[391832] = uint8(c2da_fresh112)
    c2da_mem[391833] = uint8(c2da_fresh112 >> 0x8)
    c2da_mem[391834] = uint8(c2da_fresh112 >> 0x10)
    c2da_mem[391835] = uint8(c2da_fresh112 >> 0x18)
    c2da_mem[391836] = 0u8
    c2da_mem[391837] = 0u8
    c2da_mem[391838] = 0u8
    c2da_mem[391839] = 0u8
    bottom = int(uint(c2da_mem[5252]) | uint(c2da_mem[5253]) << 0x8 | uint(c2da_mem[5254]) << 0x10 | uint(c2da_mem[5255]) << 0x18) - 1
    iv = int(uint(c2da_mem[5204]) | uint(c2da_mem[5205]) << 0x8 | uint(c2da_mem[5206]) << 0x10 | uint(c2da_mem[5207]) << 0x18)
    while (iv < bottom) {
        current_iv = iv
        fv = float(iv)
        let c2da_fresh113 : int = 1
        let c2da_fresh114 : uint = uint(c2da_fresh113)
        c2da_mem[surfaces + 1 * 88 + 32] = uint8(c2da_fresh114)
        c2da_mem[surfaces + 1 * 88 + 33] = uint8(c2da_fresh114 >> 0x8)
        c2da_mem[surfaces + 1 * 88 + 34] = uint8(c2da_fresh114 >> 0x10)
        c2da_mem[surfaces + 1 * 88 + 35] = uint8(c2da_fresh114 >> 0x18)
        if (newedges[iv] != 0) {
            R_InsertNewEdges(newedges[iv], int(uint(c2da_mem[391712]) | uint(c2da_mem[391713]) << 0x8 | uint(c2da_mem[391714]) << 0x10 | uint(c2da_mem[391715]) << 0x18))
        }
        invoke(c2da_fn_table0[pdrawfunc])
        if (span_p >= max_span_p) {
            S_ExtraUpdate()
            if (uint(r_drawculledpolys) != 0u) {
                R_DrawCulledPolys()
            } else {
                D_DrawSurfaces()
            }
            s = surfaces + 1 * 88
            while (s < surface_p) {
                let c2da_fresh115 : uint = 0u
                c2da_mem[s + 16] = uint8(c2da_fresh115)
                c2da_mem[s + 17] = uint8(c2da_fresh115 >> 0x8)
                c2da_mem[s + 18] = uint8(c2da_fresh115 >> 0x10)
                c2da_mem[s + 19] = uint8(c2da_fresh115 >> 0x18)
                c2da_mem[s + 20] = 0u8
                c2da_mem[s + 21] = 0u8
                c2da_mem[s + 22] = 0u8
                c2da_mem[s + 23] = 0u8
                s += 88
            }
            span_p = basespan_p
        }
        if (removeedges[iv] != 0) {
            R_RemoveEdges(removeedges[iv])
        }
        if (int(uint(c2da_mem[391712]) | uint(c2da_mem[391713]) << 0x8 | uint(c2da_mem[391714]) << 0x10 | uint(c2da_mem[391715]) << 0x18) != 391632) {
            R_StepActiveU(int(uint(c2da_mem[391712]) | uint(c2da_mem[391713]) << 0x8 | uint(c2da_mem[391714]) << 0x10 | uint(c2da_mem[391715]) << 0x18))
        }
        iv++
    }
    current_iv = iv
    fv = float(iv)
    let c2da_fresh116 : int = 1
    let c2da_fresh117 : uint = uint(c2da_fresh116)
    c2da_mem[surfaces + 1 * 88 + 32] = uint8(c2da_fresh117)
    c2da_mem[surfaces + 1 * 88 + 33] = uint8(c2da_fresh117 >> 0x8)
    c2da_mem[surfaces + 1 * 88 + 34] = uint8(c2da_fresh117 >> 0x10)
    c2da_mem[surfaces + 1 * 88 + 35] = uint8(c2da_fresh117 >> 0x18)
    if (newedges[iv] != 0) {
        R_InsertNewEdges(newedges[iv], int(uint(c2da_mem[391712]) | uint(c2da_mem[391713]) << 0x8 | uint(c2da_mem[391714]) << 0x10 | uint(c2da_mem[391715]) << 0x18))
    }
    invoke(c2da_fn_table0[pdrawfunc])
    if (uint(r_drawculledpolys) != 0u) {
        R_DrawCulledPolys()
    } else {
        D_DrawSurfaces()
    }
    return
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_r_edge() {
    if (length(c2da_fn_table0) < 209) {
        resize(c2da_fn_table0, 209)
    }
    c2da_fn_table0[208] = @@R_GenerateSpans
    c2da_fn_table0[207] = @@R_GenerateSpansBackward
}

[init]
def private c2da_lin_relink_init_r_edge() {
    c2da_relink_r_edge()
}
