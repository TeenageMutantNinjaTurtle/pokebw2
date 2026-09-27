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
    ScriptEntry Script_14
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_1:
    VMHalt

Script_2:
    VMHalt

Script_3:
    ActorsPauseAll
    WorkSetConst 0x4000, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    VMCall L_0064
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0064:
    SystemMsg 13, 2
    InfoMsgClose
    FadeOutBlackQ
    FadeWait
    FieldClose
    Cmd_016E
    FieldOpen
    FadeInBlackQ
    FadeWait
    Cmd_0172 0x8010
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0091
    VMJump L_0099

L_0091:
    VMReturn
    VMJump L_00BA

L_0099:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_00AC
    VMJump L_00BA

L_00AC:
    VMCall L_00BC
    VMReturn
    VMJump L_00BA

L_00BA:
    VMReturn

L_00BC:
    VMStackPushFlag 2438
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00D5
    VMCall L_00D9

L_00D5:
    FunfestMissionStart
    VMReturn

L_00D9:
    ActorCmdExec 0, Movement_0198
    ActorCmdWait
    ActorCmdExec 255, Movement_01A0
    ActorCmdWait
    ActorMsg 1024, 18, 0, 0, 0
    MsgWinCloseAll
    VMReturn

Script_8:
    ActorsPauseAll
    ActorCmdExec 0, Movement_01D0
    ActorCmdWait
    ActorCmdExec 0, Movement_01DC
    ActorCmdWait
    ActorCmdExec 255, Movement_01B0
    ActorCmdWait
    ActorMsg 1024, 14, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_01A0
    ActorCmdWait
    ActorMsg 1024, 15, 0, 0, 0
    ActorCmdExec 0, Movement_01A8
    ActorMsg 1024, 16, 0, 0, 0
    ActorCmdWait
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0198
    ActorCmdWait
    ActorMsg 1024, 17, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    MedalDiscover 77
    MedalDiscover 221
    MedalDiscover 223
    MedalDiscover 225
    MedalDiscover 229
    MedalDiscover 227
    WorkSetConst 0x404d, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0198:
    Move 32, 1
    MoveEnd

Movement_01A0:
    Move 33, 1
    MoveEnd

Movement_01A8:
    Move 35, 1
    MoveEnd

Movement_01B0:
    Move 34, 1
    MoveEnd
    Move 1, 1
    MoveEnd
    Move 3, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0

Movement_01D0:
    Move 3, 1
    Move 75, 1
    MoveEnd

Movement_01DC:
    Move 15, 1
    MoveEnd

Script_11:
    ActorsPauseAll
    ActorCmdExec 0, Movement_01D0
    ActorCmdWait
    ActorCmdExec 0, Movement_01DC
    ActorCmdWait
    ActorCmdExec 255, Movement_01B0
    ActorCmdWait
    ActorMsg 1024, 19, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0198
    ActorCmdWait
    ActorMsg 1024, 22, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_01A8
    ActorCmdWait
    ActorMsg 1024, 23, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x404d, 4
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    ActorCmdExec 0, Movement_01D0
    ActorCmdWait
    ActorCmdExec 0, Movement_01DC
    ActorCmdWait
    ActorCmdExec 255, Movement_01B0
    ActorCmdWait
    ActorMsg 1024, 20, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 575
    WorkSet 0x8001, 10
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 21, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0198
    ActorCmdWait
    ActorMsg 1024, 22, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_01A8
    ActorCmdWait
    ActorMsg 1024, 23, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x404d, 4
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    ActorCmdExec 0, Movement_0198
    ActorCmdWait
    ActorCmdExec 255, Movement_01A0
    ActorCmdWait
    ActorMsg 1024, 24, 0, 0, 0
    MsgWinCloseAll
    SystemMsg 25, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x404d, 6
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x404d
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0351
    ActorMsg 1024, 33, 0, 2, 0
    VMJump L_037C

L_0351:
    VMStackPush 0x404d
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_0376
    ActorMsg 1024, 34, 0, 2, 0
    VMJump L_037C

L_0376:
    VMCall L_0386

L_037C:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0386:
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

