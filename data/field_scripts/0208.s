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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_15:
    Cmd_02B2 0, 0x400f
    DebugPrint 0x400f
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x404a
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x413f
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_00AB
    FlagSet 714
    FlagSet 696
    FlagSet 974
    FlagReset 697
    WorkSetConst 0x413f, 2

L_00AB:
    VMStackPushFlag 417
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 491
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00DA
    Cmd_0262 1, 43
    VMJump L_0103

L_00DA:
    VMStackPushFlag 417
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 491
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0103
    Cmd_0262 1, 42

L_0103:
    VMHalt

Script_16:
    ActorsPauseAll
    ActorWalkRoute 13, 7, 21, 1, 16, 1
    ActorCmdWait
    ActorMsg 1024, 37, 13, 0, 0
    PVPlay 571, 0
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll
    FadeOutBlack
    RTReserveScript 1
    FadeWait
    MapChangeCore 603, 7, 0, 18, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    FadeInBlack
    FadeWait
    WorkSetConst 0x413f, 3
    WorkSetConst 0x404a, 1
    FlagReset 696
    VMStackPushFlag 289
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0176
    FlagReset 714

L_0176:
    VMStackPushFlag 417
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_018D
    FlagReset 974

L_018D:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    ActorWalkRoute 255, 7, 20, 1, 8, 0
    VMSleep 16
    SEPlay 1369
    ActorNew 7, 25, 0, 251, 291, 0
    SEWait
    ActorCmdWait
    ActorWalkRoute 251, 6, 20, 1, 8, 0
    ActorCmdWait
    ActorMsg 1024, 0, 0, 3, 0
    MsgWinCloseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorMsg 1024, 1, 251, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 2, 0, 3, 0
    MsgWinCloseAll
    ActorMsg 1024, 3, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0A68
    ActorCmdWait
    ActorMsg 1024, 4, 0, 3, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_06E4
    ActorCmdWait
    ActorMsg 1024, 5, 251, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 6, 251, 0, 1
    MsgWinCloseAll
    ActorMsg 1024, 7, 0, 3, 0
    MsgWinCloseAll
    WordSetPlayerName 0
    ActorMsg 1024, 8, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0A60
    VMSleep 4
    ActorCmdExec 255, Movement_0A58
    ActorCmdWait
    ActorMsg 1024, 9, 251, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 251, 6, 25, 1, 4, 0
    VMSleep 8
    ActorCmdExec 255, Movement_0A50
    ActorCmdWait
    SEPlay 1369
    ActorDelete 251
    SEWait
    ActorCmdExec 0, Movement_0A78
    VMSleep 8
    ActorCmdExec 255, Movement_0A48
    ActorCmdWait
    ActorMsg 1024, 10, 0, 3, 0
    WordSetPlayerName 0
    ActorMsg 1024, 11, 0, 3, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0310
    ActorMsg 1024, 15, 0, 3, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0316

L_0310:
    VMCall L_03A6

L_0316:
    FlagSet 719
    WorkSetConst 0x413f, 1
    Cmd_0262 1, 10
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    VMStackPushFlag 289
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_038C
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 12, 0, 3, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0380
    ActorMsg 1024, 15, 0, 3, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0386

L_0380:
    VMCall L_03A6

L_0386:
    VMJump L_03A0

L_038C:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose

L_03A0:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_03A6:
    WorkSetConst 0x8023, 0
    PokePartyGetCount 0x8023, 0
    VMStackPush 0x8023
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_03DB
    ActorMsg 1024, 14, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0695

L_03DB:
    ActorCmdExec 0, Movement_0A60
    ActorCmdWait
    ActorMsg 1024, 13, 0, 3, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 7
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 20
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0430
    ActorWalkRoute 1, 7, 19, 1, 8, 1
    VMJump L_047B

L_0430:
    VMStackPush 0x8021
    VMStackPushConst 6
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 18
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0467
    ActorWalkRoute 1, 6, 17, 1, 8, 1
    VMJump L_047B

L_0467:
    WorkAdd 0x8021, 1
    ActorWalkRoute 1, 0x8021, 0x8022, 1, 8, 1

L_047B:
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 6
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 18
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_04B4
    ActorCmdExec 0, Movement_0A58
    VMJump L_051E

L_04B4:
    VMStackPush 0x8021
    VMStackPushConst 7
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 17
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_04E5
    ActorCmdExec 0, Movement_0A48
    VMJump L_051E

