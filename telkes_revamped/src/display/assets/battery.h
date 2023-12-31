// Image Size     : @25x15 pixels
// Memory usage   : @750 bytes

#include <Arduino.h>

const unsigned short battery_low[375] PROGMEM={
0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0010 (16) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE,   // 0x0020 (32) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0030 (48) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xEF9E, 0x9D56, 0x8D35, 0x8D16, 0x9536, 0x9515, 0x9535, 0x9535, 0x9516,   // 0x0040 (64) pixels
0x9516, 0x9515, 0x9515, 0xA5B7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF7FF, 0xFFFF,   // 0x0050 (80) pixels
0x7C34, 0xA618, 0xC73D, 0xBF5D, 0xBE5A, 0xB618, 0xBE58, 0xBE19, 0xB639, 0xB639, 0xBE38, 0xBE5A, 0x9534, 0xA5B6, 0xFFDF, 0xFFFF,   // 0x0060 (96) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x74B4, 0xFFFF, 0xFD12, 0xFC4F, 0xFF9C, 0xFFFF, 0xFFDF,   // 0x0070 (112) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xEF9E, 0x53AD, 0xB61A, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0080 (128) pixels
0xFFFF, 0xFFFF, 0x7536, 0xF6DA, 0xD8C2, 0xE800, 0xFD34, 0xFFFF, 0xF7FF, 0xFFDF, 0xFFDF, 0xFFDF, 0xFFDF, 0xFFFF, 0xFFDE, 0xC69B,   // 0x0090 (144) pixels
0x6452, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7D56, 0xF71C, 0xD1E5, 0xE8C1, 0xFD96,   // 0x00A0 (160) pixels
0xFFFF, 0xFFFE, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xF7FF, 0xFFFF, 0xFFFF, 0x7CB5, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00B0 (176) pixels
0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0x74B4, 0xE618, 0xD9E6, 0xF101, 0xED34, 0xDFBE, 0xE71C, 0xE6FC, 0xDF3C, 0xE6FB, 0xDF1C, 0xDEFC,   // 0x00C0 (192) pixels
0xE73C, 0xE73C, 0x6C32, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x6C73, 0xD5D7, 0xD9A4,   // 0x00D0 (208) pixels
0xF0E0, 0xECD3, 0xD79E, 0xD6BB, 0xDEBA, 0xD6DB, 0xD6BA, 0xDEBA, 0xD6BA, 0xE71C, 0xE6FB, 0x5BB0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00E0 (224) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x6C93, 0xE679, 0xE227, 0xF963, 0xED54, 0xDFDE, 0xE71C, 0xE71B, 0xE73C, 0xE71C,   // 0x00F0 (240) pixels
0xE71C, 0xF77D, 0xD69A, 0x5BB0, 0x7C93, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFF, 0x636E,   // 0x0100 (256) pixels
0xC659, 0xDEDA, 0xD65A, 0xD6BB, 0xCEDA, 0xD699, 0xD6BA, 0xD6BA, 0xD69A, 0xD6BA, 0xE73D, 0xAD97, 0x5BD0, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0110 (272) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xB639, 0x7471, 0x6C32, 0x6452, 0x6C11, 0x6BF1, 0x6C11, 0x6C11,   // 0x0120 (288) pixels
0x6C10, 0x6C31, 0x6C11, 0x6C10, 0x7431, 0xE73C, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF,   // 0x0130 (304) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0140 (320) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0150 (336) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF7FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0160 (352) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0170 (368) pixels
};

