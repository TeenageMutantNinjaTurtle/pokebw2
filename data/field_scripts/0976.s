#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    VMCall L_0042
    MapChangeCore 29, 4, 20, 13, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    VMCall L_0042
    MapChangeCore 29, 8, 0, 4, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0042:
    WorkSetConst 0x8020, 0
    PlayerGetDir 0x8020
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_005F
    VMJump L_006D

L_005F:
    ActorCmdExec 255, Movement_00E0
    VMJump L_00D0

L_006D:
    WorkCmpConst 0x8020, 1
    VMJumpIf 1, L_0080
    VMJump L_008E

L_0080:
    ActorCmdExec 255, Movement_00EC
    VMJump L_00D0

L_008E:
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_00A1
    VMJump L_00AF

L_00A1:
    ActorCmdExec 255, Movement_00F8
    VMJump L_00D0

L_00AF:
    WorkCmpConst 0x8020, 3
    VMJumpIf 1, L_00C2
    VMJump L_00D0

L_00C2:
    ActorCmdExec 255, Movement_0104
    VMJump L_00D0

L_00D0:
    ActorCmdWait
    FadeOutBlackQ
    FadeWait
    WorkSetConst 0x8020, 0
    VMReturn
    .balign 4, 0

Movement_00E0:
    Move 52, 1
    Move 69, 1
    MoveEnd

Movement_00EC:
    Move 53, 1
    Move 69, 1
    MoveEnd

Movement_00F8:
    Move 54, 1
    Move 69, 1
    MoveEnd

Movement_0104:
    Move 55, 1
    Move 69, 1
    MoveEnd

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerCardHasBadge 0x8008, 2
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_013D
    VMCall L_017C
    VMJump L_0176

L_013D:
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0166
    ActorMsg 1024, 5, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0176

L_0166:
    ActorMsg 1024, 6, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0176:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_017C:
    ParentActorMsg 1024, 0, 0, 0
    ActorMsgClose
    WorkSetConst 0x8021, 0
    GameGetDifficulty 0x8021
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_01B3
    CallTrainerBattle 766, 0, 0
    VMJump L_01BB

L_01B3:
    CallTrainerBattle 154, 0, 0

L_01BB:
    WorkSetConst 0x8021, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01E0
    CallTrainerBattleEnd
    VMJump L_01E2

L_01E0:
    CallTrainerLose

L_01E2:
    ParentActorMsg 1024, 1, 0, 0
    ActorMsgClose
    TrainerCardSaveGymVictoryParty 2
    TrainerCardAddBadge 2
    WordSetPlayerName 0
    MEPlay 1306
    WorkSetConst 0x8022, 0
    TrainerCardGetSex 0x8022
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0224
    PlayFieldEffect 5
    VMJump L_0228

L_0224:
    PlayFieldEffect 57

L_0228:
    MEWait
    WorkSetConst 0x8022, 0
    SystemMsg 2, 0
    InfoMsgClose
    ParentActorMsg 1024, 3, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 403
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 2416
    WorkSetConst 0x40b4, 1
    FlagReset 756
    Cmd_0262 1, 5
    FlagSet 753
    WorkSetConst 0x40b2, 4
    TrainerFlagSet 737
    VMReturn
    .balign 4, 0
