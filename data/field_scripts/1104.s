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
    ScriptEntry Script_19
    ScriptEntry Script_20
    ScriptEntry Script_21
    ScriptEntry Script_22
    ScriptEntry Script_23
    ScriptEntry Script_24
    ScriptEntry Script_25
    ScriptEntry Script_26
    ScriptEntry Script_27
    ScriptEntry Script_28
    ScriptEntry Script_29
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_3:
    VMCall L_0277
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00AD
    WorkSetConst 0x4044, 3

L_00AD:
    VMStackPushFlag 429
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2793
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00D8
    FlagReset 1029
    FlagSet 846

L_00D8:
    VMHalt

Script_1:
    GameGetVersion 0x8020
    VMStackPush 0x40f1
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f2
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_011D
    DebugPrint 12
    ActorSetGPos 0, 12, 0, 29, 3
    ActorSetGPos 255, 8, 0, 30, 3

L_011D:
    VMStackPush 0x40f0
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_013C
    ActorSetGPos 255, 9, 0, 30, 3

L_013C:
    VMStackPush 0x40f0
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x40f0
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_020B
    DebugPrint 22
    ActorSetGPos 0, 13, 0, 34, 1
    ActorSetGPos 1, 11, 0, 28, 0
    ActorSetGPos 2, 10, 0, 31, 3
    ActorSetGPos 4, 14, 0, 31, 2
    ActorSetGPos 5, 12, 0, 27, 1
    ActorSetGPos 6, 11, 0, 27, 1
    ActorSetGPos 7, 13, 0, 35, 0
    ActorSetGPos 8, 12, 0, 35, 0
    ActorSetGPos 3, 14, 0, 36, 0
    ActorSetGPos 9, 11, 0, 36, 0
    ActorSetGPos 10, 15, 0, 35, 2
    ActorSetGPos 11, 14, 0, 28, 2
    ActorSetGPos 12, 13, 0, 26, 1
    ActorSetGPos 13, 14, 0, 27, 2

L_020B:
    VMStackPush 0x40f1
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0248
    ActorSetGPos 14, 18, 0, 45, 0
    ActorSetGPos 15, 19, 0, 46, 0
    ActorSetGPos 0, 18, 0, 16, 0
    VMJump L_0267

L_0248:
    VMStackPush 0x40f2
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0267
    ActorSetGPos 0, 18, 0, 16, 0

L_0267:
    VMCall L_0277
    VMHalt

Script_2:
    VMCall L_0277
    VMHalt

L_0277:
    WorkSetConst 0x8024, 0
    GameGetVersion 0x8024
    VMStackPush 0x8024
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_02AE
    ObjInitWarpGPos 2, 0, 0, 0
    ObjInitWarpGPos 3, 0, 0, 0
    VMJump L_02D5

L_02AE:
    VMStackPush 0x8024
    VMStackPushConst 22
    VMStackCmp 1
    VMJumpIf 255, L_02D5
    ObjInitWarpGPos 1, 0, 0, 0
    ObjInitWarpGPos 0, 0, 0, 0

L_02D5:
    VMStackPush 0x40c6
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0302
    ObjInitWarpGPos 6, 0, 0, 0
    ObjInitWarpGPos 7, 0, 0, 0
    VMJump L_0343

L_0302:
    VMStackPush 0x4106
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_032F
    ObjInitWarpGPos 4, 0, 0, 0
    ObjInitWarpGPos 7, 0, 0, 0
    VMJump L_0343

L_032F:
    ObjInitWarpGPos 4, 0, 0, 0
    ObjInitWarpGPos 6, 0, 0, 0

L_0343:
    WorkSetConst 0x8024, 0
    VMReturn

