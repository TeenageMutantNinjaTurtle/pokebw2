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

Script_1:
    VMHalt

Script_2:
    VMStackPush 0x40a3
    VMStackPushConst 1
    VMStackCmp 4
    VMStackPushFlag 739
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0081
    ActorSetGPos 0, 4, 0, 5, 3

L_0081:
    VMCall L_0091
    VMHalt

Script_18:
    VMCall L_0091
    VMHalt

L_0091:
    VMStackPushFlag 736
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00AE
    ObjInitPointGPos 7, 11, 0, 1

L_00AE:
    VMStackPushFlag 737
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00CB
    ObjInitPointGPos 8, 12, 0, 1

L_00CB:
    VMReturn

Script_17:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x58000, 0, 0xa8000, 1
    EvCameraWait
    FlagReset 740
    ActorAdd 0
    ActorSetGPos 0, 5, 0, 10, 0
    FadeInBlackQ
    FadeWait
    SEPlay 1369
    SEWait
    ActorWalkRoute 0, 5, 8, 0, 8, 1
    ActorCmdWait
    ActorCmdExec 0, Movement_0988
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 0, 0, 1, 0
    MsgWinCloseAll
    EvCameraReturn 40
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorCmdExec 255, Movement_0978
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    ActorWalkRoute 0, 9, 8, 1, 8, 1
    ActorCmdWait
    ActorMsg 1024, 1, 0, 1, 0
    WordSetPlayerName 0
    ActorMsg 1024, 2, 0, 1, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01F1
    WorkSetConst 0x8020, 1

L_019A:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01F1
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0990
    ActorCmdWait
    ActorCmdExec 0, Movement_0928
    ActorCmdWait
    ActorMsg 1024, 4, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0938
    ActorCmdWait
    ActorMsg 1024, 3, 0, 1, 0
    YesNoWin 0x8020
    VMJump L_019A

L_01F1:
    ActorMsg 1024, 5, 0, 1, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0226
    ActorMsg 1024, 6, 0, 1, 0
    VMJump L_0232

L_0226:
    ActorMsg 1024, 7, 0, 1, 0

L_0232:
    ActorMsg 1024, 8, 0, 1, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0284
    WorkSetConst 0x8020, 1

L_025B:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0284
    ActorMsg 1024, 10, 0, 1, 0
    YesNoWin 0x8020
    VMJump L_025B

L_0284:
    ActorMsg 1024, 9, 0, 1, 0
    VMStackPushFlag 1
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02BC
    WordSetPlayerName 0
    ActorMsg 1024, 11, 0, 1, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMJump L_0308

L_02BC:
    WordSetPlayerName 0
    ActorMsg 1024, 12, 0, 1, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02F8
    ActorMsg 1024, 14, 0, 1, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMJump L_0308

L_02F8:
    ActorMsg 1024, 13, 0, 1, 0
    MsgWaitAdvance
    MsgWinCloseAll

L_0308:
    ActorWalkRoute 0, 8, 7, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_0978
    ActorCmdWait
    WorkSetConst 0x40a0, 1
    Cmd_0263 4
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    WordSetPlayerName 0
    ActorCmdExec 0, Movement_0990
    ActorCmdWait
    ActorWalkRoute 0, 9, 8, 1, 8, 1
    ActorCmdWait
    ActorMsg 1024, 25, 0, 0, 0
    ActorMsg 1024, 26, 0, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 255, 5, 6, 1, 8, 0
    ActorWalkRoute 0, 4, 6, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_0978
    ActorCmdExec 255, Movement_0978
    ActorCmdWait
    SEPlay 1369
    ActorNew 5, 10, 0, 251, 104, 0
    SEWait
    BGMPlay 1090
    ActorWalkRoute 251, 5, 8, 1, 8, 0
    ActorCmdWait
    ActorMsg 1024, 27, 251, 2, 0
    MsgWinCloseAll
    ActorMsg 1024, 28, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0998
    ActorCmdWait
    ActorMsg 1024, 29, 251, 2, 0
    MsgWinCloseAll
    ActorWalkRoute 251, 5, 7, 1, 8, 0
    ActorCmdWait
    ActorMsg 1024, 30, 251, 2, 0
    MsgWinCloseAll
    MEPlay 1303
    WordSetPlayerName 0
    SystemMsg 31, 2
    MEWait
    MsgWaitAdvance
    MsgWinCloseAll
    PokeDexGiveNational
    ActorCmdExec 251, Movement_0940
    ActorCmdWait
    ActorMsg 1024, 32, 251, 2, 0
    MsgWinCloseAll
    ActorMsg 1024, 33, 0, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 34, 251, 2, 0
    ActorMsg 1024, 35, 251, 2, 0
    MsgWinCloseAll
    ActorWalkRoute 251, 5, 10, 1, 8, 0
    ActorCmdWait
    SEPlay 1369
    ActorDelete 251
    SEWait
    BGMChangeMap
    ActorCmdExec 0, Movement_0988
    VMSleep 8
    ActorCmdExec 255, Movement_0980
    ActorCmdWait
    ActorMsg 1024, 36, 0, 1, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 29
    WorkSet 0x8001, 2
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 37, 0, 1, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40a0, 3
    FlagReset 745
    FlagReset 744
    WorkSetConst 0x4115, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0515
    VMCall L_057B
    VMJump L_0575

