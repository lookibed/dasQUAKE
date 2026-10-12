[export, sideeffects]
def R_AddEfrags(var ent : int) {
    var entmodel : int
    if (int(uint(c2da_mem[ent + 136]) | uint(c2da_mem[ent + 137]) << 0x8 | uint(c2da_mem[ent + 138]) << 0x10 | uint(c2da_mem[ent + 139]) << 0x18) == 0) {
        return
    }
    if (ent == 10048) {
        return
    }
    r_addent = int(ent)  // nolint:PERF020
    lastlink = ent + 144
    r_pefragtopnode = 0
    entmodel = int(uint(c2da_mem[ent + 136]) | uint(c2da_mem[ent + 137]) << 0x8 | uint(c2da_mem[ent + 138]) << 0x10 | uint(c2da_mem[ent + 139]) << 0x18)
    for (i in range(0, 3)) {
        let c2da_fresh0 : float = uint_bits_to_float(uint(c2da_mem[ent + 88 + i * 4]) | uint(c2da_mem[ent + 88 + i * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + i * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + i * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[entmodel + 84 + i * 4]) | uint(c2da_mem[entmodel + 84 + i * 4 + 1]) << 0x8 | uint(c2da_mem[entmodel + 84 + i * 4 + 2]) << 0x10 | uint(c2da_mem[entmodel + 84 + i * 4 + 3]) << 0x18)
        let c2da_fresh1 : uint = float_bits_to_uint(c2da_fresh0)
        c2da_mem[391888 + i * 4] = uint8(c2da_fresh1)
        c2da_mem[391888 + i * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[391888 + i * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[391888 + i * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
        let c2da_fresh2 : float = uint_bits_to_float(uint(c2da_mem[ent + 88 + i * 4]) | uint(c2da_mem[ent + 88 + i * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + i * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + i * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[entmodel + 96 + i * 4]) | uint(c2da_mem[entmodel + 96 + i * 4 + 1]) << 0x8 | uint(c2da_mem[entmodel + 96 + i * 4 + 2]) << 0x10 | uint(c2da_mem[entmodel + 96 + i * 4 + 3]) << 0x18)
        let c2da_fresh3 : uint = float_bits_to_uint(c2da_fresh2)
        c2da_mem[391904 + i * 4] = uint8(c2da_fresh3)
        c2da_mem[391904 + i * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[391904 + i * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[391904 + i * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
    }
    let c2da_fresh4 : int = int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) + 208
    R_SplitEntityOnNode(int(uint(c2da_mem[c2da_fresh4]) | uint(c2da_mem[c2da_fresh4 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh4 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh4 + 3]) << 0x18))
    let c2da_fresh5 : uint = uint(r_pefragtopnode)
    c2da_mem[ent + 192] = uint8(c2da_fresh5)
    c2da_mem[ent + 193] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[ent + 194] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[ent + 195] = uint8(c2da_fresh5 >> 0x18)
    c2da_mem[ent + 196] = 0u8
    c2da_mem[ent + 197] = 0u8
    c2da_mem[ent + 198] = 0u8
    c2da_mem[ent + 199] = 0u8
    return
}
var r_pefragtopnode : int = default<int>

[export, sideeffects]
def R_SplitEntityOnNode(var node : int) {
    var ef : int
    var splitplane : int
    var leaf : int
    var sides : int
    if (int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18) == -2) {
        return
    }
    if (int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18) < 0) {
        if (r_pefragtopnode == 0) {
            r_pefragtopnode = int(node)  // nolint:PERF020
        }
        leaf = node
        ef = int(uint(c2da_mem[4968]) | uint(c2da_mem[4969]) << 0x8 | uint(c2da_mem[4970]) << 0x10 | uint(c2da_mem[4971]) << 0x18)
        if (ef == 0) {
            Con_Printf(732672, [])
            return
        }
        let c2da_fresh6 : int = int(uint(c2da_mem[4968]) | uint(c2da_mem[4969]) << 0x8 | uint(c2da_mem[4970]) << 0x10 | uint(c2da_mem[4971]) << 0x18) + 24
        let c2da_fresh7 : int = int(uint(c2da_mem[c2da_fresh6]) | uint(c2da_mem[c2da_fresh6 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh6 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh6 + 3]) << 0x18)
        let c2da_fresh8 : uint = uint(c2da_fresh7)
        c2da_mem[4968] = uint8(c2da_fresh8)
        c2da_mem[4969] = uint8(c2da_fresh8 >> 0x8)
        c2da_mem[4970] = uint8(c2da_fresh8 >> 0x10)
        c2da_mem[4971] = uint8(c2da_fresh8 >> 0x18)
        c2da_mem[4972] = 0u8
        c2da_mem[4973] = 0u8
        c2da_mem[4974] = 0u8
        c2da_mem[4975] = 0u8
        let c2da_fresh9 : uint = uint(r_addent)
        c2da_mem[ef + 16] = uint8(c2da_fresh9)
        c2da_mem[ef + 17] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[ef + 18] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[ef + 19] = uint8(c2da_fresh9 >> 0x18)
        c2da_mem[ef + 20] = 0u8
        c2da_mem[ef + 21] = 0u8
        c2da_mem[ef + 22] = 0u8
        c2da_mem[ef + 23] = 0u8
        let c2da_fresh10 : uint = uint(ef)
        c2da_mem[lastlink] = uint8(c2da_fresh10)
        c2da_mem[lastlink + 1] = uint8(c2da_fresh10 >> 0x8)
        c2da_mem[lastlink + 2] = uint8(c2da_fresh10 >> 0x10)
        c2da_mem[lastlink + 3] = uint8(c2da_fresh10 >> 0x18)
        c2da_mem[lastlink + 4] = 0u8
        c2da_mem[lastlink + 5] = 0u8
        c2da_mem[lastlink + 6] = 0u8
        c2da_mem[lastlink + 7] = 0u8
        lastlink = ef + 24
        let c2da_fresh11 : uint = 0u
        c2da_mem[ef + 24] = uint8(c2da_fresh11)
        c2da_mem[ef + 25] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[ef + 26] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[ef + 27] = uint8(c2da_fresh11 >> 0x18)
        c2da_mem[ef + 28] = 0u8
        c2da_mem[ef + 29] = 0u8
        c2da_mem[ef + 30] = 0u8
        c2da_mem[ef + 31] = 0u8
        let c2da_fresh12 : uint = uint(leaf)
        c2da_mem[ef] = uint8(c2da_fresh12)
        c2da_mem[ef + 1] = uint8(c2da_fresh12 >> 0x8)
        c2da_mem[ef + 2] = uint8(c2da_fresh12 >> 0x10)
        c2da_mem[ef + 3] = uint8(c2da_fresh12 >> 0x18)
        c2da_mem[ef + 4] = 0u8
        c2da_mem[ef + 5] = 0u8
        c2da_mem[ef + 6] = 0u8
        c2da_mem[ef + 7] = 0u8
        let c2da_fresh13 : int = int(uint(c2da_mem[leaf + 40]) | uint(c2da_mem[leaf + 41]) << 0x8 | uint(c2da_mem[leaf + 42]) << 0x10 | uint(c2da_mem[leaf + 43]) << 0x18)
        let c2da_fresh14 : uint = uint(c2da_fresh13)
        c2da_mem[ef + 8] = uint8(c2da_fresh14)
        c2da_mem[ef + 9] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[ef + 10] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[ef + 11] = uint8(c2da_fresh14 >> 0x18)
        c2da_mem[ef + 12] = 0u8
        c2da_mem[ef + 13] = 0u8
        c2da_mem[ef + 14] = 0u8
        c2da_mem[ef + 15] = 0u8
        let c2da_fresh15 : uint = uint(ef)
        c2da_mem[leaf + 40] = uint8(c2da_fresh15)
        c2da_mem[leaf + 41] = uint8(c2da_fresh15 >> 0x8)
        c2da_mem[leaf + 42] = uint8(c2da_fresh15 >> 0x10)
        c2da_mem[leaf + 43] = uint8(c2da_fresh15 >> 0x18)
        c2da_mem[leaf + 44] = 0u8
        c2da_mem[leaf + 45] = 0u8
        c2da_mem[leaf + 46] = 0u8
        c2da_mem[leaf + 47] = 0u8
        return
    }
    splitplane = int(uint(c2da_mem[node + 32]) | uint(c2da_mem[node + 33]) << 0x8 | uint(c2da_mem[node + 34]) << 0x10 | uint(c2da_mem[node + 35]) << 0x18)
    var c2da_fresh19 : int = 0
    if (int(c2da_mem[splitplane + 16]) < 3) {
        let c2da_fresh16 : int = 391888 + int(c2da_mem[splitplane + 16]) * 4
        var c2da_fresh18 : int = 0
        let c2da_fresh20 : float = uint_bits_to_float(uint(c2da_mem[splitplane + 12]) | uint(c2da_mem[splitplane + 13]) << 0x8 | uint(c2da_mem[splitplane + 14]) << 0x10 | uint(c2da_mem[splitplane + 15]) << 0x18)
        if (c2da_fresh20 <= uint_bits_to_float(uint(c2da_mem[c2da_fresh16]) | uint(c2da_mem[c2da_fresh16 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh16 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh16 + 3]) << 0x18)) {
            c2da_fresh18 = 1
        } else {
            let c2da_fresh17 : int = 391904 + int(c2da_mem[splitplane + 16]) * 4
            c2da_fresh18 = c2da_fresh20 >= uint_bits_to_float(uint(c2da_mem[c2da_fresh17]) | uint(c2da_mem[c2da_fresh17 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh17 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh17 + 3]) << 0x18) ? 2 : 3
        }
        c2da_fresh19 = c2da_fresh18
    } else {
        c2da_fresh19 = BoxOnPlaneSide(391888, 391904, splitplane)
    }
    sides = c2da_fresh19
    if (sides == 3) {
        if (r_pefragtopnode == 0) {
            r_pefragtopnode = int(node)  // nolint:PERF020
        }
    }
    if ((sides & 1) != 0) {
        R_SplitEntityOnNode(int(uint(c2da_mem[node + 40 + 0 * 8]) | uint(c2da_mem[node + 40 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[node + 40 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[node + 40 + 0 * 8 + 3]) << 0x18))
    }
    if ((sides & 2) != 0) {
        R_SplitEntityOnNode(int(uint(c2da_mem[node + 40 + 1 * 8]) | uint(c2da_mem[node + 40 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[node + 40 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[node + 40 + 1 * 8 + 3]) << 0x18))
    }
    return
}
var lastlink : int = default<int>

var r_addent : int = default<int>

[export, sideeffects]
def R_RemoveEfrags(var ent_0 : int) {
    var ef_0 : int
    var old : int
    var walk : int
    var prev : int
    ef_0 = int(uint(c2da_mem[ent_0 + 144]) | uint(c2da_mem[ent_0 + 145]) << 0x8 | uint(c2da_mem[ent_0 + 146]) << 0x10 | uint(c2da_mem[ent_0 + 147]) << 0x18)
    while (ef_0 != 0) {
        prev = int(uint(c2da_mem[ef_0]) | uint(c2da_mem[ef_0 + 1]) << 0x8 | uint(c2da_mem[ef_0 + 2]) << 0x10 | uint(c2da_mem[ef_0 + 3]) << 0x18) + 40
        while (true) {
            walk = int(uint(c2da_mem[prev]) | uint(c2da_mem[prev + 1]) << 0x8 | uint(c2da_mem[prev + 2]) << 0x10 | uint(c2da_mem[prev + 3]) << 0x18)
            if (walk == 0) {
                break
            }
            if (walk == ef_0) {
                let c2da_fresh21 : int = int(uint(c2da_mem[ef_0 + 8]) | uint(c2da_mem[ef_0 + 9]) << 0x8 | uint(c2da_mem[ef_0 + 10]) << 0x10 | uint(c2da_mem[ef_0 + 11]) << 0x18)
                let c2da_fresh22 : uint = uint(c2da_fresh21)
                c2da_mem[prev] = uint8(c2da_fresh22)
                c2da_mem[prev + 1] = uint8(c2da_fresh22 >> 0x8)
                c2da_mem[prev + 2] = uint8(c2da_fresh22 >> 0x10)
                c2da_mem[prev + 3] = uint8(c2da_fresh22 >> 0x18)
                c2da_mem[prev + 4] = 0u8
                c2da_mem[prev + 5] = 0u8
                c2da_mem[prev + 6] = 0u8
                c2da_mem[prev + 7] = 0u8
                break
            } else {
                prev = walk + 8
            }
        }
        old = ef_0
        ef_0 = int(uint(c2da_mem[ef_0 + 24]) | uint(c2da_mem[ef_0 + 25]) << 0x8 | uint(c2da_mem[ef_0 + 26]) << 0x10 | uint(c2da_mem[ef_0 + 27]) << 0x18)
        let c2da_fresh23 : int = int(uint(c2da_mem[4968]) | uint(c2da_mem[4969]) << 0x8 | uint(c2da_mem[4970]) << 0x10 | uint(c2da_mem[4971]) << 0x18)
        let c2da_fresh24 : uint = uint(c2da_fresh23)
        c2da_mem[old + 24] = uint8(c2da_fresh24)
        c2da_mem[old + 25] = uint8(c2da_fresh24 >> 0x8)
        c2da_mem[old + 26] = uint8(c2da_fresh24 >> 0x10)
        c2da_mem[old + 27] = uint8(c2da_fresh24 >> 0x18)
        c2da_mem[old + 28] = 0u8
        c2da_mem[old + 29] = 0u8
        c2da_mem[old + 30] = 0u8
        c2da_mem[old + 31] = 0u8
        let c2da_fresh25 : uint = uint(old)
        c2da_mem[4968] = uint8(c2da_fresh25)
        c2da_mem[4969] = uint8(c2da_fresh25 >> 0x8)
        c2da_mem[4970] = uint8(c2da_fresh25 >> 0x10)
        c2da_mem[4971] = uint8(c2da_fresh25 >> 0x18)
        c2da_mem[4972] = 0u8
        c2da_mem[4973] = 0u8
        c2da_mem[4974] = 0u8
        c2da_mem[4975] = 0u8
    }
    let c2da_fresh26 : uint = 0u
    c2da_mem[ent_0 + 144] = uint8(c2da_fresh26)
    c2da_mem[ent_0 + 145] = uint8(c2da_fresh26 >> 0x8)
    c2da_mem[ent_0 + 146] = uint8(c2da_fresh26 >> 0x10)
    c2da_mem[ent_0 + 147] = uint8(c2da_fresh26 >> 0x18)
    c2da_mem[ent_0 + 148] = 0u8
    c2da_mem[ent_0 + 149] = 0u8
    c2da_mem[ent_0 + 150] = 0u8
    c2da_mem[ent_0 + 151] = 0u8
    return
}
[export, sideeffects]
def R_StoreEfrags(var ppefrag : int) {
    var c2da_fresh27 : uint
    var pent : int
    var clmodel : int
    var pefrag : int
    while (true) {
        pefrag = int(uint(c2da_mem[ppefrag]) | uint(c2da_mem[ppefrag + 1]) << 0x8 | uint(c2da_mem[ppefrag + 2]) << 0x10 | uint(c2da_mem[ppefrag + 3]) << 0x18)
        if (pefrag == 0) {
            break
        }
        let c2da_fresh29 : int = int(uint(c2da_mem[pefrag + 16]) | uint(c2da_mem[pefrag + 17]) << 0x8 | uint(c2da_mem[pefrag + 18]) << 0x10 | uint(c2da_mem[pefrag + 19]) << 0x18)
        pent = c2da_fresh29
        clmodel = int(uint(c2da_mem[pent + 136]) | uint(c2da_mem[pent + 137]) << 0x8 | uint(c2da_mem[pent + 138]) << 0x10 | uint(c2da_mem[pent + 139]) << 0x18)
        c2da_fresh27 = uint(c2da_mem[clmodel + 68]) | uint(c2da_mem[clmodel + 69]) << 0x8 | uint(c2da_mem[clmodel + 70]) << 0x10 | uint(c2da_mem[clmodel + 71]) << 0x18
        if (c2da_fresh27 == 0x2u || c2da_fresh27 == 0x0u || c2da_fresh27 == 0x1u) {
            pent = c2da_fresh29
            if (int(uint(c2da_mem[pent + 176]) | uint(c2da_mem[pent + 177]) << 0x8 | uint(c2da_mem[pent + 178]) << 0x10 | uint(c2da_mem[pent + 179]) << 0x18) != r_framecount && cl_numvisedicts < 256) {
                let c2da_postinc : int = cl_numvisedicts
                cl_numvisedicts = cl_numvisedicts + 1
                cl_visedicts[c2da_postinc] = pent
                let c2da_fresh28 : uint = uint(r_framecount)
                c2da_mem[pent + 176] = uint8(c2da_fresh28)
                c2da_mem[pent + 177] = uint8(c2da_fresh28 >> 0x8)
                c2da_mem[pent + 178] = uint8(c2da_fresh28 >> 0x10)
                c2da_mem[pent + 179] = uint8(c2da_fresh28 >> 0x18)
            }
            ppefrag = pefrag + 8
        } else {
            Sys_Error(732690, [C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[clmodel + 68]) | uint(c2da_mem[clmodel + 69]) << 0x8 | uint(c2da_mem[clmodel + 70]) << 0x10 | uint(c2da_mem[clmodel + 71]) << 0x18), f64 = 0.0lf, raw = 0x0)])
        }
    }
    return
}
[export, sideeffects]
def R_SplitEntityOnNode2(var node_0 : int) {
    var splitplane_0 : int
    var sides_0 : int
    if (int(uint(c2da_mem[node_0 + 4]) | uint(c2da_mem[node_0 + 5]) << 0x8 | uint(c2da_mem[node_0 + 6]) << 0x10 | uint(c2da_mem[node_0 + 7]) << 0x18) != r_visframecount) {
        return
    }
    let c2da_fresh34 : int = int(uint(c2da_mem[node_0]) | uint(c2da_mem[node_0 + 1]) << 0x8 | uint(c2da_mem[node_0 + 2]) << 0x10 | uint(c2da_mem[node_0 + 3]) << 0x18)
    if (c2da_fresh34 < 0) {
        if (c2da_fresh34 != -2) {
            r_pefragtopnode = int(node_0)  // nolint:PERF020
        }
        return
    }
    splitplane_0 = int(uint(c2da_mem[node_0 + 32]) | uint(c2da_mem[node_0 + 33]) << 0x8 | uint(c2da_mem[node_0 + 34]) << 0x10 | uint(c2da_mem[node_0 + 35]) << 0x18)
    var c2da_fresh33 : int = 0
    if (int(c2da_mem[splitplane_0 + 16]) < 3) {
        let c2da_fresh30 : int = 391888 + int(c2da_mem[splitplane_0 + 16]) * 4
        var c2da_fresh32 : int = 0
        let c2da_fresh35 : float = uint_bits_to_float(uint(c2da_mem[splitplane_0 + 12]) | uint(c2da_mem[splitplane_0 + 13]) << 0x8 | uint(c2da_mem[splitplane_0 + 14]) << 0x10 | uint(c2da_mem[splitplane_0 + 15]) << 0x18)
        if (c2da_fresh35 <= uint_bits_to_float(uint(c2da_mem[c2da_fresh30]) | uint(c2da_mem[c2da_fresh30 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh30 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh30 + 3]) << 0x18)) {
            c2da_fresh32 = 1
        } else {
            let c2da_fresh31 : int = 391904 + int(c2da_mem[splitplane_0 + 16]) * 4
            c2da_fresh32 = c2da_fresh35 >= uint_bits_to_float(uint(c2da_mem[c2da_fresh31]) | uint(c2da_mem[c2da_fresh31 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh31 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh31 + 3]) << 0x18) ? 2 : 3
        }
        c2da_fresh33 = c2da_fresh32
    } else {
        c2da_fresh33 = BoxOnPlaneSide(391888, 391904, splitplane_0)
    }
    sides_0 = c2da_fresh33
    if (sides_0 == 3) {
        r_pefragtopnode = int(node_0)  // nolint:PERF020
        return
    }
    if ((sides_0 & 1) != 0) {
        R_SplitEntityOnNode2(int(uint(c2da_mem[node_0 + 40 + 0 * 8]) | uint(c2da_mem[node_0 + 40 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[node_0 + 40 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[node_0 + 40 + 0 * 8 + 3]) << 0x18))
    } else {
        R_SplitEntityOnNode2(int(uint(c2da_mem[node_0 + 40 + 1 * 8]) | uint(c2da_mem[node_0 + 40 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[node_0 + 40 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[node_0 + 40 + 1 * 8 + 3]) << 0x18))
    }
    return
}

// This unit's static data, at heap offset 732672.
let private c2da_lin_static_r_efrag_seg = fixed_array<int>(732672, 52)
let private c2da_lin_static_r_efrag = fixed_array<uint64>(0x796e616d206f6f54ul, 0x2173676172666520ul, 0x726f74535f52000aul, 0x3a73676172664565ul, 0x746e652064614220ul, 0x6570797420797469ul, 0xa642520ul)

[init]
def private c2da_lin_init_static_r_efrag() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_efrag_seg[s * 2]
        for (k in range(c2da_lin_static_r_efrag_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_efrag[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
