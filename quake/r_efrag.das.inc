var private c2da_str_r_efrag_0 : array<int8> = [int8(84), int8(111), int8(111), int8(32), int8(109), int8(97), int8(110), int8(121), int8(32), int8(101), int8(102), int8(114), int8(97), int8(103), int8(115), int8(33), int8(10), int8(0)]

var private c2da_str_r_efrag_1 : array<int8> = [int8(82), int8(95), int8(83), int8(116), int8(111), int8(114), int8(101), int8(69), int8(102), int8(114), int8(97), int8(103), int8(115), int8(58), int8(32), int8(66), int8(97), int8(100), int8(32), int8(101), int8(110), int8(116), int8(105), int8(116), int8(121), int8(32), int8(116), int8(121), int8(112), int8(101), int8(32), int8(37), int8(100), int8(10), int8(0)]

[export, sideeffects]
def R_AddEfrags(var ent : entity_s?) {
    var entmodel : model_s?
    if (ent.model == null) {
        return
    }
    if (ent == unsafe(addr(cl_entities[0]))) {
        return
    }
    r_addent = unsafe(reinterpret<entity_s?>(ent))
    var c2da_fresh0 : efrag_s?? = unsafe(reinterpret<efrag_s??>(unsafe(reinterpret<uint64>(ent)) + 144ul))
    lastlink = unsafe(reinterpret<efrag_s??>(c2da_fresh0))
    r_pefragtopnode = null
    entmodel = unsafe(reinterpret<model_s?>(ent.model))
    for (i in range(0, 3)) {
        var c2da_fresh1 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 88ul))
        var c2da_fresh2 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(entmodel)) + 84ul))
        unsafe(unsafe(addr(r_emins[0]))[i]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh1))[i]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh2))[i])
        var c2da_fresh3 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ent)) + 88ul))
        var c2da_fresh4 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(entmodel)) + 96ul))
        unsafe(unsafe(addr(r_emaxs[0]))[i]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh3))[i]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh4))[i])
    }
    R_SplitEntityOnNode(cl.worldmodel.nodes)
    ent.topnode = r_pefragtopnode
    return
}
var r_pefragtopnode : mnode_s? = default<mnode_s?>

[export, sideeffects]
def R_SplitEntityOnNode(var node : mnode_s?) {
    var ef : efrag_s?
    var splitplane : mplane_s?
    var leaf : mleaf_s?
    var sides : int
    if (node.contents == -2) {
        return
    }
    if (node.contents < 0) {
        if (r_pefragtopnode == null) {
            r_pefragtopnode = unsafe(reinterpret<mnode_s?>(node))
        }
        leaf = unsafe(reinterpret<mleaf_s?>(unsafe(reinterpret<mleaf_s?>(node))))
        ef = unsafe(reinterpret<efrag_s?>(cl.free_efrags))
        if (ef == null) {
            Con_Printf(unsafe(addr<int8?>(c2da_str_r_efrag_0[0])), [])
            return
        }
        cl.free_efrags = unsafe(reinterpret<efrag_s?>(cl.free_efrags.entnext))
        ef.entity = r_addent
        *lastlink = unsafe(reinterpret<efrag_s?>(ef))
        var c2da_fresh5 : efrag_s?? = unsafe(reinterpret<efrag_s??>(unsafe(reinterpret<uint64>(ef)) + 24ul))
        lastlink = unsafe(reinterpret<efrag_s??>(c2da_fresh5))
        ef.entnext = null
        ef.leaf = leaf
        ef.leafnext = leaf.efrags
        leaf.efrags = ef
        return
    }
    splitplane = unsafe(reinterpret<mplane_s?>(node.plane))
    sides = int(splitplane.type_0) < 3 ? (splitplane.dist <= unsafe(unsafe(addr(r_emins[0]))[int(splitplane.type_0)]) ? 1 : splitplane.dist >= unsafe(unsafe(addr(r_emaxs[0]))[int(splitplane.type_0)]) ? 2 : 3) : BoxOnPlaneSide(unsafe(addr<float?>(r_emins[0])), unsafe(addr<float?>(r_emaxs[0])), splitplane)
    if (sides == 3) {
        if (r_pefragtopnode == null) {
            r_pefragtopnode = unsafe(reinterpret<mnode_s?>(node))
        }
    }
    if ((sides & 1) != 0) {
        var c2da_fresh6 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node)) + 40ul))
        R_SplitEntityOnNode(unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh6))[0]))))
    }
    if ((sides & 2) != 0) {
        var c2da_fresh7 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node)) + 40ul))
        R_SplitEntityOnNode(unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh7))[1]))))
    }
    return
}
var r_emaxs : vec3_t = default<vec3_t>

var r_emins : vec3_t = default<vec3_t>

var lastlink : efrag_s?? = default<efrag_s??>

