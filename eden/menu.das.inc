var vid_menudrawfn : int = default<int>

var vid_menukeyfn : int = default<int>

[export, sideeffects]
def M_Init() {
    Cmd_AddCommand(719488, 101)
    Cmd_AddCommand(719499, 102)
    Cmd_AddCommand(719509, 103)
    Cmd_AddCommand(719527, 104)
    Cmd_AddCommand(719537, 105)
    Cmd_AddCommand(719547, 106)
    Cmd_AddCommand(719564, 107)
    Cmd_AddCommand(719575, 108)
    Cmd_AddCommand(719588, 109)
    Cmd_AddCommand(719598, 110)
    Cmd_AddCommand(719609, 111)
    Cmd_AddCommand(719614, 112)
    return
}
[export, sideeffects]
def M_Menu_Quit_f() {
    if (m_state == 12u) {
        return
    }
    wasInMenus = uint(uint(key_dest) == 3u ? 1 : 0)
    key_dest = 3u
    m_quit_prevstate = int(m_state)
    m_state = 12u
    m_entersound = 1u
    msgNumber = c2da_std_rand() & 7
    return
}
var msgNumber : int = default<int>

var m_entersound : uint = default<uint>

var m_state : uint = default<uint>

var m_quit_prevstate : int = default<int>

var wasInMenus : uint = default<uint>

[export, sideeffects]
def M_Menu_Help_f() {
    key_dest = 3u
    m_state = 11u
    m_entersound = 1u
    help_page = 0
    return
}
var help_page : int = default<int>

[export, sideeffects]
def M_Menu_Video_f() {
    key_dest = 3u
    m_state = 9u
    m_entersound = 1u
    return
}
[export, sideeffects]
def M_Menu_Keys_f() {
    key_dest = 3u
    m_state = 10u
    m_entersound = 1u
    return
}
[export, sideeffects]
def M_Menu_Options_f() {
    key_dest = 3u
    m_state = 8u
    m_entersound = 1u
    return
}
[export, sideeffects]
def M_Menu_Setup_f() {
    key_dest = 3u
    m_state = 6u
    m_entersound = 1u
    Q_strcpy(246160, int(uint(c2da_mem[9144]) | uint(c2da_mem[9145]) << 0x8 | uint(c2da_mem[9146]) << 0x10 | uint(c2da_mem[9147]) << 0x18))
    Q_strcpy(246176, int(uint(c2da_mem[386472]) | uint(c2da_mem[386473]) << 0x8 | uint(c2da_mem[386474]) << 0x10 | uint(c2da_mem[386475]) << 0x18))
    let c2da_fresh0 : float = uint_bits_to_float(uint(c2da_mem[9208]) | uint(c2da_mem[9209]) << 0x8 | uint(c2da_mem[9210]) << 0x10 | uint(c2da_mem[9211]) << 0x18)
    setup_oldtop = int(c2da_fresh0) >> 4
    setup_top = int(setup_oldtop)  // nolint:PERF020
    setup_oldbottom = int(c2da_fresh0) & 15
    setup_bottom = int(setup_oldbottom)  // nolint:PERF020
    return
}
var setup_oldbottom : int = default<int>

var setup_bottom : int = default<int>

var setup_oldtop : int = default<int>

var setup_top : int = default<int>

[export, sideeffects]
def M_Menu_MultiPlayer_f() {
    key_dest = 3u
    m_state = 5u
    m_entersound = 1u
    return
}
[export, sideeffects]
def M_Menu_Save_f() {
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) == 0u) {
        return
    }
    if (int(uint(c2da_mem[756]) | uint(c2da_mem[757]) << 0x8 | uint(c2da_mem[758]) << 0x10 | uint(c2da_mem[759]) << 0x18) != 0) {
        return
    }
    if (svs.maxclients != 1) {
        return
    }
    m_entersound = 1u
    m_state = 4u
    key_dest = 3u
    M_ScanSaves()
    return
}
[export, sideeffects]
def M_ScanSaves() {
    let c2da_saved_sp : int = c2da_lin_sp
    M_ScanSaves_c2da_frame(c2da_lin_enter(144))
    c2da_lin_sp = c2da_saved_sp
}
var loadable : int[12]

[export, sideeffects]
def M_Menu_Load_f() {
    m_entersound = 1u
    m_state = 3u
    key_dest = 3u
    M_ScanSaves()
    return
}
[export, sideeffects]
def M_Menu_SinglePlayer_f() {
    key_dest = 3u
    m_state = 2u
    m_entersound = 1u
    return
}
[export, sideeffects]
def M_Menu_Main_f() {
    if (uint(key_dest) != 3u) {
        m_save_demonum = int(uint(c2da_mem[7636]) | uint(c2da_mem[7637]) << 0x8 | uint(c2da_mem[7638]) << 0x10 | uint(c2da_mem[7639]) << 0x18)
        let c2da_fresh2 : int = -1
        let c2da_fresh3 : uint = uint(c2da_fresh2)
        c2da_mem[7636] = uint8(c2da_fresh3)
        c2da_mem[7637] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[7638] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[7639] = uint8(c2da_fresh3 >> 0x18)
    }
    key_dest = 3u
    m_state = 1u
    m_entersound = 1u
    return
}
var m_save_demonum : int = default<int>

[export, sideeffects]
def M_ToggleMenu_f() {
    m_entersound = 1u
    if (uint(key_dest) == 3u) {
        if (m_state != 1u) {
            M_Menu_Main_f()
            return
        }
        key_dest = 0u
        m_state = 0u
        return
    }
    if (uint(key_dest) == 1u) {
        Con_ToggleConsole_f()
    } else {
        M_Menu_Main_f()
    }
    return
}
[export, sideeffects]
def M_Keydown(var key : int) {
    let c2da_fresh4 : uint = m_state
    if (c2da_fresh4 <= 0x12u) {
        goto int(c2da_fresh4)
    }
    return
    label 0:
    return
    label 1:
    M_Main_Key(key)
    return
    label 2:
    M_SinglePlayer_Key(key)
    return
    label 3:
    M_Load_Key(key)
    return
    label 4:
    M_Save_Key(key)
    return
    label 5:
    M_MultiPlayer_Key(key)
    return
    label 6:
    M_Setup_Key(key)
    return
    label 7:
    M_Net_Key(key)
    return
    label 8:
    M_Options_Key(key)
    return
    label 10:
    M_Keys_Key(key)
    return
    label 9:
    M_Video_Key(key)
    return
    label 11:
    M_Help_Key(key)
    return
    label 12:
    M_Quit_Key(key)
    return
    label 13:
    M_SerialConfig_Key(key)
    return
    label 14:
    M_ModemConfig_Key(key)
    return
    label 15:
    M_LanConfig_Key(key)
    return
    label 16:
    M_GameOptions_Key(key)
    return
    label 17:
    M_Search_Key(key)
    return
    label 18:
    M_ServerList_Key(key)
    return
}
[export, sideeffects]
def M_ServerList_Key(var k : int) {
    if (k == 27) {
        M_Menu_LanConfig_f()
    } elif (k == 32) {
        M_Menu_Search_f()
    } elif (k == 128 || k == 130) {
        S_LocalSound(719667)
        slist_cursor--
        if (slist_cursor < 0) {
            slist_cursor = hostCacheCount - 1
        }
    } elif (k == 129 || k == 131) {
        S_LocalSound(719667)
        slist_cursor++
        if (slist_cursor >= hostCacheCount) {
            slist_cursor = 0
        }
    } elif (k == 13) {
        S_LocalSound(719682)
        m_return_state = int(m_state)
        m_return_onerror = 1u
        slist_sorted = 0u
        key_dest = 0u
        m_state = 0u
        Cbuf_AddText(va(719697, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(246672 + slist_cursor * 96 + 32))]))
    }
    return
}
var slist_cursor : int = default<int>

var slist_sorted : uint = default<uint>

var m_return_onerror : uint = default<uint>

var m_return_state : int = default<int>

[export, sideeffects]
def M_Menu_Search_f() {
    key_dest = 3u
    m_state = 17u
    m_entersound = 0u
    slistSilent = 1u
    slistLocal = 0u
    searchComplete = 0u
    NET_Slist_f()
    return
}
var searchComplete : uint = 0u

[export, sideeffects]
def M_Menu_LanConfig_f() {
    key_dest = 3u
    m_state = 15u
    m_entersound = 1u
    if (lanConfig_cursor == -1) {
        if (m_multiplayer_cursor == 0 && m_net_cursor == 3) {
            lanConfig_cursor = 2
        } else {
            lanConfig_cursor = 1
        }
    }
    if (m_multiplayer_cursor == 1 && lanConfig_cursor == 2) {
        lanConfig_cursor = 1
    }
    lanConfig_port = DEFAULTnet_hostport
    c2da_lin_snprintf(247440, 2147483647ul, 719711, [C2daVaArg(tag = 1, i64 = int64(lanConfig_port), f64 = 0.0lf, raw = 0x0)])
    m_return_onerror = 0u
    let c2da_fresh5 : int8 = int8(0)
    c2da_mem[247600 + 0] = uint8(c2da_fresh5)
    return
}
var lanConfig_port : int = default<int>

var lanConfig_cursor : int = -1

var m_multiplayer_cursor : int = default<int>

var m_net_cursor : int = default<int>

[export, sideeffects]
def M_Search_Key(var key_0 : int) {
    return
}
[export, sideeffects]
def M_GameOptions_Key(var key_1 : int) {
    if (key_1 == 27) {
        M_Menu_Net_f()
    } elif (key_1 == 128) {
        S_LocalSound(719667)
        gameoptions_cursor--
        if (gameoptions_cursor < 0) {
            gameoptions_cursor = 9 - 1
        }
    } elif (key_1 == 129) {
        S_LocalSound(719667)
        gameoptions_cursor++
        if (gameoptions_cursor >= 9) {
            gameoptions_cursor = 0
        }
    } elif (key_1 == 130) {
        if (gameoptions_cursor != 0) {
            S_LocalSound(719714)
            M_NetStart_Change(-1)
        }
    } elif (key_1 == 131) {
        if (gameoptions_cursor != 0) {
            S_LocalSound(719714)
            M_NetStart_Change(1)
        }
    } elif (key_1 == 13) {
        S_LocalSound(719682)
        if (gameoptions_cursor == 0) {
            if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) != 0u) {
                Cbuf_AddText(719729)
            }
            Cbuf_AddText(719741)
            Cbuf_AddText(va(719751, [C2daVaArg(tag = 1, i64 = int64(maxplayers), f64 = 0.0lf, raw = 0x0)]))
            SCR_BeginLoadingPlaque()
            if (uint(hipnotic) != 0u) {
                Cbuf_AddText(va(719766, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(hipnoticlevels[hipnoticepisodes[startepisode].firstLevel + startlevel].name))]))
            } elif (uint(rogue) != 0u) {
                Cbuf_AddText(va(719766, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(roguelevels[rogueepisodes[startepisode].firstLevel + startlevel].name))]))
            } else {
                Cbuf_AddText(va(719766, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(levels[episodes[startepisode].firstLevel + startlevel].name))]))
            }
            return
        }
        M_NetStart_Change(1)
    }
    return
}
[export, sideeffects]
def M_NetStart_Change(var dir : int) {
    var count : int
    if (gameoptions_cursor == 1) {
        maxplayers += dir
        if (maxplayers > svs.maxclientslimit) {
            maxplayers = svs.maxclientslimit
            m_serverInfoMessage = 1u
            m_serverInfoMessageTime = realtime
        }
        if (maxplayers < 2) {
            maxplayers = 2
        }
    } elif (gameoptions_cursor == 2) {
        Cvar_SetValue(719774, float(uint_bits_to_float(uint(c2da_mem[243752]) | uint(c2da_mem[243753]) << 0x8 | uint(c2da_mem[243754]) << 0x10 | uint(c2da_mem[243755]) << 0x18) != 0.0 ? 0 : 1))
    } elif (gameoptions_cursor == 3) {
        if (uint(rogue) != 0u) {
            count = 6
        } else {
            count = 2
        }
        Cvar_SetValue(719779, uint_bits_to_float(uint(c2da_mem[243464]) | uint(c2da_mem[243465]) << 0x8 | uint(c2da_mem[243466]) << 0x10 | uint(c2da_mem[243467]) << 0x18) + float(dir))
        if (uint_bits_to_float(uint(c2da_mem[243464]) | uint(c2da_mem[243465]) << 0x8 | uint(c2da_mem[243466]) << 0x10 | uint(c2da_mem[243467]) << 0x18) > float(count)) {
            Cvar_SetValue(719779, 0.0)
        } elif (uint_bits_to_float(uint(c2da_mem[243464]) | uint(c2da_mem[243465]) << 0x8 | uint(c2da_mem[243466]) << 0x10 | uint(c2da_mem[243467]) << 0x18) < 0.0) {
            Cvar_SetValue(719779, float(count))
        }
    } elif (gameoptions_cursor == 4) {
        Cvar_SetValue(719788, uint_bits_to_float(uint(c2da_mem[243608]) | uint(c2da_mem[243609]) << 0x8 | uint(c2da_mem[243610]) << 0x10 | uint(c2da_mem[243611]) << 0x18) + float(dir))
        if (uint_bits_to_float(uint(c2da_mem[243608]) | uint(c2da_mem[243609]) << 0x8 | uint(c2da_mem[243610]) << 0x10 | uint(c2da_mem[243611]) << 0x18) > 3.0) {
            Cvar_SetValue(719788, 0.0)
        }
        if (uint_bits_to_float(uint(c2da_mem[243608]) | uint(c2da_mem[243609]) << 0x8 | uint(c2da_mem[243610]) << 0x10 | uint(c2da_mem[243611]) << 0x18) < 0.0) {
            Cvar_SetValue(719788, 3.0)
        }
    } elif (gameoptions_cursor == 5) {
        Cvar_SetValue(719794, uint_bits_to_float(uint(c2da_mem[243368]) | uint(c2da_mem[243369]) << 0x8 | uint(c2da_mem[243370]) << 0x10 | uint(c2da_mem[243371]) << 0x18) + float(dir * 10))
        if (uint_bits_to_float(uint(c2da_mem[243368]) | uint(c2da_mem[243369]) << 0x8 | uint(c2da_mem[243370]) << 0x10 | uint(c2da_mem[243371]) << 0x18) > 100.0) {
            Cvar_SetValue(719794, 0.0)
        }
        if (uint_bits_to_float(uint(c2da_mem[243368]) | uint(c2da_mem[243369]) << 0x8 | uint(c2da_mem[243370]) << 0x10 | uint(c2da_mem[243371]) << 0x18) < 0.0) {
            Cvar_SetValue(719794, 100.0)
        }
    } elif (gameoptions_cursor == 6) {
        Cvar_SetValue(719804, uint_bits_to_float(uint(c2da_mem[243416]) | uint(c2da_mem[243417]) << 0x8 | uint(c2da_mem[243418]) << 0x10 | uint(c2da_mem[243419]) << 0x18) + float(dir * 5))
        if (uint_bits_to_float(uint(c2da_mem[243416]) | uint(c2da_mem[243417]) << 0x8 | uint(c2da_mem[243418]) << 0x10 | uint(c2da_mem[243419]) << 0x18) > 60.0) {
            Cvar_SetValue(719804, 0.0)
        }
        if (uint_bits_to_float(uint(c2da_mem[243416]) | uint(c2da_mem[243417]) << 0x8 | uint(c2da_mem[243418]) << 0x10 | uint(c2da_mem[243419]) << 0x18) < 0.0) {
            Cvar_SetValue(719804, 60.0)
        }
    } elif (gameoptions_cursor == 7) {
        startepisode += dir
        if (uint(hipnotic) != 0u) {
            count = 6
        } elif (uint(rogue) != 0u) {
            count = 4
        } elif (uint_bits_to_float(uint(c2da_mem[195528]) | uint(c2da_mem[195529]) << 0x8 | uint(c2da_mem[195530]) << 0x10 | uint(c2da_mem[195531]) << 0x18) != 0.0) {
            count = 7
        } else {
            count = 2
        }
        if (startepisode < 0) {
            startepisode = count - 1
        }
        if (startepisode >= count) {
            startepisode = 0
        }
        startlevel = 0
    } elif (gameoptions_cursor == 8) {
        startlevel += dir
        if (uint(hipnotic) != 0u) {
            count = hipnoticepisodes[startepisode].levels
        } elif (uint(rogue) != 0u) {
            count = rogueepisodes[startepisode].levels
        } else {
            count = episodes[startepisode].levels
        }
        if (startlevel < 0) {
            startlevel = count - 1
        }
        if (startlevel >= count) {
            startlevel = 0
        }
    }
    return
}
var startlevel : int = default<int>

var startepisode : int = default<int>

var episodes : episode_t[7] = fixed_array<episode_t>(episode_t(description = 719814, firstLevel = 0, levels = 1), episode_t(description = 719831, firstLevel = 1, levels = 8), episode_t(description = 719848, firstLevel = 9, levels = 7), episode_t(description = 719869, firstLevel = 16, levels = 7), episode_t(description = 719881, firstLevel = 23, levels = 8), episode_t(description = 719897, firstLevel = 31, levels = 1), episode_t(description = 719909, firstLevel = 32, levels = 6))

var rogueepisodes : episode_t[4] = fixed_array<episode_t>(episode_t(description = 719926, firstLevel = 0, levels = 1), episode_t(description = 719939, firstLevel = 1, levels = 7), episode_t(description = 719955, firstLevel = 8, levels = 8), episode_t(description = 719909, firstLevel = 16, levels = 1))

var hipnoticepisodes : episode_t[6] = fixed_array<episode_t>(episode_t(description = 719973, firstLevel = 0, levels = 1), episode_t(description = 719992, firstLevel = 1, levels = 5), episode_t(description = 720013, firstLevel = 6, levels = 6), episode_t(description = 720034, firstLevel = 12, levels = 4), episode_t(description = 719897, firstLevel = 16, levels = 1), episode_t(description = 719909, firstLevel = 17, levels = 1))

