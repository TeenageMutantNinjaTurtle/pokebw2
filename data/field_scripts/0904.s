#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd

Script_5:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    CallPlaceNameDisp
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 723
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_006B
    ParentActorMsg 1024, 8, 0, 0
    VMJump L_0075

L_006B:
    ParentActorMsg 1024, 9, 0, 0

L_0075:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 4, 2, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00E0
    ActorMsg 1024, 5, 2, 2, 0
    MsgWinCloseAll
    FadeOutBlackQ
    BGMFadeOut 30
    FadeWait
    FieldClose
    Call3DDemo 26, 0
    FieldOpen
    RTReserveScript 3
    MapChangeCore 38, 12, 0, 10, 2
    VMJump L_00F0

L_00E0:
    ActorMsg 1024, 6, 2, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_00F0:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WordSetLoadRivalName 1
    ActorMsg 1024, 0, 3, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01C6
    ActorMsg 1024, 1, 3, 2, 0
    MsgWinCloseAll
    ActorCmdExec 3, Movement_01FC
    ActorCmdWait
    ActorMsg 1024, 2, 3, 2, 0
    MsgWinCloseAll
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_016E
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_016E
    VMJump L_017E

L_016E:
    ActorCmdExec 255, Movement_01FC
    ActorCmdWait
    VMJump L_017E

L_017E:
    ActorMsg 1024, 5, 2, 2, 0
    MsgWinCloseAll
    FadeOutBlackQ
    BGMFadeOut 30
    FadeWait
    FieldClose
    Call3DDemo 23, 0
    FieldOpen
    ActorDelete 3
    MapReplaceSetEvent 3, 1, 1
    MapChangeCore 38, 12, 0, 10, 2
    FlagSet 722
    WorkSetConst 0x40ae, 1
    VMJump L_01D6

L_01C6:
    ActorMsg 1024, 3, 3, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_01D6:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0
    Move 3, 1
    MoveEnd

Movement_01FC:
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