L_04E5:
    VMStackPush 0x8021
    VMStackPushConst 7
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 19
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0516
    ActorCmdExec 0, Movement_0A50
    VMJump L_051E

L_0516:
    ActorCmdExec 0, Movement_0A50

L_051E:
    VMStackPush 0x8021
    VMStackPushConst 7
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 20
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_054F
    ActorCmdExec 1, Movement_0A50
    VMJump L_0598

L_054F:
    VMStackPush 0x8021
    VMStackPushConst 6
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 18
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0588
    ActorCmdExec 1, Movement_0A50
    ActorCmdExec 255, Movement_0A48
    VMJump L_0598

L_0588:
    ActorCmdExec 1, Movement_0A58
    ActorCmdExec 255, Movement_0A60

L_0598:
    ActorCmdWait
    VMSleep 32
    ActorDelete 1
    PokePartyAddNPoke 0x8010, 570, 25, 11, 0, 0
    WordSetPlayerName 0
    MEPlay 1304
    SystemMsg 38, 0
    MEWait
    MsgWaitAdvance
    InfoMsgClose
    VMStackPush 0x8021
    VMStackPushConst 6
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 18
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_05F4
    ActorCmdExec 255, Movement_0A60
    VMJump L_0650

L_05F4:
    VMStackPush 0x8021
    VMStackPushConst 7
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 17
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0625
    ActorCmdExec 255, Movement_0A50
    VMJump L_0650

L_0625:
    VMStackPush 0x8021
    VMStackPushConst 7
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 19
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0650
    ActorCmdExec 255, Movement_0A48

L_0650:
    ActorCmdWait
    Cmd_02B2 0, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 4
    VMJumpIf 255, L_067D
    ActorMsg 1024, 16, 0, 3, 0
    VMJump L_0689

L_067D:
    ActorMsg 1024, 17, 0, 3, 0

L_0689:
    LastKeyWait
    MsgWinCloseAll
    FlagSet 289
    FlagSet 714

L_0695:
    WorkSetConst 0x8023, 0
    VMReturn
    PlayerGetGPos 0x8021, 0x8022
    Cmd_020F 1, 8, 3, 18
    Cmd_0211 1
    FadeEx 12, 0, 16, 2
    FadeExWait
    ActorDelete 1
    FadeEx 12, 16, 0, 2
    FadeExWait
    Cmd_0210 1
    Cmd_020E 1, 0x8021, 3, 0x8022, 3, 8
    VMReturn
    .balign 4, 0

Movement_06E4:
    Move 36, 2
    MoveEnd

Script_3:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_071B
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_072F

L_071B:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose

L_072F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0764
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0778

L_0764:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose

L_0778:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 507, 0
    ParentActorMsg 1024, 27, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 596, 0
    ParentActorMsg 1024, 28, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 559, 0
    ParentActorMsg 1024, 29, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 504, 0
    ParentActorMsg 1024, 30, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 570, 0
    ParentActorMsg 1024, 31, 0, 0
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
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    VMStackPushFlag 430
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0912
    FlagSet 430
    ParentActorMsg 1024, 32, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_08FE
    VMCall L_097A
    Cmd_0262 1, 43
    FlagSet 491
    VMJump L_090C

L_08FE:
    ParentActorMsg 1024, 35, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_090C:
    VMJump L_0974

L_0912:
    VMStackPushFlag 2779
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0966
    ParentActorMsg 1024, 33, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0952
    VMCall L_097A
    VMJump L_0960

L_0952:
    ParentActorMsg 1024, 35, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0960:
    VMJump L_0974

L_0966:
    ParentActorMsg 1024, 36, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0974:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_097A:
    ParentActorMsg 1024, 34, 0, 0
    MsgWinCloseAll
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09A7
    CallTrainerBattle 696, 0, 0
    VMJump L_09D0

L_09A7:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_09C8
    CallTrainerBattle 697, 0, 0
    VMJump L_09D0

L_09C8:
    CallTrainerBattle 698, 0, 0

L_09D0:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_09EF
    CallTrainerBattleEnd
    VMJump L_09F1

L_09EF:
    CallTrainerLose

L_09F1:
    ParentActorMsg 1024, 36, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2779
    VMReturn
    .balign 4, 0
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
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

Movement_0A48:
    Move 32, 1
    MoveEnd

Movement_0A50:
    Move 33, 1
    MoveEnd

Movement_0A58:
    Move 34, 1
    MoveEnd

Movement_0A60:
    Move 35, 1
    MoveEnd

Movement_0A68:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd

Movement_0A78:
    Move 161, 1
    MoveEnd
