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
    ScriptEntry Script_12
    ScriptEntry Script_13
    ScriptEntry Script_14
    ScriptEntry Script_15
    ScriptEntry Script_16
    ScriptEntry Script_17
    ScriptEntry Script_18
    ScriptEntry Script_19
    ScriptEntry Script_20
    ScriptEntry Script_21
    ScriptEntry Script_22
    ScriptEntry Script_23
    ScriptEntry Script_24
    ScriptEntry Script_25
    ScriptEntry Script_26
    ScriptEntry Script_27
    ScriptEntry Script_28
    ScriptEntry Script_29
    ScriptEntry Script_30
    ScriptEntry Script_31
    ScriptEntry Script_32
    ScriptEntry Script_33
    ScriptEntry Script_34
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

L_00A2:
    VMStackPushFlag 444
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00DD
    ObjInitWarpGPos 4, 0, 0, 0
    ObjInitWarpGPos 5, 0, 0, 0
    ObjInitWarpGPos 6, 0, 0, 0
    ObjInitWarpGPos 8, 0, 0, 0

L_00DD:
    VMReturn

Script_32:
    VMCall L_00A2
    VMCall L_025E
    VMHalt

Script_6:
    VMCall L_00A2
    GameGetVersion 0x8010
    VMStackPush 0x8010
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0116
    WorkSetConst 0x4020, 205
    VMJump L_011C

L_0116:
    WorkSetConst 0x4020, 151

L_011C:
    WorkSetConst 0x8024, 0
    TrainerCardGetSex 0x8024
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0145
    WorkSetConst 0x4021, 231
    VMJump L_014B

L_0145:
    WorkSetConst 0x4021, 240

L_014B:
    WorkSetConst 0x8024, 0
    Cmd_02B2 15, 0x400f
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4048
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 494
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_01A8
    FlagReset 794
    FlagSet 800
    WorkSetConst 0x413e, 1

L_01A8:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4048
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 494
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 800
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0209
    FlagSet 794
    FlagSet 800
    WorkSetConst 0x413e, 2

L_0209:
    VMCall L_0215
    FlagReset 494
    VMHalt

L_0215:
    Cmd_02B2 15, 0x400f
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4048
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_025C
    FlagSet 794
    FlagReset 800
    WorkSetConst 0x413e, 0

L_025C:
    VMReturn

L_025E:
    Cmd_02B2 15, 0x400f
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4048
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_02BC
    VMStackPushFlag 794
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02AE
    ActorDelete 0

L_02AE:
    FlagSet 794
    FlagReset 800
    WorkSetConst 0x413e, 0

L_02BC:
    VMReturn

Script_7:
    WorkSetConst 0x8025, 0
    GameGetVersion 0x8025
    VMStackPush 0x40d5
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x40d7
    VMStackPushConst 1
    VMStackCmp 0
    VMStackCmp 7
    VMJumpIf 255, L_02FB
    DebugPrint 9
    ActorSetGPos 13, 432, 0, 160, 2

L_02FB:
    VMStackPush 0x40d6
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 22
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0334
    DebugPrint 0
    ActorSetGPos 0, 418, 0xffff, 169, 1
    VMJump L_056F

L_0334:
    VMStackPush 0x40d6
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 23
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_036D
    DebugPrint 1
    ActorSetGPos 0, 418, 0, 169, 1
    VMJump L_056F

L_036D:
    VMStackPush 0x40d6
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 22
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_03A6
    DebugPrint 2
    ActorSetGPos 0, 418, 0, 162, 1
    VMJump L_056F

L_03A6:
    VMStackPush 0x40d6
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 23
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_03DF
    DebugPrint 3
    ActorSetGPos 0, 418, 0, 162, 1
    VMJump L_056F

L_03DF:
    VMStackPush 0x40d7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 22
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0424
    DebugPrint 4
    ActorSetGPos 0, 419, 0, 164, 1
    ActorSetGPos 19, 418, 0, 164, 1
    VMJump L_056F

L_0424:
    VMStackPush 0x40d7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 23
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0469
    DebugPrint 5
    ActorSetGPos 0, 419, 0, 162, 1
    ActorSetGPos 19, 418, 0, 162, 1
    VMJump L_056F

L_0469:
    VMStackPush 0x40d7
    VMStackPushConst 0
    VMStackCmp 5
    VMStackPush 0x40d7
    VMStackPushConst 6
    VMStackCmp 0
    VMStackPush 0x8025
    VMStackPushConst 22
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_04BE
    DebugPrint 6
    ActorSetGPos 0, 424, 0, 175, 0
    ActorSetGPos 5, 429, 0xffff, 179, 2
    VMJump L_056F

L_04BE:
    VMStackPush 0x40d7
    VMStackPushConst 0
    VMStackCmp 5
    VMStackPush 0x40d7
    VMStackPushConst 6
    VMStackCmp 0
    VMStackPush 0x8025
    VMStackPushConst 23
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0507
    DebugPrint 7
    ActorSetGPos 0, 424, 0, 175, 0
    VMJump L_056F

L_0507:
    VMStackPush 0x40d8
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_053C
    DebugPrint 8
    ActorSetGPos 8, 442, 0, 175, 2
    ActorSetGPos 0, 398, 0, 167, 0
    VMJump L_056F

L_053C:
    VMStackPush 0x40d8
    VMStackPushConst 2
    VMStackCmp 4
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_056F
    DebugPrint 9
    ActorSetGPos 0, 418, 0, 162, 1

