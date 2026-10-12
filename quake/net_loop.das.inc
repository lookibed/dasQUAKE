var private c2da_str_net_loop_0 : array<int8> = [int8(85), int8(78), int8(78), int8(65), int8(77), int8(69), int8(68), int8(0)]

var private c2da_str_net_loop_1 : array<int8> = [int8(108), int8(111), int8(99), int8(97), int8(108), int8(0)]

var private c2da_str_net_loop_2 : array<int8> = [int8(76), int8(111), int8(111), int8(112), int8(95), int8(67), int8(111), int8(110), int8(110), int8(101), int8(99), int8(116), int8(58), int8(32), int8(110), int8(111), int8(32), int8(113), int8(115), int8(111), int8(99), int8(107), int8(101), int8(116), int8(32), int8(97), int8(118), int8(97), int8(105), int8(108), int8(97), int8(98), int8(108), int8(101), int8(10), int8(0)]

var private c2da_str_net_loop_3 : array<int8> = [int8(108), int8(111), int8(99), int8(97), int8(108), int8(104), int8(111), int8(115), int8(116), int8(0)]

var private c2da_str_net_loop_4 : array<int8> = [int8(76), int8(79), int8(67), int8(65), int8(76), int8(0)]

var private c2da_str_net_loop_5 : array<int8> = [int8(76), int8(111), int8(111), int8(112), int8(95), int8(83), int8(101), int8(110), int8(100), int8(77), int8(101), int8(115), int8(115), int8(97), int8(103), int8(101), int8(58), int8(32), int8(111), int8(118), int8(101), int8(114), int8(102), int8(108), int8(111), int8(119), int8(10), int8(0)]

[export, sideeffects]
def Loop_Init() : int {
    if (uint(cls.state) == 0u) {
        return -1
    }
    return 0
}
[export, sideeffects]
def Loop_Listen(var state : qboolean) {
    return
}
[export, sideeffects]
def Loop_SearchForHosts(var xmit : qboolean) {
    if (uint(sv.active) == 0u) {
        return
    }
    hostCacheCount = 1
    if (Q_strcmp(hostname.string_0, unsafe(addr<int8?>(c2da_str_net_loop_0[0]))) == 0) {
        Q_strcpy(unsafe(addr<int8?>(hostcache[0].name[0])), unsafe(addr<int8?>(c2da_str_net_loop_1[0])))
    } else {
        Q_strcpy(unsafe(addr<int8?>(hostcache[0].name[0])), hostname.string_0)
    }
    Q_strcpy(unsafe(addr<int8?>(hostcache[0].map[0])), unsafe(addr<int8?>(sv.name[0])))
    hostcache[0].users = net_activeconnections
    hostcache[0].maxusers = svs.maxclients
    hostcache[0].driver = net_driverlevel
    Q_strcpy(unsafe(addr<int8?>(hostcache[0].cname[0])), unsafe(addr<int8?>(c2da_str_net_loop_1[0])))
    return
}
[export, sideeffects]
def Loop_Connect(var host : int8?) : qsocket_s? {
    if (Q_strcmp(host, unsafe(addr<int8?>(c2da_str_net_loop_1[0]))) != 0) {
        return unsafe(reinterpret<qsocket_s?>(null))
    }
    localconnectpending = unsafe(reinterpret<qboolean>(1u))
    if (loop_client == null) {
        loop_client = unsafe(reinterpret<qsocket_s?>(unsafe(reinterpret<qsocket_s?>(NET_NewQSocket()))))
        if (loop_client == null) {
            Con_Printf(unsafe(addr<int8?>(c2da_str_net_loop_2[0])), [])
            return unsafe(reinterpret<qsocket_s?>(null))
        }
        var c2da_fresh0 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(loop_client)) + 16492ul))
        Q_strcpy(unsafe(reinterpret<int8?>(c2da_fresh0)), unsafe(addr<int8?>(c2da_str_net_loop_3[0])))
    }
    loop_client.receiveMessageLength = 0
    loop_client.sendMessageLength = 0
    loop_client.canSend = unsafe(reinterpret<qboolean>(1u))
    if (loop_server == null) {
        loop_server = unsafe(reinterpret<qsocket_s?>(unsafe(reinterpret<qsocket_s?>(NET_NewQSocket()))))
        if (loop_server == null) {
            Con_Printf(unsafe(addr<int8?>(c2da_str_net_loop_2[0])), [])
            return unsafe(reinterpret<qsocket_s?>(null))
        }
        var c2da_fresh1 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(loop_server)) + 16492ul))
        Q_strcpy(unsafe(reinterpret<int8?>(c2da_fresh1)), unsafe(addr<int8?>(c2da_str_net_loop_4[0])))
    }
    loop_server.receiveMessageLength = 0
    loop_server.sendMessageLength = 0
    loop_server.canSend = unsafe(reinterpret<qboolean>(1u))
    loop_client.driverdata = unsafe(reinterpret<uint8?>(loop_server))
    loop_server.driverdata = unsafe(reinterpret<uint8?>(loop_client))
    return unsafe(reinterpret<qsocket_s?>(loop_client))
}
var loop_client : qsocket_s? = null

var loop_server : qsocket_s? = null

var localconnectpending : qboolean = unsafe(reinterpret<qboolean>(0u))

