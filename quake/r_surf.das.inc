var private c2da_str_r_surf_0 : array<int8> = [int8(85), int8(110), int8(107), int8(110), int8(111), int8(119), int8(110), int8(32), int8(116), int8(105), int8(108), int8(101), int8(32), int8(116), int8(121), int8(112), int8(101), int8(0)]

var private c2da_str_r_surf_1 : array<int8> = [int8(82), int8(95), int8(84), int8(101), int8(120), int8(116), int8(117), int8(114), int8(101), int8(65), int8(110), int8(105), int8(109), int8(97), int8(116), int8(105), int8(111), int8(110), int8(58), int8(32), int8(98), int8(114), int8(111), int8(107), int8(101), int8(110), int8(32), int8(99), int8(121), int8(99), int8(108), int8(101), int8(0)]

var private c2da_str_r_surf_2 : array<int8> = [int8(82), int8(95), int8(84), int8(101), int8(120), int8(116), int8(117), int8(114), int8(101), int8(65), int8(110), int8(105), int8(109), int8(97), int8(116), int8(105), int8(111), int8(110), int8(58), int8(32), int8(105), int8(110), int8(102), int8(105), int8(110), int8(105), int8(116), int8(101), int8(32), int8(99), int8(121), int8(99), int8(108), int8(101), int8(0)]

var r_drawsurf : drawsurf_t = default<drawsurf_t>

[export, sideeffects]
def R_DrawSurface() {
    var basetptr : uint8?
    var smax : int
    var tmax : int
    var twidth : int
    var u : int
    var soffset : int
    var basetoffset : int
    var texwidth : int
    var horzblockstep : int
    var pcolumndest : uint8?
    var pblockdrawer : function<():void>
    var mt : texture_s?
    R_BuildLightMap()
    surfrowbytes = int(r_drawsurf.rowbytes)  // nolint:PERF020
    mt = unsafe(reinterpret<texture_s?>(r_drawsurf.texture))
    var c2da_fresh0 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(mt)) + 56ul))
    r_source = unsafe(reinterpret<uint8?>(unsafe(unsafe(reinterpret<uint8?>(mt)) + int64(unsafe(unsafe(reinterpret<uint?>(c2da_fresh0))[r_drawsurf.surfmip])))))
    texwidth = int(mt.width >> uint(r_drawsurf.surfmip))
    blocksize = 16 >> r_drawsurf.surfmip
    blockdivshift = 4 - r_drawsurf.surfmip
    blockdivmask = uint((1 << blockdivshift) - 1)
    var c2da_fresh1 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(r_drawsurf.surf)) + 76ul))
    r_lightwidth = (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh1))[0])) >> 4) + 1
    r_numhblocks = r_drawsurf.surfwidth >> blockdivshift
    r_numvblocks = r_drawsurf.surfheight >> blockdivshift
    pblockdrawer = surfmiptable[r_drawsurf.surfmip]
    horzblockstep = blocksize
    smax = int(mt.width >> uint(r_drawsurf.surfmip))
    twidth = texwidth
    tmax = int(mt.height >> uint(r_drawsurf.surfmip))
    sourcetstep = texwidth
    r_stepback = tmax * twidth
    r_sourcemax = unsafe(reinterpret<uint8?>(unsafe(r_source + int64(tmax * smax))))
    var c2da_fresh2 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(r_drawsurf.surf)) + 72ul))
    soffset = int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh2))[0]))
    var c2da_fresh3 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(r_drawsurf.surf)) + 72ul))
    basetoffset = int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh3))[1]))
    soffset = ((soffset >> r_drawsurf.surfmip) + (smax << 16)) % smax
    basetptr = unsafe(addr<uint8?>(unsafe(r_source[((basetoffset >> r_drawsurf.surfmip) + (tmax << 16)) % tmax * twidth])))
    pcolumndest = unsafe(reinterpret<uint8?>(r_drawsurf.surfdat))
    u = 0
    while (u < r_numhblocks) {
        r_lightptr = unsafe(reinterpret<uint?>(unsafe(unsafe(addr(blocklights[0])) + u)))
        prowdestbase = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(pcolumndest))))
        pbasesource = unsafe(reinterpret<uint8?>(unsafe(basetptr + soffset)))
        invoke(pblockdrawer)
        soffset += blocksize
        if (soffset >= smax) {
            soffset = 0
        }
        unsafe {  // nolint:STYLE025
            pcolumndest += int64(horzblockstep)
        }
        u++
    }
    return
}
var blocksize : int = default<int>

