[export, sideeffects]
def R_AliasClipTriangle(var ptri : mtriangle_s?) {
    var i : int
    var k : int
    var pingpong : int
    var mtri : mtriangle_s
    var clipflags : uint
    if (ptri.facesfront != 0) {
        var c2da_fresh0 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(ptri)) + 4ul))
        fv_0[0][0] = unsafe(pfinalverts[unsafe(unsafe(reinterpret<int?>(c2da_fresh0))[0])])
        var c2da_fresh1 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(ptri)) + 4ul))
        fv_0[0][1] = unsafe(pfinalverts[unsafe(unsafe(reinterpret<int?>(c2da_fresh1))[1])])
        var c2da_fresh2 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(ptri)) + 4ul))
        fv_0[0][2] = unsafe(pfinalverts[unsafe(unsafe(reinterpret<int?>(c2da_fresh2))[2])])
    } else {
        i = 0
        while (i < 3) {
            var c2da_fresh3 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(ptri)) + 4ul))
            fv_0[0][i] = unsafe(pfinalverts[unsafe(unsafe(reinterpret<int?>(c2da_fresh3))[i])])
            if (ptri.facesfront == 0 && (fv_0[0][i].flags & 32) != 0) {
                unsafe(unsafe(addr(fv_0[0][i].v[0]))[2]) = unsafe(unsafe(addr(fv_0[0][i].v[0]))[2]) + r_affinetridesc.seamfixupX16
            }
            i++
        }
    }
    clipflags = uint(fv_0[0][0].flags | fv_0[0][1].flags | fv_0[0][2].flags)
    if ((clipflags & 0x10u) != 0x0) {
        i = 0
        while (i < 3) {
            var c2da_fresh4 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(ptri)) + 4ul))
            av[i] = unsafe(pauxverts[unsafe(unsafe(reinterpret<int?>(c2da_fresh4))[i])])
            i++
        }
        k = R_AliasClip(unsafe(addr<finalvert_s?>(fv_0[0][0])), unsafe(addr<finalvert_s?>(fv_0[1][0])), 16, 3, @@R_Alias_clip_z)
        if (k == 0) {
            return
        }
        pingpong = 1
        clipflags = uint(fv_0[1][0].flags | fv_0[1][1].flags | fv_0[1][2].flags)
    } else {
        pingpong = 0
        k = 3
    }
    if ((clipflags & 0x1u) != 0x0) {
        k = R_AliasClip(unsafe(addr<finalvert_s?>(fv_0[pingpong][0])), unsafe(addr<finalvert_s?>(fv_0[pingpong ^ 1][0])), 1, k, @@R_Alias_clip_left)
        if (k == 0) {
            return
        }
        pingpong ^= 1
    }
    if ((clipflags & 0x4u) != 0x0) {
        k = R_AliasClip(unsafe(addr<finalvert_s?>(fv_0[pingpong][0])), unsafe(addr<finalvert_s?>(fv_0[pingpong ^ 1][0])), 4, k, @@R_Alias_clip_right)
        if (k == 0) {
            return
        }
        pingpong ^= 1
    }
    if ((clipflags & 0x8u) != 0x0) {
        k = R_AliasClip(unsafe(addr<finalvert_s?>(fv_0[pingpong][0])), unsafe(addr<finalvert_s?>(fv_0[pingpong ^ 1][0])), 8, k, @@R_Alias_clip_bottom)
        if (k == 0) {
            return
        }
        pingpong ^= 1
    }
    if ((clipflags & 0x2u) != 0x0) {
        k = R_AliasClip(unsafe(addr<finalvert_s?>(fv_0[pingpong][0])), unsafe(addr<finalvert_s?>(fv_0[pingpong ^ 1][0])), 2, k, @@R_Alias_clip_top)
        if (k == 0) {
            return
        }
        pingpong ^= 1
    }
    i = 0
    while (i < k) {
        if (unsafe(unsafe(addr(fv_0[pingpong][i].v[0]))[0]) < r_refdef.aliasvrect.x) {
            unsafe(unsafe(addr(fv_0[pingpong][i].v[0]))[0]) = r_refdef.aliasvrect.x
        } elif (unsafe(unsafe(addr(fv_0[pingpong][i].v[0]))[0]) > r_refdef.aliasvrectright) {
            unsafe(unsafe(addr(fv_0[pingpong][i].v[0]))[0]) = r_refdef.aliasvrectright
        }
        if (unsafe(unsafe(addr(fv_0[pingpong][i].v[0]))[1]) < r_refdef.aliasvrect.y) {
            unsafe(unsafe(addr(fv_0[pingpong][i].v[0]))[1]) = r_refdef.aliasvrect.y
        } elif (unsafe(unsafe(addr(fv_0[pingpong][i].v[0]))[1]) > r_refdef.aliasvrectbottom) {
            unsafe(unsafe(addr(fv_0[pingpong][i].v[0]))[1]) = r_refdef.aliasvrectbottom
        }
        fv_0[pingpong][i].flags = 0
        i++
    }
    mtri.facesfront = ptri.facesfront
    r_affinetridesc.ptriangles = unsafe(addr<mtriangle_s?>(mtri))
    r_affinetridesc.pfinalverts = unsafe(addr<finalvert_s?>(fv_0[pingpong][0]))
    unsafe(unsafe(addr(mtri.vertindex[0]))[0]) = 0
    i = 1
    for (c2da_i in range(i, k - 1)) {
        unsafe(unsafe(addr(mtri.vertindex[0]))[1]) = c2da_i
        unsafe(unsafe(addr(mtri.vertindex[0]))[2]) = c2da_i + 1
        D_PolysetDraw()
    }
    return
}
var private fv_0 : finalvert_s[2][8]

