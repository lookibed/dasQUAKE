var private c2da_str_r_part_0 : array<int8> = [int8(45), int8(112), int8(97), int8(114), int8(116), int8(105), int8(99), int8(108), int8(101), int8(115), int8(0)]

var private c2da_str_r_part_1 : array<int8> = [int8(112), int8(97), int8(114), int8(116), int8(105), int8(99), int8(108), int8(101), int8(115), int8(0)]

var private c2da_str_r_part_2 : array<int8> = [int8(109), int8(97), int8(112), int8(115), int8(47), int8(37), int8(115), int8(46), int8(112), int8(116), int8(115), int8(0)]

var private c2da_str_r_part_3 : array<int8> = [int8(99), int8(111), int8(117), int8(108), int8(100), int8(110), int8(39), int8(116), int8(32), int8(111), int8(112), int8(101), int8(110), int8(32), int8(37), int8(115), int8(10), int8(0)]

var private c2da_str_r_part_4 : array<int8> = [int8(82), int8(101), int8(97), int8(100), int8(105), int8(110), int8(103), int8(32), int8(37), int8(115), int8(46), int8(46), int8(46), int8(10), int8(0)]

var private c2da_str_r_part_5 : array<int8> = [int8(37), int8(102), int8(32), int8(37), int8(102), int8(32), int8(37), int8(102), int8(10), int8(0)]

var private c2da_str_r_part_6 : array<int8> = [int8(78), int8(111), int8(116), int8(32), int8(101), int8(110), int8(111), int8(117), int8(103), int8(104), int8(32), int8(102), int8(114), int8(101), int8(101), int8(32), int8(112), int8(97), int8(114), int8(116), int8(105), int8(99), int8(108), int8(101), int8(115), int8(10), int8(0)]

var private c2da_str_r_part_7 : array<int8> = [int8(37), int8(105), int8(32), int8(112), int8(111), int8(105), int8(110), int8(116), int8(115), int8(32), int8(114), int8(101), int8(97), int8(100), int8(10), int8(0)]

var private R_RocketTrail__tracercount : int = 0

[export, sideeffects]
def R_ParseParticleEffect() {
    var org : vec3_t
    var dir : vec3_t
    var i : int
    var count : int
    var msgcount : int
    var color : int
    i = 0
    while (i < 3) {
        unsafe(unsafe(addr(org[0]))[i]) = MSG_ReadCoord()
        i++
    }
    i = 0
    for (c2da_i in range(i, 3)) {
        unsafe(unsafe(addr(dir[0]))[c2da_i]) = float(double(MSG_ReadChar()) * (1.0lf / 16.0lf))
    }
    msgcount = MSG_ReadByte()
    color = MSG_ReadByte()
    if (msgcount == 255) {
        count = 1024
    } else {
        count = msgcount
    }
    R_RunParticleEffect(unsafe(addr<float?>(org[0])), unsafe(addr<float?>(dir[0])), color, count)
    return
}
[export, sideeffects]
def R_RunParticleEffect(var org_0 : float?; var dir_0 : float?; var color_0 : int; var count_0 : int) {
    var j : int
    var p : particle_s?
    for (i_0 in range(0, count_0)) {
        if (free_particles == null) {
            return
        }
        p = unsafe(reinterpret<particle_s?>(free_particles))
        free_particles = unsafe(reinterpret<particle_s?>(p.next))
        p.next = active_particles
        active_particles = unsafe(reinterpret<particle_s?>(p))
        if (count_0 == 1024) {
            p.die = float(cl.time + 5.0lf)
            p.color = float(ramp1[0])
            p.ramp = float(c2da_std_rand() & 3)
            if ((i_0 & 1) != 0) {
                p.type_0 = unsafe(reinterpret<ptype_t>(4u))
                j = 0
                while (j < 3) {
                    var c2da_fresh0 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
                    unsafe(unsafe(reinterpret<float?>(c2da_fresh0))[j]) = unsafe(org_0[j]) + float(c2da_std_rand() % 32 - 16)
                    var c2da_fresh1 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p)) + 24ul))
                    unsafe(unsafe(reinterpret<float?>(c2da_fresh1))[j]) = float(c2da_std_rand() % 512 - 256)
                    j++
                }
            } else {
                p.type_0 = unsafe(reinterpret<ptype_t>(5u))
                j = 0
                while (j < 3) {
                    var c2da_fresh2 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
                    unsafe(unsafe(reinterpret<float?>(c2da_fresh2))[j]) = unsafe(org_0[j]) + float(c2da_std_rand() % 32 - 16)
                    var c2da_fresh3 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p)) + 24ul))
                    unsafe(unsafe(reinterpret<float?>(c2da_fresh3))[j]) = float(c2da_std_rand() % 512 - 256)
                    j++
                }
            }
        } else {
            p.die = float(cl.time + 0.1lf * double(c2da_std_rand() % 5))
            p.color = float((color_0 & ~7) + (c2da_std_rand() & 7))
            p.type_0 = unsafe(reinterpret<ptype_t>(2u))
            j = 0
            while (j < 3) {
                var c2da_fresh4 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh4))[j]) = unsafe(org_0[j]) + float((c2da_std_rand() & 15) - 8)
                var c2da_fresh5 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p)) + 24ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh5))[j]) = unsafe(dir_0[j]) * 15.0
                j++
            }
        }
    }
    return
}
var ramp1 : int[8] = fixed_array<int>(111, 109, 107, 105, 103, 101, 99, 97)

var active_particles : particle_s? = default<particle_s?>

var free_particles : particle_s? = default<particle_s?>

[export, sideeffects]
def R_RocketTrail(var start : float?; var end : float?; var type_0 : int) {
    var vec : vec3_t
    var len : float
    var j_0 : int
    var p_0 : particle_s?
    var dec : int
    unsafe(unsafe(addr(vec[0]))[0]) = unsafe(end[0]) - unsafe(start[0])
    unsafe(unsafe(addr(vec[0]))[1]) = unsafe(end[1]) - unsafe(start[1])
    unsafe(unsafe(addr(vec[0]))[2]) = unsafe(end[2]) - unsafe(start[2])
    len = VectorNormalize(unsafe(addr<float?>(vec[0])))
    if (type_0 < 128) {
        dec = 3
    } else {
        dec = 1
        type_0 -= 128
    }
    while (len > 0.0) {
        len -= float(dec)
        if (free_particles == null) {
            return
        }
        p_0 = unsafe(reinterpret<particle_s?>(free_particles))
        free_particles = unsafe(reinterpret<particle_s?>(p_0.next))
        p_0.next = active_particles
        active_particles = unsafe(reinterpret<particle_s?>(p_0))
        var c2da_fresh6 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0)) + 24ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh6))[0]) = unsafe(unsafe(addr(vec3_origin[0]))[0])
        var c2da_fresh7 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0)) + 24ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh7))[1]) = unsafe(unsafe(addr(vec3_origin[0]))[1])
        var c2da_fresh8 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0)) + 24ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh8))[2]) = unsafe(unsafe(addr(vec3_origin[0]))[2])
        p_0.die = float(cl.time + 2.0lf)
        if (type_0 == 0) {
            p_0.ramp = float(c2da_std_rand() & 3)
            p_0.color = float(ramp3[int(p_0.ramp)])
            p_0.type_0 = unsafe(reinterpret<ptype_t>(3u))
            j_0 = 0
            while (j_0 < 3) {
                var c2da_fresh9 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh9))[j_0]) = unsafe(start[j_0]) + float(c2da_std_rand() % 6 - 3)
                j_0++
            }
        } elif (type_0 == 1) {
            p_0.ramp = float((c2da_std_rand() & 3) + 2)
            p_0.color = float(ramp3[int(p_0.ramp)])
            p_0.type_0 = unsafe(reinterpret<ptype_t>(3u))
            j_0 = 0
            while (j_0 < 3) {
                var c2da_fresh10 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh10))[j_0]) = unsafe(start[j_0]) + float(c2da_std_rand() % 6 - 3)
                j_0++
            }
        } elif (type_0 == 2) {
            p_0.type_0 = unsafe(reinterpret<ptype_t>(1u))
            p_0.color = float(67 + (c2da_std_rand() & 3))
            j_0 = 0
            while (j_0 < 3) {
                var c2da_fresh11 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh11))[j_0]) = unsafe(start[j_0]) + float(c2da_std_rand() % 6 - 3)
                j_0++
            }
        } elif (type_0 == 3 || type_0 == 5) {
            p_0.die = float(cl.time + 0.5lf)
            p_0.type_0 = unsafe(reinterpret<ptype_t>(0u))
            if (type_0 == 3) {
                p_0.color = float(52 + ((R_RocketTrail__tracercount & 4) << 1))
            } else {
                p_0.color = float(230 + ((R_RocketTrail__tracercount & 4) << 1))
            }
            R_RocketTrail__tracercount++
            var c2da_fresh12 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0))))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh12))[0]) = float(unsafe(start[0]))  // nolint:PERF020
            var c2da_fresh13 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0))))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh13))[1]) = float(unsafe(start[1]))  // nolint:PERF020
            var c2da_fresh14 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0))))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh14))[2]) = float(unsafe(start[2]))  // nolint:PERF020
            if ((R_RocketTrail__tracercount & 1) != 0) {
                var c2da_fresh15 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0)) + 24ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh15))[0]) = 30.0 * unsafe(unsafe(addr(vec[0]))[1])
                var c2da_fresh16 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0)) + 24ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh16))[1]) = 30.0 * -unsafe(unsafe(addr(vec[0]))[0])
            } else {
                var c2da_fresh17 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0)) + 24ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh17))[0]) = 30.0 * -unsafe(unsafe(addr(vec[0]))[1])
                var c2da_fresh18 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0)) + 24ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh18))[1]) = 30.0 * unsafe(unsafe(addr(vec[0]))[0])
            }
        } elif (type_0 == 4) {
            p_0.type_0 = unsafe(reinterpret<ptype_t>(1u))
            p_0.color = float(67 + (c2da_std_rand() & 3))
            j_0 = 0
            while (j_0 < 3) {
                var c2da_fresh19 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh19))[j_0]) = unsafe(start[j_0]) + float(c2da_std_rand() % 6 - 3)
                j_0++
            }
            len -= 3.0
        } elif (type_0 == 6) {
            p_0.color = float(9 * 16 + 8 + (c2da_std_rand() & 3))
            p_0.type_0 = unsafe(reinterpret<ptype_t>(0u))
            p_0.die = float(cl.time + 0.3lf)
            j_0 = 0
            while (j_0 < 3) {
                var c2da_fresh20 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_0))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh20))[j_0]) = unsafe(start[j_0]) + float((c2da_std_rand() & 15) - 8)
                j_0++
            }
        }
        unsafe(start[0]) += unsafe(unsafe(addr(vec[0]))[0])
        unsafe(start[1]) += unsafe(unsafe(addr(vec[0]))[1])
        unsafe(start[2]) += unsafe(unsafe(addr(vec[0]))[2])
    }
    return
}
var ramp3 : int[8] = fixed_array<int>(109, 107, 6, 5, 4, 3, 0, 0)

