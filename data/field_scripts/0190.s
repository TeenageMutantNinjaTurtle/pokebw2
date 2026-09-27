#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 213
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_005F
    ParentActorMsg 1024, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 80
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 213

L_005F:
    ActorMsgVersioned 1024, 1, 2, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    PokePartyGetMemberByType 0x8010, 2
    WordSetPartyPokeSpecies 0, 0x8010
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    PokePartyGetHappiness 0x8020, 0x8010
    VMStackPush 0x8020
    VMStackPushConst 120
    VMStackCmp 4
    VMJumpIf 255, L_00BD
    ParentActorMsg 1024, 4, 0, 0
    VMJump L_00EA

L_00BD:
    VMStackPush 0x8020
    VMStackPushConst 70
    VMStackCmp 4
    VMJumpIf 255, L_00E0
    ParentActorMsg 1024, 5, 0, 0
    VMJump L_00EA

L_00E0:
    ParentActorMsg 1024, 6, 0, 0

L_00EA:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
