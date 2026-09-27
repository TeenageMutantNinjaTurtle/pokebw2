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
    ScriptEntriesEnd

Script_9:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    VMStackPush 0x40cb
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_0045
    CallPlaceNameDisp
    DebugPrint 22

L_0045:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    CallPlaceNameDisp
    VMSleep 70
    ActorMsg 1024, 0, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0278
    ActorCmdWait
    ActorMsg 1024, 1, 2, 0, 0
    ActorMsgVersioned 1024, 3, 2, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0290
    ActorCmdWait
    ActorMsgVersioned 1024, 5, 4, 2, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 6, 5, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0278
    ActorCmdWait
    ActorMsgVersioned 1024, 8, 7, 2, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00F0
    ActorMsg 1024, 9, 2, 0, 0
    VMJump L_00FC

L_00F0:
    ActorMsg 1024, 10, 2, 0, 0

L_00FC:
    ActorMsg 1024, 11, 2, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 12, 5, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 5, 626, 306, 1, 8, 1
    VMSleep 8
    ActorCmdExec 255, Movement_0278
    ActorCmdWait
    ActorDelete 5
    FlagSet 777
    WorkSetConst 0x40cb, 2
    WorkSetConst 0x4120, 1
    Cmd_0262 3, 4
    Cmd_0262 0, 4
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01B3
    ParentActorMsg 1024, 19, 0, 0
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    FieldClose
    Call3DDemo 25, 0
    FieldOpen
    RTReserveScript 11
    MapChangeCore 111, 14, 0, 19, 1
    VMJump L_01C1

L_01B3:
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01C1:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 552, 0
    ParentActorMsg 1024, 17, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 21, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0278:
    Move 35, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 32, 1
    MoveEnd

Movement_0290:
    Move 33, 1
    MoveEnd
