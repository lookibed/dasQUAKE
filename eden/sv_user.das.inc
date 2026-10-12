var sv_player : int = default<int>

[export, sideeffects]
def SV_SetIdealPitch() {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_SetIdealPitch_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def SV_ClientThink() {
    var v_angle : vec3_t
    if (uint_bits_to_float(uint(c2da_mem[sv_player + 140]) | uint(c2da_mem[sv_player + 141]) << 0x8 | uint(c2da_mem[sv_player + 142]) << 0x10 | uint(c2da_mem[sv_player + 143]) << 0x18) == 0.0) {
        return
    }
    onground = uint(int(uint_bits_to_float(uint(c2da_mem[sv_player + 412]) | uint(c2da_mem[sv_player + 413]) << 0x8 | uint(c2da_mem[sv_player + 414]) << 0x10 | uint(c2da_mem[sv_player + 415]) << 0x18)) & 512)
    origin = sv_player + 148
    velocity = sv_player + 172
    DropPunchAngle()
    if (uint_bits_to_float(uint(c2da_mem[sv_player + 300]) | uint(c2da_mem[sv_player + 301]) << 0x8 | uint(c2da_mem[sv_player + 302]) << 0x10 | uint(c2da_mem[sv_player + 303]) << 0x18) <= 0.0) {
        return
    }
    var c2da_fresh16 : usercmd_t
    c2da_fresh16.viewangles[0] = uint_bits_to_float(uint(c2da_mem[host_client + 40]) | uint(c2da_mem[host_client + 41]) << 0x8 | uint(c2da_mem[host_client + 42]) << 0x10 | uint(c2da_mem[host_client + 43]) << 0x18)
    c2da_fresh16.viewangles[1] = uint_bits_to_float(uint(c2da_mem[host_client + 44]) | uint(c2da_mem[host_client + 45]) << 0x8 | uint(c2da_mem[host_client + 46]) << 0x10 | uint(c2da_mem[host_client + 47]) << 0x18)
    c2da_fresh16.viewangles[2] = uint_bits_to_float(uint(c2da_mem[host_client + 48]) | uint(c2da_mem[host_client + 49]) << 0x8 | uint(c2da_mem[host_client + 50]) << 0x10 | uint(c2da_mem[host_client + 51]) << 0x18)
    c2da_fresh16.forwardmove = uint_bits_to_float(uint(c2da_mem[host_client + 52]) | uint(c2da_mem[host_client + 53]) << 0x8 | uint(c2da_mem[host_client + 54]) << 0x10 | uint(c2da_mem[host_client + 55]) << 0x18)
    c2da_fresh16.sidemove = uint_bits_to_float(uint(c2da_mem[host_client + 56]) | uint(c2da_mem[host_client + 57]) << 0x8 | uint(c2da_mem[host_client + 58]) << 0x10 | uint(c2da_mem[host_client + 59]) << 0x18)
    c2da_fresh16.upmove = uint_bits_to_float(uint(c2da_mem[host_client + 60]) | uint(c2da_mem[host_client + 61]) << 0x8 | uint(c2da_mem[host_client + 62]) << 0x10 | uint(c2da_mem[host_client + 63]) << 0x18)
    cmd = c2da_fresh16
    angles = sv_player + 184
    v_angle[0] = uint_bits_to_float(uint(c2da_mem[sv_player + 388 + 0 * 4]) | uint(c2da_mem[sv_player + 388 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[sv_player + 388 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[sv_player + 388 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[sv_player + 208 + 0 * 4]) | uint(c2da_mem[sv_player + 208 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[sv_player + 208 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[sv_player + 208 + 0 * 4 + 3]) << 0x18)
    v_angle[1] = uint_bits_to_float(uint(c2da_mem[sv_player + 388 + 1 * 4]) | uint(c2da_mem[sv_player + 388 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[sv_player + 388 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[sv_player + 388 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[sv_player + 208 + 1 * 4]) | uint(c2da_mem[sv_player + 208 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[sv_player + 208 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[sv_player + 208 + 1 * 4 + 3]) << 0x18)
    v_angle[2] = uint_bits_to_float(uint(c2da_mem[sv_player + 388 + 2 * 4]) | uint(c2da_mem[sv_player + 388 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[sv_player + 388 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[sv_player + 388 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[sv_player + 208 + 2 * 4]) | uint(c2da_mem[sv_player + 208 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[sv_player + 208 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[sv_player + 208 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh17 : float = V_CalcRoll(sv_player + 184, sv_player + 172) * 4.0
    let c2da_fresh18 : uint = float_bits_to_uint(c2da_fresh17)
    c2da_mem[angles + 2 * 4] = uint8(c2da_fresh18)
    c2da_mem[angles + 2 * 4 + 1] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[angles + 2 * 4 + 2] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[angles + 2 * 4 + 3] = uint8(c2da_fresh18 >> 0x18)
    if (uint_bits_to_float(uint(c2da_mem[sv_player + 384]) | uint(c2da_mem[sv_player + 385]) << 0x8 | uint(c2da_mem[sv_player + 386]) << 0x10 | uint(c2da_mem[sv_player + 387]) << 0x18) == 0.0) {
        let c2da_fresh19 : float = -v_angle[0] / 3.0
        let c2da_fresh20 : uint = float_bits_to_uint(c2da_fresh19)
        c2da_mem[angles + 0 * 4] = uint8(c2da_fresh20)
        c2da_mem[angles + 0 * 4 + 1] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[angles + 0 * 4 + 2] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[angles + 0 * 4 + 3] = uint8(c2da_fresh20 >> 0x18)
        let c2da_fresh21 : float = v_angle[1]
        let c2da_fresh22 : uint = float_bits_to_uint(c2da_fresh21)
        c2da_mem[angles + 1 * 4] = uint8(c2da_fresh22)
        c2da_mem[angles + 1 * 4 + 1] = uint8(c2da_fresh22 >> 0x8)
        c2da_mem[angles + 1 * 4 + 2] = uint8(c2da_fresh22 >> 0x10)
        c2da_mem[angles + 1 * 4 + 3] = uint8(c2da_fresh22 >> 0x18)
    }
    if ((int(uint_bits_to_float(uint(c2da_mem[sv_player + 412]) | uint(c2da_mem[sv_player + 413]) << 0x8 | uint(c2da_mem[sv_player + 414]) << 0x10 | uint(c2da_mem[sv_player + 415]) << 0x18)) & 2048) != 0) {
        SV_WaterJump()
        return
    }
    if (uint_bits_to_float(uint(c2da_mem[sv_player + 440]) | uint(c2da_mem[sv_player + 441]) << 0x8 | uint(c2da_mem[sv_player + 442]) << 0x10 | uint(c2da_mem[sv_player + 443]) << 0x18) >= 2.0 && uint_bits_to_float(uint(c2da_mem[sv_player + 140]) | uint(c2da_mem[sv_player + 141]) << 0x8 | uint(c2da_mem[sv_player + 142]) << 0x10 | uint(c2da_mem[sv_player + 143]) << 0x18) != 8.0) {
        SV_WaterMove()
        return
    }
    SV_AirMove()
    return
}
[export, sideeffects]
def SV_AirMove() {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_AirMove_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def SV_AirAccelerate(var wishveloc : int) {
    var addspeed : float
    var wishspd : float
    var accelspeed : float
    wishspd = VectorNormalize(wishveloc)
    if (wishspd > 30.0) {
        wishspd = 30.0
    }
    addspeed = wishspd - (uint_bits_to_float(uint(c2da_mem[velocity + 0 * 4]) | uint(c2da_mem[velocity + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[velocity + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[velocity + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[wishveloc + 0 * 4]) | uint(c2da_mem[wishveloc + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[wishveloc + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[wishveloc + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[velocity + 1 * 4]) | uint(c2da_mem[velocity + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[velocity + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[velocity + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[wishveloc + 1 * 4]) | uint(c2da_mem[wishveloc + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[wishveloc + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[wishveloc + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[velocity + 2 * 4]) | uint(c2da_mem[velocity + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[velocity + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[velocity + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[wishveloc + 2 * 4]) | uint(c2da_mem[wishveloc + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[wishveloc + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[wishveloc + 2 * 4 + 3]) << 0x18))
    if (addspeed <= 0.0) {
        return
    }
    accelspeed = float(double(uint_bits_to_float(uint(c2da_mem[462856]) | uint(c2da_mem[462857]) << 0x8 | uint(c2da_mem[462858]) << 0x10 | uint(c2da_mem[462859]) << 0x18) * wishspeed) * host_frametime)
    if (accelspeed > addspeed) {
        accelspeed = addspeed
    }
    for (i_1 in range(0, 3)) {
        let c2da_fresh42 : float = uint_bits_to_float(uint(c2da_mem[velocity + i_1 * 4]) | uint(c2da_mem[velocity + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[velocity + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[velocity + i_1 * 4 + 3]) << 0x18) + float(accelspeed * uint_bits_to_float(uint(c2da_mem[wishveloc + i_1 * 4]) | uint(c2da_mem[wishveloc + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[wishveloc + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[wishveloc + i_1 * 4 + 3]) << 0x18))
        let c2da_fresh43 : uint = float_bits_to_uint(c2da_fresh42)
        c2da_mem[velocity + i_1 * 4] = uint8(c2da_fresh43)
        c2da_mem[velocity + i_1 * 4 + 1] = uint8(c2da_fresh43 >> 0x8)
        c2da_mem[velocity + i_1 * 4 + 2] = uint8(c2da_fresh43 >> 0x10)
        c2da_mem[velocity + i_1 * 4 + 3] = uint8(c2da_fresh43 >> 0x18)
    }
    return
}
var velocity : int = default<int>

var wishspeed : float = default<float>

[export, sideeffects]
def SV_Accelerate() {
    var addspeed_0 : float
    var accelspeed_0 : float
    addspeed_0 = wishspeed - (uint_bits_to_float(uint(c2da_mem[velocity + 0 * 4]) | uint(c2da_mem[velocity + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[velocity + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[velocity + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[465328 + 0 * 4]) | uint(c2da_mem[465328 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[465328 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[465328 + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[velocity + 1 * 4]) | uint(c2da_mem[velocity + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[velocity + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[velocity + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[465328 + 1 * 4]) | uint(c2da_mem[465328 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[465328 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[465328 + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[velocity + 2 * 4]) | uint(c2da_mem[velocity + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[velocity + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[velocity + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[465328 + 2 * 4]) | uint(c2da_mem[465328 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[465328 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[465328 + 2 * 4 + 3]) << 0x18))
    if (addspeed_0 <= 0.0) {
        return
    }
    accelspeed_0 = float(double(uint_bits_to_float(uint(c2da_mem[462856]) | uint(c2da_mem[462857]) << 0x8 | uint(c2da_mem[462858]) << 0x10 | uint(c2da_mem[462859]) << 0x18)) * host_frametime * double(wishspeed))
    if (accelspeed_0 > addspeed_0) {
        accelspeed_0 = addspeed_0
    }
    for (i_2 in range(0, 3)) {
        let c2da_fresh44 : float = uint_bits_to_float(uint(c2da_mem[velocity + i_2 * 4]) | uint(c2da_mem[velocity + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[velocity + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[velocity + i_2 * 4 + 3]) << 0x18) + float(accelspeed_0 * uint_bits_to_float(uint(c2da_mem[465328 + i_2 * 4]) | uint(c2da_mem[465328 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[465328 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[465328 + i_2 * 4 + 3]) << 0x18))
        let c2da_fresh45 : uint = float_bits_to_uint(c2da_fresh44)
        c2da_mem[velocity + i_2 * 4] = uint8(c2da_fresh45)
        c2da_mem[velocity + i_2 * 4 + 1] = uint8(c2da_fresh45 >> 0x8)
        c2da_mem[velocity + i_2 * 4 + 2] = uint8(c2da_fresh45 >> 0x10)
        c2da_mem[velocity + i_2 * 4 + 3] = uint8(c2da_fresh45 >> 0x18)
    }
    return
}
[export, sideeffects]
def SV_UserFriction() {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_UserFriction_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
var origin : int = default<int>

var onground : uint = default<uint>

var cmd : usercmd_t = default<usercmd_t>

[export, sideeffects]
def SV_WaterMove() {
    let c2da_saved_sp : int = c2da_lin_sp
    SV_WaterMove_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def SV_WaterJump() {
    if (uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20) > double(uint_bits_to_float(uint(c2da_mem[sv_player + 428]) | uint(c2da_mem[sv_player + 429]) << 0x8 | uint(c2da_mem[sv_player + 430]) << 0x10 | uint(c2da_mem[sv_player + 431]) << 0x18)) || uint_bits_to_float(uint(c2da_mem[sv_player + 440]) | uint(c2da_mem[sv_player + 441]) << 0x8 | uint(c2da_mem[sv_player + 442]) << 0x10 | uint(c2da_mem[sv_player + 443]) << 0x18) == 0.0) {
        let c2da_fresh72 : float = float(int(uint_bits_to_float(uint(c2da_mem[sv_player + 412]) | uint(c2da_mem[sv_player + 413]) << 0x8 | uint(c2da_mem[sv_player + 414]) << 0x10 | uint(c2da_mem[sv_player + 415]) << 0x18)) & ~2048)
        let c2da_fresh73 : uint = float_bits_to_uint(c2da_fresh72)
        c2da_mem[sv_player + 412] = uint8(c2da_fresh73)
        c2da_mem[sv_player + 413] = uint8(c2da_fresh73 >> 0x8)
        c2da_mem[sv_player + 414] = uint8(c2da_fresh73 >> 0x10)
        c2da_mem[sv_player + 415] = uint8(c2da_fresh73 >> 0x18)
        let c2da_fresh74 : float = 0.0
        let c2da_fresh75 : uint = float_bits_to_uint(c2da_fresh74)
        c2da_mem[sv_player + 428] = uint8(c2da_fresh75)
        c2da_mem[sv_player + 429] = uint8(c2da_fresh75 >> 0x8)
        c2da_mem[sv_player + 430] = uint8(c2da_fresh75 >> 0x10)
        c2da_mem[sv_player + 431] = uint8(c2da_fresh75 >> 0x18)
    }
    let c2da_fresh76 : float = uint_bits_to_float(uint(c2da_mem[sv_player + 492 + 0 * 4]) | uint(c2da_mem[sv_player + 492 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[sv_player + 492 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[sv_player + 492 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh77 : uint = float_bits_to_uint(c2da_fresh76)
    c2da_mem[sv_player + 172 + 0 * 4] = uint8(c2da_fresh77)
    c2da_mem[sv_player + 172 + 0 * 4 + 1] = uint8(c2da_fresh77 >> 0x8)
    c2da_mem[sv_player + 172 + 0 * 4 + 2] = uint8(c2da_fresh77 >> 0x10)
    c2da_mem[sv_player + 172 + 0 * 4 + 3] = uint8(c2da_fresh77 >> 0x18)
    let c2da_fresh78 : float = uint_bits_to_float(uint(c2da_mem[sv_player + 492 + 1 * 4]) | uint(c2da_mem[sv_player + 492 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[sv_player + 492 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[sv_player + 492 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh79 : uint = float_bits_to_uint(c2da_fresh78)
    c2da_mem[sv_player + 172 + 1 * 4] = uint8(c2da_fresh79)
    c2da_mem[sv_player + 172 + 1 * 4 + 1] = uint8(c2da_fresh79 >> 0x8)
    c2da_mem[sv_player + 172 + 1 * 4 + 2] = uint8(c2da_fresh79 >> 0x10)
    c2da_mem[sv_player + 172 + 1 * 4 + 3] = uint8(c2da_fresh79 >> 0x18)
    return
}
var angles : int = default<int>

[export, sideeffects]
def DropPunchAngle() {
    var len : float = VectorNormalize(sv_player + 208)
    len = float(double(len) - 10.0lf * host_frametime)
    if (len < 0.0) {
        len = 0.0
    }
    VectorScale(sv_player + 208, len, sv_player + 208)
    return
}
[export, sideeffects]
def SV_RunClients() {
    var i_4 : int = 0
    host_client = svs.clients
    while (i_4 < svs.maxclients) {
        if ((uint(c2da_mem[host_client]) | uint(c2da_mem[host_client + 1]) << 0x8 | uint(c2da_mem[host_client + 2]) << 0x10 | uint(c2da_mem[host_client + 3]) << 0x18) == 0u) {
            i_4++
            host_client = host_client + 8288
            continue
        }
        sv_player = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18)
        if (SV_ReadClientMessage() == 0u) {
            SV_DropClient(0u)
            i_4++
            host_client = host_client + 8288
            continue
        }
        if ((uint(c2da_mem[host_client + 4]) | uint(c2da_mem[host_client + 5]) << 0x8 | uint(c2da_mem[host_client + 6]) << 0x10 | uint(c2da_mem[host_client + 7]) << 0x18) == 0u) {
            c2da_lin_memset(int(host_client + 40), 0, 24ul)
            i_4++
            host_client = host_client + 8288
            continue
        }
        if ((uint(c2da_mem[225860]) | uint(c2da_mem[225861]) << 0x8 | uint(c2da_mem[225862]) << 0x10 | uint(c2da_mem[225863]) << 0x18) == 0u && (svs.maxclients > 1 || uint(key_dest) == 0u)) {
            SV_ClientThink()
        }
        i_4++
        host_client = host_client + 8288
    }
    return
}
[export, sideeffects]
def SV_ReadClientMessage() : uint {
    var ret : int
    var cmd_0 : int
    var s : int
    label 0:
    label 1:
    ret = NET_GetMessage(int(uint(c2da_mem[host_client + 32]) | uint(c2da_mem[host_client + 33]) << 0x8 | uint(c2da_mem[host_client + 34]) << 0x10 | uint(c2da_mem[host_client + 35]) << 0x18))
    if (ret == -1) {
        goto label 52
    }
    if (ret == 0) {
        goto label 51
    }
    MSG_BeginReading()
    label 2:
    goto label 3
    if (ret == 1) {
        goto label 0
    }
    return 1u
    label 3:
    if ((uint(c2da_mem[host_client]) | uint(c2da_mem[host_client + 1]) << 0x8 | uint(c2da_mem[host_client + 2]) << 0x10 | uint(c2da_mem[host_client + 3]) << 0x18) == 0u) {
        goto label 50
    }
    if (uint(msg_badread) != 0u) {
        goto label 49
    }
    cmd_0 = MSG_ReadChar()
    if (cmd_0 >= -1 && cmd_0 <= 4) {
        goto cmd_0 + 54
    }
    label 54:
    Sys_Printf(737103, [])
    return 0u
    label 53:
    goto label 1
    label 55:
    label 4:
    goto label 2
    label 58:
    s = MSG_ReadString()
    if ((uint(c2da_mem[host_client + 12]) | uint(c2da_mem[host_client + 13]) << 0x8 | uint(c2da_mem[host_client + 14]) << 0x10 | uint(c2da_mem[host_client + 15]) << 0x18) != 0u) {
        goto label 48
    }
    ret = 0
    label 5:
    if (Q_strncasecmp(s, 737147, 6) == 0) {
        goto label 47
    }
    if (Q_strncasecmp(s, 737154, 3) == 0) {
        goto label 46
    }
    if (Q_strncasecmp(s, 737158, 8) == 0) {
        goto label 45
    }
    if (Q_strncasecmp(s, 737167, 3) == 0) {
        goto label 44
    }
    if (Q_strncasecmp(s, 737171, 4) == 0) {
        goto label 43
    }
    if (Q_strncasecmp(s, 737176, 6) == 0) {
        goto label 42
    }
    if (Q_strncasecmp(s, 737183, 3) == 0) {
        goto label 41
    }
    if (Q_strncasecmp(s, 737187, 8) == 0) {
        goto label 40
    }
    if (Q_strncasecmp(s, 737196, 4) == 0) {
        goto label 39
    }
    if (Q_strncasecmp(s, 737201, 5) == 0) {
        goto label 38
    }
    if (Q_strncasecmp(s, 737207, 4) == 0) {
        goto label 37
    }
    if (Q_strncasecmp(s, 737212, 5) == 0) {
        goto label 36
    }
    if (Q_strncasecmp(s, 737218, 5) == 0) {
        goto label 35
    }
    if (Q_strncasecmp(s, 737224, 5) == 0) {
        goto label 34
    }
    if (Q_strncasecmp(s, 737230, 8) == 0) {
        goto label 33
    }
    if (Q_strncasecmp(s, 737239, 4) == 0) {
        goto label 32
    }
    if (Q_strncasecmp(s, 737244, 4) == 0) {
        goto label 31
    }
    if (Q_strncasecmp(s, 737249, 4) == 0) {
        goto label 30
    }
    if (Q_strncasecmp(s, 737254, 3) == 0) {
        goto label 29
    }
    label 6:
    label 7:
    label 8:
    label 9:
    label 10:
    label 11:
    label 12:
    label 13:
    label 14:
    label 15:
    label 16:
    label 17:
    label 18:
    label 19:
    label 20:
    label 21:
    label 22:
    label 23:
    label 24:
    if (ret == 2) {
        goto label 28
    }
    if (ret == 1) {
        goto label 27
    }
    Con_DPrintf(737258, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(host_client + 8112)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(s))])
    label 25:
    label 26:
    goto label 4
    label 27:
    Cmd_ExecuteString(s, 0u)
    goto label 25
    label 28:
    Cbuf_InsertText(s)
    goto label 26
    label 29:
    ret = 1
    goto label 6
    label 30:
    ret = 1
    goto label 7
    label 31:
    ret = 1
    goto label 8
    label 32:
    ret = 1
    goto label 9
    label 33:
    ret = 1
    goto label 10
    label 34:
    ret = 1
    goto label 11
    label 35:
    ret = 1
    goto label 12
    label 36:
    ret = 1
    goto label 13
    label 37:
    ret = 1
    goto label 14
    label 38:
    ret = 1
    goto label 15
    label 39:
    ret = 1
    goto label 16
    label 40:
    ret = 1
    goto label 17
    label 41:
    ret = 1
    goto label 18
    label 42:
    ret = 1
    goto label 19
    label 43:
    ret = 1
    goto label 20
    label 44:
    ret = 1
    goto label 21
    label 45:
    ret = 1
    goto label 22
    label 46:
    ret = 1
    goto label 23
    label 47:
    ret = 1
    goto label 24
    label 48:
    ret = 2
    goto label 5
    label 56:
    return 0u
    label 57:
    SV_ReadClientMove(host_client + 40)
    goto label 4
    label 49:
    Sys_Printf(737072, [])
    return 0u
    label 50:
    return 0u
    label 51:
    return 1u
    label 52:
    Sys_Printf(737027, [])
    return 0u
}
[export, sideeffects]
def SV_ReadClientMove(var move : int) {
    var i_5 : int
    var angle : vec3_t
    var bits : int
    let c2da_fresh80 : int = host_client + 8148 + int(uint(c2da_mem[host_client + 8212]) | uint(c2da_mem[host_client + 8213]) << 0x8 | uint(c2da_mem[host_client + 8214]) << 0x10 | uint(c2da_mem[host_client + 8215]) << 0x18) % 16 * 4
    let c2da_fresh81 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20) - double(MSG_ReadFloat()))
    let c2da_fresh82 : uint = float_bits_to_uint(c2da_fresh81)
    c2da_mem[c2da_fresh80] = uint8(c2da_fresh82)
    c2da_mem[c2da_fresh80 + 1] = uint8(c2da_fresh82 >> 0x8)
    c2da_mem[c2da_fresh80 + 2] = uint8(c2da_fresh82 >> 0x10)
    c2da_mem[c2da_fresh80 + 3] = uint8(c2da_fresh82 >> 0x18)
    let c2da_fresh83 : int = int(uint(c2da_mem[host_client + 8212]) | uint(c2da_mem[host_client + 8213]) << 0x8 | uint(c2da_mem[host_client + 8214]) << 0x10 | uint(c2da_mem[host_client + 8215]) << 0x18)
    let c2da_fresh84 : int = c2da_fresh83 + 1
    let c2da_fresh85 : uint = uint(c2da_fresh84)
    c2da_mem[host_client + 8212] = uint8(c2da_fresh85)
    c2da_mem[host_client + 8213] = uint8(c2da_fresh85 >> 0x8)
    c2da_mem[host_client + 8214] = uint8(c2da_fresh85 >> 0x10)
    c2da_mem[host_client + 8215] = uint8(c2da_fresh85 >> 0x18)
    i_5 = 0
    for (c2da_i_5 in range(i_5, 3)) {
        angle[c2da_i_5] = MSG_ReadAngle()
    }
    let c2da_fresh86 : int = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18) + 388 + 0 * 4
    let c2da_fresh87 : float = angle[0]
    let c2da_fresh88 : uint = float_bits_to_uint(c2da_fresh87)
    c2da_mem[c2da_fresh86] = uint8(c2da_fresh88)
    c2da_mem[c2da_fresh86 + 1] = uint8(c2da_fresh88 >> 0x8)
    c2da_mem[c2da_fresh86 + 2] = uint8(c2da_fresh88 >> 0x10)
    c2da_mem[c2da_fresh86 + 3] = uint8(c2da_fresh88 >> 0x18)
    let c2da_fresh89 : int = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18) + 388 + 1 * 4
    let c2da_fresh90 : float = angle[1]
    let c2da_fresh91 : uint = float_bits_to_uint(c2da_fresh90)
    c2da_mem[c2da_fresh89] = uint8(c2da_fresh91)
    c2da_mem[c2da_fresh89 + 1] = uint8(c2da_fresh91 >> 0x8)
    c2da_mem[c2da_fresh89 + 2] = uint8(c2da_fresh91 >> 0x10)
    c2da_mem[c2da_fresh89 + 3] = uint8(c2da_fresh91 >> 0x18)
    let c2da_fresh92 : int = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18) + 388 + 2 * 4
    let c2da_fresh93 : float = angle[2]
    let c2da_fresh94 : uint = float_bits_to_uint(c2da_fresh93)
    c2da_mem[c2da_fresh92] = uint8(c2da_fresh94)
    c2da_mem[c2da_fresh92 + 1] = uint8(c2da_fresh94 >> 0x8)
    c2da_mem[c2da_fresh92 + 2] = uint8(c2da_fresh94 >> 0x10)
    c2da_mem[c2da_fresh92 + 3] = uint8(c2da_fresh94 >> 0x18)
    let c2da_fresh95 : float = float(MSG_ReadShort())
    let c2da_fresh96 : uint = float_bits_to_uint(c2da_fresh95)
    c2da_mem[move + 12] = uint8(c2da_fresh96)
    c2da_mem[move + 13] = uint8(c2da_fresh96 >> 0x8)
    c2da_mem[move + 14] = uint8(c2da_fresh96 >> 0x10)
    c2da_mem[move + 15] = uint8(c2da_fresh96 >> 0x18)
    let c2da_fresh97 : float = float(MSG_ReadShort())
    let c2da_fresh98 : uint = float_bits_to_uint(c2da_fresh97)
    c2da_mem[move + 16] = uint8(c2da_fresh98)
    c2da_mem[move + 17] = uint8(c2da_fresh98 >> 0x8)
    c2da_mem[move + 18] = uint8(c2da_fresh98 >> 0x10)
    c2da_mem[move + 19] = uint8(c2da_fresh98 >> 0x18)
    let c2da_fresh99 : float = float(MSG_ReadShort())
    let c2da_fresh100 : uint = float_bits_to_uint(c2da_fresh99)
    c2da_mem[move + 20] = uint8(c2da_fresh100)
    c2da_mem[move + 21] = uint8(c2da_fresh100 >> 0x8)
    c2da_mem[move + 22] = uint8(c2da_fresh100 >> 0x10)
    c2da_mem[move + 23] = uint8(c2da_fresh100 >> 0x18)
    bits = MSG_ReadByte()
    let c2da_fresh101 : int = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18) + 368
    let c2da_fresh102 : float = float(bits & 1)
    let c2da_fresh103 : uint = float_bits_to_uint(c2da_fresh102)
    c2da_mem[c2da_fresh101] = uint8(c2da_fresh103)
    c2da_mem[c2da_fresh101 + 1] = uint8(c2da_fresh103 >> 0x8)
    c2da_mem[c2da_fresh101 + 2] = uint8(c2da_fresh103 >> 0x10)
    c2da_mem[c2da_fresh101 + 3] = uint8(c2da_fresh103 >> 0x18)
    let c2da_fresh104 : int = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18) + 376
    let c2da_fresh105 : float = float((bits & 2) >> 1)
    let c2da_fresh106 : uint = float_bits_to_uint(c2da_fresh105)
    c2da_mem[c2da_fresh104] = uint8(c2da_fresh106)
    c2da_mem[c2da_fresh104 + 1] = uint8(c2da_fresh106 >> 0x8)
    c2da_mem[c2da_fresh104 + 2] = uint8(c2da_fresh106 >> 0x10)
    c2da_mem[c2da_fresh104 + 3] = uint8(c2da_fresh106 >> 0x18)
    i_5 = MSG_ReadByte()
    if (i_5 != 0) {
        let c2da_fresh107 : int = int(uint(c2da_mem[host_client + 8104]) | uint(c2da_mem[host_client + 8105]) << 0x8 | uint(c2da_mem[host_client + 8106]) << 0x10 | uint(c2da_mem[host_client + 8107]) << 0x18) + 380
        let c2da_fresh108 : float = float(i_5)
        let c2da_fresh109 : uint = float_bits_to_uint(c2da_fresh108)
        c2da_mem[c2da_fresh107] = uint8(c2da_fresh109)
        c2da_mem[c2da_fresh107 + 1] = uint8(c2da_fresh109 >> 0x8)
        c2da_mem[c2da_fresh107 + 2] = uint8(c2da_fresh109 >> 0x10)
        c2da_mem[c2da_fresh107 + 3] = uint8(c2da_fresh109 >> 0x18)
    }
    return
}
[sideeffects]
def private SV_SetIdealPitch_c2da_frame(c2da_fp : int) {
    var angleval : float
    var sinval : float
    var cosval : float
    var tr : trace_t
    var z : float[6]
    var i : int
    var step : int
    var dir : int
    var steps : int
    if ((int(uint_bits_to_float(uint(c2da_mem[sv_player + 412]) | uint(c2da_mem[sv_player + 413]) << 0x8 | uint(c2da_mem[sv_player + 414]) << 0x10 | uint(c2da_mem[sv_player + 415]) << 0x18)) & 512) == 0) {
        return
    }
    angleval = float(double(uint_bits_to_float(uint(c2da_mem[sv_player + 184 + 1 * 4]) | uint(c2da_mem[sv_player + 184 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[sv_player + 184 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[sv_player + 184 + 1 * 4 + 3]) << 0x18)) * 3.141592653589793lf * 2.0lf / 360.0lf)
    sinval = float(sin(double(angleval)))
    cosval = float(cos(double(angleval)))
    i = 0
    while (i < 6) {
        let c2da_fresh0 : float = uint_bits_to_float(uint(c2da_mem[sv_player + 148 + 0 * 4]) | uint(c2da_mem[sv_player + 148 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[sv_player + 148 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[sv_player + 148 + 0 * 4 + 3]) << 0x18) + cosval * float(i + 3) * 12.0
        let c2da_fresh1 : uint = float_bits_to_uint(c2da_fresh0)
        c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh1)
        c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
        let c2da_fresh2 : float = uint_bits_to_float(uint(c2da_mem[sv_player + 148 + 1 * 4]) | uint(c2da_mem[sv_player + 148 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[sv_player + 148 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[sv_player + 148 + 1 * 4 + 3]) << 0x18) + sinval * float(i + 3) * 12.0
        let c2da_fresh3 : uint = float_bits_to_uint(c2da_fresh2)
        c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh3)
        c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
        let c2da_fresh4 : float = uint_bits_to_float(uint(c2da_mem[sv_player + 148 + 2 * 4]) | uint(c2da_mem[sv_player + 148 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[sv_player + 148 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[sv_player + 148 + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[sv_player + 356 + 2 * 4]) | uint(c2da_mem[sv_player + 356 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[sv_player + 356 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[sv_player + 356 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh5 : uint = float_bits_to_uint(c2da_fresh4)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh5)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh5 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh5 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh5 >> 0x18)
        let c2da_fresh6 : float = c2da_fresh0
        let c2da_fresh7 : uint = float_bits_to_uint(c2da_fresh6)
        c2da_mem[c2da_fp + 16 + 0 * 4] = uint8(c2da_fresh7)
        c2da_mem[c2da_fp + 16 + 0 * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
        c2da_mem[c2da_fp + 16 + 0 * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
        c2da_mem[c2da_fp + 16 + 0 * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
        let c2da_fresh8 : float = c2da_fresh2
        let c2da_fresh9 : uint = float_bits_to_uint(c2da_fresh8)
        c2da_mem[c2da_fp + 16 + 1 * 4] = uint8(c2da_fresh9)
        c2da_mem[c2da_fp + 16 + 1 * 4 + 1] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[c2da_fp + 16 + 1 * 4 + 2] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[c2da_fp + 16 + 1 * 4 + 3] = uint8(c2da_fresh9 >> 0x18)
        let c2da_fresh10 : float = c2da_fresh4 - 160.0
        let c2da_fresh11 : uint = float_bits_to_uint(c2da_fresh10)
        c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh11)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh11 >> 0x18)
        tr = SV_Move(c2da_fp, 194432, 194432, c2da_fp + 16, 1, sv_player)
        if (tr.allsolid != 0u) {
            return
        }
        if (tr.fraction == 1.0) {
            return
        }
        z[i] = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) + tr.fraction * (uint_bits_to_float(uint(c2da_mem[c2da_fp + 16 + 2 * 4]) | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 16 + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18))
        i++
    }
    dir = 0
    steps = 0
    for (j in range(1, i)) {
        step = int(z[j] - z[j - 1])
        if (double(step) > -0.1lf && double(step) < 0.1lf) {
            continue
        }
        if (dir != 0 && (double(step - dir) > 0.1lf || double(step - dir) < -0.1lf)) {
            return
        }
        steps++
        dir = step
    }
    if (dir == 0) {
        let c2da_fresh12 : float = 0.0
        let c2da_fresh13 : uint = float_bits_to_uint(c2da_fresh12)
        c2da_mem[sv_player + 400] = uint8(c2da_fresh13)
        c2da_mem[sv_player + 401] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[sv_player + 402] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[sv_player + 403] = uint8(c2da_fresh13 >> 0x18)
        return
    }
    if (steps < 2) {
        return
    }
    let c2da_fresh14 : float = float(-dir) * uint_bits_to_float(uint(c2da_mem[462904]) | uint(c2da_mem[462905]) << 0x8 | uint(c2da_mem[462906]) << 0x10 | uint(c2da_mem[462907]) << 0x18)
    let c2da_fresh15 : uint = float_bits_to_uint(c2da_fresh14)
    c2da_mem[sv_player + 400] = uint8(c2da_fresh15)
    c2da_mem[sv_player + 401] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[sv_player + 402] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[sv_player + 403] = uint8(c2da_fresh15 >> 0x18)
    return
}
[sideeffects]
def private SV_AirMove_c2da_frame(c2da_fp : int) {
    var fmove : float
    var smove : float
    AngleVectors(sv_player + 184, 736912, 736928, 736944)
    fmove = cmd.forwardmove
    smove = cmd.sidemove
    if (uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20) < double(uint_bits_to_float(uint(c2da_mem[sv_player + 428]) | uint(c2da_mem[sv_player + 429]) << 0x8 | uint(c2da_mem[sv_player + 430]) << 0x10 | uint(c2da_mem[sv_player + 431]) << 0x18)) && fmove < 0.0) {
        fmove = 0.0
    }
    for (i_0 in range(0, 3)) {
        let c2da_fresh23 : float = uint_bits_to_float(uint(c2da_mem[736912 + i_0 * 4]) | uint(c2da_mem[736912 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[736912 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[736912 + i_0 * 4 + 3]) << 0x18) * fmove + uint_bits_to_float(uint(c2da_mem[736928 + i_0 * 4]) | uint(c2da_mem[736928 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[736928 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[736928 + i_0 * 4 + 3]) << 0x18) * smove
        let c2da_fresh24 : uint = float_bits_to_uint(c2da_fresh23)
        c2da_mem[c2da_fp + i_0 * 4] = uint8(c2da_fresh24)
        c2da_mem[c2da_fp + i_0 * 4 + 1] = uint8(c2da_fresh24 >> 0x8)
        c2da_mem[c2da_fp + i_0 * 4 + 2] = uint8(c2da_fresh24 >> 0x10)
        c2da_mem[c2da_fp + i_0 * 4 + 3] = uint8(c2da_fresh24 >> 0x18)
    }
    if (int(uint_bits_to_float(uint(c2da_mem[sv_player + 140]) | uint(c2da_mem[sv_player + 141]) << 0x8 | uint(c2da_mem[sv_player + 142]) << 0x10 | uint(c2da_mem[sv_player + 143]) << 0x18)) != 3) {
        let c2da_fresh25 : float = cmd.upmove
        let c2da_fresh26 : uint = float_bits_to_uint(c2da_fresh25)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh26)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh26 >> 0x18)
    } else {
        let c2da_fresh27 : float = 0.0
        let c2da_fresh28 : uint = float_bits_to_uint(c2da_fresh27)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh28)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh28 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh28 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh28 >> 0x18)
    }
    let c2da_fresh29 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
    let c2da_fresh30 : uint = float_bits_to_uint(c2da_fresh29)
    c2da_mem[465328 + 0 * 4] = uint8(c2da_fresh30)
    c2da_mem[465328 + 0 * 4 + 1] = uint8(c2da_fresh30 >> 0x8)
    c2da_mem[465328 + 0 * 4 + 2] = uint8(c2da_fresh30 >> 0x10)
    c2da_mem[465328 + 0 * 4 + 3] = uint8(c2da_fresh30 >> 0x18)
    let c2da_fresh31 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
    let c2da_fresh32 : uint = float_bits_to_uint(c2da_fresh31)
    c2da_mem[465328 + 1 * 4] = uint8(c2da_fresh32)
    c2da_mem[465328 + 1 * 4 + 1] = uint8(c2da_fresh32 >> 0x8)
    c2da_mem[465328 + 1 * 4 + 2] = uint8(c2da_fresh32 >> 0x10)
    c2da_mem[465328 + 1 * 4 + 3] = uint8(c2da_fresh32 >> 0x18)
    let c2da_fresh33 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
    let c2da_fresh34 : uint = float_bits_to_uint(c2da_fresh33)
    c2da_mem[465328 + 2 * 4] = uint8(c2da_fresh34)
    c2da_mem[465328 + 2 * 4 + 1] = uint8(c2da_fresh34 >> 0x8)
    c2da_mem[465328 + 2 * 4 + 2] = uint8(c2da_fresh34 >> 0x10)
    c2da_mem[465328 + 2 * 4 + 3] = uint8(c2da_fresh34 >> 0x18)
    wishspeed = VectorNormalize(465328)
    let c2da_fresh41 : float = uint_bits_to_float(uint(c2da_mem[462808]) | uint(c2da_mem[462809]) << 0x8 | uint(c2da_mem[462810]) << 0x10 | uint(c2da_mem[462811]) << 0x18)
    if (wishspeed > c2da_fresh41) {
        VectorScale(c2da_fp, uint_bits_to_float(uint(c2da_mem[462808]) | uint(c2da_mem[462809]) << 0x8 | uint(c2da_mem[462810]) << 0x10 | uint(c2da_mem[462811]) << 0x18) / wishspeed, c2da_fp)
        wishspeed = uint_bits_to_float(uint(c2da_mem[462808]) | uint(c2da_mem[462809]) << 0x8 | uint(c2da_mem[462810]) << 0x10 | uint(c2da_mem[462811]) << 0x18)
    }
    if (uint_bits_to_float(uint(c2da_mem[sv_player + 140]) | uint(c2da_mem[sv_player + 141]) << 0x8 | uint(c2da_mem[sv_player + 142]) << 0x10 | uint(c2da_mem[sv_player + 143]) << 0x18) == 8.0) {
        let c2da_fresh35 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
        let c2da_fresh36 : uint = float_bits_to_uint(c2da_fresh35)
        c2da_mem[velocity + 0 * 4] = uint8(c2da_fresh36)
        c2da_mem[velocity + 0 * 4 + 1] = uint8(c2da_fresh36 >> 0x8)
        c2da_mem[velocity + 0 * 4 + 2] = uint8(c2da_fresh36 >> 0x10)
        c2da_mem[velocity + 0 * 4 + 3] = uint8(c2da_fresh36 >> 0x18)
        let c2da_fresh37 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
        let c2da_fresh38 : uint = float_bits_to_uint(c2da_fresh37)
        c2da_mem[velocity + 1 * 4] = uint8(c2da_fresh38)
        c2da_mem[velocity + 1 * 4 + 1] = uint8(c2da_fresh38 >> 0x8)
        c2da_mem[velocity + 1 * 4 + 2] = uint8(c2da_fresh38 >> 0x10)
        c2da_mem[velocity + 1 * 4 + 3] = uint8(c2da_fresh38 >> 0x18)
        let c2da_fresh39 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)
        let c2da_fresh40 : uint = float_bits_to_uint(c2da_fresh39)
        c2da_mem[velocity + 2 * 4] = uint8(c2da_fresh40)
        c2da_mem[velocity + 2 * 4 + 1] = uint8(c2da_fresh40 >> 0x8)
        c2da_mem[velocity + 2 * 4 + 2] = uint8(c2da_fresh40 >> 0x10)
        c2da_mem[velocity + 2 * 4 + 3] = uint8(c2da_fresh40 >> 0x18)
    } elif (onground != 0u) {
        SV_UserFriction()
        SV_Accelerate()
    } else {
        SV_AirAccelerate(c2da_fp)
    }
    return
}
[sideeffects]
def private SV_UserFriction_c2da_frame(c2da_fp : int) {
    var vel : int
    var speed : float
    var newspeed : float
    var friction : float
    var trace : trace_t
    vel = velocity
    speed = float(sqrt(double(uint_bits_to_float(uint(c2da_mem[vel + 0 * 4]) | uint(c2da_mem[vel + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[vel + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[vel + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[vel + 0 * 4]) | uint(c2da_mem[vel + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[vel + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[vel + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[vel + 1 * 4]) | uint(c2da_mem[vel + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[vel + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[vel + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[vel + 1 * 4]) | uint(c2da_mem[vel + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[vel + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[vel + 1 * 4 + 3]) << 0x18))))
    if (speed == 0.0) {
        return
    }
    let c2da_fresh46 : float = uint_bits_to_float(uint(c2da_mem[origin + 0 * 4]) | uint(c2da_mem[origin + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[origin + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[origin + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[vel + 0 * 4]) | uint(c2da_mem[vel + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[vel + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[vel + 0 * 4 + 3]) << 0x18) / speed * 16.0
    let c2da_fresh47 : uint = float_bits_to_uint(c2da_fresh46)
    c2da_mem[c2da_fp + 16 + 0 * 4] = uint8(c2da_fresh47)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 1] = uint8(c2da_fresh47 >> 0x8)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 2] = uint8(c2da_fresh47 >> 0x10)
    c2da_mem[c2da_fp + 16 + 0 * 4 + 3] = uint8(c2da_fresh47 >> 0x18)
    let c2da_fresh48 : uint = float_bits_to_uint(c2da_fresh46)
    c2da_mem[c2da_fp + 0 * 4] = uint8(c2da_fresh48)
    c2da_mem[c2da_fp + 0 * 4 + 1] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[c2da_fp + 0 * 4 + 2] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[c2da_fp + 0 * 4 + 3] = uint8(c2da_fresh48 >> 0x18)
    let c2da_fresh49 : float = uint_bits_to_float(uint(c2da_mem[origin + 1 * 4]) | uint(c2da_mem[origin + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[origin + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[origin + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[vel + 1 * 4]) | uint(c2da_mem[vel + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[vel + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[vel + 1 * 4 + 3]) << 0x18) / speed * 16.0
    let c2da_fresh50 : uint = float_bits_to_uint(c2da_fresh49)
    c2da_mem[c2da_fp + 16 + 1 * 4] = uint8(c2da_fresh50)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 1] = uint8(c2da_fresh50 >> 0x8)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 2] = uint8(c2da_fresh50 >> 0x10)
    c2da_mem[c2da_fp + 16 + 1 * 4 + 3] = uint8(c2da_fresh50 >> 0x18)
    let c2da_fresh51 : uint = float_bits_to_uint(c2da_fresh49)
    c2da_mem[c2da_fp + 1 * 4] = uint8(c2da_fresh51)
    c2da_mem[c2da_fp + 1 * 4 + 1] = uint8(c2da_fresh51 >> 0x8)
    c2da_mem[c2da_fp + 1 * 4 + 2] = uint8(c2da_fresh51 >> 0x10)
    c2da_mem[c2da_fp + 1 * 4 + 3] = uint8(c2da_fresh51 >> 0x18)
    let c2da_fresh52 : float = uint_bits_to_float(uint(c2da_mem[origin + 2 * 4]) | uint(c2da_mem[origin + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[origin + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[origin + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[sv_player + 240 + 2 * 4]) | uint(c2da_mem[sv_player + 240 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[sv_player + 240 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[sv_player + 240 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh53 : uint = float_bits_to_uint(c2da_fresh52)
    c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh53)
    c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh53 >> 0x8)
    c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh53 >> 0x10)
    c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh53 >> 0x18)
    let c2da_fresh54 : float = c2da_fresh52 - 34.0
    let c2da_fresh55 : uint = float_bits_to_uint(c2da_fresh54)
    c2da_mem[c2da_fp + 16 + 2 * 4] = uint8(c2da_fresh55)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 1] = uint8(c2da_fresh55 >> 0x8)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 2] = uint8(c2da_fresh55 >> 0x10)
    c2da_mem[c2da_fp + 16 + 2 * 4 + 3] = uint8(c2da_fresh55 >> 0x18)
    trace = SV_Move(c2da_fp, 194432, 194432, c2da_fp + 16, 1, sv_player)
    if (double(trace.fraction) == 1.0lf) {
        friction = uint_bits_to_float(uint(c2da_mem[462664]) | uint(c2da_mem[462665]) << 0x8 | uint(c2da_mem[462666]) << 0x10 | uint(c2da_mem[462667]) << 0x18) * uint_bits_to_float(uint(c2da_mem[462712]) | uint(c2da_mem[462713]) << 0x8 | uint(c2da_mem[462714]) << 0x10 | uint(c2da_mem[462715]) << 0x18)
    } else {
        friction = uint_bits_to_float(uint(c2da_mem[462664]) | uint(c2da_mem[462665]) << 0x8 | uint(c2da_mem[462666]) << 0x10 | uint(c2da_mem[462667]) << 0x18)
    }
    let c2da_fresh62 : float = uint_bits_to_float(uint(c2da_mem[462760]) | uint(c2da_mem[462761]) << 0x8 | uint(c2da_mem[462762]) << 0x10 | uint(c2da_mem[462763]) << 0x18)
    newspeed = float(double(speed) - host_frametime * double(speed < c2da_fresh62 ? c2da_fresh62 : speed) * double(friction))
    if (newspeed < 0.0) {
        newspeed = 0.0
    }
    newspeed /= speed
    let c2da_fresh56 : float = uint_bits_to_float(uint(c2da_mem[vel + 0 * 4]) | uint(c2da_mem[vel + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[vel + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[vel + 0 * 4 + 3]) << 0x18) * newspeed
    let c2da_fresh57 : uint = float_bits_to_uint(c2da_fresh56)
    c2da_mem[vel + 0 * 4] = uint8(c2da_fresh57)
    c2da_mem[vel + 0 * 4 + 1] = uint8(c2da_fresh57 >> 0x8)
    c2da_mem[vel + 0 * 4 + 2] = uint8(c2da_fresh57 >> 0x10)
    c2da_mem[vel + 0 * 4 + 3] = uint8(c2da_fresh57 >> 0x18)
    let c2da_fresh58 : float = uint_bits_to_float(uint(c2da_mem[vel + 1 * 4]) | uint(c2da_mem[vel + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[vel + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[vel + 1 * 4 + 3]) << 0x18) * newspeed
    let c2da_fresh59 : uint = float_bits_to_uint(c2da_fresh58)
    c2da_mem[vel + 1 * 4] = uint8(c2da_fresh59)
    c2da_mem[vel + 1 * 4 + 1] = uint8(c2da_fresh59 >> 0x8)
    c2da_mem[vel + 1 * 4 + 2] = uint8(c2da_fresh59 >> 0x10)
    c2da_mem[vel + 1 * 4 + 3] = uint8(c2da_fresh59 >> 0x18)
    let c2da_fresh60 : float = uint_bits_to_float(uint(c2da_mem[vel + 2 * 4]) | uint(c2da_mem[vel + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[vel + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[vel + 2 * 4 + 3]) << 0x18) * newspeed
    let c2da_fresh61 : uint = float_bits_to_uint(c2da_fresh60)
    c2da_mem[vel + 2 * 4] = uint8(c2da_fresh61)
    c2da_mem[vel + 2 * 4 + 1] = uint8(c2da_fresh61 >> 0x8)
    c2da_mem[vel + 2 * 4 + 2] = uint8(c2da_fresh61 >> 0x10)
    c2da_mem[vel + 2 * 4 + 3] = uint8(c2da_fresh61 >> 0x18)
    return
}
[sideeffects]
def private SV_WaterMove_c2da_frame(c2da_fp : int) {
    var i_3 : int
    var speed_0 : float
    var newspeed_0 : float
    var wishspeed_0 : float
    var addspeed_1 : float
    var accelspeed_1 : float
    AngleVectors(sv_player + 388, 736912, 736928, 736944)
    i_3 = 0
    while (i_3 < 3) {
        let c2da_fresh63 : float = uint_bits_to_float(uint(c2da_mem[736912 + i_3 * 4]) | uint(c2da_mem[736912 + i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[736912 + i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[736912 + i_3 * 4 + 3]) << 0x18) * cmd.forwardmove + uint_bits_to_float(uint(c2da_mem[736928 + i_3 * 4]) | uint(c2da_mem[736928 + i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[736928 + i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[736928 + i_3 * 4 + 3]) << 0x18) * cmd.sidemove
        let c2da_fresh64 : uint = float_bits_to_uint(c2da_fresh63)
        c2da_mem[c2da_fp + i_3 * 4] = uint8(c2da_fresh64)
        c2da_mem[c2da_fp + i_3 * 4 + 1] = uint8(c2da_fresh64 >> 0x8)
        c2da_mem[c2da_fp + i_3 * 4 + 2] = uint8(c2da_fresh64 >> 0x10)
        c2da_mem[c2da_fp + i_3 * 4 + 3] = uint8(c2da_fresh64 >> 0x18)
        i_3++
    }
    if (cmd.forwardmove == 0.0 && cmd.sidemove == 0.0 && cmd.upmove == 0.0) {
        let c2da_fresh65 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) - 60.0
        let c2da_fresh66 : uint = float_bits_to_uint(c2da_fresh65)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh66)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh66 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh66 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh66 >> 0x18)
    } else {
        let c2da_fresh67 : float = uint_bits_to_float(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) + cmd.upmove
        let c2da_fresh68 : uint = float_bits_to_uint(c2da_fresh67)
        c2da_mem[c2da_fp + 2 * 4] = uint8(c2da_fresh68)
        c2da_mem[c2da_fp + 2 * 4 + 1] = uint8(c2da_fresh68 >> 0x8)
        c2da_mem[c2da_fp + 2 * 4 + 2] = uint8(c2da_fresh68 >> 0x10)
        c2da_mem[c2da_fp + 2 * 4 + 3] = uint8(c2da_fresh68 >> 0x18)
    }
    wishspeed_0 = Length(c2da_fp)
    let c2da_fresh71 : float = uint_bits_to_float(uint(c2da_mem[462808]) | uint(c2da_mem[462809]) << 0x8 | uint(c2da_mem[462810]) << 0x10 | uint(c2da_mem[462811]) << 0x18)
    if (wishspeed_0 > c2da_fresh71) {
        VectorScale(c2da_fp, uint_bits_to_float(uint(c2da_mem[462808]) | uint(c2da_mem[462809]) << 0x8 | uint(c2da_mem[462810]) << 0x10 | uint(c2da_mem[462811]) << 0x18) / wishspeed_0, c2da_fp)
        wishspeed_0 = uint_bits_to_float(uint(c2da_mem[462808]) | uint(c2da_mem[462809]) << 0x8 | uint(c2da_mem[462810]) << 0x10 | uint(c2da_mem[462811]) << 0x18)
    }
    wishspeed_0 = float(double(wishspeed_0) * 0.7lf)
    speed_0 = Length(velocity)
    if (speed_0 != 0.0) {
        newspeed_0 = float(double(speed_0) - host_frametime * double(speed_0) * double(uint_bits_to_float(uint(c2da_mem[462664]) | uint(c2da_mem[462665]) << 0x8 | uint(c2da_mem[462666]) << 0x10 | uint(c2da_mem[462667]) << 0x18)))
        if (newspeed_0 < 0.0) {
            newspeed_0 = 0.0
        }
        VectorScale(velocity, newspeed_0 / speed_0, velocity)
    } else {
        newspeed_0 = 0.0
    }
    if (wishspeed_0 == 0.0) {
        return
    }
    addspeed_1 = wishspeed_0 - newspeed_0
    if (addspeed_1 <= 0.0) {
        return
    }
    VectorNormalize(c2da_fp)
    accelspeed_1 = float(double(uint_bits_to_float(uint(c2da_mem[462856]) | uint(c2da_mem[462857]) << 0x8 | uint(c2da_mem[462858]) << 0x10 | uint(c2da_mem[462859]) << 0x18) * wishspeed_0) * host_frametime)
    if (accelspeed_1 > addspeed_1) {
        accelspeed_1 = addspeed_1
    }
    i_3 = 0
    for (c2da_i_3 in range(i_3, 3)) {
        let c2da_fresh69 : float = uint_bits_to_float(uint(c2da_mem[velocity + c2da_i_3 * 4]) | uint(c2da_mem[velocity + c2da_i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[velocity + c2da_i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[velocity + c2da_i_3 * 4 + 3]) << 0x18) + float(accelspeed_1 * uint_bits_to_float(uint(c2da_mem[c2da_fp + c2da_i_3 * 4]) | uint(c2da_mem[c2da_fp + c2da_i_3 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + c2da_i_3 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + c2da_i_3 * 4 + 3]) << 0x18))
        let c2da_fresh70 : uint = float_bits_to_uint(c2da_fresh69)
        c2da_mem[velocity + c2da_i_3 * 4] = uint8(c2da_fresh70)
        c2da_mem[velocity + c2da_i_3 * 4 + 1] = uint8(c2da_fresh70 >> 0x8)
        c2da_mem[velocity + c2da_i_3 * 4 + 2] = uint8(c2da_fresh70 >> 0x10)
        c2da_mem[velocity + c2da_i_3 * 4 + 3] = uint8(c2da_fresh70 >> 0x18)
    }
    return
}

// This unit's static data, at heap offset 736912.
let private c2da_lin_static_sv_user_seg = fixed_array<int>(736956, 317)
let private c2da_lin_static_sv_user = fixed_array<uint64>(0x6c616564695f7673ul, 0x6163736863746970ul, 0x7300382e3000656cul, 0x656c656363615f76ul, 0x30310065746172ul, 0x6369726665676465ul, 0x730032006e6f6974ul, 0x65707378616d5f76ul, 0x5300303233006465ul, 0x6c43646165525f56ul, 0x7373654d746e6569ul, 0x54454e203a656761ul, 0x7373654d7465475ful, 0x6c69616620656761ul, 0x525f5653000a6465ul, 0x6e65696c43646165ul, 0x6567617373654d74ul, 0x616572646162203aul, 0x65525f5653000a64ul, 0x746e65696c436461ul, 0x3a6567617373654dul, 0x6e776f6e6b6e7520ul, 0x646e616d6d6f6320ul, 0x73000a7261686320ul, 0x6f67007375746174ul, 0x677261746f6e0064ul, 0x6e00796c66007465ul, 0x6c636f6e00656d61ul, 0x7300796173007069ul, 0x6d6165745f7961ul, 0x6c6f63006c6c6574ul, 0x6c6c696b00726ful, 0x7073006573756170ul, 0x69676562006e7761ul, 0x617073657270006eul, 0x6b63696b006e77ul, 0x76696700676e6970ul, 0x7325006e61620065ul, 0x7420646569727420ul, 0xa7325206ful)

[init]
def private c2da_lin_init_static_sv_user() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_sv_user_seg[s * 2]
        for (k in range(c2da_lin_static_sv_user_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_sv_user[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_sv_user_0 = fixed_array<uint8>(0xbc, 0x3e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xcf, 0x3e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_sv_user_1 = fixed_array<uint8>(0xd3, 0x3e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe1, 0x3e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_sv_user_2 = fixed_array<uint8>(0xe4, 0x3e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf1, 0x3e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_sv_user_3 = fixed_array<uint8>(0xf3, 0x3e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x3e, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_sv_user() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[462880 + i] = c2da_lin_extern_sv_user_0[i]
    }
    for (i in range(40)) {
        c2da_mem[462832 + i] = c2da_lin_extern_sv_user_1[i]
    }
    for (i in range(40)) {
        c2da_mem[462688 + i] = c2da_lin_extern_sv_user_2[i]
    }
    for (i in range(40)) {
        c2da_mem[462784 + i] = c2da_lin_extern_sv_user_3[i]
    }
}
