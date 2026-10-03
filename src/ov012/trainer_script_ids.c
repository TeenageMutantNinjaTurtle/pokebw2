#include "field/trainer_script.h"

u16 GetNPCTrainerIDFromSCRID(u32 scriptId) {
    if (scriptId < 0x1388) {
        return scriptId - 0xbb8;
    }
    return scriptId - 0x1388;
}

u16 GetNormalSCRIDFromTrainerID(u32 trainerId) {
    return trainerId + 0xbb8;
}

u16 GetPairMember2SCRIDFromTrainerID(u32 trainerId) {
    return trainerId + 0x1388;
}

BOOL isTrainerScrIdDoublePair2(u32 scriptId) {
    return scriptId >= 0x1388;
}
