#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_8:
    VMCall L_0052
    VMHalt

Script_7:
    VMCall L_0052
    VMHalt

Script_6:
    VMCall L_0052
    VMHalt

L_0052:
    WorkSetConst 0x8024, 0
    GameGetVersion 0x8024
    VMStackPush 0x8024
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_007F
    ObjInitWarpGPos 3, 0, 0, 0
    VMJump L_0089

L_007F:
    ObjInitWarpGPos 0, 0, 0, 0

L_0089:
    WorkSetConst 0x8024, 0
    VMReturn

Script_1:
    ActorsPauseAll
    WordSetLoadRivalName 1
    WordSetPlayerName 0
    VMStackPushFlag 487
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00FD
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 0, 4, 0, 0
    PlayerGetDir 0x8021
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_00E5
    LastKeyWait
    MsgWinCloseAll
    VMJump L_00F3

L_00E5:
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 4, Movement_01E4
    ActorCmdWait

L_00F3:
    FlagSet 487
    VMJump L_0117

L_00FD:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    SEPlay 1351
    ActorMsg 1024, 1, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0117:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
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
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_01E4:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
    Move 161, 1
    MoveEnd
