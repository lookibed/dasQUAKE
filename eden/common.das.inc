[export, sideeffects]
def SZ_Alloc(var buf : int; var startsize : int) {
    if (startsize < 256) {
        startsize = 256
    }
    let c2da_fresh0 : int = Hunk_AllocName(startsize, 704629)
    let c2da_fresh1 : uint = uint(c2da_fresh0)
    c2da_mem[buf + 8] = uint8(c2da_fresh1)
    c2da_mem[buf + 9] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[buf + 10] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[buf + 11] = uint8(c2da_fresh1 >> 0x18)
    c2da_mem[buf + 12] = 0u8
    c2da_mem[buf + 13] = 0u8
    c2da_mem[buf + 14] = 0u8
    c2da_mem[buf + 15] = 0u8
    let c2da_fresh2 : uint = uint(startsize)
    c2da_mem[buf + 16] = uint8(c2da_fresh2)
    c2da_mem[buf + 17] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[buf + 18] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[buf + 19] = uint8(c2da_fresh2 >> 0x18)
    let c2da_fresh3 : int = 0
    let c2da_fresh4 : uint = uint(c2da_fresh3)
    c2da_mem[buf + 20] = uint8(c2da_fresh4)
    c2da_mem[buf + 21] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[buf + 22] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[buf + 23] = uint8(c2da_fresh4 >> 0x18)
    return
}
[export, sideeffects]
def SZ_Free(var buf_0 : int) {
    let c2da_fresh5 : int = 0
    let c2da_fresh6 : uint = uint(c2da_fresh5)
    c2da_mem[buf_0 + 20] = uint8(c2da_fresh6)
    c2da_mem[buf_0 + 21] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[buf_0 + 22] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[buf_0 + 23] = uint8(c2da_fresh6 >> 0x18)
    return
}
[export, sideeffects]
def SZ_Clear(var buf_1 : int) {
    let c2da_fresh7 : int = 0
    let c2da_fresh8 : uint = uint(c2da_fresh7)
    c2da_mem[buf_1 + 20] = uint8(c2da_fresh8)
    c2da_mem[buf_1 + 21] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[buf_1 + 22] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[buf_1 + 23] = uint8(c2da_fresh8 >> 0x18)
    return
}
[export, sideeffects]
def SZ_GetSpace(var buf_2 : int; var length_0 : int) : int {
    var data : int
    let c2da_fresh13 : int = int(uint(c2da_mem[buf_2 + 16]) | uint(c2da_mem[buf_2 + 17]) << 0x8 | uint(c2da_mem[buf_2 + 18]) << 0x10 | uint(c2da_mem[buf_2 + 19]) << 0x18)
    if (int(uint(c2da_mem[buf_2 + 20]) | uint(c2da_mem[buf_2 + 21]) << 0x8 | uint(c2da_mem[buf_2 + 22]) << 0x10 | uint(c2da_mem[buf_2 + 23]) << 0x18) + length_0 > c2da_fresh13) {
        if ((uint(c2da_mem[buf_2]) | uint(c2da_mem[buf_2 + 1]) << 0x8 | uint(c2da_mem[buf_2 + 2]) << 0x10 | uint(c2da_mem[buf_2 + 3]) << 0x18) == 0u) {
            Sys_Error(704637, [])
        }
        if (length_0 > int(uint(c2da_mem[buf_2 + 16]) | uint(c2da_mem[buf_2 + 17]) << 0x8 | uint(c2da_mem[buf_2 + 18]) << 0x10 | uint(c2da_mem[buf_2 + 19]) << 0x18)) {
            Sys_Error(704685, [C2daVaArg(tag = 1, i64 = int64(length_0), f64 = 0.0lf, raw = 0x0)])
        }
        let c2da_fresh9 : uint = 1u
        let c2da_fresh10 : uint = c2da_fresh9
        c2da_mem[buf_2 + 4] = uint8(c2da_fresh10)
        c2da_mem[buf_2 + 5] = uint8(c2da_fresh10 >> 0x8)
        c2da_mem[buf_2 + 6] = uint8(c2da_fresh10 >> 0x10)
        c2da_mem[buf_2 + 7] = uint8(c2da_fresh10 >> 0x18)
        Con_Printf(704723, [])
        SZ_Clear(buf_2)
    }
    let c2da_fresh14 : int = int(uint(c2da_mem[buf_2 + 20]) | uint(c2da_mem[buf_2 + 21]) << 0x8 | uint(c2da_mem[buf_2 + 22]) << 0x10 | uint(c2da_mem[buf_2 + 23]) << 0x18)
    data = int(uint(c2da_mem[buf_2 + 8]) | uint(c2da_mem[buf_2 + 9]) << 0x8 | uint(c2da_mem[buf_2 + 10]) << 0x10 | uint(c2da_mem[buf_2 + 11]) << 0x18) + c2da_fresh14
    let c2da_fresh11 : int = c2da_fresh14 + length_0
    let c2da_fresh12 : uint = uint(c2da_fresh11)
    c2da_mem[buf_2 + 20] = uint8(c2da_fresh12)
    c2da_mem[buf_2 + 21] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[buf_2 + 22] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[buf_2 + 23] = uint8(c2da_fresh12 >> 0x18)
    return data
}
[export, sideeffects]
def SZ_Write(var buf_3 : int; var data_0 : int; var length_1 : int) {
    Q_memcpy(SZ_GetSpace(buf_3, length_1), data_0, length_1)
    return
}
[export, sideeffects]
def Q_memcpy(var dest : int; var src : int; var count : int) {
    var i : int
    if (((int64(dest) | int64(src) | int64(count)) & 3l) == 0l) {
        count >>= 2
        i = 0
        for (c2da_i in range(i, count)) {
            let c2da_fresh15 : int = int(uint(c2da_mem[src + c2da_i * 4]) | uint(c2da_mem[src + c2da_i * 4 + 1]) << 0x8 | uint(c2da_mem[src + c2da_i * 4 + 2]) << 0x10 | uint(c2da_mem[src + c2da_i * 4 + 3]) << 0x18)
            let c2da_fresh16 : uint = uint(c2da_fresh15)
            c2da_mem[dest + c2da_i * 4] = uint8(c2da_fresh16)
            c2da_mem[dest + c2da_i * 4 + 1] = uint8(c2da_fresh16 >> 0x8)
            c2da_mem[dest + c2da_i * 4 + 2] = uint8(c2da_fresh16 >> 0x10)
            c2da_mem[dest + c2da_i * 4 + 3] = uint8(c2da_fresh16 >> 0x18)
        }
    } else {
        i = 0
        for (c2da_i_0 in range(i, count)) {
            let c2da_fresh17 : uint8 = c2da_mem[src + c2da_i_0]
            c2da_mem[dest + c2da_i_0] = c2da_fresh17
        }
    }
    return
}
[export, sideeffects]
def SZ_Print(var buf_4 : int; var data_1 : int) {
    var len : int = Q_strlen(data_1) + 1
    let c2da_fresh18 : int = int(uint(c2da_mem[buf_4 + 8]) | uint(c2da_mem[buf_4 + 9]) << 0x8 | uint(c2da_mem[buf_4 + 10]) << 0x10 | uint(c2da_mem[buf_4 + 11]) << 0x18) + (int(uint(c2da_mem[buf_4 + 20]) | uint(c2da_mem[buf_4 + 21]) << 0x8 | uint(c2da_mem[buf_4 + 22]) << 0x10 | uint(c2da_mem[buf_4 + 23]) << 0x18) - 1)
    if (c2da_mem[c2da_fresh18] != 0x0) {
        Q_memcpy(SZ_GetSpace(buf_4, len), data_1, len)
    } else {
        Q_memcpy(SZ_GetSpace(buf_4, len - 1) - 1, data_1, len)
    }
    return
}
[export, sideeffects]
def Q_strlen(var str : int) : int {
    var count_0 : int = 0
    while (int8(c2da_mem[str + count_0]) != 0) {
        count_0++
    }
    return count_0
}
[export, sideeffects]
def ClearLink(var l : int) {
    let c2da_fresh19 : uint = uint(l)
    c2da_mem[l + 8] = uint8(c2da_fresh19)
    c2da_mem[l + 9] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[l + 10] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[l + 11] = uint8(c2da_fresh19 >> 0x18)
    c2da_mem[l + 12] = 0u8
    c2da_mem[l + 13] = 0u8
    c2da_mem[l + 14] = 0u8
    c2da_mem[l + 15] = 0u8
    let c2da_fresh20 : uint = uint(l)
    c2da_mem[l] = uint8(c2da_fresh20)
    c2da_mem[l + 1] = uint8(c2da_fresh20 >> 0x8)
    c2da_mem[l + 2] = uint8(c2da_fresh20 >> 0x10)
    c2da_mem[l + 3] = uint8(c2da_fresh20 >> 0x18)
    c2da_mem[l + 4] = 0u8
    c2da_mem[l + 5] = 0u8
    c2da_mem[l + 6] = 0u8
    c2da_mem[l + 7] = 0u8
    return
}
[export, sideeffects]
def RemoveLink(var l_0 : int) {
    let c2da_fresh21 : int = int(uint(c2da_mem[l_0 + 8]) | uint(c2da_mem[l_0 + 9]) << 0x8 | uint(c2da_mem[l_0 + 10]) << 0x10 | uint(c2da_mem[l_0 + 11]) << 0x18)
    let c2da_fresh22 : int = int(uint(c2da_mem[l_0]) | uint(c2da_mem[l_0 + 1]) << 0x8 | uint(c2da_mem[l_0 + 2]) << 0x10 | uint(c2da_mem[l_0 + 3]) << 0x18)
    let c2da_fresh23 : uint = uint(c2da_fresh22)
    c2da_mem[c2da_fresh21] = uint8(c2da_fresh23)
    c2da_mem[c2da_fresh21 + 1] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[c2da_fresh21 + 2] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[c2da_fresh21 + 3] = uint8(c2da_fresh23 >> 0x18)
    c2da_mem[c2da_fresh21 + 4] = 0u8
    c2da_mem[c2da_fresh21 + 5] = 0u8
    c2da_mem[c2da_fresh21 + 6] = 0u8
    c2da_mem[c2da_fresh21 + 7] = 0u8
    let c2da_fresh24 : int = int(uint(c2da_mem[l_0]) | uint(c2da_mem[l_0 + 1]) << 0x8 | uint(c2da_mem[l_0 + 2]) << 0x10 | uint(c2da_mem[l_0 + 3]) << 0x18) + 8
    let c2da_fresh25 : int = int(uint(c2da_mem[l_0 + 8]) | uint(c2da_mem[l_0 + 9]) << 0x8 | uint(c2da_mem[l_0 + 10]) << 0x10 | uint(c2da_mem[l_0 + 11]) << 0x18)
    let c2da_fresh26 : uint = uint(c2da_fresh25)
    c2da_mem[c2da_fresh24] = uint8(c2da_fresh26)
    c2da_mem[c2da_fresh24 + 1] = uint8(c2da_fresh26 >> 0x8)
    c2da_mem[c2da_fresh24 + 2] = uint8(c2da_fresh26 >> 0x10)
    c2da_mem[c2da_fresh24 + 3] = uint8(c2da_fresh26 >> 0x18)
    c2da_mem[c2da_fresh24 + 4] = 0u8
    c2da_mem[c2da_fresh24 + 5] = 0u8
    c2da_mem[c2da_fresh24 + 6] = 0u8
    c2da_mem[c2da_fresh24 + 7] = 0u8
    return
}
[export, sideeffects]
def InsertLinkBefore(var l_1 : int; var before : int) {
    let c2da_fresh27 : uint = uint(before)
    c2da_mem[l_1 + 8] = uint8(c2da_fresh27)
    c2da_mem[l_1 + 9] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[l_1 + 10] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[l_1 + 11] = uint8(c2da_fresh27 >> 0x18)
    c2da_mem[l_1 + 12] = 0u8
    c2da_mem[l_1 + 13] = 0u8
    c2da_mem[l_1 + 14] = 0u8
    c2da_mem[l_1 + 15] = 0u8
    let c2da_fresh28 : int = int(uint(c2da_mem[before]) | uint(c2da_mem[before + 1]) << 0x8 | uint(c2da_mem[before + 2]) << 0x10 | uint(c2da_mem[before + 3]) << 0x18)
    let c2da_fresh29 : uint = uint(c2da_fresh28)
    c2da_mem[l_1] = uint8(c2da_fresh29)
    c2da_mem[l_1 + 1] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[l_1 + 2] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[l_1 + 3] = uint8(c2da_fresh29 >> 0x18)
    c2da_mem[l_1 + 4] = 0u8
    c2da_mem[l_1 + 5] = 0u8
    c2da_mem[l_1 + 6] = 0u8
    c2da_mem[l_1 + 7] = 0u8
    let c2da_fresh30 : int = int(uint(c2da_mem[l_1]) | uint(c2da_mem[l_1 + 1]) << 0x8 | uint(c2da_mem[l_1 + 2]) << 0x10 | uint(c2da_mem[l_1 + 3]) << 0x18) + 8
    let c2da_fresh31 : uint = uint(l_1)
    c2da_mem[c2da_fresh30] = uint8(c2da_fresh31)
    c2da_mem[c2da_fresh30 + 1] = uint8(c2da_fresh31 >> 0x8)
    c2da_mem[c2da_fresh30 + 2] = uint8(c2da_fresh31 >> 0x10)
    c2da_mem[c2da_fresh30 + 3] = uint8(c2da_fresh31 >> 0x18)
    c2da_mem[c2da_fresh30 + 4] = 0u8
    c2da_mem[c2da_fresh30 + 5] = 0u8
    c2da_mem[c2da_fresh30 + 6] = 0u8
    c2da_mem[c2da_fresh30 + 7] = 0u8
    let c2da_fresh32 : int = int(uint(c2da_mem[l_1 + 8]) | uint(c2da_mem[l_1 + 9]) << 0x8 | uint(c2da_mem[l_1 + 10]) << 0x10 | uint(c2da_mem[l_1 + 11]) << 0x18)
    let c2da_fresh33 : uint = uint(l_1)
    c2da_mem[c2da_fresh32] = uint8(c2da_fresh33)
    c2da_mem[c2da_fresh32 + 1] = uint8(c2da_fresh33 >> 0x8)
    c2da_mem[c2da_fresh32 + 2] = uint8(c2da_fresh33 >> 0x10)
    c2da_mem[c2da_fresh32 + 3] = uint8(c2da_fresh33 >> 0x18)
    c2da_mem[c2da_fresh32 + 4] = 0u8
    c2da_mem[c2da_fresh32 + 5] = 0u8
    c2da_mem[c2da_fresh32 + 6] = 0u8
    c2da_mem[c2da_fresh32 + 7] = 0u8
    return
}
[export, sideeffects]
def InsertLinkAfter(var l_2 : int; var after : int) {
    let c2da_fresh34 : int = int(uint(c2da_mem[after + 8]) | uint(c2da_mem[after + 9]) << 0x8 | uint(c2da_mem[after + 10]) << 0x10 | uint(c2da_mem[after + 11]) << 0x18)
    let c2da_fresh35 : uint = uint(c2da_fresh34)
    c2da_mem[l_2 + 8] = uint8(c2da_fresh35)
    c2da_mem[l_2 + 9] = uint8(c2da_fresh35 >> 0x8)
    c2da_mem[l_2 + 10] = uint8(c2da_fresh35 >> 0x10)
    c2da_mem[l_2 + 11] = uint8(c2da_fresh35 >> 0x18)
    c2da_mem[l_2 + 12] = 0u8
    c2da_mem[l_2 + 13] = 0u8
    c2da_mem[l_2 + 14] = 0u8
    c2da_mem[l_2 + 15] = 0u8
    let c2da_fresh36 : uint = uint(after)
    c2da_mem[l_2] = uint8(c2da_fresh36)
    c2da_mem[l_2 + 1] = uint8(c2da_fresh36 >> 0x8)
    c2da_mem[l_2 + 2] = uint8(c2da_fresh36 >> 0x10)
    c2da_mem[l_2 + 3] = uint8(c2da_fresh36 >> 0x18)
    c2da_mem[l_2 + 4] = 0u8
    c2da_mem[l_2 + 5] = 0u8
    c2da_mem[l_2 + 6] = 0u8
    c2da_mem[l_2 + 7] = 0u8
    let c2da_fresh37 : int = int(uint(c2da_mem[l_2]) | uint(c2da_mem[l_2 + 1]) << 0x8 | uint(c2da_mem[l_2 + 2]) << 0x10 | uint(c2da_mem[l_2 + 3]) << 0x18) + 8
    let c2da_fresh38 : uint = uint(l_2)
    c2da_mem[c2da_fresh37] = uint8(c2da_fresh38)
    c2da_mem[c2da_fresh37 + 1] = uint8(c2da_fresh38 >> 0x8)
    c2da_mem[c2da_fresh37 + 2] = uint8(c2da_fresh38 >> 0x10)
    c2da_mem[c2da_fresh37 + 3] = uint8(c2da_fresh38 >> 0x18)
    c2da_mem[c2da_fresh37 + 4] = 0u8
    c2da_mem[c2da_fresh37 + 5] = 0u8
    c2da_mem[c2da_fresh37 + 6] = 0u8
    c2da_mem[c2da_fresh37 + 7] = 0u8
    let c2da_fresh39 : int = int(uint(c2da_mem[l_2 + 8]) | uint(c2da_mem[l_2 + 9]) << 0x8 | uint(c2da_mem[l_2 + 10]) << 0x10 | uint(c2da_mem[l_2 + 11]) << 0x18)
    let c2da_fresh40 : uint = uint(l_2)
    c2da_mem[c2da_fresh39] = uint8(c2da_fresh40)
    c2da_mem[c2da_fresh39 + 1] = uint8(c2da_fresh40 >> 0x8)
    c2da_mem[c2da_fresh39 + 2] = uint8(c2da_fresh40 >> 0x10)
    c2da_mem[c2da_fresh39 + 3] = uint8(c2da_fresh40 >> 0x18)
    c2da_mem[c2da_fresh39 + 4] = 0u8
    c2da_mem[c2da_fresh39 + 5] = 0u8
    c2da_mem[c2da_fresh39 + 6] = 0u8
    c2da_mem[c2da_fresh39 + 7] = 0u8
    return
}
var bigendien : uint = default<uint>

