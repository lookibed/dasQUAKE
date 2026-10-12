var private c2da_str_r_bsp_0 : array<int8> = [int8(110), int8(111), int8(32), int8(101), int8(100), int8(103), int8(101), int8(115), int8(32), int8(105), int8(110), int8(32), int8(98), int8(109), int8(111), int8(100), int8(101), int8(108), int8(0)]

var private c2da_str_r_bsp_1 : array<int8> = [int8(79), int8(117), int8(116), int8(32), int8(111), int8(102), int8(32), int8(101), int8(100), int8(103), int8(101), int8(115), int8(32), int8(102), int8(111), int8(114), int8(32), int8(98), int8(109), int8(111), int8(100), int8(101), int8(108), int8(10), int8(0)]

var currententity : entity_s? = default<entity_s?>

var modelorg : vec3_t = default<vec3_t>

var base_modelorg : vec3_t = default<vec3_t>

[export, sideeffects]
def R_RenderWorld() {
    var i : int
    var clmodel : model_s?
    var btofpolys : btofpoly_s[5000]
    pbtofpolys = unsafe(addr<btofpoly_s?>(btofpolys[0]))
    currententity = unsafe(addr<entity_s?>(unsafe(unsafe(addr(cl_entities[0]))[0])))
    unsafe(unsafe(addr(modelorg[0]))[0]) = unsafe(unsafe(addr(r_origin[0]))[0])
    unsafe(unsafe(addr(modelorg[0]))[1]) = unsafe(unsafe(addr(r_origin[0]))[1])
    unsafe(unsafe(addr(modelorg[0]))[2]) = unsafe(unsafe(addr(r_origin[0]))[2])
    clmodel = unsafe(reinterpret<model_s?>(currententity.model))
    r_pcurrentvertbase = unsafe(reinterpret<mvertex_t?>(clmodel.vertexes))
    R_RecursiveWorldNode(clmodel.nodes, 15)
    if (uint(r_worldpolysbacktofront) != 0u) {
        i = numbtofpolys - 1
        while (i >= 0) {
            R_RenderPoly(btofpolys[i].psurf, btofpolys[i].clipflags)
            i--
        }
    }
    return
}
[export, sideeffects]
def R_RecursiveWorldNode(var node : mnode_s?; var clipflags : int) {
    var c2da_fresh7 : int
    var c : int
    var side : int
    var pindex : int?
    var acceptpt : vec3_t
    var rejectpt : vec3_t
    var plane : mplane_s?
    var surf : msurface_s?
    var mark : msurface_s??
    var pleaf : mleaf_s?
    var d : double
    var dot : double
    if (node.contents == -2) {
        return
    }
    if (node.visframe != r_visframecount) {
        return
    }
    if (clipflags != 0) {
        for (i_0 in range(0, 4)) {
            if ((clipflags & 1 << i_0) == 0) {
                continue
            }
            pindex = unsafe(reinterpret<int?>(pfrustum_indexes[i_0]))
            var c2da_fresh0 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(node)) + 8ul))
            unsafe(unsafe(addr(rejectpt[0]))[0]) = float(unsafe(unsafe(reinterpret<int16?>(c2da_fresh0))[unsafe(pindex[0])]))
            var c2da_fresh1 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(node)) + 8ul))
            unsafe(unsafe(addr(rejectpt[0]))[1]) = float(unsafe(unsafe(reinterpret<int16?>(c2da_fresh1))[unsafe(pindex[1])]))
            var c2da_fresh2 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(node)) + 8ul))
            unsafe(unsafe(addr(rejectpt[0]))[2]) = float(unsafe(unsafe(reinterpret<int16?>(c2da_fresh2))[unsafe(pindex[2])]))
            d = double(unsafe(unsafe(addr(rejectpt[0]))[0]) * unsafe(unsafe(addr(view_clipplanes[i_0].normal[0]))[0]) + unsafe(unsafe(addr(rejectpt[0]))[1]) * unsafe(unsafe(addr(view_clipplanes[i_0].normal[0]))[1]) + unsafe(unsafe(addr(rejectpt[0]))[2]) * unsafe(unsafe(addr(view_clipplanes[i_0].normal[0]))[2]))
            d -= double(view_clipplanes[i_0].dist)
            if (d <= 0.0lf) {
                return
            }
            var c2da_fresh3 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(node)) + 8ul))
            unsafe(unsafe(addr(acceptpt[0]))[0]) = float(unsafe(unsafe(reinterpret<int16?>(c2da_fresh3))[unsafe(pindex[3 + 0])]))
            var c2da_fresh4 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(node)) + 8ul))
            unsafe(unsafe(addr(acceptpt[0]))[1]) = float(unsafe(unsafe(reinterpret<int16?>(c2da_fresh4))[unsafe(pindex[3 + 1])]))
            var c2da_fresh5 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(node)) + 8ul))
            unsafe(unsafe(addr(acceptpt[0]))[2]) = float(unsafe(unsafe(reinterpret<int16?>(c2da_fresh5))[unsafe(pindex[3 + 2])]))
            d = double(unsafe(unsafe(addr(acceptpt[0]))[0]) * unsafe(unsafe(addr(view_clipplanes[i_0].normal[0]))[0]) + unsafe(unsafe(addr(acceptpt[0]))[1]) * unsafe(unsafe(addr(view_clipplanes[i_0].normal[0]))[1]) + unsafe(unsafe(addr(acceptpt[0]))[2]) * unsafe(unsafe(addr(view_clipplanes[i_0].normal[0]))[2]))
            d -= double(view_clipplanes[i_0].dist)
            if (d >= 0.0lf) {
                clipflags &= ~(1 << i_0)
            }
        }
    }
    if (node.contents < 0) {
        pleaf = unsafe(reinterpret<mleaf_s?>(unsafe(reinterpret<mleaf_s?>(node))))
        mark = unsafe(reinterpret<msurface_s??>(pleaf.firstmarksurface))
        c = pleaf.nummarksurfaces
        if (c != 0) {
            while (true) {
                (*mark).visframe = r_framecount
                unsafe {  // nolint:STYLE025
                    mark += 1
                }
                c--
                if (c == 0) {
                    break
                }
            }
        }
        if (pleaf.efrags != null) {
            var c2da_fresh6 : efrag_s?? = unsafe(reinterpret<efrag_s??>(unsafe(reinterpret<uint64>(pleaf)) + 40ul))
            R_StoreEfrags(unsafe(reinterpret<efrag_s??>(c2da_fresh6)))
        }
        pleaf.key = r_currentkey
        r_currentkey = r_currentkey + 1
    } else {
        plane = unsafe(reinterpret<mplane_s?>(node.plane))
        c2da_fresh7 = int(plane.type_0)
        if (c2da_fresh7 == 0) {
            dot = double(unsafe(unsafe(addr(modelorg[0]))[0]) - plane.dist)
        } elif (c2da_fresh7 == 1) {
            dot = double(unsafe(unsafe(addr(modelorg[0]))[1]) - plane.dist)
        } elif (c2da_fresh7 == 2) {
            dot = double(unsafe(unsafe(addr(modelorg[0]))[2]) - plane.dist)
        } else {
            var c2da_fresh8 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane))))
            var c2da_fresh9 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane))))
            var c2da_fresh10 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plane))))
            dot = double(unsafe(unsafe(addr(modelorg[0]))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh8))[0]) + unsafe(unsafe(addr(modelorg[0]))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh9))[1]) + unsafe(unsafe(addr(modelorg[0]))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh10))[2]) - plane.dist)
        }
        if (dot >= 0.0lf) {
            side = 0
        } else {
            side = 1
        }
        var c2da_fresh11 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node)) + 40ul))
        R_RecursiveWorldNode(unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh11))[side]))), clipflags)
        c = int(node.numsurfaces)
        if (c != 0) {
            surf = unsafe(reinterpret<msurface_s?>(unsafe(cl.worldmodel.surfaces + int(node.firstsurface))))
            if (dot < -0.01lf) {
                while (true) {
                    if ((surf.flags & 2) != 0 && surf.visframe == r_framecount) {
                        if (uint(r_drawpolys) != 0u) {
                            if (uint(r_worldpolysbacktofront) != 0u) {
                                if (numbtofpolys < 5000) {
                                    unsafe(pbtofpolys[int(numbtofpolys)]).clipflags = clipflags
                                    unsafe(pbtofpolys[int(numbtofpolys)]).psurf = unsafe(reinterpret<msurface_s?>(surf))
                                    numbtofpolys = numbtofpolys + 1
                                }
                            } else {
                                R_RenderPoly(surf, clipflags)
                            }
                        } else {
                            R_RenderFace(surf, clipflags)
                        }
                    }
                    unsafe {  // nolint:STYLE025
                        surf += 1
                    }
                    c--
                    if (c == 0) {
                        break
                    }
                }
            } elif (dot > 0.01lf) {
                while (true) {
                    if ((surf.flags & 2) == 0 && surf.visframe == r_framecount) {
                        if (uint(r_drawpolys) != 0u) {
                            if (uint(r_worldpolysbacktofront) != 0u) {
                                if (numbtofpolys < 5000) {
                                    unsafe(pbtofpolys[int(numbtofpolys)]).clipflags = clipflags
                                    unsafe(pbtofpolys[int(numbtofpolys)]).psurf = unsafe(reinterpret<msurface_s?>(surf))
                                    numbtofpolys = numbtofpolys + 1
                                }
                            } else {
                                R_RenderPoly(surf, clipflags)
                            }
                        } else {
                            R_RenderFace(surf, clipflags)
                        }
                    }
                    unsafe {  // nolint:STYLE025
                        surf += 1
                    }
                    c--
                    if (c == 0) {
                        break
                    }
                }
            }
            r_currentkey = r_currentkey + 1
        }
        var c2da_fresh12 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(node)) + 40ul))
        R_RecursiveWorldNode(unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh12))[side == 0 ? 1 : 0]))), clipflags)
    }
    return
}
var r_entorigin : vec3_t = default<vec3_t>

