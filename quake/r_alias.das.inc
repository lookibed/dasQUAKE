var private c2da_str_r_alias_0 : array<int8> = [int8(82), int8(95), int8(65), int8(108), int8(105), int8(97), int8(115), int8(68), int8(114), int8(97), int8(119), int8(77), int8(111), int8(100), int8(101), int8(108), int8(58), int8(32), int8(33), int8(99), int8(117), int8(114), int8(114), int8(101), int8(110), int8(116), int8(101), int8(110), int8(116), int8(105), int8(116), int8(121), int8(45), int8(62), int8(99), int8(111), int8(108), int8(111), int8(114), int8(109), int8(97), int8(112), int8(0)]

var private c2da_str_r_alias_1 : array<int8> = [int8(82), int8(95), int8(65), int8(108), int8(105), int8(97), int8(115), int8(83), int8(101), int8(116), int8(117), int8(112), int8(70), int8(114), int8(97), int8(109), int8(101), int8(58), int8(32), int8(110), int8(111), int8(32), int8(115), int8(117), int8(99), int8(104), int8(32), int8(102), int8(114), int8(97), int8(109), int8(101), int8(32), int8(37), int8(100), int8(10), int8(0)]

var private c2da_str_r_alias_2 : array<int8> = [int8(82), int8(95), int8(65), int8(108), int8(105), int8(97), int8(115), int8(83), int8(101), int8(116), int8(117), int8(112), int8(83), int8(107), int8(105), int8(110), int8(58), int8(32), int8(110), int8(111), int8(32), int8(115), int8(117), int8(99), int8(104), int8(32), int8(115), int8(107), int8(105), int8(110), int8(32), int8(35), int8(32), int8(37), int8(100), int8(10), int8(0)]

var private c2da_str_r_alias_3 : array<int8> = [int8(78), int8(111), int8(32), int8(115), int8(117), int8(99), int8(104), int8(32), int8(102), int8(114), int8(97), int8(109), int8(101), int8(32), int8(37), int8(100), int8(32), int8(37), int8(115), int8(10), int8(0)]

var private R_AliasSetUpTransform__tmatrix : float[3][4] = fixed_array<float[4]>(fixed_array<float>(0.0, 0.0, 0.0, 0.0), fixed_array<float>(0.0, 0.0, 0.0, 0.0), fixed_array<float>(0.0, 0.0, 0.0, 0.0))

var private R_AliasSetUpTransform__viewmatrix : float[3][4] = fixed_array<float[4]>(fixed_array<float>(0.0, 0.0, 0.0, 0.0), fixed_array<float>(0.0, 0.0, 0.0, 0.0), fixed_array<float>(0.0, 0.0, 0.0, 0.0))

var r_affinetridesc : affinetridesc_t = default<affinetridesc_t>

var acolormap : uint8? = default<uint8?>

[export, sideeffects]
def R_AliasDrawModel(var plighting : alight_t?) {
    var finalverts : finalvert_s[2001]
    var auxverts : auxvert_t[2000]
    r_amodels_drawn++
    pfinalverts = unsafe(reinterpret<finalvert_s?>(unsafe(reinterpret<finalvert_s?>(uint64(int64(unsafe(reinterpret<uint64>(unsafe(addr(unsafe(unsafe(addr(finalverts[0]))[0])))))) + 32l - 1l & int64(~(32 - 1)))))))
    pauxverts = unsafe(addr<auxvert_t?>(unsafe(unsafe(addr(auxverts[0]))[0])))
    paliashdr = unsafe(reinterpret<aliashdr_t?>(unsafe(reinterpret<aliashdr_t?>(unsafe(reinterpret<aliashdr_t?>(Mod_Extradata(currententity.model)))))))
    pmdl = unsafe(reinterpret<mdl_t?>(unsafe(reinterpret<mdl_t?>(unsafe(unsafe(reinterpret<uint8?>(paliashdr)) + paliashdr.model)))))
    R_AliasSetupSkin()
    R_AliasSetUpTransform(currententity.trivial_accept)
    R_AliasSetupLighting(plighting)
    R_AliasSetupFrame()
    if (currententity.colormap == null) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_r_alias_0[0])), [])
    }
    r_affinetridesc.drawtype = currententity.trivial_accept == 3 && uint(r_recursiveaffinetriangles) != 0x0 ? 1 : 0
    if (r_affinetridesc.drawtype != 0) {
        D_PolysetUpdateTables()
    }
    acolormap = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(currententity.colormap))))
    if (currententity != unsafe(addr(cl.viewent))) {
        ziscale = 32768.0 * 65536.0
    } else {
        ziscale = float(double(32768.0 * 65536.0) * 3.0lf)
    }
    if (currententity.trivial_accept != 0) {
        R_AliasPrepareUnclippedPoints()
    } else {
        R_AliasPreparePoints()
    }
    return
}
[export, sideeffects]
def R_AliasPreparePoints() {
    var i : int
    var pstverts : stvert_t?
    var fv_1 : finalvert_s?
    var av_0 : auxvert_t?
    var ptri : mtriangle_s?
    var pfv : finalvert_s? [3]
    pstverts = unsafe(reinterpret<stvert_t?>(unsafe(reinterpret<stvert_t?>(unsafe(unsafe(reinterpret<uint8?>(paliashdr)) + paliashdr.stverts)))))
    r_anumverts = int(pmdl.numverts)  // nolint:PERF020
    fv_1 = unsafe(reinterpret<finalvert_s?>(pfinalverts))
    av_0 = unsafe(reinterpret<auxvert_t?>(pauxverts))
    i = 0
    while (i < r_anumverts) {
        R_AliasTransformFinalVert(fv_1, av_0, r_apverts, pstverts)
        var c2da_fresh0 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(av_0))))
        if (unsafe(unsafe(reinterpret<float?>(c2da_fresh0))[2]) < 5.0) {
            fv_1.flags |= 16
        } else {
            R_AliasProjectFinalVert(fv_1, av_0)
            var c2da_fresh1 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(fv_1))))
            if (unsafe(unsafe(reinterpret<int?>(c2da_fresh1))[0]) < r_refdef.aliasvrect.x) {
                fv_1.flags |= 1
            }
            var c2da_fresh2 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(fv_1))))
            if (unsafe(unsafe(reinterpret<int?>(c2da_fresh2))[1]) < r_refdef.aliasvrect.y) {
                fv_1.flags |= 2
            }
            var c2da_fresh3 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(fv_1))))
            if (unsafe(unsafe(reinterpret<int?>(c2da_fresh3))[0]) > r_refdef.aliasvrectright) {
                fv_1.flags |= 4
            }
            var c2da_fresh4 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(fv_1))))
            if (unsafe(unsafe(reinterpret<int?>(c2da_fresh4))[1]) > r_refdef.aliasvrectbottom) {
                fv_1.flags |= 8
            }
        }
        i++
        unsafe {  // nolint:STYLE025
            fv_1 += 1
        }
        unsafe {  // nolint:STYLE025
            av_0 += 1
        }
        unsafe {  // nolint:STYLE025
            r_apverts += 1
        }
        unsafe {  // nolint:STYLE025
            pstverts += 1
        }
    }
    r_affinetridesc.numtriangles = 1
    ptri = unsafe(reinterpret<mtriangle_s?>(unsafe(reinterpret<mtriangle_s?>(unsafe(unsafe(reinterpret<uint8?>(paliashdr)) + paliashdr.triangles)))))
    i = 0
    while (i < pmdl.numtris) {
        var c2da_fresh5 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(ptri)) + 4ul))
        pfv[0] = unsafe(addr<finalvert_s?>(unsafe(pfinalverts[unsafe(unsafe(reinterpret<int?>(c2da_fresh5))[0])])))
        var c2da_fresh6 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(ptri)) + 4ul))
        pfv[1] = unsafe(addr<finalvert_s?>(unsafe(pfinalverts[unsafe(unsafe(reinterpret<int?>(c2da_fresh6))[1])])))
        var c2da_fresh7 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(ptri)) + 4ul))
        pfv[2] = unsafe(addr<finalvert_s?>(unsafe(pfinalverts[unsafe(unsafe(reinterpret<int?>(c2da_fresh7))[2])])))
        if ((pfv[0].flags & pfv[1].flags & pfv[2].flags & (15 | 16)) != 0) {
            i++
            unsafe {  // nolint:STYLE025
                ptri += 1
            }
            continue
        }
        if (((pfv[0].flags | pfv[1].flags | pfv[2].flags) & (15 | 16)) == 0) {
            r_affinetridesc.pfinalverts = unsafe(reinterpret<finalvert_s?>(pfinalverts))
            r_affinetridesc.ptriangles = unsafe(reinterpret<mtriangle_s?>(ptri))
            D_PolysetDraw()
        } else {
            R_AliasClipTriangle(ptri)
        }
        i++
        unsafe {  // nolint:STYLE025
            ptri += 1
        }
    }
    return
}
var pfinalverts : finalvert_s? = default<finalvert_s?>

