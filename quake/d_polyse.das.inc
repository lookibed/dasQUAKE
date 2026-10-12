[export, sideeffects]
def D_PolysetDraw() {
    var spans : spanpackage_t[1027]
    a_spans = unsafe(reinterpret<spanpackage_t?>(unsafe(reinterpret<spanpackage_t?>(uint64(int64(unsafe(reinterpret<uint64>(unsafe(addr(unsafe(unsafe(addr(spans[0]))[0])))))) + 32l - 1l & int64(~(32 - 1)))))))
    if (r_affinetridesc.drawtype != 0) {
        D_DrawSubdiv()
    } else {
        D_DrawNonSubdiv()
    }
    return
}
[export, sideeffects]
def D_DrawNonSubdiv() {
    var ptri : mtriangle_s?
    var pfv : finalvert_s?
    var index0 : finalvert_s?
    var index1 : finalvert_s?
    var index2 : finalvert_s?
    var i : int
    var lnumtriangles : int
    pfv = unsafe(reinterpret<finalvert_s?>(r_affinetridesc.pfinalverts))
    ptri = unsafe(reinterpret<mtriangle_s?>(r_affinetridesc.ptriangles))
    lnumtriangles = r_affinetridesc.numtriangles
    var c2da_ptri_addr : uint64 = unsafe(reinterpret<uint64>(ptri))
    i = 0
    while (i < lnumtriangles) {
        var c2da_fresh0 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<mtriangle_s?>(c2da_ptri_addr)))) + 4ul))
        index0 = unsafe(reinterpret<finalvert_s?>(unsafe(pfv + int64(unsafe(unsafe(reinterpret<int?>(c2da_fresh0))[0])))))
        var c2da_fresh1 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<mtriangle_s?>(c2da_ptri_addr)))) + 4ul))
        index1 = unsafe(reinterpret<finalvert_s?>(unsafe(pfv + int64(unsafe(unsafe(reinterpret<int?>(c2da_fresh1))[1])))))
        var c2da_fresh2 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<mtriangle_s?>(c2da_ptri_addr)))) + 4ul))
        index2 = unsafe(reinterpret<finalvert_s?>(unsafe(pfv + int64(unsafe(unsafe(reinterpret<int?>(c2da_fresh2))[2])))))
        var c2da_fresh3 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0))))
        var c2da_fresh4 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1))))
        var c2da_fresh5 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0))))
        var c2da_fresh6 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2))))
        var c2da_fresh7 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0))))
        var c2da_fresh8 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1))))
        var c2da_fresh9 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0))))
        var c2da_fresh10 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2))))
        d_xdenom = (unsafe(unsafe(reinterpret<int?>(c2da_fresh3))[1]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh4))[1])) * (unsafe(unsafe(reinterpret<int?>(c2da_fresh5))[0]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh6))[0])) - (unsafe(unsafe(reinterpret<int?>(c2da_fresh7))[0]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh8))[0])) * (unsafe(unsafe(reinterpret<int?>(c2da_fresh9))[1]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh10))[1]))
        if (d_xdenom >= 0) {
            i++
            c2da_ptri_addr += 16ul
            continue
        }
        var c2da_fresh11 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0))))
        r_p0[0] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh11))[0]))  // nolint:PERF020
        var c2da_fresh12 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0))))
        r_p0[1] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh12))[1]))  // nolint:PERF020
        var c2da_fresh13 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0))))
        r_p0[2] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh13))[2]))  // nolint:PERF020
        var c2da_fresh14 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0))))
        r_p0[3] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh14))[3]))  // nolint:PERF020
        var c2da_fresh15 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0))))
        r_p0[4] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh15))[4]))  // nolint:PERF020
        var c2da_fresh16 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0))))
        r_p0[5] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh16))[5]))  // nolint:PERF020
        var c2da_fresh17 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1))))
        r_p1[0] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh17))[0]))  // nolint:PERF020
        var c2da_fresh18 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1))))
        r_p1[1] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh18))[1]))  // nolint:PERF020
        var c2da_fresh19 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1))))
        r_p1[2] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh19))[2]))  // nolint:PERF020
        var c2da_fresh20 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1))))
        r_p1[3] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh20))[3]))  // nolint:PERF020
        var c2da_fresh21 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1))))
        r_p1[4] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh21))[4]))  // nolint:PERF020
        var c2da_fresh22 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1))))
        r_p1[5] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh22))[5]))  // nolint:PERF020
        var c2da_fresh23 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2))))
        r_p2[0] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh23))[0]))  // nolint:PERF020
        var c2da_fresh24 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2))))
        r_p2[1] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh24))[1]))  // nolint:PERF020
        var c2da_fresh25 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2))))
        r_p2[2] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh25))[2]))  // nolint:PERF020
        var c2da_fresh26 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2))))
        r_p2[3] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh26))[3]))  // nolint:PERF020
        var c2da_fresh27 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2))))
        r_p2[4] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh27))[4]))  // nolint:PERF020
        var c2da_fresh28 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2))))
        r_p2[5] = int(unsafe(unsafe(reinterpret<int?>(c2da_fresh28))[5]))  // nolint:PERF020
        if (unsafe(reinterpret<mtriangle_s?>(c2da_ptri_addr)).facesfront == 0) {
            if ((index0.flags & 32) != 0) {
                r_p0[2] = r_p0[2] + r_affinetridesc.seamfixupX16
            }
            if ((index1.flags & 32) != 0) {
                r_p1[2] = r_p1[2] + r_affinetridesc.seamfixupX16
            }
            if ((index2.flags & 32) != 0) {
                r_p2[2] = r_p2[2] + r_affinetridesc.seamfixupX16
            }
        }
        D_PolysetSetEdgeTable()
        D_RasterizeAliasPolySmooth()
        i++
        c2da_ptri_addr += 16ul
    }
    return
}
[export, sideeffects]
def D_RasterizeAliasPolySmooth() {
    var initialleftheight : int
    var initialrightheight : int
    var plefttop : int?
    var prighttop : int?
    var pleftbottom : int?
    var prightbottom : int?
    var working_lstepx : int
    var originalcount : int
    var height : int
    var height_0 : int
    var pstart : spanpackage_t?
    plefttop = unsafe(reinterpret<int?>(pedgetable.pleftedgevert0))
    prighttop = unsafe(reinterpret<int?>(pedgetable.prightedgevert0))
    pleftbottom = unsafe(reinterpret<int?>(pedgetable.pleftedgevert1))
    prightbottom = unsafe(reinterpret<int?>(pedgetable.prightedgevert1))
    initialleftheight = unsafe(pleftbottom[1]) - unsafe(plefttop[1])
    initialrightheight = unsafe(prightbottom[1]) - unsafe(prighttop[1])
    D_PolysetCalcGradients(r_affinetridesc.skinwidth)
    d_pedgespanpackage = unsafe(reinterpret<spanpackage_t?>(a_spans))
    ystart = int(unsafe(plefttop[1]))  // nolint:PERF020
    d_aspancount = unsafe(plefttop[0]) - unsafe(prighttop[0])
    d_ptex = unsafe(reinterpret<uint8?>(unsafe(unsafe(r_affinetridesc.pskin + int64(unsafe(plefttop[2]) >> 16)) + int64((unsafe(plefttop[3]) >> 16) * r_affinetridesc.skinwidth))))
    d_sfrac = unsafe(plefttop[2]) & 65535
    d_tfrac = unsafe(plefttop[3]) & 65535
    d_light = int(unsafe(plefttop[4]))  // nolint:PERF020
    d_zi = int(unsafe(plefttop[5]))  // nolint:PERF020
    d_pdest = unsafe(reinterpret<uint8?>(unsafe(unsafe(d_viewbuffer + int64(ystart * screenwidth)) + int64(unsafe(plefttop[0])))))
    d_pz = unsafe(reinterpret<int16?>(unsafe(unsafe(d_pzbuffer + int64(uint(ystart) * d_zwidth)) + int64(unsafe(plefttop[0])))))
    if (initialleftheight == 1) {
        d_pedgespanpackage.pdest = unsafe(reinterpret<uint8?>(d_pdest))
        d_pedgespanpackage.pz = d_pz
        d_pedgespanpackage.count = int(d_aspancount)  // nolint:PERF020
        d_pedgespanpackage.ptex = d_ptex
        d_pedgespanpackage.sfrac = int(d_sfrac)  // nolint:PERF020
        d_pedgespanpackage.tfrac = int(d_tfrac)  // nolint:PERF020
        d_pedgespanpackage.light = int(d_light)  // nolint:PERF020
        d_pedgespanpackage.zi = int(d_zi)  // nolint:PERF020
        unsafe {  // nolint:STYLE025
            d_pedgespanpackage += 1
        }
    } else {
        D_PolysetSetUpForLineScan(unsafe(plefttop[0]), unsafe(plefttop[1]), unsafe(pleftbottom[0]), unsafe(pleftbottom[1]))
        d_pzbasestep = int(d_zwidth + uint(ubasestep))
        d_pzextrastep = d_pzbasestep + 1
        d_pdestbasestep = screenwidth + ubasestep
        d_pdestextrastep = d_pdestbasestep + 1
        if (ubasestep < 0) {
            working_lstepx = r_lstepx - 1
        } else {
            working_lstepx = r_lstepx
        }
        d_countextrastep = ubasestep + 1
        d_ptexbasestep = (r_sstepy + r_sstepx * ubasestep >> 16) + (r_tstepy + r_tstepx * ubasestep >> 16) * r_affinetridesc.skinwidth
        d_sfracbasestep = r_sstepy + r_sstepx * ubasestep & 65535
        d_tfracbasestep = r_tstepy + r_tstepx * ubasestep & 65535
        d_lightbasestep = r_lstepy + working_lstepx * ubasestep
        d_zibasestep = r_zistepy + r_zistepx * ubasestep
        d_ptexextrastep = (r_sstepy + r_sstepx * d_countextrastep >> 16) + (r_tstepy + r_tstepx * d_countextrastep >> 16) * r_affinetridesc.skinwidth
        d_sfracextrastep = r_sstepy + r_sstepx * d_countextrastep & 65535
        d_tfracextrastep = r_tstepy + r_tstepx * d_countextrastep & 65535
        d_lightextrastep = d_lightbasestep + working_lstepx
        d_ziextrastep = d_zibasestep + r_zistepx
        D_PolysetScanLeftEdge(initialleftheight)
    }
    if (pedgetable.numleftedges == 2) {
        plefttop = unsafe(reinterpret<int?>(pleftbottom))
        pleftbottom = unsafe(reinterpret<int?>(pedgetable.pleftedgevert2))
        height = unsafe(pleftbottom[1]) - unsafe(plefttop[1])
        ystart = int(unsafe(plefttop[1]))  // nolint:PERF020
        d_aspancount = unsafe(plefttop[0]) - unsafe(prighttop[0])
        d_ptex = unsafe(reinterpret<uint8?>(unsafe(unsafe(r_affinetridesc.pskin + int64(unsafe(plefttop[2]) >> 16)) + int64((unsafe(plefttop[3]) >> 16) * r_affinetridesc.skinwidth))))
        d_sfrac = 0
        d_tfrac = 0
        d_light = int(unsafe(plefttop[4]))  // nolint:PERF020
        d_zi = int(unsafe(plefttop[5]))  // nolint:PERF020
        d_pdest = unsafe(reinterpret<uint8?>(unsafe(unsafe(d_viewbuffer + int64(ystart * screenwidth)) + int64(unsafe(plefttop[0])))))
        d_pz = unsafe(reinterpret<int16?>(unsafe(unsafe(d_pzbuffer + int64(uint(ystart) * d_zwidth)) + int64(unsafe(plefttop[0])))))
        if (height == 1) {
            d_pedgespanpackage.pdest = unsafe(reinterpret<uint8?>(d_pdest))
            d_pedgespanpackage.pz = d_pz
            d_pedgespanpackage.count = int(d_aspancount)  // nolint:PERF020
            d_pedgespanpackage.ptex = d_ptex
            d_pedgespanpackage.sfrac = int(d_sfrac)  // nolint:PERF020
            d_pedgespanpackage.tfrac = int(d_tfrac)  // nolint:PERF020
            d_pedgespanpackage.light = int(d_light)  // nolint:PERF020
            d_pedgespanpackage.zi = int(d_zi)  // nolint:PERF020
            unsafe {  // nolint:STYLE025
                d_pedgespanpackage += 1
            }
        } else {
            D_PolysetSetUpForLineScan(unsafe(plefttop[0]), unsafe(plefttop[1]), unsafe(pleftbottom[0]), unsafe(pleftbottom[1]))
            d_pdestbasestep = screenwidth + ubasestep
            d_pdestextrastep = d_pdestbasestep + 1
            d_pzbasestep = int(d_zwidth + uint(ubasestep))
            d_pzextrastep = d_pzbasestep + 1
            if (ubasestep < 0) {
                working_lstepx = r_lstepx - 1
            } else {
                working_lstepx = r_lstepx
            }
            d_countextrastep = ubasestep + 1
            d_ptexbasestep = (r_sstepy + r_sstepx * ubasestep >> 16) + (r_tstepy + r_tstepx * ubasestep >> 16) * r_affinetridesc.skinwidth
            d_sfracbasestep = r_sstepy + r_sstepx * ubasestep & 65535
            d_tfracbasestep = r_tstepy + r_tstepx * ubasestep & 65535
            d_lightbasestep = r_lstepy + working_lstepx * ubasestep
            d_zibasestep = r_zistepy + r_zistepx * ubasestep
            d_ptexextrastep = (r_sstepy + r_sstepx * d_countextrastep >> 16) + (r_tstepy + r_tstepx * d_countextrastep >> 16) * r_affinetridesc.skinwidth
            d_sfracextrastep = r_sstepy + r_sstepx * d_countextrastep & 65535
            d_tfracextrastep = r_tstepy + r_tstepx * d_countextrastep & 65535
            d_lightextrastep = d_lightbasestep + working_lstepx
            d_ziextrastep = d_zibasestep + r_zistepx
            D_PolysetScanLeftEdge(height)
        }
    }
    d_pedgespanpackage = unsafe(reinterpret<spanpackage_t?>(a_spans))
    D_PolysetSetUpForLineScan(unsafe(prighttop[0]), unsafe(prighttop[1]), unsafe(prightbottom[0]), unsafe(prightbottom[1]))
    d_aspancount = 0
    d_countextrastep = ubasestep + 1
    originalcount = unsafe(a_spans[initialrightheight]).count
    unsafe(a_spans[initialrightheight]).count = -999999
    D_PolysetDrawSpans8(a_spans)
    if (pedgetable.numrightedges == 2) {
        pstart = unsafe(reinterpret<spanpackage_t?>(unsafe(a_spans + initialrightheight)))
        pstart.count = originalcount
        d_aspancount = unsafe(prightbottom[0]) - unsafe(prighttop[0])
        prighttop = unsafe(reinterpret<int?>(prightbottom))
        prightbottom = unsafe(reinterpret<int?>(pedgetable.prightedgevert2))
        height_0 = unsafe(prightbottom[1]) - unsafe(prighttop[1])
        D_PolysetSetUpForLineScan(unsafe(prighttop[0]), unsafe(prighttop[1]), unsafe(prightbottom[0]), unsafe(prightbottom[1]))
        d_countextrastep = ubasestep + 1
        unsafe(a_spans[initialrightheight + height_0]).count = -999999
        D_PolysetDrawSpans8(pstart)
    }
    return
}
[export, sideeffects]
def D_PolysetDrawSpans8(var pspanpackage : spanpackage_t?) {
    var lcount : int
    var lpdest : uint8?
    var lptex : uint8?
    var lsfrac : int
    var ltfrac : int
    var llight : int
    var lzi : int
    var lpz : int16?
    var c2da_pspanpackage_addr : uint64 = unsafe(reinterpret<uint64>(pspanpackage))
    while (true) {
        lcount = d_aspancount - unsafe(reinterpret<spanpackage_t?>(c2da_pspanpackage_addr)).count
        errorterm = errorterm + erroradjustup
        if (errorterm >= 0) {
            d_aspancount += d_countextrastep
            errorterm = errorterm - erroradjustdown
        } else {
            d_aspancount = d_aspancount + ubasestep
        }
        if (lcount != 0) {
            lpdest = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(unsafe(reinterpret<spanpackage_t?>(c2da_pspanpackage_addr)).pdest))))
            lptex = unsafe(reinterpret<uint8?>(unsafe(reinterpret<spanpackage_t?>(c2da_pspanpackage_addr)).ptex))
            lpz = unsafe(reinterpret<int16?>(unsafe(reinterpret<spanpackage_t?>(c2da_pspanpackage_addr)).pz))
            lsfrac = unsafe(reinterpret<spanpackage_t?>(c2da_pspanpackage_addr)).sfrac
            ltfrac = unsafe(reinterpret<spanpackage_t?>(c2da_pspanpackage_addr)).tfrac
            llight = unsafe(reinterpret<spanpackage_t?>(c2da_pspanpackage_addr)).light
            lzi = unsafe(reinterpret<spanpackage_t?>(c2da_pspanpackage_addr)).zi
            var c2da_lpdest_addr : uint64 = unsafe(reinterpret<uint64>(lpdest))
            var c2da_lpz_addr : uint64 = unsafe(reinterpret<uint64>(lpz))
            while (true) {
                if (lzi >> 16 >= int(*unsafe(reinterpret<int16?>(c2da_lpz_addr)))) {
                    *unsafe(reinterpret<uint8?>(c2da_lpdest_addr)) = uint8(unsafe(unsafe(reinterpret<uint8?>(acolormap))[int(*lptex) + (llight & 65280)]))  // nolint:PERF020
                    *unsafe(reinterpret<int16?>(c2da_lpz_addr)) = int16(lzi >> 16)
                }
                c2da_lpdest_addr++
                lzi += r_zistepx
                c2da_lpz_addr += 2ul
                llight += r_lstepx
                unsafe {  // nolint:STYLE025
                    lptex += int64(a_ststepxwhole)
                }
                lsfrac += a_sstepxfrac
                unsafe {  // nolint:STYLE025
                    lptex += int64(lsfrac >> 16)
                }
                lsfrac &= 65535
                ltfrac += a_tstepxfrac
                if ((ltfrac & 65536) != 0) {
                    unsafe {  // nolint:STYLE025
                        lptex += int64(r_affinetridesc.skinwidth)
                    }
                    ltfrac &= 65535
                }
                lcount--
                if (lcount == 0) {
                    break
                }
            }
            lpdest = unsafe(reinterpret<uint8?>(c2da_lpdest_addr))
            lpz = unsafe(reinterpret<int16?>(c2da_lpz_addr))
        }
        c2da_pspanpackage_addr += 48ul
        if (unsafe(reinterpret<spanpackage_t?>(c2da_pspanpackage_addr)).count == -999999) {
            break
        }
    }
    return
}
var a_tstepxfrac : int = default<int>

