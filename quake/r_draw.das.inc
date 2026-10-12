var r_zpointdesc : zpointdesc_t = default<zpointdesc_t>

var r_polydesc : polydesc_s = default<polydesc_s>

var sintable : int[1408]

var intsintable : int[1408]

var view_clipplanes : clipplane_s[4]

[export, sideeffects]
def R_RenderFace(var fa : msurface_s?; var clipflags : int) {
    var i : int
    var lindex : int
    var mask : uint
    var pplane : mplane_s?
    var distinv : float
    var p_normal : vec3_t
    var pedges : medge_t?
    var tedge : medge_t
    var pclip : clipplane_s?
    if (unsafe(reinterpret<uint64>(surface_p)) >= unsafe(reinterpret<uint64>(surf_max))) {
        r_outofsurfaces = r_outofsurfaces + 1
        return
    }
    var c2da_fresh0 : edge_s? = unsafe(unsafe(edge_p + fa.numedges) + 4)
    if (unsafe(reinterpret<uint64>(c2da_fresh0)) >= unsafe(reinterpret<uint64>(edge_max))) {
        r_outofedges = r_outofedges + fa.numedges
        return
    }
    c_faceclip++
    pclip = null
    i = 3
    mask = 0x8u
    while (i >= 0) {
        if ((uint(clipflags) & mask) != 0x0) {
            view_clipplanes[i].next = unsafe(reinterpret<clipplane_s?>(pclip))
            pclip = unsafe(addr<clipplane_s?>(unsafe(unsafe(addr(view_clipplanes[0]))[i])))
        }
        i--
        mask >>= 1u
    }
    r_emitted = 0
    r_nearzi = 0.0
    r_nearzionly = unsafe(reinterpret<qboolean>(0u))
    makerightedge = unsafe(reinterpret<qboolean>(0u))
    makeleftedge = makerightedge
    pedges = unsafe(reinterpret<medge_t?>(currententity.model.edges))
    r_lastvertvalid = unsafe(reinterpret<qboolean>(0u))
    i = 0
    while (i < fa.numedges) {
        lindex = unsafe(currententity.model.surfedges[fa.firstedge + i])
        if (lindex > 0) {
            r_pedge = unsafe(addr<medge_t?>(unsafe(pedges[lindex])))
            if (uint(insubmodel) == 0u) {
                if ((r_pedge.cachededgeoffset & 0x80000000u) != 0x0) {
                    if ((r_pedge.cachededgeoffset & 0x7fffffffu) == uint(r_framecount)) {
                        r_lastvertvalid = unsafe(reinterpret<qboolean>(0u))
                        i++
                        continue
                    }
                } elif (unsafe(reinterpret<uint64>(edge_p)) - unsafe(reinterpret<uint64>(r_edges)) > uint64(r_pedge.cachededgeoffset) && unsafe(reinterpret<edge_s?>(unsafe(reinterpret<uint64>(r_edges)) + uint64(r_pedge.cachededgeoffset))).owner == r_pedge) {
                    R_EmitCachedEdge()
                    r_lastvertvalid = unsafe(reinterpret<qboolean>(0u))
                    i++
                    continue
                }
            }
            cacheoffset = uint(unsafe(unsafe(reinterpret<uint8?>(edge_p)) - unsafe(reinterpret<uint8?>(r_edges))))
            r_rightclipped = unsafe(reinterpret<qboolean>(0u))
            r_leftclipped = r_rightclipped
            var c2da_fresh1 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(r_pedge))))
            var c2da_fresh2 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(r_pedge))))
            R_ClipEdge(unsafe(addr<mvertex_t?>(unsafe(r_pcurrentvertbase[int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh1))[0]))]))), unsafe(addr<mvertex_t?>(unsafe(r_pcurrentvertbase[int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh2))[1]))]))), pclip)
            r_pedge.cachededgeoffset = uint(cacheoffset)  // nolint:PERF020
            if (uint(r_leftclipped) != 0u) {
                makeleftedge = unsafe(reinterpret<qboolean>(1u))
            }
            if (uint(r_rightclipped) != 0u) {
                makerightedge = unsafe(reinterpret<qboolean>(1u))
            }
            r_lastvertvalid = unsafe(reinterpret<qboolean>(1u))
        } else {
            lindex = -lindex
            r_pedge = unsafe(addr<medge_t?>(unsafe(pedges[lindex])))
            if (uint(insubmodel) == 0u) {
                if ((r_pedge.cachededgeoffset & 0x80000000u) != 0x0) {
                    if ((r_pedge.cachededgeoffset & 0x7fffffffu) == uint(r_framecount)) {
                        r_lastvertvalid = unsafe(reinterpret<qboolean>(0u))
                        i++
                        continue
                    }
                } elif (unsafe(reinterpret<uint64>(edge_p)) - unsafe(reinterpret<uint64>(r_edges)) > uint64(r_pedge.cachededgeoffset) && unsafe(reinterpret<edge_s?>(unsafe(reinterpret<uint64>(r_edges)) + uint64(r_pedge.cachededgeoffset))).owner == r_pedge) {
                    R_EmitCachedEdge()
                    r_lastvertvalid = unsafe(reinterpret<qboolean>(0u))
                    i++
                    continue
                }
            }
            cacheoffset = uint(unsafe(unsafe(reinterpret<uint8?>(edge_p)) - unsafe(reinterpret<uint8?>(r_edges))))
            r_rightclipped = unsafe(reinterpret<qboolean>(0u))
            r_leftclipped = r_rightclipped
            var c2da_fresh3 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(r_pedge))))
            var c2da_fresh4 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(r_pedge))))
            R_ClipEdge(unsafe(addr<mvertex_t?>(unsafe(r_pcurrentvertbase[int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh3))[1]))]))), unsafe(addr<mvertex_t?>(unsafe(r_pcurrentvertbase[int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh4))[0]))]))), pclip)
            r_pedge.cachededgeoffset = uint(cacheoffset)  // nolint:PERF020
            if (uint(r_leftclipped) != 0u) {
                makeleftedge = unsafe(reinterpret<qboolean>(1u))
            }
            if (uint(r_rightclipped) != 0u) {
                makerightedge = unsafe(reinterpret<qboolean>(1u))
            }
            r_lastvertvalid = unsafe(reinterpret<qboolean>(1u))
        }
        i++
    }
    if (uint(makeleftedge) != 0u) {
        r_pedge = unsafe(addr<medge_t?>(tedge))
        r_lastvertvalid = unsafe(reinterpret<qboolean>(0u))
        R_ClipEdge(unsafe(addr<mvertex_t?>(r_leftexit)), unsafe(addr<mvertex_t?>(r_leftenter)), pclip.next)
    }
    if (uint(makerightedge) != 0u) {
        r_pedge = unsafe(addr<medge_t?>(tedge))
        r_lastvertvalid = unsafe(reinterpret<qboolean>(0u))
        r_nearzionly = unsafe(reinterpret<qboolean>(1u))
        R_ClipEdge(unsafe(addr<mvertex_t?>(r_rightexit)), unsafe(addr<mvertex_t?>(r_rightenter)), view_clipplanes[1].next)
    }
    if (r_emitted == 0) {
        return
    }
    r_polycount = r_polycount + 1
    surface_p.data = unsafe(reinterpret<uint8?>(fa))
    surface_p.nearzi = r_nearzi
    surface_p.flags = fa.flags
    surface_p.insubmodel = insubmodel
    surface_p.spanstate = 0
    surface_p.entity = currententity
    let c2da_postinc : int = r_currentkey
    r_currentkey = r_currentkey + 1
    surface_p.key = c2da_postinc
    surface_p.spans = null
    pplane = unsafe(reinterpret<mplane_s?>(fa.plane))
    var c2da_fresh5 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane))))
    TransformVector(unsafe(reinterpret<float?>(c2da_fresh5)), unsafe(addr<float?>(p_normal[0])))
    var c2da_fresh6 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane))))
    var c2da_fresh7 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane))))
    var c2da_fresh8 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane))))
    distinv = float(1.0lf / double(pplane.dist - (unsafe(unsafe(addr(modelorg[0]))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh6))[0]) + unsafe(unsafe(addr(modelorg[0]))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh7))[1]) + unsafe(unsafe(addr(modelorg[0]))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh8))[2]))))
    surface_p.d_zistepu = unsafe(unsafe(addr(p_normal[0]))[0]) * xscaleinv * distinv
    surface_p.d_zistepv = -unsafe(unsafe(addr(p_normal[0]))[1]) * yscaleinv * distinv
    surface_p.d_ziorigin = unsafe(unsafe(addr(p_normal[0]))[2]) * distinv - xcenter * surface_p.d_zistepu - ycenter * surface_p.d_zistepv
    surface_p = unsafe(surface_p + 1)
    return
}
var r_nearzi : float = default<float>

var r_emitted : int = default<int>

var r_rightenter : mvertex_t = default<mvertex_t>

var r_rightexit : mvertex_t = default<mvertex_t>

