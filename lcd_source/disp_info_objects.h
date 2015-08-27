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

#ifndef DISP_INFO_OBJS_H
#define DISP_INFO_OBJS_H

#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9340.h"

#define DISP_ERR	-1
#define DISP_SUCCESS	0

/*minimum width and height to draw borders*/
#define PBAR_BRD_THICK	3
#define PBAR_MIN_WIDTH	(PBAR_BRD_THICK*5)
#define PBAR_MIN_HEIGHT	(PBAR_BRD_THICK*5)


/*progrss bar object*/
typedef struct progress
{
	uint16_t x,y;/*top left corner*/
	uint16_t width, height;
	uint16_t vertical;
	uint8_t value;
	uint16_t color, bgColor, brdColor;
}ProgressBar;


uint8_t createProgressBar(Adafruit_ILI9340 *lcd, ProgressBar *pBar);
uint8_t updateProgressBar(Adafruit_ILI9340 *lcd, ProgressBar *pBar);
uint8_t deleteProgressBar(Adafruit_ILI9340 *lcd, ProgressBar *pBar);

#endif
