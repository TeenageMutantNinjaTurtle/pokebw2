#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_3:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 18
    VMStackCmp 1
    VMJumpIf 255, L_004D
    ActorCmdExec 0, Movement_04EC
    VMJump L_0055

L_004D:
    ActorCmdExec 0, Movement_04E4

L_0055:
    ActorCmdWait
    ActorCmdExec 0, Movement_04F4
    ActorCmdWait
    BGMPlay 1238
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    PlayerGetDir 0x8020
    VMStackPush 0x8021
    VMStackPushConst 18
    VMStackCmp 1
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 5
    VMStackCmp 7
    VMJumpIf 255, L_00A8
    ActorCmdExec 255, Movement_04E4
    VMJump L_00D3

L_00A8:
    VMStackPush 0x8021
    VMStackPushConst 12
    VMStackCmp 1
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 5
    VMStackCmp 7
    VMJumpIf 255, L_00D3
    ActorCmdExec 255, Movement_04EC

L_00D3:
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 18
    VMStackCmp 1
    VMJumpIf 255, L_00FA
    WorkSub 0x8021, 1
    VMJump L_0100

L_00FA:
    WorkAdd 0x8021, 1

L_0100:
    ActorWalkRoute 0, 0x8021, 0x8022, 0, 8, 0
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 18
    VMStackCmp 1
    VMJumpIf 255, L_0137
    ActorCmdExec 0, Movement_04EC
    VMJump L_013F

L_0137:
    ActorCmdExec 0, Movement_04E4

L_013F:
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    ActorMsg 1024, 1, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_017C
    ActorMsg 1024, 2, 0, 0, 0
    VMJump L_0188

L_017C:
    ActorMsg 1024, 3, 0, 0, 0

L_0188:
    WorkSetConst 0x8023, 0
    PokePartyGetMemberByType 0x8023, 2
    WordSetPartyPokeSpecies 0, 0x8023
    ActorMsg 1024, 4, 0, 0, 0
    MsgWinCloseAll
    VMSleep 8
    VMStackPush 0x8021
    VMStackPushConst 12
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 9
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_01DC
    ActorCmdExec 0, Movement_04EC
    VMJump L_0205

L_01DC:
    VMStackPush 0x8021
    VMStackPushConst 18
    VMStackCmp 1
    VMJumpIf 255, L_01FD
    ActorCmdExec 0, Movement_04AC
    VMJump L_0205

L_01FD:
    ActorCmdExec 0, Movement_04A4

L_0205:
    ActorCmdWait
    ActorMsg 1024, 5, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8021
    VMStackPushConst 12
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 9
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0250
    ActorCmdExec 0, Movement_04F4
    ActorCmdWait
    ActorCmdExec 0, Movement_04E4
    VMJump L_0279

L_0250:
    VMStackPush 0x8021
    VMStackPushConst 18
    VMStackCmp 1
    VMJumpIf 255, L_0271
    ActorCmdExec 0, Movement_0460
    VMJump L_0279

L_0271:
    ActorCmdExec 0, Movement_0454

L_0279:
    ActorCmdWait
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8021
    VMStackPushConst 12
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 9
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_02BA
    ActorCmdExec 0, Movement_04EC
    VMJump L_02E3

L_02BA:
    VMStackPush 0x8021
    VMStackPushConst 18
    VMStackCmp 1
    VMJumpIf 255, L_02DB
    ActorCmdExec 0, Movement_0474
    VMJump L_02E3

L_02DB:
    ActorCmdExec 0, Movement_046C

L_02E3:
    ActorCmdWait
    ActorMsg 1024, 7, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8021
    VMStackPushConst 12
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 9
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0324
    ActorCmdExec 0, Movement_04E4
    VMJump L_034D

L_0324:
    VMStackPush 0x8021
    VMStackPushConst 18
    VMStackCmp 1
    VMJumpIf 255, L_0345
    ActorCmdExec 0, Movement_04A4
    VMJump L_034D

L_0345:
    ActorCmdExec 0, Movement_04AC

L_034D:
    ActorCmdWait
    ActorMsg 1024, 8, 0, 0, 0
    YesNoWin 0x8010
    ActorMsg 1024, 9, 0, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x8023, 0
    ActorWalkRoute 0, 15, 1, 0, 8, 0
    ActorCmdWait
    SEPlay 1369
    ActorDelete 0
    SEWait
    BGMChangeMap
    WorkSetConst 0x40b4, 2
    FlagSet 756
    FlagReset 758
    WorkSetConst 0x40b6, 1
    FlagSet 988
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 13, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 14, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    VMStackPushFlag 2452
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0437
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    MsgWinCloseAll
    Cmd_0275 0, 7, 0
    SEPlay 1908
    SystemMsg 11, 0
    SEWait
    MsgWaitAdvance
    MsgWinCloseAll
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2452
    VMJump L_044B

L_0437:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    ActorMsgClose

L_044B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0454:
    Move 75, 1
    Move 14, 1
    MoveEnd

Movement_0460:
    Move 75, 1
    Move 15, 1
    MoveEnd

Movement_046C:
    Move 11, 1
    MoveEnd

Movement_0474:
    Move 10, 1
    MoveEnd
    VMStackDiv
    VMHalt
    VMStackAdd
    VMStackAdd
    PokePartyGetSpecies 0, 14
    VMHalt
    Move 12, 12
    MoveEnd
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Movement_04A4:
    Move 15, 1
    MoveEnd

Movement_04AC:
    Move 14, 1
    MoveEnd
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0
    Move 3, 1
    MoveEnd
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd

Movement_04E4:
    Move 34, 1
    MoveEnd

Movement_04EC:
    Move 35, 1
    MoveEnd

Movement_04F4:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
