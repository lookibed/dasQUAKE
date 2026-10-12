[export, sideeffects]
def D_DrawSprite() {
    var i : int
    var ymin : float
    var ymax : float
    var pverts : emitpoint_t?
    var spans : sspan_s[1025]
    sprite_spans = unsafe(addr<sspan_s?>(spans[0]))
    ymin = float(999999.9lf)
    ymax = float(-999999.9lf)
    pverts = unsafe(reinterpret<emitpoint_t?>(r_spritedesc.pverts))
    var c2da_pverts_addr : uint64 = unsafe(reinterpret<uint64>(pverts))
    i = 0
    while (i < r_spritedesc.nump) {
        if (unsafe(reinterpret<emitpoint_t?>(c2da_pverts_addr)).v < ymin) {
            ymin = unsafe(reinterpret<emitpoint_t?>(c2da_pverts_addr)).v
            minindex = i
        }
        if (unsafe(reinterpret<emitpoint_t?>(c2da_pverts_addr)).v > ymax) {
            ymax = unsafe(reinterpret<emitpoint_t?>(c2da_pverts_addr)).v
            maxindex = i
        }
        c2da_pverts_addr += 20ul
        i++
    }
    ymin = float(ceil(double(ymin)))
    ymax = float(ceil(double(ymax)))
    if (ymin >= ymax) {
        return
    }
    cachewidth = r_spritedesc.pspriteframe.width
    sprite_height = r_spritedesc.pspriteframe.height
    var c2da_fresh0 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(r_spritedesc.pspriteframe)) + 32ul))
    cacheblock = unsafe(addr<uint8?>(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh0))[0])))
    pverts = unsafe(reinterpret<emitpoint_t?>(r_spritedesc.pverts))
    unsafe(pverts[int(r_spritedesc.nump)]) = unsafe(pverts[0])
    D_SpriteCalculateGradients()
    D_SpriteScanLeftEdge()
    D_SpriteScanRightEdge()
    D_SpriteDrawSpans(sprite_spans)
    return
}
var private sprite_spans : sspan_s? = default<sspan_s?>

