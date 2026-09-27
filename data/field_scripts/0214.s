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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_21:
    VMCall L_0167
    VMHalt

Script_7:
    Cmd_02B2 13, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4049
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x40cb
    VMStackPushConst 1
    VMStackCmp 4
    VMStackPushFlag 496
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_00C9
    FlagReset 765
    ObjInitNPCGPos 3, 1, 78, 0, 269

L_00C9:
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4049
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x40cb
    VMStackPushConst 1
    VMStackCmp 4
    VMStackPushFlag 496
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0116
    WorkSetConst 0x4154, 1
    FlagSet 765

L_0116:
    VMCall L_0122
    FlagReset 496
    VMHalt

L_0122:
    Cmd_02B2 13, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4049
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x40cb
    VMStackPushConst 1
    VMStackCmp 4
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0165
    WorkSetConst 0x4154, 0
    FlagSet 765

L_0165:
    VMReturn

L_0167:
    Cmd_02B2 13, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4049
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x40cb
    VMStackPushConst 1
    VMStackCmp 4
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_01C1
    VMStackPushFlag 765
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01B7
    ActorDelete 3

L_01B7:
    WorkSetConst 0x4154, 0
    FlagSet 765

L_01C1:
    VMReturn

Script_8:
    VMHalt

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 41, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 42, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 43, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    FlagReset 621
    ActorAdd 1
    ActorAdd 2
    ActorAdd 8
    ActorDelete 0
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 367
    WorkSet 0x8001, 1
    RTCallGlobal 2814
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 615
    FlagSet 139
    ScreamMsg 28, 1
    MsgWinCloseAll
    ActorCmdExec 255, Movement_09B8
    ActorCmdWait
    ActorCmdExec 255, Movement_0988
    ActorCmdExec 1, Movement_0958
    ActorCmdExec 2, Movement_0960
    ActorCmdExec 8, Movement_0968
    ActorCmdWait
    ActorMsg 1024, 29, 2, 6, 0
    MsgWinCloseAll
    VMSleep 32
    ActorMsgGendered 1024, 30, 31, 1, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 32, 2, 6, 0
    MsgWinCloseAll
    PVPlay 580, 0
    ActorMsg 1024, 33, 8, 1, 0
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll
    VMSleep 8
    ActorMsg 1024, 34, 1, 5, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0970
    ActorCmdExec 2, Movement_0978
    ActorCmdExec 8, Movement_0980
    ActorCmdWait
    ActorDelete 1
    ActorDelete 2
    ActorDelete 8
    FlagSet 621
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    WorkSetConst 0x40c2, 1
    PlayerGetGPos 0x8021, 0x8022
    ActorWalkRoute 4, 0x8021, 297, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 4, Movement_091C
    ActorCmdWait
    BGMPlay 1089
    PlayerGetGPos 0x8021, 0x8022
    WorkSub 0x8022, 1
    ActorWalkRoute 4, 0x8021, 0x8022, 1, 8, 0
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 0, 4, 0, 0
    ActorMsg 1024, 1, 4, 0, 0
    ActorMsg 1024, 2, 4, 0, 0
    WordSetPlayerName 0
    WorkSetConst 0x8023, 0
    PokeDexGetCount 0, 0x8023
    WordSetNumber 1, 0x8023, 3
    ActorMsg 1024, 3, 4, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 1
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 4, 4, 0, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_0990
    ActorCmdWait
    ActorMsg 1024, 5, 4, 0, 0
    MsgWinCloseAll
    VMSleep 30
    InfoMsg 6, 1
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0928
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 100
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 301
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0471
    ActorWalkRoute 3, 101, 300, 1, 8, 0
    VMSleep 80
    ActorCmdExec 4, Movement_09A8
    ActorCmdExec 255, Movement_09A8
    ActorCmdWait
    ActorCmdExec 3, Movement_0990
    VMSleep 8
    ActorCmdExec 4, Movement_0988
    ActorCmdExec 255, Movement_0988
    ActorCmdWait
    VMJump L_04BF

L_0471:
    WorkSub 0x8022, 1
    WorkSub 0x8021, 1
    ActorWalkRoute 3, 0x8021, 0x8022, 1, 8, 0
    VMSleep 80
    ActorCmdExec 4, Movement_09A8
    ActorCmdExec 255, Movement_09A8
    ActorCmdWait
    ActorCmdExec 3, Movement_0988
    VMSleep 8
    ActorCmdExec 4, Movement_0990
    ActorCmdExec 255, Movement_0990
    ActorCmdWait

L_04BF:
    ActorMsg 1024, 7, 4, 0, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_09B0
    VMSleep 8
    ActorCmdExec 255, Movement_09A8
    ActorCmdWait
    ActorMsg 1024, 8, 4, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 9, 3, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8021
    VMStackPushConst 100
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 301
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_053C
    ActorCmdExec 4, Movement_0988
    VMSleep 8
    ActorCmdExec 255, Movement_0988
    VMJump L_0550

L_053C:
    ActorCmdExec 4, Movement_0990
    VMSleep 8
    ActorCmdExec 255, Movement_0990

