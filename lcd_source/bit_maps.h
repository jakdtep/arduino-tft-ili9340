/*This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Joseph Andly Koola
josephandly@gmail.com
*/
#ifndef BIT_MAPS_H
#define BIT_MAPS_H

/* GIMP RGB565 C-Source image dump (Bulb32x32) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[32 * 32 * 2 + 1];
} bulb32x32 = {
  32, 32, 2,
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\40\0e)IJ\252R\252RIJe)\40"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0A\10\212R0\204\363\234\327\2758\3068\306\327\275\363\234"
  "0\204\212RA\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\4!\20\204\226\265]\357\377\377\377\377\337\377\337\377"
  "\377\377\377\377]\357\266\2650\204$!\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0E)q\214\272\326\377\377\377\377\276\367\337"
  "\377\337\377\337\377\337\377\276\367\337\377\377\377\373\336q\214E)\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\202\20Q\214\34\347"
  "\377\377\377\377\236\367\276\367\276\367\276\367\276\367\276\367\276\367"
  "\236\367\337\377\377\377<\347Q\214\242\20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0mk\272\326\337\377\337\377\236\367\236\367\236\367"
  "\276\367\276\367\276\367\276\367\236\367\236\367\236\367\337\377\276\367"
  "\333\336mk\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\4!4\245\276"
  "\367\337\377\337\377]\357}\357\236\367\236\367\276\367\236\367\236\367\236"
  "\367}\357]\357\276\367\276\367\276\3674\245$!\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\212R\373\336\236\367\276\367}\357]\357}\357\236\367"
  "\236\367\236\367\236\367\236\367}\357}\357]\357}\357\276\367\236\367\373"
  "\336\252R\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\357{\276\367\236"
  "\367\236\367<\347]\357]\357}\357}\357\236\367\236\367}\357}\357]\357]\357"
  "\373\336\236\367}\357\276\367\357{\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\40\0\222\224\276\367}\357}\357\333\336\34\347<\347]\357]\357}\357"
  "]\357]\357]\357<\347\34\347\333\336}\357]\357\276\367\222\224\40\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0A\10\323\234\276\367]\357]\357\333\336"
  "\34\347<\347<\347<\347<\347]\357<\347<\347\34\347\34\347\333\336<\347<\347"
  "}\357\323\234A\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\222\224\236"
  "\367<\347<\347\333\336\34\347\34\347\34\347\34\347<\347<\347\34\347\34\347"
  "\34\347\34\347\333\336\34\347\34\347}\357\262\224\40\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\317{\236\367\373\336\34\347\333\336\34\347\232"
  "\326\272\326Y\316<\347\34\347y\316\272\326\232\326\34\347\272\326\373\336"
  "\373\336]\357\357{\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0IJ\333"
  "\336\333\336\333\336\272\326\373\336\226\265]\357Y\316\34\347\34\347Y\316"
  "]\357\226\265\373\336\272\326\333\336\272\326\333\336IJ\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\242\20""4\245\373\336\272\326\272\326\272"
  "\326Y\316\232\3268\306\34\347\34\3478\306\232\3268\306\232\326y\316\232\326"
  "\333\336U\255\303\30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\313Z\232\326y\316y\316y\316\333\336\226\2658\306\333\336\333\3368\306\226"
  "\265\333\336y\316Y\316Y\316\232\326\353Z\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\40\0\20\204\232\3268\3068\306Y\316U\255\272\326"
  "u\255\226\265\272\326U\255Y\316\30\306\30\306y\3160\204\40\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0a\10""0\204\30\306\367\275"
  "\367\275\30\306U\255u\255\226\265U\255\30\306\367\275\327\275\30\306Q\214"
  "\202\20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0a\10""0\204\266\265\266\265\327\275\262\224\226\265\327\275\222\224\327"
  "\275\226\265\266\2650\204a\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0E)\262\2248\3068\306\357{\367\275\327\275"
  "\317{\266\265\30\306\262\224E)\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0Mk\367\275\272\326\317{\24\245"
  "\323\234mk\226\265\327\275mk\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\2061U\255\272\326\323\234\222"
  "\224Q\2140\204U\255u\255\2461\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\242\20\24\245\333\3360\204\262"
  "\224Q\214\256sU\2554\245\303\30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0A\10\323\234\272\326mkQ\214"
  "\357{,cu\255\24\245A\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0Q\2148\306Mk\20\204\317{\14c\226"
  "\265\262\224\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0$!Mk\3079IJiJ\3079Mk\4!\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\3079y\316\236\367Y\316\216s\256sQ\214\2061\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\242\20\222\224u\255\262\224\353Z\317{\262\224\4!\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\10By\316}\357y\316\256sMk\20\204\4!\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\40\0\256"
  "sU\255\24\245Mk\20\204q\214A\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\303\20\10"
  "B\4!\242\20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
};

/* GIMP RGB565 C-Source image dump (mic32x32) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[32 * 32 * 2 + 1];
} mic32x32 = {
  32, 32, 2,
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\202\20\202\20\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\2461r\214\266\265\327\275\262\224(B\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\3479\24\235u\255\327\275\367\275\226\265U\255\252J\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\243\20\256sq\2145\245\367\275\266\265\24\245\222\224\357"
  "{%!\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0f)\317s\20|\363\234\266\265\327\275\323\224\20|\357{\10"
  ":\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\206)\14[mkQ\204u\255U\255q\214\256sMc(:\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\3071IB\354Z0\2044\245\24\245\360{\14[\252J)B\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\3071\3509iJ"
  "\317s\363\234\323\234MkiJ)B\10:\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\2471\3071IB\256s\24\245\24"
  "\235Mc\10BIB\3509\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\206)\206)\3509,cq\214Q\214\313Z\3479(B\247"
  "1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\303\30\4\31\202\20\10:(BMc\262\224U\255U\255\262\224,ciJ\3479\202\10"
  "\343\30\343\30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\20610|\262\224\256k\312R3\235\271\316\377\377\377\377\235\357\363"
  "\224,c\216k\317s\323\224\3479\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0A\10\4!\4!iJ\211Jp\204\225\255\272\326\272\326X\3060"
  "\204\313RHB\343\30\206)a\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\343\30\343\30\211Jmkq\214U\245\367\275\367\275\225"
  "\255\363\224\316s\312R\343\30e)\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0$!e)\353Zmk\363\2248\306<\347<\3478\306\322"
  "\224\215k\353ZE!\3061\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0E!\3071,c\312R\322\214y\306\377\377\377\3778\306\17|"
  "HBiJ\2461\3071\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0E)\3071\13[\252Jq\204\367\275}\357}\357\326\265\316s(BHB\246"
  "1\3079\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0e)$!(B\353Z\357{\262\2244\2454\245\363\234Q\204LcHB\303\30\3479\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0e)$!"
  "\211J\215k\323\224\367\275\232\316\232\316\30\276U\245\357{\312R\343\30\347"
  "9\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "e)\343\30iJ\357{4\245X\306\373\336\373\336y\316\226\255P\204\312Ra\10\7:"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\4!\2061\343\30\316sT\245Y\306\373\336\373\336\231\316\266\2550|e)\343\30"
  "\206)\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\353Z\0\0\2461q\214\367\265\272\316\272\316\27\276\322\224(B\0\0"
  "iJA\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\3479E)\0\0a\10\211J\356s\357{\312R\302\20\0\0\242\20\252R\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\353Z\2061\0\0\0\0\0\0\0\0\0\0\0\0\343\30mk\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\10"
  "B\256s(B\303\30\302\20\3079Mc\212R\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0D!\256"
  "s\20|\2461\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0a\10E!(B0\204\266\265IBe)\201\10"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\2061Mcq\204u\245Y\306\266\265\327\2758\306\266\265\322\224"
  "\256s\3061\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\353R\215k\316s0\204\323\224\225\2558\306X\306\266\265\23\235"
  "q\204\357s\216k\14[\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0A\10\4!\4!E)\3071\10:(B(B\10B\10:\3079\3061e)\4!\3\31A\10\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0",
};

/* GIMP RGB565 C-Source image dump (Hot32x32) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[32 * 32 * 2 + 1];
} heat32x32 = {
  32, 32, 2,
  "\0\0\0\0\0\0\0\0TdTd\0\0\0\0\353\373\0\0\0\0\0\0\13\374\0\0\0\0\0\0\13\374"
  "\0\0\0\0\0\0\13\374\0\0\0\0\0\0\13\374\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0""3d\377\367\377\3774\\\0\0\0\0\0\0\0\0\13\374\0\0\0\0\0\0\13\374\0"
  "\0\0\0\0\0\13\374\0\0\0\0\0\0\13\374\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0""3d\377\357?\247_\257\377\3674\\\0\0\0\0\0\0\353\373\0\0\0\0\0\0\13"
  "\374\0\0\0\0\0\0\13\374\0\0\0\0\0\0\13\374\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0Td\337\357\277\236\0\360\0\370\372\305\377\3674\\\0\0\0\0\0\0\13\374"
  "\0\0\0\0\0\0\13\374\0\0\0\0\0\0\13\374\0\0\0\0\0\0\13\374\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0Td\337\357\237\226\0\340\40\350b\370o\203\377\3674\\\0\0"
  "\0\0\353\373\0\0\0\0\0\0\13\374\0\0\0\0\0\0\13\374\0\0\0\0\0\0\13\374\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0Td^\226\377\226\0\340A\350b\370\373\305\377"
  "\3674\\\0\0\0\0\0\0\0\0\13\374\0\0\0\0\0\0\13\374\0\0\0\0\0\0\13\374\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0Tl~\226\362K\0\340!\350A\370\373"
  "\305\377\3674\\\0\0\0\0\0\0\353\373\0\0\0\0\0\0\13\374\0\0\0\0\0\0\13\374"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0tl~\226\37\227\0\340!\350"
  "a\370tT\377\3774\\\0\0\0\0\0\0\13\374\0\0\0\0\0\0\13\374\0\0\0\0\0\0\13\374"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0Td~\226\37\227\0\340!\360"
  "A\370\277\257\377\3674\\\0\0\0\0\353\373\0\0\0\0\0\0\13\374\0\0\0\0\0\0\13"
  "\374\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0U\\\177\226\363K"
  "\0\340\40\350!\370\277\257\377\3774\\\0\0\0\0\0\0\0\0\13\374\0\0\0\0\0\0"
  "\13\374\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0VT\177"
  "\226\37\227\0\340\40\350A\370sT\377\3674\\\0\0\0\0\0\0\353\373\0\0\0\0\0"
  "\0\13\374\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\253\240"
  "(VT_\216\37\227\0\340!\360A\370\277\257\377\3674\\\0\0\0\0\0\0\13\374\0\0"
  "\0\0\0\0\13\374\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\243\374"
  "\5\375\240\3335T\177\226\363K\0\340\40\350A\370\372\305\377\367T\\\0\0\0"
  "\0\353\373\0\0\0\0\0\0\13\374\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\300('\375\330\3774\377+\376\25T_\226\37\227\0\340!\350b\370o\203\377"
  "\3674\\\0\0\0\0\0\0\0\0\13\374\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\300(\340qi\375\20\3774\377u\377\15\377\25T_\216\37\227\0\340A\350"
  "b\370\373\305\377\3674\\\0\0\0\0\0\0\353\373\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0A\273\243\374\6\375h\375\220\376G\376'\376\213\376G\376f\376"
  "6T\177\226\363K\0\340!\350A\370\373\305\377\3674\\\0\0\0\0\0\0\13\374\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0@I\345\374T\377\23\377\320\376'\376'\376"
  "'\376'\376'\376F\3766T\177\226\37\227\0\340!\350a\370tT\377\3774\\\0\0\0"
  "\0\353\373\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\354L\376)\376\10\376"
  "\7\376\7\376\7\376\7\376\7\376\7\376%\3766T_\216\37\227\0\340!\360A\370\277"
  "\257\377\3674\\\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\354$\375"
  "\346\375\347\375\347\375\347\375\347\375\347\375\347\375\347\375\346\375"
  "\5\3766T\177\226\363K\0\340\40\350!\370\277\257\377\3674\\\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\200\40B\364h\375L\376\306\375\306\375\306\375\306"
  "\375\306\375\306\375\306\375\306\375\306\375\306\375\344\3756T\177\226\37"
  "\227\0\340\40\350!\370\277\257\377\3674\\\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\202\374&\375M\376\12\376\246\375\246\375\246\375\246\375\246\375\246\375"
  "\246\375\246\375\246\375\246\375\245\375\244\3756T_\216\377\226\0\340\40"
  "\350!\370\277\257\377\367\23\\3d4d*2\0\0\0\0\0\0\0\0\200\40B\364%\375\205"
  "\375\206\375\206\375\206\375\206\375\206\375\206\375\206\375\206\375\206"
  "\375\206\375\205\375\205\375\203\3756T_\216\377\226\0\340\0\350A\370\233"
  "\356\377\367\377\367\277\347x\225\362[\0\0\0\0\0\0\0\0\0\0\2\354\4\375e\375"
  "e\375e\375e\375e\375e\375e\375e\375e\375e\375e\375e\375e\375\1\375VT_\216"
  "\377\226\0\340\0\350A\370\33\316\337\277\277\317\377\367x\225*2\0\0\0\0\0"
  "\0\0\0\"\354F\375E\375E\375E\375E\375E\375E\375E\375E\375E\375E\375E\375"
  "E\375E\375E\375\300\333VT_\216\377\337\0\340!\350\202\370\202\370\361\333"
  "_\267\237\337Td\0\0\0\0\0\0@I\243\374%\375$\375$\375$\375$\375$\375$\375"
  "$\375$\375$\375$\375$\375$\375$\375%\375\242\374\200\40""5\\\277\317\37\247"
  "\0\340b\350\303\360\202\370\37\247\177\3174d\0\0\0\0\0\0B\273\203\374\243"
  "\374\243\374\344\374\4\375\4\375\4\375\4\375\4\375\4\375\4\375\4\375\4\375"
  "\344\374\243\374\243\374\202\374\300\232\226d\377\256\236\246\0\330\0\330"
  "a\350A\370\377\236\337\266Tl\0\0\0\0\0\0\0\0\0\0\300(\1r\243\374\343\374"
  "\343\374\343\374\343\374\343\374\343\374\343\374\343\374\343\374\243\374"
  "\1r\300(\0\0\0\0U\\=\236\277\236\355\272\0\330\0\340O\303\237\236=\236Tl"
  "\0\0\0\0\0\0\0\0\0\0\0\0\300(\203\374\303\374\243\374\243\374\303\374\303"
  "\374\303\374\243\374\243\374\303\374\203\374\300(\0\0\0\0\0\0J2\367|^\236"
  "~\226\277\226\277\226~\226^\236\367|J:\0\0\0\0\0\0\0\0\0\0\0\0\0\0\202\374"
  "\203\374B\354\"\354\203\374\243\374\203\374b\303B\364\203\374\202\374\0\0"
  "\0\0\0\0\0\0\0\0\362c\327|\334\225\35\226\35\226\334\225\327|\362c\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0B\273@I\0\0\0\0\"\354\202\374\3000\0\0\0\0@IB\273"
  "\0\0\0\0\0\0\0\0\0\0\0\0J2TltltlTlJ2\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0",
};

#endif