Script_22:
    ActorsPauseAll
    DebugPrint 8
    ActorWalkRoute 255, 12, 31, 1, 8, 1
    ActorWalkRoute 0, 13, 32, 1, 8, 1
    ActorWalkRoute 1, 14, 31, 1, 8, 1
    ActorCmdWait
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorCmdExec 0, Movement_1408
    ActorCmdWait
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_13E4
    ActorCmdWait
    ActorMsg 1024, 1, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_063C
    ActorCmdWait
    ActorMsg 1024, 2, 1, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 2, 13, 29, 1, 8, 1
    VMSleep 16
    ActorCmdExec 0, Movement_13D4
    ActorCmdExec 1, Movement_13D4
    ActorCmdExec 255, Movement_13D4
    ActorCmdWait
    ActorCmdWait
    ActorMsg 1024, 3, 2, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 5, 12, 27, 1, 8, 1
    ActorWalkRoute 6, 11, 27, 1, 8, 1
    ActorWalkRoute 11, 14, 28, 1, 8, 1
    ActorWalkRoute 12, 13, 26, 1, 8, 1
    ActorWalkRoute 13, 14, 27, 1, 8, 1
    ActorCmdWait
    WordSetLoadRivalName 1
    BGMPlay 1194
    FlagReset 2560
    BGMAmbienceResume
    ActorMsg 1024, 4, 0, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 4, 14, 33, 1, 8, 1
    VMSleep 32
    ActorCmdExec 1, Movement_13F4
    VMSleep 8
    ActorCmdExec 0, Movement_13F4
    ActorCmdExec 255, Movement_13F4
    ActorCmdWait
    ActorMsg 1024, 5, 4, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 8, 12, 35, 1, 8, 1
    ActorWalkRoute 7, 13, 35, 1, 8, 1
    ActorWalkRoute 3, 14, 36, 1, 8, 1
    ActorWalkRoute 9, 11, 36, 1, 8, 1
    ActorWalkRoute 10, 15, 35, 1, 8, 1
    ActorCmdWait
    ActorMsg 1024, 6, 4, 0, 0
    MsgWinCloseAll
    WordSetLoadRivalName 1
    ActorMsg 1024, 7, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 8, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_13D4
    ActorCmdExec 1, Movement_13E4
    ActorCmdExec 255, Movement_13EC
    ActorCmdWait
    ActorMsg 1024, 9, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0678
    ActorCmdExec 4, Movement_0688
    ActorCmdExec 0, Movement_06A4
    ActorCmdExec 1, Movement_0694
    ActorCmdExec 255, Movement_13DC
    VMSleep 16
    ActorCmdExec 13, Movement_13E4
    ActorCmdExec 10, Movement_13E4
    ActorCmdExec 11, Movement_13E4
    ActorCmdWait
    ActorMsg 1024, 10, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_13A4
    ActorCmdExec 255, Movement_13E4
    ActorCmdWait
    CallTrainerBattle 372, 0, 0
    VMCall L_1268
    ActorCmdExec 2, Movement_06AC
    ActorCmdWait
    ActorMsg 1024, 11, 2, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 13, 4, 0, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_13AC
    ActorCmdExec 255, Movement_13EC
    ActorCmdWait
    CallTrainerBattle 373, 0, 0
    VMCall L_1268
    ActorMsg 1024, 14, 4, 0, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_06BC
    ActorCmdWait
    WorkSetConst 0x40f0, 2
    Cmd_0262 0, 0
    Cmd_0262 1, 16
    Cmd_0262 2, 4
    Cmd_0262 4, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_063C:
    Move 63, 1
    Move 32, 1
    Move 63, 1
    Move 33, 1
    Move 63, 1
    Move 34, 1
    MoveEnd
    Move 13, 9
    MoveEnd
    Move 13, 8
    MoveEnd
    Move 12, 9
    MoveEnd
    Move 12, 8
    MoveEnd

Movement_0678:
    Move 14, 3
    Move 13, 2
    Move 35, 1
    MoveEnd

Movement_0688:
    Move 12, 2
    Move 34, 1
    MoveEnd

Movement_0694:
    Move 12, 2
    Move 14, 3
    Move 12, 1
    MoveEnd

Movement_06A4:
    Move 13, 2
    MoveEnd

Movement_06AC:
    Move 71, 1
    Move 14, 1
    Move 72, 1
    MoveEnd

Movement_06BC:
    Move 71, 1
    Move 15, 1
    Move 72, 1
    MoveEnd

Script_6:
    ActorsPauseAll
    WordSetLoadRivalName 1
    WordSetPlayerName 0
    VMStackPush 0x40f0
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0701
    SEPlay 1351
    ActorMsg 1024, 31, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_08AF

L_0701:
    VMStackPush 0x40f0
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0852
    SEPlay 1351
    ActorMsg 1024, 32, 0, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8022, 0x8023
    VMStackPush 0x8022
    VMStackPushConst 14
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 34
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_075D
    ActorCmdExec 255, Movement_08B8
    VMJump L_0796

L_075D:
    VMStackPush 0x8022
    VMStackPushConst 13
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 33
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_078E
    ActorCmdExec 255, Movement_08C8
    VMJump L_0796

L_078E:
    ActorCmdExec 255, Movement_13DC

