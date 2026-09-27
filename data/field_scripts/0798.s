#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 515, 0
    ParentActorMsg 1024, 3, 0, 0
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
    VMStackPushFlag 433
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 434
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_01B7
    VMStackPushFlag 431
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4000
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00FA
    VMCall L_02E2
    VMJump L_01B1

L_00FA:
    VMStackPushFlag 431
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4000
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0131
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01B1

L_0131:
    ParentActorMsg 1024, 8, 0, 0
    ParentActorMsg 1024, 9, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01A3
    ParentActorMsg 1024, 10, 0, 0
    MsgWinCloseAll
    CallTradedPokemonBattle 699, 0, 0, 2
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0191
    CallTrainerBattleEnd
    VMJump L_0193

L_0191:
    CallTrainerLose

L_0193:
    FlagSet 433
    VMCall L_03AB
    VMJump L_01B1

L_01A3:
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01B1:
    VMJump L_02DC

L_01B7:
    VMStackPushFlag 433
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 434
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_02CE
    VMStackPushFlag 432
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4000
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0209
    VMCall L_03AB
    VMJump L_02C8

L_0209:
    VMStackPushFlag 432
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4000
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0240
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02C8

L_0240:
    ParentActorMsg 1024, 16, 0, 0
    ParentActorMsg 1024, 17, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02BA
    ParentActorMsg 1024, 18, 0, 0
    MsgWinCloseAll
    CallTradedPokemonBattle 700, 0, 0, 3
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02A0
    CallTrainerBattleEnd
    VMJump L_02A2

L_02A0:
    CallTrainerLose

L_02A2:
    FlagSet 434
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02C8

L_02BA:
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02C8:
    VMJump L_02DC

L_02CE:
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02DC:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_02E2:
    ParentActorMsg 1024, 4, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_039B
    MsgWinCloseAll
    CallPokeSelect 0, 0x8021, 0x8020, 0
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0387
    FieldTradeCheck 0x8022, 29, 0x8020
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0373
    ParentActorMsg 1024, 5, 0, 0
    MsgWinCloseAll
    FieldTradeSavePokemon 0x8020, 2
    FieldTradeStart 29, 0x8020
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 431
    WorkSetConst 0x4000, 1
    VMJump L_0381

L_0373:
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0381:
    VMJump L_0395

L_0387:
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0395:
    VMJump L_03A9

L_039B:
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_03A9:
    VMReturn

L_03AB:
    ParentActorMsg 1024, 12, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0464
    MsgWinCloseAll
    CallPokeSelect 0, 0x8021, 0x8020, 0
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0450
    FieldTradeCheck 0x8022, 30, 0x8020
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_043C
    ParentActorMsg 1024, 13, 0, 0
    MsgWinCloseAll
    FieldTradeSavePokemon 0x8020, 3
    FieldTradeStart 30, 0x8020
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 432
    WorkSetConst 0x4000, 1
    VMJump L_044A

L_043C:
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_044A:
    VMJump L_045E

L_0450:
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_045E:
    VMJump L_0472

L_0464:
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0472:
    VMReturn