L_056F:
    Cmd_02B2 15, 0x400f
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x413e
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 22
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_05CA
    ActorSetGPos 0, 418, 0xffff, 168, 1
    VMJump L_0619

L_05CA:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x413e
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 23
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0619
    ActorSetGPos 0, 418, 0, 168, 1

L_0619:
    WorkSetConst 0x8025, 0
    VMHalt

Script_8:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    ActorCmdExec 11, Movement_246C
    ActorCmdWait
    ActorCmdExec 11, Movement_2464
    ActorCmdWait
    WorkSub 0x8021, 2
    ActorWalkRoute 11, 0x8021, 0x8022, 0, 8, 1
    ActorCmdWait
    ActorMsg 1024, 0, 11, 0, 0
    ActorMsg 1024, 1, 11, 0, 0
    MsgWinCloseAll
    ActorCmdExec 11, Movement_245C
    ActorCmdWait
    ActorMsg 1024, 2, 11, 0, 0
    MsgWinCloseAll
    ActorCmdExec 11, Movement_2464
    ActorCmdWait
    ActorMsgGendered 1024, 3, 4, 11, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 11, 426, 0x8022, 0, 8, 0
    ActorCmdWait
    ActorDelete 11
    WorkSetConst 0x40d5, 1
    FlagSet 793
    FlagSet 2481
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    ActorWalkRoute 255, 405, 147, 0, 8, 0
    ActorCmdWait
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x1958000, 0, 0x918000, 24
    FlagReset 794
    FlagSet 799
    SEPlay 1369
    ActorAdd 0
    SEWait
    ActorWalkRoute 0, 405, 145, 0, 8, 0
    VMSleep 8
    ActorCmdExec 255, Movement_244C
    ActorCmdWait
    EvCameraWait
    ActorMsg 1024, 5, 0, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 0, 406, 154, 4, 8, 0
    VMSleep 24
    ActorCmdExec 255, Movement_2454
    ActorCmdWait
    EvCameraMoveToDefault 24
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    WorkSetConst 0x8026, 0
    GameGetVersion 0x8026
    VMStackPush 0x8026
    VMStackPushConst 22
    VMStackCmp 1
    VMJumpIf 255, L_0788
    ActorSetGPos 0, 418, 0xffff, 169, 1
    VMJump L_07A7

L_0788:
    VMStackPush 0x8026
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_07A7
    ActorSetGPos 0, 418, 0, 169, 1

L_07A7:
    WorkSetConst 0x40d6, 2
    WorkSetConst 0x8026, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 0, 418, 161, 4, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_2434
    ActorCmdWait
    WorkSetConst 0x40d6, 3
    WorkSetConst 0x40d9, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    ActorMsg 1024, 7, 0, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 0, 418, 160, 0, 8, 0
    ActorCmdWait
    WorkSetConst 0x8027, 0
    BMCreateHandleByGPos 0x8027, 1, 418, 159
    BMHndAudioVisualAnmPlay 0x8027, 0
    BMHndAnmWait 0x8027
    ActorCmdExec 0, Movement_2414
    ActorCmdWait
    SEPlay 1369
    ActorDelete 0
    SEWait
    BMHndAudioVisualAnmPlay 0x8027, 1
    BMHndAnmWait 0x8027
    BMReleaseHandle 0x8027
    WorkSetConst 0x40d6, 4
    FlagReset 800
    FlagSet 794
    WorkSetConst 0x8027, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_21:
    ActorsPauseAll
    ActorMsg 1024, 8, 0, 5, 0
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    WorkSetConst 0x8028, 0
    GameGetVersion 0x8028
    VMStackPush 0x8028
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_08B2
    FieldClose
    Call3DDemo 14, 0
    FieldOpen
    VMJump L_08BC

L_08B2:
    FieldClose
    Call3DDemo 15, 0
    FieldOpen

L_08BC:
    WorkSetConst 0x8028, 0
    FlagSet 444
    FlagReset 796
    FlagReset 795
    FlagSet 993
    FlagSet 1009
    FlagReset 1010
    MapReplaceSetEvent 0, 1, 1
    RTReserveScript 31
    GameGetVersion 0x8023
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_090F
    MapChangeCore 120, 418, 0, 162, 1
    VMJump L_091B

L_090F:
    MapChangeCore 120, 418, 0, 164, 1

L_091B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_31:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    GameGetVersion 0x8023
    ActorCmdExec 255, Movement_0E9C
    ActorCmdWait
    EvCameraInit
    EvCameraUnbind
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_096A
    EvCameraMoveTo 9688, 0, 0xed000, 0x1a28000, 0, 0xa28000, 1
    VMJump L_0982

L_096A:
    EvCameraMoveTo 9688, 0, 0xed000, 0x1a28000, 0, 0xa48000, 1

L_0982:
    EvCameraWait
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_09A9
    ActorSetGPos 255, 419, 0, 162, 1
    VMJump L_09B5

L_09A9:
    ActorSetGPos 255, 419, 0, 164, 1

L_09B5:
    ActorMsg 1024, 9, 0, 5, 0
    MsgWinCloseAll
    GameGetVersion 0x8023
    VMCall L_0D6C
    ActorMsg 1024, 10, 0, 5, 0
    MsgWinCloseAll
    PVPlay 612, 0
    ActorMsg 1024, 11, 251, 6, 0
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0EAC
    VMSleep 2
    SEPlay 1475
    ActorCmdWait
    SEWait
    ActorCmdExec 251, Movement_2474
    ActorCmdWait
    VMSleep 8
    ActorCmdExec 19, Movement_2474
    ActorCmdExec 0, Movement_246C
    ActorCmdWait
    ActorMsg 1024, 12, 0, 5, 0
    MsgWinCloseAll
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0A5C
    ActorWalkRoute 251, 419, 163, 4, 8, 1
    VMJump L_0A6A

