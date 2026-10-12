[export, sideeffects]
def Cvar_RegisterVariable(var variable : int) {
    var oldstr : int
    if (Cvar_FindVar(int(uint(c2da_mem[variable]) | uint(c2da_mem[variable + 1]) << 0x8 | uint(c2da_mem[variable + 2]) << 0x10 | uint(c2da_mem[variable + 3]) << 0x18)) != 0) {
        Con_Printf(706800, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[variable]) | uint(c2da_mem[variable + 1]) << 0x8 | uint(c2da_mem[variable + 2]) << 0x10 | uint(c2da_mem[variable + 3]) << 0x18)))])
        return
    }
    if (uint(Cmd_Exists(int(uint(c2da_mem[variable]) | uint(c2da_mem[variable + 1]) << 0x8 | uint(c2da_mem[variable + 2]) << 0x10 | uint(c2da_mem[variable + 3]) << 0x18))) != 0u) {
        Con_Printf(706846, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[variable]) | uint(c2da_mem[variable + 1]) << 0x8 | uint(c2da_mem[variable + 2]) << 0x10 | uint(c2da_mem[variable + 3]) << 0x18)))])
        return
    }
    oldstr = int(uint(c2da_mem[variable + 8]) | uint(c2da_mem[variable + 9]) << 0x8 | uint(c2da_mem[variable + 10]) << 0x10 | uint(c2da_mem[variable + 11]) << 0x18)
    let c2da_fresh0 : int = Z_Malloc(Q_strlen(int(uint(c2da_mem[variable + 8]) | uint(c2da_mem[variable + 9]) << 0x8 | uint(c2da_mem[variable + 10]) << 0x10 | uint(c2da_mem[variable + 11]) << 0x18)) + 1)
    let c2da_fresh1 : uint = uint(c2da_fresh0)
    c2da_mem[variable + 8] = uint8(c2da_fresh1)
    c2da_mem[variable + 9] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[variable + 10] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[variable + 11] = uint8(c2da_fresh1 >> 0x18)
    c2da_mem[variable + 12] = 0u8
    c2da_mem[variable + 13] = 0u8
    c2da_mem[variable + 14] = 0u8
    c2da_mem[variable + 15] = 0u8
    Q_strcpy(int(uint(c2da_mem[variable + 8]) | uint(c2da_mem[variable + 9]) << 0x8 | uint(c2da_mem[variable + 10]) << 0x10 | uint(c2da_mem[variable + 11]) << 0x18), oldstr)
    let c2da_fresh2 : float = Q_atof(int(uint(c2da_mem[variable + 8]) | uint(c2da_mem[variable + 9]) << 0x8 | uint(c2da_mem[variable + 10]) << 0x10 | uint(c2da_mem[variable + 11]) << 0x18))
    let c2da_fresh3 : uint = float_bits_to_uint(c2da_fresh2)
    c2da_mem[variable + 24] = uint8(c2da_fresh3)
    c2da_mem[variable + 25] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[variable + 26] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[variable + 27] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : uint = uint(cvar_vars)
    c2da_mem[variable + 32] = uint8(c2da_fresh4)
    c2da_mem[variable + 33] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[variable + 34] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[variable + 35] = uint8(c2da_fresh4 >> 0x18)
    c2da_mem[variable + 36] = 0u8
    c2da_mem[variable + 37] = 0u8
    c2da_mem[variable + 38] = 0u8
    c2da_mem[variable + 39] = 0u8
    cvar_vars = int(variable)  // nolint:PERF020
    return
}
var cvar_vars : int = default<int>

