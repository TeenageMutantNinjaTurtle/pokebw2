#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 405
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0039
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0106

L_0039:
    ParentActorMsg 1024, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00F8
    MsgWinCloseAll
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    CallPokeSelect 0, 0x8021, 0x8020, 0
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00E4
    WorkSetConst 0x8022, 0
    FieldTradeCheck 0x8022, 27, 0x8020
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00D0
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    FieldTradeStart 27, 0x8020
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 405
    VMJump L_00DE

L_00D0:
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_00DE:
    VMJump L_00F2

L_00E4:
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_00F2:
    VMJump L_0106

L_00F8:
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0106:
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
