var r_zpointdesc : zpointdesc_t = default<zpointdesc_t>

var r_polydesc : polydesc_s = default<polydesc_s>

[export, sideeffects]
def R_RenderFace(var fa : int; var clipflags : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_RenderFace_c2da_frame(fa, clipflags, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
var r_nearzi : float = default<float>

var r_emitted : int = default<int>

[export, sideeffects]
def R_ClipEdge(var pv0 : int; var pv1 : int; var clip : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_ClipEdge_c2da_frame(pv0, pv1, clip, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_EmitEdge(var pv0_0 : int; var pv1_0 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_EmitEdge_c2da_frame(pv0_0, pv1_0, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
var r_v1 : float = default<float>

var r_u1 : float = default<float>

var r_ceilv1 : int = default<int>

var r_pedge : int = default<int>

var cacheoffset : uint = default<uint>

var r_nearzionly : uint = default<uint>

var r_lzi1 : float = default<float>

var r_lastvertvalid : uint = default<uint>

var r_rightclipped : uint = default<uint>

var r_leftclipped : uint = default<uint>

var private makerightedge : uint = default<uint>

var private makeleftedge : uint = default<uint>

[export, sideeffects]
def R_EmitCachedEdge() {
    var pedge_t : int = int(uint64(r_edges) + uint64(uint(c2da_mem[r_pedge + 4]) | uint(c2da_mem[r_pedge + 5]) << 0x8 | uint(c2da_mem[r_pedge + 6]) << 0x10 | uint(c2da_mem[r_pedge + 7]) << 0x18))
    if (uint16(uint(c2da_mem[pedge_t + 24 + 0 * 2]) | uint(c2da_mem[pedge_t + 24 + 0 * 2 + 1]) << 0x8) == 0) {
        let c2da_fresh112 : uint16 = uint16(int64((surface_p - surfaces) / 88))
        let c2da_fresh113 : uint = uint(c2da_fresh112)
        c2da_mem[pedge_t + 24 + 0 * 2] = uint8(c2da_fresh113)
        c2da_mem[pedge_t + 24 + 0 * 2 + 1] = uint8(c2da_fresh113 >> 0x8)
    } else {
        let c2da_fresh114 : uint16 = uint16(int64((surface_p - surfaces) / 88))
        let c2da_fresh115 : uint = uint(c2da_fresh114)
        c2da_mem[pedge_t + 24 + 1 * 2] = uint8(c2da_fresh115)
        c2da_mem[pedge_t + 24 + 1 * 2 + 1] = uint8(c2da_fresh115 >> 0x8)
    }
    let c2da_fresh116 : float = uint_bits_to_float(uint(c2da_mem[pedge_t + 40]) | uint(c2da_mem[pedge_t + 41]) << 0x8 | uint(c2da_mem[pedge_t + 42]) << 0x10 | uint(c2da_mem[pedge_t + 43]) << 0x18)
    if (c2da_fresh116 > r_nearzi) {
        r_nearzi = c2da_fresh116
    }
    r_emitted = 1
    return
}
var c_faceclip : int = default<int>

[export, sideeffects]
def R_RenderPoly(var fa_0 : int; var clipflags_0 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_RenderPoly_c2da_frame(fa_0, clipflags_0, c2da_lin_enter(2032))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_RenderBmodelFace(var pedges_1 : int; var psurf : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_RenderBmodelFace_c2da_frame(pedges_1, psurf, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_ZDrawSubmodelPolys(var pmodel_0 : int) {
    var i_2 : int
    var numsurfaces : int
    var psurf_0 : int
    var dot : float
    var pplane_2 : int
    psurf_0 = int(uint(c2da_mem[pmodel_0 + 240]) | uint(c2da_mem[pmodel_0 + 241]) << 0x8 | uint(c2da_mem[pmodel_0 + 242]) << 0x10 | uint(c2da_mem[pmodel_0 + 243]) << 0x18) + int(uint(c2da_mem[pmodel_0 + 112]) | uint(c2da_mem[pmodel_0 + 113]) << 0x8 | uint(c2da_mem[pmodel_0 + 114]) << 0x10 | uint(c2da_mem[pmodel_0 + 115]) << 0x18) * 104
    numsurfaces = int(uint(c2da_mem[pmodel_0 + 116]) | uint(c2da_mem[pmodel_0 + 117]) << 0x8 | uint(c2da_mem[pmodel_0 + 118]) << 0x10 | uint(c2da_mem[pmodel_0 + 119]) << 0x18)
    i_2 = 0
    while (i_2 < numsurfaces) {
        pplane_2 = int(uint(c2da_mem[psurf_0 + 16]) | uint(c2da_mem[psurf_0 + 17]) << 0x8 | uint(c2da_mem[psurf_0 + 18]) << 0x10 | uint(c2da_mem[psurf_0 + 19]) << 0x18)
        dot = uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane_2 + 0 * 4]) | uint(c2da_mem[pplane_2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane_2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane_2 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane_2 + 1 * 4]) | uint(c2da_mem[pplane_2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane_2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane_2 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane_2 + 2 * 4]) | uint(c2da_mem[pplane_2 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane_2 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane_2 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[pplane_2 + 12]) | uint(c2da_mem[pplane_2 + 13]) << 0x8 | uint(c2da_mem[pplane_2 + 14]) << 0x10 | uint(c2da_mem[pplane_2 + 15]) << 0x18)
        let c2da_fresh165 : int = int(uint(c2da_mem[psurf_0 + 24]) | uint(c2da_mem[psurf_0 + 25]) << 0x8 | uint(c2da_mem[psurf_0 + 26]) << 0x10 | uint(c2da_mem[psurf_0 + 27]) << 0x18)
        if ((c2da_fresh165 & 2) != 0 && double(dot) < -0.01lf || (c2da_fresh165 & 2) == 0 && double(dot) > 0.01lf) {
            R_RenderPoly(psurf_0, 15)
        }
        i_2++
        psurf_0 += 104
    }
    return
}
var entity_clipplanes : int = default<int>

var world_clipplanes : clipplane_s[16]

[sideeffects]
def private R_RenderFace_c2da_frame(var fa : int; var clipflags : int; c2da_fp : int) {
    var i : int
    var lindex : int
    var mask : uint
    var pplane : int
    var distinv : float
    var pedges : int
    var pclip : int
    if (surface_p >= surf_max) {
        r_outofsurfaces = r_outofsurfaces + 1
        return
    }
    let c2da_fresh26 : int = int(uint(c2da_mem[fa + 32]) | uint(c2da_mem[fa + 33]) << 0x8 | uint(c2da_mem[fa + 34]) << 0x10 | uint(c2da_mem[fa + 35]) << 0x18)
    if (edge_p + c2da_fresh26 * 56 + 4 * 56 >= edge_max) {
        r_outofedges = r_outofedges + c2da_fresh26
        return
    }
    c_faceclip++
    pclip = 0
    i = 3
    mask = 0x8u
    while (i >= 0) {
        if ((uint(clipflags) & mask) != 0x0) {
            let c2da_fresh0 : uint = uint(pclip)
            c2da_mem[391440 + i * 32 + 16] = uint8(c2da_fresh0)
            c2da_mem[391440 + i * 32 + 17] = uint8(c2da_fresh0 >> 0x8)
            c2da_mem[391440 + i * 32 + 18] = uint8(c2da_fresh0 >> 0x10)
            c2da_mem[391440 + i * 32 + 19] = uint8(c2da_fresh0 >> 0x18)
            c2da_mem[391440 + i * 32 + 20] = 0u8
            c2da_mem[391440 + i * 32 + 21] = 0u8
            c2da_mem[391440 + i * 32 + 22] = 0u8
            c2da_mem[391440 + i * 32 + 23] = 0u8
            pclip = 391440 + i * 32
        }
        i--
        mask >>= 1u
    }
    r_emitted = 0
    r_nearzi = 0.0
    r_nearzionly = 0u
    makerightedge = 0u
    makeleftedge = uint(makerightedge)  // nolint:PERF020
    let c2da_fresh1 : int = int(uint(c2da_mem[currententity + 136]) | uint(c2da_mem[currententity + 137]) << 0x8 | uint(c2da_mem[currententity + 138]) << 0x10 | uint(c2da_mem[currententity + 139]) << 0x18) + 192
    pedges = int(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh1 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh1 + 3]) << 0x18)
    r_lastvertvalid = 0u
    i = 0
    while (i < int(uint(c2da_mem[fa + 32]) | uint(c2da_mem[fa + 33]) << 0x8 | uint(c2da_mem[fa + 34]) << 0x10 | uint(c2da_mem[fa + 35]) << 0x18)) {
        let c2da_fresh2 : int = int(uint(c2da_mem[currententity + 136]) | uint(c2da_mem[currententity + 137]) << 0x8 | uint(c2da_mem[currententity + 138]) << 0x10 | uint(c2da_mem[currententity + 139]) << 0x18) + 256
        let c2da_fresh3 : int = int(uint(c2da_mem[c2da_fresh2]) | uint(c2da_mem[c2da_fresh2 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh2 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh2 + 3]) << 0x18) + (int(uint(c2da_mem[fa + 28]) | uint(c2da_mem[fa + 29]) << 0x8 | uint(c2da_mem[fa + 30]) << 0x10 | uint(c2da_mem[fa + 31]) << 0x18) + i) * 4
        lindex = int(uint(c2da_mem[c2da_fresh3]) | uint(c2da_mem[c2da_fresh3 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh3 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh3 + 3]) << 0x18)
        if (lindex > 0) {
            r_pedge = pedges + lindex * 8
            if (uint(insubmodel) == 0u) {
                if (((uint(c2da_mem[r_pedge + 4]) | uint(c2da_mem[r_pedge + 5]) << 0x8 | uint(c2da_mem[r_pedge + 6]) << 0x10 | uint(c2da_mem[r_pedge + 7]) << 0x18) & 0x80000000u) != 0x0) {
                    if (((uint(c2da_mem[r_pedge + 4]) | uint(c2da_mem[r_pedge + 5]) << 0x8 | uint(c2da_mem[r_pedge + 6]) << 0x10 | uint(c2da_mem[r_pedge + 7]) << 0x18) & 0x7fffffffu) == uint(r_framecount)) {
                        r_lastvertvalid = 0u
                        i++
                        continue
                    }
                } else {
                    var c2da_fresh5 : int = 0
                    if (uint64(edge_p) - uint64(r_edges) > uint64(uint(c2da_mem[r_pedge + 4]) | uint(c2da_mem[r_pedge + 5]) << 0x8 | uint(c2da_mem[r_pedge + 6]) << 0x10 | uint(c2da_mem[r_pedge + 7]) << 0x18)) {
                        let c2da_fresh4 : int = int(uint64(r_edges) + uint64(uint(c2da_mem[r_pedge + 4]) | uint(c2da_mem[r_pedge + 5]) << 0x8 | uint(c2da_mem[r_pedge + 6]) << 0x10 | uint(c2da_mem[r_pedge + 7]) << 0x18)) + 48
                        if (int(uint(c2da_mem[c2da_fresh4]) | uint(c2da_mem[c2da_fresh4 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh4 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh4 + 3]) << 0x18) == r_pedge) {
                            c2da_fresh5 = 1
                        }
                    }
                    if (c2da_fresh5 != 0) {
                        R_EmitCachedEdge()
                        r_lastvertvalid = 0u
                        i++
                        continue
                    }
                }
            }
            cacheoffset = uint(int64(edge_p - r_edges))
            r_rightclipped = 0u
            r_leftclipped = uint(r_rightclipped)  // nolint:PERF020
            R_ClipEdge(r_pcurrentvertbase + int(uint16(uint(c2da_mem[r_pedge + 0 * 2]) | uint(c2da_mem[r_pedge + 0 * 2 + 1]) << 0x8)) * 12, r_pcurrentvertbase + int(uint16(uint(c2da_mem[r_pedge + 1 * 2]) | uint(c2da_mem[r_pedge + 1 * 2 + 1]) << 0x8)) * 12, pclip)
            let c2da_fresh6 : uint = cacheoffset
            c2da_mem[r_pedge + 4] = uint8(c2da_fresh6)
            c2da_mem[r_pedge + 5] = uint8(c2da_fresh6 >> 0x8)
            c2da_mem[r_pedge + 6] = uint8(c2da_fresh6 >> 0x10)
            c2da_mem[r_pedge + 7] = uint8(c2da_fresh6 >> 0x18)
            if (r_leftclipped != 0u) {
                makeleftedge = 1u
            }
            if (r_rightclipped != 0u) {
                makerightedge = 1u
            }
            r_lastvertvalid = 1u
        } else {
            lindex = -lindex
            r_pedge = pedges + lindex * 8
            if (uint(insubmodel) == 0u) {
                if (((uint(c2da_mem[r_pedge + 4]) | uint(c2da_mem[r_pedge + 5]) << 0x8 | uint(c2da_mem[r_pedge + 6]) << 0x10 | uint(c2da_mem[r_pedge + 7]) << 0x18) & 0x80000000u) != 0x0) {
                    if (((uint(c2da_mem[r_pedge + 4]) | uint(c2da_mem[r_pedge + 5]) << 0x8 | uint(c2da_mem[r_pedge + 6]) << 0x10 | uint(c2da_mem[r_pedge + 7]) << 0x18) & 0x7fffffffu) == uint(r_framecount)) {
                        r_lastvertvalid = 0u
                        i++
                        continue
                    }
                } else {
                    var c2da_fresh8 : int = 0
                    if (uint64(edge_p) - uint64(r_edges) > uint64(uint(c2da_mem[r_pedge + 4]) | uint(c2da_mem[r_pedge + 5]) << 0x8 | uint(c2da_mem[r_pedge + 6]) << 0x10 | uint(c2da_mem[r_pedge + 7]) << 0x18)) {
                        let c2da_fresh7 : int = int(uint64(r_edges) + uint64(uint(c2da_mem[r_pedge + 4]) | uint(c2da_mem[r_pedge + 5]) << 0x8 | uint(c2da_mem[r_pedge + 6]) << 0x10 | uint(c2da_mem[r_pedge + 7]) << 0x18)) + 48
                        if (int(uint(c2da_mem[c2da_fresh7]) | uint(c2da_mem[c2da_fresh7 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh7 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh7 + 3]) << 0x18) == r_pedge) {
                            c2da_fresh8 = 1
                        }
                    }
                    if (c2da_fresh8 != 0) {
                        R_EmitCachedEdge()
                        r_lastvertvalid = 0u
                        i++
                        continue
                    }
                }
            }
            cacheoffset = uint(int64(edge_p - r_edges))
            r_rightclipped = 0u
            r_leftclipped = uint(r_rightclipped)  // nolint:PERF020
            R_ClipEdge(r_pcurrentvertbase + int(uint16(uint(c2da_mem[r_pedge + 1 * 2]) | uint(c2da_mem[r_pedge + 1 * 2 + 1]) << 0x8)) * 12, r_pcurrentvertbase + int(uint16(uint(c2da_mem[r_pedge + 0 * 2]) | uint(c2da_mem[r_pedge + 0 * 2 + 1]) << 0x8)) * 12, pclip)
            let c2da_fresh9 : uint = cacheoffset
            c2da_mem[r_pedge + 4] = uint8(c2da_fresh9)
            c2da_mem[r_pedge + 5] = uint8(c2da_fresh9 >> 0x8)
            c2da_mem[r_pedge + 6] = uint8(c2da_fresh9 >> 0x10)
            c2da_mem[r_pedge + 7] = uint8(c2da_fresh9 >> 0x18)
            if (r_leftclipped != 0u) {
                makeleftedge = 1u
            }
            if (r_rightclipped != 0u) {
                makerightedge = 1u
            }
            r_lastvertvalid = 1u
        }
        i++
    }
    if (makeleftedge != 0u) {
        r_pedge = int(c2da_fp)  // nolint:PERF020
        r_lastvertvalid = 0u
        R_ClipEdge(391568, 391584, int(uint(c2da_mem[pclip + 16]) | uint(c2da_mem[pclip + 17]) << 0x8 | uint(c2da_mem[pclip + 18]) << 0x10 | uint(c2da_mem[pclip + 19]) << 0x18))
    }
    if (makerightedge != 0u) {
        r_pedge = int(c2da_fp)  // nolint:PERF020
        r_lastvertvalid = 0u
        r_nearzionly = 1u
        R_ClipEdge(391600, 391616, int(uint(c2da_mem[391440 + 1 * 32 + 16]) | uint(c2da_mem[391440 + 1 * 32 + 17]) << 0x8 | uint(c2da_mem[391440 + 1 * 32 + 18]) << 0x10 | uint(c2da_mem[391440 + 1 * 32 + 19]) << 0x18))
    }
    if (r_emitted == 0) {
        return
    }
    r_polycount = r_polycount + 1
    let c2da_fresh10 : uint = uint(fa)
    c2da_mem[surface_p + 40] = uint8(c2da_fresh10)
    c2da_mem[surface_p + 41] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[surface_p + 42] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[surface_p + 43] = uint8(c2da_fresh10 >> 0x18)
    c2da_mem[surface_p + 44] = 0u8
    c2da_mem[surface_p + 45] = 0u8
    c2da_mem[surface_p + 46] = 0u8
    c2da_mem[surface_p + 47] = 0u8
    let c2da_fresh11 : uint = float_bits_to_uint(r_nearzi)
    c2da_mem[surface_p + 56] = uint8(c2da_fresh11)
    c2da_mem[surface_p + 57] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[surface_p + 58] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[surface_p + 59] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : int = int(uint(c2da_mem[fa + 24]) | uint(c2da_mem[fa + 25]) << 0x8 | uint(c2da_mem[fa + 26]) << 0x10 | uint(c2da_mem[fa + 27]) << 0x18)
    let c2da_fresh13 : uint = uint(c2da_fresh12)
    c2da_mem[surface_p + 36] = uint8(c2da_fresh13)
    c2da_mem[surface_p + 37] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[surface_p + 38] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[surface_p + 39] = uint8(c2da_fresh13 >> 0x18)
    let c2da_fresh14 : uint = insubmodel
    c2da_mem[surface_p + 60] = uint8(c2da_fresh14)
    c2da_mem[surface_p + 61] = uint8(c2da_fresh14 >> 0x8)
    c2da_mem[surface_p + 62] = uint8(c2da_fresh14 >> 0x10)
    c2da_mem[surface_p + 63] = uint8(c2da_fresh14 >> 0x18)
    let c2da_fresh15 : int = 0
    let c2da_fresh16 : uint = uint(c2da_fresh15)
    c2da_mem[surface_p + 32] = uint8(c2da_fresh16)
    c2da_mem[surface_p + 33] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[surface_p + 34] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[surface_p + 35] = uint8(c2da_fresh16 >> 0x18)
    let c2da_fresh17 : uint = uint(currententity)
    c2da_mem[surface_p + 48] = uint8(c2da_fresh17)
    c2da_mem[surface_p + 49] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[surface_p + 50] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[surface_p + 51] = uint8(c2da_fresh17 >> 0x18)
    c2da_mem[surface_p + 52] = 0u8
    c2da_mem[surface_p + 53] = 0u8
    c2da_mem[surface_p + 54] = 0u8
    c2da_mem[surface_p + 55] = 0u8
    let c2da_postinc : int = r_currentkey
    r_currentkey = r_currentkey + 1
    let c2da_fresh18 : uint = uint(c2da_postinc)
    c2da_mem[surface_p + 24] = uint8(c2da_fresh18)
    c2da_mem[surface_p + 25] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[surface_p + 26] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[surface_p + 27] = uint8(c2da_fresh18 >> 0x18)
    let c2da_fresh19 : uint = 0u
    c2da_mem[surface_p + 16] = uint8(c2da_fresh19)
    c2da_mem[surface_p + 17] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[surface_p + 18] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[surface_p + 19] = uint8(c2da_fresh19 >> 0x18)
    c2da_mem[surface_p + 20] = 0u8
    c2da_mem[surface_p + 21] = 0u8
    c2da_mem[surface_p + 22] = 0u8
    c2da_mem[surface_p + 23] = 0u8
    pplane = int(uint(c2da_mem[fa + 16]) | uint(c2da_mem[fa + 17]) << 0x8 | uint(c2da_mem[fa + 18]) << 0x10 | uint(c2da_mem[fa + 19]) << 0x18)
    TransformVector(pplane, c2da_fp + 16)
    distinv = float(1.0lf / double(uint_bits_to_float(uint(c2da_mem[pplane + 12]) | uint(c2da_mem[pplane + 13]) << 0x8 | uint(c2da_mem[pplane + 14]) << 0x10 | uint(c2da_mem[pplane + 15]) << 0x18) - (uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane + 0 * 4]) | uint(c2da_mem[pplane + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane + 1 * 4]) | uint(c2da_mem[pplane + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane + 2 * 4]) | uint(c2da_mem[pplane + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane + 2 * 4 + 3]) << 0x18))))
    let c2da_fresh20 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18) * xscaleinv * distinv
    let c2da_fresh21 : uint = float_bits_to_uint(c2da_fresh20)
    c2da_mem[surface_p + 68] = uint8(c2da_fresh21)
    c2da_mem[surface_p + 69] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[surface_p + 70] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[surface_p + 71] = uint8(c2da_fresh21 >> 0x18)
    let c2da_fresh22 : float = -uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18) * yscaleinv * distinv
    let c2da_fresh23 : uint = float_bits_to_uint(c2da_fresh22)
    c2da_mem[surface_p + 72] = uint8(c2da_fresh23)
    c2da_mem[surface_p + 73] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[surface_p + 74] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[surface_p + 75] = uint8(c2da_fresh23 >> 0x18)
    let c2da_fresh24 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18) * distinv - xcenter * c2da_fresh20 - ycenter * c2da_fresh22
    let c2da_fresh25 : uint = float_bits_to_uint(c2da_fresh24)
    c2da_mem[surface_p + 64] = uint8(c2da_fresh25)
    c2da_mem[surface_p + 65] = uint8(c2da_fresh25 >> 0x8)
    c2da_mem[surface_p + 66] = uint8(c2da_fresh25 >> 0x10)
    c2da_mem[surface_p + 67] = uint8(c2da_fresh25 >> 0x18)
    surface_p = surface_p + 88
    return
}
[sideeffects]
def private R_ClipEdge_c2da_frame(var pv0 : int; var pv1 : int; var clip : int; c2da_fp : int) {
    var d0 : float
    var d1 : float
    var f : float
    if (clip != 0) {
        while (true) {
            let c2da_fresh39 : float = uint_bits_to_float(uint(c2da_mem[pv0 + 0 * 4]) | uint(c2da_mem[pv0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pv0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pv0 + 0 * 4 + 3]) << 0x18)
            let c2da_fresh40 : float = uint_bits_to_float(uint(c2da_mem[clip + 0 * 4]) | uint(c2da_mem[clip + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[clip + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[clip + 0 * 4 + 3]) << 0x18)
            let c2da_fresh41 : float = uint_bits_to_float(uint(c2da_mem[pv0 + 1 * 4]) | uint(c2da_mem[pv0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pv0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pv0 + 1 * 4 + 3]) << 0x18)
            let c2da_fresh42 : float = uint_bits_to_float(uint(c2da_mem[clip + 1 * 4]) | uint(c2da_mem[clip + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[clip + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[clip + 1 * 4 + 3]) << 0x18)
            let c2da_fresh43 : float = uint_bits_to_float(uint(c2da_mem[pv0 + 2 * 4]) | uint(c2da_mem[pv0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pv0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pv0 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh44 : float = uint_bits_to_float(uint(c2da_mem[clip + 2 * 4]) | uint(c2da_mem[clip + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[clip + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[clip + 2 * 4 + 3]) << 0x18)
            let c2da_fresh45 : float = uint_bits_to_float(uint(c2da_mem[clip + 12]) | uint(c2da_mem[clip + 13]) << 0x8 | uint(c2da_mem[clip + 14]) << 0x10 | uint(c2da_mem[clip + 15]) << 0x18)
            d0 = c2da_fresh39 * c2da_fresh40 + c2da_fresh41 * c2da_fresh42 + c2da_fresh43 * c2da_fresh44 - c2da_fresh45
            let c2da_fresh46 : float = uint_bits_to_float(uint(c2da_mem[pv1 + 0 * 4]) | uint(c2da_mem[pv1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pv1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pv1 + 0 * 4 + 3]) << 0x18)
            let c2da_fresh47 : float = uint_bits_to_float(uint(c2da_mem[pv1 + 1 * 4]) | uint(c2da_mem[pv1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pv1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pv1 + 1 * 4 + 3]) << 0x18)
            let c2da_fresh48 : float = uint_bits_to_float(uint(c2da_mem[pv1 + 2 * 4]) | uint(c2da_mem[pv1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pv1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pv1 + 2 * 4 + 3]) << 0x18)
            d1 = c2da_fresh46 * c2da_fresh40 + c2da_fresh47 * c2da_fresh42 + c2da_fresh48 * c2da_fresh44 - c2da_fresh45
            if (d0 >= 0.0) {
                if (d1 >= 0.0) {
                    clip = int(uint(c2da_mem[clip + 16]) | uint(c2da_mem[clip + 17]) << 0x8 | uint(c2da_mem[clip + 18]) << 0x10 | uint(c2da_mem[clip + 19]) << 0x18)
                    if (clip == 0) {
                        break
                    }
                    continue
                }
                cacheoffset = 0x7fffffffu
                f = d0 / (d0 - d1)
                let c2da_fresh49 : float = uint_bits_to_float(uint(c2da_mem[pv0 + 0 * 4]) | uint(c2da_mem[pv0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pv0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pv0 + 0 * 4 + 3]) << 0x18)
                let c2da_fresh27 : float = c2da_fresh49 + f * (uint_bits_to_float(uint(c2da_mem[pv1 + 0 * 4]) | uint(c2da_mem[pv1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pv1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pv1 + 0 * 4 + 3]) << 0x18) - c2da_fresh49)
                let c2da_fresh28 : uint = float_bits_to_uint(c2da_fresh27)
                c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh28)
                c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh28 >> 0x8)
                c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh28 >> 0x10)
                c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh28 >> 0x18)
                let c2da_fresh50 : float = uint_bits_to_float(uint(c2da_mem[pv0 + 1 * 4]) | uint(c2da_mem[pv0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pv0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pv0 + 1 * 4 + 3]) << 0x18)
                let c2da_fresh29 : float = c2da_fresh50 + f * (uint_bits_to_float(uint(c2da_mem[pv1 + 1 * 4]) | uint(c2da_mem[pv1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pv1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pv1 + 1 * 4 + 3]) << 0x18) - c2da_fresh50)
                let c2da_fresh30 : uint = float_bits_to_uint(c2da_fresh29)
                c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh30)
                c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh30 >> 0x8)
                c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh30 >> 0x10)
                c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh30 >> 0x18)
                let c2da_fresh51 : float = uint_bits_to_float(uint(c2da_mem[pv0 + 2 * 4]) | uint(c2da_mem[pv0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pv0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pv0 + 2 * 4 + 3]) << 0x18)
                let c2da_fresh31 : float = c2da_fresh51 + f * (uint_bits_to_float(uint(c2da_mem[pv1 + 2 * 4]) | uint(c2da_mem[pv1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pv1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pv1 + 2 * 4 + 3]) << 0x18) - c2da_fresh51)
                let c2da_fresh32 : uint = float_bits_to_uint(c2da_fresh31)
                c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh32)
                c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh32 >> 0x8)
                c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh32 >> 0x10)
                c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh32 >> 0x18)
                if (c2da_mem[clip + 24] != 0x0) {
                    r_leftclipped = 1u
                    c2da_lin_memmove(391568, c2da_fp, 12ul)
                } elif (c2da_mem[clip + 25] != 0x0) {
                    r_rightclipped = 1u
                    c2da_lin_memmove(391600, c2da_fp, 12ul)
                }
                R_ClipEdge(pv0, c2da_fp, int(uint(c2da_mem[clip + 16]) | uint(c2da_mem[clip + 17]) << 0x8 | uint(c2da_mem[clip + 18]) << 0x10 | uint(c2da_mem[clip + 19]) << 0x18))
                return
            } else {
                if (d1 < 0.0) {
                    if (r_leftclipped == 0u) {
                        cacheoffset = 0x80000000u | uint(r_framecount & 2147483647)
                    }
                    return
                }
                r_lastvertvalid = 0u
                cacheoffset = 0x7fffffffu
                f = d0 / (d0 - d1)
                let c2da_fresh52 : float = uint_bits_to_float(uint(c2da_mem[pv0 + 0 * 4]) | uint(c2da_mem[pv0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pv0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pv0 + 0 * 4 + 3]) << 0x18)
                let c2da_fresh33 : float = c2da_fresh52 + f * (uint_bits_to_float(uint(c2da_mem[pv1 + 0 * 4]) | uint(c2da_mem[pv1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pv1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pv1 + 0 * 4 + 3]) << 0x18) - c2da_fresh52)
                let c2da_fresh34 : uint = float_bits_to_uint(c2da_fresh33)
                c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh34)
                c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh34 >> 0x8)
                c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh34 >> 0x10)
                c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh34 >> 0x18)
                let c2da_fresh53 : float = uint_bits_to_float(uint(c2da_mem[pv0 + 1 * 4]) | uint(c2da_mem[pv0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pv0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pv0 + 1 * 4 + 3]) << 0x18)
                let c2da_fresh35 : float = c2da_fresh53 + f * (uint_bits_to_float(uint(c2da_mem[pv1 + 1 * 4]) | uint(c2da_mem[pv1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pv1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pv1 + 1 * 4 + 3]) << 0x18) - c2da_fresh53)
                let c2da_fresh36 : uint = float_bits_to_uint(c2da_fresh35)
                c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh36)
                c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh36 >> 0x8)
                c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh36 >> 0x10)
                c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh36 >> 0x18)
                let c2da_fresh54 : float = uint_bits_to_float(uint(c2da_mem[pv0 + 2 * 4]) | uint(c2da_mem[pv0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pv0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pv0 + 2 * 4 + 3]) << 0x18)
                let c2da_fresh37 : float = c2da_fresh54 + f * (uint_bits_to_float(uint(c2da_mem[pv1 + 2 * 4]) | uint(c2da_mem[pv1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pv1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pv1 + 2 * 4 + 3]) << 0x18) - c2da_fresh54)
                let c2da_fresh38 : uint = float_bits_to_uint(c2da_fresh37)
                c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh38)
                c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh38 >> 0x8)
                c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh38 >> 0x10)
                c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh38 >> 0x18)
                if (c2da_mem[clip + 24] != 0x0) {
                    r_leftclipped = 1u
                    c2da_lin_memmove(391584, c2da_fp, 12ul)
                } elif (c2da_mem[clip + 25] != 0x0) {
                    r_rightclipped = 1u
                    c2da_lin_memmove(391616, c2da_fp, 12ul)
                }
                R_ClipEdge(c2da_fp, pv1, int(uint(c2da_mem[clip + 16]) | uint(c2da_mem[clip + 17]) << 0x8 | uint(c2da_mem[clip + 18]) << 0x10 | uint(c2da_mem[clip + 19]) << 0x18))
                return
            }
        }
    }
    R_EmitEdge(pv0, pv1)
    return
}
[sideeffects]
def private R_EmitEdge_c2da_frame(var pv0_0 : int; var pv1_0 : int; c2da_fp : int) {
    var edge : int
    var pcheck : int
    var u_check : int
    var u : float
    var u_step : float
    var world : int
    var v : int
    var v2 : int
    var ceilv0 : int
    var lzi0 : float
    var u0 : float
    var v0 : float
    var side : int
    if (r_lastvertvalid != 0u) {
        u0 = r_u1
        v0 = r_v1
        lzi0 = r_lzi1
        ceilv0 = r_ceilv1
    } else {
        world = pv0_0 + 0 * 4
        let c2da_fresh55 : float = uint_bits_to_float(uint(c2da_mem[world + 0 * 4]) | uint(c2da_mem[world + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[world + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[world + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh56 : uint = float_bits_to_uint(c2da_fresh55)
        c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh56)
        c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh56 >> 0x8)
        c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh56 >> 0x10)
        c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh56 >> 0x18)
        let c2da_fresh57 : float = uint_bits_to_float(uint(c2da_mem[world + 1 * 4]) | uint(c2da_mem[world + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[world + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[world + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh58 : uint = float_bits_to_uint(c2da_fresh57)
        c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh58)
        c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh58 >> 0x8)
        c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh58 >> 0x10)
        c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh58 >> 0x18)
        let c2da_fresh59 : float = uint_bits_to_float(uint(c2da_mem[world + 2 * 4]) | uint(c2da_mem[world + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[world + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[world + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh60 : uint = float_bits_to_uint(c2da_fresh59)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh60)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh60 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh60 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh60 >> 0x18)
        TransformVector(c2da_fp, c2da_fp + 16)
        if (double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18)) < 0.01lf) {
            let c2da_fresh61 : float = float(0.01lf)
            let c2da_fresh62 : uint = float_bits_to_uint(c2da_fresh61)
            c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh62)
            c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh62 >> 0x8)
            c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh62 >> 0x10)
            c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh62 >> 0x18)
        }
        lzi0 = float(1.0lf / double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18)))
        u0 = xcenter + xscale * lzi0 * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh107 : float = uint_bits_to_float(uint(c2da_mem[5276]) | uint(c2da_mem[5277]) << 0x8 | uint(c2da_mem[5278]) << 0x10 | uint(c2da_mem[5279]) << 0x18)
        if (u0 < c2da_fresh107) {
            u0 = c2da_fresh107
        }
        let c2da_fresh108 : float = uint_bits_to_float(uint(c2da_mem[5292]) | uint(c2da_mem[5293]) << 0x8 | uint(c2da_mem[5294]) << 0x10 | uint(c2da_mem[5295]) << 0x18)
        if (u0 > c2da_fresh108) {
            u0 = c2da_fresh108
        }
        v0 = ycenter - yscale * lzi0 * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh109 : float = uint_bits_to_float(uint(c2da_mem[5280]) | uint(c2da_mem[5281]) << 0x8 | uint(c2da_mem[5282]) << 0x10 | uint(c2da_mem[5283]) << 0x18)
        if (v0 < c2da_fresh109) {
            v0 = c2da_fresh109
        }
        let c2da_fresh110 : float = uint_bits_to_float(uint(c2da_mem[5296]) | uint(c2da_mem[5297]) << 0x8 | uint(c2da_mem[5298]) << 0x10 | uint(c2da_mem[5299]) << 0x18)
        if (v0 > c2da_fresh110) {
            v0 = c2da_fresh110
        }
        ceilv0 = int(ceil(double(v0)))
    }
    world = pv1_0 + 0 * 4
    let c2da_fresh63 : float = uint_bits_to_float(uint(c2da_mem[world + 0 * 4]) | uint(c2da_mem[world + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[world + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[world + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh64 : uint = float_bits_to_uint(c2da_fresh63)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh64)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh64 >> 0x18)
    let c2da_fresh65 : float = uint_bits_to_float(uint(c2da_mem[world + 1 * 4]) | uint(c2da_mem[world + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[world + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[world + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh66 : uint = float_bits_to_uint(c2da_fresh65)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh66)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh66 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh66 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh66 >> 0x18)
    let c2da_fresh67 : float = uint_bits_to_float(uint(c2da_mem[world + 2 * 4]) | uint(c2da_mem[world + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[world + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[world + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh68 : uint = float_bits_to_uint(c2da_fresh67)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh68)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh68 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh68 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh68 >> 0x18)
    TransformVector(c2da_fp, c2da_fp + 16)
    if (double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18)) < 0.01lf) {
        let c2da_fresh69 : float = float(0.01lf)
        let c2da_fresh70 : uint = float_bits_to_uint(c2da_fresh69)
        c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh70)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh70 >> 0x8)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh70 >> 0x10)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh70 >> 0x18)
    }
    r_lzi1 = float(1.0lf / double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18)))
    r_u1 = xcenter + xscale * r_lzi1 * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh101 : float = uint_bits_to_float(uint(c2da_mem[5276]) | uint(c2da_mem[5277]) << 0x8 | uint(c2da_mem[5278]) << 0x10 | uint(c2da_mem[5279]) << 0x18)
    if (r_u1 < c2da_fresh101) {
        r_u1 = c2da_fresh101
    }
    let c2da_fresh102 : float = uint_bits_to_float(uint(c2da_mem[5292]) | uint(c2da_mem[5293]) << 0x8 | uint(c2da_mem[5294]) << 0x10 | uint(c2da_mem[5295]) << 0x18)
    if (r_u1 > c2da_fresh102) {
        r_u1 = c2da_fresh102
    }
    r_v1 = ycenter - yscale * r_lzi1 * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh103 : float = uint_bits_to_float(uint(c2da_mem[5280]) | uint(c2da_mem[5281]) << 0x8 | uint(c2da_mem[5282]) << 0x10 | uint(c2da_mem[5283]) << 0x18)
    if (r_v1 < c2da_fresh103) {
        r_v1 = c2da_fresh103
    }
    let c2da_fresh104 : float = uint_bits_to_float(uint(c2da_mem[5296]) | uint(c2da_mem[5297]) << 0x8 | uint(c2da_mem[5298]) << 0x10 | uint(c2da_mem[5299]) << 0x18)
    if (r_v1 > c2da_fresh104) {
        r_v1 = c2da_fresh104
    }
    if (r_lzi1 > lzi0) {
        lzi0 = r_lzi1
    }
    if (lzi0 > r_nearzi) {
        r_nearzi = lzi0
    }
    if (r_nearzionly != 0u) {
        return
    }
    r_emitted = 1
    r_ceilv1 = int(ceil(double(r_v1)))
    if (ceilv0 == r_ceilv1) {
        if (cacheoffset != 0x7fffffffu) {
            cacheoffset = 0x80000000u | uint(r_framecount & 2147483647)
        }
        return
    }
    side = ceilv0 > r_ceilv1 ? 1 : 0
    let c2da_fresh71 : int = edge_p
    edge_p = edge_p + 56
    edge = c2da_fresh71
    let c2da_fresh72 : uint = uint(r_pedge)
    c2da_mem[edge + 48] = uint8(c2da_fresh72)
    c2da_mem[edge + 49] = uint8(c2da_fresh72 >> 0x8)
    c2da_mem[edge + 50] = uint8(c2da_fresh72 >> 0x10)
    c2da_mem[edge + 51] = uint8(c2da_fresh72 >> 0x18)
    c2da_mem[edge + 52] = 0u8
    c2da_mem[edge + 53] = 0u8
    c2da_mem[edge + 54] = 0u8
    c2da_mem[edge + 55] = 0u8
    let c2da_fresh73 : uint = float_bits_to_uint(lzi0)
    c2da_mem[edge + 40] = uint8(c2da_fresh73)
    c2da_mem[edge + 41] = uint8(c2da_fresh73 >> 0x8)
    c2da_mem[edge + 42] = uint8(c2da_fresh73 >> 0x10)
    c2da_mem[edge + 43] = uint8(c2da_fresh73 >> 0x18)
    if (side == 0) {
        v = ceilv0
        v2 = r_ceilv1 - 1
        let c2da_fresh74 : uint16 = uint16(int64((surface_p - surfaces) / 88))
        let c2da_fresh75 : uint = uint(c2da_fresh74)
        c2da_mem[edge + 24 + 0 * 2] = uint8(c2da_fresh75)
        c2da_mem[edge + 24 + 0 * 2 + 1] = uint8(c2da_fresh75 >> 0x8)
        let c2da_fresh76 : uint16 = uint16(0)
        let c2da_fresh77 : uint = uint(c2da_fresh76)
        c2da_mem[edge + 24 + 1 * 2] = uint8(c2da_fresh77)
        c2da_mem[edge + 24 + 1 * 2 + 1] = uint8(c2da_fresh77 >> 0x8)
        u_step = (r_u1 - u0) / (r_v1 - v0)
        u = u0 + (float(v) - v0) * u_step
    } else {
        v2 = ceilv0 - 1
        v = r_ceilv1
        let c2da_fresh78 : uint16 = uint16(0)
        let c2da_fresh79 : uint = uint(c2da_fresh78)
        c2da_mem[edge + 24 + 0 * 2] = uint8(c2da_fresh79)
        c2da_mem[edge + 24 + 0 * 2 + 1] = uint8(c2da_fresh79 >> 0x8)
        let c2da_fresh80 : uint16 = uint16(int64((surface_p - surfaces) / 88))
        let c2da_fresh81 : uint = uint(c2da_fresh80)
        c2da_mem[edge + 24 + 1 * 2] = uint8(c2da_fresh81)
        c2da_mem[edge + 24 + 1 * 2 + 1] = uint8(c2da_fresh81 >> 0x8)
        u_step = (u0 - r_u1) / (v0 - r_v1)
        u = r_u1 + (float(v) - r_v1) * u_step
    }
    let c2da_fresh82 : int = int(u_step * 1048576.0)
    let c2da_fresh83 : uint = uint(c2da_fresh82)
    c2da_mem[edge + 4] = uint8(c2da_fresh83)
    c2da_mem[edge + 5] = uint8(c2da_fresh83 >> 0x8)
    c2da_mem[edge + 6] = uint8(c2da_fresh83 >> 0x10)
    c2da_mem[edge + 7] = uint8(c2da_fresh83 >> 0x18)
    let c2da_fresh84 : int = int(u * 1048576.0 + 1048575.0)
    let c2da_fresh85 : uint = uint(c2da_fresh84)
    c2da_mem[edge] = uint8(c2da_fresh85)
    c2da_mem[edge + 1] = uint8(c2da_fresh85 >> 0x8)
    c2da_mem[edge + 2] = uint8(c2da_fresh85 >> 0x10)
    c2da_mem[edge + 3] = uint8(c2da_fresh85 >> 0x18)
    let c2da_fresh105 : int = int(uint(c2da_mem[5284]) | uint(c2da_mem[5285]) << 0x8 | uint(c2da_mem[5286]) << 0x10 | uint(c2da_mem[5287]) << 0x18)
    if (int(uint(c2da_mem[edge]) | uint(c2da_mem[edge + 1]) << 0x8 | uint(c2da_mem[edge + 2]) << 0x10 | uint(c2da_mem[edge + 3]) << 0x18) < c2da_fresh105) {
        let c2da_fresh86 : int = c2da_fresh105
        let c2da_fresh87 : uint = uint(c2da_fresh86)
        c2da_mem[edge] = uint8(c2da_fresh87)
        c2da_mem[edge + 1] = uint8(c2da_fresh87 >> 0x8)
        c2da_mem[edge + 2] = uint8(c2da_fresh87 >> 0x10)
        c2da_mem[edge + 3] = uint8(c2da_fresh87 >> 0x18)
    }
    let c2da_fresh106 : int = int(uint(c2da_mem[5288]) | uint(c2da_mem[5289]) << 0x8 | uint(c2da_mem[5290]) << 0x10 | uint(c2da_mem[5291]) << 0x18)
    if (int(uint(c2da_mem[edge]) | uint(c2da_mem[edge + 1]) << 0x8 | uint(c2da_mem[edge + 2]) << 0x10 | uint(c2da_mem[edge + 3]) << 0x18) > c2da_fresh106) {
        let c2da_fresh88 : int = c2da_fresh106
        let c2da_fresh89 : uint = uint(c2da_fresh88)
        c2da_mem[edge] = uint8(c2da_fresh89)
        c2da_mem[edge + 1] = uint8(c2da_fresh89 >> 0x8)
        c2da_mem[edge + 2] = uint8(c2da_fresh89 >> 0x10)
        c2da_mem[edge + 3] = uint8(c2da_fresh89 >> 0x18)
    }
    u_check = int(uint(c2da_mem[edge]) | uint(c2da_mem[edge + 1]) << 0x8 | uint(c2da_mem[edge + 2]) << 0x10 | uint(c2da_mem[edge + 3]) << 0x18)
    if (uint16(uint(c2da_mem[edge + 24 + 0 * 2]) | uint(c2da_mem[edge + 24 + 0 * 2 + 1]) << 0x8) != 0x0) {
        u_check++
    }
    var c2da_fresh91 : int = 1
    if (!(newedges[v] == 0)) {
        let c2da_fresh90 : int = newedges[v]
        if (!(int(uint(c2da_mem[c2da_fresh90]) | uint(c2da_mem[c2da_fresh90 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh90 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh90 + 3]) << 0x18) >= u_check)) {
            c2da_fresh91 = 0
        }
    }
    if (c2da_fresh91 != 0) {
        let c2da_fresh92 : int = newedges[v]
        let c2da_fresh93 : uint = uint(c2da_fresh92)
        c2da_mem[edge + 16] = uint8(c2da_fresh93)
        c2da_mem[edge + 17] = uint8(c2da_fresh93 >> 0x8)
        c2da_mem[edge + 18] = uint8(c2da_fresh93 >> 0x10)
        c2da_mem[edge + 19] = uint8(c2da_fresh93 >> 0x18)
        c2da_mem[edge + 20] = 0u8
        c2da_mem[edge + 21] = 0u8
        c2da_mem[edge + 22] = 0u8
        c2da_mem[edge + 23] = 0u8
        newedges[v] = edge
    } else {
        pcheck = newedges[v]
        while (true) {
            var c2da_fresh95 : int = 0
            let c2da_fresh111 : int = int(uint(c2da_mem[pcheck + 16]) | uint(c2da_mem[pcheck + 17]) << 0x8 | uint(c2da_mem[pcheck + 18]) << 0x10 | uint(c2da_mem[pcheck + 19]) << 0x18)
            if (c2da_fresh111 != 0) {
                let c2da_fresh94 : int = c2da_fresh111
                if (int(uint(c2da_mem[c2da_fresh94]) | uint(c2da_mem[c2da_fresh94 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh94 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh94 + 3]) << 0x18) < u_check) {
                    c2da_fresh95 = 1
                }
            }
            if (c2da_fresh95 == 0) {
                break
            }
            pcheck = int(uint(c2da_mem[pcheck + 16]) | uint(c2da_mem[pcheck + 17]) << 0x8 | uint(c2da_mem[pcheck + 18]) << 0x10 | uint(c2da_mem[pcheck + 19]) << 0x18)
        }
        let c2da_fresh96 : int = int(uint(c2da_mem[pcheck + 16]) | uint(c2da_mem[pcheck + 17]) << 0x8 | uint(c2da_mem[pcheck + 18]) << 0x10 | uint(c2da_mem[pcheck + 19]) << 0x18)
        let c2da_fresh97 : uint = uint(c2da_fresh96)
        c2da_mem[edge + 16] = uint8(c2da_fresh97)
        c2da_mem[edge + 17] = uint8(c2da_fresh97 >> 0x8)
        c2da_mem[edge + 18] = uint8(c2da_fresh97 >> 0x10)
        c2da_mem[edge + 19] = uint8(c2da_fresh97 >> 0x18)
        c2da_mem[edge + 20] = 0u8
        c2da_mem[edge + 21] = 0u8
        c2da_mem[edge + 22] = 0u8
        c2da_mem[edge + 23] = 0u8
        let c2da_fresh98 : uint = uint(edge)
        c2da_mem[pcheck + 16] = uint8(c2da_fresh98)
        c2da_mem[pcheck + 17] = uint8(c2da_fresh98 >> 0x8)
        c2da_mem[pcheck + 18] = uint8(c2da_fresh98 >> 0x10)
        c2da_mem[pcheck + 19] = uint8(c2da_fresh98 >> 0x18)
        c2da_mem[pcheck + 20] = 0u8
        c2da_mem[pcheck + 21] = 0u8
        c2da_mem[pcheck + 22] = 0u8
        c2da_mem[pcheck + 23] = 0u8
    }
    let c2da_fresh99 : int = removeedges[v2]
    let c2da_fresh100 : uint = uint(c2da_fresh99)
    c2da_mem[edge + 32] = uint8(c2da_fresh100)
    c2da_mem[edge + 33] = uint8(c2da_fresh100 >> 0x8)
    c2da_mem[edge + 34] = uint8(c2da_fresh100 >> 0x10)
    c2da_mem[edge + 35] = uint8(c2da_fresh100 >> 0x18)
    c2da_mem[edge + 36] = 0u8
    c2da_mem[edge + 37] = 0u8
    c2da_mem[edge + 38] = 0u8
    c2da_mem[edge + 39] = 0u8
    removeedges[v2] = edge
    return
}
[sideeffects]
def private R_RenderPoly_c2da_frame(var fa_0 : int; var clipflags_0 : int; c2da_fp : int) {
    var c2da_fresh126 : int
    var i_0 : int
    var lindex_0 : int
    var lnumverts : int
    var s_axis : int
    var t_axis : int
    var dist : float
    var lastdist : float
    var lzi : float
    var u_0 : float
    var v_0 : float
    var frac : float
    var mask_0 : uint
    var pclip_0 : int
    var pedges_0 : int
    var verts : mvertex_t[2][100]
    var vertpage : int
    var newverts : int
    var newpage : int
    var lastvert : int
    var visible : uint
    t_axis = 0
    s_axis = t_axis
    pclip_0 = 0
    i_0 = 3
    mask_0 = 0x8u
    while (i_0 >= 0) {
        if ((uint(clipflags_0) & mask_0) != 0x0) {
            let c2da_fresh117 : uint = uint(pclip_0)
            c2da_mem[391440 + i_0 * 32 + 16] = uint8(c2da_fresh117)
            c2da_mem[391440 + i_0 * 32 + 17] = uint8(c2da_fresh117 >> 0x8)
            c2da_mem[391440 + i_0 * 32 + 18] = uint8(c2da_fresh117 >> 0x10)
            c2da_mem[391440 + i_0 * 32 + 19] = uint8(c2da_fresh117 >> 0x18)
            c2da_mem[391440 + i_0 * 32 + 20] = 0u8
            c2da_mem[391440 + i_0 * 32 + 21] = 0u8
            c2da_mem[391440 + i_0 * 32 + 22] = 0u8
            c2da_mem[391440 + i_0 * 32 + 23] = 0u8
            pclip_0 = 391440 + i_0 * 32
        }
        i_0--
        mask_0 >>= 1u
    }
    let c2da_fresh118 : int = int(uint(c2da_mem[currententity + 136]) | uint(c2da_mem[currententity + 137]) << 0x8 | uint(c2da_mem[currententity + 138]) << 0x10 | uint(c2da_mem[currententity + 139]) << 0x18) + 192
    pedges_0 = int(uint(c2da_mem[c2da_fresh118]) | uint(c2da_mem[c2da_fresh118 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh118 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh118 + 3]) << 0x18)
    lnumverts = int(uint(c2da_mem[fa_0 + 32]) | uint(c2da_mem[fa_0 + 33]) << 0x8 | uint(c2da_mem[fa_0 + 34]) << 0x10 | uint(c2da_mem[fa_0 + 35]) << 0x18)
    vertpage = 0
    i_0 = 0
    while (i_0 < lnumverts) {
        let c2da_fresh119 : int = int(uint(c2da_mem[currententity + 136]) | uint(c2da_mem[currententity + 137]) << 0x8 | uint(c2da_mem[currententity + 138]) << 0x10 | uint(c2da_mem[currententity + 139]) << 0x18) + 256
        let c2da_fresh120 : int = int(uint(c2da_mem[c2da_fresh119]) | uint(c2da_mem[c2da_fresh119 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh119 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh119 + 3]) << 0x18) + (int(uint(c2da_mem[fa_0 + 28]) | uint(c2da_mem[fa_0 + 29]) << 0x8 | uint(c2da_mem[fa_0 + 30]) << 0x10 | uint(c2da_mem[fa_0 + 31]) << 0x18) + i_0) * 4
        lindex_0 = int(uint(c2da_mem[c2da_fresh120]) | uint(c2da_mem[c2da_fresh120 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh120 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh120 + 3]) << 0x18)
        if (lindex_0 > 0) {
            r_pedge = pedges_0 + lindex_0 * 8
            let c2da_fresh121 : int = r_pcurrentvertbase + int(uint16(uint(c2da_mem[r_pedge + 0 * 2]) | uint(c2da_mem[r_pedge + 0 * 2 + 1]) << 0x8)) * 12
            var c2da_fresh122 : mvertex_t
            c2da_fresh122.position[0] = uint_bits_to_float(uint(c2da_mem[c2da_fresh121]) | uint(c2da_mem[c2da_fresh121 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh121 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh121 + 3]) << 0x18)
            c2da_fresh122.position[1] = uint_bits_to_float(uint(c2da_mem[c2da_fresh121 + 4]) | uint(c2da_mem[c2da_fresh121 + 5]) << 0x8 | uint(c2da_mem[c2da_fresh121 + 6]) << 0x10 | uint(c2da_mem[c2da_fresh121 + 7]) << 0x18)
            c2da_fresh122.position[2] = uint_bits_to_float(uint(c2da_mem[c2da_fresh121 + 8]) | uint(c2da_mem[c2da_fresh121 + 9]) << 0x8 | uint(c2da_mem[c2da_fresh121 + 10]) << 0x10 | uint(c2da_mem[c2da_fresh121 + 11]) << 0x18)
            verts[0][i_0] = c2da_fresh122
        } else {
            r_pedge = pedges_0 + -lindex_0 * 8
            let c2da_fresh123 : int = r_pcurrentvertbase + int(uint16(uint(c2da_mem[r_pedge + 1 * 2]) | uint(c2da_mem[r_pedge + 1 * 2 + 1]) << 0x8)) * 12
            var c2da_fresh124 : mvertex_t
            c2da_fresh124.position[0] = uint_bits_to_float(uint(c2da_mem[c2da_fresh123]) | uint(c2da_mem[c2da_fresh123 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh123 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh123 + 3]) << 0x18)
            c2da_fresh124.position[1] = uint_bits_to_float(uint(c2da_mem[c2da_fresh123 + 4]) | uint(c2da_mem[c2da_fresh123 + 5]) << 0x8 | uint(c2da_mem[c2da_fresh123 + 6]) << 0x10 | uint(c2da_mem[c2da_fresh123 + 7]) << 0x18)
            c2da_fresh124.position[2] = uint_bits_to_float(uint(c2da_mem[c2da_fresh123 + 8]) | uint(c2da_mem[c2da_fresh123 + 9]) << 0x8 | uint(c2da_mem[c2da_fresh123 + 10]) << 0x10 | uint(c2da_mem[c2da_fresh123 + 11]) << 0x18)
            verts[0][i_0] = c2da_fresh124
        }
        i_0++
    }
    while (pclip_0 != 0) {
        lastvert = lnumverts - 1
        lastdist = verts[vertpage][lastvert].position[0] * uint_bits_to_float(uint(c2da_mem[pclip_0 + 0 * 4]) | uint(c2da_mem[pclip_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pclip_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pclip_0 + 0 * 4 + 3]) << 0x18) + verts[vertpage][lastvert].position[1] * uint_bits_to_float(uint(c2da_mem[pclip_0 + 1 * 4]) | uint(c2da_mem[pclip_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pclip_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pclip_0 + 1 * 4 + 3]) << 0x18) + verts[vertpage][lastvert].position[2] * uint_bits_to_float(uint(c2da_mem[pclip_0 + 2 * 4]) | uint(c2da_mem[pclip_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pclip_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pclip_0 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[pclip_0 + 12]) | uint(c2da_mem[pclip_0 + 13]) << 0x8 | uint(c2da_mem[pclip_0 + 14]) << 0x10 | uint(c2da_mem[pclip_0 + 15]) << 0x18)
        visible = 0u
        newverts = 0
        newpage = vertpage ^ 1
        i_0 = 0
        while (i_0 < lnumverts) {
            dist = verts[vertpage][i_0].position[0] * uint_bits_to_float(uint(c2da_mem[pclip_0 + 0 * 4]) | uint(c2da_mem[pclip_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pclip_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pclip_0 + 0 * 4 + 3]) << 0x18) + verts[vertpage][i_0].position[1] * uint_bits_to_float(uint(c2da_mem[pclip_0 + 1 * 4]) | uint(c2da_mem[pclip_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pclip_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pclip_0 + 1 * 4 + 3]) << 0x18) + verts[vertpage][i_0].position[2] * uint_bits_to_float(uint(c2da_mem[pclip_0 + 2 * 4]) | uint(c2da_mem[pclip_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pclip_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pclip_0 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[pclip_0 + 12]) | uint(c2da_mem[pclip_0 + 13]) << 0x8 | uint(c2da_mem[pclip_0 + 14]) << 0x10 | uint(c2da_mem[pclip_0 + 15]) << 0x18)
            if ((lastdist > 0.0 ? 1 : 0) != (dist > 0.0 ? 1 : 0)) {
                frac = dist / (dist - lastdist)
                verts[newpage][newverts].position[0] = verts[vertpage][i_0].position[0] + (verts[vertpage][lastvert].position[0] - verts[vertpage][i_0].position[0]) * frac
                verts[newpage][newverts].position[1] = verts[vertpage][i_0].position[1] + (verts[vertpage][lastvert].position[1] - verts[vertpage][i_0].position[1]) * frac
                verts[newpage][newverts].position[2] = verts[vertpage][i_0].position[2] + (verts[vertpage][lastvert].position[2] - verts[vertpage][i_0].position[2]) * frac
                newverts++
            }
            if (dist >= 0.0) {
                verts[newpage][newverts] = verts[vertpage][i_0]
                newverts++
                visible = 1u
            }
            lastvert = i_0
            lastdist = dist
            i_0++
        }
        if (visible == 0u || newverts < 3) {
            return
        }
        lnumverts = newverts
        vertpage ^= 1
        pclip_0 = int(uint(c2da_mem[pclip_0 + 16]) | uint(c2da_mem[pclip_0 + 17]) << 0x8 | uint(c2da_mem[pclip_0 + 18]) << 0x10 | uint(c2da_mem[pclip_0 + 19]) << 0x18)
    }
    let c2da_fresh125 : int = int(uint(c2da_mem[fa_0 + 16]) | uint(c2da_mem[fa_0 + 17]) << 0x8 | uint(c2da_mem[fa_0 + 18]) << 0x10 | uint(c2da_mem[fa_0 + 19]) << 0x18) + 16
    c2da_fresh126 = int(c2da_mem[c2da_fresh125])
    if (c2da_fresh126 == 0 || c2da_fresh126 == 3) {
        s_axis = 1
        t_axis = 2
    } elif (c2da_fresh126 == 1 || c2da_fresh126 == 4) {
        s_axis = 0
        t_axis = 2
    } elif (c2da_fresh126 == 2 || c2da_fresh126 == 5) {
        s_axis = 0
        t_axis = 1
    }
    r_nearzi = 0.0
    i_0 = 0
    for (c2da_i_0 in range(i_0, lnumverts)) {
        let c2da_fresh127 : float = verts[vertpage][c2da_i_0].position[0] - uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh128 : uint = float_bits_to_uint(c2da_fresh127)
        c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh128)
        c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh128 >> 0x8)
        c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh128 >> 0x10)
        c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh128 >> 0x18)
        let c2da_fresh129 : float = verts[vertpage][c2da_i_0].position[1] - uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh130 : uint = float_bits_to_uint(c2da_fresh129)
        c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh130)
        c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh130 >> 0x8)
        c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh130 >> 0x10)
        c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh130 >> 0x18)
        let c2da_fresh131 : float = verts[vertpage][c2da_i_0].position[2] - uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh132 : uint = float_bits_to_uint(c2da_fresh131)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh132)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh132 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh132 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh132 >> 0x18)
        TransformVector(c2da_fp, c2da_fp + 16)
        if (double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18)) < 0.01lf) {
            let c2da_fresh133 : float = float(0.01lf)
            let c2da_fresh134 : uint = float_bits_to_uint(c2da_fresh133)
            c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh134)
            c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh134 >> 0x8)
            c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh134 >> 0x10)
            c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh134 >> 0x18)
        }
        lzi = float(1.0lf / double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18)))
        if (lzi > r_nearzi) {
            r_nearzi = lzi
        }
        u_0 = xcenter + xscale * lzi * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh142 : float = uint_bits_to_float(uint(c2da_mem[5276]) | uint(c2da_mem[5277]) << 0x8 | uint(c2da_mem[5278]) << 0x10 | uint(c2da_mem[5279]) << 0x18)
        if (u_0 < c2da_fresh142) {
            u_0 = c2da_fresh142
        }
        let c2da_fresh143 : float = uint_bits_to_float(uint(c2da_mem[5292]) | uint(c2da_mem[5293]) << 0x8 | uint(c2da_mem[5294]) << 0x10 | uint(c2da_mem[5295]) << 0x18)
        if (u_0 > c2da_fresh143) {
            u_0 = c2da_fresh143
        }
        v_0 = ycenter - yscale * lzi * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh144 : float = uint_bits_to_float(uint(c2da_mem[5280]) | uint(c2da_mem[5281]) << 0x8 | uint(c2da_mem[5282]) << 0x10 | uint(c2da_mem[5283]) << 0x18)
        if (v_0 < c2da_fresh144) {
            v_0 = c2da_fresh144
        }
        let c2da_fresh145 : float = uint_bits_to_float(uint(c2da_mem[5296]) | uint(c2da_mem[5297]) << 0x8 | uint(c2da_mem[5298]) << 0x10 | uint(c2da_mem[5299]) << 0x18)
        if (v_0 > c2da_fresh145) {
            v_0 = c2da_fresh145
        }
        let c2da_fresh135 : uint = float_bits_to_uint(u_0)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20] = uint8(c2da_fresh135)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 1] = uint8(c2da_fresh135 >> 0x8)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 2] = uint8(c2da_fresh135 >> 0x10)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 3] = uint8(c2da_fresh135 >> 0x18)
        let c2da_fresh136 : uint = float_bits_to_uint(v_0)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 4] = uint8(c2da_fresh136)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 5] = uint8(c2da_fresh136 >> 0x8)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 6] = uint8(c2da_fresh136 >> 0x10)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 7] = uint8(c2da_fresh136 >> 0x18)
        let c2da_fresh137 : uint = float_bits_to_uint(lzi)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 8] = uint8(c2da_fresh137)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 9] = uint8(c2da_fresh137 >> 0x8)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 10] = uint8(c2da_fresh137 >> 0x10)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 11] = uint8(c2da_fresh137 >> 0x18)
        let c2da_fresh138 : float = verts[vertpage][c2da_i_0].position[s_axis]
        let c2da_fresh139 : uint = float_bits_to_uint(c2da_fresh138)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 12] = uint8(c2da_fresh139)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 13] = uint8(c2da_fresh139 >> 0x8)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 14] = uint8(c2da_fresh139 >> 0x10)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 15] = uint8(c2da_fresh139 >> 0x18)
        let c2da_fresh140 : float = verts[vertpage][c2da_i_0].position[t_axis]
        let c2da_fresh141 : uint = float_bits_to_uint(c2da_fresh140)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 16] = uint8(c2da_fresh141)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 17] = uint8(c2da_fresh141 >> 0x8)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 18] = uint8(c2da_fresh141 >> 0x10)
        c2da_mem[c2da_fp + 32 + c2da_i_0 * 20 + 19] = uint8(c2da_fresh141 >> 0x18)
    }
    r_polydesc.numverts = lnumverts
    r_polydesc.nearzi = float(r_nearzi)  // nolint:PERF020
    r_polydesc.pcurrentface = int(fa_0)  // nolint:PERF020
    r_polydesc.pverts = c2da_fp + 32
    D_DrawPoly()
    return
}
[sideeffects]
def private R_RenderBmodelFace_c2da_frame(var pedges_1 : int; var psurf : int; c2da_fp : int) {
    var i_1 : int
    var mask_1 : uint
    var pplane_1 : int
    var distinv_0 : float
    var pclip_1 : int
    if (surface_p >= surf_max) {
        r_outofsurfaces = r_outofsurfaces + 1
        return
    }
    let c2da_fresh164 : int = int(uint(c2da_mem[psurf + 32]) | uint(c2da_mem[psurf + 33]) << 0x8 | uint(c2da_mem[psurf + 34]) << 0x10 | uint(c2da_mem[psurf + 35]) << 0x18)
    if (edge_p + c2da_fresh164 * 56 + 4 * 56 >= edge_max) {
        r_outofedges = r_outofedges + c2da_fresh164
        return
    }
    c_faceclip++
    r_pedge = int(c2da_fp)  // nolint:PERF020
    pclip_1 = 0
    i_1 = 3
    mask_1 = 0x8u
    while (i_1 >= 0) {
        if ((uint(r_clipflags) & mask_1) != 0x0) {
            let c2da_fresh146 : uint = uint(pclip_1)
            c2da_mem[391440 + i_1 * 32 + 16] = uint8(c2da_fresh146)
            c2da_mem[391440 + i_1 * 32 + 17] = uint8(c2da_fresh146 >> 0x8)
            c2da_mem[391440 + i_1 * 32 + 18] = uint8(c2da_fresh146 >> 0x10)
            c2da_mem[391440 + i_1 * 32 + 19] = uint8(c2da_fresh146 >> 0x18)
            c2da_mem[391440 + i_1 * 32 + 20] = 0u8
            c2da_mem[391440 + i_1 * 32 + 21] = 0u8
            c2da_mem[391440 + i_1 * 32 + 22] = 0u8
            c2da_mem[391440 + i_1 * 32 + 23] = 0u8
            pclip_1 = 391440 + i_1 * 32
        }
        i_1--
        mask_1 >>= 1u
    }
    r_emitted = 0
    r_nearzi = 0.0
    r_nearzionly = 0u
    makerightedge = 0u
    makeleftedge = uint(makerightedge)  // nolint:PERF020
    r_lastvertvalid = 0u
    while (pedges_1 != 0) {
        r_rightclipped = 0u
        r_leftclipped = uint(r_rightclipped)  // nolint:PERF020
        R_ClipEdge(int(uint(c2da_mem[pedges_1 + 0 * 8]) | uint(c2da_mem[pedges_1 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[pedges_1 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[pedges_1 + 0 * 8 + 3]) << 0x18), int(uint(c2da_mem[pedges_1 + 1 * 8]) | uint(c2da_mem[pedges_1 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[pedges_1 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[pedges_1 + 1 * 8 + 3]) << 0x18), pclip_1)
        if (r_leftclipped != 0u) {
            makeleftedge = 1u
        }
        if (r_rightclipped != 0u) {
            makerightedge = 1u
        }
        pedges_1 = int(uint(c2da_mem[pedges_1 + 16]) | uint(c2da_mem[pedges_1 + 17]) << 0x8 | uint(c2da_mem[pedges_1 + 18]) << 0x10 | uint(c2da_mem[pedges_1 + 19]) << 0x18)
    }
    if (makeleftedge != 0u) {
        r_pedge = int(c2da_fp)  // nolint:PERF020
        R_ClipEdge(391568, 391584, int(uint(c2da_mem[pclip_1 + 16]) | uint(c2da_mem[pclip_1 + 17]) << 0x8 | uint(c2da_mem[pclip_1 + 18]) << 0x10 | uint(c2da_mem[pclip_1 + 19]) << 0x18))
    }
    if (makerightedge != 0u) {
        r_pedge = int(c2da_fp)  // nolint:PERF020
        r_nearzionly = 1u
        R_ClipEdge(391600, 391616, int(uint(c2da_mem[391440 + 1 * 32 + 16]) | uint(c2da_mem[391440 + 1 * 32 + 17]) << 0x8 | uint(c2da_mem[391440 + 1 * 32 + 18]) << 0x10 | uint(c2da_mem[391440 + 1 * 32 + 19]) << 0x18))
    }
    if (r_emitted == 0) {
        return
    }
    r_polycount = r_polycount + 1
    let c2da_fresh147 : uint = uint(psurf)
    c2da_mem[surface_p + 40] = uint8(c2da_fresh147)
    c2da_mem[surface_p + 41] = uint8(c2da_fresh147 >> 0x8)
    c2da_mem[surface_p + 42] = uint8(c2da_fresh147 >> 0x10)
    c2da_mem[surface_p + 43] = uint8(c2da_fresh147 >> 0x18)
    c2da_mem[surface_p + 44] = 0u8
    c2da_mem[surface_p + 45] = 0u8
    c2da_mem[surface_p + 46] = 0u8
    c2da_mem[surface_p + 47] = 0u8
    let c2da_fresh148 : uint = float_bits_to_uint(r_nearzi)
    c2da_mem[surface_p + 56] = uint8(c2da_fresh148)
    c2da_mem[surface_p + 57] = uint8(c2da_fresh148 >> 0x8)
    c2da_mem[surface_p + 58] = uint8(c2da_fresh148 >> 0x10)
    c2da_mem[surface_p + 59] = uint8(c2da_fresh148 >> 0x18)
    let c2da_fresh149 : int = int(uint(c2da_mem[psurf + 24]) | uint(c2da_mem[psurf + 25]) << 0x8 | uint(c2da_mem[psurf + 26]) << 0x10 | uint(c2da_mem[psurf + 27]) << 0x18)
    let c2da_fresh150 : uint = uint(c2da_fresh149)
    c2da_mem[surface_p + 36] = uint8(c2da_fresh150)
    c2da_mem[surface_p + 37] = uint8(c2da_fresh150 >> 0x8)
    c2da_mem[surface_p + 38] = uint8(c2da_fresh150 >> 0x10)
    c2da_mem[surface_p + 39] = uint8(c2da_fresh150 >> 0x18)
    let c2da_fresh151 : uint = 1u
    let c2da_fresh152 : uint = c2da_fresh151
    c2da_mem[surface_p + 60] = uint8(c2da_fresh152)
    c2da_mem[surface_p + 61] = uint8(c2da_fresh152 >> 0x8)
    c2da_mem[surface_p + 62] = uint8(c2da_fresh152 >> 0x10)
    c2da_mem[surface_p + 63] = uint8(c2da_fresh152 >> 0x18)
    let c2da_fresh153 : int = 0
    let c2da_fresh154 : uint = uint(c2da_fresh153)
    c2da_mem[surface_p + 32] = uint8(c2da_fresh154)
    c2da_mem[surface_p + 33] = uint8(c2da_fresh154 >> 0x8)
    c2da_mem[surface_p + 34] = uint8(c2da_fresh154 >> 0x10)
    c2da_mem[surface_p + 35] = uint8(c2da_fresh154 >> 0x18)
    let c2da_fresh155 : uint = uint(currententity)
    c2da_mem[surface_p + 48] = uint8(c2da_fresh155)
    c2da_mem[surface_p + 49] = uint8(c2da_fresh155 >> 0x8)
    c2da_mem[surface_p + 50] = uint8(c2da_fresh155 >> 0x10)
    c2da_mem[surface_p + 51] = uint8(c2da_fresh155 >> 0x18)
    c2da_mem[surface_p + 52] = 0u8
    c2da_mem[surface_p + 53] = 0u8
    c2da_mem[surface_p + 54] = 0u8
    c2da_mem[surface_p + 55] = 0u8
    let c2da_fresh156 : uint = uint(r_currentbkey)
    c2da_mem[surface_p + 24] = uint8(c2da_fresh156)
    c2da_mem[surface_p + 25] = uint8(c2da_fresh156 >> 0x8)
    c2da_mem[surface_p + 26] = uint8(c2da_fresh156 >> 0x10)
    c2da_mem[surface_p + 27] = uint8(c2da_fresh156 >> 0x18)
    let c2da_fresh157 : uint = 0u
    c2da_mem[surface_p + 16] = uint8(c2da_fresh157)
    c2da_mem[surface_p + 17] = uint8(c2da_fresh157 >> 0x8)
    c2da_mem[surface_p + 18] = uint8(c2da_fresh157 >> 0x10)
    c2da_mem[surface_p + 19] = uint8(c2da_fresh157 >> 0x18)
    c2da_mem[surface_p + 20] = 0u8
    c2da_mem[surface_p + 21] = 0u8
    c2da_mem[surface_p + 22] = 0u8
    c2da_mem[surface_p + 23] = 0u8
    pplane_1 = int(uint(c2da_mem[psurf + 16]) | uint(c2da_mem[psurf + 17]) << 0x8 | uint(c2da_mem[psurf + 18]) << 0x10 | uint(c2da_mem[psurf + 19]) << 0x18)
    TransformVector(pplane_1, c2da_fp + 16)
    distinv_0 = float(1.0lf / double(uint_bits_to_float(uint(c2da_mem[pplane_1 + 12]) | uint(c2da_mem[pplane_1 + 13]) << 0x8 | uint(c2da_mem[pplane_1 + 14]) << 0x10 | uint(c2da_mem[pplane_1 + 15]) << 0x18) - (uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane_1 + 0 * 4]) | uint(c2da_mem[pplane_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane_1 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane_1 + 1 * 4]) | uint(c2da_mem[pplane_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane_1 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pplane_1 + 2 * 4]) | uint(c2da_mem[pplane_1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pplane_1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pplane_1 + 2 * 4 + 3]) << 0x18))))
    let c2da_fresh158 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18) * xscaleinv * distinv_0
    let c2da_fresh159 : uint = float_bits_to_uint(c2da_fresh158)
    c2da_mem[surface_p + 68] = uint8(c2da_fresh159)
    c2da_mem[surface_p + 69] = uint8(c2da_fresh159 >> 0x8)
    c2da_mem[surface_p + 70] = uint8(c2da_fresh159 >> 0x10)
    c2da_mem[surface_p + 71] = uint8(c2da_fresh159 >> 0x18)
    let c2da_fresh160 : float = -uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18) * yscaleinv * distinv_0
    let c2da_fresh161 : uint = float_bits_to_uint(c2da_fresh160)
    c2da_mem[surface_p + 72] = uint8(c2da_fresh161)
    c2da_mem[surface_p + 73] = uint8(c2da_fresh161 >> 0x8)
    c2da_mem[surface_p + 74] = uint8(c2da_fresh161 >> 0x10)
    c2da_mem[surface_p + 75] = uint8(c2da_fresh161 >> 0x18)
    let c2da_fresh162 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18) * distinv_0 - xcenter * c2da_fresh158 - ycenter * c2da_fresh160
    let c2da_fresh163 : uint = float_bits_to_uint(c2da_fresh162)
    c2da_mem[surface_p + 64] = uint8(c2da_fresh163)
    c2da_mem[surface_p + 65] = uint8(c2da_fresh163 >> 0x8)
    c2da_mem[surface_p + 66] = uint8(c2da_fresh163 >> 0x10)
    c2da_mem[surface_p + 67] = uint8(c2da_fresh163 >> 0x18)
    surface_p = surface_p + 88
    return
}
