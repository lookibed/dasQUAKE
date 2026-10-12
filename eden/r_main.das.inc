var reinit_surfcache : int = 1

var r_notexture_mip : int = default<int>

[export, sideeffects]
def R_Init() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_Init_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_InitTurb() {
    var i : int = 0
    while (i < (1024 > 1280 ? 1024 : 1280) + 128) {
        let c2da_fresh8 : int = int(double(8 * 65536) + sin(double(i) * 3.14159lf * 2.0lf / 128.0lf) * 8.0lf * 65536.0lf)
        let c2da_fresh9 : uint = uint(c2da_fresh8)
        c2da_mem[210944 + i * 4] = uint8(c2da_fresh9)
        c2da_mem[210944 + i * 4 + 1] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[210944 + i * 4 + 2] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[210944 + i * 4 + 3] = uint8(c2da_fresh9 >> 0x18)
        let c2da_fresh10 : int = int(3.0lf + sin(double(i) * 3.14159lf * 2.0lf / 128.0lf) * 3.0lf)
        let c2da_fresh11 : uint = uint(c2da_fresh10)
        c2da_mem[205312 + i * 4] = uint8(c2da_fresh11)
        c2da_mem[205312 + i * 4 + 1] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[205312 + i * 4 + 2] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[205312 + i * 4 + 3] = uint8(c2da_fresh11 >> 0x18)
        i++
    }
    return
}
var r_stack_start : int = default<int>

[export, sideeffects]
def R_InitTextures() {
    var dest : int
    r_notexture_mip = Hunk_AllocName(int(72ul + uint64(16 * 16) + uint64(8 * 8) + uint64(4 * 4) + uint64(2 * 2)), 733048)
    let c2da_fresh12 : uint = 16u
    let c2da_fresh13 : uint = c2da_fresh12
    c2da_mem[r_notexture_mip + 20] = uint8(c2da_fresh13)
    c2da_mem[r_notexture_mip + 21] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[r_notexture_mip + 22] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[r_notexture_mip + 23] = uint8(c2da_fresh13 >> 0x18)
    let c2da_fresh14 : uint = c2da_fresh12
    c2da_mem[r_notexture_mip + 16] = uint8(c2da_fresh14)
    c2da_mem[r_notexture_mip + 17] = uint8(c2da_fresh14 >> 0x8)
    c2da_mem[r_notexture_mip + 18] = uint8(c2da_fresh14 >> 0x10)
    c2da_mem[r_notexture_mip + 19] = uint8(c2da_fresh14 >> 0x18)
    let c2da_fresh15 : uint = 72u
    let c2da_fresh16 : uint = c2da_fresh15
    c2da_mem[r_notexture_mip + 56 + 0 * 4] = uint8(c2da_fresh16)
    c2da_mem[r_notexture_mip + 56 + 0 * 4 + 1] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[r_notexture_mip + 56 + 0 * 4 + 2] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[r_notexture_mip + 56 + 0 * 4 + 3] = uint8(c2da_fresh16 >> 0x18)
    let c2da_fresh17 : uint = (uint(c2da_mem[r_notexture_mip + 56 + 0 * 4]) | uint(c2da_mem[r_notexture_mip + 56 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[r_notexture_mip + 56 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[r_notexture_mip + 56 + 0 * 4 + 3]) << 0x18) + uint(16 * 16)
    let c2da_fresh18 : uint = c2da_fresh17
    c2da_mem[r_notexture_mip + 56 + 1 * 4] = uint8(c2da_fresh18)
    c2da_mem[r_notexture_mip + 56 + 1 * 4 + 1] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[r_notexture_mip + 56 + 1 * 4 + 2] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[r_notexture_mip + 56 + 1 * 4 + 3] = uint8(c2da_fresh18 >> 0x18)
    let c2da_fresh19 : uint = (uint(c2da_mem[r_notexture_mip + 56 + 1 * 4]) | uint(c2da_mem[r_notexture_mip + 56 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[r_notexture_mip + 56 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[r_notexture_mip + 56 + 1 * 4 + 3]) << 0x18) + uint(8 * 8)
    let c2da_fresh20 : uint = c2da_fresh19
    c2da_mem[r_notexture_mip + 56 + 2 * 4] = uint8(c2da_fresh20)
    c2da_mem[r_notexture_mip + 56 + 2 * 4 + 1] = uint8(c2da_fresh20 >> 0x8)
    c2da_mem[r_notexture_mip + 56 + 2 * 4 + 2] = uint8(c2da_fresh20 >> 0x10)
    c2da_mem[r_notexture_mip + 56 + 2 * 4 + 3] = uint8(c2da_fresh20 >> 0x18)
    let c2da_fresh21 : uint = (uint(c2da_mem[r_notexture_mip + 56 + 2 * 4]) | uint(c2da_mem[r_notexture_mip + 56 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[r_notexture_mip + 56 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[r_notexture_mip + 56 + 2 * 4 + 3]) << 0x18) + uint(4 * 4)
    let c2da_fresh22 : uint = c2da_fresh21
    c2da_mem[r_notexture_mip + 56 + 3 * 4] = uint8(c2da_fresh22)
    c2da_mem[r_notexture_mip + 56 + 3 * 4 + 1] = uint8(c2da_fresh22 >> 0x8)
    c2da_mem[r_notexture_mip + 56 + 3 * 4 + 2] = uint8(c2da_fresh22 >> 0x10)
    c2da_mem[r_notexture_mip + 56 + 3 * 4 + 3] = uint8(c2da_fresh22 >> 0x18)
    for (m in range(0, 4)) {
        dest = r_notexture_mip + int(uint(c2da_mem[r_notexture_mip + 56 + m * 4]) | uint(c2da_mem[r_notexture_mip + 56 + m * 4 + 1]) << 0x8 | uint(c2da_mem[r_notexture_mip + 56 + m * 4 + 2]) << 0x10 | uint(c2da_mem[r_notexture_mip + 56 + m * 4 + 3]) << 0x18)
        for (y in range(0, 16 >> m)) {
            for (x in range(0, 16 >> m)) {
                if (((y < 8 >> m ? 1 : 0) ^ (x < 8 >> m ? 1 : 0)) != 0) {
                    let c2da_fresh23 : int = dest
                    dest++
                    let c2da_fresh24 : uint8 = 0u8
                    c2da_mem[c2da_fresh23] = c2da_fresh24
                } else {
                    let c2da_fresh25 : int = dest
                    dest++
                    let c2da_fresh26 : uint8 = 0xffu8
                    c2da_mem[c2da_fresh25] = c2da_fresh26
                }
            }
        }
    }
    return
}
[export, sideeffects]
def R_RenderView() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_RenderView_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_RenderView_() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_RenderView__c2da_frame(c2da_lin_enter(64000))
    c2da_lin_sp = c2da_saved_sp
}
var r_outofedges : int = default<int>

var r_outofsurfaces : int = default<int>

var r_viewleaf : int = default<int>

var r_dowarp : uint = default<uint>

var dp_time2 : float = default<float>

var dp_time1 : float = default<float>

var dv_time2 : float = default<float>

[export, sideeffects]
def R_DrawViewModel() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_DrawViewModel_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
var r_fov_greater_than_90 : uint = default<uint>

var de_time2 : float = default<float>

var dv_time1 : float = default<float>

[export, sideeffects]
def R_DrawEntitiesOnList() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_DrawEntitiesOnList_c2da_frame(c2da_lin_enter(48))
    c2da_lin_sp = c2da_saved_sp
}
var se_time2 : float = default<float>

var de_time1 : float = default<float>

[export, sideeffects]
def R_EdgeDrawing() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_EdgeDrawing_c2da_frame(c2da_lin_enter(204960))
    c2da_lin_sp = c2da_saved_sp
}
var r_drawculledpolys : uint = default<uint>

var r_drawpolys : uint = default<uint>

var db_time2 : float = default<float>

var se_time1 : float = default<float>

[export, sideeffects]
def R_DrawBEntitiesOnList() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_DrawBEntitiesOnList_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
var base_vright : vec3_t = default<vec3_t>

var base_vup : vec3_t = default<vec3_t>

var base_vpn : vec3_t = default<vec3_t>

var r_clipflags : int = default<int>

var r_pcurrentvertbase : int = default<int>

[export, sideeffects]
def R_BmodelCheckBBox(var clmodel_0 : int; var minmaxs : int) : int {
    var i_2 : int
    var pindex : int
    var clipflags_0 : int
    var acceptpt : vec3_t
    var rejectpt : vec3_t
    var d : double
    clipflags_0 = 0
    if (uint_bits_to_float(uint(c2da_mem[currententity + 124 + 0 * 4]) | uint(c2da_mem[currententity + 124 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 124 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 124 + 0 * 4 + 3]) << 0x18) != 0.0 || uint_bits_to_float(uint(c2da_mem[currententity + 124 + 1 * 4]) | uint(c2da_mem[currententity + 124 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 124 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 124 + 1 * 4 + 3]) << 0x18) != 0.0 || uint_bits_to_float(uint(c2da_mem[currententity + 124 + 2 * 4]) | uint(c2da_mem[currententity + 124 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 124 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 124 + 2 * 4 + 3]) << 0x18) != 0.0) {
        i_2 = 0
        for (c2da_i_2 in range(i_2, 4)) {
            d = double(uint_bits_to_float(uint(c2da_mem[currententity + 88 + 0 * 4]) | uint(c2da_mem[currententity + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[391440 + c2da_i_2 * 32 + 0 * 4]) | uint(c2da_mem[391440 + c2da_i_2 * 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + c2da_i_2 * 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + c2da_i_2 * 32 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[currententity + 88 + 1 * 4]) | uint(c2da_mem[currententity + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[391440 + c2da_i_2 * 32 + 1 * 4]) | uint(c2da_mem[391440 + c2da_i_2 * 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + c2da_i_2 * 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + c2da_i_2 * 32 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[currententity + 88 + 2 * 4]) | uint(c2da_mem[currententity + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[391440 + c2da_i_2 * 32 + 2 * 4]) | uint(c2da_mem[391440 + c2da_i_2 * 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + c2da_i_2 * 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + c2da_i_2 * 32 + 2 * 4 + 3]) << 0x18))
            d = d - double(uint_bits_to_float(uint(c2da_mem[391440 + c2da_i_2 * 32 + 12]) | uint(c2da_mem[391440 + c2da_i_2 * 32 + 13]) << 0x8 | uint(c2da_mem[391440 + c2da_i_2 * 32 + 14]) << 0x10 | uint(c2da_mem[391440 + c2da_i_2 * 32 + 15]) << 0x18))
            if (d <= double(-uint_bits_to_float(uint(c2da_mem[clmodel_0 + 108]) | uint(c2da_mem[clmodel_0 + 109]) << 0x8 | uint(c2da_mem[clmodel_0 + 110]) << 0x10 | uint(c2da_mem[clmodel_0 + 111]) << 0x18))) {
                return 16
            }
            if (d <= double(uint_bits_to_float(uint(c2da_mem[clmodel_0 + 108]) | uint(c2da_mem[clmodel_0 + 109]) << 0x8 | uint(c2da_mem[clmodel_0 + 110]) << 0x10 | uint(c2da_mem[clmodel_0 + 111]) << 0x18))) {
                clipflags_0 |= 1 << c2da_i_2
            }
        }
    } else {
        i_2 = 0
        for (c2da_i_2_0 in range(i_2, 4)) {
            pindex = pfrustum_indexes[c2da_i_2_0]
            let c2da_fresh134 : int = minmaxs + int(uint(c2da_mem[pindex + 0 * 4]) | uint(c2da_mem[pindex + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pindex + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pindex + 0 * 4 + 3]) << 0x18) * 4
            rejectpt[0] = uint_bits_to_float(uint(c2da_mem[c2da_fresh134]) | uint(c2da_mem[c2da_fresh134 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh134 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh134 + 3]) << 0x18)
            let c2da_fresh135 : int = minmaxs + int(uint(c2da_mem[pindex + 1 * 4]) | uint(c2da_mem[pindex + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pindex + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pindex + 1 * 4 + 3]) << 0x18) * 4
            rejectpt[1] = uint_bits_to_float(uint(c2da_mem[c2da_fresh135]) | uint(c2da_mem[c2da_fresh135 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh135 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh135 + 3]) << 0x18)
            let c2da_fresh136 : int = minmaxs + int(uint(c2da_mem[pindex + 2 * 4]) | uint(c2da_mem[pindex + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pindex + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pindex + 2 * 4 + 3]) << 0x18) * 4
            rejectpt[2] = uint_bits_to_float(uint(c2da_mem[c2da_fresh136]) | uint(c2da_mem[c2da_fresh136 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh136 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh136 + 3]) << 0x18)
            d = double(rejectpt[0] * uint_bits_to_float(uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 0 * 4]) | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 0 * 4 + 3]) << 0x18) + rejectpt[1] * uint_bits_to_float(uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 1 * 4]) | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 1 * 4 + 3]) << 0x18) + rejectpt[2] * uint_bits_to_float(uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 2 * 4]) | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 2 * 4 + 3]) << 0x18))
            d = d - double(uint_bits_to_float(uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 12]) | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 13]) << 0x8 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 14]) << 0x10 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 15]) << 0x18))
            if (d <= 0.0lf) {
                return 16
            }
            let c2da_fresh137 : int = minmaxs + int(uint(c2da_mem[pindex + (3 + 0) * 4]) | uint(c2da_mem[pindex + (3 + 0) * 4 + 1]) << 0x8 | uint(c2da_mem[pindex + (3 + 0) * 4 + 2]) << 0x10 | uint(c2da_mem[pindex + (3 + 0) * 4 + 3]) << 0x18) * 4
            acceptpt[0] = uint_bits_to_float(uint(c2da_mem[c2da_fresh137]) | uint(c2da_mem[c2da_fresh137 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh137 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh137 + 3]) << 0x18)
            let c2da_fresh138 : int = minmaxs + int(uint(c2da_mem[pindex + (3 + 1) * 4]) | uint(c2da_mem[pindex + (3 + 1) * 4 + 1]) << 0x8 | uint(c2da_mem[pindex + (3 + 1) * 4 + 2]) << 0x10 | uint(c2da_mem[pindex + (3 + 1) * 4 + 3]) << 0x18) * 4
            acceptpt[1] = uint_bits_to_float(uint(c2da_mem[c2da_fresh138]) | uint(c2da_mem[c2da_fresh138 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh138 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh138 + 3]) << 0x18)
            let c2da_fresh139 : int = minmaxs + int(uint(c2da_mem[pindex + (3 + 2) * 4]) | uint(c2da_mem[pindex + (3 + 2) * 4 + 1]) << 0x8 | uint(c2da_mem[pindex + (3 + 2) * 4 + 2]) << 0x10 | uint(c2da_mem[pindex + (3 + 2) * 4 + 3]) << 0x18) * 4
            acceptpt[2] = uint_bits_to_float(uint(c2da_mem[c2da_fresh139]) | uint(c2da_mem[c2da_fresh139 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh139 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh139 + 3]) << 0x18)
            d = double(acceptpt[0] * uint_bits_to_float(uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 0 * 4]) | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 0 * 4 + 3]) << 0x18) + acceptpt[1] * uint_bits_to_float(uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 1 * 4]) | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 1 * 4 + 3]) << 0x18) + acceptpt[2] * uint_bits_to_float(uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 2 * 4]) | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 2 * 4 + 3]) << 0x18))
            d = d - double(uint_bits_to_float(uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 12]) | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 13]) << 0x8 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 14]) << 0x10 | uint(c2da_mem[391440 + c2da_i_2_0 * 32 + 15]) << 0x18))
            if (d <= 0.0lf) {
                clipflags_0 |= 1 << c2da_i_2_0
            }
        }
    }
    return clipflags_0
}
var pfrustum_indexes : int[4]

