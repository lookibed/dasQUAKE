var private R_MakeSky__xlast : int = -1

var private R_MakeSky__ylast : int = -1

[export, sideeffects]
def R_InitSky(var mt : int) {
    var i : int
    var j : int
    var src : int = mt + int(uint(c2da_mem[mt + 56 + 0 * 4]) | uint(c2da_mem[mt + 56 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[mt + 56 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[mt + 56 + 0 * 4 + 3]) << 0x18)
    i = 0
    while (i < 128) {
        j = 0
        while (j < 128) {
            let c2da_fresh0 : uint8 = c2da_mem[src + (i * 256 + j + 128)]
            c2da_mem[393184 + (i * 256 + j + 128)] = c2da_fresh0
            j++
        }
        i++
    }
    i = 0
    for (c2da_i in range(i, 128)) {
        j = 0
        while (j < 131) {
            let c2da_fresh1 : int = src + (c2da_i * 256 + (j & 127))
            if (c2da_mem[c2da_fresh1] != 0x0) {
                let c2da_fresh2 : int = src + (c2da_i * 256 + (j & 127))
                let c2da_fresh3 : uint8 = c2da_mem[c2da_fresh2]
                c2da_mem[442720 + (c2da_i * 131 + j)] = c2da_fresh3
                let c2da_fresh4 : uint8 = 0u8
                c2da_mem[425952 + (c2da_i * 131 + j)] = c2da_fresh4
            } else {
                let c2da_fresh5 : uint8 = 0u8
                c2da_mem[442720 + (c2da_i * 131 + j)] = c2da_fresh5
                let c2da_fresh6 : uint8 = 0xffu8
                c2da_mem[425952 + (c2da_i * 131 + j)] = c2da_fresh6
            }
            j++
        }
    }
    r_skysource = 393184
    return
}
var r_skysource : int = default<int>

var r_skydirect : int = default<int>

var skyspeed : float = default<float>

var skyspeed2 : float = default<float>

var skytime : float = default<float>

var r_skymade : int = default<int>

[export, sideeffects]
def R_MakeSky() {
    var ofs : int
    var baseofs : int
    var xshift : int
    var yshift : int
    var pnewsky : int
    xshift = int(skytime * skyspeed)
    yshift = int(skytime * skyspeed)
    if (xshift == R_MakeSky__xlast && yshift == R_MakeSky__ylast) {
        return
    }
    R_MakeSky__xlast = xshift
    R_MakeSky__ylast = yshift
    pnewsky = 393184 + 0
    for (y in range(0, 1 << 7)) {
        baseofs = (y + yshift & (1 << 7) - 1) * 131
        for (x in range(0, 1 << 7)) {
            ofs = baseofs + (x + xshift & (1 << 7) - 1)
            let c2da_fresh7 : uint8 = uint8(int(c2da_mem[pnewsky + 128]) & int(c2da_mem[425952 + ofs]) | int(c2da_mem[442720 + ofs]))
            c2da_mem[pnewsky] = c2da_fresh7
            pnewsky++
        }
        pnewsky += int(128ul / 4ul) * 4
    }
    r_skymade = 1
    return
}
[export, sideeffects]
def R_SetSkyFrame() {
    var g : int
    var temp : float
    skyspeed = float(iskyspeed)
    skyspeed2 = float(iskyspeed2)
    g = GreatestCommonDivisor(iskyspeed, iskyspeed2)
    temp = float((1 << 7) * (iskyspeed / g) * (iskyspeed2 / g))
    skytime = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - double(float(int(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) / double(temp))) * temp))
    r_skymade = 0
    return
}
var iskyspeed2 : int = 2

var iskyspeed : int = 8

[export, sideeffects]
def R_GenSkyTile(var pdest : int) {
    var ofs_0 : int
    var baseofs_0 : int
    var xshift_0 : int
    var yshift_0 : int
    var pnewsky_0 : int
    var pd : int
    xshift_0 = int(skytime * skyspeed)
    yshift_0 = int(skytime * skyspeed)
    pnewsky_0 = 393184 + 0
    pd = pdest
    for (y_0 in range(0, 1 << 7)) {
        baseofs_0 = (y_0 + yshift_0 & (1 << 7) - 1) * 131
        for (x_0 in range(0, 1 << 7)) {
            ofs_0 = baseofs_0 + (x_0 + xshift_0 & (1 << 7) - 1)
            let c2da_fresh8 : uint8 = uint8(int(c2da_mem[pnewsky_0 + 128]) & int(c2da_mem[425952 + ofs_0]) | int(c2da_mem[442720 + ofs_0]))
            c2da_mem[pd] = c2da_fresh8
            pnewsky_0++
            pd++
        }
        pnewsky_0 += int(128ul / 4ul) * 4
    }
    return
}
