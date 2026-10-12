[export, sideeffects]
def D_WarpScreen() {
    let c2da_saved_sp : int = c2da_lin_sp
    D_WarpScreen_c2da_frame(c2da_lin_enter(13392))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def D_DrawSpans8(var pspan : int) {
    var count : int
    var spancount : int
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
    sstep = 0
    tstep = 0
    pbase = cacheblock
    sdivz8stepu = d_sdivzstepu * 8.0
    tdivz8stepu = d_tdivzstepu * 8.0
    zi8stepu = d_zistepu * 8.0
    while (true) {
        let c2da_fresh19 : int = int(uint(c2da_mem[pspan + 4]) | uint(c2da_mem[pspan + 5]) << 0x8 | uint(c2da_mem[pspan + 6]) << 0x10 | uint(c2da_mem[pspan + 7]) << 0x18)
        let c2da_fresh20 : int = int(uint(c2da_mem[pspan]) | uint(c2da_mem[pspan + 1]) << 0x8 | uint(c2da_mem[pspan + 2]) << 0x10 | uint(c2da_mem[pspan + 3]) << 0x18)
        pdest = d_viewbuffer + int(screenwidth * c2da_fresh19) + c2da_fresh20
        count = int(uint(c2da_mem[pspan + 8]) | uint(c2da_mem[pspan + 9]) << 0x8 | uint(c2da_mem[pspan + 10]) << 0x10 | uint(c2da_mem[pspan + 11]) << 0x18)
        du = float(c2da_fresh20)
        dv = float(c2da_fresh19)
        sdivz = d_sdivzorigin + dv * d_sdivzstepv + du * d_sdivzstepu
        tdivz = d_tdivzorigin + dv * d_tdivzstepv + du * d_tdivzstepu
        zi = d_ziorigin + dv * d_zistepv + du * d_zistepu
        z = 65536.0 / zi
        s = int(sdivz * z) + sadjust
        if (s > bbextents) {
            s = bbextents
        } elif (s < 0) {
            s = 0
        }
        t = int(tdivz * z) + tadjust
        if (t > bbextentt) {
            t = bbextentt
        } elif (t < 0) {
            t = 0
        }
        while (true) {
            if (count >= 8) {
                spancount = 8
            } else {
                spancount = count
            }
            count -= spancount
            if (count != 0) {
                sdivz += sdivz8stepu
                tdivz += tdivz8stepu
                zi += zi8stepu
                z = 65536.0 / zi
                snext = int(sdivz * z) + sadjust
                if (snext > bbextents) {
                    snext = bbextents
                } elif (snext < 8) {
                    snext = 8
                }
                tnext = int(tdivz * z) + tadjust
                if (tnext > bbextentt) {
                    tnext = bbextentt
                } elif (tnext < 8) {
                    tnext = 8
                }
                sstep = snext - s >> 3
                tstep = tnext - t >> 3
            } else {
                spancountminus1 = float(spancount - 1)
                sdivz = sdivz + d_sdivzstepu * spancountminus1
                tdivz = tdivz + d_tdivzstepu * spancountminus1
                zi = zi + d_zistepu * spancountminus1
                z = 65536.0 / zi
                snext = int(sdivz * z) + sadjust
                if (snext > bbextents) {
                    snext = bbextents
                } elif (snext < 8) {
                    snext = 8
                }
                tnext = int(tdivz * z) + tadjust
                if (tnext > bbextentt) {
                    tnext = bbextentt
                } elif (tnext < 8) {
                    tnext = 8
                }
                if (spancount > 1) {
                    sstep = (snext - s) / (spancount - 1)
                    tstep = (tnext - t) / (spancount - 1)
                }
            }
            while (true) {
                let c2da_fresh16 : int = pdest
                pdest++
                let c2da_fresh17 : int = pbase + (s >> 16) + int((t >> 16) * cachewidth)
                let c2da_fresh18 : uint8 = c2da_mem[c2da_fresh17]
                c2da_mem[c2da_fresh16] = c2da_fresh18
                s += sstep
                t += tstep
                spancount--
                if (spancount <= 0) {
                    break
                }
            }
            s = snext
            t = tnext
            if (count <= 0) {
                break
            }
        }
        pspan = int(uint(c2da_mem[pspan + 16]) | uint(c2da_mem[pspan + 17]) << 0x8 | uint(c2da_mem[pspan + 18]) << 0x10 | uint(c2da_mem[pspan + 19]) << 0x18)
        if (pspan == 0) {
            break
        }
    }
    return
}
[export, sideeffects]
def D_DrawZSpans(var pspan_0 : int) {
    var count_0 : int
    var doublecount : int
    var izistep : int
    var izi : int
    var pdest_0 : int
    var ltemp : uint
    izistep = int(d_zistepu * 32768.0 * 65536.0)
    while (true) {
        let c2da_fresh28 : int = int(uint(c2da_mem[pspan_0 + 4]) | uint(c2da_mem[pspan_0 + 5]) << 0x8 | uint(c2da_mem[pspan_0 + 6]) << 0x10 | uint(c2da_mem[pspan_0 + 7]) << 0x18)
        let c2da_fresh29 : int = int(uint(c2da_mem[pspan_0]) | uint(c2da_mem[pspan_0 + 1]) << 0x8 | uint(c2da_mem[pspan_0 + 2]) << 0x10 | uint(c2da_mem[pspan_0 + 3]) << 0x18)
        pdest_0 = d_pzbuffer + int(d_zwidth * uint(c2da_fresh28)) * 2 + c2da_fresh29 * 2
        count_0 = int(uint(c2da_mem[pspan_0 + 8]) | uint(c2da_mem[pspan_0 + 9]) << 0x8 | uint(c2da_mem[pspan_0 + 10]) << 0x10 | uint(c2da_mem[pspan_0 + 11]) << 0x18)
        izi = int(double(d_ziorigin + float(c2da_fresh28) * d_zistepv + float(c2da_fresh29) * d_zistepu) * 32768.0lf * 65536.0lf)
        if ((int64(pdest_0) & 2l) != 0) {
            let c2da_fresh21 : int = pdest_0
            pdest_0 += 2
            let c2da_fresh22 : int16 = int16(izi >> 16)
            let c2da_fresh23 : uint = uint(c2da_fresh22)
            c2da_mem[c2da_fresh21] = uint8(c2da_fresh23)
            c2da_mem[c2da_fresh21 + 1] = uint8(c2da_fresh23 >> 0x8)
            izi += izistep
            count_0--
        }
        doublecount = count_0 >> 1
        if (doublecount > 0) {
            while (true) {
                ltemp = uint(izi >> 16)
                izi += izistep
                ltemp |= uint(izi) & 0xffff0000u
                izi += izistep
                let c2da_fresh24 : int = int(ltemp)
                let c2da_fresh25 : uint = uint(c2da_fresh24)
                c2da_mem[pdest_0] = uint8(c2da_fresh25)
                c2da_mem[pdest_0 + 1] = uint8(c2da_fresh25 >> 0x8)
                c2da_mem[pdest_0 + 2] = uint8(c2da_fresh25 >> 0x10)
                c2da_mem[pdest_0 + 3] = uint8(c2da_fresh25 >> 0x18)
                pdest_0 += 2 * 2
                doublecount--
                if (doublecount <= 0) {
                    break
                }
            }
        }
        if ((count_0 & 1) != 0) {
            let c2da_fresh26 : int16 = int16(izi >> 16)
            let c2da_fresh27 : uint = uint(c2da_fresh26)
            c2da_mem[pdest_0] = uint8(c2da_fresh27)
            c2da_mem[pdest_0 + 1] = uint8(c2da_fresh27 >> 0x8)
        }
        pspan_0 = int(uint(c2da_mem[pspan_0 + 16]) | uint(c2da_mem[pspan_0 + 17]) << 0x8 | uint(c2da_mem[pspan_0 + 18]) << 0x10 | uint(c2da_mem[pspan_0 + 19]) << 0x18)
        if (pspan_0 == 0) {
            break
        }
    }
    return
}
[export, sideeffects]
def Turbulent8(var pspan_1 : int) {
    var count_1 : int
    var snext_0 : int
    var tnext_0 : int
    var sdivz_0 : float
    var tdivz_0 : float
    var zi_1 : float
    var z_0 : float
    var du_1 : float
    var dv_1 : float
    var spancountminus1_0 : float
    var sdivz16stepu : float
    var tdivz16stepu : float
    var zi16stepu : float
    r_turb_turb = 210944 + (int(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) * 20.0lf) & 128 - 1) * 4
    r_turb_sstep = 0
    r_turb_tstep = 0
    r_turb_pbase = cacheblock
    sdivz16stepu = d_sdivzstepu * 16.0
    tdivz16stepu = d_tdivzstepu * 16.0
    zi16stepu = d_zistepu * 16.0
    while (true) {
        let c2da_fresh30 : int = int(uint(c2da_mem[pspan_1 + 4]) | uint(c2da_mem[pspan_1 + 5]) << 0x8 | uint(c2da_mem[pspan_1 + 6]) << 0x10 | uint(c2da_mem[pspan_1 + 7]) << 0x18)
        let c2da_fresh31 : int = int(uint(c2da_mem[pspan_1]) | uint(c2da_mem[pspan_1 + 1]) << 0x8 | uint(c2da_mem[pspan_1 + 2]) << 0x10 | uint(c2da_mem[pspan_1 + 3]) << 0x18)
        r_turb_pdest = d_viewbuffer + int(screenwidth * c2da_fresh30) + c2da_fresh31
        count_1 = int(uint(c2da_mem[pspan_1 + 8]) | uint(c2da_mem[pspan_1 + 9]) << 0x8 | uint(c2da_mem[pspan_1 + 10]) << 0x10 | uint(c2da_mem[pspan_1 + 11]) << 0x18)
        du_1 = float(c2da_fresh31)
        dv_1 = float(c2da_fresh30)
        sdivz_0 = d_sdivzorigin + dv_1 * d_sdivzstepv + du_1 * d_sdivzstepu
        tdivz_0 = d_tdivzorigin + dv_1 * d_tdivzstepv + du_1 * d_tdivzstepu
        zi_1 = d_ziorigin + dv_1 * d_zistepv + du_1 * d_zistepu
        z_0 = 65536.0 / zi_1
        r_turb_s = int(sdivz_0 * z_0) + sadjust
        if (r_turb_s > bbextents) {
            r_turb_s = bbextents
        } elif (r_turb_s < 0) {
            r_turb_s = 0
        }
        r_turb_t = int(tdivz_0 * z_0) + tadjust
        if (r_turb_t > bbextentt) {
            r_turb_t = bbextentt
        } elif (r_turb_t < 0) {
            r_turb_t = 0
        }
        while (true) {
            if (count_1 >= 16) {
                r_turb_spancount = 16
            } else {
                r_turb_spancount = count_1
            }
            count_1 -= r_turb_spancount
            if (count_1 != 0) {
                sdivz_0 += sdivz16stepu
                tdivz_0 += tdivz16stepu
                zi_1 += zi16stepu
                z_0 = 65536.0 / zi_1
                snext_0 = int(sdivz_0 * z_0) + sadjust
                if (snext_0 > bbextents) {
                    snext_0 = bbextents
                } elif (snext_0 < 16) {
                    snext_0 = 16
                }
                tnext_0 = int(tdivz_0 * z_0) + tadjust
                if (tnext_0 > bbextentt) {
                    tnext_0 = bbextentt
                } elif (tnext_0 < 16) {
                    tnext_0 = 16
                }
                r_turb_sstep = snext_0 - r_turb_s >> 4
                r_turb_tstep = tnext_0 - r_turb_t >> 4
            } else {
                spancountminus1_0 = float(r_turb_spancount - 1)
                sdivz_0 = sdivz_0 + d_sdivzstepu * spancountminus1_0
                tdivz_0 = tdivz_0 + d_tdivzstepu * spancountminus1_0
                zi_1 = zi_1 + d_zistepu * spancountminus1_0
                z_0 = 65536.0 / zi_1
                snext_0 = int(sdivz_0 * z_0) + sadjust
                if (snext_0 > bbextents) {
                    snext_0 = bbextents
                } elif (snext_0 < 16) {
                    snext_0 = 16
                }
                tnext_0 = int(tdivz_0 * z_0) + tadjust
                if (tnext_0 > bbextentt) {
                    tnext_0 = bbextentt
                } elif (tnext_0 < 16) {
                    tnext_0 = 16
                }
                if (r_turb_spancount > 1) {
                    r_turb_sstep = (snext_0 - r_turb_s) / (r_turb_spancount - 1)
                    r_turb_tstep = (tnext_0 - r_turb_t) / (r_turb_spancount - 1)
                }
            }
            r_turb_s &= (128 << 16) - 1
            r_turb_t &= (128 << 16) - 1
            D_DrawTurbulent8Span()
            r_turb_s = snext_0
            r_turb_t = tnext_0
            if (count_1 <= 0) {
                break
            }
        }
        pspan_1 = int(uint(c2da_mem[pspan_1 + 16]) | uint(c2da_mem[pspan_1 + 17]) << 0x8 | uint(c2da_mem[pspan_1 + 18]) << 0x10 | uint(c2da_mem[pspan_1 + 19]) << 0x18)
        if (pspan_1 == 0) {
            break
        }
    }
    return
}
var r_turb_t : int = default<int>