L_0796:
    ActorCmdExec 7, Movement_13B4
    ActorCmdExec 8, Movement_13B4
    ActorCmdWait
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_07CB
    CallTrainerMultiBattle 368, 376, 377, 0
    VMJump L_07F8

L_07CB:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_07EE
    CallTrainerMultiBattle 369, 376, 377, 0
    VMJump L_07F8

L_07EE:
    CallTrainerMultiBattle 370, 376, 377, 0

L_07F8:
    VMCall L_1268
    WordSetLoadRivalName 1
    WordSetPlayerName 0
    VMCall L_0A60
    WorkSetConst 0x40f0, 4
    WorkSetConst 0x40c6, 4
    FlagSet 830
    FlagSet 831
    FlagSet 829
    FlagSet 833
    FlagSet 834
    FlagReset 711
    FlagReset 712
    FlagSet 710
    MapReplaceSetEvent 4, 0, 0
    RTReserveScript 3
    MapChangeWarp 191, 197, 491, 0
    VMJump L_08AF

L_0852:
    VMStackPush 0x40f1
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f1
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0895
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 43, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_08AF

L_0895:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 44, 0, 0
    LastKeyWait
    ActorMsgClose

L_08AF:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_08B8:
    Move 12, 1
    Move 14, 2
    Move 13, 1
    MoveEnd

Movement_08C8:
    Move 14, 1
    Move 13, 1
    MoveEnd

Script_7:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    VMStackPush 0x40f0
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0A28
    SEPlay 1351
    ActorMsg 1024, 16, 5, 0, 0
    MsgWinCloseAll
    PlayerGetDir 0x8021
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0926
    ActorCmdExec 1, Movement_13DC
    VMJump L_094F

L_0926:
    VMStackPush 0x8021
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0947
    ActorCmdExec 1, Movement_13E4
    VMJump L_094F

L_0947:
    ActorCmdExec 1, Movement_13EC

L_094F:
    ActorCmdWait
    ActorMsg 1024, 17, 1, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8022, 0x8023
    VMStackPush 0x8022
    VMStackPushConst 10
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 28
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0996
    ActorCmdExec 255, Movement_0A44
    VMJump L_09CF

L_0996:
    VMStackPush 0x8022
    VMStackPushConst 11
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 29
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_09C7
    ActorCmdExec 255, Movement_0A54
    VMJump L_09CF

L_09C7:
    ActorCmdExec 255, Movement_13D4

L_09CF:
    ActorCmdExec 5, Movement_13BC
    ActorCmdExec 6, Movement_13BC
    ActorCmdExec 1, Movement_13D4
    ActorCmdWait
    CallTrainerMultiBattle 371, 374, 375, 0
    VMCall L_1268
    WordSetPlayerName 0
    ActorCmdExec 255, Movement_13E4
    ActorCmdExec 1, Movement_13EC
    ActorCmdWait
    ActorMsg 1024, 18, 1, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x40f0, 3
    VMJump L_0A3C

L_0A28:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    ActorMsgClose

L_0A3C:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0A44:
    Move 13, 1
    Move 15, 2
    Move 12, 1
    MoveEnd

Movement_0A54:
    Move 15, 1
    Move 12, 1
    MoveEnd

L_0A60:
    WordSetLoadRivalName 1
    WordSetPlayerName 0
    MultiMsg 63, 6, 20, 1
    VMSleep 26
    MultiMsg 64, 4, 11, 2
    VMSleep 26
    MsgWinCloseNo 1
    MultiMsg 65, 13, 2, 3
    VMSleep 26
    MsgWinCloseNo 2
    MultiMsg 66, 18, 14, 4
    VMSleep 26
    MsgWinCloseNo 3
    VMSleep 26
    MsgWinCloseNo 4
    ActorMsg 1024, 33, 0, 3, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_13E4
    ActorCmdWait
    ActorMsg 1024, 34, 1, 5, 0
    MsgWinCloseAll
    FlagReset 833
    FlagReset 834
    SEPlay 1369
    ActorAdd 16
    SEWait
    BGMPlay 1240
    InfoMsg 35, 1
    MsgWinCloseAll
    ActorCmdExec 1, Movement_13D4
    ActorWalkRoute 16, 13, 30, 1, 8, 1
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xd8000, 0, 0x1f9000, 30
    ActorCmdExec 5, Movement_0BF8
    ActorCmdExec 12, Movement_0C10
    VMSleep 10
    ActorCmdExec 6, Movement_13EC
    ActorCmdExec 11, Movement_13E4
    ActorCmdExec 13, Movement_13E4
    ActorCmdWait
    EvCameraWait
    ActorCmdExec 16, Movement_0C24
    ActorCmdWait
    ActorMsg 1024, 36, 1, 6, 0
    MsgWinCloseAll
    ActorMsg 1024, 37, 16, 5, 0
    MsgWinCloseAll
    ActorCmdExec 16, Movement_0C30
    ActorCmdWait
    ActorMsg 1024, 38, 16, 5, 0
    MsgWinCloseAll
    BGMChangeMap
    EvCameraMoveToDefault 24
    ActorAdd 17
    ActorCmdExec 17, Movement_0C50
    ActorAdd 18
    ActorAdd 19
    ActorCmdExec 18, Movement_0C50
    ActorCmdExec 19, Movement_0C50
    ActorCmdWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorMsg 1024, 39, 17, 4, 0
    MsgWinCloseAll
    ActorCmdExec 16, Movement_13DC
    ActorCmdWait
    InfoMsg 40, 1
    MsgWinCloseAll
    ActorMsg 1024, 41, 17, 4, 0
    MsgWinCloseAll
    VMReturn
    .balign 4, 0

