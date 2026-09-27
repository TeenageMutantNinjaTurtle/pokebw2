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
    ScriptEntry Script_10
    ScriptEntry Script_11
    ScriptEntriesEnd

Script_11:
    VMStackPush 0x409e
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_004D
    ActorSetGPos 4, 7, 0, 13, 0

L_004D:
    VMHalt

Script_1:
    ActorsPauseAll
    FlagReset 1014
    WordSetPlayerName 0
    ActorCmdExec 1, Movement_03A8
    VMSleep 12
    ActorCmdExec 0, Movement_07CC
    ActorCmdExec 2, Movement_07CC
    ActorCmdWait
    ActorMsg 1024, 1, 1, 1, 0
    ActorMsgClose
    ActorCmdExec 255, Movement_03B4
    ActorCmdWait
    SEPlay 1768
    SEWait
    ActorAdd 4
    WorkSetConst 0x8020, 0
    BMCreateHandleByGPos 0x8020, 1, 7, 1
    BMHndAudioVisualAnmPlay 0x8020, 0
    BMHndAnmWait 0x8020
    ActorCmdExec 4, Movement_03BC
    ActorCmdExec 255, Movement_07EC
    ActorCmdWait
    BMHndAudioVisualAnmPlay 0x8020, 1
    BMHndAnmWait 0x8020
    BMReleaseHandle 0x8020
    ActorMsg 1024, 2, 4, 1, 0
    ActorMsgClose
    ActorCmdExec 4, Movement_03C4
    VMSleep 32
    ActorCmdExec 255, Movement_03E8
    VMSleep 40
    ActorCmdExec 1, Movement_07F4
    VMSleep 48
    ActorCmdExec 0, Movement_07F4
    ActorCmdExec 2, Movement_07F4
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 3, 4, 2, 0
    MultiMsg 6, 21, 3, 1
    VMSleep 10
    MultiMsg 7, 5, 5, 2
    VMSleep 10
    MultiMsg 8, 6, 1, 3
    VMSleep 30
    MsgWinCloseNo 1
    VMSleep 5
    MsgWinCloseNo 2
    VMSleep 5
    MsgWinCloseNo 3
    WordSetPlayerName 0
    WordSetMedalName 1, 1
    ActorMsg 1024, 4, 4, 2, 0
    MsgWinCloseAll
    MEPlay 1336
    MedalGetFieldEffectID 1, 0x400f
    PlayFieldEffect 0x400f
    MEWait
    WordSetPlayerName 0
    SystemMsg 0, 2
    InfoMsgClose
    WordSetPlayerName 0
    ActorMsg 1024, 5, 4, 2, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x409e, 3
    MedalAcknowledge 1, 1
    FlagSet 1014
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FlagReset 1014
    ActorCmdExec 1, Movement_03A8
    VMSleep 12
    ActorCmdExec 0, Movement_07CC
    ActorCmdExec 2, Movement_07CC
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 9, 1, 1, 0
    ActorMsgClose
    ActorCmdExec 255, Movement_03B4
    ActorCmdWait
    SEPlay 1768
    SEWait
    ActorAdd 4
    WorkSetConst 0x8021, 0
    BMCreateHandleByGPos 0x8021, 1, 7, 1
    BMHndAudioVisualAnmPlay 0x8021, 0
    BMHndAnmWait 0x8021
    ActorCmdExec 4, Movement_03BC
    ActorCmdExec 255, Movement_07EC
    ActorCmdWait
    BMHndAudioVisualAnmPlay 0x8021, 1
    BMHndAnmWait 0x8021
    BMReleaseHandle 0x8021
    ActorMsg 1024, 10, 4, 1, 0
    ActorMsgClose
    ActorCmdExec 4, Movement_03C4
    VMSleep 32
    ActorCmdExec 255, Movement_03E8
    VMSleep 40
    ActorCmdExec 1, Movement_07F4
    VMSleep 48
    ActorCmdExec 0, Movement_07F4
    ActorCmdExec 2, Movement_07F4
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 11, 4, 2, 0
    MultiMsg 14, 6, 0, 1
    VMSleep 10
    MultiMsg 15, 8, 5, 2
    VMSleep 10
    MultiMsg 16, 11, 10, 3
    VMSleep 30
    MsgWinCloseNo 1
    VMSleep 5
    MsgWinCloseNo 2
    VMSleep 5
    MsgWinCloseNo 3
    WordSetPlayerName 0
    WordSetMedalName 1, 6
    ActorMsg 1024, 12, 4, 2, 0
    MsgWinCloseAll
    MEPlay 1337
    MedalGetFieldEffectID 6, 0x400f
    PlayFieldEffect 0x400f
    MEWait
    WordSetPlayerName 0
    SystemMsg 0, 2
    InfoMsgClose
    MultiMsg 37, 9, 8, 1
    VMSleep 10
    MultiMsg 38, 3, 3, 2
    VMSleep 10
    MultiMsg 39, 12, 12, 3
    VMSleep 30
    MsgWinCloseNo 1
    MultiMsg 40, 14, 5, 4
    VMSleep 10
    MsgWinCloseNo 2
    MultiMsg 41, 3, 20, 5
    VMSleep 10
    MsgWinCloseNo 3
    MultiMsg 42, 16, 15, 6
    VMSleep 30
    MsgWinCloseNo 4
    VMSleep 5
    MsgWinCloseNo 5
    VMSleep 5
    MsgWinCloseNo 6
    WordSetPlayerName 0
    ActorMsg 1024, 13, 4, 2, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x409e, 5
    MedalAcknowledge 6, 1
    WorkSetConst 0x8021, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_03A8:
    Move 75, 1
    Move 32, 1
    MoveEnd

