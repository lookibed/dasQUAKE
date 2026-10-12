options gen2
options stack = 4194304
module snd_null public

require dasquake_runtime
require daslib/math_bits
[export, sideeffects]
def S_Init() {
    return
}
[export, sideeffects]
def S_Shutdown() {
    return
}
[export, sideeffects]
def S_StartSound(var entnum : int; var entchannel : int; var sfx : int; var origin : int; var fvol : float; var attenuation : float) {
    return
}
[export, sideeffects]
def S_StaticSound(var sfx_0 : int; var origin_0 : int; var vol : float; var attenuation_0 : float) {
    return
}
[export, sideeffects]
def S_StopSound(var entnum_0 : int; var entchannel_0 : int) {
    return
}
[export, sideeffects]
def S_StopAllSounds(var clear : uint) {
    return
}
[export, sideeffects]
def S_ClearBuffer() {
    return
}
[export, sideeffects]
def S_Update(var origin_1 : int; var v_forward : int; var v_right : int; var v_up : int) {
    return
}
[export, sideeffects]
def S_ExtraUpdate() {
    return
}
[export, sideeffects]
def S_PrecacheSound(var sample : int) : int {
    return 0
}
[export, sideeffects]
def S_TouchSound(var sample_0 : int) {
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
var bgmvolume : cvar_s = cvar_s(name = 736112, string_0 = 736122, archive = 1u, server = 0u, value = 0.0, next = 0)

var volume : cvar_s = cvar_s(name = 736124, string_0 = 736131, archive = 1u, server = 0u, value = 0.0, next = 0)

[export, sideeffects]
def S_LocalSound(var s : int) {
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

// This unit's static data, at heap offset 736112.
let private c2da_lin_static_snd_null_seg = fixed_array<int>(736112, 22)
let private c2da_lin_static_snd_null = fixed_array<uint64>(0x6d756c6f766d6762ul, 0x756c6f7600310065ul, 0x372e3000656dul)

[init]
def private c2da_lin_init_static_snd_null() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_snd_null_seg[s * 2]
        for (k in range(c2da_lin_static_snd_null_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_snd_null[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
