#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0

Script_1:
    Cmd_02C4
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x4108
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_0142
    ParentActorMsg 1024, 0, 1, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_012E
    ItemSub 30, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_011A
    MsgWinCloseAll
    SEPlay 2017
    SEWait
    ParentActorMsg 1024, 1, 1, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    PlayerGetRailPos 0x8025, 0x8026, 0x8027
    VMStackPush 0x8026
    VMStackPushConst 22
    VMStackCmp 1
    VMJumpIf 255, L_00EC
    ActorCmdExec 4, Movement_016C
    VMJump L_00F4

L_00EC:
    ActorCmdExec 4, Movement_017C

L_00F4:
    VMSleep 20
    ActorCmdExec 255, Movement_0188
    ActorCmdWait
    ActorDelete 4
    WorkSetConst 0x4108, 6
    FlagSet 863
    FlagReset 858
    VMJump L_0128

L_011A:
    ParentActorMsg 1024, 2, 1, 0
    LastKeyWait
    MsgWinCloseAll

L_0128:
    VMJump L_013C

L_012E:
    ParentActorMsg 1024, 3, 1, 0
    LastKeyWait
    MsgWinCloseAll

L_013C:
    VMJump L_0163

L_0142:
    VMStackPush 0x4108
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_0163
    ParentActorMsg 1024, 1, 1, 0
    LastKeyWait
    MsgWinCloseAll

L_0163:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_016C:
    Move 39, 4
    Move 19, 1
    Move 17, 13
    MoveEnd

Movement_017C:
    Move 37, 4
    Move 17, 13
    MoveEnd

Movement_0188:
    Move 1, 1
    MoveEnd

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 1, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 1, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 1, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 389
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0316
    PokePartyGetCount 0x8020, 0

L_023D:
    VMStackPush 0x8020
    VMStackPush 0x8021
    VMStackCmp 2
    VMJumpIf 255, L_02AB
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_029F
    PokePartyGetParam 0x8022, 0x8021, 6
    PokePartyIsEgg 0x8024, 0x8021
    VMStackPush 0x8022
    VMStackPush 245
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_029F
    WordSetPartyPokeSpecies 0, 0x8021
    WorkSetConst 0x8023, 1

L_029F:
    WorkAdd 0x8021, 1
    VMJump L_023D

L_02AB:
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0302
    ParentActorMsg 1024, 10, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 281
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 389
    VMJump L_0310

L_0302:
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0310:
    VMJump L_0324

L_0316:
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0324:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
