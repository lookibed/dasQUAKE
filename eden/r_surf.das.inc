var r_drawsurf : drawsurf_t = default<drawsurf_t>

[export, sideeffects]
def R_DrawSurface() {
    var basetptr : int
    var smax : int
    var tmax : int
    var twidth : int
    var u : int
    var soffset : int
    var basetoffset : int
    var texwidth : int
    var horzblockstep : int
    var pcolumndest : int
    var pblockdrawer : int
    var mt : int
    R_BuildLightMap()
    surfrowbytes = int(r_drawsurf.rowbytes)  // nolint:PERF020
    mt = r_drawsurf.texture
    let c2da_fresh0 : int = mt + 56 + r_drawsurf.surfmip * 4
    r_source = mt + int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18)
    texwidth = int((uint(c2da_mem[mt + 16]) | uint(c2da_mem[mt + 17]) << 0x8 | uint(c2da_mem[mt + 18]) << 0x10 | uint(c2da_mem[mt + 19]) << 0x18) >> uint(r_drawsurf.surfmip))
    blocksize = 16 >> r_drawsurf.surfmip
    blockdivshift = 4 - r_drawsurf.surfmip
    blockdivmask = uint((1 << blockdivshift) - 1)
    let c2da_fresh1 : int = r_drawsurf.surf + 76 + 0 * 2
    r_lightwidth = (int(int16(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8)) >> 4) + 1
    r_numhblocks = r_drawsurf.surfwidth >> blockdivshift
    r_numvblocks = r_drawsurf.surfheight >> blockdivshift
    pblockdrawer = surfmiptable[r_drawsurf.surfmip]
    horzblockstep = blocksize
    smax = int((uint(c2da_mem[mt + 16]) | uint(c2da_mem[mt + 17]) << 0x8 | uint(c2da_mem[mt + 18]) << 0x10 | uint(c2da_mem[mt + 19]) << 0x18) >> uint(r_drawsurf.surfmip))
    twidth = texwidth
    tmax = int((uint(c2da_mem[mt + 20]) | uint(c2da_mem[mt + 21]) << 0x8 | uint(c2da_mem[mt + 22]) << 0x10 | uint(c2da_mem[mt + 23]) << 0x18) >> uint(r_drawsurf.surfmip))
    sourcetstep = texwidth
    r_stepback = tmax * twidth
    r_sourcemax = r_source + tmax * smax
    let c2da_fresh2 : int = r_drawsurf.surf + 72 + 0 * 2
    soffset = int(int16(uint(c2da_mem[c2da_fresh2]) | uint(c2da_mem[c2da_fresh2 + 1]) << 0x8))
    let c2da_fresh3 : int = r_drawsurf.surf + 72 + 1 * 2
    basetoffset = int(int16(uint(c2da_mem[c2da_fresh3]) | uint(c2da_mem[c2da_fresh3 + 1]) << 0x8))
    soffset = ((soffset >> r_drawsurf.surfmip) + (smax << 16)) % smax
    basetptr = r_source + ((basetoffset >> r_drawsurf.surfmip) + (tmax << 16)) % tmax * twidth
    pcolumndest = r_drawsurf.surfdat
    u = 0
    while (u < r_numhblocks) {
        r_lightptr = 459488 + u * 4
        prowdestbase = pcolumndest
        pbasesource = basetptr + soffset
        invoke(c2da_fn_table0[pblockdrawer])
        soffset += blocksize
        if (soffset >= smax) {
            soffset = 0
        }
        pcolumndest += horzblockstep
        u++
    }
    return
}
var blocksize : int = default<int>

var pbasesource : int = default<int>

var prowdestbase : int = default<int>

var r_lightptr : int = default<int>

var r_numhblocks : int = default<int>

var r_source : int = default<int>

var r_sourcemax : int = default<int>

var r_stepback : int = default<int>

var sourcetstep : int = default<int>

var private surfmiptable : int[4] = fixed_array<int>(211, 212, 213, 214)

