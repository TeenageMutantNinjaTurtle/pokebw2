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
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    PokeDexIsComplete 0x8020, 3
    PokeDexIsComplete 0x8021, 1
    DebugPrint 0x8020
    DebugPrint 0x8021
    VMStackPush 0x400a
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0075
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_019D

L_0075:
    VMStackPushFlag 221
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00FF
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00E5
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    FieldClose
    CallPokedexDiploma 0, 0
    FieldOpen
    FadeInBlackQ
    FadeWait
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    MedalGive 44
    FlagReset 736
    FlagSet 221
    WorkSetConst 0x400a, 1
    VMJump L_00F9

L_00E5:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_00F9:
    VMJump L_019D

L_00FF:
    VMStackPushFlag 222
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0189
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_016F
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    FieldClose
    CallPokedexDiploma 1, 0
    FieldOpen
    FadeInBlackQ
    FadeWait
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll
    MedalGive 45
    FlagReset 737
    FlagSet 222
    WorkSetConst 0x400a, 1
    VMJump L_0183

L_016F:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0183:
    VMJump L_019D

L_0189:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose

L_019D:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_028A
    VMStackPushFlag 2739
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_021D
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0284

L_021D:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0276
    ParentActorMsg 1024, 9, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 592, 0, 0
    VMCall L_046D
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2739
    VMJump L_0284

L_0276:
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0284:
    VMJump L_031E

L_028A:
    VMStackPushFlag 2739
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02B7
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_031E

L_02B7:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0310
    ParentActorMsg 1024, 12, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 140, 0, 0
    VMCall L_046D
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2739
    VMJump L_031E

L_0310:
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_031E:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03D3
    VMStackPushFlag 2762
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0366
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_03CD

L_0366:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03BF
    ParentActorMsg 1024, 16, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 357, 0, 0
    VMCall L_046D
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2762
    VMJump L_03CD

L_03BF:
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_03CD:
    VMJump L_0467

L_03D3:
    VMStackPushFlag 2762
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0400
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0467

L_0400:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0459
    ParentActorMsg 1024, 16, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 591, 0, 0
    VMCall L_046D
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2762
    VMJump L_0467

L_0459:
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0467:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_046D:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_048C
    CallTrainerBattleEnd
    VMJump L_048E

L_048C:
    CallTrainerLose

L_048E:
    VMReturn

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
