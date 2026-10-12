var sb_lines : int = default<int>

[export, sideeffects]
def Sbar_Init() {
    var i : int = 0
    while (i < 10) {
        sb_nums[0][i] = Draw_PicFromWad(va(734640, [C2daVaArg(tag = 1, i64 = int64(i), f64 = 0.0lf, raw = 0x0)]))
        sb_nums[1][i] = Draw_PicFromWad(va(734647, [C2daVaArg(tag = 1, i64 = int64(i), f64 = 0.0lf, raw = 0x0)]))
        i++
    }
    sb_nums[0][10] = Draw_PicFromWad(734655)
    sb_nums[1][10] = Draw_PicFromWad(734665)
    sb_colon = Draw_PicFromWad(734676)
    sb_slash = Draw_PicFromWad(734686)
    sb_weapons[0][0] = Draw_PicFromWad(734696)
    sb_weapons[0][1] = Draw_PicFromWad(734708)
    sb_weapons[0][2] = Draw_PicFromWad(734721)
    sb_weapons[0][3] = Draw_PicFromWad(734733)
    sb_weapons[0][4] = Draw_PicFromWad(734746)
    sb_weapons[0][5] = Draw_PicFromWad(734758)
    sb_weapons[0][6] = Draw_PicFromWad(734771)
    sb_weapons[1][0] = Draw_PicFromWad(734783)
    sb_weapons[1][1] = Draw_PicFromWad(734796)
    sb_weapons[1][2] = Draw_PicFromWad(734810)
    sb_weapons[1][3] = Draw_PicFromWad(734823)
    sb_weapons[1][4] = Draw_PicFromWad(734837)
    sb_weapons[1][5] = Draw_PicFromWad(734850)
    sb_weapons[1][6] = Draw_PicFromWad(734864)
    i = 0
    while (i < 5) {
        sb_weapons[2 + i][0] = Draw_PicFromWad(va(734877, [C2daVaArg(tag = 1, i64 = int64(i + 1), f64 = 0.0lf, raw = 0x0)]))
        sb_weapons[2 + i][1] = Draw_PicFromWad(va(734892, [C2daVaArg(tag = 1, i64 = int64(i + 1), f64 = 0.0lf, raw = 0x0)]))
        sb_weapons[2 + i][2] = Draw_PicFromWad(va(734908, [C2daVaArg(tag = 1, i64 = int64(i + 1), f64 = 0.0lf, raw = 0x0)]))
        sb_weapons[2 + i][3] = Draw_PicFromWad(va(734923, [C2daVaArg(tag = 1, i64 = int64(i + 1), f64 = 0.0lf, raw = 0x0)]))
        sb_weapons[2 + i][4] = Draw_PicFromWad(va(734939, [C2daVaArg(tag = 1, i64 = int64(i + 1), f64 = 0.0lf, raw = 0x0)]))
        sb_weapons[2 + i][5] = Draw_PicFromWad(va(734954, [C2daVaArg(tag = 1, i64 = int64(i + 1), f64 = 0.0lf, raw = 0x0)]))
        sb_weapons[2 + i][6] = Draw_PicFromWad(va(734970, [C2daVaArg(tag = 1, i64 = int64(i + 1), f64 = 0.0lf, raw = 0x0)]))
        i++
    }
    sb_ammo[0] = Draw_PicFromWad(734985)
    sb_ammo[1] = Draw_PicFromWad(734995)
    sb_ammo[2] = Draw_PicFromWad(735004)
    sb_ammo[3] = Draw_PicFromWad(735014)
    sb_armor[0] = Draw_PicFromWad(735023)
    sb_armor[1] = Draw_PicFromWad(735033)
    sb_armor[2] = Draw_PicFromWad(735043)
    sb_items[0] = Draw_PicFromWad(735053)
    sb_items[1] = Draw_PicFromWad(735061)
    sb_items[2] = Draw_PicFromWad(735069)
    sb_items[3] = Draw_PicFromWad(735078)
    sb_items[4] = Draw_PicFromWad(735088)
    sb_items[5] = Draw_PicFromWad(735096)
    sb_sigil[0] = Draw_PicFromWad(735104)
    sb_sigil[1] = Draw_PicFromWad(735114)
    sb_sigil[2] = Draw_PicFromWad(735124)
    sb_sigil[3] = Draw_PicFromWad(735134)
    sb_faces[4][0] = Draw_PicFromWad(735144)
    sb_faces[4][1] = Draw_PicFromWad(735150)
    sb_faces[3][0] = Draw_PicFromWad(735158)
    sb_faces[3][1] = Draw_PicFromWad(735164)
    sb_faces[2][0] = Draw_PicFromWad(735172)
    sb_faces[2][1] = Draw_PicFromWad(735178)
    sb_faces[1][0] = Draw_PicFromWad(735186)
    sb_faces[1][1] = Draw_PicFromWad(735192)
    sb_faces[0][0] = Draw_PicFromWad(735200)
    sb_faces[0][1] = Draw_PicFromWad(735206)
    sb_face_invis = Draw_PicFromWad(735214)
    sb_face_invuln = Draw_PicFromWad(735225)
    sb_face_invis_invuln = Draw_PicFromWad(735237)
    sb_face_quad = Draw_PicFromWad(735247)
    Cmd_AddCommand(735257, 215)
    Cmd_AddCommand(735269, 216)
    sb_sbar = Draw_PicFromWad(735281)
    sb_ibar = Draw_PicFromWad(735286)
    sb_scorebar = Draw_PicFromWad(735291)
    if (uint(hipnotic) != 0u) {
        hsb_weapons[0][0] = Draw_PicFromWad(735300)
        hsb_weapons[0][1] = Draw_PicFromWad(735310)
        hsb_weapons[0][2] = Draw_PicFromWad(735322)
        hsb_weapons[0][3] = Draw_PicFromWad(735336)
        hsb_weapons[0][4] = Draw_PicFromWad(735350)
        hsb_weapons[1][0] = Draw_PicFromWad(735359)
        hsb_weapons[1][1] = Draw_PicFromWad(735370)
        hsb_weapons[1][2] = Draw_PicFromWad(735383)
        hsb_weapons[1][3] = Draw_PicFromWad(735398)
        hsb_weapons[1][4] = Draw_PicFromWad(735413)
        i = 0
        for (c2da_i in range(i, 5)) {
            hsb_weapons[2 + c2da_i][0] = Draw_PicFromWad(va(735423, [C2daVaArg(tag = 1, i64 = int64(c2da_i + 1), f64 = 0.0lf, raw = 0x0)]))
            hsb_weapons[2 + c2da_i][1] = Draw_PicFromWad(va(735436, [C2daVaArg(tag = 1, i64 = int64(c2da_i + 1), f64 = 0.0lf, raw = 0x0)]))
            hsb_weapons[2 + c2da_i][2] = Draw_PicFromWad(va(735451, [C2daVaArg(tag = 1, i64 = int64(c2da_i + 1), f64 = 0.0lf, raw = 0x0)]))
            hsb_weapons[2 + c2da_i][3] = Draw_PicFromWad(va(735468, [C2daVaArg(tag = 1, i64 = int64(c2da_i + 1), f64 = 0.0lf, raw = 0x0)]))
            hsb_weapons[2 + c2da_i][4] = Draw_PicFromWad(va(735485, [C2daVaArg(tag = 1, i64 = int64(c2da_i + 1), f64 = 0.0lf, raw = 0x0)]))
        }
        hsb_items[0] = Draw_PicFromWad(735497)
        hsb_items[1] = Draw_PicFromWad(735506)
    }
    if (uint(rogue) != 0u) {
        rsb_invbar[0] = Draw_PicFromWad(735515)
        rsb_invbar[1] = Draw_PicFromWad(735525)
        rsb_weapons[0] = Draw_PicFromWad(735535)
        rsb_weapons[1] = Draw_PicFromWad(735542)
        rsb_weapons[2] = Draw_PicFromWad(735554)
        rsb_weapons[3] = Draw_PicFromWad(735561)
        rsb_weapons[4] = Draw_PicFromWad(735573)
        rsb_items[0] = Draw_PicFromWad(735582)
        rsb_items[1] = Draw_PicFromWad(735592)
        rsb_teambord = Draw_PicFromWad(735601)
        rsb_ammo[0] = Draw_PicFromWad(735612)
        rsb_ammo[1] = Draw_PicFromWad(735623)
        rsb_ammo[2] = Draw_PicFromWad(735635)
    }
    return
}
var rsb_ammo : int[3]

