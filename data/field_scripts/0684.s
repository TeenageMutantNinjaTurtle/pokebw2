#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    VMStackPushFlag 919
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4117
    VMStackPushConst 2
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0051
    FlagSet 919
    WorkSetConst 0x4117, 1

L_0051:
    VMHalt

Script_2:
    ActorsPauseAll
    WordSetPlayerName 0
    InfoMsg 3, 2
    SEPlay 1351
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00F0
    VMStackPushFlag 408
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0095
    FunfestMissionBroadcast 24, 0
    FlagSet 408

L_0095:
    Cmd_0240 64, 30
    SEPlay 1968
    InfoMsg 4, 2
    WorkSetConst 0x8023, 0
    BMCreateHandleByGPos 0x8023, 8, 16, 7
    BMHndAudioVisualAnmPlay 0x8023, 0
    BMHndAnmWait 0x8023
    BMReleaseHandle 0x8023
    SEWait
    Cmd_0241 60
    InfoMsg 5, 2
    LastKeyWait
    InfoMsgClose_0039
    VMStackPush 0x40ee
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_00EA
    WorkSetConst 0x40ee, 6

L_00EA:
    VMJump L_00F9

L_00F0:
    InfoMsg 7, 2
    LastKeyWait
    InfoMsgClose_0039

L_00F9:
    WorkSetConst 0x8023, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SystemMsg 0, 2
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01B0
    MsgWinCloseAll
    FlagReset 919
    WorkSetConst 0x4117, 2
    VMSleep 30
    PVPlay 481, 0
    InfoMsg 1, 2
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    PlayerGetGPos 0x8021, 0x8022
    ActorAdd 0
    ActorSetGPos 0, 24, 9, 26, 2
    WorkAdd 0x8022, 2
    ActorMoveLinear 0, 0x8021, 5, 0x8022, 48
    ActorSetGPos 0, 0x8021, 5, 0x8022, 2
    ActorCmdExec 0, Movement_0270
    VMSleep 8
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_01A4
    ActorCmdExec 255, Movement_0278

L_01A4:
    ActorCmdWait
    VMSleep 16
    VMJump L_01B2

L_01B0:
    MsgWinCloseAll

L_01B2:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 481, 0
    ScreamMsg 1, 2
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    CallWildBattle 481, 65, 1
    WildBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0206
    FlagSet 919
    WorkSetConst 0x4117, 3
    ActorDelete 0
    CallWildBattleEnd
    VMJump L_0208

L_0206:
    CallWildLose

L_0208:
    WildBattleGetResult 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_021F
    VMJump L_0229

L_021F:
    FlagSet 397
    VMJump L_0259

L_0229:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0249
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0249
    VMJump L_0259

L_0249:
    SystemMsg 2, 2
    LastKeyWait
    InfoMsgClose
    VMJump L_0259

L_0259:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 35, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_0270:
    Move 32, 1
    MoveEnd

Movement_0278:
    Move 33, 1
    MoveEnd
