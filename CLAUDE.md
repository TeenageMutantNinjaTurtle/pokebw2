# pokebw2

A matching decompilation of Pokémon Black 2 and White 2 (NDS/DSi, MWCC `dsi/1.1p1`), aiming at 100% C like
pokeemerald and then a native PC port. **README.md is the source of truth** for the build, layout, names and MWCC's
behavior. This file holds the rules that sessions get wrong and points to the skills that carry the procedures.

## Rules

- **Both ROMs stay byte for byte.** Every change ends with `ninja`, which checks each module and both SHA1s. Black 2 is
  primary. White 2 shares the source (`BLACK2`/`WHITE2` defines) and gets its configs through the version map, so
  change configs only with the scripts, which update both versions and record what they did:
  `add_source_file.py`, `mark_complete.py`, `rename_symbol.py`, `config_fixes.py`.
- **One source file per original file**, named after the ROM's embedded string, or descriptively, with the guess said
  in the header and the commit; never an overlay number. Functions go in address order, and in reverse for SPL,
  whose `1.2/base` compiler emits them reversed. Placement follows `include/`: `src/ovNNN/` for overlays; `src/gfl`, `src/system`,
  `src/spl` and later `src/nitro`, `src/nnsys` for main, by link order. README "Code organization" has the rest.
- **Names:** swan's first, marked as swan's in the header. Our own go through `rename_symbol.py`, which records them
  in `config/names.txt`. Types swan doesn't name are named after their owner. Rename a static's symbol to its C name.
- **Write C from the asm.** pret (pokeplatinum, pokeheartgold) and other decomps are references for names and
  structure, never code to copy. The user chose this explicitly for SPL.
- **Natural C only.** No inline asm, permuter noise, unexplained `volatile`, pointer-arithmetic tricks or meaningless
  temporaries. A function that doesn't match keeps the closest natural C and gets a row in
  `docs/nonmatching-functions.md` (both addresses, the difference, and what was tried).
- **Bugs:** `// BUG:` plus an `#ifdef BUGFIX` fix, with the original in `#else`.
- **Keep going.** Continue in file order and commit each file as it is done. Don't end a turn with a menu when the next
  step is obvious. Ask only real decisions, such as placement with no evidence or a change of scope. Answer any message
  the user sends mid-turn.
- **Learn.** A trick that worked and isn't in the README goes there, with an example. See the `record-lesson` skill.

## Environment

- Python is `.venv/bin/python`. The Bash tool's shell is not fish. Keep commands plain: shell variables, `$(...)`,
  loops and heredocs trip permission guards, especially in worktrees. Put logic in a script in the scratchpad.
- Other sessions work in this checkout and in `.claude/worktrees/*` at the same time. Stage files by name, never touch
  their uncommitted files, and don't use a bare `git stash`, since the stash is shared. `.claude/hooks/guard.py`
  enforces these.
- **Context is the scarce resource.** Never print a whole `.s` file, the README, a ninja log or a permuter log. Use
  `show_func.py NAME`, `compiler_probe.py --functions F --mismatches --align`, `grep -n` and `| tail`.
- Long jobs run with `run_in_background` or Monitor, never `sleep`. Run the permuter only under a memory cap: an
  uncapped `-j8` run got the terminal OOM-killed (see `.claude/skills/match-function/permuter.md`).
- A new worktree needs `orig/`, `tools/dsd`, `tools/objdiff-cli` and `tools/wibo` linked in, and
  `ninja extract/b2_us/config.yaml` before the first full build.

## Commands

| Task | Command |
| --- | --- |
| Disassemble a module (again after renames) | `tools/dsd dis -c config/b2_us/arm9/config.yaml -a build/asm --overlay 33` (or `--main`) |
| One function's asm | `.venv/bin/python tools/scripts/show_func.py NAME [NAME...]` |
| Probe a file against the ROM | `.venv/bin/python tools/scripts/compiler_probe.py src/X.c --compilers 1.1p1 --mismatches` |
| Diff one function | `... compiler_probe.py src/X.c --compilers 1.1p1 --functions F --show-diff 1.1p1 --align` |
| White 2 | add `--version w2_us` to the probe |
| Try respellings | `.venv/bin/python tools/scripts/try_variants.py src/X.c F --score variants.c` |
| Registers and stack slots of locals | `.venv/bin/python tools/scripts/locals.py src/X.c F` |
| File boundaries and names | `.venv/bin/python tools/scripts/source_files.py ov033 [--profile START END]` |
| Add a file to both versions | `.venv/bin/python tools/scripts/add_source_file.py src/X.c overlays/ov033 .text:A-B ... --incomplete` |
| Mark complete | `.venv/bin/python tools/scripts/mark_complete.py src/X.c` |
| Name a symbol | `.venv/bin/python tools/scripts/rename_symbol.py func_ov033_0217acd4 Name` |
| Build and verify | `python3 configure.py && ninja 2>&1 \| tail -20` (configure only when source files were added) |

`try_variants.py`, `mark_complete.py` and the probe's `--mismatches`, `--functions` and `--align` came with the
graphics branch (`worktree-graphics`, its `tools:` commits). Until it is merged, a checkout without them uses
`compiler_probe.py --show-diff 1.1p1` and checks statics by hand (`grep` the address in every `relocs.txt`).

## Skills and agents

Skills in `.claude/skills/`:
- `decomp-file`: the whole loop for one original file, from boundaries to commit.
- `match-function`: the triage-and-levers loop for a function that doesn't match, with its stop rules, the symptom
  index (`levers.md`) and the capped permuter (`permuter.md`).
- `fix-build`: a link, module-check, SHA1 or White 2-only failure.
- `finish-file`: verify both versions, mark complete, document mismatches, commit.
- `record-lesson`: where a new lesson goes and how to write it.

Agents in `.claude/agents/`, used to keep large asm and diffs out of the main context:
- `function-matcher`: grinds one function. It owns that file while it runs.
- `boundary-scout`: proposes the files of a module range, read-only.
- `struct-recovery`: derives a struct's layout from every access to it, read-only.
- `decomp-reviewer`: an adversarial check of a file's diff before commit, read-only.
