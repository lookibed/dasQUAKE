[export, sideeffects]
def D_PolysetDraw() {
    let c2da_saved_sp : int = c2da_lin_sp
    D_PolysetDraw_c2da_frame(c2da_lin_enter(49296))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def D_DrawNonSubdiv() {
    var ptri : int
    var pfv : int
    var index0 : int
    var index1 : int
    var index2 : int
    var i : int
    var lnumtriangles : int
    pfv = r_affinetridesc.pfinalverts
    ptri = r_affinetridesc.ptriangles
    lnumtriangles = r_affinetridesc.numtriangles
    i = 0
    while (i < lnumtriangles) {
        index0 = pfv + int(uint(c2da_mem[ptri + 4 + 0 * 4]) | uint(c2da_mem[ptri + 4 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ptri + 4 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ptri + 4 + 0 * 4 + 3]) << 0x18) * 32
        index1 = pfv + int(uint(c2da_mem[ptri + 4 + 1 * 4]) | uint(c2da_mem[ptri + 4 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ptri + 4 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ptri + 4 + 1 * 4 + 3]) << 0x18) * 32
        index2 = pfv + int(uint(c2da_mem[ptri + 4 + 2 * 4]) | uint(c2da_mem[ptri + 4 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ptri + 4 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ptri + 4 + 2 * 4 + 3]) << 0x18) * 32
        let c2da_fresh42 : int = int(uint(c2da_mem[index0 + 1 * 4]) | uint(c2da_mem[index0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[index0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[index0 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh43 : int = int(uint(c2da_mem[index0 + 0 * 4]) | uint(c2da_mem[index0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[index0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[index0 + 0 * 4 + 3]) << 0x18)
        d_xdenom = (c2da_fresh42 - int(uint(c2da_mem[index1 + 1 * 4]) | uint(c2da_mem[index1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[index1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[index1 + 1 * 4 + 3]) << 0x18)) * (c2da_fresh43 - int(uint(c2da_mem[index2 + 0 * 4]) | uint(c2da_mem[index2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[index2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[index2 + 0 * 4 + 3]) << 0x18)) - (c2da_fresh43 - int(uint(c2da_mem[index1 + 0 * 4]) | uint(c2da_mem[index1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[index1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[index1 + 0 * 4 + 3]) << 0x18)) * (c2da_fresh42 - int(uint(c2da_mem[index2 + 1 * 4]) | uint(c2da_mem[index2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[index2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[index2 + 1 * 4 + 3]) << 0x18))
        if (d_xdenom >= 0) {
            i++
            ptri += 16
            continue
        }
        let c2da_fresh0 : int = int(uint(c2da_mem[index0 + 0 * 4]) | uint(c2da_mem[index0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[index0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[index0 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh1 : uint = uint(c2da_fresh0)
        c2da_mem[205216 + 0 * 4] = uint8(c2da_fresh1)
        c2da_mem[205216 + 0 * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[205216 + 0 * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[205216 + 0 * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
        let c2da_fresh2 : int = int(uint(c2da_mem[index0 + 1 * 4]) | uint(c2da_mem[index0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[index0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[index0 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh3 : uint = uint(c2da_fresh2)
        c2da_mem[205216 + 1 * 4] = uint8(c2da_fresh3)
        c2da_mem[205216 + 1 * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[205216 + 1 * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[205216 + 1 * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
        let c2da_fresh4 : int = int(uint(c2da_mem[index0 + 2 * 4]) | uint(c2da_mem[index0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[index0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[index0 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh5 : uint = uint(c2da_fresh4)
        c2da_mem[205216 + 2 * 4] = uint8(c2da_fresh5)
        c2da_mem[205216 + 2 * 4 + 1] = uint8(c2da_fresh5 >> 0x8)
        c2da_mem[205216 + 2 * 4 + 2] = uint8(c2da_fresh5 >> 0x10)
        c2da_mem[205216 + 2 * 4 + 3] = uint8(c2da_fresh5 >> 0x18)
        let c2da_fresh6 : int = int(uint(c2da_mem[index0 + 3 * 4]) | uint(c2da_mem[index0 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[index0 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[index0 + 3 * 4 + 3]) << 0x18)
        let c2da_fresh7 : uint = uint(c2da_fresh6)
        c2da_mem[205216 + 3 * 4] = uint8(c2da_fresh7)
        c2da_mem[205216 + 3 * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
        c2da_mem[205216 + 3 * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
        c2da_mem[205216 + 3 * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
        let c2da_fresh8 : int = int(uint(c2da_mem[index0 + 4 * 4]) | uint(c2da_mem[index0 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[index0 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[index0 + 4 * 4 + 3]) << 0x18)
        let c2da_fresh9 : uint = uint(c2da_fresh8)
        c2da_mem[205216 + 4 * 4] = uint8(c2da_fresh9)
        c2da_mem[205216 + 4 * 4 + 1] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[205216 + 4 * 4 + 2] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[205216 + 4 * 4 + 3] = uint8(c2da_fresh9 >> 0x18)
        let c2da_fresh10 : int = int(uint(c2da_mem[index0 + 5 * 4]) | uint(c2da_mem[index0 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[index0 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[index0 + 5 * 4 + 3]) << 0x18)
        let c2da_fresh11 : uint = uint(c2da_fresh10)
        c2da_mem[205216 + 5 * 4] = uint8(c2da_fresh11)
        c2da_mem[205216 + 5 * 4 + 1] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[205216 + 5 * 4 + 2] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[205216 + 5 * 4 + 3] = uint8(c2da_fresh11 >> 0x18)
        let c2da_fresh12 : int = int(uint(c2da_mem[index1 + 0 * 4]) | uint(c2da_mem[index1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[index1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[index1 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh13 : uint = uint(c2da_fresh12)
        c2da_mem[205280 + 0 * 4] = uint8(c2da_fresh13)
        c2da_mem[205280 + 0 * 4 + 1] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[205280 + 0 * 4 + 2] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[205280 + 0 * 4 + 3] = uint8(c2da_fresh13 >> 0x18)
        let c2da_fresh14 : int = int(uint(c2da_mem[index1 + 1 * 4]) | uint(c2da_mem[index1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[index1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[index1 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh15 : uint = uint(c2da_fresh14)
        c2da_mem[205280 + 1 * 4] = uint8(c2da_fresh15)
        c2da_mem[205280 + 1 * 4 + 1] = uint8(c2da_fresh15 >> 0x8)
        c2da_mem[205280 + 1 * 4 + 2] = uint8(c2da_fresh15 >> 0x10)
        c2da_mem[205280 + 1 * 4 + 3] = uint8(c2da_fresh15 >> 0x18)
        let c2da_fresh16 : int = int(uint(c2da_mem[index1 + 2 * 4]) | uint(c2da_mem[index1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[index1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[index1 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh17 : uint = uint(c2da_fresh16)
        c2da_mem[205280 + 2 * 4] = uint8(c2da_fresh17)
        c2da_mem[205280 + 2 * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
        c2da_mem[205280 + 2 * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
        c2da_mem[205280 + 2 * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
        let c2da_fresh18 : int = int(uint(c2da_mem[index1 + 3 * 4]) | uint(c2da_mem[index1 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[index1 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[index1 + 3 * 4 + 3]) << 0x18)
        let c2da_fresh19 : uint = uint(c2da_fresh18)
        c2da_mem[205280 + 3 * 4] = uint8(c2da_fresh19)
        c2da_mem[205280 + 3 * 4 + 1] = uint8(c2da_fresh19 >> 0x8)
        c2da_mem[205280 + 3 * 4 + 2] = uint8(c2da_fresh19 >> 0x10)
        c2da_mem[205280 + 3 * 4 + 3] = uint8(c2da_fresh19 >> 0x18)
        let c2da_fresh20 : int = int(uint(c2da_mem[index1 + 4 * 4]) | uint(c2da_mem[index1 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[index1 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[index1 + 4 * 4 + 3]) << 0x18)
        let c2da_fresh21 : uint = uint(c2da_fresh20)
        c2da_mem[205280 + 4 * 4] = uint8(c2da_fresh21)
        c2da_mem[205280 + 4 * 4 + 1] = uint8(c2da_fresh21 >> 0x8)
        c2da_mem[205280 + 4 * 4 + 2] = uint8(c2da_fresh21 >> 0x10)
        c2da_mem[205280 + 4 * 4 + 3] = uint8(c2da_fresh21 >> 0x18)
        let c2da_fresh22 : int = int(uint(c2da_mem[index1 + 5 * 4]) | uint(c2da_mem[index1 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[index1 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[index1 + 5 * 4 + 3]) << 0x18)
        let c2da_fresh23 : uint = uint(c2da_fresh22)
        c2da_mem[205280 + 5 * 4] = uint8(c2da_fresh23)
        c2da_mem[205280 + 5 * 4 + 1] = uint8(c2da_fresh23 >> 0x8)
        c2da_mem[205280 + 5 * 4 + 2] = uint8(c2da_fresh23 >> 0x10)
        c2da_mem[205280 + 5 * 4 + 3] = uint8(c2da_fresh23 >> 0x18)
        let c2da_fresh24 : int = int(uint(c2da_mem[index2 + 0 * 4]) | uint(c2da_mem[index2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[index2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[index2 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh25 : uint = uint(c2da_fresh24)
        c2da_mem[205248 + 0 * 4] = uint8(c2da_fresh25)
        c2da_mem[205248 + 0 * 4 + 1] = uint8(c2da_fresh25 >> 0x8)
        c2da_mem[205248 + 0 * 4 + 2] = uint8(c2da_fresh25 >> 0x10)
        c2da_mem[205248 + 0 * 4 + 3] = uint8(c2da_fresh25 >> 0x18)
        let c2da_fresh26 : int = int(uint(c2da_mem[index2 + 1 * 4]) | uint(c2da_mem[index2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[index2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[index2 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh27 : uint = uint(c2da_fresh26)
        c2da_mem[205248 + 1 * 4] = uint8(c2da_fresh27)
        c2da_mem[205248 + 1 * 4 + 1] = uint8(c2da_fresh27 >> 0x8)
        c2da_mem[205248 + 1 * 4 + 2] = uint8(c2da_fresh27 >> 0x10)
        c2da_mem[205248 + 1 * 4 + 3] = uint8(c2da_fresh27 >> 0x18)
        let c2da_fresh28 : int = int(uint(c2da_mem[index2 + 2 * 4]) | uint(c2da_mem[index2 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[index2 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[index2 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh29 : uint = uint(c2da_fresh28)
        c2da_mem[205248 + 2 * 4] = uint8(c2da_fresh29)
        c2da_mem[205248 + 2 * 4 + 1] = uint8(c2da_fresh29 >> 0x8)
        c2da_mem[205248 + 2 * 4 + 2] = uint8(c2da_fresh29 >> 0x10)
        c2da_mem[205248 + 2 * 4 + 3] = uint8(c2da_fresh29 >> 0x18)
        let c2da_fresh30 : int = int(uint(c2da_mem[index2 + 3 * 4]) | uint(c2da_mem[index2 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[index2 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[index2 + 3 * 4 + 3]) << 0x18)
        let c2da_fresh31 : uint = uint(c2da_fresh30)
        c2da_mem[205248 + 3 * 4] = uint8(c2da_fresh31)
        c2da_mem[205248 + 3 * 4 + 1] = uint8(c2da_fresh31 >> 0x8)
        c2da_mem[205248 + 3 * 4 + 2] = uint8(c2da_fresh31 >> 0x10)
        c2da_mem[205248 + 3 * 4 + 3] = uint8(c2da_fresh31 >> 0x18)
        let c2da_fresh32 : int = int(uint(c2da_mem[index2 + 4 * 4]) | uint(c2da_mem[index2 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[index2 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[index2 + 4 * 4 + 3]) << 0x18)
        let c2da_fresh33 : uint = uint(c2da_fresh32)
        c2da_mem[205248 + 4 * 4] = uint8(c2da_fresh33)
        c2da_mem[205248 + 4 * 4 + 1] = uint8(c2da_fresh33 >> 0x8)
        c2da_mem[205248 + 4 * 4 + 2] = uint8(c2da_fresh33 >> 0x10)
        c2da_mem[205248 + 4 * 4 + 3] = uint8(c2da_fresh33 >> 0x18)
        let c2da_fresh34 : int = int(uint(c2da_mem[index2 + 5 * 4]) | uint(c2da_mem[index2 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[index2 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[index2 + 5 * 4 + 3]) << 0x18)
        let c2da_fresh35 : uint = uint(c2da_fresh34)
        c2da_mem[205248 + 5 * 4] = uint8(c2da_fresh35)
        c2da_mem[205248 + 5 * 4 + 1] = uint8(c2da_fresh35 >> 0x8)
        c2da_mem[205248 + 5 * 4 + 2] = uint8(c2da_fresh35 >> 0x10)
        c2da_mem[205248 + 5 * 4 + 3] = uint8(c2da_fresh35 >> 0x18)
        if (int(uint(c2da_mem[ptri]) | uint(c2da_mem[ptri + 1]) << 0x8 | uint(c2da_mem[ptri + 2]) << 0x10 | uint(c2da_mem[ptri + 3]) << 0x18) == 0) {
            if ((int(uint(c2da_mem[index0 + 24]) | uint(c2da_mem[index0 + 25]) << 0x8 | uint(c2da_mem[index0 + 26]) << 0x10 | uint(c2da_mem[index0 + 27]) << 0x18) & 32) != 0) {
                let c2da_fresh36 : int = int(uint(c2da_mem[205216 + 2 * 4]) | uint(c2da_mem[205216 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[205216 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[205216 + 2 * 4 + 3]) << 0x18) + int(r_affinetridesc.seamfixupX16)
                let c2da_fresh37 : uint = uint(c2da_fresh36)
                c2da_mem[205216 + 2 * 4] = uint8(c2da_fresh37)
                c2da_mem[205216 + 2 * 4 + 1] = uint8(c2da_fresh37 >> 0x8)
                c2da_mem[205216 + 2 * 4 + 2] = uint8(c2da_fresh37 >> 0x10)
                c2da_mem[205216 + 2 * 4 + 3] = uint8(c2da_fresh37 >> 0x18)
            }
            if ((int(uint(c2da_mem[index1 + 24]) | uint(c2da_mem[index1 + 25]) << 0x8 | uint(c2da_mem[index1 + 26]) << 0x10 | uint(c2da_mem[index1 + 27]) << 0x18) & 32) != 0) {
                let c2da_fresh38 : int = int(uint(c2da_mem[205280 + 2 * 4]) | uint(c2da_mem[205280 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[205280 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[205280 + 2 * 4 + 3]) << 0x18) + int(r_affinetridesc.seamfixupX16)
                let c2da_fresh39 : uint = uint(c2da_fresh38)
                c2da_mem[205280 + 2 * 4] = uint8(c2da_fresh39)
                c2da_mem[205280 + 2 * 4 + 1] = uint8(c2da_fresh39 >> 0x8)
                c2da_mem[205280 + 2 * 4 + 2] = uint8(c2da_fresh39 >> 0x10)
                c2da_mem[205280 + 2 * 4 + 3] = uint8(c2da_fresh39 >> 0x18)
            }
            if ((int(uint(c2da_mem[index2 + 24]) | uint(c2da_mem[index2 + 25]) << 0x8 | uint(c2da_mem[index2 + 26]) << 0x10 | uint(c2da_mem[index2 + 27]) << 0x18) & 32) != 0) {
                let c2da_fresh40 : int = int(uint(c2da_mem[205248 + 2 * 4]) | uint(c2da_mem[205248 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[205248 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[205248 + 2 * 4 + 3]) << 0x18) + int(r_affinetridesc.seamfixupX16)
                let c2da_fresh41 : uint = uint(c2da_fresh40)
                c2da_mem[205248 + 2 * 4] = uint8(c2da_fresh41)
                c2da_mem[205248 + 2 * 4 + 1] = uint8(c2da_fresh41 >> 0x8)
                c2da_mem[205248 + 2 * 4 + 2] = uint8(c2da_fresh41 >> 0x10)
                c2da_mem[205248 + 2 * 4 + 3] = uint8(c2da_fresh41 >> 0x18)
            }
        }
        D_PolysetSetEdgeTable()
        D_RasterizeAliasPolySmooth()
        i++
        ptri += 16
    }
    return
}
[export, sideeffects]
def D_RasterizeAliasPolySmooth() {
    var initialleftheight : int
    var initialrightheight : int
    var plefttop : int
    var prighttop : int
    var pleftbottom : int
    var prightbottom : int
    var working_lstepx : int
    var originalcount : int
    var height : int
    var height_0 : int
    var pstart : int
    plefttop = int(uint(c2da_mem[pedgetable + 8]) | uint(c2da_mem[pedgetable + 9]) << 0x8 | uint(c2da_mem[pedgetable + 10]) << 0x10 | uint(c2da_mem[pedgetable + 11]) << 0x18)
    prighttop = int(uint(c2da_mem[pedgetable + 40]) | uint(c2da_mem[pedgetable + 41]) << 0x8 | uint(c2da_mem[pedgetable + 42]) << 0x10 | uint(c2da_mem[pedgetable + 43]) << 0x18)
    pleftbottom = int(uint(c2da_mem[pedgetable + 16]) | uint(c2da_mem[pedgetable + 17]) << 0x8 | uint(c2da_mem[pedgetable + 18]) << 0x10 | uint(c2da_mem[pedgetable + 19]) << 0x18)
    prightbottom = int(uint(c2da_mem[pedgetable + 48]) | uint(c2da_mem[pedgetable + 49]) << 0x8 | uint(c2da_mem[pedgetable + 50]) << 0x10 | uint(c2da_mem[pedgetable + 51]) << 0x18)
    initialleftheight = int(uint(c2da_mem[pleftbottom + 1 * 4]) | uint(c2da_mem[pleftbottom + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pleftbottom + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pleftbottom + 1 * 4 + 3]) << 0x18) - int(uint(c2da_mem[plefttop + 1 * 4]) | uint(c2da_mem[plefttop + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 1 * 4 + 3]) << 0x18)
    initialrightheight = int(uint(c2da_mem[prightbottom + 1 * 4]) | uint(c2da_mem[prightbottom + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[prightbottom + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[prightbottom + 1 * 4 + 3]) << 0x18) - int(uint(c2da_mem[prighttop + 1 * 4]) | uint(c2da_mem[prighttop + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[prighttop + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[prighttop + 1 * 4 + 3]) << 0x18)
    D_PolysetCalcGradients(r_affinetridesc.skinwidth)
    d_pedgespanpackage = int(a_spans)  // nolint:PERF020
    let c2da_fresh65 : int = int(uint(c2da_mem[plefttop + 1 * 4]) | uint(c2da_mem[plefttop + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 1 * 4 + 3]) << 0x18)
    ystart = c2da_fresh65
    let c2da_fresh66 : int = int(uint(c2da_mem[plefttop + 0 * 4]) | uint(c2da_mem[plefttop + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 0 * 4 + 3]) << 0x18)
    d_aspancount = c2da_fresh66 - int(uint(c2da_mem[prighttop + 0 * 4]) | uint(c2da_mem[prighttop + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[prighttop + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[prighttop + 0 * 4 + 3]) << 0x18)
    let c2da_fresh67 : int = int(uint(c2da_mem[plefttop + 2 * 4]) | uint(c2da_mem[plefttop + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 2 * 4 + 3]) << 0x18)
    let c2da_fresh68 : int = int(uint(c2da_mem[plefttop + 3 * 4]) | uint(c2da_mem[plefttop + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 3 * 4 + 3]) << 0x18)
    d_ptex = r_affinetridesc.pskin + (c2da_fresh67 >> 16) + (c2da_fresh68 >> 16) * r_affinetridesc.skinwidth
    d_sfrac = c2da_fresh67 & 65535
    d_tfrac = c2da_fresh68 & 65535
    d_light = int(uint(c2da_mem[plefttop + 4 * 4]) | uint(c2da_mem[plefttop + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 4 * 4 + 3]) << 0x18)
    d_zi = int(uint(c2da_mem[plefttop + 5 * 4]) | uint(c2da_mem[plefttop + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 5 * 4 + 3]) << 0x18)
    d_pdest = d_viewbuffer + int(ystart * screenwidth) + c2da_fresh66
    d_pz = d_pzbuffer + int(uint(ystart) * d_zwidth) * 2 + c2da_fresh66 * 2
    if (initialleftheight == 1) {
        let c2da_fresh44 : uint = uint(d_pdest)
        c2da_mem[d_pedgespanpackage] = uint8(c2da_fresh44)
        c2da_mem[d_pedgespanpackage + 1] = uint8(c2da_fresh44 >> 0x8)
        c2da_mem[d_pedgespanpackage + 2] = uint8(c2da_fresh44 >> 0x10)
        c2da_mem[d_pedgespanpackage + 3] = uint8(c2da_fresh44 >> 0x18)
        c2da_mem[d_pedgespanpackage + 4] = 0u8
        c2da_mem[d_pedgespanpackage + 5] = 0u8
        c2da_mem[d_pedgespanpackage + 6] = 0u8
        c2da_mem[d_pedgespanpackage + 7] = 0u8
        let c2da_fresh45 : uint = uint(d_pz)
        c2da_mem[d_pedgespanpackage + 8] = uint8(c2da_fresh45)
        c2da_mem[d_pedgespanpackage + 9] = uint8(c2da_fresh45 >> 0x8)
        c2da_mem[d_pedgespanpackage + 10] = uint8(c2da_fresh45 >> 0x10)
        c2da_mem[d_pedgespanpackage + 11] = uint8(c2da_fresh45 >> 0x18)
        c2da_mem[d_pedgespanpackage + 12] = 0u8
        c2da_mem[d_pedgespanpackage + 13] = 0u8
        c2da_mem[d_pedgespanpackage + 14] = 0u8
        c2da_mem[d_pedgespanpackage + 15] = 0u8
        let c2da_fresh46 : uint = uint(d_aspancount)
        c2da_mem[d_pedgespanpackage + 16] = uint8(c2da_fresh46)
        c2da_mem[d_pedgespanpackage + 17] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[d_pedgespanpackage + 18] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[d_pedgespanpackage + 19] = uint8(c2da_fresh46 >> 0x18)
        let c2da_fresh47 : uint = uint(d_ptex)
        c2da_mem[d_pedgespanpackage + 24] = uint8(c2da_fresh47)
        c2da_mem[d_pedgespanpackage + 25] = uint8(c2da_fresh47 >> 0x8)
        c2da_mem[d_pedgespanpackage + 26] = uint8(c2da_fresh47 >> 0x10)
        c2da_mem[d_pedgespanpackage + 27] = uint8(c2da_fresh47 >> 0x18)
        c2da_mem[d_pedgespanpackage + 28] = 0u8
        c2da_mem[d_pedgespanpackage + 29] = 0u8
        c2da_mem[d_pedgespanpackage + 30] = 0u8
        c2da_mem[d_pedgespanpackage + 31] = 0u8
        let c2da_fresh48 : uint = uint(d_sfrac)
        c2da_mem[d_pedgespanpackage + 32] = uint8(c2da_fresh48)
        c2da_mem[d_pedgespanpackage + 33] = uint8(c2da_fresh48 >> 0x8)
        c2da_mem[d_pedgespanpackage + 34] = uint8(c2da_fresh48 >> 0x10)
        c2da_mem[d_pedgespanpackage + 35] = uint8(c2da_fresh48 >> 0x18)
        let c2da_fresh49 : uint = uint(d_tfrac)
        c2da_mem[d_pedgespanpackage + 36] = uint8(c2da_fresh49)
        c2da_mem[d_pedgespanpackage + 37] = uint8(c2da_fresh49 >> 0x8)
        c2da_mem[d_pedgespanpackage + 38] = uint8(c2da_fresh49 >> 0x10)
        c2da_mem[d_pedgespanpackage + 39] = uint8(c2da_fresh49 >> 0x18)
        let c2da_fresh50 : uint = uint(d_light)
        c2da_mem[d_pedgespanpackage + 40] = uint8(c2da_fresh50)
        c2da_mem[d_pedgespanpackage + 41] = uint8(c2da_fresh50 >> 0x8)
        c2da_mem[d_pedgespanpackage + 42] = uint8(c2da_fresh50 >> 0x10)
        c2da_mem[d_pedgespanpackage + 43] = uint8(c2da_fresh50 >> 0x18)
        let c2da_fresh51 : uint = uint(d_zi)
        c2da_mem[d_pedgespanpackage + 44] = uint8(c2da_fresh51)
        c2da_mem[d_pedgespanpackage + 45] = uint8(c2da_fresh51 >> 0x8)
        c2da_mem[d_pedgespanpackage + 46] = uint8(c2da_fresh51 >> 0x10)
        c2da_mem[d_pedgespanpackage + 47] = uint8(c2da_fresh51 >> 0x18)
        d_pedgespanpackage += 48
    } else {
        D_PolysetSetUpForLineScan(int(uint(c2da_mem[plefttop + 0 * 4]) | uint(c2da_mem[plefttop + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 0 * 4 + 3]) << 0x18), int(uint(c2da_mem[plefttop + 1 * 4]) | uint(c2da_mem[plefttop + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 1 * 4 + 3]) << 0x18), int(uint(c2da_mem[pleftbottom + 0 * 4]) | uint(c2da_mem[pleftbottom + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pleftbottom + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pleftbottom + 0 * 4 + 3]) << 0x18), int(uint(c2da_mem[pleftbottom + 1 * 4]) | uint(c2da_mem[pleftbottom + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pleftbottom + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pleftbottom + 1 * 4 + 3]) << 0x18))
        let c2da_fresh69 : int = int(uint(c2da_mem[204416]) | uint(c2da_mem[204417]) << 0x8 | uint(c2da_mem[204418]) << 0x10 | uint(c2da_mem[204419]) << 0x18)
        d_pzbasestep = int(d_zwidth + uint(c2da_fresh69))
        d_pzextrastep = d_pzbasestep + 1
        d_pdestbasestep = screenwidth + c2da_fresh69
        d_pdestextrastep = d_pdestbasestep + 1
        if (c2da_fresh69 < 0) {
            working_lstepx = r_lstepx - 1
        } else {
            working_lstepx = r_lstepx
        }
        let c2da_fresh70 : int = int(uint(c2da_mem[204416]) | uint(c2da_mem[204417]) << 0x8 | uint(c2da_mem[204418]) << 0x10 | uint(c2da_mem[204419]) << 0x18)
        d_countextrastep = c2da_fresh70 + 1
        d_ptexbasestep = (r_sstepy + r_sstepx * c2da_fresh70 >> 16) + (r_tstepy + r_tstepx * c2da_fresh70 >> 16) * r_affinetridesc.skinwidth
        d_sfracbasestep = r_sstepy + r_sstepx * c2da_fresh70 & 65535
        d_tfracbasestep = r_tstepy + r_tstepx * c2da_fresh70 & 65535
        d_lightbasestep = r_lstepy + working_lstepx * c2da_fresh70
        d_zibasestep = r_zistepy + r_zistepx * c2da_fresh70
        d_ptexextrastep = (r_sstepy + r_sstepx * d_countextrastep >> 16) + (r_tstepy + r_tstepx * d_countextrastep >> 16) * r_affinetridesc.skinwidth
        d_sfracextrastep = r_sstepy + r_sstepx * d_countextrastep & 65535
        d_tfracextrastep = r_tstepy + r_tstepx * d_countextrastep & 65535
        d_lightextrastep = d_lightbasestep + working_lstepx
        d_ziextrastep = d_zibasestep + r_zistepx
        D_PolysetScanLeftEdge(initialleftheight)
    }
    if (int(uint(c2da_mem[pedgetable + 4]) | uint(c2da_mem[pedgetable + 5]) << 0x8 | uint(c2da_mem[pedgetable + 6]) << 0x10 | uint(c2da_mem[pedgetable + 7]) << 0x18) == 2) {
        plefttop = pleftbottom
        pleftbottom = int(uint(c2da_mem[pedgetable + 24]) | uint(c2da_mem[pedgetable + 25]) << 0x8 | uint(c2da_mem[pedgetable + 26]) << 0x10 | uint(c2da_mem[pedgetable + 27]) << 0x18)
        let c2da_fresh71 : int = int(uint(c2da_mem[pleftbottom + 1 * 4]) | uint(c2da_mem[pleftbottom + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pleftbottom + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pleftbottom + 1 * 4 + 3]) << 0x18)
        let c2da_fresh72 : int = int(uint(c2da_mem[plefttop + 1 * 4]) | uint(c2da_mem[plefttop + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 1 * 4 + 3]) << 0x18)
        height = c2da_fresh71 - c2da_fresh72
        ystart = c2da_fresh72
        let c2da_fresh73 : int = int(uint(c2da_mem[plefttop + 0 * 4]) | uint(c2da_mem[plefttop + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 0 * 4 + 3]) << 0x18)
        d_aspancount = c2da_fresh73 - int(uint(c2da_mem[prighttop + 0 * 4]) | uint(c2da_mem[prighttop + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[prighttop + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[prighttop + 0 * 4 + 3]) << 0x18)
        d_ptex = r_affinetridesc.pskin + (int(uint(c2da_mem[plefttop + 2 * 4]) | uint(c2da_mem[plefttop + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 2 * 4 + 3]) << 0x18) >> 16) + (int(uint(c2da_mem[plefttop + 3 * 4]) | uint(c2da_mem[plefttop + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 3 * 4 + 3]) << 0x18) >> 16) * r_affinetridesc.skinwidth
        d_sfrac = 0
        d_tfrac = 0
        d_light = int(uint(c2da_mem[plefttop + 4 * 4]) | uint(c2da_mem[plefttop + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 4 * 4 + 3]) << 0x18)
        d_zi = int(uint(c2da_mem[plefttop + 5 * 4]) | uint(c2da_mem[plefttop + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 5 * 4 + 3]) << 0x18)
        d_pdest = d_viewbuffer + int(ystart * screenwidth) + c2da_fresh73
        d_pz = d_pzbuffer + int(uint(ystart) * d_zwidth) * 2 + c2da_fresh73 * 2
        if (height == 1) {
            let c2da_fresh52 : uint = uint(d_pdest)
            c2da_mem[d_pedgespanpackage] = uint8(c2da_fresh52)
            c2da_mem[d_pedgespanpackage + 1] = uint8(c2da_fresh52 >> 0x8)
            c2da_mem[d_pedgespanpackage + 2] = uint8(c2da_fresh52 >> 0x10)
            c2da_mem[d_pedgespanpackage + 3] = uint8(c2da_fresh52 >> 0x18)
            c2da_mem[d_pedgespanpackage + 4] = 0u8
            c2da_mem[d_pedgespanpackage + 5] = 0u8
            c2da_mem[d_pedgespanpackage + 6] = 0u8
            c2da_mem[d_pedgespanpackage + 7] = 0u8
            let c2da_fresh53 : uint = uint(d_pz)
            c2da_mem[d_pedgespanpackage + 8] = uint8(c2da_fresh53)
            c2da_mem[d_pedgespanpackage + 9] = uint8(c2da_fresh53 >> 0x8)
            c2da_mem[d_pedgespanpackage + 10] = uint8(c2da_fresh53 >> 0x10)
            c2da_mem[d_pedgespanpackage + 11] = uint8(c2da_fresh53 >> 0x18)
            c2da_mem[d_pedgespanpackage + 12] = 0u8
            c2da_mem[d_pedgespanpackage + 13] = 0u8
            c2da_mem[d_pedgespanpackage + 14] = 0u8
            c2da_mem[d_pedgespanpackage + 15] = 0u8
            let c2da_fresh54 : uint = uint(d_aspancount)
            c2da_mem[d_pedgespanpackage + 16] = uint8(c2da_fresh54)
            c2da_mem[d_pedgespanpackage + 17] = uint8(c2da_fresh54 >> 0x8)
            c2da_mem[d_pedgespanpackage + 18] = uint8(c2da_fresh54 >> 0x10)
            c2da_mem[d_pedgespanpackage + 19] = uint8(c2da_fresh54 >> 0x18)
            let c2da_fresh55 : uint = uint(d_ptex)
            c2da_mem[d_pedgespanpackage + 24] = uint8(c2da_fresh55)
            c2da_mem[d_pedgespanpackage + 25] = uint8(c2da_fresh55 >> 0x8)
            c2da_mem[d_pedgespanpackage + 26] = uint8(c2da_fresh55 >> 0x10)
            c2da_mem[d_pedgespanpackage + 27] = uint8(c2da_fresh55 >> 0x18)
            c2da_mem[d_pedgespanpackage + 28] = 0u8
            c2da_mem[d_pedgespanpackage + 29] = 0u8
            c2da_mem[d_pedgespanpackage + 30] = 0u8
            c2da_mem[d_pedgespanpackage + 31] = 0u8
            let c2da_fresh56 : uint = uint(d_sfrac)
            c2da_mem[d_pedgespanpackage + 32] = uint8(c2da_fresh56)
            c2da_mem[d_pedgespanpackage + 33] = uint8(c2da_fresh56 >> 0x8)
            c2da_mem[d_pedgespanpackage + 34] = uint8(c2da_fresh56 >> 0x10)
            c2da_mem[d_pedgespanpackage + 35] = uint8(c2da_fresh56 >> 0x18)
            let c2da_fresh57 : uint = uint(d_tfrac)
            c2da_mem[d_pedgespanpackage + 36] = uint8(c2da_fresh57)
            c2da_mem[d_pedgespanpackage + 37] = uint8(c2da_fresh57 >> 0x8)
            c2da_mem[d_pedgespanpackage + 38] = uint8(c2da_fresh57 >> 0x10)
            c2da_mem[d_pedgespanpackage + 39] = uint8(c2da_fresh57 >> 0x18)
            let c2da_fresh58 : uint = uint(d_light)
            c2da_mem[d_pedgespanpackage + 40] = uint8(c2da_fresh58)
            c2da_mem[d_pedgespanpackage + 41] = uint8(c2da_fresh58 >> 0x8)
            c2da_mem[d_pedgespanpackage + 42] = uint8(c2da_fresh58 >> 0x10)
            c2da_mem[d_pedgespanpackage + 43] = uint8(c2da_fresh58 >> 0x18)
            let c2da_fresh59 : uint = uint(d_zi)
            c2da_mem[d_pedgespanpackage + 44] = uint8(c2da_fresh59)
            c2da_mem[d_pedgespanpackage + 45] = uint8(c2da_fresh59 >> 0x8)
            c2da_mem[d_pedgespanpackage + 46] = uint8(c2da_fresh59 >> 0x10)
            c2da_mem[d_pedgespanpackage + 47] = uint8(c2da_fresh59 >> 0x18)
            d_pedgespanpackage += 48
        } else {
            D_PolysetSetUpForLineScan(int(uint(c2da_mem[plefttop + 0 * 4]) | uint(c2da_mem[plefttop + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 0 * 4 + 3]) << 0x18), int(uint(c2da_mem[plefttop + 1 * 4]) | uint(c2da_mem[plefttop + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plefttop + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plefttop + 1 * 4 + 3]) << 0x18), int(uint(c2da_mem[pleftbottom + 0 * 4]) | uint(c2da_mem[pleftbottom + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pleftbottom + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pleftbottom + 0 * 4 + 3]) << 0x18), int(uint(c2da_mem[pleftbottom + 1 * 4]) | uint(c2da_mem[pleftbottom + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pleftbottom + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pleftbottom + 1 * 4 + 3]) << 0x18))
            let c2da_fresh74 : int = int(uint(c2da_mem[204416]) | uint(c2da_mem[204417]) << 0x8 | uint(c2da_mem[204418]) << 0x10 | uint(c2da_mem[204419]) << 0x18)
            d_pdestbasestep = screenwidth + c2da_fresh74
            d_pdestextrastep = d_pdestbasestep + 1
            d_pzbasestep = int(d_zwidth + uint(c2da_fresh74))
            d_pzextrastep = d_pzbasestep + 1
            if (c2da_fresh74 < 0) {
                working_lstepx = r_lstepx - 1
            } else {
                working_lstepx = r_lstepx
            }
            let c2da_fresh75 : int = int(uint(c2da_mem[204416]) | uint(c2da_mem[204417]) << 0x8 | uint(c2da_mem[204418]) << 0x10 | uint(c2da_mem[204419]) << 0x18)
            d_countextrastep = c2da_fresh75 + 1
            d_ptexbasestep = (r_sstepy + r_sstepx * c2da_fresh75 >> 16) + (r_tstepy + r_tstepx * c2da_fresh75 >> 16) * r_affinetridesc.skinwidth
            d_sfracbasestep = r_sstepy + r_sstepx * c2da_fresh75 & 65535
            d_tfracbasestep = r_tstepy + r_tstepx * c2da_fresh75 & 65535
            d_lightbasestep = r_lstepy + working_lstepx * c2da_fresh75
            d_zibasestep = r_zistepy + r_zistepx * c2da_fresh75
            d_ptexextrastep = (r_sstepy + r_sstepx * d_countextrastep >> 16) + (r_tstepy + r_tstepx * d_countextrastep >> 16) * r_affinetridesc.skinwidth
            d_sfracextrastep = r_sstepy + r_sstepx * d_countextrastep & 65535
            d_tfracextrastep = r_tstepy + r_tstepx * d_countextrastep & 65535
            d_lightextrastep = d_lightbasestep + working_lstepx
            d_ziextrastep = d_zibasestep + r_zistepx
            D_PolysetScanLeftEdge(height)
        }
    }
    d_pedgespanpackage = int(a_spans)  // nolint:PERF020
    D_PolysetSetUpForLineScan(int(uint(c2da_mem[prighttop + 0 * 4]) | uint(c2da_mem[prighttop + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[prighttop + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[prighttop + 0 * 4 + 3]) << 0x18), int(uint(c2da_mem[prighttop + 1 * 4]) | uint(c2da_mem[prighttop + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[prighttop + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[prighttop + 1 * 4 + 3]) << 0x18), int(uint(c2da_mem[prightbottom + 0 * 4]) | uint(c2da_mem[prightbottom + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[prightbottom + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[prightbottom + 0 * 4 + 3]) << 0x18), int(uint(c2da_mem[prightbottom + 1 * 4]) | uint(c2da_mem[prightbottom + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[prightbottom + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[prightbottom + 1 * 4 + 3]) << 0x18))
    d_aspancount = 0
    d_countextrastep = int(uint(c2da_mem[204416]) | uint(c2da_mem[204417]) << 0x8 | uint(c2da_mem[204418]) << 0x10 | uint(c2da_mem[204419]) << 0x18) + 1
    originalcount = int(uint(c2da_mem[a_spans + initialrightheight * 48 + 16]) | uint(c2da_mem[a_spans + initialrightheight * 48 + 17]) << 0x8 | uint(c2da_mem[a_spans + initialrightheight * 48 + 18]) << 0x10 | uint(c2da_mem[a_spans + initialrightheight * 48 + 19]) << 0x18)
    let c2da_fresh60 : int = -999999
    let c2da_fresh61 : uint = uint(c2da_fresh60)
    c2da_mem[a_spans + initialrightheight * 48 + 16] = uint8(c2da_fresh61)
    c2da_mem[a_spans + initialrightheight * 48 + 17] = uint8(c2da_fresh61 >> 0x8)
    c2da_mem[a_spans + initialrightheight * 48 + 18] = uint8(c2da_fresh61 >> 0x10)
    c2da_mem[a_spans + initialrightheight * 48 + 19] = uint8(c2da_fresh61 >> 0x18)
    D_PolysetDrawSpans8(a_spans)
    if (int(uint(c2da_mem[pedgetable + 32]) | uint(c2da_mem[pedgetable + 33]) << 0x8 | uint(c2da_mem[pedgetable + 34]) << 0x10 | uint(c2da_mem[pedgetable + 35]) << 0x18) == 2) {
        pstart = a_spans + initialrightheight * 48
        let c2da_fresh62 : uint = uint(originalcount)
        c2da_mem[pstart + 16] = uint8(c2da_fresh62)
        c2da_mem[pstart + 17] = uint8(c2da_fresh62 >> 0x8)
        c2da_mem[pstart + 18] = uint8(c2da_fresh62 >> 0x10)
        c2da_mem[pstart + 19] = uint8(c2da_fresh62 >> 0x18)
        d_aspancount = int(uint(c2da_mem[prightbottom + 0 * 4]) | uint(c2da_mem[prightbottom + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[prightbottom + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[prightbottom + 0 * 4 + 3]) << 0x18) - int(uint(c2da_mem[prighttop + 0 * 4]) | uint(c2da_mem[prighttop + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[prighttop + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[prighttop + 0 * 4 + 3]) << 0x18)
        prighttop = prightbottom
        prightbottom = int(uint(c2da_mem[pedgetable + 56]) | uint(c2da_mem[pedgetable + 57]) << 0x8 | uint(c2da_mem[pedgetable + 58]) << 0x10 | uint(c2da_mem[pedgetable + 59]) << 0x18)
        height_0 = int(uint(c2da_mem[prightbottom + 1 * 4]) | uint(c2da_mem[prightbottom + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[prightbottom + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[prightbottom + 1 * 4 + 3]) << 0x18) - int(uint(c2da_mem[prighttop + 1 * 4]) | uint(c2da_mem[prighttop + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[prighttop + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[prighttop + 1 * 4 + 3]) << 0x18)
        D_PolysetSetUpForLineScan(int(uint(c2da_mem[prighttop + 0 * 4]) | uint(c2da_mem[prighttop + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[prighttop + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[prighttop + 0 * 4 + 3]) << 0x18), int(uint(c2da_mem[prighttop + 1 * 4]) | uint(c2da_mem[prighttop + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[prighttop + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[prighttop + 1 * 4 + 3]) << 0x18), int(uint(c2da_mem[prightbottom + 0 * 4]) | uint(c2da_mem[prightbottom + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[prightbottom + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[prightbottom + 0 * 4 + 3]) << 0x18), int(uint(c2da_mem[prightbottom + 1 * 4]) | uint(c2da_mem[prightbottom + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[prightbottom + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[prightbottom + 1 * 4 + 3]) << 0x18))
        d_countextrastep = int(uint(c2da_mem[204416]) | uint(c2da_mem[204417]) << 0x8 | uint(c2da_mem[204418]) << 0x10 | uint(c2da_mem[204419]) << 0x18) + 1
        let c2da_fresh63 : int = -999999
        let c2da_fresh64 : uint = uint(c2da_fresh63)
        c2da_mem[a_spans + (initialrightheight + height_0) * 48 + 16] = uint8(c2da_fresh64)
        c2da_mem[a_spans + (initialrightheight + height_0) * 48 + 17] = uint8(c2da_fresh64 >> 0x8)
        c2da_mem[a_spans + (initialrightheight + height_0) * 48 + 18] = uint8(c2da_fresh64 >> 0x10)
        c2da_mem[a_spans + (initialrightheight + height_0) * 48 + 19] = uint8(c2da_fresh64 >> 0x18)
        D_PolysetDrawSpans8(pstart)
    }
    return
}
[export, sideeffects]
def D_PolysetDrawSpans8(var pspanpackage : int) {
    var lcount : int
    var lpdest : int
    var lptex : int
    var lsfrac : int
    var ltfrac : int
    var llight : int
    var lzi : int
    var lpz : int
    while (true) {
        lcount = d_aspancount - int(uint(c2da_mem[pspanpackage + 16]) | uint(c2da_mem[pspanpackage + 17]) << 0x8 | uint(c2da_mem[pspanpackage + 18]) << 0x10 | uint(c2da_mem[pspanpackage + 19]) << 0x18)
        errorterm = errorterm + int(uint(c2da_mem[204432]) | uint(c2da_mem[204433]) << 0x8 | uint(c2da_mem[204434]) << 0x10 | uint(c2da_mem[204435]) << 0x18)
        if (errorterm >= 0) {
            d_aspancount += d_countextrastep
            errorterm = errorterm - erroradjustdown
        } else {
            d_aspancount += int(uint(c2da_mem[204416]) | uint(c2da_mem[204417]) << 0x8 | uint(c2da_mem[204418]) << 0x10 | uint(c2da_mem[204419]) << 0x18)
        }
        if (lcount != 0) {
            lpdest = int(uint(c2da_mem[pspanpackage]) | uint(c2da_mem[pspanpackage + 1]) << 0x8 | uint(c2da_mem[pspanpackage + 2]) << 0x10 | uint(c2da_mem[pspanpackage + 3]) << 0x18)
            lptex = int(uint(c2da_mem[pspanpackage + 24]) | uint(c2da_mem[pspanpackage + 25]) << 0x8 | uint(c2da_mem[pspanpackage + 26]) << 0x10 | uint(c2da_mem[pspanpackage + 27]) << 0x18)
            lpz = int(uint(c2da_mem[pspanpackage + 8]) | uint(c2da_mem[pspanpackage + 9]) << 0x8 | uint(c2da_mem[pspanpackage + 10]) << 0x10 | uint(c2da_mem[pspanpackage + 11]) << 0x18)
            lsfrac = int(uint(c2da_mem[pspanpackage + 32]) | uint(c2da_mem[pspanpackage + 33]) << 0x8 | uint(c2da_mem[pspanpackage + 34]) << 0x10 | uint(c2da_mem[pspanpackage + 35]) << 0x18)
            ltfrac = int(uint(c2da_mem[pspanpackage + 36]) | uint(c2da_mem[pspanpackage + 37]) << 0x8 | uint(c2da_mem[pspanpackage + 38]) << 0x10 | uint(c2da_mem[pspanpackage + 39]) << 0x18)
            llight = int(uint(c2da_mem[pspanpackage + 40]) | uint(c2da_mem[pspanpackage + 41]) << 0x8 | uint(c2da_mem[pspanpackage + 42]) << 0x10 | uint(c2da_mem[pspanpackage + 43]) << 0x18)
            lzi = int(uint(c2da_mem[pspanpackage + 44]) | uint(c2da_mem[pspanpackage + 45]) << 0x8 | uint(c2da_mem[pspanpackage + 46]) << 0x10 | uint(c2da_mem[pspanpackage + 47]) << 0x18)
            while (true) {
                if (lzi >> 16 >= int(int16(uint(c2da_mem[lpz]) | uint(c2da_mem[lpz + 1]) << 0x8))) {
                    let c2da_fresh76 : int = acolormap + (int(c2da_mem[lptex]) + (llight & 65280))
                    let c2da_fresh77 : uint8 = c2da_mem[c2da_fresh76]
                    c2da_mem[lpdest] = c2da_fresh77
                    let c2da_fresh78 : int16 = int16(lzi >> 16)
                    let c2da_fresh79 : uint = uint(c2da_fresh78)
                    c2da_mem[lpz] = uint8(c2da_fresh79)
                    c2da_mem[lpz + 1] = uint8(c2da_fresh79 >> 0x8)
                }
                lpdest++
                lzi += r_zistepx
                lpz += 2
                llight += r_lstepx
                lptex += a_ststepxwhole
                lsfrac += a_sstepxfrac
                lptex += lsfrac >> 16
                lsfrac &= 65535
                ltfrac += a_tstepxfrac
                if ((ltfrac & 65536) != 0) {
                    lptex += int(r_affinetridesc.skinwidth)
                    ltfrac &= 65535
                }
                lcount--
                if (lcount == 0) {
                    break
                }
            }
        }
        pspanpackage += 48
        if (int(uint(c2da_mem[pspanpackage + 16]) | uint(c2da_mem[pspanpackage + 17]) << 0x8 | uint(c2da_mem[pspanpackage + 18]) << 0x10 | uint(c2da_mem[pspanpackage + 19]) << 0x18) == -999999) {
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

var a_spans : int = default<int>

[export, sideeffects]
def D_PolysetSetUpForLineScan(var startvertu : int; var startvertv : int; var endvertu : int; var endvertv : int) {
    var dn : double
    var tm : int
    var tn : int
    var ptemp : int
    errorterm = -1
    tm = endvertu - startvertu
    tn = endvertv - startvertv
    if (tm <= 16 && tm >= -15 && (tn <= 16 && tn >= -15)) {
        ptemp = 707024 + ((tm + 15 << 5) + (tn + 15)) * 8
        let c2da_fresh80 : int = int(uint(c2da_mem[ptemp]) | uint(c2da_mem[ptemp + 1]) << 0x8 | uint(c2da_mem[ptemp + 2]) << 0x10 | uint(c2da_mem[ptemp + 3]) << 0x18)
        let c2da_fresh81 : uint = uint(c2da_fresh80)
        c2da_mem[204416] = uint8(c2da_fresh81)
        c2da_mem[204417] = uint8(c2da_fresh81 >> 0x8)
        c2da_mem[204418] = uint8(c2da_fresh81 >> 0x10)
        c2da_mem[204419] = uint8(c2da_fresh81 >> 0x18)
        let c2da_fresh82 : int = int(uint(c2da_mem[ptemp + 4]) | uint(c2da_mem[ptemp + 5]) << 0x8 | uint(c2da_mem[ptemp + 6]) << 0x10 | uint(c2da_mem[ptemp + 7]) << 0x18)
        let c2da_fresh83 : uint = uint(c2da_fresh82)
        c2da_mem[204432] = uint8(c2da_fresh83)
        c2da_mem[204433] = uint8(c2da_fresh83 >> 0x8)
        c2da_mem[204434] = uint8(c2da_fresh83 >> 0x10)
        c2da_mem[204435] = uint8(c2da_fresh83 >> 0x18)
        erroradjustdown = tn
    } else {
        dn = double(tn)
        FloorDivMod(double(tm), dn, 204416, 204432)
        erroradjustdown = int(dn)
    }
    return
}
var pedgetable : int = default<int>

var d_pedgespanpackage : int = default<int>

[export, sideeffects]
def D_PolysetScanLeftEdge(var height_1 : int) {
    while (true) {
        let c2da_fresh84 : uint = uint(d_pdest)
        c2da_mem[d_pedgespanpackage] = uint8(c2da_fresh84)
        c2da_mem[d_pedgespanpackage + 1] = uint8(c2da_fresh84 >> 0x8)
        c2da_mem[d_pedgespanpackage + 2] = uint8(c2da_fresh84 >> 0x10)
        c2da_mem[d_pedgespanpackage + 3] = uint8(c2da_fresh84 >> 0x18)
        c2da_mem[d_pedgespanpackage + 4] = 0u8
        c2da_mem[d_pedgespanpackage + 5] = 0u8
        c2da_mem[d_pedgespanpackage + 6] = 0u8
        c2da_mem[d_pedgespanpackage + 7] = 0u8
        let c2da_fresh85 : uint = uint(d_pz)
        c2da_mem[d_pedgespanpackage + 8] = uint8(c2da_fresh85)
        c2da_mem[d_pedgespanpackage + 9] = uint8(c2da_fresh85 >> 0x8)
        c2da_mem[d_pedgespanpackage + 10] = uint8(c2da_fresh85 >> 0x10)
        c2da_mem[d_pedgespanpackage + 11] = uint8(c2da_fresh85 >> 0x18)
        c2da_mem[d_pedgespanpackage + 12] = 0u8
        c2da_mem[d_pedgespanpackage + 13] = 0u8
        c2da_mem[d_pedgespanpackage + 14] = 0u8
        c2da_mem[d_pedgespanpackage + 15] = 0u8
        let c2da_fresh86 : uint = uint(d_aspancount)
        c2da_mem[d_pedgespanpackage + 16] = uint8(c2da_fresh86)
        c2da_mem[d_pedgespanpackage + 17] = uint8(c2da_fresh86 >> 0x8)
        c2da_mem[d_pedgespanpackage + 18] = uint8(c2da_fresh86 >> 0x10)
        c2da_mem[d_pedgespanpackage + 19] = uint8(c2da_fresh86 >> 0x18)
        let c2da_fresh87 : uint = uint(d_ptex)
        c2da_mem[d_pedgespanpackage + 24] = uint8(c2da_fresh87)
        c2da_mem[d_pedgespanpackage + 25] = uint8(c2da_fresh87 >> 0x8)
        c2da_mem[d_pedgespanpackage + 26] = uint8(c2da_fresh87 >> 0x10)
        c2da_mem[d_pedgespanpackage + 27] = uint8(c2da_fresh87 >> 0x18)
        c2da_mem[d_pedgespanpackage + 28] = 0u8
        c2da_mem[d_pedgespanpackage + 29] = 0u8
        c2da_mem[d_pedgespanpackage + 30] = 0u8
        c2da_mem[d_pedgespanpackage + 31] = 0u8
        let c2da_fresh88 : uint = uint(d_sfrac)
        c2da_mem[d_pedgespanpackage + 32] = uint8(c2da_fresh88)
        c2da_mem[d_pedgespanpackage + 33] = uint8(c2da_fresh88 >> 0x8)
        c2da_mem[d_pedgespanpackage + 34] = uint8(c2da_fresh88 >> 0x10)
        c2da_mem[d_pedgespanpackage + 35] = uint8(c2da_fresh88 >> 0x18)
        let c2da_fresh89 : uint = uint(d_tfrac)
        c2da_mem[d_pedgespanpackage + 36] = uint8(c2da_fresh89)
        c2da_mem[d_pedgespanpackage + 37] = uint8(c2da_fresh89 >> 0x8)
        c2da_mem[d_pedgespanpackage + 38] = uint8(c2da_fresh89 >> 0x10)
        c2da_mem[d_pedgespanpackage + 39] = uint8(c2da_fresh89 >> 0x18)
        let c2da_fresh90 : uint = uint(d_light)
        c2da_mem[d_pedgespanpackage + 40] = uint8(c2da_fresh90)
        c2da_mem[d_pedgespanpackage + 41] = uint8(c2da_fresh90 >> 0x8)
        c2da_mem[d_pedgespanpackage + 42] = uint8(c2da_fresh90 >> 0x10)
        c2da_mem[d_pedgespanpackage + 43] = uint8(c2da_fresh90 >> 0x18)
        let c2da_fresh91 : uint = uint(d_zi)
        c2da_mem[d_pedgespanpackage + 44] = uint8(c2da_fresh91)
        c2da_mem[d_pedgespanpackage + 45] = uint8(c2da_fresh91 >> 0x8)
        c2da_mem[d_pedgespanpackage + 46] = uint8(c2da_fresh91 >> 0x10)
        c2da_mem[d_pedgespanpackage + 47] = uint8(c2da_fresh91 >> 0x18)
        d_pedgespanpackage += 48
        errorterm = errorterm + int(uint(c2da_mem[204432]) | uint(c2da_mem[204433]) << 0x8 | uint(c2da_mem[204434]) << 0x10 | uint(c2da_mem[204435]) << 0x18)
        if (errorterm >= 0) {
            d_pdest += d_pdestextrastep
            d_pz += d_pzextrastep * 2
            d_aspancount += d_countextrastep
            d_ptex += d_ptexextrastep
            d_sfrac += d_sfracextrastep
            d_ptex += d_sfrac >> 16
            d_sfrac &= 65535
            d_tfrac += d_tfracextrastep
            if ((d_tfrac & 65536) != 0) {
                d_ptex += int(r_affinetridesc.skinwidth)
                d_tfrac &= 65535
            }
            d_light += d_lightextrastep
            d_zi += d_ziextrastep
            errorterm = errorterm - erroradjustdown
        } else {
            d_pdest += d_pdestbasestep
            d_pz += d_pzbasestep * 2
            d_aspancount += int(uint(c2da_mem[204416]) | uint(c2da_mem[204417]) << 0x8 | uint(c2da_mem[204418]) << 0x10 | uint(c2da_mem[204419]) << 0x18)
            d_ptex += d_ptexbasestep
            d_sfrac += d_sfracbasestep
            d_ptex += d_sfrac >> 16
            d_sfrac &= 65535
            d_tfrac += d_tfracbasestep
            if ((d_tfrac & 65536) != 0) {
                d_ptex += int(r_affinetridesc.skinwidth)
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

var d_ptex : int = default<int>

var d_tfracbasestep : int = default<int>

var d_sfrac : int = default<int>

var d_sfracbasestep : int = default<int>

var d_ptexbasestep : int = default<int>

var d_pzbasestep : int = default<int>

var d_pz : int = default<int>

var d_pdestbasestep : int = default<int>

var d_pdest : int = default<int>

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
    let c2da_fresh92 : int = int(uint(c2da_mem[205248 + 0 * 4]) | uint(c2da_mem[205248 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[205248 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[205248 + 0 * 4 + 3]) << 0x18)
    p00_minus_p20 = float(int(uint(c2da_mem[205216 + 0 * 4]) | uint(c2da_mem[205216 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[205216 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[205216 + 0 * 4 + 3]) << 0x18) - c2da_fresh92)
    let c2da_fresh93 : int = int(uint(c2da_mem[205248 + 1 * 4]) | uint(c2da_mem[205248 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[205248 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[205248 + 1 * 4 + 3]) << 0x18)
    p01_minus_p21 = float(int(uint(c2da_mem[205216 + 1 * 4]) | uint(c2da_mem[205216 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[205216 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[205216 + 1 * 4 + 3]) << 0x18) - c2da_fresh93)
    p10_minus_p20 = float(int(uint(c2da_mem[205280 + 0 * 4]) | uint(c2da_mem[205280 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[205280 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[205280 + 0 * 4 + 3]) << 0x18) - c2da_fresh92)
    p11_minus_p21 = float(int(uint(c2da_mem[205280 + 1 * 4]) | uint(c2da_mem[205280 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[205280 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[205280 + 1 * 4 + 3]) << 0x18) - c2da_fresh93)
    xstepdenominv = float(1.0lf / double(float(d_xdenom)))
    ystepdenominv = -xstepdenominv
    let c2da_fresh94 : int = int(uint(c2da_mem[205248 + 4 * 4]) | uint(c2da_mem[205248 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[205248 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[205248 + 4 * 4 + 3]) << 0x18)
    t0 = float(int(uint(c2da_mem[205216 + 4 * 4]) | uint(c2da_mem[205216 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[205216 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[205216 + 4 * 4 + 3]) << 0x18) - c2da_fresh94)
    t1 = float(int(uint(c2da_mem[205280 + 4 * 4]) | uint(c2da_mem[205280 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[205280 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[205280 + 4 * 4 + 3]) << 0x18) - c2da_fresh94)
    r_lstepx = int(ceil(double((t1 * p01_minus_p21 - t0 * p11_minus_p21) * xstepdenominv)))
    r_lstepy = int(ceil(double((t1 * p00_minus_p20 - t0 * p10_minus_p20) * ystepdenominv)))
    let c2da_fresh95 : int = int(uint(c2da_mem[205248 + 2 * 4]) | uint(c2da_mem[205248 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[205248 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[205248 + 2 * 4 + 3]) << 0x18)
    t0 = float(int(uint(c2da_mem[205216 + 2 * 4]) | uint(c2da_mem[205216 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[205216 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[205216 + 2 * 4 + 3]) << 0x18) - c2da_fresh95)
    t1 = float(int(uint(c2da_mem[205280 + 2 * 4]) | uint(c2da_mem[205280 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[205280 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[205280 + 2 * 4 + 3]) << 0x18) - c2da_fresh95)
    r_sstepx = int((t1 * p01_minus_p21 - t0 * p11_minus_p21) * xstepdenominv)
    r_sstepy = int((t1 * p00_minus_p20 - t0 * p10_minus_p20) * ystepdenominv)
    let c2da_fresh96 : int = int(uint(c2da_mem[205248 + 3 * 4]) | uint(c2da_mem[205248 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[205248 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[205248 + 3 * 4 + 3]) << 0x18)
    t0 = float(int(uint(c2da_mem[205216 + 3 * 4]) | uint(c2da_mem[205216 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[205216 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[205216 + 3 * 4 + 3]) << 0x18) - c2da_fresh96)
    t1 = float(int(uint(c2da_mem[205280 + 3 * 4]) | uint(c2da_mem[205280 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[205280 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[205280 + 3 * 4 + 3]) << 0x18) - c2da_fresh96)
    r_tstepx = int((t1 * p01_minus_p21 - t0 * p11_minus_p21) * xstepdenominv)
    r_tstepy = int((t1 * p00_minus_p20 - t0 * p10_minus_p20) * ystepdenominv)
    let c2da_fresh97 : int = int(uint(c2da_mem[205248 + 5 * 4]) | uint(c2da_mem[205248 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[205248 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[205248 + 5 * 4 + 3]) << 0x18)
    t0 = float(int(uint(c2da_mem[205216 + 5 * 4]) | uint(c2da_mem[205216 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[205216 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[205216 + 5 * 4 + 3]) << 0x18) - c2da_fresh97)
    t1 = float(int(uint(c2da_mem[205280 + 5 * 4]) | uint(c2da_mem[205280 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[205280 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[205280 + 5 * 4 + 3]) << 0x18) - c2da_fresh97)
    r_zistepx = int((t1 * p01_minus_p21 - t0 * p11_minus_p21) * xstepdenominv)
    r_zistepy = int((t1 * p00_minus_p20 - t0 * p10_minus_p20) * ystepdenominv)
    a_sstepxfrac = r_sstepx & 65535
    a_tstepxfrac = r_tstepx & 65535
    a_ststepxwhole = skinwidth_0 * (r_tstepx >> 16) + (r_sstepx >> 16)
    return
}
var d_xdenom : int = default<int>

[export, sideeffects]
def D_PolysetSetEdgeTable() {
    var edgetableindex : int = 0
    let c2da_fresh98 : int = int(uint(c2da_mem[205216 + 1 * 4]) | uint(c2da_mem[205216 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[205216 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[205216 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh99 : int = int(uint(c2da_mem[205280 + 1 * 4]) | uint(c2da_mem[205280 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[205280 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[205280 + 1 * 4 + 3]) << 0x18)
    if (c2da_fresh98 >= c2da_fresh99) {
        if (c2da_fresh98 == c2da_fresh99) {
            if (c2da_fresh98 < int(uint(c2da_mem[205248 + 1 * 4]) | uint(c2da_mem[205248 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[205248 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[205248 + 1 * 4 + 3]) << 0x18)) {
                pedgetable = 204448 + 2 * 64
            } else {
                pedgetable = 204448 + 5 * 64
            }
            return
        } else {
            edgetableindex = 1
        }
    }
    if (int(uint(c2da_mem[205216 + 1 * 4]) | uint(c2da_mem[205216 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[205216 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[205216 + 1 * 4 + 3]) << 0x18) == int(uint(c2da_mem[205248 + 1 * 4]) | uint(c2da_mem[205248 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[205248 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[205248 + 1 * 4 + 3]) << 0x18)) {
        if (edgetableindex != 0) {
            pedgetable = 204448 + 8 * 64
        } else {
            pedgetable = 204448 + 9 * 64
        }
        return
    } elif (int(uint(c2da_mem[205280 + 1 * 4]) | uint(c2da_mem[205280 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[205280 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[205280 + 1 * 4 + 3]) << 0x18) == int(uint(c2da_mem[205248 + 1 * 4]) | uint(c2da_mem[205248 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[205248 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[205248 + 1 * 4 + 3]) << 0x18)) {
        if (edgetableindex != 0) {
            pedgetable = 204448 + 10 * 64
        } else {
            pedgetable = 204448 + 11 * 64
        }
        return
    }
    if (int(uint(c2da_mem[205216 + 1 * 4]) | uint(c2da_mem[205216 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[205216 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[205216 + 1 * 4 + 3]) << 0x18) > int(uint(c2da_mem[205248 + 1 * 4]) | uint(c2da_mem[205248 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[205248 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[205248 + 1 * 4 + 3]) << 0x18)) {
        edgetableindex += 2
    }
    if (int(uint(c2da_mem[205280 + 1 * 4]) | uint(c2da_mem[205280 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[205280 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[205280 + 1 * 4 + 3]) << 0x18) > int(uint(c2da_mem[205248 + 1 * 4]) | uint(c2da_mem[205248 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[205248 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[205248 + 1 * 4 + 3]) << 0x18)) {
        edgetableindex += 4
    }
    pedgetable = 204448 + edgetableindex * 64
    return
}
[export, sideeffects]
def D_DrawSubdiv() {
    var ptri_0 : int
    var pfv_0 : int
    var index0_0 : int
    var index1_0 : int
    var index2_0 : int
    var lnumtriangles_0 : int
    var s0 : int
    var s1 : int
    var s2 : int
    pfv_0 = r_affinetridesc.pfinalverts
    ptri_0 = r_affinetridesc.ptriangles
    lnumtriangles_0 = r_affinetridesc.numtriangles
    for (i_0 in range(0, lnumtriangles_0)) {
        index0_0 = pfv_0 + int(uint(c2da_mem[ptri_0 + i_0 * 16 + 4 + 0 * 4]) | uint(c2da_mem[ptri_0 + i_0 * 16 + 4 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ptri_0 + i_0 * 16 + 4 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ptri_0 + i_0 * 16 + 4 + 0 * 4 + 3]) << 0x18) * 32
        index1_0 = pfv_0 + int(uint(c2da_mem[ptri_0 + i_0 * 16 + 4 + 1 * 4]) | uint(c2da_mem[ptri_0 + i_0 * 16 + 4 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ptri_0 + i_0 * 16 + 4 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ptri_0 + i_0 * 16 + 4 + 1 * 4 + 3]) << 0x18) * 32
        index2_0 = pfv_0 + int(uint(c2da_mem[ptri_0 + i_0 * 16 + 4 + 2 * 4]) | uint(c2da_mem[ptri_0 + i_0 * 16 + 4 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ptri_0 + i_0 * 16 + 4 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ptri_0 + i_0 * 16 + 4 + 2 * 4 + 3]) << 0x18) * 32
        let c2da_fresh109 : int = int(uint(c2da_mem[index0_0 + 1 * 4]) | uint(c2da_mem[index0_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[index0_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[index0_0 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh110 : int = int(uint(c2da_mem[index0_0 + 0 * 4]) | uint(c2da_mem[index0_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[index0_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[index0_0 + 0 * 4 + 3]) << 0x18)
        if ((c2da_fresh109 - int(uint(c2da_mem[index1_0 + 1 * 4]) | uint(c2da_mem[index1_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[index1_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[index1_0 + 1 * 4 + 3]) << 0x18)) * (c2da_fresh110 - int(uint(c2da_mem[index2_0 + 0 * 4]) | uint(c2da_mem[index2_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[index2_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[index2_0 + 0 * 4 + 3]) << 0x18)) - (c2da_fresh110 - int(uint(c2da_mem[index1_0 + 0 * 4]) | uint(c2da_mem[index1_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[index1_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[index1_0 + 0 * 4 + 3]) << 0x18)) * (c2da_fresh109 - int(uint(c2da_mem[index2_0 + 1 * 4]) | uint(c2da_mem[index2_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[index2_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[index2_0 + 1 * 4 + 3]) << 0x18)) >= 0) {
            continue
        }
        d_pcolormap = acolormap + (int(uint(c2da_mem[index0_0 + 4 * 4]) | uint(c2da_mem[index0_0 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[index0_0 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[index0_0 + 4 * 4 + 3]) << 0x18) & 65280)
        if (int(uint(c2da_mem[ptri_0 + i_0 * 16]) | uint(c2da_mem[ptri_0 + i_0 * 16 + 1]) << 0x8 | uint(c2da_mem[ptri_0 + i_0 * 16 + 2]) << 0x10 | uint(c2da_mem[ptri_0 + i_0 * 16 + 3]) << 0x18) != 0) {
            D_PolysetRecursiveTriangle(index0_0, index1_0, index2_0)
        } else {
            let c2da_fresh111 : int = int(uint(c2da_mem[index0_0 + 2 * 4]) | uint(c2da_mem[index0_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[index0_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[index0_0 + 2 * 4 + 3]) << 0x18)
            s0 = c2da_fresh111
            s1 = int(uint(c2da_mem[index1_0 + 2 * 4]) | uint(c2da_mem[index1_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[index1_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[index1_0 + 2 * 4 + 3]) << 0x18)
            s2 = int(uint(c2da_mem[index2_0 + 2 * 4]) | uint(c2da_mem[index2_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[index2_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[index2_0 + 2 * 4 + 3]) << 0x18)
            if ((int(uint(c2da_mem[index0_0 + 24]) | uint(c2da_mem[index0_0 + 25]) << 0x8 | uint(c2da_mem[index0_0 + 26]) << 0x10 | uint(c2da_mem[index0_0 + 27]) << 0x18) & 32) != 0) {
                let c2da_fresh100 : int = c2da_fresh111 + int(r_affinetridesc.seamfixupX16)
                let c2da_fresh101 : uint = uint(c2da_fresh100)
                c2da_mem[index0_0 + 2 * 4] = uint8(c2da_fresh101)
                c2da_mem[index0_0 + 2 * 4 + 1] = uint8(c2da_fresh101 >> 0x8)
                c2da_mem[index0_0 + 2 * 4 + 2] = uint8(c2da_fresh101 >> 0x10)
                c2da_mem[index0_0 + 2 * 4 + 3] = uint8(c2da_fresh101 >> 0x18)
            }
            if ((int(uint(c2da_mem[index1_0 + 24]) | uint(c2da_mem[index1_0 + 25]) << 0x8 | uint(c2da_mem[index1_0 + 26]) << 0x10 | uint(c2da_mem[index1_0 + 27]) << 0x18) & 32) != 0) {
                let c2da_fresh102 : int = int(uint(c2da_mem[index1_0 + 2 * 4]) | uint(c2da_mem[index1_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[index1_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[index1_0 + 2 * 4 + 3]) << 0x18) + int(r_affinetridesc.seamfixupX16)
                let c2da_fresh103 : uint = uint(c2da_fresh102)
                c2da_mem[index1_0 + 2 * 4] = uint8(c2da_fresh103)
                c2da_mem[index1_0 + 2 * 4 + 1] = uint8(c2da_fresh103 >> 0x8)
                c2da_mem[index1_0 + 2 * 4 + 2] = uint8(c2da_fresh103 >> 0x10)
                c2da_mem[index1_0 + 2 * 4 + 3] = uint8(c2da_fresh103 >> 0x18)
            }
            if ((int(uint(c2da_mem[index2_0 + 24]) | uint(c2da_mem[index2_0 + 25]) << 0x8 | uint(c2da_mem[index2_0 + 26]) << 0x10 | uint(c2da_mem[index2_0 + 27]) << 0x18) & 32) != 0) {
                let c2da_fresh104 : int = int(uint(c2da_mem[index2_0 + 2 * 4]) | uint(c2da_mem[index2_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[index2_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[index2_0 + 2 * 4 + 3]) << 0x18) + int(r_affinetridesc.seamfixupX16)
                let c2da_fresh105 : uint = uint(c2da_fresh104)
                c2da_mem[index2_0 + 2 * 4] = uint8(c2da_fresh105)
                c2da_mem[index2_0 + 2 * 4 + 1] = uint8(c2da_fresh105 >> 0x8)
                c2da_mem[index2_0 + 2 * 4 + 2] = uint8(c2da_fresh105 >> 0x10)
                c2da_mem[index2_0 + 2 * 4 + 3] = uint8(c2da_fresh105 >> 0x18)
            }
            D_PolysetRecursiveTriangle(index0_0, index1_0, index2_0)
            let c2da_fresh106 : uint = uint(s0)
            c2da_mem[index0_0 + 2 * 4] = uint8(c2da_fresh106)
            c2da_mem[index0_0 + 2 * 4 + 1] = uint8(c2da_fresh106 >> 0x8)
            c2da_mem[index0_0 + 2 * 4 + 2] = uint8(c2da_fresh106 >> 0x10)
            c2da_mem[index0_0 + 2 * 4 + 3] = uint8(c2da_fresh106 >> 0x18)
            let c2da_fresh107 : uint = uint(s1)
            c2da_mem[index1_0 + 2 * 4] = uint8(c2da_fresh107)
            c2da_mem[index1_0 + 2 * 4 + 1] = uint8(c2da_fresh107 >> 0x8)
            c2da_mem[index1_0 + 2 * 4 + 2] = uint8(c2da_fresh107 >> 0x10)
            c2da_mem[index1_0 + 2 * 4 + 3] = uint8(c2da_fresh107 >> 0x18)
            let c2da_fresh108 : uint = uint(s2)
            c2da_mem[index2_0 + 2 * 4] = uint8(c2da_fresh108)
            c2da_mem[index2_0 + 2 * 4 + 1] = uint8(c2da_fresh108 >> 0x8)
            c2da_mem[index2_0 + 2 * 4 + 2] = uint8(c2da_fresh108 >> 0x10)
            c2da_mem[index2_0 + 2 * 4 + 3] = uint8(c2da_fresh108 >> 0x18)
        }
    }
    return
}
[export, sideeffects]
def D_PolysetRecursiveTriangle(var lp1 : int; var lp2 : int; var lp3 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    D_PolysetRecursiveTriangle_c2da_frame(lp1, lp2, lp3, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
var skintable : int[480]

var d_pcolormap : int = default<int>

[export, sideeffects]
def D_PolysetDrawFinalVerts(var fv_0 : int; var numverts : int) {
    var i_1 : int
    var z_0 : int
    var zbuf_0 : int
    var pix_0 : int
    i_1 = 0
    while (i_1 < numverts) {
        let c2da_fresh134 : int = int(uint(c2da_mem[fv_0 + 0 * 4]) | uint(c2da_mem[fv_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[fv_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[fv_0 + 0 * 4 + 3]) << 0x18)
        if (c2da_fresh134 < int(uint(c2da_mem[5248]) | uint(c2da_mem[5249]) << 0x8 | uint(c2da_mem[5250]) << 0x10 | uint(c2da_mem[5251]) << 0x18) && int(uint(c2da_mem[fv_0 + 1 * 4]) | uint(c2da_mem[fv_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[fv_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[fv_0 + 1 * 4 + 3]) << 0x18) < int(uint(c2da_mem[5252]) | uint(c2da_mem[5253]) << 0x8 | uint(c2da_mem[5254]) << 0x10 | uint(c2da_mem[5255]) << 0x18)) {
            z_0 = int(uint(c2da_mem[fv_0 + 5 * 4]) | uint(c2da_mem[fv_0 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[fv_0 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[fv_0 + 5 * 4 + 3]) << 0x18) >> 16
            let c2da_fresh135 : int = int(uint(c2da_mem[fv_0 + 1 * 4]) | uint(c2da_mem[fv_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[fv_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[fv_0 + 1 * 4 + 3]) << 0x18)
            zbuf_0 = zspantable[c2da_fresh135] + c2da_fresh134 * 2
            if (z_0 >= int(int16(uint(c2da_mem[zbuf_0]) | uint(c2da_mem[zbuf_0 + 1]) << 0x8))) {
                let c2da_fresh128 : int16 = int16(z_0)
                let c2da_fresh129 : uint = uint(c2da_fresh128)
                c2da_mem[zbuf_0] = uint8(c2da_fresh129)
                c2da_mem[zbuf_0 + 1] = uint8(c2da_fresh129 >> 0x8)
                let c2da_fresh130 : int = skintable[int(uint(c2da_mem[fv_0 + 3 * 4]) | uint(c2da_mem[fv_0 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[fv_0 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[fv_0 + 3 * 4 + 3]) << 0x18) >> 16] + (int(uint(c2da_mem[fv_0 + 2 * 4]) | uint(c2da_mem[fv_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[fv_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[fv_0 + 2 * 4 + 3]) << 0x18) >> 16)
                pix_0 = int(c2da_mem[c2da_fresh130])
                let c2da_fresh131 : int = acolormap + (pix_0 + (int(uint(c2da_mem[fv_0 + 4 * 4]) | uint(c2da_mem[fv_0 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[fv_0 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[fv_0 + 4 * 4 + 3]) << 0x18) & 65280))
                pix_0 = int(c2da_mem[c2da_fresh131])
                let c2da_fresh132 : int = d_viewbuffer + int(d_scantable[int(uint(c2da_mem[fv_0 + 1 * 4]) | uint(c2da_mem[fv_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[fv_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[fv_0 + 1 * 4 + 3]) << 0x18)] + int(uint(c2da_mem[fv_0 + 0 * 4]) | uint(c2da_mem[fv_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[fv_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[fv_0 + 0 * 4 + 3]) << 0x18))
                let c2da_fresh133 : uint8 = uint8(pix_0)
                c2da_mem[c2da_fresh132] = c2da_fresh133
            }
        }
        i_1++
        fv_0 += 32
    }
    return
}
[export, sideeffects]
def D_PolysetUpdateTables() {
    var i_2 : int
    var s : int
    if (r_affinetridesc.skinwidth != skinwidth || r_affinetridesc.pskin != skinstart) {
        skinwidth = r_affinetridesc.skinwidth
        skinstart = r_affinetridesc.pskin
        s = skinstart
        i_2 = 0
        while (i_2 < 480) {
            skintable[i_2] = s
            i_2++
            s += skinwidth
        }
    }
    return
}
var skinwidth : int = default<int>

var skinstart : int = default<int>

var d_aflatcolor : int = default<int>

[export, sideeffects]
def D_PolysetFillSpans8(var pspanpackage_0 : int) {
    var color : int
    var lcount_0 : int
    var lpdest_0 : int
    let c2da_postinc : int = d_aflatcolor
    d_aflatcolor++
    color = c2da_postinc
    while (true) {
        lcount_0 = int(uint(c2da_mem[pspanpackage_0 + 16]) | uint(c2da_mem[pspanpackage_0 + 17]) << 0x8 | uint(c2da_mem[pspanpackage_0 + 18]) << 0x10 | uint(c2da_mem[pspanpackage_0 + 19]) << 0x18)
        if (lcount_0 == -1) {
            return
        }
        if (lcount_0 != 0) {
            lpdest_0 = int(uint(c2da_mem[pspanpackage_0]) | uint(c2da_mem[pspanpackage_0 + 1]) << 0x8 | uint(c2da_mem[pspanpackage_0 + 2]) << 0x10 | uint(c2da_mem[pspanpackage_0 + 3]) << 0x18)
            while (true) {
                let c2da_fresh136 : int = lpdest_0
                lpdest_0++
                let c2da_fresh137 : uint8 = uint8(color)
                c2da_mem[c2da_fresh136] = c2da_fresh137
                lcount_0--
                if (lcount_0 == 0) {
                    break
                }
            }
        }
        pspanpackage_0 += 48
    }
}
[sideeffects]
def private D_PolysetDraw_c2da_frame(c2da_fp : int) {
    a_spans = int(int64(c2da_fp + 0 * 48) + 32l - 1l & int64(~(32 - 1)))
    if (r_affinetridesc.drawtype != 0) {
        D_DrawSubdiv()
    } else {
        D_DrawNonSubdiv()
    }
    return
}
[sideeffects]
def private D_PolysetRecursiveTriangle_c2da_frame(var lp1 : int; var lp2 : int; var lp3 : int; c2da_fp : int) {
    var temp : int
    var d : int
    var z : int
    var zbuf : int
    var pix : int
    d = int(uint(c2da_mem[lp2 + 0 * 4]) | uint(c2da_mem[lp2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[lp2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[lp2 + 0 * 4 + 3]) << 0x18) - int(uint(c2da_mem[lp1 + 0 * 4]) | uint(c2da_mem[lp1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[lp1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[lp1 + 0 * 4 + 3]) << 0x18)
    if (d < -1 || d > 1) {
        goto label 13
    }
    d = int(uint(c2da_mem[lp2 + 1 * 4]) | uint(c2da_mem[lp2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[lp2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[lp2 + 1 * 4 + 3]) << 0x18) - int(uint(c2da_mem[lp1 + 1 * 4]) | uint(c2da_mem[lp1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[lp1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[lp1 + 1 * 4 + 3]) << 0x18)
    if (d < -1 || d > 1) {
        goto label 12
    }
    d = int(uint(c2da_mem[lp3 + 0 * 4]) | uint(c2da_mem[lp3 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[lp3 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[lp3 + 0 * 4 + 3]) << 0x18) - int(uint(c2da_mem[lp2 + 0 * 4]) | uint(c2da_mem[lp2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[lp2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[lp2 + 0 * 4 + 3]) << 0x18)
    if (d < -1 || d > 1) {
        goto label 11
    }
    d = int(uint(c2da_mem[lp3 + 1 * 4]) | uint(c2da_mem[lp3 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[lp3 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[lp3 + 1 * 4 + 3]) << 0x18) - int(uint(c2da_mem[lp2 + 1 * 4]) | uint(c2da_mem[lp2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[lp2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[lp2 + 1 * 4 + 3]) << 0x18)
    if (d < -1 || d > 1) {
        goto label 9
    }
    d = int(uint(c2da_mem[lp1 + 0 * 4]) | uint(c2da_mem[lp1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[lp1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[lp1 + 0 * 4 + 3]) << 0x18) - int(uint(c2da_mem[lp3 + 0 * 4]) | uint(c2da_mem[lp3 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[lp3 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[lp3 + 0 * 4 + 3]) << 0x18)
    if (d < -1 || d > 1) {
        goto label 8
    }
    d = int(uint(c2da_mem[lp1 + 1 * 4]) | uint(c2da_mem[lp1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[lp1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[lp1 + 1 * 4 + 3]) << 0x18) - int(uint(c2da_mem[lp3 + 1 * 4]) | uint(c2da_mem[lp3 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[lp3 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[lp3 + 1 * 4 + 3]) << 0x18)
    if (d < -1 || d > 1) {
        goto label 0
    }
    return
    label 0:
    label 1:
    temp = lp1
    lp1 = int(lp3)  // nolint:PERF020
    lp3 = int(lp2)  // nolint:PERF020
    lp2 = temp
    label 2:
    let c2da_fresh112 : int = int(uint(c2da_mem[lp1 + 0 * 4]) | uint(c2da_mem[lp1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[lp1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[lp1 + 0 * 4 + 3]) << 0x18) + int(uint(c2da_mem[lp2 + 0 * 4]) | uint(c2da_mem[lp2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[lp2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[lp2 + 0 * 4 + 3]) << 0x18) >> 1
    let c2da_fresh113 : uint = uint(c2da_fresh112)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh113)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh113 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh113 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh113 >> 0x18)
    let c2da_fresh114 : int = int(uint(c2da_mem[lp1 + 1 * 4]) | uint(c2da_mem[lp1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[lp1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[lp1 + 1 * 4 + 3]) << 0x18) + int(uint(c2da_mem[lp2 + 1 * 4]) | uint(c2da_mem[lp2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[lp2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[lp2 + 1 * 4 + 3]) << 0x18) >> 1
    let c2da_fresh115 : uint = uint(c2da_fresh114)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh115)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh115 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh115 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh115 >> 0x18)
    let c2da_fresh116 : int = int(uint(c2da_mem[lp1 + 2 * 4]) | uint(c2da_mem[lp1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[lp1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[lp1 + 2 * 4 + 3]) << 0x18) + int(uint(c2da_mem[lp2 + 2 * 4]) | uint(c2da_mem[lp2 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[lp2 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[lp2 + 2 * 4 + 3]) << 0x18) >> 1
    let c2da_fresh117 : uint = uint(c2da_fresh116)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh117)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh117 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh117 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh117 >> 0x18)
    let c2da_fresh118 : int = int(uint(c2da_mem[lp1 + 3 * 4]) | uint(c2da_mem[lp1 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[lp1 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[lp1 + 3 * 4 + 3]) << 0x18) + int(uint(c2da_mem[lp2 + 3 * 4]) | uint(c2da_mem[lp2 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[lp2 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[lp2 + 3 * 4 + 3]) << 0x18) >> 1
    let c2da_fresh119 : uint = uint(c2da_fresh118)
    c2da_mem[c2da_fp + 3 * 4] = uint8(c2da_fresh119)
    c2da_mem[c2da_fp + 3 * 4 + 1] = uint8(c2da_fresh119 >> 0x8)
    c2da_mem[c2da_fp + 3 * 4 + 2] = uint8(c2da_fresh119 >> 0x10)
    c2da_mem[c2da_fp + 3 * 4 + 3] = uint8(c2da_fresh119 >> 0x18)
    let c2da_fresh120 : int = int(uint(c2da_mem[lp1 + 5 * 4]) | uint(c2da_mem[lp1 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[lp1 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[lp1 + 5 * 4 + 3]) << 0x18) + int(uint(c2da_mem[lp2 + 5 * 4]) | uint(c2da_mem[lp2 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[lp2 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[lp2 + 5 * 4 + 3]) << 0x18) >> 1
    let c2da_fresh121 : uint = uint(c2da_fresh120)
    c2da_mem[c2da_fp + 5 * 4] = uint8(c2da_fresh121)
    c2da_mem[c2da_fp + 5 * 4 + 1] = uint8(c2da_fresh121 >> 0x8)
    c2da_mem[c2da_fp + 5 * 4 + 2] = uint8(c2da_fresh121 >> 0x10)
    c2da_mem[c2da_fp + 5 * 4 + 3] = uint8(c2da_fresh121 >> 0x18)
    if (int(uint(c2da_mem[lp2 + 1 * 4]) | uint(c2da_mem[lp2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[lp2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[lp2 + 1 * 4 + 3]) << 0x18) > int(uint(c2da_mem[lp1 + 1 * 4]) | uint(c2da_mem[lp1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[lp1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[lp1 + 1 * 4 + 3]) << 0x18)) {
        goto label 7
    }
    if (int(uint(c2da_mem[lp2 + 1 * 4]) | uint(c2da_mem[lp2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[lp2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[lp2 + 1 * 4 + 3]) << 0x18) == int(uint(c2da_mem[lp1 + 1 * 4]) | uint(c2da_mem[lp1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[lp1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[lp1 + 1 * 4 + 3]) << 0x18) && int(uint(c2da_mem[lp2 + 0 * 4]) | uint(c2da_mem[lp2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[lp2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[lp2 + 0 * 4 + 3]) << 0x18) < int(uint(c2da_mem[lp1 + 0 * 4]) | uint(c2da_mem[lp1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[lp1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[lp1 + 0 * 4 + 3]) << 0x18)) {
        goto label 6
    }
    z = int(uint(c2da_mem[c2da_fp + 5 * 4]) | uint(c2da_mem[c2da_fp + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 5 * 4 + 3]) << 0x18) >> 16
    zbuf = zspantable[int(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)] + int(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) * 2
    if (z >= int(int16(uint(c2da_mem[zbuf]) | uint(c2da_mem[zbuf + 1]) << 0x8))) {
        goto label 5
    }
    label 3:
    label 4:
    D_PolysetRecursiveTriangle(lp3, lp1, c2da_fp)
    D_PolysetRecursiveTriangle(lp3, c2da_fp, lp2)
    return
    label 5:
    let c2da_fresh122 : int16 = int16(z)
    let c2da_fresh123 : uint = uint(c2da_fresh122)
    c2da_mem[zbuf] = uint8(c2da_fresh123)
    c2da_mem[zbuf + 1] = uint8(c2da_fresh123 >> 0x8)
    let c2da_fresh124 : int = skintable[int(uint(c2da_mem[c2da_fp + 3 * 4]) | uint(c2da_mem[c2da_fp + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3 * 4 + 3]) << 0x18) >> 16] + (int(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) >> 16)
    let c2da_fresh125 : int = d_pcolormap + int(c2da_mem[c2da_fresh124])
    pix = int(c2da_mem[c2da_fresh125])
    let c2da_fresh126 : int = d_viewbuffer + int(d_scantable[int(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)] + int(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18))
    let c2da_fresh127 : uint8 = uint8(pix)
    c2da_mem[c2da_fresh126] = c2da_fresh127
    goto label 3
    label 6:
    goto label 4
    label 7:
    goto label 4
    label 8:
    goto label 1
    label 9:
    label 10:
    temp = lp1
    lp1 = int(lp2)  // nolint:PERF020
    lp2 = int(lp3)  // nolint:PERF020
    lp3 = temp
    goto label 2
    label 11:
    goto label 10
    label 12:
    goto label 2
    label 13:
    goto label 2
    panic("unreachable: fell out of a translated control-flow graph")
}

// This unit's static data, at heap offset 707024.
let private c2da_lin_static_d_polyse_seg = fixed_array<int>(707024, 3837, 711120, 4089)
let private c2da_lin_static_d_polyse = fixed_array<uint64>(0x1ul, 0xffffffff00000001ul, 0xfffffffe00000001ul, 0xfffffffd00000001ul, 0xfffffffc00000001ul, 0xfffffffb00000001ul, 0xfffffffa00000001ul, 0xfffffff900000001ul, 0xffffffff00000002ul, 0xfffffffd00000002ul, 0x3ul, 0xfffffffd00000003ul, 0x5ul, 0xffffffff00000007ul, 0xful, 0x0ul, 0xfffffff1ul, 0x1fffffff8ul, 0xfffffffbul, 0x1fffffffcul, 0xfffffffdul, 0x3fffffffdul, 0x6fffffffdul, 0x1fffffffeul, 0x3fffffffeul, 0x5fffffffeul, 0x7fffffffeul, 0x9fffffffeul, 0xbfffffffeul, 0xdfffffffeul, 0xfffffffful, 0x1fffffffful, 0xfffffff200000000ul, 0x1ul, 0xffffffff00000001ul, 0xfffffffe00000001ul, 0xfffffffd00000001ul, 0xfffffffc00000001ul, 0xfffffffb00000001ul, 0xfffffffa00000001ul, 0x2ul, 0xfffffffe00000002ul, 0xfffffffc00000002ul, 0xfffffffe00000003ul, 0xfffffffe00000004ul, 0x7ul, 0xeul, 0x0ul, 0xfffffff2ul, 0xfffffff9ul, 0x1fffffffbul, 0x2fffffffcul, 0x1fffffffdul, 0x4fffffffdul, 0xfffffffeul, 0x2fffffffeul, 0x4fffffffeul, 0x6fffffffeul, 0x8fffffffeul, 0xafffffffeul, 0xcfffffffeul, 0xfffffffful, 0x1fffffffful, 0x2fffffffful, 0xfffffff300000000ul, 0xfffffff300000000ul, 0x1ul, 0xffffffff00000001ul, 0xfffffffe00000001ul, 0xfffffffd00000001ul, 0xfffffffc00000001ul, 0xfffffffb00000001ul, 0xfffffffa00000001ul, 0xffffffff00000002ul, 0xfffffffd00000002ul, 0xffffffff00000003ul, 0xffffffff00000004ul, 0xffffffff00000006ul, 0xdul, 0x0ul, 0xfffffff3ul, 0x1fffffff9ul, 0x2fffffffbul, 0x3fffffffcul, 0x2fffffffdul, 0x5fffffffdul, 0x1fffffffeul, 0x3fffffffeul, 0x5fffffffeul, 0x7fffffffeul, 0x9fffffffeul, 0xbfffffffeul, 0xfffffffful, 0x1fffffffful, 0x2fffffffful, 0x3fffffffful, 0xfffffff400000000ul, 0xfffffff400000000ul, 0xfffffff400000000ul, 0x1ul, 0xffffffff00000001ul, 0xfffffffe00000001ul, 0xfffffffd00000001ul, 0xfffffffc00000001ul, 0xfffffffb00000001ul, 0x2ul, 0xfffffffe00000002ul, 0x3ul, 0x4ul, 0x6ul, 0xcul, 0x0ul, 0xfffffff4ul, 0xfffffffaul, 0xfffffffcul, 0xfffffffdul, 0x3fffffffdul, 0xfffffffeul, 0x2fffffffeul, 0x4fffffffeul, 0x6fffffffeul, 0x8fffffffeul, 0xafffffffeul, 0xfffffffful, 0x1fffffffful, 0x2fffffffful, 0x3fffffffful, 0x4fffffffful, 0xfffffff500000000ul, 0xfffffff500000000ul, 0xfffffff500000000ul, 0xfffffff500000000ul, 0x1ul, 0xffffffff00000001ul, 0xfffffffe00000001ul, 0xfffffffd00000001ul, 0xfffffffc00000001ul, 0xfffffffb00000001ul, 0xffffffff00000002ul, 0xfffffffd00000002ul, 0xfffffffe00000003ul, 0xffffffff00000005ul, 0xbul, 0x0ul, 0xfffffff5ul, 0x1fffffffaul, 0x1fffffffcul, 0x1fffffffdul, 0x4fffffffdul, 0x1fffffffeul, 0x3fffffffeul, 0x5fffffffeul, 0x7fffffffeul, 0x9fffffffeul, 0xfffffffful, 0x1fffffffful, 0x2fffffffful, 0x3fffffffful, 0x4fffffffful, 0x5fffffffful, 0xfffffff600000000ul, 0xfffffff600000000ul, 0xfffffff600000000ul, 0xfffffff600000000ul, 0xfffffff600000000ul, 0x1ul, 0xffffffff00000001ul, 0xfffffffe00000001ul, 0xfffffffd00000001ul, 0xfffffffc00000001ul, 0x2ul, 0xfffffffe00000002ul, 0xffffffff00000003ul, 0x5ul, 0xaul, 0x0ul, 0xfffffff6ul, 0xfffffffbul, 0x2fffffffcul, 0x2fffffffdul, 0xfffffffeul, 0x2fffffffeul, 0x4fffffffeul, 0x6fffffffeul, 0x8fffffffeul, 0xfffffffful, 0x1fffffffful, 0x2fffffffful, 0x3fffffffful, 0x4fffffffful, 0x5fffffffful, 0x6fffffffful, 0xfffffff700000000ul, 0xfffffff700000000ul, 0xfffffff700000000ul, 0xfffffff700000000ul, 0xfffffff700000000ul, 0xfffffff700000000ul, 0x1ul, 0xffffffff00000001ul, 0xfffffffe00000001ul, 0xfffffffd00000001ul, 0xfffffffc00000001ul, 0xffffffff00000002ul, 0x3ul, 0xffffffff00000004ul, 0x9ul, 0x0ul, 0xfffffff7ul, 0x1fffffffbul, 0xfffffffdul, 0x3fffffffdul, 0x1fffffffeul, 0x3fffffffeul, 0x5fffffffeul, 0x7fffffffeul, 0xfffffffful, 0x1fffffffful, 0x2fffffffful, 0x3fffffffful, 0x4fffffffful, 0x5fffffffful, 0x6fffffffful, 0x7fffffffful, 0xfffffff800000000ul, 0xfffffff800000000ul, 0xfffffff800000000ul, 0xfffffff800000000ul, 0xfffffff800000000ul, 0xfffffff800000000ul, 0xfffffff800000000ul, 0x1ul, 0xffffffff00000001ul, 0xfffffffe00000001ul, 0xfffffffd00000001ul, 0x2ul, 0xfffffffe00000002ul, 0x4ul, 0x8ul, 0x0ul, 0xfffffff8ul, 0xfffffffcul, 0x1fffffffdul, 0xfffffffeul, 0x2fffffffeul, 0x4fffffffeul, 0x6fffffffeul, 0xfffffffful, 0x1fffffffful, 0x2fffffffful, 0x3fffffffful, 0x4fffffffful, 0x5fffffffful, 0x6fffffffful, 0x7fffffffful, 0x8fffffffful, 0xfffffff900000000ul, 0xfffffff900000000ul, 0xfffffff900000000ul, 0xfffffff900000000ul, 0xfffffff900000000ul, 0xfffffff900000000ul, 0xfffffff900000000ul, 0xfffffff900000000ul, 0x1ul, 0xffffffff00000001ul, 0xfffffffe00000001ul, 0xfffffffd00000001ul, 0xffffffff00000002ul, 0xffffffff00000003ul, 0x7ul, 0x0ul, 0xfffffff9ul, 0x1fffffffcul, 0x2fffffffdul, 0x1fffffffeul, 0x3fffffffeul, 0x5fffffffeul, 0xfffffffful, 0x1fffffffful, 0x2fffffffful, 0x3fffffffful, 0x4fffffffful, 0x5fffffffful, 0x6fffffffful, 0x7fffffffful, 0x8fffffffful, 0x9fffffffful, 0xfffffffa00000000ul, 0xfffffffa00000000ul, 0xfffffffa00000000ul, 0xfffffffa00000000ul, 0xfffffffa00000000ul, 0xfffffffa00000000ul, 0xfffffffa00000000ul, 0xfffffffa00000000ul, 0xfffffffa00000000ul, 0x1ul, 0xffffffff00000001ul, 0xfffffffe00000001ul, 0x2ul, 0x3ul, 0x6ul, 0x0ul, 0xfffffffaul, 0xfffffffdul, 0xfffffffeul, 0x2fffffffeul, 0x4fffffffeul, 0xfffffffful, 0x1fffffffful, 0x2fffffffful, 0x3fffffffful, 0x4fffffffful, 0x5fffffffful, 0x6fffffffful, 0x7fffffffful, 0x8fffffffful, 0x9fffffffful, 0xafffffffful, 0xfffffffb00000000ul, 0xfffffffb00000000ul, 0xfffffffb00000000ul, 0xfffffffb00000000ul, 0xfffffffb00000000ul, 0xfffffffb00000000ul, 0xfffffffb00000000ul, 0xfffffffb00000000ul, 0xfffffffb00000000ul, 0xfffffffb00000000ul, 0x1ul, 0xffffffff00000001ul, 0xfffffffe00000001ul, 0xffffffff00000002ul, 0x5ul, 0x0ul, 0xfffffffbul, 0x1fffffffdul, 0x1fffffffeul, 0x3fffffffeul, 0xfffffffful, 0x1fffffffful, 0x2fffffffful, 0x3fffffffful, 0x4fffffffful, 0x5fffffffful, 0x6fffffffful, 0x7fffffffful, 0x8fffffffful, 0x9fffffffful, 0xafffffffful, 0xbfffffffful, 0xfffffffc00000000ul, 0xfffffffc00000000ul, 0xfffffffc00000000ul, 0xfffffffc00000000ul, 0xfffffffc00000000ul, 0xfffffffc00000000ul, 0xfffffffc00000000ul, 0xfffffffc00000000ul, 0xfffffffc00000000ul, 0xfffffffc00000000ul, 0xfffffffc00000000ul, 0x1ul, 0xffffffff00000001ul, 0x2ul, 0x4ul, 0x0ul, 0xfffffffcul, 0xfffffffeul, 0x2fffffffeul, 0xfffffffful, 0x1fffffffful, 0x2fffffffful, 0x3fffffffful, 0x4fffffffful, 0x5fffffffful, 0x6fffffffful, 0x7fffffffful, 0x8fffffffful, 0x9fffffffful, 0xafffffffful, 0xbfffffffful, 0xcfffffffful, 0xfffffffd00000000ul, 0xfffffffd00000000ul, 0xfffffffd00000000ul, 0xfffffffd00000000ul, 0xfffffffd00000000ul, 0xfffffffd00000000ul, 0xfffffffd00000000ul, 0xfffffffd00000000ul, 0xfffffffd00000000ul, 0xfffffffd00000000ul, 0xfffffffd00000000ul, 0xfffffffd00000000ul, 0x1ul, 0xffffffff00000001ul, 0x3ul, 0x0ul, 0xfffffffdul, 0x1fffffffeul, 0xfffffffful, 0x1fffffffful, 0x2fffffffful, 0x3fffffffful, 0x4fffffffful, 0x5fffffffful, 0x6fffffffful, 0x7fffffffful, 0x8fffffffful, 0x9fffffffful, 0xafffffffful, 0xbfffffffful, 0xcfffffffful, 0xdfffffffful, 0xfffffffe00000000ul, 0xfffffffe00000000ul, 0xfffffffe00000000ul, 0xfffffffe00000000ul, 0xfffffffe00000000ul, 0xfffffffe00000000ul, 0xfffffffe00000000ul, 0xfffffffe00000000ul, 0xfffffffe00000000ul, 0xfffffffe00000000ul, 0xfffffffe00000000ul, 0xfffffffe00000000ul, 0xfffffffe00000000ul, 0x1ul, 0x2ul, 0x0ul, 0xfffffffeul, 0xfffffffful, 0x1fffffffful, 0x2fffffffful, 0x3fffffffful, 0x4fffffffful, 0x5fffffffful, 0x6fffffffful, 0x7fffffffful, 0x8fffffffful, 0x9fffffffful, 0xafffffffful, 0xbfffffffful, 0xcfffffffful, 0xdfffffffful, 0xefffffffful, 0xffffffff00000000ul, 0xffffffff00000000ul, 0xffffffff00000000ul, 0xffffffff00000000ul, 0xffffffff00000000ul, 0xffffffff00000000ul, 0xffffffff00000000ul, 0xffffffff00000000ul, 0xffffffff00000000ul, 0xffffffff00000000ul, 0xffffffff00000000ul, 0xffffffff00000000ul, 0xffffffff00000000ul, 0xffffffff00000000ul, 0x1ul, 0x0ul, 0xfffffffful, 0x1fffffffful, 0x2fffffffful, 0x3fffffffful, 0x4fffffffful, 0x5fffffffful, 0x6fffffffful, 0x7fffffffful, 0x8fffffffful, 0x9fffffffful, 0xafffffffful, 0xbfffffffful, 0xcfffffffful, 0xdfffffffful, 0xefffffffful, 0xffffff0ffffffffful, 0xfffffffffffff2fful, 0xfffffffffffff3fful, 0xfffffffffffff4fful, 0xfffffffffffff5fful, 0xfffffffffffff6fful, 0xfffffffffffff7fful, 0xfffffffffffff8fful, 0xfffffffffffff9fful, 0xfffffffffffffafful, 0xfffffffffffffbfful, 0xfffffffffffffcfful, 0xfffffffffffffdfful, 0xfffffffffffffefful, 0xfffffffffffffffful, 0xfful, 0x10000000000ul, 0x0ul, 0x100ul, 0x100ul, 0x100ul, 0x100ul, 0x100ul, 0x100ul, 0x100ul, 0x100ul, 0x100ul, 0x100ul, 0x100ul, 0x100ul, 0x100ul, 0x100ul, 0xffffff0000000100ul, 0xfffffffffffff3fful, 0xfffffffffffff4fful, 0xfffffffffffff5fful, 0xfffffffffffff6fful, 0xfffffffffffff7fful, 0xfffffffffffff8fful, 0xfffffffffffff9fful, 0xfffffffffffffafful, 0xfffffffffffffbfful, 0xfffffffffffffcfful, 0xfffffffffffffdfful, 0xfffffffffffffefful, 0xfffffffffffffffful, 0xfffffe00000000fful, 0xfful, 0x20000000000ul, 0x10000000000ul, 0x0ul, 0x200ul, 0x200ul, 0x200ul, 0x200ul, 0x200ul, 0x200ul, 0x200ul, 0x200ul, 0x200ul, 0x200ul, 0x200ul, 0x200ul, 0x200ul, 0xffffff0000000200ul, 0xfffffffffffff4fful, 0xfffffffffffff5fful, 0xfffffffffffff6fful, 0xfffffffffffff7fful, 0xfffffffffffff8fful, 0xfffffffffffff9fful, 0xfffffffffffffafful, 0xfffffffffffffbfful, 0xfffffffffffffcfful, 0xfffffffffffffdfful, 0xfffffffffffffefful, 0xfffffffffffffffful, 0xfffffe00000000fful, 0xfffffdfffffffffful, 0xfful, 0x30000000000ul, 0x10000000000ul, 0x10000000100ul, 0x0ul, 0x300ul, 0x300ul, 0x300ul, 0x300ul, 0x300ul, 0x300ul, 0x300ul, 0x300ul, 0x300ul, 0x300ul, 0x300ul, 0x300ul, 0xffffff0000000300ul, 0xfffffffffffff5fful, 0xfffffffffffff6fful, 0xfffffffffffff7fful, 0xfffffffffffff8fful, 0xfffffffffffff9fful, 0xfffffffffffffafful, 0xfffffffffffffbfful, 0xfffffffffffffcfful, 0xfffffffffffffdfful, 0xfffffffffffffefful, 0xfffffffffffffffful, 0xfffffe00000000fful, 0xfffffefffffffefful, 0xfffffc00000000fful, 0xfful, 0x40000000000ul, 0x20000000000ul, 0x10000000000ul, 0x10000000100ul, 0x0ul, 0x400ul, 0x400ul, 0x400ul, 0x400ul, 0x400ul, 0x400ul, 0x400ul, 0x400ul, 0x400ul, 0x400ul, 0x400ul, 0xffffff0000000400ul, 0xfffffffffffff6fful, 0xfffffffffffff7fful, 0xfffffffffffff8fful, 0xfffffffffffff9fful, 0xfffffffffffffafful, 0xfffffffffffffbfful, 0xfffffffffffffcfful, 0xfffffffffffffdfful, 0xfffffffffffffefful, 0xfffffffffffffffful, 0xfffffe00000000fful, 0xfffffefffffffdfful, 0xfffffdfffffffffful, 0xfffffbfffffffffful, 0xfful, 0x50000000000ul, 0x20000000000ul, 0x10000000100ul, 0x10000000200ul, 0x10000000100ul, 0x0ul, 0x500ul, 0x500ul, 0x500ul, 0x500ul, 0x500ul, 0x500ul, 0x500ul, 0x500ul, 0x500ul, 0x500ul, 0xffffff0000000500ul, 0xfffffffffffff7fful, 0xfffffffffffff8fful, 0xfffffffffffff9fful, 0xfffffffffffffafful, 0xfffffffffffffbfful, 0xfffffffffffffcfful, 0xfffffffffffffdfful, 0xfffffffffffffefful, 0xfffffffffffffffful, 0xfffffe00000000fful, 0xfffffefffffffcfful, 0xfffffefffffffefful, 0xfffffd00000000fful, 0xfffffa00000000fful, 0xfful, 0x60000000000ul, 0x30000000000ul, 0x20000000000ul, 0x10000000000ul, 0x10000000200ul, 0x10000000100ul, 0x0ul, 0x600ul, 0x600ul, 0x600ul, 0x600ul, 0x600ul, 0x600ul, 0x600ul, 0x600ul, 0x600ul, 0xffffff0000000600ul, 0xfffffffffffff8fful, 0xfffffffffffff9fful, 0xfffffffffffffafful, 0xfffffffffffffbfful, 0xfffffffffffffcfful, 0xfffffffffffffdfful, 0xfffffffffffffefful, 0xfffffffffffffffful, 0xfffffe00000000fful, 0xfffffefffffffbfful, 0xfffffefffffffdfful, 0xfffffdfffffffffful, 0xfffffcfffffffefful, 0xfffff9fffffffffful, 0xfful, 0x70000000000ul, 0x30000000000ul, 0x20000000100ul, 0x10000000100ul, 0x10000000300ul, 0x10000000200ul, 0x10000000100ul, 0x0ul, 0x700ul, 0x700ul, 0x700ul, 0x700ul, 0x700ul, 0x700ul, 0x700ul, 0x700ul, 0xffffff0000000700ul, 0xfffffffffffff9fful, 0xfffffffffffffafful, 0xfffffffffffffbfful, 0xfffffffffffffcfful, 0xfffffffffffffdfful, 0xfffffffffffffefful, 0xfffffffffffffffful, 0xfffffe00000000fful, 0xfffffefffffffafful, 0xfffffefffffffcfful, 0xfffffefffffffefful, 0xfffffd00000000fful, 0xfffffcfffffffffful, 0xfffff800000000fful, 0xfful, 0x80000000000ul, 0x40000000000ul, 0x20000000000ul, 0x20000000200ul, 0x10000000000ul, 0x10000000300ul, 0x10000000200ul, 0x10000000100ul, 0x0ul, 0x800ul, 0x800ul, 0x800ul, 0x800ul, 0x800ul, 0x800ul, 0x800ul, 0xffffff0000000800ul, 0xfffffffffffffafful, 0xfffffffffffffbfful, 0xfffffffffffffcfful, 0xfffffffffffffdfful, 0xfffffffffffffefful, 0xfffffffffffffffful, 0xfffffe00000000fful, 0xfffffefffffff9fful, 0xfffffefffffffbfful, 0xfffffefffffffdfful, 0xfffffdfffffffffful, 0xfffffdfffffffdfful, 0xfffffb00000000fful, 0xfffff7fffffffffful, 0xfful, 0x90000000000ul, 0x40000000000ul, 0x30000000100ul, 0x20000000000ul, 0x10000000100ul, 0x10000000400ul, 0x10000000300ul, 0x10000000200ul, 0x10000000100ul, 0x0ul, 0x900ul, 0x900ul, 0x900ul, 0x900ul, 0x900ul, 0x900ul, 0xffffff0000000900ul, 0xfffffffffffffbfful, 0xfffffffffffffcfful, 0xfffffffffffffdfful, 0xfffffffffffffefful, 0xfffffffffffffffful, 0xfffffe00000000fful, 0xfffffefffffff8fful, 0xfffffefffffffafful, 0xfffffefffffffcfful, 0xfffffefffffffefful, 0xfffffd00000000fful, 0xfffffcfffffffefful, 0xfffffbfffffffefful, 0xfffff600000000fful, 0xfful, 0xa0000000000ul, 0x50000000000ul, 0x30000000000ul, 0x20000000100ul, 0x20000000200ul, 0x10000000000ul, 0x10000000400ul, 0x10000000300ul, 0x10000000200ul, 0x10000000100ul, 0x0ul, 0xa00ul, 0xa00ul, 0xa00ul, 0xa00ul, 0xa00ul, 0xffffff0000000a00ul, 0xfffffffffffffcfful, 0xfffffffffffffdfful, 0xfffffffffffffefful, 0xfffffffffffffffful, 0xfffffe00000000fful, 0xfffffefffffff7fful, 0xfffffefffffff9fful, 0xfffffefffffffbfful, 0xfffffefffffffdfful, 0xfffffdfffffffffful, 0xfffffdfffffffcfful, 0xfffffcfffffffffful, 0xfffffafffffffffful, 0xfffff5fffffffffful, 0xfful, 0xb0000000000ul, 0x50000000000ul, 0x30000000100ul, 0x20000000200ul, 0x20000000300ul, 0x10000000100ul, 0x10000000500ul, 0x10000000400ul, 0x10000000300ul, 0x10000000200ul, 0x10000000100ul, 0x0ul, 0xb00ul, 0xb00ul, 0xb00ul, 0xb00ul, 0xffffff0000000b00ul, 0xfffffffffffffdfful, 0xfffffffffffffefful, 0xfffffffffffffffful, 0xfffffe00000000fful, 0xfffffefffffff6fful, 0xfffffefffffff8fful, 0xfffffefffffffafful, 0xfffffefffffffcfful, 0xfffffefffffffefful, 0xfffffd00000000fful, 0xfffffdfffffffdfful, 0xfffffc00000000fful, 0xfffffa00000000fful, 0xfffff400000000fful, 0xfful, 0xc0000000000ul, 0x60000000000ul, 0x40000000000ul, 0x30000000000ul, 0x20000000000ul, 0x20000000200ul, 0x10000000000ul, 0x10000000500ul, 0x10000000400ul, 0x10000000300ul, 0x10000000200ul, 0x10000000100ul, 0x0ul, 0xc00ul, 0xc00ul, 0xc00ul, 0xffffff0000000c00ul, 0xfffffffffffffefful, 0xfffffffffffffffful, 0xfffffe00000000fful, 0xfffffefffffff5fful, 0xfffffefffffff7fful, 0xfffffefffffff9fful, 0xfffffefffffffbfful, 0xfffffefffffffdfful, 0xfffffdfffffffffful, 0xfffffdfffffffbfful, 0xfffffcfffffffefful, 0xfffffbfffffffdfful, 0xfffff9fffffffefful, 0xfffff3fffffffffful, 0xfful, 0xd0000000000ul, 0x60000000000ul, 0x40000000100ul, 0x30000000100ul, 0x20000000100ul, 0x20000000300ul, 0x10000000100ul, 0x10000000600ul, 0x10000000500ul, 0x10000000400ul, 0x10000000300ul, 0x10000000200ul, 0x10000000100ul, 0x0ul, 0xd00ul, 0xd00ul, 0xffffff0000000d00ul, 0xfffffffffffffffful, 0xfffffe00000000fful, 0xfffffefffffff4fful, 0xfffffefffffff6fful, 0xfffffefffffff8fful, 0xfffffefffffffafful, 0xfffffefffffffcfful, 0xfffffefffffffefful, 0xfffffd00000000fful, 0xfffffdfffffffcfful, 0xfffffcfffffffffful, 0xfffffbfffffffefful, 0xfffff9fffffffffful, 0xfffff200000000fful, 0xfful, 0xe0000000000ul, 0x70000000000ul, 0x40000000000ul, 0x30000000200ul, 0x20000000200ul, 0x20000000400ul, 0x20000000200ul, 0x10000000000ul, 0x10000000600ul, 0x10000000500ul, 0x10000000400ul, 0x10000000300ul, 0x10000000200ul, 0x10000000100ul, 0x0ul, 0xe00ul, 0xffffff0000000e00ul, 0xfffffe00000000fful, 0xfffffefffffff3fful, 0xfffffefffffff5fful, 0xfffffefffffff7fful, 0xfffffefffffff9fful, 0xfffffefffffffbfful, 0xfffffefffffffdfful, 0xfffffdfffffffffful, 0xfffffdfffffffafful, 0xfffffdfffffffdfful, 0xfffffc00000000fful, 0xfffffbfffffffffful, 0xfffff800000000fful, 0xfffff1fffffffffful, 0xfful, 0xf0000000000ul, 0x70000000000ul, 0x50000000100ul, 0x30000000000ul, 0x30000000300ul, 0x20000000000ul, 0x20000000300ul, 0x10000000100ul, 0x10000000700ul, 0x10000000600ul, 0x10000000500ul, 0x10000000400ul, 0x10000000300ul, 0x10000000200ul, 0x10000000100ul, 0x0ul, 0xfffffe0000000f00ul, 0xfffffefffffff2fful, 0xfffffefffffff4fful, 0xfffffefffffff6fful, 0xfffffefffffff8fful, 0xfffffefffffffafful, 0xfffffefffffffcfful, 0xfffffefffffffefful, 0xfffffd00000000fful, 0xfffffdfffffffbfful, 0xfffffcfffffffefful, 0xfffffcfffffffcfful, 0xfffffa00000000fful, 0xfffff8fffffffefful, 0xfffff000000000fful, 0xfful, 0x100000000000ul, 0x80000000000ul, 0x50000000000ul, 0x40000000100ul, 0x30000000000ul, 0x20000000100ul, 0x20000000400ul, 0x20000000200ul, 0x10000000000ul, 0x10000000700ul, 0x10000000600ul, 0x10000000500ul, 0x10000000400ul, 0x10000000300ul, 0x10000000200ul, 0x10000000100ul)

[init]
def private c2da_lin_init_static_d_polyse() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(2)) {
        let at = c2da_lin_static_d_polyse_seg[s * 2]
        for (k in range(c2da_lin_static_d_polyse_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_d_polyse[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_d_polyse_0 = fixed_array<uint8>(0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x21, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_d_polyse() {
    c2da_lin_setup()
    for (i in range(768)) {
        c2da_mem[204448 + i] = c2da_lin_extern_d_polyse_0[i]
    }
}
