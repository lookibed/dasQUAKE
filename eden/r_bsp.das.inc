var currententity : int = default<int>

var base_modelorg : vec3_t = default<vec3_t>

[export, sideeffects]
def R_RenderWorld() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_RenderWorld_c2da_frame(c2da_lin_enter(80000))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_RecursiveWorldNode(var node : int; var clipflags : int) {
    var c2da_fresh15 : int
    var c : int
    var side : int
    var pindex : int
    var acceptpt : vec3_t
    var rejectpt : vec3_t
    var plane : int
    var surf : int
    var mark : int
    var pleaf : int
    var d : double
    var dot : double
    if (int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18) == -2) {
        return
    }
    if (int(uint(c2da_mem[node + 4]) | uint(c2da_mem[node + 5]) << 0x8 | uint(c2da_mem[node + 6]) << 0x10 | uint(c2da_mem[node + 7]) << 0x18) != r_visframecount) {
        return
    }
    if (clipflags != 0) {
        for (i_0 in range(0, 4)) {
            if ((clipflags & 1 << i_0) == 0) {
                continue
            }
            pindex = pfrustum_indexes[i_0]
            let c2da_fresh6 : int = node + 8 + int(uint(c2da_mem[pindex + 0 * 4]) | uint(c2da_mem[pindex + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pindex + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pindex + 0 * 4 + 3]) << 0x18) * 2
            rejectpt[0] = float(int16(uint(c2da_mem[c2da_fresh6]) | uint(c2da_mem[c2da_fresh6 + 1]) << 0x8))
            let c2da_fresh7 : int = node + 8 + int(uint(c2da_mem[pindex + 1 * 4]) | uint(c2da_mem[pindex + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pindex + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pindex + 1 * 4 + 3]) << 0x18) * 2
            rejectpt[1] = float(int16(uint(c2da_mem[c2da_fresh7]) | uint(c2da_mem[c2da_fresh7 + 1]) << 0x8))
            let c2da_fresh8 : int = node + 8 + int(uint(c2da_mem[pindex + 2 * 4]) | uint(c2da_mem[pindex + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pindex + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pindex + 2 * 4 + 3]) << 0x18) * 2
            rejectpt[2] = float(int16(uint(c2da_mem[c2da_fresh8]) | uint(c2da_mem[c2da_fresh8 + 1]) << 0x8))
            d = double(rejectpt[0] * uint_bits_to_float(uint(c2da_mem[391440 + i_0 * 32 + 0 * 4]) | uint(c2da_mem[391440 + i_0 * 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + i_0 * 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + i_0 * 32 + 0 * 4 + 3]) << 0x18) + rejectpt[1] * uint_bits_to_float(uint(c2da_mem[391440 + i_0 * 32 + 1 * 4]) | uint(c2da_mem[391440 + i_0 * 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + i_0 * 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + i_0 * 32 + 1 * 4 + 3]) << 0x18) + rejectpt[2] * uint_bits_to_float(uint(c2da_mem[391440 + i_0 * 32 + 2 * 4]) | uint(c2da_mem[391440 + i_0 * 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + i_0 * 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + i_0 * 32 + 2 * 4 + 3]) << 0x18))
            d = d - double(uint_bits_to_float(uint(c2da_mem[391440 + i_0 * 32 + 12]) | uint(c2da_mem[391440 + i_0 * 32 + 13]) << 0x8 | uint(c2da_mem[391440 + i_0 * 32 + 14]) << 0x10 | uint(c2da_mem[391440 + i_0 * 32 + 15]) << 0x18))
            if (d <= 0.0lf) {
                return
            }
            let c2da_fresh9 : int = node + 8 + int(uint(c2da_mem[pindex + (3 + 0) * 4]) | uint(c2da_mem[pindex + (3 + 0) * 4 + 1]) << 0x8 | uint(c2da_mem[pindex + (3 + 0) * 4 + 2]) << 0x10 | uint(c2da_mem[pindex + (3 + 0) * 4 + 3]) << 0x18) * 2
            acceptpt[0] = float(int16(uint(c2da_mem[c2da_fresh9]) | uint(c2da_mem[c2da_fresh9 + 1]) << 0x8))
            let c2da_fresh10 : int = node + 8 + int(uint(c2da_mem[pindex + (3 + 1) * 4]) | uint(c2da_mem[pindex + (3 + 1) * 4 + 1]) << 0x8 | uint(c2da_mem[pindex + (3 + 1) * 4 + 2]) << 0x10 | uint(c2da_mem[pindex + (3 + 1) * 4 + 3]) << 0x18) * 2
            acceptpt[1] = float(int16(uint(c2da_mem[c2da_fresh10]) | uint(c2da_mem[c2da_fresh10 + 1]) << 0x8))
            let c2da_fresh11 : int = node + 8 + int(uint(c2da_mem[pindex + (3 + 2) * 4]) | uint(c2da_mem[pindex + (3 + 2) * 4 + 1]) << 0x8 | uint(c2da_mem[pindex + (3 + 2) * 4 + 2]) << 0x10 | uint(c2da_mem[pindex + (3 + 2) * 4 + 3]) << 0x18) * 2
            acceptpt[2] = float(int16(uint(c2da_mem[c2da_fresh11]) | uint(c2da_mem[c2da_fresh11 + 1]) << 0x8))
            d = double(acceptpt[0] * uint_bits_to_float(uint(c2da_mem[391440 + i_0 * 32 + 0 * 4]) | uint(c2da_mem[391440 + i_0 * 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + i_0 * 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + i_0 * 32 + 0 * 4 + 3]) << 0x18) + acceptpt[1] * uint_bits_to_float(uint(c2da_mem[391440 + i_0 * 32 + 1 * 4]) | uint(c2da_mem[391440 + i_0 * 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + i_0 * 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + i_0 * 32 + 1 * 4 + 3]) << 0x18) + acceptpt[2] * uint_bits_to_float(uint(c2da_mem[391440 + i_0 * 32 + 2 * 4]) | uint(c2da_mem[391440 + i_0 * 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + i_0 * 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + i_0 * 32 + 2 * 4 + 3]) << 0x18))
            d = d - double(uint_bits_to_float(uint(c2da_mem[391440 + i_0 * 32 + 12]) | uint(c2da_mem[391440 + i_0 * 32 + 13]) << 0x8 | uint(c2da_mem[391440 + i_0 * 32 + 14]) << 0x10 | uint(c2da_mem[391440 + i_0 * 32 + 15]) << 0x18))
            if (d >= 0.0lf) {
                clipflags &= ~(1 << i_0)
            }
        }
    }
    if (int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18) < 0) {
        pleaf = node
        mark = int(uint(c2da_mem[pleaf + 48]) | uint(c2da_mem[pleaf + 49]) << 0x8 | uint(c2da_mem[pleaf + 50]) << 0x10 | uint(c2da_mem[pleaf + 51]) << 0x18)
        c = int(uint(c2da_mem[pleaf + 56]) | uint(c2da_mem[pleaf + 57]) << 0x8 | uint(c2da_mem[pleaf + 58]) << 0x10 | uint(c2da_mem[pleaf + 59]) << 0x18)
        if (c != 0) {
            while (true) {
                let c2da_fresh12 : int = int(uint(c2da_mem[mark]) | uint(c2da_mem[mark + 1]) << 0x8 | uint(c2da_mem[mark + 2]) << 0x10 | uint(c2da_mem[mark + 3]) << 0x18)
                let c2da_fresh13 : uint = uint(r_framecount)
                c2da_mem[c2da_fresh12] = uint8(c2da_fresh13)
                c2da_mem[c2da_fresh12 + 1] = uint8(c2da_fresh13 >> 0x8)
                c2da_mem[c2da_fresh12 + 2] = uint8(c2da_fresh13 >> 0x10)
                c2da_mem[c2da_fresh12 + 3] = uint8(c2da_fresh13 >> 0x18)
                mark += 8
                c--
                if (c == 0) {
                    break
                }
            }
        }
        if (int(uint(c2da_mem[pleaf + 40]) | uint(c2da_mem[pleaf + 41]) << 0x8 | uint(c2da_mem[pleaf + 42]) << 0x10 | uint(c2da_mem[pleaf + 43]) << 0x18) != 0) {
            R_StoreEfrags(pleaf + 40)
        }
        let c2da_fresh14 : uint = uint(r_currentkey)
        c2da_mem[pleaf + 60] = uint8(c2da_fresh14)
        c2da_mem[pleaf + 61] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[pleaf + 62] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[pleaf + 63] = uint8(c2da_fresh14 >> 0x18)
        r_currentkey = r_currentkey + 1
    } else {
        plane = int(uint(c2da_mem[node + 32]) | uint(c2da_mem[node + 33]) << 0x8 | uint(c2da_mem[node + 34]) << 0x10 | uint(c2da_mem[node + 35]) << 0x18)
        c2da_fresh15 = int(c2da_mem[plane + 16])
        if (c2da_fresh15 == 0) {
            dot = double(uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane + 12]) | uint(c2da_mem[plane + 13]) << 0x8 | uint(c2da_mem[plane + 14]) << 0x10 | uint(c2da_mem[plane + 15]) << 0x18))
        } elif (c2da_fresh15 == 1) {
            dot = double(uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane + 12]) | uint(c2da_mem[plane + 13]) << 0x8 | uint(c2da_mem[plane + 14]) << 0x10 | uint(c2da_mem[plane + 15]) << 0x18))
        } elif (c2da_fresh15 == 2) {
            dot = double(uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane + 12]) | uint(c2da_mem[plane + 13]) << 0x8 | uint(c2da_mem[plane + 14]) << 0x10 | uint(c2da_mem[plane + 15]) << 0x18))
        } else {
            dot = double(uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 0 * 4]) | uint(c2da_mem[plane + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 1 * 4]) | uint(c2da_mem[plane + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[plane + 2 * 4]) | uint(c2da_mem[plane + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane + 12]) | uint(c2da_mem[plane + 13]) << 0x8 | uint(c2da_mem[plane + 14]) << 0x10 | uint(c2da_mem[plane + 15]) << 0x18))
        }
        if (dot >= 0.0lf) {
            side = 0
        } else {
            side = 1
        }
        R_RecursiveWorldNode(int(uint(c2da_mem[node + 40 + side * 8]) | uint(c2da_mem[node + 40 + side * 8 + 1]) << 0x8 | uint(c2da_mem[node + 40 + side * 8 + 2]) << 0x10 | uint(c2da_mem[node + 40 + side * 8 + 3]) << 0x18), clipflags)
        c = int(uint16(uint(c2da_mem[node + 58]) | uint(c2da_mem[node + 59]) << 0x8))
        if (c != 0) {
            let c2da_fresh16 : int = int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) + 240
            surf = int(uint(c2da_mem[c2da_fresh16]) | uint(c2da_mem[c2da_fresh16 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh16 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh16 + 3]) << 0x18) + int(uint16(uint(c2da_mem[node + 56]) | uint(c2da_mem[node + 57]) << 0x8)) * 104
            if (dot < -0.01lf) {
                while (true) {
                    if ((int(uint(c2da_mem[surf + 24]) | uint(c2da_mem[surf + 25]) << 0x8 | uint(c2da_mem[surf + 26]) << 0x10 | uint(c2da_mem[surf + 27]) << 0x18) & 2) != 0 && int(uint(c2da_mem[surf]) | uint(c2da_mem[surf + 1]) << 0x8 | uint(c2da_mem[surf + 2]) << 0x10 | uint(c2da_mem[surf + 3]) << 0x18) == r_framecount) {
                        if (uint(r_drawpolys) != 0u) {
                            if (uint(r_worldpolysbacktofront) != 0u) {
                                if (numbtofpolys < 5000) {
                                    let c2da_fresh17 : uint = uint(clipflags)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16] = uint8(c2da_fresh17)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 1] = uint8(c2da_fresh17 >> 0x8)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 2] = uint8(c2da_fresh17 >> 0x10)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 3] = uint8(c2da_fresh17 >> 0x18)
                                    let c2da_fresh18 : uint = uint(surf)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 8] = uint8(c2da_fresh18)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 9] = uint8(c2da_fresh18 >> 0x8)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 10] = uint8(c2da_fresh18 >> 0x10)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 11] = uint8(c2da_fresh18 >> 0x18)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 12] = 0u8
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 13] = 0u8
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 14] = 0u8
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 15] = 0u8
                                    numbtofpolys = numbtofpolys + 1
                                }
                            } else {
                                R_RenderPoly(surf, clipflags)
                            }
                        } else {
                            R_RenderFace(surf, clipflags)
                        }
                    }
                    surf += 104
                    c--
                    if (c == 0) {
                        break
                    }
                }
            } elif (dot > 0.01lf) {
                while (true) {
                    if ((int(uint(c2da_mem[surf + 24]) | uint(c2da_mem[surf + 25]) << 0x8 | uint(c2da_mem[surf + 26]) << 0x10 | uint(c2da_mem[surf + 27]) << 0x18) & 2) == 0 && int(uint(c2da_mem[surf]) | uint(c2da_mem[surf + 1]) << 0x8 | uint(c2da_mem[surf + 2]) << 0x10 | uint(c2da_mem[surf + 3]) << 0x18) == r_framecount) {
                        if (uint(r_drawpolys) != 0u) {
                            if (uint(r_worldpolysbacktofront) != 0u) {
                                if (numbtofpolys < 5000) {
                                    let c2da_fresh19 : uint = uint(clipflags)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16] = uint8(c2da_fresh19)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 1] = uint8(c2da_fresh19 >> 0x8)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 2] = uint8(c2da_fresh19 >> 0x10)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 3] = uint8(c2da_fresh19 >> 0x18)
                                    let c2da_fresh20 : uint = uint(surf)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 8] = uint8(c2da_fresh20)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 9] = uint8(c2da_fresh20 >> 0x8)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 10] = uint8(c2da_fresh20 >> 0x10)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 11] = uint8(c2da_fresh20 >> 0x18)
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 12] = 0u8
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 13] = 0u8
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 14] = 0u8
                                    c2da_mem[pbtofpolys + int(numbtofpolys) * 16 + 15] = 0u8
                                    numbtofpolys = numbtofpolys + 1
                                }
                            } else {
                                R_RenderPoly(surf, clipflags)
                            }
                        } else {
                            R_RenderFace(surf, clipflags)
                        }
                    }
                    surf += 104
                    c--
                    if (c == 0) {
                        break
                    }
                }
            }
            r_currentkey = r_currentkey + 1
        }
        let c2da_fresh21 : int = node + 40 + (side == 0 ? 1 : 0) * 8
        R_RecursiveWorldNode(int(uint(c2da_mem[c2da_fresh21]) | uint(c2da_mem[c2da_fresh21 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh21 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh21 + 3]) << 0x18), clipflags)
    }
    return
}
var r_entorigin : vec3_t = default<vec3_t>

