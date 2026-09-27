#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntry Script_9
    ScriptEntry Script_10
    ScriptEntry Script_11
    ScriptEntry Script_12
    ScriptEntry Script_13
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_1:
    VMHalt

Script_2:
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0086
    VMStackPushFlag 970
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0080
    FlagReset 970
    ActorAdd 3

L_0080:
    VMJump L_00CF

L_0086:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_00CF
    VMStackPushFlag 970
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00B4
    FlagReset 970
    ActorAdd 3

L_00B4:
    VMStackPushFlag 971
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00CF
    FlagReset 971
    ActorAdd 6

L_00CF:
    VMHalt

Script_3:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 59750, 0, 0x239000, 0x1b8000, 0x134000, 0xa9000, 1
    ActorCmdExec 255, Movement_0578
    ActorCmdWait
    EvCameraWait
    MapChangeWarp 479, 7, 14, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    ActorCmdExec 255, Movement_0570
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 120, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_016A
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_01CE

L_016A:
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_01A7
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_01CE

L_01A7:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_01CE
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose

L_01CE:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_0207
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 28, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0271

L_0207:
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0247
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 29, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0271

L_0247:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_0271
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 30, 0, 0
    LastKeyWait
    ActorMsgClose

L_0271:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMJumpIf 255, L_02AA
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 40, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_02D1

L_02AA:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_02D1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 41, 0, 0
    LastKeyWait
    ActorMsgClose

L_02D1:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_030A
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 72, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_036E

L_030A:
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0347
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 73, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_036E

L_0347:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_036E
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 74, 0, 0
    LastKeyWait
    ActorMsgClose

L_036E:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 88, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_03C3
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 92, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0427

L_03C3:
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0400
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 93, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0427

L_0400:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_0427
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 94, 0, 0
    LastKeyWait
    ActorMsgClose

L_0427:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    WordSetPlayerName 0
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_0463
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 96, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_04C7

L_0463:
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_04A0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 97, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_04C7

L_04A0:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_04C7
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 98, 0, 0
    LastKeyWait
    ActorMsgClose

L_04C7:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_0500
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 112, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0567

L_0500:
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0540
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 113, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0567

L_0540:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_0567
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 114, 0, 0
    LastKeyWait
    ActorMsgClose

L_0567:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0570:
    Move 13, 1
    MoveEnd

Movement_0578:
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
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
