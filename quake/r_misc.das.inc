var private c2da_str_r_misc_0 : array<int8> = [int8(37), int8(102), int8(32), int8(115), int8(101), int8(99), int8(111), int8(110), int8(100), int8(115), int8(32), int8(40), int8(37), int8(102), int8(32), int8(102), int8(112), int8(115), int8(41), int8(10), int8(0)]

var private c2da_str_r_misc_1 : array<int8> = [int8(37), int8(51), int8(105), int8(32), int8(112), int8(111), int8(108), int8(121), int8(103), int8(111), int8(110), int8(32), int8(109), int8(111), int8(100), int8(101), int8(108), int8(32), int8(100), int8(114), int8(97), int8(119), int8(110), int8(10), int8(0)]

var private c2da_str_r_misc_2 : array<int8> = [int8(37), int8(53), int8(46), int8(49), int8(102), int8(32), int8(109), int8(115), int8(32), int8(37), int8(51), int8(105), int8(47), int8(37), int8(51), int8(105), int8(47), int8(37), int8(51), int8(105), int8(32), int8(112), int8(111), int8(108), int8(121), int8(32), int8(37), int8(51), int8(105), int8(32), int8(115), int8(117), int8(114), int8(102), int8(10), int8(0)]

var private c2da_str_r_misc_3 : array<int8> = [int8(37), int8(51), int8(105), int8(32), int8(37), int8(52), int8(46), int8(49), int8(102), int8(112), int8(32), int8(37), int8(51), int8(105), int8(119), int8(32), int8(37), int8(52), int8(46), int8(49), int8(102), int8(98), int8(32), int8(37), int8(51), int8(105), int8(115), int8(32), int8(37), int8(52), int8(46), int8(49), int8(102), int8(101), int8(32), int8(37), int8(52), int8(46), int8(49), int8(102), int8(118), int8(10), int8(0)]

var private c2da_str_r_misc_4 : array<int8> = [int8(114), int8(95), int8(100), int8(114), int8(97), int8(119), int8(111), int8(114), int8(100), int8(101), int8(114), int8(0)]

var private c2da_str_r_misc_5 : array<int8> = [int8(48), int8(0)]