var a_sstepxfrac : int = default<int>

var a_ststepxwhole : int = default<int>

var r_lstepx : int = default<int>

var r_zistepx : int = default<int>

var d_aspancount : int = default<int>

var d_countextrastep : int = default<int>

var a_spans : spanpackage_t? = default<spanpackage_t?>

[export, sideeffects]
def D_PolysetSetUpForLineScan(var startvertu : int; var startvertv : int; var endvertu : int; var endvertv : int) {
    var dn : double
    var tm : int
    var tn : int
    var ptemp : adivtab_t?
    errorterm = -1
    tm = endvertu - startvertu
    tn = endvertv - startvertv
    if (tm <= 16 && tm >= -15 && (tn <= 16 && tn >= -15)) {
        ptemp = unsafe(addr<adivtab_t?>(unsafe(unsafe(addr(adivtab[0]))[(tm + 15 << 5) + (tn + 15)])))
        ubasestep = ptemp.quotient
        erroradjustup = ptemp.remainder
        erroradjustdown = tn
    } else {
        dn = double(tn)
        FloorDivMod(double(tm), dn, unsafe(addr<int?>(ubasestep)), unsafe(addr<int?>(erroradjustup)))
        erroradjustdown = int(dn)
    }
    return
}
var private adivtab : adivtab_t[1024] = fixed_array<adivtab_t>(adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 1, remainder = -1), adivtab_t(quotient = 1, remainder = -2), adivtab_t(quotient = 1, remainder = -3), adivtab_t(quotient = 1, remainder = -4), adivtab_t(quotient = 1, remainder = -5), adivtab_t(quotient = 1, remainder = -6), adivtab_t(quotient = 1, remainder = -7), adivtab_t(quotient = 2, remainder = -1), adivtab_t(quotient = 2, remainder = -3), adivtab_t(quotient = 3, remainder = 0), adivtab_t(quotient = 3, remainder = -3), adivtab_t(quotient = 5, remainder = 0), adivtab_t(quotient = 7, remainder = -1), adivtab_t(quotient = 15, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -15, remainder = 0), adivtab_t(quotient = -8, remainder = 1), adivtab_t(quotient = -5, remainder = 0), adivtab_t(quotient = -4, remainder = 1), adivtab_t(quotient = -3, remainder = 0), adivtab_t(quotient = -3, remainder = 3), adivtab_t(quotient = -3, remainder = 6), adivtab_t(quotient = -2, remainder = 1), adivtab_t(quotient = -2, remainder = 3), adivtab_t(quotient = -2, remainder = 5), adivtab_t(quotient = -2, remainder = 7), adivtab_t(quotient = -2, remainder = 9), adivtab_t(quotient = -2, remainder = 11), adivtab_t(quotient = -2, remainder = 13), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = 0, remainder = -14), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 1, remainder = -1), adivtab_t(quotient = 1, remainder = -2), adivtab_t(quotient = 1, remainder = -3), adivtab_t(quotient = 1, remainder = -4), adivtab_t(quotient = 1, remainder = -5), adivtab_t(quotient = 1, remainder = -6), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 2, remainder = -2), adivtab_t(quotient = 2, remainder = -4), adivtab_t(quotient = 3, remainder = -2), adivtab_t(quotient = 4, remainder = -2), adivtab_t(quotient = 7, remainder = 0), adivtab_t(quotient = 14, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -14, remainder = 0), adivtab_t(quotient = -7, remainder = 0), adivtab_t(quotient = -5, remainder = 1), adivtab_t(quotient = -4, remainder = 2), adivtab_t(quotient = -3, remainder = 1), adivtab_t(quotient = -3, remainder = 4), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = -2, remainder = 2), adivtab_t(quotient = -2, remainder = 4), adivtab_t(quotient = -2, remainder = 6), adivtab_t(quotient = -2, remainder = 8), adivtab_t(quotient = -2, remainder = 10), adivtab_t(quotient = -2, remainder = 12), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = -1, remainder = 2), adivtab_t(quotient = 0, remainder = -13), adivtab_t(quotient = 0, remainder = -13), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 1, remainder = -1), adivtab_t(quotient = 1, remainder = -2), adivtab_t(quotient = 1, remainder = -3), adivtab_t(quotient = 1, remainder = -4), adivtab_t(quotient = 1, remainder = -5), adivtab_t(quotient = 1, remainder = -6), adivtab_t(quotient = 2, remainder = -1), adivtab_t(quotient = 2, remainder = -3), adivtab_t(quotient = 3, remainder = -1), adivtab_t(quotient = 4, remainder = -1), adivtab_t(quotient = 6, remainder = -1), adivtab_t(quotient = 13, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -13, remainder = 0), adivtab_t(quotient = -7, remainder = 1), adivtab_t(quotient = -5, remainder = 2), adivtab_t(quotient = -4, remainder = 3), adivtab_t(quotient = -3, remainder = 2), adivtab_t(quotient = -3, remainder = 5), adivtab_t(quotient = -2, remainder = 1), adivtab_t(quotient = -2, remainder = 3), adivtab_t(quotient = -2, remainder = 5), adivtab_t(quotient = -2, remainder = 7), adivtab_t(quotient = -2, remainder = 9), adivtab_t(quotient = -2, remainder = 11), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = -1, remainder = 2), adivtab_t(quotient = -1, remainder = 3), adivtab_t(quotient = 0, remainder = -12), adivtab_t(quotient = 0, remainder = -12), adivtab_t(quotient = 0, remainder = -12), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 1, remainder = -1), adivtab_t(quotient = 1, remainder = -2), adivtab_t(quotient = 1, remainder = -3), adivtab_t(quotient = 1, remainder = -4), adivtab_t(quotient = 1, remainder = -5), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 2, remainder = -2), adivtab_t(quotient = 3, remainder = 0), adivtab_t(quotient = 4, remainder = 0), adivtab_t(quotient = 6, remainder = 0), adivtab_t(quotient = 12, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -12, remainder = 0), adivtab_t(quotient = -6, remainder = 0), adivtab_t(quotient = -4, remainder = 0), adivtab_t(quotient = -3, remainder = 0), adivtab_t(quotient = -3, remainder = 3), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = -2, remainder = 2), adivtab_t(quotient = -2, remainder = 4), adivtab_t(quotient = -2, remainder = 6), adivtab_t(quotient = -2, remainder = 8), adivtab_t(quotient = -2, remainder = 10), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = -1, remainder = 2), adivtab_t(quotient = -1, remainder = 3), adivtab_t(quotient = -1, remainder = 4), adivtab_t(quotient = 0, remainder = -11), adivtab_t(quotient = 0, remainder = -11), adivtab_t(quotient = 0, remainder = -11), adivtab_t(quotient = 0, remainder = -11), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 1, remainder = -1), adivtab_t(quotient = 1, remainder = -2), adivtab_t(quotient = 1, remainder = -3), adivtab_t(quotient = 1, remainder = -4), adivtab_t(quotient = 1, remainder = -5), adivtab_t(quotient = 2, remainder = -1), adivtab_t(quotient = 2, remainder = -3), adivtab_t(quotient = 3, remainder = -2), adivtab_t(quotient = 5, remainder = -1), adivtab_t(quotient = 11, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -11, remainder = 0), adivtab_t(quotient = -6, remainder = 1), adivtab_t(quotient = -4, remainder = 1), adivtab_t(quotient = -3, remainder = 1), adivtab_t(quotient = -3, remainder = 4), adivtab_t(quotient = -2, remainder = 1), adivtab_t(quotient = -2, remainder = 3), adivtab_t(quotient = -2, remainder = 5), adivtab_t(quotient = -2, remainder = 7), adivtab_t(quotient = -2, remainder = 9), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = -1, remainder = 2), adivtab_t(quotient = -1, remainder = 3), adivtab_t(quotient = -1, remainder = 4), adivtab_t(quotient = -1, remainder = 5), adivtab_t(quotient = 0, remainder = -10), adivtab_t(quotient = 0, remainder = -10), adivtab_t(quotient = 0, remainder = -10), adivtab_t(quotient = 0, remainder = -10), adivtab_t(quotient = 0, remainder = -10), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 1, remainder = -1), adivtab_t(quotient = 1, remainder = -2), adivtab_t(quotient = 1, remainder = -3), adivtab_t(quotient = 1, remainder = -4), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 2, remainder = -2), adivtab_t(quotient = 3, remainder = -1), adivtab_t(quotient = 5, remainder = 0), adivtab_t(quotient = 10, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -10, remainder = 0), adivtab_t(quotient = -5, remainder = 0), adivtab_t(quotient = -4, remainder = 2), adivtab_t(quotient = -3, remainder = 2), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = -2, remainder = 2), adivtab_t(quotient = -2, remainder = 4), adivtab_t(quotient = -2, remainder = 6), adivtab_t(quotient = -2, remainder = 8), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = -1, remainder = 2), adivtab_t(quotient = -1, remainder = 3), adivtab_t(quotient = -1, remainder = 4), adivtab_t(quotient = -1, remainder = 5), adivtab_t(quotient = -1, remainder = 6), adivtab_t(quotient = 0, remainder = -9), adivtab_t(quotient = 0, remainder = -9), adivtab_t(quotient = 0, remainder = -9), adivtab_t(quotient = 0, remainder = -9), adivtab_t(quotient = 0, remainder = -9), adivtab_t(quotient = 0, remainder = -9), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 1, remainder = -1), adivtab_t(quotient = 1, remainder = -2), adivtab_t(quotient = 1, remainder = -3), adivtab_t(quotient = 1, remainder = -4), adivtab_t(quotient = 2, remainder = -1), adivtab_t(quotient = 3, remainder = 0), adivtab_t(quotient = 4, remainder = -1), adivtab_t(quotient = 9, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -9, remainder = 0), adivtab_t(quotient = -5, remainder = 1), adivtab_t(quotient = -3, remainder = 0), adivtab_t(quotient = -3, remainder = 3), adivtab_t(quotient = -2, remainder = 1), adivtab_t(quotient = -2, remainder = 3), adivtab_t(quotient = -2, remainder = 5), adivtab_t(quotient = -2, remainder = 7), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = -1, remainder = 2), adivtab_t(quotient = -1, remainder = 3), adivtab_t(quotient = -1, remainder = 4), adivtab_t(quotient = -1, remainder = 5), adivtab_t(quotient = -1, remainder = 6), adivtab_t(quotient = -1, remainder = 7), adivtab_t(quotient = 0, remainder = -8), adivtab_t(quotient = 0, remainder = -8), adivtab_t(quotient = 0, remainder = -8), adivtab_t(quotient = 0, remainder = -8), adivtab_t(quotient = 0, remainder = -8), adivtab_t(quotient = 0, remainder = -8), adivtab_t(quotient = 0, remainder = -8), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 1, remainder = -1), adivtab_t(quotient = 1, remainder = -2), adivtab_t(quotient = 1, remainder = -3), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 2, remainder = -2), adivtab_t(quotient = 4, remainder = 0), adivtab_t(quotient = 8, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -8, remainder = 0), adivtab_t(quotient = -4, remainder = 0), adivtab_t(quotient = -3, remainder = 1), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = -2, remainder = 2), adivtab_t(quotient = -2, remainder = 4), adivtab_t(quotient = -2, remainder = 6), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = -1, remainder = 2), adivtab_t(quotient = -1, remainder = 3), adivtab_t(quotient = -1, remainder = 4), adivtab_t(quotient = -1, remainder = 5), adivtab_t(quotient = -1, remainder = 6), adivtab_t(quotient = -1, remainder = 7), adivtab_t(quotient = -1, remainder = 8), adivtab_t(quotient = 0, remainder = -7), adivtab_t(quotient = 0, remainder = -7), adivtab_t(quotient = 0, remainder = -7), adivtab_t(quotient = 0, remainder = -7), adivtab_t(quotient = 0, remainder = -7), adivtab_t(quotient = 0, remainder = -7), adivtab_t(quotient = 0, remainder = -7), adivtab_t(quotient = 0, remainder = -7), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 1, remainder = -1), adivtab_t(quotient = 1, remainder = -2), adivtab_t(quotient = 1, remainder = -3), adivtab_t(quotient = 2, remainder = -1), adivtab_t(quotient = 3, remainder = -1), adivtab_t(quotient = 7, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -7, remainder = 0), adivtab_t(quotient = -4, remainder = 1), adivtab_t(quotient = -3, remainder = 2), adivtab_t(quotient = -2, remainder = 1), adivtab_t(quotient = -2, remainder = 3), adivtab_t(quotient = -2, remainder = 5), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = -1, remainder = 2), adivtab_t(quotient = -1, remainder = 3), adivtab_t(quotient = -1, remainder = 4), adivtab_t(quotient = -1, remainder = 5), adivtab_t(quotient = -1, remainder = 6), adivtab_t(quotient = -1, remainder = 7), adivtab_t(quotient = -1, remainder = 8), adivtab_t(quotient = -1, remainder = 9), adivtab_t(quotient = 0, remainder = -6), adivtab_t(quotient = 0, remainder = -6), adivtab_t(quotient = 0, remainder = -6), adivtab_t(quotient = 0, remainder = -6), adivtab_t(quotient = 0, remainder = -6), adivtab_t(quotient = 0, remainder = -6), adivtab_t(quotient = 0, remainder = -6), adivtab_t(quotient = 0, remainder = -6), adivtab_t(quotient = 0, remainder = -6), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 1, remainder = -1), adivtab_t(quotient = 1, remainder = -2), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 3, remainder = 0), adivtab_t(quotient = 6, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -6, remainder = 0), adivtab_t(quotient = -3, remainder = 0), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = -2, remainder = 2), adivtab_t(quotient = -2, remainder = 4), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = -1, remainder = 2), adivtab_t(quotient = -1, remainder = 3), adivtab_t(quotient = -1, remainder = 4), adivtab_t(quotient = -1, remainder = 5), adivtab_t(quotient = -1, remainder = 6), adivtab_t(quotient = -1, remainder = 7), adivtab_t(quotient = -1, remainder = 8), adivtab_t(quotient = -1, remainder = 9), adivtab_t(quotient = -1, remainder = 10), adivtab_t(quotient = 0, remainder = -5), adivtab_t(quotient = 0, remainder = -5), adivtab_t(quotient = 0, remainder = -5), adivtab_t(quotient = 0, remainder = -5), adivtab_t(quotient = 0, remainder = -5), adivtab_t(quotient = 0, remainder = -5), adivtab_t(quotient = 0, remainder = -5), adivtab_t(quotient = 0, remainder = -5), adivtab_t(quotient = 0, remainder = -5), adivtab_t(quotient = 0, remainder = -5), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 1, remainder = -1), adivtab_t(quotient = 1, remainder = -2), adivtab_t(quotient = 2, remainder = -1), adivtab_t(quotient = 5, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -5, remainder = 0), adivtab_t(quotient = -3, remainder = 1), adivtab_t(quotient = -2, remainder = 1), adivtab_t(quotient = -2, remainder = 3), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = -1, remainder = 2), adivtab_t(quotient = -1, remainder = 3), adivtab_t(quotient = -1, remainder = 4), adivtab_t(quotient = -1, remainder = 5), adivtab_t(quotient = -1, remainder = 6), adivtab_t(quotient = -1, remainder = 7), adivtab_t(quotient = -1, remainder = 8), adivtab_t(quotient = -1, remainder = 9), adivtab_t(quotient = -1, remainder = 10), adivtab_t(quotient = -1, remainder = 11), adivtab_t(quotient = 0, remainder = -4), adivtab_t(quotient = 0, remainder = -4), adivtab_t(quotient = 0, remainder = -4), adivtab_t(quotient = 0, remainder = -4), adivtab_t(quotient = 0, remainder = -4), adivtab_t(quotient = 0, remainder = -4), adivtab_t(quotient = 0, remainder = -4), adivtab_t(quotient = 0, remainder = -4), adivtab_t(quotient = 0, remainder = -4), adivtab_t(quotient = 0, remainder = -4), adivtab_t(quotient = 0, remainder = -4), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 1, remainder = -1), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 4, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -4, remainder = 0), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = -2, remainder = 2), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = -1, remainder = 2), adivtab_t(quotient = -1, remainder = 3), adivtab_t(quotient = -1, remainder = 4), adivtab_t(quotient = -1, remainder = 5), adivtab_t(quotient = -1, remainder = 6), adivtab_t(quotient = -1, remainder = 7), adivtab_t(quotient = -1, remainder = 8), adivtab_t(quotient = -1, remainder = 9), adivtab_t(quotient = -1, remainder = 10), adivtab_t(quotient = -1, remainder = 11), adivtab_t(quotient = -1, remainder = 12), adivtab_t(quotient = 0, remainder = -3), adivtab_t(quotient = 0, remainder = -3), adivtab_t(quotient = 0, remainder = -3), adivtab_t(quotient = 0, remainder = -3), adivtab_t(quotient = 0, remainder = -3), adivtab_t(quotient = 0, remainder = -3), adivtab_t(quotient = 0, remainder = -3), adivtab_t(quotient = 0, remainder = -3), adivtab_t(quotient = 0, remainder = -3), adivtab_t(quotient = 0, remainder = -3), adivtab_t(quotient = 0, remainder = -3), adivtab_t(quotient = 0, remainder = -3), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 1, remainder = -1), adivtab_t(quotient = 3, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -3, remainder = 0), adivtab_t(quotient = -2, remainder = 1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = -1, remainder = 2), adivtab_t(quotient = -1, remainder = 3), adivtab_t(quotient = -1, remainder = 4), adivtab_t(quotient = -1, remainder = 5), adivtab_t(quotient = -1, remainder = 6), adivtab_t(quotient = -1, remainder = 7), adivtab_t(quotient = -1, remainder = 8), adivtab_t(quotient = -1, remainder = 9), adivtab_t(quotient = -1, remainder = 10), adivtab_t(quotient = -1, remainder = 11), adivtab_t(quotient = -1, remainder = 12), adivtab_t(quotient = -1, remainder = 13), adivtab_t(quotient = 0, remainder = -2), adivtab_t(quotient = 0, remainder = -2), adivtab_t(quotient = 0, remainder = -2), adivtab_t(quotient = 0, remainder = -2), adivtab_t(quotient = 0, remainder = -2), adivtab_t(quotient = 0, remainder = -2), adivtab_t(quotient = 0, remainder = -2), adivtab_t(quotient = 0, remainder = -2), adivtab_t(quotient = 0, remainder = -2), adivtab_t(quotient = 0, remainder = -2), adivtab_t(quotient = 0, remainder = -2), adivtab_t(quotient = 0, remainder = -2), adivtab_t(quotient = 0, remainder = -2), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = -1, remainder = 2), adivtab_t(quotient = -1, remainder = 3), adivtab_t(quotient = -1, remainder = 4), adivtab_t(quotient = -1, remainder = 5), adivtab_t(quotient = -1, remainder = 6), adivtab_t(quotient = -1, remainder = 7), adivtab_t(quotient = -1, remainder = 8), adivtab_t(quotient = -1, remainder = 9), adivtab_t(quotient = -1, remainder = 10), adivtab_t(quotient = -1, remainder = 11), adivtab_t(quotient = -1, remainder = 12), adivtab_t(quotient = -1, remainder = 13), adivtab_t(quotient = -1, remainder = 14), adivtab_t(quotient = 0, remainder = -1), adivtab_t(quotient = 0, remainder = -1), adivtab_t(quotient = 0, remainder = -1), adivtab_t(quotient = 0, remainder = -1), adivtab_t(quotient = 0, remainder = -1), adivtab_t(quotient = 0, remainder = -1), adivtab_t(quotient = 0, remainder = -1), adivtab_t(quotient = 0, remainder = -1), adivtab_t(quotient = 0, remainder = -1), adivtab_t(quotient = 0, remainder = -1), adivtab_t(quotient = 0, remainder = -1), adivtab_t(quotient = 0, remainder = -1), adivtab_t(quotient = 0, remainder = -1), adivtab_t(quotient = 0, remainder = -1), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -1, remainder = 1), adivtab_t(quotient = -1, remainder = 2), adivtab_t(quotient = -1, remainder = 3), adivtab_t(quotient = -1, remainder = 4), adivtab_t(quotient = -1, remainder = 5), adivtab_t(quotient = -1, remainder = 6), adivtab_t(quotient = -1, remainder = 7), adivtab_t(quotient = -1, remainder = 8), adivtab_t(quotient = -1, remainder = 9), adivtab_t(quotient = -1, remainder = 10), adivtab_t(quotient = -1, remainder = 11), adivtab_t(quotient = -1, remainder = 12), adivtab_t(quotient = -1, remainder = 13), adivtab_t(quotient = -1, remainder = 14), adivtab_t(quotient = -1, remainder = 15), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = -1, remainder = -14), adivtab_t(quotient = -1, remainder = -13), adivtab_t(quotient = -1, remainder = -12), adivtab_t(quotient = -1, remainder = -11), adivtab_t(quotient = -1, remainder = -10), adivtab_t(quotient = -1, remainder = -9), adivtab_t(quotient = -1, remainder = -8), adivtab_t(quotient = -1, remainder = -7), adivtab_t(quotient = -1, remainder = -6), adivtab_t(quotient = -1, remainder = -5), adivtab_t(quotient = -1, remainder = -4), adivtab_t(quotient = -1, remainder = -3), adivtab_t(quotient = -1, remainder = -2), adivtab_t(quotient = -1, remainder = -1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = 0, remainder = 1), adivtab_t(quotient = -1, remainder = -13), adivtab_t(quotient = -1, remainder = -12), adivtab_t(quotient = -1, remainder = -11), adivtab_t(quotient = -1, remainder = -10), adivtab_t(quotient = -1, remainder = -9), adivtab_t(quotient = -1, remainder = -8), adivtab_t(quotient = -1, remainder = -7), adivtab_t(quotient = -1, remainder = -6), adivtab_t(quotient = -1, remainder = -5), adivtab_t(quotient = -1, remainder = -4), adivtab_t(quotient = -1, remainder = -3), adivtab_t(quotient = -1, remainder = -2), adivtab_t(quotient = -1, remainder = -1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 2), adivtab_t(quotient = 0, remainder = 2), adivtab_t(quotient = 0, remainder = 2), adivtab_t(quotient = 0, remainder = 2), adivtab_t(quotient = 0, remainder = 2), adivtab_t(quotient = 0, remainder = 2), adivtab_t(quotient = 0, remainder = 2), adivtab_t(quotient = 0, remainder = 2), adivtab_t(quotient = 0, remainder = 2), adivtab_t(quotient = 0, remainder = 2), adivtab_t(quotient = 0, remainder = 2), adivtab_t(quotient = 0, remainder = 2), adivtab_t(quotient = 0, remainder = 2), adivtab_t(quotient = 0, remainder = 2), adivtab_t(quotient = -1, remainder = -12), adivtab_t(quotient = -1, remainder = -11), adivtab_t(quotient = -1, remainder = -10), adivtab_t(quotient = -1, remainder = -9), adivtab_t(quotient = -1, remainder = -8), adivtab_t(quotient = -1, remainder = -7), adivtab_t(quotient = -1, remainder = -6), adivtab_t(quotient = -1, remainder = -5), adivtab_t(quotient = -1, remainder = -4), adivtab_t(quotient = -1, remainder = -3), adivtab_t(quotient = -1, remainder = -2), adivtab_t(quotient = -1, remainder = -1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -2, remainder = -1), adivtab_t(quotient = -3, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 3, remainder = 0), adivtab_t(quotient = 1, remainder = 1), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 3), adivtab_t(quotient = 0, remainder = 3), adivtab_t(quotient = 0, remainder = 3), adivtab_t(quotient = 0, remainder = 3), adivtab_t(quotient = 0, remainder = 3), adivtab_t(quotient = 0, remainder = 3), adivtab_t(quotient = 0, remainder = 3), adivtab_t(quotient = 0, remainder = 3), adivtab_t(quotient = 0, remainder = 3), adivtab_t(quotient = 0, remainder = 3), adivtab_t(quotient = 0, remainder = 3), adivtab_t(quotient = 0, remainder = 3), adivtab_t(quotient = 0, remainder = 3), adivtab_t(quotient = -1, remainder = -11), adivtab_t(quotient = -1, remainder = -10), adivtab_t(quotient = -1, remainder = -9), adivtab_t(quotient = -1, remainder = -8), adivtab_t(quotient = -1, remainder = -7), adivtab_t(quotient = -1, remainder = -6), adivtab_t(quotient = -1, remainder = -5), adivtab_t(quotient = -1, remainder = -4), adivtab_t(quotient = -1, remainder = -3), adivtab_t(quotient = -1, remainder = -2), adivtab_t(quotient = -1, remainder = -1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -2, remainder = -2), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = -4, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 4, remainder = 0), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 1, remainder = 1), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 4), adivtab_t(quotient = 0, remainder = 4), adivtab_t(quotient = 0, remainder = 4), adivtab_t(quotient = 0, remainder = 4), adivtab_t(quotient = 0, remainder = 4), adivtab_t(quotient = 0, remainder = 4), adivtab_t(quotient = 0, remainder = 4), adivtab_t(quotient = 0, remainder = 4), adivtab_t(quotient = 0, remainder = 4), adivtab_t(quotient = 0, remainder = 4), adivtab_t(quotient = 0, remainder = 4), adivtab_t(quotient = 0, remainder = 4), adivtab_t(quotient = -1, remainder = -10), adivtab_t(quotient = -1, remainder = -9), adivtab_t(quotient = -1, remainder = -8), adivtab_t(quotient = -1, remainder = -7), adivtab_t(quotient = -1, remainder = -6), adivtab_t(quotient = -1, remainder = -5), adivtab_t(quotient = -1, remainder = -4), adivtab_t(quotient = -1, remainder = -3), adivtab_t(quotient = -1, remainder = -2), adivtab_t(quotient = -1, remainder = -1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -2, remainder = -3), adivtab_t(quotient = -2, remainder = -1), adivtab_t(quotient = -3, remainder = -1), adivtab_t(quotient = -5, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 5, remainder = 0), adivtab_t(quotient = 2, remainder = 1), adivtab_t(quotient = 1, remainder = 2), adivtab_t(quotient = 1, remainder = 1), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 5), adivtab_t(quotient = 0, remainder = 5), adivtab_t(quotient = 0, remainder = 5), adivtab_t(quotient = 0, remainder = 5), adivtab_t(quotient = 0, remainder = 5), adivtab_t(quotient = 0, remainder = 5), adivtab_t(quotient = 0, remainder = 5), adivtab_t(quotient = 0, remainder = 5), adivtab_t(quotient = 0, remainder = 5), adivtab_t(quotient = 0, remainder = 5), adivtab_t(quotient = 0, remainder = 5), adivtab_t(quotient = -1, remainder = -9), adivtab_t(quotient = -1, remainder = -8), adivtab_t(quotient = -1, remainder = -7), adivtab_t(quotient = -1, remainder = -6), adivtab_t(quotient = -1, remainder = -5), adivtab_t(quotient = -1, remainder = -4), adivtab_t(quotient = -1, remainder = -3), adivtab_t(quotient = -1, remainder = -2), adivtab_t(quotient = -1, remainder = -1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -2, remainder = -4), adivtab_t(quotient = -2, remainder = -2), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = -3, remainder = 0), adivtab_t(quotient = -6, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 6, remainder = 0), adivtab_t(quotient = 3, remainder = 0), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 1, remainder = 2), adivtab_t(quotient = 1, remainder = 1), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 6), adivtab_t(quotient = 0, remainder = 6), adivtab_t(quotient = 0, remainder = 6), adivtab_t(quotient = 0, remainder = 6), adivtab_t(quotient = 0, remainder = 6), adivtab_t(quotient = 0, remainder = 6), adivtab_t(quotient = 0, remainder = 6), adivtab_t(quotient = 0, remainder = 6), adivtab_t(quotient = 0, remainder = 6), adivtab_t(quotient = 0, remainder = 6), adivtab_t(quotient = -1, remainder = -8), adivtab_t(quotient = -1, remainder = -7), adivtab_t(quotient = -1, remainder = -6), adivtab_t(quotient = -1, remainder = -5), adivtab_t(quotient = -1, remainder = -4), adivtab_t(quotient = -1, remainder = -3), adivtab_t(quotient = -1, remainder = -2), adivtab_t(quotient = -1, remainder = -1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -2, remainder = -5), adivtab_t(quotient = -2, remainder = -3), adivtab_t(quotient = -2, remainder = -1), adivtab_t(quotient = -3, remainder = -2), adivtab_t(quotient = -4, remainder = -1), adivtab_t(quotient = -7, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 7, remainder = 0), adivtab_t(quotient = 3, remainder = 1), adivtab_t(quotient = 2, remainder = 1), adivtab_t(quotient = 1, remainder = 3), adivtab_t(quotient = 1, remainder = 2), adivtab_t(quotient = 1, remainder = 1), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 7), adivtab_t(quotient = 0, remainder = 7), adivtab_t(quotient = 0, remainder = 7), adivtab_t(quotient = 0, remainder = 7), adivtab_t(quotient = 0, remainder = 7), adivtab_t(quotient = 0, remainder = 7), adivtab_t(quotient = 0, remainder = 7), adivtab_t(quotient = 0, remainder = 7), adivtab_t(quotient = 0, remainder = 7), adivtab_t(quotient = -1, remainder = -7), adivtab_t(quotient = -1, remainder = -6), adivtab_t(quotient = -1, remainder = -5), adivtab_t(quotient = -1, remainder = -4), adivtab_t(quotient = -1, remainder = -3), adivtab_t(quotient = -1, remainder = -2), adivtab_t(quotient = -1, remainder = -1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -2, remainder = -6), adivtab_t(quotient = -2, remainder = -4), adivtab_t(quotient = -2, remainder = -2), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = -3, remainder = -1), adivtab_t(quotient = -4, remainder = 0), adivtab_t(quotient = -8, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 8, remainder = 0), adivtab_t(quotient = 4, remainder = 0), adivtab_t(quotient = 2, remainder = 2), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 1, remainder = 3), adivtab_t(quotient = 1, remainder = 2), adivtab_t(quotient = 1, remainder = 1), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 8), adivtab_t(quotient = 0, remainder = 8), adivtab_t(quotient = 0, remainder = 8), adivtab_t(quotient = 0, remainder = 8), adivtab_t(quotient = 0, remainder = 8), adivtab_t(quotient = 0, remainder = 8), adivtab_t(quotient = 0, remainder = 8), adivtab_t(quotient = 0, remainder = 8), adivtab_t(quotient = -1, remainder = -6), adivtab_t(quotient = -1, remainder = -5), adivtab_t(quotient = -1, remainder = -4), adivtab_t(quotient = -1, remainder = -3), adivtab_t(quotient = -1, remainder = -2), adivtab_t(quotient = -1, remainder = -1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -2, remainder = -7), adivtab_t(quotient = -2, remainder = -5), adivtab_t(quotient = -2, remainder = -3), adivtab_t(quotient = -2, remainder = -1), adivtab_t(quotient = -3, remainder = -3), adivtab_t(quotient = -3, remainder = 0), adivtab_t(quotient = -5, remainder = -1), adivtab_t(quotient = -9, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 9, remainder = 0), adivtab_t(quotient = 4, remainder = 1), adivtab_t(quotient = 3, remainder = 0), adivtab_t(quotient = 2, remainder = 1), adivtab_t(quotient = 1, remainder = 4), adivtab_t(quotient = 1, remainder = 3), adivtab_t(quotient = 1, remainder = 2), adivtab_t(quotient = 1, remainder = 1), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 9), adivtab_t(quotient = 0, remainder = 9), adivtab_t(quotient = 0, remainder = 9), adivtab_t(quotient = 0, remainder = 9), adivtab_t(quotient = 0, remainder = 9), adivtab_t(quotient = 0, remainder = 9), adivtab_t(quotient = 0, remainder = 9), adivtab_t(quotient = -1, remainder = -5), adivtab_t(quotient = -1, remainder = -4), adivtab_t(quotient = -1, remainder = -3), adivtab_t(quotient = -1, remainder = -2), adivtab_t(quotient = -1, remainder = -1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -2, remainder = -8), adivtab_t(quotient = -2, remainder = -6), adivtab_t(quotient = -2, remainder = -4), adivtab_t(quotient = -2, remainder = -2), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = -3, remainder = -2), adivtab_t(quotient = -4, remainder = -2), adivtab_t(quotient = -5, remainder = 0), adivtab_t(quotient = -10, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 10, remainder = 0), adivtab_t(quotient = 5, remainder = 0), adivtab_t(quotient = 3, remainder = 1), adivtab_t(quotient = 2, remainder = 2), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 1, remainder = 4), adivtab_t(quotient = 1, remainder = 3), adivtab_t(quotient = 1, remainder = 2), adivtab_t(quotient = 1, remainder = 1), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 10), adivtab_t(quotient = 0, remainder = 10), adivtab_t(quotient = 0, remainder = 10), adivtab_t(quotient = 0, remainder = 10), adivtab_t(quotient = 0, remainder = 10), adivtab_t(quotient = 0, remainder = 10), adivtab_t(quotient = -1, remainder = -4), adivtab_t(quotient = -1, remainder = -3), adivtab_t(quotient = -1, remainder = -2), adivtab_t(quotient = -1, remainder = -1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -2, remainder = -9), adivtab_t(quotient = -2, remainder = -7), adivtab_t(quotient = -2, remainder = -5), adivtab_t(quotient = -2, remainder = -3), adivtab_t(quotient = -2, remainder = -1), adivtab_t(quotient = -3, remainder = -4), adivtab_t(quotient = -3, remainder = -1), adivtab_t(quotient = -4, remainder = -1), adivtab_t(quotient = -6, remainder = -1), adivtab_t(quotient = -11, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 11, remainder = 0), adivtab_t(quotient = 5, remainder = 1), adivtab_t(quotient = 3, remainder = 2), adivtab_t(quotient = 2, remainder = 3), adivtab_t(quotient = 2, remainder = 1), adivtab_t(quotient = 1, remainder = 5), adivtab_t(quotient = 1, remainder = 4), adivtab_t(quotient = 1, remainder = 3), adivtab_t(quotient = 1, remainder = 2), adivtab_t(quotient = 1, remainder = 1), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 11), adivtab_t(quotient = 0, remainder = 11), adivtab_t(quotient = 0, remainder = 11), adivtab_t(quotient = 0, remainder = 11), adivtab_t(quotient = 0, remainder = 11), adivtab_t(quotient = -1, remainder = -3), adivtab_t(quotient = -1, remainder = -2), adivtab_t(quotient = -1, remainder = -1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -2, remainder = -10), adivtab_t(quotient = -2, remainder = -8), adivtab_t(quotient = -2, remainder = -6), adivtab_t(quotient = -2, remainder = -4), adivtab_t(quotient = -2, remainder = -2), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = -3, remainder = -3), adivtab_t(quotient = -3, remainder = 0), adivtab_t(quotient = -4, remainder = 0), adivtab_t(quotient = -6, remainder = 0), adivtab_t(quotient = -12, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 12, remainder = 0), adivtab_t(quotient = 6, remainder = 0), adivtab_t(quotient = 4, remainder = 0), adivtab_t(quotient = 3, remainder = 0), adivtab_t(quotient = 2, remainder = 2), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 1, remainder = 5), adivtab_t(quotient = 1, remainder = 4), adivtab_t(quotient = 1, remainder = 3), adivtab_t(quotient = 1, remainder = 2), adivtab_t(quotient = 1, remainder = 1), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 12), adivtab_t(quotient = 0, remainder = 12), adivtab_t(quotient = 0, remainder = 12), adivtab_t(quotient = 0, remainder = 12), adivtab_t(quotient = -1, remainder = -2), adivtab_t(quotient = -1, remainder = -1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -2, remainder = -11), adivtab_t(quotient = -2, remainder = -9), adivtab_t(quotient = -2, remainder = -7), adivtab_t(quotient = -2, remainder = -5), adivtab_t(quotient = -2, remainder = -3), adivtab_t(quotient = -2, remainder = -1), adivtab_t(quotient = -3, remainder = -5), adivtab_t(quotient = -3, remainder = -2), adivtab_t(quotient = -4, remainder = -3), adivtab_t(quotient = -5, remainder = -2), adivtab_t(quotient = -7, remainder = -1), adivtab_t(quotient = -13, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 13, remainder = 0), adivtab_t(quotient = 6, remainder = 1), adivtab_t(quotient = 4, remainder = 1), adivtab_t(quotient = 3, remainder = 1), adivtab_t(quotient = 2, remainder = 3), adivtab_t(quotient = 2, remainder = 1), adivtab_t(quotient = 1, remainder = 6), adivtab_t(quotient = 1, remainder = 5), adivtab_t(quotient = 1, remainder = 4), adivtab_t(quotient = 1, remainder = 3), adivtab_t(quotient = 1, remainder = 2), adivtab_t(quotient = 1, remainder = 1), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 13), adivtab_t(quotient = 0, remainder = 13), adivtab_t(quotient = 0, remainder = 13), adivtab_t(quotient = -1, remainder = -1), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -2, remainder = -12), adivtab_t(quotient = -2, remainder = -10), adivtab_t(quotient = -2, remainder = -8), adivtab_t(quotient = -2, remainder = -6), adivtab_t(quotient = -2, remainder = -4), adivtab_t(quotient = -2, remainder = -2), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = -3, remainder = -4), adivtab_t(quotient = -3, remainder = -1), adivtab_t(quotient = -4, remainder = -2), adivtab_t(quotient = -5, remainder = -1), adivtab_t(quotient = -7, remainder = 0), adivtab_t(quotient = -14, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 14, remainder = 0), adivtab_t(quotient = 7, remainder = 0), adivtab_t(quotient = 4, remainder = 2), adivtab_t(quotient = 3, remainder = 2), adivtab_t(quotient = 2, remainder = 4), adivtab_t(quotient = 2, remainder = 2), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 1, remainder = 6), adivtab_t(quotient = 1, remainder = 5), adivtab_t(quotient = 1, remainder = 4), adivtab_t(quotient = 1, remainder = 3), adivtab_t(quotient = 1, remainder = 2), adivtab_t(quotient = 1, remainder = 1), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 14), adivtab_t(quotient = 0, remainder = 14), adivtab_t(quotient = -1, remainder = 0), adivtab_t(quotient = -2, remainder = -13), adivtab_t(quotient = -2, remainder = -11), adivtab_t(quotient = -2, remainder = -9), adivtab_t(quotient = -2, remainder = -7), adivtab_t(quotient = -2, remainder = -5), adivtab_t(quotient = -2, remainder = -3), adivtab_t(quotient = -2, remainder = -1), adivtab_t(quotient = -3, remainder = -6), adivtab_t(quotient = -3, remainder = -3), adivtab_t(quotient = -3, remainder = 0), adivtab_t(quotient = -4, remainder = -1), adivtab_t(quotient = -5, remainder = 0), adivtab_t(quotient = -8, remainder = -1), adivtab_t(quotient = -15, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 15, remainder = 0), adivtab_t(quotient = 7, remainder = 1), adivtab_t(quotient = 5, remainder = 0), adivtab_t(quotient = 3, remainder = 3), adivtab_t(quotient = 3, remainder = 0), adivtab_t(quotient = 2, remainder = 3), adivtab_t(quotient = 2, remainder = 1), adivtab_t(quotient = 1, remainder = 7), adivtab_t(quotient = 1, remainder = 6), adivtab_t(quotient = 1, remainder = 5), adivtab_t(quotient = 1, remainder = 4), adivtab_t(quotient = 1, remainder = 3), adivtab_t(quotient = 1, remainder = 2), adivtab_t(quotient = 1, remainder = 1), adivtab_t(quotient = 1, remainder = 0), adivtab_t(quotient = 0, remainder = 15), adivtab_t(quotient = -2, remainder = -14), adivtab_t(quotient = -2, remainder = -12), adivtab_t(quotient = -2, remainder = -10), adivtab_t(quotient = -2, remainder = -8), adivtab_t(quotient = -2, remainder = -6), adivtab_t(quotient = -2, remainder = -4), adivtab_t(quotient = -2, remainder = -2), adivtab_t(quotient = -2, remainder = 0), adivtab_t(quotient = -3, remainder = -5), adivtab_t(quotient = -3, remainder = -2), adivtab_t(quotient = -4, remainder = -4), adivtab_t(quotient = -4, remainder = 0), adivtab_t(quotient = -6, remainder = -2), adivtab_t(quotient = -8, remainder = 0), adivtab_t(quotient = -16, remainder = 0), adivtab_t(quotient = 0, remainder = 0), adivtab_t(quotient = 16, remainder = 0), adivtab_t(quotient = 8, remainder = 0), adivtab_t(quotient = 5, remainder = 1), adivtab_t(quotient = 4, remainder = 0), adivtab_t(quotient = 3, remainder = 1), adivtab_t(quotient = 2, remainder = 4), adivtab_t(quotient = 2, remainder = 2), adivtab_t(quotient = 2, remainder = 0), adivtab_t(quotient = 1, remainder = 7), adivtab_t(quotient = 1, remainder = 6), adivtab_t(quotient = 1, remainder = 5), adivtab_t(quotient = 1, remainder = 4), adivtab_t(quotient = 1, remainder = 3), adivtab_t(quotient = 1, remainder = 2), adivtab_t(quotient = 1, remainder = 1), adivtab_t(quotient = 1, remainder = 0))

