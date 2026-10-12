[export, sideeffects]
def PR_ExecuteProgram(var fnum : int) {
    var c2da_fresh3 : int
    var a : int
    var b : int
    var c : int
    var s : int
    var st : int
    var f : int
    var newf : int
    var runaway : int
    var i : int
    var ed : int
    var exitdepth : int
    var ptr : int
    var c2da_fresh59 : int
    if (fnum == 0 || fnum >= int(uint(c2da_mem[progs + 36]) | uint(c2da_mem[progs + 37]) << 0x8 | uint(c2da_mem[progs + 38]) << 0x10 | uint(c2da_mem[progs + 39]) << 0x18)) {
        let c2da_fresh127 : int = int(uint(c2da_mem[pr_global_struct + 112]) | uint(c2da_mem[pr_global_struct + 113]) << 0x8 | uint(c2da_mem[pr_global_struct + 114]) << 0x10 | uint(c2da_mem[pr_global_struct + 115]) << 0x18)
        if (c2da_fresh127 != 0) {
            ED_Print(int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_global_struct + 112]) | uint(c2da_mem[pr_global_struct + 113]) << 0x8 | uint(c2da_mem[pr_global_struct + 114]) << 0x10 | uint(c2da_mem[pr_global_struct + 115]) << 0x18))
        }
        Host_Error(730976, [])
    }
    f = pr_functions + fnum * 36
    runaway = 100000
    pr_trace = 0u
    exitdepth = pr_depth
    s = PR_EnterFunction(f)
    while (true) {
        s++
        st = pr_statements + s * 8
        a = pr_globals + int(int16(uint(c2da_mem[st + 2]) | uint(c2da_mem[st + 3]) << 0x8)) * 4
        b = pr_globals + int(int16(uint(c2da_mem[st + 4]) | uint(c2da_mem[st + 5]) << 0x8)) * 4
        c = pr_globals + int(int16(uint(c2da_mem[st + 6]) | uint(c2da_mem[st + 7]) << 0x8)) * 4
        runaway--
        if (runaway == 0) {
            PR_RunError(731009, [])
        }
        let c2da_fresh0 : int = int(uint(c2da_mem[pr_xfunction + 12]) | uint(c2da_mem[pr_xfunction + 13]) << 0x8 | uint(c2da_mem[pr_xfunction + 14]) << 0x10 | uint(c2da_mem[pr_xfunction + 15]) << 0x18)
        let c2da_fresh1 : int = c2da_fresh0 + 1
        let c2da_fresh2 : uint = uint(c2da_fresh1)
        c2da_mem[pr_xfunction + 12] = uint8(c2da_fresh2)
        c2da_mem[pr_xfunction + 13] = uint8(c2da_fresh2 >> 0x8)
        c2da_mem[pr_xfunction + 14] = uint8(c2da_fresh2 >> 0x10)
        c2da_mem[pr_xfunction + 15] = uint8(c2da_fresh2 >> 0x18)
        pr_xstatement = s
        if (pr_trace != 0u) {
            PR_PrintStatement(st)
        }
        c2da_fresh3 = int(uint16(uint(c2da_mem[st]) | uint(c2da_mem[st + 1]) << 0x8))
        if (c2da_fresh3 >= 0 && c2da_fresh3 <= 65) {
            goto c2da_fresh3 + 3
        }
        goto label 2
        label 9:
        let c2da_fresh4 : float = uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18)
        let c2da_fresh5 : uint = float_bits_to_uint(c2da_fresh4)
        c2da_mem[c] = uint8(c2da_fresh5)
        c2da_mem[c + 1] = uint8(c2da_fresh5 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh5 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh5 >> 0x18)
        continue
        label 10:
        let c2da_fresh6 : float = uint_bits_to_float(uint(c2da_mem[a + 0 * 4]) | uint(c2da_mem[a + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[b + 0 * 4]) | uint(c2da_mem[b + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 0 * 4 + 3]) << 0x18)
        let c2da_fresh7 : uint = float_bits_to_uint(c2da_fresh6)
        c2da_mem[c + 0 * 4] = uint8(c2da_fresh7)
        c2da_mem[c + 0 * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
        c2da_mem[c + 0 * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
        c2da_mem[c + 0 * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
        let c2da_fresh8 : float = uint_bits_to_float(uint(c2da_mem[a + 1 * 4]) | uint(c2da_mem[a + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[b + 1 * 4]) | uint(c2da_mem[b + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 1 * 4 + 3]) << 0x18)
        let c2da_fresh9 : uint = float_bits_to_uint(c2da_fresh8)
        c2da_mem[c + 1 * 4] = uint8(c2da_fresh9)
        c2da_mem[c + 1 * 4 + 1] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[c + 1 * 4 + 2] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[c + 1 * 4 + 3] = uint8(c2da_fresh9 >> 0x18)
        let c2da_fresh10 : float = uint_bits_to_float(uint(c2da_mem[a + 2 * 4]) | uint(c2da_mem[a + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 2 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[b + 2 * 4]) | uint(c2da_mem[b + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 2 * 4 + 3]) << 0x18)
        let c2da_fresh11 : uint = float_bits_to_uint(c2da_fresh10)
        c2da_mem[c + 2 * 4] = uint8(c2da_fresh11)
        c2da_mem[c + 2 * 4 + 1] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[c + 2 * 4 + 2] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[c + 2 * 4 + 3] = uint8(c2da_fresh11 >> 0x18)
        continue
        label 11:
        let c2da_fresh12 : float = uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18)
        let c2da_fresh13 : uint = float_bits_to_uint(c2da_fresh12)
        c2da_mem[c] = uint8(c2da_fresh13)
        c2da_mem[c + 1] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh13 >> 0x18)
        continue
        label 12:
        let c2da_fresh14 : float = uint_bits_to_float(uint(c2da_mem[a + 0 * 4]) | uint(c2da_mem[a + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 0 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[b + 0 * 4]) | uint(c2da_mem[b + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 0 * 4 + 3]) << 0x18)
        let c2da_fresh15 : uint = float_bits_to_uint(c2da_fresh14)
        c2da_mem[c + 0 * 4] = uint8(c2da_fresh15)
        c2da_mem[c + 0 * 4 + 1] = uint8(c2da_fresh15 >> 0x8)
        c2da_mem[c + 0 * 4 + 2] = uint8(c2da_fresh15 >> 0x10)
        c2da_mem[c + 0 * 4 + 3] = uint8(c2da_fresh15 >> 0x18)
        let c2da_fresh16 : float = uint_bits_to_float(uint(c2da_mem[a + 1 * 4]) | uint(c2da_mem[a + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 1 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[b + 1 * 4]) | uint(c2da_mem[b + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 1 * 4 + 3]) << 0x18)
        let c2da_fresh17 : uint = float_bits_to_uint(c2da_fresh16)
        c2da_mem[c + 1 * 4] = uint8(c2da_fresh17)
        c2da_mem[c + 1 * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
        c2da_mem[c + 1 * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
        c2da_mem[c + 1 * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
        let c2da_fresh18 : float = uint_bits_to_float(uint(c2da_mem[a + 2 * 4]) | uint(c2da_mem[a + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 2 * 4 + 3]) << 0x18) - uint_bits_to_float(uint(c2da_mem[b + 2 * 4]) | uint(c2da_mem[b + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 2 * 4 + 3]) << 0x18)
        let c2da_fresh19 : uint = float_bits_to_uint(c2da_fresh18)
        c2da_mem[c + 2 * 4] = uint8(c2da_fresh19)
        c2da_mem[c + 2 * 4 + 1] = uint8(c2da_fresh19 >> 0x8)
        c2da_mem[c + 2 * 4 + 2] = uint8(c2da_fresh19 >> 0x10)
        c2da_mem[c + 2 * 4 + 3] = uint8(c2da_fresh19 >> 0x18)
        continue
        label 4:
        let c2da_fresh20 : float = uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18)
        let c2da_fresh21 : uint = float_bits_to_uint(c2da_fresh20)
        c2da_mem[c] = uint8(c2da_fresh21)
        c2da_mem[c + 1] = uint8(c2da_fresh21 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh21 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh21 >> 0x18)
        continue
        label 5:
        let c2da_fresh22 : float = uint_bits_to_float(uint(c2da_mem[a + 0 * 4]) | uint(c2da_mem[a + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 0 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[b + 0 * 4]) | uint(c2da_mem[b + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 0 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[a + 1 * 4]) | uint(c2da_mem[a + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 1 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[b + 1 * 4]) | uint(c2da_mem[b + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 1 * 4 + 3]) << 0x18) + uint_bits_to_float(uint(c2da_mem[a + 2 * 4]) | uint(c2da_mem[a + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 2 * 4 + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[b + 2 * 4]) | uint(c2da_mem[b + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 2 * 4 + 3]) << 0x18)
        let c2da_fresh23 : uint = float_bits_to_uint(c2da_fresh22)
        c2da_mem[c] = uint8(c2da_fresh23)
        c2da_mem[c + 1] = uint8(c2da_fresh23 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh23 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh23 >> 0x18)
        continue
        label 6:
        let c2da_fresh24 : float = uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[b + 0 * 4]) | uint(c2da_mem[b + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 0 * 4 + 3]) << 0x18)
        let c2da_fresh25 : uint = float_bits_to_uint(c2da_fresh24)
        c2da_mem[c + 0 * 4] = uint8(c2da_fresh25)
        c2da_mem[c + 0 * 4 + 1] = uint8(c2da_fresh25 >> 0x8)
        c2da_mem[c + 0 * 4 + 2] = uint8(c2da_fresh25 >> 0x10)
        c2da_mem[c + 0 * 4 + 3] = uint8(c2da_fresh25 >> 0x18)
        let c2da_fresh26 : float = uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[b + 1 * 4]) | uint(c2da_mem[b + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 1 * 4 + 3]) << 0x18)
        let c2da_fresh27 : uint = float_bits_to_uint(c2da_fresh26)
        c2da_mem[c + 1 * 4] = uint8(c2da_fresh27)
        c2da_mem[c + 1 * 4 + 1] = uint8(c2da_fresh27 >> 0x8)
        c2da_mem[c + 1 * 4 + 2] = uint8(c2da_fresh27 >> 0x10)
        c2da_mem[c + 1 * 4 + 3] = uint8(c2da_fresh27 >> 0x18)
        let c2da_fresh28 : float = uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[b + 2 * 4]) | uint(c2da_mem[b + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 2 * 4 + 3]) << 0x18)
        let c2da_fresh29 : uint = float_bits_to_uint(c2da_fresh28)
        c2da_mem[c + 2 * 4] = uint8(c2da_fresh29)
        c2da_mem[c + 2 * 4 + 1] = uint8(c2da_fresh29 >> 0x8)
        c2da_mem[c + 2 * 4 + 2] = uint8(c2da_fresh29 >> 0x10)
        c2da_mem[c + 2 * 4 + 3] = uint8(c2da_fresh29 >> 0x18)
        continue
        label 7:
        let c2da_fresh30 : float = uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[a + 0 * 4]) | uint(c2da_mem[a + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 0 * 4 + 3]) << 0x18)
        let c2da_fresh31 : uint = float_bits_to_uint(c2da_fresh30)
        c2da_mem[c + 0 * 4] = uint8(c2da_fresh31)
        c2da_mem[c + 0 * 4 + 1] = uint8(c2da_fresh31 >> 0x8)
        c2da_mem[c + 0 * 4 + 2] = uint8(c2da_fresh31 >> 0x10)
        c2da_mem[c + 0 * 4 + 3] = uint8(c2da_fresh31 >> 0x18)
        let c2da_fresh32 : float = uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[a + 1 * 4]) | uint(c2da_mem[a + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 1 * 4 + 3]) << 0x18)
        let c2da_fresh33 : uint = float_bits_to_uint(c2da_fresh32)
        c2da_mem[c + 1 * 4] = uint8(c2da_fresh33)
        c2da_mem[c + 1 * 4 + 1] = uint8(c2da_fresh33 >> 0x8)
        c2da_mem[c + 1 * 4 + 2] = uint8(c2da_fresh33 >> 0x10)
        c2da_mem[c + 1 * 4 + 3] = uint8(c2da_fresh33 >> 0x18)
        let c2da_fresh34 : float = uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) * uint_bits_to_float(uint(c2da_mem[a + 2 * 4]) | uint(c2da_mem[a + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 2 * 4 + 3]) << 0x18)
        let c2da_fresh35 : uint = float_bits_to_uint(c2da_fresh34)
        c2da_mem[c + 2 * 4] = uint8(c2da_fresh35)
        c2da_mem[c + 2 * 4 + 1] = uint8(c2da_fresh35 >> 0x8)
        c2da_mem[c + 2 * 4 + 2] = uint8(c2da_fresh35 >> 0x10)
        c2da_mem[c + 2 * 4 + 3] = uint8(c2da_fresh35 >> 0x18)
        continue
        label 8:
        let c2da_fresh36 : float = uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) / uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18)
        let c2da_fresh37 : uint = float_bits_to_uint(c2da_fresh36)
        c2da_mem[c] = uint8(c2da_fresh37)
        c2da_mem[c + 1] = uint8(c2da_fresh37 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh37 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh37 >> 0x18)
        continue
        label 67:
        let c2da_fresh38 : float = float(int(uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18)) & int(uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18)))
        let c2da_fresh39 : uint = float_bits_to_uint(c2da_fresh38)
        c2da_mem[c] = uint8(c2da_fresh39)
        c2da_mem[c + 1] = uint8(c2da_fresh39 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh39 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh39 >> 0x18)
        continue
        label 68:
        let c2da_fresh40 : float = float(int(uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18)) | int(uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18)))
        let c2da_fresh41 : uint = float_bits_to_uint(c2da_fresh40)
        c2da_mem[c] = uint8(c2da_fresh41)
        c2da_mem[c + 1] = uint8(c2da_fresh41 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh41 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh41 >> 0x18)
        continue
        label 24:
        let c2da_fresh42 : float = float(uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) >= uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) ? 1 : 0)
        let c2da_fresh43 : uint = float_bits_to_uint(c2da_fresh42)
        c2da_mem[c] = uint8(c2da_fresh43)
        c2da_mem[c + 1] = uint8(c2da_fresh43 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh43 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh43 >> 0x18)
        continue
        label 23:
        let c2da_fresh44 : float = float(uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) <= uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) ? 1 : 0)
        let c2da_fresh45 : uint = float_bits_to_uint(c2da_fresh44)
        c2da_mem[c] = uint8(c2da_fresh45)
        c2da_mem[c + 1] = uint8(c2da_fresh45 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh45 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh45 >> 0x18)
        continue
        label 26:
        let c2da_fresh46 : float = float(uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) > uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) ? 1 : 0)
        let c2da_fresh47 : uint = float_bits_to_uint(c2da_fresh46)
        c2da_mem[c] = uint8(c2da_fresh47)
        c2da_mem[c + 1] = uint8(c2da_fresh47 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh47 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh47 >> 0x18)
        continue
        label 25:
        let c2da_fresh48 : float = float(uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) < uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) ? 1 : 0)
        let c2da_fresh49 : uint = float_bits_to_uint(c2da_fresh48)
        c2da_mem[c] = uint8(c2da_fresh49)
        c2da_mem[c + 1] = uint8(c2da_fresh49 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh49 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh49 >> 0x18)
        continue
        label 65:
        let c2da_fresh50 : float = float(uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) != 0.0 && uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) != 0.0 ? 1 : 0)
        let c2da_fresh51 : uint = float_bits_to_uint(c2da_fresh50)
        c2da_mem[c] = uint8(c2da_fresh51)
        c2da_mem[c + 1] = uint8(c2da_fresh51 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh51 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh51 >> 0x18)
        continue
        label 66:
        let c2da_fresh52 : float = float(uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) != 0.0 || uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) != 0.0 ? 1 : 0)
        let c2da_fresh53 : uint = float_bits_to_uint(c2da_fresh52)
        c2da_mem[c] = uint8(c2da_fresh53)
        c2da_mem[c + 1] = uint8(c2da_fresh53 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh53 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh53 >> 0x18)
        continue
        label 47:
        let c2da_fresh54 : float = uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) == 0.0 ? 1.0 : 0.0
        let c2da_fresh55 : uint = float_bits_to_uint(c2da_fresh54)
        c2da_mem[c] = uint8(c2da_fresh55)
        c2da_mem[c + 1] = uint8(c2da_fresh55 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh55 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh55 >> 0x18)
        continue
        label 48:
        let c2da_fresh56 : float = float(uint_bits_to_float(uint(c2da_mem[a + 0 * 4]) | uint(c2da_mem[a + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 0 * 4 + 3]) << 0x18) == 0.0 && uint_bits_to_float(uint(c2da_mem[a + 1 * 4]) | uint(c2da_mem[a + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 1 * 4 + 3]) << 0x18) == 0.0 && uint_bits_to_float(uint(c2da_mem[a + 2 * 4]) | uint(c2da_mem[a + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 2 * 4 + 3]) << 0x18) == 0.0 ? 1 : 0)
        let c2da_fresh57 : uint = float_bits_to_uint(c2da_fresh56)
        c2da_mem[c] = uint8(c2da_fresh57)
        c2da_mem[c + 1] = uint8(c2da_fresh57 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh57 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh57 >> 0x18)
        continue
        label 49:
        c2da_fresh59 = 1
        let c2da_fresh128 : int = int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18)
        if (!(c2da_fresh128 == 0)) {
            let c2da_fresh58 : int = pr_strings + c2da_fresh128
            if (!(int8(c2da_mem[c2da_fresh58]) == 0)) {
                c2da_fresh59 = 0
            }
        }
        let c2da_fresh60 : float = float(c2da_fresh59)
        let c2da_fresh61 : uint = float_bits_to_uint(c2da_fresh60)
        c2da_mem[c] = uint8(c2da_fresh61)
        c2da_mem[c + 1] = uint8(c2da_fresh61 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh61 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh61 >> 0x18)
        continue
        label 51:
        let c2da_fresh62 : float = int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) == 0 ? 1.0 : 0.0
        let c2da_fresh63 : uint = float_bits_to_uint(c2da_fresh62)
        c2da_mem[c] = uint8(c2da_fresh63)
        c2da_mem[c + 1] = uint8(c2da_fresh63 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh63 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh63 >> 0x18)
        continue
        label 50:
        let c2da_fresh129 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh64 : float = float(c2da_fresh129 + int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) == c2da_fresh129 ? 1 : 0)
        let c2da_fresh65 : uint = float_bits_to_uint(c2da_fresh64)
        c2da_mem[c] = uint8(c2da_fresh65)
        c2da_mem[c + 1] = uint8(c2da_fresh65 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh65 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh65 >> 0x18)
        continue
        label 13:
        let c2da_fresh66 : float = float(uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) == uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) ? 1 : 0)
        let c2da_fresh67 : uint = float_bits_to_uint(c2da_fresh66)
        c2da_mem[c] = uint8(c2da_fresh67)
        c2da_mem[c + 1] = uint8(c2da_fresh67 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh67 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh67 >> 0x18)
        continue
        label 14:
        let c2da_fresh68 : float = float(uint_bits_to_float(uint(c2da_mem[a + 0 * 4]) | uint(c2da_mem[a + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 0 * 4 + 3]) << 0x18) == uint_bits_to_float(uint(c2da_mem[b + 0 * 4]) | uint(c2da_mem[b + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 0 * 4 + 3]) << 0x18) && uint_bits_to_float(uint(c2da_mem[a + 1 * 4]) | uint(c2da_mem[a + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 1 * 4 + 3]) << 0x18) == uint_bits_to_float(uint(c2da_mem[b + 1 * 4]) | uint(c2da_mem[b + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 1 * 4 + 3]) << 0x18) && uint_bits_to_float(uint(c2da_mem[a + 2 * 4]) | uint(c2da_mem[a + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 2 * 4 + 3]) << 0x18) == uint_bits_to_float(uint(c2da_mem[b + 2 * 4]) | uint(c2da_mem[b + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 2 * 4 + 3]) << 0x18) ? 1 : 0)
        let c2da_fresh69 : uint = float_bits_to_uint(c2da_fresh68)
        c2da_mem[c] = uint8(c2da_fresh69)
        c2da_mem[c + 1] = uint8(c2da_fresh69 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh69 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh69 >> 0x18)
        continue
        label 15:
        let c2da_fresh70 : float = c2da_lin_strcmp(int(pr_strings + int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18)), int(pr_strings + int(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18))) == 0 ? 1.0 : 0.0
        let c2da_fresh71 : uint = float_bits_to_uint(c2da_fresh70)
        c2da_mem[c] = uint8(c2da_fresh71)
        c2da_mem[c + 1] = uint8(c2da_fresh71 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh71 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh71 >> 0x18)
        continue
        label 16:
        let c2da_fresh72 : float = float(int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) == int(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) ? 1 : 0)
        let c2da_fresh73 : uint = float_bits_to_uint(c2da_fresh72)
        c2da_mem[c] = uint8(c2da_fresh73)
        c2da_mem[c + 1] = uint8(c2da_fresh73 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh73 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh73 >> 0x18)
        continue
        label 17:
        let c2da_fresh74 : float = float(int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) == int(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) ? 1 : 0)
        let c2da_fresh75 : uint = float_bits_to_uint(c2da_fresh74)
        c2da_mem[c] = uint8(c2da_fresh75)
        c2da_mem[c + 1] = uint8(c2da_fresh75 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh75 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh75 >> 0x18)
        continue
        label 18:
        let c2da_fresh76 : float = float(uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) != uint_bits_to_float(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) ? 1 : 0)
        let c2da_fresh77 : uint = float_bits_to_uint(c2da_fresh76)
        c2da_mem[c] = uint8(c2da_fresh77)
        c2da_mem[c + 1] = uint8(c2da_fresh77 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh77 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh77 >> 0x18)
        continue
        label 19:
        let c2da_fresh78 : float = float(uint_bits_to_float(uint(c2da_mem[a + 0 * 4]) | uint(c2da_mem[a + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 0 * 4 + 3]) << 0x18) != uint_bits_to_float(uint(c2da_mem[b + 0 * 4]) | uint(c2da_mem[b + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 0 * 4 + 3]) << 0x18) || uint_bits_to_float(uint(c2da_mem[a + 1 * 4]) | uint(c2da_mem[a + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 1 * 4 + 3]) << 0x18) != uint_bits_to_float(uint(c2da_mem[b + 1 * 4]) | uint(c2da_mem[b + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 1 * 4 + 3]) << 0x18) || uint_bits_to_float(uint(c2da_mem[a + 2 * 4]) | uint(c2da_mem[a + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 2 * 4 + 3]) << 0x18) != uint_bits_to_float(uint(c2da_mem[b + 2 * 4]) | uint(c2da_mem[b + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[b + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[b + 2 * 4 + 3]) << 0x18) ? 1 : 0)
        let c2da_fresh79 : uint = float_bits_to_uint(c2da_fresh78)
        c2da_mem[c] = uint8(c2da_fresh79)
        c2da_mem[c + 1] = uint8(c2da_fresh79 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh79 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh79 >> 0x18)
        continue
        label 20:
        let c2da_fresh80 : float = float(c2da_lin_strcmp(int(pr_strings + int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18)), int(pr_strings + int(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18))))
        let c2da_fresh81 : uint = float_bits_to_uint(c2da_fresh80)
        c2da_mem[c] = uint8(c2da_fresh81)
        c2da_mem[c + 1] = uint8(c2da_fresh81 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh81 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh81 >> 0x18)
        continue
        label 21:
        let c2da_fresh82 : float = float(int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) != int(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) ? 1 : 0)
        let c2da_fresh83 : uint = float_bits_to_uint(c2da_fresh82)
        c2da_mem[c] = uint8(c2da_fresh83)
        c2da_mem[c + 1] = uint8(c2da_fresh83 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh83 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh83 >> 0x18)
        continue
        label 22:
        let c2da_fresh84 : float = float(int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) != int(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) ? 1 : 0)
        let c2da_fresh85 : uint = float_bits_to_uint(c2da_fresh84)
        c2da_mem[c] = uint8(c2da_fresh85)
        c2da_mem[c + 1] = uint8(c2da_fresh85 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh85 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh85 >> 0x18)
        continue
        label 34:
        label 36:
        label 37:
        label 38:
        label 39:
        let c2da_fresh86 : int = int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18)
        let c2da_fresh87 : uint = uint(c2da_fresh86)
        c2da_mem[b] = uint8(c2da_fresh87)
        c2da_mem[b + 1] = uint8(c2da_fresh87 >> 0x8)
        c2da_mem[b + 2] = uint8(c2da_fresh87 >> 0x10)
        c2da_mem[b + 3] = uint8(c2da_fresh87 >> 0x18)
        continue
        label 35:
        let c2da_fresh88 : float = uint_bits_to_float(uint(c2da_mem[a + 0 * 4]) | uint(c2da_mem[a + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 0 * 4 + 3]) << 0x18)
        let c2da_fresh89 : uint = float_bits_to_uint(c2da_fresh88)
        c2da_mem[b + 0 * 4] = uint8(c2da_fresh89)
        c2da_mem[b + 0 * 4 + 1] = uint8(c2da_fresh89 >> 0x8)
        c2da_mem[b + 0 * 4 + 2] = uint8(c2da_fresh89 >> 0x10)
        c2da_mem[b + 0 * 4 + 3] = uint8(c2da_fresh89 >> 0x18)
        let c2da_fresh90 : float = uint_bits_to_float(uint(c2da_mem[a + 1 * 4]) | uint(c2da_mem[a + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 1 * 4 + 3]) << 0x18)
        let c2da_fresh91 : uint = float_bits_to_uint(c2da_fresh90)
        c2da_mem[b + 1 * 4] = uint8(c2da_fresh91)
        c2da_mem[b + 1 * 4 + 1] = uint8(c2da_fresh91 >> 0x8)
        c2da_mem[b + 1 * 4 + 2] = uint8(c2da_fresh91 >> 0x10)
        c2da_mem[b + 1 * 4 + 3] = uint8(c2da_fresh91 >> 0x18)
        let c2da_fresh92 : float = uint_bits_to_float(uint(c2da_mem[a + 2 * 4]) | uint(c2da_mem[a + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 2 * 4 + 3]) << 0x18)
        let c2da_fresh93 : uint = float_bits_to_uint(c2da_fresh92)
        c2da_mem[b + 2 * 4] = uint8(c2da_fresh93)
        c2da_mem[b + 2 * 4 + 1] = uint8(c2da_fresh93 >> 0x8)
        c2da_mem[b + 2 * 4 + 2] = uint8(c2da_fresh93 >> 0x10)
        c2da_mem[b + 2 * 4 + 3] = uint8(c2da_fresh93 >> 0x18)
        continue
        label 40:
        label 42:
        label 43:
        label 44:
        label 45:
        ptr = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18)
        let c2da_fresh94 : int = int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18)
        let c2da_fresh95 : uint = uint(c2da_fresh94)
        c2da_mem[ptr] = uint8(c2da_fresh95)
        c2da_mem[ptr + 1] = uint8(c2da_fresh95 >> 0x8)
        c2da_mem[ptr + 2] = uint8(c2da_fresh95 >> 0x10)
        c2da_mem[ptr + 3] = uint8(c2da_fresh95 >> 0x18)
        continue
        label 41:
        ptr = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18)
        let c2da_fresh96 : float = uint_bits_to_float(uint(c2da_mem[a + 0 * 4]) | uint(c2da_mem[a + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 0 * 4 + 3]) << 0x18)
        let c2da_fresh97 : uint = float_bits_to_uint(c2da_fresh96)
        c2da_mem[ptr + 0 * 4] = uint8(c2da_fresh97)
        c2da_mem[ptr + 0 * 4 + 1] = uint8(c2da_fresh97 >> 0x8)
        c2da_mem[ptr + 0 * 4 + 2] = uint8(c2da_fresh97 >> 0x10)
        c2da_mem[ptr + 0 * 4 + 3] = uint8(c2da_fresh97 >> 0x18)
        let c2da_fresh98 : float = uint_bits_to_float(uint(c2da_mem[a + 1 * 4]) | uint(c2da_mem[a + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 1 * 4 + 3]) << 0x18)
        let c2da_fresh99 : uint = float_bits_to_uint(c2da_fresh98)
        c2da_mem[ptr + 1 * 4] = uint8(c2da_fresh99)
        c2da_mem[ptr + 1 * 4 + 1] = uint8(c2da_fresh99 >> 0x8)
        c2da_mem[ptr + 1 * 4 + 2] = uint8(c2da_fresh99 >> 0x10)
        c2da_mem[ptr + 1 * 4 + 3] = uint8(c2da_fresh99 >> 0x18)
        let c2da_fresh100 : float = uint_bits_to_float(uint(c2da_mem[a + 2 * 4]) | uint(c2da_mem[a + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 2 * 4 + 3]) << 0x18)
        let c2da_fresh101 : uint = float_bits_to_uint(c2da_fresh100)
        c2da_mem[ptr + 2 * 4] = uint8(c2da_fresh101)
        c2da_mem[ptr + 2 * 4 + 1] = uint8(c2da_fresh101 >> 0x8)
        c2da_mem[ptr + 2 * 4 + 2] = uint8(c2da_fresh101 >> 0x10)
        c2da_mem[ptr + 2 * 4 + 3] = uint8(c2da_fresh101 >> 0x18)
        continue
        label 33:
        let c2da_fresh130 : int = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        ed = c2da_fresh130 + int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18)
        if (ed == c2da_fresh130 && (uint(c2da_mem[232704]) | uint(c2da_mem[232705]) << 0x8 | uint(c2da_mem[232706]) << 0x10 | uint(c2da_mem[232707]) << 0x18) == 1u) {
            PR_RunError(731028, [])
        }
        let c2da_fresh102 : int = ed + 108 + int(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) * 4 - int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18)
        let c2da_fresh103 : uint = uint(c2da_fresh102)
        c2da_mem[c] = uint8(c2da_fresh103)
        c2da_mem[c + 1] = uint8(c2da_fresh103 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh103 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh103 >> 0x18)
        continue
        label 27:
        label 29:
        label 30:
        label 31:
        label 32:
        ed = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18)
        a = ed + 108 + int(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) * 4
        let c2da_fresh104 : int = int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18)
        let c2da_fresh105 : uint = uint(c2da_fresh104)
        c2da_mem[c] = uint8(c2da_fresh105)
        c2da_mem[c + 1] = uint8(c2da_fresh105 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh105 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh105 >> 0x18)
        continue
        label 28:
        ed = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18)
        a = ed + 108 + int(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18) * 4
        let c2da_fresh106 : float = uint_bits_to_float(uint(c2da_mem[a + 0 * 4]) | uint(c2da_mem[a + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 0 * 4 + 3]) << 0x18)
        let c2da_fresh107 : uint = float_bits_to_uint(c2da_fresh106)
        c2da_mem[c + 0 * 4] = uint8(c2da_fresh107)
        c2da_mem[c + 0 * 4 + 1] = uint8(c2da_fresh107 >> 0x8)
        c2da_mem[c + 0 * 4 + 2] = uint8(c2da_fresh107 >> 0x10)
        c2da_mem[c + 0 * 4 + 3] = uint8(c2da_fresh107 >> 0x18)
        let c2da_fresh108 : float = uint_bits_to_float(uint(c2da_mem[a + 1 * 4]) | uint(c2da_mem[a + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 1 * 4 + 3]) << 0x18)
        let c2da_fresh109 : uint = float_bits_to_uint(c2da_fresh108)
        c2da_mem[c + 1 * 4] = uint8(c2da_fresh109)
        c2da_mem[c + 1 * 4 + 1] = uint8(c2da_fresh109 >> 0x8)
        c2da_mem[c + 1 * 4 + 2] = uint8(c2da_fresh109 >> 0x10)
        c2da_mem[c + 1 * 4 + 3] = uint8(c2da_fresh109 >> 0x18)
        let c2da_fresh110 : float = uint_bits_to_float(uint(c2da_mem[a + 2 * 4]) | uint(c2da_mem[a + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[a + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[a + 2 * 4 + 3]) << 0x18)
        let c2da_fresh111 : uint = float_bits_to_uint(c2da_fresh110)
        c2da_mem[c + 2 * 4] = uint8(c2da_fresh111)
        c2da_mem[c + 2 * 4 + 1] = uint8(c2da_fresh111 >> 0x8)
        c2da_mem[c + 2 * 4 + 2] = uint8(c2da_fresh111 >> 0x10)
        c2da_mem[c + 2 * 4 + 3] = uint8(c2da_fresh111 >> 0x18)
        continue
        label 53:
        if (int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) == 0) {
            s += int(int16(uint(c2da_mem[st + 4]) | uint(c2da_mem[st + 5]) << 0x8)) - 1
        }
        continue
        label 52:
        if (int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) != 0) {
            s += int(int16(uint(c2da_mem[st + 4]) | uint(c2da_mem[st + 5]) << 0x8)) - 1
        }
        continue
        label 64:
        s += int(int16(uint(c2da_mem[st + 2]) | uint(c2da_mem[st + 3]) << 0x8)) - 1
        continue
        label 54:
        label 55:
        label 56:
        label 57:
        label 58:
        label 59:
        label 60:
        label 61:
        label 62:
        pr_argc = int(uint16(uint(c2da_mem[st]) | uint(c2da_mem[st + 1]) << 0x8)) - 51
        if (int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) == 0) {
            PR_RunError(731055, [])
        }
        newf = pr_functions + int(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18) * 36
        if (int(uint(c2da_mem[newf]) | uint(c2da_mem[newf + 1]) << 0x8 | uint(c2da_mem[newf + 2]) << 0x10 | uint(c2da_mem[newf + 3]) << 0x18) < 0) {
            goto label 0
        }
        s = PR_EnterFunction(newf)
        continue
        label 0:
        i = -int(uint(c2da_mem[newf]) | uint(c2da_mem[newf + 1]) << 0x8 | uint(c2da_mem[newf + 2]) << 0x10 | uint(c2da_mem[newf + 3]) << 0x18)
        if (i >= pr_numbuiltins) {
            PR_RunError(731069, [])
        }
        invoke(c2da_fn_table0[int(uint(c2da_mem[pr_builtins + i * 8]) | uint(c2da_mem[pr_builtins + i * 8 + 1]) << 0x8 | uint(c2da_mem[pr_builtins + i * 8 + 2]) << 0x10 | uint(c2da_mem[pr_builtins + i * 8 + 3]) << 0x18)])
        continue
        label 3:
        label 46:
        let c2da_fresh112 : int = pr_globals + int(int16(uint(c2da_mem[st + 2]) | uint(c2da_mem[st + 3]) << 0x8)) * 4
        let c2da_fresh113 : float = uint_bits_to_float(uint(c2da_mem[c2da_fresh112]) | uint(c2da_mem[c2da_fresh112 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh112 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh112 + 3]) << 0x18)
        let c2da_fresh114 : uint = float_bits_to_uint(c2da_fresh113)
        c2da_mem[pr_globals + 1 * 4] = uint8(c2da_fresh114)
        c2da_mem[pr_globals + 1 * 4 + 1] = uint8(c2da_fresh114 >> 0x8)
        c2da_mem[pr_globals + 1 * 4 + 2] = uint8(c2da_fresh114 >> 0x10)
        c2da_mem[pr_globals + 1 * 4 + 3] = uint8(c2da_fresh114 >> 0x18)
        let c2da_fresh115 : int = pr_globals + (int(int16(uint(c2da_mem[st + 2]) | uint(c2da_mem[st + 3]) << 0x8)) + 1) * 4
        let c2da_fresh116 : float = uint_bits_to_float(uint(c2da_mem[c2da_fresh115]) | uint(c2da_mem[c2da_fresh115 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh115 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh115 + 3]) << 0x18)
        let c2da_fresh117 : uint = float_bits_to_uint(c2da_fresh116)
        c2da_mem[pr_globals + (1 + 1) * 4] = uint8(c2da_fresh117)
        c2da_mem[pr_globals + (1 + 1) * 4 + 1] = uint8(c2da_fresh117 >> 0x8)
        c2da_mem[pr_globals + (1 + 1) * 4 + 2] = uint8(c2da_fresh117 >> 0x10)
        c2da_mem[pr_globals + (1 + 1) * 4 + 3] = uint8(c2da_fresh117 >> 0x18)
        let c2da_fresh118 : int = pr_globals + (int(int16(uint(c2da_mem[st + 2]) | uint(c2da_mem[st + 3]) << 0x8)) + 2) * 4
        let c2da_fresh119 : float = uint_bits_to_float(uint(c2da_mem[c2da_fresh118]) | uint(c2da_mem[c2da_fresh118 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh118 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh118 + 3]) << 0x18)
        let c2da_fresh120 : uint = float_bits_to_uint(c2da_fresh119)
        c2da_mem[pr_globals + (1 + 2) * 4] = uint8(c2da_fresh120)
        c2da_mem[pr_globals + (1 + 2) * 4 + 1] = uint8(c2da_fresh120 >> 0x8)
        c2da_mem[pr_globals + (1 + 2) * 4 + 2] = uint8(c2da_fresh120 >> 0x10)
        c2da_mem[pr_globals + (1 + 2) * 4 + 3] = uint8(c2da_fresh120 >> 0x18)
        s = PR_LeaveFunction()
        if (pr_depth == exitdepth) {
            goto label 1
        }
        continue
        label 1:
        return
        label 63:
        ed = int(uint(c2da_mem[232696]) | uint(c2da_mem[232697]) << 0x8 | uint(c2da_mem[232698]) << 0x10 | uint(c2da_mem[232699]) << 0x18) + int(uint(c2da_mem[pr_global_struct + 112]) | uint(c2da_mem[pr_global_struct + 113]) << 0x8 | uint(c2da_mem[pr_global_struct + 114]) << 0x10 | uint(c2da_mem[pr_global_struct + 115]) << 0x18)
        let c2da_fresh121 : float = float(double(uint_bits_to_float(uint(c2da_mem[pr_global_struct + 124]) | uint(c2da_mem[pr_global_struct + 125]) << 0x8 | uint(c2da_mem[pr_global_struct + 126]) << 0x10 | uint(c2da_mem[pr_global_struct + 127]) << 0x18)) + 0.1lf)
        let c2da_fresh122 : uint = float_bits_to_uint(c2da_fresh121)
        c2da_mem[ed + 292] = uint8(c2da_fresh122)
        c2da_mem[ed + 293] = uint8(c2da_fresh122 >> 0x8)
        c2da_mem[ed + 294] = uint8(c2da_fresh122 >> 0x10)
        c2da_mem[ed + 295] = uint8(c2da_fresh122 >> 0x18)
        let c2da_fresh131 : float = uint_bits_to_float(uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18)
        if (c2da_fresh131 != uint_bits_to_float(uint(c2da_mem[ed + 228]) | uint(c2da_mem[ed + 229]) << 0x8 | uint(c2da_mem[ed + 230]) << 0x10 | uint(c2da_mem[ed + 231]) << 0x18)) {
            let c2da_fresh123 : float = c2da_fresh131
            let c2da_fresh124 : uint = float_bits_to_uint(c2da_fresh123)
            c2da_mem[ed + 228] = uint8(c2da_fresh124)
            c2da_mem[ed + 229] = uint8(c2da_fresh124 >> 0x8)
            c2da_mem[ed + 230] = uint8(c2da_fresh124 >> 0x10)
            c2da_mem[ed + 231] = uint8(c2da_fresh124 >> 0x18)
        }
        let c2da_fresh125 : int = int(uint(c2da_mem[b]) | uint(c2da_mem[b + 1]) << 0x8 | uint(c2da_mem[b + 2]) << 0x10 | uint(c2da_mem[b + 3]) << 0x18)
        let c2da_fresh126 : uint = uint(c2da_fresh125)
        c2da_mem[ed + 284] = uint8(c2da_fresh126)
        c2da_mem[ed + 285] = uint8(c2da_fresh126 >> 0x8)
        c2da_mem[ed + 286] = uint8(c2da_fresh126 >> 0x10)
        c2da_mem[ed + 287] = uint8(c2da_fresh126 >> 0x18)
        continue
        label 2:
        PR_RunError(731093, [C2daVaArg(tag = 1, i64 = int64(uint16(uint(c2da_mem[st]) | uint(c2da_mem[st + 1]) << 0x8)), f64 = 0.0lf, raw = 0x0)])
    }
}
[export, sideeffects]
def PR_RunError(var error : int; c2da_va_args : array<C2daVaArg>) {
    let c2da_saved_sp : int = c2da_lin_sp
    PR_RunError_c2da_frame(error, c2da_va_args, c2da_lin_enter(1024))
    c2da_lin_sp = c2da_saved_sp
}
var pr_depth : int = default<int>

