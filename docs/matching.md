# How MWCC compiles

What decides whether CodeWarrior's output (`dsi/1.1p1`, Thumb, `-O4,p`) matches the game, learned from functions that
did or didn't match. Each rule names the function that shows it. They are grouped by what a diff shows;
`.claude/skills/match-function/levers.md` indexes the same rules by symptom in one line each. A rule found on one
function and confirmed on another goes here, next to the related rules; see [Decompiling](decompiling.md) for the
tools that show the differences.

## Registers

Same instructions, registers swapped.

- Register allocation follows the declaration order of locals, so try reordering declarations when registers are
  swapped.
- Of two variables that compete for the same register, the one used more gets it: one use of the Battle Subway
  command's result variable too many gave its register to the command ID. A single `*var = cond ? a : b;` counts as
  one use where an `if`/`else` with a store in each counts as two. Measured on small functions, the count is of
  instructions that refer to the variable once the code is cleaned up: its assignment, a parameter's move out of
  its argument register, and the shifts that narrow a `u8` or `u16` assigned from a wider value all count, while a
  use the optimizer deletes does not. A use inside an `if` or a switch case counts like any other. A variable a
  switch tests counts about 2 for each comparison and 4 for a jump table. On a tie the variable assigned first wins,
  whatever the declaration order, and a variable assigned later needs about one use more.
- A variable gets a register or stack slot for each group of assignments that reach the same uses, so a variable
  that is assigned in two branches and stored once after them stays in one register, while a copy of the store in
  each branch lets the two assignments go to different places.
- Where a flag is first set changes which register its zero is built in. When the original builds a flag's `FALSE` in
  the register of a call's argument, or copies it from another zero, the flag was set after the call or loop, as
  `value = joinAveTextHandler(...); found = FALSE;` and a loop's total followed by `any = FALSE;` in the Join Avenue's
  records command.
- `arr[count++] = x` and `arr[count] = x; count++;` allocate registers differently, as do `count = 1; arr[0] = x;` and
  the reverse order.
- An array index that is a sum, `a[i * 2 + x]`, is split into `(a + x) + i * 2`. When the original adds first and
  then indexes with the sum, the sum was put in a variable, as `seat` in `wbt_system.c`'s bracket code. Written as
  `seat = i * 2 + (won ? 0 : 1);`, the sum goes to the register of `i * 2`; with the `0` or `1` set by an `if` into a
  variable, it goes to that variable's register.
- The operands of `*` are loaded in source order, so a multiply whose registers are swapped has its operands swapped
  in the source.
- A product assigned to a variable of its own goes to a new register, with its operand copied there first
  (`mov r2, r1; mul r2, r0`), while a product used in place multiplies into the operand's register. The Join Avenue
  shop's arrow is placed with `row = ...; y = row * rowHeight; pos.y = y + 22;`.
- Two stores of the same constant share a register when chained, and not when written as two initializers.
  `second = first = TRUE;` stores `first` first. `nearXZ = FALSE; nearY = FALSE;` in that order loads the zero twice,
  while the other order shares it.
- Variables declared in an inner block are allocated apart from the function's variables of the same name: in
  `ShinkaDemoPieces_Move`, the branch that moves a piece home declares its own `dx` and `dz`, which live on the stack
  while the other branches keep theirs in registers.
- Two values that the original keeps in one register, one dead before the other is set, were one variable: the PC
  box's `func_ov255_021cdcc8` keeps the party position and then its result in the same variable, where two
  variables get two registers.
- A loop condition written with a local for its row start, `start = pos + j * 6; if (x >= start && x < w + start)`,
  allocates registers differently from the same sums written in both comparisons: the PC box's `func_ov255_021d229c`
  only matched with the sums written out.

## Stack slots

Same code, other `sp` offsets or frame size.

- Stack locals are laid out in reverse declaration order.
- Spilled variables get their stack slots in the order they are first assigned, the first at the lowest address,
  whatever their declaration order or use counts, in small functions. A value that sits above values assigned after
  it was spilled in a later round of register allocation. In the Join Avenue's records command, a large switch, the
  declarations counted too: one group of slots followed the declaration order in reverse, and the variables declared
  in a loop body took the highest slots, in their declaration order.
- A variable reused by several switch cases is split into one value per case (see Registers), and a split piece that is
  spilled takes the lowest slot whatever the declarations say. When the original has a case's spilled value among the
  declared variables' slots, that case had a variable of its own, as case 9 of the records command does.
- A loop counter stored to the slot of a local whose address is passed elsewhere is that local reused: in the PC box's
  range pick, `func_ov255_021c445c`, the row loop counts with `y`, the touch position's `&y`, so the counter lives in
  `y`'s slot and the frame has no slot of its own for it. Pairs such as `width, height` that the original keeps in two
  sets of slots are block locals in two blocks; declaring them once at the top shares the slots and shrinks the frame.
  In `PokeIconMoveDataMake` the slots only matched once each reused variable was made block local and the loops used the
  original's counters; reordering the declarations did nothing.
