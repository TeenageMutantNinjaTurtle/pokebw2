#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    VMStackPushFlag 2760
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_006F
    VMCall L_007E
    VMJump L_0078

L_006F:
    InfoMsg 4, 2
    LastKeyWait
    InfoMsgClose_0039

L_0078:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_007E:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8022, 0
    PokePartyGetCount 0x8024, 0

L_00AE:
    VMStackPush 0x8022
    VMStackPush 0x8024
    VMStackCmp 0
    VMJumpIf 255, L_0194
    PokePartyIsEgg 0x8023, 0x8022
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0188
    PokePartyGetTypes 0x8020, 0x8021, 0x8022
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_017C
    WordSetPartyPokeName 0, 0x8022
    InfoMsg 2, 2
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0168
    WordSetPartyPokeName 0, 0x8022
    InfoMsg 3, 2
    InfoMsgClose_0039
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 90
    WorkSet 0x8001, 1
    RTCallGlobal 2806
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 2760
    WorkSetConst 0x8022, 6
    WorkSetConst 0x8025, 1
    VMJump L_0176

L_0168:
    InfoMsgClose_0039
    WorkSetConst 0x8022, 6
    WorkSetConst 0x8025, 1

L_0176:
    VMJump L_0182

L_017C:
    WorkAdd 0x8022, 1

L_0182:
    VMJump L_018E

L_0188:
    WorkAdd 0x8022, 1

L_018E:
    VMJump L_00AE

L_0194:
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01B0
    InfoMsg 4, 2
    LastKeyWait
    InfoMsgClose_0039

L_01B0:
    VMReturn

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 5, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