L_0A5C:
    ActorWalkRoute 251, 419, 165, 4, 8, 1

L_0A6A:
    ActorCmdWait
    VMCall L_0E10
    ActorMsg 1024, 13, 0, 5, 0
    MsgWinCloseAll
    InfoMsg 14, 2
    MsgWinCloseAll
    BGMPlay 1240
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0AF4
    ActorSetGPos 2, 419, 0, 169, 0
    ActorSetGPos 1, 419, 0, 170, 0
    ActorSetGPos 4, 419, 0, 171, 0
    ActorWalkRoute 2, 417, 164, 4, 8, 1
    ActorWalkRoute 1, 418, 164, 4, 8, 1
    ActorWalkRoute 4, 419, 164, 4, 8, 1
    ActorCmdWait
    VMJump L_0B44

L_0AF4:
    ActorSetGPos 2, 419, 0, 171, 0
    ActorSetGPos 1, 419, 0, 172, 0
    ActorSetGPos 4, 419, 0, 173, 0
    ActorWalkRoute 2, 417, 166, 4, 8, 1
    ActorWalkRoute 1, 418, 166, 4, 8, 1
    ActorWalkRoute 4, 419, 166, 4, 8, 1
    ActorCmdWait

L_0B44:
    ActorCmdExec 2, Movement_244C
    ActorCmdExec 1, Movement_244C
    ActorCmdExec 4, Movement_244C
    ActorCmdWait
    ActorMsg 1024, 15, 0, 5, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0D58
    ActorCmdWait
    ActorMsg 1024, 16, 1, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 17, 1, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 18, 0, 5, 0
    MsgWinCloseAll
    ActorMsg 1024, 19, 1, 4, 0
    MsgWinCloseAll
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0BF3
    ActorWalkRoute 2, 419, 171, 4, 8, 1
    ActorWalkRoute 1, 419, 172, 4, 8, 1
    ActorWalkRoute 4, 419, 173, 4, 8, 1
    ActorCmdWait
    VMJump L_0C1F

L_0BF3:
    ActorWalkRoute 2, 419, 173, 4, 8, 1
    ActorWalkRoute 1, 419, 174, 4, 8, 1
    ActorWalkRoute 4, 419, 175, 4, 8, 1
    ActorCmdWait

L_0C1F:
    BGMChangeMap
    ActorDelete 1
    ActorMsg 1024, 20, 0, 5, 0
    ActorCmdExec 19, Movement_2464
    ActorCmdExec 0, Movement_245C
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 21, 0, 5, 0
    MsgWinCloseAll
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0C7B
    ActorWalkRoute 0, 421, 171, 1, 8, 1
    VMJump L_0C89

L_0C7B:
    ActorWalkRoute 0, 420, 170, 1, 8, 1

L_0C89:
    VMSleep 16
    ActorCmdExec 19, Movement_2454
    ActorCmdWait
    ActorSetGPos 0, 424, 0, 175, 0
    ActorSetGPos 2, 430, 0, 168, 1
    ActorSetGPos 4, 424, 0, 145, 1
    VMStackPush 0x8023
    VMStackPushConst 22
    VMStackCmp 1
    VMJumpIf 255, L_0CDA
    ActorSetGPos 5, 429, 0xffff, 179, 2

L_0CDA:
    BGMPlay 1241
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0D03
    ActorSetGPos 255, 418, 0, 162, 1
    VMJump L_0D0F

L_0D03:
    ActorSetGPos 255, 418, 0, 164, 1

L_0D0F:
    ActorCmdExec 255, Movement_0EA4
    ActorCmdWait
    EvCameraMoveToDefault 1
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorDelete 19
    WorkSetConst 0x40d7, 2
    FlagSet 795
    FlagSet 1034
    FlagSet 2546
    FlagReset 2553
    Cmd_0262 1, 25
    BGMAmbienceResume
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 75, 1
    Move 32, 1
    MoveEnd

Movement_0D58:
    Move 30, 1
    Move 31, 1
    Move 30, 1
    Move 32, 1
    MoveEnd

L_0D6C:
    GameGetVersion 0x8023
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0DA1
    Cmd_020E 0, 419, 0, 163, 3, 8
    Cmd_020F 0, 419, 0, 163
    VMJump L_0DB9

L_0DA1:
    Cmd_020E 0, 419, 0, 165, 3, 8
    Cmd_020F 0, 419, 0, 165

L_0DB9:
    Cmd_0211 0
    FadeEx 12, 0, 16, 2
    FadeExWait
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0DF0
    ActorNew 419, 163, 1, 251, 322, 0
    VMJump L_0DFE

L_0DF0:
    ActorNew 419, 165, 1, 251, 322, 0

L_0DFE:
    FadeEx 12, 16, 0, 2
    FadeExWait
    Cmd_0210 0
    VMReturn

L_0E10:
    GameGetVersion 0x8023
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0E37
    Cmd_020F 1, 419, 0, 163
    VMJump L_0E41

L_0E37:
    Cmd_020F 1, 419, 0, 165

L_0E41:
    Cmd_0211 1
    FadeEx 12, 0, 16, 2
    FadeExWait
    ActorDelete 251
    FadeEx 12, 16, 0, 2
    FadeExWait
    Cmd_0210 1
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0E8C
    Cmd_020E 1, 419, 3, 163, 3, 8
    VMJump L_0E9A

