options gen2
options solid_context = true
options stack = 4194304
module mathlib public

require dasquake_runtime
require sys_null
require strings
require daslib/fio
require math
var private c2da_str_0 : array<int8> = [int8(70), int8(108), int8(111), int8(111), int8(114), int8(68), int8(105), int8(118), int8(77), int8(111), int8(100), int8(58), int8(32), int8(98), int8(97), int8(100), int8(32), int8(100), int8(101), int8(110), int8(111), int8(109), int8(105), int8(110), int8(97), int8(116), int8(111), int8(114), int8(32), int8(37), int8(100), int8(10), int8(0)]

var private c2da_str_1 : array<int8> = [int8(66), int8(111), int8(120), int8(79), int8(110), int8(80), int8(108), int8(97), int8(110), int8(101), int8(83), int8(105), int8(100), int8(101), int8(58), int8(32), int8(32), int8(66), int8(97), int8(100), int8(32), int8(115), int8(105), int8(103), int8(110), int8(98), int8(105), int8(116), int8(115), int8(0)]

var vec3_origin : vec3_t = fixed_array<float>(0.0, 0.0, 0.0)

var nanmask : int = 255 << 23

[export, sideeffects]
def VectorMA(var veca : float?; var scale : float; var vecb : float?; var vecc : float?) {
    unsafe(vecc[0]) = unsafe(veca[0]) + scale * unsafe(vecb[0])
    unsafe(vecc[1]) = unsafe(veca[1]) + scale * unsafe(vecb[1])
    unsafe(vecc[2]) = unsafe(veca[2]) + scale * unsafe(vecb[2])
    return
}
[export, sideeffects]
def _DotProduct(var v1 : float?; var v2 : float?) : float {
    return unsafe(v1[0]) * unsafe(v2[0]) + unsafe(v1[1]) * unsafe(v2[1]) + unsafe(v1[2]) * unsafe(v2[2])
}
[export, sideeffects]
def _VectorSubtract(var veca_0 : float?; var vecb_0 : float?; var out : float?) {
    unsafe(out[0]) = unsafe(veca_0[0]) - unsafe(vecb_0[0])
    unsafe(out[1]) = unsafe(veca_0[1]) - unsafe(vecb_0[1])
    unsafe(out[2]) = unsafe(veca_0[2]) - unsafe(vecb_0[2])
    return
}
[export, sideeffects]
def _VectorAdd(var veca_1 : float?; var vecb_1 : float?; var out_0 : float?) {
    unsafe(out_0[0]) = unsafe(veca_1[0]) + unsafe(vecb_1[0])
    unsafe(out_0[1]) = unsafe(veca_1[1]) + unsafe(vecb_1[1])
    unsafe(out_0[2]) = unsafe(veca_1[2]) + unsafe(vecb_1[2])
    return
}
[export, sideeffects]
def _VectorCopy(var in_0 : float?; var out_1 : float?) {
    unsafe(out_1[0]) = float(unsafe(in_0[0]))  // nolint:PERF020
    unsafe(out_1[1]) = float(unsafe(in_0[1]))  // nolint:PERF020
    unsafe(out_1[2]) = float(unsafe(in_0[2]))  // nolint:PERF020
    return
}
[export, sideeffects]
def VectorCompare(var v1_0 : float?; var v2_0 : float?) : int {
    for (i in range(0, 3)) {
        if (unsafe(v1_0[i]) != unsafe(v2_0[i])) {
            return 0
        }
    }
    return 1
}
[export, sideeffects]
def Length(var v : float?) : float {
    var length_0 : float = 0.0
    for (i_0 in range(0, 3)) {
        length_0 += unsafe(v[i_0]) * unsafe(v[i_0])
    }
    length_0 = float(sqrt(double(length_0)))
    return length_0
}
[export, sideeffects]
def CrossProduct(var v1_1 : float?; var v2_1 : float?; var cross : float?) {
    unsafe(cross[0]) = unsafe(v1_1[1]) * unsafe(v2_1[2]) - unsafe(v1_1[2]) * unsafe(v2_1[1])
    unsafe(cross[1]) = unsafe(v1_1[2]) * unsafe(v2_1[0]) - unsafe(v1_1[0]) * unsafe(v2_1[2])
    unsafe(cross[2]) = unsafe(v1_1[0]) * unsafe(v2_1[1]) - unsafe(v1_1[1]) * unsafe(v2_1[0])
    return
}
[export, sideeffects]
def VectorNormalize(var v_0 : float?) : float {
    var length_1 : float
    var ilength : float
    length_1 = unsafe(v_0[0]) * unsafe(v_0[0]) + unsafe(v_0[1]) * unsafe(v_0[1]) + unsafe(v_0[2]) * unsafe(v_0[2])
    length_1 = float(sqrt(double(length_1)))
    if (length_1 != 0.0) {
        ilength = 1.0 / length_1
        unsafe(v_0[0]) *= ilength
        unsafe(v_0[1]) *= ilength
        unsafe(v_0[2]) *= ilength
    }
    return length_1
}
[export, sideeffects]
def VectorInverse(var v_1 : float?) {
    unsafe(v_1[0]) = -unsafe(v_1[0])
    unsafe(v_1[1]) = -unsafe(v_1[1])
    unsafe(v_1[2]) = -unsafe(v_1[2])
    return
}
[export, sideeffects]
def VectorScale(var in_1 : float?; var scale_0 : float; var out_2 : float?) {
    unsafe(out_2[0]) = unsafe(in_1[0]) * scale_0
    unsafe(out_2[1]) = unsafe(in_1[1]) * scale_0
    unsafe(out_2[2]) = unsafe(in_1[2]) * scale_0
    return
}
[export, sideeffects]
def Q_log2(var val : int) : int {
    var answer : int = 0
    while (true) {
        val >>= 1
        if (val == 0) {
            break
        }
        answer++
    }
    return answer
}
[export, sideeffects]
def R_ConcatRotations(var in1 : float[3]?; var in2 : float[3]?; var out_3 : float[3]?) {
    unsafe(unsafe(addr(unsafe(out_3[0])[0]))[0]) = unsafe(unsafe(addr(unsafe(in1[0])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2[0])[0]))[0]) + unsafe(unsafe(addr(unsafe(in1[0])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2[1])[0]))[0]) + unsafe(unsafe(addr(unsafe(in1[0])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2[2])[0]))[0])
    unsafe(unsafe(addr(unsafe(out_3[0])[0]))[1]) = unsafe(unsafe(addr(unsafe(in1[0])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2[0])[0]))[1]) + unsafe(unsafe(addr(unsafe(in1[0])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2[1])[0]))[1]) + unsafe(unsafe(addr(unsafe(in1[0])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2[2])[0]))[1])
    unsafe(unsafe(addr(unsafe(out_3[0])[0]))[2]) = unsafe(unsafe(addr(unsafe(in1[0])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2[0])[0]))[2]) + unsafe(unsafe(addr(unsafe(in1[0])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2[1])[0]))[2]) + unsafe(unsafe(addr(unsafe(in1[0])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2[2])[0]))[2])
    unsafe(unsafe(addr(unsafe(out_3[1])[0]))[0]) = unsafe(unsafe(addr(unsafe(in1[1])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2[0])[0]))[0]) + unsafe(unsafe(addr(unsafe(in1[1])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2[1])[0]))[0]) + unsafe(unsafe(addr(unsafe(in1[1])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2[2])[0]))[0])
    unsafe(unsafe(addr(unsafe(out_3[1])[0]))[1]) = unsafe(unsafe(addr(unsafe(in1[1])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2[0])[0]))[1]) + unsafe(unsafe(addr(unsafe(in1[1])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2[1])[0]))[1]) + unsafe(unsafe(addr(unsafe(in1[1])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2[2])[0]))[1])
    unsafe(unsafe(addr(unsafe(out_3[1])[0]))[2]) = unsafe(unsafe(addr(unsafe(in1[1])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2[0])[0]))[2]) + unsafe(unsafe(addr(unsafe(in1[1])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2[1])[0]))[2]) + unsafe(unsafe(addr(unsafe(in1[1])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2[2])[0]))[2])
    unsafe(unsafe(addr(unsafe(out_3[2])[0]))[0]) = unsafe(unsafe(addr(unsafe(in1[2])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2[0])[0]))[0]) + unsafe(unsafe(addr(unsafe(in1[2])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2[1])[0]))[0]) + unsafe(unsafe(addr(unsafe(in1[2])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2[2])[0]))[0])
    unsafe(unsafe(addr(unsafe(out_3[2])[0]))[1]) = unsafe(unsafe(addr(unsafe(in1[2])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2[0])[0]))[1]) + unsafe(unsafe(addr(unsafe(in1[2])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2[1])[0]))[1]) + unsafe(unsafe(addr(unsafe(in1[2])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2[2])[0]))[1])
    unsafe(unsafe(addr(unsafe(out_3[2])[0]))[2]) = unsafe(unsafe(addr(unsafe(in1[2])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2[0])[0]))[2]) + unsafe(unsafe(addr(unsafe(in1[2])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2[1])[0]))[2]) + unsafe(unsafe(addr(unsafe(in1[2])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2[2])[0]))[2])
    return
}
[export, sideeffects]
def R_ConcatTransforms(var in1_0 : float[4]?; var in2_0 : float[4]?; var out_4 : float[4]?) {
    unsafe(unsafe(addr(unsafe(out_4[0])[0]))[0]) = unsafe(unsafe(addr(unsafe(in1_0[0])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2_0[0])[0]))[0]) + unsafe(unsafe(addr(unsafe(in1_0[0])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2_0[1])[0]))[0]) + unsafe(unsafe(addr(unsafe(in1_0[0])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2_0[2])[0]))[0])
    unsafe(unsafe(addr(unsafe(out_4[0])[0]))[1]) = unsafe(unsafe(addr(unsafe(in1_0[0])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2_0[0])[0]))[1]) + unsafe(unsafe(addr(unsafe(in1_0[0])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2_0[1])[0]))[1]) + unsafe(unsafe(addr(unsafe(in1_0[0])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2_0[2])[0]))[1])
    unsafe(unsafe(addr(unsafe(out_4[0])[0]))[2]) = unsafe(unsafe(addr(unsafe(in1_0[0])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2_0[0])[0]))[2]) + unsafe(unsafe(addr(unsafe(in1_0[0])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2_0[1])[0]))[2]) + unsafe(unsafe(addr(unsafe(in1_0[0])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2_0[2])[0]))[2])
    unsafe(unsafe(addr(unsafe(out_4[0])[0]))[3]) = unsafe(unsafe(addr(unsafe(in1_0[0])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2_0[0])[0]))[3]) + unsafe(unsafe(addr(unsafe(in1_0[0])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2_0[1])[0]))[3]) + unsafe(unsafe(addr(unsafe(in1_0[0])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2_0[2])[0]))[3]) + unsafe(unsafe(addr(unsafe(in1_0[0])[0]))[3])
    unsafe(unsafe(addr(unsafe(out_4[1])[0]))[0]) = unsafe(unsafe(addr(unsafe(in1_0[1])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2_0[0])[0]))[0]) + unsafe(unsafe(addr(unsafe(in1_0[1])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2_0[1])[0]))[0]) + unsafe(unsafe(addr(unsafe(in1_0[1])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2_0[2])[0]))[0])
    unsafe(unsafe(addr(unsafe(out_4[1])[0]))[1]) = unsafe(unsafe(addr(unsafe(in1_0[1])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2_0[0])[0]))[1]) + unsafe(unsafe(addr(unsafe(in1_0[1])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2_0[1])[0]))[1]) + unsafe(unsafe(addr(unsafe(in1_0[1])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2_0[2])[0]))[1])
    unsafe(unsafe(addr(unsafe(out_4[1])[0]))[2]) = unsafe(unsafe(addr(unsafe(in1_0[1])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2_0[0])[0]))[2]) + unsafe(unsafe(addr(unsafe(in1_0[1])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2_0[1])[0]))[2]) + unsafe(unsafe(addr(unsafe(in1_0[1])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2_0[2])[0]))[2])
    unsafe(unsafe(addr(unsafe(out_4[1])[0]))[3]) = unsafe(unsafe(addr(unsafe(in1_0[1])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2_0[0])[0]))[3]) + unsafe(unsafe(addr(unsafe(in1_0[1])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2_0[1])[0]))[3]) + unsafe(unsafe(addr(unsafe(in1_0[1])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2_0[2])[0]))[3]) + unsafe(unsafe(addr(unsafe(in1_0[1])[0]))[3])
    unsafe(unsafe(addr(unsafe(out_4[2])[0]))[0]) = unsafe(unsafe(addr(unsafe(in1_0[2])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2_0[0])[0]))[0]) + unsafe(unsafe(addr(unsafe(in1_0[2])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2_0[1])[0]))[0]) + unsafe(unsafe(addr(unsafe(in1_0[2])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2_0[2])[0]))[0])
    unsafe(unsafe(addr(unsafe(out_4[2])[0]))[1]) = unsafe(unsafe(addr(unsafe(in1_0[2])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2_0[0])[0]))[1]) + unsafe(unsafe(addr(unsafe(in1_0[2])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2_0[1])[0]))[1]) + unsafe(unsafe(addr(unsafe(in1_0[2])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2_0[2])[0]))[1])
    unsafe(unsafe(addr(unsafe(out_4[2])[0]))[2]) = unsafe(unsafe(addr(unsafe(in1_0[2])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2_0[0])[0]))[2]) + unsafe(unsafe(addr(unsafe(in1_0[2])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2_0[1])[0]))[2]) + unsafe(unsafe(addr(unsafe(in1_0[2])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2_0[2])[0]))[2])
    unsafe(unsafe(addr(unsafe(out_4[2])[0]))[3]) = unsafe(unsafe(addr(unsafe(in1_0[2])[0]))[0]) * unsafe(unsafe(addr(unsafe(in2_0[0])[0]))[3]) + unsafe(unsafe(addr(unsafe(in1_0[2])[0]))[1]) * unsafe(unsafe(addr(unsafe(in2_0[1])[0]))[3]) + unsafe(unsafe(addr(unsafe(in1_0[2])[0]))[2]) * unsafe(unsafe(addr(unsafe(in2_0[2])[0]))[3]) + unsafe(unsafe(addr(unsafe(in1_0[2])[0]))[3])
    return
}
[export, sideeffects]
def FloorDivMod(var numer : double; var denom : double; var quotient : int?; var rem : int?) {
    var q : int
    var r : int
    var x : double
    if (denom <= 0.0lf) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_0[0])), [C2daVaArg(tag = 2, i64 = 0, f64 = denom, raw = 0x0)])
    }
    if (numer >= 0.0lf) {
        x = floor(numer / denom)
        q = int(x)
        r = int(floor(numer - x * denom))
    } else {
        x = floor(-numer / denom)
        q = -int(x)
        r = int(floor(-numer - x * denom))
        if (r != 0) {
            q--
            r = int(denom) - r
        }
    }
    *quotient = q
    *rem = r
    return
}
[export, sideeffects]
def Invert24To16(var val_0 : int) : int {
    if (val_0 < 256) {
        return -1
    }
    return int(65536.0lf * 16777216.0lf / double(val_0) + 0.5lf)
}
[export, sideeffects]
def GreatestCommonDivisor(var i1 : int; var i2 : int) : int {
    if (i1 > i2) {
        if (i2 == 0) {
            return i1
        }
        return GreatestCommonDivisor(i2, i1 % i2)
    } else {
        if (i1 == 0) {
            return i2
        }
        return GreatestCommonDivisor(i1, i2 % i1)
    }
}
[export, sideeffects]
def AngleVectors(var angles : float?; var forward : float?; var right : float?; var up : float?) {
    var angle : float
    var sr : float
    var sp : float
    var sy : float
    var cr : float
    var cp : float
    var cy : float
    angle = float(double(unsafe(angles[1])) * (3.141592653589793lf * 2.0lf / 360.0lf))
    sy = float(sin(double(angle)))
    cy = float(cos(double(angle)))
    angle = float(double(unsafe(angles[0])) * (3.141592653589793lf * 2.0lf / 360.0lf))
    sp = float(sin(double(angle)))
    cp = float(cos(double(angle)))
    angle = float(double(unsafe(angles[2])) * (3.141592653589793lf * 2.0lf / 360.0lf))
    sr = float(sin(double(angle)))
    cr = float(cos(double(angle)))
    unsafe(forward[0]) = cp * cy
    unsafe(forward[1]) = cp * sy
    unsafe(forward[2]) = -sp
    unsafe(right[0]) = -1.0 * sr * sp * cy + -1.0 * cr * -sy
    unsafe(right[1]) = -1.0 * sr * sp * sy + -1.0 * cr * cy
    unsafe(right[2]) = -1.0 * sr * cp
    unsafe(up[0]) = cr * sp * cy + -sr * -sy
    unsafe(up[1]) = cr * sp * sy + -sr * cy
    unsafe(up[2]) = cr * cp
    return
}
[export, sideeffects]
def BoxOnPlaneSide(var emins : float?; var emaxs : float?; var p : mplane_s?) : int {
    var c2da_fresh0 : int
    var dist1 : float
    var dist2 : float
    var sides : int
    c2da_fresh0 = int(p.signbits)
    if (c2da_fresh0 == 0) {
        var c2da_fresh1 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh2 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh3 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist1 = unsafe(unsafe(reinterpret<float?>(c2da_fresh1))[0]) * unsafe(emaxs[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh2))[1]) * unsafe(emaxs[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh3))[2]) * unsafe(emaxs[2])
        var c2da_fresh4 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh5 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh6 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist2 = unsafe(unsafe(reinterpret<float?>(c2da_fresh4))[0]) * unsafe(emins[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh5))[1]) * unsafe(emins[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh6))[2]) * unsafe(emins[2])
    } elif (c2da_fresh0 == 1) {
        var c2da_fresh7 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh8 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh9 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist1 = unsafe(unsafe(reinterpret<float?>(c2da_fresh7))[0]) * unsafe(emins[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh8))[1]) * unsafe(emaxs[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh9))[2]) * unsafe(emaxs[2])
        var c2da_fresh10 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh11 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh12 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist2 = unsafe(unsafe(reinterpret<float?>(c2da_fresh10))[0]) * unsafe(emaxs[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh11))[1]) * unsafe(emins[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh12))[2]) * unsafe(emins[2])
    } elif (c2da_fresh0 == 2) {
        var c2da_fresh13 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh14 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh15 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist1 = unsafe(unsafe(reinterpret<float?>(c2da_fresh13))[0]) * unsafe(emaxs[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh14))[1]) * unsafe(emins[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh15))[2]) * unsafe(emaxs[2])
        var c2da_fresh16 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh17 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh18 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist2 = unsafe(unsafe(reinterpret<float?>(c2da_fresh16))[0]) * unsafe(emins[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh17))[1]) * unsafe(emaxs[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh18))[2]) * unsafe(emins[2])
    } elif (c2da_fresh0 == 3) {
        var c2da_fresh19 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh20 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh21 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist1 = unsafe(unsafe(reinterpret<float?>(c2da_fresh19))[0]) * unsafe(emins[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh20))[1]) * unsafe(emins[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh21))[2]) * unsafe(emaxs[2])
        var c2da_fresh22 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh23 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh24 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist2 = unsafe(unsafe(reinterpret<float?>(c2da_fresh22))[0]) * unsafe(emaxs[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh23))[1]) * unsafe(emaxs[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh24))[2]) * unsafe(emins[2])
    } elif (c2da_fresh0 == 4) {
        var c2da_fresh25 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh26 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh27 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist1 = unsafe(unsafe(reinterpret<float?>(c2da_fresh25))[0]) * unsafe(emaxs[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh26))[1]) * unsafe(emaxs[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh27))[2]) * unsafe(emins[2])
        var c2da_fresh28 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh29 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh30 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist2 = unsafe(unsafe(reinterpret<float?>(c2da_fresh28))[0]) * unsafe(emins[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh29))[1]) * unsafe(emins[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh30))[2]) * unsafe(emaxs[2])
    } elif (c2da_fresh0 == 5) {
        var c2da_fresh31 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh32 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh33 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist1 = unsafe(unsafe(reinterpret<float?>(c2da_fresh31))[0]) * unsafe(emins[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh32))[1]) * unsafe(emaxs[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh33))[2]) * unsafe(emins[2])
        var c2da_fresh34 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh35 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh36 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist2 = unsafe(unsafe(reinterpret<float?>(c2da_fresh34))[0]) * unsafe(emaxs[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh35))[1]) * unsafe(emins[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh36))[2]) * unsafe(emaxs[2])
    } elif (c2da_fresh0 == 6) {
        var c2da_fresh37 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh38 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh39 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist1 = unsafe(unsafe(reinterpret<float?>(c2da_fresh37))[0]) * unsafe(emaxs[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh38))[1]) * unsafe(emins[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh39))[2]) * unsafe(emins[2])
        var c2da_fresh40 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh41 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh42 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist2 = unsafe(unsafe(reinterpret<float?>(c2da_fresh40))[0]) * unsafe(emins[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh41))[1]) * unsafe(emaxs[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh42))[2]) * unsafe(emaxs[2])
    } elif (c2da_fresh0 == 7) {
        var c2da_fresh43 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh44 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh45 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist1 = unsafe(unsafe(reinterpret<float?>(c2da_fresh43))[0]) * unsafe(emins[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh44))[1]) * unsafe(emins[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh45))[2]) * unsafe(emins[2])
        var c2da_fresh46 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh47 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        var c2da_fresh48 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(p))))
        dist2 = unsafe(unsafe(reinterpret<float?>(c2da_fresh46))[0]) * unsafe(emaxs[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh47))[1]) * unsafe(emaxs[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh48))[2]) * unsafe(emaxs[2])
    } else {
        dist2 = 0.0
        dist1 = dist2
        BOPS_Error()
    }
    sides = 0
    if (dist1 >= p.dist) {
        sides = 1
    }
    if (dist2 < p.dist) {
        sides |= 2
    }
    return sides
}
[export, sideeffects]
def BOPS_Error() {
    Sys_Error(unsafe(addr<int8?>(c2da_str_1[0])), [])
    return
}
[export, sideeffects]
def anglemod(var a : float) : float {
    a = float(360.0lf / 65536.0lf * double(int(double(a) * (65536.0lf / 360.0lf)) & 65535))
    return a
}
[export, sideeffects]
def ProjectPointOnPlane(var dst : float?; var p_0 : float const?; var normal : float const?) {
    var d : float
    var n : vec3_t
    var inv_denom : float = 1.0 / (unsafe(normal[0]) * unsafe(normal[0]) + unsafe(normal[1]) * unsafe(normal[1]) + unsafe(normal[2]) * unsafe(normal[2]))
    d = (unsafe(normal[0]) * unsafe(p_0[0]) + unsafe(normal[1]) * unsafe(p_0[1]) + unsafe(normal[2]) * unsafe(p_0[2])) * inv_denom
    unsafe(unsafe(addr(n[0]))[0]) = unsafe(normal[0]) * inv_denom
    unsafe(unsafe(addr(n[0]))[1]) = unsafe(normal[1]) * inv_denom
    unsafe(unsafe(addr(n[0]))[2]) = unsafe(normal[2]) * inv_denom
    unsafe(dst[0]) = unsafe(p_0[0]) - d * unsafe(unsafe(addr(n[0]))[0])
    unsafe(dst[1]) = unsafe(p_0[1]) - d * unsafe(unsafe(addr(n[0]))[1])
    unsafe(dst[2]) = unsafe(p_0[2]) - d * unsafe(unsafe(addr(n[0]))[2])
    return
}
[export, sideeffects]
def PerpendicularVector(var dst_0 : float?; var src : float const?) {
    var pos : int
    var i_1 : int
    var minelem : float
    var tempvec : vec3_t
    minelem = 1.0
    pos = 0
    i_1 = 0
    while (i_1 < 3) {
        if (c2da_std_fabs(double(unsafe(src[i_1]))) < double(minelem)) {
            pos = i_1
            minelem = float(c2da_std_fabs(double(unsafe(src[i_1]))))
        }
        i_1++
    }
    unsafe(unsafe(addr(tempvec[0]))[2]) = 0.0
    unsafe(unsafe(addr(tempvec[0]))[1]) = float(unsafe(unsafe(addr(tempvec[0]))[2]))  // nolint:PERF020
    unsafe(unsafe(addr(tempvec[0]))[0]) = float(unsafe(unsafe(addr(tempvec[0]))[1]))  // nolint:PERF020
    unsafe(unsafe(addr(tempvec[0]))[pos]) = 1.0
    ProjectPointOnPlane(dst_0, unsafe(addr<float const?>(tempvec[0])), src)
    VectorNormalize(dst_0)
    return
}
[export, sideeffects]
def RotatePointAroundVector(var dst_1 : float?; var dir : float const?; var point : float const?; var degrees : float) {
    var m : float[3][3]
    var im : float[3][3]
    var zrot : float[3][3]
    var tmpmat : float[3][3]
    var rot : float[3][3]
    var vr : vec3_t
    var vup : vec3_t
    var vf : vec3_t
    unsafe(unsafe(addr(vf[0]))[0]) = float(unsafe(dir[0]))  // nolint:PERF020
    unsafe(unsafe(addr(vf[0]))[1]) = float(unsafe(dir[1]))  // nolint:PERF020
    unsafe(unsafe(addr(vf[0]))[2]) = float(unsafe(dir[2]))  // nolint:PERF020
    PerpendicularVector(unsafe(addr<float?>(vr[0])), dir)
    CrossProduct(unsafe(addr<float?>(vr[0])), unsafe(addr<float?>(vf[0])), unsafe(addr<float?>(vup[0])))
    m[0][0] = float(unsafe(unsafe(addr(vr[0]))[0]))  // nolint:PERF020
    m[1][0] = float(unsafe(unsafe(addr(vr[0]))[1]))  // nolint:PERF020
    m[2][0] = float(unsafe(unsafe(addr(vr[0]))[2]))  // nolint:PERF020
    m[0][1] = float(unsafe(unsafe(addr(vup[0]))[0]))  // nolint:PERF020
    m[1][1] = float(unsafe(unsafe(addr(vup[0]))[1]))  // nolint:PERF020
    m[2][1] = float(unsafe(unsafe(addr(vup[0]))[2]))  // nolint:PERF020
    m[0][2] = float(unsafe(unsafe(addr(vf[0]))[0]))  // nolint:PERF020
    m[1][2] = float(unsafe(unsafe(addr(vf[0]))[1]))  // nolint:PERF020
    m[2][2] = float(unsafe(unsafe(addr(vf[0]))[2]))  // nolint:PERF020
    unsafe(memcpy(unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(im[0])))))), unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(m[0])))))), 36ul))
    im[0][1] = float(m[1][0])  // nolint:PERF020
    im[0][2] = float(m[2][0])  // nolint:PERF020
    im[1][0] = float(m[0][1])  // nolint:PERF020
    im[1][2] = float(m[2][1])  // nolint:PERF020
    im[2][0] = float(m[0][2])  // nolint:PERF020
    im[2][1] = float(m[1][2])  // nolint:PERF020
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(zrot[0])))), 0u8, 36ul)))
    zrot[2][2] = 1.0
    zrot[1][1] = float(zrot[2][2])  // nolint:PERF020
    zrot[0][0] = float(zrot[1][1])  // nolint:PERF020
    zrot[0][0] = float(cos(double(degrees) * 3.141592653589793lf / 180.0lf))
    zrot[0][1] = float(sin(double(degrees) * 3.141592653589793lf / 180.0lf))
    zrot[1][0] = float(-sin(double(degrees) * 3.141592653589793lf / 180.0lf))
    zrot[1][1] = float(cos(double(degrees) * 3.141592653589793lf / 180.0lf))
    R_ConcatRotations(unsafe(addr<float[3]?>(m[0])), unsafe(addr<float[3]?>(zrot[0])), unsafe(addr<float[3]?>(tmpmat[0])))
    R_ConcatRotations(unsafe(addr<float[3]?>(tmpmat[0])), unsafe(addr<float[3]?>(im[0])), unsafe(addr<float[3]?>(rot[0])))
    for (i_2 in range(0, 3)) {
        unsafe(dst_1[i_2]) = rot[i_2][0] * unsafe(point[0]) + rot[i_2][1] * unsafe(point[1]) + rot[i_2][2] * unsafe(point[2])
    }
    return
}
[sideeffects]
def private c2da_layout_proofs() {
    static_assert(typeinfo sizeof(type<mplane_s>) == 20, "C layout of mplane_s: sizeof")
    static_assert(typeinfo alignof(type<mplane_s>) == 4, "C layout of mplane_s: alignof")
    static_assert(typeinfo offsetof<normal>(type<mplane_s>) == 0, "C layout of mplane_s: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<mplane_s>) == 12, "C layout of mplane_s: offsetof dist")
    static_assert(typeinfo offsetof<type_0>(type<mplane_s>) == 16, "C layout of mplane_s: offsetof type_0")
    static_assert(typeinfo offsetof<signbits>(type<mplane_s>) == 17, "C layout of mplane_s: offsetof signbits")
    static_assert(typeinfo offsetof<pad>(type<mplane_s>) == 18, "C layout of mplane_s: offsetof pad")
    static_assert(typeinfo sizeof(type<mplane_t>) == 20, "C layout of mplane_t: sizeof")
    static_assert(typeinfo alignof(type<mplane_t>) == 4, "C layout of mplane_t: alignof")
    static_assert(typeinfo offsetof<normal>(type<mplane_t>) == 0, "C layout of mplane_t: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<mplane_t>) == 12, "C layout of mplane_t: offsetof dist")
    static_assert(typeinfo offsetof<type_0>(type<mplane_t>) == 16, "C layout of mplane_t: offsetof type_0")
    static_assert(typeinfo offsetof<signbits>(type<mplane_t>) == 17, "C layout of mplane_t: offsetof signbits")
    static_assert(typeinfo offsetof<pad>(type<mplane_t>) == 18, "C layout of mplane_t: offsetof pad")
}