var r_turb_s : int = default<int>

[export, sideeffects]
def D_DrawTurbulent8Span() {
    var sturb : int
    var tturb : int
    while (true) {
        let c2da_fresh32 : int = r_turb_turb + (r_turb_t >> 16 & 128 - 1) * 4
        sturb = r_turb_s + int(uint(c2da_mem[c2da_fresh32]) | uint(c2da_mem[c2da_fresh32 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh32 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh32 + 3]) << 0x18) >> 16 & 63
        let c2da_fresh33 : int = r_turb_turb + (r_turb_s >> 16 & 128 - 1) * 4
        tturb = r_turb_t + int(uint(c2da_mem[c2da_fresh33]) | uint(c2da_mem[c2da_fresh33 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh33 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh33 + 3]) << 0x18) >> 16 & 63
        let c2da_fresh34 : int = r_turb_pdest
        r_turb_pdest++
        let c2da_fresh35 : int = r_turb_pbase + (tturb << 6) + sturb
        let c2da_fresh36 : uint8 = c2da_mem[c2da_fresh35]
        c2da_mem[c2da_fresh34] = c2da_fresh36
        r_turb_s += r_turb_sstep
        r_turb_t += r_turb_tstep
        r_turb_spancount--
        if (r_turb_spancount <= 0) {
            break
        }
    }
    return
}
var r_turb_spancount : int = default<int>

