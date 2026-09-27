#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    Cmd_017A 36
    FinishAllEvents
    ActorsUnpauseAll
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
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    VMStackPushFlag 437
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0153
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 436
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00B4
    ParentActorMsg 1024, 4, 0, 0
    VMJump L_00C2

L_00B4:
    ParentActorMsg 1024, 3, 0, 0
    FlagSet 436

L_00C2:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_013F
    PokePartyAddEgg 0x8010, 440, 0
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_012B
    ParentActorMsg 1024, 7, 0, 0
    MsgWinCloseAll
    FlagSet 437
    WordSetPlayerName 0
    MEPlay 1317
    SystemMsg 9, 0
    MEWait
    MsgWaitAdvance
    MsgWinCloseAll
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0139

L_012B:
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0139:
    VMJump L_014D

L_013F:
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_014D:
    VMJump L_0167

L_0153:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose

L_0167:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