[export, sideeffects]
def PR_StackTrace() {
    var f_0 : int
    var i_0 : int
    if (pr_depth == 0) {
        Con_Printf(731125, [])
        return
    }
    pr_stack[pr_depth].f = int(pr_xfunction)  // nolint:PERF020
    i_0 = pr_depth
    while (i_0 >= 0) {
        f_0 = pr_stack[i_0].f
        if (f_0 == 0) {
            Con_Printf(731137, [])
        } else {
            Con_Printf(731152, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[f_0 + 20]) | uint(c2da_mem[f_0 + 21]) << 0x8 | uint(c2da_mem[f_0 + 22]) << 0x10 | uint(c2da_mem[f_0 + 23]) << 0x18))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[f_0 + 16]) | uint(c2da_mem[f_0 + 17]) << 0x8 | uint(c2da_mem[f_0 + 18]) << 0x10 | uint(c2da_mem[f_0 + 19]) << 0x18)))])
        }
        i_0--
    }
    return
}
var pr_stack : prstack_t[32]

var pr_xfunction : int = default<int>

var pr_xstatement : int = default<int>

[export, sideeffects]
def PR_PrintStatement(var s_0 : int) {
    var i_1 : int
    if (uint64(uint16(uint(c2da_mem[s_0]) | uint(c2da_mem[s_0 + 1]) << 0x8)) < 528ul / 8ul) {
        Con_Printf(731163, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_opnames[int(uint16(uint(c2da_mem[s_0]) | uint(c2da_mem[s_0 + 1]) << 0x8))]))])
        i_1 = int(c2da_lin_strlen(pr_opnames[int(uint16(uint(c2da_mem[s_0]) | uint(c2da_mem[s_0 + 1]) << 0x8))]))
        for (c2da_i_1 in range(i_1, 10)) {
            Con_Printf(731167, [])
        }
    }
    if (int(uint16(uint(c2da_mem[s_0]) | uint(c2da_mem[s_0 + 1]) << 0x8)) == 49 || int(uint16(uint(c2da_mem[s_0]) | uint(c2da_mem[s_0 + 1]) << 0x8)) == 50) {
        Con_Printf(731169, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(PR_GlobalString(int(int16(uint(c2da_mem[s_0 + 2]) | uint(c2da_mem[s_0 + 3]) << 0x8))))), C2daVaArg(tag = 1, i64 = int64(int16(uint(c2da_mem[s_0 + 4]) | uint(c2da_mem[s_0 + 5]) << 0x8)), f64 = 0.0lf, raw = 0x0)])
    } elif (int(uint16(uint(c2da_mem[s_0]) | uint(c2da_mem[s_0 + 1]) << 0x8)) == 61) {
        Con_Printf(731181, [C2daVaArg(tag = 1, i64 = int64(int16(uint(c2da_mem[s_0 + 2]) | uint(c2da_mem[s_0 + 3]) << 0x8)), f64 = 0.0lf, raw = 0x0)])
    } elif (uint(int(uint16(uint(c2da_mem[s_0]) | uint(c2da_mem[s_0 + 1]) << 0x8)) - 31) < 6u) {
        Con_Printf(731191, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(PR_GlobalString(int(int16(uint(c2da_mem[s_0 + 2]) | uint(c2da_mem[s_0 + 3]) << 0x8)))))])
        Con_Printf(731191, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(PR_GlobalStringNoContents(int(int16(uint(c2da_mem[s_0 + 4]) | uint(c2da_mem[s_0 + 5]) << 0x8)))))])
    } else {
        if (int16(uint(c2da_mem[s_0 + 2]) | uint(c2da_mem[s_0 + 3]) << 0x8) != 0) {
            Con_Printf(731191, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(PR_GlobalString(int(int16(uint(c2da_mem[s_0 + 2]) | uint(c2da_mem[s_0 + 3]) << 0x8)))))])
        }
        if (int16(uint(c2da_mem[s_0 + 4]) | uint(c2da_mem[s_0 + 5]) << 0x8) != 0) {
            Con_Printf(731191, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(PR_GlobalString(int(int16(uint(c2da_mem[s_0 + 4]) | uint(c2da_mem[s_0 + 5]) << 0x8)))))])
        }
        if (int16(uint(c2da_mem[s_0 + 6]) | uint(c2da_mem[s_0 + 7]) << 0x8) != 0) {
            Con_Printf(731191, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(PR_GlobalStringNoContents(int(int16(uint(c2da_mem[s_0 + 6]) | uint(c2da_mem[s_0 + 7]) << 0x8)))))])
        }
    }
    Con_Printf(731194, [])
    return
}
var pr_opnames : int[66] = fixed_array<int>(731196, 731201, 731207, 731213, 731220, 731227, 731231, 731237, 731243, 731249, 731255, 731260, 731265, 731270, 731275, 731282, 731287, 731292, 731297, 731302, 731309, 731312, 731315, 731318, 731321, 731321, 731321, 731321, 731321, 731321, 731330, 731338, 731346, 731354, 731362, 731372, 731382, 731392, 731401, 731410, 731419, 731430, 731441, 731452, 731459, 731465, 731471, 731477, 731485, 731493, 731496, 731502, 731508, 731514, 731520, 731526, 731532, 731538, 731544, 731550, 731556, 731562, 731567, 731571, 731574, 731581)

