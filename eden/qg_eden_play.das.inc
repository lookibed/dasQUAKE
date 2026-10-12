[export, sideeffects]
def qge_init() : int {
    return qge_start(3)
}
[sideeffects]
def private qge_start(var argc : int) : int {
    let c2da_fresh0 : uint = 742192u
    c2da_mem[741360 + 0 * 8] = uint8(c2da_fresh0)
    c2da_mem[741360 + 0 * 8 + 1] = uint8(c2da_fresh0 >> 0x8)
    c2da_mem[741360 + 0 * 8 + 2] = uint8(c2da_fresh0 >> 0x10)
    c2da_mem[741360 + 0 * 8 + 3] = uint8(c2da_fresh0 >> 0x18)
    c2da_mem[741360 + 0 * 8 + 4] = 0u8
    c2da_mem[741360 + 0 * 8 + 5] = 0u8
    c2da_mem[741360 + 0 * 8 + 6] = 0u8
    c2da_mem[741360 + 0 * 8 + 7] = 0u8
    let c2da_fresh1 : uint = 742198u
    c2da_mem[741360 + 1 * 8] = uint8(c2da_fresh1)
    c2da_mem[741360 + 1 * 8 + 1] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[741360 + 1 * 8 + 2] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[741360 + 1 * 8 + 3] = uint8(c2da_fresh1 >> 0x18)
    c2da_mem[741360 + 1 * 8 + 4] = 0u8
    c2da_mem[741360 + 1 * 8 + 5] = 0u8
    c2da_mem[741360 + 1 * 8 + 6] = 0u8
    c2da_mem[741360 + 1 * 8 + 7] = 0u8
    let c2da_fresh2 : uint = 742192u
    c2da_mem[741360 + 2 * 8] = uint8(c2da_fresh2)
    c2da_mem[741360 + 2 * 8 + 1] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[741360 + 2 * 8 + 2] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[741360 + 2 * 8 + 3] = uint8(c2da_fresh2 >> 0x18)
    c2da_mem[741360 + 2 * 8 + 4] = 0u8
    c2da_mem[741360 + 2 * 8 + 5] = 0u8
    c2da_mem[741360 + 2 * 8 + 6] = 0u8
    c2da_mem[741360 + 2 * 8 + 7] = 0u8
    let c2da_fresh3 : uint = 0u
    c2da_mem[741360 + argc * 8] = uint8(c2da_fresh3)
    c2da_mem[741360 + argc * 8 + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[741360 + argc * 8 + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[741360 + argc * 8 + 3] = uint8(c2da_fresh3 >> 0x18)
    c2da_mem[741360 + argc * 8 + 4] = 0u8
    c2da_mem[741360 + argc * 8 + 5] = 0u8
    c2da_mem[741360 + argc * 8 + 6] = 0u8
    c2da_mem[741360 + argc * 8 + 7] = 0u8
    qge_clock_ms = 0u
    QG_Create(argc, 741360)
    return qge_frame_count
}
var private qge_frame_count : int = 0

var private qge_clock_ms : uint = 0u

[export, sideeffects]
def qge_init_map() : int {
    let c2da_fresh4 : uint = 742207u
    c2da_mem[741360 + 3 * 8] = uint8(c2da_fresh4)
    c2da_mem[741360 + 3 * 8 + 1] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[741360 + 3 * 8 + 2] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[741360 + 3 * 8 + 3] = uint8(c2da_fresh4 >> 0x18)
    c2da_mem[741360 + 3 * 8 + 4] = 0u8
    c2da_mem[741360 + 3 * 8 + 5] = 0u8
    c2da_mem[741360 + 3 * 8 + 6] = 0u8
    c2da_mem[741360 + 3 * 8 + 7] = 0u8
    let c2da_fresh5 : uint = 742212u
    c2da_mem[741360 + 4 * 8] = uint8(c2da_fresh5)
    c2da_mem[741360 + 4 * 8 + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[741360 + 4 * 8 + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[741360 + 4 * 8 + 3] = uint8(c2da_fresh5 >> 0x18)
    c2da_mem[741360 + 4 * 8 + 4] = 0u8
    c2da_mem[741360 + 4 * 8 + 5] = 0u8
    c2da_mem[741360 + 4 * 8 + 6] = 0u8
    c2da_mem[741360 + 4 * 8 + 7] = 0u8
    return qge_start(5)
}
[export, sideeffects]
def qge_tick(var ms : uint) {
    var elapsed : uint = ms - qge_clock_ms
    qge_clock_ms = uint(ms)  // nolint:PERF020
    QG_Tick(double(elapsed) / 1000.0lf)
    return
}
[export, sideeffects]
def qge_key(var pressed : int; var qkey : int) {
    var next : int = (qge_key_tail + 1) % 64
    if (next == qge_key_head) {
        return
    }
    qge_key_down[qge_key_tail] = pressed != 0 ? 1 : 0
    qge_key_code[qge_key_tail] = int(qkey)  // nolint:PERF020
    qge_key_tail = next
    return
}
var private qge_key_tail : int = 0

var private qge_key_code : int[64]

var private qge_key_down : int[64]

var private qge_key_head : int = 0

[export, sideeffects]
def qge_mouse(var dx : int; var dy : int) {
    qge_mouse_dx += dx
    qge_mouse_dy += dy
    return
}
var private qge_mouse_dy : int = 0

var private qge_mouse_dx : int = 0

[export, sideeffects]
def qge_screen() : uint {
    return uint(uint64(qge_screen_pixels))
}
var private qge_screen_pixels : int = 0

[export, sideeffects]
def qge_palette() : uint {
    return 741424u
}
[export, sideeffects]
def qge_frames() : int {
    return qge_frame_count
}
[export, sideeffects]
def qge_width() : int {
    return 320
}
[export, sideeffects]
def qge_height() : int {
    return 240
}
[export, sideeffects]
def QG_Init() {
    return
}
[export, sideeffects]
def QG_Quit() {
    return
}
[export, sideeffects]
def QG_DrawFrame(var pixels : int) {
    qge_screen_pixels = int(pixels)  // nolint:PERF020
    qge_frame_count++
    return
}
[export, sideeffects]
def QG_SetPalette(var palette : int) {
    var i : int = 0
    i = 0
    for (c2da_i in range(i, 768)) {
        let c2da_fresh6 : uint8 = c2da_mem[palette + c2da_i]
        c2da_mem[741424 + c2da_i] = c2da_fresh6
    }
    return
}
[export, sideeffects]
def QG_GetKey(var down : int; var key : int) : int {
    if (qge_key_head == qge_key_tail) {
        return 0
    }
    let c2da_fresh7 : int = qge_key_down[qge_key_head]
    let c2da_fresh8 : uint = uint(c2da_fresh7)
    c2da_mem[down] = uint8(c2da_fresh8)
    c2da_mem[down + 1] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[down + 2] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[down + 3] = uint8(c2da_fresh8 >> 0x18)
    let c2da_fresh9 : int = qge_key_code[qge_key_head]
    let c2da_fresh10 : uint = uint(c2da_fresh9)
    c2da_mem[key] = uint8(c2da_fresh10)
    c2da_mem[key + 1] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[key + 2] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[key + 3] = uint8(c2da_fresh10 >> 0x18)
    qge_key_head = (qge_key_head + 1) % 64
    return 1
}
[export, sideeffects]
def QG_GetMouseMove(var x : int; var y : int) {
    let c2da_fresh11 : uint = uint(qge_mouse_dx)
    c2da_mem[x] = uint8(c2da_fresh11)
    c2da_mem[x + 1] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[x + 2] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[x + 3] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : uint = uint(qge_mouse_dy)
    c2da_mem[y] = uint8(c2da_fresh12)
    c2da_mem[y + 1] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[y + 2] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[y + 3] = uint8(c2da_fresh12 >> 0x18)
    qge_mouse_dx = 0
    qge_mouse_dy = 0
    return
}
[export, sideeffects]
def QG_GetJoyAxes(var axes : int) {
    var i_0 : int = 0
    i_0 = 0
    for (c2da_i_0 in range(i_0, 6)) {
        let c2da_fresh13 : float = 0.0
        let c2da_fresh14 : uint = float_bits_to_uint(c2da_fresh13)
        c2da_mem[axes + c2da_i_0 * 4] = uint8(c2da_fresh14)
        c2da_mem[axes + c2da_i_0 * 4 + 1] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[axes + c2da_i_0 * 4 + 2] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[axes + c2da_i_0 * 4 + 3] = uint8(c2da_fresh14 >> 0x18)
    }
    return
}

// This unit's static data, at heap offset 741360.
let private c2da_lin_static_qg_eden_play_seg = fixed_array<int>(742192, 25)
let private c2da_lin_static_qg_eden_play = fixed_array<uint64>(0x622d00656b617571ul, 0x2b00726964657361ul, 0x726174730070616dul, 0x74ul)

[init]
def private c2da_lin_init_static_qg_eden_play() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_qg_eden_play_seg[s * 2]
        for (k in range(c2da_lin_static_qg_eden_play_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_qg_eden_play[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
