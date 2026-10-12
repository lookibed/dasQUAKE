[export, sideeffects]
def QG_Init() {
    return
}
[export, sideeffects]
def QG_Quit() {
    return
}
[export, sideeffects]
def QG_DrawFrame(var pixels : uint8?) {
    if (scr_con_current != 0.0) {
        return
    }
    if (qg_frame_count < 4096) {
        qg_frame_hash[qg_frame_count] = int(qg_hash_frame(unsafe(reinterpret<uint8 const?>(pixels))))
    }
    qg_frame_count++
    return
}
var qg_frame_count : int = 0

[sideeffects]
def private qg_hash_frame(var pixels_0 : uint8 const?) : uint {
    var hash : uint
    var i : int
    var c : uint8 const?
    var rgb : uint
    hash = 2166136261u
    i = 0
    i = 0
    for (c2da_i in range(i, 320 * 240)) {
        c = unsafe(addr(unsafe(unsafe(addr(qg_palette[0]))[int(unsafe(pixels_0[c2da_i])) * 3])))
        rgb = uint(unsafe(c[0])) << 16u | uint(unsafe(c[1])) << 8u | uint(unsafe(c[2]))
        hash = (hash ^ rgb) * 16777619u
    }
    return hash
}
var private qg_palette : uint8[768]

var qg_frame_hash : int[4096]

[export, sideeffects]
def QG_SetPalette(var palette : uint8?) {
    var i_0 : int = 0
    i_0 = 0
    for (c2da_i_0 in range(i_0, 768)) {
        qg_palette[c2da_i_0] = uint8(unsafe(palette[c2da_i_0]))  // nolint:PERF020
    }
    return
}
[export, sideeffects]
def QG_GetKey(var down : int?; var key : int?) : int {
    return 0
}
[export, sideeffects]
def QG_GetMouseMove(var x : int?; var y : int?) {
    *x = 0
    *y = 0
    return
}
[export, sideeffects]
def QG_GetJoyAxes(var axes : float?) {
    var i_1 : int = 0
    i_1 = 0
    for (c2da_i_1 in range(i_1, 6)) {
        unsafe(axes[c2da_i_1]) = 0.0
    }
    return
}
var qg_frame_seconds : double const = 1.0lf / 64.0lf

