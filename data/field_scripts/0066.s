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
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0

Script_10:
    VMStackPushFlag 293
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00AA
    FlagReset 770
    VMStackPushFlag 2752
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00AA
    WorkSetConst 0x40c8, 1

L_00AA:
    VMHalt

Script_13:
    CasteliaRushInit
    VMHalt

Script_14:
    CasteliaRushInit
    VMHalt

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 22, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 23, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2752
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_034C
    VMStackPushFlag 293
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0161
    VMStackPushFlag 292
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_014F
    ActorMsg 1024, 9, 0, 0, 0
    FlagSet 292
    VMJump L_015B

L_014F:
    ActorMsg 1024, 2, 0, 0, 0

L_015B:
    VMJump L_0196

L_0161:
    VMStackPushFlag 291
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_018A
    ActorMsg 1024, 0, 0, 0, 0
    FlagSet 291
    VMJump L_0196

L_018A:
    ActorMsg 1024, 1, 0, 0, 0

L_0196:
    MoneyWinDisp 31, 1
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32804
    ListMenuAdd 10, 65535, 0
    ListMenuAdd 11, 65535, 1
    ListMenuAdd 12, 65535, 2
    ListMenuShow
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01E4
    WorkSetConst 0x8023, 1
    WorkSetConst 0x8025, 100
    VMJump L_0209

L_01E4:
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0209
    WorkSetConst 0x8023, 12
    WorkSetConst 0x8025, 1200
    VMJump L_0209

L_0209:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_02FB
    ItemCheckSpace 591, 0x8023, 0x8027
    MoneyCheck 0x8026, 0x8025
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0263
    MoneyWinClose
    ActorMsg 1024, 3, 0, 2, 0
    MsgWinCloseAll
    VMJump L_02F5

L_0263:
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_028C
    MoneyWinClose
    ActorMsg 1024, 4, 0, 2, 0
    MsgWinCloseAll
    VMJump L_02F5

L_028C:
    SEPlay 1621
    MoneySub 0x8025
    MoneyWinUpdate
    SEWait
    RecordAdd 21, 1
    RecordAdd 22, 0x8025
    ActorMsg 1024, 7, 0, 2, 0
    MsgWinCloseAll
    MoneyWinClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 591
    WorkSet 0x8001, 0x8023
    RTCallGlobal 2801
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 2752
    VMStackPushFlag 293
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02F5
    FlagSet 293
    VMCall Script_4

L_02F5:
    VMJump L_0346

L_02FB:
    MoneyWinClose
    VMStackPushFlag 293
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0336
    ActorMsg 1024, 5, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0346

L_0336:
    ActorMsg 1024, 6, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0346:
    VMJump L_035C

L_034C:
    ActorMsg 1024, 8, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_035C:
    VMStackPush 0x40c8
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_03CC
    ActorCmdExec 255, Movement_0B9C
    ActorCmdWait
    ActorCmdExec 2, Movement_0B5C
    ActorCmdExec 3, Movement_0B6C
    ActorCmdExec 4, Movement_0B6C
    ActorCmdExec 5, Movement_0B6C
    VMSleep 4
    ActorCmdExec 6, Movement_0B74
    ActorCmdWait
    VMStackPushFlag 2752
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03C6
    WorkSetConst 0x40c8, 0
    VMJump L_03CC

L_03C6:
    WorkSetConst 0x40c8, 1

L_03CC:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    FlagReset 771
    ActorAdd 1
    ActorWalkRoute 1, 14, 35, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 1, Movement_0B44
    ActorCmdWait
    ActorCmdExec 255, Movement_0B7C
    ActorCmdWait
    ActorMsg 1024, 13, 1, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorWalkRoute 1, 14, 18, 1, 8, 1
    ActorCmdWait
    ActorDelete 1
    FlagSet 771
    VMReturn

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 14, 2, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0B84
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 15, 3, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 3, Movement_0B8C
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 16, 4, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 4, Movement_0B8C
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 17, 5, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 5, Movement_0B8C
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2752
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_06F1
    ActorMsg 1024, 18, 6, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_06DD
    WorkSetConst 0x40c8, 2
    ActorMsg 1024, 19, 6, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 12
    VMStackCmp 5
    VMStackPush 0x8022
    VMStackPushConst 40
    VMStackCmp 5
    VMStackCmp 7
    VMJumpIf 255, L_055D
    ActorWalkRoute 255, 12, 40, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 255, Movement_0B8C
    ActorCmdWait

