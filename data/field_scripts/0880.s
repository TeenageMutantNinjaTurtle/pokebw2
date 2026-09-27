#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_1:
    VMHalt

Script_2:
    VMStackPush 0x40a6
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0057
    ActorSetGPos 2, 6, 0, 11, 0

L_0057:
    VMHalt

Script_3:
    ActorsPauseAll
    ActorCmdExec 2, Movement_02DC
    ActorCmdExec 255, Movement_02EC
    ActorCmdWait
    ActorCmdExec 1, Movement_02F4
    ActorCmdExec 0, Movement_02F4
    ActorCmdWait
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 1, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 2, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0C9C
    ActorCmdExec 255, Movement_0CA4
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 3, 2, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 1, 6, 9, 1, 8, 0
    ActorCmdExec 2, Movement_0C8C
    ActorCmdExec 255, Movement_0C8C
    ActorCmdWait
    ActorMsg 1024, 4, 1, 0, 0
    MsgWinCloseAll
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_011B
    CallTrainerBattle 169, 0, 0
    VMJump L_0144

L_011B:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_013C
    CallTrainerBattle 747, 0, 0
    VMJump L_0144

L_013C:
    CallTrainerBattle 749, 0, 0

L_0144:
    VMCall L_02B6
    ActorCmdExec 1, Movement_0300
    ActorMsg 1024, 5, 2, 0, 0
    MsgWinCloseAll
    ActorCmdWait
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll
    WordSetPlayerName 0
    ActorMsg 1024, 7, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0C9C
    ActorCmdExec 255, Movement_0CA4
    ActorCmdWait
    SEPlay 1391
    SEWait
    PokePartyRecoverAll
    ActorCmdExec 2, Movement_0C8C
    ActorCmdExec 255, Movement_0C8C
    ActorWalkRoute 0, 6, 9, 1, 8, 0
    ActorCmdWait
    ActorMsg 1024, 8, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01EA
    CallTrainerBattle 170, 0, 0
    VMJump L_0213

L_01EA:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_020B
    CallTrainerBattle 748, 0, 0
    VMJump L_0213

L_020B:
    CallTrainerBattle 750, 0, 0

L_0213:
    VMCall L_02B6
    ActorMsg 1024, 9, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0C9C
    ActorCmdExec 255, Movement_0CA4
    ActorCmdExec 0, Movement_0310
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 10, 2, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 11, 0, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x8024, 0
    PokePartyGetMemberByType 0x8024, 2
    WordSetPartyPokeSpecies 1, 0x8024
    WordSetPlayerName 0
    ActorMsg 1024, 12, 2, 0, 0
    MsgWinCloseAll
    SEPlay 1391
    SEWait
    PokePartyRecoverAll
    ActorMsg 1024, 13, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40a6, 1
    WorkSetConst 0x40a5, 5
    FlagReset 730
    WorkSetConst 0x40a3, 3
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_02B6:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02D5
    CallTrainerBattleEnd
    VMJump L_02D7

L_02D5:
    CallTrainerLose

L_02D7:
    VMReturn
    .balign 4, 0

Movement_02DC:
    Move 12, 1
    Move 15, 1
    Move 32, 1
    MoveEnd

Movement_02EC:
    Move 12, 2
    MoveEnd

Movement_02F4:
    Move 33, 1
    Move 75, 1
    MoveEnd

Movement_0300:
    Move 15, 1
    Move 12, 1
    Move 33, 1
    MoveEnd

Movement_0310:
    Move 14, 1
    Move 12, 1
    Move 33, 1
    MoveEnd

Script_4:
    ActorsPauseAll
    Cmd_02D1 0x8023
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03C8
    VMStackPushFlag 428
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0358
    VMCall L_0452
    VMJump L_03C2

L_0358:
    VMStackPushFlag 428
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0399
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 35, 34, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_03C2

L_0399:
    VMStackPush 0x8023
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_03C2
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 36, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_03C2:
    VMJump L_044C

L_03C8:
    TrainerCardHasBadge 0x8008, 0
    WorkSetConst 0x8025, 0
    TrainerCardGetBadgeCount 0x8025
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0405
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0446

L_0405:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 2
    VMJumpIf 255, L_0432
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0446

L_0432:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose

