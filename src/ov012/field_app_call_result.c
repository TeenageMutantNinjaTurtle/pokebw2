#include "field/app_call.h"

void EventFieldAppCall_ConvAppResultToEventType(u32 result, u32 *eventType) {
    switch (result) {
    case 0:
        *eventType = 0;
        break;
    case 1:
        *eventType = 1;
        break;
    case 3:
        *eventType = 3;
        break;
    case 2:
        *eventType = 2;
        break;
    case 5:
        *eventType = 5;
        break;
    default:
        break;
    }
}
