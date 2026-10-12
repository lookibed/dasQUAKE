var private c2da_str_world_0 : array<int8> = [int8(83), int8(86), int8(95), int8(72), int8(117), int8(108), int8(108), int8(80), int8(111), int8(105), int8(110), int8(116), int8(67), int8(111), int8(110), int8(116), int8(101), int8(110), int8(116), int8(115), int8(58), int8(32), int8(98), int8(97), int8(100), int8(32), int8(110), int8(111), int8(100), int8(101), int8(32), int8(110), int8(117), int8(109), int8(98), int8(101), int8(114), int8(0)]

var private c2da_str_world_1 : array<int8> = [int8(84), int8(114), int8(105), int8(103), int8(103), int8(101), int8(114), int8(32), int8(105), int8(110), int8(32), int8(99), int8(108), int8(105), int8(112), int8(112), int8(105), int8(110), int8(103), int8(32), int8(108), int8(105), int8(115), int8(116), int8(0)]

var private c2da_str_world_2 : array<int8> = [int8(83), int8(86), int8(95), int8(82), int8(101), int8(99), int8(117), int8(114), int8(115), int8(105), int8(118), int8(101), int8(72), int8(117), int8(108), int8(108), int8(67), int8(104), int8(101), int8(99), int8(107), int8(58), int8(32), int8(98), int8(97), int8(100), int8(32), int8(110), int8(111), int8(100), int8(101), int8(32), int8(110), int8(117), int8(109), int8(98), int8(101), int8(114), int8(0)]

var private c2da_str_world_3 : array<int8> = [int8(98), int8(97), int8(99), int8(107), int8(117), int8(112), int8(32), int8(112), int8(97), int8(115), int8(116), int8(32), int8(48), int8(10), int8(0)]

var private c2da_str_world_4 : array<int8> = [int8(83), int8(79), int8(76), int8(73), int8(68), int8(95), int8(66), int8(83), int8(80), int8(32), int8(119), int8(105), int8(116), int8(104), int8(111), int8(117), int8(116), int8(32), int8(77), int8(79), int8(86), int8(69), int8(84), int8(89), int8(80), int8(69), int8(95), int8(80), int8(85), int8(83), int8(72), int8(0)]

var private c2da_str_world_5 : array<int8> = [int8(77), int8(79), int8(86), int8(69), int8(84), int8(89), int8(80), int8(69), int8(95), int8(80), int8(85), int8(83), int8(72), int8(32), int8(119), int8(105), int8(116), int8(104), int8(32), int8(97), int8(32), int8(110), int8(111), int8(110), int8(32), int8(98), int8(115), int8(112), int8(32), int8(109), int8(111), int8(100), int8(101), int8(108), int8(0)]

[export, sideeffects]
def SV_ClearWorld() {
    SV_InitBoxHull()
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(sv_areanodes[0])))), 0u8, 1792ul)))
    sv_numareanodes = 0
    var c2da_fresh0 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(sv.worldmodel)) + 84ul))
    var c2da_fresh1 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(sv.worldmodel)) + 96ul))
    SV_CreateAreaNode(0, unsafe(reinterpret<float?>(c2da_fresh0)), unsafe(reinterpret<float?>(c2da_fresh1)))
    return
}
[export, sideeffects]
def SV_CreateAreaNode(var depth : int; var mins : float?; var maxs : float?) : areanode_s? {
    var anode : areanode_s?
    var size : vec3_t
    var mins1 : vec3_t
    var maxs1 : vec3_t
    var mins2 : vec3_t
    var maxs2 : vec3_t
    anode = unsafe(addr<areanode_s?>(unsafe(unsafe(addr(sv_areanodes[0]))[sv_numareanodes])))
    sv_numareanodes++
    var c2da_fresh2 : link_s? = unsafe(reinterpret<link_s?>(unsafe(reinterpret<uint64>(anode)) + 24ul))
    ClearLink(unsafe(reinterpret<link_s?>(c2da_fresh2)))
    var c2da_fresh3 : link_s? = unsafe(reinterpret<link_s?>(unsafe(reinterpret<uint64>(anode)) + 40ul))
    ClearLink(unsafe(reinterpret<link_s?>(c2da_fresh3)))
    if (depth == 4) {
        anode.axis = -1
        var c2da_fresh4 : areanode_s?? = unsafe(reinterpret<areanode_s??>(unsafe(reinterpret<uint64>(anode)) + 8ul))
        var c2da_fresh5 : areanode_s?? = unsafe(reinterpret<areanode_s??>(unsafe(reinterpret<uint64>(anode)) + 8ul))
        unsafe(unsafe(reinterpret<areanode_s??>(c2da_fresh5))[1]) = null
        unsafe(unsafe(reinterpret<areanode_s??>(c2da_fresh4))[0]) = unsafe(reinterpret<areanode_s?>(unsafe(unsafe(reinterpret<areanode_s??>(c2da_fresh5))[1])))
        return unsafe(reinterpret<areanode_s?>(anode))
    }
    unsafe(unsafe(addr(size[0]))[0]) = unsafe(maxs[0]) - unsafe(mins[0])
    unsafe(unsafe(addr(size[0]))[1]) = unsafe(maxs[1]) - unsafe(mins[1])
    unsafe(unsafe(addr(size[0]))[2]) = unsafe(maxs[2]) - unsafe(mins[2])
    if (unsafe(unsafe(addr(size[0]))[0]) > unsafe(unsafe(addr(size[0]))[1])) {
        anode.axis = 0
    } else {
        anode.axis = 1
    }
    anode.dist = float(0.5lf * double(unsafe(maxs[anode.axis]) + unsafe(mins[anode.axis])))
    unsafe(unsafe(addr(mins1[0]))[0]) = float(unsafe(mins[0]))  // nolint:PERF020
    unsafe(unsafe(addr(mins1[0]))[1]) = float(unsafe(mins[1]))  // nolint:PERF020
    unsafe(unsafe(addr(mins1[0]))[2]) = float(unsafe(mins[2]))  // nolint:PERF020
    unsafe(unsafe(addr(mins2[0]))[0]) = float(unsafe(mins[0]))  // nolint:PERF020
    unsafe(unsafe(addr(mins2[0]))[1]) = float(unsafe(mins[1]))  // nolint:PERF020
    unsafe(unsafe(addr(mins2[0]))[2]) = float(unsafe(mins[2]))  // nolint:PERF020
    unsafe(unsafe(addr(maxs1[0]))[0]) = float(unsafe(maxs[0]))  // nolint:PERF020
    unsafe(unsafe(addr(maxs1[0]))[1]) = float(unsafe(maxs[1]))  // nolint:PERF020
    unsafe(unsafe(addr(maxs1[0]))[2]) = float(unsafe(maxs[2]))  // nolint:PERF020
    unsafe(unsafe(addr(maxs2[0]))[0]) = float(unsafe(maxs[0]))  // nolint:PERF020
    unsafe(unsafe(addr(maxs2[0]))[1]) = float(unsafe(maxs[1]))  // nolint:PERF020
    unsafe(unsafe(addr(maxs2[0]))[2]) = float(unsafe(maxs[2]))  // nolint:PERF020
    unsafe(unsafe(addr(mins2[0]))[anode.axis]) = float(anode.dist)  // nolint:PERF020
    unsafe(unsafe(addr(maxs1[0]))[anode.axis]) = float(unsafe(unsafe(addr(mins2[0]))[anode.axis]))  // nolint:PERF020
    var c2da_fresh6 : areanode_s?? = unsafe(reinterpret<areanode_s??>(unsafe(reinterpret<uint64>(anode)) + 8ul))
    unsafe(unsafe(reinterpret<areanode_s??>(c2da_fresh6))[0]) = unsafe(reinterpret<areanode_s?>(unsafe(reinterpret<areanode_s?>(SV_CreateAreaNode(depth + 1, unsafe(addr<float?>(mins2[0])), unsafe(addr<float?>(maxs2[0])))))))
    var c2da_fresh7 : areanode_s?? = unsafe(reinterpret<areanode_s??>(unsafe(reinterpret<uint64>(anode)) + 8ul))
    unsafe(unsafe(reinterpret<areanode_s??>(c2da_fresh7))[1]) = unsafe(reinterpret<areanode_s?>(unsafe(reinterpret<areanode_s?>(SV_CreateAreaNode(depth + 1, unsafe(addr<float?>(mins1[0])), unsafe(addr<float?>(maxs1[0])))))))
    return unsafe(reinterpret<areanode_s?>(anode))
}
var private sv_numareanodes : int = default<int>

