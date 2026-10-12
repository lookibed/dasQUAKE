var private c2da_str_r_sprite_0 : array<int8> = [int8(82), int8(95), int8(68), int8(114), int8(97), int8(119), int8(83), int8(112), int8(114), int8(105), int8(116), int8(101), int8(58), int8(32), int8(66), int8(97), int8(100), int8(32), int8(115), int8(112), int8(114), int8(105), int8(116), int8(101), int8(32), int8(116), int8(121), int8(112), int8(101), int8(32), int8(37), int8(100), int8(0)]

var private c2da_str_r_sprite_1 : array<int8> = [int8(82), int8(95), int8(83), int8(101), int8(116), int8(117), int8(112), int8(65), int8(110), int8(100), int8(68), int8(114), int8(97), int8(119), int8(83), int8(112), int8(114), int8(105), int8(116), int8(101), int8(58), int8(32), int8(116), int8(111), int8(111), int8(32), int8(109), int8(97), int8(110), int8(121), int8(32), int8(112), int8(111), int8(105), int8(110), int8(116), int8(115), int8(0)]

var private c2da_str_r_sprite_2 : array<int8> = [int8(82), int8(95), int8(68), int8(114), int8(97), int8(119), int8(83), int8(112), int8(114), int8(105), int8(116), int8(101), int8(58), int8(32), int8(110), int8(111), int8(32), int8(115), int8(117), int8(99), int8(104), int8(32), int8(102), int8(114), int8(97), int8(109), int8(101), int8(32), int8(37), int8(100), int8(10), int8(0)]

var r_spritedesc : spritedesc_t = default<spritedesc_t>