var pmdl : mdl_t? = default<mdl_t?>

var paliashdr : aliashdr_t? = default<aliashdr_t?>

[export, sideeffects]
def R_AliasProjectFinalVert(var fv_2 : finalvert_s?; var av_1 : auxvert_t?) {
    var zi : float
    var c2da_fresh8 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(av_1))))
    zi = float(1.0lf / double(unsafe(unsafe(reinterpret<float?>(c2da_fresh8))[2])))
    var c2da_fresh9 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(fv_2))))
    unsafe(unsafe(reinterpret<int?>(c2da_fresh9))[5]) = int(zi * ziscale)
    var c2da_fresh10 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(fv_2))))
    var c2da_fresh11 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(av_1))))
    unsafe(unsafe(reinterpret<int?>(c2da_fresh10))[0]) = int(unsafe(unsafe(reinterpret<float?>(c2da_fresh11))[0]) * aliasxscale * zi + aliasxcenter)
    var c2da_fresh12 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(fv_2))))
    var c2da_fresh13 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(av_1))))
    unsafe(unsafe(reinterpret<int?>(c2da_fresh12))[1]) = int(unsafe(unsafe(reinterpret<float?>(c2da_fresh13))[1]) * aliasyscale * zi + aliasycenter)
    return
}
var private ziscale : float = default<float>

var r_apverts : trivertx_t? = default<trivertx_t?>

[export, sideeffects]
def R_AliasTransformFinalVert(var fv_3 : finalvert_s?; var av_2 : auxvert_t?; var pverts : trivertx_t?; var pstverts_0 : stvert_t?) {
    var temp : int
    var lightcos : float
    var plightnormal : float?
    var c2da_fresh14 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(av_2))))
    var c2da_fresh15 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pverts))))
    var c2da_fresh16 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pverts))))
    var c2da_fresh17 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pverts))))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh14))[0]) = float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh15))[0]))) * aliastransform[0][0] + float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh16))[1]))) * aliastransform[0][1] + float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh17))[2]))) * aliastransform[0][2] + aliastransform[0][3]
    var c2da_fresh18 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(av_2))))
    var c2da_fresh19 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pverts))))
    var c2da_fresh20 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pverts))))
    var c2da_fresh21 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pverts))))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh18))[1]) = float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh19))[0]))) * aliastransform[1][0] + float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh20))[1]))) * aliastransform[1][1] + float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh21))[2]))) * aliastransform[1][2] + aliastransform[1][3]
    var c2da_fresh22 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(av_2))))
    var c2da_fresh23 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pverts))))
    var c2da_fresh24 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pverts))))
    var c2da_fresh25 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pverts))))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh22))[2]) = float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh23))[0]))) * aliastransform[2][0] + float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh24))[1]))) * aliastransform[2][1] + float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh25))[2]))) * aliastransform[2][2] + aliastransform[2][3]
    var c2da_fresh26 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(fv_3))))
    unsafe(unsafe(reinterpret<int?>(c2da_fresh26))[2]) = int(pstverts_0.s)  // nolint:PERF020
    var c2da_fresh27 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(fv_3))))
    unsafe(unsafe(reinterpret<int?>(c2da_fresh27))[3]) = int(pstverts_0.t)  // nolint:PERF020
    fv_3.flags = int(pstverts_0.onseam)  // nolint:PERF020
    plightnormal = unsafe(addr<float?>(r_avertexnormals[int(pverts.lightnormalindex)][0]))
    lightcos = unsafe(plightnormal[0]) * unsafe(unsafe(addr(r_plightvec[0]))[0]) + unsafe(plightnormal[1]) * unsafe(unsafe(addr(r_plightvec[0]))[1]) + unsafe(plightnormal[2]) * unsafe(unsafe(addr(r_plightvec[0]))[2])
    temp = r_ambientlight
    if (lightcos < 0.0) {
        temp += int(r_shadelight * lightcos)
        if (temp < 0) {
            temp = 0
        }
    }
    var c2da_fresh28 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(fv_3))))
    unsafe(unsafe(reinterpret<int?>(c2da_fresh28))[4]) = temp
    return
}
var r_shadelight : float = default<float>

var r_ambientlight : int = default<int>

var r_plightvec : vec3_t = default<vec3_t>