- A NULL check written on a field, `if (bgs[bg].screen != NULL) { void *screen = bgs[bg].screen; ... }`, gives
  different stack slots from the same check on a local loaded before it, as `GFL_BGSysLoadScrCore` shows.
- MWCC reuses a field it has loaded, across the 64-bit multiply helpers, so a value that the original keeps on the
  stack between `piece->home.x - piece->pos.x` and `piece->pos.x = piece->home.x` is MWCC's own copy, not a local.
  Writing it as a local changes which stack slots everything gets.
- The types of locals and of the values they hold change how spilled values are scheduled. The trainer AI's speed
  comparison only matches with the speed function returning `u16` into `u16` locals: a spilled `u16` is reloaded after
  the call's stack argument is stored, while a spilled `u32` is reloaded before it.
- Structs passed by value go in registers and on the stack. Code that copies a struct to the stack and passes its
  address takes a pointer to a local copy.

## Instruction order

Same instructions, scheduled in another order.

- Loads through a pointer are not moved above stores unless the pointee is `const`. A load that the original
  schedules early, such as an argument loaded before the stack arguments are stored, points to a `const` parameter.
- The same rule moves a call's stack argument stores. When loads through a pointer that is not `const` follow the
  call, the stack arguments are stored before the register arguments are set up. If the original stores them last,
  the pointer is `const`.
- A load through a `const` pointer is also reused across stores, as the World Tournament's `wbt_setup.c` reads an
  entrant's bit fields from one load, but it is not hoisted out of a loop: `wbt_party.c`'s filter check reads each
  list's count again in every iteration because its filter is `const`, where a plain pointer's count is loaded once
  before the loop.
- Initializations are scheduled where they are written: `int i = 0;` declared after a call sets `i` after the call,
  while `for (i = 0; ...)` sets it at the loop, after any statements before the loop.
- An argument that is loaded before a call among the arguments, such as a print queue loaded before
  `BmpWin_GetBitmap(...)` in the same call, was passed to an inlined helper that makes the call, like
  `PrintWindow_Print`.
- A computed argument whose arithmetic comes before the loads of the arguments before it was assigned to a variable
  first: the PC box's `Box2Main_VFuncPartyInPokeMove` adds 30 to the party's count before loading the cursor
  position only with `putPos = count + 30; PokeIconMoveDataMake(syswk, syswk->pos, putPos);`.
- A parameter passed on the stack is loaded at the function's entry, along with the register parameters, unless it is
  an `int` or `s32`, which is loaded where it is first used. `StartMenu_DrawFrame` takes its BG as a `u8`, as
  `GFL_BGSysFillScrArea` does.
- NitroSDK's inline functions take enums, such as `GXBGColorMode`, and the BG system's `GFL_BGSysCreateBG` only loads
  every argument of `G2_SetBG0Control` before shifting any with enum parameters. `nitro/gx.h` keeps the SDK's types for
  this reason.
- Where `FX_Mul`'s sign extensions go depends on the statements. In `ShinkaDemoPieces_Init`, squaring `dy` before
  either square root, `distY = FX_Mul(dy, dy);`, keeps `dy`'s extension in a stack slot across the first one, and only
  the sum written as a `static inline` function, `distXZ = SquaredLengthXZ(dx, dz);`, puts that extension before the
  sum's multiplies. The same sum written in place, in any statement order, cast or split, does not.

## An instruction too many or too few

Narrowing shifts, reloads, recomputed addresses and folded constants.

- A compound assignment to a narrow field narrows its right side first: `work->checkFlag &= 0xff ^ (1 << waza);` on a
  `u8` shifts the mask down to a byte before the `and`, while `work->checkFlag = work->checkFlag & (0xff ^ (1 << waza));`
  ands the full mask, as the PC box's `Box2Main_PokeFreeWazaCheck` does.
- A chained assignment to fields, `a->x = a->y = value;`, stores `y`, reloads it and stores `x`. When the original
  narrows the value once and stores it to both, the stores were separate statements, as in the PC box's
  `PokeIconChgDataMake`.
- A caller narrows an argument for a `u8` or `u16` parameter with shifts before the call, so an argument passed without
  them is for a wider parameter.
- A wider parameter stored into a narrow bit field is narrowed to the field's type and then shifted into place, while
  a `u8` parameter is trusted and shifted at once. The PC box's `func_ov255_021cc460` takes its button's actor and
  palette as `u32` and narrows them in the stores to its 7- and 4-bit fields.
