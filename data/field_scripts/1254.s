#include "asm/field_script.inc"

// Script plugin 4, from the zones that start its scripts

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_004E
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    WorkSetConst 0x4085, 1
    VMCall L_0560
    VMCall L_004E
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_004E:
    VMStackPushFlag 123
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0083
    FlagSet 123
    ActorMsg 1024, 33, 0, 0, 0
    ActorMsg 1024, 34, 0, 0, 0
    VMJump L_008F

L_0083:
    ActorMsg 1024, 0, 0, 0, 0

L_008F:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0199
    WorkSetConst 0x8021, 0
    Cmd_01DD 5, 0, 0
    BoxGetCount 0x8021, 5
    VMStackPush 0x8021
    VMStackPushConst 6
    VMStackCmp 4
    VMJumpIf 255, L_0187
    ActorMsg 1024, 3, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_017B
    ActorMsgClose
    GameCommCheckDSiWiFi 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0119
    RTCallGlobal 2005
    VMCall L_01B3
    VMJump L_0175

L_0119:
    SystemMsg 4, 0
    YesNoWin 0x8010
    InfoMsgClose
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_016F
    VMCall L_01C1
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0163
    VMCall L_0228
    VMCall L_01B3
    VMJump L_0169

L_0163:
    VMCall L_01B3

L_0169:
    VMJump L_0175

L_016F:
    VMCall L_01B3

L_0175:
    VMJump L_0181

L_017B:
    VMCall L_01B3

L_0181:
    VMJump L_0193

L_0187:
    WorkSetConst 0x8020, 2
    VMCall L_01A1

L_0193:
    VMJump L_019F

L_0199:
    VMCall L_01B3

L_019F:
    VMReturn

L_01A1:
    ActorMsg 1024, 0x8020, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_01B3:
    WorkSetConst 0x8020, 1
    VMCall L_01A1
    VMReturn

L_01C1:
    WorkSetConst 0x8022, 0
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    RTCallGlobal 2003
    WorkSet 0x8022, 0x8000
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0220
    WorkSetConst 0x8010, 0
    VMJump L_0226

L_0220:
    WorkSetConst 0x8010, 1

L_0226:
    VMReturn

L_0228:
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    VMStackPush 0x8000
    RTCallGlobal 2004
    WorkSet 0x8023, 0x8000
    VMStackPop 0x8000
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0261
    VMReturn
    VMJump L_0276

L_0261:
    VMStackPush 0x8023
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0276
    VMReturn

L_0276:
    FunfestBGMReturn
    ActorMsg 1024, 6, 0, 0, 0
    ActorMsgClose
    VMCall L_0460
    WorkSetConst 0x408d, 1
    Plugin4_Cmd1000
    WorkSetConst 0x408d, 0
    VMCall L_04CA
    Plugin4_Cmd1001 0, 0x8024
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_02C4
    VMCall L_039D
    VMJump L_039B

L_02C4:
    VMStackPush 0x8024
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_02DD
    VMJump L_039B

L_02DD:
    VMStackPush 0x8024
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_0308
    VMCall L_039D
    ActorMsg 1024, 15, 0, 0, 0
    VMJump L_039B

L_0308:
    WorkSetConst 0x8025, 0
    ActorMsg 1024, 8, 0, 0, 0
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_033F
    VMCall L_03AB
    WorkSetConst 0x8025, 15
    VMJump L_0389

L_033F:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0364
    VMCall L_03AB
    WorkSetConst 0x8025, 15
    VMJump L_0389

L_0364:
    VMStackPush 0x8024
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0383
    WorkSetConst 0x8025, 16
    VMJump L_0389

L_0383:
    WorkSetConst 0x8025, 16

L_0389:
    ActorMsg 1024, 0x8025, 0, 0, 0
    WorkSetConst 0x8025, 0

L_039B:
    VMReturn

L_039D:
    ActorMsg 1024, 17, 0, 0, 0
    VMReturn

L_03AB:
    WorkSetConst 0x8026, 0
    VMStackPush 0x4000
    VMStackPushConst 900
    VMStackCmp 4
    VMJumpIf 255, L_03D0
    WorkSetConst 0x8026, 14
    VMJump L_0452

L_03D0:
    VMStackPush 0x4000
    VMStackPushConst 800
    VMStackCmp 4
    VMJumpIf 255, L_03EF
    WorkSetConst 0x8026, 13
    VMJump L_0452

L_03EF:
    VMStackPush 0x4000
    VMStackPushConst 700
    VMStackCmp 4
    VMJumpIf 255, L_040E
    WorkSetConst 0x8026, 12
    VMJump L_0452

