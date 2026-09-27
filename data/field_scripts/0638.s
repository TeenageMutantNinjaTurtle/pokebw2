#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0

Script_1:
    VMStackPush 0x4186
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_004D
    WorkSetConst 0x4020, 17
    VMJump L_0053

L_004D:
    WorkSetConst 0x4020, 297

L_0053:
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 8, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    PlayerGetDir 0x8020
    MedalIsObtained 0x8021, 18
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00B5
    SEPlay 1351
    InfoMsg 11, 2
    LastKeyWait
    InfoMsgClose_0039
    MedalGive 18
    VMJump L_00C7

L_00B5:
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 9, 3
    MsgPlaceSignClose

L_00C7:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 10, 0
    MsgPlaceSignClose
    FlagSet 2665
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    VMStackPush 0x4186
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0245
    SEPlay 1351
    ActorSetEyeToEye
    PokePartyGetCount 0x8022, 0

L_0130:
    VMStackPush 0x8022
    VMStackPush 0x8023
    VMStackCmp 2
    VMJumpIf 255, L_01A1
    PokePartyGetParam 0x8024, 0x8023, 10
    PokePartyIsEgg 0x8026, 0x8023
    VMStackPush 0x8024
    VMStackPushConst 116
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0195
    PokePartyGetSpecies 0x4186, 0x8023
    WordSetPokeSpecies 0, 0x4186
    WorkSetConst 0x8025, 1

L_0195:
    WorkAdd 0x8023, 1
    VMJump L_0130

L_01A1:
    ParentActorMsg 1024, 0, 0, 0
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_023B
    MsgWaitAdvance
    ParentActorMsg 1024, 1, 0, 0
    ItemCheckSpace 109, 1, 0x8027
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01FF
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x4186, 0
    VMJump L_0235

L_01FF:
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 109
    WorkSet 0x8001, 1
    RTCallGlobal 2801
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x4000, 1

L_0235:
    VMJump L_023F

L_023B:
    LastKeyWait
    MsgWinCloseAll

L_023F:
    VMJump L_0289

L_0245:
    VMStackPush 0x4000
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0272
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0289

L_0272:
    SEPlay 1351
    WordSetPokeSpecies 0, 0x4186
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0289:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
