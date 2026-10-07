#ifndef POKEBW2_APP_MYSTERY_MYSTERY_ALBUM_H
#define POKEBW2_APP_MYSTERY_MYSTERY_ALBUM_H

// Mystery Gift's cards: the album of saved cards, and the view of one card (ov197, mystery_album.c). Our names; swan
// has none for this overlay

#include "types.h"
#include "gfl/clact.h"
#include "gfl/heap.h"
#include "save/mystery_gift.h"
#include "struct_decls.h"
#include "system/printsys.h"

typedef struct {
    u32 mode;
    u32 unk4;
    ClActUnit *unit;
    MysteryGiftSave *giftSave;
    Font *font;
    PrintQueue *queue;
    WordSet *wordSet;
    MsgData *msgData;
    GameData *gameData;
} MysteryCardViewSetup;

typedef struct {
    u32 mainBg;
    u32 unk4;
    u32 subBg;
    u32 palette;
    u32 framePalette;
    u32 frameChar;
    ClActUnit *unit;
    MysteryGiftSave *giftSave;
    MsgData *msgData;
    Font *font;
    PrintQueue *queue;
    WordSet *wordSet;
} MysteryCardResSetup;

MysteryCardView *MysteryCardView_Create(const MysteryCardViewSetup *setup, HeapID heapId);
void MysteryCardView_Delete(MysteryCardView *view);
void MysteryCardView_Main(MysteryCardView *view);
void MysteryCardView_Draw(MysteryCardView *view);
BOOL MysteryCardView_IsEnd(MysteryCardView *view);

MysteryCardRes *MysteryCardRes_Create(const MysteryCardResSetup *setup, HeapID heapId);
void MysteryCardRes_Delete(MysteryCardRes *res);

MysteryAlbum *MysteryAlbum_CreateReceived(MysteryGiftRecvData *recv, MysteryCardRes *res, GameData *gameData,
                                          HeapID heapId);
void MysteryAlbum_Delete(MysteryAlbum *album);
void MysteryAlbum_Main(MysteryAlbum *album);
void MysteryAlbum_StartOpen(MysteryAlbum *album);
BOOL MysteryAlbum_IsOpened(MysteryAlbum *album);
void MysteryAlbum_SetVisible(MysteryAlbum *album, BOOL visible);

#endif // POKEBW2_APP_MYSTERY_MYSTERY_ALBUM_H