var r_framecount : int = 1

var rw_time2 : float = default<float>

var db_time1 : float = default<float>

var rw_time1 : float = default<float>

var r_cnumsurfs : int = default<int>

var r_surfsonstack : uint = default<uint>

[export, sideeffects]
def R_MarkLeaves() {
    var vis : int
    var node : int
    var i_3 : int
    if (r_oldviewleaf == r_viewleaf) {
        return
    }
    r_visframecount++
    r_oldviewleaf = int(r_viewleaf)  // nolint:PERF020
    vis = Mod_LeafPVS(r_viewleaf, int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18))
    i_3 = 0
    while (true) {
        let c2da_fresh140 : int = int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) + 152
        if (i_3 >= int(uint(c2da_mem[c2da_fresh140]) | uint(c2da_mem[c2da_fresh140 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh140 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh140 + 3]) << 0x18)) {
            break
        }
        let c2da_fresh141 : int = vis + (i_3 >> 3)
        if ((int(c2da_mem[c2da_fresh141]) & 1 << (i_3 & 7)) != 0) {
            let c2da_fresh142 : int = int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) + 160
            node = int(uint(c2da_mem[c2da_fresh142]) | uint(c2da_mem[c2da_fresh142 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh142 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh142 + 3]) << 0x18) + (i_3 + 1) * 72
            while (true) {
                if (int(uint(c2da_mem[node + 4]) | uint(c2da_mem[node + 5]) << 0x8 | uint(c2da_mem[node + 6]) << 0x10 | uint(c2da_mem[node + 7]) << 0x18) == r_visframecount) {
                    break
                }
                let c2da_fresh143 : uint = uint(r_visframecount)
                c2da_mem[node + 4] = uint8(c2da_fresh143)
                c2da_mem[node + 5] = uint8(c2da_fresh143 >> 0x8)
                c2da_mem[node + 6] = uint8(c2da_fresh143 >> 0x10)
                c2da_mem[node + 7] = uint8(c2da_fresh143 >> 0x18)
                node = int(uint(c2da_mem[node + 24]) | uint(c2da_mem[node + 25]) << 0x8 | uint(c2da_mem[node + 26]) << 0x10 | uint(c2da_mem[node + 27]) << 0x18)
                if (node == 0) {
                    break
                }
            }
        }
        i_3++
    }
    return
}
var r_visframecount : int = default<int>

var r_oldviewleaf : int = default<int>

var r_time1 : float = default<float>

