#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_1:
    FlagGet 367, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_003B
    BMSetVisible 8, 31, 50, 0
    RTReserveScript 2

L_003B:
    VMHalt

Script_2:
    ActorsPauseAll
    FlagReset 367
    BMSetVisible 8, 31, 50, 1
    BMCreateHandleByGPos 0x8020, 8, 31, 50
    BMHndAudioVisualAnmPlay 0x8020, 0
    BMHndAnmWait 0x8020
    BMReleaseHandle 0x8020
    SEPlay 1879
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    FlagGet 2407, 0x8021
    FlagGet 2408, 0x8022
    FlagGet 2409, 0x8023
    FlagGet 2410, 0x8024
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_00EC
    CallLeagueLiftWarp
    VMJump L_00F9

L_00EC:
    SEPlay 1351
    InfoMsg 0, 2
    LastKeyWait
    MsgWinCloseAll

L_00F9:
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