var pedgetable : edgetable? = default<edgetable?>

var d_pedgespanpackage : spanpackage_t? = default<spanpackage_t?>

[export, sideeffects]
def D_PolysetScanLeftEdge(var height_1 : int) {
    while (true) {
        d_pedgespanpackage.pdest = unsafe(reinterpret<uint8?>(d_pdest))
        d_pedgespanpackage.pz = d_pz
        d_pedgespanpackage.count = int(d_aspancount)  // nolint:PERF020
        d_pedgespanpackage.ptex = d_ptex
        d_pedgespanpackage.sfrac = int(d_sfrac)  // nolint:PERF020
        d_pedgespanpackage.tfrac = int(d_tfrac)  // nolint:PERF020
        d_pedgespanpackage.light = int(d_light)  // nolint:PERF020
        d_pedgespanpackage.zi = int(d_zi)  // nolint:PERF020
        unsafe {  // nolint:STYLE025
            d_pedgespanpackage += 1
        }
        errorterm = errorterm + erroradjustup
        if (errorterm >= 0) {
            unsafe {  // nolint:STYLE025
                d_pdest += int64(d_pdestextrastep)
            }
            unsafe {  // nolint:STYLE025
                d_pz += int64(d_pzextrastep)
            }
            d_aspancount += d_countextrastep
            unsafe {  // nolint:STYLE025
                d_ptex += int64(d_ptexextrastep)
            }
            d_sfrac += d_sfracextrastep
            unsafe {  // nolint:STYLE025
                d_ptex += int64(d_sfrac >> 16)
            }
            d_sfrac &= 65535
            d_tfrac += d_tfracextrastep
            if ((d_tfrac & 65536) != 0) {
                unsafe {  // nolint:STYLE025
                    d_ptex += int64(r_affinetridesc.skinwidth)
                }
                d_tfrac &= 65535
            }
            d_light += d_lightextrastep
            d_zi += d_ziextrastep
            errorterm = errorterm - erroradjustdown
        } else {
            unsafe {  // nolint:STYLE025
                d_pdest += int64(d_pdestbasestep)
            }
            unsafe {  // nolint:STYLE025
                d_pz += int64(d_pzbasestep)
            }
            d_aspancount = d_aspancount + ubasestep
            unsafe {  // nolint:STYLE025
                d_ptex += int64(d_ptexbasestep)
            }
            d_sfrac += d_sfracbasestep
            unsafe {  // nolint:STYLE025
                d_ptex += int64(d_sfrac >> 16)
            }
            d_sfrac &= 65535
            d_tfrac += d_tfracbasestep
            if ((d_tfrac & 65536) != 0) {
                unsafe {  // nolint:STYLE025
                    d_ptex += int64(r_affinetridesc.skinwidth)
                }
                d_tfrac &= 65535
            }
            d_light += d_lightbasestep
            d_zi += d_zibasestep
        }
        height_1--
        if (height_1 == 0) {
            break
        }
    }
    return
}
var d_zibasestep : int = default<int>

