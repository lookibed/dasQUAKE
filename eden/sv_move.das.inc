[export, sideeffects]
def SV_CheckBottom(var ent : int) : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = SV_CheckBottom_c2da_frame(ent, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
var c_yes : int = default<int>

var c_no : int = default<int>

[export, sideeffects]
def SV_movestep(var ent_0 : int; var move : int; var relink : uint) : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = SV_movestep_c2da_frame(ent_0, move, relink, c2da_lin_enter(96))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def SV_MoveToGoal() {
    var ent_1 : int
    var goal : int
    var dist : float
    let c2da_fresh130 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    ent_1 = c2da_fresh130 + int(uint(c2da_mem[pr_global_struct + 112]) | uint(c2da_mem[pr_global_struct + 113]) << 0x8 | uint(c2da_mem[pr_global_struct + 114]) << 0x10 | uint(c2da_mem[pr_global_struct + 115]) << 0x18)
    goal = c2da_fresh130 + int(uint(c2da_mem[ent_1 + 460]) | uint(c2da_mem[ent_1 + 461]) << 0x8 | uint(c2da_mem[ent_1 + 462]) << 0x10 | uint(c2da_mem[ent_1 + 463]) << 0x18)
    dist = uint_bits_to_float(uint(c2da_mem[pr_globals + 4 * 4]) | uint(c2da_mem[pr_globals + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + 4 * 4 + 3]) << 0x18)
    if ((int(uint_bits_to_float(uint(c2da_mem[ent_1 + 412]) | uint(c2da_mem[ent_1 + 413]) << 0x8 | uint(c2da_mem[ent_1 + 414]) << 0x10 | uint(c2da_mem[ent_1 + 415]) << 0x18)) & (512 | 1 | 2)) == 0) {
        let c2da_fresh128 : float = 0.0
        let c2da_fresh129 : uint = float_bits_to_uint(c2da_fresh128)
        c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh129)
        c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh129 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh129 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh129 >> 0x18)
        return
    }
    if (int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[ent_1 + 408]) | uint(c2da_mem[ent_1 + 409]) << 0x8 | uint(c2da_mem[ent_1 + 410]) << 0x10 | uint(c2da_mem[ent_1 + 411]) << 0x18) != int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) && SV_CloseEnough(ent_1, goal, dist) != 0x0) {
        return
    }
    if ((c2da_std_rand() & 3) == 1 || uint(SV_StepDirection(ent_1, uint_bits_to_float(uint(c2da_mem[ent_1 + 448]) | uint(c2da_mem[ent_1 + 449]) << 0x8 | uint(c2da_mem[ent_1 + 450]) << 0x10 | uint(c2da_mem[ent_1 + 451]) << 0x18), dist)) == 0u) {
        SV_NewChaseDir(ent_1, goal, dist)
    }
    return
}
[export, sideeffects]
def SV_NewChaseDir(var actor : int; var enemy_0 : int; var dist_0 : float) {
    var deltax : float
    var deltay : float
    var d : float[3]
    var tdir : float
    var olddir : float
    var turnaround : float
    olddir = anglemod(float(int(uint_bits_to_float(uint(c2da_mem[actor + 448]) | uint(c2da_mem[actor + 449]) << 0x8 | uint(c2da_mem[actor + 450]) << 0x10 | uint(c2da_mem[actor + 451]) << 0x18) / 45.0) * 45))
    turnaround = anglemod(olddir - 180.0)
    deltax = uint_bits_to_float(uint(c2da_mem[enemy_0 + 148 + 0 * 4]) | uint(c2da_mem[enemy_0 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[enemy_0 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[enemy_0 + 148 + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[actor + 148 + 0 * 4]) | uint(c2da_mem[actor + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[actor + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[actor + 148 + 0 * 4 + 3]) << 0x18)
    deltay = uint_bits_to_float(uint(c2da_mem[enemy_0 + 148 + 1 * 4]) | uint(c2da_mem[enemy_0 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[enemy_0 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[enemy_0 + 148 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[actor + 148 + 1 * 4]) | uint(c2da_mem[actor + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[actor + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[actor + 148 + 1 * 4 + 3]) << 0x18)
    if (deltax > 10.0) {
        d[1] = 0.0
    } elif (deltax < -10.0) {
        d[1] = 180.0
    } else {
        d[1] = -1.0
    }
    if (deltay < -10.0) {
        d[2] = 270.0
    } elif (deltay > 10.0) {
        d[2] = 90.0
    } else {
        d[2] = -1.0
    }
    if (d[1] != -1.0 && d[2] != -1.0) {
        if (d[1] == 0.0) {
            tdir = float(d[2] == 90.0 ? 45 : 315)
        } else {
            tdir = float(d[2] == 90.0 ? 135 : 215)
        }
        if (tdir != turnaround && SV_StepDirection(actor, tdir, dist_0) != 0x0) {
            return
        }
    }
    if ((c2da_std_rand() & 3 & 1) != 0 || c2da_std_abs(int(deltay)) > c2da_std_abs(int(deltax))) {
        tdir = d[1]
        d[1] = float(d[2])  // nolint:PERF020
        d[2] = tdir
    }
    if (d[1] != -1.0 && d[1] != turnaround && SV_StepDirection(actor, d[1], dist_0) != 0x0) {
        return
    }
    if (d[2] != -1.0 && d[2] != turnaround && SV_StepDirection(actor, d[2], dist_0) != 0x0) {
        return
    }
    if (olddir != -1.0 && SV_StepDirection(actor, olddir, dist_0) != 0x0) {
        return
    }
    if ((c2da_std_rand() & 1) != 0) {
        tdir = 0.0
        while (tdir <= 315.0) {
            if (tdir != turnaround && SV_StepDirection(actor, tdir, dist_0) != 0x0) {
                return
            }
            tdir += 45.0
        }
    } else {
        tdir = 315.0
        while (tdir >= 0.0) {
            if (tdir != turnaround && SV_StepDirection(actor, tdir, dist_0) != 0x0) {
                return
            }
            tdir -= 45.0
        }
    }
    if (turnaround != -1.0 && SV_StepDirection(actor, turnaround, dist_0) != 0x0) {
        return
    }
    let c2da_fresh131 : uint = float_bits_to_uint(olddir)
    c2da_mem[actor + 448] = uint8(c2da_fresh131)
    c2da_mem[actor + 449] = uint8(c2da_fresh131 >> 0x8)
    c2da_mem[actor + 450] = uint8(c2da_fresh131 >> 0x10)
    c2da_mem[actor + 451] = uint8(c2da_fresh131 >> 0x18)
    if (SV_CheckBottom(actor) == 0u) {
        SV_FixCheckBottom(actor)
    }
    return
}
[export, sideeffects]
def SV_FixCheckBottom(var ent_2 : int) {
    let c2da_fresh132 : float = float(int(uint_bits_to_float(uint(c2da_mem[ent_2 + 412]) | uint(c2da_mem[ent_2 + 413]) << 0x8 | uint(c2da_mem[ent_2 + 414]) << 0x10 | uint(c2da_mem[ent_2 + 415]) << 0x18)) | 1024)
    let c2da_fresh133 : uint = float_bits_to_uint(c2da_fresh132)
    c2da_mem[ent_2 + 412] = uint8(c2da_fresh133)
    c2da_mem[ent_2 + 413] = uint8(c2da_fresh133 >> 0x8)
    c2da_mem[ent_2 + 414] = uint8(c2da_fresh133 >> 0x10)
    c2da_mem[ent_2 + 415] = uint8(c2da_fresh133 >> 0x18)
    return
}
[export, sideeffects]
def SV_StepDirection(var ent_3 : int; var yaw : float; var dist_1 : float) : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = SV_StepDirection_c2da_frame(ent_3, yaw, dist_1, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def SV_CloseEnough(var ent_4 : int; var goal_0 : int; var dist_2 : float) : uint {
    for (i_0 in range(0, 3)) {
        if (uint_bits_to_float(uint(c2da_mem[goal_0 + 112 + i_0 * 4]) | uint(c2da_mem[goal_0 + 112 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[goal_0 + 112 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[goal_0 + 112 + i_0 * 4 + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[ent_4 + 124 + i_0 * 4]) | uint(c2da_mem[ent_4 + 124 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_4 + 124 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_4 + 124 + i_0 * 4 + 3]) << 0x18) + dist_2) {
            return 0u
        }
        if (uint_bits_to_float(uint(c2da_mem[goal_0 + 124 + i_0 * 4]) | uint(c2da_mem[goal_0 + 124 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[goal_0 + 124 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[goal_0 + 124 + i_0 * 4 + 3]) << 0x18) < uint_bits_to_float(uint(c2da_mem[ent_4 + 112 + i_0 * 4]) | uint(c2da_mem[ent_4 + 112 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_4 + 112 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_4 + 112 + i_0 * 4 + 3]) << 0x18) - dist_2) {
            return 0u
        }
    }
    return 1u
}
[sideeffects]
def private SV_CheckBottom_c2da_frame(var ent : int; c2da_fp : int) : uint {
    var mins : vec3_t
    var maxs : vec3_t
    var trace : trace_t
    var x : int
    var y : int
    var mid : float
    var bottom : float
    mins[0] = uint_bits_to_float(uint(c2da_mem[ent + 148 + 0 * 4]) | uint(c2da_mem[ent + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 148 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent + 240 + 0 * 4]) | uint(c2da_mem[ent + 240 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 240 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 240 + 0 * 4 + 3]) << 0x18)
    mins[1] = uint_bits_to_float(uint(c2da_mem[ent + 148 + 1 * 4]) | uint(c2da_mem[ent + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 148 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent + 240 + 1 * 4]) | uint(c2da_mem[ent + 240 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 240 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 240 + 1 * 4 + 3]) << 0x18)
    mins[2] = uint_bits_to_float(uint(c2da_mem[ent + 148 + 2 * 4]) | uint(c2da_mem[ent + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent + 240 + 2 * 4]) | uint(c2da_mem[ent + 240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 240 + 2 * 4 + 3]) << 0x18)
    maxs[0] = uint_bits_to_float(uint(c2da_mem[ent + 148 + 0 * 4]) | uint(c2da_mem[ent + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 148 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent + 252 + 0 * 4]) | uint(c2da_mem[ent + 252 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 252 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 252 + 0 * 4 + 3]) << 0x18)
    maxs[1] = uint_bits_to_float(uint(c2da_mem[ent + 148 + 1 * 4]) | uint(c2da_mem[ent + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 148 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent + 252 + 1 * 4]) | uint(c2da_mem[ent + 252 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 252 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 252 + 1 * 4 + 3]) << 0x18)
    maxs[2] = uint_bits_to_float(uint(c2da_mem[ent + 148 + 2 * 4]) | uint(c2da_mem[ent + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[ent + 252 + 2 * 4]) | uint(c2da_mem[ent + 252 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent + 252 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent + 252 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh0 : float = mins[2] - 1.0
    let c2da_fresh1 : uint = float_bits_to_uint(c2da_fresh0)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh1)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
    x = 0
    label 0:
    if (x <= 1) {
        goto label 1
    }
    c_yes++
    return 1u
    label 1:
    y = 0
    label 2:
    if (y <= 1) {
        goto label 3
    }
    x++
    goto label 0
    label 3:
    let c2da_fresh2 : float = x != 0 ? maxs[0] : mins[0]
    let c2da_fresh3 : uint = float_bits_to_uint(c2da_fresh2)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh3)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : float = y != 0 ? maxs[1] : mins[1]
    let c2da_fresh5 : uint = float_bits_to_uint(c2da_fresh4)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh5)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh5 >> 0x18)
    if (SV_PointContents(c2da_fp) != -2) {
        goto label 4
    }
    y++
    goto label 2
    label 4:
    c_no++
    let c2da_fresh6 : float = mins[2]
    let c2da_fresh7 : uint = float_bits_to_uint(c2da_fresh6)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh7)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
    let c2da_fresh8 : float = float(double(mins[0] + maxs[0]) * 0.5lf)
    let c2da_fresh9 : uint = float_bits_to_uint(c2da_fresh8)
    c2da_mem[c2da_fp + 16 + 0 * 4] = uint8(c2da_fresh9)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 1] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 2] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 3] = uint8(c2da_fresh9 >> 0x18)
    let c2da_fresh10 : uint = float_bits_to_uint(c2da_fresh8)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh10)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh10 >> 0x18)
    let c2da_fresh11 : float = float(double(mins[1] + maxs[1]) * 0.5lf)
    let c2da_fresh12 : uint = float_bits_to_uint(c2da_fresh11)
    c2da_mem[c2da_fp + 16 + 1 * 4] = uint8(c2da_fresh12)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 1] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 2] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 3] = uint8(c2da_fresh12 >> 0x18)
    let c2da_fresh13 : uint = float_bits_to_uint(c2da_fresh11)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh13)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh13 >> 0x18)
    let c2da_fresh14 : float = c2da_fresh6 - float(2 * 18)
    let c2da_fresh15 : uint = float_bits_to_uint(c2da_fresh14)
    c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh15)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh15 >> 0x18)
    trace = SV_Move(c2da_fp, 194432, 194432, c2da_fp + 16, 1, ent)
    if (double(trace.fraction) == 1.0lf) {
        goto label 12
    }
    bottom = trace.endpos[2]
    mid = bottom
    x = 0
    label 5:
    if (x <= 1) {
        goto label 6
    }
    c_yes++
    return 1u
    label 6:
    y = 0
    label 7:
    if (y <= 1) {
        goto label 8
    }
    x++
    goto label 5
    label 8:
    let c2da_fresh16 : float = x != 0 ? maxs[0] : mins[0]
    let c2da_fresh17 : uint = float_bits_to_uint(c2da_fresh16)
    c2da_mem[c2da_fp + 16 + 0 * 4] = uint8(c2da_fresh17)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
    let c2da_fresh18 : uint = float_bits_to_uint(c2da_fresh16)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh18)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh18 >> 0x18)
    let c2da_fresh19 : float = y != 0 ? maxs[1] : mins[1]
    let c2da_fresh20 : uint = float_bits_to_uint(c2da_fresh19)
    c2da_mem[c2da_fp + 16 + 1 * 4] = uint8(c2da_fresh20)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 1] = uint8(c2da_fresh20 >> 0x8)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 2] = uint8(c2da_fresh20 >> 0x10)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 3] = uint8(c2da_fresh20 >> 0x18)
    let c2da_fresh21 : uint = float_bits_to_uint(c2da_fresh19)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh21)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh21 >> 0x18)
    trace = SV_Move(c2da_fp, 194432, 194432, c2da_fp + 16, 1, ent)
    if (double(trace.fraction) != 1.0lf && trace.endpos[2] > bottom) {
        goto label 11
    }
    label 9:
    if (double(trace.fraction) == 1.0lf || mid - trace.endpos[2] > 18.0) {
        goto label 10
    }
    y++
    goto label 7
    label 10:
    return 0u
    label 11:
    bottom = trace.endpos[2]
    goto label 9
    label 12:
    return 0u
}
[sideeffects]
def private SV_movestep_c2da_frame(var ent_0 : int; var move : int; var relink : uint; c2da_fp : int) : uint {
    var dz : float
    var oldorg : vec3_t
    var enemy : int
    oldorg[0] = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 0 * 4]) | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 3]) << 0x18)
    oldorg[1] = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 1 * 4]) | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 3]) << 0x18)
    oldorg[2] = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 2 * 4]) | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh22 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 0 * 4]) | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[move + 0 * 4]) | uint(c2da_mem[move + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[move + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[move + 0 * 4 + 3]) << 0x18)
    let c2da_fresh23 : uint = float_bits_to_uint(c2da_fresh22)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh23)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh23 >> 0x18)
    let c2da_fresh24 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 1 * 4]) | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[move + 1 * 4]) | uint(c2da_mem[move + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[move + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[move + 1 * 4 + 3]) << 0x18)
    let c2da_fresh25 : uint = float_bits_to_uint(c2da_fresh24)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh25)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh25 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh25 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh25 >> 0x18)
    let c2da_fresh26 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 2 * 4]) | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[move + 2 * 4]) | uint(c2da_mem[move + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[move + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[move + 2 * 4 + 3]) << 0x18)
    let c2da_fresh27 : uint = float_bits_to_uint(c2da_fresh26)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh27)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh27 >> 0x18)
    let c2da_fresh123 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 412]) | uint(c2da_mem[ent_0 + 413]) << 0x8 | uint(c2da_mem[ent_0 + 414]) << 0x10 | uint(c2da_mem[ent_0 + 415]) << 0x18)
    if ((int(c2da_fresh123) & (2 | 1)) != 0) {
        for (i in range(0, 2)) {
            let c2da_fresh28 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 0 * 4]) | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[move + 0 * 4]) | uint(c2da_mem[move + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[move + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[move + 0 * 4 + 3]) << 0x18)
            let c2da_fresh29 : uint = float_bits_to_uint(c2da_fresh28)
            c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh29)
            c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh29 >> 0x8)
            c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh29 >> 0x10)
            c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh29 >> 0x18)
            let c2da_fresh30 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 1 * 4]) | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[move + 1 * 4]) | uint(c2da_mem[move + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[move + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[move + 1 * 4 + 3]) << 0x18)
            let c2da_fresh31 : uint = float_bits_to_uint(c2da_fresh30)
            c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh31)
            c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh31 >> 0x8)
            c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh31 >> 0x10)
            c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh31 >> 0x18)
            let c2da_fresh32 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 2 * 4]) | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[move + 2 * 4]) | uint(c2da_mem[move + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[move + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[move + 2 * 4 + 3]) << 0x18)
            let c2da_fresh33 : uint = float_bits_to_uint(c2da_fresh32)
            c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh33)
            c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh33 >> 0x8)
            c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh33 >> 0x10)
            c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh33 >> 0x18)
            let c2da_fresh125 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
            let c2da_fresh126 : int = int(uint(c2da_mem[ent_0 + 408]) | uint(c2da_mem[ent_0 + 409]) << 0x8 | uint(c2da_mem[ent_0 + 410]) << 0x10 | uint(c2da_mem[ent_0 + 411]) << 0x18)
            enemy = c2da_fresh125 + c2da_fresh126
            if (i == 0 && enemy != c2da_fresh125) {
                let c2da_fresh34 : int = c2da_fresh125 + c2da_fresh126 + 148 + 2 * 4
                dz = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 2 * 4]) | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fresh34]) | uint(c2da_mem[c2da_fresh34 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh34 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh34 + 3]) << 0x18)
                if (dz > 40.0) {
                    let c2da_fresh35 : float = c2da_fresh32 - 8.0
                    let c2da_fresh36 : uint = float_bits_to_uint(c2da_fresh35)
                    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh36)
                    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh36 >> 0x8)
                    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh36 >> 0x10)
                    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh36 >> 0x18)
                }
                if (dz < 30.0) {
                    let c2da_fresh37 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) + 8.0
                    let c2da_fresh38 : uint = float_bits_to_uint(c2da_fresh37)
                    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh38)
                    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh38 >> 0x8)
                    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh38 >> 0x10)
                    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh38 >> 0x18)
                }
            }
            var c2da_fresh39 : trace_t = SV_Move(ent_0 + 148, ent_0 + 240, ent_0 + 252, c2da_fp, 0, ent_0)
            let c2da_fresh40 : uint = c2da_fresh39.allsolid
            c2da_mem[c2da_fp + 16] = uint8(c2da_fresh40)
            c2da_mem[c2da_fp + 17] = uint8(c2da_fresh40 >> 0x8)
            c2da_mem[c2da_fp + 18] = uint8(c2da_fresh40 >> 0x10)
            c2da_mem[c2da_fp + 19] = uint8(c2da_fresh40 >> 0x18)
            let c2da_fresh41 : uint = c2da_fresh39.startsolid
            c2da_mem[c2da_fp + 20] = uint8(c2da_fresh41)
            c2da_mem[c2da_fp + 21] = uint8(c2da_fresh41 >> 0x8)
            c2da_mem[c2da_fp + 22] = uint8(c2da_fresh41 >> 0x10)
            c2da_mem[c2da_fp + 23] = uint8(c2da_fresh41 >> 0x18)
            let c2da_fresh42 : uint = c2da_fresh39.inopen
            c2da_mem[c2da_fp + 24] = uint8(c2da_fresh42)
            c2da_mem[c2da_fp + 25] = uint8(c2da_fresh42 >> 0x8)
            c2da_mem[c2da_fp + 26] = uint8(c2da_fresh42 >> 0x10)
            c2da_mem[c2da_fp + 27] = uint8(c2da_fresh42 >> 0x18)
            let c2da_fresh43 : uint = c2da_fresh39.inwater
            c2da_mem[c2da_fp + 28] = uint8(c2da_fresh43)
            c2da_mem[c2da_fp + 29] = uint8(c2da_fresh43 >> 0x8)
            c2da_mem[c2da_fp + 30] = uint8(c2da_fresh43 >> 0x10)
            c2da_mem[c2da_fp + 31] = uint8(c2da_fresh43 >> 0x18)
            let c2da_fresh44 : uint = float_bits_to_uint(c2da_fresh39.fraction)
            c2da_mem[c2da_fp + 32] = uint8(c2da_fresh44)
            c2da_mem[c2da_fp + 33] = uint8(c2da_fresh44 >> 0x8)
            c2da_mem[c2da_fp + 34] = uint8(c2da_fresh44 >> 0x10)
            c2da_mem[c2da_fp + 35] = uint8(c2da_fresh44 >> 0x18)
            let c2da_fresh45 : uint = float_bits_to_uint(c2da_fresh39.endpos[0])
            c2da_mem[c2da_fp + 36] = uint8(c2da_fresh45)
            c2da_mem[c2da_fp + 37] = uint8(c2da_fresh45 >> 0x8)
            c2da_mem[c2da_fp + 38] = uint8(c2da_fresh45 >> 0x10)
            c2da_mem[c2da_fp + 39] = uint8(c2da_fresh45 >> 0x18)
            let c2da_fresh46 : uint = float_bits_to_uint(c2da_fresh39.endpos[1])
            c2da_mem[c2da_fp + 40] = uint8(c2da_fresh46)
            c2da_mem[c2da_fp + 41] = uint8(c2da_fresh46 >> 0x8)
            c2da_mem[c2da_fp + 42] = uint8(c2da_fresh46 >> 0x10)
            c2da_mem[c2da_fp + 43] = uint8(c2da_fresh46 >> 0x18)
            let c2da_fresh47 : uint = float_bits_to_uint(c2da_fresh39.endpos[2])
            c2da_mem[c2da_fp + 44] = uint8(c2da_fresh47)
            c2da_mem[c2da_fp + 45] = uint8(c2da_fresh47 >> 0x8)
            c2da_mem[c2da_fp + 46] = uint8(c2da_fresh47 >> 0x10)
            c2da_mem[c2da_fp + 47] = uint8(c2da_fresh47 >> 0x18)
            let c2da_fresh48 : uint = float_bits_to_uint(c2da_fresh39.plane.normal[0])
            c2da_mem[c2da_fp + 48] = uint8(c2da_fresh48)
            c2da_mem[c2da_fp + 49] = uint8(c2da_fresh48 >> 0x8)
            c2da_mem[c2da_fp + 50] = uint8(c2da_fresh48 >> 0x10)
            c2da_mem[c2da_fp + 51] = uint8(c2da_fresh48 >> 0x18)
            let c2da_fresh49 : uint = float_bits_to_uint(c2da_fresh39.plane.normal[1])
            c2da_mem[c2da_fp + 52] = uint8(c2da_fresh49)
            c2da_mem[c2da_fp + 53] = uint8(c2da_fresh49 >> 0x8)
            c2da_mem[c2da_fp + 54] = uint8(c2da_fresh49 >> 0x10)
            c2da_mem[c2da_fp + 55] = uint8(c2da_fresh49 >> 0x18)
            let c2da_fresh50 : uint = float_bits_to_uint(c2da_fresh39.plane.normal[2])
            c2da_mem[c2da_fp + 56] = uint8(c2da_fresh50)
            c2da_mem[c2da_fp + 57] = uint8(c2da_fresh50 >> 0x8)
            c2da_mem[c2da_fp + 58] = uint8(c2da_fresh50 >> 0x10)
            c2da_mem[c2da_fp + 59] = uint8(c2da_fresh50 >> 0x18)
            let c2da_fresh51 : uint = float_bits_to_uint(c2da_fresh39.plane.dist)
            c2da_mem[c2da_fp + 60] = uint8(c2da_fresh51)
            c2da_mem[c2da_fp + 61] = uint8(c2da_fresh51 >> 0x8)
            c2da_mem[c2da_fp + 62] = uint8(c2da_fresh51 >> 0x10)
            c2da_mem[c2da_fp + 63] = uint8(c2da_fresh51 >> 0x18)
            let c2da_fresh52 : uint = uint(c2da_fresh39.ent)
            c2da_mem[c2da_fp + 64] = uint8(c2da_fresh52)
            c2da_mem[c2da_fp + 65] = uint8(c2da_fresh52 >> 0x8)
            c2da_mem[c2da_fp + 66] = uint8(c2da_fresh52 >> 0x10)
            c2da_mem[c2da_fp + 67] = uint8(c2da_fresh52 >> 0x18)
            c2da_mem[c2da_fp + 68] = 0u8
            c2da_mem[c2da_fp + 69] = 0u8
            c2da_mem[c2da_fp + 70] = 0u8
            c2da_mem[c2da_fp + 71] = 0u8
            if (uint_bits_to_float(uint(c2da_mem[c2da_fp + 32]) | uint(c2da_mem[c2da_fp + 33]) << 0x8 | uint(c2da_mem[c2da_fp + 34]) << 0x10 | uint(c2da_mem[c2da_fp + 35]) << 0x18) == 1.0) {
                if ((int(uint_bits_to_float(uint(c2da_mem[ent_0 + 412]) | uint(c2da_mem[ent_0 + 413]) << 0x8 | uint(c2da_mem[ent_0 + 414]) << 0x10 | uint(c2da_mem[ent_0 + 415]) << 0x18)) & 2) != 0 && SV_PointContents(c2da_fp + 36) == -1) {
                    return 0u
                }
                let c2da_fresh53 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 36 + 0 * 4]) | uint(c2da_mem[c2da_fp + 36 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 36 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 36 + 0 * 4 + 3]) << 0x18)
                let c2da_fresh54 : uint = float_bits_to_uint(c2da_fresh53)
                c2da_mem[ent_0 + 148 + 0 * 4] = uint8(c2da_fresh54)
                c2da_mem[ent_0 + 148 + 0 * 4 + 1] = uint8(c2da_fresh54 >> 0x8)
                c2da_mem[ent_0 + 148 + 0 * 4 + 2] = uint8(c2da_fresh54 >> 0x10)
                c2da_mem[ent_0 + 148 + 0 * 4 + 3] = uint8(c2da_fresh54 >> 0x18)
                let c2da_fresh55 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 36 + 1 * 4]) | uint(c2da_mem[c2da_fp + 36 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 36 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 36 + 1 * 4 + 3]) << 0x18)
                let c2da_fresh56 : uint = float_bits_to_uint(c2da_fresh55)
                c2da_mem[ent_0 + 148 + 1 * 4] = uint8(c2da_fresh56)
                c2da_mem[ent_0 + 148 + 1 * 4 + 1] = uint8(c2da_fresh56 >> 0x8)
                c2da_mem[ent_0 + 148 + 1 * 4 + 2] = uint8(c2da_fresh56 >> 0x10)
                c2da_mem[ent_0 + 148 + 1 * 4 + 3] = uint8(c2da_fresh56 >> 0x18)
                let c2da_fresh57 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 36 + 2 * 4]) | uint(c2da_mem[c2da_fp + 36 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 36 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 36 + 2 * 4 + 3]) << 0x18)
                let c2da_fresh58 : uint = float_bits_to_uint(c2da_fresh57)
                c2da_mem[ent_0 + 148 + 2 * 4] = uint8(c2da_fresh58)
                c2da_mem[ent_0 + 148 + 2 * 4 + 1] = uint8(c2da_fresh58 >> 0x8)
                c2da_mem[ent_0 + 148 + 2 * 4 + 2] = uint8(c2da_fresh58 >> 0x10)
                c2da_mem[ent_0 + 148 + 2 * 4 + 3] = uint8(c2da_fresh58 >> 0x18)
                if (relink != 0u) {
                    SV_LinkEdict(ent_0, 1u)
                }
                return 1u
            }
            if (enemy == int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)) {
                break
            }
        }
        return 0u
    }
    let c2da_fresh59 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) + 18.0
    let c2da_fresh60 : uint = float_bits_to_uint(c2da_fresh59)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh60)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh60 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh60 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh60 >> 0x18)
    let c2da_fresh61 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
    let c2da_fresh62 : uint = float_bits_to_uint(c2da_fresh61)
    c2da_mem[c2da_fp + 80 + 0 * 4] = uint8(c2da_fresh62)
    c2da_mem[c2da_fp + 80 + 0 * 4 + 1] = uint8(c2da_fresh62 >> 0x8)
    c2da_mem[c2da_fp + 80 + 0 * 4 + 2] = uint8(c2da_fresh62 >> 0x10)
    c2da_mem[c2da_fp + 80 + 0 * 4 + 3] = uint8(c2da_fresh62 >> 0x18)
    let c2da_fresh63 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
    let c2da_fresh64 : uint = float_bits_to_uint(c2da_fresh63)
    c2da_mem[c2da_fp + 80 + 1 * 4] = uint8(c2da_fresh64)
    c2da_mem[c2da_fp + 80 + 1 * 4 + 1] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[c2da_fp + 80 + 1 * 4 + 2] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[c2da_fp + 80 + 1 * 4 + 3] = uint8(c2da_fresh64 >> 0x18)
    let c2da_fresh65 : float = c2da_fresh59
    let c2da_fresh66 : uint = float_bits_to_uint(c2da_fresh65)
    c2da_mem[c2da_fp + 80 + 2 * 4] = uint8(c2da_fresh66)
    c2da_mem[c2da_fp + 80 + 2 * 4 + 1] = uint8(c2da_fresh66 >> 0x8)
    c2da_mem[c2da_fp + 80 + 2 * 4 + 2] = uint8(c2da_fresh66 >> 0x10)
    c2da_mem[c2da_fp + 80 + 2 * 4 + 3] = uint8(c2da_fresh66 >> 0x18)
    let c2da_fresh67 : float = c2da_fresh65 - float(18 * 2)
    let c2da_fresh68 : uint = float_bits_to_uint(c2da_fresh67)
    c2da_mem[c2da_fp + 80 + 2 * 4] = uint8(c2da_fresh68)
    c2da_mem[c2da_fp + 80 + 2 * 4 + 1] = uint8(c2da_fresh68 >> 0x8)
    c2da_mem[c2da_fp + 80 + 2 * 4 + 2] = uint8(c2da_fresh68 >> 0x10)
    c2da_mem[c2da_fp + 80 + 2 * 4 + 3] = uint8(c2da_fresh68 >> 0x18)
    var c2da_fresh69 : trace_t = SV_Move(c2da_fp, ent_0 + 240, ent_0 + 252, c2da_fp + 80, 0, ent_0)
    let c2da_fresh70 : uint = c2da_fresh69.allsolid
    c2da_mem[c2da_fp + 16] = uint8(c2da_fresh70)
    c2da_mem[c2da_fp + 17] = uint8(c2da_fresh70 >> 0x8)
    c2da_mem[c2da_fp + 18] = uint8(c2da_fresh70 >> 0x10)
    c2da_mem[c2da_fp + 19] = uint8(c2da_fresh70 >> 0x18)
    let c2da_fresh71 : uint = c2da_fresh69.startsolid
    c2da_mem[c2da_fp + 20] = uint8(c2da_fresh71)
    c2da_mem[c2da_fp + 21] = uint8(c2da_fresh71 >> 0x8)
    c2da_mem[c2da_fp + 22] = uint8(c2da_fresh71 >> 0x10)
    c2da_mem[c2da_fp + 23] = uint8(c2da_fresh71 >> 0x18)
    let c2da_fresh72 : uint = c2da_fresh69.inopen
    c2da_mem[c2da_fp + 24] = uint8(c2da_fresh72)
    c2da_mem[c2da_fp + 25] = uint8(c2da_fresh72 >> 0x8)
    c2da_mem[c2da_fp + 26] = uint8(c2da_fresh72 >> 0x10)
    c2da_mem[c2da_fp + 27] = uint8(c2da_fresh72 >> 0x18)
    let c2da_fresh73 : uint = c2da_fresh69.inwater
    c2da_mem[c2da_fp + 28] = uint8(c2da_fresh73)
    c2da_mem[c2da_fp + 29] = uint8(c2da_fresh73 >> 0x8)
    c2da_mem[c2da_fp + 30] = uint8(c2da_fresh73 >> 0x10)
    c2da_mem[c2da_fp + 31] = uint8(c2da_fresh73 >> 0x18)
    let c2da_fresh74 : uint = float_bits_to_uint(c2da_fresh69.fraction)
    c2da_mem[c2da_fp + 32] = uint8(c2da_fresh74)
    c2da_mem[c2da_fp + 33] = uint8(c2da_fresh74 >> 0x8)
    c2da_mem[c2da_fp + 34] = uint8(c2da_fresh74 >> 0x10)
    c2da_mem[c2da_fp + 35] = uint8(c2da_fresh74 >> 0x18)
    let c2da_fresh75 : uint = float_bits_to_uint(c2da_fresh69.endpos[0])
    c2da_mem[c2da_fp + 36] = uint8(c2da_fresh75)
    c2da_mem[c2da_fp + 37] = uint8(c2da_fresh75 >> 0x8)
    c2da_mem[c2da_fp + 38] = uint8(c2da_fresh75 >> 0x10)
    c2da_mem[c2da_fp + 39] = uint8(c2da_fresh75 >> 0x18)
    let c2da_fresh76 : uint = float_bits_to_uint(c2da_fresh69.endpos[1])
    c2da_mem[c2da_fp + 40] = uint8(c2da_fresh76)
    c2da_mem[c2da_fp + 41] = uint8(c2da_fresh76 >> 0x8)
    c2da_mem[c2da_fp + 42] = uint8(c2da_fresh76 >> 0x10)
    c2da_mem[c2da_fp + 43] = uint8(c2da_fresh76 >> 0x18)
    let c2da_fresh77 : uint = float_bits_to_uint(c2da_fresh69.endpos[2])
    c2da_mem[c2da_fp + 44] = uint8(c2da_fresh77)
    c2da_mem[c2da_fp + 45] = uint8(c2da_fresh77 >> 0x8)
    c2da_mem[c2da_fp + 46] = uint8(c2da_fresh77 >> 0x10)
    c2da_mem[c2da_fp + 47] = uint8(c2da_fresh77 >> 0x18)
    let c2da_fresh78 : uint = float_bits_to_uint(c2da_fresh69.plane.normal[0])
    c2da_mem[c2da_fp + 48] = uint8(c2da_fresh78)
    c2da_mem[c2da_fp + 49] = uint8(c2da_fresh78 >> 0x8)
    c2da_mem[c2da_fp + 50] = uint8(c2da_fresh78 >> 0x10)
    c2da_mem[c2da_fp + 51] = uint8(c2da_fresh78 >> 0x18)
    let c2da_fresh79 : uint = float_bits_to_uint(c2da_fresh69.plane.normal[1])
    c2da_mem[c2da_fp + 52] = uint8(c2da_fresh79)
    c2da_mem[c2da_fp + 53] = uint8(c2da_fresh79 >> 0x8)
    c2da_mem[c2da_fp + 54] = uint8(c2da_fresh79 >> 0x10)
    c2da_mem[c2da_fp + 55] = uint8(c2da_fresh79 >> 0x18)
    let c2da_fresh80 : uint = float_bits_to_uint(c2da_fresh69.plane.normal[2])
    c2da_mem[c2da_fp + 56] = uint8(c2da_fresh80)
    c2da_mem[c2da_fp + 57] = uint8(c2da_fresh80 >> 0x8)
    c2da_mem[c2da_fp + 58] = uint8(c2da_fresh80 >> 0x10)
    c2da_mem[c2da_fp + 59] = uint8(c2da_fresh80 >> 0x18)
    let c2da_fresh81 : uint = float_bits_to_uint(c2da_fresh69.plane.dist)
    c2da_mem[c2da_fp + 60] = uint8(c2da_fresh81)
    c2da_mem[c2da_fp + 61] = uint8(c2da_fresh81 >> 0x8)
    c2da_mem[c2da_fp + 62] = uint8(c2da_fresh81 >> 0x10)
    c2da_mem[c2da_fp + 63] = uint8(c2da_fresh81 >> 0x18)
    let c2da_fresh82 : uint = uint(c2da_fresh69.ent)
    c2da_mem[c2da_fp + 64] = uint8(c2da_fresh82)
    c2da_mem[c2da_fp + 65] = uint8(c2da_fresh82 >> 0x8)
    c2da_mem[c2da_fp + 66] = uint8(c2da_fresh82 >> 0x10)
    c2da_mem[c2da_fp + 67] = uint8(c2da_fresh82 >> 0x18)
    c2da_mem[c2da_fp + 68] = 0u8
    c2da_mem[c2da_fp + 69] = 0u8
    c2da_mem[c2da_fp + 70] = 0u8
    c2da_mem[c2da_fp + 71] = 0u8
    if ((uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18) != 0u) {
        return 0u
    }
    if ((uint(c2da_mem[c2da_fp + 20]) | uint(c2da_mem[c2da_fp + 21]) << 0x8 | uint(c2da_mem[c2da_fp + 22]) << 0x10 | uint(c2da_mem[c2da_fp + 23]) << 0x18) != 0u) {
        let c2da_fresh83 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) - 18.0
        let c2da_fresh84 : uint = float_bits_to_uint(c2da_fresh83)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh84)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh84 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh84 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh84 >> 0x18)
        var c2da_fresh85 : trace_t = SV_Move(c2da_fp, ent_0 + 240, ent_0 + 252, c2da_fp + 80, 0, ent_0)
        let c2da_fresh86 : uint = c2da_fresh85.allsolid
        c2da_mem[c2da_fp + 16] = uint8(c2da_fresh86)
        c2da_mem[c2da_fp + 17] = uint8(c2da_fresh86 >> 0x8)
        c2da_mem[c2da_fp + 18] = uint8(c2da_fresh86 >> 0x10)
        c2da_mem[c2da_fp + 19] = uint8(c2da_fresh86 >> 0x18)
        let c2da_fresh87 : uint = c2da_fresh85.startsolid
        c2da_mem[c2da_fp + 20] = uint8(c2da_fresh87)
        c2da_mem[c2da_fp + 21] = uint8(c2da_fresh87 >> 0x8)
        c2da_mem[c2da_fp + 22] = uint8(c2da_fresh87 >> 0x10)
        c2da_mem[c2da_fp + 23] = uint8(c2da_fresh87 >> 0x18)
        let c2da_fresh88 : uint = c2da_fresh85.inopen
        c2da_mem[c2da_fp + 24] = uint8(c2da_fresh88)
        c2da_mem[c2da_fp + 25] = uint8(c2da_fresh88 >> 0x8)
        c2da_mem[c2da_fp + 26] = uint8(c2da_fresh88 >> 0x10)
        c2da_mem[c2da_fp + 27] = uint8(c2da_fresh88 >> 0x18)
        let c2da_fresh89 : uint = c2da_fresh85.inwater
        c2da_mem[c2da_fp + 28] = uint8(c2da_fresh89)
        c2da_mem[c2da_fp + 29] = uint8(c2da_fresh89 >> 0x8)
        c2da_mem[c2da_fp + 30] = uint8(c2da_fresh89 >> 0x10)
        c2da_mem[c2da_fp + 31] = uint8(c2da_fresh89 >> 0x18)
        let c2da_fresh90 : uint = float_bits_to_uint(c2da_fresh85.fraction)
        c2da_mem[c2da_fp + 32] = uint8(c2da_fresh90)
        c2da_mem[c2da_fp + 33] = uint8(c2da_fresh90 >> 0x8)
        c2da_mem[c2da_fp + 34] = uint8(c2da_fresh90 >> 0x10)
        c2da_mem[c2da_fp + 35] = uint8(c2da_fresh90 >> 0x18)
        let c2da_fresh91 : uint = float_bits_to_uint(c2da_fresh85.endpos[0])
        c2da_mem[c2da_fp + 36] = uint8(c2da_fresh91)
        c2da_mem[c2da_fp + 37] = uint8(c2da_fresh91 >> 0x8)
        c2da_mem[c2da_fp + 38] = uint8(c2da_fresh91 >> 0x10)
        c2da_mem[c2da_fp + 39] = uint8(c2da_fresh91 >> 0x18)
        let c2da_fresh92 : uint = float_bits_to_uint(c2da_fresh85.endpos[1])
        c2da_mem[c2da_fp + 40] = uint8(c2da_fresh92)
        c2da_mem[c2da_fp + 41] = uint8(c2da_fresh92 >> 0x8)
        c2da_mem[c2da_fp + 42] = uint8(c2da_fresh92 >> 0x10)
        c2da_mem[c2da_fp + 43] = uint8(c2da_fresh92 >> 0x18)
        let c2da_fresh93 : uint = float_bits_to_uint(c2da_fresh85.endpos[2])
        c2da_mem[c2da_fp + 44] = uint8(c2da_fresh93)
        c2da_mem[c2da_fp + 45] = uint8(c2da_fresh93 >> 0x8)
        c2da_mem[c2da_fp + 46] = uint8(c2da_fresh93 >> 0x10)
        c2da_mem[c2da_fp + 47] = uint8(c2da_fresh93 >> 0x18)
        let c2da_fresh94 : uint = float_bits_to_uint(c2da_fresh85.plane.normal[0])
        c2da_mem[c2da_fp + 48] = uint8(c2da_fresh94)
        c2da_mem[c2da_fp + 49] = uint8(c2da_fresh94 >> 0x8)
        c2da_mem[c2da_fp + 50] = uint8(c2da_fresh94 >> 0x10)
        c2da_mem[c2da_fp + 51] = uint8(c2da_fresh94 >> 0x18)
        let c2da_fresh95 : uint = float_bits_to_uint(c2da_fresh85.plane.normal[1])
        c2da_mem[c2da_fp + 52] = uint8(c2da_fresh95)
        c2da_mem[c2da_fp + 53] = uint8(c2da_fresh95 >> 0x8)
        c2da_mem[c2da_fp + 54] = uint8(c2da_fresh95 >> 0x10)
        c2da_mem[c2da_fp + 55] = uint8(c2da_fresh95 >> 0x18)
        let c2da_fresh96 : uint = float_bits_to_uint(c2da_fresh85.plane.normal[2])
        c2da_mem[c2da_fp + 56] = uint8(c2da_fresh96)
        c2da_mem[c2da_fp + 57] = uint8(c2da_fresh96 >> 0x8)
        c2da_mem[c2da_fp + 58] = uint8(c2da_fresh96 >> 0x10)
        c2da_mem[c2da_fp + 59] = uint8(c2da_fresh96 >> 0x18)
        let c2da_fresh97 : uint = float_bits_to_uint(c2da_fresh85.plane.dist)
        c2da_mem[c2da_fp + 60] = uint8(c2da_fresh97)
        c2da_mem[c2da_fp + 61] = uint8(c2da_fresh97 >> 0x8)
        c2da_mem[c2da_fp + 62] = uint8(c2da_fresh97 >> 0x10)
        c2da_mem[c2da_fp + 63] = uint8(c2da_fresh97 >> 0x18)
        let c2da_fresh98 : uint = uint(c2da_fresh85.ent)
        c2da_mem[c2da_fp + 64] = uint8(c2da_fresh98)
        c2da_mem[c2da_fp + 65] = uint8(c2da_fresh98 >> 0x8)
        c2da_mem[c2da_fp + 66] = uint8(c2da_fresh98 >> 0x10)
        c2da_mem[c2da_fp + 67] = uint8(c2da_fresh98 >> 0x18)
        c2da_mem[c2da_fp + 68] = 0u8
        c2da_mem[c2da_fp + 69] = 0u8
        c2da_mem[c2da_fp + 70] = 0u8
        c2da_mem[c2da_fp + 71] = 0u8
        if ((uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18) != 0x0 || (uint(c2da_mem[c2da_fp + 20]) | uint(c2da_mem[c2da_fp + 21]) << 0x8 | uint(c2da_mem[c2da_fp + 22]) << 0x10 | uint(c2da_mem[c2da_fp + 23]) << 0x18) != 0x0) {
            return 0u
        }
    }
    if (uint_bits_to_float(uint(c2da_mem[c2da_fp + 32]) | uint(c2da_mem[c2da_fp + 33]) << 0x8 | uint(c2da_mem[c2da_fp + 34]) << 0x10 | uint(c2da_mem[c2da_fp + 35]) << 0x18) == 1.0) {
        let c2da_fresh127 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 412]) | uint(c2da_mem[ent_0 + 413]) << 0x8 | uint(c2da_mem[ent_0 + 414]) << 0x10 | uint(c2da_mem[ent_0 + 415]) << 0x18)
        if ((int(c2da_fresh127) & 1024) != 0) {
            let c2da_fresh99 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 0 * 4]) | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[move + 0 * 4]) | uint(c2da_mem[move + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[move + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[move + 0 * 4 + 3]) << 0x18)
            let c2da_fresh100 : uint = float_bits_to_uint(c2da_fresh99)
            c2da_mem[ent_0 + 148 + 0 * 4] = uint8(c2da_fresh100)
            c2da_mem[ent_0 + 148 + 0 * 4 + 1] = uint8(c2da_fresh100 >> 0x8)
            c2da_mem[ent_0 + 148 + 0 * 4 + 2] = uint8(c2da_fresh100 >> 0x10)
            c2da_mem[ent_0 + 148 + 0 * 4 + 3] = uint8(c2da_fresh100 >> 0x18)
            let c2da_fresh101 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 1 * 4]) | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[move + 1 * 4]) | uint(c2da_mem[move + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[move + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[move + 1 * 4 + 3]) << 0x18)
            let c2da_fresh102 : uint = float_bits_to_uint(c2da_fresh101)
            c2da_mem[ent_0 + 148 + 1 * 4] = uint8(c2da_fresh102)
            c2da_mem[ent_0 + 148 + 1 * 4 + 1] = uint8(c2da_fresh102 >> 0x8)
            c2da_mem[ent_0 + 148 + 1 * 4 + 2] = uint8(c2da_fresh102 >> 0x10)
            c2da_mem[ent_0 + 148 + 1 * 4 + 3] = uint8(c2da_fresh102 >> 0x18)
            let c2da_fresh103 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 148 + 2 * 4]) | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_0 + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[move + 2 * 4]) | uint(c2da_mem[move + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[move + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[move + 2 * 4 + 3]) << 0x18)
            let c2da_fresh104 : uint = float_bits_to_uint(c2da_fresh103)
            c2da_mem[ent_0 + 148 + 2 * 4] = uint8(c2da_fresh104)
            c2da_mem[ent_0 + 148 + 2 * 4 + 1] = uint8(c2da_fresh104 >> 0x8)
            c2da_mem[ent_0 + 148 + 2 * 4 + 2] = uint8(c2da_fresh104 >> 0x10)
            c2da_mem[ent_0 + 148 + 2 * 4 + 3] = uint8(c2da_fresh104 >> 0x18)
            if (relink != 0u) {
                SV_LinkEdict(ent_0, 1u)
            }
            let c2da_fresh105 : float = float(int(uint_bits_to_float(uint(c2da_mem[ent_0 + 412]) | uint(c2da_mem[ent_0 + 413]) << 0x8 | uint(c2da_mem[ent_0 + 414]) << 0x10 | uint(c2da_mem[ent_0 + 415]) << 0x18)) & ~512)
            let c2da_fresh106 : uint = float_bits_to_uint(c2da_fresh105)
            c2da_mem[ent_0 + 412] = uint8(c2da_fresh106)
            c2da_mem[ent_0 + 413] = uint8(c2da_fresh106 >> 0x8)
            c2da_mem[ent_0 + 414] = uint8(c2da_fresh106 >> 0x10)
            c2da_mem[ent_0 + 415] = uint8(c2da_fresh106 >> 0x18)
            return 1u
        }
        return 0u
    }
    let c2da_fresh107 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 36 + 0 * 4]) | uint(c2da_mem[c2da_fp + 36 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 36 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 36 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh108 : uint = float_bits_to_uint(c2da_fresh107)
    c2da_mem[ent_0 + 148 + 0 * 4] = uint8(c2da_fresh108)
    c2da_mem[ent_0 + 148 + 0 * 4 + 1] = uint8(c2da_fresh108 >> 0x8)
    c2da_mem[ent_0 + 148 + 0 * 4 + 2] = uint8(c2da_fresh108 >> 0x10)
    c2da_mem[ent_0 + 148 + 0 * 4 + 3] = uint8(c2da_fresh108 >> 0x18)
    let c2da_fresh109 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 36 + 1 * 4]) | uint(c2da_mem[c2da_fp + 36 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 36 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 36 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh110 : uint = float_bits_to_uint(c2da_fresh109)
    c2da_mem[ent_0 + 148 + 1 * 4] = uint8(c2da_fresh110)
    c2da_mem[ent_0 + 148 + 1 * 4 + 1] = uint8(c2da_fresh110 >> 0x8)
    c2da_mem[ent_0 + 148 + 1 * 4 + 2] = uint8(c2da_fresh110 >> 0x10)
    c2da_mem[ent_0 + 148 + 1 * 4 + 3] = uint8(c2da_fresh110 >> 0x18)
    let c2da_fresh111 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 36 + 2 * 4]) | uint(c2da_mem[c2da_fp + 36 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 36 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 36 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh112 : uint = float_bits_to_uint(c2da_fresh111)
    c2da_mem[ent_0 + 148 + 2 * 4] = uint8(c2da_fresh112)
    c2da_mem[ent_0 + 148 + 2 * 4 + 1] = uint8(c2da_fresh112 >> 0x8)
    c2da_mem[ent_0 + 148 + 2 * 4 + 2] = uint8(c2da_fresh112 >> 0x10)
    c2da_mem[ent_0 + 148 + 2 * 4 + 3] = uint8(c2da_fresh112 >> 0x18)
    if (SV_CheckBottom(ent_0) == 0u) {
        if ((int(uint_bits_to_float(uint(c2da_mem[ent_0 + 412]) | uint(c2da_mem[ent_0 + 413]) << 0x8 | uint(c2da_mem[ent_0 + 414]) << 0x10 | uint(c2da_mem[ent_0 + 415]) << 0x18)) & 1024) != 0) {
            if (relink != 0u) {
                SV_LinkEdict(ent_0, 1u)
            }
            return 1u
        }
        let c2da_fresh113 : float = oldorg[0]
        let c2da_fresh114 : uint = float_bits_to_uint(c2da_fresh113)
        c2da_mem[ent_0 + 148 + 0 * 4] = uint8(c2da_fresh114)
        c2da_mem[ent_0 + 148 + 0 * 4 + 1] = uint8(c2da_fresh114 >> 0x8)
        c2da_mem[ent_0 + 148 + 0 * 4 + 2] = uint8(c2da_fresh114 >> 0x10)
        c2da_mem[ent_0 + 148 + 0 * 4 + 3] = uint8(c2da_fresh114 >> 0x18)
        let c2da_fresh115 : float = oldorg[1]
        let c2da_fresh116 : uint = float_bits_to_uint(c2da_fresh115)
        c2da_mem[ent_0 + 148 + 1 * 4] = uint8(c2da_fresh116)
        c2da_mem[ent_0 + 148 + 1 * 4 + 1] = uint8(c2da_fresh116 >> 0x8)
        c2da_mem[ent_0 + 148 + 1 * 4 + 2] = uint8(c2da_fresh116 >> 0x10)
        c2da_mem[ent_0 + 148 + 1 * 4 + 3] = uint8(c2da_fresh116 >> 0x18)
        let c2da_fresh117 : float = oldorg[2]
        let c2da_fresh118 : uint = float_bits_to_uint(c2da_fresh117)
        c2da_mem[ent_0 + 148 + 2 * 4] = uint8(c2da_fresh118)
        c2da_mem[ent_0 + 148 + 2 * 4 + 1] = uint8(c2da_fresh118 >> 0x8)
        c2da_mem[ent_0 + 148 + 2 * 4 + 2] = uint8(c2da_fresh118 >> 0x10)
        c2da_mem[ent_0 + 148 + 2 * 4 + 3] = uint8(c2da_fresh118 >> 0x18)
        return 0u
    }
    let c2da_fresh124 : float = uint_bits_to_float(uint(c2da_mem[ent_0 + 412]) | uint(c2da_mem[ent_0 + 413]) << 0x8 | uint(c2da_mem[ent_0 + 414]) << 0x10 | uint(c2da_mem[ent_0 + 415]) << 0x18)
    if ((int(c2da_fresh124) & 1024) != 0) {
        let c2da_fresh119 : float = float(int(c2da_fresh124) & ~1024)
        let c2da_fresh120 : uint = float_bits_to_uint(c2da_fresh119)
        c2da_mem[ent_0 + 412] = uint8(c2da_fresh120)
        c2da_mem[ent_0 + 413] = uint8(c2da_fresh120 >> 0x8)
        c2da_mem[ent_0 + 414] = uint8(c2da_fresh120 >> 0x10)
        c2da_mem[ent_0 + 415] = uint8(c2da_fresh120 >> 0x18)
    }
    let c2da_fresh121 : int = int(uint(c2da_mem[c2da_fp + 64]) | uint(c2da_mem[c2da_fp + 65]) << 0x8 | uint(c2da_mem[c2da_fp + 66]) << 0x10 | uint(c2da_mem[c2da_fp + 67]) << 0x18) - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    let c2da_fresh122 : uint = uint(c2da_fresh121)
    c2da_mem[ent_0 + 296] = uint8(c2da_fresh122)
    c2da_mem[ent_0 + 297] = uint8(c2da_fresh122 >> 0x8)
    c2da_mem[ent_0 + 298] = uint8(c2da_fresh122 >> 0x10)
    c2da_mem[ent_0 + 299] = uint8(c2da_fresh122 >> 0x18)
    if (relink != 0u) {
        SV_LinkEdict(ent_0, 1u)
    }
    return 1u
}
[sideeffects]
def private SV_StepDirection_c2da_frame(var ent_3 : int; var yaw : float; var dist_1 : float; c2da_fp : int) : uint {
    var oldorigin : vec3_t
    var delta : float
    let c2da_fresh134 : uint = float_bits_to_uint(yaw)
    c2da_mem[ent_3 + 448] = uint8(c2da_fresh134)
    c2da_mem[ent_3 + 449] = uint8(c2da_fresh134 >> 0x8)
    c2da_mem[ent_3 + 450] = uint8(c2da_fresh134 >> 0x10)
    c2da_mem[ent_3 + 451] = uint8(c2da_fresh134 >> 0x18)
    PF_changeyaw()
    yaw = float(double(yaw) * 3.141592653589793lf * 2.0lf / 360.0lf)
    let c2da_fresh135 : float = float(cos(double(yaw)) * double(dist_1))
    let c2da_fresh136 : uint = float_bits_to_uint(c2da_fresh135)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh136)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh136 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh136 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh136 >> 0x18)
    let c2da_fresh137 : float = float(sin(double(yaw)) * double(dist_1))
    let c2da_fresh138 : uint = float_bits_to_uint(c2da_fresh137)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh138)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh138 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh138 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh138 >> 0x18)
    let c2da_fresh139 : float = 0.0
    let c2da_fresh140 : uint = float_bits_to_uint(c2da_fresh139)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh140)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh140 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh140 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh140 >> 0x18)
    oldorigin[0] = uint_bits_to_float(uint(c2da_mem[ent_3 + 148 + 0 * 4]) | uint(c2da_mem[ent_3 + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_3 + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_3 + 148 + 0 * 4 + 3]) << 0x18)
    oldorigin[1] = uint_bits_to_float(uint(c2da_mem[ent_3 + 148 + 1 * 4]) | uint(c2da_mem[ent_3 + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_3 + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_3 + 148 + 1 * 4 + 3]) << 0x18)
    oldorigin[2] = uint_bits_to_float(uint(c2da_mem[ent_3 + 148 + 2 * 4]) | uint(c2da_mem[ent_3 + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_3 + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_3 + 148 + 2 * 4 + 3]) << 0x18)
    if (SV_movestep(ent_3, c2da_fp, 0u) != 0u) {
        delta = uint_bits_to_float(uint(c2da_mem[ent_3 + 184 + 1 * 4]) | uint(c2da_mem[ent_3 + 184 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ent_3 + 184 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ent_3 + 184 + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[ent_3 + 448]) | uint(c2da_mem[ent_3 + 449]) << 0x8 | uint(c2da_mem[ent_3 + 450]) << 0x10 | uint(c2da_mem[ent_3 + 451]) << 0x18)
        if (delta > 45.0 && delta < 315.0) {
            let c2da_fresh141 : float = oldorigin[0]
            let c2da_fresh142 : uint = float_bits_to_uint(c2da_fresh141)
            c2da_mem[ent_3 + 148 + 0 * 4] = uint8(c2da_fresh142)
            c2da_mem[ent_3 + 148 + 0 * 4 + 1] = uint8(c2da_fresh142 >> 0x8)
            c2da_mem[ent_3 + 148 + 0 * 4 + 2] = uint8(c2da_fresh142 >> 0x10)
            c2da_mem[ent_3 + 148 + 0 * 4 + 3] = uint8(c2da_fresh142 >> 0x18)
            let c2da_fresh143 : float = oldorigin[1]
            let c2da_fresh144 : uint = float_bits_to_uint(c2da_fresh143)
            c2da_mem[ent_3 + 148 + 1 * 4] = uint8(c2da_fresh144)
            c2da_mem[ent_3 + 148 + 1 * 4 + 1] = uint8(c2da_fresh144 >> 0x8)
            c2da_mem[ent_3 + 148 + 1 * 4 + 2] = uint8(c2da_fresh144 >> 0x10)
            c2da_mem[ent_3 + 148 + 1 * 4 + 3] = uint8(c2da_fresh144 >> 0x18)
            let c2da_fresh145 : float = oldorigin[2]
            let c2da_fresh146 : uint = float_bits_to_uint(c2da_fresh145)
            c2da_mem[ent_3 + 148 + 2 * 4] = uint8(c2da_fresh146)
            c2da_mem[ent_3 + 148 + 2 * 4 + 1] = uint8(c2da_fresh146 >> 0x8)
            c2da_mem[ent_3 + 148 + 2 * 4 + 2] = uint8(c2da_fresh146 >> 0x10)
            c2da_mem[ent_3 + 148 + 2 * 4 + 3] = uint8(c2da_fresh146 >> 0x18)
        }
        SV_LinkEdict(ent_3, 1u)
        return 1u
    }
    SV_LinkEdict(ent_3, 1u)
    return 0u
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_sv_move() {
    if (length(c2da_fn_table0) < 191) {
        resize(c2da_fn_table0, 191)
    }
    c2da_fn_table0[190] = @@SV_MoveToGoal
}

[init]
def private c2da_lin_relink_init_sv_move() {
    c2da_relink_sv_move()
}