L_0E8C:
    Cmd_020E 1, 419, 3, 165, 3, 8

L_0E9A:
    VMReturn

Movement_0E9C:
    Move 69, 1
    MoveEnd

Movement_0EA4:
    Move 70, 1
    MoveEnd

Movement_0EAC:
    Move 13, 1
    Move 60, 1
    Move 3, 1
    Move 60, 1
    Move 0, 1
    Move 60, 1
    Move 2, 1
    Move 60, 1
    Move 1, 1
    Move 60, 1
    MoveEnd

L_0ED8:
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 404
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 145
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0F1B
    ActorCmdExec 0, Movement_245C
    VMSleep 4
    ActorCmdExec 255, Movement_2464
    VMJump L_0F83

L_0F1B:
    VMStackPush 0x8021
    VMStackPushConst 406
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 145
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0F58
    ActorCmdExec 0, Movement_2464
    VMSleep 4
    ActorCmdExec 255, Movement_245C
    VMJump L_0F83

L_0F58:
    VMStackPush 0x8021
    VMStackPushConst 405
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 146
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0F83
    ActorCmdExec 255, Movement_244C

L_0F83:
    ActorCmdWait
    ActorMsg 1024, 40, 0, 1, 0
    MsgWinCloseAll
    SEPlay 1391
    SEWait
    PokePartyRecoverAll
    ActorMsg 1024, 41, 0, 1, 0
    MsgWinCloseAll
    GameGetVersion 0x8023
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0FCE
    ActorCmdExec 0, Movement_13AC
    VMJump L_0FD6

L_0FCE:
    ActorCmdExec 0, Movement_139C

L_0FD6:
    VMSleep 4
    VMStackPush 0x8021
    VMStackPushConst 405
    VMStackCmp 5
    VMJumpIf 255, L_0FF5
    ActorCmdExec 255, Movement_244C

L_0FF5:
    ActorCmdWait
    SEPlay 1369
    ActorDelete 0
    SEWait
    VMSleep 8
    SEPlay 1369
    ActorAdd 0
    SEWait
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_1030
    ActorCmdExec 0, Movement_13B4
    VMJump L_1038

L_1030:
    ActorCmdExec 0, Movement_13A4

L_1038:
    ActorCmdWait
    VMStackPush 0x8021
    VMStackPushConst 404
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 145
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_1079
    ActorCmdExec 0, Movement_245C
    VMSleep 4
    ActorCmdExec 255, Movement_2464
    ActorCmdWait
    VMJump L_10B2

L_1079:
    VMStackPush 0x8021
    VMStackPushConst 406
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 145
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_10B2
    ActorCmdExec 0, Movement_2464
    VMSleep 4
    ActorCmdExec 255, Movement_245C
    ActorCmdWait

L_10B2:
    WordSetPlayerName 0
    ActorMsg 1024, 42, 0, 1, 0
    ActorMsg 1024, 43, 0, 1, 0
    MsgWinCloseAll
    SEPlay 1780
    Cmd_022D 628
    SEWait
    ActorMsg 1024, 44, 0, 1, 0
    MsgWinCloseAll
    ActorAdd 8
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_1110
    ActorSetGPos 8, 403, 0, 147, 1
    VMJump L_111C

L_1110:
    ActorSetGPos 8, 404, 0, 148, 1

L_111C:
    ActorCmdExec 8, Movement_13C8
    ActorCmdWait
    BGMPlay 1239
    VMStackPush 0x8021
    VMStackPushConst 405
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 146
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_1163
    ActorCmdExec 0, Movement_246C
    ActorCmdExec 255, Movement_13BC
    VMJump L_1175

L_1163:
    ActorCmdExec 255, Movement_13BC
    ActorCmdExec 0, Movement_13BC
    ActorCmdWait

L_1175:
    ActorMsg 1024, 45, 8, 2, 0
    MsgWinCloseAll
    ActorMsg 1024, 46, 0, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 47, 8, 2, 0
    MsgWinCloseAll
    ActorAdd 9
    ActorAdd 10
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_11D8
    ActorSetGPos 9, 408, 0, 145, 2
    ActorSetGPos 10, 408, 0, 146, 2
    VMJump L_11F0

L_11D8:
    ActorSetGPos 9, 403, 0, 147, 3
    ActorSetGPos 10, 408, 0, 147, 2

L_11F0:
    ActorCmdExec 9, Movement_13C8
    ActorCmdExec 10, Movement_13C8
    ActorCmdWait
    VMSleep 40
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_1237
    ActorCmdExec 8, Movement_1450
    ActorCmdExec 9, Movement_14A4
    ActorCmdExec 10, Movement_14C8
    VMJump L_124F

L_1237:
    ActorCmdExec 8, Movement_13E0
    ActorCmdExec 9, Movement_1420
    ActorCmdExec 10, Movement_1428

L_124F:
    ActorCmdWait
    ActorDelete 9
    ActorDelete 10
    ActorCmdWait
    VMStackPush 0x8021
    VMStackPushConst 405
    VMStackCmp 1
    VMJumpIf 255, L_1278
    ActorCmdExec 255, Movement_244C
    ActorCmdWait

L_1278:
    ActorMsg 1024, 48, 0, 1, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    GameGetVersion 0x8023
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMStackPush 0x8021
    VMStackPushConst 405
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_12C1
    ActorCmdExec 0, Movement_14EC
    VMJump L_134E

L_12C1:
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMStackPush 0x8021
    VMStackPushConst 405
    VMStackCmp 5
    VMStackCmp 7
    VMJumpIf 255, L_12F2
    ActorCmdExec 0, Movement_151C
    VMJump L_134E

