[export, sideeffects]
def D_DrawPoly() {
    return
}
[export, sideeffects]
def D_DrawSurfaces() {
    let c2da_saved_sp : int = c2da_lin_sp
    D_DrawSurfaces_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def D_CalcGradients(var pface_0 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    D_CalcGradients_c2da_frame(pface_0, c2da_lin_enter(48))
    c2da_lin_sp = c2da_saved_sp
}
var private miplevel : int = default<int>

var scale_for_mip : float = default<float>

[export, sideeffects]
def D_MipLevelForScale(var scale : float) : int {
    var lmiplevel : int
    if (scale >= d_scalemip[0]) {
        lmiplevel = 0
    } elif (scale >= d_scalemip[1]) {
        lmiplevel = 1
    } elif (scale >= d_scalemip[2]) {
        lmiplevel = 2
    } else {
        lmiplevel = 3
    }
    if (lmiplevel < d_minmip) {
        lmiplevel = d_minmip
    }
    return lmiplevel
}
[export, sideeffects]
def D_DrawSolidSurface(var surf : int; var color : int) {
    var span : int
    var pdest : int
    var u : int
    var u2 : int
    var pix : int = color << 24 | color << 16 | color << 8 | color
    span = int(uint(c2da_mem[surf + 16]) | uint(c2da_mem[surf + 17]) << 0x8 | uint(c2da_mem[surf + 18]) << 0x10 | uint(c2da_mem[surf + 19]) << 0x18)
    while (span != 0) {
        pdest = d_viewbuffer + int(screenwidth * int(uint(c2da_mem[span + 4]) | uint(c2da_mem[span + 5]) << 0x8 | uint(c2da_mem[span + 6]) << 0x10 | uint(c2da_mem[span + 7]) << 0x18))
        let c2da_fresh88 : int = int(uint(c2da_mem[span]) | uint(c2da_mem[span + 1]) << 0x8 | uint(c2da_mem[span + 2]) << 0x10 | uint(c2da_mem[span + 3]) << 0x18)
        u = c2da_fresh88
        u2 = c2da_fresh88 + int(uint(c2da_mem[span + 8]) | uint(c2da_mem[span + 9]) << 0x8 | uint(c2da_mem[span + 10]) << 0x10 | uint(c2da_mem[span + 11]) << 0x18) - 1
        let c2da_fresh83 : uint8 = uint8(pix)
        c2da_mem[pdest + u] = c2da_fresh83
        if (u2 - u < 8) {
            u++
            while (u <= u2) {
                let c2da_fresh84 : uint8 = uint8(pix)
                c2da_mem[pdest + u] = c2da_fresh84
                u++
            }
        } else {
            u++
            while ((u & 3) != 0) {
                let c2da_fresh85 : uint8 = uint8(pix)
                c2da_mem[pdest + u] = c2da_fresh85
                u++
            }
            u2 -= 4
            while (u <= u2) {
                let c2da_fresh86 : uint = uint(pix)
                c2da_mem[pdest + u] = uint8(c2da_fresh86)
                c2da_mem[pdest + u + 1] = uint8(c2da_fresh86 >> 0x8)
                c2da_mem[pdest + u + 2] = uint8(c2da_fresh86 >> 0x10)
                c2da_mem[pdest + u + 3] = uint8(c2da_fresh86 >> 0x18)
                u += 4
            }
            u2 += 4
            while (u <= u2) {
                let c2da_fresh87 : uint8 = uint8(pix)
                c2da_mem[pdest + u] = c2da_fresh87
                u++
            }
        }
        span = int(uint(c2da_mem[span + 16]) | uint(c2da_mem[span + 17]) << 0x8 | uint(c2da_mem[span + 18]) << 0x10 | uint(c2da_mem[span + 19]) << 0x18)
    }
    return
}
var errorterm : int = default<int>

var erroradjustdown : int = default<int>

var vstartscan : int = default<int>

[sideeffects]
def private D_DrawSurfaces_c2da_frame(c2da_fp : int) {
    var s : int
    var pface : int
    var pcurrentcache : int
    var world_transformed_modelorg : vec3_t
    currententity = 10048 + 0 * 200
    TransformVector(204240, 204256)
    world_transformed_modelorg[0] = uint_bits_to_float(uint(c2da_mem[204256 + 0 * 4]) | uint(c2da_mem[204256 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204256 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204256 + 0 * 4 + 3]) << 0x18)
    world_transformed_modelorg[1] = uint_bits_to_float(uint(c2da_mem[204256 + 1 * 4]) | uint(c2da_mem[204256 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204256 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204256 + 1 * 4 + 3]) << 0x18)
    world_transformed_modelorg[2] = uint_bits_to_float(uint(c2da_mem[204256 + 2 * 4]) | uint(c2da_mem[204256 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204256 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204256 + 2 * 4 + 3]) << 0x18)
    if (uint_bits_to_float(uint(c2da_mem[392136]) | uint(c2da_mem[392137]) << 0x8 | uint(c2da_mem[392138]) << 0x10 | uint(c2da_mem[392139]) << 0x18) != 0.0) {
        s = surfaces + 1 * 88
        while (s < surface_p) {
            if (int(uint(c2da_mem[s + 16]) | uint(c2da_mem[s + 17]) << 0x8 | uint(c2da_mem[s + 18]) << 0x10 | uint(c2da_mem[s + 19]) << 0x18) == 0) {
                s += 88
                continue
            }
            d_zistepu = uint_bits_to_float(uint(c2da_mem[s + 68]) | uint(c2da_mem[s + 69]) << 0x8 | uint(c2da_mem[s + 70]) << 0x10 | uint(c2da_mem[s + 71]) << 0x18)
            d_zistepv = uint_bits_to_float(uint(c2da_mem[s + 72]) | uint(c2da_mem[s + 73]) << 0x8 | uint(c2da_mem[s + 74]) << 0x10 | uint(c2da_mem[s + 75]) << 0x18)
            d_ziorigin = uint_bits_to_float(uint(c2da_mem[s + 64]) | uint(c2da_mem[s + 65]) << 0x8 | uint(c2da_mem[s + 66]) << 0x10 | uint(c2da_mem[s + 67]) << 0x18)
            D_DrawSolidSurface(s, int(int64(int(uint(c2da_mem[s + 40]) | uint(c2da_mem[s + 41]) << 0x8 | uint(c2da_mem[s + 42]) << 0x10 | uint(c2da_mem[s + 43]) << 0x18)) & 255l))
            D_DrawZSpans(int(uint(c2da_mem[s + 16]) | uint(c2da_mem[s + 17]) << 0x8 | uint(c2da_mem[s + 18]) << 0x10 | uint(c2da_mem[s + 19]) << 0x18))
            s += 88
        }
    } else {
        s = surfaces + 1 * 88
        while (s < surface_p) {
            if (int(uint(c2da_mem[s + 16]) | uint(c2da_mem[s + 17]) << 0x8 | uint(c2da_mem[s + 18]) << 0x10 | uint(c2da_mem[s + 19]) << 0x18) == 0) {
                s += 88
                continue
            }
            r_drawnpolycount = r_drawnpolycount + 1
            d_zistepu = uint_bits_to_float(uint(c2da_mem[s + 68]) | uint(c2da_mem[s + 69]) << 0x8 | uint(c2da_mem[s + 70]) << 0x10 | uint(c2da_mem[s + 71]) << 0x18)
            d_zistepv = uint_bits_to_float(uint(c2da_mem[s + 72]) | uint(c2da_mem[s + 73]) << 0x8 | uint(c2da_mem[s + 74]) << 0x10 | uint(c2da_mem[s + 75]) << 0x18)
            d_ziorigin = uint_bits_to_float(uint(c2da_mem[s + 64]) | uint(c2da_mem[s + 65]) << 0x8 | uint(c2da_mem[s + 66]) << 0x10 | uint(c2da_mem[s + 67]) << 0x18)
            if ((int(uint(c2da_mem[s + 36]) | uint(c2da_mem[s + 37]) << 0x8 | uint(c2da_mem[s + 38]) << 0x10 | uint(c2da_mem[s + 39]) << 0x18) & 4) != 0) {
                if (r_skymade == 0) {
                    R_MakeSky()
                }
                D_DrawSkyScans8(int(uint(c2da_mem[s + 16]) | uint(c2da_mem[s + 17]) << 0x8 | uint(c2da_mem[s + 18]) << 0x10 | uint(c2da_mem[s + 19]) << 0x18))
                D_DrawZSpans(int(uint(c2da_mem[s + 16]) | uint(c2da_mem[s + 17]) << 0x8 | uint(c2da_mem[s + 18]) << 0x10 | uint(c2da_mem[s + 19]) << 0x18))
            } elif ((int(uint(c2da_mem[s + 36]) | uint(c2da_mem[s + 37]) << 0x8 | uint(c2da_mem[s + 38]) << 0x10 | uint(c2da_mem[s + 39]) << 0x18) & 64) != 0) {
                d_zistepu = 0.0
                d_zistepv = 0.0
                d_ziorigin = float(-0.9lf)
                D_DrawSolidSurface(s, int(uint_bits_to_float(uint(c2da_mem[392232]) | uint(c2da_mem[392233]) << 0x8 | uint(c2da_mem[392234]) << 0x10 | uint(c2da_mem[392235]) << 0x18)) & 255)
                D_DrawZSpans(int(uint(c2da_mem[s + 16]) | uint(c2da_mem[s + 17]) << 0x8 | uint(c2da_mem[s + 18]) << 0x10 | uint(c2da_mem[s + 19]) << 0x18))
            } elif ((int(uint(c2da_mem[s + 36]) | uint(c2da_mem[s + 37]) << 0x8 | uint(c2da_mem[s + 38]) << 0x10 | uint(c2da_mem[s + 39]) << 0x18) & 16) != 0) {
                pface = int(uint(c2da_mem[s + 40]) | uint(c2da_mem[s + 41]) << 0x8 | uint(c2da_mem[s + 42]) << 0x10 | uint(c2da_mem[s + 43]) << 0x18)
                miplevel = 0
                let c2da_fresh76 : int = int(uint(c2da_mem[pface + 80]) | uint(c2da_mem[pface + 81]) << 0x8 | uint(c2da_mem[pface + 82]) << 0x10 | uint(c2da_mem[pface + 83]) << 0x18)
                let c2da_fresh0 : int = c2da_fresh76 + 40
                let c2da_fresh1 : int = c2da_fresh76 + 40
                let c2da_fresh2 : int = int(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh1 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh1 + 3]) << 0x18) + 56 + 0 * 4
                cacheblock = int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18) + int(uint(c2da_mem[c2da_fresh2]) | uint(c2da_mem[c2da_fresh2 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh2 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh2 + 3]) << 0x18)
                cachewidth = 64
                if ((uint(c2da_mem[s + 60]) | uint(c2da_mem[s + 61]) << 0x8 | uint(c2da_mem[s + 62]) << 0x10 | uint(c2da_mem[s + 63]) << 0x18) != 0u) {
                    currententity = int(uint(c2da_mem[s + 48]) | uint(c2da_mem[s + 49]) << 0x8 | uint(c2da_mem[s + 50]) << 0x10 | uint(c2da_mem[s + 51]) << 0x18)
                    let c2da_fresh3 : float = uint_bits_to_float(uint(c2da_mem[244112 + 0 * 4]) | uint(c2da_mem[244112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[currententity + 88 + 0 * 4]) | uint(c2da_mem[currententity + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 0 * 4 + 3]) << 0x18)
                    let c2da_fresh4 : uint = float_bits_to_uint(c2da_fresh3)
                    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh4)
                    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh4 >> 0x8)
                    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh4 >> 0x10)
                    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh4 >> 0x18)
                    let c2da_fresh5 : float = uint_bits_to_float(uint(c2da_mem[244112 + 1 * 4]) | uint(c2da_mem[244112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[currententity + 88 + 1 * 4]) | uint(c2da_mem[currententity + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 1 * 4 + 3]) << 0x18)
                    let c2da_fresh6 : uint = float_bits_to_uint(c2da_fresh5)
                    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh6)
                    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh6 >> 0x8)
                    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh6 >> 0x10)
                    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh6 >> 0x18)
                    let c2da_fresh7 : float = uint_bits_to_float(uint(c2da_mem[244112 + 2 * 4]) | uint(c2da_mem[244112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[currententity + 88 + 2 * 4]) | uint(c2da_mem[currententity + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 2 * 4 + 3]) << 0x18)
                    let c2da_fresh8 : uint = float_bits_to_uint(c2da_fresh7)
                    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh8)
                    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh8 >> 0x8)
                    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh8 >> 0x10)
                    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh8 >> 0x18)
                    TransformVector(c2da_fp, 204256)
                    R_RotateBmodel()
                }
                D_CalcGradients(pface)
                Turbulent8(int(uint(c2da_mem[s + 16]) | uint(c2da_mem[s + 17]) << 0x8 | uint(c2da_mem[s + 18]) << 0x10 | uint(c2da_mem[s + 19]) << 0x18))
                D_DrawZSpans(int(uint(c2da_mem[s + 16]) | uint(c2da_mem[s + 17]) << 0x8 | uint(c2da_mem[s + 18]) << 0x10 | uint(c2da_mem[s + 19]) << 0x18))
                if ((uint(c2da_mem[s + 60]) | uint(c2da_mem[s + 61]) << 0x8 | uint(c2da_mem[s + 62]) << 0x10 | uint(c2da_mem[s + 63]) << 0x18) != 0u) {
                    currententity = 10048 + 0 * 200
                    let c2da_fresh9 : float = world_transformed_modelorg[0]
                    let c2da_fresh10 : uint = float_bits_to_uint(c2da_fresh9)
                    c2da_mem[204256 + 0 * 4] = uint8(c2da_fresh10)
                    c2da_mem[204256 + 0 * 4 + 1] = uint8(c2da_fresh10 >> 0x8)
                    c2da_mem[204256 + 0 * 4 + 2] = uint8(c2da_fresh10 >> 0x10)
                    c2da_mem[204256 + 0 * 4 + 3] = uint8(c2da_fresh10 >> 0x18)
                    let c2da_fresh11 : float = world_transformed_modelorg[1]
                    let c2da_fresh12 : uint = float_bits_to_uint(c2da_fresh11)
                    c2da_mem[204256 + 1 * 4] = uint8(c2da_fresh12)
                    c2da_mem[204256 + 1 * 4 + 1] = uint8(c2da_fresh12 >> 0x8)
                    c2da_mem[204256 + 1 * 4 + 2] = uint8(c2da_fresh12 >> 0x10)
                    c2da_mem[204256 + 1 * 4 + 3] = uint8(c2da_fresh12 >> 0x18)
                    let c2da_fresh13 : float = world_transformed_modelorg[2]
                    let c2da_fresh14 : uint = float_bits_to_uint(c2da_fresh13)
                    c2da_mem[204256 + 2 * 4] = uint8(c2da_fresh14)
                    c2da_mem[204256 + 2 * 4 + 1] = uint8(c2da_fresh14 >> 0x8)
                    c2da_mem[204256 + 2 * 4 + 2] = uint8(c2da_fresh14 >> 0x10)
                    c2da_mem[204256 + 2 * 4 + 3] = uint8(c2da_fresh14 >> 0x18)
                    let c2da_fresh15 : float = base_vpn[0]
                    let c2da_fresh16 : uint = float_bits_to_uint(c2da_fresh15)
                    c2da_mem[244128 + 0 * 4] = uint8(c2da_fresh16)
                    c2da_mem[244128 + 0 * 4 + 1] = uint8(c2da_fresh16 >> 0x8)
                    c2da_mem[244128 + 0 * 4 + 2] = uint8(c2da_fresh16 >> 0x10)
                    c2da_mem[244128 + 0 * 4 + 3] = uint8(c2da_fresh16 >> 0x18)
                    let c2da_fresh17 : float = base_vpn[1]
                    let c2da_fresh18 : uint = float_bits_to_uint(c2da_fresh17)
                    c2da_mem[244128 + 1 * 4] = uint8(c2da_fresh18)
                    c2da_mem[244128 + 1 * 4 + 1] = uint8(c2da_fresh18 >> 0x8)
                    c2da_mem[244128 + 1 * 4 + 2] = uint8(c2da_fresh18 >> 0x10)
                    c2da_mem[244128 + 1 * 4 + 3] = uint8(c2da_fresh18 >> 0x18)
                    let c2da_fresh19 : float = base_vpn[2]
                    let c2da_fresh20 : uint = float_bits_to_uint(c2da_fresh19)
                    c2da_mem[244128 + 2 * 4] = uint8(c2da_fresh20)
                    c2da_mem[244128 + 2 * 4 + 1] = uint8(c2da_fresh20 >> 0x8)
                    c2da_mem[244128 + 2 * 4 + 2] = uint8(c2da_fresh20 >> 0x10)
                    c2da_mem[244128 + 2 * 4 + 3] = uint8(c2da_fresh20 >> 0x18)
                    let c2da_fresh21 : float = base_vup[0]
                    let c2da_fresh22 : uint = float_bits_to_uint(c2da_fresh21)
                    c2da_mem[244160 + 0 * 4] = uint8(c2da_fresh22)
                    c2da_mem[244160 + 0 * 4 + 1] = uint8(c2da_fresh22 >> 0x8)
                    c2da_mem[244160 + 0 * 4 + 2] = uint8(c2da_fresh22 >> 0x10)
                    c2da_mem[244160 + 0 * 4 + 3] = uint8(c2da_fresh22 >> 0x18)
                    let c2da_fresh23 : float = base_vup[1]
                    let c2da_fresh24 : uint = float_bits_to_uint(c2da_fresh23)
                    c2da_mem[244160 + 1 * 4] = uint8(c2da_fresh24)
                    c2da_mem[244160 + 1 * 4 + 1] = uint8(c2da_fresh24 >> 0x8)
                    c2da_mem[244160 + 1 * 4 + 2] = uint8(c2da_fresh24 >> 0x10)
                    c2da_mem[244160 + 1 * 4 + 3] = uint8(c2da_fresh24 >> 0x18)
                    let c2da_fresh25 : float = base_vup[2]
                    let c2da_fresh26 : uint = float_bits_to_uint(c2da_fresh25)
                    c2da_mem[244160 + 2 * 4] = uint8(c2da_fresh26)
                    c2da_mem[244160 + 2 * 4 + 1] = uint8(c2da_fresh26 >> 0x8)
                    c2da_mem[244160 + 2 * 4 + 2] = uint8(c2da_fresh26 >> 0x10)
                    c2da_mem[244160 + 2 * 4 + 3] = uint8(c2da_fresh26 >> 0x18)
                    let c2da_fresh27 : float = base_vright[0]
                    let c2da_fresh28 : uint = float_bits_to_uint(c2da_fresh27)
                    c2da_mem[244144 + 0 * 4] = uint8(c2da_fresh28)
                    c2da_mem[244144 + 0 * 4 + 1] = uint8(c2da_fresh28 >> 0x8)
                    c2da_mem[244144 + 0 * 4 + 2] = uint8(c2da_fresh28 >> 0x10)
                    c2da_mem[244144 + 0 * 4 + 3] = uint8(c2da_fresh28 >> 0x18)
                    let c2da_fresh29 : float = base_vright[1]
                    let c2da_fresh30 : uint = float_bits_to_uint(c2da_fresh29)
                    c2da_mem[244144 + 1 * 4] = uint8(c2da_fresh30)
                    c2da_mem[244144 + 1 * 4 + 1] = uint8(c2da_fresh30 >> 0x8)
                    c2da_mem[244144 + 1 * 4 + 2] = uint8(c2da_fresh30 >> 0x10)
                    c2da_mem[244144 + 1 * 4 + 3] = uint8(c2da_fresh30 >> 0x18)
                    let c2da_fresh31 : float = base_vright[2]
                    let c2da_fresh32 : uint = float_bits_to_uint(c2da_fresh31)
                    c2da_mem[244144 + 2 * 4] = uint8(c2da_fresh32)
                    c2da_mem[244144 + 2 * 4 + 1] = uint8(c2da_fresh32 >> 0x8)
                    c2da_mem[244144 + 2 * 4 + 2] = uint8(c2da_fresh32 >> 0x10)
                    c2da_mem[244144 + 2 * 4 + 3] = uint8(c2da_fresh32 >> 0x18)
                    let c2da_fresh33 : float = base_modelorg[0]
                    let c2da_fresh34 : uint = float_bits_to_uint(c2da_fresh33)
                    c2da_mem[204240 + 0 * 4] = uint8(c2da_fresh34)
                    c2da_mem[204240 + 0 * 4 + 1] = uint8(c2da_fresh34 >> 0x8)
                    c2da_mem[204240 + 0 * 4 + 2] = uint8(c2da_fresh34 >> 0x10)
                    c2da_mem[204240 + 0 * 4 + 3] = uint8(c2da_fresh34 >> 0x18)
                    let c2da_fresh35 : float = base_modelorg[1]
                    let c2da_fresh36 : uint = float_bits_to_uint(c2da_fresh35)
                    c2da_mem[204240 + 1 * 4] = uint8(c2da_fresh36)
                    c2da_mem[204240 + 1 * 4 + 1] = uint8(c2da_fresh36 >> 0x8)
                    c2da_mem[204240 + 1 * 4 + 2] = uint8(c2da_fresh36 >> 0x10)
                    c2da_mem[204240 + 1 * 4 + 3] = uint8(c2da_fresh36 >> 0x18)
                    let c2da_fresh37 : float = base_modelorg[2]
                    let c2da_fresh38 : uint = float_bits_to_uint(c2da_fresh37)
                    c2da_mem[204240 + 2 * 4] = uint8(c2da_fresh38)
                    c2da_mem[204240 + 2 * 4 + 1] = uint8(c2da_fresh38 >> 0x8)
                    c2da_mem[204240 + 2 * 4 + 2] = uint8(c2da_fresh38 >> 0x10)
                    c2da_mem[204240 + 2 * 4 + 3] = uint8(c2da_fresh38 >> 0x18)
                    R_TransformFrustum()
                }
            } else {
                if ((uint(c2da_mem[s + 60]) | uint(c2da_mem[s + 61]) << 0x8 | uint(c2da_mem[s + 62]) << 0x10 | uint(c2da_mem[s + 63]) << 0x18) != 0u) {
                    currententity = int(uint(c2da_mem[s + 48]) | uint(c2da_mem[s + 49]) << 0x8 | uint(c2da_mem[s + 50]) << 0x10 | uint(c2da_mem[s + 51]) << 0x18)
                    let c2da_fresh39 : float = uint_bits_to_float(uint(c2da_mem[244112 + 0 * 4]) | uint(c2da_mem[244112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[currententity + 88 + 0 * 4]) | uint(c2da_mem[currententity + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 0 * 4 + 3]) << 0x18)
                    let c2da_fresh40 : uint = float_bits_to_uint(c2da_fresh39)
                    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh40)
                    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh40 >> 0x8)
                    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh40 >> 0x10)
                    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh40 >> 0x18)
                    let c2da_fresh41 : float = uint_bits_to_float(uint(c2da_mem[244112 + 1 * 4]) | uint(c2da_mem[244112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[currententity + 88 + 1 * 4]) | uint(c2da_mem[currententity + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 1 * 4 + 3]) << 0x18)
                    let c2da_fresh42 : uint = float_bits_to_uint(c2da_fresh41)
                    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh42)
                    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh42 >> 0x8)
                    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh42 >> 0x10)
                    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh42 >> 0x18)
                    let c2da_fresh43 : float = uint_bits_to_float(uint(c2da_mem[244112 + 2 * 4]) | uint(c2da_mem[244112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[currententity + 88 + 2 * 4]) | uint(c2da_mem[currententity + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 2 * 4 + 3]) << 0x18)
                    let c2da_fresh44 : uint = float_bits_to_uint(c2da_fresh43)
                    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh44)
                    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh44 >> 0x8)
                    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh44 >> 0x10)
                    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh44 >> 0x18)
                    TransformVector(c2da_fp, 204256)
                    R_RotateBmodel()
                }
                pface = int(uint(c2da_mem[s + 40]) | uint(c2da_mem[s + 41]) << 0x8 | uint(c2da_mem[s + 42]) << 0x10 | uint(c2da_mem[s + 43]) << 0x18)
                let c2da_fresh45 : int = int(uint(c2da_mem[pface + 80]) | uint(c2da_mem[pface + 81]) << 0x8 | uint(c2da_mem[pface + 82]) << 0x10 | uint(c2da_mem[pface + 83]) << 0x18) + 32
                miplevel = D_MipLevelForScale(uint_bits_to_float(uint(c2da_mem[s + 56]) | uint(c2da_mem[s + 57]) << 0x8 | uint(c2da_mem[s + 58]) << 0x10 | uint(c2da_mem[s + 59]) << 0x18) * scale_for_mip * uint_bits_to_float(uint(c2da_mem[c2da_fresh45]) | uint(c2da_mem[c2da_fresh45 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh45 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh45 + 3]) << 0x18))
                pcurrentcache = D_CacheSurface(pface, miplevel)
                cacheblock = pcurrentcache + 64
                cachewidth = int(uint(c2da_mem[pcurrentcache + 40]) | uint(c2da_mem[pcurrentcache + 41]) << 0x8 | uint(c2da_mem[pcurrentcache + 42]) << 0x10 | uint(c2da_mem[pcurrentcache + 43]) << 0x18)
                D_CalcGradients(pface)
                invoke(c2da_fn_table5[d_drawspans], int(uint(c2da_mem[s + 16]) | uint(c2da_mem[s + 17]) << 0x8 | uint(c2da_mem[s + 18]) << 0x10 | uint(c2da_mem[s + 19]) << 0x18))
                D_DrawZSpans(int(uint(c2da_mem[s + 16]) | uint(c2da_mem[s + 17]) << 0x8 | uint(c2da_mem[s + 18]) << 0x10 | uint(c2da_mem[s + 19]) << 0x18))
                if ((uint(c2da_mem[s + 60]) | uint(c2da_mem[s + 61]) << 0x8 | uint(c2da_mem[s + 62]) << 0x10 | uint(c2da_mem[s + 63]) << 0x18) != 0u) {
                    currententity = 10048 + 0 * 200
                    let c2da_fresh46 : float = world_transformed_modelorg[0]
                    let c2da_fresh47 : uint = float_bits_to_uint(c2da_fresh46)
                    c2da_mem[204256 + 0 * 4] = uint8(c2da_fresh47)
                    c2da_mem[204256 + 0 * 4 + 1] = uint8(c2da_fresh47 >> 0x8)
                    c2da_mem[204256 + 0 * 4 + 2] = uint8(c2da_fresh47 >> 0x10)
                    c2da_mem[204256 + 0 * 4 + 3] = uint8(c2da_fresh47 >> 0x18)
                    let c2da_fresh48 : float = world_transformed_modelorg[1]
                    let c2da_fresh49 : uint = float_bits_to_uint(c2da_fresh48)
                    c2da_mem[204256 + 1 * 4] = uint8(c2da_fresh49)
                    c2da_mem[204256 + 1 * 4 + 1] = uint8(c2da_fresh49 >> 0x8)
                    c2da_mem[204256 + 1 * 4 + 2] = uint8(c2da_fresh49 >> 0x10)
                    c2da_mem[204256 + 1 * 4 + 3] = uint8(c2da_fresh49 >> 0x18)
                    let c2da_fresh50 : float = world_transformed_modelorg[2]
                    let c2da_fresh51 : uint = float_bits_to_uint(c2da_fresh50)
                    c2da_mem[204256 + 2 * 4] = uint8(c2da_fresh51)
                    c2da_mem[204256 + 2 * 4 + 1] = uint8(c2da_fresh51 >> 0x8)
                    c2da_mem[204256 + 2 * 4 + 2] = uint8(c2da_fresh51 >> 0x10)
                    c2da_mem[204256 + 2 * 4 + 3] = uint8(c2da_fresh51 >> 0x18)
                    let c2da_fresh52 : float = base_vpn[0]
                    let c2da_fresh53 : uint = float_bits_to_uint(c2da_fresh52)
                    c2da_mem[244128 + 0 * 4] = uint8(c2da_fresh53)
                    c2da_mem[244128 + 0 * 4 + 1] = uint8(c2da_fresh53 >> 0x8)
                    c2da_mem[244128 + 0 * 4 + 2] = uint8(c2da_fresh53 >> 0x10)
                    c2da_mem[244128 + 0 * 4 + 3] = uint8(c2da_fresh53 >> 0x18)
                    let c2da_fresh54 : float = base_vpn[1]
                    let c2da_fresh55 : uint = float_bits_to_uint(c2da_fresh54)
                    c2da_mem[244128 + 1 * 4] = uint8(c2da_fresh55)
                    c2da_mem[244128 + 1 * 4 + 1] = uint8(c2da_fresh55 >> 0x8)
                    c2da_mem[244128 + 1 * 4 + 2] = uint8(c2da_fresh55 >> 0x10)
                    c2da_mem[244128 + 1 * 4 + 3] = uint8(c2da_fresh55 >> 0x18)
                    let c2da_fresh56 : float = base_vpn[2]
                    let c2da_fresh57 : uint = float_bits_to_uint(c2da_fresh56)
                    c2da_mem[244128 + 2 * 4] = uint8(c2da_fresh57)
                    c2da_mem[244128 + 2 * 4 + 1] = uint8(c2da_fresh57 >> 0x8)
                    c2da_mem[244128 + 2 * 4 + 2] = uint8(c2da_fresh57 >> 0x10)
                    c2da_mem[244128 + 2 * 4 + 3] = uint8(c2da_fresh57 >> 0x18)
                    let c2da_fresh58 : float = base_vup[0]
                    let c2da_fresh59 : uint = float_bits_to_uint(c2da_fresh58)
                    c2da_mem[244160 + 0 * 4] = uint8(c2da_fresh59)
                    c2da_mem[244160 + 0 * 4 + 1] = uint8(c2da_fresh59 >> 0x8)
                    c2da_mem[244160 + 0 * 4 + 2] = uint8(c2da_fresh59 >> 0x10)
                    c2da_mem[244160 + 0 * 4 + 3] = uint8(c2da_fresh59 >> 0x18)
                    let c2da_fresh60 : float = base_vup[1]
                    let c2da_fresh61 : uint = float_bits_to_uint(c2da_fresh60)
                    c2da_mem[244160 + 1 * 4] = uint8(c2da_fresh61)
                    c2da_mem[244160 + 1 * 4 + 1] = uint8(c2da_fresh61 >> 0x8)
                    c2da_mem[244160 + 1 * 4 + 2] = uint8(c2da_fresh61 >> 0x10)
                    c2da_mem[244160 + 1 * 4 + 3] = uint8(c2da_fresh61 >> 0x18)
                    let c2da_fresh62 : float = base_vup[2]
                    let c2da_fresh63 : uint = float_bits_to_uint(c2da_fresh62)
                    c2da_mem[244160 + 2 * 4] = uint8(c2da_fresh63)
                    c2da_mem[244160 + 2 * 4 + 1] = uint8(c2da_fresh63 >> 0x8)
                    c2da_mem[244160 + 2 * 4 + 2] = uint8(c2da_fresh63 >> 0x10)
                    c2da_mem[244160 + 2 * 4 + 3] = uint8(c2da_fresh63 >> 0x18)
                    let c2da_fresh64 : float = base_vright[0]
                    let c2da_fresh65 : uint = float_bits_to_uint(c2da_fresh64)
                    c2da_mem[244144 + 0 * 4] = uint8(c2da_fresh65)
                    c2da_mem[244144 + 0 * 4 + 1] = uint8(c2da_fresh65 >> 0x8)
                    c2da_mem[244144 + 0 * 4 + 2] = uint8(c2da_fresh65 >> 0x10)
                    c2da_mem[244144 + 0 * 4 + 3] = uint8(c2da_fresh65 >> 0x18)
                    let c2da_fresh66 : float = base_vright[1]
                    let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
                    c2da_mem[244144 + 1 * 4] = uint8(c2da_fresh67)
                    c2da_mem[244144 + 1 * 4 + 1] = uint8(c2da_fresh67 >> 0x8)
                    c2da_mem[244144 + 1 * 4 + 2] = uint8(c2da_fresh67 >> 0x10)
                    c2da_mem[244144 + 1 * 4 + 3] = uint8(c2da_fresh67 >> 0x18)
                    let c2da_fresh68 : float = base_vright[2]
                    let c2da_fresh69 : uint = float_bits_to_uint(c2da_fresh68)
                    c2da_mem[244144 + 2 * 4] = uint8(c2da_fresh69)
                    c2da_mem[244144 + 2 * 4 + 1] = uint8(c2da_fresh69 >> 0x8)
                    c2da_mem[244144 + 2 * 4 + 2] = uint8(c2da_fresh69 >> 0x10)
                    c2da_mem[244144 + 2 * 4 + 3] = uint8(c2da_fresh69 >> 0x18)
                    let c2da_fresh70 : float = base_modelorg[0]
                    let c2da_fresh71 : uint = float_bits_to_uint(c2da_fresh70)
                    c2da_mem[204240 + 0 * 4] = uint8(c2da_fresh71)
                    c2da_mem[204240 + 0 * 4 + 1] = uint8(c2da_fresh71 >> 0x8)
                    c2da_mem[204240 + 0 * 4 + 2] = uint8(c2da_fresh71 >> 0x10)
                    c2da_mem[204240 + 0 * 4 + 3] = uint8(c2da_fresh71 >> 0x18)
                    let c2da_fresh72 : float = base_modelorg[1]
                    let c2da_fresh73 : uint = float_bits_to_uint(c2da_fresh72)
                    c2da_mem[204240 + 1 * 4] = uint8(c2da_fresh73)
                    c2da_mem[204240 + 1 * 4 + 1] = uint8(c2da_fresh73 >> 0x8)
                    c2da_mem[204240 + 1 * 4 + 2] = uint8(c2da_fresh73 >> 0x10)
                    c2da_mem[204240 + 1 * 4 + 3] = uint8(c2da_fresh73 >> 0x18)
                    let c2da_fresh74 : float = base_modelorg[2]
                    let c2da_fresh75 : uint = float_bits_to_uint(c2da_fresh74)
                    c2da_mem[204240 + 2 * 4] = uint8(c2da_fresh75)
                    c2da_mem[204240 + 2 * 4 + 1] = uint8(c2da_fresh75 >> 0x8)
                    c2da_mem[204240 + 2 * 4 + 2] = uint8(c2da_fresh75 >> 0x10)
                    c2da_mem[204240 + 2 * 4 + 3] = uint8(c2da_fresh75 >> 0x18)
                    R_TransformFrustum()
                }
            }
            s += 88
        }
    }
    return
}
[sideeffects]
def private D_CalcGradients_c2da_frame(var pface_0 : int; c2da_fp : int) {
    var pplane : int
    var mipscale : float
    var t : float
    pplane = int(uint(c2da_mem[pface_0 + 16]) | uint(c2da_mem[pface_0 + 17]) << 0x8 | uint(c2da_mem[pface_0 + 18]) << 0x10 | uint(c2da_mem[pface_0 + 19]) << 0x18)
    mipscale = float(1.0lf / double(float(1 << miplevel)))
    TransformVector(int(uint(c2da_mem[pface_0 + 80]) | uint(c2da_mem[pface_0 + 81]) << 0x8 | uint(c2da_mem[pface_0 + 82]) << 0x10 | uint(c2da_mem[pface_0 + 83]) << 0x18) + 0 * 16, c2da_fp)
    TransformVector(int(uint(c2da_mem[pface_0 + 80]) | uint(c2da_mem[pface_0 + 81]) << 0x8 | uint(c2da_mem[pface_0 + 82]) << 0x10 | uint(c2da_mem[pface_0 + 83]) << 0x18) + 1 * 16, c2da_fp + 16)
    t = xscaleinv * mipscale
    d_sdivzstepu = uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) * t
    d_tdivzstepu = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18) * t
    t = yscaleinv * mipscale
    d_sdivzstepv = -uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18) * t
    d_tdivzstepv = -uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18) * t
    d_sdivzorigin = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) * mipscale - xcenter * d_sdivzstepu - ycenter * d_sdivzstepv
    d_tdivzorigin = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18) * mipscale - xcenter * d_tdivzstepu - ycenter * d_tdivzstepv
    VectorScale(204256, mipscale, c2da_fp + 32)
    t = 65536.0 * mipscale
    let c2da_fresh79 : int = int(uint(c2da_mem[pface_0 + 80]) | uint(c2da_mem[pface_0 + 81]) << 0x8 | uint(c2da_mem[pface_0 + 82]) << 0x10 | uint(c2da_mem[pface_0 + 83]) << 0x18)
    let c2da_fresh77 : int = c2da_fresh79 + 0 * 16 + 3 * 4
    let c2da_fresh80 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 0 * 4]) | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh81 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 1 * 4]) | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh82 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 2 * 4]) | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 3]) << 0x18)
    sadjust = int(float(int(double((c2da_fresh80 * uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) + c2da_fresh81 * uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18) + c2da_fresh82 * uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)) * 65536.0) + 0.5lf) - (int(int16(uint(c2da_mem[pface_0 + 72 + 0 * 2]) | uint(c2da_mem[pface_0 + 72 + 0 * 2 + 1]) << 0x8)) << 16 >> miplevel)) + uint_bits_to_float(uint(c2da_mem[c2da_fresh77]) | uint(c2da_mem[c2da_fresh77 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh77 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh77 + 3]) << 0x18) * t)
    let c2da_fresh78 : int = c2da_fresh79 + 1 * 16 + 3 * 4
    tadjust = int(float(int(double((c2da_fresh80 * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18) + c2da_fresh81 * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18) + c2da_fresh82 * uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18)) * 65536.0) + 0.5lf) - (int(int16(uint(c2da_mem[pface_0 + 72 + 1 * 2]) | uint(c2da_mem[pface_0 + 72 + 1 * 2 + 1]) << 0x8)) << 16 >> miplevel)) + uint_bits_to_float(uint(c2da_mem[c2da_fresh78]) | uint(c2da_mem[c2da_fresh78 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh78 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh78 + 3]) << 0x18) * t)
    bbextents = (int(int16(uint(c2da_mem[pface_0 + 76 + 0 * 2]) | uint(c2da_mem[pface_0 + 76 + 0 * 2 + 1]) << 0x8)) << 16 >> miplevel) - 1
    bbextentt = (int(int16(uint(c2da_mem[pface_0 + 76 + 1 * 2]) | uint(c2da_mem[pface_0 + 76 + 1 * 2 + 1]) << 0x8)) << 16 >> miplevel) - 1
    return
}
