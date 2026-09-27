#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntry Script_9
    ScriptEntry Script_10
    ScriptEntriesEnd

Script_4:
    VMStackPush 0x4160
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0043
    VMCall L_0045

L_0043:
    VMHalt

L_0045:
    RTCGetWeekDay 0x8010
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0076
    WorkCmpConst 0x8010, 4
    VMJumpIf 1, L_0076
    WorkCmpConst 0x8010, 6
    VMJumpIf 1, L_0076
    VMJump L_00B5

L_0076:
    WorkSetConst 0x4160, 5
    WorkSetConst 0x4020, 133
    RTCGetTime 0x8008, 0x8009
    VMStackPush 0x8008
    VMStackPushConst 10
    VMStackCmp 4
    VMStackPush 0x8008
    VMStackPushConst 11
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_00AF
    FlagSet 220

L_00AF:
    VMJump L_00DE

L_00B5:
    WorkSetConst 0x4160, 4
    WorkSetConst 0x4020, 60
    RTCGetTime 0x8008, 0x8009
    VMStackPush 0x8008
    VMStackPushConst 10
    VMStackCmp 1
    VMJumpIf 255, L_00DE
    FlagSet 220

L_00DE:
    VMStackPushFlag 220
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00FF
    FlagReset 655
    FlagSet 666
    VMJump L_0107

L_00FF:
    FlagSet 655
    FlagReset 666

L_0107:
    VMStackPushFlag 2741
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0148
    StadiumLoadTrainerTable
    StadiumResetTrainerFlags
    StadiumFreeTrainerTable
    FlagSet 2741
    WorkSetConst 0x416d, 0
    WorkSetConst 0x416e, 0
    WorkSetConst 0x416f, 0
    WorkSetConst 0x4170, 0
    WorkSetConst 0x4171, 0
    WorkSetConst 0x4172, 0

L_0148:
    VMReturn

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkCmpConst 0x4160, 4
    VMJumpIf 1, L_0165
    VMJump L_0198

L_0165:
    VMStackPushFlag 220
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0188
    ParentActorMsg 1024, 0, 0, 0
    VMJump L_0192

L_0188:
    ParentActorMsg 1024, 1, 0, 0

L_0192:
    VMJump L_01C5

L_0198:
    VMStackPushFlag 220
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01BB
    ParentActorMsg 1024, 2, 0, 0
    VMJump L_01C5

L_01BB:
    ParentActorMsg 1024, 3, 0, 0

L_01C5:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    VMStackPush 0x4160
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_01F4
    MapChangeWarpPad 87, 6, 25, 0
    VMJump L_01FE

L_01F4:
    MapChangeWarpPad 86, 6, 25, 0

L_01FE:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkCmpConst 0x4160, 4
    VMJumpIf 1, L_02C7
    VMJump L_02D7

L_02C7:
    ParentActorMsg 1024, 7, 0, 0
    VMJump L_02E1

L_02D7:
    ParentActorMsg 1024, 8, 0, 0

L_02E1:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