[export, sideeffects]
def D_SpriteDrawSpans(var pspan : sspan_s?) {
    var count : int
    var spancount : int
    var izistep : int
    var izi : int
    var pbase : uint8?
    var pdest : uint8?
    var s : int
    var t : int
    var snext : int
    var tnext : int
    var sstep : int
    var tstep : int
    var sdivz : float
    var tdivz : float
    var zi : float
    var z : float
    var du : float
    var dv : float
    var spancountminus1 : float
    var sdivz8stepu : float
    var tdivz8stepu : float
    var zi8stepu : float
    var btemp : uint8
    var pz : int16?
    sstep = 0
    tstep = 0
    pbase = unsafe(reinterpret<uint8?>(cacheblock))
    sdivz8stepu = d_sdivzstepu * 8.0
    tdivz8stepu = d_tdivzstepu * 8.0
    zi8stepu = d_zistepu * 8.0
    izistep = int(d_zistepu * 32768.0 * 65536.0)
    label 0:
    pdest = unsafe(reinterpret<uint8?>(unsafe(unsafe(d_viewbuffer + int64(screenwidth * pspan.v)) + pspan.u)))
    pz = unsafe(reinterpret<int16?>(unsafe(unsafe(d_pzbuffer + int64(d_zwidth * uint(pspan.v))) + pspan.u)))
    count = pspan.count
    if (count <= 0) {
        goto label 38
    }
    du = float(pspan.u)
    dv = float(pspan.v)
    sdivz = d_sdivzorigin + dv * d_sdivzstepv + du * d_sdivzstepu
    tdivz = d_tdivzorigin + dv * d_tdivzstepv + du * d_tdivzstepu
    zi = d_ziorigin + dv * d_zistepv + du * d_zistepu
    z = 65536.0 / zi
    izi = int(zi * 32768.0 * 65536.0)
    s = int(sdivz * z) + sadjust
    if (s > bbextents) {
        goto label 37
    }
    if (s < 0) {
        goto label 36
    }
    label 1:
    label 2:
    t = int(tdivz * z) + tadjust
    if (t > bbextentt) {
        goto label 35
    }
    if (t < 0) {
        goto label 34
    }
    label 3:
    label 4:
    label 5:
    if (count >= 8) {
        goto label 33
    }
    spancount = count
    label 6:
    count -= spancount
    if (count != 0) {
        goto label 24
    }
    spancountminus1 = float(spancount - 1)
    sdivz = sdivz + d_sdivzstepu * spancountminus1
    tdivz = tdivz + d_tdivzstepu * spancountminus1
    zi = zi + d_zistepu * spancountminus1
    z = 65536.0 / zi
    snext = int(sdivz * z) + sadjust
    if (snext > bbextents) {
        goto label 23
    }
    if (snext < 8) {
        goto label 22
    }
    label 7:
    label 8:
    tnext = int(tdivz * z) + tadjust
    if (tnext > bbextentt) {
        goto label 21
    }
    if (tnext < 8) {
        goto label 20
    }
    label 9:
    label 10:
    if (spancount > 1) {
        goto label 19
    }
    label 11:
    label 12:
    label 13:
    btemp = uint8(*unsafe(unsafe(pbase + int64(s >> 16)) + int64((t >> 16) * cachewidth)))
    if (int(btemp) != 255) {
        goto label 16
    }
    label 14:
    izi += izistep
    unsafe {  // nolint:STYLE025
        pdest += 1
    }
    unsafe {  // nolint:STYLE025
        pz += 1
    }
    s += sstep
    t += tstep
    spancount--
    if (spancount > 0) {
        goto label 13
    }
    s = snext
    t = tnext
    if (count > 0) {
        goto label 5
    }
    label 15:
    unsafe {  // nolint:STYLE025
        pspan += 1
    }
    if (pspan.count != -128) {
        goto label 0
    }
    return
    label 16:
    if (int(*pz) <= izi >> 16) {
        goto label 18
    }
    label 17:
    goto label 14
    label 18:
    *pz = int16(izi >> 16)
    *pdest = btemp
    goto label 17
    label 19:
    sstep = (snext - s) / (spancount - 1)
    tstep = (tnext - t) / (spancount - 1)
    goto label 11
    label 20:
    tnext = 8
    goto label 9
    label 21:
    tnext = bbextentt
    goto label 10
    label 22:
    snext = 8
    goto label 7
    label 23:
    snext = bbextents
    goto label 8
    label 24:
    sdivz += sdivz8stepu
    tdivz += tdivz8stepu
    zi += zi8stepu
    z = 65536.0 / zi
    snext = int(sdivz * z) + sadjust
    if (snext > bbextents) {
        goto label 32
    }
    if (snext < 8) {
        goto label 31
    }
    label 25:
    label 26:
    tnext = int(tdivz * z) + tadjust
    if (tnext > bbextentt) {
        goto label 30
    }
    if (tnext < 8) {
        goto label 29
    }
    label 27:
    label 28:
    sstep = snext - s >> 3
    tstep = tnext - t >> 3
    goto label 12
    label 29:
    tnext = 8
    goto label 27
    label 30:
    tnext = bbextentt
    goto label 28
    label 31:
    snext = 8
    goto label 25
    label 32:
    snext = bbextents
    goto label 26
    label 33:
    spancount = 8
    goto label 6
    label 34:
    t = 0
    goto label 3
    label 35:
    t = bbextentt
    goto label 4
    label 36:
    s = 0
    goto label 1
    label 37:
    s = bbextents
    goto label 2
    label 38:
    goto label 15
    panic("unreachable: fell out of a translated control-flow graph")
}
[export, sideeffects]
def D_SpriteScanRightEdge() {
    var i_0 : int
    var itop : int
    var ibottom : int
    var pvert : emitpoint_t?
    var pnext : emitpoint_t?
    var pspan_0 : sspan_s?
    var du_0 : float
    var dv_0 : float
    var vtop : float
    var vbottom : float
    var slope : float
    var uvert : float
    var unext : float
    var vvert : float
    var vnext : float
    var u : int
    var u_step : int
    pspan_0 = unsafe(reinterpret<sspan_s?>(sprite_spans))
    i_0 = minindex
    vvert = unsafe(r_spritedesc.pverts[i_0]).v
    if (vvert < r_refdef.fvrecty_adj) {
        vvert = r_refdef.fvrecty_adj
    }
    if (vvert > r_refdef.fvrectbottom_adj) {
        vvert = r_refdef.fvrectbottom_adj
    }
    vtop = float(ceil(double(vvert)))
    while (true) {
        pvert = unsafe(addr<emitpoint_t?>(unsafe(r_spritedesc.pverts[i_0])))
        pnext = unsafe(reinterpret<emitpoint_t?>(unsafe(pvert + 1)))
        vnext = pnext.v
        if (vnext < r_refdef.fvrecty_adj) {
            vnext = r_refdef.fvrecty_adj
        }
        if (vnext > r_refdef.fvrectbottom_adj) {
            vnext = r_refdef.fvrectbottom_adj
        }
        vbottom = float(ceil(double(vnext)))
        if (vtop < vbottom) {
            uvert = pvert.u
            if (uvert < r_refdef.fvrectx_adj) {
                uvert = r_refdef.fvrectx_adj
            }
            if (uvert > r_refdef.fvrectright_adj) {
                uvert = r_refdef.fvrectright_adj
            }
            unext = pnext.u
            if (unext < r_refdef.fvrectx_adj) {
                unext = r_refdef.fvrectx_adj
            }
            if (unext > r_refdef.fvrectright_adj) {
                unext = r_refdef.fvrectright_adj
            }
            du_0 = unext - uvert
            dv_0 = vnext - vvert
            slope = du_0 / dv_0
            u_step = int(slope * 65536.0)
            u = int((uvert + slope * (vtop - vvert)) * 65536.0) + (65536 - 1)
            itop = int(vtop)
            ibottom = int(vbottom)
            var c2da_pspan_0_addr : uint64 = unsafe(reinterpret<uint64>(pspan_0))
            for (v in range(itop, ibottom)) {
                unsafe(reinterpret<sspan_s?>(c2da_pspan_0_addr)).count = (u >> 16) - unsafe(reinterpret<sspan_s?>(c2da_pspan_0_addr)).u
                u += u_step
                c2da_pspan_0_addr += 12ul
            }
            pspan_0 = unsafe(reinterpret<sspan_s?>(c2da_pspan_0_addr))
        }
        vtop = vbottom
        vvert = vnext
        i_0++
        if (i_0 == r_spritedesc.nump) {
            i_0 = 0
        }
        if (i_0 == maxindex) {
            break
        }
    }
    pspan_0.count = -128
    return
}
var private maxindex : int = default<int>

