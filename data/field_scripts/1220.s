#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    ActorCmdExec 255, Movement_0044
    VMSleep 4
    FadeOutBlack
    ActorCmdWait
    FadeWait
    RTReserveScript 5
    MapChangeCore 565, 15, 0, 0, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0044:
    Move 9, 1
    MoveEnd

Script_2:
    ActorsPauseAll
    FadeInBlack
    ActorCmdExec 255, Movement_0064
    ActorCmdWait
    FadeWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0064:
    Move 8, 2
    MoveEnd

Script_3:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 0, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 1, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 2, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 3, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
