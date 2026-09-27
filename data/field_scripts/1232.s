#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd
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
    WorkSetConst 0x802a, 0

L_004C:
    DayCareCheckSpawnFlag 0x8026
    DayCareGetPkmCount 0x8027
    FlagGet 105, 0x8025
    WorkSetConst 0x8028, 2
    VMReturn

L_0062:
    PokePartyGetCount 0x8029, 0
    PokePartyGetCount 0x802a, 2
    VMReturn

Script_1:
    ActorsPauseAll
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802b, 0
    VMCall L_004C
    VMCall L_0062
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8026
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_017C
    ActorMsg 1024, 6, 0x8011, 2, 0
    YesNoWin 0x8021
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00D2
    WorkSetConst 0x802b, 1
    VMJump L_00FB

L_00D2:
    ActorMsg 1024, 10, 0x8011, 2, 0
    YesNoWin 0x8021
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00FB
    WorkSetConst 0x802b, 1

L_00FB:
    VMStackPush 0x802b
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0164
    VMStackPush 0x8029
    VMStackPushConst 6
    VMStackCmp 0
    VMJumpIf 255, L_014E
    DayCareBreed
    ActorMsgClose
    WordSetPlayerName 0
    MEPlay 1317
    SystemMsg 7, 0
    MEWait
    MsgWaitAdvance
    InfoMsgClose
    ActorMsg 1024, 8, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_015E

L_014E:
    ActorMsg 1024, 9, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose

L_015E:
    VMJump L_0176

L_0164:
    DayCareResetSeed
    ActorMsg 1024, 11, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose

L_0176:
    VMJump L_01D9

L_017C:
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01A5
    ActorMsg 1024, 0, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_01D9

L_01A5:
    VMStackPush 0x8027
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01D3
    WordSetDaycarePokeName 0, 0
    ActorMsg 1024, 1, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_01D9

L_01D3:
    VMCall L_01E5

L_01D9:
    WorkSetConst 0x802b, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_01E5:
    WorkSetConst 0x802c, 0
    DayCareCalcEggSpawnChance 0x802c
    WorkCmpConst 0x802c, 88
    VMJumpIf 1, L_0202
    VMJump L_020E

L_0202:
    WorkSetConst 0x8020, 2
    VMJump L_02C8

L_020E:
    WorkCmpConst 0x802c, 70
    VMJumpIf 1, L_0221
    VMJump L_022D

L_0221:
    WorkSetConst 0x8020, 2
    VMJump L_02C8

L_022D:
    WorkCmpConst 0x802c, 80
    VMJumpIf 1, L_0240
    VMJump L_024C

L_0240:
    WorkSetConst 0x8020, 3
    VMJump L_02C8

L_024C:
    WorkCmpConst 0x802c, 50
    VMJumpIf 1, L_025F
    VMJump L_026B

L_025F:
    WorkSetConst 0x8020, 3
    VMJump L_02C8

L_026B:
    WorkCmpConst 0x802c, 40
    VMJumpIf 1, L_027E
    VMJump L_028A

L_027E:
    WorkSetConst 0x8020, 4
    VMJump L_02C8

L_028A:
    WorkCmpConst 0x802c, 20
    VMJumpIf 1, L_029D
    VMJump L_02A9

L_029D:
    WorkSetConst 0x8020, 4
    VMJump L_02C8

L_02A9:
    WorkCmpConst 0x802c, 0
    VMJumpIf 1, L_02BC
    VMJump L_02C8

L_02BC:
    WorkSetConst 0x8020, 5
    VMJump L_02C8

L_02C8:
    WordSetDaycarePokeName 0, 0
    WordSetDaycarePokeName 1, 1
    ActorMsg 1024, 0x8020, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x802c, 0
    VMReturn

Script_2:
    ActorsPauseAll
    WorkSetConst 0x802d, 0
    VMCall L_004C
    VMCall L_0062
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8026
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_032D
    ActorMsg 1024, 15, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0427

L_032D:
    MoneyWinDisp 31, 1
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_035C
    ActorMsg 1024, 12, 0x8011, 2, 0
    FlagSet 105
    VMJump L_0368

L_035C:
    ActorMsg 1024, 13, 0x8011, 2, 0

L_0368:
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32813
    VMStackPush 0x8027
    VMStackPush 0x8028
    VMStackCmp 0
    VMJumpIf 255, L_038C
    ListMenuAdd 30, 65535, 30

L_038C:
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 2
    VMJumpIf 255, L_03A7
    ListMenuAdd 31, 65535, 31

L_03A7:
    ListMenuAdd 32, 65535, 32
    ListMenuShow
    WorkCmpConst 0x802d, 30
    VMJumpIf 1, L_03C4
    VMJump L_03D0

L_03C4:
    VMCall L_04F2
    VMJump L_0425

