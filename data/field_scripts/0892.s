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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_7:
    WorkSetConst 0x8023, 0
    RTCGetSeason 0x8023
    VMStackPush 0x8023
    VMStackPushConst 2
    VMStackCmp 5
    VMJumpIf 255, L_0067
    FlagSet 910
    VMJump L_006B

L_0067:
    FlagReset 910

L_006B:
    VMStackPush 0x40ab
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0090
    ObjInitNPCGPos 21, 1, 162, 0xfffd, 668
    VMJump L_00AF

L_0090:
    VMStackPush 0x40ab
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_00AF
    ObjInitNPCGPos 21, 1, 151, 2, 646

L_00AF:
    VMStackPush 0x40ab
    VMStackPushConst 2
    VMStackCmp 4
    VMJumpIf 255, L_00CE
    ObjInitNPCGPos 0, 1, 160, 2, 643

L_00CE:
    WorkSetConst 0x8023, 0
    VMHalt

Script_8:
    VMHalt

Script_1:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 644
    VMStackCmp 1
    VMJumpIf 255, L_010D
    ActorCmdExec 0, Movement_0170
    VMSleep 46
    ActorCmdExec 255, Movement_07BC
    VMJump L_0134

L_010D:
    VMStackPush 0x8022
    VMStackPushConst 646
    VMStackCmp 1
    VMJumpIf 255, L_0134
    ActorCmdExec 0, Movement_017C
    VMSleep 46
    ActorCmdExec 255, Movement_07B4

L_0134:
    ActorCmdWait
    ActorMsg 1024, 2, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8022
    VMStackPushConst 645
    VMStackCmp 5
    VMJumpIf 255, L_015F
    ActorCmdExec 0, Movement_07C4

L_015F:
    ActorCmdExec 255, Movement_078C
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0170:
    Move 75, 1
    Move 32, 1
    MoveEnd

Movement_017C:
    Move 75, 1
    Move 33, 1
    MoveEnd

Script_2:
    ActorsPauseAll
    ActorCmdExec 0, Movement_07D4
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 5
    VMJumpIf 255, L_01B5
    VMSleep 20
    ActorCmdExec 255, Movement_07CC

L_01B5:
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 644
    VMStackCmp 1
    VMJumpIf 255, L_01E0
    ActorCmdExec 0, Movement_026C
    ActorCmdWait
    VMJump L_01FD

L_01E0:
    VMStackPush 0x8022
    VMStackPushConst 646
    VMStackCmp 1
    VMJumpIf 255, L_01FD
    ActorCmdExec 0, Movement_0278
    ActorCmdWait

L_01FD:
    ActorMsg 1024, 3, 0, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 206, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0232
    CallTrainerBattleEnd
    VMJump L_0234

L_0232:
    CallTrainerLose

L_0234:
    ActorMsg 1024, 4, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorWalkRoute 0, 160, 643, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_07BC
    ActorCmdWait
    WorkSetConst 0x40ab, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_026C:
    Move 12, 1
    Move 34, 1
    MoveEnd

Movement_0278:
    Move 13, 1
    Move 34, 1
    MoveEnd

Script_4:
    ActorsPauseAll
    VMStackPush 0x40ab
    VMStackPushConst 2
    VMStackCmp 4
    VMJumpIf 255, L_02B3
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_02C7

L_02B3:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose

L_02C7:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    InfoMsg 6, 2
    MsgWinCloseAll
    ActorSetGPos 21, 160, 0xffff, 650, 1
    ActorSetGPos 23, 161, 0xffff, 650, 1
    PlayerGetGPos 0x8021, 0x8022
    BGMPlay 1087
    ActorWalkRoute 23, 161, 658, 4, 8, 0
    VMSleep 4
    ActorWalkRoute 21, 160, 658, 4, 8, 0
    VMSleep 8
    ActorCmdExec 255, Movement_07B4
    ActorCmdWait
    VMStackPush 0x8021
    VMStackPushConst 161
    VMStackCmp 5
    VMJumpIf 255, L_0359
    ActorWalkRoute 255, 161, 660, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 255, Movement_07B4
    ActorCmdWait

