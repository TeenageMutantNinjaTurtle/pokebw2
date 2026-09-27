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
    VMStackPushFlag 2408
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0037
    WorkSetConst 0x400a, 555

L_0037:
    VMHalt

Script_2:
    VMStackPushFlag 2408
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0054
    BMAnmPlayLoop 7, 19, 7

L_0054:
    VMHalt

Script_3:
    VMStackPush 0x4001
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0071
    Plugin3_Cmd1000 2
    Plugin3_Cmd1001 2

L_0071:
    VMStackPushFlag 2408
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_008C
    BMAnmPlayLoop 7, 19, 7

L_008C:
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0204
    VMStackPushFlag 2408
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0199
    ActorMsg 1024, 0, 0, 1, 0
    MsgWinCloseAll
    FlagSet 2408
    WorkSetConst 0x400a, 555
    WorkSetConst 0x8020, 0
    GameGetDifficulty 0x8020
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_00FF
    CallTrainerBattle 773, 0, 0
    VMJump L_0107

L_00FF:
    CallTrainerBattle 40, 0, 0

L_0107:
    WorkSetConst 0x8020, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_012C
    CallTrainerBattleEnd
    VMJump L_012E

L_012C:
    CallTrainerLose

L_012E:
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
    VMJumpIf 255, L_0183
    ActorMsg 1024, 3, 0, 1, 0
    VMJump L_018F

L_0183:
    ActorMsg 1024, 1, 0, 1, 0

L_018F:
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01FE

L_0199:
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
    VMJumpIf 255, L_01EE
    ActorMsg 1024, 3, 0, 1, 0
    VMJump L_01FA

L_01EE:
    ActorMsg 1024, 2, 0, 1, 0

L_01FA:
    LastKeyWait
    MsgWinCloseAll

L_01FE:
    VMJump L_0359

L_0204:
    VMStackPushFlag 2408
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02F4
    ActorMsg 1024, 4, 0, 1, 0
    MsgWinCloseAll
    FlagSet 2408
    WorkSetConst 0x400a, 555
    WorkSetConst 0x8021, 0
    GameGetDifficulty 0x8021
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_025A
    CallTrainerBattle 778, 0, 0
    VMJump L_0262

L_025A:
    CallTrainerBattle 145, 0, 0

L_0262:
    WorkSetConst 0x8021, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0287
    CallTrainerBattleEnd
    VMJump L_0289

L_0287:
    CallTrainerLose

L_0289:
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
    VMJumpIf 255, L_02DE
    ActorMsg 1024, 7, 0, 1, 0
    VMJump L_02EA

L_02DE:
    ActorMsg 1024, 5, 0, 1, 0

L_02EA:
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0359

L_02F4:
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
    VMJumpIf 255, L_0349
    ActorMsg 1024, 7, 0, 1, 0
    VMJump L_0355

L_0349:
    ActorMsg 1024, 6, 0, 1, 0

L_0355:
    LastKeyWait
    MsgWinCloseAll

L_0359:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    Plugin3_Cmd1002 0
    SEPlay 2178
    VMSleep 20
    Plugin3_Cmd1003 0
    SEPlay 2179
    VMSleep 25
    WorkSetConst 0x4000, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    Plugin3_Cmd1000 2
    Plugin3_Cmd1001 2
    VMSleep 10
    Plugin3_Cmd1003 1
    SEPlay 2180
    VMSleep 50
    Plugin3_Cmd1002 1
    SEPlay 2178
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
