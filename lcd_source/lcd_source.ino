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
*/

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9340.h"

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
Adafruit_ILI9340 lcdObj = Adafruit_ILI9340(SPI_LCD_CS, SPI_LCD_DC, SPI_LCD_RST);
#else
/* in software SPI all lines are bitbanged in SW*/
Adafruit_ILI9340 lcdObj = Adafruit_ILI9340(SPI_LCD_CS, SPI_LCD_DC, SPI_MOSI, SPI_CLOCK, SPI_LCD_RST, SPI_MISO);
#endif

void setup()
{
	/*initialize serial port for debug prints*/
	Serial.begin(9600);
	/*initialize the lcd moduel*/
	lcdObj.begin();
	lcdObj.fillScreen(ILI9340_BLACK);
}


void loop()
{
}
