var private GetEdictFieldValue__rep : int = 0

var progs : int = default<int>

var pr_functions : int = default<int>

var pr_strings : int = default<int>

var pr_globaldefs : int = default<int>

var pr_fielddefs : int = default<int>

var pr_statements : int = default<int>

var pr_global_struct : int = default<int>

var pr_globals : int = default<int>

var pr_edict_size : int = default<int>

[export, sideeffects]
def PR_Init() {
    Cmd_AddCommand(729970, 198)
    Cmd_AddCommand(729976, 199)
    Cmd_AddCommand(729983, 200)
    Cmd_AddCommand(729994, 201)
    Cvar_RegisterVariable(388848)
    Cvar_RegisterVariable(388896)
    Cvar_RegisterVariable(388944)
    Cvar_RegisterVariable(388992)
    Cvar_RegisterVariable(389040)
    Cvar_RegisterVariable(389088)
    Cvar_RegisterVariable(389136)
    Cvar_RegisterVariable(389184)
    Cvar_RegisterVariable(389232)
    Cvar_RegisterVariable(389280)
    Cvar_RegisterVariable(389328)
    return
}
[export, sideeffects]
def ED_Count() {
    var i : int
    var ent : int
    var active : int
    var models : int
    var solid : int
    var step : int = 0
    solid = step
    models = solid
    active = models
    i = 0
    while (i < int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        ent = EDICT_NUM(i)
        if ((uint(c2da_mem[ent]) | uint(c2da_mem[ent + 1]) << 0x8 | uint(c2da_mem[ent + 2]) << 0x10 | uint(c2da_mem[ent + 3]) << 0x18) != 0u) {
            i++
            continue
        }
        active++
        if (uint_bits_to_float(uint(c2da_mem[ent + 144]) | uint(c2da_mem[ent + 145]) << 0x8 | uint(c2da_mem[ent + 146]) << 0x10 | uint(c2da_mem[ent + 147]) << 0x18) != 0.0) {
            solid++
        }
        if (int(uint(c2da_mem[ent + 224]) | uint(c2da_mem[ent + 225]) << 0x8 | uint(c2da_mem[ent + 226]) << 0x10 | uint(c2da_mem[ent + 227]) << 0x18) != 0) {
            models++
        }
        if (uint_bits_to_float(uint(c2da_mem[ent + 140]) | uint(c2da_mem[ent + 141]) << 0x8 | uint(c2da_mem[ent + 142]) << 0x10 | uint(c2da_mem[ent + 143]) << 0x18) == 4.0) {
            step++
        }
        i++
    }
    Con_Printf(730002, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    Con_Printf(730018, [C2daVaArg(tag = 1, i64 = int64(active), f64 = 0.0lf, raw = 0x0)])
    Con_Printf(730034, [C2daVaArg(tag = 1, i64 = int64(models), f64 = 0.0lf, raw = 0x0)])
    Con_Printf(730050, [C2daVaArg(tag = 1, i64 = int64(solid), f64 = 0.0lf, raw = 0x0)])
    Con_Printf(730066, [C2daVaArg(tag = 1, i64 = int64(step), f64 = 0.0lf, raw = 0x0)])
    return
}
[export, sideeffects]
def EDICT_NUM(var n : int) : int {
    if (n < 0 || n >= int(uint(c2da_mem[232692]) | uint(c2da_mem[232693]) << 0x8 | uint(c2da_mem[232694]) << 0x10 | uint(c2da_mem[232695]) << 0x18)) {
        Sys_Error(730082, [C2daVaArg(tag = 1, i64 = int64(n), f64 = 0.0lf, raw = 0x0)])
    }
    return int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + n * pr_edict_size
}
[export, sideeffects]
def ED_PrintEdicts() {
    var i_0 : int
    Con_Printf(730107, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    i_0 = 0
    while (i_0 < int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        ED_PrintNum(i_0)
        i_0++
    }
    return
}
[export, sideeffects]
def ED_PrintNum(var ent_0 : int) {
    ED_Print(EDICT_NUM(ent_0))
    return
}
[export, sideeffects]
def ED_Print(var ed : int) {
    var l : int
    var d : int
    var v : int
    var i_1 : int
    var j : int
    var name : int
    var type_0 : int
    if ((uint(c2da_mem[ed]) | uint(c2da_mem[ed + 1]) << 0x8 | uint(c2da_mem[ed + 2]) << 0x10 | uint(c2da_mem[ed + 3]) << 0x18) != 0u) {
        Con_Printf(730120, [])
        return
    }
    Con_Printf(730126, [C2daVaArg(tag = 1, i64 = int64(NUM_FOR_EDICT(ed)), f64 = 0.0lf, raw = 0x0)])
    i_1 = 1
    while (i_1 < int(uint(c2da_mem[progs + 28]) | uint(c2da_mem[progs + 29]) << 0x8 | uint(c2da_mem[progs + 30]) << 0x10 | uint(c2da_mem[progs + 31]) << 0x18)) {
        d = pr_fielddefs + i_1 * 8
        name = pr_strings + int(uint(c2da_mem[d + 4]) | uint(c2da_mem[d + 5]) << 0x8 | uint(c2da_mem[d + 6]) << 0x10 | uint(c2da_mem[d + 7]) << 0x18)
        let c2da_fresh0 : int = name + int(c2da_lin_strlen(name) - 2ul)
        if (int(int8(c2da_mem[c2da_fresh0])) == 95) {
            i_1++
            continue
        }
        v = ed + 108 + int(uint16(uint(c2da_mem[d + 2]) | uint(c2da_mem[d + 3]) << 0x8)) * 4
        type_0 = int(uint16(uint(c2da_mem[d]) | uint(c2da_mem[d + 1]) << 0x8)) & ~(1 << 15)
        j = 0
        while (j < type_size[type_0]) {
            if (int(uint(c2da_mem[v + j * 4]) | uint(c2da_mem[v + j * 4 + 1]) << 0x8 | uint(c2da_mem[v + j * 4 + 2]) << 0x10 | uint(c2da_mem[v + j * 4 + 3]) << 0x18) != 0) {
                break
            }
            j++
        }
        if (j == type_size[type_0]) {
            i_1++
            continue
        }
        Con_Printf(730138, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(name))])
        l = int(c2da_lin_strlen(name))
        while (true) {
            let c2da_postinc : int = l
            l++
            if (c2da_postinc >= 15) {
                break
            }
            Con_Printf(730141, [])
        }
        Con_Printf(730143, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(PR_ValueString(uint(uint16(uint(c2da_mem[d]) | uint(c2da_mem[d + 1]) << 0x8)), v)))])
        i_1++
    }
    return
}
[export, sideeffects]
def PR_ValueString(var type_1 : uint; var val : int) : int {
    var c2da_fresh1 : uint
    var def_0 : int
    var f : int
    type_1 &= uint(~(1 << 15))
    c2da_fresh1 = type_1
    if (c2da_fresh1 == 0x1u) {
        c2da_lin_snprintf(728960, 2147483647ul, 730138, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[val]) | uint(c2da_mem[val + 1]) << 0x8 | uint(c2da_mem[val + 2]) << 0x10 | uint(c2da_mem[val + 3]) << 0x18)))])
    } elif (c2da_fresh1 == 0x4u) {
        c2da_lin_snprintf(728960, 2147483647ul, 730147, [C2daVaArg(tag = 1, i64 = int64(NUM_FOR_EDICT(int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[val]) | uint(c2da_mem[val + 1]) << 0x8 | uint(c2da_mem[val + 2]) << 0x10 | uint(c2da_mem[val + 3]) << 0x18))), f64 = 0.0lf, raw = 0x0)])
    } elif (c2da_fresh1 == 0x6u) {
        f = pr_functions + int(uint(c2da_mem[val]) | uint(c2da_mem[val + 1]) << 0x8 | uint(c2da_mem[val + 2]) << 0x10 | uint(c2da_mem[val + 3]) << 0x18) * 36
        c2da_lin_snprintf(728960, 2147483647ul, 730157, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[f + 16]) | uint(c2da_mem[f + 17]) << 0x8 | uint(c2da_mem[f + 18]) << 0x10 | uint(c2da_mem[f + 19]) << 0x18)))])
    } elif (c2da_fresh1 == 0x5u) {
        def_0 = ED_FieldAtOfs(int(uint(c2da_mem[val]) | uint(c2da_mem[val + 1]) << 0x8 | uint(c2da_mem[val + 2]) << 0x10 | uint(c2da_mem[val + 3]) << 0x18))
        c2da_lin_snprintf(728960, 2147483647ul, 730162, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[def_0 + 4]) | uint(c2da_mem[def_0 + 5]) << 0x8 | uint(c2da_mem[def_0 + 6]) << 0x10 | uint(c2da_mem[def_0 + 7]) << 0x18)))])
    } elif (c2da_fresh1 == 0x0u) {
        c2da_lin_snprintf(728960, 2147483647ul, 730166, [])
    } elif (c2da_fresh1 == 0x2u) {
        c2da_lin_snprintf(728960, 2147483647ul, 730171, [C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[val]) | uint(c2da_mem[val + 1]) << 0x8 | uint(c2da_mem[val + 2]) << 0x10 | uint(c2da_mem[val + 3]) << 0x18)), raw = 0x0)])
    } elif (c2da_fresh1 == 0x3u) {
        c2da_lin_snprintf(728960, 2147483647ul, 730177, [C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[val + 0 * 4]) | uint(c2da_mem[val + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[val + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[val + 0 * 4 + 3]) << 0x18)), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[val + 1 * 4]) | uint(c2da_mem[val + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[val + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[val + 1 * 4 + 3]) << 0x18)), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[val + 2 * 4]) | uint(c2da_mem[val + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[val + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[val + 2 * 4 + 3]) << 0x18)), raw = 0x0)])
    } elif (c2da_fresh1 == 0x7u) {
        c2da_lin_snprintf(728960, 2147483647ul, 730197, [])
    } else {
        c2da_lin_snprintf(728960, 2147483647ul, 730205, [C2daVaArg(tag = 1, i64 = int64(type_1), f64 = 0.0lf, raw = 0x0)])
    }
    return 728960
}
[export, sideeffects]
def ED_FieldAtOfs(var ofs : int) : int {
    var def_1 : int
    var i_2 : int = 0
    while (i_2 < int(uint(c2da_mem[progs + 28]) | uint(c2da_mem[progs + 29]) << 0x8 | uint(c2da_mem[progs + 30]) << 0x10 | uint(c2da_mem[progs + 31]) << 0x18)) {
        def_1 = pr_fielddefs + i_2 * 8
        if (int(uint16(uint(c2da_mem[def_1 + 2]) | uint(c2da_mem[def_1 + 3]) << 0x8)) == ofs) {
            return def_1
        }
        i_2++
    }
    return 0
}
[export, sideeffects]
def NUM_FOR_EDICT(var e : int) : int {
    var b : int = e - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
    b /= pr_edict_size
    if (b < 0 || b >= int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        Sys_Error(730217, [])
    }
    return b
}
var type_size : int[8] = fixed_array<int>(1, int(4ul / 4ul), 1, 3, 1, 1, int(4ul / 4ul), int(8ul / 4ul))

