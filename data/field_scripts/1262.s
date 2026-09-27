#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0

Script_1:
    VMCall L_0059
    VMHalt

Script_2:
    FieldGetContinueFlag 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0057
    VMCall L_0059

L_0057:
    VMHalt

L_0059:
    Cmd_01DB 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_009F
    FlagSet 614
    Cmd_01DB 6, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0099
    Cmd_01DB 5, 0x8020
    ActorDelete 0x8020

L_0099:
    VMJump L_00DE

L_009F:
    FlagReset 614
    Cmd_01DB 6, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00CE
    Cmd_01DB 5, 0x8020
    VMCall L_00E0
    VMJump L_00DE

L_00CE:
    Cmd_01DB 5, 0x8020
    ActorAdd 0x8020
    VMCall L_00E0

L_00DE:
    VMReturn

L_00E0:
    ActorGetGPos 0x8020, 0x8023, 0x8024
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPush 0x8023
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPush 0x8024
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0123
    WorkAdd 0x8023, 1
    ActorSetGPos 0x8020, 0x8023, 0, 0x8024, 1

L_0123:
    VMReturn

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_0139
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0139:
    Cmd_01DB 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0166
    DebugPrint 0x8010
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_0166:
    WordSetPlayerName 0
    RTCGetDayPart 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0180
    VMJump L_0190

L_0180:
    ParentActorMsg 1024, 0, 0, 0
    VMJump L_01BD

L_0190:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_01A3
    VMJump L_01B3

L_01A3:
    ParentActorMsg 1024, 1, 0, 0
    VMJump L_01BD

L_01B3:
    ParentActorMsg 1024, 2, 0, 0

L_01BD:
    ActorMsgClose
    Cmd_01DB 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01F6
    VMCall L_0208
    Cmd_02C5 29
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0206

L_01F6:
    Cmd_01DB 3, 0x8025
    SystemMsg 0x8025, 2
    LastKeyWait
    InfoMsgClose

L_0206:
    VMReturn

L_0208:
    Cmd_01DB 2, 0x8025
    Cmd_01DB 7, 0x8010
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0227
    VMJump L_0239

L_0227:
    MEPlay 1304
    SystemMsg 0x8025, 0
    MEWait
    VMJump L_02F6

L_0239:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_024C
    VMJump L_025E

L_024C:
    MEPlay 1317
    SystemMsg 0x8025, 0
    MEWait
    VMJump L_02F6

L_025E:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_0271
    VMJump L_0283

L_0271:
    RTCallGlobal 2808
    SystemMsg 0x8025, 0
    MEWait
    VMJump L_02F6

L_0283:
    WorkCmpConst 0x8010, 4
    VMJumpIf 1, L_0296
    VMJump L_02AC

L_0296:
    MEPlay 1303
    PlayFieldEffect 54
    SystemMsg 0x8025, 0
    MEWait
    VMJump L_02F6

L_02AC:
    WorkCmpConst 0x8010, 5
    VMJumpIf 1, L_02BF
    VMJump L_02D1

L_02BF:
    SEPlay 1908
    SystemMsg 0x8025, 0
    SEWait
    VMJump L_02F6

L_02D1:
    WorkCmpConst 0x8010, 6
    VMJumpIf 1, L_02E4
    VMJump L_02F6

L_02E4:
    SEPlay 1908
    SystemMsg 0x8025, 0
    SEWait
    VMJump L_02F6

L_02F6:
    MsgWaitAdvance
    InfoMsgClose
    Cmd_01DB 4, 0x8010
    VMReturn
    .balign 4, 0