var pbasesource : uint8? = default<uint8?>

var prowdestbase : uint8? = default<uint8?>

var blocklights : uint[324]

var r_lightptr : uint? = default<uint?>

var r_numhblocks : int = default<int>

var r_source : uint8? = default<uint8?>

var r_sourcemax : uint8? = default<uint8?>

var r_stepback : int = default<int>

var sourcetstep : int = default<int>

var surfrowbytes : int = default<int>

var lightleftstep : int = default<int>

var lightleft : int = default<int>

var lightrightstep : int = default<int>

var lightright : int = default<int>

var r_lightwidth : int = default<int>

var r_numvblocks : int = default<int>

var private surfmiptable : function<():void>[4] = fixed_array<function<():void>>(@@R_DrawSurfaceBlock8_mip0, @@R_DrawSurfaceBlock8_mip1, @@R_DrawSurfaceBlock8_mip2, @@R_DrawSurfaceBlock8_mip3)

[export, sideeffects]
def R_DrawSurfaceBlock8_mip3() {
    var v : int
    var b : int
    var lightstep : int
    var lighttemp : int
    var light : int
    var pix : uint8
    var psource : uint8?
    var prowdest : uint8?
    psource = unsafe(reinterpret<uint8?>(pbasesource))
    prowdest = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(prowdestbase))))
    v = 0
    while (v < r_numvblocks) {
        lightleft = int(unsafe(r_lightptr[0]))
        lightright = int(unsafe(r_lightptr[1]))
        unsafe {  // nolint:STYLE025
            r_lightptr += int64(r_lightwidth)
        }
        lightleftstep = int(unsafe(r_lightptr[0]) - uint(lightleft) >> 1u)
        lightrightstep = int(unsafe(r_lightptr[1]) - uint(lightright) >> 1u)
        for (i in range(0, 2)) {
            lighttemp = lightleft - lightright
            lightstep = lighttemp >> 1
            light = lightright
            b = 1
            while (b >= 0) {
                pix = unsafe(psource[b])
                unsafe(prowdest[b]) = uint8(unsafe(vid.colormap[(light & 65280) + int(pix)]))
                light += lightstep
                b--
            }
            unsafe {  // nolint:STYLE025
                psource += int64(sourcetstep)
            }
            lightright += lightrightstep
            lightleft += lightleftstep
            unsafe {  // nolint:STYLE025
                prowdest += int64(surfrowbytes)
            }
        }
        if (unsafe(reinterpret<uint64>(psource)) >= unsafe(reinterpret<uint64>(r_sourcemax))) {
            unsafe {  // nolint:STYLE025
                psource -= int64(r_stepback)
            }
        }
        v++
    }
    return
}
[export, sideeffects]
def R_DrawSurfaceBlock8_mip2() {
    var v_0 : int
    var b_0 : int
    var lightstep_0 : int
    var lighttemp_0 : int
    var light_0 : int
    var pix_0 : uint8
    var psource_0 : uint8?
    var prowdest_0 : uint8?
    psource_0 = unsafe(reinterpret<uint8?>(pbasesource))
    prowdest_0 = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(prowdestbase))))
    v_0 = 0
    while (v_0 < r_numvblocks) {
        lightleft = int(unsafe(r_lightptr[0]))
        lightright = int(unsafe(r_lightptr[1]))
        unsafe {  // nolint:STYLE025
            r_lightptr += int64(r_lightwidth)
        }
        lightleftstep = int(unsafe(r_lightptr[0]) - uint(lightleft) >> 2u)
        lightrightstep = int(unsafe(r_lightptr[1]) - uint(lightright) >> 2u)
        for (i_0 in range(0, 4)) {
            lighttemp_0 = lightleft - lightright
            lightstep_0 = lighttemp_0 >> 2
            light_0 = lightright
            b_0 = 3
            while (b_0 >= 0) {
                pix_0 = unsafe(psource_0[b_0])
                unsafe(prowdest_0[b_0]) = uint8(unsafe(vid.colormap[(light_0 & 65280) + int(pix_0)]))
                light_0 += lightstep_0
                b_0--
            }
            unsafe {  // nolint:STYLE025
                psource_0 += int64(sourcetstep)
            }
            lightright += lightrightstep
            lightleft += lightleftstep
            unsafe {  // nolint:STYLE025
                prowdest_0 += int64(surfrowbytes)
            }
        }
        if (unsafe(reinterpret<uint64>(psource_0)) >= unsafe(reinterpret<uint64>(r_sourcemax))) {
            unsafe {  // nolint:STYLE025
                psource_0 -= int64(r_stepback)
            }
        }
        v_0++
    }
    return
}
[export, sideeffects]
def R_DrawSurfaceBlock8_mip1() {
    var v_1 : int
    var b_1 : int
    var lightstep_1 : int
    var lighttemp_1 : int
    var light_1 : int
    var pix_1 : uint8
    var psource_1 : uint8?
    var prowdest_1 : uint8?
    psource_1 = unsafe(reinterpret<uint8?>(pbasesource))
    prowdest_1 = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(prowdestbase))))
    v_1 = 0
    while (v_1 < r_numvblocks) {
        lightleft = int(unsafe(r_lightptr[0]))
        lightright = int(unsafe(r_lightptr[1]))
        unsafe {  // nolint:STYLE025
            r_lightptr += int64(r_lightwidth)
        }
        lightleftstep = int(unsafe(r_lightptr[0]) - uint(lightleft) >> 3u)
        lightrightstep = int(unsafe(r_lightptr[1]) - uint(lightright) >> 3u)
        for (i_1 in range(0, 8)) {
            lighttemp_1 = lightleft - lightright
            lightstep_1 = lighttemp_1 >> 3
            light_1 = lightright
            b_1 = 7
            while (b_1 >= 0) {
                pix_1 = unsafe(psource_1[b_1])
                unsafe(prowdest_1[b_1]) = uint8(unsafe(vid.colormap[(light_1 & 65280) + int(pix_1)]))
                light_1 += lightstep_1
                b_1--
            }
            unsafe {  // nolint:STYLE025
                psource_1 += int64(sourcetstep)
            }
            lightright += lightrightstep
            lightleft += lightleftstep
            unsafe {  // nolint:STYLE025
                prowdest_1 += int64(surfrowbytes)
            }
        }
        if (unsafe(reinterpret<uint64>(psource_1)) >= unsafe(reinterpret<uint64>(r_sourcemax))) {
            unsafe {  // nolint:STYLE025
                psource_1 -= int64(r_stepback)
            }
        }
        v_1++
    }
    return
}
[export, sideeffects]
def R_DrawSurfaceBlock8_mip0() {
    var v_2 : int
    var b_2 : int
    var lightstep_2 : int
    var lighttemp_2 : int
    var light_2 : int
    var pix_2 : uint8
    var psource_2 : uint8?
    var prowdest_2 : uint8?
    psource_2 = unsafe(reinterpret<uint8?>(pbasesource))
    prowdest_2 = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(prowdestbase))))
    v_2 = 0
    while (v_2 < r_numvblocks) {
        lightleft = int(unsafe(r_lightptr[0]))
        lightright = int(unsafe(r_lightptr[1]))
        unsafe {  // nolint:STYLE025
            r_lightptr += int64(r_lightwidth)
        }
        lightleftstep = int(unsafe(r_lightptr[0]) - uint(lightleft) >> 4u)
        lightrightstep = int(unsafe(r_lightptr[1]) - uint(lightright) >> 4u)
        for (i_2 in range(0, 16)) {
            lighttemp_2 = lightleft - lightright
            lightstep_2 = lighttemp_2 >> 4
            light_2 = lightright
            b_2 = 15
            while (b_2 >= 0) {
                pix_2 = unsafe(psource_2[b_2])
                unsafe(prowdest_2[b_2]) = uint8(unsafe(vid.colormap[(light_2 & 65280) + int(pix_2)]))
                light_2 += lightstep_2
                b_2--
            }
            unsafe {  // nolint:STYLE025
                psource_2 += int64(sourcetstep)
            }
            lightright += lightrightstep
            lightleft += lightleftstep
            unsafe {  // nolint:STYLE025
                prowdest_2 += int64(surfrowbytes)
            }
        }
        if (unsafe(reinterpret<uint64>(psource_2)) >= unsafe(reinterpret<uint64>(r_sourcemax))) {
            unsafe {  // nolint:STYLE025
                psource_2 -= int64(r_stepback)
            }
        }
        v_2++
    }
    return
}
var blockdivshift : int = default<int>

