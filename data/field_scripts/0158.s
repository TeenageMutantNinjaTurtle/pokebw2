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

Script_7:
    VMStackPush 0x4160
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0043
    VMCall L_0045

L_0043:
    VMHalt

L_0045:
    RTCGetWeekDay 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0076
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0076
    WorkCmpConst 0x8010, 4
    VMJumpIf 1, L_0076
    VMJump L_00B5

L_0076:
    WorkSetConst 0x4160, 1
    WorkSetConst 0x4020, 57
    RTCGetTime 0x8008, 0x8009
    VMStackPush 0x8008
    VMStackPushConst 14
    VMStackCmp 4
    VMStackPush 0x8008
    VMStackPushConst 16
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_00AF
    FlagSet 220

L_00AF:
    VMJump L_014D

L_00B5:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_00D5
    WorkCmpConst 0x8010, 5
    VMJumpIf 1, L_00D5
    VMJump L_0114

L_00D5:
    WorkSetConst 0x4160, 2
    WorkSetConst 0x4020, 58
    RTCGetTime 0x8008, 0x8009
    VMStackPush 0x8008
    VMStackPushConst 14
    VMStackCmp 4
    VMStackPush 0x8008
    VMStackPushConst 15
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_010E
    FlagSet 220

L_010E:
    VMJump L_014D

L_0114:
    WorkSetConst 0x4160, 3
    WorkSetConst 0x4020, 59
    RTCGetTime 0x8008, 0x8009
    VMStackPush 0x8008
    VMStackPushConst 14
    VMStackCmp 4
    VMStackPush 0x8008
    VMStackPushConst 15
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_014D
    FlagSet 220

L_014D:
    VMStackPushFlag 220
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_016E
    FlagReset 655
    FlagSet 666
    VMJump L_0176

L_016E:
    FlagSet 655
    FlagReset 666

L_0176:
    VMStackPushFlag 2741
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01B7
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

L_01B7:
    VMReturn

Script_6:
    ActorsPauseAll
    VMStackPush 0x4160
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01DE
    MapChangeWarpPad 82, 9, 61, 0
    VMJump L_020B

L_01DE:
    VMStackPush 0x4160
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0201
    MapChangeWarpPad 83, 10, 29, 0
    VMJump L_020B

L_0201:
    MapChangeWarpPad 81, 9, 29, 0

L_020B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkCmpConst 0x4160, 3
    VMJumpIf 1, L_022C
    VMJump L_025F

L_022C:
    VMStackPushFlag 220
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_024F
    ParentActorMsg 1024, 0, 0, 0
    VMJump L_0259

L_024F:
    ParentActorMsg 1024, 1, 0, 0

L_0259:
    VMJump L_02D2

L_025F:
    WorkCmpConst 0x4160, 1
    VMJumpIf 1, L_0272
    VMJump L_02A5

L_0272:
    VMStackPushFlag 220
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0295
    ParentActorMsg 1024, 2, 0, 0
    VMJump L_029F

L_0295:
    ParentActorMsg 1024, 3, 0, 0

L_029F:
    VMJump L_02D2

L_02A5:
    VMStackPushFlag 220
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02C8
    ParentActorMsg 1024, 4, 0, 0
    VMJump L_02D2

L_02C8:
    ParentActorMsg 1024, 5, 0, 0

L_02D2:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkCmpConst 0x4160, 3
    VMJumpIf 1, L_032F
    VMJump L_033F

L_032F:
    ParentActorMsg 1024, 8, 0, 0
    VMJump L_036C

L_033F:
    WorkCmpConst 0x4160, 1
    VMJumpIf 1, L_0352
    VMJump L_0362

L_0352:
    ParentActorMsg 1024, 9, 0, 0
    VMJump L_036C

L_0362:
    ParentActorMsg 1024, 10, 0, 0

L_036C:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkCmpConst 0x4160, 3
    VMJumpIf 1, L_0391
    VMJump L_03A1

L_0391:
    ParentActorMsg 1024, 11, 0, 0
    VMJump L_03CE

L_03A1:
    WorkCmpConst 0x4160, 1
    VMJumpIf 1, L_03B4
    VMJump L_03C4

L_03B4:
    ParentActorMsg 1024, 12, 0, 0
    VMJump L_03CE

L_03C4:
    ParentActorMsg 1024, 13, 0, 0

L_03CE:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
