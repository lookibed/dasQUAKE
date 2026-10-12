[export, sideeffects]
def D_DrawParticle(var pparticle : particle_s?) {
    var local : vec3_t
    var transformed : vec3_t
    var zi : float
    var pdest : uint8?
    var pz : int16?
    var izi : int
    var pix : int
    var count : int
    var u : int
    var v : int
    var c2da_fresh0 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pparticle))))
    unsafe(unsafe(addr(local[0]))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh0))[0]) - unsafe(unsafe(addr(r_origin[0]))[0])
    var c2da_fresh1 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pparticle))))
    unsafe(unsafe(addr(local[0]))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh1))[1]) - unsafe(unsafe(addr(r_origin[0]))[1])
    var c2da_fresh2 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pparticle))))
    unsafe(unsafe(addr(local[0]))[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh2))[2]) - unsafe(unsafe(addr(r_origin[0]))[2])
    unsafe(unsafe(addr(transformed[0]))[0]) = unsafe(unsafe(addr(local[0]))[0]) * unsafe(unsafe(addr(r_pright[0]))[0]) + unsafe(unsafe(addr(local[0]))[1]) * unsafe(unsafe(addr(r_pright[0]))[1]) + unsafe(unsafe(addr(local[0]))[2]) * unsafe(unsafe(addr(r_pright[0]))[2])
    unsafe(unsafe(addr(transformed[0]))[1]) = unsafe(unsafe(addr(local[0]))[0]) * unsafe(unsafe(addr(r_pup[0]))[0]) + unsafe(unsafe(addr(local[0]))[1]) * unsafe(unsafe(addr(r_pup[0]))[1]) + unsafe(unsafe(addr(local[0]))[2]) * unsafe(unsafe(addr(r_pup[0]))[2])
    unsafe(unsafe(addr(transformed[0]))[2]) = unsafe(unsafe(addr(local[0]))[0]) * unsafe(unsafe(addr(r_ppn[0]))[0]) + unsafe(unsafe(addr(local[0]))[1]) * unsafe(unsafe(addr(r_ppn[0]))[1]) + unsafe(unsafe(addr(local[0]))[2]) * unsafe(unsafe(addr(r_ppn[0]))[2])
    if (double(unsafe(unsafe(addr(transformed[0]))[2])) < 8.0lf) {
        return
    }
    zi = float(1.0lf / double(unsafe(unsafe(addr(transformed[0]))[2])))
    u = int(double(xcenter + zi * unsafe(unsafe(addr(transformed[0]))[0])) + 0.5lf)
    v = int(double(ycenter - zi * unsafe(unsafe(addr(transformed[0]))[1])) + 0.5lf)
    if (v > d_vrectbottom_particle || u > d_vrectright_particle || v < d_vrecty || u < d_vrectx) {
        return
    }
    pz = unsafe(reinterpret<int16?>(unsafe(unsafe(d_pzbuffer + int64(d_zwidth * uint(v))) + u)))
    pdest = unsafe(reinterpret<uint8?>(unsafe(unsafe(d_viewbuffer + int(d_scantable[v])) + u)))
    izi = int(zi * 32768.0)
    pix = izi >> d_pix_shift
    if (pix < d_pix_min) {
        pix = d_pix_min
    } elif (pix > d_pix_max) {
        pix = d_pix_max
    }
    if (pix == 1) {
        count = 1 << d_y_aspect_shift
        while (count != 0) {
            if (int(unsafe(pz[0])) <= izi) {
                unsafe(pz[0]) = int16(izi)
                unsafe(pdest[0]) = uint8(pparticle.color)
            }
            count--
            unsafe {  // nolint:STYLE025
                pz += int64(d_zwidth)
            }
            unsafe {  // nolint:STYLE025
                pdest += int64(screenwidth)
            }
        }
    } elif (pix == 2) {
        count = 2 << d_y_aspect_shift
        while (count != 0) {
            if (int(unsafe(pz[0])) <= izi) {
                unsafe(pz[0]) = int16(izi)
                unsafe(pdest[0]) = uint8(pparticle.color)
            }
            if (int(unsafe(pz[1])) <= izi) {
                unsafe(pz[1]) = int16(izi)
                unsafe(pdest[1]) = uint8(pparticle.color)
            }
            count--
            unsafe {  // nolint:STYLE025
                pz += int64(d_zwidth)
            }
            unsafe {  // nolint:STYLE025
                pdest += int64(screenwidth)
            }
        }
    } elif (pix == 3) {
        count = 3 << d_y_aspect_shift
        while (count != 0) {
            if (int(unsafe(pz[0])) <= izi) {
                unsafe(pz[0]) = int16(izi)
                unsafe(pdest[0]) = uint8(pparticle.color)
            }
            if (int(unsafe(pz[1])) <= izi) {
                unsafe(pz[1]) = int16(izi)
                unsafe(pdest[1]) = uint8(pparticle.color)
            }
            if (int(unsafe(pz[2])) <= izi) {
                unsafe(pz[2]) = int16(izi)
                unsafe(pdest[2]) = uint8(pparticle.color)
            }
            count--
            unsafe {  // nolint:STYLE025
                pz += int64(d_zwidth)
            }
            unsafe {  // nolint:STYLE025
                pdest += int64(screenwidth)
            }
        }
    } elif (pix == 4) {
        count = 4 << d_y_aspect_shift
        while (count != 0) {
            if (int(unsafe(pz[0])) <= izi) {
                unsafe(pz[0]) = int16(izi)
                unsafe(pdest[0]) = uint8(pparticle.color)
            }
            if (int(unsafe(pz[1])) <= izi) {
                unsafe(pz[1]) = int16(izi)
                unsafe(pdest[1]) = uint8(pparticle.color)
            }
            if (int(unsafe(pz[2])) <= izi) {
                unsafe(pz[2]) = int16(izi)
                unsafe(pdest[2]) = uint8(pparticle.color)
            }
            if (int(unsafe(pz[3])) <= izi) {
                unsafe(pz[3]) = int16(izi)
                unsafe(pdest[3]) = uint8(pparticle.color)
            }
            count--
            unsafe {  // nolint:STYLE025
                pz += int64(d_zwidth)
            }
            unsafe {  // nolint:STYLE025
                pdest += int64(screenwidth)
            }
        }
    } else {
        count = pix << d_y_aspect_shift
        while (count != 0) {
            for (i in range(0, pix)) {
                if (int(unsafe(pz[i])) <= izi) {
                    unsafe(pz[i]) = int16(izi)
                    unsafe(pdest[i]) = uint8(pparticle.color)
                }
            }
            count--
            unsafe {  // nolint:STYLE025
                pz += int64(d_zwidth)
            }
            unsafe {  // nolint:STYLE025
                pdest += int64(screenwidth)
            }
        }
    }
    return
}
[export, sideeffects]
def D_EndParticles() {
    return
}
[export, sideeffects]
def D_StartParticles() {
    return
}
[sideeffects]
def private c2da_layout_proofs_12() {
    static_assert(typeinfo sizeof(type<particle_s>) == 48, "C layout of particle_s: sizeof")
    static_assert(typeinfo alignof(type<particle_s>) == 8, "C layout of particle_s: alignof")
    static_assert(typeinfo offsetof<org>(type<particle_s>) == 0, "C layout of particle_s: offsetof org")
    static_assert(typeinfo offsetof<color>(type<particle_s>) == 12, "C layout of particle_s: offsetof color")
    static_assert(typeinfo offsetof<next>(type<particle_s>) == 16, "C layout of particle_s: offsetof next")
    static_assert(typeinfo offsetof<vel>(type<particle_s>) == 24, "C layout of particle_s: offsetof vel")
    static_assert(typeinfo offsetof<ramp>(type<particle_s>) == 36, "C layout of particle_s: offsetof ramp")
    static_assert(typeinfo offsetof<die>(type<particle_s>) == 40, "C layout of particle_s: offsetof die")
    static_assert(typeinfo offsetof<type_0>(type<particle_s>) == 44, "C layout of particle_s: offsetof type_0")
    static_assert(typeinfo sizeof(type<particle_t>) == 48, "C layout of particle_t: sizeof")
    static_assert(typeinfo alignof(type<particle_t>) == 8, "C layout of particle_t: alignof")
    static_assert(typeinfo offsetof<org>(type<particle_t>) == 0, "C layout of particle_t: offsetof org")
    static_assert(typeinfo offsetof<color>(type<particle_t>) == 12, "C layout of particle_t: offsetof color")
    static_assert(typeinfo offsetof<next>(type<particle_t>) == 16, "C layout of particle_t: offsetof next")
    static_assert(typeinfo offsetof<vel>(type<particle_t>) == 24, "C layout of particle_t: offsetof vel")
    static_assert(typeinfo offsetof<ramp>(type<particle_t>) == 36, "C layout of particle_t: offsetof ramp")
    static_assert(typeinfo offsetof<die>(type<particle_t>) == 40, "C layout of particle_t: offsetof die")
    static_assert(typeinfo offsetof<type_0>(type<particle_t>) == 44, "C layout of particle_t: offsetof type_0")
}