var insubmodel : uint = default<uint>

var r_worldmodelorg : vec3_t = default<vec3_t>

[export, sideeffects]
def R_DrawSubmodelPolygons(var pmodel_0 : int; var clipflags_0 : int) {
    var i_1 : int
    var dot_0 : float
    var psurf : int
    var numsurfaces : int
    var pplane : int
    psurf = int(uint(c2da_mem[pmodel_0 + 240]) | uint(c2da_mem[pmodel_0 + 241]) << 0x8 | uint(c2da_mem[pmodel_0 + 242]) << 0x10 | uint(c2da_mem[pmodel_0 + 243]) << 0x18) + int(uint(c2da_mem[pmodel_0 + 112]) | uint(c2da_mem[pmodel_0 + 113]) << 0x8 | uint(c2da_mem[pmodel_0 + 114]) << 0x10 | uint(c2da_mem[pmodel_0 + 115]) << 0x18) * 104
    numsurfaces = int(uint(c2da_mem[pmodel_0 + 116]) | uint(c2da_mem[pmodel_0 + 117]) << 0x8 | uint(c2da_mem[pmodel_0 + 118]) << 0x10 | uint(c2da_mem[pmodel_0 + 119]) << 0x18)
    i_1 = 0
    while (i_1 < numsurfaces) {
        pplane = int(uint(c2da_mem[psurf + 16]) | uint(c2da_mem[psurf + 17]) << 0x8 | uint(c2da_mem[psurf + 18]) << 0x10 | uint(c2da_mem[psurf + 19]) << 0x18)
        dot_0 = uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane + 0 * 4]) | uint(c2da_mem[pplane + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane + 1 * 4]) | uint(c2da_mem[pplane + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane + 2 * 4]) | uint(c2da_mem[pplane + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[pplane + 12]) | uint(c2da_mem[pplane + 13]) << 0x8 | uint(c2da_mem[pplane + 14]) << 0x10 | uint(c2da_mem[pplane + 15]) << 0x18)
        if ((int(uint(c2da_mem[psurf + 24]) | uint(c2da_mem[psurf + 25]) << 0x8 | uint(c2da_mem[psurf + 26]) << 0x10 | uint(c2da_mem[psurf + 27]) << 0x18) & 2) != 0 && double(dot_0) < -0.01lf || (int(uint(c2da_mem[psurf + 24]) | uint(c2da_mem[psurf + 25]) << 0x8 | uint(c2da_mem[psurf + 26]) << 0x10 | uint(c2da_mem[psurf + 27]) << 0x18) & 2) == 0 && double(dot_0) > 0.01lf) {
            let c2da_fresh22 : int = int(uint(c2da_mem[currententity + 192]) | uint(c2da_mem[currententity + 193]) << 0x8 | uint(c2da_mem[currententity + 194]) << 0x10 | uint(c2da_mem[currententity + 195]) << 0x18) + 60
            r_currentkey = int(uint(c2da_mem[c2da_fresh22]) | uint(c2da_mem[c2da_fresh22 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh22 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh22 + 3]) << 0x18)
            R_RenderFace(psurf, clipflags_0)
        }
        i_1++
        psurf += 104
    }
    return
}
[export, sideeffects]
def R_DrawSolidClippedSubmodelPolygons(var pmodel_1 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_DrawSolidClippedSubmodelPolygons_c2da_frame(pmodel_1, c2da_lin_enter(30000))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_RecursiveClipBPoly(var pedges_0 : int; var pnode : int; var psurf_1 : int) {
    var psideedges : int[2]
    var pnextedge : int
    var ptedge : int
    var side_0 : int
    var lastside : int
    var dist : float
    var frac : float
    var lastdist : float
    var splitplane : int
    var tplane : mplane_s
    var pvert : int
    var plastvert : int
    var ptvert : int
    var pn : int
    psideedges[1] = 0
    psideedges[0] = int(psideedges[1])  // nolint:PERF020
    makeclippededge = 0u
    splitplane = int(uint(c2da_mem[pnode + 32]) | uint(c2da_mem[pnode + 33]) << 0x8 | uint(c2da_mem[pnode + 34]) << 0x10 | uint(c2da_mem[pnode + 35]) << 0x18)
    tplane.dist = uint_bits_to_float(uint(c2da_mem[splitplane + 12]) | uint(c2da_mem[splitplane + 13]) << 0x8 | uint(c2da_mem[splitplane + 14]) << 0x10 | uint(c2da_mem[splitplane + 15]) << 0x18) - (r_entorigin[0] * uint_bits_to_float(uint(c2da_mem[splitplane + 0 * 4]) | uint(c2da_mem[splitplane + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 0 * 4 + 3]) << 0x18) + r_entorigin[1] * uint_bits_to_float(uint(c2da_mem[splitplane + 1 * 4]) | uint(c2da_mem[splitplane + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 1 * 4 + 3]) << 0x18) + r_entorigin[2] * uint_bits_to_float(uint(c2da_mem[splitplane + 2 * 4]) | uint(c2da_mem[splitplane + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 2 * 4 + 3]) << 0x18))
    tplane.normal[0] = uint_bits_to_float(uint(c2da_mem[391392 + 0 * 12 + 0 * 4]) | uint(c2da_mem[391392 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 0 * 12 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[splitplane + 0 * 4]) | uint(c2da_mem[splitplane + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391392 + 0 * 12 + 1 * 4]) | uint(c2da_mem[391392 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 0 * 12 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[splitplane + 1 * 4]) | uint(c2da_mem[splitplane + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391392 + 0 * 12 + 2 * 4]) | uint(c2da_mem[391392 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 0 * 12 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[splitplane + 2 * 4]) | uint(c2da_mem[splitplane + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 2 * 4 + 3]) << 0x18)
    tplane.normal[1] = uint_bits_to_float(uint(c2da_mem[391392 + 1 * 12 + 0 * 4]) | uint(c2da_mem[391392 + 1 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 1 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 1 * 12 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[splitplane + 0 * 4]) | uint(c2da_mem[splitplane + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391392 + 1 * 12 + 1 * 4]) | uint(c2da_mem[391392 + 1 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 1 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 1 * 12 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[splitplane + 1 * 4]) | uint(c2da_mem[splitplane + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391392 + 1 * 12 + 2 * 4]) | uint(c2da_mem[391392 + 1 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 1 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 1 * 12 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[splitplane + 2 * 4]) | uint(c2da_mem[splitplane + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 2 * 4 + 3]) << 0x18)
    tplane.normal[2] = uint_bits_to_float(uint(c2da_mem[391392 + 2 * 12 + 0 * 4]) | uint(c2da_mem[391392 + 2 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 2 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 2 * 12 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[splitplane + 0 * 4]) | uint(c2da_mem[splitplane + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391392 + 2 * 12 + 1 * 4]) | uint(c2da_mem[391392 + 2 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 2 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 2 * 12 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[splitplane + 1 * 4]) | uint(c2da_mem[splitplane + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391392 + 2 * 12 + 2 * 4]) | uint(c2da_mem[391392 + 2 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 2 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 2 * 12 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[splitplane + 2 * 4]) | uint(c2da_mem[splitplane + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[splitplane + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[splitplane + 2 * 4 + 3]) << 0x18)
    while (pedges_0 != 0) {
        pnextedge = int(uint(c2da_mem[pedges_0 + 16]) | uint(c2da_mem[pedges_0 + 17]) << 0x8 | uint(c2da_mem[pedges_0 + 18]) << 0x10 | uint(c2da_mem[pedges_0 + 19]) << 0x18)
        plastvert = int(uint(c2da_mem[pedges_0 + 0 * 8]) | uint(c2da_mem[pedges_0 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[pedges_0 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[pedges_0 + 0 * 8 + 3]) << 0x18)
        lastdist = uint_bits_to_float(uint(c2da_mem[plastvert + 0 * 4]) | uint(c2da_mem[plastvert + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plastvert + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plastvert + 0 * 4 + 3]) << 0x18) * tplane.normal[0] + uint_bits_to_float(uint(c2da_mem[plastvert + 1 * 4]) | uint(c2da_mem[plastvert + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plastvert + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plastvert + 1 * 4 + 3]) << 0x18) * tplane.normal[1] + uint_bits_to_float(uint(c2da_mem[plastvert + 2 * 4]) | uint(c2da_mem[plastvert + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plastvert + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plastvert + 2 * 4 + 3]) << 0x18) * tplane.normal[2] - tplane.dist
        if (lastdist > 0.0) {
            lastside = 0
        } else {
            lastside = 1
        }
        pvert = int(uint(c2da_mem[pedges_0 + 1 * 8]) | uint(c2da_mem[pedges_0 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[pedges_0 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[pedges_0 + 1 * 8 + 3]) << 0x18)
        dist = uint_bits_to_float(uint(c2da_mem[pvert + 0 * 4]) | uint(c2da_mem[pvert + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pvert + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pvert + 0 * 4 + 3]) << 0x18) * tplane.normal[0] + uint_bits_to_float(uint(c2da_mem[pvert + 1 * 4]) | uint(c2da_mem[pvert + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pvert + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pvert + 1 * 4 + 3]) << 0x18) * tplane.normal[1] + uint_bits_to_float(uint(c2da_mem[pvert + 2 * 4]) | uint(c2da_mem[pvert + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pvert + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pvert + 2 * 4 + 3]) << 0x18) * tplane.normal[2] - tplane.dist
        if (dist > 0.0) {
            side_0 = 0
        } else {
            side_0 = 1
        }
        if (side_0 != lastside) {
            if (numbverts >= 500) {
                return
            }
            frac = lastdist / (lastdist - dist)
            let c2da_postinc : int = numbverts
            numbverts++
            ptvert = pbverts + c2da_postinc * 12
            let c2da_fresh35 : float = uint_bits_to_float(uint(c2da_mem[plastvert + 0 * 4]) | uint(c2da_mem[plastvert + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plastvert + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plastvert + 0 * 4 + 3]) << 0x18) + frac * (uint_bits_to_float(uint(c2da_mem[pvert + 0 * 4]) | uint(c2da_mem[pvert + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pvert + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pvert + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plastvert + 0 * 4]) | uint(c2da_mem[plastvert + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plastvert + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plastvert + 0 * 4 + 3]) << 0x18))
            let c2da_fresh36 : uint = float_bits_to_uint(c2da_fresh35)
            c2da_mem[ptvert + 0 * 4] = uint8(c2da_fresh36)
            c2da_mem[ptvert + 0 * 4 + 1] = uint8(c2da_fresh36 >> 0x8)
            c2da_mem[ptvert + 0 * 4 + 2] = uint8(c2da_fresh36 >> 0x10)
            c2da_mem[ptvert + 0 * 4 + 3] = uint8(c2da_fresh36 >> 0x18)
            let c2da_fresh37 : float = uint_bits_to_float(uint(c2da_mem[plastvert + 1 * 4]) | uint(c2da_mem[plastvert + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plastvert + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plastvert + 1 * 4 + 3]) << 0x18) + frac * (uint_bits_to_float(uint(c2da_mem[pvert + 1 * 4]) | uint(c2da_mem[pvert + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pvert + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pvert + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plastvert + 1 * 4]) | uint(c2da_mem[plastvert + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plastvert + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plastvert + 1 * 4 + 3]) << 0x18))
            let c2da_fresh38 : uint = float_bits_to_uint(c2da_fresh37)
            c2da_mem[ptvert + 1 * 4] = uint8(c2da_fresh38)
            c2da_mem[ptvert + 1 * 4 + 1] = uint8(c2da_fresh38 >> 0x8)
            c2da_mem[ptvert + 1 * 4 + 2] = uint8(c2da_fresh38 >> 0x10)
            c2da_mem[ptvert + 1 * 4 + 3] = uint8(c2da_fresh38 >> 0x18)
            let c2da_fresh39 : float = uint_bits_to_float(uint(c2da_mem[plastvert + 2 * 4]) | uint(c2da_mem[plastvert + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plastvert + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plastvert + 2 * 4 + 3]) << 0x18) + frac * (uint_bits_to_float(uint(c2da_mem[pvert + 2 * 4]) | uint(c2da_mem[pvert + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pvert + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pvert + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plastvert + 2 * 4]) | uint(c2da_mem[plastvert + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plastvert + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plastvert + 2 * 4 + 3]) << 0x18))
            let c2da_fresh40 : uint = float_bits_to_uint(c2da_fresh39)
            c2da_mem[ptvert + 2 * 4] = uint8(c2da_fresh40)
            c2da_mem[ptvert + 2 * 4 + 1] = uint8(c2da_fresh40 >> 0x8)
            c2da_mem[ptvert + 2 * 4 + 2] = uint8(c2da_fresh40 >> 0x10)
            c2da_mem[ptvert + 2 * 4 + 3] = uint8(c2da_fresh40 >> 0x18)
            if (numbedges >= 1000 - 1) {
                Con_Printf(732643, [])
                return
            }
            ptedge = pbedges + numbedges * 24
            let c2da_fresh41 : int = psideedges[lastside]
            let c2da_fresh42 : uint = uint(c2da_fresh41)
            c2da_mem[ptedge + 16] = uint8(c2da_fresh42)
            c2da_mem[ptedge + 17] = uint8(c2da_fresh42 >> 0x8)
            c2da_mem[ptedge + 18] = uint8(c2da_fresh42 >> 0x10)
            c2da_mem[ptedge + 19] = uint8(c2da_fresh42 >> 0x18)
            c2da_mem[ptedge + 20] = 0u8
            c2da_mem[ptedge + 21] = 0u8
            c2da_mem[ptedge + 22] = 0u8
            c2da_mem[ptedge + 23] = 0u8
            psideedges[lastside] = ptedge
            let c2da_fresh43 : uint = uint(plastvert)
            c2da_mem[ptedge + 0 * 8] = uint8(c2da_fresh43)
            c2da_mem[ptedge + 0 * 8 + 1] = uint8(c2da_fresh43 >> 0x8)
            c2da_mem[ptedge + 0 * 8 + 2] = uint8(c2da_fresh43 >> 0x10)
            c2da_mem[ptedge + 0 * 8 + 3] = uint8(c2da_fresh43 >> 0x18)
            c2da_mem[ptedge + 0 * 8 + 4] = 0u8
            c2da_mem[ptedge + 0 * 8 + 5] = 0u8
            c2da_mem[ptedge + 0 * 8 + 6] = 0u8
            c2da_mem[ptedge + 0 * 8 + 7] = 0u8
            let c2da_fresh44 : uint = uint(ptvert)
            c2da_mem[ptedge + 1 * 8] = uint8(c2da_fresh44)
            c2da_mem[ptedge + 1 * 8 + 1] = uint8(c2da_fresh44 >> 0x8)
            c2da_mem[ptedge + 1 * 8 + 2] = uint8(c2da_fresh44 >> 0x10)
            c2da_mem[ptedge + 1 * 8 + 3] = uint8(c2da_fresh44 >> 0x18)
            c2da_mem[ptedge + 1 * 8 + 4] = 0u8
            c2da_mem[ptedge + 1 * 8 + 5] = 0u8
            c2da_mem[ptedge + 1 * 8 + 6] = 0u8
            c2da_mem[ptedge + 1 * 8 + 7] = 0u8
            ptedge = pbedges + (numbedges + 1) * 24
            let c2da_fresh45 : int = psideedges[side_0]
            let c2da_fresh46 : uint = uint(c2da_fresh45)
            c2da_mem[ptedge + 16] = uint8(c2da_fresh46)
            c2da_mem[ptedge + 17] = uint8(c2da_fresh46 >> 0x8)
            c2da_mem[ptedge + 18] = uint8(c2da_fresh46 >> 0x10)
            c2da_mem[ptedge + 19] = uint8(c2da_fresh46 >> 0x18)
            c2da_mem[ptedge + 20] = 0u8
            c2da_mem[ptedge + 21] = 0u8
            c2da_mem[ptedge + 22] = 0u8
            c2da_mem[ptedge + 23] = 0u8
            psideedges[side_0] = ptedge
            let c2da_fresh47 : uint = uint(ptvert)
            c2da_mem[ptedge + 0 * 8] = uint8(c2da_fresh47)
            c2da_mem[ptedge + 0 * 8 + 1] = uint8(c2da_fresh47 >> 0x8)
            c2da_mem[ptedge + 0 * 8 + 2] = uint8(c2da_fresh47 >> 0x10)
            c2da_mem[ptedge + 0 * 8 + 3] = uint8(c2da_fresh47 >> 0x18)
            c2da_mem[ptedge + 0 * 8 + 4] = 0u8
            c2da_mem[ptedge + 0 * 8 + 5] = 0u8
            c2da_mem[ptedge + 0 * 8 + 6] = 0u8
            c2da_mem[ptedge + 0 * 8 + 7] = 0u8
            let c2da_fresh48 : uint = uint(pvert)
            c2da_mem[ptedge + 1 * 8] = uint8(c2da_fresh48)
            c2da_mem[ptedge + 1 * 8 + 1] = uint8(c2da_fresh48 >> 0x8)
            c2da_mem[ptedge + 1 * 8 + 2] = uint8(c2da_fresh48 >> 0x10)
            c2da_mem[ptedge + 1 * 8 + 3] = uint8(c2da_fresh48 >> 0x18)
            c2da_mem[ptedge + 1 * 8 + 4] = 0u8
            c2da_mem[ptedge + 1 * 8 + 5] = 0u8
            c2da_mem[ptedge + 1 * 8 + 6] = 0u8
            c2da_mem[ptedge + 1 * 8 + 7] = 0u8
            numbedges += 2
            if (side_0 == 0) {
                pfrontenter = ptvert
                makeclippededge = 1u
            } else {
                pfrontexit = ptvert
                makeclippededge = 1u
            }
        } else {
            let c2da_fresh49 : int = psideedges[side_0]
            let c2da_fresh50 : uint = uint(c2da_fresh49)
            c2da_mem[pedges_0 + 16] = uint8(c2da_fresh50)
            c2da_mem[pedges_0 + 17] = uint8(c2da_fresh50 >> 0x8)
            c2da_mem[pedges_0 + 18] = uint8(c2da_fresh50 >> 0x10)
            c2da_mem[pedges_0 + 19] = uint8(c2da_fresh50 >> 0x18)
            c2da_mem[pedges_0 + 20] = 0u8
            c2da_mem[pedges_0 + 21] = 0u8
            c2da_mem[pedges_0 + 22] = 0u8
            c2da_mem[pedges_0 + 23] = 0u8
            psideedges[side_0] = int(pedges_0)  // nolint:PERF020
        }
        pedges_0 = pnextedge
    }
    if (makeclippededge != 0u) {
        if (numbedges >= 1000 - 2) {
            Con_Printf(732643, [])
            return
        }
        ptedge = pbedges + numbedges * 24
        let c2da_fresh51 : int = psideedges[0]
        let c2da_fresh52 : uint = uint(c2da_fresh51)
        c2da_mem[ptedge + 16] = uint8(c2da_fresh52)
        c2da_mem[ptedge + 17] = uint8(c2da_fresh52 >> 0x8)
        c2da_mem[ptedge + 18] = uint8(c2da_fresh52 >> 0x10)
        c2da_mem[ptedge + 19] = uint8(c2da_fresh52 >> 0x18)
        c2da_mem[ptedge + 20] = 0u8
        c2da_mem[ptedge + 21] = 0u8
        c2da_mem[ptedge + 22] = 0u8
        c2da_mem[ptedge + 23] = 0u8
        psideedges[0] = ptedge
        let c2da_fresh53 : uint = uint(pfrontexit)
        c2da_mem[ptedge + 0 * 8] = uint8(c2da_fresh53)
        c2da_mem[ptedge + 0 * 8 + 1] = uint8(c2da_fresh53 >> 0x8)
        c2da_mem[ptedge + 0 * 8 + 2] = uint8(c2da_fresh53 >> 0x10)
        c2da_mem[ptedge + 0 * 8 + 3] = uint8(c2da_fresh53 >> 0x18)
        c2da_mem[ptedge + 0 * 8 + 4] = 0u8
        c2da_mem[ptedge + 0 * 8 + 5] = 0u8
        c2da_mem[ptedge + 0 * 8 + 6] = 0u8
        c2da_mem[ptedge + 0 * 8 + 7] = 0u8
        let c2da_fresh54 : uint = uint(pfrontenter)
        c2da_mem[ptedge + 1 * 8] = uint8(c2da_fresh54)
        c2da_mem[ptedge + 1 * 8 + 1] = uint8(c2da_fresh54 >> 0x8)
        c2da_mem[ptedge + 1 * 8 + 2] = uint8(c2da_fresh54 >> 0x10)
        c2da_mem[ptedge + 1 * 8 + 3] = uint8(c2da_fresh54 >> 0x18)
        c2da_mem[ptedge + 1 * 8 + 4] = 0u8
        c2da_mem[ptedge + 1 * 8 + 5] = 0u8
        c2da_mem[ptedge + 1 * 8 + 6] = 0u8
        c2da_mem[ptedge + 1 * 8 + 7] = 0u8
        ptedge = pbedges + (numbedges + 1) * 24
        let c2da_fresh55 : int = psideedges[1]
        let c2da_fresh56 : uint = uint(c2da_fresh55)
        c2da_mem[ptedge + 16] = uint8(c2da_fresh56)
        c2da_mem[ptedge + 17] = uint8(c2da_fresh56 >> 0x8)
        c2da_mem[ptedge + 18] = uint8(c2da_fresh56 >> 0x10)
        c2da_mem[ptedge + 19] = uint8(c2da_fresh56 >> 0x18)
        c2da_mem[ptedge + 20] = 0u8
        c2da_mem[ptedge + 21] = 0u8
        c2da_mem[ptedge + 22] = 0u8
        c2da_mem[ptedge + 23] = 0u8
        psideedges[1] = ptedge
        let c2da_fresh57 : uint = uint(pfrontenter)
        c2da_mem[ptedge + 0 * 8] = uint8(c2da_fresh57)
        c2da_mem[ptedge + 0 * 8 + 1] = uint8(c2da_fresh57 >> 0x8)
        c2da_mem[ptedge + 0 * 8 + 2] = uint8(c2da_fresh57 >> 0x10)
        c2da_mem[ptedge + 0 * 8 + 3] = uint8(c2da_fresh57 >> 0x18)
        c2da_mem[ptedge + 0 * 8 + 4] = 0u8
        c2da_mem[ptedge + 0 * 8 + 5] = 0u8
        c2da_mem[ptedge + 0 * 8 + 6] = 0u8
        c2da_mem[ptedge + 0 * 8 + 7] = 0u8
        let c2da_fresh58 : uint = uint(pfrontexit)
        c2da_mem[ptedge + 1 * 8] = uint8(c2da_fresh58)
        c2da_mem[ptedge + 1 * 8 + 1] = uint8(c2da_fresh58 >> 0x8)
        c2da_mem[ptedge + 1 * 8 + 2] = uint8(c2da_fresh58 >> 0x10)
        c2da_mem[ptedge + 1 * 8 + 3] = uint8(c2da_fresh58 >> 0x18)
        c2da_mem[ptedge + 1 * 8 + 4] = 0u8
        c2da_mem[ptedge + 1 * 8 + 5] = 0u8
        c2da_mem[ptedge + 1 * 8 + 6] = 0u8
        c2da_mem[ptedge + 1 * 8 + 7] = 0u8
        numbedges += 2
    }
    for (i_3 in range(0, 2)) {
        if (psideedges[i_3] != 0) {
            pn = int(uint(c2da_mem[pnode + 40 + i_3 * 8]) | uint(c2da_mem[pnode + 40 + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[pnode + 40 + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[pnode + 40 + i_3 * 8 + 3]) << 0x18)
            if (int(uint(c2da_mem[pn + 4]) | uint(c2da_mem[pn + 5]) << 0x8 | uint(c2da_mem[pn + 6]) << 0x10 | uint(c2da_mem[pn + 7]) << 0x18) == r_visframecount) {
                if (int(uint(c2da_mem[pn]) | uint(c2da_mem[pn + 1]) << 0x8 | uint(c2da_mem[pn + 2]) << 0x10 | uint(c2da_mem[pn + 3]) << 0x18) < 0) {
                    if (int(uint(c2da_mem[pn]) | uint(c2da_mem[pn + 1]) << 0x8 | uint(c2da_mem[pn + 2]) << 0x10 | uint(c2da_mem[pn + 3]) << 0x18) != -2) {
                        r_currentbkey = int(uint(c2da_mem[pn + 60]) | uint(c2da_mem[pn + 61]) << 0x8 | uint(c2da_mem[pn + 62]) << 0x10 | uint(c2da_mem[pn + 63]) << 0x18)
                        R_RenderBmodelFace(psideedges[i_3], psurf_1)
                    }
                } else {
                    R_RecursiveClipBPoly(psideedges[i_3], int(uint(c2da_mem[pnode + 40 + i_3 * 8]) | uint(c2da_mem[pnode + 40 + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[pnode + 40 + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[pnode + 40 + i_3 * 8 + 3]) << 0x18), psurf_1)
                }
            }
        }
    }
    return
}
var r_currentbkey : int = default<int>

var private numbedges : int = default<int>

var private pfrontexit : int = default<int>

var private pfrontenter : int = default<int>

var private pbedges : int = default<int>

var private makeclippededge : uint = default<uint>

var private numbverts : int = default<int>

var private pbverts : int = default<int>

[export, sideeffects]
def R_RotateBmodel() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_RotateBmodel_c2da_frame(c2da_lin_enter(144))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_EntityRotate(var vec : int) {
    var tvec : vec3_t
    tvec[0] = uint_bits_to_float(uint(c2da_mem[vec + 0 * 4]) | uint(c2da_mem[vec + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[vec + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[vec + 0 * 4 + 3]) << 0x18)
    tvec[1] = uint_bits_to_float(uint(c2da_mem[vec + 1 * 4]) | uint(c2da_mem[vec + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[vec + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[vec + 1 * 4 + 3]) << 0x18)
    tvec[2] = uint_bits_to_float(uint(c2da_mem[vec + 2 * 4]) | uint(c2da_mem[vec + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[vec + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[vec + 2 * 4 + 3]) << 0x18)
    let c2da_fresh104 : float = uint_bits_to_float(uint(c2da_mem[391392 + 0 * 12 + 0 * 4]) | uint(c2da_mem[391392 + 0 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 0 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 0 * 12 + 0 * 4 + 3]) << 0x18) * tvec[0] + uint_bits_to_float(uint(c2da_mem[391392 + 0 * 12 + 1 * 4]) | uint(c2da_mem[391392 + 0 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 0 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 0 * 12 + 1 * 4 + 3]) << 0x18) * tvec[1] + uint_bits_to_float(uint(c2da_mem[391392 + 0 * 12 + 2 * 4]) | uint(c2da_mem[391392 + 0 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 0 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 0 * 12 + 2 * 4 + 3]) << 0x18) * tvec[2]
    let c2da_fresh105 : uint = float_bits_to_uint(c2da_fresh104)
    c2da_mem[vec + 0 * 4] = uint8(c2da_fresh105)
    c2da_mem[vec + 0 * 4 + 1] = uint8(c2da_fresh105 >> 0x8)
    c2da_mem[vec + 0 * 4 + 2] = uint8(c2da_fresh105 >> 0x10)
    c2da_mem[vec + 0 * 4 + 3] = uint8(c2da_fresh105 >> 0x18)
    let c2da_fresh106 : float = uint_bits_to_float(uint(c2da_mem[391392 + 1 * 12 + 0 * 4]) | uint(c2da_mem[391392 + 1 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 1 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 1 * 12 + 0 * 4 + 3]) << 0x18) * tvec[0] + uint_bits_to_float(uint(c2da_mem[391392 + 1 * 12 + 1 * 4]) | uint(c2da_mem[391392 + 1 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 1 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 1 * 12 + 1 * 4 + 3]) << 0x18) * tvec[1] + uint_bits_to_float(uint(c2da_mem[391392 + 1 * 12 + 2 * 4]) | uint(c2da_mem[391392 + 1 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 1 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 1 * 12 + 2 * 4 + 3]) << 0x18) * tvec[2]
    let c2da_fresh107 : uint = float_bits_to_uint(c2da_fresh106)
    c2da_mem[vec + 1 * 4] = uint8(c2da_fresh107)
    c2da_mem[vec + 1 * 4 + 1] = uint8(c2da_fresh107 >> 0x8)
    c2da_mem[vec + 1 * 4 + 2] = uint8(c2da_fresh107 >> 0x10)
    c2da_mem[vec + 1 * 4 + 3] = uint8(c2da_fresh107 >> 0x18)
    let c2da_fresh108 : float = uint_bits_to_float(uint(c2da_mem[391392 + 2 * 12 + 0 * 4]) | uint(c2da_mem[391392 + 2 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 2 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 2 * 12 + 0 * 4 + 3]) << 0x18) * tvec[0] + uint_bits_to_float(uint(c2da_mem[391392 + 2 * 12 + 1 * 4]) | uint(c2da_mem[391392 + 2 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 2 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 2 * 12 + 1 * 4 + 3]) << 0x18) * tvec[1] + uint_bits_to_float(uint(c2da_mem[391392 + 2 * 12 + 2 * 4]) | uint(c2da_mem[391392 + 2 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391392 + 2 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391392 + 2 * 12 + 2 * 4 + 3]) << 0x18) * tvec[2]
    let c2da_fresh109 : uint = float_bits_to_uint(c2da_fresh108)
    c2da_mem[vec + 2 * 4] = uint8(c2da_fresh109)
    c2da_mem[vec + 2 * 4 + 1] = uint8(c2da_fresh109 >> 0x8)
    c2da_mem[vec + 2 * 4 + 2] = uint8(c2da_fresh109 >> 0x10)
    c2da_mem[vec + 2 * 4 + 3] = uint8(c2da_fresh109 >> 0x18)
    return
}
[sideeffects]
def private R_RenderWorld_c2da_frame(c2da_fp : int) {
    var i : int
    var clmodel : int
    pbtofpolys = c2da_fp
    currententity = 10048 + 0 * 200
    let c2da_fresh0 : float = uint_bits_to_float(uint(c2da_mem[244112 + 0 * 4]) | uint(c2da_mem[244112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh1 : uint = float_bits_to_uint(c2da_fresh0)
    c2da_mem[204240 + 0 * 4] = uint8(c2da_fresh1)
    c2da_mem[204240 + 0 * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[204240 + 0 * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[204240 + 0 * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : float = uint_bits_to_float(uint(c2da_mem[244112 + 1 * 4]) | uint(c2da_mem[244112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh3 : uint = float_bits_to_uint(c2da_fresh2)
    c2da_mem[204240 + 1 * 4] = uint8(c2da_fresh3)
    c2da_mem[204240 + 1 * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[204240 + 1 * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[204240 + 1 * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : float = uint_bits_to_float(uint(c2da_mem[244112 + 2 * 4]) | uint(c2da_mem[244112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh5 : uint = float_bits_to_uint(c2da_fresh4)
    c2da_mem[204240 + 2 * 4] = uint8(c2da_fresh5)
    c2da_mem[204240 + 2 * 4 + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[204240 + 2 * 4 + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[204240 + 2 * 4 + 3] = uint8(c2da_fresh5 >> 0x18)
    clmodel = int(uint(c2da_mem[currententity + 136]) | uint(c2da_mem[currententity + 137]) << 0x8 | uint(c2da_mem[currententity + 138]) << 0x10 | uint(c2da_mem[currententity + 139]) << 0x18)
    r_pcurrentvertbase = int(uint(c2da_mem[clmodel + 176]) | uint(c2da_mem[clmodel + 177]) << 0x8 | uint(c2da_mem[clmodel + 178]) << 0x10 | uint(c2da_mem[clmodel + 179]) << 0x18)
    R_RecursiveWorldNode(int(uint(c2da_mem[clmodel + 208]) | uint(c2da_mem[clmodel + 209]) << 0x8 | uint(c2da_mem[clmodel + 210]) << 0x10 | uint(c2da_mem[clmodel + 211]) << 0x18), 15)
    if (uint(r_worldpolysbacktofront) != 0u) {
        i = numbtofpolys - 1
        while (i >= 0) {
            R_RenderPoly(int(uint(c2da_mem[c2da_fp + i * 16 + 8]) | uint(c2da_mem[c2da_fp + i * 16 + 9]) << 0x8 | uint(c2da_mem[c2da_fp + i * 16 + 10]) << 0x10 | uint(c2da_mem[c2da_fp + i * 16 + 11]) << 0x18), int(uint(c2da_mem[c2da_fp + i * 16]) | uint(c2da_mem[c2da_fp + i * 16 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + i * 16 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + i * 16 + 3]) << 0x18))
            i--
        }
    }
    return
}
[sideeffects]
def private R_DrawSolidClippedSubmodelPolygons_c2da_frame(var pmodel_1 : int; c2da_fp : int) {
    var i_2 : int
    var j : int
    var lindex : int
    var dot_1 : float
    var psurf_0 : int
    var numsurfaces_0 : int
    var pplane_0 : int
    var pbedge : int
    var pedge : int
    var pedges : int
    psurf_0 = int(uint(c2da_mem[pmodel_1 + 240]) | uint(c2da_mem[pmodel_1 + 241]) << 0x8 | uint(c2da_mem[pmodel_1 + 242]) << 0x10 | uint(c2da_mem[pmodel_1 + 243]) << 0x18) + int(uint(c2da_mem[pmodel_1 + 112]) | uint(c2da_mem[pmodel_1 + 113]) << 0x8 | uint(c2da_mem[pmodel_1 + 114]) << 0x10 | uint(c2da_mem[pmodel_1 + 115]) << 0x18) * 104
    numsurfaces_0 = int(uint(c2da_mem[pmodel_1 + 116]) | uint(c2da_mem[pmodel_1 + 117]) << 0x8 | uint(c2da_mem[pmodel_1 + 118]) << 0x10 | uint(c2da_mem[pmodel_1 + 119]) << 0x18)
    pedges = int(uint(c2da_mem[pmodel_1 + 192]) | uint(c2da_mem[pmodel_1 + 193]) << 0x8 | uint(c2da_mem[pmodel_1 + 194]) << 0x10 | uint(c2da_mem[pmodel_1 + 195]) << 0x18)
    i_2 = 0
    while (i_2 < numsurfaces_0) {
        pplane_0 = int(uint(c2da_mem[psurf_0 + 16]) | uint(c2da_mem[psurf_0 + 17]) << 0x8 | uint(c2da_mem[psurf_0 + 18]) << 0x10 | uint(c2da_mem[psurf_0 + 19]) << 0x18)
        dot_1 = uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane_0 + 0 * 4]) | uint(c2da_mem[pplane_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane_0 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane_0 + 1 * 4]) | uint(c2da_mem[pplane_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane_0 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane_0 + 2 * 4]) | uint(c2da_mem[pplane_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane_0 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[pplane_0 + 12]) | uint(c2da_mem[pplane_0 + 13]) << 0x8 | uint(c2da_mem[pplane_0 + 14]) << 0x10 | uint(c2da_mem[pplane_0 + 15]) << 0x18)
        if ((int(uint(c2da_mem[psurf_0 + 24]) | uint(c2da_mem[psurf_0 + 25]) << 0x8 | uint(c2da_mem[psurf_0 + 26]) << 0x10 | uint(c2da_mem[psurf_0 + 27]) << 0x18) & 2) != 0 && double(dot_1) < -0.01lf || (int(uint(c2da_mem[psurf_0 + 24]) | uint(c2da_mem[psurf_0 + 25]) << 0x8 | uint(c2da_mem[psurf_0 + 26]) << 0x10 | uint(c2da_mem[psurf_0 + 27]) << 0x18) & 2) == 0 && double(dot_1) > 0.01lf) {
            pbverts = int(c2da_fp)  // nolint:PERF020
            pbedges = c2da_fp + 6000
            numbedges = 0
            numbverts = int(numbedges)  // nolint:PERF020
            if (int(uint(c2da_mem[psurf_0 + 32]) | uint(c2da_mem[psurf_0 + 33]) << 0x8 | uint(c2da_mem[psurf_0 + 34]) << 0x10 | uint(c2da_mem[psurf_0 + 35]) << 0x18) > 0) {
                pbedge = c2da_fp + 6000 + numbedges * 24
                numbedges += int(uint(c2da_mem[psurf_0 + 32]) | uint(c2da_mem[psurf_0 + 33]) << 0x8 | uint(c2da_mem[psurf_0 + 34]) << 0x10 | uint(c2da_mem[psurf_0 + 35]) << 0x18)
                j = 0
                while (j < int(uint(c2da_mem[psurf_0 + 32]) | uint(c2da_mem[psurf_0 + 33]) << 0x8 | uint(c2da_mem[psurf_0 + 34]) << 0x10 | uint(c2da_mem[psurf_0 + 35]) << 0x18)) {
                    let c2da_fresh23 : int = int(uint(c2da_mem[pmodel_1 + 256]) | uint(c2da_mem[pmodel_1 + 257]) << 0x8 | uint(c2da_mem[pmodel_1 + 258]) << 0x10 | uint(c2da_mem[pmodel_1 + 259]) << 0x18) + (int(uint(c2da_mem[psurf_0 + 28]) | uint(c2da_mem[psurf_0 + 29]) << 0x8 | uint(c2da_mem[psurf_0 + 30]) << 0x10 | uint(c2da_mem[psurf_0 + 31]) << 0x18) + j) * 4
                    lindex = int(uint(c2da_mem[c2da_fresh23]) | uint(c2da_mem[c2da_fresh23 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh23 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh23 + 3]) << 0x18)
                    if (lindex > 0) {
                        pedge = pedges + lindex * 8
                        let c2da_fresh24 : int = r_pcurrentvertbase + int(uint16(uint(c2da_mem[pedge + 0 * 2]) | uint(c2da_mem[pedge + 0 * 2 + 1]) << 0x8)) * 12
                        let c2da_fresh25 : uint = uint(c2da_fresh24)
                        c2da_mem[pbedge + j * 24 + 0 * 8] = uint8(c2da_fresh25)
                        c2da_mem[pbedge + j * 24 + 0 * 8 + 1] = uint8(c2da_fresh25 >> 0x8)
                        c2da_mem[pbedge + j * 24 + 0 * 8 + 2] = uint8(c2da_fresh25 >> 0x10)
                        c2da_mem[pbedge + j * 24 + 0 * 8 + 3] = uint8(c2da_fresh25 >> 0x18)
                        c2da_mem[pbedge + j * 24 + 0 * 8 + 4] = 0u8
                        c2da_mem[pbedge + j * 24 + 0 * 8 + 5] = 0u8
                        c2da_mem[pbedge + j * 24 + 0 * 8 + 6] = 0u8
                        c2da_mem[pbedge + j * 24 + 0 * 8 + 7] = 0u8
                        let c2da_fresh26 : int = r_pcurrentvertbase + int(uint16(uint(c2da_mem[pedge + 1 * 2]) | uint(c2da_mem[pedge + 1 * 2 + 1]) << 0x8)) * 12
                        let c2da_fresh27 : uint = uint(c2da_fresh26)
                        c2da_mem[pbedge + j * 24 + 1 * 8] = uint8(c2da_fresh27)
                        c2da_mem[pbedge + j * 24 + 1 * 8 + 1] = uint8(c2da_fresh27 >> 0x8)
                        c2da_mem[pbedge + j * 24 + 1 * 8 + 2] = uint8(c2da_fresh27 >> 0x10)
                        c2da_mem[pbedge + j * 24 + 1 * 8 + 3] = uint8(c2da_fresh27 >> 0x18)
                        c2da_mem[pbedge + j * 24 + 1 * 8 + 4] = 0u8
                        c2da_mem[pbedge + j * 24 + 1 * 8 + 5] = 0u8
                        c2da_mem[pbedge + j * 24 + 1 * 8 + 6] = 0u8
                        c2da_mem[pbedge + j * 24 + 1 * 8 + 7] = 0u8
                    } else {
                        lindex = -lindex
                        pedge = pedges + lindex * 8
                        let c2da_fresh28 : int = r_pcurrentvertbase + int(uint16(uint(c2da_mem[pedge + 1 * 2]) | uint(c2da_mem[pedge + 1 * 2 + 1]) << 0x8)) * 12
                        let c2da_fresh29 : uint = uint(c2da_fresh28)
                        c2da_mem[pbedge + j * 24 + 0 * 8] = uint8(c2da_fresh29)
                        c2da_mem[pbedge + j * 24 + 0 * 8 + 1] = uint8(c2da_fresh29 >> 0x8)
                        c2da_mem[pbedge + j * 24 + 0 * 8 + 2] = uint8(c2da_fresh29 >> 0x10)
                        c2da_mem[pbedge + j * 24 + 0 * 8 + 3] = uint8(c2da_fresh29 >> 0x18)
                        c2da_mem[pbedge + j * 24 + 0 * 8 + 4] = 0u8
                        c2da_mem[pbedge + j * 24 + 0 * 8 + 5] = 0u8
                        c2da_mem[pbedge + j * 24 + 0 * 8 + 6] = 0u8
                        c2da_mem[pbedge + j * 24 + 0 * 8 + 7] = 0u8
                        let c2da_fresh30 : int = r_pcurrentvertbase + int(uint16(uint(c2da_mem[pedge + 0 * 2]) | uint(c2da_mem[pedge + 0 * 2 + 1]) << 0x8)) * 12
                        let c2da_fresh31 : uint = uint(c2da_fresh30)
                        c2da_mem[pbedge + j * 24 + 1 * 8] = uint8(c2da_fresh31)
                        c2da_mem[pbedge + j * 24 + 1 * 8 + 1] = uint8(c2da_fresh31 >> 0x8)
                        c2da_mem[pbedge + j * 24 + 1 * 8 + 2] = uint8(c2da_fresh31 >> 0x10)
                        c2da_mem[pbedge + j * 24 + 1 * 8 + 3] = uint8(c2da_fresh31 >> 0x18)
                        c2da_mem[pbedge + j * 24 + 1 * 8 + 4] = 0u8
                        c2da_mem[pbedge + j * 24 + 1 * 8 + 5] = 0u8
                        c2da_mem[pbedge + j * 24 + 1 * 8 + 6] = 0u8
                        c2da_mem[pbedge + j * 24 + 1 * 8 + 7] = 0u8
                    }
                    let c2da_fresh32 : int = pbedge + (j + 1) * 24
                    let c2da_fresh33 : uint = uint(c2da_fresh32)
                    c2da_mem[pbedge + j * 24 + 16] = uint8(c2da_fresh33)
                    c2da_mem[pbedge + j * 24 + 17] = uint8(c2da_fresh33 >> 0x8)
                    c2da_mem[pbedge + j * 24 + 18] = uint8(c2da_fresh33 >> 0x10)
                    c2da_mem[pbedge + j * 24 + 19] = uint8(c2da_fresh33 >> 0x18)
                    c2da_mem[pbedge + j * 24 + 20] = 0u8
                    c2da_mem[pbedge + j * 24 + 21] = 0u8
                    c2da_mem[pbedge + j * 24 + 22] = 0u8
                    c2da_mem[pbedge + j * 24 + 23] = 0u8
                    j++
                }
                let c2da_fresh34 : uint = 0u
                c2da_mem[pbedge + (j - 1) * 24 + 16] = uint8(c2da_fresh34)
                c2da_mem[pbedge + (j - 1) * 24 + 17] = uint8(c2da_fresh34 >> 0x8)
                c2da_mem[pbedge + (j - 1) * 24 + 18] = uint8(c2da_fresh34 >> 0x10)
                c2da_mem[pbedge + (j - 1) * 24 + 19] = uint8(c2da_fresh34 >> 0x18)
                c2da_mem[pbedge + (j - 1) * 24 + 20] = 0u8
                c2da_mem[pbedge + (j - 1) * 24 + 21] = 0u8
                c2da_mem[pbedge + (j - 1) * 24 + 22] = 0u8
                c2da_mem[pbedge + (j - 1) * 24 + 23] = 0u8
                R_RecursiveClipBPoly(pbedge, int(uint(c2da_mem[currententity + 192]) | uint(c2da_mem[currententity + 193]) << 0x8 | uint(c2da_mem[currententity + 194]) << 0x10 | uint(c2da_mem[currententity + 195]) << 0x18), psurf_0)
            } else {
                Sys_Error(732624, [])
            }
        }
        i_2++
        psurf_0 += 104
    }
    return
}
[sideeffects]
def private R_RotateBmodel_c2da_frame(c2da_fp : int) {
    var angle : float
    var s : float
    var c_0 : float
    angle = uint_bits_to_float(uint(c2da_mem[currententity + 124 + 1 * 4]) | uint(c2da_mem[currententity + 124 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 124 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 124 + 1 * 4 + 3]) << 0x18)
    angle = float(double(angle) * 3.141592653589793lf * 2.0lf / 360.0lf)
    s = float(sin(double(angle)))
    c_0 = float(cos(double(angle)))
    let c2da_fresh59 : uint = float_bits_to_uint(c_0)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 0 * 4] = uint8(c2da_fresh59)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 0 * 4 + 1] = uint8(c2da_fresh59 >> 0x8)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 0 * 4 + 2] = uint8(c2da_fresh59 >> 0x10)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 0 * 4 + 3] = uint8(c2da_fresh59 >> 0x18)
    let c2da_fresh60 : uint = float_bits_to_uint(s)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 1 * 4] = uint8(c2da_fresh60)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 1 * 4 + 1] = uint8(c2da_fresh60 >> 0x8)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 1 * 4 + 2] = uint8(c2da_fresh60 >> 0x10)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 1 * 4 + 3] = uint8(c2da_fresh60 >> 0x18)
    let c2da_fresh61 : float = 0.0
    let c2da_fresh62 : uint = float_bits_to_uint(c2da_fresh61)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 2 * 4] = uint8(c2da_fresh62)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 2 * 4 + 1] = uint8(c2da_fresh62 >> 0x8)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 2 * 4 + 2] = uint8(c2da_fresh62 >> 0x10)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 2 * 4 + 3] = uint8(c2da_fresh62 >> 0x18)
    let c2da_fresh63 : float = -s
    let c2da_fresh64 : uint = float_bits_to_uint(c2da_fresh63)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 0 * 4] = uint8(c2da_fresh64)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 0 * 4 + 1] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 0 * 4 + 2] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 0 * 4 + 3] = uint8(c2da_fresh64 >> 0x18)
    let c2da_fresh65 : uint = float_bits_to_uint(c_0)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 1 * 4] = uint8(c2da_fresh65)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 1 * 4 + 1] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 1 * 4 + 2] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 1 * 4 + 3] = uint8(c2da_fresh65 >> 0x18)
    let c2da_fresh66 : float = 0.0
    let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 2 * 4] = uint8(c2da_fresh67)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 2 * 4 + 1] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 2 * 4 + 2] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 2 * 4 + 3] = uint8(c2da_fresh67 >> 0x18)
    let c2da_fresh68 : float = 0.0
    let c2da_fresh69 : uint = float_bits_to_uint(c2da_fresh68)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 0 * 4] = uint8(c2da_fresh69)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 0 * 4 + 1] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 0 * 4 + 2] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 0 * 4 + 3] = uint8(c2da_fresh69 >> 0x18)
    let c2da_fresh70 : float = 0.0
    let c2da_fresh71 : uint = float_bits_to_uint(c2da_fresh70)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 1 * 4] = uint8(c2da_fresh71)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 1 * 4 + 1] = uint8(c2da_fresh71 >> 0x8)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 1 * 4 + 2] = uint8(c2da_fresh71 >> 0x10)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 1 * 4 + 3] = uint8(c2da_fresh71 >> 0x18)
    let c2da_fresh72 : float = 1.0
    let c2da_fresh73 : uint = float_bits_to_uint(c2da_fresh72)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 2 * 4] = uint8(c2da_fresh73)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 2 * 4 + 1] = uint8(c2da_fresh73 >> 0x8)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 2 * 4 + 2] = uint8(c2da_fresh73 >> 0x10)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 2 * 4 + 3] = uint8(c2da_fresh73 >> 0x18)
    angle = uint_bits_to_float(uint(c2da_mem[currententity + 124 + 0 * 4]) | uint(c2da_mem[currententity + 124 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 124 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 124 + 0 * 4 + 3]) << 0x18)
    angle = float(double(angle) * 3.141592653589793lf * 2.0lf / 360.0lf)
    s = float(sin(double(angle)))
    c_0 = float(cos(double(angle)))
    let c2da_fresh74 : uint = float_bits_to_uint(c_0)
    c2da_mem[c2da_fp + 0 * 12 + 0 * 4] = uint8(c2da_fresh74)
    c2da_mem[c2da_fp + 0 * 12 + 0 * 4 + 1] = uint8(c2da_fresh74 >> 0x8)
    c2da_mem[c2da_fp + 0 * 12 + 0 * 4 + 2] = uint8(c2da_fresh74 >> 0x10)
    c2da_mem[c2da_fp + 0 * 12 + 0 * 4 + 3] = uint8(c2da_fresh74 >> 0x18)
    let c2da_fresh75 : float = 0.0
    let c2da_fresh76 : uint = float_bits_to_uint(c2da_fresh75)
    c2da_mem[c2da_fp + 0 * 12 + 1 * 4] = uint8(c2da_fresh76)
    c2da_mem[c2da_fp + 0 * 12 + 1 * 4 + 1] = uint8(c2da_fresh76 >> 0x8)
    c2da_mem[c2da_fp + 0 * 12 + 1 * 4 + 2] = uint8(c2da_fresh76 >> 0x10)
    c2da_mem[c2da_fp + 0 * 12 + 1 * 4 + 3] = uint8(c2da_fresh76 >> 0x18)
    let c2da_fresh77 : float = -s
    let c2da_fresh78 : uint = float_bits_to_uint(c2da_fresh77)
    c2da_mem[c2da_fp + 0 * 12 + 2 * 4] = uint8(c2da_fresh78)
    c2da_mem[c2da_fp + 0 * 12 + 2 * 4 + 1] = uint8(c2da_fresh78 >> 0x8)
    c2da_mem[c2da_fp + 0 * 12 + 2 * 4 + 2] = uint8(c2da_fresh78 >> 0x10)
    c2da_mem[c2da_fp + 0 * 12 + 2 * 4 + 3] = uint8(c2da_fresh78 >> 0x18)
    let c2da_fresh79 : float = 0.0
    let c2da_fresh80 : uint = float_bits_to_uint(c2da_fresh79)
    c2da_mem[c2da_fp + 1 * 12 + 0 * 4] = uint8(c2da_fresh80)
    c2da_mem[c2da_fp + 1 * 12 + 0 * 4 + 1] = uint8(c2da_fresh80 >> 0x8)
    c2da_mem[c2da_fp + 1 * 12 + 0 * 4 + 2] = uint8(c2da_fresh80 >> 0x10)
    c2da_mem[c2da_fp + 1 * 12 + 0 * 4 + 3] = uint8(c2da_fresh80 >> 0x18)
    let c2da_fresh81 : float = 1.0
    let c2da_fresh82 : uint = float_bits_to_uint(c2da_fresh81)
    c2da_mem[c2da_fp + 1 * 12 + 1 * 4] = uint8(c2da_fresh82)
    c2da_mem[c2da_fp + 1 * 12 + 1 * 4 + 1] = uint8(c2da_fresh82 >> 0x8)
    c2da_mem[c2da_fp + 1 * 12 + 1 * 4 + 2] = uint8(c2da_fresh82 >> 0x10)
    c2da_mem[c2da_fp + 1 * 12 + 1 * 4 + 3] = uint8(c2da_fresh82 >> 0x18)
    let c2da_fresh83 : float = 0.0
    let c2da_fresh84 : uint = float_bits_to_uint(c2da_fresh83)
    c2da_mem[c2da_fp + 1 * 12 + 2 * 4] = uint8(c2da_fresh84)
    c2da_mem[c2da_fp + 1 * 12 + 2 * 4 + 1] = uint8(c2da_fresh84 >> 0x8)
    c2da_mem[c2da_fp + 1 * 12 + 2 * 4 + 2] = uint8(c2da_fresh84 >> 0x10)
    c2da_mem[c2da_fp + 1 * 12 + 2 * 4 + 3] = uint8(c2da_fresh84 >> 0x18)
    let c2da_fresh85 : uint = float_bits_to_uint(s)
    c2da_mem[c2da_fp + 2 * 12 + 0 * 4] = uint8(c2da_fresh85)
    c2da_mem[c2da_fp + 2 * 12 + 0 * 4 + 1] = uint8(c2da_fresh85 >> 0x8)
    c2da_mem[c2da_fp + 2 * 12 + 0 * 4 + 2] = uint8(c2da_fresh85 >> 0x10)
    c2da_mem[c2da_fp + 2 * 12 + 0 * 4 + 3] = uint8(c2da_fresh85 >> 0x18)
    let c2da_fresh86 : float = 0.0
    let c2da_fresh87 : uint = float_bits_to_uint(c2da_fresh86)
    c2da_mem[c2da_fp + 2 * 12 + 1 * 4] = uint8(c2da_fresh87)
    c2da_mem[c2da_fp + 2 * 12 + 1 * 4 + 1] = uint8(c2da_fresh87 >> 0x8)
    c2da_mem[c2da_fp + 2 * 12 + 1 * 4 + 2] = uint8(c2da_fresh87 >> 0x10)
    c2da_mem[c2da_fp + 2 * 12 + 1 * 4 + 3] = uint8(c2da_fresh87 >> 0x18)
    let c2da_fresh88 : uint = float_bits_to_uint(c_0)
    c2da_mem[c2da_fp + 2 * 12 + 2 * 4] = uint8(c2da_fresh88)
    c2da_mem[c2da_fp + 2 * 12 + 2 * 4 + 1] = uint8(c2da_fresh88 >> 0x8)
    c2da_mem[c2da_fp + 2 * 12 + 2 * 4 + 2] = uint8(c2da_fresh88 >> 0x10)
    c2da_mem[c2da_fp + 2 * 12 + 2 * 4 + 3] = uint8(c2da_fresh88 >> 0x18)
    R_ConcatRotations(c2da_fp, c2da_fp + 48, c2da_fp + 96)
    angle = uint_bits_to_float(uint(c2da_mem[currententity + 124 + 2 * 4]) | uint(c2da_mem[currententity + 124 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 124 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 124 + 2 * 4 + 3]) << 0x18)
    angle = float(double(angle) * 3.141592653589793lf * 2.0lf / 360.0lf)
    s = float(sin(double(angle)))
    c_0 = float(cos(double(angle)))
    let c2da_fresh89 : float = 1.0
    let c2da_fresh90 : uint = float_bits_to_uint(c2da_fresh89)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 0 * 4] = uint8(c2da_fresh90)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 0 * 4 + 1] = uint8(c2da_fresh90 >> 0x8)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 0 * 4 + 2] = uint8(c2da_fresh90 >> 0x10)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 0 * 4 + 3] = uint8(c2da_fresh90 >> 0x18)
    let c2da_fresh91 : float = 0.0
    let c2da_fresh92 : uint = float_bits_to_uint(c2da_fresh91)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 1 * 4] = uint8(c2da_fresh92)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 1 * 4 + 1] = uint8(c2da_fresh92 >> 0x8)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 1 * 4 + 2] = uint8(c2da_fresh92 >> 0x10)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 1 * 4 + 3] = uint8(c2da_fresh92 >> 0x18)
    let c2da_fresh93 : float = 0.0
    let c2da_fresh94 : uint = float_bits_to_uint(c2da_fresh93)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 2 * 4] = uint8(c2da_fresh94)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 2 * 4 + 1] = uint8(c2da_fresh94 >> 0x8)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 2 * 4 + 2] = uint8(c2da_fresh94 >> 0x10)
    c2da_mem[c2da_fp + 48 + 0 * 12 + 2 * 4 + 3] = uint8(c2da_fresh94 >> 0x18)
    let c2da_fresh95 : float = 0.0
    let c2da_fresh96 : uint = float_bits_to_uint(c2da_fresh95)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 0 * 4] = uint8(c2da_fresh96)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 0 * 4 + 1] = uint8(c2da_fresh96 >> 0x8)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 0 * 4 + 2] = uint8(c2da_fresh96 >> 0x10)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 0 * 4 + 3] = uint8(c2da_fresh96 >> 0x18)
    let c2da_fresh97 : uint = float_bits_to_uint(c_0)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 1 * 4] = uint8(c2da_fresh97)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 1 * 4 + 1] = uint8(c2da_fresh97 >> 0x8)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 1 * 4 + 2] = uint8(c2da_fresh97 >> 0x10)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 1 * 4 + 3] = uint8(c2da_fresh97 >> 0x18)
    let c2da_fresh98 : uint = float_bits_to_uint(s)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 2 * 4] = uint8(c2da_fresh98)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 2 * 4 + 1] = uint8(c2da_fresh98 >> 0x8)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 2 * 4 + 2] = uint8(c2da_fresh98 >> 0x10)
    c2da_mem[c2da_fp + 48 + 1 * 12 + 2 * 4 + 3] = uint8(c2da_fresh98 >> 0x18)
    let c2da_fresh99 : float = 0.0
    let c2da_fresh100 : uint = float_bits_to_uint(c2da_fresh99)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 0 * 4] = uint8(c2da_fresh100)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 0 * 4 + 1] = uint8(c2da_fresh100 >> 0x8)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 0 * 4 + 2] = uint8(c2da_fresh100 >> 0x10)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 0 * 4 + 3] = uint8(c2da_fresh100 >> 0x18)
    let c2da_fresh101 : float = -s
    let c2da_fresh102 : uint = float_bits_to_uint(c2da_fresh101)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 1 * 4] = uint8(c2da_fresh102)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 1 * 4 + 1] = uint8(c2da_fresh102 >> 0x8)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 1 * 4 + 2] = uint8(c2da_fresh102 >> 0x10)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 1 * 4 + 3] = uint8(c2da_fresh102 >> 0x18)
    let c2da_fresh103 : uint = float_bits_to_uint(c_0)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 2 * 4] = uint8(c2da_fresh103)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 2 * 4 + 1] = uint8(c2da_fresh103 >> 0x8)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 2 * 4 + 2] = uint8(c2da_fresh103 >> 0x10)
    c2da_mem[c2da_fp + 48 + 2 * 12 + 2 * 4 + 3] = uint8(c2da_fresh103 >> 0x18)
    R_ConcatRotations(c2da_fp + 48, c2da_fp + 96, 391392)
    R_EntityRotate(204240)
    R_EntityRotate(244128)
    R_EntityRotate(244144)
    R_EntityRotate(244160)
    R_TransformFrustum()
    return
}

// This unit's static data, at heap offset 732624.
let private c2da_lin_static_r_bsp_seg = fixed_array<int>(732624, 43)
let private c2da_lin_static_r_bsp = fixed_array<uint64>(0x7365676465206f6eul, 0x646f6d62206e6920ul, 0x6f2074754f006c65ul, 0x2073656764652066ul, 0x646f6d6220726f66ul, 0xa6c65ul)

[init]
def private c2da_lin_init_static_r_bsp() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_bsp_seg[s * 2]
        for (k in range(c2da_lin_static_r_bsp_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_bsp[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
