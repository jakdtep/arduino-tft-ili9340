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

#define ICON_BRD_THICK	3

/*wrapper object for LCD. stores current information.
 create the object with Adafruit LCD object (hwSPI or swSPI) and initial parameters
 This object is supposed to be global in main program*/
typedef class LcdDev: public Adafruit_ILI9340{
public:
	/*Software SPI constructor*/
	LcdDev(uint8_t CS, uint8_t RS, uint8_t MOSI, uint8_t SCLK,
		uint8_t RST, uint8_t MISO,
		uint16_t orientation, uint16_t bgColor);
	/*Hardware SPI constructor*/
	LcdDev(uint8_t CS, uint8_t RS, uint8_t RST, uint16_t orientation, uint16_t bgColor);

	int8_t	curOrientation;
	uint8_t curWidth;
	uint8_t curHeight;
	uint16_t curBgColor;

	int8_t clearScreen();
	int8_t rotateScreen(int16_t);
}LcdDev;


/*progrss bar object*/
typedef struct progress
{
	uint16_t x,y;/*top left corner*/
	uint16_t width, height;
	uint16_t vertical;
	uint8_t value;
	uint16_t color, bgColor, brdColor;
}ProgressBar;

/*icon object*/
typedef struct icon
{
	uint16_t x,y;/*top left corner*/
	/*following dimensions exclude borders*/
	uint16_t width, height;
	uint16_t vertical;
	/*pixel data in rgb565 format*/
	const uint16_t *rgb565Data;
	/*if bgColor is non zero it is filed
	  instead of transparency*/
	uint16_t  bgColor;
	/*if brdColor is non zero border will be drawn*/
        uint16_t  brdColor;
}Icon;


int8_t createProgressBar(LcdDev *lcd, ProgressBar *pBar);
int8_t updateProgressBar(LcdDev *lcd, ProgressBar *pBar);
int8_t deleteProgressBar(LcdDev *lcd, ProgressBar *pBar);

int8_t drawIcon(LcdDev *lcd, Icon *pIcon);
#endif
