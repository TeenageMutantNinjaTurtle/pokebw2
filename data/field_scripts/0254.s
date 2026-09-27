#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WordSetPlayerName 1
    MusicalIsPropOwned 99, 0x4001
    MusicalIsPropOwned 98, 0x4002
    MusicalIsPropOwned 95, 0x4003
    MusicalIsPropOwned 96, 0x4004
    VMStackPush 0x4001
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4002
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4003
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4004
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_007A
    WorkSetConst 0x4084, 1

L_007A:
    ItemCheckAmount 578, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0222
    VMStackPush 0x4084
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00BE
    ActorMsg 1024, 6, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_021C

L_00BE:
    VMStackPushFlag 2730
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00E7
    ActorMsg 1024, 5, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_021C

L_00E7:
    ActorMsg 1024, 1, 0, 0, 0
    WorkSetConst 0x8020, 0
    YesNoWin 0x8020
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_020C
    ActorMsg 1024, 2, 0, 0, 0
    ActorMsgClose
    WorkSetConst 0x8021, 0
    VMStackPush 0x4001
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_015D
    WorkSetConst 0x8008, 99
    WorkSetConst 0x8009, 1
    RTCallGlobal 10466
    ActorMsg 1024, 5, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0202

L_015D:
    VMStackPush 0x4002
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0196
    WorkSetConst 0x8008, 98
    WorkSetConst 0x8009, 1
    RTCallGlobal 10466
    ActorMsg 1024, 5, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0202

L_0196:
    VMStackPush 0x4003
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01CF
    WorkSetConst 0x8008, 95
    WorkSetConst 0x8009, 1
    RTCallGlobal 10466
    ActorMsg 1024, 5, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0202

L_01CF:
    VMStackPush 0x4004
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0202
    WorkSetConst 0x8008, 96
    WorkSetConst 0x8009, 1
    RTCallGlobal 10466
    ActorMsg 1024, 6, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0202:
    FlagSet 2730
    VMJump L_021C

L_020C:
    ActorMsg 1024, 4, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_021C:
    VMJump L_0232

L_0222:
    ActorMsg 1024, 0, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0232:
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