L_0446:
    WorkSetConst 0x8025, 0

L_044C:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0452:
    SEPlay 1351
    ActorSetEyeToEye
    Cmd_02D5 19, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0483
    ActorMsg 1024, 17, 2, 0, 0
    VMJump L_048F

L_0483:
    ActorMsg 1024, 16, 2, 0, 0

L_048F:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0A60
    MsgWinCloseAll
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_04C9
    ActorCmdExec 2, Movement_0C94
    ActorCmdWait

L_04C9:
    ActorCmdExec 2, Movement_0C64
    ActorCmdWait
    VMSleep 8
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_04FA
    ActorCmdExec 2, Movement_0C8C
    ActorCmdWait
    VMJump L_053A

L_04FA:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_051D
    ActorCmdExec 2, Movement_0CA4
    ActorCmdWait
    VMJump L_053A

L_051D:
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_053A
    ActorCmdExec 2, Movement_0C9C
    ActorCmdWait

L_053A:
    ActorMsg 1024, 18, 2, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 582, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_056F
    CallTrainerBattleEnd
    VMJump L_0571

L_056F:
    CallTrainerLose

L_0571:
    ActorMsg 1024, 20, 2, 0, 0
    MsgWinCloseAll
    VMSleep 16
    SEPlay 1369
    ActorNew 6, 12, 0, 251, 304, 0
    SEWait
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_05B6
    ActorCmdExec 2, Movement_0C94

L_05B6:
    ActorWalkRoute 251, 6, 6, 1, 4, 1
    ActorCmdWait
    WorkSetConst 0x8026, 0
    PlayerGetDir 0x8020
    GameGetVersion 0x8026
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 5
    VMStackPush 0x8026
    VMStackPushConst 23
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0602
    InfoMsg 21, 2
    VMJump L_063E

L_0602:
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 5
    VMStackPush 0x8026
    VMStackPushConst 22
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0630
    InfoMsg 22, 2
    VMJump L_063E

L_0630:
    ActorMsgVersioned 1024, 22, 21, 251, 4, 0

L_063E:
    MsgWinCloseAll
    WorkSetConst 0x8026, 0
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 6
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 2
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0685
    ActorWalkRoute 255, 5, 3, 1, 8, 0
    ActorCmdWait
    VMJump L_068D

L_0685:
    ActorCmdExec 255, Movement_0C94

L_068D:
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_06CA
    ActorMsg 1024, 23, 2, 5, 0
    VMJump L_06D6

L_06CA:
    ActorMsg 1024, 23, 2, 3, 0

L_06D6:
    MsgWinCloseAll
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_06F6
    InfoMsg 24, 2
    VMJump L_0702

L_06F6:
    ActorMsg 1024, 24, 251, 4, 0

L_0702:
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 6
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0741
    ActorWalkRoute 251, 6, 5, 1, 8, 1
    VMJump L_07BD

L_0741:
    VMStackPush 0x8021
    VMStackPushConst 7
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0782
    ActorWalkRoute 251, 7, 5, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 251, Movement_0C8C
    VMJump L_07BD

L_0782:
    VMStackPush 0x8021
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_07BD
    ActorWalkRoute 251, 5, 5, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 251, Movement_0C8C

L_07BD:
    ActorCmdWait
    ActorCmdExec 251, Movement_0CB4
    ActorCmdWait
    ActorMsg 1024, 25, 251, 4, 0
    MsgWinCloseAll
    WordSetPlayerName 0
    WorkSetConst 0x8027, 0
    TrainerCardGetSex 0x8027
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_083E
    VMStackPush 0x8021
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_082C
    ActorMsg 1024, 26, 2, 5, 0
    VMJump L_0838

L_082C:
    ActorMsg 1024, 26, 2, 3, 0

L_0838:
    VMJump L_087F

L_083E:
    VMStackPush 0x8021
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0873
    ActorMsg 1024, 27, 2, 5, 0
    VMJump L_087F

L_0873:
    ActorMsg 1024, 27, 2, 3, 0

L_087F:
    MsgWinCloseAll
    ActorMsg 1024, 28, 251, 4, 0
    MsgWinCloseAll
    VMStackPush 0x8021
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_08C4
    ActorMsg 1024, 29, 2, 5, 0
    VMJump L_08D0

