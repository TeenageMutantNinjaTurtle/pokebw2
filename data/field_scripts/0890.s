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
    ScriptEntry Script_14
    ScriptEntry Script_15
    ScriptEntry Script_16
    ScriptEntry Script_17
    ScriptEntry Script_18
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    VMHalt

Script_2:
    VMStackPush 0x40a7
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0083
    ActorSetGPos 0, 22, 2, 32, 1
    VMJump L_00CD

L_0083:
    VMStackPush 0x40a7
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_00A8
    ActorSetGPos 0, 22, 3, 13, 1
    VMJump L_00CD

L_00A8:
    VMStackPush 0x40a7
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_00CD
    ActorSetGPos 0, 47, 2, 13, 1
    VMJump L_00CD

L_00CD:
    VMStackPush 0x40a7
    VMStackPushConst 5
    VMStackCmp 0
    VMStackPush 0x40a7
    VMStackPushConst 0
    VMStackCmp 5
    VMStackCmp 7
    VMJumpIf 255, L_011A
    ActorSetGPos 1, 43, 2, 46, 2
    ActorSetGPos 2, 43, 2, 45, 2
    ActorSetGPos 10, 44, 2, 46, 2
    VMJump L_015D

L_011A:
    VMStackPush 0x40a7
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_015D
    ActorSetGPos 1, 46, 2, 42, 1
    ActorSetGPos 2, 47, 2, 42, 1
    ActorSetGPos 10, 45, 2, 40, 3
    ActorSetGPos 3, 47, 2, 40, 2

L_015D:
    VMHalt

Script_3:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    ActorSetGPos 0, 33, 2, 0x8022, 2
    WorkSub 0x8021, 1
    ActorWalkRoute 0, 0x8021, 0x8022, 1, 8, 0
    BGMPlayPush 1237
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01BF
    CallTrainerBattle 166, 0, 0
    VMJump L_01E8

L_01BF:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01E0
    CallTrainerBattle 167, 0, 0
    VMJump L_01E8

L_01E0:
    CallTrainerBattle 168, 0, 0

L_01E8:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_021F
    ActorSetGPos 0, 42, 2, 46, 0
    ActorSetGPos 255, 42, 2, 45, 1
    CallTrainerBattleEnd
    VMJump L_0221

L_021F:
    CallTrainerLose

L_0221:
    WordSetLoadRivalName 1
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    WordSetPlayerName 0
    SEPlay 2017
    SystemMsg 2, 0
    InfoMsgClose
    SEWait
    ActorMsg 1024, 3, 0, 0, 0
    MsgWinCloseAll
    FlagReset 727
    ActorAdd 2
    ActorWalkRoute 2, 44, 45, 1, 8, 1
    VMSleep 4
    ActorAdd 1
    ActorWalkRoute 1, 44, 46, 1, 8, 1
    ActorAdd 10
    ActorWalkRoute 10, 45, 46, 1, 8, 1
    VMSleep 24
    ActorCmdExec 255, Movement_0F3C
    ActorCmdExec 0, Movement_0F3C
    ActorCmdWait
    ActorMsg 1024, 4, 1, 6, 0
    MsgWinCloseAll
    WordSetLoadRivalName 1
    ActorMsg 1024, 5, 0, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 6, 1, 6, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    ActorWalkRoute 2, 43, 45, 1, 8, 0
    ActorCmdWait
    ActorMsg 1024, 7, 2, 5, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 17
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorWalkRoute 2, 43, 46, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 2, Movement_0F34
    ActorCmdWait
    ActorMsg 1024, 8, 2, 5, 0
    MsgWinCloseAll
    VMSleep 12
    ActorWalkRoute 2, 44, 45, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 2, Movement_0F34
    ActorCmdWait
    ActorMsg 1024, 9, 2, 5, 0
    MsgWinCloseAll
    ActorMsg 1024, 10, 1, 6, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0F44
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 11, 0, 4, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0F34
    ActorCmdExec 0, Movement_040C
    ActorCmdWait
    ActorCmdExec 1, Movement_0F4C
    ActorCmdExec 255, Movement_0F3C
    ActorCmdWait
    ActorMsg 1024, 12, 1, 6, 0
    MsgWinCloseAll
    ActorMsg 1024, 13, 2, 5, 0
    LastKeyWait
    MsgWinCloseAll
    ActorSetGPos 0, 25, 2, 44, 0
    WorkSetConst 0x40a7, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .byte 0x00
    VMNop
    VMStackSub
    VMNop2
    VMStackDiv
    DebugPrint 254
    VMNop
    VMStackMul
    VMHalt
    Move 12, 1
    Move 34, 1
    MoveEnd

