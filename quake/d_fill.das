options gen2
options solid_context = true
options stack = 4194304
module d_fill public

require dasquake_runtime
require chase_cluster
[export, sideeffects]
def D_FillRect(var rect : vrect_s?; var color : int) {
    var rx : int
    var ry : int
    var rwidth : int
    var rheight : int
    var dest : uint8?
    var ldest : uint?
    rx = rect.x
    ry = rect.y
    rwidth = rect.width
    rheight = rect.height
    if (rx < 0) {
        rwidth += rx
        rx = 0
    }
    if (ry < 0) {
        rheight += ry
        ry = 0
    }
    if (uint(rx + rwidth) > vid.width) {
        rwidth = int(vid.width - uint(rx))
    }
    if (uint(ry + rheight) > vid.height) {
        rheight = int(vid.height - uint(rx))
    }
    if (rwidth < 1 || rheight < 1) {
        return
    }
    dest = unsafe(reinterpret<uint8?>(unsafe(unsafe(vid.buffer + int64(uint(ry) * vid.rowbytes)) + rx)))
    if ((rwidth & 3) == 0 && (int64(unsafe(reinterpret<uint64>(dest))) & 3l) == 0l) {
        ldest = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint?>(dest))))
        color += color << 16
        rwidth >>= 2
        color += color << 8
        ry = 0
        for (c2da_ry in range(ry, rheight)) {
            rx = 0
            while (rx < rwidth) {
                unsafe(ldest[rx]) = uint(color)
                rx++
            }
            ldest = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint?>(unsafe(unsafe(reinterpret<uint8?>(ldest)) + int64(uint(vid.rowbytes)))))))
        }
    } else {
        ry = 0
        for (c2da_ry_0 in range(ry, rheight)) {
            rx = 0
            while (rx < rwidth) {
                unsafe(dest[rx]) = uint8(color)
                rx++
            }
            unsafe {  // nolint:STYLE025
                dest += int64(vid.rowbytes)
            }
        }
    }
    return
}
[sideeffects]
def private c2da_layout_proofs() {
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