[export, sideeffects]
def R_ViewChanged(var pvrect : int; var lineadj : int; var aspect : float) {
    var res_scale : float
    r_viewchanged = 1u
    R_SetVrect(pvrect, 5200, lineadj)
    let c2da_fresh144 : float = float(2.0lf * tan(double(uint_bits_to_float(uint(c2da_mem[5344]) | uint(c2da_mem[5345]) << 0x8 | uint(c2da_mem[5346]) << 0x10 | uint(c2da_mem[5347]) << 0x18) / 360.0) * 3.141592653589793lf))
    let c2da_fresh145 : uint = float_bits_to_uint(c2da_fresh144)
    c2da_mem[5308] = uint8(c2da_fresh145)
    c2da_mem[5309] = uint8(c2da_fresh145 >> 0x8)
    c2da_mem[5310] = uint8(c2da_fresh145 >> 0x10)
    c2da_mem[5311] = uint8(c2da_fresh145 >> 0x18)
    let c2da_fresh146 : float = float(int(uint(c2da_mem[5200]) | uint(c2da_mem[5201]) << 0x8 | uint(c2da_mem[5202]) << 0x10 | uint(c2da_mem[5203]) << 0x18))
    let c2da_fresh147 : uint = float_bits_to_uint(c2da_fresh146)
    c2da_mem[5268] = uint8(c2da_fresh147)
    c2da_mem[5269] = uint8(c2da_fresh147 >> 0x8)
    c2da_mem[5270] = uint8(c2da_fresh147 >> 0x10)
    c2da_mem[5271] = uint8(c2da_fresh147 >> 0x18)
    let c2da_fresh148 : float = float(double(float(int(uint(c2da_mem[5200]) | uint(c2da_mem[5201]) << 0x8 | uint(c2da_mem[5202]) << 0x10 | uint(c2da_mem[5203]) << 0x18))) - 0.5lf)
    let c2da_fresh149 : uint = float_bits_to_uint(c2da_fresh148)
    c2da_mem[5276] = uint8(c2da_fresh149)
    c2da_mem[5277] = uint8(c2da_fresh149 >> 0x8)
    c2da_mem[5278] = uint8(c2da_fresh149 >> 0x10)
    c2da_mem[5279] = uint8(c2da_fresh149 >> 0x18)
    let c2da_fresh150 : int = (int(uint(c2da_mem[5200]) | uint(c2da_mem[5201]) << 0x8 | uint(c2da_mem[5202]) << 0x10 | uint(c2da_mem[5203]) << 0x18) << 20) + (1 << 19) - 1
    let c2da_fresh151 : uint = uint(c2da_fresh150)
    c2da_mem[5284] = uint8(c2da_fresh151)
    c2da_mem[5285] = uint8(c2da_fresh151 >> 0x8)
    c2da_mem[5286] = uint8(c2da_fresh151 >> 0x10)
    c2da_mem[5287] = uint8(c2da_fresh151 >> 0x18)
    let c2da_fresh152 : float = float(int(uint(c2da_mem[5204]) | uint(c2da_mem[5205]) << 0x8 | uint(c2da_mem[5206]) << 0x10 | uint(c2da_mem[5207]) << 0x18))
    let c2da_fresh153 : uint = float_bits_to_uint(c2da_fresh152)
    c2da_mem[5272] = uint8(c2da_fresh153)
    c2da_mem[5273] = uint8(c2da_fresh153 >> 0x8)
    c2da_mem[5274] = uint8(c2da_fresh153 >> 0x10)
    c2da_mem[5275] = uint8(c2da_fresh153 >> 0x18)
    let c2da_fresh154 : float = float(double(float(int(uint(c2da_mem[5204]) | uint(c2da_mem[5205]) << 0x8 | uint(c2da_mem[5206]) << 0x10 | uint(c2da_mem[5207]) << 0x18))) - 0.5lf)
    let c2da_fresh155 : uint = float_bits_to_uint(c2da_fresh154)
    c2da_mem[5280] = uint8(c2da_fresh155)
    c2da_mem[5281] = uint8(c2da_fresh155 >> 0x8)
    c2da_mem[5282] = uint8(c2da_fresh155 >> 0x10)
    c2da_mem[5283] = uint8(c2da_fresh155 >> 0x18)
    let c2da_fresh156 : int = int(uint(c2da_mem[5200]) | uint(c2da_mem[5201]) << 0x8 | uint(c2da_mem[5202]) << 0x10 | uint(c2da_mem[5203]) << 0x18) + int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18)
    let c2da_fresh157 : uint = uint(c2da_fresh156)
    c2da_mem[5248] = uint8(c2da_fresh157)
    c2da_mem[5249] = uint8(c2da_fresh157 >> 0x8)
    c2da_mem[5250] = uint8(c2da_fresh157 >> 0x10)
    c2da_mem[5251] = uint8(c2da_fresh157 >> 0x18)
    let c2da_fresh158 : int = (int(uint(c2da_mem[5248]) | uint(c2da_mem[5249]) << 0x8 | uint(c2da_mem[5250]) << 0x10 | uint(c2da_mem[5251]) << 0x18) << 20) + (1 << 19) - 1
    let c2da_fresh159 : uint = uint(c2da_fresh158)
    c2da_mem[5288] = uint8(c2da_fresh159)
    c2da_mem[5289] = uint8(c2da_fresh159 >> 0x8)
    c2da_mem[5290] = uint8(c2da_fresh159 >> 0x10)
    c2da_mem[5291] = uint8(c2da_fresh159 >> 0x18)
    let c2da_fresh160 : float = float(int(uint(c2da_mem[5248]) | uint(c2da_mem[5249]) << 0x8 | uint(c2da_mem[5250]) << 0x10 | uint(c2da_mem[5251]) << 0x18))
    let c2da_fresh161 : uint = float_bits_to_uint(c2da_fresh160)
    c2da_mem[5300] = uint8(c2da_fresh161)
    c2da_mem[5301] = uint8(c2da_fresh161 >> 0x8)
    c2da_mem[5302] = uint8(c2da_fresh161 >> 0x10)
    c2da_mem[5303] = uint8(c2da_fresh161 >> 0x18)
    let c2da_fresh162 : float = float(double(float(int(uint(c2da_mem[5248]) | uint(c2da_mem[5249]) << 0x8 | uint(c2da_mem[5250]) << 0x10 | uint(c2da_mem[5251]) << 0x18))) - 0.5lf)
    let c2da_fresh163 : uint = float_bits_to_uint(c2da_fresh162)
    c2da_mem[5292] = uint8(c2da_fresh163)
    c2da_mem[5293] = uint8(c2da_fresh163 >> 0x8)
    c2da_mem[5294] = uint8(c2da_fresh163 >> 0x10)
    c2da_mem[5295] = uint8(c2da_fresh163 >> 0x18)
    let c2da_fresh164 : float = float(double(float(int(uint(c2da_mem[5248]) | uint(c2da_mem[5249]) << 0x8 | uint(c2da_mem[5250]) << 0x10 | uint(c2da_mem[5251]) << 0x18))) - 0.99lf)
    let c2da_fresh165 : uint = float_bits_to_uint(c2da_fresh164)
    c2da_mem[5264] = uint8(c2da_fresh165)
    c2da_mem[5265] = uint8(c2da_fresh165 >> 0x8)
    c2da_mem[5266] = uint8(c2da_fresh165 >> 0x10)
    c2da_mem[5267] = uint8(c2da_fresh165 >> 0x18)
    let c2da_fresh166 : int = int(uint(c2da_mem[5204]) | uint(c2da_mem[5205]) << 0x8 | uint(c2da_mem[5206]) << 0x10 | uint(c2da_mem[5207]) << 0x18) + int(uint(c2da_mem[5212]) | uint(c2da_mem[5213]) << 0x8 | uint(c2da_mem[5214]) << 0x10 | uint(c2da_mem[5215]) << 0x18)
    let c2da_fresh167 : uint = uint(c2da_fresh166)
    c2da_mem[5252] = uint8(c2da_fresh167)
    c2da_mem[5253] = uint8(c2da_fresh167 >> 0x8)
    c2da_mem[5254] = uint8(c2da_fresh167 >> 0x10)
    c2da_mem[5255] = uint8(c2da_fresh167 >> 0x18)
    let c2da_fresh168 : float = float(int(uint(c2da_mem[5252]) | uint(c2da_mem[5253]) << 0x8 | uint(c2da_mem[5254]) << 0x10 | uint(c2da_mem[5255]) << 0x18))
    let c2da_fresh169 : uint = float_bits_to_uint(c2da_fresh168)
    c2da_mem[5304] = uint8(c2da_fresh169)
    c2da_mem[5305] = uint8(c2da_fresh169 >> 0x8)
    c2da_mem[5306] = uint8(c2da_fresh169 >> 0x10)
    c2da_mem[5307] = uint8(c2da_fresh169 >> 0x18)
    let c2da_fresh170 : float = float(double(float(int(uint(c2da_mem[5252]) | uint(c2da_mem[5253]) << 0x8 | uint(c2da_mem[5254]) << 0x10 | uint(c2da_mem[5255]) << 0x18))) - 0.5lf)
    let c2da_fresh171 : uint = float_bits_to_uint(c2da_fresh170)
    c2da_mem[5296] = uint8(c2da_fresh171)
    c2da_mem[5297] = uint8(c2da_fresh171 >> 0x8)
    c2da_mem[5298] = uint8(c2da_fresh171 >> 0x10)
    c2da_mem[5299] = uint8(c2da_fresh171 >> 0x18)
    let c2da_fresh172 : int = int(float(int(uint(c2da_mem[5200]) | uint(c2da_mem[5201]) << 0x8 | uint(c2da_mem[5202]) << 0x10 | uint(c2da_mem[5203]) << 0x18)) * r_aliasuvscale)
    let c2da_fresh173 : uint = uint(c2da_fresh172)
    c2da_mem[5224] = uint8(c2da_fresh173)
    c2da_mem[5225] = uint8(c2da_fresh173 >> 0x8)
    c2da_mem[5226] = uint8(c2da_fresh173 >> 0x10)
    c2da_mem[5227] = uint8(c2da_fresh173 >> 0x18)
    let c2da_fresh174 : int = int(float(int(uint(c2da_mem[5204]) | uint(c2da_mem[5205]) << 0x8 | uint(c2da_mem[5206]) << 0x10 | uint(c2da_mem[5207]) << 0x18)) * r_aliasuvscale)
    let c2da_fresh175 : uint = uint(c2da_fresh174)
    c2da_mem[5228] = uint8(c2da_fresh175)
    c2da_mem[5229] = uint8(c2da_fresh175 >> 0x8)
    c2da_mem[5230] = uint8(c2da_fresh175 >> 0x10)
    c2da_mem[5231] = uint8(c2da_fresh175 >> 0x18)
    let c2da_fresh176 : int = int(float(int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18)) * r_aliasuvscale)
    let c2da_fresh177 : uint = uint(c2da_fresh176)
    c2da_mem[5232] = uint8(c2da_fresh177)
    c2da_mem[5233] = uint8(c2da_fresh177 >> 0x8)
    c2da_mem[5234] = uint8(c2da_fresh177 >> 0x10)
    c2da_mem[5235] = uint8(c2da_fresh177 >> 0x18)
    let c2da_fresh178 : int = int(float(int(uint(c2da_mem[5212]) | uint(c2da_mem[5213]) << 0x8 | uint(c2da_mem[5214]) << 0x10 | uint(c2da_mem[5215]) << 0x18)) * r_aliasuvscale)
    let c2da_fresh179 : uint = uint(c2da_fresh178)
    c2da_mem[5236] = uint8(c2da_fresh179)
    c2da_mem[5237] = uint8(c2da_fresh179 >> 0x8)
    c2da_mem[5238] = uint8(c2da_fresh179 >> 0x10)
    c2da_mem[5239] = uint8(c2da_fresh179 >> 0x18)
    let c2da_fresh180 : int = int(uint(c2da_mem[5224]) | uint(c2da_mem[5225]) << 0x8 | uint(c2da_mem[5226]) << 0x10 | uint(c2da_mem[5227]) << 0x18) + int(uint(c2da_mem[5232]) | uint(c2da_mem[5233]) << 0x8 | uint(c2da_mem[5234]) << 0x10 | uint(c2da_mem[5235]) << 0x18)
    let c2da_fresh181 : uint = uint(c2da_fresh180)
    c2da_mem[5256] = uint8(c2da_fresh181)
    c2da_mem[5257] = uint8(c2da_fresh181 >> 0x8)
    c2da_mem[5258] = uint8(c2da_fresh181 >> 0x10)
    c2da_mem[5259] = uint8(c2da_fresh181 >> 0x18)
    let c2da_fresh182 : int = int(uint(c2da_mem[5228]) | uint(c2da_mem[5229]) << 0x8 | uint(c2da_mem[5230]) << 0x10 | uint(c2da_mem[5231]) << 0x18) + int(uint(c2da_mem[5236]) | uint(c2da_mem[5237]) << 0x8 | uint(c2da_mem[5238]) << 0x10 | uint(c2da_mem[5239]) << 0x18)
    let c2da_fresh183 : uint = uint(c2da_fresh182)
    c2da_mem[5260] = uint8(c2da_fresh183)
    c2da_mem[5261] = uint8(c2da_fresh183 >> 0x8)
    c2da_mem[5262] = uint8(c2da_fresh183 >> 0x10)
    c2da_mem[5263] = uint8(c2da_fresh183 >> 0x18)
    pixelAspect = float(aspect)  // nolint:PERF020
    xOrigin = uint_bits_to_float(uint(c2da_mem[5312]) | uint(c2da_mem[5313]) << 0x8 | uint(c2da_mem[5314]) << 0x10 | uint(c2da_mem[5315]) << 0x18)
    yOrigin = uint_bits_to_float(uint(c2da_mem[5316]) | uint(c2da_mem[5317]) << 0x8 | uint(c2da_mem[5318]) << 0x10 | uint(c2da_mem[5319]) << 0x18)
    screenAspect = float(int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18)) * pixelAspect / float(int(uint(c2da_mem[5212]) | uint(c2da_mem[5213]) << 0x8 | uint(c2da_mem[5214]) << 0x10 | uint(c2da_mem[5215]) << 0x18))
    verticalFieldOfView = uint_bits_to_float(uint(c2da_mem[5308]) | uint(c2da_mem[5309]) << 0x8 | uint(c2da_mem[5310]) << 0x10 | uint(c2da_mem[5311]) << 0x18) / screenAspect
    xcenter = float(double(float(int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18))) * (1.0lf / 2.0lf) + double(int(uint(c2da_mem[5200]) | uint(c2da_mem[5201]) << 0x8 | uint(c2da_mem[5202]) << 0x10 | uint(c2da_mem[5203]) << 0x18)) - 0.5lf)
    aliasxcenter = xcenter * r_aliasuvscale
    ycenter = float(double(float(int(uint(c2da_mem[5212]) | uint(c2da_mem[5213]) << 0x8 | uint(c2da_mem[5214]) << 0x10 | uint(c2da_mem[5215]) << 0x18))) * (1.0lf / 2.0lf) + double(int(uint(c2da_mem[5204]) | uint(c2da_mem[5205]) << 0x8 | uint(c2da_mem[5206]) << 0x10 | uint(c2da_mem[5207]) << 0x18)) - 0.5lf)
    aliasycenter = ycenter * r_aliasuvscale
    xscale = float(int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18)) / uint_bits_to_float(uint(c2da_mem[5308]) | uint(c2da_mem[5309]) << 0x8 | uint(c2da_mem[5310]) << 0x10 | uint(c2da_mem[5311]) << 0x18)
    aliasxscale = xscale * r_aliasuvscale
    xscaleinv = float(1.0lf / double(xscale))
    yscale = xscale * pixelAspect
    aliasyscale = yscale * r_aliasuvscale
    yscaleinv = float(1.0lf / double(yscale))
    xscaleshrink = float(int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18) - 6) / uint_bits_to_float(uint(c2da_mem[5308]) | uint(c2da_mem[5309]) << 0x8 | uint(c2da_mem[5310]) << 0x10 | uint(c2da_mem[5311]) << 0x18)
    yscaleshrink = xscaleshrink * pixelAspect
    let c2da_fresh184 : float = float(-1.0lf / double(xOrigin * uint_bits_to_float(uint(c2da_mem[5308]) | uint(c2da_mem[5309]) << 0x8 | uint(c2da_mem[5310]) << 0x10 | uint(c2da_mem[5311]) << 0x18)))
    let c2da_fresh185 : uint = float_bits_to_uint(c2da_fresh184)
    c2da_mem[392976 + 0 * 20 + 0 * 4] = uint8(c2da_fresh185)
    c2da_mem[392976 + 0 * 20 + 0 * 4 + 1] = uint8(c2da_fresh185 >> 0x8)
    c2da_mem[392976 + 0 * 20 + 0 * 4 + 2] = uint8(c2da_fresh185 >> 0x10)
    c2da_mem[392976 + 0 * 20 + 0 * 4 + 3] = uint8(c2da_fresh185 >> 0x18)
    let c2da_fresh186 : float = 0.0
    let c2da_fresh187 : uint = float_bits_to_uint(c2da_fresh186)
    c2da_mem[392976 + 0 * 20 + 1 * 4] = uint8(c2da_fresh187)
    c2da_mem[392976 + 0 * 20 + 1 * 4 + 1] = uint8(c2da_fresh187 >> 0x8)
    c2da_mem[392976 + 0 * 20 + 1 * 4 + 2] = uint8(c2da_fresh187 >> 0x10)
    c2da_mem[392976 + 0 * 20 + 1 * 4 + 3] = uint8(c2da_fresh187 >> 0x18)
    let c2da_fresh188 : float = 1.0
    let c2da_fresh189 : uint = float_bits_to_uint(c2da_fresh188)
    c2da_mem[392976 + 0 * 20 + 2 * 4] = uint8(c2da_fresh189)
    c2da_mem[392976 + 0 * 20 + 2 * 4 + 1] = uint8(c2da_fresh189 >> 0x8)
    c2da_mem[392976 + 0 * 20 + 2 * 4 + 2] = uint8(c2da_fresh189 >> 0x10)
    c2da_mem[392976 + 0 * 20 + 2 * 4 + 3] = uint8(c2da_fresh189 >> 0x18)
    let c2da_fresh190 : uint8 = 5u8
    c2da_mem[392976 + 0 * 20 + 16] = c2da_fresh190
    let c2da_fresh191 : float = float(1.0lf / ((1.0lf - double(xOrigin)) * double(uint_bits_to_float(uint(c2da_mem[5308]) | uint(c2da_mem[5309]) << 0x8 | uint(c2da_mem[5310]) << 0x10 | uint(c2da_mem[5311]) << 0x18))))
    let c2da_fresh192 : uint = float_bits_to_uint(c2da_fresh191)
    c2da_mem[392976 + 1 * 20 + 0 * 4] = uint8(c2da_fresh192)
    c2da_mem[392976 + 1 * 20 + 0 * 4 + 1] = uint8(c2da_fresh192 >> 0x8)
    c2da_mem[392976 + 1 * 20 + 0 * 4 + 2] = uint8(c2da_fresh192 >> 0x10)
    c2da_mem[392976 + 1 * 20 + 0 * 4 + 3] = uint8(c2da_fresh192 >> 0x18)
    let c2da_fresh193 : float = 0.0
    let c2da_fresh194 : uint = float_bits_to_uint(c2da_fresh193)
    c2da_mem[392976 + 1 * 20 + 1 * 4] = uint8(c2da_fresh194)
    c2da_mem[392976 + 1 * 20 + 1 * 4 + 1] = uint8(c2da_fresh194 >> 0x8)
    c2da_mem[392976 + 1 * 20 + 1 * 4 + 2] = uint8(c2da_fresh194 >> 0x10)
    c2da_mem[392976 + 1 * 20 + 1 * 4 + 3] = uint8(c2da_fresh194 >> 0x18)
    let c2da_fresh195 : float = 1.0
    let c2da_fresh196 : uint = float_bits_to_uint(c2da_fresh195)
    c2da_mem[392976 + 1 * 20 + 2 * 4] = uint8(c2da_fresh196)
    c2da_mem[392976 + 1 * 20 + 2 * 4 + 1] = uint8(c2da_fresh196 >> 0x8)
    c2da_mem[392976 + 1 * 20 + 2 * 4 + 2] = uint8(c2da_fresh196 >> 0x10)
    c2da_mem[392976 + 1 * 20 + 2 * 4 + 3] = uint8(c2da_fresh196 >> 0x18)
    let c2da_fresh197 : uint8 = 5u8
    c2da_mem[392976 + 1 * 20 + 16] = c2da_fresh197
    let c2da_fresh198 : float = 0.0
    let c2da_fresh199 : uint = float_bits_to_uint(c2da_fresh198)
    c2da_mem[392976 + 2 * 20 + 0 * 4] = uint8(c2da_fresh199)
    c2da_mem[392976 + 2 * 20 + 0 * 4 + 1] = uint8(c2da_fresh199 >> 0x8)
    c2da_mem[392976 + 2 * 20 + 0 * 4 + 2] = uint8(c2da_fresh199 >> 0x10)
    c2da_mem[392976 + 2 * 20 + 0 * 4 + 3] = uint8(c2da_fresh199 >> 0x18)
    let c2da_fresh200 : float = float(-1.0lf / double(yOrigin * verticalFieldOfView))
    let c2da_fresh201 : uint = float_bits_to_uint(c2da_fresh200)
    c2da_mem[392976 + 2 * 20 + 1 * 4] = uint8(c2da_fresh201)
    c2da_mem[392976 + 2 * 20 + 1 * 4 + 1] = uint8(c2da_fresh201 >> 0x8)
    c2da_mem[392976 + 2 * 20 + 1 * 4 + 2] = uint8(c2da_fresh201 >> 0x10)
    c2da_mem[392976 + 2 * 20 + 1 * 4 + 3] = uint8(c2da_fresh201 >> 0x18)
    let c2da_fresh202 : float = 1.0
    let c2da_fresh203 : uint = float_bits_to_uint(c2da_fresh202)
    c2da_mem[392976 + 2 * 20 + 2 * 4] = uint8(c2da_fresh203)
    c2da_mem[392976 + 2 * 20 + 2 * 4 + 1] = uint8(c2da_fresh203 >> 0x8)
    c2da_mem[392976 + 2 * 20 + 2 * 4 + 2] = uint8(c2da_fresh203 >> 0x10)
    c2da_mem[392976 + 2 * 20 + 2 * 4 + 3] = uint8(c2da_fresh203 >> 0x18)
    let c2da_fresh204 : uint8 = 5u8
    c2da_mem[392976 + 2 * 20 + 16] = c2da_fresh204
    let c2da_fresh205 : float = 0.0
    let c2da_fresh206 : uint = float_bits_to_uint(c2da_fresh205)
    c2da_mem[392976 + 3 * 20 + 0 * 4] = uint8(c2da_fresh206)
    c2da_mem[392976 + 3 * 20 + 0 * 4 + 1] = uint8(c2da_fresh206 >> 0x8)
    c2da_mem[392976 + 3 * 20 + 0 * 4 + 2] = uint8(c2da_fresh206 >> 0x10)
    c2da_mem[392976 + 3 * 20 + 0 * 4 + 3] = uint8(c2da_fresh206 >> 0x18)
    let c2da_fresh207 : float = float(1.0lf / ((1.0lf - double(yOrigin)) * double(verticalFieldOfView)))
    let c2da_fresh208 : uint = float_bits_to_uint(c2da_fresh207)
    c2da_mem[392976 + 3 * 20 + 1 * 4] = uint8(c2da_fresh208)
    c2da_mem[392976 + 3 * 20 + 1 * 4 + 1] = uint8(c2da_fresh208 >> 0x8)
    c2da_mem[392976 + 3 * 20 + 1 * 4 + 2] = uint8(c2da_fresh208 >> 0x10)
    c2da_mem[392976 + 3 * 20 + 1 * 4 + 3] = uint8(c2da_fresh208 >> 0x18)
    let c2da_fresh209 : float = 1.0
    let c2da_fresh210 : uint = float_bits_to_uint(c2da_fresh209)
    c2da_mem[392976 + 3 * 20 + 2 * 4] = uint8(c2da_fresh210)
    c2da_mem[392976 + 3 * 20 + 2 * 4 + 1] = uint8(c2da_fresh210 >> 0x8)
    c2da_mem[392976 + 3 * 20 + 2 * 4 + 2] = uint8(c2da_fresh210 >> 0x10)
    c2da_mem[392976 + 3 * 20 + 2 * 4 + 3] = uint8(c2da_fresh210 >> 0x18)
    let c2da_fresh211 : uint8 = 5u8
    c2da_mem[392976 + 3 * 20 + 16] = c2da_fresh211
    for (i_4 in range(0, 4)) {
        VectorNormalize(392976 + i_4 * 20)
    }
    res_scale = float(sqrt(double(int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18) * int(uint(c2da_mem[5212]) | uint(c2da_mem[5213]) << 0x8 | uint(c2da_mem[5214]) << 0x10 | uint(c2da_mem[5215]) << 0x18)) / (320.0lf * 152.0lf)) * (2.0lf / double(uint_bits_to_float(uint(c2da_mem[5308]) | uint(c2da_mem[5309]) << 0x8 | uint(c2da_mem[5310]) << 0x10 | uint(c2da_mem[5311]) << 0x18))))
    r_aliastransition = uint_bits_to_float(uint(c2da_mem[392856]) | uint(c2da_mem[392857]) << 0x8 | uint(c2da_mem[392858]) << 0x10 | uint(c2da_mem[392859]) << 0x18) * res_scale
    r_resfudge = uint_bits_to_float(uint(c2da_mem[392904]) | uint(c2da_mem[392905]) << 0x8 | uint(c2da_mem[392906]) << 0x10 | uint(c2da_mem[392907]) << 0x18) * res_scale
    if (double(uint_bits_to_float(uint(c2da_mem[461128]) | uint(c2da_mem[461129]) << 0x8 | uint(c2da_mem[461130]) << 0x10 | uint(c2da_mem[461131]) << 0x18)) <= 90.0lf) {
        r_fov_greater_than_90 = 0u
    } else {
        r_fov_greater_than_90 = 1u
    }
    D_ViewChanged()
    return
}
var r_resfudge : float = default<float>

var r_aliastransition : float = default<float>

var verticalFieldOfView : float = default<float>

var yOrigin : float = default<float>

var xOrigin : float = default<float>

var pixelAspect : float = default<float>

var xscaleshrink : float = default<float>

var yscaleshrink : float = default<float>

var yscale : float = default<float>

var yscaleinv : float = default<float>

var r_aliasuvscale : float = 1.0

var aliasyscale : float = default<float>

var xscale : float = default<float>

var xscaleinv : float = default<float>

var aliasxscale : float = default<float>

var ycenter : float = default<float>

var aliasycenter : float = default<float>

var xcenter : float = default<float>

var aliasxcenter : float = default<float>

var screenAspect : float = default<float>

