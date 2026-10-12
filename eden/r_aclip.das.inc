[export, sideeffects]
def R_AliasClipTriangle(var ptri : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_AliasClipTriangle_c2da_frame(ptri, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_Alias_clip_top(var pfv0 : int; var pfv1 : int; var out : int) {
    var scale : float
    var i_0 : int
    let c2da_fresh24 : int = int(uint(c2da_mem[pfv0 + 1 * 4]) | uint(c2da_mem[pfv0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh25 : int = int(uint(c2da_mem[pfv1 + 1 * 4]) | uint(c2da_mem[pfv1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1 + 1 * 4 + 3]) << 0x18)
    if (c2da_fresh24 >= c2da_fresh25) {
        scale = float(int(uint(c2da_mem[5228]) | uint(c2da_mem[5229]) << 0x8 | uint(c2da_mem[5230]) << 0x10 | uint(c2da_mem[5231]) << 0x18) - c2da_fresh24) / float(c2da_fresh25 - c2da_fresh24)
        i_0 = 0
        for (c2da_i_0 in range(i_0, 6)) {
            let c2da_fresh26 : int = int(uint(c2da_mem[pfv0 + c2da_i_0 * 4]) | uint(c2da_mem[pfv0 + c2da_i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0 + c2da_i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0 + c2da_i_0 * 4 + 3]) << 0x18)
            let c2da_fresh20 : int = int(double(float(c2da_fresh26) + float(int(uint(c2da_mem[pfv1 + c2da_i_0 * 4]) | uint(c2da_mem[pfv1 + c2da_i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1 + c2da_i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1 + c2da_i_0 * 4 + 3]) << 0x18) - c2da_fresh26) * scale) + 0.5lf)
            let c2da_fresh21 : uint = uint(c2da_fresh20)
            c2da_mem[out + c2da_i_0 * 4] = uint8(c2da_fresh21)
            c2da_mem[out + c2da_i_0 * 4 + 1] = uint8(c2da_fresh21 >> 0x8)
            c2da_mem[out + c2da_i_0 * 4 + 2] = uint8(c2da_fresh21 >> 0x10)
            c2da_mem[out + c2da_i_0 * 4 + 3] = uint8(c2da_fresh21 >> 0x18)
        }
    } else {
        scale = float(int(uint(c2da_mem[5228]) | uint(c2da_mem[5229]) << 0x8 | uint(c2da_mem[5230]) << 0x10 | uint(c2da_mem[5231]) << 0x18) - c2da_fresh25) / float(c2da_fresh24 - c2da_fresh25)
        i_0 = 0
        for (c2da_i_0_0 in range(i_0, 6)) {
            let c2da_fresh27 : int = int(uint(c2da_mem[pfv1 + c2da_i_0_0 * 4]) | uint(c2da_mem[pfv1 + c2da_i_0_0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1 + c2da_i_0_0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1 + c2da_i_0_0 * 4 + 3]) << 0x18)
            let c2da_fresh22 : int = int(double(float(c2da_fresh27) + float(int(uint(c2da_mem[pfv0 + c2da_i_0_0 * 4]) | uint(c2da_mem[pfv0 + c2da_i_0_0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0 + c2da_i_0_0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0 + c2da_i_0_0 * 4 + 3]) << 0x18) - c2da_fresh27) * scale) + 0.5lf)
            let c2da_fresh23 : uint = uint(c2da_fresh22)
            c2da_mem[out + c2da_i_0_0 * 4] = uint8(c2da_fresh23)
            c2da_mem[out + c2da_i_0_0 * 4 + 1] = uint8(c2da_fresh23 >> 0x8)
            c2da_mem[out + c2da_i_0_0 * 4 + 2] = uint8(c2da_fresh23 >> 0x10)
            c2da_mem[out + c2da_i_0_0 * 4 + 3] = uint8(c2da_fresh23 >> 0x18)
        }
    }
    return
}
[export, sideeffects]
def R_AliasClip(var in_0 : int; var out_0 : int; var flag : int; var count : int; var clip : int) : int {
    var i_1 : int
    var j : int
    var k_0 : int
    var flags : int
    var oldflags : int
    j = count - 1
    k_0 = 0
    i_1 = 0
    while (i_1 < count) {
        oldflags = int(uint(c2da_mem[in_0 + j * 32 + 24]) | uint(c2da_mem[in_0 + j * 32 + 25]) << 0x8 | uint(c2da_mem[in_0 + j * 32 + 26]) << 0x10 | uint(c2da_mem[in_0 + j * 32 + 27]) << 0x18) & flag
        flags = int(uint(c2da_mem[in_0 + i_1 * 32 + 24]) | uint(c2da_mem[in_0 + i_1 * 32 + 25]) << 0x8 | uint(c2da_mem[in_0 + i_1 * 32 + 26]) << 0x10 | uint(c2da_mem[in_0 + i_1 * 32 + 27]) << 0x18) & flag
        if (flags != 0 && oldflags != 0) {
            j = i_1
            i_1++
            continue
        }
        if ((oldflags ^ flags) != 0) {
            invoke(c2da_fn_table12[clip], in_0 + j * 32, in_0 + i_1 * 32, out_0 + k_0 * 32)
            let c2da_fresh28 : int = 0
            let c2da_fresh29 : uint = uint(c2da_fresh28)
            c2da_mem[out_0 + k_0 * 32 + 24] = uint8(c2da_fresh29)
            c2da_mem[out_0 + k_0 * 32 + 25] = uint8(c2da_fresh29 >> 0x8)
            c2da_mem[out_0 + k_0 * 32 + 26] = uint8(c2da_fresh29 >> 0x10)
            c2da_mem[out_0 + k_0 * 32 + 27] = uint8(c2da_fresh29 >> 0x18)
            if (int(uint(c2da_mem[out_0 + k_0 * 32 + 0 * 4]) | uint(c2da_mem[out_0 + k_0 * 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[out_0 + k_0 * 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[out_0 + k_0 * 32 + 0 * 4 + 3]) << 0x18) < int(uint(c2da_mem[5224]) | uint(c2da_mem[5225]) << 0x8 | uint(c2da_mem[5226]) << 0x10 | uint(c2da_mem[5227]) << 0x18)) {
                let c2da_fresh30 : int = int(uint(c2da_mem[out_0 + k_0 * 32 + 24]) | uint(c2da_mem[out_0 + k_0 * 32 + 25]) << 0x8 | uint(c2da_mem[out_0 + k_0 * 32 + 26]) << 0x10 | uint(c2da_mem[out_0 + k_0 * 32 + 27]) << 0x18) | 1
                let c2da_fresh31 : uint = uint(c2da_fresh30)
                c2da_mem[out_0 + k_0 * 32 + 24] = uint8(c2da_fresh31)
                c2da_mem[out_0 + k_0 * 32 + 25] = uint8(c2da_fresh31 >> 0x8)
                c2da_mem[out_0 + k_0 * 32 + 26] = uint8(c2da_fresh31 >> 0x10)
                c2da_mem[out_0 + k_0 * 32 + 27] = uint8(c2da_fresh31 >> 0x18)
            }
            if (int(uint(c2da_mem[out_0 + k_0 * 32 + 1 * 4]) | uint(c2da_mem[out_0 + k_0 * 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[out_0 + k_0 * 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[out_0 + k_0 * 32 + 1 * 4 + 3]) << 0x18) < int(uint(c2da_mem[5228]) | uint(c2da_mem[5229]) << 0x8 | uint(c2da_mem[5230]) << 0x10 | uint(c2da_mem[5231]) << 0x18)) {
                let c2da_fresh32 : int = int(uint(c2da_mem[out_0 + k_0 * 32 + 24]) | uint(c2da_mem[out_0 + k_0 * 32 + 25]) << 0x8 | uint(c2da_mem[out_0 + k_0 * 32 + 26]) << 0x10 | uint(c2da_mem[out_0 + k_0 * 32 + 27]) << 0x18) | 2
                let c2da_fresh33 : uint = uint(c2da_fresh32)
                c2da_mem[out_0 + k_0 * 32 + 24] = uint8(c2da_fresh33)
                c2da_mem[out_0 + k_0 * 32 + 25] = uint8(c2da_fresh33 >> 0x8)
                c2da_mem[out_0 + k_0 * 32 + 26] = uint8(c2da_fresh33 >> 0x10)
                c2da_mem[out_0 + k_0 * 32 + 27] = uint8(c2da_fresh33 >> 0x18)
            }
            if (int(uint(c2da_mem[out_0 + k_0 * 32 + 0 * 4]) | uint(c2da_mem[out_0 + k_0 * 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[out_0 + k_0 * 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[out_0 + k_0 * 32 + 0 * 4 + 3]) << 0x18) > int(uint(c2da_mem[5256]) | uint(c2da_mem[5257]) << 0x8 | uint(c2da_mem[5258]) << 0x10 | uint(c2da_mem[5259]) << 0x18)) {
                let c2da_fresh34 : int = int(uint(c2da_mem[out_0 + k_0 * 32 + 24]) | uint(c2da_mem[out_0 + k_0 * 32 + 25]) << 0x8 | uint(c2da_mem[out_0 + k_0 * 32 + 26]) << 0x10 | uint(c2da_mem[out_0 + k_0 * 32 + 27]) << 0x18) | 4
                let c2da_fresh35 : uint = uint(c2da_fresh34)
                c2da_mem[out_0 + k_0 * 32 + 24] = uint8(c2da_fresh35)
                c2da_mem[out_0 + k_0 * 32 + 25] = uint8(c2da_fresh35 >> 0x8)
                c2da_mem[out_0 + k_0 * 32 + 26] = uint8(c2da_fresh35 >> 0x10)
                c2da_mem[out_0 + k_0 * 32 + 27] = uint8(c2da_fresh35 >> 0x18)
            }
            if (int(uint(c2da_mem[out_0 + k_0 * 32 + 1 * 4]) | uint(c2da_mem[out_0 + k_0 * 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[out_0 + k_0 * 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[out_0 + k_0 * 32 + 1 * 4 + 3]) << 0x18) > int(uint(c2da_mem[5260]) | uint(c2da_mem[5261]) << 0x8 | uint(c2da_mem[5262]) << 0x10 | uint(c2da_mem[5263]) << 0x18)) {
                let c2da_fresh36 : int = int(uint(c2da_mem[out_0 + k_0 * 32 + 24]) | uint(c2da_mem[out_0 + k_0 * 32 + 25]) << 0x8 | uint(c2da_mem[out_0 + k_0 * 32 + 26]) << 0x10 | uint(c2da_mem[out_0 + k_0 * 32 + 27]) << 0x18) | 8
                let c2da_fresh37 : uint = uint(c2da_fresh36)
                c2da_mem[out_0 + k_0 * 32 + 24] = uint8(c2da_fresh37)
                c2da_mem[out_0 + k_0 * 32 + 25] = uint8(c2da_fresh37 >> 0x8)
                c2da_mem[out_0 + k_0 * 32 + 26] = uint8(c2da_fresh37 >> 0x10)
                c2da_mem[out_0 + k_0 * 32 + 27] = uint8(c2da_fresh37 >> 0x18)
            }
            k_0++
        }
        if (flags == 0) {
            c2da_lin_memmove(out_0 + k_0 * 32, in_0 + i_1 * 32, 32ul)
            k_0++
        }
        j = i_1
        i_1++
    }
    return k_0
}
[export, sideeffects]
def R_Alias_clip_bottom(var pfv0_0 : int; var pfv1_0 : int; var out_1 : int) {
    var scale_0 : float
    var i_2 : int
    let c2da_fresh42 : int = int(uint(c2da_mem[pfv0_0 + 1 * 4]) | uint(c2da_mem[pfv0_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_0 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh43 : int = int(uint(c2da_mem[pfv1_0 + 1 * 4]) | uint(c2da_mem[pfv1_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_0 + 1 * 4 + 3]) << 0x18)
    if (c2da_fresh42 >= c2da_fresh43) {
        scale_0 = float(int(uint(c2da_mem[5260]) | uint(c2da_mem[5261]) << 0x8 | uint(c2da_mem[5262]) << 0x10 | uint(c2da_mem[5263]) << 0x18) - c2da_fresh42) / float(c2da_fresh43 - c2da_fresh42)
        i_2 = 0
        for (c2da_i_2 in range(i_2, 6)) {
            let c2da_fresh44 : int = int(uint(c2da_mem[pfv0_0 + c2da_i_2 * 4]) | uint(c2da_mem[pfv0_0 + c2da_i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_0 + c2da_i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_0 + c2da_i_2 * 4 + 3]) << 0x18)
            let c2da_fresh38 : int = int(double(float(c2da_fresh44) + float(int(uint(c2da_mem[pfv1_0 + c2da_i_2 * 4]) | uint(c2da_mem[pfv1_0 + c2da_i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_0 + c2da_i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_0 + c2da_i_2 * 4 + 3]) << 0x18) - c2da_fresh44) * scale_0) + 0.5lf)
            let c2da_fresh39 : uint = uint(c2da_fresh38)
            c2da_mem[out_1 + c2da_i_2 * 4] = uint8(c2da_fresh39)
            c2da_mem[out_1 + c2da_i_2 * 4 + 1] = uint8(c2da_fresh39 >> 0x8)
            c2da_mem[out_1 + c2da_i_2 * 4 + 2] = uint8(c2da_fresh39 >> 0x10)
            c2da_mem[out_1 + c2da_i_2 * 4 + 3] = uint8(c2da_fresh39 >> 0x18)
        }
    } else {
        scale_0 = float(int(uint(c2da_mem[5260]) | uint(c2da_mem[5261]) << 0x8 | uint(c2da_mem[5262]) << 0x10 | uint(c2da_mem[5263]) << 0x18) - c2da_fresh43) / float(c2da_fresh42 - c2da_fresh43)
        i_2 = 0
        for (c2da_i_2_0 in range(i_2, 6)) {
            let c2da_fresh45 : int = int(uint(c2da_mem[pfv1_0 + c2da_i_2_0 * 4]) | uint(c2da_mem[pfv1_0 + c2da_i_2_0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_0 + c2da_i_2_0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_0 + c2da_i_2_0 * 4 + 3]) << 0x18)
            let c2da_fresh40 : int = int(double(float(c2da_fresh45) + float(int(uint(c2da_mem[pfv0_0 + c2da_i_2_0 * 4]) | uint(c2da_mem[pfv0_0 + c2da_i_2_0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_0 + c2da_i_2_0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_0 + c2da_i_2_0 * 4 + 3]) << 0x18) - c2da_fresh45) * scale_0) + 0.5lf)
            let c2da_fresh41 : uint = uint(c2da_fresh40)
            c2da_mem[out_1 + c2da_i_2_0 * 4] = uint8(c2da_fresh41)
            c2da_mem[out_1 + c2da_i_2_0 * 4 + 1] = uint8(c2da_fresh41 >> 0x8)
            c2da_mem[out_1 + c2da_i_2_0 * 4 + 2] = uint8(c2da_fresh41 >> 0x10)
            c2da_mem[out_1 + c2da_i_2_0 * 4 + 3] = uint8(c2da_fresh41 >> 0x18)
        }
    }
    return
}
[export, sideeffects]
def R_Alias_clip_right(var pfv0_1 : int; var pfv1_1 : int; var out_2 : int) {
    var scale_1 : float
    var i_3 : int
    if (int(uint(c2da_mem[pfv0_1 + 1 * 4]) | uint(c2da_mem[pfv0_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_1 + 1 * 4 + 3]) << 0x18) >= int(uint(c2da_mem[pfv1_1 + 1 * 4]) | uint(c2da_mem[pfv1_1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_1 + 1 * 4 + 3]) << 0x18)) {
        let c2da_fresh50 : int = int(uint(c2da_mem[pfv0_1 + 0 * 4]) | uint(c2da_mem[pfv0_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_1 + 0 * 4 + 3]) << 0x18)
        scale_1 = float(int(uint(c2da_mem[5256]) | uint(c2da_mem[5257]) << 0x8 | uint(c2da_mem[5258]) << 0x10 | uint(c2da_mem[5259]) << 0x18) - c2da_fresh50) / float(int(uint(c2da_mem[pfv1_1 + 0 * 4]) | uint(c2da_mem[pfv1_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_1 + 0 * 4 + 3]) << 0x18) - c2da_fresh50)
        i_3 = 0
        for (c2da_i_3 in range(i_3, 6)) {
            let c2da_fresh51 : int = int(uint(c2da_mem[pfv0_1 + c2da_i_3 * 4]) | uint(c2da_mem[pfv0_1 + c2da_i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_1 + c2da_i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_1 + c2da_i_3 * 4 + 3]) << 0x18)
            let c2da_fresh46 : int = int(double(float(c2da_fresh51) + float(int(uint(c2da_mem[pfv1_1 + c2da_i_3 * 4]) | uint(c2da_mem[pfv1_1 + c2da_i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_1 + c2da_i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_1 + c2da_i_3 * 4 + 3]) << 0x18) - c2da_fresh51) * scale_1) + 0.5lf)
            let c2da_fresh47 : uint = uint(c2da_fresh46)
            c2da_mem[out_2 + c2da_i_3 * 4] = uint8(c2da_fresh47)
            c2da_mem[out_2 + c2da_i_3 * 4 + 1] = uint8(c2da_fresh47 >> 0x8)
            c2da_mem[out_2 + c2da_i_3 * 4 + 2] = uint8(c2da_fresh47 >> 0x10)
            c2da_mem[out_2 + c2da_i_3 * 4 + 3] = uint8(c2da_fresh47 >> 0x18)
        }
    } else {
        let c2da_fresh52 : int = int(uint(c2da_mem[pfv1_1 + 0 * 4]) | uint(c2da_mem[pfv1_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_1 + 0 * 4 + 3]) << 0x18)
        scale_1 = float(int(uint(c2da_mem[5256]) | uint(c2da_mem[5257]) << 0x8 | uint(c2da_mem[5258]) << 0x10 | uint(c2da_mem[5259]) << 0x18) - c2da_fresh52) / float(int(uint(c2da_mem[pfv0_1 + 0 * 4]) | uint(c2da_mem[pfv0_1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_1 + 0 * 4 + 3]) << 0x18) - c2da_fresh52)
        i_3 = 0
        for (c2da_i_3_0 in range(i_3, 6)) {
            let c2da_fresh53 : int = int(uint(c2da_mem[pfv1_1 + c2da_i_3_0 * 4]) | uint(c2da_mem[pfv1_1 + c2da_i_3_0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_1 + c2da_i_3_0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_1 + c2da_i_3_0 * 4 + 3]) << 0x18)
            let c2da_fresh48 : int = int(double(float(c2da_fresh53) + float(int(uint(c2da_mem[pfv0_1 + c2da_i_3_0 * 4]) | uint(c2da_mem[pfv0_1 + c2da_i_3_0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_1 + c2da_i_3_0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_1 + c2da_i_3_0 * 4 + 3]) << 0x18) - c2da_fresh53) * scale_1) + 0.5lf)
            let c2da_fresh49 : uint = uint(c2da_fresh48)
            c2da_mem[out_2 + c2da_i_3_0 * 4] = uint8(c2da_fresh49)
            c2da_mem[out_2 + c2da_i_3_0 * 4 + 1] = uint8(c2da_fresh49 >> 0x8)
            c2da_mem[out_2 + c2da_i_3_0 * 4 + 2] = uint8(c2da_fresh49 >> 0x10)
            c2da_mem[out_2 + c2da_i_3_0 * 4 + 3] = uint8(c2da_fresh49 >> 0x18)
        }
    }
    return
}
[export, sideeffects]
def R_Alias_clip_left(var pfv0_2 : int; var pfv1_2 : int; var out_3 : int) {
    var scale_2 : float
    var i_4 : int
    if (int(uint(c2da_mem[pfv0_2 + 1 * 4]) | uint(c2da_mem[pfv0_2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_2 + 1 * 4 + 3]) << 0x18) >= int(uint(c2da_mem[pfv1_2 + 1 * 4]) | uint(c2da_mem[pfv1_2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_2 + 1 * 4 + 3]) << 0x18)) {
        let c2da_fresh58 : int = int(uint(c2da_mem[pfv0_2 + 0 * 4]) | uint(c2da_mem[pfv0_2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_2 + 0 * 4 + 3]) << 0x18)
        scale_2 = float(int(uint(c2da_mem[5224]) | uint(c2da_mem[5225]) << 0x8 | uint(c2da_mem[5226]) << 0x10 | uint(c2da_mem[5227]) << 0x18) - c2da_fresh58) / float(int(uint(c2da_mem[pfv1_2 + 0 * 4]) | uint(c2da_mem[pfv1_2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_2 + 0 * 4 + 3]) << 0x18) - c2da_fresh58)
        i_4 = 0
        for (c2da_i_4 in range(i_4, 6)) {
            let c2da_fresh59 : int = int(uint(c2da_mem[pfv0_2 + c2da_i_4 * 4]) | uint(c2da_mem[pfv0_2 + c2da_i_4 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_2 + c2da_i_4 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_2 + c2da_i_4 * 4 + 3]) << 0x18)
            let c2da_fresh54 : int = int(double(float(c2da_fresh59) + float(int(uint(c2da_mem[pfv1_2 + c2da_i_4 * 4]) | uint(c2da_mem[pfv1_2 + c2da_i_4 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_2 + c2da_i_4 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_2 + c2da_i_4 * 4 + 3]) << 0x18) - c2da_fresh59) * scale_2) + 0.5lf)
            let c2da_fresh55 : uint = uint(c2da_fresh54)
            c2da_mem[out_3 + c2da_i_4 * 4] = uint8(c2da_fresh55)
            c2da_mem[out_3 + c2da_i_4 * 4 + 1] = uint8(c2da_fresh55 >> 0x8)
            c2da_mem[out_3 + c2da_i_4 * 4 + 2] = uint8(c2da_fresh55 >> 0x10)
            c2da_mem[out_3 + c2da_i_4 * 4 + 3] = uint8(c2da_fresh55 >> 0x18)
        }
    } else {
        let c2da_fresh60 : int = int(uint(c2da_mem[pfv1_2 + 0 * 4]) | uint(c2da_mem[pfv1_2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_2 + 0 * 4 + 3]) << 0x18)
        scale_2 = float(int(uint(c2da_mem[5224]) | uint(c2da_mem[5225]) << 0x8 | uint(c2da_mem[5226]) << 0x10 | uint(c2da_mem[5227]) << 0x18) - c2da_fresh60) / float(int(uint(c2da_mem[pfv0_2 + 0 * 4]) | uint(c2da_mem[pfv0_2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_2 + 0 * 4 + 3]) << 0x18) - c2da_fresh60)
        i_4 = 0
        for (c2da_i_4_0 in range(i_4, 6)) {
            let c2da_fresh61 : int = int(uint(c2da_mem[pfv1_2 + c2da_i_4_0 * 4]) | uint(c2da_mem[pfv1_2 + c2da_i_4_0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_2 + c2da_i_4_0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_2 + c2da_i_4_0 * 4 + 3]) << 0x18)
            let c2da_fresh56 : int = int(double(float(c2da_fresh61) + float(int(uint(c2da_mem[pfv0_2 + c2da_i_4_0 * 4]) | uint(c2da_mem[pfv0_2 + c2da_i_4_0 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_2 + c2da_i_4_0 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_2 + c2da_i_4_0 * 4 + 3]) << 0x18) - c2da_fresh61) * scale_2) + 0.5lf)
            let c2da_fresh57 : uint = uint(c2da_fresh56)
            c2da_mem[out_3 + c2da_i_4_0 * 4] = uint8(c2da_fresh57)
            c2da_mem[out_3 + c2da_i_4_0 * 4 + 1] = uint8(c2da_fresh57 >> 0x8)
            c2da_mem[out_3 + c2da_i_4_0 * 4 + 2] = uint8(c2da_fresh57 >> 0x10)
            c2da_mem[out_3 + c2da_i_4_0 * 4 + 3] = uint8(c2da_fresh57 >> 0x18)
        }
    }
    return
}
[export, sideeffects]
def R_Alias_clip_z(var pfv0_3 : int; var pfv1_3 : int; var out_4 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_Alias_clip_z_c2da_frame(pfv0_3, pfv1_3, out_4, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private R_AliasClipTriangle_c2da_frame(var ptri : int; c2da_fp : int) {
    var i : int
    var k : int
    var pingpong : int
    var clipflags : uint
    let c2da_fresh19 : int = int(uint(c2da_mem[ptri]) | uint(c2da_mem[ptri + 1]) << 0x8 | uint(c2da_mem[ptri + 2]) << 0x10 | uint(c2da_mem[ptri + 3]) << 0x18)
    if (c2da_fresh19 != 0) {
        c2da_lin_memmove(731728 + 0 * 256 + 0 * 32, pfinalverts + int(uint(c2da_mem[ptri + 4 + 0 * 4]) | uint(c2da_mem[ptri + 4 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ptri + 4 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ptri + 4 + 0 * 4 + 3]) << 0x18) * 32, 32ul)
        c2da_lin_memmove(731728 + 0 * 256 + 1 * 32, pfinalverts + int(uint(c2da_mem[ptri + 4 + 1 * 4]) | uint(c2da_mem[ptri + 4 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ptri + 4 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ptri + 4 + 1 * 4 + 3]) << 0x18) * 32, 32ul)
        c2da_lin_memmove(731728 + 0 * 256 + 2 * 32, pfinalverts + int(uint(c2da_mem[ptri + 4 + 2 * 4]) | uint(c2da_mem[ptri + 4 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ptri + 4 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ptri + 4 + 2 * 4 + 3]) << 0x18) * 32, 32ul)
    } else {
        i = 0
        while (i < 3) {
            c2da_lin_memmove(731728 + 0 * 256 + i * 32, pfinalverts + int(uint(c2da_mem[ptri + 4 + i * 4]) | uint(c2da_mem[ptri + 4 + i * 4 + 1]) << 0x8 | uint(c2da_mem[ptri + 4 + i * 4 + 2]) << 0x10 | uint(c2da_mem[ptri + 4 + i * 4 + 3]) << 0x18) * 32, 32ul)
            if (int(uint(c2da_mem[ptri]) | uint(c2da_mem[ptri + 1]) << 0x8 | uint(c2da_mem[ptri + 2]) << 0x10 | uint(c2da_mem[ptri + 3]) << 0x18) == 0 && (int(uint(c2da_mem[731728 + 0 * 256 + i * 32 + 24]) | uint(c2da_mem[731728 + 0 * 256 + i * 32 + 25]) << 0x8 | uint(c2da_mem[731728 + 0 * 256 + i * 32 + 26]) << 0x10 | uint(c2da_mem[731728 + 0 * 256 + i * 32 + 27]) << 0x18) & 32) != 0) {
                let c2da_fresh0 : int = int(uint(c2da_mem[731728 + 0 * 256 + i * 32 + 2 * 4]) | uint(c2da_mem[731728 + 0 * 256 + i * 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[731728 + 0 * 256 + i * 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[731728 + 0 * 256 + i * 32 + 2 * 4 + 3]) << 0x18) + int(r_affinetridesc.seamfixupX16)
                let c2da_fresh1 : uint = uint(c2da_fresh0)
                c2da_mem[731728 + 0 * 256 + i * 32 + 2 * 4] = uint8(c2da_fresh1)
                c2da_mem[731728 + 0 * 256 + i * 32 + 2 * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
                c2da_mem[731728 + 0 * 256 + i * 32 + 2 * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
                c2da_mem[731728 + 0 * 256 + i * 32 + 2 * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
            }
            i++
        }
    }
    clipflags = uint(int(uint(c2da_mem[731728 + 0 * 256 + 0 * 32 + 24]) | uint(c2da_mem[731728 + 0 * 256 + 0 * 32 + 25]) << 0x8 | uint(c2da_mem[731728 + 0 * 256 + 0 * 32 + 26]) << 0x10 | uint(c2da_mem[731728 + 0 * 256 + 0 * 32 + 27]) << 0x18) | int(uint(c2da_mem[731728 + 0 * 256 + 1 * 32 + 24]) | uint(c2da_mem[731728 + 0 * 256 + 1 * 32 + 25]) << 0x8 | uint(c2da_mem[731728 + 0 * 256 + 1 * 32 + 26]) << 0x10 | uint(c2da_mem[731728 + 0 * 256 + 1 * 32 + 27]) << 0x18) | int(uint(c2da_mem[731728 + 0 * 256 + 2 * 32 + 24]) | uint(c2da_mem[731728 + 0 * 256 + 2 * 32 + 25]) << 0x8 | uint(c2da_mem[731728 + 0 * 256 + 2 * 32 + 26]) << 0x10 | uint(c2da_mem[731728 + 0 * 256 + 2 * 32 + 27]) << 0x18))
    if ((clipflags & 0x10u) != 0x0) {
        i = 0
        while (i < 3) {
            c2da_lin_memmove(732240 + i * 12, pauxverts + int(uint(c2da_mem[ptri + 4 + i * 4]) | uint(c2da_mem[ptri + 4 + i * 4 + 1]) << 0x8 | uint(c2da_mem[ptri + 4 + i * 4 + 2]) << 0x10 | uint(c2da_mem[ptri + 4 + i * 4 + 3]) << 0x18) * 12, 12ul)
            i++
        }
        k = R_AliasClip(731728 + 0 * 256, 731728 + 1 * 256, 16, 3, 202)
        if (k == 0) {
            return
        }
        pingpong = 1
        clipflags = uint(int(uint(c2da_mem[731728 + 1 * 256 + 0 * 32 + 24]) | uint(c2da_mem[731728 + 1 * 256 + 0 * 32 + 25]) << 0x8 | uint(c2da_mem[731728 + 1 * 256 + 0 * 32 + 26]) << 0x10 | uint(c2da_mem[731728 + 1 * 256 + 0 * 32 + 27]) << 0x18) | int(uint(c2da_mem[731728 + 1 * 256 + 1 * 32 + 24]) | uint(c2da_mem[731728 + 1 * 256 + 1 * 32 + 25]) << 0x8 | uint(c2da_mem[731728 + 1 * 256 + 1 * 32 + 26]) << 0x10 | uint(c2da_mem[731728 + 1 * 256 + 1 * 32 + 27]) << 0x18) | int(uint(c2da_mem[731728 + 1 * 256 + 2 * 32 + 24]) | uint(c2da_mem[731728 + 1 * 256 + 2 * 32 + 25]) << 0x8 | uint(c2da_mem[731728 + 1 * 256 + 2 * 32 + 26]) << 0x10 | uint(c2da_mem[731728 + 1 * 256 + 2 * 32 + 27]) << 0x18))
    } else {
        pingpong = 0
        k = 3
    }
    if ((clipflags & 0x1u) != 0x0) {
        k = R_AliasClip(731728 + pingpong * 256, 731728 + (pingpong ^ 1) * 256, 1, k, 203)
        if (k == 0) {
            return
        }
        pingpong ^= 1
    }
    if ((clipflags & 0x4u) != 0x0) {
        k = R_AliasClip(731728 + pingpong * 256, 731728 + (pingpong ^ 1) * 256, 4, k, 204)
        if (k == 0) {
            return
        }
        pingpong ^= 1
    }
    if ((clipflags & 0x8u) != 0x0) {
        k = R_AliasClip(731728 + pingpong * 256, 731728 + (pingpong ^ 1) * 256, 8, k, 205)
        if (k == 0) {
            return
        }
        pingpong ^= 1
    }
    if ((clipflags & 0x2u) != 0x0) {
        k = R_AliasClip(731728 + pingpong * 256, 731728 + (pingpong ^ 1) * 256, 2, k, 206)
        if (k == 0) {
            return
        }
        pingpong ^= 1
    }
    i = 0
    while (i < k) {
        if (int(uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4]) | uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4 + 3]) << 0x18) < int(uint(c2da_mem[5224]) | uint(c2da_mem[5225]) << 0x8 | uint(c2da_mem[5226]) << 0x10 | uint(c2da_mem[5227]) << 0x18)) {
            let c2da_fresh2 : int = int(uint(c2da_mem[5224]) | uint(c2da_mem[5225]) << 0x8 | uint(c2da_mem[5226]) << 0x10 | uint(c2da_mem[5227]) << 0x18)
            let c2da_fresh3 : uint = uint(c2da_fresh2)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4] = uint8(c2da_fresh3)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
        } elif (int(uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4]) | uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4 + 3]) << 0x18) > int(uint(c2da_mem[5256]) | uint(c2da_mem[5257]) << 0x8 | uint(c2da_mem[5258]) << 0x10 | uint(c2da_mem[5259]) << 0x18)) {
            let c2da_fresh4 : int = int(uint(c2da_mem[5256]) | uint(c2da_mem[5257]) << 0x8 | uint(c2da_mem[5258]) << 0x10 | uint(c2da_mem[5259]) << 0x18)
            let c2da_fresh5 : uint = uint(c2da_fresh4)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4] = uint8(c2da_fresh5)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4 + 1] = uint8(c2da_fresh5 >> 0x8)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4 + 2] = uint8(c2da_fresh5 >> 0x10)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 0 * 4 + 3] = uint8(c2da_fresh5 >> 0x18)
        }
        if (int(uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4]) | uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4 + 3]) << 0x18) < int(uint(c2da_mem[5228]) | uint(c2da_mem[5229]) << 0x8 | uint(c2da_mem[5230]) << 0x10 | uint(c2da_mem[5231]) << 0x18)) {
            let c2da_fresh6 : int = int(uint(c2da_mem[5228]) | uint(c2da_mem[5229]) << 0x8 | uint(c2da_mem[5230]) << 0x10 | uint(c2da_mem[5231]) << 0x18)
            let c2da_fresh7 : uint = uint(c2da_fresh6)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4] = uint8(c2da_fresh7)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
        } elif (int(uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4]) | uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4 + 3]) << 0x18) > int(uint(c2da_mem[5260]) | uint(c2da_mem[5261]) << 0x8 | uint(c2da_mem[5262]) << 0x10 | uint(c2da_mem[5263]) << 0x18)) {
            let c2da_fresh8 : int = int(uint(c2da_mem[5260]) | uint(c2da_mem[5261]) << 0x8 | uint(c2da_mem[5262]) << 0x10 | uint(c2da_mem[5263]) << 0x18)
            let c2da_fresh9 : uint = uint(c2da_fresh8)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4] = uint8(c2da_fresh9)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4 + 1] = uint8(c2da_fresh9 >> 0x8)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4 + 2] = uint8(c2da_fresh9 >> 0x10)
            c2da_mem[731728 + pingpong * 256 + i * 32 + 1 * 4 + 3] = uint8(c2da_fresh9 >> 0x18)
        }
        let c2da_fresh10 : int = 0
        let c2da_fresh11 : uint = uint(c2da_fresh10)
        c2da_mem[731728 + pingpong * 256 + i * 32 + 24] = uint8(c2da_fresh11)
        c2da_mem[731728 + pingpong * 256 + i * 32 + 25] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[731728 + pingpong * 256 + i * 32 + 26] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[731728 + pingpong * 256 + i * 32 + 27] = uint8(c2da_fresh11 >> 0x18)
        i++
    }
    let c2da_fresh12 : int = int(uint(c2da_mem[ptri]) | uint(c2da_mem[ptri + 1]) << 0x8 | uint(c2da_mem[ptri + 2]) << 0x10 | uint(c2da_mem[ptri + 3]) << 0x18)
    let c2da_fresh13 : uint = uint(c2da_fresh12)
    c2da_mem[c2da_fp] = uint8(c2da_fresh13)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh13 >> 0x18)
    r_affinetridesc.ptriangles = c2da_fp
    r_affinetridesc.pfinalverts = 731728 + pingpong * 256
    let c2da_fresh14 : int = 0
    let c2da_fresh15 : uint = uint(c2da_fresh14)
    c2da_mem[c2da_fp + 4 + 0 * 4] = uint8(c2da_fresh15)
    c2da_mem[c2da_fp + 4 + 0 * 4 + 1] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[c2da_fp + 4 + 0 * 4 + 2] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[c2da_fp + 4 + 0 * 4 + 3] = uint8(c2da_fresh15 >> 0x18)
    i = 1
    for (c2da_i in range(i, k - 1)) {
        let c2da_fresh16 : uint = uint(c2da_i)
        c2da_mem[c2da_fp + 4 + 1 * 4] = uint8(c2da_fresh16)
        c2da_mem[c2da_fp + 4 + 1 * 4 + 1] = uint8(c2da_fresh16 >> 0x8)
        c2da_mem[c2da_fp + 4 + 1 * 4 + 2] = uint8(c2da_fresh16 >> 0x10)
        c2da_mem[c2da_fp + 4 + 1 * 4 + 3] = uint8(c2da_fresh16 >> 0x18)
        let c2da_fresh17 : int = c2da_i + 1
        let c2da_fresh18 : uint = uint(c2da_fresh17)
        c2da_mem[c2da_fp + 4 + 2 * 4] = uint8(c2da_fresh18)
        c2da_mem[c2da_fp + 4 + 2 * 4 + 1] = uint8(c2da_fresh18 >> 0x8)
        c2da_mem[c2da_fp + 4 + 2 * 4 + 2] = uint8(c2da_fresh18 >> 0x10)
        c2da_mem[c2da_fp + 4 + 2 * 4 + 3] = uint8(c2da_fresh18 >> 0x18)
        D_PolysetDraw()
    }
    return
}
[sideeffects]
def private R_Alias_clip_z_c2da_frame(var pfv0_3 : int; var pfv1_3 : int; var out_4 : int; c2da_fp : int) {
    var scale_3 : float
    var pav0 : int
    var pav1 : int
    pav0 = 732240 + (pfv0_3 - (731728 + 0 * 256 + 0 * 32)) / 32 * 12
    pav1 = 732240 + (pfv1_3 - (731728 + 0 * 256 + 0 * 32)) / 32 * 12
    if (int(uint(c2da_mem[pfv0_3 + 1 * 4]) | uint(c2da_mem[pfv0_3 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_3 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_3 + 1 * 4 + 3]) << 0x18) >= int(uint(c2da_mem[pfv1_3 + 1 * 4]) | uint(c2da_mem[pfv1_3 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_3 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_3 + 1 * 4 + 3]) << 0x18)) {
        let c2da_fresh94 : float = uint_bits_to_float(uint(c2da_mem[pav0 + 2 * 4]) | uint(c2da_mem[pav0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pav0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pav0 + 2 * 4 + 3]) << 0x18)
        scale_3 = (5.0 - c2da_fresh94) / (uint_bits_to_float(uint(c2da_mem[pav1 + 2 * 4]) | uint(c2da_mem[pav1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pav1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pav1 + 2 * 4 + 3]) << 0x18) - c2da_fresh94)
        let c2da_fresh95 : float = uint_bits_to_float(uint(c2da_mem[pav0 + 0 * 4]) | uint(c2da_mem[pav0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pav0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pav0 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh62 : float = c2da_fresh95 + (uint_bits_to_float(uint(c2da_mem[pav1 + 0 * 4]) | uint(c2da_mem[pav1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pav1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pav1 + 0 * 4 + 3]) << 0x18) - c2da_fresh95) * scale_3
        let c2da_fresh63 : uint = float_bits_to_uint(c2da_fresh62)
        c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh63)
        c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh63 >> 0x8)
        c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh63 >> 0x10)
        c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh63 >> 0x18)
        let c2da_fresh96 : float = uint_bits_to_float(uint(c2da_mem[pav0 + 1 * 4]) | uint(c2da_mem[pav0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pav0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pav0 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh64 : float = c2da_fresh96 + (uint_bits_to_float(uint(c2da_mem[pav1 + 1 * 4]) | uint(c2da_mem[pav1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pav1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pav1 + 1 * 4 + 3]) << 0x18) - c2da_fresh96) * scale_3
        let c2da_fresh65 : uint = float_bits_to_uint(c2da_fresh64)
        c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh65)
        c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh65 >> 0x8)
        c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh65 >> 0x10)
        c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh65 >> 0x18)
        let c2da_fresh66 : float = 5.0
        let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh67)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh67 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh67 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh67 >> 0x18)
        let c2da_fresh97 : int = int(uint(c2da_mem[pfv0_3 + 2 * 4]) | uint(c2da_mem[pfv0_3 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_3 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_3 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh68 : int = int(float(c2da_fresh97) + float(int(uint(c2da_mem[pfv1_3 + 2 * 4]) | uint(c2da_mem[pfv1_3 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_3 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_3 + 2 * 4 + 3]) << 0x18) - c2da_fresh97) * scale_3)
        let c2da_fresh69 : uint = uint(c2da_fresh68)
        c2da_mem[out_4 + 2 * 4] = uint8(c2da_fresh69)
        c2da_mem[out_4 + 2 * 4 + 1] = uint8(c2da_fresh69 >> 0x8)
        c2da_mem[out_4 + 2 * 4 + 2] = uint8(c2da_fresh69 >> 0x10)
        c2da_mem[out_4 + 2 * 4 + 3] = uint8(c2da_fresh69 >> 0x18)
        let c2da_fresh98 : int = int(uint(c2da_mem[pfv0_3 + 3 * 4]) | uint(c2da_mem[pfv0_3 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_3 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_3 + 3 * 4 + 3]) << 0x18)
        let c2da_fresh70 : int = int(float(c2da_fresh98) + float(int(uint(c2da_mem[pfv1_3 + 3 * 4]) | uint(c2da_mem[pfv1_3 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_3 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_3 + 3 * 4 + 3]) << 0x18) - c2da_fresh98) * scale_3)
        let c2da_fresh71 : uint = uint(c2da_fresh70)
        c2da_mem[out_4 + 3 * 4] = uint8(c2da_fresh71)
        c2da_mem[out_4 + 3 * 4 + 1] = uint8(c2da_fresh71 >> 0x8)
        c2da_mem[out_4 + 3 * 4 + 2] = uint8(c2da_fresh71 >> 0x10)
        c2da_mem[out_4 + 3 * 4 + 3] = uint8(c2da_fresh71 >> 0x18)
        let c2da_fresh99 : int = int(uint(c2da_mem[pfv0_3 + 4 * 4]) | uint(c2da_mem[pfv0_3 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_3 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_3 + 4 * 4 + 3]) << 0x18)
        let c2da_fresh72 : int = int(float(c2da_fresh99) + float(int(uint(c2da_mem[pfv1_3 + 4 * 4]) | uint(c2da_mem[pfv1_3 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_3 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_3 + 4 * 4 + 3]) << 0x18) - c2da_fresh99) * scale_3)
        let c2da_fresh73 : uint = uint(c2da_fresh72)
        c2da_mem[out_4 + 4 * 4] = uint8(c2da_fresh73)
        c2da_mem[out_4 + 4 * 4 + 1] = uint8(c2da_fresh73 >> 0x8)
        c2da_mem[out_4 + 4 * 4 + 2] = uint8(c2da_fresh73 >> 0x10)
        c2da_mem[out_4 + 4 * 4 + 3] = uint8(c2da_fresh73 >> 0x18)
    } else {
        let c2da_fresh100 : float = uint_bits_to_float(uint(c2da_mem[pav1 + 2 * 4]) | uint(c2da_mem[pav1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pav1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pav1 + 2 * 4 + 3]) << 0x18)
        scale_3 = (5.0 - c2da_fresh100) / (uint_bits_to_float(uint(c2da_mem[pav0 + 2 * 4]) | uint(c2da_mem[pav0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pav0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pav0 + 2 * 4 + 3]) << 0x18) - c2da_fresh100)
        let c2da_fresh101 : float = uint_bits_to_float(uint(c2da_mem[pav1 + 0 * 4]) | uint(c2da_mem[pav1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pav1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pav1 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh74 : float = c2da_fresh101 + (uint_bits_to_float(uint(c2da_mem[pav0 + 0 * 4]) | uint(c2da_mem[pav0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pav0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pav0 + 0 * 4 + 3]) << 0x18) - c2da_fresh101) * scale_3
        let c2da_fresh75 : uint = float_bits_to_uint(c2da_fresh74)
        c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh75)
        c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh75 >> 0x8)
        c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh75 >> 0x10)
        c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh75 >> 0x18)
        let c2da_fresh102 : float = uint_bits_to_float(uint(c2da_mem[pav1 + 1 * 4]) | uint(c2da_mem[pav1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pav1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pav1 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh76 : float = c2da_fresh102 + (uint_bits_to_float(uint(c2da_mem[pav0 + 1 * 4]) | uint(c2da_mem[pav0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pav0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pav0 + 1 * 4 + 3]) << 0x18) - c2da_fresh102) * scale_3
        let c2da_fresh77 : uint = float_bits_to_uint(c2da_fresh76)
        c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh77)
        c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh77 >> 0x8)
        c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh77 >> 0x10)
        c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh77 >> 0x18)
        let c2da_fresh78 : float = 5.0
        let c2da_fresh79 : uint = float_bits_to_uint(c2da_fresh78)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh79)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh79 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh79 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh79 >> 0x18)
        let c2da_fresh103 : int = int(uint(c2da_mem[pfv1_3 + 2 * 4]) | uint(c2da_mem[pfv1_3 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_3 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_3 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh80 : int = int(float(c2da_fresh103) + float(int(uint(c2da_mem[pfv0_3 + 2 * 4]) | uint(c2da_mem[pfv0_3 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_3 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_3 + 2 * 4 + 3]) << 0x18) - c2da_fresh103) * scale_3)
        let c2da_fresh81 : uint = uint(c2da_fresh80)
        c2da_mem[out_4 + 2 * 4] = uint8(c2da_fresh81)
        c2da_mem[out_4 + 2 * 4 + 1] = uint8(c2da_fresh81 >> 0x8)
        c2da_mem[out_4 + 2 * 4 + 2] = uint8(c2da_fresh81 >> 0x10)
        c2da_mem[out_4 + 2 * 4 + 3] = uint8(c2da_fresh81 >> 0x18)
        let c2da_fresh104 : int = int(uint(c2da_mem[pfv1_3 + 3 * 4]) | uint(c2da_mem[pfv1_3 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_3 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_3 + 3 * 4 + 3]) << 0x18)
        let c2da_fresh82 : int = int(float(c2da_fresh104) + float(int(uint(c2da_mem[pfv0_3 + 3 * 4]) | uint(c2da_mem[pfv0_3 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_3 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_3 + 3 * 4 + 3]) << 0x18) - c2da_fresh104) * scale_3)
        let c2da_fresh83 : uint = uint(c2da_fresh82)
        c2da_mem[out_4 + 3 * 4] = uint8(c2da_fresh83)
        c2da_mem[out_4 + 3 * 4 + 1] = uint8(c2da_fresh83 >> 0x8)
        c2da_mem[out_4 + 3 * 4 + 2] = uint8(c2da_fresh83 >> 0x10)
        c2da_mem[out_4 + 3 * 4 + 3] = uint8(c2da_fresh83 >> 0x18)
        let c2da_fresh105 : int = int(uint(c2da_mem[pfv1_3 + 4 * 4]) | uint(c2da_mem[pfv1_3 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv1_3 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv1_3 + 4 * 4 + 3]) << 0x18)
        let c2da_fresh84 : int = int(float(c2da_fresh105) + float(int(uint(c2da_mem[pfv0_3 + 4 * 4]) | uint(c2da_mem[pfv0_3 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pfv0_3 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pfv0_3 + 4 * 4 + 3]) << 0x18) - c2da_fresh105) * scale_3)
        let c2da_fresh85 : uint = uint(c2da_fresh84)
        c2da_mem[out_4 + 4 * 4] = uint8(c2da_fresh85)
        c2da_mem[out_4 + 4 * 4 + 1] = uint8(c2da_fresh85 >> 0x8)
        c2da_mem[out_4 + 4 * 4 + 2] = uint8(c2da_fresh85 >> 0x10)
        c2da_mem[out_4 + 4 * 4 + 3] = uint8(c2da_fresh85 >> 0x18)
    }
    R_AliasProjectFinalVert(out_4, c2da_fp)
    if (int(uint(c2da_mem[out_4 + 0 * 4]) | uint(c2da_mem[out_4 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[out_4 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[out_4 + 0 * 4 + 3]) << 0x18) < int(uint(c2da_mem[5224]) | uint(c2da_mem[5225]) << 0x8 | uint(c2da_mem[5226]) << 0x10 | uint(c2da_mem[5227]) << 0x18)) {
        let c2da_fresh86 : int = int(uint(c2da_mem[out_4 + 24]) | uint(c2da_mem[out_4 + 25]) << 0x8 | uint(c2da_mem[out_4 + 26]) << 0x10 | uint(c2da_mem[out_4 + 27]) << 0x18) | 1
        let c2da_fresh87 : uint = uint(c2da_fresh86)
        c2da_mem[out_4 + 24] = uint8(c2da_fresh87)
        c2da_mem[out_4 + 25] = uint8(c2da_fresh87 >> 0x8)
        c2da_mem[out_4 + 26] = uint8(c2da_fresh87 >> 0x10)
        c2da_mem[out_4 + 27] = uint8(c2da_fresh87 >> 0x18)
    }
    if (int(uint(c2da_mem[out_4 + 1 * 4]) | uint(c2da_mem[out_4 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[out_4 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[out_4 + 1 * 4 + 3]) << 0x18) < int(uint(c2da_mem[5228]) | uint(c2da_mem[5229]) << 0x8 | uint(c2da_mem[5230]) << 0x10 | uint(c2da_mem[5231]) << 0x18)) {
        let c2da_fresh88 : int = int(uint(c2da_mem[out_4 + 24]) | uint(c2da_mem[out_4 + 25]) << 0x8 | uint(c2da_mem[out_4 + 26]) << 0x10 | uint(c2da_mem[out_4 + 27]) << 0x18) | 2
        let c2da_fresh89 : uint = uint(c2da_fresh88)
        c2da_mem[out_4 + 24] = uint8(c2da_fresh89)
        c2da_mem[out_4 + 25] = uint8(c2da_fresh89 >> 0x8)
        c2da_mem[out_4 + 26] = uint8(c2da_fresh89 >> 0x10)
        c2da_mem[out_4 + 27] = uint8(c2da_fresh89 >> 0x18)
    }
    if (int(uint(c2da_mem[out_4 + 0 * 4]) | uint(c2da_mem[out_4 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[out_4 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[out_4 + 0 * 4 + 3]) << 0x18) > int(uint(c2da_mem[5256]) | uint(c2da_mem[5257]) << 0x8 | uint(c2da_mem[5258]) << 0x10 | uint(c2da_mem[5259]) << 0x18)) {
        let c2da_fresh90 : int = int(uint(c2da_mem[out_4 + 24]) | uint(c2da_mem[out_4 + 25]) << 0x8 | uint(c2da_mem[out_4 + 26]) << 0x10 | uint(c2da_mem[out_4 + 27]) << 0x18) | 4
        let c2da_fresh91 : uint = uint(c2da_fresh90)
        c2da_mem[out_4 + 24] = uint8(c2da_fresh91)
        c2da_mem[out_4 + 25] = uint8(c2da_fresh91 >> 0x8)
        c2da_mem[out_4 + 26] = uint8(c2da_fresh91 >> 0x10)
        c2da_mem[out_4 + 27] = uint8(c2da_fresh91 >> 0x18)
    }
    if (int(uint(c2da_mem[out_4 + 1 * 4]) | uint(c2da_mem[out_4 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[out_4 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[out_4 + 1 * 4 + 3]) << 0x18) > int(uint(c2da_mem[5260]) | uint(c2da_mem[5261]) << 0x8 | uint(c2da_mem[5262]) << 0x10 | uint(c2da_mem[5263]) << 0x18)) {
        let c2da_fresh92 : int = int(uint(c2da_mem[out_4 + 24]) | uint(c2da_mem[out_4 + 25]) << 0x8 | uint(c2da_mem[out_4 + 26]) << 0x10 | uint(c2da_mem[out_4 + 27]) << 0x18) | 8
        let c2da_fresh93 : uint = uint(c2da_fresh92)
        c2da_mem[out_4 + 24] = uint8(c2da_fresh93)
        c2da_mem[out_4 + 25] = uint8(c2da_fresh93 >> 0x8)
        c2da_mem[out_4 + 26] = uint8(c2da_fresh93 >> 0x10)
        c2da_mem[out_4 + 27] = uint8(c2da_fresh93 >> 0x18)
    }
    return
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_r_aclip() {
    if (length(c2da_fn_table12) < 207) {
        resize(c2da_fn_table12, 207)
    }
    c2da_fn_table12[206] = @@R_Alias_clip_top
    c2da_fn_table12[205] = @@R_Alias_clip_bottom
    c2da_fn_table12[204] = @@R_Alias_clip_right
    c2da_fn_table12[203] = @@R_Alias_clip_left
    c2da_fn_table12[202] = @@R_Alias_clip_z
}

[init]
def private c2da_lin_relink_init_r_aclip() {
    c2da_relink_r_aclip()
}
