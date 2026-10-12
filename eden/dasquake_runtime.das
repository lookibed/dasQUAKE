options gen2
options stack = 4194304
module dasquake_runtime public

require strings
require daslib/math_bits
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
    prev : int
    next : int
}
struct link_t {
    prev : int
    next : int
}
struct cache_user_s {
    data : int
}
struct cvar_s {
    name : int
    string_0 : int
    archive : uint
    server : uint
    value : float
    next : int
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
    pnext : int
}
struct vrect_t {
    x : int
    y : int
    width : int
    height : int
    pnext : int
}
struct cache_user_t {
    data : int
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
    name : int
    string_0 : int
    archive : uint
    server : uint
    value : float
    next : int
}
struct sfx_s {
    name : int8[64]
    cache : cache_user_s
}
struct efrag_s {
    leaf : int
    leafnext : int
    entity : int
    entnext : int
}
struct entity_s {
    forcelink : uint
    update_type : int
    baseline : entity_state_t
    msgtime : double
    msg_origins : vec3_t[2]
    origin : vec3_t
    msg_angles : vec3_t[2]
    angles : vec3_t
    model : int
    efrag : int
    frame : int
    syncbase : float
    colormap : int
    effects : int
    skinnum : int
    visframe : int
    dlightframe : int
    dlightbits : int
    trivial_accept : int
    topnode : int
}
struct mnode_s {
    contents : int
    visframe : int
    minmaxs : int16[6]
    parent : int
    plane : int
    children : int[2]
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
    clipnodes : int
    planes : int
    firstclipnode : int
    lastclipnode : int
    clip_mins : vec3_t
    clip_maxs : vec3_t
}
struct model_s {
    name : int8[64]
    needload : uint
    type_0 : uint
    numframes : int
    synctype : uint
    flags : int
    mins : vec3_t
    maxs : vec3_t
    radius : float
    firstmodelsurface : int
    nummodelsurfaces : int
    numsubmodels : int
    submodels : int
    numplanes : int
    planes : int
    numleafs : int
    leafs : int
    numvertexes : int
    vertexes : int
    numedges : int
    edges : int
    numnodes : int
    nodes : int
    numtexinfo : int
    texinfo : int
    numsurfaces : int
    surfaces : int
    numsurfedges : int
    surfedges : int
    numclipnodes : int
    clipnodes : int
    nummarksurfaces : int
    marksurfaces : int
    hulls : hull_t[4]
    numtextures : int
    textures : int
    visdata : int
    lightdata : int
    entities : int
    cache : cache_user_s
}
struct texture_t {
    name : int8[16]
    width : uint
    height : uint
    anim_total : int
    anim_min : int
    anim_max : int
    anim_next : int
    alternate_anims : int
    offsets : uint[4]
}
struct texture_s {
    name : int8[16]
    width : uint
    height : uint
    anim_total : int
    anim_min : int
    anim_max : int
    anim_next : int
    alternate_anims : int
    offsets : uint[4]
}
struct msurface_t {
    visframe : int
    dlightframe : int
    dlightbits : int
    plane : int
    flags : int
    firstedge : int
    numedges : int
    cachespots : int[4]
    texturemins : int16[2]
    extents : int16[2]
    texinfo : int
    styles : uint8[4]
    samples : int
}
struct msurface_s {
    visframe : int
    dlightframe : int
    dlightbits : int
    plane : int
    flags : int
    firstedge : int
    numedges : int
    cachespots : int[4]
    texturemins : int16[2]
    extents : int16[2]
    texinfo : int
    styles : uint8[4]
    samples : int
}
struct mtexinfo_t {
    vecs : float[2][4]
    mipadjust : float
    texture : int
    flags : int
}
struct surfcache_s {
    next : int
    owner : int
    lightadj : int[4]
    dlight : int
    size : int
    width : uint
    height : uint
    mipscale : float
    texture : int
    data : uint8[4]
}
struct mnode_t {
    contents : int
    visframe : int
    minmaxs : int16[6]
    parent : int
    plane : int
    children : int[2]
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
    parent : int
    compressed_vis : int
    efrags : int
    firstmarksurface : int
    nummarksurfaces : int
    key : int
    ambient_sound_level : uint8[4]
}
struct mleaf_s {
    contents : int
    visframe : int
    minmaxs : int16[6]
    parent : int
    compressed_vis : int
    efrags : int
    firstmarksurface : int
    nummarksurfaces : int
    key : int
    ambient_sound_level : uint8[4]
}
struct efrag_t {
    leaf : int
    leafnext : int
    entity : int
    entnext : int
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
struct entity_t {
    forcelink : uint
    update_type : int
    baseline : entity_state_t
    msgtime : double
    msg_origins : vec3_t[2]
    origin : vec3_t
    msg_angles : vec3_t[2]
    angles : vec3_t
    model : int
    efrag : int
    frame : int
    syncbase : float
    colormap : int
    effects : int
    skinnum : int
    visframe : int
    dlightframe : int
    dlightbits : int
    trivial_accept : int
    topnode : int
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
    nodrift : uint
    driftmove : float
    laststop : double
    viewheight : float
    crouch : float
    paused : uint
    onground : uint
    inwater : uint
    intermission : int
    completed_time : int
    mtime : double[2]
    time : double
    oldtime : double
    last_received_message : float
    model_precache : int[256]
    sound_precache : int[256]
    levelname : int8[40]
    viewentity : int
    maxclients : int
    gametype : int
    worldmodel : int
    free_efrags : int
    num_entities : int
    num_statics : int
    viewent : entity_s
    cdtrack : int
    looptrack : int
    scores : int
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
    free : uint
    area : link_s
    num_leafs : int
    leafnums : int16[16]
    baseline : entity_state_t
    freetime : float
    v : entvars_t
}
struct edict_t {
    free : uint
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
    allsolid : uint
    startsolid : uint
    inopen : uint
    inwater : uint
    fraction : float
    endpos : vec3_t
    plane : plane_t
    ent : int
}
struct _IO_FILE {
    _flags : int
    _IO_read_ptr : int
    _IO_read_end : int
    _IO_read_base : int
    _IO_write_base : int
    _IO_write_ptr : int
    _IO_write_end : int
    _IO_buf_base : int
    _IO_buf_end : int
    _IO_save_base : int
    _IO_backup_base : int
    _IO_save_end : int
    _markers : int
    _chain : int
    _fileno : int
    _flags2 : int
    _old_offset : int64
    _cur_column : uint16
    _vtable_offset : int8
    _shortbuf : int8[1]
    _lock : int
    _offset : int64
    _codecvt : int
    _wide_data : int
    _freeres_list : int
    _freeres_buf : int
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
    _IO_read_ptr : int
    _IO_read_end : int
    _IO_read_base : int
    _IO_write_base : int
    _IO_write_ptr : int
    _IO_write_end : int
    _IO_buf_base : int
    _IO_buf_end : int
    _IO_save_base : int
    _IO_backup_base : int
    _IO_save_end : int
    _markers : int
    _chain : int
    _fileno : int
    _flags2 : int
    _old_offset : int64
    _cur_column : uint16
    _vtable_offset : int8
    _shortbuf : int8[1]
    _lock : int
    _offset : int64
    _codecvt : int
    _wide_data : int
    _freeres_list : int
    _freeres_buf : int
    c2da___pad5 : uint64
    _mode : int
    _unused2 : int8[20]
}
struct sizebuf_s {
    allowoverflow : uint
    overflowed : uint
    data : int
    maxsize : int
    cursize : int
}
struct sizebuf_t {
    allowoverflow : uint
    overflowed : uint
    data : int
    maxsize : int
    cursize : int
}
struct qsockaddr {
    sa_family : int16
    sa_data : uint8[14]
}
struct qsocket_s {
    next : int
    connecttime : double
    lastMessageTime : double
    lastSendTime : double
    disconnected : uint
    canSend : uint
    sendNext : uint
    driver : int
    landriver : int
    socket : int
    driverdata : int
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
    state : uint
    mapstring : int8[64]
    spawnparms : int8[2048]
    demonum : int
    demos : int8[8][16]
    demorecording : uint
    demoplayback : uint
    timedemo : uint
    forcetrack : int
    demofile : int
    td_lastframe : int
    td_startframe : int
    td_starttime : float
    signon : int
    netcon : int
    message : sizebuf_s
}
typedef xcommand_t = int
struct kbutton_t {
    down : int[2]
    state : int
}
struct qsocket_t {
    next : int
    connecttime : double
    lastMessageTime : double
    lastSendTime : double
    disconnected : uint
    canSend : uint
    sendNext : uint
    driver : int
    landriver : int
    socket : int
    driverdata : int
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
    model : int
    endtime : float
    start : vec3_t
    end : vec3_t
}
struct server_t {
    active : uint
    paused : uint
    loadgame : uint
    time : double
    lastcheck : int
    lastchecktime : double
    name : int8[64]
    modelname : int8[64]
    worldmodel : int
    model_precache : int[256]
    models : int[256]
    sound_precache : int[256]
    lightstyles : int[64]
    num_edicts : int
    max_edicts : int
    edicts : int
    state : uint
    datagram : sizebuf_s
    datagram_buf : uint8[1024]
    reliable_datagram : sizebuf_s
    reliable_datagram_buf : uint8[1024]
    signon : sizebuf_s
    signon_buf : uint8[8192]
}
enum server_state_t : uint {
    ss_loading = 0
    ss_active = 1
}
typedef pixel_t = uint8
struct viddef_t {
    buffer : int
    colormap : int
    colormap16 : int
    fullbright : int
    rowbytes : uint
    width : uint
    height : uint
    aspect : float
    numpages : int
    recalc_refdef : int
    conbuffer : int
    conrowbytes : int
    conwidth : uint
    conheight : uint
    maxwarpwidth : int
    maxwarpheight : int
    direct : int
}
struct sfx_t {
    name : int8[64]
    cache : cache_user_s
}
struct model_t {
    name : int8[64]
    needload : uint
    type_0 : uint
    numframes : int
    synctype : uint
    flags : int
    mins : vec3_t
    maxs : vec3_t
    radius : float
    firstmodelsurface : int
    nummodelsurfaces : int
    numsubmodels : int
    submodels : int
    numplanes : int
    planes : int
    numleafs : int
    leafs : int
    numvertexes : int
    vertexes : int
    numedges : int
    edges : int
    numnodes : int
    nodes : int
    numtexinfo : int
    texinfo : int
    numsurfaces : int
    surfaces : int
    numsurfedges : int
    surfedges : int
    numclipnodes : int
    clipnodes : int
    nummarksurfaces : int
    marksurfaces : int
    hulls : hull_t[4]
    numtextures : int
    textures : int
    visdata : int
    lightdata : int
    entities : int
    cache : cache_user_s
}
struct cmdalias_t {
    next : int
    name : int8[32]
    value : int
}
struct cmdalias_s {
    next : int
    name : int8[32]
    value : int
}
struct cmd_function_t {
    next : int
    name : int
    function_0 : xcommand_t
}
struct cmd_function_s {
    next : int
    name : int
    function_0 : xcommand_t
}
struct c2da___va_list_tag {
    gp_offset : uint
    fp_offset : uint
    overflow_arg_area : int
    reg_save_area : int
}
typedef va_list = c2da___va_list_tag[1]
typedef intptr_t = int64
struct Unnamed_common_563 {
    c2da_storage : uint64 = 0ul
}
struct Unnamed_common_679 {
    c2da_storage : uint64 = 0ul
}
struct pack_t {
    filename : int8[128]
    handle : int
    numfiles : int
    files : int
}
struct pack_s {
    filename : int8[128]
    handle : int
    numfiles : int
    files : int
}
struct packfile_t {
    name : int8[64]
    filepos : int
    filelen : int
}
struct searchpath_t {
    filename : int8[128]
    pack : int
    next : int
}
struct searchpath_s {
    filename : int8[128]
    pack : int
    next : int
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
    basedir : int
    cachedir : int
    argc : int
    argv : int
    membase : int
    memsize : int
}
struct Unnamed_common_477 {
    c2da_storage : uint64 = 0ul
}
enum keydest_t : uint {
    key_game = 0
    key_console = 1
    key_message = 2
    key_menu = 3
}
typedef fixed16_t = int
struct surf_t {
    next : int
    prev : int
    spans : int
    key : int
    last_u : int
    spanstate : int
    flags : int
    data : int
    entity : int
    nearzi : float
    insubmodel : uint
    d_ziorigin : float
    d_zistepu : float
    d_zistepv : float
    pad : int[2]
}
struct surf_s {
    next : int
    prev : int
    spans : int
    key : int
    last_u : int
    spanstate : int
    flags : int
    data : int
    entity : int
    nearzi : float
    insubmodel : uint
    d_ziorigin : float
    d_zistepu : float
    d_zistepv : float
    pad : int[2]
}
struct espan_s {
    u : int
    v : int
    count : int
    pnext : int
}
struct espan_t {
    u : int
    v : int
    count : int
    pnext : int
}
struct surfcache_t {
    next : int
    owner : int
    lightadj : int[4]
    dlight : int
    size : int
    width : uint
    height : uint
    mipscale : float
    texture : int
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
    next : int
    vel : vec3_t
    ramp : float
    die : float
    type_0 : uint
}
struct particle_t {
    org : vec3_t
    color : float
    next : int
    vel : vec3_t
    ramp : float
    die : float
    type_0 : uint
}
typedef fixed8_t = int
enum aliasskintype_t : uint {
    ALIAS_SKIN_SINGLE = 0
    ALIAS_SKIN_GROUP = 1
}
struct maliasskindesc_t {
    type_0 : uint
    pcachespot : int
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
    pskin : int
    pskindesc : int
    skinwidth : int
    skinheight : int
    ptriangles : int
    pfinalverts : int
    numtriangles : int
    drawtype : int
    seamfixupX16 : int
}
struct spanpackage_t {
    pdest : int
    pz : int
    count : int
    ptex : int
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
    pleftedgevert0 : int
    pleftedgevert1 : int
    pleftedgevert2 : int
    numrightedges : int
    prightedgevert0 : int
    prightedgevert1 : int
    prightedgevert2 : int
}
struct mspriteframe_s {
    width : int
    height : int
    pcachespot : int
    up : float
    down : float
    left : float
    right : float
    pixels : uint8[4]
}
struct mspriteframe_t {
    width : int
    height : int
    pcachespot : int
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
    pverts : int
    pspriteframe : int
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
    surfdat : int
    rowbytes : int
    surf : int
    lightadj : int[4]
    texture : int
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
    ptexbytes : int
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
    c2da_storage : uint64 = 0ul
}
struct client_s {
    active : uint
    spawned : uint
    dropasap : uint
    privileged : uint
    sendsignon : uint
    last_message : double
    netconnection : int
    cmd : usercmd_t
    wishdir : vec3_t
    message : sizebuf_s
    msgbuf : uint8[8000]
    edict : int
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
    clients : int
    serverflags : int
    changelevel_issued : uint
}
struct client_t {
    active : uint
    spawned : uint
    dropasap : uint
    privileged : uint
    sendsignon : uint
    last_message : double
    netconnection : int
    cmd : usercmd_t
    wishdir : vec3_t
    message : sizebuf_s
    msgbuf : uint8[8000]
    edict : int
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
    type_0 : uint
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
    name : int
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
    description : int
    firstLevel : int
    levels : int
}
struct level_t {
    name : int
    description : int
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
    synctype : uint
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
    type_0 : uint
}
struct daliasskintype_t {
    type_0 : uint
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
    synctype : uint
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
    type_0 : uint
}
struct mspritegroup_t {
    numframes : int
    intervals : int
    frames : int[1]
}
struct mspriteframedesc_t {
    type_0 : uint
    frameptr : int
}
struct msprite_t {
    type_0 : int
    maxwidth : int
    maxheight : int
    numframes : int
    beamlength : float
    cachespot : int
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
    name : int
    initialized : uint
    Init : int
    Listen : int
    SearchForHosts : int
    Connect : int
    CheckNewConnections : int
    QGetMessage : int
    QSendMessage : int
    SendUnreliableMessage : int
    CanSendMessage : int
    CanSendUnreliableMessage : int
    Close : int
    Shutdown : int
    controlSock : int
}
struct PollProcedure {
    next : int
    nextTime : double
    procedure : int
    arg : int
}
struct _PollProcedure {
    next : int
    nextTime : double
    procedure : int
    arg : int
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
    name : int
    initialized : uint
    controlSock : int
    Init : int
    Shutdown : int
    Listen : int
    OpenSocket : int
    CloseSocket : int
    Connect : int
    CheckNewConnections : int
    Read : int
    Write : int
    Broadcast : int
    AddrToString : int
    StringToAddr : int
    GetSocketAddr : int
    GetNameFromAddr : int
    GetAddrFromName : int
    AddrCompare : int
    GetSocketPort : int
    SetSocketPort : int
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
typedef builtin_t = int
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
    pcache : int
    field : int8[64]
}
struct prstack_t {
    s : int
    f : int
}
struct auxvert_t {
    fv : float[3]
}
struct alight_t {
    ambientlight : int
    shadelight : int
    plightvec : int
}
struct aedge_t {
    index0 : int
    index1 : int
}
struct bedge_s {
    v : int[2]
    pnext : int
}
struct bedge_t {
    v : int[2]
    pnext : int
}
struct clipplane_s {
    normal : vec3_t
    dist : float
    next : int
    leftedge : uint8
    rightedge : uint8
    reserved : uint8[2]
}
struct clipplane_t {
    normal : vec3_t
    dist : float
    next : int
    leftedge : uint8
    rightedge : uint8
    reserved : uint8[2]
}
struct btofpoly_t {
    clipflags : int
    psurf : int
}
struct btofpoly_s {
    clipflags : int
    psurf : int
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
    pcurrentface : int
    pverts : int
}
struct polydesc_t {
    numverts : int
    nearzi : float
    pcurrentface : int
    pverts : int
}
struct edge_s {
    u : int
    u_step : int
    prev : int
    next : int
    surfs : uint16[2]
    nextremove : int
    nearzi : float
    owner : int
}
struct edge_t {
    u : int
    u_step : int
    prev : int
    next : int
    surfs : uint16[2]
    nextremove : int
    nearzi : float
    owner : int
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
    children : int[2]
    trigger_edicts : link_s
    solid_edicts : link_s
}
struct areanode_s {
    axis : int
    dist : float
    children : int[2]
    trigger_edicts : link_s
    solid_edicts : link_s
}
struct moveclip_t {
    boxmins : vec3_t
    boxmaxs : vec3_t
    mins : int
    maxs : int
    mins2 : vec3_t
    maxs2 : vec3_t
    start : int
    end : int
    trace : trace_t
    type_0 : int
    passedict : int
}
struct memblock_s {
    size : int
    tag : int
    id : int
    next : int
    prev : int
    pad : int
}
struct memzone_t {
    size : int
    blocklist : memblock_s
    rover : int
}
struct memblock_t {
    size : int
    tag : int
    id : int
    next : int
    prev : int
    pad : int
}
struct hunk_t {
    sentinal : int
    size : int
    name : int8[8]
}
struct cache_system_t {
    size : int
    user : int
    name : int8[16]
    prev : int
    next : int
    lru_prev : int
    lru_next : int
}
struct cache_system_s {
    size : int
    user : int
    name : int8[16]
    prev : int
    next : int
    lru_prev : int
    lru_next : int
}
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

var c2da_eden_err_text : string = ""

var c2da_eden_exit_code : int = 0

var c2da_eden_exiting : bool = false

var c2da_eden_file_data : array<array<uint8>>

var c2da_eden_file_names : array<string>

var c2da_eden_open_file : array<int>

var c2da_eden_open_pos : array<int64>

var c2da_eden_out_text : string = ""

var c2da_std_jmp_target : string = ""

var c2da_std_rand_front : int = 3

var c2da_std_rand_rear : int = 0

var c2da_std_rand_seeded : bool = false

var c2da_std_rand_state : uint[31]

var c2da_std_stream_fd : array<int>

var c2da_std_stream_flags : array<int>

var c2da_std_stream_keys : array<uint64>

var c2da_std_stream_next_fd : int = 3

var c2da_std_stream_push : array<int>

[sideeffects]
def c2da_eden_add_file(name : string; var bytes : array<uint8>) {
    push(c2da_eden_file_names, name)
    emplace(c2da_eden_file_data, bytes)
}
[sideeffects]
def c2da_eden_exit(code : int) {
    c2da_eden_flush_all()
    c2da_eden_exit_code = int(code)  // nolint:PERF020
    c2da_eden_exiting = true
    panic("c2da: exit")
}
[sideeffects]
def c2da_eden_fclose(handle : uint64) {
    if (handle < 0x10ul) {
        c2da_eden_fflush(handle)
        return
    }
    let slot : int = int(handle - 0x10ul)
    if (slot < length(c2da_eden_open_file)) {
        c2da_eden_open_file[slot] = -1
    }
}
[sideeffects]
def c2da_eden_feof(handle : uint64) : bool {
    if (handle < 0x10ul) {
        return true
    }
    let slot : int = int(handle - 0x10ul)
    if (slot >= length(c2da_eden_open_file) || c2da_eden_open_file[slot] < 0) {
        return true
    }
    let file : int = c2da_eden_open_file[slot]
    let size : int64 = int64(length(c2da_eden_file_data[file]))
    return c2da_eden_open_pos[slot] >= size
}
[sideeffects]
def c2da_eden_fflush(handle : uint64) {
    c2da_eden_flush_all()
}
[sideeffects]
def c2da_eden_find_file(path : string) : int {
    var i : int = length(c2da_eden_file_names) - 1
    while (i >= 0) {
        if (c2da_eden_file_names[i] == path) {
            return i
        }
        i--
    }
    return -1
}
[sideeffects]
def c2da_eden_flush_all() {
    if (!empty(c2da_eden_out_text)) {
        print(c2da_eden_out_text)
        c2da_eden_out_text = ""
    }
    if (!empty(c2da_eden_err_text)) {
        to_log(LOG_ERROR, c2da_eden_err_text)
        c2da_eden_err_text = ""
    }
}
[sideeffects]
def c2da_eden_fopen(path : string; mode : string) : uint64 {
    if (first_character(mode) != 114 || find(mode, "+") >= 0) {
        return 0x0ul
    }
    let file : int = c2da_eden_find_file(path)
    if (file < 0) {
        return 0x0ul
    }
    return c2da_eden_slot(file)
}
[sideeffects]
def c2da_eden_fseek(handle : uint64; offset : int64; whence : int) : int64 {
    if (handle < 0x10ul) {
        return -1l
    }
    let slot : int = int(handle - 0x10ul)
    if (slot >= length(c2da_eden_open_file) || c2da_eden_open_file[slot] < 0) {
        return -1l
    }
    let file : int = c2da_eden_open_file[slot]
    let size : int64 = int64(length(c2da_eden_file_data[file]))
    var base : int64 = 0l
    if (whence == 1) {
        base = c2da_eden_open_pos[slot]
    } elif (whence == 2) {
        base = size
    }
    let to : int64 = base + offset
    if (to < 0l) {
        return -1l
    }
    c2da_eden_open_pos[slot] = to
    return 0l
}
[sideeffects]
def c2da_eden_ftell(handle : uint64) : int64 {
    if (handle < 0x10ul) {
        return -1l
    }
    let slot : int = int(handle - 0x10ul)
    if (slot >= length(c2da_eden_open_file) || c2da_eden_open_file[slot] < 0) {
        return -1l
    }
    let file : int = c2da_eden_open_file[slot]
    let size : int64 = int64(length(c2da_eden_file_data[file]))
    return c2da_eden_open_pos[slot]
}
[sideeffects]
def c2da_eden_output(handle : uint64; body : string) {
    if (handle == 0x1ul) {
        c2da_eden_out_text += body
        var cut : int = -1
        var i : int = length(c2da_eden_out_text) - 1
        while (i >= 0) {
            if (character_at(c2da_eden_out_text, i) == 10) {
                cut = i
                break
            }
            i--
        }
        if (cut >= 0) {
            print(slice(c2da_eden_out_text, 0, cut + 1))
            c2da_eden_out_text = slice(c2da_eden_out_text, cut + 1)
        }
    } elif (handle == 0x2ul) {
        c2da_eden_err_text += body
        var cut : int = -1
        var i : int = length(c2da_eden_err_text) - 1
        while (i >= 0) {
            if (character_at(c2da_eden_err_text, i) == 10) {
                cut = i
                break
            }
            i--
        }
        if (cut >= 0) {
            to_log(LOG_ERROR, slice(c2da_eden_err_text, 0, cut + 1))
            c2da_eden_err_text = slice(c2da_eden_err_text, cut + 1)
        }
    }
}
[sideeffects]
def c2da_eden_slot(file : int) : uint64 {
    push(c2da_eden_open_file, file)
    push(c2da_eden_open_pos, 0l)
    return 0x10ul + uint64(length(c2da_eden_open_file) - 1)
}
[sideeffects]
def c2da_std_abs(x : int) : int {
    if (x < 0) {
        return 0 - x
    }
    return x
}
[sideeffects]
def c2da_std_errno_location() : uint64 {
    return 0x8ul
}
[sideeffects]
def c2da_std_exit(code : int) {
    c2da_eden_exit(code)
}
[sideeffects]
def c2da_std_fabs(x : double) : double {
    return uint64_bits_to_double(double_bits_to_uint64(x) & 0x7ffffffffffffffful)
}
[sideeffects]
def c2da_std_fclose(handle : uint64) : int {
    if (handle == 0x0ul) {
        c2da_std_set_errno(9)
        return -1
    }
    c2da_eden_fclose(c2da_std_file(handle))
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
    if (c2da_eden_feof(c2da_std_file(handle))) {
        return 1
    }
    return 0
}
[sideeffects]
def c2da_std_fflush(handle : uint64) : int {
    if (handle == 0x0ul) {
        c2da_eden_fflush(c2da_std_file(c2da_std_stdout()))
        c2da_eden_fflush(c2da_std_file(c2da_std_stderr()))
    } else {
        c2da_eden_fflush(c2da_std_file(handle))
    }
    return 0
}
[sideeffects]
def c2da_std_file(handle : uint64) : uint64 {
    return handle
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
    var mode : int = 0
    if (whence == 1) {
        mode = 1
    } elif (whence == 2) {
        mode = 2
    }
    let moved : int64 = c2da_eden_fseek(c2da_std_file(handle), offset, mode)
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
    return c2da_eden_ftell(c2da_std_file(handle))
}
[unused_argument(value), sideeffects]
def c2da_std_longjmp(target : string; value : int) {
    c2da_std_jmp_target = target
    panic("c2da_std_longjmp")
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
def c2da_std_set_errno(code : int) {
    c2da_lin_st32(8, code)
}
[sideeffects]
def c2da_std_setjmp_catch(target : string) {
    if (c2da_std_jmp_target != target) {
        panic("c2da_std_setjmp_catch: not a longjmp to this jmp_buf")
    }
    c2da_std_jmp_target = ""
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
    return 0x2ul
}
[sideeffects]
def c2da_std_stdout() : uint64 {
    return 0x1ul
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
def c2da_std_write(handle : uint64; body : string) {
    if (handle == 0x0ul) {
        return
    }
    c2da_eden_output(c2da_std_file(handle), body)
}

// --memory-model linear runtime: C memory is c2da_mem, an address is an int offset.
var c2da_mem : array<uint8>
var private c2da_lin_brk : int = 0
var private c2da_lin_free_list : int = 0
var c2da_lin_sp : int = 1790800
let private c2da_lin_limit : int64 = 33554432l
var private c2da_lin_ready : bool = false

// Reserves and sizes the heap once; every module's [init] calls it before
// copying its static block in.
def c2da_lin_setup() {
    if (c2da_lin_ready) {
        return
    }
    c2da_lin_ready = true
    reserve(c2da_mem, c2da_lin_limit)
    resize(c2da_mem, 1790800)
    c2da_lin_brk = 1790800
}

[init]
def private c2da_lin_init() {
    c2da_lin_setup()
}

// Pushes a C stack frame of `size` bytes and answers its address.
def c2da_lin_enter(size : int) : int {
    let fp = c2da_lin_sp - size
    if (fp < 742224) {
        panic("c2da: C stack overflow")
    }
    c2da_lin_sp = fp
    return fp
}

def private c2da_lin_ld32(a : int) : int {
    return int(uint(c2da_mem[a]) | (uint(c2da_mem[a + 1]) << 0x8) | (uint(c2da_mem[a + 2]) << 0x10) | (uint(c2da_mem[a + 3]) << 0x18))
}

def private c2da_lin_st32(a : int; v : int) {
    let u = uint(v)
    c2da_mem[a] = uint8(u)
    c2da_mem[a + 1] = uint8(u >> 0x8)
    c2da_mem[a + 2] = uint8(u >> 0x10)
    c2da_mem[a + 3] = uint8(u >> 0x18)
}

// A block is a 16-byte header (capacity at -16) and a 16-byte aligned payload.
// A freed block's next link is its first 4 payload bytes; reuse is first fit.
def c2da_lin_malloc(n : uint64) : int {
    if (n > uint64(0x7ffffff0)) {
        return 0
    }
    var cap = (int(n) + 15) & ~15
    if (cap == 0) {
        cap = 16
    }
    var prev = 0
    var cur = c2da_lin_free_list
    while (cur != 0) {
        let next = c2da_lin_ld32(cur)
        if (c2da_lin_ld32(cur - 16) >= cap) {
            if (prev == 0) {
                c2da_lin_free_list = next
            } else {
                c2da_lin_st32(prev, next)
            }
            return cur
        }
        prev = cur
        cur = next
    }
    let at = c2da_lin_brk
    let end = int64(at) + 16l + int64(cap)
    if (end > c2da_lin_limit) {
        return 0
    }
    resize(c2da_mem, int(end))
    c2da_lin_brk = int(end)
    c2da_lin_st32(at, cap)
    return at + 16
}

def c2da_lin_free(p : int) {
    if (p == 0) {
        return
    }
    c2da_lin_st32(p, c2da_lin_free_list)
    c2da_lin_free_list = p
}

def c2da_lin_memset(d : int; c : int; n : uint64) : int {
    let b = uint8(c)
    for (i in range(int(n))) {
        c2da_mem[d + i] = b
    }
    return d
}

def c2da_lin_calloc(count : uint64; size : uint64) : int {
    if (size != 0ul && count > uint64(0x7ffffff0) / size) {
        return 0
    }
    let n = count * size
    let p = c2da_lin_malloc(n)
    if (p != 0) {
        c2da_lin_memset(p, 0, n)
    }
    return p
}

def c2da_lin_memcpy(d : int; s : int; n : uint64) : int {
    for (i in range(int(n))) {
        c2da_mem[d + i] = c2da_mem[s + i]
    }
    return d
}

def c2da_lin_memmove(d : int; s : int; n : uint64) : int {
    let len = int(n)
    if (d <= s) {
        for (i in range(len)) {
            c2da_mem[d + i] = c2da_mem[s + i]
        }
    } else {
        var i = len - 1
        while (i >= 0) {
            c2da_mem[d + i] = c2da_mem[s + i]
            i--
        }
    }
    return d
}

def c2da_lin_realloc(p : int; n : uint64) : int {
    if (p == 0) {
        return c2da_lin_malloc(n)
    }
    if (n == 0ul) {
        c2da_lin_free(p)
        return 0
    }
    let cap = c2da_lin_ld32(p - 16)
    if (n <= uint64(cap)) {
        return p
    }
    let q = c2da_lin_malloc(n)
    if (q == 0) {
        return 0
    }
    c2da_lin_memcpy(q, p, uint64(cap))
    c2da_lin_free(p)
    return q
}

def c2da_lin_memcmp(a : int; b : int; n : uint64) : int {
    for (i in range(int(n))) {
        let x = int(c2da_mem[a + i])
        let y = int(c2da_mem[b + i])
        if (x != y) {
            return x - y
        }
    }
    return 0
}

def c2da_lin_strlen(s : int) : uint64 {
    var i = s
    while (c2da_mem[i] != uint8(0)) {
        i++
    }
    return uint64(i - s)
}

def c2da_lin_memchr(s : int; c : int; n : uint64) : int {
    let b = uint8(c & 0xff)
    for (i in range(int(n))) {
        if (c2da_mem[s + i] == b) {
            return s + i
        }
    }
    return 0
}

// The C string functions over the heap; a character compares as unsigned char.
def c2da_lin_strchr(s : int; c : int) : int {
    let b = uint8(c & 0xff)
    var i = s
    while (c2da_mem[i] != b) {
        if (c2da_mem[i] == uint8(0)) {
            return 0
        }
        i++
    }
    return i
}

def c2da_lin_strrchr(s : int; c : int) : int {
    let b = uint8(c & 0xff)
    var found = 0
    var i = s
    while (c2da_mem[i] != uint8(0)) {
        if (c2da_mem[i] == b) {
            found = i
        }
        i++
    }
    if (b == uint8(0)) {
        return i
    }
    return found
}

def c2da_lin_strncmp(a : int; b : int; n : uint64) : int {
    for (i in range(int(n))) {
        let x = int(c2da_mem[a + i])
        let y = int(c2da_mem[b + i])
        if (x != y || x == 0) {
            return x - y
        }
    }
    return 0
}

def c2da_lin_strcmp(a : int; b : int) : int {
    var i = 0
    var x = int(c2da_mem[a])
    var y = int(c2da_mem[b])
    while (x == y && x != 0) {
        i++
        x = int(c2da_mem[a + i])
        y = int(c2da_mem[b + i])
    }
    return x - y
}

def c2da_lin_strcpy(d : int; s : int) : int {
    var i = 0
    while (c2da_mem[s + i] != uint8(0)) {
        c2da_mem[d + i] = c2da_mem[s + i]
        i++
    }
    c2da_mem[d + i] = uint8(0)
    return d
}

def c2da_lin_strncpy(d : int; s : int; n : uint64) : int {
    let len = int(n)
    var i = 0
    while (i < len && c2da_mem[s + i] != uint8(0)) {
        c2da_mem[d + i] = c2da_mem[s + i]
        i++
    }
    while (i < len) {
        c2da_mem[d + i] = uint8(0)
        i++
    }
    return d
}

def c2da_lin_strcat(d : int; s : int) : int {
    c2da_lin_strcpy(d + int(c2da_lin_strlen(d)), s)
    return d
}

def c2da_lin_lower(c : int) : int {
    return c >= 65 && c <= 90 ? c + 32 : c
}

def c2da_lin_strncasecmp(a : int; b : int; n : uint64) : int {
    for (i in range(int(n))) {
        let x = c2da_lin_lower(int(c2da_mem[a + i]))
        let y = c2da_lin_lower(int(c2da_mem[b + i]))
        if (x != y || x == 0) {
            return x - y
        }
    }
    return 0
}

def c2da_lin_strcasecmp(a : int; b : int) : int {
    var i = 0
    while (true) {
        let x = c2da_lin_lower(int(c2da_mem[a + i]))
        let y = c2da_lin_lower(int(c2da_mem[b + i]))
        if (x != y || x == 0) {
            return x - y
        }
        i++
    }
    return 0
}

def c2da_lin_strdup(s : int) : int {
    let n = c2da_lin_strlen(s) + 1ul
    let d = c2da_lin_malloc(n)
    if (d != 0) {
        c2da_lin_memcpy(d, s, n)
    }
    return d
}

def c2da_lin_isspace(c : int) : bool {
    return c == 32 || (c >= 9 && c <= 13)
}

// --libc eden: no command processor, no file writes.
def c2da_lin_system(cmd : int) : int {
    return cmd == 0 ? 0 : -1
}

def c2da_lin_remove(path : int) : int {
    return -1
}

def c2da_lin_rename(from : int; to : int) : int {
    return -1
}

def c2da_lin_mkdir(path : int; mode : uint64) : int {
    return -1
}

def c2da_lin_digit(c : int; base : int) : int {
    var d = 99
    if (c >= 48 && c <= 57) {
        d = c - 48
    } elif (c >= 97 && c <= 102) {
        d = c - 87
    } elif (c >= 65 && c <= 70) {
        d = c - 55
    }
    return d < base ? d : -1
}

// sscanf with `%d %u %x %X %o` into ints (the translator checks the format):
// blanks in the format skip blanks, other characters must match, and the
// result is the number of conversions stored (-1 when the input is empty
// before the first one).
def c2da_lin_sscanf(s : int; f : int; p0 : int; p1 : int; p2 : int; p3 : int) : int {
    var i = s
    var k = f
    var n = 0
    while (int(c2da_mem[k]) != 0) {
        let c = int(c2da_mem[k])
        if (c2da_lin_isspace(c)) {
            while (c2da_lin_isspace(int(c2da_mem[i]))) {
                i++
            }
            k++
        } elif (c != 37) {
            if (int(c2da_mem[i]) != c) {
                return n == 0 && int(c2da_mem[i]) == 0 ? -1 : n
            }
            i++
            k++
        } else {
            let conv = int(c2da_mem[k + 1])
            k += 2
            while (c2da_lin_isspace(int(c2da_mem[i]))) {
                i++
            }
            if (n == 0 && int(c2da_mem[i]) == 0) {
                return -1
            }
            var neg = false
            if (int(c2da_mem[i]) == 45 || int(c2da_mem[i]) == 43) {
                neg = int(c2da_mem[i]) == 45
                i++
            }
            var base = conv == 120 || conv == 88 ? 16 : (conv == 111 ? 8 : 10)
            if (conv == 105 && int(c2da_mem[i]) == 48) {
                // %i: a leading 0x is hexadecimal, a leading 0 octal.
                let x = int(c2da_mem[i + 1])
                if ((x == 120 || x == 88) && c2da_lin_digit(int(c2da_mem[i + 2]), 16) >= 0) {
                    base = 16
                    i += 2
                } else {
                    base = 8
                }
            }
            var v = 0
            var digits = 0
            while (c2da_lin_digit(int(c2da_mem[i]), base) >= 0) {
                v = v * base + c2da_lin_digit(int(c2da_mem[i]), base)
                i++
                digits++
            }
            if (digits == 0) {
                return n
            }
            if (neg) {
                v = -v
            }
            let p = n == 0 ? p0 : (n == 1 ? p1 : (n == 2 ? p2 : p3))
            c2da_mem[p] = uint8(v & 255)
            c2da_mem[p + 1] = uint8((v >> 8) & 255)
            c2da_mem[p + 2] = uint8((v >> 16) & 255)
            c2da_mem[p + 3] = uint8((v >> 24) & 255)
            n++
        }
    }
    return n
}

// atoi: optional blanks and sign, then decimal digits (wrapping like the
// 32-bit accumulation of common libcs; overflow is undefined in C).
def c2da_lin_atoi(s : int) : int {
    var i = s
    while (c2da_lin_isspace(int(c2da_mem[i]))) {
        i++
    }
    var neg = false
    if (c2da_mem[i] == uint8(45) || c2da_mem[i] == uint8(43)) {
        neg = c2da_mem[i] == uint8(45)
        i++
    }
    var v = 0
    while (int(c2da_mem[i]) >= 48 && int(c2da_mem[i]) <= 57) {
        v = v * 10 + int(c2da_mem[i]) - 48
        i++
    }
    return neg ? -v : v
}

// atof: decimal digits, a fraction and an exponent.  Exact (correctly
// rounded) while the digits fit 2^53 and the decimal exponent is within 22;
// beyond that the scaling rounds more than once.
def c2da_lin_atof(s : int) : double {
    var i = s
    while (c2da_lin_isspace(int(c2da_mem[i]))) {
        i++
    }
    var neg = false
    if (int(c2da_mem[i]) == 45 || int(c2da_mem[i]) == 43) {
        neg = int(c2da_mem[i]) == 45
        i++
    }
    var m = 0.0lf
    var e = 0
    while (int(c2da_mem[i]) >= 48 && int(c2da_mem[i]) <= 57) {
        m = m * 10.0lf + double(int(c2da_mem[i]) - 48)
        i++
    }
    if (int(c2da_mem[i]) == 46) {
        i++
        while (int(c2da_mem[i]) >= 48 && int(c2da_mem[i]) <= 57) {
            m = m * 10.0lf + double(int(c2da_mem[i]) - 48)
            e--
            i++
        }
    }
    if (int(c2da_mem[i]) == 101 || int(c2da_mem[i]) == 69) {
        var j = i + 1
        var eneg = false
        if (int(c2da_mem[j]) == 45 || int(c2da_mem[j]) == 43) {
            eneg = int(c2da_mem[j]) == 45
            j++
        }
        if (int(c2da_mem[j]) >= 48 && int(c2da_mem[j]) <= 57) {
            var x = 0
            while (int(c2da_mem[j]) >= 48 && int(c2da_mem[j]) <= 57) {
                if (x < 100000) {
                    x = x * 10 + int(c2da_mem[j]) - 48
                }
                j++
            }
            e += eneg ? -x : x
        }
    }
    var p = 1.0lf
    for (_ in range(e < 0 ? -e : e)) {
        p *= 10.0lf
    }
    let v = e < 0 ? m / p : m * p
    return neg ? -v : v
}

def c2da_lin_strstr(h : int; n : int) : int {
    var i = h
    while (true) {
        var k = 0
        while (c2da_mem[n + k] != uint8(0) && c2da_mem[i + k] == c2da_mem[n + k]) {
            k++
        }
        if (c2da_mem[n + k] == uint8(0)) {
            return i
        }
        if (c2da_mem[i] == uint8(0)) {
            return 0
        }
        i++
    }
    return 0
}

// printf family over C memory: the format and %s/%p arguments are heap offsets.
def private c2da_lin_pad(var out : array<uint8>; c : int; n : int) {
    for (i in range(n)) {
        push(out, uint8(c))
    }
}

def private c2da_lin_fmt_int(var out : array<uint8>; neg : bool; mag : uint64; base : uint64; upper : bool; flags : int; width : int; prec : int) {
    var digits : array<uint8>
    var m = mag
    while (m != 0ul) {
        let d = int(m % base)
        if (d < 10) {
            push(digits, uint8(48 + d))
        } elif (upper) {
            push(digits, uint8(55 + d))
        } else {
            push(digits, uint8(87 + d))
        }
        m /= base
    }
    let nd = length(digits)
    var p = prec < 0 ? 1 : prec
    if ((flags & 8) != 0 && base == 8ul && p <= nd) {
        p = nd + 1
    }
    let zeros = p > nd ? p - nd : 0
    var prefix : array<uint8>
    if (neg) {
        push(prefix, uint8(45))
    } elif ((flags & 2) != 0) {
        push(prefix, uint8(43))
    } elif ((flags & 4) != 0) {
        push(prefix, uint8(32))
    }
    if ((flags & 8) != 0 && base == 16ul && mag != 0ul) {
        push(prefix, uint8(48))
        push(prefix, upper ? uint8(88) : uint8(120))
    }
    let body = length(prefix) + zeros + nd
    let fill = width > body ? width - body : 0
    let zero_fill = (flags & 1) == 0 && (flags & 16) != 0 && prec < 0
    if ((flags & 1) == 0 && !zero_fill) {
        c2da_lin_pad(out, 32, fill)
    }
    for (b in prefix) {
        push(out, b)
    }
    if (zero_fill) {
        c2da_lin_pad(out, 48, fill)
    }
    c2da_lin_pad(out, 48, zeros)
    var i = nd - 1
    while (i >= 0) {
        push(out, digits[i])
        i--
    }
    if ((flags & 1) != 0) {
        c2da_lin_pad(out, 32, fill)
    }
}

def private c2da_lin_fmt_bytes(var out : array<uint8>; s : int; n : int; flags : int; width : int) {
    let fill = width > n ? width - n : 0
    if ((flags & 1) == 0) {
        c2da_lin_pad(out, 32, fill)
    }
    for (j in range(n)) {
        push(out, c2da_mem[s + j])
    }
    if ((flags & 1) != 0) {
        c2da_lin_pad(out, 32, fill)
    }
}

// Appends the conversion of format f over args[start..] to out; answers the
// index of the first argument it did not consume.
def c2da_lin_vfmt(f : int; args : array<C2daVaArg>; start : int; var out : array<uint8>) : int {
    var k = start
    var i = f
    while (c2da_mem[i] != uint8(0)) {
        let c = int(c2da_mem[i])
        i++
        if (c != 37) {
            push(out, uint8(c))
            continue
        }
        var flags = 0
        while (true) {
            let g = int(c2da_mem[i])
            if (g == 45) {
                flags |= 1
            } elif (g == 43) {
                flags |= 2
            } elif (g == 32) {
                flags |= 4
            } elif (g == 35) {
                flags |= 8
            } elif (g == 48) {
                flags |= 16
            } else {
                break
            }
            i++
        }
        var width = 0
        if (int(c2da_mem[i]) == 42) {
            width = int(args[k].i64)
            k++
            i++
            if (width < 0) {
                flags |= 1
                width = -width
            }
        } else {
            while (int(c2da_mem[i]) >= 48 && int(c2da_mem[i]) <= 57) {
                width = width * 10 + int(c2da_mem[i]) - 48
                i++
            }
        }
        var prec = -1
        if (int(c2da_mem[i]) == 46) {
            i++
            prec = 0
            if (int(c2da_mem[i]) == 42) {
                prec = int(args[k].i64)
                k++
                i++
            } else {
                while (int(c2da_mem[i]) >= 48 && int(c2da_mem[i]) <= 57) {
                    prec = prec * 10 + int(c2da_mem[i]) - 48
                    i++
                }
            }
        }
        // 0: int, 1: hh, 2: h, 3: 64-bit
        var size = 0
        while (true) {
            let g = int(c2da_mem[i])
            if (g == 104) {
                size = size == 2 ? 1 : 2
            } elif (g == 108 || g == 106 || g == 122 || g == 116 || g == 113 || g == 76) {
                size = 3
            } else {
                break
            }
            i++
        }
        let conv = int(c2da_mem[i])
        i++
        if (conv == 37) {
            push(out, uint8(37))
        } elif (conv == 100 || conv == 105) {
            var v = args[k].i64
            k++
            if (size == 0) {
                v = ((v & 4294967295l) ^ 2147483648l) - 2147483648l
            } elif (size == 1) {
                v = ((v & 255l) ^ 128l) - 128l
            } elif (size == 2) {
                v = ((v & 65535l) ^ 32768l) - 32768l
            }
            let neg = v < 0l
            c2da_lin_fmt_int(out, neg, neg ? uint64(-v) : uint64(v), 10ul, false, flags, width, prec)
        } elif (conv == 117 || conv == 120 || conv == 88 || conv == 111) {
            var m = uint64(args[k].i64)
            k++
            if (size == 0) {
                m &= 0xfffffffful
            } elif (size == 1) {
                m &= 0xfful
            } elif (size == 2) {
                m &= 0xfffful
            }
            let base = conv == 117 ? 10ul : (conv == 111 ? 8ul : 16ul)
            c2da_lin_fmt_int(out, false, m, base, conv == 88, flags & ~6, width, prec)
        } elif (conv == 102 || conv == 70 || conv == 101 || conv == 69 || conv == 103 || conv == 71) {
            // %f %F %e %E %g %G: daslang's `fmt` spells these exactly as C
            // does (the `--libc std` engine hands them over the same way).
            var spec = ":"
            if ((flags & 1) != 0) {
                spec += "<"
            }
            if ((flags & 2) != 0) {
                spec += "+"
            } elif ((flags & 4) != 0) {
                spec += " "
            }
            if ((flags & 8) != 0) {
                spec += to_char(35)
            }
            if ((flags & 16) != 0 && (flags & 1) == 0) {
                spec += "0"
            }
            if (width > 0) {
                spec += "{width}"
            }
            if (prec >= 0) {
                spec += ".{prec}"
            }
            spec += to_char(conv)
            let text = fmt(spec, args[k].f64)
            k++
            // `push_from` does not take `peek_data`'s temporary view.
            peek_data(text) $(bytes) {
                reserve(out, length(out) + length(bytes))
                for (b in bytes) {
                    push(out, b)
                }
            }
        } elif (conv == 99) {
            let b = int(args[k].i64 & 255l)
            k++
            let fill = width > 1 ? width - 1 : 0
            if ((flags & 1) == 0) {
                c2da_lin_pad(out, 32, fill)
            }
            push(out, uint8(b))
            if ((flags & 1) != 0) {
                c2da_lin_pad(out, 32, fill)
            }
        } elif (conv == 115) {
            let s = int(args[k].raw)
            k++
            if (s == 0) {
                // glibc's "(null)"
                var t : array<uint8>
                push(t, uint8(40))
                push(t, uint8(110))
                push(t, uint8(117))
                push(t, uint8(108))
                push(t, uint8(108))
                push(t, uint8(41))
                let fill = width > 6 ? width - 6 : 0
                if ((flags & 1) == 0) {
                    c2da_lin_pad(out, 32, fill)
                }
                for (b in t) {
                    push(out, b)
                }
                if ((flags & 1) != 0) {
                    c2da_lin_pad(out, 32, fill)
                }
            } else {
                var n = 0
                while ((prec < 0 || n < prec) && c2da_mem[s + n] != uint8(0)) {
                    n++
                }
                c2da_lin_fmt_bytes(out, s, n, flags, width)
            }
        } elif (conv == 112) {
            let p = args[k].raw
            k++
            c2da_lin_fmt_int(out, false, p, 16ul, false, flags | 8, width, prec)
        } else {
            panic("c2da: printf conversion not supported under --memory-model linear")
        }
    }
    return k
}

def private c2da_lin_text(out : array<uint8>) : string {
    return build_string() $(var w) {
        for (b in out) {
            write_char(w, int(b))
        }
    }
}

// C's snprintf truncation: at most n - 1 bytes and a NUL; answers the full length.
def private c2da_lin_place(d : int; n : uint64; out : array<uint8>) : int {
    let len = length(out)
    if (n != 0ul) {
        let m = uint64(len) < n ? len : int(n) - 1
        for (j in range(m)) {
            c2da_mem[d + j] = out[j]
        }
        c2da_mem[d + m] = uint8(0)
    }
    return len
}

def c2da_lin_printf(h : uint64; f : int; args : array<C2daVaArg>) : int {
    var out : array<uint8>
    c2da_lin_vfmt(f, args, 0, out)
    c2da_std_write(h, c2da_lin_text(out))
    return length(out)
}

def c2da_lin_vprintf(h : uint64; f : int; var ap : C2daVaCursor; args : array<C2daVaArg>) : int {
    var out : array<uint8>
    ap.index = c2da_lin_vfmt(f, args, ap.index, out)
    c2da_std_write(h, c2da_lin_text(out))
    return length(out)
}

def c2da_lin_snprintf(d : int; n : uint64; f : int; args : array<C2daVaArg>) : int {
    var out : array<uint8>
    c2da_lin_vfmt(f, args, 0, out)
    return c2da_lin_place(d, n, out)
}

def c2da_lin_vsnprintf(d : int; n : uint64; f : int; var ap : C2daVaCursor; args : array<C2daVaArg>) : int {
    var out : array<uint8>
    ap.index = c2da_lin_vfmt(f, args, ap.index, out)
    return c2da_lin_place(d, n, out)
}

// <stdio.h> files over C memory: a FILE * is the --libc eden handle as an int.
def private c2da_lin_cstr(p : int) : string {
    return build_string() $(var w) {
        var i = p
        while (c2da_mem[i] != uint8(0)) {
            write_char(w, int(c2da_mem[i]))
            i++
        }
    }
}

def c2da_lin_fopen(path : int; mode : int) : int {
    return int(c2da_eden_fopen(c2da_lin_cstr(path), c2da_lin_cstr(mode)))
}

def c2da_lin_fread(d : int; size : uint64; count : uint64; handle : uint64) : uint64 {
    if (size == 0ul || count == 0ul || handle < 16ul) {
        return 0ul
    }
    let slot = int(handle - 16ul)
    if (slot >= length(c2da_eden_open_file) || c2da_eden_open_file[slot] < 0) {
        return 0ul
    }
    let file = c2da_eden_open_file[slot]
    let avail = long_length(c2da_eden_file_data[file])
    let total = int64(size * count)
    var pos = c2da_eden_open_pos[slot]
    var n = 0l
    while (n < total && pos < avail) {
        c2da_mem[d + int(n)] = c2da_eden_file_data[file][pos]
        n++
        pos++
    }
    c2da_eden_open_pos[slot] = pos
    return uint64(n) / size
}

// getc/fgetc: the next byte of a registered file as an unsigned char, -1 (EOF)
// past its end or on a handle that reads nothing (stdin has no input here).
def c2da_lin_fgetc(handle : uint64) : int {
    if (handle < 16ul) {
        return -1
    }
    let slot = int(handle - 16ul)
    if (slot >= length(c2da_eden_open_file) || c2da_eden_open_file[slot] < 0) {
        return -1
    }
    let file = c2da_eden_open_file[slot]
    let pos = c2da_eden_open_pos[slot]
    if (pos >= long_length(c2da_eden_file_data[file])) {
        return -1
    }
    c2da_eden_open_pos[slot] = pos + 1l
    return int(c2da_eden_file_data[file][pos])
}

// fscanf's one byte of lookahead goes back to the file when the scan ends, so
// the stream is left at the first byte no directive consumed (as glibc's is).
def private c2da_lin_scan_unget(handle : uint64; c : int) {
    if (c >= 0) {
        let slot = int(handle - 16ul)
        c2da_eden_open_pos[slot] = c2da_eden_open_pos[slot] - 1l
    }
}

// fscanf over a registered file.  The translator accepts only a literal format
// of white space, ordinary bytes, `%%`, `%[w]d %[w]i %[w]o %[w]u %[w]x %[w]X`
// (into an int: the low 32 bits of strtol's/strtoul's saturated value),
// `%[w]s` and `%[w]e %[w]f %[w]g %[w]E %[w]G` (into a float, a double under
// `l`); `ptrs` holds the conversions' target offsets in order.  The answer is
// the number of stored items, or -1 when the input ends before the first.
def c2da_lin_fscanf(handle : uint64; f : int; ptrs : array<int>) : int {
    var c = c2da_lin_fgetc(handle)
    var done = 0
    var k = f
    while (int(c2da_mem[k]) != 0) {
        let fc = int(c2da_mem[k])
        if (c2da_lin_isspace(fc)) {
            while (c2da_lin_isspace(int(c2da_mem[k]))) {
                k++
            }
            while (c >= 0 && c2da_lin_isspace(c)) {
                c = c2da_lin_fgetc(handle)
            }
            continue
        }
        if (fc != 37) {
            if (c < 0) {
                return done == 0 ? -1 : done
            }
            if (c != fc) {
                c2da_lin_scan_unget(handle, c)
                return done
            }
            c = c2da_lin_fgetc(handle)
            k++
            continue
        }
        k++
        var width = 0
        while (int(c2da_mem[k]) >= 48 && int(c2da_mem[k]) <= 57) {
            width = width * 10 + int(c2da_mem[k]) - 48
            k++
        }
        var wide = false
        if (int(c2da_mem[k]) == 108) {
            wide = true
            k++
        }
        let conv = int(c2da_mem[k])
        k++
        while (c >= 0 && c2da_lin_isspace(c)) {
            c = c2da_lin_fgetc(handle)
        }
        if (c < 0) {
            return done == 0 ? -1 : done
        }
        if (conv == 37) {
            if (c != 37) {
                c2da_lin_scan_unget(handle, c)
                return done
            }
            c = c2da_lin_fgetc(handle)
            continue
        }
        let p = ptrs[done]
        if (conv == 115) {
            var n = 0
            while (c >= 0 && !c2da_lin_isspace(c) && (width == 0 || n < width)) {
                c2da_mem[p + n] = uint8(c)
                n++
                c = c2da_lin_fgetc(handle)
            }
            c2da_mem[p + n] = uint8(0)
            done++
            continue
        }
        let limit = width > 0 ? width : 2147483647
        var n = 0
        var neg = false
        var any = false
        if (n < limit && (c == 45 || c == 43)) {
            neg = c == 45
            n++
            c = c2da_lin_fgetc(handle)
        }
        if (conv == 101 || conv == 102 || conv == 103 || conv == 69 || conv == 71) {
            if ((c | 32) == 105 || (c | 32) == 110) {
                panic("--memory-model linear: fscanf does not implement `inf`/`nan` input")
            }
            let subject = build_string() $(var w) {
                while (n < limit && c >= 48 && c <= 57) {
                    write_char(w, c)
                    any = true
                    n++
                    c = c2da_lin_fgetc(handle)
                }
                if (any && (c | 32) == 120) {
                    panic("--memory-model linear: fscanf does not implement hexadecimal floating input")
                }
                if (n < limit && c == 46) {
                    write_char(w, c)
                    n++
                    c = c2da_lin_fgetc(handle)
                    while (n < limit && c >= 48 && c <= 57) {
                        write_char(w, c)
                        any = true
                        n++
                        c = c2da_lin_fgetc(handle)
                    }
                }
                if (any && n < limit && (c | 32) == 101) {
                    write_char(w, c)
                    n++
                    c = c2da_lin_fgetc(handle)
                    if (n < limit && (c == 45 || c == 43)) {
                        write_char(w, c)
                        n++
                        c = c2da_lin_fgetc(handle)
                    }
                    while (n < limit && c >= 48 && c <= 57) {
                        write_char(w, c)
                        n++
                        c = c2da_lin_fgetc(handle)
                    }
                }
            }
            if (!any) {
                c2da_lin_scan_unget(handle, c)
                return done
            }
            var v = c2da_lin_scan_double(subject)
            if (neg) {
                v = -v
            }
            if (wide) {
                let bits = double_bits_to_uint64(v)
                c2da_lin_st32(p, int(uint(bits & 0xfffffffful)))
                c2da_lin_st32(p + 4, int(uint(bits >> 32ul)))
            } else {
                c2da_lin_st32(p, int(float_bits_to_uint(float(v))))
            }
            done++
            continue
        }
        var radix = conv == 105 ? 0 : (conv == 111 ? 8 : (conv == 120 || conv == 88 ? 16 : 10))
        if (n < limit && c == 48) {
            any = true
            n++
            c = c2da_lin_fgetc(handle)
            if (n < limit && (c | 32) == 120 && (radix == 0 || radix == 16)) {
                radix = 16
                n++
                c = c2da_lin_fgetc(handle)
            } elif (radix == 0) {
                radix = 8
            }
        } elif (radix == 0) {
            radix = 10
        }
        var mag = 0ul
        var over = false
        while (n < limit && c2da_lin_digit(c, radix) >= 0) {
            let d = uint64(c2da_lin_digit(c, radix))
            if (mag > (0xfffffffffffffffful - d) / uint64(radix)) {
                over = true
            } else {
                mag = mag * uint64(radix) + d
            }
            any = true
            n++
            c = c2da_lin_fgetc(handle)
        }
        if (!any) {
            c2da_lin_scan_unget(handle, c)
            return done
        }
        var value = 0ul
        if (conv == 100 || conv == 105) {
            // strtol: saturated at LONG_MIN / LONG_MAX.
            if (neg) {
                value = over || mag > 0x8000000000000000ul ? 0x8000000000000000ul : (0ul - mag)
            } else {
                value = over || mag > 0x7ffffffffffffffful ? 0x7ffffffffffffffful : mag
            }
        } elif (over) {
            value = 0xfffffffffffffffful
        } else {
            value = neg ? 0ul - mag : mag
        }
        c2da_lin_st32(p, int(uint(value & 0xfffffffful)))
        done++
    }
    c2da_lin_scan_unget(handle, c)
    return done
}

// strtod of a collected `digits[.digits][e[sign]digits]` subject, by
// daslang's correctly rounded `to_double`.
def private c2da_lin_scan_double(subject : string) : double {
    return to_double(subject)
}

// Only stdout and stderr are writable (--libc eden): any other handle writes nothing.
def c2da_lin_fputc(c : int; handle : uint64) : int {
    if (handle != 1ul && handle != 2ul) {
        return -1
    }
    c2da_std_write(handle, build_string() $(var w) {
        write_char(w, c & 255)
    })
    return c & 255
}

def c2da_lin_fwrite(s : int; size : uint64; count : uint64; handle : uint64) : uint64 {
    if (size == 0ul || count == 0ul || (handle != 1ul && handle != 2ul)) {
        return 0ul
    }
    let total = int(size * count)
    c2da_std_write(handle, build_string() $(var w) {
        for (j in range(total)) {
            write_char(w, int(c2da_mem[s + j]))
        }
    })
    return count
}

// strerror over C memory: glibc's text, copied into one heap buffer.
var private c2da_lin_strerror_buf : int = 0
var private c2da_lin_strerror_cap : int = 0

def private c2da_lin_strerror_text(code : int) : string {
    if (code == 1) {
        return "Operation not permitted"
    }
    if (code == 2) {
        return "No such file or directory"
    }
    if (code == 4) {
        return "Interrupted system call"
    }
    if (code == 5) {
        return "Input/output error"
    }
    if (code == 9) {
        return "Bad file descriptor"
    }
    if (code == 11) {
        return "Resource temporarily unavailable"
    }
    if (code == 12) {
        return "Cannot allocate memory"
    }
    if (code == 13) {
        return "Permission denied"
    }
    if (code == 16) {
        return "Device or resource busy"
    }
    if (code == 17) {
        return "File exists"
    }
    if (code == 21) {
        return "Is a directory"
    }
    if (code == 22) {
        return "Invalid argument"
    }
    if (code == 28) {
        return "No space left on device"
    }
    if (code == 29) {
        return "Illegal seek"
    }
    if (code == 34) {
        return "Numerical result out of range"
    }
    if (code == 38) {
        return "Function not implemented"
    }
    if (code == 75) {
        return "Value too large for defined data type"
    }
    return "Unknown error {code}"
}

def c2da_lin_strerror(code : int) : int {
    let s = c2da_lin_strerror_text(code)
    let n = length(s)
    if (c2da_lin_strerror_cap < n + 1) {
        let p = c2da_lin_malloc(uint64(n + 1))
        if (p == 0) {
            return 0
        }
        c2da_lin_free(c2da_lin_strerror_buf)
        c2da_lin_strerror_buf = p
        c2da_lin_strerror_cap = n + 1
    }
    let p = c2da_lin_strerror_buf
    for (j in range(n)) {
        c2da_mem[p + j] = uint8(character_at(s, j))
    }
    c2da_mem[p + n] = uint8(0)
    return p
}

// Function pointers in the heap are indices into these tables (0 is NULL).
var c2da_fn_table0 : array<function<():void>>

def c2da_fn_index0(f : function<():void>) : int {
    for (k in range(length(c2da_fn_table0))) {
        if (c2da_fn_table0[k] == f) {
            return k
        }
    }
    panic("c2da: a function pointer outside the function table")
    return 0
}

var c2da_fn_table1 : array<function<(var _arg0:float):float>>

def c2da_fn_index1(f : function<(var _arg0:float):float>) : int {
    for (k in range(length(c2da_fn_table1))) {
        if (c2da_fn_table1[k] == f) {
            return k
        }
    }
    panic("c2da: a function pointer outside the function table")
    return 0
}

var c2da_fn_table2 : array<function<(var _arg0:int):int>>

def c2da_fn_index2(f : function<(var _arg0:int):int>) : int {
    for (k in range(length(c2da_fn_table2))) {
        if (c2da_fn_table2[k] == f) {
            return k
        }
    }
    panic("c2da: a function pointer outside the function table")
    return 0
}

var c2da_fn_table3 : array<function<(var _arg0:int16):int16>>

def c2da_fn_index3(f : function<(var _arg0:int16):int16>) : int {
    for (k in range(length(c2da_fn_table3))) {
        if (c2da_fn_table3[k] == f) {
            return k
        }
    }
    panic("c2da: a function pointer outside the function table")
    return 0
}

var c2da_fn_table4 : array<function<(var _arg0:int;_arg1:array<C2daVaArg>):void>>

def c2da_fn_index4(f : function<(var _arg0:int;_arg1:array<C2daVaArg>):void>) : int {
    for (k in range(length(c2da_fn_table4))) {
        if (c2da_fn_table4[k] == f) {
            return k
        }
    }
    panic("c2da: a function pointer outside the function table")
    return 0
}

var c2da_fn_table5 : array<function<(var _arg0:int):void>>

def c2da_fn_index5(f : function<(var _arg0:int):void>) : int {
    for (k in range(length(c2da_fn_table5))) {
        if (c2da_fn_table5[k] == f) {
            return k
        }
    }
    panic("c2da: a function pointer outside the function table")
    return 0
}

var c2da_fn_table6 : array<function<(var _arg0:int;var _arg1:int;var _arg2:int;var _arg3:int;var _arg4:int):void>>

def c2da_fn_index6(f : function<(var _arg0:int;var _arg1:int;var _arg2:int;var _arg3:int;var _arg4:int):void>) : int {
    for (k in range(length(c2da_fn_table6))) {
        if (c2da_fn_table6[k] == f) {
            return k
        }
    }
    panic("c2da: a function pointer outside the function table")
    return 0
}

var c2da_fn_table7 : array<function<(var _arg0:int;var _arg1:int;var _arg2:int;var _arg3:int;var _arg4:uint):void>>

def c2da_fn_index7(f : function<(var _arg0:int;var _arg1:int;var _arg2:int;var _arg3:int;var _arg4:uint):void>) : int {
    for (k in range(length(c2da_fn_table7))) {
        if (c2da_fn_table7[k] == f) {
            return k
        }
    }
    panic("c2da: a function pointer outside the function table")
    return 0
}

var c2da_fn_table8 : array<function<():int>>

def c2da_fn_index8(f : function<():int>) : int {
    for (k in range(length(c2da_fn_table8))) {
        if (c2da_fn_table8[k] == f) {
            return k
        }
    }
    panic("c2da: a function pointer outside the function table")
    return 0
}

var c2da_fn_table9 : array<function<(var _arg0:uint):void>>

def c2da_fn_index9(f : function<(var _arg0:uint):void>) : int {
    for (k in range(length(c2da_fn_table9))) {
        if (c2da_fn_table9[k] == f) {
            return k
        }
    }
    panic("c2da: a function pointer outside the function table")
    return 0
}

var c2da_fn_table10 : array<function<(var _arg0:int;var _arg1:int):int>>

def c2da_fn_index10(f : function<(var _arg0:int;var _arg1:int):int>) : int {
    for (k in range(length(c2da_fn_table10))) {
        if (c2da_fn_table10[k] == f) {
            return k
        }
    }
    panic("c2da: a function pointer outside the function table")
    return 0
}

var c2da_fn_table11 : array<function<(var _arg0:int):uint>>

def c2da_fn_index11(f : function<(var _arg0:int):uint>) : int {
    for (k in range(length(c2da_fn_table11))) {
        if (c2da_fn_table11[k] == f) {
            return k
        }
    }
    panic("c2da: a function pointer outside the function table")
    return 0
}

var c2da_fn_table12 : array<function<(var _arg0:int;var _arg1:int;var _arg2:int):void>>

def c2da_fn_index12(f : function<(var _arg0:int;var _arg1:int;var _arg2:int):void>) : int {
    for (k in range(length(c2da_fn_table12))) {
        if (c2da_fn_table12[k] == f) {
            return k
        }
    }
    panic("c2da: a function pointer outside the function table")
    return 0
}

