[export, sideeffects]
def Loop_Init() : int {
    if ((uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) == 0u) {
        return -1
    }
    return 0
}
[export, sideeffects]
def Loop_Listen(var state : uint) {
    return
}
[export, sideeffects]
def Loop_SearchForHosts(var xmit : uint) {
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u) {
        return
    }
    hostCacheCount = 1
    if (Q_strcmp(int(uint(c2da_mem[386472]) | uint(c2da_mem[386473]) << 0x8 | uint(c2da_mem[386474]) << 0x10 | uint(c2da_mem[386475]) << 0x18), 726928) == 0) {
        Q_strcpy(246672 + 0 * 96, 726936)
    } else {
        Q_strcpy(246672 + 0 * 96, int(uint(c2da_mem[386472]) | uint(c2da_mem[386473]) << 0x8 | uint(c2da_mem[386474]) << 0x10 | uint(c2da_mem[386475]) << 0x18))
    }
    Q_strcpy(246672 + 0 * 96 + 16, 225896)
    let c2da_fresh0 : uint = uint(net_activeconnections)
    c2da_mem[246672 + 0 * 96 + 64] = uint8(c2da_fresh0)
    c2da_mem[246672 + 0 * 96 + 65] = uint8(c2da_fresh0 >> 0x8)
    c2da_mem[246672 + 0 * 96 + 66] = uint8(c2da_fresh0 >> 0x10)
    c2da_mem[246672 + 0 * 96 + 67] = uint8(c2da_fresh0 >> 0x18)
    let c2da_fresh1 : int = svs.maxclients
    let c2da_fresh2 : uint = uint(c2da_fresh1)
    c2da_mem[246672 + 0 * 96 + 68] = uint8(c2da_fresh2)
    c2da_mem[246672 + 0 * 96 + 69] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[246672 + 0 * 96 + 70] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[246672 + 0 * 96 + 71] = uint8(c2da_fresh2 >> 0x18)
    let c2da_fresh3 : uint = uint(net_driverlevel)
    c2da_mem[246672 + 0 * 96 + 72] = uint8(c2da_fresh3)
    c2da_mem[246672 + 0 * 96 + 73] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[246672 + 0 * 96 + 74] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[246672 + 0 * 96 + 75] = uint8(c2da_fresh3 >> 0x18)
    Q_strcpy(246672 + 0 * 96 + 32, 726936)
    return
}
[export, sideeffects]
def Loop_Connect(var host : int) : int {
    if (Q_strcmp(host, 726936) != 0) {
        return 0
    }
    localconnectpending = 1u
    if (loop_client == 0) {
        loop_client = NET_NewQSocket()
        if (loop_client == 0) {
            Con_Printf(726942, [])
            return 0
        }
        Q_strcpy(loop_client + 16492, 726978)
    }
    let c2da_fresh4 : int = 0
    let c2da_fresh5 : uint = uint(c2da_fresh4)
    c2da_mem[loop_client + 8280] = uint8(c2da_fresh5)
    c2da_mem[loop_client + 8281] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[loop_client + 8282] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[loop_client + 8283] = uint8(c2da_fresh5 >> 0x18)
    let c2da_fresh6 : int = 0
    let c2da_fresh7 : uint = uint(c2da_fresh6)
    c2da_mem[loop_client + 76] = uint8(c2da_fresh7)
    c2da_mem[loop_client + 77] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[loop_client + 78] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[loop_client + 79] = uint8(c2da_fresh7 >> 0x18)
    let c2da_fresh8 : uint = 1u
    let c2da_fresh9 : uint = c2da_fresh8
    c2da_mem[loop_client + 36] = uint8(c2da_fresh9)
    c2da_mem[loop_client + 37] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[loop_client + 38] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[loop_client + 39] = uint8(c2da_fresh9 >> 0x18)
    if (loop_server == 0) {
        loop_server = NET_NewQSocket()
        if (loop_server == 0) {
            Con_Printf(726942, [])
            return 0
        }
        Q_strcpy(loop_server + 16492, 726988)
    }
    let c2da_fresh10 : int = 0
    let c2da_fresh11 : uint = uint(c2da_fresh10)
    c2da_mem[loop_server + 8280] = uint8(c2da_fresh11)
    c2da_mem[loop_server + 8281] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[loop_server + 8282] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[loop_server + 8283] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : int = 0
    let c2da_fresh13 : uint = uint(c2da_fresh12)
    c2da_mem[loop_server + 76] = uint8(c2da_fresh13)
    c2da_mem[loop_server + 77] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[loop_server + 78] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[loop_server + 79] = uint8(c2da_fresh13 >> 0x18)
    let c2da_fresh14 : uint = 1u
    let c2da_fresh15 : uint = c2da_fresh14
    c2da_mem[loop_server + 36] = uint8(c2da_fresh15)
    c2da_mem[loop_server + 37] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[loop_server + 38] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[loop_server + 39] = uint8(c2da_fresh15 >> 0x18)
    let c2da_fresh16 : uint = uint(loop_server)
    c2da_mem[loop_client + 56] = uint8(c2da_fresh16)
    c2da_mem[loop_client + 57] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[loop_client + 58] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[loop_client + 59] = uint8(c2da_fresh16 >> 0x18)
    c2da_mem[loop_client + 60] = 0u8
    c2da_mem[loop_client + 61] = 0u8
    c2da_mem[loop_client + 62] = 0u8
    c2da_mem[loop_client + 63] = 0u8
    let c2da_fresh17 : uint = uint(loop_client)
    c2da_mem[loop_server + 56] = uint8(c2da_fresh17)
    c2da_mem[loop_server + 57] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[loop_server + 58] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[loop_server + 59] = uint8(c2da_fresh17 >> 0x18)
    c2da_mem[loop_server + 60] = 0u8
    c2da_mem[loop_server + 61] = 0u8
    c2da_mem[loop_server + 62] = 0u8
    c2da_mem[loop_server + 63] = 0u8
    return loop_client
}
var loop_client : int = 0

