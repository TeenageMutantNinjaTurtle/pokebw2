#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x4165
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_008D
    VMStackPushFlag 239
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0054
    ParentActorMsg 1024, 0, 0, 0
    FlagSet 239
    WorkSetConst 0x4164, 50
    VMCall L_00A1
    VMJump L_0087

L_0054:
    VMStackPush 0x4165
    VMStackPushConst 5
    VMStackCmp 0
    VMJumpIf 255, L_0077
    ParentActorMsg 1024, 1, 0, 0
    VMJump L_0081

L_0077:
    ParentActorMsg 1024, 2, 0, 0

L_0081:
    VMCall L_00A1

L_0087:
    VMJump L_009B

L_008D:
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_009B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_00A1:
    ItemCheckSpace 0x4164, 0x4165, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00D1
    WordSetItemName 0, 0x4164
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_00D1:
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 0x4164
    WorkSet 0x8001, 0x4165
    RTCallGlobal 2801
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x4165, 0
    Random 0x8010, 10
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0120
    VMJump L_012C

L_0120:
    WorkSetConst 0x4164, 50
    VMJump L_022A

L_012C:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_013F
    VMJump L_014B

L_013F:
    WorkSetConst 0x4164, 23
    VMJump L_022A

L_014B:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_015E
    VMJump L_016A

L_015E:
    WorkSetConst 0x4164, 29
    VMJump L_022A

L_016A:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_017D
    VMJump L_0189

L_017D:
    WorkSetConst 0x4164, 40
    VMJump L_022A

L_0189:
    WorkCmpConst 0x8010, 4
    VMJumpIf 1, L_019C
    VMJump L_01A8

L_019C:
    WorkSetConst 0x4164, 46
    VMJump L_022A

L_01A8:
    WorkCmpConst 0x8010, 5
    VMJumpIf 1, L_01BB
    VMJump L_01C7

L_01BB:
    WorkSetConst 0x4164, 47
    VMJump L_022A

L_01C7:
    WorkCmpConst 0x8010, 6
    VMJumpIf 1, L_01DA
    VMJump L_01E6

L_01DA:
    WorkSetConst 0x4164, 49
    VMJump L_022A

L_01E6:
    WorkCmpConst 0x8010, 7
    VMJumpIf 1, L_01F9
    VMJump L_0205

L_01F9:
    WorkSetConst 0x4164, 52
    VMJump L_022A

L_0205:
    WorkCmpConst 0x8010, 8
    VMJumpIf 1, L_0218
    VMJump L_0224

L_0218:
    WorkSetConst 0x4164, 48
    VMJump L_022A

L_0224:
    WorkSetConst 0x4164, 45

L_022A:
    VMReturn
