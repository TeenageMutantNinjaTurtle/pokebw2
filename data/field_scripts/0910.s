#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntriesEnd

Script_1:
    VMStackPushFlag 763
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_004B
    WorkSetConst 0x4000, 1
    WorkSetConst 0x4001, 1
    WorkSetConst 0x4002, 1
    WorkSetConst 0x4003, 1
    VMJump L_0063

L_004B:
    WorkSetConst 0x4000, 0
    WorkSetConst 0x4001, 1
    WorkSetConst 0x4002, 1
    WorkSetConst 0x4003, 1

L_0063:
    VMHalt

Script_2:
    VMHalt

Script_3:
    ActorsPauseAll
    VMStackPush 0x40aa
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01E2
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    PlayerGetGPos 0x8020, 0x8021
    WorkCmpConst 0x8020, 8
    VMJumpIf 1, L_00A1
    VMJump L_00B1

L_00A1:
    ActorCmdExec 0, Movement_01F4
    ActorCmdWait
    VMJump L_0101

L_00B1:
    WorkCmpConst 0x8020, 9
    VMJumpIf 1, L_00C4
    VMJump L_00D4

L_00C4:
    ActorCmdExec 0, Movement_0200
    ActorCmdWait
    VMJump L_0101

L_00D4:
    WorkCmpConst 0x8020, 10
    VMJumpIf 1, L_00E7
    VMJump L_00F7

L_00E7:
    ActorCmdExec 0, Movement_020C
    ActorCmdWait
    VMJump L_0101

L_00F7:
    ActorCmdExec 0, Movement_01F4
    ActorCmdWait

L_0101:
    ActorCmdExec 255, Movement_0238
    ActorCmdWait
    VMStackPushFlag 116
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0150
    ActorMsg 1024, 0, 0, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 30
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 116

L_0150:
    WorkCmpConst 0x8020, 8
    VMJumpIf 1, L_0163
    VMJump L_0173

L_0163:
    ActorCmdExec 0, Movement_0218
    ActorCmdWait
    VMJump L_01DC

L_0173:
    WorkCmpConst 0x8020, 9
    VMJumpIf 1, L_0186
    VMJump L_0196

L_0186:
    ActorCmdExec 0, Movement_0220
    ActorCmdWait
    VMJump L_01DC

L_0196:
    WorkCmpConst 0x8020, 10
    VMJumpIf 1, L_01A9
    VMJump L_01B9

L_01A9:
    ActorCmdExec 0, Movement_022C
    ActorCmdWait
    VMJump L_01DC

L_01B9:
    WorkCmpConst 0x8020, 8
    VMJumpIf 1, L_01CC
    VMJump L_01DC

L_01CC:
    ActorCmdExec 0, Movement_0218
    ActorCmdWait
    VMJump L_01DC

L_01DC:
    WorkSetConst 0x40aa, 1

L_01E2:
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_01F4:
    Move 75, 1
    Move 3, 1
    MoveEnd

Movement_0200:
    Move 75, 1
    Move 15, 1
    MoveEnd

Movement_020C:
    Move 75, 1
    Move 15, 2
    MoveEnd

Movement_0218:
    Move 1, 1
    MoveEnd

Movement_0220:
    Move 14, 1
    Move 1, 1
    MoveEnd

Movement_022C:
    Move 14, 2
    Move 1, 1
    MoveEnd

Movement_0238:
    Move 34, 1
    MoveEnd

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerCardHasBadge 0x8008, 1
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0275
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0283

L_0275:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_0283:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    TrainerCardHasBadge 0x8008, 1
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02B9
    InfoMsg 3, 2
    VMJump L_02DC

L_02B9:
    VMStackPush 0x40ac
    VMStackPushConst 4
    VMStackCmp 4
    VMJumpIf 255, L_02D7
    InfoMsg 5, 2
    VMJump L_02DC

L_02D7:
    InfoMsg 4, 2

L_02DC:
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 6, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
