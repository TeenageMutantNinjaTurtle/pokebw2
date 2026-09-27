#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    VMStackPushFlag 2406
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_001F
    Cmd_0262 3, 4

L_001F:
    VMHalt
    .balign 4, 0