L_12F2:
    VMStackPush 0x8023
    VMStackPushConst 22
    VMStackCmp 1
    VMStackPush 0x8021
    VMStackPushConst 405
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_1323
    ActorCmdExec 0, Movement_1440
    VMJump L_134E

L_1323:
    VMStackPush 0x8023
    VMStackPushConst 22
    VMStackCmp 1
    VMStackPush 0x8021
    VMStackPushConst 405
    VMStackCmp 5
    VMStackCmp 7
    VMJumpIf 255, L_134E
    ActorCmdExec 0, Movement_1430

L_134E:
    VMStackPush 0x8021
    VMStackPushConst 405
    VMStackCmp 1
    VMJumpIf 255, L_136D
    VMSleep 20
    ActorCmdExec 255, Movement_2454

L_136D:
    ActorCmdWait
    ActorSetGPos 0, 398, 0, 167, 0
    ActorSetMoveCode 0, 5
    ActorSetGPos 8, 442, 0, 175, 2
    BGMChangeMap
    WorkSetConst 0x40d8, 1
    FlagSet 798
    VMReturn
    .balign 4, 0

Movement_139C:
    Move 16, 1
    MoveEnd

Movement_13A4:
    Move 17, 1
    MoveEnd

Movement_13AC:
    Move 16, 1
    MoveEnd

Movement_13B4:
    Move 17, 1
    MoveEnd

Movement_13BC:
    Move 33, 1
    Move 75, 1
    MoveEnd

Movement_13C8:
    Move 70, 1
    Move 184, 1
    MoveEnd

Movement_13D4:
    Move 185, 1
    Move 69, 1
    MoveEnd

Movement_13E0:
    Move 17, 2
    Move 71, 1
    Move 17, 1
    Move 73, 1
    Move 17, 2
    Move 74, 1
    Move 72, 1
    Move 2, 1
    Move 71, 1
    Move 18, 1
    Move 73, 1
    Move 18, 1
    Move 74, 1
    Move 72, 1
    Move 17, 5
    MoveEnd

Movement_1420:
    Move 17, 9
    MoveEnd

Movement_1428:
    Move 19, 6
    MoveEnd

Movement_1430:
    Move 17, 5
    Move 18, 3
    Move 17, 4
    MoveEnd

Movement_1440:
    Move 18, 3
    Move 17, 5
    Move 17, 4
    MoveEnd

Movement_1450:
    Move 71, 1
    Move 17, 1
    Move 73, 1
    Move 17, 1
    Move 74, 1
    Move 72, 1
    Move 3, 1
    Move 71, 1
    Move 19, 1
    Move 73, 1
    Move 19, 3
    Move 74, 1
    Move 72, 1
    Move 17, 3
    Move 71, 1
    Move 17, 1
    Move 73, 1
    Move 17, 1
    Move 74, 1
    Move 72, 1
    MoveEnd

Movement_14A4:
    Move 19, 1
    Move 71, 1
    Move 19, 1
    Move 73, 1
    Move 19, 3
    Move 74, 1
    Move 72, 1
    Move 19, 3
    MoveEnd

Movement_14C8:
    Move 19, 1
    Move 71, 1
    Move 19, 1
    Move 73, 1
    Move 19, 5
    Move 74, 1
    Move 72, 1
    Move 19, 2
    MoveEnd

Movement_14EC:
    Move 19, 2
    Move 17, 3
    Move 74, 1
    Move 72, 1
    Move 17, 3
    Move 71, 1
    Move 17, 1
    Move 73, 1
    Move 17, 2
    Move 74, 1
    Move 72, 1
    MoveEnd

Movement_151C:
    Move 17, 4
    Move 3, 1
    Move 19, 2
    Move 74, 1
    Move 72, 1
    Move 17, 3
    Move 71, 1
    Move 17, 1
    Move 73, 1
    Move 17, 2
    Move 74, 1
    Move 72, 1
    MoveEnd

Script_34:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    BGMPlay 1239
    VMCall L_15B7
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    BGMPlay 1239
    PlayerGetGPos 0x8021, 0x8022
    PlayerGetDir 0x8020
    WorkAdd 0x8021, 1
    ActorWalkRoute 8, 0x8021, 0x8022, 4, 4, 1
    ActorCmdWait
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_15AB
    ActorCmdExec 255, Movement_2464
    ActorCmdWait

L_15AB:
    VMCall L_15B7
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_15B7:
    ActorMsg 1024, 50, 8, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 583, 0, 0
    VMCall L_1EF9
    PlayerGetGPos 0x8021, 0x8022
    ActorMsg 1024, 51, 8, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 177
    VMStackCmp 1
    VMJumpIf 255, L_1612
    ActorSetGPos 0, 431, 0, 176, 3
    VMJump L_1624

L_1612:
    WorkAdd 0x8022, 1
    ActorSetGPos 0, 431, 0, 0x8022, 3

L_1624:
    ActorSetMoveCode 0, 0
    PlayerGetGPos 0x8021, 0x8022
    WorkCmpConst 0x8022, 173
    VMJumpIf 1, L_1643
    VMJump L_1651

L_1643:
    ActorCmdExec 0, Movement_1A68
    VMJump L_16D5

L_1651:
    WorkCmpConst 0x8022, 174
    VMJumpIf 1, L_1664
    VMJump L_1672

L_1664:
    ActorCmdExec 0, Movement_1A88
    VMJump L_16D5

L_1672:
    WorkCmpConst 0x8022, 175
    VMJumpIf 1, L_1685
    VMJump L_1693