var private c2da_str_r_misc_6 : array<int8> = [int8(114), int8(95), int8(102), int8(117), int8(108), int8(108), int8(98), int8(114), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_r_misc_7 : array<int8> = [int8(114), int8(95), int8(97), int8(109), int8(98), int8(105), int8(101), int8(110), int8(116), int8(0)]

var private c2da_str_r_misc_8 : array<int8> = [int8(114), int8(95), int8(100), int8(114), int8(97), int8(119), int8(102), int8(108), int8(97), int8(116), int8(0)]

var private c2da_str_r_misc_9 : array<int8> = [int8(85), int8(115), int8(101), int8(100), int8(32), int8(37), int8(100), int8(32), int8(111), int8(102), int8(32), int8(37), int8(100), int8(32), int8(115), int8(117), int8(114), int8(102), int8(115), int8(59), int8(32), int8(37), int8(100), int8(32), int8(109), int8(97), int8(120), int8(10), int8(0)]

var private c2da_str_r_misc_10 : array<int8> = [int8(85), int8(115), int8(101), int8(100), int8(32), int8(37), int8(100), int8(32), int8(111), int8(102), int8(32), int8(37), int8(100), int8(32), int8(101), int8(100), int8(103), int8(101), int8(115), int8(59), int8(32), int8(37), int8(100), int8(32), int8(109), int8(97), int8(120), int8(10), int8(0)]

var private R_TimeGraph__timex : int = 0

var private R_TimeGraph__r_timings : uint8[100] = fixed_array<uint8>(0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8, 0u8)

var private R_CheckVariables__oldbright : float = 0.0

[export, sideeffects]
def TransformVector(var in_0 : float?; var out : float?) {
    unsafe(out[0]) = unsafe(in_0[0]) * unsafe(unsafe(addr(vright[0]))[0]) + unsafe(in_0[1]) * unsafe(unsafe(addr(vright[0]))[1]) + unsafe(in_0[2]) * unsafe(unsafe(addr(vright[0]))[2])
    unsafe(out[1]) = unsafe(in_0[0]) * unsafe(unsafe(addr(vup[0]))[0]) + unsafe(in_0[1]) * unsafe(unsafe(addr(vup[0]))[1]) + unsafe(in_0[2]) * unsafe(unsafe(addr(vup[0]))[2])
    unsafe(out[2]) = unsafe(in_0[0]) * unsafe(unsafe(addr(vpn[0]))[0]) + unsafe(in_0[1]) * unsafe(unsafe(addr(vpn[0]))[1]) + unsafe(in_0[2]) * unsafe(unsafe(addr(vpn[0]))[2])
    return
}
[export, sideeffects]
def R_TransformPlane(var p : mplane_s?; var normal : float?; var dist : float?) {
    var d : float
    var c2da_fresh0 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
    var c2da_fresh1 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
    var c2da_fresh2 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
    d = unsafe(unsafe(addr(r_origin[0]))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh0))[0]) + unsafe(unsafe(addr(r_origin[0]))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh1))[1]) + unsafe(unsafe(addr(r_origin[0]))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh2))[2])
    var c2da_fresh3 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
    var c2da_fresh4 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
    var c2da_fresh5 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
    d = unsafe(unsafe(addr(r_origin[0]))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh3))[0]) + unsafe(unsafe(addr(r_origin[0]))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh4))[1]) + unsafe(unsafe(addr(r_origin[0]))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh5))[2])
    *dist = p.dist - d
    var c2da_fresh6 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
    TransformVector(unsafe(reinterpret<float?>(c2da_fresh6)), normal)
    return
}
[export, sideeffects]
def R_TransformFrustum() {
    var v : vec3_t
    var v2 : vec3_t
    for (i in range(0, 4)) {
        unsafe(unsafe(addr(v[0]))[0]) = unsafe(unsafe(addr(screenedge[i].normal[0]))[2])
        unsafe(unsafe(addr(v[0]))[1]) = -unsafe(unsafe(addr(screenedge[i].normal[0]))[0])
        unsafe(unsafe(addr(v[0]))[2]) = unsafe(unsafe(addr(screenedge[i].normal[0]))[1])
        unsafe(unsafe(addr(v2[0]))[0]) = unsafe(unsafe(addr(v[0]))[1]) * unsafe(unsafe(addr(vright[0]))[0]) + unsafe(unsafe(addr(v[0]))[2]) * unsafe(unsafe(addr(vup[0]))[0]) + unsafe(unsafe(addr(v[0]))[0]) * unsafe(unsafe(addr(vpn[0]))[0])
        unsafe(unsafe(addr(v2[0]))[1]) = unsafe(unsafe(addr(v[0]))[1]) * unsafe(unsafe(addr(vright[0]))[1]) + unsafe(unsafe(addr(v[0]))[2]) * unsafe(unsafe(addr(vup[0]))[1]) + unsafe(unsafe(addr(v[0]))[0]) * unsafe(unsafe(addr(vpn[0]))[1])
        unsafe(unsafe(addr(v2[0]))[2]) = unsafe(unsafe(addr(v[0]))[1]) * unsafe(unsafe(addr(vright[0]))[2]) + unsafe(unsafe(addr(v[0]))[2]) * unsafe(unsafe(addr(vup[0]))[2]) + unsafe(unsafe(addr(v[0]))[0]) * unsafe(unsafe(addr(vpn[0]))[2])
        unsafe(unsafe(addr(view_clipplanes[i].normal[0]))[0]) = unsafe(unsafe(addr(v2[0]))[0])
        unsafe(unsafe(addr(view_clipplanes[i].normal[0]))[1]) = unsafe(unsafe(addr(v2[0]))[1])
        unsafe(unsafe(addr(view_clipplanes[i].normal[0]))[2]) = unsafe(unsafe(addr(v2[0]))[2])
        view_clipplanes[i].dist = unsafe(unsafe(addr(modelorg[0]))[0]) * unsafe(unsafe(addr(v2[0]))[0]) + unsafe(unsafe(addr(modelorg[0]))[1]) * unsafe(unsafe(addr(v2[0]))[1]) + unsafe(unsafe(addr(modelorg[0]))[2]) * unsafe(unsafe(addr(v2[0]))[2])
    }
    return
}
[export, sideeffects]
def R_TimeRefresh_f() {
    var start : float
    var stop : float
    var time : float
    var startangle : int
    var vr : vrect_s
    startangle = int(unsafe(unsafe(addr(r_refdef.viewangles[0]))[1]))
    start = float(Sys_FloatTime())
    for (i_0 in range(0, 128)) {
        unsafe(unsafe(addr(r_refdef.viewangles[0]))[1]) = float(double(i_0) / 128.0lf * 360.0lf)
        R_RenderView()
        vr.x = r_refdef.vrect.x
        vr.y = r_refdef.vrect.y
        vr.width = r_refdef.vrect.width
        vr.height = r_refdef.vrect.height
        vr.pnext = null
        VID_Update(unsafe(addr<vrect_s?>(vr)))
    }
    stop = float(Sys_FloatTime())
    time = stop - start
    Con_Printf(unsafe(addr<int8?>(c2da_str_r_misc_0[0])), [C2daVaArg(tag = 2, i64 = 0, f64 = double(time), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(128.0 / time), raw = 0x0)])
    unsafe(unsafe(addr(r_refdef.viewangles[0]))[1]) = float(startangle)
    return
}
[export, sideeffects]
def R_TimeGraph() {
    var a : int
    var r_time2 : float
    var x : int
    r_time2 = float(Sys_FloatTime())
    R_TimeGraph__r_timings[R_TimeGraph__timex] = uint8(int(double(r_time2 - r_time1) / 0.01lf))
    a = R_TimeGraph__timex
    if (r_refdef.vrect.width <= 100) {
        x = r_refdef.vrect.width - 1
    } else {
        x = r_refdef.vrect.width - (r_refdef.vrect.width - 100) / 2
    }
    while (true) {
        R_LineGraph(x, r_refdef.vrect.height - 2, int(R_TimeGraph__r_timings[a]))
        if (x == 0) {
            break
        }
        x--
        a--
        if (a == -1) {
            a = 100 - 1
        }
        if (a == R_TimeGraph__timex) {
            break
        }
    }
    R_TimeGraph__timex = (R_TimeGraph__timex + 1) % 100
    return
}
[export, sideeffects]
def R_LineGraph(var x_0 : int; var y : int; var h : int) {
    var i_1 : int
    var dest : uint8?
    var s : int
    x_0 = x_0 + r_refdef.vrect.x
    y = y + r_refdef.vrect.y
    dest = unsafe(reinterpret<uint8?>(unsafe(unsafe(vid.buffer + int64(vid.rowbytes * uint(y))) + x_0)))
    s = int(r_graphheight.value)
    if (h > s) {
        h = s
    }
    i_1 = 0
    while (i_1 < h) {
        unsafe(dest[0]) = 0xffu8
        var c2da_fresh7 : uint8? = unsafe(dest + -int64(uint(vid.rowbytes)))
        *c2da_fresh7 = 0x30u8
        i_1++
        unsafe {  // nolint:STYLE025
            dest -= int64(vid.rowbytes * 2u)
        }
    }
    while (i_1 < s) {
        unsafe(dest[0]) = 0x30u8
        var c2da_fresh8 : uint8? = unsafe(dest + -int64(uint(vid.rowbytes)))
        *c2da_fresh8 = 0x30u8
        i_1++
        unsafe {  // nolint:STYLE025
            dest -= int64(vid.rowbytes * 2u)
        }
    }
    return
}
[export, sideeffects]
def R_PrintAliasStats() {
    Con_Printf(unsafe(addr<int8?>(c2da_str_r_misc_1[0])), [C2daVaArg(tag = 1, i64 = int64(r_amodels_drawn), f64 = 0.0lf, raw = 0x0)])
    return
}
[export, sideeffects]
def R_PrintTimes() {
    var r_time2_0 : float
    var ms : float
    r_time2_0 = float(Sys_FloatTime())
    ms = 1000.0 * (r_time2_0 - r_time1)
    Con_Printf(unsafe(addr<int8?>(c2da_str_r_misc_2[0])), [C2daVaArg(tag = 2, i64 = 0, f64 = double(ms), raw = 0x0), C2daVaArg(tag = 1, i64 = int64(c_faceclip), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(r_polycount), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(r_drawnpolycount), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(c_surf), f64 = 0.0lf, raw = 0x0)])
    c_surf = 0
    return
}
[export, sideeffects]
def R_PrintDSpeeds() {
    var ms_0 : float
    var dp_time : float
    var r_time2_1 : float
    var rw_time : float
    var db_time : float
    var se_time : float
    var de_time : float
    var dv_time : float
    r_time2_1 = float(Sys_FloatTime())
    dp_time = (dp_time2 - dp_time1) * 1000.0
    rw_time = (rw_time2 - rw_time1) * 1000.0
    db_time = (db_time2 - db_time1) * 1000.0
    se_time = (se_time2 - se_time1) * 1000.0
    de_time = (de_time2 - de_time1) * 1000.0
    dv_time = (dv_time2 - dv_time1) * 1000.0
    ms_0 = (r_time2_1 - r_time1) * 1000.0
    Con_Printf(unsafe(addr<int8?>(c2da_str_r_misc_3[0])), [C2daVaArg(tag = 1, i64 = int64(int(ms_0)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(dp_time), raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(rw_time)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(db_time), raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(se_time)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(de_time), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(dv_time), raw = 0x0)])
    return
}
[export, sideeffects]
def R_SetupFrame() {
    var edgecount : int
    var vrect : vrect_s
    var w : float
    var h_0 : float
    if (cl.maxclients > 1) {
        Cvar_Set(unsafe(addr<int8?>(c2da_str_r_misc_4[0])), unsafe(addr<int8?>(c2da_str_r_misc_5[0])))
        Cvar_Set(unsafe(addr<int8?>(c2da_str_r_misc_6[0])), unsafe(addr<int8?>(c2da_str_r_misc_5[0])))
        Cvar_Set(unsafe(addr<int8?>(c2da_str_r_misc_7[0])), unsafe(addr<int8?>(c2da_str_r_misc_5[0])))
        Cvar_Set(unsafe(addr<int8?>(c2da_str_r_misc_8[0])), unsafe(addr<int8?>(c2da_str_r_misc_5[0])))
    }
    if (r_numsurfs.value != 0.0) {
        if (unsafe(surface_p - surfaces) > int64(r_maxsurfsseen)) {
            r_maxsurfsseen = int(unsafe(surface_p - surfaces))
        }
        Con_Printf(unsafe(addr<int8?>(c2da_str_r_misc_9[0])), [C2daVaArg(tag = 1, i64 = unsafe(surface_p - surfaces), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = unsafe(surf_max - surfaces), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(r_maxsurfsseen), f64 = 0.0lf, raw = 0x0)])
    }
    if (r_numedges.value != 0.0) {
        edgecount = int(unsafe(edge_p - r_edges))
        if (edgecount > r_maxedgesseen) {
            r_maxedgesseen = edgecount
        }
        Con_Printf(unsafe(addr<int8?>(c2da_str_r_misc_10[0])), [C2daVaArg(tag = 1, i64 = int64(edgecount), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(r_numallocatededges), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(r_maxedgesseen), f64 = 0.0lf, raw = 0x0)])
    }
    r_refdef.ambientlight = int(r_ambient.value)
    if (r_refdef.ambientlight < 0) {
        r_refdef.ambientlight = 0
    }
    if (uint(sv.active) == 0u) {
        r_draworder.value = 0.0
    }
    R_CheckVariables()
    R_AnimateLight()
    r_framecount = r_framecount + 1
    numbtofpolys = 0
    unsafe(unsafe(addr(modelorg[0]))[0]) = unsafe(unsafe(addr(r_refdef.vieworg[0]))[0])
    unsafe(unsafe(addr(modelorg[0]))[1]) = unsafe(unsafe(addr(r_refdef.vieworg[0]))[1])
    unsafe(unsafe(addr(modelorg[0]))[2]) = unsafe(unsafe(addr(r_refdef.vieworg[0]))[2])
    unsafe(unsafe(addr(r_origin[0]))[0]) = unsafe(unsafe(addr(r_refdef.vieworg[0]))[0])
    unsafe(unsafe(addr(r_origin[0]))[1]) = unsafe(unsafe(addr(r_refdef.vieworg[0]))[1])
    unsafe(unsafe(addr(r_origin[0]))[2]) = unsafe(unsafe(addr(r_refdef.vieworg[0]))[2])
    AngleVectors(unsafe(addr<float?>(r_refdef.viewangles[0])), unsafe(addr<float?>(vpn[0])), unsafe(addr<float?>(vright[0])), unsafe(addr<float?>(vup[0])))
    r_oldviewleaf = unsafe(reinterpret<mleaf_s?>(r_viewleaf))
    r_viewleaf = unsafe(reinterpret<mleaf_s?>(unsafe(reinterpret<mleaf_s?>(Mod_PointInLeaf(unsafe(addr<float?>(r_origin[0])), cl.worldmodel)))))
    r_dowarpold = r_dowarp
    r_dowarp = unsafe(reinterpret<qboolean>(uint(r_waterwarp.value != 0.0 && r_viewleaf.contents <= -3 ? 1 : 0)))
    if (uint(r_dowarp) != uint(r_dowarpold) || uint(r_viewchanged) != 0x0 || lcd_x.value != 0.0) {
        if (uint(r_dowarp) != 0u) {
            if (vid.width <= uint(vid.maxwarpwidth) && vid.height <= uint(vid.maxwarpheight)) {
                vrect.x = 0
                vrect.y = 0
                vrect.width = int(vid.width)
                vrect.height = int(vid.height)
                R_ViewChanged(unsafe(addr<vrect_s?>(vrect)), sb_lines, vid.aspect)
            } else {
                w = float(vid.width)
                h_0 = float(vid.height)
                if (w > float(vid.maxwarpwidth)) {
                    h_0 *= float(vid.maxwarpwidth) / w
                    w = float(vid.maxwarpwidth)
                }
                if (h_0 > float(vid.maxwarpheight)) {
                    h_0 = float(vid.maxwarpheight)
                    w *= float(vid.maxwarpheight) / h_0
                }
                vrect.x = 0
                vrect.y = 0
                vrect.width = int(w)
                vrect.height = int(h_0)
                R_ViewChanged(unsafe(addr<vrect_s?>(vrect)), int(float(sb_lines) * (h_0 / float(vid.height))), vid.aspect * (h_0 / w) * (float(vid.width) / float(vid.height)))
            }
        } else {
            vrect.x = 0
            vrect.y = 0
            vrect.width = int(vid.width)
            vrect.height = int(vid.height)
            R_ViewChanged(unsafe(addr<vrect_s?>(vrect)), sb_lines, vid.aspect)
        }
        r_viewchanged = unsafe(reinterpret<qboolean>(0u))
    }
    R_TransformFrustum()
    unsafe(unsafe(addr(base_vpn[0]))[0]) = unsafe(unsafe(addr(vpn[0]))[0])
    unsafe(unsafe(addr(base_vpn[0]))[1]) = unsafe(unsafe(addr(vpn[0]))[1])
    unsafe(unsafe(addr(base_vpn[0]))[2]) = unsafe(unsafe(addr(vpn[0]))[2])
    unsafe(unsafe(addr(base_vright[0]))[0]) = unsafe(unsafe(addr(vright[0]))[0])
    unsafe(unsafe(addr(base_vright[0]))[1]) = unsafe(unsafe(addr(vright[0]))[1])
    unsafe(unsafe(addr(base_vright[0]))[2]) = unsafe(unsafe(addr(vright[0]))[2])
    unsafe(unsafe(addr(base_vup[0]))[0]) = unsafe(unsafe(addr(vup[0]))[0])
    unsafe(unsafe(addr(base_vup[0]))[1]) = unsafe(unsafe(addr(vup[0]))[1])
    unsafe(unsafe(addr(base_vup[0]))[2]) = unsafe(unsafe(addr(vup[0]))[2])
    unsafe(unsafe(addr(base_modelorg[0]))[0]) = unsafe(unsafe(addr(modelorg[0]))[0])
    unsafe(unsafe(addr(base_modelorg[0]))[1]) = unsafe(unsafe(addr(modelorg[0]))[1])
    unsafe(unsafe(addr(base_modelorg[0]))[2]) = unsafe(unsafe(addr(modelorg[0]))[2])
    R_SetSkyFrame()
    R_SetUpFrustumIndexes()
    r_cache_thrash = unsafe(reinterpret<qboolean>(0u))
    c_faceclip = 0
    d_spanpixcount = 0
    r_polycount = 0
    r_drawnpolycount = 0
    r_wholepolycount = 0
    r_amodels_drawn = 0
    r_outofsurfaces = 0
    r_outofedges = 0
    D_SetupFrame()
    return
}
[export, sideeffects]
def R_SetUpFrustumIndexes() {
    var pindex : int? = unsafe(addr<int?>(r_frustum_indexes[0]))
    for (i_2 in range(0, 4)) {
        for (j in range(0, 3)) {
            if (unsafe(unsafe(addr(view_clipplanes[i_2].normal[0]))[j]) < 0.0) {
                unsafe(pindex[j]) = j
                unsafe(pindex[j + 3]) = j + 3
            } else {
                unsafe(pindex[j]) = j + 3
                unsafe(pindex[j + 3]) = j
            }
        }
        pfrustum_indexes[i_2] = unsafe(reinterpret<int?>(pindex))
        unsafe {  // nolint:STYLE025
            pindex += 6
        }
    }
    return
}
[export, sideeffects]
def R_CheckVariables() {
    if (r_fullbright.value != R_CheckVariables__oldbright) {
        R_CheckVariables__oldbright = r_fullbright.value
        D_FlushCaches()
    }
    return
}
[export, sideeffects]
def Show() {
    var vr_0 : vrect_s
    vr_0.y = 0
    vr_0.x = vr_0.y
    vr_0.width = int(vid.width)
    vr_0.height = int(vid.height)
    vr_0.pnext = null
    VID_Update(unsafe(addr<vrect_s?>(vr_0)))
    return
}
[export, sideeffects]
def WarpPalette() {
    var newpalette : uint8[768]
    var basecolor : int[3]
    basecolor[0] = 130
    basecolor[1] = 80
    basecolor[2] = 50
    for (i_3 in range(0, 256)) {
        for (j_0 in range(0, 3)) {
            newpalette[i_3 * 3 + j_0] = uint8((int(unsafe(host_basepal[i_3 * 3 + j_0])) + basecolor[j_0]) / 2)
        }
    }
    VID_ShiftPalette(unsafe(addr<uint8?>(newpalette[0])))
    return
}
[sideeffects]
def private c2da_layout_proofs_40() {
    static_assert(typeinfo sizeof(type<sizebuf_s>) == 24, "C layout of sizebuf_s: sizeof")
    static_assert(typeinfo alignof(type<sizebuf_s>) == 8, "C layout of sizebuf_s: alignof")
    static_assert(typeinfo offsetof<allowoverflow>(type<sizebuf_s>) == 0, "C layout of sizebuf_s: offsetof allowoverflow")
    static_assert(typeinfo offsetof<overflowed>(type<sizebuf_s>) == 4, "C layout of sizebuf_s: offsetof overflowed")
    static_assert(typeinfo offsetof<data>(type<sizebuf_s>) == 8, "C layout of sizebuf_s: offsetof data")
    static_assert(typeinfo offsetof<maxsize>(type<sizebuf_s>) == 16, "C layout of sizebuf_s: offsetof maxsize")
    static_assert(typeinfo offsetof<cursize>(type<sizebuf_s>) == 20, "C layout of sizebuf_s: offsetof cursize")
    static_assert(typeinfo sizeof(type<sizebuf_t>) == 24, "C layout of sizebuf_t: sizeof")
    static_assert(typeinfo alignof(type<sizebuf_t>) == 8, "C layout of sizebuf_t: alignof")
    static_assert(typeinfo offsetof<allowoverflow>(type<sizebuf_t>) == 0, "C layout of sizebuf_t: offsetof allowoverflow")
    static_assert(typeinfo offsetof<overflowed>(type<sizebuf_t>) == 4, "C layout of sizebuf_t: offsetof overflowed")
    static_assert(typeinfo offsetof<data>(type<sizebuf_t>) == 8, "C layout of sizebuf_t: offsetof data")
    static_assert(typeinfo offsetof<maxsize>(type<sizebuf_t>) == 16, "C layout of sizebuf_t: offsetof maxsize")
    static_assert(typeinfo offsetof<cursize>(type<sizebuf_t>) == 20, "C layout of sizebuf_t: offsetof cursize")
    static_assert(typeinfo sizeof(type<link_s>) == 16, "C layout of link_s: sizeof")
    static_assert(typeinfo alignof(type<link_s>) == 8, "C layout of link_s: alignof")
    static_assert(typeinfo offsetof<prev>(type<link_s>) == 0, "C layout of link_s: offsetof prev")
    static_assert(typeinfo offsetof<next>(type<link_s>) == 8, "C layout of link_s: offsetof next")
    static_assert(typeinfo sizeof(type<link_t>) == 16, "C layout of link_t: sizeof")
    static_assert(typeinfo alignof(type<link_t>) == 8, "C layout of link_t: alignof")
    static_assert(typeinfo offsetof<prev>(type<link_t>) == 0, "C layout of link_t: offsetof prev")
    static_assert(typeinfo offsetof<next>(type<link_t>) == 8, "C layout of link_t: offsetof next")
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
    static_assert(typeinfo sizeof(type<viddef_t>) == 96, "C layout of viddef_t: sizeof")
    static_assert(typeinfo alignof(type<viddef_t>) == 8, "C layout of viddef_t: alignof")
    static_assert(typeinfo offsetof<buffer>(type<viddef_t>) == 0, "C layout of viddef_t: offsetof buffer")
    static_assert(typeinfo offsetof<colormap>(type<viddef_t>) == 8, "C layout of viddef_t: offsetof colormap")
    static_assert(typeinfo offsetof<colormap16>(type<viddef_t>) == 16, "C layout of viddef_t: offsetof colormap16")
    static_assert(typeinfo offsetof<fullbright>(type<viddef_t>) == 24, "C layout of viddef_t: offsetof fullbright")
    static_assert(typeinfo offsetof<rowbytes>(type<viddef_t>) == 28, "C layout of viddef_t: offsetof rowbytes")
    static_assert(typeinfo offsetof<width>(type<viddef_t>) == 32, "C layout of viddef_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<viddef_t>) == 36, "C layout of viddef_t: offsetof height")
    static_assert(typeinfo offsetof<aspect>(type<viddef_t>) == 40, "C layout of viddef_t: offsetof aspect")
    static_assert(typeinfo offsetof<numpages>(type<viddef_t>) == 44, "C layout of viddef_t: offsetof numpages")
    static_assert(typeinfo offsetof<recalc_refdef>(type<viddef_t>) == 48, "C layout of viddef_t: offsetof recalc_refdef")
    static_assert(typeinfo offsetof<conbuffer>(type<viddef_t>) == 56, "C layout of viddef_t: offsetof conbuffer")
    static_assert(typeinfo offsetof<conrowbytes>(type<viddef_t>) == 64, "C layout of viddef_t: offsetof conrowbytes")
    static_assert(typeinfo offsetof<conwidth>(type<viddef_t>) == 68, "C layout of viddef_t: offsetof conwidth")
    static_assert(typeinfo offsetof<conheight>(type<viddef_t>) == 72, "C layout of viddef_t: offsetof conheight")
    static_assert(typeinfo offsetof<maxwarpwidth>(type<viddef_t>) == 76, "C layout of viddef_t: offsetof maxwarpwidth")
    static_assert(typeinfo offsetof<maxwarpheight>(type<viddef_t>) == 80, "C layout of viddef_t: offsetof maxwarpheight")
    static_assert(typeinfo offsetof<direct>(type<viddef_t>) == 88, "C layout of viddef_t: offsetof direct")
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
    static_assert(typeinfo sizeof(type<usercmd_t>) == 24, "C layout of usercmd_t: sizeof")
    static_assert(typeinfo alignof(type<usercmd_t>) == 4, "C layout of usercmd_t: alignof")
    static_assert(typeinfo offsetof<viewangles>(type<usercmd_t>) == 0, "C layout of usercmd_t: offsetof viewangles")
    static_assert(typeinfo offsetof<forwardmove>(type<usercmd_t>) == 12, "C layout of usercmd_t: offsetof forwardmove")
    static_assert(typeinfo offsetof<sidemove>(type<usercmd_t>) == 16, "C layout of usercmd_t: offsetof sidemove")
    static_assert(typeinfo offsetof<upmove>(type<usercmd_t>) == 20, "C layout of usercmd_t: offsetof upmove")
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
    static_assert(typeinfo sizeof(type<entvars_t>) == 420, "C layout of entvars_t: sizeof")
    static_assert(typeinfo alignof(type<entvars_t>) == 4, "C layout of entvars_t: alignof")
    static_assert(typeinfo offsetof<modelindex>(type<entvars_t>) == 0, "C layout of entvars_t: offsetof modelindex")
    static_assert(typeinfo offsetof<absmin>(type<entvars_t>) == 4, "C layout of entvars_t: offsetof absmin")
    static_assert(typeinfo offsetof<absmax>(type<entvars_t>) == 16, "C layout of entvars_t: offsetof absmax")
    static_assert(typeinfo offsetof<ltime>(type<entvars_t>) == 28, "C layout of entvars_t: offsetof ltime")
    static_assert(typeinfo offsetof<movetype>(type<entvars_t>) == 32, "C layout of entvars_t: offsetof movetype")
    static_assert(typeinfo offsetof<solid>(type<entvars_t>) == 36, "C layout of entvars_t: offsetof solid")
    static_assert(typeinfo offsetof<origin>(type<entvars_t>) == 40, "C layout of entvars_t: offsetof origin")
    static_assert(typeinfo offsetof<oldorigin>(type<entvars_t>) == 52, "C layout of entvars_t: offsetof oldorigin")
    static_assert(typeinfo offsetof<velocity>(type<entvars_t>) == 64, "C layout of entvars_t: offsetof velocity")
    static_assert(typeinfo offsetof<angles>(type<entvars_t>) == 76, "C layout of entvars_t: offsetof angles")
    static_assert(typeinfo offsetof<avelocity>(type<entvars_t>) == 88, "C layout of entvars_t: offsetof avelocity")
    static_assert(typeinfo offsetof<punchangle>(type<entvars_t>) == 100, "C layout of entvars_t: offsetof punchangle")
    static_assert(typeinfo offsetof<classname>(type<entvars_t>) == 112, "C layout of entvars_t: offsetof classname")
    static_assert(typeinfo offsetof<model>(type<entvars_t>) == 116, "C layout of entvars_t: offsetof model")
    static_assert(typeinfo offsetof<frame>(type<entvars_t>) == 120, "C layout of entvars_t: offsetof frame")
    static_assert(typeinfo offsetof<skin>(type<entvars_t>) == 124, "C layout of entvars_t: offsetof skin")
    static_assert(typeinfo offsetof<effects>(type<entvars_t>) == 128, "C layout of entvars_t: offsetof effects")
    static_assert(typeinfo offsetof<mins>(type<entvars_t>) == 132, "C layout of entvars_t: offsetof mins")
    static_assert(typeinfo offsetof<maxs>(type<entvars_t>) == 144, "C layout of entvars_t: offsetof maxs")
    static_assert(typeinfo offsetof<size>(type<entvars_t>) == 156, "C layout of entvars_t: offsetof size")
    static_assert(typeinfo offsetof<touch>(type<entvars_t>) == 168, "C layout of entvars_t: offsetof touch")
    static_assert(typeinfo offsetof<use>(type<entvars_t>) == 172, "C layout of entvars_t: offsetof use")
    static_assert(typeinfo offsetof<think>(type<entvars_t>) == 176, "C layout of entvars_t: offsetof think")
    static_assert(typeinfo offsetof<blocked>(type<entvars_t>) == 180, "C layout of entvars_t: offsetof blocked")
    static_assert(typeinfo offsetof<nextthink>(type<entvars_t>) == 184, "C layout of entvars_t: offsetof nextthink")
    static_assert(typeinfo offsetof<groundentity>(type<entvars_t>) == 188, "C layout of entvars_t: offsetof groundentity")
    static_assert(typeinfo offsetof<health>(type<entvars_t>) == 192, "C layout of entvars_t: offsetof health")
    static_assert(typeinfo offsetof<frags>(type<entvars_t>) == 196, "C layout of entvars_t: offsetof frags")
    static_assert(typeinfo offsetof<weapon>(type<entvars_t>) == 200, "C layout of entvars_t: offsetof weapon")
    static_assert(typeinfo offsetof<weaponmodel>(type<entvars_t>) == 204, "C layout of entvars_t: offsetof weaponmodel")
    static_assert(typeinfo offsetof<weaponframe>(type<entvars_t>) == 208, "C layout of entvars_t: offsetof weaponframe")
    static_assert(typeinfo offsetof<currentammo>(type<entvars_t>) == 212, "C layout of entvars_t: offsetof currentammo")
    static_assert(typeinfo offsetof<ammo_shells>(type<entvars_t>) == 216, "C layout of entvars_t: offsetof ammo_shells")
    static_assert(typeinfo offsetof<ammo_nails>(type<entvars_t>) == 220, "C layout of entvars_t: offsetof ammo_nails")
    static_assert(typeinfo offsetof<ammo_rockets>(type<entvars_t>) == 224, "C layout of entvars_t: offsetof ammo_rockets")
    static_assert(typeinfo offsetof<ammo_cells>(type<entvars_t>) == 228, "C layout of entvars_t: offsetof ammo_cells")
    static_assert(typeinfo offsetof<items>(type<entvars_t>) == 232, "C layout of entvars_t: offsetof items")
    static_assert(typeinfo offsetof<takedamage>(type<entvars_t>) == 236, "C layout of entvars_t: offsetof takedamage")
    static_assert(typeinfo offsetof<chain>(type<entvars_t>) == 240, "C layout of entvars_t: offsetof chain")
    static_assert(typeinfo offsetof<deadflag>(type<entvars_t>) == 244, "C layout of entvars_t: offsetof deadflag")
    static_assert(typeinfo offsetof<view_ofs>(type<entvars_t>) == 248, "C layout of entvars_t: offsetof view_ofs")
    static_assert(typeinfo offsetof<button0>(type<entvars_t>) == 260, "C layout of entvars_t: offsetof button0")
    static_assert(typeinfo offsetof<button1>(type<entvars_t>) == 264, "C layout of entvars_t: offsetof button1")
    static_assert(typeinfo offsetof<button2>(type<entvars_t>) == 268, "C layout of entvars_t: offsetof button2")
    static_assert(typeinfo offsetof<impulse>(type<entvars_t>) == 272, "C layout of entvars_t: offsetof impulse")
    static_assert(typeinfo offsetof<fixangle>(type<entvars_t>) == 276, "C layout of entvars_t: offsetof fixangle")
    static_assert(typeinfo offsetof<v_angle>(type<entvars_t>) == 280, "C layout of entvars_t: offsetof v_angle")
    static_assert(typeinfo offsetof<idealpitch>(type<entvars_t>) == 292, "C layout of entvars_t: offsetof idealpitch")
    static_assert(typeinfo offsetof<netname>(type<entvars_t>) == 296, "C layout of entvars_t: offsetof netname")
    static_assert(typeinfo offsetof<enemy>(type<entvars_t>) == 300, "C layout of entvars_t: offsetof enemy")
    static_assert(typeinfo offsetof<flags>(type<entvars_t>) == 304, "C layout of entvars_t: offsetof flags")
    static_assert(typeinfo offsetof<colormap>(type<entvars_t>) == 308, "C layout of entvars_t: offsetof colormap")
    static_assert(typeinfo offsetof<team>(type<entvars_t>) == 312, "C layout of entvars_t: offsetof team")
    static_assert(typeinfo offsetof<max_health>(type<entvars_t>) == 316, "C layout of entvars_t: offsetof max_health")
    static_assert(typeinfo offsetof<teleport_time>(type<entvars_t>) == 320, "C layout of entvars_t: offsetof teleport_time")
    static_assert(typeinfo offsetof<armortype>(type<entvars_t>) == 324, "C layout of entvars_t: offsetof armortype")
    static_assert(typeinfo offsetof<armorvalue>(type<entvars_t>) == 328, "C layout of entvars_t: offsetof armorvalue")
    static_assert(typeinfo offsetof<waterlevel>(type<entvars_t>) == 332, "C layout of entvars_t: offsetof waterlevel")
    static_assert(typeinfo offsetof<watertype>(type<entvars_t>) == 336, "C layout of entvars_t: offsetof watertype")
    static_assert(typeinfo offsetof<ideal_yaw>(type<entvars_t>) == 340, "C layout of entvars_t: offsetof ideal_yaw")
    static_assert(typeinfo offsetof<yaw_speed>(type<entvars_t>) == 344, "C layout of entvars_t: offsetof yaw_speed")
    static_assert(typeinfo offsetof<aiment>(type<entvars_t>) == 348, "C layout of entvars_t: offsetof aiment")
    static_assert(typeinfo offsetof<goalentity>(type<entvars_t>) == 352, "C layout of entvars_t: offsetof goalentity")
    static_assert(typeinfo offsetof<spawnflags>(type<entvars_t>) == 356, "C layout of entvars_t: offsetof spawnflags")
    static_assert(typeinfo offsetof<target>(type<entvars_t>) == 360, "C layout of entvars_t: offsetof target")
    static_assert(typeinfo offsetof<targetname>(type<entvars_t>) == 364, "C layout of entvars_t: offsetof targetname")
    static_assert(typeinfo offsetof<dmg_take>(type<entvars_t>) == 368, "C layout of entvars_t: offsetof dmg_take")
    static_assert(typeinfo offsetof<dmg_save>(type<entvars_t>) == 372, "C layout of entvars_t: offsetof dmg_save")
    static_assert(typeinfo offsetof<dmg_inflictor>(type<entvars_t>) == 376, "C layout of entvars_t: offsetof dmg_inflictor")
    static_assert(typeinfo offsetof<owner>(type<entvars_t>) == 380, "C layout of entvars_t: offsetof owner")
    static_assert(typeinfo offsetof<movedir>(type<entvars_t>) == 384, "C layout of entvars_t: offsetof movedir")
    static_assert(typeinfo offsetof<message>(type<entvars_t>) == 396, "C layout of entvars_t: offsetof message")
    static_assert(typeinfo offsetof<sounds>(type<entvars_t>) == 400, "C layout of entvars_t: offsetof sounds")
    static_assert(typeinfo offsetof<noise>(type<entvars_t>) == 404, "C layout of entvars_t: offsetof noise")
    static_assert(typeinfo offsetof<noise1>(type<entvars_t>) == 408, "C layout of entvars_t: offsetof noise1")
    static_assert(typeinfo offsetof<noise2>(type<entvars_t>) == 412, "C layout of entvars_t: offsetof noise2")
    static_assert(typeinfo offsetof<noise3>(type<entvars_t>) == 416, "C layout of entvars_t: offsetof noise3")
    static_assert(typeinfo sizeof(type<edict_s>) == 528, "C layout of edict_s: sizeof")
    static_assert(typeinfo alignof(type<edict_s>) == 8, "C layout of edict_s: alignof")
    static_assert(typeinfo offsetof<free>(type<edict_s>) == 0, "C layout of edict_s: offsetof free")
    static_assert(typeinfo offsetof<area>(type<edict_s>) == 8, "C layout of edict_s: offsetof area")
    static_assert(typeinfo offsetof<num_leafs>(type<edict_s>) == 24, "C layout of edict_s: offsetof num_leafs")
    static_assert(typeinfo offsetof<leafnums>(type<edict_s>) == 28, "C layout of edict_s: offsetof leafnums")
    static_assert(typeinfo offsetof<baseline>(type<edict_s>) == 60, "C layout of edict_s: offsetof baseline")
    static_assert(typeinfo offsetof<freetime>(type<edict_s>) == 104, "C layout of edict_s: offsetof freetime")
    static_assert(typeinfo offsetof<v>(type<edict_s>) == 108, "C layout of edict_s: offsetof v")
    static_assert(typeinfo sizeof(type<edict_t>) == 528, "C layout of edict_t: sizeof")
    static_assert(typeinfo alignof(type<edict_t>) == 8, "C layout of edict_t: alignof")
    static_assert(typeinfo offsetof<free>(type<edict_t>) == 0, "C layout of edict_t: offsetof free")
    static_assert(typeinfo offsetof<area>(type<edict_t>) == 8, "C layout of edict_t: offsetof area")
    static_assert(typeinfo offsetof<num_leafs>(type<edict_t>) == 24, "C layout of edict_t: offsetof num_leafs")
    static_assert(typeinfo offsetof<leafnums>(type<edict_t>) == 28, "C layout of edict_t: offsetof leafnums")
    static_assert(typeinfo offsetof<baseline>(type<edict_t>) == 60, "C layout of edict_t: offsetof baseline")
    static_assert(typeinfo offsetof<freetime>(type<edict_t>) == 104, "C layout of edict_t: offsetof freetime")
    static_assert(typeinfo offsetof<v>(type<edict_t>) == 108, "C layout of edict_t: offsetof v")
    static_assert(typeinfo sizeof(type<server_t>) == 17168, "C layout of server_t: sizeof")
    static_assert(typeinfo alignof(type<server_t>) == 8, "C layout of server_t: alignof")
    static_assert(typeinfo offsetof<active>(type<server_t>) == 0, "C layout of server_t: offsetof active")
    static_assert(typeinfo offsetof<paused>(type<server_t>) == 4, "C layout of server_t: offsetof paused")
    static_assert(typeinfo offsetof<loadgame>(type<server_t>) == 8, "C layout of server_t: offsetof loadgame")
    static_assert(typeinfo offsetof<time>(type<server_t>) == 16, "C layout of server_t: offsetof time")
    static_assert(typeinfo offsetof<lastcheck>(type<server_t>) == 24, "C layout of server_t: offsetof lastcheck")
    static_assert(typeinfo offsetof<lastchecktime>(type<server_t>) == 32, "C layout of server_t: offsetof lastchecktime")
    static_assert(typeinfo offsetof<name>(type<server_t>) == 40, "C layout of server_t: offsetof name")
    static_assert(typeinfo offsetof<modelname>(type<server_t>) == 104, "C layout of server_t: offsetof modelname")
    static_assert(typeinfo offsetof<worldmodel>(type<server_t>) == 168, "C layout of server_t: offsetof worldmodel")
    static_assert(typeinfo offsetof<model_precache>(type<server_t>) == 176, "C layout of server_t: offsetof model_precache")
    static_assert(typeinfo offsetof<models>(type<server_t>) == 2224, "C layout of server_t: offsetof models")
    static_assert(typeinfo offsetof<sound_precache>(type<server_t>) == 4272, "C layout of server_t: offsetof sound_precache")
    static_assert(typeinfo offsetof<lightstyles>(type<server_t>) == 6320, "C layout of server_t: offsetof lightstyles")
    static_assert(typeinfo offsetof<num_edicts>(type<server_t>) == 6832, "C layout of server_t: offsetof num_edicts")
    static_assert(typeinfo offsetof<max_edicts>(type<server_t>) == 6836, "C layout of server_t: offsetof max_edicts")
    static_assert(typeinfo offsetof<edicts>(type<server_t>) == 6840, "C layout of server_t: offsetof edicts")
    static_assert(typeinfo offsetof<state>(type<server_t>) == 6848, "C layout of server_t: offsetof state")
    static_assert(typeinfo offsetof<datagram>(type<server_t>) == 6856, "C layout of server_t: offsetof datagram")
    static_assert(typeinfo offsetof<datagram_buf>(type<server_t>) == 6880, "C layout of server_t: offsetof datagram_buf")
    static_assert(typeinfo offsetof<reliable_datagram>(type<server_t>) == 7904, "C layout of server_t: offsetof reliable_datagram")
    static_assert(typeinfo offsetof<reliable_datagram_buf>(type<server_t>) == 7928, "C layout of server_t: offsetof reliable_datagram_buf")
    static_assert(typeinfo offsetof<signon>(type<server_t>) == 8952, "C layout of server_t: offsetof signon")
    static_assert(typeinfo offsetof<signon_buf>(type<server_t>) == 8976, "C layout of server_t: offsetof signon_buf")
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