var r_avertexnormals : float[162][3] = fixed_array<float[3]>(fixed_array<float>(float(-0.525731lf), 0.0, float(0.850651lf)), fixed_array<float>(float(-0.442863lf), float(0.238856lf), float(0.864188lf)), fixed_array<float>(float(-0.295242lf), 0.0, float(0.955423lf)), fixed_array<float>(float(-0.309017lf), 0.5, float(0.809017lf)), fixed_array<float>(float(-0.16246lf), float(0.262866lf), float(0.951056lf)), fixed_array<float>(0.0, 0.0, 1.0), fixed_array<float>(0.0, float(0.850651lf), float(0.525731lf)), fixed_array<float>(float(-0.147621lf), float(0.716567lf), float(0.681718lf)), fixed_array<float>(float(0.147621lf), float(0.716567lf), float(0.681718lf)), fixed_array<float>(0.0, float(0.525731lf), float(0.850651lf)), fixed_array<float>(float(0.309017lf), 0.5, float(0.809017lf)), fixed_array<float>(float(0.525731lf), 0.0, float(0.850651lf)), fixed_array<float>(float(0.295242lf), 0.0, float(0.955423lf)), fixed_array<float>(float(0.442863lf), float(0.238856lf), float(0.864188lf)), fixed_array<float>(float(0.16246lf), float(0.262866lf), float(0.951056lf)), fixed_array<float>(float(-0.681718lf), float(0.147621lf), float(0.716567lf)), fixed_array<float>(float(-0.809017lf), float(0.309017lf), 0.5), fixed_array<float>(float(-0.587785lf), float(0.425325lf), float(0.688191lf)), fixed_array<float>(float(-0.850651lf), float(0.525731lf), 0.0), fixed_array<float>(float(-0.864188lf), float(0.442863lf), float(0.238856lf)), fixed_array<float>(float(-0.716567lf), float(0.681718lf), float(0.147621lf)), fixed_array<float>(float(-0.688191lf), float(0.587785lf), float(0.425325lf)), fixed_array<float>(float(-0.5lf), float(0.809017lf), float(0.309017lf)), fixed_array<float>(float(-0.238856lf), float(0.864188lf), float(0.442863lf)), fixed_array<float>(float(-0.425325lf), float(0.688191lf), float(0.587785lf)), fixed_array<float>(float(-0.716567lf), float(0.681718lf), float(-0.147621lf)), fixed_array<float>(float(-0.5lf), float(0.809017lf), float(-0.309017lf)), fixed_array<float>(float(-0.525731lf), float(0.850651lf), 0.0), fixed_array<float>(0.0, float(0.850651lf), float(-0.525731lf)), fixed_array<float>(float(-0.238856lf), float(0.864188lf), float(-0.442863lf)), fixed_array<float>(0.0, float(0.955423lf), float(-0.295242lf)), fixed_array<float>(float(-0.262866lf), float(0.951056lf), float(-0.16246lf)), fixed_array<float>(0.0, 1.0, 0.0), fixed_array<float>(0.0, float(0.955423lf), float(0.295242lf)), fixed_array<float>(float(-0.262866lf), float(0.951056lf), float(0.16246lf)), fixed_array<float>(float(0.238856lf), float(0.864188lf), float(0.442863lf)), fixed_array<float>(float(0.262866lf), float(0.951056lf), float(0.16246lf)), fixed_array<float>(0.5, float(0.809017lf), float(0.309017lf)), fixed_array<float>(float(0.238856lf), float(0.864188lf), float(-0.442863lf)), fixed_array<float>(float(0.262866lf), float(0.951056lf), float(-0.16246lf)), fixed_array<float>(0.5, float(0.809017lf), float(-0.309017lf)), fixed_array<float>(float(0.850651lf), float(0.525731lf), 0.0), fixed_array<float>(float(0.716567lf), float(0.681718lf), float(0.147621lf)), fixed_array<float>(float(0.716567lf), float(0.681718lf), float(-0.147621lf)), fixed_array<float>(float(0.525731lf), float(0.850651lf), 0.0), fixed_array<float>(float(0.425325lf), float(0.688191lf), float(0.587785lf)), fixed_array<float>(float(0.864188lf), float(0.442863lf), float(0.238856lf)), fixed_array<float>(float(0.688191lf), float(0.587785lf), float(0.425325lf)), fixed_array<float>(float(0.809017lf), float(0.309017lf), 0.5), fixed_array<float>(float(0.681718lf), float(0.147621lf), float(0.716567lf)), fixed_array<float>(float(0.587785lf), float(0.425325lf), float(0.688191lf)), fixed_array<float>(float(0.955423lf), float(0.295242lf), 0.0), fixed_array<float>(1.0, 0.0, 0.0), fixed_array<float>(float(0.951056lf), float(0.16246lf), float(0.262866lf)), fixed_array<float>(float(0.850651lf), float(-0.525731lf), 0.0), fixed_array<float>(float(0.955423lf), float(-0.295242lf), 0.0), fixed_array<float>(float(0.864188lf), float(-0.442863lf), float(0.238856lf)), fixed_array<float>(float(0.951056lf), float(-0.16246lf), float(0.262866lf)), fixed_array<float>(float(0.809017lf), float(-0.309017lf), 0.5), fixed_array<float>(float(0.681718lf), float(-0.147621lf), float(0.716567lf)), fixed_array<float>(float(0.850651lf), 0.0, float(0.525731lf)), fixed_array<float>(float(0.864188lf), float(0.442863lf), float(-0.238856lf)), fixed_array<float>(float(0.809017lf), float(0.309017lf), float(-0.5lf)), fixed_array<float>(float(0.951056lf), float(0.16246lf), float(-0.262866lf)), fixed_array<float>(float(0.525731lf), 0.0, float(-0.850651lf)), fixed_array<float>(float(0.681718lf), float(0.147621lf), float(-0.716567lf)), fixed_array<float>(float(0.681718lf), float(-0.147621lf), float(-0.716567lf)), fixed_array<float>(float(0.850651lf), 0.0, float(-0.525731lf)), fixed_array<float>(float(0.809017lf), float(-0.309017lf), float(-0.5lf)), fixed_array<float>(float(0.864188lf), float(-0.442863lf), float(-0.238856lf)), fixed_array<float>(float(0.951056lf), float(-0.16246lf), float(-0.262866lf)), fixed_array<float>(float(0.147621lf), float(0.716567lf), float(-0.681718lf)), fixed_array<float>(float(0.309017lf), 0.5, float(-0.809017lf)), fixed_array<float>(float(0.425325lf), float(0.688191lf), float(-0.587785lf)), fixed_array<float>(float(0.442863lf), float(0.238856lf), float(-0.864188lf)), fixed_array<float>(float(0.587785lf), float(0.425325lf), float(-0.688191lf)), fixed_array<float>(float(0.688191lf), float(0.587785lf), float(-0.425325lf)), fixed_array<float>(float(-0.147621lf), float(0.716567lf), float(-0.681718lf)), fixed_array<float>(float(-0.309017lf), 0.5, float(-0.809017lf)), fixed_array<float>(0.0, float(0.525731lf), float(-0.850651lf)), fixed_array<float>(float(-0.525731lf), 0.0, float(-0.850651lf)), fixed_array<float>(float(-0.442863lf), float(0.238856lf), float(-0.864188lf)), fixed_array<float>(float(-0.295242lf), 0.0, float(-0.955423lf)), fixed_array<float>(float(-0.16246lf), float(0.262866lf), float(-0.951056lf)), fixed_array<float>(0.0, 0.0, float(-1.0lf)), fixed_array<float>(float(0.295242lf), 0.0, float(-0.955423lf)), fixed_array<float>(float(0.16246lf), float(0.262866lf), float(-0.951056lf)), fixed_array<float>(float(-0.442863lf), float(-0.238856lf), float(-0.864188lf)), fixed_array<float>(float(-0.309017lf), float(-0.5lf), float(-0.809017lf)), fixed_array<float>(float(-0.16246lf), float(-0.262866lf), float(-0.951056lf)), fixed_array<float>(0.0, float(-0.850651lf), float(-0.525731lf)), fixed_array<float>(float(-0.147621lf), float(-0.716567lf), float(-0.681718lf)), fixed_array<float>(float(0.147621lf), float(-0.716567lf), float(-0.681718lf)), fixed_array<float>(0.0, float(-0.525731lf), float(-0.850651lf)), fixed_array<float>(float(0.309017lf), float(-0.5lf), float(-0.809017lf)), fixed_array<float>(float(0.442863lf), float(-0.238856lf), float(-0.864188lf)), fixed_array<float>(float(0.16246lf), float(-0.262866lf), float(-0.951056lf)), fixed_array<float>(float(0.238856lf), float(-0.864188lf), float(-0.442863lf)), fixed_array<float>(0.5, float(-0.809017lf), float(-0.309017lf)), fixed_array<float>(float(0.425325lf), float(-0.688191lf), float(-0.587785lf)), fixed_array<float>(float(0.716567lf), float(-0.681718lf), float(-0.147621lf)), fixed_array<float>(float(0.688191lf), float(-0.587785lf), float(-0.425325lf)), fixed_array<float>(float(0.587785lf), float(-0.425325lf), float(-0.688191lf)), fixed_array<float>(0.0, float(-0.955423lf), float(-0.295242lf)), fixed_array<float>(0.0, float(-1.0lf), 0.0), fixed_array<float>(float(0.262866lf), float(-0.951056lf), float(-0.16246lf)), fixed_array<float>(0.0, float(-0.850651lf), float(0.525731lf)), fixed_array<float>(0.0, float(-0.955423lf), float(0.295242lf)), fixed_array<float>(float(0.238856lf), float(-0.864188lf), float(0.442863lf)), fixed_array<float>(float(0.262866lf), float(-0.951056lf), float(0.16246lf)), fixed_array<float>(0.5, float(-0.809017lf), float(0.309017lf)), fixed_array<float>(float(0.716567lf), float(-0.681718lf), float(0.147621lf)), fixed_array<float>(float(0.525731lf), float(-0.850651lf), 0.0), fixed_array<float>(float(-0.238856lf), float(-0.864188lf), float(-0.442863lf)), fixed_array<float>(float(-0.5lf), float(-0.809017lf), float(-0.309017lf)), fixed_array<float>(float(-0.262866lf), float(-0.951056lf), float(-0.16246lf)), fixed_array<float>(float(-0.850651lf), float(-0.525731lf), 0.0), fixed_array<float>(float(-0.716567lf), float(-0.681718lf), float(-0.147621lf)), fixed_array<float>(float(-0.716567lf), float(-0.681718lf), float(0.147621lf)), fixed_array<float>(float(-0.525731lf), float(-0.850651lf), 0.0), fixed_array<float>(float(-0.5lf), float(-0.809017lf), float(0.309017lf)), fixed_array<float>(float(-0.238856lf), float(-0.864188lf), float(0.442863lf)), fixed_array<float>(float(-0.262866lf), float(-0.951056lf), float(0.16246lf)), fixed_array<float>(float(-0.864188lf), float(-0.442863lf), float(0.238856lf)), fixed_array<float>(float(-0.809017lf), float(-0.309017lf), 0.5), fixed_array<float>(float(-0.688191lf), float(-0.587785lf), float(0.425325lf)), fixed_array<float>(float(-0.681718lf), float(-0.147621lf), float(0.716567lf)), fixed_array<float>(float(-0.442863lf), float(-0.238856lf), float(0.864188lf)), fixed_array<float>(float(-0.587785lf), float(-0.425325lf), float(0.688191lf)), fixed_array<float>(float(-0.309017lf), float(-0.5lf), float(0.809017lf)), fixed_array<float>(float(-0.147621lf), float(-0.716567lf), float(0.681718lf)), fixed_array<float>(float(-0.425325lf), float(-0.688191lf), float(0.587785lf)), fixed_array<float>(float(-0.16246lf), float(-0.262866lf), float(0.951056lf)), fixed_array<float>(float(0.442863lf), float(-0.238856lf), float(0.864188lf)), fixed_array<float>(float(0.16246lf), float(-0.262866lf), float(0.951056lf)), fixed_array<float>(float(0.309017lf), float(-0.5lf), float(0.809017lf)), fixed_array<float>(float(0.147621lf), float(-0.716567lf), float(0.681718lf)), fixed_array<float>(0.0, float(-0.525731lf), float(0.850651lf)), fixed_array<float>(float(0.425325lf), float(-0.688191lf), float(0.587785lf)), fixed_array<float>(float(0.587785lf), float(-0.425325lf), float(0.688191lf)), fixed_array<float>(float(0.688191lf), float(-0.587785lf), float(0.425325lf)), fixed_array<float>(float(-0.955423lf), float(0.295242lf), 0.0), fixed_array<float>(float(-0.951056lf), float(0.16246lf), float(0.262866lf)), fixed_array<float>(float(-1.0lf), 0.0, 0.0), fixed_array<float>(float(-0.850651lf), 0.0, float(0.525731lf)), fixed_array<float>(float(-0.955423lf), float(-0.295242lf), 0.0), fixed_array<float>(float(-0.951056lf), float(-0.16246lf), float(0.262866lf)), fixed_array<float>(float(-0.864188lf), float(0.442863lf), float(-0.238856lf)), fixed_array<float>(float(-0.951056lf), float(0.16246lf), float(-0.262866lf)), fixed_array<float>(float(-0.809017lf), float(0.309017lf), float(-0.5lf)), fixed_array<float>(float(-0.864188lf), float(-0.442863lf), float(-0.238856lf)), fixed_array<float>(float(-0.951056lf), float(-0.16246lf), float(-0.262866lf)), fixed_array<float>(float(-0.809017lf), float(-0.309017lf), float(-0.5lf)), fixed_array<float>(float(-0.681718lf), float(0.147621lf), float(-0.716567lf)), fixed_array<float>(float(-0.681718lf), float(-0.147621lf), float(-0.716567lf)), fixed_array<float>(float(-0.850651lf), 0.0, float(-0.525731lf)), fixed_array<float>(float(-0.688191lf), float(0.587785lf), float(-0.425325lf)), fixed_array<float>(float(-0.587785lf), float(0.425325lf), float(-0.688191lf)), fixed_array<float>(float(-0.425325lf), float(0.688191lf), float(-0.587785lf)), fixed_array<float>(float(-0.425325lf), float(-0.688191lf), float(-0.587785lf)), fixed_array<float>(float(-0.587785lf), float(-0.425325lf), float(-0.688191lf)), fixed_array<float>(float(-0.688191lf), float(-0.587785lf), float(-0.425325lf)))