L_1685:
    ActorCmdExec 0, Movement_1AA8
    VMJump L_16D5

L_1693:
    WorkCmpConst 0x8022, 176
    VMJumpIf 1, L_16A6
    VMJump L_16B4

L_16A6:
    ActorCmdExec 0, Movement_1AC8
    VMJump L_16D5

L_16B4:
    WorkCmpConst 0x8022, 177
    VMJumpIf 1, L_16C7
    VMJump L_16D5

L_16C7:
    ActorCmdExec 0, Movement_1AA8
    VMJump L_16D5

L_16D5:
    VMSleep 16
    ActorCmdExec 8, Movement_13D4
    ActorCmdWait
    ActorDelete 8
    BGMChangeMap
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 441
    VMStackCmp 4
    VMJumpIf 255, L_1712
    ActorWalkRoute 255, 440, 0x8022, 4, 8, 0
    ActorCmdWait

L_1712:
    VMStackPush 0x8022
    VMStackPushConst 177
    VMStackCmp 1
    VMJumpIf 255, L_173B
    ActorCmdExec 0, Movement_2454
    ActorCmdExec 255, Movement_244C
    VMJump L_174B

L_173B:
    ActorCmdExec 0, Movement_244C
    ActorCmdExec 255, Movement_2454

L_174B:
    ActorCmdWait
    WordSetPlayerName 0
    VMStackPush 0x8022
    VMStackPushConst 177
    VMStackCmp 1
    VMJumpIf 255, L_1775
    ActorMsg 1024, 52, 0, 3, 0
    VMJump L_1781

L_1775:
    ActorMsg 1024, 52, 0, 4, 0

L_1781:
    MsgWinCloseAll
    MEPlay 1327
    SystemMsg 53, 2
    MEWait
    InfoMsgClose
    WordSetPlayerName 0
    SystemMsg 54, 2
    InfoMsgClose
    FadeOutBlackQ
    FadeWait
    CallXTransceiver 5, 0
    FadeInBlackQ
    FadeWait
    VMStackPush 0x8022
    VMStackPushConst 177
    VMStackCmp 1
    VMJumpIf 255, L_17CF
    ActorMsg 1024, 55, 0, 3, 0
    VMJump L_17DB

L_17CF:
    ActorMsg 1024, 55, 0, 4, 0

L_17DB:
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    SEPlay 1369
    ActorNew 446, 175, 2, 251, 223, 0
    SEWait
    BGMPlay 1087
    ActorCmdExec 0, Movement_2464
    ActorCmdExec 255, Movement_2464
    ActorCmdWait
    ActorWalkRoute 251, 442, 0x8022, 4, 4, 0
    ActorCmdWait
    VMStackPush 0x8022
    VMStackPushConst 175
    VMStackCmp 5
    VMJumpIf 255, L_183A
    ActorCmdExec 251, Movement_245C
    ActorCmdWait

L_183A:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    VMStackPush 0x8022
    VMStackPushConst 177
    VMStackCmp 1
    VMJumpIf 255, L_1865
    ActorMsg 1024, 56, 251, 6, 0
    VMJump L_1871

L_1865:
    ActorMsg 1024, 56, 251, 5, 0

L_1871:
    MsgWinCloseAll
    VMStackPush 0x8022
    VMStackPushConst 177
    VMStackCmp 1
    VMJumpIf 255, L_1898
    ActorMsg 1024, 57, 0, 3, 0
    VMJump L_18A4

L_1898:
    ActorMsg 1024, 57, 0, 4, 0

L_18A4:
    MsgWinCloseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    VMStackPush 0x8022
    VMStackPushConst 177
    VMStackCmp 1
    VMJumpIf 255, L_18D1
    ActorMsg 1024, 58, 251, 6, 0
    VMJump L_18DD

L_18D1:
    ActorMsg 1024, 58, 251, 5, 0

L_18DD:
    MsgWinCloseAll
    VMStackPush 0x8022
    VMStackPushConst 177
    VMStackCmp 1
    VMJumpIf 255, L_1904
    ActorMsg 1024, 59, 0, 3, 0
    VMJump L_1910

L_1904:
    ActorMsg 1024, 59, 0, 4, 0

L_1910:
    MsgWinCloseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    VMStackPush 0x8022
    VMStackPushConst 177
    VMStackCmp 1
    VMJumpIf 255, L_193D
    ActorMsg 1024, 60, 251, 6, 0
    VMJump L_1949

L_193D:
    ActorMsg 1024, 60, 251, 5, 0

L_1949:
    MsgWinCloseAll
    VMStackPush 0x8022
    VMStackPushConst 173
    VMStackCmp 1
    VMJumpIf 255, L_1972
    ActorWalkRoute 251, 446, 174, 4, 4, 1
    VMJump L_19A7

L_1972:
    VMStackPush 0x8022
    VMStackPushConst 177
    VMStackCmp 1
    VMJumpIf 255, L_1999
    ActorWalkRoute 251, 446, 176, 4, 4, 1
    VMJump L_19A7

L_1999:
    ActorWalkRoute 251, 446, 0x8022, 4, 4, 1

L_19A7:
    ActorCmdWait
    BGMChangeMap
    SEPlay 1369
    ActorDelete 251
    SEWait
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 177
    VMStackCmp 1
    VMJumpIf 255, L_19EA
    ActorCmdExec 0, Movement_2454
    ActorCmdExec 255, Movement_244C
    VMJump L_19FA

L_19EA:
    ActorCmdExec 0, Movement_244C
    ActorCmdExec 255, Movement_2454