const unsigned short battery_half[375] PROGMEM={
0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0010 (16) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFDF,   // 0x0020 (32) pixels
0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0030 (48) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xE79D, 0x9D56, 0x8D37, 0x8D36, 0x8D16, 0x9516, 0x8D15, 0x9535, 0x8D15,   // 0x0040 (64) pixels
0x9535, 0x8D35, 0x9515, 0xA5B7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0050 (80) pixels
0x7454, 0xA617, 0xBE9E, 0xBEBE, 0xBE9E, 0xBE7D, 0xB67E, 0xB65D, 0xB65A, 0xB619, 0xBE18, 0xBE5A, 0x9534, 0xA5B6, 0xFFDF, 0xFFFF,   // 0x0060 (96) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x74B3, 0xFFFF, 0xFF2F, 0xFECE, 0xFEEF, 0xFF4E, 0xFF6E,   // 0x0070 (112) pixels
0xFF6F, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xEF9E, 0x53AD, 0xB61A, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0080 (128) pixels
0xFFFF, 0xFFFF, 0x7CB8, 0xF759, 0xE500, 0xD4A0, 0xDCE0, 0xFDA0, 0xFDA0, 0xFDC1, 0xFF79, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFDE, 0xC69B,   // 0x0090 (144) pixels
0x6452, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0x7CF6, 0xF79A, 0xED60, 0xDD00, 0xDD40,   // 0x00A0 (160) pixels
0xFE00, 0xFDE0, 0xFE00, 0xFF99, 0xFFFF, 0xFFDF, 0xF7FF, 0xFFFF, 0xFFFF, 0x7CB5, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00B0 (176) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x6C54, 0xDEB8, 0xE561, 0xDD20, 0xDD41, 0xFDE0, 0xFE00, 0xFE00, 0xE6D7, 0xDF3F, 0xE71B, 0xDEFC,   // 0x00C0 (192) pixels
0xE73C, 0xE73C, 0x6C32, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x6BF3, 0xDE77, 0xE540,   // 0x00D0 (208) pixels
0xDD00, 0xDD40, 0xFE00, 0xFDE0, 0xFDE0, 0xDE96, 0xCEDE, 0xD6BA, 0xD6BA, 0xE71C, 0xE6FB, 0x5BB0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00E0 (224) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x6C14, 0xE6F9, 0xEDA2, 0xE541, 0xE561, 0xFE22, 0xFE22, 0xFE42, 0xEED6, 0xE71F,   // 0x00F0 (240) pixels
0xE71B, 0xF77D, 0xD69A, 0x5BB0, 0x7C93, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0x5B6F,   // 0x0100 (256) pixels
0xBE59, 0xE6FA, 0xD698, 0xD699, 0xD699, 0xD6B8, 0xD699, 0xD6BA, 0xD6BA, 0xD6BB, 0xE73D, 0xAD97, 0x5BD0, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0110 (272) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xB61A, 0x7C91, 0x6C32, 0x6C33, 0x6C32, 0x6412, 0x6C12, 0x6C32,   // 0x0120 (288) pixels
0x6C11, 0x6C10, 0x6C11, 0x6C10, 0x7431, 0xE73C, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0130 (304) pixels
0xFFFF, 0xF7FF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0140 (320) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0150 (336) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF7FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0160 (352) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0170 (368) pixels
};

const unsigned short battery_full[375] PROGMEM={
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0010 (16) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0020 (32) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0030 (48) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xEF9F, 0x9576, 0x8D36, 0x8D35, 0x9535, 0x9535, 0x8D15, 0x8D15, 0x9515,   // 0x0040 (64) pixels
0x9515, 0x9536, 0x8D16, 0xA5B8, 0xFFBF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0050 (80) pixels
0x7433, 0xADD8, 0xDEDC, 0xD6BD, 0xDEBD, 0xDEBD, 0xD69C, 0xD69D, 0xD69C, 0xD69C, 0xD69C, 0xD67B, 0x8D36, 0xADB6, 0xFFFF, 0xFFFF,   // 0x0060 (96) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7CB3, 0xFFFF, 0xB6D4, 0x9E72, 0xA693, 0xA693, 0xA6B3,   // 0x0070 (112) pixels
0xAF14, 0xAF14, 0xAF14, 0x9ED3, 0xD7D8, 0xF7BF, 0x538E, 0xB63A, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0080 (128) pixels
0xFFFF, 0xFFFF, 0x8CF6, 0xDF3B, 0x2466, 0x1C03, 0x2444, 0x1C24, 0x2465, 0x34E6, 0x3506, 0x2D26, 0x1CA4, 0x4DAB, 0xFFDE, 0xD6DC,   // 0x0090 (144) pixels
0x6C12, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x8CD6, 0xE75D, 0x4CE9, 0x3C88, 0x44C9,   // 0x00A0 (160) pixels
0x44A8, 0x44E8, 0x4D6A, 0x4D6A, 0x4D89, 0x3527, 0x65CD, 0xFFFF, 0xFFFF, 0x7CB3, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00B0 (176) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7C53, 0xC6D8, 0x4CE8, 0x3C87, 0x44C8, 0x44A8, 0x44E8, 0x4D6A, 0x4D8A, 0x4D89, 0x3D48, 0x5DCC,   // 0x00C0 (192) pixels
0xEF5D, 0xE73D, 0x7432, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7432, 0xBE77, 0x44A7,   // 0x00D0 (208) pixels
0x3487, 0x3CA7, 0x3C87, 0x3CA7, 0x4D49, 0x4D69, 0x4588, 0x3527, 0x5D8B, 0xEF1D, 0xE6FB, 0x63B0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00E0 (224) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7C33, 0xD6DA, 0x554A, 0x44E8, 0x4D09, 0x4CE9, 0x4D29, 0x5D8B, 0x55AB, 0x55AA,   // 0x00F0 (240) pixels
0x4D89, 0x7E6F, 0xD6BA, 0x63D1, 0x7C92, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF7FF, 0x5B6F,   // 0x0100 (256) pixels
0xC659, 0xD6DA, 0xCE79, 0xCE9A, 0xCE79, 0xCE79, 0xCE9A, 0xCEB9, 0xCEB9, 0xC699, 0xE71B, 0xAD97, 0x63B1, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0110 (272) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xBE19, 0x7471, 0x7C12, 0x7412, 0x7432, 0x7412, 0x7432, 0x7412,   // 0x0120 (288) pixels
0x7412, 0x7412, 0x7432, 0x7411, 0x7432, 0xE71D, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF,   // 0x0130 (304) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF7FF,   // 0x0140 (320) pixels
0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0150 (336) pixels
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0160 (352) pixels
0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0170 (368) pixels
};
