[export, sideeffects]
def SV_ClearWorld() {
    SV_InitBoxHull()
    c2da_lin_memset(737856, 0, 1792ul)
    sv_numareanodes = 0
    SV_CreateAreaNode(0, int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) + 84, int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) + 96)
    return
}
[export, sideeffects]
def SV_CreateAreaNode(var depth : int; var mins : int; var maxs : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = SV_CreateAreaNode_c2da_frame(depth, mins, maxs, c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
var private sv_numareanodes : int = default<int>

[export, sideeffects]
def SV_InitBoxHull() {
    var side : int
    let c2da_fresh45 : uint = 739648u
    c2da_mem[739824] = uint8(c2da_fresh45)
    c2da_mem[739825] = uint8(c2da_fresh45 >> 0x8)
    c2da_mem[739826] = uint8(c2da_fresh45 >> 0x10)
    c2da_mem[739827] = uint8(c2da_fresh45 >> 0x18)
    c2da_mem[739828] = 0u8
    c2da_mem[739829] = 0u8
    c2da_mem[739830] = 0u8
    c2da_mem[739831] = 0u8
    let c2da_fresh46 : uint = 739696u
    c2da_mem[739832] = uint8(c2da_fresh46)
    c2da_mem[739833] = uint8(c2da_fresh46 >> 0x8)
    c2da_mem[739834] = uint8(c2da_fresh46 >> 0x10)
    c2da_mem[739835] = uint8(c2da_fresh46 >> 0x18)
    c2da_mem[739836] = 0u8
    c2da_mem[739837] = 0u8
    c2da_mem[739838] = 0u8
    c2da_mem[739839] = 0u8
    let c2da_fresh47 : int = 0
    let c2da_fresh48 : uint = uint(c2da_fresh47)
    c2da_mem[739840] = uint8(c2da_fresh48)
    c2da_mem[739841] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[739842] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[739843] = uint8(c2da_fresh48 >> 0x18)
    let c2da_fresh49 : int = 5
    let c2da_fresh50 : uint = uint(c2da_fresh49)
    c2da_mem[739844] = uint8(c2da_fresh50)
    c2da_mem[739845] = uint8(c2da_fresh50 >> 0x8)
    c2da_mem[739846] = uint8(c2da_fresh50 >> 0x10)
    c2da_mem[739847] = uint8(c2da_fresh50 >> 0x18)
    for (i in range(0, 6)) {
        let c2da_fresh51 : uint = uint(i)
        c2da_mem[739648 + i * 8] = uint8(c2da_fresh51)
        c2da_mem[739648 + i * 8 + 1] = uint8(c2da_fresh51 >> 0x8)
        c2da_mem[739648 + i * 8 + 2] = uint8(c2da_fresh51 >> 0x10)
        c2da_mem[739648 + i * 8 + 3] = uint8(c2da_fresh51 >> 0x18)
        side = i & 1
        let c2da_fresh52 : int16 = int16(-1)
        let c2da_fresh53 : uint = uint(c2da_fresh52)
        c2da_mem[739648 + i * 8 + 4 + side * 2] = uint8(c2da_fresh53)
        c2da_mem[739648 + i * 8 + 4 + side * 2 + 1] = uint8(c2da_fresh53 >> 0x8)
        if (i != 5) {
            let c2da_fresh54 : int = 739648 + i * 8 + 4 + (side ^ 1) * 2
            let c2da_fresh55 : int16 = int16(i + 1)
            let c2da_fresh56 : uint = uint(c2da_fresh55)
            c2da_mem[c2da_fresh54] = uint8(c2da_fresh56)
            c2da_mem[c2da_fresh54 + 1] = uint8(c2da_fresh56 >> 0x8)
        } else {
            let c2da_fresh57 : int = 739648 + i * 8 + 4 + (side ^ 1) * 2
            let c2da_fresh58 : int16 = int16(-2)
            let c2da_fresh59 : uint = uint(c2da_fresh58)
            c2da_mem[c2da_fresh57] = uint8(c2da_fresh59)
            c2da_mem[c2da_fresh57 + 1] = uint8(c2da_fresh59 >> 0x8)
        }
        let c2da_fresh60 : uint8 = uint8(i >> 1)
        c2da_mem[739696 + i * 20 + 16] = c2da_fresh60
        let c2da_fresh61 : int = 739696 + i * 20 + (i >> 1) * 4
        let c2da_fresh62 : float = 1.0
        let c2da_fresh63 : uint = float_bits_to_uint(c2da_fresh62)
        c2da_mem[c2da_fresh61] = uint8(c2da_fresh63)
        c2da_mem[c2da_fresh61 + 1] = uint8(c2da_fresh63 >> 0x8)
        c2da_mem[c2da_fresh61 + 2] = uint8(c2da_fresh63 >> 0x10)
        c2da_mem[c2da_fresh61 + 3] = uint8(c2da_fresh63 >> 0x18)
    }
    return
}
[export, sideeffects]
def SV_UnlinkEdict(var ent : int) {
    if (int(uint(c2da_mem[ent + 8]) | uint(c2da_mem[ent + 9]) << 0x8 | uint(c2da_mem[ent + 10]) << 0x10 | uint(c2da_mem[ent + 11]) << 0x18) == 0) {
        return
    }
    RemoveLink(ent + 8)
    let c2da_fresh64 : uint = 0u
    c2da_mem[ent + 16] = uint8(c2da_fresh64)
    c2da_mem[ent + 17] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[ent + 18] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[ent + 19] = uint8(c2da_fresh64 >> 0x18)
    c2da_mem[ent + 20] = 0u8
    c2da_mem[ent + 21] = 0u8
    c2da_mem[ent + 22] = 0u8
    c2da_mem[ent + 23] = 0u8
    let c2da_fresh65 : uint = 0u
    c2da_mem[ent + 8] = uint8(c2da_fresh65)
    c2da_mem[ent + 9] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[ent + 10] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[ent + 11] = uint8(c2da_fresh65 >> 0x18)
    c2da_mem[ent + 12] = 0u8
    c2da_mem[ent + 13] = 0u8
    c2da_mem[ent + 14] = 0u8
    c2da_mem[ent + 15] = 0u8
    return
}
[export, sideeffects]
def SV_LinkEdict(var ent_0 : int; var touch_triggers : uint) {
    var node : int
    if (int(uint(c2da_mem[ent_0 + 8]) | uint(c2da_mem[ent_0 + 9]) << 0x8 | uint(c2da_mem[ent_0 + 10]) << 0x10 | uint(c2da_mem[ent_0 + 11]) << 0x18) != 0) {
        SV_UnlinkEdict(ent_0)
    }
    if (ent_0 == int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)) {
        return
    }
    if ((uint(c2da_mem[ent_0]) | uint(c2da_mem[ent_0 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 3]) << 0x18) != 0u) {
        return
    }
    let c2da_fresh66 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 0 * 4]) | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_0 + 240 + 0 * 4]) | uint(c2da_mem[ent_0 + 240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 240 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
    c2da_mem[ent_0 + 112 + 0 * 4] = uint8(c2da_fresh67)
    c2da_mem[ent_0 + 112 + 0 * 4 + 1] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[ent_0 + 112 + 0 * 4 + 2] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[ent_0 + 112 + 0 * 4 + 3] = uint8(c2da_fresh67 >> 0x18)
    let c2da_fresh68 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 1 * 4]) | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_0 + 240 + 1 * 4]) | uint(c2da_mem[ent_0 + 240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 240 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh69 : uint = float_bits_to_uint(c2da_fresh68)
    c2da_mem[ent_0 + 112 + 1 * 4] = uint8(c2da_fresh69)
    c2da_mem[ent_0 + 112 + 1 * 4 + 1] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[ent_0 + 112 + 1 * 4 + 2] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[ent_0 + 112 + 1 * 4 + 3] = uint8(c2da_fresh69 >> 0x18)
    let c2da_fresh70 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 2 * 4]) | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_0 + 240 + 2 * 4]) | uint(c2da_mem[ent_0 + 240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 240 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh71 : uint = float_bits_to_uint(c2da_fresh70)
    c2da_mem[ent_0 + 112 + 2 * 4] = uint8(c2da_fresh71)
    c2da_mem[ent_0 + 112 + 2 * 4 + 1] = uint8(c2da_fresh71 >> 0x8)
    c2da_mem[ent_0 + 112 + 2 * 4 + 2] = uint8(c2da_fresh71 >> 0x10)
    c2da_mem[ent_0 + 112 + 2 * 4 + 3] = uint8(c2da_fresh71 >> 0x18)
    let c2da_fresh72 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 0 * 4]) | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_0 + 252 + 0 * 4]) | uint(c2da_mem[ent_0 + 252 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 252 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 252 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh73 : uint = float_bits_to_uint(c2da_fresh72)
    c2da_mem[ent_0 + 124 + 0 * 4] = uint8(c2da_fresh73)
    c2da_mem[ent_0 + 124 + 0 * 4 + 1] = uint8(c2da_fresh73 >> 0x8)
    c2da_mem[ent_0 + 124 + 0 * 4 + 2] = uint8(c2da_fresh73 >> 0x10)
    c2da_mem[ent_0 + 124 + 0 * 4 + 3] = uint8(c2da_fresh73 >> 0x18)
    let c2da_fresh74 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 1 * 4]) | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_0 + 252 + 1 * 4]) | uint(c2da_mem[ent_0 + 252 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 252 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 252 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh75 : uint = float_bits_to_uint(c2da_fresh74)
    c2da_mem[ent_0 + 124 + 1 * 4] = uint8(c2da_fresh75)
    c2da_mem[ent_0 + 124 + 1 * 4 + 1] = uint8(c2da_fresh75 >> 0x8)
    c2da_mem[ent_0 + 124 + 1 * 4 + 2] = uint8(c2da_fresh75 >> 0x10)
    c2da_mem[ent_0 + 124 + 1 * 4 + 3] = uint8(c2da_fresh75 >> 0x18)
    let c2da_fresh76 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 2 * 4]) | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_0 + 252 + 2 * 4]) | uint(c2da_mem[ent_0 + 252 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 252 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 252 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh77 : uint = float_bits_to_uint(c2da_fresh76)
    c2da_mem[ent_0 + 124 + 2 * 4] = uint8(c2da_fresh77)
    c2da_mem[ent_0 + 124 + 2 * 4 + 1] = uint8(c2da_fresh77 >> 0x8)
    c2da_mem[ent_0 + 124 + 2 * 4 + 2] = uint8(c2da_fresh77 >> 0x10)
    c2da_mem[ent_0 + 124 + 2 * 4 + 3] = uint8(c2da_fresh77 >> 0x18)
    if ((int(uint_bits_to_float(uint(c2da_mem[ent_0 + 412]) | uint(c2da_mem[ent_0 + 413]) << 0x8 | uint(c2da_mem[ent_0 + 414]) << 0x10 | uint(c2da_mem[ent_0 + 415]) << 0x18)) & 256) != 0) {
        let c2da_fresh78 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 112 + 0 * 4]) | uint(c2da_mem[ent_0 + 112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 112 + 0 * 4 + 3]) << 0x18) - 15.0
        let c2da_fresh79 : uint = float_bits_to_uint(c2da_fresh78)
        c2da_mem[ent_0 + 112 + 0 * 4] = uint8(c2da_fresh79)
        c2da_mem[ent_0 + 112 + 0 * 4 + 1] = uint8(c2da_fresh79 >> 0x8)
        c2da_mem[ent_0 + 112 + 0 * 4 + 2] = uint8(c2da_fresh79 >> 0x10)
        c2da_mem[ent_0 + 112 + 0 * 4 + 3] = uint8(c2da_fresh79 >> 0x18)
        let c2da_fresh80 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 112 + 1 * 4]) | uint(c2da_mem[ent_0 + 112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 112 + 1 * 4 + 3]) << 0x18) - 15.0
        let c2da_fresh81 : uint = float_bits_to_uint(c2da_fresh80)
        c2da_mem[ent_0 + 112 + 1 * 4] = uint8(c2da_fresh81)
        c2da_mem[ent_0 + 112 + 1 * 4 + 1] = uint8(c2da_fresh81 >> 0x8)
        c2da_mem[ent_0 + 112 + 1 * 4 + 2] = uint8(c2da_fresh81 >> 0x10)
        c2da_mem[ent_0 + 112 + 1 * 4 + 3] = uint8(c2da_fresh81 >> 0x18)
        let c2da_fresh82 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 124 + 0 * 4]) | uint(c2da_mem[ent_0 + 124 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 124 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 124 + 0 * 4 + 3]) << 0x18) + 15.0
        let c2da_fresh83 : uint = float_bits_to_uint(c2da_fresh82)
        c2da_mem[ent_0 + 124 + 0 * 4] = uint8(c2da_fresh83)
        c2da_mem[ent_0 + 124 + 0 * 4 + 1] = uint8(c2da_fresh83 >> 0x8)
        c2da_mem[ent_0 + 124 + 0 * 4 + 2] = uint8(c2da_fresh83 >> 0x10)
        c2da_mem[ent_0 + 124 + 0 * 4 + 3] = uint8(c2da_fresh83 >> 0x18)
        let c2da_fresh84 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 124 + 1 * 4]) | uint(c2da_mem[ent_0 + 124 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 124 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 124 + 1 * 4 + 3]) << 0x18) + 15.0
        let c2da_fresh85 : uint = float_bits_to_uint(c2da_fresh84)
        c2da_mem[ent_0 + 124 + 1 * 4] = uint8(c2da_fresh85)
        c2da_mem[ent_0 + 124 + 1 * 4 + 1] = uint8(c2da_fresh85 >> 0x8)
        c2da_mem[ent_0 + 124 + 1 * 4 + 2] = uint8(c2da_fresh85 >> 0x10)
        c2da_mem[ent_0 + 124 + 1 * 4 + 3] = uint8(c2da_fresh85 >> 0x18)
    } else {
        let c2da_fresh86 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 112 + 0 * 4]) | uint(c2da_mem[ent_0 + 112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 112 + 0 * 4 + 3]) << 0x18) - 1.0
        let c2da_fresh87 : uint = float_bits_to_uint(c2da_fresh86)
        c2da_mem[ent_0 + 112 + 0 * 4] = uint8(c2da_fresh87)
        c2da_mem[ent_0 + 112 + 0 * 4 + 1] = uint8(c2da_fresh87 >> 0x8)
        c2da_mem[ent_0 + 112 + 0 * 4 + 2] = uint8(c2da_fresh87 >> 0x10)
        c2da_mem[ent_0 + 112 + 0 * 4 + 3] = uint8(c2da_fresh87 >> 0x18)
        let c2da_fresh88 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 112 + 1 * 4]) | uint(c2da_mem[ent_0 + 112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 112 + 1 * 4 + 3]) << 0x18) - 1.0
        let c2da_fresh89 : uint = float_bits_to_uint(c2da_fresh88)
        c2da_mem[ent_0 + 112 + 1 * 4] = uint8(c2da_fresh89)
        c2da_mem[ent_0 + 112 + 1 * 4 + 1] = uint8(c2da_fresh89 >> 0x8)
        c2da_mem[ent_0 + 112 + 1 * 4 + 2] = uint8(c2da_fresh89 >> 0x10)
        c2da_mem[ent_0 + 112 + 1 * 4 + 3] = uint8(c2da_fresh89 >> 0x18)
        let c2da_fresh90 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 112 + 2 * 4]) | uint(c2da_mem[ent_0 + 112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 112 + 2 * 4 + 3]) << 0x18) - 1.0
        let c2da_fresh91 : uint = float_bits_to_uint(c2da_fresh90)
        c2da_mem[ent_0 + 112 + 2 * 4] = uint8(c2da_fresh91)
        c2da_mem[ent_0 + 112 + 2 * 4 + 1] = uint8(c2da_fresh91 >> 0x8)
        c2da_mem[ent_0 + 112 + 2 * 4 + 2] = uint8(c2da_fresh91 >> 0x10)
        c2da_mem[ent_0 + 112 + 2 * 4 + 3] = uint8(c2da_fresh91 >> 0x18)
        let c2da_fresh92 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 124 + 0 * 4]) | uint(c2da_mem[ent_0 + 124 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 124 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 124 + 0 * 4 + 3]) << 0x18) + 1.0
        let c2da_fresh93 : uint = float_bits_to_uint(c2da_fresh92)
        c2da_mem[ent_0 + 124 + 0 * 4] = uint8(c2da_fresh93)
        c2da_mem[ent_0 + 124 + 0 * 4 + 1] = uint8(c2da_fresh93 >> 0x8)
        c2da_mem[ent_0 + 124 + 0 * 4 + 2] = uint8(c2da_fresh93 >> 0x10)
        c2da_mem[ent_0 + 124 + 0 * 4 + 3] = uint8(c2da_fresh93 >> 0x18)
        let c2da_fresh94 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 124 + 1 * 4]) | uint(c2da_mem[ent_0 + 124 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 124 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 124 + 1 * 4 + 3]) << 0x18) + 1.0
        let c2da_fresh95 : uint = float_bits_to_uint(c2da_fresh94)
        c2da_mem[ent_0 + 124 + 1 * 4] = uint8(c2da_fresh95)
        c2da_mem[ent_0 + 124 + 1 * 4 + 1] = uint8(c2da_fresh95 >> 0x8)
        c2da_mem[ent_0 + 124 + 1 * 4 + 2] = uint8(c2da_fresh95 >> 0x10)
        c2da_mem[ent_0 + 124 + 1 * 4 + 3] = uint8(c2da_fresh95 >> 0x18)
        let c2da_fresh96 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 124 + 2 * 4]) | uint(c2da_mem[ent_0 + 124 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 124 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 124 + 2 * 4 + 3]) << 0x18) + 1.0
        let c2da_fresh97 : uint = float_bits_to_uint(c2da_fresh96)
        c2da_mem[ent_0 + 124 + 2 * 4] = uint8(c2da_fresh97)
        c2da_mem[ent_0 + 124 + 2 * 4 + 1] = uint8(c2da_fresh97 >> 0x8)
        c2da_mem[ent_0 + 124 + 2 * 4 + 2] = uint8(c2da_fresh97 >> 0x10)
        c2da_mem[ent_0 + 124 + 2 * 4 + 3] = uint8(c2da_fresh97 >> 0x18)
    }
    let c2da_fresh98 : int = 0
    let c2da_fresh99 : uint = uint(c2da_fresh98)
    c2da_mem[ent_0 + 24] = uint8(c2da_fresh99)
    c2da_mem[ent_0 + 25] = uint8(c2da_fresh99 >> 0x8)
    c2da_mem[ent_0 + 26] = uint8(c2da_fresh99 >> 0x10)
    c2da_mem[ent_0 + 27] = uint8(c2da_fresh99 >> 0x18)
    if (uint_bits_to_float(uint(c2da_mem[ent_0 + 108]) | uint(c2da_mem[ent_0 + 109]) << 0x8 | uint(c2da_mem[ent_0 + 110]) << 0x10 | uint(c2da_mem[ent_0 + 111]) << 0x18) != 0.0) {
        let c2da_fresh100 : int = int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) + 208
        SV_FindTouchedLeafs(ent_0, int(uint(c2da_mem[c2da_fresh100]) | uint(c2da_mem[c2da_fresh100 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh100 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh100 + 3]) << 0x18))
    }
    if (uint_bits_to_float(uint(c2da_mem[ent_0 + 144]) | uint(c2da_mem[ent_0 + 145]) << 0x8 | uint(c2da_mem[ent_0 + 146]) << 0x10 | uint(c2da_mem[ent_0 + 147]) << 0x18) == 0.0) {
        return
    }
    node = 737856
    while (true) {
        if (int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18) == -1) {
            break
        }
        let c2da_fresh101 : int = ent_0 + 112 + int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18) * 4
        if (uint_bits_to_float(uint(c2da_mem[c2da_fresh101]) | uint(c2da_mem[c2da_fresh101 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh101 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh101 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[node + 4]) | uint(c2da_mem[node + 5]) << 0x8 | uint(c2da_mem[node + 6]) << 0x10 | uint(c2da_mem[node + 7]) << 0x18)) {
            node = int(uint(c2da_mem[node + 8 + 0 * 8]) | uint(c2da_mem[node + 8 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[node + 8 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[node + 8 + 0 * 8 + 3]) << 0x18)
        } else {
            let c2da_fresh102 : int = ent_0 + 124 + int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18) * 4
            if (uint_bits_to_float(uint(c2da_mem[c2da_fresh102]) | uint(c2da_mem[c2da_fresh102 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh102 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh102 + 3]) << 0x18) < uint_bits_to_float(uint(c2da_mem[node + 4]) | uint(c2da_mem[node + 5]) << 0x8 | uint(c2da_mem[node + 6]) << 0x10 | uint(c2da_mem[node + 7]) << 0x18)) {
                node = int(uint(c2da_mem[node + 8 + 1 * 8]) | uint(c2da_mem[node + 8 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[node + 8 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[node + 8 + 1 * 8 + 3]) << 0x18)
            } else {
                break
            }
        }
    }
    if (uint_bits_to_float(uint(c2da_mem[ent_0 + 144]) | uint(c2da_mem[ent_0 + 145]) << 0x8 | uint(c2da_mem[ent_0 + 146]) << 0x10 | uint(c2da_mem[ent_0 + 147]) << 0x18) == 1.0) {
        InsertLinkBefore(ent_0 + 8, node + 24)
    } else {
        InsertLinkBefore(ent_0 + 8, node + 40)
    }
    if (touch_triggers != 0u) {
        SV_TouchLinks(ent_0, 737856)
    }
    return
}
[export, sideeffects]
def SV_TouchLinks(var ent_1 : int; var node_0 : int) {
    var l : int
    var next : int
    var touch : int
    var old_self : int
    var old_other : int
    l = int(uint(c2da_mem[node_0 + 32]) | uint(c2da_mem[node_0 + 33]) << 0x8 | uint(c2da_mem[node_0 + 34]) << 0x10 | uint(c2da_mem[node_0 + 35]) << 0x18)
    while (l != node_0 + 24) {
        next = int(uint(c2da_mem[l + 8]) | uint(c2da_mem[l + 9]) << 0x8 | uint(c2da_mem[l + 10]) << 0x10 | uint(c2da_mem[l + 11]) << 0x18)
        touch = l - 8
        if (touch == ent_1) {
            l = next
            continue
        }
        if (int(uint(c2da_mem[touch + 276]) | uint(c2da_mem[touch + 277]) << 0x8 | uint(c2da_mem[touch + 278]) << 0x10 | uint(c2da_mem[touch + 279]) << 0x18) == 0 || uint_bits_to_float(uint(c2da_mem[touch + 144]) | uint(c2da_mem[touch + 145]) << 0x8 | uint(c2da_mem[touch + 146]) << 0x10 | uint(c2da_mem[touch + 147]) << 0x18) != 1.0) {
            l = next
            continue
        }
        if (uint_bits_to_float(uint(c2da_mem[ent_1 + 112 + 0 * 4]) | uint(c2da_mem[ent_1 + 112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 112 + 0 * 4 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[touch + 124 + 0 * 4]) | uint(c2da_mem[touch + 124 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[touch + 124 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[touch + 124 + 0 * 4 + 3]) << 0x18) || uint_bits_to_float(uint(c2da_mem[ent_1 + 112 + 1 * 4]) | uint(c2da_mem[ent_1 + 112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 112 + 1 * 4 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[touch + 124 + 1 * 4]) | uint(c2da_mem[touch + 124 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[touch + 124 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[touch + 124 + 1 * 4 + 3]) << 0x18) || uint_bits_to_float(uint(c2da_mem[ent_1 + 112 + 2 * 4]) | uint(c2da_mem[ent_1 + 112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 112 + 2 * 4 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[touch + 124 + 2 * 4]) | uint(c2da_mem[touch + 124 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[touch + 124 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[touch + 124 + 2 * 4 + 3]) << 0x18) || uint_bits_to_float(uint(c2da_mem[ent_1 + 124 + 0 * 4]) | uint(c2da_mem[ent_1 + 124 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 124 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 124 + 0 * 4 + 3]) << 0x18) < uint_bits_to_float(uint(c2da_mem[touch + 112 + 0 * 4]) | uint(c2da_mem[touch + 112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[touch + 112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[touch + 112 + 0 * 4 + 3]) << 0x18) || uint_bits_to_float(uint(c2da_mem[ent_1 + 124 + 1 * 4]) | uint(c2da_mem[ent_1 + 124 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 124 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 124 + 1 * 4 + 3]) << 0x18) < uint_bits_to_float(uint(c2da_mem[touch + 112 + 1 * 4]) | uint(c2da_mem[touch + 112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[touch + 112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[touch + 112 + 1 * 4 + 3]) << 0x18) || uint_bits_to_float(uint(c2da_mem[ent_1 + 124 + 2 * 4]) | uint(c2da_mem[ent_1 + 124 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_1 + 124 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_1 + 124 + 2 * 4 + 3]) << 0x18) < uint_bits_to_float(uint(c2da_mem[touch + 112 + 2 * 4]) | uint(c2da_mem[touch + 112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[touch + 112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[touch + 112 + 2 * 4 + 3]) << 0x18)) {
            l = next
            continue
        }
        old_self = int(uint(c2da_mem[pr_global_struct + 112]) | uint(c2da_mem[pr_global_struct + 113]) << 0x8 | uint(c2da_mem[pr_global_struct + 114]) << 0x10 | uint(c2da_mem[pr_global_struct + 115]) << 0x18)
        old_other = int(uint(c2da_mem[pr_global_struct + 116]) | uint(c2da_mem[pr_global_struct + 117]) << 0x8 | uint(c2da_mem[pr_global_struct + 118]) << 0x10 | uint(c2da_mem[pr_global_struct + 119]) << 0x18)
        let c2da_fresh103 : int = touch - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh104 : uint = uint(c2da_fresh103)
        c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh104)
        c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh104 >> 0x8)
        c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh104 >> 0x10)
        c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh104 >> 0x18)
        let c2da_fresh105 : int = ent_1 - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh106 : uint = uint(c2da_fresh105)
        c2da_mem[pr_global_struct + 116] = uint8(c2da_fresh106)
        c2da_mem[pr_global_struct + 117] = uint8(c2da_fresh106 >> 0x8)
        c2da_mem[pr_global_struct + 118] = uint8(c2da_fresh106 >> 0x10)
        c2da_mem[pr_global_struct + 119] = uint8(c2da_fresh106 >> 0x18)
        let c2da_fresh107 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20))
        let c2da_fresh108 : uint = float_bits_to_uint(c2da_fresh107)
        c2da_mem[pr_global_struct + 124] = uint8(c2da_fresh108)
        c2da_mem[pr_global_struct + 125] = uint8(c2da_fresh108 >> 0x8)
        c2da_mem[pr_global_struct + 126] = uint8(c2da_fresh108 >> 0x10)
        c2da_mem[pr_global_struct + 127] = uint8(c2da_fresh108 >> 0x18)
        PR_ExecuteProgram(int(uint(c2da_mem[touch + 276]) | uint(c2da_mem[touch + 277]) << 0x8 | uint(c2da_mem[touch + 278]) << 0x10 | uint(c2da_mem[touch + 279]) << 0x18))
        let c2da_fresh109 : uint = uint(old_self)
        c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh109)
        c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh109 >> 0x8)
        c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh109 >> 0x10)
        c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh109 >> 0x18)
        let c2da_fresh110 : uint = uint(old_other)
        c2da_mem[pr_global_struct + 116] = uint8(c2da_fresh110)
        c2da_mem[pr_global_struct + 117] = uint8(c2da_fresh110 >> 0x8)
        c2da_mem[pr_global_struct + 118] = uint8(c2da_fresh110 >> 0x10)
        c2da_mem[pr_global_struct + 119] = uint8(c2da_fresh110 >> 0x18)
        l = next
    }
    if (int(uint(c2da_mem[node_0]) | uint(c2da_mem[node_0 + 1]) << 0x8 | uint(c2da_mem[node_0 + 2]) << 0x10 | uint(c2da_mem[node_0 + 3]) << 0x18) == -1) {
        return
    }
    let c2da_fresh111 : int = ent_1 + 124 + int(uint(c2da_mem[node_0]) | uint(c2da_mem[node_0 + 1]) << 0x8 | uint(c2da_mem[node_0 + 2]) << 0x10 | uint(c2da_mem[node_0 + 3]) << 0x18) * 4
    if (uint_bits_to_float(uint(c2da_mem[c2da_fresh111]) | uint(c2da_mem[c2da_fresh111 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh111 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh111 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[node_0 + 4]) | uint(c2da_mem[node_0 + 5]) << 0x8 | uint(c2da_mem[node_0 + 6]) << 0x10 | uint(c2da_mem[node_0 + 7]) << 0x18)) {
        SV_TouchLinks(ent_1, int(uint(c2da_mem[node_0 + 8 + 0 * 8]) | uint(c2da_mem[node_0 + 8 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[node_0 + 8 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[node_0 + 8 + 0 * 8 + 3]) << 0x18))
    }
    let c2da_fresh112 : int = ent_1 + 112 + int(uint(c2da_mem[node_0]) | uint(c2da_mem[node_0 + 1]) << 0x8 | uint(c2da_mem[node_0 + 2]) << 0x10 | uint(c2da_mem[node_0 + 3]) << 0x18) * 4
    if (uint_bits_to_float(uint(c2da_mem[c2da_fresh112]) | uint(c2da_mem[c2da_fresh112 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh112 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh112 + 3]) << 0x18) < uint_bits_to_float(uint(c2da_mem[node_0 + 4]) | uint(c2da_mem[node_0 + 5]) << 0x8 | uint(c2da_mem[node_0 + 6]) << 0x10 | uint(c2da_mem[node_0 + 7]) << 0x18)) {
        SV_TouchLinks(ent_1, int(uint(c2da_mem[node_0 + 8 + 1 * 8]) | uint(c2da_mem[node_0 + 8 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[node_0 + 8 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[node_0 + 8 + 1 * 8 + 3]) << 0x18))
    }
    return
}
[export, sideeffects]
def SV_FindTouchedLeafs(var ent_2 : int; var node_1 : int) {
    var splitplane : int
    var sides : int
    var leafnum : int
    if (int(uint(c2da_mem[node_1]) | uint(c2da_mem[node_1 + 1]) << 0x8 | uint(c2da_mem[node_1 + 2]) << 0x10 | uint(c2da_mem[node_1 + 3]) << 0x18) == -2) {
        return
    }
    if (int(uint(c2da_mem[node_1]) | uint(c2da_mem[node_1 + 1]) << 0x8 | uint(c2da_mem[node_1 + 2]) << 0x10 | uint(c2da_mem[node_1 + 3]) << 0x18) < 0) {
        if (int(uint(c2da_mem[ent_2 + 24]) | uint(c2da_mem[ent_2 + 25]) << 0x8 | uint(c2da_mem[ent_2 + 26]) << 0x10 | uint(c2da_mem[ent_2 + 27]) << 0x18) == 16) {
            return
        }
        let c2da_fresh113 : int = int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) + 160
        leafnum = int(int64((node_1 - int(uint(c2da_mem[c2da_fresh113]) | uint(c2da_mem[c2da_fresh113 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh113 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh113 + 3]) << 0x18)) / 72) - 1l)
        let c2da_fresh114 : int = int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) + 160
        leafnum = int(int64((node_1 - int(uint(c2da_mem[c2da_fresh114]) | uint(c2da_mem[c2da_fresh114 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh114 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh114 + 3]) << 0x18)) / 72) - 1l)
        let c2da_fresh115 : int = ent_2 + 28 + int(uint(c2da_mem[ent_2 + 24]) | uint(c2da_mem[ent_2 + 25]) << 0x8 | uint(c2da_mem[ent_2 + 26]) << 0x10 | uint(c2da_mem[ent_2 + 27]) << 0x18) * 2
        let c2da_fresh116 : int16 = int16(leafnum)
        let c2da_fresh117 : uint = uint(c2da_fresh116)
        c2da_mem[c2da_fresh115] = uint8(c2da_fresh117)
        c2da_mem[c2da_fresh115 + 1] = uint8(c2da_fresh117 >> 0x8)
        let c2da_fresh118 : int = int(uint(c2da_mem[ent_2 + 24]) | uint(c2da_mem[ent_2 + 25]) << 0x8 | uint(c2da_mem[ent_2 + 26]) << 0x10 | uint(c2da_mem[ent_2 + 27]) << 0x18)
        let c2da_fresh119 : int = c2da_fresh118 + 1
        let c2da_fresh120 : uint = uint(c2da_fresh119)
        c2da_mem[ent_2 + 24] = uint8(c2da_fresh120)
        c2da_mem[ent_2 + 25] = uint8(c2da_fresh120 >> 0x8)
        c2da_mem[ent_2 + 26] = uint8(c2da_fresh120 >> 0x10)
        c2da_mem[ent_2 + 27] = uint8(c2da_fresh120 >> 0x18)
        return
    }
    splitplane = int(uint(c2da_mem[node_1 + 32]) | uint(c2da_mem[node_1 + 33]) << 0x8 | uint(c2da_mem[node_1 + 34]) << 0x10 | uint(c2da_mem[node_1 + 35]) << 0x18)
    var c2da_fresh124 : int = 0
    if (int(c2da_mem[splitplane + 16]) < 3) {
        let c2da_fresh121 : int = ent_2 + 112 + int(c2da_mem[splitplane + 16]) * 4
        var c2da_fresh123 : int = 0
        if (uint_bits_to_float(uint(c2da_mem[splitplane + 12]) | uint(c2da_mem[splitplane + 13]) << 0x8 | uint(c2da_mem[splitplane + 14]) << 0x10 | uint(c2da_mem[splitplane + 15]) << 0x18) <= uint_bits_to_float(uint(c2da_mem[c2da_fresh121]) | uint(c2da_mem[c2da_fresh121 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh121 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh121 + 3]) << 0x18)) {
            c2da_fresh123 = 1
        } else {
            let c2da_fresh122 : int = ent_2 + 124 + int(c2da_mem[splitplane + 16]) * 4
            c2da_fresh123 = uint_bits_to_float(uint(c2da_mem[splitplane + 12]) | uint(c2da_mem[splitplane + 13]) << 0x8 | uint(c2da_mem[splitplane + 14]) << 0x10 | uint(c2da_mem[splitplane + 15]) << 0x18) >= uint_bits_to_float(uint(c2da_mem[c2da_fresh122]) | uint(c2da_mem[c2da_fresh122 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh122 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh122 + 3]) << 0x18) ? 2 : 3
        }
        c2da_fresh124 = c2da_fresh123
    } else {
        c2da_fresh124 = BoxOnPlaneSide(ent_2 + 112, ent_2 + 124, splitplane)
    }
    sides = c2da_fresh124
    if ((sides & 1) != 0) {
        SV_FindTouchedLeafs(ent_2, int(uint(c2da_mem[node_1 + 40 + 0 * 8]) | uint(c2da_mem[node_1 + 40 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[node_1 + 40 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[node_1 + 40 + 0 * 8 + 3]) << 0x18))
    }
    if ((sides & 2) != 0) {
        SV_FindTouchedLeafs(ent_2, int(uint(c2da_mem[node_1 + 40 + 1 * 8]) | uint(c2da_mem[node_1 + 40 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[node_1 + 40 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[node_1 + 40 + 1 * 8 + 3]) << 0x18))
    }
    return
}
[export, sideeffects]
def SV_PointContents(var p : int) : int {
    var cont : int = SV_HullPointContents(int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) + 296 + 0 * 48, 0, p)
    if (cont <= -9 && cont >= -14) {
        cont = -3
    }
    return cont
}
[export, sideeffects]
def SV_HullPointContents(var hull : int; var num : int; var p_0 : int) : int {
    var d : float
    var node_2 : int
    var plane : int
    while (num >= 0) {
        if (num < int(uint(c2da_mem[hull + 16]) | uint(c2da_mem[hull + 17]) << 0x8 | uint(c2da_mem[hull + 18]) << 0x10 | uint(c2da_mem[hull + 19]) << 0x18) || num > int(uint(c2da_mem[hull + 20]) | uint(c2da_mem[hull + 21]) << 0x8 | uint(c2da_mem[hull + 22]) << 0x10 | uint(c2da_mem[hull + 23]) << 0x18)) {
            Sys_Error(739872, [])
        }
        node_2 = int(uint(c2da_mem[hull]) | uint(c2da_mem[hull + 1]) << 0x8 | uint(c2da_mem[hull + 2]) << 0x10 | uint(c2da_mem[hull + 3]) << 0x18) + num * 8
        plane = int(uint(c2da_mem[hull + 8]) | uint(c2da_mem[hull + 9]) << 0x8 | uint(c2da_mem[hull + 10]) << 0x10 | uint(c2da_mem[hull + 11]) << 0x18) + int(uint(c2da_mem[node_2]) | uint(c2da_mem[node_2 + 1]) << 0x8 | uint(c2da_mem[node_2 + 2]) << 0x10 | uint(c2da_mem[node_2 + 3]) << 0x18) * 20
        if (int(c2da_mem[plane + 16]) < 3) {
            let c2da_fresh125 : int = p_0 + int(c2da_mem[plane + 16]) * 4
            d = uint_bits_to_float(uint(c2da_mem[c2da_fresh125]) | uint(c2da_mem[c2da_fresh125 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh125 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh125 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane + 12]) | uint(c2da_mem[plane + 13]) << 0x8 | uint(c2da_mem[plane + 14]) << 0x10 | uint(c2da_mem[plane + 15]) << 0x18)
        } else {
            d = uint_bits_to_float(uint(c2da_mem[plane + 0 * 4]) | uint(c2da_mem[plane + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[p_0 + 0 * 4]) | uint(c2da_mem[p_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p_0 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[plane + 1 * 4]) | uint(c2da_mem[plane + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[p_0 + 1 * 4]) | uint(c2da_mem[p_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p_0 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[plane + 2 * 4]) | uint(c2da_mem[plane + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plane + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plane + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[p_0 + 2 * 4]) | uint(c2da_mem[p_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p_0 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane + 12]) | uint(c2da_mem[plane + 13]) << 0x8 | uint(c2da_mem[plane + 14]) << 0x10 | uint(c2da_mem[plane + 15]) << 0x18)
        }
        if (d < 0.0) {
            num = int(int16(uint(c2da_mem[node_2 + 4 + 1 * 2]) | uint(c2da_mem[node_2 + 4 + 1 * 2 + 1]) << 0x8))
        } else {
            num = int(int16(uint(c2da_mem[node_2 + 4 + 0 * 2]) | uint(c2da_mem[node_2 + 4 + 0 * 2 + 1]) << 0x8))
        }
    }
    return num
}
[export, sideeffects]
def SV_TruePointContents(var p_1 : int) : int {
    return SV_HullPointContents(int(uint(c2da_mem[226024]) | uint(c2da_mem[226025]) << 0x8 | uint(c2da_mem[226026]) << 0x10 | uint(c2da_mem[226027]) << 0x18) + 296 + 0 * 48, 0, p_1)
}
[export, sideeffects]
def SV_TestEntityPosition(var ent_3 : int) : int {
    var trace : trace_t = SV_Move(ent_3 + 148, ent_3 + 240, ent_3 + 252, ent_3 + 148, 0, ent_3)
    if (trace.startsolid != 0u) {
        return int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    }
    return 0
}
[export, sideeffects]
def SV_Move(var start : int; var mins_0 : int; var maxs_0 : int; var end : int; var type_0 : int; var passedict : int) : trace_t {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : trace_t = SV_Move_c2da_frame(start, mins_0, maxs_0, end, type_0, passedict, c2da_lin_enter(160))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def SV_ClipToLinks(var node_3 : int; var clip : int) {
    var l_0 : int
    var next_0 : int
    var touch_0 : int
    var trace_0 : trace_t
    l_0 = int(uint(c2da_mem[node_3 + 48]) | uint(c2da_mem[node_3 + 49]) << 0x8 | uint(c2da_mem[node_3 + 50]) << 0x10 | uint(c2da_mem[node_3 + 51]) << 0x18)
    while (l_0 != node_3 + 40) {
        next_0 = int(uint(c2da_mem[l_0 + 8]) | uint(c2da_mem[l_0 + 9]) << 0x8 | uint(c2da_mem[l_0 + 10]) << 0x10 | uint(c2da_mem[l_0 + 11]) << 0x18)
        touch_0 = l_0 - 8
        if (uint_bits_to_float(uint(c2da_mem[touch_0 + 144]) | uint(c2da_mem[touch_0 + 145]) << 0x8 | uint(c2da_mem[touch_0 + 146]) << 0x10 | uint(c2da_mem[touch_0 + 147]) << 0x18) == 0.0) {
            l_0 = next_0
            continue
        }
        if (touch_0 == int(uint(c2da_mem[clip + 144]) | uint(c2da_mem[clip + 145]) << 0x8 | uint(c2da_mem[clip + 146]) << 0x10 | uint(c2da_mem[clip + 147]) << 0x18)) {
            l_0 = next_0
            continue
        }
        if (uint_bits_to_float(uint(c2da_mem[touch_0 + 144]) | uint(c2da_mem[touch_0 + 145]) << 0x8 | uint(c2da_mem[touch_0 + 146]) << 0x10 | uint(c2da_mem[touch_0 + 147]) << 0x18) == 1.0) {
            Sys_Error(739910, [])
        }
        if (int(uint(c2da_mem[clip + 136]) | uint(c2da_mem[clip + 137]) << 0x8 | uint(c2da_mem[clip + 138]) << 0x10 | uint(c2da_mem[clip + 139]) << 0x18) == 1 && uint_bits_to_float(uint(c2da_mem[touch_0 + 144]) | uint(c2da_mem[touch_0 + 145]) << 0x8 | uint(c2da_mem[touch_0 + 146]) << 0x10 | uint(c2da_mem[touch_0 + 147]) << 0x18) != 4.0) {
            l_0 = next_0
            continue
        }
        if (uint_bits_to_float(uint(c2da_mem[clip + 0 * 4]) | uint(c2da_mem[clip + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[clip + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[clip + 0 * 4 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[touch_0 + 124 + 0 * 4]) | uint(c2da_mem[touch_0 + 124 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[touch_0 + 124 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[touch_0 + 124 + 0 * 4 + 3]) << 0x18) || uint_bits_to_float(uint(c2da_mem[clip + 1 * 4]) | uint(c2da_mem[clip + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[clip + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[clip + 1 * 4 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[touch_0 + 124 + 1 * 4]) | uint(c2da_mem[touch_0 + 124 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[touch_0 + 124 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[touch_0 + 124 + 1 * 4 + 3]) << 0x18) || uint_bits_to_float(uint(c2da_mem[clip + 2 * 4]) | uint(c2da_mem[clip + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[clip + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[clip + 2 * 4 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[touch_0 + 124 + 2 * 4]) | uint(c2da_mem[touch_0 + 124 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[touch_0 + 124 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[touch_0 + 124 + 2 * 4 + 3]) << 0x18) || uint_bits_to_float(uint(c2da_mem[clip + 12 + 0 * 4]) | uint(c2da_mem[clip + 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[clip + 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[clip + 12 + 0 * 4 + 3]) << 0x18) < uint_bits_to_float(uint(c2da_mem[touch_0 + 112 + 0 * 4]) | uint(c2da_mem[touch_0 + 112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[touch_0 + 112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[touch_0 + 112 + 0 * 4 + 3]) << 0x18) || uint_bits_to_float(uint(c2da_mem[clip + 12 + 1 * 4]) | uint(c2da_mem[clip + 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[clip + 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[clip + 12 + 1 * 4 + 3]) << 0x18) < uint_bits_to_float(uint(c2da_mem[touch_0 + 112 + 1 * 4]) | uint(c2da_mem[touch_0 + 112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[touch_0 + 112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[touch_0 + 112 + 1 * 4 + 3]) << 0x18) || uint_bits_to_float(uint(c2da_mem[clip + 12 + 2 * 4]) | uint(c2da_mem[clip + 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[clip + 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[clip + 12 + 2 * 4 + 3]) << 0x18) < uint_bits_to_float(uint(c2da_mem[touch_0 + 112 + 2 * 4]) | uint(c2da_mem[touch_0 + 112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[touch_0 + 112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[touch_0 + 112 + 2 * 4 + 3]) << 0x18)) {
            l_0 = next_0
            continue
        }
        var c2da_fresh164 : int = 0
        if (int(uint(c2da_mem[clip + 144]) | uint(c2da_mem[clip + 145]) << 0x8 | uint(c2da_mem[clip + 146]) << 0x10 | uint(c2da_mem[clip + 147]) << 0x18) != 0) {
            let c2da_fresh163 : int = int(uint(c2da_mem[clip + 144]) | uint(c2da_mem[clip + 145]) << 0x8 | uint(c2da_mem[clip + 146]) << 0x10 | uint(c2da_mem[clip + 147]) << 0x18) + 264 + 0 * 4
            if (uint_bits_to_float(uint(c2da_mem[c2da_fresh163]) | uint(c2da_mem[c2da_fresh163 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh163 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh163 + 3]) << 0x18) != 0.0) {
                c2da_fresh164 = 1
            }
        }
        if (c2da_fresh164 != 0 && uint_bits_to_float(uint(c2da_mem[touch_0 + 264 + 0 * 4]) | uint(c2da_mem[touch_0 + 264 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[touch_0 + 264 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[touch_0 + 264 + 0 * 4 + 3]) << 0x18) == 0.0) {
            l_0 = next_0
            continue
        }
        if ((uint(c2da_mem[clip + 80]) | uint(c2da_mem[clip + 81]) << 0x8 | uint(c2da_mem[clip + 82]) << 0x10 | uint(c2da_mem[clip + 83]) << 0x18) != 0u) {
            return
        }
        if (int(uint(c2da_mem[clip + 144]) | uint(c2da_mem[clip + 145]) << 0x8 | uint(c2da_mem[clip + 146]) << 0x10 | uint(c2da_mem[clip + 147]) << 0x18) != 0) {
            if (int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[touch_0 + 488]) | uint(c2da_mem[touch_0 + 489]) << 0x8 | uint(c2da_mem[touch_0 + 490]) << 0x10 | uint(c2da_mem[touch_0 + 491]) << 0x18) == int(uint(c2da_mem[clip + 144]) | uint(c2da_mem[clip + 145]) << 0x8 | uint(c2da_mem[clip + 146]) << 0x10 | uint(c2da_mem[clip + 147]) << 0x18)) {
                l_0 = next_0
                continue
            }
            let c2da_fresh165 : int = int(uint(c2da_mem[clip + 144]) | uint(c2da_mem[clip + 145]) << 0x8 | uint(c2da_mem[clip + 146]) << 0x10 | uint(c2da_mem[clip + 147]) << 0x18) + 488
            if (int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[c2da_fresh165]) | uint(c2da_mem[c2da_fresh165 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh165 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh165 + 3]) << 0x18) == touch_0) {
                l_0 = next_0
                continue
            }
        }
        if ((int(uint_bits_to_float(uint(c2da_mem[touch_0 + 412]) | uint(c2da_mem[touch_0 + 413]) << 0x8 | uint(c2da_mem[touch_0 + 414]) << 0x10 | uint(c2da_mem[touch_0 + 415]) << 0x18)) & 32) != 0) {
            trace_0 = SV_ClipMoveToEntity(touch_0, int(uint(c2da_mem[clip + 64]) | uint(c2da_mem[clip + 65]) << 0x8 | uint(c2da_mem[clip + 66]) << 0x10 | uint(c2da_mem[clip + 67]) << 0x18), clip + 40, clip + 52, int(uint(c2da_mem[clip + 72]) | uint(c2da_mem[clip + 73]) << 0x8 | uint(c2da_mem[clip + 74]) << 0x10 | uint(c2da_mem[clip + 75]) << 0x18))
        } else {
            trace_0 = SV_ClipMoveToEntity(touch_0, int(uint(c2da_mem[clip + 64]) | uint(c2da_mem[clip + 65]) << 0x8 | uint(c2da_mem[clip + 66]) << 0x10 | uint(c2da_mem[clip + 67]) << 0x18), int(uint(c2da_mem[clip + 24]) | uint(c2da_mem[clip + 25]) << 0x8 | uint(c2da_mem[clip + 26]) << 0x10 | uint(c2da_mem[clip + 27]) << 0x18), int(uint(c2da_mem[clip + 32]) | uint(c2da_mem[clip + 33]) << 0x8 | uint(c2da_mem[clip + 34]) << 0x10 | uint(c2da_mem[clip + 35]) << 0x18), int(uint(c2da_mem[clip + 72]) | uint(c2da_mem[clip + 73]) << 0x8 | uint(c2da_mem[clip + 74]) << 0x10 | uint(c2da_mem[clip + 75]) << 0x18))
        }
        if (trace_0.allsolid != 0x0 || trace_0.startsolid != 0x0 || trace_0.fraction < uint_bits_to_float(uint(c2da_mem[clip + 96]) | uint(c2da_mem[clip + 97]) << 0x8 | uint(c2da_mem[clip + 98]) << 0x10 | uint(c2da_mem[clip + 99]) << 0x18)) {
            trace_0.ent = touch_0
            if ((uint(c2da_mem[clip + 84]) | uint(c2da_mem[clip + 85]) << 0x8 | uint(c2da_mem[clip + 86]) << 0x10 | uint(c2da_mem[clip + 87]) << 0x18) != 0u) {
                let c2da_fresh166 : uint = trace_0.allsolid
                c2da_mem[clip + 80] = uint8(c2da_fresh166)
                c2da_mem[clip + 81] = uint8(c2da_fresh166 >> 0x8)
                c2da_mem[clip + 82] = uint8(c2da_fresh166 >> 0x10)
                c2da_mem[clip + 83] = uint8(c2da_fresh166 >> 0x18)
                let c2da_fresh167 : uint = trace_0.startsolid
                c2da_mem[clip + 84] = uint8(c2da_fresh167)
                c2da_mem[clip + 85] = uint8(c2da_fresh167 >> 0x8)
                c2da_mem[clip + 86] = uint8(c2da_fresh167 >> 0x10)
                c2da_mem[clip + 87] = uint8(c2da_fresh167 >> 0x18)
                let c2da_fresh168 : uint = trace_0.inopen
                c2da_mem[clip + 88] = uint8(c2da_fresh168)
                c2da_mem[clip + 89] = uint8(c2da_fresh168 >> 0x8)
                c2da_mem[clip + 90] = uint8(c2da_fresh168 >> 0x10)
                c2da_mem[clip + 91] = uint8(c2da_fresh168 >> 0x18)
                let c2da_fresh169 : uint = trace_0.inwater
                c2da_mem[clip + 92] = uint8(c2da_fresh169)
                c2da_mem[clip + 93] = uint8(c2da_fresh169 >> 0x8)
                c2da_mem[clip + 94] = uint8(c2da_fresh169 >> 0x10)
                c2da_mem[clip + 95] = uint8(c2da_fresh169 >> 0x18)
                let c2da_fresh170 : uint = float_bits_to_uint(trace_0.fraction)
                c2da_mem[clip + 96] = uint8(c2da_fresh170)
                c2da_mem[clip + 97] = uint8(c2da_fresh170 >> 0x8)
                c2da_mem[clip + 98] = uint8(c2da_fresh170 >> 0x10)
                c2da_mem[clip + 99] = uint8(c2da_fresh170 >> 0x18)
                let c2da_fresh171 : uint = float_bits_to_uint(trace_0.endpos[0])
                c2da_mem[clip + 100] = uint8(c2da_fresh171)
                c2da_mem[clip + 101] = uint8(c2da_fresh171 >> 0x8)
                c2da_mem[clip + 102] = uint8(c2da_fresh171 >> 0x10)
                c2da_mem[clip + 103] = uint8(c2da_fresh171 >> 0x18)
                let c2da_fresh172 : uint = float_bits_to_uint(trace_0.endpos[1])
                c2da_mem[clip + 104] = uint8(c2da_fresh172)
                c2da_mem[clip + 105] = uint8(c2da_fresh172 >> 0x8)
                c2da_mem[clip + 106] = uint8(c2da_fresh172 >> 0x10)
                c2da_mem[clip + 107] = uint8(c2da_fresh172 >> 0x18)
                let c2da_fresh173 : uint = float_bits_to_uint(trace_0.endpos[2])
                c2da_mem[clip + 108] = uint8(c2da_fresh173)
                c2da_mem[clip + 109] = uint8(c2da_fresh173 >> 0x8)
                c2da_mem[clip + 110] = uint8(c2da_fresh173 >> 0x10)
                c2da_mem[clip + 111] = uint8(c2da_fresh173 >> 0x18)
                let c2da_fresh174 : uint = float_bits_to_uint(trace_0.plane.normal[0])
                c2da_mem[clip + 112] = uint8(c2da_fresh174)
                c2da_mem[clip + 113] = uint8(c2da_fresh174 >> 0x8)
                c2da_mem[clip + 114] = uint8(c2da_fresh174 >> 0x10)
                c2da_mem[clip + 115] = uint8(c2da_fresh174 >> 0x18)
                let c2da_fresh175 : uint = float_bits_to_uint(trace_0.plane.normal[1])
                c2da_mem[clip + 116] = uint8(c2da_fresh175)
                c2da_mem[clip + 117] = uint8(c2da_fresh175 >> 0x8)
                c2da_mem[clip + 118] = uint8(c2da_fresh175 >> 0x10)
                c2da_mem[clip + 119] = uint8(c2da_fresh175 >> 0x18)
                let c2da_fresh176 : uint = float_bits_to_uint(trace_0.plane.normal[2])
                c2da_mem[clip + 120] = uint8(c2da_fresh176)
                c2da_mem[clip + 121] = uint8(c2da_fresh176 >> 0x8)
                c2da_mem[clip + 122] = uint8(c2da_fresh176 >> 0x10)
                c2da_mem[clip + 123] = uint8(c2da_fresh176 >> 0x18)
                let c2da_fresh177 : uint = float_bits_to_uint(trace_0.plane.dist)
                c2da_mem[clip + 124] = uint8(c2da_fresh177)
                c2da_mem[clip + 125] = uint8(c2da_fresh177 >> 0x8)
                c2da_mem[clip + 126] = uint8(c2da_fresh177 >> 0x10)
                c2da_mem[clip + 127] = uint8(c2da_fresh177 >> 0x18)
                let c2da_fresh178 : uint = uint(trace_0.ent)
                c2da_mem[clip + 128] = uint8(c2da_fresh178)
                c2da_mem[clip + 129] = uint8(c2da_fresh178 >> 0x8)
                c2da_mem[clip + 130] = uint8(c2da_fresh178 >> 0x10)
                c2da_mem[clip + 131] = uint8(c2da_fresh178 >> 0x18)
                c2da_mem[clip + 132] = 0u8
                c2da_mem[clip + 133] = 0u8
                c2da_mem[clip + 134] = 0u8
                c2da_mem[clip + 135] = 0u8
                let c2da_fresh179 : uint = 1u
                let c2da_fresh180 : uint = c2da_fresh179
                c2da_mem[clip + 84] = uint8(c2da_fresh180)
                c2da_mem[clip + 85] = uint8(c2da_fresh180 >> 0x8)
                c2da_mem[clip + 86] = uint8(c2da_fresh180 >> 0x10)
                c2da_mem[clip + 87] = uint8(c2da_fresh180 >> 0x18)
            } else {
                let c2da_fresh181 : uint = trace_0.allsolid
                c2da_mem[clip + 80] = uint8(c2da_fresh181)
                c2da_mem[clip + 81] = uint8(c2da_fresh181 >> 0x8)
                c2da_mem[clip + 82] = uint8(c2da_fresh181 >> 0x10)
                c2da_mem[clip + 83] = uint8(c2da_fresh181 >> 0x18)
                let c2da_fresh182 : uint = trace_0.startsolid
                c2da_mem[clip + 84] = uint8(c2da_fresh182)
                c2da_mem[clip + 85] = uint8(c2da_fresh182 >> 0x8)
                c2da_mem[clip + 86] = uint8(c2da_fresh182 >> 0x10)
                c2da_mem[clip + 87] = uint8(c2da_fresh182 >> 0x18)
                let c2da_fresh183 : uint = trace_0.inopen
                c2da_mem[clip + 88] = uint8(c2da_fresh183)
                c2da_mem[clip + 89] = uint8(c2da_fresh183 >> 0x8)
                c2da_mem[clip + 90] = uint8(c2da_fresh183 >> 0x10)
                c2da_mem[clip + 91] = uint8(c2da_fresh183 >> 0x18)
                let c2da_fresh184 : uint = trace_0.inwater
                c2da_mem[clip + 92] = uint8(c2da_fresh184)
                c2da_mem[clip + 93] = uint8(c2da_fresh184 >> 0x8)
                c2da_mem[clip + 94] = uint8(c2da_fresh184 >> 0x10)
                c2da_mem[clip + 95] = uint8(c2da_fresh184 >> 0x18)
                let c2da_fresh185 : uint = float_bits_to_uint(trace_0.fraction)
                c2da_mem[clip + 96] = uint8(c2da_fresh185)
                c2da_mem[clip + 97] = uint8(c2da_fresh185 >> 0x8)
                c2da_mem[clip + 98] = uint8(c2da_fresh185 >> 0x10)
                c2da_mem[clip + 99] = uint8(c2da_fresh185 >> 0x18)
                let c2da_fresh186 : uint = float_bits_to_uint(trace_0.endpos[0])
                c2da_mem[clip + 100] = uint8(c2da_fresh186)
                c2da_mem[clip + 101] = uint8(c2da_fresh186 >> 0x8)
                c2da_mem[clip + 102] = uint8(c2da_fresh186 >> 0x10)
                c2da_mem[clip + 103] = uint8(c2da_fresh186 >> 0x18)
                let c2da_fresh187 : uint = float_bits_to_uint(trace_0.endpos[1])
                c2da_mem[clip + 104] = uint8(c2da_fresh187)
                c2da_mem[clip + 105] = uint8(c2da_fresh187 >> 0x8)
                c2da_mem[clip + 106] = uint8(c2da_fresh187 >> 0x10)
                c2da_mem[clip + 107] = uint8(c2da_fresh187 >> 0x18)
                let c2da_fresh188 : uint = float_bits_to_uint(trace_0.endpos[2])
                c2da_mem[clip + 108] = uint8(c2da_fresh188)
                c2da_mem[clip + 109] = uint8(c2da_fresh188 >> 0x8)
                c2da_mem[clip + 110] = uint8(c2da_fresh188 >> 0x10)
                c2da_mem[clip + 111] = uint8(c2da_fresh188 >> 0x18)
                let c2da_fresh189 : uint = float_bits_to_uint(trace_0.plane.normal[0])
                c2da_mem[clip + 112] = uint8(c2da_fresh189)
                c2da_mem[clip + 113] = uint8(c2da_fresh189 >> 0x8)
                c2da_mem[clip + 114] = uint8(c2da_fresh189 >> 0x10)
                c2da_mem[clip + 115] = uint8(c2da_fresh189 >> 0x18)
                let c2da_fresh190 : uint = float_bits_to_uint(trace_0.plane.normal[1])
                c2da_mem[clip + 116] = uint8(c2da_fresh190)
                c2da_mem[clip + 117] = uint8(c2da_fresh190 >> 0x8)
                c2da_mem[clip + 118] = uint8(c2da_fresh190 >> 0x10)
                c2da_mem[clip + 119] = uint8(c2da_fresh190 >> 0x18)
                let c2da_fresh191 : uint = float_bits_to_uint(trace_0.plane.normal[2])
                c2da_mem[clip + 120] = uint8(c2da_fresh191)
                c2da_mem[clip + 121] = uint8(c2da_fresh191 >> 0x8)
                c2da_mem[clip + 122] = uint8(c2da_fresh191 >> 0x10)
                c2da_mem[clip + 123] = uint8(c2da_fresh191 >> 0x18)
                let c2da_fresh192 : uint = float_bits_to_uint(trace_0.plane.dist)
                c2da_mem[clip + 124] = uint8(c2da_fresh192)
                c2da_mem[clip + 125] = uint8(c2da_fresh192 >> 0x8)
                c2da_mem[clip + 126] = uint8(c2da_fresh192 >> 0x10)
                c2da_mem[clip + 127] = uint8(c2da_fresh192 >> 0x18)
                let c2da_fresh193 : uint = uint(trace_0.ent)
                c2da_mem[clip + 128] = uint8(c2da_fresh193)
                c2da_mem[clip + 129] = uint8(c2da_fresh193 >> 0x8)
                c2da_mem[clip + 130] = uint8(c2da_fresh193 >> 0x10)
                c2da_mem[clip + 131] = uint8(c2da_fresh193 >> 0x18)
                c2da_mem[clip + 132] = 0u8
                c2da_mem[clip + 133] = 0u8
                c2da_mem[clip + 134] = 0u8
                c2da_mem[clip + 135] = 0u8
            }
        } elif (trace_0.startsolid != 0u) {
            let c2da_fresh194 : uint = 1u
            let c2da_fresh195 : uint = c2da_fresh194
            c2da_mem[clip + 84] = uint8(c2da_fresh195)
            c2da_mem[clip + 85] = uint8(c2da_fresh195 >> 0x8)
            c2da_mem[clip + 86] = uint8(c2da_fresh195 >> 0x10)
            c2da_mem[clip + 87] = uint8(c2da_fresh195 >> 0x18)
        }
        l_0 = next_0
    }
    if (int(uint(c2da_mem[node_3]) | uint(c2da_mem[node_3 + 1]) << 0x8 | uint(c2da_mem[node_3 + 2]) << 0x10 | uint(c2da_mem[node_3 + 3]) << 0x18) == -1) {
        return
    }
    let c2da_fresh196 : int = clip + 12 + int(uint(c2da_mem[node_3]) | uint(c2da_mem[node_3 + 1]) << 0x8 | uint(c2da_mem[node_3 + 2]) << 0x10 | uint(c2da_mem[node_3 + 3]) << 0x18) * 4
    if (uint_bits_to_float(uint(c2da_mem[c2da_fresh196]) | uint(c2da_mem[c2da_fresh196 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh196 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh196 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[node_3 + 4]) | uint(c2da_mem[node_3 + 5]) << 0x8 | uint(c2da_mem[node_3 + 6]) << 0x10 | uint(c2da_mem[node_3 + 7]) << 0x18)) {
        SV_ClipToLinks(int(uint(c2da_mem[node_3 + 8 + 0 * 8]) | uint(c2da_mem[node_3 + 8 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[node_3 + 8 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[node_3 + 8 + 0 * 8 + 3]) << 0x18), clip)
    }
    let c2da_fresh197 : int = clip + int(uint(c2da_mem[node_3]) | uint(c2da_mem[node_3 + 1]) << 0x8 | uint(c2da_mem[node_3 + 2]) << 0x10 | uint(c2da_mem[node_3 + 3]) << 0x18) * 4
    if (uint_bits_to_float(uint(c2da_mem[c2da_fresh197]) | uint(c2da_mem[c2da_fresh197 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh197 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh197 + 3]) << 0x18) < uint_bits_to_float(uint(c2da_mem[node_3 + 4]) | uint(c2da_mem[node_3 + 5]) << 0x8 | uint(c2da_mem[node_3 + 6]) << 0x10 | uint(c2da_mem[node_3 + 7]) << 0x18)) {
        SV_ClipToLinks(int(uint(c2da_mem[node_3 + 8 + 1 * 8]) | uint(c2da_mem[node_3 + 8 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[node_3 + 8 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[node_3 + 8 + 1 * 8 + 3]) << 0x18), clip)
    }
    return
}
[export, sideeffects]
def SV_ClipMoveToEntity(var ent_4 : int; var start_0 : int; var mins_1 : int; var maxs_1 : int; var end_0 : int) : trace_t {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : trace_t = SV_ClipMoveToEntity_c2da_frame(ent_4, start_0, mins_1, maxs_1, end_0, c2da_lin_enter(112))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def SV_RecursiveHullCheck(var hull_1 : int; var num_0 : int; var p1f : float; var p2f : float; var p1 : int; var p2 : int; var trace_1 : int) : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = SV_RecursiveHullCheck_c2da_frame(hull_1, num_0, p1f, p2f, p1, p2, trace_1, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def SV_HullForEntity(var ent_5 : int; var mins_2 : int; var maxs_2 : int; var offset : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = SV_HullForEntity_c2da_frame(ent_5, mins_2, maxs_2, offset, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def SV_HullForBox(var mins_3 : int; var maxs_3 : int) : int {
    let c2da_fresh305 : float = uint_bits_to_float(uint(c2da_mem[maxs_3 + 0 * 4]) | uint(c2da_mem[maxs_3 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs_3 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs_3 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh306 : uint = float_bits_to_uint(c2da_fresh305)
    c2da_mem[739696 + 0 * 20 + 12] = uint8(c2da_fresh306)
    c2da_mem[739696 + 0 * 20 + 13] = uint8(c2da_fresh306 >> 0x8)
    c2da_mem[739696 + 0 * 20 + 14] = uint8(c2da_fresh306 >> 0x10)
    c2da_mem[739696 + 0 * 20 + 15] = uint8(c2da_fresh306 >> 0x18)
    let c2da_fresh307 : float = uint_bits_to_float(uint(c2da_mem[mins_3 + 0 * 4]) | uint(c2da_mem[mins_3 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_3 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_3 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh308 : uint = float_bits_to_uint(c2da_fresh307)
    c2da_mem[739696 + 1 * 20 + 12] = uint8(c2da_fresh308)
    c2da_mem[739696 + 1 * 20 + 13] = uint8(c2da_fresh308 >> 0x8)
    c2da_mem[739696 + 1 * 20 + 14] = uint8(c2da_fresh308 >> 0x10)
    c2da_mem[739696 + 1 * 20 + 15] = uint8(c2da_fresh308 >> 0x18)
    let c2da_fresh309 : float = uint_bits_to_float(uint(c2da_mem[maxs_3 + 1 * 4]) | uint(c2da_mem[maxs_3 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs_3 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs_3 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh310 : uint = float_bits_to_uint(c2da_fresh309)
    c2da_mem[739696 + 2 * 20 + 12] = uint8(c2da_fresh310)
    c2da_mem[739696 + 2 * 20 + 13] = uint8(c2da_fresh310 >> 0x8)
    c2da_mem[739696 + 2 * 20 + 14] = uint8(c2da_fresh310 >> 0x10)
    c2da_mem[739696 + 2 * 20 + 15] = uint8(c2da_fresh310 >> 0x18)
    let c2da_fresh311 : float = uint_bits_to_float(uint(c2da_mem[mins_3 + 1 * 4]) | uint(c2da_mem[mins_3 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_3 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_3 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh312 : uint = float_bits_to_uint(c2da_fresh311)
    c2da_mem[739696 + 3 * 20 + 12] = uint8(c2da_fresh312)
    c2da_mem[739696 + 3 * 20 + 13] = uint8(c2da_fresh312 >> 0x8)
    c2da_mem[739696 + 3 * 20 + 14] = uint8(c2da_fresh312 >> 0x10)
    c2da_mem[739696 + 3 * 20 + 15] = uint8(c2da_fresh312 >> 0x18)
    let c2da_fresh313 : float = uint_bits_to_float(uint(c2da_mem[maxs_3 + 2 * 4]) | uint(c2da_mem[maxs_3 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs_3 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs_3 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh314 : uint = float_bits_to_uint(c2da_fresh313)
    c2da_mem[739696 + 4 * 20 + 12] = uint8(c2da_fresh314)
    c2da_mem[739696 + 4 * 20 + 13] = uint8(c2da_fresh314 >> 0x8)
    c2da_mem[739696 + 4 * 20 + 14] = uint8(c2da_fresh314 >> 0x10)
    c2da_mem[739696 + 4 * 20 + 15] = uint8(c2da_fresh314 >> 0x18)
    let c2da_fresh315 : float = uint_bits_to_float(uint(c2da_mem[mins_3 + 2 * 4]) | uint(c2da_mem[mins_3 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_3 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_3 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh316 : uint = float_bits_to_uint(c2da_fresh315)
    c2da_mem[739696 + 5 * 20 + 12] = uint8(c2da_fresh316)
    c2da_mem[739696 + 5 * 20 + 13] = uint8(c2da_fresh316 >> 0x8)
    c2da_mem[739696 + 5 * 20 + 14] = uint8(c2da_fresh316 >> 0x10)
    c2da_mem[739696 + 5 * 20 + 15] = uint8(c2da_fresh316 >> 0x18)
    return 739824
}
[export, sideeffects]
def SV_MoveBounds(var start_1 : int; var mins_4 : int; var maxs_4 : int; var end_1 : int; var boxmins : int; var boxmaxs : int) {
    for (i_2 in range(0, 3)) {
        if (uint_bits_to_float(uint(c2da_mem[end_1 + i_2 * 4]) | uint(c2da_mem[end_1 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[end_1 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[end_1 + i_2 * 4 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[start_1 + i_2 * 4]) | uint(c2da_mem[start_1 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[start_1 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[start_1 + i_2 * 4 + 3]) << 0x18)) {
            let c2da_fresh317 : float = uint_bits_to_float(uint(c2da_mem[start_1 + i_2 * 4]) | uint(c2da_mem[start_1 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[start_1 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[start_1 + i_2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[mins_4 + i_2 * 4]) | uint(c2da_mem[mins_4 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_4 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_4 + i_2 * 4 + 3]) << 0x18) - 1.0
            let c2da_fresh318 : uint = float_bits_to_uint(c2da_fresh317)
            c2da_mem[boxmins + i_2 * 4] = uint8(c2da_fresh318)
            c2da_mem[boxmins + i_2 * 4 + 1] = uint8(c2da_fresh318 >> 0x8)
            c2da_mem[boxmins + i_2 * 4 + 2] = uint8(c2da_fresh318 >> 0x10)
            c2da_mem[boxmins + i_2 * 4 + 3] = uint8(c2da_fresh318 >> 0x18)
            let c2da_fresh319 : float = uint_bits_to_float(uint(c2da_mem[end_1 + i_2 * 4]) | uint(c2da_mem[end_1 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[end_1 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[end_1 + i_2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[maxs_4 + i_2 * 4]) | uint(c2da_mem[maxs_4 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs_4 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs_4 + i_2 * 4 + 3]) << 0x18) + 1.0
            let c2da_fresh320 : uint = float_bits_to_uint(c2da_fresh319)
            c2da_mem[boxmaxs + i_2 * 4] = uint8(c2da_fresh320)
            c2da_mem[boxmaxs + i_2 * 4 + 1] = uint8(c2da_fresh320 >> 0x8)
            c2da_mem[boxmaxs + i_2 * 4 + 2] = uint8(c2da_fresh320 >> 0x10)
            c2da_mem[boxmaxs + i_2 * 4 + 3] = uint8(c2da_fresh320 >> 0x18)
        } else {
            let c2da_fresh321 : float = uint_bits_to_float(uint(c2da_mem[end_1 + i_2 * 4]) | uint(c2da_mem[end_1 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[end_1 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[end_1 + i_2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[mins_4 + i_2 * 4]) | uint(c2da_mem[mins_4 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_4 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_4 + i_2 * 4 + 3]) << 0x18) - 1.0
            let c2da_fresh322 : uint = float_bits_to_uint(c2da_fresh321)
            c2da_mem[boxmins + i_2 * 4] = uint8(c2da_fresh322)
            c2da_mem[boxmins + i_2 * 4 + 1] = uint8(c2da_fresh322 >> 0x8)
            c2da_mem[boxmins + i_2 * 4 + 2] = uint8(c2da_fresh322 >> 0x10)
            c2da_mem[boxmins + i_2 * 4 + 3] = uint8(c2da_fresh322 >> 0x18)
            let c2da_fresh323 : float = uint_bits_to_float(uint(c2da_mem[start_1 + i_2 * 4]) | uint(c2da_mem[start_1 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[start_1 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[start_1 + i_2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[maxs_4 + i_2 * 4]) | uint(c2da_mem[maxs_4 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs_4 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs_4 + i_2 * 4 + 3]) << 0x18) + 1.0
            let c2da_fresh324 : uint = float_bits_to_uint(c2da_fresh323)
            c2da_mem[boxmaxs + i_2 * 4] = uint8(c2da_fresh324)
            c2da_mem[boxmaxs + i_2 * 4 + 1] = uint8(c2da_fresh324 >> 0x8)
            c2da_mem[boxmaxs + i_2 * 4 + 2] = uint8(c2da_fresh324 >> 0x10)
            c2da_mem[boxmaxs + i_2 * 4 + 3] = uint8(c2da_fresh324 >> 0x18)
        }
    }
    return
}
[sideeffects]
def private SV_CreateAreaNode_c2da_frame(var depth : int; var mins : int; var maxs : int; c2da_fp : int) : int {
    var anode : int
    var size : vec3_t
    anode = 737856 + sv_numareanodes * 56
    sv_numareanodes++
    ClearLink(anode + 24)
    ClearLink(anode + 40)
    if (depth == 4) {
        let c2da_fresh0 : int = -1
        let c2da_fresh1 : uint = uint(c2da_fresh0)
        c2da_mem[anode] = uint8(c2da_fresh1)
        c2da_mem[anode + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[anode + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[anode + 3] = uint8(c2da_fresh1 >> 0x18)
        let c2da_fresh2 : uint = 0u
        c2da_mem[anode + 8 + 1 * 8] = uint8(c2da_fresh2)
        c2da_mem[anode + 8 + 1 * 8 + 1] = uint8(c2da_fresh2 >> 0x8)
        c2da_mem[anode + 8 + 1 * 8 + 2] = uint8(c2da_fresh2 >> 0x10)
        c2da_mem[anode + 8 + 1 * 8 + 3] = uint8(c2da_fresh2 >> 0x18)
        c2da_mem[anode + 8 + 1 * 8 + 4] = 0u8
        c2da_mem[anode + 8 + 1 * 8 + 5] = 0u8
        c2da_mem[anode + 8 + 1 * 8 + 6] = 0u8
        c2da_mem[anode + 8 + 1 * 8 + 7] = 0u8
        let c2da_fresh3 : uint = 0u
        c2da_mem[anode + 8 + 0 * 8] = uint8(c2da_fresh3)
        c2da_mem[anode + 8 + 0 * 8 + 1] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[anode + 8 + 0 * 8 + 2] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[anode + 8 + 0 * 8 + 3] = uint8(c2da_fresh3 >> 0x18)
        c2da_mem[anode + 8 + 0 * 8 + 4] = 0u8
        c2da_mem[anode + 8 + 0 * 8 + 5] = 0u8
        c2da_mem[anode + 8 + 0 * 8 + 6] = 0u8
        c2da_mem[anode + 8 + 0 * 8 + 7] = 0u8
        return anode
    }
    size[0] = uint_bits_to_float(uint(c2da_mem[maxs + 0 * 4]) | uint(c2da_mem[maxs + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[mins + 0 * 4]) | uint(c2da_mem[mins + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[mins + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[mins + 0 * 4 + 3]) << 0x18)
    size[1] = uint_bits_to_float(uint(c2da_mem[maxs + 1 * 4]) | uint(c2da_mem[maxs + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[mins + 1 * 4]) | uint(c2da_mem[mins + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[mins + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[mins + 1 * 4 + 3]) << 0x18)
    size[2] = uint_bits_to_float(uint(c2da_mem[maxs + 2 * 4]) | uint(c2da_mem[maxs + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[mins + 2 * 4]) | uint(c2da_mem[mins + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[mins + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[mins + 2 * 4 + 3]) << 0x18)
    if (size[0] > size[1]) {
        let c2da_fresh4 : int = 0
        let c2da_fresh5 : uint = uint(c2da_fresh4)
        c2da_mem[anode] = uint8(c2da_fresh5)
        c2da_mem[anode + 1] = uint8(c2da_fresh5 >> 0x8)
        c2da_mem[anode + 2] = uint8(c2da_fresh5 >> 0x10)
        c2da_mem[anode + 3] = uint8(c2da_fresh5 >> 0x18)
    } else {
        let c2da_fresh6 : int = 1
        let c2da_fresh7 : uint = uint(c2da_fresh6)
        c2da_mem[anode] = uint8(c2da_fresh7)
        c2da_mem[anode + 1] = uint8(c2da_fresh7 >> 0x8)
        c2da_mem[anode + 2] = uint8(c2da_fresh7 >> 0x10)
        c2da_mem[anode + 3] = uint8(c2da_fresh7 >> 0x18)
    }
    let c2da_fresh8 : int = maxs + int(uint(c2da_mem[anode]) | uint(c2da_mem[anode + 1]) << 0x8 | uint(c2da_mem[anode + 2]) << 0x10 | uint(c2da_mem[anode + 3]) << 0x18) * 4
    let c2da_fresh9 : int = mins + int(uint(c2da_mem[anode]) | uint(c2da_mem[anode + 1]) << 0x8 | uint(c2da_mem[anode + 2]) << 0x10 | uint(c2da_mem[anode + 3]) << 0x18) * 4
    let c2da_fresh10 : float = float(0.5lf * double(uint_bits_to_float(uint(c2da_mem[c2da_fresh8]) | uint(c2da_mem[c2da_fresh8 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh8 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh8 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fresh9]) | uint(c2da_mem[c2da_fresh9 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh9 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh9 + 3]) << 0x18)))
    let c2da_fresh11 : uint = float_bits_to_uint(c2da_fresh10)
    c2da_mem[anode + 4] = uint8(c2da_fresh11)
    c2da_mem[anode + 5] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[anode + 6] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[anode + 7] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : float = uint_bits_to_float(uint(c2da_mem[mins + 0 * 4]) | uint(c2da_mem[mins + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[mins + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[mins + 0 * 4 + 3]) << 0x18)
    let c2da_fresh13 : uint = float_bits_to_uint(c2da_fresh12)
    c2da_mem[c2da_fp + 32 + 0 * 4] = uint8(c2da_fresh13)
    c2da_mem[c2da_fp + 32 + 0 * 4 + 1] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[c2da_fp + 32 + 0 * 4 + 2] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[c2da_fp + 32 + 0 * 4 + 3] = uint8(c2da_fresh13 >> 0x18)
    let c2da_fresh14 : float = uint_bits_to_float(uint(c2da_mem[mins + 1 * 4]) | uint(c2da_mem[mins + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[mins + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[mins + 1 * 4 + 3]) << 0x18)
    let c2da_fresh15 : uint = float_bits_to_uint(c2da_fresh14)
    c2da_mem[c2da_fp + 32 + 1 * 4] = uint8(c2da_fresh15)
    c2da_mem[c2da_fp + 32 + 1 * 4 + 1] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[c2da_fp + 32 + 1 * 4 + 2] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[c2da_fp + 32 + 1 * 4 + 3] = uint8(c2da_fresh15 >> 0x18)
    let c2da_fresh16 : float = uint_bits_to_float(uint(c2da_mem[mins + 2 * 4]) | uint(c2da_mem[mins + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[mins + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[mins + 2 * 4 + 3]) << 0x18)
    let c2da_fresh17 : uint = float_bits_to_uint(c2da_fresh16)
    c2da_mem[c2da_fp + 32 + 2 * 4] = uint8(c2da_fresh17)
    c2da_mem[c2da_fp + 32 + 2 * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[c2da_fp + 32 + 2 * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[c2da_fp + 32 + 2 * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
    let c2da_fresh18 : float = uint_bits_to_float(uint(c2da_mem[mins + 0 * 4]) | uint(c2da_mem[mins + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[mins + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[mins + 0 * 4 + 3]) << 0x18)
    let c2da_fresh19 : uint = float_bits_to_uint(c2da_fresh18)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh19)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh19 >> 0x18)
    let c2da_fresh20 : float = uint_bits_to_float(uint(c2da_mem[mins + 1 * 4]) | uint(c2da_mem[mins + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[mins + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[mins + 1 * 4 + 3]) << 0x18)
    let c2da_fresh21 : uint = float_bits_to_uint(c2da_fresh20)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh21)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh21 >> 0x18)
    let c2da_fresh22 : float = uint_bits_to_float(uint(c2da_mem[mins + 2 * 4]) | uint(c2da_mem[mins + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[mins + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[mins + 2 * 4 + 3]) << 0x18)
    let c2da_fresh23 : uint = float_bits_to_uint(c2da_fresh22)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh23)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh23 >> 0x18)
    let c2da_fresh24 : float = uint_bits_to_float(uint(c2da_mem[maxs + 0 * 4]) | uint(c2da_mem[maxs + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs + 0 * 4 + 3]) << 0x18)
    let c2da_fresh25 : uint = float_bits_to_uint(c2da_fresh24)
    c2da_mem[c2da_fp + 48 + 0 * 4] = uint8(c2da_fresh25)
    c2da_mem[c2da_fp + 48 + 0 * 4 + 1] = uint8(c2da_fresh25 >> 0x8)
    c2da_mem[c2da_fp + 48 + 0 * 4 + 2] = uint8(c2da_fresh25 >> 0x10)
    c2da_mem[c2da_fp + 48 + 0 * 4 + 3] = uint8(c2da_fresh25 >> 0x18)
    let c2da_fresh26 : float = uint_bits_to_float(uint(c2da_mem[maxs + 1 * 4]) | uint(c2da_mem[maxs + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs + 1 * 4 + 3]) << 0x18)
    let c2da_fresh27 : uint = float_bits_to_uint(c2da_fresh26)
    c2da_mem[c2da_fp + 48 + 1 * 4] = uint8(c2da_fresh27)
    c2da_mem[c2da_fp + 48 + 1 * 4 + 1] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[c2da_fp + 48 + 1 * 4 + 2] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[c2da_fp + 48 + 1 * 4 + 3] = uint8(c2da_fresh27 >> 0x18)
    let c2da_fresh28 : float = uint_bits_to_float(uint(c2da_mem[maxs + 2 * 4]) | uint(c2da_mem[maxs + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs + 2 * 4 + 3]) << 0x18)
    let c2da_fresh29 : uint = float_bits_to_uint(c2da_fresh28)
    c2da_mem[c2da_fp + 48 + 2 * 4] = uint8(c2da_fresh29)
    c2da_mem[c2da_fp + 48 + 2 * 4 + 1] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[c2da_fp + 48 + 2 * 4 + 2] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[c2da_fp + 48 + 2 * 4 + 3] = uint8(c2da_fresh29 >> 0x18)
    let c2da_fresh30 : float = uint_bits_to_float(uint(c2da_mem[maxs + 0 * 4]) | uint(c2da_mem[maxs + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs + 0 * 4 + 3]) << 0x18)
    let c2da_fresh31 : uint = float_bits_to_uint(c2da_fresh30)
    c2da_mem[c2da_fp + 16 + 0 * 4] = uint8(c2da_fresh31)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 1] = uint8(c2da_fresh31 >> 0x8)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 2] = uint8(c2da_fresh31 >> 0x10)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 3] = uint8(c2da_fresh31 >> 0x18)
    let c2da_fresh32 : float = uint_bits_to_float(uint(c2da_mem[maxs + 1 * 4]) | uint(c2da_mem[maxs + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs + 1 * 4 + 3]) << 0x18)
    let c2da_fresh33 : uint = float_bits_to_uint(c2da_fresh32)
    c2da_mem[c2da_fp + 16 + 1 * 4] = uint8(c2da_fresh33)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 1] = uint8(c2da_fresh33 >> 0x8)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 2] = uint8(c2da_fresh33 >> 0x10)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 3] = uint8(c2da_fresh33 >> 0x18)
    let c2da_fresh34 : float = uint_bits_to_float(uint(c2da_mem[maxs + 2 * 4]) | uint(c2da_mem[maxs + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs + 2 * 4 + 3]) << 0x18)
    let c2da_fresh35 : uint = float_bits_to_uint(c2da_fresh34)
    c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh35)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh35 >> 0x8)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh35 >> 0x10)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh35 >> 0x18)
    let c2da_fresh36 : int = c2da_fp + 48 + int(uint(c2da_mem[anode]) | uint(c2da_mem[anode + 1]) << 0x8 | uint(c2da_mem[anode + 2]) << 0x10 | uint(c2da_mem[anode + 3]) << 0x18) * 4
    let c2da_fresh37 : int = c2da_fp + int(uint(c2da_mem[anode]) | uint(c2da_mem[anode + 1]) << 0x8 | uint(c2da_mem[anode + 2]) << 0x10 | uint(c2da_mem[anode + 3]) << 0x18) * 4
    let c2da_fresh38 : float = uint_bits_to_float(uint(c2da_mem[anode + 4]) | uint(c2da_mem[anode + 5]) << 0x8 | uint(c2da_mem[anode + 6]) << 0x10 | uint(c2da_mem[anode + 7]) << 0x18)
    let c2da_fresh39 : uint = float_bits_to_uint(c2da_fresh38)
    c2da_mem[c2da_fresh37] = uint8(c2da_fresh39)
    c2da_mem[c2da_fresh37 + 1] = uint8(c2da_fresh39 >> 0x8)
    c2da_mem[c2da_fresh37 + 2] = uint8(c2da_fresh39 >> 0x10)
    c2da_mem[c2da_fresh37 + 3] = uint8(c2da_fresh39 >> 0x18)
    let c2da_fresh40 : uint = float_bits_to_uint(c2da_fresh38)
    c2da_mem[c2da_fresh36] = uint8(c2da_fresh40)
    c2da_mem[c2da_fresh36 + 1] = uint8(c2da_fresh40 >> 0x8)
    c2da_mem[c2da_fresh36 + 2] = uint8(c2da_fresh40 >> 0x10)
    c2da_mem[c2da_fresh36 + 3] = uint8(c2da_fresh40 >> 0x18)
    let c2da_fresh41 : int = SV_CreateAreaNode(depth + 1, c2da_fp, c2da_fp + 16)
    let c2da_fresh42 : uint = uint(c2da_fresh41)
    c2da_mem[anode + 8 + 0 * 8] = uint8(c2da_fresh42)
    c2da_mem[anode + 8 + 0 * 8 + 1] = uint8(c2da_fresh42 >> 0x8)
    c2da_mem[anode + 8 + 0 * 8 + 2] = uint8(c2da_fresh42 >> 0x10)
    c2da_mem[anode + 8 + 0 * 8 + 3] = uint8(c2da_fresh42 >> 0x18)
    c2da_mem[anode + 8 + 0 * 8 + 4] = 0u8
    c2da_mem[anode + 8 + 0 * 8 + 5] = 0u8
    c2da_mem[anode + 8 + 0 * 8 + 6] = 0u8
    c2da_mem[anode + 8 + 0 * 8 + 7] = 0u8
    let c2da_fresh43 : int = SV_CreateAreaNode(depth + 1, c2da_fp + 32, c2da_fp + 48)
    let c2da_fresh44 : uint = uint(c2da_fresh43)
    c2da_mem[anode + 8 + 1 * 8] = uint8(c2da_fresh44)
    c2da_mem[anode + 8 + 1 * 8 + 1] = uint8(c2da_fresh44 >> 0x8)
    c2da_mem[anode + 8 + 1 * 8 + 2] = uint8(c2da_fresh44 >> 0x10)
    c2da_mem[anode + 8 + 1 * 8 + 3] = uint8(c2da_fresh44 >> 0x18)
    c2da_mem[anode + 8 + 1 * 8 + 4] = 0u8
    c2da_mem[anode + 8 + 1 * 8 + 5] = 0u8
    c2da_mem[anode + 8 + 1 * 8 + 6] = 0u8
    c2da_mem[anode + 8 + 1 * 8 + 7] = 0u8
    return anode
}
[sideeffects]
def private SV_Move_c2da_frame(var start : int; var mins_0 : int; var maxs_0 : int; var end : int; var type_0 : int; var passedict : int; c2da_fp : int) : trace_t {
    c2da_lin_memset(c2da_fp, 0, 152ul)
    var c2da_fresh126 : trace_t = SV_ClipMoveToEntity(int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18), start, mins_0, maxs_0, end)
    let c2da_fresh127 : uint = c2da_fresh126.allsolid
    c2da_mem[c2da_fp + 80] = uint8(c2da_fresh127)
    c2da_mem[c2da_fp + 81] = uint8(c2da_fresh127 >> 0x8)
    c2da_mem[c2da_fp + 82] = uint8(c2da_fresh127 >> 0x10)
    c2da_mem[c2da_fp + 83] = uint8(c2da_fresh127 >> 0x18)
    let c2da_fresh128 : uint = c2da_fresh126.startsolid
    c2da_mem[c2da_fp + 84] = uint8(c2da_fresh128)
    c2da_mem[c2da_fp + 85] = uint8(c2da_fresh128 >> 0x8)
    c2da_mem[c2da_fp + 86] = uint8(c2da_fresh128 >> 0x10)
    c2da_mem[c2da_fp + 87] = uint8(c2da_fresh128 >> 0x18)
    let c2da_fresh129 : uint = c2da_fresh126.inopen
    c2da_mem[c2da_fp + 88] = uint8(c2da_fresh129)
    c2da_mem[c2da_fp + 89] = uint8(c2da_fresh129 >> 0x8)
    c2da_mem[c2da_fp + 90] = uint8(c2da_fresh129 >> 0x10)
    c2da_mem[c2da_fp + 91] = uint8(c2da_fresh129 >> 0x18)
    let c2da_fresh130 : uint = c2da_fresh126.inwater
    c2da_mem[c2da_fp + 92] = uint8(c2da_fresh130)
    c2da_mem[c2da_fp + 93] = uint8(c2da_fresh130 >> 0x8)
    c2da_mem[c2da_fp + 94] = uint8(c2da_fresh130 >> 0x10)
    c2da_mem[c2da_fp + 95] = uint8(c2da_fresh130 >> 0x18)
    let c2da_fresh131 : uint = float_bits_to_uint(c2da_fresh126.fraction)
    c2da_mem[c2da_fp + 96] = uint8(c2da_fresh131)
    c2da_mem[c2da_fp + 97] = uint8(c2da_fresh131 >> 0x8)
    c2da_mem[c2da_fp + 98] = uint8(c2da_fresh131 >> 0x10)
    c2da_mem[c2da_fp + 99] = uint8(c2da_fresh131 >> 0x18)
    let c2da_fresh132 : uint = float_bits_to_uint(c2da_fresh126.endpos[0])
    c2da_mem[c2da_fp + 100] = uint8(c2da_fresh132)
    c2da_mem[c2da_fp + 101] = uint8(c2da_fresh132 >> 0x8)
    c2da_mem[c2da_fp + 102] = uint8(c2da_fresh132 >> 0x10)
    c2da_mem[c2da_fp + 103] = uint8(c2da_fresh132 >> 0x18)
    let c2da_fresh133 : uint = float_bits_to_uint(c2da_fresh126.endpos[1])
    c2da_mem[c2da_fp + 104] = uint8(c2da_fresh133)
    c2da_mem[c2da_fp + 105] = uint8(c2da_fresh133 >> 0x8)
    c2da_mem[c2da_fp + 106] = uint8(c2da_fresh133 >> 0x10)
    c2da_mem[c2da_fp + 107] = uint8(c2da_fresh133 >> 0x18)
    let c2da_fresh134 : uint = float_bits_to_uint(c2da_fresh126.endpos[2])
    c2da_mem[c2da_fp + 108] = uint8(c2da_fresh134)
    c2da_mem[c2da_fp + 109] = uint8(c2da_fresh134 >> 0x8)
    c2da_mem[c2da_fp + 110] = uint8(c2da_fresh134 >> 0x10)
    c2da_mem[c2da_fp + 111] = uint8(c2da_fresh134 >> 0x18)
    let c2da_fresh135 : uint = float_bits_to_uint(c2da_fresh126.plane.normal[0])
    c2da_mem[c2da_fp + 112] = uint8(c2da_fresh135)
    c2da_mem[c2da_fp + 113] = uint8(c2da_fresh135 >> 0x8)
    c2da_mem[c2da_fp + 114] = uint8(c2da_fresh135 >> 0x10)
    c2da_mem[c2da_fp + 115] = uint8(c2da_fresh135 >> 0x18)
    let c2da_fresh136 : uint = float_bits_to_uint(c2da_fresh126.plane.normal[1])
    c2da_mem[c2da_fp + 116] = uint8(c2da_fresh136)
    c2da_mem[c2da_fp + 117] = uint8(c2da_fresh136 >> 0x8)
    c2da_mem[c2da_fp + 118] = uint8(c2da_fresh136 >> 0x10)
    c2da_mem[c2da_fp + 119] = uint8(c2da_fresh136 >> 0x18)
    let c2da_fresh137 : uint = float_bits_to_uint(c2da_fresh126.plane.normal[2])
    c2da_mem[c2da_fp + 120] = uint8(c2da_fresh137)
    c2da_mem[c2da_fp + 121] = uint8(c2da_fresh137 >> 0x8)
    c2da_mem[c2da_fp + 122] = uint8(c2da_fresh137 >> 0x10)
    c2da_mem[c2da_fp + 123] = uint8(c2da_fresh137 >> 0x18)
    let c2da_fresh138 : uint = float_bits_to_uint(c2da_fresh126.plane.dist)
    c2da_mem[c2da_fp + 124] = uint8(c2da_fresh138)
    c2da_mem[c2da_fp + 125] = uint8(c2da_fresh138 >> 0x8)
    c2da_mem[c2da_fp + 126] = uint8(c2da_fresh138 >> 0x10)
    c2da_mem[c2da_fp + 127] = uint8(c2da_fresh138 >> 0x18)
    let c2da_fresh139 : uint = uint(c2da_fresh126.ent)
    c2da_mem[c2da_fp + 128] = uint8(c2da_fresh139)
    c2da_mem[c2da_fp + 129] = uint8(c2da_fresh139 >> 0x8)
    c2da_mem[c2da_fp + 130] = uint8(c2da_fresh139 >> 0x10)
    c2da_mem[c2da_fp + 131] = uint8(c2da_fresh139 >> 0x18)
    c2da_mem[c2da_fp + 132] = 0u8
    c2da_mem[c2da_fp + 133] = 0u8
    c2da_mem[c2da_fp + 134] = 0u8
    c2da_mem[c2da_fp + 135] = 0u8
    let c2da_fresh140 : uint = uint(start)
    c2da_mem[c2da_fp + 64] = uint8(c2da_fresh140)
    c2da_mem[c2da_fp + 65] = uint8(c2da_fresh140 >> 0x8)
    c2da_mem[c2da_fp + 66] = uint8(c2da_fresh140 >> 0x10)
    c2da_mem[c2da_fp + 67] = uint8(c2da_fresh140 >> 0x18)
    c2da_mem[c2da_fp + 68] = 0u8
    c2da_mem[c2da_fp + 69] = 0u8
    c2da_mem[c2da_fp + 70] = 0u8
    c2da_mem[c2da_fp + 71] = 0u8
    let c2da_fresh141 : uint = uint(end)
    c2da_mem[c2da_fp + 72] = uint8(c2da_fresh141)
    c2da_mem[c2da_fp + 73] = uint8(c2da_fresh141 >> 0x8)
    c2da_mem[c2da_fp + 74] = uint8(c2da_fresh141 >> 0x10)
    c2da_mem[c2da_fp + 75] = uint8(c2da_fresh141 >> 0x18)
    c2da_mem[c2da_fp + 76] = 0u8
    c2da_mem[c2da_fp + 77] = 0u8
    c2da_mem[c2da_fp + 78] = 0u8
    c2da_mem[c2da_fp + 79] = 0u8
    let c2da_fresh142 : uint = uint(mins_0)
    c2da_mem[c2da_fp + 24] = uint8(c2da_fresh142)
    c2da_mem[c2da_fp + 25] = uint8(c2da_fresh142 >> 0x8)
    c2da_mem[c2da_fp + 26] = uint8(c2da_fresh142 >> 0x10)
    c2da_mem[c2da_fp + 27] = uint8(c2da_fresh142 >> 0x18)
    c2da_mem[c2da_fp + 28] = 0u8
    c2da_mem[c2da_fp + 29] = 0u8
    c2da_mem[c2da_fp + 30] = 0u8
    c2da_mem[c2da_fp + 31] = 0u8
    let c2da_fresh143 : uint = uint(maxs_0)
    c2da_mem[c2da_fp + 32] = uint8(c2da_fresh143)
    c2da_mem[c2da_fp + 33] = uint8(c2da_fresh143 >> 0x8)
    c2da_mem[c2da_fp + 34] = uint8(c2da_fresh143 >> 0x10)
    c2da_mem[c2da_fp + 35] = uint8(c2da_fresh143 >> 0x18)
    c2da_mem[c2da_fp + 36] = 0u8
    c2da_mem[c2da_fp + 37] = 0u8
    c2da_mem[c2da_fp + 38] = 0u8
    c2da_mem[c2da_fp + 39] = 0u8
    let c2da_fresh144 : uint = uint(type_0)
    c2da_mem[c2da_fp + 136] = uint8(c2da_fresh144)
    c2da_mem[c2da_fp + 137] = uint8(c2da_fresh144 >> 0x8)
    c2da_mem[c2da_fp + 138] = uint8(c2da_fresh144 >> 0x10)
    c2da_mem[c2da_fp + 139] = uint8(c2da_fresh144 >> 0x18)
    let c2da_fresh145 : uint = uint(passedict)
    c2da_mem[c2da_fp + 144] = uint8(c2da_fresh145)
    c2da_mem[c2da_fp + 145] = uint8(c2da_fresh145 >> 0x8)
    c2da_mem[c2da_fp + 146] = uint8(c2da_fresh145 >> 0x10)
    c2da_mem[c2da_fp + 147] = uint8(c2da_fresh145 >> 0x18)
    c2da_mem[c2da_fp + 148] = 0u8
    c2da_mem[c2da_fp + 149] = 0u8
    c2da_mem[c2da_fp + 150] = 0u8
    c2da_mem[c2da_fp + 151] = 0u8
    if (type_0 == 2) {
        for (i_0 in range(0, 3)) {
            let c2da_fresh146 : float = -15.0
            let c2da_fresh147 : uint = float_bits_to_uint(c2da_fresh146)
            c2da_mem[c2da_fp + 40 + i_0 * 4] = uint8(c2da_fresh147)
            c2da_mem[c2da_fp + 40 + i_0 * 4 + 1] = uint8(c2da_fresh147 >> 0x8)
            c2da_mem[c2da_fp + 40 + i_0 * 4 + 2] = uint8(c2da_fresh147 >> 0x10)
            c2da_mem[c2da_fp + 40 + i_0 * 4 + 3] = uint8(c2da_fresh147 >> 0x18)
            let c2da_fresh148 : float = 15.0
            let c2da_fresh149 : uint = float_bits_to_uint(c2da_fresh148)
            c2da_mem[c2da_fp + 52 + i_0 * 4] = uint8(c2da_fresh149)
            c2da_mem[c2da_fp + 52 + i_0 * 4 + 1] = uint8(c2da_fresh149 >> 0x8)
            c2da_mem[c2da_fp + 52 + i_0 * 4 + 2] = uint8(c2da_fresh149 >> 0x10)
            c2da_mem[c2da_fp + 52 + i_0 * 4 + 3] = uint8(c2da_fresh149 >> 0x18)
        }
    } else {
        let c2da_fresh150 : float = uint_bits_to_float(uint(c2da_mem[mins_0 + 0 * 4]) | uint(c2da_mem[mins_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_0 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh151 : uint = float_bits_to_uint(c2da_fresh150)
        c2da_mem[c2da_fp + 40 + 0 * 4] = uint8(c2da_fresh151)
        c2da_mem[c2da_fp + 40 + 0 * 4 + 1] = uint8(c2da_fresh151 >> 0x8)
        c2da_mem[c2da_fp + 40 + 0 * 4 + 2] = uint8(c2da_fresh151 >> 0x10)
        c2da_mem[c2da_fp + 40 + 0 * 4 + 3] = uint8(c2da_fresh151 >> 0x18)
        let c2da_fresh152 : float = uint_bits_to_float(uint(c2da_mem[mins_0 + 1 * 4]) | uint(c2da_mem[mins_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_0 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh153 : uint = float_bits_to_uint(c2da_fresh152)
        c2da_mem[c2da_fp + 40 + 1 * 4] = uint8(c2da_fresh153)
        c2da_mem[c2da_fp + 40 + 1 * 4 + 1] = uint8(c2da_fresh153 >> 0x8)
        c2da_mem[c2da_fp + 40 + 1 * 4 + 2] = uint8(c2da_fresh153 >> 0x10)
        c2da_mem[c2da_fp + 40 + 1 * 4 + 3] = uint8(c2da_fresh153 >> 0x18)
        let c2da_fresh154 : float = uint_bits_to_float(uint(c2da_mem[mins_0 + 2 * 4]) | uint(c2da_mem[mins_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_0 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh155 : uint = float_bits_to_uint(c2da_fresh154)
        c2da_mem[c2da_fp + 40 + 2 * 4] = uint8(c2da_fresh155)
        c2da_mem[c2da_fp + 40 + 2 * 4 + 1] = uint8(c2da_fresh155 >> 0x8)
        c2da_mem[c2da_fp + 40 + 2 * 4 + 2] = uint8(c2da_fresh155 >> 0x10)
        c2da_mem[c2da_fp + 40 + 2 * 4 + 3] = uint8(c2da_fresh155 >> 0x18)
        let c2da_fresh156 : float = uint_bits_to_float(uint(c2da_mem[maxs_0 + 0 * 4]) | uint(c2da_mem[maxs_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs_0 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh157 : uint = float_bits_to_uint(c2da_fresh156)
        c2da_mem[c2da_fp + 52 + 0 * 4] = uint8(c2da_fresh157)
        c2da_mem[c2da_fp + 52 + 0 * 4 + 1] = uint8(c2da_fresh157 >> 0x8)
        c2da_mem[c2da_fp + 52 + 0 * 4 + 2] = uint8(c2da_fresh157 >> 0x10)
        c2da_mem[c2da_fp + 52 + 0 * 4 + 3] = uint8(c2da_fresh157 >> 0x18)
        let c2da_fresh158 : float = uint_bits_to_float(uint(c2da_mem[maxs_0 + 1 * 4]) | uint(c2da_mem[maxs_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs_0 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh159 : uint = float_bits_to_uint(c2da_fresh158)
        c2da_mem[c2da_fp + 52 + 1 * 4] = uint8(c2da_fresh159)
        c2da_mem[c2da_fp + 52 + 1 * 4 + 1] = uint8(c2da_fresh159 >> 0x8)
        c2da_mem[c2da_fp + 52 + 1 * 4 + 2] = uint8(c2da_fresh159 >> 0x10)
        c2da_mem[c2da_fp + 52 + 1 * 4 + 3] = uint8(c2da_fresh159 >> 0x18)
        let c2da_fresh160 : float = uint_bits_to_float(uint(c2da_mem[maxs_0 + 2 * 4]) | uint(c2da_mem[maxs_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs_0 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh161 : uint = float_bits_to_uint(c2da_fresh160)
        c2da_mem[c2da_fp + 52 + 2 * 4] = uint8(c2da_fresh161)
        c2da_mem[c2da_fp + 52 + 2 * 4 + 1] = uint8(c2da_fresh161 >> 0x8)
        c2da_mem[c2da_fp + 52 + 2 * 4 + 2] = uint8(c2da_fresh161 >> 0x10)
        c2da_mem[c2da_fp + 52 + 2 * 4 + 3] = uint8(c2da_fresh161 >> 0x18)
    }
    SV_MoveBounds(start, c2da_fp + 40, c2da_fp + 52, end, c2da_fp, c2da_fp + 12)
    SV_ClipToLinks(737856, c2da_fp)
    var c2da_fresh162 : trace_t
    c2da_fresh162.allsolid = uint(c2da_mem[c2da_fp + 80]) | uint(c2da_mem[c2da_fp + 81]) << 0x8 | uint(c2da_mem[c2da_fp + 82]) << 0x10 | uint(c2da_mem[c2da_fp + 83]) << 0x18
    c2da_fresh162.startsolid = uint(c2da_mem[c2da_fp + 84]) | uint(c2da_mem[c2da_fp + 85]) << 0x8 | uint(c2da_mem[c2da_fp + 86]) << 0x10 | uint(c2da_mem[c2da_fp + 87]) << 0x18
    c2da_fresh162.inopen = uint(c2da_mem[c2da_fp + 88]) | uint(c2da_mem[c2da_fp + 89]) << 0x8 | uint(c2da_mem[c2da_fp + 90]) << 0x10 | uint(c2da_mem[c2da_fp + 91]) << 0x18
    c2da_fresh162.inwater = uint(c2da_mem[c2da_fp + 92]) | uint(c2da_mem[c2da_fp + 93]) << 0x8 | uint(c2da_mem[c2da_fp + 94]) << 0x10 | uint(c2da_mem[c2da_fp + 95]) << 0x18
    c2da_fresh162.fraction = uint_bits_to_float(uint(c2da_mem[c2da_fp + 96]) | uint(c2da_mem[c2da_fp + 97]) << 0x8 | uint(c2da_mem[c2da_fp + 98]) << 0x10 | uint(c2da_mem[c2da_fp + 99]) << 0x18)
    c2da_fresh162.endpos[0] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 100]) | uint(c2da_mem[c2da_fp + 101]) << 0x8 | uint(c2da_mem[c2da_fp + 102]) << 0x10 | uint(c2da_mem[c2da_fp + 103]) << 0x18)
    c2da_fresh162.endpos[1] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 104]) | uint(c2da_mem[c2da_fp + 105]) << 0x8 | uint(c2da_mem[c2da_fp + 106]) << 0x10 | uint(c2da_mem[c2da_fp + 107]) << 0x18)
    c2da_fresh162.endpos[2] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 108]) | uint(c2da_mem[c2da_fp + 109]) << 0x8 | uint(c2da_mem[c2da_fp + 110]) << 0x10 | uint(c2da_mem[c2da_fp + 111]) << 0x18)
    c2da_fresh162.plane.normal[0] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 112]) | uint(c2da_mem[c2da_fp + 113]) << 0x8 | uint(c2da_mem[c2da_fp + 114]) << 0x10 | uint(c2da_mem[c2da_fp + 115]) << 0x18)
    c2da_fresh162.plane.normal[1] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 116]) | uint(c2da_mem[c2da_fp + 117]) << 0x8 | uint(c2da_mem[c2da_fp + 118]) << 0x10 | uint(c2da_mem[c2da_fp + 119]) << 0x18)
    c2da_fresh162.plane.normal[2] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 120]) | uint(c2da_mem[c2da_fp + 121]) << 0x8 | uint(c2da_mem[c2da_fp + 122]) << 0x10 | uint(c2da_mem[c2da_fp + 123]) << 0x18)
    c2da_fresh162.plane.dist = uint_bits_to_float(uint(c2da_mem[c2da_fp + 124]) | uint(c2da_mem[c2da_fp + 125]) << 0x8 | uint(c2da_mem[c2da_fp + 126]) << 0x10 | uint(c2da_mem[c2da_fp + 127]) << 0x18)
    c2da_fresh162.ent = int(uint(c2da_mem[c2da_fp + 128]) | uint(c2da_mem[c2da_fp + 129]) << 0x8 | uint(c2da_mem[c2da_fp + 130]) << 0x10 | uint(c2da_mem[c2da_fp + 131]) << 0x18)
    return c2da_fresh162
}
[sideeffects]
def private SV_ClipMoveToEntity_c2da_frame(var ent_4 : int; var start_0 : int; var mins_1 : int; var maxs_1 : int; var end_0 : int; c2da_fp : int) : trace_t {
    var hull_0 : int
    c2da_lin_memset(c2da_fp, 0, 56ul)
    let c2da_fresh198 : float = 1.0
    let c2da_fresh199 : uint = float_bits_to_uint(c2da_fresh198)
    c2da_mem[c2da_fp + 16] = uint8(c2da_fresh199)
    c2da_mem[c2da_fp + 17] = uint8(c2da_fresh199 >> 0x8)
    c2da_mem[c2da_fp + 18] = uint8(c2da_fresh199 >> 0x10)
    c2da_mem[c2da_fp + 19] = uint8(c2da_fresh199 >> 0x18)
    let c2da_fresh200 : uint = 1u
    let c2da_fresh201 : uint = c2da_fresh200
    c2da_mem[c2da_fp] = uint8(c2da_fresh201)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh201 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh201 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh201 >> 0x18)
    let c2da_fresh202 : float = uint_bits_to_float(uint(c2da_mem[end_0 + 0 * 4]) | uint(c2da_mem[end_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[end_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[end_0 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh203 : uint = float_bits_to_uint(c2da_fresh202)
    c2da_mem[c2da_fp + 20 + 0 * 4] = uint8(c2da_fresh203)
    c2da_mem[c2da_fp + 20 + 0 * 4 + 1] = uint8(c2da_fresh203 >> 0x8)
    c2da_mem[c2da_fp + 20 + 0 * 4 + 2] = uint8(c2da_fresh203 >> 0x10)
    c2da_mem[c2da_fp + 20 + 0 * 4 + 3] = uint8(c2da_fresh203 >> 0x18)
    let c2da_fresh204 : float = uint_bits_to_float(uint(c2da_mem[end_0 + 1 * 4]) | uint(c2da_mem[end_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[end_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[end_0 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh205 : uint = float_bits_to_uint(c2da_fresh204)
    c2da_mem[c2da_fp + 20 + 1 * 4] = uint8(c2da_fresh205)
    c2da_mem[c2da_fp + 20 + 1 * 4 + 1] = uint8(c2da_fresh205 >> 0x8)
    c2da_mem[c2da_fp + 20 + 1 * 4 + 2] = uint8(c2da_fresh205 >> 0x10)
    c2da_mem[c2da_fp + 20 + 1 * 4 + 3] = uint8(c2da_fresh205 >> 0x18)
    let c2da_fresh206 : float = uint_bits_to_float(uint(c2da_mem[end_0 + 2 * 4]) | uint(c2da_mem[end_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[end_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[end_0 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh207 : uint = float_bits_to_uint(c2da_fresh206)
    c2da_mem[c2da_fp + 20 + 2 * 4] = uint8(c2da_fresh207)
    c2da_mem[c2da_fp + 20 + 2 * 4 + 1] = uint8(c2da_fresh207 >> 0x8)
    c2da_mem[c2da_fp + 20 + 2 * 4 + 2] = uint8(c2da_fresh207 >> 0x10)
    c2da_mem[c2da_fp + 20 + 2 * 4 + 3] = uint8(c2da_fresh207 >> 0x18)
    hull_0 = SV_HullForEntity(ent_4, mins_1, maxs_1, c2da_fp + 64)
    let c2da_fresh208 : float = uint_bits_to_float(uint(c2da_mem[start_0 + 0 * 4]) | uint(c2da_mem[start_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[start_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[start_0 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 0 * 4]) | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh209 : uint = float_bits_to_uint(c2da_fresh208)
    c2da_mem[c2da_fp + 80 + 0 * 4] = uint8(c2da_fresh209)
    c2da_mem[c2da_fp + 80 + 0 * 4 + 1] = uint8(c2da_fresh209 >> 0x8)
    c2da_mem[c2da_fp + 80 + 0 * 4 + 2] = uint8(c2da_fresh209 >> 0x10)
    c2da_mem[c2da_fp + 80 + 0 * 4 + 3] = uint8(c2da_fresh209 >> 0x18)
    let c2da_fresh210 : float = uint_bits_to_float(uint(c2da_mem[start_0 + 1 * 4]) | uint(c2da_mem[start_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[start_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[start_0 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 1 * 4]) | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh211 : uint = float_bits_to_uint(c2da_fresh210)
    c2da_mem[c2da_fp + 80 + 1 * 4] = uint8(c2da_fresh211)
    c2da_mem[c2da_fp + 80 + 1 * 4 + 1] = uint8(c2da_fresh211 >> 0x8)
    c2da_mem[c2da_fp + 80 + 1 * 4 + 2] = uint8(c2da_fresh211 >> 0x10)
    c2da_mem[c2da_fp + 80 + 1 * 4 + 3] = uint8(c2da_fresh211 >> 0x18)
    let c2da_fresh212 : float = uint_bits_to_float(uint(c2da_mem[start_0 + 2 * 4]) | uint(c2da_mem[start_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[start_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[start_0 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 2 * 4]) | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh213 : uint = float_bits_to_uint(c2da_fresh212)
    c2da_mem[c2da_fp + 80 + 2 * 4] = uint8(c2da_fresh213)
    c2da_mem[c2da_fp + 80 + 2 * 4 + 1] = uint8(c2da_fresh213 >> 0x8)
    c2da_mem[c2da_fp + 80 + 2 * 4 + 2] = uint8(c2da_fresh213 >> 0x10)
    c2da_mem[c2da_fp + 80 + 2 * 4 + 3] = uint8(c2da_fresh213 >> 0x18)
    let c2da_fresh214 : float = uint_bits_to_float(uint(c2da_mem[end_0 + 0 * 4]) | uint(c2da_mem[end_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[end_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[end_0 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 0 * 4]) | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh215 : uint = float_bits_to_uint(c2da_fresh214)
    c2da_mem[c2da_fp + 96 + 0 * 4] = uint8(c2da_fresh215)
    c2da_mem[c2da_fp + 96 + 0 * 4 + 1] = uint8(c2da_fresh215 >> 0x8)
    c2da_mem[c2da_fp + 96 + 0 * 4 + 2] = uint8(c2da_fresh215 >> 0x10)
    c2da_mem[c2da_fp + 96 + 0 * 4 + 3] = uint8(c2da_fresh215 >> 0x18)
    let c2da_fresh216 : float = uint_bits_to_float(uint(c2da_mem[end_0 + 1 * 4]) | uint(c2da_mem[end_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[end_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[end_0 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 1 * 4]) | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh217 : uint = float_bits_to_uint(c2da_fresh216)
    c2da_mem[c2da_fp + 96 + 1 * 4] = uint8(c2da_fresh217)
    c2da_mem[c2da_fp + 96 + 1 * 4 + 1] = uint8(c2da_fresh217 >> 0x8)
    c2da_mem[c2da_fp + 96 + 1 * 4 + 2] = uint8(c2da_fresh217 >> 0x10)
    c2da_mem[c2da_fp + 96 + 1 * 4 + 3] = uint8(c2da_fresh217 >> 0x18)
    let c2da_fresh218 : float = uint_bits_to_float(uint(c2da_mem[end_0 + 2 * 4]) | uint(c2da_mem[end_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[end_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[end_0 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 2 * 4]) | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh219 : uint = float_bits_to_uint(c2da_fresh218)
    c2da_mem[c2da_fp + 96 + 2 * 4] = uint8(c2da_fresh219)
    c2da_mem[c2da_fp + 96 + 2 * 4 + 1] = uint8(c2da_fresh219 >> 0x8)
    c2da_mem[c2da_fp + 96 + 2 * 4 + 2] = uint8(c2da_fresh219 >> 0x10)
    c2da_mem[c2da_fp + 96 + 2 * 4 + 3] = uint8(c2da_fresh219 >> 0x18)
    SV_RecursiveHullCheck(hull_0, int(uint(c2da_mem[hull_0 + 16]) | uint(c2da_mem[hull_0 + 17]) << 0x8 | uint(c2da_mem[hull_0 + 18]) << 0x10 | uint(c2da_mem[hull_0 + 19]) << 0x18), 0.0, 1.0, c2da_fp + 80, c2da_fp + 96, c2da_fp)
    if (uint_bits_to_float(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18) != 1.0) {
        let c2da_fresh220 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 20 + 0 * 4]) | uint(c2da_mem[c2da_fp + 20 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 20 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 20 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 0 * 4]) | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh221 : uint = float_bits_to_uint(c2da_fresh220)
        c2da_mem[c2da_fp + 20 + 0 * 4] = uint8(c2da_fresh221)
        c2da_mem[c2da_fp + 20 + 0 * 4 + 1] = uint8(c2da_fresh221 >> 0x8)
        c2da_mem[c2da_fp + 20 + 0 * 4 + 2] = uint8(c2da_fresh221 >> 0x10)
        c2da_mem[c2da_fp + 20 + 0 * 4 + 3] = uint8(c2da_fresh221 >> 0x18)
        let c2da_fresh222 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 20 + 1 * 4]) | uint(c2da_mem[c2da_fp + 20 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 20 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 20 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 1 * 4]) | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh223 : uint = float_bits_to_uint(c2da_fresh222)
        c2da_mem[c2da_fp + 20 + 1 * 4] = uint8(c2da_fresh223)
        c2da_mem[c2da_fp + 20 + 1 * 4 + 1] = uint8(c2da_fresh223 >> 0x8)
        c2da_mem[c2da_fp + 20 + 1 * 4 + 2] = uint8(c2da_fresh223 >> 0x10)
        c2da_mem[c2da_fp + 20 + 1 * 4 + 3] = uint8(c2da_fresh223 >> 0x18)
        let c2da_fresh224 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 20 + 2 * 4]) | uint(c2da_mem[c2da_fp + 20 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 20 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 20 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 64 + 2 * 4]) | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 64 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh225 : uint = float_bits_to_uint(c2da_fresh224)
        c2da_mem[c2da_fp + 20 + 2 * 4] = uint8(c2da_fresh225)
        c2da_mem[c2da_fp + 20 + 2 * 4 + 1] = uint8(c2da_fresh225 >> 0x8)
        c2da_mem[c2da_fp + 20 + 2 * 4 + 2] = uint8(c2da_fresh225 >> 0x10)
        c2da_mem[c2da_fp + 20 + 2 * 4 + 3] = uint8(c2da_fresh225 >> 0x18)
    }
    if (uint_bits_to_float(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18) < 1.0 || (uint(c2da_mem[c2da_fp + 4]) | uint(c2da_mem[c2da_fp + 5]) << 0x8 | uint(c2da_mem[c2da_fp + 6]) << 0x10 | uint(c2da_mem[c2da_fp + 7]) << 0x18) != 0x0) {
        let c2da_fresh226 : uint = uint(ent_4)
        c2da_mem[c2da_fp + 48] = uint8(c2da_fresh226)
        c2da_mem[c2da_fp + 49] = uint8(c2da_fresh226 >> 0x8)
        c2da_mem[c2da_fp + 50] = uint8(c2da_fresh226 >> 0x10)
        c2da_mem[c2da_fp + 51] = uint8(c2da_fresh226 >> 0x18)
        c2da_mem[c2da_fp + 52] = 0u8
        c2da_mem[c2da_fp + 53] = 0u8
        c2da_mem[c2da_fp + 54] = 0u8
        c2da_mem[c2da_fp + 55] = 0u8
    }
    var c2da_fresh227 : trace_t
    c2da_fresh227.allsolid = uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18
    c2da_fresh227.startsolid = uint(c2da_mem[c2da_fp + 4]) | uint(c2da_mem[c2da_fp + 5]) << 0x8 | uint(c2da_mem[c2da_fp + 6]) << 0x10 | uint(c2da_mem[c2da_fp + 7]) << 0x18
    c2da_fresh227.inopen = uint(c2da_mem[c2da_fp + 8]) | uint(c2da_mem[c2da_fp + 9]) << 0x8 | uint(c2da_mem[c2da_fp + 10]) << 0x10 | uint(c2da_mem[c2da_fp + 11]) << 0x18
    c2da_fresh227.inwater = uint(c2da_mem[c2da_fp + 12]) | uint(c2da_mem[c2da_fp + 13]) << 0x8 | uint(c2da_mem[c2da_fp + 14]) << 0x10 | uint(c2da_mem[c2da_fp + 15]) << 0x18
    c2da_fresh227.fraction = uint_bits_to_float(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18)
    c2da_fresh227.endpos[0] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 20]) | uint(c2da_mem[c2da_fp + 21]) << 0x8 | uint(c2da_mem[c2da_fp + 22]) << 0x10 | uint(c2da_mem[c2da_fp + 23]) << 0x18)
    c2da_fresh227.endpos[1] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 24]) | uint(c2da_mem[c2da_fp + 25]) << 0x8 | uint(c2da_mem[c2da_fp + 26]) << 0x10 | uint(c2da_mem[c2da_fp + 27]) << 0x18)
    c2da_fresh227.endpos[2] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 28]) | uint(c2da_mem[c2da_fp + 29]) << 0x8 | uint(c2da_mem[c2da_fp + 30]) << 0x10 | uint(c2da_mem[c2da_fp + 31]) << 0x18)
    c2da_fresh227.plane.normal[0] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 32]) | uint(c2da_mem[c2da_fp + 33]) << 0x8 | uint(c2da_mem[c2da_fp + 34]) << 0x10 | uint(c2da_mem[c2da_fp + 35]) << 0x18)
    c2da_fresh227.plane.normal[1] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 36]) | uint(c2da_mem[c2da_fp + 37]) << 0x8 | uint(c2da_mem[c2da_fp + 38]) << 0x10 | uint(c2da_mem[c2da_fp + 39]) << 0x18)
    c2da_fresh227.plane.normal[2] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 40]) | uint(c2da_mem[c2da_fp + 41]) << 0x8 | uint(c2da_mem[c2da_fp + 42]) << 0x10 | uint(c2da_mem[c2da_fp + 43]) << 0x18)
    c2da_fresh227.plane.dist = uint_bits_to_float(uint(c2da_mem[c2da_fp + 44]) | uint(c2da_mem[c2da_fp + 45]) << 0x8 | uint(c2da_mem[c2da_fp + 46]) << 0x10 | uint(c2da_mem[c2da_fp + 47]) << 0x18)
    c2da_fresh227.ent = int(uint(c2da_mem[c2da_fp + 48]) | uint(c2da_mem[c2da_fp + 49]) << 0x8 | uint(c2da_mem[c2da_fp + 50]) << 0x10 | uint(c2da_mem[c2da_fp + 51]) << 0x18)
    return c2da_fresh227
}
[sideeffects]
def private SV_RecursiveHullCheck_c2da_frame(var hull_1 : int; var num_0 : int; var p1f : float; var p2f : float; var p1 : int; var p2 : int; var trace_1 : int; c2da_fp : int) : uint {
    var node_4 : int
    var plane_0 : int
    var t1 : float
    var t2 : float
    var frac : float
    var i_1 : int
    var side_0 : int
    var midf : float
    if (num_0 < 0) {
        if (num_0 != -2) {
            let c2da_fresh228 : uint = 0u
            let c2da_fresh229 : uint = c2da_fresh228
            c2da_mem[trace_1] = uint8(c2da_fresh229)
            c2da_mem[trace_1 + 1] = uint8(c2da_fresh229 >> 0x8)
            c2da_mem[trace_1 + 2] = uint8(c2da_fresh229 >> 0x10)
            c2da_mem[trace_1 + 3] = uint8(c2da_fresh229 >> 0x18)
            if (num_0 == -1) {
                let c2da_fresh230 : uint = 1u
                let c2da_fresh231 : uint = c2da_fresh230
                c2da_mem[trace_1 + 8] = uint8(c2da_fresh231)
                c2da_mem[trace_1 + 9] = uint8(c2da_fresh231 >> 0x8)
                c2da_mem[trace_1 + 10] = uint8(c2da_fresh231 >> 0x10)
                c2da_mem[trace_1 + 11] = uint8(c2da_fresh231 >> 0x18)
            } else {
                let c2da_fresh232 : uint = 1u
                let c2da_fresh233 : uint = c2da_fresh232
                c2da_mem[trace_1 + 12] = uint8(c2da_fresh233)
                c2da_mem[trace_1 + 13] = uint8(c2da_fresh233 >> 0x8)
                c2da_mem[trace_1 + 14] = uint8(c2da_fresh233 >> 0x10)
                c2da_mem[trace_1 + 15] = uint8(c2da_fresh233 >> 0x18)
            }
        } else {
            let c2da_fresh234 : uint = 1u
            let c2da_fresh235 : uint = c2da_fresh234
            c2da_mem[trace_1 + 4] = uint8(c2da_fresh235)
            c2da_mem[trace_1 + 5] = uint8(c2da_fresh235 >> 0x8)
            c2da_mem[trace_1 + 6] = uint8(c2da_fresh235 >> 0x10)
            c2da_mem[trace_1 + 7] = uint8(c2da_fresh235 >> 0x18)
        }
        return 1u
    }
    if (num_0 < int(uint(c2da_mem[hull_1 + 16]) | uint(c2da_mem[hull_1 + 17]) << 0x8 | uint(c2da_mem[hull_1 + 18]) << 0x10 | uint(c2da_mem[hull_1 + 19]) << 0x18) || num_0 > int(uint(c2da_mem[hull_1 + 20]) | uint(c2da_mem[hull_1 + 21]) << 0x8 | uint(c2da_mem[hull_1 + 22]) << 0x10 | uint(c2da_mem[hull_1 + 23]) << 0x18)) {
        Sys_Error(739935, [])
    }
    node_4 = int(uint(c2da_mem[hull_1]) | uint(c2da_mem[hull_1 + 1]) << 0x8 | uint(c2da_mem[hull_1 + 2]) << 0x10 | uint(c2da_mem[hull_1 + 3]) << 0x18) + num_0 * 8
    plane_0 = int(uint(c2da_mem[hull_1 + 8]) | uint(c2da_mem[hull_1 + 9]) << 0x8 | uint(c2da_mem[hull_1 + 10]) << 0x10 | uint(c2da_mem[hull_1 + 11]) << 0x18) + int(uint(c2da_mem[node_4]) | uint(c2da_mem[node_4 + 1]) << 0x8 | uint(c2da_mem[node_4 + 2]) << 0x10 | uint(c2da_mem[node_4 + 3]) << 0x18) * 20
    if (int(c2da_mem[plane_0 + 16]) < 3) {
        let c2da_fresh236 : int = p1 + int(c2da_mem[plane_0 + 16]) * 4
        t1 = uint_bits_to_float(uint(c2da_mem[c2da_fresh236]) | uint(c2da_mem[c2da_fresh236 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh236 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh236 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane_0 + 12]) | uint(c2da_mem[plane_0 + 13]) << 0x8 | uint(c2da_mem[plane_0 + 14]) << 0x10 | uint(c2da_mem[plane_0 + 15]) << 0x18)
        let c2da_fresh237 : int = p2 + int(c2da_mem[plane_0 + 16]) * 4
        t2 = uint_bits_to_float(uint(c2da_mem[c2da_fresh237]) | uint(c2da_mem[c2da_fresh237 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh237 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh237 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane_0 + 12]) | uint(c2da_mem[plane_0 + 13]) << 0x8 | uint(c2da_mem[plane_0 + 14]) << 0x10 | uint(c2da_mem[plane_0 + 15]) << 0x18)
    } else {
        t1 = uint_bits_to_float(uint(c2da_mem[plane_0 + 0 * 4]) | uint(c2da_mem[plane_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plane_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plane_0 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[p1 + 0 * 4]) | uint(c2da_mem[p1 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p1 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p1 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[plane_0 + 1 * 4]) | uint(c2da_mem[plane_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plane_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plane_0 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[p1 + 1 * 4]) | uint(c2da_mem[p1 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p1 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p1 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[plane_0 + 2 * 4]) | uint(c2da_mem[plane_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plane_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plane_0 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[p1 + 2 * 4]) | uint(c2da_mem[p1 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p1 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p1 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane_0 + 12]) | uint(c2da_mem[plane_0 + 13]) << 0x8 | uint(c2da_mem[plane_0 + 14]) << 0x10 | uint(c2da_mem[plane_0 + 15]) << 0x18)
        t2 = uint_bits_to_float(uint(c2da_mem[plane_0 + 0 * 4]) | uint(c2da_mem[plane_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plane_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plane_0 + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[p2 + 0 * 4]) | uint(c2da_mem[p2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p2 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[plane_0 + 1 * 4]) | uint(c2da_mem[plane_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plane_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plane_0 + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[p2 + 1 * 4]) | uint(c2da_mem[p2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p2 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[plane_0 + 2 * 4]) | uint(c2da_mem[plane_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plane_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plane_0 + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[p2 + 2 * 4]) | uint(c2da_mem[p2 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p2 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p2 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane_0 + 12]) | uint(c2da_mem[plane_0 + 13]) << 0x8 | uint(c2da_mem[plane_0 + 14]) << 0x10 | uint(c2da_mem[plane_0 + 15]) << 0x18)
    }
    if (t1 >= 0.0 && t2 >= 0.0) {
        return SV_RecursiveHullCheck(hull_1, int(int16(uint(c2da_mem[node_4 + 4 + 0 * 2]) | uint(c2da_mem[node_4 + 4 + 0 * 2 + 1]) << 0x8)), p1f, p2f, p1, p2, trace_1)
    }
    if (t1 < 0.0 && t2 < 0.0) {
        return SV_RecursiveHullCheck(hull_1, int(int16(uint(c2da_mem[node_4 + 4 + 1 * 2]) | uint(c2da_mem[node_4 + 4 + 1 * 2 + 1]) << 0x8)), p1f, p2f, p1, p2, trace_1)
    }
    if (t1 < 0.0) {
        frac = float((double(t1) + 0.03125lf) / double(t1 - t2))
    } else {
        frac = float((double(t1) - 0.03125lf) / double(t1 - t2))
    }
    if (frac < 0.0) {
        frac = 0.0
    }
    if (frac > 1.0) {
        frac = 1.0
    }
    midf = p1f + (p2f - p1f) * frac
    i_1 = 0
    while (i_1 < 3) {
        let c2da_fresh238 : float = uint_bits_to_float(uint(c2da_mem[p1 + i_1 * 4]) | uint(c2da_mem[p1 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[p1 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[p1 + i_1 * 4 + 3]) << 0x18) + frac * (uint_bits_to_float(uint(c2da_mem[p2 + i_1 * 4]) | uint(c2da_mem[p2 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[p2 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[p2 + i_1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[p1 + i_1 * 4]) | uint(c2da_mem[p1 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[p1 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[p1 + i_1 * 4 + 3]) << 0x18))
        let c2da_fresh239 : uint = float_bits_to_uint(c2da_fresh238)
        c2da_mem[c2da_fp + i_1 * 4] = uint8(c2da_fresh239)
        c2da_mem[c2da_fp + i_1 * 4 + 1] = uint8(c2da_fresh239 >> 0x8)
        c2da_mem[c2da_fp + i_1 * 4 + 2] = uint8(c2da_fresh239 >> 0x10)
        c2da_mem[c2da_fp + i_1 * 4 + 3] = uint8(c2da_fresh239 >> 0x18)
        i_1++
    }
    side_0 = t1 < 0.0 ? 1 : 0
    if (SV_RecursiveHullCheck(hull_1, int(int16(uint(c2da_mem[node_4 + 4 + side_0 * 2]) | uint(c2da_mem[node_4 + 4 + side_0 * 2 + 1]) << 0x8)), p1f, midf, p1, c2da_fp, trace_1) == 0u) {
        return 0u
    }
    let c2da_fresh240 : int = node_4 + 4 + (side_0 ^ 1) * 2
    if (SV_HullPointContents(hull_1, int(int16(uint(c2da_mem[c2da_fresh240]) | uint(c2da_mem[c2da_fresh240 + 1]) << 0x8)), c2da_fp) != -2) {
        let c2da_fresh241 : int = node_4 + 4 + (side_0 ^ 1) * 2
        return SV_RecursiveHullCheck(hull_1, int(int16(uint(c2da_mem[c2da_fresh241]) | uint(c2da_mem[c2da_fresh241 + 1]) << 0x8)), midf, p2f, c2da_fp, p2, trace_1)
    }
    if ((uint(c2da_mem[trace_1]) | uint(c2da_mem[trace_1 + 1]) << 0x8 | uint(c2da_mem[trace_1 + 2]) << 0x10 | uint(c2da_mem[trace_1 + 3]) << 0x18) != 0u) {
        return 0u
    }
    if (side_0 == 0) {
        let c2da_fresh242 : float = uint_bits_to_float(uint(c2da_mem[plane_0 + 0 * 4]) | uint(c2da_mem[plane_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plane_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plane_0 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh243 : uint = float_bits_to_uint(c2da_fresh242)
        c2da_mem[trace_1 + 32 + 0 * 4] = uint8(c2da_fresh243)
        c2da_mem[trace_1 + 32 + 0 * 4 + 1] = uint8(c2da_fresh243 >> 0x8)
        c2da_mem[trace_1 + 32 + 0 * 4 + 2] = uint8(c2da_fresh243 >> 0x10)
        c2da_mem[trace_1 + 32 + 0 * 4 + 3] = uint8(c2da_fresh243 >> 0x18)
        let c2da_fresh244 : float = uint_bits_to_float(uint(c2da_mem[plane_0 + 1 * 4]) | uint(c2da_mem[plane_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plane_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plane_0 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh245 : uint = float_bits_to_uint(c2da_fresh244)
        c2da_mem[trace_1 + 32 + 1 * 4] = uint8(c2da_fresh245)
        c2da_mem[trace_1 + 32 + 1 * 4 + 1] = uint8(c2da_fresh245 >> 0x8)
        c2da_mem[trace_1 + 32 + 1 * 4 + 2] = uint8(c2da_fresh245 >> 0x10)
        c2da_mem[trace_1 + 32 + 1 * 4 + 3] = uint8(c2da_fresh245 >> 0x18)
        let c2da_fresh246 : float = uint_bits_to_float(uint(c2da_mem[plane_0 + 2 * 4]) | uint(c2da_mem[plane_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plane_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plane_0 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh247 : uint = float_bits_to_uint(c2da_fresh246)
        c2da_mem[trace_1 + 32 + 2 * 4] = uint8(c2da_fresh247)
        c2da_mem[trace_1 + 32 + 2 * 4 + 1] = uint8(c2da_fresh247 >> 0x8)
        c2da_mem[trace_1 + 32 + 2 * 4 + 2] = uint8(c2da_fresh247 >> 0x10)
        c2da_mem[trace_1 + 32 + 2 * 4 + 3] = uint8(c2da_fresh247 >> 0x18)
        let c2da_fresh248 : float = uint_bits_to_float(uint(c2da_mem[plane_0 + 12]) | uint(c2da_mem[plane_0 + 13]) << 0x8 | uint(c2da_mem[plane_0 + 14]) << 0x10 | uint(c2da_mem[plane_0 + 15]) << 0x18)
        let c2da_fresh249 : uint = float_bits_to_uint(c2da_fresh248)
        c2da_mem[trace_1 + 44] = uint8(c2da_fresh249)
        c2da_mem[trace_1 + 45] = uint8(c2da_fresh249 >> 0x8)
        c2da_mem[trace_1 + 46] = uint8(c2da_fresh249 >> 0x10)
        c2da_mem[trace_1 + 47] = uint8(c2da_fresh249 >> 0x18)
    } else {
        let c2da_fresh250 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane_0 + 0 * 4]) | uint(c2da_mem[plane_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plane_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plane_0 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh251 : uint = float_bits_to_uint(c2da_fresh250)
        c2da_mem[trace_1 + 32 + 0 * 4] = uint8(c2da_fresh251)
        c2da_mem[trace_1 + 32 + 0 * 4 + 1] = uint8(c2da_fresh251 >> 0x8)
        c2da_mem[trace_1 + 32 + 0 * 4 + 2] = uint8(c2da_fresh251 >> 0x10)
        c2da_mem[trace_1 + 32 + 0 * 4 + 3] = uint8(c2da_fresh251 >> 0x18)
        let c2da_fresh252 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane_0 + 1 * 4]) | uint(c2da_mem[plane_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plane_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plane_0 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh253 : uint = float_bits_to_uint(c2da_fresh252)
        c2da_mem[trace_1 + 32 + 1 * 4] = uint8(c2da_fresh253)
        c2da_mem[trace_1 + 32 + 1 * 4 + 1] = uint8(c2da_fresh253 >> 0x8)
        c2da_mem[trace_1 + 32 + 1 * 4 + 2] = uint8(c2da_fresh253 >> 0x10)
        c2da_mem[trace_1 + 32 + 1 * 4 + 3] = uint8(c2da_fresh253 >> 0x18)
        let c2da_fresh254 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[plane_0 + 2 * 4]) | uint(c2da_mem[plane_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[plane_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[plane_0 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh255 : uint = float_bits_to_uint(c2da_fresh254)
        c2da_mem[trace_1 + 32 + 2 * 4] = uint8(c2da_fresh255)
        c2da_mem[trace_1 + 32 + 2 * 4 + 1] = uint8(c2da_fresh255 >> 0x8)
        c2da_mem[trace_1 + 32 + 2 * 4 + 2] = uint8(c2da_fresh255 >> 0x10)
        c2da_mem[trace_1 + 32 + 2 * 4 + 3] = uint8(c2da_fresh255 >> 0x18)
        let c2da_fresh256 : float = -uint_bits_to_float(uint(c2da_mem[plane_0 + 12]) | uint(c2da_mem[plane_0 + 13]) << 0x8 | uint(c2da_mem[plane_0 + 14]) << 0x10 | uint(c2da_mem[plane_0 + 15]) << 0x18)
        let c2da_fresh257 : uint = float_bits_to_uint(c2da_fresh256)
        c2da_mem[trace_1 + 44] = uint8(c2da_fresh257)
        c2da_mem[trace_1 + 45] = uint8(c2da_fresh257 >> 0x8)
        c2da_mem[trace_1 + 46] = uint8(c2da_fresh257 >> 0x10)
        c2da_mem[trace_1 + 47] = uint8(c2da_fresh257 >> 0x18)
    }
    while (SV_HullPointContents(hull_1, int(uint(c2da_mem[hull_1 + 16]) | uint(c2da_mem[hull_1 + 17]) << 0x8 | uint(c2da_mem[hull_1 + 18]) << 0x10 | uint(c2da_mem[hull_1 + 19]) << 0x18), c2da_fp) == -2) {
        frac = float(double(frac) - 0.1lf)
        if (frac < 0.0) {
            let c2da_fresh258 : uint = float_bits_to_uint(midf)
            c2da_mem[trace_1 + 16] = uint8(c2da_fresh258)
            c2da_mem[trace_1 + 17] = uint8(c2da_fresh258 >> 0x8)
            c2da_mem[trace_1 + 18] = uint8(c2da_fresh258 >> 0x10)
            c2da_mem[trace_1 + 19] = uint8(c2da_fresh258 >> 0x18)
            let c2da_fresh259 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
            let c2da_fresh260 : uint = float_bits_to_uint(c2da_fresh259)
            c2da_mem[trace_1 + 20 + 0 * 4] = uint8(c2da_fresh260)
            c2da_mem[trace_1 + 20 + 0 * 4 + 1] = uint8(c2da_fresh260 >> 0x8)
            c2da_mem[trace_1 + 20 + 0 * 4 + 2] = uint8(c2da_fresh260 >> 0x10)
            c2da_mem[trace_1 + 20 + 0 * 4 + 3] = uint8(c2da_fresh260 >> 0x18)
            let c2da_fresh261 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
            let c2da_fresh262 : uint = float_bits_to_uint(c2da_fresh261)
            c2da_mem[trace_1 + 20 + 1 * 4] = uint8(c2da_fresh262)
            c2da_mem[trace_1 + 20 + 1 * 4 + 1] = uint8(c2da_fresh262 >> 0x8)
            c2da_mem[trace_1 + 20 + 1 * 4 + 2] = uint8(c2da_fresh262 >> 0x10)
            c2da_mem[trace_1 + 20 + 1 * 4 + 3] = uint8(c2da_fresh262 >> 0x18)
            let c2da_fresh263 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
            let c2da_fresh264 : uint = float_bits_to_uint(c2da_fresh263)
            c2da_mem[trace_1 + 20 + 2 * 4] = uint8(c2da_fresh264)
            c2da_mem[trace_1 + 20 + 2 * 4 + 1] = uint8(c2da_fresh264 >> 0x8)
            c2da_mem[trace_1 + 20 + 2 * 4 + 2] = uint8(c2da_fresh264 >> 0x10)
            c2da_mem[trace_1 + 20 + 2 * 4 + 3] = uint8(c2da_fresh264 >> 0x18)
            Con_DPrintf(739974, [])
            return 0u
        }
        midf = p1f + (p2f - p1f) * frac
        i_1 = 0
        while (i_1 < 3) {
            let c2da_fresh265 : float = uint_bits_to_float(uint(c2da_mem[p1 + i_1 * 4]) | uint(c2da_mem[p1 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[p1 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[p1 + i_1 * 4 + 3]) << 0x18) + frac * (uint_bits_to_float(uint(c2da_mem[p2 + i_1 * 4]) | uint(c2da_mem[p2 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[p2 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[p2 + i_1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[p1 + i_1 * 4]) | uint(c2da_mem[p1 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[p1 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[p1 + i_1 * 4 + 3]) << 0x18))
            let c2da_fresh266 : uint = float_bits_to_uint(c2da_fresh265)
            c2da_mem[c2da_fp + i_1 * 4] = uint8(c2da_fresh266)
            c2da_mem[c2da_fp + i_1 * 4 + 1] = uint8(c2da_fresh266 >> 0x8)
            c2da_mem[c2da_fp + i_1 * 4 + 2] = uint8(c2da_fresh266 >> 0x10)
            c2da_mem[c2da_fp + i_1 * 4 + 3] = uint8(c2da_fresh266 >> 0x18)
            i_1++
        }
    }
    let c2da_fresh267 : uint = float_bits_to_uint(midf)
    c2da_mem[trace_1 + 16] = uint8(c2da_fresh267)
    c2da_mem[trace_1 + 17] = uint8(c2da_fresh267 >> 0x8)
    c2da_mem[trace_1 + 18] = uint8(c2da_fresh267 >> 0x10)
    c2da_mem[trace_1 + 19] = uint8(c2da_fresh267 >> 0x18)
    let c2da_fresh268 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
    let c2da_fresh269 : uint = float_bits_to_uint(c2da_fresh268)
    c2da_mem[trace_1 + 20 + 0 * 4] = uint8(c2da_fresh269)
    c2da_mem[trace_1 + 20 + 0 * 4 + 1] = uint8(c2da_fresh269 >> 0x8)
    c2da_mem[trace_1 + 20 + 0 * 4 + 2] = uint8(c2da_fresh269 >> 0x10)
    c2da_mem[trace_1 + 20 + 0 * 4 + 3] = uint8(c2da_fresh269 >> 0x18)
    let c2da_fresh270 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
    let c2da_fresh271 : uint = float_bits_to_uint(c2da_fresh270)
    c2da_mem[trace_1 + 20 + 1 * 4] = uint8(c2da_fresh271)
    c2da_mem[trace_1 + 20 + 1 * 4 + 1] = uint8(c2da_fresh271 >> 0x8)
    c2da_mem[trace_1 + 20 + 1 * 4 + 2] = uint8(c2da_fresh271 >> 0x10)
    c2da_mem[trace_1 + 20 + 1 * 4 + 3] = uint8(c2da_fresh271 >> 0x18)
    let c2da_fresh272 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
    let c2da_fresh273 : uint = float_bits_to_uint(c2da_fresh272)
    c2da_mem[trace_1 + 20 + 2 * 4] = uint8(c2da_fresh273)
    c2da_mem[trace_1 + 20 + 2 * 4 + 1] = uint8(c2da_fresh273 >> 0x8)
    c2da_mem[trace_1 + 20 + 2 * 4 + 2] = uint8(c2da_fresh273 >> 0x10)
    c2da_mem[trace_1 + 20 + 2 * 4 + 3] = uint8(c2da_fresh273 >> 0x18)
    return 0u
}
[sideeffects]
def private SV_HullForEntity_c2da_frame(var ent_5 : int; var mins_2 : int; var maxs_2 : int; var offset : int; c2da_fp : int) : int {
    var model : int
    var size_0 : vec3_t
    var hull_2 : int
    if (uint_bits_to_float(uint(c2da_mem[ent_5 + 144]) | uint(c2da_mem[ent_5 + 145]) << 0x8 | uint(c2da_mem[ent_5 + 146]) << 0x10 | uint(c2da_mem[ent_5 + 147]) << 0x18) == 4.0) {
        if (uint_bits_to_float(uint(c2da_mem[ent_5 + 140]) | uint(c2da_mem[ent_5 + 141]) << 0x8 | uint(c2da_mem[ent_5 + 142]) << 0x10 | uint(c2da_mem[ent_5 + 143]) << 0x18) != 7.0) {
            Sys_Error(739989, [])
        }
        let c2da_fresh274 : int = 228080 + int(uint_bits_to_float(uint(c2da_mem[ent_5 + 108]) | uint(c2da_mem[ent_5 + 109]) << 0x8 | uint(c2da_mem[ent_5 + 110]) << 0x10 | uint(c2da_mem[ent_5 + 111]) << 0x18)) * 8
        model = int(uint(c2da_mem[c2da_fresh274]) | uint(c2da_mem[c2da_fresh274 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh274 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh274 + 3]) << 0x18)
        if (model == 0 || (uint(c2da_mem[model + 68]) | uint(c2da_mem[model + 69]) << 0x8 | uint(c2da_mem[model + 70]) << 0x10 | uint(c2da_mem[model + 71]) << 0x18) != 0u) {
            Sys_Error(740021, [])
        }
        size_0[0] = uint_bits_to_float(uint(c2da_mem[maxs_2 + 0 * 4]) | uint(c2da_mem[maxs_2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs_2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs_2 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[mins_2 + 0 * 4]) | uint(c2da_mem[mins_2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_2 + 0 * 4 + 3]) << 0x18)
        size_0[1] = uint_bits_to_float(uint(c2da_mem[maxs_2 + 1 * 4]) | uint(c2da_mem[maxs_2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs_2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs_2 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[mins_2 + 1 * 4]) | uint(c2da_mem[mins_2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_2 + 1 * 4 + 3]) << 0x18)
        size_0[2] = uint_bits_to_float(uint(c2da_mem[maxs_2 + 2 * 4]) | uint(c2da_mem[maxs_2 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs_2 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs_2 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[mins_2 + 2 * 4]) | uint(c2da_mem[mins_2 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_2 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_2 + 2 * 4 + 3]) << 0x18)
        if (size_0[0] < 3.0) {
            hull_2 = model + 296 + 0 * 48
        } elif (size_0[0] <= 32.0) {
            hull_2 = model + 296 + 1 * 48
        } else {
            hull_2 = model + 296 + 2 * 48
        }
        let c2da_fresh275 : float = uint_bits_to_float(uint(c2da_mem[hull_2 + 24 + 0 * 4]) | uint(c2da_mem[hull_2 + 24 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[hull_2 + 24 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[hull_2 + 24 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[mins_2 + 0 * 4]) | uint(c2da_mem[mins_2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_2 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh276 : uint = float_bits_to_uint(c2da_fresh275)
        c2da_mem[offset + 0 * 4] = uint8(c2da_fresh276)
        c2da_mem[offset + 0 * 4 + 1] = uint8(c2da_fresh276 >> 0x8)
        c2da_mem[offset + 0 * 4 + 2] = uint8(c2da_fresh276 >> 0x10)
        c2da_mem[offset + 0 * 4 + 3] = uint8(c2da_fresh276 >> 0x18)
        let c2da_fresh277 : float = uint_bits_to_float(uint(c2da_mem[hull_2 + 24 + 1 * 4]) | uint(c2da_mem[hull_2 + 24 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[hull_2 + 24 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[hull_2 + 24 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[mins_2 + 1 * 4]) | uint(c2da_mem[mins_2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_2 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh278 : uint = float_bits_to_uint(c2da_fresh277)
        c2da_mem[offset + 1 * 4] = uint8(c2da_fresh278)
        c2da_mem[offset + 1 * 4 + 1] = uint8(c2da_fresh278 >> 0x8)
        c2da_mem[offset + 1 * 4 + 2] = uint8(c2da_fresh278 >> 0x10)
        c2da_mem[offset + 1 * 4 + 3] = uint8(c2da_fresh278 >> 0x18)
        let c2da_fresh279 : float = uint_bits_to_float(uint(c2da_mem[hull_2 + 24 + 2 * 4]) | uint(c2da_mem[hull_2 + 24 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[hull_2 + 24 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[hull_2 + 24 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[mins_2 + 2 * 4]) | uint(c2da_mem[mins_2 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_2 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_2 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh280 : uint = float_bits_to_uint(c2da_fresh279)
        c2da_mem[offset + 2 * 4] = uint8(c2da_fresh280)
        c2da_mem[offset + 2 * 4 + 1] = uint8(c2da_fresh280 >> 0x8)
        c2da_mem[offset + 2 * 4 + 2] = uint8(c2da_fresh280 >> 0x10)
        c2da_mem[offset + 2 * 4 + 3] = uint8(c2da_fresh280 >> 0x18)
        let c2da_fresh281 : float = uint_bits_to_float(uint(c2da_mem[offset + 0 * 4]) | uint(c2da_mem[offset + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[offset + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[offset + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_5 + 148 + 0 * 4]) | uint(c2da_mem[ent_5 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_5 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_5 + 148 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh282 : uint = float_bits_to_uint(c2da_fresh281)
        c2da_mem[offset + 0 * 4] = uint8(c2da_fresh282)
        c2da_mem[offset + 0 * 4 + 1] = uint8(c2da_fresh282 >> 0x8)
        c2da_mem[offset + 0 * 4 + 2] = uint8(c2da_fresh282 >> 0x10)
        c2da_mem[offset + 0 * 4 + 3] = uint8(c2da_fresh282 >> 0x18)
        let c2da_fresh283 : float = uint_bits_to_float(uint(c2da_mem[offset + 1 * 4]) | uint(c2da_mem[offset + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[offset + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[offset + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_5 + 148 + 1 * 4]) | uint(c2da_mem[ent_5 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_5 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_5 + 148 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh284 : uint = float_bits_to_uint(c2da_fresh283)
        c2da_mem[offset + 1 * 4] = uint8(c2da_fresh284)
        c2da_mem[offset + 1 * 4 + 1] = uint8(c2da_fresh284 >> 0x8)
        c2da_mem[offset + 1 * 4 + 2] = uint8(c2da_fresh284 >> 0x10)
        c2da_mem[offset + 1 * 4 + 3] = uint8(c2da_fresh284 >> 0x18)
        let c2da_fresh285 : float = uint_bits_to_float(uint(c2da_mem[offset + 2 * 4]) | uint(c2da_mem[offset + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[offset + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[offset + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent_5 + 148 + 2 * 4]) | uint(c2da_mem[ent_5 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_5 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_5 + 148 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh286 : uint = float_bits_to_uint(c2da_fresh285)
        c2da_mem[offset + 2 * 4] = uint8(c2da_fresh286)
        c2da_mem[offset + 2 * 4 + 1] = uint8(c2da_fresh286 >> 0x8)
        c2da_mem[offset + 2 * 4 + 2] = uint8(c2da_fresh286 >> 0x10)
        c2da_mem[offset + 2 * 4 + 3] = uint8(c2da_fresh286 >> 0x18)
    } else {
        let c2da_fresh287 : float = uint_bits_to_float(uint(c2da_mem[ent_5 + 240 + 0 * 4]) | uint(c2da_mem[ent_5 + 240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_5 + 240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_5 + 240 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[maxs_2 + 0 * 4]) | uint(c2da_mem[maxs_2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs_2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs_2 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh288 : uint = float_bits_to_uint(c2da_fresh287)
        c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh288)
        c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh288 >> 0x8)
        c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh288 >> 0x10)
        c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh288 >> 0x18)
        let c2da_fresh289 : float = uint_bits_to_float(uint(c2da_mem[ent_5 + 240 + 1 * 4]) | uint(c2da_mem[ent_5 + 240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_5 + 240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_5 + 240 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[maxs_2 + 1 * 4]) | uint(c2da_mem[maxs_2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs_2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs_2 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh290 : uint = float_bits_to_uint(c2da_fresh289)
        c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh290)
        c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh290 >> 0x8)
        c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh290 >> 0x10)
        c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh290 >> 0x18)
        let c2da_fresh291 : float = uint_bits_to_float(uint(c2da_mem[ent_5 + 240 + 2 * 4]) | uint(c2da_mem[ent_5 + 240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_5 + 240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_5 + 240 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[maxs_2 + 2 * 4]) | uint(c2da_mem[maxs_2 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[maxs_2 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[maxs_2 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh292 : uint = float_bits_to_uint(c2da_fresh291)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh292)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh292 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh292 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh292 >> 0x18)
        let c2da_fresh293 : float = uint_bits_to_float(uint(c2da_mem[ent_5 + 252 + 0 * 4]) | uint(c2da_mem[ent_5 + 252 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_5 + 252 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_5 + 252 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[mins_2 + 0 * 4]) | uint(c2da_mem[mins_2 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_2 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_2 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh294 : uint = float_bits_to_uint(c2da_fresh293)
        c2da_mem[c2da_fp + 16 + 0 * 4] = uint8(c2da_fresh294)
        c2da_mem[c2da_fp + 16 + 0 * 4 + 1] = uint8(c2da_fresh294 >> 0x8)
        c2da_mem[c2da_fp + 16 + 0 * 4 + 2] = uint8(c2da_fresh294 >> 0x10)
        c2da_mem[c2da_fp + 16 + 0 * 4 + 3] = uint8(c2da_fresh294 >> 0x18)
        let c2da_fresh295 : float = uint_bits_to_float(uint(c2da_mem[ent_5 + 252 + 1 * 4]) | uint(c2da_mem[ent_5 + 252 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_5 + 252 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_5 + 252 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[mins_2 + 1 * 4]) | uint(c2da_mem[mins_2 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_2 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_2 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh296 : uint = float_bits_to_uint(c2da_fresh295)
        c2da_mem[c2da_fp + 16 + 1 * 4] = uint8(c2da_fresh296)
        c2da_mem[c2da_fp + 16 + 1 * 4 + 1] = uint8(c2da_fresh296 >> 0x8)
        c2da_mem[c2da_fp + 16 + 1 * 4 + 2] = uint8(c2da_fresh296 >> 0x10)
        c2da_mem[c2da_fp + 16 + 1 * 4 + 3] = uint8(c2da_fresh296 >> 0x18)
        let c2da_fresh297 : float = uint_bits_to_float(uint(c2da_mem[ent_5 + 252 + 2 * 4]) | uint(c2da_mem[ent_5 + 252 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_5 + 252 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_5 + 252 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[mins_2 + 2 * 4]) | uint(c2da_mem[mins_2 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[mins_2 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[mins_2 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh298 : uint = float_bits_to_uint(c2da_fresh297)
        c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh298)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh298 >> 0x8)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh298 >> 0x10)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh298 >> 0x18)
        hull_2 = SV_HullForBox(c2da_fp, c2da_fp + 16)
        let c2da_fresh299 : float = uint_bits_to_float(uint(c2da_mem[ent_5 + 148 + 0 * 4]) | uint(c2da_mem[ent_5 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_5 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_5 + 148 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh300 : uint = float_bits_to_uint(c2da_fresh299)
        c2da_mem[offset + 0 * 4] = uint8(c2da_fresh300)
        c2da_mem[offset + 0 * 4 + 1] = uint8(c2da_fresh300 >> 0x8)
        c2da_mem[offset + 0 * 4 + 2] = uint8(c2da_fresh300 >> 0x10)
        c2da_mem[offset + 0 * 4 + 3] = uint8(c2da_fresh300 >> 0x18)
        let c2da_fresh301 : float = uint_bits_to_float(uint(c2da_mem[ent_5 + 148 + 1 * 4]) | uint(c2da_mem[ent_5 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_5 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_5 + 148 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh302 : uint = float_bits_to_uint(c2da_fresh301)
        c2da_mem[offset + 1 * 4] = uint8(c2da_fresh302)
        c2da_mem[offset + 1 * 4 + 1] = uint8(c2da_fresh302 >> 0x8)
        c2da_mem[offset + 1 * 4 + 2] = uint8(c2da_fresh302 >> 0x10)
        c2da_mem[offset + 1 * 4 + 3] = uint8(c2da_fresh302 >> 0x18)
        let c2da_fresh303 : float = uint_bits_to_float(uint(c2da_mem[ent_5 + 148 + 2 * 4]) | uint(c2da_mem[ent_5 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_5 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_5 + 148 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh304 : uint = float_bits_to_uint(c2da_fresh303)
        c2da_mem[offset + 2 * 4] = uint8(c2da_fresh304)
        c2da_mem[offset + 2 * 4 + 1] = uint8(c2da_fresh304 >> 0x8)
        c2da_mem[offset + 2 * 4 + 2] = uint8(c2da_fresh304 >> 0x10)
        c2da_mem[offset + 2 * 4 + 3] = uint8(c2da_fresh304 >> 0x18)
    }
    return hull_2
}

// This unit's static data, at heap offset 737856.
let private c2da_lin_static_world_seg = fixed_array<int>(739872, 183)
let private c2da_lin_static_world = fixed_array<uint64>(0x506c6c75485f5653ul, 0x746e6f43746e696ful, 0x6162203a73746e65ul, 0x6e2065646f6e2064ul, 0x7254007265626d75ul, 0x6e69207265676769ul, 0x6e697070696c6320ul, 0x53007473696c2067ul, 0x7372756365525f56ul, 0x436c6c7548657669ul, 0x6162203a6b636568ul, 0x6e2065646f6e2064ul, 0x6162007265626d75ul, 0x7361702070756b63ul, 0x4c4f53000a302074ul, 0x77205053425f4449ul, 0x4d2074756f687469ul, 0x5f4550595445564ful, 0x564f4d0048535550ul, 0x55505f4550595445ul, 0x2068746977204853ul, 0x7362206e6f6e2061ul, 0x6c65646f6d2070ul)

[init]
def private c2da_lin_init_static_world() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_world_seg[s * 2]
        for (k in range(c2da_lin_static_world_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_world[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
