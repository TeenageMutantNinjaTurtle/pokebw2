#include "types.h"

typedef struct { u8 a; u8 b; u16 c; u32 d; s16 e; s8 f; u8 g; } S1;
typedef struct { u32 w[6]; } Big;
typedef struct { u32 x : 5; u32 y : 7; u32 z : 20; } Bits;

extern void ext_v(void);
extern int ext_i(int);
extern int ext_ii(int, int);
extern void ext_p(void *);
extern u32 g_arr[16];
extern S1 g_s1;
extern Big g_big;

static inline int inl_max(int a, int b) { return a > b ? a : b; }

int t_switch_sparse(int x) {
    switch (x) {
    case 1: return ext_i(10);
    case 7: return ext_i(20);
    case 30: return ext_i(30);
    case 100: return ext_i(40);
    case 1000: return ext_i(50);
    default: return 0;
    }
}
int t_switch_dense(int x, int y) {
    switch (x) {
    case 0: y += 3; break;
    case 1: y *= 5; break;
    case 2: y -= 7; break;
    case 3: y ^= 9; break;
    case 4: y = ext_i(y); break;
    case 5: y <<= 2; break;
    case 6: return ext_ii(x, y);
    case 7: y = -y; break;
    }
    return y + 1;
}
u32 t_div_const(u32 a, int b) { return a / 10 + b / 7 + a % 13 + (u32)b % 3u; }
int t_div_var(int a, int b) { return a / b + a % b; }
u8 t_u8_math(u8 a, u8 b) { return (u8)(a + b * 3) >> 1; }
s8 t_s8_math(s8 a, s8 b) { return (s8)(a - b) / 2; }
u16 t_u16_loop(u16 *p, int n) { u16 s = 0; int i; for (i = 0; i < n; i++) s += p[i]; return s; }
void t_struct_copy(Big *dst) { *dst = g_big; }
void t_struct_copy2(S1 *dst, S1 *src) { *dst = *src; dst->c++; }
u32 t_bits(Bits *b) { b->y = b->x + 3; return b->z * 2 + b->y; }
void t_bits_set(Bits *b, u32 v) { b->x = v; b->z = v >> 4; }
int t_inline(int a, int b, int c) { return inl_max(a, b) + inl_max(b, c) * inl_max(a, c); }
s64 t_mul64(s32 a, s32 b) { return (s64)a * b + 5; }
u64 t_shift64(u64 a, int s) { return (a << s) | (a >> 3); }
int t_ternary(int a, int b) { return a ? (b ? 1 : 2) : (b ? 3 : 4); }
int t_many_args(int a, int b, int c, int d, int e, int f, int g) { return a + b * c - d + e * f - g; }
int t_regpressure(u32 *p) {
    u32 a = p[0], b = p[1], c = p[2], d = p[3], e = p[4], f = p[5], g = p[6], h = p[7], i = p[8];
    ext_v();
    return a * b + c * d - e * f + g * h + i + a * i - b * h;
}
void t_memset_loop(u8 *p, int n) { while (n-- > 0) *p++ = 0; }
int t_while_break(int *p) { int n = 0; while (1) { if (p[n] < 0) break; if (p[n] == 5) return n; n++; } return -1; }
BOOL t_bool_chain(S1 *s) { return s->a == 1 && s->b != 2 || s->c > 300 && s->f < 0; }
int t_nested_loops(u8 (*grid)[8]) { int x, y, n = 0; for (y = 0; y < 8; y++) for (x = 0; x < 8; x++) if (grid[y][x] == 3) n += x * y; return n; }
void t_array_global(int i, u32 v) { g_arr[i & 15] = v; g_arr[(i + 1) & 15] = v + 1; }
int t_signed_cmp(s16 a, u16 b) { return a < (int)b ? a : b; }
void t_callbacks(void (*f)(int), int n) { int i; for (i = 0; i < n; i++) f(i * 3); }
u32 t_ptr_arith(u32 *a, u32 *b) { return (u32)(b - a) + ((u8 *)b - (u8 *)a); }
int t_float(float a, float b) { return (int)(a * b + 1.5f); }
int t_double(double a) { return (int)(a / 3.0); }
u32 t_rotate(u32 x) { return (x << 7) | (x >> 25); }
int t_abs(int x) { return x < 0 ? -x : x; }
int t_min_max(int x, int lo, int hi) { if (x < lo) x = lo; else if (x > hi) x = hi; return x; }
void t_local_array(void) { u32 buf[8]; int i; for (i = 0; i < 8; i++) buf[i] = i * i; ext_p(buf); }
int t_do_while(u32 x) { int n = 0; do { x >>= 1; n++; } while (x); return n; }
u32 t_struct_fields(S1 *s) { return s->a + s->b + s->c + s->d + s->e + s->f + s->g; }
void t_tailcall(int x) { if (x > 3) ext_v(); else ext_p(&g_s1); }
