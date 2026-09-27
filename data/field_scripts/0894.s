#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    ActorsPauseAll
    Cmd_017A 36
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    ActorCmdExec 0, Movement_01E8
    VMSleep 4
    ActorCmdExec 255, Movement_01C8
    ActorCmdWait
    VMStackPush 0x8022
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_0077
    ActorMsg 1024, 0, 0, 0, 0
    VMJump L_007C

L_0077:
    InfoMsg 0, 1

L_007C:
    MsgWinCloseAll
    VMStackPush 0x8022
    VMStackPushConst 4
    VMStackCmp 5
    VMJumpIf 255, L_009F
    ActorWalkRoute 255, 13, 4, 1, 8, 1

L_009F:
    ActorCmdWait
    WorkSetConst 0x8023, 0
    PokePartyGetCount 0x8023, 1
    WorkSetConst 0x8024, 0
    PokePartyGetMemberByType 0x8024, 2
    WordSetPartyPokeSpecies 0, 0x8024
    WordSetNumber 1, 0x8023, 1
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00EA
    ActorMsg 1024, 1, 0, 0, 0
    VMJump L_00F6

L_00EA:
    ActorMsg 1024, 2, 0, 0, 0

L_00F6:
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 3
    WorkSet 0x8001, 2
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 3, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x4151, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
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

Movement_01C8:
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_01E8:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