var d_zi : int = default<int>

var d_lightbasestep : int = default<int>

var d_light : int = default<int>

var d_tfrac : int = default<int>

var d_ptex : uint8? = default<uint8?>

var d_tfracbasestep : int = default<int>

var d_sfrac : int = default<int>

var d_sfracbasestep : int = default<int>

var d_ptexbasestep : int = default<int>

var d_pzbasestep : int = default<int>

var d_pz : int16? = default<int16?>

var d_pdestbasestep : int = default<int>

var d_pdest : uint8? = default<uint8?>

var d_ziextrastep : int = default<int>

var d_lightextrastep : int = default<int>

var d_tfracextrastep : int = default<int>

var d_sfracextrastep : int = default<int>

var d_ptexextrastep : int = default<int>

var d_pzextrastep : int = default<int>

var d_pdestextrastep : int = default<int>

var r_tstepx : int = default<int>

var r_tstepy : int = default<int>

var r_sstepx : int = default<int>

var r_sstepy : int = default<int>

var r_zistepy : int = default<int>

var r_lstepy : int = default<int>

var private ystart : int = default<int>

[export, sideeffects]
def D_PolysetCalcGradients(var skinwidth_0 : int) {
    var xstepdenominv : float
    var ystepdenominv : float
    var t0 : float
    var t1 : float
    var p01_minus_p21 : float
    var p11_minus_p21 : float
    var p00_minus_p20 : float
    var p10_minus_p20 : float
    p00_minus_p20 = float(r_p0[0] - r_p2[0])
    p01_minus_p21 = float(r_p0[1] - r_p2[1])
    p10_minus_p20 = float(r_p1[0] - r_p2[0])
    p11_minus_p21 = float(r_p1[1] - r_p2[1])
    xstepdenominv = float(1.0lf / double(float(d_xdenom)))
    ystepdenominv = -xstepdenominv
    t0 = float(r_p0[4] - r_p2[4])
    t1 = float(r_p1[4] - r_p2[4])
    r_lstepx = int(ceil(double((t1 * p01_minus_p21 - t0 * p11_minus_p21) * xstepdenominv)))
    r_lstepy = int(ceil(double((t1 * p00_minus_p20 - t0 * p10_minus_p20) * ystepdenominv)))
    t0 = float(r_p0[2] - r_p2[2])
    t1 = float(r_p1[2] - r_p2[2])
    r_sstepx = int((t1 * p01_minus_p21 - t0 * p11_minus_p21) * xstepdenominv)
    r_sstepy = int((t1 * p00_minus_p20 - t0 * p10_minus_p20) * ystepdenominv)
    t0 = float(r_p0[3] - r_p2[3])
    t1 = float(r_p1[3] - r_p2[3])
    r_tstepx = int((t1 * p01_minus_p21 - t0 * p11_minus_p21) * xstepdenominv)
    r_tstepy = int((t1 * p00_minus_p20 - t0 * p10_minus_p20) * ystepdenominv)
    t0 = float(r_p0[5] - r_p2[5])
    t1 = float(r_p1[5] - r_p2[5])
    r_zistepx = int((t1 * p01_minus_p21 - t0 * p11_minus_p21) * xstepdenominv)
    r_zistepy = int((t1 * p00_minus_p20 - t0 * p10_minus_p20) * ystepdenominv)
    a_sstepxfrac = r_sstepx & 65535
    a_tstepxfrac = r_tstepx & 65535
    a_ststepxwhole = skinwidth_0 * (r_tstepx >> 16) + (r_sstepx >> 16)
    return
}
var r_p2 : int[6] = default<int[6]>

