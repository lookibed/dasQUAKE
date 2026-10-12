[export, sideeffects]
def CL_ParseTEnt() {
    let c2da_saved_sp : int = c2da_lin_sp
    CL_ParseTEnt_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
var cl_sfx_r_exp3 : int = default<int>

[export, sideeffects]
def CL_ParseBeam(var m : int) {
    var ent : int
    var start : vec3_t
    var end : vec3_t
    var b : int
    var i : int
    ent = MSG_ReadShort()
    start[0] = MSG_ReadCoord()
    start[1] = MSG_ReadCoord()
    start[2] = MSG_ReadCoord()
    end[0] = MSG_ReadCoord()
    end[1] = MSG_ReadCoord()
    end[2] = MSG_ReadCoord()
    i = 0
    b = 167680
    while (i < 24) {
        if (int(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) == ent) {
            let c2da_fresh84 : uint = uint(ent)
            c2da_mem[b] = uint8(c2da_fresh84)
            c2da_mem[b + 1] = uint8(c2da_fresh84 >> 0x8)
            c2da_mem[b + 2] = uint8(c2da_fresh84 >> 0x10)
            c2da_mem[b + 3] = uint8(c2da_fresh84 >> 0x18)
            let c2da_fresh85 : uint = uint(m)
            c2da_mem[b + 8] = uint8(c2da_fresh85)
            c2da_mem[b + 9] = uint8(c2da_fresh85 >> 0x8)
            c2da_mem[b + 10] = uint8(c2da_fresh85 >> 0x10)
            c2da_mem[b + 11] = uint8(c2da_fresh85 >> 0x18)
            c2da_mem[b + 12] = 0u8
            c2da_mem[b + 13] = 0u8
            c2da_mem[b + 14] = 0u8
            c2da_mem[b + 15] = 0u8
            let c2da_fresh86 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.2lf)
            let c2da_fresh87 : uint = float_bits_to_uint(c2da_fresh86)
            c2da_mem[b + 16] = uint8(c2da_fresh87)
            c2da_mem[b + 17] = uint8(c2da_fresh87 >> 0x8)
            c2da_mem[b + 18] = uint8(c2da_fresh87 >> 0x10)
            c2da_mem[b + 19] = uint8(c2da_fresh87 >> 0x18)
            let c2da_fresh88 : float = start[0]
            let c2da_fresh89 : uint = float_bits_to_uint(c2da_fresh88)
            c2da_mem[b + 20 + 0 * 4] = uint8(c2da_fresh89)
            c2da_mem[b + 20 + 0 * 4 + 1] = uint8(c2da_fresh89 >> 0x8)
            c2da_mem[b + 20 + 0 * 4 + 2] = uint8(c2da_fresh89 >> 0x10)
            c2da_mem[b + 20 + 0 * 4 + 3] = uint8(c2da_fresh89 >> 0x18)
            let c2da_fresh90 : float = start[1]
            let c2da_fresh91 : uint = float_bits_to_uint(c2da_fresh90)
            c2da_mem[b + 20 + 1 * 4] = uint8(c2da_fresh91)
            c2da_mem[b + 20 + 1 * 4 + 1] = uint8(c2da_fresh91 >> 0x8)
            c2da_mem[b + 20 + 1 * 4 + 2] = uint8(c2da_fresh91 >> 0x10)
            c2da_mem[b + 20 + 1 * 4 + 3] = uint8(c2da_fresh91 >> 0x18)
            let c2da_fresh92 : float = start[2]
            let c2da_fresh93 : uint = float_bits_to_uint(c2da_fresh92)
            c2da_mem[b + 20 + 2 * 4] = uint8(c2da_fresh93)
            c2da_mem[b + 20 + 2 * 4 + 1] = uint8(c2da_fresh93 >> 0x8)
            c2da_mem[b + 20 + 2 * 4 + 2] = uint8(c2da_fresh93 >> 0x10)
            c2da_mem[b + 20 + 2 * 4 + 3] = uint8(c2da_fresh93 >> 0x18)
            let c2da_fresh94 : float = end[0]
            let c2da_fresh95 : uint = float_bits_to_uint(c2da_fresh94)
            c2da_mem[b + 32 + 0 * 4] = uint8(c2da_fresh95)
            c2da_mem[b + 32 + 0 * 4 + 1] = uint8(c2da_fresh95 >> 0x8)
            c2da_mem[b + 32 + 0 * 4 + 2] = uint8(c2da_fresh95 >> 0x10)
            c2da_mem[b + 32 + 0 * 4 + 3] = uint8(c2da_fresh95 >> 0x18)
            let c2da_fresh96 : float = end[1]
            let c2da_fresh97 : uint = float_bits_to_uint(c2da_fresh96)
            c2da_mem[b + 32 + 1 * 4] = uint8(c2da_fresh97)
            c2da_mem[b + 32 + 1 * 4 + 1] = uint8(c2da_fresh97 >> 0x8)
            c2da_mem[b + 32 + 1 * 4 + 2] = uint8(c2da_fresh97 >> 0x10)
            c2da_mem[b + 32 + 1 * 4 + 3] = uint8(c2da_fresh97 >> 0x18)
            let c2da_fresh98 : float = end[2]
            let c2da_fresh99 : uint = float_bits_to_uint(c2da_fresh98)
            c2da_mem[b + 32 + 2 * 4] = uint8(c2da_fresh99)
            c2da_mem[b + 32 + 2 * 4 + 1] = uint8(c2da_fresh99 >> 0x8)
            c2da_mem[b + 32 + 2 * 4 + 2] = uint8(c2da_fresh99 >> 0x10)
            c2da_mem[b + 32 + 2 * 4 + 3] = uint8(c2da_fresh99 >> 0x18)
            return
        }
        i++
        b += 48
    }
    i = 0
    b = 167680
    while (i < 24) {
        if (int(uint(c2da_mem[b + 8]) | uint(c2da_mem[b + 9]) << 0x8 | uint(c2da_mem[b + 10]) << 0x10 | uint(c2da_mem[b + 11]) << 0x18) == 0 || double(uint_bits_to_float(uint(c2da_mem[b + 16]) | uint(c2da_mem[b + 17]) << 0x8 | uint(c2da_mem[b + 18]) << 0x10 | uint(c2da_mem[b + 19]) << 0x18)) < uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20)) {
            let c2da_fresh100 : uint = uint(ent)
            c2da_mem[b] = uint8(c2da_fresh100)
            c2da_mem[b + 1] = uint8(c2da_fresh100 >> 0x8)
            c2da_mem[b + 2] = uint8(c2da_fresh100 >> 0x10)
            c2da_mem[b + 3] = uint8(c2da_fresh100 >> 0x18)
            let c2da_fresh101 : uint = uint(m)
            c2da_mem[b + 8] = uint8(c2da_fresh101)
            c2da_mem[b + 9] = uint8(c2da_fresh101 >> 0x8)
            c2da_mem[b + 10] = uint8(c2da_fresh101 >> 0x10)
            c2da_mem[b + 11] = uint8(c2da_fresh101 >> 0x18)
            c2da_mem[b + 12] = 0u8
            c2da_mem[b + 13] = 0u8
            c2da_mem[b + 14] = 0u8
            c2da_mem[b + 15] = 0u8
            let c2da_fresh102 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.2lf)
            let c2da_fresh103 : uint = float_bits_to_uint(c2da_fresh102)
            c2da_mem[b + 16] = uint8(c2da_fresh103)
            c2da_mem[b + 17] = uint8(c2da_fresh103 >> 0x8)
            c2da_mem[b + 18] = uint8(c2da_fresh103 >> 0x10)
            c2da_mem[b + 19] = uint8(c2da_fresh103 >> 0x18)
            let c2da_fresh104 : float = start[0]
            let c2da_fresh105 : uint = float_bits_to_uint(c2da_fresh104)
            c2da_mem[b + 20 + 0 * 4] = uint8(c2da_fresh105)
            c2da_mem[b + 20 + 0 * 4 + 1] = uint8(c2da_fresh105 >> 0x8)
            c2da_mem[b + 20 + 0 * 4 + 2] = uint8(c2da_fresh105 >> 0x10)
            c2da_mem[b + 20 + 0 * 4 + 3] = uint8(c2da_fresh105 >> 0x18)
            let c2da_fresh106 : float = start[1]
            let c2da_fresh107 : uint = float_bits_to_uint(c2da_fresh106)
            c2da_mem[b + 20 + 1 * 4] = uint8(c2da_fresh107)
            c2da_mem[b + 20 + 1 * 4 + 1] = uint8(c2da_fresh107 >> 0x8)
            c2da_mem[b + 20 + 1 * 4 + 2] = uint8(c2da_fresh107 >> 0x10)
            c2da_mem[b + 20 + 1 * 4 + 3] = uint8(c2da_fresh107 >> 0x18)
            let c2da_fresh108 : float = start[2]
            let c2da_fresh109 : uint = float_bits_to_uint(c2da_fresh108)
            c2da_mem[b + 20 + 2 * 4] = uint8(c2da_fresh109)
            c2da_mem[b + 20 + 2 * 4 + 1] = uint8(c2da_fresh109 >> 0x8)
            c2da_mem[b + 20 + 2 * 4 + 2] = uint8(c2da_fresh109 >> 0x10)
            c2da_mem[b + 20 + 2 * 4 + 3] = uint8(c2da_fresh109 >> 0x18)
            let c2da_fresh110 : float = end[0]
            let c2da_fresh111 : uint = float_bits_to_uint(c2da_fresh110)
            c2da_mem[b + 32 + 0 * 4] = uint8(c2da_fresh111)
            c2da_mem[b + 32 + 0 * 4 + 1] = uint8(c2da_fresh111 >> 0x8)
            c2da_mem[b + 32 + 0 * 4 + 2] = uint8(c2da_fresh111 >> 0x10)
            c2da_mem[b + 32 + 0 * 4 + 3] = uint8(c2da_fresh111 >> 0x18)
            let c2da_fresh112 : float = end[1]
            let c2da_fresh113 : uint = float_bits_to_uint(c2da_fresh112)
            c2da_mem[b + 32 + 1 * 4] = uint8(c2da_fresh113)
            c2da_mem[b + 32 + 1 * 4 + 1] = uint8(c2da_fresh113 >> 0x8)
            c2da_mem[b + 32 + 1 * 4 + 2] = uint8(c2da_fresh113 >> 0x10)
            c2da_mem[b + 32 + 1 * 4 + 3] = uint8(c2da_fresh113 >> 0x18)
            let c2da_fresh114 : float = end[2]
            let c2da_fresh115 : uint = float_bits_to_uint(c2da_fresh114)
            c2da_mem[b + 32 + 2 * 4] = uint8(c2da_fresh115)
            c2da_mem[b + 32 + 2 * 4 + 1] = uint8(c2da_fresh115 >> 0x8)
            c2da_mem[b + 32 + 2 * 4 + 2] = uint8(c2da_fresh115 >> 0x10)
            c2da_mem[b + 32 + 2 * 4 + 3] = uint8(c2da_fresh115 >> 0x18)
            return
        }
        i++
        b += 48
    }
    Con_Printf(700469, [])
    return
}
var cl_sfx_ric3 : int = default<int>

