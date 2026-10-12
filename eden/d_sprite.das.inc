[export, sideeffects]
def D_DrawSprite() {
    let c2da_saved_sp : int = c2da_lin_sp
    D_DrawSprite_c2da_frame(c2da_lin_enter(12304))
    c2da_lin_sp = c2da_saved_sp
}
var private sprite_spans : int = default<int>

[export, sideeffects]
def D_SpriteDrawSpans(var pspan : int) {
    var count : int
    var spancount : int
    var izistep : int
    var izi : int
    var pbase : int
    var pdest : int
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
    var pz : int
    sstep = 0
    tstep = 0
    pbase = cacheblock
    sdivz8stepu = d_sdivzstepu * 8.0
    tdivz8stepu = d_tdivzstepu * 8.0
    zi8stepu = d_zistepu * 8.0
    izistep = int(d_zistepu * 32768.0 * 65536.0)
    label 0:
    pdest = d_viewbuffer + int(screenwidth * int(uint(c2da_mem[pspan + 4]) | uint(c2da_mem[pspan + 5]) << 0x8 | uint(c2da_mem[pspan + 6]) << 0x10 | uint(c2da_mem[pspan + 7]) << 0x18)) + int(uint(c2da_mem[pspan]) | uint(c2da_mem[pspan + 1]) << 0x8 | uint(c2da_mem[pspan + 2]) << 0x10 | uint(c2da_mem[pspan + 3]) << 0x18)
    pz = d_pzbuffer + int(d_zwidth * uint(int(uint(c2da_mem[pspan + 4]) | uint(c2da_mem[pspan + 5]) << 0x8 | uint(c2da_mem[pspan + 6]) << 0x10 | uint(c2da_mem[pspan + 7]) << 0x18))) * 2 + int(uint(c2da_mem[pspan]) | uint(c2da_mem[pspan + 1]) << 0x8 | uint(c2da_mem[pspan + 2]) << 0x10 | uint(c2da_mem[pspan + 3]) << 0x18) * 2
    count = int(uint(c2da_mem[pspan + 8]) | uint(c2da_mem[pspan + 9]) << 0x8 | uint(c2da_mem[pspan + 10]) << 0x10 | uint(c2da_mem[pspan + 11]) << 0x18)
    if (count <= 0) {
        goto label 38
    }
    du = float(int(uint(c2da_mem[pspan]) | uint(c2da_mem[pspan + 1]) << 0x8 | uint(c2da_mem[pspan + 2]) << 0x10 | uint(c2da_mem[pspan + 3]) << 0x18))
    dv = float(int(uint(c2da_mem[pspan + 4]) | uint(c2da_mem[pspan + 5]) << 0x8 | uint(c2da_mem[pspan + 6]) << 0x10 | uint(c2da_mem[pspan + 7]) << 0x18))
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
    let c2da_fresh3 : int = pbase + (s >> 16) + int((t >> 16) * cachewidth)
    btemp = uint8(c2da_mem[c2da_fresh3])
    if (int(btemp) != 255) {
        goto label 16
    }
    label 14:
    izi += izistep
    pdest++
    pz += 2
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
    pspan += 12
    if (int(uint(c2da_mem[pspan + 8]) | uint(c2da_mem[pspan + 9]) << 0x8 | uint(c2da_mem[pspan + 10]) << 0x10 | uint(c2da_mem[pspan + 11]) << 0x18) != -128) {
        goto label 0
    }
    return
    label 16:
    if (int(int16(uint(c2da_mem[pz]) | uint(c2da_mem[pz + 1]) << 0x8)) <= izi >> 16) {
        goto label 18
    }
    label 17:
    goto label 14
    label 18:
    let c2da_fresh4 : int16 = int16(izi >> 16)
    let c2da_fresh5 : uint = uint(c2da_fresh4)
    c2da_mem[pz] = uint8(c2da_fresh5)
    c2da_mem[pz + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[pdest] = btemp
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
    var pvert : int
    var pnext : int
    var pspan_0 : int
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
    pspan_0 = sprite_spans
    i_0 = minindex
    let c2da_fresh6 : int = int(uint(c2da_mem[216584]) | uint(c2da_mem[216585]) << 0x8 | uint(c2da_mem[216586]) << 0x10 | uint(c2da_mem[216587]) << 0x18) + i_0 * 20 + 4
    vvert = uint_bits_to_float(uint(c2da_mem[c2da_fresh6]) | uint(c2da_mem[c2da_fresh6 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh6 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh6 + 3]) << 0x18)
    if (vvert < uint_bits_to_float(uint(c2da_mem[5280]) | uint(c2da_mem[5281]) << 0x8 | uint(c2da_mem[5282]) << 0x10 | uint(c2da_mem[5283]) << 0x18)) {
        vvert = uint_bits_to_float(uint(c2da_mem[5280]) | uint(c2da_mem[5281]) << 0x8 | uint(c2da_mem[5282]) << 0x10 | uint(c2da_mem[5283]) << 0x18)
    }
    if (vvert > uint_bits_to_float(uint(c2da_mem[5296]) | uint(c2da_mem[5297]) << 0x8 | uint(c2da_mem[5298]) << 0x10 | uint(c2da_mem[5299]) << 0x18)) {
        vvert = uint_bits_to_float(uint(c2da_mem[5296]) | uint(c2da_mem[5297]) << 0x8 | uint(c2da_mem[5298]) << 0x10 | uint(c2da_mem[5299]) << 0x18)
    }
    vtop = float(ceil(double(vvert)))
    while (true) {
        pvert = int(uint(c2da_mem[216584]) | uint(c2da_mem[216585]) << 0x8 | uint(c2da_mem[216586]) << 0x10 | uint(c2da_mem[216587]) << 0x18) + i_0 * 20
        pnext = pvert + 1 * 20
        vnext = uint_bits_to_float(uint(c2da_mem[pnext + 4]) | uint(c2da_mem[pnext + 5]) << 0x8 | uint(c2da_mem[pnext + 6]) << 0x10 | uint(c2da_mem[pnext + 7]) << 0x18)
        if (vnext < uint_bits_to_float(uint(c2da_mem[5280]) | uint(c2da_mem[5281]) << 0x8 | uint(c2da_mem[5282]) << 0x10 | uint(c2da_mem[5283]) << 0x18)) {
            vnext = uint_bits_to_float(uint(c2da_mem[5280]) | uint(c2da_mem[5281]) << 0x8 | uint(c2da_mem[5282]) << 0x10 | uint(c2da_mem[5283]) << 0x18)
        }
        if (vnext > uint_bits_to_float(uint(c2da_mem[5296]) | uint(c2da_mem[5297]) << 0x8 | uint(c2da_mem[5298]) << 0x10 | uint(c2da_mem[5299]) << 0x18)) {
            vnext = uint_bits_to_float(uint(c2da_mem[5296]) | uint(c2da_mem[5297]) << 0x8 | uint(c2da_mem[5298]) << 0x10 | uint(c2da_mem[5299]) << 0x18)
        }
        vbottom = float(ceil(double(vnext)))
        if (vtop < vbottom) {
            uvert = uint_bits_to_float(uint(c2da_mem[pvert]) | uint(c2da_mem[pvert + 1]) << 0x8 | uint(c2da_mem[pvert + 2]) << 0x10 | uint(c2da_mem[pvert + 3]) << 0x18)
            if (uvert < uint_bits_to_float(uint(c2da_mem[5276]) | uint(c2da_mem[5277]) << 0x8 | uint(c2da_mem[5278]) << 0x10 | uint(c2da_mem[5279]) << 0x18)) {
                uvert = uint_bits_to_float(uint(c2da_mem[5276]) | uint(c2da_mem[5277]) << 0x8 | uint(c2da_mem[5278]) << 0x10 | uint(c2da_mem[5279]) << 0x18)
            }
            if (uvert > uint_bits_to_float(uint(c2da_mem[5292]) | uint(c2da_mem[5293]) << 0x8 | uint(c2da_mem[5294]) << 0x10 | uint(c2da_mem[5295]) << 0x18)) {
                uvert = uint_bits_to_float(uint(c2da_mem[5292]) | uint(c2da_mem[5293]) << 0x8 | uint(c2da_mem[5294]) << 0x10 | uint(c2da_mem[5295]) << 0x18)
            }
            unext = uint_bits_to_float(uint(c2da_mem[pnext]) | uint(c2da_mem[pnext + 1]) << 0x8 | uint(c2da_mem[pnext + 2]) << 0x10 | uint(c2da_mem[pnext + 3]) << 0x18)
            if (unext < uint_bits_to_float(uint(c2da_mem[5276]) | uint(c2da_mem[5277]) << 0x8 | uint(c2da_mem[5278]) << 0x10 | uint(c2da_mem[5279]) << 0x18)) {
                unext = uint_bits_to_float(uint(c2da_mem[5276]) | uint(c2da_mem[5277]) << 0x8 | uint(c2da_mem[5278]) << 0x10 | uint(c2da_mem[5279]) << 0x18)
            }
            if (unext > uint_bits_to_float(uint(c2da_mem[5292]) | uint(c2da_mem[5293]) << 0x8 | uint(c2da_mem[5294]) << 0x10 | uint(c2da_mem[5295]) << 0x18)) {
                unext = uint_bits_to_float(uint(c2da_mem[5292]) | uint(c2da_mem[5293]) << 0x8 | uint(c2da_mem[5294]) << 0x10 | uint(c2da_mem[5295]) << 0x18)
            }
            du_0 = unext - uvert
            dv_0 = vnext - vvert
            slope = du_0 / dv_0
            u_step = int(slope * 65536.0)
            u = int((uvert + slope * (vtop - vvert)) * 65536.0) + (65536 - 1)
            itop = int(vtop)
            ibottom = int(vbottom)
            for (v in range(itop, ibottom)) {
                let c2da_fresh7 : int = (u >> 16) - int(uint(c2da_mem[pspan_0]) | uint(c2da_mem[pspan_0 + 1]) << 0x8 | uint(c2da_mem[pspan_0 + 2]) << 0x10 | uint(c2da_mem[pspan_0 + 3]) << 0x18)
                let c2da_fresh8 : uint = uint(c2da_fresh7)
                c2da_mem[pspan_0 + 8] = uint8(c2da_fresh8)
                c2da_mem[pspan_0 + 9] = uint8(c2da_fresh8 >> 0x8)
                c2da_mem[pspan_0 + 10] = uint8(c2da_fresh8 >> 0x10)
                c2da_mem[pspan_0 + 11] = uint8(c2da_fresh8 >> 0x18)
                u += u_step
                pspan_0 += 12
            }
        }
        vtop = vbottom
        vvert = vnext
        i_0++
        if (i_0 == int(uint(c2da_mem[216576]) | uint(c2da_mem[216577]) << 0x8 | uint(c2da_mem[216578]) << 0x10 | uint(c2da_mem[216579]) << 0x18)) {
            i_0 = 0
        }
        if (i_0 == maxindex) {
            break
        }
    }
    let c2da_fresh9 : int = -128
    let c2da_fresh10 : uint = uint(c2da_fresh9)
    c2da_mem[pspan_0 + 8] = uint8(c2da_fresh10)
    c2da_mem[pspan_0 + 9] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[pspan_0 + 10] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[pspan_0 + 11] = uint8(c2da_fresh10 >> 0x18)
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
    var pvert_0 : int
    var pnext_0 : int
    var pspan_1 : int
    var du_1 : float
    var dv_1 : float
    var vtop_0 : float
    var vbottom_0 : float
    var slope_0 : float
    var u_0 : int
    var u_step_0 : int
    pspan_1 = sprite_spans
    i_1 = minindex
    if (i_1 == 0) {
        i_1 = int(uint(c2da_mem[216576]) | uint(c2da_mem[216577]) << 0x8 | uint(c2da_mem[216578]) << 0x10 | uint(c2da_mem[216579]) << 0x18)
    }
    lmaxindex = maxindex
    if (lmaxindex == 0) {
        lmaxindex = int(uint(c2da_mem[216576]) | uint(c2da_mem[216577]) << 0x8 | uint(c2da_mem[216578]) << 0x10 | uint(c2da_mem[216579]) << 0x18)
    }
    let c2da_fresh11 : int = int(uint(c2da_mem[216584]) | uint(c2da_mem[216585]) << 0x8 | uint(c2da_mem[216586]) << 0x10 | uint(c2da_mem[216587]) << 0x18) + i_1 * 20 + 4
    vtop_0 = float(ceil(double(uint_bits_to_float(uint(c2da_mem[c2da_fresh11]) | uint(c2da_mem[c2da_fresh11 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh11 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh11 + 3]) << 0x18))))
    while (true) {
        pvert_0 = int(uint(c2da_mem[216584]) | uint(c2da_mem[216585]) << 0x8 | uint(c2da_mem[216586]) << 0x10 | uint(c2da_mem[216587]) << 0x18) + i_1 * 20
        pnext_0 = pvert_0 - 1 * 20
        vbottom_0 = float(ceil(double(uint_bits_to_float(uint(c2da_mem[pnext_0 + 4]) | uint(c2da_mem[pnext_0 + 5]) << 0x8 | uint(c2da_mem[pnext_0 + 6]) << 0x10 | uint(c2da_mem[pnext_0 + 7]) << 0x18))))
        if (vtop_0 < vbottom_0) {
            du_1 = uint_bits_to_float(uint(c2da_mem[pnext_0]) | uint(c2da_mem[pnext_0 + 1]) << 0x8 | uint(c2da_mem[pnext_0 + 2]) << 0x10 | uint(c2da_mem[pnext_0 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[pvert_0]) | uint(c2da_mem[pvert_0 + 1]) << 0x8 | uint(c2da_mem[pvert_0 + 2]) << 0x10 | uint(c2da_mem[pvert_0 + 3]) << 0x18)
            dv_1 = uint_bits_to_float(uint(c2da_mem[pnext_0 + 4]) | uint(c2da_mem[pnext_0 + 5]) << 0x8 | uint(c2da_mem[pnext_0 + 6]) << 0x10 | uint(c2da_mem[pnext_0 + 7]) << 0x18) - uint_bits_to_float(uint(c2da_mem[pvert_0 + 4]) | uint(c2da_mem[pvert_0 + 5]) << 0x8 | uint(c2da_mem[pvert_0 + 6]) << 0x10 | uint(c2da_mem[pvert_0 + 7]) << 0x18)
            slope_0 = du_1 / dv_1
            u_step_0 = int(slope_0 * 65536.0)
            u_0 = int((uint_bits_to_float(uint(c2da_mem[pvert_0]) | uint(c2da_mem[pvert_0 + 1]) << 0x8 | uint(c2da_mem[pvert_0 + 2]) << 0x10 | uint(c2da_mem[pvert_0 + 3]) << 0x18) + slope_0 * (vtop_0 - uint_bits_to_float(uint(c2da_mem[pvert_0 + 4]) | uint(c2da_mem[pvert_0 + 5]) << 0x8 | uint(c2da_mem[pvert_0 + 6]) << 0x10 | uint(c2da_mem[pvert_0 + 7]) << 0x18))) * 65536.0) + (65536 - 1)
            itop_0 = int(vtop_0)
            ibottom_0 = int(vbottom_0)
            for (v_0 in range(itop_0, ibottom_0)) {
                let c2da_fresh12 : int = u_0 >> 16
                let c2da_fresh13 : uint = uint(c2da_fresh12)
                c2da_mem[pspan_1] = uint8(c2da_fresh13)
                c2da_mem[pspan_1 + 1] = uint8(c2da_fresh13 >> 0x8)
                c2da_mem[pspan_1 + 2] = uint8(c2da_fresh13 >> 0x10)
                c2da_mem[pspan_1 + 3] = uint8(c2da_fresh13 >> 0x18)
                let c2da_fresh14 : uint = uint(v_0)
                c2da_mem[pspan_1 + 4] = uint8(c2da_fresh14)
                c2da_mem[pspan_1 + 5] = uint8(c2da_fresh14 >> 0x8)
                c2da_mem[pspan_1 + 6] = uint8(c2da_fresh14 >> 0x10)
                c2da_mem[pspan_1 + 7] = uint8(c2da_fresh14 >> 0x18)
                u_0 += u_step_0
                pspan_1 += 12
            }
        }
        vtop_0 = vbottom_0
        i_1--
        if (i_1 == 0) {
            i_1 = int(uint(c2da_mem[216576]) | uint(c2da_mem[216577]) << 0x8 | uint(c2da_mem[216578]) << 0x10 | uint(c2da_mem[216579]) << 0x18)
        }
        if (i_1 == lmaxindex) {
            break
        }
    }
    return
}
[export, sideeffects]
def D_SpriteCalculateGradients() {
    let c2da_saved_sp : int = c2da_lin_sp
    D_SpriteCalculateGradients_c2da_frame(c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
var private sprite_height : int = default<int>

[sideeffects]
def private D_DrawSprite_c2da_frame(c2da_fp : int) {
    var i : int
    var ymin : float
    var ymax : float
    var pverts : int
    sprite_spans = int(c2da_fp)  // nolint:PERF020
    ymin = float(999999.9lf)
    ymax = float(-999999.9lf)
    pverts = int(uint(c2da_mem[216584]) | uint(c2da_mem[216585]) << 0x8 | uint(c2da_mem[216586]) << 0x10 | uint(c2da_mem[216587]) << 0x18)
    i = 0
    while (i < int(uint(c2da_mem[216576]) | uint(c2da_mem[216577]) << 0x8 | uint(c2da_mem[216578]) << 0x10 | uint(c2da_mem[216579]) << 0x18)) {
        if (uint_bits_to_float(uint(c2da_mem[pverts + 4]) | uint(c2da_mem[pverts + 5]) << 0x8 | uint(c2da_mem[pverts + 6]) << 0x10 | uint(c2da_mem[pverts + 7]) << 0x18) < ymin) {
            ymin = uint_bits_to_float(uint(c2da_mem[pverts + 4]) | uint(c2da_mem[pverts + 5]) << 0x8 | uint(c2da_mem[pverts + 6]) << 0x10 | uint(c2da_mem[pverts + 7]) << 0x18)
            minindex = i
        }
        if (uint_bits_to_float(uint(c2da_mem[pverts + 4]) | uint(c2da_mem[pverts + 5]) << 0x8 | uint(c2da_mem[pverts + 6]) << 0x10 | uint(c2da_mem[pverts + 7]) << 0x18) > ymax) {
            ymax = uint_bits_to_float(uint(c2da_mem[pverts + 4]) | uint(c2da_mem[pverts + 5]) << 0x8 | uint(c2da_mem[pverts + 6]) << 0x10 | uint(c2da_mem[pverts + 7]) << 0x18)
            maxindex = i
        }
        pverts += 20
        i++
    }
    ymin = float(ceil(double(ymin)))
    ymax = float(ceil(double(ymax)))
    if (ymin >= ymax) {
        return
    }
    let c2da_fresh0 : int = int(uint(c2da_mem[216592]) | uint(c2da_mem[216593]) << 0x8 | uint(c2da_mem[216594]) << 0x10 | uint(c2da_mem[216595]) << 0x18)
    cachewidth = int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18)
    let c2da_fresh1 : int = int(uint(c2da_mem[216592]) | uint(c2da_mem[216593]) << 0x8 | uint(c2da_mem[216594]) << 0x10 | uint(c2da_mem[216595]) << 0x18) + 4
    sprite_height = int(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh1 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh1 + 3]) << 0x18)
    cacheblock = int(uint(c2da_mem[216592]) | uint(c2da_mem[216593]) << 0x8 | uint(c2da_mem[216594]) << 0x10 | uint(c2da_mem[216595]) << 0x18) + 32 + 0
    pverts = int(uint(c2da_mem[216584]) | uint(c2da_mem[216585]) << 0x8 | uint(c2da_mem[216586]) << 0x10 | uint(c2da_mem[216587]) << 0x18)
    let c2da_fresh2 : int = pverts + int(uint(c2da_mem[216576]) | uint(c2da_mem[216577]) << 0x8 | uint(c2da_mem[216578]) << 0x10 | uint(c2da_mem[216579]) << 0x18) * 20
    c2da_lin_memmove(c2da_fresh2, pverts + 0 * 20, 20ul)
    D_SpriteCalculateGradients()
    D_SpriteScanLeftEdge()
    D_SpriteScanRightEdge()
    D_SpriteDrawSpans(sprite_spans)
    return
}
[sideeffects]
def private D_SpriteCalculateGradients_c2da_frame(c2da_fp : int) {
    var distinv : float
    TransformVector(216624, c2da_fp)
    TransformVector(216612, c2da_fp + 16)
    TransformVector(216600, c2da_fp + 32)
    VectorInverse(c2da_fp + 32)
    distinv = float(1.0lf / double(-(uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[216624 + 0 * 4]) | uint(c2da_mem[216624 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[216624 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[216624 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[216624 + 1 * 4]) | uint(c2da_mem[216624 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[216624 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[216624 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[216624 + 2 * 4]) | uint(c2da_mem[216624 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[216624 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[216624 + 2 * 4 + 3]) << 0x18))))
    d_sdivzstepu = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18) * xscaleinv
    d_tdivzstepu = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 0 * 4]) | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 3]) << 0x18) * xscaleinv
    d_sdivzstepv = -uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18) * yscaleinv
    d_tdivzstepv = -uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 1 * 4]) | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 3]) << 0x18) * yscaleinv
    d_zistepu = uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) * xscaleinv * distinv
    d_zistepv = -uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18) * yscaleinv * distinv
    d_sdivzorigin = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18) - xcenter * d_sdivzstepu - ycenter * d_sdivzstepv
    d_tdivzorigin = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 2 * 4]) | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 3]) << 0x18) - xcenter * d_tdivzstepu - ycenter * d_tdivzstepv
    d_ziorigin = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) * distinv - xcenter * d_zistepu - ycenter * d_zistepv
    TransformVector(204240, c2da_fp + 48)
    sadjust = int(double((uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 0 * 4]) | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 1 * 4]) | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 2 * 4]) | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18)) * 65536.0) + 0.5lf) - (-(cachewidth >> 1) << 16)
    tadjust = int(double((uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 0 * 4]) | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 0 * 4]) | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 1 * 4]) | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 1 * 4]) | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 2 * 4]) | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 2 * 4]) | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 3]) << 0x18)) * 65536.0) + 0.5lf) - (-(sprite_height >> 1) << 16)
    bbextents = (cachewidth << 16) - 1
    bbextentt = (sprite_height << 16) - 1
    return
}