var maxplayers : int = default<int>

var m_serverInfoMessageTime : double = default<double>

var m_serverInfoMessage : uint = 0u

var gameoptions_cursor : int = default<int>

var levels : level_t[38] = fixed_array<level_t>(level_t(name = 720043, description = 720049), level_t(name = 720058, description = 720063), level_t(name = 720080, description = 720085), level_t(name = 720106, description = 720111), level_t(name = 720126, description = 720131), level_t(name = 720149, description = 720154), level_t(name = 720165, description = 720170), level_t(name = 720189, description = 720194), level_t(name = 720214, description = 720219), level_t(name = 720236, description = 720241), level_t(name = 720258, description = 720263), level_t(name = 720276, description = 720281), level_t(name = 720296, description = 720301), level_t(name = 720319, description = 720324), level_t(name = 720343, description = 720348), level_t(name = 720369, description = 720374), level_t(name = 720385, description = 720390), level_t(name = 720410, description = 720415), level_t(name = 720433, description = 720438), level_t(name = 720457, description = 720462), level_t(name = 720483, description = 720488), level_t(name = 720501, description = 720506), level_t(name = 720526, description = 720531), level_t(name = 720549, description = 720554), level_t(name = 720572, description = 720577), level_t(name = 720598, description = 720603), level_t(name = 720624, description = 720629), level_t(name = 720648, description = 720653), level_t(name = 720667, description = 720672), level_t(name = 720686, description = 720691), level_t(name = 720703, description = 720708), level_t(name = 720726, description = 720730), level_t(name = 720751, description = 720755), level_t(name = 720775, description = 720779), level_t(name = 720798, description = 720802), level_t(name = 720821, description = 720825), level_t(name = 720839, description = 720843), level_t(name = 720855, description = 720859))

var roguelevels : level_t[17] = fixed_array<level_t>(level_t(name = 720043, description = 720873), level_t(name = 720888, description = 720893), level_t(name = 720910, description = 720915), level_t(name = 720928, description = 720933), level_t(name = 720948, description = 720953), level_t(name = 720967, description = 720972), level_t(name = 720988, description = 720993), level_t(name = 721008, description = 721013), level_t(name = 721034, description = 721039), level_t(name = 721052, description = 721057), level_t(name = 721074, description = 721079), level_t(name = 721097, description = 721102), level_t(name = 721118, description = 721123), level_t(name = 721137, description = 721142), level_t(name = 721158, description = 721163), level_t(name = 721176, description = 721181), level_t(name = 721196, description = 721201))

var hipnoticlevels : level_t[18] = fixed_array<level_t>(level_t(name = 720043, description = 721220), level_t(name = 721231, description = 721238), level_t(name = 721258, description = 721265), level_t(name = 721282, description = 721289), level_t(name = 721303, description = 721310), level_t(name = 721328, description = 721335), level_t(name = 721352, description = 721359), level_t(name = 721374, description = 721381), level_t(name = 721401, description = 721408), level_t(name = 721422, description = 721429), level_t(name = 721439, description = 721446), level_t(name = 721460, description = 721467), level_t(name = 721488, description = 721495), level_t(name = 721507, description = 721514), level_t(name = 721526, description = 721533), level_t(name = 721539, description = 721546), level_t(name = 721559, description = 721566), level_t(name = 721581, description = 721588))

[export, sideeffects]
def M_Menu_Net_f() {
    key_dest = 3u
    m_state = 7u
    m_entersound = 1u
    m_net_items = 4
    if (m_net_cursor >= m_net_items) {
        m_net_cursor = 0
    }
    m_net_cursor--
    M_Net_Key(129)
    return
}
[export, sideeffects]
def M_Net_Key(var k_0 : int) {
    label 0:
    if (k_0 == 13) {
        goto label 13
    } elif (k_0 == 27) {
        goto label 6
    } elif (k_0 == 128) {
        goto label 10
    } elif (k_0 == 129) {
        goto label 7
    }
    label 1:
    if (m_net_cursor == 0 && uint(serialAvailable) == 0u) {
        goto label 5
    }
    if (m_net_cursor == 1 && uint(serialAvailable) == 0u) {
        goto label 4
    }
    if (m_net_cursor == 2 && uint(ipxAvailable) == 0u) {
        goto label 3
    }
    if (m_net_cursor == 3 && uint(tcpipAvailable) == 0u) {
        goto label 2
    }
    return
    label 2:
    goto label 0
    label 3:
    goto label 0
    label 4:
    goto label 0
    label 5:
    goto label 0
    label 6:
    M_Menu_MultiPlayer_f()
    goto label 1
    label 7:
    S_LocalSound(719667)
    m_net_cursor++
    if (m_net_cursor >= m_net_items) {
        goto label 9
    }
    label 8:
    goto label 1
    label 9:
    m_net_cursor = 0
    goto label 8
    label 10:
    S_LocalSound(719667)
    m_net_cursor--
    if (m_net_cursor < 0) {
        goto label 12
    }
    label 11:
    goto label 1
    label 12:
    m_net_cursor = m_net_items - 1
    goto label 11
    label 13:
    m_entersound = 1u
    if (m_net_cursor >= 0 && m_net_cursor <= 4) {
        goto m_net_cursor + 15
    }
    label 14:
    goto label 1
    label 15:
    M_Menu_SerialConfig_f()
    goto label 14
    label 16:
    M_Menu_SerialConfig_f()
    goto label 14
    label 17:
    M_Menu_LanConfig_f()
    goto label 14
    label 18:
    M_Menu_LanConfig_f()
    goto label 14
    label 19:
    goto label 14
    panic("unreachable: fell out of a translated control-flow graph")
}
[export, sideeffects]
def M_Menu_SerialConfig_f() {
    let c2da_saved_sp : int = c2da_lin_sp
    M_Menu_SerialConfig_f_c2da_frame(c2da_lin_enter(48))
    c2da_lin_sp = c2da_saved_sp
}
var serialConfig_baud : int = default<int>

var serialConfig_baudrate : int[6] = fixed_array<int>(9600, 14400, 19200, 28800, 38400, 57600)

var serialConfig_comport : int = default<int>

var private ISA_uarts : int[4] = fixed_array<int>(1016, 760, 1000, 744)

var serialConfig_cursor : int = default<int>

var m_net_items : int = default<int>

[export, sideeffects]
def M_LanConfig_Key(var key_2 : int) {
    var l : int
    if (key_2 == 27) {
        M_Menu_Net_f()
    } elif (key_2 == 128) {
        S_LocalSound(719667)
        lanConfig_cursor--
        if (lanConfig_cursor < 0) {
            lanConfig_cursor = 3 - 1
        }
    } elif (key_2 == 129) {
        S_LocalSound(719667)
        lanConfig_cursor++
        if (lanConfig_cursor >= 3) {
            lanConfig_cursor = 0
        }
    } elif (key_2 == 13) {
        if (lanConfig_cursor != 0) {
            m_entersound = 1u
            M_ConfigureNetSubsystem()
            if (lanConfig_cursor == 1) {
                if (m_multiplayer_cursor == 1) {
                    M_Menu_GameOptions_f()
                } else {
                    M_Menu_Search_f()
                }
            } elif (lanConfig_cursor == 2) {
                m_return_state = int(m_state)
                m_return_onerror = 1u
                key_dest = 0u
                m_state = 0u
                Cbuf_AddText(va(719697, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 247472ul)]))
            }
        }
    } elif (key_2 == 127) {
        if (lanConfig_cursor == 0) {
            if (c2da_lin_strlen(247440) != 0x0) {
                let c2da_fresh9 : int = 247440 + int(c2da_lin_strlen(247440) - 1ul)
                let c2da_fresh10 : int8 = int8(0)
                c2da_mem[c2da_fresh9] = uint8(c2da_fresh10)
            }
        }
        if (lanConfig_cursor == 2) {
            if (c2da_lin_strlen(247472) != 0x0) {
                let c2da_fresh11 : int = 247472 + int(c2da_lin_strlen(247472) - 1ul)
                let c2da_fresh12 : int8 = int8(0)
                c2da_mem[c2da_fresh11] = uint8(c2da_fresh12)
            }
        }
    } elif (!(key_2 < 32 || key_2 > 127)) {
        if (lanConfig_cursor == 2) {
            l = int(c2da_lin_strlen(247472))
            if (l < 21) {
                let c2da_fresh13 : int8 = int8(0)
                c2da_mem[247472 + (l + 1)] = uint8(c2da_fresh13)
                let c2da_fresh14 : int8 = int8(key_2)
                c2da_mem[247472 + l] = uint8(c2da_fresh14)
            }
        }
        if (!(key_2 < 48 || key_2 > 57)) {
            if (lanConfig_cursor == 0) {
                l = int(c2da_lin_strlen(247440))
                if (l < 5) {
                    let c2da_fresh15 : int8 = int8(0)
                    c2da_mem[247440 + (l + 1)] = uint8(c2da_fresh15)
                    let c2da_fresh16 : int8 = int8(key_2)
                    c2da_mem[247440 + l] = uint8(c2da_fresh16)
                }
            }
        }
    }
    if (m_multiplayer_cursor == 1 && lanConfig_cursor == 2) {
        if (key_2 == 128) {
            lanConfig_cursor = 1
        } else {
            lanConfig_cursor = 0
        }
    }
    l = Q_atoi(247440)
    if (l > 65535) {
        l = lanConfig_port
    } else {
        lanConfig_port = l
    }
    c2da_lin_snprintf(247440, 2147483647ul, 719711, [C2daVaArg(tag = 1, i64 = int64(lanConfig_port), f64 = 0.0lf, raw = 0x0)])
    return
}
[export, sideeffects]
def M_Menu_GameOptions_f() {
    key_dest = 3u
    m_state = 16u
    m_entersound = 1u
    if (maxplayers == 0) {
        maxplayers = svs.maxclients
    }
    if (maxplayers < 2) {
        maxplayers = svs.maxclientslimit
    }
    return
}
[export, sideeffects]
def M_ConfigureNetSubsystem() {
    Cbuf_AddText(721609)
    if (m_net_cursor == 0 || m_net_cursor == 1) {
        Cbuf_AddText(721619)
    }
    if (m_net_cursor == 2 || m_net_cursor == 3) {
        net_hostport = lanConfig_port
    }
    return
}
[export, sideeffects]
def M_ModemConfig_Key(var key_3 : int) {
    var l_0 : int
    if (key_3 == 27) {
        M_Menu_SerialConfig_f()
    } elif (key_3 == 128) {
        S_LocalSound(719667)
        modemConfig_cursor--
        if (modemConfig_cursor < 0) {
            modemConfig_cursor = 5 - 1
        }
    } elif (key_3 == 129) {
        S_LocalSound(719667)
        modemConfig_cursor++
        if (modemConfig_cursor >= 5) {
            modemConfig_cursor = 0
        }
    } elif (key_3 == 130 || key_3 == 131) {
        if (modemConfig_cursor == 0) {
            if (int(int8(c2da_mem[247584])) == 80) {
                let c2da_fresh17 : int8 = int8(84)
                c2da_mem[247584] = uint8(c2da_fresh17)
            } else {
                let c2da_fresh18 : int8 = int8(80)
                c2da_mem[247584] = uint8(c2da_fresh18)
            }
            S_LocalSound(719667)
        }
    } elif (key_3 == 13) {
        if (modemConfig_cursor == 0) {
            if (int(int8(c2da_mem[247584])) == 80) {
                let c2da_fresh19 : int8 = int8(84)
                c2da_mem[247584] = uint8(c2da_fresh19)
            } else {
                let c2da_fresh20 : int8 = int8(80)
                c2da_mem[247584] = uint8(c2da_fresh20)
            }
            m_entersound = 1u
        }
        if (modemConfig_cursor == 4) {
            invoke(c2da_fn_table6[SetModemConfig], 0, va(721632, [C2daVaArg(tag = 1, i64 = int64(int8(c2da_mem[247584])), f64 = 0.0lf, raw = 0x0)]), 247504, 247520, 247552)
            m_entersound = 1u
            M_Menu_SerialConfig_f()
        }
    } elif (key_3 == 127) {
        if (modemConfig_cursor == 1) {
            if (c2da_lin_strlen(247504) != 0x0) {
                let c2da_fresh21 : int = 247504 + int(c2da_lin_strlen(247504) - 1ul)
                let c2da_fresh22 : int8 = int8(0)
                c2da_mem[c2da_fresh21] = uint8(c2da_fresh22)
            }
        }
        if (modemConfig_cursor == 2) {
            if (c2da_lin_strlen(247520) != 0x0) {
                let c2da_fresh23 : int = 247520 + int(c2da_lin_strlen(247520) - 1ul)
                let c2da_fresh24 : int8 = int8(0)
                c2da_mem[c2da_fresh23] = uint8(c2da_fresh24)
            }
        }
        if (modemConfig_cursor == 3) {
            if (c2da_lin_strlen(247552) != 0x0) {
                let c2da_fresh25 : int = 247552 + int(c2da_lin_strlen(247552) - 1ul)
                let c2da_fresh26 : int8 = int8(0)
                c2da_mem[c2da_fresh25] = uint8(c2da_fresh26)
            }
        }
    } elif (!(key_3 < 32 || key_3 > 127)) {
        if (modemConfig_cursor == 1) {
            l_0 = int(c2da_lin_strlen(247504))
            if (l_0 < 15) {
                let c2da_fresh27 : int8 = int8(0)
                c2da_mem[247504 + (l_0 + 1)] = uint8(c2da_fresh27)
                let c2da_fresh28 : int8 = int8(key_3)
                c2da_mem[247504 + l_0] = uint8(c2da_fresh28)
            }
        }
        if (modemConfig_cursor == 2) {
            l_0 = int(c2da_lin_strlen(247520))
            if (l_0 < 29) {
                let c2da_fresh29 : int8 = int8(0)
                c2da_mem[247520 + (l_0 + 1)] = uint8(c2da_fresh29)
                let c2da_fresh30 : int8 = int8(key_3)
                c2da_mem[247520 + l_0] = uint8(c2da_fresh30)
            }
        }
        if (modemConfig_cursor == 3) {
            l_0 = int(c2da_lin_strlen(247552))
            if (l_0 < 15) {
                let c2da_fresh31 : int8 = int8(0)
                c2da_mem[247552 + (l_0 + 1)] = uint8(c2da_fresh31)
                let c2da_fresh32 : int8 = int8(key_3)
                c2da_mem[247552 + l_0] = uint8(c2da_fresh32)
            }
        }
    }
    return
}
var modemConfig_cursor : int = default<int>

