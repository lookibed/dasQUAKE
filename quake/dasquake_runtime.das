options gen2
options solid_context = true
options stack = 4194304
module dasquake_runtime public

require strings
require daslib/fio
var c2da_rt_heap : array<uint8>

var c2da_rt_locals : array<uint64>

var c2da_rt_next : uint64 = 0x0

var c2da_rt_alloc_addrs : array<uint64>

var c2da_rt_alloc_sizes : array<uint64>

var c2da_rt_alloc_live : array<bool>

var c2da_rt_alloc_free : array<int>

[sideeffects]
def c2da_rt_init_heap() {
    if (empty(c2da_rt_heap)) {
        reserve(c2da_rt_heap, 1073741824l)
        resize(c2da_rt_heap, 1)
    }
}
[sideeffects]
def c2da_rt_reset() {
    c2da_rt_next = 0x0
    resize(c2da_rt_alloc_addrs, 0)
    resize(c2da_rt_alloc_sizes, 0)
    resize(c2da_rt_alloc_live, 0)
    resize(c2da_rt_alloc_free, 0)
}
[sideeffects]
def c2da_rt_find_record(address : uint64) : int {
    var lo : int = 0
    var hi : int = length(c2da_rt_alloc_addrs)
    while (lo < hi) {
        let mid : int = (lo + hi) / 2
        if (c2da_rt_alloc_addrs[mid] < address) {
            lo = mid + 1
        } else {
            hi = mid
        }
    }
    if (lo < length(c2da_rt_alloc_addrs) && c2da_rt_alloc_addrs[lo] == address) {
        return lo
    }
    return -1
}
[sideeffects]
def c2da_rt_take_free(need : uint64) : int {
    var best : int = -1
    var best_slot : int = -1
    var slot : int = length(c2da_rt_alloc_free) - 1
    while (slot >= 0) {
        let record : int = c2da_rt_alloc_free[slot]
        let capacity : uint64 = c2da_rt_alloc_sizes[record]
        if (capacity >= need && capacity - need <= need) {
            if (best < 0 || capacity < c2da_rt_alloc_sizes[best]) {
                best = record
                best_slot = slot
            }
            if (capacity == need) {
                break
            }
        }
        slot--
    }
    if (best >= 0) {
        c2da_rt_alloc_free[best_slot] = int(c2da_rt_alloc_free[length(c2da_rt_alloc_free) - 1])  // nolint:PERF020
        pop(c2da_rt_alloc_free)
    }
    return best
}
[sideeffects]
def c2da_rt_malloc(size : uint64) : uint64 {
    c2da_rt_init_heap()
    if (size == 0x0 || size > 0x40000000) {
        return 0x0
    }
    let need : uint64 = (size + 0xf) / 0x10 * 0x10
    let reused : int = c2da_rt_take_free(need)
    if (reused >= 0) {
        c2da_rt_alloc_live[reused] = true
        return c2da_rt_alloc_addrs[reused]
    }
    let base : uint64 = unsafe(intptr(unsafe(addr(c2da_rt_heap[0x0]))))
    let start : uint64 = (base + c2da_rt_next + 0xf) / 0x10 * 0x10 - base
    let end : uint64 = start + need
    if (end > 0x40000000) {
        return 0x0
    }
    if (int64(end) > long_length(c2da_rt_heap)) {
        resize(c2da_rt_heap, int64(end))
    }
    c2da_rt_next = end
    let address : uint64 = unsafe(intptr(unsafe(addr(c2da_rt_heap[start]))))
    let record : uint64 = uint64(long_length(c2da_rt_alloc_addrs))
    resize(c2da_rt_alloc_addrs, int64(record + 0x1))
    resize(c2da_rt_alloc_sizes, int64(record + 0x1))
    resize(c2da_rt_alloc_live, int64(record + 0x1))
    c2da_rt_alloc_addrs[record] = address
    c2da_rt_alloc_sizes[record] = need
    c2da_rt_alloc_live[record] = true
    return address
}
[sideeffects]
def c2da_rt_free(address : uint64) {
    let record : int = c2da_rt_find_record(address)
    if (record >= 0 && c2da_rt_alloc_live[record]) {
        c2da_rt_alloc_live[record] = false
        push(c2da_rt_alloc_free, record)
    }
}
[sideeffects]
def c2da_rt_realloc(address : uint64; size : uint64) : uint64 {
    if (address == 0x0) {
        return c2da_rt_malloc(size)
    }
    if (size == 0x0) {
        c2da_rt_free(address)
        return 0x0
    }
    let record : int = c2da_rt_find_record(address)
    if (record < 0 || !c2da_rt_alloc_live[record]) {
        return 0x0
    }
    let capacity : uint64 = c2da_rt_alloc_sizes[record]
    if (size <= capacity) {
        return address
    }
    if (size > 0x40000000) {
        return 0x0
    }
    let need : uint64 = (size + 0xf) / 0x10 * 0x10
    let start : uint64 = address - unsafe(intptr(unsafe(addr(c2da_rt_heap[0x0]))))
    let end : uint64 = start + need
    if (start + capacity == c2da_rt_next && end <= 0x40000000) {
        if (int64(end) > long_length(c2da_rt_heap)) {
            resize(c2da_rt_heap, int64(end))
        }
        c2da_rt_next = end
        c2da_rt_alloc_sizes[record] = need
        return address
    }
    let replacement : uint64 = c2da_rt_malloc(size)
    if (replacement == 0x0) {
        return 0x0
    }
    c2da_rt_memcpy(replacement, address, capacity)
    c2da_rt_free(address)
    return replacement
}
[sideeffects]
def c2da_rt_memset(dst : uint64; value : uint8; count : uint64) : uint64 {
    var done : uint64 = 0x0
    while (done < count) {
        let chunk : uint64 = count - done < 0x40000000ul ? count - done : 0x40000000ul
        unsafe(memset8(unsafe(reinterpret<void?>(dst + done)), value, int(chunk)))
        done += chunk
    }
    return dst
}
[sideeffects]
def c2da_rt_calloc(count : uint64; size : uint64) : uint64 {
    let total : uint64 = count * size
    if (size != 0x0 && total / size != count) {
        return 0x0
    }
    let address : uint64 = c2da_rt_malloc(total)
    if (address != 0x0) {
        c2da_rt_memset(address, 0x0u8, total)
    }
    return address
}
[sideeffects]
def c2da_rt_memcpy(dst : uint64; src : uint64; count : uint64) : uint64 {
    var i : uint64 = 0x0
    while (i < count) {
        unsafe(unsafe(reinterpret<uint8?>(dst))[i]) = uint8(unsafe(unsafe(reinterpret<uint8?>(src))[i]))  // nolint:PERF020
        i = i + 0x1
    }
    return dst
}
[sideeffects]
def c2da_rt_memcmp(left : uint64; right : uint64; count : uint64) : int {
    var i : uint64 = 0x0
    while (i < count) {
        if (uint(unsafe(unsafe(reinterpret<uint8?>(left))[i])) < uint(unsafe(unsafe(reinterpret<uint8?>(right))[i]))) {
            return -1
        }
        if (uint(unsafe(unsafe(reinterpret<uint8?>(left))[i])) > uint(unsafe(unsafe(reinterpret<uint8?>(right))[i]))) {
            return 1
        }
        i = i + 0x1
    }
    return 0
}
[sideeffects]
def c2da_rt_memmove(dst : uint64; src : uint64; count : uint64) : uint64 {
    if (dst < src) {
        var i : uint64 = 0x0
        while (i < count) {
            unsafe(unsafe(reinterpret<uint8?>(dst))[i]) = uint8(unsafe(unsafe(reinterpret<uint8?>(src))[i]))  // nolint:PERF020
            i = i + 0x1
        }
    } else {
        var i : uint64 = count
        while (i > 0x0) {
            i = i - 0x1
            unsafe(unsafe(reinterpret<uint8?>(dst))[i]) = uint8(unsafe(unsafe(reinterpret<uint8?>(src))[i]))  // nolint:PERF020
        }
    }
    return dst
}
[sideeffects]
def c2da_rt_memchr(src : uint64; value : uint8; count : uint64) : uint64 {
    var i : uint64 = 0x0
    while (i < count) {
        if (unsafe(unsafe(reinterpret<uint8?>(src))[i]) == value) {
            return src + i
        }
        i = i + 0x1
    }
    return 0x0
}
[sideeffects]
def c2da_rt_frame_enter() : int {
    return length(c2da_rt_locals)
}
[sideeffects]
def c2da_rt_frame_leave(mark : int) {
    while (length(c2da_rt_locals) > mark) {
        c2da_rt_free(c2da_rt_locals[length(c2da_rt_locals) - 1])
        pop(c2da_rt_locals)
    }
}
[sideeffects]
def c2da_rt_local(size : uint64; align : uint64) : uint64 {
    let address = c2da_rt_calloc(0x1ul, size + 0x1)
    if (address == 0x0) {
        panic("c2da runtime: the 1073741824-byte heap reserve cannot hold storage for a C local")
    }
    push(c2da_rt_locals, address)
    return address
}
[sideeffects]
def c2da_rt_static(size : uint64; align : uint64) : uint64 {
    let address = c2da_rt_calloc(0x1ul, size + 0x1)
    if (address == 0x0) {
        panic("c2da runtime: the 1073741824-byte heap reserve cannot hold storage for a C static object")
    }
    return address
}
struct C2daVaArg {
    tag : int
    i64 : int64
    f64 : double
    raw : uint64
}
struct C2daVaCursor {
    index : int
}
[sideeffects]
def c2da_clip_uint(v : int) : uint {
    if (v < 0) {
        return 0x0
    }
    if (v > 255) {
        return 0xff
    }
    return uint(v)
}
[sideeffects]
def c2da_bool_to_uint(v : bool) : uint {
    if (v) {
        return 0x1
    } else {
        return 0x0
    }
}
[sideeffects]
def c2da___assert_fail(expr : void?; file : void?; line : uint; func : void?) {
}
typedef byte = uint8
enum qboolean : uint {
    false_0 = 0
    true_0 = 1
}
typedef size_t = uint64
struct link_s {
    prev : link_s?
    next : link_s?
}
struct link_t {
    prev : link_s?
    next : link_s?
}
struct cache_user_s {
    data : uint8?
}
struct cvar_s {
    name : int8?
    string_0 : int8?
    archive : qboolean
    server : qboolean
    value : float
    next : cvar_s?
}
struct dmodel_t {
    mins : float[3]
    maxs : float[3]
    origin : float[3]
    headnode : int[4]
    visleafs : int
    firstface : int
    numfaces : int
}
struct dclipnode_t {
    planenum : int
    children : int16[2]
}
struct vrect_s {
    x : int
    y : int
    width : int
    height : int
    pnext : vrect_s?
}
struct vrect_t {
    x : int
    y : int
    width : int
    height : int
    pnext : vrect_s?
}
struct cache_user_t {
    data : uint8?
}
typedef vec_t = float
typedef vec3_t = float[3]
struct mplane_s {
    normal : vec3_t
    dist : float
    type_0 : uint8
    signbits : uint8
    pad : uint8[2]
}
struct entity_state_t {
    origin : vec3_t
    angles : vec3_t
    modelindex : int
    frame : int
    colormap : int
    skin : int
    effects : int
}
struct cvar_t {
    name : int8?
    string_0 : int8?
    archive : qboolean
    server : qboolean
    value : float
    next : cvar_s?
}
struct sfx_s {
    name : int8[64]
    cache : cache_user_s
}
struct efrag_s {
    leaf : mleaf_s?
    leafnext : efrag_s?
    entity : entity_s?
    entnext : efrag_s?
}
struct entity_s {
    forcelink : qboolean
    update_type : int
    baseline : entity_state_t
    msgtime : double
    msg_origins : vec3_t[2]
    origin : vec3_t
    msg_angles : vec3_t[2]
    angles : vec3_t
    model : model_s?
    efrag : efrag_s?
    frame : int
    syncbase : float
    colormap : uint8?
    effects : int
    skinnum : int
    visframe : int
    dlightframe : int
    dlightbits : int
    trivial_accept : int
    topnode : mnode_s?
}
struct mnode_s {
    contents : int
    visframe : int
    minmaxs : int16[6]
    parent : mnode_s?
    plane : mplane_s?
    children : mnode_s? [2]
    firstsurface : uint16
    numsurfaces : uint16
}
struct mplane_t {
    normal : vec3_t
    dist : float
    type_0 : uint8
    signbits : uint8
    pad : uint8[2]
}
struct hull_t {
    clipnodes : dclipnode_t?
    planes : mplane_s?
    firstclipnode : int
    lastclipnode : int
    clip_mins : vec3_t
    clip_maxs : vec3_t
}
enum synctype_t : uint {
    ST_SYNC = 0
    ST_RAND = 1
}
enum modtype_t : uint {
    mod_brush = 0
    mod_sprite = 1
    mod_alias = 2
}
struct model_s {
    name : int8[64]
    needload : qboolean
    type_0 : modtype_t
    numframes : int
    synctype : synctype_t
    flags : int
    mins : vec3_t
    maxs : vec3_t
    radius : float
    firstmodelsurface : int
    nummodelsurfaces : int
    numsubmodels : int
    submodels : dmodel_t?
    numplanes : int
    planes : mplane_s?
    numleafs : int
    leafs : mleaf_s?
    numvertexes : int
    vertexes : mvertex_t?
    numedges : int
    edges : medge_t?
    numnodes : int
    nodes : mnode_s?
    numtexinfo : int
    texinfo : mtexinfo_t?
    numsurfaces : int
    surfaces : msurface_s?
    numsurfedges : int
    surfedges : int?
    numclipnodes : int
    clipnodes : dclipnode_t?
    nummarksurfaces : int
    marksurfaces : msurface_s??
    hulls : hull_t[4]
    numtextures : int
    textures : texture_s??
    visdata : uint8?
    lightdata : uint8?
    entities : int8?
    cache : cache_user_s
}
struct texture_t {
    name : int8[16]
    width : uint
    height : uint
    anim_total : int
    anim_min : int
    anim_max : int
    anim_next : texture_s?
    alternate_anims : texture_s?
    offsets : uint[4]
}
struct texture_s {
    name : int8[16]
    width : uint
    height : uint
    anim_total : int
    anim_min : int
    anim_max : int
    anim_next : texture_s?
    alternate_anims : texture_s?
    offsets : uint[4]
}
struct msurface_t {
    visframe : int
    dlightframe : int
    dlightbits : int
    plane : mplane_s?
    flags : int
    firstedge : int
    numedges : int
    cachespots : surfcache_s? [4]
    texturemins : int16[2]
    extents : int16[2]
    texinfo : mtexinfo_t?
    styles : uint8[4]
    samples : uint8?
}
struct msurface_s {
    visframe : int
    dlightframe : int
    dlightbits : int
    plane : mplane_s?
    flags : int
    firstedge : int
    numedges : int
    cachespots : surfcache_s? [4]
    texturemins : int16[2]
    extents : int16[2]
    texinfo : mtexinfo_t?
    styles : uint8[4]
    samples : uint8?
}
struct mtexinfo_t {
    vecs : float[2][4]
    mipadjust : float
    texture : texture_s?
    flags : int
}
struct surfcache_s {
    next : surfcache_s?
    owner : surfcache_s??
    lightadj : int[4]
    dlight : int
    size : int
    width : uint
    height : uint
    mipscale : float
    texture : texture_s?
    data : uint8[4]
}
struct mnode_t {
    contents : int
    visframe : int
    minmaxs : int16[6]
    parent : mnode_s?
    plane : mplane_s?
    children : mnode_s? [2]
    firstsurface : uint16
    numsurfaces : uint16
}
struct medge_t {
    v : uint16[2]
    cachededgeoffset : uint
}
struct mvertex_t {
    position : vec3_t
}
struct mleaf_t {
    contents : int
    visframe : int
    minmaxs : int16[6]
    parent : mnode_s?
    compressed_vis : uint8?
    efrags : efrag_s?
    firstmarksurface : msurface_s??
    nummarksurfaces : int
    key : int
    ambient_sound_level : uint8[4]
}
struct mleaf_s {
    contents : int
    visframe : int
    minmaxs : int16[6]
    parent : mnode_s?
    compressed_vis : uint8?
    efrags : efrag_s?
    firstmarksurface : msurface_s??
    nummarksurfaces : int
    key : int
    ambient_sound_level : uint8[4]
}
struct efrag_t {
    leaf : mleaf_s?
    leafnext : efrag_s?
    entity : entity_s?
    entnext : efrag_s?
}
struct entity_t {
    forcelink : qboolean
    update_type : int
    baseline : entity_state_t
    msgtime : double
    msg_origins : vec3_t[2]
    origin : vec3_t
    msg_angles : vec3_t[2]
    angles : vec3_t
    model : model_s?
    efrag : efrag_s?
    frame : int
    syncbase : float
    colormap : uint8?
    effects : int
    skinnum : int
    visframe : int
    dlightframe : int
    dlightbits : int
    trivial_accept : int
    topnode : mnode_s?
}
struct refdef_t {
    vrect : vrect_s
    aliasvrect : vrect_s
    vrectright : int
    vrectbottom : int
    aliasvrectright : int
    aliasvrectbottom : int
    vrectrightedge : float
    fvrectx : float
    fvrecty : float
    fvrectx_adj : float
    fvrecty_adj : float
    vrect_x_adj_shift20 : int
    vrectright_adj_shift20 : int
    fvrectright_adj : float
    fvrectbottom_adj : float
    fvrectright : float
    fvrectbottom : float
    horizontalFieldOfView : float
    xOrigin : float
    yOrigin : float
    vieworg : vec3_t
    viewangles : vec3_t
    fov_x : float
    fov_y : float
    ambientlight : int
}
struct usercmd_t {
    viewangles : vec3_t
    forwardmove : float
    sidemove : float
    upmove : float
}
struct scoreboard_t {
    name : int8[32]
    entertime : float
    frags : int
    colors : int
    translations : uint8[16384]
}
struct cshift_t {
    destcolor : int[3]
    percent : int
}
struct client_state_t {
    movemessages : int
    cmd : usercmd_t
    stats : int[32]
    items : int
    item_gettime : float[32]
    faceanimtime : float
    cshifts : cshift_t[4]
    prev_cshifts : cshift_t[4]
    mviewangles : vec3_t[2]
    viewangles : vec3_t
    mvelocity : vec3_t[2]
    velocity : vec3_t
    punchangle : vec3_t
    idealpitch : float
    pitchvel : float
    nodrift : qboolean
    driftmove : float
    laststop : double
    viewheight : float
    crouch : float
    paused : qboolean
    onground : qboolean
    inwater : qboolean
    intermission : int
    completed_time : int
    mtime : double[2]
    time : double
    oldtime : double
    last_received_message : float
    model_precache : model_s? [256]
    sound_precache : sfx_s? [256]
    levelname : int8[40]
    viewentity : int
    maxclients : int
    gametype : int
    worldmodel : model_s?
    free_efrags : efrag_s?
    num_entities : int
    num_statics : int
    viewent : entity_s
    cdtrack : int
    looptrack : int
    scores : scoreboard_t?
}
typedef func_t = int
typedef string_t = int
struct entvars_t {
    modelindex : float
    absmin : vec3_t
    absmax : vec3_t
    ltime : float
    movetype : float
    solid : float
    origin : vec3_t
    oldorigin : vec3_t
    velocity : vec3_t
    angles : vec3_t
    avelocity : vec3_t
    punchangle : vec3_t
    classname : int
    model : int
    frame : float
    skin : float
    effects : float
    mins : vec3_t
    maxs : vec3_t
    size : vec3_t
    touch : int
    use : int
    think : int
    blocked : int
    nextthink : float
    groundentity : int
    health : float
    frags : float
    weapon : float
    weaponmodel : int
    weaponframe : float
    currentammo : float
    ammo_shells : float
    ammo_nails : float
    ammo_rockets : float
    ammo_cells : float
    items : float
    takedamage : float
    chain : int
    deadflag : float
    view_ofs : vec3_t
    button0 : float
    button1 : float
    button2 : float
    impulse : float
    fixangle : float
    v_angle : vec3_t
    idealpitch : float
    netname : int
    enemy : int
    flags : float
    colormap : float
    team : float
    max_health : float
    teleport_time : float
    armortype : float
    armorvalue : float
    waterlevel : float
    watertype : float
    ideal_yaw : float
    yaw_speed : float
    aiment : int
    goalentity : int
    spawnflags : float
    target : int
    targetname : int
    dmg_take : float
    dmg_save : float
    dmg_inflictor : int
    owner : int
    movedir : vec3_t
    message : int
    sounds : float
    noise : int
    noise1 : int
    noise2 : int
    noise3 : int
}
struct edict_s {
    free : qboolean
    area : link_s
    num_leafs : int
    leafnums : int16[16]
    baseline : entity_state_t
    freetime : float
    v : entvars_t
}
struct edict_t {
    free : qboolean
    area : link_s
    num_leafs : int
    leafnums : int16[16]
    baseline : entity_state_t
    freetime : float
    v : entvars_t
}
struct plane_t {
    normal : vec3_t
    dist : float
}
struct trace_t {
    allsolid : qboolean
    startsolid : qboolean
    inopen : qboolean
    inwater : qboolean
    fraction : float
    endpos : vec3_t
    plane : plane_t
    ent : edict_s?
}
struct _IO_FILE {
    _flags : int
    _IO_read_ptr : int8?
    _IO_read_end : int8?
    _IO_read_base : int8?
    _IO_write_base : int8?
    _IO_write_ptr : int8?
    _IO_write_end : int8?
    _IO_buf_base : int8?
    _IO_buf_end : int8?
    _IO_save_base : int8?
    _IO_backup_base : int8?
    _IO_save_end : int8?
    _markers : _IO_marker?
    _chain : _IO_FILE?
    _fileno : int
    _flags2 : int
    _old_offset : int64
    _cur_column : uint16
    _vtable_offset : int8
    _shortbuf : int8[1]
    _lock : uint8?
    _offset : int64
    _codecvt : _IO_codecvt?
    _wide_data : _IO_wide_data?
    _freeres_list : _IO_FILE?
    _freeres_buf : uint8?
    c2da___pad5 : uint64
    _mode : int
    _unused2 : int8[20]
}
struct _IO_wide_data {
}
struct _IO_codecvt {
}
typedef _IO_lock_t = void
struct _IO_marker {
}
struct FILE_0 {
    _flags : int
    _IO_read_ptr : int8?
    _IO_read_end : int8?
    _IO_read_base : int8?
    _IO_write_base : int8?
    _IO_write_ptr : int8?
    _IO_write_end : int8?
    _IO_buf_base : int8?
    _IO_buf_end : int8?
    _IO_save_base : int8?
    _IO_backup_base : int8?
    _IO_save_end : int8?
    _markers : _IO_marker?
    _chain : _IO_FILE?
    _fileno : int
    _flags2 : int
    _old_offset : int64
    _cur_column : uint16
    _vtable_offset : int8
    _shortbuf : int8[1]
    _lock : uint8?
    _offset : int64
    _codecvt : _IO_codecvt?
    _wide_data : _IO_wide_data?
    _freeres_list : _IO_FILE?
    _freeres_buf : uint8?
    c2da___pad5 : uint64
    _mode : int
    _unused2 : int8[20]
}
struct sizebuf_s {
    allowoverflow : qboolean
    overflowed : qboolean
    data : uint8?
    maxsize : int
    cursize : int
}
struct sizebuf_t {
    allowoverflow : qboolean
    overflowed : qboolean
    data : uint8?
    maxsize : int
    cursize : int
}
struct qsockaddr {
    sa_family : int16
    sa_data : uint8[14]
}
struct qsocket_s {
    next : qsocket_s?
    connecttime : double
    lastMessageTime : double
    lastSendTime : double
    disconnected : qboolean
    canSend : qboolean
    sendNext : qboolean
    driver : int
    landriver : int
    socket : int
    driverdata : uint8?
    ackSequence : uint
    sendSequence : uint
    unreliableSendSequence : uint
    sendMessageLength : int
    sendMessage : uint8[8192]
    receiveSequence : uint
    unreliableReceiveSequence : uint
    receiveMessageLength : int
    receiveMessage : uint8[8192]
    addr_0 : qsockaddr
    address : int8[64]
}
enum cmd_source_t : uint {
    src_client = 0
    src_command = 1
}
enum cactive_t : uint {
    ca_dedicated = 0
    ca_disconnected = 1
    ca_connected = 2
}
struct client_static_t {
    state : cactive_t
    mapstring : int8[64]
    spawnparms : int8[2048]
    demonum : int
    demos : int8[8][16]
    demorecording : qboolean
    demoplayback : qboolean
    timedemo : qboolean
    forcetrack : int
    demofile : _IO_FILE?
    td_lastframe : int
    td_startframe : int
    td_starttime : float
    signon : int
    netcon : qsocket_s?
    message : sizebuf_s
}
typedef xcommand_t = function<():void>
struct kbutton_t {
    down : int[2]
    state : int
}
struct qsocket_t {
    next : qsocket_s?
    connecttime : double
    lastMessageTime : double
    lastSendTime : double
    disconnected : qboolean
    canSend : qboolean
    sendNext : qboolean
    driver : int
    landriver : int
    socket : int
    driverdata : uint8?
    ackSequence : uint
    sendSequence : uint
    unreliableSendSequence : uint
    sendMessageLength : int
    sendMessage : uint8[8192]
    receiveSequence : uint
    unreliableReceiveSequence : uint
    receiveMessageLength : int
    receiveMessage : uint8[8192]
    addr_0 : qsockaddr
    address : int8[64]
}
struct lightstyle_t {
    length : int
    map : int8[64]
}
struct dlight_t {
    origin : vec3_t
    radius : float
    die : float
    decay : float
    minlight : float
    key : int
}
struct beam_t {
    entity : int
    model : model_s?
    endtime : float
    start : vec3_t
    end : vec3_t
}
enum server_state_t : uint {
    ss_loading = 0
    ss_active = 1
}
struct server_t {
    active : qboolean
    paused : qboolean
    loadgame : qboolean
    time : double
    lastcheck : int
    lastchecktime : double
    name : int8[64]
    modelname : int8[64]
    worldmodel : model_s?
    model_precache : int8? [256]
    models : model_s? [256]
    sound_precache : int8? [256]
    lightstyles : int8? [64]
    num_edicts : int
    max_edicts : int
    edicts : edict_s?
    state : server_state_t
    datagram : sizebuf_s
    datagram_buf : uint8[1024]
    reliable_datagram : sizebuf_s
    reliable_datagram_buf : uint8[1024]
    signon : sizebuf_s
    signon_buf : uint8[8192]
}
typedef pixel_t = uint8
struct viddef_t {
    buffer : uint8?
    colormap : uint8?
    colormap16 : uint16?
    fullbright : int
    rowbytes : uint
    width : uint
    height : uint
    aspect : float
    numpages : int
    recalc_refdef : int
    conbuffer : uint8?
    conrowbytes : int
    conwidth : uint
    conheight : uint
    maxwarpwidth : int
    maxwarpheight : int
    direct : uint8?
}
struct sfx_t {
    name : int8[64]
    cache : cache_user_s
}
struct model_t {
    name : int8[64]
    needload : qboolean
    type_0 : modtype_t
    numframes : int
    synctype : synctype_t
    flags : int
    mins : vec3_t
    maxs : vec3_t
    radius : float
    firstmodelsurface : int
    nummodelsurfaces : int
    numsubmodels : int
    submodels : dmodel_t?
    numplanes : int
    planes : mplane_s?
    numleafs : int
    leafs : mleaf_s?
    numvertexes : int
    vertexes : mvertex_t?
    numedges : int
    edges : medge_t?
    numnodes : int
    nodes : mnode_s?
    numtexinfo : int
    texinfo : mtexinfo_t?
    numsurfaces : int
    surfaces : msurface_s?
    numsurfedges : int
    surfedges : int?
    numclipnodes : int
    clipnodes : dclipnode_t?
    nummarksurfaces : int
    marksurfaces : msurface_s??
    hulls : hull_t[4]
    numtextures : int
    textures : texture_s??
    visdata : uint8?
    lightdata : uint8?
    entities : int8?
    cache : cache_user_s
}
struct cmdalias_t {
    next : cmdalias_s?
    name : int8[32]
    value : int8?
}
struct cmdalias_s {
    next : cmdalias_s?
    name : int8[32]
    value : int8?
}
struct cmd_function_t {
    next : cmd_function_s?
    name : int8?
    function_0 : xcommand_t
}
struct cmd_function_s {
    next : cmd_function_s?
    name : int8?
    function_0 : xcommand_t
}
struct c2da___va_list_tag {
    gp_offset : uint
    fp_offset : uint
    overflow_arg_area : uint8?
    reg_save_area : uint8?
}
typedef va_list = c2da___va_list_tag[1]
typedef intptr_t = int64
struct Unnamed_common_563 {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 4ul)
}
struct Unnamed_common_679 {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 4ul)
}
struct pack_t {
    filename : int8[128]
    handle : int
    numfiles : int
    files : packfile_t?
}
struct pack_s {
    filename : int8[128]
    handle : int
    numfiles : int
    files : packfile_t?
}
struct packfile_t {
    name : int8[64]
    filepos : int
    filelen : int
}
struct searchpath_t {
    filename : int8[128]
    pack : pack_s?
    next : searchpath_s?
}
struct searchpath_s {
    filename : int8[128]
    pack : pack_s?
    next : searchpath_s?
}
struct dpackfile_t {
    name : int8[56]
    filepos : int
    filelen : int
}
struct dpackheader_t {
    id : int8[4]
    dirofs : int
    dirlen : int
}
struct quakeparms_t {
    basedir : int8?
    cachedir : int8?
    argc : int
    argv : int8??
    membase : uint8?
    memsize : int
}
struct Unnamed_common_477 {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 4ul)
}
enum keydest_t : uint {
    key_game = 0
    key_console = 1
    key_message = 2
    key_menu = 3
}
typedef fixed16_t = int
struct surf_t {
    next : surf_s?
    prev : surf_s?
    spans : espan_s?
    key : int
    last_u : int
    spanstate : int
    flags : int
    data : uint8?
    entity : entity_s?
    nearzi : float
    insubmodel : qboolean
    d_ziorigin : float
    d_zistepu : float
    d_zistepv : float
    pad : int[2]
}
struct surf_s {
    next : surf_s?
    prev : surf_s?
    spans : espan_s?
    key : int
    last_u : int
    spanstate : int
    flags : int
    data : uint8?
    entity : entity_s?
    nearzi : float
    insubmodel : qboolean
    d_ziorigin : float
    d_zistepu : float
    d_zistepv : float
    pad : int[2]
}
struct espan_s {
    u : int
    v : int
    count : int
    pnext : espan_s?
}
struct espan_t {
    u : int
    v : int
    count : int
    pnext : espan_s?
}
struct surfcache_t {
    next : surfcache_s?
    owner : surfcache_s??
    lightadj : int[4]
    dlight : int
    size : int
    width : uint
    height : uint
    mipscale : float
    texture : texture_s?
    data : uint8[4]
}
enum ptype_t : uint {
    pt_static = 0
    pt_grav = 1
    pt_slowgrav = 2
    pt_fire = 3
    pt_explode = 4
    pt_explode2 = 5
    pt_blob = 6
    pt_blob2 = 7
}
struct particle_s {
    org : vec3_t
    color : float
    next : particle_s?
    vel : vec3_t
    ramp : float
    die : float
    type_0 : ptype_t
}
struct particle_t {
    org : vec3_t
    color : float
    next : particle_s?
    vel : vec3_t
    ramp : float
    die : float
    type_0 : ptype_t
}
typedef fixed8_t = int
enum aliasskintype_t : uint {
    ALIAS_SKIN_SINGLE = 0
    ALIAS_SKIN_GROUP = 1
}
struct maliasskindesc_t {
    type_0 : aliasskintype_t
    pcachespot : uint8?
    skin : int
}
struct mtriangle_s {
    facesfront : int
    vertindex : int[3]
}
struct mtriangle_t {
    facesfront : int
    vertindex : int[3]
}
struct finalvert_s {
    v : int[6]
    flags : int
    reserved : float
}
struct finalvert_t {
    v : int[6]
    flags : int
    reserved : float
}
struct affinetridesc_t {
    pskin : uint8?
    pskindesc : maliasskindesc_t?
    skinwidth : int
    skinheight : int
    ptriangles : mtriangle_s?
    pfinalverts : finalvert_s?
    numtriangles : int
    drawtype : int
    seamfixupX16 : int
}
struct spanpackage_t {
    pdest : uint8?
    pz : int16?
    count : int
    ptex : uint8?
    sfrac : int
    tfrac : int
    light : int
    zi : int
}
struct adivtab_t {
    quotient : int
    remainder : int
}
struct edgetable {
    isflattop : int
    numleftedges : int
    pleftedgevert0 : int?
    pleftedgevert1 : int?
    pleftedgevert2 : int?
    numrightedges : int
    prightedgevert0 : int?
    prightedgevert1 : int?
    prightedgevert2 : int?
}
struct mspriteframe_s {
    width : int
    height : int
    pcachespot : uint8?
    up : float
    down : float
    left : float
    right : float
    pixels : uint8[4]
}
struct mspriteframe_t {
    width : int
    height : int
    pcachespot : uint8?
    up : float
    down : float
    left : float
    right : float
    pixels : uint8[4]
}
struct emitpoint_t {
    u : float
    v : float
    s : float
    t : float
    zi : float
}
struct spritedesc_t {
    nump : int
    pverts : emitpoint_t?
    pspriteframe : mspriteframe_s?
    vup : vec3_t
    vright : vec3_t
    vpn : vec3_t
    nearzi : float
}
struct sspan_t {
    u : int
    v : int
    count : int
}
struct sspan_s {
    u : int
    v : int
    count : int
}
struct drawsurf_t {
    surfdat : uint8?
    rowbytes : int
    surf : msurface_s?
    lightadj : int[4]
    texture : texture_s?
    surfmip : int
    surfwidth : int
    surfheight : int
}
struct zpointdesc_t {
    u : int
    v : int
    zi : float
    color : int
}
struct qpic_t {
    width : int
    height : int
    data : uint8[4]
}
struct rectdesc_t {
    rect : vrect_s
    width : int
    height : int
    ptexbytes : uint8?
    rowbytes : int
}
struct cachepic_t {
    name : int8[64]
    cache : cache_user_s
}
struct cachepic_s {
    name : int8[64]
    cache : cache_user_s
}
struct dprograms_t {
    version : int
    crc : int
    ofs_statements : int
    numstatements : int
    ofs_globaldefs : int
    numglobaldefs : int
    ofs_fielddefs : int
    numfielddefs : int
    ofs_functions : int
    numfunctions : int
    ofs_strings : int
    numstrings : int
    ofs_globals : int
    numglobals : int
    entityfields : int
}
struct globalvars_t {
    pad : int[28]
    self : int
    other : int
    world : int
    time : float
    frametime : float
    force_retouch : float
    mapname : int
    deathmatch : float
    coop : float
    teamplay : float
    serverflags : float
    total_secrets : float
    total_monsters : float
    found_secrets : float
    killed_monsters : float
    parm1 : float
    parm2 : float
    parm3 : float
    parm4 : float
    parm5 : float
    parm6 : float
    parm7 : float
    parm8 : float
    parm9 : float
    parm10 : float
    parm11 : float
    parm12 : float
    parm13 : float
    parm14 : float
    parm15 : float
    parm16 : float
    v_forward : vec3_t
    v_up : vec3_t
    v_right : vec3_t
    trace_allsolid : float
    trace_startsolid : float
    trace_fraction : float
    trace_endpos : vec3_t
    trace_plane_normal : vec3_t
    trace_plane_dist : float
    trace_ent : int
    trace_inopen : float
    trace_inwater : float
    msg_entity : int
    main : int
    StartFrame : int
    PlayerPreThink : int
    PlayerPostThink : int
    ClientKill : int
    ClientConnect : int
    PutClientInServer : int
    ClientDisconnect : int
    SetNewParms : int
    SetChangeParms : int
}
struct eval_s {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 12ul)
}
struct client_s {
    active : qboolean
    spawned : qboolean
    dropasap : qboolean
    privileged : qboolean
    sendsignon : qboolean
    last_message : double
    netconnection : qsocket_s?
    cmd : usercmd_t
    wishdir : vec3_t
    message : sizebuf_s
    msgbuf : uint8[8000]
    edict : edict_s?
    name : int8[32]
    colors : int
    ping_times : float[16]
    num_pings : int
    spawn_parms : float[16]
    old_frags : int
}
struct server_static_t {
    maxclients : int
    maxclientslimit : int
    clients : client_s?
    serverflags : int
    changelevel_issued : qboolean
}
struct client_t {
    active : qboolean
    spawned : qboolean
    dropasap : qboolean
    privileged : qboolean
    sendsignon : qboolean
    last_message : double
    netconnection : qsocket_s?
    cmd : usercmd_t
    wishdir : vec3_t
    message : sizebuf_s
    msgbuf : uint8[8000]
    edict : edict_s?
    name : int8[32]
    colors : int
    ping_times : float[16]
    num_pings : int
    spawn_parms : float[16]
    old_frags : int
}
enum aliasframetype_t : uint {
    ALIAS_SINGLE = 0
    ALIAS_GROUP = 1
}
struct trivertx_t {
    v : uint8[3]
    lightnormalindex : uint8
}
struct maliasframedesc_t {
    type_0 : aliasframetype_t
    bboxmin : trivertx_t
    bboxmax : trivertx_t
    frame : int
    name : int8[16]
}
struct aliashdr_t {
    model : int
    stverts : int
    skindesc : int
    triangles : int
    frames : maliasframedesc_t[1]
}
struct c2da___sigset_t {
    c2da___val : uint64[16]
}
struct c2da___jmp_buf_tag {
    c2da___jmpbuf : int64[8]
    c2da___mask_was_saved : int
    c2da___saved_mask : c2da___sigset_t
}
typedef jmp_buf = c2da___jmp_buf_tag[1]
enum _ControlList : uint {
    AxisNada = 0
    AxisForward = 1
    AxisLook = 2
    AxisSide = 3
    AxisTurn = 4
}
struct keyname_t {
    name : int8?
    keynum : int
}
struct hostcache_t {
    name : int8[16]
    map : int8[16]
    cname : int8[32]
    users : int
    maxusers : int
    driver : int
    ldriver : int
    addr_0 : qsockaddr
}
struct episode_t {
    description : int8?
    firstLevel : int
    levels : int
}
struct level_t {
    name : int8?
    description : int8?
}
struct lump_t {
    fileofs : int
    filelen : int
}
struct dheader_t {
    version : int
    lumps : lump_t[15]
}
struct dmiptexlump_t {
    nummiptex : int
    dataofs : int[4]
}
struct miptex_s {
    name : int8[16]
    width : uint
    height : uint
    offsets : uint[4]
}
struct miptex_t {
    name : int8[16]
    width : uint
    height : uint
    offsets : uint[4]
}
struct dvertex_t {
    point : float[3]
}
struct dplane_t {
    normal : float[3]
    dist : float
    type_0 : int
}
struct dnode_t {
    planenum : int
    children : int16[2]
    mins : int16[3]
    maxs : int16[3]
    firstface : uint16
    numfaces : uint16
}
struct texinfo_s {
    vecs : float[2][4]
    miptex : int
    flags : int
}
struct texinfo_t {
    vecs : float[2][4]
    miptex : int
    flags : int
}
struct dedge_t {
    v : uint16[2]
}
struct dface_t {
    planenum : int16
    side : int16
    firstedge : int
    numedges : int16
    texinfo : int16
    styles : uint8[4]
    lightofs : int
}
struct dleaf_t {
    contents : int
    visofs : int
    mins : int16[3]
    maxs : int16[3]
    firstmarksurface : uint16
    nummarksurfaces : uint16
    ambient_level : uint8[4]
}
struct mdl_t {
    ident : int
    version : int
    scale : vec3_t
    scale_origin : vec3_t
    boundingradius : float
    eyeposition : vec3_t
    numskins : int
    skinwidth : int
    skinheight : int
    numverts : int
    numtris : int
    numframes : int
    synctype : synctype_t
    flags : int
    size : float
}
struct stvert_t {
    onseam : int
    s : int
    t : int
}
struct dtriangle_s {
    facesfront : int
    vertindex : int[3]
}
struct dtriangle_t {
    facesfront : int
    vertindex : int[3]
}
struct daliasframe_t {
    bboxmin : trivertx_t
    bboxmax : trivertx_t
    name : int8[16]
}
struct daliasgroup_t {
    numframes : int
    bboxmin : trivertx_t
    bboxmax : trivertx_t
}
struct daliasskingroup_t {
    numskins : int
}
struct daliasinterval_t {
    interval : float
}
struct daliasskininterval_t {
    interval : float
}
struct daliasframetype_t {
    type_0 : aliasframetype_t
}
struct daliasskintype_t {
    type_0 : aliasskintype_t
}
struct dsprite_t {
    ident : int
    version : int
    type_0 : int
    boundingradius : float
    width : int
    height : int
    numframes : int
    beamlength : float
    synctype : synctype_t
}
struct dspriteframe_t {
    origin : int[2]
    width : int
    height : int
}
struct dspritegroup_t {
    numframes : int
}
struct dspriteinterval_t {
    interval : float
}
enum spriteframetype_t : uint {
    SPR_SINGLE = 0
    SPR_GROUP = 1
}
struct dspriteframetype_t {
    type_0 : spriteframetype_t
}
struct mspritegroup_t {
    numframes : int
    intervals : float?
    frames : mspriteframe_s? [1]
}
struct mspriteframedesc_t {
    type_0 : spriteframetype_t
    frameptr : mspriteframe_s?
}
struct msprite_t {
    type_0 : int
    maxwidth : int
    maxheight : int
    numframes : int
    beamlength : float
    cachespot : uint8?
    frames : mspriteframedesc_t[1]
}
struct maliasgroupframedesc_t {
    bboxmin : trivertx_t
    bboxmax : trivertx_t
    frame : int
}
struct maliasgroup_t {
    numframes : int
    intervals : int
    frames : maliasgroupframedesc_t[1]
}
struct maliasskingroup_t {
    numskins : int
    intervals : int
    skindescs : maliasskindesc_t[1]
}
struct net_driver_t {
    name : int8?
    initialized : qboolean
    Init : function<():int>
    Listen : function<(var _arg0:qboolean):void>
    SearchForHosts : function<(var _arg0:qboolean):void>
    Connect : function<(var _arg0:int8?):qsocket_s?>
    CheckNewConnections : function<():qsocket_s?>
    QGetMessage : function<(var _arg0:qsocket_s?):int>
    QSendMessage : function<(var _arg0:qsocket_s?;var _arg1:sizebuf_s?):int>
    SendUnreliableMessage : function<(var _arg0:qsocket_s?;var _arg1:sizebuf_s?):int>
    CanSendMessage : function<(var _arg0:qsocket_s?):qboolean>
    CanSendUnreliableMessage : function<(var _arg0:qsocket_s?):qboolean>
    Close : function<(var _arg0:qsocket_s?):void>
    Shutdown : function<():void>
    controlSock : int
}
struct PollProcedure {
    next : _PollProcedure?
    nextTime : double
    procedure : function<():void>
    arg : uint8?
}
struct _PollProcedure {
    next : _PollProcedure?
    nextTime : double
    procedure : function<():void>
    arg : uint8?
}
struct Unnamed_net_main_450 {
    time : double
    op : int
    session : int64
}
struct Unnamed_net_main_617 {
    time : double
    op : int
    session : int64
    r : int
}
struct Unnamed_net_main_529 {
    time : double
    op : int
    session : int64
    ret : int
    len : int
}
struct net_landriver_t {
    name : int8?
    initialized : qboolean
    controlSock : int
    Init : function<():int>
    Shutdown : function<():void>
    Listen : function<(var _arg0:qboolean):void>
    OpenSocket : function<(var _arg0:int):int>
    CloseSocket : function<(var _arg0:int):int>
    Connect : function<(var _arg0:int;var _arg1:qsockaddr?):int>
    CheckNewConnections : function<():int>
    Read : function<(var _arg0:int;var _arg1:uint8?;var _arg2:int;var _arg3:qsockaddr?):int>
    Write : function<(var _arg0:int;var _arg1:uint8?;var _arg2:int;var _arg3:qsockaddr?):int>
    Broadcast : function<(var _arg0:int;var _arg1:uint8?;var _arg2:int):int>
    AddrToString : function<(var _arg0:qsockaddr?):int8?>
    StringToAddr : function<(var _arg0:int8?;var _arg1:qsockaddr?):int>
    GetSocketAddr : function<(var _arg0:int;var _arg1:qsockaddr?):int>
    GetNameFromAddr : function<(var _arg0:qsockaddr?;var _arg1:int8?):int>
    GetAddrFromName : function<(var _arg0:int8?;var _arg1:qsockaddr?):int>
    AddrCompare : function<(var _arg0:qsockaddr?;var _arg1:qsockaddr?):int>
    GetSocketPort : function<(var _arg0:qsockaddr?):int>
    SetSocketPort : function<(var _arg0:qsockaddr?;var _arg1:int):int>
}
struct Unnamed_net_vcr_32 {
    time : double
    op : int
    session : int64
}
struct dfunction_t {
    first_statement : int
    parm_start : int
    locals : int
    profile : int
    s_name : int
    s_file : int
    numparms : int
    parm_size : uint8[8]
}
typedef builtin_t = function<():void>
enum etype_t : uint {
    ev_void = 0
    ev_string = 1
    ev_float = 2
    ev_vector = 3
    ev_entity = 4
    ev_field = 5
    ev_function = 6
    ev_pointer = 7
}
struct statement_s {
    op : uint16
    a : int16
    b : int16
    c : int16
}
struct dstatement_t {
    op : uint16
    a : int16
    b : int16
    c : int16
}
struct ddef_t {
    type_0 : uint16
    ofs : uint16
    s_name : int
}
struct gefv_cache {
    pcache : ddef_t?
    field : int8[64]
}
struct prstack_t {
    s : int
    f : dfunction_t?
}
struct auxvert_t {
    fv : float[3]
}
struct alight_t {
    ambientlight : int
    shadelight : int
    plightvec : float?
}
struct aedge_t {
    index0 : int
    index1 : int
}
struct bedge_s {
    v : mvertex_t? [2]
    pnext : bedge_s?
}
struct bedge_t {
    v : mvertex_t? [2]
    pnext : bedge_s?
}
struct clipplane_s {
    normal : vec3_t
    dist : float
    next : clipplane_s?
    leftedge : uint8
    rightedge : uint8
    reserved : uint8[2]
}
struct clipplane_t {
    normal : vec3_t
    dist : float
    next : clipplane_s?
    leftedge : uint8
    rightedge : uint8
    reserved : uint8[2]
}
struct btofpoly_t {
    clipflags : int
    psurf : msurface_s?
}
struct btofpoly_s {
    clipflags : int
    psurf : msurface_s?
}
typedef uintptr_t = uint64
struct polyvert_s {
    u : float
    v : float
    zi : float
    s : float
    t : float
}
struct polyvert_t {
    u : float
    v : float
    zi : float
    s : float
    t : float
}
struct polydesc_s {
    numverts : int
    nearzi : float
    pcurrentface : msurface_s?
    pverts : polyvert_s?
}
struct polydesc_t {
    numverts : int
    nearzi : float
    pcurrentface : msurface_s?
    pverts : polyvert_s?
}
struct edge_s {
    u : int
    u_step : int
    prev : edge_s?
    next : edge_s?
    surfs : uint16[2]
    nextremove : edge_s?
    nearzi : float
    owner : medge_t?
}
struct edge_t {
    u : int
    u_step : int
    prev : edge_s?
    next : edge_s?
    surfs : uint16[2]
    nextremove : edge_s?
    nearzi : float
    owner : medge_t?
}
typedef vec5_t = float[5]
struct pcx_t {
    manufacturer : int8
    version : int8
    encoding : int8
    bits_per_pixel : int8
    xmin : uint16
    ymin : uint16
    xmax : uint16
    ymax : uint16
    hres : uint16
    vres : uint16
    palette : uint8[48]
    reserved : int8
    color_planes : int8
    bytes_per_line : uint16
    palette_type : uint16
    filler : int8[58]
    data : uint8
}
struct wadinfo_t {
    identification : int8[4]
    numlumps : int
    infotableofs : int
}
struct lumpinfo_t {
    filepos : int
    disksize : int
    size : int
    type_0 : int8
    compression : int8
    pad1 : int8
    pad2 : int8
    name : int8[16]
}
struct areanode_t {
    axis : int
    dist : float
    children : areanode_s? [2]
    trigger_edicts : link_s
    solid_edicts : link_s
}
struct areanode_s {
    axis : int
    dist : float
    children : areanode_s? [2]
    trigger_edicts : link_s
    solid_edicts : link_s
}
struct moveclip_t {
    boxmins : vec3_t
    boxmaxs : vec3_t
    mins : float?
    maxs : float?
    mins2 : vec3_t
    maxs2 : vec3_t
    start : float?
    end : float?
    trace : trace_t
    type_0 : int
    passedict : edict_s?
}
struct memblock_s {
    size : int
    tag : int
    id : int
    next : memblock_s?
    prev : memblock_s?
    pad : int
}
struct memzone_t {
    size : int
    blocklist : memblock_s
    rover : memblock_s?
}
struct memblock_t {
    size : int
    tag : int
    id : int
    next : memblock_s?
    prev : memblock_s?
    pad : int
}
struct hunk_t {
    sentinal : int
    size : int
    name : int8[8]
}
struct cache_system_t {
    size : int
    user : cache_user_s?
    name : int8[16]
    prev : cache_system_s?
    next : cache_system_s?
    lru_prev : cache_system_s?
    lru_next : cache_system_s?
}
struct cache_system_s {
    size : int
    user : cache_user_s?
    name : int8[16]
    prev : cache_system_s?
    next : cache_system_s?
    lru_prev : cache_system_s?
    lru_next : cache_system_s?
}
typedef int32_t = int
typedef uint32_t = uint
let true_0 : int = 1