var r_p1 : int[6] = default<int[6]>

var r_p0 : int[6] = default<int[6]>

var d_xdenom : int = default<int>

[export, sideeffects]
def D_PolysetSetEdgeTable() {
    var edgetableindex : int = 0
    if (r_p0[1] >= r_p1[1]) {
        if (r_p0[1] == r_p1[1]) {
            if (r_p0[1] < r_p2[1]) {
                pedgetable = unsafe(addr<edgetable?>(unsafe(unsafe(addr(edgetables[0]))[2])))
            } else {
                pedgetable = unsafe(addr<edgetable?>(unsafe(unsafe(addr(edgetables[0]))[5])))
            }
            return
        } else {
            edgetableindex = 1
        }
    }
    if (r_p0[1] == r_p2[1]) {
        if (edgetableindex != 0) {
            pedgetable = unsafe(addr<edgetable?>(unsafe(unsafe(addr(edgetables[0]))[8])))
        } else {
            pedgetable = unsafe(addr<edgetable?>(unsafe(unsafe(addr(edgetables[0]))[9])))
        }
        return
    } elif (r_p1[1] == r_p2[1]) {
        if (edgetableindex != 0) {
            pedgetable = unsafe(addr<edgetable?>(unsafe(unsafe(addr(edgetables[0]))[10])))
        } else {
            pedgetable = unsafe(addr<edgetable?>(unsafe(unsafe(addr(edgetables[0]))[11])))
        }
        return
    }
    if (r_p0[1] > r_p2[1]) {
        edgetableindex += 2
    }
    if (r_p1[1] > r_p2[1]) {
        edgetableindex += 4
    }
    pedgetable = unsafe(addr<edgetable?>(unsafe(unsafe(addr(edgetables[0]))[edgetableindex])))
    return
}
var edgetables : edgetable[12] = fixed_array<edgetable>(edgetable(isflattop = 0, numleftedges = 1, pleftedgevert0 = unsafe(addr(r_p0[0])), pleftedgevert1 = unsafe(addr(r_p2[0])), pleftedgevert2 = null, numrightedges = 2, prightedgevert0 = unsafe(addr(r_p0[0])), prightedgevert1 = unsafe(addr(r_p1[0])), prightedgevert2 = unsafe(addr(r_p2[0]))), edgetable(isflattop = 0, numleftedges = 2, pleftedgevert0 = unsafe(addr(r_p1[0])), pleftedgevert1 = unsafe(addr(r_p0[0])), pleftedgevert2 = unsafe(addr(r_p2[0])), numrightedges = 1, prightedgevert0 = unsafe(addr(r_p1[0])), prightedgevert1 = unsafe(addr(r_p2[0])), prightedgevert2 = null), edgetable(isflattop = 1, numleftedges = 1, pleftedgevert0 = unsafe(addr(r_p0[0])), pleftedgevert1 = unsafe(addr(r_p2[0])), pleftedgevert2 = null, numrightedges = 1, prightedgevert0 = unsafe(addr(r_p1[0])), prightedgevert1 = unsafe(addr(r_p2[0])), prightedgevert2 = null), edgetable(isflattop = 0, numleftedges = 1, pleftedgevert0 = unsafe(addr(r_p1[0])), pleftedgevert1 = unsafe(addr(r_p0[0])), pleftedgevert2 = null, numrightedges = 2, prightedgevert0 = unsafe(addr(r_p1[0])), prightedgevert1 = unsafe(addr(r_p2[0])), prightedgevert2 = unsafe(addr(r_p0[0]))), edgetable(isflattop = 0, numleftedges = 2, pleftedgevert0 = unsafe(addr(r_p0[0])), pleftedgevert1 = unsafe(addr(r_p2[0])), pleftedgevert2 = unsafe(addr(r_p1[0])), numrightedges = 1, prightedgevert0 = unsafe(addr(r_p0[0])), prightedgevert1 = unsafe(addr(r_p1[0])), prightedgevert2 = null), edgetable(isflattop = 0, numleftedges = 1, pleftedgevert0 = unsafe(addr(r_p2[0])), pleftedgevert1 = unsafe(addr(r_p1[0])), pleftedgevert2 = null, numrightedges = 1, prightedgevert0 = unsafe(addr(r_p2[0])), prightedgevert1 = unsafe(addr(r_p0[0])), prightedgevert2 = null), edgetable(isflattop = 0, numleftedges = 1, pleftedgevert0 = unsafe(addr(r_p2[0])), pleftedgevert1 = unsafe(addr(r_p1[0])), pleftedgevert2 = null, numrightedges = 2, prightedgevert0 = unsafe(addr(r_p2[0])), prightedgevert1 = unsafe(addr(r_p0[0])), prightedgevert2 = unsafe(addr(r_p1[0]))), edgetable(isflattop = 0, numleftedges = 2, pleftedgevert0 = unsafe(addr(r_p2[0])), pleftedgevert1 = unsafe(addr(r_p1[0])), pleftedgevert2 = unsafe(addr(r_p0[0])), numrightedges = 1, prightedgevert0 = unsafe(addr(r_p2[0])), prightedgevert1 = unsafe(addr(r_p0[0])), prightedgevert2 = null), edgetable(isflattop = 0, numleftedges = 1, pleftedgevert0 = unsafe(addr(r_p1[0])), pleftedgevert1 = unsafe(addr(r_p0[0])), pleftedgevert2 = null, numrightedges = 1, prightedgevert0 = unsafe(addr(r_p1[0])), prightedgevert1 = unsafe(addr(r_p2[0])), prightedgevert2 = null), edgetable(isflattop = 1, numleftedges = 1, pleftedgevert0 = unsafe(addr(r_p2[0])), pleftedgevert1 = unsafe(addr(r_p1[0])), pleftedgevert2 = null, numrightedges = 1, prightedgevert0 = unsafe(addr(r_p0[0])), prightedgevert1 = unsafe(addr(r_p1[0])), prightedgevert2 = null), edgetable(isflattop = 1, numleftedges = 1, pleftedgevert0 = unsafe(addr(r_p1[0])), pleftedgevert1 = unsafe(addr(r_p0[0])), pleftedgevert2 = null, numrightedges = 1, prightedgevert0 = unsafe(addr(r_p2[0])), prightedgevert1 = unsafe(addr(r_p0[0])), prightedgevert2 = null), edgetable(isflattop = 0, numleftedges = 1, pleftedgevert0 = unsafe(addr(r_p0[0])), pleftedgevert1 = unsafe(addr(r_p2[0])), pleftedgevert2 = null, numrightedges = 1, prightedgevert0 = unsafe(addr(r_p0[0])), prightedgevert1 = unsafe(addr(r_p1[0])), prightedgevert2 = null))

