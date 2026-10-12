[export, sideeffects]
def R_PushDlights() {
    var i : int
    var l : dlight_t?
    r_dlightframecount = r_framecount + 1
    l = unsafe(addr<dlight_t?>(cl_dlights[0]))
    i = 0
    while (i < 32) {
        if (double(l.die) < cl.time || l.radius == 0.0) {
            i++
            unsafe {  // nolint:STYLE025
                l += 1
            }
            continue
        }
        R_MarkLights(l, 1 << i, cl.worldmodel.nodes)
        i++
        unsafe {  // nolint:STYLE025
            l += 1
        }
    }
    return
}
[export, sideeffects]
def R_MarkLights(var light : dlight_t?; var bit : int; var node : mnode_s?) {
    var splitplane : mplane_s?
    var dist : float
    var surf : msurface_s?
    var i_0 : int
    if (node.contents < 0) {
        return
    }
    splitplane = unsafe(reinterpret<mplane_s?>(node.plane))
    var c2da_fresh0 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(light))))
    var c2da_fresh1 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    var c2da_fresh2 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(light))))
    var c2da_fresh3 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    var c2da_fresh4 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(light))))
    var c2da_fresh5 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    dist = unsafe(unsafe(reinterpret<float?>(c2da_fresh0))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh1))[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh2))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh3))[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh4))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh5))[2]) - splitplane.dist
    if (dist > light.radius) {
        var c2da_fresh6 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node)) + 40ul))
        R_MarkLights(light, bit, unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh6))[0]))))
        return
    }
    if (dist < -light.radius) {
        var c2da_fresh7 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node)) + 40ul))
        R_MarkLights(light, bit, unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh7))[1]))))
        return
    }
    surf = unsafe(reinterpret<msurface_s?>(unsafe(cl.worldmodel.surfaces + int(node.firstsurface))))
    var c2da_surf_addr : uint64 = unsafe(reinterpret<uint64>(surf))
    i_0 = 0
    while (i_0 < int(node.numsurfaces)) {
        if (unsafe(reinterpret<msurface_s?>(c2da_surf_addr)).dlightframe != r_dlightframecount) {
            unsafe(reinterpret<msurface_s?>(c2da_surf_addr)).dlightbits = 0
            unsafe(reinterpret<msurface_s?>(c2da_surf_addr)).dlightframe = int(r_dlightframecount)  // nolint:PERF020
        }
        unsafe(reinterpret<msurface_s?>(c2da_surf_addr)).dlightbits |= bit
        i_0++
        c2da_surf_addr += 104ul
    }
    var c2da_fresh8 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node)) + 40ul))
    R_MarkLights(light, bit, unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh8))[0]))))
    var c2da_fresh9 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node)) + 40ul))
    R_MarkLights(light, bit, unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh9))[1]))))
    return
}
var r_dlightframecount : int = default<int>