let false_0 : int = 0

let ST_RAND : int = 1

let ST_SYNC : int = 0

let mod_alias : int = 2

let mod_sprite : int = 1

let mod_brush : int = 0

let src_command : int = 1

let src_client : int = 0

let ca_connected : int = 2

let ca_disconnected : int = 1

let ca_dedicated : int = 0

let ss_active : int = 1

let ss_loading : int = 0

let key_menu : int = 3

let key_message : int = 2

let key_console : int = 1

let key_game : int = 0

let pt_blob2 : int = 7

let pt_blob : int = 6

let pt_explode2 : int = 5

let pt_explode : int = 4

let pt_fire : int = 3

let pt_slowgrav : int = 2

let pt_grav : int = 1

let pt_static : int = 0

let ALIAS_SKIN_GROUP : int = 1

let ALIAS_SKIN_SINGLE : int = 0

let ALIAS_GROUP : int = 1

let ALIAS_SINGLE : int = 0

let AxisForward : int = 1

let AxisTurn : int = 4

let AxisNada : int = 0

let AxisLook : int = 2

let AxisSide : int = 3

let m_slist : int = 18

let m_search : int = 17

let m_gameoptions : int = 16

let m_lanconfig : int = 15

let m_modemconfig : int = 14

let m_serialconfig : int = 13

