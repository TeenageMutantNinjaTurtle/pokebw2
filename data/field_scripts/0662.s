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
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_4:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    BGMPlay 1087
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    WorkCmpConst 0x8022, 371
    VMJumpIf 1, L_005D
    VMJump L_006B

L_005D:
    ActorCmdExec 8, Movement_0184
    VMJump L_00F7

L_006B:
    WorkCmpConst 0x8022, 372
    VMJumpIf 1, L_007E
    VMJump L_008C

L_007E:
    ActorCmdExec 8, Movement_0190
    VMJump L_00F7

L_008C:
    WorkCmpConst 0x8022, 373
    VMJumpIf 1, L_009F
    VMJump L_00AD

L_009F:
    ActorCmdExec 8, Movement_019C
    VMJump L_00F7

L_00AD:
    WorkCmpConst 0x8022, 374
    VMJumpIf 1, L_00C0
    VMJump L_00CE

L_00C0:
    ActorCmdExec 8, Movement_01A4
    VMJump L_00F7

L_00CE:
    WorkCmpConst 0x8022, 375
    VMJumpIf 1, L_00E1
    VMJump L_00F7

L_00E1:
    ActorCmdExec 8, Movement_01B0
    ActorCmdExec 255, Movement_04A4
    VMJump L_00F7

L_00F7:
    ActorCmdWait
    ActorMsg 1024, 0, 8, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 8, 135, 370, 1, 8, 0
    ActorWalkRoute 255, 135, 371, 1, 8, 0
    ActorCmdWait
    WorkSetConst 0x8023, 0
    BMCreateHandleByGPos 0x8023, 1, 135, 369
    BMHndAudioVisualAnmPlay 0x8023, 0
    BMHndAnmWait 0x8023
    WorkSetConst 0x8023, 0
    ActorCmdExec 8, Movement_047C
    ActorCmdWait
    SEPlay 1369
    ActorDelete 8
    SEWait
    ActorCmdExec 255, Movement_01BC
    ActorCmdWait
    BGMChangeMap
    WorkSetConst 0x40c9, 2
    FlagSet 772
    RTReserveScript 3
    MapChangeWarp 332, 6, 9, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0184:
    Move 12, 2
    Move 15, 2
    MoveEnd

Movement_0190:
    Move 12, 1
    Move 15, 2
    MoveEnd

Movement_019C:
    Move 15, 2
    MoveEnd

Movement_01A4:
    Move 13, 1
    Move 15, 2
    MoveEnd

Movement_01B0:
    Move 13, 2
    Move 15, 2
    MoveEnd

Movement_01BC:
    Move 12, 2
    MoveEnd

Script_5:
    ActorsPauseAll
    FlagReset 773
    FlagReset 774
    ActorNew 110, 353, 1, 251, 369, 0
    PVPlay 638, 0
    ScreamMsg 1, 1
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_020E
    ActorCmdExec 255, Movement_04B4
    ActorCmdWait

L_020E:
    ActorCmdExec 255, Movement_04D4
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    ActorAnimationInit 251
    ActorAnimationPlay 0
    SEPlay 2264
    ActorAnimationWait
    SEWait
    VMSleep 30
    ActorMsg 1024, 1, 251, 0, 0
    PVPlay 638, 0
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll
    VMSleep 12
    ActorAnimationPlay 1
    SEPlay 2265
    ActorAnimationWait
    SEWait
    ActorAnimationFree
    ActorDelete 251
    ActorAdd 10
    ActorAdd 9
    PlayerGetGPos 0x8021, 0x8022
    ActorSetGPos 9, 102, 0, 372, 0
    VMSleep 30
    WorkAdd 0x8022, 2
    ActorWalkRoute 10, 103, 367, 1, 16, 1
    VMSleep 8
    ActorWalkRoute 9, 102, 367, 1, 16, 1
    VMSleep 30
    VMStackPush 0x8021
    VMStackPushConst 102
    VMStackCmp 1
    VMJumpIf 255, L_02C9
    ActorCmdExec 255, Movement_0398
    VMJump L_02F2

L_02C9:
    VMStackPush 0x8021
    VMStackPushConst 104
    VMStackCmp 1
    VMJumpIf 255, L_02EA
    ActorCmdExec 255, Movement_03A4
    VMJump L_02F2

L_02EA:
    ActorCmdExec 255, Movement_04BC

L_02F2:
    ActorCmdWait
    ActorMsg 1024, 2, 10, 6, 0
    MsgWinCloseAll
    ActorMsg 1024, 3, 9, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 4, 10, 6, 0
    MsgWinCloseAll
    ActorMsg 1024, 5, 9, 4, 0
    ActorMsg 1024, 6, 9, 4, 0
    MsgWinCloseAll
    ActorCmdExec 9, Movement_04DC
    ActorCmdWait
    ActorMsg 1024, 7, 9, 4, 0
    ActorMsg 1024, 8, 9, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 9, 10, 6, 0
    MsgWinCloseAll
    ActorCmdExec 10, Movement_047C
    ActorCmdWait
    ActorMsg 1024, 10, 10, 6, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 773
    FlagSet 774
    WorkSetConst 0x40ca, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0398:
    Move 15, 1
    Move 33, 1
    MoveEnd

Movement_03A4:
    Move 14, 1
    Move 33, 1
    MoveEnd

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 14, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 15, 0
    MsgPlaceSignClose
    FlagSet 2669
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 16, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    MoveEnd

Movement_047C:
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd

Movement_04A4:
    Move 2, 1
    MoveEnd
    Move 3, 1
    MoveEnd

Movement_04B4:
    Move 32, 1
    MoveEnd

Movement_04BC:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_04D4:
    Move 75, 1
    MoveEnd

Movement_04DC:
    Move 159, 1
    MoveEnd