[export, sideeffects]
def Cvar_FindVar(var var_name : int) : int {
    var var_0 : int = cvar_vars
    while (var_0 != 0) {
        if (Q_strcmp(var_name, int(uint(c2da_mem[var_0]) | uint(c2da_mem[var_0 + 1]) << 0x8 | uint(c2da_mem[var_0 + 2]) << 0x10 | uint(c2da_mem[var_0 + 3]) << 0x18)) == 0) {
            return var_0
        }
        var_0 = int(uint(c2da_mem[var_0 + 32]) | uint(c2da_mem[var_0 + 33]) << 0x8 | uint(c2da_mem[var_0 + 34]) << 0x10 | uint(c2da_mem[var_0 + 35]) << 0x18)
    }
    return 0
}
[export, sideeffects]
def Cvar_Set(var var_name_0 : int; var value : int) {
    var var_1 : int
    var changed : uint
    var_1 = Cvar_FindVar(var_name_0)
    if (var_1 == 0) {
        Con_Printf(706886, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(var_name_0))])
        return
    }
    changed = uint(Q_strcmp(int(uint(c2da_mem[var_1 + 8]) | uint(c2da_mem[var_1 + 9]) << 0x8 | uint(c2da_mem[var_1 + 10]) << 0x10 | uint(c2da_mem[var_1 + 11]) << 0x18), value))
    Z_Free(int(uint(c2da_mem[var_1 + 8]) | uint(c2da_mem[var_1 + 9]) << 0x8 | uint(c2da_mem[var_1 + 10]) << 0x10 | uint(c2da_mem[var_1 + 11]) << 0x18))
    let c2da_fresh5 : int = Z_Malloc(Q_strlen(value) + 1)
    let c2da_fresh6 : uint = uint(c2da_fresh5)
    c2da_mem[var_1 + 8] = uint8(c2da_fresh6)
    c2da_mem[var_1 + 9] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[var_1 + 10] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[var_1 + 11] = uint8(c2da_fresh6 >> 0x18)
    c2da_mem[var_1 + 12] = 0u8
    c2da_mem[var_1 + 13] = 0u8
    c2da_mem[var_1 + 14] = 0u8
    c2da_mem[var_1 + 15] = 0u8
    Q_strcpy(int(uint(c2da_mem[var_1 + 8]) | uint(c2da_mem[var_1 + 9]) << 0x8 | uint(c2da_mem[var_1 + 10]) << 0x10 | uint(c2da_mem[var_1 + 11]) << 0x18), value)
    let c2da_fresh7 : float = Q_atof(int(uint(c2da_mem[var_1 + 8]) | uint(c2da_mem[var_1 + 9]) << 0x8 | uint(c2da_mem[var_1 + 10]) << 0x10 | uint(c2da_mem[var_1 + 11]) << 0x18))
    let c2da_fresh8 : uint = float_bits_to_uint(c2da_fresh7)
    c2da_mem[var_1 + 24] = uint8(c2da_fresh8)
    c2da_mem[var_1 + 25] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[var_1 + 26] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[var_1 + 27] = uint8(c2da_fresh8 >> 0x18)
    if ((uint(c2da_mem[var_1 + 20]) | uint(c2da_mem[var_1 + 21]) << 0x8 | uint(c2da_mem[var_1 + 22]) << 0x10 | uint(c2da_mem[var_1 + 23]) << 0x18) != 0x0 && changed != 0x0) {
        if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) != 0u) {
            SV_BroadcastPrintf(706919, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[var_1]) | uint(c2da_mem[var_1 + 1]) << 0x8 | uint(c2da_mem[var_1 + 2]) << 0x10 | uint(c2da_mem[var_1 + 3]) << 0x18))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[var_1 + 8]) | uint(c2da_mem[var_1 + 9]) << 0x8 | uint(c2da_mem[var_1 + 10]) << 0x10 | uint(c2da_mem[var_1 + 11]) << 0x18)))])
        }
    }
    return
}
[export, sideeffects]
def Cvar_SetValue(var var_name_1 : int; var value_0 : float) {
    let c2da_saved_sp : int = c2da_lin_sp
    Cvar_SetValue_c2da_frame(var_name_1, value_0, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Cvar_VariableValue(var var_name_2 : int) : float {
    var var_2 : int = Cvar_FindVar(var_name_2)
    if (var_2 == 0) {
        return 0.0
    }
    return Q_atof(int(uint(c2da_mem[var_2 + 8]) | uint(c2da_mem[var_2 + 9]) << 0x8 | uint(c2da_mem[var_2 + 10]) << 0x10 | uint(c2da_mem[var_2 + 11]) << 0x18))
}
[export, sideeffects]
def Cvar_VariableString(var var_name_3 : int) : int {
    var var_3 : int = Cvar_FindVar(var_name_3)
    if (var_3 == 0) {
        return cvar_null_string
    }
    return int(uint(c2da_mem[var_3 + 8]) | uint(c2da_mem[var_3 + 9]) << 0x8 | uint(c2da_mem[var_3 + 10]) << 0x10 | uint(c2da_mem[var_3 + 11]) << 0x18)
}
var cvar_null_string : int = 706944

[export, sideeffects]
def Cvar_CompleteVariable(var partial : int) : int {
    var cvar : int
    var len : int = Q_strlen(partial)
    if (len == 0) {
        return 0
    }
    cvar = cvar_vars
    while (cvar != 0) {
        if (Q_strncmp(partial, int(uint(c2da_mem[cvar]) | uint(c2da_mem[cvar + 1]) << 0x8 | uint(c2da_mem[cvar + 2]) << 0x10 | uint(c2da_mem[cvar + 3]) << 0x18), len) == 0) {
            return int(uint(c2da_mem[cvar]) | uint(c2da_mem[cvar + 1]) << 0x8 | uint(c2da_mem[cvar + 2]) << 0x10 | uint(c2da_mem[cvar + 3]) << 0x18)
        }
        cvar = int(uint(c2da_mem[cvar + 32]) | uint(c2da_mem[cvar + 33]) << 0x8 | uint(c2da_mem[cvar + 34]) << 0x10 | uint(c2da_mem[cvar + 35]) << 0x18)
    }
    return 0
}
[export, sideeffects]
def Cvar_Command() : uint {
    var v : int = Cvar_FindVar(Cmd_Argv(0))
    if (v == 0) {
        return 0u
    }
    if (Cmd_Argc() == 1) {
        Con_Printf(706945, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[v]) | uint(c2da_mem[v + 1]) << 0x8 | uint(c2da_mem[v + 2]) << 0x10 | uint(c2da_mem[v + 3]) << 0x18))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[v + 8]) | uint(c2da_mem[v + 9]) << 0x8 | uint(c2da_mem[v + 10]) << 0x10 | uint(c2da_mem[v + 11]) << 0x18)))])
        return 1u
    }
    Cvar_Set(int(uint(c2da_mem[v]) | uint(c2da_mem[v + 1]) << 0x8 | uint(c2da_mem[v + 2]) << 0x10 | uint(c2da_mem[v + 3]) << 0x18), Cmd_Argv(1))
    return 1u
}
[export, sideeffects]
def Cvar_WriteVariables(var f : int) {
    var var_4 : int = cvar_vars
    while (var_4 != 0) {
        if ((uint(c2da_mem[var_4 + 16]) | uint(c2da_mem[var_4 + 17]) << 0x8 | uint(c2da_mem[var_4 + 18]) << 0x10 | uint(c2da_mem[var_4 + 19]) << 0x18) != 0u) {
            c2da_lin_printf(uint64(f), 706959, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[var_4]) | uint(c2da_mem[var_4 + 1]) << 0x8 | uint(c2da_mem[var_4 + 2]) << 0x10 | uint(c2da_mem[var_4 + 3]) << 0x18))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[var_4 + 8]) | uint(c2da_mem[var_4 + 9]) << 0x8 | uint(c2da_mem[var_4 + 10]) << 0x10 | uint(c2da_mem[var_4 + 11]) << 0x18)))])
        }
        var_4 = int(uint(c2da_mem[var_4 + 32]) | uint(c2da_mem[var_4 + 33]) << 0x8 | uint(c2da_mem[var_4 + 34]) << 0x10 | uint(c2da_mem[var_4 + 35]) << 0x18)
    }
    return
}
[sideeffects]
def private Cvar_SetValue_c2da_frame(var var_name_1 : int; var value_0 : float; c2da_fp : int) {
    c2da_lin_snprintf(c2da_fp, 2147483647ul, 706941, [C2daVaArg(tag = 2, i64 = 0, f64 = double(value_0), raw = 0x0)])
    Cvar_Set(var_name_1, c2da_fp)
    return
}

// This unit's static data, at heap offset 706800.
let private c2da_lin_static_cvar_seg = fixed_array<int>(706800, 167)
let private c2da_lin_static_cvar = fixed_array<uint64>(0x65722074276e6143ul, 0x7620726574736967ul, 0x20656c6261697261ul, 0x726c6c61202c7325ul, 0x6665642079646165ul, 0x7643000a64656e69ul, 0x73696765525f7261ul, 0x6169726156726574ul, 0x207325203a656c62ul, 0x6d6f632061207369ul, 0x7643000a646e616dul, 0x203a7465535f7261ul, 0x656c626169726176ul, 0x20746f6e20732520ul, 0x22000a646e756f66ul, 0x6e61686320227325ul, 0x22206f7420646567ul, 0x6625000a227325ul, 0x7369202273252200ul, 0x25000a2273252220ul, 0xa227325222073ul)

[init]
def private c2da_lin_init_static_cvar() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_cvar_seg[s * 2]
        for (k in range(c2da_lin_static_cvar_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_cvar[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