[export, sideeffects]
def R_DrawSprite() {
    var i : int
    var psprite : msprite_t?
    var tvec : vec3_t
    var dot : float
    var angle : float
    var sr : float
    var cr : float
    psprite = unsafe(reinterpret<msprite_t?>(unsafe(reinterpret<msprite_t?>(currententity.model.cache.data))))
    r_spritedesc.pspriteframe = unsafe(reinterpret<mspriteframe_s?>(unsafe(reinterpret<mspriteframe_s?>(R_GetSpriteframe(psprite)))))
    sprite_width = int(r_spritedesc.pspriteframe.width)  // nolint:PERF020
    sprite_height_0 = int(r_spritedesc.pspriteframe.height)  // nolint:PERF020
    if (psprite.type_0 == 1) {
        unsafe(unsafe(addr(tvec[0]))[0]) = -unsafe(unsafe(addr(modelorg[0]))[0])
        unsafe(unsafe(addr(tvec[0]))[1]) = -unsafe(unsafe(addr(modelorg[0]))[1])
        unsafe(unsafe(addr(tvec[0]))[2]) = -unsafe(unsafe(addr(modelorg[0]))[2])
        VectorNormalize(unsafe(addr<float?>(tvec[0])))
        dot = unsafe(unsafe(addr(tvec[0]))[2])
        if (double(dot) > 0.999848lf || double(dot) < -0.999848lf) {
            return
        }
        unsafe(unsafe(addr(r_spritedesc.vup[0]))[0]) = 0.0
        unsafe(unsafe(addr(r_spritedesc.vup[0]))[1]) = 0.0
        unsafe(unsafe(addr(r_spritedesc.vup[0]))[2]) = 1.0
        unsafe(unsafe(addr(r_spritedesc.vright[0]))[0]) = float(unsafe(unsafe(addr(tvec[0]))[1]))  // nolint:PERF020
        unsafe(unsafe(addr(r_spritedesc.vright[0]))[1]) = -unsafe(unsafe(addr(tvec[0]))[0])
        unsafe(unsafe(addr(r_spritedesc.vright[0]))[2]) = 0.0
        VectorNormalize(unsafe(addr<float?>(r_spritedesc.vright[0])))
        unsafe(unsafe(addr(r_spritedesc.vpn[0]))[0]) = -unsafe(unsafe(addr(r_spritedesc.vright[0]))[1])
        unsafe(unsafe(addr(r_spritedesc.vpn[0]))[1]) = float(unsafe(unsafe(addr(r_spritedesc.vright[0]))[0]))  // nolint:PERF020
        unsafe(unsafe(addr(r_spritedesc.vpn[0]))[2]) = 0.0
    } elif (psprite.type_0 == 2) {
        i = 0
        for (c2da_i in range(i, 3)) {
            unsafe(unsafe(addr(r_spritedesc.vup[0]))[c2da_i]) = unsafe(unsafe(addr(vup[0]))[c2da_i])
            unsafe(unsafe(addr(r_spritedesc.vright[0]))[c2da_i]) = unsafe(unsafe(addr(vright[0]))[c2da_i])
            unsafe(unsafe(addr(r_spritedesc.vpn[0]))[c2da_i]) = unsafe(unsafe(addr(vpn[0]))[c2da_i])
        }
    } elif (psprite.type_0 == 0) {
        dot = unsafe(unsafe(addr(vpn[0]))[2])
        if (double(dot) > 0.999848lf || double(dot) < -0.999848lf) {
            return
        }
        unsafe(unsafe(addr(r_spritedesc.vup[0]))[0]) = 0.0
        unsafe(unsafe(addr(r_spritedesc.vup[0]))[1]) = 0.0
        unsafe(unsafe(addr(r_spritedesc.vup[0]))[2]) = 1.0
        unsafe(unsafe(addr(r_spritedesc.vright[0]))[0]) = unsafe(unsafe(addr(vpn[0]))[1])
        unsafe(unsafe(addr(r_spritedesc.vright[0]))[1]) = -unsafe(unsafe(addr(vpn[0]))[0])
        unsafe(unsafe(addr(r_spritedesc.vright[0]))[2]) = 0.0
        VectorNormalize(unsafe(addr<float?>(r_spritedesc.vright[0])))
        unsafe(unsafe(addr(r_spritedesc.vpn[0]))[0]) = -unsafe(unsafe(addr(r_spritedesc.vright[0]))[1])
        unsafe(unsafe(addr(r_spritedesc.vpn[0]))[1]) = float(unsafe(unsafe(addr(r_spritedesc.vright[0]))[0]))  // nolint:PERF020
        unsafe(unsafe(addr(r_spritedesc.vpn[0]))[2]) = 0.0
    } elif (psprite.type_0 == 3) {
        var c2da_fresh0 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(currententity)) + 124ul))
        AngleVectors(unsafe(reinterpret<float?>(c2da_fresh0)), unsafe(addr<float?>(r_spritedesc.vpn[0])), unsafe(addr<float?>(r_spritedesc.vright[0])), unsafe(addr<float?>(r_spritedesc.vup[0])))
    } elif (psprite.type_0 == 4) {
        var c2da_fresh1 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(currententity)) + 124ul))
        angle = float(double(unsafe(unsafe(reinterpret<float?>(c2da_fresh1))[2])) * (3.141592653589793lf * 2.0lf / 360.0lf))
        sr = float(sin(double(angle)))
        cr = float(cos(double(angle)))
        i = 0
        for (c2da_i_0 in range(i, 3)) {
            unsafe(unsafe(addr(r_spritedesc.vpn[0]))[c2da_i_0]) = unsafe(unsafe(addr(vpn[0]))[c2da_i_0])
            unsafe(unsafe(addr(r_spritedesc.vright[0]))[c2da_i_0]) = unsafe(unsafe(addr(vright[0]))[c2da_i_0]) * cr + unsafe(unsafe(addr(vup[0]))[c2da_i_0]) * sr
            unsafe(unsafe(addr(r_spritedesc.vup[0]))[c2da_i_0]) = unsafe(unsafe(addr(vright[0]))[c2da_i_0]) * -sr + unsafe(unsafe(addr(vup[0]))[c2da_i_0]) * cr
        }
    } else {
        Sys_Error(unsafe(addr<int8?>(c2da_str_r_sprite_0[0])), [C2daVaArg(tag = 1, i64 = int64(psprite.type_0), f64 = 0.0lf, raw = 0x0)])
    }
    R_RotateSprite(psprite.beamlength)
    R_SetupAndDrawSprite()
    return
}
[export, sideeffects]
def R_SetupAndDrawSprite() {
    var i_0 : int
    var nump : int
    var pv : float?
    var pverts : vec5_t?
    var left : vec3_t
    var up_0 : vec3_t
    var right_0 : vec3_t
    var down : vec3_t
    var transformed : vec3_t
    var local : vec3_t
    var outverts : emitpoint_t[21]
    var pout : emitpoint_t?
    if (unsafe(unsafe(addr(r_spritedesc.vpn[0]))[0]) * unsafe(unsafe(addr(modelorg[0]))[0]) + unsafe(unsafe(addr(r_spritedesc.vpn[0]))[1]) * unsafe(unsafe(addr(modelorg[0]))[1]) + unsafe(unsafe(addr(r_spritedesc.vpn[0]))[2]) * unsafe(unsafe(addr(modelorg[0]))[2]) >= 0.0) {
        return
    }
    VectorScale(unsafe(addr<float?>(r_spritedesc.vright[0])), r_spritedesc.pspriteframe.right, unsafe(addr<float?>(right_0[0])))
    VectorScale(unsafe(addr<float?>(r_spritedesc.vup[0])), r_spritedesc.pspriteframe.up, unsafe(addr<float?>(up_0[0])))
    VectorScale(unsafe(addr<float?>(r_spritedesc.vright[0])), r_spritedesc.pspriteframe.left, unsafe(addr<float?>(left[0])))
    VectorScale(unsafe(addr<float?>(r_spritedesc.vup[0])), r_spritedesc.pspriteframe.down, unsafe(addr<float?>(down[0])))
    pverts = unsafe(addr<vec5_t?>(clip_verts[0][0]))
    unsafe(unsafe(addr(unsafe(pverts[0])[0]))[0]) = unsafe(unsafe(addr(r_entorigin[0]))[0]) + unsafe(unsafe(addr(up_0[0]))[0]) + unsafe(unsafe(addr(left[0]))[0])
    unsafe(unsafe(addr(unsafe(pverts[0])[0]))[1]) = unsafe(unsafe(addr(r_entorigin[0]))[1]) + unsafe(unsafe(addr(up_0[0]))[1]) + unsafe(unsafe(addr(left[0]))[1])
    unsafe(unsafe(addr(unsafe(pverts[0])[0]))[2]) = unsafe(unsafe(addr(r_entorigin[0]))[2]) + unsafe(unsafe(addr(up_0[0]))[2]) + unsafe(unsafe(addr(left[0]))[2])
    unsafe(unsafe(addr(unsafe(pverts[0])[0]))[3]) = 0.0
    unsafe(unsafe(addr(unsafe(pverts[0])[0]))[4]) = 0.0
    unsafe(unsafe(addr(unsafe(pverts[1])[0]))[0]) = unsafe(unsafe(addr(r_entorigin[0]))[0]) + unsafe(unsafe(addr(up_0[0]))[0]) + unsafe(unsafe(addr(right_0[0]))[0])
    unsafe(unsafe(addr(unsafe(pverts[1])[0]))[1]) = unsafe(unsafe(addr(r_entorigin[0]))[1]) + unsafe(unsafe(addr(up_0[0]))[1]) + unsafe(unsafe(addr(right_0[0]))[1])
    unsafe(unsafe(addr(unsafe(pverts[1])[0]))[2]) = unsafe(unsafe(addr(r_entorigin[0]))[2]) + unsafe(unsafe(addr(up_0[0]))[2]) + unsafe(unsafe(addr(right_0[0]))[2])
    unsafe(unsafe(addr(unsafe(pverts[1])[0]))[3]) = float(sprite_width)
    unsafe(unsafe(addr(unsafe(pverts[1])[0]))[4]) = 0.0
    unsafe(unsafe(addr(unsafe(pverts[2])[0]))[0]) = unsafe(unsafe(addr(r_entorigin[0]))[0]) + unsafe(unsafe(addr(down[0]))[0]) + unsafe(unsafe(addr(right_0[0]))[0])
    unsafe(unsafe(addr(unsafe(pverts[2])[0]))[1]) = unsafe(unsafe(addr(r_entorigin[0]))[1]) + unsafe(unsafe(addr(down[0]))[1]) + unsafe(unsafe(addr(right_0[0]))[1])
    unsafe(unsafe(addr(unsafe(pverts[2])[0]))[2]) = unsafe(unsafe(addr(r_entorigin[0]))[2]) + unsafe(unsafe(addr(down[0]))[2]) + unsafe(unsafe(addr(right_0[0]))[2])
    unsafe(unsafe(addr(unsafe(pverts[2])[0]))[3]) = float(sprite_width)
    unsafe(unsafe(addr(unsafe(pverts[2])[0]))[4]) = float(sprite_height_0)
    unsafe(unsafe(addr(unsafe(pverts[3])[0]))[0]) = unsafe(unsafe(addr(r_entorigin[0]))[0]) + unsafe(unsafe(addr(down[0]))[0]) + unsafe(unsafe(addr(left[0]))[0])
    unsafe(unsafe(addr(unsafe(pverts[3])[0]))[1]) = unsafe(unsafe(addr(r_entorigin[0]))[1]) + unsafe(unsafe(addr(down[0]))[1]) + unsafe(unsafe(addr(left[0]))[1])
    unsafe(unsafe(addr(unsafe(pverts[3])[0]))[2]) = unsafe(unsafe(addr(r_entorigin[0]))[2]) + unsafe(unsafe(addr(down[0]))[2]) + unsafe(unsafe(addr(left[0]))[2])
    unsafe(unsafe(addr(unsafe(pverts[3])[0]))[3]) = 0.0
    unsafe(unsafe(addr(unsafe(pverts[3])[0]))[4]) = float(sprite_height_0)
    nump = 4
    clip_current = 0
    i_0 = 0
    while (i_0 < 4) {
        nump = R_ClipSpriteFace(nump, unsafe(addr<clipplane_s?>(unsafe(unsafe(addr(view_clipplanes[0]))[i_0]))))
        if (nump < 3) {
            return
        }
        if (nump >= 16 + 4) {
            Sys_Error(unsafe(addr<int8?>(c2da_str_r_sprite_1[0])), [])
        }
        i_0++
    }
    pv = unsafe(addr<float?>(unsafe(unsafe(addr(clip_verts[clip_current][0][0]))[0])))
    r_spritedesc.nearzi = -999999.0
    i_0 = 0
    for (c2da_i_0_0 in range(i_0, nump)) {
        unsafe(unsafe(addr(local[0]))[0]) = unsafe(pv[0]) - unsafe(unsafe(addr(r_origin[0]))[0])
        unsafe(unsafe(addr(local[0]))[1]) = unsafe(pv[1]) - unsafe(unsafe(addr(r_origin[0]))[1])
        unsafe(unsafe(addr(local[0]))[2]) = unsafe(pv[2]) - unsafe(unsafe(addr(r_origin[0]))[2])
        TransformVector(unsafe(addr<float?>(local[0])), unsafe(addr<float?>(transformed[0])))
        if (double(unsafe(unsafe(addr(transformed[0]))[2])) < 0.01lf) {
            unsafe(unsafe(addr(transformed[0]))[2]) = float(0.01lf)
        }
        pout = unsafe(addr<emitpoint_t?>(unsafe(unsafe(addr(outverts[0]))[c2da_i_0_0])))
        pout.zi = float(1.0lf / double(unsafe(unsafe(addr(transformed[0]))[2])))
        if (pout.zi > r_spritedesc.nearzi) {
            r_spritedesc.nearzi = float(pout.zi)  // nolint:PERF020
        }
        pout.s = float(unsafe(pv[3]))  // nolint:PERF020
        pout.t = float(unsafe(pv[4]))  // nolint:PERF020
        pout.u = xcenter + xscale * pout.zi * unsafe(unsafe(addr(transformed[0]))[0])
        pout.v = ycenter - yscale * pout.zi * unsafe(unsafe(addr(transformed[0]))[1])
        unsafe {  // nolint:STYLE025
            pv += int64(20ul / 4ul)
        }
    }
    r_spritedesc.nump = nump
    r_spritedesc.pverts = unsafe(addr<emitpoint_t?>(outverts[0]))
    D_DrawSprite()
    return
}
var private clip_current : int = default<int>