[export, sideeffects]
def R_DrawSurfaceBlock8_mip3() {
    var v : int
    var b : int
    var lightstep : int
    var lighttemp : int
    var light : int
    var pix : uint8
    var psource : int
    var prowdest : int
    psource = pbasesource
    prowdest = prowdestbase
    v = 0
    while (v < r_numvblocks) {
        lightleft = int(uint(c2da_mem[r_lightptr + 0 * 4]) | uint(c2da_mem[r_lightptr + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 0 * 4 + 3]) << 0x18)
        lightright = int(uint(c2da_mem[r_lightptr + 1 * 4]) | uint(c2da_mem[r_lightptr + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 1 * 4 + 3]) << 0x18)
        r_lightptr += r_lightwidth * 4
        lightleftstep = int((uint(c2da_mem[r_lightptr + 0 * 4]) | uint(c2da_mem[r_lightptr + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 0 * 4 + 3]) << 0x18) - uint(lightleft) >> 1u)
        lightrightstep = int((uint(c2da_mem[r_lightptr + 1 * 4]) | uint(c2da_mem[r_lightptr + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 1 * 4 + 3]) << 0x18) - uint(lightright) >> 1u)
        for (i in range(0, 2)) {
            lighttemp = lightleft - lightright
            lightstep = lighttemp >> 1
            light = lightright
            b = 1
            while (b >= 0) {
                pix = uint8(c2da_mem[psource + b])
                let c2da_fresh4 : int = vid.colormap + ((light & 65280) + int(pix))
                let c2da_fresh5 : uint8 = c2da_mem[c2da_fresh4]
                c2da_mem[prowdest + b] = c2da_fresh5
                light += lightstep
                b--
            }
            psource += sourcetstep
            lightright += lightrightstep
            lightleft += lightleftstep
            prowdest += surfrowbytes
        }
        if (psource >= r_sourcemax) {
            psource -= r_stepback
        }
        v++
    }
    return
}
var surfrowbytes : int = default<int>

var lightleftstep : int = default<int>

var lightleft : int = default<int>

var lightrightstep : int = default<int>

var lightright : int = default<int>

var r_lightwidth : int = default<int>

var r_numvblocks : int = default<int>