L_08C4:
    ActorMsg 1024, 29, 2, 3, 0

L_08D0:
    MsgWinCloseAll
    ActorMsg 1024, 30, 251, 4, 0
    ActorMsgVersioned 1024, 32, 31, 251, 4, 0
    WordSetPlayerName 0
    ActorMsg 1024, 33, 251, 4, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 6
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_093A
    ActorWalkRoute 251, 6, 12, 1, 4, 1
    VMJump L_0958

L_093A:
    ActorWalkRoute 251, 6, 6, 1, 4, 1
    ActorCmdWait
    ActorWalkRoute 251, 6, 12, 1, 4, 1

L_0958:
    ActorCmdWait
    SEPlay 1369
    ActorDelete 251
    SEWait
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 6
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_099B
    ActorCmdExec 255, Movement_0C8C
    VMJump L_0A07

L_099B:
    VMStackPush 0x8021
    VMStackPushConst 7
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_09D4
    ActorCmdExec 2, Movement_0CA4
    ActorCmdExec 255, Movement_0C9C
    VMJump L_0A07

L_09D4:
    VMStackPush 0x8021
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0A07
    ActorCmdExec 2, Movement_0C9C
    ActorCmdExec 255, Movement_0CA4

L_0A07:
    ActorCmdWait
    VMStackPush 0x8021
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0A40
    ActorMsgVersioned 1024, 35, 34, 2, 5, 0
    VMJump L_0A4E

L_0A40:
    ActorMsgVersioned 1024, 35, 34, 2, 3, 0

L_0A4E:
    LastKeyWait
    MsgWinCloseAll
    FlagSet 428
    FlagSet 750
    VMJump L_0A70

L_0A60:
    ActorMsg 1024, 19, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0A70:
    VMReturn

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WordSetPlayerName 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    ActorMsgVersioned 1024, 40, 39, 3, 0, 0
    MsgWinCloseAll
    GameGetVersion 0x8028
    VMStackPush 0x8028
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0ACF
    PokePartyAddEx 0x8029, 443, 0, 1, 0, 0, 1, 216, 4
    WordSetPokeSpecies 1, 443
    VMJump L_0AE8

L_0ACF:
    PokePartyAddEx 0x8029, 147, 0, 1, 0, 0, 1, 216, 4
    WordSetPokeSpecies 1, 147

L_0AE8:
    VMStackPush 0x8029
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0BCB
    WordSetPlayerName 0
    MEPlay 1304
    SystemMsg 41, 0
    MEWait
    MsgWaitAdvance
    InfoMsgClose
    SystemMsg 42, 0
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0
    YesNoWin 0x802a
    InfoMsgClose
    VMStackPush 0x802a
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0B59
    WorkSetConst 0x802c, 0
    PokePartyGetCount 0x802c, 0
    WorkSetConst 0x802d, 0
    WorkSub 0x802c, 1
    CallPokeNameInput 0x802b, 0x802c, 1

L_0B59:
    ActorMsgVersioned 1024, 45, 44, 3, 0, 0
    MsgWinCloseAll
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0B8E
    ActorCmdExec 3, Movement_0C08
    VMJump L_0B96

L_0B8E:
    ActorCmdExec 3, Movement_0C1C

L_0B96:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_0BB5
    VMSleep 8
    ActorCmdExec 255, Movement_0C94

L_0BB5:
    ActorCmdWait
    SEPlay 1369
    ActorDelete 3
    SEWait
    FlagSet 996
    VMJump L_0BDB

L_0BCB:
    ActorMsg 1024, 43, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0BDB:
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802a, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x8028, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0C08:
    Move 14, 1
    Move 13, 2
    Move 14, 1
    Move 13, 7
    MoveEnd

Movement_0C1C:
    Move 13, 3
    Move 14, 2
    Move 13, 6
    MoveEnd

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 38, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 37, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0C64:
    Move 100, 1
    MoveEnd
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0
    Move 3, 1
    MoveEnd

Movement_0C8C:
    Move 32, 1
    MoveEnd

Movement_0C94:
    Move 33, 1
    MoveEnd

Movement_0C9C:
    Move 34, 1
    MoveEnd

Movement_0CA4:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd

Movement_0CB4:
    Move 159, 1
    MoveEnd
