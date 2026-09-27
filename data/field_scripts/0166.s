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

Script_1:
    WorkSetConst 0x8020, 0
    VMStackPush 0x416d
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x416e
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x416f
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4170
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4171
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4172
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 6
    VMStackCmp 6
    VMStackCmp 6
    VMStackCmp 6
    VMStackCmp 6
    VMJumpIf 255, L_00A5
    StadiumLoadTrainerTable
    Cmd_0249 0x416d, 0x416e, 0x416f, 0x4170, 0x4171, 0x4172
    StadiumFreeTrainerTable

L_00A5:
    FlagSet 649
    FlagSet 650
    FlagSet 651
    FlagSet 652
    FlagSet 653
    TrainerCardHasBadge 0x8020, 4
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00D6
    FlagReset 649

L_00D6:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00F9
    FlagReset 650
    FlagReset 651
    FlagReset 652
    FlagReset 653

L_00F9:
    StadiumLoadTrainerTable
    StadiumSetupActorSingle 6, 9, 1
    StadiumSetupActorSingle 7, 10, 1
    StadiumSetupActorSingle 8, 11, 1
    TrainerCardHasBadge 0x8020, 4
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_014E
    StadiumSetupActorSingle 6, 9, 2
    StadiumSetupActorSingle 7, 10, 2
    StadiumSetupActorSingle 8, 11, 2
    StadiumSetupActorsDouble 19, 12, 22, 2

L_014E:
    TrainerCardHasBadge 0x8020, 6
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0189
    StadiumSetupActorSingle 6, 9, 3
    StadiumSetupActorSingle 7, 10, 3
    StadiumSetupActorSingle 8, 11, 3
    StadiumSetupActorsDouble 19, 12, 22, 3

L_0189:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01D6
    StadiumSetupActorSingle 6, 9, 4
    StadiumSetupActorSingle 7, 10, 4
    StadiumSetupActorSingle 8, 11, 4
    StadiumSetupActorsDouble 19, 12, 22, 4
    StadiumSetupActorsDouble 20, 13, 23, 4
    StadiumSetupActorsTriple 14, 15, 16, 0x416d, 0x416e, 0x416f

L_01D6:
    StadiumFreeTrainerTable
    WorkSetConst 0x8020, 0
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 504, 0
    ParentActorMsg 1024, 7, 0, 0
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
    PVPlay 504, 0
    ParentActorMsg 1024, 8, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
