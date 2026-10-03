#include "field/field_script.h"
#include "gfl/msg.h"

void SetFieldScriptEnvMsgData(FieldScriptEnv *env, u32 arcId, u32 fileNo) {
    env->msgData = GFL_MsgSysLoadData(FALSE, (u16)arcId, (u16)fileNo, env->heapId);
    env->msgFileNo = (u16)fileNo;
}