[export, sideeffects]
def R_SetVrect(var pvrectin : int; var pvrect_0 : int; var lineadj_0 : int) {
    var h : int
    var size : float = uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18) > 100.0 ? 100.0 : uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18)
    if (int(uint(c2da_mem[756]) | uint(c2da_mem[757]) << 0x8 | uint(c2da_mem[758]) << 0x10 | uint(c2da_mem[759]) << 0x18) != 0) {
        size = 100.0
        lineadj_0 = 0
    }
    size /= 100.0
    h = int(uint(c2da_mem[pvrectin + 12]) | uint(c2da_mem[pvrectin + 13]) << 0x8 | uint(c2da_mem[pvrectin + 14]) << 0x10 | uint(c2da_mem[pvrectin + 15]) << 0x18) - lineadj_0
    let c2da_fresh212 : int = int(float(int(uint(c2da_mem[pvrectin + 8]) | uint(c2da_mem[pvrectin + 9]) << 0x8 | uint(c2da_mem[pvrectin + 10]) << 0x10 | uint(c2da_mem[pvrectin + 11]) << 0x18)) * size)
    let c2da_fresh213 : uint = uint(c2da_fresh212)
    c2da_mem[pvrect_0 + 8] = uint8(c2da_fresh213)
    c2da_mem[pvrect_0 + 9] = uint8(c2da_fresh213 >> 0x8)
    c2da_mem[pvrect_0 + 10] = uint8(c2da_fresh213 >> 0x10)
    c2da_mem[pvrect_0 + 11] = uint8(c2da_fresh213 >> 0x18)
    if (int(uint(c2da_mem[pvrect_0 + 8]) | uint(c2da_mem[pvrect_0 + 9]) << 0x8 | uint(c2da_mem[pvrect_0 + 10]) << 0x10 | uint(c2da_mem[pvrect_0 + 11]) << 0x18) < 96) {
        size = float(96.0lf / double(int(uint(c2da_mem[pvrectin + 8]) | uint(c2da_mem[pvrectin + 9]) << 0x8 | uint(c2da_mem[pvrectin + 10]) << 0x10 | uint(c2da_mem[pvrectin + 11]) << 0x18)))
        let c2da_fresh214 : int = 96
        let c2da_fresh215 : uint = uint(c2da_fresh214)
        c2da_mem[pvrect_0 + 8] = uint8(c2da_fresh215)
        c2da_mem[pvrect_0 + 9] = uint8(c2da_fresh215 >> 0x8)
        c2da_mem[pvrect_0 + 10] = uint8(c2da_fresh215 >> 0x10)
        c2da_mem[pvrect_0 + 11] = uint8(c2da_fresh215 >> 0x18)
    }
    let c2da_fresh216 : int = int(uint(c2da_mem[pvrect_0 + 8]) | uint(c2da_mem[pvrect_0 + 9]) << 0x8 | uint(c2da_mem[pvrect_0 + 10]) << 0x10 | uint(c2da_mem[pvrect_0 + 11]) << 0x18) & ~7
    let c2da_fresh217 : uint = uint(c2da_fresh216)
    c2da_mem[pvrect_0 + 8] = uint8(c2da_fresh217)
    c2da_mem[pvrect_0 + 9] = uint8(c2da_fresh217 >> 0x8)
    c2da_mem[pvrect_0 + 10] = uint8(c2da_fresh217 >> 0x10)
    c2da_mem[pvrect_0 + 11] = uint8(c2da_fresh217 >> 0x18)
    let c2da_fresh218 : int = int(float(int(uint(c2da_mem[pvrectin + 12]) | uint(c2da_mem[pvrectin + 13]) << 0x8 | uint(c2da_mem[pvrectin + 14]) << 0x10 | uint(c2da_mem[pvrectin + 15]) << 0x18)) * size)
    let c2da_fresh219 : uint = uint(c2da_fresh218)
    c2da_mem[pvrect_0 + 12] = uint8(c2da_fresh219)
    c2da_mem[pvrect_0 + 13] = uint8(c2da_fresh219 >> 0x8)
    c2da_mem[pvrect_0 + 14] = uint8(c2da_fresh219 >> 0x10)
    c2da_mem[pvrect_0 + 15] = uint8(c2da_fresh219 >> 0x18)
    if (int(uint(c2da_mem[pvrect_0 + 12]) | uint(c2da_mem[pvrect_0 + 13]) << 0x8 | uint(c2da_mem[pvrect_0 + 14]) << 0x10 | uint(c2da_mem[pvrect_0 + 15]) << 0x18) > int(uint(c2da_mem[pvrectin + 12]) | uint(c2da_mem[pvrectin + 13]) << 0x8 | uint(c2da_mem[pvrectin + 14]) << 0x10 | uint(c2da_mem[pvrectin + 15]) << 0x18) - lineadj_0) {
        let c2da_fresh220 : int = int(uint(c2da_mem[pvrectin + 12]) | uint(c2da_mem[pvrectin + 13]) << 0x8 | uint(c2da_mem[pvrectin + 14]) << 0x10 | uint(c2da_mem[pvrectin + 15]) << 0x18) - lineadj_0
        let c2da_fresh221 : uint = uint(c2da_fresh220)
        c2da_mem[pvrect_0 + 12] = uint8(c2da_fresh221)
        c2da_mem[pvrect_0 + 13] = uint8(c2da_fresh221 >> 0x8)
        c2da_mem[pvrect_0 + 14] = uint8(c2da_fresh221 >> 0x10)
        c2da_mem[pvrect_0 + 15] = uint8(c2da_fresh221 >> 0x18)
    }
    let c2da_fresh222 : int = int(uint(c2da_mem[pvrect_0 + 12]) | uint(c2da_mem[pvrect_0 + 13]) << 0x8 | uint(c2da_mem[pvrect_0 + 14]) << 0x10 | uint(c2da_mem[pvrect_0 + 15]) << 0x18) & ~1
    let c2da_fresh223 : uint = uint(c2da_fresh222)
    c2da_mem[pvrect_0 + 12] = uint8(c2da_fresh223)
    c2da_mem[pvrect_0 + 13] = uint8(c2da_fresh223 >> 0x8)
    c2da_mem[pvrect_0 + 14] = uint8(c2da_fresh223 >> 0x10)
    c2da_mem[pvrect_0 + 15] = uint8(c2da_fresh223 >> 0x18)
    let c2da_fresh224 : int = (int(uint(c2da_mem[pvrectin + 8]) | uint(c2da_mem[pvrectin + 9]) << 0x8 | uint(c2da_mem[pvrectin + 10]) << 0x10 | uint(c2da_mem[pvrectin + 11]) << 0x18) - int(uint(c2da_mem[pvrect_0 + 8]) | uint(c2da_mem[pvrect_0 + 9]) << 0x8 | uint(c2da_mem[pvrect_0 + 10]) << 0x10 | uint(c2da_mem[pvrect_0 + 11]) << 0x18)) / 2
    let c2da_fresh225 : uint = uint(c2da_fresh224)
    c2da_mem[pvrect_0] = uint8(c2da_fresh225)
    c2da_mem[pvrect_0 + 1] = uint8(c2da_fresh225 >> 0x8)
    c2da_mem[pvrect_0 + 2] = uint8(c2da_fresh225 >> 0x10)
    c2da_mem[pvrect_0 + 3] = uint8(c2da_fresh225 >> 0x18)
    let c2da_fresh226 : int = (h - int(uint(c2da_mem[pvrect_0 + 12]) | uint(c2da_mem[pvrect_0 + 13]) << 0x8 | uint(c2da_mem[pvrect_0 + 14]) << 0x10 | uint(c2da_mem[pvrect_0 + 15]) << 0x18)) / 2
    let c2da_fresh227 : uint = uint(c2da_fresh226)
    c2da_mem[pvrect_0 + 4] = uint8(c2da_fresh227)
    c2da_mem[pvrect_0 + 5] = uint8(c2da_fresh227 >> 0x8)
    c2da_mem[pvrect_0 + 6] = uint8(c2da_fresh227 >> 0x10)
    c2da_mem[pvrect_0 + 7] = uint8(c2da_fresh227 >> 0x18)
    if (uint_bits_to_float(uint(c2da_mem[695816]) | uint(c2da_mem[695817]) << 0x8 | uint(c2da_mem[695818]) << 0x10 | uint(c2da_mem[695819]) << 0x18) != 0.0) {
        let c2da_fresh228 : int = int(uint(c2da_mem[pvrect_0 + 4]) | uint(c2da_mem[pvrect_0 + 5]) << 0x8 | uint(c2da_mem[pvrect_0 + 6]) << 0x10 | uint(c2da_mem[pvrect_0 + 7]) << 0x18) >> 1
        let c2da_fresh229 : uint = uint(c2da_fresh228)
        c2da_mem[pvrect_0 + 4] = uint8(c2da_fresh229)
        c2da_mem[pvrect_0 + 5] = uint8(c2da_fresh229 >> 0x8)
        c2da_mem[pvrect_0 + 6] = uint8(c2da_fresh229 >> 0x10)
        c2da_mem[pvrect_0 + 7] = uint8(c2da_fresh229 >> 0x18)
        let c2da_fresh230 : int = int(uint(c2da_mem[pvrect_0 + 12]) | uint(c2da_mem[pvrect_0 + 13]) << 0x8 | uint(c2da_mem[pvrect_0 + 14]) << 0x10 | uint(c2da_mem[pvrect_0 + 15]) << 0x18) >> 1
        let c2da_fresh231 : uint = uint(c2da_fresh230)
        c2da_mem[pvrect_0 + 12] = uint8(c2da_fresh231)
        c2da_mem[pvrect_0 + 13] = uint8(c2da_fresh231 >> 0x8)
        c2da_mem[pvrect_0 + 14] = uint8(c2da_fresh231 >> 0x10)
        c2da_mem[pvrect_0 + 15] = uint8(c2da_fresh231 >> 0x18)
    }
    return
}
var r_viewchanged : uint = default<uint>

[export, sideeffects]
def R_NewMap() {
    var i_5 : int = 0
    while (true) {
        let c2da_fresh232 : int = int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) + 152
        if (i_5 >= int(uint(c2da_mem[c2da_fresh232]) | uint(c2da_mem[c2da_fresh232 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh232 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh232 + 3]) << 0x18)) {
            break
        }
        let c2da_fresh233 : int = int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) + 160
        let c2da_fresh234 : int = int(uint(c2da_mem[c2da_fresh233]) | uint(c2da_mem[c2da_fresh233 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh233 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh233 + 3]) << 0x18) + i_5 * 72 + 40
        let c2da_fresh235 : uint = 0u
        c2da_mem[c2da_fresh234] = uint8(c2da_fresh235)
        c2da_mem[c2da_fresh234 + 1] = uint8(c2da_fresh235 >> 0x8)
        c2da_mem[c2da_fresh234 + 2] = uint8(c2da_fresh235 >> 0x10)
        c2da_mem[c2da_fresh234 + 3] = uint8(c2da_fresh235 >> 0x18)
        c2da_mem[c2da_fresh234 + 4] = 0u8
        c2da_mem[c2da_fresh234 + 5] = 0u8
        c2da_mem[c2da_fresh234 + 6] = 0u8
        c2da_mem[c2da_fresh234 + 7] = 0u8
        i_5++
    }
    r_viewleaf = 0
    R_ClearParticles()
    r_cnumsurfs = int(uint_bits_to_float(uint(c2da_mem[392616]) | uint(c2da_mem[392617]) << 0x8 | uint(c2da_mem[392618]) << 0x10 | uint(c2da_mem[392619]) << 0x18))
    if (r_cnumsurfs <= 800) {
        r_cnumsurfs = 800
    }
    if (r_cnumsurfs > 800) {
        surfaces = Hunk_AllocName(int(uint64(r_cnumsurfs) * 88ul), 733238)
        surface_p = surfaces
        surf_max = surfaces + r_cnumsurfs * 88
        r_surfsonstack = 0u
        surfaces = surfaces - 88
        R_SurfacePatch()
    } else {
        r_surfsonstack = 1u
    }
    r_maxedgesseen = 0
    r_maxsurfsseen = 0
    r_numallocatededges = int(uint_bits_to_float(uint(c2da_mem[392760]) | uint(c2da_mem[392761]) << 0x8 | uint(c2da_mem[392762]) << 0x10 | uint(c2da_mem[392763]) << 0x18))
    if (r_numallocatededges < 2400) {
        r_numallocatededges = 2400
    }
    if (r_numallocatededges <= 2400) {
        auxedges = 0
    } else {
        auxedges = Hunk_AllocName(int(uint64(r_numallocatededges) * 56ul), 733247)
    }
    r_dowarpold = 0u
    r_viewchanged = 0u
    return
}
var r_dowarpold : uint = default<uint>

var r_numallocatededges : int = default<int>

var r_maxsurfsseen : int = default<int>

var r_maxedgesseen : int = default<int>

var d_spanpixcount : int = default<int>

var r_worldpolysbacktofront : uint = default<uint>

var r_recursiveaffinetriangles : uint = 1u

var c_surf : int = default<int>

var screenwidth : int = default<int>

var r_drawnpolycount : int = default<int>

var d_lightstylevalue : int[256]

var r_polycount : int = default<int>

var r_wholepolycount : int = default<int>

var numbtofpolys : int = default<int>

var pbtofpolys : int = default<int>

var colormap : int = default<int>

var viewmodname : int8[257]

var modcount : int = default<int>

