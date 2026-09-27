#include "asm/field_script.inc"

// Script plugin 3, from the zones that use this file

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd

Script_1:
    VMStackPushFlag 2407
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0037
    WorkSetConst 0x400a, 555

L_0037:
    VMHalt

Script_2:
    VMStackPush 0x4001
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0058
    ActorSetGPos 0, 15, 12, 7, 0

L_0058:
    VMStackPushFlag 2407
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0073
    BMAnmPlayLoop 7, 18, 8

L_0073:
    VMHalt

Script_3:
    VMStackPush 0x4001
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0096
    Plugin3_Cmd1000 1
    Plugin3_Cmd1001 1
    VMJump L_00A2

L_0096:
    ActorSetGPos 0, 15, 12, 7, 0

L_00A2:
    VMStackPushFlag 2407
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00BD
    BMAnmPlayLoop 7, 18, 8

L_00BD:
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0237
    VMStackPushFlag 2407
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01CC
    ActorMsgVersioned 1024, 1, 0, 0, 1, 0
    MsgWinCloseAll
    FlagSet 2407
    WorkSetConst 0x400a, 555
    WorkSetConst 0x8020, 0
    GameGetDifficulty 0x8020
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0132
    CallTrainerBattle 772, 0, 0
    VMJump L_013A

L_0132:
    CallTrainerBattle 38, 0, 0

L_013A:
    WorkSetConst 0x8020, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_015F
    CallTrainerBattleEnd
    VMJump L_0161

L_015F:
    CallTrainerLose

L_0161:
    VMStackPushFlag 2407
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2408
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2409
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2410
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_01B6
    ActorMsg 1024, 4, 0, 1, 0
    VMJump L_01C2

L_01B6:
    ActorMsg 1024, 2, 0, 1, 0

L_01C2:
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0231

L_01CC:
    VMStackPushFlag 2407
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2408
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2409
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2410
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0221
    ActorMsg 1024, 4, 0, 1, 0
    VMJump L_022D

L_0221:
    ActorMsg 1024, 3, 0, 1, 0

L_022D:
    LastKeyWait
    MsgWinCloseAll

L_0231:
    VMJump L_0426

L_0237:
    VMStackPushFlag 2407
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03C1
    Random 0x8010, 5
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0263
    VMJump L_0275

L_0263:
    ActorMsg 1024, 5, 0, 1, 0
    VMJump L_02F0

L_0275:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0288
    VMJump L_029A

L_0288:
    ActorMsg 1024, 6, 0, 1, 0
    VMJump L_02F0

L_029A:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_02AD
    VMJump L_02BF

L_02AD:
    ActorMsg 1024, 7, 0, 1, 0
    VMJump L_02F0

L_02BF:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_02D2
    VMJump L_02E4

L_02D2:
    ActorMsg 1024, 8, 0, 1, 0
    VMJump L_02F0

L_02E4:
    ActorMsg 1024, 9, 0, 1, 0

L_02F0:
    MsgWinCloseAll
    FlagSet 2407
    WorkSetConst 0x400a, 555
    WorkSetConst 0x8021, 0
    GameGetDifficulty 0x8021
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0327
    CallTrainerBattle 777, 0, 0
    VMJump L_032F

L_0327:
    CallTrainerBattle 143, 0, 0

L_032F:
    WorkSetConst 0x8021, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0354
    CallTrainerBattleEnd
    VMJump L_0356

L_0354:
    CallTrainerLose

L_0356:
    VMStackPushFlag 2407
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2408
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2409
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2410
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_03AB
    ActorMsg 1024, 12, 0, 1, 0
    VMJump L_03B7

L_03AB:
    ActorMsg 1024, 10, 0, 1, 0

L_03B7:
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0426

L_03C1:
    VMStackPushFlag 2407
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2408
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2409
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2410
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0416
    ActorMsg 1024, 12, 0, 1, 0
    VMJump L_0422

L_0416:
    ActorMsg 1024, 11, 0, 1, 0

L_0422:
    LastKeyWait
    MsgWinCloseAll

L_0426:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    Plugin3_Cmd1009
    VMSleep 31
    Plugin3_Cmd1010 0
    VMSleep 35
    Plugin3_Cmd1010 1
    VMSleep 7
    Plugin3_Cmd1010 2
    VMSleep 7
    Plugin3_Cmd1010 3
    VMSleep 7
    Plugin3_Cmd1010 4
    WorkSetConst 0x4000, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    Plugin3_Cmd1000 1
    Plugin3_Cmd1001 1
    Plugin3_Cmd1011 37
    Plugin3_Cmd1012
    WorkSetConst 0x4001, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    MapChangeWarpPad 137, 31, 48, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
