#include "field/event_chatot.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "gfl/arc.h"
#include "gfl/arc_util.h"
#include "gfl/bmp.h"
#include "pml/poke_graphic.h"
#include "pml/poke_party.h"
#include "system/game_system.h"

void func_ov033_02178fcc(void *work, u32 *state) {
    *state = 1;
}

void func_ov033_02178fd4(ChatotEventWork *work) {
    DisableAllActorsMovement(Field_GetActorSystem(GSYS_GetField(work->gsys)));
}

void func_ov033_02178fe8(ChatotEventWork *work) {
    EnableAllActorsMovement(Field_GetActorSystem(GSYS_GetField(work->gsys)));
}

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

void func_ov033_021790a0(ChatotEventWork *work) {
    func_0204c108(work->sprite);
    func_0204b98c(work->chars);
    func_0204bcd0(work->palette);
    func_0204be64(work->cellAnims);
    func_0204bf98(work->unit);
}

u32 func_ov033_021790c4(ChatotEventWork *work) {
    ClActorPos position;

    if (work->animFrame == 0) {
        work->animOffset = -4;
    }
    if (work->animOffset == -4) {
        work->animOffset = 3;
        work->animFrame++;
        if (work->animFrame == 3) {
            return 0;
        }
    }
    func_0204c178(work->sprite, &position, 0);
    position.y -= work->animOffset;
    func_0204c140(work->sprite, &position, 0);
    work->animOffset--;
    return 1;
}

void func_ov033_02179140(ChatotEventWork *work) {
    u32 paletteId;
    GFLBitmap *bitmap;

    paletteId = GetSysMsgBoxPaletteDatID(0);
    GFL_G2DIOLoadNCLR(5, paletteId, 0, 0, 0, 32, 21);
    work->window = BmpWin_CreateDynamic(1, 10, 3, 12, 12, 0, 1);
    bitmap = BmpWin_GetBitmap(work->window);
    GFL_BitmapFill(bitmap, 17);
    BmpWin_FlushChar(work->window);
    BmpWin_FlushMap(work->window);
    BmpWin_DrawFrame(work->window, 1, 1, 0);
    func_ov033_02178ffc(work);
}

void func_ov033_021791a8(ChatotEventWork *work) {
    func_ov033_021790a0(work);
    func_02024eec(work->window, 1);
    BmpWin_Free(work->window);
}