var aliastransform : float[3][4]

var r_anumverts : int = default<int>

var pauxverts : auxvert_t? = default<auxvert_t?>

[export, sideeffects]
def R_AliasPrepareUnclippedPoints() {
    var pstverts_1 : stvert_t?
    var fv_4 : finalvert_s?
    pstverts_1 = unsafe(reinterpret<stvert_t?>(unsafe(reinterpret<stvert_t?>(unsafe(unsafe(reinterpret<uint8?>(paliashdr)) + paliashdr.stverts)))))
    r_anumverts = int(pmdl.numverts)  // nolint:PERF020
    fv_4 = unsafe(reinterpret<finalvert_s?>(pfinalverts))
    R_AliasTransformAndProjectFinalVerts(fv_4, pstverts_1)
    if (r_affinetridesc.drawtype != 0) {
        D_PolysetDrawFinalVerts(fv_4, r_anumverts)
    }
    r_affinetridesc.pfinalverts = unsafe(reinterpret<finalvert_s?>(pfinalverts))
    r_affinetridesc.ptriangles = unsafe(reinterpret<mtriangle_s?>(unsafe(reinterpret<mtriangle_s?>(unsafe(unsafe(reinterpret<uint8?>(paliashdr)) + paliashdr.triangles)))))
    r_affinetridesc.numtriangles = int(pmdl.numtris)  // nolint:PERF020
    D_PolysetDraw()
    return
}
[export, sideeffects]
def R_AliasTransformAndProjectFinalVerts(var fv_5 : finalvert_s?; var pstverts_2 : stvert_t?) {
    var i_0 : int
    var temp_0 : int
    var lightcos_0 : float
    var plightnormal_0 : float?
    var zi_0 : float
    var pverts_0 : trivertx_t? = unsafe(reinterpret<trivertx_t?>(r_apverts))
    var c2da_fv_5_addr : uint64 = unsafe(reinterpret<uint64>(fv_5))
    var c2da_pverts_0_addr : uint64 = unsafe(reinterpret<uint64>(pverts_0))
    var c2da_pstverts_2_addr : uint64 = unsafe(reinterpret<uint64>(pstverts_2))
    i_0 = 0
    while (i_0 < r_anumverts) {
        var c2da_fresh29 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<trivertx_t?>(c2da_pverts_0_addr))))))
        var c2da_fresh30 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<trivertx_t?>(c2da_pverts_0_addr))))))
        var c2da_fresh31 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<trivertx_t?>(c2da_pverts_0_addr))))))
        zi_0 = float(1.0lf / double(float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh29))[0]))) * aliastransform[2][0] + float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh30))[1]))) * aliastransform[2][1] + float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh31))[2]))) * aliastransform[2][2] + aliastransform[2][3]))
        var c2da_fresh32 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_5_addr))))))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh32))[5]) = int(zi_0)
        var c2da_fresh33 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_5_addr))))))
        var c2da_fresh34 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<trivertx_t?>(c2da_pverts_0_addr))))))
        var c2da_fresh35 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<trivertx_t?>(c2da_pverts_0_addr))))))
        var c2da_fresh36 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<trivertx_t?>(c2da_pverts_0_addr))))))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh33))[0]) = int((float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh34))[0]))) * aliastransform[0][0] + float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh35))[1]))) * aliastransform[0][1] + float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh36))[2]))) * aliastransform[0][2] + aliastransform[0][3]) * zi_0 + aliasxcenter)
        var c2da_fresh37 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_5_addr))))))
        var c2da_fresh38 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<trivertx_t?>(c2da_pverts_0_addr))))))
        var c2da_fresh39 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<trivertx_t?>(c2da_pverts_0_addr))))))
        var c2da_fresh40 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<trivertx_t?>(c2da_pverts_0_addr))))))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh37))[1]) = int((float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh38))[0]))) * aliastransform[1][0] + float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh39))[1]))) * aliastransform[1][1] + float(int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh40))[2]))) * aliastransform[1][2] + aliastransform[1][3]) * zi_0 + aliasycenter)
        var c2da_fresh41 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_5_addr))))))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh41))[2]) = int(unsafe(reinterpret<stvert_t?>(c2da_pstverts_2_addr)).s)  // nolint:PERF020
        var c2da_fresh42 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_5_addr))))))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh42))[3]) = int(unsafe(reinterpret<stvert_t?>(c2da_pstverts_2_addr)).t)  // nolint:PERF020
        unsafe(reinterpret<finalvert_s?>(c2da_fv_5_addr)).flags = int(unsafe(reinterpret<stvert_t?>(c2da_pstverts_2_addr)).onseam)  // nolint:PERF020
        plightnormal_0 = unsafe(addr<float?>(r_avertexnormals[int(unsafe(reinterpret<trivertx_t?>(c2da_pverts_0_addr)).lightnormalindex)][0]))
        lightcos_0 = unsafe(plightnormal_0[0]) * unsafe(unsafe(addr(r_plightvec[0]))[0]) + unsafe(plightnormal_0[1]) * unsafe(unsafe(addr(r_plightvec[0]))[1]) + unsafe(plightnormal_0[2]) * unsafe(unsafe(addr(r_plightvec[0]))[2])
        temp_0 = r_ambientlight
        if (lightcos_0 < 0.0) {
            temp_0 += int(r_shadelight * lightcos_0)
            if (temp_0 < 0) {
                temp_0 = 0
            }
        }
        var c2da_fresh43 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<finalvert_s?>(c2da_fv_5_addr))))))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh43))[4]) = temp_0
        i_0++
        c2da_fv_5_addr += 32ul
        c2da_pverts_0_addr += 4ul
        c2da_pstverts_2_addr += 12ul
    }
    return
}
[export, sideeffects]
def R_AliasSetupFrame() {
    var frame : int
    var i_1 : int
    var numframes : int
    var paliasgroup : maliasgroup_t?
    var pintervals : float?
    var fullinterval : float
    var targettime : float
    var time : float
    frame = currententity.frame
    if (frame >= pmdl.numframes || frame < 0) {
        Con_DPrintf(unsafe(addr<int8?>(c2da_str_r_alias_1[0])), [C2daVaArg(tag = 1, i64 = int64(frame), f64 = 0.0lf, raw = 0x0)])
        frame = 0
    }
    var c2da_fresh44 : maliasframedesc_t? = unsafe(reinterpret<maliasframedesc_t?>(unsafe(reinterpret<uint64>(paliashdr)) + 16ul))
    if (uint(unsafe(unsafe(reinterpret<maliasframedesc_t?>(c2da_fresh44))[frame]).type_0) == 0u) {
        var c2da_fresh45 : maliasframedesc_t? = unsafe(reinterpret<maliasframedesc_t?>(unsafe(reinterpret<uint64>(paliashdr)) + 16ul))
        r_apverts = unsafe(reinterpret<trivertx_t?>(unsafe(reinterpret<trivertx_t?>(unsafe(unsafe(reinterpret<uint8?>(paliashdr)) + unsafe(unsafe(reinterpret<maliasframedesc_t?>(c2da_fresh45))[frame]).frame)))))
        return
    }
    var c2da_fresh46 : maliasframedesc_t? = unsafe(reinterpret<maliasframedesc_t?>(unsafe(reinterpret<uint64>(paliashdr)) + 16ul))
    paliasgroup = unsafe(reinterpret<maliasgroup_t?>(unsafe(reinterpret<maliasgroup_t?>(unsafe(unsafe(reinterpret<uint8?>(paliashdr)) + unsafe(unsafe(reinterpret<maliasframedesc_t?>(c2da_fresh46))[frame]).frame)))))
    pintervals = unsafe(reinterpret<float?>(unsafe(reinterpret<float?>(unsafe(unsafe(reinterpret<uint8?>(paliashdr)) + paliasgroup.intervals)))))
    numframes = paliasgroup.numframes
    fullinterval = unsafe(pintervals[numframes - 1])
    time = float(cl.time + double(currententity.syncbase))
    targettime = time - float(int(time / fullinterval)) * fullinterval
    i_1 = 0
    while (i_1 < numframes - 1) {
        if (unsafe(pintervals[i_1]) > targettime) {
            break
        }
        i_1++
    }
    var c2da_fresh47 : maliasgroupframedesc_t? = unsafe(reinterpret<maliasgroupframedesc_t?>(unsafe(reinterpret<uint64>(paliasgroup)) + 8ul))
    r_apverts = unsafe(reinterpret<trivertx_t?>(unsafe(reinterpret<trivertx_t?>(unsafe(unsafe(reinterpret<uint8?>(paliashdr)) + unsafe(unsafe(reinterpret<maliasgroupframedesc_t?>(c2da_fresh47))[i_1]).frame)))))
    return
}
[export, sideeffects]
def R_AliasSetupLighting(var plighting_0 : alight_t?) {
    r_ambientlight = int(plighting_0.ambientlight)  // nolint:PERF020
    if (r_ambientlight < 5) {
        r_ambientlight = 5
    }
    r_ambientlight = 255 - r_ambientlight << 6
    if (r_ambientlight < 5) {
        r_ambientlight = 5
    }
    r_shadelight = float(plighting_0.shadelight)
    if (r_shadelight < 0.0) {
        r_shadelight = 0.0
    }
    r_shadelight *= float(1 << 6)
    unsafe(unsafe(addr(r_plightvec[0]))[0]) = unsafe(plighting_0.plightvec[0]) * unsafe(unsafe(addr(alias_forward[0]))[0]) + unsafe(plighting_0.plightvec[1]) * unsafe(unsafe(addr(alias_forward[0]))[1]) + unsafe(plighting_0.plightvec[2]) * unsafe(unsafe(addr(alias_forward[0]))[2])
    unsafe(unsafe(addr(r_plightvec[0]))[1]) = -(unsafe(plighting_0.plightvec[0]) * unsafe(unsafe(addr(alias_right[0]))[0]) + unsafe(plighting_0.plightvec[1]) * unsafe(unsafe(addr(alias_right[0]))[1]) + unsafe(plighting_0.plightvec[2]) * unsafe(unsafe(addr(alias_right[0]))[2]))
    unsafe(unsafe(addr(r_plightvec[0]))[2]) = unsafe(plighting_0.plightvec[0]) * unsafe(unsafe(addr(alias_up[0]))[0]) + unsafe(plighting_0.plightvec[1]) * unsafe(unsafe(addr(alias_up[0]))[1]) + unsafe(plighting_0.plightvec[2]) * unsafe(unsafe(addr(alias_up[0]))[2])
    return
}
var private alias_up : vec3_t = default<vec3_t>