let m_quit : int = 12

let m_help : int = 11

let m_keys : int = 10

let m_video : int = 9

let m_options : int = 8

let m_net : int = 7

let m_setup : int = 6

let m_multiplayer : int = 5

let m_save : int = 4

let m_load : int = 3

let m_singleplayer : int = 2

let m_main : int = 1

let m_none : int = 0

let SPR_GROUP : int = 1

let SPR_SINGLE : int = 0

let ev_pointer : int = 7

let ev_function : int = 6

let ev_field : int = 5

let ev_entity : int = 4

let ev_vector : int = 3

let ev_float : int = 2

let ev_string : int = 1

let ev_void : int = 0

let OP_BITOR : int = 65

let OP_BITAND : int = 64

let OP_OR : int = 63

let OP_AND : int = 62

let OP_GOTO : int = 61

let OP_STATE : int = 60

let OP_CALL8 : int = 59

let OP_CALL7 : int = 58

let OP_CALL6 : int = 57

let OP_CALL5 : int = 56

let OP_CALL4 : int = 55

let OP_CALL3 : int = 54

let OP_CALL2 : int = 53

let OP_CALL1 : int = 52

let OP_CALL0 : int = 51

let OP_IFNOT : int = 50

let OP_IF : int = 49

let OP_NOT_FNC : int = 48