[export, sideeffects]
def M_SerialConfig_Key(var key_4 : int) {
    var l_1 : int
    if (key_4 < 128) {
        if (key_4 == 13) {
            goto label 54
        } elif (key_4 == 27) {
            goto label 14
        } elif (key_4 == 127) {
            goto label 61
        }
    } else {
        if (key_4 == 128) {
            goto label 15
        } elif (key_4 == 129) {
            goto label 18
        } elif (key_4 == 130) {
            goto label 21
        } elif (key_4 == 131) {
            goto label 37
        }
    }
    if (key_4 < 32 || key_4 > 127) {
        goto label 13
    }
    if (serialConfig_cursor == 4) {
        goto label 10
    }
    label 0:
    label 1:
    if (m_net_cursor == 1 && (serialConfig_cursor == 3 || serialConfig_cursor == 4)) {
        goto label 7
    }
    label 2:
    if (m_net_cursor == 0 && m_multiplayer_cursor == 1 && serialConfig_cursor == 4) {
        goto label 4
    }
    label 3:
    return
    label 4:
    if (key_4 == 128) {
        goto label 6
    }
    serialConfig_cursor = 5
    label 5:
    goto label 3
    label 6:
    serialConfig_cursor = 3
    goto label 5
    label 7:
    if (key_4 == 128) {
        goto label 9
    }
    serialConfig_cursor = 5
    label 8:
    goto label 2
    label 9:
    serialConfig_cursor = 2
    goto label 8
    label 10:
    l_1 = int(c2da_lin_strlen(247568))
    if (l_1 < 15) {
        goto label 12
    }
    label 11:
    goto label 0
    label 12:
    let c2da_fresh53 : int8 = int8(0)
    c2da_mem[247568 + (l_1 + 1)] = uint8(c2da_fresh53)
    let c2da_fresh54 : int8 = int8(key_4)
    c2da_mem[247568 + l_1] = uint8(c2da_fresh54)
    goto label 11
    label 13:
    goto label 1
    label 14:
    M_Menu_Net_f()
    goto label 1
    label 15:
    S_LocalSound(719667)
    serialConfig_cursor--
    if (serialConfig_cursor < 0) {
        goto label 17
    }
    label 16:
    goto label 1
    label 17:
    serialConfig_cursor = 6 - 1
    goto label 16
    label 18:
    S_LocalSound(719667)
    serialConfig_cursor++
    if (serialConfig_cursor >= 6) {
        goto label 20
    }
    label 19:
    goto label 1
    label 20:
    serialConfig_cursor = 0
    goto label 19
    label 21:
    if (serialConfig_cursor > 2) {
        goto label 36
    }
    S_LocalSound(719714)
    if (serialConfig_cursor == 0) {
        goto label 33
    }
    label 22:
    if (serialConfig_cursor == 1) {
        goto label 28
    }
    label 23:
    if (serialConfig_cursor == 2) {
        goto label 25
    }
    label 24:
    goto label 1
    label 25:
    serialConfig_baud--
    if (serialConfig_baud < 0) {
        goto label 27
    }
    label 26:
    goto label 24
    label 27:
    serialConfig_baud = 5
    goto label 26
    label 28:
    let c2da_fresh35 : int = int(uint(c2da_mem[247456]) | uint(c2da_mem[247457]) << 0x8 | uint(c2da_mem[247458]) << 0x10 | uint(c2da_mem[247459]) << 0x18)
    let c2da_fresh36 : int = c2da_fresh35 - 1
    let c2da_fresh37 : uint = uint(c2da_fresh36)
    c2da_mem[247456] = uint8(c2da_fresh37)
    c2da_mem[247457] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[247458] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[247459] = uint8(c2da_fresh37 >> 0x18)
    if (int(uint(c2da_mem[247456]) | uint(c2da_mem[247457]) << 0x8 | uint(c2da_mem[247458]) << 0x10 | uint(c2da_mem[247459]) << 0x18) == 6) {
        goto label 32
    }
    label 29:
    if (int(uint(c2da_mem[247456]) | uint(c2da_mem[247457]) << 0x8 | uint(c2da_mem[247458]) << 0x10 | uint(c2da_mem[247459]) << 0x18) == 1) {
        goto label 31
    }
    label 30:
    goto label 23
    label 31:
    let c2da_fresh40 : int = 7
    let c2da_fresh41 : uint = uint(c2da_fresh40)
    c2da_mem[247456] = uint8(c2da_fresh41)
    c2da_mem[247457] = uint8(c2da_fresh41 >> 0x8)
    c2da_mem[247458] = uint8(c2da_fresh41 >> 0x10)
    c2da_mem[247459] = uint8(c2da_fresh41 >> 0x18)
    goto label 30
    label 32:
    let c2da_fresh38 : int = 5
    let c2da_fresh39 : uint = uint(c2da_fresh38)
    c2da_mem[247456] = uint8(c2da_fresh39)
    c2da_mem[247457] = uint8(c2da_fresh39 >> 0x8)
    c2da_mem[247458] = uint8(c2da_fresh39 >> 0x10)
    c2da_mem[247459] = uint8(c2da_fresh39 >> 0x18)
    goto label 29
    label 33:
    serialConfig_comport--
    if (serialConfig_comport == 0) {
        goto label 35
    }
    label 34:
    let c2da_fresh33 : int = ISA_IRQs[serialConfig_comport - 1]
    let c2da_fresh34 : uint = uint(c2da_fresh33)
    c2da_mem[247456] = uint8(c2da_fresh34)
    c2da_mem[247457] = uint8(c2da_fresh34 >> 0x8)
    c2da_mem[247458] = uint8(c2da_fresh34 >> 0x10)
    c2da_mem[247459] = uint8(c2da_fresh34 >> 0x18)
    goto label 22
    label 35:
    serialConfig_comport = 4
    goto label 34
    label 36:
    goto label 1
    label 37:
    if (serialConfig_cursor > 2) {
        goto label 53
    }
    label 38:
    S_LocalSound(719714)
    if (serialConfig_cursor == 0) {
        goto label 50
    }
    label 39:
    if (serialConfig_cursor == 1) {
        goto label 45
    }
    label 40:
    if (serialConfig_cursor == 2) {
        goto label 42
    }
    label 41:
    goto label 1
    label 42:
    serialConfig_baud++
    if (serialConfig_baud > 5) {
        goto label 44
    }
    label 43:
    goto label 41
    label 44:
    serialConfig_baud = 0
    goto label 43
    label 45:
    let c2da_fresh44 : int = int(uint(c2da_mem[247456]) | uint(c2da_mem[247457]) << 0x8 | uint(c2da_mem[247458]) << 0x10 | uint(c2da_mem[247459]) << 0x18)
    let c2da_fresh45 : int = c2da_fresh44 + 1
    let c2da_fresh46 : uint = uint(c2da_fresh45)
    c2da_mem[247456] = uint8(c2da_fresh46)
    c2da_mem[247457] = uint8(c2da_fresh46 >> 0x8)
    c2da_mem[247458] = uint8(c2da_fresh46 >> 0x10)
    c2da_mem[247459] = uint8(c2da_fresh46 >> 0x18)
    if (int(uint(c2da_mem[247456]) | uint(c2da_mem[247457]) << 0x8 | uint(c2da_mem[247458]) << 0x10 | uint(c2da_mem[247459]) << 0x18) == 6) {
        goto label 49
    }
    label 46:
    if (int(uint(c2da_mem[247456]) | uint(c2da_mem[247457]) << 0x8 | uint(c2da_mem[247458]) << 0x10 | uint(c2da_mem[247459]) << 0x18) == 8) {
        goto label 48
    }
    label 47:
    goto label 40
    label 48:
    let c2da_fresh49 : int = 2
    let c2da_fresh50 : uint = uint(c2da_fresh49)
    c2da_mem[247456] = uint8(c2da_fresh50)
    c2da_mem[247457] = uint8(c2da_fresh50 >> 0x8)
    c2da_mem[247458] = uint8(c2da_fresh50 >> 0x10)
    c2da_mem[247459] = uint8(c2da_fresh50 >> 0x18)
    goto label 47
    label 49:
    let c2da_fresh47 : int = 7
    let c2da_fresh48 : uint = uint(c2da_fresh47)
    c2da_mem[247456] = uint8(c2da_fresh48)
    c2da_mem[247457] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[247458] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[247459] = uint8(c2da_fresh48 >> 0x18)
    goto label 46
    label 50:
    serialConfig_comport++
    if (serialConfig_comport > 4) {
        goto label 52
    }
    label 51:
    let c2da_fresh42 : int = ISA_IRQs[serialConfig_comport - 1]
    let c2da_fresh43 : uint = uint(c2da_fresh42)
    c2da_mem[247456] = uint8(c2da_fresh43)
    c2da_mem[247457] = uint8(c2da_fresh43 >> 0x8)
    c2da_mem[247458] = uint8(c2da_fresh43 >> 0x10)
    c2da_mem[247459] = uint8(c2da_fresh43 >> 0x18)
    goto label 39
    label 52:
    serialConfig_comport = 1
    goto label 51
    label 53:
    goto label 1
    label 54:
    if (serialConfig_cursor < 3) {
        goto label 60
    }
    m_entersound = 1u
    if (serialConfig_cursor == 3) {
        goto label 59
    }
    if (serialConfig_cursor == 4) {
        goto label 58
    }
    invoke(c2da_fn_table7[SetComPortConfig], 0, ISA_uarts[serialConfig_comport - 1], int(uint(c2da_mem[247456]) | uint(c2da_mem[247457]) << 0x8 | uint(c2da_mem[247458]) << 0x10 | uint(c2da_mem[247459]) << 0x18), serialConfig_baudrate[serialConfig_baud], uint(m_net_cursor == 0 ? 1 : 0))
    M_ConfigureNetSubsystem()
    if (m_multiplayer_cursor == 1) {
        goto label 57
    }
    m_return_state = int(m_state)
    m_return_onerror = 1u
    key_dest = 0u
    m_state = 0u
    if (m_net_cursor == 0) {
        goto label 56
    }
    Cbuf_AddText(721635)
    label 55:
    goto label 1
    label 56:
    Cbuf_AddText(va(719697, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 247568ul)]))
    goto label 55
    label 57:
    M_Menu_GameOptions_f()
    goto label 1
    label 58:
    serialConfig_cursor = 5
    goto label 1
    label 59:
    invoke(c2da_fn_table7[SetComPortConfig], 0, ISA_uarts[serialConfig_comport - 1], int(uint(c2da_mem[247456]) | uint(c2da_mem[247457]) << 0x8 | uint(c2da_mem[247458]) << 0x10 | uint(c2da_mem[247459]) << 0x18), serialConfig_baudrate[serialConfig_baud], uint(m_net_cursor == 0 ? 1 : 0))
    M_Menu_ModemConfig_f()
    goto label 1
    label 60:
    goto label 38
    label 61:
    if (serialConfig_cursor == 4) {
        goto label 63
    }
    label 62:
    goto label 1
    label 63:
    if (c2da_lin_strlen(247568) != 0x0) {
        goto label 65
    }
    label 64:
    goto label 62
    label 65:
    let c2da_fresh51 : int = 247568 + int(c2da_lin_strlen(247568) - 1ul)
    let c2da_fresh52 : int8 = int8(0)
    c2da_mem[c2da_fresh51] = uint8(c2da_fresh52)
    goto label 64
    panic("unreachable: fell out of a translated control-flow graph")
}
[export, sideeffects]
def M_Menu_ModemConfig_f() {
    key_dest = 3u
    m_state = 14u
    m_entersound = 1u
    invoke(c2da_fn_table6[GetModemConfig], 0, 247584, 247504, 247520, 247552)
    return
}
var private ISA_IRQs : int[4] = fixed_array<int>(4, 3, 4, 3)

[export, sideeffects]
def M_Quit_Key(var key_5 : int) {
    if (key_5 == 27 || key_5 == 110 || key_5 == 78) {
        if (wasInMenus != 0u) {
            m_state = uint(m_quit_prevstate)
            m_entersound = 1u
        } else {
            key_dest = 0u
            m_state = 0u
        }
    } elif (key_5 == 89 || key_5 == 121) {
        key_dest = 1u
        Host_Quit_f()
    }
    return
}
[export, sideeffects]
def M_Help_Key(var key_6 : int) {
    if (key_6 == 27) {
        M_Menu_Main_f()
    } elif (key_6 == 128 || key_6 == 131) {
        m_entersound = 1u
        help_page++
        if (help_page >= 6) {
            help_page = 0
        }
    } elif (key_6 == 129 || key_6 == 130) {
        m_entersound = 1u
        help_page--
        if (help_page < 0) {
            help_page = 6 - 1
        }
    }
    return
}
[export, sideeffects]
def M_Video_Key(var key_7 : int) {
    invoke(c2da_fn_table5[vid_menukeyfn], key_7)
    return
}
[export, sideeffects]
def M_Keys_Key(var k_1 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    M_Keys_Key_c2da_frame(k_1, c2da_lin_enter(96))
    c2da_lin_sp = c2da_saved_sp
}
var keys_cursor : int = default<int>

var bindnames : int[18][2] = fixed_array<int[2]>(fixed_array<int>(721660, 721668), fixed_array<int>(721675, 721686), fixed_array<int>(721700, 721706), fixed_array<int>(721721, 721730), fixed_array<int>(721743, 721749), fixed_array<int>(721759, 721765), fixed_array<int>(721775, 721782), fixed_array<int>(721793, 721800), fixed_array<int>(721804, 721814), fixed_array<int>(721824, 721835), fixed_array<int>(721846, 721854), fixed_array<int>(721863, 721871), fixed_array<int>(721879, 721889), fixed_array<int>(721899, 721910), fixed_array<int>(721922, 721929), fixed_array<int>(721940, 721947), fixed_array<int>(721961, 721969), fixed_array<int>(721977, 721987))

[export, sideeffects]
def M_UnbindCommand(var command : int) {
    var l_2 : int
    var b : int
    l_2 = int(c2da_lin_strlen(command))
    for (j_0 in range(0, 256)) {
        b = keybindings[j_0]
        if (b == 0) {
            continue
        }
        if (c2da_lin_strncmp(b, command, uint64(l_2)) == 0) {
            Key_SetBinding(j_0, 721997)
        }
    }
    return
}
var bind_grab : int = default<int>

[export, sideeffects]
def M_FindKeysForCommand(var command_0 : int; var twokeys : int) {
    var count_0 : int
    var l_3 : int
    var b_0 : int
    let c2da_fresh55 : int = -1
    let c2da_fresh56 : uint = uint(c2da_fresh55)
    c2da_mem[twokeys + 1 * 4] = uint8(c2da_fresh56)
    c2da_mem[twokeys + 1 * 4 + 1] = uint8(c2da_fresh56 >> 0x8)
    c2da_mem[twokeys + 1 * 4 + 2] = uint8(c2da_fresh56 >> 0x10)
    c2da_mem[twokeys + 1 * 4 + 3] = uint8(c2da_fresh56 >> 0x18)
    let c2da_fresh57 : uint = uint(c2da_fresh55)
    c2da_mem[twokeys + 0 * 4] = uint8(c2da_fresh57)
    c2da_mem[twokeys + 0 * 4 + 1] = uint8(c2da_fresh57 >> 0x8)
    c2da_mem[twokeys + 0 * 4 + 2] = uint8(c2da_fresh57 >> 0x10)
    c2da_mem[twokeys + 0 * 4 + 3] = uint8(c2da_fresh57 >> 0x18)
    l_3 = int(c2da_lin_strlen(command_0))
    count_0 = 0
    for (j_1 in range(0, 256)) {
        b_0 = keybindings[j_1]
        if (b_0 == 0) {
            continue
        }
        if (c2da_lin_strncmp(b_0, command_0, uint64(l_3)) == 0) {
            let c2da_fresh58 : uint = uint(j_1)
            c2da_mem[twokeys + count_0 * 4] = uint8(c2da_fresh58)
            c2da_mem[twokeys + count_0 * 4 + 1] = uint8(c2da_fresh58 >> 0x8)
            c2da_mem[twokeys + count_0 * 4 + 2] = uint8(c2da_fresh58 >> 0x10)
            c2da_mem[twokeys + count_0 * 4 + 3] = uint8(c2da_fresh58 >> 0x18)
            count_0++
            if (count_0 == 2) {
                break
            }
        }
    }
    return
}
[export, sideeffects]
def M_Options_Key(var k_2 : int) {
    if (k_2 == 27) {
        M_Menu_Main_f()
    } elif (k_2 == 13) {
        m_entersound = 1u
        if (options_cursor == 0) {
            M_Menu_Keys_f()
        } elif (options_cursor == 1) {
            m_state = 0u
            Con_ToggleConsole_f()
        } elif (options_cursor == 2) {
            Cbuf_AddText(721998)
        } elif (options_cursor == 12) {
            M_Menu_Video_f()
        } else {
            M_AdjustSliders(1)
        }
        return
    } elif (k_2 == 128) {
        S_LocalSound(719667)
        options_cursor--
        if (options_cursor < 0) {
            options_cursor = 13 - 1
        }
    } elif (k_2 == 129) {
        S_LocalSound(719667)
        options_cursor++
        if (options_cursor >= 13) {
            options_cursor = 0
        }
    } elif (k_2 == 130) {
        M_AdjustSliders(-1)
    } elif (k_2 == 131) {
        M_AdjustSliders(1)
    }
    if (options_cursor == 12 && vid_menudrawfn == 0) {
        if (k_2 == 128) {
            options_cursor = 11
        } else {
            options_cursor = 0
        }
    }
    return
}
var options_cursor : int = default<int>

