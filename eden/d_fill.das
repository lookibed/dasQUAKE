options gen2
options stack = 4194304
module d_fill public

require dasquake_runtime
require chase_cluster
require daslib/math_bits
[export, sideeffects]
def D_FillRect(var rect : int; var color : int) {
    var rx : int
    var ry : int
    var rwidth : int
    var rheight : int
    var dest : int
    var ldest : int
    rx = int(uint(c2da_mem[rect]) | uint(c2da_mem[rect + 1]) << 0x8 | uint(c2da_mem[rect + 2]) << 0x10 | uint(c2da_mem[rect + 3]) << 0x18)
    ry = int(uint(c2da_mem[rect + 4]) | uint(c2da_mem[rect + 5]) << 0x8 | uint(c2da_mem[rect + 6]) << 0x10 | uint(c2da_mem[rect + 7]) << 0x18)
    rwidth = int(uint(c2da_mem[rect + 8]) | uint(c2da_mem[rect + 9]) << 0x8 | uint(c2da_mem[rect + 10]) << 0x10 | uint(c2da_mem[rect + 11]) << 0x18)
    rheight = int(uint(c2da_mem[rect + 12]) | uint(c2da_mem[rect + 13]) << 0x8 | uint(c2da_mem[rect + 14]) << 0x10 | uint(c2da_mem[rect + 15]) << 0x18)
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
    dest = vid.buffer + int(uint(ry) * vid.rowbytes) + rx
    if ((rwidth & 3) == 0 && (int64(dest) & 3l) == 0l) {
        ldest = dest
        color += color << 16
        rwidth >>= 2
        color += color << 8
        ry = 0
        for (c2da_ry in range(ry, rheight)) {
            rx = 0
            while (rx < rwidth) {
                let c2da_fresh0 : uint = uint(color)
                let c2da_fresh1 : uint = c2da_fresh0
                c2da_mem[ldest + rx * 4] = uint8(c2da_fresh1)
                c2da_mem[ldest + rx * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
                c2da_mem[ldest + rx * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
                c2da_mem[ldest + rx * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
                rx++
            }
            ldest += int(vid.rowbytes)
        }
    } else {
        ry = 0
        for (c2da_ry_0 in range(ry, rheight)) {
            rx = 0
            while (rx < rwidth) {
                let c2da_fresh2 : uint8 = uint8(color)
                c2da_mem[dest + rx] = c2da_fresh2
                rx++
            }
            dest += int(vid.rowbytes)
        }
    }
    return
}
