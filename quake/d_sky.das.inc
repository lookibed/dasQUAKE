[export, sideeffects]
def D_DrawSkyScans8(var pspan : espan_s?) {
    var count : int
    var spancount : int
    var u : int
    var v : int
    var pdest : uint8?
    var s : int
    var t : int
    var snext : int
    var tnext : int
    var sstep : int
    var tstep : int
    var spancountminus1 : int
    sstep = 0
    tstep = 0
    while (true) {
        pdest = unsafe(reinterpret<uint8?>(unsafe(unsafe(d_viewbuffer + int64(screenwidth * pspan.v)) + pspan.u)))
        count = pspan.count
        u = pspan.u
        v = pspan.v
        D_Sky_uv_To_st(u, v, unsafe(addr<int?>(s)), unsafe(addr<int?>(t)))
        while (true) {
            if (count >= 1 << 5) {
                spancount = 1 << 5
            } else {
                spancount = count
            }
            count -= spancount
            if (count != 0) {
                u += spancount
                D_Sky_uv_To_st(u, v, unsafe(addr<int?>(snext)), unsafe(addr<int?>(tnext)))
                sstep = snext - s >> 5
                tstep = tnext - t >> 5
            } else {
                spancountminus1 = int(float(spancount - 1))
                if (spancountminus1 > 0) {
                    u += spancountminus1
                    D_Sky_uv_To_st(u, v, unsafe(addr<int?>(snext)), unsafe(addr<int?>(tnext)))
                    sstep = (snext - s) / spancountminus1
                    tstep = (tnext - t) / spancountminus1
                }
            }
            var c2da_pdest_addr : uint64 = unsafe(reinterpret<uint64>(pdest))
            while (true) {
                *unsafe(reinterpret<uint8?>(c2da_pdest_addr)) = uint8(unsafe(r_skysource[((t & 8323072) >> 8) + ((s & 8323072) >> 16)]))
                c2da_pdest_addr++
                s += sstep
                t += tstep
                spancount--
                if (spancount <= 0) {
                    break
                }
            }
            pdest = unsafe(reinterpret<uint8?>(c2da_pdest_addr))
            s = snext
            t = tnext
            if (count <= 0) {
                break
            }
        }
        pspan = unsafe(reinterpret<espan_s?>(pspan.pnext))
        if (pspan == null) {
            break
        }
    }
    return
}
[export, sideeffects]
def D_Sky_uv_To_st(var u_0 : int; var v_0 : int; var s_0 : int?; var t_0 : int?) {
    var wu : float
    var wv : float
    var temp : float
    var end : vec3_t
    if (r_refdef.vrect.width >= r_refdef.vrect.height) {
        temp = float(r_refdef.vrect.width)
    } else {
        temp = float(r_refdef.vrect.height)
    }
    wu = float(8192.0lf * double(float(u_0 - (int(vid.width) >> 1))) / double(temp))
    wv = float(8192.0lf * double(float((int(vid.height) >> 1) - v_0)) / double(temp))
    unsafe(unsafe(addr(end[0]))[0]) = 4096.0 * unsafe(unsafe(addr(vpn[0]))[0]) + wu * unsafe(unsafe(addr(vright[0]))[0]) + wv * unsafe(unsafe(addr(vup[0]))[0])
    unsafe(unsafe(addr(end[0]))[1]) = 4096.0 * unsafe(unsafe(addr(vpn[0]))[1]) + wu * unsafe(unsafe(addr(vright[0]))[1]) + wv * unsafe(unsafe(addr(vup[0]))[1])
    unsafe(unsafe(addr(end[0]))[2]) = 4096.0 * unsafe(unsafe(addr(vpn[0]))[2]) + wu * unsafe(unsafe(addr(vright[0]))[2]) + wv * unsafe(unsafe(addr(vup[0]))[2])
    unsafe(unsafe(addr(end[0]))[2]) *= 3.0
    VectorNormalize(unsafe(addr<float?>(end[0])))
    temp = skytime * skyspeed
    *s_0 = int((temp + float(6 * ((1 << 7) / 2 - 1)) * unsafe(unsafe(addr(end[0]))[0])) * 65536.0)
    *t_0 = int((temp + float(6 * ((1 << 7) / 2 - 1)) * unsafe(unsafe(addr(end[0]))[1])) * 65536.0)
    return
}
[sideeffects]
def private c2da_layout_proofs_15() {
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
    static_assert(typeinfo sizeof(type<refdef_t>) == 160, "C layout of refdef_t: sizeof")
    static_assert(typeinfo alignof(type<refdef_t>) == 8, "C layout of refdef_t: alignof")
    static_assert(typeinfo offsetof<vrect>(type<refdef_t>) == 0, "C layout of refdef_t: offsetof vrect")
    static_assert(typeinfo offsetof<aliasvrect>(type<refdef_t>) == 24, "C layout of refdef_t: offsetof aliasvrect")
    static_assert(typeinfo offsetof<vrectright>(type<refdef_t>) == 48, "C layout of refdef_t: offsetof vrectright")
    static_assert(typeinfo offsetof<vrectbottom>(type<refdef_t>) == 52, "C layout of refdef_t: offsetof vrectbottom")
    static_assert(typeinfo offsetof<aliasvrectright>(type<refdef_t>) == 56, "C layout of refdef_t: offsetof aliasvrectright")
    static_assert(typeinfo offsetof<aliasvrectbottom>(type<refdef_t>) == 60, "C layout of refdef_t: offsetof aliasvrectbottom")
    static_assert(typeinfo offsetof<vrectrightedge>(type<refdef_t>) == 64, "C layout of refdef_t: offsetof vrectrightedge")
    static_assert(typeinfo offsetof<fvrectx>(type<refdef_t>) == 68, "C layout of refdef_t: offsetof fvrectx")
    static_assert(typeinfo offsetof<fvrecty>(type<refdef_t>) == 72, "C layout of refdef_t: offsetof fvrecty")
    static_assert(typeinfo offsetof<fvrectx_adj>(type<refdef_t>) == 76, "C layout of refdef_t: offsetof fvrectx_adj")
    static_assert(typeinfo offsetof<fvrecty_adj>(type<refdef_t>) == 80, "C layout of refdef_t: offsetof fvrecty_adj")
    static_assert(typeinfo offsetof<vrect_x_adj_shift20>(type<refdef_t>) == 84, "C layout of refdef_t: offsetof vrect_x_adj_shift20")
    static_assert(typeinfo offsetof<vrectright_adj_shift20>(type<refdef_t>) == 88, "C layout of refdef_t: offsetof vrectright_adj_shift20")
    static_assert(typeinfo offsetof<fvrectright_adj>(type<refdef_t>) == 92, "C layout of refdef_t: offsetof fvrectright_adj")
    static_assert(typeinfo offsetof<fvrectbottom_adj>(type<refdef_t>) == 96, "C layout of refdef_t: offsetof fvrectbottom_adj")
    static_assert(typeinfo offsetof<fvrectright>(type<refdef_t>) == 100, "C layout of refdef_t: offsetof fvrectright")
    static_assert(typeinfo offsetof<fvrectbottom>(type<refdef_t>) == 104, "C layout of refdef_t: offsetof fvrectbottom")
    static_assert(typeinfo offsetof<horizontalFieldOfView>(type<refdef_t>) == 108, "C layout of refdef_t: offsetof horizontalFieldOfView")
    static_assert(typeinfo offsetof<xOrigin>(type<refdef_t>) == 112, "C layout of refdef_t: offsetof xOrigin")
    static_assert(typeinfo offsetof<yOrigin>(type<refdef_t>) == 116, "C layout of refdef_t: offsetof yOrigin")
    static_assert(typeinfo offsetof<vieworg>(type<refdef_t>) == 120, "C layout of refdef_t: offsetof vieworg")
    static_assert(typeinfo offsetof<viewangles>(type<refdef_t>) == 132, "C layout of refdef_t: offsetof viewangles")
    static_assert(typeinfo offsetof<fov_x>(type<refdef_t>) == 144, "C layout of refdef_t: offsetof fov_x")
    static_assert(typeinfo offsetof<fov_y>(type<refdef_t>) == 148, "C layout of refdef_t: offsetof fov_y")
    static_assert(typeinfo offsetof<ambientlight>(type<refdef_t>) == 152, "C layout of refdef_t: offsetof ambientlight")
    static_assert(typeinfo sizeof(type<espan_s>) == 24, "C layout of espan_s: sizeof")
    static_assert(typeinfo alignof(type<espan_s>) == 8, "C layout of espan_s: alignof")
    static_assert(typeinfo offsetof<u>(type<espan_s>) == 0, "C layout of espan_s: offsetof u")
    static_assert(typeinfo offsetof<v>(type<espan_s>) == 4, "C layout of espan_s: offsetof v")
    static_assert(typeinfo offsetof<count>(type<espan_s>) == 8, "C layout of espan_s: offsetof count")
    static_assert(typeinfo offsetof<pnext>(type<espan_s>) == 16, "C layout of espan_s: offsetof pnext")
    static_assert(typeinfo sizeof(type<espan_t>) == 24, "C layout of espan_t: sizeof")
    static_assert(typeinfo alignof(type<espan_t>) == 8, "C layout of espan_t: alignof")
    static_assert(typeinfo offsetof<u>(type<espan_t>) == 0, "C layout of espan_t: offsetof u")
    static_assert(typeinfo offsetof<v>(type<espan_t>) == 4, "C layout of espan_t: offsetof v")
    static_assert(typeinfo offsetof<count>(type<espan_t>) == 8, "C layout of espan_t: offsetof count")
    static_assert(typeinfo offsetof<pnext>(type<espan_t>) == 16, "C layout of espan_t: offsetof pnext")
}
