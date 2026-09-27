#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd

Script_4:
    ActorsPauseAll
    VMStackPushFlag 474
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_009D
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    ActorMsgClose
    CallPokemonPreview 643, 0, 0, 0
    PokeDexRegist 0, 643
    SystemMsg 8, 0
    MsgWaitAdvance
    InfoMsgClose
    ParentActorMsg 1024, 9, 0, 0
    ActorMsgClose
    CallPokemonPreview 644, 0, 0, 0
    PokeDexRegist 0, 644
    SystemMsg 10, 0
    MsgWaitAdvance
    InfoMsgClose
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 474
    VMJump L_00B1

L_009D:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose

L_00B1:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00E6
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_00FA

L_00E6:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose

L_00FA:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 2222
    SEWait
    InfoMsg 12, 2
    LastKeyWait
    InfoMsgClose_0039
    WorkSetConst 0x4149, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
