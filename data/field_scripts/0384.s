#include "asm/field_script.inc"

// Script plugin 6, from the zones that use this file

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

Script_9:
    VMStackPush 0x4135
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0091
    FlagReset 892
    FlagReset 891
    ActorAdd 14
    ActorAdd 5
    ActorSetGPos 13, 15, 0, 11, 0
    ActorSetGPos 14, 14, 0, 11, 0
    ActorSetGPos 5, 14, 0, 9, 1

L_0091:
    VMHalt

Script_8:
    ActorsPauseAll
    ActorWalkRoute 255, 15, 25, 1, 8, 1
    VMSleep 8
    FlagReset 891
    SEPlay 1369
    ActorAdd 5
    SEWait
    ActorCmdWait
    ActorCmdExec 255, Movement_04DC
    ActorCmdExec 5, Movement_0508
    ActorCmdWait
    ActorMsg 1024, 0, 13, 0, 0
    MsgWinCloseAll
    ActorCmdExec 14, Movement_04BC
    ActorCmdWait
    ActorMsg 1024, 1, 14, 0, 0
    MsgWinCloseAll
    ActorCmdExec 13, Movement_04C4
    ActorCmdWait
    ActorMsg 1024, 2, 13, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 4, 14, 0, 0
    MsgWinCloseAll
    ActorCmdExec 14, Movement_04E4
    VMSleep 8
    ActorCmdExec 13, Movement_04CC
    WordSetLoadRivalName 1
    ActorMsg 1024, 5, 5, 0, 0
    MsgWinCloseAll
    ActorCmdExec 5, Movement_04C4
    VMSleep 3
    ActorCmdExec 255, Movement_04BC
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 6, 5, 0, 0
    MsgWinCloseAll
    ActorCmdExec 5, Movement_0518
    VMSleep 8
    ActorCmdExec 255, Movement_04CC
    ActorCmdWait
    VMSleep 30
    ActorCmdExec 0, Movement_04EC
    VMSleep 16
    ActorCmdExec 14, Movement_04E4
    ActorCmdExec 5, Movement_0528
    ActorCmdWait
    ActorDelete 14
    ActorDelete 5
    FlagSet 892
    FlagSet 891
    FlagSet 2441
    Cmd_0262 2, 1
    Cmd_0262 1, 13
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    ActorWalkRoute 255, 15, 9, 1, 8, 0
    ActorCmdWait
    ActorMsg 1024, 7, 13, 0, 0
    MsgWinCloseAll
    FlagReset 894
    ActorAdd 16
    ActorCmdExec 16, Movement_0530
    VMSleep 32
    ActorCmdExec 255, Movement_04BC
    ActorCmdExec 13, Movement_04BC
    VMSleep 3
    ActorCmdExec 5, Movement_04BC
    ActorCmdExec 14, Movement_04BC
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 8, 16, 0, 0
    MsgWinCloseAll
    ActorCmdExec 16, Movement_053C
    VMSleep 24
    ActorCmdExec 13, Movement_04CC
    VMSleep 3
    ActorCmdExec 255, Movement_04D4
    VMSleep 3
    ActorCmdExec 5, Movement_04D4
    ActorCmdExec 14, Movement_04CC
    ActorCmdWait
    ActorMsg 1024, 9, 13, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 13, 15, 19, 1, 8, 1
    VMSleep 8
    ActorCmdExec 14, Movement_04D4
    ActorCmdWait
    ActorDelete 16
    ActorDelete 13
    MapReplaceSetEvent 4, 1, 1
    MapReplaceSetEvent 3, 0, 0
    FlagSet 894
    FlagSet 893
    FlagSet 892
    FlagSet 891
    FlagReset 890
    WorkSetConst 0x40c6, 2
    WorkSetConst 0x4044, 0
    FlagReset 2441
    FlagReset 1001
    Cmd_0262 1, 14
    Cmd_0262 2, 2
    WorkSetConst 0x4135, 2
    ActorAdd 17
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 253
    WorkSet 0x8001, 2
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 254
    WorkSet 0x8001, 1
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_04BC:
    Move 35, 1
    MoveEnd

Movement_04C4:
    Move 34, 1
    MoveEnd

Movement_04CC:
    Move 32, 1
    MoveEnd

Movement_04D4:
    Move 33, 1
    MoveEnd

Movement_04DC:
    Move 12, 11
    MoveEnd

Movement_04E4:
    Move 12, 5
    MoveEnd

Movement_04EC:
    Move 12, 1
    Move 15, 1
    Move 34, 1
    Move 63, 6
    Move 14, 1
    Move 13, 1
    MoveEnd

Movement_0508:
    Move 12, 11
    Move 15, 1
    Move 12, 1
    MoveEnd

Movement_0518:
    Move 12, 6
    Move 14, 2
    Move 32, 1
    MoveEnd

Movement_0528:
    Move 12, 5
    MoveEnd

Movement_0530:
    Move 12, 5
    Move 34, 1
    MoveEnd

Movement_053C:
    Move 13, 6
    MoveEnd
