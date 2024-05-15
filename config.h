/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#pragma once

/* Select hand configuration */

#define MASTER_RIGHT
// #define MASTER_RIGHT
// #define EE_HANDS

#ifdef RGBLIGHT_ENABLE
#endif
    #define CAPS_WORD_INVERT_ON_SHIFT
    #define TAPPING_TERM 175
    #define DYNAMIC_KEYMAP_LAYER_COUNT 8
    #define NO_ACTION_ONESHOT
    #define NO_ACTION_MACRO
    #define NO_ACTION_FUNCTION
    #define WPM_ESTIMATED_WORD_SIZE	4
    #define WPM_SAMPLE_SECONDS 4
    #define WPM_SAMPLE_PERIODS 20
