options gen2
options stack = 4194304
module cd_null public

require dasquake_runtime
require daslib/math_bits
[export, sideeffects]
def CDAudio_Init() : int {
    return 0
}
[export, sideeffects]
def CDAudio_Play(var track : uint8; var looping : uint) {
    return
}
[export, sideeffects]
def CDAudio_Stop() {
    return
}
[export, sideeffects]
def CDAudio_Pause() {
    return
}
[export, sideeffects]
def CDAudio_Resume() {
    return
}
[export, sideeffects]
def CDAudio_Shutdown() {
    return
}
[export, sideeffects]
def CDAudio_Update() {
    return
}