var r_turb_tstep : int = default<int>

var r_turb_sstep : int = default<int>

var r_turb_pbase : int = default<int>

var r_turb_pdest : int = default<int>

var r_turb_turb : int = default<int>

[sideeffects]
def private D_WarpScreen_c2da_frame(c2da_fp : int) {
    var w : int
    var h : int
    var u : int
    var v : int
    var dest : int
    var turb : int
    var col : int
    var row : int
    var wratio : float
    var hratio : float
    w = int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18)
    h = int(uint(c2da_mem[5212]) | uint(c2da_mem[5213]) << 0x8 | uint(c2da_mem[5214]) << 0x10 | uint(c2da_mem[5215]) << 0x18)
    wratio = float(w) / float(int(uint(c2da_mem[462520]) | uint(c2da_mem[462521]) << 0x8 | uint(c2da_mem[462522]) << 0x10 | uint(c2da_mem[462523]) << 0x18))
    hratio = float(h) / float(int(uint(c2da_mem[462524]) | uint(c2da_mem[462525]) << 0x8 | uint(c2da_mem[462526]) << 0x10 | uint(c2da_mem[462527]) << 0x18))
    v = 0
    while (v < int(uint(c2da_mem[462524]) | uint(c2da_mem[462525]) << 0x8 | uint(c2da_mem[462526]) << 0x10 | uint(c2da_mem[462527]) << 0x18) + 3 * 2) {
        let c2da_fresh0 : int = d_viewbuffer + int(uint(c2da_mem[5204]) | uint(c2da_mem[5205]) << 0x8 | uint(c2da_mem[5206]) << 0x10 | uint(c2da_mem[5207]) << 0x18) * screenwidth + int(screenwidth * int(float(v) * hratio * float(h) / float(h + 3 * 2)))
        let c2da_fresh1 : uint = uint(c2da_fresh0)
        c2da_mem[c2da_fp + 5152 + v * 8] = uint8(c2da_fresh1)
        c2da_mem[c2da_fp + 5152 + v * 8 + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[c2da_fp + 5152 + v * 8 + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[c2da_fp + 5152 + v * 8 + 3] = uint8(c2da_fresh1 >> 0x18)
        c2da_mem[c2da_fp + 5152 + v * 8 + 4] = 0u8
        c2da_mem[c2da_fp + 5152 + v * 8 + 5] = 0u8
        c2da_mem[c2da_fp + 5152 + v * 8 + 6] = 0u8
        c2da_mem[c2da_fp + 5152 + v * 8 + 7] = 0u8
        v++
    }
    u = 0
    while (u < int(uint(c2da_mem[462520]) | uint(c2da_mem[462521]) << 0x8 | uint(c2da_mem[462522]) << 0x10 | uint(c2da_mem[462523]) << 0x18) + 3 * 2) {
        let c2da_fresh2 : int = int(uint(c2da_mem[5200]) | uint(c2da_mem[5201]) << 0x8 | uint(c2da_mem[5202]) << 0x10 | uint(c2da_mem[5203]) << 0x18) + int(float(u) * wratio * float(w) / float(w + 3 * 2))
        let c2da_fresh3 : uint = uint(c2da_fresh2)
        c2da_mem[c2da_fp + u * 4] = uint8(c2da_fresh3)
        c2da_mem[c2da_fp + u * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[c2da_fp + u * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[c2da_fp + u * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
        u++
    }
    turb = 205312 + (int(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) * 20.0lf) & 128 - 1) * 4
    dest = vid.buffer + int(uint(int(uint(c2da_mem[462516]) | uint(c2da_mem[462517]) << 0x8 | uint(c2da_mem[462518]) << 0x10 | uint(c2da_mem[462519]) << 0x18)) * vid.rowbytes) + int(uint(c2da_mem[462512]) | uint(c2da_mem[462513]) << 0x8 | uint(c2da_mem[462514]) << 0x10 | uint(c2da_mem[462515]) << 0x18)
    v = 0
    while (v < int(uint(c2da_mem[462524]) | uint(c2da_mem[462525]) << 0x8 | uint(c2da_mem[462526]) << 0x10 | uint(c2da_mem[462527]) << 0x18)) {
        col = c2da_fp + int(uint(c2da_mem[turb + v * 4]) | uint(c2da_mem[turb + v * 4 + 1]) << 0x8 | uint(c2da_mem[turb + v * 4 + 2]) << 0x10 | uint(c2da_mem[turb + v * 4 + 3]) << 0x18) * 4
        row = c2da_fp + 5152 + v * 8
        u = 0
        while (u < int(uint(c2da_mem[462520]) | uint(c2da_mem[462521]) << 0x8 | uint(c2da_mem[462522]) << 0x10 | uint(c2da_mem[462523]) << 0x18)) {
            let c2da_fresh4 : int = row + int(uint(c2da_mem[turb + (u + 0) * 4]) | uint(c2da_mem[turb + (u + 0) * 4 + 1]) << 0x8 | uint(c2da_mem[turb + (u + 0) * 4 + 2]) << 0x10 | uint(c2da_mem[turb + (u + 0) * 4 + 3]) << 0x18) * 8
            let c2da_fresh5 : int = int(uint(c2da_mem[c2da_fresh4]) | uint(c2da_mem[c2da_fresh4 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh4 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh4 + 3]) << 0x18) + int(uint(c2da_mem[col + (u + 0) * 4]) | uint(c2da_mem[col + (u + 0) * 4 + 1]) << 0x8 | uint(c2da_mem[col + (u + 0) * 4 + 2]) << 0x10 | uint(c2da_mem[col + (u + 0) * 4 + 3]) << 0x18)
            let c2da_fresh6 : uint8 = c2da_mem[c2da_fresh5]
            c2da_mem[dest + (u + 0)] = c2da_fresh6
            let c2da_fresh7 : int = row + int(uint(c2da_mem[turb + (u + 1) * 4]) | uint(c2da_mem[turb + (u + 1) * 4 + 1]) << 0x8 | uint(c2da_mem[turb + (u + 1) * 4 + 2]) << 0x10 | uint(c2da_mem[turb + (u + 1) * 4 + 3]) << 0x18) * 8
            let c2da_fresh8 : int = int(uint(c2da_mem[c2da_fresh7]) | uint(c2da_mem[c2da_fresh7 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh7 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh7 + 3]) << 0x18) + int(uint(c2da_mem[col + (u + 1) * 4]) | uint(c2da_mem[col + (u + 1) * 4 + 1]) << 0x8 | uint(c2da_mem[col + (u + 1) * 4 + 2]) << 0x10 | uint(c2da_mem[col + (u + 1) * 4 + 3]) << 0x18)
            let c2da_fresh9 : uint8 = c2da_mem[c2da_fresh8]
            c2da_mem[dest + (u + 1)] = c2da_fresh9
            let c2da_fresh10 : int = row + int(uint(c2da_mem[turb + (u + 2) * 4]) | uint(c2da_mem[turb + (u + 2) * 4 + 1]) << 0x8 | uint(c2da_mem[turb + (u + 2) * 4 + 2]) << 0x10 | uint(c2da_mem[turb + (u + 2) * 4 + 3]) << 0x18) * 8
            let c2da_fresh11 : int = int(uint(c2da_mem[c2da_fresh10]) | uint(c2da_mem[c2da_fresh10 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh10 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh10 + 3]) << 0x18) + int(uint(c2da_mem[col + (u + 2) * 4]) | uint(c2da_mem[col + (u + 2) * 4 + 1]) << 0x8 | uint(c2da_mem[col + (u + 2) * 4 + 2]) << 0x10 | uint(c2da_mem[col + (u + 2) * 4 + 3]) << 0x18)
            let c2da_fresh12 : uint8 = c2da_mem[c2da_fresh11]
            c2da_mem[dest + (u + 2)] = c2da_fresh12
            let c2da_fresh13 : int = row + int(uint(c2da_mem[turb + (u + 3) * 4]) | uint(c2da_mem[turb + (u + 3) * 4 + 1]) << 0x8 | uint(c2da_mem[turb + (u + 3) * 4 + 2]) << 0x10 | uint(c2da_mem[turb + (u + 3) * 4 + 3]) << 0x18) * 8
            let c2da_fresh14 : int = int(uint(c2da_mem[c2da_fresh13]) | uint(c2da_mem[c2da_fresh13 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh13 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh13 + 3]) << 0x18) + int(uint(c2da_mem[col + (u + 3) * 4]) | uint(c2da_mem[col + (u + 3) * 4 + 1]) << 0x8 | uint(c2da_mem[col + (u + 3) * 4 + 2]) << 0x10 | uint(c2da_mem[col + (u + 3) * 4 + 3]) << 0x18)
            let c2da_fresh15 : uint8 = c2da_mem[c2da_fresh14]
            c2da_mem[dest + (u + 3)] = c2da_fresh15
            u += 4
        }
        v++
        dest += int(vid.rowbytes)
    }
    return
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_d_scan() {
    if (length(c2da_fn_table5) < 60) {
        resize(c2da_fn_table5, 60)
    }
    c2da_fn_table5[59] = @@D_DrawSpans8
}

[init]
def private c2da_lin_relink_init_d_scan() {
    c2da_relink_d_scan()
}
