[export, sideeffects]
def D_DrawPoly() {
    return
}
[export, sideeffects]
def D_DrawSurfaces() {
    var s : surf_s?
    var pface : msurface_s?
    var pcurrentcache : surfcache_s?
    var world_transformed_modelorg : vec3_t
    var local_modelorg : vec3_t
    currententity = unsafe(addr<entity_s?>(unsafe(unsafe(addr(cl_entities[0]))[0])))
    TransformVector(unsafe(addr<float?>(modelorg[0])), unsafe(addr<float?>(transformed_modelorg[0])))
    unsafe(unsafe(addr(world_transformed_modelorg[0]))[0]) = float(unsafe(unsafe(addr(transformed_modelorg[0]))[0]))  // nolint:PERF020
    unsafe(unsafe(addr(world_transformed_modelorg[0]))[1]) = float(unsafe(unsafe(addr(transformed_modelorg[0]))[1]))  // nolint:PERF020
    unsafe(unsafe(addr(world_transformed_modelorg[0]))[2]) = float(unsafe(unsafe(addr(transformed_modelorg[0]))[2]))  // nolint:PERF020
    if (r_drawflat.value != 0.0) {
        s = unsafe(addr<surf_s?>(unsafe(surfaces[1])))
        while (unsafe(reinterpret<uint64>(s)) < unsafe(reinterpret<uint64>(surface_p))) {
            if (s.spans == null) {
                unsafe {  // nolint:STYLE025
                    s += 1
                }
                continue
            }
            d_zistepu = s.d_zistepu
            d_zistepv = s.d_zistepv
            d_ziorigin = s.d_ziorigin
            D_DrawSolidSurface(s, int(int64(unsafe(reinterpret<uint64>(s.data))) & 255l))
            D_DrawZSpans(s.spans)
            unsafe {  // nolint:STYLE025
                s += 1
            }
        }
    } else {
        s = unsafe(addr<surf_s?>(unsafe(surfaces[1])))
        while (unsafe(reinterpret<uint64>(s)) < unsafe(reinterpret<uint64>(surface_p))) {
            if (s.spans == null) {
                unsafe {  // nolint:STYLE025
                    s += 1
                }
                continue
            }
            r_drawnpolycount = r_drawnpolycount + 1
            d_zistepu = s.d_zistepu
            d_zistepv = s.d_zistepv
            d_ziorigin = s.d_ziorigin
            if ((s.flags & 4) != 0) {
                if (r_skymade == 0) {
                    R_MakeSky()
                }
                D_DrawSkyScans8(s.spans)
                D_DrawZSpans(s.spans)
            } elif ((s.flags & 64) != 0) {
                d_zistepu = 0.0
                d_zistepv = 0.0
                d_ziorigin = float(-0.9lf)
                D_DrawSolidSurface(s, int(r_clearcolor.value) & 255)
                D_DrawZSpans(s.spans)
            } elif ((s.flags & 16) != 0) {
                pface = unsafe(reinterpret<msurface_s?>(unsafe(reinterpret<msurface_s?>(s.data))))
                miplevel = 0
                var c2da_fresh0 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(pface.texinfo.texture)) + 56ul))
                cacheblock = unsafe(reinterpret<uint8?>(unsafe(unsafe(reinterpret<uint8?>(pface.texinfo.texture)) + int64(unsafe(unsafe(reinterpret<uint?>(c2da_fresh0))[0])))))
                cachewidth = 64
                if (uint(s.insubmodel) != 0u) {
                    currententity = unsafe(reinterpret<entity_s?>(s.entity))
                    var c2da_fresh1 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(currententity)) + 88ul))
                    unsafe(unsafe(addr(local_modelorg[0]))[0]) = unsafe(unsafe(addr(r_origin[0]))[0]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh1))[0])
                    var c2da_fresh2 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(currententity)) + 88ul))
                    unsafe(unsafe(addr(local_modelorg[0]))[1]) = unsafe(unsafe(addr(r_origin[0]))[1]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh2))[1])
                    var c2da_fresh3 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(currententity)) + 88ul))
                    unsafe(unsafe(addr(local_modelorg[0]))[2]) = unsafe(unsafe(addr(r_origin[0]))[2]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh3))[2])
                    TransformVector(unsafe(addr<float?>(local_modelorg[0])), unsafe(addr<float?>(transformed_modelorg[0])))
                    R_RotateBmodel()
                }
                D_CalcGradients(pface)
                Turbulent8(s.spans)
                D_DrawZSpans(s.spans)
                if (uint(s.insubmodel) != 0u) {
                    currententity = unsafe(addr<entity_s?>(unsafe(unsafe(addr(cl_entities[0]))[0])))
                    unsafe(unsafe(addr(transformed_modelorg[0]))[0]) = float(unsafe(unsafe(addr(world_transformed_modelorg[0]))[0]))  // nolint:PERF020
                    unsafe(unsafe(addr(transformed_modelorg[0]))[1]) = float(unsafe(unsafe(addr(world_transformed_modelorg[0]))[1]))  // nolint:PERF020
                    unsafe(unsafe(addr(transformed_modelorg[0]))[2]) = float(unsafe(unsafe(addr(world_transformed_modelorg[0]))[2]))  // nolint:PERF020
                    unsafe(unsafe(addr(vpn[0]))[0]) = unsafe(unsafe(addr(base_vpn[0]))[0])
                    unsafe(unsafe(addr(vpn[0]))[1]) = unsafe(unsafe(addr(base_vpn[0]))[1])
                    unsafe(unsafe(addr(vpn[0]))[2]) = unsafe(unsafe(addr(base_vpn[0]))[2])
                    unsafe(unsafe(addr(vup[0]))[0]) = unsafe(unsafe(addr(base_vup[0]))[0])
                    unsafe(unsafe(addr(vup[0]))[1]) = unsafe(unsafe(addr(base_vup[0]))[1])
                    unsafe(unsafe(addr(vup[0]))[2]) = unsafe(unsafe(addr(base_vup[0]))[2])
                    unsafe(unsafe(addr(vright[0]))[0]) = unsafe(unsafe(addr(base_vright[0]))[0])
                    unsafe(unsafe(addr(vright[0]))[1]) = unsafe(unsafe(addr(base_vright[0]))[1])
                    unsafe(unsafe(addr(vright[0]))[2]) = unsafe(unsafe(addr(base_vright[0]))[2])
                    unsafe(unsafe(addr(modelorg[0]))[0]) = unsafe(unsafe(addr(base_modelorg[0]))[0])
                    unsafe(unsafe(addr(modelorg[0]))[1]) = unsafe(unsafe(addr(base_modelorg[0]))[1])
                    unsafe(unsafe(addr(modelorg[0]))[2]) = unsafe(unsafe(addr(base_modelorg[0]))[2])
                    R_TransformFrustum()
                }
            } else {
                if (uint(s.insubmodel) != 0u) {
                    currententity = unsafe(reinterpret<entity_s?>(s.entity))
                    var c2da_fresh4 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(currententity)) + 88ul))
                    unsafe(unsafe(addr(local_modelorg[0]))[0]) = unsafe(unsafe(addr(r_origin[0]))[0]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh4))[0])
                    var c2da_fresh5 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(currententity)) + 88ul))
                    unsafe(unsafe(addr(local_modelorg[0]))[1]) = unsafe(unsafe(addr(r_origin[0]))[1]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh5))[1])
                    var c2da_fresh6 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(currententity)) + 88ul))
                    unsafe(unsafe(addr(local_modelorg[0]))[2]) = unsafe(unsafe(addr(r_origin[0]))[2]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh6))[2])
                    TransformVector(unsafe(addr<float?>(local_modelorg[0])), unsafe(addr<float?>(transformed_modelorg[0])))
                    R_RotateBmodel()
                }
                pface = unsafe(reinterpret<msurface_s?>(unsafe(reinterpret<msurface_s?>(s.data))))
                miplevel = D_MipLevelForScale(s.nearzi * scale_for_mip * pface.texinfo.mipadjust)
                pcurrentcache = unsafe(reinterpret<surfcache_s?>(unsafe(reinterpret<surfcache_s?>(D_CacheSurface(pface, miplevel)))))
                var c2da_fresh7 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pcurrentcache)) + 64ul))
                cacheblock = unsafe(reinterpret<uint8?>(c2da_fresh7))
                cachewidth = int(pcurrentcache.width)
                D_CalcGradients(pface)
                invoke(d_drawspans, s.spans)
                D_DrawZSpans(s.spans)
                if (uint(s.insubmodel) != 0u) {
                    currententity = unsafe(addr<entity_s?>(unsafe(unsafe(addr(cl_entities[0]))[0])))
                    unsafe(unsafe(addr(transformed_modelorg[0]))[0]) = float(unsafe(unsafe(addr(world_transformed_modelorg[0]))[0]))  // nolint:PERF020
                    unsafe(unsafe(addr(transformed_modelorg[0]))[1]) = float(unsafe(unsafe(addr(world_transformed_modelorg[0]))[1]))  // nolint:PERF020
                    unsafe(unsafe(addr(transformed_modelorg[0]))[2]) = float(unsafe(unsafe(addr(world_transformed_modelorg[0]))[2]))  // nolint:PERF020
                    unsafe(unsafe(addr(vpn[0]))[0]) = unsafe(unsafe(addr(base_vpn[0]))[0])
                    unsafe(unsafe(addr(vpn[0]))[1]) = unsafe(unsafe(addr(base_vpn[0]))[1])
                    unsafe(unsafe(addr(vpn[0]))[2]) = unsafe(unsafe(addr(base_vpn[0]))[2])
                    unsafe(unsafe(addr(vup[0]))[0]) = unsafe(unsafe(addr(base_vup[0]))[0])
                    unsafe(unsafe(addr(vup[0]))[1]) = unsafe(unsafe(addr(base_vup[0]))[1])
                    unsafe(unsafe(addr(vup[0]))[2]) = unsafe(unsafe(addr(base_vup[0]))[2])
                    unsafe(unsafe(addr(vright[0]))[0]) = unsafe(unsafe(addr(base_vright[0]))[0])
                    unsafe(unsafe(addr(vright[0]))[1]) = unsafe(unsafe(addr(base_vright[0]))[1])
                    unsafe(unsafe(addr(vright[0]))[2]) = unsafe(unsafe(addr(base_vright[0]))[2])
                    unsafe(unsafe(addr(modelorg[0]))[0]) = unsafe(unsafe(addr(base_modelorg[0]))[0])
                    unsafe(unsafe(addr(modelorg[0]))[1]) = unsafe(unsafe(addr(base_modelorg[0]))[1])
                    unsafe(unsafe(addr(modelorg[0]))[2]) = unsafe(unsafe(addr(base_modelorg[0]))[2])
                    R_TransformFrustum()
                }
            }
            unsafe {  // nolint:STYLE025
                s += 1
            }
        }
    }
    return
}
var transformed_modelorg : vec3_t = default<vec3_t>