var r_addent : entity_s? = default<entity_s?>

[export, sideeffects]
def R_RemoveEfrags(var ent_0 : entity_s?) {
    var ef_0 : efrag_s?
    var old : efrag_s?
    var walk : efrag_s?
    var prev : efrag_s??
    ef_0 = unsafe(reinterpret<efrag_s?>(ent_0.efrag))
    while (ef_0 != null) {
        var c2da_fresh8 : efrag_s?? = unsafe(reinterpret<efrag_s??>(unsafe(reinterpret<uint64>(ef_0.leaf)) + 40ul))
        prev = unsafe(reinterpret<efrag_s??>(c2da_fresh8))
        while (true) {
            walk = unsafe(reinterpret<efrag_s?>(*prev))
            if (walk == null) {
                break
            }
            if (walk == ef_0) {
                *prev = unsafe(reinterpret<efrag_s?>(ef_0.leafnext))
                break
            } else {
                var c2da_fresh9 : efrag_s?? = unsafe(reinterpret<efrag_s??>(unsafe(reinterpret<uint64>(walk)) + 8ul))
                prev = unsafe(reinterpret<efrag_s??>(c2da_fresh9))
            }
        }
        old = unsafe(reinterpret<efrag_s?>(ef_0))
        ef_0 = unsafe(reinterpret<efrag_s?>(ef_0.entnext))
        old.entnext = cl.free_efrags
        cl.free_efrags = unsafe(reinterpret<efrag_s?>(old))
    }
    ent_0.efrag = null
    return
}
[export, sideeffects]
def R_StoreEfrags(var ppefrag : efrag_s??) {
    var c2da_fresh10 : uint
    var pent : entity_s?
    var clmodel : model_s?
    var pefrag : efrag_s?
    while (true) {
        pefrag = unsafe(reinterpret<efrag_s?>(*ppefrag))
        if (pefrag == null) {
            break
        }
        pent = unsafe(reinterpret<entity_s?>(pefrag.entity))
        clmodel = unsafe(reinterpret<model_s?>(pent.model))
        c2da_fresh10 = uint(clmodel.type_0)
        if (c2da_fresh10 == 0x2u || c2da_fresh10 == 0x0u || c2da_fresh10 == 0x1u) {
            pent = unsafe(reinterpret<entity_s?>(pefrag.entity))
            if (pent.visframe != r_framecount && cl_numvisedicts < 256) {
                let c2da_postinc : int = cl_numvisedicts
                cl_numvisedicts = cl_numvisedicts + 1
                cl_visedicts[c2da_postinc] = unsafe(reinterpret<entity_s?>(pent))
                pent.visframe = r_framecount
            }
            var c2da_fresh11 : efrag_s?? = unsafe(reinterpret<efrag_s??>(unsafe(reinterpret<uint64>(pefrag)) + 8ul))
            ppefrag = unsafe(reinterpret<efrag_s??>(c2da_fresh11))
        } else {
            Sys_Error(unsafe(addr<int8?>(c2da_str_r_efrag_1[0])), [C2daVaArg(tag = 1, i64 = int64(uint(clmodel.type_0)), f64 = 0.0lf, raw = 0x0)])
        }
    }
    return
}
[export, sideeffects]
def R_SplitEntityOnNode2(var node_0 : mnode_s?) {
    var splitplane_0 : mplane_s?
    var sides_0 : int
    if (node_0.visframe != r_visframecount) {
        return
    }
    if (node_0.contents < 0) {
        if (node_0.contents != -2) {
            r_pefragtopnode = unsafe(reinterpret<mnode_s?>(node_0))
        }
        return
    }
    splitplane_0 = unsafe(reinterpret<mplane_s?>(node_0.plane))
    sides_0 = int(splitplane_0.type_0) < 3 ? (splitplane_0.dist <= unsafe(unsafe(addr(r_emins[0]))[int(splitplane_0.type_0)]) ? 1 : splitplane_0.dist >= unsafe(unsafe(addr(r_emaxs[0]))[int(splitplane_0.type_0)]) ? 2 : 3) : BoxOnPlaneSide(unsafe(addr<float?>(r_emins[0])), unsafe(addr<float?>(r_emaxs[0])), splitplane_0)
    if (sides_0 == 3) {
        r_pefragtopnode = unsafe(reinterpret<mnode_s?>(node_0))
        return
    }
    if ((sides_0 & 1) != 0) {
        var c2da_fresh12 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node_0)) + 40ul))
        R_SplitEntityOnNode2(unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh12))[0]))))
    } else {
        var c2da_fresh13 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node_0)) + 40ul))
        R_SplitEntityOnNode2(unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh13))[1]))))
    }
    return
}
[sideeffects]
def private c2da_layout_proofs_37() {
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
}
