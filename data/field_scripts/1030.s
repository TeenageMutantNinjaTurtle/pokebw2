#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40d8
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0041
    VMCall L_00A8
    VMJump L_004F

L_0041:
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_004F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    WorkSetConst 0x4152, 1
    ActorCmdExec 12, Movement_035C
    ActorCmdWait
    WorkSetConst 0x8020, 0
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_008C
    ActorCmdExec 255, Movement_0320

L_008C:
    WorkSetConst 0x8020, 0
    ActorCmdExec 12, Movement_0314
    ActorCmdWait
    VMCall L_00A8
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_00A8:
    ActorMsg 1024, 1, 12, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0137
    ActorMsg 1024, 2, 12, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 580, 0, 0
    VMCall L_0149
    ActorMsg 1024, 4, 12, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMSleep 15
    FadeEx 3, 0, 16, 4
    FadeExWait
    ActorDelete 12
    ActorDelete 8
    ActorDelete 10
    ActorDelete 11
    FlagSet 867
    WorkSetConst 0x4152, 1
    FadeEx 3, 16, 0, 4
    FadeExWait
    VMSleep 30
    VMJump L_0147

L_0137:
    ActorMsg 1024, 3, 12, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0147:
    VMReturn

L_0149:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0168
    CallTrainerBattleEnd
    VMJump L_016A

L_0168:
    CallTrainerLose

L_016A:
    VMReturn

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 524, 0
    ParentActorMsg 1024, 6, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 524, 0
    ParentActorMsg 1024, 7, 0, 0
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
    PVPlay 524, 0
    ParentActorMsg 1024, 8, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    VMStackPushFlag 368
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01FD
    VMCall L_020D
    VMJump L_0207

L_01FD:
    SystemMsg 9, 2
    LastKeyWait
    MsgWinCloseAll

L_0207:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_020D:
    SystemMsg 10, 2
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02EE
    MsgWinCloseAll
    SEPlay 1589
    SEWait
    WorkSetConst 0x8021, 0
    PlayerGetDir 0x8021
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_025D
    ActorCmdExec 9, Movement_033C
    VMJump L_0286

L_025D:
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_027E
    ActorCmdExec 9, Movement_0344
    VMJump L_0286

L_027E:
    ActorCmdExec 9, Movement_034C

L_0286:
    ActorCmdWait
    WorkSetConst 0x8021, 0
    PVPlay 558, 0
    InfoMsg 11, 2
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll
    CallWildBattle 558, 42, 128
    WildBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02CE
    FlagSet 868
    ActorDelete 9
    CallWildBattleEnd
    VMJump L_02D0

L_02CE:
    CallWildLose

L_02D0:
    SystemMsg 12, 2
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8022, 0
    ItemSub 635, 1, 0x8022
    VMJump L_02F0

L_02EE:
    MsgWinCloseAll

L_02F0:
    VMReturn
    .balign 4, 0
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd

Movement_0314:
    Move 32, 1
    Move 0, 1
    MoveEnd

Movement_0320:
    Move 33, 1
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0
    Move 3, 1
    MoveEnd

Movement_033C:
    Move 32, 1
    MoveEnd

Movement_0344:
    Move 33, 1
    MoveEnd

Movement_034C:
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_035C:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
