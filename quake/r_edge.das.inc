var surfaces : surf_s? = default<surf_s?>

var surface_p : surf_s? = default<surf_s?>

var surf_max : surf_s? = default<surf_s?>

[export, sideeffects]
def R_BeginEdgeFrame() {
    var v : int
    edge_p = unsafe(reinterpret<edge_s?>(r_edges))
    edge_max = unsafe(addr<edge_s?>(unsafe(r_edges[int(r_numallocatededges)])))
    surface_p = unsafe(addr<surf_s?>(unsafe(surfaces[2])))
    unsafe(surfaces[1]).spans = null
    unsafe(surfaces[1]).flags = 64
    if (r_draworder.value != 0.0) {
        pdrawfunc = @@R_GenerateSpansBackward
        unsafe(surfaces[1]).key = 0
        r_currentkey = 1
    } else {
        pdrawfunc = @@R_GenerateSpans
        unsafe(surfaces[1]).key = 2147483647
        r_currentkey = 0
    }
    v = r_refdef.vrect.y
    while (v < r_refdef.vrectbottom) {
        removeedges[v] = null
        newedges[v] = unsafe(reinterpret<edge_s?>(removeedges[v]))
        v++
    }
    return
}
var removeedges : edge_s? [1024]

var newedges : edge_s? [1024]

var r_currentkey : int = default<int>

[export, sideeffects]
def R_GenerateSpans() {
    var edge : edge_s?
    var surf : surf_s?
    r_bmodelactive = 0
    unsafe(surfaces[1]).prev = unsafe(addr<surf_s?>(unsafe(surfaces[1])))
    unsafe(surfaces[1]).next = unsafe(reinterpret<surf_s?>(unsafe(surfaces[1]).prev))
    unsafe(surfaces[1]).last_u = int(edge_head_u_shift20)  // nolint:PERF020
    edge = unsafe(reinterpret<edge_s?>(edge_head.next))
    while (edge != unsafe(addr(edge_tail))) {
        var c2da_fresh0 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(edge)) + 24ul))
        if (unsafe(unsafe(reinterpret<uint16?>(c2da_fresh0))[0]) != 0x0) {
            var c2da_fresh1 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(edge)) + 24ul))
            surf = unsafe(addr<surf_s?>(unsafe(surfaces[int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh1))[0]))])))
            R_TrailingEdge(surf, edge)
            var c2da_fresh2 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(edge)) + 24ul))
            if (unsafe(unsafe(reinterpret<uint16?>(c2da_fresh2))[1]) == 0) {
                edge = unsafe(reinterpret<edge_s?>(edge.next))
                continue
            }
        }
        R_LeadingEdge(edge)
        edge = unsafe(reinterpret<edge_s?>(edge.next))
    }
    R_CleanupSpan()
    return
}
[export, sideeffects]
def R_CleanupSpan() {
    var surf_0 : surf_s?
    var iu : int
    var span : espan_s?
    surf_0 = unsafe(reinterpret<surf_s?>(unsafe(surfaces[1]).next))
    iu = edge_tail_u_shift20
    if (iu > surf_0.last_u) {
        var c2da_postinc : espan_s? = span_p
        unsafe {  // nolint:STYLE025
            span_p += 1
        }
        span = unsafe(reinterpret<espan_s?>(c2da_postinc))
        span.u = int(surf_0.last_u)  // nolint:PERF020
        span.count = iu - span.u
        span.v = int(current_iv)  // nolint:PERF020
        span.pnext = surf_0.spans
        surf_0.spans = span
    }
    while (true) {
        surf_0.spanstate = 0
        surf_0 = unsafe(reinterpret<surf_s?>(surf_0.next))
        if (surf_0 == unsafe(addr(unsafe(surfaces[1])))) {
            break
        }
    }
    return
}
var current_iv : int = default<int>

var span_p : espan_s? = default<espan_s?>

var edge_tail_u_shift20 : int = default<int>