[export, sideeffects]
def PR_LeaveFunction() : int {
    var c_0 : int
    if (pr_depth <= 0) {
        Sys_Error(731587, [])
    }
    c_0 = int(uint(c2da_mem[pr_xfunction + 8]) | uint(c2da_mem[pr_xfunction + 9]) << 0x8 | uint(c2da_mem[pr_xfunction + 10]) << 0x10 | uint(c2da_mem[pr_xfunction + 11]) << 0x18)
    localstack_used -= c_0
    if (localstack_used < 0) {
        PR_RunError(731608, [])
    }
    for (i_2 in range(0, c_0)) {
        let c2da_fresh132 : int = pr_globals + (int(uint(c2da_mem[pr_xfunction + 4]) | uint(c2da_mem[pr_xfunction + 5]) << 0x8 | uint(c2da_mem[pr_xfunction + 6]) << 0x10 | uint(c2da_mem[pr_xfunction + 7]) << 0x18) + i_2) * 4
        let c2da_fresh133 : int = localstack[localstack_used + i_2]
        let c2da_fresh134 : uint = uint(c2da_fresh133)
        c2da_mem[c2da_fresh132] = uint8(c2da_fresh134)
        c2da_mem[c2da_fresh132 + 1] = uint8(c2da_fresh134 >> 0x8)
        c2da_mem[c2da_fresh132 + 2] = uint8(c2da_fresh134 >> 0x10)
        c2da_mem[c2da_fresh132 + 3] = uint8(c2da_fresh134 >> 0x18)
    }
    pr_depth--
    pr_xfunction = int(pr_stack[pr_depth].f)  // nolint:PERF020
    return pr_stack[pr_depth].s
}
var localstack_used : int = default<int>

