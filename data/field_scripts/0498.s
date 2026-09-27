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
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 0, 0, 2, 0
    MoneyWinDisp 31, 1
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0065
    VMCall L_0179
    VMJump L_0173

L_0065:
    MoneyWinClose
    ActorMsg 1024, 2, 0, 2, 0
    Random 0x4000, 5
    VMStackPush 0x4000
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_009E
    ActorMsg 1024, 3, 0, 2, 0
    VMJump L_012C

L_009E:
    VMStackPush 0x4000
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00C3
    ActorMsg 1024, 4, 0, 2, 0
    VMJump L_012C

L_00C3:
    VMStackPush 0x4000
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_00E8
    ActorMsg 1024, 5, 0, 2, 0
    VMJump L_012C

L_00E8:
    VMStackPush 0x4000
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_010D
    ActorMsg 1024, 6, 0, 2, 0
    VMJump L_012C

L_010D:
    VMStackPush 0x4000
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_012C
    ActorMsg 1024, 7, 0, 2, 0

L_012C:
    ActorMsg 1024, 8, 0, 2, 0
    MoneyWinDisp 31, 1
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0161
    VMCall L_0179
    VMJump L_0173

L_0161:
    MoneyWinClose
    ActorMsg 1024, 9, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0173:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0179:
    ItemCheckSpace 30, 1, 0x8022
    MoneyCheck 0x8021, 300
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01B2
    MoneyWinClose
    ActorMsg 1024, 10, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_021B

L_01B2:
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01DD
    MoneyWinClose
    ActorMsg 1024, 11, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_021B

L_01DD:
    SEPlay 1621
    MoneySub 300
    MoneyWinUpdate
    SEWait
    ActorMsg 1024, 1, 0, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    MoneyWinClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 30
    WorkSet 0x8001, 1
    RTCallGlobal 2802
    VMStackPop 0x8001
    VMStackPop 0x8000

L_021B:
    VMReturn

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x4108
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_036F
    ParentActorMsg 1024, 12, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_035B
    ItemSub 30, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0347
    MsgWinCloseAll
    SEPlay 2017
    SEWait
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    PlayerGetRailPos 0x8023, 0x8024, 0x8025
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0319
    ActorCmdExec 4, Movement_0438
    VMJump L_0321

L_0319:
    ActorCmdExec 4, Movement_044C

L_0321:
    VMSleep 20
    ActorCmdExec 255, Movement_045C
    ActorCmdWait
    ActorDelete 4
    WorkSetConst 0x4108, 1
    FlagSet 858
    FlagReset 859
    VMJump L_0355

L_0347:
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0355:
    VMJump L_0369

L_035B:
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0369:
    VMJump L_0431

L_036F:
    VMStackPush 0x4108
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0396
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0431

L_0396:
    VMStackPush 0x4108
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_0410
    ParentActorMsg 1024, 16, 0, 0
    ItemCheckSpace 33, 12, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03FC
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 33
    WorkSet 0x8001, 12
    RTCallGlobal 2801
    VMStackPop 0x8001
    VMStackPop 0x8000
    WorkSetConst 0x4108, 7
    VMJump L_040A

L_03FC:
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_040A:
    VMJump L_0431

L_0410:
    VMStackPush 0x4108
    VMStackPushConst 7
    VMStackCmp 1
    VMJumpIf 255, L_0431
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0431:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0438:
    Move 38, 4
    Move 18, 1
    Move 16, 8
    Move 20, 8
    MoveEnd

Movement_044C:
    Move 36, 4
    Move 16, 8
    Move 20, 8
    MoveEnd

Movement_045C:
    Move 0, 1
    MoveEnd