Movement_03B4:
    Move 13, 2
    MoveEnd

Movement_03BC:
    Move 13, 2
    MoveEnd

Movement_03C4:
    Move 13, 1
    Move 14, 1
    Move 13, 1
    Move 34, 1
    Move 14, 2
    Move 13, 9
    Move 15, 3
    Move 32, 1
    MoveEnd

Movement_03E8:
    Move 14, 3
    Move 13, 6
    Move 15, 3
    Move 13, 1
    MoveEnd

Script_10:
    ActorsPauseAll
    WordSetPlayerName 0
    VMStackPush 0x409e
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_042E
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0442

L_042E:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose

L_0442:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8022, 0
    MedalGetCount 7, 0x8022
    WordSetMedalRank 1, 0x8022
    WorkSetConst 0x8023, 0
    MedalGetCount 3, 0x8023
    WordSetNumber 0, 0x8023, 3
    WorkCmpConst 0x8022, 1
    VMJumpIf 1, L_0485
    VMJump L_0497

L_0485:
    ActorMsg 1024, 17, 1, 0, 0
    VMJump L_0512

L_0497:
    WorkCmpConst 0x8022, 2
    VMJumpIf 1, L_04AA
    VMJump L_04BC

L_04AA:
    ActorMsg 1024, 18, 1, 0, 0
    VMJump L_0512

L_04BC:
    WorkCmpConst 0x8022, 3
    VMJumpIf 1, L_04CF
    VMJump L_04E1

L_04CF:
    ActorMsg 1024, 19, 1, 0, 0
    VMJump L_0512

L_04E1:
    WorkCmpConst 0x8022, 4
    VMJumpIf 1, L_04F4
    VMJump L_0506

L_04F4:
    ActorMsg 1024, 20, 1, 0, 0
    VMJump L_0512

L_0506:
    ActorMsg 1024, 21, 1, 0, 0

L_0512:
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0

L_053C:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_065D
    ActorMsg 1024, 22, 0, 4, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32804
    ListMenuAdd 23, 65535, 0
    ListMenuAdd 24, 65535, 1
    ListMenuAdd 25, 65535, 2
    ListMenuAdd 26, 65535, 3
    ListMenuAdd 27, 65535, 4
    ListMenuAdd 28, 65535, 5
    ListMenuShow
    WorkCmpConst 0x8024, 0
    VMJumpIf 1, L_05A9
    VMJump L_05BB

L_05A9:
    ActorMsg 1024, 29, 0, 0, 0
    VMJump L_0657

L_05BB:
    WorkCmpConst 0x8024, 1
    VMJumpIf 1, L_05CE
    VMJump L_05E0

L_05CE:
    ActorMsg 1024, 30, 0, 0, 0
    VMJump L_0657

L_05E0:
    WorkCmpConst 0x8024, 2
    VMJumpIf 1, L_05F3
    VMJump L_0605

L_05F3:
    ActorMsg 1024, 31, 0, 0, 0
    VMJump L_0657

L_0605:
    WorkCmpConst 0x8024, 3
    VMJumpIf 1, L_0618
    VMJump L_062A

L_0618:
    ActorMsg 1024, 32, 0, 0, 0
    VMJump L_0657

L_062A:
    WorkCmpConst 0x8024, 4
    VMJumpIf 1, L_063D
    VMJump L_064F

L_063D:
    ActorMsg 1024, 33, 0, 0, 0
    VMJump L_0657

L_064F:
    MsgWinCloseAll
    WorkSetConst 0x8025, 1

L_0657:
    VMJump L_053C

L_065D:
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    VMStackPush 0x409e
    VMStackPushConst 1
    VMStackCmp 3
    VMJumpIf 255, L_069E
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 36, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_06F2

L_069E:
    VMStackPush 0x409e
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_06CB
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 35, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_06F2

L_06CB:
    VMStackPush 0x409e
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_06F2
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 34, 0, 0
    LastKeyWait
    ActorMsgClose

L_06F2:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 45, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    WordSetPlayerName 0
    WorkSetConst 0x8026, 0
    MedalGetCount 3, 0x8026
    WordSetNumber 1, 0x8026, 3
    WorkSetConst 0x8027, 0
    MedalGetCount 7, 0x8027
    WordSetMedalRank 2, 0x8027
    SEPlay 1351
    InfoMsg 46, 2
    LastKeyWait
    InfoMsgClose_0039
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 47, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40e2
    VMStackPushConst 6
    VMStackCmp 5
    VMStackPushFlag 312
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_07B7
    SEPlay 1690
    ParentActorMsg 1024, 43, 0, 0
    FlagSet 312
    WorkAdd 0x40e2, 1
    SEWait
    LastKeyWait
    MsgWinCloseAll
    VMJump L_07C5

L_07B7:
    ParentActorMsg 1024, 44, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_07C5:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_07CC:
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

Movement_07EC:
    Move 32, 1
    MoveEnd

Movement_07F4:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd
