var private R_RocketTrail__tracercount : int = 0

[export, sideeffects]
def R_ParseParticleEffect() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_ParseParticleEffect_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_RunParticleEffect(var org : int; var dir : int; var color_0 : int; var count_0 : int) {
    var j : int
    var p : int
    for (i_0 in range(0, count_0)) {
        if (free_particles == 0) {
            return
        }
        p = free_particles
        free_particles = int(uint(c2da_mem[p + 16]) | uint(c2da_mem[p + 17]) << 0x8 | uint(c2da_mem[p + 18]) << 0x10 | uint(c2da_mem[p + 19]) << 0x18)
        let c2da_fresh4 : uint = uint(active_particles)
        c2da_mem[p + 16] = uint8(c2da_fresh4)
        c2da_mem[p + 17] = uint8(c2da_fresh4 >> 0x8)
        c2da_mem[p + 18] = uint8(c2da_fresh4 >> 0x10)
        c2da_mem[p + 19] = uint8(c2da_fresh4 >> 0x18)
        c2da_mem[p + 20] = 0u8
        c2da_mem[p + 21] = 0u8
        c2da_mem[p + 22] = 0u8
        c2da_mem[p + 23] = 0u8
        active_particles = p
        if (count_0 == 1024) {
            let c2da_fresh5 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 5.0lf)
            let c2da_fresh6 : uint = float_bits_to_uint(c2da_fresh5)
            c2da_mem[p + 40] = uint8(c2da_fresh6)
            c2da_mem[p + 41] = uint8(c2da_fresh6 >> 0x8)
            c2da_mem[p + 42] = uint8(c2da_fresh6 >> 0x10)
            c2da_mem[p + 43] = uint8(c2da_fresh6 >> 0x18)
            let c2da_fresh7 : float = float(ramp1[0])
            let c2da_fresh8 : uint = float_bits_to_uint(c2da_fresh7)
            c2da_mem[p + 12] = uint8(c2da_fresh8)
            c2da_mem[p + 13] = uint8(c2da_fresh8 >> 0x8)
            c2da_mem[p + 14] = uint8(c2da_fresh8 >> 0x10)
            c2da_mem[p + 15] = uint8(c2da_fresh8 >> 0x18)
            let c2da_fresh9 : float = float(c2da_std_rand() & 3)
            let c2da_fresh10 : uint = float_bits_to_uint(c2da_fresh9)
            c2da_mem[p + 36] = uint8(c2da_fresh10)
            c2da_mem[p + 37] = uint8(c2da_fresh10 >> 0x8)
            c2da_mem[p + 38] = uint8(c2da_fresh10 >> 0x10)
            c2da_mem[p + 39] = uint8(c2da_fresh10 >> 0x18)
            if ((i_0 & 1) != 0) {
                let c2da_fresh11 : uint = 4u
                let c2da_fresh12 : uint = c2da_fresh11
                c2da_mem[p + 44] = uint8(c2da_fresh12)
                c2da_mem[p + 45] = uint8(c2da_fresh12 >> 0x8)
                c2da_mem[p + 46] = uint8(c2da_fresh12 >> 0x10)
                c2da_mem[p + 47] = uint8(c2da_fresh12 >> 0x18)
                j = 0
                while (j < 3) {
                    let c2da_fresh13 : float = uint_bits_to_float(uint(c2da_mem[org + j * 4]) | uint(c2da_mem[org + j * 4 + 1]) << 0x8 | uint(c2da_mem[org + j * 4 + 2]) << 0x10 | uint(c2da_mem[org + j * 4 + 3]) << 0x18) + float(c2da_std_rand() % 32 - 16)
                    let c2da_fresh14 : uint = float_bits_to_uint(c2da_fresh13)
                    c2da_mem[p + j * 4] = uint8(c2da_fresh14)
                    c2da_mem[p + j * 4 + 1] = uint8(c2da_fresh14 >> 0x8)
                    c2da_mem[p + j * 4 + 2] = uint8(c2da_fresh14 >> 0x10)
                    c2da_mem[p + j * 4 + 3] = uint8(c2da_fresh14 >> 0x18)
                    let c2da_fresh15 : float = float(c2da_std_rand() % 512 - 256)
                    let c2da_fresh16 : uint = float_bits_to_uint(c2da_fresh15)
                    c2da_mem[p + 24 + j * 4] = uint8(c2da_fresh16)
                    c2da_mem[p + 24 + j * 4 + 1] = uint8(c2da_fresh16 >> 0x8)
                    c2da_mem[p + 24 + j * 4 + 2] = uint8(c2da_fresh16 >> 0x10)
                    c2da_mem[p + 24 + j * 4 + 3] = uint8(c2da_fresh16 >> 0x18)
                    j++
                }
            } else {
                let c2da_fresh17 : uint = 5u
                let c2da_fresh18 : uint = c2da_fresh17
                c2da_mem[p + 44] = uint8(c2da_fresh18)
                c2da_mem[p + 45] = uint8(c2da_fresh18 >> 0x8)
                c2da_mem[p + 46] = uint8(c2da_fresh18 >> 0x10)
                c2da_mem[p + 47] = uint8(c2da_fresh18 >> 0x18)
                j = 0
                while (j < 3) {
                    let c2da_fresh19 : float = uint_bits_to_float(uint(c2da_mem[org + j * 4]) | uint(c2da_mem[org + j * 4 + 1]) << 0x8 | uint(c2da_mem[org + j * 4 + 2]) << 0x10 | uint(c2da_mem[org + j * 4 + 3]) << 0x18) + float(c2da_std_rand() % 32 - 16)
                    let c2da_fresh20 : uint = float_bits_to_uint(c2da_fresh19)
                    c2da_mem[p + j * 4] = uint8(c2da_fresh20)
                    c2da_mem[p + j * 4 + 1] = uint8(c2da_fresh20 >> 0x8)
                    c2da_mem[p + j * 4 + 2] = uint8(c2da_fresh20 >> 0x10)
                    c2da_mem[p + j * 4 + 3] = uint8(c2da_fresh20 >> 0x18)
                    let c2da_fresh21 : float = float(c2da_std_rand() % 512 - 256)
                    let c2da_fresh22 : uint = float_bits_to_uint(c2da_fresh21)
                    c2da_mem[p + 24 + j * 4] = uint8(c2da_fresh22)
                    c2da_mem[p + 24 + j * 4 + 1] = uint8(c2da_fresh22 >> 0x8)
                    c2da_mem[p + 24 + j * 4 + 2] = uint8(c2da_fresh22 >> 0x10)
                    c2da_mem[p + 24 + j * 4 + 3] = uint8(c2da_fresh22 >> 0x18)
                    j++
                }
            }
        } else {
            let c2da_fresh23 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.1lf * double(c2da_std_rand() % 5))
            let c2da_fresh24 : uint = float_bits_to_uint(c2da_fresh23)
            c2da_mem[p + 40] = uint8(c2da_fresh24)
            c2da_mem[p + 41] = uint8(c2da_fresh24 >> 0x8)
            c2da_mem[p + 42] = uint8(c2da_fresh24 >> 0x10)
            c2da_mem[p + 43] = uint8(c2da_fresh24 >> 0x18)
            let c2da_fresh25 : float = float((color_0 & ~7) + (c2da_std_rand() & 7))
            let c2da_fresh26 : uint = float_bits_to_uint(c2da_fresh25)
            c2da_mem[p + 12] = uint8(c2da_fresh26)
            c2da_mem[p + 13] = uint8(c2da_fresh26 >> 0x8)
            c2da_mem[p + 14] = uint8(c2da_fresh26 >> 0x10)
            c2da_mem[p + 15] = uint8(c2da_fresh26 >> 0x18)
            let c2da_fresh27 : uint = 2u
            let c2da_fresh28 : uint = c2da_fresh27
            c2da_mem[p + 44] = uint8(c2da_fresh28)
            c2da_mem[p + 45] = uint8(c2da_fresh28 >> 0x8)
            c2da_mem[p + 46] = uint8(c2da_fresh28 >> 0x10)
            c2da_mem[p + 47] = uint8(c2da_fresh28 >> 0x18)
            j = 0
            while (j < 3) {
                let c2da_fresh29 : float = uint_bits_to_float(uint(c2da_mem[org + j * 4]) | uint(c2da_mem[org + j * 4 + 1]) << 0x8 | uint(c2da_mem[org + j * 4 + 2]) << 0x10 | uint(c2da_mem[org + j * 4 + 3]) << 0x18) + float((c2da_std_rand() & 15) - 8)
                let c2da_fresh30 : uint = float_bits_to_uint(c2da_fresh29)
                c2da_mem[p + j * 4] = uint8(c2da_fresh30)
                c2da_mem[p + j * 4 + 1] = uint8(c2da_fresh30 >> 0x8)
                c2da_mem[p + j * 4 + 2] = uint8(c2da_fresh30 >> 0x10)
                c2da_mem[p + j * 4 + 3] = uint8(c2da_fresh30 >> 0x18)
                let c2da_fresh31 : float = uint_bits_to_float(uint(c2da_mem[dir + j * 4]) | uint(c2da_mem[dir + j * 4 + 1]) << 0x8 | uint(c2da_mem[dir + j * 4 + 2]) << 0x10 | uint(c2da_mem[dir + j * 4 + 3]) << 0x18) * 15.0
                let c2da_fresh32 : uint = float_bits_to_uint(c2da_fresh31)
                c2da_mem[p + 24 + j * 4] = uint8(c2da_fresh32)
                c2da_mem[p + 24 + j * 4 + 1] = uint8(c2da_fresh32 >> 0x8)
                c2da_mem[p + 24 + j * 4 + 2] = uint8(c2da_fresh32 >> 0x10)
                c2da_mem[p + 24 + j * 4 + 3] = uint8(c2da_fresh32 >> 0x18)
                j++
            }
        }
    }
    return
}
var ramp1 : int[8] = fixed_array<int>(111, 109, 107, 105, 103, 101, 99, 97)

var active_particles : int = default<int>

var free_particles : int = default<int>

