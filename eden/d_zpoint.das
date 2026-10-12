options gen2
options stack = 4194304
module d_zpoint public

require dasquake_runtime
require chase_cluster
require d_vars
require daslib/math_bits
[export, sideeffects]
def D_DrawZPoint() {
    var pdest : int
    var pz : int
    var izi : int
    pz = d_pzbuffer + int(d_zwidth * uint(r_zpointdesc.v)) * 2 + int(r_zpointdesc.u) * 2
    pdest = d_viewbuffer + int(d_scantable[int(r_zpointdesc.v)]) + int(r_zpointdesc.u)
    izi = int(r_zpointdesc.zi * 32768.0)
    if (int(int16(uint(c2da_mem[pz]) | uint(c2da_mem[pz + 1]) << 0x8)) <= izi) {
        let c2da_fresh0 : int16 = int16(izi)
        let c2da_fresh1 : uint = uint(c2da_fresh0)
        c2da_mem[pz] = uint8(c2da_fresh1)
        c2da_mem[pz + 1] = uint8(c2da_fresh1 >> 0x8)
        let c2da_fresh2 : uint8 = uint8(r_zpointdesc.color)
        c2da_mem[pdest] = c2da_fresh2
    }
    return
}