var localstack : int[2048]

[export, sideeffects]
def PR_EnterFunction(var f_1 : int) : int {
    var i_3 : int
    var j : int
    var c_1 : int
    var o : int
    pr_stack[pr_depth].s = int(pr_xstatement)  // nolint:PERF020
    pr_stack[pr_depth].f = int(pr_xfunction)  // nolint:PERF020
    pr_depth++
    if (pr_depth >= 32) {
        PR_RunError(731651, [])
    }
    c_1 = int(uint(c2da_mem[f_1 + 8]) | uint(c2da_mem[f_1 + 9]) << 0x8 | uint(c2da_mem[f_1 + 10]) << 0x10 | uint(c2da_mem[f_1 + 11]) << 0x18)
    if (localstack_used + c_1 > 2048) {
        PR_RunError(731666, [])
    }
    i_3 = 0
    while (i_3 < c_1) {
        let c2da_fresh135 : int = pr_globals + (int(uint(c2da_mem[f_1 + 4]) | uint(c2da_mem[f_1 + 5]) << 0x8 | uint(c2da_mem[f_1 + 6]) << 0x10 | uint(c2da_mem[f_1 + 7]) << 0x18) + i_3) * 4
        localstack[localstack_used + i_3] = int(uint(c2da_mem[c2da_fresh135]) | uint(c2da_mem[c2da_fresh135 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh135 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh135 + 3]) << 0x18)
        i_3++
    }
    localstack_used += c_1
    o = int(uint(c2da_mem[f_1 + 4]) | uint(c2da_mem[f_1 + 5]) << 0x8 | uint(c2da_mem[f_1 + 6]) << 0x10 | uint(c2da_mem[f_1 + 7]) << 0x18)
    i_3 = 0
    while (i_3 < int(uint(c2da_mem[f_1 + 24]) | uint(c2da_mem[f_1 + 25]) << 0x8 | uint(c2da_mem[f_1 + 26]) << 0x10 | uint(c2da_mem[f_1 + 27]) << 0x18)) {
        j = 0
        while (j < int(c2da_mem[f_1 + 28 + i_3])) {
            let c2da_fresh136 : int = int(uint(c2da_mem[pr_globals + (4 + i_3 * 3 + j) * 4]) | uint(c2da_mem[pr_globals + (4 + i_3 * 3 + j) * 4 + 1]) << 0x8 | uint(c2da_mem[pr_globals + (4 + i_3 * 3 + j) * 4 + 2]) << 0x10 | uint(c2da_mem[pr_globals + (4 + i_3 * 3 + j) * 4 + 3]) << 0x18)
            let c2da_fresh137 : uint = uint(c2da_fresh136)
            c2da_mem[pr_globals + o * 4] = uint8(c2da_fresh137)
            c2da_mem[pr_globals + o * 4 + 1] = uint8(c2da_fresh137 >> 0x8)
            c2da_mem[pr_globals + o * 4 + 2] = uint8(c2da_fresh137 >> 0x10)
            c2da_mem[pr_globals + o * 4 + 3] = uint8(c2da_fresh137 >> 0x18)
            o++
            j++
        }
        i_3++
    }
    pr_xfunction = int(f_1)  // nolint:PERF020
    return int(uint(c2da_mem[f_1]) | uint(c2da_mem[f_1 + 1]) << 0x8 | uint(c2da_mem[f_1 + 2]) << 0x10 | uint(c2da_mem[f_1 + 3]) << 0x18) - 1
}
var pr_argc : int = default<int>

