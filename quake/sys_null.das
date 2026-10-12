options gen2
options solid_context = true
options stack = 4194304
module sys_null public

require dasquake_runtime
require strings
require daslib/fio
var private c2da_str_0 : array<int8> = [int8(114), int8(98), int8(0)]

var private c2da_str_1 : array<int8> = [int8(111), int8(117), int8(116), int8(32), int8(111), int8(102), int8(32), int8(104), int8(97), int8(110), int8(100), int8(108), int8(101), int8(115), int8(0)]

var private c2da_str_2 : array<int8> = [int8(83), int8(121), int8(115), int8(95), int8(69), int8(114), int8(114), int8(111), int8(114), int8(58), int8(32), int8(0)]

var private c2da_str_3 : array<int8> = [int8(10), int8(0)]

var private c2da_str_4 : array<int8> = [int8(119), int8(98), int8(0)]

var private c2da_str_5 : array<int8> = [int8(69), int8(114), int8(114), int8(111), int8(114), int8(32), int8(111), int8(112), int8(101), int8(110), int8(105), int8(110), int8(103), int8(32), int8(37), int8(115), int8(58), int8(32), int8(37), int8(115), int8(0)]

var private Sys_FloatTime__t : double = 0.0lf

[export, sideeffects]
def Sys_FileOpenRead(var path : int8?; var hndl : int?) : int {
    var f : _IO_FILE?
    var i : int = findhandle()
    f = unsafe(reinterpret<_IO_FILE?>(unsafe(reinterpret<_IO_FILE?>(c2da_std_fopen(unsafe(reinterpret<int8 const?>(path)), unsafe(addr<int8 const?>(c2da_str_0[0])))))))
    if (f == null) {
        *hndl = -1
        return -1
    }
    sys_handles[i] = unsafe(reinterpret<_IO_FILE?>(f))
    *hndl = i
    return filelength(f)
}
[export, sideeffects]
def filelength(var f_0 : _IO_FILE?) : int {
    var pos : int
    var end : int
    pos = int(c2da_std_ftell(unsafe(reinterpret<uint64>(f_0))))
    c2da_std_fseek(unsafe(reinterpret<uint64>(f_0)), 0l, 2)
    end = int(c2da_std_ftell(unsafe(reinterpret<uint64>(f_0))))
    c2da_std_fseek(unsafe(reinterpret<uint64>(f_0)), int64(pos), 0)
    return end
}
var sys_handles : _IO_FILE? [10]

