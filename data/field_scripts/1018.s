#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    SEPlay 1351
    PokePartyGetCountBySpecies 378, 0x8020
    PokePartyGetCountBySpecies 377, 0x8021
    PokePartyGetCountBySpecies 379, 0x8022
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 6
    VMStackCmp 6
    VMJumpIf 255, L_007F
    SystemMsg 0, 2
    LastKeyWait
    InfoMsgClose
    VMJump L_0085

L_007F:
    VMCall L_008B

L_0085:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_008B:
    SystemMsg 1, 2
    MsgWaitAdvance
    InfoMsgClose
    PVPlay 486, 0
    ScreamMsg 2, 2
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    CallWildBattle 486, 68, 1
    WildBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00D5
    FlagSet 924
    ActorDelete 3
    CallWildBattleEnd
    VMJump L_00D7

L_00D5:
    CallWildLose

L_00D7:
    WildBattleGetResult 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_00EE
    VMJump L_00F8

L_00EE:
    FlagSet 402
    VMJump L_0128

L_00F8:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0118
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0118
    VMJump L_0128

L_0118:
    SystemMsg 3, 2
    LastKeyWait
    InfoMsgClose
    VMJump L_0128

L_0128:
    VMReturn

Script_2:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    InfoMsg 4, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    InfoMsg 5, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    InfoMsg 6, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