L_055D:
    ActorCmdExec 6, Movement_0B8C
    ActorCmdWait
    ActorCmdExec 2, Movement_0B50
    VMSleep 16
    ActorCmdExec 3, Movement_0B5C
    ActorCmdExec 4, Movement_0B6C
    ActorCmdExec 5, Movement_0B6C
    ActorCmdExec 6, Movement_0B6C
    ActorCmdExec 255, Movement_0B6C
    ActorCmdWait
    ActorSetGPos 2, 12, 0, 47, 0
    VMSleep 8
    ActorCmdExec 3, Movement_0B50
    VMSleep 16
    ActorCmdExec 4, Movement_0B5C
    ActorCmdExec 5, Movement_0B6C
    ActorCmdExec 6, Movement_0B6C
    ActorCmdExec 255, Movement_0B6C
    VMSleep 4
    ActorCmdExec 2, Movement_0B74
    ActorCmdWait
    ActorSetGPos 3, 12, 0, 47, 0
    VMSleep 8
    ActorCmdExec 4, Movement_0B50
    VMSleep 16
    ActorCmdExec 5, Movement_0B5C
    ActorCmdExec 6, Movement_0B6C
    ActorCmdExec 255, Movement_0B6C
    ActorCmdExec 2, Movement_0B6C
    VMSleep 4
    ActorCmdExec 3, Movement_0B74
    ActorCmdWait
    ActorSetGPos 4, 12, 0, 47, 0
    VMSleep 8
    ActorCmdExec 5, Movement_0B50
    VMSleep 16
    ActorCmdExec 6, Movement_0B5C
    ActorCmdExec 255, Movement_0B6C
    ActorCmdExec 2, Movement_0B6C
    ActorCmdExec 3, Movement_0B6C
    VMSleep 4
    ActorCmdExec 4, Movement_0B74
    ActorCmdWait
    ActorSetGPos 5, 12, 0, 47, 0
    VMSleep 8
    ActorCmdExec 6, Movement_0B50
    VMSleep 16
    ActorCmdExec 255, Movement_0B5C
    ActorCmdExec 2, Movement_0B6C
    ActorCmdExec 3, Movement_0B6C
    ActorCmdExec 4, Movement_0B6C
    VMSleep 4
    ActorCmdExec 5, Movement_0B74
    ActorCmdWait
    ActorSetGPos 6, 12, 0, 47, 0
    VMCall Script_3
    VMJump L_06EB

L_06DD:
    ActorMsg 1024, 20, 6, 0, 0
    MsgWinCloseAll

L_06EB:
    VMJump L_06FF

L_06F1:
    ActorMsg 1024, 21, 6, 0, 0
    MsgWinCloseAll

L_06FF:
    ActorCmdExec 6, Movement_0B8C
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    ActorCmdExec 6, Movement_0B94
    VMSleep 3
    ActorCmdExec 255, Movement_0B8C
    ActorCmdWait
    VMStackPushFlag 2752
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0905
    ActorMsg 1024, 18, 6, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_08F1
    WorkSetConst 0x40c8, 2
    ActorMsg 1024, 19, 6, 0, 0
    MsgWinCloseAll
    ActorCmdExec 6, Movement_0B8C
    ActorCmdWait
    ActorCmdExec 2, Movement_0B50
    VMSleep 16
    ActorCmdExec 3, Movement_0B5C
    ActorCmdExec 4, Movement_0B6C
    ActorCmdExec 5, Movement_0B6C
    ActorCmdExec 6, Movement_0B6C
    ActorCmdExec 255, Movement_0B6C
    ActorCmdWait
    ActorSetGPos 2, 12, 0, 47, 0
    VMSleep 8
    ActorCmdExec 3, Movement_0B50
    VMSleep 16
    ActorCmdExec 4, Movement_0B5C
    ActorCmdExec 5, Movement_0B6C
    ActorCmdExec 6, Movement_0B6C
    ActorCmdExec 255, Movement_0B6C
    VMSleep 4
    ActorCmdExec 2, Movement_0B74
    ActorCmdWait
    ActorSetGPos 3, 12, 0, 47, 0
    VMSleep 8
    ActorCmdExec 4, Movement_0B50
    VMSleep 16
    ActorCmdExec 5, Movement_0B5C
    ActorCmdExec 6, Movement_0B6C
    ActorCmdExec 255, Movement_0B6C
    ActorCmdExec 2, Movement_0B6C
    VMSleep 4
    ActorCmdExec 3, Movement_0B74
    ActorCmdWait
    ActorSetGPos 4, 12, 0, 47, 0
    VMSleep 8
    ActorCmdExec 5, Movement_0B50
    VMSleep 16
    ActorCmdExec 6, Movement_0B5C
    ActorCmdExec 255, Movement_0B6C
    ActorCmdExec 2, Movement_0B6C
    ActorCmdExec 3, Movement_0B6C
    VMSleep 4
    ActorCmdExec 4, Movement_0B74
    ActorCmdWait
    ActorSetGPos 5, 12, 0, 47, 0
    VMSleep 8
    ActorCmdExec 6, Movement_0B50
    VMSleep 16
    ActorCmdExec 255, Movement_0B5C
    ActorCmdExec 2, Movement_0B6C
    ActorCmdExec 3, Movement_0B6C
    ActorCmdExec 4, Movement_0B6C
    VMSleep 4
    ActorCmdExec 5, Movement_0B74
    ActorCmdWait
    ActorSetGPos 6, 12, 0, 47, 0
    VMCall Script_12
    VMJump L_08FF

