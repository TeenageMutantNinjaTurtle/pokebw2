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
- The registers follow the declarations, but the order the constants are set follows the statements: when the
  declaration order that gives the right registers sets them in the wrong order, or derives one constant from the
  other (`movs r6, #0` ... `subs r4, r6, #1` for `-1`), declare the locals without initializers and assign them in the
  original's order. The phrase select's `PMSSelect_SeqSelect` needs `BOOL end; int touch;` then `touch = -1;
  end = FALSE;`.
- Of two variables that compete for the same register, the one used more gets it: one use of the Battle Subway
  command's result variable too many gave its register to the command ID. A single `*var = cond ? a : b;` counts as
  one use where an `if`/`else` with a store in each counts as two. Measured on small functions, the count is of
  instructions that refer to the variable once the code is cleaned up: its assignment, a parameter's move out of
  its argument register, and the shifts that narrow a `u8` or `u16` assigned from a wider value all count, while a
  use the optimizer deletes does not. A use inside an `if` or a switch case counts like any other. A variable a
  switch tests counts about 2 for each comparison and 4 for a jump table. On a tie the variable assigned first wins,
  whatever the declaration order, and a variable assigned later needs about one use more. That held in small
  functions; in `status_rcv.c`'s `StatusRcv_CanUseItem`, six effort values with the same uses, assigned one after
  another, went to `r5` and `r7` by declaration order instead: the last declared got `r5` and the one before it `r7`,
  and the rest took stack slots, the first declared highest.
- A variable gets a register or stack slot for each group of assignments that reach the same uses, so a variable
  that is assigned in two branches and stored once after them stays in one register, while a copy of the store in
  each branch lets the two assignments go to different places.
- Where a flag is first set changes which register its zero is built in. When the original builds a flag's `FALSE` in
  the register of a call's argument, or copies it from another zero, the flag was set after the call or loop, as
  `value = joinAveTextHandler(...); found = FALSE;` and a loop's total followed by `any = FALSE;` in the Join Avenue's
  records command.
- `arr[count++] = x` and `arr[count] = x; count++;` allocate registers differently, as do `count = 1; arr[0] = x;` and
  the reverse order.
- `a[i + c]` adds `c` to `i` first, while `(a + i)[c]` folds `c * 4` into the base offset. When the original folds a
  constant index offset outside a loop, the array it indexes probably starts at `a + c` in the source.
- An array index that is a sum, `a[i * 2 + x]`, is split into `(a + x) + i * 2`. When the original adds first and
  then indexes with the sum, the sum was put in a variable, as `seat` in `wbt_system.c`'s bracket code. Written as
  `seat = i * 2 + (won ? 0 : 1);`, the sum goes to the register of `i * 2`; with the `0` or `1` set by an `if` into a
  variable, it goes to that variable's register.
- A field read where nothing between its uses can change it, as in a stretch without calls or stores, is loaded once
  into a value MWCC allocates after the declared locals. A local copy is allocated with the locals instead and moves
  every spill slot: the PC box's `Box2Main_RangePutCheck` reads `syswk->pos` directly in its party branch.
- A spilled copy of a narrow value takes its slot by its type: `Box2Main_VFuncItemArrangeGetTouch` keeps a `u16` drop
  position in a `u16` local, which a `u32` local moved to the lowest slot.
- The operands of `*` are loaded in source order, so a multiply whose registers are swapped has its operands swapped
  in the source.
- The terms of a three-term `|` chain are not loaded in source order: `a | b | c` loads `c`, then `a`, then `b`.
  `btl_server_cmd.c`'s command encoder loads `args[2]`, `args[1]`, `args[0]` for each packed argument, which
  `((args[1] & 0x1f) << 5) | ((args[0] & 0x1f) << 10) | (args[2] & 0x1f)` gives, while its four- and five-term chains
  match in field order. Try swapping the first two terms when the loads of a packing come out swapped.
- A product assigned to a variable of its own goes to a new register, with its operand copied there first
  (`mov r2, r1; mul r2, r0`), while a product used in place multiplies into the operand's register. The Join Avenue
  shop's arrow is placed with `row = ...; y = row * rowHeight; pos.y = y + 22;`.
- Two stores of the same constant share a register when chained, and not when written as two initializers.
  `second = first = TRUE;` stores `first` first. `nearXZ = FALSE; nearY = FALSE;` in that order loads the zero twice,
  while the other order shares it.
