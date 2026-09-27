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
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    VMStackPushFlag 2455
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0245
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 0, 32784
    ListMenuAdd 4, 65535, 0
    ListMenuAdd 5, 65535, 1
    ListMenuAdd 6, 65535, 2
    ListMenuShow
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_00E5
    VMJump L_00F7

L_00E5:
    WorkSetConst 0x8024, 4
    WorkSetConst 0x8025, 5
    VMJump L_0141

L_00F7:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_010A
    VMJump L_011C

L_010A:
    WorkSetConst 0x8024, 5
    WorkSetConst 0x8025, 6
    VMJump L_0141

L_011C:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_012F
    VMJump L_0141

L_012F:
    WorkSetConst 0x8024, 6
    WorkSetConst 0x8025, 4
    VMJump L_0141

L_0141:
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0158
    VMJump L_0176

L_0158:
    WorkSetConst 0x8020, 14
    WorkSetConst 0x8021, 15
    WorkSetConst 0x8022, 14
    WorkSetConst 0x8023, 4
    VMJump L_01D8

L_0176:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_0189
    VMJump L_01A7

L_0189:
    WorkSetConst 0x8020, 10
    WorkSetConst 0x8021, 6
    WorkSetConst 0x8022, 20
    WorkSetConst 0x8023, 13
    VMJump L_01D8

L_01A7:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_01BA
    VMJump L_01D8

L_01BA:
    WorkSetConst 0x8020, 18
    WorkSetConst 0x8021, 6
    WorkSetConst 0x8022, 9
    WorkSetConst 0x8023, 14
    VMJump L_01D8

L_01D8:
    MsgWinCloseAll
    ActorMsg 1024, 7, 3, 2, 1
    MsgWaitAdvance
    MsgWinCloseAll
    MultiMsg 0x8024, 0x8020, 0x8021, 1
    MultiMsg 0x8025, 0x8022, 0x8023, 2
    VMSleep 60
    MsgWinCloseNo 1
    MsgWinCloseNo 2
    ParentActorMsg 1024, 8, 2, 0
    MsgWinCloseAll
    Cmd_0275 0, 41, 0
    SEPlay 1908
    SystemMsg 9, 0
    SEWait
    MsgWaitAdvance
    MsgWinCloseAll
    ParentActorMsg 1024, 10, 2, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2455
    VMJump L_0259

L_0245:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose

L_0259:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
