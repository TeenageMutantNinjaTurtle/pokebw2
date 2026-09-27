#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_1:
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_003B
    WorkSetConst 0x4020, 209
    VMJump L_0041

L_003B:
    WorkSetConst 0x4020, 129

L_0041:
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PokePartyGetMemberByType 0x8008, 2
    WordSetPartyPokeSpecies 0, 0x8008
    ParentActorMsg 1024, 0, 0, 0
    PokePartyGetHappiness 0x8009, 0x8008
    VMStackPush 0x8009
    VMStackPushConst 255
    VMStackCmp 1
    VMJumpIf 255, L_0089
    ParentActorMsg 1024, 1, 0, 0
    VMJump L_01AF

L_0089:
    VMStackPush 0x8009
    VMStackPushConst 200
    VMStackCmp 4
    VMStackPush 0x8009
    VMStackPushConst 254
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_00C1
    WordSetPartyPokeSpecies 0, 0x8008
    ParentActorMsg 1024, 2, 0, 0
    VMJump L_01AF

L_00C1:
    VMStackPush 0x8009
    VMStackPushConst 150
    VMStackCmp 4
    VMStackPush 0x8009
    VMStackPushConst 199
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_00F9
    WordSetPartyPokeSpecies 0, 0x8008
    ParentActorMsg 1024, 3, 0, 0
    VMJump L_01AF

L_00F9:
    VMStackPush 0x8009
    VMStackPushConst 100
    VMStackCmp 4
    VMStackPush 0x8009
    VMStackPushConst 149
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_012C
    ParentActorMsg 1024, 4, 0, 0
    VMJump L_01AF

L_012C:
    VMStackPush 0x8009
    VMStackPushConst 50
    VMStackCmp 4
    VMStackPush 0x8009
    VMStackPushConst 99
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_015F
    ParentActorMsg 1024, 5, 0, 0
    VMJump L_01AF

L_015F:
    VMStackPush 0x8009
    VMStackPushConst 1
    VMStackCmp 4
    VMStackPush 0x8009
    VMStackPushConst 49
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0192
    ParentActorMsg 1024, 6, 0, 0
    VMJump L_01AF

L_0192:
    VMStackPush 0x8009
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01AF
    ParentActorMsg 1024, 7, 0, 0

L_01AF:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_01F4
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 546, 0
    ParentActorMsg 1024, 9, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_0210

L_01F4:
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 548, 0
    ParentActorMsg 1024, 8, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose

L_0210:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
