var private c2da_str_d_init_0 : array<int8> = [int8(100), int8(95), int8(109), int8(105), int8(112), int8(115), int8(99), int8(97), int8(108), int8(101), int8(0)]

var private c2da_str_d_init_1 : array<int8> = [int8(49), int8(0)]

var private c2da_str_d_init_2 : array<int8> = [int8(100), int8(95), int8(109), int8(105), int8(112), int8(99), int8(97), int8(112), int8(0)]

var private c2da_str_d_init_3 : array<int8> = [int8(48), int8(0)]

var private c2da_str_d_init_4 : array<int8> = [int8(100), int8(95), int8(115), int8(117), int8(98), int8(100), int8(105), int8(118), int8(49), int8(54), int8(0)]

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
    Cvar_RegisterVariable(unsafe(addr<cvar_s?>(d_subdiv16)))
    Cvar_RegisterVariable(unsafe(addr<cvar_s?>(d_mipcap)))
    Cvar_RegisterVariable(unsafe(addr<cvar_s?>(d_mipscale)))
    r_drawpolys = unsafe(reinterpret<qboolean>(0u))
    r_worldpolysbacktofront = unsafe(reinterpret<qboolean>(0u))
    r_recursiveaffinetriangles = unsafe(reinterpret<qboolean>(1u))
    r_aliasuvscale = 1.0
    return
}
var d_mipscale : cvar_s = cvar_s(name = unsafe(addr(c2da_str_d_init_0[0])), string_0 = unsafe(addr(c2da_str_d_init_1[0])), archive = qboolean(), server = qboolean(), value = 0.0, next = null)

var d_mipcap : cvar_s = cvar_s(name = unsafe(addr(c2da_str_d_init_2[0])), string_0 = unsafe(addr(c2da_str_d_init_3[0])), archive = qboolean(), server = qboolean(), value = 0.0, next = null)

var d_subdiv16 : cvar_s = cvar_s(name = unsafe(addr(c2da_str_d_init_4[0])), string_0 = unsafe(addr(c2da_str_d_init_1[0])), archive = qboolean(), server = qboolean(), value = 0.0, next = null)

[export, sideeffects]
def D_SetupFrame() {
    if (uint(r_dowarp) != 0u) {
        d_viewbuffer = unsafe(reinterpret<uint8?>(r_warpbuffer))
    } else {
        d_viewbuffer = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(vid.buffer))))
    }
    if (uint(r_dowarp) != 0u) {
        screenwidth = 320
    } else {
        screenwidth = int(vid.rowbytes)
    }
    d_roverwrapped = unsafe(reinterpret<qboolean>(0u))
    d_initial_rover = unsafe(reinterpret<surfcache_s?>(sc_rover))
    d_minmip = int(d_mipcap.value)
    if (d_minmip > 3) {
        d_minmip = 3
    } elif (d_minmip < 0) {
        d_minmip = 0
    }
    for (i in range(0, 4 - 1)) {
        d_scalemip[i] = basemip[i] * d_mipscale.value
    }
    d_drawspans = @@D_DrawSpans8
    d_aflatcolor = 0
    return
}
var d_drawspans : function<(var _arg0:espan_s?):void> = default<function<(var _arg0:espan_s?):void>>

var private basemip : float[3] = fixed_array<float>(1.0, float(0.5lf * 0.8lf), float(0.25lf * 0.8lf))

var d_scalemip : float[3]

var d_minmip : int = default<int>

var d_initial_rover : surfcache_s? = default<surfcache_s?>

var d_roverwrapped : qboolean = default<qboolean>

