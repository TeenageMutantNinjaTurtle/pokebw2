#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0

Script_1:
    ActorsPauseAll
    MEPlay 1327
    SystemMsg 0, 2
    MEWait
    WordSetPlayerName 0
    SystemMsg 1, 2
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    Cmd_0265 0
    FadeInBlackQ
    FadeWait
    RTGetZoneID 0x8021
    WorkCmpConst 0x8021, 62
    VMJumpIf 1, L_004E
    VMJump L_005A

L_004E:
    WorkSetConst 0x4126, 2
    VMJump L_0210

L_005A:
    WorkCmpConst 0x8021, 96
    VMJumpIf 1, L_006D
    VMJump L_0079

L_006D:
    WorkSetConst 0x4127, 2
    VMJump L_0210

L_0079:
    WorkCmpConst 0x8021, 107
    VMJumpIf 1, L_008C
    VMJump L_0098

L_008C:
    WorkSetConst 0x4128, 2
    VMJump L_0210

L_0098:
    WorkCmpConst 0x8021, 406
    VMJumpIf 1, L_00AB
    VMJump L_00B7

L_00AB:
    WorkSetConst 0x4129, 2
    VMJump L_0210

L_00B7:
    WorkCmpConst 0x8021, 412
    VMJumpIf 1, L_00CA
    VMJump L_00D6

L_00CA:
    WorkSetConst 0x412a, 2
    VMJump L_0210

L_00D6:
    WorkCmpConst 0x8021, 458
    VMJumpIf 1, L_00E9
    VMJump L_00F5

L_00E9:
    WorkSetConst 0x412b, 2
    VMJump L_0210

L_00F5:
    WorkCmpConst 0x8021, 329
    VMJumpIf 1, L_0108
    VMJump L_0114

L_0108:
    WorkSetConst 0x412c, 2
    VMJump L_0210

L_0114:
    WorkCmpConst 0x8021, 331
    VMJumpIf 1, L_0127
    VMJump L_0133

L_0127:
    WorkSetConst 0x412d, 2
    VMJump L_0210

L_0133:
    WorkCmpConst 0x8021, 337
    VMJumpIf 1, L_0146
    VMJump L_0152

L_0146:
    WorkSetConst 0x412e, 2
    VMJump L_0210

L_0152:
    WorkCmpConst 0x8021, 348
    VMJumpIf 1, L_0165
    VMJump L_0171

L_0165:
    WorkSetConst 0x412f, 2
    VMJump L_0210

L_0171:
    WorkCmpConst 0x8021, 365
    VMJumpIf 1, L_0184
    VMJump L_0190

L_0184:
    WorkSetConst 0x4130, 2
    VMJump L_0210

L_0190:
    WorkCmpConst 0x8021, 368
    VMJumpIf 1, L_01A3
    VMJump L_01AF

L_01A3:
    WorkSetConst 0x4131, 2
    VMJump L_0210

L_01AF:
    WorkCmpConst 0x8021, 370
    VMJumpIf 1, L_01C2
    VMJump L_01CE

L_01C2:
    WorkSetConst 0x4132, 2
    VMJump L_0210

L_01CE:
    WorkCmpConst 0x8021, 374
    VMJumpIf 1, L_01E1
    VMJump L_01ED

L_01E1:
    WorkSetConst 0x4133, 2
    VMJump L_0210

L_01ED:
    WorkCmpConst 0x8021, 383
    VMJumpIf 1, L_0200
    VMJump L_020C

L_0200:
    WorkSetConst 0x4134, 2
    VMJump L_0210

L_020C:
    DebugPrint 0x8021

L_0210:
    Cmd_02D3 5, 0x8020
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_0283
    WorkSetConst 0x4126, 2
    WorkSetConst 0x4127, 2
    WorkSetConst 0x4128, 2
    WorkSetConst 0x4129, 2
    WorkSetConst 0x412a, 2
    WorkSetConst 0x412b, 2
    WorkSetConst 0x412c, 2
    WorkSetConst 0x412d, 2
    WorkSetConst 0x412e, 2
    WorkSetConst 0x412f, 2
    WorkSetConst 0x4130, 2
    WorkSetConst 0x4131, 2
    WorkSetConst 0x4132, 2
    WorkSetConst 0x4133, 2
    WorkSetConst 0x4134, 2

L_0283:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
