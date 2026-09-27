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
    VMStackPushFlag 2410
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0037
    WorkSetConst 0x400a, 555

L_0037:
    VMHalt

Script_2:
    Plugin3_Cmd1004
    VMStackPush 0x4001
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_005A
    ActorSetGPos 0, 15, 15, 7, 1

L_005A:
    VMStackPushFlag 2410
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0075
    BMAnmPlayLoop 7, 18, 5

L_0075:
    VMHalt

Script_3:
    Plugin3_Cmd1004
    VMStackPush 0x4001
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_009A
    Plugin3_Cmd1000 4
    Plugin3_Cmd1001 4
    VMJump L_00A6

L_009A:
    ActorSetGPos 0, 15, 15, 7, 1

L_00A6:
    VMStackPushFlag 2410
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00C1
    BMAnmPlayLoop 7, 18, 5

L_00C1:
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0239
    VMStackPushFlag 2410
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01CE
    ActorMsg 1024, 0, 0, 1, 0
    MsgWinCloseAll
    FlagSet 2410
    WorkSetConst 0x400a, 555
    WorkSetConst 0x8020, 0
    GameGetDifficulty 0x8020
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0134
    CallTrainerBattle 775, 0, 0
    VMJump L_013C

L_0134:
    CallTrainerBattle 41, 0, 0

L_013C:
    WorkSetConst 0x8020, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0161
    CallTrainerBattleEnd
    VMJump L_0163

L_0161:
    CallTrainerLose

L_0163:
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
    VMJumpIf 255, L_01B8
    ActorMsg 1024, 3, 0, 1, 0
    VMJump L_01C4

L_01B8:
    ActorMsg 1024, 1, 0, 1, 0

L_01C4:
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0233

L_01CE:
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
    VMJumpIf 255, L_0223
    ActorMsg 1024, 3, 0, 1, 0
    VMJump L_022F

L_0223:
    ActorMsg 1024, 2, 0, 1, 0

L_022F:
    LastKeyWait
    MsgWinCloseAll

L_0233:
    VMJump L_038E

L_0239:
    VMStackPushFlag 2410
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0329
    ActorMsg 1024, 4, 0, 1, 0
    MsgWinCloseAll
    FlagSet 2410
    WorkSetConst 0x400a, 555
    WorkSetConst 0x8021, 0
    GameGetDifficulty 0x8021
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_028F
    CallTrainerBattle 780, 0, 0
    VMJump L_0297

L_028F:
    CallTrainerBattle 146, 0, 0

L_0297:
    WorkSetConst 0x8021, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02BC
    CallTrainerBattleEnd
    VMJump L_02BE

L_02BC:
    CallTrainerLose

L_02BE:
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
    VMJumpIf 255, L_0313
    ActorMsg 1024, 7, 0, 1, 0
    VMJump L_031F

L_0313:
    ActorMsg 1024, 5, 0, 1, 0

L_031F:
    LastKeyWait
    MsgWinCloseAll
    VMJump L_038E

L_0329:
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
    VMJumpIf 255, L_037E
    ActorMsg 1024, 7, 0, 1, 0
    VMJump L_038A

L_037E:
    ActorMsg 1024, 6, 0, 1, 0

L_038A:
    LastKeyWait
    MsgWinCloseAll

L_038E:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    VMSleep 10
    Plugin3_Cmd1005 0
    SEPlay 2189
    VMSleep 40
    WorkSetConst 0x4000, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    Plugin3_Cmd1000 4
    Plugin3_Cmd1001 4
    VMSleep 5
    Plugin3_Cmd1005 1
    VMSleep 40
    Plugin3_Cmd1006
    SEPlay 2190
    VMSleep 30
    Plugin3_Cmd1007
    VMSleep 30
    Plugin3_Cmd1008 0, 15
    VMSleep 60
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
