[export, sideeffects]
def SV_CheckBottom(var ent : edict_s?) : qboolean {
    var mins : vec3_t
    var maxs : vec3_t
    var start : vec3_t
    var stop : vec3_t
    var trace : trace_t = trace_t()
    var x : int
    var y : int
    var mid : float
    var bottom : float
    var c2da_fresh0 : float?
    var c2da_fresh1 : float?
    c2da_fresh0 = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 148ul))
    c2da_fresh1 = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 240ul))
    unsafe(unsafe(addr(mins[0]))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh0))[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh1))[0])
    c2da_fresh0 = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 148ul))
    c2da_fresh1 = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 240ul))
    unsafe(unsafe(addr(mins[0]))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh0))[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh1))[1])
    c2da_fresh0 = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 148ul))
    c2da_fresh1 = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 240ul))
    unsafe(unsafe(addr(mins[0]))[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh0))[2]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh1))[2])
    c2da_fresh0 = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 148ul))
    c2da_fresh1 = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 252ul))
    unsafe(unsafe(addr(maxs[0]))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh0))[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh1))[0])
    c2da_fresh0 = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 148ul))
    c2da_fresh1 = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 252ul))
    unsafe(unsafe(addr(maxs[0]))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh0))[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh1))[1])
    c2da_fresh0 = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 148ul))
    c2da_fresh1 = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 252ul))
    unsafe(unsafe(addr(maxs[0]))[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh0))[2]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh1))[2])
    unsafe(unsafe(addr(start[0]))[2]) = unsafe(unsafe(addr(mins[0]))[2]) - 1.0
    x = 0
    label 0:
    if (x <= 1) {
        goto label 1
    }
    c_yes++
    return unsafe(reinterpret<qboolean>(1u))
    label 1:
    y = 0
    label 2:
    if (y <= 1) {
        goto label 3
    }
    x++
    goto label 0
    label 3:
    unsafe(unsafe(addr(start[0]))[0]) = x != 0 ? unsafe(unsafe(addr(maxs[0]))[0]) : unsafe(unsafe(addr(mins[0]))[0])
    unsafe(unsafe(addr(start[0]))[1]) = y != 0 ? unsafe(unsafe(addr(maxs[0]))[1]) : unsafe(unsafe(addr(mins[0]))[1])
    if (SV_PointContents(unsafe(addr<float?>(start[0]))) != -2) {
        goto label 4
    }
    y++
    goto label 2
    label 4:
    c_no++
    unsafe(unsafe(addr(start[0]))[2]) = float(unsafe(unsafe(addr(mins[0]))[2]))  // nolint:PERF020
    unsafe(unsafe(addr(stop[0]))[0]) = float(double(unsafe(unsafe(addr(mins[0]))[0]) + unsafe(unsafe(addr(maxs[0]))[0])) * 0.5lf)
    unsafe(unsafe(addr(start[0]))[0]) = float(unsafe(unsafe(addr(stop[0]))[0]))  // nolint:PERF020
    unsafe(unsafe(addr(stop[0]))[1]) = float(double(unsafe(unsafe(addr(mins[0]))[1]) + unsafe(unsafe(addr(maxs[0]))[1])) * 0.5lf)
    unsafe(unsafe(addr(start[0]))[1]) = float(unsafe(unsafe(addr(stop[0]))[1]))  // nolint:PERF020
    unsafe(unsafe(addr(stop[0]))[2]) = unsafe(unsafe(addr(start[0]))[2]) - float(2 * 18)
    trace = SV_Move(unsafe(addr<float?>(start[0])), unsafe(addr<float?>(vec3_origin[0])), unsafe(addr<float?>(vec3_origin[0])), unsafe(addr<float?>(stop[0])), 1, ent)
    if (double(trace.fraction) == 1.0lf) {
        goto label 12
    }
    bottom = unsafe(unsafe(addr(trace.endpos[0]))[2])
    mid = bottom
    x = 0
    label 5:
    if (x <= 1) {
        goto label 6
    }
    c_yes++
    return unsafe(reinterpret<qboolean>(1u))
    label 6:
    y = 0
    label 7:
    if (y <= 1) {
        goto label 8
    }
    x++
    goto label 5
    label 8:
    unsafe(unsafe(addr(stop[0]))[0]) = x != 0 ? unsafe(unsafe(addr(maxs[0]))[0]) : unsafe(unsafe(addr(mins[0]))[0])
    unsafe(unsafe(addr(start[0]))[0]) = float(unsafe(unsafe(addr(stop[0]))[0]))  // nolint:PERF020
    unsafe(unsafe(addr(stop[0]))[1]) = y != 0 ? unsafe(unsafe(addr(maxs[0]))[1]) : unsafe(unsafe(addr(mins[0]))[1])
    unsafe(unsafe(addr(start[0]))[1]) = float(unsafe(unsafe(addr(stop[0]))[1]))  // nolint:PERF020
    trace = SV_Move(unsafe(addr<float?>(start[0])), unsafe(addr<float?>(vec3_origin[0])), unsafe(addr<float?>(vec3_origin[0])), unsafe(addr<float?>(stop[0])), 1, ent)
    if (double(trace.fraction) != 1.0lf && unsafe(unsafe(addr(trace.endpos[0]))[2]) > bottom) {
        goto label 11
    }
    label 9:
    if (double(trace.fraction) == 1.0lf || mid - unsafe(unsafe(addr(trace.endpos[0]))[2]) > 18.0) {
        goto label 10
    }
    y++
    goto label 7
    label 10:
    return unsafe(reinterpret<qboolean>(0u))
    label 11:
    bottom = unsafe(unsafe(addr(trace.endpos[0]))[2])
    goto label 9
    label 12:
    return unsafe(reinterpret<qboolean>(0u))
}
var c_yes : int = default<int>

