/* GNU Public License
This program is free software: you can redistribute it and/or modify
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

#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9340.h"

#include "disp_info_objects.h"

uint8_t createProgressBar(Adafruit_ILI9340 *lcd, ProgressBar *pBar)
{
	uint16_t width, height, x, y;
	width = pBar->width;
	height = pBar->height;
	x = pBar->x;
	y = pBar->y;

	if(x > ILI9340_TFTWIDTH || y > ILI9340_TFTHEIGHT)
		return DISP_ERR;

	/*correct to the limiting values if needed*/
	if(width < PBAR_MIN_WIDTH)
		width = PBAR_MIN_WIDTH;
	
	if(x+width > ILI9340_TFTWIDTH)
		width = ILI9340_TFTWIDTH - x;

	if(height < PBAR_MIN_HEIGHT)
		height = PBAR_MIN_HEIGHT;

	if(y+height > ILI9340_TFTHEIGHT)
		height = ILI9340_TFTHEIGHT - y;
	
	/*draw the borders with respective thickness*/
	for(int i=0; i<PBAR_BRD_THICK; i++)
		lcd->drawFastHLine(x, y+i, width, pBar->brdColor);
	for(int i=0; i<PBAR_BRD_THICK; i++)
		lcd->drawFastHLine(x, y+height+i-PBAR_BRD_THICK, width, pBar->brdColor);
	for(int i=0; i<PBAR_BRD_THICK; i++)
		lcd->drawFastVLine(x+i, y, height, pBar->brdColor);
	for(int i=0; i<PBAR_BRD_THICK; i++)
		lcd->drawFastVLine(x+width+i-PBAR_BRD_THICK, y, height, pBar->brdColor);
	/*fill the background*/
	lcd->fillRect(x+PBAR_BRD_THICK, y+PBAR_BRD_THICK, width-PBAR_BRD_THICK*2, height-PBAR_BRD_THICK*2, pBar->bgColor);

	return DISP_SUCCESS;
}
uint8_t updateProgressBar(Adafruit_ILI9340 *lcd, ProgressBar *pBar)
{
	uint8_t val = pBar->value;
	uint16_t width, height, x, y;
	uint16_t progWidth = 0;
	width = pBar->width;
	height = pBar->height;
	x = pBar->x;
	y = pBar->y;
	
	if(val > 100)
		val = 100;

	/*calculate how much to fill*/
	progWidth = (uint16_t)((float)width*val/100.0);

	/*fill the progress*/
	lcd->fillRect(x+PBAR_BRD_THICK+1, y+PBAR_BRD_THICK+1, 
		progWidth-(PBAR_BRD_THICK*2)-1, height-(PBAR_BRD_THICK+1)*2, pBar->color);
	
	/*fill the background*/
	lcd->fillRect(x+PBAR_BRD_THICK+1+progWidth, y+PBAR_BRD_THICK, 
		width-progWidth-PBAR_BRD_THICK*2, height-PBAR_BRD_THICK*2, 
		pBar->bgColor);
	
	return DISP_SUCCESS;
}
uint8_t deleteProgressBar(Adafruit_ILI9340 *lcd, ProgressBar *pBar)
{
}
