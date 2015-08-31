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

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9340.h"

#include "disp_info_objects.h"
#include "bit_maps.h"

#define USE_HW_SPI

/*defines the SPI HW GPIOs for the lcd module*/
/*Can also work in SW SPI mode*/
#define SPI_CLOCK 	13
#define SPI_MISO 	12
#define SPI_MOSI 	11
#define SPI_LCD_CS 	10
#define SPI_LCD_DC 	9
#define SPI_LCD_RST	8

#ifdef USE_HW_SPI
/*in HW SPI other lines are hardware controlled. refer arduino pinout*/
static LcdDev lcdDevObj = LcdDev(SPI_LCD_CS, SPI_LCD_DC, SPI_LCD_RST,
				90, ILI9340_BLACK);
#else
/* in software SPI all lines are bitbanged in SW*/
static LcdDev lcdDevObj = LcdDev(SPI_LCD_CS, SPI_LCD_DC, SPI_MOSI, SPI_CLOCK, SPI_LCD_RST, SPI_MISO,
				90, ILI9340_BLACK);
#endif

static ProgressBar pgBar1;
static ProgressBar pgBar2;
static ProgressBar pgBar3;
static Icon	icon1;
static Icon	icon2;
static Icon	icon3;

void setup()
{
	/*initialize serial port for debug prints*/
	Serial.begin(9600);
	
	Serial.printf("jak:> clear LCD!\n");
	lcdDevObj.clearScreen();
	
	for(int i=270; i<360; i+=90)
	{
		lcdDevObj.rotateScreen(i);
		lcdDevObj.showFakeBootLog();
	}
	delay(1000);

	lcdDevObj.clearScreen();

	pgBar1.x = 0;
	pgBar1.y = 120;
	pgBar1.width = 320;
	pgBar1.height = 25;
	pgBar1.brdColor = ILI9340_BLUE;
	pgBar1.color = ILI9340_RED;
	pgBar1.bgColor = ILI9340_GREEN;

	createProgressBar(&lcdDevObj, &pgBar1);
	
	pgBar2.x = 2;
	pgBar2.y = 157;
	pgBar2.width = 250;
	pgBar2.height = 25;
	pgBar2.brdColor = ILI9340_BLUE;
	pgBar2.color = ILI9340_RED;
	pgBar2.bgColor = ILI9340_GREEN;

	createProgressBar(&lcdDevObj, &pgBar2);
	
	pgBar3.x = 2;
	pgBar3.y = 194;
	pgBar3.width = 250;
	pgBar3.height = 25;
	pgBar3.brdColor = ILI9340_YELLOW;
	pgBar3.color = ILI9340_BLUE;
	pgBar3.bgColor = ILI9340_RED;

	createProgressBar(&lcdDevObj, &pgBar3);

	icon1.x = 0;
	icon1.y = 0;
	icon1.width = heat32x32.width;
	icon1.height = heat32x32.height;
	icon1.rgb565Data = (const uint16_t*)heat32x32.pixel_data;
	icon1.brdColor = ILI9340_BLUE;	
	
	drawIcon(&lcdDevObj, &icon1);
	
	icon2.x = 80;
	icon2.y = 0;
	icon2.width = bulb32x32.width;
	icon2.height = bulb32x32.height;
	icon2.rgb565Data = (const uint16_t*)bulb32x32.pixel_data;
	icon2.brdColor = ILI9340_BLUE;	
	
	drawIcon(&lcdDevObj, &icon2);
	
	icon3.x = 160;
	icon3.y = 0;
	icon3.width = mic32x32.width;
	icon3.height = mic32x32.height;
	icon3.rgb565Data = (const uint16_t*)mic32x32.pixel_data;
	icon3.brdColor = ILI9340_BLUE;	
	
	drawIcon(&lcdDevObj, &icon3);
}


void loop()
{
	unsigned long time = micros();
	pgBar1.value = time%100;
	pgBar2.value = time%100;
	updateProgressBar(&lcdDevObj, &pgBar1);
	updateProgressBar(&lcdDevObj, &pgBar2);
	delay(50);
}
