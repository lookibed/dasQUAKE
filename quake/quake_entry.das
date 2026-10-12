options gen2
options solid_context = true
options stack = 4194304

require dasquake_runtime
require chase_cluster
require quakegeneric
require strings
require daslib/fio
var private c2da_str_0 : array<int8> = [int8(108), int8(111), int8(97), int8(100), int8(61), int8(48), int8(10), int8(0)]

var private c2da_str_1 : array<int8> = [int8(113), int8(117), int8(97), int8(107), int8(101), int8(0)]

var private c2da_str_2 : array<int8> = [int8(45), int8(98), int8(97), int8(115), int8(101), int8(100), int8(105), int8(114), int8(0)]

var private c2da_str_3 : array<int8> = [int8(43), int8(116), int8(105), int8(109), int8(101), int8(100), int8(101), int8(109), int8(111), int8(0)]

var private c2da_str_4 : array<int8> = [int8(100), int8(101), int8(109), int8(111), int8(49), int8(0)]

var private c2da_str_5 : array<int8> = [int8(102), int8(114), int8(97), int8(109), int8(101), int8(115), int8(61), int8(37), int8(100), int8(32), int8(116), int8(105), int8(99), int8(107), int8(115), int8(61), int8(37), int8(100), int8(10), int8(0)]

var private c2da_str_6 : array<int8> = [int8(102), int8(114), int8(97), int8(109), int8(101), int8(91), int8(37), int8(100), int8(93), int8(61), int8(37), int8(100), int8(10), int8(0)]

var private c2da_str_7 : array<int8> = [int8(102), int8(114), int8(97), int8(109), int8(101), int8(115), int8(61), int8(37), int8(100), int8(10), int8(0)]

var private quake_argv : int8? [6]