[export, sideeffects]
def D_CalcGradients(var pface_0 : msurface_s?) {
    var pplane : mplane_s?
    var mipscale : float
    var p_temp1 : vec3_t
    var p_saxis : vec3_t
    var p_taxis : vec3_t
    var t : float
    pplane = unsafe(reinterpret<mplane_s?>(pface_0.plane))
    mipscale = float(1.0lf / double(float(1 << miplevel)))
    var c2da_fresh8 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(pface_0.texinfo))))
    TransformVector(unsafe(addr<float?>(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh8))[0])[0])), unsafe(addr<float?>(p_saxis[0])))
    var c2da_fresh9 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(pface_0.texinfo))))
    TransformVector(unsafe(addr<float?>(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh9))[1])[0])), unsafe(addr<float?>(p_taxis[0])))
    t = xscaleinv * mipscale
    d_sdivzstepu = unsafe(unsafe(addr(p_saxis[0]))[0]) * t
    d_tdivzstepu = unsafe(unsafe(addr(p_taxis[0]))[0]) * t
    t = yscaleinv * mipscale
    d_sdivzstepv = -unsafe(unsafe(addr(p_saxis[0]))[1]) * t
    d_tdivzstepv = -unsafe(unsafe(addr(p_taxis[0]))[1]) * t
    d_sdivzorigin = unsafe(unsafe(addr(p_saxis[0]))[2]) * mipscale - xcenter * d_sdivzstepu - ycenter * d_sdivzstepv
    d_tdivzorigin = unsafe(unsafe(addr(p_taxis[0]))[2]) * mipscale - xcenter * d_tdivzstepu - ycenter * d_tdivzstepv
    VectorScale(unsafe(addr<float?>(transformed_modelorg[0])), mipscale, unsafe(addr<float?>(p_temp1[0])))
    t = 65536.0 * mipscale
    var c2da_fresh10 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(pface_0)) + 72ul))
    var c2da_fresh11 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(pface_0.texinfo))))
    sadjust = int(float(int(double((unsafe(unsafe(addr(p_temp1[0]))[0]) * unsafe(unsafe(addr(p_saxis[0]))[0]) + unsafe(unsafe(addr(p_temp1[0]))[1]) * unsafe(unsafe(addr(p_saxis[0]))[1]) + unsafe(unsafe(addr(p_temp1[0]))[2]) * unsafe(unsafe(addr(p_saxis[0]))[2])) * 65536.0) + 0.5lf) - (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh10))[0])) << 16 >> miplevel)) + unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh11))[0])[0]))[3]) * t)
    var c2da_fresh12 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(pface_0)) + 72ul))
    var c2da_fresh13 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(pface_0.texinfo))))
    tadjust = int(float(int(double((unsafe(unsafe(addr(p_temp1[0]))[0]) * unsafe(unsafe(addr(p_taxis[0]))[0]) + unsafe(unsafe(addr(p_temp1[0]))[1]) * unsafe(unsafe(addr(p_taxis[0]))[1]) + unsafe(unsafe(addr(p_temp1[0]))[2]) * unsafe(unsafe(addr(p_taxis[0]))[2])) * 65536.0) + 0.5lf) - (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh12))[1])) << 16 >> miplevel)) + unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh13))[1])[0]))[3]) * t)
    var c2da_fresh14 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(pface_0)) + 76ul))
    bbextents = (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh14))[0])) << 16 >> miplevel) - 1
    var c2da_fresh15 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(pface_0)) + 76ul))
    bbextentt = (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh15))[1])) << 16 >> miplevel) - 1
    return
}
var private miplevel : int = default<int>