var loop_server : int = 0

var localconnectpending : uint = 0u

[export, sideeffects]
def Loop_CheckNewConnections() : int {
    if (localconnectpending == 0u) {
        return 0
    }
    localconnectpending = 0u
    let c2da_fresh18 : int = 0
    let c2da_fresh19 : uint = uint(c2da_fresh18)
    c2da_mem[loop_server + 76] = uint8(c2da_fresh19)
    c2da_mem[loop_server + 77] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[loop_server + 78] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[loop_server + 79] = uint8(c2da_fresh19 >> 0x18)
    let c2da_fresh20 : int = 0
    let c2da_fresh21 : uint = uint(c2da_fresh20)
    c2da_mem[loop_server + 8280] = uint8(c2da_fresh21)
    c2da_mem[loop_server + 8281] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[loop_server + 8282] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[loop_server + 8283] = uint8(c2da_fresh21 >> 0x18)
    let c2da_fresh22 : uint = 1u
    let c2da_fresh23 : uint = c2da_fresh22
    c2da_mem[loop_server + 36] = uint8(c2da_fresh23)
    c2da_mem[loop_server + 37] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[loop_server + 38] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[loop_server + 39] = uint8(c2da_fresh23 >> 0x18)
    let c2da_fresh24 : int = 0
    let c2da_fresh25 : uint = uint(c2da_fresh24)
    c2da_mem[loop_client + 76] = uint8(c2da_fresh25)
    c2da_mem[loop_client + 77] = uint8(c2da_fresh25 >> 0x8)
    c2da_mem[loop_client + 78] = uint8(c2da_fresh25 >> 0x10)
    c2da_mem[loop_client + 79] = uint8(c2da_fresh25 >> 0x18)
    let c2da_fresh26 : int = 0
    let c2da_fresh27 : uint = uint(c2da_fresh26)
    c2da_mem[loop_client + 8280] = uint8(c2da_fresh27)
    c2da_mem[loop_client + 8281] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[loop_client + 8282] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[loop_client + 8283] = uint8(c2da_fresh27 >> 0x18)
    let c2da_fresh28 : uint = 1u
    let c2da_fresh29 : uint = c2da_fresh28
    c2da_mem[loop_client + 36] = uint8(c2da_fresh29)
    c2da_mem[loop_client + 37] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[loop_client + 38] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[loop_client + 39] = uint8(c2da_fresh29 >> 0x18)
    return loop_server
}
[export, sideeffects]
def Loop_GetMessage(var sock : int) : int {
    var ret : int
    var length_0 : int
    if (int(uint(c2da_mem[sock + 8280]) | uint(c2da_mem[sock + 8281]) << 0x8 | uint(c2da_mem[sock + 8282]) << 0x10 | uint(c2da_mem[sock + 8283]) << 0x18) == 0) {
        return 0
    }
    ret = int(c2da_mem[sock + 8284 + 0])
    length_0 = int(c2da_mem[sock + 8284 + 1]) + (int(c2da_mem[sock + 8284 + 2]) << 8)
    SZ_Clear(5360)
    SZ_Write(5360, sock + 8284 + 4, length_0)
    let c2da_fresh30 : int = length_0 + 4
    length_0 = int(uint64(c2da_fresh30) + (4ul - 1ul) & ~(4ul - 1ul))
    let c2da_fresh31 : int = int(uint(c2da_mem[sock + 8280]) | uint(c2da_mem[sock + 8281]) << 0x8 | uint(c2da_mem[sock + 8282]) << 0x10 | uint(c2da_mem[sock + 8283]) << 0x18) - length_0
    let c2da_fresh32 : uint = uint(c2da_fresh31)
    c2da_mem[sock + 8280] = uint8(c2da_fresh32)
    c2da_mem[sock + 8281] = uint8(c2da_fresh32 >> 0x8)
    c2da_mem[sock + 8282] = uint8(c2da_fresh32 >> 0x10)
    c2da_mem[sock + 8283] = uint8(c2da_fresh32 >> 0x18)
    if (int(uint(c2da_mem[sock + 8280]) | uint(c2da_mem[sock + 8281]) << 0x8 | uint(c2da_mem[sock + 8282]) << 0x10 | uint(c2da_mem[sock + 8283]) << 0x18) != 0) {
        Q_memcpy(sock + 8284, sock + 8284 + length_0, int(uint(c2da_mem[sock + 8280]) | uint(c2da_mem[sock + 8281]) << 0x8 | uint(c2da_mem[sock + 8282]) << 0x10 | uint(c2da_mem[sock + 8283]) << 0x18))
    }
    if (int(uint(c2da_mem[sock + 56]) | uint(c2da_mem[sock + 57]) << 0x8 | uint(c2da_mem[sock + 58]) << 0x10 | uint(c2da_mem[sock + 59]) << 0x18) != 0 && ret == 1) {
        let c2da_fresh33 : int = int(uint(c2da_mem[sock + 56]) | uint(c2da_mem[sock + 57]) << 0x8 | uint(c2da_mem[sock + 58]) << 0x10 | uint(c2da_mem[sock + 59]) << 0x18) + 36
        let c2da_fresh34 : uint = 1u
        let c2da_fresh35 : uint = c2da_fresh34
        c2da_mem[c2da_fresh33] = uint8(c2da_fresh35)
        c2da_mem[c2da_fresh33 + 1] = uint8(c2da_fresh35 >> 0x8)
        c2da_mem[c2da_fresh33 + 2] = uint8(c2da_fresh35 >> 0x10)
        c2da_mem[c2da_fresh33 + 3] = uint8(c2da_fresh35 >> 0x18)
    }
    return ret
}
[sideeffects]
def private IntAlign(var value : int) : int {
    return int(uint64(value) + (4ul - 1ul) & ~(4ul - 1ul))
}
[export, sideeffects]
def Loop_SendMessage(var sock_0 : int; var data : int) : int {
    var buffer : int
    var bufferLength : int
    if (int(uint(c2da_mem[sock_0 + 56]) | uint(c2da_mem[sock_0 + 57]) << 0x8 | uint(c2da_mem[sock_0 + 58]) << 0x10 | uint(c2da_mem[sock_0 + 59]) << 0x18) == 0) {
        return -1
    }
    bufferLength = int(uint(c2da_mem[sock_0 + 56]) | uint(c2da_mem[sock_0 + 57]) << 0x8 | uint(c2da_mem[sock_0 + 58]) << 0x10 | uint(c2da_mem[sock_0 + 59]) << 0x18) + 8280
    if (int(uint(c2da_mem[bufferLength]) | uint(c2da_mem[bufferLength + 1]) << 0x8 | uint(c2da_mem[bufferLength + 2]) << 0x10 | uint(c2da_mem[bufferLength + 3]) << 0x18) + int(uint(c2da_mem[data + 20]) | uint(c2da_mem[data + 21]) << 0x8 | uint(c2da_mem[data + 22]) << 0x10 | uint(c2da_mem[data + 23]) << 0x18) + 4 > 8192) {
        Sys_Error(726994, [])
    }
    buffer = int(uint(c2da_mem[sock_0 + 56]) | uint(c2da_mem[sock_0 + 57]) << 0x8 | uint(c2da_mem[sock_0 + 58]) << 0x10 | uint(c2da_mem[sock_0 + 59]) << 0x18) + 8284 + int(uint(c2da_mem[bufferLength]) | uint(c2da_mem[bufferLength + 1]) << 0x8 | uint(c2da_mem[bufferLength + 2]) << 0x10 | uint(c2da_mem[bufferLength + 3]) << 0x18)
    let c2da_fresh36 : int = buffer
    buffer++
    let c2da_fresh37 : uint8 = 1u8
    c2da_mem[c2da_fresh36] = c2da_fresh37
    let c2da_fresh38 : int = buffer
    buffer++
    let c2da_fresh39 : uint8 = uint8(int(uint(c2da_mem[data + 20]) | uint(c2da_mem[data + 21]) << 0x8 | uint(c2da_mem[data + 22]) << 0x10 | uint(c2da_mem[data + 23]) << 0x18) & 255)
    c2da_mem[c2da_fresh38] = c2da_fresh39
    let c2da_fresh40 : int = buffer
    buffer++
    let c2da_fresh41 : uint8 = uint8(int(uint(c2da_mem[data + 20]) | uint(c2da_mem[data + 21]) << 0x8 | uint(c2da_mem[data + 22]) << 0x10 | uint(c2da_mem[data + 23]) << 0x18) >> 8)
    c2da_mem[c2da_fresh40] = c2da_fresh41
    buffer++
    Q_memcpy(buffer, int(uint(c2da_mem[data + 8]) | uint(c2da_mem[data + 9]) << 0x8 | uint(c2da_mem[data + 10]) << 0x10 | uint(c2da_mem[data + 11]) << 0x18), int(uint(c2da_mem[data + 20]) | uint(c2da_mem[data + 21]) << 0x8 | uint(c2da_mem[data + 22]) << 0x10 | uint(c2da_mem[data + 23]) << 0x18))
    let c2da_fresh42 : int = int(uint(c2da_mem[bufferLength]) | uint(c2da_mem[bufferLength + 1]) << 0x8 | uint(c2da_mem[bufferLength + 2]) << 0x10 | uint(c2da_mem[bufferLength + 3]) << 0x18) + int(uint(c2da_mem[data + 20]) | uint(c2da_mem[data + 21]) << 0x8 | uint(c2da_mem[data + 22]) << 0x10 | uint(c2da_mem[data + 23]) << 0x18) + 4
    let c2da_fresh43 : int = int(uint64(c2da_fresh42) + (4ul - 1ul) & ~(4ul - 1ul))
    let c2da_fresh44 : uint = uint(c2da_fresh43)
    c2da_mem[bufferLength] = uint8(c2da_fresh44)
    c2da_mem[bufferLength + 1] = uint8(c2da_fresh44 >> 0x8)
    c2da_mem[bufferLength + 2] = uint8(c2da_fresh44 >> 0x10)
    c2da_mem[bufferLength + 3] = uint8(c2da_fresh44 >> 0x18)
    let c2da_fresh45 : uint = 0u
    let c2da_fresh46 : uint = c2da_fresh45
    c2da_mem[sock_0 + 36] = uint8(c2da_fresh46)
    c2da_mem[sock_0 + 37] = uint8(c2da_fresh46 >> 0x8)
    c2da_mem[sock_0 + 38] = uint8(c2da_fresh46 >> 0x10)
    c2da_mem[sock_0 + 39] = uint8(c2da_fresh46 >> 0x18)
    return 1
}
[export, sideeffects]
def Loop_SendUnreliableMessage(var sock_1 : int; var data_0 : int) : int {
    var buffer_0 : int
    var bufferLength_0 : int
    if (int(uint(c2da_mem[sock_1 + 56]) | uint(c2da_mem[sock_1 + 57]) << 0x8 | uint(c2da_mem[sock_1 + 58]) << 0x10 | uint(c2da_mem[sock_1 + 59]) << 0x18) == 0) {
        return -1
    }
    bufferLength_0 = int(uint(c2da_mem[sock_1 + 56]) | uint(c2da_mem[sock_1 + 57]) << 0x8 | uint(c2da_mem[sock_1 + 58]) << 0x10 | uint(c2da_mem[sock_1 + 59]) << 0x18) + 8280
    if (uint64(int(uint(c2da_mem[bufferLength_0]) | uint(c2da_mem[bufferLength_0 + 1]) << 0x8 | uint(c2da_mem[bufferLength_0 + 2]) << 0x10 | uint(c2da_mem[bufferLength_0 + 3]) << 0x18) + int(uint(c2da_mem[data_0 + 20]) | uint(c2da_mem[data_0 + 21]) << 0x8 | uint(c2da_mem[data_0 + 22]) << 0x10 | uint(c2da_mem[data_0 + 23]) << 0x18)) + 1ul + 2ul > 8192ul) {
        return 0
    }
    buffer_0 = int(uint(c2da_mem[sock_1 + 56]) | uint(c2da_mem[sock_1 + 57]) << 0x8 | uint(c2da_mem[sock_1 + 58]) << 0x10 | uint(c2da_mem[sock_1 + 59]) << 0x18) + 8284 + int(uint(c2da_mem[bufferLength_0]) | uint(c2da_mem[bufferLength_0 + 1]) << 0x8 | uint(c2da_mem[bufferLength_0 + 2]) << 0x10 | uint(c2da_mem[bufferLength_0 + 3]) << 0x18)
    let c2da_fresh47 : int = buffer_0
    buffer_0++
    let c2da_fresh48 : uint8 = 2u8
    c2da_mem[c2da_fresh47] = c2da_fresh48
    let c2da_fresh49 : int = buffer_0
    buffer_0++
    let c2da_fresh50 : uint8 = uint8(int(uint(c2da_mem[data_0 + 20]) | uint(c2da_mem[data_0 + 21]) << 0x8 | uint(c2da_mem[data_0 + 22]) << 0x10 | uint(c2da_mem[data_0 + 23]) << 0x18) & 255)
    c2da_mem[c2da_fresh49] = c2da_fresh50
    let c2da_fresh51 : int = buffer_0
    buffer_0++
    let c2da_fresh52 : uint8 = uint8(int(uint(c2da_mem[data_0 + 20]) | uint(c2da_mem[data_0 + 21]) << 0x8 | uint(c2da_mem[data_0 + 22]) << 0x10 | uint(c2da_mem[data_0 + 23]) << 0x18) >> 8)
    c2da_mem[c2da_fresh51] = c2da_fresh52
    buffer_0++
    Q_memcpy(buffer_0, int(uint(c2da_mem[data_0 + 8]) | uint(c2da_mem[data_0 + 9]) << 0x8 | uint(c2da_mem[data_0 + 10]) << 0x10 | uint(c2da_mem[data_0 + 11]) << 0x18), int(uint(c2da_mem[data_0 + 20]) | uint(c2da_mem[data_0 + 21]) << 0x8 | uint(c2da_mem[data_0 + 22]) << 0x10 | uint(c2da_mem[data_0 + 23]) << 0x18))
    let c2da_fresh53 : int = int(uint(c2da_mem[bufferLength_0]) | uint(c2da_mem[bufferLength_0 + 1]) << 0x8 | uint(c2da_mem[bufferLength_0 + 2]) << 0x10 | uint(c2da_mem[bufferLength_0 + 3]) << 0x18) + int(uint(c2da_mem[data_0 + 20]) | uint(c2da_mem[data_0 + 21]) << 0x8 | uint(c2da_mem[data_0 + 22]) << 0x10 | uint(c2da_mem[data_0 + 23]) << 0x18) + 4
    let c2da_fresh54 : int = int(uint64(c2da_fresh53) + (4ul - 1ul) & ~(4ul - 1ul))
    let c2da_fresh55 : uint = uint(c2da_fresh54)
    c2da_mem[bufferLength_0] = uint8(c2da_fresh55)
    c2da_mem[bufferLength_0 + 1] = uint8(c2da_fresh55 >> 0x8)
    c2da_mem[bufferLength_0 + 2] = uint8(c2da_fresh55 >> 0x10)
    c2da_mem[bufferLength_0 + 3] = uint8(c2da_fresh55 >> 0x18)
    return 1
}
[export, sideeffects]
def Loop_CanSendMessage(var sock_2 : int) : uint {
    if (int(uint(c2da_mem[sock_2 + 56]) | uint(c2da_mem[sock_2 + 57]) << 0x8 | uint(c2da_mem[sock_2 + 58]) << 0x10 | uint(c2da_mem[sock_2 + 59]) << 0x18) == 0) {
        return 0u
    }
    return uint(c2da_mem[sock_2 + 36]) | uint(c2da_mem[sock_2 + 37]) << 0x8 | uint(c2da_mem[sock_2 + 38]) << 0x10 | uint(c2da_mem[sock_2 + 39]) << 0x18
}
[export, sideeffects]
def Loop_CanSendUnreliableMessage(var sock_3 : int) : uint {
    return 1u
}
[export, sideeffects]
def Loop_Close(var sock_4 : int) {
    if (int(uint(c2da_mem[sock_4 + 56]) | uint(c2da_mem[sock_4 + 57]) << 0x8 | uint(c2da_mem[sock_4 + 58]) << 0x10 | uint(c2da_mem[sock_4 + 59]) << 0x18) != 0) {
        let c2da_fresh56 : int = int(uint(c2da_mem[sock_4 + 56]) | uint(c2da_mem[sock_4 + 57]) << 0x8 | uint(c2da_mem[sock_4 + 58]) << 0x10 | uint(c2da_mem[sock_4 + 59]) << 0x18) + 56
        let c2da_fresh57 : uint = 0u
        c2da_mem[c2da_fresh56] = uint8(c2da_fresh57)
        c2da_mem[c2da_fresh56 + 1] = uint8(c2da_fresh57 >> 0x8)
        c2da_mem[c2da_fresh56 + 2] = uint8(c2da_fresh57 >> 0x10)
        c2da_mem[c2da_fresh56 + 3] = uint8(c2da_fresh57 >> 0x18)
        c2da_mem[c2da_fresh56 + 4] = 0u8
        c2da_mem[c2da_fresh56 + 5] = 0u8
        c2da_mem[c2da_fresh56 + 6] = 0u8
        c2da_mem[c2da_fresh56 + 7] = 0u8
    }
    let c2da_fresh58 : int = 0
    let c2da_fresh59 : uint = uint(c2da_fresh58)
    c2da_mem[sock_4 + 8280] = uint8(c2da_fresh59)
    c2da_mem[sock_4 + 8281] = uint8(c2da_fresh59 >> 0x8)
    c2da_mem[sock_4 + 8282] = uint8(c2da_fresh59 >> 0x10)
    c2da_mem[sock_4 + 8283] = uint8(c2da_fresh59 >> 0x18)
    let c2da_fresh60 : int = 0
    let c2da_fresh61 : uint = uint(c2da_fresh60)
    c2da_mem[sock_4 + 76] = uint8(c2da_fresh61)
    c2da_mem[sock_4 + 77] = uint8(c2da_fresh61 >> 0x8)
    c2da_mem[sock_4 + 78] = uint8(c2da_fresh61 >> 0x10)
    c2da_mem[sock_4 + 79] = uint8(c2da_fresh61 >> 0x18)
    let c2da_fresh62 : uint = 1u
    let c2da_fresh63 : uint = c2da_fresh62
    c2da_mem[sock_4 + 36] = uint8(c2da_fresh63)
    c2da_mem[sock_4 + 37] = uint8(c2da_fresh63 >> 0x8)
    c2da_mem[sock_4 + 38] = uint8(c2da_fresh63 >> 0x10)
    c2da_mem[sock_4 + 39] = uint8(c2da_fresh63 >> 0x18)
    if (sock_4 == loop_client) {
        loop_client = 0
    } else {
        loop_server = 0
    }
    return
}
[export, sideeffects]
def Loop_Shutdown() {
    return
}