var BigShort : int = default<int>

var LittleShort : int = default<int>

var BigLong : int = default<int>

var LittleLong : int = default<int>

var BigFloat : int = default<int>

var LittleFloat : int = default<int>

[export, sideeffects]
def MSG_WriteChar(var sb : int; var c : int) {
    var buf_5 : int = SZ_GetSpace(sb, 1)
    let c2da_fresh41 : uint8 = uint8(c)
    c2da_mem[buf_5 + 0] = c2da_fresh41
    return
}
[export, sideeffects]
def MSG_WriteByte(var sb_0 : int; var c_0 : int) {
    var buf_6 : int = SZ_GetSpace(sb_0, 1)
    let c2da_fresh42 : uint8 = uint8(c_0)
    c2da_mem[buf_6 + 0] = c2da_fresh42
    return
}
[export, sideeffects]
def MSG_WriteShort(var sb_1 : int; var c_1 : int) {
    var buf_7 : int = SZ_GetSpace(sb_1, 2)
    let c2da_fresh43 : uint8 = uint8(c_1 & 255)
    c2da_mem[buf_7 + 0] = c2da_fresh43
    let c2da_fresh44 : uint8 = uint8(c_1 >> 8)
    c2da_mem[buf_7 + 1] = c2da_fresh44
    return
}
[export, sideeffects]
def MSG_WriteLong(var sb_2 : int; var c_2 : int) {
    var buf_8 : int = SZ_GetSpace(sb_2, 4)
    let c2da_fresh45 : uint8 = uint8(c_2 & 255)
    c2da_mem[buf_8 + 0] = c2da_fresh45
    let c2da_fresh46 : uint8 = uint8(c_2 >> 8 & 255)
    c2da_mem[buf_8 + 1] = c2da_fresh46
    let c2da_fresh47 : uint8 = uint8(c_2 >> 16 & 255)
    c2da_mem[buf_8 + 2] = c2da_fresh47
    let c2da_fresh48 : uint8 = uint8(c_2 >> 24)
    c2da_mem[buf_8 + 3] = c2da_fresh48
    return
}
[export, sideeffects]
def MSG_WriteFloat(var sb_3 : int; var f : float) {
    let c2da_saved_sp : int = c2da_lin_sp
    MSG_WriteFloat_c2da_frame(sb_3, f, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def MSG_WriteString(var sb_4 : int; var s : int) {
    if (s == 0) {
        SZ_Write(sb_4, 704745, 1)
    } else {
        SZ_Write(sb_4, s, Q_strlen(s) + 1)
    }
    return
}
[export, sideeffects]
def MSG_WriteCoord(var sb_5 : int; var f_0 : float) {
    MSG_WriteShort(sb_5, int(f_0 * 8.0))
    return
}
[export, sideeffects]
def MSG_WriteAngle(var sb_6 : int; var f_1 : float) {
    MSG_WriteByte(sb_6, int(f_1) * 256 / 360 & 255)
    return
}
var msg_readcount : int = default<int>

var msg_badread : uint = default<uint>

[export, sideeffects]
def MSG_BeginReading() {
    msg_readcount = 0
    msg_badread = 0u
    return
}
[export, sideeffects]
def MSG_ReadChar() : int {
    var c_3 : int
    if (msg_readcount + 1 > int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18)) {
        msg_badread = 1u
        return -1
    }
    let c2da_fresh52 : int = int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18) + msg_readcount
    c_3 = int(int8(c2da_mem[c2da_fresh52]))
    msg_readcount++
    return c_3
}
[export, sideeffects]
def MSG_ReadByte() : int {
    var c_4 : int
    if (msg_readcount + 1 > int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18)) {
        msg_badread = 1u
        return -1
    }
    let c2da_fresh53 : int = int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18) + msg_readcount
    c_4 = int(c2da_mem[c2da_fresh53])
    msg_readcount++
    return c_4
}
[export, sideeffects]
def MSG_ReadShort() : int {
    var c_5 : int
    if (msg_readcount + 2 > int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18)) {
        msg_badread = 1u
        return -1
    }
    let c2da_fresh56 : int = int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18)
    let c2da_fresh54 : int = c2da_fresh56 + msg_readcount
    let c2da_fresh55 : int = c2da_fresh56 + (msg_readcount + 1)
    c_5 = int(int16(int(c2da_mem[c2da_fresh54]) + (int(c2da_mem[c2da_fresh55]) << 8)))
    msg_readcount += 2
    return c_5
}
[export, sideeffects]
def MSG_ReadLong() : int {
    var c_6 : int
    if (msg_readcount + 4 > int(uint(c2da_mem[5380]) | uint(c2da_mem[5381]) << 0x8 | uint(c2da_mem[5382]) << 0x10 | uint(c2da_mem[5383]) << 0x18)) {
        msg_badread = 1u
        return -1
    }
    let c2da_fresh61 : int = int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18)
    let c2da_fresh57 : int = c2da_fresh61 + msg_readcount
    let c2da_fresh58 : int = c2da_fresh61 + (msg_readcount + 1)
    let c2da_fresh59 : int = c2da_fresh61 + (msg_readcount + 2)
    let c2da_fresh60 : int = c2da_fresh61 + (msg_readcount + 3)
    c_6 = int(c2da_mem[c2da_fresh57]) + (int(c2da_mem[c2da_fresh58]) << 8) + (int(c2da_mem[c2da_fresh59]) << 16) + (int(c2da_mem[c2da_fresh60]) << 24)
    msg_readcount += 4
    return c_6
}
[export, sideeffects]
def MSG_ReadFloat() : float {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : float = MSG_ReadFloat_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def MSG_ReadString() : int {
    var l_3 : int
    var c_7 : int
    l_3 = 0
    while (true) {
        c_7 = MSG_ReadChar()
        if (c_7 == -1 || c_7 == 0) {
            break
        }
        let c2da_fresh72 : int8 = int8(c_7)
        c2da_mem[701056 + l_3] = uint8(c2da_fresh72)
        l_3++
        if (uint64(l_3) >= 2048ul - 1ul) {
            break
        }
    }
    let c2da_fresh73 : int8 = int8(0)
    c2da_mem[701056 + l_3] = uint8(c2da_fresh73)
    return 701056
}
[export, sideeffects]
def MSG_ReadCoord() : float {
    return float(double(MSG_ReadShort()) * (1.0lf / 8.0lf))
}
[export, sideeffects]
def MSG_ReadAngle() : float {
    return float(double(MSG_ReadChar()) * (360.0lf / 256.0lf))
}
[export, sideeffects]
def Q_memset(var dest_0 : int; var fill : int; var count_1 : int) {
    var i_0 : int
    if (((int64(dest_0) | int64(count_1)) & 3l) == 0l) {
        count_1 >>= 2
        fill = fill | fill << 8 | fill << 16 | fill << 24
        i_0 = 0
        for (c2da_i_0_0 in range(i_0, count_1)) {
            let c2da_fresh74 : uint = uint(fill)
            c2da_mem[dest_0 + c2da_i_0_0 * 4] = uint8(c2da_fresh74)
            c2da_mem[dest_0 + c2da_i_0_0 * 4 + 1] = uint8(c2da_fresh74 >> 0x8)
            c2da_mem[dest_0 + c2da_i_0_0 * 4 + 2] = uint8(c2da_fresh74 >> 0x10)
            c2da_mem[dest_0 + c2da_i_0_0 * 4 + 3] = uint8(c2da_fresh74 >> 0x18)
        }
    } else {
        i_0 = 0
        for (c2da_i_0_1 in range(i_0, count_1)) {
            let c2da_fresh75 : uint8 = uint8(fill)
            c2da_mem[dest_0 + c2da_i_0_1] = c2da_fresh75
        }
    }
    return
}
[export, sideeffects]
def Q_memcmp(var m1 : int; var m2 : int; var count_2 : int) : int {
    while (count_2 != 0) {
        count_2--
        if (int(c2da_mem[m1 + count_2]) != int(c2da_mem[m2 + count_2])) {
            return -1
        }
    }
    return 0
}
[export, sideeffects]
def Q_strcpy(var dest_1 : int; var src_0 : int) {
    while (int8(c2da_mem[src_0]) != 0) {
        let c2da_fresh76 : int = dest_1
        dest_1++
        let c2da_fresh77 : int = src_0
        src_0++
        let c2da_fresh78 : int8 = int8(c2da_mem[c2da_fresh77])
        c2da_mem[c2da_fresh76] = uint8(c2da_fresh78)
    }
    let c2da_fresh79 : int = dest_1
    dest_1++
    let c2da_fresh80 : int8 = int8(0)
    c2da_mem[c2da_fresh79] = uint8(c2da_fresh80)
    return
}
[export, sideeffects]
def Q_strncpy(var dest_2 : int; var src_1 : int; var count_3 : int) {
    while (true) {
        var c2da_fresh81 : int = 0
        if (int(int8(c2da_mem[src_1])) != 0) {
            let c2da_postinc : int = count_3
            count_3--
            if (c2da_postinc != 0) {
                c2da_fresh81 = 1
            }
        }
        if (c2da_fresh81 == 0) {
            break
        }
        let c2da_fresh82 : int = dest_2
        dest_2++
        let c2da_fresh83 : int = src_1
        src_1++
        let c2da_fresh84 : int8 = int8(c2da_mem[c2da_fresh83])
        c2da_mem[c2da_fresh82] = uint8(c2da_fresh84)
    }
    if (count_3 != 0) {
        let c2da_fresh85 : int = dest_2
        dest_2++
        let c2da_fresh86 : int8 = int8(0)
        c2da_mem[c2da_fresh85] = uint8(c2da_fresh86)
    }
    return
}
[export, sideeffects]
def Q_strrchr(var s_0 : int; var c_8 : int8) : int {
    var len_0 : int = Q_strlen(s_0)
    s_0 += len_0
    while (true) {
        let c2da_postinc_0 : int = len_0
        len_0--
        if (c2da_postinc_0 == 0) {
            break
        }
        s_0--
        if (int(int8(c2da_mem[s_0])) == int(c_8)) {
            return s_0
        }
    }
    return 0
}
[export, sideeffects]
def Q_strcat(var dest_3 : int; var src_2 : int) {
    dest_3 = dest_3 + Q_strlen(dest_3)
    Q_strcpy(dest_3, src_2)
    return
}
[export, sideeffects]
def Q_strcmp(var s1 : int; var s2 : int) : int {
    while (true) {
        if (int(int8(c2da_mem[s1])) != int(int8(c2da_mem[s2]))) {
            return -1
        }
        if (int8(c2da_mem[s1]) == 0) {
            return 0
        }
        s1++
        s2++
    }
    panic("control reached the end of a non-void function")
    return 0
}
[export, sideeffects]
def Q_strncmp(var s1_0 : int; var s2_0 : int; var count_4 : int) : int {
    while (true) {
        let c2da_postinc_1 : int = count_4
        count_4--
        if (c2da_postinc_1 == 0) {
            return 0
        }
        if (int(int8(c2da_mem[s1_0])) != int(int8(c2da_mem[s2_0]))) {
            return -1
        }
        if (int8(c2da_mem[s1_0]) == 0) {
            return 0
        }
        s1_0++
        s2_0++
    }
    panic("control reached the end of a non-void function")
    return 0
}
[export, sideeffects]
def Q_strcasecmp(var s1_1 : int; var s2_1 : int) : int {
    return Q_strncasecmp(s1_1, s2_1, 99999)
}
[export, sideeffects]
def Q_strncasecmp(var s1_2 : int; var s2_2 : int; var n : int) : int {
    var c1 : int
    var c2 : int
    while (true) {
        let c2da_fresh87 : int = s1_2
        s1_2++
        c1 = int(int8(c2da_mem[c2da_fresh87]))
        let c2da_fresh88 : int = s2_2
        s2_2++
        c2 = int(int8(c2da_mem[c2da_fresh88]))
        let c2da_postinc_2 : int = n
        n--
        if (c2da_postinc_2 == 0) {
            return 0
        }
        if (c1 != c2) {
            if (c1 >= 97 && c1 <= 122) {
                c1 -= 97 - 65
            }
            if (c2 >= 97 && c2 <= 122) {
                c2 -= 97 - 65
            }
            if (c1 != c2) {
                return -1
            }
        }
        if (c1 == 0) {
            return 0
        }
    }
    panic("control reached the end of a non-void function")
    return 0
}
[export, sideeffects]
def Q_atoi(var str_0 : int) : int {
    var val : int
    var sign : int
    var c_9 : int
    if (int(int8(c2da_mem[str_0])) == 45) {
        sign = -1
        str_0++
    } else {
        sign = 1
    }
    val = 0
    if (int(int8(c2da_mem[str_0 + 0])) == 48 && (int(int8(c2da_mem[str_0 + 1])) == 120 || int(int8(c2da_mem[str_0 + 1])) == 88)) {
        str_0 += 2
        while (true) {
            let c2da_fresh89 : int = str_0
            str_0++
            c_9 = int(int8(c2da_mem[c2da_fresh89]))
            if (c_9 >= 48 && c_9 <= 57) {
                val = (val << 4) + c_9 - 48
            } elif (c_9 >= 97 && c_9 <= 102) {
                val = (val << 4) + c_9 - 97 + 10
            } elif (c_9 >= 65 && c_9 <= 70) {
                val = (val << 4) + c_9 - 65 + 10
            } else {
                return val * sign
            }
        }
    }
    if (int(int8(c2da_mem[str_0 + 0])) == 39) {
        return sign * int(int8(c2da_mem[str_0 + 1]))
    }
    while (true) {
        let c2da_fresh90 : int = str_0
        str_0++
        c_9 = int(int8(c2da_mem[c2da_fresh90]))
        if (c_9 < 48 || c_9 > 57) {
            return val * sign
        }
        val = val * 10 + c_9 - 48
    }
    panic("control reached the end of a non-void function")
    return 0
}
[export, sideeffects]
def Q_atof(var str_1 : int) : float {
    var val_0 : double
    var sign_0 : int
    var c_10 : int
    var decimal : int
    var total : int
    if (int(int8(c2da_mem[str_1])) == 45) {
        sign_0 = -1
        str_1++
    } else {
        sign_0 = 1
    }
    val_0 = 0.0lf
    if (int(int8(c2da_mem[str_1 + 0])) == 48 && (int(int8(c2da_mem[str_1 + 1])) == 120 || int(int8(c2da_mem[str_1 + 1])) == 88)) {
        str_1 += 2
        while (true) {
            let c2da_fresh91 : int = str_1
            str_1++
            c_10 = int(int8(c2da_mem[c2da_fresh91]))
            if (c_10 >= 48 && c_10 <= 57) {
                val_0 = val_0 * 16.0lf + double(c_10) - 48.0lf
            } elif (c_10 >= 97 && c_10 <= 102) {
                val_0 = val_0 * 16.0lf + double(c_10) - 97.0lf + 10.0lf
            } elif (c_10 >= 65 && c_10 <= 70) {
                val_0 = val_0 * 16.0lf + double(c_10) - 65.0lf + 10.0lf
            } else {
                return float(val_0 * double(sign_0))
            }
        }
    }
    if (int(int8(c2da_mem[str_1 + 0])) == 39) {
        return float(sign_0 * int(int8(c2da_mem[str_1 + 1])))
    }
    decimal = -1
    total = 0
    while (true) {
        let c2da_fresh92 : int = str_1
        str_1++
        c_10 = int(int8(c2da_mem[c2da_fresh92]))
        if (c_10 == 46) {
            decimal = total
            continue
        }
        if (c_10 < 48 || c_10 > 57) {
            break
        }
        val_0 = val_0 * 10.0lf + double(c_10) - 48.0lf
        total++
    }
    if (decimal == -1) {
        return float(val_0 * double(sign_0))
    }
    while (total > decimal) {
        val_0 /= 10.0lf
        total--
    }
    return float(val_0 * double(sign_0))
}
[export, sideeffects]
def COM_Parse(var data_2 : int) : int {
    var c_11 : int
    var len_1 : int = 0
    let c2da_fresh93 : int8 = int8(0)
    c2da_mem[194480 + 0] = uint8(c2da_fresh93)
    if (data_2 == 0) {
        goto label 16
    }
    label 0:
    label 1:
    c_11 = int(int8(c2da_mem[data_2]))
    if (c_11 <= 32) {
        goto label 14
    }
    if (c_11 == 47 && int(int8(c2da_mem[data_2 + 1])) == 47) {
        goto label 11
    }
    if (c_11 == 34) {
        goto label 7
    }
    label 2:
    if (c_11 == 123 || c_11 == 125 || c_11 == 41 || c_11 == 40 || c_11 == 39 || c_11 == 58) {
        goto label 6
    }
    label 3:
    let c2da_fresh99 : int8 = int8(c_11)
    c2da_mem[194480 + len_1] = uint8(c2da_fresh99)
    data_2++
    len_1++
    c_11 = int(int8(c2da_mem[data_2]))
    if (c_11 == 123 || c_11 == 125 || c_11 == 41 || c_11 == 40 || c_11 == 39 || c_11 == 58) {
        goto label 5
    }
    if (c_11 > 32) {
        goto label 3
    }
    label 4:
    let c2da_fresh100 : int8 = int8(0)
    c2da_mem[194480 + len_1] = uint8(c2da_fresh100)
    return data_2
    label 5:
    goto label 4
    label 6:
    let c2da_fresh97 : int8 = int8(c_11)
    c2da_mem[194480 + len_1] = uint8(c2da_fresh97)
    len_1++
    let c2da_fresh98 : int8 = int8(0)
    c2da_mem[194480 + len_1] = uint8(c2da_fresh98)
    return data_2 + 1
    label 7:
    data_2++
    label 8:
    goto label 9
    goto label 2
    label 9:
    let c2da_fresh94 : int = data_2
    data_2++
    c_11 = int(int8(c2da_mem[c2da_fresh94]))
    if (c_11 == 34 || c_11 == 0) {
        goto label 10
    }
    let c2da_fresh96 : int8 = int8(c_11)
    c2da_mem[194480 + len_1] = uint8(c2da_fresh96)
    len_1++
    goto label 8
    label 10:
    let c2da_fresh95 : int8 = int8(0)
    c2da_mem[194480 + len_1] = uint8(c2da_fresh95)
    return data_2
    label 11:
    label 12:
    if (int(int8(c2da_mem[data_2])) != 0 && int(int8(c2da_mem[data_2])) != 10) {
        goto label 13
    }
    goto label 0
    label 13:
    data_2++
    goto label 12
    label 14:
    if (c_11 == 0) {
        goto label 15
    }
    data_2++
    goto label 1
    label 15:
    return 0
    label 16:
    return 0
}
var com_argv : int = default<int>

[export, sideeffects]
def COM_CheckParm(var parm : int) : int {
    var i_1 : int = 1
    while (i_1 < int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18)) {
        if (int(uint(c2da_mem[com_argv + i_1 * 8]) | uint(c2da_mem[com_argv + i_1 * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + i_1 * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + i_1 * 8 + 3]) << 0x18) == 0) {
            i_1++
            continue
        }
        if (Q_strcmp(parm, int(uint(c2da_mem[com_argv + i_1 * 8]) | uint(c2da_mem[com_argv + i_1 * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + i_1 * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + i_1 * 8 + 3]) << 0x18)) == 0) {
            return i_1
        }
        i_1++
    }
    return 0
}
[export, sideeffects]
def COM_Init(var basedir : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    COM_Init_c2da_frame(basedir, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def COM_CheckRegistered() {
    let c2da_saved_sp : int = c2da_lin_sp
    COM_CheckRegistered_c2da_frame(c2da_lin_enter(272))
    c2da_lin_sp = c2da_saved_sp
}
var static_registered : int = 1

var pop : uint16[128] = fixed_array<uint16>(uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0x6600), uint16(0), uint16(0), uint16(0), uint16(0x6600), uint16(0), uint16(0), uint16(0x66), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0x67), uint16(0), uint16(0), uint16(0x6665), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0x65), uint16(0x6600), uint16(0x63), uint16(0x6561), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0x61), uint16(0x6563), uint16(0x64), uint16(0x6561), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0x61), uint16(0x6564), uint16(0x64), uint16(0x6564), uint16(0), uint16(0x6469), uint16(0x6969), uint16(0x6400), uint16(0x64), uint16(0x6564), uint16(0x63), uint16(0x6568), uint16(0x6200), uint16(0x64), uint16(0x6864), uint16(0), uint16(0x6268), uint16(0x6563), uint16(0), uint16(0x6567), uint16(0x6963), uint16(0x64), uint16(0x6764), uint16(0x63), uint16(0x6967), uint16(0x6500), uint16(0), uint16(0x6266), uint16(0x6769), uint16(0x6a68), uint16(0x6768), uint16(0x6a69), uint16(0x6766), uint16(0x6200), uint16(0), uint16(0x62), uint16(0x6566), uint16(0x6666), uint16(0x6666), uint16(0x6666), uint16(0x6562), uint16(0), uint16(0), uint16(0), uint16(0x62), uint16(0x6364), uint16(0x6664), uint16(0x6362), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0x62), uint16(0x6662), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0x61), uint16(0x6661), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0x6500), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0x6400), uint16(0), uint16(0), uint16(0))

