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
    ScriptEntry Script_11
    ScriptEntry Script_12
    ScriptEntry Script_13
    ScriptEntry Script_14
    ScriptEntry Script_15
    ScriptEntry Script_16
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

L_0048:
    SystemMsg 33, 2
    LastKeyWait
    InfoMsgClose
    VMReturn

Movement_0054:
    Move 162, 1
    MoveEnd

L_005C:
    PlayerSetSpecialSequence 128
    ActorCmdExec 255, Movement_0054
    ActorCmdWait
    VMReturn

L_006C:
    PlayerSetSpecialSequence 8
    VMReturn

Script_1:
    ActorsPauseAll
    SEPlay 1351
    FlagGet 2404, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_009D
    VMCall L_00ED
    VMJump L_00E7

L_009D:
    PokePartyHasMoveAny 0x8010, 70
    VMStackPush 0x8010
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_00C2
    VMCall L_00F9
    VMJump L_00E7

L_00C2:
    SystemMsg 6, 2
    YesNoWin 0x8010
    InfoMsgClose
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00E7
    VMCall L_0105

L_00E7:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_00ED:
    SystemMsg 9, 2
    LastKeyWait
    InfoMsgClose
    VMReturn

L_00F9:
    SystemMsg 8, 2
    LastKeyWait
    InfoMsgClose
    VMReturn

L_0105:
    WorkSetConst 0x8021, 0
    FlagSet 2404
    Cmd_01DD 1, 70, 0
    PokePartyHasMoveAny 0x8021, 70
    WordSetPartyPokeName 0, 0x8021
    SystemMsg 10, 2
    InfoMsgClose
    VMCall L_005C
    PlayHMCutInEffect 0x8021
    VMCall L_006C
    SystemMsg 11, 2
    LastKeyWait
    InfoMsgClose
    WorkSetConst 0x8021, 0
    VMReturn

Script_2:
    ActorsPauseAll
    FlagGet 2404, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0173
    VMCall L_00ED
    VMJump L_01A6

L_0173:
    FlagSet 2404
    Cmd_01DD 1, 70, 0
    WordSetPartyPokeName 0, 0x8000
    SystemMsg 10, 2
    InfoMsgClose
    VMCall L_005C
    PlayHMCutInEffect 0x8000
    VMCall L_006C
    SystemMsg 11, 2
    LastKeyWait
    InfoMsgClose

L_01A6:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    PokePartyHasMoveAny 0x8010, 57
    VMStackPush 0x8010
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_01D7
    VMCall L_0226
    VMJump L_0220

L_01D7:
    VMStackPushFlag 2406
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01FB
    WordSetMoveName 0, 57
    VMCall L_0048
    VMJump L_0220

L_01FB:
    SystemMsg 13, 2
    YesNoWin 0x8010
    InfoMsgClose
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0220
    VMCall L_0232

L_0220:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0226:
    SystemMsg 15, 2
    LastKeyWait
    InfoMsgClose
    VMReturn

L_0232:
    PokePartyHasMoveAny 0x8010, 57
    WorkGet 0x8008, 0x8010
    WordSetPartyPokeName 0, 0x8010
    SystemMsg 14, 2
    InfoMsgClose
    VMCall L_005C
    PlayHMCutInEffect 0x8008
    PlayerSetSpecialSequence 1
    CallSurf
    Cmd_01DD 1, 57, 0
    VMReturn

Script_4:
    ActorsPauseAll
    WordSetPartyPokeName 0, 0x8000
    SystemMsg 14, 2
    InfoMsgClose
    VMCall L_005C
    PlayHMCutInEffect 0x8000
    VMCall L_006C
    CallSurf
    Cmd_01DD 1, 57, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    PokePartyHasMoveAny 0x8010, 15
    VMStackPush 0x8010
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_02BF
    VMCall L_02F0
    VMJump L_02EA

L_02BF:
    SystemMsg 0, 2
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02E8
    VMCall L_02FC
    VMJump L_02EA

L_02E8:
    InfoMsgClose

L_02EA:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_02F0:
    SystemMsg 2, 2
    LastKeyWait
    InfoMsgClose
    VMReturn