[export, sideeffects]
def D_TurnZOn() {
    return
}
[export, sideeffects]
def D_UpdateRects(var prect : vrect_s?) {
    prect = unsafe(reinterpret<vrect_s?>(prect))
    return
}
[export, sideeffects]
def D_CopyRects(var prects : vrect_s?; var transparent : int) {
    prects = unsafe(reinterpret<vrect_s?>(prects))
    transparent = int(transparent)  // nolint:PERF020
    return
}
[sideeffects]
def private c2da_layout_proofs_10() {
    static_assert(typeinfo sizeof(type<cvar_s>) == 40, "C layout of cvar_s: sizeof")
    static_assert(typeinfo alignof(type<cvar_s>) == 8, "C layout of cvar_s: alignof")
    static_assert(typeinfo offsetof<name>(type<cvar_s>) == 0, "C layout of cvar_s: offsetof name")
    static_assert(typeinfo offsetof<string_0>(type<cvar_s>) == 8, "C layout of cvar_s: offsetof string_0")
    static_assert(typeinfo offsetof<archive>(type<cvar_s>) == 16, "C layout of cvar_s: offsetof archive")
    static_assert(typeinfo offsetof<server>(type<cvar_s>) == 20, "C layout of cvar_s: offsetof server")
    static_assert(typeinfo offsetof<value>(type<cvar_s>) == 24, "C layout of cvar_s: offsetof value")
    static_assert(typeinfo offsetof<next>(type<cvar_s>) == 32, "C layout of cvar_s: offsetof next")
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
    static_assert(typeinfo sizeof(type<cvar_t>) == 40, "C layout of cvar_t: sizeof")
    static_assert(typeinfo alignof(type<cvar_t>) == 8, "C layout of cvar_t: alignof")
    static_assert(typeinfo offsetof<name>(type<cvar_t>) == 0, "C layout of cvar_t: offsetof name")
    static_assert(typeinfo offsetof<string_0>(type<cvar_t>) == 8, "C layout of cvar_t: offsetof string_0")
    static_assert(typeinfo offsetof<archive>(type<cvar_t>) == 16, "C layout of cvar_t: offsetof archive")
    static_assert(typeinfo offsetof<server>(type<cvar_t>) == 20, "C layout of cvar_t: offsetof server")
    static_assert(typeinfo offsetof<value>(type<cvar_t>) == 24, "C layout of cvar_t: offsetof value")
    static_assert(typeinfo offsetof<next>(type<cvar_t>) == 32, "C layout of cvar_t: offsetof next")
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
    static_assert(typeinfo sizeof(type<surfcache_s>) == 72, "C layout of surfcache_s: sizeof")
    static_assert(typeinfo alignof(type<surfcache_s>) == 8, "C layout of surfcache_s: alignof")
    static_assert(typeinfo offsetof<next>(type<surfcache_s>) == 0, "C layout of surfcache_s: offsetof next")
    static_assert(typeinfo offsetof<owner>(type<surfcache_s>) == 8, "C layout of surfcache_s: offsetof owner")
    static_assert(typeinfo offsetof<lightadj>(type<surfcache_s>) == 16, "C layout of surfcache_s: offsetof lightadj")
    static_assert(typeinfo offsetof<dlight>(type<surfcache_s>) == 32, "C layout of surfcache_s: offsetof dlight")
    static_assert(typeinfo offsetof<size>(type<surfcache_s>) == 36, "C layout of surfcache_s: offsetof size")
    static_assert(typeinfo offsetof<width>(type<surfcache_s>) == 40, "C layout of surfcache_s: offsetof width")
    static_assert(typeinfo offsetof<height>(type<surfcache_s>) == 44, "C layout of surfcache_s: offsetof height")
    static_assert(typeinfo offsetof<mipscale>(type<surfcache_s>) == 48, "C layout of surfcache_s: offsetof mipscale")
    static_assert(typeinfo offsetof<texture>(type<surfcache_s>) == 56, "C layout of surfcache_s: offsetof texture")
    static_assert(typeinfo offsetof<data>(type<surfcache_s>) == 64, "C layout of surfcache_s: offsetof data")
    static_assert(typeinfo sizeof(type<espan_t>) == 24, "C layout of espan_t: sizeof")
    static_assert(typeinfo alignof(type<espan_t>) == 8, "C layout of espan_t: alignof")
    static_assert(typeinfo offsetof<u>(type<espan_t>) == 0, "C layout of espan_t: offsetof u")
    static_assert(typeinfo offsetof<v>(type<espan_t>) == 4, "C layout of espan_t: offsetof v")
    static_assert(typeinfo offsetof<count>(type<espan_t>) == 8, "C layout of espan_t: offsetof count")
    static_assert(typeinfo offsetof<pnext>(type<espan_t>) == 16, "C layout of espan_t: offsetof pnext")
    static_assert(typeinfo sizeof(type<espan_s>) == 24, "C layout of espan_s: sizeof")
    static_assert(typeinfo alignof(type<espan_s>) == 8, "C layout of espan_s: alignof")
    static_assert(typeinfo offsetof<u>(type<espan_s>) == 0, "C layout of espan_s: offsetof u")
    static_assert(typeinfo offsetof<v>(type<espan_s>) == 4, "C layout of espan_s: offsetof v")
    static_assert(typeinfo offsetof<count>(type<espan_s>) == 8, "C layout of espan_s: offsetof count")
    static_assert(typeinfo offsetof<pnext>(type<espan_s>) == 16, "C layout of espan_s: offsetof pnext")
    static_assert(typeinfo sizeof(type<surfcache_t>) == 72, "C layout of surfcache_t: sizeof")
    static_assert(typeinfo alignof(type<surfcache_t>) == 8, "C layout of surfcache_t: alignof")
    static_assert(typeinfo offsetof<next>(type<surfcache_t>) == 0, "C layout of surfcache_t: offsetof next")
    static_assert(typeinfo offsetof<owner>(type<surfcache_t>) == 8, "C layout of surfcache_t: offsetof owner")
    static_assert(typeinfo offsetof<lightadj>(type<surfcache_t>) == 16, "C layout of surfcache_t: offsetof lightadj")
    static_assert(typeinfo offsetof<dlight>(type<surfcache_t>) == 32, "C layout of surfcache_t: offsetof dlight")
    static_assert(typeinfo offsetof<size>(type<surfcache_t>) == 36, "C layout of surfcache_t: offsetof size")
    static_assert(typeinfo offsetof<width>(type<surfcache_t>) == 40, "C layout of surfcache_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<surfcache_t>) == 44, "C layout of surfcache_t: offsetof height")
    static_assert(typeinfo offsetof<mipscale>(type<surfcache_t>) == 48, "C layout of surfcache_t: offsetof mipscale")
    static_assert(typeinfo offsetof<texture>(type<surfcache_t>) == 56, "C layout of surfcache_t: offsetof texture")
    static_assert(typeinfo offsetof<data>(type<surfcache_t>) == 64, "C layout of surfcache_t: offsetof data")
}