[export, sideeffects]
def R_RocketTrail(var start : int; var end : int; var type_0 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_RocketTrail_c2da_frame(start, end, type_0, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
var ramp3 : int[8] = fixed_array<int>(109, 107, 6, 5, 4, 3, 0, 0)

[export, sideeffects]
def R_EntityParticles(var ent : int) {
    var count_1 : int
    var i_1 : int
    var p_1 : int
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
    if (avelocities[0][0] == 0.0) {
        i_1 = 0
        while (i_1 < 162 * 3) {
            avelocities[0][i_1] = float(double(c2da_std_rand() & 255) * 0.01lf)
            i_1++
        }
    }
    i_1 = 0
    for (c2da_i_1 in range(i_1, 162)) {
        angle = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) * double(avelocities[c2da_i_1][0]))
        sy = float(sin(double(angle)))
        cy = float(cos(double(angle)))
        angle = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) * double(avelocities[c2da_i_1][1]))
        sp = float(sin(double(angle)))
        cp = float(cos(double(angle)))
        angle = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) * double(avelocities[c2da_i_1][2]))
        sr = float(sin(double(angle)))
        cr = float(cos(double(angle)))
        forward_0[0] = cp * cy
        forward_0[1] = cp * sy
        forward_0[2] = -sp
        if (free_particles == 0) {
            return
        }
        p_1 = free_particles
        free_particles = int(uint(c2da_mem[p_1 + 16]) | uint(c2da_mem[p_1 + 17]) << 0x8 | uint(c2da_mem[p_1 + 18]) << 0x10 | uint(c2da_mem[p_1 + 19]) << 0x18)
        let c2da_fresh112 : uint = uint(active_particles)
        c2da_mem[p_1 + 16] = uint8(c2da_fresh112)
        c2da_mem[p_1 + 17] = uint8(c2da_fresh112 >> 0x8)
        c2da_mem[p_1 + 18] = uint8(c2da_fresh112 >> 0x10)
        c2da_mem[p_1 + 19] = uint8(c2da_fresh112 >> 0x18)
        c2da_mem[p_1 + 20] = 0u8
        c2da_mem[p_1 + 21] = 0u8
        c2da_mem[p_1 + 22] = 0u8
        c2da_mem[p_1 + 23] = 0u8
        active_particles = p_1
        let c2da_fresh113 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.01lf)
        let c2da_fresh114 : uint = float_bits_to_uint(c2da_fresh113)
        c2da_mem[p_1 + 40] = uint8(c2da_fresh114)
        c2da_mem[p_1 + 41] = uint8(c2da_fresh114 >> 0x8)
        c2da_mem[p_1 + 42] = uint8(c2da_fresh114 >> 0x10)
        c2da_mem[p_1 + 43] = uint8(c2da_fresh114 >> 0x18)
        let c2da_fresh115 : float = 111.0
        let c2da_fresh116 : uint = float_bits_to_uint(c2da_fresh115)
        c2da_mem[p_1 + 12] = uint8(c2da_fresh116)
        c2da_mem[p_1 + 13] = uint8(c2da_fresh116 >> 0x8)
        c2da_mem[p_1 + 14] = uint8(c2da_fresh116 >> 0x10)
        c2da_mem[p_1 + 15] = uint8(c2da_fresh116 >> 0x18)
        let c2da_fresh117 : uint = 4u
        let c2da_fresh118 : uint = c2da_fresh117
        c2da_mem[p_1 + 44] = uint8(c2da_fresh118)
        c2da_mem[p_1 + 45] = uint8(c2da_fresh118 >> 0x8)
        c2da_mem[p_1 + 46] = uint8(c2da_fresh118 >> 0x10)
        c2da_mem[p_1 + 47] = uint8(c2da_fresh118 >> 0x18)
        let c2da_fresh119 : float = uint_bits_to_float(uint(c2da_mem[ent + 88 + 0 * 4]) | uint(c2da_mem[ent + 88 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[389392 + c2da_i_1 * 12 + 0 * 4]) | uint(c2da_mem[389392 + c2da_i_1 * 12 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[389392 + c2da_i_1 * 12 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[389392 + c2da_i_1 * 12 + 0 * 4 + 3]) << 0x18) * dist + forward_0[0] * beamlength
        let c2da_fresh120 : uint = float_bits_to_uint(c2da_fresh119)
        c2da_mem[p_1 + 0 * 4] = uint8(c2da_fresh120)
        c2da_mem[p_1 + 0 * 4 + 1] = uint8(c2da_fresh120 >> 0x8)
        c2da_mem[p_1 + 0 * 4 + 2] = uint8(c2da_fresh120 >> 0x10)
        c2da_mem[p_1 + 0 * 4 + 3] = uint8(c2da_fresh120 >> 0x18)
        let c2da_fresh121 : float = uint_bits_to_float(uint(c2da_mem[ent + 88 + 1 * 4]) | uint(c2da_mem[ent + 88 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[389392 + c2da_i_1 * 12 + 1 * 4]) | uint(c2da_mem[389392 + c2da_i_1 * 12 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[389392 + c2da_i_1 * 12 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[389392 + c2da_i_1 * 12 + 1 * 4 + 3]) << 0x18) * dist + forward_0[1] * beamlength
        let c2da_fresh122 : uint = float_bits_to_uint(c2da_fresh121)
        c2da_mem[p_1 + 1 * 4] = uint8(c2da_fresh122)
        c2da_mem[p_1 + 1 * 4 + 1] = uint8(c2da_fresh122 >> 0x8)
        c2da_mem[p_1 + 1 * 4 + 2] = uint8(c2da_fresh122 >> 0x10)
        c2da_mem[p_1 + 1 * 4 + 3] = uint8(c2da_fresh122 >> 0x18)
        let c2da_fresh123 : float = uint_bits_to_float(uint(c2da_mem[ent + 88 + 2 * 4]) | uint(c2da_mem[ent + 88 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 88 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 88 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[389392 + c2da_i_1 * 12 + 2 * 4]) | uint(c2da_mem[389392 + c2da_i_1 * 12 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[389392 + c2da_i_1 * 12 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[389392 + c2da_i_1 * 12 + 2 * 4 + 3]) << 0x18) * dist + forward_0[2] * beamlength
        let c2da_fresh124 : uint = float_bits_to_uint(c2da_fresh123)
        c2da_mem[p_1 + 2 * 4] = uint8(c2da_fresh124)
        c2da_mem[p_1 + 2 * 4 + 1] = uint8(c2da_fresh124 >> 0x8)
        c2da_mem[p_1 + 2 * 4 + 2] = uint8(c2da_fresh124 >> 0x10)
        c2da_mem[p_1 + 2 * 4 + 3] = uint8(c2da_fresh124 >> 0x18)
    }
    return
}
var beamlength : float = 16.0

var avelocities : vec3_t[162]

[export, sideeffects]
def R_BlobExplosion(var org_0 : int) {
    var j_1 : int
    var p_2 : int
    for (i_2 in range(0, 1024)) {
        if (free_particles == 0) {
            return
        }
        p_2 = free_particles
        free_particles = int(uint(c2da_mem[p_2 + 16]) | uint(c2da_mem[p_2 + 17]) << 0x8 | uint(c2da_mem[p_2 + 18]) << 0x10 | uint(c2da_mem[p_2 + 19]) << 0x18)
        let c2da_fresh125 : uint = uint(active_particles)
        c2da_mem[p_2 + 16] = uint8(c2da_fresh125)
        c2da_mem[p_2 + 17] = uint8(c2da_fresh125 >> 0x8)
        c2da_mem[p_2 + 18] = uint8(c2da_fresh125 >> 0x10)
        c2da_mem[p_2 + 19] = uint8(c2da_fresh125 >> 0x18)
        c2da_mem[p_2 + 20] = 0u8
        c2da_mem[p_2 + 21] = 0u8
        c2da_mem[p_2 + 22] = 0u8
        c2da_mem[p_2 + 23] = 0u8
        active_particles = p_2
        let c2da_fresh126 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 1.0lf + double(c2da_std_rand() & 8) * 0.05lf)
        let c2da_fresh127 : uint = float_bits_to_uint(c2da_fresh126)
        c2da_mem[p_2 + 40] = uint8(c2da_fresh127)
        c2da_mem[p_2 + 41] = uint8(c2da_fresh127 >> 0x8)
        c2da_mem[p_2 + 42] = uint8(c2da_fresh127 >> 0x10)
        c2da_mem[p_2 + 43] = uint8(c2da_fresh127 >> 0x18)
        if ((i_2 & 1) != 0) {
            let c2da_fresh128 : uint = 6u
            let c2da_fresh129 : uint = c2da_fresh128
            c2da_mem[p_2 + 44] = uint8(c2da_fresh129)
            c2da_mem[p_2 + 45] = uint8(c2da_fresh129 >> 0x8)
            c2da_mem[p_2 + 46] = uint8(c2da_fresh129 >> 0x10)
            c2da_mem[p_2 + 47] = uint8(c2da_fresh129 >> 0x18)
            let c2da_fresh130 : float = float(66 + c2da_std_rand() % 6)
            let c2da_fresh131 : uint = float_bits_to_uint(c2da_fresh130)
            c2da_mem[p_2 + 12] = uint8(c2da_fresh131)
            c2da_mem[p_2 + 13] = uint8(c2da_fresh131 >> 0x8)
            c2da_mem[p_2 + 14] = uint8(c2da_fresh131 >> 0x10)
            c2da_mem[p_2 + 15] = uint8(c2da_fresh131 >> 0x18)
            j_1 = 0
            while (j_1 < 3) {
                let c2da_fresh132 : float = uint_bits_to_float(uint(c2da_mem[org_0 + j_1 * 4]) | uint(c2da_mem[org_0 + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[org_0 + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[org_0 + j_1 * 4 + 3]) << 0x18) + float(c2da_std_rand() % 32 - 16)
                let c2da_fresh133 : uint = float_bits_to_uint(c2da_fresh132)
                c2da_mem[p_2 + j_1 * 4] = uint8(c2da_fresh133)
                c2da_mem[p_2 + j_1 * 4 + 1] = uint8(c2da_fresh133 >> 0x8)
                c2da_mem[p_2 + j_1 * 4 + 2] = uint8(c2da_fresh133 >> 0x10)
                c2da_mem[p_2 + j_1 * 4 + 3] = uint8(c2da_fresh133 >> 0x18)
                let c2da_fresh134 : float = float(c2da_std_rand() % 512 - 256)
                let c2da_fresh135 : uint = float_bits_to_uint(c2da_fresh134)
                c2da_mem[p_2 + 24 + j_1 * 4] = uint8(c2da_fresh135)
                c2da_mem[p_2 + 24 + j_1 * 4 + 1] = uint8(c2da_fresh135 >> 0x8)
                c2da_mem[p_2 + 24 + j_1 * 4 + 2] = uint8(c2da_fresh135 >> 0x10)
                c2da_mem[p_2 + 24 + j_1 * 4 + 3] = uint8(c2da_fresh135 >> 0x18)
                j_1++
            }
        } else {
            let c2da_fresh136 : uint = 7u
            let c2da_fresh137 : uint = c2da_fresh136
            c2da_mem[p_2 + 44] = uint8(c2da_fresh137)
            c2da_mem[p_2 + 45] = uint8(c2da_fresh137 >> 0x8)
            c2da_mem[p_2 + 46] = uint8(c2da_fresh137 >> 0x10)
            c2da_mem[p_2 + 47] = uint8(c2da_fresh137 >> 0x18)
            let c2da_fresh138 : float = float(150 + c2da_std_rand() % 6)
            let c2da_fresh139 : uint = float_bits_to_uint(c2da_fresh138)
            c2da_mem[p_2 + 12] = uint8(c2da_fresh139)
            c2da_mem[p_2 + 13] = uint8(c2da_fresh139 >> 0x8)
            c2da_mem[p_2 + 14] = uint8(c2da_fresh139 >> 0x10)
            c2da_mem[p_2 + 15] = uint8(c2da_fresh139 >> 0x18)
            j_1 = 0
            while (j_1 < 3) {
                let c2da_fresh140 : float = uint_bits_to_float(uint(c2da_mem[org_0 + j_1 * 4]) | uint(c2da_mem[org_0 + j_1 * 4 + 1]) << 0x8 | uint(c2da_mem[org_0 + j_1 * 4 + 2]) << 0x10 | uint(c2da_mem[org_0 + j_1 * 4 + 3]) << 0x18) + float(c2da_std_rand() % 32 - 16)
                let c2da_fresh141 : uint = float_bits_to_uint(c2da_fresh140)
                c2da_mem[p_2 + j_1 * 4] = uint8(c2da_fresh141)
                c2da_mem[p_2 + j_1 * 4 + 1] = uint8(c2da_fresh141 >> 0x8)
                c2da_mem[p_2 + j_1 * 4 + 2] = uint8(c2da_fresh141 >> 0x10)
                c2da_mem[p_2 + j_1 * 4 + 3] = uint8(c2da_fresh141 >> 0x18)
                let c2da_fresh142 : float = float(c2da_std_rand() % 512 - 256)
                let c2da_fresh143 : uint = float_bits_to_uint(c2da_fresh142)
                c2da_mem[p_2 + 24 + j_1 * 4] = uint8(c2da_fresh143)
                c2da_mem[p_2 + 24 + j_1 * 4 + 1] = uint8(c2da_fresh143 >> 0x8)
                c2da_mem[p_2 + 24 + j_1 * 4 + 2] = uint8(c2da_fresh143 >> 0x10)
                c2da_mem[p_2 + 24 + j_1 * 4 + 3] = uint8(c2da_fresh143 >> 0x18)
                j_1++
            }
        }
    }
    return
}
[export, sideeffects]
def R_ParticleExplosion(var org_1 : int) {
    var j_2 : int
    var p_3 : int
    for (i_3 in range(0, 1024)) {
        if (free_particles == 0) {
            return
        }
        p_3 = free_particles
        free_particles = int(uint(c2da_mem[p_3 + 16]) | uint(c2da_mem[p_3 + 17]) << 0x8 | uint(c2da_mem[p_3 + 18]) << 0x10 | uint(c2da_mem[p_3 + 19]) << 0x18)
        let c2da_fresh144 : uint = uint(active_particles)
        c2da_mem[p_3 + 16] = uint8(c2da_fresh144)
        c2da_mem[p_3 + 17] = uint8(c2da_fresh144 >> 0x8)
        c2da_mem[p_3 + 18] = uint8(c2da_fresh144 >> 0x10)
        c2da_mem[p_3 + 19] = uint8(c2da_fresh144 >> 0x18)
        c2da_mem[p_3 + 20] = 0u8
        c2da_mem[p_3 + 21] = 0u8
        c2da_mem[p_3 + 22] = 0u8
        c2da_mem[p_3 + 23] = 0u8
        active_particles = p_3
        let c2da_fresh145 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 5.0lf)
        let c2da_fresh146 : uint = float_bits_to_uint(c2da_fresh145)
        c2da_mem[p_3 + 40] = uint8(c2da_fresh146)
        c2da_mem[p_3 + 41] = uint8(c2da_fresh146 >> 0x8)
        c2da_mem[p_3 + 42] = uint8(c2da_fresh146 >> 0x10)
        c2da_mem[p_3 + 43] = uint8(c2da_fresh146 >> 0x18)
        let c2da_fresh147 : float = float(ramp1[0])
        let c2da_fresh148 : uint = float_bits_to_uint(c2da_fresh147)
        c2da_mem[p_3 + 12] = uint8(c2da_fresh148)
        c2da_mem[p_3 + 13] = uint8(c2da_fresh148 >> 0x8)
        c2da_mem[p_3 + 14] = uint8(c2da_fresh148 >> 0x10)
        c2da_mem[p_3 + 15] = uint8(c2da_fresh148 >> 0x18)
        let c2da_fresh149 : float = float(c2da_std_rand() & 3)
        let c2da_fresh150 : uint = float_bits_to_uint(c2da_fresh149)
        c2da_mem[p_3 + 36] = uint8(c2da_fresh150)
        c2da_mem[p_3 + 37] = uint8(c2da_fresh150 >> 0x8)
        c2da_mem[p_3 + 38] = uint8(c2da_fresh150 >> 0x10)
        c2da_mem[p_3 + 39] = uint8(c2da_fresh150 >> 0x18)
        if ((i_3 & 1) != 0) {
            let c2da_fresh151 : uint = 4u
            let c2da_fresh152 : uint = c2da_fresh151
            c2da_mem[p_3 + 44] = uint8(c2da_fresh152)
            c2da_mem[p_3 + 45] = uint8(c2da_fresh152 >> 0x8)
            c2da_mem[p_3 + 46] = uint8(c2da_fresh152 >> 0x10)
            c2da_mem[p_3 + 47] = uint8(c2da_fresh152 >> 0x18)
            j_2 = 0
            while (j_2 < 3) {
                let c2da_fresh153 : float = uint_bits_to_float(uint(c2da_mem[org_1 + j_2 * 4]) | uint(c2da_mem[org_1 + j_2 * 4 + 1]) << 0x8 | uint(c2da_mem[org_1 + j_2 * 4 + 2]) << 0x10 | uint(c2da_mem[org_1 + j_2 * 4 + 3]) << 0x18) + float(c2da_std_rand() % 32 - 16)
                let c2da_fresh154 : uint = float_bits_to_uint(c2da_fresh153)
                c2da_mem[p_3 + j_2 * 4] = uint8(c2da_fresh154)
                c2da_mem[p_3 + j_2 * 4 + 1] = uint8(c2da_fresh154 >> 0x8)
                c2da_mem[p_3 + j_2 * 4 + 2] = uint8(c2da_fresh154 >> 0x10)
                c2da_mem[p_3 + j_2 * 4 + 3] = uint8(c2da_fresh154 >> 0x18)
                let c2da_fresh155 : float = float(c2da_std_rand() % 512 - 256)
                let c2da_fresh156 : uint = float_bits_to_uint(c2da_fresh155)
                c2da_mem[p_3 + 24 + j_2 * 4] = uint8(c2da_fresh156)
                c2da_mem[p_3 + 24 + j_2 * 4 + 1] = uint8(c2da_fresh156 >> 0x8)
                c2da_mem[p_3 + 24 + j_2 * 4 + 2] = uint8(c2da_fresh156 >> 0x10)
                c2da_mem[p_3 + 24 + j_2 * 4 + 3] = uint8(c2da_fresh156 >> 0x18)
                j_2++
            }
        } else {
            let c2da_fresh157 : uint = 5u
            let c2da_fresh158 : uint = c2da_fresh157
            c2da_mem[p_3 + 44] = uint8(c2da_fresh158)
            c2da_mem[p_3 + 45] = uint8(c2da_fresh158 >> 0x8)
            c2da_mem[p_3 + 46] = uint8(c2da_fresh158 >> 0x10)
            c2da_mem[p_3 + 47] = uint8(c2da_fresh158 >> 0x18)
            j_2 = 0
            while (j_2 < 3) {
                let c2da_fresh159 : float = uint_bits_to_float(uint(c2da_mem[org_1 + j_2 * 4]) | uint(c2da_mem[org_1 + j_2 * 4 + 1]) << 0x8 | uint(c2da_mem[org_1 + j_2 * 4 + 2]) << 0x10 | uint(c2da_mem[org_1 + j_2 * 4 + 3]) << 0x18) + float(c2da_std_rand() % 32 - 16)
                let c2da_fresh160 : uint = float_bits_to_uint(c2da_fresh159)
                c2da_mem[p_3 + j_2 * 4] = uint8(c2da_fresh160)
                c2da_mem[p_3 + j_2 * 4 + 1] = uint8(c2da_fresh160 >> 0x8)
                c2da_mem[p_3 + j_2 * 4 + 2] = uint8(c2da_fresh160 >> 0x10)
                c2da_mem[p_3 + j_2 * 4 + 3] = uint8(c2da_fresh160 >> 0x18)
                let c2da_fresh161 : float = float(c2da_std_rand() % 512 - 256)
                let c2da_fresh162 : uint = float_bits_to_uint(c2da_fresh161)
                c2da_mem[p_3 + 24 + j_2 * 4] = uint8(c2da_fresh162)
                c2da_mem[p_3 + 24 + j_2 * 4 + 1] = uint8(c2da_fresh162 >> 0x8)
                c2da_mem[p_3 + 24 + j_2 * 4 + 2] = uint8(c2da_fresh162 >> 0x10)
                c2da_mem[p_3 + 24 + j_2 * 4 + 3] = uint8(c2da_fresh162 >> 0x18)
                j_2++
            }
        }
    }
    return
}
[export, sideeffects]
def R_ParticleExplosion2(var org_2 : int; var colorStart : int; var colorLength : int) {
    var p_4 : int
    var colorMod : int = 0
    for (i_4 in range(0, 512)) {
        if (free_particles == 0) {
            return
        }
        p_4 = free_particles
        free_particles = int(uint(c2da_mem[p_4 + 16]) | uint(c2da_mem[p_4 + 17]) << 0x8 | uint(c2da_mem[p_4 + 18]) << 0x10 | uint(c2da_mem[p_4 + 19]) << 0x18)
        let c2da_fresh163 : uint = uint(active_particles)
        c2da_mem[p_4 + 16] = uint8(c2da_fresh163)
        c2da_mem[p_4 + 17] = uint8(c2da_fresh163 >> 0x8)
        c2da_mem[p_4 + 18] = uint8(c2da_fresh163 >> 0x10)
        c2da_mem[p_4 + 19] = uint8(c2da_fresh163 >> 0x18)
        c2da_mem[p_4 + 20] = 0u8
        c2da_mem[p_4 + 21] = 0u8
        c2da_mem[p_4 + 22] = 0u8
        c2da_mem[p_4 + 23] = 0u8
        active_particles = p_4
        let c2da_fresh164 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.3lf)
        let c2da_fresh165 : uint = float_bits_to_uint(c2da_fresh164)
        c2da_mem[p_4 + 40] = uint8(c2da_fresh165)
        c2da_mem[p_4 + 41] = uint8(c2da_fresh165 >> 0x8)
        c2da_mem[p_4 + 42] = uint8(c2da_fresh165 >> 0x10)
        c2da_mem[p_4 + 43] = uint8(c2da_fresh165 >> 0x18)
        let c2da_fresh166 : float = float(colorStart + colorMod % colorLength)
        let c2da_fresh167 : uint = float_bits_to_uint(c2da_fresh166)
        c2da_mem[p_4 + 12] = uint8(c2da_fresh167)
        c2da_mem[p_4 + 13] = uint8(c2da_fresh167 >> 0x8)
        c2da_mem[p_4 + 14] = uint8(c2da_fresh167 >> 0x10)
        c2da_mem[p_4 + 15] = uint8(c2da_fresh167 >> 0x18)
        colorMod++
        let c2da_fresh168 : uint = 6u
        let c2da_fresh169 : uint = c2da_fresh168
        c2da_mem[p_4 + 44] = uint8(c2da_fresh169)
        c2da_mem[p_4 + 45] = uint8(c2da_fresh169 >> 0x8)
        c2da_mem[p_4 + 46] = uint8(c2da_fresh169 >> 0x10)
        c2da_mem[p_4 + 47] = uint8(c2da_fresh169 >> 0x18)
        for (j_3 in range(0, 3)) {
            let c2da_fresh170 : float = uint_bits_to_float(uint(c2da_mem[org_2 + j_3 * 4]) | uint(c2da_mem[org_2 + j_3 * 4 + 1]) << 0x8 | uint(c2da_mem[org_2 + j_3 * 4 + 2]) << 0x10 | uint(c2da_mem[org_2 + j_3 * 4 + 3]) << 0x18) + float(c2da_std_rand() % 32 - 16)
            let c2da_fresh171 : uint = float_bits_to_uint(c2da_fresh170)
            c2da_mem[p_4 + j_3 * 4] = uint8(c2da_fresh171)
            c2da_mem[p_4 + j_3 * 4 + 1] = uint8(c2da_fresh171 >> 0x8)
            c2da_mem[p_4 + j_3 * 4 + 2] = uint8(c2da_fresh171 >> 0x10)
            c2da_mem[p_4 + j_3 * 4 + 3] = uint8(c2da_fresh171 >> 0x18)
            let c2da_fresh172 : float = float(c2da_std_rand() % 512 - 256)
            let c2da_fresh173 : uint = float_bits_to_uint(c2da_fresh172)
            c2da_mem[p_4 + 24 + j_3 * 4] = uint8(c2da_fresh173)
            c2da_mem[p_4 + 24 + j_3 * 4 + 1] = uint8(c2da_fresh173 >> 0x8)
            c2da_mem[p_4 + 24 + j_3 * 4 + 2] = uint8(c2da_fresh173 >> 0x10)
            c2da_mem[p_4 + 24 + j_3 * 4 + 3] = uint8(c2da_fresh173 >> 0x18)
        }
    }
    return
}
[export, sideeffects]
def R_LavaSplash(var org_3 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_LavaSplash_c2da_frame(org_3, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_TeleportSplash(var org_4 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_TeleportSplash_c2da_frame(org_4, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
var r_ppn : vec3_t = default<vec3_t>

[export, sideeffects]
def R_DrawParticles() {
    var c2da_fresh222 : uint
    var p_7 : int
    var kill : int
    var grav : float
    var i_7 : int
    var time2 : float
    var time3 : float
    var time1 : float
    var dvel : float
    var frametime : float
    D_StartParticles()
    VectorScale(244144, xscaleshrink, 393152)
    VectorScale(244160, yscaleshrink, 393168)
    r_ppn[0] = uint_bits_to_float(uint(c2da_mem[244128 + 0 * 4]) | uint(c2da_mem[244128 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 0 * 4 + 3]) << 0x18)
    r_ppn[1] = uint_bits_to_float(uint(c2da_mem[244128 + 1 * 4]) | uint(c2da_mem[244128 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 1 * 4 + 3]) << 0x18)
    r_ppn[2] = uint_bits_to_float(uint(c2da_mem[244128 + 2 * 4]) | uint(c2da_mem[244128 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[244128 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[244128 + 2 * 4 + 3]) << 0x18)
    frametime = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - uint64_bits_to_double(uint64(uint(c2da_mem[792]) | uint(c2da_mem[793]) << 0x8 | uint(c2da_mem[794]) << 0x10 | uint(c2da_mem[795]) << 0x18) | uint64(uint(c2da_mem[796]) | uint(c2da_mem[797]) << 0x8 | uint(c2da_mem[798]) << 0x10 | uint(c2da_mem[799]) << 0x18) << 0x20))
    time3 = frametime * 15.0
    time2 = frametime * 10.0
    time1 = frametime * 5.0
    grav = float(double(frametime * uint_bits_to_float(uint(c2da_mem[462616]) | uint(c2da_mem[462617]) << 0x8 | uint(c2da_mem[462618]) << 0x10 | uint(c2da_mem[462619]) << 0x18)) * 0.05lf)
    dvel = 4.0 * frametime
    while (true) {
        kill = active_particles
        if (kill != 0 && double(uint_bits_to_float(uint(c2da_mem[kill + 40]) | uint(c2da_mem[kill + 41]) << 0x8 | uint(c2da_mem[kill + 42]) << 0x10 | uint(c2da_mem[kill + 43]) << 0x18)) < uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20)) {
            active_particles = int(uint(c2da_mem[kill + 16]) | uint(c2da_mem[kill + 17]) << 0x8 | uint(c2da_mem[kill + 18]) << 0x10 | uint(c2da_mem[kill + 19]) << 0x18)
            let c2da_fresh212 : uint = uint(free_particles)
            c2da_mem[kill + 16] = uint8(c2da_fresh212)
            c2da_mem[kill + 17] = uint8(c2da_fresh212 >> 0x8)
            c2da_mem[kill + 18] = uint8(c2da_fresh212 >> 0x10)
            c2da_mem[kill + 19] = uint8(c2da_fresh212 >> 0x18)
            c2da_mem[kill + 20] = 0u8
            c2da_mem[kill + 21] = 0u8
            c2da_mem[kill + 22] = 0u8
            c2da_mem[kill + 23] = 0u8
            free_particles = kill
            continue
        }
        break
    }
    p_7 = active_particles
    while (p_7 != 0) {
        while (true) {
            kill = int(uint(c2da_mem[p_7 + 16]) | uint(c2da_mem[p_7 + 17]) << 0x8 | uint(c2da_mem[p_7 + 18]) << 0x10 | uint(c2da_mem[p_7 + 19]) << 0x18)
            if (kill != 0 && double(uint_bits_to_float(uint(c2da_mem[kill + 40]) | uint(c2da_mem[kill + 41]) << 0x8 | uint(c2da_mem[kill + 42]) << 0x10 | uint(c2da_mem[kill + 43]) << 0x18)) < uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20)) {
                let c2da_fresh213 : int = int(uint(c2da_mem[kill + 16]) | uint(c2da_mem[kill + 17]) << 0x8 | uint(c2da_mem[kill + 18]) << 0x10 | uint(c2da_mem[kill + 19]) << 0x18)
                let c2da_fresh214 : uint = uint(c2da_fresh213)
                c2da_mem[p_7 + 16] = uint8(c2da_fresh214)
                c2da_mem[p_7 + 17] = uint8(c2da_fresh214 >> 0x8)
                c2da_mem[p_7 + 18] = uint8(c2da_fresh214 >> 0x10)
                c2da_mem[p_7 + 19] = uint8(c2da_fresh214 >> 0x18)
                c2da_mem[p_7 + 20] = 0u8
                c2da_mem[p_7 + 21] = 0u8
                c2da_mem[p_7 + 22] = 0u8
                c2da_mem[p_7 + 23] = 0u8
                let c2da_fresh215 : uint = uint(free_particles)
                c2da_mem[kill + 16] = uint8(c2da_fresh215)
                c2da_mem[kill + 17] = uint8(c2da_fresh215 >> 0x8)
                c2da_mem[kill + 18] = uint8(c2da_fresh215 >> 0x10)
                c2da_mem[kill + 19] = uint8(c2da_fresh215 >> 0x18)
                c2da_mem[kill + 20] = 0u8
                c2da_mem[kill + 21] = 0u8
                c2da_mem[kill + 22] = 0u8
                c2da_mem[kill + 23] = 0u8
                free_particles = kill
                continue
            }
            break
        }
        D_DrawParticle(p_7)
        let c2da_fresh216 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 0 * 4]) | uint(c2da_mem[p_7 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 0 * 4 + 3]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[p_7 + 24 + 0 * 4]) | uint(c2da_mem[p_7 + 24 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + 0 * 4 + 3]) << 0x18) * frametime)
        let c2da_fresh217 : uint = float_bits_to_uint(c2da_fresh216)
        c2da_mem[p_7 + 0 * 4] = uint8(c2da_fresh217)
        c2da_mem[p_7 + 0 * 4 + 1] = uint8(c2da_fresh217 >> 0x8)
        c2da_mem[p_7 + 0 * 4 + 2] = uint8(c2da_fresh217 >> 0x10)
        c2da_mem[p_7 + 0 * 4 + 3] = uint8(c2da_fresh217 >> 0x18)
        let c2da_fresh218 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 1 * 4]) | uint(c2da_mem[p_7 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 1 * 4 + 3]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[p_7 + 24 + 1 * 4]) | uint(c2da_mem[p_7 + 24 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + 1 * 4 + 3]) << 0x18) * frametime)
        let c2da_fresh219 : uint = float_bits_to_uint(c2da_fresh218)
        c2da_mem[p_7 + 1 * 4] = uint8(c2da_fresh219)
        c2da_mem[p_7 + 1 * 4 + 1] = uint8(c2da_fresh219 >> 0x8)
        c2da_mem[p_7 + 1 * 4 + 2] = uint8(c2da_fresh219 >> 0x10)
        c2da_mem[p_7 + 1 * 4 + 3] = uint8(c2da_fresh219 >> 0x18)
        let c2da_fresh220 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 2 * 4]) | uint(c2da_mem[p_7 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 2 * 4 + 3]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[p_7 + 24 + 2 * 4]) | uint(c2da_mem[p_7 + 24 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + 2 * 4 + 3]) << 0x18) * frametime)
        let c2da_fresh221 : uint = float_bits_to_uint(c2da_fresh220)
        c2da_mem[p_7 + 2 * 4] = uint8(c2da_fresh221)
        c2da_mem[p_7 + 2 * 4 + 1] = uint8(c2da_fresh221 >> 0x8)
        c2da_mem[p_7 + 2 * 4 + 2] = uint8(c2da_fresh221 >> 0x10)
        c2da_mem[p_7 + 2 * 4 + 3] = uint8(c2da_fresh221 >> 0x18)
        c2da_fresh222 = uint(c2da_mem[p_7 + 44]) | uint(c2da_mem[p_7 + 45]) << 0x8 | uint(c2da_mem[p_7 + 46]) << 0x10 | uint(c2da_mem[p_7 + 47]) << 0x18
        if (c2da_fresh222 == 0x0u) {
        } elif (c2da_fresh222 == 0x3u) {
            let c2da_fresh223 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 36]) | uint(c2da_mem[p_7 + 37]) << 0x8 | uint(c2da_mem[p_7 + 38]) << 0x10 | uint(c2da_mem[p_7 + 39]) << 0x18) + time1
            let c2da_fresh224 : uint = float_bits_to_uint(c2da_fresh223)
            c2da_mem[p_7 + 36] = uint8(c2da_fresh224)
            c2da_mem[p_7 + 37] = uint8(c2da_fresh224 >> 0x8)
            c2da_mem[p_7 + 38] = uint8(c2da_fresh224 >> 0x10)
            c2da_mem[p_7 + 39] = uint8(c2da_fresh224 >> 0x18)
            if (uint_bits_to_float(uint(c2da_mem[p_7 + 36]) | uint(c2da_mem[p_7 + 37]) << 0x8 | uint(c2da_mem[p_7 + 38]) << 0x10 | uint(c2da_mem[p_7 + 39]) << 0x18) >= 6.0) {
                let c2da_fresh225 : float = -1.0
                let c2da_fresh226 : uint = float_bits_to_uint(c2da_fresh225)
                c2da_mem[p_7 + 40] = uint8(c2da_fresh226)
                c2da_mem[p_7 + 41] = uint8(c2da_fresh226 >> 0x8)
                c2da_mem[p_7 + 42] = uint8(c2da_fresh226 >> 0x10)
                c2da_mem[p_7 + 43] = uint8(c2da_fresh226 >> 0x18)
            } else {
                let c2da_fresh227 : float = float(ramp3[int(uint_bits_to_float(uint(c2da_mem[p_7 + 36]) | uint(c2da_mem[p_7 + 37]) << 0x8 | uint(c2da_mem[p_7 + 38]) << 0x10 | uint(c2da_mem[p_7 + 39]) << 0x18))])
                let c2da_fresh228 : uint = float_bits_to_uint(c2da_fresh227)
                c2da_mem[p_7 + 12] = uint8(c2da_fresh228)
                c2da_mem[p_7 + 13] = uint8(c2da_fresh228 >> 0x8)
                c2da_mem[p_7 + 14] = uint8(c2da_fresh228 >> 0x10)
                c2da_mem[p_7 + 15] = uint8(c2da_fresh228 >> 0x18)
            }
            let c2da_fresh229 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 24 + 2 * 4]) | uint(c2da_mem[p_7 + 24 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + 2 * 4 + 3]) << 0x18) + grav
            let c2da_fresh230 : uint = float_bits_to_uint(c2da_fresh229)
            c2da_mem[p_7 + 24 + 2 * 4] = uint8(c2da_fresh230)
            c2da_mem[p_7 + 24 + 2 * 4 + 1] = uint8(c2da_fresh230 >> 0x8)
            c2da_mem[p_7 + 24 + 2 * 4 + 2] = uint8(c2da_fresh230 >> 0x10)
            c2da_mem[p_7 + 24 + 2 * 4 + 3] = uint8(c2da_fresh230 >> 0x18)
        } elif (c2da_fresh222 == 0x4u) {
            let c2da_fresh231 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 36]) | uint(c2da_mem[p_7 + 37]) << 0x8 | uint(c2da_mem[p_7 + 38]) << 0x10 | uint(c2da_mem[p_7 + 39]) << 0x18) + time2
            let c2da_fresh232 : uint = float_bits_to_uint(c2da_fresh231)
            c2da_mem[p_7 + 36] = uint8(c2da_fresh232)
            c2da_mem[p_7 + 37] = uint8(c2da_fresh232 >> 0x8)
            c2da_mem[p_7 + 38] = uint8(c2da_fresh232 >> 0x10)
            c2da_mem[p_7 + 39] = uint8(c2da_fresh232 >> 0x18)
            if (uint_bits_to_float(uint(c2da_mem[p_7 + 36]) | uint(c2da_mem[p_7 + 37]) << 0x8 | uint(c2da_mem[p_7 + 38]) << 0x10 | uint(c2da_mem[p_7 + 39]) << 0x18) >= 8.0) {
                let c2da_fresh233 : float = -1.0
                let c2da_fresh234 : uint = float_bits_to_uint(c2da_fresh233)
                c2da_mem[p_7 + 40] = uint8(c2da_fresh234)
                c2da_mem[p_7 + 41] = uint8(c2da_fresh234 >> 0x8)
                c2da_mem[p_7 + 42] = uint8(c2da_fresh234 >> 0x10)
                c2da_mem[p_7 + 43] = uint8(c2da_fresh234 >> 0x18)
            } else {
                let c2da_fresh235 : float = float(ramp1[int(uint_bits_to_float(uint(c2da_mem[p_7 + 36]) | uint(c2da_mem[p_7 + 37]) << 0x8 | uint(c2da_mem[p_7 + 38]) << 0x10 | uint(c2da_mem[p_7 + 39]) << 0x18))])
                let c2da_fresh236 : uint = float_bits_to_uint(c2da_fresh235)
                c2da_mem[p_7 + 12] = uint8(c2da_fresh236)
                c2da_mem[p_7 + 13] = uint8(c2da_fresh236 >> 0x8)
                c2da_mem[p_7 + 14] = uint8(c2da_fresh236 >> 0x10)
                c2da_mem[p_7 + 15] = uint8(c2da_fresh236 >> 0x18)
            }
            i_7 = 0
            while (i_7 < 3) {
                let c2da_fresh237 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 24 + i_7 * 4]) | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 3]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[p_7 + 24 + i_7 * 4]) | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 3]) << 0x18) * dvel)
                let c2da_fresh238 : uint = float_bits_to_uint(c2da_fresh237)
                c2da_mem[p_7 + 24 + i_7 * 4] = uint8(c2da_fresh238)
                c2da_mem[p_7 + 24 + i_7 * 4 + 1] = uint8(c2da_fresh238 >> 0x8)
                c2da_mem[p_7 + 24 + i_7 * 4 + 2] = uint8(c2da_fresh238 >> 0x10)
                c2da_mem[p_7 + 24 + i_7 * 4 + 3] = uint8(c2da_fresh238 >> 0x18)
                i_7++
            }
            let c2da_fresh239 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 24 + 2 * 4]) | uint(c2da_mem[p_7 + 24 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + 2 * 4 + 3]) << 0x18) - grav
            let c2da_fresh240 : uint = float_bits_to_uint(c2da_fresh239)
            c2da_mem[p_7 + 24 + 2 * 4] = uint8(c2da_fresh240)
            c2da_mem[p_7 + 24 + 2 * 4 + 1] = uint8(c2da_fresh240 >> 0x8)
            c2da_mem[p_7 + 24 + 2 * 4 + 2] = uint8(c2da_fresh240 >> 0x10)
            c2da_mem[p_7 + 24 + 2 * 4 + 3] = uint8(c2da_fresh240 >> 0x18)
        } elif (c2da_fresh222 == 0x5u) {
            let c2da_fresh241 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 36]) | uint(c2da_mem[p_7 + 37]) << 0x8 | uint(c2da_mem[p_7 + 38]) << 0x10 | uint(c2da_mem[p_7 + 39]) << 0x18) + time3
            let c2da_fresh242 : uint = float_bits_to_uint(c2da_fresh241)
            c2da_mem[p_7 + 36] = uint8(c2da_fresh242)
            c2da_mem[p_7 + 37] = uint8(c2da_fresh242 >> 0x8)
            c2da_mem[p_7 + 38] = uint8(c2da_fresh242 >> 0x10)
            c2da_mem[p_7 + 39] = uint8(c2da_fresh242 >> 0x18)
            if (uint_bits_to_float(uint(c2da_mem[p_7 + 36]) | uint(c2da_mem[p_7 + 37]) << 0x8 | uint(c2da_mem[p_7 + 38]) << 0x10 | uint(c2da_mem[p_7 + 39]) << 0x18) >= 8.0) {
                let c2da_fresh243 : float = -1.0
                let c2da_fresh244 : uint = float_bits_to_uint(c2da_fresh243)
                c2da_mem[p_7 + 40] = uint8(c2da_fresh244)
                c2da_mem[p_7 + 41] = uint8(c2da_fresh244 >> 0x8)
                c2da_mem[p_7 + 42] = uint8(c2da_fresh244 >> 0x10)
                c2da_mem[p_7 + 43] = uint8(c2da_fresh244 >> 0x18)
            } else {
                let c2da_fresh245 : float = float(ramp2[int(uint_bits_to_float(uint(c2da_mem[p_7 + 36]) | uint(c2da_mem[p_7 + 37]) << 0x8 | uint(c2da_mem[p_7 + 38]) << 0x10 | uint(c2da_mem[p_7 + 39]) << 0x18))])
                let c2da_fresh246 : uint = float_bits_to_uint(c2da_fresh245)
                c2da_mem[p_7 + 12] = uint8(c2da_fresh246)
                c2da_mem[p_7 + 13] = uint8(c2da_fresh246 >> 0x8)
                c2da_mem[p_7 + 14] = uint8(c2da_fresh246 >> 0x10)
                c2da_mem[p_7 + 15] = uint8(c2da_fresh246 >> 0x18)
            }
            i_7 = 0
            while (i_7 < 3) {
                let c2da_fresh247 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 24 + i_7 * 4]) | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 3]) << 0x18) - float(uint_bits_to_float(uint(c2da_mem[p_7 + 24 + i_7 * 4]) | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 3]) << 0x18) * frametime)
                let c2da_fresh248 : uint = float_bits_to_uint(c2da_fresh247)
                c2da_mem[p_7 + 24 + i_7 * 4] = uint8(c2da_fresh248)
                c2da_mem[p_7 + 24 + i_7 * 4 + 1] = uint8(c2da_fresh248 >> 0x8)
                c2da_mem[p_7 + 24 + i_7 * 4 + 2] = uint8(c2da_fresh248 >> 0x10)
                c2da_mem[p_7 + 24 + i_7 * 4 + 3] = uint8(c2da_fresh248 >> 0x18)
                i_7++
            }
            let c2da_fresh249 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 24 + 2 * 4]) | uint(c2da_mem[p_7 + 24 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + 2 * 4 + 3]) << 0x18) - grav
            let c2da_fresh250 : uint = float_bits_to_uint(c2da_fresh249)
            c2da_mem[p_7 + 24 + 2 * 4] = uint8(c2da_fresh250)
            c2da_mem[p_7 + 24 + 2 * 4 + 1] = uint8(c2da_fresh250 >> 0x8)
            c2da_mem[p_7 + 24 + 2 * 4 + 2] = uint8(c2da_fresh250 >> 0x10)
            c2da_mem[p_7 + 24 + 2 * 4 + 3] = uint8(c2da_fresh250 >> 0x18)
        } elif (c2da_fresh222 == 0x6u) {
            i_7 = 0
            while (i_7 < 3) {
                let c2da_fresh251 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 24 + i_7 * 4]) | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 3]) << 0x18) + float(uint_bits_to_float(uint(c2da_mem[p_7 + 24 + i_7 * 4]) | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 3]) << 0x18) * dvel)
                let c2da_fresh252 : uint = float_bits_to_uint(c2da_fresh251)
                c2da_mem[p_7 + 24 + i_7 * 4] = uint8(c2da_fresh252)
                c2da_mem[p_7 + 24 + i_7 * 4 + 1] = uint8(c2da_fresh252 >> 0x8)
                c2da_mem[p_7 + 24 + i_7 * 4 + 2] = uint8(c2da_fresh252 >> 0x10)
                c2da_mem[p_7 + 24 + i_7 * 4 + 3] = uint8(c2da_fresh252 >> 0x18)
                i_7++
            }
            let c2da_fresh253 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 24 + 2 * 4]) | uint(c2da_mem[p_7 + 24 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + 2 * 4 + 3]) << 0x18) - grav
            let c2da_fresh254 : uint = float_bits_to_uint(c2da_fresh253)
            c2da_mem[p_7 + 24 + 2 * 4] = uint8(c2da_fresh254)
            c2da_mem[p_7 + 24 + 2 * 4 + 1] = uint8(c2da_fresh254 >> 0x8)
            c2da_mem[p_7 + 24 + 2 * 4 + 2] = uint8(c2da_fresh254 >> 0x10)
            c2da_mem[p_7 + 24 + 2 * 4 + 3] = uint8(c2da_fresh254 >> 0x18)
        } elif (c2da_fresh222 == 0x7u) {
            i_7 = 0
            while (i_7 < 2) {
                let c2da_fresh255 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 24 + i_7 * 4]) | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 3]) << 0x18) - float(uint_bits_to_float(uint(c2da_mem[p_7 + 24 + i_7 * 4]) | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + i_7 * 4 + 3]) << 0x18) * dvel)
                let c2da_fresh256 : uint = float_bits_to_uint(c2da_fresh255)
                c2da_mem[p_7 + 24 + i_7 * 4] = uint8(c2da_fresh256)
                c2da_mem[p_7 + 24 + i_7 * 4 + 1] = uint8(c2da_fresh256 >> 0x8)
                c2da_mem[p_7 + 24 + i_7 * 4 + 2] = uint8(c2da_fresh256 >> 0x10)
                c2da_mem[p_7 + 24 + i_7 * 4 + 3] = uint8(c2da_fresh256 >> 0x18)
                i_7++
            }
            let c2da_fresh257 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 24 + 2 * 4]) | uint(c2da_mem[p_7 + 24 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + 2 * 4 + 3]) << 0x18) - grav
            let c2da_fresh258 : uint = float_bits_to_uint(c2da_fresh257)
            c2da_mem[p_7 + 24 + 2 * 4] = uint8(c2da_fresh258)
            c2da_mem[p_7 + 24 + 2 * 4 + 1] = uint8(c2da_fresh258 >> 0x8)
            c2da_mem[p_7 + 24 + 2 * 4 + 2] = uint8(c2da_fresh258 >> 0x10)
            c2da_mem[p_7 + 24 + 2 * 4 + 3] = uint8(c2da_fresh258 >> 0x18)
        } elif (c2da_fresh222 == 0x1u || c2da_fresh222 == 0x2u) {
            let c2da_fresh259 : float = uint_bits_to_float(uint(c2da_mem[p_7 + 24 + 2 * 4]) | uint(c2da_mem[p_7 + 24 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p_7 + 24 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p_7 + 24 + 2 * 4 + 3]) << 0x18) - grav
            let c2da_fresh260 : uint = float_bits_to_uint(c2da_fresh259)
            c2da_mem[p_7 + 24 + 2 * 4] = uint8(c2da_fresh260)
            c2da_mem[p_7 + 24 + 2 * 4 + 1] = uint8(c2da_fresh260 >> 0x8)
            c2da_mem[p_7 + 24 + 2 * 4 + 2] = uint8(c2da_fresh260 >> 0x10)
            c2da_mem[p_7 + 24 + 2 * 4 + 3] = uint8(c2da_fresh260 >> 0x18)
        }
        p_7 = int(uint(c2da_mem[p_7 + 16]) | uint(c2da_mem[p_7 + 17]) << 0x8 | uint(c2da_mem[p_7 + 18]) << 0x10 | uint(c2da_mem[p_7 + 19]) << 0x18)
    }
    D_EndParticles()
    return
}
var ramp2 : int[8] = fixed_array<int>(111, 110, 109, 108, 107, 106, 104, 102)

