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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_23:
    VMHalt

Script_22:
    ActorsPauseAll
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    ActorGetRailPos 255, 0x8021, 0x8022, 0x8023
    VMStackPush 0x8023
    VMStackPushConst 11
    VMStackCmp 2
    VMJumpIf 255, L_00A1
    ActorCmdExec 0, Movement_0A0C
    ActorCmdWait

L_00A1:
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8023
    VMStackPushConst 11
    VMStackCmp 2
    VMJumpIf 255, L_00D4
    DebugPrint 300
    ActorCmdExec 0, Movement_010C
    VMJump L_00DC

L_00D4:
    ActorCmdExec 0, Movement_0114

L_00DC:
    ActorCmdWait
    WorkSetConst 0x40b1, 2
    FlagSet 751
    FlagReset 1030
    ActorAdd 12
    ActorDelete 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_010C:
    Move 15, 12
    MoveEnd

Movement_0114:
    Move 15, 8
    MoveEnd

Script_9:
    ActorsPauseAll
    ActorMsg 1024, 1, 12, 0, 0
    MsgWinCloseAll
    ActorCmdExec 12, Movement_015C
    ActorCmdWait
    SEPlay 1369
    ActorDelete 12
    SEWait
    WorkSetConst 0x40b1, 3
    FlagSet 1030
    FlagReset 753
    WorkSetConst 0x40b2, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_015C:
    Move 13, 8
    MoveEnd

Script_20:
    ActorsPauseAll
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    ActorCmdExec 11, Movement_0A2C
    ActorCmdWait
    PlayerGetRailPos 0x8024, 0x8025, 0x8026
    VMStackPush 0x8024
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 4
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_01CB
    ActorCmdExec 11, Movement_08D8
    VMJump L_03CD

L_01CB:
    VMStackPush 0x8024
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_020C
    ActorCmdExec 11, Movement_08E4
    VMJump L_03CD

L_020C:
    VMStackPush 0x8024
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_024D
    ActorCmdExec 11, Movement_08F0
    VMJump L_03CD

L_024D:
    VMStackPush 0x8024
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_028E
    ActorCmdExec 11, Movement_08FC
    VMJump L_03CD

L_028E:
    VMStackPush 0x8024
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_02CF
    ActorCmdExec 11, Movement_0908
    VMJump L_03CD

L_02CF:
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 28
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0310
    ActorCmdExec 11, Movement_0914
    VMJump L_03CD

L_0310:
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 27
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0351
    ActorCmdExec 11, Movement_091C
    VMJump L_03CD

L_0351:
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 26
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0392
    ActorCmdExec 11, Movement_0928
    VMJump L_03CD

L_0392:
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 25
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_03CD
    ActorCmdExec 11, Movement_0934

L_03CD:
    ActorCmdWait
    ActorMsg 1024, 12, 11, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 450
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 13, 11, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMStackPush 0x8024
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 4
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_044E
    ActorCmdExec 11, Movement_0940
    VMJump L_0650

L_044E:
    VMStackPush 0x8024
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_048F
    ActorCmdExec 11, Movement_0950
    VMJump L_0650

L_048F:
    VMStackPush 0x8024
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_04D0
    ActorCmdExec 11, Movement_0960
    VMJump L_0650

L_04D0:
    VMStackPush 0x8024
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0511
    ActorCmdExec 11, Movement_0970
    VMJump L_0650

L_0511:
    VMStackPush 0x8024
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0552
    ActorCmdExec 11, Movement_0980
    VMJump L_0650

L_0552:
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 28
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0593
    ActorCmdExec 11, Movement_0990
    VMJump L_0650

L_0593:
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 27
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_05D4
    ActorCmdExec 11, Movement_099C
    VMJump L_0650

L_05D4:
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 26
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0615
    ActorCmdExec 11, Movement_09AC
    VMJump L_0650

L_0615:
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 25
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0650
    ActorCmdExec 11, Movement_09BC

L_0650:
    ActorCmdWait
    WorkSetConst 0x40e2, 2
    MedalDiscover 19
    FlagSet 2476
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_21:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40e2
    VMStackPushConst 6
    VMStackCmp 5
    VMJumpIf 255, L_07E7
    ParentActorMsg 1024, 14, 0, 0
    VMStackPush 0x40e2
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_06F6
    ParentActorMsg 1024, 19, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 50
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40e2, 6
    VMJump L_07E1

L_06F6:
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0

L_0702:
    VMStackPush 0x8028
    VMStackPushConst 3
    VMStackCmp 0
    VMJumpIf 255, L_07CC
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 312
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0750
    ActorMsg 1024, 15, 11, 0, 0
    WorkAdd 0x8027, 1
    VMJump L_07C0

L_0750:
    VMStackPush 0x8028
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 313
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_078B
    ActorMsg 1024, 16, 11, 0, 0
    WorkAdd 0x8027, 1
    VMJump L_07C0

L_078B:
    VMStackPush 0x8028
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPushFlag 314
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_07C0
    ActorMsg 1024, 17, 11, 0, 0
    WorkAdd 0x8027, 1

L_07C0:
    WorkAdd 0x8028, 1
    VMJump L_0702

L_07CC:
    WordSetNumber 0, 0x8027, 1
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_07E1:
    VMJump L_07F5

L_07E7:
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_07F5:
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8027, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 21, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 21, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 22, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 23, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 24, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 25, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 26, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 27, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_08D8:
    Move 14, 5
    Move 13, 2
    MoveEnd

Movement_08E4:
    Move 14, 4
    Move 13, 2
    MoveEnd

Movement_08F0:
    Move 14, 3
    Move 13, 2
    MoveEnd

Movement_08FC:
    Move 14, 2
    Move 13, 2
    MoveEnd

Movement_0908:
    Move 14, 1
    Move 13, 2
    MoveEnd

Movement_0914:
    Move 13, 2
    MoveEnd

Movement_091C:
    Move 15, 1
    Move 13, 2
    MoveEnd

Movement_0928:
    Move 15, 2
    Move 13, 2
    MoveEnd

Movement_0934:
    Move 15, 3
    Move 13, 2
    MoveEnd

Movement_0940:
    Move 12, 2
    Move 15, 5
    Move 33, 1
    MoveEnd

Movement_0950:
    Move 12, 2
    Move 15, 4
    Move 33, 1
    MoveEnd

Movement_0960:
    Move 12, 2
    Move 15, 3
    Move 33, 1
    MoveEnd

Movement_0970:
    Move 12, 2
    Move 15, 2
    Move 33, 1
    MoveEnd

Movement_0980:
    Move 12, 2
    Move 15, 1
    Move 33, 1
    MoveEnd

Movement_0990:
    Move 12, 2
    Move 33, 1
    MoveEnd

Movement_099C:
    Move 12, 2
    Move 14, 1
    Move 33, 1
    MoveEnd

Movement_09AC:
    Move 12, 2
    Move 14, 2
    Move 33, 1
    MoveEnd

Movement_09BC:
    Move 12, 2
    Move 14, 3
    Move 33, 1
    MoveEnd
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

Movement_0A0C:
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_0A2C:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 9, 6, 1, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
