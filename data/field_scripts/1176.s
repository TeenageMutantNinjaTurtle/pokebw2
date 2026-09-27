#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd

L_000A:
    WorkSetConst 0x8020, 0
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0045
    ObjInitWarpGPos 3, 0xff08, 0, 248
    ObjInitWarpGPos 2, 0xff08, 0, 232
    FlagSet 1039
    VMJump L_005D

L_0045:
    ObjInitWarpGPos 0, 0xff08, 0, 248
    ObjInitWarpGPos 1, 0xff08, 0, 232
    FlagSet 1040

L_005D:
    VMReturn

Script_1:
    VMCall L_000A
    VMHalt

Script_2:
    VMCall L_000A
    VMHalt
    .balign 4, 0