L_040E:
    VMStackPush 0x4000
    VMStackPushConst 550
    VMStackCmp 4
    VMJumpIf 255, L_042D
    WorkSetConst 0x8026, 11
    VMJump L_0452

L_042D:
    VMStackPush 0x4000
    VMStackPushConst 400
    VMStackCmp 4
    VMJumpIf 255, L_044C
    WorkSetConst 0x8026, 10
    VMJump L_0452

L_044C:
    WorkSetConst 0x8026, 9

L_0452:
    ActorMsg 1024, 0x8026, 0, 0, 0
    VMReturn

L_0460:
    WorkSetConst 0x8027, 0
    ActorCmdExec 0, Movement_0504
    ActorCmdWait
    ActorCmdExec 255, Movement_0514
    ActorCmdWait
    ActorCmdExec 0, Movement_051C
    ActorCmdWait
    BMCreateHandleByGPos 0x8027, 9, 10, 3
    SEPlay 1892
    BMHndAudioVisualAnmPlay 0x8027, 0
    BMHndAnmWait 0x8027
    BMHndAnmPlay 0x8027, 1
    SEWait
    ActorCmdExec 0, Movement_0534
    ActorCmdWait
    ActorMsg 1024, 7, 0, 0, 0
    ActorMsgClose
    FadeOutBlackQ
    FadeWait
    BMHndAnmPause 0x8027
    BMReleaseHandle 0x8027
    VMReturn

L_04CA:
    FadeInBlackQ
    FadeWait
    ActorCmdExec 255, Movement_0544
    ActorCmdWait
    ActorCmdExec 0, Movement_054C
    ActorCmdWait
    ActorCmdExec 255, Movement_0558
    ActorCmdWait
    VMReturn

L_04EE:
    ActorCmdExec 255, Movement_0544
    ActorCmdWait
    ActorCmdExec 0, Movement_054C
    ActorCmdWait
    VMReturn

Movement_0504:
    Move 16, 1
    Move 18, 1
    Move 35, 1
    MoveEnd

Movement_0514:
    Move 12, 4
    MoveEnd

Movement_051C:
    Move 16, 1
    Move 18, 1
    Move 36, 1
    Move 19, 4
    Move 36, 1
    MoveEnd

Movement_0534:
    Move 18, 3
    Move 17, 1
    Move 36, 1
    MoveEnd

Movement_0544:
    Move 13, 4
    MoveEnd

Movement_054C:
    Move 19, 1
    Move 17, 1
    MoveEnd

Movement_0558:
    Move 32, 1
    MoveEnd

L_0560:
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    PlayerGetGPos 0x8028, 0x8029
    VMStackPush 0x8028
    VMStackPushConst 9
    VMStackCmp 1
    VMJumpIf 255, L_0593
    ActorCmdExec 1, Movement_0800
    VMJump L_05BC

L_0593:
    VMStackPush 0x8028
    VMStackPushConst 11
    VMStackCmp 1
    VMJumpIf 255, L_05B4
    ActorCmdExec 1, Movement_0814
    VMJump L_05BC

L_05B4:
    ActorCmdExec 1, Movement_0828

L_05BC:
    ActorCmdWait
    ActorMsg 1024, 18, 1, 0, 0
    ActorMsgClose
    ActorCmdExec 1, Movement_08D8
    ActorCmdWait
    ActorMsg 1024, 19, 1, 0, 1
    ActorMsgClose
    ActorMsg 1024, 20, 1, 0, 0
    ActorMsgClose
    ActorCmdExec 1, Movement_08E0
    ActorCmdWait
    ActorMsg 1024, 21, 1, 0, 0
    ActorMsgClose
    VMStackPush 0x8028
    VMStackPushConst 9
    VMStackCmp 1
    VMJumpIf 255, L_064B
    ActorCmdExec 1, Movement_085C
    ActorCmdWait
    ActorMsg 1024, 22, 1, 0, 0
    ActorMsgClose
    ActorCmdExec 1, Movement_0894
    ActorCmdExec 255, Movement_0834
    VMJump L_06B4

L_064B:
    VMStackPush 0x8028
    VMStackPushConst 11
    VMStackCmp 1
    VMJumpIf 255, L_068C
    ActorCmdExec 1, Movement_0870
    ActorCmdWait
    ActorMsg 1024, 22, 1, 0, 0
    ActorMsgClose
    ActorCmdExec 1, Movement_0894
    ActorCmdExec 255, Movement_0844
    VMJump L_06B4

