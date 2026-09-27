#include "asm/field_script.inc"

// Script plugin 11, from the zones that use this file

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntry Script_9
    ScriptEntry Script_10
    ScriptEntry Script_11
    ScriptEntry Script_12
    ScriptEntry Script_13
    ScriptEntry Script_14
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

L_004C:
    WorkSetConst 0x8023, 0
    GameGetVersion 0x8023
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0079
    ObjInitWarpGPos 1, 0xff08, 80, 248
    VMJump L_0083

L_0079:
    ObjInitWarpGPos 0, 0xff08, 80, 248

L_0083:
    WorkSetConst 0x8023, 0
    VMReturn

Script_1:
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8025, 1
    TrainerCardHasBadge 0x8024, 0
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40e4
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00CC
    WorkSetConst 0x40e4, 1

L_00CC:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00E5
    WorkSetConst 0x8025, 0

L_00E5:
    TrainerCardHasBadge 0x8024, 1
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40e5
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0114
    WorkSetConst 0x40e5, 1

L_0114:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_012D
    WorkSetConst 0x8025, 0

L_012D:
    TrainerCardHasBadge 0x8024, 2
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40e6
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_015C
    WorkSetConst 0x40e6, 1

L_015C:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0175
    WorkSetConst 0x8025, 0

L_0175:
    TrainerCardHasBadge 0x8024, 3
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40e7
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_01A4
    WorkSetConst 0x40e7, 1

L_01A4:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01BD
    WorkSetConst 0x8025, 0

L_01BD:
    TrainerCardHasBadge 0x8024, 4
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40e8
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_01EC
    WorkSetConst 0x40e8, 1

L_01EC:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0205
    WorkSetConst 0x8025, 0

L_0205:
    TrainerCardHasBadge 0x8024, 5
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40e9
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0234
    WorkSetConst 0x40e9, 1

L_0234:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_024D
    WorkSetConst 0x8025, 0

L_024D:
    TrainerCardHasBadge 0x8024, 6
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40ea
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_027C
    WorkSetConst 0x40ea, 1

L_027C:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0295
    WorkSetConst 0x8025, 0

L_0295:
    TrainerCardHasBadge 0x8024, 7
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40eb
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_02C4
    WorkSetConst 0x40eb, 1

L_02C4:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02DD
    WorkSetConst 0x8025, 0

L_02DD:
    VMStackPush 0x40ec
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02F6
    WorkSetConst 0x40ec, 1

L_02F6:
    WorkGet 0x4000, 0x8025
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    VMCall L_004C
    VMHalt

Script_14:
    VMCall L_004C
    VMHalt

Script_2:
    ActorsPauseAll
    Plugin11_Cmd1000 0
    SystemMsg 10, 2
    LastKeyWait
    InfoMsgClose
    WorkSetConst 0x40e4, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    Plugin11_Cmd1000 1
    SystemMsg 11, 2
    LastKeyWait
    InfoMsgClose
    WorkSetConst 0x40e5, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    Plugin11_Cmd1000 2
    SystemMsg 12, 2
    LastKeyWait
    InfoMsgClose
    WorkSetConst 0x40e6, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    Plugin11_Cmd1000 3
    SystemMsg 13, 2
    LastKeyWait
    InfoMsgClose
    WorkSetConst 0x40e7, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    Plugin11_Cmd1000 4
    SystemMsg 14, 2
    LastKeyWait
    InfoMsgClose
    WorkSetConst 0x40e8, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    Plugin11_Cmd1000 5
    SystemMsg 15, 2
    LastKeyWait
    InfoMsgClose
    WorkSetConst 0x40e9, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    Plugin11_Cmd1000 6
    SystemMsg 16, 2
    LastKeyWait
    InfoMsgClose
    WorkSetConst 0x40ea, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    Plugin11_Cmd1000 7
    SystemMsg 17, 2
    LastKeyWait
    InfoMsgClose
    WorkSetConst 0x40eb, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    VMStackPush 0x4000
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_047C
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    ActorGetGPos 255, 0x8026, 0x8027
    VMStackPush 0x8026
    VMStackPushConst 31
    VMStackCmp 5
    VMStackPush 0x8027
    VMStackPushConst 44
    VMStackCmp 5
    VMStackCmp 6
    VMJumpIf 255, L_045E
    ActorWalkRoute 255, 31, 44, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 255, Movement_06A0
    ActorCmdWait

L_045E:
    VMCall L_0498
    Plugin11_Cmd1001
    VMCall L_049E
    WorkSetConst 0x40ec, 2
    FlagSet 2530
    VMJump L_0486

L_047C:
    ActorCmdExec 255, Movement_06AC
    ActorCmdWait

L_0486:
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0498:
    EvCameraInit
    EvCameraUnbind
    VMReturn

L_049E:
    EvCameraWait
    EvCameraMoveToDefault 30
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    VMReturn

Script_11:
    ActorsPauseAll
    ActorCmdExec 255, Movement_06C4
    ActorCmdWait
    ActorWalkRoute 255, 80, 50, 1, 8, 0
    ActorCmdWait
    VMSleep 16
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x508000, 0x5004f, 0x308000, 30
    ActorWalkRoute 0, 80, 47, 1, 14, 1
    ActorCmdWait
    EvCameraWait
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_06DC
    ActorCmdWait
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_06EC
    ActorCmdWait
    ActorMsg 1024, 2, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_06BC
    ActorCmdWait
    ActorCmdExec 0, Movement_06CC
    ActorCmdWait
    ActorMsg 1024, 3, 0, 0, 0
    ActorMsgVersioned 1024, 5, 4, 0, 0, 0
    VMCall L_05F8
    ActorMsg 1024, 7, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_06CC
    ActorCmdWait
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 424
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsgVersioned 1024, 9, 8, 0, 0, 0
    MsgWinCloseAll
    EvCameraMoveToDefault 30
    ActorWalkRoute 0, 81, 56, 1, 8, 0
    VMSleep 16
    ActorCmdExec 255, Movement_06EC
    ActorCmdWait
    ActorDelete 0
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    FlagSet 901
    WorkSetConst 0x410d, 1
    Cmd_0262 1, 37
    FlagSet 1031
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_05F8:
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802c, 0
    PokePartyGetCount 0x8028, 0

L_061C:
    VMStackPush 0x8028
    VMStackPush 0x8029
    VMStackCmp 2
    VMJumpIf 255, L_0667
    PokePartyGetParam 0x802b, 0x8029, 178
    VMStackPush 0x802b
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_065B
    PokePartyGetSpecies 0x802a, 0x8029
    WordSetPokeSpecies 0, 0x802a
    WorkSetConst 0x802c, 1

L_065B:
    WorkAdd 0x8029, 1
    VMJump L_061C

L_0667:
    VMStackPush 0x802c
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0694
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0698
    ActorCmdWait
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll

L_0694:
    VMReturn
    .balign 4, 0

Movement_0698:
    Move 75, 1
    MoveEnd

Movement_06A0:
    Move 32, 1
    Move 0, 1
    MoveEnd

Movement_06AC:
    Move 33, 1
    Move 1, 1
    Move 13, 1
    MoveEnd

Movement_06BC:
    Move 182, 1
    MoveEnd

Movement_06C4:
    Move 12, 1
    MoveEnd

Movement_06CC:
    Move 13, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_06DC:
    Move 34, 1
    MoveEnd
    Move 32, 1
    MoveEnd

Movement_06EC:
    Move 33, 1
    MoveEnd

Script_12:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 18, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 19, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
