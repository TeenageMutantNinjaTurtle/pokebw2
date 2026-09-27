#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0

Script_2:
    GameGetVersion 0x8020
    VMStackPush 0x4100
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0063
    FlagSet 837
    VMJump L_00B7

L_0063:
    VMStackPush 0x4100
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0090
    FlagReset 837
    VMJump L_00B7

L_0090:
    VMStackPush 0x4100
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8020
    VMStackPushConst 22
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00B7
    FlagReset 837

L_00B7:
    VMStackPush 0x4100
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_00D8
    FlagSet 997
    FlagSet 998
    VMJump L_0114

L_00D8:
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_00F9
    FlagReset 997
    FlagSet 998
    VMJump L_0114

L_00F9:
    VMStackPush 0x8020
    VMStackPushConst 22
    VMStackCmp 1
    VMJumpIf 255, L_0114
    FlagSet 997
    FlagReset 998

L_0114:
    VMHalt

Script_3:
    GameGetVersion 0x8020
    VMStackPush 0x40ff
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0149
    ActorSetGPos 7, 16, 0, 25, 1

L_0149:
    VMStackPush 0x4100
    VMStackPushConst 2
    VMStackCmp 5
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0178
    ActorSetGPos 0, 16, 0, 27, 0

L_0178:
    VMHalt

Script_4:
    VMHalt

Script_5:
    ActorsPauseAll
    GameGetVersion 0x8020
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_01A9
    ActorCmdExec 255, Movement_03E0
    VMJump L_01B1

L_01A9:
    ActorCmdExec 255, Movement_03D4

L_01B1:
    ActorCmdWait
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_01D8
    ActorMsg 1024, 0, 7, 5, 0
    VMJump L_01E4

L_01D8:
    ActorMsg 1024, 0, 7, 4, 0

L_01E4:
    MsgWinCloseAll
    ActorCmdExec 0, Movement_052C
    ActorCmdWait
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0215
    ActorMsg 1024, 1, 0, 6, 0
    VMJump L_0221

L_0215:
    ActorMsg 1024, 1, 0, 3, 0

L_0221:
    MsgWinCloseAll
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0248
    ActorMsg 1024, 2, 0, 6, 0
    VMJump L_0254

L_0248:
    ActorMsg 1024, 2, 0, 3, 0

L_0254:
    MsgWinCloseAll
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_027B
    ActorMsg 1024, 3, 7, 5, 0
    VMJump L_0287

L_027B:
    ActorMsg 1024, 3, 7, 4, 0

L_0287:
    MsgWinCloseAll
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_02AE
    ActorMsg 1024, 4, 0, 6, 0
    VMJump L_02BA

L_02AE:
    ActorMsg 1024, 4, 0, 3, 0

L_02BA:
    MsgWinCloseAll
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_02E1
    ActorMsg 1024, 5, 7, 5, 0
    VMJump L_02ED

L_02E1:
    ActorMsg 1024, 5, 7, 4, 0

L_02ED:
    MsgWinCloseAll
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0322
    ActorCmdExec 7, Movement_0408
    VMSleep 4
    ActorCmdExec 255, Movement_0524
    ActorCmdWait
    SEPlay 1369
    VMJump L_0338

L_0322:
    ActorCmdExec 7, Movement_03FC
    VMSleep 16
    ActorCmdExec 255, Movement_0514
    ActorCmdWait

L_0338:
    ActorDelete 7
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0351
    SEWait

L_0351:
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0372
    ActorCmdExec 255, Movement_0514
    VMJump L_037A

L_0372:
    ActorCmdExec 255, Movement_050C

L_037A:
    ActorCmdWait
    ActorCmdExec 0, Movement_053C
    ActorCmdWait
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_03AB
    ActorMsg 1024, 6, 0, 6, 0
    VMJump L_03B7

L_03AB:
    ActorMsg 1024, 6, 0, 3, 0

L_03B7:
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40ff, 2
    WorkSetConst 0x4149, 1
    FlagSet 1036
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_03D4:
    Move 15, 1
    Move 12, 1
    MoveEnd

Movement_03E0:
    Move 14, 1
    Move 13, 1
    MoveEnd
    Move 12, 4
    MoveEnd
    Move 13, 4
    MoveEnd

Movement_03FC:
    Move 18, 3
    Move 17, 7
    MoveEnd

Movement_0408:
    Move 19, 3
    Move 17, 3
    Move 19, 2
    MoveEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 8, 7, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0467
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_047B

L_0467:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose

L_047B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_04B0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_04C4

L_04B0:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose

L_04C4:
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

Movement_050C:
    Move 32, 1
    MoveEnd

Movement_0514:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_0524:
    Move 35, 1
    MoveEnd

Movement_052C:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd

Movement_053C:
    Move 161, 1
    MoveEnd
