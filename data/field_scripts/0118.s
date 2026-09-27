#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8021, 0
    ActorMsg 1024, 0, 1, 4, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0236

L_004B:
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_0230
    ActorMsg 1024, 10, 1, 4, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32800
    ListMenuAdd 11, 65535, 0
    ListMenuAdd 12, 65535, 1
    ListMenuAdd 13, 65535, 2
    ListMenuAdd 14, 65535, 3
    ListMenuAdd 15, 65535, 4
    ListMenuAdd 16, 65535, 5
    ListMenuAdd 17, 65535, 6
    ListMenuAdd 18, 65535, 7
    ListMenuAdd 19, 65535, 8
    ListMenuShow
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_00D0
    VMJump L_00E2

L_00D0:
    ActorMsg 1024, 2, 1, 4, 0
    VMJump L_022A

L_00E2:
    WorkCmpConst 0x8020, 1
    VMJumpIf 1, L_00F5
    VMJump L_0107

L_00F5:
    ActorMsg 1024, 3, 1, 4, 0
    VMJump L_022A

L_0107:
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_011A
    VMJump L_012C

L_011A:
    ActorMsg 1024, 4, 1, 4, 0
    VMJump L_022A

L_012C:
    WorkCmpConst 0x8020, 3
    VMJumpIf 1, L_013F
    VMJump L_0151

L_013F:
    ActorMsg 1024, 5, 1, 4, 0
    VMJump L_022A

L_0151:
    WorkCmpConst 0x8020, 4
    VMJumpIf 1, L_0164
    VMJump L_0176

L_0164:
    ActorMsg 1024, 6, 1, 4, 0
    VMJump L_022A

L_0176:
    WorkCmpConst 0x8020, 5
    VMJumpIf 1, L_0189
    VMJump L_019B

L_0189:
    ActorMsg 1024, 7, 1, 4, 0
    VMJump L_022A

L_019B:
    WorkCmpConst 0x8020, 6
    VMJumpIf 1, L_01AE
    VMJump L_01C0

L_01AE:
    ActorMsg 1024, 8, 1, 4, 0
    VMJump L_022A

L_01C0:
    WorkCmpConst 0x8020, 7
    VMJumpIf 1, L_01D3
    VMJump L_01E5

L_01D3:
    ActorMsg 1024, 9, 1, 4, 0
    VMJump L_022A

L_01E5:
    WorkCmpConst 0x8020, 8
    VMJumpIf 1, L_01F8
    VMJump L_0214

L_01F8:
    ActorMsg 1024, 1, 1, 4, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8021, 1
    VMJump L_022A

L_0214:
    ActorMsg 1024, 1, 1, 4, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8021, 1

L_022A:
    VMJump L_004B

L_0230:
    VMJump L_0246

L_0236:
    ActorMsg 1024, 1, 1, 4, 0
    LastKeyWait
    MsgWinCloseAll

L_0246:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 507, 0
    ParentActorMsg 1024, 21, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