var pr_trace : uint = default<uint>

[export, sideeffects]
def PR_Profile_f() {
    var f_2 : int
    var best : int
    var max : int
    var num : int
    var i_4 : int
    num = 0
    while (true) {
        max = 0
        best = 0
        i_4 = 0
        while (i_4 < int(uint(c2da_mem[progs + 36]) | uint(c2da_mem[progs + 37]) << 0x8 | uint(c2da_mem[progs + 38]) << 0x10 | uint(c2da_mem[progs + 39]) << 0x18)) {
            f_2 = pr_functions + i_4 * 36
            let c2da_fresh140 : int = int(uint(c2da_mem[f_2 + 12]) | uint(c2da_mem[f_2 + 13]) << 0x8 | uint(c2da_mem[f_2 + 14]) << 0x10 | uint(c2da_mem[f_2 + 15]) << 0x18)
            if (c2da_fresh140 > max) {
                max = c2da_fresh140
                best = f_2
            }
            i_4++
        }
        if (best != 0) {
            if (num < 10) {
                Con_Printf(731708, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[best + 12]) | uint(c2da_mem[best + 13]) << 0x8 | uint(c2da_mem[best + 14]) << 0x10 | uint(c2da_mem[best + 15]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pr_strings + int(uint(c2da_mem[best + 16]) | uint(c2da_mem[best + 17]) << 0x8 | uint(c2da_mem[best + 18]) << 0x10 | uint(c2da_mem[best + 19]) << 0x18)))])
            }
            num++
            let c2da_fresh138 : int = 0
            let c2da_fresh139 : uint = uint(c2da_fresh138)
            c2da_mem[best + 12] = uint8(c2da_fresh139)
            c2da_mem[best + 13] = uint8(c2da_fresh139 >> 0x8)
            c2da_mem[best + 14] = uint8(c2da_fresh139 >> 0x10)
            c2da_mem[best + 15] = uint8(c2da_fresh139 >> 0x18)
        }
        if (best == 0) {
            break
        }
    }
    return
}
[sideeffects]
def private PR_RunError_c2da_frame(var error : int; c2da_va_args : array<C2daVaArg>; c2da_fp : int) {
    var argptr : C2daVaCursor = C2daVaCursor(index = 0)
    argptr.index = 0
    c2da_lin_vsnprintf(c2da_fp, 2147483647ul, error, argptr, c2da_va_args)
    argptr.index = -1
    PR_PrintStatement(pr_statements + pr_xstatement * 8)
    PR_StackTrace()
    Con_Printf(731107, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    pr_depth = 0
    Host_Error(731111, [])
    return
}

// This unit's static data, at heap offset 730976.
let private c2da_lin_static_pr_exec_seg = fixed_array<int>(730976, 739)
let private c2da_lin_static_pr_exec = fixed_array<uint64>(0x75636578455f5250ul, 0x6172676f72506574ul, 0x204c4c554e203a6dul, 0x6e6f6974636e7566ul, 0x796177616e757200ul, 0x726520706f6f6c20ul, 0x6973736100726f72ul, 0x7420746e656d6e67ul, 0x20646c726f77206ful, 0x4e00797469746e65ul, 0x636e7566204c4c55ul, 0x646142006e6f6974ul, 0x6e69746c69756220ul, 0x756e206c6c616320ul, 0x646142007265626dul, 0x2065646f63706f20ul, 0x50000a7325006925ul, 0x65206d6172676f72ul, 0x4f4e3c00726f7272ul, 0xa3e4b4341545320ul, 0x4e5546204f4e3c00ul, 0xa3e4e4f495443ul, 0x25203a2073323125ul, 0x2000207325000a73ul, 0x636e617262732500ul, 0x6172620069252068ul, 0x250069252068636eul, 0x454e4f44000a0073ul, 0x4d00465f4c554d00ul, 0x4c554d00565f4c55ul, 0x5f4c554d0056465ful, 0x4100564944004656ul, 0x44444100465f4444ul, 0x465f42555300565ful, 0x4500565f42555300ul, 0x565f514500465f51ul, 0x514500535f514500ul, 0x4e465f514500455ful, 0x4e00465f454e0043ul, 0x535f454e00565f45ul, 0x454e00455f454e00ul, 0x454c00434e465ful, 0x544700544c004547ul, 0x43455249444e4900ul, 0x5345524444410054ul, 0x5f45524f54530053ul, 0x5f45524f54530046ul, 0x5f45524f54530056ul, 0x5f45524f54530053ul, 0x524f545300544e45ul, 0x545300444c465f45ul, 0x434e465f45524ful, 0x465f5045524f5453ul, 0x5f5045524f545300ul, 0x5045524f54530056ul, 0x45524f545300535ful, 0x545300544e455f50ul, 0x444c465f5045524ful, 0x5f5045524f545300ul, 0x5554455200434e46ul, 0x465f544f4e004e52ul, 0x4e00565f544f4e00ul, 0x544f4e00535f544ful, 0x544f4e00544e455ful, 0x464900434e465ful, 0x414300544f4e4649ul, 0x4c4c414300304c4cul, 0x324c4c41430031ul, 0x414300334c4c4143ul, 0x4c4c414300344c4cul, 0x364c4c41430035ul, 0x414300374c4c4143ul, 0x5441545300384c4cul, 0x41004f544f470045ul, 0x494200524f00444eul, 0x54494200444e4154ul, 0x20676f727000524ful, 0x6e75206b63617473ul, 0x776f6c66726564ul, 0x75636578455f5250ul, 0x6172676f72506574ul, 0x6c61636f6c203a6dul, 0x206b636174732073ul, 0x6f6c667265646e75ul, 0x6b63617473000a77ul, 0x6f6c667265766f20ul, 0x6578455f52500077ul, 0x676f725065747563ul, 0x636f6c203a6d6172ul, 0x6361747320736c61ul, 0x6c667265766f206bul, 0x20693725000a776ful, 0xa7325ul)

[init]
def private c2da_lin_init_static_pr_exec() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_pr_exec_seg[s * 2]
        for (k in range(c2da_lin_static_pr_exec_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_pr_exec[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_pr_exec() {
    if (length(c2da_fn_table0) < 202) {
        resize(c2da_fn_table0, 202)
    }
    c2da_fn_table0[201] = @@PR_Profile_f
}

[init]
def private c2da_lin_relink_init_pr_exec() {
    c2da_relink_pr_exec()
}
