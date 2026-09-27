#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    VMStackPushFlag 474
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0085
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    ActorMsgClose
    CallPokemonPreview 643, 0, 0, 0
    PokeDexRegist 0, 643
    SystemMsg 1, 0
    MsgWaitAdvance
    InfoMsgClose
    ParentActorMsg 1024, 2, 0, 0
    ActorMsgClose
    CallPokemonPreview 644, 0, 0, 0
    PokeDexRegist 0, 644
    SystemMsg 3, 0
    MsgWaitAdvance
    InfoMsgClose
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 474
    VMJump L_0099

L_0085:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose

L_0099:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