- A sum that the original truncates to `s16` before comparing it was stored in an `s16` local, as the edges of the
  Join Avenue's balloons are; casting it in the comparison gives the same code but is not needed.
- Masks written with `~` clear bits with `bic`. The game's `and` with a constant such as `0xef` is `x &= (u8)~FLAG`.
- MWCC doesn't propagate constants into a variable of an enum type. A loop that still checks its bound before the
  first pass, as `for (p = 80; p <= 83; p++)` does in the Join Avenue's commands, or a sum that still adds a counter
  known to be 0, as the Battle Subway's loop over its music switches does, has an enum counter.
- A local variable that holds a constant, like `fx32 one = FX32_ONE;`, keeps its own stack slot or register, while the
  literal is hoisted out of a loop by the compiler. Extra hoisted constants in our output point to such a variable.
- An address computed before calls is reused after them only when the expression is the same, types included:
  `a[j].f` read before the calls lets a later `a[j].g` reuse the address, but not `a[(u32)j].g`. An address that the
  original computes again, where ours keeps it on the stack, is written differently at one of the two places. An
  inline accessor does it naturally, since its parameter is a copy of the index in the parameter's type: the Join
  Avenue shop reads `ResortShop_GetEntry(wk, j)->id` with a `u32` index for an `int` `j`, and its later
  `wk->entries[j]` is computed again while `wk->entries[i]` is reused.
- A value that a loop uses and the code after it uses again is reused from the copy hoisted out of the loop. When
  the original computes it again after the loop, the loop assigns it to a variable declared in the loop's body, as
  `int wanted = mode + 1;` in the Join Avenue's records command.
- An address passed to a `const` pointer parameter is converted, and the conversion is not shared with the same
  address written elsewhere. When the original computes an address a second time for another call, the first call
  takes a `const` pointer, as `GymElecFade_IsActive` does.
- Reads of a `const` table at a constant index are folded into immediates, but reads in a loop over the table are not,
  even when the loop runs once and is unrolled. An `ldm` from a table straight into argument registers is two fields
  read in such a loop, as the egg and evolution demos' particles load the resource of each of their one unit.
- A value moved into an argument register just before a call, and used for nothing else, is an argument the prototype
  is missing. `GFL_SEPlayKeepVol` takes the sound's player as well as the sound.
- A caller that keeps an argument register untouched across a call to a function that ignores it is passing that
  argument: `ShinkaDemoPieces_IsFadeDone` takes the heap ID like the functions around it.

## Branches and block layout

- Blocks are laid out in source order. A switch whose default code comes right after its comparisons or jump table
  had `default:` written first, and `if (f()) { n++; } else { return FALSE; }` puts the return after the code that goes
  on, where `if (!f()) { return FALSE; } n++;` puts it before.
- Identical statements in different branches are merged, so a branch that jumps into the middle of another block had
  the same code in the source. For example, `if (a) { x = 3; y = 19; } else { x = 0; y = 19; }` compiles differently
  from `x = a ? 3 : 0; y = 19;`. A run of jumps to one store, as in the start menu's `StartMenu_MoveCursor`, is the
  same store written in several `else` branches.
- A branch to the very next instruction is left by cross-jumping: two statements that end the same way, such as a
  store in each case of a switch, share their tail, and the first jumps to it even when it follows.
- An early `return` at the top of a long function jumps to the nearest `b` to the epilogue. When the original skips the
  body with `bne` over a `b` to the very end, the body was wrapped in `if (cond) { ... }`, as in the PC box's
  `Box2Main_PokeDataMove`.
- A function whose last check returns a register that also served as a `NULL` argument, `mov r4, #0` ... `cmp r0, #1;
  beq; mov r4, #1; mov r0, r4`, ends in `return f(...) == TRUE ? FALSE : TRUE;`; an `if` with two returns, or `!=`,
  merges that return with an earlier one. The PC box's `Box2Main_PokeItemMoveCheck` shows it.
- The two halves of an `if`/`else` that end in the same computation are merged by cross-jumping, unless they end the
  function: a step of the PC box's icon moves sets `vx` and `mx` in each branch of the x test and `vy` and `my` in each
  branch of the y test, and only the x branches share their tail; a variable for the difference merges the y branches
  too and doesn't match.
- When comparing a call's result, `v = f(); if (v == x)` and `if (f() == x)` put the operands of `cmp` in opposite
  orders.
- The operands of `==` between two fields are compared in source order: `syswk->tray == syswk->getTray` gives
  `cmp tray, getTray`, as the PC box's `func_ov255_021cc8dc` needs.
- A store picked by a test, `if (pos < 30) syswk->pos = pos; else syswk->pos = 0;`, branches past the second value with
  `bhs` and `b`, while clamping a local first, `if (pos >= 30) pos = 0; syswk->pos = pos;`, uses one `blo`. The PC box's
  `func_ov255_021c8b38` is the first.