L_19FA:
    ActorCmdWait
    VMStackPush 0x8022
    VMStackPushConst 177
    VMStackCmp 1
    VMJumpIf 255, L_1A21
    ActorMsg 1024, 61, 0, 3, 0
    VMJump L_1A2D

L_1A21:
    ActorMsg 1024, 61, 0, 4, 0

L_1A2D:
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40d8, 2
    FlagSet 797
    WorkSetConst 0x411e, 1
    FlagSet 947
    FlagReset 986
    FlagSet 775
    WorkSetConst 0x40de, 1
    WorkSetConst 0x4146, 1
    Cmd_0262 1, 26
    Cmd_0262 2, 7
    VMReturn
    .balign 4, 0

Movement_1A68:
    Move 71, 1
    Move 19, 1
    Move 73, 1
    Move 19, 1
    Move 74, 1
    Move 72, 1
    Move 19, 7
    MoveEnd

Movement_1A88:
    Move 71, 1
    Move 19, 1
    Move 73, 1
    Move 19, 4
    Move 74, 1
    Move 72, 1
    Move 19, 4
    MoveEnd

Movement_1AA8:
    Move 71, 1
    Move 19, 1
    Move 73, 1
    Move 19, 5
    Move 74, 1
    Move 72, 1
    Move 19, 3
    MoveEnd

Movement_1AC8:
    Move 71, 1
    Move 19, 1
    Move 73, 1
    Move 19, 6
    Move 74, 1
    Move 72, 1
    Move 19, 2
    MoveEnd

Script_13:
    ActorsPauseAll
    WordSetPlayerName 0
    TrainerCardHasBadge 0x8008, 7
    VMStackPush 0x413e
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1B34
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 82, 0, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    RTReserveScript 1
    FadeWait
    MapChangeCore 601, 9, 0, 9, 1
    VMJump L_1C2F

L_1B34:
    VMStackPush 0x40d7
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_1B61
    SEPlay 1351
    ActorMsg 1024, 34, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_1C2F

L_1B61:
    VMStackPush 0x8008
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_1B9E
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 62, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_1C2F

L_1B9E:
    VMStackPush 0x40d7
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x40d8
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_1BDB
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 35, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_1C2F

L_1BDB:
    VMStackPush 0x40d8
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1C08
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 49, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_1C2F

L_1C08:
    VMStackPush 0x40d8
    VMStackPushConst 2
    VMStackCmp 4
    VMJumpIf 255, L_1C2F
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 61, 0, 0
    LastKeyWait
    ActorMsgClose

L_1C2F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    BGMPlayPush 1240
    ActorMsg 1024, 38, 1, 0, 0
    ActorMsgClose
    CallTrainerBattle 584, 0, 0
    VMCall L_1EF9
    ActorMsg 1024, 39, 1, 0, 0
    ActorMsgClose
    GameGetVersion 0x8023
    FadeEx 3, 0, 16, 4
    FadeExWait
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_1CAA
    ActorSetGPos 0, 405, 0, 145, 1
    ActorCmdExec 255, Movement_2434
    ActorCmdWait
    VMJump L_1CC0

L_1CAA:
    ActorSetGPos 0, 405, 0, 145, 1
    ActorCmdExec 255, Movement_2434
    ActorCmdWait

L_1CC0:
    ActorDelete 1
    ActorDelete 2
    ActorDelete 3
    ActorDelete 5
    ActorDelete 6
    ActorDelete 4
    ActorDelete 7
    FlagSet 795
    FlagSet 796
    FlagReset 797
    FlagReset 798
    WorkAdd 0x40d7, 1
    FadeEx 3, 16, 0, 4
    FadeExWait
    VMCall L_0ED8
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerFlagGet 585, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1D70
    TrainerBGMPlayPush 585
    ActorMsg 1024, 22, 2, 0, 0
    ActorMsgClose
    CallTrainerBattle 585, 0, 0
    VMCall L_1EF9
    WorkAdd 0x40d7, 1
    TrainerFlagSet 585
    VMStackPush 0x40d7
    VMStackPushConst 5
    VMStackCmp 4
    VMJumpIf 255, L_1D70
    FlagReset 795
    ActorAdd 1

L_1D70:
    VMStackPush 0x40d7
    VMStackPushConst 5
    VMStackCmp 4
    VMJumpIf 255, L_1D99
    ActorMsg 1024, 24, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_1DA9

L_1D99:
    ActorMsg 1024, 23, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_1DA9:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerFlagGet 586, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1E15
    TrainerBGMPlayPush 586
    ActorMsg 1024, 25, 3, 0, 0
    ActorMsgClose
    CallTrainerBattle 586, 0, 0
    VMCall L_1EF9
    WorkAdd 0x40d7, 1
    TrainerFlagSet 586
    VMStackPush 0x40d7
    VMStackPushConst 5
    VMStackCmp 4
    VMJumpIf 255, L_1E15
    FlagReset 795
    ActorAdd 1

L_1E15:
    VMStackPush 0x40d7
    VMStackPushConst 5
    VMStackCmp 4
    VMJumpIf 255, L_1E3E
    ActorMsg 1024, 27, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_1E4E

L_1E3E:
    ActorMsg 1024, 26, 3, 0, 0
    LastKeyWait
    ActorMsgClose

L_1E4E:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerFlagGet 587, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1EBA
    TrainerBGMPlayPush 587
    ActorMsg 1024, 28, 4, 0, 0
    ActorMsgClose
    CallTrainerBattle 587, 0, 0
    VMCall L_1EF9
    WorkAdd 0x40d7, 1
    TrainerFlagSet 587
    VMStackPush 0x40d7
    VMStackPushConst 5
    VMStackCmp 4
    VMJumpIf 255, L_1EBA
    FlagReset 795
    ActorAdd 1