[sideeffects]
def private R_Init_c2da_frame(c2da_fp : int) {
    r_stack_start = int(c2da_fp)  // nolint:PERF020
    R_InitTurb()
    Cmd_AddCommand(733026, 209)
    Cmd_AddCommand(733038, 210)
    Cvar_RegisterVariable(391920)
    Cvar_RegisterVariable(391968)
    Cvar_RegisterVariable(392016)
    Cvar_RegisterVariable(392064)
    Cvar_RegisterVariable(392112)
    Cvar_RegisterVariable(392160)
    Cvar_RegisterVariable(392208)
    Cvar_RegisterVariable(392256)
    Cvar_RegisterVariable(392304)
    Cvar_RegisterVariable(392352)
    Cvar_RegisterVariable(392400)
    Cvar_RegisterVariable(392448)
    Cvar_RegisterVariable(392496)
    Cvar_RegisterVariable(392544)
    Cvar_RegisterVariable(392592)
    Cvar_RegisterVariable(392640)
    Cvar_RegisterVariable(392688)
    Cvar_RegisterVariable(392736)
    Cvar_RegisterVariable(392784)
    Cvar_RegisterVariable(392832)
    Cvar_RegisterVariable(392880)
    Cvar_SetValue(732963, 2400.0)
    Cvar_SetValue(732925, 800.0)
    let c2da_fresh0 : uint8 = 1u8
    c2da_mem[391440 + 0 * 32 + 24] = c2da_fresh0
    let c2da_fresh1 : uint8 = 1u8
    c2da_mem[391440 + 1 * 32 + 25] = c2da_fresh1
    let c2da_fresh2 : uint8 = 0u8
    c2da_mem[391440 + 3 * 32 + 24] = c2da_fresh2
    c2da_mem[391440 + 2 * 32 + 24] = c2da_fresh2
    c2da_mem[391440 + 1 * 32 + 24] = c2da_fresh2
    let c2da_fresh3 : uint8 = 0u8
    c2da_mem[391440 + 3 * 32 + 25] = c2da_fresh3
    c2da_mem[391440 + 2 * 32 + 25] = c2da_fresh3
    c2da_mem[391440 + 0 * 32 + 25] = c2da_fresh3
    let c2da_fresh4 : float = float(1.0lf / 2.0lf)
    let c2da_fresh5 : uint = float_bits_to_uint(c2da_fresh4)
    c2da_mem[5312] = uint8(c2da_fresh5)
    c2da_mem[5313] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[5314] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[5315] = uint8(c2da_fresh5 >> 0x18)
    let c2da_fresh6 : float = float(1.0lf / 2.0lf)
    let c2da_fresh7 : uint = float_bits_to_uint(c2da_fresh6)
    c2da_mem[5316] = uint8(c2da_fresh7)
    c2da_mem[5317] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[5318] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[5319] = uint8(c2da_fresh7 >> 0x18)
    R_InitParticles()
    D_Init()
    return
}
[sideeffects]
def private R_RenderView_c2da_frame(c2da_fp : int) {
    var delta : int = c2da_fp - r_stack_start
    if (delta < -10000 || delta > 10000) {
        Sys_Error(733058, [])
    }
    if ((Hunk_LowMark() & 3) != 0) {
        Sys_Error(733100, [])
    }
    if ((int64(c2da_fp) & 3l) != 0) {
        Sys_Error(733120, [])
    }
    if ((392928l & 3l) != 0) {
        Sys_Error(733141, [])
    }
    R_RenderView_()
    return
}
[sideeffects]
def private R_RenderView__c2da_frame(c2da_fp : int) {
    let c2da_fresh27 : uint = uint(c2da_fp)
    c2da_mem[392928] = uint8(c2da_fresh27)
    c2da_mem[392929] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[392930] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[392931] = uint8(c2da_fresh27 >> 0x18)
    c2da_mem[392932] = 0u8
    c2da_mem[392933] = 0u8
    c2da_mem[392934] = 0u8
    c2da_mem[392935] = 0u8
    if (uint_bits_to_float(uint(c2da_mem[392040]) | uint(c2da_mem[392041]) << 0x8 | uint(c2da_mem[392042]) << 0x10 | uint(c2da_mem[392043]) << 0x18) != 0.0 || uint_bits_to_float(uint(c2da_mem[391992]) | uint(c2da_mem[391993]) << 0x8 | uint(c2da_mem[391994]) << 0x10 | uint(c2da_mem[391995]) << 0x18) != 0.0 || uint_bits_to_float(uint(c2da_mem[392520]) | uint(c2da_mem[392521]) << 0x8 | uint(c2da_mem[392522]) << 0x10 | uint(c2da_mem[392523]) << 0x18) != 0.0) {
        r_time1 = float(Sys_FloatTime())
    }
    R_SetupFrame()
    R_MarkLeaves()
    Sys_LowFPPrecision()
    if (int(uint(c2da_mem[10048 + 0 * 200 + 136]) | uint(c2da_mem[10048 + 0 * 200 + 137]) << 0x8 | uint(c2da_mem[10048 + 0 * 200 + 138]) << 0x10 | uint(c2da_mem[10048 + 0 * 200 + 139]) << 0x18) == 0 || int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) == 0) {
        Sys_Error(733165, [])
    }
    if (uint_bits_to_float(uint(c2da_mem[392520]) | uint(c2da_mem[392521]) << 0x8 | uint(c2da_mem[392522]) << 0x10 | uint(c2da_mem[392523]) << 0x18) == 0.0) {
        S_ExtraUpdate()
    }
    R_EdgeDrawing()
    if (uint_bits_to_float(uint(c2da_mem[392520]) | uint(c2da_mem[392521]) << 0x8 | uint(c2da_mem[392522]) << 0x10 | uint(c2da_mem[392523]) << 0x18) == 0.0) {
        S_ExtraUpdate()
    }
    if (uint_bits_to_float(uint(c2da_mem[392520]) | uint(c2da_mem[392521]) << 0x8 | uint(c2da_mem[392522]) << 0x10 | uint(c2da_mem[392523]) << 0x18) != 0.0) {
        se_time2 = float(Sys_FloatTime())
        de_time1 = float(se_time2)  // nolint:PERF020
    }
    R_DrawEntitiesOnList()
    if (uint_bits_to_float(uint(c2da_mem[392520]) | uint(c2da_mem[392521]) << 0x8 | uint(c2da_mem[392522]) << 0x10 | uint(c2da_mem[392523]) << 0x18) != 0.0) {
        de_time2 = float(Sys_FloatTime())
        dv_time1 = float(de_time2)  // nolint:PERF020
    }
    R_DrawViewModel()
    if (uint_bits_to_float(uint(c2da_mem[392520]) | uint(c2da_mem[392521]) << 0x8 | uint(c2da_mem[392522]) << 0x10 | uint(c2da_mem[392523]) << 0x18) != 0.0) {
        dv_time2 = float(Sys_FloatTime())
        dp_time1 = float(Sys_FloatTime())
    }
    R_DrawParticles()
    if (uint_bits_to_float(uint(c2da_mem[392520]) | uint(c2da_mem[392521]) << 0x8 | uint(c2da_mem[392522]) << 0x10 | uint(c2da_mem[392523]) << 0x18) != 0.0) {
        dp_time2 = float(Sys_FloatTime())
    }
    if (r_dowarp != 0u) {
        D_WarpScreen()
    }
    V_SetContentsColor(int(uint(c2da_mem[r_viewleaf]) | uint(c2da_mem[r_viewleaf + 1]) << 0x8 | uint(c2da_mem[r_viewleaf + 2]) << 0x10 | uint(c2da_mem[r_viewleaf + 3]) << 0x18))
    if (uint_bits_to_float(uint(c2da_mem[392040]) | uint(c2da_mem[392041]) << 0x8 | uint(c2da_mem[392042]) << 0x10 | uint(c2da_mem[392043]) << 0x18) != 0.0) {
        R_TimeGraph()
    }
    if (uint_bits_to_float(uint(c2da_mem[392472]) | uint(c2da_mem[392473]) << 0x8 | uint(c2da_mem[392474]) << 0x10 | uint(c2da_mem[392475]) << 0x18) != 0.0) {
        R_PrintAliasStats()
    }
    if (uint_bits_to_float(uint(c2da_mem[391992]) | uint(c2da_mem[391993]) << 0x8 | uint(c2da_mem[391994]) << 0x10 | uint(c2da_mem[391995]) << 0x18) != 0.0) {
        R_PrintTimes()
    }
    if (uint_bits_to_float(uint(c2da_mem[392520]) | uint(c2da_mem[392521]) << 0x8 | uint(c2da_mem[392522]) << 0x10 | uint(c2da_mem[392523]) << 0x18) != 0.0) {
        R_PrintDSpeeds()
    }
    if (uint_bits_to_float(uint(c2da_mem[392568]) | uint(c2da_mem[392569]) << 0x8 | uint(c2da_mem[392570]) << 0x10 | uint(c2da_mem[392571]) << 0x18) != 0.0 && r_outofsurfaces != 0) {
        Con_Printf(733195, [C2daVaArg(tag = 1, i64 = int64(r_outofsurfaces), f64 = 0.0lf, raw = 0x0)])
    }
    if (uint_bits_to_float(uint(c2da_mem[392712]) | uint(c2da_mem[392713]) << 0x8 | uint(c2da_mem[392714]) << 0x10 | uint(c2da_mem[392715]) << 0x18) != 0.0 && r_outofedges != 0) {
        Con_Printf(733214, [C2daVaArg(tag = 1, i64 = int64(r_outofedges * 2 / 3), f64 = 0.0lf, raw = 0x0)])
    }
    Sys_HighFPPrecision()
    return
}
[sideeffects]
def private R_DrawViewModel_c2da_frame(c2da_fp : int) {
    var j : int
    var add : float
    var dl : int
    c2da_mem[c2da_fp + 16] = 0u8
    c2da_mem[c2da_fp + 17] = 0u8
    c2da_mem[c2da_fp + 18] = 128u8
    c2da_mem[c2da_fp + 19] = 191u8
    c2da_mem[c2da_fp + 20] = 0u8
    c2da_mem[c2da_fp + 21] = 0u8
    c2da_mem[c2da_fp + 22] = 0u8
    c2da_mem[c2da_fp + 23] = 0u8
    c2da_mem[c2da_fp + 24] = 0u8
    c2da_mem[c2da_fp + 25] = 0u8
    c2da_mem[c2da_fp + 26] = 0u8
    c2da_mem[c2da_fp + 27] = 0u8
    if (uint_bits_to_float(uint(c2da_mem[392424]) | uint(c2da_mem[392425]) << 0x8 | uint(c2da_mem[392426]) << 0x10 | uint(c2da_mem[392427]) << 0x18) == 0.0 || r_fov_greater_than_90 != 0x0) {
        return
    }
    if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 524288) != 0) {
        return
    }
    if (int(uint(c2da_mem[236 + 0 * 4]) | uint(c2da_mem[236 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 0 * 4 + 3]) << 0x18) <= 0) {
        return
    }
    currententity = 4984
    if (int(uint(c2da_mem[currententity + 136]) | uint(c2da_mem[currententity + 137]) << 0x8 | uint(c2da_mem[currententity + 138]) << 0x10 | uint(c2da_mem[currententity + 139]) << 0x18) == 0) {
        return
    }
    r_entorigin[0] = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 0 * 4]) | uint(c2da_mem[currententity + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 0 * 4 + 3]) << 0x18)
    r_entorigin[1] = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 1 * 4]) | uint(c2da_mem[currententity + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 1 * 4 + 3]) << 0x18)
    r_entorigin[2] = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 2 * 4]) | uint(c2da_mem[currententity + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh28 : float = uint_bits_to_float(uint(c2da_mem[244112 + 0 * 4]) | uint(c2da_mem[244112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 0 * 4 + 3]) << 0x18) - r_entorigin[0]
    let c2da_fresh29 : uint = float_bits_to_uint(c2da_fresh28)
    c2da_mem[204240 + 0 * 4] = uint8(c2da_fresh29)
    c2da_mem[204240 + 0 * 4 + 1] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[204240 + 0 * 4 + 2] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[204240 + 0 * 4 + 3] = uint8(c2da_fresh29 >> 0x18)
    let c2da_fresh30 : float = uint_bits_to_float(uint(c2da_mem[244112 + 1 * 4]) | uint(c2da_mem[244112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 1 * 4 + 3]) << 0x18) - r_entorigin[1]
    let c2da_fresh31 : uint = float_bits_to_uint(c2da_fresh30)
    c2da_mem[204240 + 1 * 4] = uint8(c2da_fresh31)
    c2da_mem[204240 + 1 * 4 + 1] = uint8(c2da_fresh31 >> 0x8)
    c2da_mem[204240 + 1 * 4 + 2] = uint8(c2da_fresh31 >> 0x10)
    c2da_mem[204240 + 1 * 4 + 3] = uint8(c2da_fresh31 >> 0x18)
    let c2da_fresh32 : float = uint_bits_to_float(uint(c2da_mem[244112 + 2 * 4]) | uint(c2da_mem[244112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 2 * 4 + 3]) << 0x18) - r_entorigin[2]
    let c2da_fresh33 : uint = float_bits_to_uint(c2da_fresh32)
    c2da_mem[204240 + 2 * 4] = uint8(c2da_fresh33)
    c2da_mem[204240 + 2 * 4 + 1] = uint8(c2da_fresh33 >> 0x8)
    c2da_mem[204240 + 2 * 4 + 2] = uint8(c2da_fresh33 >> 0x10)
    c2da_mem[204240 + 2 * 4 + 3] = uint8(c2da_fresh33 >> 0x18)
    let c2da_fresh34 : float = uint_bits_to_float(uint(c2da_mem[244160 + 0 * 4]) | uint(c2da_mem[244160 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh35 : uint = float_bits_to_uint(c2da_fresh34)
    c2da_mem[392944 + 0 * 4] = uint8(c2da_fresh35)
    c2da_mem[392944 + 0 * 4 + 1] = uint8(c2da_fresh35 >> 0x8)
    c2da_mem[392944 + 0 * 4 + 2] = uint8(c2da_fresh35 >> 0x10)
    c2da_mem[392944 + 0 * 4 + 3] = uint8(c2da_fresh35 >> 0x18)
    let c2da_fresh36 : float = uint_bits_to_float(uint(c2da_mem[244160 + 1 * 4]) | uint(c2da_mem[244160 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh37 : uint = float_bits_to_uint(c2da_fresh36)
    c2da_mem[392944 + 1 * 4] = uint8(c2da_fresh37)
    c2da_mem[392944 + 1 * 4 + 1] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[392944 + 1 * 4 + 2] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[392944 + 1 * 4 + 3] = uint8(c2da_fresh37 >> 0x18)
    let c2da_fresh38 : float = uint_bits_to_float(uint(c2da_mem[244160 + 2 * 4]) | uint(c2da_mem[244160 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244160 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244160 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh39 : uint = float_bits_to_uint(c2da_fresh38)
    c2da_mem[392944 + 2 * 4] = uint8(c2da_fresh39)
    c2da_mem[392944 + 2 * 4 + 1] = uint8(c2da_fresh39 >> 0x8)
    c2da_mem[392944 + 2 * 4 + 2] = uint8(c2da_fresh39 >> 0x10)
    c2da_mem[392944 + 2 * 4 + 3] = uint8(c2da_fresh39 >> 0x18)
    VectorInverse(392944)
    j = R_LightPoint(currententity + 88)
    if (j < 24) {
        j = 24
    }
    let c2da_fresh40 : uint = uint(j)
    c2da_mem[392960] = uint8(c2da_fresh40)
    c2da_mem[392961] = uint8(c2da_fresh40 >> 0x8)
    c2da_mem[392962] = uint8(c2da_fresh40 >> 0x10)
    c2da_mem[392963] = uint8(c2da_fresh40 >> 0x18)
    let c2da_fresh41 : uint = uint(j)
    c2da_mem[392964] = uint8(c2da_fresh41)
    c2da_mem[392965] = uint8(c2da_fresh41 >> 0x8)
    c2da_mem[392966] = uint8(c2da_fresh41 >> 0x10)
    c2da_mem[392967] = uint8(c2da_fresh41 >> 0x18)
    for (lnum in range(0, 32)) {
        dl = 8112 + lnum * 32
        if (uint_bits_to_float(uint(c2da_mem[dl + 12]) | uint(c2da_mem[dl + 13]) << 0x8 | uint(c2da_mem[dl + 14]) << 0x10 | uint(c2da_mem[dl + 15]) << 0x18) == 0.0) {
            continue
        }
        if (uint_bits_to_float(uint(c2da_mem[dl + 12]) | uint(c2da_mem[dl + 13]) << 0x8 | uint(c2da_mem[dl + 14]) << 0x10 | uint(c2da_mem[dl + 15]) << 0x18) == 0.0) {
            continue
        }
        if (double(uint_bits_to_float(uint(c2da_mem[dl + 16]) | uint(c2da_mem[dl + 17]) << 0x8 | uint(c2da_mem[dl + 18]) << 0x10 | uint(c2da_mem[dl + 19]) << 0x18)) < uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20)) {
            continue
        }
        let c2da_fresh42 : float = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 0 * 4]) | uint(c2da_mem[currententity + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[dl + 0 * 4]) | uint(c2da_mem[dl + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[dl + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[dl + 0 * 4 + 3]) << 0x18)
        let c2da_fresh43 : uint = float_bits_to_uint(c2da_fresh42)
        c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh43)
        c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh43 >> 0x8)
        c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh43 >> 0x10)
        c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh43 >> 0x18)
        let c2da_fresh44 : float = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 1 * 4]) | uint(c2da_mem[currententity + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[dl + 1 * 4]) | uint(c2da_mem[dl + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[dl + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[dl + 1 * 4 + 3]) << 0x18)
        let c2da_fresh45 : uint = float_bits_to_uint(c2da_fresh44)
        c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh45)
        c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh45 >> 0x8)
        c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh45 >> 0x10)
        c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh45 >> 0x18)
        let c2da_fresh46 : float = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 2 * 4]) | uint(c2da_mem[currententity + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[dl + 2 * 4]) | uint(c2da_mem[dl + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[dl + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[dl + 2 * 4 + 3]) << 0x18)
        let c2da_fresh47 : uint = float_bits_to_uint(c2da_fresh46)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh47)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh47 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh47 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh47 >> 0x18)
        add = uint_bits_to_float(uint(c2da_mem[dl + 12]) | uint(c2da_mem[dl + 13]) << 0x8 | uint(c2da_mem[dl + 14]) << 0x10 | uint(c2da_mem[dl + 15]) << 0x18) - Length(c2da_fp)
        if (add > 0.0) {
            let c2da_fresh48 : int = int(float(int(uint(c2da_mem[392960]) | uint(c2da_mem[392961]) << 0x8 | uint(c2da_mem[392962]) << 0x10 | uint(c2da_mem[392963]) << 0x18)) + add)
            let c2da_fresh49 : uint = uint(c2da_fresh48)
            c2da_mem[392960] = uint8(c2da_fresh49)
            c2da_mem[392961] = uint8(c2da_fresh49 >> 0x8)
            c2da_mem[392962] = uint8(c2da_fresh49 >> 0x10)
            c2da_mem[392963] = uint8(c2da_fresh49 >> 0x18)
        }
    }
    if (int(uint(c2da_mem[392960]) | uint(c2da_mem[392961]) << 0x8 | uint(c2da_mem[392962]) << 0x10 | uint(c2da_mem[392963]) << 0x18) > 128) {
        let c2da_fresh50 : int = 128
        let c2da_fresh51 : uint = uint(c2da_fresh50)
        c2da_mem[392960] = uint8(c2da_fresh51)
        c2da_mem[392961] = uint8(c2da_fresh51 >> 0x8)
        c2da_mem[392962] = uint8(c2da_fresh51 >> 0x10)
        c2da_mem[392963] = uint8(c2da_fresh51 >> 0x18)
    }
    if (int(uint(c2da_mem[392960]) | uint(c2da_mem[392961]) << 0x8 | uint(c2da_mem[392962]) << 0x10 | uint(c2da_mem[392963]) << 0x18) + int(uint(c2da_mem[392964]) | uint(c2da_mem[392965]) << 0x8 | uint(c2da_mem[392966]) << 0x10 | uint(c2da_mem[392967]) << 0x18) > 192) {
        let c2da_fresh52 : int = 192 - int(uint(c2da_mem[392960]) | uint(c2da_mem[392961]) << 0x8 | uint(c2da_mem[392962]) << 0x10 | uint(c2da_mem[392963]) << 0x18)
        let c2da_fresh53 : uint = uint(c2da_fresh52)
        c2da_mem[392964] = uint8(c2da_fresh53)
        c2da_mem[392965] = uint8(c2da_fresh53 >> 0x8)
        c2da_mem[392966] = uint8(c2da_fresh53 >> 0x10)
        c2da_mem[392967] = uint8(c2da_fresh53 >> 0x18)
    }
    let c2da_fresh54 : int = c2da_fp + 16
    let c2da_fresh55 : uint = uint(c2da_fresh54)
    c2da_mem[392968] = uint8(c2da_fresh55)
    c2da_mem[392969] = uint8(c2da_fresh55 >> 0x8)
    c2da_mem[392970] = uint8(c2da_fresh55 >> 0x10)
    c2da_mem[392971] = uint8(c2da_fresh55 >> 0x18)
    c2da_mem[392972] = 0u8
    c2da_mem[392973] = 0u8
    c2da_mem[392974] = 0u8
    c2da_mem[392975] = 0u8
    R_AliasDrawModel(392960)
    return
}
[sideeffects]
def private R_DrawEntitiesOnList_c2da_frame(c2da_fp : int) {
    var c2da_fresh57 : uint
    var i_0 : int
    var j_0 : int
    var add_0 : float
    c2da_mem[c2da_fp] = 0u8
    c2da_mem[c2da_fp + 1] = 0u8
    c2da_mem[c2da_fp + 2] = 128u8
    c2da_mem[c2da_fp + 3] = 191u8
    c2da_mem[c2da_fp + 4] = 0u8
    c2da_mem[c2da_fp + 5] = 0u8
    c2da_mem[c2da_fp + 6] = 0u8
    c2da_mem[c2da_fp + 7] = 0u8
    c2da_mem[c2da_fp + 8] = 0u8
    c2da_mem[c2da_fp + 9] = 0u8
    c2da_mem[c2da_fp + 10] = 0u8
    c2da_mem[c2da_fp + 11] = 0u8
    if (uint_bits_to_float(uint(c2da_mem[392376]) | uint(c2da_mem[392377]) << 0x8 | uint(c2da_mem[392378]) << 0x10 | uint(c2da_mem[392379]) << 0x18) == 0.0) {
        return
    }
    i_0 = 0
    while (i_0 < cl_numvisedicts) {
        currententity = cl_visedicts[i_0]
        if (currententity == 10048 + int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18) * 200) {
            i_0++
            continue
        }
        let c2da_fresh56 : int = int(uint(c2da_mem[currententity + 136]) | uint(c2da_mem[currententity + 137]) << 0x8 | uint(c2da_mem[currententity + 138]) << 0x10 | uint(c2da_mem[currententity + 139]) << 0x18) + 68
        c2da_fresh57 = uint(c2da_mem[c2da_fresh56]) | uint(c2da_mem[c2da_fresh56 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh56 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh56 + 3]) << 0x18
        if (c2da_fresh57 == 0x1u) {
            r_entorigin[0] = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 0 * 4]) | uint(c2da_mem[currententity + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 0 * 4 + 3]) << 0x18)
            r_entorigin[1] = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 1 * 4]) | uint(c2da_mem[currententity + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 1 * 4 + 3]) << 0x18)
            r_entorigin[2] = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 2 * 4]) | uint(c2da_mem[currententity + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh58 : float = uint_bits_to_float(uint(c2da_mem[244112 + 0 * 4]) | uint(c2da_mem[244112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 0 * 4 + 3]) << 0x18) - r_entorigin[0]
            let c2da_fresh59 : uint = float_bits_to_uint(c2da_fresh58)
            c2da_mem[204240 + 0 * 4] = uint8(c2da_fresh59)
            c2da_mem[204240 + 0 * 4 + 1] = uint8(c2da_fresh59 >> 0x8)
            c2da_mem[204240 + 0 * 4 + 2] = uint8(c2da_fresh59 >> 0x10)
            c2da_mem[204240 + 0 * 4 + 3] = uint8(c2da_fresh59 >> 0x18)
            let c2da_fresh60 : float = uint_bits_to_float(uint(c2da_mem[244112 + 1 * 4]) | uint(c2da_mem[244112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 1 * 4 + 3]) << 0x18) - r_entorigin[1]
            let c2da_fresh61 : uint = float_bits_to_uint(c2da_fresh60)
            c2da_mem[204240 + 1 * 4] = uint8(c2da_fresh61)
            c2da_mem[204240 + 1 * 4 + 1] = uint8(c2da_fresh61 >> 0x8)
            c2da_mem[204240 + 1 * 4 + 2] = uint8(c2da_fresh61 >> 0x10)
            c2da_mem[204240 + 1 * 4 + 3] = uint8(c2da_fresh61 >> 0x18)
            let c2da_fresh62 : float = uint_bits_to_float(uint(c2da_mem[244112 + 2 * 4]) | uint(c2da_mem[244112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 2 * 4 + 3]) << 0x18) - r_entorigin[2]
            let c2da_fresh63 : uint = float_bits_to_uint(c2da_fresh62)
            c2da_mem[204240 + 2 * 4] = uint8(c2da_fresh63)
            c2da_mem[204240 + 2 * 4 + 1] = uint8(c2da_fresh63 >> 0x8)
            c2da_mem[204240 + 2 * 4 + 2] = uint8(c2da_fresh63 >> 0x10)
            c2da_mem[204240 + 2 * 4 + 3] = uint8(c2da_fresh63 >> 0x18)
            R_DrawSprite()
        } elif (c2da_fresh57 == 0x2u) {
            r_entorigin[0] = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 0 * 4]) | uint(c2da_mem[currententity + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 0 * 4 + 3]) << 0x18)
            r_entorigin[1] = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 1 * 4]) | uint(c2da_mem[currententity + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 1 * 4 + 3]) << 0x18)
            r_entorigin[2] = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 2 * 4]) | uint(c2da_mem[currententity + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 2 * 4 + 3]) << 0x18)
            let c2da_fresh64 : float = uint_bits_to_float(uint(c2da_mem[244112 + 0 * 4]) | uint(c2da_mem[244112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 0 * 4 + 3]) << 0x18) - r_entorigin[0]
            let c2da_fresh65 : uint = float_bits_to_uint(c2da_fresh64)
            c2da_mem[204240 + 0 * 4] = uint8(c2da_fresh65)
            c2da_mem[204240 + 0 * 4 + 1] = uint8(c2da_fresh65 >> 0x8)
            c2da_mem[204240 + 0 * 4 + 2] = uint8(c2da_fresh65 >> 0x10)
            c2da_mem[204240 + 0 * 4 + 3] = uint8(c2da_fresh65 >> 0x18)
            let c2da_fresh66 : float = uint_bits_to_float(uint(c2da_mem[244112 + 1 * 4]) | uint(c2da_mem[244112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 1 * 4 + 3]) << 0x18) - r_entorigin[1]
            let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
            c2da_mem[204240 + 1 * 4] = uint8(c2da_fresh67)
            c2da_mem[204240 + 1 * 4 + 1] = uint8(c2da_fresh67 >> 0x8)
            c2da_mem[204240 + 1 * 4 + 2] = uint8(c2da_fresh67 >> 0x10)
            c2da_mem[204240 + 1 * 4 + 3] = uint8(c2da_fresh67 >> 0x18)
            let c2da_fresh68 : float = uint_bits_to_float(uint(c2da_mem[244112 + 2 * 4]) | uint(c2da_mem[244112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 2 * 4 + 3]) << 0x18) - r_entorigin[2]
            let c2da_fresh69 : uint = float_bits_to_uint(c2da_fresh68)
            c2da_mem[204240 + 2 * 4] = uint8(c2da_fresh69)
            c2da_mem[204240 + 2 * 4 + 1] = uint8(c2da_fresh69 >> 0x8)
            c2da_mem[204240 + 2 * 4 + 2] = uint8(c2da_fresh69 >> 0x10)
            c2da_mem[204240 + 2 * 4 + 3] = uint8(c2da_fresh69 >> 0x18)
            if (uint(R_AliasCheckBBox()) != 0u) {
                j_0 = R_LightPoint(currententity + 88)
                let c2da_fresh70 : uint = uint(j_0)
                c2da_mem[c2da_fp + 32] = uint8(c2da_fresh70)
                c2da_mem[c2da_fp + 33] = uint8(c2da_fresh70 >> 0x8)
                c2da_mem[c2da_fp + 34] = uint8(c2da_fresh70 >> 0x10)
                c2da_mem[c2da_fp + 35] = uint8(c2da_fresh70 >> 0x18)
                let c2da_fresh71 : uint = uint(j_0)
                c2da_mem[c2da_fp + 36] = uint8(c2da_fresh71)
                c2da_mem[c2da_fp + 37] = uint8(c2da_fresh71 >> 0x8)
                c2da_mem[c2da_fp + 38] = uint8(c2da_fresh71 >> 0x10)
                c2da_mem[c2da_fp + 39] = uint8(c2da_fresh71 >> 0x18)
                let c2da_fresh72 : uint = uint(c2da_fp)
                c2da_mem[c2da_fp + 40] = uint8(c2da_fresh72)
                c2da_mem[c2da_fp + 41] = uint8(c2da_fresh72 >> 0x8)
                c2da_mem[c2da_fp + 42] = uint8(c2da_fresh72 >> 0x10)
                c2da_mem[c2da_fp + 43] = uint8(c2da_fresh72 >> 0x18)
                c2da_mem[c2da_fp + 44] = 0u8
                c2da_mem[c2da_fp + 45] = 0u8
                c2da_mem[c2da_fp + 46] = 0u8
                c2da_mem[c2da_fp + 47] = 0u8
                for (lnum_0 in range(0, 32)) {
                    if (double(uint_bits_to_float(uint(c2da_mem[8112 + lnum_0 * 32 + 16]) | uint(c2da_mem[8112 + lnum_0 * 32 + 17]) << 0x8 | uint(c2da_mem[8112 + lnum_0 * 32 + 18]) << 0x10 | uint(c2da_mem[8112 + lnum_0 * 32 + 19]) << 0x18)) >= uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20)) {
                        let c2da_fresh73 : float = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 0 * 4]) | uint(c2da_mem[currententity + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[8112 + lnum_0 * 32 + 0 * 4]) | uint(c2da_mem[8112 + lnum_0 * 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[8112 + lnum_0 * 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[8112 + lnum_0 * 32 + 0 * 4 + 3]) << 0x18)
                        let c2da_fresh74 : uint = float_bits_to_uint(c2da_fresh73)
                        c2da_mem[c2da_fp + 16 + 0 * 4] = uint8(c2da_fresh74)
                        c2da_mem[c2da_fp + 16 + 0 * 4 + 1] = uint8(c2da_fresh74 >> 0x8)
                        c2da_mem[c2da_fp + 16 + 0 * 4 + 2] = uint8(c2da_fresh74 >> 0x10)
                        c2da_mem[c2da_fp + 16 + 0 * 4 + 3] = uint8(c2da_fresh74 >> 0x18)
                        let c2da_fresh75 : float = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 1 * 4]) | uint(c2da_mem[currententity + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[8112 + lnum_0 * 32 + 1 * 4]) | uint(c2da_mem[8112 + lnum_0 * 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[8112 + lnum_0 * 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[8112 + lnum_0 * 32 + 1 * 4 + 3]) << 0x18)
                        let c2da_fresh76 : uint = float_bits_to_uint(c2da_fresh75)
                        c2da_mem[c2da_fp + 16 + 1 * 4] = uint8(c2da_fresh76)
                        c2da_mem[c2da_fp + 16 + 1 * 4 + 1] = uint8(c2da_fresh76 >> 0x8)
                        c2da_mem[c2da_fp + 16 + 1 * 4 + 2] = uint8(c2da_fresh76 >> 0x10)
                        c2da_mem[c2da_fp + 16 + 1 * 4 + 3] = uint8(c2da_fresh76 >> 0x18)
                        let c2da_fresh77 : float = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 2 * 4]) | uint(c2da_mem[currententity + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[8112 + lnum_0 * 32 + 2 * 4]) | uint(c2da_mem[8112 + lnum_0 * 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[8112 + lnum_0 * 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[8112 + lnum_0 * 32 + 2 * 4 + 3]) << 0x18)
                        let c2da_fresh78 : uint = float_bits_to_uint(c2da_fresh77)
                        c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh78)
                        c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh78 >> 0x8)
                        c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh78 >> 0x10)
                        c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh78 >> 0x18)
                        add_0 = uint_bits_to_float(uint(c2da_mem[8112 + lnum_0 * 32 + 12]) | uint(c2da_mem[8112 + lnum_0 * 32 + 13]) << 0x8 | uint(c2da_mem[8112 + lnum_0 * 32 + 14]) << 0x10 | uint(c2da_mem[8112 + lnum_0 * 32 + 15]) << 0x18) - Length(c2da_fp + 16)
                        if (add_0 > 0.0) {
                            let c2da_fresh79 : int = int(float(int(uint(c2da_mem[c2da_fp + 32]) | uint(c2da_mem[c2da_fp + 33]) << 0x8 | uint(c2da_mem[c2da_fp + 34]) << 0x10 | uint(c2da_mem[c2da_fp + 35]) << 0x18)) + add_0)
                            let c2da_fresh80 : uint = uint(c2da_fresh79)
                            c2da_mem[c2da_fp + 32] = uint8(c2da_fresh80)
                            c2da_mem[c2da_fp + 33] = uint8(c2da_fresh80 >> 0x8)
                            c2da_mem[c2da_fp + 34] = uint8(c2da_fresh80 >> 0x10)
                            c2da_mem[c2da_fp + 35] = uint8(c2da_fresh80 >> 0x18)
                        }
                    }
                }
                if (int(uint(c2da_mem[c2da_fp + 32]) | uint(c2da_mem[c2da_fp + 33]) << 0x8 | uint(c2da_mem[c2da_fp + 34]) << 0x10 | uint(c2da_mem[c2da_fp + 35]) << 0x18) > 128) {
                    let c2da_fresh81 : int = 128
                    let c2da_fresh82 : uint = uint(c2da_fresh81)
                    c2da_mem[c2da_fp + 32] = uint8(c2da_fresh82)
                    c2da_mem[c2da_fp + 33] = uint8(c2da_fresh82 >> 0x8)
                    c2da_mem[c2da_fp + 34] = uint8(c2da_fresh82 >> 0x10)
                    c2da_mem[c2da_fp + 35] = uint8(c2da_fresh82 >> 0x18)
                }
                if (int(uint(c2da_mem[c2da_fp + 32]) | uint(c2da_mem[c2da_fp + 33]) << 0x8 | uint(c2da_mem[c2da_fp + 34]) << 0x10 | uint(c2da_mem[c2da_fp + 35]) << 0x18) + int(uint(c2da_mem[c2da_fp + 36]) | uint(c2da_mem[c2da_fp + 37]) << 0x8 | uint(c2da_mem[c2da_fp + 38]) << 0x10 | uint(c2da_mem[c2da_fp + 39]) << 0x18) > 192) {
                    let c2da_fresh83 : int = 192 - int(uint(c2da_mem[c2da_fp + 32]) | uint(c2da_mem[c2da_fp + 33]) << 0x8 | uint(c2da_mem[c2da_fp + 34]) << 0x10 | uint(c2da_mem[c2da_fp + 35]) << 0x18)
                    let c2da_fresh84 : uint = uint(c2da_fresh83)
                    c2da_mem[c2da_fp + 36] = uint8(c2da_fresh84)
                    c2da_mem[c2da_fp + 37] = uint8(c2da_fresh84 >> 0x8)
                    c2da_mem[c2da_fp + 38] = uint8(c2da_fresh84 >> 0x10)
                    c2da_mem[c2da_fp + 39] = uint8(c2da_fresh84 >> 0x18)
                }
                R_AliasDrawModel(c2da_fp + 32)
            }
        }
        i_0++
    }
    return
}
[sideeffects]
def private R_EdgeDrawing_c2da_frame(c2da_fp : int) {
    if (auxedges != 0) {
        r_edges = auxedges
    } else {
        r_edges = int(int64(c2da_fp + 0 * 56) + 32l - 1l & int64(~(32 - 1)))
    }
    if (r_surfsonstack != 0u) {
        surfaces = int(int64(c2da_fp + 134464 + 0 * 88) + 32l - 1l & int64(~(32 - 1)))
        surf_max = surfaces + r_cnumsurfs * 88
        surfaces = surfaces - 88
        R_SurfacePatch()
    }
    R_BeginEdgeFrame()
    if (uint_bits_to_float(uint(c2da_mem[392520]) | uint(c2da_mem[392521]) << 0x8 | uint(c2da_mem[392522]) << 0x10 | uint(c2da_mem[392523]) << 0x18) != 0.0) {
        rw_time1 = float(Sys_FloatTime())
    }
    R_RenderWorld()
    if (r_drawculledpolys != 0u) {
        R_ScanEdges()
    }
    D_TurnZOn()
    if (uint_bits_to_float(uint(c2da_mem[392520]) | uint(c2da_mem[392521]) << 0x8 | uint(c2da_mem[392522]) << 0x10 | uint(c2da_mem[392523]) << 0x18) != 0.0) {
        rw_time2 = float(Sys_FloatTime())
        db_time1 = float(rw_time2)  // nolint:PERF020
    }
    R_DrawBEntitiesOnList()
    if (uint_bits_to_float(uint(c2da_mem[392520]) | uint(c2da_mem[392521]) << 0x8 | uint(c2da_mem[392522]) << 0x10 | uint(c2da_mem[392523]) << 0x18) != 0.0) {
        db_time2 = float(Sys_FloatTime())
        se_time1 = float(db_time2)  // nolint:PERF020
    }
    if (uint_bits_to_float(uint(c2da_mem[392520]) | uint(c2da_mem[392521]) << 0x8 | uint(c2da_mem[392522]) << 0x10 | uint(c2da_mem[392523]) << 0x18) == 0.0) {
        S_ExtraUpdate()
    }
    if ((r_drawpolys | r_drawculledpolys) == 0) {
        R_ScanEdges()
    }
    return
}
[sideeffects]
def private R_DrawBEntitiesOnList_c2da_frame(c2da_fp : int) {
    var c2da_fresh86 : uint
    var i_1 : int
    var j_1 : int
    var clipflags : int
    var oldorigin : vec3_t
    var clmodel : int
    if (uint_bits_to_float(uint(c2da_mem[392376]) | uint(c2da_mem[392377]) << 0x8 | uint(c2da_mem[392378]) << 0x10 | uint(c2da_mem[392379]) << 0x18) == 0.0) {
        return
    }
    oldorigin[0] = uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18)
    oldorigin[1] = uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18)
    oldorigin[2] = uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18)
    insubmodel = 1u
    r_dlightframecount = r_framecount
    i_1 = 0
    while (i_1 < cl_numvisedicts) {
        currententity = cl_visedicts[i_1]
        let c2da_fresh85 : int = int(uint(c2da_mem[currententity + 136]) | uint(c2da_mem[currententity + 137]) << 0x8 | uint(c2da_mem[currententity + 138]) << 0x10 | uint(c2da_mem[currententity + 139]) << 0x18) + 68
        c2da_fresh86 = uint(c2da_mem[c2da_fresh85]) | uint(c2da_mem[c2da_fresh85 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh85 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh85 + 3]) << 0x18
        if (c2da_fresh86 == 0x0u) {
            clmodel = int(uint(c2da_mem[currententity + 136]) | uint(c2da_mem[currententity + 137]) << 0x8 | uint(c2da_mem[currententity + 138]) << 0x10 | uint(c2da_mem[currententity + 139]) << 0x18)
            j_1 = 0
            while (j_1 < 3) {
                let c2da_fresh87 : float = uint_bits_to_float(uint(c2da_mem[currententity + 88 + j_1 * 4]) | uint(c2da_mem[currententity + 88 + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + j_1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[clmodel + 84 + j_1 * 4]) | uint(c2da_mem[clmodel + 84 + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[clmodel + 84 + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[clmodel + 84 + j_1 * 4 + 3]) << 0x18)
                let c2da_fresh88 : uint = float_bits_to_uint(c2da_fresh87)
                c2da_mem[c2da_fp + j_1 * 4] = uint8(c2da_fresh88)
                c2da_mem[c2da_fp + j_1 * 4 + 1] = uint8(c2da_fresh88 >> 0x8)
                c2da_mem[c2da_fp + j_1 * 4 + 2] = uint8(c2da_fresh88 >> 0x10)
                c2da_mem[c2da_fp + j_1 * 4 + 3] = uint8(c2da_fresh88 >> 0x18)
                let c2da_fresh89 : float = uint_bits_to_float(uint(c2da_mem[currententity + 88 + j_1 * 4]) | uint(c2da_mem[currententity + 88 + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + j_1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[clmodel + 96 + j_1 * 4]) | uint(c2da_mem[clmodel + 96 + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[clmodel + 96 + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[clmodel + 96 + j_1 * 4 + 3]) << 0x18)
                let c2da_fresh90 : uint = float_bits_to_uint(c2da_fresh89)
                c2da_mem[c2da_fp + (3 + j_1) * 4] = uint8(c2da_fresh90)
                c2da_mem[c2da_fp + (3 + j_1) * 4 + 1] = uint8(c2da_fresh90 >> 0x8)
                c2da_mem[c2da_fp + (3 + j_1) * 4 + 2] = uint8(c2da_fresh90 >> 0x10)
                c2da_mem[c2da_fp + (3 + j_1) * 4 + 3] = uint8(c2da_fresh90 >> 0x18)
                j_1++
            }
            clipflags = R_BmodelCheckBBox(clmodel, c2da_fp)
            if (clipflags != 16) {
                r_entorigin[0] = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 0 * 4]) | uint(c2da_mem[currententity + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 0 * 4 + 3]) << 0x18)
                r_entorigin[1] = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 1 * 4]) | uint(c2da_mem[currententity + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 1 * 4 + 3]) << 0x18)
                r_entorigin[2] = uint_bits_to_float(uint(c2da_mem[currententity + 88 + 2 * 4]) | uint(c2da_mem[currententity + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[currententity + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[currententity + 88 + 2 * 4 + 3]) << 0x18)
                let c2da_fresh91 : float = uint_bits_to_float(uint(c2da_mem[244112 + 0 * 4]) | uint(c2da_mem[244112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 0 * 4 + 3]) << 0x18) - r_entorigin[0]
                let c2da_fresh92 : uint = float_bits_to_uint(c2da_fresh91)
                c2da_mem[204240 + 0 * 4] = uint8(c2da_fresh92)
                c2da_mem[204240 + 0 * 4 + 1] = uint8(c2da_fresh92 >> 0x8)
                c2da_mem[204240 + 0 * 4 + 2] = uint8(c2da_fresh92 >> 0x10)
                c2da_mem[204240 + 0 * 4 + 3] = uint8(c2da_fresh92 >> 0x18)
                let c2da_fresh93 : float = uint_bits_to_float(uint(c2da_mem[244112 + 1 * 4]) | uint(c2da_mem[244112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 1 * 4 + 3]) << 0x18) - r_entorigin[1]
                let c2da_fresh94 : uint = float_bits_to_uint(c2da_fresh93)
                c2da_mem[204240 + 1 * 4] = uint8(c2da_fresh94)
                c2da_mem[204240 + 1 * 4 + 1] = uint8(c2da_fresh94 >> 0x8)
                c2da_mem[204240 + 1 * 4 + 2] = uint8(c2da_fresh94 >> 0x10)
                c2da_mem[204240 + 1 * 4 + 3] = uint8(c2da_fresh94 >> 0x18)
                let c2da_fresh95 : float = uint_bits_to_float(uint(c2da_mem[244112 + 2 * 4]) | uint(c2da_mem[244112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 2 * 4 + 3]) << 0x18) - r_entorigin[2]
                let c2da_fresh96 : uint = float_bits_to_uint(c2da_fresh95)
                c2da_mem[204240 + 2 * 4] = uint8(c2da_fresh96)
                c2da_mem[204240 + 2 * 4 + 1] = uint8(c2da_fresh96 >> 0x8)
                c2da_mem[204240 + 2 * 4 + 2] = uint8(c2da_fresh96 >> 0x10)
                c2da_mem[204240 + 2 * 4 + 3] = uint8(c2da_fresh96 >> 0x18)
                r_worldmodelorg[0] = uint_bits_to_float(uint(c2da_mem[204240 + 0 * 4]) | uint(c2da_mem[204240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 0 * 4 + 3]) << 0x18)
                r_worldmodelorg[1] = uint_bits_to_float(uint(c2da_mem[204240 + 1 * 4]) | uint(c2da_mem[204240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 1 * 4 + 3]) << 0x18)
                r_worldmodelorg[2] = uint_bits_to_float(uint(c2da_mem[204240 + 2 * 4]) | uint(c2da_mem[204240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[204240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[204240 + 2 * 4 + 3]) << 0x18)
                r_pcurrentvertbase = int(uint(c2da_mem[clmodel + 176]) | uint(c2da_mem[clmodel + 177]) << 0x8 | uint(c2da_mem[clmodel + 178]) << 0x10 | uint(c2da_mem[clmodel + 179]) << 0x18)
                R_RotateBmodel()
                if (int(uint(c2da_mem[clmodel + 112]) | uint(c2da_mem[clmodel + 113]) << 0x8 | uint(c2da_mem[clmodel + 114]) << 0x10 | uint(c2da_mem[clmodel + 115]) << 0x18) != 0) {
                    for (k in range(0, 32)) {
                        if (double(uint_bits_to_float(uint(c2da_mem[8112 + k * 32 + 16]) | uint(c2da_mem[8112 + k * 32 + 17]) << 0x8 | uint(c2da_mem[8112 + k * 32 + 18]) << 0x10 | uint(c2da_mem[8112 + k * 32 + 19]) << 0x18)) < uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) || uint_bits_to_float(uint(c2da_mem[8112 + k * 32 + 12]) | uint(c2da_mem[8112 + k * 32 + 13]) << 0x8 | uint(c2da_mem[8112 + k * 32 + 14]) << 0x10 | uint(c2da_mem[8112 + k * 32 + 15]) << 0x18) == 0.0) {
                            continue
                        }
                        R_MarkLights(8112 + k * 32, 1 << k, int(uint(c2da_mem[clmodel + 208]) | uint(c2da_mem[clmodel + 209]) << 0x8 | uint(c2da_mem[clmodel + 210]) << 0x10 | uint(c2da_mem[clmodel + 211]) << 0x18) + int(uint(c2da_mem[clmodel + 296 + 0 * 48 + 16]) | uint(c2da_mem[clmodel + 296 + 0 * 48 + 17]) << 0x8 | uint(c2da_mem[clmodel + 296 + 0 * 48 + 18]) << 0x10 | uint(c2da_mem[clmodel + 296 + 0 * 48 + 19]) << 0x18) * 64)
                    }
                }
                if ((r_drawpolys | r_drawculledpolys) != 0x0) {
                    R_ZDrawSubmodelPolys(clmodel)
                } else {
                    r_pefragtopnode = 0
                    j_1 = 0
                    while (j_1 < 3) {
                        let c2da_fresh97 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + j_1 * 4]) | uint(c2da_mem[c2da_fp + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + j_1 * 4 + 3]) << 0x18)
                        let c2da_fresh98 : uint = float_bits_to_uint(c2da_fresh97)
                        c2da_mem[391888 + j_1 * 4] = uint8(c2da_fresh98)
                        c2da_mem[391888 + j_1 * 4 + 1] = uint8(c2da_fresh98 >> 0x8)
                        c2da_mem[391888 + j_1 * 4 + 2] = uint8(c2da_fresh98 >> 0x10)
                        c2da_mem[391888 + j_1 * 4 + 3] = uint8(c2da_fresh98 >> 0x18)
                        let c2da_fresh99 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + (3 + j_1) * 4]) | uint(c2da_mem[c2da_fp + (3 + j_1) * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + (3 + j_1) * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + (3 + j_1) * 4 + 3]) << 0x18)
                        let c2da_fresh100 : uint = float_bits_to_uint(c2da_fresh99)
                        c2da_mem[391904 + j_1 * 4] = uint8(c2da_fresh100)
                        c2da_mem[391904 + j_1 * 4 + 1] = uint8(c2da_fresh100 >> 0x8)
                        c2da_mem[391904 + j_1 * 4 + 2] = uint8(c2da_fresh100 >> 0x10)
                        c2da_mem[391904 + j_1 * 4 + 3] = uint8(c2da_fresh100 >> 0x18)
                        j_1++
                    }
                    let c2da_fresh101 : int = int(uint(c2da_mem[4960]) | uint(c2da_mem[4961]) << 0x8 | uint(c2da_mem[4962]) << 0x10 | uint(c2da_mem[4963]) << 0x18) + 208
                    R_SplitEntityOnNode2(int(uint(c2da_mem[c2da_fresh101]) | uint(c2da_mem[c2da_fresh101 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh101 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh101 + 3]) << 0x18))
                    if (r_pefragtopnode != 0) {
                        let c2da_fresh102 : uint = uint(r_pefragtopnode)
                        c2da_mem[currententity + 192] = uint8(c2da_fresh102)
                        c2da_mem[currententity + 193] = uint8(c2da_fresh102 >> 0x8)
                        c2da_mem[currententity + 194] = uint8(c2da_fresh102 >> 0x10)
                        c2da_mem[currententity + 195] = uint8(c2da_fresh102 >> 0x18)
                        c2da_mem[currententity + 196] = 0u8
                        c2da_mem[currententity + 197] = 0u8
                        c2da_mem[currententity + 198] = 0u8
                        c2da_mem[currententity + 199] = 0u8
                        if (int(uint(c2da_mem[r_pefragtopnode]) | uint(c2da_mem[r_pefragtopnode + 1]) << 0x8 | uint(c2da_mem[r_pefragtopnode + 2]) << 0x10 | uint(c2da_mem[r_pefragtopnode + 3]) << 0x18) >= 0) {
                            r_clipflags = clipflags
                            R_DrawSolidClippedSubmodelPolygons(clmodel)
                        } else {
                            R_DrawSubmodelPolygons(clmodel, clipflags)
                        }
                        let c2da_fresh103 : uint = 0u
                        c2da_mem[currententity + 192] = uint8(c2da_fresh103)
                        c2da_mem[currententity + 193] = uint8(c2da_fresh103 >> 0x8)
                        c2da_mem[currententity + 194] = uint8(c2da_fresh103 >> 0x10)
                        c2da_mem[currententity + 195] = uint8(c2da_fresh103 >> 0x18)
                        c2da_mem[currententity + 196] = 0u8
                        c2da_mem[currententity + 197] = 0u8
                        c2da_mem[currententity + 198] = 0u8
                        c2da_mem[currententity + 199] = 0u8
                    }
                }
                let c2da_fresh104 : float = base_vpn[0]
                let c2da_fresh105 : uint = float_bits_to_uint(c2da_fresh104)
                c2da_mem[244128 + 0 * 4] = uint8(c2da_fresh105)
                c2da_mem[244128 + 0 * 4 + 1] = uint8(c2da_fresh105 >> 0x8)
                c2da_mem[244128 + 0 * 4 + 2] = uint8(c2da_fresh105 >> 0x10)
                c2da_mem[244128 + 0 * 4 + 3] = uint8(c2da_fresh105 >> 0x18)
                let c2da_fresh106 : float = base_vpn[1]
                let c2da_fresh107 : uint = float_bits_to_uint(c2da_fresh106)
                c2da_mem[244128 + 1 * 4] = uint8(c2da_fresh107)
                c2da_mem[244128 + 1 * 4 + 1] = uint8(c2da_fresh107 >> 0x8)
                c2da_mem[244128 + 1 * 4 + 2] = uint8(c2da_fresh107 >> 0x10)
                c2da_mem[244128 + 1 * 4 + 3] = uint8(c2da_fresh107 >> 0x18)
                let c2da_fresh108 : float = base_vpn[2]
                let c2da_fresh109 : uint = float_bits_to_uint(c2da_fresh108)
                c2da_mem[244128 + 2 * 4] = uint8(c2da_fresh109)
                c2da_mem[244128 + 2 * 4 + 1] = uint8(c2da_fresh109 >> 0x8)
                c2da_mem[244128 + 2 * 4 + 2] = uint8(c2da_fresh109 >> 0x10)
                c2da_mem[244128 + 2 * 4 + 3] = uint8(c2da_fresh109 >> 0x18)
                let c2da_fresh110 : float = base_vup[0]
                let c2da_fresh111 : uint = float_bits_to_uint(c2da_fresh110)
                c2da_mem[244160 + 0 * 4] = uint8(c2da_fresh111)
                c2da_mem[244160 + 0 * 4 + 1] = uint8(c2da_fresh111 >> 0x8)
                c2da_mem[244160 + 0 * 4 + 2] = uint8(c2da_fresh111 >> 0x10)
                c2da_mem[244160 + 0 * 4 + 3] = uint8(c2da_fresh111 >> 0x18)
                let c2da_fresh112 : float = base_vup[1]
                let c2da_fresh113 : uint = float_bits_to_uint(c2da_fresh112)
                c2da_mem[244160 + 1 * 4] = uint8(c2da_fresh113)
                c2da_mem[244160 + 1 * 4 + 1] = uint8(c2da_fresh113 >> 0x8)
                c2da_mem[244160 + 1 * 4 + 2] = uint8(c2da_fresh113 >> 0x10)
                c2da_mem[244160 + 1 * 4 + 3] = uint8(c2da_fresh113 >> 0x18)
                let c2da_fresh114 : float = base_vup[2]
                let c2da_fresh115 : uint = float_bits_to_uint(c2da_fresh114)
                c2da_mem[244160 + 2 * 4] = uint8(c2da_fresh115)
                c2da_mem[244160 + 2 * 4 + 1] = uint8(c2da_fresh115 >> 0x8)
                c2da_mem[244160 + 2 * 4 + 2] = uint8(c2da_fresh115 >> 0x10)
                c2da_mem[244160 + 2 * 4 + 3] = uint8(c2da_fresh115 >> 0x18)
                let c2da_fresh116 : float = base_vright[0]
                let c2da_fresh117 : uint = float_bits_to_uint(c2da_fresh116)
                c2da_mem[244144 + 0 * 4] = uint8(c2da_fresh117)
                c2da_mem[244144 + 0 * 4 + 1] = uint8(c2da_fresh117 >> 0x8)
                c2da_mem[244144 + 0 * 4 + 2] = uint8(c2da_fresh117 >> 0x10)
                c2da_mem[244144 + 0 * 4 + 3] = uint8(c2da_fresh117 >> 0x18)
                let c2da_fresh118 : float = base_vright[1]
                let c2da_fresh119 : uint = float_bits_to_uint(c2da_fresh118)
                c2da_mem[244144 + 1 * 4] = uint8(c2da_fresh119)
                c2da_mem[244144 + 1 * 4 + 1] = uint8(c2da_fresh119 >> 0x8)
                c2da_mem[244144 + 1 * 4 + 2] = uint8(c2da_fresh119 >> 0x10)
                c2da_mem[244144 + 1 * 4 + 3] = uint8(c2da_fresh119 >> 0x18)
                let c2da_fresh120 : float = base_vright[2]
                let c2da_fresh121 : uint = float_bits_to_uint(c2da_fresh120)
                c2da_mem[244144 + 2 * 4] = uint8(c2da_fresh121)
                c2da_mem[244144 + 2 * 4 + 1] = uint8(c2da_fresh121 >> 0x8)
                c2da_mem[244144 + 2 * 4 + 2] = uint8(c2da_fresh121 >> 0x10)
                c2da_mem[244144 + 2 * 4 + 3] = uint8(c2da_fresh121 >> 0x18)
                let c2da_fresh122 : float = base_modelorg[0]
                let c2da_fresh123 : uint = float_bits_to_uint(c2da_fresh122)
                c2da_mem[204240 + 0 * 4] = uint8(c2da_fresh123)
                c2da_mem[204240 + 0 * 4 + 1] = uint8(c2da_fresh123 >> 0x8)
                c2da_mem[204240 + 0 * 4 + 2] = uint8(c2da_fresh123 >> 0x10)
                c2da_mem[204240 + 0 * 4 + 3] = uint8(c2da_fresh123 >> 0x18)
                let c2da_fresh124 : float = base_modelorg[1]
                let c2da_fresh125 : uint = float_bits_to_uint(c2da_fresh124)
                c2da_mem[204240 + 1 * 4] = uint8(c2da_fresh125)
                c2da_mem[204240 + 1 * 4 + 1] = uint8(c2da_fresh125 >> 0x8)
                c2da_mem[204240 + 1 * 4 + 2] = uint8(c2da_fresh125 >> 0x10)
                c2da_mem[204240 + 1 * 4 + 3] = uint8(c2da_fresh125 >> 0x18)
                let c2da_fresh126 : float = base_modelorg[2]
                let c2da_fresh127 : uint = float_bits_to_uint(c2da_fresh126)
                c2da_mem[204240 + 2 * 4] = uint8(c2da_fresh127)
                c2da_mem[204240 + 2 * 4 + 1] = uint8(c2da_fresh127 >> 0x8)
                c2da_mem[204240 + 2 * 4 + 2] = uint8(c2da_fresh127 >> 0x10)
                c2da_mem[204240 + 2 * 4 + 3] = uint8(c2da_fresh127 >> 0x18)
                let c2da_fresh128 : float = oldorigin[0]
                let c2da_fresh129 : uint = float_bits_to_uint(c2da_fresh128)
                c2da_mem[204240 + 0 * 4] = uint8(c2da_fresh129)
                c2da_mem[204240 + 0 * 4 + 1] = uint8(c2da_fresh129 >> 0x8)
                c2da_mem[204240 + 0 * 4 + 2] = uint8(c2da_fresh129 >> 0x10)
                c2da_mem[204240 + 0 * 4 + 3] = uint8(c2da_fresh129 >> 0x18)
                let c2da_fresh130 : float = oldorigin[1]
                let c2da_fresh131 : uint = float_bits_to_uint(c2da_fresh130)
                c2da_mem[204240 + 1 * 4] = uint8(c2da_fresh131)
                c2da_mem[204240 + 1 * 4 + 1] = uint8(c2da_fresh131 >> 0x8)
                c2da_mem[204240 + 1 * 4 + 2] = uint8(c2da_fresh131 >> 0x10)
                c2da_mem[204240 + 1 * 4 + 3] = uint8(c2da_fresh131 >> 0x18)
                let c2da_fresh132 : float = oldorigin[2]
                let c2da_fresh133 : uint = float_bits_to_uint(c2da_fresh132)
                c2da_mem[204240 + 2 * 4] = uint8(c2da_fresh133)
                c2da_mem[204240 + 2 * 4 + 1] = uint8(c2da_fresh133 >> 0x8)
                c2da_mem[204240 + 2 * 4 + 2] = uint8(c2da_fresh133 >> 0x10)
                c2da_mem[204240 + 2 * 4 + 3] = uint8(c2da_fresh133 >> 0x18)
                R_TransformFrustum()
            }
        }
        i_1++
    }
    insubmodel = 0u
    return
}

