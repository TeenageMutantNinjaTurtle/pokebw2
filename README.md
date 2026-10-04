# Pokémon Black 2 and White 2

A work-in-progress decompilation of Pokémon Black 2 and White 2 (NDS, DSi-enhanced). The long-term goal is a PC port.

It builds the following ROMs:

| Version | File | SHA1 |
| --- | --- | --- |
| Black 2, USA/Europe (NDSi Enhanced) | `build/pokeblack2_us.nds` | `e51e6dfb8678a3d19dcd2a10691b96a569ca0abb` |
| White 2, USA/Europe (NDSi Enhanced) | `build/pokewhite2_us.nds` | `b5d7490be7b415b8f1e672a53e978a9cc667e56a` |

## Status

Both ROMs rebuild byte for byte from the same source tree. 14 source files match, including the script VM and the
trainer AI, and everything else is still delinked code. The trainer AI scripts are built from source, see
[Scripts](#scripts).

- 41,423 functions found by [dsd](https://github.com/AetiasHax/ds-decomp) in the ARM9, its 344 overlays, ITCM, DTCM, and the two TWL autoloads.
- 8,152 functions and 573 data symbols have real names, imported from [swan](#names).
- The DSi-only LTD module in ARM9i is decompressed, analyzed and linked like the other modules. The ARM7i program is
  only extracted (decrypted) and rebuilt.

## Setup

1. Build dsd with DSi hybrid ROM support. Until the changes are upstreamed, it comes from these forks, both on the
   `dsi-hybrid` branch:
   - `ds-rom`: DSi header, digests, modcrypt, TWL autoloads and DSi banners.
   - `ds-decomp`: TWL entrypoint, DS Protect and Thumb jump table fixes. Its `Cargo.toml` patches in `../ds-rom/lib`.

   ```sh
   cd ../ds-decomp && cargo build --release && cp target/release/dsd ../pokebw2/tools/dsd
   ```

2. Install clang and LLVM, whose `clang` and `llvm-objcopy` assemble the scripts and must be on the `PATH`.

3. Place your own dumps at `orig/baserom_b2_us.nds` and/or `orig/baserom_w2_us.nds`. They must match the SHA1s above.
   They are not included and will not be provided. `tools/scripts/verify_dsi_rom.py` checks a dump against the
   digests in its own header.

4. Configure and build. `configure.py` downloads [wibo](https://github.com/decompals/wibo) and the Metrowerks
   CodeWarrior tools on first run.

   ```sh
   python3 configure.py
   ninja
   ```

   `ninja` extracts each base ROM, delinks the code, links it with `mwldarm`, rebuilds the ROM and checks its SHA1.
   `configure.py` builds every version that has a base ROM, or the versions given as arguments.

5. Optionally, `python3 configure.py --bugfix` builds the ROMs with the game's bugs fixed, those marked with `BUGFIX`
   in the source. These ROMs don't match, so the build skips the checks. Only files marked `complete` are built from
   source, so fixes in the others don't apply yet. Run `configure.py` without it to go back to the matching build.

## Layout

| Path | Contents |
| --- | --- |
| `config/<version>/` | dsd configs: sections (`delinks.txt`), symbols and relocations for every module |
| `config/names.txt`, `config/fixes.txt` | Our own names and fixes to dsd's analysis, applied again after regenerating the configs |
| `src/ovNNN/` | Decompiled C of each overlay, such as `src/ov035/event_mapchange.c` |
| `src/gfl/`, `src/system/`, `src/spl/` | Decompiled C of the ARM9 main module, by library like the headers, such as `src/gfl/heap.c` |
| `include/` | Headers shared by the C code, see [Code organization](#code-organization) |
| `data/` | Scripts assembled into the ROM's files, see [Scripts](#scripts) and [Field scripts](#field-scripts) |
| `include/asm/` | Macros for the scripts |
| `tools/scripts/` | Helper scripts, such as `romdiff.py` to compare two ROMs region by region |
| `extract/`, `build/` | Generated, never committed |

## DSi specifics

Black 2 is an NDS/DSi hybrid built with the TWL-SDK, which differs from DS-only games in ways the tooling had to learn:

- The ARM9 has no footer. Its autoload list has four words per entry, including a `.sinit` address.
- The ROM has a DSi region with ARM9i/ARM7i programs. The first 0x4000 bytes of ARM9i are encrypted with modcrypt
  (AES-CTR). Extraction decrypts it, and the build re-encrypts it.
- Every 0x400-byte sector of the ROM is covered by a SHA1-HMAC digest, and the header holds SHA1-HMACs of each
  program. The build recomputes all of these.
- The digests of the ARM9 secure area are computed over its encrypted form. Without an ARM7 BIOS the build reuses
  the original values, which stay valid as long as the secure area is unchanged.
- The DSi-only LTD ("limited") module is compressed inside ARM9i and loaded to `0x02700000` in DSi mode. ARM9 main
  calls into it. Extraction splits ARM9i into this module (`dsi/ltd_autoload_0.bin`), and the build links, recompresses
  and reinserts it.

## Known gaps

- dsd only finds 253 functions in the LTD module's 437 KB. Its layout, with code after the static initializers,
  does not fit dsd's section heuristics yet.
- 8 calls lead to functions dsd did not discover, and got placeholder symbols (`func_..._unk`).

## Compiler

The game code was built with CodeWarrior for DSi, a version between `dsi/1.1p1` and `dsi/1.3p1`, and
`configure.py` uses `dsi/1.1p1` (build 1024, `mwcc_40_1024` on decomp.me):

- `dsi/1.6sp1` and `dsi/1.6sp2` do not match overlay 4's switch statement.
- `dsi/1.1` differs from the later builds in one way: after a store to a field, it reuses the stored register where
  the game reloads the field (`strb r0, [r4, r7]; ldrb r0, [r4, r7]`). That reload is the compiler, not `volatile`.
- `dsi/1.1p1` through `dsi/1.3p1` produce identical code for every game function tried so far.

The ROM was not necessarily built with one compiler. The Pokémon Black decomp by Goldoire found library code in Black
built with other versions (`2.0/sp2p2` and `1.2`), so try them on library code that doesn't match. `configure.py`
extracts only the `dsi` compilers; the others are in `build/mwccarm.zip`. Extracted to `tools/mwccarm`, they can be
named by directory, as in `compiler_probe.py --compilers 2.0/sp2p2`, and `1.2` needs `--flags` without `-ipa file`.
`configure.py` downloads a library's compiler when `LIB_COMPILERS` lists it.
Game code needs the `dsi` builds: the evolution demo's view matches 36 of its 56 functions with every `2.0` build and
25 with `1.2`.

`tools/scripts/compiler_probe.py` compiles a C file with every version and compares each function against the
game, ignoring relocated bytes. For example:

```sh
.venv/bin/python tools/scripts/compiler_probe.py tools/compiler_tests/main_loops.c
```

It needs `pyelftools`, `capstone` and `pyyaml`. To look at a function's disassembly, run `dsd dis` into
`build/asm`, then use `tools/scripts/show_func.py`.

## Decompiling

Matching is checked per function with [objdiff](https://github.com/encounter/objdiff). A default `ninja` also writes
`objdiff.json` for the first configured version, Black 2 by default, which the objdiff GUI opens from this directory.
The current C mismatches and attempted translations still in assembly are tracked in
[Nonmatching functions](docs/nonmatching-functions.md).

1. Move a range of functions into a source file by adding it to the module's `delinks.txt`, as `src/ov004/event_worldtrade.c`
   is in `config/b2_us/arm9/overlays/ov004/delinks.txt`. Mark it `complete` once all its functions match. Add the
   same entry to `config/w2_us` with White 2's addresses, which `build/version_map.tsv` lists.
2. Write the C code. objdiff rebuilds the object with ninja whenever a source file changes, and diffs every function
   against the original.
3. objdiff can also create a decomp.me scratch for a function. The scratch uses compiler `mwcc_40_1024` (dsi/1.1p1),
   and a context file preprocessed from the source.

`ninja progress` prints how much of the game matches, from the report at `build/b2_us/report.json`.

`tools/scripts/add_source_file.py` adds a source file to both versions' `delinks.txt`, with White 2's ranges taken
from the version map. `tools/scripts/compiler_probe.py src/... --compilers 1.1 --show-diff 1.1` compiles a file and
diffs every function in it against the original. A library that `configure.py` builds with its own compiler, such
as SPL with `1.2/base`, gets that compiler and its flags by default. `--mismatches` leaves out the functions that
match, and `--functions` limits the table and diffs to the functions named. `--align` shows only the hunks of the
diff that differ, aligned so that an instruction more or less does not shift everything after it, which is what makes
a long function's diff readable.

`tools/scripts/try_variants.py src/... FUNC variants.c` puts each variant of a function, separated by lines of
`=====`, in place of its definition and probes it with the file's compiler, keeping the first that matches. `--score`
adds each variant's count of differing aligned lines, to tell apart variants of the same size.
`rename_symbol.py --file` renames each `old new` pair, one per line, of a file.

Things that affect whether MWCC output matches:

- Register allocation follows the declaration order of locals, so try reordering declarations when registers are
  swapped.
- Loads through a pointer are not moved above stores unless the pointee is `const`. A load that the original
  schedules early, such as an argument loaded before the stack arguments are stored, points to a `const` parameter.
- The same rule moves a call's stack argument stores. When loads through a pointer that is not `const` follow the
  call, the stack arguments are stored before the register arguments are set up. If the original stores them last,
  the pointer is `const`.
- A load through a `const` pointer is also reused across stores, as the World Tournament's `wbt_setup.c` reads an
  entrant's bit fields from one load, but it is not hoisted out of a loop: `wbt_party.c`'s filter check reads each
  list's count again in every iteration because its filter is `const`, where a plain pointer's count is loaded once
  before the loop.
- MWCC doesn't propagate constants into a variable of an enum type. A loop that still checks its bound before the
  first pass, as `for (p = 80; p <= 83; p++)` does in the Join Avenue's commands, or a sum that still adds a counter
  known to be 0, as the Battle Subway's loop over its music switches does, has an enum counter.
- An array index that is a sum, `a[i * 2 + x]`, is split into `(a + x) + i * 2`. When the original adds first and
  then indexes with the sum, the sum was put in a variable, as `seat` in `wbt_system.c`'s bracket code. Written as
  `seat = i * 2 + (won ? 0 : 1);`, the sum goes to the register of `i * 2`; with the `0` or `1` set by an `if` into a
  variable, it goes to that variable's register.
- Float arithmetic calls MWCC's runtime helpers, such as `_fadd` and `_ffix`, which swan names `__aeabi_*`. When a
  complete file fails to link on one of them, rename it to the MWCC name with `rename_symbol.py`.
- Structs passed by value go in registers and on the stack. Code that copies a struct to the stack and passes its
  address takes a pointer to a local copy.
- Stack locals are laid out in reverse declaration order.
- Static data is sorted by size. MWCC lists each object of a section when it is declared, a local struct initializer
  when its function is, and heapsorts the list by size starting from the last object declared. Objects of 64 bytes or
  more, local initializers and globals that no code refers to get sections of their own, and the sections are created as
  the sorted list is walked: the section the other objects share sits where its smallest object comes, so a 12-byte
  initializer goes before a file's 19-byte table unless something smaller is shared. A read of a const global whose
  initializer has been seen is folded and doesn't count as a reference. Taking its address counts, and so does reading
  it before its definition, as an unused inline function in a header does, even though that code is never emitted.
  `demo/shinka_demo_view.h` reconstructs such accessors for the evolution demo's helix constants. Heapsort is not
  stable, so objects of the same size come out in an order that depends on where every object in the file is declared,
  and moving one object can reorder others. `tools/scripts/rodata_order.py` predicts the layout for a declaration order
  and tries the orders of the objects given with `--permute`; `intro_graphic.c` matches only with its light setups
  declared after the function whose BG setups are local initializers.
- Overlay IDs are linker symbols, written `OVERLAY_ID(279)` from `gfl/overlay.h`, which gives the literal pool entry
  a relocation. Mark the literal in the config with `tools/scripts/config_fixes.py overlay-id`.
- A switch case that ends in the same code as another case is merged into it, so its end moves.
- Switch cases are laid out in source order, not by value, so the layout shows the order the cases were written in.
- A switch's comparison tree and jump tables depend on every case value, including cases with no code: the Battle
  Subway's command switch only splits its values as the game does with an empty `case 102:` inside its first jump
  table, and empty cases that sit between others still get a comparison.
- Of two variables that compete for the same register, the one used more gets it: one use of the Battle Subway
  command's result variable too many gave its register to the command ID. A single `*var = cond ? a : b;` counts as
  one use where an `if`/`else` with a store in each counts as two. Measured on small functions, the count is of
  instructions that refer to the variable once the code is cleaned up: its assignment, a parameter's move out of
  its argument register, and the shifts that narrow a `u8` or `u16` assigned from a wider value all count, while a
  use the optimizer deletes does not. A use inside an `if` or a switch case counts like any other. A variable a
  switch tests counts about 2 for each comparison and 4 for a jump table. On a tie the variable assigned first wins,
  whatever the declaration order, and a variable assigned later needs about one use more.
- Spilled variables get their stack slots in the order they are first assigned, the first at the lowest address,
  whatever their declaration order or use counts, in small functions. A value that sits above values assigned after
  it was spilled in a later round of register allocation. In the Join Avenue's records command, a large switch, the
  declarations counted too: one group of slots followed the declaration order in reverse, and the variables declared
  in a loop body took the highest slots, in their declaration order.
- A variable reused by several switch cases is split into one value per case (see below), and a split piece that is
  spilled takes the lowest slot whatever the declarations say. When the original has a case's spilled value among the
  declared variables' slots, that case had a variable of its own, as case 9 of the records command does.
- Where a flag is first set changes which register its zero is built in. When the original builds a flag's `FALSE` in
  the register of a call's argument, or copies it from another zero, the flag was set after the call or loop, as
  `value = joinAveTextHandler(...); found = FALSE;` and a loop's total followed by `any = FALSE;` in the Join Avenue's
  records command.
- A branch to the very next instruction is left by cross-jumping: two statements that end the same way, such as a
  store in each case of a switch, share their tail, and the first jumps to it even when it follows.
- `while (cond)` is rotated, with a copy of its test before the loop. A loop that tests once, at its top, is
  `while (TRUE)` with a `break` or `return` inside, as the Join Avenue's walks through its data are.
- Blocks are laid out in source order. A switch whose default code comes right after its comparisons or jump table
  had `default:` written first, and `if (f()) { n++; } else { return FALSE; }` puts the return after the code that goes
  on, where `if (!f()) { return FALSE; } n++;` puts it before.
- A sum that the original truncates to `s16` before comparing it was stored in an `s16` local, as the edges of the
  Join Avenue's balloons are; casting it in the comparison gives the same code but is not needed.
- Identical statements in different branches are merged, so a branch that jumps into the middle of another block had
  the same code in the source. For example, `if (a) { x = 3; y = 19; } else { x = 0; y = 19; }` compiles differently
  from `x = a ? 3 : 0; y = 19;`. A run of jumps to one store, as in the start menu's `StartMenu_MoveCursor`, is the
  same store written in several `else` branches.
- A variable gets a register or stack slot for each group of assignments that reach the same uses, so a variable
  that is assigned in two branches and stored once after them stays in one register, while a copy of the store in
  each branch lets the two assignments go to different places.
- An argument that is loaded before a call among the arguments, such as a print queue loaded before
  `BmpWin_GetBitmap(...)` in the same call, was passed to an inlined helper that makes the call, like
  `PrintWindow_Print`.
- A parameter passed on the stack is loaded at the function's entry, along with the register parameters, unless it is
  an `int` or `s32`, which is loaded where it is first used. `StartMenu_DrawFrame` takes its BG as a `u8`, as
  `GFL_BGSysFillScrArea` does.
- `static const` data goes in `.rodata`, so a table that the original has in `.data` is not `const`. The module
  check fails if a table ends up in the wrong section, even when every function matches.
- `a == 4 || a == 5` becomes a range check. Separate comparisons that jump to the same code come from separate
  branches with the same body.
- The types of locals and of the values they hold change how spilled values are scheduled. The trainer AI's speed
  comparison only matches with the speed function returning `u16` into `u16` locals: a spilled `u16` is reloaded after
  the call's stack argument is stored, while a spilled `u32` is reloaded before it.
- Masks written with `~` clear bits with `bic`. The game's `and` with a constant such as `0xef` is `x &= (u8)~FLAG`.
- `arr[count++] = x` and `arr[count] = x; count++;` allocate registers differently, as do `count = 1; arr[0] = x;` and
  the reverse order.
- When comparing a call's result, `v = f(); if (v == x)` and `if (f() == x)` put the operands of `cmp` in opposite
  orders.
- A loop that runs once is unrolled when its counter and bound have the same signedness. `int i; i < NELEMS(x)`
  compares unsigned, so the loop stays, as in the gym files' loops over one-element tables.
- Float arithmetic on a literal passes the literal first, as in `_fmul(4096.0f, x)` for `x * FX32_ONE`, whatever the
  source order. A constant kept in a local variable, which is reloaded from the literal pool at each use, keeps its
  place in the source instead, so `col * pixels` with `f32 pixels = 96.0f / 18;` passes `col` first.
- MWCC doesn't fold float arithmetic on a local variable that holds a constant, so `size / 2.0f` stays a call when
  `size` is a variable, while an expression of literals is folded.
- An address that an inner loop computes from the outer loop's counter, such as `&pieces->pieces[row][col]`, is hoisted
  into the inner loop's preheader, after the inner counter is set. When the original sets the inner counter before
  computing the row's address, the source takes the address in the inner loop rather than through a row pointer.
- A local variable that holds a constant, like `fx32 one = FX32_ONE;`, keeps its own stack slot or register, while the
  literal is hoisted out of a loop by the compiler. Extra hoisted constants in our output point to such a variable.
- A value the inner loop computes from the outer loop's counter alone, like `turn = row / 3`, is hoisted into the
  preheader too, so it can be written inside the inner loop. `row % 3` used in both conditions of an `if`/`else if`
  is computed once, later than a `rowInTurn` variable set with `turn` would be.
- Where `FX_Mul`'s sign extensions go depends on the statements. In `ShinkaDemoPieces_Init`, squaring `dy` before
  either square root, `distY = FX_Mul(dy, dy);`, keeps `dy`'s extension in a stack slot across the first one, and only
  the sum written as a `static inline` function, `distXZ = SquaredLengthXZ(dx, dz);`, puts that extension before the
  sum's multiplies. The same sum written in place, in any statement order, cast or split, does not.
- Variables declared in an inner block are allocated apart from the function's variables of the same name: in
  `ShinkaDemoPieces_Move`, the branch that moves a piece home declares its own `dx` and `dz`, which live on the stack
  while the other branches keep theirs in registers.
- Two stores of the same constant share a register when chained, and not when written as two initializers.
  `second = first = TRUE;` stores `first` first. `nearXZ = FALSE; nearY = FALSE;` in that order loads the zero twice,
  while the other order shares it.
- MWCC reuses a field it has loaded, across the 64-bit multiply helpers, so a value that the original keeps on the
  stack between `piece->home.x - piece->pos.x` and `piece->pos.x = piece->home.x` is MWCC's own copy, not a local.
  Writing it as a local changes which stack slots everything gets.
- A call whose argument is picked by branches comes from one of two sources, told apart by the layout. `f(x ? FALSE :
  TRUE)` tests `x` with `bne` to the second value, and puts the value for `x == 0` first. Two calls in an `if`/`else`,
  `if (x) f(FALSE); else f(TRUE);`, are merged into one call after the branches, with `beq` to the else branch and the
  then branch's value first. The evolution demo's touch screen flags and its view and effect creation are two calls.
- A caller narrows an argument for a `u8` or `u16` parameter with shifts before the call, so an argument passed without
  them is for a wider parameter.
- A caller that keeps an argument register untouched across a call to a function that ignores it is passing that
  argument: `ShinkaDemoPieces_IsFadeDone` takes the heap ID like the functions around it.
- Reads of a `const` table at a constant index are folded into immediates, but reads in a loop over the table are not,
  even when the loop runs once and is unrolled. An `ldm` from a table straight into argument registers is two fields
  read in such a loop, as the egg and evolution demos' particles load the resource of each of their one unit.
- Initializations are scheduled where they are written: `int i = 0;` declared after a call sets `i` after the call,
  while `for (i = 0; ...)` sets it at the loop, after any statements before the loop.
- An address passed to a `const` pointer parameter is converted, and the conversion is not shared with the same
  address written elsewhere. When the original computes an address a second time for another call, the first call
  takes a `const` pointer, as `GymElecFade_IsActive` does.
- A `static const` variable whose address is never taken is folded into the code and not emitted. If the original has
  it anyway, it is not `static`: a global that no code refers to gets a section of its own, laid out by size with the
  rest. An object laid out ahead of smaller ones is in a file of its own, linked first, as overlay 65's command table
  is in `scrcmd_pokemon_center_table.c`, and one laid out after larger ones is in a file linked after, as overlay 50's
  is in `scrcmd_bsubway_table.c`.
- `GFL_ASSERT` keeps its expression as a string in `.data`, so the variable it tests keeps its original name, as the
  Medal Rally's `p_sv` does.
- A clamp that ends in one store, with each limit copied into the value's register, is a conditional expression.
  `if`/`else if` stores each limit separately.
- The operands of `*` are loaded in source order, so a multiply whose registers are swapped has its operands swapped
  in the source.
- A product assigned to a variable of its own goes to a new register, with its operand copied there first
  (`mov r2, r1; mul r2, r0`), while a product used in place multiplies into the operand's register. The Join Avenue
  shop's arrow is placed with `row = ...; y = row * rowHeight; pos.y = y + 22;`.
- An address computed before calls is reused after them only when the expression is the same, types included:
  `a[j].f` read before the calls lets a later `a[j].g` reuse the address, but not `a[(u32)j].g`. An address that the
  original computes again, where ours keeps it on the stack, is written differently at one of the two places. An
  inline accessor does it naturally, since its parameter is a copy of the index in the parameter's type: the Join
  Avenue shop reads `ResortShop_GetEntry(wk, j)->id` with a `u32` index for an `int` `j`, and its later
  `wk->entries[j]` is computed again while `wk->entries[i]` is reused.
- A value that a loop uses and the code after it uses again is reused from the copy hoisted out of the loop. When
  the original computes it again after the loop, the loop assigns it to a variable declared in the loop's body, as
  `int wanted = mode + 1;` in the Join Avenue's records command.
- A value moved into an argument register just before a call, and used for nothing else, is an argument the prototype
  is missing. `GFL_SEPlayKeepVol` takes the sound's player as well as the sound.
- `compiler_probe.py` skips relocated words, so a wrong addend, such as a table index that the compiler folds into a
  literal pool address, or a call to the wrong runtime helper, only shows when the module check fails. Division and
  modulo call `_s32_div_f` for a signed operand and `_u32_div_f` (swan's `__aeabi_uidivmod`) for an unsigned one; a
  `u8` or `u16` promotes to a signed `int`, so `(u8)id % 5u` is the unsigned one, and so is a `u16` divided by a
  `u32`. Compare the built overlay in `build/<version>/build`
  with the original to find it.
- NitroSDK's inline functions take enums, such as `GXBGColorMode`, and the BG system's `GFL_BGSysCreateBG` only loads
  every argument of `G2_SetBG0Control` before shifting any with enum parameters. `nitro/gx.h` keeps the SDK's types for
  this reason.
- A NULL check written on a field, `if (bgs[bg].screen != NULL) { void *screen = bgs[bg].screen; ... }`, gives
  different stack slots from the same check on a local loaded before it, as `GFL_BGSysLoadScrCore` shows.
- When the order of instructions differs and no source change moves it, try `tools/scripts/permuter_setup.py`, which
  prepares a function for [decomp-permuter](https://github.com/simonlindholm/decomp-permuter). Its result can point to
  a plain change: `GFL_BGSysAllocChar`'s registers only matched with its tile size, a `u8` from a call, in an `int`.

## Scripts

The script VM in `src/system/vm.c` runs four sets of commands: field events, the trainer AI, battle move animations and
musicals. Scripts are files in the ROM's NARC archives. Each command is a 16-bit ID followed by its arguments.

The trainer AI scripts are built from source. Archive `a/1/6/9` holds 14 scripts, one per AI flag, which run in turn
for each flag the trainer has: flag bit N runs script N (`AI_FLAG_*` in `include/constants/tr_ai.h`). They are
written in `data/tr_ai/NN_name.s`, numbered by their flag bit, with the macros in
`include/asm/tr_ai.inc`, in the style of [pokeplatinum](https://github.com/pret/pokeplatinum)'s trainer AI. This
game's scripts grew out of Gen 4's, so most commands, routines and labels are the same as pokeplatinum's, and share
their names. Gen 5's additions, such as the handlers of the new move effects, are named in the same style. Each
script starts with a comment on what it does, and bugs are marked where the code shows them.

```
Basic_CheckForImmunity:
    IfMoveEffectivenessEquals TYPE_EFFECTIVENESS_IMMUNE, ScoreMinus10
    LoadBattlerAbility AI_BATTLER_ATTACKER
    IfLoadedEqualTo ABILITY_MOLD_BREAKER, Basic_CheckSoundproof
    LoadBattlerAbility AI_BATTLER_DEFENDER
    IfLoadedEqualTo ABILITY_VOLT_ABSORB, Basic_CheckElectricAbsorption
```

Each macro is one command of `src/ov170/tr_ai.c`. Its arguments are 32-bit. Jump and table arguments are labels,
which the macros encode relative to the end of the argument. The Load commands set a value that `IfLoadedEqualTo`
and the other comparisons test. Commands that behave differently from Gen 4's have a comment in the macros, and the
commands that do nothing here are named `DummyNN` after their ID, as pokeplatinum does.

Scripts go through the C preprocessor, so they use the same constants as the C code. `include/constants/` holds
only `#define`s for this reason. The constants come from:

- The game's text, for moves, abilities, items, species and types, by `tools/scripts/make_constants.py`, which reads
  it with `tools/scripts/msgdata.py`.
- pokeplatinum, for the move effects and held item effects that Gen 4 has, whose IDs this game keeps. Gen 5's move
  effects are named after their first move.
- The move data, for move categories and the conditions that moves inflict.
- The scripts themselves, for stat stages, weather, side and field conditions and genders: where a routine is the same
  as pokeplatinum's, its values show which constant is which.

```sh
python3 tools/scripts/make_constants.py extract/b2_us/files/a/0/0/2 include/constants
```

`ninja` assembles each script with `clang`, converts it to a binary with `llvm-objcopy`, packs the binaries with
`tools/scripts/narc.py` into `build/<version>/files/a/1/6/9`, and checks the archive against the extracted one. The
ROM is built from `build/<version>/files`, which `tools/scripts/files_tree.py` fills with links to the extracted files,
except for the files built from source. `ARCHIVES` in `configure.py` lists them.

The scripts are source, edited by hand. `tools/scripts/tr_ai_script.py` disassembled them, and writes the macros:

```sh
python3 tools/scripts/tr_ai_script.py inc include/asm/tr_ai.inc
python3 tools/scripts/tr_ai_script.py disasm extract/b2_us/files/a/1/6/9 OUTPUT_DIR [--labels NAMES.json]
```

The disassembler follows the jumps from the start of each script. Bytes it does not reach are decoded as commands
where they are valid, then as tables, and otherwise kept as `.byte`. A value compared with the loaded value is written
as a constant when every way to the comparison loads the same kind of value. Labels are named after their offset,
unless `--labels` gives names.

### Field scripts

The field scripts, archive `a/0/5/6`, are built from source in `data/field_scripts/NNNN.s`, with the macros in
`include/asm/field_script.inc`. Both versions have the same archive. It holds a script file and a map script table
for each zone, and the global scripts, which zones start by their IDs (from 2000 up). A script file starts with the
offsets of its scripts, followed by the scripts and their movement data. A map script table lists the scripts that
the zone runs at points such as its loading.

```
L_015C:
    ItemSub ITEM_POKE_BALL, 1, 0x8010
    ItemAdd ITEM_GREAT_BALL, 1, 0x8010
    WorkSetConst 0x8020, 2
    VMReturn
```

Commands are named after swan's names for their handlers, such as `s0024_FlagReset` for `FlagReset`. Of the ones swan
does not name, a few are named after the function they call, such as `IsFestMissionAvailable`. Those whose calls only
tell the save data they use get its area, such as `MusicalCmd_0165`, and the rest are `Cmd_NNNN`.

Commands from ID 1000 up come from the script plugin, overlays that the zone loads. They take their handler's name once
it has one, such as `BadgeGateCmd_PlayCheck`, and are `PluginN_CmdNNNN` until then. Overlay 12's `SCRIPT_PLUGIN_TABLE`
lists the plugins:

| Plugin | Overlays | For | Files named in the overlays |
|---|---|---|---|
| 1 | 50 | Battle Subway: Gear Station and the trains | |
| 2 | 51 | The Royal Unova, the "pleasure boat" of overlay 36's `pleasure_boat.c` | |
| 3 | 52 | Pokémon League: the Elite Four's rooms, whose gimmicks are overlays 122 (Shauntal), 123 (Grimsley), 124 (Marshal), 125 (Caitlin) and 120 (the Champion) | |
| 4 | 53 | Poké Transfer Lab | `scrcmd_palpark.c` |
| 5 | 54 | Abyssal Ruins | |
| 6, 7 | 55, and 56 or 57 | Pokémon World Tournament | `wbt_*.c` |
| 8 | 58 and 59, with 60 swapped in for the shops | Join Avenue | `scrcmd_resort.c`, `scrcmd_medalinfo.c`, `scrcmd_resort_shop.c` |
| 9 | 61 | Black Tower and White Treehollow | |
| 10 | 62 | Pokéstar Studios | `pokewood_*.c` |
| 11 | 63 | Victory Road's badge gates | |
| 12 | 64 | The Plasma Frigate, with its password device | |
| 13 | 65 | Pokémon Centers: Mr. Medal's Medal Rally, and records of link battles | |
| 14 to 16 | 66 to 68 | Not identified yet: 15 has the DNA Splicers and Terrakion, 16 Meloetta's Relic Song and the Swords of Justice | |

Our files take those names where the overlay has them, and otherwise follow them, as `scrcmd_badge_gate.c`.

Conditions are computed on a stack: `VMStackPush 0x8010`, `VMStackPushConst 0`, `VMStackCmp CMP_EQ`, and then
`VMJumpIf CMP_STACK` jumps if the result is TRUE. `VMJumpIf` can also test the comparison register that
`WorkCmpConst` and the other Cmp commands set (`cmpResult` in `system/vm.h`). The comparisons are in
`include/constants/field_script.h`. Arguments that take a value can take a variable instead: IDs from `0x4000` are
saved event work and from `0x8000` the script's own work, and the scripts write them in hex.

Arguments are written as constants where the handler shows what they are: items, moves, species, abilities and types,
and `MSGFILE_SCRIPT` for the script's own text file. Each command that shows a message has its text as a comment,
from the zone's or the global script's text file in the script message archive (`a/0/0/3`).

The arguments of every command come from its handler. `tools/scripts/field_command_table.py` follows the reads of the
script in each handler's disassembly: `VM_Read16`, `VM_Read32`, `ScriptReadAny` (a value or a variable),
`ScriptReadVar`, loads through the VM's pc, and the same in the functions the handler calls with the VM. It follows
each value read to the functions it is passed to, and a known function such as `BagSave_AddItem` or
`LoadFieldScriptMessage` tells what the argument is. It writes `tools/scripts/field_commands.json`, and needs
`dsd dis` output in `build/asm`. Every script file decodes with these arguments.

A script file has the plugin of the zones that use it, or else of the zones that start its scripts. A few global
files get the only plugin whose commands they decode with, and files whose plugin is not known keep plugin commands
as bytes. The Join Avenue shop commands swap one of the plugin's overlays, which changes the arguments of its
commands, and the disassembler follows that.

```sh
python3 tools/scripts/field_command_table.py tools/scripts/field_commands.json
python3 tools/scripts/field_script.py inc include/asm/field_script.inc
python3 tools/scripts/field_script.py disasm extract/b2_us OUTPUT_DIR
```

The disassembler follows the code from each script. Bytes it does not reach are decoded as code where it ends
cleanly, then as movement data, and otherwise kept as `.byte`: about 2,500 bytes, mostly in global files whose plugin
is not known. The scripts are still written by the disassembler, so improvements to it can be applied by running it
again.

## Versions

Black 2 is the primary version. White 2 is the same program: of its 41,423 functions, 41,311 are byte-identical to
Black 2's apart from relocations, and 112 differ. Every White 2 symbol with a Black 2 counterpart uses the Black 2 name,
so source files are shared, and code that differs uses the `BLACK2` and `WHITE2` defines. Symbols only found in White 2
get a `_w2_us` suffix.

`tools/scripts/version_map.py` pairs the functions of two versions by their bytes, and pairs other symbols through
relocations and section offsets. Functions that differ are marked `different` in `build/version_map.tsv`. Check them
with `compiler_probe.py --version w2_us`, which compiles with the `WHITE2` define, before marking a file complete.

## Names

Names come from the [swan](https://github.com/ds-pokemon-hacking/swan) symbol databases (GPL-3.0) by the
ds-pokemon-hacking community, revision `4324f73` (2025-07-03). `tools/scripts/import_swan.py` applies them:

- IDA-generated names are skipped.
- A name is only applied if a symbol starts exactly at its address.
- Names are carried between versions through the version map.
- Only default `func_`/`data_` names are replaced.

```sh
.venv/bin/python tools/scripts/version_map.py b2_us w2_us -o build/map_b2_w2.tsv --symbols-output build/map_b2_w2_symbols.tsv
.venv/bin/python tools/scripts/import_swan.py path/to/swan --map build/map_b2_w2.tsv --symbols-map build/map_b2_w2_symbols.tsv
```

Names that swan lacks are ours, and are recorded in `config/names.txt` by module and Black 2 address.
`tools/scripts/rename_symbol.py` renames a symbol in both versions, updates the source files and records the name:

```sh
.venv/bin/python tools/scripts/rename_symbol.py func_ov035_0217ed70 ElScoreboard_Create
```

### Code organization

Each source file is one of the game's original source files. The linker placed one object per original file, so a
file's `.text`, `.rodata`, `.data` and `.bss` are each one contiguous range, and the files come in the same order in
every section.

- Name a file after the original. Many functions pass their file's name to `GFL_HeapAllocate` or an assert, so the
  overlay embeds strings such as `"resort_npc.c"`, which sit in that file's `.data`. A file whose name the ROM doesn't
  give gets a name for what it does, such as `gym_nacrene.c`; never an overlay number or a counter.
- An original file is one entry in `delinks.txt`, covering its whole range in each section, even while only some of
  its functions are written. The entry stays without `complete` until every function matches, and the original code
  is linked until then, as with `src/ov059/scrcmd_resort.c`. Never split a file into several entries to link the
  matching parts early, and never put two original files in one entry.
- The C file holds its functions in address order. A function that doesn't match yet stays in the file as the closest
  C found, so objdiff shows how far off it is. Library code built with another compiler can differ: SPL's compiler
  emits a file's functions in reverse source order, so `src/spl/` files hold theirs in reverse address order.
- An overlay's files go in `src/ovNNN/`. The main module's files go by library, mirroring `include/`: `src/gfl/` (Game
  Freak's library), `src/system/` (the game's own code), `src/spl/`, and later `src/nitro/` and `src/nnsys/`. A
  library's private header stays with its sources, as `src/spl/spl_internal.h` does.
- `tools/scripts/source_files.py OVERLAY` finds the boundaries: it lists the embedded file names, the functions that
  refer to them, and how well each boundary between two functions keeps every section's data references in file
  order and the calls inside one file.
  `docs/source-files.md` lists every overlay's files with the evidence for their names (`source_files.py --markdown`).
- `struct_decls.h` declares every struct type once, as `typedef struct Name Name;`. The header of the module that
  owns a struct defines its layout when that is known (`struct Name { ... };`, without another typedef), and other
  code only uses pointers to it. A struct that only one file uses, such as an event's work, is defined in that file.
  A layout is defined once: two files that need the same struct share it through the owner's header, and a partial
  layout with padding is still the one definition.
- Headers are grouped like the game's code: `system/` (game system, game data, events), `field/`, `save/`, `gfl/`
  (Game Freak's library), `pml/` (Pokémon data), `battle/`, `demo/`, `dsprot/` and `constants/`, and by library:
  `nitro/` (NitroSDK), `nnsys/` (NitroSystem: FND, G2D, G3D and GFD) and `spl/` (the SPL particle library).
  A header is named after the original file that owns its declarations, or after swan's header for it, such as
  `field/field_3dci.h`.
- Put functions, data and callback tables used across source files or overlays in the owning file's header. Declare
  external data with `extern` there, and include the header at each use. Do not add `extern` declarations or
  prototypes of other files' functions in a `.c` file. A file includes its own header, so its definitions are checked
  against the declarations.
- Each proc that an event starts has a header in `app/` with its parameter struct, proc table and overlay ID, such as
  `app/worldtrade.h`. Each event has a header in `field/` with its create functions, such as
  `field/event_worldtrade.h`.
- Functions only called within their file are `static` where linking permits it and declared at the top of the file,
  since `-requireprotos` requires a prototype for every function.
- Event callbacks take `void *data`, as `GameEventCallback` does, and cast it to their work.
- A bug gets a `// BUG:` comment on what goes wrong. Where a fix is clear, it goes in an `#ifdef BUGFIX` block next to
  the original code, which stays in the `#else` branch, as in `bg_sys.c`'s `GFL_BGSysFlipTile`.
- Names, layouts and constants from swan are marked as such. swan's headers are generated for hacking tools, so
  they are a reference rather than copied as they are. A type that swan doesn't name gets a name from its owner,
  such as `ResortNPC` in `resort_npc.c`, and structs with the same layout and purpose are one type.

`ninja format` formats `src/` and `include/` with clang-format, using `.clang-format`. `compile_flags.txt` makes
clangd check the code as 32-bit ARM.

### Fixing the configs

dsd sometimes cannot tell which overlay a relocation points to, because many overlays share addresses. It then lists
every candidate, such as `module:overlays(36,214)`, and the build links to the first one, which gives the right bytes
but the wrong symbol. `tools/scripts/config_fixes.py` fixes such relocations and other mistakes in both versions, and
records them in `config/fixes.txt`:

```sh
.venv/bin/python tools/scripts/config_fixes.py reloc-module overlays/ov004 'overlay(214)' 0x0214f6c0
.venv/bin/python tools/scripts/config_fixes.py overlay-id overlays/ov004 214 0x0214f6bc
```

It also removes relocations and symbols that are not real (`remove-reloc`, `remove-symbol`), and gives a function a
second name with `add-label`. MWCC calls the runtime's 64-bit multiply `_ll_mul` for signed values and `_ull_mul` for
unsigned ones, while the game has one copy of it, so `_ll_mul` is a label on `_ull_mul`. In the same way, `_fflt` (int
to float) is a label on swan's `__aeabi_i2f`, and `_u32_div_f` (unsigned division) on `__aeabi_uidivmod`. `add-data`
adds an object that nothing references, such as a global constant that the compiler folds into the code but still emits,
so that the object before it does not seem to run on over it.

A relocation that dsd could not pin to one overlay only links while its symbol is global. When a function becomes
`static` in a decompiled file, check `relocs.txt` of both versions for relocations to its address with several
candidate modules, and fix the ones that belong to another overlay. Field gimmicks, such as gym puzzles, share one load
address, so calls between them are often ambiguous; the gimmick table in ov036 gives each entry's overlay ID, and its
pointers are fixed from it.

## Regenerating configs

After improving dsd's analysis, regenerate the configs of both versions and import the names again:

```sh
.venv/bin/python tools/scripts/regenerate_configs.py path/to/swan
```

This keeps the source files listed in each `delinks.txt`, but loses any other manual changes to the configs. It runs
the following command once per version:

```sh
tools/dsd init --rom-config extract/b2_us/config.yaml --output-path config/b2_us --build-path build/b2_us \
    --allow-unknown-function-calls
```

The fixes in `config/fixes.txt` and the names from swan and `config/names.txt` are applied again afterwards, so only
changes made to the configs by hand are lost.

## License

This project is licensed under the GNU General Public License v3.0, see [LICENSE](LICENSE). The symbol names imported
from swan are also GPL-3.0.

The repository contains no game code or assets. Building it requires your own dump of the game.