L_068C:
    ActorCmdExec 1, Movement_0884
    ActorCmdWait
    ActorMsg 1024, 22, 1, 0, 0
    ActorMsgClose
    ActorCmdExec 1, Movement_0894
    ActorCmdExec 255, Movement_0854

L_06B4:
    ActorCmdWait
    ActorMsg 1024, 23, 1, 0, 0
    ActorMsgClose
    ActorCmdExec 1, Movement_08D0
    ActorCmdWait
    ActorMsg 1024, 24, 1, 0, 0
    ActorMsgClose
    ActorCmdExec 1, Movement_08A0
    ActorCmdWait
    ActorCmdExec 255, Movement_08B8
    ActorCmdWait
    ActorMsg 1024, 25, 0, 4, 0
    ActorMsgClose
    ActorCmdExec 0, Movement_08D8
    ActorCmdWait
    ActorCmdExec 0, Movement_08E8
    ActorCmdWait
    ActorMsg 1024, 26, 0, 0, 1
    ActorMsgClose
    ActorMsg 1024, 27, 0, 0, 1
    ActorMsgClose
    ActorMsg 1024, 28, 0, 0, 1
    ActorMsgClose
    ActorCmdExec 0, Movement_08F4
    ActorCmdWait
    ActorMsg 1024, 29, 0, 0, 0
    ActorMsgClose
    WordSetPlayerName 0
    ActorMsg 1024, 30, 1, 0, 0
    ActorMsgClose
    ActorMsg 1024, 31, 0, 0, 0
    ActorMsgClose
    ActorCmdExec 1, Movement_08C0
    ActorCmdWait
    ActorCmdExec 255, Movement_08C8
    ActorCmdWait
    ActorMsg 1024, 32, 1, 0, 0
    ActorMsgClose
    ActorCmdExec 1, Movement_08D0
    ActorCmdExec 255, Movement_08D0
    ActorCmdWait
    VMReturn

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 35, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 36, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 37, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0800:
    Move 75, 1
    Move 13, 1
    Move 14, 1
    Move 1, 1
    MoveEnd

Movement_0814:
    Move 75, 1
    Move 13, 1
    Move 15, 1
    Move 1, 1
    MoveEnd

Movement_0828:
    Move 75, 1
    Move 13, 1
    MoveEnd

Movement_0834:
    Move 12, 1
    Move 15, 1
    Move 12, 12
    MoveEnd

Movement_0844:
    Move 12, 1
    Move 14, 1
    Move 12, 12
    MoveEnd

Movement_0854:
    Move 12, 13
    MoveEnd

Movement_085C:
    Move 19, 1
    Move 16, 1
    Move 63, 1
    Move 37, 1
    MoveEnd

Movement_0870:
    Move 18, 1
    Move 16, 1
    Move 63, 1
    Move 37, 1
    MoveEnd

Movement_0884:
    Move 16, 1
    Move 63, 1
    Move 37, 1
    MoveEnd

Movement_0894:
    Move 16, 12
    Move 1, 1
    MoveEnd

Movement_08A0:
    Move 2, 1
    Move 71, 1
    Move 15, 1
    Move 72, 1
    Move 0, 1
    MoveEnd

Movement_08B8:
    Move 12, 1
    MoveEnd

Movement_08C0:
    Move 2, 1
    MoveEnd

Movement_08C8:
    Move 3, 1
    MoveEnd

Movement_08D0:
    Move 0, 1
    MoveEnd

Movement_08D8:
    Move 75, 1
    MoveEnd

Movement_08E0:
    Move 36, 1
    MoveEnd

Movement_08E8:
    Move 37, 1
    Move 17, 3
    MoveEnd

Movement_08F4:
    Move 2, 1
    Move 0, 1
    Move 3, 1
    Move 1, 1
    Move 2, 1
    Move 0, 1
    Move 3, 1
    Move 1, 1
    Move 2, 1
    Move 0, 1
    Move 3, 1
    Move 1, 1
    Move 2, 1
    Move 0, 1
    Move 3, 1
    Move 1, 1
    Move 2, 1
    Move 0, 1
    Move 3, 1
    Move 1, 1
    Move 2, 1
    Move 0, 1
    Move 3, 1
    Move 1, 1
    Move 2, 1
    Move 0, 1
    Move 3, 1
    Move 1, 1
    Move 2, 1
    Move 0, 1
    Move 3, 1
    Move 1, 1
    Move 49, 2
    MoveEnd

Script_6:
    VMCall L_04EE
    WorkSetConst 0x408d, 0
    RTEndGlobal
    VMHalt