var c_no : int = default<int>

[export, sideeffects]
def SV_movestep(var ent_0 : edict_s?; var move : float?; var relink : qboolean) : qboolean {
    var dz : float
    var oldorg : vec3_t
    var neworg : vec3_t
    var end : vec3_t
    var trace_0 : trace_t = trace_t()
    var enemy : edict_s?
    var c2da_fresh12 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    unsafe(unsafe(addr(oldorg[0]))[0]) = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh12))[0]))  // nolint:PERF020
    var c2da_fresh13 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    unsafe(unsafe(addr(oldorg[0]))[1]) = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh13))[1]))  // nolint:PERF020
    var c2da_fresh14 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    unsafe(unsafe(addr(oldorg[0]))[2]) = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh14))[2]))  // nolint:PERF020
    var c2da_fresh15 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    unsafe(unsafe(addr(neworg[0]))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh15))[0]) + unsafe(move[0])
    var c2da_fresh16 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    unsafe(unsafe(addr(neworg[0]))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh16))[1]) + unsafe(move[1])
    var c2da_fresh17 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    unsafe(unsafe(addr(neworg[0]))[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh17))[2]) + unsafe(move[2])
    if ((int(ent_0.v.flags) & (2 | 1)) != 0) {
        for (i in range(0, 2)) {
            var c2da_fresh18 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
            unsafe(unsafe(addr(neworg[0]))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh18))[0]) + unsafe(move[0])
            var c2da_fresh19 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
            unsafe(unsafe(addr(neworg[0]))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh19))[1]) + unsafe(move[1])
            var c2da_fresh20 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
            unsafe(unsafe(addr(neworg[0]))[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh20))[2]) + unsafe(move[2])
            enemy = unsafe(reinterpret<edict_s?>(unsafe(reinterpret<edict_s?>(unsafe(unsafe(reinterpret<uint8?>(sv.edicts)) + ent_0.v.enemy)))))
            if (i == 0 && enemy != sv.edicts) {
                var c2da_fresh21 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
                var c2da_fresh22 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<edict_s?>(unsafe(unsafe(reinterpret<uint8?>(sv.edicts)) + ent_0.v.enemy))))) + 148ul))
                dz = unsafe(unsafe(reinterpret<float?>(c2da_fresh21))[2]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh22))[2])
                if (dz > 40.0) {
                    unsafe(unsafe(addr(neworg[0]))[2]) -= 8.0
                }
                if (dz < 30.0) {
                    unsafe(unsafe(addr(neworg[0]))[2]) += 8.0
                }
            }
            var c2da_fresh23 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
            var c2da_fresh24 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 240ul))
            var c2da_fresh25 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 252ul))
            trace_0 = SV_Move(unsafe(reinterpret<float?>(c2da_fresh23)), unsafe(reinterpret<float?>(c2da_fresh24)), unsafe(reinterpret<float?>(c2da_fresh25)), unsafe(addr<float?>(neworg[0])), 0, ent_0)
            if (trace_0.fraction == 1.0) {
                if ((int(ent_0.v.flags) & 2) != 0 && SV_PointContents(unsafe(addr<float?>(trace_0.endpos[0]))) == -1) {
                    return unsafe(reinterpret<qboolean>(0u))
                }
                var c2da_fresh26 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh26))[0]) = float(unsafe(unsafe(addr(trace_0.endpos[0]))[0]))  // nolint:PERF020
                var c2da_fresh27 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh27))[1]) = float(unsafe(unsafe(addr(trace_0.endpos[0]))[1]))  // nolint:PERF020
                var c2da_fresh28 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
                unsafe(unsafe(reinterpret<float?>(c2da_fresh28))[2]) = float(unsafe(unsafe(addr(trace_0.endpos[0]))[2]))  // nolint:PERF020
                if (uint(relink) != 0u) {
                    SV_LinkEdict(ent_0, unsafe(reinterpret<qboolean>(1u)))
                }
                return unsafe(reinterpret<qboolean>(1u))
            }
            if (enemy == sv.edicts) {
                break
            }
        }
        return unsafe(reinterpret<qboolean>(0u))
    }
    unsafe(unsafe(addr(neworg[0]))[2]) += 18.0
    unsafe(unsafe(addr(end[0]))[0]) = float(unsafe(unsafe(addr(neworg[0]))[0]))  // nolint:PERF020
    unsafe(unsafe(addr(end[0]))[1]) = float(unsafe(unsafe(addr(neworg[0]))[1]))  // nolint:PERF020
    unsafe(unsafe(addr(end[0]))[2]) = float(unsafe(unsafe(addr(neworg[0]))[2]))  // nolint:PERF020
    unsafe(unsafe(addr(end[0]))[2]) -= float(18 * 2)
    var c2da_fresh29 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 240ul))
    var c2da_fresh30 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 252ul))
    trace_0 = SV_Move(unsafe(addr<float?>(neworg[0])), unsafe(reinterpret<float?>(c2da_fresh29)), unsafe(reinterpret<float?>(c2da_fresh30)), unsafe(addr<float?>(end[0])), 0, ent_0)
    if (uint(trace_0.allsolid) != 0u) {
        return unsafe(reinterpret<qboolean>(0u))
    }
    if (uint(trace_0.startsolid) != 0u) {
        unsafe(unsafe(addr(neworg[0]))[2]) -= 18.0
        var c2da_fresh31 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 240ul))
        var c2da_fresh32 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 252ul))
        trace_0 = SV_Move(unsafe(addr<float?>(neworg[0])), unsafe(reinterpret<float?>(c2da_fresh31)), unsafe(reinterpret<float?>(c2da_fresh32)), unsafe(addr<float?>(end[0])), 0, ent_0)
        if (uint(trace_0.allsolid) != 0x0 || uint(trace_0.startsolid) != 0x0) {
            return unsafe(reinterpret<qboolean>(0u))
        }
    }
    if (trace_0.fraction == 1.0) {
        if ((int(ent_0.v.flags) & 1024) != 0) {
            var c2da_fresh33 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
            var c2da_fresh34 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh33))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh34))[0]) + unsafe(move[0])
            var c2da_fresh35 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
            var c2da_fresh36 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh35))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh36))[1]) + unsafe(move[1])
            var c2da_fresh37 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
            var c2da_fresh38 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh37))[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh38))[2]) + unsafe(move[2])
            if (uint(relink) != 0u) {
                SV_LinkEdict(ent_0, unsafe(reinterpret<qboolean>(1u)))
            }
            ent_0.v.flags = float(int(ent_0.v.flags) & ~512)
            return unsafe(reinterpret<qboolean>(1u))
        }
        return unsafe(reinterpret<qboolean>(0u))
    }
    var c2da_fresh39 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh39))[0]) = float(unsafe(unsafe(addr(trace_0.endpos[0]))[0]))  // nolint:PERF020
    var c2da_fresh40 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh40))[1]) = float(unsafe(unsafe(addr(trace_0.endpos[0]))[1]))  // nolint:PERF020
    var c2da_fresh41 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh41))[2]) = float(unsafe(unsafe(addr(trace_0.endpos[0]))[2]))  // nolint:PERF020
    if (uint(SV_CheckBottom(ent_0)) == 0u) {
        if ((int(ent_0.v.flags) & 1024) != 0) {
            if (uint(relink) != 0u) {
                SV_LinkEdict(ent_0, unsafe(reinterpret<qboolean>(1u)))
            }
            return unsafe(reinterpret<qboolean>(1u))
        }
        var c2da_fresh42 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh42))[0]) = float(unsafe(unsafe(addr(oldorg[0]))[0]))  // nolint:PERF020
        var c2da_fresh43 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh43))[1]) = float(unsafe(unsafe(addr(oldorg[0]))[1]))  // nolint:PERF020
        var c2da_fresh44 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh44))[2]) = float(unsafe(unsafe(addr(oldorg[0]))[2]))  // nolint:PERF020
        return unsafe(reinterpret<qboolean>(0u))
    }
    if ((int(ent_0.v.flags) & 1024) != 0) {
        ent_0.v.flags = float(int(ent_0.v.flags) & ~1024)
    }
    ent_0.v.groundentity = int(unsafe(unsafe(reinterpret<uint8?>(trace_0.ent)) - unsafe(reinterpret<uint8?>(sv.edicts))))
    if (uint(relink) != 0u) {
        SV_LinkEdict(ent_0, unsafe(reinterpret<qboolean>(1u)))
    }
    return unsafe(reinterpret<qboolean>(1u))
}
[export, sideeffects]
def SV_MoveToGoal() {
    var ent_1 : edict_s?
    var goal : edict_s?
    var dist : float
    ent_1 = unsafe(reinterpret<edict_s?>(unsafe(reinterpret<edict_s?>(unsafe(unsafe(reinterpret<uint8?>(sv.edicts)) + int(pr_global_struct.self))))))
    goal = unsafe(reinterpret<edict_s?>(unsafe(reinterpret<edict_s?>(unsafe(unsafe(reinterpret<uint8?>(sv.edicts)) + ent_1.v.goalentity)))))
    dist = unsafe(pr_globals[4])
    if ((int(ent_1.v.flags) & (512 | 1 | 2)) == 0) {
        unsafe(pr_globals[1]) = 0.0
        return
    }
    if (unsafe(reinterpret<edict_s?>(unsafe(unsafe(reinterpret<uint8?>(sv.edicts)) + ent_1.v.enemy))) != sv.edicts && uint(SV_CloseEnough(ent_1, goal, dist)) != 0x0) {
        return
    }
    if ((c2da_std_rand() & 3) == 1 || uint(SV_StepDirection(ent_1, ent_1.v.ideal_yaw, dist)) == 0u) {
        SV_NewChaseDir(ent_1, goal, dist)
    }
    return
}
[export, sideeffects]
def SV_NewChaseDir(var actor : edict_s?; var enemy_0 : edict_s?; var dist_0 : float) {
    var deltax : float
    var deltay : float
    var d : float[3]
    var tdir : float
    var olddir : float
    var turnaround : float
    olddir = anglemod(float(int(actor.v.ideal_yaw / 45.0) * 45))
    turnaround = anglemod(olddir - 180.0)
    var c2da_fresh45 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(enemy_0)) + 148ul))
    var c2da_fresh46 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(actor)) + 148ul))
    deltax = unsafe(unsafe(reinterpret<float?>(c2da_fresh45))[0]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh46))[0])
    var c2da_fresh47 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(enemy_0)) + 148ul))
    var c2da_fresh48 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(actor)) + 148ul))
    deltay = unsafe(unsafe(reinterpret<float?>(c2da_fresh47))[1]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh48))[1])
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
        if (tdir != turnaround && uint(SV_StepDirection(actor, tdir, dist_0)) != 0x0) {
            return
        }
    }
    if ((c2da_std_rand() & 3 & 1) != 0 || c2da_std_abs(int(deltay)) > c2da_std_abs(int(deltax))) {
        tdir = d[1]
        d[1] = float(d[2])  // nolint:PERF020
        d[2] = tdir
    }
    if (d[1] != -1.0 && d[1] != turnaround && uint(SV_StepDirection(actor, d[1], dist_0)) != 0x0) {
        return
    }
    if (d[2] != -1.0 && d[2] != turnaround && uint(SV_StepDirection(actor, d[2], dist_0)) != 0x0) {
        return
    }
    if (olddir != -1.0 && uint(SV_StepDirection(actor, olddir, dist_0)) != 0x0) {
        return
    }
    if ((c2da_std_rand() & 1) != 0) {
        tdir = 0.0
        while (tdir <= 315.0) {
            if (tdir != turnaround && uint(SV_StepDirection(actor, tdir, dist_0)) != 0x0) {
                return
            }
            tdir += 45.0
        }
    } else {
        tdir = 315.0
        while (tdir >= 0.0) {
            if (tdir != turnaround && uint(SV_StepDirection(actor, tdir, dist_0)) != 0x0) {
                return
            }
            tdir -= 45.0
        }
    }
    if (turnaround != -1.0 && uint(SV_StepDirection(actor, turnaround, dist_0)) != 0x0) {
        return
    }
    actor.v.ideal_yaw = olddir
    if (uint(SV_CheckBottom(actor)) == 0u) {
        SV_FixCheckBottom(actor)
    }
    return
}
[export, sideeffects]
def SV_FixCheckBottom(var ent_2 : edict_s?) {
    ent_2.v.flags = float(int(ent_2.v.flags) | 1024)
    return
}
[export, sideeffects]
def SV_StepDirection(var ent_3 : edict_s?; var yaw : float; var dist_1 : float) : qboolean {
    var move_0 : vec3_t
    var oldorigin : vec3_t
    var delta : float
    ent_3.v.ideal_yaw = float(yaw)  // nolint:PERF020
    PF_changeyaw()
    yaw = float(double(yaw) * 3.141592653589793lf * 2.0lf / 360.0lf)
    unsafe(unsafe(addr(move_0[0]))[0]) = float(cos(double(yaw)) * double(dist_1))
    unsafe(unsafe(addr(move_0[0]))[1]) = float(sin(double(yaw)) * double(dist_1))
    unsafe(unsafe(addr(move_0[0]))[2]) = 0.0
    var c2da_fresh49 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_3)) + 148ul))
    unsafe(unsafe(addr(oldorigin[0]))[0]) = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh49))[0]))  // nolint:PERF020
    var c2da_fresh50 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_3)) + 148ul))
    unsafe(unsafe(addr(oldorigin[0]))[1]) = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh50))[1]))  // nolint:PERF020
    var c2da_fresh51 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_3)) + 148ul))
    unsafe(unsafe(addr(oldorigin[0]))[2]) = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh51))[2]))  // nolint:PERF020
    if (uint(SV_movestep(ent_3, unsafe(addr<float?>(move_0[0])), unsafe(reinterpret<qboolean>(0u)))) != 0u) {
        var c2da_fresh52 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_3)) + 184ul))
        delta = unsafe(unsafe(reinterpret<float?>(c2da_fresh52))[1]) - ent_3.v.ideal_yaw
        if (delta > 45.0 && delta < 315.0) {
            var c2da_fresh53 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_3)) + 148ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh53))[0]) = float(unsafe(unsafe(addr(oldorigin[0]))[0]))  // nolint:PERF020
            var c2da_fresh54 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_3)) + 148ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh54))[1]) = float(unsafe(unsafe(addr(oldorigin[0]))[1]))  // nolint:PERF020
            var c2da_fresh55 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_3)) + 148ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh55))[2]) = float(unsafe(unsafe(addr(oldorigin[0]))[2]))  // nolint:PERF020
        }
        SV_LinkEdict(ent_3, unsafe(reinterpret<qboolean>(1u)))
        return unsafe(reinterpret<qboolean>(1u))
    }
    SV_LinkEdict(ent_3, unsafe(reinterpret<qboolean>(1u)))
    return unsafe(reinterpret<qboolean>(0u))
}
[export, sideeffects]
def SV_CloseEnough(var ent_4 : edict_s?; var goal_0 : edict_s?; var dist_2 : float) : qboolean {
    for (i_0 in range(0, 3)) {
        var c2da_fresh56 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(goal_0)) + 112ul))
        var c2da_fresh57 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_4)) + 124ul))
        if (unsafe(unsafe(reinterpret<float?>(c2da_fresh56))[i_0]) > unsafe(unsafe(reinterpret<float?>(c2da_fresh57))[i_0]) + dist_2) {
            return unsafe(reinterpret<qboolean>(0u))
        }
        var c2da_fresh58 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(goal_0)) + 124ul))
        var c2da_fresh59 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_4)) + 112ul))
        if (unsafe(unsafe(reinterpret<float?>(c2da_fresh58))[i_0]) < unsafe(unsafe(reinterpret<float?>(c2da_fresh59))[i_0]) - dist_2) {
            return unsafe(reinterpret<qboolean>(0u))
        }
    }
    return unsafe(reinterpret<qboolean>(1u))
}
[sideeffects]
def private c2da_layout_proofs_48() {
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
    static_assert(typeinfo sizeof(type<globalvars_t>) == 368, "C layout of globalvars_t: sizeof")
    static_assert(typeinfo alignof(type<globalvars_t>) == 4, "C layout of globalvars_t: alignof")
    static_assert(typeinfo offsetof<pad>(type<globalvars_t>) == 0, "C layout of globalvars_t: offsetof pad")
    static_assert(typeinfo offsetof<self>(type<globalvars_t>) == 112, "C layout of globalvars_t: offsetof self")
    static_assert(typeinfo offsetof<other>(type<globalvars_t>) == 116, "C layout of globalvars_t: offsetof other")
    static_assert(typeinfo offsetof<world>(type<globalvars_t>) == 120, "C layout of globalvars_t: offsetof world")
    static_assert(typeinfo offsetof<time>(type<globalvars_t>) == 124, "C layout of globalvars_t: offsetof time")
    static_assert(typeinfo offsetof<frametime>(type<globalvars_t>) == 128, "C layout of globalvars_t: offsetof frametime")
    static_assert(typeinfo offsetof<force_retouch>(type<globalvars_t>) == 132, "C layout of globalvars_t: offsetof force_retouch")
    static_assert(typeinfo offsetof<mapname>(type<globalvars_t>) == 136, "C layout of globalvars_t: offsetof mapname")
    static_assert(typeinfo offsetof<deathmatch>(type<globalvars_t>) == 140, "C layout of globalvars_t: offsetof deathmatch")
    static_assert(typeinfo offsetof<coop>(type<globalvars_t>) == 144, "C layout of globalvars_t: offsetof coop")
    static_assert(typeinfo offsetof<teamplay>(type<globalvars_t>) == 148, "C layout of globalvars_t: offsetof teamplay")
    static_assert(typeinfo offsetof<serverflags>(type<globalvars_t>) == 152, "C layout of globalvars_t: offsetof serverflags")
    static_assert(typeinfo offsetof<total_secrets>(type<globalvars_t>) == 156, "C layout of globalvars_t: offsetof total_secrets")
    static_assert(typeinfo offsetof<total_monsters>(type<globalvars_t>) == 160, "C layout of globalvars_t: offsetof total_monsters")
    static_assert(typeinfo offsetof<found_secrets>(type<globalvars_t>) == 164, "C layout of globalvars_t: offsetof found_secrets")
    static_assert(typeinfo offsetof<killed_monsters>(type<globalvars_t>) == 168, "C layout of globalvars_t: offsetof killed_monsters")
    static_assert(typeinfo offsetof<parm1>(type<globalvars_t>) == 172, "C layout of globalvars_t: offsetof parm1")
    static_assert(typeinfo offsetof<parm2>(type<globalvars_t>) == 176, "C layout of globalvars_t: offsetof parm2")
    static_assert(typeinfo offsetof<parm3>(type<globalvars_t>) == 180, "C layout of globalvars_t: offsetof parm3")
    static_assert(typeinfo offsetof<parm4>(type<globalvars_t>) == 184, "C layout of globalvars_t: offsetof parm4")
    static_assert(typeinfo offsetof<parm5>(type<globalvars_t>) == 188, "C layout of globalvars_t: offsetof parm5")
    static_assert(typeinfo offsetof<parm6>(type<globalvars_t>) == 192, "C layout of globalvars_t: offsetof parm6")
    static_assert(typeinfo offsetof<parm7>(type<globalvars_t>) == 196, "C layout of globalvars_t: offsetof parm7")
    static_assert(typeinfo offsetof<parm8>(type<globalvars_t>) == 200, "C layout of globalvars_t: offsetof parm8")
    static_assert(typeinfo offsetof<parm9>(type<globalvars_t>) == 204, "C layout of globalvars_t: offsetof parm9")
    static_assert(typeinfo offsetof<parm10>(type<globalvars_t>) == 208, "C layout of globalvars_t: offsetof parm10")
    static_assert(typeinfo offsetof<parm11>(type<globalvars_t>) == 212, "C layout of globalvars_t: offsetof parm11")
    static_assert(typeinfo offsetof<parm12>(type<globalvars_t>) == 216, "C layout of globalvars_t: offsetof parm12")
    static_assert(typeinfo offsetof<parm13>(type<globalvars_t>) == 220, "C layout of globalvars_t: offsetof parm13")
    static_assert(typeinfo offsetof<parm14>(type<globalvars_t>) == 224, "C layout of globalvars_t: offsetof parm14")
    static_assert(typeinfo offsetof<parm15>(type<globalvars_t>) == 228, "C layout of globalvars_t: offsetof parm15")
    static_assert(typeinfo offsetof<parm16>(type<globalvars_t>) == 232, "C layout of globalvars_t: offsetof parm16")
    static_assert(typeinfo offsetof<v_forward>(type<globalvars_t>) == 236, "C layout of globalvars_t: offsetof v_forward")
    static_assert(typeinfo offsetof<v_up>(type<globalvars_t>) == 248, "C layout of globalvars_t: offsetof v_up")
    static_assert(typeinfo offsetof<v_right>(type<globalvars_t>) == 260, "C layout of globalvars_t: offsetof v_right")
    static_assert(typeinfo offsetof<trace_allsolid>(type<globalvars_t>) == 272, "C layout of globalvars_t: offsetof trace_allsolid")
    static_assert(typeinfo offsetof<trace_startsolid>(type<globalvars_t>) == 276, "C layout of globalvars_t: offsetof trace_startsolid")
    static_assert(typeinfo offsetof<trace_fraction>(type<globalvars_t>) == 280, "C layout of globalvars_t: offsetof trace_fraction")
    static_assert(typeinfo offsetof<trace_endpos>(type<globalvars_t>) == 284, "C layout of globalvars_t: offsetof trace_endpos")
    static_assert(typeinfo offsetof<trace_plane_normal>(type<globalvars_t>) == 296, "C layout of globalvars_t: offsetof trace_plane_normal")
    static_assert(typeinfo offsetof<trace_plane_dist>(type<globalvars_t>) == 308, "C layout of globalvars_t: offsetof trace_plane_dist")
    static_assert(typeinfo offsetof<trace_ent>(type<globalvars_t>) == 312, "C layout of globalvars_t: offsetof trace_ent")
    static_assert(typeinfo offsetof<trace_inopen>(type<globalvars_t>) == 316, "C layout of globalvars_t: offsetof trace_inopen")
    static_assert(typeinfo offsetof<trace_inwater>(type<globalvars_t>) == 320, "C layout of globalvars_t: offsetof trace_inwater")
    static_assert(typeinfo offsetof<msg_entity>(type<globalvars_t>) == 324, "C layout of globalvars_t: offsetof msg_entity")
    static_assert(typeinfo offsetof<main>(type<globalvars_t>) == 328, "C layout of globalvars_t: offsetof main")
    static_assert(typeinfo offsetof<StartFrame>(type<globalvars_t>) == 332, "C layout of globalvars_t: offsetof StartFrame")
    static_assert(typeinfo offsetof<PlayerPreThink>(type<globalvars_t>) == 336, "C layout of globalvars_t: offsetof PlayerPreThink")
    static_assert(typeinfo offsetof<PlayerPostThink>(type<globalvars_t>) == 340, "C layout of globalvars_t: offsetof PlayerPostThink")
    static_assert(typeinfo offsetof<ClientKill>(type<globalvars_t>) == 344, "C layout of globalvars_t: offsetof ClientKill")
    static_assert(typeinfo offsetof<ClientConnect>(type<globalvars_t>) == 348, "C layout of globalvars_t: offsetof ClientConnect")
    static_assert(typeinfo offsetof<PutClientInServer>(type<globalvars_t>) == 352, "C layout of globalvars_t: offsetof PutClientInServer")
    static_assert(typeinfo offsetof<ClientDisconnect>(type<globalvars_t>) == 356, "C layout of globalvars_t: offsetof ClientDisconnect")
    static_assert(typeinfo offsetof<SetNewParms>(type<globalvars_t>) == 360, "C layout of globalvars_t: offsetof SetNewParms")
    static_assert(typeinfo offsetof<SetChangeParms>(type<globalvars_t>) == 364, "C layout of globalvars_t: offsetof SetChangeParms")
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
    static_assert(typeinfo sizeof(type<trace_t>) == 56, "C layout of trace_t: sizeof")
    static_assert(typeinfo alignof(type<trace_t>) == 8, "C layout of trace_t: alignof")
    static_assert(typeinfo offsetof<allsolid>(type<trace_t>) == 0, "C layout of trace_t: offsetof allsolid")
    static_assert(typeinfo offsetof<startsolid>(type<trace_t>) == 4, "C layout of trace_t: offsetof startsolid")
    static_assert(typeinfo offsetof<inopen>(type<trace_t>) == 8, "C layout of trace_t: offsetof inopen")
    static_assert(typeinfo offsetof<inwater>(type<trace_t>) == 12, "C layout of trace_t: offsetof inwater")
    static_assert(typeinfo offsetof<fraction>(type<trace_t>) == 16, "C layout of trace_t: offsetof fraction")
    static_assert(typeinfo offsetof<endpos>(type<trace_t>) == 20, "C layout of trace_t: offsetof endpos")
    static_assert(typeinfo offsetof<plane>(type<trace_t>) == 32, "C layout of trace_t: offsetof plane")
    static_assert(typeinfo offsetof<ent>(type<trace_t>) == 48, "C layout of trace_t: offsetof ent")
    static_assert(typeinfo sizeof(type<plane_t>) == 16, "C layout of plane_t: sizeof")
    static_assert(typeinfo alignof(type<plane_t>) == 4, "C layout of plane_t: alignof")
    static_assert(typeinfo offsetof<normal>(type<plane_t>) == 0, "C layout of plane_t: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<plane_t>) == 12, "C layout of plane_t: offsetof dist")
}