var rsb_teambord : int = default<int>

var rsb_items : int[2]

var rsb_weapons : int[5]

var rsb_invbar : int[2]

var hsb_items : int[2]

var hsb_weapons : int[7][5]

var sb_scorebar : int = default<int>

var sb_ibar : int = default<int>

var sb_sbar : int = default<int>

[export, sideeffects]
def Sbar_DontShowScores() {
    sb_showscores = 0u
    sb_updates = 0
    return
}
var sb_updates : int = default<int>

var sb_showscores : uint = default<uint>

[export, sideeffects]
def Sbar_ShowScores() {
    if (sb_showscores != 0u) {
        return
    }
    sb_showscores = 1u
    sb_updates = 0
    return
}
var sb_face_quad : int = default<int>

var sb_face_invis_invuln : int = default<int>

var sb_face_invuln : int = default<int>

var sb_face_invis : int = default<int>

var sb_faces : int[7][2]

var sb_sigil : int[4]

var sb_items : int[32]

var sb_armor : int[3]

var sb_ammo : int[4]

var sb_weapons : int[7][8]

var sb_slash : int = default<int>

var sb_colon : int = default<int>

var sb_nums : int[2][11]

[export, sideeffects]
def Sbar_Changed() {
    sb_updates = 0
    return
}
[export, sideeffects]
def Sbar_Draw() {
    if (scr_con_current == float(vid.height)) {
        return
    }
    if (sb_updates >= vid.numpages) {
        return
    }
    scr_copyeverything = 1
    sb_updates++
    if (sb_lines != 0 && vid.width > 320u) {
        Draw_TileClear(0, int(vid.height - uint(sb_lines)), int(vid.width), sb_lines)
    }
    if (sb_lines > 24) {
        Sbar_DrawInventory()
        if (int(uint(c2da_mem[4948]) | uint(c2da_mem[4949]) << 0x8 | uint(c2da_mem[4950]) << 0x10 | uint(c2da_mem[4951]) << 0x18) != 1) {
            Sbar_DrawFrags()
        }
    }
    if (sb_showscores != 0x0 || int(uint(c2da_mem[236 + 0 * 4]) | uint(c2da_mem[236 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 0 * 4 + 3]) << 0x18) <= 0) {
        Sbar_DrawPic(0, 0, sb_scorebar)
        Sbar_DrawScoreboard()
        sb_updates = 0
    } elif (sb_lines != 0) {
        Sbar_DrawPic(0, 0, sb_sbar)
        if (uint(hipnotic) != 0u) {
            if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 131072) != 0) {
                Sbar_DrawPic(209, 3, sb_items[0])
            }
            if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 262144) != 0) {
                Sbar_DrawPic(209, 12, sb_items[1])
            }
        }
        if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 1048576) != 0) {
            Sbar_DrawNum(24, 0, 666, 3, 1)
            Sbar_DrawPic(0, 0, draw_disc)
        } elif (uint(rogue) != 0u) {
            Sbar_DrawNum(24, 0, int(uint(c2da_mem[236 + 4 * 4]) | uint(c2da_mem[236 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 4 * 4 + 3]) << 0x18), 3, int(uint(c2da_mem[236 + 4 * 4]) | uint(c2da_mem[236 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 4 * 4 + 3]) << 0x18) <= 25 ? 1 : 0)
            if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 33554432) != 0) {
                Sbar_DrawPic(0, 0, sb_armor[2])
            } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 16777216) != 0) {
                Sbar_DrawPic(0, 0, sb_armor[1])
            } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 8388608) != 0) {
                Sbar_DrawPic(0, 0, sb_armor[0])
            }
        } else {
            Sbar_DrawNum(24, 0, int(uint(c2da_mem[236 + 4 * 4]) | uint(c2da_mem[236 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 4 * 4 + 3]) << 0x18), 3, int(uint(c2da_mem[236 + 4 * 4]) | uint(c2da_mem[236 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 4 * 4 + 3]) << 0x18) <= 25 ? 1 : 0)
            if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 32768) != 0) {
                Sbar_DrawPic(0, 0, sb_armor[2])
            } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 16384) != 0) {
                Sbar_DrawPic(0, 0, sb_armor[1])
            } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 8192) != 0) {
                Sbar_DrawPic(0, 0, sb_armor[0])
            }
        }
        Sbar_DrawFace()
        Sbar_DrawNum(136, 0, int(uint(c2da_mem[236 + 0 * 4]) | uint(c2da_mem[236 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 0 * 4 + 3]) << 0x18), 3, int(uint(c2da_mem[236 + 0 * 4]) | uint(c2da_mem[236 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 0 * 4 + 3]) << 0x18) <= 25 ? 1 : 0)
        if (uint(rogue) != 0u) {
            if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 128) != 0) {
                Sbar_DrawPic(224, 0, sb_ammo[0])
            } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 256) != 0) {
                Sbar_DrawPic(224, 0, sb_ammo[1])
            } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 512) != 0) {
                Sbar_DrawPic(224, 0, sb_ammo[2])
            } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 1024) != 0) {
                Sbar_DrawPic(224, 0, sb_ammo[3])
            } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 67108864) != 0) {
                Sbar_DrawPic(224, 0, rsb_ammo[0])
            } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 134217728) != 0) {
                Sbar_DrawPic(224, 0, rsb_ammo[1])
            } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 268435456) != 0) {
                Sbar_DrawPic(224, 0, rsb_ammo[2])
            }
        } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 256) != 0) {
            Sbar_DrawPic(224, 0, sb_ammo[0])
        } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 512) != 0) {
            Sbar_DrawPic(224, 0, sb_ammo[1])
        } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 1024) != 0) {
            Sbar_DrawPic(224, 0, sb_ammo[2])
        } elif ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 2048) != 0) {
            Sbar_DrawPic(224, 0, sb_ammo[3])
        }
        Sbar_DrawNum(248, 0, int(uint(c2da_mem[236 + 3 * 4]) | uint(c2da_mem[236 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 3 * 4 + 3]) << 0x18), 3, int(uint(c2da_mem[236 + 3 * 4]) | uint(c2da_mem[236 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 3 * 4 + 3]) << 0x18) <= 10 ? 1 : 0)
    }
    if (vid.width > 320u) {
        if (int(uint(c2da_mem[4952]) | uint(c2da_mem[4953]) << 0x8 | uint(c2da_mem[4954]) << 0x10 | uint(c2da_mem[4955]) << 0x18) == 1) {
            Sbar_MiniDeathmatchOverlay()
        }
    }
    return
}
[export, sideeffects]
def Sbar_MiniDeathmatchOverlay() {
    let c2da_saved_sp : int = c2da_lin_sp
    Sbar_MiniDeathmatchOverlay_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Sbar_ColorForMap(var m : int) : int {
    return m < 128 ? m + 8 : m + 8
}
var fragsort : int[16]

var scoreboardlines : int = default<int>

[export, sideeffects]
def Sbar_SortFrags() {
    var i_1 : int
    var j : int
    var k_0 : int
    scoreboardlines = 0
    i_1 = 0
    while (i_1 < int(uint(c2da_mem[4948]) | uint(c2da_mem[4949]) << 0x8 | uint(c2da_mem[4950]) << 0x10 | uint(c2da_mem[4951]) << 0x18)) {
        let c2da_fresh0 : int = int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + i_1 * 16428 + 0
        if (int8(c2da_mem[c2da_fresh0]) != 0) {
            fragsort[scoreboardlines] = i_1
            scoreboardlines++
        }
        i_1++
    }
    i_1 = 0
    while (i_1 < scoreboardlines) {
        j = 0
        while (j < scoreboardlines - 1 - i_1) {
            let c2da_fresh1 : int = int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + fragsort[j] * 16428 + 36
            let c2da_fresh2 : int = int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + fragsort[j + 1] * 16428 + 36
            if (int(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh1 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh1 + 3]) << 0x18) < int(uint(c2da_mem[c2da_fresh2]) | uint(c2da_mem[c2da_fresh2 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh2 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh2 + 3]) << 0x18)) {
                k_0 = fragsort[j]
                fragsort[j] = int(fragsort[j + 1])  // nolint:PERF020
                fragsort[j + 1] = k_0
            }
            j++
        }
        i_1++
    }
    return
}
[export, sideeffects]
def Sbar_DrawNum(var x_0 : int; var y_0 : int; var num : int; var digits : int; var color : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    Sbar_DrawNum_c2da_frame(x_0, y_0, num, digits, color, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Sbar_DrawTransPic(var x_1 : int; var y_1 : int; var pic_0 : int) {
    if (int(uint(c2da_mem[4952]) | uint(c2da_mem[4953]) << 0x8 | uint(c2da_mem[4954]) << 0x10 | uint(c2da_mem[4955]) << 0x18) == 1) {
        Draw_TransPic(x_1, int(uint(y_1) + (vid.height - 24u)), pic_0)
    } else {
        Draw_TransPic(int(uint(x_1) + (vid.width - 320u >> 1u)), int(uint(y_1) + (vid.height - 24u)), pic_0)
    }
    return
}
[export, sideeffects]
def Sbar_itoa(var num_0 : int; var buf : int) : int {
    var str : int
    var pow10 : int
    var dig : int
    str = buf
    if (num_0 < 0) {
        let c2da_fresh3 : int = str
        str++
        let c2da_fresh4 : int8 = int8(45)
        c2da_mem[c2da_fresh3] = uint8(c2da_fresh4)
        num_0 = -num_0
    }
    pow10 = 10
    while (num_0 >= pow10) {
        pow10 *= 10
    }
    while (true) {
        pow10 /= 10
        dig = num_0 / pow10
        let c2da_fresh5 : int = str
        str++
        let c2da_fresh6 : int8 = int8(48 + dig)
        c2da_mem[c2da_fresh5] = uint8(c2da_fresh6)
        num_0 -= dig * pow10
        if (pow10 == 1) {
            break
        }
    }
    let c2da_fresh7 : int8 = int8(0)
    c2da_mem[str] = uint8(c2da_fresh7)
    return str - buf
}
[export, sideeffects]
def Sbar_DrawPic(var x_2 : int; var y_2 : int; var pic_1 : int) {
    if (int(uint(c2da_mem[4952]) | uint(c2da_mem[4953]) << 0x8 | uint(c2da_mem[4954]) << 0x10 | uint(c2da_mem[4955]) << 0x18) == 1) {
        Draw_Pic(x_2, int(uint(y_2) + (vid.height - 24u)), pic_1)
    } else {
        Draw_Pic(int(uint(x_2) + (vid.width - 320u >> 1u)), int(uint(y_2) + (vid.height - 24u)), pic_1)
    }
    return
}
[export, sideeffects]
def Sbar_DrawFace() {
    let c2da_saved_sp : int = c2da_lin_sp
    Sbar_DrawFace_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Sbar_DrawCharacter(var x_3 : int; var y_3 : int; var num_1 : int) {
    if (int(uint(c2da_mem[4952]) | uint(c2da_mem[4953]) << 0x8 | uint(c2da_mem[4954]) << 0x10 | uint(c2da_mem[4955]) << 0x18) == 1) {
        Draw_Character(x_3 + 4, int(uint(y_3) + vid.height - 24u), num_1)
    } else {
        Draw_Character(int(uint(x_3) + (vid.width - 320u >> 1u) + 4u), int(uint(y_3) + vid.height - 24u), num_1)
    }
    return
}
[export, sideeffects]
def Sbar_DrawScoreboard() {
    Sbar_SoloScoreboard()
    if (int(uint(c2da_mem[4952]) | uint(c2da_mem[4953]) << 0x8 | uint(c2da_mem[4954]) << 0x10 | uint(c2da_mem[4955]) << 0x18) == 1) {
        Sbar_DeathmatchOverlay()
    }
    return
}
[export, sideeffects]
def Sbar_DeathmatchOverlay() {
    let c2da_saved_sp : int = c2da_lin_sp
    Sbar_DeathmatchOverlay_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Sbar_SoloScoreboard() {
    let c2da_saved_sp : int = c2da_lin_sp
    Sbar_SoloScoreboard_c2da_frame(c2da_lin_enter(80))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Sbar_DrawString(var x_5 : int; var y_5 : int; var str_0 : int) {
    if (int(uint(c2da_mem[4952]) | uint(c2da_mem[4953]) << 0x8 | uint(c2da_mem[4954]) << 0x10 | uint(c2da_mem[4955]) << 0x18) == 1) {
        Draw_String(x_5, int(uint(y_5) + vid.height - 24u), str_0)
    } else {
        Draw_String(int(uint(x_5) + (vid.width - 320u >> 1u)), int(uint(y_5) + vid.height - 24u), str_0)
    }
    return
}
[export, sideeffects]
def Sbar_DrawFrags() {
    let c2da_saved_sp : int = c2da_lin_sp
    Sbar_DrawFrags_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Sbar_DrawInventory() {
    let c2da_saved_sp : int = c2da_lin_sp
    Sbar_DrawInventory_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
var hipweapons : int[4] = fixed_array<int>(23, 7, 4, 16)

[export, sideeffects]
def Sbar_IntermissionOverlay() {
    var pic_3 : int
    var dig_0 : int
    var num_2 : int
    scr_copyeverything = 1
    scr_fullupdate = 0
    if (int(uint(c2da_mem[4952]) | uint(c2da_mem[4953]) << 0x8 | uint(c2da_mem[4954]) << 0x10 | uint(c2da_mem[4955]) << 0x18) == 1) {
        Sbar_DeathmatchOverlay()
        return
    }
    pic_3 = Draw_CachePic(735719)
    Draw_Pic(64, 24, pic_3)
    pic_3 = Draw_CachePic(735736)
    Draw_TransPic(0, 56, pic_3)
    dig_0 = int(uint(c2da_mem[760]) | uint(c2da_mem[761]) << 0x8 | uint(c2da_mem[762]) << 0x10 | uint(c2da_mem[763]) << 0x18) / 60
    Sbar_IntermissionNumber(160, 64, dig_0, 3, 0)
    num_2 = int(uint(c2da_mem[760]) | uint(c2da_mem[761]) << 0x8 | uint(c2da_mem[762]) << 0x10 | uint(c2da_mem[763]) << 0x18) - dig_0 * 60
    Draw_TransPic(234, 64, sb_colon)
    Draw_TransPic(246, 64, sb_nums[0][num_2 / 10])
    Draw_TransPic(266, 64, sb_nums[0][num_2 % 10])
    Sbar_IntermissionNumber(160, 104, int(uint(c2da_mem[236 + 13 * 4]) | uint(c2da_mem[236 + 13 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 13 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 13 * 4 + 3]) << 0x18), 3, 0)
    Draw_TransPic(232, 104, sb_slash)
    Sbar_IntermissionNumber(240, 104, int(uint(c2da_mem[236 + 11 * 4]) | uint(c2da_mem[236 + 11 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 11 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 11 * 4 + 3]) << 0x18), 3, 0)
    Sbar_IntermissionNumber(160, 144, int(uint(c2da_mem[236 + 14 * 4]) | uint(c2da_mem[236 + 14 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 14 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 14 * 4 + 3]) << 0x18), 3, 0)
    Draw_TransPic(232, 144, sb_slash)
    Sbar_IntermissionNumber(240, 144, int(uint(c2da_mem[236 + 12 * 4]) | uint(c2da_mem[236 + 12 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 12 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 12 * 4 + 3]) << 0x18), 3, 0)
    return
}
[export, sideeffects]
def Sbar_IntermissionNumber(var x_7 : int; var y_7 : int; var num_3 : int; var digits_0 : int; var color_0 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    Sbar_IntermissionNumber_c2da_frame(x_7, y_7, num_3, digits_0, color_0, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def Sbar_FinaleOverlay() {
    var pic_4 : int
    scr_copyeverything = 1
    pic_4 = Draw_CachePic(735750)
    Draw_TransPic(int((vid.width - uint(int(uint(c2da_mem[pic_4]) | uint(c2da_mem[pic_4 + 1]) << 0x8 | uint(c2da_mem[pic_4 + 2]) << 0x10 | uint(c2da_mem[pic_4 + 3]) << 0x18))) / 2u), 16, pic_4)
    return
}
var scoreboardtop : int[16]

var scoreboardbottom : int[16]

var scoreboardcount : int[16]

[export, sideeffects]
def Sbar_UpdateScoreboard() {
    var i_5 : int
    var k_3 : int
    var top_3 : int
    var bottom_3 : int
    var s_3 : int
    Sbar_SortFrags()
    c2da_lin_memset(460784, 0, 320ul)
    i_5 = 0
    while (i_5 < scoreboardlines) {
        k_3 = fragsort[i_5]
        s_3 = int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + k_3 * 16428
        c2da_lin_snprintf(460784 + i_5 * 20 + 1, 2147483647ul, 735765, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[s_3 + 36]) | uint(c2da_mem[s_3 + 37]) << 0x8 | uint(c2da_mem[s_3 + 38]) << 0x10 | uint(c2da_mem[s_3 + 39]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(s_3))])
        top_3 = int(uint(c2da_mem[s_3 + 40]) | uint(c2da_mem[s_3 + 41]) << 0x8 | uint(c2da_mem[s_3 + 42]) << 0x10 | uint(c2da_mem[s_3 + 43]) << 0x18) & 240
        bottom_3 = (int(uint(c2da_mem[s_3 + 40]) | uint(c2da_mem[s_3 + 41]) << 0x8 | uint(c2da_mem[s_3 + 42]) << 0x10 | uint(c2da_mem[s_3 + 43]) << 0x18) & 15) << 4
        scoreboardtop[i_5] = Sbar_ColorForMap(top_3)
        scoreboardbottom[i_5] = Sbar_ColorForMap(bottom_3)
        i_5++
    }
    return
}
[sideeffects]
def private Sbar_MiniDeathmatchOverlay_c2da_frame(c2da_fp : int) {
    var pic : int
    var i_0 : int
    var k : int
    var l : int
    var top : int
    var bottom : int
    var x : int
    var y : int
    var f : int
    var s : int
    var numlines : int
    if (vid.width < 512u || sb_lines == 0) {
        return
    }
    scr_copyeverything = 1
    scr_fullupdate = 0
    Sbar_SortFrags()
    l = scoreboardlines
    y = int(vid.height - uint(sb_lines))
    numlines = sb_lines / 8
    if (numlines < 3) {
        return
    }
    i_0 = 0
    while (i_0 < scoreboardlines) {
        if (fragsort[i_0] == int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18) - 1) {
            break
        }
        i_0++
    }
    if (i_0 == scoreboardlines) {
        i_0 = 0
    } else {
        i_0 -= numlines / 2
    }
    if (i_0 > scoreboardlines - numlines) {
        i_0 = scoreboardlines - numlines
    }
    if (i_0 < 0) {
        i_0 = 0
    }
    x = 324
    while (i_0 < scoreboardlines && uint(y) < vid.height - 8u) {
        k = fragsort[i_0]
        s = int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + k * 16428
        if (int8(c2da_mem[s + 0]) == 0) {
            i_0++
            continue
        }
        top = int(uint(c2da_mem[s + 40]) | uint(c2da_mem[s + 41]) << 0x8 | uint(c2da_mem[s + 42]) << 0x10 | uint(c2da_mem[s + 43]) << 0x18) & 240
        bottom = (int(uint(c2da_mem[s + 40]) | uint(c2da_mem[s + 41]) << 0x8 | uint(c2da_mem[s + 42]) << 0x10 | uint(c2da_mem[s + 43]) << 0x18) & 15) << 4
        top = Sbar_ColorForMap(top)
        bottom = Sbar_ColorForMap(bottom)
        Draw_Fill(x, y + 1, 40, 3, top)
        Draw_Fill(x, y + 4, 40, 4, bottom)
        f = int(uint(c2da_mem[s + 36]) | uint(c2da_mem[s + 37]) << 0x8 | uint(c2da_mem[s + 38]) << 0x10 | uint(c2da_mem[s + 39]) << 0x18)
        c2da_lin_snprintf(c2da_fp, 2147483647ul, 735648, [C2daVaArg(tag = 1, i64 = int64(f), f64 = 0.0lf, raw = 0x0)])
        Draw_Character(x + 8, y, int(int8(c2da_mem[c2da_fp + 0])))
        Draw_Character(x + 16, y, int(int8(c2da_mem[c2da_fp + 1])))
        Draw_Character(x + 24, y, int(int8(c2da_mem[c2da_fp + 2])))
        if (k == int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18) - 1) {
            Draw_Character(x, y, 16)
            Draw_Character(x + 32, y, 17)
        }
        Draw_String(x + 48, y, s)
        y += 8
        i_0++
    }
    return
}
[sideeffects]
def private Sbar_DrawNum_c2da_frame(var x_0 : int; var y_0 : int; var num : int; var digits : int; var color : int; c2da_fp : int) {
    var ptr : int
    var l_0 : int
    var frame : int
    l_0 = Sbar_itoa(num, c2da_fp)
    ptr = c2da_fp
    if (l_0 > digits) {
        ptr += l_0 - digits
    }
    if (l_0 < digits) {
        x_0 += (digits - l_0) * 24
    }
    while (int8(c2da_mem[ptr]) != 0) {
        if (int(int8(c2da_mem[ptr])) == 45) {
            frame = 10
        } else {
            frame = int(int8(c2da_mem[ptr])) - 48
        }
        Sbar_DrawTransPic(x_0, y_0, sb_nums[color][frame])
        x_0 += 24
        ptr++
    }
    return
}
[sideeffects]
def private Sbar_DrawFace_c2da_frame(c2da_fp : int) {
    var f_0 : int
    var anim : int
    var top_0 : int
    var bottom_0 : int
    var xofs : int
    var s_0 : int
    if (uint(rogue) != 0x0 && int(uint(c2da_mem[4948]) | uint(c2da_mem[4949]) << 0x8 | uint(c2da_mem[4950]) << 0x10 | uint(c2da_mem[4951]) << 0x18) != 1 && uint_bits_to_float(uint(c2da_mem[243464]) | uint(c2da_mem[243465]) << 0x8 | uint(c2da_mem[243466]) << 0x10 | uint(c2da_mem[243467]) << 0x18) > 3.0 && uint_bits_to_float(uint(c2da_mem[243464]) | uint(c2da_mem[243465]) << 0x8 | uint(c2da_mem[243466]) << 0x10 | uint(c2da_mem[243467]) << 0x18) < 7.0) {
        s_0 = int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + (int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18) - 1) * 16428
        top_0 = int(uint(c2da_mem[s_0 + 40]) | uint(c2da_mem[s_0 + 41]) << 0x8 | uint(c2da_mem[s_0 + 42]) << 0x10 | uint(c2da_mem[s_0 + 43]) << 0x18) & 240
        bottom_0 = (int(uint(c2da_mem[s_0 + 40]) | uint(c2da_mem[s_0 + 41]) << 0x8 | uint(c2da_mem[s_0 + 42]) << 0x10 | uint(c2da_mem[s_0 + 43]) << 0x18) & 15) << 4
        top_0 = Sbar_ColorForMap(top_0)
        bottom_0 = Sbar_ColorForMap(bottom_0)
        if (int(uint(c2da_mem[4952]) | uint(c2da_mem[4953]) << 0x8 | uint(c2da_mem[4954]) << 0x10 | uint(c2da_mem[4955]) << 0x18) == 1) {
            xofs = 113
        } else {
            xofs = int((vid.width - 320u >> 1u) + 113u)
        }
        Sbar_DrawPic(112, 0, rsb_teambord)
        Draw_Fill(xofs, int(vid.height - 24u + 3u), 22, 9, top_0)
        Draw_Fill(xofs, int(vid.height - 24u + 12u), 22, 9, bottom_0)
        f_0 = int(uint(c2da_mem[s_0 + 36]) | uint(c2da_mem[s_0 + 37]) << 0x8 | uint(c2da_mem[s_0 + 38]) << 0x10 | uint(c2da_mem[s_0 + 39]) << 0x18)
        c2da_lin_snprintf(c2da_fp, 2147483647ul, 735648, [C2daVaArg(tag = 1, i64 = int64(f_0), f64 = 0.0lf, raw = 0x0)])
        if (top_0 == 8) {
            if (int(int8(c2da_mem[c2da_fp + 0])) != 32) {
                Sbar_DrawCharacter(109, 3, 18 + int(int8(c2da_mem[c2da_fp + 0])) - 48)
            }
            if (int(int8(c2da_mem[c2da_fp + 1])) != 32) {
                Sbar_DrawCharacter(116, 3, 18 + int(int8(c2da_mem[c2da_fp + 1])) - 48)
            }
            if (int(int8(c2da_mem[c2da_fp + 2])) != 32) {
                Sbar_DrawCharacter(123, 3, 18 + int(int8(c2da_mem[c2da_fp + 2])) - 48)
            }
        } else {
            Sbar_DrawCharacter(109, 3, int(int8(c2da_mem[c2da_fp + 0])))
            Sbar_DrawCharacter(116, 3, int(int8(c2da_mem[c2da_fp + 1])))
            Sbar_DrawCharacter(123, 3, int(int8(c2da_mem[c2da_fp + 2])))
        }
        return
    }
    if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & (524288 | 1048576)) == (524288 | 1048576)) {
        Sbar_DrawPic(112, 0, sb_face_invis_invuln)
        return
    }
    if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 4194304) != 0) {
        Sbar_DrawPic(112, 0, sb_face_quad)
        return
    }
    if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 524288) != 0) {
        Sbar_DrawPic(112, 0, sb_face_invis)
        return
    }
    if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 1048576) != 0) {
        Sbar_DrawPic(112, 0, sb_face_invuln)
        return
    }
    if (int(uint(c2da_mem[236 + 0 * 4]) | uint(c2da_mem[236 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 0 * 4 + 3]) << 0x18) >= 100) {
        f_0 = 4
    } else {
        f_0 = int(uint(c2da_mem[236 + 0 * 4]) | uint(c2da_mem[236 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 0 * 4 + 3]) << 0x18) / 20
    }
    if (uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) <= double(uint_bits_to_float(uint(c2da_mem[496]) | uint(c2da_mem[497]) << 0x8 | uint(c2da_mem[498]) << 0x10 | uint(c2da_mem[499]) << 0x18))) {
        anim = 1
        sb_updates = 0
    } else {
        anim = 0
    }
    Sbar_DrawPic(112, 0, sb_faces[f_0][anim])
    return
}
[sideeffects]
def private Sbar_DeathmatchOverlay_c2da_frame(c2da_fp : int) {
    var pic_2 : int
    var k_1 : int
    var l_1 : int
    var top_1 : int
    var bottom_1 : int
    var x_4 : int
    var y_4 : int
    var f_1 : int
    var s_1 : int
    scr_copyeverything = 1
    scr_fullupdate = 0
    pic_2 = Draw_CachePic(735652)
    M_DrawPic((320 - int(uint(c2da_mem[pic_2]) | uint(c2da_mem[pic_2 + 1]) << 0x8 | uint(c2da_mem[pic_2 + 2]) << 0x10 | uint(c2da_mem[pic_2 + 3]) << 0x18)) / 2, 8, pic_2)
    Sbar_SortFrags()
    l_1 = scoreboardlines
    x_4 = int(80u + (vid.width - 320u >> 1u))
    y_4 = 40
    for (i_2 in range(0, l_1)) {
        k_1 = fragsort[i_2]
        s_1 = int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + k_1 * 16428
        if (int8(c2da_mem[s_1 + 0]) == 0) {
            continue
        }
        top_1 = int(uint(c2da_mem[s_1 + 40]) | uint(c2da_mem[s_1 + 41]) << 0x8 | uint(c2da_mem[s_1 + 42]) << 0x10 | uint(c2da_mem[s_1 + 43]) << 0x18) & 240
        bottom_1 = (int(uint(c2da_mem[s_1 + 40]) | uint(c2da_mem[s_1 + 41]) << 0x8 | uint(c2da_mem[s_1 + 42]) << 0x10 | uint(c2da_mem[s_1 + 43]) << 0x18) & 15) << 4
        top_1 = Sbar_ColorForMap(top_1)
        bottom_1 = Sbar_ColorForMap(bottom_1)
        Draw_Fill(x_4, y_4, 40, 4, top_1)
        Draw_Fill(x_4, y_4 + 4, 40, 4, bottom_1)
        f_1 = int(uint(c2da_mem[s_1 + 36]) | uint(c2da_mem[s_1 + 37]) << 0x8 | uint(c2da_mem[s_1 + 38]) << 0x10 | uint(c2da_mem[s_1 + 39]) << 0x18)
        c2da_lin_snprintf(c2da_fp, 2147483647ul, 735648, [C2daVaArg(tag = 1, i64 = int64(f_1), f64 = 0.0lf, raw = 0x0)])
        Draw_Character(x_4 + 8, y_4, int(int8(c2da_mem[c2da_fp + 0])))
        Draw_Character(x_4 + 16, y_4, int(int8(c2da_mem[c2da_fp + 1])))
        Draw_Character(x_4 + 24, y_4, int(int8(c2da_mem[c2da_fp + 2])))
        if (k_1 == int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18) - 1) {
            Draw_Character(x_4 - 8, y_4, 12)
        }
        Draw_String(x_4 + 64, y_4, s_1)
        y_4 += 10
    }
    return
}
[sideeffects]
def private Sbar_SoloScoreboard_c2da_frame(c2da_fp : int) {
    var minutes : int
    var seconds : int
    var tens : int
    var l_2 : int
    c2da_lin_snprintf(c2da_fp, 2147483647ul, 735668, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[236 + 14 * 4]) | uint(c2da_mem[236 + 14 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 14 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 14 * 4 + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[236 + 12 * 4]) | uint(c2da_mem[236 + 12 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 12 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 12 * 4 + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    Sbar_DrawString(8, 4, c2da_fp)
    c2da_lin_snprintf(c2da_fp, 2147483647ul, 735686, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[236 + 13 * 4]) | uint(c2da_mem[236 + 13 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 13 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 13 * 4 + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[236 + 11 * 4]) | uint(c2da_mem[236 + 11 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 11 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 11 * 4 + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    Sbar_DrawString(8, 12, c2da_fp)
    minutes = int(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) / 60.0lf)
    seconds = int(uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - double(60 * minutes))
    tens = seconds / 10
    c2da_lin_snprintf(c2da_fp, 2147483647ul, 735704, [C2daVaArg(tag = 1, i64 = int64(minutes), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(tens), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(seconds - 10 * tens), f64 = 0.0lf, raw = 0x0)])
    Sbar_DrawString(184, 4, c2da_fp)
    l_2 = int(c2da_lin_strlen(4904))
    Sbar_DrawString(232 - l_2 * 4, 12, 4904)
    return
}
[sideeffects]
def private Sbar_DrawFrags_c2da_frame(c2da_fp : int) {
    var k_2 : int
    var l_3 : int
    var top_2 : int
    var bottom_2 : int
    var x_6 : int
    var y_6 : int
    var f_2 : int
    var xofs_0 : int
    var s_2 : int
    Sbar_SortFrags()
    l_3 = scoreboardlines <= 4 ? scoreboardlines : 4
    x_6 = 23
    if (int(uint(c2da_mem[4952]) | uint(c2da_mem[4953]) << 0x8 | uint(c2da_mem[4954]) << 0x10 | uint(c2da_mem[4955]) << 0x18) == 1) {
        xofs_0 = 0
    } else {
        xofs_0 = int(vid.width - 320u >> 1u)
    }
    y_6 = int(vid.height - 24u - 23u)
    for (i_3 in range(0, l_3)) {
        k_2 = fragsort[i_3]
        s_2 = int(uint(c2da_mem[5192]) | uint(c2da_mem[5193]) << 0x8 | uint(c2da_mem[5194]) << 0x10 | uint(c2da_mem[5195]) << 0x18) + k_2 * 16428
        if (int8(c2da_mem[s_2 + 0]) == 0) {
            continue
        }
        top_2 = int(uint(c2da_mem[s_2 + 40]) | uint(c2da_mem[s_2 + 41]) << 0x8 | uint(c2da_mem[s_2 + 42]) << 0x10 | uint(c2da_mem[s_2 + 43]) << 0x18) & 240
        bottom_2 = (int(uint(c2da_mem[s_2 + 40]) | uint(c2da_mem[s_2 + 41]) << 0x8 | uint(c2da_mem[s_2 + 42]) << 0x10 | uint(c2da_mem[s_2 + 43]) << 0x18) & 15) << 4
        top_2 = Sbar_ColorForMap(top_2)
        bottom_2 = Sbar_ColorForMap(bottom_2)
        Draw_Fill(xofs_0 + x_6 * 8 + 10, y_6, 28, 4, top_2)
        Draw_Fill(xofs_0 + x_6 * 8 + 10, y_6 + 4, 28, 3, bottom_2)
        f_2 = int(uint(c2da_mem[s_2 + 36]) | uint(c2da_mem[s_2 + 37]) << 0x8 | uint(c2da_mem[s_2 + 38]) << 0x10 | uint(c2da_mem[s_2 + 39]) << 0x18)
        c2da_lin_snprintf(c2da_fp, 2147483647ul, 735648, [C2daVaArg(tag = 1, i64 = int64(f_2), f64 = 0.0lf, raw = 0x0)])
        Sbar_DrawCharacter((x_6 + 1) * 8, -24, int(int8(c2da_mem[c2da_fp + 0])))
        Sbar_DrawCharacter((x_6 + 2) * 8, -24, int(int8(c2da_mem[c2da_fp + 1])))
        Sbar_DrawCharacter((x_6 + 3) * 8, -24, int(int8(c2da_mem[c2da_fp + 2])))
        if (k_2 == int(uint(c2da_mem[4944]) | uint(c2da_mem[4945]) << 0x8 | uint(c2da_mem[4946]) << 0x10 | uint(c2da_mem[4947]) << 0x18) - 1) {
            Sbar_DrawCharacter(x_6 * 8 + 2, -24, 16)
            Sbar_DrawCharacter((x_6 + 4) * 8 - 4, -24, 17)
        }
        x_6 += 4
    }
    return
}
[sideeffects]
def private Sbar_DrawInventory_c2da_frame(c2da_fp : int) {
    var i_4 : int
    var time : float
    var flashon : int
    var grenadeflashing : int
    if (uint(rogue) != 0u) {
        if (int(uint(c2da_mem[236 + 10 * 4]) | uint(c2da_mem[236 + 10 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 10 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 10 * 4 + 3]) << 0x18) >= 4096) {
            Sbar_DrawPic(0, -24, rsb_invbar[0])
        } else {
            Sbar_DrawPic(0, -24, rsb_invbar[1])
        }
    } else {
        Sbar_DrawPic(0, -24, sb_ibar)
    }
    i_4 = 0
    while (i_4 < 7) {
        if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 1 << i_4) != 0) {
            time = uint_bits_to_float(uint(c2da_mem[368 + i_4 * 4]) | uint(c2da_mem[368 + i_4 * 4 + 1]) << 0x8 | uint(c2da_mem[368 + i_4 * 4 + 2]) << 0x10 | uint(c2da_mem[368 + i_4 * 4 + 3]) << 0x18)
            flashon = int((uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - double(time)) * 10.0lf)
            if (flashon >= 10) {
                if (int(uint(c2da_mem[236 + 10 * 4]) | uint(c2da_mem[236 + 10 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 10 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 10 * 4 + 3]) << 0x18) == 1 << i_4) {
                    flashon = 1
                } else {
                    flashon = 0
                }
            } else {
                flashon = flashon % 5 + 2
            }
            Sbar_DrawPic(i_4 * 24, -16, sb_weapons[flashon][i_4])
            if (flashon > 1) {
                sb_updates = 0
            }
        }
        i_4++
    }
    if (uint(hipnotic) != 0u) {
        grenadeflashing = 0
        i_4 = 0
        while (i_4 < 4) {
            if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 1 << hipweapons[i_4]) != 0) {
                let c2da_fresh8 : int = 368 + hipweapons[i_4] * 4
                time = uint_bits_to_float(uint(c2da_mem[c2da_fresh8]) | uint(c2da_mem[c2da_fresh8 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh8 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh8 + 3]) << 0x18)
                flashon = int((uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - double(time)) * 10.0lf)
                if (flashon >= 10) {
                    if (int(uint(c2da_mem[236 + 10 * 4]) | uint(c2da_mem[236 + 10 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 10 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 10 * 4 + 3]) << 0x18) == 1 << hipweapons[i_4]) {
                        flashon = 1
                    } else {
                        flashon = 0
                    }
                } else {
                    flashon = flashon % 5 + 2
                }
                if (i_4 == 2) {
                    if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 1 << 16) != 0) {
                        if (flashon != 0) {
                            grenadeflashing = 1
                            Sbar_DrawPic(96, -16, hsb_weapons[flashon][2])
                        }
                    }
                } elif (i_4 == 3) {
                    if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 1 << 4) != 0) {
                        if (flashon != 0 && grenadeflashing == 0) {
                            Sbar_DrawPic(96, -16, hsb_weapons[flashon][3])
                        } elif (grenadeflashing == 0) {
                            Sbar_DrawPic(96, -16, hsb_weapons[0][3])
                        }
                    } else {
                        Sbar_DrawPic(96, -16, hsb_weapons[flashon][4])
                    }
                } else {
                    Sbar_DrawPic(176 + i_4 * 24, -16, hsb_weapons[flashon][i_4])
                }
                if (flashon > 1) {
                    sb_updates = 0
                }
            }
            i_4++
        }
    }
    if (uint(rogue) != 0u) {
        if (int(uint(c2da_mem[236 + 10 * 4]) | uint(c2da_mem[236 + 10 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 10 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 10 * 4 + 3]) << 0x18) >= 4096) {
            i_4 = 0
            while (i_4 < 5) {
                if (int(uint(c2da_mem[236 + 10 * 4]) | uint(c2da_mem[236 + 10 * 4 + 1]) << 0x8 | uint(c2da_mem[236 + 10 * 4 + 2]) << 0x10 | uint(c2da_mem[236 + 10 * 4 + 3]) << 0x18) == 4096 << i_4) {
                    Sbar_DrawPic((i_4 + 2) * 24, -16, rsb_weapons[i_4])
                }
                i_4++
            }
        }
    }
    i_4 = 0
    while (i_4 < 4) {
        c2da_lin_snprintf(c2da_fp, 2147483647ul, 735648, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[236 + (6 + i_4) * 4]) | uint(c2da_mem[236 + (6 + i_4) * 4 + 1]) << 0x8 | uint(c2da_mem[236 + (6 + i_4) * 4 + 2]) << 0x10 | uint(c2da_mem[236 + (6 + i_4) * 4 + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
        if (int(int8(c2da_mem[c2da_fp + 0])) != 32) {
            Sbar_DrawCharacter((6 * i_4 + 1) * 8 - 2, -24, 18 + int(int8(c2da_mem[c2da_fp + 0])) - 48)
        }
        if (int(int8(c2da_mem[c2da_fp + 1])) != 32) {
            Sbar_DrawCharacter((6 * i_4 + 2) * 8 - 2, -24, 18 + int(int8(c2da_mem[c2da_fp + 1])) - 48)
        }
        if (int(int8(c2da_mem[c2da_fp + 2])) != 32) {
            Sbar_DrawCharacter((6 * i_4 + 3) * 8 - 2, -24, 18 + int(int8(c2da_mem[c2da_fp + 2])) - 48)
        }
        i_4++
    }
    flashon = 0
    i_4 = 0
    while (i_4 < 6) {
        if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 1 << 17 + i_4) != 0) {
            time = uint_bits_to_float(uint(c2da_mem[368 + (17 + i_4) * 4]) | uint(c2da_mem[368 + (17 + i_4) * 4 + 1]) << 0x8 | uint(c2da_mem[368 + (17 + i_4) * 4 + 2]) << 0x10 | uint(c2da_mem[368 + (17 + i_4) * 4 + 3]) << 0x18)
            if (time != 0.0 && double(time) > uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - 2.0lf && flashon != 0) {
                sb_updates = 0
            } elif (uint(hipnotic) == 0u || i_4 > 1) {
                Sbar_DrawPic(192 + i_4 * 16, -16, sb_items[i_4])
            }
            if (time != 0.0 && double(time) > uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - 2.0lf) {
                sb_updates = 0
            }
        }
        i_4++
    }
    if (uint(hipnotic) != 0u) {
        i_4 = 0
        while (i_4 < 2) {
            if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 1 << 24 + i_4) != 0) {
                time = uint_bits_to_float(uint(c2da_mem[368 + (24 + i_4) * 4]) | uint(c2da_mem[368 + (24 + i_4) * 4 + 1]) << 0x8 | uint(c2da_mem[368 + (24 + i_4) * 4 + 2]) << 0x10 | uint(c2da_mem[368 + (24 + i_4) * 4 + 3]) << 0x18)
                if (time != 0.0 && double(time) > uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - 2.0lf && flashon != 0) {
                    sb_updates = 0
                } else {
                    Sbar_DrawPic(288 + i_4 * 16, -16, hsb_items[i_4])
                }
                if (time != 0.0 && double(time) > uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - 2.0lf) {
                    sb_updates = 0
                }
            }
            i_4++
        }
    }
    if (uint(rogue) != 0u) {
        i_4 = 0
        for (c2da_i_4 in range(i_4, 2)) {
            if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 1 << 29 + c2da_i_4) != 0) {
                time = uint_bits_to_float(uint(c2da_mem[368 + (29 + c2da_i_4) * 4]) | uint(c2da_mem[368 + (29 + c2da_i_4) * 4 + 1]) << 0x8 | uint(c2da_mem[368 + (29 + c2da_i_4) * 4 + 2]) << 0x10 | uint(c2da_mem[368 + (29 + c2da_i_4) * 4 + 3]) << 0x18)
                if (time != 0.0 && double(time) > uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - 2.0lf && flashon != 0) {
                    sb_updates = 0
                } else {
                    Sbar_DrawPic(288 + c2da_i_4 * 16, -16, rsb_items[c2da_i_4])
                }
                if (time != 0.0 && double(time) > uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - 2.0lf) {
                    sb_updates = 0
                }
            }
        }
    } else {
        i_4 = 0
        for (c2da_i_4_0 in range(i_4, 4)) {
            if ((int(uint(c2da_mem[364]) | uint(c2da_mem[365]) << 0x8 | uint(c2da_mem[366]) << 0x10 | uint(c2da_mem[367]) << 0x18) & 1 << 28 + c2da_i_4_0) != 0) {
                time = uint_bits_to_float(uint(c2da_mem[368 + (28 + c2da_i_4_0) * 4]) | uint(c2da_mem[368 + (28 + c2da_i_4_0) * 4 + 1]) << 0x8 | uint(c2da_mem[368 + (28 + c2da_i_4_0) * 4 + 2]) << 0x10 | uint(c2da_mem[368 + (28 + c2da_i_4_0) * 4 + 3]) << 0x18)
                if (time != 0.0 && double(time) > uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - 2.0lf && flashon != 0) {
                    sb_updates = 0
                } else {
                    Sbar_DrawPic(320 - 32 + c2da_i_4_0 * 8, -16, sb_sigil[c2da_i_4_0])
                }
                if (time != 0.0 && double(time) > uint64_bits_to_double(uint64(uint(c2da_mem[784]) | uint(c2da_mem[785]) << 0x8 | uint(c2da_mem[786]) << 0x10 | uint(c2da_mem[787]) << 0x18) | uint64(uint(c2da_mem[788]) | uint(c2da_mem[789]) << 0x8 | uint(c2da_mem[790]) << 0x10 | uint(c2da_mem[791]) << 0x18) << 0x20) - 2.0lf) {
                    sb_updates = 0
                }
            }
        }
    }
    return
}
[sideeffects]
def private Sbar_IntermissionNumber_c2da_frame(var x_7 : int; var y_7 : int; var num_3 : int; var digits_0 : int; var color_0 : int; c2da_fp : int) {
    var ptr_0 : int
    var l_4 : int
    var frame_0 : int
    l_4 = Sbar_itoa(num_3, c2da_fp)
    ptr_0 = c2da_fp
    if (l_4 > digits_0) {
        ptr_0 += l_4 - digits_0
    }
    if (l_4 < digits_0) {
        x_7 += (digits_0 - l_4) * 24
    }
    while (int8(c2da_mem[ptr_0]) != 0) {
        if (int(int8(c2da_mem[ptr_0])) == 45) {
            frame_0 = 10
        } else {
            frame_0 = int(int8(c2da_mem[ptr_0])) - 48
        }
        Draw_TransPic(x_7, y_7, sb_nums[color_0][frame_0])
        x_7 += 24
        ptr_0++
    }
    return
}

