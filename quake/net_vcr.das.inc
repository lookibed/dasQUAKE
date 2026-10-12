var private c2da_str_net_vcr_0 : array<int8> = [int8(86), int8(67), int8(82), int8(32), int8(109), int8(105), int8(115), int8(115), int8(109), int8(97), int8(116), int8(99), int8(104), int8(0)]

var private c2da_str_net_vcr_1 : array<int8> = [int8(61), int8(61), int8(61), int8(32), int8(69), int8(78), int8(68), int8(32), int8(79), int8(70), int8(32), int8(80), int8(76), int8(65), int8(89), int8(66), int8(65), int8(67), int8(75), int8(61), int8(61), int8(61), int8(10), int8(0)]

var private c2da_str_net_vcr_2 : array<int8> = [int8(86), int8(67), int8(82), int8(95), int8(82), int8(101), int8(97), int8(100), int8(78), int8(101), int8(120), int8(116), int8(58), int8(32), int8(98), int8(97), int8(100), int8(32), int8(111), int8(112), int8(0)]

[export, sideeffects]
def VCR_Init() : int {
    net_drivers[0].Init = @@VCR_Init
    net_drivers[0].SearchForHosts = @@VCR_SearchForHosts
    net_drivers[0].Connect = @@VCR_Connect
    net_drivers[0].CheckNewConnections = @@VCR_CheckNewConnections
    net_drivers[0].QGetMessage = @@VCR_GetMessage
    net_drivers[0].QSendMessage = @@VCR_SendMessage
    net_drivers[0].CanSendMessage = @@VCR_CanSendMessage
    net_drivers[0].Close = @@VCR_Close
    net_drivers[0].Shutdown = @@VCR_Shutdown
    Sys_FileRead(vcrFile, unsafe(addr<uint8?>(next)), 24)
    return 0
}
var private next : Unnamed_net_vcr_32 = default<Unnamed_net_vcr_32>