var blockdivmask : uint = default<uint>

[export, sideeffects]
def R_BuildLightMap() {
    var smax_0 : int
    var tmax_0 : int
    var t : int
    var i_3 : int
    var size : int
    var lightmap : uint8?
    var scale : uint
    var maps : int
    var surf : msurface_s? = unsafe(reinterpret<msurface_s?>(r_drawsurf.surf))
    var c2da_fresh4 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(surf)) + 76ul))
    smax_0 = (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh4))[0])) >> 4) + 1
    var c2da_fresh5 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(surf)) + 76ul))
    smax_0 = (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh5))[0])) >> 4) + 1
    var c2da_fresh6 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(surf)) + 76ul))
    tmax_0 = (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh6))[1])) >> 4) + 1
    var c2da_fresh7 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(surf)) + 76ul))
    tmax_0 = (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh7))[1])) >> 4) + 1
    size = smax_0 * tmax_0
    lightmap = unsafe(reinterpret<uint8?>(surf.samples))
    if (r_fullbright.value != 0.0 || cl.worldmodel.lightdata == null) {
        i_3 = 0
        for (c2da_i_3 in range(i_3, size)) {
            blocklights[c2da_i_3] = 0u
        }
        return
    }
    i_3 = 0
    while (i_3 < size) {
        blocklights[i_3] = uint(r_refdef.ambientlight << 8)
        i_3++
    }
    if (lightmap != null) {
        maps = 0
        while (true) {
            var c2da_fresh9 : int = 0
            if (maps < 4) {
                var c2da_fresh8 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(surf)) + 88ul))
                if (int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh8))[maps])) != 255) {
                    c2da_fresh9 = 1
                }
            }
            if (c2da_fresh9 == 0) {
                break
            }
            scale = uint(unsafe(unsafe(addr(r_drawsurf.lightadj[0]))[maps]))
            i_3 = 0
            while (i_3 < size) {
                blocklights[i_3] += uint(unsafe(lightmap[i_3])) * scale
                i_3++
            }
            unsafe {  // nolint:STYLE025
                lightmap += int64(size)
            }
            maps++
        }
    }
    if (surf.dlightframe == r_framecount) {
        R_AddDynamicLights()
    }
    i_3 = 0
    for (c2da_i_3_0 in range(i_3, size)) {
        t = 255 * 256 - int(blocklights[c2da_i_3_0]) >> 8 - 6
        if (t < 1 << 6) {
            t = 1 << 6
        }
        blocklights[c2da_i_3_0] = uint(t)
    }
    return
}
[export, sideeffects]
def R_AddDynamicLights() {
    var surf_0 : msurface_s?
    var sd : int
    var td : int
    var dist : float
    var rad : float
    var minlight : float
    var impact : vec3_t
    var local : vec3_t
    var smax_1 : int
    var tmax_1 : int
    var tex : mtexinfo_t?
    surf_0 = unsafe(reinterpret<msurface_s?>(r_drawsurf.surf))
    var c2da_fresh10 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(surf_0)) + 76ul))
    smax_1 = (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh10))[0])) >> 4) + 1
    var c2da_fresh11 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(surf_0)) + 76ul))
    tmax_1 = (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh11))[1])) >> 4) + 1
    tex = unsafe(reinterpret<mtexinfo_t?>(surf_0.texinfo))
    for (lnum in range(0, 32)) {
        if ((surf_0.dlightbits & 1 << lnum) == 0) {
            continue
        }
        rad = cl_dlights[lnum].radius
        var c2da_fresh12 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(surf_0.plane))))
        var c2da_fresh13 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(surf_0.plane))))
        var c2da_fresh14 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(surf_0.plane))))
        dist = unsafe(unsafe(addr(cl_dlights[lnum].origin[0]))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh12))[0]) + unsafe(unsafe(addr(cl_dlights[lnum].origin[0]))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh13))[1]) + unsafe(unsafe(addr(cl_dlights[lnum].origin[0]))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh14))[2]) - surf_0.plane.dist
        rad = float(double(rad) - c2da_std_fabs(double(dist)))
        minlight = cl_dlights[lnum].minlight
        if (rad < minlight) {
            continue
        }
        minlight = rad - minlight
        for (i_4 in range(0, 3)) {
            var c2da_fresh15 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(surf_0.plane))))
            unsafe(unsafe(addr(impact[0]))[i_4]) = unsafe(unsafe(addr(cl_dlights[lnum].origin[0]))[i_4]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh15))[i_4]) * dist
        }
        var c2da_fresh16 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        var c2da_fresh17 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        var c2da_fresh18 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        var c2da_fresh19 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        unsafe(unsafe(addr(local[0]))[0]) = unsafe(unsafe(addr(impact[0]))[0]) * unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh16))[0])[0]))[0]) + unsafe(unsafe(addr(impact[0]))[1]) * unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh17))[0])[0]))[1]) + unsafe(unsafe(addr(impact[0]))[2]) * unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh18))[0])[0]))[2]) + unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh19))[0])[0]))[3])
        var c2da_fresh20 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        var c2da_fresh21 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        var c2da_fresh22 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        var c2da_fresh23 : float[4]? = unsafe(reinterpret<float[4]?>(unsafe(reinterpret<uint64>(tex))))
        unsafe(unsafe(addr(local[0]))[1]) = unsafe(unsafe(addr(impact[0]))[0]) * unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh20))[1])[0]))[0]) + unsafe(unsafe(addr(impact[0]))[1]) * unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh21))[1])[0]))[1]) + unsafe(unsafe(addr(impact[0]))[2]) * unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh22))[1])[0]))[2]) + unsafe(unsafe(addr(unsafe(unsafe(reinterpret<float[4]?>(c2da_fresh23))[1])[0]))[3])
        var c2da_fresh24 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(surf_0)) + 72ul))
        unsafe(unsafe(addr(local[0]))[0]) -= float(int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh24))[0])))
        var c2da_fresh25 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(surf_0)) + 72ul))
        unsafe(unsafe(addr(local[0]))[1]) -= float(int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh25))[1])))
        for (t_0 in range(0, tmax_1)) {
            td = int(unsafe(unsafe(addr(local[0]))[1]) - float(t_0 * 16))
            if (td < 0) {
                td = -td
            }
            for (s in range(0, smax_1)) {
                sd = int(unsafe(unsafe(addr(local[0]))[0]) - float(s * 16))
                if (sd < 0) {
                    sd = -sd
                }
                if (sd > td) {
                    dist = float(sd + (td >> 1))
                } else {
                    dist = float(td + (sd >> 1))
                }
                if (dist < minlight) {
                    blocklights[t_0 * smax_1 + s] = uint(float(blocklights[t_0 * smax_1 + s]) + (rad - dist) * 256.0)
                }
            }
        }
    }
    return
}
[export, sideeffects]
def R_GenTile(var psurf : msurface_s?; var pdest : uint8?) {
    if ((psurf.flags & 16) != 0) {
        var c2da_fresh26 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(psurf.texinfo.texture)) + 56ul))
        R_GenTurbTile(unsafe(unsafe(reinterpret<uint8?>(psurf.texinfo.texture)) + int64(unsafe(unsafe(reinterpret<uint?>(c2da_fresh26))[0]))), pdest)
    } elif ((psurf.flags & 4) != 0) {
        R_GenSkyTile(pdest)
    } else {
        Sys_Error(unsafe(addr<int8?>(c2da_str_r_surf_0[0])), [])
    }
    return
}
[export, sideeffects]
def R_GenTurbTile(var pbasetex : uint8?; var pdest_0 : uint8?) {
    var turb : int?
    var s_0 : int
    var t_1 : int
    var pd : uint8?
    turb = unsafe(reinterpret<int?>(unsafe(unsafe(addr(sintable[0])) + (int(cl.time * 20.0lf) & 128 - 1))))
    pd = unsafe(reinterpret<uint8?>(pdest_0))
    for (i_5 in range(0, 128)) {
        var c2da_pd_addr : uint64 = unsafe(reinterpret<uint64>(pd))
        for (j in range(0, 128)) {
            s_0 = (j << 16) + unsafe(turb[i_5 & 128 - 1]) >> 16 & 63
            t_1 = (i_5 << 16) + unsafe(turb[j & 128 - 1]) >> 16 & 63
            *unsafe(reinterpret<uint8?>(c2da_pd_addr)) = uint8(*unsafe(unsafe(pbasetex + int64(t_1 << 6)) + s_0))
            c2da_pd_addr++
        }
        pd = unsafe(reinterpret<uint8?>(c2da_pd_addr))
    }
    return
}
[export, sideeffects]
def R_TextureAnimation(var base : texture_s?) : texture_s? {
    var reletive : int
    var count : int
    if (currententity.frame != 0) {
        if (base.alternate_anims != null) {
            base = unsafe(reinterpret<texture_s?>(base.alternate_anims))
        }
    }
    if (base.anim_total == 0) {
        return unsafe(reinterpret<texture_s?>(base))
    }
    reletive = int(cl.time * 10.0lf) % base.anim_total
    count = 0
    while (base.anim_min > reletive || base.anim_max <= reletive) {
        base = unsafe(reinterpret<texture_s?>(base.anim_next))
        if (base == null) {
            Sys_Error(unsafe(addr<int8?>(c2da_str_r_surf_1[0])), [])
        }
        count++
        if (count > 100) {
            Sys_Error(unsafe(addr<int8?>(c2da_str_r_surf_2[0])), [])
        }
    }
    return unsafe(reinterpret<texture_s?>(base))
}
var sourcesstep : int = default<int>