[export, sideeffects]
def COM_CloseFile(var h : int) {
    var s_1 : int = com_searchpaths
    while (s_1 != 0) {
        var c2da_fresh102 : int = 0
        let c2da_fresh103 : int = int(uint(c2da_mem[s_1 + 128]) | uint(c2da_mem[s_1 + 129]) << 0x8 | uint(c2da_mem[s_1 + 130]) << 0x10 | uint(c2da_mem[s_1 + 131]) << 0x18)
        if (c2da_fresh103 != 0) {
            let c2da_fresh101 : int = c2da_fresh103 + 128
            if (int(uint(c2da_mem[c2da_fresh101]) | uint(c2da_mem[c2da_fresh101 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh101 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh101 + 3]) << 0x18) == h) {
                c2da_fresh102 = 1
            }
        }
        if (c2da_fresh102 != 0) {
            return
        }
        s_1 = int(uint(c2da_mem[s_1 + 136]) | uint(c2da_mem[s_1 + 137]) << 0x8 | uint(c2da_mem[s_1 + 138]) << 0x10 | uint(c2da_mem[s_1 + 139]) << 0x18)
    }
    Sys_FileClose(h)
    return
}
var com_searchpaths : int = default<int>

var com_modified : uint = default<uint>

[export, sideeffects]
def COM_OpenFile(var filename : int; var handle : int) : int {
    return COM_FindFile(filename, handle, 0)
}
[export, sideeffects]
def COM_FindFile(var filename_0 : int; var handle_0 : int; var file : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = COM_FindFile_c2da_frame(filename_0, handle_0, file, c2da_lin_enter(272))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
var com_filesize : int = default<int>

[export, sideeffects]
def COM_CopyFile(var netpath : int; var cachepath : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    COM_CopyFile_c2da_frame(netpath, cachepath, c2da_lin_enter(4112))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def COM_CreatePath(var path : int) {
    var ofs : int = path + 1
    while (int8(c2da_mem[ofs]) != 0) {
        if (int(int8(c2da_mem[ofs])) == 47) {
            let c2da_fresh125 : int8 = int8(0)
            c2da_mem[ofs] = uint8(c2da_fresh125)
            Sys_mkdir(path)
            let c2da_fresh126 : int8 = int8(47)
            c2da_mem[ofs] = uint8(c2da_fresh126)
        }
        ofs++
    }
    return
}
var proghack : uint = default<uint>

[export, sideeffects]
def COM_InitFilesystem() {
    let c2da_saved_sp : int = c2da_lin_sp
    COM_InitFilesystem_c2da_frame(c2da_lin_enter(128))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def COM_LoadPackFile(var packfile : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = COM_LoadPackFile_c2da_frame(packfile, c2da_lin_enter(131120))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def COM_FileExtension(var in_0 : int) : int {
    var i_5 : int
    while (int(int8(c2da_mem[in_0])) != 0 && int(int8(c2da_mem[in_0])) != 46) {
        in_0++
    }
    if (int8(c2da_mem[in_0]) == 0) {
        return 704745
    }
    in_0++
    i_5 = 0
    while (i_5 < 7 && int(int8(c2da_mem[in_0])) != 0) {
        let c2da_fresh152 : int8 = int8(c2da_mem[in_0])
        c2da_mem[703104 + i_5] = uint8(c2da_fresh152)
        i_5++
        in_0++
    }
    let c2da_fresh153 : int8 = int8(0)
    c2da_mem[703104 + i_5] = uint8(c2da_fresh153)
    return 703104
}
[export, sideeffects]
def va(var format : int; c2da_va_args : array<C2daVaArg>) : int {
    var argptr : C2daVaCursor = C2daVaCursor(index = 0)
    argptr.index = 0
    c2da_lin_vsnprintf(703120, 2147483647ul, format, argptr, c2da_va_args)
    argptr.index = -1
    return 703120
}
[export, sideeffects]
def COM_AddGameDirectory(var dir : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    COM_AddGameDirectory_c2da_frame(dir, c2da_lin_enter(128))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def COM_Path_f() {
    var s_2 : int
    Con_Printf(705270, [])
    s_2 = com_searchpaths
    while (s_2 != 0) {
        let c2da_fresh158 : int = int(uint(c2da_mem[s_2 + 128]) | uint(c2da_mem[s_2 + 129]) << 0x8 | uint(c2da_mem[s_2 + 130]) << 0x10 | uint(c2da_mem[s_2 + 131]) << 0x18)
        if (c2da_fresh158 != 0) {
            let c2da_fresh157 : int = c2da_fresh158 + 132
            Con_Printf(705292, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[s_2 + 128]) | uint(c2da_mem[s_2 + 129]) << 0x8 | uint(c2da_mem[s_2 + 130]) << 0x10 | uint(c2da_mem[s_2 + 131]) << 0x18))), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[c2da_fresh157]) | uint(c2da_mem[c2da_fresh157 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh157 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh157 + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
        } else {
            Con_Printf(705307, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(s_2))])
        }
        s_2 = int(uint(c2da_mem[s_2 + 136]) | uint(c2da_mem[s_2 + 137]) << 0x8 | uint(c2da_mem[s_2 + 138]) << 0x10 | uint(c2da_mem[s_2 + 139]) << 0x18)
    }
    return
}
[export, sideeffects]
def FloatSwap(var f_2 : float) : float {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : float = FloatSwap_c2da_frame(f_2, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def FloatNoSwap(var f_3 : float) : float {
    return f_3
}
[export, sideeffects]
def LongSwap(var l_4 : int) : int {
    return (int(uint8(l_4 & 255)) << 24) + (int(uint8(l_4 >> 8 & 255)) << 16) + (int(uint8(l_4 >> 16 & 255)) << 8) + int(uint8(l_4 >> 24 & 255))
}
[export, sideeffects]
def LongNoSwap(var l_5 : int) : int {
    return l_5
}
[export, sideeffects]
def ShortSwap(var l_6 : int16) : int16 {
    return int16((int(uint8(int(l_6) & 255)) << 8) + int(uint8(int(l_6) >> 8 & 255)))
}
[export, sideeffects]
def ShortNoSwap(var l_7 : int16) : int16 {
    return l_7
}
[export, sideeffects]
def COM_InitArgv(var argc : int; var argv : int) {
    var safe : uint
    var i_7 : int
    var j_0 : int
    var n_0 : int = 0
    j_0 = 0
    while (j_0 < 50 && j_0 < argc) {
        i_7 = 0
        while (true) {
            var c2da_fresh165 : int = 0
            if (n_0 < 256 - 1) {
                let c2da_fresh164 : int = int(uint(c2da_mem[argv + j_0 * 8]) | uint(c2da_mem[argv + j_0 * 8 + 1]) << 0x8 | uint(c2da_mem[argv + j_0 * 8 + 2]) << 0x10 | uint(c2da_mem[argv + j_0 * 8 + 3]) << 0x18) + i_7
                if (int(int8(c2da_mem[c2da_fresh164])) != 0) {
                    c2da_fresh165 = 1
                }
            }
            if (c2da_fresh165 == 0) {
                break
            }
            let c2da_postinc_3 : int = n_0
            n_0++
            let c2da_postinc_4 : int = i_7
            i_7++
            let c2da_fresh166 : int = int(uint(c2da_mem[argv + j_0 * 8]) | uint(c2da_mem[argv + j_0 * 8 + 1]) << 0x8 | uint(c2da_mem[argv + j_0 * 8 + 2]) << 0x10 | uint(c2da_mem[argv + j_0 * 8 + 3]) << 0x18) + c2da_postinc_4
            let c2da_fresh167 : int8 = int8(c2da_mem[c2da_fresh166])
            c2da_mem[195600 + c2da_postinc_3] = uint8(c2da_fresh167)
        }
        if (n_0 < 256 - 1) {
            let c2da_postinc_5 : int = n_0
            n_0++
            let c2da_fresh168 : int8 = int8(32)
            c2da_mem[195600 + c2da_postinc_5] = uint8(c2da_fresh168)
        } else {
            break
        }
        j_0++
    }
    let c2da_fresh169 : int8 = int8(0)
    c2da_mem[195600 + n_0] = uint8(c2da_fresh169)
    safe = 0u
    let c2da_fresh170 : int = 0
    let c2da_fresh171 : uint = uint(c2da_fresh170)
    c2da_mem[243888] = uint8(c2da_fresh171)
    c2da_mem[243889] = uint8(c2da_fresh171 >> 0x8)
    c2da_mem[243890] = uint8(c2da_fresh171 >> 0x10)
    c2da_mem[243891] = uint8(c2da_fresh171 >> 0x18)
    while (int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) < 50 && int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) < argc) {
        let c2da_fresh188 : int = int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18)
        let c2da_fresh172 : int = 704144 + c2da_fresh188 * 8
        let c2da_fresh173 : int = argv + c2da_fresh188 * 8
        let c2da_fresh174 : int = int(uint(c2da_mem[c2da_fresh173]) | uint(c2da_mem[c2da_fresh173 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh173 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh173 + 3]) << 0x18)
        let c2da_fresh175 : uint = uint(c2da_fresh174)
        c2da_mem[c2da_fresh172] = uint8(c2da_fresh175)
        c2da_mem[c2da_fresh172 + 1] = uint8(c2da_fresh175 >> 0x8)
        c2da_mem[c2da_fresh172 + 2] = uint8(c2da_fresh175 >> 0x10)
        c2da_mem[c2da_fresh172 + 3] = uint8(c2da_fresh175 >> 0x18)
        c2da_mem[c2da_fresh172 + 4] = 0u8
        c2da_mem[c2da_fresh172 + 5] = 0u8
        c2da_mem[c2da_fresh172 + 6] = 0u8
        c2da_mem[c2da_fresh172 + 7] = 0u8
        let c2da_fresh176 : int = argv + int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) * 8
        if (Q_strcmp(705311, int(uint(c2da_mem[c2da_fresh176]) | uint(c2da_mem[c2da_fresh176 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh176 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh176 + 3]) << 0x18)) == 0) {
            safe = 1u
        }
        let c2da_fresh177 : int = int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18)
        let c2da_fresh178 : int = c2da_fresh177 + 1
        let c2da_fresh179 : uint = uint(c2da_fresh178)
        c2da_mem[243888] = uint8(c2da_fresh179)
        c2da_mem[243889] = uint8(c2da_fresh179 >> 0x8)
        c2da_mem[243890] = uint8(c2da_fresh179 >> 0x10)
        c2da_mem[243891] = uint8(c2da_fresh179 >> 0x18)
    }
    if (safe != 0u) {
        i_7 = 0
        for (c2da_i_7 in range(i_7, 7)) {
            let c2da_fresh180 : int = 704144 + int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) * 8
            let c2da_fresh181 : int = safeargvs[c2da_i_7]
            let c2da_fresh182 : uint = uint(c2da_fresh181)
            c2da_mem[c2da_fresh180] = uint8(c2da_fresh182)
            c2da_mem[c2da_fresh180 + 1] = uint8(c2da_fresh182 >> 0x8)
            c2da_mem[c2da_fresh180 + 2] = uint8(c2da_fresh182 >> 0x10)
            c2da_mem[c2da_fresh180 + 3] = uint8(c2da_fresh182 >> 0x18)
            c2da_mem[c2da_fresh180 + 4] = 0u8
            c2da_mem[c2da_fresh180 + 5] = 0u8
            c2da_mem[c2da_fresh180 + 6] = 0u8
            c2da_mem[c2da_fresh180 + 7] = 0u8
            let c2da_fresh183 : int = int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18)
            let c2da_fresh184 : int = c2da_fresh183 + 1
            let c2da_fresh185 : uint = uint(c2da_fresh184)
            c2da_mem[243888] = uint8(c2da_fresh185)
            c2da_mem[243889] = uint8(c2da_fresh185 >> 0x8)
            c2da_mem[243890] = uint8(c2da_fresh185 >> 0x10)
            c2da_mem[243891] = uint8(c2da_fresh185 >> 0x18)
        }
    }
    let c2da_fresh186 : int = 704144 + int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) * 8
    let c2da_fresh187 : uint = uint(argvdummy)
    c2da_mem[c2da_fresh186] = uint8(c2da_fresh187)
    c2da_mem[c2da_fresh186 + 1] = uint8(c2da_fresh187 >> 0x8)
    c2da_mem[c2da_fresh186 + 2] = uint8(c2da_fresh187 >> 0x10)
    c2da_mem[c2da_fresh186 + 3] = uint8(c2da_fresh187 >> 0x18)
    c2da_mem[c2da_fresh186 + 4] = 0u8
    c2da_mem[c2da_fresh186 + 5] = 0u8
    c2da_mem[c2da_fresh186 + 6] = 0u8
    c2da_mem[c2da_fresh186 + 7] = 0u8
    com_argv = 704144
    if (COM_CheckParm(705090) != 0) {
        rogue = 1u
        standard_quake = 0u
    }
    if (COM_CheckParm(705106) != 0) {
        hipnotic = 1u
        standard_quake = 0u
    }
    return
}
var standard_quake : uint = 1u