let OP_NOT_ENT : int = 47

let OP_NOT_S : int = 46

let OP_NOT_V : int = 45

let OP_NOT_F : int = 44

let OP_RETURN : int = 43

let OP_STOREP_FNC : int = 42

let OP_STOREP_FLD : int = 41

let OP_STOREP_ENT : int = 40

let OP_STOREP_S : int = 39

let OP_STOREP_V : int = 38

let OP_STOREP_F : int = 37

let OP_STORE_FNC : int = 36

let OP_STORE_FLD : int = 35

let OP_STORE_ENT : int = 34

let OP_STORE_S : int = 33

let OP_STORE_V : int = 32

let OP_STORE_F : int = 31

let OP_ADDRESS : int = 30

let OP_LOAD_FNC : int = 29

let OP_LOAD_FLD : int = 28

let OP_LOAD_ENT : int = 27

let OP_LOAD_S : int = 26

let OP_LOAD_V : int = 25

let OP_LOAD_F : int = 24

let OP_GT : int = 23

let OP_LT : int = 22

let OP_GE : int = 21

let OP_LE : int = 20

let OP_NE_FNC : int = 19

let OP_NE_E : int = 18

let OP_NE_S : int = 17

let OP_NE_V : int = 16

let OP_NE_F : int = 15

