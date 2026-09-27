#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    // "Saying yes only so you won't\nhurt another person's feelings...[f000]븀\u0000\nThat is not true kindness.[f000]븁\u0000\nTeam Plasma didn't have true kindness.\nNot even me..."
    ParentActorMsg MSGFILE_SCRIPT, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
