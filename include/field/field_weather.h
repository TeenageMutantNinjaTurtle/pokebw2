#ifndef POKEBW2_FIELD_FIELD_WEATHER_H
#define POKEBW2_FIELD_FIELD_WEATHER_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The field's weathers. Overlay 36 keeps the weather system, which loads an overlay with each weather's data:
// overlay 74 for weather 0, which the weather names call sunny, and overlays 75 to 78 for the others

// What a weather's functions get
typedef struct WeatherTask WeatherTask;

typedef BOOL (*WeatherFunc)(WeatherTask *task, u32 arg);

typedef struct {
    u16 unk00[20];
    // The size of the work that func_ov036_021997e4 returns
    u32 workSize;
    WeatherFunc funcs[8];
} WeatherData;

// Overlay 36
void *func_ov036_021997e4(WeatherTask *task);
void func_ov036_02199734(WeatherTask *task, u32 a1, u32 a2);
void func_ov036_02199740(WeatherTask *task, u32 a1, u32 a2);
void func_ov036_0219974c(WeatherTask *task, u32 a1);
void func_ov036_0219990c(WeatherTask *task, u32 a1, u32 a2, u32 a3);
void func_ov036_02199948(WeatherTask *task, u32 a1);
void func_ov036_02199958(WeatherTask *task, u32 a1, u32 a2, u32 a3, u32 a4);
void func_ov036_021999bc(WeatherTask *task, u32 a1, u32 a2, u32 a3);
BOOL func_ov036_021999dc(WeatherTask *task);
BOOL func_ov036_02199a00(WeatherTask *task);
BOOL func_ov036_02199a14(WeatherTask *task);
BOOL func_ov036_02199a20(WeatherTask *task);
u32 func_ov036_02199a2c(WeatherTask *task);
u32 func_ov036_02199a38(WeatherTask *task);
u32 func_ov036_02199a44(WeatherTask *task);

// Overlay 74
extern WeatherData SUNNY_WEATHER;
BOOL func_ov074_021e90c0(WeatherTask *task, u32 arg);
BOOL func_ov074_021e9108(WeatherTask *task, u32 arg);
BOOL func_ov074_021e9170(WeatherTask *task, u32 arg);
BOOL func_ov074_021e91b8(WeatherTask *task, u32 arg);
BOOL func_ov074_021e91bc(WeatherTask *task, u32 arg);
BOOL func_ov074_021e91e0(WeatherTask *task, u32 arg);
BOOL func_ov074_021e91f4(WeatherTask *task, u32 arg);
void *func_ov036_02199004(FieldCamera *camera, void *light, FieldFog *fog, void *fogCtrl, FieldSound *sound, u32 season,
                          HeapID heapId);
void func_ov036_021990d8(void *weather);
void FieldWeather_Update(void *weather, HeapID heapId);
void FieldWeather_Draw(void *weather);
BOOL func_ov036_0219917c(void *weather);
void SetWeatherInit(void *weather, u16 weatherId, HeapID heapId);
void func_ov036_02199208(void *weather, u16 weatherId);

#endif // POKEBW2_FIELD_FIELD_WEATHER_H