var hipnotic : uint = default<uint>

var rogue : uint = default<uint>

var private argvdummy : int = 705317

var private safeargvs : int[7] = fixed_array<int>(705319, 705327, 705334, 705343, 705354, 705361, 705370)

[export, sideeffects]
def COM_SkipPath(var pathname : int) : int {
    var last : int = pathname
    while (int8(c2da_mem[pathname]) != 0) {
        if (int(int8(c2da_mem[pathname])) == 47) {
            last = pathname + 1
        }
        pathname++
    }
    return last
}
[export, sideeffects]
def COM_StripExtension(var in_1 : int; var out_0 : int) {
    while (int(int8(c2da_mem[in_1])) != 0 && int(int8(c2da_mem[in_1])) != 46) {
        let c2da_fresh189 : int = out_0
        out_0++
        let c2da_fresh190 : int = in_1
        in_1++
        let c2da_fresh191 : int8 = int8(c2da_mem[c2da_fresh190])
        c2da_mem[c2da_fresh189] = uint8(c2da_fresh191)
    }
    let c2da_fresh192 : int8 = int8(0)
    c2da_mem[out_0] = uint8(c2da_fresh192)
    return
}
[export, sideeffects]
def COM_FileBase(var in_2 : int; var out_1 : int; var outsize : uint64) {
    var dot : int
    var slash : int
    var s_3 : int
    var len_2 : uint64
    s_3 = in_2
    slash = in_2
    dot = 0
    while (int8(c2da_mem[s_3]) != 0) {
        if (int(int8(c2da_mem[s_3])) == 47) {
            slash = s_3 + 1
        }
        if (int(int8(c2da_mem[s_3])) == 46) {
            dot = s_3
        }
        s_3++
    }
    if (dot == 0) {
        dot = s_3
    }
    if (int64(dot - slash) < 2l) {
        c2da_lin_strncpy(out_1, 705379, outsize)
    } else {
        len_2 = uint64(dot - slash)
        if (len_2 >= outsize) {
            len_2 = outsize - 1ul
        }
        c2da_lin_memcpy(out_1, slash, len_2)
        let c2da_fresh193 : int8 = int8(0)
        c2da_mem[out_1 + int(len_2)] = uint8(c2da_fresh193)
    }
    return
}
[export, sideeffects]
def COM_DefaultExtension(var path_0 : int; var extension : int) {
    var src_3 : int = path_0 + int(c2da_lin_strlen(path_0)) - 1
    while (int(int8(c2da_mem[src_3])) != 47 && src_3 != path_0) {
        if (int(int8(c2da_mem[src_3])) == 46) {
            return
        }
        src_3--
    }
    c2da_lin_strcat(path_0, extension)
    return
}
[export, sideeffects]
def COM_WriteFile(var filename_1 : int; var data_3 : int; var len_3 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    COM_WriteFile_c2da_frame(filename_1, data_3, len_3, c2da_lin_enter(128))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def COM_FOpenFile(var filename_2 : int; var file_0 : int) : int {
    return COM_FindFile(filename_2, 0, file_0)
}
[export, sideeffects]
def COM_LoadStackFile(var path_1 : int; var buffer : int; var bufsize : int) : int {
    var buf_9 : int
    loadbuf = int(buffer)  // nolint:PERF020
    loadsize = int(bufsize)  // nolint:PERF020
    buf_9 = COM_LoadFile(path_1, 4)
    return buf_9
}
[export, sideeffects]
def COM_LoadFile(var path_2 : int; var usehunk : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = COM_LoadFile_c2da_frame(path_2, usehunk, c2da_lin_enter(48))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
var loadbuf : int = default<int>

var loadsize : int = default<int>

var loadcache : int = default<int>

[export, sideeffects]
def COM_LoadTempFile(var path_3 : int) : int {
    return COM_LoadFile(path_3, 2)
}
[export, sideeffects]
def COM_LoadHunkFile(var path_4 : int) : int {
    return COM_LoadFile(path_4, 1)
}
[export, sideeffects]
def COM_LoadCacheFile(var path_5 : int; var cu : int) {
    loadcache = int(cu)  // nolint:PERF020
    COM_LoadFile(path_5, 3)
    return
}
var msg_suppress_1 : uint = 0u

[export, sideeffects]
def memsearch(var start : int; var count_6 : int; var search_2 : int) : int {
    for (i_8 in range(0, count_6)) {
        if (int(c2da_mem[start + i_8]) == search_2) {
            return i_8
        }
    }
    return -1
}
[sideeffects]
def private MSG_WriteFloat_c2da_frame(var sb_3 : int; var f : float; c2da_fp : int) {
    let c2da_fresh49 : uint = float_bits_to_uint(f)
    c2da_mem[c2da_fp] = uint8(c2da_fresh49)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh49 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh49 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh49 >> 0x18)
    let c2da_fresh50 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18))
    let c2da_fresh51 : uint = uint(c2da_fresh50)
    c2da_mem[c2da_fp] = uint8(c2da_fresh51)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh51 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh51 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh51 >> 0x18)
    SZ_Write(sb_3, c2da_fp, 4)
    return
}
[sideeffects]
def private MSG_ReadFloat_c2da_frame(c2da_fp : int) : float {
    let c2da_fresh62 : int = int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18) + msg_readcount
    let c2da_fresh63 : uint8 = c2da_mem[c2da_fresh62]
    c2da_mem[c2da_fp + 0] = c2da_fresh63
    let c2da_fresh64 : int = int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18) + (msg_readcount + 1)
    let c2da_fresh65 : uint8 = c2da_mem[c2da_fresh64]
    c2da_mem[c2da_fp + 1] = c2da_fresh65
    let c2da_fresh66 : int = int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18) + (msg_readcount + 2)
    let c2da_fresh67 : uint8 = c2da_mem[c2da_fresh66]
    c2da_mem[c2da_fp + 2] = c2da_fresh67
    let c2da_fresh68 : int = int(uint(c2da_mem[5368]) | uint(c2da_mem[5369]) << 0x8 | uint(c2da_mem[5370]) << 0x10 | uint(c2da_mem[5371]) << 0x18) + (msg_readcount + 3)
    let c2da_fresh69 : uint8 = c2da_mem[c2da_fresh68]
    c2da_mem[c2da_fp + 3] = c2da_fresh69
    msg_readcount += 4
    let c2da_fresh70 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18))
    let c2da_fresh71 : uint = uint(c2da_fresh70)
    c2da_mem[c2da_fp] = uint8(c2da_fresh71)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh71 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh71 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh71 >> 0x18)
    return uint_bits_to_float(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18)
}
[sideeffects]
def private COM_Init_c2da_frame(var basedir : int; c2da_fp : int) {
    c2da_mem[c2da_fp] = 1u8
    c2da_mem[c2da_fp + 1] = 0u8
    if (int(int16(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8)) == 1) {
        bigendien = 0u
        BigShort = 48
        LittleShort = 49
        BigLong = 50
        LittleLong = 51
        BigFloat = 52
        LittleFloat = 53
    } else {
        bigendien = 1u
        BigShort = 49
        LittleShort = 48
        BigLong = 51
        LittleLong = 50
        BigFloat = 53
        LittleFloat = 52
    }
    Cvar_RegisterVariable(195504)
    Cvar_RegisterVariable(195552)
    Cmd_AddCommand(704746, 54)
    COM_InitFilesystem()
    COM_CheckRegistered()
    return
}
[sideeffects]
def private COM_CheckRegistered_c2da_frame(c2da_fp : int) {
    COM_OpenFile(704751, c2da_fp)
    static_registered = 0
    if (int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) == -1) {
        Con_Printf(704763, [])
        if (com_modified != 0u) {
            Sys_Error(704791, [])
        }
        return
    }
    Sys_FileRead(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18), c2da_fp + 16, 256)
    COM_CloseFile(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18))
    for (i_2 in range(0, 128)) {
        if (int(pop[i_2]) != int(uint16(invoke(c2da_fn_table3[BigShort], int16(uint16(uint(c2da_mem[c2da_fp + 16 + i_2 * 2]) | uint(c2da_mem[c2da_fp + 16 + i_2 * 2 + 1]) << 0x8)))))) {
            Sys_Error(704850, [])
        }
    }
    Cvar_Set(704621, 195600)
    Cvar_Set(704608, 704871)
    static_registered = 1
    Con_Printf(704873, [])
    return
}
[sideeffects]
def private COM_FindFile_c2da_frame(var filename_0 : int; var handle_0 : int; var file : int; c2da_fp : int) : int {
    var search : int
    var pak : int
    var findtime : int
    var cachetime : int
    if (file != 0 && handle_0 != 0) {
        Sys_Error(704902, [])
    }
    if (file == 0 && handle_0 == 0) {
        Sys_Error(704941, [])
    }
    search = com_searchpaths
    if (proghack != 0u) {
        if (c2da_lin_strcmp(filename_0, 704982) == 0) {
            search = int(uint(c2da_mem[search + 136]) | uint(c2da_mem[search + 137]) << 0x8 | uint(c2da_mem[search + 138]) << 0x10 | uint(c2da_mem[search + 139]) << 0x18)
        }
    }
    while (search != 0) {
        let c2da_fresh123 : int = int(uint(c2da_mem[search + 128]) | uint(c2da_mem[search + 129]) << 0x8 | uint(c2da_mem[search + 130]) << 0x10 | uint(c2da_mem[search + 131]) << 0x18)
        if (c2da_fresh123 != 0) {
            pak = c2da_fresh123
            let c2da_fresh104 : int = 0
            let c2da_fresh105 : uint = uint(c2da_fresh104)
            c2da_mem[c2da_fp + 256] = uint8(c2da_fresh105)
            c2da_mem[c2da_fp + 257] = uint8(c2da_fresh105 >> 0x8)
            c2da_mem[c2da_fp + 258] = uint8(c2da_fresh105 >> 0x10)
            c2da_mem[c2da_fp + 259] = uint8(c2da_fresh105 >> 0x18)
            while (int(uint(c2da_mem[c2da_fp + 256]) | uint(c2da_mem[c2da_fp + 257]) << 0x8 | uint(c2da_mem[c2da_fp + 258]) << 0x10 | uint(c2da_mem[c2da_fp + 259]) << 0x18) < int(uint(c2da_mem[pak + 132]) | uint(c2da_mem[pak + 133]) << 0x8 | uint(c2da_mem[pak + 134]) << 0x10 | uint(c2da_mem[pak + 135]) << 0x18)) {
                if (c2da_lin_strcmp(int(uint(c2da_mem[pak + 136]) | uint(c2da_mem[pak + 137]) << 0x8 | uint(c2da_mem[pak + 138]) << 0x10 | uint(c2da_mem[pak + 139]) << 0x18) + int(uint(c2da_mem[c2da_fp + 256]) | uint(c2da_mem[c2da_fp + 257]) << 0x8 | uint(c2da_mem[c2da_fp + 258]) << 0x10 | uint(c2da_mem[c2da_fp + 259]) << 0x18) * 72, filename_0) == 0) {
                    Sys_Printf(704992, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pak)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(filename_0))])
                    if (handle_0 != 0) {
                        let c2da_fresh106 : int = int(uint(c2da_mem[pak + 128]) | uint(c2da_mem[pak + 129]) << 0x8 | uint(c2da_mem[pak + 130]) << 0x10 | uint(c2da_mem[pak + 131]) << 0x18)
                        let c2da_fresh107 : uint = uint(c2da_fresh106)
                        c2da_mem[handle_0] = uint8(c2da_fresh107)
                        c2da_mem[handle_0 + 1] = uint8(c2da_fresh107 >> 0x8)
                        c2da_mem[handle_0 + 2] = uint8(c2da_fresh107 >> 0x10)
                        c2da_mem[handle_0 + 3] = uint8(c2da_fresh107 >> 0x18)
                        let c2da_fresh108 : int = int(uint(c2da_mem[pak + 136]) | uint(c2da_mem[pak + 137]) << 0x8 | uint(c2da_mem[pak + 138]) << 0x10 | uint(c2da_mem[pak + 139]) << 0x18) + int(uint(c2da_mem[c2da_fp + 256]) | uint(c2da_mem[c2da_fp + 257]) << 0x8 | uint(c2da_mem[c2da_fp + 258]) << 0x10 | uint(c2da_mem[c2da_fp + 259]) << 0x18) * 72 + 64
                        Sys_FileSeek(int(uint(c2da_mem[pak + 128]) | uint(c2da_mem[pak + 129]) << 0x8 | uint(c2da_mem[pak + 130]) << 0x10 | uint(c2da_mem[pak + 131]) << 0x18), int(uint(c2da_mem[c2da_fresh108]) | uint(c2da_mem[c2da_fresh108 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh108 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh108 + 3]) << 0x18))
                    } else {
                        let c2da_fresh109 : int = c2da_lin_fopen(pak, 705011)
                        let c2da_fresh110 : uint = uint(c2da_fresh109)
                        c2da_mem[file] = uint8(c2da_fresh110)
                        c2da_mem[file + 1] = uint8(c2da_fresh110 >> 0x8)
                        c2da_mem[file + 2] = uint8(c2da_fresh110 >> 0x10)
                        c2da_mem[file + 3] = uint8(c2da_fresh110 >> 0x18)
                        c2da_mem[file + 4] = 0u8
                        c2da_mem[file + 5] = 0u8
                        c2da_mem[file + 6] = 0u8
                        c2da_mem[file + 7] = 0u8
                        let c2da_fresh124 : int = int(uint(c2da_mem[file]) | uint(c2da_mem[file + 1]) << 0x8 | uint(c2da_mem[file + 2]) << 0x10 | uint(c2da_mem[file + 3]) << 0x18)
                        if (c2da_fresh124 != 0) {
                            let c2da_fresh111 : int = int(uint(c2da_mem[pak + 136]) | uint(c2da_mem[pak + 137]) << 0x8 | uint(c2da_mem[pak + 138]) << 0x10 | uint(c2da_mem[pak + 139]) << 0x18) + int(uint(c2da_mem[c2da_fp + 256]) | uint(c2da_mem[c2da_fp + 257]) << 0x8 | uint(c2da_mem[c2da_fp + 258]) << 0x10 | uint(c2da_mem[c2da_fp + 259]) << 0x18) * 72 + 64
                            c2da_std_fseek(uint64(int(uint(c2da_mem[file]) | uint(c2da_mem[file + 1]) << 0x8 | uint(c2da_mem[file + 2]) << 0x10 | uint(c2da_mem[file + 3]) << 0x18)), int64(int(uint(c2da_mem[c2da_fresh111]) | uint(c2da_mem[c2da_fresh111 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh111 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh111 + 3]) << 0x18)), 0)
                        }
                    }
                    let c2da_fresh112 : int = int(uint(c2da_mem[pak + 136]) | uint(c2da_mem[pak + 137]) << 0x8 | uint(c2da_mem[pak + 138]) << 0x10 | uint(c2da_mem[pak + 139]) << 0x18) + int(uint(c2da_mem[c2da_fp + 256]) | uint(c2da_mem[c2da_fp + 257]) << 0x8 | uint(c2da_mem[c2da_fp + 258]) << 0x10 | uint(c2da_mem[c2da_fp + 259]) << 0x18) * 72 + 68
                    com_filesize = int(uint(c2da_mem[c2da_fresh112]) | uint(c2da_mem[c2da_fresh112 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh112 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh112 + 3]) << 0x18)
                    return com_filesize
                }
                let c2da_fresh113 : int = int(uint(c2da_mem[c2da_fp + 256]) | uint(c2da_mem[c2da_fp + 257]) << 0x8 | uint(c2da_mem[c2da_fp + 258]) << 0x10 | uint(c2da_mem[c2da_fp + 259]) << 0x18)
                let c2da_fresh114 : int = c2da_fresh113 + 1
                let c2da_fresh115 : uint = uint(c2da_fresh114)
                c2da_mem[c2da_fp + 256] = uint8(c2da_fresh115)
                c2da_mem[c2da_fp + 257] = uint8(c2da_fresh115 >> 0x8)
                c2da_mem[c2da_fp + 258] = uint8(c2da_fresh115 >> 0x10)
                c2da_mem[c2da_fp + 259] = uint8(c2da_fresh115 >> 0x18)
            }
        } else {
            if (static_registered == 0) {
                if (c2da_lin_strchr(filename_0, 47) != 0 || c2da_lin_strchr(filename_0, 92) != 0) {
                    search = int(uint(c2da_mem[search + 136]) | uint(c2da_mem[search + 137]) << 0x8 | uint(c2da_mem[search + 138]) << 0x10 | uint(c2da_mem[search + 139]) << 0x18)
                    continue
                }
            }
            c2da_lin_snprintf(c2da_fp, 2147483647ul, 705014, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(search)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(filename_0))])
            findtime = Sys_FileTime(c2da_fp)
            if (findtime == -1) {
                search = int(uint(c2da_mem[search + 136]) | uint(c2da_mem[search + 137]) << 0x8 | uint(c2da_mem[search + 138]) << 0x10 | uint(c2da_mem[search + 139]) << 0x18)
                continue
            }
            if (int8(c2da_mem[195856 + 0]) == 0) {
                c2da_lin_strcpy(c2da_fp + 128, c2da_fp)
            } else {
                c2da_lin_snprintf(c2da_fp + 128, 2147483647ul, 705020, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 195856ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
                cachetime = Sys_FileTime(c2da_fp + 128)
                if (cachetime < findtime) {
                    COM_CopyFile(c2da_fp, c2da_fp + 128)
                }
                c2da_lin_strcpy(c2da_fp, c2da_fp + 128)
            }
            Sys_Printf(705025, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
            com_filesize = Sys_FileOpenRead(c2da_fp, c2da_fp + 256)
            if (handle_0 != 0) {
                let c2da_fresh116 : int = int(uint(c2da_mem[c2da_fp + 256]) | uint(c2da_mem[c2da_fp + 257]) << 0x8 | uint(c2da_mem[c2da_fp + 258]) << 0x10 | uint(c2da_mem[c2da_fp + 259]) << 0x18)
                let c2da_fresh117 : uint = uint(c2da_fresh116)
                c2da_mem[handle_0] = uint8(c2da_fresh117)
                c2da_mem[handle_0 + 1] = uint8(c2da_fresh117 >> 0x8)
                c2da_mem[handle_0 + 2] = uint8(c2da_fresh117 >> 0x10)
                c2da_mem[handle_0 + 3] = uint8(c2da_fresh117 >> 0x18)
            } else {
                Sys_FileClose(int(uint(c2da_mem[c2da_fp + 256]) | uint(c2da_mem[c2da_fp + 257]) << 0x8 | uint(c2da_mem[c2da_fp + 258]) << 0x10 | uint(c2da_mem[c2da_fp + 259]) << 0x18))
                let c2da_fresh118 : int = c2da_lin_fopen(c2da_fp, 705011)
                let c2da_fresh119 : uint = uint(c2da_fresh118)
                c2da_mem[file] = uint8(c2da_fresh119)
                c2da_mem[file + 1] = uint8(c2da_fresh119 >> 0x8)
                c2da_mem[file + 2] = uint8(c2da_fresh119 >> 0x10)
                c2da_mem[file + 3] = uint8(c2da_fresh119 >> 0x18)
                c2da_mem[file + 4] = 0u8
                c2da_mem[file + 5] = 0u8
                c2da_mem[file + 6] = 0u8
                c2da_mem[file + 7] = 0u8
            }
            return com_filesize
        }
        search = int(uint(c2da_mem[search + 136]) | uint(c2da_mem[search + 137]) << 0x8 | uint(c2da_mem[search + 138]) << 0x10 | uint(c2da_mem[search + 139]) << 0x18)
    }
    Sys_Printf(705039, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(filename_0))])
    if (handle_0 != 0) {
        let c2da_fresh120 : int = -1
        let c2da_fresh121 : uint = uint(c2da_fresh120)
        c2da_mem[handle_0] = uint8(c2da_fresh121)
        c2da_mem[handle_0 + 1] = uint8(c2da_fresh121 >> 0x8)
        c2da_mem[handle_0 + 2] = uint8(c2da_fresh121 >> 0x10)
        c2da_mem[handle_0 + 3] = uint8(c2da_fresh121 >> 0x18)
    } else {
        let c2da_fresh122 : uint = 0u
        c2da_mem[file] = uint8(c2da_fresh122)
        c2da_mem[file + 1] = uint8(c2da_fresh122 >> 0x8)
        c2da_mem[file + 2] = uint8(c2da_fresh122 >> 0x10)
        c2da_mem[file + 3] = uint8(c2da_fresh122 >> 0x18)
        c2da_mem[file + 4] = 0u8
        c2da_mem[file + 5] = 0u8
        c2da_mem[file + 6] = 0u8
        c2da_mem[file + 7] = 0u8
    }
    com_filesize = -1
    return -1
}
[sideeffects]
def private COM_CopyFile_c2da_frame(var netpath : int; var cachepath : int; c2da_fp : int) {
    var out : int
    var remaining : int
    var count_5 : int
    remaining = Sys_FileOpenRead(netpath, c2da_fp)
    COM_CreatePath(cachepath)
    out = Sys_FileOpenWrite(cachepath)
    while (remaining != 0) {
        if (uint64(remaining) < 4096ul) {
            count_5 = remaining
        } else {
            count_5 = 4096
        }
        Sys_FileRead(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18), c2da_fp + 16, count_5)
        Sys_FileWrite(out, c2da_fp + 16, count_5)
        remaining -= count_5
    }
    Sys_FileClose(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18))
    Sys_FileClose(out)
    return
}
[sideeffects]
def private COM_InitFilesystem_c2da_frame(c2da_fp : int) {
    var i_3 : int
    var j : int
    var search_0 : int
    i_3 = COM_CheckParm(705064)
    if (i_3 != 0 && i_3 < int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) - 1) {
        c2da_lin_strcpy(c2da_fp, int(uint(c2da_mem[com_argv + (i_3 + 1) * 8]) | uint(c2da_mem[com_argv + (i_3 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + (i_3 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + (i_3 + 1) * 8 + 3]) << 0x18))
    } else {
        c2da_lin_strcpy(c2da_fp, int(host_parms.basedir))
    }
    j = int(c2da_lin_strlen(c2da_fp))
    if (j > 0) {
        if (int(int8(c2da_mem[c2da_fp + (j - 1)])) == 92 || int(int8(c2da_mem[c2da_fp + (j - 1)])) == 47) {
            let c2da_fresh127 : int8 = int8(0)
            c2da_mem[c2da_fp + (j - 1)] = uint8(c2da_fresh127)
        }
    }
    i_3 = COM_CheckParm(705073)
    if (i_3 != 0 && i_3 < int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) - 1) {
        let c2da_fresh138 : int = int(uint(c2da_mem[com_argv + (i_3 + 1) * 8]) | uint(c2da_mem[com_argv + (i_3 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + (i_3 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + (i_3 + 1) * 8 + 3]) << 0x18)
        let c2da_fresh128 : int = c2da_fresh138 + 0
        if (int(int8(c2da_mem[c2da_fresh128])) == 45) {
            let c2da_fresh129 : int8 = int8(0)
            c2da_mem[195856 + 0] = uint8(c2da_fresh129)
        } else {
            c2da_lin_strcpy(195856, int(uint(c2da_mem[com_argv + (i_3 + 1) * 8]) | uint(c2da_mem[com_argv + (i_3 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + (i_3 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + (i_3 + 1) * 8 + 3]) << 0x18))
        }
    } elif (host_parms.cachedir != 0) {
        c2da_lin_strcpy(195856, int(host_parms.cachedir))
    } else {
        let c2da_fresh130 : int8 = int8(0)
        c2da_mem[195856 + 0] = uint8(c2da_fresh130)
    }
    COM_AddGameDirectory(va(705083, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))]))
    if (COM_CheckParm(705090) != 0) {
        COM_AddGameDirectory(va(705097, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))]))
    }
    if (COM_CheckParm(705106) != 0) {
        COM_AddGameDirectory(va(705116, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))]))
    }
    i_3 = COM_CheckParm(705128)
    if (i_3 != 0 && i_3 < int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18) - 1) {
        com_modified = 1u
        COM_AddGameDirectory(va(705014, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[com_argv + (i_3 + 1) * 8]) | uint(c2da_mem[com_argv + (i_3 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + (i_3 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + (i_3 + 1) * 8 + 3]) << 0x18)))]))
    }
    i_3 = COM_CheckParm(705134)
    if (i_3 != 0) {
        com_modified = 1u
        com_searchpaths = 0
        while (true) {
            i_3++
            if (i_3 >= int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18)) {
                break
            }
            var c2da_fresh132 : int = 1
            let c2da_fresh139 : int = int(uint(c2da_mem[com_argv + i_3 * 8]) | uint(c2da_mem[com_argv + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + i_3 * 8 + 3]) << 0x18)
            if (!(c2da_fresh139 == 0)) {
                let c2da_fresh131 : int = c2da_fresh139 + 0
                if (!(int(int8(c2da_mem[c2da_fresh131])) == 43)) {
                    c2da_fresh132 = 0
                }
            }
            var c2da_fresh134 : int = 1
            if (!(c2da_fresh132 != 0)) {
                let c2da_fresh133 : int = int(uint(c2da_mem[com_argv + i_3 * 8]) | uint(c2da_mem[com_argv + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + i_3 * 8 + 3]) << 0x18) + 0
                if (!(int(int8(c2da_mem[c2da_fresh133])) == 45)) {
                    c2da_fresh134 = 0
                }
            }
            if (c2da_fresh134 != 0) {
                break
            }
            search_0 = Hunk_Alloc(144)
            if (c2da_lin_strcmp(COM_FileExtension(int(uint(c2da_mem[com_argv + i_3 * 8]) | uint(c2da_mem[com_argv + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + i_3 * 8 + 3]) << 0x18)), 705140) == 0) {
                let c2da_fresh135 : int = COM_LoadPackFile(int(uint(c2da_mem[com_argv + i_3 * 8]) | uint(c2da_mem[com_argv + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + i_3 * 8 + 3]) << 0x18))
                let c2da_fresh136 : uint = uint(c2da_fresh135)
                c2da_mem[search_0 + 128] = uint8(c2da_fresh136)
                c2da_mem[search_0 + 129] = uint8(c2da_fresh136 >> 0x8)
                c2da_mem[search_0 + 130] = uint8(c2da_fresh136 >> 0x10)
                c2da_mem[search_0 + 131] = uint8(c2da_fresh136 >> 0x18)
                c2da_mem[search_0 + 132] = 0u8
                c2da_mem[search_0 + 133] = 0u8
                c2da_mem[search_0 + 134] = 0u8
                c2da_mem[search_0 + 135] = 0u8
                if (int(uint(c2da_mem[search_0 + 128]) | uint(c2da_mem[search_0 + 129]) << 0x8 | uint(c2da_mem[search_0 + 130]) << 0x10 | uint(c2da_mem[search_0 + 131]) << 0x18) == 0) {
                    Sys_Error(705144, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[com_argv + i_3 * 8]) | uint(c2da_mem[com_argv + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + i_3 * 8 + 3]) << 0x18)))])
                }
            } else {
                c2da_lin_strcpy(search_0, int(uint(c2da_mem[com_argv + i_3 * 8]) | uint(c2da_mem[com_argv + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + i_3 * 8 + 3]) << 0x18))
            }
            let c2da_fresh137 : uint = uint(com_searchpaths)
            c2da_mem[search_0 + 136] = uint8(c2da_fresh137)
            c2da_mem[search_0 + 137] = uint8(c2da_fresh137 >> 0x8)
            c2da_mem[search_0 + 138] = uint8(c2da_fresh137 >> 0x10)
            c2da_mem[search_0 + 139] = uint8(c2da_fresh137 >> 0x18)
            c2da_mem[search_0 + 140] = 0u8
            c2da_mem[search_0 + 141] = 0u8
            c2da_mem[search_0 + 142] = 0u8
            c2da_mem[search_0 + 143] = 0u8
            com_searchpaths = search_0
        }
    }
    if (COM_CheckParm(705171) != 0) {
        proghack = 1u
    }
    return
}
[sideeffects]
def private COM_LoadPackFile_c2da_frame(var packfile : int; c2da_fp : int) : int {
    var i_4 : int
    var newfiles : int
    var numpackfiles : int
    var pack : int
    if (Sys_FileOpenRead(packfile, c2da_fp) == -1) {
        return 0
    }
    Sys_FileRead(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18), c2da_fp + 16, 12)
    if (int(int8(c2da_mem[c2da_fp + 16 + 0])) != 80 || int(int8(c2da_mem[c2da_fp + 16 + 1])) != 65 || int(int8(c2da_mem[c2da_fp + 16 + 2])) != 67 || int(int8(c2da_mem[c2da_fp + 16 + 3])) != 75) {
        Sys_Error(705181, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(packfile))])
    }
    let c2da_fresh140 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[c2da_fp + 20]) | uint(c2da_mem[c2da_fp + 21]) << 0x8 | uint(c2da_mem[c2da_fp + 22]) << 0x10 | uint(c2da_mem[c2da_fp + 23]) << 0x18))
    let c2da_fresh141 : uint = uint(c2da_fresh140)
    c2da_mem[c2da_fp + 20] = uint8(c2da_fresh141)
    c2da_mem[c2da_fp + 21] = uint8(c2da_fresh141 >> 0x8)
    c2da_mem[c2da_fp + 22] = uint8(c2da_fresh141 >> 0x10)
    c2da_mem[c2da_fp + 23] = uint8(c2da_fresh141 >> 0x18)
    let c2da_fresh142 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[c2da_fp + 24]) | uint(c2da_mem[c2da_fp + 25]) << 0x8 | uint(c2da_mem[c2da_fp + 26]) << 0x10 | uint(c2da_mem[c2da_fp + 27]) << 0x18))
    let c2da_fresh143 : uint = uint(c2da_fresh142)
    c2da_mem[c2da_fp + 24] = uint8(c2da_fresh143)
    c2da_mem[c2da_fp + 25] = uint8(c2da_fresh143 >> 0x8)
    c2da_mem[c2da_fp + 26] = uint8(c2da_fresh143 >> 0x10)
    c2da_mem[c2da_fp + 27] = uint8(c2da_fresh143 >> 0x18)
    numpackfiles = int(uint64(int(uint(c2da_mem[c2da_fp + 24]) | uint(c2da_mem[c2da_fp + 25]) << 0x8 | uint(c2da_mem[c2da_fp + 26]) << 0x10 | uint(c2da_mem[c2da_fp + 27]) << 0x18)) / 64ul)
    if (numpackfiles > 2048) {
        Sys_Error(705202, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(packfile)), C2daVaArg(tag = 1, i64 = int64(numpackfiles), f64 = 0.0lf, raw = 0x0)])
    }
    if (numpackfiles != 339) {
        com_modified = 1u
    }
    newfiles = Hunk_AllocName(int(uint64(numpackfiles) * 72ul), 705218)
    Sys_FileSeek(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18), int(uint(c2da_mem[c2da_fp + 20]) | uint(c2da_mem[c2da_fp + 21]) << 0x8 | uint(c2da_mem[c2da_fp + 22]) << 0x10 | uint(c2da_mem[c2da_fp + 23]) << 0x18))
    Sys_FileRead(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18), c2da_fp + 32, int(uint(c2da_mem[c2da_fp + 24]) | uint(c2da_mem[c2da_fp + 25]) << 0x8 | uint(c2da_mem[c2da_fp + 26]) << 0x10 | uint(c2da_mem[c2da_fp + 27]) << 0x18))
    CRC_Init(c2da_fp + 131104)
    i_4 = 0
    while (i_4 < int(uint(c2da_mem[c2da_fp + 24]) | uint(c2da_mem[c2da_fp + 25]) << 0x8 | uint(c2da_mem[c2da_fp + 26]) << 0x10 | uint(c2da_mem[c2da_fp + 27]) << 0x18)) {
        CRC_ProcessByte(c2da_fp + 131104, c2da_mem[c2da_fp + 32 + i_4])
        i_4++
    }
    if (int(uint16(uint(c2da_mem[c2da_fp + 131104]) | uint(c2da_mem[c2da_fp + 131105]) << 0x8)) != 32981) {
        com_modified = 1u
    }
    i_4 = 0
    for (c2da_i_4 in range(i_4, numpackfiles)) {
        c2da_lin_strcpy(newfiles + c2da_i_4 * 72, c2da_fp + 32 + c2da_i_4 * 64)
        let c2da_fresh144 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[c2da_fp + 32 + c2da_i_4 * 64 + 56]) | uint(c2da_mem[c2da_fp + 32 + c2da_i_4 * 64 + 57]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + c2da_i_4 * 64 + 58]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + c2da_i_4 * 64 + 59]) << 0x18))
        let c2da_fresh145 : uint = uint(c2da_fresh144)
        c2da_mem[newfiles + c2da_i_4 * 72 + 64] = uint8(c2da_fresh145)
        c2da_mem[newfiles + c2da_i_4 * 72 + 65] = uint8(c2da_fresh145 >> 0x8)
        c2da_mem[newfiles + c2da_i_4 * 72 + 66] = uint8(c2da_fresh145 >> 0x10)
        c2da_mem[newfiles + c2da_i_4 * 72 + 67] = uint8(c2da_fresh145 >> 0x18)
        let c2da_fresh146 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[c2da_fp + 32 + c2da_i_4 * 64 + 60]) | uint(c2da_mem[c2da_fp + 32 + c2da_i_4 * 64 + 61]) << 0x8 | uint(c2da_mem[c2da_fp + 32 + c2da_i_4 * 64 + 62]) << 0x10 | uint(c2da_mem[c2da_fp + 32 + c2da_i_4 * 64 + 63]) << 0x18))
        let c2da_fresh147 : uint = uint(c2da_fresh146)
        c2da_mem[newfiles + c2da_i_4 * 72 + 68] = uint8(c2da_fresh147)
        c2da_mem[newfiles + c2da_i_4 * 72 + 69] = uint8(c2da_fresh147 >> 0x8)
        c2da_mem[newfiles + c2da_i_4 * 72 + 70] = uint8(c2da_fresh147 >> 0x10)
        c2da_mem[newfiles + c2da_i_4 * 72 + 71] = uint8(c2da_fresh147 >> 0x18)
    }
    pack = Hunk_Alloc(144)
    c2da_lin_strcpy(pack, packfile)
    let c2da_fresh148 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18)
    let c2da_fresh149 : uint = uint(c2da_fresh148)
    c2da_mem[pack + 128] = uint8(c2da_fresh149)
    c2da_mem[pack + 129] = uint8(c2da_fresh149 >> 0x8)
    c2da_mem[pack + 130] = uint8(c2da_fresh149 >> 0x10)
    c2da_mem[pack + 131] = uint8(c2da_fresh149 >> 0x18)
    let c2da_fresh150 : uint = uint(numpackfiles)
    c2da_mem[pack + 132] = uint8(c2da_fresh150)
    c2da_mem[pack + 133] = uint8(c2da_fresh150 >> 0x8)
    c2da_mem[pack + 134] = uint8(c2da_fresh150 >> 0x10)
    c2da_mem[pack + 135] = uint8(c2da_fresh150 >> 0x18)
    let c2da_fresh151 : uint = uint(newfiles)
    c2da_mem[pack + 136] = uint8(c2da_fresh151)
    c2da_mem[pack + 137] = uint8(c2da_fresh151 >> 0x8)
    c2da_mem[pack + 138] = uint8(c2da_fresh151 >> 0x10)
    c2da_mem[pack + 139] = uint8(c2da_fresh151 >> 0x18)
    c2da_mem[pack + 140] = 0u8
    c2da_mem[pack + 141] = 0u8
    c2da_mem[pack + 142] = 0u8
    c2da_mem[pack + 143] = 0u8
    Con_Printf(705227, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(packfile)), C2daVaArg(tag = 1, i64 = int64(numpackfiles), f64 = 0.0lf, raw = 0x0)])
    return pack
}
[sideeffects]
def private COM_AddGameDirectory_c2da_frame(var dir : int; c2da_fp : int) {
    var i_6 : int
    var search_1 : int
    var pak_0 : int
    c2da_lin_strcpy(5392, dir)
    search_1 = Hunk_Alloc(144)
    c2da_lin_strcpy(search_1, dir)
    let c2da_fresh154 : uint = uint(com_searchpaths)
    c2da_mem[search_1 + 136] = uint8(c2da_fresh154)
    c2da_mem[search_1 + 137] = uint8(c2da_fresh154 >> 0x8)
    c2da_mem[search_1 + 138] = uint8(c2da_fresh154 >> 0x10)
    c2da_mem[search_1 + 139] = uint8(c2da_fresh154 >> 0x18)
    c2da_mem[search_1 + 140] = 0u8
    c2da_mem[search_1 + 141] = 0u8
    c2da_mem[search_1 + 142] = 0u8
    c2da_mem[search_1 + 143] = 0u8
    com_searchpaths = search_1
    i_6 = 0
    while (true) {
        c2da_lin_snprintf(c2da_fp, 2147483647ul, 705257, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(dir)), C2daVaArg(tag = 1, i64 = int64(i_6), f64 = 0.0lf, raw = 0x0)])
        pak_0 = COM_LoadPackFile(c2da_fp)
        if (pak_0 == 0) {
            break
        }
        search_1 = Hunk_Alloc(144)
        let c2da_fresh155 : uint = uint(pak_0)
        c2da_mem[search_1 + 128] = uint8(c2da_fresh155)
        c2da_mem[search_1 + 129] = uint8(c2da_fresh155 >> 0x8)
        c2da_mem[search_1 + 130] = uint8(c2da_fresh155 >> 0x10)
        c2da_mem[search_1 + 131] = uint8(c2da_fresh155 >> 0x18)
        c2da_mem[search_1 + 132] = 0u8
        c2da_mem[search_1 + 133] = 0u8
        c2da_mem[search_1 + 134] = 0u8
        c2da_mem[search_1 + 135] = 0u8
        let c2da_fresh156 : uint = uint(com_searchpaths)
        c2da_mem[search_1 + 136] = uint8(c2da_fresh156)
        c2da_mem[search_1 + 137] = uint8(c2da_fresh156 >> 0x8)
        c2da_mem[search_1 + 138] = uint8(c2da_fresh156 >> 0x10)
        c2da_mem[search_1 + 139] = uint8(c2da_fresh156 >> 0x18)
        c2da_mem[search_1 + 140] = 0u8
        c2da_mem[search_1 + 141] = 0u8
        c2da_mem[search_1 + 142] = 0u8
        c2da_mem[search_1 + 143] = 0u8
        com_searchpaths = search_1
        i_6++
    }
    return
}
[sideeffects]
def private FloatSwap_c2da_frame(var f_2 : float; c2da_fp : int) : float {
    let c2da_fresh159 : uint = float_bits_to_uint(f_2)
    c2da_mem[c2da_fp] = uint8(c2da_fresh159)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh159 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh159 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh159 >> 0x18)
    let c2da_fresh160 : uint8 = c2da_mem[c2da_fp + 3]
    c2da_mem[c2da_fp + 16 + 0] = c2da_fresh160
    let c2da_fresh161 : uint8 = c2da_mem[c2da_fp + 2]
    c2da_mem[c2da_fp + 16 + 1] = c2da_fresh161
    let c2da_fresh162 : uint8 = c2da_mem[c2da_fp + 1]
    c2da_mem[c2da_fp + 16 + 2] = c2da_fresh162
    let c2da_fresh163 : uint8 = c2da_mem[c2da_fp + 0]
    c2da_mem[c2da_fp + 16 + 3] = c2da_fresh163
    return uint_bits_to_float(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18)
}
[sideeffects]
def private COM_WriteFile_c2da_frame(var filename_1 : int; var data_3 : int; var len_3 : int; c2da_fp : int) {
    var handle_1 : int
    c2da_lin_snprintf(c2da_fp, 2147483647ul, 705014, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 5392ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(filename_1))])
    handle_1 = Sys_FileOpenWrite(c2da_fp)
    if (handle_1 == -1) {
        Sys_Printf(705387, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
        return
    }
    Sys_Printf(705416, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    Sys_FileWrite(handle_1, data_3, len_3)
    Sys_FileClose(handle_1)
    return
}
[sideeffects]
def private COM_LoadFile_c2da_frame(var path_2 : int; var usehunk : int; c2da_fp : int) : int {
    var buf_10 : int
    var len_4 : int
    buf_10 = 0
    len_4 = COM_OpenFile(path_2, c2da_fp)
    if (int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) == -1) {
        return 0
    }
    COM_FileBase(path_2, c2da_fp + 16, 32ul)
    if (usehunk == 1) {
        buf_10 = Hunk_AllocName(len_4 + 1, c2da_fp + 16)
    } elif (usehunk == 2) {
        buf_10 = Hunk_TempAlloc(len_4 + 1)
    } elif (usehunk == 0) {
        buf_10 = Z_Malloc(len_4 + 1)
    } elif (usehunk == 3) {
        buf_10 = Cache_Alloc(loadcache, len_4 + 1, c2da_fp + 16)
    } elif (usehunk == 4) {
        if (len_4 + 1 > loadsize) {
            buf_10 = Hunk_TempAlloc(len_4 + 1)
        } else {
            buf_10 = loadbuf
        }
    } else {
        Sys_Error(705435, [])
    }
    if (buf_10 == 0) {
        Sys_Error(705461, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(path_2))])
    }
    let c2da_fresh194 : uint8 = 0u8
    c2da_mem[buf_10 + len_4] = c2da_fresh194
    Draw_BeginDisc()
    Sys_FileRead(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18), buf_10, len_4)
    COM_CloseFile(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18))
    Draw_EndDisc()
    return buf_10
}