Movement_040C:
    Move 18, 11
    MoveEnd

Script_4:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    WorkAdd 0x8022, 2
    ActorSetGPos 0, 21, 2, 42, 0
    ActorWalkRoute 0, 0x8021, 0x8022, 1, 8, 0
    VMSleep 24
    ActorCmdExec 255, Movement_0F2C
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 15, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8021
    VMStackPushConst 21
    VMStackCmp 1
    VMJumpIf 255, L_047C
    ActorCmdExec 0, Movement_04AC
    VMJump L_0484

L_047C:
    ActorCmdExec 0, Movement_04B8

L_0484:
    VMSleep 8
    ActorCmdExec 255, Movement_0F24
    ActorCmdWait
    ActorSetGPos 0, 22, 3, 22, 0
    WorkSetConst 0x40a7, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_04AC:
    Move 19, 1
    Move 16, 12
    MoveEnd

Movement_04B8:
    Move 18, 1
    Move 16, 12
    MoveEnd

Script_5:
    ActorsPauseAll
    ActorSetGPos 0, 22, 3, 19, 0
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 11
    VMStackCmp 1
    VMJumpIf 255, L_04FD
    ActorCmdExec 0, Movement_05BC
    VMSleep 40
    VMJump L_0541

L_04FD:
    VMStackPush 0x8022
    VMStackPushConst 12
    VMStackCmp 1
    VMJumpIf 255, L_0522
    ActorCmdExec 0, Movement_05C8
    VMSleep 32
    VMJump L_0541

L_0522:
    VMStackPush 0x8022
    VMStackPushConst 13
    VMStackCmp 1
    VMJumpIf 255, L_0541
    ActorCmdExec 0, Movement_05D4
    VMSleep 24

L_0541:
    ActorCmdExec 255, Movement_0F34
    ActorCmdWait
    ActorMsg 1024, 18, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 22
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    WordSetLoadRivalName 1
    ActorMsg 1024, 19, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_05E0
    ActorCmdWait
    ActorCmdExec 0, Movement_0F3C
    ActorCmdWait
    ActorMsg 1024, 20, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40a7, 3
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_05BC:
    Move 16, 8
    Move 39, 1
    MoveEnd

Movement_05C8:
    Move 16, 7
    Move 39, 1
    MoveEnd

Movement_05D4:
    Move 16, 6
    Move 39, 1
    MoveEnd

Movement_05E0:
    Move 33, 1
    Move 161, 1
    MoveEnd

Script_6:
    ActorsPauseAll
    PVPlay 507, 0
    InfoMsg 21, 2
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll
    ActorSetGPos 0, 35, 2, 11, 3
    ActorCmdExec 0, Movement_06D0
    VMSleep 48
    PlayerGetDir 0x8020
    WorkCmpConst 0x8020, 3
    VMJumpIf 1, L_062E
    VMJump L_063C

L_062E:
    ActorCmdExec 255, Movement_0F34
    VMJump L_0665

L_063C:
    WorkCmpConst 0x8020, 1
    VMJumpIf 1, L_064F
    VMJump L_065D

L_064F:
    ActorCmdExec 255, Movement_0F24
    VMJump L_0665

L_065D:
    ActorCmdExec 255, Movement_0F24

L_0665:
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 22, 0, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 12
    VMStackCmp 1
    VMJumpIf 255, L_069F
    ActorCmdExec 0, Movement_06E0
    VMJump L_06A7

L_069F:
    ActorCmdExec 0, Movement_06EC

L_06A7:
    VMSleep 16
    ActorCmdExec 255, Movement_0F3C
    ActorCmdWait
    ActorMsg 1024, 23, 0, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x40a7, 4
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_06D0:
    Move 19, 6
    Move 17, 1
    Move 75, 1
    MoveEnd

Movement_06E0:
    Move 17, 1
    Move 19, 5
    MoveEnd

Movement_06EC:
    Move 19, 5
    MoveEnd

