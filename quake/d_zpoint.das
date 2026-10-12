options gen2
options solid_context = true
options stack = 4194304
module d_zpoint public

require dasquake_runtime
require chase_cluster
require d_vars
[export, sideeffects]
def D_DrawZPoint() {
    var pdest : uint8?
    var pz : int16?
    var izi : int
    pz = unsafe(reinterpret<int16?>(unsafe(unsafe(d_pzbuffer + int64(d_zwidth * uint(r_zpointdesc.v))) + int(r_zpointdesc.u))))
    pdest = unsafe(reinterpret<uint8?>(unsafe(unsafe(d_viewbuffer + int(d_scantable[int(r_zpointdesc.v)])) + int(r_zpointdesc.u))))
    izi = int(r_zpointdesc.zi * 32768.0)
    if (int(*pz) <= izi) {
        *pz = int16(izi)
        *pdest = uint8(r_zpointdesc.color)
    }
    return
}
[sideeffects]
def private c2da_layout_proofs() {
    static_assert(typeinfo sizeof(type<zpointdesc_t>) == 16, "C layout of zpointdesc_t: sizeof")
    static_assert(typeinfo alignof(type<zpointdesc_t>) == 4, "C layout of zpointdesc_t: alignof")
    static_assert(typeinfo offsetof<u>(type<zpointdesc_t>) == 0, "C layout of zpointdesc_t: offsetof u")
    static_assert(typeinfo offsetof<v>(type<zpointdesc_t>) == 4, "C layout of zpointdesc_t: offsetof v")
    static_assert(typeinfo offsetof<zi>(type<zpointdesc_t>) == 8, "C layout of zpointdesc_t: offsetof zi")
    static_assert(typeinfo offsetof<color>(type<zpointdesc_t>) == 12, "C layout of zpointdesc_t: offsetof color")
}
