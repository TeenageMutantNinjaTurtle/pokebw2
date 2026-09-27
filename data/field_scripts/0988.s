#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    ParentActorMsg 1024, 24, 2, 0

L_003A:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_00EF
    ParentActorMsg 1024, 25, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32801
    ListMenuAdd 26, 65535, 1
    ListMenuAdd 27, 65535, 2
    ListMenuAdd 28, 65535, 3
    ListMenuShow
    WorkCmpConst 0x8021, 1
    VMJumpIf 1, L_008D
    VMJump L_009D

L_008D:
    ParentActorMsg 1024, 29, 2, 0
    VMJump L_00E9

L_009D:
    WorkCmpConst 0x8021, 2
    VMJumpIf 1, L_00B0
    VMJump L_00C0

L_00B0:
    ParentActorMsg 1024, 30, 2, 0
    VMJump L_00E9

L_00C0:
    WorkCmpConst 0x8021, 3
    VMJumpIf 1, L_00D3
    VMJump L_00E1

L_00D3:
    MsgWinCloseAll
    WorkSetConst 0x8020, 1
    VMJump L_00E9

L_00E1:
    MsgWinCloseAll
    WorkSetConst 0x8020, 1

L_00E9:
    VMJump L_003A

L_00EF:
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 31, 2
    LastKeyWait
    InfoMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 32, 2
    LastKeyWait
    InfoMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 393
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0208
    ParentActorMsg 1024, 0, 0, 0
    WorkSetConst 0x8022, 0
    PlayerGetDir 0x8022
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_017D
    ActorCmdExec 0, Movement_0264
    VMJump L_01DA

L_017D:
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_019E
    ActorCmdExec 0, Movement_025C
    VMJump L_01DA

L_019E:
    VMStackPush 0x8022
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_01BF
    ActorCmdExec 0, Movement_0274
    VMJump L_01DA

L_01BF:
    VMStackPush 0x8022
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_01DA
    ActorCmdExec 0, Movement_026C

L_01DA:
    ActorCmdWait
    ParentActorMsg 1024, 1, 0, 0
    ParentActorMsg 1024, 2, 0, 0
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 393
    VMJump L_0249

L_0208:
    WorkSetConst 0x8023, 0
    RecordGet 119, 0x8023
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_023B
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0249

L_023B:
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0249:
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_025C:
    Move 48, 1
    MoveEnd

Movement_0264:
    Move 49, 1
    MoveEnd

Movement_026C:
    Move 50, 1
    MoveEnd

Movement_0274:
    Move 51, 1
    MoveEnd

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8024, 0
    VMStackPushFlag 2411
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02C5
    ActorMsg 1024, 6, 1, 2, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0540
    ActorCmdWait
    ActorMsg 1024, 7, 1, 2, 0
    FlagSet 2411

L_02C5:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0414
    VMStackPushFlag 394
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_031E
    VMStackPush 0x400a
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0312
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0318

L_0312:
    VMCall L_0420

L_0318:
    VMJump L_040E

L_031E:
    ParentActorMsg 1024, 17, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03FC
    WorkSetConst 0x8025, 0
    PokePartyGetCount 0x8025, 0
    VMStackPush 0x8025
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_0372
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_03F6

L_0372:
    ParentActorMsg 1024, 18, 0, 0
    MsgWinCloseAll
    PokePartyAddEx 0x8010, 133, 0, 10, 3, 0, 0, 0, 4
    WordSetPlayerName 0
    MEPlay 1304
    SystemMsg 19, 0
    MEWait
    MsgWaitAdvance
    InfoMsgClose
    SystemMsg 20, 0
    WorkSetConst 0x8026, 0
    YesNoWin 0x8026
    InfoMsgClose
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03DE
    WorkSetConst 0x8027, 0
    CallPokeNameInput 0x8027, 0x8025, 1
    VMJump L_03DE

L_03DE:
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 394
    WorkSetConst 0x400a, 1

L_03F6:
    VMJump L_040E

L_03FC:
    DebugPrint 0x8010
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_040E:
    VMJump L_041A

L_0414:
    VMCall L_0420

L_041A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0420:
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x8028, 0

L_0432:
    VMStackPush 0x8028
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_053C
    ActorMsg 1024, 8, 1, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32809
    ListMenuAdd 9, 65535, 1
    ListMenuAdd 10, 65535, 2
    ListMenuAdd 11, 65535, 3
    ListMenuAdd 12, 65535, 4
    ListMenuShow
    WorkCmpConst 0x8029, 1
    VMJumpIf 1, L_048F
    VMJump L_04A3

L_048F:
    ActorMsg 1024, 13, 1, 2, 0
    MsgWaitAdvance
    VMJump L_0536

L_04A3:
    WorkCmpConst 0x8029, 2
    VMJumpIf 1, L_04B6
    VMJump L_04CA

L_04B6:
    ActorMsg 1024, 14, 1, 2, 0
    MsgWaitAdvance
    VMJump L_0536

L_04CA:
    WorkCmpConst 0x8029, 3
    VMJumpIf 1, L_04DD
    VMJump L_04F1

L_04DD:
    ActorMsg 1024, 15, 1, 2, 0
    MsgWaitAdvance
    VMJump L_0536

L_04F1:
    WorkCmpConst 0x8029, 4
    VMJumpIf 1, L_0504
    VMJump L_0520

L_0504:
    ActorMsg 1024, 16, 1, 2, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8028, 1
    VMJump L_0536

L_0520:
    ActorMsg 1024, 16, 1, 2, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8028, 1

L_0536:
    VMJump L_0432

L_053C:
    VMReturn
    .balign 4, 0

Movement_0540:
    Move 75, 1
    MoveEnd
