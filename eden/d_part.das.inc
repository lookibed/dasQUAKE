[export, sideeffects]
def D_DrawParticle(var pparticle : int) {
    var local : vec3_t
    var transformed : vec3_t
    var zi : float
    var pdest : int
    var pz : int
    var izi : int
    var pix : int
    var count : int
    var u : int
    var v : int
    local[0] = uint_bits_to_float(uint(c2da_mem[pparticle + 0 * 4]) | uint(c2da_mem[pparticle + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[pparticle + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[pparticle + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[244112 + 0 * 4]) | uint(c2da_mem[244112 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 0 * 4 + 3]) << 0x18)
    local[1] = uint_bits_to_float(uint(c2da_mem[pparticle + 1 * 4]) | uint(c2da_mem[pparticle + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[pparticle + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[pparticle + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[244112 + 1 * 4]) | uint(c2da_mem[244112 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 1 * 4 + 3]) << 0x18)
    local[2] = uint_bits_to_float(uint(c2da_mem[pparticle + 2 * 4]) | uint(c2da_mem[pparticle + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[pparticle + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[pparticle + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[244112 + 2 * 4]) | uint(c2da_mem[244112 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244112 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244112 + 2 * 4 + 3]) << 0x18)
    transformed[0] = local[0] * uint_bits_to_float(uint(c2da_mem[393152 + 0 * 4]) | uint(c2da_mem[393152 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[393152 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[393152 + 0 * 4 + 3]) << 0x18) + local[1] * uint_bits_to_float(uint(c2da_mem[393152 + 1 * 4]) | uint(c2da_mem[393152 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[393152 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[393152 + 1 * 4 + 3]) << 0x18) + local[2] * uint_bits_to_float(uint(c2da_mem[393152 + 2 * 4]) | uint(c2da_mem[393152 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[393152 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[393152 + 2 * 4 + 3]) << 0x18)
    transformed[1] = local[0] * uint_bits_to_float(uint(c2da_mem[393168 + 0 * 4]) | uint(c2da_mem[393168 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[393168 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[393168 + 0 * 4 + 3]) << 0x18) + local[1] * uint_bits_to_float(uint(c2da_mem[393168 + 1 * 4]) | uint(c2da_mem[393168 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[393168 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[393168 + 1 * 4 + 3]) << 0x18) + local[2] * uint_bits_to_float(uint(c2da_mem[393168 + 2 * 4]) | uint(c2da_mem[393168 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[393168 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[393168 + 2 * 4 + 3]) << 0x18)
    transformed[2] = local[0] * r_ppn[0] + local[1] * r_ppn[1] + local[2] * r_ppn[2]
    if (double(transformed[2]) < 8.0lf) {
        return
    }
    zi = float(1.0lf / double(transformed[2]))
    u = int(double(xcenter + zi * transformed[0]) + 0.5lf)
    v = int(double(ycenter - zi * transformed[1]) + 0.5lf)
    if (v > d_vrectbottom_particle || u > d_vrectright_particle || v < d_vrecty || u < d_vrectx) {
        return
    }
    pz = d_pzbuffer + int(d_zwidth * uint(v)) * 2 + u * 2
    pdest = d_viewbuffer + int(d_scantable[v]) + u
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
            if (int(int16(uint(c2da_mem[pz + 0 * 2]) | uint(c2da_mem[pz + 0 * 2 + 1]) << 0x8)) <= izi) {
                let c2da_fresh0 : int16 = int16(izi)
                let c2da_fresh1 : uint = uint(c2da_fresh0)
                c2da_mem[pz + 0 * 2] = uint8(c2da_fresh1)
                c2da_mem[pz + 0 * 2 + 1] = uint8(c2da_fresh1 >> 0x8)
                let c2da_fresh2 : uint8 = uint8(uint_bits_to_float(uint(c2da_mem[pparticle + 12]) | uint(c2da_mem[pparticle + 13]) << 0x8 | uint(c2da_mem[pparticle + 14]) << 0x10 | uint(c2da_mem[pparticle + 15]) << 0x18))
                c2da_mem[pdest + 0] = c2da_fresh2
            }
            count--
            pz += int(d_zwidth) * 2
            pdest += int(screenwidth)
        }
    } elif (pix == 2) {
        count = 2 << d_y_aspect_shift
        while (count != 0) {
            if (int(int16(uint(c2da_mem[pz + 0 * 2]) | uint(c2da_mem[pz + 0 * 2 + 1]) << 0x8)) <= izi) {
                let c2da_fresh3 : int16 = int16(izi)
                let c2da_fresh4 : uint = uint(c2da_fresh3)
                c2da_mem[pz + 0 * 2] = uint8(c2da_fresh4)
                c2da_mem[pz + 0 * 2 + 1] = uint8(c2da_fresh4 >> 0x8)
                let c2da_fresh5 : uint8 = uint8(uint_bits_to_float(uint(c2da_mem[pparticle + 12]) | uint(c2da_mem[pparticle + 13]) << 0x8 | uint(c2da_mem[pparticle + 14]) << 0x10 | uint(c2da_mem[pparticle + 15]) << 0x18))
                c2da_mem[pdest + 0] = c2da_fresh5
            }
            if (int(int16(uint(c2da_mem[pz + 1 * 2]) | uint(c2da_mem[pz + 1 * 2 + 1]) << 0x8)) <= izi) {
                let c2da_fresh6 : int16 = int16(izi)
                let c2da_fresh7 : uint = uint(c2da_fresh6)
                c2da_mem[pz + 1 * 2] = uint8(c2da_fresh7)
                c2da_mem[pz + 1 * 2 + 1] = uint8(c2da_fresh7 >> 0x8)
                let c2da_fresh8 : uint8 = uint8(uint_bits_to_float(uint(c2da_mem[pparticle + 12]) | uint(c2da_mem[pparticle + 13]) << 0x8 | uint(c2da_mem[pparticle + 14]) << 0x10 | uint(c2da_mem[pparticle + 15]) << 0x18))
                c2da_mem[pdest + 1] = c2da_fresh8
            }
            count--
            pz += int(d_zwidth) * 2
            pdest += int(screenwidth)
        }
    } elif (pix == 3) {
        count = 3 << d_y_aspect_shift
        while (count != 0) {
            if (int(int16(uint(c2da_mem[pz + 0 * 2]) | uint(c2da_mem[pz + 0 * 2 + 1]) << 0x8)) <= izi) {
                let c2da_fresh9 : int16 = int16(izi)
                let c2da_fresh10 : uint = uint(c2da_fresh9)
                c2da_mem[pz + 0 * 2] = uint8(c2da_fresh10)
                c2da_mem[pz + 0 * 2 + 1] = uint8(c2da_fresh10 >> 0x8)
                let c2da_fresh11 : uint8 = uint8(uint_bits_to_float(uint(c2da_mem[pparticle + 12]) | uint(c2da_mem[pparticle + 13]) << 0x8 | uint(c2da_mem[pparticle + 14]) << 0x10 | uint(c2da_mem[pparticle + 15]) << 0x18))
                c2da_mem[pdest + 0] = c2da_fresh11
            }
            if (int(int16(uint(c2da_mem[pz + 1 * 2]) | uint(c2da_mem[pz + 1 * 2 + 1]) << 0x8)) <= izi) {
                let c2da_fresh12 : int16 = int16(izi)
                let c2da_fresh13 : uint = uint(c2da_fresh12)
                c2da_mem[pz + 1 * 2] = uint8(c2da_fresh13)
                c2da_mem[pz + 1 * 2 + 1] = uint8(c2da_fresh13 >> 0x8)
                let c2da_fresh14 : uint8 = uint8(uint_bits_to_float(uint(c2da_mem[pparticle + 12]) | uint(c2da_mem[pparticle + 13]) << 0x8 | uint(c2da_mem[pparticle + 14]) << 0x10 | uint(c2da_mem[pparticle + 15]) << 0x18))
                c2da_mem[pdest + 1] = c2da_fresh14
            }
            if (int(int16(uint(c2da_mem[pz + 2 * 2]) | uint(c2da_mem[pz + 2 * 2 + 1]) << 0x8)) <= izi) {
                let c2da_fresh15 : int16 = int16(izi)
                let c2da_fresh16 : uint = uint(c2da_fresh15)
                c2da_mem[pz + 2 * 2] = uint8(c2da_fresh16)
                c2da_mem[pz + 2 * 2 + 1] = uint8(c2da_fresh16 >> 0x8)
                let c2da_fresh17 : uint8 = uint8(uint_bits_to_float(uint(c2da_mem[pparticle + 12]) | uint(c2da_mem[pparticle + 13]) << 0x8 | uint(c2da_mem[pparticle + 14]) << 0x10 | uint(c2da_mem[pparticle + 15]) << 0x18))
                c2da_mem[pdest + 2] = c2da_fresh17
            }
            count--
            pz += int(d_zwidth) * 2
            pdest += int(screenwidth)
        }
    } elif (pix == 4) {
        count = 4 << d_y_aspect_shift
        while (count != 0) {
            if (int(int16(uint(c2da_mem[pz + 0 * 2]) | uint(c2da_mem[pz + 0 * 2 + 1]) << 0x8)) <= izi) {
                let c2da_fresh18 : int16 = int16(izi)
                let c2da_fresh19 : uint = uint(c2da_fresh18)
                c2da_mem[pz + 0 * 2] = uint8(c2da_fresh19)
                c2da_mem[pz + 0 * 2 + 1] = uint8(c2da_fresh19 >> 0x8)
                let c2da_fresh20 : uint8 = uint8(uint_bits_to_float(uint(c2da_mem[pparticle + 12]) | uint(c2da_mem[pparticle + 13]) << 0x8 | uint(c2da_mem[pparticle + 14]) << 0x10 | uint(c2da_mem[pparticle + 15]) << 0x18))
                c2da_mem[pdest + 0] = c2da_fresh20
            }
            if (int(int16(uint(c2da_mem[pz + 1 * 2]) | uint(c2da_mem[pz + 1 * 2 + 1]) << 0x8)) <= izi) {
                let c2da_fresh21 : int16 = int16(izi)
                let c2da_fresh22 : uint = uint(c2da_fresh21)
                c2da_mem[pz + 1 * 2] = uint8(c2da_fresh22)
                c2da_mem[pz + 1 * 2 + 1] = uint8(c2da_fresh22 >> 0x8)
                let c2da_fresh23 : uint8 = uint8(uint_bits_to_float(uint(c2da_mem[pparticle + 12]) | uint(c2da_mem[pparticle + 13]) << 0x8 | uint(c2da_mem[pparticle + 14]) << 0x10 | uint(c2da_mem[pparticle + 15]) << 0x18))
                c2da_mem[pdest + 1] = c2da_fresh23
            }
            if (int(int16(uint(c2da_mem[pz + 2 * 2]) | uint(c2da_mem[pz + 2 * 2 + 1]) << 0x8)) <= izi) {
                let c2da_fresh24 : int16 = int16(izi)
                let c2da_fresh25 : uint = uint(c2da_fresh24)
                c2da_mem[pz + 2 * 2] = uint8(c2da_fresh25)
                c2da_mem[pz + 2 * 2 + 1] = uint8(c2da_fresh25 >> 0x8)
                let c2da_fresh26 : uint8 = uint8(uint_bits_to_float(uint(c2da_mem[pparticle + 12]) | uint(c2da_mem[pparticle + 13]) << 0x8 | uint(c2da_mem[pparticle + 14]) << 0x10 | uint(c2da_mem[pparticle + 15]) << 0x18))
                c2da_mem[pdest + 2] = c2da_fresh26
            }
            if (int(int16(uint(c2da_mem[pz + 3 * 2]) | uint(c2da_mem[pz + 3 * 2 + 1]) << 0x8)) <= izi) {
                let c2da_fresh27 : int16 = int16(izi)
                let c2da_fresh28 : uint = uint(c2da_fresh27)
                c2da_mem[pz + 3 * 2] = uint8(c2da_fresh28)
                c2da_mem[pz + 3 * 2 + 1] = uint8(c2da_fresh28 >> 0x8)
                let c2da_fresh29 : uint8 = uint8(uint_bits_to_float(uint(c2da_mem[pparticle + 12]) | uint(c2da_mem[pparticle + 13]) << 0x8 | uint(c2da_mem[pparticle + 14]) << 0x10 | uint(c2da_mem[pparticle + 15]) << 0x18))
                c2da_mem[pdest + 3] = c2da_fresh29
            }
            count--
            pz += int(d_zwidth) * 2
            pdest += int(screenwidth)
        }
    } else {
        count = pix << d_y_aspect_shift
        while (count != 0) {
            for (i in range(0, pix)) {
                if (int(int16(uint(c2da_mem[pz + i * 2]) | uint(c2da_mem[pz + i * 2 + 1]) << 0x8)) <= izi) {
                    let c2da_fresh30 : int16 = int16(izi)
                    let c2da_fresh31 : uint = uint(c2da_fresh30)
                    c2da_mem[pz + i * 2] = uint8(c2da_fresh31)
                    c2da_mem[pz + i * 2 + 1] = uint8(c2da_fresh31 >> 0x8)
                    let c2da_fresh32 : uint8 = uint8(uint_bits_to_float(uint(c2da_mem[pparticle + 12]) | uint(c2da_mem[pparticle + 13]) << 0x8 | uint(c2da_mem[pparticle + 14]) << 0x10 | uint(c2da_mem[pparticle + 15]) << 0x18))
                    c2da_mem[pdest + i] = c2da_fresh32
                }
            }
            count--
            pz += int(d_zwidth) * 2
            pdest += int(screenwidth)
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
