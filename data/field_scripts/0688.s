#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    VMStackPushFlag 485
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0051
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 1, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 2, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_00D5

L_0051:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 3, 1, 0, 0
    ActorMsg 1024, 4, 1, 0, 0
    MsgWinCloseAll
    CallPokemonPreview 641, 0, 0, 0
    PokeDexRegist 0, 641
    ActorMsg 1024, 5, 1, 0, 0
    MsgWinCloseAll
    CallPokemonPreview 642, 0, 0, 0
    PokeDexRegist 0, 642
    SystemMsg 6, 0
    MsgWaitAdvance
    InfoMsgClose
    ActorMsg 1024, 7, 1, 0, 0
    MsgWinCloseAll
    CallPokemonPreview 645, 0, 0, 0
    PokeDexRegist 0, 645
    SystemMsg 8, 0
    MsgWaitAdvance
    InfoMsgClose
    FlagSet 485

L_00D5:
    FinishAllEvents
    ActorsUnpauseAll
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
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    PokePartyGetCount 0x8020, 0

L_013F:
    VMStackPush 0x8020
    VMStackPush 0x8021
    VMStackCmp 2
    VMJumpIf 255, L_0193
    PokePartyIsFullHP 0x8022, 0x8021
    PokePartyIsFullPP 0x8023, 0x8021
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0187
    WorkAdd 0x8024, 1

L_0187:
    WorkAdd 0x8021, 1
    VMJump L_013F

L_0193:
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 4
    VMJumpIf 255, L_01E6
    ParentActorMsg 1024, 9, 0, 0
    MsgWinCloseAll
    FadeEx 3, 0, 16, 2
    FadeExWait
    PokePartyRecoverAll
    MEPlay 1300
    MEWait
    FadeEx 3, 16, 0, 2
    FadeExWait
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01F4

L_01E6:
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01F4:
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
