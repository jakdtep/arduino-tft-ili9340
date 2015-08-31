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

#include "linux_boot_log.h"
#include "disp_info_objects.h"

/*Software SPI constructor*/
LcdDev::LcdDev(uint8_t CS, uint8_t RS, uint8_t MOSI, uint8_t SCLK,
       uint8_t RST, uint8_t MISO,
       uint16_t orientation, uint16_t bgColor)
	:Adafruit_ILI9340(CS, RS, MOSI, SCLK, RST, MISO)
{
	curOrientation = orientation;
	curBgColor = bgColor;
	
	begin();
	rotateScreen(curOrientation);
}

/*Hardware SPI constructor*/
LcdDev::LcdDev(uint8_t CS, uint8_t RS, uint8_t RST, uint16_t orientation, uint16_t bgColor)
	:Adafruit_ILI9340(CS, RS, RST)
{
	curBgColor = bgColor;
	
	begin();
	rotateScreen(orientation);
}

int8_t LcdDev::rotateScreen(int16_t degree)
{
	switch(degree)
	{
		case 0:
			setRotation(0);
			curOrientation = 0;
			curWidth = ILI9340_TFTWIDTH;
			curHeight = ILI9340_TFTHEIGHT;
			break;
		case 90:
			setRotation(1);
			curOrientation = 90;
			curHeight = ILI9340_TFTWIDTH;
			curWidth = ILI9340_TFTHEIGHT;
			break;
		case 180:
			setRotation(2);
			curOrientation = 180;
			curWidth = ILI9340_TFTWIDTH;
			curHeight = ILI9340_TFTHEIGHT;
			break;
		case 270:
			setRotation(3);
			curOrientation = 270;
			curHeight = ILI9340_TFTWIDTH;
			curWidth = ILI9340_TFTHEIGHT;
			break;
		default:
			setRotation(0);
			curOrientation = 0;
			curWidth = ILI9340_TFTWIDTH;
			curHeight = ILI9340_TFTHEIGHT;
			break;
	}
	return DISP_SUCCESS;
}

int8_t LcdDev::clearScreen()
{
	fillScreen(curBgColor);
	return DISP_SUCCESS;
}

/*This function fakes a progress by dots with fixed delay*/
void LcdDev::showFakeDotProgress(uint16_t count, uint16_t delayMs)
{
	int i;
	for(i=0; i<count; i++)
	{
		printf(".");
		delay(delayMs);
	}
}

void LcdDev::showFakeBootLog()
{
	int linei;
	uint8_t linesCount, logLines;
	fillScreen(ILI9340_BLACK);
	setCursor(0, 0);
	setTextColor(ILI9340_WHITE);
	setTextSize(BOOT_TEXT_SIZE);
	/*find no. of lines from orientation*/
	if(curOrientation == 90 || curOrientation == 90) 
		linesCount = (MAX_LINES_PORTRAIT/BOOT_TEXT_SIZE);
	else
		linesCount = (MAX_LINES_LANDSCAPE/BOOT_TEXT_SIZE);
	logLines =  sizeof(linuxBootLogStr)/LINUX_BOOT_LOG_LINE_WIDTH;

	printf("Waiting for Devices");
	showFakeDotProgress(6, 300);
	printf("\n");
	printf("Uncompressing Linux");
	showFakeDotProgress(50, 100);
	printf("\n");
	for(linei=0; linei<logLines; linei++)
	{
		if(!(linei % linesCount) && linei)
		{
			fillScreen(ILI9340_BLACK);
			setCursor(0, 0);
			delay(linei);
		}

		printf("%s\n", linuxBootLogStr[linei]);
		delay(linei%50);
	}
}