- A pointer local to an element of a struct, like `dst = &shot->pokes[i]`, takes a callee-saved register of its own
  and can push the struct's pointer to the stack along with a constant MWCC keeps for it. The musical's photo
  (`musical_event.c`'s `func_ov012_02151384`) only matches with `shot->pokes[pos].field` written at each use.
  The base register tells the two apart: `&call->rows[i]` is `call + 0x40 + i * 0x1c`, used with the field's own
  offset (`[r5, #0x14]`), while `call->rows[i].window` written out is `call + i * 0x1c` with the array's offset
  folded in (`[r5, #0x54]`), as in `ctvt_call.c`'s `CtvtCall_Leave` and `CtvtCall_Main`.
- An element address computed before an inline helper's argument calls, and kept in a register while the loop counter
  spills, is the address passed to the helper: `CtvtCall_CreateActor(sys, &call->rows[i].frame, ...)` stores through
  a `ClActor **`, where `call->rows[i].frame = CtvtCall_CreateActor(...)` computes the address after the call.
- Two loops that reuse one counter and both spill it share its stack slots in the order MWCC splits the variable,
  not in declaration order; giving the second loop a counter of its own, as `pos` in the same function, moves it.
- Variables declared in an inner block are allocated apart from the function's variables of the same name: in
  `ShinkaDemoPieces_Move`, the branch that moves a piece home declares its own `dx` and `dz`, which live on the stack
  while the other branches keep theirs in registers.
- Two values that the original keeps in one register, one dead before the other is set, were one variable: the PC
  box's `func_ov255_021cdcc8` keeps the party position and then its result in the same variable, where two
  variables get two registers.
- A loop condition written with a local for its row start, `start = pos + j * 6; if (x >= start && x < w + start)`,
  allocates registers differently from the same sums written in both comparisons: the PC box's `func_ov255_021d229c`
  only matched with the sums written out.
- A parameter that the callers narrow with shifts before the call is a `u16` or `u8`, and the type also decides how it
  is spilled: `BagItemList_GetItem` spills `pocket` first and compares the reloaded copy only once `pocket` and `index`
  are `u16`, as `itemmenu.c`'s caller narrows them; as `u32` it compares a register copy and stores it after.
- Loops over an array of structs that test two fields through a pointer to the element, then write the fields as
  `list->entries[i].x` in the body, keep the array's base in a register and the element's address in another, as
  `bag_item.c`'s `BagItemList_Remove` and `BagItemList_GetItem` do; indexing in the test too folds the field offsets.

## Stack slots

Same code, other `sp` offsets or frame size.

- A pointer to an array element written to a local, `font = &app->fontOam[i]; font->bitmap = ...; font->oam = ...`,
  keeps the array's address in a register and spills the element's offset, where `app->fontOam[i].bitmap` folds the
  offsets into each access: the PC box's `func_ov255_021d1c30` matched only with the pointer.
- Declaration order does move spill slots in longer functions: `func_ov255_021d0374` matched with its loop counters
  declared first and `y` before the row width.
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
- The same holds for a variable assigned anew in several `if` blocks: its first piece takes the variable's slot in
  declaration order and the later pieces the lowest slots, in the order they are assigned. `status_rcv.c`'s
  `StatusRcv_UseItem` reuses one function-level `add` in its six effort blocks, which puts the first block's value
  among the declared slots and the other five at the bottom of the frame; a block-scoped `add` in each block does not.
- In a chained assignment, `a = b = f();`, MWCC treats `a` as its own copy of `b`, and a spilled `a` takes the lowest
  slot instead of its declared one. `StatusRcv_UseItem` needs `status = f(); newStatus = status;`.
- Named locals take stack slots apart from the compiler's temporaries. When the original's spilled values all sit in
  the order they are first assigned, they may be common subexpressions: the trade's `func_ov194_021c1530` reads
  `colors[side * 2]` at each use, and `int color = colors[side * 2];` moved it above the temporaries.
- One counter for two loops in a row keeps one slot. `func_ov194_021c12ec` has a loop over `i`, then two nested loops.
  MWCC keeps the `0` that the first loop passes as arguments in the stack slot of the variable it starts the outer
  nested loop with, and in the original that slot is the lowest: both loops count with `i`, the inner one with `j`.
  A separate `side` for the outer loop took the highest slot instead.
- A NULL check written on a field, `if (bgs[bg].screen != NULL) { void *screen = bgs[bg].screen; ... }`, gives
  different stack slots from the same check on a local loaded before it, as `GFL_BGSysLoadScrCore` shows.
- MWCC reuses a field it has loaded, across the 64-bit multiply helpers, so a value that the original keeps on the
  stack between `piece->home.x - piece->pos.x` and `piece->pos.x = piece->home.x` is MWCC's own copy, not a local.
  Writing it as a local changes which stack slots everything gets.
- A test of a field right after a store into it reuses the stored register only when the source tests the field
  written to: `tr_tool.c`'s `TrainerUtil_LoadTrainer` tests `trainer->trainerClass` after storing `data->trainerClass`
  there, not `data->trainerClass`.
- The types of locals and of the values they hold change how spilled values are scheduled. The trainer AI's speed
  comparison only matches with the speed function returning `u16` into `u16` locals: a spilled `u16` is reloaded after
  the call's stack argument is stored, while a spilled `u32` is reloaded before it.
- A `u64` argument whose high word is 0 keeps that zero in a stack slot of its own, where a `u32` zero is folded into
  a constant. Two such slots in `mystery_gift_pokemon.c` show that `PokeParty_CreatePkm` takes its trainer ID and PID
  as `u64`s.
- A `u64` parameter after three `u32`s is split between `r3` and the first stack word, with no alignment to a register
  pair. Arguments passed in pairs such as `(x, 0)` or `(0, -1)`, a constant -1 stored last, and a callee that saves
  `r3` and its first stack argument to adjacent slots are the signs, as `tr_tool.c`'s `TrainerUtil_LoadParty` shows
  for `PokeParty_CreatePkm`.
- Structs passed by value go in registers and on the stack. Code that copies a struct to the stack and passes its
  address takes a pointer to a local copy. A struct local keeps its stack slot even when it only passes through, so a
  frame larger than the locals explain holds one: Guard Spec.'s effect in `btl_server_flow_sub.c` stores
  `SetConditionTurns`'s `BattleCondition` in a local before passing it on, and `BattleHandler_AddSideEffect` keeps its
  copy's address in a register to pass the copy by value after passing its address.

- A function that declares every local first and assigns them below gets other registers and stack slots than one
  that initializes them in their declarations (palanm.c's `MaskPalettes` sets `mask = 0` after the count for its
  register order): bmp_menulist.c's `Bitmap_Scroll16` declares `pixels, widthTiles,
  fill32, end, y, i, j, src, dst` and assigns `pixels`, `fill32`, `widthTiles` and `end` in call order, and swapping
  the declarations of `widthTiles` and `fill32` swaps their slots.
- A stack parameter loaded at entry although it is an `int` was reassigned rather than copied: wipe.c's
  `GFL_WipeSet` does `sync /= GFL_FadeGetUpdateFreq()`, where a new local leaves the load at the division. A pointer
  local such as `sys = &sWipe` assigned after that statement, not in its declaration, keeps its register free until
  then.
- A `u16` local and `local + 1` stored back to the same field can share a register and push a parameter out of r0;
  a wider local keeps them apart, as `u32 listTop` does in `BmpMenuList_Scroll`.

- A value that reloads its source for each use, where ours loads it once into a register (or the reverse), was
  written as an expression that re-reads the source in each part, as a macro writes it: palanm.c's `BlendFadeColors`
  matches with `BLEND_CHANNEL(src[i] & 0x1f, ...)` for each channel, not with channel locals.
- A field addressed from the struct's base plus its full offset, where ours goes through a pointer to the member, was
  reached through the member path: `paletteBuffer->fade.delayCounter` in `PaletteFade_StepBuffer`, not a
  `FadeControl *` local.

- A field loaded earlier than its first use in the source was read into a local initialized in its declaration, in
  declaration order (`s16 brightness = data->brightness;` before `target` in `BrightnessData_Step`).
- A constant store written first reserves its register before the parameters are moved, though the scheduler moves
  the store itself later: `data->active = TRUE;` first in `BrightnessData_Init` keeps the shared 1 in r0.

- Block-scoped arrays set both the stack order and where their initializers are copied: infowin.c's
  `InfoWin_VBlankTask` matches only with each table declared in the `if` block that uses it.
- A local pointer to a struct member, `PrintWindow *window = &work->priceWindow;`, is kept as the member's offset in a
  callee-saved register, added to the struct's base at each use, and where the pointer is assigned decides when that
  register is loaded. When the original loads a member's offset into `r6` or `r7` early and indexes from it, the
  source had such a pointer: the bag's `ItemMenuDisp_DrawQuantity`, `ItemMenuDisp_ShowMessage` and
  `ItemMenuDisp_DrawTMInfo` only match with one, and it also stopped MWCC from holding a zero for the stack arguments.

## Instruction order

Same instructions, scheduled in another order.

- `x + (p << 12)` and `x + p * 0x1000` put the operands of `adds` in opposite orders: the phrase select's
  `PMSSelect_BGDrawPlate` sets a screen entry's palette with `(entries[i] & 0xfff) + (palette + 2) * 0x1000`, which
  gives `adds r5, r5, r2`, where `<< 12` gave `adds r5, r2, r5`.
- Loads through a pointer are not moved above stores unless the pointee is `const`. A load that the original
  schedules early, such as an argument loaded before the stack arguments are stored, points to a `const` parameter.
- The same rule moves a call's stack argument stores. When loads through a pointer that is not `const` follow the
  call, the stack arguments are stored before the register arguments are set up. If the original stores them last,
  the pointer is `const`.
- A struct assignment loads every field before it stores any, through a pointer that is not `const` too. Two
  fields copied with both loads first, `ldr r2, [r0, #0x10]; ldr r1, [r0, #0x14]; str r2, [r0]`, are one struct
  copied: `KeySystemTween_Update` ends with `tween->pos = tween->end;` for an `{ s32 x, y; }` position.
- A load through a `const` pointer is also reused across stores, as the World Tournament's `wbt_setup.c` reads an
  entrant's bit fields from one load, but it is not hoisted out of a loop: `wbt_party.c`'s filter check reads each
  list's count again in every iteration because its filter is `const`, where a plain pointer's count is loaded once
  before the loop.
- A field load scheduled ahead of a store it doesn't depend on, where MWCC keeps the written order, can come from an
  inline helper's argument: arguments are evaluated before the body's stores. The PC box's sequences set the picked
  position with `u8 pos = func_0202ba60(...); Box2Seq_SetGetPos(syswk, pos, syswk->tray);`, which loads `tray` before
  storing `pos`; the same stores written out load it after.
- Initializations are scheduled where they are written: `int i = 0;` declared after a call sets `i` after the call,
  while `for (i = 0; ...)` sets it at the loop, after any statements before the loop.
- A counter's zero stored to its stack slot ahead of a call, in another register than the call's arguments, can be
  written after that call: overlay 185's `CountupGreetings` stores `n`'s zero before calling
  `PMSWord_GetWordNumByGmmId` only with `n = 0;` after `first` and `last` are computed. Written before the call, it is
  stored after the call's result and built in `r0`; the next function, `CountupPokemon`, sets it right after its call.
- A field of a local struct that a call fills is loaded before the next call only when the source reads it there: the
  Pokédex forms page copies `targetX = target.x;` between `ZukanDetailForm_GetSpritePosF32(..., &target)` and
  `MCSS_GetPosition`.
- A call nested in another call's arguments is made after the other arguments' addresses are computed. When the
  original makes the inner call first, its result was put in a local: the summary screen's ribbon list writes
  `y = PStaRibbon_GetRowY(ribbon, i); PStaOam_SetPosition(ribbon->rows[i].oam, ROW_X, y);`.
- A conditional expression among a call's arguments is evaluated before the plain ones. When the original loads the
  arguments in their order, the conditional one was a local set before the call: the forms page passes `addToDex`
  locals `sex` and `rare` set just before it.
- An argument that is loaded before a call among the arguments, such as a print queue loaded before
  `BmpWin_GetBitmap(...)` in the same call, was passed to an inlined helper that makes the call, like
  `PrintWindow_Print`. A block-scoped local set from the field before the call does the same: bmp_menu.c's
  `BmpMenu_PrintOptions` loads the queue first because its loop body declares `PrintQueue *queue` and a `u8 y`.
- Two stores through a pointer read from a struct, with one load of the pointer where ours loads it again after the
  first store, were made by an inlined helper that takes the pointer, such as `PrintWindow_Init(header.printWindow,
  window)` in `ShopUI_CreateConfirmDialog`.
  `PrintWindow_Print`.
- A computed argument whose arithmetic comes before the loads of the arguments before it was assigned to a variable
  first: the PC box's `Box2Main_VFuncPartyInPokeMove` adds 30 to the party's count before loading the cursor
  position only with `putPos = count + 30; PokeIconMoveDataMake(syswk, syswk->pos, putPos);`.
- A parameter passed on the stack is loaded at the function's entry, along with the register parameters, unless it is
  an `int` or `s32`, which is loaded where it is first used. `StartMenu_DrawFrame` takes its BG as a `u8`, as
  `GFL_BGSysFillScrArea` does.
- A `u16` stack parameter reloaded with `ldrh` at some uses, with one `ldrh` into a register that feeds others, has
  few uses of its own: the shared load is its conversion to a wider type, so the callees there take a `u32`. In
  bmp_menu.c's `BmpMenu_AddEx`, `BmpCursor_Create` and `BmpCursor_LoadBitmap` narrow their heap ID with shifts, so they take
  `u32 heapId`. When reloads look like register allocation, read the callees' asm before reordering statements.
- NitroSDK's inline functions take enums, such as `GXBGColorMode`, and the BG system's `GFL_BGSysCreateBG` only loads
  every argument of `G2_SetBG0Control` before shifting any with enum parameters. `nitro/gx.h` keeps the SDK's types for
  this reason.
- Where `FX_Mul`'s sign extensions go depends on the statements. In `ShinkaDemoPieces_Init`, squaring `dy` before
  either square root, `distY = FX_Mul(dy, dy);`, keeps `dy`'s extension in a stack slot across the first one, and only
  the sum written as a `static inline` function, `distXZ = SquaredLengthXZ(dx, dz);`, puts that extension before the
  sum's multiplies. The same sum written in place, in any statement order, cast or split, does not.

## An instruction too many or too few

Narrowing shifts, reloads, recomputed addresses and folded constants.

- `field += value` on an `s16` field with an `int` value narrows the value first and shares the narrowed copy between
  such adds, where `field = field + value` adds the `int` as it is. The phrase input's `PMSIVEdit_ScrollWait` adds its
  step to two scroll fields the second way.
- An argument narrowed by a `u16` parameter is narrowed again at each call, and only hoisted out of a loop, while a
  `(u16)` cast is computed once and reused: `PMSIVEdit_ScrollWait` matched only once `func_0204c1a8` and
  `func_0204c1dc` took their surface as `u16`.
- After `a = b;`, a test of `b` reuses the register just stored and a test of `a` loads `a` again. The phrase
  select's `PMSSelect_SetupList` writes `wk->lineCount = wk->sentenceCount; if (wk->sentenceCount < 20)`, and its
  `PMSSelect_SetupScreen` tests `wk->pos` after `wk->prevPos = wk->pos;`.
- `field--` and `field++` load the field again before the subtraction, even right after comparing it, where
  `field = field - 1` reuses the register: the phrase input's `PMSInput_SentenceKey` moves its edit position the
  second way.
- A compound assignment to a narrow field narrows its right side first: `work->checkFlag &= 0xff ^ (1 << waza);` on a
  `u8` shifts the mask down to a byte before the `and`, while `work->checkFlag = work->checkFlag & (0xff ^ (1 << waza));`
  ands the full mask, as the PC box's `Box2Main_PokeFreeWazaCheck` does.
- `res -= 34;` lets MWCC fold a later `res + 36` into `res + 2`; a variable of its own, `u32 slot = res - 34;`, keeps the
  difference in its register and adds 36 to it, as the PC box's `func_ov255_021c445c` does.
- A chained assignment to fields, `a->x = a->y = value;`, stores `y`, reloads it and stores `x`. When the original
  narrows the value once and stores it to both, the stores were separate statements, as in the PC box's
  `PokeIconChgDataMake`.
  The same holds with a local on the left: a call's result stored to a field and read back from it before a test,
  `str r0, [r7, r1]` then `ldr r0, [r7, r0]`, is `icon = wk->markIcons.icons[i] = f(...);`, as the trade summary's
  marking icons are made in `func_ov194_021c4ec0`.
- A caller narrows an argument for a `u8` or `u16` parameter with shifts before the call, so an argument passed without
  them is for a wider parameter. Read the narrowings of every caller together: `GFL_BitmapFillArea` takes `s16 x, s16
  y, u16 width, u16 height`, and `GFL_BitmapGetWidth` returns a `u16`, which is why printsys.c passes its width
  without shifts and bmp_menulist.c's `PrintOptions` narrows its computed width and height.
- MWCC trusts the type of a call's result: a `u8` returned by one function and passed on to a `u8` parameter isn't
  narrowed again. When the original narrows such a value before the call, it was held in an `int` or `u32` local, as
  `research_graph.c`'s `SetFirstAnswer` and `ChangeAnswer` keep a question's ID in an `int`.
- A `u8` function that narrows its result at the return (`lsl #24; lsr #24` after setting a 0/1 flag) keeps the flag
  in a `BOOL` local, as palanm.c's `IsBitSet` does.
- A signed compare (`bge`) of a parameter that callers pass as a `u8` without narrowing means the parameter is an
  `int`: palanm.c's `MaskPalettes(int buffer, ...)`.
- A signed compare (`bge`) of a `u32` function result means it was stored in an `int` local: `tr_tool.c`'s
  `TrainerMsg_Load` keeps `GFL_ArcSysGetDataLength`'s result in an `int` and compares it with an `int` trainer ID.
- A `u16` narrowing followed by an `s16` one (`lsl #16; lsr #16; lsl #16; asr #16`) is a value returned by a `u16`
  inline helper and passed to an `s16` parameter, as bmp_menulist.c's `RowY` is in `BmpMenuList_EraseCursor`.
- A 4-bit color field masked with `& 0x1f` before it is shifted into a print color (`lsl #27; lsr #17` for the text
  color) went through `PRINT_COLOR`, which masks each component.
  them is for a wider parameter. The other way round, a parameter passed on to a `u8` parameter without shifts is a
  `u8` itself: `GetBattleMon` hands its ID straight to `GetPokeParam`, so both take a `u8`, and so do the ability
  helpers that pass their mon's ID to `GetBattleMon`.
- A wider parameter stored into a narrow bit field is narrowed to the field's type and then shifted into place, while
  a `u8` parameter is trusted and shifted at once. The PC box's `func_ov255_021cc460` takes its button's actor and
  palette as `u32` and narrows them in the stores to its 7- and 4-bit fields.
- A sum that the original truncates to `s16` before comparing it was stored in an `s16` local, as the edges of the
  Join Avenue's balloons are; casting it in the comparison gives the same code but is not needed.
- A value narrowed again after it is clamped was clamped with a conditional expression, whose `int` result is
  narrowed when it is stored back: the Pokédex cry page writes `sample = MATH_CLAMP(sample, -500, 500);` for an `s16`
  sample, where an `if`/`else if` chain assigning the bounds leaves no narrowing.
- A comparison right after a `u16` narrowing that isn't done in `u16` arithmetic (`subs r0, r1, #6; cmp #1; bhi`
  rather than `subs; adds; lsl/lsr #16; cmp`) compares the narrowed value as an `int`: `zone_weather.c`'s
  `UpdateWeatherToDefault` keeps `int nowWeather = (u16)GetNowWeather(gameData);` for its `== 6 || == 7` test.
- A callee that narrows its result in its body (`lsl #24; lsr #24`) can still return `u32`, with the value in a `u8`
  local: the caller narrowing the result again shows it, as `event_mapchange.c` does for `season.c`'s
  `Season_GetRealTime`.
- MWCC keeps the grouping written in an address offset: `raw + (i * 0x180 + 0xc00)` and `raw + i * 0x180 + 0xc00`
  compile differently, and a bracketed `((personality & 0xf) - 8)` is kept as its own term where the bare `- 8` is
  folded into the constant beside it (`pokegra.c`'s `PokeGra_CellCharsToImage` and `PokeGra_DrawSpindaSpots`).
- An `if` whose condition is an assignment with `|=`, `if (texBanks |= GX_VRAM_C)`, keeps the `orr` and tests its
  result, which `|` would fold away: `screentex.c`'s bank switch, where the test is always true.
- Masks written with `~` clear bits with `bic`. The game's `and` with a constant such as `0xef` is `x &= (u8)~FLAG`.
- MWCC doesn't propagate constants into a variable of an enum type. A loop that still checks its bound before the
  first pass, as `for (p = 80; p <= 83; p++)` does in the Join Avenue's commands, or a sum that still adds a counter
  known to be 0, as the Battle Subway's loop over its music switches does, has an enum counter.
- A function that returns `-1` or `0` from two branches, `if (f(x)) { return 0; } return -1;`, is folded into a
  computed result (`rsbs`) when it returns an `int`, and keeps both returns when it returns an enum. The field action
  checks of `itemuse_event.c` return such an enum.
- A local variable that holds a constant, like `fx32 one = FX32_ONE;`, keeps its own stack slot or register, while the
  literal is hoisted out of a loop by the compiler. Extra hoisted constants in our output point to such a variable.
- An address computed before calls is reused after them only when the expression is the same, types included:
  `a[j].f` read before the calls lets a later `a[j].g` reuse the address, but not `a[(u32)j].g`. An address that the
  original computes again, where ours keeps it on the stack, is written differently at one of the two places. An
  inline accessor does it naturally, since its parameter is a copy of the index in the parameter's type: the Join
  Avenue shop reads `ResortShop_GetEntry(wk, j)->id` with a `u32` index for an `int` `j`, and its later
  `wk->entries[j]` is computed again while `wk->entries[i]` is reused.
- Stores to fixed addresses fold into one literal each, `((u16 *)(HW_DB_BG_PLTT + 0x1c0))[9]` included. A literal kept as
  a base with offsets, `ldr r1, =0x50005c0; strh r0, [r1, #0x12]`, is a pointer local: the summary screen's
  `PStatus_InitText` sets two font colors through `GXRgb *pltt = (GXRgb *)(HW_DB_BG_PLTT + 0x1c0);`.
- A loop that computes an element's offset (`i * size`) once into a register of its own, using it both for stores
  through the array and for `&arr[i]` passed to a call, took the element's address into a pointer at the top of the
  body and used the pointer only for the call: the phrase input's `PMSIVMenu_SetupEditButtons` keeps
  `wk->items[i].str = ...` for its stores and passes `item`. Indexing at both places multiplies twice, and storing
  through the pointer moves the stores onto it.
- Stores through a pointer to an array element, `icon = &icons[3]; icon->chars = ...;`, use the element's address as
  their base register, while `icons[3].chars = ...;` reaches the field from a base of MWCC's choosing, often an
  earlier element. The Pokédex touch bar's map and forms buttons are filled through a pointer. The other way round,
  a loop that indexes `wk->buttons[i].rect[0]` keeps `wk + i * size` and adds each field's offset, where a
  `LanguageButton *button` local gives other registers, as the Pokédex info page's language buttons show.
- A local array or struct initialized in its declaration is stored through a base register, `add r0, sp, #0x4c;
  str r4, [r0]; str r4, [r0, #4]`, where assignments to its elements store at `sp` offsets. A `u8` array initialized
  so, `u8 kinds[3] = { FALSE, FALSE, FALSE };`, also makes MWCC load memory again after each store to the array, where
  with assignments it keeps the first load: the Pokédex habitat map reads `wk->habitat` again for each of its three
  tests of a place's habitats.
- The initializer's stores happen at the declaration, so an array cleared by an initializer after some calls is
  declared in an inner block opened there: the forms page's `BOOL hasSex[3] = { FALSE, FALSE, FALSE };` follows the
  Pokédex reads in a block around the rest of the gathering, and `BOOL seenRare[2] = { FALSE, FALSE };` sits in the
  loop over the forms.
- A value that a loop uses and the code after it uses again is reused from the copy hoisted out of the loop. When
  the original computes it again after the loop, the loop assigns it to a variable declared in the loop's body, as
  `int wanted = mode + 1;` in the Join Avenue's records command.
- An address passed to a `const` pointer parameter is converted, and the conversion is not shared with the same
  address written elsewhere. When the original computes an address a second time for another call, the first call
  takes a `const` pointer, as `GymElecFade_IsActive` does.
- Reads of a `const` table at a constant index are folded into immediates, but reads in a loop over the table are not,
  even when the loop runs once and is unrolled. An `ldm` from a table straight into argument registers is two fields
  read in such a loop, as the egg and evolution demos' particles load the resource of each of their one unit. Reads
  through a pointer to the entry, `const BitmapEntry *entry = &sListBitmaps[BMP_YES];`, aren't folded either, as
  `research_list.c`'s `ResearchList_DrawYesButton` and `DrawNoButton` load their bitmap's file, colors and text from
  the table; written as `sListBitmaps[BMP_YES].arcId`, the same function is 0x38 bytes shorter.
- A struct assignment, `u->pos = *pos`, copies with `ldm`/`stm`. Separate `ldr`/`str` pairs for each field are the
  NitroSDK's `VEC_Set(&u->pos, pos->x, pos->y, pos->z)`, as `iss_3ds_sys.c`'s `ISS3DSoundSys_SetListenerCore` writes it.
- Two locals initialized to 0 in their declarations share one zero register, so a later `offset += 4` compiles as
  `adds r5, r4, #4` from the counter's zero: `iss_switch_set.c`'s `ISSSwitchSet_LoadArcDataCore` declares `int i = 0;
  u32 offset = 0;`, where `offset = 4` shares the `movs #4` of another argument instead.
- A value moved into an argument register just before a call, and used for nothing else, is an argument the prototype
  is missing. `GFL_SEPlayKeepVol` takes the sound's player as well as the sound. The value can be narrowed for it:
  `CtvtComm_RecvPacket` narrows `packet->value` into r1 (`lsls`/`lsrs #24`) but compares the unnarrowed value with
  0xff, because `func_ov257_021aad74(sys, u8 talker)` takes it; with `u32 talker = packet->value` and the talker
  passed, it matches, where a `u8` local or no argument cannot. A missing parameter can also swap the registers of
  the caller's loop variables, as it did in `CtvtComm_UpdateTalk` (`CtvtComm_IsMemberTalking` takes the net ID).
- A value built once and passed both in `r3` and in the first stack slot (`mvn r3, r3; mov r0, r3; str r0, [sp]`)
  is a `u64` argument, its low word in `r3` and its high word on the stack. Two `u32` arguments get a constant each:
  the summary screen's debug box matches only with `PML_CreateTempPkm(pkm, species, level, PKM_ID_RANDOM)` taking a
  `u64` ID.
- A caller that keeps an argument register untouched across a call to a function that ignores it is passing that
  argument: `ShinkaDemoPieces_IsFadeDone` takes the heap ID like the functions around it.

- A ternary argument `f(c ? 1 : 0)` compiles to the select form (`movs r0, #1; cmp; beq; movs r0, #0`). A branchy
  original (`bne`; `movs #1`; `b`; `movs #0`) is an `if`/`else` with a call in each branch, as `CtvtTalk_UpdateMain`
  calls `func_0203d564(TRUE)` or `func_0203d564(FALSE)`.
- A ternary store `*p = c ? a : b` computes the address once and stores after the branches; an `if`/`else` with a
  store in each branch computes the address in each, as `Bitmap_Scroll16` does.
- Parenthesized offsets change the code: `pixels + (dst + 4)` adds the offsets and indexes once, `pixels + dst + 4`
  adds to the pointer twice (`Bitmap_Scroll256`).
- The operand order of a product decides which value is loaded first: `(row + 1) * rowHeight * 2` and
  `widthTiles * (y & ~7)` match in bmp_menulist.c where the other orders do not.
- `u8` flag parameters, not `BOOL`, change the order in which register parameters are spilled at entry
  (`BmpMenuList_CycleCursor`).
- A bit-table lookup with an unsigned `lsr #5` for the index and a signed modulo for the bit is
  `table[item / (sizeof(u32) * 8)] & (1 << (item % 32))`; `item >> 5` gives `asr` (pml_item.c).
- A result computed into the parameter's own callee-saved register comes from a compound assignment to the parameter
  (`item -= ITEM_TM93 - TM_INDEX_TM93;` in `PML_ItemGetTMWazaID`); `item = item - X` or a new local computes into r0.

- A parameter masked in place (`word &= 0x7ff`) with no narrowing after is wider than the callers' `u16`: pms_word.c's
  `PMSWord_GetMessage` takes a `u32`.
- A store of a loaded value back into an address-taken out-variable's slot is a reassignment in the source:
  `fileId = sCategoryMsgFiles[fileId];` after the call that filled it (`loadSayingToString`).
- `for (j = 0, base = 0; ...)` zeroes `j` first; `base = 0;` before `for (j = 0; ...)` zeroes `base` first
  (`PMSWord_FromMessage`).

- `x |= c` reloads the field and its pointer, while `x = x | c` reuses the value just tested: infowin.c's
  `InfoWin_Update` sets a flag with `flags = flags | 4`.
- Clearing a bit of a `u16` field with a pool literal of 0x0000efff is `& (0xffff ^ bit)`; `& ~bit` gives 0xffffefff,
  which only shows in the pool bytes (`InfoWin_Update`).
- An index masked with `lsl #24; lsr #22` at its use is a `BOOL` passed through a `u8` parameter of an inline
  (`InfoWin_GetSignalColors(u8 on)`).
- A constant choice passed to a `u16` parameter without narrowing is `u16 v; if (...) v = A; else v = B;`; a ternary
  keeps the `lsl`/`lsr` (actor_tool.c's `ActorTool_LoadPalettesFade`).
- A loop that copies its index each pass (`adds r3, r2, #0`) has a `u32` index against an `int` bound
  (`ActorPalSlots_Free`).
- A switch whose result moves to r0 once at the end assigns a result variable initialized to the input
  (`u8 next = pos; switch ...` in cursor_move.c's `CursorMoveData_GetLink`).

- An `int` assigned to a `u8` bitfield is narrowed (`lsl`/`lsr #0x18`) before the bit insert; a `u8` value isn't
  (game_comm.c, a `BOOL flag` stored in a 1-bit field).
- Loads still move above stores to other known offsets of the same pointer: in `GameCommSys_Main`,
  `comm->work = NULL; comm->commNo = 0; cb = comm->exitCallback;` reads the callback first, and only that source order
  gives the original's registers.
- A struct is copied by its type's alignment: one of `u8` fields bytewise, a union with a `u16` by `ldrh`/`strh`
  while its fields stay byte-accessed (game_beacon.c's `GameBeaconTime`).
- One load of a global serving a store and a following address comes from taking the address into a local before the
  store (`GameBeacon *beacon = &GameBeaconSys->mine.beacon;` in `GameBeaconSys_SetGameData`).
- `x == n` compiled as `sub; bne` is `x - n == 0`; `return (*p)++` and an increment followed by `return *p - 1`
  differ (`GameBeaconSys_GetRecentEntry`, `GameBeaconSys_GetNextNew`).
- A `u16` parameter is spilled at entry before the other parameters are moved, a `u32` one after them. A caller's
  `u16` narrowing can come from its own `u16` local rather than the parameter type (`GameCommSys_LogPlayers`).

- A store written before a read through a `const` pointer parameter can move above another store; dropping the
  `const` keeps the source order (app_taskmenu.c's `AppTaskMenu_Create`).
- A range test `subs; subs; cmp; bhi` is an unsigned difference in the source, `x - left <= right - left` on `u32`
  values; MWCC doesn't fold `x >= left && x <= right` into it (`AppTaskMenuWin_IsTouched`).

## Branches and block layout

- Blocks are laid out in source order. A switch whose default code comes right after its comparisons or jump table
  had `default:` written first, and `if (f()) { n++; } else { return FALSE; }` puts the return after the code that goes
  on, where `if (!f()) { return FALSE; } n++;` puts it before.
- Every `return` gets its own epilogue. Failures that all branch to one block that sets a saved register and jumps
  to a shared `mov r0, rN` exit come from a result variable and a single `return`, as `mystery_gift_pokemon.c`'s
  original has.
- Identical statements in different branches are merged, so a branch that jumps into the middle of another block had
  the same code in the source. For example, `if (a) { x = 3; y = 19; } else { x = 0; y = 19; }` compiles differently
  from `x = a ? 3 : 0; y = 19;`. A run of jumps to one store, as in the start menu's `StartMenu_MoveCursor`, is the
  same store written in several `else` branches.
  A test that branches past an unconditional jump, `bne next; b hide`, where `||` would give one `beq hide`, is the
  first copy of a body written twice in an `if`/`else if` chain and replaced by a jump to the second:
  `func_ov194_021c4ec0` hides a marking icon with `if (anim == -1) { hide } else if (isEgg && i == 6) { hide }`.
- A `bne` over a `b` into another branch's call, `cmp r0, #0; bne x; b call; x: cmp r7, #0; beq call; mov r6, #1;
  call:`, is the call written in both branches: overlay 185's `PMSIView_CmdWordWinToCategory` matches only with
  `if (mode == 0) { f(flag); } else { if (search) { flag = TRUE; } f(flag); }`. Writing the call once after the `if`
  also swapped the registers of `flag` and `search`.
- A range or equality test that ends in `b store` while its other arm is `mov rN, #const; b store` is the store
  written in both arms, `if (x >= 20 && x <= 23) { wk->pos = x; } else { wk->pos = 22; }`: the then-arm's store is
  cross-jumped into the shared one and only its `b` is left. The phrase input's `PMSInput_CategoryKeyInitial` writes
  its cursor's fallbacks so; a fallback assigned to the value and stored once after gives a plain branch to the store.
- Of a store written in several arms, cross-jumping keeps the copy written last and turns the others into `b`, so the
  order of the arms decides where the store sits. The phrase input's `PMSIVWordWin_SetScrollBar` keeps its top
  position's store at the end of the function, behind a plain `beq`, only as `else if (scrollMax != 0) { compute }
  else { y = TOP; }`; `else if (scrollMax == 0) { y = TOP; } else { compute }` kept it early behind `bne; b`. Its
  `PMSIVWordWin_GetScrollBarLine` has `cmp #0x12; bne next; b zero` from `line = 0` written both as the first arm of
  the inner chain and as the outer `else`.
- A branch to the very next instruction is left by cross-jumping: two statements that end the same way, such as a
  store in each case of a switch, share their tail, and the first jumps to it even when it follows.
- MWCC evaluates the operands of `|` in the order they are grouped, so a color built from three computed parts shows
  its grouping: `field_menu.c`'s cursor fade (`func_ov036_021a040c`) computes red, then blue, then green, and only
  matches as `r | ((b << 10) | (g << 5))`, not as `GX_RGB(r, g, b)`.
- A block that many cases of a switch branch to, such as the step advance of `event_entrance_effect.c`'s
  `func_ov036_0219f380` (`*state = next(work); advance(work);`), is each case's own copy merged by cross-jumping. A flag
  set in the cases and tested after the switch keeps a register for it and doesn't match.
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
- `if (!f())` and `if (f() == FALSE)` lay the two blocks out in opposite orders. `field_sound_system.c`'s
  `FieldSnd_GetLastQueuedCommand` puts the `then` block first behind `bne` only with `== FALSE`; `!` put the `else`
  block first behind `beq`.
- The operands of `==` between two fields are compared in source order: `syswk->tray == syswk->getTray` gives
  `cmp tray, getTray`, as the PC box's `func_ov255_021cc8dc` needs.
- The left operand of a comparison is loaded first, even before a store just above it: `sw->nowFrame++; if
  (sw->endFrame < sw->nowFrame)` loads `endFrame` before the increment's store, as `iss_switch.c`'s
  `ISSSwitch_AdvanceFade` does, where `sw->nowFrame > sw->endFrame` is 2 bytes off.
- A store picked by a test, `if (pos < 30) syswk->pos = pos; else syswk->pos = 0;`, branches past the second value with
  `bhs` and `b`, while clamping a local first, `if (pos >= 30) pos = 0; syswk->pos = pos;`, uses one `blo`. The PC box's
  `func_ov255_021c8b38` is the first.
- `x = x == 0 ? 3 : x - 1;` reads `x` once, and `if (x == 0) { x = 3; } else { x--; }` reads it again in the `else`
  branch before the shared store, as the Pokédex habitat map's season changes do.
- The last test of a condition branches to the code written second. `if (a == x || a == y) { return TRUE; } return
  FALSE;` ends with `bne` to the `FALSE` return, while the original's `beq` to a `TRUE` return placed after the `FALSE`
  one is `if (a != x && a != y) { return FALSE; } return TRUE;`, as `plist_demo.c`'s Reveal Glass and Gracidea checks
  are written.
- `a == 4 || a == 5` becomes a range check. Separate comparisons that jump to the same code come from separate
  branches with the same body.
- A clamp that ends in one store, with each limit copied into the value's register, is a conditional expression.
  `if`/`else if` stores each limit separately.
- An `if`/`else` that assigns one field a constant in each branch can still end in one store after the branches, with
  `b` over the else branch, as the trade's key cursor wraps its row to 2 or 4 in `pokemontrade_proc.c`. The
  conditional expression gives `mov`, a conditional branch over a second `mov`, and no `b`.
- A call whose argument is picked by branches comes from one of two sources, told apart by the layout. `f(x ? FALSE :
  TRUE)` tests `x` with `bne` to the second value, and puts the value for `x == 0` first. Two calls in an `if`/`else`,
  `if (x) f(FALSE); else f(TRUE);`, are merged into one call after the branches, with `beq` to the else branch and the
  then branch's value first. The evolution demo's touch screen flags and its view and effect creation are two calls.

- An `if`/`else if` chain whose first and last branches make the same call gets the calls merged (`bgt +2; b call`):
  wipe_sub.c's `WipeCircleWork_Compute` matches with `if (y <= cy) call; else if (y <= cy * 2) mirror; else call;`,
  where a condition joined with `&&` doesn't.
- Assigning both of two values in every branch (`start = 16; end = 0;`) lets MWCC build -16 from the register holding
  0 (`WipeBright_Init`); zero-initialized locals or a ternary don't.
- A constant argument loaded in both arms of an `if`/`else` (`movs r3, #0x3c` in each) was assigned to a local in each
  branch, even when the value is the same: `field_sound.c`'s `FieldSnd_ChangeZoneBGM` matches with `fadeOutFrames =
  60` set beside `fadeInFrames` in both branches, where `60` written once at the call is 2 bytes short.

- When the original puts an `if`'s then-block after the else path, write the condition negated with the bodies
  swapped: brightness.c's `BrightnessData_Step` matches with the long advance body first and `done = TRUE` in the
  `else`, for both its tests.
- A test of a value against a few nearby constants returned as `return x == a || x == b || x == c;` compiles to a bit
  test, `sub; cmp #range; bhi; mov #1; lsl; tst #mask`, while the same test as an `if`, or as a `switch` that returns or
  sets a flag, compiles to compares. `itemmenu.c`'s `ItemMenu_IsRepel` returns the expression for its three repels.
- Nested tests that end in the same call can come from a nested `if` whose inner `if` has no `else`: the bag's item menu
  calls `func_0202d384` with `if (pocket != FREE_SPACE) { if (pocket != KEY_ITEMS) f(); } else if (...) f();`, which
  puts the Free Space's test after the other two; an `if`/`else if` chain or a `switch` puts it first.

## Loops

- A loop counted with `!=` tests with `beq` before the loop and `bne` at its end, where `<` gives `bls` and `blo`:
  the forms page walks its form-name table with `for (i = 0; i != form; i++)`.
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
- A loop that walks a pointer parameter (`for (; options->text != END; options++)`) reuses the test's load in the
  body. When the original loads the field again at the top of the body, the loop walks a local cursor set from the
  parameter instead (`for (option = options; option->text != END; option++)`), as bmp_menuwork.c's
  `ListMenuCore_FreeStrBufs` and `ListMenuCore_GetFirstFreeIndex` do.
- A bound written as `i <= N - 1` is computed once into a register before the loop and tested with `ble`, where
  `i < N` reloads `N` from the literal pool and tests with `blt`. The bag's Free Space list compacts its entries with
  `for (i = 0; i <= BAG_ITEM_LIST_SLOTS - 1; i++)` in `bag_item.c`'s `BagItemList_Compact`.

- A test that the original places after its body, entered from the top as well as from an earlier branch, is a loop
  that stops after its first pass: `while (box < n) { ...; break; }`. The trade does one box a frame this way in
  `pokemontrade_proc.c`'s `func_ov194_021bb3c0` and `pokemontrade_2d.c`'s `func_ov194_021c2c04` and
  `func_ov194_021c3e9c`, each 8 bytes or so shorter as an `if`. Comment it, so it isn't "fixed".

## Switches

- Switch cases are laid out in source order, not by value, so the layout shows the order the cases were written in.
- A switch's comparison tree and jump tables depend on every case value, including cases with no code: the Battle
  Subway's command switch only splits its values as the game does with an empty `case 102:` inside its first jump
  table, and empty cases that sit between others still get a comparison.
- Listing the empty cases also keeps a jump table where identical case bodies would otherwise be merged into
  comparisons: `ringtone_sys.c`'s `RingtoneSys_UpdateState` matches only with all four states written, two of them
  empty.
- A switch case that ends in the same code as another case is merged into it, so its end moves.
- A switch whose cases each set every argument of one call after it, as `research_top.c`'s button highlights set the
  BG, position, size and palette for `GFL_BGSysSetScrPaletteNo`, has each argument in a variable: the cases keep only
  the values that differ, and the values they share are set once at the merged end, in registers. Writing only the
  differing value as a variable leaves the others as constants at the call, and a call in each case is merged
  differently.
- A `switch` on a few small values tests them all first (`cmp; beq` for each, then `b` to the default), while an
  `if`/`else if` chain tests each one before its body (`cmp; bne` to the next test), as bmp_menu.c's
  `BmpMenu_NextCursorPos` does.

- A case that ends in the same code as the next (`seq++; done = TRUE; break;` before `case 3: done = TRUE; break;`)
  is merged into it, leaving a `b` to the next case. The original's code is that `b`, so write each case out in full
  with its own `done = TRUE; break;`, as wipe_sub.c's `WipeBright_Main` does, rather than a fall-through.
- The comparison tree depends only on the set of case values, and evenly spaced cases are grouped from the low end:
  the PC box search's `func_ov255_021d40e8` cases {0, 3, 9, 15, 21, 24, 27, 30} split at 27, and no order, type or
  `default:` changes that.
- A switch whose comparisons start with a value outside its jump table, `cmp r0, #5; beq other; cmp r0, #3; bls table`,
  with that value's code after the cases, is `if (x != 5) { switch (x) { ... } } else { ... }`; the same test before
  a compare chain, `cmp r0, #5; beq end`, is the `if` without an `else`. The Pokédex forms page's button input reads
  so: a `case 5:` in the switch puts 5 in the table.
- A short chain of tests whose first value does nothing, `cmp r5, #1; beq end; cmp r5, #3; bne next`, with each body
  after its test, is `if (x == 1) { } else if (x == 3) { ... } else if (x == 4) { ... }`; a switch of the same values
  branches to its cases instead. The Pokédex habitat map's state changes test the new state so.

## Floats and runtime helpers

- Float arithmetic calls MWCC's runtime helpers, such as `_fadd` and `_ffix`, which swan names `__aeabi_*`. When a
  complete file fails to link on one of them, rename it to the MWCC name with `rename_symbol.py`.
- Float arithmetic on a literal passes the literal first, as in `_fmul(4096.0f, x)` for `x * FX32_ONE`, whatever the
  source order. A constant kept in a local variable, which is reloaded from the literal pool at each use, keeps its
  place in the source instead, so `col * pixels` with `f32 pixels = 96.0f / 18;` passes `col` first. A compound
  assignment passes its target first: `research_list.c`'s `ResearchList_ReleaseDrag` calls `_dmul` with the drag
  speed in `r0`/`r1` and 1.5 in `r2`/`r3` for `wk->dragSpeed *= 1.5;`, while `wk->dragSpeed = wk->dragSpeed * 1.5;`
  loads the literal into `r0`/`r1`.
- NitroSDK's `FX32_CONST(x)` names `x` three times, in its test and in both branches, so a call written inside it is
  made three times. The game passes a local, as the capture rate in `btl_server_flow_sub.c` does.
- A literal in a compound assignment keeps its place: `y = scale.y / (f32)FX32_ONE; y += 0.01f;` calls
  `_fadd(y, 0.01f)`, where `y = scale.y / (f32)FX32_ONE + 0.01f;` calls `_fadd(0.01f, y)`, as the Pokédex cry page
  stretches its Pokémon.
- MWCC doesn't fold float arithmetic on a local variable that holds a constant, so `size / 2.0f` stays a call when
  `size` is a variable, while an expression of literals is folded.
- `compiler_probe.py` skips relocated words, so a wrong addend, such as a table index that the compiler folds into a
  literal pool address, or a call to the wrong runtime helper, only shows when the module check fails. Division and
  modulo call `_s32_div_f` for a signed operand and `_u32_div_f` (swan's `__aeabi_uidivmod`) for an unsigned one; a
  `u8` or `u16` promotes to a signed `int`, so `(u8)id % 5u` is the unsigned one, and so is a `u16` divided by a
  `u32`. Compare the built overlay in `build/<version>/build`
  with the original to find it.
- A 64-bit division calls `_ll_udiv` (swan's `__aeabi_uldivmod`) when either operand is unsigned. A call to it with
  operands sign-extended by `asr #0x1f` is an `int` cast to `u64`: the trade's box cubes turn by
  `((u64)((x + 48) % width) << 16) / width` in `func_ov194_021c2844`. A file that calls it needs `_ll_udiv` added as a
  label on `__aeabi_uldivmod` with `config_fixes.py add-label` before it can go complete.
- A float one ULP off a round decimal is written with the shortest digits that round to it, and a comment:
  Kadabra's sprite offset in `pokemontrade_3d.c` is 0x40533334, next to `3.3f`'s 0x40533333, so it is `3.3000002f`.

## Data and sections

- A function-local static of a function MWCC doesn't emit is dropped, while a global read only by an unemitted
  static function stays in the shared section. Data that outlived code the original link dead-stripped can't be
  reproduced under `-nodead`: wipe_sub.c's `.data` and `.rodata` hold the parameters of about 31 handlers the ROM
  doesn't have, as their own function-local statics, which an unemitted handler takes with it. Making them globals
  read by unemitted statics was not tried; it would put names on data Game Freak kept local.
- Static data is sorted by size. MWCC lists each object of a section when it is declared, a local struct initializer
  when its function is, and heapsorts the list by size starting from the last object declared. Equal sizes come out
  in no declared order: palanm.c's three 4-byte weights declared R, G, B lie G, R, B (`rodata_order.py --permute`
  searches the orders). Objects of 64 bytes or more, local initializers and globals that no code refers to get sections
  of their own, and the sections are created as the sorted list is walked: the section the other objects share sits where its smallest object comes, so a 12-byte
  initializer goes before a file's 19-byte table unless something smaller is shared. A read of a const global whose
  initializer has been seen is folded and doesn't count as a reference. Taking its address counts, and so does reading
  it before its definition, as an unused inline function in a header does, even though that code is never emitted.
  `demo/shinka_demo_view.h` reconstructs such accessors for the evolution demo's helix constants. Heapsort is not
  stable, so objects of the same size come out in an order that depends on where every object in the file is declared,
  and moving one object can reorder others. `tools/scripts/rodata_order.py` predicts the layout for a declaration order
  and tries the orders of the objects given with `--permute`; `intro_graphic.c` matches only with its light setups
  declared after the function whose BG setups are local initializers.
- A `static const` table declared inside the one function that reads it is listed where that function is, among
  the local initializers, rather than where file-scope data would be. `pokemontrade_nego.c` lays out its menus' item
  lists in the game's order only with its table of blocking fields declared inside `func_ov194_021bbe60`.
- A struct that is copied from `.rodata` and then has a few fields overwritten with computed values is one local
  initializer with the computed values in its braces. Its template gets a section of its own, while a `static const`
  template assigned to the local compiles to the same code but joins the shared section, so only the module check
  tells them apart. When the copy comes after some calls, the local is declared in a block after them, as the
  projection in `pokemontrade_3d.c`'s `func_ov194_021c1918` is.
- When `rodata_order.py`'s prediction disagrees with the built object, move one declaration at a time, compile, and
  compare the sections with the ROM. `pokemontrade_3d.c` lays out its scene tables in order only with its lights
  declared after the scenes' resource lists, and its cube data only with the vertices declared before the texture coordinates.
- String literals are laid out in `.data` in the order they first appear in the source, each aligned to 4, and an
  identical literal is shared from its first use. An assert's text is the expression as written, spacing included, so
  `GFL_ASSERT(a < (B*C))` needs the game's spacing (`delivery_beacon.c` turns clang-format off for it). In
  `delivery_beacon.c` the game has the asserts' `""` before the file name of an earlier allocation, which no source
  order tried reproduces: a folded assert or an unused inline creates no literal.
- Small objects that come after a larger one in the same file, out of size order, may be rows of one array: the PC
  box's `box2_ui.c` has seven cursor tables after a 540-byte one, and they are `sTrayCursorData[3][47]`, three rows
  of equal length that each end in a `TOUCH_RECT_END` entry, with other tables pointing into the rows. Once the sizes
  are right, any order of the objects of one size can be reached; keep the natural order elsewhere and let
  `rodata_order.py` solve for the same-size groups.
- The linker starts each `.rodata` section on a 4-byte boundary, whatever the section's own alignment, so a 6-byte
  `u16` table followed by a `u8` initializer leaves 2 bytes of padding between them, as at the start of
  `btl_server_flow.c`'s `.rodata`. `scrcmd_ochiba.c`'s 150-byte and 342-byte tables, both 2-aligned, end where only
  this layout puts them.
- The list that is heapsorted holds the file's `.data` tables as well as its `.rodata` objects, so a `.data` table's
  declaration reorders `.rodata` objects of the same size, and `rodata_order.py` predicts the layout only when it is
  given them too (string literals don't count). `worldtrade_search.c`'s four BG setups come out in the game's order
  only with its touch screen's cursor table, in `.data`, declared after the touch rectangles rather than at the top.
- `static const` data goes in `.rodata`, so a table that the original has in `.data` is not `const`. The module
  check fails if a table ends up in the wrong section, even when every function matches.
- A `static const` variable whose address is never taken is folded into the code and not emitted. If the original has
  it anyway, it is not `static`: a global that no code refers to gets a section of its own, laid out by size with the
  rest. An object laid out ahead of smaller ones is in a file of its own, linked first, as overlay 65's command table
  is in `scrcmd_pokemon_center_table.c`, and one laid out after larger ones is in a file linked after, as overlay 50's
  is in `scrcmd_bsubway_table.c`. The smallest objects come first, so an unreferenced word at a boundary, laid out
  after a file's larger tables, is the next file's first object: the 4 bytes at 0x021a773c in overlay 310 can't end
  `research_graph.c`, whose tables are larger, and as `research_common.c`'s global `ResearchCommon_Unused` they take
  a section of their own ahead of that file's 8-byte table, as the ROM has them.
- `GFL_ASSERT` keeps its expression as a string in `.data`, so the variable it tests keeps its original name, as the
  Medal Rally's `p_sv` does.
- Overlay IDs are linker symbols, written `OVERLAY_ID(279)` from `gfl/overlay.h`, which gives the literal pool entry
  a relocation. Mark the literal in the config with `tools/scripts/config_fixes.py overlay-id`.
- A table one element longer in the ROM than the code needs has a terminator: pml_item.c's `TM_MOVE_LIST` is 101 moves
  and a `MOVE_NONE`. Without it the next object starts 2 bytes early.

- Sections start 4-aligned at link time (`ALIGNALL(4)` in the LCF), whatever their own alignment: pms_data.c's
  12-entry `u16` initializer after 0x16 bytes of shared `.rodata` sits at +0x18, not +0x16.

## When nothing moves it

- When the order of instructions differs and no source change moves it, try `tools/scripts/permuter_setup.py`, which
  prepares a function for [decomp-permuter](https://github.com/simonlindholm/decomp-permuter). Its result can point to
  a plain change: `GFL_BGSysAllocChar`'s registers only matched with its tile size, a `u8` from a call, in an `int`.