var private sv_areanodes : areanode_s[32]

[export, sideeffects]
def SV_InitBoxHull() {
    var side : int
    box_hull.clipnodes = unsafe(addr<dclipnode_t?>(box_clipnodes[0]))
    box_hull.planes = unsafe(addr<mplane_s?>(box_planes[0]))
    box_hull.firstclipnode = 0
    box_hull.lastclipnode = 5
    for (i in range(0, 6)) {
        box_clipnodes[i].planenum = i
        side = i & 1
        unsafe(unsafe(addr(box_clipnodes[i].children[0]))[side]) = int16(-1)
        if (i != 5) {
            unsafe(unsafe(addr(box_clipnodes[i].children[0]))[side ^ 1]) = int16(i + 1)
        } else {
            unsafe(unsafe(addr(box_clipnodes[i].children[0]))[side ^ 1]) = int16(-2)
        }
        box_planes[i].type_0 = uint8(i >> 1)
        unsafe(unsafe(addr(box_planes[i].normal[0]))[i >> 1]) = 1.0
    }
    return
}
var private box_planes : mplane_s[6]

var private box_clipnodes : dclipnode_t[6]

var private box_hull : hull_t = default<hull_t>

[export, sideeffects]
def SV_UnlinkEdict(var ent : edict_s?) {
    if (ent.area.prev == null) {
        return
    }
    var c2da_fresh8 : link_s? = unsafe(reinterpret<link_s?>(unsafe(reinterpret<uint64>(ent)) + 8ul))
    RemoveLink(unsafe(reinterpret<link_s?>(c2da_fresh8)))
    var c2da_fresh9 : link_s? = null
    ent.area.next = c2da_fresh9
    ent.area.prev = c2da_fresh9
    return
}
[export, sideeffects]
def SV_LinkEdict(var ent_0 : edict_s?; var touch_triggers : qboolean) {
    var node : areanode_s?
    if (ent_0.area.prev != null) {
        SV_UnlinkEdict(ent_0)
    }
    if (ent_0 == sv.edicts) {
        return
    }
    if (uint(ent_0.free) != 0u) {
        return
    }
    var c2da_fresh10 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 112ul))
    var c2da_fresh11 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    var c2da_fresh12 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 240ul))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh10))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh11))[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh12))[0])
    var c2da_fresh13 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 112ul))
    var c2da_fresh14 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    var c2da_fresh15 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 240ul))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh13))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh14))[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh15))[1])
    var c2da_fresh16 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 112ul))
    var c2da_fresh17 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    var c2da_fresh18 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 240ul))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh16))[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh17))[2]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh18))[2])
    var c2da_fresh19 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 124ul))
    var c2da_fresh20 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    var c2da_fresh21 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 252ul))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh19))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh20))[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh21))[0])
    var c2da_fresh22 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 124ul))
    var c2da_fresh23 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    var c2da_fresh24 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 252ul))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh22))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh23))[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh24))[1])
    var c2da_fresh25 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 124ul))
    var c2da_fresh26 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 148ul))
    var c2da_fresh27 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 252ul))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh25))[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh26))[2]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh27))[2])
    if ((int(ent_0.v.flags) & 256) != 0) {
        var c2da_fresh28 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 112ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh28))[0]) -= 15.0
        var c2da_fresh29 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 112ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh29))[1]) -= 15.0
        var c2da_fresh30 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 124ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh30))[0]) += 15.0
        var c2da_fresh31 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 124ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh31))[1]) += 15.0
    } else {
        var c2da_fresh32 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 112ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh32))[0]) -= 1.0
        var c2da_fresh33 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 112ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh33))[1]) -= 1.0
        var c2da_fresh34 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 112ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh34))[2]) -= 1.0
        var c2da_fresh35 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 124ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh35))[0]) += 1.0
        var c2da_fresh36 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 124ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh36))[1]) += 1.0
        var c2da_fresh37 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 124ul))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh37))[2]) += 1.0
    }
    ent_0.num_leafs = 0
    if (ent_0.v.modelindex != 0.0) {
        SV_FindTouchedLeafs(ent_0, sv.worldmodel.nodes)
    }
    if (ent_0.v.solid == 0.0) {
        return
    }
    node = unsafe(addr<areanode_s?>(sv_areanodes[0]))
    while (true) {
        if (node.axis == -1) {
            break
        }
        var c2da_fresh38 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 112ul))
        if (unsafe(unsafe(reinterpret<float?>(c2da_fresh38))[node.axis]) > node.dist) {
            var c2da_fresh39 : areanode_s?? = unsafe(reinterpret<areanode_s??>(unsafe(reinterpret<uint64>(node)) + 8ul))
            node = unsafe(reinterpret<areanode_s?>(unsafe(unsafe(reinterpret<areanode_s??>(c2da_fresh39))[0])))
        } else {
            var c2da_fresh40 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_0)) + 124ul))
            if (unsafe(unsafe(reinterpret<float?>(c2da_fresh40))[node.axis]) < node.dist) {
                var c2da_fresh41 : areanode_s?? = unsafe(reinterpret<areanode_s??>(unsafe(reinterpret<uint64>(node)) + 8ul))
                node = unsafe(reinterpret<areanode_s?>(unsafe(unsafe(reinterpret<areanode_s??>(c2da_fresh41))[1])))
            } else {
                break
            }
        }
    }
    if (ent_0.v.solid == 1.0) {
        var c2da_fresh42 : link_s? = unsafe(reinterpret<link_s?>(unsafe(reinterpret<uint64>(ent_0)) + 8ul))
        var c2da_fresh43 : link_s? = unsafe(reinterpret<link_s?>(unsafe(reinterpret<uint64>(node)) + 24ul))
        InsertLinkBefore(unsafe(reinterpret<link_s?>(c2da_fresh42)), unsafe(reinterpret<link_s?>(c2da_fresh43)))
    } else {
        var c2da_fresh44 : link_s? = unsafe(reinterpret<link_s?>(unsafe(reinterpret<uint64>(ent_0)) + 8ul))
        var c2da_fresh45 : link_s? = unsafe(reinterpret<link_s?>(unsafe(reinterpret<uint64>(node)) + 40ul))
        InsertLinkBefore(unsafe(reinterpret<link_s?>(c2da_fresh44)), unsafe(reinterpret<link_s?>(c2da_fresh45)))
    }
    if (uint(touch_triggers) != 0u) {
        SV_TouchLinks(ent_0, unsafe(addr<areanode_s?>(sv_areanodes[0])))
    }
    return
}
[export, sideeffects]
def SV_TouchLinks(var ent_1 : edict_s?; var node_0 : areanode_s?) {
    var l : link_s?
    var next_0 : link_s?
    var touch : edict_s?
    var old_self : int
    var old_other : int
    l = unsafe(reinterpret<link_s?>(node_0.trigger_edicts.next))
    while (true) {
        var c2da_fresh46 : link_s? = unsafe(reinterpret<link_s?>(unsafe(reinterpret<uint64>(node_0)) + 24ul))
        if (l == c2da_fresh46) {
            break
        }
        next_0 = unsafe(reinterpret<link_s?>(l.next))
        var c2da_fresh47 : link_s? = unsafe(reinterpret<link_s?>(unsafe(reinterpret<uint64>(null)) + 8ul))
        touch = unsafe(reinterpret<edict_s?>(unsafe(reinterpret<edict_s?>(unsafe(unsafe(reinterpret<uint8?>(l)) + -int64(unsafe(reinterpret<uint64>(c2da_fresh47))))))))
        if (touch == ent_1) {
            l = unsafe(reinterpret<link_s?>(next_0))
            continue
        }
        if (touch.v.touch == 0 || touch.v.solid != 1.0) {
            l = unsafe(reinterpret<link_s?>(next_0))
            continue
        }
        var c2da_fresh48 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_1)) + 112ul))
        var c2da_fresh49 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(touch)) + 124ul))
        var c2da_fresh52 : int = 1
        if (!(unsafe(unsafe(reinterpret<float?>(c2da_fresh48))[0]) > unsafe(unsafe(reinterpret<float?>(c2da_fresh49))[0]))) {
            var c2da_fresh50 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_1)) + 112ul))
            var c2da_fresh51 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(touch)) + 124ul))
            if (!(unsafe(unsafe(reinterpret<float?>(c2da_fresh50))[1]) > unsafe(unsafe(reinterpret<float?>(c2da_fresh51))[1]))) {
                c2da_fresh52 = 0
            }
        }
        var c2da_fresh55 : int = 1
        if (!(c2da_fresh52 != 0)) {
            var c2da_fresh53 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_1)) + 112ul))
            var c2da_fresh54 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(touch)) + 124ul))
            if (!(unsafe(unsafe(reinterpret<float?>(c2da_fresh53))[2]) > unsafe(unsafe(reinterpret<float?>(c2da_fresh54))[2]))) {
                c2da_fresh55 = 0
            }
        }
        var c2da_fresh58 : int = 1
        if (!(c2da_fresh55 != 0)) {
            var c2da_fresh56 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_1)) + 124ul))
            var c2da_fresh57 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(touch)) + 112ul))
            if (!(unsafe(unsafe(reinterpret<float?>(c2da_fresh56))[0]) < unsafe(unsafe(reinterpret<float?>(c2da_fresh57))[0]))) {
                c2da_fresh58 = 0
            }
        }
        var c2da_fresh61 : int = 1
        if (!(c2da_fresh58 != 0)) {
            var c2da_fresh59 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_1)) + 124ul))
            var c2da_fresh60 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(touch)) + 112ul))
            if (!(unsafe(unsafe(reinterpret<float?>(c2da_fresh59))[1]) < unsafe(unsafe(reinterpret<float?>(c2da_fresh60))[1]))) {
                c2da_fresh61 = 0
            }
        }
        var c2da_fresh64 : int = 1
        if (!(c2da_fresh61 != 0)) {
            var c2da_fresh62 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_1)) + 124ul))
            var c2da_fresh63 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(touch)) + 112ul))
            if (!(unsafe(unsafe(reinterpret<float?>(c2da_fresh62))[2]) < unsafe(unsafe(reinterpret<float?>(c2da_fresh63))[2]))) {
                c2da_fresh64 = 0
            }
        }
        if (c2da_fresh64 != 0) {
            l = unsafe(reinterpret<link_s?>(next_0))
            continue
        }
        old_self = pr_global_struct.self
        old_other = pr_global_struct.other
        pr_global_struct.self = int(unsafe(unsafe(reinterpret<uint8?>(touch)) - unsafe(reinterpret<uint8?>(sv.edicts))))
        pr_global_struct.other = int(unsafe(unsafe(reinterpret<uint8?>(ent_1)) - unsafe(reinterpret<uint8?>(sv.edicts))))
        pr_global_struct.time = float(sv.time)
        PR_ExecuteProgram(touch.v.touch)
        pr_global_struct.self = old_self
        pr_global_struct.other = old_other
        l = unsafe(reinterpret<link_s?>(next_0))
    }
    if (node_0.axis == -1) {
        return
    }
    var c2da_fresh65 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_1)) + 124ul))
    if (unsafe(unsafe(reinterpret<float?>(c2da_fresh65))[node_0.axis]) > node_0.dist) {
        var c2da_fresh66 : areanode_s?? = unsafe(reinterpret<areanode_s??>(unsafe(reinterpret<uint64>(node_0)) + 8ul))
        SV_TouchLinks(ent_1, unsafe(reinterpret<areanode_s?>(unsafe(unsafe(reinterpret<areanode_s??>(c2da_fresh66))[0]))))
    }
    var c2da_fresh67 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_1)) + 112ul))
    if (unsafe(unsafe(reinterpret<float?>(c2da_fresh67))[node_0.axis]) < node_0.dist) {
        var c2da_fresh68 : areanode_s?? = unsafe(reinterpret<areanode_s??>(unsafe(reinterpret<uint64>(node_0)) + 8ul))
        SV_TouchLinks(ent_1, unsafe(reinterpret<areanode_s?>(unsafe(unsafe(reinterpret<areanode_s??>(c2da_fresh68))[1]))))
    }
    return
}
[export, sideeffects]
def SV_FindTouchedLeafs(var ent_2 : edict_s?; var node_1 : mnode_s?) {
    var splitplane : mplane_s?
    var sides : int
    if (node_1.contents == -2) {
        return
    }
    if (node_1.contents < 0) {
        if (ent_2.num_leafs == 16) {
            return
        }
        var c2da_fresh69 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ent_2)) + 28ul))
        unsafe(unsafe(reinterpret<int16?>(c2da_fresh69))[ent_2.num_leafs]) = int16(int(unsafe(unsafe(reinterpret<mleaf_s?>(unsafe(reinterpret<mleaf_s?>(node_1)))) - sv.worldmodel.leafs) - 1l))
        let c2da_postinc : int = ent_2.num_leafs
        ent_2.num_leafs = c2da_postinc + 1
        return
    }
    splitplane = unsafe(reinterpret<mplane_s?>(node_1.plane))
    var c2da_fresh75 : int = 0
    if (int(splitplane.type_0) < 3) {
        var c2da_fresh70 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_2)) + 112ul))
        var c2da_fresh72 : int = 0
        if (splitplane.dist <= unsafe(unsafe(reinterpret<float?>(c2da_fresh70))[int(splitplane.type_0)])) {
            c2da_fresh72 = 1
        } else {
            var c2da_fresh71 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_2)) + 124ul))
            c2da_fresh72 = splitplane.dist >= unsafe(unsafe(reinterpret<float?>(c2da_fresh71))[int(splitplane.type_0)]) ? 2 : 3
        }
        c2da_fresh75 = c2da_fresh72
    } else {
        var c2da_fresh73 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_2)) + 112ul))
        var c2da_fresh74 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_2)) + 124ul))
        c2da_fresh75 = BoxOnPlaneSide(unsafe(reinterpret<float?>(c2da_fresh73)), unsafe(reinterpret<float?>(c2da_fresh74)), splitplane)
    }
    sides = c2da_fresh75
    if ((sides & 1) != 0) {
        var c2da_fresh76 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node_1)) + 40ul))
        SV_FindTouchedLeafs(ent_2, unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh76))[0]))))
    }
    if ((sides & 2) != 0) {
        var c2da_fresh77 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node_1)) + 40ul))
        SV_FindTouchedLeafs(ent_2, unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh77))[1]))))
    }
    return
}
[export, sideeffects]
def SV_PointContents(var p : float?) : int {
    var cont : int
    var c2da_fresh78 : hull_t? = unsafe(reinterpret<hull_t?>(unsafe(reinterpret<uint64>(sv.worldmodel)) + 296ul))
    cont = SV_HullPointContents(unsafe(addr<hull_t?>(unsafe(unsafe(reinterpret<hull_t?>(c2da_fresh78))[0]))), 0, p)
    if (cont <= -9 && cont >= -14) {
        cont = -3
    }
    return cont
}
[export, sideeffects]
def SV_HullPointContents(var hull : hull_t?; var num : int; var p_0 : float?) : int {
    var d : float
    var node_2 : dclipnode_t?
    var plane : mplane_s?
    while (num >= 0) {
        if (num < hull.firstclipnode || num > hull.lastclipnode) {
            Sys_Error(unsafe(addr<int8?>(c2da_str_world_0[0])), [])
        }
        node_2 = unsafe(reinterpret<dclipnode_t?>(unsafe(hull.clipnodes + num)))
        plane = unsafe(reinterpret<mplane_s?>(unsafe(hull.planes + node_2.planenum)))
        if (int(plane.type_0) < 3) {
            d = unsafe(p_0[int(plane.type_0)]) - plane.dist
        } else {
            var c2da_fresh79 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane))))
            var c2da_fresh80 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane))))
            var c2da_fresh81 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane))))
            d = unsafe(unsafe(reinterpret<float?>(c2da_fresh79))[0]) * unsafe(p_0[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh80))[1]) * unsafe(p_0[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh81))[2]) * unsafe(p_0[2]) - plane.dist
        }
        if (d < 0.0) {
            var c2da_fresh82 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(node_2)) + 4ul))
            num = int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh82))[1]))
        } else {
            var c2da_fresh83 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(node_2)) + 4ul))
            num = int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh83))[0]))
        }
    }
    return num
}
[export, sideeffects]
def SV_TruePointContents(var p_1 : float?) : int {
    var c2da_fresh84 : hull_t? = unsafe(reinterpret<hull_t?>(unsafe(reinterpret<uint64>(sv.worldmodel)) + 296ul))
    return SV_HullPointContents(unsafe(addr<hull_t?>(unsafe(unsafe(reinterpret<hull_t?>(c2da_fresh84))[0]))), 0, p_1)
}
[export, sideeffects]
def SV_TestEntityPosition(var ent_3 : edict_s?) : edict_s? {
    var trace : trace_t = trace_t()
    var c2da_fresh85 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_3)) + 148ul))
    var c2da_fresh86 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_3)) + 240ul))
    var c2da_fresh87 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_3)) + 252ul))
    var c2da_fresh88 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_3)) + 148ul))
    trace = SV_Move(unsafe(reinterpret<float?>(c2da_fresh85)), unsafe(reinterpret<float?>(c2da_fresh86)), unsafe(reinterpret<float?>(c2da_fresh87)), unsafe(reinterpret<float?>(c2da_fresh88)), 0, ent_3)
    if (uint(trace.startsolid) != 0u) {
        return unsafe(reinterpret<edict_s?>(sv.edicts))
    }
    return unsafe(reinterpret<edict_s?>(null))
}
[export, sideeffects]
def SV_Move(var start : float?; var mins_0 : float?; var maxs_0 : float?; var end : float?; var type_0 : int; var passedict : edict_s?) : trace_t {
    var clip : moveclip_t = moveclip_t()
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(clip)))), 0u8, 152ul)))
    clip.trace = SV_ClipMoveToEntity(sv.edicts, start, mins_0, maxs_0, end)
    clip.start = unsafe(reinterpret<float?>(start))
    clip.end = unsafe(reinterpret<float?>(end))
    clip.mins = unsafe(reinterpret<float?>(mins_0))
    clip.maxs = unsafe(reinterpret<float?>(maxs_0))
    clip.type_0 = type_0
    clip.passedict = unsafe(reinterpret<edict_s?>(passedict))
    if (type_0 == 2) {
        for (i_0 in range(0, 3)) {
            unsafe(unsafe(addr(clip.mins2[0]))[i_0]) = -15.0
            unsafe(unsafe(addr(clip.maxs2[0]))[i_0]) = 15.0
        }
    } else {
        unsafe(unsafe(addr(clip.mins2[0]))[0]) = float(unsafe(mins_0[0]))  // nolint:PERF020
        unsafe(unsafe(addr(clip.mins2[0]))[1]) = float(unsafe(mins_0[1]))  // nolint:PERF020
        unsafe(unsafe(addr(clip.mins2[0]))[2]) = float(unsafe(mins_0[2]))  // nolint:PERF020
        unsafe(unsafe(addr(clip.maxs2[0]))[0]) = float(unsafe(maxs_0[0]))  // nolint:PERF020
        unsafe(unsafe(addr(clip.maxs2[0]))[1]) = float(unsafe(maxs_0[1]))  // nolint:PERF020
        unsafe(unsafe(addr(clip.maxs2[0]))[2]) = float(unsafe(maxs_0[2]))  // nolint:PERF020
    }
    SV_MoveBounds(start, unsafe(addr<float?>(clip.mins2[0])), unsafe(addr<float?>(clip.maxs2[0])), end, unsafe(addr<float?>(clip.boxmins[0])), unsafe(addr<float?>(clip.boxmaxs[0])))
    SV_ClipToLinks(unsafe(addr<areanode_s?>(sv_areanodes[0])), unsafe(addr<moveclip_t?>(clip)))
    return clip.trace
}
[export, sideeffects]
def SV_ClipToLinks(var node_3 : areanode_s?; var clip_0 : moveclip_t?) {
    var l_0 : link_s?
    var next_1 : link_s?
    var touch_0 : edict_s?
    var trace_0 : trace_t = trace_t()
    l_0 = unsafe(reinterpret<link_s?>(node_3.solid_edicts.next))
    while (true) {
        var c2da_fresh89 : link_s? = unsafe(reinterpret<link_s?>(unsafe(reinterpret<uint64>(node_3)) + 40ul))
        if (l_0 == c2da_fresh89) {
            break
        }
        next_1 = unsafe(reinterpret<link_s?>(l_0.next))
        var c2da_fresh90 : link_s? = unsafe(reinterpret<link_s?>(unsafe(reinterpret<uint64>(null)) + 8ul))
        touch_0 = unsafe(reinterpret<edict_s?>(unsafe(reinterpret<edict_s?>(unsafe(unsafe(reinterpret<uint8?>(l_0)) + -int64(unsafe(reinterpret<uint64>(c2da_fresh90))))))))
        if (touch_0.v.solid == 0.0) {
            l_0 = unsafe(reinterpret<link_s?>(next_1))
            continue
        }
        if (touch_0 == clip_0.passedict) {
            l_0 = unsafe(reinterpret<link_s?>(next_1))
            continue
        }
        if (touch_0.v.solid == 1.0) {
            Sys_Error(unsafe(addr<int8?>(c2da_str_world_1[0])), [])
        }
        if (clip_0.type_0 == 1 && touch_0.v.solid != 4.0) {
            l_0 = unsafe(reinterpret<link_s?>(next_1))
            continue
        }
        var c2da_fresh91 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip_0))))
        var c2da_fresh92 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(touch_0)) + 124ul))
        var c2da_fresh95 : int = 1
        if (!(unsafe(unsafe(reinterpret<float?>(c2da_fresh91))[0]) > unsafe(unsafe(reinterpret<float?>(c2da_fresh92))[0]))) {
            var c2da_fresh93 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip_0))))
            var c2da_fresh94 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(touch_0)) + 124ul))
            if (!(unsafe(unsafe(reinterpret<float?>(c2da_fresh93))[1]) > unsafe(unsafe(reinterpret<float?>(c2da_fresh94))[1]))) {
                c2da_fresh95 = 0
            }
        }
        var c2da_fresh98 : int = 1
        if (!(c2da_fresh95 != 0)) {
            var c2da_fresh96 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip_0))))
            var c2da_fresh97 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(touch_0)) + 124ul))
            if (!(unsafe(unsafe(reinterpret<float?>(c2da_fresh96))[2]) > unsafe(unsafe(reinterpret<float?>(c2da_fresh97))[2]))) {
                c2da_fresh98 = 0
            }
        }
        var c2da_fresh101 : int = 1
        if (!(c2da_fresh98 != 0)) {
            var c2da_fresh99 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip_0)) + 12ul))
            var c2da_fresh100 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(touch_0)) + 112ul))
            if (!(unsafe(unsafe(reinterpret<float?>(c2da_fresh99))[0]) < unsafe(unsafe(reinterpret<float?>(c2da_fresh100))[0]))) {
                c2da_fresh101 = 0
            }
        }
        var c2da_fresh104 : int = 1
        if (!(c2da_fresh101 != 0)) {
            var c2da_fresh102 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip_0)) + 12ul))
            var c2da_fresh103 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(touch_0)) + 112ul))
            if (!(unsafe(unsafe(reinterpret<float?>(c2da_fresh102))[1]) < unsafe(unsafe(reinterpret<float?>(c2da_fresh103))[1]))) {
                c2da_fresh104 = 0
            }
        }
        var c2da_fresh107 : int = 1
        if (!(c2da_fresh104 != 0)) {
            var c2da_fresh105 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip_0)) + 12ul))
            var c2da_fresh106 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(touch_0)) + 112ul))
            if (!(unsafe(unsafe(reinterpret<float?>(c2da_fresh105))[2]) < unsafe(unsafe(reinterpret<float?>(c2da_fresh106))[2]))) {
                c2da_fresh107 = 0
            }
        }
        if (c2da_fresh107 != 0) {
            l_0 = unsafe(reinterpret<link_s?>(next_1))
            continue
        }
        var c2da_fresh109 : int = 0
        if (clip_0.passedict != null) {
            var c2da_fresh108 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip_0.passedict)) + 264ul))
            if (unsafe(unsafe(reinterpret<float?>(c2da_fresh108))[0]) != 0.0) {
                c2da_fresh109 = 1
            }
        }
        var c2da_fresh111 : int = 0
        if (c2da_fresh109 != 0) {
            var c2da_fresh110 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(touch_0)) + 264ul))
            if (unsafe(unsafe(reinterpret<float?>(c2da_fresh110))[0]) == 0.0) {
                c2da_fresh111 = 1
            }
        }
        if (c2da_fresh111 != 0) {
            l_0 = unsafe(reinterpret<link_s?>(next_1))
            continue
        }
        if (uint(clip_0.trace.allsolid) != 0u) {
            return
        }
        if (clip_0.passedict != null) {
            if (unsafe(reinterpret<edict_s?>(unsafe(unsafe(reinterpret<uint8?>(sv.edicts)) + touch_0.v.owner))) == clip_0.passedict) {
                l_0 = unsafe(reinterpret<link_s?>(next_1))
                continue
            }
            if (unsafe(reinterpret<edict_s?>(unsafe(unsafe(reinterpret<uint8?>(sv.edicts)) + clip_0.passedict.v.owner))) == touch_0) {
                l_0 = unsafe(reinterpret<link_s?>(next_1))
                continue
            }
        }
        if ((int(touch_0.v.flags) & 32) != 0) {
            var c2da_fresh112 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip_0)) + 40ul))
            var c2da_fresh113 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip_0)) + 52ul))
            trace_0 = SV_ClipMoveToEntity(touch_0, clip_0.start, unsafe(reinterpret<float?>(c2da_fresh112)), unsafe(reinterpret<float?>(c2da_fresh113)), clip_0.end)
        } else {
            trace_0 = SV_ClipMoveToEntity(touch_0, clip_0.start, clip_0.mins, clip_0.maxs, clip_0.end)
        }
        if (uint(trace_0.allsolid) != 0x0 || uint(trace_0.startsolid) != 0x0 || trace_0.fraction < clip_0.trace.fraction) {
            trace_0.ent = unsafe(reinterpret<edict_s?>(touch_0))
            if (uint(clip_0.trace.startsolid) != 0u) {
                var c2da_fresh114 : trace_t = trace_0
                unsafe(memcpy(unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(clip_0)) + 80ul)), unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(addr(c2da_fresh114)))))), 56ul))
                clip_0.trace.startsolid = unsafe(reinterpret<qboolean>(1u))
            } else {
                var c2da_fresh115 : trace_t = trace_0
                unsafe(memcpy(unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(clip_0)) + 80ul)), unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(addr(c2da_fresh115)))))), 56ul))
            }
        } elif (uint(trace_0.startsolid) != 0u) {
            clip_0.trace.startsolid = unsafe(reinterpret<qboolean>(1u))
        }
        l_0 = unsafe(reinterpret<link_s?>(next_1))
    }
    if (node_3.axis == -1) {
        return
    }
    var c2da_fresh116 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip_0)) + 12ul))
    if (unsafe(unsafe(reinterpret<float?>(c2da_fresh116))[node_3.axis]) > node_3.dist) {
        var c2da_fresh117 : areanode_s?? = unsafe(reinterpret<areanode_s??>(unsafe(reinterpret<uint64>(node_3)) + 8ul))
        SV_ClipToLinks(unsafe(reinterpret<areanode_s?>(unsafe(unsafe(reinterpret<areanode_s??>(c2da_fresh117))[0]))), clip_0)
    }
    var c2da_fresh118 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(clip_0))))
    if (unsafe(unsafe(reinterpret<float?>(c2da_fresh118))[node_3.axis]) < node_3.dist) {
        var c2da_fresh119 : areanode_s?? = unsafe(reinterpret<areanode_s??>(unsafe(reinterpret<uint64>(node_3)) + 8ul))
        SV_ClipToLinks(unsafe(reinterpret<areanode_s?>(unsafe(unsafe(reinterpret<areanode_s??>(c2da_fresh119))[1]))), clip_0)
    }
    return
}
[export, sideeffects]
def SV_ClipMoveToEntity(var ent_4 : edict_s?; var start_0 : float?; var mins_1 : float?; var maxs_1 : float?; var end_0 : float?) : trace_t {
    var trace_1 : trace_t = trace_t()
    var offset : vec3_t
    var start_l : vec3_t
    var end_l : vec3_t
    var hull_0 : hull_t?
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(trace_1)))), 0u8, 56ul)))
    trace_1.fraction = 1.0
    trace_1.allsolid = unsafe(reinterpret<qboolean>(1u))
    unsafe(unsafe(addr(trace_1.endpos[0]))[0]) = float(unsafe(end_0[0]))  // nolint:PERF020
    unsafe(unsafe(addr(trace_1.endpos[0]))[1]) = float(unsafe(end_0[1]))  // nolint:PERF020
    unsafe(unsafe(addr(trace_1.endpos[0]))[2]) = float(unsafe(end_0[2]))  // nolint:PERF020
    hull_0 = unsafe(reinterpret<hull_t?>(unsafe(reinterpret<hull_t?>(SV_HullForEntity(ent_4, mins_1, maxs_1, unsafe(addr<float?>(offset[0])))))))
    unsafe(unsafe(addr(start_l[0]))[0]) = unsafe(start_0[0]) - unsafe(unsafe(addr(offset[0]))[0])
    unsafe(unsafe(addr(start_l[0]))[1]) = unsafe(start_0[1]) - unsafe(unsafe(addr(offset[0]))[1])
    unsafe(unsafe(addr(start_l[0]))[2]) = unsafe(start_0[2]) - unsafe(unsafe(addr(offset[0]))[2])
    unsafe(unsafe(addr(end_l[0]))[0]) = unsafe(end_0[0]) - unsafe(unsafe(addr(offset[0]))[0])
    unsafe(unsafe(addr(end_l[0]))[1]) = unsafe(end_0[1]) - unsafe(unsafe(addr(offset[0]))[1])
    unsafe(unsafe(addr(end_l[0]))[2]) = unsafe(end_0[2]) - unsafe(unsafe(addr(offset[0]))[2])
    SV_RecursiveHullCheck(hull_0, hull_0.firstclipnode, 0.0, 1.0, unsafe(addr<float?>(start_l[0])), unsafe(addr<float?>(end_l[0])), unsafe(addr<trace_t?>(trace_1)))
    if (trace_1.fraction != 1.0) {
        unsafe(unsafe(addr(trace_1.endpos[0]))[0]) += unsafe(unsafe(addr(offset[0]))[0])
        unsafe(unsafe(addr(trace_1.endpos[0]))[1]) += unsafe(unsafe(addr(offset[0]))[1])
        unsafe(unsafe(addr(trace_1.endpos[0]))[2]) += unsafe(unsafe(addr(offset[0]))[2])
    }
    if (trace_1.fraction < 1.0 || uint(trace_1.startsolid) != 0x0) {
        trace_1.ent = unsafe(reinterpret<edict_s?>(ent_4))
    }
    return trace_1
}
[export, sideeffects]
def SV_RecursiveHullCheck(var hull_1 : hull_t?; var num_0 : int; var p1f : float; var p2f : float; var p1 : float?; var p2 : float?; var trace_2 : trace_t?) : qboolean {
    var node_4 : dclipnode_t?
    var plane_0 : mplane_s?
    var t1 : float
    var t2 : float
    var frac : float
    var i_1 : int
    var mid : vec3_t
    var side_0 : int
    var midf : float
    if (num_0 < 0) {
        if (num_0 != -2) {
            trace_2.allsolid = unsafe(reinterpret<qboolean>(0u))
            if (num_0 == -1) {
                trace_2.inopen = unsafe(reinterpret<qboolean>(1u))
            } else {
                trace_2.inwater = unsafe(reinterpret<qboolean>(1u))
            }
        } else {
            trace_2.startsolid = unsafe(reinterpret<qboolean>(1u))
        }
        return unsafe(reinterpret<qboolean>(1u))
    }
    if (num_0 < hull_1.firstclipnode || num_0 > hull_1.lastclipnode) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_world_2[0])), [])
    }
    node_4 = unsafe(reinterpret<dclipnode_t?>(unsafe(hull_1.clipnodes + num_0)))
    plane_0 = unsafe(reinterpret<mplane_s?>(unsafe(hull_1.planes + node_4.planenum)))
    if (int(plane_0.type_0) < 3) {
        t1 = unsafe(p1[int(plane_0.type_0)]) - plane_0.dist
        t2 = unsafe(p2[int(plane_0.type_0)]) - plane_0.dist
    } else {
        var c2da_fresh120 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane_0))))
        var c2da_fresh121 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane_0))))
        var c2da_fresh122 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane_0))))
        t1 = unsafe(unsafe(reinterpret<float?>(c2da_fresh120))[0]) * unsafe(p1[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh121))[1]) * unsafe(p1[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh122))[2]) * unsafe(p1[2]) - plane_0.dist
        var c2da_fresh123 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane_0))))
        var c2da_fresh124 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane_0))))
        var c2da_fresh125 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane_0))))
        t2 = unsafe(unsafe(reinterpret<float?>(c2da_fresh123))[0]) * unsafe(p2[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh124))[1]) * unsafe(p2[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh125))[2]) * unsafe(p2[2]) - plane_0.dist
    }
    if (t1 >= 0.0 && t2 >= 0.0) {
        var c2da_fresh126 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(node_4)) + 4ul))
        return SV_RecursiveHullCheck(hull_1, int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh126))[0])), p1f, p2f, p1, p2, trace_2)
    }
    if (t1 < 0.0 && t2 < 0.0) {
        var c2da_fresh127 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(node_4)) + 4ul))
        return SV_RecursiveHullCheck(hull_1, int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh127))[1])), p1f, p2f, p1, p2, trace_2)
    }
    if (t1 < 0.0) {
        frac = float((double(t1) + 0.03125lf) / double(t1 - t2))
    } else {
        frac = float((double(t1) - 0.03125lf) / double(t1 - t2))
    }
    if (frac < 0.0) {
        frac = 0.0
    }
    if (frac > 1.0) {
        frac = 1.0
    }
    midf = p1f + (p2f - p1f) * frac
    i_1 = 0
    while (i_1 < 3) {
        unsafe(unsafe(addr(mid[0]))[i_1]) = unsafe(p1[i_1]) + frac * (unsafe(p2[i_1]) - unsafe(p1[i_1]))
        i_1++
    }
    side_0 = t1 < 0.0 ? 1 : 0
    var c2da_fresh128 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(node_4)) + 4ul))
    if (uint(SV_RecursiveHullCheck(hull_1, int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh128))[side_0])), p1f, midf, p1, unsafe(addr<float?>(mid[0])), trace_2)) == 0u) {
        return unsafe(reinterpret<qboolean>(0u))
    }
    var c2da_fresh129 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(node_4)) + 4ul))
    if (SV_HullPointContents(hull_1, int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh129))[side_0 ^ 1])), unsafe(addr<float?>(mid[0]))) != -2) {
        var c2da_fresh130 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(node_4)) + 4ul))
        return SV_RecursiveHullCheck(hull_1, int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh130))[side_0 ^ 1])), midf, p2f, unsafe(addr<float?>(mid[0])), p2, trace_2)
    }
    if (uint(trace_2.allsolid) != 0u) {
        return unsafe(reinterpret<qboolean>(0u))
    }
    if (side_0 == 0) {
        var c2da_fresh131 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(trace_2)) + 32ul))
        var c2da_fresh132 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane_0))))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh131))[0]) = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh132))[0]))  // nolint:PERF020
        var c2da_fresh133 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(trace_2)) + 32ul))
        var c2da_fresh134 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane_0))))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh133))[1]) = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh134))[1]))  // nolint:PERF020
        var c2da_fresh135 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(trace_2)) + 32ul))
        var c2da_fresh136 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane_0))))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh135))[2]) = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh136))[2]))  // nolint:PERF020
        trace_2.plane.dist = float(plane_0.dist)  // nolint:PERF020
    } else {
        var c2da_fresh137 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(trace_2)) + 32ul))
        var c2da_fresh138 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane_0))))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh137))[0]) = unsafe(unsafe(addr(vec3_origin[0]))[0]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh138))[0])
        var c2da_fresh139 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(trace_2)) + 32ul))
        var c2da_fresh140 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane_0))))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh139))[1]) = unsafe(unsafe(addr(vec3_origin[0]))[1]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh140))[1])
        var c2da_fresh141 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(trace_2)) + 32ul))
        var c2da_fresh142 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane_0))))
        unsafe(unsafe(reinterpret<float?>(c2da_fresh141))[2]) = unsafe(unsafe(addr(vec3_origin[0]))[2]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh142))[2])
        trace_2.plane.dist = -plane_0.dist
    }
    while (SV_HullPointContents(hull_1, hull_1.firstclipnode, unsafe(addr<float?>(mid[0]))) == -2) {
        frac = float(double(frac) - 0.1lf)
        if (frac < 0.0) {
            trace_2.fraction = midf
            var c2da_fresh143 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(trace_2)) + 20ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh143))[0]) = float(unsafe(unsafe(addr(mid[0]))[0]))  // nolint:PERF020
            var c2da_fresh144 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(trace_2)) + 20ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh144))[1]) = float(unsafe(unsafe(addr(mid[0]))[1]))  // nolint:PERF020
            var c2da_fresh145 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(trace_2)) + 20ul))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh145))[2]) = float(unsafe(unsafe(addr(mid[0]))[2]))  // nolint:PERF020
            Con_DPrintf(unsafe(addr<int8?>(c2da_str_world_3[0])), [])
            return unsafe(reinterpret<qboolean>(0u))
        }
        midf = p1f + (p2f - p1f) * frac
        i_1 = 0
        while (i_1 < 3) {
            unsafe(unsafe(addr(mid[0]))[i_1]) = unsafe(p1[i_1]) + frac * (unsafe(p2[i_1]) - unsafe(p1[i_1]))
            i_1++
        }
    }
    trace_2.fraction = midf
    var c2da_fresh146 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(trace_2)) + 20ul))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh146))[0]) = float(unsafe(unsafe(addr(mid[0]))[0]))  // nolint:PERF020
    var c2da_fresh147 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(trace_2)) + 20ul))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh147))[1]) = float(unsafe(unsafe(addr(mid[0]))[1]))  // nolint:PERF020
    var c2da_fresh148 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(trace_2)) + 20ul))
    unsafe(unsafe(reinterpret<float?>(c2da_fresh148))[2]) = float(unsafe(unsafe(addr(mid[0]))[2]))  // nolint:PERF020
    return unsafe(reinterpret<qboolean>(0u))
}
[export, sideeffects]
def SV_HullForEntity(var ent_5 : edict_s?; var mins_2 : float?; var maxs_2 : float?; var offset_0 : float?) : hull_t? {
    var model : model_s?
    var size_0 : vec3_t
    var hullmins : vec3_t
    var hullmaxs : vec3_t
    var hull_2 : hull_t?
    if (ent_5.v.solid == 4.0) {
        if (ent_5.v.movetype != 7.0) {
            Sys_Error(unsafe(addr<int8?>(c2da_str_world_4[0])), [])
        }
        model = unsafe(reinterpret<model_s?>(unsafe(unsafe(addr(sv.models[0]))[int(ent_5.v.modelindex)])))
        if (model == null || uint(model.type_0) != 0u) {
            Sys_Error(unsafe(addr<int8?>(c2da_str_world_5[0])), [])
        }
        unsafe(unsafe(addr(size_0[0]))[0]) = unsafe(maxs_2[0]) - unsafe(mins_2[0])
        unsafe(unsafe(addr(size_0[0]))[1]) = unsafe(maxs_2[1]) - unsafe(mins_2[1])
        unsafe(unsafe(addr(size_0[0]))[2]) = unsafe(maxs_2[2]) - unsafe(mins_2[2])
        if (unsafe(unsafe(addr(size_0[0]))[0]) < 3.0) {
            var c2da_fresh149 : hull_t? = unsafe(reinterpret<hull_t?>(unsafe(reinterpret<uint64>(model)) + 296ul))
            hull_2 = unsafe(addr<hull_t?>(unsafe(unsafe(reinterpret<hull_t?>(c2da_fresh149))[0])))
        } elif (unsafe(unsafe(addr(size_0[0]))[0]) <= 32.0) {
            var c2da_fresh150 : hull_t? = unsafe(reinterpret<hull_t?>(unsafe(reinterpret<uint64>(model)) + 296ul))
            hull_2 = unsafe(addr<hull_t?>(unsafe(unsafe(reinterpret<hull_t?>(c2da_fresh150))[1])))
        } else {
            var c2da_fresh151 : hull_t? = unsafe(reinterpret<hull_t?>(unsafe(reinterpret<uint64>(model)) + 296ul))
            hull_2 = unsafe(addr<hull_t?>(unsafe(unsafe(reinterpret<hull_t?>(c2da_fresh151))[2])))
        }
        var c2da_fresh152 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(hull_2)) + 24ul))
        unsafe(offset_0[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh152))[0]) - unsafe(mins_2[0])
        var c2da_fresh153 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(hull_2)) + 24ul))
        unsafe(offset_0[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh153))[1]) - unsafe(mins_2[1])
        var c2da_fresh154 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(hull_2)) + 24ul))
        unsafe(offset_0[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh154))[2]) - unsafe(mins_2[2])
        var c2da_fresh155 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_5)) + 148ul))
        unsafe(offset_0[0]) += unsafe(unsafe(reinterpret<float?>(c2da_fresh155))[0])
        var c2da_fresh156 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_5)) + 148ul))
        unsafe(offset_0[1]) += unsafe(unsafe(reinterpret<float?>(c2da_fresh156))[1])
        var c2da_fresh157 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_5)) + 148ul))
        unsafe(offset_0[2]) += unsafe(unsafe(reinterpret<float?>(c2da_fresh157))[2])
    } else {
        var c2da_fresh158 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_5)) + 240ul))
        unsafe(unsafe(addr(hullmins[0]))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh158))[0]) - unsafe(maxs_2[0])
        var c2da_fresh159 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_5)) + 240ul))
        unsafe(unsafe(addr(hullmins[0]))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh159))[1]) - unsafe(maxs_2[1])
        var c2da_fresh160 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_5)) + 240ul))
        unsafe(unsafe(addr(hullmins[0]))[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh160))[2]) - unsafe(maxs_2[2])
        var c2da_fresh161 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_5)) + 252ul))
        unsafe(unsafe(addr(hullmaxs[0]))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh161))[0]) - unsafe(mins_2[0])
        var c2da_fresh162 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_5)) + 252ul))
        unsafe(unsafe(addr(hullmaxs[0]))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh162))[1]) - unsafe(mins_2[1])
        var c2da_fresh163 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_5)) + 252ul))
        unsafe(unsafe(addr(hullmaxs[0]))[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh163))[2]) - unsafe(mins_2[2])
        hull_2 = unsafe(reinterpret<hull_t?>(unsafe(reinterpret<hull_t?>(SV_HullForBox(unsafe(addr<float?>(hullmins[0])), unsafe(addr<float?>(hullmaxs[0])))))))
        var c2da_fresh164 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_5)) + 148ul))
        unsafe(offset_0[0]) = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh164))[0]))  // nolint:PERF020
        var c2da_fresh165 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_5)) + 148ul))
        unsafe(offset_0[1]) = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh165))[1]))  // nolint:PERF020
        var c2da_fresh166 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent_5)) + 148ul))
        unsafe(offset_0[2]) = float(unsafe(unsafe(reinterpret<float?>(c2da_fresh166))[2]))  // nolint:PERF020
    }
    return unsafe(reinterpret<hull_t?>(hull_2))
}
[export, sideeffects]
def SV_HullForBox(var mins_3 : float?; var maxs_3 : float?) : hull_t? {
    box_planes[0].dist = float(unsafe(maxs_3[0]))  // nolint:PERF020
    box_planes[1].dist = float(unsafe(mins_3[0]))  // nolint:PERF020
    box_planes[2].dist = float(unsafe(maxs_3[1]))  // nolint:PERF020
    box_planes[3].dist = float(unsafe(mins_3[1]))  // nolint:PERF020
    box_planes[4].dist = float(unsafe(maxs_3[2]))  // nolint:PERF020
    box_planes[5].dist = float(unsafe(mins_3[2]))  // nolint:PERF020
    return unsafe(addr<hull_t?>(box_hull))
}
[export, sideeffects]
def SV_MoveBounds(var start_1 : float?; var mins_4 : float?; var maxs_4 : float?; var end_1 : float?; var boxmins : float?; var boxmaxs : float?) {
    for (i_2 in range(0, 3)) {
        if (unsafe(end_1[i_2]) > unsafe(start_1[i_2])) {
            unsafe(boxmins[i_2]) = unsafe(start_1[i_2]) + unsafe(mins_4[i_2]) - 1.0
            unsafe(boxmaxs[i_2]) = unsafe(end_1[i_2]) + unsafe(maxs_4[i_2]) + 1.0
        } else {
            unsafe(boxmins[i_2]) = unsafe(end_1[i_2]) + unsafe(mins_4[i_2]) - 1.0
            unsafe(boxmaxs[i_2]) = unsafe(start_1[i_2]) + unsafe(maxs_4[i_2]) + 1.0
        }
    }
    return
}
[sideeffects]
def private c2da_layout_proofs_54() {
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
    static_assert(typeinfo sizeof(type<model_t>) == 536, "C layout of model_t: sizeof")
    static_assert(typeinfo alignof(type<model_t>) == 8, "C layout of model_t: alignof")
    static_assert(typeinfo offsetof<name>(type<model_t>) == 0, "C layout of model_t: offsetof name")
    static_assert(typeinfo offsetof<needload>(type<model_t>) == 64, "C layout of model_t: offsetof needload")
    static_assert(typeinfo offsetof<type_0>(type<model_t>) == 68, "C layout of model_t: offsetof type_0")
    static_assert(typeinfo offsetof<numframes>(type<model_t>) == 72, "C layout of model_t: offsetof numframes")
    static_assert(typeinfo offsetof<synctype>(type<model_t>) == 76, "C layout of model_t: offsetof synctype")
    static_assert(typeinfo offsetof<flags>(type<model_t>) == 80, "C layout of model_t: offsetof flags")
    static_assert(typeinfo offsetof<mins>(type<model_t>) == 84, "C layout of model_t: offsetof mins")
    static_assert(typeinfo offsetof<maxs>(type<model_t>) == 96, "C layout of model_t: offsetof maxs")
    static_assert(typeinfo offsetof<radius>(type<model_t>) == 108, "C layout of model_t: offsetof radius")
    static_assert(typeinfo offsetof<firstmodelsurface>(type<model_t>) == 112, "C layout of model_t: offsetof firstmodelsurface")
    static_assert(typeinfo offsetof<nummodelsurfaces>(type<model_t>) == 116, "C layout of model_t: offsetof nummodelsurfaces")
    static_assert(typeinfo offsetof<numsubmodels>(type<model_t>) == 120, "C layout of model_t: offsetof numsubmodels")
    static_assert(typeinfo offsetof<submodels>(type<model_t>) == 128, "C layout of model_t: offsetof submodels")
    static_assert(typeinfo offsetof<numplanes>(type<model_t>) == 136, "C layout of model_t: offsetof numplanes")
    static_assert(typeinfo offsetof<planes>(type<model_t>) == 144, "C layout of model_t: offsetof planes")
    static_assert(typeinfo offsetof<numleafs>(type<model_t>) == 152, "C layout of model_t: offsetof numleafs")
    static_assert(typeinfo offsetof<leafs>(type<model_t>) == 160, "C layout of model_t: offsetof leafs")
    static_assert(typeinfo offsetof<numvertexes>(type<model_t>) == 168, "C layout of model_t: offsetof numvertexes")
    static_assert(typeinfo offsetof<vertexes>(type<model_t>) == 176, "C layout of model_t: offsetof vertexes")
    static_assert(typeinfo offsetof<numedges>(type<model_t>) == 184, "C layout of model_t: offsetof numedges")
    static_assert(typeinfo offsetof<edges>(type<model_t>) == 192, "C layout of model_t: offsetof edges")
    static_assert(typeinfo offsetof<numnodes>(type<model_t>) == 200, "C layout of model_t: offsetof numnodes")
    static_assert(typeinfo offsetof<nodes>(type<model_t>) == 208, "C layout of model_t: offsetof nodes")
    static_assert(typeinfo offsetof<numtexinfo>(type<model_t>) == 216, "C layout of model_t: offsetof numtexinfo")
    static_assert(typeinfo offsetof<texinfo>(type<model_t>) == 224, "C layout of model_t: offsetof texinfo")
    static_assert(typeinfo offsetof<numsurfaces>(type<model_t>) == 232, "C layout of model_t: offsetof numsurfaces")
    static_assert(typeinfo offsetof<surfaces>(type<model_t>) == 240, "C layout of model_t: offsetof surfaces")
    static_assert(typeinfo offsetof<numsurfedges>(type<model_t>) == 248, "C layout of model_t: offsetof numsurfedges")
    static_assert(typeinfo offsetof<surfedges>(type<model_t>) == 256, "C layout of model_t: offsetof surfedges")
    static_assert(typeinfo offsetof<numclipnodes>(type<model_t>) == 264, "C layout of model_t: offsetof numclipnodes")
    static_assert(typeinfo offsetof<clipnodes>(type<model_t>) == 272, "C layout of model_t: offsetof clipnodes")
    static_assert(typeinfo offsetof<nummarksurfaces>(type<model_t>) == 280, "C layout of model_t: offsetof nummarksurfaces")
    static_assert(typeinfo offsetof<marksurfaces>(type<model_t>) == 288, "C layout of model_t: offsetof marksurfaces")
    static_assert(typeinfo offsetof<hulls>(type<model_t>) == 296, "C layout of model_t: offsetof hulls")
    static_assert(typeinfo offsetof<numtextures>(type<model_t>) == 488, "C layout of model_t: offsetof numtextures")
    static_assert(typeinfo offsetof<textures>(type<model_t>) == 496, "C layout of model_t: offsetof textures")
    static_assert(typeinfo offsetof<visdata>(type<model_t>) == 504, "C layout of model_t: offsetof visdata")
    static_assert(typeinfo offsetof<lightdata>(type<model_t>) == 512, "C layout of model_t: offsetof lightdata")
    static_assert(typeinfo offsetof<entities>(type<model_t>) == 520, "C layout of model_t: offsetof entities")
    static_assert(typeinfo offsetof<cache>(type<model_t>) == 528, "C layout of model_t: offsetof cache")
    static_assert(typeinfo sizeof(type<plane_t>) == 16, "C layout of plane_t: sizeof")
    static_assert(typeinfo alignof(type<plane_t>) == 4, "C layout of plane_t: alignof")
    static_assert(typeinfo offsetof<normal>(type<plane_t>) == 0, "C layout of plane_t: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<plane_t>) == 12, "C layout of plane_t: offsetof dist")
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
    static_assert(typeinfo sizeof(type<areanode_t>) == 56, "C layout of areanode_t: sizeof")
    static_assert(typeinfo alignof(type<areanode_t>) == 8, "C layout of areanode_t: alignof")
    static_assert(typeinfo offsetof<axis>(type<areanode_t>) == 0, "C layout of areanode_t: offsetof axis")
    static_assert(typeinfo offsetof<dist>(type<areanode_t>) == 4, "C layout of areanode_t: offsetof dist")
    static_assert(typeinfo offsetof<children>(type<areanode_t>) == 8, "C layout of areanode_t: offsetof children")
    static_assert(typeinfo offsetof<trigger_edicts>(type<areanode_t>) == 24, "C layout of areanode_t: offsetof trigger_edicts")
    static_assert(typeinfo offsetof<solid_edicts>(type<areanode_t>) == 40, "C layout of areanode_t: offsetof solid_edicts")
    static_assert(typeinfo sizeof(type<areanode_s>) == 56, "C layout of areanode_s: sizeof")
    static_assert(typeinfo alignof(type<areanode_s>) == 8, "C layout of areanode_s: alignof")
    static_assert(typeinfo offsetof<axis>(type<areanode_s>) == 0, "C layout of areanode_s: offsetof axis")
    static_assert(typeinfo offsetof<dist>(type<areanode_s>) == 4, "C layout of areanode_s: offsetof dist")
    static_assert(typeinfo offsetof<children>(type<areanode_s>) == 8, "C layout of areanode_s: offsetof children")
    static_assert(typeinfo offsetof<trigger_edicts>(type<areanode_s>) == 24, "C layout of areanode_s: offsetof trigger_edicts")
    static_assert(typeinfo offsetof<solid_edicts>(type<areanode_s>) == 40, "C layout of areanode_s: offsetof solid_edicts")
    static_assert(typeinfo sizeof(type<moveclip_t>) == 152, "C layout of moveclip_t: sizeof")
    static_assert(typeinfo alignof(type<moveclip_t>) == 8, "C layout of moveclip_t: alignof")
    static_assert(typeinfo offsetof<boxmins>(type<moveclip_t>) == 0, "C layout of moveclip_t: offsetof boxmins")
    static_assert(typeinfo offsetof<boxmaxs>(type<moveclip_t>) == 12, "C layout of moveclip_t: offsetof boxmaxs")
    static_assert(typeinfo offsetof<mins>(type<moveclip_t>) == 24, "C layout of moveclip_t: offsetof mins")
    static_assert(typeinfo offsetof<maxs>(type<moveclip_t>) == 32, "C layout of moveclip_t: offsetof maxs")
    static_assert(typeinfo offsetof<mins2>(type<moveclip_t>) == 40, "C layout of moveclip_t: offsetof mins2")
    static_assert(typeinfo offsetof<maxs2>(type<moveclip_t>) == 52, "C layout of moveclip_t: offsetof maxs2")
    static_assert(typeinfo offsetof<start>(type<moveclip_t>) == 64, "C layout of moveclip_t: offsetof start")
    static_assert(typeinfo offsetof<end>(type<moveclip_t>) == 72, "C layout of moveclip_t: offsetof end")
    static_assert(typeinfo offsetof<trace>(type<moveclip_t>) == 80, "C layout of moveclip_t: offsetof trace")
    static_assert(typeinfo offsetof<type_0>(type<moveclip_t>) == 136, "C layout of moveclip_t: offsetof type_0")
    static_assert(typeinfo offsetof<passedict>(type<moveclip_t>) == 144, "C layout of moveclip_t: offsetof passedict")
}
