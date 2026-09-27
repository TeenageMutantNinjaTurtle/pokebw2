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
    ScriptEntriesEnd

Script_10:
    Cmd_0262 0, 0
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 19, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 21, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 22, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 23, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 24, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 388
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0101
    ParentActorMsg 1024, 0, 0, 0
    RTCallGlobal 10380
    ItemCheckAmount 630, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00F7
    ActorCmdExec 1, Movement_0208
    ActorCmdWait
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_00F7:
    FlagSet 388
    VMJump L_010F

L_0101:
    ParentActorMsg 1024, 1, 0, 0
    RTCallGlobal 10380

L_010F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WordSetPlayerName 0
    VMStackPushFlag 387
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_014B
    ParentActorMsg 1024, 14, 0, 0
    RTCallGlobal 10381
    FlagSet 387
    VMJump L_0159

L_014B:
    ParentActorMsg 1024, 15, 0, 0
    RTCallGlobal 10381

L_0159:
    VMStackPushFlag 2437
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01B8
    ActorCmdExec 0, Movement_0208
    ActorCmdWait
    ParentActorMsg 1024, 16, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 447
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2437
    MedalDiscover 23

L_01B8:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 505, 0
    ParentActorMsg 1024, 18, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 573, 0
    ParentActorMsg 1024, 25, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0208:
    Move 75, 1
    MoveEnd