L_1EBA:
    VMStackPush 0x40d7
    VMStackPushConst 5
    VMStackCmp 4
    VMJumpIf 255, L_1EE3
    ActorMsg 1024, 30, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_1EF3

L_1EE3:
    ActorMsg 1024, 29, 4, 0, 0
    LastKeyWait
    ActorMsgClose

L_1EF3:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_1EF9:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1F18
    CallTrainerBattleEnd
    VMJump L_1F1A

L_1F18:
    CallTrainerLose

L_1F1A:
    VMReturn

Script_17:
    ActorsPauseAll
    VMStackPush 0x40d7
    VMStackPushConst 5
    VMStackCmp 4
    VMJumpIf 255, L_1F4B
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 32, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_1F5F

L_1F4B:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 31, 0, 0
    LastKeyWait
    ActorMsgClose

L_1F5F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    SEPlay 1351
    ActorMsg 1024, 33, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    VMStackPush 0x40d7
    VMStackPushConst 5
    VMStackCmp 4
    VMJumpIf 255, L_1FB0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 37, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_1FC4

L_1FB0:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 36, 0, 0
    LastKeyWait
    ActorMsgClose

L_1FC4:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_29:
    ActorsPauseAll
    ActorCmdExec 0, Movement_246C
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    PlayerGetDir 0x8020
    WorkSub 0x8022, 2
    ActorWalkRoute 0, 0x8021, 0x8022, 0, 8, 1
    ActorCmdWait
    VMStackPush 0x8021
    VMStackPushConst 418
    VMStackCmp 5
    VMJumpIf 255, L_2013
    ActorCmdExec 0, Movement_2454
    ActorCmdWait

L_2013:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_2030
    ActorCmdExec 255, Movement_244C
    ActorCmdWait

L_2030:
    ActorMsg 1024, 82, 0, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    RTReserveScript 1
    FadeWait
    MapChangeCore 601, 9, 0, 9, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_33:
    ActorsPauseAll
    FlagReset 794
    ActorAdd 0
    ActorWalkRoute 255, 418, 162, 0, 8, 1
    ActorCmdWait
    WorkSetConst 0x8029, 0
    BMCreateHandleByGPos 0x8029, 1, 418, 159
    BMHndAudioVisualAnmPlay 0x8029, 0
    BMHndAnmWait 0x8029
    SEPlay 1369
    ActorSetGPos 0, 418, 0, 159, 1
    SEWait
    ActorCmdExec 255, Movement_244C
    ActorCmdWait
    ActorCmdExec 0, Movement_240C
    ActorCmdWait
    BMHndAudioVisualAnmPlay 0x8029, 1
    BMHndAnmWait 0x8029
    BMReleaseHandle 0x8029
    ActorMsg 1024, 82, 0, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    RTReserveScript 1
    FadeWait
    MapChangeCore 601, 9, 0, 9, 1
    WorkSetConst 0x8029, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    MoveEnd

Script_30:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    ActorMsg 1024, 83, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorWalkRoute 0, 418, 161, 4, 8, 0
    ActorCmdWait
    ActorDelete 0
    WorkSetConst 0x413e, 3
    WorkSetConst 0x4048, 1
    FlagSet 794
    FlagReset 800
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_22:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_216B
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 63, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_2183

L_216B:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 64, 65, 14, 0, 0
    LastKeyWait
    ActorMsgClose

L_2183:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_23:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_21B8
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 66, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_21D0

L_21B8:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 67, 68, 12, 0, 0
    LastKeyWait
    ActorMsgClose

L_21D0:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_24:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_2205
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 69, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_221D

L_2205:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 70, 71, 15, 0, 0
    LastKeyWait
    ActorMsgClose

L_221D:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_25:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_2252
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 72, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_2266

L_2252:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 73, 0, 0
    LastKeyWait
    ActorMsgClose

L_2266:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_27:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_229B
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 74, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_22B3

L_229B:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 75, 76, 13, 0, 0
    LastKeyWait
    ActorMsgClose

L_22B3:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_28:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_22E8
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 77, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_2300

L_22E8:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 78, 79, 16, 0, 0
    LastKeyWait
    ActorMsgClose

L_2300:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_26:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 80, 81, 18, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 84, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 85, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    GameGetVersion 0x8010
    VMStackPush 0x8010
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_238B
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 87, 2
    MsgPlaceSignClose
    VMJump L_239D

L_238B:
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 86, 2
    MsgPlaceSignClose

L_239D:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 88, 0
    MsgPlaceSignClose
    FlagSet 2662
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    GameGetVersion 0x8010
    VMStackPush 0x8010
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_23F2
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 90, 2
    MsgPlaceSignClose
    VMJump L_2404

L_23F2:
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 89, 2
    MsgPlaceSignClose

L_2404:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_240C:
    Move 13, 1
    MoveEnd

Movement_2414:
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd
    Move 0, 1
    MoveEnd

Movement_2434:
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0
    Move 3, 1
    MoveEnd

Movement_244C:
    Move 32, 1
    MoveEnd

Movement_2454:
    Move 33, 1
    MoveEnd

Movement_245C:
    Move 34, 1
    MoveEnd

Movement_2464:
    Move 35, 1
    MoveEnd

Movement_246C:
    Move 75, 1
    MoveEnd

Movement_2474:
    Move 159, 1
    MoveEnd