Script_7:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x338000, 0x2001f, 0x148000, 40
    PlayerGetGPos 0x8021, 0x8022
    ActorWalkRoute 255, 51, 23, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 255, Movement_0F24
    ActorCmdExec 3, Movement_09A4
    ActorCmdExec 16, Movement_0EFC
    ActorCmdWait
    EvCameraWait
    PVPlay 507, 0
    ActorMsg 1024, 25, 3, 3, 0
    PVWait
    MsgWaitAdvance
    ActorMsgClose
    WordSetLoadRivalName 1
    InfoMsg 26, 1
    MsgWinCloseAll
    ActorCmdExec 16, Movement_0F2C
    ActorWalkRoute 0, 42, 12, 1, 4, 0
    ActorCmdWait
    ActorMsg 1024, 27, 16, 5, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_07B3
    ActorMsg 1024, 28, 16, 5, 0
    VMJump L_07BF

L_07B3:
    ActorMsg 1024, 29, 16, 5, 0

L_07BF:
    ActorMsg 1024, 30, 16, 5, 0
    MsgWinCloseAll
    ActorNew 51, 20, 1, 251, 110, 0
    VMSleep 4
    ActorWalkRoute 251, 51, 23, 1, 4, 1
    VMSleep 16
    SEPlay 1422
    ActorCmdWait
    SEWait
    ActorDelete 251
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 348
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 31, 16, 5, 0
    MsgWinCloseAll
    EvCameraMoveToDefault 32
    ActorCmdExec 16, Movement_09B4
    VMSleep 20
    ActorCmdExec 255, Movement_0F2C
    ActorCmdWait
    ActorCmdExec 3, Movement_0A2C
    ActorCmdExec 255, Movement_0F24
    ActorCmdWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    PVPlay 507, 0
    ActorMsg 1024, 32, 3, 3, 0
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll
    ActorSetGPos 0, 46, 2, 14, 1
    ActorSetGPos 1, 46, 2, 15, 1
    ActorCmdExec 1, Movement_0A5C
    VMSleep 4
    ActorCmdExec 0, Movement_0A6C
    VMSleep 80
    ActorCmdExec 255, Movement_0F2C
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 33, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 3, Movement_0A8C
    VMSleep 48
    ActorCmdExec 0, Movement_0F3C
    ActorCmdWait
    ActorMsg 1024, 34, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0A04
    VMSleep 8
    ActorCmdExec 1, Movement_0F34
    ActorCmdExec 255, Movement_0F34
    ActorCmdWait
    ActorDelete 0
    ActorDelete 16
    ActorCmdExec 255, Movement_0F2C
    ActorCmdExec 1, Movement_0F24
    ActorCmdWait
    ActorMsg 1024, 35, 1, 4, 0
    MsgWinCloseAll
    FadeEx 3, 0, 16, 4
    ActorCmdExec 1, Movement_0AEC
    VMSleep 8
    ActorCmdExec 3, Movement_0ADC
    ActorCmdWait
    FadeExWait
    ActorSetGPos 1, 46, 2, 42, 1
    ActorSetGPos 2, 47, 2, 42, 1
    ActorSetGPos 10, 45, 2, 40, 3
    ActorSetGPos 3, 47, 2, 40, 2
    FadeEx 3, 16, 0, 4
    FadeExWait
    WorkSetConst 0x40a7, 5
    WorkSetConst 0x40a5, 3
    FlagSet 729
    FlagSet 728
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_09A4:
    Move 71, 1
    Move 10, 1
    Move 72, 1
    MoveEnd

Movement_09B4:
    Move 19, 1
    Move 17, 7
    Move 18, 6
    Move 16, 7
    Move 18, 6
    MoveEnd
    WorkAnd 1, 17
    DebugPrint 18
    VMReturn
    VMStackPushFlag 14
    PokePartyGetSpecies 0, 34
    VMNop
    FlagSet 0
    MsgWinCloseAll
    VMNop2
    VMStackCmp 1
    PokePartyGetSpecies 0, 17
    VMStackPop 19
    VMReturn
    Move 32, 0
    MoveEnd

Movement_0A04:
    Move 13, 2
    Move 14, 4
    Move 12, 7
    Move 14, 5
    MoveEnd
    VMStackSub
    VMHalt
    VMStackDiv
    VMHalt
    VMStackMul
    VMHalt
    Move 33, 0
    MoveEnd

