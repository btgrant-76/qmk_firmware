# Troubleshooting Combo Introduction

When I started introducing combos into my userspace, I began to see compilation errors across all of my keymaps. The most common kind of error was related to "multiple definitions" of one combo-related thing or another. The error (more examples below) calls out a previous duplication, e.g. `key_combos` and the function in the error message seems to be related to the *last member of the keymap itself*, e.g. `achordion_chord_keymap` or `keymap_layer_count_raw`.

[If I move the combo definitions into individual keymaps](https://github.com/btgrant-76/qmk_firmware/commit/a594d3544ae9472c1f30fa7b2b5377b6e031dbc1), those keymaps, which include my userspace, compile without issue. But as soon as I introduce combo definition to my userspace, any other keymap compilation fails. 

## Combos in Keymaps

These build without issue. Of course, after adding combo definitions to `btgrant-76.h`, [those definitions](https://github.com/btgrant-76/qmk_firmware/blob/troubleshoot-combos/users/btgrant-76/btgrant-76.h#L45) need to be commented out in order to build.

### Lesovoz
`qmk compile -kb tsquash/lesovoz -km btgrant-76 -j 9 -c`

### Waterfowl
`qmk compile -kb waterfowl -km btgrant-76 -j 9 -c`

## Combos added to userspace/`btgrant-76.h`

With [combos defined in userspace](https://github.com/btgrant-76/qmk_firmware/commit/550a2c5f1e9abf9ebce3814e839bc91c510b1ef4), I picked a couple of *other* boards to use for troubleshooting. As mentioned above, the compilation failures describe multiple definitions of combo-related configurations, e.g. `key_combos`, `test_combo1`, `test_combo2`. Since I saw functions related to [Achordion](https://getreuer.info/posts/keyboards/achordion/index.html) integration appearing in several of the compilation errors, [I tried commenting out that code](https://github.com/btgrant-76/qmk_firmware/commit/e21989133ec50d3cf33b8c893445adf19afacb30); compilation continues to fail though `achordion_chord_keymap` no longer appeared in the errors.

Boards/keymaps are listed below with compilation commands and resulting errors. I compiled with and without `-j 9` but I wasn't able to observe any difference in the error/output.

### Planck

`qmk compile -kb planck/rev6_drop -km btgrant-76 -j 9 -c`

```console
Linking: .build/planck_rev6_drop_btgrant-76.elf                                                     [ERRORS]
 | 
 | /opt/homebrew/Cellar/arm-gcc-bin@8/8-2019-q3-update_3/bin/../lib/gcc/arm-none-eabi/8.3.1/../../../../arm-none-eabi/bin/ld: .build/obj_planck_rev6_drop_btgrant-76/quantum/keymap_introspection.o (symbol from plugin): in function `test_combo2':
 | (.text+0x0): multiple definition of `key_combos'; .build/obj_planck_rev6_drop_btgrant-76/btgrant-76.o (symbol from plugin):(.text+0x0): first defined here
 | /opt/homebrew/Cellar/arm-gcc-bin@8/8-2019-q3-update_3/bin/../lib/gcc/arm-none-eabi/8.3.1/../../../../arm-none-eabi/bin/ld: .build/obj_planck_rev6_drop_btgrant-76/quantum/keymap_introspection.o (symbol from plugin): in function `test_combo2':
 | (.text+0x0): multiple definition of `test_combo1'; .build/obj_planck_rev6_drop_btgrant-76/btgrant-76.o (symbol from plugin):(.text+0x0): first defined here
 | /opt/homebrew/Cellar/arm-gcc-bin@8/8-2019-q3-update_3/bin/../lib/gcc/arm-none-eabi/8.3.1/../../../../arm-none-eabi/bin/ld: .build/obj_planck_rev6_drop_btgrant-76/quantum/keymap_introspection.o (symbol from plugin): in function `test_combo2':
 | (.text+0x0): multiple definition of `test_combo2'; .build/obj_planck_rev6_drop_btgrant-76/btgrant-76.o (symbol from plugin):(.text+0x0): first defined here
 | collect2: error: ld returned 1 exit status
 | 
gmake[1]: *** [builddefs/common_rules.mk:268: .build/planck_rev6_drop_btgrant-76.elf] Error 1
```

### Willy

`qmk compile -kb tsquash/willy -km btgrant-76 -j 9 -c`

```console
Linking: .build/tsquash_willy_btgrant-76.elf                                                        [ERRORS]
 | 
 | /opt/homebrew/opt/avr-binutils/bin/avr-ld: .build/obj_tsquash_willy_btgrant-76/quantum/keymap_introspection.o (symbol from plugin): in function `achordion_chord_keymap':
 | (.text+0x0): multiple definition of `key_combos'; .build/obj_tsquash_willy_btgrant-76/btgrant-76.o (symbol from plugin):(.text+0x0): first defined here
 | /opt/homebrew/opt/avr-binutils/bin/avr-ld: .build/obj_tsquash_willy_btgrant-76/quantum/keymap_introspection.o (symbol from plugin): in function `achordion_chord_keymap':
 | (.text+0x0): multiple definition of `test_combo1'; .build/obj_tsquash_willy_btgrant-76/btgrant-76.o (symbol from plugin):(.text+0x0): first defined here
 | /opt/homebrew/opt/avr-binutils/bin/avr-ld: .build/obj_tsquash_willy_btgrant-76/quantum/keymap_introspection.o (symbol from plugin): in function `achordion_chord_keymap':
 | (.text+0x0): multiple definition of `test_combo2'; .build/obj_tsquash_willy_btgrant-76/btgrant-76.o (symbol from plugin):(.text+0x0): first defined here
 | collect2: error: ld returned 1 exit status
 | 
gmake[1]: *** [builddefs/common_rules.mk:268: .build/tsquash_willy_btgrant-76.elf] Error 1
```

#### With Achordion code commented out

After commenting out `achordion_chord_keymap` from the Willy `keymap.c`, this is the new error:

```console
Linking: .build/tsquash_willy_btgrant-76.elf                                                        [ERRORS]
 | 
 | /opt/homebrew/opt/avr-binutils/bin/avr-ld: .build/obj_tsquash_willy_btgrant-76/quantum/keymap_introspection.o (symbol from plugin): in function `keymap_layer_count_raw':
 | (.text+0x0): multiple definition of `key_combos'; .build/obj_tsquash_willy_btgrant-76/btgrant-76.o (symbol from plugin):(.text+0x0): first defined here
 | /opt/homebrew/opt/avr-binutils/bin/avr-ld: .build/obj_tsquash_willy_btgrant-76/quantum/keymap_introspection.o (symbol from plugin): in function `keymap_layer_count_raw':
 | (.text+0x0): multiple definition of `test_combo1'; .build/obj_tsquash_willy_btgrant-76/btgrant-76.o (symbol from plugin):(.text+0x0): first defined here
 | /opt/homebrew/opt/avr-binutils/bin/avr-ld: .build/obj_tsquash_willy_btgrant-76/quantum/keymap_introspection.o (symbol from plugin): in function `keymap_layer_count_raw':
 | (.text+0x0): multiple definition of `test_combo2'; .build/obj_tsquash_willy_btgrant-76/btgrant-76.o (symbol from plugin):(.text+0x0): first defined here
 | collect2: error: ld returned 1 exit status
 | 
gmake[1]: *** [builddefs/common_rules.mk:268: .build/tsquash_willy_btgrant-76.elf] Error 1
```
