#ifndef POKEBW2_FIELD_GYM_GIMMICK_H
#define POKEBW2_FIELD_GYM_GIMMICK_H

// The gym puzzles that overlay 36's gym script commands drive, each in its own overlay at the field gimmicks' shared
// load address. The GymElec and GymInsect names are swan's (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"

// Overlay 92: the Nimbasa City gym's roller coaster
void GymElec_ReapplyProgress(Field *field);
void GymElec_SetFollower(Field *field, u16 a1, u16 a2, u16 a3);
GameEvent *GymElec_SetProgress(GameSystem *gsys, u8 progress);
void GymElec_SetEffectsMode(Field *field, u32 mode);
void GymElec_ShowModel(Field *field, BOOL show);
void GymElec_ShowStageObject5(Field *field, BOOL show);
void GymElec_SetBrightness(Field *field, u32 brightness);

// Overlay 91: the Castelia City gym
void GymInsect_PlayObject(Field *field, u8 object);
void GymInsect_ShowEffect(Field *field);

// Overlays 94 and 96 to 102: the other gyms' puzzles
GameEvent *func_ov094_021eeef8(GameSystem *gsys, u16 a1);
GameEvent *func_ov096_021eeddc(GameSystem *gsys, u16 a1, u16 a2);
GameEvent *func_ov096_021eedf0(GameSystem *gsys, BOOL a1, BOOL a2);
void func_ov096_021eee04(GameSystem *gsys);
GameEvent *func_ov097_021eede4(GameSystem *gsys, BOOL a1, BOOL a2);
void func_ov097_021eefe4(GameSystem *gsys, u16 a1);
GameEvent *func_ov098_021eee0c(GameSystem *gsys, u16 a1);
GameEvent *func_ov098_021eee48(GameSystem *gsys, u16 a1);
void func_ov098_021eee84(GameSystem *gsys, u16 a1);
GameEvent *func_ov099_021ef144(GameSystem *gsys, u16 a1);
GameEvent *func_ov099_021ef210(GameSystem *gsys, u16 a1);
void func_ov099_021ef168(GameSystem *gsys);
void func_ov099_021efb70(GameSystem *gsys);
void func_ov099_021efb8c(GameSystem *gsys);
void func_ov100_021eed10(GameSystem *gsys, u16 a1);
void func_ov100_021eed64(GameSystem *gsys, u16 a1);
void func_ov101_021eee48(GameSystem *gsys);
void func_ov101_021eeee0(GameSystem *gsys);
GameEvent *func_ov102_021ef3e8(GameSystem *gsys, u8 a1);
void func_ov102_021ef6f8(GameSystem *gsys, u8 a1);
void func_ov102_021ef338(GameSystem *gsys);

#endif // POKEBW2_FIELD_GYM_GIMMICK_H