L_0392:
    VMStackPush 0x8021
    VMStackPushConst 555
    VMStackCmp 5
    VMJumpIf 255, L_042A
    ActorMsg 1024, 26, 0, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32802
    ListMenuAdd 27, 65535, 0
    ListMenuAdd 28, 65535, 1
    ListMenuAdd 29, 65535, 10
    ListMenuShow
    WorkCmpConst 0x8022, 0
    VMJumpIf 1, L_03E7
    VMJump L_03F9

L_03E7:
    ActorMsg 1024, 31, 0, 2, 0
    VMJump L_0424

L_03F9:
    WorkCmpConst 0x8022, 1
    VMJumpIf 1, L_040C
    VMJump L_041E

L_040C:
    ActorMsg 1024, 32, 0, 2, 0
    VMJump L_0424

L_041E:
    WorkSetConst 0x8021, 555

L_0424:
    VMJump L_0392

L_042A:
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0
    ActorMsg 1024, 30, 0, 2, 0
    VMReturn

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0

L_0458:
    VMStackPush 0x8023
    VMStackPushConst 555
    VMStackCmp 5
    VMJumpIf 255, L_04F0
    ActorMsg 1024, 42, 1, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32804
    ListMenuAdd 43, 65535, 0
    ListMenuAdd 44, 65535, 1
    ListMenuAdd 45, 65535, 10
    ListMenuShow
    WorkCmpConst 0x8024, 0
    VMJumpIf 1, L_04AD
    VMJump L_04BF

L_04AD:
    ActorMsg 1024, 46, 1, 2, 0
    VMJump L_04EA

L_04BF:
    WorkCmpConst 0x8024, 1
    VMJumpIf 1, L_04D2
    VMJump L_04E4

L_04D2:
    ActorMsg 1024, 47, 1, 2, 0
    VMJump L_04EA

L_04E4:
    WorkSetConst 0x8023, 555

L_04EA:
    VMJump L_0458

L_04F0:
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    ActorMsg 1024, 48, 1, 2, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0

L_0526:
    VMStackPush 0x8025
    VMStackPushConst 555
    VMStackCmp 5
    VMJumpIf 255, L_05BE
    ActorMsg 1024, 35, 2, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32806
    ListMenuAdd 36, 65535, 0
    ListMenuAdd 37, 65535, 1
    ListMenuAdd 38, 65535, 10
    ListMenuShow
    WorkCmpConst 0x8026, 0
    VMJumpIf 1, L_057B
    VMJump L_058D

L_057B:
    ActorMsg 1024, 39, 2, 2, 0
    VMJump L_05B8

L_058D:
    WorkCmpConst 0x8026, 1
    VMJumpIf 1, L_05A0
    VMJump L_05B2

L_05A0:
    ActorMsg 1024, 40, 2, 2, 0
    VMJump L_05B8

L_05B2:
    WorkSetConst 0x8025, 555

L_05B8:
    VMJump L_0526

L_05BE:
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0
    ActorMsg 1024, 41, 2, 2, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 2, 5, 2, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0

L_0600:
    VMStackPush 0x8027
    VMStackPushConst 555
    VMStackCmp 5
    VMJumpIf 255, L_0698
    ActorMsg 1024, 3, 5, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32808
    ListMenuAdd 7, 65535, 0
    ListMenuAdd 8, 65535, 1
    ListMenuAdd 9, 65535, 10
    ListMenuShow
    WorkCmpConst 0x8028, 0
    VMJumpIf 1, L_0655
    VMJump L_0667

L_0655:
    ActorMsg 1024, 4, 5, 2, 0
    VMJump L_0692

L_0667:
    WorkCmpConst 0x8028, 1
    VMJumpIf 1, L_067A
    VMJump L_068C

L_067A:
    ActorMsg 1024, 5, 5, 2, 0
    VMJump L_0692

L_068C:
    WorkSetConst 0x8027, 555

L_0692:
    VMJump L_0600

L_0698:
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8027, 0
    ActorMsg 1024, 6, 5, 2, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SystemMsg 12, 2
    YesNoWin 0x8010
    InfoMsgClose
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_06FF
    CallEntralinkWarpOut
    VMJump L_0709

L_06FF:
    ActorCmdExec 255, Movement_0710
    ActorCmdWait

L_0709:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0710:
    Move 8, 1
    MoveEnd