L_03D0:
    WorkCmpConst 0x802d, 31
    VMJumpIf 1, L_03E3
    VMJump L_03EF

L_03E3:
    VMCall L_08D4
    VMJump L_0425

L_03EF:
    WorkCmpConst 0x802d, 32
    VMJumpIf 1, L_040F
    WorkCmpConst 0x802d, 65534
    VMJumpIf 1, L_040F
    VMJump L_0425

L_040F:
    ActorMsg 1024, 14, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0425

L_0425:
    MoneyWinClose

L_0427:
    WorkSetConst 0x802d, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0433:
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x8030, 0
    WorkSetConst 0x8031, 0
    DayCareCallPokeSelect 0x802e
    MoneyWinDisp 31, 1
    VMStackPush 0x802e
    VMStackPush 0x8029
    VMStackCmp 0
    VMJumpIf 255, L_04C6
    PokePartyIsEgg 0x802f, 0x802e
    VMStackPush 0x802f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_048D
    WorkSetConst 0x8022, 1
    VMJump L_04C0

L_048D:
    PokePartyGetSpecies 0x8030, 0x802e
    PokePartyGetForme 0x8031, 0x802e
    Cmd_023A 0x8030, 0x8031
    WordSetPartyPokeName 0, 0x802e
    ActorMsg 1024, 19, 0x8011, 2, 0
    DayCareDeposit 0x802e
    RecordAdd 24, 1
    WorkSetConst 0x8022, 2

L_04C0:
    VMJump L_04CC

L_04C6:
    WorkSetConst 0x8022, 0

L_04CC:
    VMCall L_004C
    VMCall L_0062
    WorkSetConst 0x8031, 0
    WorkSetConst 0x8030, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x802e, 0
    VMReturn

L_04F2:
    WorkSetConst 0x8032, 0
    WorkSetConst 0x8033, 0
    WorkSetConst 0x8033, 1

L_0504:
    VMStackPush 0x8033
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_064B
    VMStackPush 0x802a
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_053C
    ActorMsg 1024, 16, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_053C:
    VMStackPush 0x802a
    VMStackPushConst 2
    VMStackCmp 3
    VMJumpIf 255, L_057A
    BoxGetCount 0x8032, 1
    VMStackPush 0x8032
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_057A
    ActorMsg 1024, 28, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_057A:
    ActorMsg 1024, 17, 0x8011, 2, 0
    ActorMsgClose
    VMCall L_0433
    WorkCmpConst 0x8022, 0
    VMJumpIf 1, L_05A1
    VMJump L_05B9

L_05A1:
    ActorMsg 1024, 14, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    VMJump L_0645

L_05B9:
    WorkCmpConst 0x8022, 1
    VMJumpIf 1, L_05CC
    VMJump L_05E4

L_05CC:
    ActorMsg 1024, 18, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    VMJump L_0645

L_05E4:
    WorkCmpConst 0x8022, 2
    VMJumpIf 1, L_05F7
    VMJump L_0645

L_05F7:
    VMStackPush 0x8027
    VMStackPush 0x8028
    VMStackCmp 0
    VMJumpIf 255, L_0639
    ActorMsg 1024, 21, 0x8011, 2, 0
    YesNoWin 0x8021
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0633
    WorkSetConst 0x8033, 0

L_0633:
    VMJump L_063F

L_0639:
    WorkSetConst 0x8033, 0

L_063F:
    VMJump L_0645

L_0645:
    VMJump L_0504

L_064B:
    ActorMsg 1024, 20, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x8033, 0
    WorkSetConst 0x8032, 0
    VMReturn

L_0669:
    WorkSetConst 0x8034, 0
    WorkSetConst 0x8035, 0
    WorkSetConst 0x8036, 0
    WorkSetConst 0x8037, 0
    WorkSetConst 0x8038, 0
    WorkSetConst 0x8039, 0
    WorkSetConst 0x803a, 0
    WorkSetConst 0x803b, 0
    WorkSetConst 0x803c, 0
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32820
    WorkSetConst 0x803c, 0

L_06AE:
    VMStackPush 0x803c
    VMStackPush 0x8027
    VMStackCmp 0
    VMJumpIf 255, L_0756
    DayCareGetSpecies 0x8039, 0x803c
    DayCareGetSex 0x803b, 0x803c
    DayCareCalcNewLevel 0x8035, 0x803c
    WordSetDaycarePokeName 0, 0x803c
    WordSetNumber 1, 0x8035, 3
    DayCareGetSexForNamePrint 0x8010, 0, 0x803c
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_06FA
    VMJump L_0708

L_06FA:
    ListMenuAdd 36, 65535, 0x803c
    VMJump L_074A

L_0708:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_071B
    VMJump L_0729

