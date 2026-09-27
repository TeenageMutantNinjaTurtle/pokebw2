#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 338
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0142
    ParentActorMsg 1024, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_012E
    ParentActorMsg 1024, 1, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    CallPokeSelect 0, 0x8021, 0x8020, 0
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_011A
    PokePartyGetSpecies 0x8022, 0x8020
    PokePartyIsEgg 0x8023, 0x8020
    VMStackPush 0x8022
    VMStackPushConst 535
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0106
    ParentActorMsg 1024, 4, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMCall L_0225
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 338
    VMJump L_0114

L_0106:
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0114:
    VMJump L_0128

L_011A:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0128:
    VMJump L_013C

L_012E:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_013C:
    VMJump L_021F

L_0142:
    ParentActorMsg 1024, 6, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0211
    ParentActorMsg 1024, 1, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    CallPokeSelect 0, 0x8021, 0x8020, 0
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01FD
    PokePartyGetSpecies 0x8022, 0x8020
    PokePartyIsEgg 0x8023, 0x8020
    VMStackPush 0x8022
    VMStackPushConst 535
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_01E9
    ParentActorMsg 1024, 7, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMCall L_0225
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 338
    VMJump L_01F7

L_01E9:
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01F7:
    VMJump L_020B

L_01FD:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_020B:
    VMJump L_021F

L_0211:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_021F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0225:
    PlayerGetGPos 0x8025, 0x8026
    ActorCmdExec 0, Movement_0428
    VMSleep 3
    VMStackPush 0x8025
    VMStackPushConst 9
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 13
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0270
    ActorWalkRoute 255, 10, 12, 1, 8, 0
    ActorCmdWait
    VMJump L_027A

L_0270:
    ActorCmdExec 255, Movement_0428
    ActorCmdWait

L_027A:
    VMSleep 8
    FadeEx 3, 0, 16, 4
    FadeExWait
    ActorSetGPos 1, 7, 0, 9, 1
    ActorSetGPos 2, 8, 0, 9, 1
    ActorSetGPos 3, 9, 0, 9, 1
    ActorSetGPos 5, 10, 0, 9, 1
    ActorSetGPos 4, 11, 0, 9, 1
    ActorNew 12, 9, 1, 251, 313, 0
    FadeEx 3, 16, 0, 4
    FadeExWait
    VMSleep 16
    MEPlay 1339
    MEWait
    VMSleep 8
    FadeEx 3, 0, 16, 4
    FadeExWait
    ActorSetGPos 1, 13, 0, 10, 2
    ActorSetGPos 2, 14, 0, 5, 2
    ActorSetGPos 3, 8, 0, 7, 1
    ActorSetGPos 5, 8, 0, 12, 0
    ActorSetGPos 4, 6, 0, 11, 0
    ActorDelete 251
    FadeEx 3, 16, 0, 4
    FadeExWait
    VMSleep 32
    ActorCmdExec 0, Movement_0418
    VMSleep 3
    ActorCmdExec 255, Movement_0420
    ActorCmdWait
    VMReturn

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 535, 0
    ParentActorMsg 1024, 9, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 535, 0
    ParentActorMsg 1024, 10, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 535, 0
    ParentActorMsg 1024, 11, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 535, 0
    ParentActorMsg 1024, 12, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 535, 0
    ParentActorMsg 1024, 13, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0418:
    Move 35, 1
    MoveEnd

Movement_0420:
    Move 34, 1
    MoveEnd

Movement_0428:
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
