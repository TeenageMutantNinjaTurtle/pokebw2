#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd

Script_5:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    PlayerGetGPos 0x8020, 0x8021
    VMStackPushFlag 260
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_007E
    VMStackPush 0x8020
    VMStackPushConst 7
    VMStackCmp 1
    VMStackPush 0x8021
    VMStackPushConst 12
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_006C
    VMJump L_007E

L_006C:
    ActorSetGPos 8, 7, 0, 12, 0
    WorkSetConst 0x4001, 1

L_007E:
    RTCallGlobal 10395
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    VMHalt

Script_4:
    ActorsPauseAll
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    PlayerGetDir 0x8022
    Cmd_0233 0x8023
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 260
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4001
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0130
    ParentActorMsg 1024, 8, 0, 0
    MsgWinCloseAll
    WorkCmpConst 0x8022, 0
    VMJumpIf 1, L_00FB
    WorkCmpConst 0x8022, 3
    VMJumpIf 1, L_00FB
    VMJump L_0109

L_00FB:
    ActorCmdExec 8, Movement_01D8
    VMJump L_012A

L_0109:
    WorkCmpConst 0x8022, 2
    VMJumpIf 1, L_011C
    VMJump L_012A

L_011C:
    ActorCmdExec 8, Movement_01E8
    VMJump L_012A

L_012A:
    VMSleep 8
    ActorCmdWait

L_0130:
    ActorMsg 1024, 9, 8, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0179
    ActorMsg 1024, 10, 8, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01CC

L_0179:
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_01B2
    ActorMsg 1024, 11, 8, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01CC

L_01B2:
    ActorCmdExec 8, Movement_01F8
    ActorCmdWait
    ActorMsg 1024, 12, 8, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_01CC:
    FlagSet 260
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_01D8:
    Move 15, 2
    Move 34, 1
    Move 63, 1
    MoveEnd

Movement_01E8:
    Move 14, 1
    Move 35, 1
    Move 63, 1
    MoveEnd

Movement_01F8:
    Move 32, 1
    MoveEnd
    Move 75, 1
    MoveEnd
    Move 35, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 32, 1
    MoveEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 255
    WorkSet 0x8001, 1
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 3
    WorkSet 0x8001, 1
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PokePartyGetCount 0x8024, 4
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_02C3
    VMCall L_02CF
    VMJump L_02C9

L_02C3:
    VMCall L_02DF

L_02C9:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_02CF:
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_02DF:
    PokePartyIsEgg 0x8025, 0
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0308
    ParentActorMsg 1024, 1, 0, 0
    VMJump L_0317

L_0308:
    WordSetPartyPokeSpecies 0, 0
    ParentActorMsg 1024, 0, 0, 0

L_0317:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0342
    TrainerCardSetFavePokemon 0
    ParentActorMsg 1024, 2, 0, 0
    VMJump L_0374

L_0342:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0365
    ParentActorMsg 1024, 4, 0, 0
    VMJump L_0374

L_0365:
    WordSetPartyPokeSpecies 0, 0
    ParentActorMsg 1024, 3, 0, 0

L_0374:
    LastKeyWait
    MsgWinCloseAll
    VMReturn

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 531, 0
    ParentActorMsg 1024, 7, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