var private alias_right : vec3_t = default<vec3_t>

var private alias_forward : vec3_t = default<vec3_t>

[export, sideeffects]
def R_AliasSetUpTransform(var trivial_accept : int) {
    var i_2 : int
    var rotationmatrix : float[3][4]
    var t2matrix : float[3][4]
    var angles_0 : vec3_t
    var c2da_fresh48 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(currententity)) + 124ul))
    unsafe(unsafe(addr(angles_0[0]))[2]) = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh48))[2]))  // nolint:PERF020
    var c2da_fresh49 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(currententity)) + 124ul))
    unsafe(unsafe(addr(angles_0[0]))[0]) = -unsafe(unsafe(reinterpret<float?>(c2da_fresh49))[0])
    var c2da_fresh50 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(currententity)) + 124ul))
    unsafe(unsafe(addr(angles_0[0]))[1]) = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh50))[1]))  // nolint:PERF020
    AngleVectors(unsafe(addr<float?>(angles_0[0])), unsafe(addr<float?>(alias_forward[0])), unsafe(addr<float?>(alias_right[0])), unsafe(addr<float?>(alias_up[0])))
    var c2da_fresh51 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pmdl)) + 8ul))
    R_AliasSetUpTransform__tmatrix[0][0] = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh51))[0]))  // nolint:PERF020
    var c2da_fresh52 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pmdl)) + 8ul))
    R_AliasSetUpTransform__tmatrix[1][1] = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh52))[1]))  // nolint:PERF020
    var c2da_fresh53 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pmdl)) + 8ul))
    R_AliasSetUpTransform__tmatrix[2][2] = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh53))[2]))  // nolint:PERF020
    var c2da_fresh54 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pmdl)) + 20ul))
    R_AliasSetUpTransform__tmatrix[0][3] = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh54))[0]))  // nolint:PERF020
    var c2da_fresh55 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pmdl)) + 20ul))
    R_AliasSetUpTransform__tmatrix[1][3] = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh55))[1]))  // nolint:PERF020
    var c2da_fresh56 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pmdl)) + 20ul))
    R_AliasSetUpTransform__tmatrix[2][3] = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh56))[2]))  // nolint:PERF020
    i_2 = 0
    while (i_2 < 3) {
        t2matrix[i_2][0] = float(unsafe(unsafe(addr(alias_forward[0]))[i_2]))  // nolint:PERF020
        t2matrix[i_2][1] = -unsafe(unsafe(addr(alias_right[0]))[i_2])
        t2matrix[i_2][2] = float(unsafe(unsafe(addr(alias_up[0]))[i_2]))  // nolint:PERF020
        i_2++
    }
    t2matrix[0][3] = -unsafe(unsafe(addr(modelorg[0]))[0])
    t2matrix[1][3] = -unsafe(unsafe(addr(modelorg[0]))[1])
    t2matrix[2][3] = -unsafe(unsafe(addr(modelorg[0]))[2])
    R_ConcatTransforms(unsafe(addr<float[4]?>(t2matrix[0])), unsafe(addr<float[4]?>(R_AliasSetUpTransform__tmatrix[0])), unsafe(addr<float[4]?>(rotationmatrix[0])))
    R_AliasSetUpTransform__viewmatrix[0][0] = unsafe(unsafe(addr(vright[0]))[0])
    R_AliasSetUpTransform__viewmatrix[0][1] = unsafe(unsafe(addr(vright[0]))[1])
    R_AliasSetUpTransform__viewmatrix[0][2] = unsafe(unsafe(addr(vright[0]))[2])
    R_AliasSetUpTransform__viewmatrix[1][0] = unsafe(unsafe(addr(vup[0]))[0])
    R_AliasSetUpTransform__viewmatrix[1][1] = unsafe(unsafe(addr(vup[0]))[1])
    R_AliasSetUpTransform__viewmatrix[1][2] = unsafe(unsafe(addr(vup[0]))[2])
    VectorInverse(unsafe(addr<float?>(R_AliasSetUpTransform__viewmatrix[1][0])))
    R_AliasSetUpTransform__viewmatrix[2][0] = unsafe(unsafe(addr(vpn[0]))[0])
    R_AliasSetUpTransform__viewmatrix[2][1] = unsafe(unsafe(addr(vpn[0]))[1])
    R_AliasSetUpTransform__viewmatrix[2][2] = unsafe(unsafe(addr(vpn[0]))[2])
    R_ConcatTransforms(unsafe(addr<float[4]?>(R_AliasSetUpTransform__viewmatrix[0])), unsafe(addr<float[4]?>(rotationmatrix[0])), unsafe(addr<float[4]?>(aliastransform[0])))
    if (trivial_accept != 0) {
        i_2 = 0
        for (c2da_i_2 in range(i_2, 4)) {
            aliastransform[0][c2da_i_2] = float(double(aliastransform[0][c2da_i_2]) * (double(aliasxscale) * (1.0lf / double(32768.0 * 65536.0))))
            aliastransform[1][c2da_i_2] = float(double(aliastransform[1][c2da_i_2]) * (double(aliasyscale) * (1.0lf / double(32768.0 * 65536.0))))
            aliastransform[2][c2da_i_2] = float(double(aliastransform[2][c2da_i_2]) * (1.0lf / double(32768.0 * 65536.0)))
        }
    }
    return
}
[export, sideeffects]
def R_AliasSetupSkin() {
    var skinnum : int
    var i_3 : int
    var numskins : int
    var paliasskingroup : maliasskingroup_t?
    var pskinintervals : float?
    var fullskininterval : float
    var skintargettime : float
    var skintime : float
    skinnum = currententity.skinnum
    if (skinnum >= pmdl.numskins || skinnum < 0) {
        Con_DPrintf(unsafe(addr<int8?>(c2da_str_r_alias_2[0])), [C2daVaArg(tag = 1, i64 = int64(skinnum), f64 = 0.0lf, raw = 0x0)])
        skinnum = 0
    }
    pskindesc = unsafe(reinterpret<maliasskindesc_t?>(unsafe(unsafe(reinterpret<maliasskindesc_t?>(unsafe(unsafe(reinterpret<uint8?>(paliashdr)) + paliashdr.skindesc))) + skinnum)))
    a_skinwidth = int(pmdl.skinwidth)  // nolint:PERF020
    if (uint(pskindesc.type_0) == 1u) {
        paliasskingroup = unsafe(reinterpret<maliasskingroup_t?>(unsafe(reinterpret<maliasskingroup_t?>(unsafe(unsafe(reinterpret<uint8?>(paliashdr)) + pskindesc.skin)))))
        pskinintervals = unsafe(reinterpret<float?>(unsafe(reinterpret<float?>(unsafe(unsafe(reinterpret<uint8?>(paliashdr)) + paliasskingroup.intervals)))))
        numskins = paliasskingroup.numskins
        fullskininterval = unsafe(pskinintervals[numskins - 1])
        skintime = float(cl.time + double(currententity.syncbase))
        skintargettime = skintime - float(int(skintime / fullskininterval)) * fullskininterval
        i_3 = 0
        while (i_3 < numskins - 1) {
            if (unsafe(pskinintervals[i_3]) > skintargettime) {
                break
            }
            i_3++
        }
        var c2da_fresh57 : maliasskindesc_t? = unsafe(reinterpret<maliasskindesc_t?>(unsafe(reinterpret<uint64>(paliasskingroup)) + 8ul))
        pskindesc = unsafe(addr<maliasskindesc_t?>(unsafe(unsafe(reinterpret<maliasskindesc_t?>(c2da_fresh57))[i_3])))
    }
    r_affinetridesc.pskindesc = unsafe(reinterpret<maliasskindesc_t?>(pskindesc))
    r_affinetridesc.pskin = unsafe(reinterpret<uint8?>(unsafe(unsafe(reinterpret<uint8?>(paliashdr)) + pskindesc.skin)))
    r_affinetridesc.skinwidth = int(a_skinwidth)  // nolint:PERF020
    r_affinetridesc.seamfixupX16 = a_skinwidth >> 1 << 16
    r_affinetridesc.skinheight = int(pmdl.skinheight)  // nolint:PERF020
    return
}
var a_skinwidth : int = default<int>