var insubmodel : qboolean = default<qboolean>

var r_worldmodelorg : vec3_t = default<vec3_t>

[export, sideeffects]
def R_DrawSubmodelPolygons(var pmodel_0 : model_s?; var clipflags_0 : int) {
    var i_1 : int
    var dot_0 : float
    var psurf : msurface_s?
    var numsurfaces : int
    var pplane : mplane_s?
    psurf = unsafe(addr<msurface_s?>(unsafe(pmodel_0.surfaces[pmodel_0.firstmodelsurface])))
    numsurfaces = pmodel_0.nummodelsurfaces
    i_1 = 0
    while (i_1 < numsurfaces) {
        pplane = unsafe(reinterpret<mplane_s?>(psurf.plane))
        var c2da_fresh13 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane))))
        var c2da_fresh14 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane))))
        var c2da_fresh15 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane))))
        dot_0 = unsafe(unsafe(addr(modelorg[0]))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh13))[0]) + unsafe(unsafe(addr(modelorg[0]))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh14))[1]) + unsafe(unsafe(addr(modelorg[0]))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh15))[2]) - pplane.dist
        if ((psurf.flags & 2) != 0 && double(dot_0) < -0.01lf || (psurf.flags & 2) == 0 && double(dot_0) > 0.01lf) {
            r_currentkey = unsafe(reinterpret<mleaf_s?>(currententity.topnode)).key
            R_RenderFace(psurf, clipflags_0)
        }
        i_1++
        unsafe {  // nolint:STYLE025
            psurf += 1
        }
    }
    return
}
[export, sideeffects]
def R_DrawSolidClippedSubmodelPolygons(var pmodel_1 : model_s?) {
    var i_2 : int
    var j : int
    var lindex : int
    var dot_1 : float
    var psurf_0 : msurface_s?
    var numsurfaces_0 : int
    var pplane_0 : mplane_s?
    var bverts : mvertex_t[500]
    var bedges : bedge_s[1000]
    var pbedge : bedge_s?
    var pedge : medge_t?
    var pedges : medge_t?
    psurf_0 = unsafe(addr<msurface_s?>(unsafe(pmodel_1.surfaces[pmodel_1.firstmodelsurface])))
    numsurfaces_0 = pmodel_1.nummodelsurfaces
    pedges = unsafe(reinterpret<medge_t?>(pmodel_1.edges))
    i_2 = 0
    while (i_2 < numsurfaces_0) {
        pplane_0 = unsafe(reinterpret<mplane_s?>(psurf_0.plane))
        var c2da_fresh16 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane_0))))
        var c2da_fresh17 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane_0))))
        var c2da_fresh18 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pplane_0))))
        dot_1 = unsafe(unsafe(addr(modelorg[0]))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh16))[0]) + unsafe(unsafe(addr(modelorg[0]))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh17))[1]) + unsafe(unsafe(addr(modelorg[0]))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh18))[2]) - pplane_0.dist
        if ((psurf_0.flags & 2) != 0 && double(dot_1) < -0.01lf || (psurf_0.flags & 2) == 0 && double(dot_1) > 0.01lf) {
            pbverts = unsafe(addr<mvertex_t?>(bverts[0]))
            pbedges = unsafe(addr<bedge_s?>(bedges[0]))
            numbedges = 0
            numbverts = int(numbedges)  // nolint:PERF020
            if (psurf_0.numedges > 0) {
                pbedge = unsafe(addr<bedge_s?>(unsafe(unsafe(addr(bedges[0]))[numbedges])))
                numbedges += psurf_0.numedges
                j = 0
                while (j < psurf_0.numedges) {
                    lindex = unsafe(pmodel_1.surfedges[psurf_0.firstedge + j])
                    if (lindex > 0) {
                        pedge = unsafe(addr<medge_t?>(unsafe(pedges[lindex])))
                        var c2da_fresh19 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pedge))))
                        unsafe(unsafe(addr(unsafe(pbedge[j]).v[0]))[0]) = unsafe(addr<mvertex_t?>(unsafe(r_pcurrentvertbase[int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh19))[0]))])))
                        var c2da_fresh20 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pedge))))
                        unsafe(unsafe(addr(unsafe(pbedge[j]).v[0]))[1]) = unsafe(addr<mvertex_t?>(unsafe(r_pcurrentvertbase[int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh20))[1]))])))
                    } else {
                        lindex = -lindex
                        pedge = unsafe(addr<medge_t?>(unsafe(pedges[lindex])))
                        var c2da_fresh21 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pedge))))
                        unsafe(unsafe(addr(unsafe(pbedge[j]).v[0]))[0]) = unsafe(addr<mvertex_t?>(unsafe(r_pcurrentvertbase[int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh21))[1]))])))
                        var c2da_fresh22 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pedge))))
                        unsafe(unsafe(addr(unsafe(pbedge[j]).v[0]))[1]) = unsafe(addr<mvertex_t?>(unsafe(r_pcurrentvertbase[int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh22))[0]))])))
                    }
                    unsafe(pbedge[j]).pnext = unsafe(addr<bedge_s?>(unsafe(pbedge[j + 1])))
                    j++
                }
                unsafe(pbedge[j - 1]).pnext = null
                R_RecursiveClipBPoly(pbedge, currententity.topnode, psurf_0)
            } else {
                Sys_Error(unsafe(addr<int8?>(c2da_str_r_bsp_0[0])), [])
            }
        }
        i_2++
        unsafe {  // nolint:STYLE025
            psurf_0 += 1
        }
    }
    return
}
[export, sideeffects]
def R_RecursiveClipBPoly(var pedges_0 : bedge_s?; var pnode : mnode_s?; var psurf_1 : msurface_s?) {
    var psideedges : bedge_s? [2]
    var pnextedge : bedge_s?
    var ptedge : bedge_s?
    var side_0 : int
    var lastside : int
    var dist : float
    var frac : float
    var lastdist : float
    var splitplane : mplane_s?
    var tplane : mplane_s
    var pvert : mvertex_t?
    var plastvert : mvertex_t?
    var ptvert : mvertex_t?
    var pn : mnode_s?
    psideedges[1] = null
    psideedges[0] = unsafe(reinterpret<bedge_s?>(psideedges[1]))
    makeclippededge = unsafe(reinterpret<qboolean>(0u))
    splitplane = unsafe(reinterpret<mplane_s?>(pnode.plane))
    var c2da_fresh23 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    var c2da_fresh24 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    var c2da_fresh25 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    tplane.dist = splitplane.dist - (unsafe(unsafe(addr(r_entorigin[0]))[0]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh23))[0]) + unsafe(unsafe(addr(r_entorigin[0]))[1]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh24))[1]) + unsafe(unsafe(addr(r_entorigin[0]))[2]) * unsafe(unsafe(reinterpret<float?>(c2da_fresh25))[2]))
    var c2da_fresh26 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    var c2da_fresh27 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    var c2da_fresh28 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    unsafe(unsafe(addr(tplane.normal[0]))[0]) = entity_rotation[0][0] * unsafe(unsafe(reinterpret<float?>(c2da_fresh26))[0]) + entity_rotation[0][1] * unsafe(unsafe(reinterpret<float?>(c2da_fresh27))[1]) + entity_rotation[0][2] * unsafe(unsafe(reinterpret<float?>(c2da_fresh28))[2])
    var c2da_fresh29 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    var c2da_fresh30 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    var c2da_fresh31 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    unsafe(unsafe(addr(tplane.normal[0]))[1]) = entity_rotation[1][0] * unsafe(unsafe(reinterpret<float?>(c2da_fresh29))[0]) + entity_rotation[1][1] * unsafe(unsafe(reinterpret<float?>(c2da_fresh30))[1]) + entity_rotation[1][2] * unsafe(unsafe(reinterpret<float?>(c2da_fresh31))[2])
    var c2da_fresh32 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    var c2da_fresh33 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    var c2da_fresh34 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(splitplane))))
    unsafe(unsafe(addr(tplane.normal[0]))[2]) = entity_rotation[2][0] * unsafe(unsafe(reinterpret<float?>(c2da_fresh32))[0]) + entity_rotation[2][1] * unsafe(unsafe(reinterpret<float?>(c2da_fresh33))[1]) + entity_rotation[2][2] * unsafe(unsafe(reinterpret<float?>(c2da_fresh34))[2])
    while (pedges_0 != null) {
        pnextedge = unsafe(reinterpret<bedge_s?>(pedges_0.pnext))
        var c2da_fresh35 : mvertex_t?? = unsafe(reinterpret<mvertex_t??>(unsafe(reinterpret<uint64>(pedges_0))))
        plastvert = unsafe(reinterpret<mvertex_t?>(unsafe(unsafe(reinterpret<mvertex_t??>(c2da_fresh35))[0])))
        var c2da_fresh36 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plastvert))))
        var c2da_fresh37 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plastvert))))
        var c2da_fresh38 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plastvert))))
        lastdist = unsafe(unsafe(reinterpret<float?>(c2da_fresh36))[0]) * unsafe(unsafe(addr(tplane.normal[0]))[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh37))[1]) * unsafe(unsafe(addr(tplane.normal[0]))[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh38))[2]) * unsafe(unsafe(addr(tplane.normal[0]))[2]) - tplane.dist
        if (lastdist > 0.0) {
            lastside = 0
        } else {
            lastside = 1
        }
        var c2da_fresh39 : mvertex_t?? = unsafe(reinterpret<mvertex_t??>(unsafe(reinterpret<uint64>(pedges_0))))
        pvert = unsafe(reinterpret<mvertex_t?>(unsafe(unsafe(reinterpret<mvertex_t??>(c2da_fresh39))[1])))
        var c2da_fresh40 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pvert))))
        var c2da_fresh41 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pvert))))
        var c2da_fresh42 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pvert))))
        dist = unsafe(unsafe(reinterpret<float?>(c2da_fresh40))[0]) * unsafe(unsafe(addr(tplane.normal[0]))[0]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh41))[1]) * unsafe(unsafe(addr(tplane.normal[0]))[1]) + unsafe(unsafe(reinterpret<float?>(c2da_fresh42))[2]) * unsafe(unsafe(addr(tplane.normal[0]))[2]) - tplane.dist
        if (dist > 0.0) {
            side_0 = 0
        } else {
            side_0 = 1
        }
        if (side_0 != lastside) {
            if (numbverts >= 500) {
                return
            }
            frac = lastdist / (lastdist - dist)
            var c2da_postinc : int = numbverts
            numbverts++
            ptvert = unsafe(addr<mvertex_t?>(unsafe(pbverts[c2da_postinc])))
            var c2da_fresh43 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ptvert))))
            var c2da_fresh44 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plastvert))))
            var c2da_fresh45 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pvert))))
            var c2da_fresh46 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plastvert))))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh43))[0]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh44))[0]) + frac * (unsafe(unsafe(reinterpret<float?>(c2da_fresh45))[0]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh46))[0]))
            var c2da_fresh47 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ptvert))))
            var c2da_fresh48 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plastvert))))
            var c2da_fresh49 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pvert))))
            var c2da_fresh50 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plastvert))))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh47))[1]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh48))[1]) + frac * (unsafe(unsafe(reinterpret<float?>(c2da_fresh49))[1]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh50))[1]))
            var c2da_fresh51 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(ptvert))))
            var c2da_fresh52 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plastvert))))
            var c2da_fresh53 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(pvert))))
            var c2da_fresh54 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(plastvert))))
            unsafe(unsafe(reinterpret<float?>(c2da_fresh51))[2]) = unsafe(unsafe(reinterpret<float?>(c2da_fresh52))[2]) + frac * (unsafe(unsafe(reinterpret<float?>(c2da_fresh53))[2]) - unsafe(unsafe(reinterpret<float?>(c2da_fresh54))[2]))
            if (numbedges >= 1000 - 1) {
                Con_Printf(unsafe(addr<int8?>(c2da_str_r_bsp_1[0])), [])
                return
            }
            ptedge = unsafe(addr<bedge_s?>(unsafe(pbedges[numbedges])))
            ptedge.pnext = psideedges[lastside]
            psideedges[lastside] = unsafe(reinterpret<bedge_s?>(ptedge))
            var c2da_fresh55 : mvertex_t?? = unsafe(reinterpret<mvertex_t??>(unsafe(reinterpret<uint64>(ptedge))))
            unsafe(unsafe(reinterpret<mvertex_t??>(c2da_fresh55))[0]) = unsafe(reinterpret<mvertex_t?>(plastvert))
            var c2da_fresh56 : mvertex_t?? = unsafe(reinterpret<mvertex_t??>(unsafe(reinterpret<uint64>(ptedge))))
            unsafe(unsafe(reinterpret<mvertex_t??>(c2da_fresh56))[1]) = unsafe(reinterpret<mvertex_t?>(ptvert))
            ptedge = unsafe(addr<bedge_s?>(unsafe(pbedges[numbedges + 1])))
            ptedge.pnext = psideedges[side_0]
            psideedges[side_0] = unsafe(reinterpret<bedge_s?>(ptedge))
            var c2da_fresh57 : mvertex_t?? = unsafe(reinterpret<mvertex_t??>(unsafe(reinterpret<uint64>(ptedge))))
            unsafe(unsafe(reinterpret<mvertex_t??>(c2da_fresh57))[0]) = unsafe(reinterpret<mvertex_t?>(ptvert))
            var c2da_fresh58 : mvertex_t?? = unsafe(reinterpret<mvertex_t??>(unsafe(reinterpret<uint64>(ptedge))))
            unsafe(unsafe(reinterpret<mvertex_t??>(c2da_fresh58))[1]) = unsafe(reinterpret<mvertex_t?>(pvert))
            numbedges += 2
            if (side_0 == 0) {
                pfrontenter = unsafe(reinterpret<mvertex_t?>(ptvert))
                makeclippededge = unsafe(reinterpret<qboolean>(1u))
            } else {
                pfrontexit = unsafe(reinterpret<mvertex_t?>(ptvert))
                makeclippededge = unsafe(reinterpret<qboolean>(1u))
            }
        } else {
            pedges_0.pnext = psideedges[side_0]
            psideedges[side_0] = unsafe(reinterpret<bedge_s?>(pedges_0))
        }
        pedges_0 = unsafe(reinterpret<bedge_s?>(pnextedge))
    }
    if (uint(makeclippededge) != 0u) {
        if (numbedges >= 1000 - 2) {
            Con_Printf(unsafe(addr<int8?>(c2da_str_r_bsp_1[0])), [])
            return
        }
        ptedge = unsafe(addr<bedge_s?>(unsafe(pbedges[numbedges])))
        ptedge.pnext = psideedges[0]
        psideedges[0] = unsafe(reinterpret<bedge_s?>(ptedge))
        var c2da_fresh59 : mvertex_t?? = unsafe(reinterpret<mvertex_t??>(unsafe(reinterpret<uint64>(ptedge))))
        unsafe(unsafe(reinterpret<mvertex_t??>(c2da_fresh59))[0]) = unsafe(reinterpret<mvertex_t?>(pfrontexit))
        var c2da_fresh60 : mvertex_t?? = unsafe(reinterpret<mvertex_t??>(unsafe(reinterpret<uint64>(ptedge))))
        unsafe(unsafe(reinterpret<mvertex_t??>(c2da_fresh60))[1]) = unsafe(reinterpret<mvertex_t?>(pfrontenter))
        ptedge = unsafe(addr<bedge_s?>(unsafe(pbedges[numbedges + 1])))
        ptedge.pnext = psideedges[1]
        psideedges[1] = unsafe(reinterpret<bedge_s?>(ptedge))
        var c2da_fresh61 : mvertex_t?? = unsafe(reinterpret<mvertex_t??>(unsafe(reinterpret<uint64>(ptedge))))
        unsafe(unsafe(reinterpret<mvertex_t??>(c2da_fresh61))[0]) = unsafe(reinterpret<mvertex_t?>(pfrontenter))
        var c2da_fresh62 : mvertex_t?? = unsafe(reinterpret<mvertex_t??>(unsafe(reinterpret<uint64>(ptedge))))
        unsafe(unsafe(reinterpret<mvertex_t??>(c2da_fresh62))[1]) = unsafe(reinterpret<mvertex_t?>(pfrontexit))
        numbedges += 2
    }
    for (i_3 in range(0, 2)) {
        if (psideedges[i_3] != null) {
            var c2da_fresh63 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(pnode)) + 40ul))
            pn = unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh63))[i_3])))
            if (pn.visframe == r_visframecount) {
                if (pn.contents < 0) {
                    if (pn.contents != -2) {
                        r_currentbkey = int(unsafe(reinterpret<mleaf_s?>(pn)).key)  // nolint:PERF020
                        R_RenderBmodelFace(unsafe(reinterpret<bedge_s?>(psideedges[i_3])), psurf_1)
                    }
                } else {
                    var c2da_fresh64 : mnode_s?? = unsafe(reinterpret<mnode_s??>(unsafe(reinterpret<uint64>(pnode)) + 40ul))
                    R_RecursiveClipBPoly(unsafe(reinterpret<bedge_s?>(psideedges[i_3])), unsafe(reinterpret<mnode_s?>(unsafe(unsafe(reinterpret<mnode_s??>(c2da_fresh64))[i_3]))), psurf_1)
                }
            }
        }
    }
    return
}
var r_currentbkey : int = default<int>