var private clip_verts : vec5_t[2][20]

[export, sideeffects]
def R_ClipSpriteFace(var nump_0 : int; var pclipplane : clipplane_s?) : int {
    var i_1 : int
    var outcount : int
    var dists : float[21]
    var frac : float
    var clipdist : float
    var pclipnormal : float?
    var in_0 : float?
    var instep : float?
    var outstep : float?
    var vert2 : float?
    clipdist = pclipplane.dist
    var c2da_fresh2 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pclipplane))))
    pclipnormal = unsafe(reinterpret<float?>(c2da_fresh2))
    if (clip_current != 0) {
        in_0 = unsafe(addr<float?>(clip_verts[1][0][0]))
        outstep = unsafe(addr<float?>(clip_verts[0][0][0]))
        clip_current = 0
    } else {
        in_0 = unsafe(addr<float?>(clip_verts[0][0][0]))
        outstep = unsafe(addr<float?>(clip_verts[1][0][0]))
        clip_current = 1
    }
    instep = unsafe(reinterpret<float?>(in_0))
    i_1 = 0
    while (i_1 < nump_0) {
        dists[i_1] = unsafe(instep[0]) * unsafe(pclipnormal[0]) + unsafe(instep[1]) * unsafe(pclipnormal[1]) + unsafe(instep[2]) * unsafe(pclipnormal[2]) - clipdist
        i_1++
        unsafe {  // nolint:STYLE025
            instep += int64(20ul / 4ul)
        }
    }
    dists[nump_0] = float(dists[0])  // nolint:PERF020
    Q_memcpy(unsafe(reinterpret<uint8?>(instep)), unsafe(reinterpret<uint8?>(in_0)), 20)
    instep = unsafe(reinterpret<float?>(in_0))
    outcount = 0
    i_1 = 0
    while (i_1 < nump_0) {
        if (dists[i_1] >= 0.0) {
            Q_memcpy(unsafe(reinterpret<uint8?>(outstep)), unsafe(reinterpret<uint8?>(instep)), 20)
            unsafe {  // nolint:STYLE025
                outstep += int64(20ul / 4ul)
            }
            outcount++
        }
        if (dists[i_1] == 0.0 || dists[i_1 + 1] == 0.0) {
            i_1++
            unsafe {  // nolint:STYLE025
                instep += int64(20ul / 4ul)
            }
            continue
        }
        if ((dists[i_1] > 0.0 ? 1 : 0) == (dists[i_1 + 1] > 0.0 ? 1 : 0)) {
            i_1++
            unsafe {  // nolint:STYLE025
                instep += int64(20ul / 4ul)
            }
            continue
        }
        frac = dists[i_1] / (dists[i_1] - dists[i_1 + 1])
        vert2 = unsafe(reinterpret<float?>(unsafe(instep + int64(20ul / 4ul))))
        unsafe(outstep[0]) = unsafe(instep[0]) + frac * (unsafe(vert2[0]) - unsafe(instep[0]))
        unsafe(outstep[1]) = unsafe(instep[1]) + frac * (unsafe(vert2[1]) - unsafe(instep[1]))
        unsafe(outstep[2]) = unsafe(instep[2]) + frac * (unsafe(vert2[2]) - unsafe(instep[2]))
        unsafe(outstep[3]) = unsafe(instep[3]) + frac * (unsafe(vert2[3]) - unsafe(instep[3]))
        unsafe(outstep[4]) = unsafe(instep[4]) + frac * (unsafe(vert2[4]) - unsafe(instep[4]))
        unsafe {  // nolint:STYLE025
            outstep += int64(20ul / 4ul)
        }
        outcount++
        i_1++
        unsafe {  // nolint:STYLE025
            instep += int64(20ul / 4ul)
        }
    }
    return outcount
}
var private sprite_height_0 : int = default<int>

