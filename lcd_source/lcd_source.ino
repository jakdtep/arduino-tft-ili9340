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

#include "linux_boot_log.h"

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
static Adafruit_ILI9340 lcdObj = Adafruit_ILI9340(SPI_LCD_CS, SPI_LCD_DC, SPI_LCD_RST);
#else
/* in software SPI all lines are bitbanged in SW*/
static Adafruit_ILI9340 lcdObj = Adafruit_ILI9340(SPI_LCD_CS, SPI_LCD_DC, SPI_MOSI, SPI_CLOCK, SPI_LCD_RST, SPI_MISO);
#endif

static uint8_t curLcdOrientation = 0;

/*char height is multiple of 8 starting with 8 pixels when 1*/
#define BOOT_TEXT_SIZE	1

/*maximum no. lines in landscape with font size 8 pixels (320/8)*/
#define MAX_LINES_LANDSCAPE	40
/*maximum no. lines in portrait with font size 8 pixels (240/8)*/
#define MAX_LINES_PORTRAIT	30


/*This function fakes a progress by dots with fixed delay*/
void showFakeDotProgress(uint16_t count, uint16_t delayMs)
{
	int i;
	for(i=0; i<count; i++)
	{
		lcdObj.printf(".");
		delay(delayMs);
	}
}

void showFakeBootLog()
{
	int linei;
	uint8_t linesCount, logLines;
	lcdObj.fillScreen(ILI9340_BLACK);
	lcdObj.setCursor(0, 0);
	lcdObj.setTextColor(ILI9340_WHITE);
	lcdObj.setTextSize(BOOT_TEXT_SIZE);
	/*find no. of lines from orientation*/
	if(curLcdOrientation & 1)
		linesCount = (MAX_LINES_PORTRAIT/BOOT_TEXT_SIZE);
	else
		linesCount = (MAX_LINES_LANDSCAPE/BOOT_TEXT_SIZE);
	logLines =  sizeof(linuxBootLogStr)/LINUX_BOOT_LOG_LINE_WIDTH;

	lcdObj.printf("Waiting for Devices");
	showFakeDotProgress(6, 300);
	lcdObj.printf("\n");
	lcdObj.printf("Uncompressing Linux");
	showFakeDotProgress(50, 100);
	lcdObj.printf("\n");
	for(linei=0; linei<logLines; linei++)
	{
		if(!(linei % linesCount) && linei)
		{
			lcdObj.fillScreen(ILI9340_BLACK);
			lcdObj.setCursor(0, 0);
			delay(linei);
		}

		lcdObj.printf("%s\n", linuxBootLogStr[linei]);
		delay(linei%50);
	}

}

void setup()
{
	/*initialize serial port for debug prints*/
	Serial.begin(9600);
	/*initialize the lcd moduel*/
	Serial.printf("jak:> initializing LCD!\n");
	lcdObj.begin();
	for(int i=0; i<4; i++)
	{
		lcdObj.setRotation(i);
		curLcdOrientation = i;
		showFakeBootLog();
	}

}


void loop()
{
}
