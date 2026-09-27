#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntry Script_9
    ScriptEntry Script_10
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_4:
    ActorsPauseAll
    ActorCmdExec 0, Movement_0090
    ActorCmdWait
    WordSetPlayerName 0
    TrainerCardGetSex 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0073
    InfoMsg 0, 1
    VMJump L_0078

L_0073:
    InfoMsg 1, 1

L_0078:
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0098
    ActorCmdWait
    WorkSetConst 0x417f, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0090:
    Move 1, 1
    MoveEnd

Movement_0098:
    Move 32, 1
    MoveEnd

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 15, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 17, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 16, 0
    MsgPlaceSignClose
    FlagSet 2666
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0194
    PokePartyGetCount 0x8023, 3
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0180
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_018E

L_0180:
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_018E:
    VMJump L_01A2

L_0194:
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01A2:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01F7
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_020B

L_01F7:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose

L_020B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    VMStackPushFlag 471
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02F1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    PokeDexCheckHabitatList 321, 0, 0, 0x8024
    PokeDexCheckHabitatList 321, 1, 0, 0x8025
    PokeDexCheckHabitatList 321, 2, 0, 0x8026
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_02DD
    ParentActorMsg 1024, 13, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 7
    WorkSet 0x8001, 5
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 471
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02EB

L_02DD:
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02EB:
    VMJump L_0305

L_02F1:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose

L_0305:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
