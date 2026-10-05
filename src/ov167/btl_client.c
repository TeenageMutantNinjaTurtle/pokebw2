#include "types.h"
#include "battle/btl_action.h"
#include "battle/btl_adapter.h"
#include "battle/btl_calc.h"
#include "battle/btl_client.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server.h"
#include "battle/btl_server_cmd.h"
#include "battle/btlv.h"
#include "battle/tr_ai.h"
#include "gfl/heap.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "nitro/math.h"

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0) where it has them

// The playback of a recorded battle
typedef struct {
    u8 seq;
    // 1 or 2 when the playback stopped
    u8 result;
    u8 skipping : 1;
    u8 quitStarted : 1;
    u8 quitDone : 1;
    u8 chapterReached : 1;
    u8 unk2_4 : 1;
    u8 dataEnd : 1;
    u16 quitTimer;
    u16 chapter;
    u16 skipTarget;
    u16 maxChapter;
    u16 skipCount;
} BtlClientRecPlayer;

// A Pokestar Studios movie's score
typedef struct {
    s16 points[4];
    s16 unk08;
    s16 unk0A;
    u8 counts[4];
    u32 unk10;
    // Clamped to +-9999
    s32 total;
} BtlClientStudioScore;

// A Pokestar Studios movie
typedef struct {
    u8 seq;
    u8 nextSeq;
    u8 unk02;
    u8 unk03;
    u8 unk04;
    u8 unk05;
    // The entry of the movie's script
    s8 scene;
    u32 unk08;
    s32 unk0C;
    s8 unk10;
    u8 unk11[0xb];
    s32 msgId1;
    s32 msgId2;
    u16 unk24;
    u16 unk26;
    // One bit per script entry used
    u32 usedEventMask;
    s32 unk2C;
    StrBuf *strBufs[4];
    BtlClientStudioScore score;
    u16 unk58;
    u32 audienceMask;
    u16 audienceTimers[22];
    u8 waitTimer;
} BtlClientStudioWork;

struct BtlClient {
    BtlMainModule *mainModule;
    BtlPokeCon *pokeCon;
    BattleMon *procMon;
    BattleAction *procAction;
    void *recorder;
    void *recReader;
    BtlClientRecPlayer recPlayer;
    BOOL (*mainProc)(BtlClient *client);
    BtlClientIDList clientIdList;
    u32 fieldStatus;
    MATHRandContext32 targetRand;
    BtlAdapter *adapter;
    BtlvCore *viewCore;
    BtlvStringParam strParam;
    BtlvStringParam strParam2;
    BtlServer *cmdCheckServer;
    BtlvSelectTargetParam rotationParam;
    u8 unkCC;
    BOOL (*cmdProc)(BtlClient *client, s32 *seq);
    s32 cmdSeq;
    BOOL (*selActProc)(BtlClient *client, s32 *seq);
    s32 selActSeq;
    const void *returnData;
    u32 returnDataSize;
    u32 dummyReturnData;
    u16 cmdLimitTime;
    u16 gameLimitTime;
    u16 aiItems[4];
    VM *aiVM;
    MATHRandContext32 aiRand;
    s8 aiSwitchReserved[6];
    u8 hintShown[4];
    BattleParty *party;
    u8 numCoverPos;
    u8 procActionIdx;
    s8 prevActionIdx;
    u8 firstActionIdx;
    u8 forceActionMsg;
    u8 unk129;
    BattleAction actions[3];
    u8 shooterCost[3];
    BtlServerCmdQueue *cmdQueue;
    u32 cmdArgs[16];
    u32 serverCmd;
    BOOL (*serverCmdProc)(BtlClient *client, s32 *seq, const u32 *args);
    s32 serverCmdSeq;
    BtlvPokeListCmd pokeListCmd;
    BtlvPokeSelectParam pokeSelect;
    u16 heapId;
    u16 savedHp;
    u16 hintMsgId;
    u16 reservedItems[3];
    u8 clientId;
    // 0 for the player, 1 for the AI, 2 for a recorded battle's playback
    u8 clientType;
    u8 mainSeq;
    u8 waitMsgShown;
    u8 bagMode;
    u8 shooterEnergy;
    u8 yesNoResult;
    u8 cmdLimitOver;
    u8 cmdCheckReq;
    u8 extraActionCount;
    u8 moveInfoPos;
    u8 moveInfoIdx;
    u8 unk1BA_0 : 1;
    u8 forceQuit : 1;
    u8 unk1BA_2 : 1;
    u8 cmdCheckEnable : 1;
    u8 unk1BA_4 : 1;
    u8 unk1BA_5 : 1;
    u8 changePokeCount;
    u8 unk1BC;
    u8 turnCount;
    u8 changePokePos[6];
    BtlClientStudioWork studio;
};
