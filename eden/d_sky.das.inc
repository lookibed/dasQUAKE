[export, sideeffects]
def D_DrawSkyScans8(var pspan : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    D_DrawSkyScans8_c2da_frame(pspan, c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def D_Sky_uv_To_st(var u_0 : int; var v_0 : int; var s : int; var t : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    D_Sky_uv_To_st_c2da_frame(u_0, v_0, s, t, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private D_DrawSkyScans8_c2da_frame(var pspan : int; c2da_fp : int) {
    var count : int
    var spancount : int
    var u : int
    var v : int
    var pdest : int
    var sstep : int
    var tstep : int
    var spancountminus1 : int
    sstep = 0
    tstep = 0
    while (true) {
        pdest = d_viewbuffer + int(screenwidth * int(uint(c2da_mem[pspan + 4]) | uint(c2da_mem[pspan + 5]) << 0x8 | uint(c2da_mem[pspan + 6]) << 0x10 | uint(c2da_mem[pspan + 7]) << 0x18)) + int(uint(c2da_mem[pspan]) | uint(c2da_mem[pspan + 1]) << 0x8 | uint(c2da_mem[pspan + 2]) << 0x10 | uint(c2da_mem[pspan + 3]) << 0x18)
        count = int(uint(c2da_mem[pspan + 8]) | uint(c2da_mem[pspan + 9]) << 0x8 | uint(c2da_mem[pspan + 10]) << 0x10 | uint(c2da_mem[pspan + 11]) << 0x18)
        u = int(uint(c2da_mem[pspan]) | uint(c2da_mem[pspan + 1]) << 0x8 | uint(c2da_mem[pspan + 2]) << 0x10 | uint(c2da_mem[pspan + 3]) << 0x18)
        v = int(uint(c2da_mem[pspan + 4]) | uint(c2da_mem[pspan + 5]) << 0x8 | uint(c2da_mem[pspan + 6]) << 0x10 | uint(c2da_mem[pspan + 7]) << 0x18)
        D_Sky_uv_To_st(u, v, c2da_fp, c2da_fp + 16)
        while (true) {
            if (count >= 1 << 5) {
                spancount = 1 << 5
            } else {
                spancount = count
            }
            count -= spancount
            if (count != 0) {
                u += spancount
                D_Sky_uv_To_st(u, v, c2da_fp + 32, c2da_fp + 48)
                sstep = int(uint(c2da_mem[c2da_fp + 32]) | uint(c2da_mem[c2da_fp + 33]) << 0x8 | uint(c2da_mem[c2da_fp + 34]) << 0x10 | uint(c2da_mem[c2da_fp + 35]) << 0x18) - int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) >> 5
                tstep = int(uint(c2da_mem[c2da_fp + 48]) | uint(c2da_mem[c2da_fp + 49]) << 0x8 | uint(c2da_mem[c2da_fp + 50]) << 0x10 | uint(c2da_mem[c2da_fp + 51]) << 0x18) - int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18) >> 5
            } else {
                spancountminus1 = int(float(spancount - 1))
                if (spancountminus1 > 0) {
                    u += spancountminus1
                    D_Sky_uv_To_st(u, v, c2da_fp + 32, c2da_fp + 48)
                    sstep = (int(uint(c2da_mem[c2da_fp + 32]) | uint(c2da_mem[c2da_fp + 33]) << 0x8 | uint(c2da_mem[c2da_fp + 34]) << 0x10 | uint(c2da_mem[c2da_fp + 35]) << 0x18) - int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18)) / spancountminus1
                    tstep = (int(uint(c2da_mem[c2da_fp + 48]) | uint(c2da_mem[c2da_fp + 49]) << 0x8 | uint(c2da_mem[c2da_fp + 50]) << 0x10 | uint(c2da_mem[c2da_fp + 51]) << 0x18) - int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18)) / spancountminus1
                }
            }
            while (true) {
                let c2da_fresh0 : int = pdest
                pdest++
                let c2da_fresh1 : int = r_skysource + (((int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18) & 8323072) >> 8) + ((int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) & 8323072) >> 16))
                let c2da_fresh2 : uint8 = c2da_mem[c2da_fresh1]
                c2da_mem[c2da_fresh0] = c2da_fresh2
                let c2da_fresh3 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) + sstep
                let c2da_fresh4 : uint = uint(c2da_fresh3)
                c2da_mem[c2da_fp] = uint8(c2da_fresh4)
                c2da_mem[c2da_fp + 1] = uint8(c2da_fresh4 >> 0x8)
                c2da_mem[c2da_fp + 2] = uint8(c2da_fresh4 >> 0x10)
                c2da_mem[c2da_fp + 3] = uint8(c2da_fresh4 >> 0x18)
                let c2da_fresh5 : int = int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18) + tstep
                let c2da_fresh6 : uint = uint(c2da_fresh5)
                c2da_mem[c2da_fp + 16] = uint8(c2da_fresh6)
                c2da_mem[c2da_fp + 17] = uint8(c2da_fresh6 >> 0x8)
                c2da_mem[c2da_fp + 18] = uint8(c2da_fresh6 >> 0x10)
                c2da_mem[c2da_fp + 19] = uint8(c2da_fresh6 >> 0x18)
                spancount--
                if (spancount <= 0) {
                    break
                }
            }
            let c2da_fresh7 : int = int(uint(c2da_mem[c2da_fp + 32]) | uint(c2da_mem[c2da_fp + 33]) << 0x8 | uint(c2da_mem[c2da_fp + 34]) << 0x10 | uint(c2da_mem[c2da_fp + 35]) << 0x18)
            let c2da_fresh8 : uint = uint(c2da_fresh7)
            c2da_mem[c2da_fp] = uint8(c2da_fresh8)
            c2da_mem[c2da_fp + 1] = uint8(c2da_fresh8 >> 0x8)
            c2da_mem[c2da_fp + 2] = uint8(c2da_fresh8 >> 0x10)
            c2da_mem[c2da_fp + 3] = uint8(c2da_fresh8 >> 0x18)
            let c2da_fresh9 : int = int(uint(c2da_mem[c2da_fp + 48]) | uint(c2da_mem[c2da_fp + 49]) << 0x8 | uint(c2da_mem[c2da_fp + 50]) << 0x10 | uint(c2da_mem[c2da_fp + 51]) << 0x18)
            let c2da_fresh10 : uint = uint(c2da_fresh9)
            c2da_mem[c2da_fp + 16] = uint8(c2da_fresh10)
            c2da_mem[c2da_fp + 17] = uint8(c2da_fresh10 >> 0x8)
            c2da_mem[c2da_fp + 18] = uint8(c2da_fresh10 >> 0x10)
            c2da_mem[c2da_fp + 19] = uint8(c2da_fresh10 >> 0x18)
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
[sideeffects]
def private D_Sky_uv_To_st_c2da_frame(var u_0 : int; var v_0 : int; var s : int; var t : int; c2da_fp : int) {
    var wu : float
    var wv : float
    var temp : float
    if (int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18) >= int(uint(c2da_mem[5212]) | uint(c2da_mem[5213]) << 0x8 | uint(c2da_mem[5214]) << 0x10 | uint(c2da_mem[5215]) << 0x18)) {
        temp = float(int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18))
    } else {
        temp = float(int(uint(c2da_mem[5212]) | uint(c2da_mem[5213]) << 0x8 | uint(c2da_mem[5214]) << 0x10 | uint(c2da_mem[5215]) << 0x18))
    }
    wu = float(8192.0lf * double(float(u_0 - (int(vid.width) >> 1))) / double(temp))
    wv = float(8192.0lf * double(float((int(vid.height) >> 1) - v_0)) / double(temp))
    let c2da_fresh11 : float = 4096.0 * uint_bits_to_float(uint(c2da_mem[244128 + 0 * 4]) | uint(c2da_mem[244128 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 0 * 4 + 3]) << 0x18) + wu * uint_bits_to_float(uint(c2da_mem[244144 + 0 * 4]) | uint(c2da_mem[244144 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 0 * 4 + 3]) << 0x18) + wv * uint_bits_to_float(uint(c2da_mem[244160 + 0 * 4]) | uint(c2da_mem[244160 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh12 : uint = float_bits_to_uint(c2da_fresh11)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh12)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh12 >> 0x18)
    let c2da_fresh13 : float = 4096.0 * uint_bits_to_float(uint(c2da_mem[244128 + 1 * 4]) | uint(c2da_mem[244128 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 1 * 4 + 3]) << 0x18) + wu * uint_bits_to_float(uint(c2da_mem[244144 + 1 * 4]) | uint(c2da_mem[244144 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 1 * 4 + 3]) << 0x18) + wv * uint_bits_to_float(uint(c2da_mem[244160 + 1 * 4]) | uint(c2da_mem[244160 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh14 : uint = float_bits_to_uint(c2da_fresh13)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh14)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh14 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh14 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh14 >> 0x18)
    let c2da_fresh15 : float = 4096.0 * uint_bits_to_float(uint(c2da_mem[244128 + 2 * 4]) | uint(c2da_mem[244128 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 2 * 4 + 3]) << 0x18) + wu * uint_bits_to_float(uint(c2da_mem[244144 + 2 * 4]) | uint(c2da_mem[244144 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + 2 * 4 + 3]) << 0x18) + wv * uint_bits_to_float(uint(c2da_mem[244160 + 2 * 4]) | uint(c2da_mem[244160 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh16 : uint = float_bits_to_uint(c2da_fresh15)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh16)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh16 >> 0x18)
    let c2da_fresh17 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) * 3.0
    let c2da_fresh18 : uint = float_bits_to_uint(c2da_fresh17)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh18)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh18 >> 0x18)
    VectorNormalize(c2da_fp)
    temp = skytime * skyspeed
    let c2da_fresh19 : int = int((temp + float(6 * ((1 << 7) / 2 - 1)) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)) * 65536.0)
    let c2da_fresh20 : uint = uint(c2da_fresh19)
    c2da_mem[s] = uint8(c2da_fresh20)
    c2da_mem[s + 1] = uint8(c2da_fresh20 >> 0x8)
    c2da_mem[s + 2] = uint8(c2da_fresh20 >> 0x10)
    c2da_mem[s + 3] = uint8(c2da_fresh20 >> 0x18)
    let c2da_fresh21 : int = int((temp + float(6 * ((1 << 7) / 2 - 1)) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)) * 65536.0)
    let c2da_fresh22 : uint = uint(c2da_fresh21)
    c2da_mem[t] = uint8(c2da_fresh22)
    c2da_mem[t + 1] = uint8(c2da_fresh22 >> 0x8)
    c2da_mem[t + 2] = uint8(c2da_fresh22 >> 0x10)
    c2da_mem[t + 3] = uint8(c2da_fresh22 >> 0x18)
    return
}