[export, sideeffects]
def Loop_CheckNewConnections() : qsocket_s? {
    if (uint(localconnectpending) == 0u) {
        return unsafe(reinterpret<qsocket_s?>(null))
    }
    localconnectpending = unsafe(reinterpret<qboolean>(0u))
    loop_server.sendMessageLength = 0
    loop_server.receiveMessageLength = 0
    loop_server.canSend = unsafe(reinterpret<qboolean>(1u))
    loop_client.sendMessageLength = 0
    loop_client.receiveMessageLength = 0
    loop_client.canSend = unsafe(reinterpret<qboolean>(1u))
    return unsafe(reinterpret<qsocket_s?>(loop_server))
}
[export, sideeffects]
def Loop_GetMessage(var sock : qsocket_s?) : int {
    var ret : int
    var length_0 : int
    if (sock.receiveMessageLength == 0) {
        return 0
    }
    var c2da_fresh2 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(sock)) + 8284ul))
    ret = int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh2))[0]))
    var c2da_fresh3 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(sock)) + 8284ul))
    var c2da_fresh4 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(sock)) + 8284ul))
    length_0 = int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh3))[1])) + (int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh4))[2])) << 8)
    SZ_Clear(unsafe(addr<sizebuf_s?>(net_message)))
    var c2da_fresh5 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(sock)) + 8284ul))
    SZ_Write(unsafe(addr<sizebuf_s?>(net_message)), unsafe(addr<uint8?>(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh5))[4]))), length_0)
    let c2da_fresh6 : int = length_0 + 4
    length_0 = int(uint64(c2da_fresh6) + (4ul - 1ul) & ~(4ul - 1ul))
    sock.receiveMessageLength -= length_0
    if (sock.receiveMessageLength != 0) {
        var c2da_fresh7 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(sock)) + 8284ul))
        var c2da_fresh8 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(sock)) + 8284ul))
        Q_memcpy(unsafe(reinterpret<uint8?>(c2da_fresh7)), unsafe(addr<uint8?>(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh8))[length_0]))), sock.receiveMessageLength)
    }
    if (sock.driverdata != null && ret == 1) {
        unsafe(reinterpret<qsocket_s?>(sock.driverdata)).canSend = unsafe(reinterpret<qboolean>(1u))
    }
    return ret
}
[sideeffects]
def private IntAlign(var value : int) : int {
    return int(uint64(value) + (4ul - 1ul) & ~(4ul - 1ul))
}
[export, sideeffects]
def Loop_SendMessage(var sock_0 : qsocket_s?; var data : sizebuf_s?) : int {
    var buffer : uint8?
    var bufferLength : int?
    if (sock_0.driverdata == null) {
        return -1
    }
    var c2da_fresh9 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<qsocket_s?>(sock_0.driverdata)))) + 8280ul))
    bufferLength = unsafe(reinterpret<int?>(c2da_fresh9))
    if (*bufferLength + data.cursize + 4 > 8192) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_net_loop_5[0])), [])
    }
    var c2da_fresh10 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<qsocket_s?>(sock_0.driverdata)))) + 8284ul))
    buffer = unsafe(reinterpret<uint8?>(unsafe(c2da_fresh10 + *bufferLength)))
    *buffer = 1u8
    unsafe {  // nolint:STYLE025
        buffer += 1
    }
    *buffer = uint8(data.cursize & 255)
    unsafe {  // nolint:STYLE025
        buffer += 1
    }
    *buffer = uint8(data.cursize >> 8)
    unsafe {  // nolint:STYLE025
        buffer += 1
    }
    unsafe {  // nolint:STYLE025
        buffer += 1
    }
    Q_memcpy(unsafe(reinterpret<uint8?>(buffer)), unsafe(reinterpret<uint8?>(data.data)), data.cursize)
    let c2da_fresh11 : int = *bufferLength + data.cursize + 4
    *bufferLength = int(uint64(c2da_fresh11) + (4ul - 1ul) & ~(4ul - 1ul))
    sock_0.canSend = unsafe(reinterpret<qboolean>(0u))
    return 1
}
[export, sideeffects]
def Loop_SendUnreliableMessage(var sock_1 : qsocket_s?; var data_0 : sizebuf_s?) : int {
    var buffer_0 : uint8?
    var bufferLength_0 : int?
    if (sock_1.driverdata == null) {
        return -1
    }
    var c2da_fresh12 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<qsocket_s?>(sock_1.driverdata)))) + 8280ul))
    bufferLength_0 = unsafe(reinterpret<int?>(c2da_fresh12))
    if (uint64(*bufferLength_0 + data_0.cursize) + 1ul + 2ul > 8192ul) {
        return 0
    }
    var c2da_fresh13 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<qsocket_s?>(sock_1.driverdata)))) + 8284ul))
    buffer_0 = unsafe(reinterpret<uint8?>(unsafe(c2da_fresh13 + *bufferLength_0)))
    *buffer_0 = 2u8
    unsafe {  // nolint:STYLE025
        buffer_0 += 1
    }
    *buffer_0 = uint8(data_0.cursize & 255)
    unsafe {  // nolint:STYLE025
        buffer_0 += 1
    }
    *buffer_0 = uint8(data_0.cursize >> 8)
    unsafe {  // nolint:STYLE025
        buffer_0 += 1
    }
    unsafe {  // nolint:STYLE025
        buffer_0 += 1
    }
    Q_memcpy(unsafe(reinterpret<uint8?>(buffer_0)), unsafe(reinterpret<uint8?>(data_0.data)), data_0.cursize)
    let c2da_fresh14 : int = *bufferLength_0 + data_0.cursize + 4
    *bufferLength_0 = int(uint64(c2da_fresh14) + (4ul - 1ul) & ~(4ul - 1ul))
    return 1
}
[export, sideeffects]
def Loop_CanSendMessage(var sock_2 : qsocket_s?) : qboolean {
    if (sock_2.driverdata == null) {
        return unsafe(reinterpret<qboolean>(0u))
    }
    return sock_2.canSend
}
[export, sideeffects]
def Loop_CanSendUnreliableMessage(var sock_3 : qsocket_s?) : qboolean {
    return unsafe(reinterpret<qboolean>(1u))
}
[export, sideeffects]
def Loop_Close(var sock_4 : qsocket_s?) {
    if (sock_4.driverdata != null) {
        unsafe(reinterpret<qsocket_s?>(sock_4.driverdata)).driverdata = null
    }
    sock_4.receiveMessageLength = 0
    sock_4.sendMessageLength = 0
    sock_4.canSend = unsafe(reinterpret<qboolean>(1u))
    if (sock_4 == loop_client) {
        loop_client = null
    } else {
        loop_server = null
    }
    return
}
[export, sideeffects]
def Loop_Shutdown() {
    return
}
[sideeffects]
def private c2da_layout_proofs_25() {
    static_assert(typeinfo sizeof(type<_IO_FILE>) == 216, "C layout of _IO_FILE: sizeof")
    static_assert(typeinfo alignof(type<_IO_FILE>) == 8, "C layout of _IO_FILE: alignof")
    static_assert(typeinfo offsetof<_flags>(type<_IO_FILE>) == 0, "C layout of _IO_FILE: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<_IO_FILE>) == 8, "C layout of _IO_FILE: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<_IO_FILE>) == 16, "C layout of _IO_FILE: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<_IO_FILE>) == 24, "C layout of _IO_FILE: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<_IO_FILE>) == 32, "C layout of _IO_FILE: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<_IO_FILE>) == 40, "C layout of _IO_FILE: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<_IO_FILE>) == 48, "C layout of _IO_FILE: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<_IO_FILE>) == 56, "C layout of _IO_FILE: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<_IO_FILE>) == 64, "C layout of _IO_FILE: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<_IO_FILE>) == 72, "C layout of _IO_FILE: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<_IO_FILE>) == 80, "C layout of _IO_FILE: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<_IO_FILE>) == 88, "C layout of _IO_FILE: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<_IO_FILE>) == 96, "C layout of _IO_FILE: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<_IO_FILE>) == 104, "C layout of _IO_FILE: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<_IO_FILE>) == 112, "C layout of _IO_FILE: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<_IO_FILE>) == 116, "C layout of _IO_FILE: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<_IO_FILE>) == 120, "C layout of _IO_FILE: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<_IO_FILE>) == 128, "C layout of _IO_FILE: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<_IO_FILE>) == 130, "C layout of _IO_FILE: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<_IO_FILE>) == 131, "C layout of _IO_FILE: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<_IO_FILE>) == 136, "C layout of _IO_FILE: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<_IO_FILE>) == 144, "C layout of _IO_FILE: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<_IO_FILE>) == 152, "C layout of _IO_FILE: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<_IO_FILE>) == 160, "C layout of _IO_FILE: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<_IO_FILE>) == 168, "C layout of _IO_FILE: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<_IO_FILE>) == 176, "C layout of _IO_FILE: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<_IO_FILE>) == 184, "C layout of _IO_FILE: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<_IO_FILE>) == 192, "C layout of _IO_FILE: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<_IO_FILE>) == 196, "C layout of _IO_FILE: offsetof _unused2")
    static_assert(typeinfo sizeof(type<FILE_0>) == 216, "C layout of FILE_0: sizeof")
    static_assert(typeinfo alignof(type<FILE_0>) == 8, "C layout of FILE_0: alignof")
    static_assert(typeinfo offsetof<_flags>(type<FILE_0>) == 0, "C layout of FILE_0: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<FILE_0>) == 8, "C layout of FILE_0: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<FILE_0>) == 16, "C layout of FILE_0: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<FILE_0>) == 24, "C layout of FILE_0: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<FILE_0>) == 32, "C layout of FILE_0: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<FILE_0>) == 40, "C layout of FILE_0: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<FILE_0>) == 48, "C layout of FILE_0: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<FILE_0>) == 56, "C layout of FILE_0: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<FILE_0>) == 64, "C layout of FILE_0: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<FILE_0>) == 72, "C layout of FILE_0: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<FILE_0>) == 80, "C layout of FILE_0: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<FILE_0>) == 88, "C layout of FILE_0: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<FILE_0>) == 96, "C layout of FILE_0: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<FILE_0>) == 104, "C layout of FILE_0: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<FILE_0>) == 112, "C layout of FILE_0: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<FILE_0>) == 116, "C layout of FILE_0: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<FILE_0>) == 120, "C layout of FILE_0: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<FILE_0>) == 128, "C layout of FILE_0: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<FILE_0>) == 130, "C layout of FILE_0: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<FILE_0>) == 131, "C layout of FILE_0: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<FILE_0>) == 136, "C layout of FILE_0: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<FILE_0>) == 144, "C layout of FILE_0: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<FILE_0>) == 152, "C layout of FILE_0: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<FILE_0>) == 160, "C layout of FILE_0: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<FILE_0>) == 168, "C layout of FILE_0: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<FILE_0>) == 176, "C layout of FILE_0: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<FILE_0>) == 184, "C layout of FILE_0: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<FILE_0>) == 192, "C layout of FILE_0: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<FILE_0>) == 196, "C layout of FILE_0: offsetof _unused2")
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
    static_assert(typeinfo sizeof(type<link_s>) == 16, "C layout of link_s: sizeof")
    static_assert(typeinfo alignof(type<link_s>) == 8, "C layout of link_s: alignof")
    static_assert(typeinfo offsetof<prev>(type<link_s>) == 0, "C layout of link_s: offsetof prev")
    static_assert(typeinfo offsetof<next>(type<link_s>) == 8, "C layout of link_s: offsetof next")
    static_assert(typeinfo sizeof(type<link_t>) == 16, "C layout of link_t: sizeof")
    static_assert(typeinfo alignof(type<link_t>) == 8, "C layout of link_t: alignof")
    static_assert(typeinfo offsetof<prev>(type<link_t>) == 0, "C layout of link_t: offsetof prev")
    static_assert(typeinfo offsetof<next>(type<link_t>) == 8, "C layout of link_t: offsetof next")
    static_assert(typeinfo sizeof(type<cache_user_s>) == 8, "C layout of cache_user_s: sizeof")
    static_assert(typeinfo alignof(type<cache_user_s>) == 8, "C layout of cache_user_s: alignof")
    static_assert(typeinfo offsetof<data>(type<cache_user_s>) == 0, "C layout of cache_user_s: offsetof data")
    static_assert(typeinfo sizeof(type<cvar_s>) == 40, "C layout of cvar_s: sizeof")
    static_assert(typeinfo alignof(type<cvar_s>) == 8, "C layout of cvar_s: alignof")
    static_assert(typeinfo offsetof<name>(type<cvar_s>) == 0, "C layout of cvar_s: offsetof name")
    static_assert(typeinfo offsetof<string_0>(type<cvar_s>) == 8, "C layout of cvar_s: offsetof string_0")
    static_assert(typeinfo offsetof<archive>(type<cvar_s>) == 16, "C layout of cvar_s: offsetof archive")
    static_assert(typeinfo offsetof<server>(type<cvar_s>) == 20, "C layout of cvar_s: offsetof server")
    static_assert(typeinfo offsetof<value>(type<cvar_s>) == 24, "C layout of cvar_s: offsetof value")
    static_assert(typeinfo offsetof<next>(type<cvar_s>) == 32, "C layout of cvar_s: offsetof next")
    static_assert(typeinfo sizeof(type<dmodel_t>) == 64, "C layout of dmodel_t: sizeof")
    static_assert(typeinfo alignof(type<dmodel_t>) == 4, "C layout of dmodel_t: alignof")
    static_assert(typeinfo offsetof<mins>(type<dmodel_t>) == 0, "C layout of dmodel_t: offsetof mins")
    static_assert(typeinfo offsetof<maxs>(type<dmodel_t>) == 12, "C layout of dmodel_t: offsetof maxs")
    static_assert(typeinfo offsetof<origin>(type<dmodel_t>) == 24, "C layout of dmodel_t: offsetof origin")
    static_assert(typeinfo offsetof<headnode>(type<dmodel_t>) == 36, "C layout of dmodel_t: offsetof headnode")
    static_assert(typeinfo offsetof<visleafs>(type<dmodel_t>) == 52, "C layout of dmodel_t: offsetof visleafs")
    static_assert(typeinfo offsetof<firstface>(type<dmodel_t>) == 56, "C layout of dmodel_t: offsetof firstface")
    static_assert(typeinfo offsetof<numfaces>(type<dmodel_t>) == 60, "C layout of dmodel_t: offsetof numfaces")
    static_assert(typeinfo sizeof(type<dclipnode_t>) == 8, "C layout of dclipnode_t: sizeof")
    static_assert(typeinfo alignof(type<dclipnode_t>) == 4, "C layout of dclipnode_t: alignof")
    static_assert(typeinfo offsetof<planenum>(type<dclipnode_t>) == 0, "C layout of dclipnode_t: offsetof planenum")
    static_assert(typeinfo offsetof<children>(type<dclipnode_t>) == 4, "C layout of dclipnode_t: offsetof children")
    static_assert(typeinfo sizeof(type<cache_user_t>) == 8, "C layout of cache_user_t: sizeof")
    static_assert(typeinfo alignof(type<cache_user_t>) == 8, "C layout of cache_user_t: alignof")
    static_assert(typeinfo offsetof<data>(type<cache_user_t>) == 0, "C layout of cache_user_t: offsetof data")
    static_assert(typeinfo sizeof(type<mplane_s>) == 20, "C layout of mplane_s: sizeof")
    static_assert(typeinfo alignof(type<mplane_s>) == 4, "C layout of mplane_s: alignof")
    static_assert(typeinfo offsetof<normal>(type<mplane_s>) == 0, "C layout of mplane_s: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<mplane_s>) == 12, "C layout of mplane_s: offsetof dist")
    static_assert(typeinfo offsetof<type_0>(type<mplane_s>) == 16, "C layout of mplane_s: offsetof type_0")
    static_assert(typeinfo offsetof<signbits>(type<mplane_s>) == 17, "C layout of mplane_s: offsetof signbits")
    static_assert(typeinfo offsetof<pad>(type<mplane_s>) == 18, "C layout of mplane_s: offsetof pad")
    static_assert(typeinfo sizeof(type<entity_state_t>) == 44, "C layout of entity_state_t: sizeof")
    static_assert(typeinfo alignof(type<entity_state_t>) == 4, "C layout of entity_state_t: alignof")
    static_assert(typeinfo offsetof<origin>(type<entity_state_t>) == 0, "C layout of entity_state_t: offsetof origin")
    static_assert(typeinfo offsetof<angles>(type<entity_state_t>) == 12, "C layout of entity_state_t: offsetof angles")
    static_assert(typeinfo offsetof<modelindex>(type<entity_state_t>) == 24, "C layout of entity_state_t: offsetof modelindex")
    static_assert(typeinfo offsetof<frame>(type<entity_state_t>) == 28, "C layout of entity_state_t: offsetof frame")
    static_assert(typeinfo offsetof<colormap>(type<entity_state_t>) == 32, "C layout of entity_state_t: offsetof colormap")
    static_assert(typeinfo offsetof<skin>(type<entity_state_t>) == 36, "C layout of entity_state_t: offsetof skin")
    static_assert(typeinfo offsetof<effects>(type<entity_state_t>) == 40, "C layout of entity_state_t: offsetof effects")
    static_assert(typeinfo sizeof(type<cvar_t>) == 40, "C layout of cvar_t: sizeof")
    static_assert(typeinfo alignof(type<cvar_t>) == 8, "C layout of cvar_t: alignof")
    static_assert(typeinfo offsetof<name>(type<cvar_t>) == 0, "C layout of cvar_t: offsetof name")
    static_assert(typeinfo offsetof<string_0>(type<cvar_t>) == 8, "C layout of cvar_t: offsetof string_0")
    static_assert(typeinfo offsetof<archive>(type<cvar_t>) == 16, "C layout of cvar_t: offsetof archive")
    static_assert(typeinfo offsetof<server>(type<cvar_t>) == 20, "C layout of cvar_t: offsetof server")
    static_assert(typeinfo offsetof<value>(type<cvar_t>) == 24, "C layout of cvar_t: offsetof value")
    static_assert(typeinfo offsetof<next>(type<cvar_t>) == 32, "C layout of cvar_t: offsetof next")
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
    static_assert(typeinfo sizeof(type<hostcache_t>) == 96, "C layout of hostcache_t: sizeof")
    static_assert(typeinfo alignof(type<hostcache_t>) == 4, "C layout of hostcache_t: alignof")
    static_assert(typeinfo offsetof<name>(type<hostcache_t>) == 0, "C layout of hostcache_t: offsetof name")
    static_assert(typeinfo offsetof<map>(type<hostcache_t>) == 16, "C layout of hostcache_t: offsetof map")
    static_assert(typeinfo offsetof<cname>(type<hostcache_t>) == 32, "C layout of hostcache_t: offsetof cname")
    static_assert(typeinfo offsetof<users>(type<hostcache_t>) == 64, "C layout of hostcache_t: offsetof users")
    static_assert(typeinfo offsetof<maxusers>(type<hostcache_t>) == 68, "C layout of hostcache_t: offsetof maxusers")
    static_assert(typeinfo offsetof<driver>(type<hostcache_t>) == 72, "C layout of hostcache_t: offsetof driver")
    static_assert(typeinfo offsetof<ldriver>(type<hostcache_t>) == 76, "C layout of hostcache_t: offsetof ldriver")
    static_assert(typeinfo offsetof<addr_0>(type<hostcache_t>) == 80, "C layout of hostcache_t: offsetof addr_0")
    static_assert(typeinfo sizeof(type<efrag_s>) == 32, "C layout of efrag_s: sizeof")
    static_assert(typeinfo alignof(type<efrag_s>) == 8, "C layout of efrag_s: alignof")
    static_assert(typeinfo offsetof<leaf>(type<efrag_s>) == 0, "C layout of efrag_s: offsetof leaf")
    static_assert(typeinfo offsetof<leafnext>(type<efrag_s>) == 8, "C layout of efrag_s: offsetof leafnext")
    static_assert(typeinfo offsetof<entity>(type<efrag_s>) == 16, "C layout of efrag_s: offsetof entity")
    static_assert(typeinfo offsetof<entnext>(type<efrag_s>) == 24, "C layout of efrag_s: offsetof entnext")
    static_assert(typeinfo sizeof(type<entity_s>) == 200, "C layout of entity_s: sizeof")
    static_assert(typeinfo alignof(type<entity_s>) == 8, "C layout of entity_s: alignof")
    static_assert(typeinfo offsetof<forcelink>(type<entity_s>) == 0, "C layout of entity_s: offsetof forcelink")
    static_assert(typeinfo offsetof<update_type>(type<entity_s>) == 4, "C layout of entity_s: offsetof update_type")
    static_assert(typeinfo offsetof<baseline>(type<entity_s>) == 8, "C layout of entity_s: offsetof baseline")
    static_assert(typeinfo offsetof<msgtime>(type<entity_s>) == 56, "C layout of entity_s: offsetof msgtime")
    static_assert(typeinfo offsetof<msg_origins>(type<entity_s>) == 64, "C layout of entity_s: offsetof msg_origins")
    static_assert(typeinfo offsetof<origin>(type<entity_s>) == 88, "C layout of entity_s: offsetof origin")
    static_assert(typeinfo offsetof<msg_angles>(type<entity_s>) == 100, "C layout of entity_s: offsetof msg_angles")
    static_assert(typeinfo offsetof<angles>(type<entity_s>) == 124, "C layout of entity_s: offsetof angles")
    static_assert(typeinfo offsetof<model>(type<entity_s>) == 136, "C layout of entity_s: offsetof model")
    static_assert(typeinfo offsetof<efrag>(type<entity_s>) == 144, "C layout of entity_s: offsetof efrag")
    static_assert(typeinfo offsetof<frame>(type<entity_s>) == 152, "C layout of entity_s: offsetof frame")
    static_assert(typeinfo offsetof<syncbase>(type<entity_s>) == 156, "C layout of entity_s: offsetof syncbase")
    static_assert(typeinfo offsetof<colormap>(type<entity_s>) == 160, "C layout of entity_s: offsetof colormap")
    static_assert(typeinfo offsetof<effects>(type<entity_s>) == 168, "C layout of entity_s: offsetof effects")
    static_assert(typeinfo offsetof<skinnum>(type<entity_s>) == 172, "C layout of entity_s: offsetof skinnum")
    static_assert(typeinfo offsetof<visframe>(type<entity_s>) == 176, "C layout of entity_s: offsetof visframe")
    static_assert(typeinfo offsetof<dlightframe>(type<entity_s>) == 180, "C layout of entity_s: offsetof dlightframe")
    static_assert(typeinfo offsetof<dlightbits>(type<entity_s>) == 184, "C layout of entity_s: offsetof dlightbits")
    static_assert(typeinfo offsetof<trivial_accept>(type<entity_s>) == 188, "C layout of entity_s: offsetof trivial_accept")
    static_assert(typeinfo offsetof<topnode>(type<entity_s>) == 192, "C layout of entity_s: offsetof topnode")
    static_assert(typeinfo sizeof(type<mnode_s>) == 64, "C layout of mnode_s: sizeof")
    static_assert(typeinfo alignof(type<mnode_s>) == 8, "C layout of mnode_s: alignof")
    static_assert(typeinfo offsetof<contents>(type<mnode_s>) == 0, "C layout of mnode_s: offsetof contents")
    static_assert(typeinfo offsetof<visframe>(type<mnode_s>) == 4, "C layout of mnode_s: offsetof visframe")
    static_assert(typeinfo offsetof<minmaxs>(type<mnode_s>) == 8, "C layout of mnode_s: offsetof minmaxs")
    static_assert(typeinfo offsetof<parent>(type<mnode_s>) == 24, "C layout of mnode_s: offsetof parent")
    static_assert(typeinfo offsetof<plane>(type<mnode_s>) == 32, "C layout of mnode_s: offsetof plane")
    static_assert(typeinfo offsetof<children>(type<mnode_s>) == 40, "C layout of mnode_s: offsetof children")
    static_assert(typeinfo offsetof<firstsurface>(type<mnode_s>) == 56, "C layout of mnode_s: offsetof firstsurface")
    static_assert(typeinfo offsetof<numsurfaces>(type<mnode_s>) == 58, "C layout of mnode_s: offsetof numsurfaces")
    static_assert(typeinfo sizeof(type<mplane_t>) == 20, "C layout of mplane_t: sizeof")
    static_assert(typeinfo alignof(type<mplane_t>) == 4, "C layout of mplane_t: alignof")
    static_assert(typeinfo offsetof<normal>(type<mplane_t>) == 0, "C layout of mplane_t: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<mplane_t>) == 12, "C layout of mplane_t: offsetof dist")
    static_assert(typeinfo offsetof<type_0>(type<mplane_t>) == 16, "C layout of mplane_t: offsetof type_0")
    static_assert(typeinfo offsetof<signbits>(type<mplane_t>) == 17, "C layout of mplane_t: offsetof signbits")
    static_assert(typeinfo offsetof<pad>(type<mplane_t>) == 18, "C layout of mplane_t: offsetof pad")
    static_assert(typeinfo sizeof(type<model_s>) == 536, "C layout of model_s: sizeof")
    static_assert(typeinfo alignof(type<model_s>) == 8, "C layout of model_s: alignof")
    static_assert(typeinfo offsetof<name>(type<model_s>) == 0, "C layout of model_s: offsetof name")
    static_assert(typeinfo offsetof<needload>(type<model_s>) == 64, "C layout of model_s: offsetof needload")
    static_assert(typeinfo offsetof<type_0>(type<model_s>) == 68, "C layout of model_s: offsetof type_0")
    static_assert(typeinfo offsetof<numframes>(type<model_s>) == 72, "C layout of model_s: offsetof numframes")
    static_assert(typeinfo offsetof<synctype>(type<model_s>) == 76, "C layout of model_s: offsetof synctype")
    static_assert(typeinfo offsetof<flags>(type<model_s>) == 80, "C layout of model_s: offsetof flags")
    static_assert(typeinfo offsetof<mins>(type<model_s>) == 84, "C layout of model_s: offsetof mins")
    static_assert(typeinfo offsetof<maxs>(type<model_s>) == 96, "C layout of model_s: offsetof maxs")
    static_assert(typeinfo offsetof<radius>(type<model_s>) == 108, "C layout of model_s: offsetof radius")
    static_assert(typeinfo offsetof<firstmodelsurface>(type<model_s>) == 112, "C layout of model_s: offsetof firstmodelsurface")
    static_assert(typeinfo offsetof<nummodelsurfaces>(type<model_s>) == 116, "C layout of model_s: offsetof nummodelsurfaces")
    static_assert(typeinfo offsetof<numsubmodels>(type<model_s>) == 120, "C layout of model_s: offsetof numsubmodels")
    static_assert(typeinfo offsetof<submodels>(type<model_s>) == 128, "C layout of model_s: offsetof submodels")
    static_assert(typeinfo offsetof<numplanes>(type<model_s>) == 136, "C layout of model_s: offsetof numplanes")
    static_assert(typeinfo offsetof<planes>(type<model_s>) == 144, "C layout of model_s: offsetof planes")
    static_assert(typeinfo offsetof<numleafs>(type<model_s>) == 152, "C layout of model_s: offsetof numleafs")
    static_assert(typeinfo offsetof<leafs>(type<model_s>) == 160, "C layout of model_s: offsetof leafs")
    static_assert(typeinfo offsetof<numvertexes>(type<model_s>) == 168, "C layout of model_s: offsetof numvertexes")
    static_assert(typeinfo offsetof<vertexes>(type<model_s>) == 176, "C layout of model_s: offsetof vertexes")
    static_assert(typeinfo offsetof<numedges>(type<model_s>) == 184, "C layout of model_s: offsetof numedges")
    static_assert(typeinfo offsetof<edges>(type<model_s>) == 192, "C layout of model_s: offsetof edges")
    static_assert(typeinfo offsetof<numnodes>(type<model_s>) == 200, "C layout of model_s: offsetof numnodes")
    static_assert(typeinfo offsetof<nodes>(type<model_s>) == 208, "C layout of model_s: offsetof nodes")
    static_assert(typeinfo offsetof<numtexinfo>(type<model_s>) == 216, "C layout of model_s: offsetof numtexinfo")
    static_assert(typeinfo offsetof<texinfo>(type<model_s>) == 224, "C layout of model_s: offsetof texinfo")
    static_assert(typeinfo offsetof<numsurfaces>(type<model_s>) == 232, "C layout of model_s: offsetof numsurfaces")
    static_assert(typeinfo offsetof<surfaces>(type<model_s>) == 240, "C layout of model_s: offsetof surfaces")
    static_assert(typeinfo offsetof<numsurfedges>(type<model_s>) == 248, "C layout of model_s: offsetof numsurfedges")
    static_assert(typeinfo offsetof<surfedges>(type<model_s>) == 256, "C layout of model_s: offsetof surfedges")
    static_assert(typeinfo offsetof<numclipnodes>(type<model_s>) == 264, "C layout of model_s: offsetof numclipnodes")
    static_assert(typeinfo offsetof<clipnodes>(type<model_s>) == 272, "C layout of model_s: offsetof clipnodes")
    static_assert(typeinfo offsetof<nummarksurfaces>(type<model_s>) == 280, "C layout of model_s: offsetof nummarksurfaces")
    static_assert(typeinfo offsetof<marksurfaces>(type<model_s>) == 288, "C layout of model_s: offsetof marksurfaces")
    static_assert(typeinfo offsetof<hulls>(type<model_s>) == 296, "C layout of model_s: offsetof hulls")
    static_assert(typeinfo offsetof<numtextures>(type<model_s>) == 488, "C layout of model_s: offsetof numtextures")
    static_assert(typeinfo offsetof<textures>(type<model_s>) == 496, "C layout of model_s: offsetof textures")
    static_assert(typeinfo offsetof<visdata>(type<model_s>) == 504, "C layout of model_s: offsetof visdata")
    static_assert(typeinfo offsetof<lightdata>(type<model_s>) == 512, "C layout of model_s: offsetof lightdata")
    static_assert(typeinfo offsetof<entities>(type<model_s>) == 520, "C layout of model_s: offsetof entities")
    static_assert(typeinfo offsetof<cache>(type<model_s>) == 528, "C layout of model_s: offsetof cache")
    static_assert(typeinfo sizeof(type<texture_t>) == 72, "C layout of texture_t: sizeof")
    static_assert(typeinfo alignof(type<texture_t>) == 8, "C layout of texture_t: alignof")
    static_assert(typeinfo offsetof<name>(type<texture_t>) == 0, "C layout of texture_t: offsetof name")
    static_assert(typeinfo offsetof<width>(type<texture_t>) == 16, "C layout of texture_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<texture_t>) == 20, "C layout of texture_t: offsetof height")
    static_assert(typeinfo offsetof<anim_total>(type<texture_t>) == 24, "C layout of texture_t: offsetof anim_total")
    static_assert(typeinfo offsetof<anim_min>(type<texture_t>) == 28, "C layout of texture_t: offsetof anim_min")
    static_assert(typeinfo offsetof<anim_max>(type<texture_t>) == 32, "C layout of texture_t: offsetof anim_max")
    static_assert(typeinfo offsetof<anim_next>(type<texture_t>) == 40, "C layout of texture_t: offsetof anim_next")
    static_assert(typeinfo offsetof<alternate_anims>(type<texture_t>) == 48, "C layout of texture_t: offsetof alternate_anims")
    static_assert(typeinfo offsetof<offsets>(type<texture_t>) == 56, "C layout of texture_t: offsetof offsets")
    static_assert(typeinfo sizeof(type<texture_s>) == 72, "C layout of texture_s: sizeof")
    static_assert(typeinfo alignof(type<texture_s>) == 8, "C layout of texture_s: alignof")
    static_assert(typeinfo offsetof<name>(type<texture_s>) == 0, "C layout of texture_s: offsetof name")
    static_assert(typeinfo offsetof<width>(type<texture_s>) == 16, "C layout of texture_s: offsetof width")
    static_assert(typeinfo offsetof<height>(type<texture_s>) == 20, "C layout of texture_s: offsetof height")
    static_assert(typeinfo offsetof<anim_total>(type<texture_s>) == 24, "C layout of texture_s: offsetof anim_total")
    static_assert(typeinfo offsetof<anim_min>(type<texture_s>) == 28, "C layout of texture_s: offsetof anim_min")
    static_assert(typeinfo offsetof<anim_max>(type<texture_s>) == 32, "C layout of texture_s: offsetof anim_max")
    static_assert(typeinfo offsetof<anim_next>(type<texture_s>) == 40, "C layout of texture_s: offsetof anim_next")
    static_assert(typeinfo offsetof<alternate_anims>(type<texture_s>) == 48, "C layout of texture_s: offsetof alternate_anims")
    static_assert(typeinfo offsetof<offsets>(type<texture_s>) == 56, "C layout of texture_s: offsetof offsets")
    static_assert(typeinfo sizeof(type<hull_t>) == 48, "C layout of hull_t: sizeof")
    static_assert(typeinfo alignof(type<hull_t>) == 8, "C layout of hull_t: alignof")
    static_assert(typeinfo offsetof<clipnodes>(type<hull_t>) == 0, "C layout of hull_t: offsetof clipnodes")
    static_assert(typeinfo offsetof<planes>(type<hull_t>) == 8, "C layout of hull_t: offsetof planes")
    static_assert(typeinfo offsetof<firstclipnode>(type<hull_t>) == 16, "C layout of hull_t: offsetof firstclipnode")
    static_assert(typeinfo offsetof<lastclipnode>(type<hull_t>) == 20, "C layout of hull_t: offsetof lastclipnode")
    static_assert(typeinfo offsetof<clip_mins>(type<hull_t>) == 24, "C layout of hull_t: offsetof clip_mins")
    static_assert(typeinfo offsetof<clip_maxs>(type<hull_t>) == 36, "C layout of hull_t: offsetof clip_maxs")
    static_assert(typeinfo sizeof(type<msurface_t>) == 104, "C layout of msurface_t: sizeof")
    static_assert(typeinfo alignof(type<msurface_t>) == 8, "C layout of msurface_t: alignof")
    static_assert(typeinfo offsetof<visframe>(type<msurface_t>) == 0, "C layout of msurface_t: offsetof visframe")
    static_assert(typeinfo offsetof<dlightframe>(type<msurface_t>) == 4, "C layout of msurface_t: offsetof dlightframe")
    static_assert(typeinfo offsetof<dlightbits>(type<msurface_t>) == 8, "C layout of msurface_t: offsetof dlightbits")
    static_assert(typeinfo offsetof<plane>(type<msurface_t>) == 16, "C layout of msurface_t: offsetof plane")
    static_assert(typeinfo offsetof<flags>(type<msurface_t>) == 24, "C layout of msurface_t: offsetof flags")
    static_assert(typeinfo offsetof<firstedge>(type<msurface_t>) == 28, "C layout of msurface_t: offsetof firstedge")
    static_assert(typeinfo offsetof<numedges>(type<msurface_t>) == 32, "C layout of msurface_t: offsetof numedges")
    static_assert(typeinfo offsetof<cachespots>(type<msurface_t>) == 40, "C layout of msurface_t: offsetof cachespots")
    static_assert(typeinfo offsetof<texturemins>(type<msurface_t>) == 72, "C layout of msurface_t: offsetof texturemins")
    static_assert(typeinfo offsetof<extents>(type<msurface_t>) == 76, "C layout of msurface_t: offsetof extents")
    static_assert(typeinfo offsetof<texinfo>(type<msurface_t>) == 80, "C layout of msurface_t: offsetof texinfo")
    static_assert(typeinfo offsetof<styles>(type<msurface_t>) == 88, "C layout of msurface_t: offsetof styles")
    static_assert(typeinfo offsetof<samples>(type<msurface_t>) == 96, "C layout of msurface_t: offsetof samples")
    static_assert(typeinfo sizeof(type<msurface_s>) == 104, "C layout of msurface_s: sizeof")
    static_assert(typeinfo alignof(type<msurface_s>) == 8, "C layout of msurface_s: alignof")
    static_assert(typeinfo offsetof<visframe>(type<msurface_s>) == 0, "C layout of msurface_s: offsetof visframe")
    static_assert(typeinfo offsetof<dlightframe>(type<msurface_s>) == 4, "C layout of msurface_s: offsetof dlightframe")
    static_assert(typeinfo offsetof<dlightbits>(type<msurface_s>) == 8, "C layout of msurface_s: offsetof dlightbits")
    static_assert(typeinfo offsetof<plane>(type<msurface_s>) == 16, "C layout of msurface_s: offsetof plane")
    static_assert(typeinfo offsetof<flags>(type<msurface_s>) == 24, "C layout of msurface_s: offsetof flags")
    static_assert(typeinfo offsetof<firstedge>(type<msurface_s>) == 28, "C layout of msurface_s: offsetof firstedge")
    static_assert(typeinfo offsetof<numedges>(type<msurface_s>) == 32, "C layout of msurface_s: offsetof numedges")
    static_assert(typeinfo offsetof<cachespots>(type<msurface_s>) == 40, "C layout of msurface_s: offsetof cachespots")
    static_assert(typeinfo offsetof<texturemins>(type<msurface_s>) == 72, "C layout of msurface_s: offsetof texturemins")
    static_assert(typeinfo offsetof<extents>(type<msurface_s>) == 76, "C layout of msurface_s: offsetof extents")
    static_assert(typeinfo offsetof<texinfo>(type<msurface_s>) == 80, "C layout of msurface_s: offsetof texinfo")
    static_assert(typeinfo offsetof<styles>(type<msurface_s>) == 88, "C layout of msurface_s: offsetof styles")
    static_assert(typeinfo offsetof<samples>(type<msurface_s>) == 96, "C layout of msurface_s: offsetof samples")
    static_assert(typeinfo sizeof(type<mtexinfo_t>) == 56, "C layout of mtexinfo_t: sizeof")
    static_assert(typeinfo alignof(type<mtexinfo_t>) == 8, "C layout of mtexinfo_t: alignof")
    static_assert(typeinfo offsetof<vecs>(type<mtexinfo_t>) == 0, "C layout of mtexinfo_t: offsetof vecs")
    static_assert(typeinfo offsetof<mipadjust>(type<mtexinfo_t>) == 32, "C layout of mtexinfo_t: offsetof mipadjust")
    static_assert(typeinfo offsetof<texture>(type<mtexinfo_t>) == 40, "C layout of mtexinfo_t: offsetof texture")
    static_assert(typeinfo offsetof<flags>(type<mtexinfo_t>) == 48, "C layout of mtexinfo_t: offsetof flags")
    static_assert(typeinfo sizeof(type<mnode_t>) == 64, "C layout of mnode_t: sizeof")
    static_assert(typeinfo alignof(type<mnode_t>) == 8, "C layout of mnode_t: alignof")
    static_assert(typeinfo offsetof<contents>(type<mnode_t>) == 0, "C layout of mnode_t: offsetof contents")
    static_assert(typeinfo offsetof<visframe>(type<mnode_t>) == 4, "C layout of mnode_t: offsetof visframe")
    static_assert(typeinfo offsetof<minmaxs>(type<mnode_t>) == 8, "C layout of mnode_t: offsetof minmaxs")
    static_assert(typeinfo offsetof<parent>(type<mnode_t>) == 24, "C layout of mnode_t: offsetof parent")
    static_assert(typeinfo offsetof<plane>(type<mnode_t>) == 32, "C layout of mnode_t: offsetof plane")
    static_assert(typeinfo offsetof<children>(type<mnode_t>) == 40, "C layout of mnode_t: offsetof children")
    static_assert(typeinfo offsetof<firstsurface>(type<mnode_t>) == 56, "C layout of mnode_t: offsetof firstsurface")
    static_assert(typeinfo offsetof<numsurfaces>(type<mnode_t>) == 58, "C layout of mnode_t: offsetof numsurfaces")
    static_assert(typeinfo sizeof(type<medge_t>) == 8, "C layout of medge_t: sizeof")
    static_assert(typeinfo alignof(type<medge_t>) == 4, "C layout of medge_t: alignof")
    static_assert(typeinfo offsetof<v>(type<medge_t>) == 0, "C layout of medge_t: offsetof v")
    static_assert(typeinfo offsetof<cachededgeoffset>(type<medge_t>) == 4, "C layout of medge_t: offsetof cachededgeoffset")
    static_assert(typeinfo sizeof(type<mvertex_t>) == 12, "C layout of mvertex_t: sizeof")
    static_assert(typeinfo alignof(type<mvertex_t>) == 4, "C layout of mvertex_t: alignof")
    static_assert(typeinfo offsetof<position>(type<mvertex_t>) == 0, "C layout of mvertex_t: offsetof position")
    static_assert(typeinfo sizeof(type<mleaf_t>) == 72, "C layout of mleaf_t: sizeof")
    static_assert(typeinfo alignof(type<mleaf_t>) == 8, "C layout of mleaf_t: alignof")
    static_assert(typeinfo offsetof<contents>(type<mleaf_t>) == 0, "C layout of mleaf_t: offsetof contents")
    static_assert(typeinfo offsetof<visframe>(type<mleaf_t>) == 4, "C layout of mleaf_t: offsetof visframe")
    static_assert(typeinfo offsetof<minmaxs>(type<mleaf_t>) == 8, "C layout of mleaf_t: offsetof minmaxs")
    static_assert(typeinfo offsetof<parent>(type<mleaf_t>) == 24, "C layout of mleaf_t: offsetof parent")
    static_assert(typeinfo offsetof<compressed_vis>(type<mleaf_t>) == 32, "C layout of mleaf_t: offsetof compressed_vis")
    static_assert(typeinfo offsetof<efrags>(type<mleaf_t>) == 40, "C layout of mleaf_t: offsetof efrags")
    static_assert(typeinfo offsetof<firstmarksurface>(type<mleaf_t>) == 48, "C layout of mleaf_t: offsetof firstmarksurface")
    static_assert(typeinfo offsetof<nummarksurfaces>(type<mleaf_t>) == 56, "C layout of mleaf_t: offsetof nummarksurfaces")
    static_assert(typeinfo offsetof<key>(type<mleaf_t>) == 60, "C layout of mleaf_t: offsetof key")
    static_assert(typeinfo offsetof<ambient_sound_level>(type<mleaf_t>) == 64, "C layout of mleaf_t: offsetof ambient_sound_level")
    static_assert(typeinfo sizeof(type<mleaf_s>) == 72, "C layout of mleaf_s: sizeof")
    static_assert(typeinfo alignof(type<mleaf_s>) == 8, "C layout of mleaf_s: alignof")
    static_assert(typeinfo offsetof<contents>(type<mleaf_s>) == 0, "C layout of mleaf_s: offsetof contents")
    static_assert(typeinfo offsetof<visframe>(type<mleaf_s>) == 4, "C layout of mleaf_s: offsetof visframe")
    static_assert(typeinfo offsetof<minmaxs>(type<mleaf_s>) == 8, "C layout of mleaf_s: offsetof minmaxs")
    static_assert(typeinfo offsetof<parent>(type<mleaf_s>) == 24, "C layout of mleaf_s: offsetof parent")
    static_assert(typeinfo offsetof<compressed_vis>(type<mleaf_s>) == 32, "C layout of mleaf_s: offsetof compressed_vis")
    static_assert(typeinfo offsetof<efrags>(type<mleaf_s>) == 40, "C layout of mleaf_s: offsetof efrags")
    static_assert(typeinfo offsetof<firstmarksurface>(type<mleaf_s>) == 48, "C layout of mleaf_s: offsetof firstmarksurface")
    static_assert(typeinfo offsetof<nummarksurfaces>(type<mleaf_s>) == 56, "C layout of mleaf_s: offsetof nummarksurfaces")
    static_assert(typeinfo offsetof<key>(type<mleaf_s>) == 60, "C layout of mleaf_s: offsetof key")
    static_assert(typeinfo offsetof<ambient_sound_level>(type<mleaf_s>) == 64, "C layout of mleaf_s: offsetof ambient_sound_level")
    static_assert(typeinfo sizeof(type<efrag_t>) == 32, "C layout of efrag_t: sizeof")
    static_assert(typeinfo alignof(type<efrag_t>) == 8, "C layout of efrag_t: alignof")
    static_assert(typeinfo offsetof<leaf>(type<efrag_t>) == 0, "C layout of efrag_t: offsetof leaf")
    static_assert(typeinfo offsetof<leafnext>(type<efrag_t>) == 8, "C layout of efrag_t: offsetof leafnext")
    static_assert(typeinfo offsetof<entity>(type<efrag_t>) == 16, "C layout of efrag_t: offsetof entity")
    static_assert(typeinfo offsetof<entnext>(type<efrag_t>) == 24, "C layout of efrag_t: offsetof entnext")
    static_assert(typeinfo sizeof(type<usercmd_t>) == 24, "C layout of usercmd_t: sizeof")
    static_assert(typeinfo alignof(type<usercmd_t>) == 4, "C layout of usercmd_t: alignof")
    static_assert(typeinfo offsetof<viewangles>(type<usercmd_t>) == 0, "C layout of usercmd_t: offsetof viewangles")
    static_assert(typeinfo offsetof<forwardmove>(type<usercmd_t>) == 12, "C layout of usercmd_t: offsetof forwardmove")
    static_assert(typeinfo offsetof<sidemove>(type<usercmd_t>) == 16, "C layout of usercmd_t: offsetof sidemove")
    static_assert(typeinfo offsetof<upmove>(type<usercmd_t>) == 20, "C layout of usercmd_t: offsetof upmove")
    static_assert(typeinfo sizeof(type<client_static_t>) == 2320, "C layout of client_static_t: sizeof")
    static_assert(typeinfo alignof(type<client_static_t>) == 8, "C layout of client_static_t: alignof")
    static_assert(typeinfo offsetof<state>(type<client_static_t>) == 0, "C layout of client_static_t: offsetof state")
    static_assert(typeinfo offsetof<mapstring>(type<client_static_t>) == 4, "C layout of client_static_t: offsetof mapstring")
    static_assert(typeinfo offsetof<spawnparms>(type<client_static_t>) == 68, "C layout of client_static_t: offsetof spawnparms")
    static_assert(typeinfo offsetof<demonum>(type<client_static_t>) == 2116, "C layout of client_static_t: offsetof demonum")
    static_assert(typeinfo offsetof<demos>(type<client_static_t>) == 2120, "C layout of client_static_t: offsetof demos")
    static_assert(typeinfo offsetof<demorecording>(type<client_static_t>) == 2248, "C layout of client_static_t: offsetof demorecording")
    static_assert(typeinfo offsetof<demoplayback>(type<client_static_t>) == 2252, "C layout of client_static_t: offsetof demoplayback")
    static_assert(typeinfo offsetof<timedemo>(type<client_static_t>) == 2256, "C layout of client_static_t: offsetof timedemo")
    static_assert(typeinfo offsetof<forcetrack>(type<client_static_t>) == 2260, "C layout of client_static_t: offsetof forcetrack")
    static_assert(typeinfo offsetof<demofile>(type<client_static_t>) == 2264, "C layout of client_static_t: offsetof demofile")
    static_assert(typeinfo offsetof<td_lastframe>(type<client_static_t>) == 2272, "C layout of client_static_t: offsetof td_lastframe")
    static_assert(typeinfo offsetof<td_startframe>(type<client_static_t>) == 2276, "C layout of client_static_t: offsetof td_startframe")
    static_assert(typeinfo offsetof<td_starttime>(type<client_static_t>) == 2280, "C layout of client_static_t: offsetof td_starttime")
    static_assert(typeinfo offsetof<signon>(type<client_static_t>) == 2284, "C layout of client_static_t: offsetof signon")
    static_assert(typeinfo offsetof<netcon>(type<client_static_t>) == 2288, "C layout of client_static_t: offsetof netcon")
    static_assert(typeinfo offsetof<message>(type<client_static_t>) == 2296, "C layout of client_static_t: offsetof message")
    static_assert(typeinfo sizeof(type<entvars_t>) == 420, "C layout of entvars_t: sizeof")
    static_assert(typeinfo alignof(type<entvars_t>) == 4, "C layout of entvars_t: alignof")
    static_assert(typeinfo offsetof<modelindex>(type<entvars_t>) == 0, "C layout of entvars_t: offsetof modelindex")
    static_assert(typeinfo offsetof<absmin>(type<entvars_t>) == 4, "C layout of entvars_t: offsetof absmin")
    static_assert(typeinfo offsetof<absmax>(type<entvars_t>) == 16, "C layout of entvars_t: offsetof absmax")
    static_assert(typeinfo offsetof<ltime>(type<entvars_t>) == 28, "C layout of entvars_t: offsetof ltime")
    static_assert(typeinfo offsetof<movetype>(type<entvars_t>) == 32, "C layout of entvars_t: offsetof movetype")
    static_assert(typeinfo offsetof<solid>(type<entvars_t>) == 36, "C layout of entvars_t: offsetof solid")
    static_assert(typeinfo offsetof<origin>(type<entvars_t>) == 40, "C layout of entvars_t: offsetof origin")
    static_assert(typeinfo offsetof<oldorigin>(type<entvars_t>) == 52, "C layout of entvars_t: offsetof oldorigin")
    static_assert(typeinfo offsetof<velocity>(type<entvars_t>) == 64, "C layout of entvars_t: offsetof velocity")
    static_assert(typeinfo offsetof<angles>(type<entvars_t>) == 76, "C layout of entvars_t: offsetof angles")
    static_assert(typeinfo offsetof<avelocity>(type<entvars_t>) == 88, "C layout of entvars_t: offsetof avelocity")
    static_assert(typeinfo offsetof<punchangle>(type<entvars_t>) == 100, "C layout of entvars_t: offsetof punchangle")
    static_assert(typeinfo offsetof<classname>(type<entvars_t>) == 112, "C layout of entvars_t: offsetof classname")
    static_assert(typeinfo offsetof<model>(type<entvars_t>) == 116, "C layout of entvars_t: offsetof model")
    static_assert(typeinfo offsetof<frame>(type<entvars_t>) == 120, "C layout of entvars_t: offsetof frame")
    static_assert(typeinfo offsetof<skin>(type<entvars_t>) == 124, "C layout of entvars_t: offsetof skin")
    static_assert(typeinfo offsetof<effects>(type<entvars_t>) == 128, "C layout of entvars_t: offsetof effects")
    static_assert(typeinfo offsetof<mins>(type<entvars_t>) == 132, "C layout of entvars_t: offsetof mins")
    static_assert(typeinfo offsetof<maxs>(type<entvars_t>) == 144, "C layout of entvars_t: offsetof maxs")
    static_assert(typeinfo offsetof<size>(type<entvars_t>) == 156, "C layout of entvars_t: offsetof size")
    static_assert(typeinfo offsetof<touch>(type<entvars_t>) == 168, "C layout of entvars_t: offsetof touch")
    static_assert(typeinfo offsetof<use>(type<entvars_t>) == 172, "C layout of entvars_t: offsetof use")
    static_assert(typeinfo offsetof<think>(type<entvars_t>) == 176, "C layout of entvars_t: offsetof think")
    static_assert(typeinfo offsetof<blocked>(type<entvars_t>) == 180, "C layout of entvars_t: offsetof blocked")
    static_assert(typeinfo offsetof<nextthink>(type<entvars_t>) == 184, "C layout of entvars_t: offsetof nextthink")
    static_assert(typeinfo offsetof<groundentity>(type<entvars_t>) == 188, "C layout of entvars_t: offsetof groundentity")
    static_assert(typeinfo offsetof<health>(type<entvars_t>) == 192, "C layout of entvars_t: offsetof health")
    static_assert(typeinfo offsetof<frags>(type<entvars_t>) == 196, "C layout of entvars_t: offsetof frags")
    static_assert(typeinfo offsetof<weapon>(type<entvars_t>) == 200, "C layout of entvars_t: offsetof weapon")
    static_assert(typeinfo offsetof<weaponmodel>(type<entvars_t>) == 204, "C layout of entvars_t: offsetof weaponmodel")
    static_assert(typeinfo offsetof<weaponframe>(type<entvars_t>) == 208, "C layout of entvars_t: offsetof weaponframe")
    static_assert(typeinfo offsetof<currentammo>(type<entvars_t>) == 212, "C layout of entvars_t: offsetof currentammo")
    static_assert(typeinfo offsetof<ammo_shells>(type<entvars_t>) == 216, "C layout of entvars_t: offsetof ammo_shells")
    static_assert(typeinfo offsetof<ammo_nails>(type<entvars_t>) == 220, "C layout of entvars_t: offsetof ammo_nails")
    static_assert(typeinfo offsetof<ammo_rockets>(type<entvars_t>) == 224, "C layout of entvars_t: offsetof ammo_rockets")
    static_assert(typeinfo offsetof<ammo_cells>(type<entvars_t>) == 228, "C layout of entvars_t: offsetof ammo_cells")
    static_assert(typeinfo offsetof<items>(type<entvars_t>) == 232, "C layout of entvars_t: offsetof items")
    static_assert(typeinfo offsetof<takedamage>(type<entvars_t>) == 236, "C layout of entvars_t: offsetof takedamage")
    static_assert(typeinfo offsetof<chain>(type<entvars_t>) == 240, "C layout of entvars_t: offsetof chain")
    static_assert(typeinfo offsetof<deadflag>(type<entvars_t>) == 244, "C layout of entvars_t: offsetof deadflag")
    static_assert(typeinfo offsetof<view_ofs>(type<entvars_t>) == 248, "C layout of entvars_t: offsetof view_ofs")
    static_assert(typeinfo offsetof<button0>(type<entvars_t>) == 260, "C layout of entvars_t: offsetof button0")
    static_assert(typeinfo offsetof<button1>(type<entvars_t>) == 264, "C layout of entvars_t: offsetof button1")
    static_assert(typeinfo offsetof<button2>(type<entvars_t>) == 268, "C layout of entvars_t: offsetof button2")
    static_assert(typeinfo offsetof<impulse>(type<entvars_t>) == 272, "C layout of entvars_t: offsetof impulse")
    static_assert(typeinfo offsetof<fixangle>(type<entvars_t>) == 276, "C layout of entvars_t: offsetof fixangle")
    static_assert(typeinfo offsetof<v_angle>(type<entvars_t>) == 280, "C layout of entvars_t: offsetof v_angle")
    static_assert(typeinfo offsetof<idealpitch>(type<entvars_t>) == 292, "C layout of entvars_t: offsetof idealpitch")
    static_assert(typeinfo offsetof<netname>(type<entvars_t>) == 296, "C layout of entvars_t: offsetof netname")
    static_assert(typeinfo offsetof<enemy>(type<entvars_t>) == 300, "C layout of entvars_t: offsetof enemy")
    static_assert(typeinfo offsetof<flags>(type<entvars_t>) == 304, "C layout of entvars_t: offsetof flags")
    static_assert(typeinfo offsetof<colormap>(type<entvars_t>) == 308, "C layout of entvars_t: offsetof colormap")
    static_assert(typeinfo offsetof<team>(type<entvars_t>) == 312, "C layout of entvars_t: offsetof team")
    static_assert(typeinfo offsetof<max_health>(type<entvars_t>) == 316, "C layout of entvars_t: offsetof max_health")
    static_assert(typeinfo offsetof<teleport_time>(type<entvars_t>) == 320, "C layout of entvars_t: offsetof teleport_time")
    static_assert(typeinfo offsetof<armortype>(type<entvars_t>) == 324, "C layout of entvars_t: offsetof armortype")
    static_assert(typeinfo offsetof<armorvalue>(type<entvars_t>) == 328, "C layout of entvars_t: offsetof armorvalue")
    static_assert(typeinfo offsetof<waterlevel>(type<entvars_t>) == 332, "C layout of entvars_t: offsetof waterlevel")
    static_assert(typeinfo offsetof<watertype>(type<entvars_t>) == 336, "C layout of entvars_t: offsetof watertype")
    static_assert(typeinfo offsetof<ideal_yaw>(type<entvars_t>) == 340, "C layout of entvars_t: offsetof ideal_yaw")
    static_assert(typeinfo offsetof<yaw_speed>(type<entvars_t>) == 344, "C layout of entvars_t: offsetof yaw_speed")
    static_assert(typeinfo offsetof<aiment>(type<entvars_t>) == 348, "C layout of entvars_t: offsetof aiment")
    static_assert(typeinfo offsetof<goalentity>(type<entvars_t>) == 352, "C layout of entvars_t: offsetof goalentity")
    static_assert(typeinfo offsetof<spawnflags>(type<entvars_t>) == 356, "C layout of entvars_t: offsetof spawnflags")
    static_assert(typeinfo offsetof<target>(type<entvars_t>) == 360, "C layout of entvars_t: offsetof target")
    static_assert(typeinfo offsetof<targetname>(type<entvars_t>) == 364, "C layout of entvars_t: offsetof targetname")
    static_assert(typeinfo offsetof<dmg_take>(type<entvars_t>) == 368, "C layout of entvars_t: offsetof dmg_take")
    static_assert(typeinfo offsetof<dmg_save>(type<entvars_t>) == 372, "C layout of entvars_t: offsetof dmg_save")
    static_assert(typeinfo offsetof<dmg_inflictor>(type<entvars_t>) == 376, "C layout of entvars_t: offsetof dmg_inflictor")
    static_assert(typeinfo offsetof<owner>(type<entvars_t>) == 380, "C layout of entvars_t: offsetof owner")
    static_assert(typeinfo offsetof<movedir>(type<entvars_t>) == 384, "C layout of entvars_t: offsetof movedir")
    static_assert(typeinfo offsetof<message>(type<entvars_t>) == 396, "C layout of entvars_t: offsetof message")
    static_assert(typeinfo offsetof<sounds>(type<entvars_t>) == 400, "C layout of entvars_t: offsetof sounds")
    static_assert(typeinfo offsetof<noise>(type<entvars_t>) == 404, "C layout of entvars_t: offsetof noise")
    static_assert(typeinfo offsetof<noise1>(type<entvars_t>) == 408, "C layout of entvars_t: offsetof noise1")
    static_assert(typeinfo offsetof<noise2>(type<entvars_t>) == 412, "C layout of entvars_t: offsetof noise2")
    static_assert(typeinfo offsetof<noise3>(type<entvars_t>) == 416, "C layout of entvars_t: offsetof noise3")
    static_assert(typeinfo sizeof(type<edict_s>) == 528, "C layout of edict_s: sizeof")
    static_assert(typeinfo alignof(type<edict_s>) == 8, "C layout of edict_s: alignof")
    static_assert(typeinfo offsetof<free>(type<edict_s>) == 0, "C layout of edict_s: offsetof free")
    static_assert(typeinfo offsetof<area>(type<edict_s>) == 8, "C layout of edict_s: offsetof area")
    static_assert(typeinfo offsetof<num_leafs>(type<edict_s>) == 24, "C layout of edict_s: offsetof num_leafs")
    static_assert(typeinfo offsetof<leafnums>(type<edict_s>) == 28, "C layout of edict_s: offsetof leafnums")
    static_assert(typeinfo offsetof<baseline>(type<edict_s>) == 60, "C layout of edict_s: offsetof baseline")
    static_assert(typeinfo offsetof<freetime>(type<edict_s>) == 104, "C layout of edict_s: offsetof freetime")
    static_assert(typeinfo offsetof<v>(type<edict_s>) == 108, "C layout of edict_s: offsetof v")
    static_assert(typeinfo sizeof(type<edict_t>) == 528, "C layout of edict_t: sizeof")
    static_assert(typeinfo alignof(type<edict_t>) == 8, "C layout of edict_t: alignof")
    static_assert(typeinfo offsetof<free>(type<edict_t>) == 0, "C layout of edict_t: offsetof free")
    static_assert(typeinfo offsetof<area>(type<edict_t>) == 8, "C layout of edict_t: offsetof area")
    static_assert(typeinfo offsetof<num_leafs>(type<edict_t>) == 24, "C layout of edict_t: offsetof num_leafs")
    static_assert(typeinfo offsetof<leafnums>(type<edict_t>) == 28, "C layout of edict_t: offsetof leafnums")
    static_assert(typeinfo offsetof<baseline>(type<edict_t>) == 60, "C layout of edict_t: offsetof baseline")
    static_assert(typeinfo offsetof<freetime>(type<edict_t>) == 104, "C layout of edict_t: offsetof freetime")
    static_assert(typeinfo offsetof<v>(type<edict_t>) == 108, "C layout of edict_t: offsetof v")
    static_assert(typeinfo sizeof(type<client_s>) == 8288, "C layout of client_s: sizeof")
    static_assert(typeinfo alignof(type<client_s>) == 8, "C layout of client_s: alignof")
    static_assert(typeinfo offsetof<active>(type<client_s>) == 0, "C layout of client_s: offsetof active")
    static_assert(typeinfo offsetof<spawned>(type<client_s>) == 4, "C layout of client_s: offsetof spawned")
    static_assert(typeinfo offsetof<dropasap>(type<client_s>) == 8, "C layout of client_s: offsetof dropasap")
    static_assert(typeinfo offsetof<privileged>(type<client_s>) == 12, "C layout of client_s: offsetof privileged")
    static_assert(typeinfo offsetof<sendsignon>(type<client_s>) == 16, "C layout of client_s: offsetof sendsignon")
    static_assert(typeinfo offsetof<last_message>(type<client_s>) == 24, "C layout of client_s: offsetof last_message")
    static_assert(typeinfo offsetof<netconnection>(type<client_s>) == 32, "C layout of client_s: offsetof netconnection")
    static_assert(typeinfo offsetof<cmd>(type<client_s>) == 40, "C layout of client_s: offsetof cmd")
    static_assert(typeinfo offsetof<wishdir>(type<client_s>) == 64, "C layout of client_s: offsetof wishdir")
    static_assert(typeinfo offsetof<message>(type<client_s>) == 80, "C layout of client_s: offsetof message")
    static_assert(typeinfo offsetof<msgbuf>(type<client_s>) == 104, "C layout of client_s: offsetof msgbuf")
    static_assert(typeinfo offsetof<edict>(type<client_s>) == 8104, "C layout of client_s: offsetof edict")
    static_assert(typeinfo offsetof<name>(type<client_s>) == 8112, "C layout of client_s: offsetof name")
    static_assert(typeinfo offsetof<colors>(type<client_s>) == 8144, "C layout of client_s: offsetof colors")
    static_assert(typeinfo offsetof<ping_times>(type<client_s>) == 8148, "C layout of client_s: offsetof ping_times")
    static_assert(typeinfo offsetof<num_pings>(type<client_s>) == 8212, "C layout of client_s: offsetof num_pings")
    static_assert(typeinfo offsetof<spawn_parms>(type<client_s>) == 8216, "C layout of client_s: offsetof spawn_parms")
    static_assert(typeinfo offsetof<old_frags>(type<client_s>) == 8280, "C layout of client_s: offsetof old_frags")
    static_assert(typeinfo sizeof(type<server_static_t>) == 24, "C layout of server_static_t: sizeof")
    static_assert(typeinfo alignof(type<server_static_t>) == 8, "C layout of server_static_t: alignof")
    static_assert(typeinfo offsetof<maxclients>(type<server_static_t>) == 0, "C layout of server_static_t: offsetof maxclients")
    static_assert(typeinfo offsetof<maxclientslimit>(type<server_static_t>) == 4, "C layout of server_static_t: offsetof maxclientslimit")
    static_assert(typeinfo offsetof<clients>(type<server_static_t>) == 8, "C layout of server_static_t: offsetof clients")
    static_assert(typeinfo offsetof<serverflags>(type<server_static_t>) == 16, "C layout of server_static_t: offsetof serverflags")
    static_assert(typeinfo offsetof<changelevel_issued>(type<server_static_t>) == 20, "C layout of server_static_t: offsetof changelevel_issued")
    static_assert(typeinfo sizeof(type<server_t>) == 17168, "C layout of server_t: sizeof")
    static_assert(typeinfo alignof(type<server_t>) == 8, "C layout of server_t: alignof")
    static_assert(typeinfo offsetof<active>(type<server_t>) == 0, "C layout of server_t: offsetof active")
    static_assert(typeinfo offsetof<paused>(type<server_t>) == 4, "C layout of server_t: offsetof paused")
    static_assert(typeinfo offsetof<loadgame>(type<server_t>) == 8, "C layout of server_t: offsetof loadgame")
    static_assert(typeinfo offsetof<time>(type<server_t>) == 16, "C layout of server_t: offsetof time")
    static_assert(typeinfo offsetof<lastcheck>(type<server_t>) == 24, "C layout of server_t: offsetof lastcheck")
    static_assert(typeinfo offsetof<lastchecktime>(type<server_t>) == 32, "C layout of server_t: offsetof lastchecktime")
    static_assert(typeinfo offsetof<name>(type<server_t>) == 40, "C layout of server_t: offsetof name")
    static_assert(typeinfo offsetof<modelname>(type<server_t>) == 104, "C layout of server_t: offsetof modelname")
    static_assert(typeinfo offsetof<worldmodel>(type<server_t>) == 168, "C layout of server_t: offsetof worldmodel")
    static_assert(typeinfo offsetof<model_precache>(type<server_t>) == 176, "C layout of server_t: offsetof model_precache")
    static_assert(typeinfo offsetof<models>(type<server_t>) == 2224, "C layout of server_t: offsetof models")
    static_assert(typeinfo offsetof<sound_precache>(type<server_t>) == 4272, "C layout of server_t: offsetof sound_precache")
    static_assert(typeinfo offsetof<lightstyles>(type<server_t>) == 6320, "C layout of server_t: offsetof lightstyles")
    static_assert(typeinfo offsetof<num_edicts>(type<server_t>) == 6832, "C layout of server_t: offsetof num_edicts")
    static_assert(typeinfo offsetof<max_edicts>(type<server_t>) == 6836, "C layout of server_t: offsetof max_edicts")
    static_assert(typeinfo offsetof<edicts>(type<server_t>) == 6840, "C layout of server_t: offsetof edicts")
    static_assert(typeinfo offsetof<state>(type<server_t>) == 6848, "C layout of server_t: offsetof state")
    static_assert(typeinfo offsetof<datagram>(type<server_t>) == 6856, "C layout of server_t: offsetof datagram")
    static_assert(typeinfo offsetof<datagram_buf>(type<server_t>) == 6880, "C layout of server_t: offsetof datagram_buf")
    static_assert(typeinfo offsetof<reliable_datagram>(type<server_t>) == 7904, "C layout of server_t: offsetof reliable_datagram")
    static_assert(typeinfo offsetof<reliable_datagram_buf>(type<server_t>) == 7928, "C layout of server_t: offsetof reliable_datagram_buf")
    static_assert(typeinfo offsetof<signon>(type<server_t>) == 8952, "C layout of server_t: offsetof signon")
    static_assert(typeinfo offsetof<signon_buf>(type<server_t>) == 8976, "C layout of server_t: offsetof signon_buf")
}
