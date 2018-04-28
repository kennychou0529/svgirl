/*
 * This file is an optional part of Libsvgtiny
 * Licensed under the MIT License,
 *                http://opensource.org/licenses/mit-license.php
 *
 * It allows you to omit colors.gperf as a way of binding the named colors.
 *
 * Copyright 2016 by David Phillip Oster
 */
#include <stdlib.h>
#include <string.h>

#include "svgtiny.h"
#include "svgtiny_internal.h"


#ifndef UNUSED
#define UNUSED(x) ((void) (x))
#endif

// from colors.gperf.
// search for: ^([a-zA-Z]+),[ \t]+(svgtiny_RGB[^\)]+\))  replace by: {"$1", $2},
static struct svgtiny_named_color sSortedColors[] = {
    {"aliceblue", svgtiny_RGB(240, 248, 255)},
    {"antiquewhite", svgtiny_RGB(250, 235, 215)},
    {"aqua", svgtiny_RGB(0, 255, 255)},
    {"aquamarine", svgtiny_RGB(127, 255, 212)},
    {"azure", svgtiny_RGB(240, 255, 255)},
    {"beige", svgtiny_RGB(245, 245, 220)},
    {"bisque", svgtiny_RGB(255, 228, 196)},
    {"black", svgtiny_RGB(0, 0, 0)},
    {"blanchedalmond", svgtiny_RGB(255, 235, 205)},
    {"blue", svgtiny_RGB(0, 0, 255)},
    {"blueviolet", svgtiny_RGB(138, 43, 226)},
    {"brown", svgtiny_RGB(165, 42, 42)},
    {"burlywood", svgtiny_RGB(222, 184, 135)},
    {"cadetblue", svgtiny_RGB(95, 158, 160)},
    {"chartreuse", svgtiny_RGB(127, 255, 0)},
    {"chocolate", svgtiny_RGB(210, 105, 30)},
    {"coral", svgtiny_RGB(255, 127, 80)},
    {"cornflowerblue", svgtiny_RGB(100, 149, 237)},
    {"cornsilk", svgtiny_RGB(255, 248, 220)},
    {"crimson", svgtiny_RGB(220, 20, 60)},
    {"cyan", svgtiny_RGB(0, 255, 255)},
    {"darkblue", svgtiny_RGB(0, 0, 139)},
    {"darkcyan", svgtiny_RGB(0, 139, 139)},
    {"darkgoldenrod", svgtiny_RGB(184, 134, 11)},
    {"darkgray", svgtiny_RGB(169, 169, 169)},
    {"darkgreen", svgtiny_RGB(0, 100, 0)},
    {"darkgrey", svgtiny_RGB(169, 169, 169)},
    {"darkkhaki", svgtiny_RGB(189, 183, 107)},
    {"darkmagenta", svgtiny_RGB(139, 0, 139)},
    {"darkolivegreen", svgtiny_RGB(85, 107, 47)},
    {"darkorange", svgtiny_RGB(255, 140, 0)},
    {"darkorchid", svgtiny_RGB(153, 50, 204)},
    {"darkred", svgtiny_RGB(139, 0, 0)},
    {"darksalmon", svgtiny_RGB(233, 150, 122)},
    {"darkseagreen", svgtiny_RGB(143, 188, 143)},
    {"darkslateblue", svgtiny_RGB(72, 61, 139)},
    {"darkslategray", svgtiny_RGB(47, 79, 79)},
    {"darkslategrey", svgtiny_RGB(47, 79, 79)},
    {"darkturquoise", svgtiny_RGB(0, 206, 209)},
    {"darkviolet", svgtiny_RGB(148, 0, 211)},
    {"deeppink", svgtiny_RGB(255, 20, 147)},
    {"deepskyblue", svgtiny_RGB(0, 191, 255)},
    {"dimgray", svgtiny_RGB(105, 105, 105)},
    {"dimgrey", svgtiny_RGB(105, 105, 105)},
    {"dodgerblue", svgtiny_RGB(30, 144, 255)},
    {"firebrick", svgtiny_RGB(178, 34, 34)},
    {"floralwhite", svgtiny_RGB(255, 250, 240)},
    {"forestgreen", svgtiny_RGB(34, 139, 34)},
    {"fuchsia", svgtiny_RGB(255, 0, 255)},
    {"gainsboro", svgtiny_RGB(220, 220, 220)},
    {"ghostwhite", svgtiny_RGB(248, 248, 255)},
    {"gold", svgtiny_RGB(255, 215, 0)},
    {"goldenrod", svgtiny_RGB(218, 165, 32)},
    {"gray", svgtiny_RGB(128, 128, 128)},
    {"grey", svgtiny_RGB(128, 128, 128)},
    {"green", svgtiny_RGB(0, 128, 0)},
    {"greenyellow", svgtiny_RGB(173, 255, 47)},
    {"honeydew", svgtiny_RGB(240, 255, 240)},
    {"hotpink", svgtiny_RGB(255, 105, 180)},
    {"indianred", svgtiny_RGB(205, 92, 92)},
    {"indigo", svgtiny_RGB(75, 0, 130)},
    {"ivory", svgtiny_RGB(255, 255, 240)},
    {"khaki", svgtiny_RGB(240, 230, 140)},
    {"lavender", svgtiny_RGB(230, 230, 250)},
    {"lavenderblush", svgtiny_RGB(255, 240, 245)},
    {"lawngreen", svgtiny_RGB(124, 252, 0)},
    {"lemonchiffon", svgtiny_RGB(255, 250, 205)},
    {"lightblue", svgtiny_RGB(173, 216, 230)},
    {"lightcoral", svgtiny_RGB(240, 128, 128)},
    {"lightcyan", svgtiny_RGB(224, 255, 255)},
    {"lightgoldenrodyellow", svgtiny_RGB(250, 250, 210)},
    {"lightgray", svgtiny_RGB(211, 211, 211)},
    {"lightgreen", svgtiny_RGB(144, 238, 144)},
    {"lightgrey", svgtiny_RGB(211, 211, 211)},
    {"lightpink", svgtiny_RGB(255, 182, 193)},
    {"lightsalmon", svgtiny_RGB(255, 160, 122)},
    {"lightseagreen", svgtiny_RGB(32, 178, 170)},
    {"lightskyblue", svgtiny_RGB(135, 206, 250)},
    {"lightslategray", svgtiny_RGB(119, 136, 153)},
    {"lightslategrey", svgtiny_RGB(119, 136, 153)},
    {"lightsteelblue", svgtiny_RGB(176, 196, 222)},
    {"lightyellow", svgtiny_RGB(255, 255, 224)},
    {"lime", svgtiny_RGB(0, 255, 0)},
    {"limegreen", svgtiny_RGB(50, 205, 50)},
    {"linen", svgtiny_RGB(250, 240, 230)},
    {"magenta", svgtiny_RGB(255, 0, 255)},
    {"maroon", svgtiny_RGB(128, 0, 0)},
    {"mediumaquamarine", svgtiny_RGB(102, 205, 170)},
    {"mediumblue", svgtiny_RGB(0, 0, 205)},
    {"mediumorchid", svgtiny_RGB(186, 85, 211)},
    {"mediumpurple", svgtiny_RGB(147, 112, 219)},
    {"mediumseagreen", svgtiny_RGB(60, 179, 113)},
    {"mediumslateblue", svgtiny_RGB(123, 104, 238)},
    {"mediumspringgreen", svgtiny_RGB(0, 250, 154)},
    {"mediumturquoise", svgtiny_RGB(72, 209, 204)},
    {"mediumvioletred", svgtiny_RGB(199, 21, 133)},
    {"midnightblue", svgtiny_RGB(25, 25, 112)},
    {"mintcream", svgtiny_RGB(245, 255, 250)},
    {"mistyrose", svgtiny_RGB(255, 228, 225)},
    {"moccasin", svgtiny_RGB(255, 228, 181)},
    {"navajowhite", svgtiny_RGB(255, 222, 173)},
    {"navy", svgtiny_RGB(0, 0, 128)},
    {"oldlace", svgtiny_RGB(253, 245, 230)},
    {"olive", svgtiny_RGB(128, 128, 0)},
    {"olivedrab", svgtiny_RGB(107, 142, 35)},
    {"orange", svgtiny_RGB(255, 165, 0)},
    {"orangered", svgtiny_RGB(255, 69, 0)},
    {"orchid", svgtiny_RGB(218, 112, 214)},
    {"palegoldenrod", svgtiny_RGB(238, 232, 170)},
    {"palegreen", svgtiny_RGB(152, 251, 152)},
    {"paleturquoise", svgtiny_RGB(175, 238, 238)},
    {"palevioletred", svgtiny_RGB(219, 112, 147)},
    {"papayawhip", svgtiny_RGB(255, 239, 213)},
    {"peachpuff", svgtiny_RGB(255, 218, 185)},
    {"peru", svgtiny_RGB(205, 133, 63)},
    {"pink", svgtiny_RGB(255, 192, 203)},
    {"plum", svgtiny_RGB(221, 160, 221)},
    {"powderblue", svgtiny_RGB(176, 224, 230)},
    {"purple", svgtiny_RGB(128, 0, 128)},
    {"red", svgtiny_RGB(255, 0, 0)},
    {"rosybrown", svgtiny_RGB(188, 143, 143)},
    {"royalblue", svgtiny_RGB(65, 105, 225)},
    {"saddlebrown", svgtiny_RGB(139, 69, 19)},
    {"salmon", svgtiny_RGB(250, 128, 114)},
    {"sandybrown", svgtiny_RGB(244, 164, 96)},
    {"seagreen", svgtiny_RGB(46, 139, 87)},
    {"seashell", svgtiny_RGB(255, 245, 238)},
    {"sienna", svgtiny_RGB(160, 82, 45)},
    {"silver", svgtiny_RGB(192, 192, 192)},
    {"skyblue", svgtiny_RGB(135, 206, 235)},
    {"slateblue", svgtiny_RGB(106, 90, 205)},
    {"slategray", svgtiny_RGB(112, 128, 144)},
    {"slategrey", svgtiny_RGB(112, 128, 144)},
    {"snow", svgtiny_RGB(255, 250, 250)},
    {"springgreen", svgtiny_RGB(0, 255, 127)},
    {"steelblue", svgtiny_RGB(70, 130, 180)},
    {"tan", svgtiny_RGB(210, 180, 140)},
    {"teal", svgtiny_RGB(0, 128, 128)},
    {"thistle", svgtiny_RGB(216, 191, 216)},
    {"tomato", svgtiny_RGB(255, 99, 71)},
    {"turquoise", svgtiny_RGB(64, 224, 208)},
    {"violet", svgtiny_RGB(238, 130, 238)},
    {"wheat", svgtiny_RGB(245, 222, 179)},
    {"white", svgtiny_RGB(255, 255, 255)},
    {"whitesmoke", svgtiny_RGB(245, 245, 245)},
    {"yellow", svgtiny_RGB(255, 255, 0)},
    {"yellowgreen", svgtiny_RGB(154, 205, 50)},
};


