static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ~    |   1  |   2  |   3  |   4  |   5  |      |           |   =  |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------|  L0  |           |      |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ~L1  | Lft  | Rght |  LGui| Lalt |                                       |  Up  |  Dn  |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | Home |  End |       | PgUp | PgDn |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | LAlt |       | LAlt |      |      |
     *                                 | BkSp |  ESC |------|       |------| Enter| Space|
     *                                 |      |      | LGui |       | RGui |      |      |
     *                                 `--------------------'       `--------------------'
     */

    KEYMAP(  // layout: layer 0: default
        // left hand
        GRV, 1,   2,   3,   4,   5,    NO,
        TAB, Q,   W,   E,   R,   T,   LBRC,
        FN2, A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,   FN0,
        FN1, LEFT,  RIGHT,LGUI,LALT,
        HOME,END,
        LALT,
        BSPC,FN2, LGUI,
        // right hand
             EQL, 6,   7,   8,   9,   0,   MINS,
             RBRC,Y,   U,   I,   O,   P,   BSLS,
                  H,   J,   K,   L,   SCLN,QUOT,
             NO,  N,   M,   COMM,DOT, SLSH,RSFT,
                       UP,  DOWN,NO,  NO,  NO,
        PGUP,PGDN,
        LALT,
        RGUI,ENT, SPC
    ),

    KEYMAP(  // layout: layer 1: F-keys instead of numbers, media keys
        // left hand
        TRNS,F1,  F2,  F3,  F4,  F5,  F6,
        TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,TRNS,
        TRNS,MPRV,MNXT,MPLY,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F7,  F8,  F9,  F10, F11, F12, TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       RGUI,RALT,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    ACTION_DEFAULT_LAYER_SET(0),                    // FN0 - switch to Layer0
    ACTION_LAYER_MOMENTARY(1),                      // FN1 - push Layer1
    ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),          // FN2 - LCtl with tap Escape
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    print("action_function called\n");
    print("id  = "); phex(id); print("\n");
    print("opt = "); phex(opt); print("\n");
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}
