#ifndef POKEBW2_APP_BATTLE_RECORDER_BR_BTN_H
#define POKEBW2_APP_BATTLE_RECORDER_BR_BTN_H

#include "types.h"
#include "struct_decls.h"

// The Battle Recorder's menu buttons (br_btn.c)

#define BR_BTN_SYS_STACK_MAX 6

typedef struct {
    u16 menuID;
    u16 btnID;
} BrBtnStack;

// The menus that were open, kept while another screen runs
typedef struct {
    BrBtnStack stack[BR_BTN_SYS_STACK_MAX];
    u32 stack_num;
} BrBtnRecovery;

#endif // POKEBW2_APP_BATTLE_RECORDER_BR_BTN_H
