#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd

Script_1:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0031
    FlagSet 820
    FlagReset 821
    FlagReset 822

L_0031:
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    VMStackPush 0x40ee
    VMStackPushConst 7
    VMStackCmp 1
    VMJumpIf 255, L_007E
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0092

L_007E:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose

L_0092:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40ee
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0112
    ParentActorMsg 1024, 3, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00FE
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40ee, 1
    FlagReset 823
    FlagReset 824
    FlagReset 825
    FlagReset 826
    VMJump L_010C

L_00FE:
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_010C:
    VMJump L_01C5

L_0112:
    VMStackPush 0x40ee
    VMStackPushConst 1
    VMStackCmp 4
    VMStackPush 0x40ee
    VMStackPushConst 5
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0149
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01C5

L_0149:
    VMStackPush 0x40ee
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_01A4
    ParentActorMsg 1024, 7, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 28
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40ee, 7
    VMJump L_01C5

L_01A4:
    VMStackPush 0x40ee
    VMStackPushConst 7
    VMStackCmp 1
    VMJumpIf 255, L_01C5
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01C5:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