[export, sideeffects]
def R_LeadingEdge(var edge_0 : edge_s?) {
    var span_0 : espan_s?
    var surf_1 : surf_s?
    var surf2 : surf_s?
    var iu_0 : int
    var fu : double
    var newzi : double
    var testzi : double
    var newzitop : double
    var newzibottom : double
    var c2da_fresh3 : uint16?
    var c2da_fresh4 : uint16?
    var c2da_postinc_0 : int
    var c2da_postinc_1 : espan_s?
    c2da_fresh3 = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(edge_0)) + 24ul))
    if (unsafe(unsafe(reinterpret<uint16?>(c2da_fresh3))[1]) != 0x0) {
        goto label 1
    }
    label 0:
    return
    label 1:
    c2da_fresh4 = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(edge_0)) + 24ul))
    surf_1 = unsafe(addr<surf_s?>(unsafe(surfaces[int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh4))[1]))])))
    c2da_postinc_0 = surf_1.spanstate
    surf_1.spanstate = c2da_postinc_0 + 1
    if (c2da_postinc_0 + 1 == 1) {
        goto label 3
    }
    label 2:
    goto label 0
    label 3:
    if (uint(surf_1.insubmodel) != 0u) {
        goto label 24
    }
    label 4:
    surf2 = unsafe(reinterpret<surf_s?>(unsafe(surfaces[1]).next))
    if (surf_1.key < surf2.key) {
        goto label 23
    }
    if (uint(surf_1.insubmodel) != 0x0 && surf_1.key == surf2.key) {
        goto label 15
    }
    label 5:
    label 6:
    label 7:
    surf2 = unsafe(reinterpret<surf_s?>(surf2.next))
    if (surf_1.key > surf2.key) {
        goto label 7
    }
    if (surf_1.key == surf2.key) {
        goto label 9
    }
    label 8:
    surf_1.next = surf2
    surf_1.prev = surf2.prev
    surf2.prev.next = surf_1
    surf2.prev = surf_1
    goto label 2
    label 9:
    if (uint(surf_1.insubmodel) == 0u) {
        goto label 14
    }
    fu = double(float(edge_0.u - 1048575)) * (1.0lf / 1048576.0lf)
    newzi = double(surf_1.d_ziorigin + fv * surf_1.d_zistepv) + fu * double(surf_1.d_zistepu)
    newzibottom = newzi * 0.99lf
    testzi = double(surf2.d_ziorigin + fv * surf2.d_zistepv) + fu * double(surf2.d_zistepu)
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
    if (surf_1.d_zistepu >= surf2.d_zistepu) {
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
    fu = double(float(edge_0.u - 1048575)) * (1.0lf / 1048576.0lf)
    newzi = double(surf_1.d_ziorigin + fv * surf_1.d_zistepv) + fu * double(surf_1.d_zistepu)
    newzibottom = newzi * 0.99lf
    testzi = double(surf2.d_ziorigin + fv * surf2.d_zistepv) + fu * double(surf2.d_zistepu)
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
    if (surf_1.d_zistepu >= surf2.d_zistepu) {
        goto label 18
    }
    goto label 16
    label 18:
    label 19:
    iu_0 = edge_0.u >> 20
    if (iu_0 > surf2.last_u) {
        goto label 21
    }
    label 20:
    surf_1.last_u = iu_0
    goto label 8
    label 21:
    c2da_postinc_1 = span_p
    unsafe {  // nolint:STYLE025
        span_p += 1
    }
    span_0 = unsafe(reinterpret<espan_s?>(c2da_postinc_1))
    span_0.u = int(surf2.last_u)  // nolint:PERF020
    span_0.count = iu_0 - span_0.u
    span_0.v = int(current_iv)  // nolint:PERF020
    span_0.pnext = surf2.spans
    surf2.spans = span_0
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
def R_TrailingEdge(var surf_2 : surf_s?; var edge_1 : edge_s?) {
    var span_1 : espan_s?
    var iu_1 : int
    let c2da_postinc_2 : int = surf_2.spanstate
    surf_2.spanstate = c2da_postinc_2 - 1
    if (c2da_postinc_2 - 1 == 0) {
        if (uint(surf_2.insubmodel) != 0u) {
            r_bmodelactive = r_bmodelactive - 1
        }
        if (surf_2 == unsafe(surfaces[1]).next) {
            iu_1 = edge_1.u >> 20
            if (iu_1 > surf_2.last_u) {
                var c2da_postinc_3 : espan_s? = span_p
                unsafe {  // nolint:STYLE025
                    span_p += 1
                }
                span_1 = unsafe(reinterpret<espan_s?>(c2da_postinc_3))
                span_1.u = int(surf_2.last_u)  // nolint:PERF020
                span_1.count = iu_1 - span_1.u
                span_1.v = int(current_iv)  // nolint:PERF020
                span_1.pnext = surf_2.spans
                surf_2.spans = span_1
            }
            surf_2.next.last_u = iu_1
        }
        surf_2.prev.next = surf_2.next
        surf_2.next.prev = surf_2.prev
    }
    return
}
var edge_tail : edge_s = default<edge_s>

var edge_head : edge_s = default<edge_s>

var edge_head_u_shift20 : int = default<int>

var private pdrawfunc : function<():void> = default<function<():void>>

[export, sideeffects]
def R_GenerateSpansBackward() {
    var edge_2 : edge_s?
    r_bmodelactive = 0
    unsafe(surfaces[1]).prev = unsafe(addr<surf_s?>(unsafe(surfaces[1])))
    unsafe(surfaces[1]).next = unsafe(reinterpret<surf_s?>(unsafe(surfaces[1]).prev))
    unsafe(surfaces[1]).last_u = int(edge_head_u_shift20)  // nolint:PERF020
    edge_2 = unsafe(reinterpret<edge_s?>(edge_head.next))
    while (edge_2 != unsafe(addr(edge_tail))) {
        var c2da_fresh5 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(edge_2)) + 24ul))
        if (unsafe(unsafe(reinterpret<uint16?>(c2da_fresh5))[0]) != 0x0) {
            var c2da_fresh6 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(edge_2)) + 24ul))
            R_TrailingEdge(unsafe(addr<surf_s?>(unsafe(surfaces[int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh6))[0]))]))), edge_2)
        }
        var c2da_fresh7 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(edge_2)) + 24ul))
        if (unsafe(unsafe(reinterpret<uint16?>(c2da_fresh7))[1]) != 0x0) {
            R_LeadingEdgeBackwards(edge_2)
        }
        edge_2 = unsafe(reinterpret<edge_s?>(edge_2.next))
    }
    R_CleanupSpan()
    return
}
[export, sideeffects]
def R_LeadingEdgeBackwards(var edge_3 : edge_s?) {
    var span_2 : espan_s?
    var surf_3 : surf_s?
    var surf2_0 : surf_s?
    var iu_2 : int
    var c2da_fresh8 : uint16?
    var c2da_postinc_4 : int
    var c2da_postinc_5 : espan_s?
    c2da_fresh8 = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(edge_3)) + 24ul))
    surf_3 = unsafe(addr<surf_s?>(unsafe(surfaces[int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh8))[1]))])))
    c2da_postinc_4 = surf_3.spanstate
    surf_3.spanstate = c2da_postinc_4 + 1
    if (c2da_postinc_4 + 1 == 1) {
        goto label 1
    }
    label 0:
    return
    label 1:
    surf2_0 = unsafe(reinterpret<surf_s?>(unsafe(surfaces[1]).next))
    if (surf_3.key > surf2_0.key) {
        goto label 12
    }
    if (uint(surf_3.insubmodel) != 0x0 && surf_3.key == surf2_0.key) {
        goto label 8
    }
    label 2:
    label 3:
    surf2_0 = unsafe(reinterpret<surf_s?>(surf2_0.next))
    if (surf_3.key < surf2_0.key) {
        goto label 3
    }
    if (surf_3.key == surf2_0.key) {
        goto label 6
    }
    label 4:
    label 5:
    surf_3.next = surf2_0
    surf_3.prev = surf2_0.prev
    surf2_0.prev.next = surf_3
    surf2_0.prev = surf_3
    goto label 0
    label 6:
    if (uint(surf_3.insubmodel) == 0u) {
        goto label 7
    }
    goto label 4
    label 7:
    goto label 2
    label 8:
    label 9:
    iu_2 = edge_3.u >> 20
    if (iu_2 > surf2_0.last_u) {
        goto label 11
    }
    label 10:
    surf_3.last_u = iu_2
    goto label 5
    label 11:
    c2da_postinc_5 = span_p
    unsafe {  // nolint:STYLE025
        span_p += 1
    }
    span_2 = unsafe(reinterpret<espan_s?>(c2da_postinc_5))
    span_2.u = int(surf2_0.last_u)  // nolint:PERF020
    span_2.count = iu_2 - span_2.u
    span_2.v = int(current_iv)  // nolint:PERF020
    span_2.pnext = surf2_0.spans
    surf2_0.spans = span_2
    goto label 10
    label 12:
    goto label 9
    panic("unreachable: fell out of a translated control-flow graph")
}
var r_edges : edge_s? = default<edge_s?>