L_08F1:
    ActorMsg 1024, 20, 6, 0, 0
    MsgWinCloseAll

L_08FF:
    VMJump L_0913

L_0905:
    ActorMsg 1024, 21, 6, 0, 0
    MsgWinCloseAll

L_0913:
    ActorCmdExec 6, Movement_0B8C
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    VMStackPushFlag 2752
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0ABF
    VMStackPushFlag 292
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_095F
    ActorMsg 1024, 9, 0, 0, 0
    FlagSet 292
    VMJump L_096B

L_095F:
    ActorMsg 1024, 2, 0, 0, 0

L_096B:
    MoneyWinDisp 31, 1
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32804
    ListMenuAdd 10, 65535, 0
    ListMenuAdd 11, 65535, 1
    ListMenuAdd 12, 65535, 2
    ListMenuShow
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09B9
    WorkSetConst 0x8023, 1
    WorkSetConst 0x8025, 100
    VMJump L_09DE

L_09B9:
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_09DE
    WorkSetConst 0x8023, 12
    WorkSetConst 0x8025, 1200
    VMJump L_09DE

L_09DE:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0AA7
    ItemCheckSpace 591, 0x8023, 0x8027
    MoneyCheck 0x8026, 0x8025
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0A38
    MoneyWinClose
    ActorMsg 1024, 3, 0, 2, 0
    MsgWinCloseAll
    VMJump L_0AA1

L_0A38:
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0A61
    MoneyWinClose
    ActorMsg 1024, 4, 0, 2, 0
    MsgWinCloseAll
    VMJump L_0AA1

L_0A61:
    SEPlay 1621
    MoneySub 0x8025
    MoneyWinUpdate
    SEWait
    ActorMsg 1024, 7, 0, 2, 0
    MsgWinCloseAll
    MoneyWinClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 591
    WorkSet 0x8001, 0x8023
    RTCallGlobal 2801
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 2752

L_0AA1:
    VMJump L_0AB9

L_0AA7:
    MoneyWinClose
    ActorMsg 1024, 5, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0AB9:
    VMJump L_0ACF

L_0ABF:
    ActorMsg 1024, 8, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0ACF:
    VMStackPush 0x40c8
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0B3F
    ActorCmdExec 255, Movement_0B9C
    ActorCmdWait
    ActorCmdExec 2, Movement_0B5C
    ActorCmdExec 3, Movement_0B6C
    ActorCmdExec 4, Movement_0B6C
    ActorCmdExec 5, Movement_0B6C
    VMSleep 4
    ActorCmdExec 6, Movement_0B74
    ActorCmdWait
    VMStackPushFlag 2752
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0B39
    WorkSetConst 0x40c8, 0
    VMJump L_0B3F

L_0B39:
    WorkSetConst 0x40c8, 1

L_0B3F:
    VMReturn
    .balign 4, 0

Movement_0B44:
    Move 34, 1
    Move 75, 1
    MoveEnd

Movement_0B50:
    Move 15, 2
    Move 13, 12
    MoveEnd

Movement_0B5C:
    Move 12, 1
    Move 34, 1
    Move 63, 2
    MoveEnd

Movement_0B6C:
    Move 12, 1
    MoveEnd

Movement_0B74:
    Move 12, 8
    MoveEnd

Movement_0B7C:
    Move 35, 1
    MoveEnd

Movement_0B84:
    Move 34, 1
    MoveEnd

Movement_0B8C:
    Move 32, 1
    MoveEnd

Movement_0B94:
    Move 33, 1
    MoveEnd

Movement_0B9C:
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd
    Move 75, 1
    MoveEnd
