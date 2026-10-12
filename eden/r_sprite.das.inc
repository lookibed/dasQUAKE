[export, sideeffects]
def R_DrawSprite() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_DrawSprite_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_SetupAndDrawSprite() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_SetupAndDrawSprite_c2da_frame(c2da_lin_enter(528))
    c2da_lin_sp = c2da_saved_sp
}
var private clip_current : int = default<int>

[export, sideeffects]
def R_ClipSpriteFace(var nump_0 : int; var pclipplane : int) : int {
    var i_1 : int
    var outcount : int
    var dists : float[21]
    var frac : float
    var clipdist : float
    var pclipnormal : int
    var in_0 : int
    var instep : int
    var outstep : int
    var vert2 : int
    clipdist = uint_bits_to_float(uint(c2da_mem[pclipplane + 12]) | uint(c2da_mem[pclipplane + 13]) << 0x8 | uint(c2da_mem[pclipplane + 14]) << 0x10 | uint(c2da_mem[pclipplane + 15]) << 0x18)
    pclipnormal = pclipplane
    if (clip_current != 0) {
        in_0 = 733632 + 1 * 400 + 0 * 20
        outstep = 733632 + 0 * 400 + 0 * 20
        clip_current = 0
    } else {
        in_0 = 733632 + 0 * 400 + 0 * 20
        outstep = 733632 + 1 * 400 + 0 * 20
        clip_current = 1
    }
    instep = in_0
    i_1 = 0
    while (i_1 < nump_0) {
        dists[i_1] = uint_bits_to_float(uint(c2da_mem[instep + 0 * 4]) | uint(c2da_mem[instep + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[instep + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[instep + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pclipnormal + 0 * 4]) | uint(c2da_mem[pclipnormal + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pclipnormal + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pclipnormal + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[instep + 1 * 4]) | uint(c2da_mem[instep + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[instep + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[instep + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pclipnormal + 1 * 4]) | uint(c2da_mem[pclipnormal + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pclipnormal + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pclipnormal + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[instep + 2 * 4]) | uint(c2da_mem[instep + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[instep + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[instep + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[pclipnormal + 2 * 4]) | uint(c2da_mem[pclipnormal + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pclipnormal + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pclipnormal + 2 * 4 + 3]) << 0x18) - clipdist
        i_1++
        instep += int(20ul / 4ul) * 4
    }
    dists[nump_0] = float(dists[0])  // nolint:PERF020
    Q_memcpy(instep, in_0, 20)
    instep = in_0
    outcount = 0
    i_1 = 0
    while (i_1 < nump_0) {
        if (dists[i_1] >= 0.0) {
            Q_memcpy(outstep, instep, 20)
            outstep += int(20ul / 4ul) * 4
            outcount++
        }
        if (dists[i_1] == 0.0 || dists[i_1 + 1] == 0.0) {
            i_1++
            instep += int(20ul / 4ul) * 4
            continue
        }
        if ((dists[i_1] > 0.0 ? 1 : 0) == (dists[i_1 + 1] > 0.0 ? 1 : 0)) {
            i_1++
            instep += int(20ul / 4ul) * 4
            continue
        }
        frac = dists[i_1] / (dists[i_1] - dists[i_1 + 1])
        vert2 = instep + int(20ul / 4ul) * 4
        let c2da_fresh140 : float = uint_bits_to_float(uint(c2da_mem[instep + 0 * 4]) | uint(c2da_mem[instep + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[instep + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[instep + 0 * 4 + 3]) << 0x18)
        let c2da_fresh130 : float = c2da_fresh140 + frac * (uint_bits_to_float(uint(c2da_mem[vert2 + 0 * 4]) | uint(c2da_mem[vert2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[vert2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[vert2 + 0 * 4 + 3]) << 0x18) - c2da_fresh140)
        let c2da_fresh131 : uint = float_bits_to_uint(c2da_fresh130)
        c2da_mem[outstep + 0 * 4] = uint8(c2da_fresh131)
        c2da_mem[outstep + 0 * 4 + 1] = uint8(c2da_fresh131 >> 0x8)
        c2da_mem[outstep + 0 * 4 + 2] = uint8(c2da_fresh131 >> 0x10)
        c2da_mem[outstep + 0 * 4 + 3] = uint8(c2da_fresh131 >> 0x18)
        let c2da_fresh141 : float = uint_bits_to_float(uint(c2da_mem[instep + 1 * 4]) | uint(c2da_mem[instep + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[instep + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[instep + 1 * 4 + 3]) << 0x18)
        let c2da_fresh132 : float = c2da_fresh141 + frac * (uint_bits_to_float(uint(c2da_mem[vert2 + 1 * 4]) | uint(c2da_mem[vert2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[vert2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[vert2 + 1 * 4 + 3]) << 0x18) - c2da_fresh141)
        let c2da_fresh133 : uint = float_bits_to_uint(c2da_fresh132)
        c2da_mem[outstep + 1 * 4] = uint8(c2da_fresh133)
        c2da_mem[outstep + 1 * 4 + 1] = uint8(c2da_fresh133 >> 0x8)
        c2da_mem[outstep + 1 * 4 + 2] = uint8(c2da_fresh133 >> 0x10)
        c2da_mem[outstep + 1 * 4 + 3] = uint8(c2da_fresh133 >> 0x18)
        let c2da_fresh142 : float = uint_bits_to_float(uint(c2da_mem[instep + 2 * 4]) | uint(c2da_mem[instep + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[instep + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[instep + 2 * 4 + 3]) << 0x18)
        let c2da_fresh134 : float = c2da_fresh142 + frac * (uint_bits_to_float(uint(c2da_mem[vert2 + 2 * 4]) | uint(c2da_mem[vert2 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[vert2 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[vert2 + 2 * 4 + 3]) << 0x18) - c2da_fresh142)
        let c2da_fresh135 : uint = float_bits_to_uint(c2da_fresh134)
        c2da_mem[outstep + 2 * 4] = uint8(c2da_fresh135)
        c2da_mem[outstep + 2 * 4 + 1] = uint8(c2da_fresh135 >> 0x8)
        c2da_mem[outstep + 2 * 4 + 2] = uint8(c2da_fresh135 >> 0x10)
        c2da_mem[outstep + 2 * 4 + 3] = uint8(c2da_fresh135 >> 0x18)
        let c2da_fresh143 : float = uint_bits_to_float(uint(c2da_mem[instep + 3 * 4]) | uint(c2da_mem[instep + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[instep + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[instep + 3 * 4 + 3]) << 0x18)
        let c2da_fresh136 : float = c2da_fresh143 + frac * (uint_bits_to_float(uint(c2da_mem[vert2 + 3 * 4]) | uint(c2da_mem[vert2 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[vert2 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[vert2 + 3 * 4 + 3]) << 0x18) - c2da_fresh143)
        let c2da_fresh137 : uint = float_bits_to_uint(c2da_fresh136)
        c2da_mem[outstep + 3 * 4] = uint8(c2da_fresh137)
        c2da_mem[outstep + 3 * 4 + 1] = uint8(c2da_fresh137 >> 0x8)
        c2da_mem[outstep + 3 * 4 + 2] = uint8(c2da_fresh137 >> 0x10)
        c2da_mem[outstep + 3 * 4 + 3] = uint8(c2da_fresh137 >> 0x18)
        let c2da_fresh144 : float = uint_bits_to_float(uint(c2da_mem[instep + 4 * 4]) | uint(c2da_mem[instep + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[instep + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[instep + 4 * 4 + 3]) << 0x18)
        let c2da_fresh138 : float = c2da_fresh144 + frac * (uint_bits_to_float(uint(c2da_mem[vert2 + 4 * 4]) | uint(c2da_mem[vert2 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[vert2 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[vert2 + 4 * 4 + 3]) << 0x18) - c2da_fresh144)
        let c2da_fresh139 : uint = float_bits_to_uint(c2da_fresh138)
        c2da_mem[outstep + 4 * 4] = uint8(c2da_fresh139)
        c2da_mem[outstep + 4 * 4 + 1] = uint8(c2da_fresh139 >> 0x8)
        c2da_mem[outstep + 4 * 4 + 2] = uint8(c2da_fresh139 >> 0x10)
        c2da_mem[outstep + 4 * 4 + 3] = uint8(c2da_fresh139 >> 0x18)
        outstep += int(20ul / 4ul) * 4
        outcount++
        i_1++
        instep += int(20ul / 4ul) * 4
    }
    return outcount
}
var private sprite_height_0 : int = default<int>

var private sprite_width : int = default<int>

[export, sideeffects]
def R_RotateSprite(var beamlength_0 : float) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_RotateSprite_c2da_frame(beamlength_0, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_GetSpriteframe(var psprite_0 : int) : int {
    var pspritegroup : int
    var pspriteframe : int
    var i_2 : int
    var numframes : int
    var frame : int
    var pintervals : int
    var fullinterval : float
    var targettime : float
    var time : float
    frame = int(uint(c2da_mem[currententity + 152]) | uint(c2da_mem[currententity + 153]) << 0x8 | uint(c2da_mem[currententity + 154]) << 0x10 | uint(c2da_mem[currententity + 155]) << 0x18)
    if (frame >= int(uint(c2da_mem[psprite_0 + 12]) | uint(c2da_mem[psprite_0 + 13]) << 0x8 | uint(c2da_mem[psprite_0 + 14]) << 0x10 | uint(c2da_mem[psprite_0 + 15]) << 0x18) || frame < 0) {
        Con_Printf(734503, [C2daVaArg(tag = 1, i64 = int64(frame), f64 = 0.0lf, raw = 0x0)])
        frame = 0
    }
    if ((uint(c2da_mem[psprite_0 + 32 + frame * 16]) | uint(c2da_mem[psprite_0 + 32 + frame * 16 + 1]) << 0x8 | uint(c2da_mem[psprite_0 + 32 + frame * 16 + 2]) << 0x10 | uint(c2da_mem[psprite_0 + 32 + frame * 16 + 3]) << 0x18) == 0u) {
        pspriteframe = int(uint(c2da_mem[psprite_0 + 32 + frame * 16 + 8]) | uint(c2da_mem[psprite_0 + 32 + frame * 16 + 9]) << 0x8 | uint(c2da_mem[psprite_0 + 32 + frame * 16 + 10]) << 0x10 | uint(c2da_mem[psprite_0 + 32 + frame * 16 + 11]) << 0x18)
    } else {
        pspritegroup = int(uint(c2da_mem[psprite_0 + 32 + frame * 16 + 8]) | uint(c2da_mem[psprite_0 + 32 + frame * 16 + 9]) << 0x8 | uint(c2da_mem[psprite_0 + 32 + frame * 16 + 10]) << 0x10 | uint(c2da_mem[psprite_0 + 32 + frame * 16 + 11]) << 0x18)
        pintervals = int(uint(c2da_mem[pspritegroup + 8]) | uint(c2da_mem[pspritegroup + 9]) << 0x8 | uint(c2da_mem[pspritegroup + 10]) << 0x10 | uint(c2da_mem[pspritegroup + 11]) << 0x18)
        numframes = int(uint(c2da_mem[pspritegroup]) | uint(c2da_mem[pspritegroup + 1]) << 0x8 | uint(c2da_mem[pspritegroup + 2]) << 0x10 | uint(c2da_mem[pspritegroup + 3]) << 0x18)
        fullinterval = uint_bits_to_float(uint(c2da_mem[pintervals + (numframes - 1) * 4]) | uint(c2da_mem[pintervals + (numframes - 1) * 4 + 1]) << 0x8 | uint(c2da_mem[pintervals + (numframes - 1) * 4 + 2]) << 0x10 | uint(c2da_mem[pintervals + (numframes - 1) * 4 + 3]) << 0x18)
        time = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + double(uint_bits_to_float(uint(c2da_mem[currententity + 156]) | uint(c2da_mem[currententity + 157]) << 0x8 | uint(c2da_mem[currententity + 158]) << 0x10 | uint(c2da_mem[currententity + 159]) << 0x18)))
        targettime = time - float(int(time / fullinterval)) * fullinterval
        i_2 = 0
        while (i_2 < numframes - 1) {
            if (uint_bits_to_float(uint(c2da_mem[pintervals + i_2 * 4]) | uint(c2da_mem[pintervals + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[pintervals + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[pintervals + i_2 * 4 + 3]) << 0x18) > targettime) {
                break
            }
            i_2++
        }
        pspriteframe = int(uint(c2da_mem[pspritegroup + 16 + i_2 * 8]) | uint(c2da_mem[pspritegroup + 16 + i_2 * 8 + 1]) << 0x8 | uint(c2da_mem[pspritegroup + 16 + i_2 * 8 + 2]) << 0x10 | uint(c2da_mem[pspritegroup + 16 + i_2 * 8 + 3]) << 0x18)
    }
    return pspriteframe
}
[sideeffects]
def private R_DrawSprite_c2da_frame(c2da_fp : int) {
    var i : int
    var psprite : int
    var dot : float
    var angle : float
    var sr : float
    var cr : float
    let c2da_fresh0 : int = int(uint(c2da_mem[currententity + 136]) | uint(c2da_mem[currententity + 137]) << 0x8 | uint(c2da_mem[currententity + 138]) << 0x10 | uint(c2da_mem[currententity + 139]) << 0x18) + 528
    psprite = int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18)
    let c2da_fresh1 : int = R_GetSpriteframe(psprite)
    let c2da_fresh2 : uint = uint(c2da_fresh1)
    c2da_mem[216592] = uint8(c2da_fresh2)
    c2da_mem[216593] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[216594] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[216595] = uint8(c2da_fresh2 >> 0x18)
    c2da_mem[216596] = 0u8
    c2da_mem[216597] = 0u8
    c2da_mem[216598] = 0u8
    c2da_mem[216599] = 0u8
    let c2da_fresh59 : int = int(uint(c2da_mem[216592]) | uint(c2da_mem[216593]) << 0x8 | uint(c2da_mem[216594]) << 0x10 | uint(c2da_mem[216595]) << 0x18)
    let c2da_fresh3 : int = c2da_fresh59
    sprite_width = int(uint(c2da_mem[c2da_fresh3]) | uint(c2da_mem[c2da_fresh3 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh3 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh3 + 3]) << 0x18)
    let c2da_fresh4 : int = c2da_fresh59 + 4
    sprite_height_0 = int(uint(c2da_mem[c2da_fresh4]) | uint(c2da_mem[c2da_fresh4 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh4 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh4 + 3]) << 0x18)
    if (int(uint(c2da_mem[psprite]) | uint(c2da_mem[psprite + 1]) << 0x8 | uint(c2da_mem[psprite + 2]) << 0x10 | uint(c2da_mem[psprite + 3]) << 0x18) == 1) {
        let c2da_fresh5 : float = -uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh6 : uint = float_bits_to_uint(c2da_fresh5)
        c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh6)
        c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh6 >> 0x8)
        c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh6 >> 0x10)
        c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh6 >> 0x18)
        let c2da_fresh7 : float = -uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh8 : uint = float_bits_to_uint(c2da_fresh7)
        c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh8)
        c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh8 >> 0x8)
        c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh8 >> 0x10)
        c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh8 >> 0x18)
        let c2da_fresh9 : float = -uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh10 : uint = float_bits_to_uint(c2da_fresh9)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh10)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh10 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh10 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh10 >> 0x18)
        VectorNormalize(c2da_fp)
        dot = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
        if (double(dot) > 0.999848lf || double(dot) < -0.999848lf) {
            return
        }
        let c2da_fresh11 : float = 0.0
        let c2da_fresh12 : uint = float_bits_to_uint(c2da_fresh11)
        c2da_mem[216600 + 0 * 4] = uint8(c2da_fresh12)
        c2da_mem[216600 + 0 * 4 + 1] = uint8(c2da_fresh12 >> 0x8)
        c2da_mem[216600 + 0 * 4 + 2] = uint8(c2da_fresh12 >> 0x10)
        c2da_mem[216600 + 0 * 4 + 3] = uint8(c2da_fresh12 >> 0x18)
        let c2da_fresh13 : float = 0.0
        let c2da_fresh14 : uint = float_bits_to_uint(c2da_fresh13)
        c2da_mem[216600 + 1 * 4] = uint8(c2da_fresh14)
        c2da_mem[216600 + 1 * 4 + 1] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[216600 + 1 * 4 + 2] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[216600 + 1 * 4 + 3] = uint8(c2da_fresh14 >> 0x18)
        let c2da_fresh15 : float = 1.0
        let c2da_fresh16 : uint = float_bits_to_uint(c2da_fresh15)
        c2da_mem[216600 + 2 * 4] = uint8(c2da_fresh16)
        c2da_mem[216600 + 2 * 4 + 1] = uint8(c2da_fresh16 >> 0x8)
        c2da_mem[216600 + 2 * 4 + 2] = uint8(c2da_fresh16 >> 0x10)
        c2da_mem[216600 + 2 * 4 + 3] = uint8(c2da_fresh16 >> 0x18)
        let c2da_fresh17 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
        let c2da_fresh18 : uint = float_bits_to_uint(c2da_fresh17)
        c2da_mem[216612 + 0 * 4] = uint8(c2da_fresh18)
        c2da_mem[216612 + 0 * 4 + 1] = uint8(c2da_fresh18 >> 0x8)
        c2da_mem[216612 + 0 * 4 + 2] = uint8(c2da_fresh18 >> 0x10)
        c2da_mem[216612 + 0 * 4 + 3] = uint8(c2da_fresh18 >> 0x18)
        let c2da_fresh19 : float = -uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
        let c2da_fresh20 : uint = float_bits_to_uint(c2da_fresh19)
        c2da_mem[216612 + 1 * 4] = uint8(c2da_fresh20)
        c2da_mem[216612 + 1 * 4 + 1] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[216612 + 1 * 4 + 2] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[216612 + 1 * 4 + 3] = uint8(c2da_fresh20 >> 0x18)
        let c2da_fresh21 : float = 0.0
        let c2da_fresh22 : uint = float_bits_to_uint(c2da_fresh21)
        c2da_mem[216612 + 2 * 4] = uint8(c2da_fresh22)
        c2da_mem[216612 + 2 * 4 + 1] = uint8(c2da_fresh22 >> 0x8)
        c2da_mem[216612 + 2 * 4 + 2] = uint8(c2da_fresh22 >> 0x10)
        c2da_mem[216612 + 2 * 4 + 3] = uint8(c2da_fresh22 >> 0x18)
        VectorNormalize(216612)
        let c2da_fresh23 : float = -uint_bits_to_float(uint(c2da_mem[216612 + 1 * 4]) | uint(c2da_mem[216612 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[216612 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[216612 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh24 : uint = float_bits_to_uint(c2da_fresh23)
        c2da_mem[216624 + 0 * 4] = uint8(c2da_fresh24)
        c2da_mem[216624 + 0 * 4 + 1] = uint8(c2da_fresh24 >> 0x8)
        c2da_mem[216624 + 0 * 4 + 2] = uint8(c2da_fresh24 >> 0x10)
        c2da_mem[216624 + 0 * 4 + 3] = uint8(c2da_fresh24 >> 0x18)
        let c2da_fresh25 : float = uint_bits_to_float(uint(c2da_mem[216612 + 0 * 4]) | uint(c2da_mem[216612 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[216612 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[216612 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh26 : uint = float_bits_to_uint(c2da_fresh25)
        c2da_mem[216624 + 1 * 4] = uint8(c2da_fresh26)
        c2da_mem[216624 + 1 * 4 + 1] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[216624 + 1 * 4 + 2] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[216624 + 1 * 4 + 3] = uint8(c2da_fresh26 >> 0x18)
        let c2da_fresh27 : float = 0.0
        let c2da_fresh28 : uint = float_bits_to_uint(c2da_fresh27)
        c2da_mem[216624 + 2 * 4] = uint8(c2da_fresh28)
        c2da_mem[216624 + 2 * 4 + 1] = uint8(c2da_fresh28 >> 0x8)
        c2da_mem[216624 + 2 * 4 + 2] = uint8(c2da_fresh28 >> 0x10)
        c2da_mem[216624 + 2 * 4 + 3] = uint8(c2da_fresh28 >> 0x18)
    } elif (int(uint(c2da_mem[psprite]) | uint(c2da_mem[psprite + 1]) << 0x8 | uint(c2da_mem[psprite + 2]) << 0x10 | uint(c2da_mem[psprite + 3]) << 0x18) == 2) {
        i = 0
        for (c2da_i in range(i, 3)) {
            let c2da_fresh29 : float = uint_bits_to_float(uint(c2da_mem[244160 + c2da_i * 4]) | uint(c2da_mem[244160 + c2da_i * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + c2da_i * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + c2da_i * 4 + 3]) << 0x18)
            let c2da_fresh30 : uint = float_bits_to_uint(c2da_fresh29)
            c2da_mem[216600 + c2da_i * 4] = uint8(c2da_fresh30)
            c2da_mem[216600 + c2da_i * 4 + 1] = uint8(c2da_fresh30 >> 0x8)
            c2da_mem[216600 + c2da_i * 4 + 2] = uint8(c2da_fresh30 >> 0x10)
            c2da_mem[216600 + c2da_i * 4 + 3] = uint8(c2da_fresh30 >> 0x18)
            let c2da_fresh31 : float = uint_bits_to_float(uint(c2da_mem[244144 + c2da_i * 4]) | uint(c2da_mem[244144 + c2da_i * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + c2da_i * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + c2da_i * 4 + 3]) << 0x18)
            let c2da_fresh32 : uint = float_bits_to_uint(c2da_fresh31)
            c2da_mem[216612 + c2da_i * 4] = uint8(c2da_fresh32)
            c2da_mem[216612 + c2da_i * 4 + 1] = uint8(c2da_fresh32 >> 0x8)
            c2da_mem[216612 + c2da_i * 4 + 2] = uint8(c2da_fresh32 >> 0x10)
            c2da_mem[216612 + c2da_i * 4 + 3] = uint8(c2da_fresh32 >> 0x18)
            let c2da_fresh33 : float = uint_bits_to_float(uint(c2da_mem[244128 + c2da_i * 4]) | uint(c2da_mem[244128 + c2da_i * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + c2da_i * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + c2da_i * 4 + 3]) << 0x18)
            let c2da_fresh34 : uint = float_bits_to_uint(c2da_fresh33)
            c2da_mem[216624 + c2da_i * 4] = uint8(c2da_fresh34)
            c2da_mem[216624 + c2da_i * 4 + 1] = uint8(c2da_fresh34 >> 0x8)
            c2da_mem[216624 + c2da_i * 4 + 2] = uint8(c2da_fresh34 >> 0x10)
            c2da_mem[216624 + c2da_i * 4 + 3] = uint8(c2da_fresh34 >> 0x18)
        }
    } elif (int(uint(c2da_mem[psprite]) | uint(c2da_mem[psprite + 1]) << 0x8 | uint(c2da_mem[psprite + 2]) << 0x10 | uint(c2da_mem[psprite + 3]) << 0x18) == 0) {
        dot = uint_bits_to_float(uint(c2da_mem[244128 + 2 * 4]) | uint(c2da_mem[244128 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 2 * 4 + 3]) << 0x18)
        if (double(dot) > 0.999848lf || double(dot) < -0.999848lf) {
            return
        }
        let c2da_fresh35 : float = 0.0
        let c2da_fresh36 : uint = float_bits_to_uint(c2da_fresh35)
        c2da_mem[216600 + 0 * 4] = uint8(c2da_fresh36)
        c2da_mem[216600 + 0 * 4 + 1] = uint8(c2da_fresh36 >> 0x8)
        c2da_mem[216600 + 0 * 4 + 2] = uint8(c2da_fresh36 >> 0x10)
        c2da_mem[216600 + 0 * 4 + 3] = uint8(c2da_fresh36 >> 0x18)
        let c2da_fresh37 : float = 0.0
        let c2da_fresh38 : uint = float_bits_to_uint(c2da_fresh37)
        c2da_mem[216600 + 1 * 4] = uint8(c2da_fresh38)
        c2da_mem[216600 + 1 * 4 + 1] = uint8(c2da_fresh38 >> 0x8)
        c2da_mem[216600 + 1 * 4 + 2] = uint8(c2da_fresh38 >> 0x10)
        c2da_mem[216600 + 1 * 4 + 3] = uint8(c2da_fresh38 >> 0x18)
        let c2da_fresh39 : float = 1.0
        let c2da_fresh40 : uint = float_bits_to_uint(c2da_fresh39)
        c2da_mem[216600 + 2 * 4] = uint8(c2da_fresh40)
        c2da_mem[216600 + 2 * 4 + 1] = uint8(c2da_fresh40 >> 0x8)
        c2da_mem[216600 + 2 * 4 + 2] = uint8(c2da_fresh40 >> 0x10)
        c2da_mem[216600 + 2 * 4 + 3] = uint8(c2da_fresh40 >> 0x18)
        let c2da_fresh41 : float = uint_bits_to_float(uint(c2da_mem[244128 + 1 * 4]) | uint(c2da_mem[244128 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh42 : uint = float_bits_to_uint(c2da_fresh41)
        c2da_mem[216612 + 0 * 4] = uint8(c2da_fresh42)
        c2da_mem[216612 + 0 * 4 + 1] = uint8(c2da_fresh42 >> 0x8)
        c2da_mem[216612 + 0 * 4 + 2] = uint8(c2da_fresh42 >> 0x10)
        c2da_mem[216612 + 0 * 4 + 3] = uint8(c2da_fresh42 >> 0x18)
        let c2da_fresh43 : float = -uint_bits_to_float(uint(c2da_mem[244128 + 0 * 4]) | uint(c2da_mem[244128 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh44 : uint = float_bits_to_uint(c2da_fresh43)
        c2da_mem[216612 + 1 * 4] = uint8(c2da_fresh44)
        c2da_mem[216612 + 1 * 4 + 1] = uint8(c2da_fresh44 >> 0x8)
        c2da_mem[216612 + 1 * 4 + 2] = uint8(c2da_fresh44 >> 0x10)
        c2da_mem[216612 + 1 * 4 + 3] = uint8(c2da_fresh44 >> 0x18)
        let c2da_fresh45 : float = 0.0
        let c2da_fresh46 : uint = float_bits_to_uint(c2da_fresh45)
        c2da_mem[216612 + 2 * 4] = uint8(c2da_fresh46)
        c2da_mem[216612 + 2 * 4 + 1] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[216612 + 2 * 4 + 2] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[216612 + 2 * 4 + 3] = uint8(c2da_fresh46 >> 0x18)
        VectorNormalize(216612)
        let c2da_fresh47 : float = -uint_bits_to_float(uint(c2da_mem[216612 + 1 * 4]) | uint(c2da_mem[216612 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[216612 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[216612 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh48 : uint = float_bits_to_uint(c2da_fresh47)
        c2da_mem[216624 + 0 * 4] = uint8(c2da_fresh48)
        c2da_mem[216624 + 0 * 4 + 1] = uint8(c2da_fresh48 >> 0x8)
        c2da_mem[216624 + 0 * 4 + 2] = uint8(c2da_fresh48 >> 0x10)
        c2da_mem[216624 + 0 * 4 + 3] = uint8(c2da_fresh48 >> 0x18)
        let c2da_fresh49 : float = uint_bits_to_float(uint(c2da_mem[216612 + 0 * 4]) | uint(c2da_mem[216612 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[216612 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[216612 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh50 : uint = float_bits_to_uint(c2da_fresh49)
        c2da_mem[216624 + 1 * 4] = uint8(c2da_fresh50)
        c2da_mem[216624 + 1 * 4 + 1] = uint8(c2da_fresh50 >> 0x8)
        c2da_mem[216624 + 1 * 4 + 2] = uint8(c2da_fresh50 >> 0x10)
        c2da_mem[216624 + 1 * 4 + 3] = uint8(c2da_fresh50 >> 0x18)
        let c2da_fresh51 : float = 0.0
        let c2da_fresh52 : uint = float_bits_to_uint(c2da_fresh51)
        c2da_mem[216624 + 2 * 4] = uint8(c2da_fresh52)
        c2da_mem[216624 + 2 * 4 + 1] = uint8(c2da_fresh52 >> 0x8)
        c2da_mem[216624 + 2 * 4 + 2] = uint8(c2da_fresh52 >> 0x10)
        c2da_mem[216624 + 2 * 4 + 3] = uint8(c2da_fresh52 >> 0x18)
    } elif (int(uint(c2da_mem[psprite]) | uint(c2da_mem[psprite + 1]) << 0x8 | uint(c2da_mem[psprite + 2]) << 0x10 | uint(c2da_mem[psprite + 3]) << 0x18) == 3) {
        AngleVectors(currententity + 124, 216624, 216612, 216600)
    } elif (int(uint(c2da_mem[psprite]) | uint(c2da_mem[psprite + 1]) << 0x8 | uint(c2da_mem[psprite + 2]) << 0x10 | uint(c2da_mem[psprite + 3]) << 0x18) == 4) {
        angle = float(double(uint_bits_to_float(uint(c2da_mem[currententity + 124 + 2 * 4]) | uint(c2da_mem[currententity + 124 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 124 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 124 + 2 * 4 + 3]) << 0x18)) * (3.141592653589793lf * 2.0lf / 360.0lf))
        sr = float(sin(double(angle)))
        cr = float(cos(double(angle)))
        i = 0
        for (c2da_i_0 in range(i, 3)) {
            let c2da_fresh53 : float = uint_bits_to_float(uint(c2da_mem[244128 + c2da_i_0 * 4]) | uint(c2da_mem[244128 + c2da_i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + c2da_i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + c2da_i_0 * 4 + 3]) << 0x18)
            let c2da_fresh54 : uint = float_bits_to_uint(c2da_fresh53)
            c2da_mem[216624 + c2da_i_0 * 4] = uint8(c2da_fresh54)
            c2da_mem[216624 + c2da_i_0 * 4 + 1] = uint8(c2da_fresh54 >> 0x8)
            c2da_mem[216624 + c2da_i_0 * 4 + 2] = uint8(c2da_fresh54 >> 0x10)
            c2da_mem[216624 + c2da_i_0 * 4 + 3] = uint8(c2da_fresh54 >> 0x18)
            let c2da_fresh55 : float = uint_bits_to_float(uint(c2da_mem[244144 + c2da_i_0 * 4]) | uint(c2da_mem[244144 + c2da_i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + c2da_i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + c2da_i_0 * 4 + 3]) << 0x18) * cr + uint_bits_to_float(uint(c2da_mem[244160 + c2da_i_0 * 4]) | uint(c2da_mem[244160 + c2da_i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + c2da_i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + c2da_i_0 * 4 + 3]) << 0x18) * sr
            let c2da_fresh56 : uint = float_bits_to_uint(c2da_fresh55)
            c2da_mem[216612 + c2da_i_0 * 4] = uint8(c2da_fresh56)
            c2da_mem[216612 + c2da_i_0 * 4 + 1] = uint8(c2da_fresh56 >> 0x8)
            c2da_mem[216612 + c2da_i_0 * 4 + 2] = uint8(c2da_fresh56 >> 0x10)
            c2da_mem[216612 + c2da_i_0 * 4 + 3] = uint8(c2da_fresh56 >> 0x18)
            let c2da_fresh57 : float = uint_bits_to_float(uint(c2da_mem[244144 + c2da_i_0 * 4]) | uint(c2da_mem[244144 + c2da_i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[244144 + c2da_i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[244144 + c2da_i_0 * 4 + 3]) << 0x18) * -sr + uint_bits_to_float(uint(c2da_mem[244160 + c2da_i_0 * 4]) | uint(c2da_mem[244160 + c2da_i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + c2da_i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + c2da_i_0 * 4 + 3]) << 0x18) * cr
            let c2da_fresh58 : uint = float_bits_to_uint(c2da_fresh57)
            c2da_mem[216600 + c2da_i_0 * 4] = uint8(c2da_fresh58)
            c2da_mem[216600 + c2da_i_0 * 4 + 1] = uint8(c2da_fresh58 >> 0x8)
            c2da_mem[216600 + c2da_i_0 * 4 + 2] = uint8(c2da_fresh58 >> 0x10)
            c2da_mem[216600 + c2da_i_0 * 4 + 3] = uint8(c2da_fresh58 >> 0x18)
        }
    } else {
        Sys_Error(734432, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[psprite]) | uint(c2da_mem[psprite + 1]) << 0x8 | uint(c2da_mem[psprite + 2]) << 0x10 | uint(c2da_mem[psprite + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    }
    R_RotateSprite(uint_bits_to_float(uint(c2da_mem[psprite + 16]) | uint(c2da_mem[psprite + 17]) << 0x8 | uint(c2da_mem[psprite + 18]) << 0x10 | uint(c2da_mem[psprite + 19]) << 0x18))
    R_SetupAndDrawSprite()
    return
}
[sideeffects]
def private R_SetupAndDrawSprite_c2da_frame(c2da_fp : int) {
    var i_0 : int
    var nump : int
    var pv : int
    var pverts : int
    var pout : int
    if (uint_bits_to_float(uint(c2da_mem[216624 + 0 * 4]) | uint(c2da_mem[216624 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[216624 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[216624 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[216624 + 1 * 4]) | uint(c2da_mem[216624 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[216624 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[216624 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[216624 + 2 * 4]) | uint(c2da_mem[216624 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[216624 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[216624 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18) >= 0.0) {
        return
    }
    let c2da_fresh60 : int = int(uint(c2da_mem[216592]) | uint(c2da_mem[216593]) << 0x8 | uint(c2da_mem[216594]) << 0x10 | uint(c2da_mem[216595]) << 0x18) + 28
    VectorScale(216612, uint_bits_to_float(uint(c2da_mem[c2da_fresh60]) | uint(c2da_mem[c2da_fresh60 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh60 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh60 + 3]) << 0x18), c2da_fp)
    let c2da_fresh61 : int = int(uint(c2da_mem[216592]) | uint(c2da_mem[216593]) << 0x8 | uint(c2da_mem[216594]) << 0x10 | uint(c2da_mem[216595]) << 0x18) + 16
    VectorScale(216600, uint_bits_to_float(uint(c2da_mem[c2da_fresh61]) | uint(c2da_mem[c2da_fresh61 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh61 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh61 + 3]) << 0x18), c2da_fp + 16)
    let c2da_fresh62 : int = int(uint(c2da_mem[216592]) | uint(c2da_mem[216593]) << 0x8 | uint(c2da_mem[216594]) << 0x10 | uint(c2da_mem[216595]) << 0x18) + 24
    VectorScale(216612, uint_bits_to_float(uint(c2da_mem[c2da_fresh62]) | uint(c2da_mem[c2da_fresh62 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh62 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh62 + 3]) << 0x18), c2da_fp + 32)
    let c2da_fresh63 : int = int(uint(c2da_mem[216592]) | uint(c2da_mem[216593]) << 0x8 | uint(c2da_mem[216594]) << 0x10 | uint(c2da_mem[216595]) << 0x18) + 20
    VectorScale(216600, uint_bits_to_float(uint(c2da_mem[c2da_fresh63]) | uint(c2da_mem[c2da_fresh63 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh63 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh63 + 3]) << 0x18), c2da_fp + 48)
    pverts = 733632 + 0 * 400
    let c2da_fresh64 : float = r_entorigin[0] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 0 * 4]) | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh65 : uint = float_bits_to_uint(c2da_fresh64)
    c2da_mem[pverts + 0 * 20 + 0 * 4] = uint8(c2da_fresh65)
    c2da_mem[pverts + 0 * 20 + 0 * 4 + 1] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[pverts + 0 * 20 + 0 * 4 + 2] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[pverts + 0 * 20 + 0 * 4 + 3] = uint8(c2da_fresh65 >> 0x18)
    let c2da_fresh66 : float = r_entorigin[1] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 1 * 4]) | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
    c2da_mem[pverts + 0 * 20 + 1 * 4] = uint8(c2da_fresh67)
    c2da_mem[pverts + 0 * 20 + 1 * 4 + 1] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[pverts + 0 * 20 + 1 * 4 + 2] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[pverts + 0 * 20 + 1 * 4 + 3] = uint8(c2da_fresh67 >> 0x18)
    let c2da_fresh68 : float = r_entorigin[2] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 2 * 4]) | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh69 : uint = float_bits_to_uint(c2da_fresh68)
    c2da_mem[pverts + 0 * 20 + 2 * 4] = uint8(c2da_fresh69)
    c2da_mem[pverts + 0 * 20 + 2 * 4 + 1] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[pverts + 0 * 20 + 2 * 4 + 2] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[pverts + 0 * 20 + 2 * 4 + 3] = uint8(c2da_fresh69 >> 0x18)
    let c2da_fresh70 : float = 0.0
    let c2da_fresh71 : uint = float_bits_to_uint(c2da_fresh70)
    c2da_mem[pverts + 0 * 20 + 3 * 4] = uint8(c2da_fresh71)
    c2da_mem[pverts + 0 * 20 + 3 * 4 + 1] = uint8(c2da_fresh71 >> 0x8)
    c2da_mem[pverts + 0 * 20 + 3 * 4 + 2] = uint8(c2da_fresh71 >> 0x10)
    c2da_mem[pverts + 0 * 20 + 3 * 4 + 3] = uint8(c2da_fresh71 >> 0x18)
    let c2da_fresh72 : float = 0.0
    let c2da_fresh73 : uint = float_bits_to_uint(c2da_fresh72)
    c2da_mem[pverts + 0 * 20 + 4 * 4] = uint8(c2da_fresh73)
    c2da_mem[pverts + 0 * 20 + 4 * 4 + 1] = uint8(c2da_fresh73 >> 0x8)
    c2da_mem[pverts + 0 * 20 + 4 * 4 + 2] = uint8(c2da_fresh73 >> 0x10)
    c2da_mem[pverts + 0 * 20 + 4 * 4 + 3] = uint8(c2da_fresh73 >> 0x18)
    let c2da_fresh74 : float = r_entorigin[0] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 0 * 4]) | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
    let c2da_fresh75 : uint = float_bits_to_uint(c2da_fresh74)
    c2da_mem[pverts + 1 * 20 + 0 * 4] = uint8(c2da_fresh75)
    c2da_mem[pverts + 1 * 20 + 0 * 4 + 1] = uint8(c2da_fresh75 >> 0x8)
    c2da_mem[pverts + 1 * 20 + 0 * 4 + 2] = uint8(c2da_fresh75 >> 0x10)
    c2da_mem[pverts + 1 * 20 + 0 * 4 + 3] = uint8(c2da_fresh75 >> 0x18)
    let c2da_fresh76 : float = r_entorigin[1] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 1 * 4]) | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
    let c2da_fresh77 : uint = float_bits_to_uint(c2da_fresh76)
    c2da_mem[pverts + 1 * 20 + 1 * 4] = uint8(c2da_fresh77)
    c2da_mem[pverts + 1 * 20 + 1 * 4 + 1] = uint8(c2da_fresh77 >> 0x8)
    c2da_mem[pverts + 1 * 20 + 1 * 4 + 2] = uint8(c2da_fresh77 >> 0x10)
    c2da_mem[pverts + 1 * 20 + 1 * 4 + 3] = uint8(c2da_fresh77 >> 0x18)
    let c2da_fresh78 : float = r_entorigin[2] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
    let c2da_fresh79 : uint = float_bits_to_uint(c2da_fresh78)
    c2da_mem[pverts + 1 * 20 + 2 * 4] = uint8(c2da_fresh79)
    c2da_mem[pverts + 1 * 20 + 2 * 4 + 1] = uint8(c2da_fresh79 >> 0x8)
    c2da_mem[pverts + 1 * 20 + 2 * 4 + 2] = uint8(c2da_fresh79 >> 0x10)
    c2da_mem[pverts + 1 * 20 + 2 * 4 + 3] = uint8(c2da_fresh79 >> 0x18)
    let c2da_fresh80 : float = float(sprite_width)
    let c2da_fresh81 : uint = float_bits_to_uint(c2da_fresh80)
    c2da_mem[pverts + 1 * 20 + 3 * 4] = uint8(c2da_fresh81)
    c2da_mem[pverts + 1 * 20 + 3 * 4 + 1] = uint8(c2da_fresh81 >> 0x8)
    c2da_mem[pverts + 1 * 20 + 3 * 4 + 2] = uint8(c2da_fresh81 >> 0x10)
    c2da_mem[pverts + 1 * 20 + 3 * 4 + 3] = uint8(c2da_fresh81 >> 0x18)
    let c2da_fresh82 : float = 0.0
    let c2da_fresh83 : uint = float_bits_to_uint(c2da_fresh82)
    c2da_mem[pverts + 1 * 20 + 4 * 4] = uint8(c2da_fresh83)
    c2da_mem[pverts + 1 * 20 + 4 * 4 + 1] = uint8(c2da_fresh83 >> 0x8)
    c2da_mem[pverts + 1 * 20 + 4 * 4 + 2] = uint8(c2da_fresh83 >> 0x10)
    c2da_mem[pverts + 1 * 20 + 4 * 4 + 3] = uint8(c2da_fresh83 >> 0x18)
    let c2da_fresh84 : float = r_entorigin[0] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 0 * 4]) | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
    let c2da_fresh85 : uint = float_bits_to_uint(c2da_fresh84)
    c2da_mem[pverts + 2 * 20 + 0 * 4] = uint8(c2da_fresh85)
    c2da_mem[pverts + 2 * 20 + 0 * 4 + 1] = uint8(c2da_fresh85 >> 0x8)
    c2da_mem[pverts + 2 * 20 + 0 * 4 + 2] = uint8(c2da_fresh85 >> 0x10)
    c2da_mem[pverts + 2 * 20 + 0 * 4 + 3] = uint8(c2da_fresh85 >> 0x18)
    let c2da_fresh86 : float = r_entorigin[1] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 1 * 4]) | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
    let c2da_fresh87 : uint = float_bits_to_uint(c2da_fresh86)
    c2da_mem[pverts + 2 * 20 + 1 * 4] = uint8(c2da_fresh87)
    c2da_mem[pverts + 2 * 20 + 1 * 4 + 1] = uint8(c2da_fresh87 >> 0x8)
    c2da_mem[pverts + 2 * 20 + 1 * 4 + 2] = uint8(c2da_fresh87 >> 0x10)
    c2da_mem[pverts + 2 * 20 + 1 * 4 + 3] = uint8(c2da_fresh87 >> 0x18)
    let c2da_fresh88 : float = r_entorigin[2] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 2 * 4]) | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
    let c2da_fresh89 : uint = float_bits_to_uint(c2da_fresh88)
    c2da_mem[pverts + 2 * 20 + 2 * 4] = uint8(c2da_fresh89)
    c2da_mem[pverts + 2 * 20 + 2 * 4 + 1] = uint8(c2da_fresh89 >> 0x8)
    c2da_mem[pverts + 2 * 20 + 2 * 4 + 2] = uint8(c2da_fresh89 >> 0x10)
    c2da_mem[pverts + 2 * 20 + 2 * 4 + 3] = uint8(c2da_fresh89 >> 0x18)
    let c2da_fresh90 : float = float(sprite_width)
    let c2da_fresh91 : uint = float_bits_to_uint(c2da_fresh90)
    c2da_mem[pverts + 2 * 20 + 3 * 4] = uint8(c2da_fresh91)
    c2da_mem[pverts + 2 * 20 + 3 * 4 + 1] = uint8(c2da_fresh91 >> 0x8)
    c2da_mem[pverts + 2 * 20 + 3 * 4 + 2] = uint8(c2da_fresh91 >> 0x10)
    c2da_mem[pverts + 2 * 20 + 3 * 4 + 3] = uint8(c2da_fresh91 >> 0x18)
    let c2da_fresh92 : float = float(sprite_height_0)
    let c2da_fresh93 : uint = float_bits_to_uint(c2da_fresh92)
    c2da_mem[pverts + 2 * 20 + 4 * 4] = uint8(c2da_fresh93)
    c2da_mem[pverts + 2 * 20 + 4 * 4 + 1] = uint8(c2da_fresh93 >> 0x8)
    c2da_mem[pverts + 2 * 20 + 4 * 4 + 2] = uint8(c2da_fresh93 >> 0x10)
    c2da_mem[pverts + 2 * 20 + 4 * 4 + 3] = uint8(c2da_fresh93 >> 0x18)
    let c2da_fresh94 : float = r_entorigin[0] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 0 * 4]) | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 0 * 4]) | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh95 : uint = float_bits_to_uint(c2da_fresh94)
    c2da_mem[pverts + 3 * 20 + 0 * 4] = uint8(c2da_fresh95)
    c2da_mem[pverts + 3 * 20 + 0 * 4 + 1] = uint8(c2da_fresh95 >> 0x8)
    c2da_mem[pverts + 3 * 20 + 0 * 4 + 2] = uint8(c2da_fresh95 >> 0x10)
    c2da_mem[pverts + 3 * 20 + 0 * 4 + 3] = uint8(c2da_fresh95 >> 0x18)
    let c2da_fresh96 : float = r_entorigin[1] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 1 * 4]) | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 1 * 4]) | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh97 : uint = float_bits_to_uint(c2da_fresh96)
    c2da_mem[pverts + 3 * 20 + 1 * 4] = uint8(c2da_fresh97)
    c2da_mem[pverts + 3 * 20 + 1 * 4 + 1] = uint8(c2da_fresh97 >> 0x8)
    c2da_mem[pverts + 3 * 20 + 1 * 4 + 2] = uint8(c2da_fresh97 >> 0x10)
    c2da_mem[pverts + 3 * 20 + 1 * 4 + 3] = uint8(c2da_fresh97 >> 0x18)
    let c2da_fresh98 : float = r_entorigin[2] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 48 + 2 * 4]) | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 48 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 32 + 2 * 4]) | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh99 : uint = float_bits_to_uint(c2da_fresh98)
    c2da_mem[pverts + 3 * 20 + 2 * 4] = uint8(c2da_fresh99)
    c2da_mem[pverts + 3 * 20 + 2 * 4 + 1] = uint8(c2da_fresh99 >> 0x8)
    c2da_mem[pverts + 3 * 20 + 2 * 4 + 2] = uint8(c2da_fresh99 >> 0x10)
    c2da_mem[pverts + 3 * 20 + 2 * 4 + 3] = uint8(c2da_fresh99 >> 0x18)
    let c2da_fresh100 : float = 0.0
    let c2da_fresh101 : uint = float_bits_to_uint(c2da_fresh100)
    c2da_mem[pverts + 3 * 20 + 3 * 4] = uint8(c2da_fresh101)
    c2da_mem[pverts + 3 * 20 + 3 * 4 + 1] = uint8(c2da_fresh101 >> 0x8)
    c2da_mem[pverts + 3 * 20 + 3 * 4 + 2] = uint8(c2da_fresh101 >> 0x10)
    c2da_mem[pverts + 3 * 20 + 3 * 4 + 3] = uint8(c2da_fresh101 >> 0x18)
    let c2da_fresh102 : float = float(sprite_height_0)
    let c2da_fresh103 : uint = float_bits_to_uint(c2da_fresh102)
    c2da_mem[pverts + 3 * 20 + 4 * 4] = uint8(c2da_fresh103)
    c2da_mem[pverts + 3 * 20 + 4 * 4 + 1] = uint8(c2da_fresh103 >> 0x8)
    c2da_mem[pverts + 3 * 20 + 4 * 4 + 2] = uint8(c2da_fresh103 >> 0x10)
    c2da_mem[pverts + 3 * 20 + 4 * 4 + 3] = uint8(c2da_fresh103 >> 0x18)
    nump = 4
    clip_current = 0
    i_0 = 0
    while (i_0 < 4) {
        nump = R_ClipSpriteFace(nump, 391440 + i_0 * 32)
        if (nump < 3) {
            return
        }
        if (nump >= 16 + 4) {
            Sys_Error(734465, [])
        }
        i_0++
    }
    pv = 733632 + clip_current * 400 + 0 * 20 + 0 * 4
    let c2da_fresh104 : float = -999999.0
    let c2da_fresh105 : uint = float_bits_to_uint(c2da_fresh104)
    c2da_mem[216636] = uint8(c2da_fresh105)
    c2da_mem[216637] = uint8(c2da_fresh105 >> 0x8)
    c2da_mem[216638] = uint8(c2da_fresh105 >> 0x10)
    c2da_mem[216639] = uint8(c2da_fresh105 >> 0x18)
    i_0 = 0
    for (c2da_i_0_0 in range(i_0, nump)) {
        let c2da_fresh106 : float = uint_bits_to_float(uint(c2da_mem[pv + 0 * 4]) | uint(c2da_mem[pv + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pv + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pv + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[244112 + 0 * 4]) | uint(c2da_mem[244112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh107 : uint = float_bits_to_uint(c2da_fresh106)
        c2da_mem[c2da_fp + 64 + 0 * 4] = uint8(c2da_fresh107)
        c2da_mem[c2da_fp + 64 + 0 * 4 + 1] = uint8(c2da_fresh107 >> 0x8)
        c2da_mem[c2da_fp + 64 + 0 * 4 + 2] = uint8(c2da_fresh107 >> 0x10)
        c2da_mem[c2da_fp + 64 + 0 * 4 + 3] = uint8(c2da_fresh107 >> 0x18)
        let c2da_fresh108 : float = uint_bits_to_float(uint(c2da_mem[pv + 1 * 4]) | uint(c2da_mem[pv + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pv + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pv + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[244112 + 1 * 4]) | uint(c2da_mem[244112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh109 : uint = float_bits_to_uint(c2da_fresh108)
        c2da_mem[c2da_fp + 64 + 1 * 4] = uint8(c2da_fresh109)
        c2da_mem[c2da_fp + 64 + 1 * 4 + 1] = uint8(c2da_fresh109 >> 0x8)
        c2da_mem[c2da_fp + 64 + 1 * 4 + 2] = uint8(c2da_fresh109 >> 0x10)
        c2da_mem[c2da_fp + 64 + 1 * 4 + 3] = uint8(c2da_fresh109 >> 0x18)
        let c2da_fresh110 : float = uint_bits_to_float(uint(c2da_mem[pv + 2 * 4]) | uint(c2da_mem[pv + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pv + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pv + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[244112 + 2 * 4]) | uint(c2da_mem[244112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh111 : uint = float_bits_to_uint(c2da_fresh110)
        c2da_mem[c2da_fp + 64 + 2 * 4] = uint8(c2da_fresh111)
        c2da_mem[c2da_fp + 64 + 2 * 4 + 1] = uint8(c2da_fresh111 >> 0x8)
        c2da_mem[c2da_fp + 64 + 2 * 4 + 2] = uint8(c2da_fresh111 >> 0x10)
        c2da_mem[c2da_fp + 64 + 2 * 4 + 3] = uint8(c2da_fresh111 >> 0x18)
        TransformVector(c2da_fp + 64, c2da_fp + 80)
        if (double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 80 + 2 * 4]) | uint(c2da_mem[c2da_fp + 80 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 80 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 80 + 2 * 4 + 3]) << 0x18)) < 0.01lf) {
            let c2da_fresh112 : float = float(0.01lf)
            let c2da_fresh113 : uint = float_bits_to_uint(c2da_fresh112)
            c2da_mem[c2da_fp + 80 + 2 * 4] = uint8(c2da_fresh113)
            c2da_mem[c2da_fp + 80 + 2 * 4 + 1] = uint8(c2da_fresh113 >> 0x8)
            c2da_mem[c2da_fp + 80 + 2 * 4 + 2] = uint8(c2da_fresh113 >> 0x10)
            c2da_mem[c2da_fp + 80 + 2 * 4 + 3] = uint8(c2da_fresh113 >> 0x18)
        }
        pout = c2da_fp + 96 + c2da_i_0_0 * 20
        let c2da_fresh114 : float = float(1.0lf / double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 80 + 2 * 4]) | uint(c2da_mem[c2da_fp + 80 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 80 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 80 + 2 * 4 + 3]) << 0x18)))
        let c2da_fresh115 : uint = float_bits_to_uint(c2da_fresh114)
        c2da_mem[pout + 16] = uint8(c2da_fresh115)
        c2da_mem[pout + 17] = uint8(c2da_fresh115 >> 0x8)
        c2da_mem[pout + 18] = uint8(c2da_fresh115 >> 0x10)
        c2da_mem[pout + 19] = uint8(c2da_fresh115 >> 0x18)
        if (c2da_fresh114 > uint_bits_to_float(uint(c2da_mem[216636]) | uint(c2da_mem[216637]) << 0x8 | uint(c2da_mem[216638]) << 0x10 | uint(c2da_mem[216639]) << 0x18)) {
            let c2da_fresh116 : float = c2da_fresh114
            let c2da_fresh117 : uint = float_bits_to_uint(c2da_fresh116)
            c2da_mem[216636] = uint8(c2da_fresh117)
            c2da_mem[216637] = uint8(c2da_fresh117 >> 0x8)
            c2da_mem[216638] = uint8(c2da_fresh117 >> 0x10)
            c2da_mem[216639] = uint8(c2da_fresh117 >> 0x18)
        }
        let c2da_fresh118 : float = uint_bits_to_float(uint(c2da_mem[pv + 3 * 4]) | uint(c2da_mem[pv + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[pv + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[pv + 3 * 4 + 3]) << 0x18)
        let c2da_fresh119 : uint = float_bits_to_uint(c2da_fresh118)
        c2da_mem[pout + 8] = uint8(c2da_fresh119)
        c2da_mem[pout + 9] = uint8(c2da_fresh119 >> 0x8)
        c2da_mem[pout + 10] = uint8(c2da_fresh119 >> 0x10)
        c2da_mem[pout + 11] = uint8(c2da_fresh119 >> 0x18)
        let c2da_fresh120 : float = uint_bits_to_float(uint(c2da_mem[pv + 4 * 4]) | uint(c2da_mem[pv + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pv + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pv + 4 * 4 + 3]) << 0x18)
        let c2da_fresh121 : uint = float_bits_to_uint(c2da_fresh120)
        c2da_mem[pout + 12] = uint8(c2da_fresh121)
        c2da_mem[pout + 13] = uint8(c2da_fresh121 >> 0x8)
        c2da_mem[pout + 14] = uint8(c2da_fresh121 >> 0x10)
        c2da_mem[pout + 15] = uint8(c2da_fresh121 >> 0x18)
        let c2da_fresh129 : float = uint_bits_to_float(uint(c2da_mem[pout + 16]) | uint(c2da_mem[pout + 17]) << 0x8 | uint(c2da_mem[pout + 18]) << 0x10 | uint(c2da_mem[pout + 19]) << 0x18)
        let c2da_fresh122 : float = xcenter + xscale * c2da_fresh129 * uint_bits_to_float(uint(c2da_mem[c2da_fp + 80 + 0 * 4]) | uint(c2da_mem[c2da_fp + 80 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 80 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 80 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh123 : uint = float_bits_to_uint(c2da_fresh122)
        c2da_mem[pout] = uint8(c2da_fresh123)
        c2da_mem[pout + 1] = uint8(c2da_fresh123 >> 0x8)
        c2da_mem[pout + 2] = uint8(c2da_fresh123 >> 0x10)
        c2da_mem[pout + 3] = uint8(c2da_fresh123 >> 0x18)
        let c2da_fresh124 : float = ycenter - yscale * c2da_fresh129 * uint_bits_to_float(uint(c2da_mem[c2da_fp + 80 + 1 * 4]) | uint(c2da_mem[c2da_fp + 80 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 80 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 80 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh125 : uint = float_bits_to_uint(c2da_fresh124)
        c2da_mem[pout + 4] = uint8(c2da_fresh125)
        c2da_mem[pout + 5] = uint8(c2da_fresh125 >> 0x8)
        c2da_mem[pout + 6] = uint8(c2da_fresh125 >> 0x10)
        c2da_mem[pout + 7] = uint8(c2da_fresh125 >> 0x18)
        pv += int(20ul / 4ul) * 4
    }
    let c2da_fresh126 : uint = uint(nump)
    c2da_mem[216576] = uint8(c2da_fresh126)
    c2da_mem[216577] = uint8(c2da_fresh126 >> 0x8)
    c2da_mem[216578] = uint8(c2da_fresh126 >> 0x10)
    c2da_mem[216579] = uint8(c2da_fresh126 >> 0x18)
    let c2da_fresh127 : int = c2da_fp + 96
    let c2da_fresh128 : uint = uint(c2da_fresh127)
    c2da_mem[216584] = uint8(c2da_fresh128)
    c2da_mem[216585] = uint8(c2da_fresh128 >> 0x8)
    c2da_mem[216586] = uint8(c2da_fresh128 >> 0x10)
    c2da_mem[216587] = uint8(c2da_fresh128 >> 0x18)
    c2da_mem[216588] = 0u8
    c2da_mem[216589] = 0u8
    c2da_mem[216590] = 0u8
    c2da_mem[216591] = 0u8
    D_DrawSprite()
    return
}
[sideeffects]
def private R_RotateSprite_c2da_frame(var beamlength_0 : float; c2da_fp : int) {
    if (double(beamlength_0) == 0.0lf) {
        return
    }
    VectorScale(216624, -beamlength_0, c2da_fp)
    r_entorigin[0] = r_entorigin[0] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
    r_entorigin[1] = r_entorigin[1] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
    r_entorigin[2] = r_entorigin[2] + uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
    let c2da_fresh145 : float = uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
    let c2da_fresh146 : uint = float_bits_to_uint(c2da_fresh145)
    c2da_mem[204240 + 0 * 4] = uint8(c2da_fresh146)
    c2da_mem[204240 + 0 * 4 + 1] = uint8(c2da_fresh146 >> 0x8)
    c2da_mem[204240 + 0 * 4 + 2] = uint8(c2da_fresh146 >> 0x10)
    c2da_mem[204240 + 0 * 4 + 3] = uint8(c2da_fresh146 >> 0x18)
    let c2da_fresh147 : float = uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
    let c2da_fresh148 : uint = float_bits_to_uint(c2da_fresh147)
    c2da_mem[204240 + 1 * 4] = uint8(c2da_fresh148)
    c2da_mem[204240 + 1 * 4 + 1] = uint8(c2da_fresh148 >> 0x8)
    c2da_mem[204240 + 1 * 4 + 2] = uint8(c2da_fresh148 >> 0x10)
    c2da_mem[204240 + 1 * 4 + 3] = uint8(c2da_fresh148 >> 0x18)
    let c2da_fresh149 : float = uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
    let c2da_fresh150 : uint = float_bits_to_uint(c2da_fresh149)
    c2da_mem[204240 + 2 * 4] = uint8(c2da_fresh150)
    c2da_mem[204240 + 2 * 4 + 1] = uint8(c2da_fresh150 >> 0x8)
    c2da_mem[204240 + 2 * 4 + 2] = uint8(c2da_fresh150 >> 0x10)
    c2da_mem[204240 + 2 * 4 + 3] = uint8(c2da_fresh150 >> 0x18)
    return
}

// This unit's static data, at heap offset 733632.
let private c2da_lin_static_r_sprite_seg = fixed_array<int>(734432, 102)
let private c2da_lin_static_r_sprite = fixed_array<uint64>(0x7053776172445f52ul, 0x6142203a65746972ul, 0x6574697270732064ul, 0x6425206570797420ul, 0x70757465535f5200ul, 0x5377617244646e41ul, 0x74203a6574697270ul, 0x20796e616d206f6ful, 0x520073746e696f70ul, 0x727053776172445ful, 0x206f6e203a657469ul, 0x6172662068637573ul, 0xa642520656dul)

[init]
def private c2da_lin_init_static_r_sprite() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_sprite_seg[s * 2]
        for (k in range(c2da_lin_static_r_sprite_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_sprite[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