// This unit's static data, at heap offset 734640.
let private c2da_lin_static_sbar_seg = fixed_array<int>(734640, 1131)
let private c2da_lin_static_sbar = fixed_array<uint64>(0x610069255f6d756eul, 0x6e0069255f6d756eul, 0x73756e696d5f6d75ul, 0x696d5f6d756e6100ul, 0x5f6d756e0073756eul, 0x756e006e6f6c6f63ul, 0x6873616c735f6dul, 0x746f68735f766e69ul, 0x5f766e69006e7567ul, 0x6e7567746f687373ul, 0x69616e5f766e6900ul, 0x766e69006e75676cul, 0x75676c69616e735ful, 0x6c725f766e69006eul, 0x6e690068636e7561ul, 0x6e75616c72735f76ul, 0x6c5f766e69006863ul, 0x6900676e74686769ul, 0x746f68735f32766eul, 0x32766e69006e7567ul, 0x7567746f6873735ful, 0x6e5f32766e69006eul, 0x69006e75676c6961ul, 0x69616e735f32766eul, 0x766e69006e75676cul, 0x636e75616c725f32ul, 0x735f32766e690068ul, 0x68636e75616c72ul, 0x67696c5f32766e69ul, 0x766e6900676e7468ul, 0x746f68735f692561ul, 0x61766e69006e7567ul, 0x746f6873735f6925ul, 0x61766e69006e7567ul, 0x676c69616e5f6925ul, 0x2561766e69006e75ul, 0x676c69616e735f69ul, 0x2561766e69006e75ul, 0x636e75616c725f69ul, 0x692561766e690068ul, 0x636e75616c72735ful, 0x692561766e690068ul, 0x676e746867696c5ful, 0x6c6568735f627300ul, 0x616e5f627300736cul, 0x725f627300736c69ul, 0x62730074656b636ful, 0x7300736c6c65635ful, 0x31726f6d72615f62ul, 0x6f6d72615f627300ul, 0x72615f6273003272ul, 0x5f62730033726f6dul, 0x5f6273003179656bul, 0x5f6273003279656bul, 0x6273007369766e69ul, 0x6e6c75766e695ful, 0x746975735f6273ul, 0x646175715f6273ul, 0x6c696769735f6273ul, 0x6769735f62730031ul, 0x735f627300326c69ul, 0x627300336c696769ul, 0x346c696769735ful, 0x6166003165636166ul, 0x61660031705f6563ul, 0x6563616600326563ul, 0x656361660032705ful, 0x705f656361660033ul, 0x34656361660033ul, 0x34705f65636166ul, 0x6166003565636166ul, 0x61660035705f6563ul, 0x7369766e695f6563ul, 0x6e695f6563616600ul, 0x63616600326c7576ul, 0x660032766e695f65ul, 0x646175715f656361ul, 0x6373776f68732b00ul, 0x68732d007365726ful, 0x7365726f6373776ful, 0x6269007261627300ul, 0x65726f6373007261ul, 0x5f766e6900726162ul, 0x6e6900726573616cul, 0x696e6c6f6a6d5f76ul, 0x72675f766e690072ul, 0x786f72705f6e65ul, 0x786f72705f766e69ul, 0x6e69006e6572675ful, 0x6900786f72705f76ul, 0x6573616c5f32766eul, 0x6d5f32766e690072ul, 0x690072696e6c6f6aul, 0x6e6572675f32766eul, 0x6e6900786f72705ful, 0x5f786f72705f3276ul, 0x766e69006e657267ul, 0x6900786f72705f32ul, 0x616c5f692561766eul, 0x61766e6900726573ul, 0x6e6c6f6a6d5f6925ul, 0x2561766e69007269ul, 0x705f6e6572675f69ul, 0x61766e6900786f72ul, 0x5f786f72705f6925ul, 0x766e69006e657267ul, 0x786f72705f692561ul, 0x697573775f627300ul, 0x6873655f62730074ul, 0x766e695f7200646cul, 0x695f720031726162ul, 0x720032726162766eul, 0x5f72006176616c5ful, 0x76616c7265707573ul, 0x6e6572675f720061ul, 0x69746c756d5f7200ul, 0x705f72006b636f72ul, 0x5f7200616d73616cul, 0x31646c65696873ul, 0x3176617267615f72ul, 0x626d6165745f7200ul, 0x6d615f720064726ful, 0x72006176616c6f6dul, 0x6c756d6f6d6d615ful, 0x6d6d615f72006974ul, 0x616d73616c706ful, 0x2f78666700693325ul, 0x2e676e696b6e6172ul, 0x736e6f4d00706d6cul, 0x6933253a73726574ul, 0x6553006933252f20ul, 0x253a207374657263ul, 0x6933252f206933ul, 0x33253a20656d6954ul, 0x6700692569253a69ul, 0x6c706d6f632f7866ul, 0x706d6c2e657465ul, 0x65746e692f786667ul, 0x666700706d6c2e72ul, 0x656c616e69662f78ul, 0x69332500706d6c2eul, 0x732520ul)

[init]
def private c2da_lin_init_static_sbar() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_sbar_seg[s * 2]
        for (k in range(c2da_lin_static_sbar_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_sbar[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_sbar() {
    if (length(c2da_fn_table0) < 217) {
        resize(c2da_fn_table0, 217)
    }
    c2da_fn_table0[216] = @@Sbar_DontShowScores
    c2da_fn_table0[215] = @@Sbar_ShowScores
}

[init]
def private c2da_lin_relink_init_sbar() {
    c2da_relink_sbar()
}