var cl_sfx_ric2 : int = default<int>

var cl_sfx_ric1 : int = default<int>

var cl_sfx_tink1 : int = default<int>

var cl_sfx_knighthit : int = default<int>

var cl_sfx_wizhit : int = default<int>

[export, sideeffects]
def CL_UpdateTEnts() {
    let c2da_saved_sp : int = c2da_lin_sp
    CL_UpdateTEnts_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def CL_NewTempEntity() : int {
    var ent_1 : int
    if (cl_numvisedicts == 256) {
        return 0
    }
    if (num_temp_entities == 64) {
        return 0
    }
    ent_1 = 154880 + num_temp_entities * 200
    c2da_lin_memset(ent_1, 0, 200ul)
    num_temp_entities++
    cl_visedicts[int(cl_numvisedicts)] = ent_1
    cl_numvisedicts = cl_numvisedicts + 1
    let c2da_fresh144 : int = vid.colormap
    let c2da_fresh145 : uint = uint(c2da_fresh144)
    c2da_mem[ent_1 + 160] = uint8(c2da_fresh145)
    c2da_mem[ent_1 + 161] = uint8(c2da_fresh145 >> 0x8)
    c2da_mem[ent_1 + 162] = uint8(c2da_fresh145 >> 0x10)
    c2da_mem[ent_1 + 163] = uint8(c2da_fresh145 >> 0x18)
    c2da_mem[ent_1 + 164] = 0u8
    c2da_mem[ent_1 + 165] = 0u8
    c2da_mem[ent_1 + 166] = 0u8
    c2da_mem[ent_1 + 167] = 0u8
    return ent_1
}
var num_temp_entities : int = default<int>

[export, sideeffects]
def CL_InitTEnts() {
    cl_sfx_wizhit = S_PrecacheSound(700490)
    cl_sfx_knighthit = S_PrecacheSound(700505)
    cl_sfx_tink1 = S_PrecacheSound(700521)
    cl_sfx_ric1 = S_PrecacheSound(700539)
    cl_sfx_ric2 = S_PrecacheSound(700556)
    cl_sfx_ric3 = S_PrecacheSound(700573)
    cl_sfx_r_exp3 = S_PrecacheSound(700590)
    return
}
[sideeffects]
def private CL_ParseTEnt_c2da_frame(c2da_fp : int) {
    var type_0 : int
    var dl : int
    var rnd : int
    var colorStart : int
    var colorLength : int
    type_0 = MSG_ReadByte()
    if (type_0 >= 0 && type_0 <= 13) {
        goto type_0 + 1
    }
    goto label 0
    label 8:
    let c2da_fresh0 : float = MSG_ReadCoord()
    let c2da_fresh1 : uint = float_bits_to_uint(c2da_fresh0)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh1)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : float = MSG_ReadCoord()
    let c2da_fresh3 : uint = float_bits_to_uint(c2da_fresh2)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh3)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : float = MSG_ReadCoord()
    let c2da_fresh5 : uint = float_bits_to_uint(c2da_fresh4)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh5)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh5 >> 0x18)
    R_RunParticleEffect(c2da_fp, 194432, 20, 30)
    S_StartSound(-1, 0, cl_sfx_wizhit, c2da_fp, 1.0, 1.0)
    return
    label 9:
    let c2da_fresh6 : float = MSG_ReadCoord()
    let c2da_fresh7 : uint = float_bits_to_uint(c2da_fresh6)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh7)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
    let c2da_fresh8 : float = MSG_ReadCoord()
    let c2da_fresh9 : uint = float_bits_to_uint(c2da_fresh8)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh9)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh9 >> 0x18)
    let c2da_fresh10 : float = MSG_ReadCoord()
    let c2da_fresh11 : uint = float_bits_to_uint(c2da_fresh10)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh11)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh11 >> 0x18)
    R_RunParticleEffect(c2da_fp, 194432, 226, 20)
    S_StartSound(-1, 0, cl_sfx_knighthit, c2da_fp, 1.0, 1.0)
    return
    label 1:
    let c2da_fresh12 : float = MSG_ReadCoord()
    let c2da_fresh13 : uint = float_bits_to_uint(c2da_fresh12)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh13)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh13 >> 0x18)
    let c2da_fresh14 : float = MSG_ReadCoord()
    let c2da_fresh15 : uint = float_bits_to_uint(c2da_fresh14)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh15)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh15 >> 0x18)
    let c2da_fresh16 : float = MSG_ReadCoord()
    let c2da_fresh17 : uint = float_bits_to_uint(c2da_fresh16)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh17)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
    R_RunParticleEffect(c2da_fp, 194432, 0, 10)
    if (c2da_std_rand() % 5 != 0) {
        S_StartSound(-1, 0, cl_sfx_tink1, c2da_fp, 1.0, 1.0)
    } else {
        rnd = c2da_std_rand() & 3
        if (rnd == 1) {
            S_StartSound(-1, 0, cl_sfx_ric1, c2da_fp, 1.0, 1.0)
        } elif (rnd == 2) {
            S_StartSound(-1, 0, cl_sfx_ric2, c2da_fp, 1.0, 1.0)
        } else {
            S_StartSound(-1, 0, cl_sfx_ric3, c2da_fp, 1.0, 1.0)
        }
    }
    return
    label 2:
    let c2da_fresh18 : float = MSG_ReadCoord()
    let c2da_fresh19 : uint = float_bits_to_uint(c2da_fresh18)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh19)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh19 >> 0x18)
    let c2da_fresh20 : float = MSG_ReadCoord()
    let c2da_fresh21 : uint = float_bits_to_uint(c2da_fresh20)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh21)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh21 >> 0x18)
    let c2da_fresh22 : float = MSG_ReadCoord()
    let c2da_fresh23 : uint = float_bits_to_uint(c2da_fresh22)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh23)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh23 >> 0x18)
    R_RunParticleEffect(c2da_fp, 194432, 0, 20)
    if (c2da_std_rand() % 5 != 0) {
        S_StartSound(-1, 0, cl_sfx_tink1, c2da_fp, 1.0, 1.0)
    } else {
        rnd = c2da_std_rand() & 3
        if (rnd == 1) {
            S_StartSound(-1, 0, cl_sfx_ric1, c2da_fp, 1.0, 1.0)
        } elif (rnd == 2) {
            S_StartSound(-1, 0, cl_sfx_ric2, c2da_fp, 1.0, 1.0)
        } else {
            S_StartSound(-1, 0, cl_sfx_ric3, c2da_fp, 1.0, 1.0)
        }
    }
    return
    label 3:
    let c2da_fresh24 : float = MSG_ReadCoord()
    let c2da_fresh25 : uint = float_bits_to_uint(c2da_fresh24)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh25)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh25 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh25 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh25 >> 0x18)
    let c2da_fresh26 : float = MSG_ReadCoord()
    let c2da_fresh27 : uint = float_bits_to_uint(c2da_fresh26)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh27)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh27 >> 0x18)
    let c2da_fresh28 : float = MSG_ReadCoord()
    let c2da_fresh29 : uint = float_bits_to_uint(c2da_fresh28)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh29)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh29 >> 0x18)
    R_RunParticleEffect(c2da_fp, 194432, 0, 20)
    return
    label 4:
    let c2da_fresh30 : float = MSG_ReadCoord()
    let c2da_fresh31 : uint = float_bits_to_uint(c2da_fresh30)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh31)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh31 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh31 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh31 >> 0x18)
    let c2da_fresh32 : float = MSG_ReadCoord()
    let c2da_fresh33 : uint = float_bits_to_uint(c2da_fresh32)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh33)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh33 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh33 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh33 >> 0x18)
    let c2da_fresh34 : float = MSG_ReadCoord()
    let c2da_fresh35 : uint = float_bits_to_uint(c2da_fresh34)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh35)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh35 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh35 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh35 >> 0x18)
    R_ParticleExplosion(c2da_fp)
    dl = CL_AllocDlight(0)
    let c2da_fresh36 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
    let c2da_fresh37 : uint = float_bits_to_uint(c2da_fresh36)
    c2da_mem[dl + 0 * 4] = uint8(c2da_fresh37)
    c2da_mem[dl + 0 * 4 + 1] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[dl + 0 * 4 + 2] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[dl + 0 * 4 + 3] = uint8(c2da_fresh37 >> 0x18)
    let c2da_fresh38 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
    let c2da_fresh39 : uint = float_bits_to_uint(c2da_fresh38)
    c2da_mem[dl + 1 * 4] = uint8(c2da_fresh39)
    c2da_mem[dl + 1 * 4 + 1] = uint8(c2da_fresh39 >> 0x8)
    c2da_mem[dl + 1 * 4 + 2] = uint8(c2da_fresh39 >> 0x10)
    c2da_mem[dl + 1 * 4 + 3] = uint8(c2da_fresh39 >> 0x18)
    let c2da_fresh40 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
    let c2da_fresh41 : uint = float_bits_to_uint(c2da_fresh40)
    c2da_mem[dl + 2 * 4] = uint8(c2da_fresh41)
    c2da_mem[dl + 2 * 4 + 1] = uint8(c2da_fresh41 >> 0x8)
    c2da_mem[dl + 2 * 4 + 2] = uint8(c2da_fresh41 >> 0x10)
    c2da_mem[dl + 2 * 4 + 3] = uint8(c2da_fresh41 >> 0x18)
    let c2da_fresh42 : float = 350.0
    let c2da_fresh43 : uint = float_bits_to_uint(c2da_fresh42)
    c2da_mem[dl + 12] = uint8(c2da_fresh43)
    c2da_mem[dl + 13] = uint8(c2da_fresh43 >> 0x8)
    c2da_mem[dl + 14] = uint8(c2da_fresh43 >> 0x10)
    c2da_mem[dl + 15] = uint8(c2da_fresh43 >> 0x18)
    let c2da_fresh44 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.5lf)
    let c2da_fresh45 : uint = float_bits_to_uint(c2da_fresh44)
    c2da_mem[dl + 16] = uint8(c2da_fresh45)
    c2da_mem[dl + 17] = uint8(c2da_fresh45 >> 0x8)
    c2da_mem[dl + 18] = uint8(c2da_fresh45 >> 0x10)
    c2da_mem[dl + 19] = uint8(c2da_fresh45 >> 0x18)
    let c2da_fresh46 : float = 300.0
    let c2da_fresh47 : uint = float_bits_to_uint(c2da_fresh46)
    c2da_mem[dl + 20] = uint8(c2da_fresh47)
    c2da_mem[dl + 21] = uint8(c2da_fresh47 >> 0x8)
    c2da_mem[dl + 22] = uint8(c2da_fresh47 >> 0x10)
    c2da_mem[dl + 23] = uint8(c2da_fresh47 >> 0x18)
    S_StartSound(-1, 0, cl_sfx_r_exp3, c2da_fp, 1.0, 1.0)
    return
    label 5:
    let c2da_fresh48 : float = MSG_ReadCoord()
    let c2da_fresh49 : uint = float_bits_to_uint(c2da_fresh48)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh49)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh49 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh49 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh49 >> 0x18)
    let c2da_fresh50 : float = MSG_ReadCoord()
    let c2da_fresh51 : uint = float_bits_to_uint(c2da_fresh50)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh51)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh51 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh51 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh51 >> 0x18)
    let c2da_fresh52 : float = MSG_ReadCoord()
    let c2da_fresh53 : uint = float_bits_to_uint(c2da_fresh52)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh53)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh53 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh53 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh53 >> 0x18)
    R_BlobExplosion(c2da_fp)
    S_StartSound(-1, 0, cl_sfx_r_exp3, c2da_fp, 1.0, 1.0)
    return
    label 6:
    CL_ParseBeam(Mod_ForName(700384, 1u))
    return
    label 7:
    CL_ParseBeam(Mod_ForName(700399, 1u))
    return
    label 10:
    CL_ParseBeam(Mod_ForName(700415, 1u))
    return
    label 14:
    CL_ParseBeam(Mod_ForName(700431, 1u))
    return
    label 11:
    let c2da_fresh54 : float = MSG_ReadCoord()
    let c2da_fresh55 : uint = float_bits_to_uint(c2da_fresh54)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh55)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh55 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh55 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh55 >> 0x18)
    let c2da_fresh56 : float = MSG_ReadCoord()
    let c2da_fresh57 : uint = float_bits_to_uint(c2da_fresh56)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh57)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh57 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh57 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh57 >> 0x18)
    let c2da_fresh58 : float = MSG_ReadCoord()
    let c2da_fresh59 : uint = float_bits_to_uint(c2da_fresh58)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh59)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh59 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh59 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh59 >> 0x18)
    R_LavaSplash(c2da_fp)
    return
    label 12:
    let c2da_fresh60 : float = MSG_ReadCoord()
    let c2da_fresh61 : uint = float_bits_to_uint(c2da_fresh60)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh61)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh61 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh61 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh61 >> 0x18)
    let c2da_fresh62 : float = MSG_ReadCoord()
    let c2da_fresh63 : uint = float_bits_to_uint(c2da_fresh62)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh63)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh63 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh63 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh63 >> 0x18)
    let c2da_fresh64 : float = MSG_ReadCoord()
    let c2da_fresh65 : uint = float_bits_to_uint(c2da_fresh64)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh65)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh65 >> 0x18)
    R_TeleportSplash(c2da_fp)
    return
    label 13:
    let c2da_fresh66 : float = MSG_ReadCoord()
    let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh67)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh67 >> 0x18)
    let c2da_fresh68 : float = MSG_ReadCoord()
    let c2da_fresh69 : uint = float_bits_to_uint(c2da_fresh68)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh69)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh69 >> 0x18)
    let c2da_fresh70 : float = MSG_ReadCoord()
    let c2da_fresh71 : uint = float_bits_to_uint(c2da_fresh70)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh71)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh71 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh71 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh71 >> 0x18)
    colorStart = MSG_ReadByte()
    colorLength = MSG_ReadByte()
    R_ParticleExplosion2(c2da_fp, colorStart, colorLength)
    dl = CL_AllocDlight(0)
    let c2da_fresh72 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
    let c2da_fresh73 : uint = float_bits_to_uint(c2da_fresh72)
    c2da_mem[dl + 0 * 4] = uint8(c2da_fresh73)
    c2da_mem[dl + 0 * 4 + 1] = uint8(c2da_fresh73 >> 0x8)
    c2da_mem[dl + 0 * 4 + 2] = uint8(c2da_fresh73 >> 0x10)
    c2da_mem[dl + 0 * 4 + 3] = uint8(c2da_fresh73 >> 0x18)
    let c2da_fresh74 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
    let c2da_fresh75 : uint = float_bits_to_uint(c2da_fresh74)
    c2da_mem[dl + 1 * 4] = uint8(c2da_fresh75)
    c2da_mem[dl + 1 * 4 + 1] = uint8(c2da_fresh75 >> 0x8)
    c2da_mem[dl + 1 * 4 + 2] = uint8(c2da_fresh75 >> 0x10)
    c2da_mem[dl + 1 * 4 + 3] = uint8(c2da_fresh75 >> 0x18)
    let c2da_fresh76 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
    let c2da_fresh77 : uint = float_bits_to_uint(c2da_fresh76)
    c2da_mem[dl + 2 * 4] = uint8(c2da_fresh77)
    c2da_mem[dl + 2 * 4 + 1] = uint8(c2da_fresh77 >> 0x8)
    c2da_mem[dl + 2 * 4 + 2] = uint8(c2da_fresh77 >> 0x10)
    c2da_mem[dl + 2 * 4 + 3] = uint8(c2da_fresh77 >> 0x18)
    let c2da_fresh78 : float = 350.0
    let c2da_fresh79 : uint = float_bits_to_uint(c2da_fresh78)
    c2da_mem[dl + 12] = uint8(c2da_fresh79)
    c2da_mem[dl + 13] = uint8(c2da_fresh79 >> 0x8)
    c2da_mem[dl + 14] = uint8(c2da_fresh79 >> 0x10)
    c2da_mem[dl + 15] = uint8(c2da_fresh79 >> 0x18)
    let c2da_fresh80 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.5lf)
    let c2da_fresh81 : uint = float_bits_to_uint(c2da_fresh80)
    c2da_mem[dl + 16] = uint8(c2da_fresh81)
    c2da_mem[dl + 17] = uint8(c2da_fresh81 >> 0x8)
    c2da_mem[dl + 18] = uint8(c2da_fresh81 >> 0x10)
    c2da_mem[dl + 19] = uint8(c2da_fresh81 >> 0x18)
    let c2da_fresh82 : float = 300.0
    let c2da_fresh83 : uint = float_bits_to_uint(c2da_fresh82)
    c2da_mem[dl + 20] = uint8(c2da_fresh83)
    c2da_mem[dl + 21] = uint8(c2da_fresh83 >> 0x8)
    c2da_mem[dl + 22] = uint8(c2da_fresh83 >> 0x10)
    c2da_mem[dl + 23] = uint8(c2da_fresh83 >> 0x18)
    S_StartSound(-1, 0, cl_sfx_r_exp3, c2da_fp, 1.0, 1.0)
    return
    label 0:
    Sys_Error(700446, [])
    return
}
[sideeffects]
def private CL_UpdateTEnts_c2da_frame(c2da_fp : int) {
    var i_0 : int
    var b_0 : int
    var org : vec3_t
    var d : float
    var ent_0 : int
    var yaw : float
    var pitch : float
    var forward_0 : float
    num_temp_entities = 0
    i_0 = 0
    b_0 = 167680
    while (i_0 < 24) {
        if (int(uint(c2da_mem[b_0 + 8]) | uint(c2da_mem[b_0 + 9]) << 0x8 | uint(c2da_mem[b_0 + 10]) << 0x10 | uint(c2da_mem[b_0 + 11]) << 0x18) == 0 || double(uint_bits_to_float(uint(c2da_mem[b_0 + 16]) | uint(c2da_mem[b_0 + 17]) << 0x8 | uint(c2da_mem[b_0 + 18]) << 0x10 | uint(c2da_mem[b_0 + 19]) << 0x18)) < uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20)) {
            i_0++
            b_0 += 48
            continue
        }
        let c2da_fresh143 : int = int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18)
        if (int(uint(c2da_mem[b_0]) | uint(c2da_mem[b_0 + 1]) << 0x8 | uint(c2da_mem[b_0 + 2]) << 0x10 | uint(c2da_mem[b_0 + 3]) << 0x18) == c2da_fresh143) {
            let c2da_fresh116 : int = 10048 + c2da_fresh143 * 200 + 88 + 0 * 4
            let c2da_fresh117 : float = uint_bits_to_float(uint(c2da_mem[c2da_fresh116]) | uint(c2da_mem[c2da_fresh116 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh116 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh116 + 3]) << 0x18)
            let c2da_fresh118 : uint = float_bits_to_uint(c2da_fresh117)
            c2da_mem[b_0 + 20 + 0 * 4] = uint8(c2da_fresh118)
            c2da_mem[b_0 + 20 + 0 * 4 + 1] = uint8(c2da_fresh118 >> 0x8)
            c2da_mem[b_0 + 20 + 0 * 4 + 2] = uint8(c2da_fresh118 >> 0x10)
            c2da_mem[b_0 + 20 + 0 * 4 + 3] = uint8(c2da_fresh118 >> 0x18)
            let c2da_fresh119 : int = 10048 + int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18) * 200 + 88 + 1 * 4
            let c2da_fresh120 : float = uint_bits_to_float(uint(c2da_mem[c2da_fresh119]) | uint(c2da_mem[c2da_fresh119 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh119 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh119 + 3]) << 0x18)
            let c2da_fresh121 : uint = float_bits_to_uint(c2da_fresh120)
            c2da_mem[b_0 + 20 + 1 * 4] = uint8(c2da_fresh121)
            c2da_mem[b_0 + 20 + 1 * 4 + 1] = uint8(c2da_fresh121 >> 0x8)
            c2da_mem[b_0 + 20 + 1 * 4 + 2] = uint8(c2da_fresh121 >> 0x10)
            c2da_mem[b_0 + 20 + 1 * 4 + 3] = uint8(c2da_fresh121 >> 0x18)
            let c2da_fresh122 : int = 10048 + int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18) * 200 + 88 + 2 * 4
            let c2da_fresh123 : float = uint_bits_to_float(uint(c2da_mem[c2da_fresh122]) | uint(c2da_mem[c2da_fresh122 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh122 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh122 + 3]) << 0x18)
            let c2da_fresh124 : uint = float_bits_to_uint(c2da_fresh123)
            c2da_mem[b_0 + 20 + 2 * 4] = uint8(c2da_fresh124)
            c2da_mem[b_0 + 20 + 2 * 4 + 1] = uint8(c2da_fresh124 >> 0x8)
            c2da_mem[b_0 + 20 + 2 * 4 + 2] = uint8(c2da_fresh124 >> 0x10)
            c2da_mem[b_0 + 20 + 2 * 4 + 3] = uint8(c2da_fresh124 >> 0x18)
        }
        let c2da_fresh125 : float = uint_bits_to_float(uint(c2da_mem[b_0 + 32 + 0 * 4]) | uint(c2da_mem[b_0 + 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[b_0 + 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[b_0 + 32 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[b_0 + 20 + 0 * 4]) | uint(c2da_mem[b_0 + 20 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[b_0 + 20 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[b_0 + 20 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh126 : uint = float_bits_to_uint(c2da_fresh125)
        c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh126)
        c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh126 >> 0x8)
        c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh126 >> 0x10)
        c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh126 >> 0x18)
        let c2da_fresh127 : float = uint_bits_to_float(uint(c2da_mem[b_0 + 32 + 1 * 4]) | uint(c2da_mem[b_0 + 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[b_0 + 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[b_0 + 32 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[b_0 + 20 + 1 * 4]) | uint(c2da_mem[b_0 + 20 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[b_0 + 20 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[b_0 + 20 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh128 : uint = float_bits_to_uint(c2da_fresh127)
        c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh128)
        c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh128 >> 0x8)
        c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh128 >> 0x10)
        c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh128 >> 0x18)
        let c2da_fresh129 : float = uint_bits_to_float(uint(c2da_mem[b_0 + 32 + 2 * 4]) | uint(c2da_mem[b_0 + 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[b_0 + 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[b_0 + 32 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[b_0 + 20 + 2 * 4]) | uint(c2da_mem[b_0 + 20 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[b_0 + 20 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[b_0 + 20 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh130 : uint = float_bits_to_uint(c2da_fresh129)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh130)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh130 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh130 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh130 >> 0x18)
        if (c2da_fresh127 == 0.0 && c2da_fresh125 == 0.0) {
            yaw = 0.0
            if (c2da_fresh129 > 0.0) {
                pitch = 90.0
            } else {
                pitch = 270.0
            }
        } else {
            yaw = float(int(atan2(double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)), double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18))) * 180.0lf / 3.141592653589793lf))
            if (yaw < 0.0) {
                yaw += 360.0
            }
            forward_0 = float(sqrt(double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18))))
            pitch = float(int(atan2(double(uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)), double(forward_0)) * 180.0lf / 3.141592653589793lf))
            if (pitch < 0.0) {
                pitch += 360.0
            }
        }
        org[0] = uint_bits_to_float(uint(c2da_mem[b_0 + 20 + 0 * 4]) | uint(c2da_mem[b_0 + 20 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[b_0 + 20 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[b_0 + 20 + 0 * 4 + 3]) << 0x18)
        org[1] = uint_bits_to_float(uint(c2da_mem[b_0 + 20 + 1 * 4]) | uint(c2da_mem[b_0 + 20 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[b_0 + 20 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[b_0 + 20 + 1 * 4 + 3]) << 0x18)
        org[2] = uint_bits_to_float(uint(c2da_mem[b_0 + 20 + 2 * 4]) | uint(c2da_mem[b_0 + 20 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[b_0 + 20 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[b_0 + 20 + 2 * 4 + 3]) << 0x18)
        d = VectorNormalize(c2da_fp)
        while (d > 0.0) {
            ent_0 = CL_NewTempEntity()
            if (ent_0 == 0) {
                return
            }
            let c2da_fresh131 : float = org[0]
            let c2da_fresh132 : uint = float_bits_to_uint(c2da_fresh131)
            c2da_mem[ent_0 + 88 + 0 * 4] = uint8(c2da_fresh132)
            c2da_mem[ent_0 + 88 + 0 * 4 + 1] = uint8(c2da_fresh132 >> 0x8)
            c2da_mem[ent_0 + 88 + 0 * 4 + 2] = uint8(c2da_fresh132 >> 0x10)
            c2da_mem[ent_0 + 88 + 0 * 4 + 3] = uint8(c2da_fresh132 >> 0x18)
            let c2da_fresh133 : float = org[1]
            let c2da_fresh134 : uint = float_bits_to_uint(c2da_fresh133)
            c2da_mem[ent_0 + 88 + 1 * 4] = uint8(c2da_fresh134)
            c2da_mem[ent_0 + 88 + 1 * 4 + 1] = uint8(c2da_fresh134 >> 0x8)
            c2da_mem[ent_0 + 88 + 1 * 4 + 2] = uint8(c2da_fresh134 >> 0x10)
            c2da_mem[ent_0 + 88 + 1 * 4 + 3] = uint8(c2da_fresh134 >> 0x18)
            let c2da_fresh135 : float = org[2]
            let c2da_fresh136 : uint = float_bits_to_uint(c2da_fresh135)
            c2da_mem[ent_0 + 88 + 2 * 4] = uint8(c2da_fresh136)
            c2da_mem[ent_0 + 88 + 2 * 4 + 1] = uint8(c2da_fresh136 >> 0x8)
            c2da_mem[ent_0 + 88 + 2 * 4 + 2] = uint8(c2da_fresh136 >> 0x10)
            c2da_mem[ent_0 + 88 + 2 * 4 + 3] = uint8(c2da_fresh136 >> 0x18)
            let c2da_fresh137 : int = int(uint(c2da_mem[b_0 + 8]) | uint(c2da_mem[b_0 + 9]) << 0x8 | uint(c2da_mem[b_0 + 10]) << 0x10 | uint(c2da_mem[b_0 + 11]) << 0x18)
            let c2da_fresh138 : uint = uint(c2da_fresh137)
            c2da_mem[ent_0 + 136] = uint8(c2da_fresh138)
            c2da_mem[ent_0 + 137] = uint8(c2da_fresh138 >> 0x8)
            c2da_mem[ent_0 + 138] = uint8(c2da_fresh138 >> 0x10)
            c2da_mem[ent_0 + 139] = uint8(c2da_fresh138 >> 0x18)
            c2da_mem[ent_0 + 140] = 0u8
            c2da_mem[ent_0 + 141] = 0u8
            c2da_mem[ent_0 + 142] = 0u8
            c2da_mem[ent_0 + 143] = 0u8
            let c2da_fresh139 : uint = float_bits_to_uint(pitch)
            c2da_mem[ent_0 + 124 + 0 * 4] = uint8(c2da_fresh139)
            c2da_mem[ent_0 + 124 + 0 * 4 + 1] = uint8(c2da_fresh139 >> 0x8)
            c2da_mem[ent_0 + 124 + 0 * 4 + 2] = uint8(c2da_fresh139 >> 0x10)
            c2da_mem[ent_0 + 124 + 0 * 4 + 3] = uint8(c2da_fresh139 >> 0x18)
            let c2da_fresh140 : uint = float_bits_to_uint(yaw)
            c2da_mem[ent_0 + 124 + 1 * 4] = uint8(c2da_fresh140)
            c2da_mem[ent_0 + 124 + 1 * 4 + 1] = uint8(c2da_fresh140 >> 0x8)
            c2da_mem[ent_0 + 124 + 1 * 4 + 2] = uint8(c2da_fresh140 >> 0x10)
            c2da_mem[ent_0 + 124 + 1 * 4 + 3] = uint8(c2da_fresh140 >> 0x18)
            let c2da_fresh141 : float = float(c2da_std_rand() % 360)
            let c2da_fresh142 : uint = float_bits_to_uint(c2da_fresh141)
            c2da_mem[ent_0 + 124 + 2 * 4] = uint8(c2da_fresh142)
            c2da_mem[ent_0 + 124 + 2 * 4 + 1] = uint8(c2da_fresh142 >> 0x8)
            c2da_mem[ent_0 + 124 + 2 * 4 + 2] = uint8(c2da_fresh142 >> 0x10)
            c2da_mem[ent_0 + 124 + 2 * 4 + 3] = uint8(c2da_fresh142 >> 0x18)
            for (j in range(0, 3)) {
                org[j] = org[j] + uint_bits_to_float(uint(c2da_mem[c2da_fp + j * 4]) | uint(c2da_mem[c2da_fp + j * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + j * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + j * 4 + 3]) << 0x18) * 30.0
            }
            d -= 30.0
        }
        i_0++
        b_0 += 48
    }
    return
}

// This unit's static data, at heap offset 700384.
let private c2da_lin_static_cl_tent_seg = fixed_array<int>(700384, 224)
let private c2da_lin_static_cl_tent = fixed_array<uint64>(0x6f622f73676f7270ul, 0x70006c646d2e746cul, 0x6c6f622f73676f72ul, 0x70006c646d2e3274ul, 0x6c6f622f73676f72ul, 0x70006c646d2e3374ul, 0x6165622f73676f72ul, 0x4c43006c646d2e6dul, 0x455465737261505ful, 0x20646162203a746eul, 0x6165620065707974ul, 0x6f207473696c206dul, 0x21776f6c66726576ul, 0x6472617a6977000aul, 0x7661772e7469682ful, 0x746867696e6b6800ul, 0x7661772e7469682ful, 0x736e6f7061657700ul, 0x772e316b6e69742ful, 0x6f70616577007661ul, 0x2e316369722f736eul, 0x7061657700766177ul, 0x326369722f736e6ful, 0x616577007661772eul, 0x6369722f736e6f70ul, 0x6577007661772e33ul, 0x5f722f736e6f7061ul, 0x7661772e33707865ul)

[init]
def private c2da_lin_init_static_cl_tent() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_cl_tent_seg[s * 2]
        for (k in range(c2da_lin_static_cl_tent_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_cl_tent[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
