#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

L_002A:
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0065
    ObjInitWarpGPos 1, 655, 0xfffe, 289
    ObjInitWarpGPos 3, 667, 0xffff, 304
    ObjInitWarpGPos 5, 671, 0xffff, 299
    VMJump L_0083

L_0065:
    ObjInitWarpGPos 0, 655, 0xfffe, 289
    ObjInitWarpGPos 2, 667, 0xffff, 304
    ObjInitWarpGPos 4, 671, 0xffff, 299

L_0083:
    VMReturn

Script_1:
    VMCall L_002A
    VMStackPushFlag 2406
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00A4
    Cmd_0262 3, 5

L_00A4:
    VMHalt

Script_4:
    VMCall L_002A
    VMHalt

Script_2:
    VMHalt

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 0, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