L_0359:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorMsg 1024, 7, 23, 0, 0
    MsgWinCloseAll
    ActorCmdExec 23, Movement_04AC
    VMSleep 16
    ActorCmdExec 255, Movement_07CC
    ActorCmdExec 21, Movement_04BC
    ActorCmdWait
    ActorCmdExec 23, Movement_04D0
    VMSleep 4
    ActorCmdExec 21, Movement_04E0
    ActorCmdExec 255, Movement_04E0
    ActorCmdWait
    ActorCmdExec 23, Movement_04C8
    ActorCmdWait
    ActorMsg 1024, 8, 23, 0, 0
    MsgWinCloseAll
    ActorCmdExec 23, Movement_07B4
    ActorCmdWait
    ActorMsg 1024, 9, 23, 0, 0
    MsgWinCloseAll
    ActorCmdExec 23, Movement_077C
    ActorCmdWait
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 151
    WorkSet 0x8001, 3
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorCmdExec 23, Movement_04F0
    ActorCmdWait
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorMsg 1024, 10, 23, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 11, 23, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 23, 161, 653, 1, 8, 0
    VMSleep 16
    ActorCmdExec 21, Movement_07B4
    ActorCmdExec 255, Movement_07B4
    ActorCmdWait
    BGMChangeMap
    ActorMsg 1024, 12, 21, 0, 0
    MsgWinCloseAll
    ActorCmdExec 21, Movement_07CC
    ActorCmdExec 255, Movement_07C4
    ActorCmdWait
    ActorMsg 1024, 13, 21, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 21, 162, 668, 1, 8, 0
    ActorCmdWait
    ActorDelete 23
    WorkSetConst 0x40ab, 3
    FlagSet 703
    FlagSet 1032
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_04AC:
    Move 15, 1
    Move 13, 2
    Move 34, 1
    MoveEnd

Movement_04BC:
    Move 13, 2
    Move 35, 1
    MoveEnd

Movement_04C8:
    Move 181, 1
    MoveEnd

Movement_04D0:
    Move 13, 3
    Move 15, 2
    Move 13, 2
    MoveEnd

Movement_04E0:
    Move 13, 3
    Move 15, 3
    Move 33, 1
    MoveEnd

Movement_04F0:
    Move 14, 1
    Move 32, 1
    MoveEnd

Script_9:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    VMStackPush 0x40ab
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_0531
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0545

L_0531:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose

L_0545:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorSetGPos 21, 146, 2, 663, 3
    TrainerBGMPlayPush 763
    ActorMsg 1024, 15, 22, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 763, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0598
    CallTrainerBattleEnd
    VMJump L_059A

L_0598:
    CallTrainerLose

L_059A:
    ActorMsg 1024, 16, 22, 0, 0
    MsgWinCloseAll
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_05D3
    ActorWalkRoute 22, 155, 653, 1, 4, 0
    VMJump L_05E1

L_05D3:
    ActorWalkRoute 22, 156, 653, 1, 4, 0

L_05E1:
    VMSleep 8
    ActorCmdExec 255, Movement_07B4
    ActorCmdWait
    FlagReset 2558
    BGMChangeMap
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0630
    ActorWalkRoute 21, 156, 666, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 255, Movement_07CC
    ActorCmdExec 21, Movement_07C4
    ActorCmdWait
    VMJump L_06DB

L_0630:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_066B
    ActorWalkRoute 21, 155, 667, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 255, Movement_07C4
    ActorCmdExec 21, Movement_07CC
    ActorCmdWait
    VMJump L_06DB

L_066B:
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_06A6
    ActorWalkRoute 21, 156, 668, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 255, Movement_07CC
    ActorCmdExec 21, Movement_07C4
    ActorCmdWait
    VMJump L_06DB

L_06A6:
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_06DB
    ActorWalkRoute 21, 155, 667, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 255, Movement_07CC
    ActorCmdExec 21, Movement_07C4
    ActorCmdWait

L_06DB:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorMsg 1024, 17, 21, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 21, 155, 654, 1, 8, 1
    VMSleep 8
    ActorCmdExec 255, Movement_07B4
    ActorCmdWait
    ActorDelete 21
    ActorDelete 22
    FlagSet 701
    FlagSet 702
    WorkSetConst 0x40ab, 6
    FlagReset 726
    WorkSetConst 0x40ac, 7
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 5, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    CallLeafPileStuck
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    MoveEnd

Movement_077C:
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd

Movement_078C:
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

Movement_07B4:
    Move 32, 1
    MoveEnd

Movement_07BC:
    Move 33, 1
    MoveEnd

Movement_07C4:
    Move 34, 1
    MoveEnd

Movement_07CC:
    Move 35, 1
    MoveEnd

Movement_07D4:
    Move 75, 1
    MoveEnd
