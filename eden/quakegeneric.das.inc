[export, sideeffects]
def QG_Tick(var duration : double) {
    Host_Frame(float(duration))
    return
}
[export, sideeffects]
def QG_Create(var argc : int; var argv : int) {
    let c2da_fresh0 : int = 8 * 1024 * 1024
    let c2da_fresh1 : uint = uint(c2da_fresh0)
    c2da_mem[741336] = uint8(c2da_fresh1)
    c2da_mem[741337] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[741338] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[741339] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : int = c2da_lin_malloc(uint64(int(uint(c2da_mem[741336]) | uint(c2da_mem[741337]) << 0x8 | uint(c2da_mem[741338]) << 0x10 | uint(c2da_mem[741339]) << 0x18)))
    let c2da_fresh3 : uint = uint(c2da_fresh2)
    c2da_mem[741328] = uint8(c2da_fresh3)
    c2da_mem[741329] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[741330] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[741331] = uint8(c2da_fresh3 >> 0x18)
    c2da_mem[741332] = 0u8
    c2da_mem[741333] = 0u8
    c2da_mem[741334] = 0u8
    c2da_mem[741335] = 0u8
    let c2da_fresh4 : uint = 741344u
    c2da_mem[741296] = uint8(c2da_fresh4)
    c2da_mem[741297] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[741298] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[741299] = uint8(c2da_fresh4 >> 0x18)
    c2da_mem[741300] = 0u8
    c2da_mem[741301] = 0u8
    c2da_mem[741302] = 0u8
    c2da_mem[741303] = 0u8
    COM_InitArgv(argc, argv)
    let c2da_fresh5 : int = int(uint(c2da_mem[243888]) | uint(c2da_mem[243889]) << 0x8 | uint(c2da_mem[243890]) << 0x10 | uint(c2da_mem[243891]) << 0x18)
    let c2da_fresh6 : uint = uint(c2da_fresh5)
    c2da_mem[741312] = uint8(c2da_fresh6)
    c2da_mem[741313] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[741314] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[741315] = uint8(c2da_fresh6 >> 0x18)
    let c2da_fresh7 : uint = uint(com_argv)
    c2da_mem[741320] = uint8(c2da_fresh7)
    c2da_mem[741321] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[741322] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[741323] = uint8(c2da_fresh7 >> 0x18)
    c2da_mem[741324] = 0u8
    c2da_mem[741325] = 0u8
    c2da_mem[741326] = 0u8
    c2da_mem[741327] = 0u8
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 741346, [])
    Host_Init(741296)
    return
}

// This unit's static data, at heap offset 741296.
let private c2da_lin_static_quakegeneric_seg = fixed_array<int>(741344, 12)
let private c2da_lin_static_quakegeneric = fixed_array<uint64>(0x495f74736f48002eul, 0xa74696eul)

[init]
def private c2da_lin_init_static_quakegeneric() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_quakegeneric_seg[s * 2]
        for (k in range(c2da_lin_static_quakegeneric_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_quakegeneric[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