var private numbedges : int = default<int>

var private pfrontexit : mvertex_t? = default<mvertex_t?>

var private pfrontenter : mvertex_t? = default<mvertex_t?>

var private pbedges : bedge_s? = default<bedge_s?>

var private makeclippededge : qboolean = default<qboolean>

var private numbverts : int = default<int>

var private pbverts : mvertex_t? = default<mvertex_t?>

var entity_rotation : float[3][3]

[export, sideeffects]
def R_RotateBmodel() {
    var angle : float
    var s : float
    var c_0 : float
    var temp1_0 : float[3][3]
    var temp2 : float[3][3]
    var temp3 : float[3][3]
    var c2da_fresh65 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(currententity)) + 124ul))
    angle = unsafe(unsafe(reinterpret<float?>(c2da_fresh65))[1])
    angle = float(double(angle) * 3.141592653589793lf * 2.0lf / 360.0lf)
    s = float(sin(double(angle)))
    c_0 = float(cos(double(angle)))
    temp1_0[0][0] = c_0
    temp1_0[0][1] = s
    temp1_0[0][2] = 0.0
    temp1_0[1][0] = -s
    temp1_0[1][1] = c_0
    temp1_0[1][2] = 0.0
    temp1_0[2][0] = 0.0
    temp1_0[2][1] = 0.0
    temp1_0[2][2] = 1.0
    var c2da_fresh66 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(currententity)) + 124ul))
    angle = unsafe(unsafe(reinterpret<float?>(c2da_fresh66))[0])
    angle = float(double(angle) * 3.141592653589793lf * 2.0lf / 360.0lf)
    s = float(sin(double(angle)))
    c_0 = float(cos(double(angle)))
    temp2[0][0] = c_0
    temp2[0][1] = 0.0
    temp2[0][2] = -s
    temp2[1][0] = 0.0
    temp2[1][1] = 1.0
    temp2[1][2] = 0.0
    temp2[2][0] = s
    temp2[2][1] = 0.0
    temp2[2][2] = c_0
    R_ConcatRotations(unsafe(addr<float[3]?>(temp2[0])), unsafe(addr<float[3]?>(temp1_0[0])), unsafe(addr<float[3]?>(temp3[0])))
    var c2da_fresh67 : float? = unsafe(reinterpret<float?>(unsafe(reinterpret<uint64>(currententity)) + 124ul))
    angle = unsafe(unsafe(reinterpret<float?>(c2da_fresh67))[2])
    angle = float(double(angle) * 3.141592653589793lf * 2.0lf / 360.0lf)
    s = float(sin(double(angle)))
    c_0 = float(cos(double(angle)))
    temp1_0[0][0] = 1.0
    temp1_0[0][1] = 0.0
    temp1_0[0][2] = 0.0
    temp1_0[1][0] = 0.0
    temp1_0[1][1] = c_0
    temp1_0[1][2] = s
    temp1_0[2][0] = 0.0
    temp1_0[2][1] = -s
    temp1_0[2][2] = c_0
    R_ConcatRotations(unsafe(addr<float[3]?>(temp1_0[0])), unsafe(addr<float[3]?>(temp3[0])), unsafe(addr<float[3]?>(entity_rotation[0])))
    R_EntityRotate(unsafe(addr<float?>(modelorg[0])))
    R_EntityRotate(unsafe(addr<float?>(vpn[0])))
    R_EntityRotate(unsafe(addr<float?>(vright[0])))
    R_EntityRotate(unsafe(addr<float?>(vup[0])))
    R_TransformFrustum()
    return
}
[export, sideeffects]
def R_EntityRotate(var vec : float?) {
    var tvec : vec3_t
    unsafe(unsafe(addr(tvec[0]))[0]) = float(unsafe(vec[0]))  // nolint:PERF020
    unsafe(unsafe(addr(tvec[0]))[1]) = float(unsafe(vec[1]))  // nolint:PERF020
    unsafe(unsafe(addr(tvec[0]))[2]) = float(unsafe(vec[2]))  // nolint:PERF020
    unsafe(vec[0]) = entity_rotation[0][0] * unsafe(unsafe(addr(tvec[0]))[0]) + entity_rotation[0][1] * unsafe(unsafe(addr(tvec[0]))[1]) + entity_rotation[0][2] * unsafe(unsafe(addr(tvec[0]))[2])
    unsafe(vec[1]) = entity_rotation[1][0] * unsafe(unsafe(addr(tvec[0]))[0]) + entity_rotation[1][1] * unsafe(unsafe(addr(tvec[0]))[1]) + entity_rotation[1][2] * unsafe(unsafe(addr(tvec[0]))[2])
    unsafe(vec[2]) = entity_rotation[2][0] * unsafe(unsafe(addr(tvec[0]))[0]) + entity_rotation[2][1] * unsafe(unsafe(addr(tvec[0]))[1]) + entity_rotation[2][2] * unsafe(unsafe(addr(tvec[0]))[2])
    return
}
[sideeffects]
def private c2da_layout_proofs_34() {
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
    static_assert(typeinfo sizeof(type<usercmd_t>) == 24, "C layout of usercmd_t: sizeof")
    static_assert(typeinfo alignof(type<usercmd_t>) == 4, "C layout of usercmd_t: alignof")
    static_assert(typeinfo offsetof<viewangles>(type<usercmd_t>) == 0, "C layout of usercmd_t: offsetof viewangles")
    static_assert(typeinfo offsetof<forwardmove>(type<usercmd_t>) == 12, "C layout of usercmd_t: offsetof forwardmove")
    static_assert(typeinfo offsetof<sidemove>(type<usercmd_t>) == 16, "C layout of usercmd_t: offsetof sidemove")
    static_assert(typeinfo offsetof<upmove>(type<usercmd_t>) == 20, "C layout of usercmd_t: offsetof upmove")
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
    static_assert(typeinfo sizeof(type<bedge_s>) == 24, "C layout of bedge_s: sizeof")
    static_assert(typeinfo alignof(type<bedge_s>) == 8, "C layout of bedge_s: alignof")
    static_assert(typeinfo offsetof<v>(type<bedge_s>) == 0, "C layout of bedge_s: offsetof v")
    static_assert(typeinfo offsetof<pnext>(type<bedge_s>) == 16, "C layout of bedge_s: offsetof pnext")
    static_assert(typeinfo sizeof(type<bedge_t>) == 24, "C layout of bedge_t: sizeof")
    static_assert(typeinfo alignof(type<bedge_t>) == 8, "C layout of bedge_t: alignof")
    static_assert(typeinfo offsetof<v>(type<bedge_t>) == 0, "C layout of bedge_t: offsetof v")
    static_assert(typeinfo offsetof<pnext>(type<bedge_t>) == 16, "C layout of bedge_t: offsetof pnext")
    static_assert(typeinfo sizeof(type<clipplane_s>) == 32, "C layout of clipplane_s: sizeof")
    static_assert(typeinfo alignof(type<clipplane_s>) == 8, "C layout of clipplane_s: alignof")
    static_assert(typeinfo offsetof<normal>(type<clipplane_s>) == 0, "C layout of clipplane_s: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<clipplane_s>) == 12, "C layout of clipplane_s: offsetof dist")
    static_assert(typeinfo offsetof<next>(type<clipplane_s>) == 16, "C layout of clipplane_s: offsetof next")
    static_assert(typeinfo offsetof<leftedge>(type<clipplane_s>) == 24, "C layout of clipplane_s: offsetof leftedge")
    static_assert(typeinfo offsetof<rightedge>(type<clipplane_s>) == 25, "C layout of clipplane_s: offsetof rightedge")
    static_assert(typeinfo offsetof<reserved>(type<clipplane_s>) == 26, "C layout of clipplane_s: offsetof reserved")
    static_assert(typeinfo sizeof(type<clipplane_t>) == 32, "C layout of clipplane_t: sizeof")
    static_assert(typeinfo alignof(type<clipplane_t>) == 8, "C layout of clipplane_t: alignof")
    static_assert(typeinfo offsetof<normal>(type<clipplane_t>) == 0, "C layout of clipplane_t: offsetof normal")
    static_assert(typeinfo offsetof<dist>(type<clipplane_t>) == 12, "C layout of clipplane_t: offsetof dist")
    static_assert(typeinfo offsetof<next>(type<clipplane_t>) == 16, "C layout of clipplane_t: offsetof next")
    static_assert(typeinfo offsetof<leftedge>(type<clipplane_t>) == 24, "C layout of clipplane_t: offsetof leftedge")
    static_assert(typeinfo offsetof<rightedge>(type<clipplane_t>) == 25, "C layout of clipplane_t: offsetof rightedge")
    static_assert(typeinfo offsetof<reserved>(type<clipplane_t>) == 26, "C layout of clipplane_t: offsetof reserved")
    static_assert(typeinfo sizeof(type<btofpoly_t>) == 16, "C layout of btofpoly_t: sizeof")
    static_assert(typeinfo alignof(type<btofpoly_t>) == 8, "C layout of btofpoly_t: alignof")
    static_assert(typeinfo offsetof<clipflags>(type<btofpoly_t>) == 0, "C layout of btofpoly_t: offsetof clipflags")
    static_assert(typeinfo offsetof<psurf>(type<btofpoly_t>) == 8, "C layout of btofpoly_t: offsetof psurf")
    static_assert(typeinfo sizeof(type<btofpoly_s>) == 16, "C layout of btofpoly_s: sizeof")
    static_assert(typeinfo alignof(type<btofpoly_s>) == 8, "C layout of btofpoly_s: alignof")
    static_assert(typeinfo offsetof<clipflags>(type<btofpoly_s>) == 0, "C layout of btofpoly_s: offsetof clipflags")
    static_assert(typeinfo offsetof<psurf>(type<btofpoly_s>) == 8, "C layout of btofpoly_s: offsetof psurf")
}
