[export, sideeffects]
def D_DisableBackBufferAccess() {
    return
}
[export, sideeffects]
def D_EnableBackBufferAccess() {
    return
}
[export, sideeffects]
def D_Init() {
    r_skydirect = 1
    Cvar_RegisterVariable(204272)
    Cvar_RegisterVariable(204320)
    Cvar_RegisterVariable(204368)
    r_drawpolys = 0u
    r_worldpolysbacktofront = 0u
    r_recursiveaffinetriangles = 1u
    r_aliasuvscale = 1.0
    return
}
[export, sideeffects]
def D_SetupFrame() {
    if (uint(r_dowarp) != 0u) {
        d_viewbuffer = int(uint(c2da_mem[392928]) | uint(c2da_mem[392929]) << 0x8 | uint(c2da_mem[392930]) << 0x10 | uint(c2da_mem[392931]) << 0x18)
    } else {
        d_viewbuffer = vid.buffer
    }
    if (uint(r_dowarp) != 0u) {
        screenwidth = 320
    } else {
        screenwidth = int(vid.rowbytes)
    }
    d_roverwrapped = 0u
    d_initial_rover = sc_rover
    d_minmip = int(uint_bits_to_float(uint(c2da_mem[204344]) | uint(c2da_mem[204345]) << 0x8 | uint(c2da_mem[204346]) << 0x10 | uint(c2da_mem[204347]) << 0x18))
    if (d_minmip > 3) {
        d_minmip = 3
    } elif (d_minmip < 0) {
        d_minmip = 0
    }
    for (i in range(0, 4 - 1)) {
        d_scalemip[i] = basemip[i] * uint_bits_to_float(uint(c2da_mem[204392]) | uint(c2da_mem[204393]) << 0x8 | uint(c2da_mem[204394]) << 0x10 | uint(c2da_mem[204395]) << 0x18)
    }
    d_drawspans = 59
    d_aflatcolor = 0
    return
}
var d_drawspans : int = default<int>

var private basemip : float[3] = fixed_array<float>(1.0, float(0.5lf * 0.8lf), float(0.25lf * 0.8lf))

var d_scalemip : float[3]

var d_minmip : int = default<int>

var d_initial_rover : int = default<int>

var d_roverwrapped : uint = default<uint>

[export, sideeffects]
def D_TurnZOn() {
    return
}
[export, sideeffects]
def D_UpdateRects(var prect : int) {
    prect = int(prect)  // nolint:PERF020
    return
}
[export, sideeffects]
def D_CopyRects(var prects : int; var transparent : int) {
    prects = int(prects)  // nolint:PERF020
    transparent = int(transparent)  // nolint:PERF020
    return
}

// This unit's static data, at heap offset 706976.
let private c2da_lin_static_d_init_seg = fixed_array<int>(706976, 34)
let private c2da_lin_static_d_init = fixed_array<uint64>(0x7669646275735f64ul, 0x6d5f640031003631ul, 0x30007061637069ul, 0x61637370696d5f64ul, 0x656cul)

[init]
def private c2da_lin_init_static_d_init() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_d_init_seg[s * 2]
        for (k in range(c2da_lin_static_d_init_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_d_init[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_d_init_0 = fixed_array<uint8>(0xa0, 0xc9, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xab, 0xc9, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_d_init_1 = fixed_array<uint8>(0xad, 0xc9, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb6, 0xc9, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_d_init_2 = fixed_array<uint8>(0xb8, 0xc9, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0xab, 0xc9, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_d_init() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[204272 + i] = c2da_lin_extern_d_init_0[i]
    }
    for (i in range(40)) {
        c2da_mem[204320 + i] = c2da_lin_extern_d_init_1[i]
    }
    for (i in range(40)) {
        c2da_mem[204368 + i] = c2da_lin_extern_d_init_2[i]
    }
}