[export, sideeffects]
def findhandle() : int {
    for (i_0 in range(1, 10)) {
        if (sys_handles[i_0] == null) {
            return i_0
        }
    }
    Sys_Error(unsafe(addr<int8?>(c2da_str_1[0])), [])
    return -1
}
[export, sideeffects]
def Sys_Error(var error : int8?; c2da_va_args : array<C2daVaArg>) {
    var argptr : C2daVaCursor = C2daVaCursor(index = 0)
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_2[0])), [])
    argptr.index = 0
    c2da_std_vfprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(reinterpret<int8 const?>(error)), argptr, c2da_va_args)
    argptr.index = -1
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_3[0])), [])
    c2da_std_exit(1)
    return
}
[export, sideeffects]
def Sys_FileOpenWrite(var path_0 : int8?) : int {
    var f_1 : _IO_FILE?
    var i_1 : int = findhandle()
    f_1 = unsafe(reinterpret<_IO_FILE?>(unsafe(reinterpret<_IO_FILE?>(c2da_std_fopen(unsafe(reinterpret<int8 const?>(path_0)), unsafe(addr<int8 const?>(c2da_str_4[0])))))))
    if (f_1 == null) {
        Sys_Error(unsafe(addr<int8?>(c2da_str_5[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(path_0))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(reinterpret<int8?>(c2da_std_strerror(*unsafe(reinterpret<int?>(c2da_std_errno_location()))))))))])
    }
    sys_handles[i_1] = unsafe(reinterpret<_IO_FILE?>(f_1))
    return i_1
}
[export, sideeffects]
def Sys_FileClose(var handle : int) {
    c2da_std_fclose(unsafe(reinterpret<uint64>(sys_handles[handle])))
    sys_handles[handle] = null
    return
}
[export, sideeffects]
def Sys_FileSeek(var handle_0 : int; var position : int) {
    c2da_std_fseek(unsafe(reinterpret<uint64>(sys_handles[handle_0])), int64(position), 0)
    return
}
[export, sideeffects]
def Sys_FileRead(var handle_1 : int; var dest : uint8?; var count : int) : int {
    return int(c2da_std_fread(unsafe(reinterpret<uint64>(dest)), 1ul, uint64(count), unsafe(reinterpret<uint64>(sys_handles[handle_1]))))
}
[export, sideeffects]
def Sys_FileWrite(var handle_2 : int; var data : uint8?; var count_0 : int) : int {
    return int(c2da_std_fwrite(unsafe(reinterpret<uint64>(data)), 1ul, uint64(count_0), unsafe(reinterpret<uint64>(sys_handles[handle_2]))))
}
[export, sideeffects]
def Sys_FileTime(var path_1 : int8?) : int {
    var f_2 : _IO_FILE? = unsafe(reinterpret<_IO_FILE?>(unsafe(reinterpret<_IO_FILE?>(c2da_std_fopen(unsafe(reinterpret<int8 const?>(path_1)), unsafe(addr<int8 const?>(c2da_str_0[0])))))))
    if (f_2 != null) {
        c2da_std_fclose(unsafe(reinterpret<uint64>(f_2)))
        return 1
    }
    return -1
}
[export, sideeffects]
def Sys_mkdir(var path_2 : int8?) {
    return
}
[export, sideeffects]
def Sys_MakeCodeWriteable(var startaddr : uint64; var length_0 : uint64) {
    return
}
[export, sideeffects]
def Sys_Printf(var fmt_0 : int8?; c2da_va_args : array<C2daVaArg>) {
    var argptr_0 : C2daVaCursor = C2daVaCursor(index = 0)
    argptr_0.index = 0
    c2da_std_vfprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(reinterpret<int8 const?>(fmt_0)), argptr_0, c2da_va_args)
    argptr_0.index = -1
    return
}
[export, sideeffects]
def Sys_Quit() {
    c2da_std_exit(0)
    return
}
[export, sideeffects]
def Sys_FloatTime() : double {
    Sys_FloatTime__t += 0.1lf
    return Sys_FloatTime__t
}
[export, sideeffects]
def Sys_ConsoleInput() : int8? {
    return unsafe(reinterpret<int8?>(null))
}
[export, sideeffects]
def Sys_Sleep() {
    return
}
[export, sideeffects]
def Sys_SendKeyEvents() {
    return
}
[export, sideeffects]
def Sys_LowFPPrecision() {
    return
}
[export, sideeffects]
def Sys_HighFPPrecision() {
    return
}
var isDedicated : qboolean

[sideeffects]
def private c2da_layout_proofs() {
    static_assert(typeinfo sizeof(type<c2da___va_list_tag>) == 24, "C layout of c2da___va_list_tag: sizeof")
    static_assert(typeinfo alignof(type<c2da___va_list_tag>) == 8, "C layout of c2da___va_list_tag: alignof")
    static_assert(typeinfo offsetof<gp_offset>(type<c2da___va_list_tag>) == 0, "C layout of c2da___va_list_tag: offsetof gp_offset")
    static_assert(typeinfo offsetof<fp_offset>(type<c2da___va_list_tag>) == 4, "C layout of c2da___va_list_tag: offsetof fp_offset")
    static_assert(typeinfo offsetof<overflow_arg_area>(type<c2da___va_list_tag>) == 8, "C layout of c2da___va_list_tag: offsetof overflow_arg_area")
    static_assert(typeinfo offsetof<reg_save_area>(type<c2da___va_list_tag>) == 16, "C layout of c2da___va_list_tag: offsetof reg_save_area")
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
