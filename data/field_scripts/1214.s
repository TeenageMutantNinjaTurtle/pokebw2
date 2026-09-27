#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x98000, 0x67000, 0x138000, 1
    EvCameraWait
    ActorCmdExec 255, Movement_0560
    ActorCmdWait
    FadeInBlackQ
    EvCameraReturn 60
    EvCameraWait
    FadeWait
    VMSleep 45
    ActorCmdExec 0, Movement_04D8
    ActorCmdWait
    ActorMsg 1024, 0, 0, 1, 0
    MsgWinCloseAll
    VMSleep 30
    ActorCmdExec 1, Movement_0528
    ActorCmdWait
    ActorCmdExec 1, Movement_0540
    ActorCmdWait
    VMSleep 30
    ActorCmdExec 1, Movement_04D0
    ActorCmdWait
    ActorMsg 1024, 1, 1, 0, 0
    MsgWinCloseAll
    VMSleep 30
    ActorCmdExec 0, Movement_0570
    ActorCmdWait
    ActorCmdExec 1, Movement_0508
    ActorCmdWait
    VMSleep 30
    ActorMsg 1024, 2, 0, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 3, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0518
    ActorCmdWait
    ActorCmdExec 0, Movement_0568
    ActorCmdWait
    ActorMsg 1024, 4, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0530
    ActorCmdWait
    ActorCmdExec 1, Movement_0578
    ActorCmdWait
    ActorMsg 1024, 5, 1, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 1, 9, 17, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_0580
    ActorCmdWait
    ActorMsgVersioned 1024, 7, 6, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0518
    ActorCmdWait
    ActorMsg 1024, 8, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0590
    VMSleep 8
    ActorCmdExec 0, Movement_0510
    ActorCmdWait
    ActorDelete 1
    ActorMsg 1024, 9, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_05A0
    ActorCmdWait
    Cmd_02B5 0, 0
    ActorMsg 1024, 10, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_05AC
    ActorCmdWait
    ActorMsg 1024, 11, 0, 1, 0
    MsgWinCloseAll
    ActorWalkRoute 0, 16, 13, 1, 8, 1
    EvCameraMoveTo 9688, 0, 0xed000, 0x98000, 0x67000, 0x138000, 30
    FadeOutBlack
    FadeWait
    EvCameraWait
    ActorCmdWait
    EvCameraRebind
    EvCameraEnd
    RTReserveScript 2110
    WorkCmpConst 0x4192, 8
    VMJumpIf 1, L_01EF
    VMJump L_0201

L_01EF:
    MapChangeCore 8, 3, 0, 13, 0
    VMJump L_04C0

L_0201:
    WorkCmpConst 0x4192, 20
    VMJumpIf 1, L_0214
    VMJump L_0226

L_0214:
    MapChangeCore 20, 3, 0, 13, 0
    VMJump L_04C0

L_0226:
    WorkCmpConst 0x4192, 41
    VMJumpIf 1, L_0239
    VMJump L_024B

L_0239:
    MapChangeCore 41, 3, 0, 13, 0
    VMJump L_04C0

L_024B:
    WorkCmpConst 0x4192, 65
    VMJumpIf 1, L_025E
    VMJump L_0270

L_025E:
    MapChangeCore 65, 3, 0, 13, 0
    VMJump L_04C0

L_0270:
    WorkCmpConst 0x4192, 99
    VMJumpIf 1, L_0283
    VMJump L_0295

L_0283:
    MapChangeCore 99, 3, 0, 13, 0
    VMJump L_04C0

L_0295:
    WorkCmpConst 0x4192, 109
    VMJumpIf 1, L_02A8
    VMJump L_02BA

L_02A8:
    MapChangeCore 109, 3, 0, 13, 0
    VMJump L_04C0

L_02BA:
    WorkCmpConst 0x4192, 115
    VMJumpIf 1, L_02CD
    VMJump L_02DF

L_02CD:
    MapChangeCore 115, 3, 0, 13, 0
    VMJump L_04C0

L_02DF:
    WorkCmpConst 0x4192, 122
    VMJumpIf 1, L_02F2
    VMJump L_0304