[export, sideeffects]
def R_Alias_clip_top(var pfv0 : finalvert_s?; var pfv1 : finalvert_s?; var out : finalvert_s?) {
    var scale : float
    var i_0 : int
    var c2da_fresh5 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0))))
    var c2da_fresh6 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1))))
    if (unsafe(unsafe(reinterpret<int?>(c2da_fresh5))[1]) >= unsafe(unsafe(reinterpret<int?>(c2da_fresh6))[1])) {
        var c2da_fresh7 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0))))
        var c2da_fresh8 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1))))
        var c2da_fresh9 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0))))
        scale = float(r_refdef.aliasvrect.y - unsafe(unsafe(reinterpret<int?>(c2da_fresh7))[1])) / float(unsafe(unsafe(reinterpret<int?>(c2da_fresh8))[1]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh9))[1]))
        i_0 = 0
        for (c2da_i_0 in range(i_0, 6)) {
            var c2da_fresh10 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out))))
            var c2da_fresh11 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0))))
            var c2da_fresh12 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1))))
            var c2da_fresh13 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0))))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh10))[c2da_i_0]) = int(double(float(unsafe(unsafe(reinterpret<int?>(c2da_fresh11))[c2da_i_0])) + float(unsafe(unsafe(reinterpret<int?>(c2da_fresh12))[c2da_i_0]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh13))[c2da_i_0])) * scale) + 0.5lf)
        }
    } else {
        var c2da_fresh14 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1))))
        var c2da_fresh15 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0))))
        var c2da_fresh16 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1))))
        scale = float(r_refdef.aliasvrect.y - unsafe(unsafe(reinterpret<int?>(c2da_fresh14))[1])) / float(unsafe(unsafe(reinterpret<int?>(c2da_fresh15))[1]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh16))[1]))
        i_0 = 0
        for (c2da_i_0_0 in range(i_0, 6)) {
            var c2da_fresh17 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out))))
            var c2da_fresh18 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1))))
            var c2da_fresh19 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0))))
            var c2da_fresh20 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1))))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh17))[c2da_i_0_0]) = int(double(float(unsafe(unsafe(reinterpret<int?>(c2da_fresh18))[c2da_i_0_0])) + float(unsafe(unsafe(reinterpret<int?>(c2da_fresh19))[c2da_i_0_0]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh20))[c2da_i_0_0])) * scale) + 0.5lf)
        }
    }
    return
}
[export, sideeffects]
def R_AliasClip(var in_0 : finalvert_s?; var out_0 : finalvert_s?; var flag : int; var count : int; var clip : function<(var _arg0:finalvert_s?;var _arg1:finalvert_s?;var _arg2:finalvert_s?):void>) : int {
    var i_1 : int
    var j : int
    var k_0 : int
    var flags : int
    var oldflags : int
    j = count - 1
    k_0 = 0
    i_1 = 0
    while (i_1 < count) {
        oldflags = unsafe(in_0[j]).flags & flag
        flags = unsafe(in_0[i_1]).flags & flag
        if (flags != 0 && oldflags != 0) {
            j = i_1
            i_1++
            continue
        }
        if ((oldflags ^ flags) != 0) {
            invoke(clip, unsafe(addr(unsafe(in_0[j]))), unsafe(addr(unsafe(in_0[i_1]))), unsafe(addr(unsafe(out_0[k_0]))))
            unsafe(out_0[k_0]).flags = 0
            if (unsafe(unsafe(addr(unsafe(out_0[k_0]).v[0]))[0]) < r_refdef.aliasvrect.x) {
                unsafe(out_0[k_0]).flags |= 1
            }
            if (unsafe(unsafe(addr(unsafe(out_0[k_0]).v[0]))[1]) < r_refdef.aliasvrect.y) {
                unsafe(out_0[k_0]).flags |= 2
            }
            if (unsafe(unsafe(addr(unsafe(out_0[k_0]).v[0]))[0]) > r_refdef.aliasvrectright) {
                unsafe(out_0[k_0]).flags |= 4
            }
            if (unsafe(unsafe(addr(unsafe(out_0[k_0]).v[0]))[1]) > r_refdef.aliasvrectbottom) {
                unsafe(out_0[k_0]).flags |= 8
            }
            k_0++
        }
        if (flags == 0) {
            unsafe(out_0[k_0]) = unsafe(in_0[i_1])
            k_0++
        }
        j = i_1
        i_1++
    }
    return k_0
}
[export, sideeffects]
def R_Alias_clip_bottom(var pfv0_0 : finalvert_s?; var pfv1_0 : finalvert_s?; var out_1 : finalvert_s?) {
    var scale_0 : float
    var i_2 : int
    var c2da_fresh21 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_0))))
    var c2da_fresh22 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_0))))
    if (unsafe(unsafe(reinterpret<int?>(c2da_fresh21))[1]) >= unsafe(unsafe(reinterpret<int?>(c2da_fresh22))[1])) {
        var c2da_fresh23 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_0))))
        var c2da_fresh24 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_0))))
        var c2da_fresh25 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_0))))
        scale_0 = float(r_refdef.aliasvrectbottom - unsafe(unsafe(reinterpret<int?>(c2da_fresh23))[1])) / float(unsafe(unsafe(reinterpret<int?>(c2da_fresh24))[1]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh25))[1]))
        i_2 = 0
        for (c2da_i_2 in range(i_2, 6)) {
            var c2da_fresh26 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_1))))
            var c2da_fresh27 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_0))))
            var c2da_fresh28 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_0))))
            var c2da_fresh29 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_0))))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh26))[c2da_i_2]) = int(double(float(unsafe(unsafe(reinterpret<int?>(c2da_fresh27))[c2da_i_2])) + float(unsafe(unsafe(reinterpret<int?>(c2da_fresh28))[c2da_i_2]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh29))[c2da_i_2])) * scale_0) + 0.5lf)
        }
    } else {
        var c2da_fresh30 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_0))))
        var c2da_fresh31 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_0))))
        var c2da_fresh32 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_0))))
        scale_0 = float(r_refdef.aliasvrectbottom - unsafe(unsafe(reinterpret<int?>(c2da_fresh30))[1])) / float(unsafe(unsafe(reinterpret<int?>(c2da_fresh31))[1]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh32))[1]))
        i_2 = 0
        for (c2da_i_2_0 in range(i_2, 6)) {
            var c2da_fresh33 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_1))))
            var c2da_fresh34 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_0))))
            var c2da_fresh35 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_0))))
            var c2da_fresh36 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_0))))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh33))[c2da_i_2_0]) = int(double(float(unsafe(unsafe(reinterpret<int?>(c2da_fresh34))[c2da_i_2_0])) + float(unsafe(unsafe(reinterpret<int?>(c2da_fresh35))[c2da_i_2_0]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh36))[c2da_i_2_0])) * scale_0) + 0.5lf)
        }
    }
    return
}
[export, sideeffects]
def R_Alias_clip_right(var pfv0_1 : finalvert_s?; var pfv1_1 : finalvert_s?; var out_2 : finalvert_s?) {
    var scale_1 : float
    var i_3 : int
    var c2da_fresh37 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_1))))
    var c2da_fresh38 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_1))))
    if (unsafe(unsafe(reinterpret<int?>(c2da_fresh37))[1]) >= unsafe(unsafe(reinterpret<int?>(c2da_fresh38))[1])) {
        var c2da_fresh39 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_1))))
        var c2da_fresh40 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_1))))
        var c2da_fresh41 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_1))))
        scale_1 = float(r_refdef.aliasvrectright - unsafe(unsafe(reinterpret<int?>(c2da_fresh39))[0])) / float(unsafe(unsafe(reinterpret<int?>(c2da_fresh40))[0]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh41))[0]))
        i_3 = 0
        for (c2da_i_3 in range(i_3, 6)) {
            var c2da_fresh42 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_2))))
            var c2da_fresh43 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_1))))
            var c2da_fresh44 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_1))))
            var c2da_fresh45 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_1))))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh42))[c2da_i_3]) = int(double(float(unsafe(unsafe(reinterpret<int?>(c2da_fresh43))[c2da_i_3])) + float(unsafe(unsafe(reinterpret<int?>(c2da_fresh44))[c2da_i_3]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh45))[c2da_i_3])) * scale_1) + 0.5lf)
        }
    } else {
        var c2da_fresh46 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_1))))
        var c2da_fresh47 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_1))))
        var c2da_fresh48 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_1))))
        scale_1 = float(r_refdef.aliasvrectright - unsafe(unsafe(reinterpret<int?>(c2da_fresh46))[0])) / float(unsafe(unsafe(reinterpret<int?>(c2da_fresh47))[0]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh48))[0]))
        i_3 = 0
        for (c2da_i_3_0 in range(i_3, 6)) {
            var c2da_fresh49 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_2))))
            var c2da_fresh50 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_1))))
            var c2da_fresh51 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_1))))
            var c2da_fresh52 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_1))))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh49))[c2da_i_3_0]) = int(double(float(unsafe(unsafe(reinterpret<int?>(c2da_fresh50))[c2da_i_3_0])) + float(unsafe(unsafe(reinterpret<int?>(c2da_fresh51))[c2da_i_3_0]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh52))[c2da_i_3_0])) * scale_1) + 0.5lf)
        }
    }
    return
}
[export, sideeffects]
def R_Alias_clip_left(var pfv0_2 : finalvert_s?; var pfv1_2 : finalvert_s?; var out_3 : finalvert_s?) {
    var scale_2 : float
    var i_4 : int
    var c2da_fresh53 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_2))))
    var c2da_fresh54 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_2))))
    if (unsafe(unsafe(reinterpret<int?>(c2da_fresh53))[1]) >= unsafe(unsafe(reinterpret<int?>(c2da_fresh54))[1])) {
        var c2da_fresh55 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_2))))
        var c2da_fresh56 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_2))))
        var c2da_fresh57 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_2))))
        scale_2 = float(r_refdef.aliasvrect.x - unsafe(unsafe(reinterpret<int?>(c2da_fresh55))[0])) / float(unsafe(unsafe(reinterpret<int?>(c2da_fresh56))[0]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh57))[0]))
        i_4 = 0
        for (c2da_i_4 in range(i_4, 6)) {
            var c2da_fresh58 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_3))))
            var c2da_fresh59 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_2))))
            var c2da_fresh60 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_2))))
            var c2da_fresh61 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_2))))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh58))[c2da_i_4]) = int(double(float(unsafe(unsafe(reinterpret<int?>(c2da_fresh59))[c2da_i_4])) + float(unsafe(unsafe(reinterpret<int?>(c2da_fresh60))[c2da_i_4]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh61))[c2da_i_4])) * scale_2) + 0.5lf)
        }
    } else {
        var c2da_fresh62 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_2))))
        var c2da_fresh63 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_2))))
        var c2da_fresh64 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_2))))
        scale_2 = float(r_refdef.aliasvrect.x - unsafe(unsafe(reinterpret<int?>(c2da_fresh62))[0])) / float(unsafe(unsafe(reinterpret<int?>(c2da_fresh63))[0]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh64))[0]))
        i_4 = 0
        for (c2da_i_4_0 in range(i_4, 6)) {
            var c2da_fresh65 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_3))))
            var c2da_fresh66 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_2))))
            var c2da_fresh67 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_2))))
            var c2da_fresh68 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_2))))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh65))[c2da_i_4_0]) = int(double(float(unsafe(unsafe(reinterpret<int?>(c2da_fresh66))[c2da_i_4_0])) + float(unsafe(unsafe(reinterpret<int?>(c2da_fresh67))[c2da_i_4_0]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh68))[c2da_i_4_0])) * scale_2) + 0.5lf)
        }
    }
    return
}
[export, sideeffects]
def R_Alias_clip_z(var pfv0_3 : finalvert_s?; var pfv1_3 : finalvert_s?; var out_4 : finalvert_s?) {
    var scale_3 : float
    var pav0 : auxvert_t?
    var pav1 : auxvert_t?
    var avout : auxvert_t
    pav0 = unsafe(addr<auxvert_t?>(unsafe(unsafe(addr(av[0]))[int(unsafe(pfv0_3 - unsafe(addr(unsafe(unsafe(addr(fv_0[0][0]))[0])))))])))
    pav1 = unsafe(addr<auxvert_t?>(unsafe(unsafe(addr(av[0]))[int(unsafe(pfv1_3 - unsafe(addr(unsafe(unsafe(addr(fv_0[0][0]))[0])))))])))
    var c2da_fresh69 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_3))))
    var c2da_fresh70 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_3))))
    if (unsafe(unsafe(reinterpret<int?>(c2da_fresh69))[1]) >= unsafe(unsafe(reinterpret<int?>(c2da_fresh70))[1])) {
        var c2da_fresh71 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav0))))
        var c2da_fresh72 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav1))))
        var c2da_fresh73 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav0))))
        scale_3 = (5.0 - unsafe(unsafe(reinterpret<float?>(c2da_fresh71))[2])) / (unsafe(unsafe(reinterpret<float?>(c2da_fresh72))[2]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh73))[2]))
        var c2da_fresh74 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav0))))
        var c2da_fresh75 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav1))))
        var c2da_fresh76 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav0))))
        unsafe(unsafe(addr(avout.fv[0]))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh74))[0]) + (unsafe(unsafe(reinterpret<float?>(c2da_fresh75))[0]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh76))[0])) * scale_3
        var c2da_fresh77 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav0))))
        var c2da_fresh78 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav1))))
        var c2da_fresh79 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav0))))
        unsafe(unsafe(addr(avout.fv[0]))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh77))[1]) + (unsafe(unsafe(reinterpret<float?>(c2da_fresh78))[1]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh79))[1])) * scale_3
        unsafe(unsafe(addr(avout.fv[0]))[2]) = 5.0
        var c2da_fresh80 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_4))))
        var c2da_fresh81 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_3))))
        var c2da_fresh82 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_3))))
        var c2da_fresh83 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_3))))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh80))[2]) = int(float(unsafe(unsafe(reinterpret<int?>(c2da_fresh81))[2])) + float(unsafe(unsafe(reinterpret<int?>(c2da_fresh82))[2]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh83))[2])) * scale_3)
        var c2da_fresh84 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_4))))
        var c2da_fresh85 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_3))))
        var c2da_fresh86 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_3))))
        var c2da_fresh87 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_3))))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh84))[3]) = int(float(unsafe(unsafe(reinterpret<int?>(c2da_fresh85))[3])) + float(unsafe(unsafe(reinterpret<int?>(c2da_fresh86))[3]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh87))[3])) * scale_3)
        var c2da_fresh88 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_4))))
        var c2da_fresh89 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_3))))
        var c2da_fresh90 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_3))))
        var c2da_fresh91 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_3))))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh88))[4]) = int(float(unsafe(unsafe(reinterpret<int?>(c2da_fresh89))[4])) + float(unsafe(unsafe(reinterpret<int?>(c2da_fresh90))[4]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh91))[4])) * scale_3)
    } else {
        var c2da_fresh92 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav1))))
        var c2da_fresh93 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav0))))
        var c2da_fresh94 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav1))))
        scale_3 = (5.0 - unsafe(unsafe(reinterpret<float?>(c2da_fresh92))[2])) / (unsafe(unsafe(reinterpret<float?>(c2da_fresh93))[2]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh94))[2]))
        var c2da_fresh95 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav1))))
        var c2da_fresh96 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav0))))
        var c2da_fresh97 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav1))))
        unsafe(unsafe(addr(avout.fv[0]))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh95))[0]) + (unsafe(unsafe(reinterpret<float?>(c2da_fresh96))[0]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh97))[0])) * scale_3
        var c2da_fresh98 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav1))))
        var c2da_fresh99 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav0))))
        var c2da_fresh100 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pav1))))
        unsafe(unsafe(addr(avout.fv[0]))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh98))[1]) + (unsafe(unsafe(reinterpret<float?>(c2da_fresh99))[1]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh100))[1])) * scale_3
        unsafe(unsafe(addr(avout.fv[0]))[2]) = 5.0
        var c2da_fresh101 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_4))))
        var c2da_fresh102 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_3))))
        var c2da_fresh103 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_3))))
        var c2da_fresh104 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_3))))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh101))[2]) = int(float(unsafe(unsafe(reinterpret<int?>(c2da_fresh102))[2])) + float(unsafe(unsafe(reinterpret<int?>(c2da_fresh103))[2]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh104))[2])) * scale_3)
        var c2da_fresh105 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_4))))
        var c2da_fresh106 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_3))))
        var c2da_fresh107 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_3))))
        var c2da_fresh108 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_3))))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh105))[3]) = int(float(unsafe(unsafe(reinterpret<int?>(c2da_fresh106))[3])) + float(unsafe(unsafe(reinterpret<int?>(c2da_fresh107))[3]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh108))[3])) * scale_3)
        var c2da_fresh109 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_4))))
        var c2da_fresh110 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_3))))
        var c2da_fresh111 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv0_3))))
        var c2da_fresh112 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(pfv1_3))))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh109))[4]) = int(float(unsafe(unsafe(reinterpret<int?>(c2da_fresh110))[4])) + float(unsafe(unsafe(reinterpret<int?>(c2da_fresh111))[4]) - unsafe(unsafe(reinterpret<int?>(c2da_fresh112))[4])) * scale_3)
    }
    R_AliasProjectFinalVert(out_4, unsafe(addr<auxvert_t?>(avout)))
    var c2da_fresh113 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_4))))
    if (unsafe(unsafe(reinterpret<int?>(c2da_fresh113))[0]) < r_refdef.aliasvrect.x) {
        out_4.flags |= 1
    }
    var c2da_fresh114 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_4))))
    if (unsafe(unsafe(reinterpret<int?>(c2da_fresh114))[1]) < r_refdef.aliasvrect.y) {
        out_4.flags |= 2
    }
    var c2da_fresh115 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_4))))
    if (unsafe(unsafe(reinterpret<int?>(c2da_fresh115))[0]) > r_refdef.aliasvrectright) {
        out_4.flags |= 4
    }
    var c2da_fresh116 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(out_4))))
    if (unsafe(unsafe(reinterpret<int?>(c2da_fresh116))[1]) > r_refdef.aliasvrectbottom) {
        out_4.flags |= 8
    }
    return
}
var private av : auxvert_t[8]

[sideeffects]
def private c2da_layout_proofs_32() {
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
    static_assert(typeinfo sizeof(type<auxvert_t>) == 12, "C layout of auxvert_t: sizeof")
    static_assert(typeinfo alignof(type<auxvert_t>) == 4, "C layout of auxvert_t: alignof")
    static_assert(typeinfo offsetof<fv>(type<auxvert_t>) == 0, "C layout of auxvert_t: offsetof fv")
}
