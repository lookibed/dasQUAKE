var net_numlandrivers : int = 0

var net_landrivers : net_landriver_t[8]

var net_numdrivers : int = 1

var net_drivers : net_driver_t[8] = fixed_array<net_driver_t>(net_driver_t(name = 728000, initialized = 0u, Init = 115, Listen = 116, SearchForHosts = 117, Connect = 118, CheckNewConnections = 119, QGetMessage = 120, QSendMessage = 121, SendUnreliableMessage = 122, CanSendMessage = 123, CanSendUnreliableMessage = 124, Close = 125, Shutdown = 126, controlSock = 0), net_driver_t(), net_driver_t(), net_driver_t(), net_driver_t(), net_driver_t(), net_driver_t(), net_driver_t())


// This unit's static data, at heap offset 728000.
let private c2da_lin_static_net_none_seg = fixed_array<int>(728000, 8)
let private c2da_lin_static_net_none = fixed_array<uint64>(0x6b636162706f6f4cul)

[init]
def private c2da_lin_init_static_net_none() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_net_none_seg[s * 2]
        for (k in range(c2da_lin_static_net_none_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_net_none[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