// This unit's static data, at heap offset 732736.
let private c2da_lin_static_r_main_seg = fixed_array<int>(732736, 516)
let private c2da_lin_static_r_main = fixed_array<uint64>(0x726f776172645f72ul, 0x5f72003000726564ul, 0x7200736465657073ul, 0x617267656d69745ful, 0x6172675f72006870ul, 0x7468676965686870ul, 0x72645f7200303100ul, 0x720074616c667761ul, 0x746e6569626d615ful, 0x7261656c635f7200ul, 0x3200726f6c6f63ul, 0x7772657461775f72ul, 0x5f72003100707261ul, 0x676972626c6c7566ul, 0x6172645f72007468ul, 0x65697469746e6577ul, 0x776172645f720073ul, 0x65646f6d77656976ul, 0x796c6f705f72006cul, 0x6174736c65646f6dul, 0x7073645f72007374ul, 0x725f720073646565ul, 0x72757374726f7065ul, 0x6d5f720074756f66ul, 0x73667275737861ul, 0x7275736d756e5f72ul, 0x7065725f72007366ul, 0x6f6567646574726ful, 0x78616d5f72007475ul, 0x5f72007365676465ul, 0x73656764656d756eul, 0x7361696c615f7200ul, 0x736162736e617274ul, 0x5f72003030320065ul, 0x6172747361696c61ul, 0x3031006a6461736eul, 0x6572656d69740030ul, 0x6f70006873657266ul, 0x656c6966746e69ul, 0x7275747865746f6eul, 0x646e65525f520065ul, 0x203a776569567265ul, 0x772064656c6c6163ul, 0x652074756f687469ul, 0x7473206867756f6eul, 0x6b6e7548006b6361ul, 0x7373696d20736920ul, 0x64656e67696c61ul, 0x7369206b63617453ul, 0x696c617373696d20ul, 0x6f6c470064656e67ul, 0x65726120736c6162ul, 0x696c617373696d20ul, 0x525f520064656e67ul, 0x6569567265646e65ul, 0x204c4c554e203a77ul, 0x646f6d646c726f77ul, 0x74726f6853006c65ul, 0x6672757320642520ul, 0x6853000a73656361ul, 0x67756f722074726ful, 0x6520642520796c68ul, 0x7573000a73656764ul, 0x6500736563616672ul, 0x73656764ul)

