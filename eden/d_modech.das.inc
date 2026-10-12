[export, sideeffects]
def D_ViewChanged() {
    var rowbytes : int
    var i : int
    if (uint(r_dowarp) != 0u) {
        rowbytes = 320
    } else {
        rowbytes = int(vid.rowbytes)
    }
    scale_for_mip = xscale
    if (yscale > xscale) {
        scale_for_mip = yscale
    }
    d_zrowbytes = uint(vid.width * 2u)
    d_zwidth = uint(vid.width)
    d_pix_min = int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18) / 320
    if (d_pix_min < 1) {
        d_pix_min = 1
    }
    let c2da_fresh0 : int = int(uint(c2da_mem[5208]) | uint(c2da_mem[5209]) << 0x8 | uint(c2da_mem[5210]) << 0x10 | uint(c2da_mem[5211]) << 0x18)
    d_pix_max = int(double(float(c2da_fresh0)) / (320.0lf / 4.0lf) + 0.5lf)
    d_pix_shift = 8 - int(double(float(c2da_fresh0)) / 320.0lf + 0.5lf)
    if (d_pix_max < 1) {
        d_pix_max = 1
    }
    if (double(pixelAspect) > 1.4lf) {
        d_y_aspect_shift = 1
    } else {
        d_y_aspect_shift = 0
    }
    d_vrectx = int(uint(c2da_mem[5200]) | uint(c2da_mem[5201]) << 0x8 | uint(c2da_mem[5202]) << 0x10 | uint(c2da_mem[5203]) << 0x18)
    d_vrecty = int(uint(c2da_mem[5204]) | uint(c2da_mem[5205]) << 0x8 | uint(c2da_mem[5206]) << 0x10 | uint(c2da_mem[5207]) << 0x18)
    d_vrectright_particle = int(uint(c2da_mem[5248]) | uint(c2da_mem[5249]) << 0x8 | uint(c2da_mem[5250]) << 0x10 | uint(c2da_mem[5251]) << 0x18) - d_pix_max
    d_vrectbottom_particle = int(uint(c2da_mem[5252]) | uint(c2da_mem[5253]) << 0x8 | uint(c2da_mem[5254]) << 0x10 | uint(c2da_mem[5255]) << 0x18) - (d_pix_max << d_y_aspect_shift)
    i = 0
    while (uint(i) < vid.height) {
        d_scantable[i] = i * rowbytes
        zspantable[i] = d_pzbuffer + int(uint(i) * d_zwidth) * 2
        i++
    }
    return
}
var zspantable : int[1024]

var d_scantable : int[1024]

var d_y_aspect_shift : int = default<int>

var d_pix_max : int = default<int>

var d_vrectbottom_particle : int = default<int>

var d_vrectright_particle : int = default<int>

var d_vrecty : int = default<int>

var d_vrectx : int = default<int>

var d_pix_shift : int = default<int>

var d_pix_min : int = default<int>