[export, sideeffects]
def R_ClipEdge(var pv0 : mvertex_t?; var pv1 : mvertex_t?; var clip : clipplane_s?) {
    var d0 : float
    var d1 : float
    var f : float
    var clipvert : mvertex_t
    if (clip != null) {
        while (true) {
            var c2da_fresh9 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
            var c2da_fresh10 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip))))
            var c2da_fresh11 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
            var c2da_fresh12 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip))))
            var c2da_fresh13 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
            var c2da_fresh14 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip))))
            d0 = unsafe(unsafe(reinterpret<float?>(c2da_fresh9))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh10))[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh11))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh12))[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh13))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh14))[2]) - clip.dist
            var c2da_fresh15 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv1))))
            var c2da_fresh16 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip))))
            var c2da_fresh17 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv1))))
            var c2da_fresh18 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip))))
            var c2da_fresh19 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv1))))
            var c2da_fresh20 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip))))
            d1 = unsafe(unsafe(reinterpret<float?>(c2da_fresh15))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh16))[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh17))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh18))[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh19))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh20))[2]) - clip.dist
            if (d0 >= 0.0) {
                if (d1 >= 0.0) {
                    clip = unsafe(reinterpret<clipplane_s?>(clip.next))
                    if (clip == null) {
                        break
                    }
                    continue
                }
                cacheoffset = 0x7fffffffu
                f = d0 / (d0 - d1)
                var c2da_fresh21 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
                var c2da_fresh22 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv1))))
                var c2da_fresh23 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
                unsafe(unsafe(addr(clipvert.position[0]))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh21))[0]) + f * (unsafe(unsafe(reinterpret<float?>(c2da_fresh22))[0]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh23))[0]))
                var c2da_fresh24 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
                var c2da_fresh25 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv1))))
                var c2da_fresh26 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
                unsafe(unsafe(addr(clipvert.position[0]))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh24))[1]) + f * (unsafe(unsafe(reinterpret<float?>(c2da_fresh25))[1]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh26))[1]))
                var c2da_fresh27 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
                var c2da_fresh28 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv1))))
                var c2da_fresh29 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
                unsafe(unsafe(addr(clipvert.position[0]))[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh27))[2]) + f * (unsafe(unsafe(reinterpret<float?>(c2da_fresh28))[2]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh29))[2]))
                if (clip.leftedge != 0x0) {
                    r_leftclipped = unsafe(reinterpret<qboolean>(1u))
                    r_leftexit = clipvert
                } elif (clip.rightedge != 0x0) {
                    r_rightclipped = unsafe(reinterpret<qboolean>(1u))
                    r_rightexit = clipvert
                }
                R_ClipEdge(pv0, unsafe(addr<mvertex_t?>(clipvert)), clip.next)
                return
            } else {
                if (d1 < 0.0) {
                    if (uint(r_leftclipped) == 0u) {
                        cacheoffset = 0x80000000u | uint(r_framecount & 2147483647)
                    }
                    return
                }
                r_lastvertvalid = unsafe(reinterpret<qboolean>(0u))
                cacheoffset = 0x7fffffffu
                f = d0 / (d0 - d1)
                var c2da_fresh30 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
                var c2da_fresh31 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv1))))
                var c2da_fresh32 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
                unsafe(unsafe(addr(clipvert.position[0]))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh30))[0]) + f * (unsafe(unsafe(reinterpret<float?>(c2da_fresh31))[0]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh32))[0]))
                var c2da_fresh33 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
                var c2da_fresh34 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv1))))
                var c2da_fresh35 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
                unsafe(unsafe(addr(clipvert.position[0]))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh33))[1]) + f * (unsafe(unsafe(reinterpret<float?>(c2da_fresh34))[1]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh35))[1]))
                var c2da_fresh36 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
                var c2da_fresh37 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv1))))
                var c2da_fresh38 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0))))
                unsafe(unsafe(addr(clipvert.position[0]))[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh36))[2]) + f * (unsafe(unsafe(reinterpret<float?>(c2da_fresh37))[2]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh38))[2]))
                if (clip.leftedge != 0x0) {
                    r_leftclipped = unsafe(reinterpret<qboolean>(1u))
                    r_leftenter = clipvert
                } elif (clip.rightedge != 0x0) {
                    r_rightclipped = unsafe(reinterpret<qboolean>(1u))
                    r_rightenter = clipvert
                }
                R_ClipEdge(unsafe(addr<mvertex_t?>(clipvert)), pv1, clip.next)
                return
            }
        }
    }
    R_EmitEdge(pv0, pv1)
    return
}
[export, sideeffects]
def R_EmitEdge(var pv0_0 : mvertex_t?; var pv1_0 : mvertex_t?) {
    var edge : edge_s?
    var pcheck : edge_s?
    var u_check : int
    var u : float
    var u_step : float
    var local : vec3_t
    var transformed : vec3_t
    var world : float?
    var v : int
    var v2 : int
    var ceilv0 : int
    var lzi0 : float
    var u0 : float
    var v0 : float
    var side : int
    if (uint(r_lastvertvalid) != 0u) {
        u0 = r_u1
        v0 = r_v1
        lzi0 = r_lzi1
        ceilv0 = r_ceilv1
    } else {
        var c2da_fresh39 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv0_0))))
        world = unsafe(addr<float?>(unsafe(unsafe(reinterpret<float?>(c2da_fresh39))[0])))
        unsafe(unsafe(addr(local[0]))[0]) = unsafe(world[0]) - unsafe(unsafe(addr(modelorg[0]))[0])
        unsafe(unsafe(addr(local[0]))[1]) = unsafe(world[1]) - unsafe(unsafe(addr(modelorg[0]))[1])
        unsafe(unsafe(addr(local[0]))[2]) = unsafe(world[2]) - unsafe(unsafe(addr(modelorg[0]))[2])
        TransformVector(unsafe(addr<float?>(local[0])), unsafe(addr<float?>(transformed[0])))
        if (double(unsafe(unsafe(addr(transformed[0]))[2])) < 0.01lf) {
            unsafe(unsafe(addr(transformed[0]))[2]) = float(0.01lf)
        }
        lzi0 = float(1.0lf / double(unsafe(unsafe(addr(transformed[0]))[2])))
        u0 = xcenter + xscale * lzi0 * unsafe(unsafe(addr(transformed[0]))[0])
        if (u0 < r_refdef.fvrectx_adj) {
            u0 = r_refdef.fvrectx_adj
        }
        if (u0 > r_refdef.fvrectright_adj) {
            u0 = r_refdef.fvrectright_adj
        }
        v0 = ycenter - yscale * lzi0 * unsafe(unsafe(addr(transformed[0]))[1])
        if (v0 < r_refdef.fvrecty_adj) {
            v0 = r_refdef.fvrecty_adj
        }
        if (v0 > r_refdef.fvrectbottom_adj) {
            v0 = r_refdef.fvrectbottom_adj
        }
        ceilv0 = int(ceil(double(v0)))
    }
    var c2da_fresh40 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pv1_0))))
    world = unsafe(addr<float?>(unsafe(unsafe(reinterpret<float?>(c2da_fresh40))[0])))
    unsafe(unsafe(addr(local[0]))[0]) = unsafe(world[0]) - unsafe(unsafe(addr(modelorg[0]))[0])
    unsafe(unsafe(addr(local[0]))[1]) = unsafe(world[1]) - unsafe(unsafe(addr(modelorg[0]))[1])
    unsafe(unsafe(addr(local[0]))[2]) = unsafe(world[2]) - unsafe(unsafe(addr(modelorg[0]))[2])
    TransformVector(unsafe(addr<float?>(local[0])), unsafe(addr<float?>(transformed[0])))
    if (double(unsafe(unsafe(addr(transformed[0]))[2])) < 0.01lf) {
        unsafe(unsafe(addr(transformed[0]))[2]) = float(0.01lf)
    }
    r_lzi1 = float(1.0lf / double(unsafe(unsafe(addr(transformed[0]))[2])))
    r_u1 = xcenter + xscale * r_lzi1 * unsafe(unsafe(addr(transformed[0]))[0])
    if (r_u1 < r_refdef.fvrectx_adj) {
        r_u1 = r_refdef.fvrectx_adj
    }
    if (r_u1 > r_refdef.fvrectright_adj) {
        r_u1 = r_refdef.fvrectright_adj
    }
    r_v1 = ycenter - yscale * r_lzi1 * unsafe(unsafe(addr(transformed[0]))[1])
    if (r_v1 < r_refdef.fvrecty_adj) {
        r_v1 = r_refdef.fvrecty_adj
    }
    if (r_v1 > r_refdef.fvrectbottom_adj) {
        r_v1 = r_refdef.fvrectbottom_adj
    }
    if (r_lzi1 > lzi0) {
        lzi0 = r_lzi1
    }
    if (lzi0 > r_nearzi) {
        r_nearzi = lzi0
    }
    if (uint(r_nearzionly) != 0u) {
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
    var c2da_postinc_0 : edge_s? = edge_p
    edge_p = unsafe(edge_p + 1)
    edge = unsafe(reinterpret<edge_s?>(c2da_postinc_0))
    edge.owner = r_pedge
    edge.nearzi = lzi0
    if (side == 0) {
        v = ceilv0
        v2 = r_ceilv1 - 1
        var c2da_fresh41 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(edge)) + 24ul))
        unsafe(unsafe(reinterpret<uint16?>(c2da_fresh41))[0]) = uint16(unsafe(surface_p - surfaces))
        var c2da_fresh42 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(edge)) + 24ul))
        unsafe(unsafe(reinterpret<uint16?>(c2da_fresh42))[1]) = uint16(0)
        u_step = (r_u1 - u0) / (r_v1 - v0)
        u = u0 + (float(v) - v0) * u_step
    } else {
        v2 = ceilv0 - 1
        v = r_ceilv1
        var c2da_fresh43 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(edge)) + 24ul))
        unsafe(unsafe(reinterpret<uint16?>(c2da_fresh43))[0]) = uint16(0)
        var c2da_fresh44 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(edge)) + 24ul))
        unsafe(unsafe(reinterpret<uint16?>(c2da_fresh44))[1]) = uint16(unsafe(surface_p - surfaces))
        u_step = (u0 - r_u1) / (v0 - r_v1)
        u = r_u1 + (float(v) - r_v1) * u_step
    }
    edge.u_step = int(u_step * 1048576.0)
    edge.u = int(u * 1048576.0 + 1048575.0)
    if (edge.u < r_refdef.vrect_x_adj_shift20) {
        edge.u = r_refdef.vrect_x_adj_shift20
    }
    if (edge.u > r_refdef.vrectright_adj_shift20) {
        edge.u = r_refdef.vrectright_adj_shift20
    }
    u_check = edge.u
    var c2da_fresh45 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(edge)) + 24ul))
    if (unsafe(unsafe(reinterpret<uint16?>(c2da_fresh45))[0]) != 0x0) {
        u_check++
    }
    if (newedges[v] == null || newedges[v].u >= u_check) {
        edge.next = newedges[v]
        newedges[v] = unsafe(reinterpret<edge_s?>(edge))
    } else {
        pcheck = unsafe(reinterpret<edge_s?>(newedges[v]))
        while (pcheck.next != null && pcheck.next.u < u_check) {
            pcheck = unsafe(reinterpret<edge_s?>(pcheck.next))
        }
        edge.next = pcheck.next
        pcheck.next = edge
    }
    edge.nextremove = removeedges[v2]
    removeedges[v2] = unsafe(reinterpret<edge_s?>(edge))
    return
}
var r_v1 : float = default<float>

var r_u1 : float = default<float>

var r_ceilv1 : int = default<int>

var r_pedge : medge_t? = default<medge_t?>

var cacheoffset : uint = default<uint>

var r_nearzionly : qboolean = default<qboolean>

var r_lzi1 : float = default<float>

var r_lastvertvalid : qboolean = default<qboolean>

var r_rightclipped : qboolean = default<qboolean>

var r_leftenter : mvertex_t = default<mvertex_t>

var r_leftclipped : qboolean = default<qboolean>

var r_leftexit : mvertex_t = default<mvertex_t>

var private makerightedge : qboolean = default<qboolean>

var private makeleftedge : qboolean = default<qboolean>

[export, sideeffects]
def R_EmitCachedEdge() {
    var pedge_t : edge_s? = unsafe(reinterpret<edge_s?>(unsafe(reinterpret<edge_s?>(unsafe(reinterpret<uint64>(r_edges)) + uint64(r_pedge.cachededgeoffset)))))
    var c2da_fresh46 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pedge_t)) + 24ul))
    if (unsafe(unsafe(reinterpret<uint16?>(c2da_fresh46))[0]) == 0) {
        var c2da_fresh47 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pedge_t)) + 24ul))
        unsafe(unsafe(reinterpret<uint16?>(c2da_fresh47))[0]) = uint16(unsafe(surface_p - surfaces))
    } else {
        var c2da_fresh48 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pedge_t)) + 24ul))
        unsafe(unsafe(reinterpret<uint16?>(c2da_fresh48))[1]) = uint16(unsafe(surface_p - surfaces))
    }
    if (pedge_t.nearzi > r_nearzi) {
        r_nearzi = float(pedge_t.nearzi)  // nolint:PERF020
    }
    r_emitted = 1
    return
}
var c_faceclip : int = default<int>