// This unit's static data, at heap offset 701056.
let private c2da_lin_static_common_seg = fixed_array<int>(704608, 890)
let private c2da_lin_static_common = fixed_array<uint64>(0x7265747369676572ul, 0x646d630030006465ul, 0x7a697300656e696cul, 0x5f5a530066756265ul, 0x6563617053746547ul, 0x6c667265766f203aul, 0x6f6874697720776ful, 0x776f6c6c61207475ul, 0x776f6c667265766ful, 0x5f5a530074657320ul, 0x6563617053746547ul, 0x207369206925203aul, 0x62206c6c7566203eul, 0x6973207265666675ul, 0x65475f5a5300657aul, 0x203a656361705374ul, 0x776f6c667265766ful, 0x6700687461700000ul, 0x6c2e706f702f7866ul, 0x6979616c5000706dul, 0x657261687320676eul, 0x7265762065726177ul, 0x59000a2e6e6f6973ul, 0x207473756d20756ful, 0x6568742065766168ul, 0x6574736967657220ul, 0x7372657620646572ul, 0x75206f74206e6f69ul, 0x6669646f6d206573ul, 0x656d616720646569ul, 0x707572726f430073ul, 0x6174616420646574ul, 0x31002e656c696620ul, 0x676e6979616c5000ul, 0x6574736967657220ul, 0x7372657620646572ul, 0x4f43000a2e6e6f69ul, 0x6946646e69465f4dul, 0x68746f62203a656cul, 0x20656c646e616820ul, 0x656c696620646e61ul, 0x4d4f430074657320ul, 0x6c6946646e69465ful, 0x687469656e203a65ul, 0x6c646e6168207265ul, 0x6c696620726f2065ul, 0x7270007465732065ul, 0x7461642e73676ful, 0x656c69466b636150ul, 0x25203a207325203aul, 0x7325006272000a73ul, 0x732573250073252ful, 0x6c6946646e694600ul, 0x46000a7325203a65ul, 0x3a656c6946646e69ul, 0x662074276e616320ul, 0xa732520646e69ul, 0x726964657361622dul, 0x6465686361632d00ul, 0x64692f7325007269ul, 0x6575676f722d0031ul, 0x75676f722f732500ul, 0x6f6e7069682d0065ul, 0x682f732500636974ul, 0x6369746f6e7069ul, 0x702d00656d61672dul, 0x6b617000687461ul, 0x74276e646c756f43ul, 0x61702064616f6c20ul, 0x203a656c69666b63ul, 0x676f72702d007325ul, 0x207325006b636168ul, 0x6120746f6e207369ul, 0x6c69666b63617020ul, 0x7361682073250065ul, 0x656c696620692520ul, 0x69666b6361700073ul, 0x646564644100656cul, 0x6c69666b63617020ul, 0x6925282073252065ul, 0xa2973656c696620ul, 0x256b61702f732500ul, 0x7543006b61702e69ul, 0x657320746e657272ul, 0x7461702068637261ul, 0x28207325000a3a68ul, 0x73656c6966206925ul, 0x2d000a7325000a29ul, 0x2d00200065666173ul, 0x2d00646976647473ul, 0x6e2d006e616c6f6eul, 0x2d00646e756f736ful, 0x6964756164636f6eul, 0x796f6a6f6e2d006ful, 0x73756f6d6f6e2d00ul, 0x6e6f6269642d0065ul, 0x65646f6d3f00796cul, 0x575f4d4f43003f6cul, 0x656c694665746972ul, 0x64656c696166203aul, 0xa7325206e6f20ul, 0x746972575f4d4f43ul, 0x25203a656c694665ul, 0x4c5f4d4f43000a73ul, 0x3a656c694664616ful, 0x6573752064616220ul, 0x4d4f43006b6e7568ul, 0x6c694664616f4c5ful, 0x6520746f6e203a65ul, 0x7073206867756f6eul, 0x20726f6620656361ul, 0x7325ul)

