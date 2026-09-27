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
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    FadeInBlackQ_
    FadeWait
    PlayerSetSpecialSequence 64
    ActorCmdExec 255, Movement_0120
    ActorCmdWait
    PlayerSetSpecialSequence 8
    ActorCmdExec 255, Movement_0128
    ActorCmdWait
    PlayerGetGPos 0x8020, 0x8021
    WorkSub 0x8021, 2
    ActorFindByGPos 0x8011, 0x8022, 0x8020, 0, 0x8021
    PokePartyRecoverAll
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_009B
    ActorMsg 1024, 19, 0x8011, 0, 0
    VMCall L_0144
    ActorMsgClose

L_009B:
    PlayerSetSpecialSequence 64
    ActorCmdExec 255, Movement_0130
    ActorCmdWait
    PlayerSetSpecialSequence 8
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0105
    ActorCmdExec 0x8011, Movement_0138
    ActorCmdWait
    TrainerCardHasBadge 0x8010, 0
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00F5
    ActorMsg 1024, 20, 0x8011, 0, 0
    VMJump L_0101

L_00F5:
    ActorMsg 1024, 21, 0x8011, 0, 0

L_0101:
    LastKeyWait
    ActorMsgClose

L_0105:
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0120:
    Move 102, 1
    MoveEnd

Movement_0128:
    Move 0, 1
    MoveEnd

Movement_0130:
    Move 104, 1
    MoveEnd

Movement_0138:
    Move 100, 1
    Move 62, 1
    MoveEnd

L_0144:
    WorkSetConst 0x8023, 0
    ActorCmdExec 0x8011, Movement_0170
    ActorCmdWait
    PokePartyGetCount 0x8023, 1
    PokecenPlayHealingSequence 0x8023
    ActorCmdExec 0x8011, Movement_0178
    ActorCmdWait
    VMReturn
    .byte 0x28
    .byte 0x00
    .byte 0x23
    .byte 0x80
    .balign 4, 0

Movement_0170:
    Move 0, 1
    MoveEnd

Movement_0178:
    Move 1, 1
    MoveEnd

Script_3:
    WorkSetConst 0x8024, 0
    SaveDataCheckRequired 0x8024
    WorkCmpConst 0x8024, 1
    VMJumpIf 1, L_019D
    VMJump L_01A9

L_019D:
    VMCall Script_4
    VMJump L_01C8

L_01A9:
    WorkCmpConst 0x8024, 0
    VMJumpIf 1, L_01BC
    VMJump L_01C8

L_01BC:
    WorkSetConst 0x8000, 0
    VMJump L_01C8

L_01C8:
    RTEndGlobal
    WorkSetConst 0x8024, 0
    VMHalt

Script_4:
    VMCall L_01DC
    RTEndGlobal
    VMHalt

L_01DC:
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x8001, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8004, 0
    WorkSetConst 0x8029, 0
    SaveDataGetStatus 0x8026, 0x8027, 0x8028
    FieldSubscreenChange 0
    SystemMsg 2, 2
    YesNoWin 0x8029
    VMStackPush 0x8029
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0247
    WorkSetConst 0x8025, 1

L_0247:
    InfoMsgClose
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8027
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_028A
    SystemMsg 9, 2
    InfoMsgClose
    WorkSetConst 0x8025, 0

L_028A:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0329
    WorkCmpConst 0x8028, 0
    VMJumpIf 1, L_02B0
    VMJump L_02BC

L_02B0:
    SystemMsgAsync 4, 2
    VMJump L_02DB

L_02BC:
    WorkCmpConst 0x8028, 1
    VMJumpIf 1, L_02CF
    VMJump L_02DB

L_02CF:
    SystemMsgAsync 10, 2
    VMJump L_02DB

L_02DB:
    VMSleep 1
    MsgSetLoadingSpinner 0
    SaveDataWrite 0x8029
    SEStop
    InfoMsgClose
    VMStackPush 0x8029
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_031B
    SEPlay 1368
    WordSetPlayerName 0
    SystemMsg 5, 2
    MsgWaitAdvance
    InfoMsgClose
    WorkSetConst 0x8000, 0
    VMJump L_0329

L_031B:
    SystemMsg 7, 2
    InfoMsgClose
    WorkSetConst 0x8000, 1

L_0329:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_0342
    WorkSetConst 0x8000, 1

L_0342:
    FieldSubscreenReturn
    VMReturn
    WorkSetConst 0x8029, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0

Script_5:
    VMCall L_036E
    RTEndGlobal
    VMHalt

L_036E:
    GameCommGetStatus 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_038D
    WorkSetConst 0x8000, 0
    VMReturn

L_038D:
    VMStackPush 0x8010
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_03D9
    SystemMsg 15, 2
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03C7
    WorkSetConst 0x8000, 1
    InfoMsgClose
    VMReturn

L_03C7:
    SystemMsg 16, 2
    GameCommDisconnect 0x8000
    InfoMsgClose
    VMJump L_03DD

L_03D9:
    GameCommDisconnect 0x8000

L_03DD:
    VMReturn

Script_6:
    SystemMsg 22, 2
    InfoMsgClose
    RTEndGlobal

Script_7:
    ActorsPauseAll
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802a, 24
    WorkAdd 0x802a, 0x8000
    WordSetPlayerName 0
    WordSetItemName 1, 0x8001
    SystemMsg 0x802a, 2
    LastKeyWait
    InfoMsgClose
    WorkSetConst 0x802a, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