var private pskindesc : maliasskindesc_t? = default<maliasskindesc_t?>

var r_amodels_drawn : int = default<int>

var ptriangles : mtriangle_s? = default<mtriangle_s?>

[export, sideeffects]
def R_AliasCheckBBox() : qboolean {
    var i_4 : int
    var flags : int
    var frame_0 : int
    var numv : int
    var pahdr : aliashdr_t?
    var zi_1 : float
    var basepts : float[8][3]
    var v0 : float
    var v1 : float
    var frac : float
    var pv0 : finalvert_s?
    var pv1 : finalvert_s?
    var viewpts : finalvert_s[16]
    var pa0 : auxvert_t?
    var pa1 : auxvert_t?
    var viewaux : auxvert_t[16]
    var pframedesc : maliasframedesc_t?
    var zclipped : qboolean = qboolean()
    var zfullyclipped : qboolean = qboolean()
    var anyclip : uint
    var allclip : uint
    var minz : int
    currententity.trivial_accept = 0
    pmodel = unsafe(reinterpret<model_s?>(currententity.model))
    pahdr = unsafe(reinterpret<aliashdr_t?>(unsafe(reinterpret<aliashdr_t?>(Mod_Extradata(pmodel)))))
    pmdl = unsafe(reinterpret<mdl_t?>(unsafe(reinterpret<mdl_t?>(unsafe(unsafe(reinterpret<uint8?>(pahdr)) + pahdr.model)))))
    R_AliasSetUpTransform(0)
    frame_0 = currententity.frame
    if (frame_0 >= pmdl.numframes || frame_0 < 0) {
        var c2da_fresh58 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(pmodel))))
        Con_DPrintf(unsafe(addr<int8?>(c2da_str_r_alias_3[0])), [C2daVaArg(tag = 1, i64 = int64(frame_0), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(c2da_fresh58)))])
        frame_0 = 0
    }
    var c2da_fresh59 : maliasframedesc_t? = unsafe(reinterpret<maliasframedesc_t?>(unsafe(reinterpret<uint64>(pahdr)) + 16ul))
    pframedesc = unsafe(addr<maliasframedesc_t?>(unsafe(unsafe(reinterpret<maliasframedesc_t?>(c2da_fresh59))[frame_0])))
    var c2da_fresh60 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pframedesc)) + 4ul))
    basepts[3][0] = float(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh60))[0]))
    basepts[2][0] = float(basepts[3][0])  // nolint:PERF020
    basepts[1][0] = float(basepts[2][0])  // nolint:PERF020
    basepts[0][0] = float(basepts[1][0])  // nolint:PERF020
    var c2da_fresh61 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pframedesc)) + 8ul))
    basepts[7][0] = float(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh61))[0]))
    basepts[6][0] = float(basepts[7][0])  // nolint:PERF020
    basepts[5][0] = float(basepts[6][0])  // nolint:PERF020
    basepts[4][0] = float(basepts[5][0])  // nolint:PERF020
    var c2da_fresh62 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pframedesc)) + 4ul))
    basepts[6][1] = float(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh62))[1]))
    basepts[5][1] = float(basepts[6][1])  // nolint:PERF020
    basepts[3][1] = float(basepts[5][1])  // nolint:PERF020
    basepts[0][1] = float(basepts[3][1])  // nolint:PERF020
    var c2da_fresh63 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pframedesc)) + 8ul))
    basepts[7][1] = float(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh63))[1]))
    basepts[4][1] = float(basepts[7][1])  // nolint:PERF020
    basepts[2][1] = float(basepts[4][1])  // nolint:PERF020
    basepts[1][1] = float(basepts[2][1])  // nolint:PERF020
    var c2da_fresh64 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pframedesc)) + 4ul))
    basepts[5][2] = float(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh64))[2]))
    basepts[4][2] = float(basepts[5][2])  // nolint:PERF020
    basepts[1][2] = float(basepts[4][2])  // nolint:PERF020
    basepts[0][2] = float(basepts[1][2])  // nolint:PERF020
    var c2da_fresh65 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pframedesc)) + 8ul))
    basepts[7][2] = float(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh65))[2]))
    basepts[6][2] = float(basepts[7][2])  // nolint:PERF020
    basepts[3][2] = float(basepts[6][2])  // nolint:PERF020
    basepts[2][2] = float(basepts[3][2])  // nolint:PERF020
    zclipped = unsafe(reinterpret<qboolean>(0u))
    zfullyclipped = unsafe(reinterpret<qboolean>(1u))
    minz = 9999
    i_4 = 0
    while (i_4 < 8) {
        R_AliasTransformVector(unsafe(addr<float?>(unsafe(unsafe(addr(basepts[i_4][0]))[0]))), unsafe(addr<float?>(unsafe(unsafe(addr(viewaux[i_4].fv[0]))[0]))))
        if (unsafe(unsafe(addr(viewaux[i_4].fv[0]))[2]) < 5.0) {
            viewpts[i_4].flags = 16
            zclipped = unsafe(reinterpret<qboolean>(1u))
        } else {
            if (unsafe(unsafe(addr(viewaux[i_4].fv[0]))[2]) < float(minz)) {
                minz = int(unsafe(unsafe(addr(viewaux[i_4].fv[0]))[2]))
            }
            viewpts[i_4].flags = 0
            zfullyclipped = unsafe(reinterpret<qboolean>(0u))
        }
        i_4++
    }
    if (uint(zfullyclipped) != 0u) {
        return unsafe(reinterpret<qboolean>(0u))
    }
    numv = 8
    if (uint(zclipped) != 0u) {
        i_4 = 0
        while (i_4 < 12) {
            pv0 = unsafe(addr<finalvert_s?>(unsafe(unsafe(addr(viewpts[0]))[aedges[i_4].index0])))
            pv1 = unsafe(addr<finalvert_s?>(unsafe(unsafe(addr(viewpts[0]))[aedges[i_4].index1])))
            pa0 = unsafe(addr<auxvert_t?>(unsafe(unsafe(addr(viewaux[0]))[aedges[i_4].index0])))
            pa1 = unsafe(addr<auxvert_t?>(unsafe(unsafe(addr(viewaux[0]))[aedges[i_4].index1])))
            if ((pv0.flags ^ pv1.flags) != 0) {
                var c2da_fresh66 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pa0))))
                var c2da_fresh67 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pa1))))
                var c2da_fresh68 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pa0))))
                frac = (5.0 - unsafe(unsafe(reinterpret<float?>(c2da_fresh66))[2])) / (unsafe(unsafe(reinterpret<float?>(c2da_fresh67))[2]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh68))[2]))
                var c2da_fresh69 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pa0))))
                var c2da_fresh70 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pa1))))
                var c2da_fresh71 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pa0))))
                unsafe(unsafe(addr(viewaux[numv].fv[0]))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh69))[0]) + (unsafe(unsafe(reinterpret<float?>(c2da_fresh70))[0]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh71))[0])) * frac
                var c2da_fresh72 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pa0))))
                var c2da_fresh73 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pa1))))
                var c2da_fresh74 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pa0))))
                unsafe(unsafe(addr(viewaux[numv].fv[0]))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh72))[1]) + (unsafe(unsafe(reinterpret<float?>(c2da_fresh73))[1]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh74))[1])) * frac
                unsafe(unsafe(addr(viewaux[numv].fv[0]))[2]) = 5.0
                viewpts[numv].flags = 0
                numv++
            }
            i_4++
        }
    }
    anyclip = 0u
    allclip = 0xfu
    i_4 = 0
    for (c2da_i_4 in range(i_4, numv)) {
        if ((viewpts[c2da_i_4].flags & 16) != 0) {
            continue
        }
        zi_1 = float(1.0lf / double(unsafe(unsafe(addr(viewaux[c2da_i_4].fv[0]))[2])))
        v0 = unsafe(unsafe(addr(viewaux[c2da_i_4].fv[0]))[0]) * xscale * zi_1 + xcenter
        v1 = unsafe(unsafe(addr(viewaux[c2da_i_4].fv[0]))[1]) * yscale * zi_1 + ycenter
        flags = 0
        if (v0 < r_refdef.fvrectx) {
            flags |= 1
        }
        if (v1 < r_refdef.fvrecty) {
            flags |= 2
        }
        if (v0 > r_refdef.fvrectright) {
            flags |= 4
        }
        if (v1 > r_refdef.fvrectbottom) {
            flags |= 8
        }
        anyclip |= uint(flags)
        allclip &= uint(flags)
    }
    if (allclip != 0x0) {
        return unsafe(reinterpret<qboolean>(0u))
    }
    currententity.trivial_accept = (anyclip == 0 ? 1 : 0) & (uint(zclipped) == 0u ? 1 : 0)
    if (currententity.trivial_accept != 0) {
        if (float(minz) > r_aliastransition + pmdl.size * r_resfudge) {
            currententity.trivial_accept = currententity.trivial_accept | 2
        }
    }
    return unsafe(reinterpret<qboolean>(1u))
}
var private aedges : aedge_t[12] = fixed_array<aedge_t>(aedge_t(index0 = 0, index1 = 1), aedge_t(index0 = 1, index1 = 2), aedge_t(index0 = 2, index1 = 3), aedge_t(index0 = 3, index1 = 0), aedge_t(index0 = 4, index1 = 5), aedge_t(index0 = 5, index1 = 6), aedge_t(index0 = 6, index1 = 7), aedge_t(index0 = 7, index1 = 4), aedge_t(index0 = 0, index1 = 5), aedge_t(index0 = 1, index1 = 4), aedge_t(index0 = 2, index1 = 7), aedge_t(index0 = 3, index1 = 6))

