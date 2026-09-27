#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    ActorCmdExec 255, Movement_0210
    ActorCmdWait
    VMSleep 8
    SEPlay 1369
    ActorNew 8, 19, 0, 251, 298, 0
    SEWait
    ActorCmdExec 251, Movement_01DC
    ActorCmdWait
    WordSetPlayerName 0
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_005E
    ActorMsg 1024, 0, 251, 0, 0
    MsgWinCloseAll
    VMJump L_006C

L_005E:
    ActorMsg 1024, 1, 251, 0, 0
    MsgWinCloseAll

L_006C:
    ActorCmdExec 251, Movement_01F8
    ActorCmdExec 255, Movement_01F0
    ActorCmdWait
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x88000, 0x2001f, 0x48000, 20
    EvCameraWait
    WorkSetConst 0x8020, 0
    TrainerCardGetSex 0x8020
    ActorCmdExec 251, Movement_0270
    VMSleep 8
    ActorCmdExec 255, Movement_0278
    ActorCmdWait
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00E3
    ActorMsg 1024, 2, 251, 0, 0
    ActorMsgClose
    VMJump L_00F1

L_00E3:
    ActorMsg 1024, 3, 251, 0, 0
    ActorMsgClose

L_00F1:
    ActorCmdExec 255, Movement_0260
    VMSleep 8
    ActorCmdExec 251, Movement_0260
    ActorCmdWait
    ActorMsg 1024, 4, 251, 0, 0
    ActorMsgClose
    BMPlayHOFMachineSeq
    EvCameraEnd
    MedalIsObtained 0x400e, 253
    PokePartyGetCount 0x400f, 0
    PokePartyGetCount 0x400d, 3
    WorkSub 0x400f, 0x400d
    VMStackPush 0x400e
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0158
    MedalGive 253

L_0158:
    MedalDiscover 236
    MedalDiscover 237
    MedalDiscover 238
    MedalDiscover 239
    MedalDiscover 240
    MedalDiscover 241
    MedalDiscover 242
    MedalDiscover 243
    MedalDiscover 244
    MedalDiscover 245
    MedalDiscover 246
    MedalDiscover 247
    MedalDiscover 248
    MedalDiscover 249
    MedalDiscover 250
    MedalDiscover 251
    MedalDiscover 252
    MedalDiscover 253
    MedalDiscover 102
    MedalDiscover 136
    MedalDiscover 124
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01CD
    FadeOutBlackQ
    FadeWait
    CallGameClear 0
    .byte 0x1e
    .byte 0x00
    VMStackPushConst 0

L_01CD:
    FadeOutBlackQ
    FadeWait
    CallGameClear 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_01DC:
    Move 15, 1
    Move 12, 3
    Move 14, 1
    Move 33, 1
    MoveEnd

Movement_01F0:
    Move 12, 13
    MoveEnd

Movement_01F8:
    Move 12, 11
    Move 15, 1
    Move 32, 1
    MoveEnd
    Move 13, 1
    MoveEnd

Movement_0210:
    Move 12, 1
    MoveEnd
    VMStackDiv
    VMNop2
    PokePartyGetSpecies 0, 14
    VMNop2
    PokePartyGetSpecies 0, 0
    VMNop2
    PokePartyGetSpecies 0, 1
    VMNop2
    PokePartyGetSpecies 0, 2
    VMNop2
    PokePartyGetSpecies 0, 3
    VMNop2
    PokePartyGetSpecies 0, 15
    VMHalt
    PokePartyGetSpecies 0, 14
    VMHalt
    .byte 0xfe
    .balign 4, 0
    Move 10, 1
    MoveEnd

Movement_0260:
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd

Movement_0270:
    Move 34, 1
    MoveEnd

Movement_0278:
    Move 35, 1
    MoveEnd