[init]
def private c2da_lin_init_static_r_main() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_main_seg[s * 2]
        for (k in range(c2da_lin_static_r_main_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_main[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_r_main_0 = fixed_array<uint8>(0x40, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_1 = fixed_array<uint8>(0x4e, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_2 = fixed_array<uint8>(0x57, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_3 = fixed_array<uint8>(0x63, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x71, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_4 = fixed_array<uint8>(0x74, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_5 = fixed_array<uint8>(0x7f, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_6 = fixed_array<uint8>(0x89, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x96, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_7 = fixed_array<uint8>(0x98, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa4, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_8 = fixed_array<uint8>(0xa6, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_9 = fixed_array<uint8>(0xb3, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa4, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_10 = fixed_array<uint8>(0xc2, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa4, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_11 = fixed_array<uint8>(0xd2, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_12 = fixed_array<uint8>(0xe3, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_13 = fixed_array<uint8>(0xed, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_14 = fixed_array<uint8>(0xfd, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_15 = fixed_array<uint8>(0x8, 0x2f, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_16 = fixed_array<uint8>(0x13, 0x2f, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_17 = fixed_array<uint8>(0x23, 0x2f, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_18 = fixed_array<uint8>(0x2e, 0x2f, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x2e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_19 = fixed_array<uint8>(0x39, 0x2f, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4a, 0x2f, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_20 = fixed_array<uint8>(0x4e, 0x2f, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5e, 0x2f, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_r_main_21 = fixed_array<uint8>(0x80, 0x0, 0x0, 0x0, 0xc0, 0x0, 0x0, 0x0, 0xf0, 0xfe, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_r_main() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[391920 + i] = c2da_lin_extern_r_main_0[i]
    }
    for (i in range(40)) {
        c2da_mem[391968 + i] = c2da_lin_extern_r_main_1[i]
    }
    for (i in range(40)) {
        c2da_mem[392016 + i] = c2da_lin_extern_r_main_2[i]
    }
    for (i in range(40)) {
        c2da_mem[392064 + i] = c2da_lin_extern_r_main_3[i]
    }
    for (i in range(40)) {
        c2da_mem[392112 + i] = c2da_lin_extern_r_main_4[i]
    }
    for (i in range(40)) {
        c2da_mem[392160 + i] = c2da_lin_extern_r_main_5[i]
    }
    for (i in range(40)) {
        c2da_mem[392208 + i] = c2da_lin_extern_r_main_6[i]
    }
    for (i in range(40)) {
        c2da_mem[392256 + i] = c2da_lin_extern_r_main_7[i]
    }
    for (i in range(40)) {
        c2da_mem[392304 + i] = c2da_lin_extern_r_main_8[i]
    }
    for (i in range(40)) {
        c2da_mem[392352 + i] = c2da_lin_extern_r_main_9[i]
    }
    for (i in range(40)) {
        c2da_mem[392400 + i] = c2da_lin_extern_r_main_10[i]
    }
    for (i in range(40)) {
        c2da_mem[392448 + i] = c2da_lin_extern_r_main_11[i]
    }
    for (i in range(40)) {
        c2da_mem[392496 + i] = c2da_lin_extern_r_main_12[i]
    }
    for (i in range(40)) {
        c2da_mem[392544 + i] = c2da_lin_extern_r_main_13[i]
    }
    for (i in range(40)) {
        c2da_mem[392592 + i] = c2da_lin_extern_r_main_14[i]
    }
    for (i in range(40)) {
        c2da_mem[392640 + i] = c2da_lin_extern_r_main_15[i]
    }
    for (i in range(40)) {
        c2da_mem[392688 + i] = c2da_lin_extern_r_main_16[i]
    }
    for (i in range(40)) {
        c2da_mem[392736 + i] = c2da_lin_extern_r_main_17[i]
    }
    for (i in range(40)) {
        c2da_mem[392784 + i] = c2da_lin_extern_r_main_18[i]
    }
    for (i in range(40)) {
        c2da_mem[392832 + i] = c2da_lin_extern_r_main_19[i]
    }
    for (i in range(40)) {
        c2da_mem[392880 + i] = c2da_lin_extern_r_main_20[i]
    }
    for (i in range(16)) {
        c2da_mem[392960 + i] = c2da_lin_extern_r_main_21[i]
    }
}
