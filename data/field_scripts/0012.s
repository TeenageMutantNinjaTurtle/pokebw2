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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    RTCGetSeason 0x8020
    RTCGetDayPart 0x8021
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00B2
    VMStackPush 0x8021
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8021
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_00A8
    FlagReset 815
    VMJump L_00AC

L_00A8:
    FlagSet 815

L_00AC:
    VMJump L_00B6

L_00B2:
    FlagSet 815

L_00B6:
    VMStackPushFlag 374
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x410c
    VMStackPushConst 6
    VMStackCmp 5
    VMStackCmp 7
    VMJumpIf 255, L_00DF
    WorkSetConst 0x410c, 0

L_00DF:
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 26, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 27, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 28, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 29, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    VMStackPush 0x8006
    WorkSet 0x8000, 89
    WorkSet 0x8001, 1
    WorkSet 0x8002, 140
    WorkSet 0x8003, 11
    WorkSet 0x8004, 12
    WorkSet 0x8005, 12
    RTGetTextFile 0x8006
    RTCallGlobal 2800
    VMStackPop 0x8006
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    VMStackPush 0x8006
    WorkSet 0x8000, 13
    WorkSet 0x8001, 5
    WorkSet 0x8002, 142
    WorkSet 0x8003, 13
    WorkSet 0x8004, 14
    WorkSet 0x8005, 14
    RTGetTextFile 0x8006
    RTCallGlobal 2800
    VMStackPop 0x8006
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    RTCGetSeason 0x8020
    RTCGetDayPart 0x8021
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0290
    VMStackPush 0x8021
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8021
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0276
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_028A

L_0276:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose

L_028A:
    VMJump L_02A4

L_0290:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose

L_02A4:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 618, 0
    ParentActorMsg 1024, 24, 0, 0
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
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    Random 0x4000, 3
    VMStackPush 0x4000
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03AB
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_03F3

L_03AB:
    VMStackPush 0x4000
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03D2
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_03F3

L_03D2:
    VMStackPush 0x4000
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_03F3
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_03F3:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    MedalGetMostCompleteCategory 0x8022
    VMStackPush 0x8022
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_0452
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_04E8

L_0452:
    VMStackPush 0x8022
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0479
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_04E8

L_0479:
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_04A0
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_04E8

L_04A0:
    VMStackPush 0x8022
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_04C7
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_04E8

L_04C7:
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04E8
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_04E8:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 23, Movement_0548
    ActorCmdWait
    BMCreateHandleByGPos 0x8010, 1, 788, 586
    BMHndAudioVisualAnmPlay 0x8010, 0
    BMHndAnmWait 0x8010
    ActorCmdExec 23, Movement_0570
    ActorCmdWait
    ActorDelete 23
    BMHndAudioVisualAnmPlay 0x8010, 1
    BMHndAnmWait 0x8010
    BMReleaseHandle 0x8010
    FlagSet 1013
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0548:
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd
    Move 13, 1
    MoveEnd

Movement_0570:
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd
