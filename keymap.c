#include QMK_KEYBOARD_H
//#include "caps_word.h"
#include "layer_lock.h"
// Smart shift implementation - https://github.com/qmk/qmk_firmware/blob/master/keyboards/crkbd/keymaps/rpbaptist/keymap.c
// Luna - https://github.com/HellSingCoder/qmk_firmware/tree/master/keyboards/sofle/keymaps/helltm
// Layer indicator - https://github.com/JReneHS/crkb_conf/tree/main/nahum_qwerty
// LOCKING LAYER https://getreuer.info/posts/keyboards/layer-lock/index.html

enum layer_number {
  _QWERTY = 0,
  _QGAME,
//   NAV,
//   NUM,
//   MEDIA,
//   SYM,
  FUNC,
  MODE,
  LAYER_NUMBER_MAX 
};

static const char *PROGMEM LAYER_NAME[] = {
    "QWRTY", "GAME", "FUNC", "MODE"
};

enum custom_keycodes {
  LLOCK = SAFE_RANGE,
  // Other custom keys...
};

/* Display functions*/
uint8_t get_current_layer(void) {
    return get_highest_layer(layer_state | default_layer_state);
}

const char *layer_upper_name(uint8_t layer) {
    if (layer < LAYER_NUMBER_MAX) {
        return LAYER_NAME[layer];
    } else {
        return "UNDEF";
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   `  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ALT  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | GUI  | ESC  | SPCE | / TAB   /       \Enter \  |BSPCE | DEL  | XXX  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */                 

 [_QWERTY] = LAYOUT( \
    KC_ESC,    KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
    KC_LALT,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
    KC_LCTL,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
              LT(MODE,KC_LGUI), LT(FUNC, KC_ESC), KC_SPC, KC_TAB,  KC_ENT, KC_BSPC, KC_DEL, _______
),
/* QWERTY GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   `  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  UP  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  | LEFT | DOWN | RGHT |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | GUI  |      | SPCE | / LALT  /       \Enter \  |BSPCE | DEL  | XXX  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QGAME] = LAYOUT( \
  KC_ESC  ,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB  ,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LCTL,    KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_UP,   KC_QUOT, \
  KC_LSFT,    KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_LEFT, KC_DOWN, KC_RIGHT, \
                              _______, U_NU  , KC_SPC, KC_LALT,  KC_ENT, KC_BSPC, _______, _______ \
),


// NAV
/*
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | REDO | PSTE |  UP  | CUT  | UNDO |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LGUI | LALT | LCTRL| LSFT | LOCK |-------.    ,-------| CAPS | LEFT | DOWN | RGHT | COPY |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | RGUI | RALT | RCTRL| RSFT |      |-------|    |-------|  INS | HOME | PBUP | PGDN | END  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \ ENTR \  | BSPC |  DEL |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
/**
[NAV] = LAYOUT(
    U_NU,   U_NU,    U_NU,    U_NU,    U_NU,    U_NU,               U_NU,    U_NU,    U_NU,    U_NU,    U_NU,   U_NU, \
    U_NU,   U_NA,    U_NA,    U_NA,    U_NA,    U_NA,               U_REDO,  U_PSTE,  KC_UP,   U_CUT,   U_UNDO, U_NU, \
    U_NU,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, LLOCK,              KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, U_COPY, U_NU, \
    U_NU,   KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, U_NU, U_NU,U_NU,    KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END, U_NU, \
                          U_NA,    U_NA,    U_NA,     U_NA,KC_ENT,  KC_BSPC, KC_DEL,  U_NP \
    ),
**/
// NUMBER
/*
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  [   |  7   |  8   |  9   |  ]   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  ;   |  4   |  5   |  6   |  =   |-------.    ,-------| LOCK | LSFT | LCTRL| LALT | LGUI |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  +   |  1   |  2   |  3   |  /   |-------|    |-------|      | RSFT | RCTRL| RALT | RGUI |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |   .  |   0  | /   -   /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
/**
[NUM] = LAYOUT(
    U_NU,   U_NU,    U_NU,    U_NU,    U_NU,    U_NU,                   U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU, \
    U_NU,   KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                U_NA,    U_NA,    U_NA,    U_NA,    U_NU,    U_NU, \
    U_NU,   KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                 LLOCK,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, U_NU, \
    U_NU,   KC_PLUS, KC_1,    KC_2,    KC_3,    KC_BSLS, U_NU,    U_NU, U_NA,    KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, U_NU,\
                              U_NU,    KC_DOT,  KC_0,    KC_MINS, U_NA, U_NA,    U_NA,    U_NA \
  ),
**/
// MEDIA
/*
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      | WINL |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LGUI | LALT | LCTRL| LSFT | LOCK |-------.    ,-------|      | REWD | VOLD | VOLU | FORW |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | RGUI | RALT | RCTRL| RSFT |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \ MPAUS\  | PLAY | MUTE |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
/**
[MEDIA] = LAYOUT(
    U_NU,   U_NU,    U_NU,    U_NU,    U_NU,    U_NU,                   U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU, \
    U_NU,   U_NA ,   U_NA,    U_NA,    U_NA,    U_NA,                   U_NA,    U_WINLK, U_NA,    U_NA,    U_NA,    U_NU, \
    U_NU,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, LLOCK,                  U_NU,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, U_NU, \
    U_NU,   KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, U_NU,  U_NU,    U_NU,   U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU, \
                            U_NA,    U_NA,    U_NA,    U_NA,    KC_MSTP, KC_MPLY, KC_MUTE, U_NU \
    ),
**/
/* SYMBOLS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   &  |   @  |   <  |   (  |   )  |   >  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   \  |   !  |   _  |   +  |   =  |   *  |-------.    ,-------| LOCK |LShift| LCtrl| LAlt | LGUI |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |   ~  |   ^  |   -  |  [|{ |  }|] |  |   |-------|    |-------|      | RSFT | RCTRL| RALT | RGUI |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |   %  |   $  | /   #   /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
/**
[SYM] = LAYOUT(
    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,                      U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU, \
    KC_AMPR, KC_AT  , KC_LABK, KC_LPRN, KC_RPRN, KC_RABK,                   U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NU, \
    KC_BSLS,  KC_EXLM, KC_UNDS, KC_PLUS, KC_EQL,  KC_ASTR,                   LLOCK,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, U_NU, \
    KC_TILD, KC_CIRC, KC_MINS, KC_LBRC, KC_RBRC, KC_PIPE,   U_NU,   U_NU,   U_NA,    KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, U_NU,\
                                U_NP,    KC_PERC, KC_DLR,   KC_HASH,U_NA,   U_NA,    U_NA,    U_NA \
    ),
**/

//FUNCTION
/*
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F12 |  F7  |  F8  |  F9  | PSCR |                    | CALC |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F11 |  F4  |  F5  |  F6  | APP  |-------.    ,-------| LOCK |LShift| LCtrl| LAlt | LGUI |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  F10 |  F1  |  F2  |  F3  | PAUSE|-------|    |-------| NKRO | RSFT | RCTRL| RALT | RGUI |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[FUNC] = LAYOUT(
    _______, U_NU,    U_NU,    U_NU,    U_NU,    U_NU,                      U_NU,    U_NU,     U_NU,        U_NU,       U_NU,    U_NU, \
    _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                   KC_CALC, U_NU,     U_NU,        U_NU,       U_NA,    U_NA,\
    _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_APP ,                   LLOCK,   KC_LSFT,  KC_LCTL,     KC_LALT,    KC_LGUI, U_NU,\
    _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, U_NU,   U_NU,     NK_TOGG, KC_RSFT,  KC_RCTL,     KC_RALT,    KC_RGUI, U_NU,\
                                 U_NP,    U_NU  ,  U_NU,  U_NU,   U_NA,     U_NA,    U_NA,     U_NA \
  ),

// MODE
/*
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |QWERTY| QGME | FUNC |      | CAPS |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LGUI | LALT | LCTRL| LSFT | NKRO |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | RGUI | RALT | RCTRL| RSFT |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[MODE] = LAYOUT(
    U_NU, U_NU,         U_NU,       U_NU,    U_NU,      U_NU,                      U_NU,    U_NU,          U_NU,       U_NU,       U_NU,    U_NU, \
    U_NU, TG(_QWERTY),  TG(_QGAME), U_NU,    U_NU,      KC_CAPS,                   U_NU,    U_NU,          U_NU,       U_NU,       U_NU,    U_NU,\
    U_NU, KC_LGUI,      KC_LALT,    KC_LCTL, KC_LSFT,   NK_TOGG,                   U_NU,    U_NU,          U_NU,       U_NU,       U_NU,    U_NU,\
    U_NU, KC_RGUI,      KC_RALT,    KC_RCTL, KC_RSFT,   KC_PAUS, U_NU,   U_NU,     U_NU,    U_NU,          U_NU,       U_NU,       U_NU,    U_NU,\
                                    _______, U_NU  ,  U_NU,  U_NU,                 U_NA,    U_NA,    U_NA,     U_NA \
  )
};

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

/* status variables */
int   current_wpm = 0;
bool caps_on = false;

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}


