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
    VMStackPushFlag 2409
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
    ActorSetGPos 0, 15, 22, 7, 1

L_0058:
    VMStackPushFlag 2409
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0073
    BMAnmPlayLoop 7, 17, 9

L_0073:
    VMHalt

Script_3:
    VMStackPush 0x4001
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0096
    Plugin3_Cmd1000 3
    Plugin3_Cmd1001 3
    VMJump L_00A2

L_0096:
    ActorSetGPos 0, 15, 22, 7, 1

L_00A2:
    VMStackPushFlag 2409
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00BD
    BMAnmPlayLoop 7, 17, 9

L_00BD:
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_025C
    VMStackPushFlag 2409
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01F1
    VMStackPushFlag 489
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0114
    ActorMsg 1024, 0, 0, 1, 0
    MsgWinCloseAll
    VMJump L_0122

L_0114:
    ActorMsg 1024, 1, 0, 1, 0
    MsgWinCloseAll

L_0122:
    FlagSet 2409
    WorkSetConst 0x400a, 555
    WorkSetConst 0x8020, 0
    GameGetDifficulty 0x8020
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0157
    CallTrainerBattle 774, 0, 0
    VMJump L_015F

L_0157:
    CallTrainerBattle 39, 0, 0

L_015F:
    WorkSetConst 0x8020, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0184
    CallTrainerBattleEnd
    VMJump L_0186

L_0184:
    CallTrainerLose

L_0186:
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
    VMJumpIf 255, L_01DB
    ActorMsg 1024, 4, 0, 1, 0
    VMJump L_01E7

L_01DB:
    ActorMsg 1024, 2, 0, 1, 0

L_01E7:
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0256

L_01F1:
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
    VMJumpIf 255, L_0246
    ActorMsg 1024, 4, 0, 1, 0
    VMJump L_0252

L_0246:
    ActorMsg 1024, 3, 0, 1, 0

L_0252:
    LastKeyWait
    MsgWinCloseAll

L_0256:
    VMJump L_03B1

L_025C:
    VMStackPushFlag 2409
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_034C
    ActorMsg 1024, 5, 0, 1, 0
    MsgWinCloseAll
    FlagSet 2409
    WorkSetConst 0x400a, 555
    WorkSetConst 0x8021, 0
    GameGetDifficulty 0x8021
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_02B2
    CallTrainerBattle 779, 0, 0
    VMJump L_02BA

L_02B2:
    CallTrainerBattle 144, 0, 0

L_02BA:
    WorkSetConst 0x8021, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02DF
    CallTrainerBattleEnd
    VMJump L_02E1

L_02DF:
    CallTrainerLose

L_02E1:
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
    VMJumpIf 255, L_0336
    ActorMsg 1024, 8, 0, 1, 0
    VMJump L_0342

L_0336:
    ActorMsg 1024, 6, 0, 1, 0

L_0342:
    LastKeyWait
    MsgWinCloseAll
    VMJump L_03B1

L_034C:
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
    VMJumpIf 255, L_03A1
    ActorMsg 1024, 8, 0, 1, 0
    VMJump L_03AD

L_03A1:
    ActorMsg 1024, 7, 0, 1, 0

L_03AD:
    LastKeyWait
    MsgWinCloseAll

L_03B1:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    VMSleep 5
    Plugin3_Cmd1013
    SEPlay 2198
    VMSleep 60
    Plugin3_Cmd1014 0
    SEPlay 2199
    VMSleep 20
    WorkSetConst 0x4000, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    Plugin3_Cmd1000 3
    Plugin3_Cmd1001 3
    ActorCmdExec 255, Movement_043C
    ActorCmdWait
    Plugin3_Cmd1014 1
    SEPlay 2200
    VMSleep 30
    Plugin3_Cmd1016
    VMSleep 30
    ActorCmdExec 0, Movement_0444
    ActorCmdWait
    VMSleep 10
    Plugin3_Cmd1015
    SEPlay 2202
    VMSleep 5
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

Movement_043C:
    Move 75, 1
    MoveEnd

Movement_0444:
    Move 100, 1
    MoveEnd