[export, sideeffects]
def D_DrawSubdiv() {
    var ptri_0 : mtriangle_s?
    var pfv_0 : finalvert_s?
    var index0_0 : finalvert_s?
    var index1_0 : finalvert_s?
    var index2_0 : finalvert_s?
    var lnumtriangles_0 : int
    var s0 : int
    var s1 : int
    var s2 : int
    pfv_0 = unsafe(reinterpret<finalvert_s?>(r_affinetridesc.pfinalverts))
    ptri_0 = unsafe(reinterpret<mtriangle_s?>(r_affinetridesc.ptriangles))
    lnumtriangles_0 = r_affinetridesc.numtriangles
    for (i_0 in range(0, lnumtriangles_0)) {
        index0_0 = unsafe(reinterpret<finalvert_s?>(unsafe(pfv_0 + int64(unsafe(unsafe(addr(unsafe(ptri_0[i_0]).vertindex[0]))[0])))))
        index1_0 = unsafe(reinterpret<finalvert_s?>(unsafe(pfv_0 + int64(unsafe(unsafe(addr(unsafe(ptri_0[i_0]).vertindex[0]))[1])))))
        index2_0 = unsafe(reinterpret<finalvert_s?>(unsafe(pfv_0 + int64(unsafe(unsafe(addr(unsafe(ptri_0[i_0]).vertindex[0]))[2])))))
        var c2da_fresh29 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0_0))))
        var c2da_fresh30 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1_0))))
        var c2da_fresh31 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0_0))))
        var c2da_fresh32 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2_0))))
        var c2da_fresh33 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0_0))))
        var c2da_fresh34 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1_0))))
        var c2da_fresh35 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0_0))))
        var c2da_fresh36 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2_0))))
        if ((unsafe(unsafe(reinterpret<int?>(c2da_fresh29))[1]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh30))[1])) * (unsafe(unsafe(reinterpret<int?>(c2da_fresh31))[0]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh32))[0])) - (unsafe(unsafe(reinterpret<int?>(c2da_fresh33))[0]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh34))[0])) * (unsafe(unsafe(reinterpret<int?>(c2da_fresh35))[1]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh36))[1])) >= 0) {
            continue
        }
        var c2da_fresh37 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0_0))))
        d_pcolormap = unsafe(addr<uint8?>(unsafe(unsafe(reinterpret<uint8?>(acolormap))[unsafe(unsafe(reinterpret<int?>(c2da_fresh37))[4]) & 65280])))
        if (unsafe(ptri_0[i_0]).facesfront != 0) {
            var c2da_fresh38 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0_0))))
            var c2da_fresh39 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1_0))))
            var c2da_fresh40 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2_0))))
            D_PolysetRecursiveTriangle(unsafe(reinterpret<int?>(c2da_fresh38)), unsafe(reinterpret<int?>(c2da_fresh39)), unsafe(reinterpret<int?>(c2da_fresh40)))
        } else {
            var c2da_fresh41 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0_0))))
            s0 = unsafe(unsafe(reinterpret<int?>(c2da_fresh41))[2])
            var c2da_fresh42 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1_0))))
            s1 = unsafe(unsafe(reinterpret<int?>(c2da_fresh42))[2])
            var c2da_fresh43 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2_0))))
            s2 = unsafe(unsafe(reinterpret<int?>(c2da_fresh43))[2])
            if ((index0_0.flags & 32) != 0) {
                var c2da_fresh44 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0_0))))
                unsafe(unsafe(reinterpret<int?>(c2da_fresh44))[2]) = unsafe(unsafe(reinterpret<int?>(c2da_fresh44))[2]) + r_affinetridesc.seamfixupX16
            }
            if ((index1_0.flags & 32) != 0) {
                var c2da_fresh45 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1_0))))
                unsafe(unsafe(reinterpret<int?>(c2da_fresh45))[2]) = unsafe(unsafe(reinterpret<int?>(c2da_fresh45))[2]) + r_affinetridesc.seamfixupX16
            }
            if ((index2_0.flags & 32) != 0) {
                var c2da_fresh46 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2_0))))
                unsafe(unsafe(reinterpret<int?>(c2da_fresh46))[2]) = unsafe(unsafe(reinterpret<int?>(c2da_fresh46))[2]) + r_affinetridesc.seamfixupX16
            }
            var c2da_fresh47 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0_0))))
            var c2da_fresh48 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1_0))))
            var c2da_fresh49 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2_0))))
            D_PolysetRecursiveTriangle(unsafe(reinterpret<int?>(c2da_fresh47)), unsafe(reinterpret<int?>(c2da_fresh48)), unsafe(reinterpret<int?>(c2da_fresh49)))
            var c2da_fresh50 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index0_0))))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh50))[2]) = s0
            var c2da_fresh51 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index1_0))))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh51))[2]) = s1
            var c2da_fresh52 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(index2_0))))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh52))[2]) = s2
        }
    }
    return
}
[export, sideeffects]
def D_PolysetRecursiveTriangle(var lp1 : int?; var lp2 : int?; var lp3 : int?) {
    var temp : int?
    var d : int
    var new_0 : int[6]
    var z : int
    var zbuf : int16?
    var pix : int
    d = unsafe(lp2[0]) - unsafe(lp1[0])
    if (d < -1 || d > 1) {
        goto label 13
    }
    d = unsafe(lp2[1]) - unsafe(lp1[1])
    if (d < -1 || d > 1) {
        goto label 12
    }
    d = unsafe(lp3[0]) - unsafe(lp2[0])
    if (d < -1 || d > 1) {
        goto label 11
    }
    d = unsafe(lp3[1]) - unsafe(lp2[1])
    if (d < -1 || d > 1) {
        goto label 9
    }
    d = unsafe(lp1[0]) - unsafe(lp3[0])
    if (d < -1 || d > 1) {
        goto label 8
    }
    d = unsafe(lp1[1]) - unsafe(lp3[1])
    if (d < -1 || d > 1) {
        goto label 0
    }
    return
    label 0:
    label 1:
    temp = unsafe(reinterpret<int?>(lp1))
    lp1 = unsafe(reinterpret<int?>(lp3))
    lp3 = unsafe(reinterpret<int?>(lp2))
    lp2 = unsafe(reinterpret<int?>(temp))
    label 2:
    new_0[0] = unsafe(lp1[0]) + unsafe(lp2[0]) >> 1
    new_0[1] = unsafe(lp1[1]) + unsafe(lp2[1]) >> 1
    new_0[2] = unsafe(lp1[2]) + unsafe(lp2[2]) >> 1
    new_0[3] = unsafe(lp1[3]) + unsafe(lp2[3]) >> 1
    new_0[5] = unsafe(lp1[5]) + unsafe(lp2[5]) >> 1
    if (unsafe(lp2[1]) > unsafe(lp1[1])) {
        goto label 7
    }
    if (unsafe(lp2[1]) == unsafe(lp1[1]) && unsafe(lp2[0]) < unsafe(lp1[0])) {
        goto label 6
    }
    z = new_0[5] >> 16
    zbuf = unsafe(reinterpret<int16?>(unsafe(zspantable[new_0[1]] + new_0[0])))
    if (z >= int(*zbuf)) {
        goto label 5
    }
    label 3:
    label 4:
    D_PolysetRecursiveTriangle(lp3, lp1, unsafe(addr<int?>(new_0[0])))
    D_PolysetRecursiveTriangle(lp3, unsafe(addr<int?>(new_0[0])), lp2)
    return
    label 5:
    *zbuf = int16(z)
    pix = int(unsafe(d_pcolormap[int(unsafe(unsafe(reinterpret<uint8?>(skintable[new_0[3] >> 16]))[new_0[2] >> 16]))]))
    unsafe(d_viewbuffer[int(d_scantable[new_0[1]] + new_0[0])]) = uint8(pix)
    goto label 3
    label 6:
    goto label 4
    label 7:
    goto label 4
    label 8:
    goto label 1
    label 9:
    label 10:
    temp = unsafe(reinterpret<int?>(lp1))
    lp1 = unsafe(reinterpret<int?>(lp2))
    lp2 = unsafe(reinterpret<int?>(lp3))
    lp3 = unsafe(reinterpret<int?>(temp))
    goto label 2
    label 11:
    goto label 10
    label 12:
    goto label 2
    label 13:
    goto label 2
    panic("unreachable: fell out of a translated control-flow graph")
}
var skintable : uint8? [480]

