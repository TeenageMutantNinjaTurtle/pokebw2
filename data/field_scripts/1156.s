#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 2222
    SEWait
    InfoMsg 0, 2
    LastKeyWait
    InfoMsgClose_0039
    WorkSetConst 0x4149, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
