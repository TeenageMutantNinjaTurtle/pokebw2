#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    VMStackPushFlag 259
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0035
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0114

L_0035:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 0, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0104
    ActorMsgClose
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    CallPokeSelect 0, 0x8021, 0x8020, 0
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00EE
    WorkSetConst 0x8022, 0
    FieldTradeCheck 0x8022, 28, 0x8020
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00D8
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    FieldTradeStart 28, 0x8020
    ActorMsg 1024, 2, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 259
    VMJump L_00E8

L_00D8:
    ActorMsg 1024, 3, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_00E8:
    VMJump L_00FE

L_00EE:
    ActorMsg 1024, 4, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_00FE:
    VMJump L_0114

L_0104:
    ActorMsg 1024, 4, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0114:
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