[sideeffects]
def private main_0(var argc : int; var argv : int8??) : int {
    var i : int
    var ticks : int
    i = 0
    ticks = 0
    c2da_std_setvbuf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stdout())))), unsafe(reinterpret<uint64>(null)), 2, 0ul)
    if (argc < 2) {
        c2da_std_printf(unsafe(addr<int8 const?>(c2da_str_0[0])), [])
        return 2
    }
    quake_argv[0] = unsafe(addr<int8?>(c2da_str_1[0]))
    quake_argv[1] = unsafe(addr<int8?>(c2da_str_2[0]))
    quake_argv[2] = unsafe(reinterpret<int8?>(unsafe(argv[argc - 1])))
    quake_argv[3] = unsafe(addr<int8?>(c2da_str_3[0]))
    quake_argv[4] = unsafe(addr<int8?>(c2da_str_4[0]))
    quake_argv[5] = null
    QG_Create(5, unsafe(addr<int8??>(quake_argv[0])))
    while (qg_frame_count < 100 && ticks < 2000) {
        QG_Tick(qg_frame_seconds)
        ticks++
    }
    if (qg_frame_count < 100) {
        c2da_std_printf(unsafe(addr<int8 const?>(c2da_str_5[0])), [C2daVaArg(tag = 1, i64 = int64(qg_frame_count), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(ticks), f64 = 0.0lf, raw = 0x0)])
        return 1
    }
    i = 0
    for (c2da_i in range(i, 100)) {
        c2da_std_printf(unsafe(addr<int8 const?>(c2da_str_6[0])), [C2daVaArg(tag = 1, i64 = int64(c2da_i), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(unsafe(unsafe(addr(qg_frame_hash[0]))[c2da_i])), f64 = 0.0lf, raw = 0x0)])
    }
    c2da_std_printf(unsafe(addr<int8 const?>(c2da_str_7[0])), [C2daVaArg(tag = 1, i64 = 100l, f64 = 0.0lf, raw = 0x0)])
    return 0
}
[export, sideeffects]
def main() : int {
    let raw = get_command_line_arguments()
    if (empty(raw)) {
        return main_0(0, null)
    }
    var script : int = 0
    var i : int = 1
    while (i < length(raw)) {
        if (ends_with(raw[i], ".das")) {
            script = i
            break
        }
        i++
    }
    var first : int = script + 1
    i = 0
    while (i < length(raw)) {
        if (raw[i] == "--") {
            first = i + 1
            break
        }
        i++
    }
    var argc : int = 1 + (length(raw) - first)
    if (argc < 1) {
        argc = 1
    }
    var argv_raw : uint64 = c2da_rt_malloc(uint64(argc + 1) * 0x8ul + 0x7ul)
    var argv_bytes : uint64 = (argv_raw + 0x7ul) / 0x8ul * 0x8ul
    unsafe(unsafe(reinterpret<uint64?>(argv_bytes))[0]) = c2da_std_store(raw[script])
    var at : int = 1
    i = first
    while (i < length(raw)) {
        unsafe(unsafe(reinterpret<uint64?>(argv_bytes))[at]) = c2da_std_store(raw[i])
        at++
        i++
    }
    unsafe(unsafe(reinterpret<uint64?>(argv_bytes))[argc]) = 0x0ul
    return main_0(argc, unsafe(reinterpret<int8??>(argv_bytes)))
}
[sideeffects]
def private c2da_layout_proofs() {
    static_assert(typeinfo sizeof(type<_IO_FILE>) == 216, "C layout of _IO_FILE: sizeof")
    static_assert(typeinfo alignof(type<_IO_FILE>) == 8, "C layout of _IO_FILE: alignof")
    static_assert(typeinfo offsetof<_flags>(type<_IO_FILE>) == 0, "C layout of _IO_FILE: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<_IO_FILE>) == 8, "C layout of _IO_FILE: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<_IO_FILE>) == 16, "C layout of _IO_FILE: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<_IO_FILE>) == 24, "C layout of _IO_FILE: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<_IO_FILE>) == 32, "C layout of _IO_FILE: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<_IO_FILE>) == 40, "C layout of _IO_FILE: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<_IO_FILE>) == 48, "C layout of _IO_FILE: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<_IO_FILE>) == 56, "C layout of _IO_FILE: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<_IO_FILE>) == 64, "C layout of _IO_FILE: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<_IO_FILE>) == 72, "C layout of _IO_FILE: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<_IO_FILE>) == 80, "C layout of _IO_FILE: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<_IO_FILE>) == 88, "C layout of _IO_FILE: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<_IO_FILE>) == 96, "C layout of _IO_FILE: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<_IO_FILE>) == 104, "C layout of _IO_FILE: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<_IO_FILE>) == 112, "C layout of _IO_FILE: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<_IO_FILE>) == 116, "C layout of _IO_FILE: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<_IO_FILE>) == 120, "C layout of _IO_FILE: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<_IO_FILE>) == 128, "C layout of _IO_FILE: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<_IO_FILE>) == 130, "C layout of _IO_FILE: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<_IO_FILE>) == 131, "C layout of _IO_FILE: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<_IO_FILE>) == 136, "C layout of _IO_FILE: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<_IO_FILE>) == 144, "C layout of _IO_FILE: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<_IO_FILE>) == 152, "C layout of _IO_FILE: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<_IO_FILE>) == 160, "C layout of _IO_FILE: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<_IO_FILE>) == 168, "C layout of _IO_FILE: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<_IO_FILE>) == 176, "C layout of _IO_FILE: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<_IO_FILE>) == 184, "C layout of _IO_FILE: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<_IO_FILE>) == 192, "C layout of _IO_FILE: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<_IO_FILE>) == 196, "C layout of _IO_FILE: offsetof _unused2")
    static_assert(typeinfo sizeof(type<FILE_0>) == 216, "C layout of FILE_0: sizeof")
    static_assert(typeinfo alignof(type<FILE_0>) == 8, "C layout of FILE_0: alignof")
    static_assert(typeinfo offsetof<_flags>(type<FILE_0>) == 0, "C layout of FILE_0: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<FILE_0>) == 8, "C layout of FILE_0: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<FILE_0>) == 16, "C layout of FILE_0: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<FILE_0>) == 24, "C layout of FILE_0: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<FILE_0>) == 32, "C layout of FILE_0: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<FILE_0>) == 40, "C layout of FILE_0: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<FILE_0>) == 48, "C layout of FILE_0: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<FILE_0>) == 56, "C layout of FILE_0: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<FILE_0>) == 64, "C layout of FILE_0: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<FILE_0>) == 72, "C layout of FILE_0: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<FILE_0>) == 80, "C layout of FILE_0: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<FILE_0>) == 88, "C layout of FILE_0: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<FILE_0>) == 96, "C layout of FILE_0: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<FILE_0>) == 104, "C layout of FILE_0: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<FILE_0>) == 112, "C layout of FILE_0: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<FILE_0>) == 116, "C layout of FILE_0: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<FILE_0>) == 120, "C layout of FILE_0: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<FILE_0>) == 128, "C layout of FILE_0: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<FILE_0>) == 130, "C layout of FILE_0: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<FILE_0>) == 131, "C layout of FILE_0: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<FILE_0>) == 136, "C layout of FILE_0: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<FILE_0>) == 144, "C layout of FILE_0: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<FILE_0>) == 152, "C layout of FILE_0: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<FILE_0>) == 160, "C layout of FILE_0: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<FILE_0>) == 168, "C layout of FILE_0: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<FILE_0>) == 176, "C layout of FILE_0: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<FILE_0>) == 184, "C layout of FILE_0: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<FILE_0>) == 192, "C layout of FILE_0: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<FILE_0>) == 196, "C layout of FILE_0: offsetof _unused2")
}