[export, sideeffects]
def R_EntityParticles(var ent : entity_s?) {
    var count_1 : int
    var i_1 : int
    var p_1 : particle_s?
    var angle : float
    var sr : float
    var sp : float
    var sy : float
    var cr : float
    var cp : float
    var cy : float
    var forward_0 : vec3_t
    var dist : float = 64.0
    count_1 = 50
    if (unsafe(unsafe(addr(avelocities[0][0]))[0]) == 0.0) {
        i_1 = 0
        while (i_1 < 162 * 3) {
            unsafe(unsafe(addr(avelocities[0][0]))[i_1]) = float(double(c2da_std_rand() & 255) * 0.01lf)
            i_1++
        }
    }
    i_1 = 0
    for (c2da_i_1 in range(i_1, 162)) {
        angle = float(cl.time * double(unsafe(unsafe(addr(avelocities[c2da_i_1][0]))[0])))
        sy = float(sin(double(angle)))
        cy = float(cos(double(angle)))
        angle = float(cl.time * double(unsafe(unsafe(addr(avelocities[c2da_i_1][0]))[1])))
        sp = float(sin(double(angle)))
        cp = float(cos(double(angle)))
        angle = float(cl.time * double(unsafe(unsafe(addr(avelocities[c2da_i_1][0]))[2])))
        sr = float(sin(double(angle)))
        cr = float(cos(double(angle)))
        unsafe(unsafe(addr(forward_0[0]))[0]) = cp * cy
        unsafe(unsafe(addr(forward_0[0]))[1]) = cp * sy
        unsafe(unsafe(addr(forward_0[0]))[2]) = -sp
        if (free_particles == null) {
            return
        }
        p_1 = unsafe(reinterpret<particle_s?>(free_particles))
        free_particles = unsafe(reinterpret<particle_s?>(p_1.next))
        p_1.next = active_particles
        active_particles = unsafe(reinterpret<particle_s?>(p_1))
        p_1.die = float(cl.time + 0.01lf)
        p_1.color = 111.0
        p_1.type_0 = unsafe(reinterpret<ptype_t>(4u))
        var c2da_fresh21 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_1))))
        var c2da_fresh22 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 88ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh21))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh22))[0]) + r_avertexnormals[c2da_i_1][0] * dist + unsafe(unsafe(addr(forward_0[0]))[0]) * beamlength
        var c2da_fresh23 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_1))))
        var c2da_fresh24 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 88ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh23))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh24))[1]) + r_avertexnormals[c2da_i_1][1] * dist + unsafe(unsafe(addr(forward_0[0]))[1]) * beamlength
        var c2da_fresh25 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_1))))
        var c2da_fresh26 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 88ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh25))[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh26))[2]) + r_avertexnormals[c2da_i_1][2] * dist + unsafe(unsafe(addr(forward_0[0]))[2]) * beamlength
    }
    return
}
var beamlength : float = 16.0

var avelocities : vec3_t[162]

[export, sideeffects]
def R_BlobExplosion(var org_1 : float?) {
    var j_1 : int
    var p_2 : particle_s?
    for (i_2 in range(0, 1024)) {
        if (free_particles == null) {
            return
        }
        p_2 = unsafe(reinterpret<particle_s?>(free_particles))
        free_particles = unsafe(reinterpret<particle_s?>(p_2.next))
        p_2.next = active_particles
        active_particles = unsafe(reinterpret<particle_s?>(p_2))
        p_2.die = float(cl.time + 1.0lf + double(c2da_std_rand() & 8) * 0.05lf)
        if ((i_2 & 1) != 0) {
            p_2.type_0 = unsafe(reinterpret<ptype_t>(6u))
            p_2.color = float(66 + c2da_std_rand() % 6)
            j_1 = 0
            while (j_1 < 3) {
                var c2da_fresh27 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_2))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh27))[j_1]) = unsafe(org_1[j_1]) + float(c2da_std_rand() % 32 - 16)
                var c2da_fresh28 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_2)) + 24ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh28))[j_1]) = float(c2da_std_rand() % 512 - 256)
                j_1++
            }
        } else {
            p_2.type_0 = unsafe(reinterpret<ptype_t>(7u))
            p_2.color = float(150 + c2da_std_rand() % 6)
            j_1 = 0
            while (j_1 < 3) {
                var c2da_fresh29 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_2))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh29))[j_1]) = unsafe(org_1[j_1]) + float(c2da_std_rand() % 32 - 16)
                var c2da_fresh30 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_2)) + 24ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh30))[j_1]) = float(c2da_std_rand() % 512 - 256)
                j_1++
            }
        }
    }
    return
}
[export, sideeffects]
def R_ParticleExplosion(var org_2 : float?) {
    var j_2 : int
    var p_3 : particle_s?
    for (i_3 in range(0, 1024)) {
        if (free_particles == null) {
            return
        }
        p_3 = unsafe(reinterpret<particle_s?>(free_particles))
        free_particles = unsafe(reinterpret<particle_s?>(p_3.next))
        p_3.next = active_particles
        active_particles = unsafe(reinterpret<particle_s?>(p_3))
        p_3.die = float(cl.time + 5.0lf)
        p_3.color = float(ramp1[0])
        p_3.ramp = float(c2da_std_rand() & 3)
        if ((i_3 & 1) != 0) {
            p_3.type_0 = unsafe(reinterpret<ptype_t>(4u))
            j_2 = 0
            while (j_2 < 3) {
                var c2da_fresh31 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_3))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh31))[j_2]) = unsafe(org_2[j_2]) + float(c2da_std_rand() % 32 - 16)
                var c2da_fresh32 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_3)) + 24ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh32))[j_2]) = float(c2da_std_rand() % 512 - 256)
                j_2++
            }
        } else {
            p_3.type_0 = unsafe(reinterpret<ptype_t>(5u))
            j_2 = 0
            while (j_2 < 3) {
                var c2da_fresh33 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_3))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh33))[j_2]) = unsafe(org_2[j_2]) + float(c2da_std_rand() % 32 - 16)
                var c2da_fresh34 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_3)) + 24ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh34))[j_2]) = float(c2da_std_rand() % 512 - 256)
                j_2++
            }
        }
    }
    return
}
[export, sideeffects]
def R_ParticleExplosion2(var org_3 : float?; var colorStart : int; var colorLength : int) {
    var p_4 : particle_s?
    var colorMod : int = 0
    for (i_4 in range(0, 512)) {
        if (free_particles == null) {
            return
        }
        p_4 = unsafe(reinterpret<particle_s?>(free_particles))
        free_particles = unsafe(reinterpret<particle_s?>(p_4.next))
        p_4.next = active_particles
        active_particles = unsafe(reinterpret<particle_s?>(p_4))
        p_4.die = float(cl.time + 0.3lf)
        p_4.color = float(colorStart + colorMod % colorLength)
        colorMod++
        p_4.type_0 = unsafe(reinterpret<ptype_t>(6u))
        for (j_3 in range(0, 3)) {
            var c2da_fresh35 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_4))))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh35))[j_3]) = unsafe(org_3[j_3]) + float(c2da_std_rand() % 32 - 16)
            var c2da_fresh36 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_4)) + 24ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh36))[j_3]) = float(c2da_std_rand() % 512 - 256)
        }
    }
    return
}
[export, sideeffects]
def R_LavaSplash(var org_4 : float?) {
    var p_5 : particle_s?
    var vel : float
    var dir_1 : vec3_t
    for (i_5 in range(-16, 16)) {
        for (j_4 in range(-16, 16)) {
            for (k in range(0, 1)) {
                if (free_particles == null) {
                    return
                }
                p_5 = unsafe(reinterpret<particle_s?>(free_particles))
                free_particles = unsafe(reinterpret<particle_s?>(p_5.next))
                p_5.next = active_particles
                active_particles = unsafe(reinterpret<particle_s?>(p_5))
                p_5.die = float(cl.time + 2.0lf + double(c2da_std_rand() & 31) * 0.02lf)
                p_5.color = float(224 + (c2da_std_rand() & 7))
                p_5.type_0 = unsafe(reinterpret<ptype_t>(2u))
                unsafe(unsafe(addr(dir_1[0]))[0]) = float(j_4 * 8 + (c2da_std_rand() & 7))
                unsafe(unsafe(addr(dir_1[0]))[1]) = float(i_5 * 8 + (c2da_std_rand() & 7))
                unsafe(unsafe(addr(dir_1[0]))[2]) = 256.0
                var c2da_fresh37 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_5))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh37))[0]) = unsafe(org_4[0]) + unsafe(unsafe(addr(dir_1[0]))[0])
                var c2da_fresh38 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_5))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh38))[1]) = unsafe(org_4[1]) + unsafe(unsafe(addr(dir_1[0]))[1])
                var c2da_fresh39 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_5))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh39))[2]) = unsafe(org_4[2]) + float(c2da_std_rand() & 63)
                VectorNormalize(unsafe(addr<float?>(dir_1[0])))
                vel = float(50 + (c2da_std_rand() & 63))
                var c2da_fresh40 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_5)) + 24ul))
                VectorScale(unsafe(addr<float?>(dir_1[0])), vel, unsafe(reinterpret<float?>(c2da_fresh40)))
            }
        }
    }
    return
}
[export, sideeffects]
def R_TeleportSplash(var org_5 : float?) {
    var i_6 : int
    var j_5 : int
    var k_0 : int
    var p_6 : particle_s?
    var vel_0 : float
    var dir_2 : vec3_t
    i_6 = -16
    while (i_6 < 16) {
        j_5 = -16
        while (j_5 < 16) {
            k_0 = -24
            while (k_0 < 32) {
                if (free_particles == null) {
                    return
                }
                p_6 = unsafe(reinterpret<particle_s?>(free_particles))
                free_particles = unsafe(reinterpret<particle_s?>(p_6.next))
                p_6.next = active_particles
                active_particles = unsafe(reinterpret<particle_s?>(p_6))
                p_6.die = float(cl.time + 0.2lf + double(c2da_std_rand() & 7) * 0.02lf)
                p_6.color = float(7 + (c2da_std_rand() & 7))
                p_6.type_0 = unsafe(reinterpret<ptype_t>(2u))
                unsafe(unsafe(addr(dir_2[0]))[0]) = float(j_5 * 8)
                unsafe(unsafe(addr(dir_2[0]))[1]) = float(i_6 * 8)
                unsafe(unsafe(addr(dir_2[0]))[2]) = float(k_0 * 8)
                var c2da_fresh41 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_6))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh41))[0]) = unsafe(org_5[0]) + float(i_6) + float(c2da_std_rand() & 3)
                var c2da_fresh42 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_6))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh42))[1]) = unsafe(org_5[1]) + float(j_5) + float(c2da_std_rand() & 3)
                var c2da_fresh43 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_6))))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh43))[2]) = unsafe(org_5[2]) + float(k_0) + float(c2da_std_rand() & 3)
                VectorNormalize(unsafe(addr<float?>(dir_2[0])))
                vel_0 = float(50 + (c2da_std_rand() & 63))
                var c2da_fresh44 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_6)) + 24ul))
                VectorScale(unsafe(addr<float?>(dir_2[0])), vel_0, unsafe(reinterpret<float?>(c2da_fresh44)))
                k_0 += 4
            }
            j_5 += 4
        }
        i_6 += 4
    }
    return
}
var r_pright : vec3_t = default<vec3_t>

var r_pup : vec3_t = default<vec3_t>

var r_ppn : vec3_t = default<vec3_t>