[export, sideeffects]
def M_AdjustSliders(var dir_0 : int) {
    S_LocalSound(719714)
    if (options_cursor >= 3 && options_cursor <= 11) {
        goto options_cursor - 3
    }
    return
    label 0:
    let c2da_fresh59 : float = uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18) + float(dir_0 * 10)
    let c2da_fresh60 : uint = float_bits_to_uint(c2da_fresh59)
    c2da_mem[461176] = uint8(c2da_fresh60)
    c2da_mem[461177] = uint8(c2da_fresh60 >> 0x8)
    c2da_mem[461178] = uint8(c2da_fresh60 >> 0x10)
    c2da_mem[461179] = uint8(c2da_fresh60 >> 0x18)
    if (c2da_fresh59 < 30.0) {
        let c2da_fresh61 : float = 30.0
        let c2da_fresh62 : uint = float_bits_to_uint(c2da_fresh61)
        c2da_mem[461176] = uint8(c2da_fresh62)
        c2da_mem[461177] = uint8(c2da_fresh62 >> 0x8)
        c2da_mem[461178] = uint8(c2da_fresh62 >> 0x10)
        c2da_mem[461179] = uint8(c2da_fresh62 >> 0x18)
    }
    if (uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18) > 120.0) {
        let c2da_fresh63 : float = 120.0
        let c2da_fresh64 : uint = float_bits_to_uint(c2da_fresh63)
        c2da_mem[461176] = uint8(c2da_fresh64)
        c2da_mem[461177] = uint8(c2da_fresh64 >> 0x8)
        c2da_mem[461178] = uint8(c2da_fresh64 >> 0x10)
        c2da_mem[461179] = uint8(c2da_fresh64 >> 0x18)
    }
    Cvar_SetValue(722016, uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18))
    return
    label 1:
    let c2da_fresh65 : float = float(double(uint_bits_to_float(uint(c2da_mem[697064]) | uint(c2da_mem[697065]) << 0x8 | uint(c2da_mem[697066]) << 0x10 | uint(c2da_mem[697067]) << 0x18)) - double(dir_0) * 0.05lf)
    let c2da_fresh66 : uint = float_bits_to_uint(c2da_fresh65)
    c2da_mem[697064] = uint8(c2da_fresh66)
    c2da_mem[697065] = uint8(c2da_fresh66 >> 0x8)
    c2da_mem[697066] = uint8(c2da_fresh66 >> 0x10)
    c2da_mem[697067] = uint8(c2da_fresh66 >> 0x18)
    if (double(c2da_fresh65) < 0.5lf) {
        let c2da_fresh67 : float = 0.5
        let c2da_fresh68 : uint = float_bits_to_uint(c2da_fresh67)
        c2da_mem[697064] = uint8(c2da_fresh68)
        c2da_mem[697065] = uint8(c2da_fresh68 >> 0x8)
        c2da_mem[697066] = uint8(c2da_fresh68 >> 0x10)
        c2da_mem[697067] = uint8(c2da_fresh68 >> 0x18)
    }
    if (uint_bits_to_float(uint(c2da_mem[697064]) | uint(c2da_mem[697065]) << 0x8 | uint(c2da_mem[697066]) << 0x10 | uint(c2da_mem[697067]) << 0x18) > 1.0) {
        let c2da_fresh69 : float = 1.0
        let c2da_fresh70 : uint = float_bits_to_uint(c2da_fresh69)
        c2da_mem[697064] = uint8(c2da_fresh70)
        c2da_mem[697065] = uint8(c2da_fresh70 >> 0x8)
        c2da_mem[697066] = uint8(c2da_fresh70 >> 0x10)
        c2da_mem[697067] = uint8(c2da_fresh70 >> 0x18)
    }
    Cvar_SetValue(722025, uint_bits_to_float(uint(c2da_mem[697064]) | uint(c2da_mem[697065]) << 0x8 | uint(c2da_mem[697066]) << 0x10 | uint(c2da_mem[697067]) << 0x18))
    return
    label 2:
    let c2da_fresh71 : float = float(double(uint_bits_to_float(uint(c2da_mem[9832]) | uint(c2da_mem[9833]) << 0x8 | uint(c2da_mem[9834]) << 0x10 | uint(c2da_mem[9835]) << 0x18)) + double(dir_0) * 0.5lf)
    let c2da_fresh72 : uint = float_bits_to_uint(c2da_fresh71)
    c2da_mem[9832] = uint8(c2da_fresh72)
    c2da_mem[9833] = uint8(c2da_fresh72 >> 0x8)
    c2da_mem[9834] = uint8(c2da_fresh72 >> 0x10)
    c2da_mem[9835] = uint8(c2da_fresh72 >> 0x18)
    if (c2da_fresh71 < 1.0) {
        let c2da_fresh73 : float = 1.0
        let c2da_fresh74 : uint = float_bits_to_uint(c2da_fresh73)
        c2da_mem[9832] = uint8(c2da_fresh74)
        c2da_mem[9833] = uint8(c2da_fresh74 >> 0x8)
        c2da_mem[9834] = uint8(c2da_fresh74 >> 0x10)
        c2da_mem[9835] = uint8(c2da_fresh74 >> 0x18)
    }
    if (uint_bits_to_float(uint(c2da_mem[9832]) | uint(c2da_mem[9833]) << 0x8 | uint(c2da_mem[9834]) << 0x10 | uint(c2da_mem[9835]) << 0x18) > 11.0) {
        let c2da_fresh75 : float = 11.0
        let c2da_fresh76 : uint = float_bits_to_uint(c2da_fresh75)
        c2da_mem[9832] = uint8(c2da_fresh76)
        c2da_mem[9833] = uint8(c2da_fresh76 >> 0x8)
        c2da_mem[9834] = uint8(c2da_fresh76 >> 0x10)
        c2da_mem[9835] = uint8(c2da_fresh76 >> 0x18)
    }
    Cvar_SetValue(722031, uint_bits_to_float(uint(c2da_mem[9832]) | uint(c2da_mem[9833]) << 0x8 | uint(c2da_mem[9834]) << 0x10 | uint(c2da_mem[9835]) << 0x18))
    return
    label 3:
    bgmvolume.value = float(double(bgmvolume.value) + double(dir_0) * 0.1lf)
    if (bgmvolume.value < 0.0) {
        bgmvolume.value = 0.0
    }
    if (bgmvolume.value > 1.0) {
        bgmvolume.value = 1.0
    }
    Cvar_SetValue(722043, bgmvolume.value)
    return
    label 4:
    volume.value = float(double(volume.value) + double(dir_0) * 0.1lf)
    if (volume.value < 0.0) {
        volume.value = 0.0
    }
    if (volume.value > 1.0) {
        volume.value = 1.0
    }
    Cvar_SetValue(722053, volume.value)
    return
    label 5:
    if (uint_bits_to_float(uint(c2da_mem[9304]) | uint(c2da_mem[9305]) << 0x8 | uint(c2da_mem[9306]) << 0x10 | uint(c2da_mem[9307]) << 0x18) > 200.0) {
        Cvar_SetValue(722060, 200.0)
        Cvar_SetValue(722076, 200.0)
    } else {
        Cvar_SetValue(722060, 400.0)
        Cvar_SetValue(722076, 400.0)
    }
    return
    label 6:
    Cvar_SetValue(722089, -uint_bits_to_float(uint(c2da_mem[9880]) | uint(c2da_mem[9881]) << 0x8 | uint(c2da_mem[9882]) << 0x10 | uint(c2da_mem[9883]) << 0x18))
    return
    label 7:
    Cvar_SetValue(722097, uint_bits_to_float(uint(c2da_mem[9736]) | uint(c2da_mem[9737]) << 0x8 | uint(c2da_mem[9738]) << 0x10 | uint(c2da_mem[9739]) << 0x18) == 0.0 ? 1.0 : 0.0)
    return
    label 8:
    Cvar_SetValue(722108, uint_bits_to_float(uint(c2da_mem[9784]) | uint(c2da_mem[9785]) << 0x8 | uint(c2da_mem[9786]) << 0x10 | uint(c2da_mem[9787]) << 0x18) == 0.0 ? 1.0 : 0.0)
    return
}
[export, sideeffects]
def M_Setup_Key(var k_3 : int) {
    var l_4 : int
    if (k_3 < 128) {
        if (k_3 == 13) {
            goto label 38
        } elif (k_3 == 27) {
            goto label 18
        } elif (k_3 == 127) {
            goto label 47
        }
    } else {
        if (k_3 == 128) {
            goto label 19
        } elif (k_3 == 129) {
            goto label 22
        } elif (k_3 == 130) {
            goto label 25
        } elif (k_3 == 131) {
            goto label 31
        }
    }
    if (k_3 < 32 || k_3 > 127) {
        goto label 17
    }
    if (setup_cursor == 0) {
        goto label 14
    }
    label 0:
    if (setup_cursor == 1) {
        goto label 11
    }
    label 1:
    label 2:
    if (setup_top > 13) {
        goto label 10
    }
    label 3:
    if (setup_top < 0) {
        goto label 9
    }
    label 4:
    if (setup_bottom > 13) {
        goto label 8
    }
    label 5:
    if (setup_bottom < 0) {
        goto label 7
    }
    label 6:
    return
    label 7:
    setup_bottom = 13
    goto label 6
    label 8:
    setup_bottom = 0
    goto label 5
    label 9:
    setup_top = 13
    goto label 4
    label 10:
    setup_top = 0
    goto label 3
    label 11:
    l_4 = int(c2da_lin_strlen(246160))
    if (l_4 < 15) {
        goto label 13
    }
    label 12:
    goto label 1
    label 13:
    let c2da_fresh83 : int8 = int8(0)
    c2da_mem[246160 + (l_4 + 1)] = uint8(c2da_fresh83)
    let c2da_fresh84 : int8 = int8(k_3)
    c2da_mem[246160 + l_4] = uint8(c2da_fresh84)
    goto label 12
    label 14:
    l_4 = int(c2da_lin_strlen(246176))
    if (l_4 < 15) {
        goto label 16
    }
    label 15:
    goto label 0
    label 16:
    let c2da_fresh81 : int8 = int8(0)
    c2da_mem[246176 + (l_4 + 1)] = uint8(c2da_fresh81)
    let c2da_fresh82 : int8 = int8(k_3)
    c2da_mem[246176 + l_4] = uint8(c2da_fresh82)
    goto label 15
    label 17:
    goto label 2
    label 18:
    M_Menu_MultiPlayer_f()
    goto label 2
    label 19:
    S_LocalSound(719667)
    setup_cursor--
    if (setup_cursor < 0) {
        goto label 21
    }
    label 20:
    goto label 2
    label 21:
    setup_cursor = 5 - 1
    goto label 20
    label 22:
    S_LocalSound(719667)
    setup_cursor++
    if (setup_cursor >= 5) {
        goto label 24
    }
    label 23:
    goto label 2
    label 24:
    setup_cursor = 0
    goto label 23
    label 25:
    if (setup_cursor < 2) {
        goto label 30
    }
    S_LocalSound(719714)
    if (setup_cursor == 2) {
        goto label 29
    }
    label 26:
    if (setup_cursor == 3) {
        goto label 28
    }
    label 27:
    goto label 2
    label 28:
    setup_bottom--
    goto label 27
    label 29:
    setup_top--
    goto label 26
    label 30:
    return
    label 31:
    if (setup_cursor < 2) {
        goto label 37
    }
    label 32:
    S_LocalSound(719714)
    if (setup_cursor == 2) {
        goto label 36
    }
    label 33:
    if (setup_cursor == 3) {
        goto label 35
    }
    label 34:
    goto label 2
    label 35:
    setup_bottom++
    goto label 34
    label 36:
    setup_top++
    goto label 33
    label 37:
    return
    label 38:
    if (setup_cursor == 0 || setup_cursor == 1) {
        goto label 46
    }
    if (setup_cursor == 2 || setup_cursor == 3) {
        goto label 45
    }
    if (Q_strcmp(int(uint(c2da_mem[9144]) | uint(c2da_mem[9145]) << 0x8 | uint(c2da_mem[9146]) << 0x10 | uint(c2da_mem[9147]) << 0x18), 246160) != 0) {
        goto label 44
    }
    label 39:
    if (Q_strcmp(int(uint(c2da_mem[386472]) | uint(c2da_mem[386473]) << 0x8 | uint(c2da_mem[386474]) << 0x10 | uint(c2da_mem[386475]) << 0x18), 246176) != 0) {
        goto label 43
    }
    label 40:
    if (setup_top != setup_oldtop || setup_bottom != setup_oldbottom) {
        goto label 42
    }
    label 41:
    m_entersound = 1u
    M_Menu_MultiPlayer_f()
    goto label 2
    label 42:
    Cbuf_AddText(va(722139, [C2daVaArg(tag = 1, i64 = int64(setup_top), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(setup_bottom), f64 = 0.0lf, raw = 0x0)]))
    goto label 41
    label 43:
    Cvar_Set(722130, 246176)
    goto label 40
    label 44:
    Cbuf_AddText(va(722119, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 246160ul)]))
    goto label 39
    label 45:
    goto label 32
    label 46:
    return
    label 47:
    if (setup_cursor == 0) {
        goto label 53
    }
    label 48:
    if (setup_cursor == 1) {
        goto label 50
    }
    label 49:
    goto label 2
    label 50:
    if (c2da_lin_strlen(246160) != 0x0) {
        goto label 52
    }
    label 51:
    goto label 49
    label 52:
    let c2da_fresh79 : int = 246160 + int(c2da_lin_strlen(246160) - 1ul)
    let c2da_fresh80 : int8 = int8(0)
    c2da_mem[c2da_fresh79] = uint8(c2da_fresh80)
    goto label 51
    label 53:
    if (c2da_lin_strlen(246176) != 0x0) {
        goto label 55
    }
    label 54:
    goto label 48
    label 55:
    let c2da_fresh77 : int = 246176 + int(c2da_lin_strlen(246176) - 1ul)
    let c2da_fresh78 : int8 = int8(0)
    c2da_mem[c2da_fresh77] = uint8(c2da_fresh78)
    goto label 54
    panic("unreachable: fell out of a translated control-flow graph")
}
var setup_cursor : int = 4

[export, sideeffects]
def M_MultiPlayer_Key(var key_8 : int) {
    if (key_8 == 27) {
        M_Menu_Main_f()
    } elif (key_8 == 129) {
        S_LocalSound(719667)
        m_multiplayer_cursor++
        if (m_multiplayer_cursor >= 3) {
            m_multiplayer_cursor = 0
        }
    } elif (key_8 == 128) {
        S_LocalSound(719667)
        m_multiplayer_cursor--
        if (m_multiplayer_cursor < 0) {
            m_multiplayer_cursor = 3 - 1
        }
    } elif (key_8 == 13) {
        m_entersound = 1u
        if (m_multiplayer_cursor == 0) {
            if (uint(serialAvailable) != 0x0 || uint(ipxAvailable) != 0x0 || uint(tcpipAvailable) != 0x0) {
                M_Menu_Net_f()
            }
        } elif (m_multiplayer_cursor == 1) {
            if (uint(serialAvailable) != 0x0 || uint(ipxAvailable) != 0x0 || uint(tcpipAvailable) != 0x0) {
                M_Menu_Net_f()
            }
        } elif (m_multiplayer_cursor == 2) {
            M_Menu_Setup_f()
        }
    }
    return
}
[export, sideeffects]
def M_Save_Key(var k_4 : int) {
    if (k_4 == 27) {
        M_Menu_SinglePlayer_f()
    } elif (k_4 == 13) {
        m_state = 0u
        key_dest = 0u
        Cbuf_AddText(va(722152, [C2daVaArg(tag = 1, i64 = int64(load_cursor), f64 = 0.0lf, raw = 0x0)]))
        return
    } elif (k_4 == 128 || k_4 == 130) {
        S_LocalSound(719667)
        load_cursor--
        if (load_cursor < 0) {
            load_cursor = 12 - 1
        }
    } elif (k_4 == 129 || k_4 == 131) {
        S_LocalSound(719667)
        load_cursor++
        if (load_cursor >= 12) {
            load_cursor = 0
        }
    }
    return
}
var load_cursor : int = default<int>

[export, sideeffects]
def M_Load_Key(var k_5 : int) {
    if (k_5 == 27) {
        M_Menu_SinglePlayer_f()
    } elif (k_5 == 13) {
        S_LocalSound(719682)
        if (loadable[load_cursor] == 0) {
            return
        }
        m_state = 0u
        key_dest = 0u
        SCR_BeginLoadingPlaque()
        Cbuf_AddText(va(722162, [C2daVaArg(tag = 1, i64 = int64(load_cursor), f64 = 0.0lf, raw = 0x0)]))
        return
    } elif (k_5 == 128 || k_5 == 130) {
        S_LocalSound(719667)
        load_cursor--
        if (load_cursor < 0) {
            load_cursor = 12 - 1
        }
    } elif (k_5 == 129 || k_5 == 131) {
        S_LocalSound(719667)
        load_cursor++
        if (load_cursor >= 12) {
            load_cursor = 0
        }
    }
    return
}
[export, sideeffects]
def M_SinglePlayer_Key(var key_9 : int) {
    if (key_9 == 13) {
        goto label 3
    } elif (key_9 == 27) {
        goto label 0
    } elif (key_9 == 128) {
        goto label 2
    } elif (key_9 == 129) {
        goto label 1
    } else {
        return
    }
    label 0:
    M_Menu_Main_f()
    return
    label 1:
    S_LocalSound(719667)
    m_singleplayer_cursor++
    if (m_singleplayer_cursor >= 3) {
        m_singleplayer_cursor = 0
    }
    return
    label 2:
    S_LocalSound(719667)
    m_singleplayer_cursor--
    if (m_singleplayer_cursor < 0) {
        m_singleplayer_cursor = 3 - 1
    }
    return
    label 3:
    m_entersound = 1u
    if (m_singleplayer_cursor == 0) {
        goto label 4
    } elif (m_singleplayer_cursor == 1) {
        goto label 5
    } elif (m_singleplayer_cursor == 2) {
        goto label 6
    } else {
        return
    }
    label 4:
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) != 0u) {
        if (SCR_ModalMessage(722172) == 0) {
            return
        }
    }
    key_dest = 0u
    if ((uint(c2da_mem[225856]) | uint(c2da_mem[225857]) << 0x8 | uint(c2da_mem[225858]) << 0x10 | uint(c2da_mem[225859]) << 0x18) != 0u) {
        Cbuf_AddText(719729)
    }
    Cbuf_AddText(722216)
    Cbuf_AddText(722230)
    return
    label 5:
    M_Menu_Load_f()
    return
    label 6:
    M_Menu_Save_f()
    return
}
var m_singleplayer_cursor : int = default<int>

[export, sideeffects]
def M_Main_Key(var key_10 : int) {
    if (key_10 == 27) {
        key_dest = 0u
        m_state = 0u
        let c2da_fresh85 : uint = uint(m_save_demonum)
        c2da_mem[7636] = uint8(c2da_fresh85)
        c2da_mem[7637] = uint8(c2da_fresh85 >> 0x8)
        c2da_mem[7638] = uint8(c2da_fresh85 >> 0x10)
        c2da_mem[7639] = uint8(c2da_fresh85 >> 0x18)
        if (int(uint(c2da_mem[7636]) | uint(c2da_mem[7637]) << 0x8 | uint(c2da_mem[7638]) << 0x10 | uint(c2da_mem[7639]) << 0x18) != -1 && (uint(c2da_mem[7772]) | uint(c2da_mem[7773]) << 0x8 | uint(c2da_mem[7774]) << 0x10 | uint(c2da_mem[7775]) << 0x18) == 0u && (uint(c2da_mem[5520]) | uint(c2da_mem[5521]) << 0x8 | uint(c2da_mem[5522]) << 0x10 | uint(c2da_mem[5523]) << 0x18) != 2u) {
            CL_NextDemo()
        }
    } elif (key_10 == 129) {
        S_LocalSound(719667)
        m_main_cursor++
        if (m_main_cursor >= 5) {
            m_main_cursor = 0
        }
    } elif (key_10 == 128) {
        S_LocalSound(719667)
        m_main_cursor--
        if (m_main_cursor < 0) {
            m_main_cursor = 5 - 1
        }
    } elif (key_10 == 13) {
        m_entersound = 1u
        if (m_main_cursor == 0) {
            M_Menu_SinglePlayer_f()
        } elif (m_main_cursor == 1) {
            M_Menu_MultiPlayer_f()
        } elif (m_main_cursor == 2) {
            M_Menu_Options_f()
        } elif (m_main_cursor == 3) {
            M_Menu_Help_f()
        } elif (m_main_cursor == 4) {
            M_Menu_Quit_f()
        }
    }
    return
}
var m_main_cursor : int = default<int>

