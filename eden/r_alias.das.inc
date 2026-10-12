var r_affinetridesc : affinetridesc_t = default<affinetridesc_t>

var acolormap : int = default<int>

[export, sideeffects]
def R_AliasDrawModel(var plighting : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_AliasDrawModel_c2da_frame(plighting, c2da_lin_enter(88032))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_AliasPreparePoints() {
    var i : int
    var pstverts : int
    var fv_0 : int
    var av : int
    var ptri : int
    var pfv : int[3]
    pstverts = paliashdr + int(uint(c2da_mem[paliashdr + 4]) | uint(c2da_mem[paliashdr + 5]) << 0x8 | uint(c2da_mem[paliashdr + 6]) << 0x10 | uint(c2da_mem[paliashdr + 7]) << 0x18)
    r_anumverts = int(uint(c2da_mem[pmdl + 60]) | uint(c2da_mem[pmdl + 61]) << 0x8 | uint(c2da_mem[pmdl + 62]) << 0x10 | uint(c2da_mem[pmdl + 63]) << 0x18)
    fv_0 = pfinalverts
    av = pauxverts
    i = 0
    while (i < r_anumverts) {
        R_AliasTransformFinalVert(fv_0, av, r_apverts, pstverts)
        if (uint_bits_to_float(uint(c2da_mem[av + 2 * 4]) | uint(c2da_mem[av + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[av + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[av + 2 * 4 + 3]) << 0x18) < 5.0) {
            let c2da_fresh0 : int = int(uint(c2da_mem[fv_0 + 24]) | uint(c2da_mem[fv_0 + 25]) << 0x8 | uint(c2da_mem[fv_0 + 26]) << 0x10 | uint(c2da_mem[fv_0 + 27]) << 0x18) | 16
            let c2da_fresh1 : uint = uint(c2da_fresh0)
            c2da_mem[fv_0 + 24] = uint8(c2da_fresh1)
            c2da_mem[fv_0 + 25] = uint8(c2da_fresh1 >> 0x8)
            c2da_mem[fv_0 + 26] = uint8(c2da_fresh1 >> 0x10)
            c2da_mem[fv_0 + 27] = uint8(c2da_fresh1 >> 0x18)
        } else {
            R_AliasProjectFinalVert(fv_0, av)
            if (int(uint(c2da_mem[fv_0 + 0 * 4]) | uint(c2da_mem[fv_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[fv_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[fv_0 + 0 * 4 + 3]) << 0x18) < int(uint(c2da_mem[5224]) | uint(c2da_mem[5225]) << 0x8 | uint(c2da_mem[5226]) << 0x10 | uint(c2da_mem[5227]) << 0x18)) {
                let c2da_fresh2 : int = int(uint(c2da_mem[fv_0 + 24]) | uint(c2da_mem[fv_0 + 25]) << 0x8 | uint(c2da_mem[fv_0 + 26]) << 0x10 | uint(c2da_mem[fv_0 + 27]) << 0x18) | 1
                let c2da_fresh3 : uint = uint(c2da_fresh2)
                c2da_mem[fv_0 + 24] = uint8(c2da_fresh3)
                c2da_mem[fv_0 + 25] = uint8(c2da_fresh3 >> 0x8)
                c2da_mem[fv_0 + 26] = uint8(c2da_fresh3 >> 0x10)
                c2da_mem[fv_0 + 27] = uint8(c2da_fresh3 >> 0x18)
            }
            if (int(uint(c2da_mem[fv_0 + 1 * 4]) | uint(c2da_mem[fv_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[fv_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[fv_0 + 1 * 4 + 3]) << 0x18) < int(uint(c2da_mem[5228]) | uint(c2da_mem[5229]) << 0x8 | uint(c2da_mem[5230]) << 0x10 | uint(c2da_mem[5231]) << 0x18)) {
                let c2da_fresh4 : int = int(uint(c2da_mem[fv_0 + 24]) | uint(c2da_mem[fv_0 + 25]) << 0x8 | uint(c2da_mem[fv_0 + 26]) << 0x10 | uint(c2da_mem[fv_0 + 27]) << 0x18) | 2
                let c2da_fresh5 : uint = uint(c2da_fresh4)
                c2da_mem[fv_0 + 24] = uint8(c2da_fresh5)
                c2da_mem[fv_0 + 25] = uint8(c2da_fresh5 >> 0x8)
                c2da_mem[fv_0 + 26] = uint8(c2da_fresh5 >> 0x10)
                c2da_mem[fv_0 + 27] = uint8(c2da_fresh5 >> 0x18)
            }
            if (int(uint(c2da_mem[fv_0 + 0 * 4]) | uint(c2da_mem[fv_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[fv_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[fv_0 + 0 * 4 + 3]) << 0x18) > int(uint(c2da_mem[5256]) | uint(c2da_mem[5257]) << 0x8 | uint(c2da_mem[5258]) << 0x10 | uint(c2da_mem[5259]) << 0x18)) {
                let c2da_fresh6 : int = int(uint(c2da_mem[fv_0 + 24]) | uint(c2da_mem[fv_0 + 25]) << 0x8 | uint(c2da_mem[fv_0 + 26]) << 0x10 | uint(c2da_mem[fv_0 + 27]) << 0x18) | 4
                let c2da_fresh7 : uint = uint(c2da_fresh6)
                c2da_mem[fv_0 + 24] = uint8(c2da_fresh7)
                c2da_mem[fv_0 + 25] = uint8(c2da_fresh7 >> 0x8)
                c2da_mem[fv_0 + 26] = uint8(c2da_fresh7 >> 0x10)
                c2da_mem[fv_0 + 27] = uint8(c2da_fresh7 >> 0x18)
            }
            if (int(uint(c2da_mem[fv_0 + 1 * 4]) | uint(c2da_mem[fv_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[fv_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[fv_0 + 1 * 4 + 3]) << 0x18) > int(uint(c2da_mem[5260]) | uint(c2da_mem[5261]) << 0x8 | uint(c2da_mem[5262]) << 0x10 | uint(c2da_mem[5263]) << 0x18)) {
                let c2da_fresh8 : int = int(uint(c2da_mem[fv_0 + 24]) | uint(c2da_mem[fv_0 + 25]) << 0x8 | uint(c2da_mem[fv_0 + 26]) << 0x10 | uint(c2da_mem[fv_0 + 27]) << 0x18) | 8
                let c2da_fresh9 : uint = uint(c2da_fresh8)
                c2da_mem[fv_0 + 24] = uint8(c2da_fresh9)
                c2da_mem[fv_0 + 25] = uint8(c2da_fresh9 >> 0x8)
                c2da_mem[fv_0 + 26] = uint8(c2da_fresh9 >> 0x10)
                c2da_mem[fv_0 + 27] = uint8(c2da_fresh9 >> 0x18)
            }
        }
        i++
        fv_0 += 32
        av += 12
        r_apverts += 4
        pstverts += 12
    }
    r_affinetridesc.numtriangles = 1
    ptri = paliashdr + int(uint(c2da_mem[paliashdr + 12]) | uint(c2da_mem[paliashdr + 13]) << 0x8 | uint(c2da_mem[paliashdr + 14]) << 0x10 | uint(c2da_mem[paliashdr + 15]) << 0x18)
    i = 0
    while (i < int(uint(c2da_mem[pmdl + 64]) | uint(c2da_mem[pmdl + 65]) << 0x8 | uint(c2da_mem[pmdl + 66]) << 0x10 | uint(c2da_mem[pmdl + 67]) << 0x18)) {
        pfv[0] = pfinalverts + int(uint(c2da_mem[ptri + 4 + 0 * 4]) | uint(c2da_mem[ptri + 4 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ptri + 4 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ptri + 4 + 0 * 4 + 3]) << 0x18) * 32
        pfv[1] = pfinalverts + int(uint(c2da_mem[ptri + 4 + 1 * 4]) | uint(c2da_mem[ptri + 4 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ptri + 4 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ptri + 4 + 1 * 4 + 3]) << 0x18) * 32
        pfv[2] = pfinalverts + int(uint(c2da_mem[ptri + 4 + 2 * 4]) | uint(c2da_mem[ptri + 4 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ptri + 4 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ptri + 4 + 2 * 4 + 3]) << 0x18) * 32
        let c2da_fresh10 : int = pfv[0] + 24
        let c2da_fresh11 : int = pfv[1] + 24
        let c2da_fresh12 : int = pfv[2] + 24
        if ((int(uint(c2da_mem[c2da_fresh10]) | uint(c2da_mem[c2da_fresh10 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh10 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh10 + 3]) << 0x18) & int(uint(c2da_mem[c2da_fresh11]) | uint(c2da_mem[c2da_fresh11 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh11 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh11 + 3]) << 0x18) & int(uint(c2da_mem[c2da_fresh12]) | uint(c2da_mem[c2da_fresh12 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh12 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh12 + 3]) << 0x18) & (15 | 16)) != 0) {
            i++
            ptri += 16
            continue
        }
        let c2da_fresh13 : int = pfv[0] + 24
        let c2da_fresh14 : int = pfv[1] + 24
        let c2da_fresh15 : int = pfv[2] + 24
        if (((int(uint(c2da_mem[c2da_fresh13]) | uint(c2da_mem[c2da_fresh13 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh13 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh13 + 3]) << 0x18) | int(uint(c2da_mem[c2da_fresh14]) | uint(c2da_mem[c2da_fresh14 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh14 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh14 + 3]) << 0x18) | int(uint(c2da_mem[c2da_fresh15]) | uint(c2da_mem[c2da_fresh15 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh15 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh15 + 3]) << 0x18)) & (15 | 16)) == 0) {
            r_affinetridesc.pfinalverts = int(pfinalverts)  // nolint:PERF020
            r_affinetridesc.ptriangles = ptri
            D_PolysetDraw()
        } else {
            R_AliasClipTriangle(ptri)
        }
        i++
        ptri += 16
    }
    return
}
var pfinalverts : int = default<int>

var pmdl : int = default<int>

var paliashdr : int = default<int>

[export, sideeffects]
def R_AliasProjectFinalVert(var fv_1 : int; var av_0 : int) {
    var zi : float = float(1.0lf / double(uint_bits_to_float(uint(c2da_mem[av_0 + 2 * 4]) | uint(c2da_mem[av_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[av_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[av_0 + 2 * 4 + 3]) << 0x18)))
    let c2da_fresh16 : int = int(zi * ziscale)
    let c2da_fresh17 : uint = uint(c2da_fresh16)
    c2da_mem[fv_1 + 5 * 4] = uint8(c2da_fresh17)
    c2da_mem[fv_1 + 5 * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[fv_1 + 5 * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[fv_1 + 5 * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
    let c2da_fresh18 : int = int(uint_bits_to_float(uint(c2da_mem[av_0 + 0 * 4]) | uint(c2da_mem[av_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[av_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[av_0 + 0 * 4 + 3]) << 0x18) * aliasxscale * zi + aliasxcenter)
    let c2da_fresh19 : uint = uint(c2da_fresh18)
    c2da_mem[fv_1 + 0 * 4] = uint8(c2da_fresh19)
    c2da_mem[fv_1 + 0 * 4 + 1] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[fv_1 + 0 * 4 + 2] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[fv_1 + 0 * 4 + 3] = uint8(c2da_fresh19 >> 0x18)
    let c2da_fresh20 : int = int(uint_bits_to_float(uint(c2da_mem[av_0 + 1 * 4]) | uint(c2da_mem[av_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[av_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[av_0 + 1 * 4 + 3]) << 0x18) * aliasyscale * zi + aliasycenter)
    let c2da_fresh21 : uint = uint(c2da_fresh20)
    c2da_mem[fv_1 + 1 * 4] = uint8(c2da_fresh21)
    c2da_mem[fv_1 + 1 * 4 + 1] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[fv_1 + 1 * 4 + 2] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[fv_1 + 1 * 4 + 3] = uint8(c2da_fresh21 >> 0x18)
    return
}
var private ziscale : float = default<float>

var r_apverts : int = default<int>

[export, sideeffects]
def R_AliasTransformFinalVert(var fv_2 : int; var av_1 : int; var pverts : int; var pstverts_0 : int) {
    var temp : int
    var lightcos : float
    var plightnormal : int
    let c2da_fresh22 : float = float(int(c2da_mem[pverts + 0])) * uint_bits_to_float(uint(c2da_mem[391344 + 0 * 16 + 0 * 4]) | uint(c2da_mem[391344 + 0 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 0 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 0 * 16 + 0 * 4 + 3]) << 0x18) + float(int(c2da_mem[pverts + 1])) * uint_bits_to_float(uint(c2da_mem[391344 + 0 * 16 + 1 * 4]) | uint(c2da_mem[391344 + 0 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 0 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 0 * 16 + 1 * 4 + 3]) << 0x18) + float(int(c2da_mem[pverts + 2])) * uint_bits_to_float(uint(c2da_mem[391344 + 0 * 16 + 2 * 4]) | uint(c2da_mem[391344 + 0 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 0 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 0 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391344 + 0 * 16 + 3 * 4]) | uint(c2da_mem[391344 + 0 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 0 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 0 * 16 + 3 * 4 + 3]) << 0x18)
    let c2da_fresh23 : uint = float_bits_to_uint(c2da_fresh22)
    c2da_mem[av_1 + 0 * 4] = uint8(c2da_fresh23)
    c2da_mem[av_1 + 0 * 4 + 1] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[av_1 + 0 * 4 + 2] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[av_1 + 0 * 4 + 3] = uint8(c2da_fresh23 >> 0x18)
    let c2da_fresh24 : float = float(int(c2da_mem[pverts + 0])) * uint_bits_to_float(uint(c2da_mem[391344 + 1 * 16 + 0 * 4]) | uint(c2da_mem[391344 + 1 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 1 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 1 * 16 + 0 * 4 + 3]) << 0x18) + float(int(c2da_mem[pverts + 1])) * uint_bits_to_float(uint(c2da_mem[391344 + 1 * 16 + 1 * 4]) | uint(c2da_mem[391344 + 1 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 1 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 1 * 16 + 1 * 4 + 3]) << 0x18) + float(int(c2da_mem[pverts + 2])) * uint_bits_to_float(uint(c2da_mem[391344 + 1 * 16 + 2 * 4]) | uint(c2da_mem[391344 + 1 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 1 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 1 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391344 + 1 * 16 + 3 * 4]) | uint(c2da_mem[391344 + 1 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 1 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 1 * 16 + 3 * 4 + 3]) << 0x18)
    let c2da_fresh25 : uint = float_bits_to_uint(c2da_fresh24)
    c2da_mem[av_1 + 1 * 4] = uint8(c2da_fresh25)
    c2da_mem[av_1 + 1 * 4 + 1] = uint8(c2da_fresh25 >> 0x8)
    c2da_mem[av_1 + 1 * 4 + 2] = uint8(c2da_fresh25 >> 0x10)
    c2da_mem[av_1 + 1 * 4 + 3] = uint8(c2da_fresh25 >> 0x18)
    let c2da_fresh26 : float = float(int(c2da_mem[pverts + 0])) * uint_bits_to_float(uint(c2da_mem[391344 + 2 * 16 + 0 * 4]) | uint(c2da_mem[391344 + 2 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 2 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 2 * 16 + 0 * 4 + 3]) << 0x18) + float(int(c2da_mem[pverts + 1])) * uint_bits_to_float(uint(c2da_mem[391344 + 2 * 16 + 1 * 4]) | uint(c2da_mem[391344 + 2 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 2 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 2 * 16 + 1 * 4 + 3]) << 0x18) + float(int(c2da_mem[pverts + 2])) * uint_bits_to_float(uint(c2da_mem[391344 + 2 * 16 + 2 * 4]) | uint(c2da_mem[391344 + 2 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 2 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 2 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391344 + 2 * 16 + 3 * 4]) | uint(c2da_mem[391344 + 2 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 2 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 2 * 16 + 3 * 4 + 3]) << 0x18)
    let c2da_fresh27 : uint = float_bits_to_uint(c2da_fresh26)
    c2da_mem[av_1 + 2 * 4] = uint8(c2da_fresh27)
    c2da_mem[av_1 + 2 * 4 + 1] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[av_1 + 2 * 4 + 2] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[av_1 + 2 * 4 + 3] = uint8(c2da_fresh27 >> 0x18)
    let c2da_fresh28 : int = int(uint(c2da_mem[pstverts_0 + 4]) | uint(c2da_mem[pstverts_0 + 5]) << 0x8 | uint(c2da_mem[pstverts_0 + 6]) << 0x10 | uint(c2da_mem[pstverts_0 + 7]) << 0x18)
    let c2da_fresh29 : uint = uint(c2da_fresh28)
    c2da_mem[fv_2 + 2 * 4] = uint8(c2da_fresh29)
    c2da_mem[fv_2 + 2 * 4 + 1] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[fv_2 + 2 * 4 + 2] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[fv_2 + 2 * 4 + 3] = uint8(c2da_fresh29 >> 0x18)
    let c2da_fresh30 : int = int(uint(c2da_mem[pstverts_0 + 8]) | uint(c2da_mem[pstverts_0 + 9]) << 0x8 | uint(c2da_mem[pstverts_0 + 10]) << 0x10 | uint(c2da_mem[pstverts_0 + 11]) << 0x18)
    let c2da_fresh31 : uint = uint(c2da_fresh30)
    c2da_mem[fv_2 + 3 * 4] = uint8(c2da_fresh31)
    c2da_mem[fv_2 + 3 * 4 + 1] = uint8(c2da_fresh31 >> 0x8)
    c2da_mem[fv_2 + 3 * 4 + 2] = uint8(c2da_fresh31 >> 0x10)
    c2da_mem[fv_2 + 3 * 4 + 3] = uint8(c2da_fresh31 >> 0x18)
    let c2da_fresh32 : int = int(uint(c2da_mem[pstverts_0]) | uint(c2da_mem[pstverts_0 + 1]) << 0x8 | uint(c2da_mem[pstverts_0 + 2]) << 0x10 | uint(c2da_mem[pstverts_0 + 3]) << 0x18)
    let c2da_fresh33 : uint = uint(c2da_fresh32)
    c2da_mem[fv_2 + 24] = uint8(c2da_fresh33)
    c2da_mem[fv_2 + 25] = uint8(c2da_fresh33 >> 0x8)
    c2da_mem[fv_2 + 26] = uint8(c2da_fresh33 >> 0x10)
    c2da_mem[fv_2 + 27] = uint8(c2da_fresh33 >> 0x18)
    plightnormal = 389392 + int(c2da_mem[pverts + 3]) * 12
    lightcos = uint_bits_to_float(uint(c2da_mem[plightnormal + 0 * 4]) | uint(c2da_mem[plightnormal + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plightnormal + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plightnormal + 0 * 4 + 3]) << 0x18) * r_plightvec[0] + uint_bits_to_float(uint(c2da_mem[plightnormal + 1 * 4]) | uint(c2da_mem[plightnormal + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plightnormal + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plightnormal + 1 * 4 + 3]) << 0x18) * r_plightvec[1] + uint_bits_to_float(uint(c2da_mem[plightnormal + 2 * 4]) | uint(c2da_mem[plightnormal + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plightnormal + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plightnormal + 2 * 4 + 3]) << 0x18) * r_plightvec[2]
    temp = r_ambientlight
    if (lightcos < 0.0) {
        temp += int(r_shadelight * lightcos)
        if (temp < 0) {
            temp = 0
        }
    }
    let c2da_fresh34 : uint = uint(temp)
    c2da_mem[fv_2 + 4 * 4] = uint8(c2da_fresh34)
    c2da_mem[fv_2 + 4 * 4 + 1] = uint8(c2da_fresh34 >> 0x8)
    c2da_mem[fv_2 + 4 * 4 + 2] = uint8(c2da_fresh34 >> 0x10)
    c2da_mem[fv_2 + 4 * 4 + 3] = uint8(c2da_fresh34 >> 0x18)
    return
}
var r_shadelight : float = default<float>

var r_ambientlight : int = default<int>

var r_plightvec : vec3_t = default<vec3_t>

var r_anumverts : int = default<int>

var pauxverts : int = default<int>

[export, sideeffects]
def R_AliasPrepareUnclippedPoints() {
    var pstverts_1 : int
    var fv_3 : int
    pstverts_1 = paliashdr + int(uint(c2da_mem[paliashdr + 4]) | uint(c2da_mem[paliashdr + 5]) << 0x8 | uint(c2da_mem[paliashdr + 6]) << 0x10 | uint(c2da_mem[paliashdr + 7]) << 0x18)
    r_anumverts = int(uint(c2da_mem[pmdl + 60]) | uint(c2da_mem[pmdl + 61]) << 0x8 | uint(c2da_mem[pmdl + 62]) << 0x10 | uint(c2da_mem[pmdl + 63]) << 0x18)
    fv_3 = pfinalverts
    R_AliasTransformAndProjectFinalVerts(fv_3, pstverts_1)
    if (r_affinetridesc.drawtype != 0) {
        D_PolysetDrawFinalVerts(fv_3, r_anumverts)
    }
    r_affinetridesc.pfinalverts = int(pfinalverts)  // nolint:PERF020
    r_affinetridesc.ptriangles = paliashdr + int(uint(c2da_mem[paliashdr + 12]) | uint(c2da_mem[paliashdr + 13]) << 0x8 | uint(c2da_mem[paliashdr + 14]) << 0x10 | uint(c2da_mem[paliashdr + 15]) << 0x18)
    r_affinetridesc.numtriangles = int(uint(c2da_mem[pmdl + 64]) | uint(c2da_mem[pmdl + 65]) << 0x8 | uint(c2da_mem[pmdl + 66]) << 0x10 | uint(c2da_mem[pmdl + 67]) << 0x18)
    D_PolysetDraw()
    return
}
[export, sideeffects]
def R_AliasTransformAndProjectFinalVerts(var fv_4 : int; var pstverts_2 : int) {
    var i_0 : int
    var temp_0 : int
    var lightcos_0 : float
    var plightnormal_0 : int
    var zi_0 : float
    var pverts_0 : int = r_apverts
    i_0 = 0
    while (i_0 < r_anumverts) {
        zi_0 = float(1.0lf / double(float(int(c2da_mem[pverts_0 + 0])) * uint_bits_to_float(uint(c2da_mem[391344 + 2 * 16 + 0 * 4]) | uint(c2da_mem[391344 + 2 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 2 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 2 * 16 + 0 * 4 + 3]) << 0x18) + float(int(c2da_mem[pverts_0 + 1])) * uint_bits_to_float(uint(c2da_mem[391344 + 2 * 16 + 1 * 4]) | uint(c2da_mem[391344 + 2 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 2 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 2 * 16 + 1 * 4 + 3]) << 0x18) + float(int(c2da_mem[pverts_0 + 2])) * uint_bits_to_float(uint(c2da_mem[391344 + 2 * 16 + 2 * 4]) | uint(c2da_mem[391344 + 2 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 2 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 2 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391344 + 2 * 16 + 3 * 4]) | uint(c2da_mem[391344 + 2 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 2 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 2 * 16 + 3 * 4 + 3]) << 0x18)))
        let c2da_fresh35 : int = int(zi_0)
        let c2da_fresh36 : uint = uint(c2da_fresh35)
        c2da_mem[fv_4 + 5 * 4] = uint8(c2da_fresh36)
        c2da_mem[fv_4 + 5 * 4 + 1] = uint8(c2da_fresh36 >> 0x8)
        c2da_mem[fv_4 + 5 * 4 + 2] = uint8(c2da_fresh36 >> 0x10)
        c2da_mem[fv_4 + 5 * 4 + 3] = uint8(c2da_fresh36 >> 0x18)
        let c2da_fresh37 : int = int((float(int(c2da_mem[pverts_0 + 0])) * uint_bits_to_float(uint(c2da_mem[391344 + 0 * 16 + 0 * 4]) | uint(c2da_mem[391344 + 0 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 0 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 0 * 16 + 0 * 4 + 3]) << 0x18) + float(int(c2da_mem[pverts_0 + 1])) * uint_bits_to_float(uint(c2da_mem[391344 + 0 * 16 + 1 * 4]) | uint(c2da_mem[391344 + 0 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 0 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 0 * 16 + 1 * 4 + 3]) << 0x18) + float(int(c2da_mem[pverts_0 + 2])) * uint_bits_to_float(uint(c2da_mem[391344 + 0 * 16 + 2 * 4]) | uint(c2da_mem[391344 + 0 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 0 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 0 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391344 + 0 * 16 + 3 * 4]) | uint(c2da_mem[391344 + 0 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 0 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 0 * 16 + 3 * 4 + 3]) << 0x18)) * zi_0 + aliasxcenter)
        let c2da_fresh38 : uint = uint(c2da_fresh37)
        c2da_mem[fv_4 + 0 * 4] = uint8(c2da_fresh38)
        c2da_mem[fv_4 + 0 * 4 + 1] = uint8(c2da_fresh38 >> 0x8)
        c2da_mem[fv_4 + 0 * 4 + 2] = uint8(c2da_fresh38 >> 0x10)
        c2da_mem[fv_4 + 0 * 4 + 3] = uint8(c2da_fresh38 >> 0x18)
        let c2da_fresh39 : int = int((float(int(c2da_mem[pverts_0 + 0])) * uint_bits_to_float(uint(c2da_mem[391344 + 1 * 16 + 0 * 4]) | uint(c2da_mem[391344 + 1 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 1 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 1 * 16 + 0 * 4 + 3]) << 0x18) + float(int(c2da_mem[pverts_0 + 1])) * uint_bits_to_float(uint(c2da_mem[391344 + 1 * 16 + 1 * 4]) | uint(c2da_mem[391344 + 1 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 1 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 1 * 16 + 1 * 4 + 3]) << 0x18) + float(int(c2da_mem[pverts_0 + 2])) * uint_bits_to_float(uint(c2da_mem[391344 + 1 * 16 + 2 * 4]) | uint(c2da_mem[391344 + 1 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 1 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 1 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391344 + 1 * 16 + 3 * 4]) | uint(c2da_mem[391344 + 1 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 1 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 1 * 16 + 3 * 4 + 3]) << 0x18)) * zi_0 + aliasycenter)
        let c2da_fresh40 : uint = uint(c2da_fresh39)
        c2da_mem[fv_4 + 1 * 4] = uint8(c2da_fresh40)
        c2da_mem[fv_4 + 1 * 4 + 1] = uint8(c2da_fresh40 >> 0x8)
        c2da_mem[fv_4 + 1 * 4 + 2] = uint8(c2da_fresh40 >> 0x10)
        c2da_mem[fv_4 + 1 * 4 + 3] = uint8(c2da_fresh40 >> 0x18)
        let c2da_fresh41 : int = int(uint(c2da_mem[pstverts_2 + 4]) | uint(c2da_mem[pstverts_2 + 5]) << 0x8 | uint(c2da_mem[pstverts_2 + 6]) << 0x10 | uint(c2da_mem[pstverts_2 + 7]) << 0x18)
        let c2da_fresh42 : uint = uint(c2da_fresh41)
        c2da_mem[fv_4 + 2 * 4] = uint8(c2da_fresh42)
        c2da_mem[fv_4 + 2 * 4 + 1] = uint8(c2da_fresh42 >> 0x8)
        c2da_mem[fv_4 + 2 * 4 + 2] = uint8(c2da_fresh42 >> 0x10)
        c2da_mem[fv_4 + 2 * 4 + 3] = uint8(c2da_fresh42 >> 0x18)
        let c2da_fresh43 : int = int(uint(c2da_mem[pstverts_2 + 8]) | uint(c2da_mem[pstverts_2 + 9]) << 0x8 | uint(c2da_mem[pstverts_2 + 10]) << 0x10 | uint(c2da_mem[pstverts_2 + 11]) << 0x18)
        let c2da_fresh44 : uint = uint(c2da_fresh43)
        c2da_mem[fv_4 + 3 * 4] = uint8(c2da_fresh44)
        c2da_mem[fv_4 + 3 * 4 + 1] = uint8(c2da_fresh44 >> 0x8)
        c2da_mem[fv_4 + 3 * 4 + 2] = uint8(c2da_fresh44 >> 0x10)
        c2da_mem[fv_4 + 3 * 4 + 3] = uint8(c2da_fresh44 >> 0x18)
        let c2da_fresh45 : int = int(uint(c2da_mem[pstverts_2]) | uint(c2da_mem[pstverts_2 + 1]) << 0x8 | uint(c2da_mem[pstverts_2 + 2]) << 0x10 | uint(c2da_mem[pstverts_2 + 3]) << 0x18)
        let c2da_fresh46 : uint = uint(c2da_fresh45)
        c2da_mem[fv_4 + 24] = uint8(c2da_fresh46)
        c2da_mem[fv_4 + 25] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[fv_4 + 26] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[fv_4 + 27] = uint8(c2da_fresh46 >> 0x18)
        plightnormal_0 = 389392 + int(c2da_mem[pverts_0 + 3]) * 12
        lightcos_0 = uint_bits_to_float(uint(c2da_mem[plightnormal_0 + 0 * 4]) | uint(c2da_mem[plightnormal_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plightnormal_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plightnormal_0 + 0 * 4 + 3]) << 0x18) * r_plightvec[0] + uint_bits_to_float(uint(c2da_mem[plightnormal_0 + 1 * 4]) | uint(c2da_mem[plightnormal_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plightnormal_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plightnormal_0 + 1 * 4 + 3]) << 0x18) * r_plightvec[1] + uint_bits_to_float(uint(c2da_mem[plightnormal_0 + 2 * 4]) | uint(c2da_mem[plightnormal_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plightnormal_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plightnormal_0 + 2 * 4 + 3]) << 0x18) * r_plightvec[2]
        temp_0 = r_ambientlight
        if (lightcos_0 < 0.0) {
            temp_0 += int(r_shadelight * lightcos_0)
            if (temp_0 < 0) {
                temp_0 = 0
            }
        }
        let c2da_fresh47 : uint = uint(temp_0)
        c2da_mem[fv_4 + 4 * 4] = uint8(c2da_fresh47)
        c2da_mem[fv_4 + 4 * 4 + 1] = uint8(c2da_fresh47 >> 0x8)
        c2da_mem[fv_4 + 4 * 4 + 2] = uint8(c2da_fresh47 >> 0x10)
        c2da_mem[fv_4 + 4 * 4 + 3] = uint8(c2da_fresh47 >> 0x18)
        i_0++
        fv_4 += 32
        pverts_0 += 4
        pstverts_2 += 12
    }
    return
}
[export, sideeffects]
def R_AliasSetupFrame() {
    var frame : int
    var i_1 : int
    var numframes : int
    var paliasgroup : int
    var pintervals : int
    var fullinterval : float
    var targettime : float
    var time : float
    frame = int(uint(c2da_mem[currententity + 152]) | uint(c2da_mem[currententity + 153]) << 0x8 | uint(c2da_mem[currententity + 154]) << 0x10 | uint(c2da_mem[currententity + 155]) << 0x18)
    if (frame >= int(uint(c2da_mem[pmdl + 68]) | uint(c2da_mem[pmdl + 69]) << 0x8 | uint(c2da_mem[pmdl + 70]) << 0x10 | uint(c2da_mem[pmdl + 71]) << 0x18) || frame < 0) {
        Con_DPrintf(732523, [C2daVaArg(tag = 1, i64 = int64(frame), f64 = 0.0lf, raw = 0x0)])
        frame = 0
    }
    if ((uint(c2da_mem[paliashdr + 16 + frame * 32]) | uint(c2da_mem[paliashdr + 16 + frame * 32 + 1]) << 0x8 | uint(c2da_mem[paliashdr + 16 + frame * 32 + 2]) << 0x10 | uint(c2da_mem[paliashdr + 16 + frame * 32 + 3]) << 0x18) == 0u) {
        r_apverts = paliashdr + int(uint(c2da_mem[paliashdr + 16 + frame * 32 + 12]) | uint(c2da_mem[paliashdr + 16 + frame * 32 + 13]) << 0x8 | uint(c2da_mem[paliashdr + 16 + frame * 32 + 14]) << 0x10 | uint(c2da_mem[paliashdr + 16 + frame * 32 + 15]) << 0x18)
        return
    }
    paliasgroup = paliashdr + int(uint(c2da_mem[paliashdr + 16 + frame * 32 + 12]) | uint(c2da_mem[paliashdr + 16 + frame * 32 + 13]) << 0x8 | uint(c2da_mem[paliashdr + 16 + frame * 32 + 14]) << 0x10 | uint(c2da_mem[paliashdr + 16 + frame * 32 + 15]) << 0x18)
    pintervals = paliashdr + int(uint(c2da_mem[paliasgroup + 4]) | uint(c2da_mem[paliasgroup + 5]) << 0x8 | uint(c2da_mem[paliasgroup + 6]) << 0x10 | uint(c2da_mem[paliasgroup + 7]) << 0x18)
    numframes = int(uint(c2da_mem[paliasgroup]) | uint(c2da_mem[paliasgroup + 1]) << 0x8 | uint(c2da_mem[paliasgroup + 2]) << 0x10 | uint(c2da_mem[paliasgroup + 3]) << 0x18)
    fullinterval = uint_bits_to_float(uint(c2da_mem[pintervals + (numframes - 1) * 4]) | uint(c2da_mem[pintervals + (numframes - 1) * 4 + 1]) << 0x8 | uint(c2da_mem[pintervals + (numframes - 1) * 4 + 2]) << 0x10 | uint(c2da_mem[pintervals + (numframes - 1) * 4 + 3]) << 0x18)
    time = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + double(uint_bits_to_float(uint(c2da_mem[currententity + 156]) | uint(c2da_mem[currententity + 157]) << 0x8 | uint(c2da_mem[currententity + 158]) << 0x10 | uint(c2da_mem[currententity + 159]) << 0x18)))
    targettime = time - float(int(time / fullinterval)) * fullinterval
    i_1 = 0
    while (i_1 < numframes - 1) {
        if (uint_bits_to_float(uint(c2da_mem[pintervals + i_1 * 4]) | uint(c2da_mem[pintervals + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[pintervals + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[pintervals + i_1 * 4 + 3]) << 0x18) > targettime) {
            break
        }
        i_1++
    }
    r_apverts = paliashdr + int(uint(c2da_mem[paliasgroup + 8 + i_1 * 12 + 8]) | uint(c2da_mem[paliasgroup + 8 + i_1 * 12 + 9]) << 0x8 | uint(c2da_mem[paliasgroup + 8 + i_1 * 12 + 10]) << 0x10 | uint(c2da_mem[paliasgroup + 8 + i_1 * 12 + 11]) << 0x18)
    return
}
[export, sideeffects]
def R_AliasSetupLighting(var plighting_0 : int) {
    r_ambientlight = int(uint(c2da_mem[plighting_0]) | uint(c2da_mem[plighting_0 + 1]) << 0x8 | uint(c2da_mem[plighting_0 + 2]) << 0x10 | uint(c2da_mem[plighting_0 + 3]) << 0x18)
    if (r_ambientlight < 5) {
        r_ambientlight = 5
    }
    r_ambientlight = 255 - r_ambientlight << 6
    if (r_ambientlight < 5) {
        r_ambientlight = 5
    }
    r_shadelight = float(int(uint(c2da_mem[plighting_0 + 4]) | uint(c2da_mem[plighting_0 + 5]) << 0x8 | uint(c2da_mem[plighting_0 + 6]) << 0x10 | uint(c2da_mem[plighting_0 + 7]) << 0x18))
    if (r_shadelight < 0.0) {
        r_shadelight = 0.0
    }
    r_shadelight *= float(1 << 6)
    let c2da_fresh48 : int = int(uint(c2da_mem[plighting_0 + 8]) | uint(c2da_mem[plighting_0 + 9]) << 0x8 | uint(c2da_mem[plighting_0 + 10]) << 0x10 | uint(c2da_mem[plighting_0 + 11]) << 0x18) + 0 * 4
    let c2da_fresh49 : int = int(uint(c2da_mem[plighting_0 + 8]) | uint(c2da_mem[plighting_0 + 9]) << 0x8 | uint(c2da_mem[plighting_0 + 10]) << 0x10 | uint(c2da_mem[plighting_0 + 11]) << 0x18) + 1 * 4
    let c2da_fresh50 : int = int(uint(c2da_mem[plighting_0 + 8]) | uint(c2da_mem[plighting_0 + 9]) << 0x8 | uint(c2da_mem[plighting_0 + 10]) << 0x10 | uint(c2da_mem[plighting_0 + 11]) << 0x18) + 2 * 4
    r_plightvec[0] = uint_bits_to_float(uint(c2da_mem[c2da_fresh48]) | uint(c2da_mem[c2da_fresh48 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh48 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh48 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[732336 + 0 * 4]) | uint(c2da_mem[732336 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[732336 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[732336 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fresh49]) | uint(c2da_mem[c2da_fresh49 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh49 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh49 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[732336 + 1 * 4]) | uint(c2da_mem[732336 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[732336 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[732336 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fresh50]) | uint(c2da_mem[c2da_fresh50 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh50 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh50 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[732336 + 2 * 4]) | uint(c2da_mem[732336 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[732336 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[732336 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh51 : int = int(uint(c2da_mem[plighting_0 + 8]) | uint(c2da_mem[plighting_0 + 9]) << 0x8 | uint(c2da_mem[plighting_0 + 10]) << 0x10 | uint(c2da_mem[plighting_0 + 11]) << 0x18) + 0 * 4
    let c2da_fresh52 : int = int(uint(c2da_mem[plighting_0 + 8]) | uint(c2da_mem[plighting_0 + 9]) << 0x8 | uint(c2da_mem[plighting_0 + 10]) << 0x10 | uint(c2da_mem[plighting_0 + 11]) << 0x18) + 1 * 4
    let c2da_fresh53 : int = int(uint(c2da_mem[plighting_0 + 8]) | uint(c2da_mem[plighting_0 + 9]) << 0x8 | uint(c2da_mem[plighting_0 + 10]) << 0x10 | uint(c2da_mem[plighting_0 + 11]) << 0x18) + 2 * 4
    r_plightvec[1] = -(uint_bits_to_float(uint(c2da_mem[c2da_fresh51]) | uint(c2da_mem[c2da_fresh51 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh51 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh51 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[732352 + 0 * 4]) | uint(c2da_mem[732352 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[732352 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[732352 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fresh52]) | uint(c2da_mem[c2da_fresh52 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh52 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh52 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[732352 + 1 * 4]) | uint(c2da_mem[732352 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[732352 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[732352 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fresh53]) | uint(c2da_mem[c2da_fresh53 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh53 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh53 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[732352 + 2 * 4]) | uint(c2da_mem[732352 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[732352 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[732352 + 2 * 4 + 3]) << 0x18))
    let c2da_fresh54 : int = int(uint(c2da_mem[plighting_0 + 8]) | uint(c2da_mem[plighting_0 + 9]) << 0x8 | uint(c2da_mem[plighting_0 + 10]) << 0x10 | uint(c2da_mem[plighting_0 + 11]) << 0x18) + 0 * 4
    let c2da_fresh55 : int = int(uint(c2da_mem[plighting_0 + 8]) | uint(c2da_mem[plighting_0 + 9]) << 0x8 | uint(c2da_mem[plighting_0 + 10]) << 0x10 | uint(c2da_mem[plighting_0 + 11]) << 0x18) + 1 * 4
    let c2da_fresh56 : int = int(uint(c2da_mem[plighting_0 + 8]) | uint(c2da_mem[plighting_0 + 9]) << 0x8 | uint(c2da_mem[plighting_0 + 10]) << 0x10 | uint(c2da_mem[plighting_0 + 11]) << 0x18) + 2 * 4
    r_plightvec[2] = uint_bits_to_float(uint(c2da_mem[c2da_fresh54]) | uint(c2da_mem[c2da_fresh54 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh54 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh54 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[732368 + 0 * 4]) | uint(c2da_mem[732368 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[732368 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[732368 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fresh55]) | uint(c2da_mem[c2da_fresh55 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh55 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh55 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[732368 + 1 * 4]) | uint(c2da_mem[732368 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[732368 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[732368 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fresh56]) | uint(c2da_mem[c2da_fresh56 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh56 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh56 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[732368 + 2 * 4]) | uint(c2da_mem[732368 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[732368 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[732368 + 2 * 4 + 3]) << 0x18)
    return
}
[export, sideeffects]
def R_AliasSetUpTransform(var trivial_accept : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_AliasSetUpTransform_c2da_frame(trivial_accept, c2da_lin_enter(112))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_AliasSetupSkin() {
    var skinnum : int
    var i_3 : int
    var numskins : int
    var paliasskingroup : int
    var pskinintervals : int
    var fullskininterval : float
    var skintargettime : float
    var skintime : float
    skinnum = int(uint(c2da_mem[currententity + 172]) | uint(c2da_mem[currententity + 173]) << 0x8 | uint(c2da_mem[currententity + 174]) << 0x10 | uint(c2da_mem[currententity + 175]) << 0x18)
    if (skinnum >= int(uint(c2da_mem[pmdl + 48]) | uint(c2da_mem[pmdl + 49]) << 0x8 | uint(c2da_mem[pmdl + 50]) << 0x10 | uint(c2da_mem[pmdl + 51]) << 0x18) || skinnum < 0) {
        Con_DPrintf(732560, [C2daVaArg(tag = 1, i64 = int64(skinnum), f64 = 0.0lf, raw = 0x0)])
        skinnum = 0
    }
    pskindesc = paliashdr + int(uint(c2da_mem[paliashdr + 8]) | uint(c2da_mem[paliashdr + 9]) << 0x8 | uint(c2da_mem[paliashdr + 10]) << 0x10 | uint(c2da_mem[paliashdr + 11]) << 0x18) + skinnum * 24
    a_skinwidth = int(uint(c2da_mem[pmdl + 52]) | uint(c2da_mem[pmdl + 53]) << 0x8 | uint(c2da_mem[pmdl + 54]) << 0x10 | uint(c2da_mem[pmdl + 55]) << 0x18)
    if ((uint(c2da_mem[pskindesc]) | uint(c2da_mem[pskindesc + 1]) << 0x8 | uint(c2da_mem[pskindesc + 2]) << 0x10 | uint(c2da_mem[pskindesc + 3]) << 0x18) == 1u) {
        paliasskingroup = paliashdr + int(uint(c2da_mem[pskindesc + 16]) | uint(c2da_mem[pskindesc + 17]) << 0x8 | uint(c2da_mem[pskindesc + 18]) << 0x10 | uint(c2da_mem[pskindesc + 19]) << 0x18)
        pskinintervals = paliashdr + int(uint(c2da_mem[paliasskingroup + 4]) | uint(c2da_mem[paliasskingroup + 5]) << 0x8 | uint(c2da_mem[paliasskingroup + 6]) << 0x10 | uint(c2da_mem[paliasskingroup + 7]) << 0x18)
        numskins = int(uint(c2da_mem[paliasskingroup]) | uint(c2da_mem[paliasskingroup + 1]) << 0x8 | uint(c2da_mem[paliasskingroup + 2]) << 0x10 | uint(c2da_mem[paliasskingroup + 3]) << 0x18)
        fullskininterval = uint_bits_to_float(uint(c2da_mem[pskinintervals + (numskins - 1) * 4]) | uint(c2da_mem[pskinintervals + (numskins - 1) * 4 + 1]) << 0x8 | uint(c2da_mem[pskinintervals + (numskins - 1) * 4 + 2]) << 0x10 | uint(c2da_mem[pskinintervals + (numskins - 1) * 4 + 3]) << 0x18)
        skintime = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + double(uint_bits_to_float(uint(c2da_mem[currententity + 156]) | uint(c2da_mem[currententity + 157]) << 0x8 | uint(c2da_mem[currententity + 158]) << 0x10 | uint(c2da_mem[currententity + 159]) << 0x18)))
        skintargettime = skintime - float(int(skintime / fullskininterval)) * fullskininterval
        i_3 = 0
        while (i_3 < numskins - 1) {
            if (uint_bits_to_float(uint(c2da_mem[pskinintervals + i_3 * 4]) | uint(c2da_mem[pskinintervals + i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[pskinintervals + i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[pskinintervals + i_3 * 4 + 3]) << 0x18) > skintargettime) {
                break
            }
            i_3++
        }
        pskindesc = paliasskingroup + 8 + i_3 * 24
    }
    r_affinetridesc.pskindesc = int(pskindesc)  // nolint:PERF020
    r_affinetridesc.pskin = paliashdr + int(uint(c2da_mem[pskindesc + 16]) | uint(c2da_mem[pskindesc + 17]) << 0x8 | uint(c2da_mem[pskindesc + 18]) << 0x10 | uint(c2da_mem[pskindesc + 19]) << 0x18)
    r_affinetridesc.skinwidth = int(a_skinwidth)  // nolint:PERF020
    r_affinetridesc.seamfixupX16 = a_skinwidth >> 1 << 16
    r_affinetridesc.skinheight = int(uint(c2da_mem[pmdl + 56]) | uint(c2da_mem[pmdl + 57]) << 0x8 | uint(c2da_mem[pmdl + 58]) << 0x10 | uint(c2da_mem[pmdl + 59]) << 0x18)
    return
}
var a_skinwidth : int = default<int>

var private pskindesc : int = default<int>

var r_amodels_drawn : int = default<int>

var ptriangles : int = default<int>

[export, sideeffects]
def R_AliasCheckBBox() : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = R_AliasCheckBBox_c2da_frame(c2da_lin_enter(800))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
var private aedges : aedge_t[12] = fixed_array<aedge_t>(aedge_t(index0 = 0, index1 = 1), aedge_t(index0 = 1, index1 = 2), aedge_t(index0 = 2, index1 = 3), aedge_t(index0 = 3, index1 = 0), aedge_t(index0 = 4, index1 = 5), aedge_t(index0 = 5, index1 = 6), aedge_t(index0 = 6, index1 = 7), aedge_t(index0 = 7, index1 = 4), aedge_t(index0 = 0, index1 = 5), aedge_t(index0 = 1, index1 = 4), aedge_t(index0 = 2, index1 = 7), aedge_t(index0 = 3, index1 = 6))

[export, sideeffects]
def R_AliasTransformVector(var in_0 : int; var out : int) {
    let c2da_fresh159 : float = uint_bits_to_float(uint(c2da_mem[in_0 + 0 * 4]) | uint(c2da_mem[in_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[391344 + 0 * 16 + 0 * 4]) | uint(c2da_mem[391344 + 0 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 0 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 0 * 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in_0 + 1 * 4]) | uint(c2da_mem[in_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[391344 + 0 * 16 + 1 * 4]) | uint(c2da_mem[391344 + 0 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 0 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 0 * 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in_0 + 2 * 4]) | uint(c2da_mem[in_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[391344 + 0 * 16 + 2 * 4]) | uint(c2da_mem[391344 + 0 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 0 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 0 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391344 + 0 * 16 + 3 * 4]) | uint(c2da_mem[391344 + 0 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 0 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 0 * 16 + 3 * 4 + 3]) << 0x18)
    let c2da_fresh160 : uint = float_bits_to_uint(c2da_fresh159)
    c2da_mem[out + 0 * 4] = uint8(c2da_fresh160)
    c2da_mem[out + 0 * 4 + 1] = uint8(c2da_fresh160 >> 0x8)
    c2da_mem[out + 0 * 4 + 2] = uint8(c2da_fresh160 >> 0x10)
    c2da_mem[out + 0 * 4 + 3] = uint8(c2da_fresh160 >> 0x18)
    let c2da_fresh161 : float = uint_bits_to_float(uint(c2da_mem[in_0 + 0 * 4]) | uint(c2da_mem[in_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[391344 + 1 * 16 + 0 * 4]) | uint(c2da_mem[391344 + 1 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 1 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 1 * 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in_0 + 1 * 4]) | uint(c2da_mem[in_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[391344 + 1 * 16 + 1 * 4]) | uint(c2da_mem[391344 + 1 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 1 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 1 * 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in_0 + 2 * 4]) | uint(c2da_mem[in_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[391344 + 1 * 16 + 2 * 4]) | uint(c2da_mem[391344 + 1 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 1 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 1 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391344 + 1 * 16 + 3 * 4]) | uint(c2da_mem[391344 + 1 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 1 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 1 * 16 + 3 * 4 + 3]) << 0x18)
    let c2da_fresh162 : uint = float_bits_to_uint(c2da_fresh161)
    c2da_mem[out + 1 * 4] = uint8(c2da_fresh162)
    c2da_mem[out + 1 * 4 + 1] = uint8(c2da_fresh162 >> 0x8)
    c2da_mem[out + 1 * 4 + 2] = uint8(c2da_fresh162 >> 0x10)
    c2da_mem[out + 1 * 4 + 3] = uint8(c2da_fresh162 >> 0x18)
    let c2da_fresh163 : float = uint_bits_to_float(uint(c2da_mem[in_0 + 0 * 4]) | uint(c2da_mem[in_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[391344 + 2 * 16 + 0 * 4]) | uint(c2da_mem[391344 + 2 * 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 2 * 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 2 * 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in_0 + 1 * 4]) | uint(c2da_mem[in_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[391344 + 2 * 16 + 1 * 4]) | uint(c2da_mem[391344 + 2 * 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 2 * 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 2 * 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[in_0 + 2 * 4]) | uint(c2da_mem[in_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[in_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[in_0 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[391344 + 2 * 16 + 2 * 4]) | uint(c2da_mem[391344 + 2 * 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 2 * 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 2 * 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[391344 + 2 * 16 + 3 * 4]) | uint(c2da_mem[391344 + 2 * 16 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 2 * 16 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 2 * 16 + 3 * 4 + 3]) << 0x18)
    let c2da_fresh164 : uint = float_bits_to_uint(c2da_fresh163)
    c2da_mem[out + 2 * 4] = uint8(c2da_fresh164)
    c2da_mem[out + 2 * 4 + 1] = uint8(c2da_fresh164 >> 0x8)
    c2da_mem[out + 2 * 4 + 2] = uint8(c2da_fresh164 >> 0x10)
    c2da_mem[out + 2 * 4 + 3] = uint8(c2da_fresh164 >> 0x18)
    return
}
var private pmodel : int = default<int>

[sideeffects]
def private R_AliasDrawModel_c2da_frame(var plighting : int; c2da_fp : int) {
    r_amodels_drawn++
    pfinalverts = int(int64(c2da_fp + 0 * 32) + 32l - 1l & int64(~(32 - 1)))
    pauxverts = c2da_fp + 64032 + 0 * 12
    paliashdr = Mod_Extradata(int(uint(c2da_mem[currententity + 136]) | uint(c2da_mem[currententity + 137]) << 0x8 | uint(c2da_mem[currententity + 138]) << 0x10 | uint(c2da_mem[currententity + 139]) << 0x18))
    pmdl = paliashdr + int(uint(c2da_mem[paliashdr]) | uint(c2da_mem[paliashdr + 1]) << 0x8 | uint(c2da_mem[paliashdr + 2]) << 0x10 | uint(c2da_mem[paliashdr + 3]) << 0x18)
    R_AliasSetupSkin()
    R_AliasSetUpTransform(int(uint(c2da_mem[currententity + 188]) | uint(c2da_mem[currententity + 189]) << 0x8 | uint(c2da_mem[currententity + 190]) << 0x10 | uint(c2da_mem[currententity + 191]) << 0x18))
    R_AliasSetupLighting(plighting)
    R_AliasSetupFrame()
    if (int(uint(c2da_mem[currententity + 160]) | uint(c2da_mem[currententity + 161]) << 0x8 | uint(c2da_mem[currententity + 162]) << 0x10 | uint(c2da_mem[currententity + 163]) << 0x18) == 0) {
        Sys_Error(732480, [])
    }
    r_affinetridesc.drawtype = int(uint(c2da_mem[currententity + 188]) | uint(c2da_mem[currententity + 189]) << 0x8 | uint(c2da_mem[currententity + 190]) << 0x10 | uint(c2da_mem[currententity + 191]) << 0x18) == 3 && uint(r_recursiveaffinetriangles) != 0x0 ? 1 : 0
    if (r_affinetridesc.drawtype != 0) {
        D_PolysetUpdateTables()
    }
    acolormap = int(uint(c2da_mem[currententity + 160]) | uint(c2da_mem[currententity + 161]) << 0x8 | uint(c2da_mem[currententity + 162]) << 0x10 | uint(c2da_mem[currententity + 163]) << 0x18)
    if (currententity != 4984) {
        ziscale = 32768.0 * 65536.0
    } else {
        ziscale = float(double(32768.0 * 65536.0) * 3.0lf)
    }
    if (int(uint(c2da_mem[currententity + 188]) | uint(c2da_mem[currententity + 189]) << 0x8 | uint(c2da_mem[currententity + 190]) << 0x10 | uint(c2da_mem[currententity + 191]) << 0x18) != 0) {
        R_AliasPrepareUnclippedPoints()
    } else {
        R_AliasPreparePoints()
    }
    return
}
[sideeffects]
def private R_AliasSetUpTransform_c2da_frame(var trivial_accept : int; c2da_fp : int) {
    var i_2 : int
    let c2da_fresh57 : float = uint_bits_to_float(uint(c2da_mem[currententity + 124 + 2 * 4]) | uint(c2da_mem[currententity + 124 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 124 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 124 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh58 : uint = float_bits_to_uint(c2da_fresh57)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh58)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh58 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh58 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh58 >> 0x18)
    let c2da_fresh59 : float = -uint_bits_to_float(uint(c2da_mem[currententity + 124 + 0 * 4]) | uint(c2da_mem[currententity + 124 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 124 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 124 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh60 : uint = float_bits_to_uint(c2da_fresh59)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh60)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh60 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh60 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh60 >> 0x18)
    let c2da_fresh61 : float = uint_bits_to_float(uint(c2da_mem[currententity + 124 + 1 * 4]) | uint(c2da_mem[currententity + 124 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 124 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 124 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh62 : uint = float_bits_to_uint(c2da_fresh61)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh62)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh62 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh62 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh62 >> 0x18)
    AngleVectors(c2da_fp, 732336, 732352, 732368)
    let c2da_fresh63 : float = uint_bits_to_float(uint(c2da_mem[pmdl + 8 + 0 * 4]) | uint(c2da_mem[pmdl + 8 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pmdl + 8 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pmdl + 8 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh64 : uint = float_bits_to_uint(c2da_fresh63)
    c2da_mem[732384 + 0 * 16 + 0 * 4] = uint8(c2da_fresh64)
    c2da_mem[732384 + 0 * 16 + 0 * 4 + 1] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[732384 + 0 * 16 + 0 * 4 + 2] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[732384 + 0 * 16 + 0 * 4 + 3] = uint8(c2da_fresh64 >> 0x18)
    let c2da_fresh65 : float = uint_bits_to_float(uint(c2da_mem[pmdl + 8 + 1 * 4]) | uint(c2da_mem[pmdl + 8 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pmdl + 8 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pmdl + 8 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh66 : uint = float_bits_to_uint(c2da_fresh65)
    c2da_mem[732384 + 1 * 16 + 1 * 4] = uint8(c2da_fresh66)
    c2da_mem[732384 + 1 * 16 + 1 * 4 + 1] = uint8(c2da_fresh66 >> 0x8)
    c2da_mem[732384 + 1 * 16 + 1 * 4 + 2] = uint8(c2da_fresh66 >> 0x10)
    c2da_mem[732384 + 1 * 16 + 1 * 4 + 3] = uint8(c2da_fresh66 >> 0x18)
    let c2da_fresh67 : float = uint_bits_to_float(uint(c2da_mem[pmdl + 8 + 2 * 4]) | uint(c2da_mem[pmdl + 8 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pmdl + 8 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pmdl + 8 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh68 : uint = float_bits_to_uint(c2da_fresh67)
    c2da_mem[732384 + 2 * 16 + 2 * 4] = uint8(c2da_fresh68)
    c2da_mem[732384 + 2 * 16 + 2 * 4 + 1] = uint8(c2da_fresh68 >> 0x8)
    c2da_mem[732384 + 2 * 16 + 2 * 4 + 2] = uint8(c2da_fresh68 >> 0x10)
    c2da_mem[732384 + 2 * 16 + 2 * 4 + 3] = uint8(c2da_fresh68 >> 0x18)
    let c2da_fresh69 : float = uint_bits_to_float(uint(c2da_mem[pmdl + 20 + 0 * 4]) | uint(c2da_mem[pmdl + 20 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pmdl + 20 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pmdl + 20 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh70 : uint = float_bits_to_uint(c2da_fresh69)
    c2da_mem[732384 + 0 * 16 + 3 * 4] = uint8(c2da_fresh70)
    c2da_mem[732384 + 0 * 16 + 3 * 4 + 1] = uint8(c2da_fresh70 >> 0x8)
    c2da_mem[732384 + 0 * 16 + 3 * 4 + 2] = uint8(c2da_fresh70 >> 0x10)
    c2da_mem[732384 + 0 * 16 + 3 * 4 + 3] = uint8(c2da_fresh70 >> 0x18)
    let c2da_fresh71 : float = uint_bits_to_float(uint(c2da_mem[pmdl + 20 + 1 * 4]) | uint(c2da_mem[pmdl + 20 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pmdl + 20 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pmdl + 20 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh72 : uint = float_bits_to_uint(c2da_fresh71)
    c2da_mem[732384 + 1 * 16 + 3 * 4] = uint8(c2da_fresh72)
    c2da_mem[732384 + 1 * 16 + 3 * 4 + 1] = uint8(c2da_fresh72 >> 0x8)
    c2da_mem[732384 + 1 * 16 + 3 * 4 + 2] = uint8(c2da_fresh72 >> 0x10)
    c2da_mem[732384 + 1 * 16 + 3 * 4 + 3] = uint8(c2da_fresh72 >> 0x18)
    let c2da_fresh73 : float = uint_bits_to_float(uint(c2da_mem[pmdl + 20 + 2 * 4]) | uint(c2da_mem[pmdl + 20 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pmdl + 20 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pmdl + 20 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh74 : uint = float_bits_to_uint(c2da_fresh73)
    c2da_mem[732384 + 2 * 16 + 3 * 4] = uint8(c2da_fresh74)
    c2da_mem[732384 + 2 * 16 + 3 * 4 + 1] = uint8(c2da_fresh74 >> 0x8)
    c2da_mem[732384 + 2 * 16 + 3 * 4 + 2] = uint8(c2da_fresh74 >> 0x10)
    c2da_mem[732384 + 2 * 16 + 3 * 4 + 3] = uint8(c2da_fresh74 >> 0x18)
    i_2 = 0
    while (i_2 < 3) {
        let c2da_fresh75 : float = uint_bits_to_float(uint(c2da_mem[732336 + i_2 * 4]) | uint(c2da_mem[732336 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[732336 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[732336 + i_2 * 4 + 3]) << 0x18)
        let c2da_fresh76 : uint = float_bits_to_uint(c2da_fresh75)
        c2da_mem[c2da_fp + 16 + i_2 * 16 + 0 * 4] = uint8(c2da_fresh76)
        c2da_mem[c2da_fp + 16 + i_2 * 16 + 0 * 4 + 1] = uint8(c2da_fresh76 >> 0x8)
        c2da_mem[c2da_fp + 16 + i_2 * 16 + 0 * 4 + 2] = uint8(c2da_fresh76 >> 0x10)
        c2da_mem[c2da_fp + 16 + i_2 * 16 + 0 * 4 + 3] = uint8(c2da_fresh76 >> 0x18)
        let c2da_fresh77 : float = -uint_bits_to_float(uint(c2da_mem[732352 + i_2 * 4]) | uint(c2da_mem[732352 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[732352 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[732352 + i_2 * 4 + 3]) << 0x18)
        let c2da_fresh78 : uint = float_bits_to_uint(c2da_fresh77)
        c2da_mem[c2da_fp + 16 + i_2 * 16 + 1 * 4] = uint8(c2da_fresh78)
        c2da_mem[c2da_fp + 16 + i_2 * 16 + 1 * 4 + 1] = uint8(c2da_fresh78 >> 0x8)
        c2da_mem[c2da_fp + 16 + i_2 * 16 + 1 * 4 + 2] = uint8(c2da_fresh78 >> 0x10)
        c2da_mem[c2da_fp + 16 + i_2 * 16 + 1 * 4 + 3] = uint8(c2da_fresh78 >> 0x18)
        let c2da_fresh79 : float = uint_bits_to_float(uint(c2da_mem[732368 + i_2 * 4]) | uint(c2da_mem[732368 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[732368 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[732368 + i_2 * 4 + 3]) << 0x18)
        let c2da_fresh80 : uint = float_bits_to_uint(c2da_fresh79)
        c2da_mem[c2da_fp + 16 + i_2 * 16 + 2 * 4] = uint8(c2da_fresh80)
        c2da_mem[c2da_fp + 16 + i_2 * 16 + 2 * 4 + 1] = uint8(c2da_fresh80 >> 0x8)
        c2da_mem[c2da_fp + 16 + i_2 * 16 + 2 * 4 + 2] = uint8(c2da_fresh80 >> 0x10)
        c2da_mem[c2da_fp + 16 + i_2 * 16 + 2 * 4 + 3] = uint8(c2da_fresh80 >> 0x18)
        i_2++
    }
    let c2da_fresh81 : float = -uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh82 : uint = float_bits_to_uint(c2da_fresh81)
    c2da_mem[c2da_fp + 16 + 0 * 16 + 3 * 4] = uint8(c2da_fresh82)
    c2da_mem[c2da_fp + 16 + 0 * 16 + 3 * 4 + 1] = uint8(c2da_fresh82 >> 0x8)
    c2da_mem[c2da_fp + 16 + 0 * 16 + 3 * 4 + 2] = uint8(c2da_fresh82 >> 0x10)
    c2da_mem[c2da_fp + 16 + 0 * 16 + 3 * 4 + 3] = uint8(c2da_fresh82 >> 0x18)
    let c2da_fresh83 : float = -uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh84 : uint = float_bits_to_uint(c2da_fresh83)
    c2da_mem[c2da_fp + 16 + 1 * 16 + 3 * 4] = uint8(c2da_fresh84)
    c2da_mem[c2da_fp + 16 + 1 * 16 + 3 * 4 + 1] = uint8(c2da_fresh84 >> 0x8)
    c2da_mem[c2da_fp + 16 + 1 * 16 + 3 * 4 + 2] = uint8(c2da_fresh84 >> 0x10)
    c2da_mem[c2da_fp + 16 + 1 * 16 + 3 * 4 + 3] = uint8(c2da_fresh84 >> 0x18)
    let c2da_fresh85 : float = -uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh86 : uint = float_bits_to_uint(c2da_fresh85)
    c2da_mem[c2da_fp + 16 + 2 * 16 + 3 * 4] = uint8(c2da_fresh86)
    c2da_mem[c2da_fp + 16 + 2 * 16 + 3 * 4 + 1] = uint8(c2da_fresh86 >> 0x8)
    c2da_mem[c2da_fp + 16 + 2 * 16 + 3 * 4 + 2] = uint8(c2da_fresh86 >> 0x10)
    c2da_mem[c2da_fp + 16 + 2 * 16 + 3 * 4 + 3] = uint8(c2da_fresh86 >> 0x18)
    R_ConcatTransforms(c2da_fp + 16, 732384, c2da_fp + 64)
    let c2da_fresh87 : float = uint_bits_to_float(uint(c2da_mem[244144 + 0 * 4]) | uint(c2da_mem[244144 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh88 : uint = float_bits_to_uint(c2da_fresh87)
    c2da_mem[732432 + 0 * 16 + 0 * 4] = uint8(c2da_fresh88)
    c2da_mem[732432 + 0 * 16 + 0 * 4 + 1] = uint8(c2da_fresh88 >> 0x8)
    c2da_mem[732432 + 0 * 16 + 0 * 4 + 2] = uint8(c2da_fresh88 >> 0x10)
    c2da_mem[732432 + 0 * 16 + 0 * 4 + 3] = uint8(c2da_fresh88 >> 0x18)
    let c2da_fresh89 : float = uint_bits_to_float(uint(c2da_mem[244144 + 1 * 4]) | uint(c2da_mem[244144 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh90 : uint = float_bits_to_uint(c2da_fresh89)
    c2da_mem[732432 + 0 * 16 + 1 * 4] = uint8(c2da_fresh90)
    c2da_mem[732432 + 0 * 16 + 1 * 4 + 1] = uint8(c2da_fresh90 >> 0x8)
    c2da_mem[732432 + 0 * 16 + 1 * 4 + 2] = uint8(c2da_fresh90 >> 0x10)
    c2da_mem[732432 + 0 * 16 + 1 * 4 + 3] = uint8(c2da_fresh90 >> 0x18)
    let c2da_fresh91 : float = uint_bits_to_float(uint(c2da_mem[244144 + 2 * 4]) | uint(c2da_mem[244144 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh92 : uint = float_bits_to_uint(c2da_fresh91)
    c2da_mem[732432 + 0 * 16 + 2 * 4] = uint8(c2da_fresh92)
    c2da_mem[732432 + 0 * 16 + 2 * 4 + 1] = uint8(c2da_fresh92 >> 0x8)
    c2da_mem[732432 + 0 * 16 + 2 * 4 + 2] = uint8(c2da_fresh92 >> 0x10)
    c2da_mem[732432 + 0 * 16 + 2 * 4 + 3] = uint8(c2da_fresh92 >> 0x18)
    let c2da_fresh93 : float = uint_bits_to_float(uint(c2da_mem[244160 + 0 * 4]) | uint(c2da_mem[244160 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh94 : uint = float_bits_to_uint(c2da_fresh93)
    c2da_mem[732432 + 1 * 16 + 0 * 4] = uint8(c2da_fresh94)
    c2da_mem[732432 + 1 * 16 + 0 * 4 + 1] = uint8(c2da_fresh94 >> 0x8)
    c2da_mem[732432 + 1 * 16 + 0 * 4 + 2] = uint8(c2da_fresh94 >> 0x10)
    c2da_mem[732432 + 1 * 16 + 0 * 4 + 3] = uint8(c2da_fresh94 >> 0x18)
    let c2da_fresh95 : float = uint_bits_to_float(uint(c2da_mem[244160 + 1 * 4]) | uint(c2da_mem[244160 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh96 : uint = float_bits_to_uint(c2da_fresh95)
    c2da_mem[732432 + 1 * 16 + 1 * 4] = uint8(c2da_fresh96)
    c2da_mem[732432 + 1 * 16 + 1 * 4 + 1] = uint8(c2da_fresh96 >> 0x8)
    c2da_mem[732432 + 1 * 16 + 1 * 4 + 2] = uint8(c2da_fresh96 >> 0x10)
    c2da_mem[732432 + 1 * 16 + 1 * 4 + 3] = uint8(c2da_fresh96 >> 0x18)
    let c2da_fresh97 : float = uint_bits_to_float(uint(c2da_mem[244160 + 2 * 4]) | uint(c2da_mem[244160 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh98 : uint = float_bits_to_uint(c2da_fresh97)
    c2da_mem[732432 + 1 * 16 + 2 * 4] = uint8(c2da_fresh98)
    c2da_mem[732432 + 1 * 16 + 2 * 4 + 1] = uint8(c2da_fresh98 >> 0x8)
    c2da_mem[732432 + 1 * 16 + 2 * 4 + 2] = uint8(c2da_fresh98 >> 0x10)
    c2da_mem[732432 + 1 * 16 + 2 * 4 + 3] = uint8(c2da_fresh98 >> 0x18)
    VectorInverse(732432 + 1 * 16)
    let c2da_fresh99 : float = uint_bits_to_float(uint(c2da_mem[244128 + 0 * 4]) | uint(c2da_mem[244128 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh100 : uint = float_bits_to_uint(c2da_fresh99)
    c2da_mem[732432 + 2 * 16 + 0 * 4] = uint8(c2da_fresh100)
    c2da_mem[732432 + 2 * 16 + 0 * 4 + 1] = uint8(c2da_fresh100 >> 0x8)
    c2da_mem[732432 + 2 * 16 + 0 * 4 + 2] = uint8(c2da_fresh100 >> 0x10)
    c2da_mem[732432 + 2 * 16 + 0 * 4 + 3] = uint8(c2da_fresh100 >> 0x18)
    let c2da_fresh101 : float = uint_bits_to_float(uint(c2da_mem[244128 + 1 * 4]) | uint(c2da_mem[244128 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh102 : uint = float_bits_to_uint(c2da_fresh101)
    c2da_mem[732432 + 2 * 16 + 1 * 4] = uint8(c2da_fresh102)
    c2da_mem[732432 + 2 * 16 + 1 * 4 + 1] = uint8(c2da_fresh102 >> 0x8)
    c2da_mem[732432 + 2 * 16 + 1 * 4 + 2] = uint8(c2da_fresh102 >> 0x10)
    c2da_mem[732432 + 2 * 16 + 1 * 4 + 3] = uint8(c2da_fresh102 >> 0x18)
    let c2da_fresh103 : float = uint_bits_to_float(uint(c2da_mem[244128 + 2 * 4]) | uint(c2da_mem[244128 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh104 : uint = float_bits_to_uint(c2da_fresh103)
    c2da_mem[732432 + 2 * 16 + 2 * 4] = uint8(c2da_fresh104)
    c2da_mem[732432 + 2 * 16 + 2 * 4 + 1] = uint8(c2da_fresh104 >> 0x8)
    c2da_mem[732432 + 2 * 16 + 2 * 4 + 2] = uint8(c2da_fresh104 >> 0x10)
    c2da_mem[732432 + 2 * 16 + 2 * 4 + 3] = uint8(c2da_fresh104 >> 0x18)
    R_ConcatTransforms(732432, c2da_fp + 64, 391344)
    if (trivial_accept != 0) {
        i_2 = 0
        for (c2da_i_2 in range(i_2, 4)) {
            let c2da_fresh105 : float = float(double(uint_bits_to_float(uint(c2da_mem[391344 + 0 * 16 + c2da_i_2 * 4]) | uint(c2da_mem[391344 + 0 * 16 + c2da_i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 0 * 16 + c2da_i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 0 * 16 + c2da_i_2 * 4 + 3]) << 0x18)) * (double(aliasxscale) * (1.0lf / double(32768.0 * 65536.0))))
            let c2da_fresh106 : uint = float_bits_to_uint(c2da_fresh105)
            c2da_mem[391344 + 0 * 16 + c2da_i_2 * 4] = uint8(c2da_fresh106)
            c2da_mem[391344 + 0 * 16 + c2da_i_2 * 4 + 1] = uint8(c2da_fresh106 >> 0x8)
            c2da_mem[391344 + 0 * 16 + c2da_i_2 * 4 + 2] = uint8(c2da_fresh106 >> 0x10)
            c2da_mem[391344 + 0 * 16 + c2da_i_2 * 4 + 3] = uint8(c2da_fresh106 >> 0x18)
            let c2da_fresh107 : float = float(double(uint_bits_to_float(uint(c2da_mem[391344 + 1 * 16 + c2da_i_2 * 4]) | uint(c2da_mem[391344 + 1 * 16 + c2da_i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 1 * 16 + c2da_i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 1 * 16 + c2da_i_2 * 4 + 3]) << 0x18)) * (double(aliasyscale) * (1.0lf / double(32768.0 * 65536.0))))
            let c2da_fresh108 : uint = float_bits_to_uint(c2da_fresh107)
            c2da_mem[391344 + 1 * 16 + c2da_i_2 * 4] = uint8(c2da_fresh108)
            c2da_mem[391344 + 1 * 16 + c2da_i_2 * 4 + 1] = uint8(c2da_fresh108 >> 0x8)
            c2da_mem[391344 + 1 * 16 + c2da_i_2 * 4 + 2] = uint8(c2da_fresh108 >> 0x10)
            c2da_mem[391344 + 1 * 16 + c2da_i_2 * 4 + 3] = uint8(c2da_fresh108 >> 0x18)
            let c2da_fresh109 : float = float(double(uint_bits_to_float(uint(c2da_mem[391344 + 2 * 16 + c2da_i_2 * 4]) | uint(c2da_mem[391344 + 2 * 16 + c2da_i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[391344 + 2 * 16 + c2da_i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[391344 + 2 * 16 + c2da_i_2 * 4 + 3]) << 0x18)) * (1.0lf / double(32768.0 * 65536.0)))
            let c2da_fresh110 : uint = float_bits_to_uint(c2da_fresh109)
            c2da_mem[391344 + 2 * 16 + c2da_i_2 * 4] = uint8(c2da_fresh110)
            c2da_mem[391344 + 2 * 16 + c2da_i_2 * 4 + 1] = uint8(c2da_fresh110 >> 0x8)
            c2da_mem[391344 + 2 * 16 + c2da_i_2 * 4 + 2] = uint8(c2da_fresh110 >> 0x10)
            c2da_mem[391344 + 2 * 16 + c2da_i_2 * 4 + 3] = uint8(c2da_fresh110 >> 0x18)
        }
    }
    return
}
[sideeffects]
def private R_AliasCheckBBox_c2da_frame(c2da_fp : int) : uint {
    var i_4 : int
    var flags : int
    var frame_0 : int
    var numv : int
    var pahdr : int
    var zi_1 : float
    var v0 : float
    var v1 : float
    var frac : float
    var pv0 : int
    var pv1 : int
    var pa0 : int
    var pa1 : int
    var pframedesc : int
    var zclipped : uint
    var zfullyclipped : uint
    var anyclip : uint
    var allclip : uint
    var minz : int
    let c2da_fresh111 : int = 0
    let c2da_fresh112 : uint = uint(c2da_fresh111)
    c2da_mem[currententity + 188] = uint8(c2da_fresh112)
    c2da_mem[currententity + 189] = uint8(c2da_fresh112 >> 0x8)
    c2da_mem[currententity + 190] = uint8(c2da_fresh112 >> 0x10)
    c2da_mem[currententity + 191] = uint8(c2da_fresh112 >> 0x18)
    pmodel = int(uint(c2da_mem[currententity + 136]) | uint(c2da_mem[currententity + 137]) << 0x8 | uint(c2da_mem[currententity + 138]) << 0x10 | uint(c2da_mem[currententity + 139]) << 0x18)
    pahdr = Mod_Extradata(pmodel)
    pmdl = pahdr + int(uint(c2da_mem[pahdr]) | uint(c2da_mem[pahdr + 1]) << 0x8 | uint(c2da_mem[pahdr + 2]) << 0x10 | uint(c2da_mem[pahdr + 3]) << 0x18)
    R_AliasSetUpTransform(0)
    frame_0 = int(uint(c2da_mem[currententity + 152]) | uint(c2da_mem[currententity + 153]) << 0x8 | uint(c2da_mem[currententity + 154]) << 0x10 | uint(c2da_mem[currententity + 155]) << 0x18)
    if (frame_0 >= int(uint(c2da_mem[pmdl + 68]) | uint(c2da_mem[pmdl + 69]) << 0x8 | uint(c2da_mem[pmdl + 70]) << 0x10 | uint(c2da_mem[pmdl + 71]) << 0x18) || frame_0 < 0) {
        Con_DPrintf(732597, [C2daVaArg(tag = 1, i64 = int64(frame_0), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pmodel))])
        frame_0 = 0
    }
    pframedesc = pahdr + 16 + frame_0 * 32
    let c2da_fresh113 : float = float(c2da_mem[pframedesc + 4 + 0])
    let c2da_fresh114 : uint = float_bits_to_uint(c2da_fresh113)
    c2da_mem[c2da_fp + 3 * 12 + 0 * 4] = uint8(c2da_fresh114)
    c2da_mem[c2da_fp + 3 * 12 + 0 * 4 + 1] = uint8(c2da_fresh114 >> 0x8)
    c2da_mem[c2da_fp + 3 * 12 + 0 * 4 + 2] = uint8(c2da_fresh114 >> 0x10)
    c2da_mem[c2da_fp + 3 * 12 + 0 * 4 + 3] = uint8(c2da_fresh114 >> 0x18)
    let c2da_fresh115 : uint = float_bits_to_uint(c2da_fresh113)
    c2da_mem[c2da_fp + 2 * 12 + 0 * 4] = uint8(c2da_fresh115)
    c2da_mem[c2da_fp + 2 * 12 + 0 * 4 + 1] = uint8(c2da_fresh115 >> 0x8)
    c2da_mem[c2da_fp + 2 * 12 + 0 * 4 + 2] = uint8(c2da_fresh115 >> 0x10)
    c2da_mem[c2da_fp + 2 * 12 + 0 * 4 + 3] = uint8(c2da_fresh115 >> 0x18)
    let c2da_fresh116 : uint = float_bits_to_uint(c2da_fresh113)
    c2da_mem[c2da_fp + 1 * 12 + 0 * 4] = uint8(c2da_fresh116)
    c2da_mem[c2da_fp + 1 * 12 + 0 * 4 + 1] = uint8(c2da_fresh116 >> 0x8)
    c2da_mem[c2da_fp + 1 * 12 + 0 * 4 + 2] = uint8(c2da_fresh116 >> 0x10)
    c2da_mem[c2da_fp + 1 * 12 + 0 * 4 + 3] = uint8(c2da_fresh116 >> 0x18)
    let c2da_fresh117 : uint = float_bits_to_uint(c2da_fresh113)
    c2da_mem[c2da_fp + 0 * 12 + 0 * 4] = uint8(c2da_fresh117)
    c2da_mem[c2da_fp + 0 * 12 + 0 * 4 + 1] = uint8(c2da_fresh117 >> 0x8)
    c2da_mem[c2da_fp + 0 * 12 + 0 * 4 + 2] = uint8(c2da_fresh117 >> 0x10)
    c2da_mem[c2da_fp + 0 * 12 + 0 * 4 + 3] = uint8(c2da_fresh117 >> 0x18)
    let c2da_fresh118 : float = float(c2da_mem[pframedesc + 8 + 0])
    let c2da_fresh119 : uint = float_bits_to_uint(c2da_fresh118)
    c2da_mem[c2da_fp + 7 * 12 + 0 * 4] = uint8(c2da_fresh119)
    c2da_mem[c2da_fp + 7 * 12 + 0 * 4 + 1] = uint8(c2da_fresh119 >> 0x8)
    c2da_mem[c2da_fp + 7 * 12 + 0 * 4 + 2] = uint8(c2da_fresh119 >> 0x10)
    c2da_mem[c2da_fp + 7 * 12 + 0 * 4 + 3] = uint8(c2da_fresh119 >> 0x18)
    let c2da_fresh120 : uint = float_bits_to_uint(c2da_fresh118)
    c2da_mem[c2da_fp + 6 * 12 + 0 * 4] = uint8(c2da_fresh120)
    c2da_mem[c2da_fp + 6 * 12 + 0 * 4 + 1] = uint8(c2da_fresh120 >> 0x8)
    c2da_mem[c2da_fp + 6 * 12 + 0 * 4 + 2] = uint8(c2da_fresh120 >> 0x10)
    c2da_mem[c2da_fp + 6 * 12 + 0 * 4 + 3] = uint8(c2da_fresh120 >> 0x18)
    let c2da_fresh121 : uint = float_bits_to_uint(c2da_fresh118)
    c2da_mem[c2da_fp + 5 * 12 + 0 * 4] = uint8(c2da_fresh121)
    c2da_mem[c2da_fp + 5 * 12 + 0 * 4 + 1] = uint8(c2da_fresh121 >> 0x8)
    c2da_mem[c2da_fp + 5 * 12 + 0 * 4 + 2] = uint8(c2da_fresh121 >> 0x10)
    c2da_mem[c2da_fp + 5 * 12 + 0 * 4 + 3] = uint8(c2da_fresh121 >> 0x18)
    let c2da_fresh122 : uint = float_bits_to_uint(c2da_fresh118)
    c2da_mem[c2da_fp + 4 * 12 + 0 * 4] = uint8(c2da_fresh122)
    c2da_mem[c2da_fp + 4 * 12 + 0 * 4 + 1] = uint8(c2da_fresh122 >> 0x8)
    c2da_mem[c2da_fp + 4 * 12 + 0 * 4 + 2] = uint8(c2da_fresh122 >> 0x10)
    c2da_mem[c2da_fp + 4 * 12 + 0 * 4 + 3] = uint8(c2da_fresh122 >> 0x18)
    let c2da_fresh123 : float = float(c2da_mem[pframedesc + 4 + 1])
    let c2da_fresh124 : uint = float_bits_to_uint(c2da_fresh123)
    c2da_mem[c2da_fp + 6 * 12 + 1 * 4] = uint8(c2da_fresh124)
    c2da_mem[c2da_fp + 6 * 12 + 1 * 4 + 1] = uint8(c2da_fresh124 >> 0x8)
    c2da_mem[c2da_fp + 6 * 12 + 1 * 4 + 2] = uint8(c2da_fresh124 >> 0x10)
    c2da_mem[c2da_fp + 6 * 12 + 1 * 4 + 3] = uint8(c2da_fresh124 >> 0x18)
    let c2da_fresh125 : uint = float_bits_to_uint(c2da_fresh123)
    c2da_mem[c2da_fp + 5 * 12 + 1 * 4] = uint8(c2da_fresh125)
    c2da_mem[c2da_fp + 5 * 12 + 1 * 4 + 1] = uint8(c2da_fresh125 >> 0x8)
    c2da_mem[c2da_fp + 5 * 12 + 1 * 4 + 2] = uint8(c2da_fresh125 >> 0x10)
    c2da_mem[c2da_fp + 5 * 12 + 1 * 4 + 3] = uint8(c2da_fresh125 >> 0x18)
    let c2da_fresh126 : uint = float_bits_to_uint(c2da_fresh123)
    c2da_mem[c2da_fp + 3 * 12 + 1 * 4] = uint8(c2da_fresh126)
    c2da_mem[c2da_fp + 3 * 12 + 1 * 4 + 1] = uint8(c2da_fresh126 >> 0x8)
    c2da_mem[c2da_fp + 3 * 12 + 1 * 4 + 2] = uint8(c2da_fresh126 >> 0x10)
    c2da_mem[c2da_fp + 3 * 12 + 1 * 4 + 3] = uint8(c2da_fresh126 >> 0x18)
    let c2da_fresh127 : uint = float_bits_to_uint(c2da_fresh123)
    c2da_mem[c2da_fp + 0 * 12 + 1 * 4] = uint8(c2da_fresh127)
    c2da_mem[c2da_fp + 0 * 12 + 1 * 4 + 1] = uint8(c2da_fresh127 >> 0x8)
    c2da_mem[c2da_fp + 0 * 12 + 1 * 4 + 2] = uint8(c2da_fresh127 >> 0x10)
    c2da_mem[c2da_fp + 0 * 12 + 1 * 4 + 3] = uint8(c2da_fresh127 >> 0x18)
    let c2da_fresh128 : float = float(c2da_mem[pframedesc + 8 + 1])
    let c2da_fresh129 : uint = float_bits_to_uint(c2da_fresh128)
    c2da_mem[c2da_fp + 7 * 12 + 1 * 4] = uint8(c2da_fresh129)
    c2da_mem[c2da_fp + 7 * 12 + 1 * 4 + 1] = uint8(c2da_fresh129 >> 0x8)
    c2da_mem[c2da_fp + 7 * 12 + 1 * 4 + 2] = uint8(c2da_fresh129 >> 0x10)
    c2da_mem[c2da_fp + 7 * 12 + 1 * 4 + 3] = uint8(c2da_fresh129 >> 0x18)
    let c2da_fresh130 : uint = float_bits_to_uint(c2da_fresh128)
    c2da_mem[c2da_fp + 4 * 12 + 1 * 4] = uint8(c2da_fresh130)
    c2da_mem[c2da_fp + 4 * 12 + 1 * 4 + 1] = uint8(c2da_fresh130 >> 0x8)
    c2da_mem[c2da_fp + 4 * 12 + 1 * 4 + 2] = uint8(c2da_fresh130 >> 0x10)
    c2da_mem[c2da_fp + 4 * 12 + 1 * 4 + 3] = uint8(c2da_fresh130 >> 0x18)
    let c2da_fresh131 : uint = float_bits_to_uint(c2da_fresh128)
    c2da_mem[c2da_fp + 2 * 12 + 1 * 4] = uint8(c2da_fresh131)
    c2da_mem[c2da_fp + 2 * 12 + 1 * 4 + 1] = uint8(c2da_fresh131 >> 0x8)
    c2da_mem[c2da_fp + 2 * 12 + 1 * 4 + 2] = uint8(c2da_fresh131 >> 0x10)
    c2da_mem[c2da_fp + 2 * 12 + 1 * 4 + 3] = uint8(c2da_fresh131 >> 0x18)
    let c2da_fresh132 : uint = float_bits_to_uint(c2da_fresh128)
    c2da_mem[c2da_fp + 1 * 12 + 1 * 4] = uint8(c2da_fresh132)
    c2da_mem[c2da_fp + 1 * 12 + 1 * 4 + 1] = uint8(c2da_fresh132 >> 0x8)
    c2da_mem[c2da_fp + 1 * 12 + 1 * 4 + 2] = uint8(c2da_fresh132 >> 0x10)
    c2da_mem[c2da_fp + 1 * 12 + 1 * 4 + 3] = uint8(c2da_fresh132 >> 0x18)
    let c2da_fresh133 : float = float(c2da_mem[pframedesc + 4 + 2])
    let c2da_fresh134 : uint = float_bits_to_uint(c2da_fresh133)
    c2da_mem[c2da_fp + 5 * 12 + 2 * 4] = uint8(c2da_fresh134)
    c2da_mem[c2da_fp + 5 * 12 + 2 * 4 + 1] = uint8(c2da_fresh134 >> 0x8)
    c2da_mem[c2da_fp + 5 * 12 + 2 * 4 + 2] = uint8(c2da_fresh134 >> 0x10)
    c2da_mem[c2da_fp + 5 * 12 + 2 * 4 + 3] = uint8(c2da_fresh134 >> 0x18)
    let c2da_fresh135 : uint = float_bits_to_uint(c2da_fresh133)
    c2da_mem[c2da_fp + 4 * 12 + 2 * 4] = uint8(c2da_fresh135)
    c2da_mem[c2da_fp + 4 * 12 + 2 * 4 + 1] = uint8(c2da_fresh135 >> 0x8)
    c2da_mem[c2da_fp + 4 * 12 + 2 * 4 + 2] = uint8(c2da_fresh135 >> 0x10)
    c2da_mem[c2da_fp + 4 * 12 + 2 * 4 + 3] = uint8(c2da_fresh135 >> 0x18)
    let c2da_fresh136 : uint = float_bits_to_uint(c2da_fresh133)
    c2da_mem[c2da_fp + 1 * 12 + 2 * 4] = uint8(c2da_fresh136)
    c2da_mem[c2da_fp + 1 * 12 + 2 * 4 + 1] = uint8(c2da_fresh136 >> 0x8)
    c2da_mem[c2da_fp + 1 * 12 + 2 * 4 + 2] = uint8(c2da_fresh136 >> 0x10)
    c2da_mem[c2da_fp + 1 * 12 + 2 * 4 + 3] = uint8(c2da_fresh136 >> 0x18)
    let c2da_fresh137 : uint = float_bits_to_uint(c2da_fresh133)
    c2da_mem[c2da_fp + 0 * 12 + 2 * 4] = uint8(c2da_fresh137)
    c2da_mem[c2da_fp + 0 * 12 + 2 * 4 + 1] = uint8(c2da_fresh137 >> 0x8)
    c2da_mem[c2da_fp + 0 * 12 + 2 * 4 + 2] = uint8(c2da_fresh137 >> 0x10)
    c2da_mem[c2da_fp + 0 * 12 + 2 * 4 + 3] = uint8(c2da_fresh137 >> 0x18)
    let c2da_fresh138 : float = float(c2da_mem[pframedesc + 8 + 2])
    let c2da_fresh139 : uint = float_bits_to_uint(c2da_fresh138)
    c2da_mem[c2da_fp + 7 * 12 + 2 * 4] = uint8(c2da_fresh139)
    c2da_mem[c2da_fp + 7 * 12 + 2 * 4 + 1] = uint8(c2da_fresh139 >> 0x8)
    c2da_mem[c2da_fp + 7 * 12 + 2 * 4 + 2] = uint8(c2da_fresh139 >> 0x10)
    c2da_mem[c2da_fp + 7 * 12 + 2 * 4 + 3] = uint8(c2da_fresh139 >> 0x18)
    let c2da_fresh140 : uint = float_bits_to_uint(c2da_fresh138)
    c2da_mem[c2da_fp + 6 * 12 + 2 * 4] = uint8(c2da_fresh140)
    c2da_mem[c2da_fp + 6 * 12 + 2 * 4 + 1] = uint8(c2da_fresh140 >> 0x8)
    c2da_mem[c2da_fp + 6 * 12 + 2 * 4 + 2] = uint8(c2da_fresh140 >> 0x10)
    c2da_mem[c2da_fp + 6 * 12 + 2 * 4 + 3] = uint8(c2da_fresh140 >> 0x18)
    let c2da_fresh141 : uint = float_bits_to_uint(c2da_fresh138)
    c2da_mem[c2da_fp + 3 * 12 + 2 * 4] = uint8(c2da_fresh141)
    c2da_mem[c2da_fp + 3 * 12 + 2 * 4 + 1] = uint8(c2da_fresh141 >> 0x8)
    c2da_mem[c2da_fp + 3 * 12 + 2 * 4 + 2] = uint8(c2da_fresh141 >> 0x10)
    c2da_mem[c2da_fp + 3 * 12 + 2 * 4 + 3] = uint8(c2da_fresh141 >> 0x18)
    let c2da_fresh142 : uint = float_bits_to_uint(c2da_fresh138)
    c2da_mem[c2da_fp + 2 * 12 + 2 * 4] = uint8(c2da_fresh142)
    c2da_mem[c2da_fp + 2 * 12 + 2 * 4 + 1] = uint8(c2da_fresh142 >> 0x8)
    c2da_mem[c2da_fp + 2 * 12 + 2 * 4 + 2] = uint8(c2da_fresh142 >> 0x10)
    c2da_mem[c2da_fp + 2 * 12 + 2 * 4 + 3] = uint8(c2da_fresh142 >> 0x18)
    zclipped = 0u
    zfullyclipped = 1u
    minz = 9999
    i_4 = 0
    while (i_4 < 8) {
        R_AliasTransformVector(c2da_fp + i_4 * 12 + 0 * 4, c2da_fp + 96 + i_4 * 12 + 0 * 4)
        if (uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + i_4 * 12 + 2 * 4]) | uint(c2da_mem[c2da_fp + 96 + i_4 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + i_4 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + i_4 * 12 + 2 * 4 + 3]) << 0x18) < 5.0) {
            let c2da_fresh143 : int = 16
            let c2da_fresh144 : uint = uint(c2da_fresh143)
            c2da_mem[c2da_fp + 288 + i_4 * 32 + 24] = uint8(c2da_fresh144)
            c2da_mem[c2da_fp + 288 + i_4 * 32 + 25] = uint8(c2da_fresh144 >> 0x8)
            c2da_mem[c2da_fp + 288 + i_4 * 32 + 26] = uint8(c2da_fresh144 >> 0x10)
            c2da_mem[c2da_fp + 288 + i_4 * 32 + 27] = uint8(c2da_fresh144 >> 0x18)
            zclipped = 1u
        } else {
            if (uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + i_4 * 12 + 2 * 4]) | uint(c2da_mem[c2da_fp + 96 + i_4 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + i_4 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + i_4 * 12 + 2 * 4 + 3]) << 0x18) < float(minz)) {
                minz = int(uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + i_4 * 12 + 2 * 4]) | uint(c2da_mem[c2da_fp + 96 + i_4 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + i_4 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + i_4 * 12 + 2 * 4 + 3]) << 0x18))
            }
            let c2da_fresh145 : int = 0
            let c2da_fresh146 : uint = uint(c2da_fresh145)
            c2da_mem[c2da_fp + 288 + i_4 * 32 + 24] = uint8(c2da_fresh146)
            c2da_mem[c2da_fp + 288 + i_4 * 32 + 25] = uint8(c2da_fresh146 >> 0x8)
            c2da_mem[c2da_fp + 288 + i_4 * 32 + 26] = uint8(c2da_fresh146 >> 0x10)
            c2da_mem[c2da_fp + 288 + i_4 * 32 + 27] = uint8(c2da_fresh146 >> 0x18)
            zfullyclipped = 0u
        }
        i_4++
    }
    if (zfullyclipped != 0u) {
        return 0u
    }
    numv = 8
    if (zclipped != 0u) {
        i_4 = 0
        while (i_4 < 12) {
            pv0 = c2da_fp + 288 + aedges[i_4].index0 * 32
            pv1 = c2da_fp + 288 + aedges[i_4].index1 * 32
            pa0 = c2da_fp + 96 + aedges[i_4].index0 * 12
            pa1 = c2da_fp + 96 + aedges[i_4].index1 * 12
            if ((int(uint(c2da_mem[pv0 + 24]) | uint(c2da_mem[pv0 + 25]) << 0x8 | uint(c2da_mem[pv0 + 26]) << 0x10 | uint(c2da_mem[pv0 + 27]) << 0x18) ^ int(uint(c2da_mem[pv1 + 24]) | uint(c2da_mem[pv1 + 25]) << 0x8 | uint(c2da_mem[pv1 + 26]) << 0x10 | uint(c2da_mem[pv1 + 27]) << 0x18)) != 0) {
                frac = (5.0 - uint_bits_to_float(uint(c2da_mem[pa0 + 2 * 4]) | uint(c2da_mem[pa0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pa0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pa0 + 2 * 4 + 3]) << 0x18)) / (uint_bits_to_float(uint(c2da_mem[pa1 + 2 * 4]) | uint(c2da_mem[pa1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pa1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pa1 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[pa0 + 2 * 4]) | uint(c2da_mem[pa0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pa0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pa0 + 2 * 4 + 3]) << 0x18))
                let c2da_fresh147 : float = uint_bits_to_float(uint(c2da_mem[pa0 + 0 * 4]) | uint(c2da_mem[pa0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pa0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pa0 + 0 * 4 + 3]) << 0x18) + (uint_bits_to_float(uint(c2da_mem[pa1 + 0 * 4]) | uint(c2da_mem[pa1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pa1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pa1 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[pa0 + 0 * 4]) | uint(c2da_mem[pa0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pa0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pa0 + 0 * 4 + 3]) << 0x18)) * frac
                let c2da_fresh148 : uint = float_bits_to_uint(c2da_fresh147)
                c2da_mem[c2da_fp + 96 + numv * 12 + 0 * 4] = uint8(c2da_fresh148)
                c2da_mem[c2da_fp + 96 + numv * 12 + 0 * 4 + 1] = uint8(c2da_fresh148 >> 0x8)
                c2da_mem[c2da_fp + 96 + numv * 12 + 0 * 4 + 2] = uint8(c2da_fresh148 >> 0x10)
                c2da_mem[c2da_fp + 96 + numv * 12 + 0 * 4 + 3] = uint8(c2da_fresh148 >> 0x18)
                let c2da_fresh149 : float = uint_bits_to_float(uint(c2da_mem[pa0 + 1 * 4]) | uint(c2da_mem[pa0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pa0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pa0 + 1 * 4 + 3]) << 0x18) + (uint_bits_to_float(uint(c2da_mem[pa1 + 1 * 4]) | uint(c2da_mem[pa1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pa1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pa1 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[pa0 + 1 * 4]) | uint(c2da_mem[pa0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pa0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pa0 + 1 * 4 + 3]) << 0x18)) * frac
                let c2da_fresh150 : uint = float_bits_to_uint(c2da_fresh149)
                c2da_mem[c2da_fp + 96 + numv * 12 + 1 * 4] = uint8(c2da_fresh150)
                c2da_mem[c2da_fp + 96 + numv * 12 + 1 * 4 + 1] = uint8(c2da_fresh150 >> 0x8)
                c2da_mem[c2da_fp + 96 + numv * 12 + 1 * 4 + 2] = uint8(c2da_fresh150 >> 0x10)
                c2da_mem[c2da_fp + 96 + numv * 12 + 1 * 4 + 3] = uint8(c2da_fresh150 >> 0x18)
                let c2da_fresh151 : float = 5.0
                let c2da_fresh152 : uint = float_bits_to_uint(c2da_fresh151)
                c2da_mem[c2da_fp + 96 + numv * 12 + 2 * 4] = uint8(c2da_fresh152)
                c2da_mem[c2da_fp + 96 + numv * 12 + 2 * 4 + 1] = uint8(c2da_fresh152 >> 0x8)
                c2da_mem[c2da_fp + 96 + numv * 12 + 2 * 4 + 2] = uint8(c2da_fresh152 >> 0x10)
                c2da_mem[c2da_fp + 96 + numv * 12 + 2 * 4 + 3] = uint8(c2da_fresh152 >> 0x18)
                let c2da_fresh153 : int = 0
                let c2da_fresh154 : uint = uint(c2da_fresh153)
                c2da_mem[c2da_fp + 288 + numv * 32 + 24] = uint8(c2da_fresh154)
                c2da_mem[c2da_fp + 288 + numv * 32 + 25] = uint8(c2da_fresh154 >> 0x8)
                c2da_mem[c2da_fp + 288 + numv * 32 + 26] = uint8(c2da_fresh154 >> 0x10)
                c2da_mem[c2da_fp + 288 + numv * 32 + 27] = uint8(c2da_fresh154 >> 0x18)
                numv++
            }
            i_4++
        }
    }
    anyclip = 0u
    allclip = 0xfu
    i_4 = 0
    for (c2da_i_4 in range(i_4, numv)) {
        if ((int(uint(c2da_mem[c2da_fp + 288 + c2da_i_4 * 32 + 24]) | uint(c2da_mem[c2da_fp + 288 + c2da_i_4 * 32 + 25]) << 0x8 | uint(c2da_mem[c2da_fp + 288 + c2da_i_4 * 32 + 26]) << 0x10 | uint(c2da_mem[c2da_fp + 288 + c2da_i_4 * 32 + 27]) << 0x18) & 16) != 0) {
            continue
        }
        zi_1 = float(1.0lf / double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + c2da_i_4 * 12 + 2 * 4]) | uint(c2da_mem[c2da_fp + 96 + c2da_i_4 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + c2da_i_4 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + c2da_i_4 * 12 + 2 * 4 + 3]) << 0x18)))
        v0 = uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + c2da_i_4 * 12 + 0 * 4]) | uint(c2da_mem[c2da_fp + 96 + c2da_i_4 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + c2da_i_4 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + c2da_i_4 * 12 + 0 * 4 + 3]) << 0x18) * xscale * zi_1 + xcenter
        v1 = uint_bits_to_float(uint(c2da_mem[c2da_fp + 96 + c2da_i_4 * 12 + 1 * 4]) | uint(c2da_mem[c2da_fp + 96 + c2da_i_4 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 96 + c2da_i_4 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 96 + c2da_i_4 * 12 + 1 * 4 + 3]) << 0x18) * yscale * zi_1 + ycenter
        flags = 0
        if (v0 < uint_bits_to_float(uint(c2da_mem[5268]) | uint(c2da_mem[5269]) << 0x8 | uint(c2da_mem[5270]) << 0x10 | uint(c2da_mem[5271]) << 0x18)) {
            flags |= 1
        }
        if (v1 < uint_bits_to_float(uint(c2da_mem[5272]) | uint(c2da_mem[5273]) << 0x8 | uint(c2da_mem[5274]) << 0x10 | uint(c2da_mem[5275]) << 0x18)) {
            flags |= 2
        }
        if (v0 > uint_bits_to_float(uint(c2da_mem[5300]) | uint(c2da_mem[5301]) << 0x8 | uint(c2da_mem[5302]) << 0x10 | uint(c2da_mem[5303]) << 0x18)) {
            flags |= 4
        }
        if (v1 > uint_bits_to_float(uint(c2da_mem[5304]) | uint(c2da_mem[5305]) << 0x8 | uint(c2da_mem[5306]) << 0x10 | uint(c2da_mem[5307]) << 0x18)) {
            flags |= 8
        }
        anyclip |= uint(flags)
        allclip &= uint(flags)
    }
    if (allclip != 0x0) {
        return 0u
    }
    let c2da_fresh155 : int = (anyclip == 0 ? 1 : 0) & (zclipped == 0u ? 1 : 0)
    let c2da_fresh156 : uint = uint(c2da_fresh155)
    c2da_mem[currententity + 188] = uint8(c2da_fresh156)
    c2da_mem[currententity + 189] = uint8(c2da_fresh156 >> 0x8)
    c2da_mem[currententity + 190] = uint8(c2da_fresh156 >> 0x10)
    c2da_mem[currententity + 191] = uint8(c2da_fresh156 >> 0x18)
    if (int(uint(c2da_mem[currententity + 188]) | uint(c2da_mem[currententity + 189]) << 0x8 | uint(c2da_mem[currententity + 190]) << 0x10 | uint(c2da_mem[currententity + 191]) << 0x18) != 0) {
        if (float(minz) > r_aliastransition + uint_bits_to_float(uint(c2da_mem[pmdl + 80]) | uint(c2da_mem[pmdl + 81]) << 0x8 | uint(c2da_mem[pmdl + 82]) << 0x10 | uint(c2da_mem[pmdl + 83]) << 0x18) * r_resfudge) {
            let c2da_fresh157 : int = int(uint(c2da_mem[currententity + 188]) | uint(c2da_mem[currententity + 189]) << 0x8 | uint(c2da_mem[currententity + 190]) << 0x10 | uint(c2da_mem[currententity + 191]) << 0x18) | 2
            let c2da_fresh158 : uint = uint(c2da_fresh157)
            c2da_mem[currententity + 188] = uint8(c2da_fresh158)
            c2da_mem[currententity + 189] = uint8(c2da_fresh158 >> 0x8)
            c2da_mem[currententity + 190] = uint8(c2da_fresh158 >> 0x10)
            c2da_mem[currententity + 191] = uint8(c2da_fresh158 >> 0x18)
        }
    }
    return 1u
}

// This unit's static data, at heap offset 732336.
let private c2da_lin_static_r_alias_seg = fixed_array<int>(732480, 137)
let private c2da_lin_static_r_alias = fixed_array<uint64>(0x447361696c415f52ul, 0x6c65646f4d776172ul, 0x657272756321203aul, 0x797469746e65746eul, 0x6d726f6c6f633e2dul, 0x696c415f52007061ul, 0x4670757465537361ul, 0x6f6e203a656d6172ul, 0x7266206863757320ul, 0xa642520656d61ul, 0x537361696c415f52ul, 0x6e696b5370757465ul, 0x637573206f6e203aul, 0x23206e696b732068ul, 0x206f4e000a642520ul, 0x6172662068637573ul, 0x732520642520656dul, 0xaul)

[init]
def private c2da_lin_init_static_r_alias() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_alias_seg[s * 2]
        for (k in range(c2da_lin_static_r_alias_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_alias[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_r_alias_0 = fixed_array<uint8>(0x4f, 0x96, 0x6, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x44, 0xc4, 0x59, 0x3f, 0xf0, 0xbe, 0xe2, 0xbe, 0xab, 0x96, 0x74, 0x3e, 0x6d, 0x3b, 0x5d, 0x3f, 0xf6, 0x29, 0x97, 0xbe, 0x0, 0x0, 0x0, 0x0, 0x9a, 0x96, 0x74, 0x3f, 0x7a, 0x37, 0x9e, 0xbe, 0x0, 0x0, 0x0, 0x3f, 0xbd, 0x1b, 0x4f, 0x3f, 0xea, 0x5b, 0x26, 0xbe, 0x5f, 0x96, 0x86, 0x3e, 0x68, 0x78, 0x73, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x44, 0xc4, 0x59, 0x3f, 0x4f, 0x96, 0x6, 0x3f, 0xf6, 0x29, 0x17, 0xbe, 0xef, 0x70, 0x37, 0x3f, 0x12, 0x85, 0x2e, 0x3f, 0xf6, 0x29, 0x17, 0x3e, 0xef, 0x70, 0x37, 0x3f, 0x12, 0x85, 0x2e, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x4f, 0x96, 0x6, 0x3f, 0x44, 0xc4, 0x59, 0x3f, 0x7a, 0x37, 0x9e, 0x3e, 0x0, 0x0, 0x0, 0x3f, 0xbd, 0x1b, 0x4f, 0x3f, 0x4f, 0x96, 0x6, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x44, 0xc4, 0x59, 0x3f, 0xf6, 0x29, 0x97, 0x3e, 0x0, 0x0, 0x0, 0x0, 0x9a, 0x96, 0x74, 0x3f, 0xf0, 0xbe, 0xe2, 0x3e, 0xab, 0x96, 0x74, 0x3e, 0x6d, 0x3b, 0x5d, 0x3f, 0xea, 0x5b, 0x26, 0x3e, 0x5f, 0x96, 0x86, 0x3e, 0x68, 0x78, 0x73, 0x3f, 0x12, 0x85, 0x2e, 0xbf, 0xf6, 0x29, 0x17, 0x3e, 0xef, 0x70, 0x37, 0x3f, 0xbd, 0x1b, 0x4f, 0xbf, 0x7a, 0x37, 0x9e, 0x3e, 0x0, 0x0, 0x0, 0x3f, 0x14, 0x79, 0x16, 0xbf, 0x33, 0xc4, 0xd9, 0x3e, 0x49, 0x2d, 0x30, 0x3f, 0x44, 0xc4, 0x59, 0xbf, 0x4f, 0x96, 0x6, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x6d, 0x3b, 0x5d, 0xbf, 0xf0, 0xbe, 0xe2, 0x3e, 0xab, 0x96, 0x74, 0x3e, 0xef, 0x70, 0x37, 0xbf, 0x12, 0x85, 0x2e, 0x3f, 0xf6, 0x29, 0x17, 0x3e, 0x49, 0x2d, 0x30, 0xbf, 0x14, 0x79, 0x16, 0x3f, 0x33, 0xc4, 0xd9, 0x3e, 0x0, 0x0, 0x0, 0xbf, 0xbd, 0x1b, 0x4f, 0x3f, 0x7a, 0x37, 0x9e, 0x3e, 0xab, 0x96, 0x74, 0xbe, 0x6d, 0x3b, 0x5d, 0x3f, 0xf0, 0xbe, 0xe2, 0x3e, 0x33, 0xc4, 0xd9, 0xbe, 0x49, 0x2d, 0x30, 0x3f, 0x14, 0x79, 0x16, 0x3f, 0xef, 0x70, 0x37, 0xbf, 0x12, 0x85, 0x2e, 0x3f, 0xf6, 0x29, 0x17, 0xbe, 0x0, 0x0, 0x0, 0xbf, 0xbd, 0x1b, 0x4f, 0x3f, 0x7a, 0x37, 0x9e, 0xbe, 0x4f, 0x96, 0x6, 0xbf, 0x44, 0xc4, 0x59, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x44, 0xc4, 0x59, 0x3f, 0x4f, 0x96, 0x6, 0xbf, 0xab, 0x96, 0x74, 0xbe, 0x6d, 0x3b, 0x5d, 0x3f, 0xf0, 0xbe, 0xe2, 0xbe, 0x0, 0x0, 0x0, 0x0, 0x9a, 0x96, 0x74, 0x3f, 0xf6, 0x29, 0x97, 0xbe, 0x5f, 0x96, 0x86, 0xbe, 0x68, 0x78, 0x73, 0x3f, 0xea, 0x5b, 0x26, 0xbe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9a, 0x96, 0x74, 0x3f, 0xf6, 0x29, 0x97, 0x3e, 0x5f, 0x96, 0x86, 0xbe, 0x68, 0x78, 0x73, 0x3f, 0xea, 0x5b, 0x26, 0x3e, 0xab, 0x96, 0x74, 0x3e, 0x6d, 0x3b, 0x5d, 0x3f, 0xf0, 0xbe, 0xe2, 0x3e, 0x5f, 0x96, 0x86, 0x3e, 0x68, 0x78, 0x73, 0x3f, 0xea, 0x5b, 0x26, 0x3e, 0x0, 0x0, 0x0, 0x3f, 0xbd, 0x1b, 0x4f, 0x3f, 0x7a, 0x37, 0x9e, 0x3e, 0xab, 0x96, 0x74, 0x3e, 0x6d, 0x3b, 0x5d, 0x3f, 0xf0, 0xbe, 0xe2, 0xbe, 0x5f, 0x96, 0x86, 0x3e, 0x68, 0x78, 0x73, 0x3f, 0xea, 0x5b, 0x26, 0xbe, 0x0, 0x0, 0x0, 0x3f, 0xbd, 0x1b, 0x4f, 0x3f, 0x7a, 0x37, 0x9e, 0xbe, 0x44, 0xc4, 0x59, 0x3f, 0x4f, 0x96, 0x6, 0x3f, 0x0, 0x0, 0x0, 0x0, 0xef, 0x70, 0x37, 0x3f, 0x12, 0x85, 0x2e, 0x3f, 0xf6, 0x29, 0x17, 0x3e, 0xef, 0x70, 0x37, 0x3f, 0x12, 0x85, 0x2e, 0x3f, 0xf6, 0x29, 0x17, 0xbe, 0x4f, 0x96, 0x6, 0x3f, 0x44, 0xc4, 0x59, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x33, 0xc4, 0xd9, 0x3e, 0x49, 0x2d, 0x30, 0x3f, 0x14, 0x79, 0x16, 0x3f, 0x6d, 0x3b, 0x5d, 0x3f, 0xf0, 0xbe, 0xe2, 0x3e, 0xab, 0x96, 0x74, 0x3e, 0x49, 0x2d, 0x30, 0x3f, 0x14, 0x79, 0x16, 0x3f, 0x33, 0xc4, 0xd9, 0x3e, 0xbd, 0x1b, 0x4f, 0x3f, 0x7a, 0x37, 0x9e, 0x3e, 0x0, 0x0, 0x0, 0x3f, 0x12, 0x85, 0x2e, 0x3f, 0xf6, 0x29, 0x17, 0x3e, 0xef, 0x70, 0x37, 0x3f, 0x14, 0x79, 0x16, 0x3f, 0x33, 0xc4, 0xd9, 0x3e, 0x49, 0x2d, 0x30, 0x3f, 0x9a, 0x96, 0x74, 0x3f, 0xf6, 0x29, 0x97, 0x3e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x68, 0x78, 0x73, 0x3f, 0xea, 0x5b, 0x26, 0x3e, 0x5f, 0x96, 0x86, 0x3e, 0x44, 0xc4, 0x59, 0x3f, 0x4f, 0x96, 0x6, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x9a, 0x96, 0x74, 0x3f, 0xf6, 0x29, 0x97, 0xbe, 0x0, 0x0, 0x0, 0x0, 0x6d, 0x3b, 0x5d, 0x3f, 0xf0, 0xbe, 0xe2, 0xbe, 0xab, 0x96, 0x74, 0x3e, 0x68, 0x78, 0x73, 0x3f, 0xea, 0x5b, 0x26, 0xbe, 0x5f, 0x96, 0x86, 0x3e, 0xbd, 0x1b, 0x4f, 0x3f, 0x7a, 0x37, 0x9e, 0xbe, 0x0, 0x0, 0x0, 0x3f, 0x12, 0x85, 0x2e, 0x3f, 0xf6, 0x29, 0x17, 0xbe, 0xef, 0x70, 0x37, 0x3f, 0x44, 0xc4, 0x59, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x4f, 0x96, 0x6, 0x3f, 0x6d, 0x3b, 0x5d, 0x3f, 0xf0, 0xbe, 0xe2, 0x3e, 0xab, 0x96, 0x74, 0xbe, 0xbd, 0x1b, 0x4f, 0x3f, 0x7a, 0x37, 0x9e, 0x3e, 0x0, 0x0, 0x0, 0xbf, 0x68, 0x78, 0x73, 0x3f, 0xea, 0x5b, 0x26, 0x3e, 0x5f, 0x96, 0x86, 0xbe, 0x4f, 0x96, 0x6, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x44, 0xc4, 0x59, 0xbf, 0x12, 0x85, 0x2e, 0x3f, 0xf6, 0x29, 0x17, 0x3e, 0xef, 0x70, 0x37, 0xbf, 0x12, 0x85, 0x2e, 0x3f, 0xf6, 0x29, 0x17, 0xbe, 0xef, 0x70, 0x37, 0xbf, 0x44, 0xc4, 0x59, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x4f, 0x96, 0x6, 0xbf, 0xbd, 0x1b, 0x4f, 0x3f, 0x7a, 0x37, 0x9e, 0xbe, 0x0, 0x0, 0x0, 0xbf, 0x6d, 0x3b, 0x5d, 0x3f, 0xf0, 0xbe, 0xe2, 0xbe, 0xab, 0x96, 0x74, 0xbe, 0x68, 0x78, 0x73, 0x3f, 0xea, 0x5b, 0x26, 0xbe, 0x5f, 0x96, 0x86, 0xbe, 0xf6, 0x29, 0x17, 0x3e, 0xef, 0x70, 0x37, 0x3f, 0x12, 0x85, 0x2e, 0xbf, 0x7a, 0x37, 0x9e, 0x3e, 0x0, 0x0, 0x0, 0x3f, 0xbd, 0x1b, 0x4f, 0xbf, 0x33, 0xc4, 0xd9, 0x3e, 0x49, 0x2d, 0x30, 0x3f, 0x14, 0x79, 0x16, 0xbf, 0xf0, 0xbe, 0xe2, 0x3e, 0xab, 0x96, 0x74, 0x3e, 0x6d, 0x3b, 0x5d, 0xbf, 0x14, 0x79, 0x16, 0x3f, 0x33, 0xc4, 0xd9, 0x3e, 0x49, 0x2d, 0x30, 0xbf, 0x49, 0x2d, 0x30, 0x3f, 0x14, 0x79, 0x16, 0x3f, 0x33, 0xc4, 0xd9, 0xbe, 0xf6, 0x29, 0x17, 0xbe, 0xef, 0x70, 0x37, 0x3f, 0x12, 0x85, 0x2e, 0xbf, 0x7a, 0x37, 0x9e, 0xbe, 0x0, 0x0, 0x0, 0x3f, 0xbd, 0x1b, 0x4f, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x4f, 0x96, 0x6, 0x3f, 0x44, 0xc4, 0x59, 0xbf, 0x4f, 0x96, 0x6, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x44, 0xc4, 0x59, 0xbf, 0xf0, 0xbe, 0xe2, 0xbe, 0xab, 0x96, 0x74, 0x3e, 0x6d, 0x3b, 0x5d, 0xbf, 0xf6, 0x29, 0x97, 0xbe, 0x0, 0x0, 0x0, 0x0, 0x9a, 0x96, 0x74, 0xbf, 0xea, 0x5b, 0x26, 0xbe, 0x5f, 0x96, 0x86, 0x3e, 0x68, 0x78, 0x73, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xbf, 0xf6, 0x29, 0x97, 0x3e, 0x0, 0x0, 0x0, 0x0, 0x9a, 0x96, 0x74, 0xbf, 0xea, 0x5b, 0x26, 0x3e, 0x5f, 0x96, 0x86, 0x3e, 0x68, 0x78, 0x73, 0xbf, 0xf0, 0xbe, 0xe2, 0xbe, 0xab, 0x96, 0x74, 0xbe, 0x6d, 0x3b, 0x5d, 0xbf, 0x7a, 0x37, 0x9e, 0xbe, 0x0, 0x0, 0x0, 0xbf, 0xbd, 0x1b, 0x4f, 0xbf, 0xea, 0x5b, 0x26, 0xbe, 0x5f, 0x96, 0x86, 0xbe, 0x68, 0x78, 0x73, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x44, 0xc4, 0x59, 0xbf, 0x4f, 0x96, 0x6, 0xbf, 0xf6, 0x29, 0x17, 0xbe, 0xef, 0x70, 0x37, 0xbf, 0x12, 0x85, 0x2e, 0xbf, 0xf6, 0x29, 0x17, 0x3e, 0xef, 0x70, 0x37, 0xbf, 0x12, 0x85, 0x2e, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x4f, 0x96, 0x6, 0xbf, 0x44, 0xc4, 0x59, 0xbf, 0x7a, 0x37, 0x9e, 0x3e, 0x0, 0x0, 0x0, 0xbf, 0xbd, 0x1b, 0x4f, 0xbf, 0xf0, 0xbe, 0xe2, 0x3e, 0xab, 0x96, 0x74, 0xbe, 0x6d, 0x3b, 0x5d, 0xbf, 0xea, 0x5b, 0x26, 0x3e, 0x5f, 0x96, 0x86, 0xbe, 0x68, 0x78, 0x73, 0xbf, 0xab, 0x96, 0x74, 0x3e, 0x6d, 0x3b, 0x5d, 0xbf, 0xf0, 0xbe, 0xe2, 0xbe, 0x0, 0x0, 0x0, 0x3f, 0xbd, 0x1b, 0x4f, 0xbf, 0x7a, 0x37, 0x9e, 0xbe, 0x33, 0xc4, 0xd9, 0x3e, 0x49, 0x2d, 0x30, 0xbf, 0x14, 0x79, 0x16, 0xbf, 0xef, 0x70, 0x37, 0x3f, 0x12, 0x85, 0x2e, 0xbf, 0xf6, 0x29, 0x17, 0xbe, 0x49, 0x2d, 0x30, 0x3f, 0x14, 0x79, 0x16, 0xbf, 0x33, 0xc4, 0xd9, 0xbe, 0x14, 0x79, 0x16, 0x3f, 0x33, 0xc4, 0xd9, 0xbe, 0x49, 0x2d, 0x30, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x9a, 0x96, 0x74, 0xbf, 0xf6, 0x29, 0x97, 0xbe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x5f, 0x96, 0x86, 0x3e, 0x68, 0x78, 0x73, 0xbf, 0xea, 0x5b, 0x26, 0xbe, 0x0, 0x0, 0x0, 0x0, 0x44, 0xc4, 0x59, 0xbf, 0x4f, 0x96, 0x6, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x9a, 0x96, 0x74, 0xbf, 0xf6, 0x29, 0x97, 0x3e, 0xab, 0x96, 0x74, 0x3e, 0x6d, 0x3b, 0x5d, 0xbf, 0xf0, 0xbe, 0xe2, 0x3e, 0x5f, 0x96, 0x86, 0x3e, 0x68, 0x78, 0x73, 0xbf, 0xea, 0x5b, 0x26, 0x3e, 0x0, 0x0, 0x0, 0x3f, 0xbd, 0x1b, 0x4f, 0xbf, 0x7a, 0x37, 0x9e, 0x3e, 0xef, 0x70, 0x37, 0x3f, 0x12, 0x85, 0x2e, 0xbf, 0xf6, 0x29, 0x17, 0x3e, 0x4f, 0x96, 0x6, 0x3f, 0x44, 0xc4, 0x59, 0xbf, 0x0, 0x0, 0x0, 0x0, 0xab, 0x96, 0x74, 0xbe, 0x6d, 0x3b, 0x5d, 0xbf, 0xf0, 0xbe, 0xe2, 0xbe, 0x0, 0x0, 0x0, 0xbf, 0xbd, 0x1b, 0x4f, 0xbf, 0x7a, 0x37, 0x9e, 0xbe, 0x5f, 0x96, 0x86, 0xbe, 0x68, 0x78, 0x73, 0xbf, 0xea, 0x5b, 0x26, 0xbe, 0x44, 0xc4, 0x59, 0xbf, 0x4f, 0x96, 0x6, 0xbf, 0x0, 0x0, 0x0, 0x0, 0xef, 0x70, 0x37, 0xbf, 0x12, 0x85, 0x2e, 0xbf, 0xf6, 0x29, 0x17, 0xbe, 0xef, 0x70, 0x37, 0xbf, 0x12, 0x85, 0x2e, 0xbf, 0xf6, 0x29, 0x17, 0x3e, 0x4f, 0x96, 0x6, 0xbf, 0x44, 0xc4, 0x59, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xbd, 0x1b, 0x4f, 0xbf, 0x7a, 0x37, 0x9e, 0x3e, 0xab, 0x96, 0x74, 0xbe, 0x6d, 0x3b, 0x5d, 0xbf, 0xf0, 0xbe, 0xe2, 0x3e, 0x5f, 0x96, 0x86, 0xbe, 0x68, 0x78, 0x73, 0xbf, 0xea, 0x5b, 0x26, 0x3e, 0x6d, 0x3b, 0x5d, 0xbf, 0xf0, 0xbe, 0xe2, 0xbe, 0xab, 0x96, 0x74, 0x3e, 0xbd, 0x1b, 0x4f, 0xbf, 0x7a, 0x37, 0x9e, 0xbe, 0x0, 0x0, 0x0, 0x3f, 0x49, 0x2d, 0x30, 0xbf, 0x14, 0x79, 0x16, 0xbf, 0x33, 0xc4, 0xd9, 0x3e, 0x12, 0x85, 0x2e, 0xbf, 0xf6, 0x29, 0x17, 0xbe, 0xef, 0x70, 0x37, 0x3f, 0xf0, 0xbe, 0xe2, 0xbe, 0xab, 0x96, 0x74, 0xbe, 0x6d, 0x3b, 0x5d, 0x3f, 0x14, 0x79, 0x16, 0xbf, 0x33, 0xc4, 0xd9, 0xbe, 0x49, 0x2d, 0x30, 0x3f, 0x7a, 0x37, 0x9e, 0xbe, 0x0, 0x0, 0x0, 0xbf, 0xbd, 0x1b, 0x4f, 0x3f, 0xf6, 0x29, 0x17, 0xbe, 0xef, 0x70, 0x37, 0xbf, 0x12, 0x85, 0x2e, 0x3f, 0x33, 0xc4, 0xd9, 0xbe, 0x49, 0x2d, 0x30, 0xbf, 0x14, 0x79, 0x16, 0x3f, 0xea, 0x5b, 0x26, 0xbe, 0x5f, 0x96, 0x86, 0xbe, 0x68, 0x78, 0x73, 0x3f, 0xf0, 0xbe, 0xe2, 0x3e, 0xab, 0x96, 0x74, 0xbe, 0x6d, 0x3b, 0x5d, 0x3f, 0xea, 0x5b, 0x26, 0x3e, 0x5f, 0x96, 0x86, 0xbe, 0x68, 0x78, 0x73, 0x3f, 0x7a, 0x37, 0x9e, 0x3e, 0x0, 0x0, 0x0, 0xbf, 0xbd, 0x1b, 0x4f, 0x3f, 0xf6, 0x29, 0x17, 0x3e, 0xef, 0x70, 0x37, 0xbf, 0x12, 0x85, 0x2e, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x4f, 0x96, 0x6, 0xbf, 0x44, 0xc4, 0x59, 0x3f, 0x33, 0xc4, 0xd9, 0x3e, 0x49, 0x2d, 0x30, 0xbf, 0x14, 0x79, 0x16, 0x3f, 0x14, 0x79, 0x16, 0x3f, 0x33, 0xc4, 0xd9, 0xbe, 0x49, 0x2d, 0x30, 0x3f, 0x49, 0x2d, 0x30, 0x3f, 0x14, 0x79, 0x16, 0xbf, 0x33, 0xc4, 0xd9, 0x3e, 0x9a, 0x96, 0x74, 0xbf, 0xf6, 0x29, 0x97, 0x3e, 0x0, 0x0, 0x0, 0x0, 0x68, 0x78, 0x73, 0xbf, 0xea, 0x5b, 0x26, 0x3e, 0x5f, 0x96, 0x86, 0x3e, 0x0, 0x0, 0x80, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x44, 0xc4, 0x59, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x4f, 0x96, 0x6, 0x3f, 0x9a, 0x96, 0x74, 0xbf, 0xf6, 0x29, 0x97, 0xbe, 0x0, 0x0, 0x0, 0x0, 0x68, 0x78, 0x73, 0xbf, 0xea, 0x5b, 0x26, 0xbe, 0x5f, 0x96, 0x86, 0x3e, 0x6d, 0x3b, 0x5d, 0xbf, 0xf0, 0xbe, 0xe2, 0x3e, 0xab, 0x96, 0x74, 0xbe, 0x68, 0x78, 0x73, 0xbf, 0xea, 0x5b, 0x26, 0x3e, 0x5f, 0x96, 0x86, 0xbe, 0xbd, 0x1b, 0x4f, 0xbf, 0x7a, 0x37, 0x9e, 0x3e, 0x0, 0x0, 0x0, 0xbf, 0x6d, 0x3b, 0x5d, 0xbf, 0xf0, 0xbe, 0xe2, 0xbe, 0xab, 0x96, 0x74, 0xbe, 0x68, 0x78, 0x73, 0xbf, 0xea, 0x5b, 0x26, 0xbe, 0x5f, 0x96, 0x86, 0xbe, 0xbd, 0x1b, 0x4f, 0xbf, 0x7a, 0x37, 0x9e, 0xbe, 0x0, 0x0, 0x0, 0xbf, 0x12, 0x85, 0x2e, 0xbf, 0xf6, 0x29, 0x17, 0x3e, 0xef, 0x70, 0x37, 0xbf, 0x12, 0x85, 0x2e, 0xbf, 0xf6, 0x29, 0x17, 0xbe, 0xef, 0x70, 0x37, 0xbf, 0x44, 0xc4, 0x59, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x4f, 0x96, 0x6, 0xbf, 0x49, 0x2d, 0x30, 0xbf, 0x14, 0x79, 0x16, 0x3f, 0x33, 0xc4, 0xd9, 0xbe, 0x14, 0x79, 0x16, 0xbf, 0x33, 0xc4, 0xd9, 0x3e, 0x49, 0x2d, 0x30, 0xbf, 0x33, 0xc4, 0xd9, 0xbe, 0x49, 0x2d, 0x30, 0x3f, 0x14, 0x79, 0x16, 0xbf, 0x33, 0xc4, 0xd9, 0xbe, 0x49, 0x2d, 0x30, 0xbf, 0x14, 0x79, 0x16, 0xbf, 0x14, 0x79, 0x16, 0xbf, 0x33, 0xc4, 0xd9, 0xbe, 0x49, 0x2d, 0x30, 0xbf, 0x49, 0x2d, 0x30, 0xbf, 0x14, 0x79, 0x16, 0xbf, 0x33, 0xc4, 0xd9, 0xbe)

[init]
def private c2da_lin_init_externs_r_alias() {
    c2da_lin_setup()
    for (i in range(1944)) {
        c2da_mem[389392 + i] = c2da_lin_extern_r_alias_0[i]
    }
}
