#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 255
    WorkSet 0x8001, 1
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 8
    WorkSet 0x8001, 1
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 444
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00D8
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00C4
    ActorMsgVersioned 1024, 0, 1, 11, 0, 0
    VMJump L_00D2

L_00C4:
    ActorMsgVersioned 1024, 3, 4, 11, 0, 0

L_00D2:
    VMJump L_00E2

L_00D8:
    ParentActorMsg 1024, 2, 0, 0

L_00E2:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 444
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0142
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_012E
    ActorMsgVersioned 1024, 5, 6, 8, 0, 0
    VMJump L_013C

L_012E:
    ActorMsgVersioned 1024, 8, 9, 8, 0, 0

L_013C:
    VMJump L_014C

L_0142:
    ParentActorMsg 1024, 7, 0, 0

L_014C:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 444
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01A4
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0194
    ParentActorMsg 1024, 10, 0, 0
    VMJump L_019E

L_0194:
    ParentActorMsg 1024, 12, 0, 0

L_019E:
    VMJump L_01AE

L_01A4:
    ParentActorMsg 1024, 11, 0, 0

L_01AE:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 444
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01E3
    ParentActorMsg 1024, 13, 0, 0
    VMJump L_01ED

L_01E3:
    ParentActorMsg 1024, 14, 0, 0

L_01ED:
    MedalGetCount 7, 0x8021
    WordSetMedalRank 0, 0x8021
    WorkCmpConst 0x8021, 0
    VMJumpIf 1, L_020A
    VMJump L_021A

L_020A:
    ParentActorMsg 1024, 15, 0, 0
    VMJump L_02AA

L_021A:
    WorkCmpConst 0x8021, 1
    VMJumpIf 1, L_022D
    VMJump L_023D

L_022D:
    ParentActorMsg 1024, 16, 0, 0
    VMJump L_02AA

L_023D:
    WorkCmpConst 0x8021, 2
    VMJumpIf 1, L_0250
    VMJump L_0260

L_0250:
    ParentActorMsg 1024, 17, 0, 0
    VMJump L_02AA

L_0260:
    WorkCmpConst 0x8021, 3
    VMJumpIf 1, L_0273
    VMJump L_0283

L_0273:
    ParentActorMsg 1024, 18, 0, 0
    VMJump L_02AA

L_0283:
    WorkCmpConst 0x8021, 4
    VMJumpIf 1, L_0296
    VMJump L_02AA

L_0296:
    ActorMsgVersioned 1024, 20, 19, 9, 0, 0
    VMJump L_02AA

L_02AA:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