[export, sideeffects]
def M_Draw() {
    var c2da_fresh86 : uint
    if (m_state == 0u || uint(key_dest) != 3u) {
        return
    }
    if (m_recursiveDraw == 0u) {
        scr_copyeverything = 1
        if (scr_con_current != 0.0) {
            Draw_ConsoleBackground(int(vid.height))
            S_ExtraUpdate()
        } else {
            Draw_FadeScreen()
        }
        scr_fullupdate = 0
    } else {
        m_recursiveDraw = 0u
    }
    c2da_fresh86 = m_state
    if (c2da_fresh86 <= 0x12u) {
        goto int(c2da_fresh86) + 1
    }
    goto label 0
    label 1:
    goto label 0
    label 2:
    M_Main_Draw()
    goto label 0
    label 3:
    M_SinglePlayer_Draw()
    goto label 0
    label 4:
    M_Load_Draw()
    goto label 0
    label 5:
    M_Save_Draw()
    goto label 0
    label 6:
    M_MultiPlayer_Draw()
    goto label 0
    label 7:
    M_Setup_Draw()
    goto label 0
    label 8:
    M_Net_Draw()
    goto label 0
    label 9:
    M_Options_Draw()
    goto label 0
    label 11:
    M_Keys_Draw()
    goto label 0
    label 10:
    M_Video_Draw()
    goto label 0
    label 12:
    M_Help_Draw()
    goto label 0
    label 13:
    M_Quit_Draw()
    goto label 0
    label 14:
    M_SerialConfig_Draw()
    goto label 0
    label 15:
    M_ModemConfig_Draw()
    goto label 0
    label 16:
    M_LanConfig_Draw()
    goto label 0
    label 17:
    M_GameOptions_Draw()
    goto label 0
    label 18:
    M_Search_Draw()
    goto label 0
    label 19:
    M_ServerList_Draw()
    label 0:
    if (m_entersound != 0u) {
        S_LocalSound(719682)
        m_entersound = 0u
    }
    S_ExtraUpdate()
    return
}
[export, sideeffects]
def M_ServerList_Draw() {
    let c2da_saved_sp : int = c2da_lin_sp
    M_ServerList_Draw_c2da_frame(c2da_lin_enter(160))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def M_PrintWhite(var cx : int; var cy : int; var str : int) {
    while (int8(c2da_mem[str]) != 0) {
        M_DrawCharacter(cx, cy, int(int8(c2da_mem[str])))
        str++
        cx += 8
    }
    return
}
[export, sideeffects]
def M_DrawCharacter(var cx_0 : int; var line : int; var num : int) {
    Draw_Character(int(uint(cx_0) + (vid.width - 320u >> 1u)), line, num)
    return
}
[export, sideeffects]
def M_Print(var cx_1 : int; var cy_0 : int; var str_0 : int) {
    while (int8(c2da_mem[str_0]) != 0) {
        M_DrawCharacter(cx_1, cy_0, int(int8(c2da_mem[str_0])) + 128)
        str_0++
        cx_1 += 8
    }
    return
}
[export, sideeffects]
def M_DrawPic(var x : int; var y : int; var pic : int) {
    Draw_Pic(int(uint(x) + (vid.width - 320u >> 1u)), y, pic)
    return
}
[export, sideeffects]
def M_Search_Draw() {
    var p_0 : int
    var x_0 : int
    p_0 = Draw_CachePic(722241)
    M_DrawPic((320 - int(uint(c2da_mem[p_0]) | uint(c2da_mem[p_0 + 1]) << 0x8 | uint(c2da_mem[p_0 + 2]) << 0x10 | uint(c2da_mem[p_0 + 3]) << 0x18)) / 2, 4, p_0)
    x_0 = 320 / 2 - 12 * 8 / 2 + 4
    M_DrawTextBox(x_0 - 8, 32, 12, 1)
    M_Print(x_0, 40, 722303)
    if (uint(slistInProgress) != 0u) {
        NET_Poll()
        return
    }
    if (searchComplete == 0u) {
        searchComplete = 1u
        searchCompleteTime = realtime
    }
    if (hostCacheCount != 0) {
        M_Menu_ServerList_f()
        return
    }
    M_PrintWhite(320 / 2 - 22 * 8 / 2, 64, 722316)
    if (realtime - searchCompleteTime < 3.0lf) {
        return
    }
    M_Menu_LanConfig_f()
    return
}
var searchCompleteTime : double = default<double>

[export, sideeffects]
def M_Menu_ServerList_f() {
    key_dest = 3u
    m_state = 18u
    m_entersound = 1u
    slist_cursor = 0
    m_return_onerror = 0u
    let c2da_fresh87 : int8 = int8(0)
    c2da_mem[247600 + 0] = uint8(c2da_fresh87)
    slist_sorted = 0u
    return
}
[export, sideeffects]
def M_DrawTextBox(var x_1 : int; var y_0 : int; var width : int; var lines : int) {
    var p_1 : int
    var cx_2 : int
    var cy_1 : int
    var n_1 : int
    cx_2 = x_1
    cy_1 = y_0
    p_1 = Draw_CachePic(722339)
    M_DrawTransPic(cx_2, cy_1, p_1)
    p_1 = Draw_CachePic(722354)
    n_1 = 0
    while (n_1 < lines) {
        cy_1 += 8
        M_DrawTransPic(cx_2, cy_1, p_1)
        n_1++
    }
    p_1 = Draw_CachePic(722369)
    M_DrawTransPic(cx_2, cy_1 + 8, p_1)
    cx_2 += 8
    while (width > 0) {
        cy_1 = y_0
        p_1 = Draw_CachePic(722384)
        M_DrawTransPic(cx_2, cy_1, p_1)
        p_1 = Draw_CachePic(722399)
        n_1 = 0
        while (n_1 < lines) {
            cy_1 += 8
            if (n_1 == 1) {
                p_1 = Draw_CachePic(722414)
            }
            M_DrawTransPic(cx_2, cy_1, p_1)
            n_1++
        }
        p_1 = Draw_CachePic(722430)
        M_DrawTransPic(cx_2, cy_1 + 8, p_1)
        width -= 2
        cx_2 += 16
    }
    cy_1 = y_0
    p_1 = Draw_CachePic(722445)
    M_DrawTransPic(cx_2, cy_1, p_1)
    p_1 = Draw_CachePic(722460)
    n_1 = 0
    for (c2da_n_1 in range(n_1, lines)) {
        cy_1 += 8
        M_DrawTransPic(cx_2, cy_1, p_1)
    }
    p_1 = Draw_CachePic(722475)
    M_DrawTransPic(cx_2, cy_1 + 8, p_1)
    return
}
[export, sideeffects]
def M_DrawTransPic(var x_2 : int; var y_1 : int; var pic_0 : int) {
    Draw_TransPic(int(uint(x_2) + (vid.width - 320u >> 1u)), y_1, pic_0)
    return
}
[export, sideeffects]
def M_GameOptions_Draw() {
    var c2da_fresh88 : int
    var c2da_fresh89 : int
    var p_2 : int
    var x_3 : int
    var msg : int
    var msg_0 : int
    M_DrawTransPic(16, 4, Draw_CachePic(722490))
    p_2 = Draw_CachePic(722241)
    M_DrawPic((320 - int(uint(c2da_mem[p_2]) | uint(c2da_mem[p_2 + 1]) << 0x8 | uint(c2da_mem[p_2 + 2]) << 0x10 | uint(c2da_mem[p_2 + 3]) << 0x18)) / 2, 4, p_2)
    M_DrawTextBox(152, 32, 10, 1)
    M_Print(160, 40, 722506)
    M_Print(0, 56, 722517)
    M_Print(160, 56, va(722535, [C2daVaArg(tag = 1, i64 = int64(maxplayers), f64 = 0.0lf, raw = 0x0)]))
    M_Print(0, 64, 722538)
    if (uint_bits_to_float(uint(c2da_mem[243752]) | uint(c2da_mem[243753]) << 0x8 | uint(c2da_mem[243754]) << 0x10 | uint(c2da_mem[243755]) << 0x18) != 0.0) {
        M_Print(160, 64, 722556)
    } else {
        M_Print(160, 64, 722568)
    }
    M_Print(0, 72, 722579)
    if (uint(rogue) != 0u) {
        c2da_fresh88 = int(uint_bits_to_float(uint(c2da_mem[243464]) | uint(c2da_mem[243465]) << 0x8 | uint(c2da_mem[243466]) << 0x10 | uint(c2da_mem[243467]) << 0x18))
        if (c2da_fresh88 == 1) {
            msg = 722596
        } elif (c2da_fresh88 == 2) {
            msg = 722613
        } elif (c2da_fresh88 == 3) {
            msg = 722627
        } elif (c2da_fresh88 == 4) {
            msg = 722631
        } elif (c2da_fresh88 == 5) {
            msg = 722648
        } elif (c2da_fresh88 == 6) {
            msg = 722661
        } else {
            msg = 722676
        }
        M_Print(160, 72, msg)
    } else {
        c2da_fresh89 = int(uint_bits_to_float(uint(c2da_mem[243464]) | uint(c2da_mem[243465]) << 0x8 | uint(c2da_mem[243466]) << 0x10 | uint(c2da_mem[243467]) << 0x18))
        if (c2da_fresh89 == 1) {
            msg_0 = 722596
        } elif (c2da_fresh89 == 2) {
            msg_0 = 722613
        } else {
            msg_0 = 722676
        }
        M_Print(160, 72, msg_0)
    }
    M_Print(0, 80, 722680)
    if (uint_bits_to_float(uint(c2da_mem[243608]) | uint(c2da_mem[243609]) << 0x8 | uint(c2da_mem[243610]) << 0x10 | uint(c2da_mem[243611]) << 0x18) == 0.0) {
        M_Print(160, 80, 722698)
    } elif (uint_bits_to_float(uint(c2da_mem[243608]) | uint(c2da_mem[243609]) << 0x8 | uint(c2da_mem[243610]) << 0x10 | uint(c2da_mem[243611]) << 0x18) == 1.0) {
        M_Print(160, 80, 722714)
    } elif (uint_bits_to_float(uint(c2da_mem[243608]) | uint(c2da_mem[243609]) << 0x8 | uint(c2da_mem[243610]) << 0x10 | uint(c2da_mem[243611]) << 0x18) == 2.0) {
        M_Print(160, 80, 722732)
    } else {
        M_Print(160, 80, 722748)
    }
    M_Print(0, 88, 722769)
    if (uint_bits_to_float(uint(c2da_mem[243368]) | uint(c2da_mem[243369]) << 0x8 | uint(c2da_mem[243370]) << 0x10 | uint(c2da_mem[243371]) << 0x18) == 0.0) {
        M_Print(160, 88, 722787)
    } else {
        M_Print(160, 88, va(722792, [C2daVaArg(tag = 1, i64 = int64(int(uint_bits_to_float(uint(c2da_mem[243368]) | uint(c2da_mem[243369]) << 0x8 | uint(c2da_mem[243370]) << 0x10 | uint(c2da_mem[243371]) << 0x18))), f64 = 0.0lf, raw = 0x0)]))
    }
    M_Print(0, 96, 722801)
    if (uint_bits_to_float(uint(c2da_mem[243416]) | uint(c2da_mem[243417]) << 0x8 | uint(c2da_mem[243418]) << 0x10 | uint(c2da_mem[243419]) << 0x18) == 0.0) {
        M_Print(160, 96, 722787)
    } else {
        M_Print(160, 96, va(722819, [C2daVaArg(tag = 1, i64 = int64(int(uint_bits_to_float(uint(c2da_mem[243416]) | uint(c2da_mem[243417]) << 0x8 | uint(c2da_mem[243418]) << 0x10 | uint(c2da_mem[243419]) << 0x18))), f64 = 0.0lf, raw = 0x0)]))
    }
    M_Print(0, 112, 722830)
    if (uint(hipnotic) != 0u) {
        M_Print(160, 112, hipnoticepisodes[startepisode].description)
    } elif (uint(rogue) != 0u) {
        M_Print(160, 112, rogueepisodes[startepisode].description)
    } else {
        M_Print(160, 112, episodes[startepisode].description)
    }
    M_Print(0, 120, 722847)
    if (uint(hipnotic) != 0u) {
        M_Print(160, 120, hipnoticlevels[hipnoticepisodes[startepisode].firstLevel + startlevel].description)
        M_Print(160, 128, hipnoticlevels[hipnoticepisodes[startepisode].firstLevel + startlevel].name)
    } elif (uint(rogue) != 0u) {
        M_Print(160, 120, roguelevels[rogueepisodes[startepisode].firstLevel + startlevel].description)
        M_Print(160, 128, roguelevels[rogueepisodes[startepisode].firstLevel + startlevel].name)
    } else {
        M_Print(160, 120, levels[episodes[startepisode].firstLevel + startlevel].description)
        M_Print(160, 128, levels[episodes[startepisode].firstLevel + startlevel].name)
    }
    M_DrawCharacter(144, gameoptions_cursor_table[gameoptions_cursor], 12 + (int(realtime * 4.0lf) & 1))
    if (m_serverInfoMessage != 0u) {
        if (realtime - m_serverInfoMessageTime < 5.0lf) {
            x_3 = (320 - 26 * 8) / 2
            M_DrawTextBox(x_3, 138, 24, 4)
            x_3 += 8
            M_Print(x_3, 146, 722864)
            M_Print(x_3, 154, 722889)
            M_Print(x_3, 162, 722914)
            M_Print(x_3, 170, 722939)
        } else {
            m_serverInfoMessage = 0u
        }
    }
    return
}
var gameoptions_cursor_table : int[9] = fixed_array<int>(40, 56, 64, 72, 80, 88, 96, 112, 120)

[export, sideeffects]
def M_LanConfig_Draw() {
    var p_3 : int
    var basex : int
    var startJoin : int
    var protocol : int
    M_DrawTransPic(16, 4, Draw_CachePic(722490))
    p_3 = Draw_CachePic(722241)
    basex = (320 - int(uint(c2da_mem[p_3]) | uint(c2da_mem[p_3 + 1]) << 0x8 | uint(c2da_mem[p_3 + 2]) << 0x10 | uint(c2da_mem[p_3 + 3]) << 0x18)) / 2
    M_DrawPic(basex, 4, p_3)
    if (m_multiplayer_cursor == 1) {
        startJoin = 722964
    } else {
        startJoin = 722973
    }
    if (m_net_cursor == 2) {
        protocol = 722983
    } else {
        protocol = 722987
    }
    M_Print(basex, 32, va(722994, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(startJoin)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(protocol))]))
    basex += 8
    M_Print(basex, 52, 723002)
    if (m_net_cursor == 2) {
        M_Print(basex + 9 * 8, 52, 243088)
    } else {
        M_Print(basex + 9 * 8, 52, 243024)
    }
    M_Print(basex, lanConfig_cursor_table[0], 723011)
    M_DrawTextBox(basex + 8 * 8, lanConfig_cursor_table[0] - 8, 6, 1)
    M_Print(basex + 9 * 8, lanConfig_cursor_table[0], 247440)
    if (m_multiplayer_cursor == 0) {
        M_Print(basex, lanConfig_cursor_table[1], 723016)
        M_Print(basex, 108, 723042)
        M_DrawTextBox(basex + 8, lanConfig_cursor_table[2] - 8, 22, 1)
        M_Print(basex + 16, lanConfig_cursor_table[2], 247472)
    } else {
        M_DrawTextBox(basex, lanConfig_cursor_table[1] - 8, 2, 1)
        M_Print(basex + 8, lanConfig_cursor_table[1], 723056)
    }
    M_DrawCharacter(basex - 8, lanConfig_cursor_table[lanConfig_cursor], 12 + (int(realtime * 4.0lf) & 1))
    if (lanConfig_cursor == 0) {
        M_DrawCharacter(int(uint64(basex + 9 * 8) + 8ul * c2da_lin_strlen(247440)), lanConfig_cursor_table[0], 10 + (int(realtime * 4.0lf) & 1))
    }
    if (lanConfig_cursor == 2) {
        M_DrawCharacter(int(uint64(basex + 16) + 8ul * c2da_lin_strlen(247472)), lanConfig_cursor_table[2], 10 + (int(realtime * 4.0lf) & 1))
    }
    if (int8(c2da_mem[247600]) != 0) {
        M_PrintWhite(basex, 148, 247600)
    }
    return
}
var lanConfig_cursor_table : int[3] = fixed_array<int>(72, 92, 124)

[export, sideeffects]
def M_ModemConfig_Draw() {
    var p_4 : int
    var basex_0 : int
    M_DrawTransPic(16, 4, Draw_CachePic(722490))
    p_4 = Draw_CachePic(722241)
    basex_0 = (320 - int(uint(c2da_mem[p_4]) | uint(c2da_mem[p_4 + 1]) << 0x8 | uint(c2da_mem[p_4 + 2]) << 0x10 | uint(c2da_mem[p_4 + 3]) << 0x18)) / 2
    M_DrawPic(basex_0, 4, p_4)
    basex_0 += 8
    if (int(int8(c2da_mem[247584])) == 80) {
        M_Print(basex_0, modemConfig_cursor_table[0], 723059)
    } else {
        M_Print(basex_0, modemConfig_cursor_table[0], 723073)
    }
    M_Print(basex_0, modemConfig_cursor_table[1], 723092)
    M_DrawTextBox(basex_0, modemConfig_cursor_table[1] + 4, 16, 1)
    M_Print(basex_0 + 8, modemConfig_cursor_table[1] + 12, 247504)
    if (modemConfig_cursor == 1) {
        M_DrawCharacter(int(uint64(basex_0 + 8) + 8ul * c2da_lin_strlen(247504)), modemConfig_cursor_table[1] + 12, 10 + (int(realtime * 4.0lf) & 1))
    }
    M_Print(basex_0, modemConfig_cursor_table[2], 723098)
    M_DrawTextBox(basex_0, modemConfig_cursor_table[2] + 4, 30, 1)
    M_Print(basex_0 + 8, modemConfig_cursor_table[2] + 12, 247520)
    if (modemConfig_cursor == 2) {
        M_DrawCharacter(int(uint64(basex_0 + 8) + 8ul * c2da_lin_strlen(247520)), modemConfig_cursor_table[2] + 12, 10 + (int(realtime * 4.0lf) & 1))
    }
    M_Print(basex_0, modemConfig_cursor_table[3], 723103)
    M_DrawTextBox(basex_0, modemConfig_cursor_table[3] + 4, 16, 1)
    M_Print(basex_0 + 8, modemConfig_cursor_table[3] + 12, 247552)
    if (modemConfig_cursor == 3) {
        M_DrawCharacter(int(uint64(basex_0 + 8) + 8ul * c2da_lin_strlen(247552)), modemConfig_cursor_table[3] + 12, 10 + (int(realtime * 4.0lf) & 1))
    }
    M_DrawTextBox(basex_0, modemConfig_cursor_table[4] - 8, 2, 1)
    M_Print(basex_0 + 8, modemConfig_cursor_table[4], 723056)
    M_DrawCharacter(basex_0 - 8, modemConfig_cursor_table[modemConfig_cursor], 12 + (int(realtime * 4.0lf) & 1))
    return
}
var modemConfig_cursor_table : int[5] = fixed_array<int>(40, 56, 88, 120, 156)