[init]
def private c2da_lin_init_static_common() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_common_seg[s * 2]
        for (k in range(c2da_lin_static_common_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_common[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_common_0 = fixed_array<uint8>(0x60, 0xc0, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6b, 0xc0, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_common_1 = fixed_array<uint8>(0x6d, 0xc0, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6b, 0xc0, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_common() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[195504 + i] = c2da_lin_extern_common_0[i]
    }
    for (i in range(40)) {
        c2da_mem[195552 + i] = c2da_lin_extern_common_1[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_common() {
    if (length(c2da_fn_table0) < 55) {
        resize(c2da_fn_table0, 55)
    }
    c2da_fn_table0[54] = @@COM_Path_f
    if (length(c2da_fn_table1) < 55) {
        resize(c2da_fn_table1, 55)
    }
    c2da_fn_table1[52] = @@FloatSwap
    c2da_fn_table1[53] = @@FloatNoSwap
    if (length(c2da_fn_table2) < 55) {
        resize(c2da_fn_table2, 55)
    }
    c2da_fn_table2[50] = @@LongSwap
    c2da_fn_table2[51] = @@LongNoSwap
    if (length(c2da_fn_table3) < 55) {
        resize(c2da_fn_table3, 55)
    }
    c2da_fn_table3[48] = @@ShortSwap
    c2da_fn_table3[49] = @@ShortNoSwap
}

[init]
def private c2da_lin_relink_init_common() {
    c2da_relink_common()
}
