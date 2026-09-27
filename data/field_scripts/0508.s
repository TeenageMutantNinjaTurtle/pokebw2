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

Script_3:
    VMHalt

Script_1:
    VMHalt

Script_2:
    VMHalt
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

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 14, 0, 1, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x4185
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4003
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_021D
    ActorMsg 1024, 0, 1, 0, 1
    MsgWaitAdvance
    Random 0x4002, 4
    VMStackPush 0x4002
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00F2
    ActorMsg 1024, 1, 1, 0, 1
    MsgWaitAdvance
    VMJump L_0161

L_00F2:
    VMStackPush 0x4002
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0119
    ActorMsg 1024, 2, 1, 0, 1
    MsgWaitAdvance
    VMJump L_0161

L_0119:
    VMStackPush 0x4002
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0140
    ActorMsg 1024, 3, 1, 0, 1
    MsgWaitAdvance
    VMJump L_0161

L_0140:
    VMStackPush 0x4002
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0161
    ActorMsg 1024, 4, 1, 0, 1
    MsgWaitAdvance

L_0161:
    PokePartyGetCount 0x8020, 0

L_0167:
    VMStackPush 0x8020
    VMStackPush 0x8021
    VMStackCmp 2
    VMJumpIf 255, L_01D8
    PokePartyGetParam 0x8022, 0x8021, 10
    PokePartyIsEgg 0x8024, 0x8021
    VMStackPush 0x8022
    VMStackPushConst 43
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_01CC
    PokePartyGetSpecies 0x4185, 0x8021
    WordSetPokeSpecies 0, 0x4185
    WorkSetConst 0x8023, 1

L_01CC:
    WorkAdd 0x8021, 1
    VMJump L_0167

L_01D8:
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0207
    ActorMsg 1024, 6, 1, 0, 1
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x4003, 1
    VMJump L_0217

L_0207:
    ActorMsg 1024, 5, 1, 0, 1
    LastKeyWait
    MsgWinCloseAll

L_0217:
    VMJump L_0230

L_021D:
    WordSetPokeSpecies 0, 0x4185
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0230:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    VMStackPush 0x8006
    WorkSet 0x8000, 370
    WorkSet 0x8001, 1
    WorkSet 0x8002, 345
    WorkSet 0x8003, 15
    WorkSet 0x8004, 16
    WorkSet 0x8005, 16
    RTGetTextFile 0x8006
    RTCallGlobal 2800
    VMStackPop 0x8006
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    Cmd_02B4 0, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 4
    VMJumpIf 255, L_02DD
    Cmd_02B5 0, 1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_02F1

L_02DD:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose

L_02F1:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x4108
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_03DF
    ParentActorMsg 1024, 10, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03CB
    ItemSub 30, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03B7
    MsgWinCloseAll
    SEPlay 2017
    SEWait
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll
    PlayerGetDir 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0389
    ActorCmdExec 3, Movement_0408
    VMJump L_0391

L_0389:
    ActorCmdExec 3, Movement_041C

L_0391:
    VMSleep 20
    ActorCmdExec 255, Movement_042C
    ActorCmdWait
    ActorDelete 3
    WorkSetConst 0x4108, 3
    FlagSet 860
    FlagReset 861
    VMJump L_03C5

L_03B7:
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_03C5:
    VMJump L_03D9

L_03CB:
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_03D9:
    VMJump L_0400

L_03DF:
    VMStackPush 0x4108
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0400
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0400:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0408:
    Move 39, 4
    Move 19, 1
    Move 16, 8
    Move 20, 25
    MoveEnd

Movement_041C:
    Move 36, 4
    Move 16, 8
    Move 20, 25
    MoveEnd

Movement_042C:
    Move 0, 1
    MoveEnd