Movement_0A2C:
    Move 13, 2
    Move 15, 2
    Move 14, 2
    Move 15, 1
    Move 33, 0
    MoveEnd
    VMStackSub
    VMHalt
    VMStackDiv
    VMHalt
    VMStackMul
    VMHalt
    VMStackDiv
    VMHalt
    Move 33, 0
    MoveEnd

Movement_0A5C:
    Move 13, 12
    Move 15, 5
    Move 12, 2
    MoveEnd

Movement_0A6C:
    Move 13, 13
    Move 15, 4
    Move 12, 2
    MoveEnd
    VMStackDiv
    VMHalt
    Move 13, 4
    Move 34, 0
    MoveEnd

Movement_0A8C:
    Move 15, 1
    Move 13, 3
    Move 34, 0
    Move 50, 0
    MoveEnd
    VMStackMul
    VMNop2
    VMStackSub
    VMHalt
    VMStackDiv
    VMNop2
    VMStackSub
    VMHalt
    Move 34, 0
    MoveEnd
    Move 15, 1
    Move 33, 0
    MoveEnd
    Move 14, 1
    Move 33, 0
    MoveEnd
    Move 14, 1
    Move 32, 0
    MoveEnd

Movement_0ADC:
    Move 14, 1
    Move 13, 1
    Move 14, 4
    MoveEnd

Movement_0AEC:
    Move 35, 0
    Move 13, 1
    Move 14, 4
    MoveEnd

Script_8:
    ActorsPauseAll
    WordSetLoadRivalName 1
    VMStackPush 0x40a7
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0B2E
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0BAF

L_0B2E:
    VMStackPush 0x40a7
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0B5B
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0BAF

L_0B5B:
    VMStackPush 0x40a7
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0B88
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0BAF

L_0B88:
    VMStackPush 0x40a7
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_0BAF
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    ActorMsgClose

L_0BAF:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    VMStackPush 0x40a7
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPushFlag 482
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0BF8
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 36, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 482
    VMJump L_0C49

L_0BF8:
    VMStackPush 0x40a7
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPushFlag 482
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0C35
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 37, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0C49

L_0C35:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 38, 0, 0
    LastKeyWait
    ActorMsgClose

L_0C49:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    VMStackPush 0x40a7
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPushFlag 268
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0C92
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 41, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 268
    VMJump L_0D69

L_0C92:
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    PokePartyGetCount 0x8023, 0

L_0CBC:
    VMStackPush 0x8023
    VMStackPush 0x8024
    VMStackCmp 2
    VMJumpIf 255, L_0D10
    PokePartyIsFullHP 0x8025, 0x8024
    PokePartyIsFullPP 0x8026, 0x8024
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0D04
    WorkAdd 0x8027, 1

L_0D04:
    WorkAdd 0x8024, 1
    VMJump L_0CBC

L_0D10:
    VMStackPush 0x8027
    VMStackPushConst 1
    VMStackCmp 4
    VMJumpIf 255, L_0D5B
    ParentActorMsg 1024, 40, 0, 0
    MsgWinCloseAll
    FadeEx 3, 0, 16, 2
    FadeExWait
    PokePartyRecoverAll
    MEPlay 1300
    MEWait
    FadeEx 3, 16, 0, 2
    FadeExWait
    WorkSetConst 0x4001, 1
    VMJump L_0D69

L_0D5B:
    ParentActorMsg 1024, 39, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0D69:
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 507, 0
    ParentActorMsg 1024, 44, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    VMStackPush 0x40a7
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_0DE8
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 507, 0
    ParentActorMsg 1024, 43, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_0E04

L_0DE8:
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 507, 0
    ParentActorMsg 1024, 42, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose

L_0E04:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 179, 0
    ParentActorMsg 1024, 45, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 179, 0
    ParentActorMsg 1024, 46, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 179, 0
    ParentActorMsg 1024, 47, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 179, 0
    ParentActorMsg 1024, 48, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 179, 0
    ParentActorMsg 1024, 49, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 179, 0
    ParentActorMsg 1024, 50, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd

Movement_0EFC:
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

Movement_0F24:
    Move 32, 1
    MoveEnd

Movement_0F2C:
    Move 33, 1
    MoveEnd

Movement_0F34:
    Move 34, 1
    MoveEnd

Movement_0F3C:
    Move 35, 1
    MoveEnd

Movement_0F44:
    Move 75, 1
    MoveEnd

Movement_0F4C:
    Move 159, 1
    MoveEnd