[export, sideeffects]
def ED_PrintEdict_f() {
    var i_3 : int = Q_atoi(Cmd_Argv(1))
    if (i_3 >= int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        Con_Printf(730244, [])
        return
    }
    ED_PrintNum(i_3)
    return
}
[export, sideeffects]
def PR_LoadProgs() {
    var i_4 : int = 0
    while (i_4 < 2) {
        let c2da_fresh2 : int8 = int8(0)
        c2da_mem[729472 + i_4 * 72 + 8 + 0] = uint8(c2da_fresh2)
        i_4++
    }
    CRC_Init(389376)
    progs = COM_LoadHunkFile(730262)
    if (progs == 0) {
        Sys_Error(730272, [])
    }
    Con_DPrintf(730310, [C2daVaArg(tag = 1, i64 = int64(com_filesize / 1024), f64 = 0.0lf, raw = 0x0)])
    i_4 = 0
    while (i_4 < com_filesize) {
        CRC_ProcessByte(389376, c2da_mem[progs + i_4])
        i_4++
    }
    i_4 = 0
    while (uint64(i_4) < 60ul / 4ul) {
        let c2da_fresh3 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[progs + i_4 * 4]) | uint(c2da_mem[progs + i_4 * 4 + 1]) << 0x8 | uint(c2da_mem[progs + i_4 * 4 + 2]) << 0x10 | uint(c2da_mem[progs + i_4 * 4 + 3]) << 0x18))
        let c2da_fresh4 : uint = uint(c2da_fresh3)
        c2da_mem[progs + i_4 * 4] = uint8(c2da_fresh4)
        c2da_mem[progs + i_4 * 4 + 1] = uint8(c2da_fresh4 >> 0x8)
        c2da_mem[progs + i_4 * 4 + 2] = uint8(c2da_fresh4 >> 0x10)
        c2da_mem[progs + i_4 * 4 + 3] = uint8(c2da_fresh4 >> 0x18)
        i_4++
    }
    if (int(uint(c2da_mem[progs]) | uint(c2da_mem[progs + 1]) << 0x8 | uint(c2da_mem[progs + 2]) << 0x10 | uint(c2da_mem[progs + 3]) << 0x18) != 6) {
        Sys_Error(730332, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[progs]) | uint(c2da_mem[progs + 1]) << 0x8 | uint(c2da_mem[progs + 2]) << 0x10 | uint(c2da_mem[progs + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = 6l, f64 = 0.0lf, raw = 0x0)])
    }
    if (int(uint(c2da_mem[progs + 4]) | uint(c2da_mem[progs + 5]) << 0x8 | uint(c2da_mem[progs + 6]) << 0x10 | uint(c2da_mem[progs + 7]) << 0x18) != 5927) {
        Sys_Error(730385, [])
    }
    pr_functions = progs + int(uint(c2da_mem[progs + 32]) | uint(c2da_mem[progs + 33]) << 0x8 | uint(c2da_mem[progs + 34]) << 0x10 | uint(c2da_mem[progs + 35]) << 0x18)
    pr_strings = progs + int(uint(c2da_mem[progs + 40]) | uint(c2da_mem[progs + 41]) << 0x8 | uint(c2da_mem[progs + 42]) << 0x10 | uint(c2da_mem[progs + 43]) << 0x18)
    pr_globaldefs = progs + int(uint(c2da_mem[progs + 16]) | uint(c2da_mem[progs + 17]) << 0x8 | uint(c2da_mem[progs + 18]) << 0x10 | uint(c2da_mem[progs + 19]) << 0x18)
    pr_fielddefs = progs + int(uint(c2da_mem[progs + 24]) | uint(c2da_mem[progs + 25]) << 0x8 | uint(c2da_mem[progs + 26]) << 0x10 | uint(c2da_mem[progs + 27]) << 0x18)
    pr_statements = progs + int(uint(c2da_mem[progs + 8]) | uint(c2da_mem[progs + 9]) << 0x8 | uint(c2da_mem[progs + 10]) << 0x10 | uint(c2da_mem[progs + 11]) << 0x18)
    pr_global_struct = progs + int(uint(c2da_mem[progs + 48]) | uint(c2da_mem[progs + 49]) << 0x8 | uint(c2da_mem[progs + 50]) << 0x10 | uint(c2da_mem[progs + 51]) << 0x18)
    pr_globals = int(pr_global_struct)  // nolint:PERF020
    pr_edict_size = int(uint64(int(uint(c2da_mem[progs + 56]) | uint(c2da_mem[progs + 57]) << 0x8 | uint(c2da_mem[progs + 58]) << 0x10 | uint(c2da_mem[progs + 59]) << 0x18) * 4) + 528ul - 420ul)
    i_4 = 0
    while (i_4 < int(uint(c2da_mem[progs + 12]) | uint(c2da_mem[progs + 13]) << 0x8 | uint(c2da_mem[progs + 14]) << 0x10 | uint(c2da_mem[progs + 15]) << 0x18)) {
        let c2da_fresh5 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(uint16(uint(c2da_mem[pr_statements + i_4 * 8]) | uint(c2da_mem[pr_statements + i_4 * 8 + 1]) << 0x8))))
        let c2da_fresh6 : uint = uint(c2da_fresh5)
        c2da_mem[pr_statements + i_4 * 8] = uint8(c2da_fresh6)
        c2da_mem[pr_statements + i_4 * 8 + 1] = uint8(c2da_fresh6 >> 0x8)
        let c2da_fresh7 : int16 = invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[pr_statements + i_4 * 8 + 2]) | uint(c2da_mem[pr_statements + i_4 * 8 + 3]) << 0x8))
        let c2da_fresh8 : uint = uint(c2da_fresh7)
        c2da_mem[pr_statements + i_4 * 8 + 2] = uint8(c2da_fresh8)
        c2da_mem[pr_statements + i_4 * 8 + 3] = uint8(c2da_fresh8 >> 0x8)
        let c2da_fresh9 : int16 = invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[pr_statements + i_4 * 8 + 4]) | uint(c2da_mem[pr_statements + i_4 * 8 + 5]) << 0x8))
        let c2da_fresh10 : uint = uint(c2da_fresh9)
        c2da_mem[pr_statements + i_4 * 8 + 4] = uint8(c2da_fresh10)
        c2da_mem[pr_statements + i_4 * 8 + 5] = uint8(c2da_fresh10 >> 0x8)
        let c2da_fresh11 : int16 = invoke(c2da_fn_table3[LittleShort], int16(uint(c2da_mem[pr_statements + i_4 * 8 + 6]) | uint(c2da_mem[pr_statements + i_4 * 8 + 7]) << 0x8))
        let c2da_fresh12 : uint = uint(c2da_fresh11)
        c2da_mem[pr_statements + i_4 * 8 + 6] = uint8(c2da_fresh12)
        c2da_mem[pr_statements + i_4 * 8 + 7] = uint8(c2da_fresh12 >> 0x8)
        i_4++
    }
    i_4 = 0
    while (i_4 < int(uint(c2da_mem[progs + 36]) | uint(c2da_mem[progs + 37]) << 0x8 | uint(c2da_mem[progs + 38]) << 0x10 | uint(c2da_mem[progs + 39]) << 0x18)) {
        let c2da_fresh13 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pr_functions + i_4 * 36]) | uint(c2da_mem[pr_functions + i_4 * 36 + 1]) << 0x8 | uint(c2da_mem[pr_functions + i_4 * 36 + 2]) << 0x10 | uint(c2da_mem[pr_functions + i_4 * 36 + 3]) << 0x18))
        let c2da_fresh14 : uint = uint(c2da_fresh13)
        c2da_mem[pr_functions + i_4 * 36] = uint8(c2da_fresh14)
        c2da_mem[pr_functions + i_4 * 36 + 1] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[pr_functions + i_4 * 36 + 2] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[pr_functions + i_4 * 36 + 3] = uint8(c2da_fresh14 >> 0x18)
        let c2da_fresh15 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pr_functions + i_4 * 36 + 4]) | uint(c2da_mem[pr_functions + i_4 * 36 + 5]) << 0x8 | uint(c2da_mem[pr_functions + i_4 * 36 + 6]) << 0x10 | uint(c2da_mem[pr_functions + i_4 * 36 + 7]) << 0x18))
        let c2da_fresh16 : uint = uint(c2da_fresh15)
        c2da_mem[pr_functions + i_4 * 36 + 4] = uint8(c2da_fresh16)
        c2da_mem[pr_functions + i_4 * 36 + 5] = uint8(c2da_fresh16 >> 0x8)
        c2da_mem[pr_functions + i_4 * 36 + 6] = uint8(c2da_fresh16 >> 0x10)
        c2da_mem[pr_functions + i_4 * 36 + 7] = uint8(c2da_fresh16 >> 0x18)
        let c2da_fresh17 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pr_functions + i_4 * 36 + 16]) | uint(c2da_mem[pr_functions + i_4 * 36 + 17]) << 0x8 | uint(c2da_mem[pr_functions + i_4 * 36 + 18]) << 0x10 | uint(c2da_mem[pr_functions + i_4 * 36 + 19]) << 0x18))
        let c2da_fresh18 : uint = uint(c2da_fresh17)
        c2da_mem[pr_functions + i_4 * 36 + 16] = uint8(c2da_fresh18)
        c2da_mem[pr_functions + i_4 * 36 + 17] = uint8(c2da_fresh18 >> 0x8)
        c2da_mem[pr_functions + i_4 * 36 + 18] = uint8(c2da_fresh18 >> 0x10)
        c2da_mem[pr_functions + i_4 * 36 + 19] = uint8(c2da_fresh18 >> 0x18)
        let c2da_fresh19 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pr_functions + i_4 * 36 + 20]) | uint(c2da_mem[pr_functions + i_4 * 36 + 21]) << 0x8 | uint(c2da_mem[pr_functions + i_4 * 36 + 22]) << 0x10 | uint(c2da_mem[pr_functions + i_4 * 36 + 23]) << 0x18))
        let c2da_fresh20 : uint = uint(c2da_fresh19)
        c2da_mem[pr_functions + i_4 * 36 + 20] = uint8(c2da_fresh20)
        c2da_mem[pr_functions + i_4 * 36 + 21] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[pr_functions + i_4 * 36 + 22] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[pr_functions + i_4 * 36 + 23] = uint8(c2da_fresh20 >> 0x18)
        let c2da_fresh21 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pr_functions + i_4 * 36 + 24]) | uint(c2da_mem[pr_functions + i_4 * 36 + 25]) << 0x8 | uint(c2da_mem[pr_functions + i_4 * 36 + 26]) << 0x10 | uint(c2da_mem[pr_functions + i_4 * 36 + 27]) << 0x18))
        let c2da_fresh22 : uint = uint(c2da_fresh21)
        c2da_mem[pr_functions + i_4 * 36 + 24] = uint8(c2da_fresh22)
        c2da_mem[pr_functions + i_4 * 36 + 25] = uint8(c2da_fresh22 >> 0x8)
        c2da_mem[pr_functions + i_4 * 36 + 26] = uint8(c2da_fresh22 >> 0x10)
        c2da_mem[pr_functions + i_4 * 36 + 27] = uint8(c2da_fresh22 >> 0x18)
        let c2da_fresh23 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pr_functions + i_4 * 36 + 8]) | uint(c2da_mem[pr_functions + i_4 * 36 + 9]) << 0x8 | uint(c2da_mem[pr_functions + i_4 * 36 + 10]) << 0x10 | uint(c2da_mem[pr_functions + i_4 * 36 + 11]) << 0x18))
        let c2da_fresh24 : uint = uint(c2da_fresh23)
        c2da_mem[pr_functions + i_4 * 36 + 8] = uint8(c2da_fresh24)
        c2da_mem[pr_functions + i_4 * 36 + 9] = uint8(c2da_fresh24 >> 0x8)
        c2da_mem[pr_functions + i_4 * 36 + 10] = uint8(c2da_fresh24 >> 0x10)
        c2da_mem[pr_functions + i_4 * 36 + 11] = uint8(c2da_fresh24 >> 0x18)
        i_4++
    }
    i_4 = 0
    while (i_4 < int(uint(c2da_mem[progs + 20]) | uint(c2da_mem[progs + 21]) << 0x8 | uint(c2da_mem[progs + 22]) << 0x10 | uint(c2da_mem[progs + 23]) << 0x18)) {
        let c2da_fresh25 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(uint16(uint(c2da_mem[pr_globaldefs + i_4 * 8]) | uint(c2da_mem[pr_globaldefs + i_4 * 8 + 1]) << 0x8))))
        let c2da_fresh26 : uint = uint(c2da_fresh25)
        c2da_mem[pr_globaldefs + i_4 * 8] = uint8(c2da_fresh26)
        c2da_mem[pr_globaldefs + i_4 * 8 + 1] = uint8(c2da_fresh26 >> 0x8)
        let c2da_fresh27 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(uint16(uint(c2da_mem[pr_globaldefs + i_4 * 8 + 2]) | uint(c2da_mem[pr_globaldefs + i_4 * 8 + 3]) << 0x8))))
        let c2da_fresh28 : uint = uint(c2da_fresh27)
        c2da_mem[pr_globaldefs + i_4 * 8 + 2] = uint8(c2da_fresh28)
        c2da_mem[pr_globaldefs + i_4 * 8 + 3] = uint8(c2da_fresh28 >> 0x8)
        let c2da_fresh29 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pr_globaldefs + i_4 * 8 + 4]) | uint(c2da_mem[pr_globaldefs + i_4 * 8 + 5]) << 0x8 | uint(c2da_mem[pr_globaldefs + i_4 * 8 + 6]) << 0x10 | uint(c2da_mem[pr_globaldefs + i_4 * 8 + 7]) << 0x18))
        let c2da_fresh30 : uint = uint(c2da_fresh29)
        c2da_mem[pr_globaldefs + i_4 * 8 + 4] = uint8(c2da_fresh30)
        c2da_mem[pr_globaldefs + i_4 * 8 + 5] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[pr_globaldefs + i_4 * 8 + 6] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[pr_globaldefs + i_4 * 8 + 7] = uint8(c2da_fresh30 >> 0x18)
        i_4++
    }
    i_4 = 0
    while (i_4 < int(uint(c2da_mem[progs + 28]) | uint(c2da_mem[progs + 29]) << 0x8 | uint(c2da_mem[progs + 30]) << 0x10 | uint(c2da_mem[progs + 31]) << 0x18)) {
        let c2da_fresh31 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(uint16(uint(c2da_mem[pr_fielddefs + i_4 * 8]) | uint(c2da_mem[pr_fielddefs + i_4 * 8 + 1]) << 0x8))))
        let c2da_fresh32 : uint = uint(c2da_fresh31)
        c2da_mem[pr_fielddefs + i_4 * 8] = uint8(c2da_fresh32)
        c2da_mem[pr_fielddefs + i_4 * 8 + 1] = uint8(c2da_fresh32 >> 0x8)
        if ((int(uint16(uint(c2da_mem[pr_fielddefs + i_4 * 8]) | uint(c2da_mem[pr_fielddefs + i_4 * 8 + 1]) << 0x8)) & 1 << 15) != 0) {
            Sys_Error(730453, [])
        }
        let c2da_fresh33 : uint16 = uint16(invoke(c2da_fn_table3[LittleShort], int16(uint16(uint(c2da_mem[pr_fielddefs + i_4 * 8 + 2]) | uint(c2da_mem[pr_fielddefs + i_4 * 8 + 3]) << 0x8))))
        let c2da_fresh34 : uint = uint(c2da_fresh33)
        c2da_mem[pr_fielddefs + i_4 * 8 + 2] = uint8(c2da_fresh34)
        c2da_mem[pr_fielddefs + i_4 * 8 + 3] = uint8(c2da_fresh34 >> 0x8)
        let c2da_fresh35 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pr_fielddefs + i_4 * 8 + 4]) | uint(c2da_mem[pr_fielddefs + i_4 * 8 + 5]) << 0x8 | uint(c2da_mem[pr_fielddefs + i_4 * 8 + 6]) << 0x10 | uint(c2da_mem[pr_fielddefs + i_4 * 8 + 7]) << 0x18))
        let c2da_fresh36 : uint = uint(c2da_fresh35)
        c2da_mem[pr_fielddefs + i_4 * 8 + 4] = uint8(c2da_fresh36)
        c2da_mem[pr_fielddefs + i_4 * 8 + 5] = uint8(c2da_fresh36 >> 0x8)
        c2da_mem[pr_fielddefs + i_4 * 8 + 6] = uint8(c2da_fresh36 >> 0x10)
        c2da_mem[pr_fielddefs + i_4 * 8 + 7] = uint8(c2da_fresh36 >> 0x18)
        i_4++
    }
    i_4 = 0
    while (i_4 < int(uint(c2da_mem[progs + 52]) | uint(c2da_mem[progs + 53]) << 0x8 | uint(c2da_mem[progs + 54]) << 0x10 | uint(c2da_mem[progs + 55]) << 0x18)) {
        let c2da_fresh37 : int = invoke(c2da_fn_table2[LittleLong], int(uint(c2da_mem[pr_globals + i_4 * 4]) | uint(c2da_mem[pr_globals + i_4 * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + i_4 * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + i_4 * 4 + 3]) << 0x18))
        let c2da_fresh38 : uint = uint(c2da_fresh37)
        c2da_mem[pr_globals + i_4 * 4] = uint8(c2da_fresh38)
        c2da_mem[pr_globals + i_4 * 4 + 1] = uint8(c2da_fresh38 >> 0x8)
        c2da_mem[pr_globals + i_4 * 4 + 2] = uint8(c2da_fresh38 >> 0x10)
        c2da_mem[pr_globals + i_4 * 4 + 3] = uint8(c2da_fresh38 >> 0x18)
        i_4++
    }
    return
}
[export, sideeffects]
def ED_Alloc() : int {
    var i_5 : int
    var e_0 : int
    i_5 = svs.maxclients + 1
    while (i_5 < int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)) {
        e_0 = EDICT_NUM(i_5)
        if ((uint(c2da_mem[e_0]) | uint(c2da_mem[e_0 + 1]) << 0x8 | uint(c2da_mem[e_0 + 2]) << 0x10 | uint(c2da_mem[e_0 + 3]) << 0x18) != 0x0 && (uint_bits_to_float(uint(c2da_mem[e_0 + 104]) | uint(c2da_mem[e_0 + 105]) << 0x8 | uint(c2da_mem[e_0 + 106]) << 0x10 | uint(c2da_mem[e_0 + 107]) << 0x18) < 2.0 || uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20) - double(uint_bits_to_float(uint(c2da_mem[e_0 + 104]) | uint(c2da_mem[e_0 + 105]) << 0x8 | uint(c2da_mem[e_0 + 106]) << 0x10 | uint(c2da_mem[e_0 + 107]) << 0x18)) > 0.5lf)) {
            ED_ClearEdict(e_0)
            return e_0
        }
        i_5++
    }
    if (i_5 == 600) {
        Sys_Error(730505, [])
    }
    let c2da_fresh39 : int = int(uint(c2da_mem[232688]) | uint(c2da_mem[232689]) << 0x8 | uint(c2da_mem[232690]) << 0x10 | uint(c2da_mem[232691]) << 0x18)
    let c2da_fresh40 : int = c2da_fresh39 + 1
    let c2da_fresh41 : uint = uint(c2da_fresh40)
    c2da_mem[232688] = uint8(c2da_fresh41)
    c2da_mem[232689] = uint8(c2da_fresh41 >> 0x8)
    c2da_mem[232690] = uint8(c2da_fresh41 >> 0x10)
    c2da_mem[232691] = uint8(c2da_fresh41 >> 0x18)
    e_0 = EDICT_NUM(i_5)
    ED_ClearEdict(e_0)
    return e_0
}
[export, sideeffects]
def ED_ClearEdict(var e_1 : int) {
    c2da_lin_memset(e_1 + 108, 0, uint64(int(uint(c2da_mem[progs + 56]) | uint(c2da_mem[progs + 57]) << 0x8 | uint(c2da_mem[progs + 58]) << 0x10 | uint(c2da_mem[progs + 59]) << 0x18) * 4))
    let c2da_fresh42 : uint = 0u
    let c2da_fresh43 : uint = c2da_fresh42
    c2da_mem[e_1] = uint8(c2da_fresh43)
    c2da_mem[e_1 + 1] = uint8(c2da_fresh43 >> 0x8)
    c2da_mem[e_1 + 2] = uint8(c2da_fresh43 >> 0x10)
    c2da_mem[e_1 + 3] = uint8(c2da_fresh43 >> 0x18)
    return
}
[export, sideeffects]
def ED_Free(var ed_0 : int) {
    SV_UnlinkEdict(ed_0)
    let c2da_fresh44 : uint = 1u
    let c2da_fresh45 : uint = c2da_fresh44
    c2da_mem[ed_0] = uint8(c2da_fresh45)
    c2da_mem[ed_0 + 1] = uint8(c2da_fresh45 >> 0x8)
    c2da_mem[ed_0 + 2] = uint8(c2da_fresh45 >> 0x10)
    c2da_mem[ed_0 + 3] = uint8(c2da_fresh45 >> 0x18)
    let c2da_fresh46 : int = 0
    let c2da_fresh47 : uint = uint(c2da_fresh46)
    c2da_mem[ed_0 + 224] = uint8(c2da_fresh47)
    c2da_mem[ed_0 + 225] = uint8(c2da_fresh47 >> 0x8)
    c2da_mem[ed_0 + 226] = uint8(c2da_fresh47 >> 0x10)
    c2da_mem[ed_0 + 227] = uint8(c2da_fresh47 >> 0x18)
    let c2da_fresh48 : float = 0.0
    let c2da_fresh49 : uint = float_bits_to_uint(c2da_fresh48)
    c2da_mem[ed_0 + 344] = uint8(c2da_fresh49)
    c2da_mem[ed_0 + 345] = uint8(c2da_fresh49 >> 0x8)
    c2da_mem[ed_0 + 346] = uint8(c2da_fresh49 >> 0x10)
    c2da_mem[ed_0 + 347] = uint8(c2da_fresh49 >> 0x18)
    let c2da_fresh50 : float = 0.0
    let c2da_fresh51 : uint = float_bits_to_uint(c2da_fresh50)
    c2da_mem[ed_0 + 108] = uint8(c2da_fresh51)
    c2da_mem[ed_0 + 109] = uint8(c2da_fresh51 >> 0x8)
    c2da_mem[ed_0 + 110] = uint8(c2da_fresh51 >> 0x10)
    c2da_mem[ed_0 + 111] = uint8(c2da_fresh51 >> 0x18)
    let c2da_fresh52 : float = 0.0
    let c2da_fresh53 : uint = float_bits_to_uint(c2da_fresh52)
    c2da_mem[ed_0 + 416] = uint8(c2da_fresh53)
    c2da_mem[ed_0 + 417] = uint8(c2da_fresh53 >> 0x8)
    c2da_mem[ed_0 + 418] = uint8(c2da_fresh53 >> 0x10)
    c2da_mem[ed_0 + 419] = uint8(c2da_fresh53 >> 0x18)
    let c2da_fresh54 : float = 0.0
    let c2da_fresh55 : uint = float_bits_to_uint(c2da_fresh54)
    c2da_mem[ed_0 + 232] = uint8(c2da_fresh55)
    c2da_mem[ed_0 + 233] = uint8(c2da_fresh55 >> 0x8)
    c2da_mem[ed_0 + 234] = uint8(c2da_fresh55 >> 0x10)
    c2da_mem[ed_0 + 235] = uint8(c2da_fresh55 >> 0x18)
    let c2da_fresh56 : float = 0.0
    let c2da_fresh57 : uint = float_bits_to_uint(c2da_fresh56)
    c2da_mem[ed_0 + 228] = uint8(c2da_fresh57)
    c2da_mem[ed_0 + 229] = uint8(c2da_fresh57 >> 0x8)
    c2da_mem[ed_0 + 230] = uint8(c2da_fresh57 >> 0x10)
    c2da_mem[ed_0 + 231] = uint8(c2da_fresh57 >> 0x18)
    let c2da_fresh58 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh59 : uint = float_bits_to_uint(c2da_fresh58)
    c2da_mem[ed_0 + 148 + 0 * 4] = uint8(c2da_fresh59)
    c2da_mem[ed_0 + 148 + 0 * 4 + 1] = uint8(c2da_fresh59 >> 0x8)
    c2da_mem[ed_0 + 148 + 0 * 4 + 2] = uint8(c2da_fresh59 >> 0x10)
    c2da_mem[ed_0 + 148 + 0 * 4 + 3] = uint8(c2da_fresh59 >> 0x18)
    let c2da_fresh60 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh61 : uint = float_bits_to_uint(c2da_fresh60)
    c2da_mem[ed_0 + 148 + 1 * 4] = uint8(c2da_fresh61)
    c2da_mem[ed_0 + 148 + 1 * 4 + 1] = uint8(c2da_fresh61 >> 0x8)
    c2da_mem[ed_0 + 148 + 1 * 4 + 2] = uint8(c2da_fresh61 >> 0x10)
    c2da_mem[ed_0 + 148 + 1 * 4 + 3] = uint8(c2da_fresh61 >> 0x18)
    let c2da_fresh62 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh63 : uint = float_bits_to_uint(c2da_fresh62)
    c2da_mem[ed_0 + 148 + 2 * 4] = uint8(c2da_fresh63)
    c2da_mem[ed_0 + 148 + 2 * 4 + 1] = uint8(c2da_fresh63 >> 0x8)
    c2da_mem[ed_0 + 148 + 2 * 4 + 2] = uint8(c2da_fresh63 >> 0x10)
    c2da_mem[ed_0 + 148 + 2 * 4 + 3] = uint8(c2da_fresh63 >> 0x18)
    let c2da_fresh64 : float = uint_bits_to_float(uint(c2da_mem[194432 + 0 * 4]) | uint(c2da_mem[194432 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 0 * 4 + 3]) << 0x18)
    let c2da_fresh65 : uint = float_bits_to_uint(c2da_fresh64)
    c2da_mem[ed_0 + 184 + 0 * 4] = uint8(c2da_fresh65)
    c2da_mem[ed_0 + 184 + 0 * 4 + 1] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[ed_0 + 184 + 0 * 4 + 2] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[ed_0 + 184 + 0 * 4 + 3] = uint8(c2da_fresh65 >> 0x18)
    let c2da_fresh66 : float = uint_bits_to_float(uint(c2da_mem[194432 + 1 * 4]) | uint(c2da_mem[194432 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 1 * 4 + 3]) << 0x18)
    let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
    c2da_mem[ed_0 + 184 + 1 * 4] = uint8(c2da_fresh67)
    c2da_mem[ed_0 + 184 + 1 * 4 + 1] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[ed_0 + 184 + 1 * 4 + 2] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[ed_0 + 184 + 1 * 4 + 3] = uint8(c2da_fresh67 >> 0x18)
    let c2da_fresh68 : float = uint_bits_to_float(uint(c2da_mem[194432 + 2 * 4]) | uint(c2da_mem[194432 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[194432 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[194432 + 2 * 4 + 3]) << 0x18)
    let c2da_fresh69 : uint = float_bits_to_uint(c2da_fresh68)
    c2da_mem[ed_0 + 184 + 2 * 4] = uint8(c2da_fresh69)
    c2da_mem[ed_0 + 184 + 2 * 4 + 1] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[ed_0 + 184 + 2 * 4 + 2] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[ed_0 + 184 + 2 * 4 + 3] = uint8(c2da_fresh69 >> 0x18)
    let c2da_fresh70 : float = -1.0
    let c2da_fresh71 : uint = float_bits_to_uint(c2da_fresh70)
    c2da_mem[ed_0 + 292] = uint8(c2da_fresh71)
    c2da_mem[ed_0 + 293] = uint8(c2da_fresh71 >> 0x8)
    c2da_mem[ed_0 + 294] = uint8(c2da_fresh71 >> 0x10)
    c2da_mem[ed_0 + 295] = uint8(c2da_fresh71 >> 0x18)
    let c2da_fresh72 : float = 0.0
    let c2da_fresh73 : uint = float_bits_to_uint(c2da_fresh72)
    c2da_mem[ed_0 + 144] = uint8(c2da_fresh73)
    c2da_mem[ed_0 + 145] = uint8(c2da_fresh73 >> 0x8)
    c2da_mem[ed_0 + 146] = uint8(c2da_fresh73 >> 0x10)
    c2da_mem[ed_0 + 147] = uint8(c2da_fresh73 >> 0x18)
    let c2da_fresh74 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20))
    let c2da_fresh75 : uint = float_bits_to_uint(c2da_fresh74)
    c2da_mem[ed_0 + 104] = uint8(c2da_fresh75)
    c2da_mem[ed_0 + 105] = uint8(c2da_fresh75 >> 0x8)
    c2da_mem[ed_0 + 106] = uint8(c2da_fresh75 >> 0x10)
    c2da_mem[ed_0 + 107] = uint8(c2da_fresh75 >> 0x18)
    return
}
[export, sideeffects]
def ED_NewString(var string_0 : int) : int {
    var new_0 : int
    var new_p : int
    var i_6 : int
    var l_0 : int = int(c2da_lin_strlen(string_0) + 1ul)
    new_0 = Hunk_Alloc(l_0)
    new_p = new_0
    i_6 = 0
    while (i_6 < l_0) {
        if (int(int8(c2da_mem[string_0 + i_6])) == 92 && i_6 < l_0 - 1) {
            i_6++
            if (int(int8(c2da_mem[string_0 + i_6])) == 110) {
                let c2da_fresh76 : int = new_p
                new_p++
                let c2da_fresh77 : int8 = int8(10)
                c2da_mem[c2da_fresh76] = uint8(c2da_fresh77)
            } else {
                let c2da_fresh78 : int = new_p
                new_p++
                let c2da_fresh79 : int8 = int8(92)
                c2da_mem[c2da_fresh78] = uint8(c2da_fresh79)
            }
        } else {
            let c2da_fresh80 : int = new_p
            new_p++
            let c2da_fresh81 : int8 = int8(c2da_mem[string_0 + i_6])
            c2da_mem[c2da_fresh80] = uint8(c2da_fresh81)
        }
        i_6++
    }
    return new_0
}
[export, sideeffects]
def ED_Write(var f_0 : int; var ed_1 : int) {
    var d_0 : int
    var v_0 : int
    var i_7 : int
    var j_0 : int
    var name_0 : int
    var type_2 : int
    c2da_lin_printf(uint64(f_0), 730530, [])
    if ((uint(c2da_mem[ed_1]) | uint(c2da_mem[ed_1 + 1]) << 0x8 | uint(c2da_mem[ed_1 + 2]) << 0x10 | uint(c2da_mem[ed_1 + 3]) << 0x18) != 0u) {
        c2da_lin_printf(uint64(f_0), 730533, [])
        return
    }
    i_7 = 1
    while (i_7 < int(uint(c2da_mem[progs + 28]) | uint(c2da_mem[progs + 29]) << 0x8 | uint(c2da_mem[progs + 30]) << 0x10 | uint(c2da_mem[progs + 31]) << 0x18)) {
        d_0 = pr_fielddefs + i_7 * 8
        name_0 = pr_strings + int(uint(c2da_mem[d_0 + 4]) | uint(c2da_mem[d_0 + 5]) << 0x8 | uint(c2da_mem[d_0 + 6]) << 0x10 | uint(c2da_mem[d_0 + 7]) << 0x18)
        let c2da_fresh82 : int = name_0 + int(c2da_lin_strlen(name_0) - 2ul)
        if (int(int8(c2da_mem[c2da_fresh82])) == 95) {
            i_7++
            continue
        }
        v_0 = ed_1 + 108 + int(uint16(uint(c2da_mem[d_0 + 2]) | uint(c2da_mem[d_0 + 3]) << 0x8)) * 4
        type_2 = int(uint16(uint(c2da_mem[d_0]) | uint(c2da_mem[d_0 + 1]) << 0x8)) & ~(1 << 15)
        j_0 = 0
        while (j_0 < type_size[type_2]) {
            if (int(uint(c2da_mem[v_0 + j_0 * 4]) | uint(c2da_mem[v_0 + j_0 * 4 + 1]) << 0x8 | uint(c2da_mem[v_0 + j_0 * 4 + 2]) << 0x10 | uint(c2da_mem[v_0 + j_0 * 4 + 3]) << 0x18) != 0) {
                break
            }
            j_0++
        }
        if (j_0 == type_size[type_2]) {
            i_7++
            continue
        }
        c2da_lin_printf(uint64(f_0), 730536, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(name_0))])
        c2da_lin_printf(uint64(f_0), 730542, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(PR_UglyValueString(uint(uint16(uint(c2da_mem[d_0]) | uint(c2da_mem[d_0 + 1]) << 0x8)), v_0)))])
        i_7++
    }
    c2da_lin_printf(uint64(f_0), 730533, [])
    return
}
[export, sideeffects]
def PR_UglyValueString(var type_3 : uint; var val_0 : int) : int {
    var c2da_fresh83 : uint
    var def_2 : int
    var f_1 : int
    type_3 &= uint(~(1 << 15))
    c2da_fresh83 = type_3
    if (c2da_fresh83 == 0x1u) {
        c2da_lin_snprintf(729216, 2147483647ul, 730138, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[val_0]) | uint(c2da_mem[val_0 + 1]) << 0x8 | uint(c2da_mem[val_0 + 2]) << 0x10 | uint(c2da_mem[val_0 + 3]) << 0x18)))])
    } elif (c2da_fresh83 == 0x4u) {
        c2da_lin_snprintf(729216, 2147483647ul, 730548, [C2daVaArg(tag = 1, i64 = int64(NUM_FOR_EDICT(int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[val_0]) | uint(c2da_mem[val_0 + 1]) << 0x8 | uint(c2da_mem[val_0 + 2]) << 0x10 | uint(c2da_mem[val_0 + 3]) << 0x18))), f64 = 0.0lf, raw = 0x0)])
    } elif (c2da_fresh83 == 0x6u) {
        f_1 = pr_functions + int(uint(c2da_mem[val_0]) | uint(c2da_mem[val_0 + 1]) << 0x8 | uint(c2da_mem[val_0 + 2]) << 0x10 | uint(c2da_mem[val_0 + 3]) << 0x18) * 36
        c2da_lin_snprintf(729216, 2147483647ul, 730138, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[f_1 + 16]) | uint(c2da_mem[f_1 + 17]) << 0x8 | uint(c2da_mem[f_1 + 18]) << 0x10 | uint(c2da_mem[f_1 + 19]) << 0x18)))])
    } elif (c2da_fresh83 == 0x5u) {
        def_2 = ED_FieldAtOfs(int(uint(c2da_mem[val_0]) | uint(c2da_mem[val_0 + 1]) << 0x8 | uint(c2da_mem[val_0 + 2]) << 0x10 | uint(c2da_mem[val_0 + 3]) << 0x18))
        c2da_lin_snprintf(729216, 2147483647ul, 730138, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[def_2 + 4]) | uint(c2da_mem[def_2 + 5]) << 0x8 | uint(c2da_mem[def_2 + 6]) << 0x10 | uint(c2da_mem[def_2 + 7]) << 0x18)))])
    } elif (c2da_fresh83 == 0x0u) {
        c2da_lin_snprintf(729216, 2147483647ul, 730166, [])
    } elif (c2da_fresh83 == 0x2u) {
        c2da_lin_snprintf(729216, 2147483647ul, 730551, [C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[val_0]) | uint(c2da_mem[val_0 + 1]) << 0x8 | uint(c2da_mem[val_0 + 2]) << 0x10 | uint(c2da_mem[val_0 + 3]) << 0x18)), raw = 0x0)])
    } elif (c2da_fresh83 == 0x3u) {
        c2da_lin_snprintf(729216, 2147483647ul, 730554, [C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[val_0 + 0 * 4]) | uint(c2da_mem[val_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[val_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[val_0 + 0 * 4 + 3]) << 0x18)), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[val_0 + 1 * 4]) | uint(c2da_mem[val_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[val_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[val_0 + 1 * 4 + 3]) << 0x18)), raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(uint_bits_to_float(uint(c2da_mem[val_0 + 2 * 4]) | uint(c2da_mem[val_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[val_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[val_0 + 2 * 4 + 3]) << 0x18)), raw = 0x0)])
    } else {
        c2da_lin_snprintf(729216, 2147483647ul, 730205, [C2daVaArg(tag = 1, i64 = int64(type_3), f64 = 0.0lf, raw = 0x0)])
    }
    return 729216
}
[export, sideeffects]
def ED_ParseEdict(var data : int; var ent_1 : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = ED_ParseEdict_c2da_frame(data, ent_1, c2da_lin_enter(288))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def ED_ParseEpair(var base : int; var key_0 : int; var s : int) : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = ED_ParseEpair_c2da_frame(base, key_0, s, c2da_lin_enter(128))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def ED_FindFunction(var name_1 : int) : int {
    var func_0 : int
    var i_9 : int = 0
    while (i_9 < int(uint(c2da_mem[progs + 36]) | uint(c2da_mem[progs + 37]) << 0x8 | uint(c2da_mem[progs + 38]) << 0x10 | uint(c2da_mem[progs + 39]) << 0x18)) {
        func_0 = pr_functions + i_9 * 36
        if (c2da_lin_strcmp(pr_strings + int(uint(c2da_mem[func_0 + 16]) | uint(c2da_mem[func_0 + 17]) << 0x8 | uint(c2da_mem[func_0 + 18]) << 0x10 | uint(c2da_mem[func_0 + 19]) << 0x18), name_1) == 0) {
            return func_0
        }
        i_9++
    }
    return 0
}
[export, sideeffects]
def ED_FindField(var name_2 : int) : int {
    var def_4 : int
    var i_10 : int = 0
    while (i_10 < int(uint(c2da_mem[progs + 28]) | uint(c2da_mem[progs + 29]) << 0x8 | uint(c2da_mem[progs + 30]) << 0x10 | uint(c2da_mem[progs + 31]) << 0x18)) {
        def_4 = pr_fielddefs + i_10 * 8
        if (c2da_lin_strcmp(pr_strings + int(uint(c2da_mem[def_4 + 4]) | uint(c2da_mem[def_4 + 5]) << 0x8 | uint(c2da_mem[def_4 + 6]) << 0x10 | uint(c2da_mem[def_4 + 7]) << 0x18), name_2) == 0) {
            return def_4
        }
        i_10++
    }
    return 0
}
[export, sideeffects]
def ED_WriteGlobals(var f_2 : int) {
    var def_5 : int
    var i_11 : int
    var name_3 : int
    var type_4 : int
    c2da_lin_printf(uint64(f_2), 730530, [])
    i_11 = 0
    while (i_11 < int(uint(c2da_mem[progs + 20]) | uint(c2da_mem[progs + 21]) << 0x8 | uint(c2da_mem[progs + 22]) << 0x10 | uint(c2da_mem[progs + 23]) << 0x18)) {
        def_5 = pr_globaldefs + i_11 * 8
        type_4 = int(uint16(uint(c2da_mem[def_5]) | uint(c2da_mem[def_5 + 1]) << 0x8))
        if ((int(uint16(uint(c2da_mem[def_5]) | uint(c2da_mem[def_5 + 1]) << 0x8)) & 1 << 15) == 0) {
            i_11++
            continue
        }
        type_4 &= ~(1 << 15)
        if (type_4 != 1 && type_4 != 2 && type_4 != 4) {
            i_11++
            continue
        }
        name_3 = pr_strings + int(uint(c2da_mem[def_5 + 4]) | uint(c2da_mem[def_5 + 5]) << 0x8 | uint(c2da_mem[def_5 + 6]) << 0x10 | uint(c2da_mem[def_5 + 7]) << 0x18)
        c2da_lin_printf(uint64(f_2), 730536, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(name_3))])
        c2da_lin_printf(uint64(f_2), 730542, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(PR_UglyValueString(uint(type_4), pr_globals + int(uint16(uint(c2da_mem[def_5 + 2]) | uint(c2da_mem[def_5 + 3]) << 0x8)) * 4)))])
        i_11++
    }
    c2da_lin_printf(uint64(f_2), 730533, [])
    return
}
[export, sideeffects]
def ED_ParseGlobals(var data_0 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    ED_ParseGlobals_c2da_frame(data_0, c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def ED_FindGlobal(var name_4 : int) : int {
    var def_6 : int
    var i_12 : int = 0
    while (i_12 < int(uint(c2da_mem[progs + 20]) | uint(c2da_mem[progs + 21]) << 0x8 | uint(c2da_mem[progs + 22]) << 0x10 | uint(c2da_mem[progs + 23]) << 0x18)) {
        def_6 = pr_globaldefs + i_12 * 8
        if (c2da_lin_strcmp(pr_strings + int(uint(c2da_mem[def_6 + 4]) | uint(c2da_mem[def_6 + 5]) << 0x8 | uint(c2da_mem[def_6 + 6]) << 0x10 | uint(c2da_mem[def_6 + 7]) << 0x18), name_4) == 0) {
            return def_6
        }
        i_12++
    }
    return 0
}
[export, sideeffects]
def ED_LoadFromFile(var data_1 : int) {
    var ent_2 : int
    var inhibit : int
    var func_1 : int
    ent_2 = 0
    inhibit = 0
    let c2da_fresh102 : float = float(uint64_bits_to_double(uint64(uint(c2da_mem[225872]) | uint(c2da_mem[225873]) << 0x8 | uint(c2da_mem[225874]) << 0x10 | uint(c2da_mem[225875]) << 0x18) | uint64(uint(c2da_mem[225876]) | uint(c2da_mem[225877]) << 0x8 | uint(c2da_mem[225878]) << 0x10 | uint(c2da_mem[225879]) << 0x18) << 0x20))
    let c2da_fresh103 : uint = float_bits_to_uint(c2da_fresh102)
    c2da_mem[pr_global_struct + 124] = uint8(c2da_fresh103)
    c2da_mem[pr_global_struct + 125] = uint8(c2da_fresh103 >> 0x8)
    c2da_mem[pr_global_struct + 126] = uint8(c2da_fresh103 >> 0x10)
    c2da_mem[pr_global_struct + 127] = uint8(c2da_fresh103 >> 0x18)
    while (true) {
        data_1 = COM_Parse(data_1)
        if (data_1 == 0) {
            break
        }
        if (int(int8(c2da_mem[194480 + 0])) != 123) {
            Sys_Error(730828, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 194480ul)])
        }
        if (ent_2 == 0) {
            ent_2 = EDICT_NUM(0)
        } else {
            ent_2 = ED_Alloc()
        }
        data_1 = ED_ParseEdict(data_1, ent_2)
        if (uint_bits_to_float(uint(c2da_mem[243704]) | uint(c2da_mem[243705]) << 0x8 | uint(c2da_mem[243706]) << 0x10 | uint(c2da_mem[243707]) << 0x18) != 0.0) {
            if ((int(uint_bits_to_float(uint(c2da_mem[ent_2 + 464]) | uint(c2da_mem[ent_2 + 465]) << 0x8 | uint(c2da_mem[ent_2 + 466]) << 0x10 | uint(c2da_mem[ent_2 + 467]) << 0x18)) & 2048) != 0) {
                ED_Free(ent_2)
                inhibit++
                continue
            }
        } elif (current_skill == 0 && (int(uint_bits_to_float(uint(c2da_mem[ent_2 + 464]) | uint(c2da_mem[ent_2 + 465]) << 0x8 | uint(c2da_mem[ent_2 + 466]) << 0x10 | uint(c2da_mem[ent_2 + 467]) << 0x18)) & 256) != 0 || current_skill == 1 && (int(uint_bits_to_float(uint(c2da_mem[ent_2 + 464]) | uint(c2da_mem[ent_2 + 465]) << 0x8 | uint(c2da_mem[ent_2 + 466]) << 0x10 | uint(c2da_mem[ent_2 + 467]) << 0x18)) & 512) != 0 || current_skill >= 2 && (int(uint_bits_to_float(uint(c2da_mem[ent_2 + 464]) | uint(c2da_mem[ent_2 + 465]) << 0x8 | uint(c2da_mem[ent_2 + 466]) << 0x10 | uint(c2da_mem[ent_2 + 467]) << 0x18)) & 1024) != 0) {
            ED_Free(ent_2)
            inhibit++
            continue
        }
        if (int(uint(c2da_mem[ent_2 + 220]) | uint(c2da_mem[ent_2 + 221]) << 0x8 | uint(c2da_mem[ent_2 + 222]) << 0x10 | uint(c2da_mem[ent_2 + 223]) << 0x18) == 0) {
            Con_Printf(730871, [])
            ED_Print(ent_2)
            ED_Free(ent_2)
            continue
        }
        func_1 = ED_FindFunction(pr_strings + int(uint(c2da_mem[ent_2 + 220]) | uint(c2da_mem[ent_2 + 221]) << 0x8 | uint(c2da_mem[ent_2 + 222]) << 0x10 | uint(c2da_mem[ent_2 + 223]) << 0x18))
        if (func_1 == 0) {
            Con_Printf(730890, [])
            ED_Print(ent_2)
            ED_Free(ent_2)
            continue
        }
        let c2da_fresh104 : int = ent_2 - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh105 : uint = uint(c2da_fresh104)
        c2da_mem[pr_global_struct + 112] = uint8(c2da_fresh105)
        c2da_mem[pr_global_struct + 113] = uint8(c2da_fresh105 >> 0x8)
        c2da_mem[pr_global_struct + 114] = uint8(c2da_fresh105 >> 0x10)
        c2da_mem[pr_global_struct + 115] = uint8(c2da_fresh105 >> 0x18)
        PR_ExecuteProgram((func_1 - pr_functions) / 36)
    }
    Con_DPrintf(730914, [C2daVaArg(tag = 1, i64 = int64(inhibit), f64 = 0.0lf, raw = 0x0)])
    return
}
[export, sideeffects]
def GetEdictFieldValue(var ed_2 : int; var field : int) : int {
    var def_7 : int
    var i_13 : int
    def_7 = 0
    i_13 = 0
    label 0:
    if (i_13 < 2) {
        goto label 5
    }
    def_7 = ED_FindField(field)
    if (c2da_lin_strlen(field) < 64ul) {
        goto label 4
    }
    label 1:
    label 2:
    if (def_7 == 0) {
        goto label 3
    }
    return ed_2 + 108 + int(uint16(uint(c2da_mem[def_7 + 2]) | uint(c2da_mem[def_7 + 3]) << 0x8)) * 4
    label 3:
    return 0
    label 4:
    let c2da_fresh106 : uint = uint(def_7)
    c2da_mem[729472 + GetEdictFieldValue__rep * 72] = uint8(c2da_fresh106)
    c2da_mem[729472 + GetEdictFieldValue__rep * 72 + 1] = uint8(c2da_fresh106 >> 0x8)
    c2da_mem[729472 + GetEdictFieldValue__rep * 72 + 2] = uint8(c2da_fresh106 >> 0x10)
    c2da_mem[729472 + GetEdictFieldValue__rep * 72 + 3] = uint8(c2da_fresh106 >> 0x18)
    c2da_mem[729472 + GetEdictFieldValue__rep * 72 + 4] = 0u8
    c2da_mem[729472 + GetEdictFieldValue__rep * 72 + 5] = 0u8
    c2da_mem[729472 + GetEdictFieldValue__rep * 72 + 6] = 0u8
    c2da_mem[729472 + GetEdictFieldValue__rep * 72 + 7] = 0u8
    c2da_lin_strcpy(729472 + GetEdictFieldValue__rep * 72 + 8, field)
    GetEdictFieldValue__rep ^= 1
    goto label 1
    label 5:
    if (c2da_lin_strcmp(field, 729472 + i_13 * 72 + 8) == 0) {
        goto label 6
    }
    i_13++
    goto label 0
    label 6:
    def_7 = int(uint(c2da_mem[729472 + i_13 * 72]) | uint(c2da_mem[729472 + i_13 * 72 + 1]) << 0x8 | uint(c2da_mem[729472 + i_13 * 72 + 2]) << 0x10 | uint(c2da_mem[729472 + i_13 * 72 + 3]) << 0x18)
    goto label 2
    panic("unreachable: fell out of a translated control-flow graph")
}
[export, sideeffects]
def ED_GlobalAtOfs(var ofs_0 : int) : int {
    var def_8 : int
    var i_14 : int = 0
    while (i_14 < int(uint(c2da_mem[progs + 20]) | uint(c2da_mem[progs + 21]) << 0x8 | uint(c2da_mem[progs + 22]) << 0x10 | uint(c2da_mem[progs + 23]) << 0x18)) {
        def_8 = pr_globaldefs + i_14 * 8
        if (int(uint16(uint(c2da_mem[def_8 + 2]) | uint(c2da_mem[def_8 + 3]) << 0x8)) == ofs_0) {
            return def_8
        }
        i_14++
    }
    return 0
}
[export, sideeffects]
def PR_GlobalString(var ofs_1 : int) : int {
    var s_0 : int
    var i_15 : int
    var def_9 : int
    var val_1 : int = pr_globals + ofs_1 * 4
    def_9 = ED_GlobalAtOfs(ofs_1)
    if (def_9 == 0) {
        c2da_lin_snprintf(729616, 2147483647ul, 730937, [C2daVaArg(tag = 1, i64 = int64(ofs_1), f64 = 0.0lf, raw = 0x0)])
    } else {
        s_0 = PR_ValueString(uint(uint16(uint(c2da_mem[def_9]) | uint(c2da_mem[def_9 + 1]) << 0x8)), val_1)
        c2da_lin_snprintf(729616, 2147483647ul, 730945, [C2daVaArg(tag = 1, i64 = int64(ofs_1), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[def_9 + 4]) | uint(c2da_mem[def_9 + 5]) << 0x8 | uint(c2da_mem[def_9 + 6]) << 0x10 | uint(c2da_mem[def_9 + 7]) << 0x18))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(s_0))])
    }
    i_15 = int(c2da_lin_strlen(729616))
    for (c2da_i_15 in range(i_15, 20)) {
        c2da_lin_strcat(729616, 730141)
    }
    c2da_lin_strcat(729616, 730141)
    return 729616
}
[export, sideeffects]
def PR_GlobalStringNoContents(var ofs_2 : int) : int {
    var i_16 : int
    var def_10 : int = ED_GlobalAtOfs(ofs_2)
    if (def_10 == 0) {
        c2da_lin_snprintf(729744, 2147483647ul, 730937, [C2daVaArg(tag = 1, i64 = int64(ofs_2), f64 = 0.0lf, raw = 0x0)])
    } else {
        c2da_lin_snprintf(729744, 2147483647ul, 730954, [C2daVaArg(tag = 1, i64 = int64(ofs_2), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[def_10 + 4]) | uint(c2da_mem[def_10 + 5]) << 0x8 | uint(c2da_mem[def_10 + 6]) << 0x10 | uint(c2da_mem[def_10 + 7]) << 0x18)))])
    }
    i_16 = int(c2da_lin_strlen(729744))
    for (c2da_i_16 in range(i_16, 20)) {
        c2da_lin_strcat(729744, 730141)
    }
    c2da_lin_strcat(729744, 730141)
    return 729744
}
[sideeffects]
def private ED_ParseEdict_c2da_frame(var data : int; var ent_1 : int; c2da_fp : int) : int {
    var key : int
    var anglehack : uint
    var init_0 : uint
    var n_0 : int
    init_0 = 0u
    if (ent_1 != int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)) {
        c2da_lin_memset(ent_1 + 108, 0, uint64(int(uint(c2da_mem[progs + 56]) | uint(c2da_mem[progs + 57]) << 0x8 | uint(c2da_mem[progs + 58]) << 0x10 | uint(c2da_mem[progs + 59]) << 0x18) * 4))
    }
    while (true) {
        data = COM_Parse(data)
        if (int(int8(c2da_mem[194480 + 0])) == 125) {
            break
        }
        if (data == 0) {
            Sys_Error(730563, [])
        }
        if (c2da_lin_strcmp(194480, 730605) == 0) {
            c2da_lin_strcpy(194480, 730611)
            anglehack = 1u
        } else {
            anglehack = 0u
        }
        if (c2da_lin_strcmp(194480, 730618) == 0) {
            c2da_lin_strcpy(194480, 730624)
        }
        c2da_lin_strcpy(c2da_fp, 194480)
        n_0 = int(c2da_lin_strlen(c2da_fp))
        while (n_0 != 0 && int(int8(c2da_mem[c2da_fp + (n_0 - 1)])) == 32) {
            let c2da_fresh84 : int8 = int8(0)
            c2da_mem[c2da_fp + (n_0 - 1)] = uint8(c2da_fresh84)
            n_0--
        }
        data = COM_Parse(data)
        if (data == 0) {
            Sys_Error(730563, [])
        }
        if (int(int8(c2da_mem[194480 + 0])) == 125) {
            Sys_Error(730634, [])
        }
        init_0 = 1u
        if (int(int8(c2da_mem[c2da_fp + 0])) == 95) {
            continue
        }
        key = ED_FindField(c2da_fp)
        if (key == 0) {
            Con_Printf(730677, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
            continue
        }
        if (anglehack != 0u) {
            c2da_lin_strcpy(c2da_fp + 256, 194480)
            c2da_lin_snprintf(194480, 2147483647ul, 730698, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp + 256))])
        }
        if (ED_ParseEpair(ent_1 + 108, key, 194480) == 0u) {
            Host_Error(730705, [])
        }
    }
    if (init_0 == 0u) {
        let c2da_fresh85 : uint = 1u
        let c2da_fresh86 : uint = c2da_fresh85
        c2da_mem[ent_1] = uint8(c2da_fresh86)
        c2da_mem[ent_1 + 1] = uint8(c2da_fresh86 >> 0x8)
        c2da_mem[ent_1 + 2] = uint8(c2da_fresh86 >> 0x10)
        c2da_mem[ent_1 + 3] = uint8(c2da_fresh86 >> 0x18)
    }
    return data
}
[sideeffects]
def private ED_ParseEpair_c2da_frame(var base : int; var key_0 : int; var s : int; c2da_fp : int) : uint {
    var c2da_fresh87 : int
    var def_3 : int
    var v_1 : int
    var w : int
    var d_1 : int
    var func : int
    d_1 = base + int(uint16(uint(c2da_mem[key_0 + 2]) | uint(c2da_mem[key_0 + 3]) << 0x8)) * 4
    c2da_fresh87 = int(uint16(uint(c2da_mem[key_0]) | uint(c2da_mem[key_0 + 1]) << 0x8)) & ~(1 << 15)
    if (c2da_fresh87 == 1) {
        let c2da_fresh88 : int = ED_NewString(s) - pr_strings
        let c2da_fresh89 : uint = uint(c2da_fresh88)
        c2da_mem[d_1] = uint8(c2da_fresh89)
        c2da_mem[d_1 + 1] = uint8(c2da_fresh89 >> 0x8)
        c2da_mem[d_1 + 2] = uint8(c2da_fresh89 >> 0x10)
        c2da_mem[d_1 + 3] = uint8(c2da_fresh89 >> 0x18)
    } elif (c2da_fresh87 == 2) {
        let c2da_fresh90 : float = float(c2da_lin_atof(s))
        let c2da_fresh91 : uint = float_bits_to_uint(c2da_fresh90)
        c2da_mem[d_1] = uint8(c2da_fresh91)
        c2da_mem[d_1 + 1] = uint8(c2da_fresh91 >> 0x8)
        c2da_mem[d_1 + 2] = uint8(c2da_fresh91 >> 0x10)
        c2da_mem[d_1 + 3] = uint8(c2da_fresh91 >> 0x18)
    } elif (c2da_fresh87 == 3) {
        c2da_lin_strcpy(c2da_fp, s)
        v_1 = c2da_fp
        w = c2da_fp
        for (i_8 in range(0, 3)) {
            while (int(int8(c2da_mem[v_1])) != 0 && int(int8(c2da_mem[v_1])) != 32) {
                v_1++
            }
            let c2da_fresh92 : int8 = int8(0)
            c2da_mem[v_1] = uint8(c2da_fresh92)
            let c2da_fresh93 : float = float(c2da_lin_atof(w))
            let c2da_fresh94 : uint = float_bits_to_uint(c2da_fresh93)
            c2da_mem[d_1 + i_8 * 4] = uint8(c2da_fresh94)
            c2da_mem[d_1 + i_8 * 4 + 1] = uint8(c2da_fresh94 >> 0x8)
            c2da_mem[d_1 + i_8 * 4 + 2] = uint8(c2da_fresh94 >> 0x10)
            c2da_mem[d_1 + i_8 * 4 + 3] = uint8(c2da_fresh94 >> 0x18)
            v_1++
            w = v_1
        }
    } elif (c2da_fresh87 == 4) {
        let c2da_fresh95 : int = int(int64(EDICT_NUM(c2da_lin_atoi(s)) - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)))
        let c2da_fresh96 : uint = uint(c2da_fresh95)
        c2da_mem[d_1] = uint8(c2da_fresh96)
        c2da_mem[d_1 + 1] = uint8(c2da_fresh96 >> 0x8)
        c2da_mem[d_1 + 2] = uint8(c2da_fresh96 >> 0x10)
        c2da_mem[d_1 + 3] = uint8(c2da_fresh96 >> 0x18)
    } elif (c2da_fresh87 == 5) {
        def_3 = ED_FindField(s)
        if (def_3 == 0) {
            Con_Printf(730732, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(s))])
            return 0u
        }
        let c2da_fresh97 : int = pr_globals + int(uint16(uint(c2da_mem[def_3 + 2]) | uint(c2da_mem[def_3 + 3]) << 0x8)) * 4
        let c2da_fresh98 : int = int(uint(c2da_mem[c2da_fresh97]) | uint(c2da_mem[c2da_fresh97 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh97 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh97 + 3]) << 0x18)
        let c2da_fresh99 : uint = uint(c2da_fresh98)
        c2da_mem[d_1] = uint8(c2da_fresh99)
        c2da_mem[d_1 + 1] = uint8(c2da_fresh99 >> 0x8)
        c2da_mem[d_1 + 2] = uint8(c2da_fresh99 >> 0x10)
        c2da_mem[d_1 + 3] = uint8(c2da_fresh99 >> 0x18)
    } elif (c2da_fresh87 == 6) {
        func = ED_FindFunction(s)
        if (func == 0) {
            Con_Printf(730753, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(s))])
            return 0u
        }
        let c2da_fresh100 : int = (func - pr_functions) / 36
        let c2da_fresh101 : uint = uint(c2da_fresh100)
        c2da_mem[d_1] = uint8(c2da_fresh101)
        c2da_mem[d_1 + 1] = uint8(c2da_fresh101 >> 0x8)
        c2da_mem[d_1 + 2] = uint8(c2da_fresh101 >> 0x10)
        c2da_mem[d_1 + 3] = uint8(c2da_fresh101 >> 0x18)
    }
    return 1u
}
[sideeffects]
def private ED_ParseGlobals_c2da_frame(var data_0 : int; c2da_fp : int) {
    var key_1 : int
    while (true) {
        data_0 = COM_Parse(data_0)
        if (int(int8(c2da_mem[194480 + 0])) == 125) {
            break
        }
        if (data_0 == 0) {
            Sys_Error(730563, [])
        }
        c2da_lin_strcpy(c2da_fp, 194480)
        data_0 = COM_Parse(data_0)
        if (data_0 == 0) {
            Sys_Error(730563, [])
        }
        if (int(int8(c2da_mem[194480 + 0])) == 125) {
            Sys_Error(730634, [])
        }
        key_1 = ED_FindGlobal(c2da_fp)
        if (key_1 == 0) {
            Con_Printf(730777, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
            continue
        }
        if (ED_ParseEpair(pr_globals, key_1, 194480) == 0u) {
            Host_Error(730799, [])
        }
    }
    return
}

// This unit's static data, at heap offset 728960.
let private c2da_lin_static_pr_edict_seg = fixed_array<int>(729872, 1088)
let private c2da_lin_static_pr_edict = fixed_array<uint64>(0x6574736e6f6d6f6eul, 0x6d61670030007372ul, 0x7263730067666365ul, 0x6373003168637461ul, 0x7300326863746172ul, 0x33686374617263ul, 0x3468637461726373ul, 0x6167646576617300ul, 0x617300676663656dul, 0x7661730031646576ul, 0x6576617300326465ul, 0x6465766173003364ul, 0x74636964650034ul, 0x6500737463696465ul, 0x6e756f6374636964ul, 0x6c69666f72700074ul, 0x64655f6d756e0065ul, 0x6933253a73746369ul, 0x657669746361000aul, 0x6933253a20202020ul, 0x202077656976000aul, 0x6933253a20202020ul, 0x206863756f74000aul, 0x6933253a20202020ul, 0x202070657473000aul, 0x6933253a20202020ul, 0x5f5443494445000aul, 0x646162203a4d554eul, 0x207265626d756e20ul, 0x6e65206925006925ul, 0xa736569746974ul, 0x450a000a45455246ul, 0x3a69252054434944ul, 0x250020007325000aul, 0x7469746e65000a73ul, 0x2873250069252079ul, 0x6f760073252e0029ul, 0x66312e3525006469ul, 0x2066312e35252700ul, 0x35252066312e3525ul, 0x696f70002766312eul, 0x646162007265746eul, 0x6925206570797420ul, 0x524f465f4d554e00ul, 0x203a54434944455ful, 0x6e696f7020646162ul, 0x2064614200726574ul, 0x756e207463696465ul, 0x7270000a7265626dul, 0x7461642e73676ful, 0x5064616f4c5f5250ul, 0x6f63203a73676f72ul, 0x6c2074276e646c75ul, 0x676f72702064616ful, 0x7250007461642e73ul, 0x6f20736d6172676ful, 0x6925207970756363ul, 0x676f7270000a2e4bul, 0x6168207461642e73ul, 0x20676e6f72772073ul, 0x206e6f6973726576ul, 0x28207265626d756eul, 0x6c756f6873206925ul, 0x2969252065622064ul, 0x642e73676f727000ul, 0x6574737973207461ul, 0x682073726176206dul, 0x6e65656220657661ul, 0x65696669646f6d20ul, 0x64676f7270202c64ul, 0x736920682e736665ul, 0x20666f2074756f20ul, 0x5f52500065746164ul, 0x676f725064616f4cul, 0x69665f7270203a73ul, 0x5b73666564646c65ul, 0x20657079742e5d69ul, 0x41535f4645442026ul, 0x4c41424f4c474556ul, 0x6f6c6c415f444500ul, 0x7266206f6e203a63ul, 0x7463696465206565ul, 0xa7d000a7b0073ul, 0x2522002022732522ul, 0x25006925000a2273ul, 0x2066252066250066ul, 0x61505f4445006625ul, 0x7469746e45657372ul, 0x7720464f45203a79ul, 0x632074756f687469ul, 0x6220676e69736f6cul, 0x676e610065636172ul, 0x656c676e6100656cul, 0x746867696c0073ul, 0x656c5f746867696cul, 0x7261505f44450076ul, 0x797469746e456573ul, 0x6e69736f6c63203aul, 0x2065636172622067ul, 0x2074756f68746977ul, 0x7325270061746164ul, 0x746f6e2073692027ul, 0x646c656966206120ul, 0x302073252030000aul, 0x737261505f444500ul, 0x203a746369644565ul, 0x7265206573726170ul, 0x276e614300726f72ul, 0x6620646e69662074ul, 0xa732520646c6569ul, 0x662074276e614300ul, 0x636e756620646e69ul, 0xa7325206e6f6974ul, 0x7369202773252700ul, 0x67206120746f6e20ul, 0x45000a6c61626f6cul, 0x4765737261505f44ul, 0x203a736c61626f6cul, 0x7265206573726170ul, 0x4c5f444500726f72ul, 0x466d6f724664616ful, 0x756f66203a656c69ul, 0x687720732520646eul, 0x6365707865206e65ul, 0x4e007b20676e6974ul, 0x6e7373616c63206ful, 0x3a726f6620656d61ul, 0x617073206f4e000aul, 0x74636e7566206e77ul, 0x3a726f66206e6f69ul, 0x746e65206925000aul, 0x6e69207365697469ul, 0xa64657469626968ul, 0x293f3f3f28692500ul, 0x2529732528692500ul, 0x2973252869250073ul)

[init]
def private c2da_lin_init_static_pr_edict() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_pr_edict_seg[s * 2]
        for (k in range(c2da_lin_static_pr_edict_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_pr_edict[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_pr_edict_0 = fixed_array<uint8>(0x10, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1b, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_pr_edict_1 = fixed_array<uint8>(0x1d, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1b, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_pr_edict_2 = fixed_array<uint8>(0x25, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1b, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_pr_edict_3 = fixed_array<uint8>(0x2e, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1b, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_pr_edict_4 = fixed_array<uint8>(0x37, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1b, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_pr_edict_5 = fixed_array<uint8>(0x40, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1b, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_pr_edict_6 = fixed_array<uint8>(0x49, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1b, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_pr_edict_7 = fixed_array<uint8>(0x56, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1b, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_pr_edict_8 = fixed_array<uint8>(0x5d, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1b, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_pr_edict_9 = fixed_array<uint8>(0x64, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1b, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_pr_edict_10 = fixed_array<uint8>(0x6b, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1b, 0x23, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_pr_edict() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[388848 + i] = c2da_lin_extern_pr_edict_0[i]
    }
    for (i in range(40)) {
        c2da_mem[388896 + i] = c2da_lin_extern_pr_edict_1[i]
    }
    for (i in range(40)) {
        c2da_mem[388944 + i] = c2da_lin_extern_pr_edict_2[i]
    }
    for (i in range(40)) {
        c2da_mem[388992 + i] = c2da_lin_extern_pr_edict_3[i]
    }
    for (i in range(40)) {
        c2da_mem[389040 + i] = c2da_lin_extern_pr_edict_4[i]
    }
    for (i in range(40)) {
        c2da_mem[389088 + i] = c2da_lin_extern_pr_edict_5[i]
    }
    for (i in range(40)) {
        c2da_mem[389136 + i] = c2da_lin_extern_pr_edict_6[i]
    }
    for (i in range(40)) {
        c2da_mem[389184 + i] = c2da_lin_extern_pr_edict_7[i]
    }
    for (i in range(40)) {
        c2da_mem[389232 + i] = c2da_lin_extern_pr_edict_8[i]
    }
    for (i in range(40)) {
        c2da_mem[389280 + i] = c2da_lin_extern_pr_edict_9[i]
    }
    for (i in range(40)) {
        c2da_mem[389328 + i] = c2da_lin_extern_pr_edict_10[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_pr_edict() {
    if (length(c2da_fn_table0) < 201) {
        resize(c2da_fn_table0, 201)
    }
    c2da_fn_table0[200] = @@ED_Count
    c2da_fn_table0[199] = @@ED_PrintEdicts
    c2da_fn_table0[198] = @@ED_PrintEdict_f
}

[init]
def private c2da_lin_relink_init_pr_edict() {
    c2da_relink_pr_edict()
}