Movement_0BF8:
    Move 13, 1
    Move 3, 1
    Move 71, 1
    Move 14, 1
    Move 72, 1
    MoveEnd

Movement_0C10:
    Move 2, 1
    Move 71, 1
    Move 15, 1
    Move 72, 1
    MoveEnd

Movement_0C24:
    Move 75, 1
    Move 159, 1
    MoveEnd

Movement_0C30:
    Move 71, 1
    Move 12, 1
    Move 72, 1
    Move 34, 1
    Move 35, 1
    Move 34, 1
    Move 35, 1
    MoveEnd

Movement_0C50:
    Move 184, 1
    MoveEnd
    Move 185, 1
    Move 69, 1
    MoveEnd

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 12, 0, 0
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
    VMStackPush 0x40f0
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0CCB
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0CDF

L_0CCB:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose

L_0CDF:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 27, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 28, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 29, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 30, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 54, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_21:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 55, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_27:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 56, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_28:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 57, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_23:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorCmdExec 0, Movement_13E4
    ActorCmdWait
    ActorMsg 1024, 43, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_13EC
    ActorWalkRoute 14, 10, 30, 1, 8, 1
    ActorCmdWait
    ActorMsg 1024, 48, 14, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 500, 0, 0
    VMCall L_1268
    ActorCmdExec 14, Movement_0FC0
    ActorCmdWait
    ActorMsg 1024, 49, 14, 0, 0
    MsgWinCloseAll
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0F04
    ActorWalkRoute 14, 13, 20, 1, 4, 0
    ActorWalkRoute 15, 13, 20, 1, 4, 0
    ActorCmdWait
    WorkSetConst 0x40f2, 2
    ActorDelete 14
    ActorDelete 15
    ActorDelete 23
    ActorDelete 24
    VMJump L_0F40

L_0F04:
    ActorWalkRoute 14, 13, 38, 1, 4, 0
    ActorWalkRoute 15, 14, 38, 1, 4, 0
    ActorCmdWait
    WorkSetConst 0x40f1, 2
    ActorSetGPos 14, 18, 0, 45, 0
    ActorSetGPos 15, 19, 0, 46, 0

L_0F40:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorCmdExec 0, Movement_13E4
    ActorCmdWait
    ActorMsg 1024, 45, 0, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 0, 12, 20, 1, 4, 0
    ActorCmdExec 255, Movement_13D4
    ActorCmdWait
    ActorSetGPos 0, 18, 0, 16, 0
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0F99
    FlagSet 832

L_0F99:
    Cmd_0262 0, 6
    Cmd_0262 1, 31
    Cmd_0262 2, 7
    Cmd_0262 3, 7
    Cmd_0262 4, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0FC0:
    Move 71, 1
    Move 15, 1
    Move 72, 1
    Move 63, 1
    Move 75, 1
    MoveEnd
    Move 15, 4
    Move 12, 10
    Move 15, 2
    Move 12, 4
    Move 15, 3
    Move 12, 1
    MoveEnd
    Move 12, 1
    Move 15, 4
    Move 12, 10
    Move 15, 2
    Move 12, 3
    Move 15, 3
    Move 32, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Script_4:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    PlayerGetGPos 0x8022, 0x8023
    VMStackPush 0x8022
    VMStackPushConst 16
    VMStackCmp 1
    VMJumpIf 255, L_104B
    ActorCmdExec 0, Movement_13E4
    VMJump L_1053