[export, sideeffects]
def M_SerialConfig_Draw() {
    var p_5 : int
    var basex_1 : int
    var startJoin_0 : int
    var directModem : int
    M_DrawTransPic(16, 4, Draw_CachePic(722490))
    p_5 = Draw_CachePic(722241)
    basex_1 = (320 - int(uint(c2da_mem[p_5]) | uint(c2da_mem[p_5 + 1]) << 0x8 | uint(c2da_mem[p_5 + 2]) << 0x10 | uint(c2da_mem[p_5 + 3]) << 0x18)) / 2
    M_DrawPic(basex_1, 4, p_5)
    if (m_multiplayer_cursor == 1) {
        startJoin_0 = 722964
    } else {
        startJoin_0 = 722973
    }
    if (m_net_cursor == 0) {
        directModem = 723110
    } else {
        directModem = 723116
    }
    M_Print(basex_1, 32, va(722994, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(startJoin_0)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(directModem))]))
    basex_1 += 8
    M_Print(basex_1, serialConfig_cursor_table[0], 723011)
    M_DrawTextBox(160, 40, 4, 1)
    M_Print(168, serialConfig_cursor_table[0], va(723131, [C2daVaArg(tag = 1, i64 = int64(serialConfig_comport), f64 = 0.0lf, raw = 0x0)]))
    M_Print(basex_1, serialConfig_cursor_table[1], 723137)
    M_DrawTextBox(160, serialConfig_cursor_table[1] - 8, 1, 1)
    M_Print(168, serialConfig_cursor_table[1], va(719711, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[247456]) | uint(c2da_mem[247457]) << 0x8 | uint(c2da_mem[247458]) << 0x10 | uint(c2da_mem[247459]) << 0x18)), f64 = 0.0lf, raw = 0x0)]))
    M_Print(basex_1, serialConfig_cursor_table[2], 723141)
    M_DrawTextBox(160, serialConfig_cursor_table[2] - 8, 5, 1)
    M_Print(168, serialConfig_cursor_table[2], va(719711, [C2daVaArg(tag = 1, i64 = int64(serialConfig_baudrate[serialConfig_baud]), f64 = 0.0lf, raw = 0x0)]))
    if (m_net_cursor == 0) {
        M_Print(basex_1, serialConfig_cursor_table[3], 723146)
        if (m_multiplayer_cursor == 0) {
            M_Print(basex_1, serialConfig_cursor_table[4], 723161)
            M_DrawTextBox(160, serialConfig_cursor_table[4] - 8, 16, 1)
            M_Print(168, serialConfig_cursor_table[4], 247568)
        }
    }
    if (m_multiplayer_cursor == 0) {
        M_DrawTextBox(basex_1, serialConfig_cursor_table[5] - 8, 7, 1)
        M_Print(basex_1 + 8, serialConfig_cursor_table[5], 723174)
    } else {
        M_DrawTextBox(basex_1, serialConfig_cursor_table[5] - 8, 2, 1)
        M_Print(basex_1 + 8, serialConfig_cursor_table[5], 723056)
    }
    M_DrawCharacter(basex_1 - 8, serialConfig_cursor_table[serialConfig_cursor], 12 + (int(realtime * 4.0lf) & 1))
    if (serialConfig_cursor == 4) {
        M_DrawCharacter(int(168ul + 8ul * c2da_lin_strlen(247568)), serialConfig_cursor_table[serialConfig_cursor], 10 + (int(realtime * 4.0lf) & 1))
    }
    if (int8(c2da_mem[247600]) != 0) {
        M_PrintWhite(basex_1, 148, 247600)
    }
    return
}
var serialConfig_cursor_table : int[6] = fixed_array<int>(48, 64, 80, 96, 112, 132)

[export, sideeffects]
def M_Quit_Draw() {
    if (wasInMenus != 0u) {
        m_state = uint(m_quit_prevstate)
        m_recursiveDraw = 1u
        M_Draw()
        m_state = 12u
    }
    M_DrawTextBox(56, 76, 24, 4)
    M_Print(64, 84, quitMessage[msgNumber * 4 + 0])
    M_Print(64, 92, quitMessage[msgNumber * 4 + 1])
    M_Print(64, 100, quitMessage[msgNumber * 4 + 2])
    M_Print(64, 108, quitMessage[msgNumber * 4 + 3])
    return
}
var quitMessage : int[32] = fixed_array<int>(723182, 723207, 723232, 723257, 723282, 723307, 723332, 723257, 723357, 723382, 723407, 723257, 723432, 723457, 723482, 723507, 723532, 723557, 723582, 723607, 723632, 723657, 723682, 723707, 723732, 723757, 723782, 723807, 723832, 723857, 723882, 723257)

var m_recursiveDraw : uint = default<uint>

[export, sideeffects]
def M_Help_Draw() {
    M_DrawPic(0, 0, Draw_CachePic(va(723907, [C2daVaArg(tag = 1, i64 = int64(help_page), f64 = 0.0lf, raw = 0x0)])))
    return
}
[export, sideeffects]
def M_Video_Draw() {
    invoke(c2da_fn_table0[vid_menudrawfn])
    return
}
[export, sideeffects]
def M_Keys_Draw() {
    let c2da_saved_sp : int = c2da_lin_sp
    M_Keys_Draw_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def M_Options_Draw() {
    var r : float
    var p_7 : int
    M_DrawTransPic(16, 4, Draw_CachePic(722490))
    p_7 = Draw_CachePic(724020)
    M_DrawPic((320 - int(uint(c2da_mem[p_7]) | uint(c2da_mem[p_7 + 1]) << 0x8 | uint(c2da_mem[p_7 + 2]) << 0x10 | uint(c2da_mem[p_7 + 3]) << 0x18)) / 2, 4, p_7)
    M_Print(16, 32, 724037)
    M_Print(16, 40, 724060)
    M_Print(16, 48, 724083)
    M_Print(16, 56, 724106)
    r = (uint_bits_to_float(uint(c2da_mem[461176]) | uint(c2da_mem[461177]) << 0x8 | uint(c2da_mem[461178]) << 0x10 | uint(c2da_mem[461179]) << 0x18) - 30.0) / float(120 - 30)
    M_DrawSlider(220, 56, r)
    M_Print(16, 64, 724129)
    r = float((1.0lf - double(uint_bits_to_float(uint(c2da_mem[697064]) | uint(c2da_mem[697065]) << 0x8 | uint(c2da_mem[697066]) << 0x10 | uint(c2da_mem[697067]) << 0x18))) / 0.5lf)
    M_DrawSlider(220, 64, r)
    M_Print(16, 72, 724152)
    r = (uint_bits_to_float(uint(c2da_mem[9832]) | uint(c2da_mem[9833]) << 0x8 | uint(c2da_mem[9834]) << 0x10 | uint(c2da_mem[9835]) << 0x18) - 1.0) / 10.0
    M_DrawSlider(220, 72, r)
    M_Print(16, 80, 724175)
    r = bgmvolume.value
    M_DrawSlider(220, 80, r)
    M_Print(16, 88, 724198)
    r = volume.value
    M_DrawSlider(220, 88, r)
    M_Print(16, 96, 724221)
    M_DrawCheckbox(220, 96, uint_bits_to_float(uint(c2da_mem[9304]) | uint(c2da_mem[9305]) << 0x8 | uint(c2da_mem[9306]) << 0x10 | uint(c2da_mem[9307]) << 0x18) > 200.0 ? 1 : 0)
    M_Print(16, 104, 724244)
    M_DrawCheckbox(220, 104, uint_bits_to_float(uint(c2da_mem[9880]) | uint(c2da_mem[9881]) << 0x8 | uint(c2da_mem[9882]) << 0x10 | uint(c2da_mem[9883]) << 0x18) < 0.0 ? 1 : 0)
    M_Print(16, 112, 724267)
    M_DrawCheckbox(220, 112, int(uint_bits_to_float(uint(c2da_mem[9736]) | uint(c2da_mem[9737]) << 0x8 | uint(c2da_mem[9738]) << 0x10 | uint(c2da_mem[9739]) << 0x18)))
    M_Print(16, 120, 724290)
    M_DrawCheckbox(220, 120, int(uint_bits_to_float(uint(c2da_mem[9784]) | uint(c2da_mem[9785]) << 0x8 | uint(c2da_mem[9786]) << 0x10 | uint(c2da_mem[9787]) << 0x18)))
    if (vid_menudrawfn != default<int>) {
        M_Print(16, 128, 724313)
    }
    M_DrawCharacter(200, 32 + options_cursor * 8, 12 + (int(realtime * 4.0lf) & 1))
    return
}
[export, sideeffects]
def M_DrawCheckbox(var x_5 : int; var y_3 : int; var on : int) {
    if (on != 0) {
        M_Print(x_5, y_3, 724336)
    } else {
        M_Print(x_5, y_3, 724339)
    }
    return
}
[export, sideeffects]
def M_DrawSlider(var x_6 : int; var y_4 : int; var range_0 : float) {
    var i_2 : int
    if (range_0 < 0.0) {
        range_0 = 0.0
    }
    if (range_0 > 1.0) {
        range_0 = 1.0
    }
    M_DrawCharacter(x_6 - 8, y_4, 128)
    i_2 = 0
    while (i_2 < 10) {
        M_DrawCharacter(x_6 + i_2 * 8, y_4, 129)
        i_2++
    }
    M_DrawCharacter(x_6 + i_2 * 8, y_4, 130)
    M_DrawCharacter(int(float(x_6) + float((10 - 1) * 8) * range_0), y_4, 131)
    return
}
[export, sideeffects]
def M_Net_Draw() {
    var f_0 : int
    var p_8 : int
    M_DrawTransPic(16, 4, Draw_CachePic(722490))
    p_8 = Draw_CachePic(722241)
    M_DrawPic((320 - int(uint(c2da_mem[p_8]) | uint(c2da_mem[p_8 + 1]) << 0x8 | uint(c2da_mem[p_8 + 2]) << 0x10 | uint(c2da_mem[p_8 + 3]) << 0x18)) / 2, 4, p_8)
    f_0 = 32
    if (uint(serialAvailable) != 0u) {
        p_8 = Draw_CachePic(724343)
    } else {
        p_8 = Draw_CachePic(724359)
    }
    if (p_8 != 0) {
        M_DrawTransPic(72, f_0, p_8)
    }
    f_0 += 19
    if (uint(serialAvailable) != 0u) {
        p_8 = Draw_CachePic(724376)
    } else {
        p_8 = Draw_CachePic(724392)
    }
    if (p_8 != 0) {
        M_DrawTransPic(72, f_0, p_8)
    }
    f_0 += 19
    if (uint(ipxAvailable) != 0u) {
        p_8 = Draw_CachePic(724409)
    } else {
        p_8 = Draw_CachePic(724425)
    }
    M_DrawTransPic(72, f_0, p_8)
    f_0 += 19
    if (uint(tcpipAvailable) != 0u) {
        p_8 = Draw_CachePic(724441)
    } else {
        p_8 = Draw_CachePic(724457)
    }
    M_DrawTransPic(72, f_0, p_8)
    if (m_net_items == 5) {
        f_0 += 19
        p_8 = Draw_CachePic(724473)
        M_DrawTransPic(72, f_0, p_8)
    }
    f_0 = (320 - 26 * 8) / 2
    M_DrawTextBox(f_0, 134, 24, 4)
    f_0 += 8
    M_Print(f_0, 142, net_helpMessage[m_net_cursor * 4 + 0])
    M_Print(f_0, 150, net_helpMessage[m_net_cursor * 4 + 1])
    M_Print(f_0, 158, net_helpMessage[m_net_cursor * 4 + 2])
    M_Print(f_0, 166, net_helpMessage[m_net_cursor * 4 + 3])
    f_0 = int(host_time * 10.0lf) % 6
    M_DrawTransPic(54, 32 + m_net_cursor * 20, Draw_CachePic(va(724489, [C2daVaArg(tag = 1, i64 = int64(f_0 + 1), f64 = 0.0lf, raw = 0x0)])))
    return
}
var net_helpMessage : int[16] = fixed_array<int>(723257, 724507, 724532, 723257, 723257, 724507, 724557, 723257, 724582, 724607, 723257, 724632, 724657, 724682, 724707, 724732)

[export, sideeffects]
def M_Setup_Draw() {
    var p_9 : int
    M_DrawTransPic(16, 4, Draw_CachePic(722490))
    p_9 = Draw_CachePic(722241)
    M_DrawPic((320 - int(uint(c2da_mem[p_9]) | uint(c2da_mem[p_9 + 1]) << 0x8 | uint(c2da_mem[p_9 + 2]) << 0x10 | uint(c2da_mem[p_9 + 3]) << 0x18)) / 2, 4, p_9)
    M_Print(64, 40, 724757)
    M_DrawTextBox(160, 32, 16, 1)
    M_Print(168, 40, 246176)
    M_Print(64, 56, 724766)
    M_DrawTextBox(160, 48, 16, 1)
    M_Print(168, 56, 246160)
    M_Print(64, 80, 724776)
    M_Print(64, 104, 724788)
    M_DrawTextBox(64, 140 - 8, 14, 1)
    M_Print(72, 140, 724800)
    p_9 = Draw_CachePic(724815)
    M_DrawTransPic(160, 64, p_9)
    p_9 = Draw_CachePic(724830)
    M_BuildTranslationTable(setup_top * 16, setup_bottom * 16)
    M_DrawTransPicTranslate(172, 72, p_9)
    M_DrawCharacter(56, setup_cursor_table[setup_cursor], 12 + (int(realtime * 4.0lf) & 1))
    if (setup_cursor == 0) {
        M_DrawCharacter(int(168ul + 8ul * c2da_lin_strlen(246176)), setup_cursor_table[setup_cursor], 10 + (int(realtime * 4.0lf) & 1))
    }
    if (setup_cursor == 1) {
        M_DrawCharacter(int(168ul + 8ul * c2da_lin_strlen(246160)), setup_cursor_table[setup_cursor], 10 + (int(realtime * 4.0lf) & 1))
    }
    return
}
var setup_cursor_table : int[5] = fixed_array<int>(40, 56, 80, 104, 140)

[export, sideeffects]
def M_DrawTransPicTranslate(var x_7 : int; var y_5 : int; var pic_1 : int) {
    Draw_TransPicTranslate(int(uint(x_7) + (vid.width - 320u >> 1u)), y_5, pic_1, 247632)
    return
}
[export, sideeffects]
def M_BuildTranslationTable(var top : int; var bottom : int) {
    var j_3 : int
    var dest : int
    var source : int
    j_3 = 0
    while (j_3 < 256) {
        let c2da_fresh92 : uint8 = uint8(j_3)
        c2da_mem[247888 + j_3] = c2da_fresh92
        j_3++
    }
    dest = 247632
    source = 247888
    c2da_lin_memcpy(dest, source, 256ul)
    if (top < 128) {
        c2da_lin_memcpy(dest + 16, source + top, 16ul)
    } else {
        j_3 = 0
        while (j_3 < 16) {
            let c2da_fresh93 : uint8 = c2da_mem[source + (top + 15 - j_3)]
            c2da_mem[dest + (16 + j_3)] = c2da_fresh93
            j_3++
        }
    }
    if (bottom < 128) {
        c2da_lin_memcpy(dest + 96, source + bottom, 16ul)
    } else {
        j_3 = 0
        for (c2da_j_3 in range(j_3, 16)) {
            let c2da_fresh94 : uint8 = c2da_mem[source + (bottom + 15 - c2da_j_3)]
            c2da_mem[dest + (96 + c2da_j_3)] = c2da_fresh94
        }
    }
    return
}
[export, sideeffects]
def M_MultiPlayer_Draw() {
    var f_1 : int
    var p_10 : int
    M_DrawTransPic(16, 4, Draw_CachePic(722490))
    p_10 = Draw_CachePic(722241)
    M_DrawPic((320 - int(uint(c2da_mem[p_10]) | uint(c2da_mem[p_10 + 1]) << 0x8 | uint(c2da_mem[p_10 + 2]) << 0x10 | uint(c2da_mem[p_10 + 3]) << 0x18)) / 2, 4, p_10)
    M_DrawTransPic(72, 32, Draw_CachePic(724847))
    f_1 = int(host_time * 10.0lf) % 6
    M_DrawTransPic(54, 32 + m_multiplayer_cursor * 20, Draw_CachePic(va(724489, [C2daVaArg(tag = 1, i64 = int64(f_1 + 1), f64 = 0.0lf, raw = 0x0)])))
    if (uint(serialAvailable) != 0x0 || uint(ipxAvailable) != 0x0 || uint(tcpipAvailable) != 0x0) {
        return
    }
    M_PrintWhite(320 / 2 - 27 * 8 / 2, 148, 724863)
    return
}
[export, sideeffects]
def M_Save_Draw() {
    var p_11 : int = Draw_CachePic(724891)
    M_DrawPic((320 - int(uint(c2da_mem[p_11]) | uint(c2da_mem[p_11 + 1]) << 0x8 | uint(c2da_mem[p_11 + 2]) << 0x10 | uint(c2da_mem[p_11 + 3]) << 0x18)) / 2, 4, p_11)
    for (i_3 in range(0, 12)) {
        M_Print(16, 32 + 8 * i_3, 246192 + i_3 * 40)
    }
    M_DrawCharacter(8, 32 + load_cursor * 8, 12 + (int(realtime * 4.0lf) & 1))
    return
}
[export, sideeffects]
def M_Load_Draw() {
    var p_12 : int = Draw_CachePic(724906)
    M_DrawPic((320 - int(uint(c2da_mem[p_12]) | uint(c2da_mem[p_12 + 1]) << 0x8 | uint(c2da_mem[p_12 + 2]) << 0x10 | uint(c2da_mem[p_12 + 3]) << 0x18)) / 2, 4, p_12)
    for (i_4 in range(0, 12)) {
        M_Print(16, 32 + 8 * i_4, 246192 + i_4 * 40)
    }
    M_DrawCharacter(8, 32 + load_cursor * 8, 12 + (int(realtime * 4.0lf) & 1))
    return
}
[export, sideeffects]
def M_SinglePlayer_Draw() {
    var f_2 : int
    var p_13 : int
    M_DrawTransPic(16, 4, Draw_CachePic(722490))
    p_13 = Draw_CachePic(724921)
    M_DrawPic((320 - int(uint(c2da_mem[p_13]) | uint(c2da_mem[p_13 + 1]) << 0x8 | uint(c2da_mem[p_13 + 2]) << 0x10 | uint(c2da_mem[p_13 + 3]) << 0x18)) / 2, 4, p_13)
    M_DrawTransPic(72, 32, Draw_CachePic(724937))
    f_2 = int(host_time * 10.0lf) % 6
    M_DrawTransPic(54, 32 + m_singleplayer_cursor * 20, Draw_CachePic(va(724489, [C2daVaArg(tag = 1, i64 = int64(f_2 + 1), f64 = 0.0lf, raw = 0x0)])))
    return
}
[export, sideeffects]
def M_Main_Draw() {
    var f_3 : int
    var p_14 : int
    M_DrawTransPic(16, 4, Draw_CachePic(722490))
    p_14 = Draw_CachePic(724953)
    M_DrawPic((320 - int(uint(c2da_mem[p_14]) | uint(c2da_mem[p_14 + 1]) << 0x8 | uint(c2da_mem[p_14 + 2]) << 0x10 | uint(c2da_mem[p_14 + 3]) << 0x18)) / 2, 4, p_14)
    M_DrawTransPic(72, 32, Draw_CachePic(724970))
    f_3 = int(host_time * 10.0lf) % 6
    M_DrawTransPic(54, 32 + m_main_cursor * 20, Draw_CachePic(va(724489, [C2daVaArg(tag = 1, i64 = int64(f_3 + 1), f64 = 0.0lf, raw = 0x0)])))
    return
}
var m_net_saveHeight : int = default<int>

[sideeffects]
def private M_ScanSaves_c2da_frame(c2da_fp : int) {
    var f : int
    for (i in range(0, 12)) {
        c2da_lin_strcpy(246192 + i * 40, 719624)
        loadable[i] = 0
        c2da_lin_snprintf(c2da_fp, 2147483647ul, 719644, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 5392ul), C2daVaArg(tag = 1, i64 = int64(i), f64 = 0.0lf, raw = 0x0)])
        f = c2da_lin_fopen(c2da_fp, 719655)
        if (f == 0) {
            continue
        }
        c2da_lin_fscanf(uint64(f), 719657, [c2da_fp + 128])
        c2da_lin_fscanf(uint64(f), 719661, [c2da_fp])
        c2da_lin_strncpy(246192 + i * 40, c2da_fp, 40ul - 1ul)
        for (j in range(0, 39)) {
            if (int(int8(c2da_mem[246192 + i * 40 + j])) == 95) {
                let c2da_fresh1 : int8 = int8(32)
                c2da_mem[246192 + i * 40 + j] = uint8(c2da_fresh1)
            }
        }
        loadable[i] = 1
        c2da_std_fclose(uint64(f))
    }
    return
}
[sideeffects]
def private M_Menu_SerialConfig_f_c2da_frame(c2da_fp : int) {
    var n : int
    key_dest = 3u
    m_state = 13u
    m_entersound = 1u
    if (m_multiplayer_cursor == 0 && m_net_cursor == 0) {
        serialConfig_cursor = 4
    } else {
        serialConfig_cursor = 5
    }
    invoke(c2da_fn_table6[GetComPortConfig], 0, c2da_fp, 247456, c2da_fp + 16, c2da_fp + 32)
    n = 0
    while (n < 4) {
        if (ISA_uarts[n] == int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18)) {
            break
        }
        n++
    }
    if (n == 4) {
        n = 0
        let c2da_fresh6 : int = 4
        let c2da_fresh7 : uint = uint(c2da_fresh6)
        c2da_mem[247456] = uint8(c2da_fresh7)
        c2da_mem[247457] = uint8(c2da_fresh7 >> 0x8)
        c2da_mem[247458] = uint8(c2da_fresh7 >> 0x10)
        c2da_mem[247459] = uint8(c2da_fresh7 >> 0x18)
    }
    serialConfig_comport = n + 1
    n = 0
    while (n < 6) {
        if (serialConfig_baudrate[n] == int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18)) {
            break
        }
        n++
    }
    if (n == 6) {
        n = 5
    }
    serialConfig_baud = n
    m_return_onerror = 0u
    let c2da_fresh8 : int8 = int8(0)
    c2da_mem[247600 + 0] = uint8(c2da_fresh8)
    return
}
[sideeffects]
def private M_Keys_Key_c2da_frame(var k_1 : int; c2da_fp : int) {
    if (bind_grab != 0) {
        S_LocalSound(719667)
        if (k_1 == 27) {
            bind_grab = 0
        } elif (k_1 != 96) {
            c2da_lin_snprintf(c2da_fp, 2147483647ul, 721644, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(Key_KeynumToString(k_1))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(bindnames[keys_cursor][0]))])
            Cbuf_InsertText(c2da_fp)
        }
        bind_grab = 0
        return
    }
    if (k_1 == 27) {
        M_Menu_Options_f()
    } elif (k_1 == 130 || k_1 == 128) {
        S_LocalSound(719667)
        keys_cursor--
        if (keys_cursor < 0) {
            keys_cursor = int(288ul / 16ul - 1ul)
        }
    } elif (k_1 == 129 || k_1 == 131) {
        S_LocalSound(719667)
        keys_cursor++
        if (uint64(keys_cursor) >= 288ul / 16ul) {
            keys_cursor = 0
        }
    } elif (k_1 == 13) {
        M_FindKeysForCommand(bindnames[keys_cursor][0], c2da_fp + 80)
        S_LocalSound(719682)
        if (int(uint(c2da_mem[c2da_fp + 80 + 1 * 4]) | uint(c2da_mem[c2da_fp + 80 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 80 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 80 + 1 * 4 + 3]) << 0x18) != -1) {
            M_UnbindCommand(bindnames[keys_cursor][0])
        }
        bind_grab = 1
    } elif (k_1 == 127 || k_1 == 148) {
        S_LocalSound(719682)
        M_UnbindCommand(bindnames[keys_cursor][0])
    }
    return
}
[sideeffects]
def private M_ServerList_Draw_c2da_frame(c2da_fp : int) {
    var n_0 : int
    var p : int
    var i_0 : int
    var j_2 : int
    if (slist_sorted == 0u) {
        if (hostCacheCount > 1) {
            i_0 = 0
            while (i_0 < hostCacheCount) {
                j_2 = i_0 + 1
                while (j_2 < hostCacheCount) {
                    if (c2da_lin_strcmp(246672 + j_2 * 96, 246672 + i_0 * 96) < 0) {
                        Q_memcpy(c2da_fp, 246672 + j_2 * 96, 96)
                        Q_memcpy(246672 + j_2 * 96, 246672 + i_0 * 96, 96)
                        Q_memcpy(246672 + i_0 * 96, c2da_fp, 96)
                    }
                    j_2++
                }
                i_0++
            }
        }
        slist_sorted = 1u
    }
    p = Draw_CachePic(722241)
    M_DrawPic((320 - int(uint(c2da_mem[p]) | uint(c2da_mem[p + 1]) << 0x8 | uint(c2da_mem[p + 2]) << 0x10 | uint(c2da_mem[p + 3]) << 0x18)) / 2, 4, p)
    n_0 = 0
    while (n_0 < hostCacheCount) {
        if (int(uint(c2da_mem[246672 + n_0 * 96 + 68]) | uint(c2da_mem[246672 + n_0 * 96 + 69]) << 0x8 | uint(c2da_mem[246672 + n_0 * 96 + 70]) << 0x10 | uint(c2da_mem[246672 + n_0 * 96 + 71]) << 0x18) != 0) {
            c2da_lin_snprintf(c2da_fp + 96, 2147483647ul, 722257, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(246672 + n_0 * 96)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(246672 + n_0 * 96 + 16)), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[246672 + n_0 * 96 + 64]) | uint(c2da_mem[246672 + n_0 * 96 + 65]) << 0x8 | uint(c2da_mem[246672 + n_0 * 96 + 66]) << 0x10 | uint(c2da_mem[246672 + n_0 * 96 + 67]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[246672 + n_0 * 96 + 68]) | uint(c2da_mem[246672 + n_0 * 96 + 69]) << 0x8 | uint(c2da_mem[246672 + n_0 * 96 + 70]) << 0x10 | uint(c2da_mem[246672 + n_0 * 96 + 71]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
        } else {
            c2da_lin_snprintf(c2da_fp + 96, 2147483647ul, 722284, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(246672 + n_0 * 96)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(246672 + n_0 * 96 + 16))])
        }
        M_Print(16, 32 + 8 * n_0, c2da_fp + 96)
        n_0++
    }
    M_DrawCharacter(0, 32 + slist_cursor * 8, 12 + (int(realtime * 4.0lf) & 1))
    if (int8(c2da_mem[247600]) != 0) {
        M_PrintWhite(16, 148, 247600)
    }
    return
}
[sideeffects]
def private M_Keys_Draw_c2da_frame(c2da_fp : int) {
    var i_1 : int
    var l_5 : int
    var name : int
    var x_4 : int
    var y_2 : int
    var p_6 : int = Draw_CachePic(723922)
    M_DrawPic((320 - int(uint(c2da_mem[p_6]) | uint(c2da_mem[p_6 + 1]) << 0x8 | uint(c2da_mem[p_6 + 2]) << 0x10 | uint(c2da_mem[p_6 + 3]) << 0x18)) / 2, 4, p_6)
    if (bind_grab != 0) {
        M_Print(12, 32, 723939)
    } else {
        M_Print(18, 32, 723977)
    }
    i_1 = 0
    while (uint64(i_1) < 288ul / 16ul) {
        y_2 = 48 + 8 * i_1
        M_Print(16, y_2, bindnames[i_1][1])
        l_5 = int(c2da_lin_strlen(bindnames[i_1][0]))
        M_FindKeysForCommand(bindnames[i_1][0], c2da_fp)
        let c2da_fresh90 : int = int(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)
        if (c2da_fresh90 == -1) {
            M_Print(140, y_2, 724013)
        } else {
            name = Key_KeynumToString(int(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18))
            M_Print(140, y_2, name)
            x_4 = int(c2da_lin_strlen(name) * 8ul)
            let c2da_fresh91 : int = int(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)
            if (c2da_fresh91 != -1) {
                M_Print(140 + x_4 + 8, y_2, 724017)
                M_Print(140 + x_4 + 32, y_2, Key_KeynumToString(int(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)))
            }
        }
        i_1++
    }
    if (bind_grab != 0) {
        M_DrawCharacter(130, 48 + keys_cursor * 8, 61)
    } else {
        M_DrawCharacter(130, 48 + keys_cursor * 8, 12 + (int(realtime * 4.0lf) & 1))
    }
    return
}

