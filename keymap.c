/*iCopyright 2021 @mangoiv

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_number {
  _BASE,
  _NUM,
  _SYMB,
  _MUS,
  _ADJ,
  _GAME,
  _FGAME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] =  LAYOUT(
        KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,                                                 KC_Y,             KC_U,    KC_I,    KC_O,    KC_P,
        LT(_MUS,KC_A),         LGUI_T(KC_S),    LALT_T(KC_D),    LCTL_T(KC_F),    KC_G,                         KC_H,             RCTL_T(KC_J),    LALT_T(KC_K),    RGUI_T(KC_L),    RALT_T(KC_SCLN),
        LSFT_T(KC_Z), KC_X,    KC_C,    KC_V,    KC_B,                                                 KC_N,             KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
                                                 TG(_GAME),                                              TG(_ADJ),
                                        KC_TAB, LT(_SYMB,KC_SPC), KC_ESC,    KC_ENT, LT(_NUM,KC_BSPC), KC_DEL
    ),
    [_NUM] = LAYOUT(
        KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,                         KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
        KC_1,    KC_2,     KC_3,     KC_4,     KC_5,                          KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
        KC_LSFT, KC_F11,   KC_F12,   KC_MUTE, QK_BOOT,                         KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_RSFT,
                                            XXXXXXX,                      KC_NO,
                                        KC_TAB, KC_SPC, KC_ESC,    KC_ENT, KC_BSPC, KC_DEL
    ),
    [_SYMB] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,                        XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS,  KC_EQL,
        XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,                        KC_GRV,  KC_LBRC, KC_RBRC, KC_QUOT,  KC_BSLS,
        KC_LSFT, KC_F9,   KC_F10,  KC_F11,  KC_F12,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
                                            XXXXXXX,                      KC_NO,
                                        KC_TAB, KC_SPC, KC_ESC,    KC_ENT, KC_BSPC, KC_DEL
    ),
    [_MUS] = LAYOUT(
        KC_LCTL, KC_BTN1,  MS_UP,   KC_BTN2,  XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LALT, MS_LEFT,  MS_DOWN, MS_RGHT, XXXXXXX,                      KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        KC_LSFT, MS_ACL0,  MS_ACL1, MS_ACL2, XXXXXXX,                      KC_HOME,   KC_PGDN, KC_PGDN, KC_END, XXXXXXX,
                                            XXXXXXX,                      XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_ADJ] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      UG_NEXT,  UG_HUEU, UG_SATU, UG_VALU, UG_TOGG,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      UG_PREV,  UG_HUED, UG_SATD, UG_VALD, _______,
                                            XXXXXXX,                      _______,
                                   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_GAME] =  LAYOUT(
        KC_TAB,         KC_1,    KC_2,    KC_3,    KC_4,                                                 KC_Y,             KC_U,    KC_I,    KC_O,    KC_P,
        KC_LCTL,        KC_Q,    KC_W,    KC_E,    KC_R,                                                 KC_Y,             KC_U,    KC_I,    KC_O,    KC_P,
        KC_LSFT,        KC_A,    KC_S,    KC_D,    KC_F,                         KC_H,             RCTL_T(KC_J),    LALT_T(KC_K),    RGUI_T(KC_L),    RALT_T(KC_SCLN),
                                                 TG(_GAME),                                              TG(_ADJ),
                                        KC_B, LT(_FGAME, KC_SPC), KC_SPC,    LT(_NUM,KC_ENT), LT(_SYMB,KC_BSPC), KC_DEL
    ),
    [_FGAME] =  LAYOUT(
        KC_ESC,         KC_F1,   KC_F2,   KC_F3,   KC_F4,                                                 KC_Y,             KC_U,    KC_I,    KC_O,    KC_P,
        KC_LCTL,        KC_Q,    KC_W,    KC_E,    KC_R,                                                 KC_Y,             KC_U,    KC_I,    KC_O,    KC_P,
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,                         KC_H,             RCTL_T(KC_J),    LALT_T(KC_K),    RGUI_T(KC_L),    RALT_T(KC_SCLN),
                                                 TG(_GAME),                                              TG(_ADJ),
                                        KC_B, KC_SPC, KC_SPC,    LT(_NUM,KC_ENT), LT(_SYMB,KC_BSPC), KC_DEL
    ),
};

#ifdef OLED_ENABLE


oled_rotation_t oled_init_user(oled_rotation_t rotation) {

 if (is_keyboard_master()) {
    if(is_keyboard_left()){
      return OLED_ROTATION_270;
      }
      else {
        return OLED_ROTATION_90;
      }
    } else {
	    return OLED_ROTATION_0;
    }
}
static void render_logo(void) {
  static const char PROGMEM drac_logo[] = {
    // drac_logo, 128x64px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x0c, 0x18, 0x78, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x07, 0x3e, 0xfc, 0xf0, 0x00, 0x00, 0x00,
    0xf0, 0xf0, 0x60, 0x30, 0x30, 0x30, 0x00, 0x00, 0xe0, 0xe0, 0x30, 0x30, 0x30, 0x30, 0x30, 0xe0,
    0xe0, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x30, 0x30, 0x30, 0x70, 0xe0, 0xc0, 0x00, 0x00,
    0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0,
    0x80, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xf0, 0x80, 0xc0, 0xe0, 0xf0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0x7c, 0x3f, 0x0f, 0x00, 0x00, 0x00,
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xf8, 0xcc, 0x8c, 0x84, 0x86, 0x86, 0xc6, 0xff,
    0xff, 0x80, 0x80, 0x00, 0x3f, 0x7f, 0xe0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xf0, 0x71, 0x00, 0x00,
    0x1f, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xf8, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x1f,
    0x7f, 0x7f, 0x3e, 0x3e, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf8, 0xfc,
    0xfc, 0xfe, 0xfe, 0x7e, 0x7c, 0x78, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x60, 0x60,
    0x60, 0x60, 0x60, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xe0, 0x60, 0x60, 0x60, 0xc0,
    0xc0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07,
    0x0f, 0x3e, 0x7c, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf8,
    0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf1, 0x99, 0x18, 0x08,
    0x0c, 0x0c, 0x8c, 0xff, 0xff, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xc3, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x01, 0x01, 0x03, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01,
    0x01, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
  oled_write_raw_P(drac_logo, sizeof(drac_logo));
}

static void render_status(void) {
    oled_write_P(PSTR("This is\n~~~~~~~~~\nDracu\nLad\n~~~~~~~~~\nv1.0\n~~~~~~~~~\n"), false);
    uint8_t n = get_current_wpm();
    char    wpm_counter[4];
    wpm_counter[3] = '\0';
    wpm_counter[2] = '0' + n % 10;
    wpm_counter[1] = (n /= 10) % 10 ? '0' + (n) % 10 : (n / 10) % 10 ? '0' : ' ';
    wpm_counter[0] = n / 10 ? '0' + n / 10 : ' ';
    oled_write_P(PSTR("WPM:"), false);
    oled_write(wpm_counter, false);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("\nCaps: "), false);
    oled_write_P(led_state.caps_lock ? PSTR("on ") : PSTR("off"), false);
    oled_write_P(PSTR("\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base   "), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Numbers"), false);
            break;
        case _SYMB:
            oled_write_P(PSTR("Symbols"), false);
            break;
        case _ADJ:
            oled_write_P(PSTR("Adjust "), false);
            break;
        case _MUS:
            oled_write_P(PSTR("Mouse  "), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game  "), false);
            break;
        case _FGAME:
            oled_write_P(PSTR("FGame  "), false);
            break;
        default:
            oled_write_P(PSTR("Unkn "), false);
            break;
    }
}

bool oled_task_user(void) {
      if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();
    }
    return false;
}

#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 2) {
      if(clockwise) {
        tap_code(KC_PGUP);
      }
      else{
        tap_code(KC_PGDN);
      }
    }
    else if (index == 3  ) {
        // Page up/Page down
        if (clockwise) {
          tap_code(KC_WH_U);
        } else {
          tap_code(KC_WH_D);
        }
    }
    return true;
}
#endif