var scale_for_mip : float = default<float>

[export, sideeffects]
def D_MipLevelForScale(var scale : float) : int {
    var lmiplevel : int
    if (scale >= d_scalemip[0]) {
        lmiplevel = 0
    } elif (scale >= d_scalemip[1]) {
        lmiplevel = 1
    } elif (scale >= d_scalemip[2]) {
        lmiplevel = 2
    } else {
        lmiplevel = 3
    }
    if (lmiplevel < d_minmip) {
        lmiplevel = d_minmip
    }
    return lmiplevel
}
[export, sideeffects]
def D_DrawSolidSurface(var surf : surf_s?; var color : int) {
    var span : espan_s?
    var pdest : uint8?
    var u : int
    var u2 : int
    var pix : int = color << 24 | color << 16 | color << 8 | color
    span = unsafe(reinterpret<espan_s?>(surf.spans))
    while (span != null) {
        pdest = unsafe(reinterpret<uint8?>(unsafe(d_viewbuffer + int64(screenwidth * span.v))))
        u = span.u
        u2 = span.u + span.count - 1
        unsafe(pdest[u]) = uint8(pix)
        if (u2 - u < 8) {
            u++
            while (u <= u2) {
                unsafe(pdest[u]) = uint8(pix)
                u++
            }
        } else {
            u++
            while ((u & 3) != 0) {
                unsafe(pdest[u]) = uint8(pix)
                u++
            }
            u2 -= 4
            while (u <= u2) {
                var c2da_fresh16 : int? = unsafe(reinterpret<int?>(unsafe(pdest + u)))
                *c2da_fresh16 = pix
                u += 4
            }
            u2 += 4
            while (u <= u2) {
                unsafe(pdest[u]) = uint8(pix)
                u++
            }
        }
        span = unsafe(reinterpret<espan_s?>(span.pnext))
    }
    return
}
var ubasestep : int = default<int>