// This unit's static data, at heap offset 719488.
let private c2da_lin_static_menu_seg = fixed_array<int>(719488, 5498)
let private c2da_lin_static_menu = fixed_array<uint64>(0x656d656c67676f74ul, 0x5f756e656d00756eul, 0x6e656d006e69616dul, 0x656c676e69735f75ul, 0x6d00726579616c70ul, 0x64616f6c5f756e65ul, 0x61735f756e656d00ul, 0x5f756e656d006576ul, 0x616c7069746c756dul, 0x756e656d00726579ul, 0x6d0070757465735ful, 0x6974706f5f756e65ul, 0x756e656d00736e6ful, 0x656d007379656b5ful, 0x6f656469765f756eul, 0x656d00706c656800ul, 0x746975715f756eul, 0x53554e55202d2d2dul, 0x20544f4c53204445ul, 0x732f7325002d2d2dul, 0x72007661732e6925ul, 0x393725000a692500ul, 0x2f6373696d000a73ul, 0x61772e31756e656dul, 0x6d2f6373696d0076ul, 0x7661772e32756e65ul, 0x7463656e6e6f6300ul, 0x25000a2273252220ul, 0x6d2f6373696d0075ul, 0x7661772e33756e65ul, 0x6e6e6f6373696400ul, 0x73696c000a746365ul, 0x6d000a30206e6574ul, 0x726579616c707861ul, 0x616d000a75252073ul, 0x6f63000a73252070ul, 0x706d61657400706ful, 0x6c696b730079616cul, 0x696c67617266006cul, 0x656d69740074696dul, 0x65570074696d696cul, 0x6f7420656d6f636cul, 0x4400656b61755120ul, 0x69442064656d6f6ful, 0x6e6f69736e656dul, 0x666f206d6c616552ul, 0x4d206b63616c4220ul, 0x74654e0063696761ul, 0x646c726f77726568ul, 0x646c452065685400ul, 0x646c726f57207265ul, 0x4c206c616e694600ul, 0x616544006c657665ul, 0x20686374616d6874ul, 0x6e4900616e657241ul, 0x69746375646f7274ul, 0x276c6c6548006e6ful, 0x657274726f462073ul, 0x6972726f43007373ul, 0x20666f2073726f64ul, 0x6f635300656d6954ul, 0x20666f2065677275ul, 0x6e6f67616d7241ul, 0x7373657274726f46ul, 0x2065687420666f20ul, 0x6d6f440064616544ul, 0x666f206e6f696e69ul, 0x73656e6b72614420ul, 0x6952206568540073ul, 0x7472617473007466ul, 0x636e6172746e4500ul, 0x5300316d31650065ul, 0x206574616770696cul, 0x78656c706d6f43ul, 0x73614300326d3165ul, 0x7420666f20656c74ul, 0x656e6d6144206568ul, 0x5400336d31650064ul, 0x6f7263654e206568ul, 0x31650073696c6f70ul, 0x472065685400346dul, 0x724720796c736972ul, 0x6d3165006f74746ful, 0x206d6f6f6c470035ul, 0x6d3165007065654bul, 0x6f44206568540036ul, 0x6843206f5420726ful, 0x6d3165006e6f6874ul, 0x6f48206568540037ul, 0x4320666f20657375ul, 0x3165006e6f687468ul, 0x756767695a00386dul, 0x7472655620746172ul, 0x316d3265006f6769ul, 0x736e492065685400ul, 0x6f6974616c6c6174ul, 0x4f00326d3265006eul, 0x6174694320657267ul, 0x336d3265006c6564ul, 0x6f20747079724300ul, 0x79616365442066ul, 0x65685400346d3265ul, 0x6f46206e6f624520ul, 0x6500737365727472ul, 0x2065685400356d32ul, 0x73276472617a6957ul, 0x650065736e614d20ul, 0x2065685400366d32ul, 0x4f206c616d736944ul, 0x65747465696c6275ul, 0x6e5500376d326500ul, 0x6874726165726564ul, 0x655400316d336500ul, 0x6f6974616e696d72ul, 0x6172746e6543206eul, 0x5400326d3365006cul, 0x746c756156206568ul, 0x6e695a20666f2073ul, 0x685400336d336500ul, 0x6f20626d6f542065ul, 0x726f727265542066ul, 0x615300346d336500ul, 0x61442073276e6174ul, 0x67696c6544206b72ul, 0x356d3365007468ul, 0x6e755420646e6957ul, 0x6d336500736c656eul, 0x65626d6168430036ul, 0x6f5420666f207372ul, 0x336500746e656d72ul, 0x482065685400376dul, 0x48206465746e7561ul, 0x6d346500736c6c61ul, 0x6553206568540031ul, 0x7379532065676177ul, 0x326d3465006d6574ul, 0x776f542065685400ul, 0x654420666f207265ul, 0x3465007269617073ul, 0x452065685400336dul, 0x646f47207265646cul, 0x656e6972685320ul, 0x65685400346d3465ul, 0x206563616c615020ul, 0x6574614820666ful, 0x6c654800356d3465ul, 0x697274412073276cul, 0x366d3465006d75ul, 0x6e69615020656854ul, 0x346500657a614d20ul, 0x6572757a4100376dul, 0x6500796e6f674120ul, 0x2065685400386d34ul, 0x7373656c656d614eul, 0x6e65007974694320ul, 0x4e2d627568530064ul, 0x6874617275676769ul, 0x6400746950207327ul, 0x6563616c5000316dul, 0x206f775420666f20ul, 0x6400736874616544ul, 0x7375616c4300326dul, 0x6f626f68706f7274ul, 0x6d640073696c6f70ul, 0x6241206568540033ul, 0x2064656e6f646e61ul, 0x346d640065736142ul, 0x6461422065685400ul, 0x64006563616c5020ul, 0x432065685400356dul, 0x64006e7265747369ul, 0x442065685400366dul, 0x656e6f5a206b7261ul, 0x442074696c705300ul, 0x6e6f6973696365ul, 0x76654400316d3172ul, 0x44207327746e6169ul, 0x3172006e69616d6ful, 0x646165724400326dul, 0x6c6174726f5020ul, 0x64754a00336d3172ul, 0x4320746e656d6567ul, 0x346d3172006c6c61ul, 0x666f206576614300ul, 0x7200687461654420ul, 0x65776f5400356d31ul, 0x725720666f207372ul, 0x366d317200687461ul, 0x20656c706d655400ul, 0x6e69615020666ful, 0x6d6f5400376d3172ul, 0x65687420666f2062ul, 0x726f6c7265764f20ul, 0x5400316d32720064ul, 0x7546207375706d65ul, 0x326d327200746967ul, 0x746e656d656c4500ul, 0x2079727546206c61ul, 0x4500336d32720049ul, 0x6c61746e656d656cul, 0x4949207972754620ul, 0x754300346d327200ul, 0x4f20666f20657372ul, 0x3272007369726973ul, 0x72617a695700356dul, 0x7065654b20732764ul, 0x6c4200366d327200ul, 0x7263615320646f6ful, 0x3272006563696669ul, 0x207473614c00376dul, 0x6e6f6974736142ul, 0x756f5300386d3272ul, 0x4520666f20656372ul, 0x31667463006c6976ul, 0x6f69736976694400ul, 0x61684320666f206eul, 0x6d6d6f430065676eul, 0x6800514820646e61ul, 0x685400316d317069ul, 0x6e69706d75502065ul, 0x6f69746174532067ul, 0x326d31706968006eul, 0x656761726f745300ul, 0x74696c6963614620ul, 0x336d317069680079ul, 0x736f4c2065685400ul, 0x6800656e694d2074ul, 0x655200346d317069ul, 0x4620686372616573ul, 0x7974696c696361ul, 0x4d00356d31706968ul, 0x2079726174696c69ul, 0x78656c706d6f43ul, 0x4100316d32706968ul, 0x5220746e6569636eul, 0x696800736d6c6165ul, 0x65685400326d3270ul, 0x43206b63616c4220ul, 0x6c61726465687461ul, 0x336d3270696800ul, 0x6174614320656854ul, 0x69680073626d6f63ul, 0x65685400346d3270ul, 0x6800747079724320ul, 0x6f4d00356d327069ul, 0x4b2073276d757472ul, 0x3270696800706565ul, 0x472065685400366dul, 0x73276e696c6d6572ul, 0x6e69616d6f4420ul, 0x5400316d33706968ul, 0x656d726f54207275ul, 0x6d3370696800746eul, 0x6d65646e61500032ul, 0x6968006d75696e6ful, 0x6d694c00336d3370ul, 0x6d33706968006f62ul, 0x6147206568540034ul, 0x680074656c746e75ul, 0x724100646e657069ul, 0x2073276e6f67616dul, 0x706968007269614cul, 0x2065685400316d64ul, 0x20666f2065676445ul, 0x6e6f6976696c624ful, 0x6d6564706f747300ul, 0x20316d6f63000a6ful, 0xa656c62616e65ul, 0x656e6e6f63006325ul, 0x646e6962000a7463ul, 0x2522202273252220ul, 0x7474612b000a2273ul, 0x61747461006b6361ul, 0x6c75706d69006b63ul, 0x6863003031206573ul, 0x6165772065676e61ul, 0x6d756a2b006e6f70ul, 0x2f20706d756a0070ul, 0x7075206d69777320ul, 0x726177726f662b00ul, 0x66206b6c61770064ul, 0x2b0064726177726ful, 0x636162006b636162ul, 0x2b006c616465706bul, 0x727574007466656cul, 0x2b007466656c206eul, 0x7574007468676972ul, 0x7468676972206e72ul, 0x64656570732b00ul, 0x766f6d2b006e7572ul, 0x7473007466656c65ul, 0x7466656c207065ul, 0x67697265766f6d2bul, 0x2070657473007468ul, 0x732b007468676972ul, 0x6973006566617274ul, 0x2b00706574736564ul, 0x6c0070756b6f6f6cul, 0x2b007075206b6f6ful, 0x6e776f646b6f6f6cul, 0x6f64206b6f6f6c00ul, 0x65746e6563006e77ul, 0x6563007765697672ul, 0x656976207265746eul, 0x6b6f6f6c6d2b0077ul, 0x6c206573756f6d00ul, 0x6f6c6b2b006b6f6ful, 0x6f6279656b006b6ful, 0x6b6f6f6c20647261ul, 0x707565766f6d2b00ul, 0x7075206d69777300ul, 0x6f6465766f6d2b00ul, 0x206d697773006e77ul, 0x786500006e776f64ul, 0x7561666564206365ul, 0xa6766632e746cul, 0x657a697377656976ul, 0x7300616d6d616700ul, 0x6976697469736e65ul, 0x6f766d6762007974ul, 0x6c6f7600656d756cul, 0x665f6c6300656d75ul, 0x707364726177726ful, 0x625f6c6300646565ul, 0x64656570736b6361ul, 0x68637469705f6d00ul, 0x7270736b6f6f6c00ul, 0x6b6f6f6c00676e69ul, 0x6e00656661727473ul, 0x2273252220656d61ul, 0x616e74736f68000aul, 0x726f6c6f6300656dul, 0xa692520692520ul, 0x6925732065766173ul, 0x732064616f6c000aul, 0x20657241000a6925ul, 0x6572757320756f79ul, 0x6e617720756f7920ul, 0x6174730a6f742074ul, 0x77656e2061207472ul, 0xa3f656d616720ul, 0x6579616c7078616dul, 0x616d000a31207372ul, 0xa74726174732070ul, 0x6d5f702f78666700ul, 0x706d6c2e69746c75ul, 0x35312e35312d2500ul, 0x312e35312d252073ul, 0x252f753225207335ul, 0x35312d25000a7532ul, 0x312d25207335312eul, 0x53000a7335312e35ul, 0x676e696863726165ul, 0x51206f4e002e2e2eul, 0x72657320656b6175ul, 0x756f662073726576ul, 0x622f78666700646eul, 0x6d6c2e6c745f786ful, 0x6f622f7866670070ul, 0x706d6c2e6c6d5f78ul, 0x786f622f78666700ul, 0x706d6c2e6c625ful, 0x5f786f622f786667ul, 0x6700706d6c2e6d74ul, 0x6d5f786f622f7866ul, 0x666700706d6c2e6dul, 0x6d6d5f786f622f78ul, 0x666700706d6c2e32ul, 0x6d625f786f622f78ul, 0x78666700706d6c2eul, 0x2e72745f786f622ful, 0x2f78666700706d6cul, 0x6c2e726d5f786f62ul, 0x622f78666700706dul, 0x6d6c2e72625f786ful, 0x70712f7866670070ul, 0x6d6c2e657571616cul, 0x206e696765620070ul, 0x20202000656d6167ul, 0x702078614d202020ul, 0x250073726579616cul, 0x2020202020200069ul, 0x5420656d61472020ul, 0x706f6f4300657079ul, 0x65766974617265ul, 0x74616d6874616544ul, 0x2020202020006863ul, 0x706d616554202020ul, 0x46206f4e0079616cul, 0x20796c646e656972ul, 0x6972460065726946ul, 0x694620796c646e65ul, 0x4300676154006572ul, 0x7420657275747061ul, 0x67616c46206568ul, 0x67616c4620656e4ful, 0x7268540046544320ul, 0x206d616554206565ul, 0x66664f00465443ul, 0x2020202020202020ul, 0x6c696b5320202020ul, 0x642079736145006cul, 0x746c756369666669ul, 0x6c616d726f4e0079ul, 0x7563696666696420ul, 0x647261480079746cul, 0x7563696666696420ul, 0x6867694e0079746cul, 0x6964206572616d74ul, 0x79746c7563696666ul, 0x2020202020202000ul, 0x6d694c2067617246ul, 0x656e6f6e007469ul, 0x7367617266206925ul, 0x2020202020202000ul, 0x6d694c20656d6954ul, 0x696d206925007469ul, 0x202000736574756eul, 0x4520202020202020ul, 0x200065646f736970ul, 0x2020202020202020ul, 0x6c6576654c2020ul, 0x742065726f4d2020ul, 0x6c702034206e6168ul, 0x2020207372657961ul, 0x7269757165722000ul, 0x676e697375207365ul, 0x646e616d6d6f6320ul, 0x7020656e696c0020ul, 0x726574656d617261ul, 0x7361656c70203b73ul, 0x6573202020002065ul, 0x6e69686365742065ul, 0x202e7478742e6f66ul, 0x2077654e00202020ul, 0x696f4a00656d6147ul, 0x4900656d6147206eul, 0x492f504354005850ul, 0x25202d2073250050ul, 0x7365726464410073ul, 0x74726f50003a73ul, 0x6620686372616553ul, 0x6c61636f6c20726ful, 0x2e2e73656d616720ul, 0x67206e696f4a002eul, 0x3a746120656d61ul, 0x65736c7550004b4ful, 0x676e696c61694420ul, 0x54206863756f5400ul, 0x6c61694420656e6ful, 0x61656c4300676e69ul, 0x480074696e490072ul, 0x6f4d007075676e61ul, 0x65726944006d6564ul, 0x656e6e6f43207463ul, 0x75254d4f43007463ul, 0x7561420051524900ul, 0x206d65646f4d0064ul, 0x2e2e2e7075746553ul, 0x6e20656e6f685000ul, 0x6f43007265626d75ul, 0x2020007463656e6eul, 0x20756f7920657241ul, 0x757120616e6e6f67ul, 0x2000202020207469ul, 0x6167207369687420ul, 0x207473756a20656dul, 0x202020656b696cul, 0x7972657665202020ul, 0x6c6520676e696874ul, 0x20202020203f6573ul, 0x2020202020202000ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x726f6c694d200020ul, 0x696874656d202c64ul, 0x7461687420736b6eul, 0x6874202020002020ul, 0x612074726120756ful, 0x2020796c776f6c20ul, 0x6975712000202020ul, 0x7349202e72657474ul, 0x7274207369687420ul, 0x6f442000203f6575ul, 0x206465656e204920ul, 0x2074737562206f74ul, 0x2020002072756f79ul, 0x65706f2065636166ul, 0x727420726f66206eul, 0x20002020676e6979ul, 0x7420202020202020ul, 0x203f74697571206ful, 0x20202020202020ul, 0x2049202c6e614d20ul, 0x732061746867756ful, 0x756f79206b63616dul, 0x20726f6620202000ul, 0x7420676e69797274ul, 0x202174697571206ful, 0x5020202020200020ul, 0x7420592073736572ul, 0x202020746567206ful, 0x2020202020002020ul, 0x64656b63616d7320ul, 0x2020202e74756f20ul, 0x6572502000202020ul, 0x206f742059207373ul, 0x6b696c2074697571ul, 0x2020200020612065ul, 0x65736f6c20676962ul, 0x66696c206e692072ul, 0x2020002020202e65ul, 0x204e207373657250ul, 0x2079617473206f74ul, 0x20002064756f7270ul, 0x7320646e61202020ul, 0x7566737365636375ul, 0x2020202020216cul, 0x6f79206649202020ul, 0x2073736572702075ul, 0x202020206f742059ul, 0x2c74697571202000ul, 0x206c6c6977204920ul, 0x20206e6f6d6d7573ul, 0x6174615320200020ul, 0x766f206c6c61206eul, 0x2072756f79207265ul, 0x2020202020002020ul, 0x7264206472616820ul, 0x2020202021657669ul, 0x6d55202000202020ul, 0x65646f6d7341202cul, 0x696c736964207375ul, 0x696820002073656bul, 0x72646c6968632073ul, 0x6e69797274206e65ul, 0x712000206f742067ul, 0x657250202e746975ul, 0x206f742059207373ul, 0x20006e7275746572ul, 0x756f79206f742020ul, 0x72656b6e69542072ul, 0x20202e73796f74ul, 0x756f792066492020ul, 0x6f6e207469757120ul, 0x206c6c2749202c77ul, 0x776f726874202000ul, 0x6b6e616c62206120ul, 0x79747261702d7465ul, 0x726f662020200020ul, 0x78656e20756f7920ul, 0x2021656d69742074ul, 0x682f786667002020ul, 0x6d6c2e6925706c65ul, 0x74742f7866670070ul, 0x6c2e6d7473635f6cul, 0x737365725000706dul, 0x6f2079656b206120ul, 0x6e6f747475622072ul, 0x69687420726f6620ul, 0x6e6f697463612073ul, 0x74207265746e4500ul, 0x65676e616863206ful, 0x70736b636162202cul, 0x63206f7420656361ul, 0x3f3f3f007261656cul, 0x2f78666700726f00ul, 0x6e6f6974706f5f70ul, 0x20202000706d6c2eul, 0x696d6f7473754320ul, 0x72746e6f6320657aul, 0x2020202000736c6ful, 0x206f472020202020ul, 0x6f736e6f63206f74ul, 0x202020202000656cul, 0x6f74207465736552ul, 0x746c756166656420ul, 0x2020202020200073ul, 0x7263532020202020ul, 0x657a6973206e6565ul, 0x2020202020202000ul, 0x6972422020202020ul, 0x7373656e746867ul, 0x2020202020202020ul, 0x6573756f4d202020ul, 0x2000646565705320ul, 0x4443202020202020ul, 0x5620636973754d20ul, 0x202000656d756c6ful, 0x2020202020202020ul, 0x6f5620646e756f53ul, 0x20202000656d756cul, 0x2020202020202020ul, 0x20737961776c4120ul, 0x20202020006e7552ul, 0x6e49202020202020ul, 0x756f4d2074726576ul, 0x2020202020006573ul, 0x4c20202020202020ul, 0x6e697270736b6f6ful, 0x2020202020200067ul, 0x6f4c202020202020ul, 0x6566617274736b6ful, 0x2020202020202000ul, 0x206f656469562020ul, 0x736e6f6974704ful, 0x670066666f006e6ful, 0x656d74656e2f7866ul, 0x6700706d6c2e316eul, 0x6d5f6d69642f7866ul, 0x706d6c2e6d646ful, 0x6d74656e2f786667ul, 0x706d6c2e326e65ul, 0x5f6d69642f786667ul, 0x706d6c2e74637264ul, 0x74656e2f78666700ul, 0x706d6c2e336e656dul, 0x6d69642f78666700ul, 0x706d6c2e7870695ful, 0x74656e2f78666700ul, 0x706d6c2e346e656dul, 0x6d69642f78666700ul, 0x706d6c2e7063745ful, 0x74656e2f78666700ul, 0x706d6c2e356e656dul, 0x6e656d2f78666700ul, 0x6c2e6925746f6475ul, 0x206f77542000706dul, 0x72657475706d6f63ul, 0x63656e6e6f632073ul, 0x7420202000646574ul, 0x74206867756f7268ul, 0x6d65646f6d206f77ul, 0x7962200020202e73ul, 0x2d6c6c756e206120ul, 0x6163206d65646f6dul, 0x4e2000202e656c62ul, 0x656e206c6c65766ful, 0x414c206b726f7774ul, 0x200020202020734eul, 0x6f646e695720726ful, 0x4f44203539207377ul, 0x202e786f622d53ul, 0x636f4c3d4e414c28ul, 0x2061657241206c61ul, 0x296b726f7774654eul, 0x6e6f6d6d6f432000ul, 0x206465737520796cul, 0x2079616c70206f74ul, 0x207265766f200020ul, 0x65746e4920656874ul, 0x7562202c74656e72ul, 0x6f736c6120002074ul, 0x6e6f206465737520ul, 0x6c61636f4c206120ul, 0x6572412000202020ul, 0x726f7774654e2061ul, 0x2020202020202e6bul, 0x736f480020202020ul, 0x6f5900656d616e74ul, 0x656d616e207275ul, 0x6f63207472696853ul, 0x746e615000726f6cul, 0x726f6c6f632073ul, 0x4320747065636341ul, 0x67007365676e6168ul, 0x6f626769622f7866ul, 0x666700706d6c2e78ul, 0x6c70756e656d2f78ul, 0x6700706d6c2e7279ul, 0x656d5f706d2f7866ul, 0x4e00706d6c2e756eul, 0x6e756d6d6f43206ful, 0x736e6f6974616369ul, 0x62616c6961764120ul, 0x702f78666700656cul, 0x6d6c2e657661735ful, 0x5f702f7866670070ul, 0x706d6c2e64616f6cul, 0x6c74742f78666700ul, 0x706d6c2e6c67735ful, 0x5f70732f78666700ul, 0x706d6c2e756e656dul, 0x6c74742f78666700ul, 0x6d6c2e6e69616d5ful, 0x616d2f7866670070ul, 0x6c2e756e656d6e69ul, 0x706dul)

[init]
def private c2da_lin_init_static_menu() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_menu_seg[s * 2]
        for (k in range(c2da_lin_static_menu_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_menu[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_menu() {
    if (length(c2da_fn_table0) < 113) {
        resize(c2da_fn_table0, 113)
    }
    c2da_fn_table0[112] = @@M_Menu_Quit_f
    c2da_fn_table0[111] = @@M_Menu_Help_f
    c2da_fn_table0[110] = @@M_Menu_Video_f
    c2da_fn_table0[109] = @@M_Menu_Keys_f
    c2da_fn_table0[108] = @@M_Menu_Options_f
    c2da_fn_table0[107] = @@M_Menu_Setup_f
    c2da_fn_table0[106] = @@M_Menu_MultiPlayer_f
    c2da_fn_table0[105] = @@M_Menu_Save_f
    c2da_fn_table0[104] = @@M_Menu_Load_f
    c2da_fn_table0[103] = @@M_Menu_SinglePlayer_f
    c2da_fn_table0[102] = @@M_Menu_Main_f
    c2da_fn_table0[101] = @@M_ToggleMenu_f
}

[init]
def private c2da_lin_relink_init_menu() {
    c2da_relink_menu()
}
