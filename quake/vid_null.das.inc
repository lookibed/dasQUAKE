var vid : viddef_t = default<viddef_t>

[export, sideeffects]
def VID_SetPalette(var palette : uint8?) {
    QG_SetPalette(palette)
    return
}
[export, sideeffects]
def VID_ShiftPalette(var palette_0 : uint8?) {
    QG_SetPalette(palette_0)
    return
}
[export, sideeffects]
def VID_Init(var palette_1 : uint8?) {
    vid.conwidth = 320u
    vid.width = uint(vid.conwidth)  // nolint:PERF020
    vid.maxwarpwidth = int(vid.width)
    vid.conheight = 240u
    vid.height = uint(vid.conheight)  // nolint:PERF020
    vid.maxwarpheight = int(vid.height)
    vid.aspect = 1.0
    vid.numpages = 1
    vid.colormap = unsafe(reinterpret<uint8?>(host_colormap))
    vid.fullbright = 256 - invoke(LittleLong, *unsafe(unsafe(reinterpret<int?>(vid.colormap)) + 2048))
    vid.conbuffer = unsafe(addr<uint8?>(vid_buffer[0]))
    vid.buffer = unsafe(reinterpret<uint8?>(vid.conbuffer))
    vid.conrowbytes = 320
    vid.rowbytes = uint(vid.conrowbytes)
    d_pzbuffer = unsafe(addr<int16?>(zbuffer[0]))
    surfcache_size = uint64(D_SurfaceCacheForRes(320, 240))
    surfcache = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(c2da_rt_malloc(surfcache_size)))))))
    D_InitCaches(unsafe(reinterpret<uint8?>(surfcache)), int(surfcache_size))
    QG_Init()
    return
}
var surfcache_size : uint64 = default<uint64>

var surfcache : uint8? = default<uint8?>

var zbuffer : int16[76800]

var vid_buffer : uint8[76800]

[export, sideeffects]
def VID_Shutdown() {
    c2da_rt_free(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(surfcache)))))
    return
}
[export, sideeffects]
def VID_Update(var rects : vrect_s?) {
    QG_DrawFrame(unsafe(reinterpret<uint8?>(vid.buffer)))
    return
}
[export, sideeffects]
def D_BeginDirectRect(var x : int; var y : int; var pbitmap : uint8?; var width : int; var height : int) {
    return
}
[export, sideeffects]
def D_EndDirectRect(var x_0 : int; var y_0 : int; var width_0 : int; var height_0 : int) {
    return
}
[sideeffects]
def private c2da_layout_proofs_51() {
    static_assert(typeinfo sizeof(type<vrect_s>) == 24, "C layout of vrect_s: sizeof")
    static_assert(typeinfo alignof(type<vrect_s>) == 8, "C layout of vrect_s: alignof")
    static_assert(typeinfo offsetof<x>(type<vrect_s>) == 0, "C layout of vrect_s: offsetof x")
    static_assert(typeinfo offsetof<y>(type<vrect_s>) == 4, "C layout of vrect_s: offsetof y")
    static_assert(typeinfo offsetof<width>(type<vrect_s>) == 8, "C layout of vrect_s: offsetof width")
    static_assert(typeinfo offsetof<height>(type<vrect_s>) == 12, "C layout of vrect_s: offsetof height")
    static_assert(typeinfo offsetof<pnext>(type<vrect_s>) == 16, "C layout of vrect_s: offsetof pnext")
    static_assert(typeinfo sizeof(type<vrect_t>) == 24, "C layout of vrect_t: sizeof")
    static_assert(typeinfo alignof(type<vrect_t>) == 8, "C layout of vrect_t: alignof")
    static_assert(typeinfo offsetof<x>(type<vrect_t>) == 0, "C layout of vrect_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<vrect_t>) == 4, "C layout of vrect_t: offsetof y")
    static_assert(typeinfo offsetof<width>(type<vrect_t>) == 8, "C layout of vrect_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<vrect_t>) == 12, "C layout of vrect_t: offsetof height")
    static_assert(typeinfo offsetof<pnext>(type<vrect_t>) == 16, "C layout of vrect_t: offsetof pnext")
    static_assert(typeinfo sizeof(type<viddef_t>) == 96, "C layout of viddef_t: sizeof")
    static_assert(typeinfo alignof(type<viddef_t>) == 8, "C layout of viddef_t: alignof")
    static_assert(typeinfo offsetof<buffer>(type<viddef_t>) == 0, "C layout of viddef_t: offsetof buffer")
    static_assert(typeinfo offsetof<colormap>(type<viddef_t>) == 8, "C layout of viddef_t: offsetof colormap")
    static_assert(typeinfo offsetof<colormap16>(type<viddef_t>) == 16, "C layout of viddef_t: offsetof colormap16")
    static_assert(typeinfo offsetof<fullbright>(type<viddef_t>) == 24, "C layout of viddef_t: offsetof fullbright")
    static_assert(typeinfo offsetof<rowbytes>(type<viddef_t>) == 28, "C layout of viddef_t: offsetof rowbytes")
    static_assert(typeinfo offsetof<width>(type<viddef_t>) == 32, "C layout of viddef_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<viddef_t>) == 36, "C layout of viddef_t: offsetof height")
    static_assert(typeinfo offsetof<aspect>(type<viddef_t>) == 40, "C layout of viddef_t: offsetof aspect")
    static_assert(typeinfo offsetof<numpages>(type<viddef_t>) == 44, "C layout of viddef_t: offsetof numpages")
    static_assert(typeinfo offsetof<recalc_refdef>(type<viddef_t>) == 48, "C layout of viddef_t: offsetof recalc_refdef")
    static_assert(typeinfo offsetof<conbuffer>(type<viddef_t>) == 56, "C layout of viddef_t: offsetof conbuffer")
    static_assert(typeinfo offsetof<conrowbytes>(type<viddef_t>) == 64, "C layout of viddef_t: offsetof conrowbytes")
    static_assert(typeinfo offsetof<conwidth>(type<viddef_t>) == 68, "C layout of viddef_t: offsetof conwidth")
    static_assert(typeinfo offsetof<conheight>(type<viddef_t>) == 72, "C layout of viddef_t: offsetof conheight")
    static_assert(typeinfo offsetof<maxwarpwidth>(type<viddef_t>) == 76, "C layout of viddef_t: offsetof maxwarpwidth")
    static_assert(typeinfo offsetof<maxwarpheight>(type<viddef_t>) == 80, "C layout of viddef_t: offsetof maxwarpheight")
    static_assert(typeinfo offsetof<direct>(type<viddef_t>) == 88, "C layout of viddef_t: offsetof direct")
}
