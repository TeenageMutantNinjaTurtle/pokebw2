#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 200
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0049
    ActorMsg 1024, 0, 2, 0, 0
    FlagSet 200

L_0049:
    ActorMsg 1024, 1, 2, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0315
    ActorMsg 1024, 3, 2, 0, 0
    ActorMsgClose
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    CallPokeSelect 0, 0x8021, 0x8020, 0
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02FF
    WorkSetConst 0x8022, 0
    PokePartyIsEgg 0x8022, 0x8020
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00D8
    ActorMsg 1024, 5, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_02F9

L_00D8:
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    PokePartyGetParam 0x8023, 0x8020, 153
    PokePartyGetParam 0x8024, 0x8020, 158
    WordSetPartyPokeSpecies 0, 0x8020
    WordSetNumber 1, 0x8023, 3
    WordSetNumber 2, 0x8024, 3
    WorkSub 0x8024, 0x8023
    ActorMsg 1024, 6, 2, 0, 0
    VMStackPush 0x8024
    VMStackPushConst 99
    VMStackCmp 1
    VMJumpIf 255, L_019B
    ActorMsg 1024, 7, 2, 0, 0
    VMStackPushFlag 203
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0189
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 221
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 11, 2, 0, 0
    FlagSet 203
    VMJump L_0195

L_0189:
    ActorMsg 1024, 12, 2, 0, 0

L_0195:
    VMJump L_02F5

L_019B:
    VMStackPush 0x8024
    VMStackPushConst 50
    VMStackCmp 4
    VMJumpIf 255, L_0217
    ActorMsg 1024, 8, 2, 0, 0
    VMStackPushFlag 202
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0205
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 224
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 11, 2, 0, 0
    FlagSet 202
    VMJump L_0211

L_0205:
    ActorMsg 1024, 12, 2, 0, 0

L_0211:
    VMJump L_02F5

L_0217:
    VMStackPush 0x8024
    VMStackPushConst 25
    VMStackCmp 4
    VMJumpIf 255, L_0293
    ActorMsg 1024, 9, 2, 0, 0
    VMStackPushFlag 201
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0281
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 216
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 11, 2, 0, 0
    FlagSet 201
    VMJump L_028D

L_0281:
    ActorMsg 1024, 12, 2, 0, 0

L_028D:
    VMJump L_02F5

L_0293:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02B8
    ActorMsg 1024, 13, 2, 0, 0
    VMJump L_02F5

L_02B8:
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 4
    VMJumpIf 255, L_02E9
    ActorMsg 1024, 10, 2, 0, 0
    ActorMsg 1024, 12, 2, 0, 0
    VMJump L_02F5

L_02E9:
    ActorMsg 1024, 4, 2, 0, 0

L_02F5:
    LastKeyWait
    ActorMsgClose

L_02F9:
    VMJump L_030F

L_02FF:
    ActorMsg 1024, 2, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_030F:
    VMJump L_0325

L_0315:
    ActorMsg 1024, 2, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_0325:
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 14, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0519
    ActorMsgClose
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    CallPokeSelect 0, 0x8027, 0x8026, 0
    VMStackPush 0x8027
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0503
    WorkSetConst 0x8028, 0
    PokePartyIsEgg 0x8028, 0x8026
    VMStackPush 0x8028
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03DA
    ActorMsg 1024, 15, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_04FD

L_03DA:
    WordSetPartyPokeSpecies 0, 0x8026
    ActorMsg 1024, 16, 0, 0, 0
    WorkSetConst 0x8029, 0
    PokePartyGetHappiness 0x8029, 0x8026
    VMStackPush 0x8029
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0420
    ActorMsg 1024, 23, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_04FD

L_0420:
    VMStackPush 0x8029
    VMStackPushConst 255
    VMStackCmp 1
    VMJumpIf 255, L_0449
    ActorMsg 1024, 17, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_04FD

L_0449:
    VMStackPush 0x8029
    VMStackPushConst 200
    VMStackCmp 4
    VMJumpIf 255, L_0472
    ActorMsg 1024, 18, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_04FD

L_0472:
    VMStackPush 0x8029
    VMStackPushConst 150
    VMStackCmp 4
    VMJumpIf 255, L_049B
    ActorMsg 1024, 19, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_04FD

L_049B:
    VMStackPush 0x8029
    VMStackPushConst 100
    VMStackCmp 4
    VMJumpIf 255, L_04C4
    ActorMsg 1024, 20, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_04FD

L_04C4:
    VMStackPush 0x8029
    VMStackPushConst 50
    VMStackCmp 4
    VMJumpIf 255, L_04ED
    ActorMsg 1024, 21, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_04FD

L_04ED:
    ActorMsg 1024, 22, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_04FD:
    VMJump L_0513

L_0503:
    ActorMsg 1024, 24, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0513:
    VMJump L_0529

L_0519:
    ActorMsg 1024, 24, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0529:
    WorkSetConst 0x8029, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 517, 0
    ParentActorMsg 1024, 25, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 552, 0
    ParentActorMsg 1024, 26, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 531, 0
    ParentActorMsg 1024, 27, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 580, 0
    ParentActorMsg 1024, 28, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 524, 0
    ParentActorMsg 1024, 29, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