[export, sideeffects]
def R_RenderPoly(var fa_0 : msurface_s?; var clipflags_0 : int) {
    var c2da_fresh57 : int
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
    var local_0 : vec3_t
    var transformed_0 : vec3_t
    var pclip_0 : clipplane_s?
    var pedges_0 : medge_t?
    var verts : mvertex_t[2][100]
    var pverts : polyvert_s[100]
    var vertpage : int
    var newverts : int
    var newpage : int
    var lastvert : int
    var visible : qboolean = qboolean()
    t_axis = 0
    s_axis = t_axis
    pclip_0 = null
    i_0 = 3
    mask_0 = 0x8u
    while (i_0 >= 0) {
        if ((uint(clipflags_0) & mask_0) != 0x0) {
            view_clipplanes[i_0].next = unsafe(reinterpret<clipplane_s?>(pclip_0))
            pclip_0 = unsafe(addr<clipplane_s?>(unsafe(unsafe(addr(view_clipplanes[0]))[i_0])))
        }
        i_0--
        mask_0 >>= 1u
    }
    pedges_0 = unsafe(reinterpret<medge_t?>(currententity.model.edges))
    lnumverts = fa_0.numedges
    vertpage = 0
    i_0 = 0
    while (i_0 < lnumverts) {
        lindex_0 = unsafe(currententity.model.surfedges[fa_0.firstedge + i_0])
        if (lindex_0 > 0) {
            r_pedge = unsafe(addr<medge_t?>(unsafe(pedges_0[lindex_0])))
            var c2da_fresh49 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(r_pedge))))
            verts[0][i_0] = unsafe(r_pcurrentvertbase[int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh49))[0]))])
        } else {
            r_pedge = unsafe(addr<medge_t?>(unsafe(pedges_0[-lindex_0])))
            var c2da_fresh50 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(r_pedge))))
            verts[0][i_0] = unsafe(r_pcurrentvertbase[int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh50))[1]))])
        }
        i_0++
    }
    while (pclip_0 != null) {
        lastvert = lnumverts - 1
        var c2da_fresh51 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pclip_0))))
        var c2da_fresh52 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pclip_0))))
        var c2da_fresh53 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pclip_0))))
        lastdist = unsafe(unsafe(addr(verts[vertpage][lastvert].position[0]))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh51))[0]) + unsafe(unsafe(addr(verts[vertpage][lastvert].position[0]))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh52))[1]) + unsafe(unsafe(addr(verts[vertpage][lastvert].position[0]))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh53))[2]) - pclip_0.dist
        visible = unsafe(reinterpret<qboolean>(0u))
        newverts = 0
        newpage = vertpage ^ 1
        i_0 = 0
        while (i_0 < lnumverts) {
            var c2da_fresh54 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pclip_0))))
            var c2da_fresh55 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pclip_0))))
            var c2da_fresh56 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pclip_0))))
            dist = unsafe(unsafe(addr(verts[vertpage][i_0].position[0]))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh54))[0]) + unsafe(unsafe(addr(verts[vertpage][i_0].position[0]))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh55))[1]) + unsafe(unsafe(addr(verts[vertpage][i_0].position[0]))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh56))[2]) - pclip_0.dist
            if ((lastdist > 0.0 ? 1 : 0) != (dist > 0.0 ? 1 : 0)) {
                frac = dist / (dist - lastdist)
                unsafe(unsafe(addr(verts[newpage][newverts].position[0]))[0]) = unsafe(unsafe(addr(verts[vertpage][i_0].position[0]))[0]) + (unsafe(unsafe(addr(verts[vertpage][lastvert].position[0]))[0]) - unsafe(unsafe(addr(verts[vertpage][i_0].position[0]))[0])) * frac
                unsafe(unsafe(addr(verts[newpage][newverts].position[0]))[1]) = unsafe(unsafe(addr(verts[vertpage][i_0].position[0]))[1]) + (unsafe(unsafe(addr(verts[vertpage][lastvert].position[0]))[1]) - unsafe(unsafe(addr(verts[vertpage][i_0].position[0]))[1])) * frac
                unsafe(unsafe(addr(verts[newpage][newverts].position[0]))[2]) = unsafe(unsafe(addr(verts[vertpage][i_0].position[0]))[2]) + (unsafe(unsafe(addr(verts[vertpage][lastvert].position[0]))[2]) - unsafe(unsafe(addr(verts[vertpage][i_0].position[0]))[2])) * frac
                newverts++
            }
            if (dist >= 0.0) {
                verts[newpage][newverts] = verts[vertpage][i_0]
                newverts++
                visible = unsafe(reinterpret<qboolean>(1u))
            }
            lastvert = i_0
            lastdist = dist
            i_0++
        }
        if (uint(visible) == 0u || newverts < 3) {
            return
        }
        lnumverts = newverts
        vertpage ^= 1
        pclip_0 = unsafe(reinterpret<clipplane_s?>(pclip_0.next))
    }
    c2da_fresh57 = int(unsafe(reinterpret<mplane_s?>(fa_0.plane)).type_0)
    if (c2da_fresh57 == 0 || c2da_fresh57 == 3) {
        s_axis = 1
        t_axis = 2
    } elif (c2da_fresh57 == 1 || c2da_fresh57 == 4) {
        s_axis = 0
        t_axis = 2
    } elif (c2da_fresh57 == 2 || c2da_fresh57 == 5) {
        s_axis = 0
        t_axis = 1
    }
    r_nearzi = 0.0
    i_0 = 0
    for (c2da_i_0 in range(i_0, lnumverts)) {
        unsafe(unsafe(addr(local_0[0]))[0]) = unsafe(unsafe(addr(verts[vertpage][c2da_i_0].position[0]))[0]) - unsafe(unsafe(addr(modelorg[0]))[0])
        unsafe(unsafe(addr(local_0[0]))[1]) = unsafe(unsafe(addr(verts[vertpage][c2da_i_0].position[0]))[1]) - unsafe(unsafe(addr(modelorg[0]))[1])
        unsafe(unsafe(addr(local_0[0]))[2]) = unsafe(unsafe(addr(verts[vertpage][c2da_i_0].position[0]))[2]) - unsafe(unsafe(addr(modelorg[0]))[2])
        TransformVector(unsafe(addr<float?>(local_0[0])), unsafe(addr<float?>(transformed_0[0])))
        if (double(unsafe(unsafe(addr(transformed_0[0]))[2])) < 0.01lf) {
            unsafe(unsafe(addr(transformed_0[0]))[2]) = float(0.01lf)
        }
        lzi = float(1.0lf / double(unsafe(unsafe(addr(transformed_0[0]))[2])))
        if (lzi > r_nearzi) {
            r_nearzi = lzi
        }
        u_0 = xcenter + xscale * lzi * unsafe(unsafe(addr(transformed_0[0]))[0])
        if (u_0 < r_refdef.fvrectx_adj) {
            u_0 = r_refdef.fvrectx_adj
        }
        if (u_0 > r_refdef.fvrectright_adj) {
            u_0 = r_refdef.fvrectright_adj
        }
        v_0 = ycenter - yscale * lzi * unsafe(unsafe(addr(transformed_0[0]))[1])
        if (v_0 < r_refdef.fvrecty_adj) {
            v_0 = r_refdef.fvrecty_adj
        }
        if (v_0 > r_refdef.fvrectbottom_adj) {
            v_0 = r_refdef.fvrectbottom_adj
        }
        pverts[c2da_i_0].u = u_0
        pverts[c2da_i_0].v = v_0
        pverts[c2da_i_0].zi = lzi
        pverts[c2da_i_0].s = float(unsafe(unsafe(addr(verts[vertpage][c2da_i_0].position[0]))[s_axis]))  // nolint:PERF020
        pverts[c2da_i_0].t = float(unsafe(unsafe(addr(verts[vertpage][c2da_i_0].position[0]))[t_axis]))  // nolint:PERF020
    }
    r_polydesc.numverts = lnumverts
    r_polydesc.nearzi = float(r_nearzi)  // nolint:PERF020
    r_polydesc.pcurrentface = unsafe(reinterpret<msurface_s?>(fa_0))
    r_polydesc.pverts = unsafe(addr<polyvert_s?>(pverts[0]))
    D_DrawPoly()
    return
}
[export, sideeffects]
def R_RenderBmodelFace(var pedges_1 : bedge_s?; var psurf : msurface_s?) {
    var i_1 : int
    var mask_1 : uint
    var pplane_1 : mplane_s?
    var distinv_0 : float
    var p_normal_0 : vec3_t
    var tedge_0 : medge_t
    var pclip_1 : clipplane_s?
    if (unsafe(reinterpret<uint64>(surface_p)) >= unsafe(reinterpret<uint64>(surf_max))) {
        r_outofsurfaces = r_outofsurfaces + 1
        return
    }
    var c2da_fresh58 : edge_s? = unsafe(unsafe(edge_p + psurf.numedges) + 4)
    if (unsafe(reinterpret<uint64>(c2da_fresh58)) >= unsafe(reinterpret<uint64>(edge_max))) {
        r_outofedges = r_outofedges + psurf.numedges
        return
    }
    c_faceclip++
    r_pedge = unsafe(addr<medge_t?>(tedge_0))
    pclip_1 = null
    i_1 = 3
    mask_1 = 0x8u
    while (i_1 >= 0) {
        if ((uint(r_clipflags) & mask_1) != 0x0) {
            view_clipplanes[i_1].next = unsafe(reinterpret<clipplane_s?>(pclip_1))
            pclip_1 = unsafe(addr<clipplane_s?>(unsafe(unsafe(addr(view_clipplanes[0]))[i_1])))
        }
        i_1--
        mask_1 >>= 1u
    }
    r_emitted = 0
    r_nearzi = 0.0
    r_nearzionly = unsafe(reinterpret<qboolean>(0u))
    makerightedge = unsafe(reinterpret<qboolean>(0u))
    makeleftedge = makerightedge
    r_lastvertvalid = unsafe(reinterpret<qboolean>(0u))
    while (pedges_1 != null) {
        r_rightclipped = unsafe(reinterpret<qboolean>(0u))
        r_leftclipped = r_rightclipped
        var c2da_fresh59 : mvertex_t?? = unsafe(reinterpret<mvertex_t??>(unsafe(reinterpret<uint64>(pedges_1))))
        var c2da_fresh60 : mvertex_t?? = unsafe(reinterpret<mvertex_t??>(unsafe(reinterpret<uint64>(pedges_1))))
        R_ClipEdge(unsafe(reinterpret<mvertex_t?>(unsafe(unsafe(reinterpret<mvertex_t??>(c2da_fresh59))[0]))), unsafe(reinterpret<mvertex_t?>(unsafe(unsafe(reinterpret<mvertex_t??>(c2da_fresh60))[1]))), pclip_1)
        if (uint(r_leftclipped) != 0u) {
            makeleftedge = unsafe(reinterpret<qboolean>(1u))
        }
        if (uint(r_rightclipped) != 0u) {
            makerightedge = unsafe(reinterpret<qboolean>(1u))
        }
        pedges_1 = unsafe(reinterpret<bedge_s?>(pedges_1.pnext))
    }
    if (uint(makeleftedge) != 0u) {
        r_pedge = unsafe(addr<medge_t?>(tedge_0))
        R_ClipEdge(unsafe(addr<mvertex_t?>(r_leftexit)), unsafe(addr<mvertex_t?>(r_leftenter)), pclip_1.next)
    }
    if (uint(makerightedge) != 0u) {
        r_pedge = unsafe(addr<medge_t?>(tedge_0))
        r_nearzionly = unsafe(reinterpret<qboolean>(1u))
        R_ClipEdge(unsafe(addr<mvertex_t?>(r_rightexit)), unsafe(addr<mvertex_t?>(r_rightenter)), view_clipplanes[1].next)
    }
    if (r_emitted == 0) {
        return
    }
    r_polycount = r_polycount + 1
    surface_p.data = unsafe(reinterpret<uint8?>(psurf))
    surface_p.nearzi = r_nearzi
    surface_p.flags = psurf.flags
    surface_p.insubmodel = unsafe(reinterpret<qboolean>(1u))
    surface_p.spanstate = 0
    surface_p.entity = currententity
    surface_p.key = r_currentbkey
    surface_p.spans = null
    pplane_1 = unsafe(reinterpret<mplane_s?>(psurf.plane))
    var c2da_fresh61 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane_1))))
    TransformVector(unsafe(reinterpret<float?>(c2da_fresh61)), unsafe(addr<float?>(p_normal_0[0])))
    var c2da_fresh62 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane_1))))
    var c2da_fresh63 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane_1))))
    var c2da_fresh64 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane_1))))
    distinv_0 = float(1.0lf / double(pplane_1.dist - (unsafe(unsafe(addr(modelorg[0]))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh62))[0]) + unsafe(unsafe(addr(modelorg[0]))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh63))[1]) + unsafe(unsafe(addr(modelorg[0]))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh64))[2]))))
    surface_p.d_zistepu = unsafe(unsafe(addr(p_normal_0[0]))[0]) * xscaleinv * distinv_0
    surface_p.d_zistepv = -unsafe(unsafe(addr(p_normal_0[0]))[1]) * yscaleinv * distinv_0
    surface_p.d_ziorigin = unsafe(unsafe(addr(p_normal_0[0]))[2]) * distinv_0 - xcenter * surface_p.d_zistepu - ycenter * surface_p.d_zistepv
    surface_p = unsafe(surface_p + 1)
    return
}
[export, sideeffects]
def R_ZDrawSubmodelPolys(var pmodel_0 : model_s?) {
    var i_2 : int
    var numsurfaces : int
    var psurf_0 : msurface_s?
    var dot : float
    var pplane_2 : mplane_s?
    psurf_0 = unsafe(addr<msurface_s?>(unsafe(pmodel_0.surfaces[pmodel_0.firstmodelsurface])))
    numsurfaces = pmodel_0.nummodelsurfaces
    i_2 = 0
    while (i_2 < numsurfaces) {
        pplane_2 = unsafe(reinterpret<mplane_s?>(psurf_0.plane))
        var c2da_fresh65 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane_2))))
        var c2da_fresh66 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane_2))))
        var c2da_fresh67 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane_2))))
        dot = unsafe(unsafe(addr(modelorg[0]))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh65))[0]) + unsafe(unsafe(addr(modelorg[0]))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh66))[1]) + unsafe(unsafe(addr(modelorg[0]))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh67))[2]) - pplane_2.dist
        if ((psurf_0.flags & 2) != 0 && double(dot) < -0.01lf || (psurf_0.flags & 2) == 0 && double(dot) > 0.01lf) {
            R_RenderPoly(psurf_0, 15)
        }
        i_2++
        unsafe {  // nolint:STYLE025
            psurf_0 += 1
        }
    }
    return
}
var entity_clipplanes : clipplane_s? = default<clipplane_s?>