const struct svgtiny_named_color *svgtiny_color_lookup(const char *s,
                                                       unsigned int len)
{
    struct svgtiny_named_color *result = NULL;
    char *lowerStr = strduplower2((const uint8_t *) s, len);
    int lo = 0;
    int hi = -1 + sizeof(sSortedColors) / sizeof(sSortedColors[0]);
    int mid = lo + (lo + hi) / 2;
    int cmp = -1;
    while (0 != (cmp = strcmp(lowerStr, sSortedColors[mid].name)) && lo < hi) {
        int delta = (hi - lo) / 2;
        if (delta == 0) {
            delta = 1;
        }
        if (cmp < 0) {
            hi -= delta;
        } else {
            lo += delta;
        }
        mid = (lo + hi) / 2;
    }
    if (0 == cmp || 0 == strcmp(lowerStr, sSortedColors[mid].name)) {
        result = &sSortedColors[mid];
    }
    free(lowerStr);
    return result;
}

/*
test() {
  const char *aliceblue = "AliceBlue";
  const struct svgtiny_named_color *aliceblueS = svgtiny_color_lookup(aliceblue,
(unsigned int)strlen(aliceblue));
  assert(aliceblueS); // first

  const char *yellowgreen = "yellowgreen";
  const struct svgtiny_named_color *yellowgreenS =
svgtiny_color_lookup(yellowgreen, (unsigned int)strlen(yellowgreen));
  assert(yellowgreenS); // last

  const char *a000 = "a000";
  const struct svgtiny_named_color *a000S = svgtiny_color_lookup(a000, (unsigned
int)strlen(a000));
  assert( ! a000S); // before first

  const char *zztop = "zztop";
  const struct svgtiny_named_color *zztopS = svgtiny_color_lookup(zztop,
(unsigned int)strlen(zztop));
  assert( ! zztopS);   // after last

}

 */