[export, sideeffects]
def R_AliasTransformVector(var in_0 : float?; var out : float?) {
    unsafe(out[0]) = unsafe(in_0[0]) * aliastransform[0][0] + unsafe(in_0[1]) * aliastransform[0][1] + unsafe(in_0[2]) * aliastransform[0][2] + aliastransform[0][3]
    unsafe(out[1]) = unsafe(in_0[0]) * aliastransform[1][0] + unsafe(in_0[1]) * aliastransform[1][1] + unsafe(in_0[2]) * aliastransform[1][2] + aliastransform[1][3]
    unsafe(out[2]) = unsafe(in_0[0]) * aliastransform[2][0] + unsafe(in_0[1]) * aliastransform[2][1] + unsafe(in_0[2]) * aliastransform[2][2] + aliastransform[2][3]
    return
}
var private pmodel : model_s? = default<model_s?>

[sideeffects]
def private c2da_layout_proofs_33() {
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
    static_assert(typeinfo sizeof(type<mdl_t>) == 84, "C layout of mdl_t: sizeof")
    static_assert(typeinfo alignof(type<mdl_t>) == 4, "C layout of mdl_t: alignof")
    static_assert(typeinfo offsetof<ident>(type<mdl_t>) == 0, "C layout of mdl_t: offsetof ident")
    static_assert(typeinfo offsetof<version>(type<mdl_t>) == 4, "C layout of mdl_t: offsetof version")
    static_assert(typeinfo offsetof<scale>(type<mdl_t>) == 8, "C layout of mdl_t: offsetof scale")
    static_assert(typeinfo offsetof<scale_origin>(type<mdl_t>) == 20, "C layout of mdl_t: offsetof scale_origin")
    static_assert(typeinfo offsetof<boundingradius>(type<mdl_t>) == 32, "C layout of mdl_t: offsetof boundingradius")
    static_assert(typeinfo offsetof<eyeposition>(type<mdl_t>) == 36, "C layout of mdl_t: offsetof eyeposition")
    static_assert(typeinfo offsetof<numskins>(type<mdl_t>) == 48, "C layout of mdl_t: offsetof numskins")
    static_assert(typeinfo offsetof<skinwidth>(type<mdl_t>) == 52, "C layout of mdl_t: offsetof skinwidth")
    static_assert(typeinfo offsetof<skinheight>(type<mdl_t>) == 56, "C layout of mdl_t: offsetof skinheight")
    static_assert(typeinfo offsetof<numverts>(type<mdl_t>) == 60, "C layout of mdl_t: offsetof numverts")
    static_assert(typeinfo offsetof<numtris>(type<mdl_t>) == 64, "C layout of mdl_t: offsetof numtris")
    static_assert(typeinfo offsetof<numframes>(type<mdl_t>) == 68, "C layout of mdl_t: offsetof numframes")
    static_assert(typeinfo offsetof<synctype>(type<mdl_t>) == 72, "C layout of mdl_t: offsetof synctype")
    static_assert(typeinfo offsetof<flags>(type<mdl_t>) == 76, "C layout of mdl_t: offsetof flags")
    static_assert(typeinfo offsetof<size>(type<mdl_t>) == 80, "C layout of mdl_t: offsetof size")
    static_assert(typeinfo sizeof(type<stvert_t>) == 12, "C layout of stvert_t: sizeof")
    static_assert(typeinfo alignof(type<stvert_t>) == 4, "C layout of stvert_t: alignof")
    static_assert(typeinfo offsetof<onseam>(type<stvert_t>) == 0, "C layout of stvert_t: offsetof onseam")
    static_assert(typeinfo offsetof<s>(type<stvert_t>) == 4, "C layout of stvert_t: offsetof s")
    static_assert(typeinfo offsetof<t>(type<stvert_t>) == 8, "C layout of stvert_t: offsetof t")
    static_assert(typeinfo sizeof(type<trivertx_t>) == 4, "C layout of trivertx_t: sizeof")
    static_assert(typeinfo alignof(type<trivertx_t>) == 1, "C layout of trivertx_t: alignof")
    static_assert(typeinfo offsetof<v>(type<trivertx_t>) == 0, "C layout of trivertx_t: offsetof v")
    static_assert(typeinfo offsetof<lightnormalindex>(type<trivertx_t>) == 3, "C layout of trivertx_t: offsetof lightnormalindex")
    static_assert(typeinfo sizeof(type<maliasframedesc_t>) == 32, "C layout of maliasframedesc_t: sizeof")
    static_assert(typeinfo alignof(type<maliasframedesc_t>) == 4, "C layout of maliasframedesc_t: alignof")
    static_assert(typeinfo offsetof<type_0>(type<maliasframedesc_t>) == 0, "C layout of maliasframedesc_t: offsetof type_0")
    static_assert(typeinfo offsetof<bboxmin>(type<maliasframedesc_t>) == 4, "C layout of maliasframedesc_t: offsetof bboxmin")
    static_assert(typeinfo offsetof<bboxmax>(type<maliasframedesc_t>) == 8, "C layout of maliasframedesc_t: offsetof bboxmax")
    static_assert(typeinfo offsetof<frame>(type<maliasframedesc_t>) == 12, "C layout of maliasframedesc_t: offsetof frame")
    static_assert(typeinfo offsetof<name>(type<maliasframedesc_t>) == 16, "C layout of maliasframedesc_t: offsetof name")
    static_assert(typeinfo sizeof(type<maliasskindesc_t>) == 24, "C layout of maliasskindesc_t: sizeof")
    static_assert(typeinfo alignof(type<maliasskindesc_t>) == 8, "C layout of maliasskindesc_t: alignof")
    static_assert(typeinfo offsetof<type_0>(type<maliasskindesc_t>) == 0, "C layout of maliasskindesc_t: offsetof type_0")
    static_assert(typeinfo offsetof<pcachespot>(type<maliasskindesc_t>) == 8, "C layout of maliasskindesc_t: offsetof pcachespot")
    static_assert(typeinfo offsetof<skin>(type<maliasskindesc_t>) == 16, "C layout of maliasskindesc_t: offsetof skin")
    static_assert(typeinfo sizeof(type<maliasgroupframedesc_t>) == 12, "C layout of maliasgroupframedesc_t: sizeof")
    static_assert(typeinfo alignof(type<maliasgroupframedesc_t>) == 4, "C layout of maliasgroupframedesc_t: alignof")
    static_assert(typeinfo offsetof<bboxmin>(type<maliasgroupframedesc_t>) == 0, "C layout of maliasgroupframedesc_t: offsetof bboxmin")
    static_assert(typeinfo offsetof<bboxmax>(type<maliasgroupframedesc_t>) == 4, "C layout of maliasgroupframedesc_t: offsetof bboxmax")
    static_assert(typeinfo offsetof<frame>(type<maliasgroupframedesc_t>) == 8, "C layout of maliasgroupframedesc_t: offsetof frame")
    static_assert(typeinfo sizeof(type<maliasgroup_t>) == 20, "C layout of maliasgroup_t: sizeof")
    static_assert(typeinfo alignof(type<maliasgroup_t>) == 4, "C layout of maliasgroup_t: alignof")
    static_assert(typeinfo offsetof<numframes>(type<maliasgroup_t>) == 0, "C layout of maliasgroup_t: offsetof numframes")
    static_assert(typeinfo offsetof<intervals>(type<maliasgroup_t>) == 4, "C layout of maliasgroup_t: offsetof intervals")
    static_assert(typeinfo offsetof<frames>(type<maliasgroup_t>) == 8, "C layout of maliasgroup_t: offsetof frames")
    static_assert(typeinfo sizeof(type<maliasskingroup_t>) == 32, "C layout of maliasskingroup_t: sizeof")
    static_assert(typeinfo alignof(type<maliasskingroup_t>) == 8, "C layout of maliasskingroup_t: alignof")
    static_assert(typeinfo offsetof<numskins>(type<maliasskingroup_t>) == 0, "C layout of maliasskingroup_t: offsetof numskins")
    static_assert(typeinfo offsetof<intervals>(type<maliasskingroup_t>) == 4, "C layout of maliasskingroup_t: offsetof intervals")
    static_assert(typeinfo offsetof<skindescs>(type<maliasskingroup_t>) == 8, "C layout of maliasskingroup_t: offsetof skindescs")
    static_assert(typeinfo sizeof(type<mtriangle_s>) == 16, "C layout of mtriangle_s: sizeof")
    static_assert(typeinfo alignof(type<mtriangle_s>) == 4, "C layout of mtriangle_s: alignof")
    static_assert(typeinfo offsetof<facesfront>(type<mtriangle_s>) == 0, "C layout of mtriangle_s: offsetof facesfront")
    static_assert(typeinfo offsetof<vertindex>(type<mtriangle_s>) == 4, "C layout of mtriangle_s: offsetof vertindex")
    static_assert(typeinfo sizeof(type<mtriangle_t>) == 16, "C layout of mtriangle_t: sizeof")
    static_assert(typeinfo alignof(type<mtriangle_t>) == 4, "C layout of mtriangle_t: alignof")
    static_assert(typeinfo offsetof<facesfront>(type<mtriangle_t>) == 0, "C layout of mtriangle_t: offsetof facesfront")
    static_assert(typeinfo offsetof<vertindex>(type<mtriangle_t>) == 4, "C layout of mtriangle_t: offsetof vertindex")
    static_assert(typeinfo sizeof(type<aliashdr_t>) == 48, "C layout of aliashdr_t: sizeof")
    static_assert(typeinfo alignof(type<aliashdr_t>) == 4, "C layout of aliashdr_t: alignof")
    static_assert(typeinfo offsetof<model>(type<aliashdr_t>) == 0, "C layout of aliashdr_t: offsetof model")
    static_assert(typeinfo offsetof<stverts>(type<aliashdr_t>) == 4, "C layout of aliashdr_t: offsetof stverts")
    static_assert(typeinfo offsetof<skindesc>(type<aliashdr_t>) == 8, "C layout of aliashdr_t: offsetof skindesc")
    static_assert(typeinfo offsetof<triangles>(type<aliashdr_t>) == 12, "C layout of aliashdr_t: offsetof triangles")
    static_assert(typeinfo offsetof<frames>(type<aliashdr_t>) == 16, "C layout of aliashdr_t: offsetof frames")
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
    static_assert(typeinfo sizeof(type<alight_t>) == 16, "C layout of alight_t: sizeof")
    static_assert(typeinfo alignof(type<alight_t>) == 8, "C layout of alight_t: alignof")
    static_assert(typeinfo offsetof<ambientlight>(type<alight_t>) == 0, "C layout of alight_t: offsetof ambientlight")
    static_assert(typeinfo offsetof<shadelight>(type<alight_t>) == 4, "C layout of alight_t: offsetof shadelight")
    static_assert(typeinfo offsetof<plightvec>(type<alight_t>) == 8, "C layout of alight_t: offsetof plightvec")
    static_assert(typeinfo sizeof(type<auxvert_t>) == 12, "C layout of auxvert_t: sizeof")
    static_assert(typeinfo alignof(type<auxvert_t>) == 4, "C layout of auxvert_t: alignof")
    static_assert(typeinfo offsetof<fv>(type<auxvert_t>) == 0, "C layout of auxvert_t: offsetof fv")
    static_assert(typeinfo sizeof(type<aedge_t>) == 8, "C layout of aedge_t: sizeof")
    static_assert(typeinfo alignof(type<aedge_t>) == 4, "C layout of aedge_t: alignof")
    static_assert(typeinfo offsetof<index0>(type<aedge_t>) == 0, "C layout of aedge_t: offsetof index0")
    static_assert(typeinfo offsetof<index1>(type<aedge_t>) == 4, "C layout of aedge_t: offsetof index1")
}