var world_clipplanes : clipplane_s[16]

[sideeffects]
def private c2da_layout_proofs_35() {
    static_assert(typeinfo sizeof(type<cache_user_s>) == 8, "C layout of cache_user_s: sizeof")
    static_assert(typeinfo alignof(type<cache_user_s>) == 8, "C layout of cache_user_s: alignof")
    static_assert(typeinfo offsetof<data>(type<cache_user_s>) == 0, "C layout of cache_user_s: offsetof data")
    static_assert(typeinfo sizeof(type<dmodel_t>) == 64, "C layout of dmodel_t: sizeof")
    static_assert(typeinfo alignof(type<dmodel_t>) == 4, "C layout of dmodel_t: alignof")
    static_assert(typeinfo offsetof<mins>(type<dmodel_t>) == 0, "C layout of dmodel_t: offsetof mins")
    static_assert(typeinfo offsetof<maxs>(type<dmodel_t>) == 12, "C layout of dmodel_t: offsetof maxs")
    static_assert(typeinfo offsetof<origin>(type<dmodel_t>) == 24, "C layout of dmodel_t: offsetof origin")
    static_assert(typeinfo offsetof<headnode>(type<dmodel_t>) == 36, "C layout of dmodel_t: offsetof headnode")
    static_assert(typeinfo offsetof<visleafs>(type<dmodel_t>) == 52, "C layout of dmodel_t: offsetof visleafs")
    static_assert(typeinfo offsetof<firstface>(type<dmodel_t>) == 56, "C layout of dmodel_t: offsetof firstface")
    static_assert(typeinfo offsetof<numfaces>(type<dmodel_t>) == 60, "C layout of dmodel_t: offsetof numfaces")
    static_assert(typeinfo sizeof(type<dclipnode_t>) == 8, "C layout of dclipnode_t: sizeof")
    static_assert(typeinfo alignof(type<dclipnode_t>) == 4, "C layout of dclipnode_t: alignof")
    static_assert(typeinfo offsetof<planenum>(type<dclipnode_t>) == 0, "C layout of dclipnode_t: offsetof planenum")
    static_assert(typeinfo offsetof<children>(type<dclipnode_t>) == 4, "C layout of dclipnode_t: offsetof children")
    static_assert(typeinfo sizeof(type<vrect_s>) == 24, "C layout of vrect_s: sizeof")
    static_assert(typeinfo alignof(type<vrect_s>) == 8, "C layout of vrect_s: alignof")
    static_assert(typeinfo offsetof<x>(type<vrect_s>) == 0, "C layout of vrect_s: offsetof x")
    static_assert(typeinfo offsetof<y>(type<vrect_s>) == 4, "C layout of vrect_s: offsetof y")
    static_assert(typeinfo offsetof<width>(type<vrect_s>) == 8, "C layout of vrect_s: offsetof width")
    static_assert(typeinfo offsetof<height>(type<vrect_s>) == 12, "C layout of vrect_s: offsetof height")
    static_assert(typeinfo offsetof<pnext>(type<vrect_s>) == 16, "C layout of vrect_s: offsetof pnext")
    static_assert(typeinfo sizeof(type<vrect_t>) == 24, "C layout of vrect_t: sizeof")
    static_assert(typeinfo alignof(type<vrect_t>) == 8, "C layout of vrect_t: alignof")
    static_assert(typeinfo offsetof<x>(type<vrect_t>) == 0, "C layout of vrect_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<vrect_t>) == 4, "C layout of vrect_t: offsetof y")
    static_assert(typeinfo offsetof<width>(type<vrect_t>) == 8, "C layout of vrect_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<vrect_t>) == 12, "C layout of vrect_t: offsetof height")
    static_assert(typeinfo offsetof<pnext>(type<vrect_t>) == 16, "C layout of vrect_t: offsetof pnext")
    static_assert(typeinfo sizeof(type<cache_user_t>) == 8, "C layout of cache_user_t: sizeof")
    static_assert(typeinfo alignof(type<cache_user_t>) == 8, "C layout of cache_user_t: alignof")
    static_assert(typeinfo offsetof<data>(type<cache_user_t>) == 0, "C layout of cache_user_t: offsetof data")
    static_assert(typeinfo sizeof(type<mplane_s>) == 20, "C layout of mplane_s: sizeof")
    static_assert(typeinfo alignof(type<mplane_s>) == 4, "C layout of mplane_s: alignof")
    static_assert(typeinfo offsetof<normal>(type<mplane_s>) == 0, "C layout of mplane_s: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<mplane_s>) == 12, "C layout of mplane_s: offsetof dist")
    static_assert(typeinfo offsetof<type_0>(type<mplane_s>) == 16, "C layout of mplane_s: offsetof type_0")
    static_assert(typeinfo offsetof<signbits>(type<mplane_s>) == 17, "C layout of mplane_s: offsetof signbits")
    static_assert(typeinfo offsetof<pad>(type<mplane_s>) == 18, "C layout of mplane_s: offsetof pad")
    static_assert(typeinfo sizeof(type<entity_state_t>) == 44, "C layout of entity_state_t: sizeof")
    static_assert(typeinfo alignof(type<entity_state_t>) == 4, "C layout of entity_state_t: alignof")
    static_assert(typeinfo offsetof<origin>(type<entity_state_t>) == 0, "C layout of entity_state_t: offsetof origin")
    static_assert(typeinfo offsetof<angles>(type<entity_state_t>) == 12, "C layout of entity_state_t: offsetof angles")
    static_assert(typeinfo offsetof<modelindex>(type<entity_state_t>) == 24, "C layout of entity_state_t: offsetof modelindex")
    static_assert(typeinfo offsetof<frame>(type<entity_state_t>) == 28, "C layout of entity_state_t: offsetof frame")
    static_assert(typeinfo offsetof<colormap>(type<entity_state_t>) == 32, "C layout of entity_state_t: offsetof colormap")
    static_assert(typeinfo offsetof<skin>(type<entity_state_t>) == 36, "C layout of entity_state_t: offsetof skin")
    static_assert(typeinfo offsetof<effects>(type<entity_state_t>) == 40, "C layout of entity_state_t: offsetof effects")
    static_assert(typeinfo sizeof(type<efrag_s>) == 32, "C layout of efrag_s: sizeof")
    static_assert(typeinfo alignof(type<efrag_s>) == 8, "C layout of efrag_s: alignof")
    static_assert(typeinfo offsetof<leaf>(type<efrag_s>) == 0, "C layout of efrag_s: offsetof leaf")
    static_assert(typeinfo offsetof<leafnext>(type<efrag_s>) == 8, "C layout of efrag_s: offsetof leafnext")
    static_assert(typeinfo offsetof<entity>(type<efrag_s>) == 16, "C layout of efrag_s: offsetof entity")
    static_assert(typeinfo offsetof<entnext>(type<efrag_s>) == 24, "C layout of efrag_s: offsetof entnext")
    static_assert(typeinfo sizeof(type<entity_s>) == 200, "C layout of entity_s: sizeof")
    static_assert(typeinfo alignof(type<entity_s>) == 8, "C layout of entity_s: alignof")
    static_assert(typeinfo offsetof<forcelink>(type<entity_s>) == 0, "C layout of entity_s: offsetof forcelink")
    static_assert(typeinfo offsetof<update_type>(type<entity_s>) == 4, "C layout of entity_s: offsetof update_type")
    static_assert(typeinfo offsetof<baseline>(type<entity_s>) == 8, "C layout of entity_s: offsetof baseline")
    static_assert(typeinfo offsetof<msgtime>(type<entity_s>) == 56, "C layout of entity_s: offsetof msgtime")
    static_assert(typeinfo offsetof<msg_origins>(type<entity_s>) == 64, "C layout of entity_s: offsetof msg_origins")
    static_assert(typeinfo offsetof<origin>(type<entity_s>) == 88, "C layout of entity_s: offsetof origin")
    static_assert(typeinfo offsetof<msg_angles>(type<entity_s>) == 100, "C layout of entity_s: offsetof msg_angles")
    static_assert(typeinfo offsetof<angles>(type<entity_s>) == 124, "C layout of entity_s: offsetof angles")
    static_assert(typeinfo offsetof<model>(type<entity_s>) == 136, "C layout of entity_s: offsetof model")
    static_assert(typeinfo offsetof<efrag>(type<entity_s>) == 144, "C layout of entity_s: offsetof efrag")
    static_assert(typeinfo offsetof<frame>(type<entity_s>) == 152, "C layout of entity_s: offsetof frame")
    static_assert(typeinfo offsetof<syncbase>(type<entity_s>) == 156, "C layout of entity_s: offsetof syncbase")
    static_assert(typeinfo offsetof<colormap>(type<entity_s>) == 160, "C layout of entity_s: offsetof colormap")
    static_assert(typeinfo offsetof<effects>(type<entity_s>) == 168, "C layout of entity_s: offsetof effects")
    static_assert(typeinfo offsetof<skinnum>(type<entity_s>) == 172, "C layout of entity_s: offsetof skinnum")
    static_assert(typeinfo offsetof<visframe>(type<entity_s>) == 176, "C layout of entity_s: offsetof visframe")
    static_assert(typeinfo offsetof<dlightframe>(type<entity_s>) == 180, "C layout of entity_s: offsetof dlightframe")
    static_assert(typeinfo offsetof<dlightbits>(type<entity_s>) == 184, "C layout of entity_s: offsetof dlightbits")
    static_assert(typeinfo offsetof<trivial_accept>(type<entity_s>) == 188, "C layout of entity_s: offsetof trivial_accept")
    static_assert(typeinfo offsetof<topnode>(type<entity_s>) == 192, "C layout of entity_s: offsetof topnode")
    static_assert(typeinfo sizeof(type<mnode_s>) == 64, "C layout of mnode_s: sizeof")
    static_assert(typeinfo alignof(type<mnode_s>) == 8, "C layout of mnode_s: alignof")
    static_assert(typeinfo offsetof<contents>(type<mnode_s>) == 0, "C layout of mnode_s: offsetof contents")
    static_assert(typeinfo offsetof<visframe>(type<mnode_s>) == 4, "C layout of mnode_s: offsetof visframe")
    static_assert(typeinfo offsetof<minmaxs>(type<mnode_s>) == 8, "C layout of mnode_s: offsetof minmaxs")
    static_assert(typeinfo offsetof<parent>(type<mnode_s>) == 24, "C layout of mnode_s: offsetof parent")
    static_assert(typeinfo offsetof<plane>(type<mnode_s>) == 32, "C layout of mnode_s: offsetof plane")
    static_assert(typeinfo offsetof<children>(type<mnode_s>) == 40, "C layout of mnode_s: offsetof children")
    static_assert(typeinfo offsetof<firstsurface>(type<mnode_s>) == 56, "C layout of mnode_s: offsetof firstsurface")
    static_assert(typeinfo offsetof<numsurfaces>(type<mnode_s>) == 58, "C layout of mnode_s: offsetof numsurfaces")
    static_assert(typeinfo sizeof(type<mplane_t>) == 20, "C layout of mplane_t: sizeof")
    static_assert(typeinfo alignof(type<mplane_t>) == 4, "C layout of mplane_t: alignof")
    static_assert(typeinfo offsetof<normal>(type<mplane_t>) == 0, "C layout of mplane_t: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<mplane_t>) == 12, "C layout of mplane_t: offsetof dist")
    static_assert(typeinfo offsetof<type_0>(type<mplane_t>) == 16, "C layout of mplane_t: offsetof type_0")
    static_assert(typeinfo offsetof<signbits>(type<mplane_t>) == 17, "C layout of mplane_t: offsetof signbits")
    static_assert(typeinfo offsetof<pad>(type<mplane_t>) == 18, "C layout of mplane_t: offsetof pad")
    static_assert(typeinfo sizeof(type<model_s>) == 536, "C layout of model_s: sizeof")
    static_assert(typeinfo alignof(type<model_s>) == 8, "C layout of model_s: alignof")
    static_assert(typeinfo offsetof<name>(type<model_s>) == 0, "C layout of model_s: offsetof name")
    static_assert(typeinfo offsetof<needload>(type<model_s>) == 64, "C layout of model_s: offsetof needload")
    static_assert(typeinfo offsetof<type_0>(type<model_s>) == 68, "C layout of model_s: offsetof type_0")
    static_assert(typeinfo offsetof<numframes>(type<model_s>) == 72, "C layout of model_s: offsetof numframes")
    static_assert(typeinfo offsetof<synctype>(type<model_s>) == 76, "C layout of model_s: offsetof synctype")
    static_assert(typeinfo offsetof<flags>(type<model_s>) == 80, "C layout of model_s: offsetof flags")
    static_assert(typeinfo offsetof<mins>(type<model_s>) == 84, "C layout of model_s: offsetof mins")
    static_assert(typeinfo offsetof<maxs>(type<model_s>) == 96, "C layout of model_s: offsetof maxs")
    static_assert(typeinfo offsetof<radius>(type<model_s>) == 108, "C layout of model_s: offsetof radius")
    static_assert(typeinfo offsetof<firstmodelsurface>(type<model_s>) == 112, "C layout of model_s: offsetof firstmodelsurface")
    static_assert(typeinfo offsetof<nummodelsurfaces>(type<model_s>) == 116, "C layout of model_s: offsetof nummodelsurfaces")
    static_assert(typeinfo offsetof<numsubmodels>(type<model_s>) == 120, "C layout of model_s: offsetof numsubmodels")
    static_assert(typeinfo offsetof<submodels>(type<model_s>) == 128, "C layout of model_s: offsetof submodels")
    static_assert(typeinfo offsetof<numplanes>(type<model_s>) == 136, "C layout of model_s: offsetof numplanes")
    static_assert(typeinfo offsetof<planes>(type<model_s>) == 144, "C layout of model_s: offsetof planes")
    static_assert(typeinfo offsetof<numleafs>(type<model_s>) == 152, "C layout of model_s: offsetof numleafs")
    static_assert(typeinfo offsetof<leafs>(type<model_s>) == 160, "C layout of model_s: offsetof leafs")
    static_assert(typeinfo offsetof<numvertexes>(type<model_s>) == 168, "C layout of model_s: offsetof numvertexes")
    static_assert(typeinfo offsetof<vertexes>(type<model_s>) == 176, "C layout of model_s: offsetof vertexes")
    static_assert(typeinfo offsetof<numedges>(type<model_s>) == 184, "C layout of model_s: offsetof numedges")
    static_assert(typeinfo offsetof<edges>(type<model_s>) == 192, "C layout of model_s: offsetof edges")
    static_assert(typeinfo offsetof<numnodes>(type<model_s>) == 200, "C layout of model_s: offsetof numnodes")
    static_assert(typeinfo offsetof<nodes>(type<model_s>) == 208, "C layout of model_s: offsetof nodes")
    static_assert(typeinfo offsetof<numtexinfo>(type<model_s>) == 216, "C layout of model_s: offsetof numtexinfo")
    static_assert(typeinfo offsetof<texinfo>(type<model_s>) == 224, "C layout of model_s: offsetof texinfo")
    static_assert(typeinfo offsetof<numsurfaces>(type<model_s>) == 232, "C layout of model_s: offsetof numsurfaces")
    static_assert(typeinfo offsetof<surfaces>(type<model_s>) == 240, "C layout of model_s: offsetof surfaces")
    static_assert(typeinfo offsetof<numsurfedges>(type<model_s>) == 248, "C layout of model_s: offsetof numsurfedges")
    static_assert(typeinfo offsetof<surfedges>(type<model_s>) == 256, "C layout of model_s: offsetof surfedges")
    static_assert(typeinfo offsetof<numclipnodes>(type<model_s>) == 264, "C layout of model_s: offsetof numclipnodes")
    static_assert(typeinfo offsetof<clipnodes>(type<model_s>) == 272, "C layout of model_s: offsetof clipnodes")
    static_assert(typeinfo offsetof<nummarksurfaces>(type<model_s>) == 280, "C layout of model_s: offsetof nummarksurfaces")
    static_assert(typeinfo offsetof<marksurfaces>(type<model_s>) == 288, "C layout of model_s: offsetof marksurfaces")
    static_assert(typeinfo offsetof<hulls>(type<model_s>) == 296, "C layout of model_s: offsetof hulls")
    static_assert(typeinfo offsetof<numtextures>(type<model_s>) == 488, "C layout of model_s: offsetof numtextures")
    static_assert(typeinfo offsetof<textures>(type<model_s>) == 496, "C layout of model_s: offsetof textures")
    static_assert(typeinfo offsetof<visdata>(type<model_s>) == 504, "C layout of model_s: offsetof visdata")
    static_assert(typeinfo offsetof<lightdata>(type<model_s>) == 512, "C layout of model_s: offsetof lightdata")
    static_assert(typeinfo offsetof<entities>(type<model_s>) == 520, "C layout of model_s: offsetof entities")
    static_assert(typeinfo offsetof<cache>(type<model_s>) == 528, "C layout of model_s: offsetof cache")
    static_assert(typeinfo sizeof(type<texture_t>) == 72, "C layout of texture_t: sizeof")
    static_assert(typeinfo alignof(type<texture_t>) == 8, "C layout of texture_t: alignof")
    static_assert(typeinfo offsetof<name>(type<texture_t>) == 0, "C layout of texture_t: offsetof name")
    static_assert(typeinfo offsetof<width>(type<texture_t>) == 16, "C layout of texture_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<texture_t>) == 20, "C layout of texture_t: offsetof height")
    static_assert(typeinfo offsetof<anim_total>(type<texture_t>) == 24, "C layout of texture_t: offsetof anim_total")
    static_assert(typeinfo offsetof<anim_min>(type<texture_t>) == 28, "C layout of texture_t: offsetof anim_min")
    static_assert(typeinfo offsetof<anim_max>(type<texture_t>) == 32, "C layout of texture_t: offsetof anim_max")
    static_assert(typeinfo offsetof<anim_next>(type<texture_t>) == 40, "C layout of texture_t: offsetof anim_next")
    static_assert(typeinfo offsetof<alternate_anims>(type<texture_t>) == 48, "C layout of texture_t: offsetof alternate_anims")
    static_assert(typeinfo offsetof<offsets>(type<texture_t>) == 56, "C layout of texture_t: offsetof offsets")
    static_assert(typeinfo sizeof(type<texture_s>) == 72, "C layout of texture_s: sizeof")
    static_assert(typeinfo alignof(type<texture_s>) == 8, "C layout of texture_s: alignof")
    static_assert(typeinfo offsetof<name>(type<texture_s>) == 0, "C layout of texture_s: offsetof name")
    static_assert(typeinfo offsetof<width>(type<texture_s>) == 16, "C layout of texture_s: offsetof width")
    static_assert(typeinfo offsetof<height>(type<texture_s>) == 20, "C layout of texture_s: offsetof height")
    static_assert(typeinfo offsetof<anim_total>(type<texture_s>) == 24, "C layout of texture_s: offsetof anim_total")
    static_assert(typeinfo offsetof<anim_min>(type<texture_s>) == 28, "C layout of texture_s: offsetof anim_min")
    static_assert(typeinfo offsetof<anim_max>(type<texture_s>) == 32, "C layout of texture_s: offsetof anim_max")
    static_assert(typeinfo offsetof<anim_next>(type<texture_s>) == 40, "C layout of texture_s: offsetof anim_next")
    static_assert(typeinfo offsetof<alternate_anims>(type<texture_s>) == 48, "C layout of texture_s: offsetof alternate_anims")
    static_assert(typeinfo offsetof<offsets>(type<texture_s>) == 56, "C layout of texture_s: offsetof offsets")
    static_assert(typeinfo sizeof(type<hull_t>) == 48, "C layout of hull_t: sizeof")
    static_assert(typeinfo alignof(type<hull_t>) == 8, "C layout of hull_t: alignof")
    static_assert(typeinfo offsetof<clipnodes>(type<hull_t>) == 0, "C layout of hull_t: offsetof clipnodes")
    static_assert(typeinfo offsetof<planes>(type<hull_t>) == 8, "C layout of hull_t: offsetof planes")
    static_assert(typeinfo offsetof<firstclipnode>(type<hull_t>) == 16, "C layout of hull_t: offsetof firstclipnode")
    static_assert(typeinfo offsetof<lastclipnode>(type<hull_t>) == 20, "C layout of hull_t: offsetof lastclipnode")
    static_assert(typeinfo offsetof<clip_mins>(type<hull_t>) == 24, "C layout of hull_t: offsetof clip_mins")
    static_assert(typeinfo offsetof<clip_maxs>(type<hull_t>) == 36, "C layout of hull_t: offsetof clip_maxs")
    static_assert(typeinfo sizeof(type<msurface_t>) == 104, "C layout of msurface_t: sizeof")
    static_assert(typeinfo alignof(type<msurface_t>) == 8, "C layout of msurface_t: alignof")
    static_assert(typeinfo offsetof<visframe>(type<msurface_t>) == 0, "C layout of msurface_t: offsetof visframe")
    static_assert(typeinfo offsetof<dlightframe>(type<msurface_t>) == 4, "C layout of msurface_t: offsetof dlightframe")
    static_assert(typeinfo offsetof<dlightbits>(type<msurface_t>) == 8, "C layout of msurface_t: offsetof dlightbits")
    static_assert(typeinfo offsetof<plane>(type<msurface_t>) == 16, "C layout of msurface_t: offsetof plane")
    static_assert(typeinfo offsetof<flags>(type<msurface_t>) == 24, "C layout of msurface_t: offsetof flags")
    static_assert(typeinfo offsetof<firstedge>(type<msurface_t>) == 28, "C layout of msurface_t: offsetof firstedge")
    static_assert(typeinfo offsetof<numedges>(type<msurface_t>) == 32, "C layout of msurface_t: offsetof numedges")
    static_assert(typeinfo offsetof<cachespots>(type<msurface_t>) == 40, "C layout of msurface_t: offsetof cachespots")
    static_assert(typeinfo offsetof<texturemins>(type<msurface_t>) == 72, "C layout of msurface_t: offsetof texturemins")
    static_assert(typeinfo offsetof<extents>(type<msurface_t>) == 76, "C layout of msurface_t: offsetof extents")
    static_assert(typeinfo offsetof<texinfo>(type<msurface_t>) == 80, "C layout of msurface_t: offsetof texinfo")
    static_assert(typeinfo offsetof<styles>(type<msurface_t>) == 88, "C layout of msurface_t: offsetof styles")
    static_assert(typeinfo offsetof<samples>(type<msurface_t>) == 96, "C layout of msurface_t: offsetof samples")
    static_assert(typeinfo sizeof(type<msurface_s>) == 104, "C layout of msurface_s: sizeof")
    static_assert(typeinfo alignof(type<msurface_s>) == 8, "C layout of msurface_s: alignof")
    static_assert(typeinfo offsetof<visframe>(type<msurface_s>) == 0, "C layout of msurface_s: offsetof visframe")
    static_assert(typeinfo offsetof<dlightframe>(type<msurface_s>) == 4, "C layout of msurface_s: offsetof dlightframe")
    static_assert(typeinfo offsetof<dlightbits>(type<msurface_s>) == 8, "C layout of msurface_s: offsetof dlightbits")
    static_assert(typeinfo offsetof<plane>(type<msurface_s>) == 16, "C layout of msurface_s: offsetof plane")
    static_assert(typeinfo offsetof<flags>(type<msurface_s>) == 24, "C layout of msurface_s: offsetof flags")
    static_assert(typeinfo offsetof<firstedge>(type<msurface_s>) == 28, "C layout of msurface_s: offsetof firstedge")
    static_assert(typeinfo offsetof<numedges>(type<msurface_s>) == 32, "C layout of msurface_s: offsetof numedges")
    static_assert(typeinfo offsetof<cachespots>(type<msurface_s>) == 40, "C layout of msurface_s: offsetof cachespots")
    static_assert(typeinfo offsetof<texturemins>(type<msurface_s>) == 72, "C layout of msurface_s: offsetof texturemins")
    static_assert(typeinfo offsetof<extents>(type<msurface_s>) == 76, "C layout of msurface_s: offsetof extents")
    static_assert(typeinfo offsetof<texinfo>(type<msurface_s>) == 80, "C layout of msurface_s: offsetof texinfo")
    static_assert(typeinfo offsetof<styles>(type<msurface_s>) == 88, "C layout of msurface_s: offsetof styles")
    static_assert(typeinfo offsetof<samples>(type<msurface_s>) == 96, "C layout of msurface_s: offsetof samples")
    static_assert(typeinfo sizeof(type<mtexinfo_t>) == 56, "C layout of mtexinfo_t: sizeof")
    static_assert(typeinfo alignof(type<mtexinfo_t>) == 8, "C layout of mtexinfo_t: alignof")
    static_assert(typeinfo offsetof<vecs>(type<mtexinfo_t>) == 0, "C layout of mtexinfo_t: offsetof vecs")
    static_assert(typeinfo offsetof<mipadjust>(type<mtexinfo_t>) == 32, "C layout of mtexinfo_t: offsetof mipadjust")
    static_assert(typeinfo offsetof<texture>(type<mtexinfo_t>) == 40, "C layout of mtexinfo_t: offsetof texture")
    static_assert(typeinfo offsetof<flags>(type<mtexinfo_t>) == 48, "C layout of mtexinfo_t: offsetof flags")
    static_assert(typeinfo sizeof(type<surfcache_s>) == 72, "C layout of surfcache_s: sizeof")
    static_assert(typeinfo alignof(type<surfcache_s>) == 8, "C layout of surfcache_s: alignof")
    static_assert(typeinfo offsetof<next>(type<surfcache_s>) == 0, "C layout of surfcache_s: offsetof next")
    static_assert(typeinfo offsetof<owner>(type<surfcache_s>) == 8, "C layout of surfcache_s: offsetof owner")
    static_assert(typeinfo offsetof<lightadj>(type<surfcache_s>) == 16, "C layout of surfcache_s: offsetof lightadj")
    static_assert(typeinfo offsetof<dlight>(type<surfcache_s>) == 32, "C layout of surfcache_s: offsetof dlight")
    static_assert(typeinfo offsetof<size>(type<surfcache_s>) == 36, "C layout of surfcache_s: offsetof size")
    static_assert(typeinfo offsetof<width>(type<surfcache_s>) == 40, "C layout of surfcache_s: offsetof width")
    static_assert(typeinfo offsetof<height>(type<surfcache_s>) == 44, "C layout of surfcache_s: offsetof height")
    static_assert(typeinfo offsetof<mipscale>(type<surfcache_s>) == 48, "C layout of surfcache_s: offsetof mipscale")
    static_assert(typeinfo offsetof<texture>(type<surfcache_s>) == 56, "C layout of surfcache_s: offsetof texture")
    static_assert(typeinfo offsetof<data>(type<surfcache_s>) == 64, "C layout of surfcache_s: offsetof data")
    static_assert(typeinfo sizeof(type<mnode_t>) == 64, "C layout of mnode_t: sizeof")
    static_assert(typeinfo alignof(type<mnode_t>) == 8, "C layout of mnode_t: alignof")
    static_assert(typeinfo offsetof<contents>(type<mnode_t>) == 0, "C layout of mnode_t: offsetof contents")
    static_assert(typeinfo offsetof<visframe>(type<mnode_t>) == 4, "C layout of mnode_t: offsetof visframe")
    static_assert(typeinfo offsetof<minmaxs>(type<mnode_t>) == 8, "C layout of mnode_t: offsetof minmaxs")
    static_assert(typeinfo offsetof<parent>(type<mnode_t>) == 24, "C layout of mnode_t: offsetof parent")
    static_assert(typeinfo offsetof<plane>(type<mnode_t>) == 32, "C layout of mnode_t: offsetof plane")
    static_assert(typeinfo offsetof<children>(type<mnode_t>) == 40, "C layout of mnode_t: offsetof children")
    static_assert(typeinfo offsetof<firstsurface>(type<mnode_t>) == 56, "C layout of mnode_t: offsetof firstsurface")
    static_assert(typeinfo offsetof<numsurfaces>(type<mnode_t>) == 58, "C layout of mnode_t: offsetof numsurfaces")
    static_assert(typeinfo sizeof(type<medge_t>) == 8, "C layout of medge_t: sizeof")
    static_assert(typeinfo alignof(type<medge_t>) == 4, "C layout of medge_t: alignof")
    static_assert(typeinfo offsetof<v>(type<medge_t>) == 0, "C layout of medge_t: offsetof v")
    static_assert(typeinfo offsetof<cachededgeoffset>(type<medge_t>) == 4, "C layout of medge_t: offsetof cachededgeoffset")
    static_assert(typeinfo sizeof(type<mvertex_t>) == 12, "C layout of mvertex_t: sizeof")
    static_assert(typeinfo alignof(type<mvertex_t>) == 4, "C layout of mvertex_t: alignof")
    static_assert(typeinfo offsetof<position>(type<mvertex_t>) == 0, "C layout of mvertex_t: offsetof position")
    static_assert(typeinfo sizeof(type<mleaf_t>) == 72, "C layout of mleaf_t: sizeof")
    static_assert(typeinfo alignof(type<mleaf_t>) == 8, "C layout of mleaf_t: alignof")
    static_assert(typeinfo offsetof<contents>(type<mleaf_t>) == 0, "C layout of mleaf_t: offsetof contents")
    static_assert(typeinfo offsetof<visframe>(type<mleaf_t>) == 4, "C layout of mleaf_t: offsetof visframe")
    static_assert(typeinfo offsetof<minmaxs>(type<mleaf_t>) == 8, "C layout of mleaf_t: offsetof minmaxs")
    static_assert(typeinfo offsetof<parent>(type<mleaf_t>) == 24, "C layout of mleaf_t: offsetof parent")
    static_assert(typeinfo offsetof<compressed_vis>(type<mleaf_t>) == 32, "C layout of mleaf_t: offsetof compressed_vis")
    static_assert(typeinfo offsetof<efrags>(type<mleaf_t>) == 40, "C layout of mleaf_t: offsetof efrags")
    static_assert(typeinfo offsetof<firstmarksurface>(type<mleaf_t>) == 48, "C layout of mleaf_t: offsetof firstmarksurface")
    static_assert(typeinfo offsetof<nummarksurfaces>(type<mleaf_t>) == 56, "C layout of mleaf_t: offsetof nummarksurfaces")
    static_assert(typeinfo offsetof<key>(type<mleaf_t>) == 60, "C layout of mleaf_t: offsetof key")
    static_assert(typeinfo offsetof<ambient_sound_level>(type<mleaf_t>) == 64, "C layout of mleaf_t: offsetof ambient_sound_level")
    static_assert(typeinfo sizeof(type<mleaf_s>) == 72, "C layout of mleaf_s: sizeof")
    static_assert(typeinfo alignof(type<mleaf_s>) == 8, "C layout of mleaf_s: alignof")
    static_assert(typeinfo offsetof<contents>(type<mleaf_s>) == 0, "C layout of mleaf_s: offsetof contents")
    static_assert(typeinfo offsetof<visframe>(type<mleaf_s>) == 4, "C layout of mleaf_s: offsetof visframe")
    static_assert(typeinfo offsetof<minmaxs>(type<mleaf_s>) == 8, "C layout of mleaf_s: offsetof minmaxs")
    static_assert(typeinfo offsetof<parent>(type<mleaf_s>) == 24, "C layout of mleaf_s: offsetof parent")
    static_assert(typeinfo offsetof<compressed_vis>(type<mleaf_s>) == 32, "C layout of mleaf_s: offsetof compressed_vis")
    static_assert(typeinfo offsetof<efrags>(type<mleaf_s>) == 40, "C layout of mleaf_s: offsetof efrags")
    static_assert(typeinfo offsetof<firstmarksurface>(type<mleaf_s>) == 48, "C layout of mleaf_s: offsetof firstmarksurface")
    static_assert(typeinfo offsetof<nummarksurfaces>(type<mleaf_s>) == 56, "C layout of mleaf_s: offsetof nummarksurfaces")
    static_assert(typeinfo offsetof<key>(type<mleaf_s>) == 60, "C layout of mleaf_s: offsetof key")
    static_assert(typeinfo offsetof<ambient_sound_level>(type<mleaf_s>) == 64, "C layout of mleaf_s: offsetof ambient_sound_level")
    static_assert(typeinfo sizeof(type<efrag_t>) == 32, "C layout of efrag_t: sizeof")
    static_assert(typeinfo alignof(type<efrag_t>) == 8, "C layout of efrag_t: alignof")
    static_assert(typeinfo offsetof<leaf>(type<efrag_t>) == 0, "C layout of efrag_t: offsetof leaf")
    static_assert(typeinfo offsetof<leafnext>(type<efrag_t>) == 8, "C layout of efrag_t: offsetof leafnext")
    static_assert(typeinfo offsetof<entity>(type<efrag_t>) == 16, "C layout of efrag_t: offsetof entity")
    static_assert(typeinfo offsetof<entnext>(type<efrag_t>) == 24, "C layout of efrag_t: offsetof entnext")
    static_assert(typeinfo sizeof(type<entity_t>) == 200, "C layout of entity_t: sizeof")
    static_assert(typeinfo alignof(type<entity_t>) == 8, "C layout of entity_t: alignof")
    static_assert(typeinfo offsetof<forcelink>(type<entity_t>) == 0, "C layout of entity_t: offsetof forcelink")
    static_assert(typeinfo offsetof<update_type>(type<entity_t>) == 4, "C layout of entity_t: offsetof update_type")
    static_assert(typeinfo offsetof<baseline>(type<entity_t>) == 8, "C layout of entity_t: offsetof baseline")
    static_assert(typeinfo offsetof<msgtime>(type<entity_t>) == 56, "C layout of entity_t: offsetof msgtime")
    static_assert(typeinfo offsetof<msg_origins>(type<entity_t>) == 64, "C layout of entity_t: offsetof msg_origins")
    static_assert(typeinfo offsetof<origin>(type<entity_t>) == 88, "C layout of entity_t: offsetof origin")
    static_assert(typeinfo offsetof<msg_angles>(type<entity_t>) == 100, "C layout of entity_t: offsetof msg_angles")
    static_assert(typeinfo offsetof<angles>(type<entity_t>) == 124, "C layout of entity_t: offsetof angles")
    static_assert(typeinfo offsetof<model>(type<entity_t>) == 136, "C layout of entity_t: offsetof model")
    static_assert(typeinfo offsetof<efrag>(type<entity_t>) == 144, "C layout of entity_t: offsetof efrag")
    static_assert(typeinfo offsetof<frame>(type<entity_t>) == 152, "C layout of entity_t: offsetof frame")
    static_assert(typeinfo offsetof<syncbase>(type<entity_t>) == 156, "C layout of entity_t: offsetof syncbase")
    static_assert(typeinfo offsetof<colormap>(type<entity_t>) == 160, "C layout of entity_t: offsetof colormap")
    static_assert(typeinfo offsetof<effects>(type<entity_t>) == 168, "C layout of entity_t: offsetof effects")
    static_assert(typeinfo offsetof<skinnum>(type<entity_t>) == 172, "C layout of entity_t: offsetof skinnum")
    static_assert(typeinfo offsetof<visframe>(type<entity_t>) == 176, "C layout of entity_t: offsetof visframe")
    static_assert(typeinfo offsetof<dlightframe>(type<entity_t>) == 180, "C layout of entity_t: offsetof dlightframe")
    static_assert(typeinfo offsetof<dlightbits>(type<entity_t>) == 184, "C layout of entity_t: offsetof dlightbits")
    static_assert(typeinfo offsetof<trivial_accept>(type<entity_t>) == 188, "C layout of entity_t: offsetof trivial_accept")
    static_assert(typeinfo offsetof<topnode>(type<entity_t>) == 192, "C layout of entity_t: offsetof topnode")
    static_assert(typeinfo sizeof(type<refdef_t>) == 160, "C layout of refdef_t: sizeof")
    static_assert(typeinfo alignof(type<refdef_t>) == 8, "C layout of refdef_t: alignof")
    static_assert(typeinfo offsetof<vrect>(type<refdef_t>) == 0, "C layout of refdef_t: offsetof vrect")
    static_assert(typeinfo offsetof<aliasvrect>(type<refdef_t>) == 24, "C layout of refdef_t: offsetof aliasvrect")
    static_assert(typeinfo offsetof<vrectright>(type<refdef_t>) == 48, "C layout of refdef_t: offsetof vrectright")
    static_assert(typeinfo offsetof<vrectbottom>(type<refdef_t>) == 52, "C layout of refdef_t: offsetof vrectbottom")
    static_assert(typeinfo offsetof<aliasvrectright>(type<refdef_t>) == 56, "C layout of refdef_t: offsetof aliasvrectright")
    static_assert(typeinfo offsetof<aliasvrectbottom>(type<refdef_t>) == 60, "C layout of refdef_t: offsetof aliasvrectbottom")
    static_assert(typeinfo offsetof<vrectrightedge>(type<refdef_t>) == 64, "C layout of refdef_t: offsetof vrectrightedge")
    static_assert(typeinfo offsetof<fvrectx>(type<refdef_t>) == 68, "C layout of refdef_t: offsetof fvrectx")
    static_assert(typeinfo offsetof<fvrecty>(type<refdef_t>) == 72, "C layout of refdef_t: offsetof fvrecty")
    static_assert(typeinfo offsetof<fvrectx_adj>(type<refdef_t>) == 76, "C layout of refdef_t: offsetof fvrectx_adj")
    static_assert(typeinfo offsetof<fvrecty_adj>(type<refdef_t>) == 80, "C layout of refdef_t: offsetof fvrecty_adj")
    static_assert(typeinfo offsetof<vrect_x_adj_shift20>(type<refdef_t>) == 84, "C layout of refdef_t: offsetof vrect_x_adj_shift20")
    static_assert(typeinfo offsetof<vrectright_adj_shift20>(type<refdef_t>) == 88, "C layout of refdef_t: offsetof vrectright_adj_shift20")
    static_assert(typeinfo offsetof<fvrectright_adj>(type<refdef_t>) == 92, "C layout of refdef_t: offsetof fvrectright_adj")
    static_assert(typeinfo offsetof<fvrectbottom_adj>(type<refdef_t>) == 96, "C layout of refdef_t: offsetof fvrectbottom_adj")
    static_assert(typeinfo offsetof<fvrectright>(type<refdef_t>) == 100, "C layout of refdef_t: offsetof fvrectright")
    static_assert(typeinfo offsetof<fvrectbottom>(type<refdef_t>) == 104, "C layout of refdef_t: offsetof fvrectbottom")
    static_assert(typeinfo offsetof<horizontalFieldOfView>(type<refdef_t>) == 108, "C layout of refdef_t: offsetof horizontalFieldOfView")
    static_assert(typeinfo offsetof<xOrigin>(type<refdef_t>) == 112, "C layout of refdef_t: offsetof xOrigin")
    static_assert(typeinfo offsetof<yOrigin>(type<refdef_t>) == 116, "C layout of refdef_t: offsetof yOrigin")
    static_assert(typeinfo offsetof<vieworg>(type<refdef_t>) == 120, "C layout of refdef_t: offsetof vieworg")
    static_assert(typeinfo offsetof<viewangles>(type<refdef_t>) == 132, "C layout of refdef_t: offsetof viewangles")
    static_assert(typeinfo offsetof<fov_x>(type<refdef_t>) == 144, "C layout of refdef_t: offsetof fov_x")
    static_assert(typeinfo offsetof<fov_y>(type<refdef_t>) == 148, "C layout of refdef_t: offsetof fov_y")
    static_assert(typeinfo offsetof<ambientlight>(type<refdef_t>) == 152, "C layout of refdef_t: offsetof ambientlight")
    static_assert(typeinfo sizeof(type<model_t>) == 536, "C layout of model_t: sizeof")
    static_assert(typeinfo alignof(type<model_t>) == 8, "C layout of model_t: alignof")
    static_assert(typeinfo offsetof<name>(type<model_t>) == 0, "C layout of model_t: offsetof name")
    static_assert(typeinfo offsetof<needload>(type<model_t>) == 64, "C layout of model_t: offsetof needload")
    static_assert(typeinfo offsetof<type_0>(type<model_t>) == 68, "C layout of model_t: offsetof type_0")
    static_assert(typeinfo offsetof<numframes>(type<model_t>) == 72, "C layout of model_t: offsetof numframes")
    static_assert(typeinfo offsetof<synctype>(type<model_t>) == 76, "C layout of model_t: offsetof synctype")
    static_assert(typeinfo offsetof<flags>(type<model_t>) == 80, "C layout of model_t: offsetof flags")
    static_assert(typeinfo offsetof<mins>(type<model_t>) == 84, "C layout of model_t: offsetof mins")
    static_assert(typeinfo offsetof<maxs>(type<model_t>) == 96, "C layout of model_t: offsetof maxs")
    static_assert(typeinfo offsetof<radius>(type<model_t>) == 108, "C layout of model_t: offsetof radius")
    static_assert(typeinfo offsetof<firstmodelsurface>(type<model_t>) == 112, "C layout of model_t: offsetof firstmodelsurface")
    static_assert(typeinfo offsetof<nummodelsurfaces>(type<model_t>) == 116, "C layout of model_t: offsetof nummodelsurfaces")
    static_assert(typeinfo offsetof<numsubmodels>(type<model_t>) == 120, "C layout of model_t: offsetof numsubmodels")
    static_assert(typeinfo offsetof<submodels>(type<model_t>) == 128, "C layout of model_t: offsetof submodels")
    static_assert(typeinfo offsetof<numplanes>(type<model_t>) == 136, "C layout of model_t: offsetof numplanes")
    static_assert(typeinfo offsetof<planes>(type<model_t>) == 144, "C layout of model_t: offsetof planes")
    static_assert(typeinfo offsetof<numleafs>(type<model_t>) == 152, "C layout of model_t: offsetof numleafs")
    static_assert(typeinfo offsetof<leafs>(type<model_t>) == 160, "C layout of model_t: offsetof leafs")
    static_assert(typeinfo offsetof<numvertexes>(type<model_t>) == 168, "C layout of model_t: offsetof numvertexes")
    static_assert(typeinfo offsetof<vertexes>(type<model_t>) == 176, "C layout of model_t: offsetof vertexes")
    static_assert(typeinfo offsetof<numedges>(type<model_t>) == 184, "C layout of model_t: offsetof numedges")
    static_assert(typeinfo offsetof<edges>(type<model_t>) == 192, "C layout of model_t: offsetof edges")
    static_assert(typeinfo offsetof<numnodes>(type<model_t>) == 200, "C layout of model_t: offsetof numnodes")
    static_assert(typeinfo offsetof<nodes>(type<model_t>) == 208, "C layout of model_t: offsetof nodes")
    static_assert(typeinfo offsetof<numtexinfo>(type<model_t>) == 216, "C layout of model_t: offsetof numtexinfo")
    static_assert(typeinfo offsetof<texinfo>(type<model_t>) == 224, "C layout of model_t: offsetof texinfo")
    static_assert(typeinfo offsetof<numsurfaces>(type<model_t>) == 232, "C layout of model_t: offsetof numsurfaces")
    static_assert(typeinfo offsetof<surfaces>(type<model_t>) == 240, "C layout of model_t: offsetof surfaces")
    static_assert(typeinfo offsetof<numsurfedges>(type<model_t>) == 248, "C layout of model_t: offsetof numsurfedges")
    static_assert(typeinfo offsetof<surfedges>(type<model_t>) == 256, "C layout of model_t: offsetof surfedges")
    static_assert(typeinfo offsetof<numclipnodes>(type<model_t>) == 264, "C layout of model_t: offsetof numclipnodes")
    static_assert(typeinfo offsetof<clipnodes>(type<model_t>) == 272, "C layout of model_t: offsetof clipnodes")
    static_assert(typeinfo offsetof<nummarksurfaces>(type<model_t>) == 280, "C layout of model_t: offsetof nummarksurfaces")
    static_assert(typeinfo offsetof<marksurfaces>(type<model_t>) == 288, "C layout of model_t: offsetof marksurfaces")
    static_assert(typeinfo offsetof<hulls>(type<model_t>) == 296, "C layout of model_t: offsetof hulls")
    static_assert(typeinfo offsetof<numtextures>(type<model_t>) == 488, "C layout of model_t: offsetof numtextures")
    static_assert(typeinfo offsetof<textures>(type<model_t>) == 496, "C layout of model_t: offsetof textures")
    static_assert(typeinfo offsetof<visdata>(type<model_t>) == 504, "C layout of model_t: offsetof visdata")
    static_assert(typeinfo offsetof<lightdata>(type<model_t>) == 512, "C layout of model_t: offsetof lightdata")
    static_assert(typeinfo offsetof<entities>(type<model_t>) == 520, "C layout of model_t: offsetof entities")
    static_assert(typeinfo offsetof<cache>(type<model_t>) == 528, "C layout of model_t: offsetof cache")
    static_assert(typeinfo sizeof(type<polyvert_s>) == 20, "C layout of polyvert_s: sizeof")
    static_assert(typeinfo alignof(type<polyvert_s>) == 4, "C layout of polyvert_s: alignof")
    static_assert(typeinfo offsetof<u>(type<polyvert_s>) == 0, "C layout of polyvert_s: offsetof u")
    static_assert(typeinfo offsetof<v>(type<polyvert_s>) == 4, "C layout of polyvert_s: offsetof v")
    static_assert(typeinfo offsetof<zi>(type<polyvert_s>) == 8, "C layout of polyvert_s: offsetof zi")
    static_assert(typeinfo offsetof<s>(type<polyvert_s>) == 12, "C layout of polyvert_s: offsetof s")
    static_assert(typeinfo offsetof<t>(type<polyvert_s>) == 16, "C layout of polyvert_s: offsetof t")
    static_assert(typeinfo sizeof(type<polyvert_t>) == 20, "C layout of polyvert_t: sizeof")
    static_assert(typeinfo alignof(type<polyvert_t>) == 4, "C layout of polyvert_t: alignof")
    static_assert(typeinfo offsetof<u>(type<polyvert_t>) == 0, "C layout of polyvert_t: offsetof u")
    static_assert(typeinfo offsetof<v>(type<polyvert_t>) == 4, "C layout of polyvert_t: offsetof v")
    static_assert(typeinfo offsetof<zi>(type<polyvert_t>) == 8, "C layout of polyvert_t: offsetof zi")
    static_assert(typeinfo offsetof<s>(type<polyvert_t>) == 12, "C layout of polyvert_t: offsetof s")
    static_assert(typeinfo offsetof<t>(type<polyvert_t>) == 16, "C layout of polyvert_t: offsetof t")
    static_assert(typeinfo sizeof(type<polydesc_s>) == 24, "C layout of polydesc_s: sizeof")
    static_assert(typeinfo alignof(type<polydesc_s>) == 8, "C layout of polydesc_s: alignof")
    static_assert(typeinfo offsetof<numverts>(type<polydesc_s>) == 0, "C layout of polydesc_s: offsetof numverts")
    static_assert(typeinfo offsetof<nearzi>(type<polydesc_s>) == 4, "C layout of polydesc_s: offsetof nearzi")
    static_assert(typeinfo offsetof<pcurrentface>(type<polydesc_s>) == 8, "C layout of polydesc_s: offsetof pcurrentface")
    static_assert(typeinfo offsetof<pverts>(type<polydesc_s>) == 16, "C layout of polydesc_s: offsetof pverts")
    static_assert(typeinfo sizeof(type<polydesc_t>) == 24, "C layout of polydesc_t: sizeof")
    static_assert(typeinfo alignof(type<polydesc_t>) == 8, "C layout of polydesc_t: alignof")
    static_assert(typeinfo offsetof<numverts>(type<polydesc_t>) == 0, "C layout of polydesc_t: offsetof numverts")
    static_assert(typeinfo offsetof<nearzi>(type<polydesc_t>) == 4, "C layout of polydesc_t: offsetof nearzi")
    static_assert(typeinfo offsetof<pcurrentface>(type<polydesc_t>) == 8, "C layout of polydesc_t: offsetof pcurrentface")
    static_assert(typeinfo offsetof<pverts>(type<polydesc_t>) == 16, "C layout of polydesc_t: offsetof pverts")
    static_assert(typeinfo sizeof(type<zpointdesc_t>) == 16, "C layout of zpointdesc_t: sizeof")
    static_assert(typeinfo alignof(type<zpointdesc_t>) == 4, "C layout of zpointdesc_t: alignof")
    static_assert(typeinfo offsetof<u>(type<zpointdesc_t>) == 0, "C layout of zpointdesc_t: offsetof u")
    static_assert(typeinfo offsetof<v>(type<zpointdesc_t>) == 4, "C layout of zpointdesc_t: offsetof v")
    static_assert(typeinfo offsetof<zi>(type<zpointdesc_t>) == 8, "C layout of zpointdesc_t: offsetof zi")
    static_assert(typeinfo offsetof<color>(type<zpointdesc_t>) == 12, "C layout of zpointdesc_t: offsetof color")
    static_assert(typeinfo sizeof(type<espan_s>) == 24, "C layout of espan_s: sizeof")
    static_assert(typeinfo alignof(type<espan_s>) == 8, "C layout of espan_s: alignof")
    static_assert(typeinfo offsetof<u>(type<espan_s>) == 0, "C layout of espan_s: offsetof u")
    static_assert(typeinfo offsetof<v>(type<espan_s>) == 4, "C layout of espan_s: offsetof v")
    static_assert(typeinfo offsetof<count>(type<espan_s>) == 8, "C layout of espan_s: offsetof count")
    static_assert(typeinfo offsetof<pnext>(type<espan_s>) == 16, "C layout of espan_s: offsetof pnext")
    static_assert(typeinfo sizeof(type<surf_s>) == 88, "C layout of surf_s: sizeof")
    static_assert(typeinfo alignof(type<surf_s>) == 8, "C layout of surf_s: alignof")
    static_assert(typeinfo offsetof<next>(type<surf_s>) == 0, "C layout of surf_s: offsetof next")
    static_assert(typeinfo offsetof<prev>(type<surf_s>) == 8, "C layout of surf_s: offsetof prev")
    static_assert(typeinfo offsetof<spans>(type<surf_s>) == 16, "C layout of surf_s: offsetof spans")
    static_assert(typeinfo offsetof<key>(type<surf_s>) == 24, "C layout of surf_s: offsetof key")
    static_assert(typeinfo offsetof<last_u>(type<surf_s>) == 28, "C layout of surf_s: offsetof last_u")
    static_assert(typeinfo offsetof<spanstate>(type<surf_s>) == 32, "C layout of surf_s: offsetof spanstate")
    static_assert(typeinfo offsetof<flags>(type<surf_s>) == 36, "C layout of surf_s: offsetof flags")
    static_assert(typeinfo offsetof<data>(type<surf_s>) == 40, "C layout of surf_s: offsetof data")
    static_assert(typeinfo offsetof<entity>(type<surf_s>) == 48, "C layout of surf_s: offsetof entity")
    static_assert(typeinfo offsetof<nearzi>(type<surf_s>) == 56, "C layout of surf_s: offsetof nearzi")
    static_assert(typeinfo offsetof<insubmodel>(type<surf_s>) == 60, "C layout of surf_s: offsetof insubmodel")
    static_assert(typeinfo offsetof<d_ziorigin>(type<surf_s>) == 64, "C layout of surf_s: offsetof d_ziorigin")
    static_assert(typeinfo offsetof<d_zistepu>(type<surf_s>) == 68, "C layout of surf_s: offsetof d_zistepu")
    static_assert(typeinfo offsetof<d_zistepv>(type<surf_s>) == 72, "C layout of surf_s: offsetof d_zistepv")
    static_assert(typeinfo offsetof<pad>(type<surf_s>) == 76, "C layout of surf_s: offsetof pad")
    static_assert(typeinfo sizeof(type<surf_t>) == 88, "C layout of surf_t: sizeof")
    static_assert(typeinfo alignof(type<surf_t>) == 8, "C layout of surf_t: alignof")
    static_assert(typeinfo offsetof<next>(type<surf_t>) == 0, "C layout of surf_t: offsetof next")
    static_assert(typeinfo offsetof<prev>(type<surf_t>) == 8, "C layout of surf_t: offsetof prev")
    static_assert(typeinfo offsetof<spans>(type<surf_t>) == 16, "C layout of surf_t: offsetof spans")
    static_assert(typeinfo offsetof<key>(type<surf_t>) == 24, "C layout of surf_t: offsetof key")
    static_assert(typeinfo offsetof<last_u>(type<surf_t>) == 28, "C layout of surf_t: offsetof last_u")
    static_assert(typeinfo offsetof<spanstate>(type<surf_t>) == 32, "C layout of surf_t: offsetof spanstate")
    static_assert(typeinfo offsetof<flags>(type<surf_t>) == 36, "C layout of surf_t: offsetof flags")
    static_assert(typeinfo offsetof<data>(type<surf_t>) == 40, "C layout of surf_t: offsetof data")
    static_assert(typeinfo offsetof<entity>(type<surf_t>) == 48, "C layout of surf_t: offsetof entity")
    static_assert(typeinfo offsetof<nearzi>(type<surf_t>) == 56, "C layout of surf_t: offsetof nearzi")
    static_assert(typeinfo offsetof<insubmodel>(type<surf_t>) == 60, "C layout of surf_t: offsetof insubmodel")
    static_assert(typeinfo offsetof<d_ziorigin>(type<surf_t>) == 64, "C layout of surf_t: offsetof d_ziorigin")
    static_assert(typeinfo offsetof<d_zistepu>(type<surf_t>) == 68, "C layout of surf_t: offsetof d_zistepu")
    static_assert(typeinfo offsetof<d_zistepv>(type<surf_t>) == 72, "C layout of surf_t: offsetof d_zistepv")
    static_assert(typeinfo offsetof<pad>(type<surf_t>) == 76, "C layout of surf_t: offsetof pad")
    static_assert(typeinfo sizeof(type<edge_s>) == 56, "C layout of edge_s: sizeof")
    static_assert(typeinfo alignof(type<edge_s>) == 8, "C layout of edge_s: alignof")
    static_assert(typeinfo offsetof<u>(type<edge_s>) == 0, "C layout of edge_s: offsetof u")
    static_assert(typeinfo offsetof<u_step>(type<edge_s>) == 4, "C layout of edge_s: offsetof u_step")
    static_assert(typeinfo offsetof<prev>(type<edge_s>) == 8, "C layout of edge_s: offsetof prev")
    static_assert(typeinfo offsetof<next>(type<edge_s>) == 16, "C layout of edge_s: offsetof next")
    static_assert(typeinfo offsetof<surfs>(type<edge_s>) == 24, "C layout of edge_s: offsetof surfs")
    static_assert(typeinfo offsetof<nextremove>(type<edge_s>) == 32, "C layout of edge_s: offsetof nextremove")
    static_assert(typeinfo offsetof<nearzi>(type<edge_s>) == 40, "C layout of edge_s: offsetof nearzi")
    static_assert(typeinfo offsetof<owner>(type<edge_s>) == 48, "C layout of edge_s: offsetof owner")
    static_assert(typeinfo sizeof(type<edge_t>) == 56, "C layout of edge_t: sizeof")
    static_assert(typeinfo alignof(type<edge_t>) == 8, "C layout of edge_t: alignof")
    static_assert(typeinfo offsetof<u>(type<edge_t>) == 0, "C layout of edge_t: offsetof u")
    static_assert(typeinfo offsetof<u_step>(type<edge_t>) == 4, "C layout of edge_t: offsetof u_step")
    static_assert(typeinfo offsetof<prev>(type<edge_t>) == 8, "C layout of edge_t: offsetof prev")
    static_assert(typeinfo offsetof<next>(type<edge_t>) == 16, "C layout of edge_t: offsetof next")
    static_assert(typeinfo offsetof<surfs>(type<edge_t>) == 24, "C layout of edge_t: offsetof surfs")
    static_assert(typeinfo offsetof<nextremove>(type<edge_t>) == 32, "C layout of edge_t: offsetof nextremove")
    static_assert(typeinfo offsetof<nearzi>(type<edge_t>) == 40, "C layout of edge_t: offsetof nearzi")
    static_assert(typeinfo offsetof<owner>(type<edge_t>) == 48, "C layout of edge_t: offsetof owner")
    static_assert(typeinfo sizeof(type<bedge_s>) == 24, "C layout of bedge_s: sizeof")
    static_assert(typeinfo alignof(type<bedge_s>) == 8, "C layout of bedge_s: alignof")
    static_assert(typeinfo offsetof<v>(type<bedge_s>) == 0, "C layout of bedge_s: offsetof v")
    static_assert(typeinfo offsetof<pnext>(type<bedge_s>) == 16, "C layout of bedge_s: offsetof pnext")
    static_assert(typeinfo sizeof(type<bedge_t>) == 24, "C layout of bedge_t: sizeof")
    static_assert(typeinfo alignof(type<bedge_t>) == 8, "C layout of bedge_t: alignof")
    static_assert(typeinfo offsetof<v>(type<bedge_t>) == 0, "C layout of bedge_t: offsetof v")
    static_assert(typeinfo offsetof<pnext>(type<bedge_t>) == 16, "C layout of bedge_t: offsetof pnext")
    static_assert(typeinfo sizeof(type<clipplane_s>) == 32, "C layout of clipplane_s: sizeof")
    static_assert(typeinfo alignof(type<clipplane_s>) == 8, "C layout of clipplane_s: alignof")
    static_assert(typeinfo offsetof<normal>(type<clipplane_s>) == 0, "C layout of clipplane_s: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<clipplane_s>) == 12, "C layout of clipplane_s: offsetof dist")
    static_assert(typeinfo offsetof<next>(type<clipplane_s>) == 16, "C layout of clipplane_s: offsetof next")
    static_assert(typeinfo offsetof<leftedge>(type<clipplane_s>) == 24, "C layout of clipplane_s: offsetof leftedge")
    static_assert(typeinfo offsetof<rightedge>(type<clipplane_s>) == 25, "C layout of clipplane_s: offsetof rightedge")
    static_assert(typeinfo offsetof<reserved>(type<clipplane_s>) == 26, "C layout of clipplane_s: offsetof reserved")
    static_assert(typeinfo sizeof(type<clipplane_t>) == 32, "C layout of clipplane_t: sizeof")
    static_assert(typeinfo alignof(type<clipplane_t>) == 8, "C layout of clipplane_t: alignof")
    static_assert(typeinfo offsetof<normal>(type<clipplane_t>) == 0, "C layout of clipplane_t: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<clipplane_t>) == 12, "C layout of clipplane_t: offsetof dist")
    static_assert(typeinfo offsetof<next>(type<clipplane_t>) == 16, "C layout of clipplane_t: offsetof next")
    static_assert(typeinfo offsetof<leftedge>(type<clipplane_t>) == 24, "C layout of clipplane_t: offsetof leftedge")
    static_assert(typeinfo offsetof<rightedge>(type<clipplane_t>) == 25, "C layout of clipplane_t: offsetof rightedge")
    static_assert(typeinfo offsetof<reserved>(type<clipplane_t>) == 26, "C layout of clipplane_t: offsetof reserved")
}