var d_pcolormap : uint8? = default<uint8?>

[export, sideeffects]
def D_PolysetDrawFinalVerts(var fv_0 : finalvert_s?; var numverts : int) {
    var i_1 : int
    var z_0 : int
    var zbuf_0 : int16?
    var pix_0 : int
    var c2da_fv_0_addr : uint64 = unsafe(reinterpret<uint64>(fv_0))
    i_1 = 0
    while (i_1 < numverts) {
        var c2da_fresh53 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_0_addr))))))
        var c2da_fresh55 : int = 0
        if (unsafe(unsafe(reinterpret<int?>(c2da_fresh53))[0]) < r_refdef.vrectright) {
            var c2da_fresh54 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_0_addr))))))
            if (unsafe(unsafe(reinterpret<int?>(c2da_fresh54))[1]) < r_refdef.vrectbottom) {
                c2da_fresh55 = 1
            }
        }
        if (c2da_fresh55 != 0) {
            var c2da_fresh56 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_0_addr))))))
            z_0 = unsafe(unsafe(reinterpret<int?>(c2da_fresh56))[5]) >> 16
            var c2da_fresh57 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_0_addr))))))
            var c2da_fresh58 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_0_addr))))))
            zbuf_0 = unsafe(reinterpret<int16?>(unsafe(zspantable[unsafe(unsafe(reinterpret<int?>(c2da_fresh57))[1])] + int64(unsafe(unsafe(reinterpret<int?>(c2da_fresh58))[0])))))
            if (z_0 >= int(*zbuf_0)) {
                *zbuf_0 = int16(z_0)
                var c2da_fresh59 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_0_addr))))))
                var c2da_fresh60 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_0_addr))))))
                pix_0 = int(unsafe(unsafe(reinterpret<uint8?>(skintable[unsafe(unsafe(reinterpret<int?>(c2da_fresh59))[3]) >> 16]))[unsafe(unsafe(reinterpret<int?>(c2da_fresh60))[2]) >> 16]))
                var c2da_fresh61 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_0_addr))))))
                pix_0 = int(unsafe(unsafe(reinterpret<uint8?>(acolormap))[pix_0 + (unsafe(unsafe(reinterpret<int?>(c2da_fresh61))[4]) & 65280)]))
                var c2da_fresh62 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_0_addr))))))
                var c2da_fresh63 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_0_addr))))))
                unsafe(d_viewbuffer[int(d_scantable[unsafe(unsafe(reinterpret<int?>(c2da_fresh62))[1])] + unsafe(unsafe(reinterpret<int?>(c2da_fresh63))[0]))]) = uint8(pix_0)
            }
        }
        i_1++
        c2da_fv_0_addr += 32ul
    }
    return
}
[export, sideeffects]
def D_PolysetUpdateTables() {
    var i_2 : int
    var s : uint8?
    if (r_affinetridesc.skinwidth != skinwidth || r_affinetridesc.pskin != unsafe(reinterpret<uint8?>(skinstart))) {
        skinwidth = r_affinetridesc.skinwidth
        skinstart = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(r_affinetridesc.pskin))))
        s = unsafe(reinterpret<uint8?>(skinstart))
        i_2 = 0
        while (i_2 < 480) {
            skintable[i_2] = unsafe(reinterpret<uint8?>(s))
            i_2++
            unsafe {  // nolint:STYLE025
                s += int64(skinwidth)
            }
        }
    }
    return
}
var skinwidth : int = default<int>

