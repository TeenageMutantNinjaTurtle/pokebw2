#include "types.h"
#include "field/field_weather.h"

WeatherData SUNNY_WEATHER = {
    { 0 },
    sizeof(u32),
    {
        func_ov074_021e90c0,
        func_ov074_021e9108,
        func_ov074_021e9170,
        func_ov074_021e91b8,
        func_ov074_021e91bc,
        func_ov074_021e91e0,
        func_ov074_021e91f4,
    },
    NULL,
};

BOOL func_ov074_021e90c0(WeatherTask *task, u32 arg, HeapID heapId) {
    u32 *state;

    if (func_ov036_02199a00(task)) {
        return FALSE;
    }
    state = func_ov036_021997e4(task);
    *state = 0;
    if (func_ov036_02199a14(task)) {
        func_ov036_02199a2c(task);
        func_ov036_0219990c(task, func_ov036_02199a38(task), 0x7fff, arg);
    }
    return TRUE;
}

BOOL func_ov074_021e9108(WeatherTask *task, u32 arg, HeapID heapId) {
    u32 *state = func_ov036_021997e4(task);
    if (*state == 0) {
        if (func_ov036_02199a14(task)) {
            u32 value = func_ov036_02199a2c(task);
            func_ov036_02199958(task, func_ov036_02199a38(task), value, 0xa0, arg);
        }
        if (func_ov036_02199a20(task)) {
            func_ov036_02199734(task, 0x51, func_ov036_02199a44(task));
        }
        *state = 1;
    }
    if (func_ov036_021999dc(task)) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov074_021e9170(WeatherTask *task, u32 arg, HeapID heapId) {
    if (func_ov036_02199a14(task)) {
        u32 value = func_ov036_02199a2c(task);
        func_ov036_0219990c(task, func_ov036_02199a38(task), value, arg);
    }
    if (func_ov036_02199a20(task)) {
        func_ov036_02199740(task, 0x51, func_ov036_02199a44(task));
    }
    return TRUE;
}

BOOL func_ov074_021e91b8(WeatherTask *task, u32 arg, HeapID heapId) {
    return FALSE;
}

BOOL func_ov074_021e91bc(WeatherTask *task, u32 arg, HeapID heapId) {
    if (func_ov036_02199a14(task)) {
        func_ov036_021999bc(task, 0x7fff, 0x50, arg);
    }
    return TRUE;
}

BOOL func_ov074_021e91e0(WeatherTask *task, u32 arg, HeapID heapId) {
    if (func_ov036_021999dc(task)) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov074_021e91f4(WeatherTask *task, u32 arg, HeapID heapId) {
    if (func_ov036_02199a14(task)) {
        func_ov036_02199948(task, arg);
    }
    if (func_ov036_02199a20(task)) {
        func_ov036_0219974c(task, arg);
    }
    return TRUE;
}
