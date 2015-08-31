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
				90, ILI9340_WHITE);
#else
/* in software SPI all lines are bitbanged in SW*/
static LcdDev lcdDevObj = LcdDev(SPI_LCD_CS, SPI_LCD_DC, SPI_MOSI, SPI_CLOCK, SPI_LCD_RST, SPI_MISO,
				90, ILI9340_WHITE);
#endif

static ProgressBar pgBarHeat;
static ProgressBar pgBarBulb;
static ProgressBar pgBarMic;
static Icon	iconHeat;
static Icon	iconBulb;
static Icon	iconMic;
static Icon	iconLogo;

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

	pgBarHeat.x = 2;
	pgBarHeat.y = 132;
	pgBarHeat.width = 276;
	pgBarHeat.height = 25;
	pgBarHeat.brdColor = ILI9340_GREEN;
	pgBarHeat.color = ILI9340_RED;
	pgBarHeat.bgColor = ILI9340_BLUE;

	createProgressBar(&lcdDevObj, &pgBarHeat);
	
	pgBarBulb.x = 2;
	pgBarBulb.y = 170;
	pgBarBulb.width = 276;
	pgBarBulb.height = 25;
	pgBarBulb.brdColor = ILI9340_GREEN;
	pgBarBulb.color = ILI9340_WHITE;
	pgBarBulb.bgColor = ILI9340_BLACK;

	createProgressBar(&lcdDevObj, &pgBarBulb);
	
	pgBarMic.x = 2;
	pgBarMic.y = 208;
	pgBarMic.width = 276;
	pgBarMic.height = 25;
	pgBarMic.brdColor = ILI9340_GREEN;
	pgBarMic.color = ILI9340_BLUE;
	pgBarMic.bgColor = ILI9340_RED;

	createProgressBar(&lcdDevObj, &pgBarMic);

	iconLogo.x = 0;
	iconLogo.y = 0;
	iconLogo.width = logo.width;
	iconLogo.height = logo.height;
	iconLogo.rgb565Data = (const uint16_t*)logo.pixel_data;
	iconLogo.brdColor = 0;	
	
	drawIcon(&lcdDevObj, &iconLogo);	
	
	iconHeat.x = 282;
	iconHeat.y = 126;
	iconHeat.width = heat32x32.width;
	iconHeat.height = heat32x32.height;
	iconHeat.rgb565Data = (const uint16_t*)heat32x32.pixel_data;
	iconHeat.brdColor = 0;	
	
	drawIcon(&lcdDevObj, &iconHeat);
	
	iconBulb.x = 282;
	iconBulb.y = 164;
	iconBulb.width = bulb32x32.width;
	iconBulb.height = bulb32x32.height;
	iconBulb.rgb565Data = (const uint16_t*)bulb32x32.pixel_data;
	iconBulb.brdColor = 0;	
	
	drawIcon(&lcdDevObj, &iconBulb);
	
	iconMic.x = 282;
	iconMic.y = 202;
	iconMic.width = mic32x32.width;
	iconMic.height = mic32x32.height;
	iconMic.rgb565Data = (const uint16_t*)mic32x32.pixel_data;
	iconMic.brdColor = 0;	
	
	drawIcon(&lcdDevObj, &iconMic);
}


void loop()
{
	unsigned long time = micros();
	pgBarHeat.value = time%100;
	pgBarBulb.value = time%100;
	pgBarMic.value = time%100;
	updateProgressBar(&lcdDevObj, &pgBarHeat);
	updateProgressBar(&lcdDevObj, &pgBarBulb);
	updateProgressBar(&lcdDevObj, &pgBarMic);
	delay(50);
}
