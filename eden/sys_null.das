options gen2
options stack = 4194304
module sys_null public

require dasquake_runtime
require strings
require daslib/math_bits
var private Sys_FloatTime__t : double = 0.0lf

[export, sideeffects]
def Sys_FileOpenRead(var path : int; var hndl : int) : int {
    var f : int
    var i : int = findhandle()
    f = c2da_lin_fopen(path, 737280)
    if (f == 0) {
        let c2da_fresh0 : int = -1
        let c2da_fresh1 : uint = uint(c2da_fresh0)
        c2da_mem[hndl] = uint8(c2da_fresh1)
        c2da_mem[hndl + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[hndl + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[hndl + 3] = uint8(c2da_fresh1 >> 0x18)
        return -1
    }
    sys_handles[i] = f
    let c2da_fresh2 : uint = uint(i)
    c2da_mem[hndl] = uint8(c2da_fresh2)
    c2da_mem[hndl + 1] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[hndl + 2] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[hndl + 3] = uint8(c2da_fresh2 >> 0x18)
    return filelength(f)
}
[export, sideeffects]
def filelength(var f_0 : int) : int {
    var pos : int
    var end : int
    pos = int(c2da_std_ftell(uint64(f_0)))
    c2da_std_fseek(uint64(f_0), 0l, 2)
    end = int(c2da_std_ftell(uint64(f_0)))
    c2da_std_fseek(uint64(f_0), int64(pos), 0)
    return end
}
var sys_handles : int[10]

[export, sideeffects]
def findhandle() : int {
    for (i_0 in range(1, 10)) {
        if (sys_handles[i_0] == 0) {
            return i_0
        }
    }
    Sys_Error(737283, [])
    return -1
}
[export, sideeffects]
def Sys_Error(var error : int; c2da_va_args : array<C2daVaArg>) {
    var argptr : C2daVaCursor = C2daVaCursor(index = 0)
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 737298, [])
    argptr.index = 0
    c2da_lin_vprintf(uint64(int(c2da_std_stderr())), error, argptr, c2da_va_args)
    argptr.index = -1
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 737310, [])
    c2da_std_exit(1)
    return
}
[export, sideeffects]
def Sys_FileOpenWrite(var path_0 : int) : int {
    var f_1 : int
    var i_1 : int = findhandle()
    f_1 = c2da_lin_fopen(path_0, 737312)
    if (f_1 == 0) {
        Sys_Error(737315, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(path_0)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_lin_strerror(int(uint(c2da_mem[8]) | uint(c2da_mem[9]) << 0x8 | uint(c2da_mem[10]) << 0x10 | uint(c2da_mem[11]) << 0x18))))])
    }
    sys_handles[i_1] = f_1
    return i_1
}
[export, sideeffects]
def Sys_FileClose(var handle : int) {
    c2da_std_fclose(uint64(sys_handles[handle]))
    sys_handles[handle] = 0
    return
}
[export, sideeffects]
def Sys_FileSeek(var handle_0 : int; var position : int) {
    c2da_std_fseek(uint64(sys_handles[handle_0]), int64(position), 0)
    return
}
[export, sideeffects]
def Sys_FileRead(var handle_1 : int; var dest : int; var count : int) : int {
    return int(c2da_lin_fread(dest, 1ul, uint64(count), uint64(sys_handles[handle_1])))
}
[export, sideeffects]
def Sys_FileWrite(var handle_2 : int; var data : int; var count_0 : int) : int {
    return int(c2da_lin_fwrite(data, 1ul, uint64(count_0), uint64(sys_handles[handle_2])))
}
[export, sideeffects]
def Sys_FileTime(var path_1 : int) : int {
    var f_2 : int = c2da_lin_fopen(path_1, 737280)
    if (f_2 != 0) {
        c2da_std_fclose(uint64(f_2))
        return 1
    }
    return -1
}
[export, sideeffects]
def Sys_mkdir(var path_2 : int) {
    return
}
[export, sideeffects]
def Sys_MakeCodeWriteable(var startaddr : uint64; var length_0 : uint64) {
    return
}
[export, sideeffects]
def Sys_Printf(var fmt_0 : int; c2da_va_args : array<C2daVaArg>) {
    var argptr_0 : C2daVaCursor = C2daVaCursor(index = 0)
    argptr_0.index = 0
    c2da_lin_vprintf(uint64(int(c2da_std_stderr())), fmt_0, argptr_0, c2da_va_args)
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
def Sys_ConsoleInput() : int {
    return 0
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
var isDedicated : uint


// This unit's static data, at heap offset 737280.
let private c2da_lin_static_sys_null_seg = fixed_array<int>(737280, 55)
let private c2da_lin_static_sys_null = fixed_array<uint64>(0x6f2074756f006272ul, 0x656c646e61682066ul, 0x72455f7379530073ul, 0xa00203a726f72ul, 0x726f727245006277ul, 0x676e696e65706f20ul, 0x7325203a732520ul)

[init]
def private c2da_lin_init_static_sys_null() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_sys_null_seg[s * 2]
        for (k in range(c2da_lin_static_sys_null_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_sys_null[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