let OP_EQ_FNC : int = 14

let OP_EQ_E : int = 13

let OP_EQ_S : int = 12

let OP_EQ_V : int = 11

let OP_EQ_F : int = 10

let OP_SUB_V : int = 9

let OP_SUB_F : int = 8

let OP_ADD_V : int = 7

let OP_ADD_F : int = 6

let OP_DIV_F : int = 5

let OP_MUL_VF : int = 4

let OP_MUL_FV : int = 3

let OP_MUL_V : int = 2

let OP_MUL_F : int = 1

let OP_DONE : int = 0

var c2da_std_errno_cell : uint64 = c2da_std_cell_alloc()

var c2da_std_io_byte : uint64 = c2da_std_cell_alloc()

var c2da_std_jmp_target : string = ""

var c2da_std_lost_bytes : int = 0

var c2da_std_rand_front : int = 3

var c2da_std_rand_rear : int = 0

var c2da_std_rand_seeded : bool = false

var c2da_std_rand_state : uint[31]

var c2da_std_stream_fd : array<int>

var c2da_std_stream_flags : array<int>

var c2da_std_stream_keys : array<uint64>

var c2da_std_stream_next_fd : int = 3

var c2da_std_stream_push : array<int>

var c2da_std_text_caps : array<uint64>

var c2da_std_text_cells : array<uint64>

