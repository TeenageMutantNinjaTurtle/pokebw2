#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 0, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    FlagSet 950
    FlagSet 951
    FlagSet 953
    FlagSet 955
    FlagSet 957
    FlagReset 948
    FlagReset 949
    FlagReset 952
    FlagReset 954
    FlagReset 956
    VMHalt
    .balign 4, 0