L_104B:
    ActorCmdExec 0, Movement_13EC

L_1053:
    ActorCmdWait
    ActorMsg 1024, 46, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_10A8
    ActorCmdWait
    SEPlay 1369
    ActorDelete 0
    SEWait
    ActorWalkRoute 255, 18, 15, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 255, Movement_139C
    ActorCmdWait
    RTReserveScript 6
    MapChangeWarp 563, 11, 15, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_10A8:
    Move 12, 2
    MoveEnd

Script_5:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    PlayerGetGPos 0x8022, 0x8023
    VMStackPush 0x8022
    VMStackPushConst 16
    VMStackCmp 1
    VMJumpIf 255, L_10DF
    ActorCmdExec 0, Movement_13E4
    VMJump L_10E7

L_10DF:
    ActorCmdExec 0, Movement_13EC

L_10E7:
    ActorCmdWait
    ActorMsg 1024, 46, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_10A8
    ActorCmdWait
    SEPlay 1369
    ActorDelete 0
    SEWait
    ActorWalkRoute 255, 18, 15, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 255, Movement_139C
    ActorCmdWait
    RTReserveScript 9
    MapChangeWarp 553, 11, 15, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_24:
    ActorsPauseAll
    SEPlay 1351
    ActorCmdExec 22, Movement_1410
    ActorCmdWait
    InfoMsg 51, 1
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_29:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2793
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_121C
    VMStackPushFlag 493
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_119A
    ParentActorMsg 1024, 58, 0, 0
    FlagSet 493
    VMJump L_11A4

L_119A:
    ParentActorMsg 1024, 61, 0, 0

L_11A4:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1208
    ParentActorMsg 1024, 59, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 813, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_11EE
    CallTrainerBattleEnd
    VMJump L_11F0

L_11EE:
    CallTrainerLose

L_11F0:
    ParentActorMsg 1024, 62, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2793
    VMJump L_1216

L_1208:
    ParentActorMsg 1024, 60, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_1216:
    VMJump L_122A

L_121C:
    ParentActorMsg 1024, 62, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_122A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_25:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 52, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_26:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 53, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_1268:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1371
    VMStackPush 0x40f0
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_1298
    VMCall L_1375

L_1298:
    VMStackPush 0x40f0
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_1369
    VMCall L_1375
    ActorSetGPos 2, 10, 0, 30, 3
    ActorSetGPos 4, 10, 0, 32, 3
    ActorSetGPos 5, 12, 0, 27, 1
    ActorSetGPos 6, 11, 0, 27, 1
    ActorSetGPos 7, 13, 0, 35, 0
    ActorSetGPos 8, 12, 0, 35, 0
    ActorSetGPos 3, 14, 0, 36, 0
    ActorSetGPos 9, 11, 0, 36, 0
    ActorSetGPos 10, 15, 0, 35, 0
    ActorSetGPos 11, 14, 0, 28, 1
    ActorSetGPos 12, 13, 0, 26, 1
    ActorSetGPos 13, 14, 0, 27, 1
    ActorSetGPos 0, 12, 0, 32, 0
    ActorSetGPos 1, 14, 0, 32, 0
    ActorSetGPos 255, 13, 0, 33, 0
    FlagSet 831

L_1369:
    CallTrainerBattleEnd
    VMJump L_1373

L_1371:
    CallTrainerLose

L_1373:
    VMReturn

L_1375:
    PokePartyGetCount 0x8008, 2
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1390
    PokePartyRecoverAll

L_1390:
    VMReturn
    .balign 4, 0
    Move 13, 1
    MoveEnd

Movement_139C:
    Move 12, 1
    MoveEnd

Movement_13A4:
    Move 15, 1
    MoveEnd

Movement_13AC:
    Move 14, 1
    MoveEnd

Movement_13B4:
    Move 0, 1
    MoveEnd

Movement_13BC:
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0
    Move 3, 1
    MoveEnd

Movement_13D4:
    Move 32, 1
    MoveEnd

Movement_13DC:
    Move 33, 1
    MoveEnd

Movement_13E4:
    Move 34, 1
    MoveEnd

Movement_13EC:
    Move 35, 1
    MoveEnd

Movement_13F4:
    Move 33, 1
    Move 75, 1
    MoveEnd
    Move 75, 1
    MoveEnd

Movement_1408:
    Move 159, 1
    MoveEnd

Movement_1410:
    Move 161, 1
    MoveEnd