[export, sideeffects]
def R_InitParticles() {
    var i_8 : int = COM_CheckParm(733504)
    if (i_8 != 0) {
        r_numparticles = Q_atoi(int(uint(c2da_mem[com_argv + (i_8 + 1) * 8]) | uint(c2da_mem[com_argv + (i_8 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[com_argv + (i_8 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[com_argv + (i_8 + 1) * 8 + 3]) << 0x18))
        if (r_numparticles < 512) {
            r_numparticles = 512
        }
    } else {
        r_numparticles = 2048
    }
    particles = Hunk_AllocName(int(uint64(r_numparticles) * 48ul), 733515)
    return
}
var r_numparticles : int = default<int>

var particles : int = default<int>

[export, sideeffects]
def R_ClearParticles() {
    var i_9 : int
    free_particles = particles + 0 * 48
    active_particles = 0
    i_9 = 0
    while (i_9 < r_numparticles) {
        let c2da_fresh261 : int = particles + (i_9 + 1) * 48
        let c2da_fresh262 : uint = uint(c2da_fresh261)
        c2da_mem[particles + i_9 * 48 + 16] = uint8(c2da_fresh262)
        c2da_mem[particles + i_9 * 48 + 17] = uint8(c2da_fresh262 >> 0x8)
        c2da_mem[particles + i_9 * 48 + 18] = uint8(c2da_fresh262 >> 0x10)
        c2da_mem[particles + i_9 * 48 + 19] = uint8(c2da_fresh262 >> 0x18)
        c2da_mem[particles + i_9 * 48 + 20] = 0u8
        c2da_mem[particles + i_9 * 48 + 21] = 0u8
        c2da_mem[particles + i_9 * 48 + 22] = 0u8
        c2da_mem[particles + i_9 * 48 + 23] = 0u8
        i_9++
    }
    let c2da_fresh263 : uint = 0u
    c2da_mem[particles + (r_numparticles - 1) * 48 + 16] = uint8(c2da_fresh263)
    c2da_mem[particles + (r_numparticles - 1) * 48 + 17] = uint8(c2da_fresh263 >> 0x8)
    c2da_mem[particles + (r_numparticles - 1) * 48 + 18] = uint8(c2da_fresh263 >> 0x10)
    c2da_mem[particles + (r_numparticles - 1) * 48 + 19] = uint8(c2da_fresh263 >> 0x18)
    c2da_mem[particles + (r_numparticles - 1) * 48 + 20] = 0u8
    c2da_mem[particles + (r_numparticles - 1) * 48 + 21] = 0u8
    c2da_mem[particles + (r_numparticles - 1) * 48 + 22] = 0u8
    c2da_mem[particles + (r_numparticles - 1) * 48 + 23] = 0u8
    return
}
[export, sideeffects]
def R_ReadPointFile_f() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_ReadPointFile_f_c2da_frame(c2da_lin_enter(160))
    c2da_lin_sp = c2da_saved_sp
}
var avelocity : vec3_t = fixed_array<float>(23.0, 7.0, 3.0)

var partstep : float = float(0.01lf)

var timescale : float = float(0.01lf)

[sideeffects]
def private R_ParseParticleEffect_c2da_frame(c2da_fp : int) {
    var i : int
    var count : int
    var msgcount : int
    var color : int
    i = 0
    while (i < 3) {
        let c2da_fresh0 : float = MSG_ReadCoord()
        let c2da_fresh1 : uint = float_bits_to_uint(c2da_fresh0)
        c2da_mem[c2da_fp + i * 4] = uint8(c2da_fresh1)
        c2da_mem[c2da_fp + i * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[c2da_fp + i * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[c2da_fp + i * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
        i++
    }
    i = 0
    for (c2da_i in range(i, 3)) {
        let c2da_fresh2 : float = float(double(MSG_ReadChar()) * (1.0lf / 16.0lf))
        let c2da_fresh3 : uint = float_bits_to_uint(c2da_fresh2)
        c2da_mem[c2da_fp + 16 + c2da_i * 4] = uint8(c2da_fresh3)
        c2da_mem[c2da_fp + 16 + c2da_i * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[c2da_fp + 16 + c2da_i * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[c2da_fp + 16 + c2da_i * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
    }
    msgcount = MSG_ReadByte()
    color = MSG_ReadByte()
    if (msgcount == 255) {
        count = 1024
    } else {
        count = msgcount
    }
    R_RunParticleEffect(c2da_fp, c2da_fp + 16, color, count)
    return
}
[sideeffects]
def private R_RocketTrail_c2da_frame(var start : int; var end : int; var type_0 : int; c2da_fp : int) {
    var len : float
    var j_0 : int
    var p_0 : int
    var dec : int
    let c2da_fresh33 : float = uint_bits_to_float(uint(c2da_mem[end + 0 * 4]) | uint(c2da_mem[end + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[end + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[end + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[start + 0 * 4]) | uint(c2da_mem[start + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 0 * 4 + 3]) << 0x18)
    let c2da_fresh34 : uint = float_bits_to_uint(c2da_fresh33)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh34)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh34 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh34 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh34 >> 0x18)
    let c2da_fresh35 : float = uint_bits_to_float(uint(c2da_mem[end + 1 * 4]) | uint(c2da_mem[end + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[end + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[end + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[start + 1 * 4]) | uint(c2da_mem[start + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 1 * 4 + 3]) << 0x18)
    let c2da_fresh36 : uint = float_bits_to_uint(c2da_fresh35)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh36)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh36 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh36 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh36 >> 0x18)
    let c2da_fresh37 : float = uint_bits_to_float(uint(c2da_mem[end + 2 * 4]) | uint(c2da_mem[end + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[end + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[end + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[start + 2 * 4]) | uint(c2da_mem[start + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 2 * 4 + 3]) << 0x18)
    let c2da_fresh38 : uint = float_bits_to_uint(c2da_fresh37)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh38)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh38 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh38 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh38 >> 0x18)
    len = VectorNormalize(c2da_fp)
    if (type_0 < 128) {
        dec = 3
    } else {
        dec = 1
        type_0 -= 128
    }
    while (len > 0.0) {
        len -= float(dec)
        if (free_particles == 0) {
            return
        }
        p_0 = free_particles
        free_particles = int(uint(c2da_mem[p_0 + 16]) | uint(c2da_mem[p_0 + 17]) << 0x8 | uint(c2da_mem[p_0 + 18]) << 0x10 | uint(c2da_mem[p_0 + 19]) << 0x18)
        let c2da_fresh39 : uint = uint(active_particles)
        c2da_mem[p_0 + 16] = uint8(c2da_fresh39)
        c2da_mem[p_0 + 17] = uint8(c2da_fresh39 >> 0x8)
        c2da_mem[p_0 + 18] = uint8(c2da_fresh39 >> 0x10)
        c2da_mem[p_0 + 19] = uint8(c2da_fresh39 >> 0x18)
        c2da_mem[p_0 + 20] = 0u8
        c2da_mem[p_0 + 21] = 0u8
        c2da_mem[p_0 + 22] = 0u8
        c2da_mem[p_0 + 23] = 0u8
        active_particles = p_0
        let c2da_fresh40 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh41 : uint = float_bits_to_uint(c2da_fresh40)
        c2da_mem[p_0 + 24 + 0 * 4] = uint8(c2da_fresh41)
        c2da_mem[p_0 + 24 + 0 * 4 + 1] = uint8(c2da_fresh41 >> 0x8)
        c2da_mem[p_0 + 24 + 0 * 4 + 2] = uint8(c2da_fresh41 >> 0x10)
        c2da_mem[p_0 + 24 + 0 * 4 + 3] = uint8(c2da_fresh41 >> 0x18)
        let c2da_fresh42 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh43 : uint = float_bits_to_uint(c2da_fresh42)
        c2da_mem[p_0 + 24 + 1 * 4] = uint8(c2da_fresh43)
        c2da_mem[p_0 + 24 + 1 * 4 + 1] = uint8(c2da_fresh43 >> 0x8)
        c2da_mem[p_0 + 24 + 1 * 4 + 2] = uint8(c2da_fresh43 >> 0x10)
        c2da_mem[p_0 + 24 + 1 * 4 + 3] = uint8(c2da_fresh43 >> 0x18)
        let c2da_fresh44 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh45 : uint = float_bits_to_uint(c2da_fresh44)
        c2da_mem[p_0 + 24 + 2 * 4] = uint8(c2da_fresh45)
        c2da_mem[p_0 + 24 + 2 * 4 + 1] = uint8(c2da_fresh45 >> 0x8)
        c2da_mem[p_0 + 24 + 2 * 4 + 2] = uint8(c2da_fresh45 >> 0x10)
        c2da_mem[p_0 + 24 + 2 * 4 + 3] = uint8(c2da_fresh45 >> 0x18)
        let c2da_fresh46 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 2.0lf)
        let c2da_fresh47 : uint = float_bits_to_uint(c2da_fresh46)
        c2da_mem[p_0 + 40] = uint8(c2da_fresh47)
        c2da_mem[p_0 + 41] = uint8(c2da_fresh47 >> 0x8)
        c2da_mem[p_0 + 42] = uint8(c2da_fresh47 >> 0x10)
        c2da_mem[p_0 + 43] = uint8(c2da_fresh47 >> 0x18)
        if (type_0 == 0) {
            let c2da_fresh48 : float = float(c2da_std_rand() & 3)
            let c2da_fresh49 : uint = float_bits_to_uint(c2da_fresh48)
            c2da_mem[p_0 + 36] = uint8(c2da_fresh49)
            c2da_mem[p_0 + 37] = uint8(c2da_fresh49 >> 0x8)
            c2da_mem[p_0 + 38] = uint8(c2da_fresh49 >> 0x10)
            c2da_mem[p_0 + 39] = uint8(c2da_fresh49 >> 0x18)
            let c2da_fresh50 : float = float(ramp3[int(uint_bits_to_float(uint(c2da_mem[p_0 + 36]) | uint(c2da_mem[p_0 + 37]) << 0x8 | uint(c2da_mem[p_0 + 38]) << 0x10 | uint(c2da_mem[p_0 + 39]) << 0x18))])
            let c2da_fresh51 : uint = float_bits_to_uint(c2da_fresh50)
            c2da_mem[p_0 + 12] = uint8(c2da_fresh51)
            c2da_mem[p_0 + 13] = uint8(c2da_fresh51 >> 0x8)
            c2da_mem[p_0 + 14] = uint8(c2da_fresh51 >> 0x10)
            c2da_mem[p_0 + 15] = uint8(c2da_fresh51 >> 0x18)
            let c2da_fresh52 : uint = 3u
            let c2da_fresh53 : uint = c2da_fresh52
            c2da_mem[p_0 + 44] = uint8(c2da_fresh53)
            c2da_mem[p_0 + 45] = uint8(c2da_fresh53 >> 0x8)
            c2da_mem[p_0 + 46] = uint8(c2da_fresh53 >> 0x10)
            c2da_mem[p_0 + 47] = uint8(c2da_fresh53 >> 0x18)
            j_0 = 0
            while (j_0 < 3) {
                let c2da_fresh54 : float = uint_bits_to_float(uint(c2da_mem[start + j_0 * 4]) | uint(c2da_mem[start + j_0 * 4 + 1]) << 0x8 | uint(c2da_mem[start + j_0 * 4 + 2]) << 0x10 | uint(c2da_mem[start + j_0 * 4 + 3]) << 0x18) + float(c2da_std_rand() % 6 - 3)
                let c2da_fresh55 : uint = float_bits_to_uint(c2da_fresh54)
                c2da_mem[p_0 + j_0 * 4] = uint8(c2da_fresh55)
                c2da_mem[p_0 + j_0 * 4 + 1] = uint8(c2da_fresh55 >> 0x8)
                c2da_mem[p_0 + j_0 * 4 + 2] = uint8(c2da_fresh55 >> 0x10)
                c2da_mem[p_0 + j_0 * 4 + 3] = uint8(c2da_fresh55 >> 0x18)
                j_0++
            }
        } elif (type_0 == 1) {
            let c2da_fresh56 : float = float((c2da_std_rand() & 3) + 2)
            let c2da_fresh57 : uint = float_bits_to_uint(c2da_fresh56)
            c2da_mem[p_0 + 36] = uint8(c2da_fresh57)
            c2da_mem[p_0 + 37] = uint8(c2da_fresh57 >> 0x8)
            c2da_mem[p_0 + 38] = uint8(c2da_fresh57 >> 0x10)
            c2da_mem[p_0 + 39] = uint8(c2da_fresh57 >> 0x18)
            let c2da_fresh58 : float = float(ramp3[int(uint_bits_to_float(uint(c2da_mem[p_0 + 36]) | uint(c2da_mem[p_0 + 37]) << 0x8 | uint(c2da_mem[p_0 + 38]) << 0x10 | uint(c2da_mem[p_0 + 39]) << 0x18))])
            let c2da_fresh59 : uint = float_bits_to_uint(c2da_fresh58)
            c2da_mem[p_0 + 12] = uint8(c2da_fresh59)
            c2da_mem[p_0 + 13] = uint8(c2da_fresh59 >> 0x8)
            c2da_mem[p_0 + 14] = uint8(c2da_fresh59 >> 0x10)
            c2da_mem[p_0 + 15] = uint8(c2da_fresh59 >> 0x18)
            let c2da_fresh60 : uint = 3u
            let c2da_fresh61 : uint = c2da_fresh60
            c2da_mem[p_0 + 44] = uint8(c2da_fresh61)
            c2da_mem[p_0 + 45] = uint8(c2da_fresh61 >> 0x8)
            c2da_mem[p_0 + 46] = uint8(c2da_fresh61 >> 0x10)
            c2da_mem[p_0 + 47] = uint8(c2da_fresh61 >> 0x18)
            j_0 = 0
            while (j_0 < 3) {
                let c2da_fresh62 : float = uint_bits_to_float(uint(c2da_mem[start + j_0 * 4]) | uint(c2da_mem[start + j_0 * 4 + 1]) << 0x8 | uint(c2da_mem[start + j_0 * 4 + 2]) << 0x10 | uint(c2da_mem[start + j_0 * 4 + 3]) << 0x18) + float(c2da_std_rand() % 6 - 3)
                let c2da_fresh63 : uint = float_bits_to_uint(c2da_fresh62)
                c2da_mem[p_0 + j_0 * 4] = uint8(c2da_fresh63)
                c2da_mem[p_0 + j_0 * 4 + 1] = uint8(c2da_fresh63 >> 0x8)
                c2da_mem[p_0 + j_0 * 4 + 2] = uint8(c2da_fresh63 >> 0x10)
                c2da_mem[p_0 + j_0 * 4 + 3] = uint8(c2da_fresh63 >> 0x18)
                j_0++
            }
        } elif (type_0 == 2) {
            let c2da_fresh64 : uint = 1u
            let c2da_fresh65 : uint = c2da_fresh64
            c2da_mem[p_0 + 44] = uint8(c2da_fresh65)
            c2da_mem[p_0 + 45] = uint8(c2da_fresh65 >> 0x8)
            c2da_mem[p_0 + 46] = uint8(c2da_fresh65 >> 0x10)
            c2da_mem[p_0 + 47] = uint8(c2da_fresh65 >> 0x18)
            let c2da_fresh66 : float = float(67 + (c2da_std_rand() & 3))
            let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
            c2da_mem[p_0 + 12] = uint8(c2da_fresh67)
            c2da_mem[p_0 + 13] = uint8(c2da_fresh67 >> 0x8)
            c2da_mem[p_0 + 14] = uint8(c2da_fresh67 >> 0x10)
            c2da_mem[p_0 + 15] = uint8(c2da_fresh67 >> 0x18)
            j_0 = 0
            while (j_0 < 3) {
                let c2da_fresh68 : float = uint_bits_to_float(uint(c2da_mem[start + j_0 * 4]) | uint(c2da_mem[start + j_0 * 4 + 1]) << 0x8 | uint(c2da_mem[start + j_0 * 4 + 2]) << 0x10 | uint(c2da_mem[start + j_0 * 4 + 3]) << 0x18) + float(c2da_std_rand() % 6 - 3)
                let c2da_fresh69 : uint = float_bits_to_uint(c2da_fresh68)
                c2da_mem[p_0 + j_0 * 4] = uint8(c2da_fresh69)
                c2da_mem[p_0 + j_0 * 4 + 1] = uint8(c2da_fresh69 >> 0x8)
                c2da_mem[p_0 + j_0 * 4 + 2] = uint8(c2da_fresh69 >> 0x10)
                c2da_mem[p_0 + j_0 * 4 + 3] = uint8(c2da_fresh69 >> 0x18)
                j_0++
            }
        } elif (type_0 == 3 || type_0 == 5) {
            let c2da_fresh70 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.5lf)
            let c2da_fresh71 : uint = float_bits_to_uint(c2da_fresh70)
            c2da_mem[p_0 + 40] = uint8(c2da_fresh71)
            c2da_mem[p_0 + 41] = uint8(c2da_fresh71 >> 0x8)
            c2da_mem[p_0 + 42] = uint8(c2da_fresh71 >> 0x10)
            c2da_mem[p_0 + 43] = uint8(c2da_fresh71 >> 0x18)
            let c2da_fresh72 : uint = 0u
            let c2da_fresh73 : uint = c2da_fresh72
            c2da_mem[p_0 + 44] = uint8(c2da_fresh73)
            c2da_mem[p_0 + 45] = uint8(c2da_fresh73 >> 0x8)
            c2da_mem[p_0 + 46] = uint8(c2da_fresh73 >> 0x10)
            c2da_mem[p_0 + 47] = uint8(c2da_fresh73 >> 0x18)
            if (type_0 == 3) {
                let c2da_fresh74 : float = float(52 + ((R_RocketTrail__tracercount & 4) << 1))
                let c2da_fresh75 : uint = float_bits_to_uint(c2da_fresh74)
                c2da_mem[p_0 + 12] = uint8(c2da_fresh75)
                c2da_mem[p_0 + 13] = uint8(c2da_fresh75 >> 0x8)
                c2da_mem[p_0 + 14] = uint8(c2da_fresh75 >> 0x10)
                c2da_mem[p_0 + 15] = uint8(c2da_fresh75 >> 0x18)
            } else {
                let c2da_fresh76 : float = float(230 + ((R_RocketTrail__tracercount & 4) << 1))
                let c2da_fresh77 : uint = float_bits_to_uint(c2da_fresh76)
                c2da_mem[p_0 + 12] = uint8(c2da_fresh77)
                c2da_mem[p_0 + 13] = uint8(c2da_fresh77 >> 0x8)
                c2da_mem[p_0 + 14] = uint8(c2da_fresh77 >> 0x10)
                c2da_mem[p_0 + 15] = uint8(c2da_fresh77 >> 0x18)
            }
            R_RocketTrail__tracercount++
            let c2da_fresh78 : float = uint_bits_to_float(uint(c2da_mem[start + 0 * 4]) | uint(c2da_mem[start + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 0 * 4 + 3]) << 0x18)
            let c2da_fresh79 : uint = float_bits_to_uint(c2da_fresh78)
            c2da_mem[p_0 + 0 * 4] = uint8(c2da_fresh79)
            c2da_mem[p_0 + 0 * 4 + 1] = uint8(c2da_fresh79 >> 0x8)
            c2da_mem[p_0 + 0 * 4 + 2] = uint8(c2da_fresh79 >> 0x10)
            c2da_mem[p_0 + 0 * 4 + 3] = uint8(c2da_fresh79 >> 0x18)
            let c2da_fresh80 : float = uint_bits_to_float(uint(c2da_mem[start + 1 * 4]) | uint(c2da_mem[start + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 1 * 4 + 3]) << 0x18)
            let c2da_fresh81 : uint = float_bits_to_uint(c2da_fresh80)
            c2da_mem[p_0 + 1 * 4] = uint8(c2da_fresh81)
            c2da_mem[p_0 + 1 * 4 + 1] = uint8(c2da_fresh81 >> 0x8)
            c2da_mem[p_0 + 1 * 4 + 2] = uint8(c2da_fresh81 >> 0x10)
            c2da_mem[p_0 + 1 * 4 + 3] = uint8(c2da_fresh81 >> 0x18)
            let c2da_fresh82 : float = uint_bits_to_float(uint(c2da_mem[start + 2 * 4]) | uint(c2da_mem[start + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 2 * 4 + 3]) << 0x18)
            let c2da_fresh83 : uint = float_bits_to_uint(c2da_fresh82)
            c2da_mem[p_0 + 2 * 4] = uint8(c2da_fresh83)
            c2da_mem[p_0 + 2 * 4 + 1] = uint8(c2da_fresh83 >> 0x8)
            c2da_mem[p_0 + 2 * 4 + 2] = uint8(c2da_fresh83 >> 0x10)
            c2da_mem[p_0 + 2 * 4 + 3] = uint8(c2da_fresh83 >> 0x18)
            if ((R_RocketTrail__tracercount & 1) != 0) {
                let c2da_fresh84 : float = 30.0 * uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
                let c2da_fresh85 : uint = float_bits_to_uint(c2da_fresh84)
                c2da_mem[p_0 + 24 + 0 * 4] = uint8(c2da_fresh85)
                c2da_mem[p_0 + 24 + 0 * 4 + 1] = uint8(c2da_fresh85 >> 0x8)
                c2da_mem[p_0 + 24 + 0 * 4 + 2] = uint8(c2da_fresh85 >> 0x10)
                c2da_mem[p_0 + 24 + 0 * 4 + 3] = uint8(c2da_fresh85 >> 0x18)
                let c2da_fresh86 : float = 30.0 * -uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
                let c2da_fresh87 : uint = float_bits_to_uint(c2da_fresh86)
                c2da_mem[p_0 + 24 + 1 * 4] = uint8(c2da_fresh87)
                c2da_mem[p_0 + 24 + 1 * 4 + 1] = uint8(c2da_fresh87 >> 0x8)
                c2da_mem[p_0 + 24 + 1 * 4 + 2] = uint8(c2da_fresh87 >> 0x10)
                c2da_mem[p_0 + 24 + 1 * 4 + 3] = uint8(c2da_fresh87 >> 0x18)
            } else {
                let c2da_fresh88 : float = 30.0 * -uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
                let c2da_fresh89 : uint = float_bits_to_uint(c2da_fresh88)
                c2da_mem[p_0 + 24 + 0 * 4] = uint8(c2da_fresh89)
                c2da_mem[p_0 + 24 + 0 * 4 + 1] = uint8(c2da_fresh89 >> 0x8)
                c2da_mem[p_0 + 24 + 0 * 4 + 2] = uint8(c2da_fresh89 >> 0x10)
                c2da_mem[p_0 + 24 + 0 * 4 + 3] = uint8(c2da_fresh89 >> 0x18)
                let c2da_fresh90 : float = 30.0 * uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
                let c2da_fresh91 : uint = float_bits_to_uint(c2da_fresh90)
                c2da_mem[p_0 + 24 + 1 * 4] = uint8(c2da_fresh91)
                c2da_mem[p_0 + 24 + 1 * 4 + 1] = uint8(c2da_fresh91 >> 0x8)
                c2da_mem[p_0 + 24 + 1 * 4 + 2] = uint8(c2da_fresh91 >> 0x10)
                c2da_mem[p_0 + 24 + 1 * 4 + 3] = uint8(c2da_fresh91 >> 0x18)
            }
        } elif (type_0 == 4) {
            let c2da_fresh92 : uint = 1u
            let c2da_fresh93 : uint = c2da_fresh92
            c2da_mem[p_0 + 44] = uint8(c2da_fresh93)
            c2da_mem[p_0 + 45] = uint8(c2da_fresh93 >> 0x8)
            c2da_mem[p_0 + 46] = uint8(c2da_fresh93 >> 0x10)
            c2da_mem[p_0 + 47] = uint8(c2da_fresh93 >> 0x18)
            let c2da_fresh94 : float = float(67 + (c2da_std_rand() & 3))
            let c2da_fresh95 : uint = float_bits_to_uint(c2da_fresh94)
            c2da_mem[p_0 + 12] = uint8(c2da_fresh95)
            c2da_mem[p_0 + 13] = uint8(c2da_fresh95 >> 0x8)
            c2da_mem[p_0 + 14] = uint8(c2da_fresh95 >> 0x10)
            c2da_mem[p_0 + 15] = uint8(c2da_fresh95 >> 0x18)
            j_0 = 0
            while (j_0 < 3) {
                let c2da_fresh96 : float = uint_bits_to_float(uint(c2da_mem[start + j_0 * 4]) | uint(c2da_mem[start + j_0 * 4 + 1]) << 0x8 | uint(c2da_mem[start + j_0 * 4 + 2]) << 0x10 | uint(c2da_mem[start + j_0 * 4 + 3]) << 0x18) + float(c2da_std_rand() % 6 - 3)
                let c2da_fresh97 : uint = float_bits_to_uint(c2da_fresh96)
                c2da_mem[p_0 + j_0 * 4] = uint8(c2da_fresh97)
                c2da_mem[p_0 + j_0 * 4 + 1] = uint8(c2da_fresh97 >> 0x8)
                c2da_mem[p_0 + j_0 * 4 + 2] = uint8(c2da_fresh97 >> 0x10)
                c2da_mem[p_0 + j_0 * 4 + 3] = uint8(c2da_fresh97 >> 0x18)
                j_0++
            }
            len -= 3.0
        } elif (type_0 == 6) {
            let c2da_fresh98 : float = float(9 * 16 + 8 + (c2da_std_rand() & 3))
            let c2da_fresh99 : uint = float_bits_to_uint(c2da_fresh98)
            c2da_mem[p_0 + 12] = uint8(c2da_fresh99)
            c2da_mem[p_0 + 13] = uint8(c2da_fresh99 >> 0x8)
            c2da_mem[p_0 + 14] = uint8(c2da_fresh99 >> 0x10)
            c2da_mem[p_0 + 15] = uint8(c2da_fresh99 >> 0x18)
            let c2da_fresh100 : uint = 0u
            let c2da_fresh101 : uint = c2da_fresh100
            c2da_mem[p_0 + 44] = uint8(c2da_fresh101)
            c2da_mem[p_0 + 45] = uint8(c2da_fresh101 >> 0x8)
            c2da_mem[p_0 + 46] = uint8(c2da_fresh101 >> 0x10)
            c2da_mem[p_0 + 47] = uint8(c2da_fresh101 >> 0x18)
            let c2da_fresh102 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.3lf)
            let c2da_fresh103 : uint = float_bits_to_uint(c2da_fresh102)
            c2da_mem[p_0 + 40] = uint8(c2da_fresh103)
            c2da_mem[p_0 + 41] = uint8(c2da_fresh103 >> 0x8)
            c2da_mem[p_0 + 42] = uint8(c2da_fresh103 >> 0x10)
            c2da_mem[p_0 + 43] = uint8(c2da_fresh103 >> 0x18)
            j_0 = 0
            while (j_0 < 3) {
                let c2da_fresh104 : float = uint_bits_to_float(uint(c2da_mem[start + j_0 * 4]) | uint(c2da_mem[start + j_0 * 4 + 1]) << 0x8 | uint(c2da_mem[start + j_0 * 4 + 2]) << 0x10 | uint(c2da_mem[start + j_0 * 4 + 3]) << 0x18) + float((c2da_std_rand() & 15) - 8)
                let c2da_fresh105 : uint = float_bits_to_uint(c2da_fresh104)
                c2da_mem[p_0 + j_0 * 4] = uint8(c2da_fresh105)
                c2da_mem[p_0 + j_0 * 4 + 1] = uint8(c2da_fresh105 >> 0x8)
                c2da_mem[p_0 + j_0 * 4 + 2] = uint8(c2da_fresh105 >> 0x10)
                c2da_mem[p_0 + j_0 * 4 + 3] = uint8(c2da_fresh105 >> 0x18)
                j_0++
            }
        }
        let c2da_fresh106 : float = uint_bits_to_float(uint(c2da_mem[start + 0 * 4]) | uint(c2da_mem[start + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
        let c2da_fresh107 : uint = float_bits_to_uint(c2da_fresh106)
        c2da_mem[start + 0 * 4] = uint8(c2da_fresh107)
        c2da_mem[start + 0 * 4 + 1] = uint8(c2da_fresh107 >> 0x8)
        c2da_mem[start + 0 * 4 + 2] = uint8(c2da_fresh107 >> 0x10)
        c2da_mem[start + 0 * 4 + 3] = uint8(c2da_fresh107 >> 0x18)
        let c2da_fresh108 : float = uint_bits_to_float(uint(c2da_mem[start + 1 * 4]) | uint(c2da_mem[start + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
        let c2da_fresh109 : uint = float_bits_to_uint(c2da_fresh108)
        c2da_mem[start + 1 * 4] = uint8(c2da_fresh109)
        c2da_mem[start + 1 * 4 + 1] = uint8(c2da_fresh109 >> 0x8)
        c2da_mem[start + 1 * 4 + 2] = uint8(c2da_fresh109 >> 0x10)
        c2da_mem[start + 1 * 4 + 3] = uint8(c2da_fresh109 >> 0x18)
        let c2da_fresh110 : float = uint_bits_to_float(uint(c2da_mem[start + 2 * 4]) | uint(c2da_mem[start + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[start + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[start + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
        let c2da_fresh111 : uint = float_bits_to_uint(c2da_fresh110)
        c2da_mem[start + 2 * 4] = uint8(c2da_fresh111)
        c2da_mem[start + 2 * 4 + 1] = uint8(c2da_fresh111 >> 0x8)
        c2da_mem[start + 2 * 4 + 2] = uint8(c2da_fresh111 >> 0x10)
        c2da_mem[start + 2 * 4 + 3] = uint8(c2da_fresh111 >> 0x18)
    }
    return
}
[sideeffects]
def private R_LavaSplash_c2da_frame(var org_3 : int; c2da_fp : int) {
    var p_5 : int
    var vel : float
    for (i_5 in range(-16, 16)) {
        for (j_4 in range(-16, 16)) {
            for (k in range(0, 1)) {
                if (free_particles == 0) {
                    return
                }
                p_5 = free_particles
                free_particles = int(uint(c2da_mem[p_5 + 16]) | uint(c2da_mem[p_5 + 17]) << 0x8 | uint(c2da_mem[p_5 + 18]) << 0x10 | uint(c2da_mem[p_5 + 19]) << 0x18)
                let c2da_fresh174 : uint = uint(active_particles)
                c2da_mem[p_5 + 16] = uint8(c2da_fresh174)
                c2da_mem[p_5 + 17] = uint8(c2da_fresh174 >> 0x8)
                c2da_mem[p_5 + 18] = uint8(c2da_fresh174 >> 0x10)
                c2da_mem[p_5 + 19] = uint8(c2da_fresh174 >> 0x18)
                c2da_mem[p_5 + 20] = 0u8
                c2da_mem[p_5 + 21] = 0u8
                c2da_mem[p_5 + 22] = 0u8
                c2da_mem[p_5 + 23] = 0u8
                active_particles = p_5
                let c2da_fresh175 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 2.0lf + double(c2da_std_rand() & 31) * 0.02lf)
                let c2da_fresh176 : uint = float_bits_to_uint(c2da_fresh175)
                c2da_mem[p_5 + 40] = uint8(c2da_fresh176)
                c2da_mem[p_5 + 41] = uint8(c2da_fresh176 >> 0x8)
                c2da_mem[p_5 + 42] = uint8(c2da_fresh176 >> 0x10)
                c2da_mem[p_5 + 43] = uint8(c2da_fresh176 >> 0x18)
                let c2da_fresh177 : float = float(224 + (c2da_std_rand() & 7))
                let c2da_fresh178 : uint = float_bits_to_uint(c2da_fresh177)
                c2da_mem[p_5 + 12] = uint8(c2da_fresh178)
                c2da_mem[p_5 + 13] = uint8(c2da_fresh178 >> 0x8)
                c2da_mem[p_5 + 14] = uint8(c2da_fresh178 >> 0x10)
                c2da_mem[p_5 + 15] = uint8(c2da_fresh178 >> 0x18)
                let c2da_fresh179 : uint = 2u
                let c2da_fresh180 : uint = c2da_fresh179
                c2da_mem[p_5 + 44] = uint8(c2da_fresh180)
                c2da_mem[p_5 + 45] = uint8(c2da_fresh180 >> 0x8)
                c2da_mem[p_5 + 46] = uint8(c2da_fresh180 >> 0x10)
                c2da_mem[p_5 + 47] = uint8(c2da_fresh180 >> 0x18)
                let c2da_fresh181 : float = float(j_4 * 8 + (c2da_std_rand() & 7))
                let c2da_fresh182 : uint = float_bits_to_uint(c2da_fresh181)
                c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh182)
                c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh182 >> 0x8)
                c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh182 >> 0x10)
                c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh182 >> 0x18)
                let c2da_fresh183 : float = float(i_5 * 8 + (c2da_std_rand() & 7))
                let c2da_fresh184 : uint = float_bits_to_uint(c2da_fresh183)
                c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh184)
                c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh184 >> 0x8)
                c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh184 >> 0x10)
                c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh184 >> 0x18)
                let c2da_fresh185 : float = 256.0
                let c2da_fresh186 : uint = float_bits_to_uint(c2da_fresh185)
                c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh186)
                c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh186 >> 0x8)
                c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh186 >> 0x10)
                c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh186 >> 0x18)
                let c2da_fresh187 : float = uint_bits_to_float(uint(c2da_mem[org_3 + 0 * 4]) | uint(c2da_mem[org_3 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[org_3 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[org_3 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
                let c2da_fresh188 : uint = float_bits_to_uint(c2da_fresh187)
                c2da_mem[p_5 + 0 * 4] = uint8(c2da_fresh188)
                c2da_mem[p_5 + 0 * 4 + 1] = uint8(c2da_fresh188 >> 0x8)
                c2da_mem[p_5 + 0 * 4 + 2] = uint8(c2da_fresh188 >> 0x10)
                c2da_mem[p_5 + 0 * 4 + 3] = uint8(c2da_fresh188 >> 0x18)
                let c2da_fresh189 : float = uint_bits_to_float(uint(c2da_mem[org_3 + 1 * 4]) | uint(c2da_mem[org_3 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[org_3 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[org_3 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
                let c2da_fresh190 : uint = float_bits_to_uint(c2da_fresh189)
                c2da_mem[p_5 + 1 * 4] = uint8(c2da_fresh190)
                c2da_mem[p_5 + 1 * 4 + 1] = uint8(c2da_fresh190 >> 0x8)
                c2da_mem[p_5 + 1 * 4 + 2] = uint8(c2da_fresh190 >> 0x10)
                c2da_mem[p_5 + 1 * 4 + 3] = uint8(c2da_fresh190 >> 0x18)
                let c2da_fresh191 : float = uint_bits_to_float(uint(c2da_mem[org_3 + 2 * 4]) | uint(c2da_mem[org_3 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[org_3 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[org_3 + 2 * 4 + 3]) << 0x18) + float(c2da_std_rand() & 63)
                let c2da_fresh192 : uint = float_bits_to_uint(c2da_fresh191)
                c2da_mem[p_5 + 2 * 4] = uint8(c2da_fresh192)
                c2da_mem[p_5 + 2 * 4 + 1] = uint8(c2da_fresh192 >> 0x8)
                c2da_mem[p_5 + 2 * 4 + 2] = uint8(c2da_fresh192 >> 0x10)
                c2da_mem[p_5 + 2 * 4 + 3] = uint8(c2da_fresh192 >> 0x18)
                VectorNormalize(c2da_fp)
                vel = float(50 + (c2da_std_rand() & 63))
                VectorScale(c2da_fp, vel, p_5 + 24)
            }
        }
    }
    return
}
[sideeffects]
def private R_TeleportSplash_c2da_frame(var org_4 : int; c2da_fp : int) {
    var i_6 : int
    var j_5 : int
    var k_0 : int
    var p_6 : int
    var vel_0 : float
    i_6 = -16
    while (i_6 < 16) {
        j_5 = -16
        while (j_5 < 16) {
            k_0 = -24
            while (k_0 < 32) {
                if (free_particles == 0) {
                    return
                }
                p_6 = free_particles
                free_particles = int(uint(c2da_mem[p_6 + 16]) | uint(c2da_mem[p_6 + 17]) << 0x8 | uint(c2da_mem[p_6 + 18]) << 0x10 | uint(c2da_mem[p_6 + 19]) << 0x18)
                let c2da_fresh193 : uint = uint(active_particles)
                c2da_mem[p_6 + 16] = uint8(c2da_fresh193)
                c2da_mem[p_6 + 17] = uint8(c2da_fresh193 >> 0x8)
                c2da_mem[p_6 + 18] = uint8(c2da_fresh193 >> 0x10)
                c2da_mem[p_6 + 19] = uint8(c2da_fresh193 >> 0x18)
                c2da_mem[p_6 + 20] = 0u8
                c2da_mem[p_6 + 21] = 0u8
                c2da_mem[p_6 + 22] = 0u8
                c2da_mem[p_6 + 23] = 0u8
                active_particles = p_6
                let c2da_fresh194 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) + 0.2lf + double(c2da_std_rand() & 7) * 0.02lf)
                let c2da_fresh195 : uint = float_bits_to_uint(c2da_fresh194)
                c2da_mem[p_6 + 40] = uint8(c2da_fresh195)
                c2da_mem[p_6 + 41] = uint8(c2da_fresh195 >> 0x8)
                c2da_mem[p_6 + 42] = uint8(c2da_fresh195 >> 0x10)
                c2da_mem[p_6 + 43] = uint8(c2da_fresh195 >> 0x18)
                let c2da_fresh196 : float = float(7 + (c2da_std_rand() & 7))
                let c2da_fresh197 : uint = float_bits_to_uint(c2da_fresh196)
                c2da_mem[p_6 + 12] = uint8(c2da_fresh197)
                c2da_mem[p_6 + 13] = uint8(c2da_fresh197 >> 0x8)
                c2da_mem[p_6 + 14] = uint8(c2da_fresh197 >> 0x10)
                c2da_mem[p_6 + 15] = uint8(c2da_fresh197 >> 0x18)
                let c2da_fresh198 : uint = 2u
                let c2da_fresh199 : uint = c2da_fresh198
                c2da_mem[p_6 + 44] = uint8(c2da_fresh199)
                c2da_mem[p_6 + 45] = uint8(c2da_fresh199 >> 0x8)
                c2da_mem[p_6 + 46] = uint8(c2da_fresh199 >> 0x10)
                c2da_mem[p_6 + 47] = uint8(c2da_fresh199 >> 0x18)
                let c2da_fresh200 : float = float(j_5 * 8)
                let c2da_fresh201 : uint = float_bits_to_uint(c2da_fresh200)
                c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh201)
                c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh201 >> 0x8)
                c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh201 >> 0x10)
                c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh201 >> 0x18)
                let c2da_fresh202 : float = float(i_6 * 8)
                let c2da_fresh203 : uint = float_bits_to_uint(c2da_fresh202)
                c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh203)
                c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh203 >> 0x8)
                c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh203 >> 0x10)
                c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh203 >> 0x18)
                let c2da_fresh204 : float = float(k_0 * 8)
                let c2da_fresh205 : uint = float_bits_to_uint(c2da_fresh204)
                c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh205)
                c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh205 >> 0x8)
                c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh205 >> 0x10)
                c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh205 >> 0x18)
                let c2da_fresh206 : float = uint_bits_to_float(uint(c2da_mem[org_4 + 0 * 4]) | uint(c2da_mem[org_4 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[org_4 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[org_4 + 0 * 4 + 3]) << 0x18) + float(i_6) + float(c2da_std_rand() & 3)
                let c2da_fresh207 : uint = float_bits_to_uint(c2da_fresh206)
                c2da_mem[p_6 + 0 * 4] = uint8(c2da_fresh207)
                c2da_mem[p_6 + 0 * 4 + 1] = uint8(c2da_fresh207 >> 0x8)
                c2da_mem[p_6 + 0 * 4 + 2] = uint8(c2da_fresh207 >> 0x10)
                c2da_mem[p_6 + 0 * 4 + 3] = uint8(c2da_fresh207 >> 0x18)
                let c2da_fresh208 : float = uint_bits_to_float(uint(c2da_mem[org_4 + 1 * 4]) | uint(c2da_mem[org_4 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[org_4 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[org_4 + 1 * 4 + 3]) << 0x18) + float(j_5) + float(c2da_std_rand() & 3)
                let c2da_fresh209 : uint = float_bits_to_uint(c2da_fresh208)
                c2da_mem[p_6 + 1 * 4] = uint8(c2da_fresh209)
                c2da_mem[p_6 + 1 * 4 + 1] = uint8(c2da_fresh209 >> 0x8)
                c2da_mem[p_6 + 1 * 4 + 2] = uint8(c2da_fresh209 >> 0x10)
                c2da_mem[p_6 + 1 * 4 + 3] = uint8(c2da_fresh209 >> 0x18)
                let c2da_fresh210 : float = uint_bits_to_float(uint(c2da_mem[org_4 + 2 * 4]) | uint(c2da_mem[org_4 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[org_4 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[org_4 + 2 * 4 + 3]) << 0x18) + float(k_0) + float(c2da_std_rand() & 3)
                let c2da_fresh211 : uint = float_bits_to_uint(c2da_fresh210)
                c2da_mem[p_6 + 2 * 4] = uint8(c2da_fresh211)
                c2da_mem[p_6 + 2 * 4 + 1] = uint8(c2da_fresh211 >> 0x8)
                c2da_mem[p_6 + 2 * 4 + 2] = uint8(c2da_fresh211 >> 0x10)
                c2da_mem[p_6 + 2 * 4 + 3] = uint8(c2da_fresh211 >> 0x18)
                VectorNormalize(c2da_fp)
                vel_0 = float(50 + (c2da_std_rand() & 63))
                VectorScale(c2da_fp, vel_0, p_6 + 24)
                k_0 += 4
            }
            j_5 += 4
        }
        i_6 += 4
    }
    return
}
[sideeffects]
def private R_ReadPointFile_f_c2da_frame(c2da_fp : int) {
    var r : int
    var c : int
    var p_8 : int
    c2da_lin_snprintf(c2da_fp, 2147483647ul, 733525, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 225896ul)])
    COM_FOpenFile(c2da_fp, c2da_fp + 128)
    if (int(uint(c2da_mem[c2da_fp + 128]) | uint(c2da_mem[c2da_fp + 129]) << 0x8 | uint(c2da_mem[c2da_fp + 130]) << 0x10 | uint(c2da_mem[c2da_fp + 131]) << 0x18) == 0) {
        Con_Printf(733537, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
        return
    }
    Con_Printf(733555, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    c = 0
    while (true) {
        r = c2da_lin_fscanf(uint64(int(uint(c2da_mem[c2da_fp + 128]) | uint(c2da_mem[c2da_fp + 129]) << 0x8 | uint(c2da_mem[c2da_fp + 130]) << 0x10 | uint(c2da_mem[c2da_fp + 131]) << 0x18)), 733570, [c2da_fp + 144 + 0 * 4, c2da_fp + 144 + 1 * 4, c2da_fp + 144 + 2 * 4])
        if (r != 3) {
            break
        }
        c++
        if (free_particles == 0) {
            Con_Printf(733580, [])
            break
        }
        p_8 = free_particles
        free_particles = int(uint(c2da_mem[p_8 + 16]) | uint(c2da_mem[p_8 + 17]) << 0x8 | uint(c2da_mem[p_8 + 18]) << 0x10 | uint(c2da_mem[p_8 + 19]) << 0x18)
        let c2da_fresh264 : uint = uint(active_particles)
        c2da_mem[p_8 + 16] = uint8(c2da_fresh264)
        c2da_mem[p_8 + 17] = uint8(c2da_fresh264 >> 0x8)
        c2da_mem[p_8 + 18] = uint8(c2da_fresh264 >> 0x10)
        c2da_mem[p_8 + 19] = uint8(c2da_fresh264 >> 0x18)
        c2da_mem[p_8 + 20] = 0u8
        c2da_mem[p_8 + 21] = 0u8
        c2da_mem[p_8 + 22] = 0u8
        c2da_mem[p_8 + 23] = 0u8
        active_particles = p_8
        let c2da_fresh265 : float = 99999.0
        let c2da_fresh266 : uint = float_bits_to_uint(c2da_fresh265)
        c2da_mem[p_8 + 40] = uint8(c2da_fresh266)
        c2da_mem[p_8 + 41] = uint8(c2da_fresh266 >> 0x8)
        c2da_mem[p_8 + 42] = uint8(c2da_fresh266 >> 0x10)
        c2da_mem[p_8 + 43] = uint8(c2da_fresh266 >> 0x18)
        let c2da_fresh267 : float = float(-c & 15)
        let c2da_fresh268 : uint = float_bits_to_uint(c2da_fresh267)
        c2da_mem[p_8 + 12] = uint8(c2da_fresh268)
        c2da_mem[p_8 + 13] = uint8(c2da_fresh268 >> 0x8)
        c2da_mem[p_8 + 14] = uint8(c2da_fresh268 >> 0x10)
        c2da_mem[p_8 + 15] = uint8(c2da_fresh268 >> 0x18)
        let c2da_fresh269 : uint = 0u
        let c2da_fresh270 : uint = c2da_fresh269
        c2da_mem[p_8 + 44] = uint8(c2da_fresh270)
        c2da_mem[p_8 + 45] = uint8(c2da_fresh270 >> 0x8)
        c2da_mem[p_8 + 46] = uint8(c2da_fresh270 >> 0x10)
        c2da_mem[p_8 + 47] = uint8(c2da_fresh270 >> 0x18)
        let c2da_fresh271 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh272 : uint = float_bits_to_uint(c2da_fresh271)
        c2da_mem[p_8 + 24 + 0 * 4] = uint8(c2da_fresh272)
        c2da_mem[p_8 + 24 + 0 * 4 + 1] = uint8(c2da_fresh272 >> 0x8)
        c2da_mem[p_8 + 24 + 0 * 4 + 2] = uint8(c2da_fresh272 >> 0x10)
        c2da_mem[p_8 + 24 + 0 * 4 + 3] = uint8(c2da_fresh272 >> 0x18)
        let c2da_fresh273 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh274 : uint = float_bits_to_uint(c2da_fresh273)
        c2da_mem[p_8 + 24 + 1 * 4] = uint8(c2da_fresh274)
        c2da_mem[p_8 + 24 + 1 * 4 + 1] = uint8(c2da_fresh274 >> 0x8)
        c2da_mem[p_8 + 24 + 1 * 4 + 2] = uint8(c2da_fresh274 >> 0x10)
        c2da_mem[p_8 + 24 + 1 * 4 + 3] = uint8(c2da_fresh274 >> 0x18)
        let c2da_fresh275 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh276 : uint = float_bits_to_uint(c2da_fresh275)
        c2da_mem[p_8 + 24 + 2 * 4] = uint8(c2da_fresh276)
        c2da_mem[p_8 + 24 + 2 * 4 + 1] = uint8(c2da_fresh276 >> 0x8)
        c2da_mem[p_8 + 24 + 2 * 4 + 2] = uint8(c2da_fresh276 >> 0x10)
        c2da_mem[p_8 + 24 + 2 * 4 + 3] = uint8(c2da_fresh276 >> 0x18)
        let c2da_fresh277 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 144 + 0 * 4]) | uint(c2da_mem[c2da_fp + 144 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 144 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 144 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh278 : uint = float_bits_to_uint(c2da_fresh277)
        c2da_mem[p_8 + 0 * 4] = uint8(c2da_fresh278)
        c2da_mem[p_8 + 0 * 4 + 1] = uint8(c2da_fresh278 >> 0x8)
        c2da_mem[p_8 + 0 * 4 + 2] = uint8(c2da_fresh278 >> 0x10)
        c2da_mem[p_8 + 0 * 4 + 3] = uint8(c2da_fresh278 >> 0x18)
        let c2da_fresh279 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 144 + 1 * 4]) | uint(c2da_mem[c2da_fp + 144 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 144 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 144 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh280 : uint = float_bits_to_uint(c2da_fresh279)
        c2da_mem[p_8 + 1 * 4] = uint8(c2da_fresh280)
        c2da_mem[p_8 + 1 * 4 + 1] = uint8(c2da_fresh280 >> 0x8)
        c2da_mem[p_8 + 1 * 4 + 2] = uint8(c2da_fresh280 >> 0x10)
        c2da_mem[p_8 + 1 * 4 + 3] = uint8(c2da_fresh280 >> 0x18)
        let c2da_fresh281 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 144 + 2 * 4]) | uint(c2da_mem[c2da_fp + 144 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 144 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 144 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh282 : uint = float_bits_to_uint(c2da_fresh281)
        c2da_mem[p_8 + 2 * 4] = uint8(c2da_fresh282)
        c2da_mem[p_8 + 2 * 4 + 1] = uint8(c2da_fresh282 >> 0x8)
        c2da_mem[p_8 + 2 * 4 + 2] = uint8(c2da_fresh282 >> 0x10)
        c2da_mem[p_8 + 2 * 4 + 3] = uint8(c2da_fresh282 >> 0x18)
    }
    c2da_std_fclose(uint64(int(uint(c2da_mem[c2da_fp + 128]) | uint(c2da_mem[c2da_fp + 129]) << 0x8 | uint(c2da_mem[c2da_fp + 130]) << 0x10 | uint(c2da_mem[c2da_fp + 131]) << 0x18)))
    Con_Printf(733607, [C2daVaArg(tag = 1, i64 = int64(c), f64 = 0.0lf, raw = 0x0)])
    return
}

// This unit's static data, at heap offset 733504.
let private c2da_lin_static_r_part_seg = fixed_array<int>(733504, 118)
let private c2da_lin_static_r_part = fixed_array<uint64>(0x6c6369747261702dul, 0x6974726170007365ul, 0x70616d0073656c63ul, 0x7374702e73252f73ul, 0x276e646c756f6300ul, 0x25206e65706f2074ul, 0x6964616552000a73ul, 0x2e2e2e732520676eul, 0x206625206625000aul, 0x20746f4e000a6625ul, 0x66206867756f6e65ul, 0x7472617020656572ul, 0x25000a73656c6369ul, 0x73746e696f702069ul, 0xa6461657220ul)

[init]
def private c2da_lin_init_static_r_part() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_part_seg[s * 2]
        for (k in range(c2da_lin_static_r_part_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_part[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_r_part() {
    if (length(c2da_fn_table0) < 211) {
        resize(c2da_fn_table0, 211)
    }
    c2da_fn_table0[210] = @@R_ReadPointFile_f
}

[init]
def private c2da_lin_relink_init_r_part() {
    c2da_relink_r_part()
}