[export, sideeffects]
def R_DrawSurfaceBlock8_mip2() {
    var v_0 : int
    var b_0 : int
    var lightstep_0 : int
    var lighttemp_0 : int
    var light_0 : int
    var pix_0 : uint8
    var psource_0 : int
    var prowdest_0 : int
    psource_0 = pbasesource
    prowdest_0 = prowdestbase
    v_0 = 0
    while (v_0 < r_numvblocks) {
        lightleft = int(uint(c2da_mem[r_lightptr + 0 * 4]) | uint(c2da_mem[r_lightptr + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 0 * 4 + 3]) << 0x18)
        lightright = int(uint(c2da_mem[r_lightptr + 1 * 4]) | uint(c2da_mem[r_lightptr + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 1 * 4 + 3]) << 0x18)
        r_lightptr += r_lightwidth * 4
        lightleftstep = int((uint(c2da_mem[r_lightptr + 0 * 4]) | uint(c2da_mem[r_lightptr + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 0 * 4 + 3]) << 0x18) - uint(lightleft) >> 2u)
        lightrightstep = int((uint(c2da_mem[r_lightptr + 1 * 4]) | uint(c2da_mem[r_lightptr + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 1 * 4 + 3]) << 0x18) - uint(lightright) >> 2u)
        for (i_0 in range(0, 4)) {
            lighttemp_0 = lightleft - lightright
            lightstep_0 = lighttemp_0 >> 2
            light_0 = lightright
            b_0 = 3
            while (b_0 >= 0) {
                pix_0 = uint8(c2da_mem[psource_0 + b_0])
                let c2da_fresh6 : int = vid.colormap + ((light_0 & 65280) + int(pix_0))
                let c2da_fresh7 : uint8 = c2da_mem[c2da_fresh6]
                c2da_mem[prowdest_0 + b_0] = c2da_fresh7
                light_0 += lightstep_0
                b_0--
            }
            psource_0 += sourcetstep
            lightright += lightrightstep
            lightleft += lightleftstep
            prowdest_0 += surfrowbytes
        }
        if (psource_0 >= r_sourcemax) {
            psource_0 -= r_stepback
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
    var psource_1 : int
    var prowdest_1 : int
    psource_1 = pbasesource
    prowdest_1 = prowdestbase
    v_1 = 0
    while (v_1 < r_numvblocks) {
        lightleft = int(uint(c2da_mem[r_lightptr + 0 * 4]) | uint(c2da_mem[r_lightptr + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 0 * 4 + 3]) << 0x18)
        lightright = int(uint(c2da_mem[r_lightptr + 1 * 4]) | uint(c2da_mem[r_lightptr + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 1 * 4 + 3]) << 0x18)
        r_lightptr += r_lightwidth * 4
        lightleftstep = int((uint(c2da_mem[r_lightptr + 0 * 4]) | uint(c2da_mem[r_lightptr + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 0 * 4 + 3]) << 0x18) - uint(lightleft) >> 3u)
        lightrightstep = int((uint(c2da_mem[r_lightptr + 1 * 4]) | uint(c2da_mem[r_lightptr + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 1 * 4 + 3]) << 0x18) - uint(lightright) >> 3u)
        for (i_1 in range(0, 8)) {
            lighttemp_1 = lightleft - lightright
            lightstep_1 = lighttemp_1 >> 3
            light_1 = lightright
            b_1 = 7
            while (b_1 >= 0) {
                pix_1 = uint8(c2da_mem[psource_1 + b_1])
                let c2da_fresh8 : int = vid.colormap + ((light_1 & 65280) + int(pix_1))
                let c2da_fresh9 : uint8 = c2da_mem[c2da_fresh8]
                c2da_mem[prowdest_1 + b_1] = c2da_fresh9
                light_1 += lightstep_1
                b_1--
            }
            psource_1 += sourcetstep
            lightright += lightrightstep
            lightleft += lightleftstep
            prowdest_1 += surfrowbytes
        }
        if (psource_1 >= r_sourcemax) {
            psource_1 -= r_stepback
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
    var psource_2 : int
    var prowdest_2 : int
    psource_2 = pbasesource
    prowdest_2 = prowdestbase
    v_2 = 0
    while (v_2 < r_numvblocks) {
        lightleft = int(uint(c2da_mem[r_lightptr + 0 * 4]) | uint(c2da_mem[r_lightptr + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 0 * 4 + 3]) << 0x18)
        lightright = int(uint(c2da_mem[r_lightptr + 1 * 4]) | uint(c2da_mem[r_lightptr + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 1 * 4 + 3]) << 0x18)
        r_lightptr += r_lightwidth * 4
        lightleftstep = int((uint(c2da_mem[r_lightptr + 0 * 4]) | uint(c2da_mem[r_lightptr + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 0 * 4 + 3]) << 0x18) - uint(lightleft) >> 4u)
        lightrightstep = int((uint(c2da_mem[r_lightptr + 1 * 4]) | uint(c2da_mem[r_lightptr + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[r_lightptr + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[r_lightptr + 1 * 4 + 3]) << 0x18) - uint(lightright) >> 4u)
        for (i_2 in range(0, 16)) {
            lighttemp_2 = lightleft - lightright
            lightstep_2 = lighttemp_2 >> 4
            light_2 = lightright
            b_2 = 15
            while (b_2 >= 0) {
                pix_2 = uint8(c2da_mem[psource_2 + b_2])
                let c2da_fresh10 : int = vid.colormap + ((light_2 & 65280) + int(pix_2))
                let c2da_fresh11 : uint8 = c2da_mem[c2da_fresh10]
                c2da_mem[prowdest_2 + b_2] = c2da_fresh11
                light_2 += lightstep_2
                b_2--
            }
            psource_2 += sourcetstep
            lightright += lightrightstep
            lightleft += lightleftstep
            prowdest_2 += surfrowbytes
        }
        if (psource_2 >= r_sourcemax) {
            psource_2 -= r_stepback
        }
        v_2++
    }
    return
}
var blockdivshift : int = default<int>

var blockdivmask : uint = default<uint>

[export, sideeffects]
def R_BuildLightMap() {
    var t : int
    var i_3 : int
    var size : int
    var lightmap : int
    var scale : uint
    var maps : int
    var surf : int = r_drawsurf.surf
    size = ((int(int16(uint(c2da_mem[surf + 76 + 0 * 2]) | uint(c2da_mem[surf + 76 + 0 * 2 + 1]) << 0x8)) >> 4) + 1) * ((int(int16(uint(c2da_mem[surf + 76 + 1 * 2]) | uint(c2da_mem[surf + 76 + 1 * 2 + 1]) << 0x8)) >> 4) + 1)
    lightmap = int(uint(c2da_mem[surf + 96]) | uint(c2da_mem[surf + 97]) << 0x8 | uint(c2da_mem[surf + 98]) << 0x10 | uint(c2da_mem[surf + 99]) << 0x18)
    var c2da_fresh13 : int = 1
    if (!(uint_bits_to_float(uint(c2da_mem[392328]) | uint(c2da_mem[392329]) << 0x8 | uint(c2da_mem[392330]) << 0x10 | uint(c2da_mem[392331]) << 0x18) != 0.0)) {
        let c2da_fresh12 : int = int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) + 512
        if (!(int(uint(c2da_mem[c2da_fresh12]) | uint(c2da_mem[c2da_fresh12 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh12 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh12 + 3]) << 0x18) == 0)) {
            c2da_fresh13 = 0
        }
    }
    if (c2da_fresh13 != 0) {
        i_3 = 0
        for (c2da_i_3 in range(i_3, size)) {
            let c2da_fresh14 : uint = 0u
            let c2da_fresh15 : uint = c2da_fresh14
            c2da_mem[459488 + c2da_i_3 * 4] = uint8(c2da_fresh15)
            c2da_mem[459488 + c2da_i_3 * 4 + 1] = uint8(c2da_fresh15 >> 0x8)
            c2da_mem[459488 + c2da_i_3 * 4 + 2] = uint8(c2da_fresh15 >> 0x10)
            c2da_mem[459488 + c2da_i_3 * 4 + 3] = uint8(c2da_fresh15 >> 0x18)
        }
        return
    }
    i_3 = 0
    while (i_3 < size) {
        let c2da_fresh16 : uint = uint(int(uint(c2da_mem[5352]) | uint(c2da_mem[5353]) << 0x8 | uint(c2da_mem[5354]) << 0x10 | uint(c2da_mem[5355]) << 0x18) << 8)
        let c2da_fresh17 : uint = c2da_fresh16
        c2da_mem[459488 + i_3 * 4] = uint8(c2da_fresh17)
        c2da_mem[459488 + i_3 * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
        c2da_mem[459488 + i_3 * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
        c2da_mem[459488 + i_3 * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
        i_3++
    }
    if (lightmap != 0) {
        maps = 0
        while (maps < 4 && int(c2da_mem[surf + 88 + maps]) != 255) {
            scale = uint(r_drawsurf.lightadj[maps])
            i_3 = 0
            while (i_3 < size) {
                let c2da_fresh18 : uint = (uint(c2da_mem[459488 + i_3 * 4]) | uint(c2da_mem[459488 + i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[459488 + i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[459488 + i_3 * 4 + 3]) << 0x18) + uint(c2da_mem[lightmap + i_3]) * scale
                let c2da_fresh19 : uint = c2da_fresh18
                c2da_mem[459488 + i_3 * 4] = uint8(c2da_fresh19)
                c2da_mem[459488 + i_3 * 4 + 1] = uint8(c2da_fresh19 >> 0x8)
                c2da_mem[459488 + i_3 * 4 + 2] = uint8(c2da_fresh19 >> 0x10)
                c2da_mem[459488 + i_3 * 4 + 3] = uint8(c2da_fresh19 >> 0x18)
                i_3++
            }
            lightmap += size
            maps++
        }
    }
    if (int(uint(c2da_mem[surf + 4]) | uint(c2da_mem[surf + 5]) << 0x8 | uint(c2da_mem[surf + 6]) << 0x10 | uint(c2da_mem[surf + 7]) << 0x18) == r_framecount) {
        R_AddDynamicLights()
    }
    i_3 = 0
    for (c2da_i_3_0 in range(i_3, size)) {
        t = 255 * 256 - int(uint(c2da_mem[459488 + c2da_i_3_0 * 4]) | uint(c2da_mem[459488 + c2da_i_3_0 * 4 + 1]) << 0x8 | uint(c2da_mem[459488 + c2da_i_3_0 * 4 + 2]) << 0x10 | uint(c2da_mem[459488 + c2da_i_3_0 * 4 + 3]) << 0x18) >> 8 - 6
        if (t < 1 << 6) {
            t = 1 << 6
        }
        let c2da_fresh20 : uint = uint(t)
        let c2da_fresh21 : uint = c2da_fresh20
        c2da_mem[459488 + c2da_i_3_0 * 4] = uint8(c2da_fresh21)
        c2da_mem[459488 + c2da_i_3_0 * 4 + 1] = uint8(c2da_fresh21 >> 0x8)
        c2da_mem[459488 + c2da_i_3_0 * 4 + 2] = uint8(c2da_fresh21 >> 0x10)
        c2da_mem[459488 + c2da_i_3_0 * 4 + 3] = uint8(c2da_fresh21 >> 0x18)
    }
    return
}
[export, sideeffects]
def R_AddDynamicLights() {
    var surf_0 : int
    var sd : int
    var td : int
    var dist : float
    var rad : float
    var minlight : float
    var impact : vec3_t
    var local : vec3_t
    var smax_1 : int
    var tmax_1 : int
    var tex : int
    surf_0 = r_drawsurf.surf
    smax_1 = (int(int16(uint(c2da_mem[surf_0 + 76 + 0 * 2]) | uint(c2da_mem[surf_0 + 76 + 0 * 2 + 1]) << 0x8)) >> 4) + 1
    tmax_1 = (int(int16(uint(c2da_mem[surf_0 + 76 + 1 * 2]) | uint(c2da_mem[surf_0 + 76 + 1 * 2 + 1]) << 0x8)) >> 4) + 1
    tex = int(uint(c2da_mem[surf_0 + 80]) | uint(c2da_mem[surf_0 + 81]) << 0x8 | uint(c2da_mem[surf_0 + 82]) << 0x10 | uint(c2da_mem[surf_0 + 83]) << 0x18)
    for (lnum in range(0, 32)) {
        if ((int(uint(c2da_mem[surf_0 + 8]) | uint(c2da_mem[surf_0 + 9]) << 0x8 | uint(c2da_mem[surf_0 + 10]) << 0x10 | uint(c2da_mem[surf_0 + 11]) << 0x18) & 1 << lnum) == 0) {
            continue
        }
        rad = uint_bits_to_float(uint(c2da_mem[8112 + lnum * 32 + 12]) | uint(c2da_mem[8112 + lnum * 32 + 13]) << 0x8 | uint(c2da_mem[8112 + lnum * 32 + 14]) << 0x10 | uint(c2da_mem[8112 + lnum * 32 + 15]) << 0x18)
        let c2da_fresh22 : int = int(uint(c2da_mem[surf_0 + 16]) | uint(c2da_mem[surf_0 + 17]) << 0x8 | uint(c2da_mem[surf_0 + 18]) << 0x10 | uint(c2da_mem[surf_0 + 19]) << 0x18) + 0 * 4
        let c2da_fresh23 : int = int(uint(c2da_mem[surf_0 + 16]) | uint(c2da_mem[surf_0 + 17]) << 0x8 | uint(c2da_mem[surf_0 + 18]) << 0x10 | uint(c2da_mem[surf_0 + 19]) << 0x18) + 1 * 4
        let c2da_fresh24 : int = int(uint(c2da_mem[surf_0 + 16]) | uint(c2da_mem[surf_0 + 17]) << 0x8 | uint(c2da_mem[surf_0 + 18]) << 0x10 | uint(c2da_mem[surf_0 + 19]) << 0x18) + 2 * 4
        let c2da_fresh25 : int = int(uint(c2da_mem[surf_0 + 16]) | uint(c2da_mem[surf_0 + 17]) << 0x8 | uint(c2da_mem[surf_0 + 18]) << 0x10 | uint(c2da_mem[surf_0 + 19]) << 0x18) + 12
        dist = uint_bits_to_float(uint(c2da_mem[8112 + lnum * 32 + 0 * 4]) | uint(c2da_mem[8112 + lnum * 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[8112 + lnum * 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[8112 + lnum * 32 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fresh22]) | uint(c2da_mem[c2da_fresh22 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh22 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh22 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[8112 + lnum * 32 + 1 * 4]) | uint(c2da_mem[8112 + lnum * 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[8112 + lnum * 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[8112 + lnum * 32 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fresh23]) | uint(c2da_mem[c2da_fresh23 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh23 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh23 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[8112 + lnum * 32 + 2 * 4]) | uint(c2da_mem[8112 + lnum * 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[8112 + lnum * 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[8112 + lnum * 32 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fresh24]) | uint(c2da_mem[c2da_fresh24 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh24 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh24 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fresh25]) | uint(c2da_mem[c2da_fresh25 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh25 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh25 + 3]) << 0x18)
        rad = float(double(rad) - c2da_std_fabs(double(dist)))
        minlight = uint_bits_to_float(uint(c2da_mem[8112 + lnum * 32 + 24]) | uint(c2da_mem[8112 + lnum * 32 + 25]) << 0x8 | uint(c2da_mem[8112 + lnum * 32 + 26]) << 0x10 | uint(c2da_mem[8112 + lnum * 32 + 27]) << 0x18)
        if (rad < minlight) {
            continue
        }
        minlight = rad - minlight
        for (i_4 in range(0, 3)) {
            let c2da_fresh26 : int = int(uint(c2da_mem[surf_0 + 16]) | uint(c2da_mem[surf_0 + 17]) << 0x8 | uint(c2da_mem[surf_0 + 18]) << 0x10 | uint(c2da_mem[surf_0 + 19]) << 0x18) + i_4 * 4
            impact[i_4] = uint_bits_to_float(uint(c2da_mem[8112 + lnum * 32 + i_4 * 4]) | uint(c2da_mem[8112 + lnum * 32 + i_4 * 4 + 1]) << 0x8 | uint(c2da_mem[8112 + lnum * 32 + i_4 * 4 + 2]) << 0x10 | uint(c2da_mem[8112 + lnum * 32 + i_4 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fresh26]) | uint(c2da_mem[c2da_fresh26 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh26 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh26 + 3]) << 0x18) * dist
        }
        local[0] = impact[0] * uint_bits_to_float(uint(c2da_mem[tex + 0 * 16 + 0 * 4]) | uint(c2da_mem[tex + 0 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 0 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 0 * 16 + 0 * 4 + 3]) << 0x18) + impact[1] * uint_bits_to_float(uint(c2da_mem[tex + 0 * 16 + 1 * 4]) | uint(c2da_mem[tex + 0 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 0 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 0 * 16 + 1 * 4 + 3]) << 0x18) + impact[2] * uint_bits_to_float(uint(c2da_mem[tex + 0 * 16 + 2 * 4]) | uint(c2da_mem[tex + 0 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 0 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 0 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[tex + 0 * 16 + 3 * 4]) | uint(c2da_mem[tex + 0 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 0 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 0 * 16 + 3 * 4 + 3]) << 0x18)
        local[1] = impact[0] * uint_bits_to_float(uint(c2da_mem[tex + 1 * 16 + 0 * 4]) | uint(c2da_mem[tex + 1 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 1 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 1 * 16 + 0 * 4 + 3]) << 0x18) + impact[1] * uint_bits_to_float(uint(c2da_mem[tex + 1 * 16 + 1 * 4]) | uint(c2da_mem[tex + 1 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 1 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 1 * 16 + 1 * 4 + 3]) << 0x18) + impact[2] * uint_bits_to_float(uint(c2da_mem[tex + 1 * 16 + 2 * 4]) | uint(c2da_mem[tex + 1 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 1 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 1 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[tex + 1 * 16 + 3 * 4]) | uint(c2da_mem[tex + 1 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[tex + 1 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[tex + 1 * 16 + 3 * 4 + 3]) << 0x18)
        local[0] -= float(int(int16(uint(c2da_mem[surf_0 + 72 + 0 * 2]) | uint(c2da_mem[surf_0 + 72 + 0 * 2 + 1]) << 0x8)))
        local[1] -= float(int(int16(uint(c2da_mem[surf_0 + 72 + 1 * 2]) | uint(c2da_mem[surf_0 + 72 + 1 * 2 + 1]) << 0x8)))
        for (t_0 in range(0, tmax_1)) {
            td = int(local[1] - float(t_0 * 16))
            if (td < 0) {
                td = -td
            }
            for (s in range(0, smax_1)) {
                sd = int(local[0] - float(s * 16))
                if (sd < 0) {
                    sd = -sd
                }
                if (sd > td) {
                    dist = float(sd + (td >> 1))
                } else {
                    dist = float(td + (sd >> 1))
                }
                if (dist < minlight) {
                    let c2da_fresh27 : uint = uint(float(uint(c2da_mem[459488 + (t_0 * smax_1 + s) * 4]) | uint(c2da_mem[459488 + (t_0 * smax_1 + s) * 4 + 1]) << 0x8 | uint(c2da_mem[459488 + (t_0 * smax_1 + s) * 4 + 2]) << 0x10 | uint(c2da_mem[459488 + (t_0 * smax_1 + s) * 4 + 3]) << 0x18) + (rad - dist) * 256.0)
                    let c2da_fresh28 : uint = c2da_fresh27
                    c2da_mem[459488 + (t_0 * smax_1 + s) * 4] = uint8(c2da_fresh28)
                    c2da_mem[459488 + (t_0 * smax_1 + s) * 4 + 1] = uint8(c2da_fresh28 >> 0x8)
                    c2da_mem[459488 + (t_0 * smax_1 + s) * 4 + 2] = uint8(c2da_fresh28 >> 0x10)
                    c2da_mem[459488 + (t_0 * smax_1 + s) * 4 + 3] = uint8(c2da_fresh28 >> 0x18)
                }
            }
        }
    }
    return
}
[export, sideeffects]
def R_GenTile(var psurf : int; var pdest : int) {
    if ((int(uint(c2da_mem[psurf + 24]) | uint(c2da_mem[psurf + 25]) << 0x8 | uint(c2da_mem[psurf + 26]) << 0x10 | uint(c2da_mem[psurf + 27]) << 0x18) & 16) != 0) {
        let c2da_fresh29 : int = int(uint(c2da_mem[psurf + 80]) | uint(c2da_mem[psurf + 81]) << 0x8 | uint(c2da_mem[psurf + 82]) << 0x10 | uint(c2da_mem[psurf + 83]) << 0x18) + 40
        let c2da_fresh30 : int = int(uint(c2da_mem[psurf + 80]) | uint(c2da_mem[psurf + 81]) << 0x8 | uint(c2da_mem[psurf + 82]) << 0x10 | uint(c2da_mem[psurf + 83]) << 0x18) + 40
        let c2da_fresh31 : int = int(uint(c2da_mem[c2da_fresh30]) | uint(c2da_mem[c2da_fresh30 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh30 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh30 + 3]) << 0x18) + 56 + 0 * 4
        R_GenTurbTile(int(uint(c2da_mem[c2da_fresh29]) | uint(c2da_mem[c2da_fresh29 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh29 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh29 + 3]) << 0x18) + int(uint(c2da_mem[c2da_fresh31]) | uint(c2da_mem[c2da_fresh31 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh31 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh31 + 3]) << 0x18), pdest)
    } elif ((int(uint(c2da_mem[psurf + 24]) | uint(c2da_mem[psurf + 25]) << 0x8 | uint(c2da_mem[psurf + 26]) << 0x10 | uint(c2da_mem[psurf + 27]) << 0x18) & 4) != 0) {
        R_GenSkyTile(pdest)
    } else {
        Sys_Error(734544, [])
    }
    return
}
[export, sideeffects]
def R_GenTurbTile(var pbasetex : int; var pdest_0 : int) {
    var turb : int
    var s_0 : int
    var t_1 : int
    var pd : int
    turb = 210944 + (int(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) * 20.0lf) & 128 - 1) * 4
    pd = pdest_0
    for (i_5 in range(0, 128)) {
        for (j in range(0, 128)) {
            let c2da_fresh32 : int = turb + (i_5 & 128 - 1) * 4
            s_0 = (j << 16) + int(uint(c2da_mem[c2da_fresh32]) | uint(c2da_mem[c2da_fresh32 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh32 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh32 + 3]) << 0x18) >> 16 & 63
            let c2da_fresh33 : int = turb + (j & 128 - 1) * 4
            t_1 = (i_5 << 16) + int(uint(c2da_mem[c2da_fresh33]) | uint(c2da_mem[c2da_fresh33 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh33 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh33 + 3]) << 0x18) >> 16 & 63
            let c2da_fresh34 : int = pd
            pd++
            let c2da_fresh35 : int = pbasetex + (t_1 << 6) + s_0
            let c2da_fresh36 : uint8 = c2da_mem[c2da_fresh35]
            c2da_mem[c2da_fresh34] = c2da_fresh36
        }
    }
    return
}
[export, sideeffects]
def R_TextureAnimation(var base : int) : int {
    var reletive : int
    var count : int
    if (int(uint(c2da_mem[currententity + 152]) | uint(c2da_mem[currententity + 153]) << 0x8 | uint(c2da_mem[currententity + 154]) << 0x10 | uint(c2da_mem[currententity + 155]) << 0x18) != 0) {
        if (int(uint(c2da_mem[base + 48]) | uint(c2da_mem[base + 49]) << 0x8 | uint(c2da_mem[base + 50]) << 0x10 | uint(c2da_mem[base + 51]) << 0x18) != 0) {
            base = int(uint(c2da_mem[base + 48]) | uint(c2da_mem[base + 49]) << 0x8 | uint(c2da_mem[base + 50]) << 0x10 | uint(c2da_mem[base + 51]) << 0x18)
        }
    }
    if (int(uint(c2da_mem[base + 24]) | uint(c2da_mem[base + 25]) << 0x8 | uint(c2da_mem[base + 26]) << 0x10 | uint(c2da_mem[base + 27]) << 0x18) == 0) {
        return base
    }
    reletive = int(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) * 10.0lf) % int(uint(c2da_mem[base + 24]) | uint(c2da_mem[base + 25]) << 0x8 | uint(c2da_mem[base + 26]) << 0x10 | uint(c2da_mem[base + 27]) << 0x18)
    count = 0
    while (int(uint(c2da_mem[base + 28]) | uint(c2da_mem[base + 29]) << 0x8 | uint(c2da_mem[base + 30]) << 0x10 | uint(c2da_mem[base + 31]) << 0x18) > reletive || int(uint(c2da_mem[base + 32]) | uint(c2da_mem[base + 33]) << 0x8 | uint(c2da_mem[base + 34]) << 0x10 | uint(c2da_mem[base + 35]) << 0x18) <= reletive) {
        base = int(uint(c2da_mem[base + 40]) | uint(c2da_mem[base + 41]) << 0x8 | uint(c2da_mem[base + 42]) << 0x10 | uint(c2da_mem[base + 43]) << 0x18)
        if (base == 0) {
            Sys_Error(734562, [])
        }
        count++
        if (count > 100) {
            Sys_Error(734595, [])
        }
    }
    return base
}
var sourcesstep : int = default<int>

var lightdelta : int = default<int>

var lightdeltastep : int = default<int>


// This unit's static data, at heap offset 734544.
let private c2da_lin_static_r_surf_seg = fixed_array<int>(734544, 85)
let private c2da_lin_static_r_surf = fixed_array<uint64>(0x206e776f6e6b6e55ul, 0x70797420656c6974ul, 0x747865545f520065ul, 0x616d696e41657275ul, 0x7262203a6e6f6974ul, 0x637963206e656b6ful, 0x7865545f5200656cul, 0x6d696e4165727574ul, 0x69203a6e6f697461ul, 0x206574696e69666eul, 0x656c637963ul)

[init]
def private c2da_lin_init_static_r_surf() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_surf_seg[s * 2]
        for (k in range(c2da_lin_static_r_surf_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_surf[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_r_surf() {
    if (length(c2da_fn_table0) < 215) {
        resize(c2da_fn_table0, 215)
    }
    c2da_fn_table0[214] = @@R_DrawSurfaceBlock8_mip3
    c2da_fn_table0[213] = @@R_DrawSurfaceBlock8_mip2
    c2da_fn_table0[212] = @@R_DrawSurfaceBlock8_mip1
    c2da_fn_table0[211] = @@R_DrawSurfaceBlock8_mip0
}

[init]
def private c2da_lin_relink_init_r_surf() {
    c2da_relink_r_surf()
}