L_0515:
    VMStackPushFlag 2406
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0542
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0575

L_0542:
    VMStackPush 0x40a1
    VMStackPushConst 2
    VMStackCmp 0
    VMJumpIf 255, L_056F
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0575

L_056F:
    VMCall L_057B

L_0575:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_057B:
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x400f
    VMStackPushConst 999
    VMStackCmp 1
    VMJumpIf 255, L_05AD
    WordSetPlayerName 0
    VMCall L_060C
    ParentActorMsg 1024, 0x8008, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_05AD:
    WordSetPlayerName 0
    ParentActorMsg 1024, 17, 0, 0
    MsgWinCloseAll
    VMCall L_05DE
    Random 0x400a, 5
    VMCall L_060C
    ParentActorMsg 1024, 0x8008, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_05DE:
    FadeEx 3, 0, 16, 2
    FadeExWait
    PokePartyRecoverAll
    MEPlay 1300
    MEWait
    FadeEx 3, 16, 0, 2
    FadeExWait
    WorkSetConst 0x400f, 999
    RecordAdd 72, 1
    VMReturn

L_060C:
    WordSetPlayerName 0
    WorkCmpConst 0x400a, 0
    VMJumpIf 1, L_0622
    VMJump L_062E

L_0622:
    WorkSetConst 0x8008, 18
    VMJump L_06AA

L_062E:
    WorkCmpConst 0x400a, 1
    VMJumpIf 1, L_0641
    VMJump L_064D

L_0641:
    WorkSetConst 0x8008, 19
    VMJump L_06AA

L_064D:
    WorkCmpConst 0x400a, 2
    VMJumpIf 1, L_0660
    VMJump L_066C

L_0660:
    WorkSetConst 0x8008, 20
    VMJump L_06AA

L_066C:
    WorkCmpConst 0x400a, 3
    VMJumpIf 1, L_067F
    VMJump L_068B

L_067F:
    WorkSetConst 0x8008, 21
    VMJump L_06AA

L_068B:
    WorkCmpConst 0x400a, 4
    VMJumpIf 1, L_069E
    VMJump L_06AA

L_069E:
    WorkSetConst 0x8008, 22
    VMJump L_06AA

L_06AA:
    VMReturn

Script_5:
    ActorsPauseAll
    VMStackPush 0x4115
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x4115
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_06EB
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 49, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_071E

L_06EB:
    VMStackPush 0x4115
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_070A
    VMCall L_0724
    VMJump L_071E

L_070A:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    ActorMsgClose

L_071E:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0724:
    Random 0x8010, 5
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_073D
    VMJump L_0757

L_073D:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 50, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_080B

L_0757:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_076A
    VMJump L_0784

L_076A:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 51, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_080B

L_0784:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0797
    VMJump L_07B1

L_0797:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 52, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_080B

L_07B1:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_07C4
    VMJump L_07DE

L_07C4:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 53, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_080B

L_07DE:
    WorkCmpConst 0x8010, 4
    VMJumpIf 1, L_07F1
    VMJump L_080B

L_07F1:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 54, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_080B

L_080B:
    VMReturn

Script_6:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 39, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 40, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    InfoMsg 41, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 42, 2
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    FieldClose
    CallPokedexDiploma 0, 1
    FieldOpen
    FadeInBlackQ
    FadeWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 43, 2
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    FieldClose
    CallPokedexDiploma 1, 1
    FieldOpen
    FadeInBlackQ
    FadeWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 44, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 45, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 46, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 47, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 48, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    VMNop
    VMHalt
    VMNop2
    VMNop
    VMNop2
    VMSleep 1
    VMNop2
    VMNop2
    VMHalt
    .byte 0x01
    .balign 4, 0
    Move 0, 1
    Move 3, 1
    Move 61, 1
    MoveEnd

Movement_0928:
    Move 71, 1
    Move 14, 1
    Move 72, 1
    MoveEnd

Movement_0938:
    Move 15, 1
    MoveEnd

Movement_0940:
    Move 71, 1
    Move 13, 1
    Move 72, 1
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

Movement_0978:
    Move 33, 1
    MoveEnd

Movement_0980:
    Move 34, 1
    MoveEnd

Movement_0988:
    Move 35, 1
    MoveEnd

Movement_0990:
    Move 75, 1
    MoveEnd

Movement_0998:
    Move 159, 1
    MoveEnd
