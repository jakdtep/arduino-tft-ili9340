# arduino-tft-ili9340
Interfacing Arduino with ILI9340 2.2" TFT for a info display

This project uses ILI9340 SPI Adafruit LCD module with SD card.
This project uses arduino Adafruit GFX and ILI9340 libraries to drive LCD
Development is done with teensy 3.1 arduino. Hardware SPI is used to communicate to LCD
arduino-1.6.4/hardware/teensy/avr/libraries/Adafruit_ILI9340/examples/graphicstest is used to test the LCD.
On teensy 3.1 digital pin numbers used in the above code is same for software bitbanging SPI and hardware SPI. No rewiring required. Module also works with 3.3V from teensy. LED pin should be connected to VCC to get the back light running.
SW or HW SPI can be selected by choosing respective class construcor. 
SCLK, MOSI & MISO are switched between HW and SW for communication depending on which mode is selected. Other lines DC, CS, and RST are software controlled.
SW SPI is terribly slow compared to HW SPI.
Even with Teensy running at 96MHz a full screen fill is visually noticeable.
Teensy MK20 family reference manual is available below
http://cache.freescale.com/files/32bit/doc/ref_manual/K20P121M100SF2RM.pdf

ILI9340 reference manual is available below
http://www.displaytech-us.com/sites/default/files/driver-ic-data-sheet/Ilitek-ILI9340.pdf

At first display is initilized with .begin() member function. This initializes gpios DC, CS, RST and initializes HW/SW SPI using arduino SPI class It is defined in avr/cores/teensy/HardwareSerial.h
"class HardwareSerial : public Stream". This initializes digital pins, baud rate and SPI rx, tx FIFO buffers.
This function then initializes the lcd module by sending various set of commands and their parameters through SPI.

The class Adafruit_ILI9340 is inherited from Adafruit_GFX class

When the lcd initialization is completed, the region to draw can be selcted using setAddrWindow(). This function follows commands described in lcd reference manual.
Following is the sequence
CASET->params->PASET->params->RAMWR
After these commands lcd expects sequential (18bit max, we send 16bit) bitmap data for the region defined above.
CASET -> column set (X coordinates of region)
PASET -> page set (Y coordinates of the region)

pushColor(pixel) can be used after this state to sequentially send region data pixel by pixel. This API doesnot send any commands but only data.

Other operations supported by lcd module can be found in reference manual. 
