#ifndef POKEBW2_BATTLE_BTL_SERVER_H
#define POKEBW2_BATTLE_BTL_SERVER_H

#include "types.h"
#include "struct_decls.h"

struct SwitchModeState {
    void *actionManager;
    u8 unk04[7];
    u8 enabled;
};

struct BtlServer {
    u8 unk00[0xc];
    BtlMainModule *mainModule;
    BtlPokeCon *pokeCon;
    u8 unk14[0xc];
    struct SwitchModeState switchMode;
    u8 unk2c[0xc88];
    u8 posList[6];
    u8 count;
};

BOOL DoesSwitchModeNeedConfirming(BtlServer *server);
u8 GetNextEnemyForSwitchMode(BtlServer *server);
void RequestChangePokemon(BtlServer *server, u8 pos);

#endif // POKEBW2_BATTLE_BTL_SERVER_H