int8_t createProgressBar(LcdDev *devLcd, ProgressBar *pBar)
{
	uint16_t width, height, x, y;
	width = pBar->width;
	height = pBar->height;
	x = pBar->x;
	y = pBar->y;

	if(x > devLcd->curWidth || y > devLcd->curHeight)
		return DISP_ERR;

	/*correct to the limiting values if needed*/
	if(width < PBAR_MIN_WIDTH)
		width = PBAR_MIN_WIDTH;

	if(x+width > devLcd->curWidth)
		width = devLcd->curWidth - x;

	if(height < PBAR_MIN_HEIGHT)
		height = PBAR_MIN_HEIGHT;

	if(y+height > devLcd->curHeight)
		height = devLcd->curHeight - y;
	
	/*draw the borders with respective thickness*/
	for(int i=0; i<PBAR_BRD_THICK; i++)
		devLcd->drawFastHLine(x, y+i, width, pBar->brdColor);
	for(int i=0; i<PBAR_BRD_THICK; i++)
		devLcd->drawFastHLine(x, y+height+i-PBAR_BRD_THICK, width, pBar->brdColor);
	for(int i=0; i<PBAR_BRD_THICK; i++)
		devLcd->drawFastVLine(x+i, y, height, pBar->brdColor);
	for(int i=0; i<PBAR_BRD_THICK; i++)
		devLcd->drawFastVLine(x+width+i-PBAR_BRD_THICK, y, height, pBar->brdColor);
	/*fill the background*/
	devLcd->fillRect(x+PBAR_BRD_THICK, y+PBAR_BRD_THICK, width-PBAR_BRD_THICK*2, height-PBAR_BRD_THICK*2, pBar->bgColor);

	return DISP_SUCCESS;
}

int8_t updateProgressBar(LcdDev *devLcd, ProgressBar *pBar)
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
	devLcd->fillRect(x+PBAR_BRD_THICK+1, y+PBAR_BRD_THICK+1, 
		progWidth-(PBAR_BRD_THICK*2)-1, height-(PBAR_BRD_THICK+1)*2, pBar->color);
	
	/*fill the background*/
	devLcd->fillRect(x+PBAR_BRD_THICK+1+progWidth, y+PBAR_BRD_THICK, 
		width-progWidth-PBAR_BRD_THICK*2, height-PBAR_BRD_THICK*2, 
		pBar->bgColor);
	
	return DISP_SUCCESS;
}
int8_t deleteProgressBar(LcdDev *devLcd, ProgressBar *pBar)
{
	return DISP_SUCCESS;
}

int8_t drawIcon(LcdDev *devLcd, Icon *pIcon)
{	
	uint16_t width, height, x, y;
	uint16_t bmX, bmY;
	width = pIcon->width;
	height = pIcon->height;
	x = pIcon->x;
	y = pIcon->y;

	if(x > devLcd->curWidth || y > devLcd->curHeight)
		return DISP_ERR;

	/*correct to the limiting values if needed*/
	if(width < PBAR_MIN_WIDTH)
		width = PBAR_MIN_WIDTH;
	
	if(x+width > devLcd->curWidth)
		width = devLcd->curWidth - x;

	if(height < PBAR_MIN_HEIGHT)
		height = PBAR_MIN_HEIGHT;

	if(y+height > devLcd->curHeight)
		height = devLcd->curHeight - y;
	
	bmX = x;
	bmY = y;

	if(pIcon->brdColor)
	{
		/*draw the borders with respective thickness*/
		for(int i=0; i<ICON_BRD_THICK; i++)
			devLcd->drawFastHLine(x, y+i, width+ICON_BRD_THICK, pIcon->brdColor);
		for(int i=0; i<ICON_BRD_THICK; i++)
			devLcd->drawFastHLine(x, y+height+i+ICON_BRD_THICK, width+ICON_BRD_THICK,
					pIcon->brdColor);
		for(int i=0; i<ICON_BRD_THICK; i++)
			devLcd->drawFastVLine(x+i, y, height+ICON_BRD_THICK, pIcon->brdColor);
		for(int i=0; i<ICON_BRD_THICK; i++)
			devLcd->drawFastVLine(x+width+i+ICON_BRD_THICK, y, height+ICON_BRD_THICK*2, 
					pIcon->brdColor);
		bmX = x + ICON_BRD_THICK;
		bmY = y + ICON_BRD_THICK;
	}

	/*draw the icon bitmap*/
	devLcd->setAddrWindow(bmX, bmY,
		       	bmX+width-1, bmY+height);

	for(int i=0; i<height; i++)
		for(int j=0; j<width; j++)
			devLcd->pushColor(pIcon->rgb565Data[i*(width)+j]);

	return DISP_SUCCESS;
}

