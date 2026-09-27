#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 11, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 12, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 445
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0073
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_020C

L_0073:
    ActorMsg 1024, 1, 0, 2, 0

L_007F:
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_020C
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32800
    ListMenuAdd 2, 65535, 0
    ListMenuAdd 3, 65535, 1
    ListMenuAdd 4, 65535, 2
    ListMenuShow
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_00C8
    VMJump L_013B

L_00C8:
    ActorMsg 1024, 5, 0, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0129
    ActorMsg 1024, 9, 0, 2, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 572
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 445
    WorkSetConst 0x8021, 1
    VMJump L_0135

L_0129:
    ActorMsg 1024, 7, 0, 2, 0

L_0135:
    VMJump L_0206

L_013B:
    WorkCmpConst 0x8020, 1
    VMJumpIf 1, L_014E
    VMJump L_01C1

L_014E:
    ActorMsg 1024, 6, 0, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01AF
    ActorMsg 1024, 10, 0, 2, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 573
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 445
    WorkSetConst 0x8021, 1
    VMJump L_01BB

L_01AF:
    ActorMsg 1024, 7, 0, 2, 0

L_01BB:
    VMJump L_0206

L_01C1:
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_01D4
    VMJump L_01F0

L_01D4:
    ActorMsg 1024, 8, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8021, 1
    VMJump L_0206

L_01F0:
    ActorMsg 1024, 8, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8021, 1

L_0206:
    VMJump L_007F

L_020C:
    VMStackPushFlag 447
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0223
    FlagSet 447

L_0223:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