L_02FC:
    PokePartyHasMoveAny 0x8010, 15
    WorkGet 0x8008, 0x8010
    WordSetPartyPokeName 0, 0x8010
    SystemMsg 1, 2
    InfoMsgClose
    VMCall L_005C
    PlayHMCutInEffect 0x8008
    VMCall L_006C
    CallCut
    Cmd_01DD 1, 15, 0
    VMSleep 3
    ActorDelete 0x8011
    SEPlay 1651
    VMSleep 1
    VMReturn

Script_6:
    ActorsPauseAll
    SEPlay 1351
    WordSetPartyPokeName 0, 0x8000
    SystemMsg 1, 2
    InfoMsgClose
    VMCall L_005C
    PlayHMCutInEffect 0x8000
    VMCall L_006C
    CallCut
    Cmd_01DD 1, 15, 0
    VMSleep 3
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    PlayerGetActorInFront 0x8022, 0x8023
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_039B
    ActorDelete 0x8022

L_039B:
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    SEPlay 1651
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    PokePartyHasMoveAny 0x8010, 127
    VMStackPush 0x8010
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_03DC
    VMCall L_042B
    VMJump L_0425

L_03DC:
    VMStackPushFlag 2406
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0400
    WordSetMoveName 0, 127
    VMCall L_0048
    VMJump L_0425

L_0400:
    SystemMsg 23, 2
    YesNoWin 0x8010
    InfoMsgClose
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0425
    VMCall L_0437

L_0425:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_042B:
    SystemMsg 25, 2
    LastKeyWait
    InfoMsgClose
    VMReturn

L_0437:
    WorkSetConst 0x8024, 0
    PokePartyHasMoveAny 0x8024, 127
    WordSetPartyPokeName 0, 0x8024
    SystemMsg 24, 2
    InfoMsgClose
    VMCall L_005C
    PlayHMCutInEffect 0x8024
    VMCall L_006C
    CallWaterfall 0x8024
    Cmd_01DD 1, 127, 0
    WorkSetConst 0x8024, 0
    VMReturn

Script_8:
    ActorsPauseAll
    WordSetPartyPokeName 0, 0x8000
    SystemMsg 24, 2
    InfoMsgClose
    PlayHMCutInEffect 0x8000
    CallWaterfall 0x8000
    Cmd_01DD 1, 127, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    CallWaterfall 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    WordSetPartyPokeName 0, 0x8000
    SystemMsg 27, 2
    InfoMsgClose
    VMCall L_005C
    PlayHMCutInEffect 0x8000
    VMCall L_006C
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    WordSetPartyPokeName 0, 0x8000
    SystemMsg 28, 2
    InfoMsgClose
    VMCall L_005C
    PlayHMCutInEffect 0x8000
    VMCall L_006C
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    WordSetPartyPokeName 0, 0x8000
    SystemMsg 29, 2
    InfoMsgClose
    VMCall L_005C
    PlayHMCutInEffect 0x8000
    VMCall L_006C
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    PokePartyHasMoveAny 0x8010, 291
    VMStackPush 0x8010
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_053F
    SystemMsg 30, 2
    LastKeyWait
    InfoMsgClose
    VMJump L_0599

L_053F:
    VMStackPushFlag 2406
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0563
    WordSetMoveName 0, 291
    VMCall L_0048
    VMJump L_0599

L_0563:
    SystemMsg 31, 2
    YesNoWin 0x8010
    InfoMsgClose
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0599
    PokePartyHasMoveAny 0x8010, 291
    WorkGet 0x8008, 0x8010
    WordSetPartyPokeName 0, 0x8010
    VMCall L_059F

L_0599:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_059F:
    SystemMsg 32, 2
    InfoMsgClose
    VMCall L_005C
    PlayHMCutInEffect 0x8008
    VMCall L_006C
    CallDiving 0
    Cmd_01DD 1, 291, 0
    VMReturn

Script_13:
    ActorsPauseAll
    WordSetPartyPokeName 0, 0x8000
    WorkGet 0x8008, 0x8000
    VMCall L_059F
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    FlagGet 215, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0616
    WordSetPartyPokeName 0, 0x8000
    SystemMsg 27, 2
    InfoMsgClose
    VMCall L_005C
    PlayHMCutInEffect 0x8000
    VMCall L_006C

L_0616:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    FlagGet 214, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0654
    WordSetPartyPokeName 0, 0x8000
    SystemMsg 10, 2
    InfoMsgClose
    VMCall L_005C
    PlayHMCutInEffect 0x8000
    VMCall L_006C

L_0654:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