var private minindex : int = default<int>

[export, sideeffects]
def D_SpriteScanLeftEdge() {
    var i_1 : int
    var itop_0 : int
    var ibottom_0 : int
    var lmaxindex : int
    var pvert_0 : emitpoint_t?
    var pnext_0 : emitpoint_t?
    var pspan_1 : sspan_s?
    var du_1 : float
    var dv_1 : float
    var vtop_0 : float
    var vbottom_0 : float
    var slope_0 : float
    var u_0 : int
    var u_step_0 : int
    pspan_1 = unsafe(reinterpret<sspan_s?>(sprite_spans))
    i_1 = minindex
    if (i_1 == 0) {
        i_1 = r_spritedesc.nump
    }
    lmaxindex = maxindex
    if (lmaxindex == 0) {
        lmaxindex = r_spritedesc.nump
    }
    vtop_0 = float(ceil(double(unsafe(r_spritedesc.pverts[i_1]).v)))
    while (true) {
        pvert_0 = unsafe(addr<emitpoint_t?>(unsafe(r_spritedesc.pverts[i_1])))
        pnext_0 = unsafe(reinterpret<emitpoint_t?>(unsafe(pvert_0 + -1)))
        vbottom_0 = float(ceil(double(pnext_0.v)))
        if (vtop_0 < vbottom_0) {
            du_1 = pnext_0.u - pvert_0.u
            dv_1 = pnext_0.v - pvert_0.v
            slope_0 = du_1 / dv_1
            u_step_0 = int(slope_0 * 65536.0)
            u_0 = int((pvert_0.u + slope_0 * (vtop_0 - pvert_0.v)) * 65536.0) + (65536 - 1)
            itop_0 = int(vtop_0)
            ibottom_0 = int(vbottom_0)
            var c2da_pspan_1_addr : uint64 = unsafe(reinterpret<uint64>(pspan_1))
            for (v_0 in range(itop_0, ibottom_0)) {
                unsafe(reinterpret<sspan_s?>(c2da_pspan_1_addr)).u = u_0 >> 16
                unsafe(reinterpret<sspan_s?>(c2da_pspan_1_addr)).v = v_0
                u_0 += u_step_0
                c2da_pspan_1_addr += 12ul
            }
            pspan_1 = unsafe(reinterpret<sspan_s?>(c2da_pspan_1_addr))
        }
        vtop_0 = vbottom_0
        i_1--
        if (i_1 == 0) {
            i_1 = r_spritedesc.nump
        }
        if (i_1 == lmaxindex) {
            break
        }
    }
    return
}
[export, sideeffects]
def D_SpriteCalculateGradients() {
    var p_normal : vec3_t
    var p_saxis : vec3_t
    var p_taxis : vec3_t
    var p_temp1 : vec3_t
    var distinv : float
    TransformVector(unsafe(addr<float?>(r_spritedesc.vpn[0])), unsafe(addr<float?>(p_normal[0])))
    TransformVector(unsafe(addr<float?>(r_spritedesc.vright[0])), unsafe(addr<float?>(p_saxis[0])))
    TransformVector(unsafe(addr<float?>(r_spritedesc.vup[0])), unsafe(addr<float?>(p_taxis[0])))
    VectorInverse(unsafe(addr<float?>(p_taxis[0])))
    distinv = float(1.0lf / double(-(unsafe(unsafe(addr(modelorg[0]))[0]) * unsafe(unsafe(addr(r_spritedesc.vpn[0]))[0]) + unsafe(unsafe(addr(modelorg[0]))[1]) * unsafe(unsafe(addr(r_spritedesc.vpn[0]))[1]) + unsafe(unsafe(addr(modelorg[0]))[2]) * unsafe(unsafe(addr(r_spritedesc.vpn[0]))[2]))))
    d_sdivzstepu = unsafe(unsafe(addr(p_saxis[0]))[0]) * xscaleinv
    d_tdivzstepu = unsafe(unsafe(addr(p_taxis[0]))[0]) * xscaleinv
    d_sdivzstepv = -unsafe(unsafe(addr(p_saxis[0]))[1]) * yscaleinv
    d_tdivzstepv = -unsafe(unsafe(addr(p_taxis[0]))[1]) * yscaleinv
    d_zistepu = unsafe(unsafe(addr(p_normal[0]))[0]) * xscaleinv * distinv
    d_zistepv = -unsafe(unsafe(addr(p_normal[0]))[1]) * yscaleinv * distinv
    d_sdivzorigin = unsafe(unsafe(addr(p_saxis[0]))[2]) - xcenter * d_sdivzstepu - ycenter * d_sdivzstepv
    d_tdivzorigin = unsafe(unsafe(addr(p_taxis[0]))[2]) - xcenter * d_tdivzstepu - ycenter * d_tdivzstepv
    d_ziorigin = unsafe(unsafe(addr(p_normal[0]))[2]) * distinv - xcenter * d_zistepu - ycenter * d_zistepv
    TransformVector(unsafe(addr<float?>(modelorg[0])), unsafe(addr<float?>(p_temp1[0])))
    sadjust = int(double((unsafe(unsafe(addr(p_temp1[0]))[0]) * unsafe(unsafe(addr(p_saxis[0]))[0]) + unsafe(unsafe(addr(p_temp1[0]))[1]) * unsafe(unsafe(addr(p_saxis[0]))[1]) + unsafe(unsafe(addr(p_temp1[0]))[2]) * unsafe(unsafe(addr(p_saxis[0]))[2])) * 65536.0) + 0.5lf) - (-(cachewidth >> 1) << 16)
    tadjust = int(double((unsafe(unsafe(addr(p_temp1[0]))[0]) * unsafe(unsafe(addr(p_taxis[0]))[0]) + unsafe(unsafe(addr(p_temp1[0]))[1]) * unsafe(unsafe(addr(p_taxis[0]))[1]) + unsafe(unsafe(addr(p_temp1[0]))[2]) * unsafe(unsafe(addr(p_taxis[0]))[2])) * 65536.0) + 0.5lf) - (-(sprite_height >> 1) << 16)
    bbextents = (cachewidth << 16) - 1
    bbextentt = (sprite_height << 16) - 1
    return
}
var private sprite_height : int = default<int>

[sideeffects]
def private c2da_layout_proofs_16() {
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
    static_assert(typeinfo sizeof(type<sspan_t>) == 12, "C layout of sspan_t: sizeof")
    static_assert(typeinfo alignof(type<sspan_t>) == 4, "C layout of sspan_t: alignof")
    static_assert(typeinfo offsetof<u>(type<sspan_t>) == 0, "C layout of sspan_t: offsetof u")
    static_assert(typeinfo offsetof<v>(type<sspan_t>) == 4, "C layout of sspan_t: offsetof v")
    static_assert(typeinfo offsetof<count>(type<sspan_t>) == 8, "C layout of sspan_t: offsetof count")
    static_assert(typeinfo sizeof(type<sspan_s>) == 12, "C layout of sspan_s: sizeof")
    static_assert(typeinfo alignof(type<sspan_s>) == 4, "C layout of sspan_s: alignof")
    static_assert(typeinfo offsetof<u>(type<sspan_s>) == 0, "C layout of sspan_s: offsetof u")
    static_assert(typeinfo offsetof<v>(type<sspan_s>) == 4, "C layout of sspan_s: offsetof v")
    static_assert(typeinfo offsetof<count>(type<sspan_s>) == 8, "C layout of sspan_s: offsetof count")
}