var errorterm : int = default<int>

var erroradjustup : int = default<int>

var erroradjustdown : int = default<int>

var vstartscan : int = default<int>

[sideeffects]
def private c2da_layout_proofs_9() {
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
    static_assert(typeinfo sizeof(type<surfcache_t>) == 72, "C layout of surfcache_t: sizeof")
    static_assert(typeinfo alignof(type<surfcache_t>) == 8, "C layout of surfcache_t: alignof")
    static_assert(typeinfo offsetof<next>(type<surfcache_t>) == 0, "C layout of surfcache_t: offsetof next")
    static_assert(typeinfo offsetof<owner>(type<surfcache_t>) == 8, "C layout of surfcache_t: offsetof owner")
    static_assert(typeinfo offsetof<lightadj>(type<surfcache_t>) == 16, "C layout of surfcache_t: offsetof lightadj")
    static_assert(typeinfo offsetof<dlight>(type<surfcache_t>) == 32, "C layout of surfcache_t: offsetof dlight")
    static_assert(typeinfo offsetof<size>(type<surfcache_t>) == 36, "C layout of surfcache_t: offsetof size")
    static_assert(typeinfo offsetof<width>(type<surfcache_t>) == 40, "C layout of surfcache_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<surfcache_t>) == 44, "C layout of surfcache_t: offsetof height")
    static_assert(typeinfo offsetof<mipscale>(type<surfcache_t>) == 48, "C layout of surfcache_t: offsetof mipscale")
    static_assert(typeinfo offsetof<texture>(type<surfcache_t>) == 56, "C layout of surfcache_t: offsetof texture")
    static_assert(typeinfo offsetof<data>(type<surfcache_t>) == 64, "C layout of surfcache_t: offsetof data")
}