- `a == 4 || a == 5` becomes a range check. Separate comparisons that jump to the same code come from separate
  branches with the same body.
- A clamp that ends in one store, with each limit copied into the value's register, is a conditional expression.
  `if`/`else if` stores each limit separately.
- A call whose argument is picked by branches comes from one of two sources, told apart by the layout. `f(x ? FALSE :
  TRUE)` tests `x` with `bne` to the second value, and puts the value for `x == 0` first. Two calls in an `if`/`else`,
  `if (x) f(FALSE); else f(TRUE);`, are merged into one call after the branches, with `beq` to the else branch and the
  then branch's value first. The evolution demo's touch screen flags and its view and effect creation are two calls.

## Loops

- `while (cond)` is rotated, with a copy of its test before the loop. A loop that tests once, at its top, is
  `while (TRUE)` with a `break` or `return` inside, as the Join Avenue's walks through its data are.
- A loop that runs once is unrolled when its counter and bound have the same signedness. `int i; i < NELEMS(x)`
  compares unsigned, so the loop stays, as in the gym files' loops over one-element tables.
- An address that an inner loop computes from the outer loop's counter, such as `&pieces->pieces[row][col]`, is hoisted
  into the inner loop's preheader, after the inner counter is set. When the original sets the inner counter before
  computing the row's address, the source takes the address in the inner loop rather than through a row pointer.
- A value the inner loop computes from the outer loop's counter alone, like `turn = row / 3`, is hoisted into the
  preheader too, so it can be written inside the inner loop. `row % 3` used in both conditions of an `if`/`else if`
  is computed once, later than a `rowInTurn` variable set with `turn` would be.

## Switches

- Switch cases are laid out in source order, not by value, so the layout shows the order the cases were written in.
- A switch's comparison tree and jump tables depend on every case value, including cases with no code: the Battle
  Subway's command switch only splits its values as the game does with an empty `case 102:` inside its first jump
  table, and empty cases that sit between others still get a comparison.
- A switch case that ends in the same code as another case is merged into it, so its end moves.

## Floats and runtime helpers

- Float arithmetic calls MWCC's runtime helpers, such as `_fadd` and `_ffix`, which swan names `__aeabi_*`. When a
  complete file fails to link on one of them, rename it to the MWCC name with `rename_symbol.py`.
- Float arithmetic on a literal passes the literal first, as in `_fmul(4096.0f, x)` for `x * FX32_ONE`, whatever the
  source order. A constant kept in a local variable, which is reloaded from the literal pool at each use, keeps its
  place in the source instead, so `col * pixels` with `f32 pixels = 96.0f / 18;` passes `col` first.
- MWCC doesn't fold float arithmetic on a local variable that holds a constant, so `size / 2.0f` stays a call when
  `size` is a variable, while an expression of literals is folded.
- `compiler_probe.py` skips relocated words, so a wrong addend, such as a table index that the compiler folds into a
  literal pool address, or a call to the wrong runtime helper, only shows when the module check fails. Division and
  modulo call `_s32_div_f` for a signed operand and `_u32_div_f` (swan's `__aeabi_uidivmod`) for an unsigned one; a
  `u8` or `u16` promotes to a signed `int`, so `(u8)id % 5u` is the unsigned one, and so is a `u16` divided by a
  `u32`. Compare the built overlay in `build/<version>/build`
  with the original to find it.

## Data and sections

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
- `static const` data goes in `.rodata`, so a table that the original has in `.data` is not `const`. The module
  check fails if a table ends up in the wrong section, even when every function matches.
- A `static const` variable whose address is never taken is folded into the code and not emitted. If the original has
  it anyway, it is not `static`: a global that no code refers to gets a section of its own, laid out by size with the
  rest. An object laid out ahead of smaller ones is in a file of its own, linked first, as overlay 65's command table
  is in `scrcmd_pokemon_center_table.c`, and one laid out after larger ones is in a file linked after, as overlay 50's
  is in `scrcmd_bsubway_table.c`.
- `GFL_ASSERT` keeps its expression as a string in `.data`, so the variable it tests keeps its original name, as the
  Medal Rally's `p_sv` does.
- Overlay IDs are linker symbols, written `OVERLAY_ID(279)` from `gfl/overlay.h`, which gives the literal pool entry
  a relocation. Mark the literal in the config with `tools/scripts/config_fixes.py overlay-id`.

## When nothing moves it

- When the order of instructions differs and no source change moves it, try `tools/scripts/permuter_setup.py`, which
  prepares a function for [decomp-permuter](https://github.com/simonlindholm/decomp-permuter). Its result can point to
  a plain change: `GFL_BGSysAllocChar`'s registers only matched with its tile size, a `u8` from a call, in an `int`.