[export, sideeffects]
def VCR_Shutdown() {
    return
}
[export, sideeffects]
def VCR_Close(var sock : qsocket_s?) {
    return
}
[export, sideeffects]
def VCR_CanSendMessage(var sock_0 : qsocket_s?) : qboolean {
    var ret : qboolean = qboolean()
    var c2da_fresh1 : int = 1
    if (!(host_time != next.time || next.op != 4)) {
        var c2da_fresh0 : uint8?? = unsafe(reinterpret<uint8??>(unsafe(reinterpret<uint64>(sock_0)) + 56ul))
        if (!(next.session != *unsafe(reinterpret<int64?>(c2da_fresh0)))) {
            c2da_fresh1 = 0
        }
    }
    if (c2da_fresh1 != 0) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_net_vcr_0[0])), [])
    }
    Sys_FileRead(vcrFile, unsafe(addr<uint8?>(ret)), 4)
    VCR_ReadNext()
    return ret
}
[export, sideeffects]
def VCR_ReadNext() {
    if (Sys_FileRead(vcrFile, unsafe(addr<uint8?>(next)), 24) == 0) {
        next.op = 255
        Sys_Error(unsafe(addr<int8?>(c2da_str_net_vcr_1[0])), [])
    }
    if (next.op < 1 || next.op > 4) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_net_vcr_2[0])), [])
    }
    return
}
[export, sideeffects]
def VCR_SendMessage(var sock_1 : qsocket_s?; var data : sizebuf_s?) : int {
    var ret_0 : int
    var c2da_fresh3 : int = 1
    if (!(host_time != next.time || next.op != 3)) {
        var c2da_fresh2 : uint8?? = unsafe(reinterpret<uint8??>(unsafe(reinterpret<uint64>(sock_1)) + 56ul))
        if (!(next.session != *unsafe(reinterpret<int64?>(c2da_fresh2)))) {
            c2da_fresh3 = 0
        }
    }
    if (c2da_fresh3 != 0) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_net_vcr_0[0])), [])
    }
    Sys_FileRead(vcrFile, unsafe(addr<uint8?>(ret_0)), 4)
    VCR_ReadNext()
    return ret_0
}
[export, sideeffects]
def VCR_GetMessage(var sock_2 : qsocket_s?) : int {
    var ret_1 : int
    var c2da_fresh5 : int = 1
    if (!(host_time != next.time || next.op != 2)) {
        var c2da_fresh4 : uint8?? = unsafe(reinterpret<uint8??>(unsafe(reinterpret<uint64>(sock_2)) + 56ul))
        if (!(next.session != *unsafe(reinterpret<int64?>(c2da_fresh4)))) {
            c2da_fresh5 = 0
        }
    }
    if (c2da_fresh5 != 0) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_net_vcr_0[0])), [])
    }
    Sys_FileRead(vcrFile, unsafe(addr<uint8?>(ret_1)), 4)
    if (ret_1 != 1) {
        VCR_ReadNext()
        return ret_1
    }
    Sys_FileRead(vcrFile, unsafe(addr<uint8?>(net_message.cursize)), 4)
    Sys_FileRead(vcrFile, unsafe(reinterpret<uint8?>(net_message.data)), net_message.cursize)
    VCR_ReadNext()
    return 1
}
[export, sideeffects]
def VCR_CheckNewConnections() : qsocket_s? {
    var sock_3 : qsocket_s?
    if (host_time != next.time || next.op != 1) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_net_vcr_0[0])), [])
    }
    if (next.session == 0) {
        VCR_ReadNext()
        return unsafe(reinterpret<qsocket_s?>(null))
    }
    sock_3 = unsafe(reinterpret<qsocket_s?>(unsafe(reinterpret<qsocket_s?>(NET_NewQSocket()))))
    var c2da_fresh6 : uint8?? = unsafe(reinterpret<uint8??>(unsafe(reinterpret<uint64>(sock_3)) + 56ul))
    *unsafe(reinterpret<int64?>(c2da_fresh6)) = int64(next.session)  // nolint:PERF020
    var c2da_fresh7 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(sock_3)) + 16492ul))
    Sys_FileRead(vcrFile, unsafe(reinterpret<uint8?>(c2da_fresh7)), 64)
    VCR_ReadNext()
    return unsafe(reinterpret<qsocket_s?>(sock_3))
}
[export, sideeffects]
def VCR_Connect(var host : int8?) : qsocket_s? {
    return unsafe(reinterpret<qsocket_s?>(null))
}
[export, sideeffects]
def VCR_SearchForHosts(var xmit : qboolean) {
    return
}
[export, sideeffects]
def VCR_Listen(var state : qboolean) {
    return
}
[sideeffects]
def private c2da_layout_proofs_28() {
    static_assert(typeinfo sizeof(type<sizebuf_s>) == 24, "C layout of sizebuf_s: sizeof")
    static_assert(typeinfo alignof(type<sizebuf_s>) == 8, "C layout of sizebuf_s: alignof")
    static_assert(typeinfo offsetof<allowoverflow>(type<sizebuf_s>) == 0, "C layout of sizebuf_s: offsetof allowoverflow")
    static_assert(typeinfo offsetof<overflowed>(type<sizebuf_s>) == 4, "C layout of sizebuf_s: offsetof overflowed")
    static_assert(typeinfo offsetof<data>(type<sizebuf_s>) == 8, "C layout of sizebuf_s: offsetof data")
    static_assert(typeinfo offsetof<maxsize>(type<sizebuf_s>) == 16, "C layout of sizebuf_s: offsetof maxsize")
    static_assert(typeinfo offsetof<cursize>(type<sizebuf_s>) == 20, "C layout of sizebuf_s: offsetof cursize")
    static_assert(typeinfo sizeof(type<sizebuf_t>) == 24, "C layout of sizebuf_t: sizeof")
    static_assert(typeinfo alignof(type<sizebuf_t>) == 8, "C layout of sizebuf_t: alignof")
    static_assert(typeinfo offsetof<allowoverflow>(type<sizebuf_t>) == 0, "C layout of sizebuf_t: offsetof allowoverflow")
    static_assert(typeinfo offsetof<overflowed>(type<sizebuf_t>) == 4, "C layout of sizebuf_t: offsetof overflowed")
    static_assert(typeinfo offsetof<data>(type<sizebuf_t>) == 8, "C layout of sizebuf_t: offsetof data")
    static_assert(typeinfo offsetof<maxsize>(type<sizebuf_t>) == 16, "C layout of sizebuf_t: offsetof maxsize")
    static_assert(typeinfo offsetof<cursize>(type<sizebuf_t>) == 20, "C layout of sizebuf_t: offsetof cursize")
    static_assert(typeinfo sizeof(type<qsockaddr>) == 16, "C layout of qsockaddr: sizeof")
    static_assert(typeinfo alignof(type<qsockaddr>) == 2, "C layout of qsockaddr: alignof")
    static_assert(typeinfo offsetof<sa_family>(type<qsockaddr>) == 0, "C layout of qsockaddr: offsetof sa_family")
    static_assert(typeinfo offsetof<sa_data>(type<qsockaddr>) == 2, "C layout of qsockaddr: offsetof sa_data")
    static_assert(typeinfo sizeof(type<qsocket_s>) == 16560, "C layout of qsocket_s: sizeof")
    static_assert(typeinfo alignof(type<qsocket_s>) == 8, "C layout of qsocket_s: alignof")
    static_assert(typeinfo offsetof<next>(type<qsocket_s>) == 0, "C layout of qsocket_s: offsetof next")
    static_assert(typeinfo offsetof<connecttime>(type<qsocket_s>) == 8, "C layout of qsocket_s: offsetof connecttime")
    static_assert(typeinfo offsetof<lastMessageTime>(type<qsocket_s>) == 16, "C layout of qsocket_s: offsetof lastMessageTime")
    static_assert(typeinfo offsetof<lastSendTime>(type<qsocket_s>) == 24, "C layout of qsocket_s: offsetof lastSendTime")
    static_assert(typeinfo offsetof<disconnected>(type<qsocket_s>) == 32, "C layout of qsocket_s: offsetof disconnected")
    static_assert(typeinfo offsetof<canSend>(type<qsocket_s>) == 36, "C layout of qsocket_s: offsetof canSend")
    static_assert(typeinfo offsetof<sendNext>(type<qsocket_s>) == 40, "C layout of qsocket_s: offsetof sendNext")
    static_assert(typeinfo offsetof<driver>(type<qsocket_s>) == 44, "C layout of qsocket_s: offsetof driver")
    static_assert(typeinfo offsetof<landriver>(type<qsocket_s>) == 48, "C layout of qsocket_s: offsetof landriver")
    static_assert(typeinfo offsetof<socket>(type<qsocket_s>) == 52, "C layout of qsocket_s: offsetof socket")
    static_assert(typeinfo offsetof<driverdata>(type<qsocket_s>) == 56, "C layout of qsocket_s: offsetof driverdata")
    static_assert(typeinfo offsetof<ackSequence>(type<qsocket_s>) == 64, "C layout of qsocket_s: offsetof ackSequence")
    static_assert(typeinfo offsetof<sendSequence>(type<qsocket_s>) == 68, "C layout of qsocket_s: offsetof sendSequence")
    static_assert(typeinfo offsetof<unreliableSendSequence>(type<qsocket_s>) == 72, "C layout of qsocket_s: offsetof unreliableSendSequence")
    static_assert(typeinfo offsetof<sendMessageLength>(type<qsocket_s>) == 76, "C layout of qsocket_s: offsetof sendMessageLength")
    static_assert(typeinfo offsetof<sendMessage>(type<qsocket_s>) == 80, "C layout of qsocket_s: offsetof sendMessage")
    static_assert(typeinfo offsetof<receiveSequence>(type<qsocket_s>) == 8272, "C layout of qsocket_s: offsetof receiveSequence")
    static_assert(typeinfo offsetof<unreliableReceiveSequence>(type<qsocket_s>) == 8276, "C layout of qsocket_s: offsetof unreliableReceiveSequence")
    static_assert(typeinfo offsetof<receiveMessageLength>(type<qsocket_s>) == 8280, "C layout of qsocket_s: offsetof receiveMessageLength")
    static_assert(typeinfo offsetof<receiveMessage>(type<qsocket_s>) == 8284, "C layout of qsocket_s: offsetof receiveMessage")
    static_assert(typeinfo offsetof<addr_0>(type<qsocket_s>) == 16476, "C layout of qsocket_s: offsetof addr_0")
    static_assert(typeinfo offsetof<address>(type<qsocket_s>) == 16492, "C layout of qsocket_s: offsetof address")
    static_assert(typeinfo sizeof(type<qsocket_t>) == 16560, "C layout of qsocket_t: sizeof")
    static_assert(typeinfo alignof(type<qsocket_t>) == 8, "C layout of qsocket_t: alignof")
    static_assert(typeinfo offsetof<next>(type<qsocket_t>) == 0, "C layout of qsocket_t: offsetof next")
    static_assert(typeinfo offsetof<connecttime>(type<qsocket_t>) == 8, "C layout of qsocket_t: offsetof connecttime")
    static_assert(typeinfo offsetof<lastMessageTime>(type<qsocket_t>) == 16, "C layout of qsocket_t: offsetof lastMessageTime")
    static_assert(typeinfo offsetof<lastSendTime>(type<qsocket_t>) == 24, "C layout of qsocket_t: offsetof lastSendTime")
    static_assert(typeinfo offsetof<disconnected>(type<qsocket_t>) == 32, "C layout of qsocket_t: offsetof disconnected")
    static_assert(typeinfo offsetof<canSend>(type<qsocket_t>) == 36, "C layout of qsocket_t: offsetof canSend")
    static_assert(typeinfo offsetof<sendNext>(type<qsocket_t>) == 40, "C layout of qsocket_t: offsetof sendNext")
    static_assert(typeinfo offsetof<driver>(type<qsocket_t>) == 44, "C layout of qsocket_t: offsetof driver")
    static_assert(typeinfo offsetof<landriver>(type<qsocket_t>) == 48, "C layout of qsocket_t: offsetof landriver")
    static_assert(typeinfo offsetof<socket>(type<qsocket_t>) == 52, "C layout of qsocket_t: offsetof socket")
    static_assert(typeinfo offsetof<driverdata>(type<qsocket_t>) == 56, "C layout of qsocket_t: offsetof driverdata")
    static_assert(typeinfo offsetof<ackSequence>(type<qsocket_t>) == 64, "C layout of qsocket_t: offsetof ackSequence")
    static_assert(typeinfo offsetof<sendSequence>(type<qsocket_t>) == 68, "C layout of qsocket_t: offsetof sendSequence")
    static_assert(typeinfo offsetof<unreliableSendSequence>(type<qsocket_t>) == 72, "C layout of qsocket_t: offsetof unreliableSendSequence")
    static_assert(typeinfo offsetof<sendMessageLength>(type<qsocket_t>) == 76, "C layout of qsocket_t: offsetof sendMessageLength")
    static_assert(typeinfo offsetof<sendMessage>(type<qsocket_t>) == 80, "C layout of qsocket_t: offsetof sendMessage")
    static_assert(typeinfo offsetof<receiveSequence>(type<qsocket_t>) == 8272, "C layout of qsocket_t: offsetof receiveSequence")
    static_assert(typeinfo offsetof<unreliableReceiveSequence>(type<qsocket_t>) == 8276, "C layout of qsocket_t: offsetof unreliableReceiveSequence")
    static_assert(typeinfo offsetof<receiveMessageLength>(type<qsocket_t>) == 8280, "C layout of qsocket_t: offsetof receiveMessageLength")
    static_assert(typeinfo offsetof<receiveMessage>(type<qsocket_t>) == 8284, "C layout of qsocket_t: offsetof receiveMessage")
    static_assert(typeinfo offsetof<addr_0>(type<qsocket_t>) == 16476, "C layout of qsocket_t: offsetof addr_0")
    static_assert(typeinfo offsetof<address>(type<qsocket_t>) == 16492, "C layout of qsocket_t: offsetof address")
    static_assert(typeinfo sizeof(type<net_driver_t>) == 120, "C layout of net_driver_t: sizeof")
    static_assert(typeinfo alignof(type<net_driver_t>) == 8, "C layout of net_driver_t: alignof")
    static_assert(typeinfo offsetof<name>(type<net_driver_t>) == 0, "C layout of net_driver_t: offsetof name")
    static_assert(typeinfo offsetof<initialized>(type<net_driver_t>) == 8, "C layout of net_driver_t: offsetof initialized")
    static_assert(typeinfo offsetof<Init>(type<net_driver_t>) == 16, "C layout of net_driver_t: offsetof Init")
    static_assert(typeinfo offsetof<Listen>(type<net_driver_t>) == 24, "C layout of net_driver_t: offsetof Listen")
    static_assert(typeinfo offsetof<SearchForHosts>(type<net_driver_t>) == 32, "C layout of net_driver_t: offsetof SearchForHosts")
    static_assert(typeinfo offsetof<Connect>(type<net_driver_t>) == 40, "C layout of net_driver_t: offsetof Connect")
    static_assert(typeinfo offsetof<CheckNewConnections>(type<net_driver_t>) == 48, "C layout of net_driver_t: offsetof CheckNewConnections")
    static_assert(typeinfo offsetof<QGetMessage>(type<net_driver_t>) == 56, "C layout of net_driver_t: offsetof QGetMessage")
    static_assert(typeinfo offsetof<QSendMessage>(type<net_driver_t>) == 64, "C layout of net_driver_t: offsetof QSendMessage")
    static_assert(typeinfo offsetof<SendUnreliableMessage>(type<net_driver_t>) == 72, "C layout of net_driver_t: offsetof SendUnreliableMessage")
    static_assert(typeinfo offsetof<CanSendMessage>(type<net_driver_t>) == 80, "C layout of net_driver_t: offsetof CanSendMessage")
    static_assert(typeinfo offsetof<CanSendUnreliableMessage>(type<net_driver_t>) == 88, "C layout of net_driver_t: offsetof CanSendUnreliableMessage")
    static_assert(typeinfo offsetof<Close>(type<net_driver_t>) == 96, "C layout of net_driver_t: offsetof Close")
    static_assert(typeinfo offsetof<Shutdown>(type<net_driver_t>) == 104, "C layout of net_driver_t: offsetof Shutdown")
    static_assert(typeinfo offsetof<controlSock>(type<net_driver_t>) == 112, "C layout of net_driver_t: offsetof controlSock")
    static_assert(typeinfo sizeof(type<Unnamed_net_vcr_32>) == 24, "C layout of Unnamed_net_vcr_32: sizeof")
    static_assert(typeinfo alignof(type<Unnamed_net_vcr_32>) == 8, "C layout of Unnamed_net_vcr_32: alignof")
    static_assert(typeinfo offsetof<time>(type<Unnamed_net_vcr_32>) == 0, "C layout of Unnamed_net_vcr_32: offsetof time")
    static_assert(typeinfo offsetof<op>(type<Unnamed_net_vcr_32>) == 8, "C layout of Unnamed_net_vcr_32: offsetof op")
    static_assert(typeinfo offsetof<session>(type<Unnamed_net_vcr_32>) == 16, "C layout of Unnamed_net_vcr_32: offsetof session")
}