[export, sideeffects]
def R_AnimateLight() {
    var i_1 : int
    var k : int
    i_1 = int(cl.time * 10.0lf)
    for (j in range(0, 64)) {
        if (cl_lightstyle[j].length == 0) {
            d_lightstylevalue[j] = 256
            continue
        }
        k = i_1 % cl_lightstyle[j].length
        k = int(unsafe(unsafe(addr(cl_lightstyle[j].map[0]))[k])) - 97
        k *= 22
        d_lightstylevalue[j] = k
    }
    return
}
[export, sideeffects]
def R_LightPoint(var p : float?) : int {
    var end : vec3_t
    var r : int
    if (cl.worldmodel.lightdata == null) {
        return 255
    }
    unsafe(unsafe(addr(end[0]))[0]) = float(unsafe(p[0]))  // nolint:PERF020
    unsafe(unsafe(addr(end[0]))[1]) = float(unsafe(p[1]))  // nolint:PERF020
    unsafe(unsafe(addr(end[0]))[2]) = unsafe(p[2]) - 2048.0
    r = RecursiveLightPoint(cl.worldmodel.nodes, p, unsafe(addr<float?>(end[0])))
    if (r == -1) {
        r = 0
    }
    if (r < r_refdef.ambientlight) {
        r = r_refdef.ambientlight
    }
    return r
}
[export, sideeffects]
def RecursiveLightPoint(var node_0 : mnode_s?; var start : float?; var end_0 : float?) : int {
    var r_0 : int
    var front : float
    var back : float
    var frac : float
    var side : int
    var plane : mplane_s?
    var mid : vec3_t
    var surf_0 : msurface_s?
    var s : int
    var t : int
    var ds : int
    var dt : int
    var i_2 : int
    var tex : mtexinfo_t?
    var lightmap : uint8?
    var scale : uint
    var maps : int
    if (node_0.contents < 0) {
        return -1
    }
    plane = unsafe(reinterpret<mplane_s?>(node_0.plane))
    var c2da_fresh10 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane))))
    var c2da_fresh11 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane))))
    var c2da_fresh12 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane))))
    front = unsafe(start[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh10))[0]) + unsafe(start[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh11))[1]) + unsafe(start[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh12))[2]) - plane.dist
    var c2da_fresh13 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane))))
    var c2da_fresh14 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane))))
    var c2da_fresh15 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane))))
    back = unsafe(end_0[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh13))[0]) + unsafe(end_0[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh14))[1]) + unsafe(end_0[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh15))[2]) - plane.dist
    side = front < 0.0 ? 1 : 0
    if ((back < 0.0 ? 1 : 0) == side) {
        var c2da_fresh16 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node_0)) + 40ul))
        return RecursiveLightPoint(unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh16))[side]))), start, end_0)
    }
    frac = front / (front - back)
    unsafe(unsafe(addr(mid[0]))[0]) = unsafe(start[0]) + (unsafe(end_0[0]) - unsafe(start[0])) * frac
    unsafe(unsafe(addr(mid[0]))[1]) = unsafe(start[1]) + (unsafe(end_0[1]) - unsafe(start[1])) * frac
    unsafe(unsafe(addr(mid[0]))[2]) = unsafe(start[2]) + (unsafe(end_0[2]) - unsafe(start[2])) * frac
    var c2da_fresh17 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node_0)) + 40ul))
    r_0 = RecursiveLightPoint(unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh17))[side]))), start, unsafe(addr<float?>(mid[0])))
    if (r_0 >= 0) {
        return r_0
    }
    if ((back < 0.0 ? 1 : 0) == side) {
        return -1
    }
    surf_0 = unsafe(reinterpret<msurface_s?>(unsafe(cl.worldmodel.surfaces + int(node_0.firstsurface))))
    var c2da_surf_0_addr : uint64 = unsafe(reinterpret<uint64>(surf_0))
    i_2 = 0
    while (i_2 < int(node_0.numsurfaces)) {
        if ((unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)).flags & 32) != 0) {
            i_2++
            c2da_surf_0_addr += 104ul
            continue
        }
        tex = unsafe(reinterpret<mtexinfo_t?>(unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)).texinfo))
        var c2da_fresh18 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        var c2da_fresh19 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        var c2da_fresh20 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        var c2da_fresh21 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        s = int(unsafe(unsafe(addr(mid[0]))[0]) * unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh18))[0])[0]))[0]) + unsafe(unsafe(addr(mid[0]))[1]) * unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh19))[0])[0]))[1]) + unsafe(unsafe(addr(mid[0]))[2]) * unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh20))[0])[0]))[2]) + unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh21))[0])[0]))[3]))
        var c2da_fresh22 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        var c2da_fresh23 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        var c2da_fresh24 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        var c2da_fresh25 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        t = int(unsafe(unsafe(addr(mid[0]))[0]) * unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh22))[1])[0]))[0]) + unsafe(unsafe(addr(mid[0]))[1]) * unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh23))[1])[0]))[1]) + unsafe(unsafe(addr(mid[0]))[2]) * unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh24))[1])[0]))[2]) + unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh25))[1])[0]))[3]))
        var c2da_fresh26 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)))) + 72ul))
        var c2da_fresh28 : int = 1
        if (!(s < int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh26))[0])))) {
            var c2da_fresh27 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)))) + 72ul))
            if (!(t < int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh27))[1])))) {
                c2da_fresh28 = 0
            }
        }
        if (c2da_fresh28 != 0) {
            i_2++
            c2da_surf_0_addr += 104ul
            continue
        }
        var c2da_fresh29 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)))) + 72ul))
        ds = s - int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh29))[0]))
        var c2da_fresh30 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)))) + 72ul))
        dt = t - int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh30))[1]))
        var c2da_fresh31 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)))) + 76ul))
        var c2da_fresh33 : int = 1
        if (!(ds > int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh31))[0])))) {
            var c2da_fresh32 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)))) + 76ul))
            if (!(dt > int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh32))[1])))) {
                c2da_fresh33 = 0
            }
        }
        if (c2da_fresh33 != 0) {
            i_2++
            c2da_surf_0_addr += 104ul
            continue
        }
        if (unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)).samples == null) {
            return 0
        }
        ds >>= 4
        dt >>= 4
        lightmap = unsafe(reinterpret<uint8?>(unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)).samples))
        r_0 = 0
        if (lightmap != null) {
            var c2da_fresh34 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)))) + 76ul))
            unsafe {
                lightmap += int64(dt * ((int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh34))[0])) >> 4) + 1) + ds)
            }
            maps = 0
            while (true) {
                var c2da_fresh36 : int = 0
                if (maps < 4) {
                    var c2da_fresh35 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)))) + 88ul))
                    if (int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh35))[maps])) != 255) {
                        c2da_fresh36 = 1
                    }
                }
                if (c2da_fresh36 == 0) {
                    break
                }
                var c2da_fresh37 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)))) + 88ul))
                scale = uint(d_lightstylevalue[int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh37))[maps]))])
                var c2da_fresh38 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)))) + 88ul))
                scale = uint(d_lightstylevalue[int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh38))[maps]))])
                r_0 = int(uint(r_0) + uint(*lightmap) * scale)
                var c2da_fresh39 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)))) + 76ul))
                var c2da_fresh40 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<msurface_s?>(c2da_surf_0_addr)))) + 76ul))
                unsafe {
                    lightmap += ((int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh39))[0])) >> 4) + 1) * ((int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh40))[1])) >> 4) + 1)
                }
                maps++
            }
            r_0 >>= 8
        }
        return r_0
    }
    var c2da_fresh41 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node_0)) + 40ul))
    return RecursiveLightPoint(unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh41))[side == 0 ? 1 : 0]))), unsafe(addr<float?>(mid[0])), end_0)
}
[sideeffects]
def private c2da_layout_proofs_38() {
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
    static_assert(typeinfo sizeof(type<sfx_s>) == 72, "C layout of sfx_s: sizeof")
    static_assert(typeinfo alignof(type<sfx_s>) == 8, "C layout of sfx_s: alignof")
    static_assert(typeinfo offsetof<name>(type<sfx_s>) == 0, "C layout of sfx_s: offsetof name")
    static_assert(typeinfo offsetof<cache>(type<sfx_s>) == 64, "C layout of sfx_s: offsetof cache")
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
    static_assert(typeinfo sizeof(type<client_state_t>) == 4992, "C layout of client_state_t: sizeof")
    static_assert(typeinfo alignof(type<client_state_t>) == 8, "C layout of client_state_t: alignof")
    static_assert(typeinfo offsetof<movemessages>(type<client_state_t>) == 0, "C layout of client_state_t: offsetof movemessages")
    static_assert(typeinfo offsetof<cmd>(type<client_state_t>) == 4, "C layout of client_state_t: offsetof cmd")
    static_assert(typeinfo offsetof<stats>(type<client_state_t>) == 28, "C layout of client_state_t: offsetof stats")
    static_assert(typeinfo offsetof<items>(type<client_state_t>) == 156, "C layout of client_state_t: offsetof items")
    static_assert(typeinfo offsetof<item_gettime>(type<client_state_t>) == 160, "C layout of client_state_t: offsetof item_gettime")
    static_assert(typeinfo offsetof<faceanimtime>(type<client_state_t>) == 288, "C layout of client_state_t: offsetof faceanimtime")
    static_assert(typeinfo offsetof<cshifts>(type<client_state_t>) == 292, "C layout of client_state_t: offsetof cshifts")
    static_assert(typeinfo offsetof<prev_cshifts>(type<client_state_t>) == 356, "C layout of client_state_t: offsetof prev_cshifts")
    static_assert(typeinfo offsetof<mviewangles>(type<client_state_t>) == 420, "C layout of client_state_t: offsetof mviewangles")
    static_assert(typeinfo offsetof<viewangles>(type<client_state_t>) == 444, "C layout of client_state_t: offsetof viewangles")
    static_assert(typeinfo offsetof<mvelocity>(type<client_state_t>) == 456, "C layout of client_state_t: offsetof mvelocity")
    static_assert(typeinfo offsetof<velocity>(type<client_state_t>) == 480, "C layout of client_state_t: offsetof velocity")
    static_assert(typeinfo offsetof<punchangle>(type<client_state_t>) == 492, "C layout of client_state_t: offsetof punchangle")
    static_assert(typeinfo offsetof<idealpitch>(type<client_state_t>) == 504, "C layout of client_state_t: offsetof idealpitch")
    static_assert(typeinfo offsetof<pitchvel>(type<client_state_t>) == 508, "C layout of client_state_t: offsetof pitchvel")
    static_assert(typeinfo offsetof<nodrift>(type<client_state_t>) == 512, "C layout of client_state_t: offsetof nodrift")
    static_assert(typeinfo offsetof<driftmove>(type<client_state_t>) == 516, "C layout of client_state_t: offsetof driftmove")
    static_assert(typeinfo offsetof<laststop>(type<client_state_t>) == 520, "C layout of client_state_t: offsetof laststop")
    static_assert(typeinfo offsetof<viewheight>(type<client_state_t>) == 528, "C layout of client_state_t: offsetof viewheight")
    static_assert(typeinfo offsetof<crouch>(type<client_state_t>) == 532, "C layout of client_state_t: offsetof crouch")
    static_assert(typeinfo offsetof<paused>(type<client_state_t>) == 536, "C layout of client_state_t: offsetof paused")
    static_assert(typeinfo offsetof<onground>(type<client_state_t>) == 540, "C layout of client_state_t: offsetof onground")
    static_assert(typeinfo offsetof<inwater>(type<client_state_t>) == 544, "C layout of client_state_t: offsetof inwater")
    static_assert(typeinfo offsetof<intermission>(type<client_state_t>) == 548, "C layout of client_state_t: offsetof intermission")
    static_assert(typeinfo offsetof<completed_time>(type<client_state_t>) == 552, "C layout of client_state_t: offsetof completed_time")
    static_assert(typeinfo offsetof<mtime>(type<client_state_t>) == 560, "C layout of client_state_t: offsetof mtime")
    static_assert(typeinfo offsetof<time>(type<client_state_t>) == 576, "C layout of client_state_t: offsetof time")
    static_assert(typeinfo offsetof<oldtime>(type<client_state_t>) == 584, "C layout of client_state_t: offsetof oldtime")
    static_assert(typeinfo offsetof<last_received_message>(type<client_state_t>) == 592, "C layout of client_state_t: offsetof last_received_message")
    static_assert(typeinfo offsetof<model_precache>(type<client_state_t>) == 600, "C layout of client_state_t: offsetof model_precache")
    static_assert(typeinfo offsetof<sound_precache>(type<client_state_t>) == 2648, "C layout of client_state_t: offsetof sound_precache")
    static_assert(typeinfo offsetof<levelname>(type<client_state_t>) == 4696, "C layout of client_state_t: offsetof levelname")
    static_assert(typeinfo offsetof<viewentity>(type<client_state_t>) == 4736, "C layout of client_state_t: offsetof viewentity")
    static_assert(typeinfo offsetof<maxclients>(type<client_state_t>) == 4740, "C layout of client_state_t: offsetof maxclients")
    static_assert(typeinfo offsetof<gametype>(type<client_state_t>) == 4744, "C layout of client_state_t: offsetof gametype")
    static_assert(typeinfo offsetof<worldmodel>(type<client_state_t>) == 4752, "C layout of client_state_t: offsetof worldmodel")
    static_assert(typeinfo offsetof<free_efrags>(type<client_state_t>) == 4760, "C layout of client_state_t: offsetof free_efrags")
    static_assert(typeinfo offsetof<num_entities>(type<client_state_t>) == 4768, "C layout of client_state_t: offsetof num_entities")
    static_assert(typeinfo offsetof<num_statics>(type<client_state_t>) == 4772, "C layout of client_state_t: offsetof num_statics")
    static_assert(typeinfo offsetof<viewent>(type<client_state_t>) == 4776, "C layout of client_state_t: offsetof viewent")
    static_assert(typeinfo offsetof<cdtrack>(type<client_state_t>) == 4976, "C layout of client_state_t: offsetof cdtrack")
    static_assert(typeinfo offsetof<looptrack>(type<client_state_t>) == 4980, "C layout of client_state_t: offsetof looptrack")
    static_assert(typeinfo offsetof<scores>(type<client_state_t>) == 4984, "C layout of client_state_t: offsetof scores")
    static_assert(typeinfo sizeof(type<scoreboard_t>) == 16428, "C layout of scoreboard_t: sizeof")
    static_assert(typeinfo alignof(type<scoreboard_t>) == 4, "C layout of scoreboard_t: alignof")
    static_assert(typeinfo offsetof<name>(type<scoreboard_t>) == 0, "C layout of scoreboard_t: offsetof name")
    static_assert(typeinfo offsetof<entertime>(type<scoreboard_t>) == 32, "C layout of scoreboard_t: offsetof entertime")
    static_assert(typeinfo offsetof<frags>(type<scoreboard_t>) == 36, "C layout of scoreboard_t: offsetof frags")
    static_assert(typeinfo offsetof<colors>(type<scoreboard_t>) == 40, "C layout of scoreboard_t: offsetof colors")
    static_assert(typeinfo offsetof<translations>(type<scoreboard_t>) == 44, "C layout of scoreboard_t: offsetof translations")
    static_assert(typeinfo sizeof(type<cshift_t>) == 16, "C layout of cshift_t: sizeof")
    static_assert(typeinfo alignof(type<cshift_t>) == 4, "C layout of cshift_t: alignof")
    static_assert(typeinfo offsetof<destcolor>(type<cshift_t>) == 0, "C layout of cshift_t: offsetof destcolor")
    static_assert(typeinfo offsetof<percent>(type<cshift_t>) == 12, "C layout of cshift_t: offsetof percent")
    static_assert(typeinfo sizeof(type<usercmd_t>) == 24, "C layout of usercmd_t: sizeof")
    static_assert(typeinfo alignof(type<usercmd_t>) == 4, "C layout of usercmd_t: alignof")
    static_assert(typeinfo offsetof<viewangles>(type<usercmd_t>) == 0, "C layout of usercmd_t: offsetof viewangles")
    static_assert(typeinfo offsetof<forwardmove>(type<usercmd_t>) == 12, "C layout of usercmd_t: offsetof forwardmove")
    static_assert(typeinfo offsetof<sidemove>(type<usercmd_t>) == 16, "C layout of usercmd_t: offsetof sidemove")
    static_assert(typeinfo offsetof<upmove>(type<usercmd_t>) == 20, "C layout of usercmd_t: offsetof upmove")
    static_assert(typeinfo sizeof(type<dlight_t>) == 32, "C layout of dlight_t: sizeof")
    static_assert(typeinfo alignof(type<dlight_t>) == 4, "C layout of dlight_t: alignof")
    static_assert(typeinfo offsetof<origin>(type<dlight_t>) == 0, "C layout of dlight_t: offsetof origin")
    static_assert(typeinfo offsetof<radius>(type<dlight_t>) == 12, "C layout of dlight_t: offsetof radius")
    static_assert(typeinfo offsetof<die>(type<dlight_t>) == 16, "C layout of dlight_t: offsetof die")
    static_assert(typeinfo offsetof<decay>(type<dlight_t>) == 20, "C layout of dlight_t: offsetof decay")
    static_assert(typeinfo offsetof<minlight>(type<dlight_t>) == 24, "C layout of dlight_t: offsetof minlight")
    static_assert(typeinfo offsetof<key>(type<dlight_t>) == 28, "C layout of dlight_t: offsetof key")
    static_assert(typeinfo sizeof(type<lightstyle_t>) == 68, "C layout of lightstyle_t: sizeof")
    static_assert(typeinfo alignof(type<lightstyle_t>) == 4, "C layout of lightstyle_t: alignof")
    static_assert(typeinfo offsetof<length>(type<lightstyle_t>) == 0, "C layout of lightstyle_t: offsetof length")
    static_assert(typeinfo offsetof<map>(type<lightstyle_t>) == 4, "C layout of lightstyle_t: offsetof map")
}