// This unit's static data, at heap offset 726928.
let private c2da_lin_static_net_loop_seg = fixed_array<int>(726928, 93)
let private c2da_lin_static_net_loop = fixed_array<uint64>(0x44454d414e4e55ul, 0x6f4c006c61636f6cul, 0x656e6e6f435f706ful, 0x71206f6e203a7463ul, 0x612074656b636f73ul, 0x656c62616c696176ul, 0x686c61636f6c000aul, 0x41434f4c0074736ful, 0x535f706f6f4c004cul, 0x617373654d646e65ul, 0x7265766f203a6567ul, 0xa776f6c66ul)

[init]
def private c2da_lin_init_static_net_loop() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_net_loop_seg[s * 2]
        for (k in range(c2da_lin_static_net_loop_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_net_loop[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_net_loop() {
    if (length(c2da_fn_table0) < 127) {
        resize(c2da_fn_table0, 127)
    }
    c2da_fn_table0[126] = @@Loop_Shutdown
    if (length(c2da_fn_table2) < 127) {
        resize(c2da_fn_table2, 127)
    }
    c2da_fn_table2[118] = @@Loop_Connect
    c2da_fn_table2[120] = @@Loop_GetMessage
    if (length(c2da_fn_table5) < 127) {
        resize(c2da_fn_table5, 127)
    }
    c2da_fn_table5[125] = @@Loop_Close
    if (length(c2da_fn_table8) < 127) {
        resize(c2da_fn_table8, 127)
    }
    c2da_fn_table8[115] = @@Loop_Init
    c2da_fn_table8[119] = @@Loop_CheckNewConnections
    if (length(c2da_fn_table9) < 127) {
        resize(c2da_fn_table9, 127)
    }
    c2da_fn_table9[116] = @@Loop_Listen
    c2da_fn_table9[117] = @@Loop_SearchForHosts
    if (length(c2da_fn_table10) < 127) {
        resize(c2da_fn_table10, 127)
    }
    c2da_fn_table10[121] = @@Loop_SendMessage
    c2da_fn_table10[122] = @@Loop_SendUnreliableMessage
    if (length(c2da_fn_table11) < 127) {
        resize(c2da_fn_table11, 127)
    }
    c2da_fn_table11[123] = @@Loop_CanSendMessage
    c2da_fn_table11[124] = @@Loop_CanSendUnreliableMessage
}

[init]
def private c2da_lin_relink_init_net_loop() {
    c2da_relink_net_loop()
}
