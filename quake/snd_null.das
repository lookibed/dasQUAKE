options gen2
options solid_context = true
options stack = 4194304
module snd_null public

require dasquake_runtime
var private c2da_str_0 : array<int8> = [int8(98), int8(103), int8(109), int8(118), int8(111), int8(108), int8(117), int8(109), int8(101), int8(0)]

var private c2da_str_1 : array<int8> = [int8(49), int8(0)]

var private c2da_str_2 : array<int8> = [int8(118), int8(111), int8(108), int8(117), int8(109), int8(101), int8(0)]

var private c2da_str_3 : array<int8> = [int8(48), int8(46), int8(55), int8(0)]

[export, sideeffects]
def S_Init() {
    return
}
[export, sideeffects]
def S_Shutdown() {
    return
}
[export, sideeffects]
def S_StartSound(var entnum : int; var entchannel : int; var sfx : sfx_s?; var origin : float?; var fvol : float; var attenuation : float) {
    return
}
[export, sideeffects]
def S_StaticSound(var sfx_0 : sfx_s?; var origin_0 : float?; var vol : float; var attenuation_0 : float) {
    return
}
[export, sideeffects]
def S_StopSound(var entnum_0 : int; var entchannel_0 : int) {
    return
}
[export, sideeffects]
def S_StopAllSounds(var clear : qboolean) {
    return
}
[export, sideeffects]
def S_ClearBuffer() {
    return
}
[export, sideeffects]
def S_Update(var origin_1 : float?; var v_forward : float?; var v_right : float?; var v_up : float?) {
    return
}
[export, sideeffects]
def S_ExtraUpdate() {
    return
}
[export, sideeffects]
def S_PrecacheSound(var sample : int8?) : sfx_s? {
    return unsafe(reinterpret<sfx_s?>(null))
}
[export, sideeffects]
def S_TouchSound(var sample_0 : int8?) {
    return
}
[export, sideeffects]
def S_ClearPrecache() {
    return
}
[export, sideeffects]
def S_BeginPrecaching() {
    return
}
[export, sideeffects]
def S_EndPrecaching() {
    return
}
var bgmvolume : cvar_s = cvar_s(name = unsafe(addr(c2da_str_0[0])), string_0 = unsafe(addr(c2da_str_1[0])), archive = unsafe(reinterpret<qboolean>(1u)), server = qboolean(), value = 0.0, next = null)

var volume : cvar_s = cvar_s(name = unsafe(addr(c2da_str_2[0])), string_0 = unsafe(addr(c2da_str_3[0])), archive = unsafe(reinterpret<qboolean>(1u)), server = qboolean(), value = 0.0, next = null)

[export, sideeffects]
def S_LocalSound(var s : int8?) {
    return
}
[export, sideeffects]
def S_AmbientOff() {
    return
}
[export, sideeffects]
def S_AmbientOn() {
    return
}
[sideeffects]
def private c2da_layout_proofs() {
    static_assert(typeinfo sizeof(type<cache_user_s>) == 8, "C layout of cache_user_s: sizeof")
    static_assert(typeinfo alignof(type<cache_user_s>) == 8, "C layout of cache_user_s: alignof")
    static_assert(typeinfo offsetof<data>(type<cache_user_s>) == 0, "C layout of cache_user_s: offsetof data")
    static_assert(typeinfo sizeof(type<cvar_s>) == 40, "C layout of cvar_s: sizeof")
    static_assert(typeinfo alignof(type<cvar_s>) == 8, "C layout of cvar_s: alignof")
    static_assert(typeinfo offsetof<name>(type<cvar_s>) == 0, "C layout of cvar_s: offsetof name")
    static_assert(typeinfo offsetof<string_0>(type<cvar_s>) == 8, "C layout of cvar_s: offsetof string_0")
    static_assert(typeinfo offsetof<archive>(type<cvar_s>) == 16, "C layout of cvar_s: offsetof archive")
    static_assert(typeinfo offsetof<server>(type<cvar_s>) == 20, "C layout of cvar_s: offsetof server")
    static_assert(typeinfo offsetof<value>(type<cvar_s>) == 24, "C layout of cvar_s: offsetof value")
    static_assert(typeinfo offsetof<next>(type<cvar_s>) == 32, "C layout of cvar_s: offsetof next")
    static_assert(typeinfo sizeof(type<cache_user_t>) == 8, "C layout of cache_user_t: sizeof")
    static_assert(typeinfo alignof(type<cache_user_t>) == 8, "C layout of cache_user_t: alignof")
    static_assert(typeinfo offsetof<data>(type<cache_user_t>) == 0, "C layout of cache_user_t: offsetof data")
    static_assert(typeinfo sizeof(type<cvar_t>) == 40, "C layout of cvar_t: sizeof")
    static_assert(typeinfo alignof(type<cvar_t>) == 8, "C layout of cvar_t: alignof")
    static_assert(typeinfo offsetof<name>(type<cvar_t>) == 0, "C layout of cvar_t: offsetof name")
    static_assert(typeinfo offsetof<string_0>(type<cvar_t>) == 8, "C layout of cvar_t: offsetof string_0")
    static_assert(typeinfo offsetof<archive>(type<cvar_t>) == 16, "C layout of cvar_t: offsetof archive")
    static_assert(typeinfo offsetof<server>(type<cvar_t>) == 20, "C layout of cvar_t: offsetof server")
    static_assert(typeinfo offsetof<value>(type<cvar_t>) == 24, "C layout of cvar_t: offsetof value")
    static_assert(typeinfo offsetof<next>(type<cvar_t>) == 32, "C layout of cvar_t: offsetof next")
    static_assert(typeinfo sizeof(type<sfx_s>) == 72, "C layout of sfx_s: sizeof")
    static_assert(typeinfo alignof(type<sfx_s>) == 8, "C layout of sfx_s: alignof")
    static_assert(typeinfo offsetof<name>(type<sfx_s>) == 0, "C layout of sfx_s: offsetof name")
    static_assert(typeinfo offsetof<cache>(type<sfx_s>) == 64, "C layout of sfx_s: offsetof cache")
    static_assert(typeinfo sizeof(type<sfx_t>) == 72, "C layout of sfx_t: sizeof")
    static_assert(typeinfo alignof(type<sfx_t>) == 8, "C layout of sfx_t: alignof")
    static_assert(typeinfo offsetof<name>(type<sfx_t>) == 0, "C layout of sfx_t: offsetof name")
    static_assert(typeinfo offsetof<cache>(type<sfx_t>) == 64, "C layout of sfx_t: offsetof cache")
}