void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_on_off_status(char *name, bool status) {
    static const char PROGMEM on_symbol[] = {0x82,0x83,0x0};
    static const char PROGMEM off_symbol[] = {0x80,0x81,0x0};

    oled_write_P(PSTR(name),false);
    if (status) {
        oled_write_P(on_symbol, false);
    } else {
        oled_write_P(off_symbol, false);
    }
}

void render_status_main(void) {
    led_t led_usb_state = host_keyboard_led_state();
    bool  caps          = led_usb_state.caps_lock || is_caps_word_on();    
    /* Display the letter layout */
    oled_clear();
    oled_set_cursor(0, 5);
    oled_write_ln(layer_upper_name(get_current_layer()), false);

    oled_set_cursor(0, 7);


    // Display the status of the keyboard
    render_on_off_status("CPS", caps);
    render_on_off_status("LCK", is_any_layer_locked());
    render_on_off_status("NRO", keymap_config.nkro);

    oled_set_cursor(0,11);

    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void render_status_secondary(void) {
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    #if OLED_TIMEOUT > 0
    /* let the main half decide when to turn off the animation
        using last activite. The animation prevents the normal
        timeout from occuring */
    if (is_keyboard_master() == true && 
        last_input_activity_elapsed() > OLED_TIMEOUT && 
        last_led_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
    } else {
        led_t led_usb_state = host_keyboard_led_state();

        // Get global state of certain keyboard stats for the oled rendering
        caps_on = led_usb_state.caps_lock || is_caps_word_on(); 
        current_wpm = get_current_wpm();

        if (is_keyboard_master()) {
            // Renders the current keyboard state (layer, lock, caps, scroll, etc)
            render_status_main();  
        } else {
            render_status_secondary();
        }
    }
    #endif

    return true;
}
#endif // OLED_ENABLE

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    // switch (keycode) {
    //     default:

    // }

    // Check if we need to handle the layer lock (llock) key
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }

    return true;
}

// For layer lock. Need to add timeout every scan cycle
// Run time based events at then end of each update cycle
void housekeeping_task_user(void) {
    layer_lock_task();
}

// Tasks to do when the keyboard is told the system is idle
void suspend_power_down_user(void) {
    #ifdef OLED_ENABLE
    oled_off();
    #endif

    // Reset layer back to default
    layer_clear();

}

//Template
/*
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */