var vid : viddef_t = default<viddef_t>

[export, sideeffects]
def VID_SetPalette(var palette : int) {
    QG_SetPalette(palette)
    return
}
[export, sideeffects]
def VID_ShiftPalette(var palette_0 : int) {
    QG_SetPalette(palette_0)
    return
}
[export, sideeffects]
def VID_Init(var palette_1 : int) {
    vid.conwidth = 320u
    vid.width = uint(vid.conwidth)  // nolint:PERF020
    vid.maxwarpwidth = int(vid.width)
    vid.conheight = 240u
    vid.height = uint(vid.conheight)  // nolint:PERF020
    vid.maxwarpheight = int(vid.height)
    vid.aspect = 1.0
    vid.numpages = 1
    vid.colormap = host_colormap
    let c2da_fresh0 : int = vid.colormap + 2048 * 4
    vid.fullbright = 256 - invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18))
    vid.conbuffer = 465344
    vid.buffer = int(vid.conbuffer)  // nolint:PERF020
    vid.conrowbytes = 320
    vid.rowbytes = uint(vid.conrowbytes)
    d_pzbuffer = 542144
    surfcache_size = uint64(D_SurfaceCacheForRes(320, 240))
    surfcache = c2da_lin_malloc(surfcache_size)
    D_InitCaches(surfcache, int(surfcache_size))
    QG_Init()
    return
}
var surfcache_size : uint64 = default<uint64>

var surfcache : int = default<int>

[export, sideeffects]
def VID_Shutdown() {
    c2da_lin_free(surfcache)
    return
}
[export, sideeffects]
def VID_Update(var rects : int) {
    QG_DrawFrame(vid.buffer)
    return
}
[export, sideeffects]
def D_BeginDirectRect(var x : int; var y : int; var pbitmap : int; var width : int; var height : int) {
    return
}
[export, sideeffects]
def D_EndDirectRect(var x_0 : int; var y_0 : int; var width_0 : int; var height_0 : int) {
    return
}
