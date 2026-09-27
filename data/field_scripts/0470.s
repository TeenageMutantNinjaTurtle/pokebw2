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
    ScriptEntry Script_11
    ScriptEntry Script_12
    ScriptEntry Script_13
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_12:
    VMStackPush 0x4138
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_012F
    VMStackPush 0x40c2
    VMStackPushConst 1
    VMStackCmp 4
    VMJumpIf 255, L_012F
    PokePartyGetCount 0x8020, 0

L_007A:
    VMStackPush 0x8020
    VMStackPush 0x8022
    VMStackCmp 2
    VMJumpIf 255, L_00BC
    PokePartyGetSpecies 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 494
    VMStackCmp 1
    VMJumpIf 255, L_00AC
    WorkSetConst 0x400a, 1

L_00AC:
    DebugPrint 0x8021
    WorkAdd 0x8022, 1
    VMJump L_007A

L_00BC:
    VMStackPush 0x400a
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00DB
    WorkSetConst 0x4138, 1
    VMJump L_012F

L_00DB:
    PokeDexIsRegist 1, 494, 0x8023
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0108
    WorkSetConst 0x4138, 1
    WorkSetConst 0x400a, 2
    VMJump L_012F

L_0108:
    PokeDexIsRegist 0, 494, 0x8023
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_012F
    WorkSetConst 0x4138, 1
    WorkSetConst 0x400a, 3

L_012F:
    VMHalt

Script_13:
    ActorsPauseAll
    CallPlaceNameDisp
    VMSleep 70
    ActorNew 308, 747, 2, 251, 105, 0
    ActorWalkRoute 251, 299, 747, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 251, Movement_052C
    ActorCmdWait
    BGMPlay 1089
    ActorCmdExec 251, Movement_0244
    ActorCmdWait
    WorkCmpConst 0x400a, 1
    VMJumpIf 1, L_0182
    VMJump L_0194

L_0182:
    ActorMsg 1024, 14, 251, 0, 0
    VMJump L_01DE

L_0194:
    WorkCmpConst 0x400a, 2
    VMJumpIf 1, L_01A7
    VMJump L_01B9

L_01A7:
    ActorMsg 1024, 15, 251, 0, 0
    VMJump L_01DE

L_01B9:
    WorkCmpConst 0x400a, 3
    VMJumpIf 1, L_01CC
    VMJump L_01DE

L_01CC:
    ActorMsg 1024, 16, 251, 0, 0
    VMJump L_01DE

L_01DE:
    MsgWinCloseAll
    ActorCmdExec 251, Movement_04B4
    ActorCmdWait
    VMSleep 30
    ActorMsg 1024, 17, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_04BC
    ActorCmdWait
    ActorMsg 1024, 18, 251, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 251, 298, 762, 0, 8, 1
    VMSleep 20
    ActorCmdExec 255, Movement_04EC
    ActorCmdWait
    BGMChangeMap
    ActorDelete 251
    WorkSetConst 0x4138, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0244:
    Move 13, 1
    Move 14, 2
    MoveEnd

Script_11:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    VMStackPush 0x4138
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_026B
    CallPlaceNameDisp

L_026B:
    ActorCmdExec 255, Movement_04AC
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02E6
    ParentActorMsg 1024, 1, 0, 0
    ActorMsgClose
    ActorCmdExec 0, Movement_04BC
    VMSleep 8
    ActorCmdExec 255, Movement_04BC
    ActorCmdWait
    RTReserveScript 4
    FadeOutBlackQ
    FadeWait
    SEPlay 2007
    MapChangeRail 36, 0, 2, 11, 3
    SEWait
    VMJump L_02F4

L_02E6:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_02F4:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    WorkSetConst 0x8024, 0
    TrainerCardGetSex 0x8024
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_034F
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0363

L_034F:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose

L_0363:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    PokePartyGetCount 0x8020, 0

L_038D:
    VMStackPush 0x8020
    VMStackPush 0x8022
    VMStackCmp 2
    VMJumpIf 255, L_03CF
    PokePartyGetSpecies 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 494
    VMStackCmp 1
    VMJumpIf 255, L_03BF
    WorkSetConst 0x400f, 1

L_03BF:
    DebugPrint 0x8021
    WorkAdd 0x8022, 1
    VMJump L_038D

L_03CF:
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03FC
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0410

L_03FC:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose

L_0410:
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
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 11, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 12, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 13, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Movement_04AC:
    Move 15, 1
    MoveEnd

Movement_04B4:
    Move 11, 1
    MoveEnd

Movement_04BC:
    Move 14, 1
    MoveEnd
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0
    Move 3, 1
    MoveEnd
    Move 32, 1
    MoveEnd

Movement_04EC:
    Move 33, 1
    MoveEnd
    FieldGetContinueFlag 1
    PokePartyGetSpecies 0, 35
    VMNop2
    PokePartyGetSpecies 0, 48
    VMNop2
    PokePartyGetSpecies 0, 49
    VMNop2
    PokePartyGetSpecies 0, 50
    VMNop2
    PokePartyGetSpecies 0, 51
    VMNop2
    PokePartyGetSpecies 0, 49
    VMHalt
    .byte 0xfe
    .balign 4, 0

Movement_052C:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
    Move 71, 1
    Move 170, 1
    Move 72, 1
    MoveEnd
