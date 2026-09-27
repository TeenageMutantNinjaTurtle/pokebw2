#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2753
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 299
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0079
    VMCall L_0144
    VMJump L_013E

L_0079:
    VMStackPushFlag 2753
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4182
    VMStackPushConst 0
    VMStackCmp 5
    VMStackCmp 7
    VMJumpIf 255, L_00BB
    WordSetPokeSpecies 0, 0x4182
    ParentActorMsg 1024, 5, 0, 0
    YesNoWin 0x8010
    VMCall L_01CB
    VMJump L_013E

L_00BB:
    VMStackPushFlag 2753
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 299
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_010D
    ParentActorMsg 1024, 12, 0, 0
    FishingChallengeGetRandomPkm 0x4182
    WordSetPokeSpecies 0, 0x4182
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2753
    FlagSet 299
    VMJump L_013E

L_010D:
    VMStackPushFlag 2753
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4182
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_013E
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_013E:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0144:
    VMStackPushFlag 298
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0167
    ParentActorMsg 1024, 1, 0, 0
    VMJump L_0171

L_0167:
    ParentActorMsg 1024, 0, 0, 0

L_0171:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01B7
    FishingChallengeGetRandomPkm 0x4182
    WordSetPokeSpecies 0, 0x4182
    ParentActorMsg 1024, 3, 0, 0
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2753
    FlagSet 299
    VMJump L_01C9

L_01B7:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 298

L_01C9:
    VMReturn

L_01CB:
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02FF
    ParentActorMsg 1024, 6, 0, 0
    MsgWinCloseAll
    RTCGetDate 0x8026, 0x8024
    CallPokeSelect 0, 0x8022, 0x8021, 0
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02EB
    PokePartyGetSpecies 0x8023, 0x8021
    WordSetPokeSpecies 0, 0x8023
    PokePartyGetMetDate 0x8029, 0x8027, 0x8025, 0x8021
    VMStackPush 0x4182
    VMStackPush 0x8023
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPush 0x8027
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPush 0x8025
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_028D
    ParentActorMsg 1024, 7, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 7
    WorkSet 0x8001, 5
    RTCallGlobal 2806
    VMStackPop 0x8001
    VMStackPop 0x8000
    WorkSetConst 0x4182, 0
    VMJump L_02E5

L_028D:
    VMStackPush 0x4182
    VMStackPush 0x8023
    VMStackCmp 5
    VMJumpIf 255, L_02B4
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02E5

L_02B4:
    VMStackPush 0x8026
    VMStackPush 0x8027
    VMStackCmp 5
    VMStackPush 0x8024
    VMStackPush 0x8025
    VMStackCmp 5
    VMStackCmp 6
    VMJumpIf 255, L_02E5
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02E5:
    VMJump L_02F9

L_02EB:
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02F9:
    VMJump L_030D

L_02FF:
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_030D:
    VMReturn
    .balign 4, 0