var edge_max : edge_s? = default<edge_s?>

var edge_p : edge_s? = default<edge_s?>

[export, sideeffects]
def R_ScanEdges() {
    var iv : int
    var bottom : int
    var basespans : uint8[72032]
    var basespan_p : espan_s?
    var s : surf_s?
    var c2da_fresh9 : uint8? = unsafe(unsafe(unsafe(addr(basespans[0])) + 32) + -1)
    basespan_p = unsafe(reinterpret<espan_s?>(unsafe(reinterpret<espan_s?>(uint64(int64(unsafe(reinterpret<uint64>(c2da_fresh9))) & int64(~(32 - 1)))))))
    max_span_p = unsafe(addr<espan_s?>(unsafe(basespan_p[3000 - r_refdef.vrect.width])))
    span_p = unsafe(reinterpret<espan_s?>(basespan_p))
    edge_head.u = r_refdef.vrect.x << 20
    edge_head_u_shift20 = edge_head.u >> 20
    edge_head.u_step = 0
    edge_head.prev = null
    edge_head.next = unsafe(addr<edge_s?>(edge_tail))
    unsafe(unsafe(addr(edge_head.surfs[0]))[0]) = uint16(0)
    unsafe(unsafe(addr(edge_head.surfs[0]))[1]) = uint16(1)
    edge_tail.u = (r_refdef.vrectright << 20) + 1048575
    edge_tail_u_shift20 = edge_tail.u >> 20
    edge_tail.u_step = 0
    edge_tail.prev = unsafe(addr<edge_s?>(edge_head))
    edge_tail.next = unsafe(addr<edge_s?>(edge_aftertail))
    unsafe(unsafe(addr(edge_tail.surfs[0]))[0]) = uint16(1)
    unsafe(unsafe(addr(edge_tail.surfs[0]))[1]) = uint16(0)
    edge_aftertail.u = -1
    edge_aftertail.u_step = 0
    edge_aftertail.next = unsafe(addr<edge_s?>(edge_sentinel))
    edge_aftertail.prev = unsafe(addr<edge_s?>(edge_tail))
    edge_sentinel.u = 2000 << 24
    edge_sentinel.prev = unsafe(addr<edge_s?>(edge_aftertail))
    bottom = r_refdef.vrectbottom - 1
    iv = r_refdef.vrect.y
    while (iv < bottom) {
        current_iv = iv
        fv = float(iv)
        unsafe(surfaces[1]).spanstate = 1
        if (newedges[iv] != null) {
            R_InsertNewEdges(unsafe(reinterpret<edge_s?>(newedges[iv])), edge_head.next)
        }
        invoke(pdrawfunc)
        if (unsafe(reinterpret<uint64>(span_p)) >= unsafe(reinterpret<uint64>(max_span_p))) {
            S_ExtraUpdate()
            if (uint(r_drawculledpolys) != 0u) {
                R_DrawCulledPolys()
            } else {
                D_DrawSurfaces()
            }
            s = unsafe(addr<surf_s?>(unsafe(surfaces[1])))
            while (unsafe(reinterpret<uint64>(s)) < unsafe(reinterpret<uint64>(surface_p))) {
                s.spans = null
                unsafe {  // nolint:STYLE025
                    s += 1
                }
            }
            span_p = unsafe(reinterpret<espan_s?>(basespan_p))
        }
        if (removeedges[iv] != null) {
            R_RemoveEdges(unsafe(reinterpret<edge_s?>(removeedges[iv])))
        }
        if (edge_head.next != unsafe(addr(edge_tail))) {
            R_StepActiveU(edge_head.next)
        }
        iv++
    }
    current_iv = iv
    fv = float(iv)
    unsafe(surfaces[1]).spanstate = 1
    if (newedges[iv] != null) {
        R_InsertNewEdges(unsafe(reinterpret<edge_s?>(newedges[iv])), edge_head.next)
    }
    invoke(pdrawfunc)
    if (uint(r_drawculledpolys) != 0u) {
        R_DrawCulledPolys()
    } else {
        D_DrawSurfaces()
    }
    return
}
[export, sideeffects]
def R_DrawCulledPolys() {
    var s_0 : surf_s?
    var pface : msurface_s?
    currententity = unsafe(addr<entity_s?>(unsafe(unsafe(addr(cl_entities[0]))[0])))
    if (uint(r_worldpolysbacktofront) != 0u) {
        s_0 = unsafe(reinterpret<surf_s?>(unsafe(surface_p + -1)))
        while (unsafe(reinterpret<uint64>(s_0)) > unsafe(reinterpret<uint64>(unsafe(addr(unsafe(surfaces[1])))))) {
            if (s_0.spans == null) {
                unsafe {  // nolint:STYLE025
                    s_0 -= 1
                }
                continue
            }
            if ((s_0.flags & 64) == 0) {
                pface = unsafe(reinterpret<msurface_s?>(unsafe(reinterpret<msurface_s?>(s_0.data))))
                R_RenderPoly(pface, 15)
            }
            unsafe {  // nolint:STYLE025
                s_0 -= 1
            }
        }
    } else {
        s_0 = unsafe(addr<surf_s?>(unsafe(surfaces[1])))
        while (unsafe(reinterpret<uint64>(s_0)) < unsafe(reinterpret<uint64>(surface_p))) {
            if (s_0.spans == null) {
                unsafe {  // nolint:STYLE025
                    s_0 += 1
                }
                continue
            }
            if ((s_0.flags & 64) == 0) {
                pface = unsafe(reinterpret<msurface_s?>(unsafe(reinterpret<msurface_s?>(s_0.data))))
                R_RenderPoly(pface, 15)
            }
            unsafe {  // nolint:STYLE025
                s_0 += 1
            }
        }
    }
    return
}
[export, sideeffects]
def R_InsertNewEdges(var edgestoadd : edge_s?; var edgelist : edge_s?) {
    var next_edge : edge_s?
    label 0:
    next_edge = unsafe(reinterpret<edge_s?>(edgestoadd.next))
    label 1:
    if (edgelist.u >= edgestoadd.u) {
        goto label 6
    }
    edgelist = unsafe(reinterpret<edge_s?>(edgelist.next))
    if (edgelist.u >= edgestoadd.u) {
        goto label 5
    }
    edgelist = unsafe(reinterpret<edge_s?>(edgelist.next))
    if (edgelist.u >= edgestoadd.u) {
        goto label 4
    }
    edgelist = unsafe(reinterpret<edge_s?>(edgelist.next))
    if (edgelist.u >= edgestoadd.u) {
        goto label 2
    }
    edgelist = unsafe(reinterpret<edge_s?>(edgelist.next))
    goto label 1
    label 2:
    label 3:
    edgestoadd.next = edgelist
    edgestoadd.prev = edgelist.prev
    edgelist.prev.next = edgestoadd
    edgelist.prev = edgestoadd
    edgestoadd = unsafe(reinterpret<edge_s?>(next_edge))
    if (edgestoadd != null) {
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
def R_StepActiveU(var pedge : edge_s?) {
    var pnext_edge : edge_s?
    var pwedge : edge_s?
    label 0:
    goto label 1
    return
    label 1:
    label 2:
    pedge.u += pedge.u_step
    if (pedge.u < pedge.prev.u) {
        goto label 11
    }
    pedge = unsafe(reinterpret<edge_s?>(pedge.next))
    pedge.u += pedge.u_step
    if (pedge.u < pedge.prev.u) {
        goto label 10
    }
    pedge = unsafe(reinterpret<edge_s?>(pedge.next))
    pedge.u += pedge.u_step
    if (pedge.u < pedge.prev.u) {
        goto label 9
    }
    pedge = unsafe(reinterpret<edge_s?>(pedge.next))
    pedge.u += pedge.u_step
    if (pedge.u < pedge.prev.u) {
        goto label 3
    }
    pedge = unsafe(reinterpret<edge_s?>(pedge.next))
    goto label 2
    label 3:
    label 4:
    if (pedge == unsafe(addr(edge_aftertail))) {
        goto label 8
    }
    pnext_edge = unsafe(reinterpret<edge_s?>(pedge.next))
    pedge.next.prev = pedge.prev
    pedge.prev.next = pedge.next
    pwedge = unsafe(reinterpret<edge_s?>(pedge.prev.prev))
    label 5:
    if (pwedge.u > pedge.u) {
        goto label 7
    }
    pedge.next = pwedge.next
    pedge.prev = pwedge
    pedge.next.prev = pedge
    pwedge.next = pedge
    pedge = unsafe(reinterpret<edge_s?>(pnext_edge))
    if (pedge == unsafe(addr(edge_tail))) {
        goto label 6
    }
    goto label 0
    label 6:
    return
    label 7:
    pwedge = unsafe(reinterpret<edge_s?>(pwedge.prev))
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
var edge_aftertail : edge_s = default<edge_s>

[export, sideeffects]
def R_RemoveEdges(var pedge_0 : edge_s?) {
    while (true) {
        pedge_0.next.prev = pedge_0.prev
        pedge_0.prev.next = pedge_0.next
        pedge_0 = unsafe(reinterpret<edge_s?>(pedge_0.nextremove))
        if (pedge_0 == null) {
            break
        }
    }
    return
}
var max_span_p : espan_s? = default<espan_s?>

var edge_sentinel : edge_s = default<edge_s>

var auxedges : edge_s? = default<edge_s?>

[sideeffects]
def private c2da_layout_proofs_36() {
    static_assert(typeinfo sizeof(type<cache_user_s>) == 8, "C layout of cache_user_s: sizeof")
    static_assert(typeinfo alignof(type<cache_user_s>) == 8, "C layout of cache_user_s: alignof")
    static_assert(typeinfo offsetof<data>(type<cache_user_s>) == 0, "C layout of cache_user_s: offsetof data")
    static_assert(typeinfo sizeof(type<cvar_s>) == 40, "C layout of cvar_s: sizeof")
    static_assert(typeinfo alignof(type<cvar_s>) == 8, "C layout of cvar_s: alignof")
    static_assert(typeinfo offsetof<name>(type<cvar_s>) == 0, "C layout of cvar_s: offsetof name")
    static_assert(typeinfo offsetof<string_0>(type<cvar_s>) == 8, "C layout of cvar_s: offsetof string_0")
    static_assert(typeinfo offsetof<archive>(type<cvar_s>) == 16, "C layout of cvar_s: offsetof archive")
    static_assert(typeinfo offsetof<server>(type<cvar_s>) == 20, "C layout of cvar_s: offsetof server")
    static_assert(typeinfo offsetof<value>(type<cvar_s>) == 24, "C layout of cvar_s: offsetof value")
    static_assert(typeinfo offsetof<next>(type<cvar_s>) == 32, "C layout of cvar_s: offsetof next")
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
    static_assert(typeinfo sizeof(type<cvar_t>) == 40, "C layout of cvar_t: sizeof")
    static_assert(typeinfo alignof(type<cvar_t>) == 8, "C layout of cvar_t: alignof")
    static_assert(typeinfo offsetof<name>(type<cvar_t>) == 0, "C layout of cvar_t: offsetof name")
    static_assert(typeinfo offsetof<string_0>(type<cvar_t>) == 8, "C layout of cvar_t: offsetof string_0")
    static_assert(typeinfo offsetof<archive>(type<cvar_t>) == 16, "C layout of cvar_t: offsetof archive")
    static_assert(typeinfo offsetof<server>(type<cvar_t>) == 20, "C layout of cvar_t: offsetof server")
    static_assert(typeinfo offsetof<value>(type<cvar_t>) == 24, "C layout of cvar_t: offsetof value")
    static_assert(typeinfo offsetof<next>(type<cvar_t>) == 32, "C layout of cvar_t: offsetof next")
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
    static_assert(typeinfo sizeof(type<espan_s>) == 24, "C layout of espan_s: sizeof")
    static_assert(typeinfo alignof(type<espan_s>) == 8, "C layout of espan_s: alignof")
    static_assert(typeinfo offsetof<u>(type<espan_s>) == 0, "C layout of espan_s: offsetof u")
    static_assert(typeinfo offsetof<v>(type<espan_s>) == 4, "C layout of espan_s: offsetof v")
    static_assert(typeinfo offsetof<count>(type<espan_s>) == 8, "C layout of espan_s: offsetof count")
    static_assert(typeinfo offsetof<pnext>(type<espan_s>) == 16, "C layout of espan_s: offsetof pnext")
    static_assert(typeinfo sizeof(type<espan_t>) == 24, "C layout of espan_t: sizeof")
    static_assert(typeinfo alignof(type<espan_t>) == 8, "C layout of espan_t: alignof")
    static_assert(typeinfo offsetof<u>(type<espan_t>) == 0, "C layout of espan_t: offsetof u")
    static_assert(typeinfo offsetof<v>(type<espan_t>) == 4, "C layout of espan_t: offsetof v")
    static_assert(typeinfo offsetof<count>(type<espan_t>) == 8, "C layout of espan_t: offsetof count")
    static_assert(typeinfo offsetof<pnext>(type<espan_t>) == 16, "C layout of espan_t: offsetof pnext")
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
}
