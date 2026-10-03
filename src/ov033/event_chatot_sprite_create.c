#include "field/event_chatot.h"
#include "gfl/arc.h"
#include "pml/poke_graphic.h"
#include "pml/poke_party.h"

void func_ov033_02178ffc(ChatotEventWork *work) {
    BoxPkm *pkm;
    ArcTool *arc;
    BOOL encrypted;
    ClActorSetup setup;

    work->unit = func_0204bf1c(1, 0, 21);
    pkm = func_0201d620(work->pkm);
    arc = MakePokeGraArcHandle(21);
    encrypted = PML_PkmDecrypt(pkm);
    work->chars = func_02033f90(arc, pkm, 0, 0, 21);
    work->palette = func_02033f2c(arc, pkm, 0, 0, 0xc0, 21);
    work->cellAnims = func_02034000(pkm, 0, 1, 0, 21);
    PML_PkmReEncrypt(pkm, encrypted);
    GFL_ArcToolFree(arc);
    setup = data_ov033_0217c488;
    work->sprite = func_0204c040(work->unit, work->chars, work->palette, work->cellAnims, &setup, 0, 21);
}