[sideeffects]
def c2da_std_abs(x : int) : int {
    if (x < 0) {
        return 0 - x
    }
    return x
}
[sideeffects]
def c2da_std_arg_f64(args : array<C2daVaArg>; index : int) : double {
    if (index < 0 || index >= length(args)) {
        return 0.0lf
    }
    let item = args[index]
    if (item.tag == 2) {
        return item.f64
    }
    return double(item.i64)
}
[sideeffects]
def c2da_std_arg_i64(args : array<C2daVaArg>; index : int) : int64 {
    if (index < 0 || index >= length(args)) {
        return 0l
    }
    let item = args[index]
    if (item.tag == 2) {
        return int64(item.f64)
    }
    if (item.tag == 3) {
        return int64(item.raw)
    }
    return item.i64
}
[sideeffects]
def c2da_std_arg_u64(args : array<C2daVaArg>; index : int) : uint64 {
    if (index < 0 || index >= length(args)) {
        return 0x0ul
    }
    let item = args[index]
    if (item.tag == 3) {
        return item.raw
    }
    if (item.tag == 2) {
        return uint64(item.f64)
    }
    return uint64(item.i64)
}
[sideeffects]
def c2da_std_atof(nptr : uint64) : double {
    return c2da_std_strtod(nptr, 0x0ul)
}
[sideeffects]
def c2da_std_atoi(nptr : uint64) : int {
    return int(int64(c2da_std_strto(nptr, 0x0ul, 10, 0x7ffffffffffffffful, 0x8000000000000000ul)))
}
[sideeffects]
def c2da_std_byte(s : int8 const?; index : int) : int {
    if (s == null) {
        return 0
    }
    return int(unsafe(s[index])) & 255
}
[sideeffects]
def c2da_std_cell_alloc() : uint64 {
    let raw : uint64 = c2da_rt_malloc(0xcul)
    if (raw == 0x0ul) {
        panic("--libc std prelude: the raw heap is exhausted")
    }
    let aligned : uint64 = (raw + 0x7ul) / 0x8ul * 0x8ul
    c2da_std_raw_put(aligned, 0x0ul, 0)
    c2da_std_raw_put(aligned, 0x1ul, 0)
    c2da_std_raw_put(aligned, 0x2ul, 0)
    c2da_std_raw_put(aligned, 0x3ul, 0)
    return aligned
}
[sideeffects]
def c2da_std_digit(ch : int; base : int) : int {
    var v : int = -1
    if (is_number(ch)) {
        v = ch - 48
    } elif (ch >= 97 && ch <= 122) {
        v = ch - 97 + 10
    } elif (ch >= 65 && ch <= 90) {
        v = ch - 65 + 10
    }
    if (v < 0 || v >= base) {
        return -1
    }
    return v
}
[sideeffects]
def c2da_std_errno_location() : uint64 {
    return c2da_std_errno_cell
}
[sideeffects]
def c2da_std_exit(code : int) {
    unsafe(exit_now(code))
}
[sideeffects]
def c2da_std_fabs(x : double) : double {
    return unsafe(reinterpret<double>(unsafe(reinterpret<uint64>(x)) & 0x7ffffffffffffffful))
}
[sideeffects]
def c2da_std_fclose(handle : uint64) : int {
    if (handle == 0x0ul) {
        c2da_std_set_errno(9)
        return -1
    }
    fclose(c2da_std_file(handle))
    let slot = c2da_std_stream_slot(handle)
    c2da_std_stream_flags[slot] = 0
    c2da_std_stream_push[slot] = -1
    c2da_std_stream_fd[slot] = -1
    return 0
}
[sideeffects]
def c2da_std_feof(handle : uint64) : int {
    if (handle == 0x0ul) {
        return 0
    }
    let slot = c2da_std_stream_slot(handle)
    if (c2da_std_stream_push[slot] >= 0) {
        return 0
    }
    if (feof(c2da_std_file(handle))) {
        return 1
    }
    return 0
}
[sideeffects]
def c2da_std_fflush(handle : uint64) : int {
    if (handle == 0x0ul) {
        fflush(c2da_std_file(c2da_std_stdout()))
        fflush(c2da_std_file(c2da_std_stderr()))
    } else {
        fflush(c2da_std_file(handle))
    }
    return 0
}
[sideeffects]
def c2da_std_fgetc(handle : uint64) : int {
    if (handle == 0x0ul) {
        return -1
    }
    let pushed : int = c2da_std_stream_take_push(handle)
    if (pushed >= 0) {
        return pushed
    }
    var buffer : uint8? = unsafe(reinterpret<uint8?>(c2da_std_io_byte))
    let got : int64 = _builtin_read64(c2da_std_file(handle), buffer, 1l)
    if (got < 0l) {
        c2da_std_stream_fail(handle)
        return -1
    }
    if (got == 0l) {
        return -1
    }
    return c2da_std_raw_byte(c2da_std_io_byte, 0x0ul)
}
[sideeffects]
def c2da_std_file(handle : uint64) : FILE const? {
    return unsafe(reinterpret<FILE const?>(handle))
}
[sideeffects]
def c2da_std_fopen(path : int8 const?; mode : int8 const?) : uint64 {
    let spelled : string = c2da_std_string(mode)
    if (empty(spelled)) {
        c2da_std_set_errno(22)
        return 0x0ul
    }
    let head = first_character(spelled)
    if (head != 114 && (head != 119 && head != 97)) {
        c2da_std_set_errno(22)
        return 0x0ul
    }
    let accepted : string = build_string($(var writer : StringBuilderWriter) {
        write_char(writer, head)
        var k : int = 1
        while (k < length(spelled)) {
            let letter = unsafe(character_uat(spelled, k))
            if (letter == 44) {
                break
            }
            if (letter == 43 || (letter == 98 || (letter == 116 || letter == 120))) {
                write_char(writer, letter)
            }
            k++
        }
    })
    var opened : FILE const? = fopen(c2da_std_string(path), accepted)
    if (opened == null) {
        c2da_std_fopen_errno(path)
        return 0x0ul
    }
    let handle : uint64 = unsafe(reinterpret<uint64>(opened))
    c2da_std_stream_open(handle)
    return handle
}
[sideeffects]
def c2da_std_fopen_errno(path : int8 const?) {
    c2da_std_path_errno(c2da_std_string(path))
}
[sideeffects]
def c2da_std_format(f : int8 const?; args : array<C2daVaArg>) : string {
    var from : int = 0
    return c2da_std_vformat(f, args, from)
}
[sideeffects]
def c2da_std_fprintf(handle : uint64; f : int8 const?; args : array<C2daVaArg>) : int {
    let body : string = c2da_std_format(f, args)
    c2da_std_write(handle, body)
    return length(body) + c2da_std_lost_bytes
}
[sideeffects]
def c2da_std_fread(dst : uint64; size : uint64; count : uint64; handle : uint64) : uint64 {
    if (handle == 0x0ul || dst == 0x0ul || size == 0x0ul || count == 0x0ul) {
        return 0x0ul
    }
    if (count > 0xfffffffffffffffful / size) {
        c2da_std_set_errno(12)
        return 0x0ul
    }
    var total : uint64 = size * count
    if (total > 0x7ffffffffffffffful) {
        c2da_std_set_errno(12)
        return 0x0ul
    }
    let pushed : int = c2da_std_stream_take_push(handle)
    var head : uint64 = 0x0ul
    if (pushed >= 0) {
        c2da_std_raw_put(dst, 0x0ul, pushed)
        head = 0x1ul
        total--
    }
    if (total == 0x0ul) {
        return head / size
    }
    var buffer : uint8? = unsafe(reinterpret<uint8?>(dst + head))
    let got : int64 = _builtin_read64(c2da_std_file(handle), buffer, int64(total))
    if (got < 0l) {
        c2da_std_stream_fail(handle)
        return head / size
    }
    return (head + uint64(got)) / size
}
[sideeffects]
def c2da_std_fscanf(handle : uint64; f : uint64; args : array<C2daVaArg>) : int {
    var done : int = 0
    var arg : int = 0
    var i : uint64 = 0x0ul
    let buf : uint64 = c2da_rt_malloc(0x200ul)
    var c : int = c2da_std_fgetc(handle)
    while (true) {
        let fc = c2da_std_raw_byte(f, i)
        if (fc == 0) {
            break
        }
        if (c2da_std_isspace(fc) != 0) {
            while (c2da_std_isspace(c2da_std_raw_byte(f, i)) != 0) {
                i++
            }
            while (c >= 0 && c2da_std_isspace(c) != 0) {
                c = c2da_std_fgetc(handle)
            }
            continue
        }
        if (fc != 37) {
            if (c < 0) {
                if (done == 0) {
                    if (c >= 0) {
                        c2da_std_ungetc(c, handle)
                    }
                    c2da_rt_free(buf)
                    return -1
                }
                if (c >= 0) {
                    c2da_std_ungetc(c, handle)
                }
                c2da_rt_free(buf)
                return done
            }
            if (c != fc) {
                if (c >= 0) {
                    c2da_std_ungetc(c, handle)
                }
                c2da_rt_free(buf)
                return done
            }
            c = c2da_std_fgetc(handle)
            i++
            continue
        }
        var j : uint64 = i + 0x1ul
        var width : int = 0
        while (is_number(c2da_std_raw_byte(f, j))) {
            width = width * 10 + c2da_std_raw_byte(f, j) - 48
            j++
        }
        var wide : bool = false
        if (c2da_std_raw_byte(f, j) == 108) {
            wide = true
            j++
        }
        let conv = c2da_std_raw_byte(f, j)
        i = j + 0x1ul
        if (conv == 37) {
            while (c >= 0 && c2da_std_isspace(c) != 0) {
                c = c2da_std_fgetc(handle)
            }
            if (c < 0) {
                if (done == 0) {
                    if (c >= 0) {
                        c2da_std_ungetc(c, handle)
                    }
                    c2da_rt_free(buf)
                    return -1
                }
                if (c >= 0) {
                    c2da_std_ungetc(c, handle)
                }
                c2da_rt_free(buf)
                return done
            }
            if (!(c == 37)) {
                if (c >= 0) {
                    c2da_std_ungetc(c, handle)
                }
                c2da_rt_free(buf)
                return done
            }
            c = c2da_std_fgetc(handle)
            continue
        }
        var base : int = -1
        var signed_conv : bool = false
        var floating : bool = false
        if (conv == 100) {
            base = 10
            signed_conv = true
        } elif (conv == 105) {
            base = 0
            signed_conv = true
        } elif (conv == 111) {
            base = 8
            signed_conv = false
        } elif (conv == 117) {
            base = 10
            signed_conv = false
        } elif (conv == 120 || conv == 88) {
            base = 16
            signed_conv = false
        } elif (conv == 101 || conv == 102 || conv == 103 || conv == 69 || conv == 71) {
            floating = true
        }
        if ((base < 0 || wide) && (!floating && !(conv == 115))) {
            panic("--libc std: fscanf conversion is not implemented")
        }
        while (c >= 0 && c2da_std_isspace(c) != 0) {
            c = c2da_std_fgetc(handle)
        }
        if (c < 0) {
            if (done == 0) {
                if (c >= 0) {
                    c2da_std_ungetc(c, handle)
                }
                c2da_rt_free(buf)
                return -1
            }
            if (c >= 0) {
                c2da_std_ungetc(c, handle)
            }
            c2da_rt_free(buf)
            return done
        }
        let cell : uint64 = c2da_std_arg_u64(args, arg)
        if (cell == 0x0ul) {
            panic("--libc std: fscanf has no pointer argument to store a conversion through")
        }
        if (conv == 115) {
            var k : int = 0
            while (c >= 0 && (c2da_std_isspace(c) == 0 && (width == 0 || k < width))) {
                c2da_std_raw_put(cell, uint64(k), c)
                k++
                c = c2da_std_fgetc(handle)
            }
            c2da_std_raw_put(cell, uint64(k), 0)
        } else {
            var limit : int = 511
            if (width > 0 && width < limit) {
                limit = width
            }
            var n : int = 0
            var any : bool = false
            if (floating) {
                if (n < limit && (c == 45 || c == 43)) {
                    c2da_std_raw_put(buf, uint64(n), c)
                    n++
                    c = c2da_std_fgetc(handle)
                }
                if ((c | 32) == 105 || (c | 32) == 110) {
                    panic("--libc std: fscanf does not implement `inf`/`nan` input")
                }
                while (n < limit && is_number(c)) {
                    any = true
                    c2da_std_raw_put(buf, uint64(n), c)
                    n++
                    c = c2da_std_fgetc(handle)
                }
                if (any && (c | 32) == 120) {
                    panic("--libc std: fscanf does not implement hexadecimal floating input")
                }
                if (n < limit && c == 46) {
                    c2da_std_raw_put(buf, uint64(n), c)
                    n++
                    c = c2da_std_fgetc(handle)
                    while (n < limit && is_number(c)) {
                        any = true
                        c2da_std_raw_put(buf, uint64(n), c)
                        n++
                        c = c2da_std_fgetc(handle)
                    }
                }
                if (any && n < limit && (c | 32) == 101) {
                    c2da_std_raw_put(buf, uint64(n), c)
                    n++
                    c = c2da_std_fgetc(handle)
                    if (n < limit && (c == 45 || c == 43)) {
                        c2da_std_raw_put(buf, uint64(n), c)
                        n++
                        c = c2da_std_fgetc(handle)
                    }
                    while (n < limit && is_number(c)) {
                        c2da_std_raw_put(buf, uint64(n), c)
                        n++
                        c = c2da_std_fgetc(handle)
                    }
                }
                if (!any) {
                    if (c >= 0) {
                        c2da_std_ungetc(c, handle)
                    }
                    c2da_rt_free(buf)
                    return done
                }
                c2da_std_raw_put(buf, uint64(n), 0)
                let number : double = c2da_std_strtod(buf, 0x0ul)
                if (wide) {
                    unsafe(unsafe(reinterpret<double?>(cell))[0]) = number
                } else {
                    unsafe(unsafe(reinterpret<float?>(cell))[0]) = float(number)
                }
            } else {
                var radix : int = base
                if (n < limit && (c == 45 || c == 43)) {
                    c2da_std_raw_put(buf, uint64(n), c)
                    n++
                    c = c2da_std_fgetc(handle)
                }
                if (n < limit && c == 48) {
                    any = true
                    c2da_std_raw_put(buf, uint64(n), c)
                    n++
                    c = c2da_std_fgetc(handle)
                    if (n < limit && (c | 32) == 120) {
                        if (radix == 0 || radix == 16) {
                            radix = 16
                            c2da_std_raw_put(buf, uint64(n), c)
                            n++
                            c = c2da_std_fgetc(handle)
                        }
                    } elif (radix == 0) {
                        radix = 8
                    }
                } elif (radix == 0) {
                    radix = 10
                }
                while (n < limit && c2da_std_digit(c, radix) >= 0) {
                    any = true
                    c2da_std_raw_put(buf, uint64(n), c)
                    n++
                    c = c2da_std_fgetc(handle)
                }
                if (!any) {
                    if (c >= 0) {
                        c2da_std_ungetc(c, handle)
                    }
                    c2da_rt_free(buf)
                    return done
                }
                c2da_std_raw_put(buf, uint64(n), 0)
                var value : uint64 = 0x0ul
                if (signed_conv) {
                    value = c2da_std_strto(buf, 0x0ul, base, 0x7ffffffffffffffful, 0x8000000000000000ul)
                } else {
                    value = c2da_std_strto(buf, 0x0ul, base, 0xfffffffffffffffful, 0xfffffffffffffffful)
                }
                unsafe(unsafe(reinterpret<uint?>(cell))[0]) = uint(value & 0xfffffffful)
            }
        }
        arg++
        done++
    }
    if (c >= 0) {
        c2da_std_ungetc(c, handle)
    }
    c2da_rt_free(buf)
    return done
}
[sideeffects]
def c2da_std_fseek(handle : uint64; offset : int64; whence : int) : int {
    if (handle == 0x0ul) {
        return -1
    }
    if (whence < 0 || whence > 2) {
        c2da_std_set_errno(22)
        return -1
    }
    if (whence == 0 && offset < 0l) {
        c2da_std_set_errno(22)
        return -1
    }
    let slot = c2da_std_stream_slot(handle)
    c2da_std_stream_push[slot] = -1
    var mode : int = seek_set
    if (whence == 1) {
        mode = seek_cur
    } elif (whence == 2) {
        mode = seek_end
    }
    let moved : int64 = fseek(c2da_std_file(handle), offset, mode)
    if (moved != 0l) {
        return -1
    }
    return 0
}
[sideeffects]
def c2da_std_ftell(handle : uint64) : int64 {
    if (handle == 0x0ul) {
        return -1l
    }
    return ftell(c2da_std_file(handle))
}
[sideeffects]
def c2da_std_fwrite(src : uint64; size : uint64; count : uint64; handle : uint64) : uint64 {
    if (handle == 0x0ul || src == 0x0ul) {
        return 0x0ul
    }
    let total : uint64 = size * count
    if (total == 0x0ul) {
        return 0x0ul
    }
    var buffer : uint8? = unsafe(reinterpret<uint8?>(src))
    let wrote : int = _builtin_write(c2da_std_file(handle), buffer, int(total))
    if (wrote < 0 || uint64(wrote) < total) {
        c2da_std_stream_fail(handle)
    }
    if (wrote <= 0) {
        return 0x0ul
    }
    return uint64(wrote) / size
}
[sideeffects]
def c2da_std_huge() : double {
    return to_double("inf")
}
[sideeffects]
def c2da_std_isspace(c : int) : int {
    if (c == 32 || c >= 9 && c <= 13) {
        return 1
    }
    return 0
}
[unused_argument(value), sideeffects]
def c2da_std_longjmp(target : string; value : int) {
    c2da_std_jmp_target = target
    panic("c2da_std_longjmp")
}
[sideeffects]
def c2da_std_number(value : uint64; base : int; upper : bool; sign : string; alt : bool; has_precision : bool; precision : int; width : int; left : bool; zero : bool) : string {
    var digits : string = c2da_std_utoa(value, base, upper)
    if (has_precision) {
        if (precision == 0 && value == 0x0ul) {
            digits = ""
        } elif (length(digits) < precision) {
            digits = repeat("0", precision - length(digits)) + digits
        }
    }
    var prefix : string = sign
    if (alt) {
        if (base == 16 && value != 0x0ul) {
            if (upper) {
                prefix += "0X"
            } else {
                prefix += "0x"
            }
        }
        if (base == 8) {
            if (empty(digits)) {
                digits = "0"
            } elif (first_character(digits) != 48) {
                digits = "0" + digits
            }
        }
    }
    let body : string = prefix + digits
    let gap : int = width - length(body)
    if (gap <= 0) {
        return body
    }
    if (left) {
        return body + repeat(" ", gap)
    }
    if (zero && !has_precision) {
        return prefix + repeat("0", gap) + digits
    }
    return repeat(" ", gap) + body
}
[sideeffects]
def c2da_std_own_text(slot : int; body : string) : uint64 {
    while (length(c2da_std_text_cells) <= slot) {
        push(c2da_std_text_cells, 0x0ul)
        push(c2da_std_text_caps, 0x0ul)
    }
    let need : uint64 = uint64(long_length(body)) + 0x1ul
    if (c2da_std_text_caps[slot] < need) {
        let raw : uint64 = c2da_rt_malloc(need)
        if (raw == 0x0ul) {
            return 0x0ul
        }
        c2da_std_text_cells[slot] = raw
        c2da_std_text_caps[slot] = need
    }
    let base : uint64 = c2da_std_text_cells[slot]
    var i : int = 0
    while (i < length(body)) {
        c2da_std_raw_put(base, uint64(i), unsafe(character_uat(body, i)))
        i++
    }
    c2da_std_raw_put(base, uint64(i), 0)
    return base
}
[sideeffects]
def c2da_std_pad(body : string; width : int; left : bool) : string {
    let gap : int = width - length(body)
    if (gap <= 0) {
        return body
    }
    let spaces : string = repeat(" ", gap)
    if (left) {
        return body + spaces
    }
    return spaces + body
}
[sideeffects]
def c2da_std_path_errno(path : string) {
    if (!fexist(path)) {
        c2da_std_set_errno(2)
        return
    }
    let info = stat(path)
    if (info.is_dir) {
        c2da_std_set_errno(21)
        return
    }
    c2da_std_set_errno(13)
}
[sideeffects]
def c2da_std_place(dst : uint64; size : uint64; body : string) : int {
    let n : int = length(body)
    if (size != 0x0ul && dst != 0x0ul) {
        let cap : int = int(size) - 1
        var i : int = 0
        while (i < n && i < cap) {
            c2da_std_raw_put(dst, uint64(i), unsafe(character_uat(body, i)))
            i++
        }
        c2da_std_raw_put(dst, uint64(i), 0)
    }
    return n
}
[sideeffects]
def c2da_std_printf(f : int8 const?; args : array<C2daVaArg>) : int {
    let body : string = c2da_std_format(f, args)
    print(body)
    return length(body) + c2da_std_lost_bytes
}
[sideeffects]
def c2da_std_rand() : int {
    if (!c2da_std_rand_seeded) {
        c2da_std_srand(0x1)
    }
    return c2da_std_rand_step()
}
[sideeffects]
def c2da_std_rand_step() : int {
    c2da_std_rand_state[c2da_std_rand_front] += c2da_std_rand_state[c2da_std_rand_rear]
    let result = int(c2da_std_rand_state[c2da_std_rand_front] >> 0x1)
    c2da_std_rand_front++
    c2da_std_rand_rear++
    if (c2da_std_rand_front >= 31) {
        c2da_std_rand_front = 0
    }
    if (c2da_std_rand_rear >= 31) {
        c2da_std_rand_rear = 0
    }
    return result
}
[sideeffects]
def c2da_std_raw_byte(base : uint64; index : uint64) : int {
    if (base == 0x0ul) {
        return 0
    }
    return int(unsafe(unsafe(reinterpret<uint8?>(base))[index])) & 255
}
[sideeffects]
def c2da_std_raw_put(base : uint64; index : uint64; value : int) {
    if (base == 0x0ul) {
        return
    }
    unsafe(unsafe(reinterpret<uint8?>(base))[index]) = uint8(value & 255)
}
[sideeffects]
def c2da_std_raw_string(base : uint64) : string {
    if (base == 0x0ul) {
        return ""
    }
    return build_string($(var writer : StringBuilderWriter) {
        var i : uint64 = 0x0ul
        while (true) {
            let b = c2da_std_raw_byte(base, i)
            if (b == 0) {
                break
            }
            write_char(writer, b)
            i++
        }
    })
}
[sideeffects]
def c2da_std_remove(path : uint64) : int {
    let name : string = c2da_std_raw_string(path)
    if (remove(name)) {
        return 0
    }
    c2da_std_path_errno(name)
    return -1
}
[sideeffects]
def c2da_std_set_errno(code : int) {
    var cell : uint64 = c2da_std_errno_location()
    unsafe(unsafe(reinterpret<int?>(cell))[0]) = int(code)  // nolint:PERF020
}
[sideeffects]
def c2da_std_setjmp_catch(target : string) {
    if (c2da_std_jmp_target != target) {
        panic("c2da_std_setjmp_catch: not a longjmp to this jmp_buf")
    }
    c2da_std_jmp_target = ""
}
[sideeffects]
def c2da_std_setvbuf(handle : uint64; buffer : uint64; mode : int; size : uint64) : int {
    if (handle == 0x0ul) {
        return -1
    }
    if (mode == 2) {
        funbuffered(c2da_std_file(handle))
    }
    return 0
}
[sideeffects]
def c2da_std_snprintf(dst : uint64; size : uint64; f : int8 const?; args : array<C2daVaArg>) : int {
    let placed : int = c2da_std_place(dst, size, c2da_std_format(f, args))
    return placed + c2da_std_lost_bytes
}
[sideeffects]
def c2da_std_sprintf(dst : uint64; f : int8 const?; args : array<C2daVaArg>) : int {
    return c2da_std_snprintf(dst, 0x7ffffffful, f, args)
}
[sideeffects]
def c2da_std_srand(seed : uint) {
    c2da_std_rand_seeded = true
    var word : int = int(seed)
    if (word == 0) {
        word = 1
    }
    c2da_std_rand_state[0] = uint(word)
    var i : int = 1
    while (i < 31) {
        let hi = word / 127773
        let lo = word % 127773
        word = 16807 * lo - 2836 * hi
        if (word < 0) {
            word += 2147483647
        }
        c2da_std_rand_state[i] = uint(word)
        i++
    }
    c2da_std_rand_front = 3
    c2da_std_rand_rear = 0
    i = 0
    while (i < 310) {
        c2da_std_rand_step()
        i++
    }
}
[sideeffects]
def c2da_std_stderr() : uint64 {
    var stream : FILE const? = fstderr()
    return unsafe(reinterpret<uint64>(stream))
}
[sideeffects]
def c2da_std_stdout() : uint64 {
    var stream : FILE const? = fstdout()
    return unsafe(reinterpret<uint64>(stream))
}
[sideeffects]
def c2da_std_store(s : string) : uint64 {
    let n : int = length(s)
    var base : uint64 = c2da_rt_malloc(uint64(n + 1))
    var i : int = 0
    while (i < n) {
        unsafe(unsafe(reinterpret<uint8?>(base))[i]) = uint8(unsafe(character_uat(s, i)) & 255)
        i++
    }
    unsafe(unsafe(reinterpret<uint8?>(base))[n]) = 0u8
    return base
}
[sideeffects]
def c2da_std_store_addr(cell : uint64; value : uint64) {
    if (cell == 0x0ul) {
        return
    }
    unsafe(unsafe(reinterpret<uint64?>(cell))[0]) = uint64(value)  // nolint:PERF020
}
[sideeffects]
def c2da_std_strcat(dst : uint64; src : uint64) : uint64 {
    c2da_std_strcpy(dst + c2da_std_strlen(dst), src)
    return dst
}
[sideeffects]
def c2da_std_strchr(s : uint64; ch : int) : uint64 {
    if (s == 0x0ul) {
        return 0x0ul
    }
    let target : int = ch & 255
    var i : uint64 = 0x0ul
    while (true) {
        let b = c2da_std_raw_byte(s, i)
        if (b == target) {
            return s + i
        }
        if (b == 0) {
            break
        }
        i++
    }
    return 0x0ul
}
[sideeffects]
def c2da_std_strcmp(a : uint64; b : uint64) : int {
    var i : uint64 = 0x0ul
    while (true) {
        let ca = c2da_std_raw_byte(a, i)
        let cb = c2da_std_raw_byte(b, i)
        if (ca != cb) {
            if (ca < cb) {
                return -1
            }
            return 1
        }
        if (ca == 0) {
            return 0
        }
        i++
    }
    return 0
}
[sideeffects]
def c2da_std_strcpy(dst : uint64; src : uint64) : uint64 {
    var i : uint64 = 0x0ul
    while (true) {
        let c = c2da_std_raw_byte(src, i)
        c2da_std_raw_put(dst, i, c)
        if (c == 0) {
            break
        }
        i++
    }
    return dst
}
[sideeffects]
def c2da_std_stream_fail(handle : uint64) {
    if (handle == 0x0ul) {
        return
    }
    let slot = c2da_std_stream_slot(handle)
    c2da_std_stream_flags[slot] = 1
}
[sideeffects]
def c2da_std_stream_open(handle : uint64) {
    let slot = c2da_std_stream_slot(handle)
    c2da_std_stream_flags[slot] = 0
    c2da_std_stream_push[slot] = -1
    c2da_std_stream_fd[slot] = int(c2da_std_stream_next_fd)  // nolint:PERF020
    c2da_std_stream_next_fd++
}
[sideeffects]
def c2da_std_stream_slot(handle : uint64) : int {
    var i : int = 0
    while (i < length(c2da_std_stream_keys)) {
        if (c2da_std_stream_keys[i] == handle) {
            return i
        }
        i++
    }
    push(c2da_std_stream_keys, handle)
    push(c2da_std_stream_flags, 0)
    push(c2da_std_stream_push, -1)
    push(c2da_std_stream_fd, c2da_std_stream_next_fd)
    c2da_std_stream_next_fd++
    return i
}
[sideeffects]
def c2da_std_stream_take_push(handle : uint64) : int {
    if (handle == 0x0ul) {
        return -1
    }
    let slot = c2da_std_stream_slot(handle)
    let pushed : int = c2da_std_stream_push[slot]
    c2da_std_stream_push[slot] = -1
    return pushed
}
[sideeffects]
def c2da_std_strerror(code : int) : uint64 {
    return c2da_std_own_text(0, c2da_std_strerror_text(code))
}
[sideeffects]
def c2da_std_strerror_text(code : int) : string {
    if (code == 1) {
        return "Operation not permitted"
    } elif (code == 2) {
        return "No such file or directory"
    } elif (code == 4) {
        return "Interrupted system call"
    } elif (code == 5) {
        return "Input/output error"
    } elif (code == 9) {
        return "Bad file descriptor"
    } elif (code == 11) {
        return "Resource temporarily unavailable"
    } elif (code == 12) {
        return "Cannot allocate memory"
    } elif (code == 13) {
        return "Permission denied"
    } elif (code == 16) {
        return "Device or resource busy"
    } elif (code == 17) {
        return "File exists"
    } elif (code == 21) {
        return "Is a directory"
    } elif (code == 22) {
        return "Invalid argument"
    } elif (code == 28) {
        return "No space left on device"
    } elif (code == 29) {
        return "Illegal seek"
    } elif (code == 34) {
        return "Numerical result out of range"
    } elif (code == 38) {
        return "Function not implemented"
    } elif (code == 75) {
        return "Value too large for defined data type"
    }
    if (code < 0) {
        return "Unknown error -" + c2da_std_utoa(uint64(0 - code), 10, false)
    }
    return "Unknown error " + c2da_std_utoa(uint64(code), 10, false)
}
[sideeffects]
def c2da_std_string(s : int8 const?) : string {
    if (s == null) {
        return ""
    }
    return build_string($(var writer : StringBuilderWriter) {
        var i : int = 0
        while (true) {
            let b = c2da_std_byte(s, i)
            if (b == 0) {
                break
            }
            write_char(writer, b)
            i++
        }
    })
}
[sideeffects]
def c2da_std_strlen(s : uint64) : uint64 {
    var n : uint64 = 0x0ul
    while (c2da_std_raw_byte(s, n) != 0) {
        n++
    }
    return n
}
[sideeffects]
def c2da_std_strncmp(a : uint64; b : uint64; n : uint64) : int {
    var i : uint64 = 0x0ul
    while (i < n) {
        let ca = c2da_std_raw_byte(a, i)
        let cb = c2da_std_raw_byte(b, i)
        if (ca != cb) {
            if (ca < cb) {
                return -1
            }
            return 1
        }
        if (ca == 0) {
            return 0
        }
        i++
    }
    return 0
}
[sideeffects]
def c2da_std_strncpy(dst : uint64; src : uint64; n : uint64) : uint64 {
    var i : uint64 = 0x0ul
    while (i < n) {
        let c = c2da_std_raw_byte(src, i)
        c2da_std_raw_put(dst, i, c)
        if (c == 0) {
            break
        }
        i++
    }
    while (i < n) {
        c2da_std_raw_put(dst, i, 0)
        i++
    }
    return dst
}
[sideeffects]
def c2da_std_strstr(h : uint64; n : uint64) : uint64 {
    if (h == 0x0ul) {
        return 0x0ul
    }
    if (c2da_std_raw_byte(n, 0x0ul) == 0) {
        return h
    }
    var i : uint64 = 0x0ul
    while (c2da_std_raw_byte(h, i) != 0) {
        var j : uint64 = 0x0ul
        while (c2da_std_raw_byte(n, j) != 0 && c2da_std_raw_byte(h, i + j) == c2da_std_raw_byte(n, j)) {
            j++
        }
        if (c2da_std_raw_byte(n, j) == 0) {
            return h + i
        }
        i++
    }
    return 0x0ul
}
[sideeffects]
def c2da_std_strto(nptr : uint64; endptr : uint64; base : int; pos_limit : uint64; neg_limit : uint64) : uint64 {
    if (base != 0 && (base < 2 || base > 36)) {
        c2da_std_set_errno(22)
        return 0x0ul
    }
    c2da_std_store_addr(endptr, nptr)
    if (nptr == 0x0ul) {
        return 0x0ul
    }
    var i : uint64 = 0x0ul
    while (c2da_std_isspace(c2da_std_raw_byte(nptr, i)) != 0) {
        i++
    }
    var neg : bool = false
    let sign = c2da_std_raw_byte(nptr, i)
    if (sign == 45) {
        neg = true
        i++
    } elif (sign == 43) {
        i++
    }
    var radix : uint64 = 0xaul
    if ((base == 0 || base == 16) && (c2da_std_raw_byte(nptr, i) == 48 && ((c2da_std_raw_byte(nptr, i + 0x1ul) | 32) == 120 && c2da_std_digit(c2da_std_raw_byte(nptr, i + 0x2ul), 16) >= 0))) {
        i += 0x2ul
        radix = 0x10ul
    } elif (base != 0) {
        radix = uint64(base)
    } elif (c2da_std_raw_byte(nptr, i) == 48) {
        radix = 0x8ul
    }
    var limit : uint64 = pos_limit
    if (neg) {
        limit = neg_limit
    }
    var acc : uint64 = 0x0ul
    var any : bool = false
    var over : bool = false
    while (true) {
        let d = c2da_std_digit(c2da_std_raw_byte(nptr, i), int(radix))
        if (d < 0) {
            break
        }
        any = true
        let dv = uint64(d)
        if (acc > limit / radix || acc == limit / radix && dv > limit % radix) {
            over = true
        } else {
            acc = acc * radix + dv
        }
        i++
    }
    if (!any) {
        return 0x0ul
    }
    c2da_std_store_addr(endptr, nptr + i)
    if (over) {
        c2da_std_set_errno(34)
        return limit
    }
    if (neg) {
        return 0x0ul - acc
    }
    return acc
}
[sideeffects]
def c2da_std_strtod(nptr : uint64; endptr : uint64) : double {
    c2da_std_store_addr(endptr, nptr)
    if (nptr == 0x0ul) {
        return 0.0lf
    }
    var i : uint64 = 0x0ul
    while (c2da_std_isspace(c2da_std_raw_byte(nptr, i)) != 0) {
        i++
    }
    var negative : bool = false
    let sign = c2da_std_raw_byte(nptr, i)
    if (sign == 45) {
        negative = true
        i++
    } elif (sign == 43) {
        i++
    }
    if (c2da_std_raw_byte(nptr, i) == 48 && (c2da_std_raw_byte(nptr, i + 0x1ul) | 32) == 120) {
        panic("--libc std: strtod does not implement hexadecimal floating constants")
    }
    let head = c2da_std_raw_byte(nptr, i) | 32
    if (head == 105 || head == 110) {
        panic("--libc std: strtod does not implement inf and nan")
    }
    let start : uint64 = i
    var digits : int = 0
    var exponent : int = 0
    var nonzero : bool = false
    var lead : bool = true
    var point : bool = false
    while (true) {
        let b = c2da_std_raw_byte(nptr, i)
        if (is_number(b)) {
            digits++
            if (b != 48) {
                nonzero = true
                lead = false
            }
            if (!point) {
                if (!lead) {
                    exponent++
                }
            } else {
                if (lead) {
                    exponent--
                }
            }
            i++
        } elif (b == 46 && !point) {
            point = true
            i++
        } else {
            break
        }
    }
    if (digits == 0) {
        return 0.0lf
    }
    var stop : uint64 = i
    if ((c2da_std_raw_byte(nptr, i) | 32) == 101) {
        var j : uint64 = i + 0x1ul
        var negative_exponent : bool = false
        if (c2da_std_raw_byte(nptr, j) == 45) {
            negative_exponent = true
            j++
        } elif (c2da_std_raw_byte(nptr, j) == 43) {
            j++
        }
        var written : int = 0
        var value : int = 0
        while (true) {
            let d = c2da_std_digit(c2da_std_raw_byte(nptr, j), 10)
            if (d < 0) {
                break
            }
            if (value < 100000) {
                value = value * 10 + d
            }
            written++
            j++
        }
        if (written > 0) {
            stop = j
            if (negative_exponent) {
                exponent -= value
            } else {
                exponent += value
            }
        }
    }
    c2da_std_store_addr(endptr, nptr + stop)
    let body : string = build_string($(var writer : StringBuilderWriter) {
        var k : uint64 = start
        while (k < stop) {
            write_char(writer, c2da_std_raw_byte(nptr, k))
            k++
        }
    })
    var value : double = to_double(body)
    if (nonzero && (value == 0.0lf || value == c2da_std_huge())) {
        c2da_std_set_errno(34)
        if (exponent > 0) {
            value = c2da_std_huge()
        } else {
            value = 0.0lf
        }
    }
    if (negative) {
        value = 0.0lf - value
    }
    return value
}
[sideeffects]
def c2da_std_take(s : int8 const?; from : int; limit : int) : string {
    if (s == null) {
        return ""
    }
    return build_string($(var writer : StringBuilderWriter) {
        var k : int = 0
        while (k < limit) {
            let ch = c2da_std_byte(s, from + k)
            if (ch == 0) {
                break
            }
            write_char(writer, ch)
            k++
        }
    })
}
[sideeffects]
def c2da_std_ungetc(ch : int; handle : uint64) : int {
    if (handle == 0x0ul || ch < 0) {
        return -1
    }
    let slot = c2da_std_stream_slot(handle)
    if (c2da_std_stream_push[slot] >= 0) {
        return -1
    }
    c2da_std_stream_push[slot] = ch & 255
    return ch & 255
}
[sideeffects]
def c2da_std_utoa(value : uint64; base : int; upper : bool) : string {
    if (value == 0x0ul) {
        return "0"
    }
    let radix : uint64 = uint64(base)
    var rest : uint64 = value
    var out : string = ""
    while (rest != 0x0ul) {
        let d : int = int(rest % radix)
        var code : int = 48
        if (d < 10) {
            code = 48 + d
        } elif (upper) {
            code = 55 + d
        } else {
            code = 87 + d
        }
        out = to_char(code) + out
        rest /= radix
    }
    return out
}
[sideeffects]
def c2da_std_vformat(f : int8 const?; args : array<C2daVaArg>; var start : int&) : string {
    c2da_std_lost_bytes = 0
    if (f == null) {
        return ""
    }
    var next : int = start
    let out : string = build_string($(var writer : StringBuilderWriter) {
        var i : int = 0
        while (true) {
            let ch = c2da_std_byte(f, i)
            if (ch == 0) {
                break
            }
            if (ch != 37) {
                write_char(writer, ch)
                i++
                continue
            }
            var j : int = i + 1
            var left : bool = false
            var zero : bool = false
            var plus : bool = false
            var blank : bool = false
            var alt : bool = false
            var width : int = 0
            var has_precision : bool = false
            var precision : int = 0
            var wide : bool = false
            while (true) {
                let fc = c2da_std_byte(f, j)
                if (fc == 45) {
                    left = true
                } elif (fc == 48) {
                    zero = true
                } elif (fc == 43) {
                    plus = true
                } elif (fc == 32) {
                    blank = true
                } elif (fc == 35) {
                    alt = true
                } else {
                    break
                }
                j++
            }
            if (c2da_std_byte(f, j) == 42) {
                let given : int = int(c2da_std_arg_i64(args, next))
                next++
                j++
                if (given < 0) {
                    left = true
                    width = 0 - given
                } else {
                    width = given
                }
            } else {
                while (true) {
                    let wc = c2da_std_byte(f, j)
                    if (!is_number(wc)) {
                        break
                    }
                    width = width * 10 + (wc - 48)
                    j++
                }
            }
            if (c2da_std_byte(f, j) == 46) {
                j++
                has_precision = true
                if (c2da_std_byte(f, j) == 42) {
                    let given : int = int(c2da_std_arg_i64(args, next))
                    next++
                    j++
                    if (given < 0) {
                        has_precision = false
                    } else {
                        precision = given
                    }
                } else {
                    while (true) {
                        let pc = c2da_std_byte(f, j)
                        if (!is_number(pc)) {
                            break
                        }
                        precision = precision * 10 + (pc - 48)
                        j++
                    }
                }
            }
            while (true) {
                let lc = c2da_std_byte(f, j)
                if (lc == 108 || lc == 122 || lc == 106 || lc == 116) {
                    wide = true
                } elif (lc != 104) {
                    break
                }
                j++
            }
            let conv = c2da_std_byte(f, j)
            if (conv == 37) {
                write(writer, "%")
                i = j + 1
                continue
            }
            if (conv == 0) {
                write(writer, c2da_std_take(f, i, j - i))
                i = j
                continue
            }
            if (conv == 100 || conv == 105) {
                var value : int64 = c2da_std_arg_i64(args, next)
                if (!wide) {
                    value = int64(int(value))
                }
                var magnitude : uint64 = unsafe(reinterpret<uint64>(value))
                var sign : string = ""
                if (value < 0l) {
                    sign = "-"
                    magnitude = 0x0ul - magnitude
                } elif (plus) {
                    sign = "+"
                } elif (blank) {
                    sign = " "
                }
                write(writer, c2da_std_number(magnitude, 10, false, sign, false, has_precision, precision, width, left, zero))
                next++
            } elif (conv == 117 || conv == 120 || conv == 88 || conv == 111) {
                var uvalue : uint64 = c2da_std_arg_u64(args, next)
                if (!wide) {
                    uvalue = uint64(uint(uvalue))
                }
                var radix : int = 10
                if (conv == 120 || conv == 88) {
                    radix = 16
                } elif (conv == 111) {
                    radix = 8
                }
                write(writer, c2da_std_number(uvalue, radix, conv == 88, "", alt, has_precision, precision, width, left, zero))
                next++
            } elif (conv == 99) {
                let code : int = int(c2da_std_arg_i64(args, next)) & 255
                var field : int = width
                if (code == 0) {
                    c2da_std_lost_bytes++
                    field--
                }
                write(writer, c2da_std_pad(to_char(code), field, left))
                next++
            } elif (conv == 102 || conv == 70 || conv == 101 || conv == 69 || conv == 103 || conv == 71) {
                var spec : string = ":"
                if (left) {
                    spec += "<"
                }
                if (plus) {
                    spec += "+"
                } elif (blank) {
                    spec += " "
                }
                if (alt) {
                    spec += "#"
                }
                if (zero && !left) {
                    spec += "0"
                }
                if (width > 0) {
                    spec += c2da_std_utoa(uint64(width), 10, false)
                }
                if (has_precision) {
                    spec += "."
                    spec += c2da_std_utoa(uint64(precision), 10, false)
                }
                write(writer, fmt(spec + to_char(conv), c2da_std_arg_f64(args, next)))
                next++
            } elif (conv == 115) {
                let address : uint64 = c2da_std_arg_u64(args, next)
                var body : string = ""
                if (address == 0x0ul) {
                    if (!(has_precision && precision < 6)) {
                        body = "(null)"
                    }
                } elif (has_precision) {
                    body = c2da_std_take(unsafe(reinterpret<int8 const?>(address)), 0, precision)
                } else {
                    body = c2da_std_string(unsafe(reinterpret<int8 const?>(address)))
                }
                write(writer, c2da_std_pad(body, width, left))
                next++
            } elif (conv == 112) {
                let target : uint64 = c2da_std_arg_u64(args, next)
                var body : string = "(nil)"
                if (target != 0x0ul) {
                    body = "0x" + c2da_std_utoa(target, 16, false)
                }
                write(writer, c2da_std_pad(body, width, left))
                next++
            } elif (conv == 110) {
                next++
            } else {
                panic("--libc std: printf conversion is not implemented: " + c2da_std_take(f, i, j + 1 - i))
            }
            i = j + 1
        }
    })
    start = next
    return out
}
[sideeffects]
def c2da_std_vfprintf(handle : uint64; f : int8 const?; var ap : C2daVaCursor; args : array<C2daVaArg>) : int {
    var from : int = ap.index
    let body : string = c2da_std_vformat(f, args, from)
    ap.index = from
    c2da_std_write(handle, body)
    return length(body) + c2da_std_lost_bytes
}
[sideeffects]
def c2da_std_vsnprintf(dst : uint64; size : uint64; f : int8 const?; var ap : C2daVaCursor; args : array<C2daVaArg>) : int {
    var from : int = ap.index
    let body : string = c2da_std_vformat(f, args, from)
    ap.index = from
    let placed : int = c2da_std_place(dst, size, body)
    return placed + c2da_std_lost_bytes
}
[sideeffects]
def c2da_std_vsprintf(dst : uint64; f : int8 const?; var ap : C2daVaCursor; args : array<C2daVaArg>) : int {
    return c2da_std_vsnprintf(dst, 0x7ffffffful, f, ap, args)
}
[sideeffects]
def c2da_std_write(handle : uint64; body : string) {
    if (handle == 0x0ul) {
        return
    }
    fprint(c2da_std_file(handle), body)
}
