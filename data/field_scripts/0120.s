#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0

Script_2:
    VMStackPush 0x411a
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_004B
    ActorSetGPos 0, 9, 0, 2, 1
    VMJump L_0057

L_004B:
    ActorSetGPos 0, 7, 0, 2, 1

L_0057:
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x411a
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01CD
    ActorMsg 1024, 0, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0194
    TrainerCardGetSex 0x8020
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0172
    PlayerGetDir 0x8021
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_00D3
    ActorCmdExec 0, Movement_03DC
    VMJump L_00FC

L_00D3:
    VMStackPush 0x8021
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_00F4
    ActorCmdExec 0, Movement_0408
    VMJump L_00FC

L_00F4:
    ActorCmdExec 0, Movement_0434

L_00FC:
    ActorMsg 1024, 1, 0, 0, 0
    ActorMsgClose
    ActorCmdWait
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_012D
    ActorCmdExec 0, Movement_03F4
    VMJump L_0156

L_012D:
    VMStackPush 0x8021
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_014E
    ActorCmdExec 0, Movement_0420
    VMJump L_0156

L_014E:
    ActorCmdExec 0, Movement_044C

L_0156:
    ActorCmdWait
    ActorMsg 1024, 2, 0, 0, 0
    ActorMsgClose
    VMCall L_036F
    VMJump L_0188

L_0172:
    ActorMsg 1024, 3, 0, 0, 0
    MsgWaitAdvance
    ActorMsgClose
    VMCall L_036F

L_0188:
    WorkSetConst 0x411a, 1
    VMJump L_01C7

L_0194:
    MsgWinCloseAll
    PlayerGetDir 0x8021
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_01B7
    ActorCmdExec 0, Movement_046C
    ActorCmdWait

L_01B7:
    ActorMsg 1024, 4, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_01C7:
    VMJump L_01DD

L_01CD:
    ActorMsg 1024, 3, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_01DD:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    PlayerGetDir 0x8021
    ActorCmdExec 0, Movement_03AC
    VMStackPush 0x8021
    VMStackPushConst 3
    VMStackCmp 5
    VMJumpIf 255, L_020C
    ActorCmdExec 255, Movement_0460

L_020C:
    ActorCmdWait
    ActorMsg 1024, 0, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_032E
    TrainerCardGetSex 0x8020
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_030C
    PlayerGetDir 0x8021
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_026D
    ActorCmdExec 0, Movement_03DC
    VMJump L_0296

L_026D:
    VMStackPush 0x8021
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_028E
    ActorCmdExec 0, Movement_0408
    VMJump L_0296

L_028E:
    ActorCmdExec 0, Movement_0434

L_0296:
    ActorMsg 1024, 1, 0, 0, 0
    ActorMsgClose
    ActorCmdWait
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_02C7
    ActorCmdExec 0, Movement_03F4
    VMJump L_02F0

L_02C7:
    VMStackPush 0x8021
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_02E8
    ActorCmdExec 0, Movement_0420
    VMJump L_02F0

L_02E8:
    ActorCmdExec 0, Movement_044C

L_02F0:
    ActorCmdWait
    ActorMsg 1024, 2, 0, 0, 0
    ActorMsgClose
    VMCall L_036F
    VMJump L_0322

L_030C:
    ActorMsg 1024, 3, 0, 0, 0
    MsgWaitAdvance
    ActorMsgClose
    VMCall L_036F

L_0322:
    WorkSetConst 0x411a, 1
    VMJump L_0369

L_032E:
    MsgWinCloseAll
    PlayerGetDir 0x8021
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0351
    ActorCmdExec 0, Movement_046C
    ActorCmdWait

L_0351:
    ActorMsg 1024, 5, 0, 0, 0
    ActorMsgClose
    ActorCmdExec 255, Movement_0474
    ActorCmdWait

L_0369:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_036F:
    PlayerGetDir 0x8021
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0396
    ActorCmdExec 0, Movement_03BC
    ActorCmdWait
    VMJump L_03A0

L_0396:
    ActorCmdExec 0, Movement_03D0
    ActorCmdWait

L_03A0:
    VMReturn
    .balign 4, 0
    Move 35, 1
    MoveEnd

Movement_03AC:
    Move 34, 1
    MoveEnd
    Move 33, 1
    MoveEnd

Movement_03BC:
    Move 13, 1
    Move 15, 2
    Move 12, 1
    Move 33, 1
    MoveEnd

Movement_03D0:
    Move 15, 2
    Move 33, 1
    MoveEnd

Movement_03DC:
    Move 35, 1
    Move 13, 1
    Move 15, 2
    Move 12, 1
    Move 34, 4
    MoveEnd

Movement_03F4:
    Move 13, 1
    Move 14, 2
    Move 12, 1
    Move 35, 1
    MoveEnd

Movement_0408:
    Move 34, 1
    Move 13, 1
    Move 14, 2
    Move 12, 1
    Move 35, 4
    MoveEnd

Movement_0420:
    Move 13, 1
    Move 15, 2
    Move 12, 1
    Move 34, 1
    MoveEnd

Movement_0434:
    Move 33, 1
    Move 15, 1
    Move 13, 2
    Move 14, 1
    Move 32, 4
    MoveEnd

Movement_044C:
    Move 14, 1
    Move 12, 2
    Move 15, 1
    Move 33, 1
    MoveEnd

Movement_0460:
    Move 63, 1
    Move 35, 1
    MoveEnd

Movement_046C:
    Move 33, 1
    MoveEnd

Movement_0474:
    Move 13, 1
    MoveEnd

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
