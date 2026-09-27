#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    VMStackPush 0x8006
    WorkSet 0x8000, 43
    WorkSet 0x8001, 1
    WorkSet 0x8002, 413
    WorkSet 0x8003, 0
    WorkSet 0x8004, 1
    WorkSet 0x8005, 1
    RTGetTextFile 0x8006
    RTCallGlobal 2800
    VMStackPop 0x8006
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    Cmd_02B4 0, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 4
    VMJumpIf 255, L_00B4
    WordSetPlayerName 0
    Cmd_02B5 0, 1
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_00C5

L_00B4:
    WordSetPlayerName 0
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_00C5:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