L_0550:
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 10, 4, 0, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_09B0
    VMSleep 8
    ActorCmdExec 255, Movement_09A8
    ActorCmdWait
    ActorMsg 1024, 11, 4, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    ActorWalkRoute 4, 109, 297, 1, 8, 1
    VMSleep 16
    ActorCmdExec 3, Movement_09A8
    ActorCmdWait
    ActorDelete 4
    BGMChangeMap
    ActorMsg 1024, 12, 3, 0, 0
    MsgWinCloseAll
    VMSleep 15
    PlayerGetGPos 0x8021, 0x8022
    WorkSub 0x8022, 1
    ActorWalkRoute 3, 0x8021, 0x8022, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 3, Movement_09B0
    ActorCmdWait
    ActorMsg 1024, 13, 3, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 3, 90, 297, 1, 8, 1
    ActorCmdWait
    ActorDelete 3
    FlagSet 765
    FlagSet 699
    Cmd_0262 0, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    ActorWalkRoute 255, 78, 271, 1, 8, 1
    ActorCmdWait
    FlagReset 765
    FlagReset 699
    ActorAdd 3
    ActorAdd 4
    SEPlay 1369
    ActorSetGPos 3, 78, 0, 268, 1
    SEWait
    ActorSetGPos 4, 84, 0, 279, 0
    VMSleep 15
    ActorWalkRoute 3, 78, 270, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 255, Movement_09A8
    ActorCmdWait
    ActorMsg 1024, 14, 3, 0, 0
    MsgWinCloseAll
    VMStackPush 0x40c2
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_071F
    ActorCmdExec 4, Movement_0934
    ActorCmdWait
    ActorCmdExec 3, Movement_0988
    ActorCmdExec 255, Movement_0988
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 16, 4, 0, 0
    ActorMsg 1024, 17, 4, 0, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_0940
    ActorCmdWait
    ActorMsg 1024, 18, 3, 0, 0
    MsgWinCloseAll
    ActorCmdExec 3, Movement_09B0
    ActorCmdExec 255, Movement_09A8
    ActorCmdWait
    ActorMsg 1024, 19, 3, 0, 0
    MsgWinCloseAll
    FlagReset 767
    FlagReset 768
    FlagSet 766
    VMJump L_0731

L_071F:
    ActorMsg 1024, 15, 3, 0, 0
    MsgWinCloseAll
    FlagReset 767

L_0731:
    ActorCmdExec 3, Movement_094C
    VMSleep 16
    ActorCmdExec 255, Movement_0988
    ActorCmdWait
    ActorDelete 3
    ActorDelete 4
    FlagSet 765
    FlagSet 699
    FlagSet 1006
    WorkSetConst 0x40c1, 2
    WorkAdd 0x40c2, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 35, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    RTReserveScript 1
    FadeWait
    MapChangeCore 599, 6, 0, 5, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    FlagReset 765
    ActorWalkRoute 255, 78, 271, 0, 8, 1
    ActorCmdWait
    ActorAdd 3
    SEPlay 1369
    ActorSetGPos 3, 78, 0, 268, 1
    SEWait
    ActorCmdExec 255, Movement_09A8
    ActorCmdWait
    ActorWalkRoute 3, 78, 269, 4, 8, 1
    ActorCmdWait
    ActorMsg 1024, 35, 3, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    RTReserveScript 1
    FadeWait
    MapChangeCore 599, 6, 0, 5, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    ActorMsg 1024, 36, 3, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 3, Movement_0914
    ActorCmdWait
    SEPlay 1369
    ActorDelete 3
    SEWait
    WorkSetConst 0x4049, 1
    WorkSetConst 0x4154, 2
    FlagSet 765
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 26, 27, 15, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0914:
    Move 12, 1
    MoveEnd

Movement_091C:
    Move 33, 1
    Move 75, 1
    MoveEnd

Movement_0928:
    Move 75, 1
    Move 34, 1
    MoveEnd

Movement_0934:
    Move 12, 9
    Move 14, 4
    MoveEnd

Movement_0940:
    Move 15, 4
    Move 13, 9
    MoveEnd

Movement_094C:
    Move 15, 5
    Move 13, 8
    MoveEnd

Movement_0958:
    Move 18, 7
    MoveEnd

Movement_0960:
    Move 14, 7
    MoveEnd

Movement_0968:
    Move 14, 7
    MoveEnd

Movement_0970:
    Move 15, 7
    MoveEnd

Movement_0978:
    Move 15, 7
    MoveEnd

Movement_0980:
    Move 79, 7
    MoveEnd

Movement_0988:
    Move 35, 1
    MoveEnd

Movement_0990:
    Move 34, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0
    Move 30, 1
    MoveEnd

Movement_09A8:
    Move 32, 1
    MoveEnd

Movement_09B0:
    Move 33, 1
    MoveEnd

Movement_09B8:
    Move 75, 1
    MoveEnd
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd

Script_18:
    ActorsPauseAll
    VMStackPushFlag 2449
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0A36
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 37, 0, 0
    MsgWinCloseAll
    Cmd_0275 0, 20, 0
    SEPlay 1908
    SystemMsg 38, 0
    SEWait
    MsgWaitAdvance
    MsgWinCloseAll
    ParentActorMsg 1024, 39, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2449
    VMJump L_0A4A

L_0A36:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 39, 0, 0
    LastKeyWait
    ActorMsgClose

L_0A4A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    WordSetLoadJoinAvenueName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 40, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