L_02F2:
    MapChangeCore 122, 3, 0, 13, 0
    VMJump L_04C0

L_0304:
    WorkCmpConst 0x4192, 146
    VMJumpIf 1, L_0317
    VMJump L_0329

L_0317:
    MapChangeCore 146, 3, 0, 13, 0
    VMJump L_04C0

L_0329:
    WorkCmpConst 0x4192, 1
    VMJumpIf 1, L_033C
    VMJump L_034E

L_033C:
    MapChangeCore 1, 3, 0, 13, 0
    VMJump L_04C0

L_034E:
    WorkCmpConst 0x4192, 425
    VMJumpIf 1, L_0361
    VMJump L_0373

L_0361:
    MapChangeCore 425, 3, 0, 13, 0
    VMJump L_04C0

L_0373:
    WorkCmpConst 0x4192, 435
    VMJumpIf 1, L_0386
    VMJump L_0398

L_0386:
    MapChangeCore 435, 3, 0, 13, 0
    VMJump L_04C0

L_0398:
    WorkCmpConst 0x4192, 454
    VMJumpIf 1, L_03AB
    VMJump L_03BD

L_03AB:
    MapChangeCore 454, 3, 0, 13, 0
    VMJump L_04C0

L_03BD:
    WorkCmpConst 0x4192, 472
    VMJumpIf 1, L_03D0
    VMJump L_03E2

L_03D0:
    MapChangeCore 472, 3, 0, 13, 0
    VMJump L_04C0

L_03E2:
    WorkCmpConst 0x4192, 398
    VMJumpIf 1, L_03F5
    VMJump L_0407

L_03F5:
    MapChangeCore 398, 3, 0, 13, 0
    VMJump L_04C0

L_0407:
    WorkCmpConst 0x4192, 407
    VMJumpIf 1, L_041A
    VMJump L_042C

L_041A:
    MapChangeCore 407, 3, 0, 13, 0
    VMJump L_04C0

L_042C:
    WorkCmpConst 0x4192, 413
    VMJumpIf 1, L_043F
    VMJump L_0451

L_043F:
    MapChangeCore 413, 3, 0, 13, 0
    VMJump L_04C0

L_0451:
    WorkCmpConst 0x4192, 443
    VMJumpIf 1, L_0464
    VMJump L_0476

L_0464:
    MapChangeCore 443, 3, 0, 13, 0
    VMJump L_04C0

L_0476:
    WorkCmpConst 0x4192, 460
    VMJumpIf 1, L_0489
    VMJump L_049B

L_0489:
    MapChangeCore 460, 3, 0, 13, 0
    VMJump L_04C0

L_049B:
    WorkCmpConst 0x4192, 602
    VMJumpIf 1, L_04AE
    VMJump L_04C0

L_04AE:
    MapChangeCore 602, 3, 0, 13, 0
    VMJump L_04C0

L_04C0:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    MoveEnd

Movement_04D0:
    Move 12, 1
    MoveEnd

Movement_04D8:
    Move 8, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0

Movement_0508:
    Move 3, 1
    MoveEnd

Movement_0510:
    Move 32, 1
    MoveEnd

Movement_0518:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_0528:
    Move 35, 1
    MoveEnd

Movement_0530:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd

Movement_0540:
    Move 161, 1
    MoveEnd
    Move 160, 1
    MoveEnd
    Move 71, 1
    Move 169, 1
    Move 72, 1
    MoveEnd

Movement_0560:
    Move 69, 1
    MoveEnd

Movement_0568:
    Move 182, 1
    MoveEnd

Movement_0570:
    Move 11, 2
    MoveEnd

Movement_0578:
    Move 39, 4
    MoveEnd

Movement_0580:
    Move 10, 1
    Move 1, 1
    Move 182, 1
    MoveEnd

Movement_0590:
    Move 12, 4
    Move 15, 7
    Move 12, 5
    MoveEnd

Movement_05A0:
    Move 9, 1
    Move 182, 1
    MoveEnd

Movement_05AC:
    Move 10, 1
    MoveEnd