var lightdelta : int = default<int>

var lightdeltastep : int = default<int>

[sideeffects]
def private c2da_layout_proofs_44() {
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
    static_assert(typeinfo sizeof(type<dlight_t>) == 32, "C layout of dlight_t: sizeof")
    static_assert(typeinfo alignof(type<dlight_t>) == 4, "C layout of dlight_t: alignof")
    static_assert(typeinfo offsetof<origin>(type<dlight_t>) == 0, "C layout of dlight_t: offsetof origin")
    static_assert(typeinfo offsetof<radius>(type<dlight_t>) == 12, "C layout of dlight_t: offsetof radius")
    static_assert(typeinfo offsetof<die>(type<dlight_t>) == 16, "C layout of dlight_t: offsetof die")
    static_assert(typeinfo offsetof<decay>(type<dlight_t>) == 20, "C layout of dlight_t: offsetof decay")
    static_assert(typeinfo offsetof<minlight>(type<dlight_t>) == 24, "C layout of dlight_t: offsetof minlight")
    static_assert(typeinfo offsetof<key>(type<dlight_t>) == 28, "C layout of dlight_t: offsetof key")
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
    static_assert(typeinfo sizeof(type<drawsurf_t>) == 64, "C layout of drawsurf_t: sizeof")
    static_assert(typeinfo alignof(type<drawsurf_t>) == 8, "C layout of drawsurf_t: alignof")
    static_assert(typeinfo offsetof<surfdat>(type<drawsurf_t>) == 0, "C layout of drawsurf_t: offsetof surfdat")
    static_assert(typeinfo offsetof<rowbytes>(type<drawsurf_t>) == 8, "C layout of drawsurf_t: offsetof rowbytes")
    static_assert(typeinfo offsetof<surf>(type<drawsurf_t>) == 16, "C layout of drawsurf_t: offsetof surf")
    static_assert(typeinfo offsetof<lightadj>(type<drawsurf_t>) == 24, "C layout of drawsurf_t: offsetof lightadj")
    static_assert(typeinfo offsetof<texture>(type<drawsurf_t>) == 40, "C layout of drawsurf_t: offsetof texture")
    static_assert(typeinfo offsetof<surfmip>(type<drawsurf_t>) == 48, "C layout of drawsurf_t: offsetof surfmip")
    static_assert(typeinfo offsetof<surfwidth>(type<drawsurf_t>) == 52, "C layout of drawsurf_t: offsetof surfwidth")
    static_assert(typeinfo offsetof<surfheight>(type<drawsurf_t>) == 56, "C layout of drawsurf_t: offsetof surfheight")
}