L_071B:
    ListMenuAdd 34, 65535, 0x803c
    VMJump L_074A

L_0729:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_073C
    VMJump L_074A

L_073C:
    ListMenuAdd 35, 65535, 0x803c
    VMJump L_074A

L_074A:
    WorkAdd 0x803c, 1
    VMJump L_06AE

L_0756:
    ListMenuAdd 32, 65535, 2
    ListMenuShow
    VMStackPush 0x8034
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8034
    VMStackPushConst 65534
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_078B
    WorkSetConst 0x8023, 1
    VMReturn

L_078B:
    DayCareCalcLevelGain 0x8036, 0x8034
    DayCareCalcWithdrawCost 0x8037, 0x8034
    VMStackPush 0x8036
    VMStackPushConst 0
    VMStackCmp 2
    VMJumpIf 255, L_07C2
    WordSetDaycarePokeName 0, 0x8034
    WordSetNumber 1, 0x8036, 2
    ActorMsg 1024, 23, 0x8011, 2, 0

L_07C2:
    WordSetDaycarePokeName 0, 0x8034
    WordSetNumber 1, 0x8037, 5
    ActorMsg 1024, 24, 0x8011, 2, 0
    YesNoWin 0x8021
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_07F9
    WorkSetConst 0x8023, 1
    VMReturn

L_07F9:
    MoneyCheck 0x8038, 0x8037
    VMStackPush 0x8038
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_081A
    WorkSetConst 0x8023, 0
    VMReturn

L_081A:
    PokePartyGetCount 0x8010, 5
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_083B
    WorkSetConst 0x8023, 3
    VMReturn

L_083B:
    MoneySub 0x8037
    MoneyWinUpdate
    SEPlay 1621
    SEWait
    ActorMsgClose
    ActorCmdExec 0, Movement_08B8
    ActorCmdWait
    DayCareGetSpecies 0x8039, 0x8034
    DayCareGetForme 0x803a, 0x8034
    Cmd_023A 0x8039, 0x803a
    WordSetDaycarePokeName 0, 0x8034
    WordSetPlayerName 1
    SystemMsg 26, 2
    InfoMsgClose
    DayCareWithdraw 0x8034
    WorkSetConst 0x8023, 2
    WorkSetConst 0x803c, 0
    WorkSetConst 0x803b, 0
    WorkSetConst 0x803a, 0
    WorkSetConst 0x8039, 0
    WorkSetConst 0x8038, 0
    WorkSetConst 0x8037, 0
    WorkSetConst 0x8036, 0
    WorkSetConst 0x8035, 0
    WorkSetConst 0x8034, 0
    VMReturn
    .balign 4, 0

Movement_08B8:
    Move 8, 3
    Move 69, 1
    Move 65, 1
    Move 1, 1
    Move 70, 1
    Move 9, 3
    MoveEnd

L_08D4:
    WorkSetConst 0x803d, 0
    ActorMsg 1024, 22, 0x8011, 2, 0
    WorkSetConst 0x803d, 1

L_08EC:
    VMStackPush 0x803d
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A1B
    VMCall L_0669
    VMCall L_004C
    VMCall L_0062
    WorkCmpConst 0x8023, 0
    VMJumpIf 1, L_0924
    VMJump L_093E

L_0924:
    ActorMsg 1024, 25, 0x8011, 2, 0
    LastKeyWait
    WorkSetConst 0x803d, 0
    VMJump L_0A15

L_093E:
    WorkCmpConst 0x8023, 3
    VMJumpIf 1, L_0951
    VMJump L_096B

L_0951:
    ActorMsg 1024, 9, 0x8011, 2, 0
    LastKeyWait
    WorkSetConst 0x803d, 0
    VMJump L_0A15

L_096B:
    WorkCmpConst 0x8023, 1
    VMJumpIf 1, L_097E
    VMJump L_0998

L_097E:
    ActorMsg 1024, 14, 0x8011, 2, 0
    LastKeyWait
    WorkSetConst 0x803d, 0
    VMJump L_0A15

L_0998:
    WorkCmpConst 0x8023, 2
    VMJumpIf 1, L_09AB
    VMJump L_0A15

L_09AB:
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09D8
    ActorMsg 1024, 14, 0x8011, 2, 0
    LastKeyWait
    WorkSetConst 0x803d, 0
    VMJump L_0A0F

L_09D8:
    ActorMsg 1024, 27, 0x8011, 2, 0
    YesNoWin 0x8021
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A0F
    ActorMsg 1024, 14, 0x8011, 2, 0
    LastKeyWait
    WorkSetConst 0x803d, 0

L_0A0F:
    VMJump L_0A15

L_0A15:
    VMJump L_08EC

L_0A1B:
    ActorMsgClose
    WorkSetConst 0x803d, 0
    VMReturn
    .balign 4, 0