var private sprite_width : int = default<int>

[export, sideeffects]
def R_RotateSprite(var beamlength_0 : float) {
    var vec : vec3_t
    if (double(beamlength_0) == 0.0lf) {
        return
    }
    VectorScale(unsafe(addr<float?>(r_spritedesc.vpn[0])), -beamlength_0, unsafe(addr<float?>(vec[0])))
    unsafe(unsafe(addr(r_entorigin[0]))[0]) = unsafe(unsafe(addr(r_entorigin[0]))[0]) + unsafe(unsafe(addr(vec[0]))[0])
    unsafe(unsafe(addr(r_entorigin[0]))[1]) = unsafe(unsafe(addr(r_entorigin[0]))[1]) + unsafe(unsafe(addr(vec[0]))[1])
    unsafe(unsafe(addr(r_entorigin[0]))[2]) = unsafe(unsafe(addr(r_entorigin[0]))[2]) + unsafe(unsafe(addr(vec[0]))[2])
    unsafe(unsafe(addr(modelorg[0]))[0]) = unsafe(unsafe(addr(modelorg[0]))[0]) - unsafe(unsafe(addr(vec[0]))[0])
    unsafe(unsafe(addr(modelorg[0]))[1]) = unsafe(unsafe(addr(modelorg[0]))[1]) - unsafe(unsafe(addr(vec[0]))[1])
    unsafe(unsafe(addr(modelorg[0]))[2]) = unsafe(unsafe(addr(modelorg[0]))[2]) - unsafe(unsafe(addr(vec[0]))[2])
    return
}
[export, sideeffects]
def R_GetSpriteframe(var psprite_0 : msprite_t?) : mspriteframe_s? {
    var pspritegroup : mspritegroup_t?
    var pspriteframe : mspriteframe_s?
    var i_2 : int
    var numframes : int
    var frame : int
    var pintervals : float?
    var fullinterval : float
    var targettime : float
    var time : float
    frame = currententity.frame
    if (frame >= psprite_0.numframes || frame < 0) {
        Con_Printf(unsafe(addr<int8?>(c2da_str_r_sprite_2[0])), [C2daVaArg(tag = 1, i64 = int64(frame), f64 = 0.0lf, raw = 0x0)])
        frame = 0
    }
    var c2da_fresh3 : mspriteframedesc_t? = unsafe(reinterpret<mspriteframedesc_t?>(unsafe(reinterpret<uint64>(psprite_0)) + 32ul))
    if (uint(unsafe(unsafe(reinterpret<mspriteframedesc_t?>(c2da_fresh3))[frame]).type_0) == 0u) {
        var c2da_fresh4 : mspriteframedesc_t? = unsafe(reinterpret<mspriteframedesc_t?>(unsafe(reinterpret<uint64>(psprite_0)) + 32ul))
        pspriteframe = unsafe(reinterpret<mspriteframe_s?>(unsafe(unsafe(reinterpret<mspriteframedesc_t?>(c2da_fresh4))[frame]).frameptr))
    } else {
        var c2da_fresh5 : mspriteframedesc_t? = unsafe(reinterpret<mspriteframedesc_t?>(unsafe(reinterpret<uint64>(psprite_0)) + 32ul))
        pspritegroup = unsafe(reinterpret<mspritegroup_t?>(unsafe(reinterpret<mspritegroup_t?>(unsafe(unsafe(reinterpret<mspriteframedesc_t?>(c2da_fresh5))[frame]).frameptr))))
        pintervals = unsafe(reinterpret<float?>(pspritegroup.intervals))
        numframes = pspritegroup.numframes
        fullinterval = unsafe(pintervals[numframes - 1])
        time = float(cl.time + double(currententity.syncbase))
        targettime = time - float(int(time / fullinterval)) * fullinterval
        i_2 = 0
        while (i_2 < numframes - 1) {
            if (unsafe(pintervals[i_2]) > targettime) {
                break
            }
            i_2++
        }
        var c2da_fresh6 : mspriteframe_s?? = unsafe(reinterpret<mspriteframe_s??>(unsafe(reinterpret<uint64>(pspritegroup)) + 16ul))
        pspriteframe = unsafe(reinterpret<mspriteframe_s?>(unsafe(unsafe(reinterpret<mspriteframe_s??>(c2da_fresh6))[i_2])))
    }
    return unsafe(reinterpret<mspriteframe_s?>(pspriteframe))
}
[sideeffects]
def private c2da_layout_proofs_43() {
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
    static_assert(typeinfo sizeof(type<mspriteframe_s>) == 40, "C layout of mspriteframe_s: sizeof")
    static_assert(typeinfo alignof(type<mspriteframe_s>) == 8, "C layout of mspriteframe_s: alignof")
    static_assert(typeinfo offsetof<width>(type<mspriteframe_s>) == 0, "C layout of mspriteframe_s: offsetof width")
    static_assert(typeinfo offsetof<height>(type<mspriteframe_s>) == 4, "C layout of mspriteframe_s: offsetof height")
    static_assert(typeinfo offsetof<pcachespot>(type<mspriteframe_s>) == 8, "C layout of mspriteframe_s: offsetof pcachespot")
    static_assert(typeinfo offsetof<up>(type<mspriteframe_s>) == 16, "C layout of mspriteframe_s: offsetof up")
    static_assert(typeinfo offsetof<down>(type<mspriteframe_s>) == 20, "C layout of mspriteframe_s: offsetof down")
    static_assert(typeinfo offsetof<left>(type<mspriteframe_s>) == 24, "C layout of mspriteframe_s: offsetof left")
    static_assert(typeinfo offsetof<right>(type<mspriteframe_s>) == 28, "C layout of mspriteframe_s: offsetof right")
    static_assert(typeinfo offsetof<pixels>(type<mspriteframe_s>) == 32, "C layout of mspriteframe_s: offsetof pixels")
    static_assert(typeinfo sizeof(type<mspriteframe_t>) == 40, "C layout of mspriteframe_t: sizeof")
    static_assert(typeinfo alignof(type<mspriteframe_t>) == 8, "C layout of mspriteframe_t: alignof")
    static_assert(typeinfo offsetof<width>(type<mspriteframe_t>) == 0, "C layout of mspriteframe_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<mspriteframe_t>) == 4, "C layout of mspriteframe_t: offsetof height")
    static_assert(typeinfo offsetof<pcachespot>(type<mspriteframe_t>) == 8, "C layout of mspriteframe_t: offsetof pcachespot")
    static_assert(typeinfo offsetof<up>(type<mspriteframe_t>) == 16, "C layout of mspriteframe_t: offsetof up")
    static_assert(typeinfo offsetof<down>(type<mspriteframe_t>) == 20, "C layout of mspriteframe_t: offsetof down")
    static_assert(typeinfo offsetof<left>(type<mspriteframe_t>) == 24, "C layout of mspriteframe_t: offsetof left")
    static_assert(typeinfo offsetof<right>(type<mspriteframe_t>) == 28, "C layout of mspriteframe_t: offsetof right")
    static_assert(typeinfo offsetof<pixels>(type<mspriteframe_t>) == 32, "C layout of mspriteframe_t: offsetof pixels")
    static_assert(typeinfo sizeof(type<mspritegroup_t>) == 24, "C layout of mspritegroup_t: sizeof")
    static_assert(typeinfo alignof(type<mspritegroup_t>) == 8, "C layout of mspritegroup_t: alignof")
    static_assert(typeinfo offsetof<numframes>(type<mspritegroup_t>) == 0, "C layout of mspritegroup_t: offsetof numframes")
    static_assert(typeinfo offsetof<intervals>(type<mspritegroup_t>) == 8, "C layout of mspritegroup_t: offsetof intervals")
    static_assert(typeinfo offsetof<frames>(type<mspritegroup_t>) == 16, "C layout of mspritegroup_t: offsetof frames")
    static_assert(typeinfo sizeof(type<mspriteframedesc_t>) == 16, "C layout of mspriteframedesc_t: sizeof")
    static_assert(typeinfo alignof(type<mspriteframedesc_t>) == 8, "C layout of mspriteframedesc_t: alignof")
    static_assert(typeinfo offsetof<type_0>(type<mspriteframedesc_t>) == 0, "C layout of mspriteframedesc_t: offsetof type_0")
    static_assert(typeinfo offsetof<frameptr>(type<mspriteframedesc_t>) == 8, "C layout of mspriteframedesc_t: offsetof frameptr")
    static_assert(typeinfo sizeof(type<msprite_t>) == 48, "C layout of msprite_t: sizeof")
    static_assert(typeinfo alignof(type<msprite_t>) == 8, "C layout of msprite_t: alignof")
    static_assert(typeinfo offsetof<type_0>(type<msprite_t>) == 0, "C layout of msprite_t: offsetof type_0")
    static_assert(typeinfo offsetof<maxwidth>(type<msprite_t>) == 4, "C layout of msprite_t: offsetof maxwidth")
    static_assert(typeinfo offsetof<maxheight>(type<msprite_t>) == 8, "C layout of msprite_t: offsetof maxheight")
    static_assert(typeinfo offsetof<numframes>(type<msprite_t>) == 12, "C layout of msprite_t: offsetof numframes")
    static_assert(typeinfo offsetof<beamlength>(type<msprite_t>) == 16, "C layout of msprite_t: offsetof beamlength")
    static_assert(typeinfo offsetof<cachespot>(type<msprite_t>) == 24, "C layout of msprite_t: offsetof cachespot")
    static_assert(typeinfo offsetof<frames>(type<msprite_t>) == 32, "C layout of msprite_t: offsetof frames")
    static_assert(typeinfo sizeof(type<emitpoint_t>) == 20, "C layout of emitpoint_t: sizeof")
    static_assert(typeinfo alignof(type<emitpoint_t>) == 4, "C layout of emitpoint_t: alignof")
    static_assert(typeinfo offsetof<u>(type<emitpoint_t>) == 0, "C layout of emitpoint_t: offsetof u")
    static_assert(typeinfo offsetof<v>(type<emitpoint_t>) == 4, "C layout of emitpoint_t: offsetof v")
    static_assert(typeinfo offsetof<s>(type<emitpoint_t>) == 8, "C layout of emitpoint_t: offsetof s")
    static_assert(typeinfo offsetof<t>(type<emitpoint_t>) == 12, "C layout of emitpoint_t: offsetof t")
    static_assert(typeinfo offsetof<zi>(type<emitpoint_t>) == 16, "C layout of emitpoint_t: offsetof zi")
    static_assert(typeinfo sizeof(type<spritedesc_t>) == 64, "C layout of spritedesc_t: sizeof")
    static_assert(typeinfo alignof(type<spritedesc_t>) == 8, "C layout of spritedesc_t: alignof")
    static_assert(typeinfo offsetof<nump>(type<spritedesc_t>) == 0, "C layout of spritedesc_t: offsetof nump")
    static_assert(typeinfo offsetof<pverts>(type<spritedesc_t>) == 8, "C layout of spritedesc_t: offsetof pverts")
    static_assert(typeinfo offsetof<pspriteframe>(type<spritedesc_t>) == 16, "C layout of spritedesc_t: offsetof pspriteframe")
    static_assert(typeinfo offsetof<vup>(type<spritedesc_t>) == 24, "C layout of spritedesc_t: offsetof vup")
    static_assert(typeinfo offsetof<vright>(type<spritedesc_t>) == 36, "C layout of spritedesc_t: offsetof vright")
    static_assert(typeinfo offsetof<vpn>(type<spritedesc_t>) == 48, "C layout of spritedesc_t: offsetof vpn")
    static_assert(typeinfo offsetof<nearzi>(type<spritedesc_t>) == 60, "C layout of spritedesc_t: offsetof nearzi")
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