[export, sideeffects]
def R_DrawParticles() {
    var c2da_fresh51 : uint
    var p_7 : particle_s?
    var kill : particle_s?
    var grav : float
    var i_7 : int
    var time2 : float
    var time3 : float
    var time1 : float
    var dvel : float
    var frametime : float
    D_StartParticles()
    VectorScale(unsafe(addr<float?>(vright[0])), xscaleshrink, unsafe(addr<float?>(r_pright[0])))
    VectorScale(unsafe(addr<float?>(vup[0])), yscaleshrink, unsafe(addr<float?>(r_pup[0])))
    unsafe(unsafe(addr(r_ppn[0]))[0]) = unsafe(unsafe(addr(vpn[0]))[0])
    unsafe(unsafe(addr(r_ppn[0]))[1]) = unsafe(unsafe(addr(vpn[0]))[1])
    unsafe(unsafe(addr(r_ppn[0]))[2]) = unsafe(unsafe(addr(vpn[0]))[2])
    frametime = float(cl.time - cl.oldtime)
    time3 = frametime * 15.0
    time2 = frametime * 10.0
    time1 = frametime * 5.0
    grav = float(double(frametime * sv_gravity.value) * 0.05lf)
    dvel = 4.0 * frametime
    while (true) {
        kill = unsafe(reinterpret<particle_s?>(active_particles))
        if (kill != null && double(kill.die) < cl.time) {
            active_particles = unsafe(reinterpret<particle_s?>(kill.next))
            kill.next = free_particles
            free_particles = unsafe(reinterpret<particle_s?>(kill))
            continue
        }
        break
    }
    p_7 = unsafe(reinterpret<particle_s?>(active_particles))
    while (p_7 != null) {
        while (true) {
            kill = unsafe(reinterpret<particle_s?>(p_7.next))
            if (kill != null && double(kill.die) < cl.time) {
                p_7.next = kill.next
                kill.next = free_particles
                free_particles = unsafe(reinterpret<particle_s?>(kill))
                continue
            }
            break
        }
        D_DrawParticle(p_7)
        var c2da_fresh45 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7))))
        var c2da_fresh46 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh45))[0]) += unsafe(unsafe(reinterpret<float?>(c2da_fresh46))[0]) * frametime
        var c2da_fresh47 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7))))
        var c2da_fresh48 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh47))[1]) += unsafe(unsafe(reinterpret<float?>(c2da_fresh48))[1]) * frametime
        var c2da_fresh49 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7))))
        var c2da_fresh50 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh49))[2]) += unsafe(unsafe(reinterpret<float?>(c2da_fresh50))[2]) * frametime
        c2da_fresh51 = uint(p_7.type_0)
        if (c2da_fresh51 == 0x0u) {
        } elif (c2da_fresh51 == 0x3u) {
            p_7.ramp += time1
            if (p_7.ramp >= 6.0) {
                p_7.die = -1.0
            } else {
                p_7.color = float(ramp3[int(p_7.ramp)])
            }
            var c2da_fresh52 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh52))[2]) += grav
        } elif (c2da_fresh51 == 0x4u) {
            p_7.ramp += time2
            if (p_7.ramp >= 8.0) {
                p_7.die = -1.0
            } else {
                p_7.color = float(ramp1[int(p_7.ramp)])
            }
            i_7 = 0
            while (i_7 < 3) {
                var c2da_fresh53 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
                var c2da_fresh54 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh53))[i_7]) += unsafe(unsafe(reinterpret<float?>(c2da_fresh54))[i_7]) * dvel
                i_7++
            }
            var c2da_fresh55 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh55))[2]) -= grav
        } elif (c2da_fresh51 == 0x5u) {
            p_7.ramp += time3
            if (p_7.ramp >= 8.0) {
                p_7.die = -1.0
            } else {
                p_7.color = float(ramp2[int(p_7.ramp)])
            }
            i_7 = 0
            while (i_7 < 3) {
                var c2da_fresh56 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
                var c2da_fresh57 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh56))[i_7]) -= unsafe(unsafe(reinterpret<float?>(c2da_fresh57))[i_7]) * frametime
                i_7++
            }
            var c2da_fresh58 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh58))[2]) -= grav
        } elif (c2da_fresh51 == 0x6u) {
            i_7 = 0
            while (i_7 < 3) {
                var c2da_fresh59 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
                var c2da_fresh60 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh59))[i_7]) += unsafe(unsafe(reinterpret<float?>(c2da_fresh60))[i_7]) * dvel
                i_7++
            }
            var c2da_fresh61 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh61))[2]) -= grav
        } elif (c2da_fresh51 == 0x7u) {
            i_7 = 0
            while (i_7 < 2) {
                var c2da_fresh62 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
                var c2da_fresh63 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh62))[i_7]) -= unsafe(unsafe(reinterpret<float?>(c2da_fresh63))[i_7]) * dvel
                i_7++
            }
            var c2da_fresh64 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh64))[2]) -= grav
        } elif (c2da_fresh51 == 0x1u || c2da_fresh51 == 0x2u) {
            var c2da_fresh65 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_7)) + 24ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh65))[2]) -= grav
        }
        p_7 = unsafe(reinterpret<particle_s?>(p_7.next))
    }
    D_EndParticles()
    return
}
var ramp2 : int[8] = fixed_array<int>(111, 110, 109, 108, 107, 106, 104, 102)

[export, sideeffects]
def R_InitParticles() {
    var i_8 : int = COM_CheckParm(unsafe(addr<int8?>(c2da_str_r_part_0[0])))
    if (i_8 != 0) {
        r_numparticles = Q_atoi(unsafe(reinterpret<int8?>(unsafe(com_argv[i_8 + 1]))))
        if (r_numparticles < 512) {
            r_numparticles = 512
        }
    } else {
        r_numparticles = 2048
    }
    particles = unsafe(reinterpret<particle_s?>(unsafe(reinterpret<particle_s?>(unsafe(reinterpret<particle_s?>(Hunk_AllocName(int(uint64(r_numparticles) * 48ul), unsafe(addr<int8?>(c2da_str_r_part_1[0])))))))))
    return
}
var r_numparticles : int = default<int>

var particles : particle_s? = default<particle_s?>

[export, sideeffects]
def R_ClearParticles() {
    var i_9 : int
    free_particles = unsafe(addr<particle_s?>(unsafe(particles[0])))
    active_particles = null
    i_9 = 0
    while (i_9 < r_numparticles) {
        unsafe(particles[i_9]).next = unsafe(addr<particle_s?>(unsafe(particles[i_9 + 1])))
        i_9++
    }
    unsafe(particles[r_numparticles - 1]).next = null
    return
}
[export, sideeffects]
def R_ReadPointFile_f() {
    var f : _IO_FILE?
    var org_6 : vec3_t
    var r : int
    var c : int
    var p_8 : particle_s?
    var name : int8[128]
    c2da_std_sprintf(unsafe(reinterpret<uint64>(unsafe(addr(name[0])))), unsafe(addr<int8 const?>(c2da_str_r_part_2[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(sv.name[0])))))])
    COM_FOpenFile(unsafe(addr<int8?>(name[0])), unsafe(addr<_IO_FILE??>(f)))
    if (f == null) {
        Con_Printf(unsafe(addr<int8?>(c2da_str_r_part_3[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(name[0])))))])
        return
    }
    Con_Printf(unsafe(addr<int8?>(c2da_str_r_part_4[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(name[0])))))])
    c = 0
    while (true) {
        r = c2da_std_fscanf(unsafe(reinterpret<uint64>(f)), unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_r_part_5[0])))), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(unsafe(unsafe(addr(org_6[0]))[0])))))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(unsafe(unsafe(addr(org_6[0]))[1])))))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(unsafe(unsafe(addr(org_6[0]))[2]))))))])
        if (r != 3) {
            break
        }
        c++
        if (free_particles == null) {
            Con_Printf(unsafe(addr<int8?>(c2da_str_r_part_6[0])), [])
            break
        }
        p_8 = unsafe(reinterpret<particle_s?>(free_particles))
        free_particles = unsafe(reinterpret<particle_s?>(p_8.next))
        p_8.next = active_particles
        active_particles = unsafe(reinterpret<particle_s?>(p_8))
        p_8.die = 99999.0
        p_8.color = float(-c & 15)
        p_8.type_0 = unsafe(reinterpret<ptype_t>(0u))
        var c2da_fresh66 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_8)) + 24ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh66))[0]) = unsafe(unsafe(addr(vec3_origin[0]))[0])
        var c2da_fresh67 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_8)) + 24ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh67))[1]) = unsafe(unsafe(addr(vec3_origin[0]))[1])
        var c2da_fresh68 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_8)) + 24ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh68))[2]) = unsafe(unsafe(addr(vec3_origin[0]))[2])
        var c2da_fresh69 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_8))))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh69))[0]) = float(unsafe(unsafe(addr(org_6[0]))[0]))  // nolint:PERF020
        var c2da_fresh70 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_8))))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh70))[1]) = float(unsafe(unsafe(addr(org_6[0]))[1]))  // nolint:PERF020
        var c2da_fresh71 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p_8))))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh71))[2]) = float(unsafe(unsafe(addr(org_6[0]))[2]))  // nolint:PERF020
    }
    c2da_std_fclose(unsafe(reinterpret<uint64>(f)))
    Con_Printf(unsafe(addr<int8?>(c2da_str_r_part_7[0])), [C2daVaArg(tag = 1, i64 = int64(c), f64 = 0.0lf, raw = 0x0)])
    return
}
var avelocity : vec3_t = fixed_array<float>(23.0, 7.0, 3.0)

var partstep : float = float(0.01lf)

var timescale : float = float(0.01lf)

