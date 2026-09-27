#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_1:
    ActorsPauseAll
    Cmd_017A 36
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    ActorCmdExec 0, Movement_0224
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 7
    VMStackCmp 1
    VMJumpIf 255, L_007A
    ActorCmdExec 255, Movement_0204
    VMJump L_0088

L_007A:
    ActorWalkRoute 255, 7, 0x8022, 1, 8, 0

L_0088:
    ActorCmdWait
    WordSetPlayerName 0
    PokePartyGetMemberByType 0x8023, 2
    WordSetPartyPokeSpecies 1, 0x8023
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 17
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    WordSetPlayerName 0
    ActorMsg 1024, 2, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40e0, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40e0
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0162
    WordSetPlayerName 0
    ParentActorMsg 1024, 0, 0, 0
    WordSetPlayerName 0
    PokePartyGetMemberByType 0x8023, 2
    WordSetPartyPokeSpecies 1, 0x8023
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 17
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    WordSetPlayerName 0
    ActorMsg 1024, 2, 0, 0, 0
    WorkSetConst 0x40e0, 1
    VMJump L_016F

L_0162:
    WordSetPlayerName 0
    ParentActorMsg 1024, 3, 0, 0

L_016F:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01A8
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_01FD

L_01A8:
    VMStackPush 0x4000
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01E9
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 4, 1, 0, 0
    ActorMsg 1024, 5, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x4000, 1
    VMJump L_01FD

L_01E9:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose

L_01FD:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0204:
    Move 35, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd

Movement_0224:
    Move 75, 1
    MoveEnd