var skinstart : uint8? = default<uint8?>

var d_aflatcolor : int = default<int>

[export, sideeffects]
def D_PolysetFillSpans8(var pspanpackage_0 : spanpackage_t?) {
    var color : int
    var lcount_0 : int
    var lpdest_0 : uint8?
    let c2da_postinc : int = d_aflatcolor
    d_aflatcolor++
    color = c2da_postinc
    var c2da_pspanpackage_0_addr : uint64 = unsafe(reinterpret<uint64>(pspanpackage_0))
    while (true) {
        lcount_0 = unsafe(reinterpret<spanpackage_t?>(c2da_pspanpackage_0_addr)).count
        if (lcount_0 == -1) {
            return
        }
        if (lcount_0 != 0) {
            lpdest_0 = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(unsafe(reinterpret<spanpackage_t?>(c2da_pspanpackage_0_addr)).pdest))))
            var c2da_lpdest_0_addr : uint64 = unsafe(reinterpret<uint64>(lpdest_0))
            while (true) {
                *unsafe(reinterpret<uint8?>(c2da_lpdest_0_addr)) = uint8(color)
                c2da_lpdest_0_addr++
                lcount_0--
                if (lcount_0 == 0) {
                    break
                }
            }
            lpdest_0 = unsafe(reinterpret<uint8?>(c2da_lpdest_0_addr))
        }
        c2da_pspanpackage_0_addr += 48ul
    }
}
[sideeffects]
def private c2da_layout_proofs_13() {
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
    static_assert(typeinfo sizeof(type<maliasskindesc_t>) == 24, "C layout of maliasskindesc_t: sizeof")
    static_assert(typeinfo alignof(type<maliasskindesc_t>) == 8, "C layout of maliasskindesc_t: alignof")
    static_assert(typeinfo offsetof<type_0>(type<maliasskindesc_t>) == 0, "C layout of maliasskindesc_t: offsetof type_0")
    static_assert(typeinfo offsetof<pcachespot>(type<maliasskindesc_t>) == 8, "C layout of maliasskindesc_t: offsetof pcachespot")
    static_assert(typeinfo offsetof<skin>(type<maliasskindesc_t>) == 16, "C layout of maliasskindesc_t: offsetof skin")
    static_assert(typeinfo sizeof(type<mtriangle_s>) == 16, "C layout of mtriangle_s: sizeof")
    static_assert(typeinfo alignof(type<mtriangle_s>) == 4, "C layout of mtriangle_s: alignof")
    static_assert(typeinfo offsetof<facesfront>(type<mtriangle_s>) == 0, "C layout of mtriangle_s: offsetof facesfront")
    static_assert(typeinfo offsetof<vertindex>(type<mtriangle_s>) == 4, "C layout of mtriangle_s: offsetof vertindex")
    static_assert(typeinfo sizeof(type<mtriangle_t>) == 16, "C layout of mtriangle_t: sizeof")
    static_assert(typeinfo alignof(type<mtriangle_t>) == 4, "C layout of mtriangle_t: alignof")
    static_assert(typeinfo offsetof<facesfront>(type<mtriangle_t>) == 0, "C layout of mtriangle_t: offsetof facesfront")
    static_assert(typeinfo offsetof<vertindex>(type<mtriangle_t>) == 4, "C layout of mtriangle_t: offsetof vertindex")
    static_assert(typeinfo sizeof(type<finalvert_s>) == 32, "C layout of finalvert_s: sizeof")
    static_assert(typeinfo alignof(type<finalvert_s>) == 4, "C layout of finalvert_s: alignof")
    static_assert(typeinfo offsetof<v>(type<finalvert_s>) == 0, "C layout of finalvert_s: offsetof v")
    static_assert(typeinfo offsetof<flags>(type<finalvert_s>) == 24, "C layout of finalvert_s: offsetof flags")
    static_assert(typeinfo offsetof<reserved>(type<finalvert_s>) == 28, "C layout of finalvert_s: offsetof reserved")
    static_assert(typeinfo sizeof(type<finalvert_t>) == 32, "C layout of finalvert_t: sizeof")
    static_assert(typeinfo alignof(type<finalvert_t>) == 4, "C layout of finalvert_t: alignof")
    static_assert(typeinfo offsetof<v>(type<finalvert_t>) == 0, "C layout of finalvert_t: offsetof v")
    static_assert(typeinfo offsetof<flags>(type<finalvert_t>) == 24, "C layout of finalvert_t: offsetof flags")
    static_assert(typeinfo offsetof<reserved>(type<finalvert_t>) == 28, "C layout of finalvert_t: offsetof reserved")
    static_assert(typeinfo sizeof(type<affinetridesc_t>) == 56, "C layout of affinetridesc_t: sizeof")
    static_assert(typeinfo alignof(type<affinetridesc_t>) == 8, "C layout of affinetridesc_t: alignof")
    static_assert(typeinfo offsetof<pskin>(type<affinetridesc_t>) == 0, "C layout of affinetridesc_t: offsetof pskin")
    static_assert(typeinfo offsetof<pskindesc>(type<affinetridesc_t>) == 8, "C layout of affinetridesc_t: offsetof pskindesc")
    static_assert(typeinfo offsetof<skinwidth>(type<affinetridesc_t>) == 16, "C layout of affinetridesc_t: offsetof skinwidth")
    static_assert(typeinfo offsetof<skinheight>(type<affinetridesc_t>) == 20, "C layout of affinetridesc_t: offsetof skinheight")
    static_assert(typeinfo offsetof<ptriangles>(type<affinetridesc_t>) == 24, "C layout of affinetridesc_t: offsetof ptriangles")
    static_assert(typeinfo offsetof<pfinalverts>(type<affinetridesc_t>) == 32, "C layout of affinetridesc_t: offsetof pfinalverts")
    static_assert(typeinfo offsetof<numtriangles>(type<affinetridesc_t>) == 40, "C layout of affinetridesc_t: offsetof numtriangles")
    static_assert(typeinfo offsetof<drawtype>(type<affinetridesc_t>) == 44, "C layout of affinetridesc_t: offsetof drawtype")
    static_assert(typeinfo offsetof<seamfixupX16>(type<affinetridesc_t>) == 48, "C layout of affinetridesc_t: offsetof seamfixupX16")
    static_assert(typeinfo sizeof(type<spanpackage_t>) == 48, "C layout of spanpackage_t: sizeof")
    static_assert(typeinfo alignof(type<spanpackage_t>) == 8, "C layout of spanpackage_t: alignof")
    static_assert(typeinfo offsetof<pdest>(type<spanpackage_t>) == 0, "C layout of spanpackage_t: offsetof pdest")
    static_assert(typeinfo offsetof<pz>(type<spanpackage_t>) == 8, "C layout of spanpackage_t: offsetof pz")
    static_assert(typeinfo offsetof<count>(type<spanpackage_t>) == 16, "C layout of spanpackage_t: offsetof count")
    static_assert(typeinfo offsetof<ptex>(type<spanpackage_t>) == 24, "C layout of spanpackage_t: offsetof ptex")
    static_assert(typeinfo offsetof<sfrac>(type<spanpackage_t>) == 32, "C layout of spanpackage_t: offsetof sfrac")
    static_assert(typeinfo offsetof<tfrac>(type<spanpackage_t>) == 36, "C layout of spanpackage_t: offsetof tfrac")
    static_assert(typeinfo offsetof<light>(type<spanpackage_t>) == 40, "C layout of spanpackage_t: offsetof light")
    static_assert(typeinfo offsetof<zi>(type<spanpackage_t>) == 44, "C layout of spanpackage_t: offsetof zi")
    static_assert(typeinfo sizeof(type<adivtab_t>) == 8, "C layout of adivtab_t: sizeof")
    static_assert(typeinfo alignof(type<adivtab_t>) == 4, "C layout of adivtab_t: alignof")
    static_assert(typeinfo offsetof<quotient>(type<adivtab_t>) == 0, "C layout of adivtab_t: offsetof quotient")
    static_assert(typeinfo offsetof<remainder>(type<adivtab_t>) == 4, "C layout of adivtab_t: offsetof remainder")
    static_assert(typeinfo sizeof(type<edgetable>) == 64, "C layout of edgetable: sizeof")
    static_assert(typeinfo alignof(type<edgetable>) == 8, "C layout of edgetable: alignof")
    static_assert(typeinfo offsetof<isflattop>(type<edgetable>) == 0, "C layout of edgetable: offsetof isflattop")
    static_assert(typeinfo offsetof<numleftedges>(type<edgetable>) == 4, "C layout of edgetable: offsetof numleftedges")
    static_assert(typeinfo offsetof<pleftedgevert0>(type<edgetable>) == 8, "C layout of edgetable: offsetof pleftedgevert0")
    static_assert(typeinfo offsetof<pleftedgevert1>(type<edgetable>) == 16, "C layout of edgetable: offsetof pleftedgevert1")
    static_assert(typeinfo offsetof<pleftedgevert2>(type<edgetable>) == 24, "C layout of edgetable: offsetof pleftedgevert2")
    static_assert(typeinfo offsetof<numrightedges>(type<edgetable>) == 32, "C layout of edgetable: offsetof numrightedges")
    static_assert(typeinfo offsetof<prightedgevert0>(type<edgetable>) == 40, "C layout of edgetable: offsetof prightedgevert0")
    static_assert(typeinfo offsetof<prightedgevert1>(type<edgetable>) == 48, "C layout of edgetable: offsetof prightedgevert1")
    static_assert(typeinfo offsetof<prightedgevert2>(type<edgetable>) == 56, "C layout of edgetable: offsetof prightedgevert2")
}