[sideeffects]
def private c2da_layout_proofs_41() {
    static_assert(typeinfo sizeof(type<_IO_FILE>) == 216, "C layout of _IO_FILE: sizeof")
    static_assert(typeinfo alignof(type<_IO_FILE>) == 8, "C layout of _IO_FILE: alignof")
    static_assert(typeinfo offsetof<_flags>(type<_IO_FILE>) == 0, "C layout of _IO_FILE: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<_IO_FILE>) == 8, "C layout of _IO_FILE: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<_IO_FILE>) == 16, "C layout of _IO_FILE: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<_IO_FILE>) == 24, "C layout of _IO_FILE: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<_IO_FILE>) == 32, "C layout of _IO_FILE: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<_IO_FILE>) == 40, "C layout of _IO_FILE: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<_IO_FILE>) == 48, "C layout of _IO_FILE: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<_IO_FILE>) == 56, "C layout of _IO_FILE: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<_IO_FILE>) == 64, "C layout of _IO_FILE: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<_IO_FILE>) == 72, "C layout of _IO_FILE: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<_IO_FILE>) == 80, "C layout of _IO_FILE: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<_IO_FILE>) == 88, "C layout of _IO_FILE: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<_IO_FILE>) == 96, "C layout of _IO_FILE: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<_IO_FILE>) == 104, "C layout of _IO_FILE: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<_IO_FILE>) == 112, "C layout of _IO_FILE: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<_IO_FILE>) == 116, "C layout of _IO_FILE: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<_IO_FILE>) == 120, "C layout of _IO_FILE: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<_IO_FILE>) == 128, "C layout of _IO_FILE: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<_IO_FILE>) == 130, "C layout of _IO_FILE: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<_IO_FILE>) == 131, "C layout of _IO_FILE: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<_IO_FILE>) == 136, "C layout of _IO_FILE: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<_IO_FILE>) == 144, "C layout of _IO_FILE: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<_IO_FILE>) == 152, "C layout of _IO_FILE: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<_IO_FILE>) == 160, "C layout of _IO_FILE: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<_IO_FILE>) == 168, "C layout of _IO_FILE: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<_IO_FILE>) == 176, "C layout of _IO_FILE: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<_IO_FILE>) == 184, "C layout of _IO_FILE: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<_IO_FILE>) == 192, "C layout of _IO_FILE: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<_IO_FILE>) == 196, "C layout of _IO_FILE: offsetof _unused2")
    static_assert(typeinfo sizeof(type<FILE_0>) == 216, "C layout of FILE_0: sizeof")
    static_assert(typeinfo alignof(type<FILE_0>) == 8, "C layout of FILE_0: alignof")
    static_assert(typeinfo offsetof<_flags>(type<FILE_0>) == 0, "C layout of FILE_0: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<FILE_0>) == 8, "C layout of FILE_0: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<FILE_0>) == 16, "C layout of FILE_0: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<FILE_0>) == 24, "C layout of FILE_0: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<FILE_0>) == 32, "C layout of FILE_0: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<FILE_0>) == 40, "C layout of FILE_0: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<FILE_0>) == 48, "C layout of FILE_0: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<FILE_0>) == 56, "C layout of FILE_0: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<FILE_0>) == 64, "C layout of FILE_0: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<FILE_0>) == 72, "C layout of FILE_0: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<FILE_0>) == 80, "C layout of FILE_0: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<FILE_0>) == 88, "C layout of FILE_0: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<FILE_0>) == 96, "C layout of FILE_0: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<FILE_0>) == 104, "C layout of FILE_0: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<FILE_0>) == 112, "C layout of FILE_0: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<FILE_0>) == 116, "C layout of FILE_0: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<FILE_0>) == 120, "C layout of FILE_0: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<FILE_0>) == 128, "C layout of FILE_0: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<FILE_0>) == 130, "C layout of FILE_0: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<FILE_0>) == 131, "C layout of FILE_0: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<FILE_0>) == 136, "C layout of FILE_0: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<FILE_0>) == 144, "C layout of FILE_0: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<FILE_0>) == 152, "C layout of FILE_0: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<FILE_0>) == 160, "C layout of FILE_0: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<FILE_0>) == 168, "C layout of FILE_0: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<FILE_0>) == 176, "C layout of FILE_0: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<FILE_0>) == 184, "C layout of FILE_0: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<FILE_0>) == 192, "C layout of FILE_0: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<FILE_0>) == 196, "C layout of FILE_0: offsetof _unused2")
    static_assert(typeinfo sizeof(type<sizebuf_s>) == 24, "C layout of sizebuf_s: sizeof")
    static_assert(typeinfo alignof(type<sizebuf_s>) == 8, "C layout of sizebuf_s: alignof")
    static_assert(typeinfo offsetof<allowoverflow>(type<sizebuf_s>) == 0, "C layout of sizebuf_s: offsetof allowoverflow")
    static_assert(typeinfo offsetof<overflowed>(type<sizebuf_s>) == 4, "C layout of sizebuf_s: offsetof overflowed")
    static_assert(typeinfo offsetof<data>(type<sizebuf_s>) == 8, "C layout of sizebuf_s: offsetof data")
    static_assert(typeinfo offsetof<maxsize>(type<sizebuf_s>) == 16, "C layout of sizebuf_s: offsetof maxsize")
    static_assert(typeinfo offsetof<cursize>(type<sizebuf_s>) == 20, "C layout of sizebuf_s: offsetof cursize")
    static_assert(typeinfo sizeof(type<sizebuf_t>) == 24, "C layout of sizebuf_t: sizeof")
    static_assert(typeinfo alignof(type<sizebuf_t>) == 8, "C layout of sizebuf_t: alignof")
    static_assert(typeinfo offsetof<allowoverflow>(type<sizebuf_t>) == 0, "C layout of sizebuf_t: offsetof allowoverflow")
    static_assert(typeinfo offsetof<overflowed>(type<sizebuf_t>) == 4, "C layout of sizebuf_t: offsetof overflowed")
    static_assert(typeinfo offsetof<data>(type<sizebuf_t>) == 8, "C layout of sizebuf_t: offsetof data")
    static_assert(typeinfo offsetof<maxsize>(type<sizebuf_t>) == 16, "C layout of sizebuf_t: offsetof maxsize")
    static_assert(typeinfo offsetof<cursize>(type<sizebuf_t>) == 20, "C layout of sizebuf_t: offsetof cursize")
    static_assert(typeinfo sizeof(type<link_s>) == 16, "C layout of link_s: sizeof")
    static_assert(typeinfo alignof(type<link_s>) == 8, "C layout of link_s: alignof")
    static_assert(typeinfo offsetof<prev>(type<link_s>) == 0, "C layout of link_s: offsetof prev")
    static_assert(typeinfo offsetof<next>(type<link_s>) == 8, "C layout of link_s: offsetof next")
    static_assert(typeinfo sizeof(type<link_t>) == 16, "C layout of link_t: sizeof")
    static_assert(typeinfo alignof(type<link_t>) == 8, "C layout of link_t: alignof")
    static_assert(typeinfo offsetof<prev>(type<link_t>) == 0, "C layout of link_t: offsetof prev")
    static_assert(typeinfo offsetof<next>(type<link_t>) == 8, "C layout of link_t: offsetof next")
    static_assert(typeinfo sizeof(type<cache_user_s>) == 8, "C layout of cache_user_s: sizeof")
    static_assert(typeinfo alignof(type<cache_user_s>) == 8, "C layout of cache_user_s: alignof")
    static_assert(typeinfo offsetof<data>(type<cache_user_s>) == 0, "C layout of cache_user_s: offsetof data")
    static_assert(typeinfo sizeof(type<cvar_s>) == 40, "C layout of cvar_s: sizeof")
    static_assert(typeinfo alignof(type<cvar_s>) == 8, "C layout of cvar_s: alignof")
    static_assert(typeinfo offsetof<name>(type<cvar_s>) == 0, "C layout of cvar_s: offsetof name")
    static_assert(typeinfo offsetof<string_0>(type<cvar_s>) == 8, "C layout of cvar_s: offsetof string_0")
    static_assert(typeinfo offsetof<archive>(type<cvar_s>) == 16, "C layout of cvar_s: offsetof archive")
    static_assert(typeinfo offsetof<server>(type<cvar_s>) == 20, "C layout of cvar_s: offsetof server")
    static_assert(typeinfo offsetof<value>(type<cvar_s>) == 24, "C layout of cvar_s: offsetof value")
    static_assert(typeinfo offsetof<next>(type<cvar_s>) == 32, "C layout of cvar_s: offsetof next")
    static_assert(typeinfo sizeof(type<dmodel_t>) == 64, "C layout of dmodel_t: sizeof")
    static_assert(typeinfo alignof(type<dmodel_t>) == 4, "C layout of dmodel_t: alignof")
    static_assert(typeinfo offsetof<mins>(type<dmodel_t>) == 0, "C layout of dmodel_t: offsetof mins")
    static_assert(typeinfo offsetof<maxs>(type<dmodel_t>) == 12, "C layout of dmodel_t: offsetof maxs")
    static_assert(typeinfo offsetof<origin>(type<dmodel_t>) == 24, "C layout of dmodel_t: offsetof origin")
    static_assert(typeinfo offsetof<headnode>(type<dmodel_t>) == 36, "C layout of dmodel_t: offsetof headnode")
    static_assert(typeinfo offsetof<visleafs>(type<dmodel_t>) == 52, "C layout of dmodel_t: offsetof visleafs")
    static_assert(typeinfo offsetof<firstface>(type<dmodel_t>) == 56, "C layout of dmodel_t: offsetof firstface")
    static_assert(typeinfo offsetof<numfaces>(type<dmodel_t>) == 60, "C layout of dmodel_t: offsetof numfaces")
    static_assert(typeinfo sizeof(type<dclipnode_t>) == 8, "C layout of dclipnode_t: sizeof")
    static_assert(typeinfo alignof(type<dclipnode_t>) == 4, "C layout of dclipnode_t: alignof")
    static_assert(typeinfo offsetof<planenum>(type<dclipnode_t>) == 0, "C layout of dclipnode_t: offsetof planenum")
    static_assert(typeinfo offsetof<children>(type<dclipnode_t>) == 4, "C layout of dclipnode_t: offsetof children")
    static_assert(typeinfo sizeof(type<cache_user_t>) == 8, "C layout of cache_user_t: sizeof")
    static_assert(typeinfo alignof(type<cache_user_t>) == 8, "C layout of cache_user_t: alignof")
    static_assert(typeinfo offsetof<data>(type<cache_user_t>) == 0, "C layout of cache_user_t: offsetof data")
    static_assert(typeinfo sizeof(type<mplane_s>) == 20, "C layout of mplane_s: sizeof")
    static_assert(typeinfo alignof(type<mplane_s>) == 4, "C layout of mplane_s: alignof")
    static_assert(typeinfo offsetof<normal>(type<mplane_s>) == 0, "C layout of mplane_s: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<mplane_s>) == 12, "C layout of mplane_s: offsetof dist")
    static_assert(typeinfo offsetof<type_0>(type<mplane_s>) == 16, "C layout of mplane_s: offsetof type_0")
    static_assert(typeinfo offsetof<signbits>(type<mplane_s>) == 17, "C layout of mplane_s: offsetof signbits")
    static_assert(typeinfo offsetof<pad>(type<mplane_s>) == 18, "C layout of mplane_s: offsetof pad")
    static_assert(typeinfo sizeof(type<entity_state_t>) == 44, "C layout of entity_state_t: sizeof")
    static_assert(typeinfo alignof(type<entity_state_t>) == 4, "C layout of entity_state_t: alignof")
    static_assert(typeinfo offsetof<origin>(type<entity_state_t>) == 0, "C layout of entity_state_t: offsetof origin")
    static_assert(typeinfo offsetof<angles>(type<entity_state_t>) == 12, "C layout of entity_state_t: offsetof angles")
    static_assert(typeinfo offsetof<modelindex>(type<entity_state_t>) == 24, "C layout of entity_state_t: offsetof modelindex")
    static_assert(typeinfo offsetof<frame>(type<entity_state_t>) == 28, "C layout of entity_state_t: offsetof frame")
    static_assert(typeinfo offsetof<colormap>(type<entity_state_t>) == 32, "C layout of entity_state_t: offsetof colormap")
    static_assert(typeinfo offsetof<skin>(type<entity_state_t>) == 36, "C layout of entity_state_t: offsetof skin")
    static_assert(typeinfo offsetof<effects>(type<entity_state_t>) == 40, "C layout of entity_state_t: offsetof effects")
    static_assert(typeinfo sizeof(type<cvar_t>) == 40, "C layout of cvar_t: sizeof")
    static_assert(typeinfo alignof(type<cvar_t>) == 8, "C layout of cvar_t: alignof")
    static_assert(typeinfo offsetof<name>(type<cvar_t>) == 0, "C layout of cvar_t: offsetof name")
    static_assert(typeinfo offsetof<string_0>(type<cvar_t>) == 8, "C layout of cvar_t: offsetof string_0")
    static_assert(typeinfo offsetof<archive>(type<cvar_t>) == 16, "C layout of cvar_t: offsetof archive")
    static_assert(typeinfo offsetof<server>(type<cvar_t>) == 20, "C layout of cvar_t: offsetof server")
    static_assert(typeinfo offsetof<value>(type<cvar_t>) == 24, "C layout of cvar_t: offsetof value")
    static_assert(typeinfo offsetof<next>(type<cvar_t>) == 32, "C layout of cvar_t: offsetof next")
    static_assert(typeinfo sizeof(type<sfx_s>) == 72, "C layout of sfx_s: sizeof")
    static_assert(typeinfo alignof(type<sfx_s>) == 8, "C layout of sfx_s: alignof")
    static_assert(typeinfo offsetof<name>(type<sfx_s>) == 0, "C layout of sfx_s: offsetof name")
    static_assert(typeinfo offsetof<cache>(type<sfx_s>) == 64, "C layout of sfx_s: offsetof cache")
    static_assert(typeinfo sizeof(type<efrag_s>) == 32, "C layout of efrag_s: sizeof")
    static_assert(typeinfo alignof(type<efrag_s>) == 8, "C layout of efrag_s: alignof")
    static_assert(typeinfo offsetof<leaf>(type<efrag_s>) == 0, "C layout of efrag_s: offsetof leaf")
    static_assert(typeinfo offsetof<leafnext>(type<efrag_s>) == 8, "C layout of efrag_s: offsetof leafnext")
    static_assert(typeinfo offsetof<entity>(type<efrag_s>) == 16, "C layout of efrag_s: offsetof entity")
    static_assert(typeinfo offsetof<entnext>(type<efrag_s>) == 24, "C layout of efrag_s: offsetof entnext")
    static_assert(typeinfo sizeof(type<entity_s>) == 200, "C layout of entity_s: sizeof")
    static_assert(typeinfo alignof(type<entity_s>) == 8, "C layout of entity_s: alignof")
    static_assert(typeinfo offsetof<forcelink>(type<entity_s>) == 0, "C layout of entity_s: offsetof forcelink")
    static_assert(typeinfo offsetof<update_type>(type<entity_s>) == 4, "C layout of entity_s: offsetof update_type")
    static_assert(typeinfo offsetof<baseline>(type<entity_s>) == 8, "C layout of entity_s: offsetof baseline")
    static_assert(typeinfo offsetof<msgtime>(type<entity_s>) == 56, "C layout of entity_s: offsetof msgtime")
    static_assert(typeinfo offsetof<msg_origins>(type<entity_s>) == 64, "C layout of entity_s: offsetof msg_origins")
    static_assert(typeinfo offsetof<origin>(type<entity_s>) == 88, "C layout of entity_s: offsetof origin")
    static_assert(typeinfo offsetof<msg_angles>(type<entity_s>) == 100, "C layout of entity_s: offsetof msg_angles")
    static_assert(typeinfo offsetof<angles>(type<entity_s>) == 124, "C layout of entity_s: offsetof angles")
    static_assert(typeinfo offsetof<model>(type<entity_s>) == 136, "C layout of entity_s: offsetof model")
    static_assert(typeinfo offsetof<efrag>(type<entity_s>) == 144, "C layout of entity_s: offsetof efrag")
    static_assert(typeinfo offsetof<frame>(type<entity_s>) == 152, "C layout of entity_s: offsetof frame")
    static_assert(typeinfo offsetof<syncbase>(type<entity_s>) == 156, "C layout of entity_s: offsetof syncbase")
    static_assert(typeinfo offsetof<colormap>(type<entity_s>) == 160, "C layout of entity_s: offsetof colormap")
    static_assert(typeinfo offsetof<effects>(type<entity_s>) == 168, "C layout of entity_s: offsetof effects")
    static_assert(typeinfo offsetof<skinnum>(type<entity_s>) == 172, "C layout of entity_s: offsetof skinnum")
    static_assert(typeinfo offsetof<visframe>(type<entity_s>) == 176, "C layout of entity_s: offsetof visframe")
    static_assert(typeinfo offsetof<dlightframe>(type<entity_s>) == 180, "C layout of entity_s: offsetof dlightframe")
    static_assert(typeinfo offsetof<dlightbits>(type<entity_s>) == 184, "C layout of entity_s: offsetof dlightbits")
    static_assert(typeinfo offsetof<trivial_accept>(type<entity_s>) == 188, "C layout of entity_s: offsetof trivial_accept")
    static_assert(typeinfo offsetof<topnode>(type<entity_s>) == 192, "C layout of entity_s: offsetof topnode")
    static_assert(typeinfo sizeof(type<mnode_s>) == 64, "C layout of mnode_s: sizeof")
    static_assert(typeinfo alignof(type<mnode_s>) == 8, "C layout of mnode_s: alignof")
    static_assert(typeinfo offsetof<contents>(type<mnode_s>) == 0, "C layout of mnode_s: offsetof contents")
    static_assert(typeinfo offsetof<visframe>(type<mnode_s>) == 4, "C layout of mnode_s: offsetof visframe")
    static_assert(typeinfo offsetof<minmaxs>(type<mnode_s>) == 8, "C layout of mnode_s: offsetof minmaxs")
    static_assert(typeinfo offsetof<parent>(type<mnode_s>) == 24, "C layout of mnode_s: offsetof parent")
    static_assert(typeinfo offsetof<plane>(type<mnode_s>) == 32, "C layout of mnode_s: offsetof plane")
    static_assert(typeinfo offsetof<children>(type<mnode_s>) == 40, "C layout of mnode_s: offsetof children")
    static_assert(typeinfo offsetof<firstsurface>(type<mnode_s>) == 56, "C layout of mnode_s: offsetof firstsurface")
    static_assert(typeinfo offsetof<numsurfaces>(type<mnode_s>) == 58, "C layout of mnode_s: offsetof numsurfaces")
    static_assert(typeinfo sizeof(type<mplane_t>) == 20, "C layout of mplane_t: sizeof")
    static_assert(typeinfo alignof(type<mplane_t>) == 4, "C layout of mplane_t: alignof")
    static_assert(typeinfo offsetof<normal>(type<mplane_t>) == 0, "C layout of mplane_t: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<mplane_t>) == 12, "C layout of mplane_t: offsetof dist")
    static_assert(typeinfo offsetof<type_0>(type<mplane_t>) == 16, "C layout of mplane_t: offsetof type_0")
    static_assert(typeinfo offsetof<signbits>(type<mplane_t>) == 17, "C layout of mplane_t: offsetof signbits")
    static_assert(typeinfo offsetof<pad>(type<mplane_t>) == 18, "C layout of mplane_t: offsetof pad")
    static_assert(typeinfo sizeof(type<model_s>) == 536, "C layout of model_s: sizeof")
    static_assert(typeinfo alignof(type<model_s>) == 8, "C layout of model_s: alignof")
    static_assert(typeinfo offsetof<name>(type<model_s>) == 0, "C layout of model_s: offsetof name")
    static_assert(typeinfo offsetof<needload>(type<model_s>) == 64, "C layout of model_s: offsetof needload")
    static_assert(typeinfo offsetof<type_0>(type<model_s>) == 68, "C layout of model_s: offsetof type_0")
    static_assert(typeinfo offsetof<numframes>(type<model_s>) == 72, "C layout of model_s: offsetof numframes")
    static_assert(typeinfo offsetof<synctype>(type<model_s>) == 76, "C layout of model_s: offsetof synctype")
    static_assert(typeinfo offsetof<flags>(type<model_s>) == 80, "C layout of model_s: offsetof flags")
    static_assert(typeinfo offsetof<mins>(type<model_s>) == 84, "C layout of model_s: offsetof mins")
    static_assert(typeinfo offsetof<maxs>(type<model_s>) == 96, "C layout of model_s: offsetof maxs")
    static_assert(typeinfo offsetof<radius>(type<model_s>) == 108, "C layout of model_s: offsetof radius")
    static_assert(typeinfo offsetof<firstmodelsurface>(type<model_s>) == 112, "C layout of model_s: offsetof firstmodelsurface")
    static_assert(typeinfo offsetof<nummodelsurfaces>(type<model_s>) == 116, "C layout of model_s: offsetof nummodelsurfaces")
    static_assert(typeinfo offsetof<numsubmodels>(type<model_s>) == 120, "C layout of model_s: offsetof numsubmodels")
    static_assert(typeinfo offsetof<submodels>(type<model_s>) == 128, "C layout of model_s: offsetof submodels")
    static_assert(typeinfo offsetof<numplanes>(type<model_s>) == 136, "C layout of model_s: offsetof numplanes")
    static_assert(typeinfo offsetof<planes>(type<model_s>) == 144, "C layout of model_s: offsetof planes")
    static_assert(typeinfo offsetof<numleafs>(type<model_s>) == 152, "C layout of model_s: offsetof numleafs")
    static_assert(typeinfo offsetof<leafs>(type<model_s>) == 160, "C layout of model_s: offsetof leafs")
    static_assert(typeinfo offsetof<numvertexes>(type<model_s>) == 168, "C layout of model_s: offsetof numvertexes")
    static_assert(typeinfo offsetof<vertexes>(type<model_s>) == 176, "C layout of model_s: offsetof vertexes")
    static_assert(typeinfo offsetof<numedges>(type<model_s>) == 184, "C layout of model_s: offsetof numedges")
    static_assert(typeinfo offsetof<edges>(type<model_s>) == 192, "C layout of model_s: offsetof edges")
    static_assert(typeinfo offsetof<numnodes>(type<model_s>) == 200, "C layout of model_s: offsetof numnodes")
    static_assert(typeinfo offsetof<nodes>(type<model_s>) == 208, "C layout of model_s: offsetof nodes")
    static_assert(typeinfo offsetof<numtexinfo>(type<model_s>) == 216, "C layout of model_s: offsetof numtexinfo")
    static_assert(typeinfo offsetof<texinfo>(type<model_s>) == 224, "C layout of model_s: offsetof texinfo")
    static_assert(typeinfo offsetof<numsurfaces>(type<model_s>) == 232, "C layout of model_s: offsetof numsurfaces")
    static_assert(typeinfo offsetof<surfaces>(type<model_s>) == 240, "C layout of model_s: offsetof surfaces")
    static_assert(typeinfo offsetof<numsurfedges>(type<model_s>) == 248, "C layout of model_s: offsetof numsurfedges")
    static_assert(typeinfo offsetof<surfedges>(type<model_s>) == 256, "C layout of model_s: offsetof surfedges")
    static_assert(typeinfo offsetof<numclipnodes>(type<model_s>) == 264, "C layout of model_s: offsetof numclipnodes")
    static_assert(typeinfo offsetof<clipnodes>(type<model_s>) == 272, "C layout of model_s: offsetof clipnodes")
    static_assert(typeinfo offsetof<nummarksurfaces>(type<model_s>) == 280, "C layout of model_s: offsetof nummarksurfaces")
    static_assert(typeinfo offsetof<marksurfaces>(type<model_s>) == 288, "C layout of model_s: offsetof marksurfaces")
    static_assert(typeinfo offsetof<hulls>(type<model_s>) == 296, "C layout of model_s: offsetof hulls")
    static_assert(typeinfo offsetof<numtextures>(type<model_s>) == 488, "C layout of model_s: offsetof numtextures")
    static_assert(typeinfo offsetof<textures>(type<model_s>) == 496, "C layout of model_s: offsetof textures")
    static_assert(typeinfo offsetof<visdata>(type<model_s>) == 504, "C layout of model_s: offsetof visdata")
    static_assert(typeinfo offsetof<lightdata>(type<model_s>) == 512, "C layout of model_s: offsetof lightdata")
    static_assert(typeinfo offsetof<entities>(type<model_s>) == 520, "C layout of model_s: offsetof entities")
    static_assert(typeinfo offsetof<cache>(type<model_s>) == 528, "C layout of model_s: offsetof cache")
    static_assert(typeinfo sizeof(type<texture_t>) == 72, "C layout of texture_t: sizeof")
    static_assert(typeinfo alignof(type<texture_t>) == 8, "C layout of texture_t: alignof")
    static_assert(typeinfo offsetof<name>(type<texture_t>) == 0, "C layout of texture_t: offsetof name")
    static_assert(typeinfo offsetof<width>(type<texture_t>) == 16, "C layout of texture_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<texture_t>) == 20, "C layout of texture_t: offsetof height")
    static_assert(typeinfo offsetof<anim_total>(type<texture_t>) == 24, "C layout of texture_t: offsetof anim_total")
    static_assert(typeinfo offsetof<anim_min>(type<texture_t>) == 28, "C layout of texture_t: offsetof anim_min")
    static_assert(typeinfo offsetof<anim_max>(type<texture_t>) == 32, "C layout of texture_t: offsetof anim_max")
    static_assert(typeinfo offsetof<anim_next>(type<texture_t>) == 40, "C layout of texture_t: offsetof anim_next")
    static_assert(typeinfo offsetof<alternate_anims>(type<texture_t>) == 48, "C layout of texture_t: offsetof alternate_anims")
    static_assert(typeinfo offsetof<offsets>(type<texture_t>) == 56, "C layout of texture_t: offsetof offsets")
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
    static_assert(typeinfo sizeof(type<hull_t>) == 48, "C layout of hull_t: sizeof")
    static_assert(typeinfo alignof(type<hull_t>) == 8, "C layout of hull_t: alignof")
    static_assert(typeinfo offsetof<clipnodes>(type<hull_t>) == 0, "C layout of hull_t: offsetof clipnodes")
    static_assert(typeinfo offsetof<planes>(type<hull_t>) == 8, "C layout of hull_t: offsetof planes")
    static_assert(typeinfo offsetof<firstclipnode>(type<hull_t>) == 16, "C layout of hull_t: offsetof firstclipnode")
    static_assert(typeinfo offsetof<lastclipnode>(type<hull_t>) == 20, "C layout of hull_t: offsetof lastclipnode")
    static_assert(typeinfo offsetof<clip_mins>(type<hull_t>) == 24, "C layout of hull_t: offsetof clip_mins")
    static_assert(typeinfo offsetof<clip_maxs>(type<hull_t>) == 36, "C layout of hull_t: offsetof clip_maxs")
    static_assert(typeinfo sizeof(type<msurface_t>) == 104, "C layout of msurface_t: sizeof")
    static_assert(typeinfo alignof(type<msurface_t>) == 8, "C layout of msurface_t: alignof")
    static_assert(typeinfo offsetof<visframe>(type<msurface_t>) == 0, "C layout of msurface_t: offsetof visframe")
    static_assert(typeinfo offsetof<dlightframe>(type<msurface_t>) == 4, "C layout of msurface_t: offsetof dlightframe")
    static_assert(typeinfo offsetof<dlightbits>(type<msurface_t>) == 8, "C layout of msurface_t: offsetof dlightbits")
    static_assert(typeinfo offsetof<plane>(type<msurface_t>) == 16, "C layout of msurface_t: offsetof plane")
    static_assert(typeinfo offsetof<flags>(type<msurface_t>) == 24, "C layout of msurface_t: offsetof flags")
    static_assert(typeinfo offsetof<firstedge>(type<msurface_t>) == 28, "C layout of msurface_t: offsetof firstedge")
    static_assert(typeinfo offsetof<numedges>(type<msurface_t>) == 32, "C layout of msurface_t: offsetof numedges")
    static_assert(typeinfo offsetof<cachespots>(type<msurface_t>) == 40, "C layout of msurface_t: offsetof cachespots")
    static_assert(typeinfo offsetof<texturemins>(type<msurface_t>) == 72, "C layout of msurface_t: offsetof texturemins")
    static_assert(typeinfo offsetof<extents>(type<msurface_t>) == 76, "C layout of msurface_t: offsetof extents")
    static_assert(typeinfo offsetof<texinfo>(type<msurface_t>) == 80, "C layout of msurface_t: offsetof texinfo")
    static_assert(typeinfo offsetof<styles>(type<msurface_t>) == 88, "C layout of msurface_t: offsetof styles")
    static_assert(typeinfo offsetof<samples>(type<msurface_t>) == 96, "C layout of msurface_t: offsetof samples")
    static_assert(typeinfo sizeof(type<msurface_s>) == 104, "C layout of msurface_s: sizeof")
    static_assert(typeinfo alignof(type<msurface_s>) == 8, "C layout of msurface_s: alignof")
    static_assert(typeinfo offsetof<visframe>(type<msurface_s>) == 0, "C layout of msurface_s: offsetof visframe")
    static_assert(typeinfo offsetof<dlightframe>(type<msurface_s>) == 4, "C layout of msurface_s: offsetof dlightframe")
    static_assert(typeinfo offsetof<dlightbits>(type<msurface_s>) == 8, "C layout of msurface_s: offsetof dlightbits")
    static_assert(typeinfo offsetof<plane>(type<msurface_s>) == 16, "C layout of msurface_s: offsetof plane")
    static_assert(typeinfo offsetof<flags>(type<msurface_s>) == 24, "C layout of msurface_s: offsetof flags")
    static_assert(typeinfo offsetof<firstedge>(type<msurface_s>) == 28, "C layout of msurface_s: offsetof firstedge")
    static_assert(typeinfo offsetof<numedges>(type<msurface_s>) == 32, "C layout of msurface_s: offsetof numedges")
    static_assert(typeinfo offsetof<cachespots>(type<msurface_s>) == 40, "C layout of msurface_s: offsetof cachespots")
    static_assert(typeinfo offsetof<texturemins>(type<msurface_s>) == 72, "C layout of msurface_s: offsetof texturemins")
    static_assert(typeinfo offsetof<extents>(type<msurface_s>) == 76, "C layout of msurface_s: offsetof extents")
    static_assert(typeinfo offsetof<texinfo>(type<msurface_s>) == 80, "C layout of msurface_s: offsetof texinfo")
    static_assert(typeinfo offsetof<styles>(type<msurface_s>) == 88, "C layout of msurface_s: offsetof styles")
    static_assert(typeinfo offsetof<samples>(type<msurface_s>) == 96, "C layout of msurface_s: offsetof samples")
    static_assert(typeinfo sizeof(type<mtexinfo_t>) == 56, "C layout of mtexinfo_t: sizeof")
    static_assert(typeinfo alignof(type<mtexinfo_t>) == 8, "C layout of mtexinfo_t: alignof")
    static_assert(typeinfo offsetof<vecs>(type<mtexinfo_t>) == 0, "C layout of mtexinfo_t: offsetof vecs")
    static_assert(typeinfo offsetof<mipadjust>(type<mtexinfo_t>) == 32, "C layout of mtexinfo_t: offsetof mipadjust")
    static_assert(typeinfo offsetof<texture>(type<mtexinfo_t>) == 40, "C layout of mtexinfo_t: offsetof texture")
    static_assert(typeinfo offsetof<flags>(type<mtexinfo_t>) == 48, "C layout of mtexinfo_t: offsetof flags")
    static_assert(typeinfo sizeof(type<mnode_t>) == 64, "C layout of mnode_t: sizeof")
    static_assert(typeinfo alignof(type<mnode_t>) == 8, "C layout of mnode_t: alignof")
    static_assert(typeinfo offsetof<contents>(type<mnode_t>) == 0, "C layout of mnode_t: offsetof contents")
    static_assert(typeinfo offsetof<visframe>(type<mnode_t>) == 4, "C layout of mnode_t: offsetof visframe")
    static_assert(typeinfo offsetof<minmaxs>(type<mnode_t>) == 8, "C layout of mnode_t: offsetof minmaxs")
    static_assert(typeinfo offsetof<parent>(type<mnode_t>) == 24, "C layout of mnode_t: offsetof parent")
    static_assert(typeinfo offsetof<plane>(type<mnode_t>) == 32, "C layout of mnode_t: offsetof plane")
    static_assert(typeinfo offsetof<children>(type<mnode_t>) == 40, "C layout of mnode_t: offsetof children")
    static_assert(typeinfo offsetof<firstsurface>(type<mnode_t>) == 56, "C layout of mnode_t: offsetof firstsurface")
    static_assert(typeinfo offsetof<numsurfaces>(type<mnode_t>) == 58, "C layout of mnode_t: offsetof numsurfaces")
    static_assert(typeinfo sizeof(type<medge_t>) == 8, "C layout of medge_t: sizeof")
    static_assert(typeinfo alignof(type<medge_t>) == 4, "C layout of medge_t: alignof")
    static_assert(typeinfo offsetof<v>(type<medge_t>) == 0, "C layout of medge_t: offsetof v")
    static_assert(typeinfo offsetof<cachededgeoffset>(type<medge_t>) == 4, "C layout of medge_t: offsetof cachededgeoffset")
    static_assert(typeinfo sizeof(type<mvertex_t>) == 12, "C layout of mvertex_t: sizeof")
    static_assert(typeinfo alignof(type<mvertex_t>) == 4, "C layout of mvertex_t: alignof")
    static_assert(typeinfo offsetof<position>(type<mvertex_t>) == 0, "C layout of mvertex_t: offsetof position")
    static_assert(typeinfo sizeof(type<mleaf_t>) == 72, "C layout of mleaf_t: sizeof")
    static_assert(typeinfo alignof(type<mleaf_t>) == 8, "C layout of mleaf_t: alignof")
    static_assert(typeinfo offsetof<contents>(type<mleaf_t>) == 0, "C layout of mleaf_t: offsetof contents")
    static_assert(typeinfo offsetof<visframe>(type<mleaf_t>) == 4, "C layout of mleaf_t: offsetof visframe")
    static_assert(typeinfo offsetof<minmaxs>(type<mleaf_t>) == 8, "C layout of mleaf_t: offsetof minmaxs")
    static_assert(typeinfo offsetof<parent>(type<mleaf_t>) == 24, "C layout of mleaf_t: offsetof parent")
    static_assert(typeinfo offsetof<compressed_vis>(type<mleaf_t>) == 32, "C layout of mleaf_t: offsetof compressed_vis")
    static_assert(typeinfo offsetof<efrags>(type<mleaf_t>) == 40, "C layout of mleaf_t: offsetof efrags")
    static_assert(typeinfo offsetof<firstmarksurface>(type<mleaf_t>) == 48, "C layout of mleaf_t: offsetof firstmarksurface")
    static_assert(typeinfo offsetof<nummarksurfaces>(type<mleaf_t>) == 56, "C layout of mleaf_t: offsetof nummarksurfaces")
    static_assert(typeinfo offsetof<key>(type<mleaf_t>) == 60, "C layout of mleaf_t: offsetof key")
    static_assert(typeinfo offsetof<ambient_sound_level>(type<mleaf_t>) == 64, "C layout of mleaf_t: offsetof ambient_sound_level")
    static_assert(typeinfo sizeof(type<mleaf_s>) == 72, "C layout of mleaf_s: sizeof")
    static_assert(typeinfo alignof(type<mleaf_s>) == 8, "C layout of mleaf_s: alignof")
    static_assert(typeinfo offsetof<contents>(type<mleaf_s>) == 0, "C layout of mleaf_s: offsetof contents")
    static_assert(typeinfo offsetof<visframe>(type<mleaf_s>) == 4, "C layout of mleaf_s: offsetof visframe")
    static_assert(typeinfo offsetof<minmaxs>(type<mleaf_s>) == 8, "C layout of mleaf_s: offsetof minmaxs")
    static_assert(typeinfo offsetof<parent>(type<mleaf_s>) == 24, "C layout of mleaf_s: offsetof parent")
    static_assert(typeinfo offsetof<compressed_vis>(type<mleaf_s>) == 32, "C layout of mleaf_s: offsetof compressed_vis")
    static_assert(typeinfo offsetof<efrags>(type<mleaf_s>) == 40, "C layout of mleaf_s: offsetof efrags")
    static_assert(typeinfo offsetof<firstmarksurface>(type<mleaf_s>) == 48, "C layout of mleaf_s: offsetof firstmarksurface")
    static_assert(typeinfo offsetof<nummarksurfaces>(type<mleaf_s>) == 56, "C layout of mleaf_s: offsetof nummarksurfaces")
    static_assert(typeinfo offsetof<key>(type<mleaf_s>) == 60, "C layout of mleaf_s: offsetof key")
    static_assert(typeinfo offsetof<ambient_sound_level>(type<mleaf_s>) == 64, "C layout of mleaf_s: offsetof ambient_sound_level")
    static_assert(typeinfo sizeof(type<efrag_t>) == 32, "C layout of efrag_t: sizeof")
    static_assert(typeinfo alignof(type<efrag_t>) == 8, "C layout of efrag_t: alignof")
    static_assert(typeinfo offsetof<leaf>(type<efrag_t>) == 0, "C layout of efrag_t: offsetof leaf")
    static_assert(typeinfo offsetof<leafnext>(type<efrag_t>) == 8, "C layout of efrag_t: offsetof leafnext")
    static_assert(typeinfo offsetof<entity>(type<efrag_t>) == 16, "C layout of efrag_t: offsetof entity")
    static_assert(typeinfo offsetof<entnext>(type<efrag_t>) == 24, "C layout of efrag_t: offsetof entnext")
    static_assert(typeinfo sizeof(type<entity_t>) == 200, "C layout of entity_t: sizeof")
    static_assert(typeinfo alignof(type<entity_t>) == 8, "C layout of entity_t: alignof")
    static_assert(typeinfo offsetof<forcelink>(type<entity_t>) == 0, "C layout of entity_t: offsetof forcelink")
    static_assert(typeinfo offsetof<update_type>(type<entity_t>) == 4, "C layout of entity_t: offsetof update_type")
    static_assert(typeinfo offsetof<baseline>(type<entity_t>) == 8, "C layout of entity_t: offsetof baseline")
    static_assert(typeinfo offsetof<msgtime>(type<entity_t>) == 56, "C layout of entity_t: offsetof msgtime")
    static_assert(typeinfo offsetof<msg_origins>(type<entity_t>) == 64, "C layout of entity_t: offsetof msg_origins")
    static_assert(typeinfo offsetof<origin>(type<entity_t>) == 88, "C layout of entity_t: offsetof origin")
    static_assert(typeinfo offsetof<msg_angles>(type<entity_t>) == 100, "C layout of entity_t: offsetof msg_angles")
    static_assert(typeinfo offsetof<angles>(type<entity_t>) == 124, "C layout of entity_t: offsetof angles")
    static_assert(typeinfo offsetof<model>(type<entity_t>) == 136, "C layout of entity_t: offsetof model")
    static_assert(typeinfo offsetof<efrag>(type<entity_t>) == 144, "C layout of entity_t: offsetof efrag")
    static_assert(typeinfo offsetof<frame>(type<entity_t>) == 152, "C layout of entity_t: offsetof frame")
    static_assert(typeinfo offsetof<syncbase>(type<entity_t>) == 156, "C layout of entity_t: offsetof syncbase")
    static_assert(typeinfo offsetof<colormap>(type<entity_t>) == 160, "C layout of entity_t: offsetof colormap")
    static_assert(typeinfo offsetof<effects>(type<entity_t>) == 168, "C layout of entity_t: offsetof effects")
    static_assert(typeinfo offsetof<skinnum>(type<entity_t>) == 172, "C layout of entity_t: offsetof skinnum")
    static_assert(typeinfo offsetof<visframe>(type<entity_t>) == 176, "C layout of entity_t: offsetof visframe")
    static_assert(typeinfo offsetof<dlightframe>(type<entity_t>) == 180, "C layout of entity_t: offsetof dlightframe")
    static_assert(typeinfo offsetof<dlightbits>(type<entity_t>) == 184, "C layout of entity_t: offsetof dlightbits")
    static_assert(typeinfo offsetof<trivial_accept>(type<entity_t>) == 188, "C layout of entity_t: offsetof trivial_accept")
    static_assert(typeinfo offsetof<topnode>(type<entity_t>) == 192, "C layout of entity_t: offsetof topnode")
    static_assert(typeinfo sizeof(type<particle_t>) == 48, "C layout of particle_t: sizeof")
    static_assert(typeinfo alignof(type<particle_t>) == 8, "C layout of particle_t: alignof")
    static_assert(typeinfo offsetof<org>(type<particle_t>) == 0, "C layout of particle_t: offsetof org")
    static_assert(typeinfo offsetof<color>(type<particle_t>) == 12, "C layout of particle_t: offsetof color")
    static_assert(typeinfo offsetof<next>(type<particle_t>) == 16, "C layout of particle_t: offsetof next")
    static_assert(typeinfo offsetof<vel>(type<particle_t>) == 24, "C layout of particle_t: offsetof vel")
    static_assert(typeinfo offsetof<ramp>(type<particle_t>) == 36, "C layout of particle_t: offsetof ramp")
    static_assert(typeinfo offsetof<die>(type<particle_t>) == 40, "C layout of particle_t: offsetof die")
    static_assert(typeinfo offsetof<type_0>(type<particle_t>) == 44, "C layout of particle_t: offsetof type_0")
    static_assert(typeinfo sizeof(type<particle_s>) == 48, "C layout of particle_s: sizeof")
    static_assert(typeinfo alignof(type<particle_s>) == 8, "C layout of particle_s: alignof")
    static_assert(typeinfo offsetof<org>(type<particle_s>) == 0, "C layout of particle_s: offsetof org")
    static_assert(typeinfo offsetof<color>(type<particle_s>) == 12, "C layout of particle_s: offsetof color")
    static_assert(typeinfo offsetof<next>(type<particle_s>) == 16, "C layout of particle_s: offsetof next")
    static_assert(typeinfo offsetof<vel>(type<particle_s>) == 24, "C layout of particle_s: offsetof vel")
    static_assert(typeinfo offsetof<ramp>(type<particle_s>) == 36, "C layout of particle_s: offsetof ramp")
    static_assert(typeinfo offsetof<die>(type<particle_s>) == 40, "C layout of particle_s: offsetof die")
    static_assert(typeinfo offsetof<type_0>(type<particle_s>) == 44, "C layout of particle_s: offsetof type_0")
    static_assert(typeinfo sizeof(type<client_state_t>) == 4992, "C layout of client_state_t: sizeof")
    static_assert(typeinfo alignof(type<client_state_t>) == 8, "C layout of client_state_t: alignof")
    static_assert(typeinfo offsetof<movemessages>(type<client_state_t>) == 0, "C layout of client_state_t: offsetof movemessages")
    static_assert(typeinfo offsetof<cmd>(type<client_state_t>) == 4, "C layout of client_state_t: offsetof cmd")
    static_assert(typeinfo offsetof<stats>(type<client_state_t>) == 28, "C layout of client_state_t: offsetof stats")
    static_assert(typeinfo offsetof<items>(type<client_state_t>) == 156, "C layout of client_state_t: offsetof items")
    static_assert(typeinfo offsetof<item_gettime>(type<client_state_t>) == 160, "C layout of client_state_t: offsetof item_gettime")
    static_assert(typeinfo offsetof<faceanimtime>(type<client_state_t>) == 288, "C layout of client_state_t: offsetof faceanimtime")
    static_assert(typeinfo offsetof<cshifts>(type<client_state_t>) == 292, "C layout of client_state_t: offsetof cshifts")
    static_assert(typeinfo offsetof<prev_cshifts>(type<client_state_t>) == 356, "C layout of client_state_t: offsetof prev_cshifts")
    static_assert(typeinfo offsetof<mviewangles>(type<client_state_t>) == 420, "C layout of client_state_t: offsetof mviewangles")
    static_assert(typeinfo offsetof<viewangles>(type<client_state_t>) == 444, "C layout of client_state_t: offsetof viewangles")
    static_assert(typeinfo offsetof<mvelocity>(type<client_state_t>) == 456, "C layout of client_state_t: offsetof mvelocity")
    static_assert(typeinfo offsetof<velocity>(type<client_state_t>) == 480, "C layout of client_state_t: offsetof velocity")
    static_assert(typeinfo offsetof<punchangle>(type<client_state_t>) == 492, "C layout of client_state_t: offsetof punchangle")
    static_assert(typeinfo offsetof<idealpitch>(type<client_state_t>) == 504, "C layout of client_state_t: offsetof idealpitch")
    static_assert(typeinfo offsetof<pitchvel>(type<client_state_t>) == 508, "C layout of client_state_t: offsetof pitchvel")
    static_assert(typeinfo offsetof<nodrift>(type<client_state_t>) == 512, "C layout of client_state_t: offsetof nodrift")
    static_assert(typeinfo offsetof<driftmove>(type<client_state_t>) == 516, "C layout of client_state_t: offsetof driftmove")
    static_assert(typeinfo offsetof<laststop>(type<client_state_t>) == 520, "C layout of client_state_t: offsetof laststop")
    static_assert(typeinfo offsetof<viewheight>(type<client_state_t>) == 528, "C layout of client_state_t: offsetof viewheight")
    static_assert(typeinfo offsetof<crouch>(type<client_state_t>) == 532, "C layout of client_state_t: offsetof crouch")
    static_assert(typeinfo offsetof<paused>(type<client_state_t>) == 536, "C layout of client_state_t: offsetof paused")
    static_assert(typeinfo offsetof<onground>(type<client_state_t>) == 540, "C layout of client_state_t: offsetof onground")
    static_assert(typeinfo offsetof<inwater>(type<client_state_t>) == 544, "C layout of client_state_t: offsetof inwater")
    static_assert(typeinfo offsetof<intermission>(type<client_state_t>) == 548, "C layout of client_state_t: offsetof intermission")
    static_assert(typeinfo offsetof<completed_time>(type<client_state_t>) == 552, "C layout of client_state_t: offsetof completed_time")
    static_assert(typeinfo offsetof<mtime>(type<client_state_t>) == 560, "C layout of client_state_t: offsetof mtime")
    static_assert(typeinfo offsetof<time>(type<client_state_t>) == 576, "C layout of client_state_t: offsetof time")
    static_assert(typeinfo offsetof<oldtime>(type<client_state_t>) == 584, "C layout of client_state_t: offsetof oldtime")
    static_assert(typeinfo offsetof<last_received_message>(type<client_state_t>) == 592, "C layout of client_state_t: offsetof last_received_message")
    static_assert(typeinfo offsetof<model_precache>(type<client_state_t>) == 600, "C layout of client_state_t: offsetof model_precache")
    static_assert(typeinfo offsetof<sound_precache>(type<client_state_t>) == 2648, "C layout of client_state_t: offsetof sound_precache")
    static_assert(typeinfo offsetof<levelname>(type<client_state_t>) == 4696, "C layout of client_state_t: offsetof levelname")
    static_assert(typeinfo offsetof<viewentity>(type<client_state_t>) == 4736, "C layout of client_state_t: offsetof viewentity")
    static_assert(typeinfo offsetof<maxclients>(type<client_state_t>) == 4740, "C layout of client_state_t: offsetof maxclients")
    static_assert(typeinfo offsetof<gametype>(type<client_state_t>) == 4744, "C layout of client_state_t: offsetof gametype")
    static_assert(typeinfo offsetof<worldmodel>(type<client_state_t>) == 4752, "C layout of client_state_t: offsetof worldmodel")
    static_assert(typeinfo offsetof<free_efrags>(type<client_state_t>) == 4760, "C layout of client_state_t: offsetof free_efrags")
    static_assert(typeinfo offsetof<num_entities>(type<client_state_t>) == 4768, "C layout of client_state_t: offsetof num_entities")
    static_assert(typeinfo offsetof<num_statics>(type<client_state_t>) == 4772, "C layout of client_state_t: offsetof num_statics")
    static_assert(typeinfo offsetof<viewent>(type<client_state_t>) == 4776, "C layout of client_state_t: offsetof viewent")
    static_assert(typeinfo offsetof<cdtrack>(type<client_state_t>) == 4976, "C layout of client_state_t: offsetof cdtrack")
    static_assert(typeinfo offsetof<looptrack>(type<client_state_t>) == 4980, "C layout of client_state_t: offsetof looptrack")
    static_assert(typeinfo offsetof<scores>(type<client_state_t>) == 4984, "C layout of client_state_t: offsetof scores")
    static_assert(typeinfo sizeof(type<scoreboard_t>) == 16428, "C layout of scoreboard_t: sizeof")
    static_assert(typeinfo alignof(type<scoreboard_t>) == 4, "C layout of scoreboard_t: alignof")
    static_assert(typeinfo offsetof<name>(type<scoreboard_t>) == 0, "C layout of scoreboard_t: offsetof name")
    static_assert(typeinfo offsetof<entertime>(type<scoreboard_t>) == 32, "C layout of scoreboard_t: offsetof entertime")
    static_assert(typeinfo offsetof<frags>(type<scoreboard_t>) == 36, "C layout of scoreboard_t: offsetof frags")
    static_assert(typeinfo offsetof<colors>(type<scoreboard_t>) == 40, "C layout of scoreboard_t: offsetof colors")
    static_assert(typeinfo offsetof<translations>(type<scoreboard_t>) == 44, "C layout of scoreboard_t: offsetof translations")
    static_assert(typeinfo sizeof(type<cshift_t>) == 16, "C layout of cshift_t: sizeof")
    static_assert(typeinfo alignof(type<cshift_t>) == 4, "C layout of cshift_t: alignof")
    static_assert(typeinfo offsetof<destcolor>(type<cshift_t>) == 0, "C layout of cshift_t: offsetof destcolor")
    static_assert(typeinfo offsetof<percent>(type<cshift_t>) == 12, "C layout of cshift_t: offsetof percent")
    static_assert(typeinfo sizeof(type<usercmd_t>) == 24, "C layout of usercmd_t: sizeof")
    static_assert(typeinfo alignof(type<usercmd_t>) == 4, "C layout of usercmd_t: alignof")
    static_assert(typeinfo offsetof<viewangles>(type<usercmd_t>) == 0, "C layout of usercmd_t: offsetof viewangles")
    static_assert(typeinfo offsetof<forwardmove>(type<usercmd_t>) == 12, "C layout of usercmd_t: offsetof forwardmove")
    static_assert(typeinfo offsetof<sidemove>(type<usercmd_t>) == 16, "C layout of usercmd_t: offsetof sidemove")
    static_assert(typeinfo offsetof<upmove>(type<usercmd_t>) == 20, "C layout of usercmd_t: offsetof upmove")
    static_assert(typeinfo sizeof(type<entvars_t>) == 420, "C layout of entvars_t: sizeof")
    static_assert(typeinfo alignof(type<entvars_t>) == 4, "C layout of entvars_t: alignof")
    static_assert(typeinfo offsetof<modelindex>(type<entvars_t>) == 0, "C layout of entvars_t: offsetof modelindex")
    static_assert(typeinfo offsetof<absmin>(type<entvars_t>) == 4, "C layout of entvars_t: offsetof absmin")
    static_assert(typeinfo offsetof<absmax>(type<entvars_t>) == 16, "C layout of entvars_t: offsetof absmax")
    static_assert(typeinfo offsetof<ltime>(type<entvars_t>) == 28, "C layout of entvars_t: offsetof ltime")
    static_assert(typeinfo offsetof<movetype>(type<entvars_t>) == 32, "C layout of entvars_t: offsetof movetype")
    static_assert(typeinfo offsetof<solid>(type<entvars_t>) == 36, "C layout of entvars_t: offsetof solid")
    static_assert(typeinfo offsetof<origin>(type<entvars_t>) == 40, "C layout of entvars_t: offsetof origin")
    static_assert(typeinfo offsetof<oldorigin>(type<entvars_t>) == 52, "C layout of entvars_t: offsetof oldorigin")
    static_assert(typeinfo offsetof<velocity>(type<entvars_t>) == 64, "C layout of entvars_t: offsetof velocity")
    static_assert(typeinfo offsetof<angles>(type<entvars_t>) == 76, "C layout of entvars_t: offsetof angles")
    static_assert(typeinfo offsetof<avelocity>(type<entvars_t>) == 88, "C layout of entvars_t: offsetof avelocity")
    static_assert(typeinfo offsetof<punchangle>(type<entvars_t>) == 100, "C layout of entvars_t: offsetof punchangle")
    static_assert(typeinfo offsetof<classname>(type<entvars_t>) == 112, "C layout of entvars_t: offsetof classname")
    static_assert(typeinfo offsetof<model>(type<entvars_t>) == 116, "C layout of entvars_t: offsetof model")
    static_assert(typeinfo offsetof<frame>(type<entvars_t>) == 120, "C layout of entvars_t: offsetof frame")
    static_assert(typeinfo offsetof<skin>(type<entvars_t>) == 124, "C layout of entvars_t: offsetof skin")
    static_assert(typeinfo offsetof<effects>(type<entvars_t>) == 128, "C layout of entvars_t: offsetof effects")
    static_assert(typeinfo offsetof<mins>(type<entvars_t>) == 132, "C layout of entvars_t: offsetof mins")
    static_assert(typeinfo offsetof<maxs>(type<entvars_t>) == 144, "C layout of entvars_t: offsetof maxs")
    static_assert(typeinfo offsetof<size>(type<entvars_t>) == 156, "C layout of entvars_t: offsetof size")
    static_assert(typeinfo offsetof<touch>(type<entvars_t>) == 168, "C layout of entvars_t: offsetof touch")
    static_assert(typeinfo offsetof<use>(type<entvars_t>) == 172, "C layout of entvars_t: offsetof use")
    static_assert(typeinfo offsetof<think>(type<entvars_t>) == 176, "C layout of entvars_t: offsetof think")
    static_assert(typeinfo offsetof<blocked>(type<entvars_t>) == 180, "C layout of entvars_t: offsetof blocked")
    static_assert(typeinfo offsetof<nextthink>(type<entvars_t>) == 184, "C layout of entvars_t: offsetof nextthink")
    static_assert(typeinfo offsetof<groundentity>(type<entvars_t>) == 188, "C layout of entvars_t: offsetof groundentity")
    static_assert(typeinfo offsetof<health>(type<entvars_t>) == 192, "C layout of entvars_t: offsetof health")
    static_assert(typeinfo offsetof<frags>(type<entvars_t>) == 196, "C layout of entvars_t: offsetof frags")
    static_assert(typeinfo offsetof<weapon>(type<entvars_t>) == 200, "C layout of entvars_t: offsetof weapon")
    static_assert(typeinfo offsetof<weaponmodel>(type<entvars_t>) == 204, "C layout of entvars_t: offsetof weaponmodel")
    static_assert(typeinfo offsetof<weaponframe>(type<entvars_t>) == 208, "C layout of entvars_t: offsetof weaponframe")
    static_assert(typeinfo offsetof<currentammo>(type<entvars_t>) == 212, "C layout of entvars_t: offsetof currentammo")
    static_assert(typeinfo offsetof<ammo_shells>(type<entvars_t>) == 216, "C layout of entvars_t: offsetof ammo_shells")
    static_assert(typeinfo offsetof<ammo_nails>(type<entvars_t>) == 220, "C layout of entvars_t: offsetof ammo_nails")
    static_assert(typeinfo offsetof<ammo_rockets>(type<entvars_t>) == 224, "C layout of entvars_t: offsetof ammo_rockets")
    static_assert(typeinfo offsetof<ammo_cells>(type<entvars_t>) == 228, "C layout of entvars_t: offsetof ammo_cells")
    static_assert(typeinfo offsetof<items>(type<entvars_t>) == 232, "C layout of entvars_t: offsetof items")
    static_assert(typeinfo offsetof<takedamage>(type<entvars_t>) == 236, "C layout of entvars_t: offsetof takedamage")
    static_assert(typeinfo offsetof<chain>(type<entvars_t>) == 240, "C layout of entvars_t: offsetof chain")
    static_assert(typeinfo offsetof<deadflag>(type<entvars_t>) == 244, "C layout of entvars_t: offsetof deadflag")
    static_assert(typeinfo offsetof<view_ofs>(type<entvars_t>) == 248, "C layout of entvars_t: offsetof view_ofs")
    static_assert(typeinfo offsetof<button0>(type<entvars_t>) == 260, "C layout of entvars_t: offsetof button0")
    static_assert(typeinfo offsetof<button1>(type<entvars_t>) == 264, "C layout of entvars_t: offsetof button1")
    static_assert(typeinfo offsetof<button2>(type<entvars_t>) == 268, "C layout of entvars_t: offsetof button2")
    static_assert(typeinfo offsetof<impulse>(type<entvars_t>) == 272, "C layout of entvars_t: offsetof impulse")
    static_assert(typeinfo offsetof<fixangle>(type<entvars_t>) == 276, "C layout of entvars_t: offsetof fixangle")
    static_assert(typeinfo offsetof<v_angle>(type<entvars_t>) == 280, "C layout of entvars_t: offsetof v_angle")
    static_assert(typeinfo offsetof<idealpitch>(type<entvars_t>) == 292, "C layout of entvars_t: offsetof idealpitch")
    static_assert(typeinfo offsetof<netname>(type<entvars_t>) == 296, "C layout of entvars_t: offsetof netname")
    static_assert(typeinfo offsetof<enemy>(type<entvars_t>) == 300, "C layout of entvars_t: offsetof enemy")
    static_assert(typeinfo offsetof<flags>(type<entvars_t>) == 304, "C layout of entvars_t: offsetof flags")
    static_assert(typeinfo offsetof<colormap>(type<entvars_t>) == 308, "C layout of entvars_t: offsetof colormap")
    static_assert(typeinfo offsetof<team>(type<entvars_t>) == 312, "C layout of entvars_t: offsetof team")
    static_assert(typeinfo offsetof<max_health>(type<entvars_t>) == 316, "C layout of entvars_t: offsetof max_health")
    static_assert(typeinfo offsetof<teleport_time>(type<entvars_t>) == 320, "C layout of entvars_t: offsetof teleport_time")
    static_assert(typeinfo offsetof<armortype>(type<entvars_t>) == 324, "C layout of entvars_t: offsetof armortype")
    static_assert(typeinfo offsetof<armorvalue>(type<entvars_t>) == 328, "C layout of entvars_t: offsetof armorvalue")
    static_assert(typeinfo offsetof<waterlevel>(type<entvars_t>) == 332, "C layout of entvars_t: offsetof waterlevel")
    static_assert(typeinfo offsetof<watertype>(type<entvars_t>) == 336, "C layout of entvars_t: offsetof watertype")
    static_assert(typeinfo offsetof<ideal_yaw>(type<entvars_t>) == 340, "C layout of entvars_t: offsetof ideal_yaw")
    static_assert(typeinfo offsetof<yaw_speed>(type<entvars_t>) == 344, "C layout of entvars_t: offsetof yaw_speed")
    static_assert(typeinfo offsetof<aiment>(type<entvars_t>) == 348, "C layout of entvars_t: offsetof aiment")
    static_assert(typeinfo offsetof<goalentity>(type<entvars_t>) == 352, "C layout of entvars_t: offsetof goalentity")
    static_assert(typeinfo offsetof<spawnflags>(type<entvars_t>) == 356, "C layout of entvars_t: offsetof spawnflags")
    static_assert(typeinfo offsetof<target>(type<entvars_t>) == 360, "C layout of entvars_t: offsetof target")
    static_assert(typeinfo offsetof<targetname>(type<entvars_t>) == 364, "C layout of entvars_t: offsetof targetname")
    static_assert(typeinfo offsetof<dmg_take>(type<entvars_t>) == 368, "C layout of entvars_t: offsetof dmg_take")
    static_assert(typeinfo offsetof<dmg_save>(type<entvars_t>) == 372, "C layout of entvars_t: offsetof dmg_save")
    static_assert(typeinfo offsetof<dmg_inflictor>(type<entvars_t>) == 376, "C layout of entvars_t: offsetof dmg_inflictor")
    static_assert(typeinfo offsetof<owner>(type<entvars_t>) == 380, "C layout of entvars_t: offsetof owner")
    static_assert(typeinfo offsetof<movedir>(type<entvars_t>) == 384, "C layout of entvars_t: offsetof movedir")
    static_assert(typeinfo offsetof<message>(type<entvars_t>) == 396, "C layout of entvars_t: offsetof message")
    static_assert(typeinfo offsetof<sounds>(type<entvars_t>) == 400, "C layout of entvars_t: offsetof sounds")
    static_assert(typeinfo offsetof<noise>(type<entvars_t>) == 404, "C layout of entvars_t: offsetof noise")
    static_assert(typeinfo offsetof<noise1>(type<entvars_t>) == 408, "C layout of entvars_t: offsetof noise1")
    static_assert(typeinfo offsetof<noise2>(type<entvars_t>) == 412, "C layout of entvars_t: offsetof noise2")
    static_assert(typeinfo offsetof<noise3>(type<entvars_t>) == 416, "C layout of entvars_t: offsetof noise3")
    static_assert(typeinfo sizeof(type<edict_s>) == 528, "C layout of edict_s: sizeof")
    static_assert(typeinfo alignof(type<edict_s>) == 8, "C layout of edict_s: alignof")
    static_assert(typeinfo offsetof<free>(type<edict_s>) == 0, "C layout of edict_s: offsetof free")
    static_assert(typeinfo offsetof<area>(type<edict_s>) == 8, "C layout of edict_s: offsetof area")
    static_assert(typeinfo offsetof<num_leafs>(type<edict_s>) == 24, "C layout of edict_s: offsetof num_leafs")
    static_assert(typeinfo offsetof<leafnums>(type<edict_s>) == 28, "C layout of edict_s: offsetof leafnums")
    static_assert(typeinfo offsetof<baseline>(type<edict_s>) == 60, "C layout of edict_s: offsetof baseline")
    static_assert(typeinfo offsetof<freetime>(type<edict_s>) == 104, "C layout of edict_s: offsetof freetime")
    static_assert(typeinfo offsetof<v>(type<edict_s>) == 108, "C layout of edict_s: offsetof v")
    static_assert(typeinfo sizeof(type<edict_t>) == 528, "C layout of edict_t: sizeof")
    static_assert(typeinfo alignof(type<edict_t>) == 8, "C layout of edict_t: alignof")
    static_assert(typeinfo offsetof<free>(type<edict_t>) == 0, "C layout of edict_t: offsetof free")
    static_assert(typeinfo offsetof<area>(type<edict_t>) == 8, "C layout of edict_t: offsetof area")
    static_assert(typeinfo offsetof<num_leafs>(type<edict_t>) == 24, "C layout of edict_t: offsetof num_leafs")
    static_assert(typeinfo offsetof<leafnums>(type<edict_t>) == 28, "C layout of edict_t: offsetof leafnums")
    static_assert(typeinfo offsetof<baseline>(type<edict_t>) == 60, "C layout of edict_t: offsetof baseline")
    static_assert(typeinfo offsetof<freetime>(type<edict_t>) == 104, "C layout of edict_t: offsetof freetime")
    static_assert(typeinfo offsetof<v>(type<edict_t>) == 108, "C layout of edict_t: offsetof v")
    static_assert(typeinfo sizeof(type<server_t>) == 17168, "C layout of server_t: sizeof")
    static_assert(typeinfo alignof(type<server_t>) == 8, "C layout of server_t: alignof")
    static_assert(typeinfo offsetof<active>(type<server_t>) == 0, "C layout of server_t: offsetof active")
    static_assert(typeinfo offsetof<paused>(type<server_t>) == 4, "C layout of server_t: offsetof paused")
    static_assert(typeinfo offsetof<loadgame>(type<server_t>) == 8, "C layout of server_t: offsetof loadgame")
    static_assert(typeinfo offsetof<time>(type<server_t>) == 16, "C layout of server_t: offsetof time")
    static_assert(typeinfo offsetof<lastcheck>(type<server_t>) == 24, "C layout of server_t: offsetof lastcheck")
    static_assert(typeinfo offsetof<lastchecktime>(type<server_t>) == 32, "C layout of server_t: offsetof lastchecktime")
    static_assert(typeinfo offsetof<name>(type<server_t>) == 40, "C layout of server_t: offsetof name")
    static_assert(typeinfo offsetof<modelname>(type<server_t>) == 104, "C layout of server_t: offsetof modelname")
    static_assert(typeinfo offsetof<worldmodel>(type<server_t>) == 168, "C layout of server_t: offsetof worldmodel")
    static_assert(typeinfo offsetof<model_precache>(type<server_t>) == 176, "C layout of server_t: offsetof model_precache")
    static_assert(typeinfo offsetof<models>(type<server_t>) == 2224, "C layout of server_t: offsetof models")
    static_assert(typeinfo offsetof<sound_precache>(type<server_t>) == 4272, "C layout of server_t: offsetof sound_precache")
    static_assert(typeinfo offsetof<lightstyles>(type<server_t>) == 6320, "C layout of server_t: offsetof lightstyles")
    static_assert(typeinfo offsetof<num_edicts>(type<server_t>) == 6832, "C layout of server_t: offsetof num_edicts")
    static_assert(typeinfo offsetof<max_edicts>(type<server_t>) == 6836, "C layout of server_t: offsetof max_edicts")
    static_assert(typeinfo offsetof<edicts>(type<server_t>) == 6840, "C layout of server_t: offsetof edicts")
    static_assert(typeinfo offsetof<state>(type<server_t>) == 6848, "C layout of server_t: offsetof state")
    static_assert(typeinfo offsetof<datagram>(type<server_t>) == 6856, "C layout of server_t: offsetof datagram")
    static_assert(typeinfo offsetof<datagram_buf>(type<server_t>) == 6880, "C layout of server_t: offsetof datagram_buf")
    static_assert(typeinfo offsetof<reliable_datagram>(type<server_t>) == 7904, "C layout of server_t: offsetof reliable_datagram")
    static_assert(typeinfo offsetof<reliable_datagram_buf>(type<server_t>) == 7928, "C layout of server_t: offsetof reliable_datagram_buf")
    static_assert(typeinfo offsetof<signon>(type<server_t>) == 8952, "C layout of server_t: offsetof signon")
    static_assert(typeinfo offsetof<signon_buf>(type<server_t>) == 8976, "C layout of server_t: offsetof signon_buf")
}
