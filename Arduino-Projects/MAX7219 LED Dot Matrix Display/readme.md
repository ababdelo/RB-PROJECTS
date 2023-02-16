<h3 align="center"> Interfacing MAX7219 LED Dot Matrix Display with Arduino </h3>
<br>
<p align="center"> <img src="https://www.circuitgeeks.com/wp-content/uploads/2021/09/MAX7219-LED-Matrix-Display-with-Arduino.jpg"> </p>

<font size="4">
Dot matrix displays are something that all Arduino enthusiasts come across at some point. These displays are so popular that almost all modern outdoor LED displays use them to display characters, symbols, and images.

When it comes to controlling dot-matrix displays, there is hardly a better option than the MAX7219. It can easily control a single dot matrix and, for larger projects, it can be chained together to control two or more dot matrices.

All in all, they are a lot of fun and quite useful as well, so let’s get started.
</font>
<font size="5" color="white">
MAX7219 Module Overview
</font>
<font size="4">
There are several MAX7219 breakout boards available, two of which are more popular: the generic module and the FC-16 module.
<p align="center"> <img src="https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/MAX7219-Module-Variants.jpg" /> </p>

A typical MAX7219 module includes an 8×8 dot matrix display and a MAX7219 LED display driver. Let’s get familiar with them.
</font>
<font size="5" color="white">
The Dot Matrix Display
</font>
<p align="center"> <img src="https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/8x8-Dot-Matrix-Display.jpg" /> </p>

<font size="4">

An 8×8 dot matrix display typically has 16 pins, 8 for each row and 8 for each column. All rows and columns are wired together in order to reduce the number of pins. If this were not the case, an 8×8 dot matrix display would require 65 pins, one for each LED and one for a common anode or common cathode connector. By connecting rows and columns, only 16 pins are needed to control the entire matrix. This technique of controlling a large number of LEDs with fewer pins is referred to as **Multiplexing**.

<p align="center"> <img src="https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/8x8-Dot-Matrix-Internal-Structure-Multiplexing.png"/> </p>

In this technique, each column is activated for a very short time, and at the same time, the LEDs on that column are lit by addressing the corresponding row. As a result, no more than eight LEDs are lit at the same time. The columns are switched so fast (hundreds or thousands of times per second) that the human eye perceives the display as fully lit.

<p align="center"> <img src="https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/LED-Matrix-Display-Working-Animation-Persistence-of-Vision.gif"> </p>

</font>
<font size="5" color="white">
MAX7219 Chip
</font>
<font size="4">
The only problem with multiplexing is that you have to refresh the display all the time to keep the image stable.
<br>
Then there’s the MAX7219 Chip, which handles all of the control and refresh work for you. All you have to do is send it serial commands through the 4-pin SPI interface, and it will take care of the rest.
</font>
<br>
<br>
<p align="center"> <img src="https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/MAX7219-IC.jpg"/> </p>

<font size="4">
It can fully control 64 individual LEDs while keeping their brightness constant. Once the microcontroller has updated the display, the MAX7219 handles the work of refreshing the display at 800 Hz. This frees up the microcontroller to do other important things.

The MAX7219 has a power saving mode in which the display can be turned off to save power. It also turns off the LEDs during startup, preventing wacky displays for the first few seconds of operation.

The MAX7219 communicates via the SPI interface, so it only needs 3 data pins to connect to a microcontroller. In addition, we can daisy-chain multiple modules together for a larger display using the same 3 wires.

</font>
<br>
<font size="5" color="white">
Setting Maximum Current and Brightness
</font>
<br>
<br>
<font size="4">
The MAX7219 allows you to adjust the brightness of the display using either hardware or software (or both).

<br>

**At the Hardware Level**

<p align="center"> <img src="https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/MAX7219-Rset-Resistance-for-Setting-Brightness.jpg"> </p>

This resistor controls the maximum current supplied to the LEDs and, hence, the overall brightness of the display.

The table below shows the resistor values you should use based on the voltage and forward current of your LED matrix. A 2V 20 mA LED, for instance, would require a 28kΩ resistor.
<br>
<p><table align="center">Rset vs. Segment current and LED forward voltage</ <br><tbody align="center"><tr ><td rowspan="2">I<sub>SEG</sub> (mA)</td><td colspan="5">V<sub>LED</sub> (V)</td></tr><tr><td>1.5</td><td>2.0</td><td>2.5</td><td>3.0</td><td>3.5</td></tr><tr><td>40</td><td>12.2</td><td>11.8</td><td>11.0</td><td>10.6</td><td>9.69</td></tr><tr><td>30</td><td>17.8</td><td>17.1</td><td>15.8</td><td>15.0</td><td>14.0</td></tr><tr><td>20</td><td>29.8</td><td>28.0</td><td>25.9</td><td>24.5</td><td>22.6</td></tr><tr><td>10</td><td>66.7</td><td>63.7</td><td>59.3</td><td>55.4</td><td>51.2</td></tr></tbody></table></p>

**At the Software Level**

We’ll discuss adjusting brightness using software later in this tutorial.
</font>

<font size="5" color="white">
MAX7219 Module Pinout
</font>

<br>
<br>

|  <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <img align="center" height="200" width="300" src="https://components101.com/sites/default/files/component_pin/8x8-Dot-Matrix-Display-Module-Pinout.jpg" /> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  <br> <br> | <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   <img align="center"  height="200" width="350" src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQC4z4SO9CFy6SOjSq9oQuIVfMipxBk1EMmoA&usqp=CAU" /> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  <br> <br> |
|------|-------|

 </p>

<font size="4">

**Input Connector**

The breakout pins on one end of the module are used to communicate with the microcontroller.

- `VCC` is connected to 5V. Because the display draws a lot of current (up to 1A at maximum brightness), it’s best to use an external power supply instead of the Arduino’s 5V supply. If you want to use the Arduino’s 5V supply, keep the brightness below 25% to avoid overheating the voltage regulator.

- `GND` is the common ground pin.

- `DIN` is the Data pin. Connect it to any digital pin of the microcontroller.

- `CS/LOAD` is Chip Select (sometimes labeled as LOAD). Connect it to any digital pin of the microcontroller.

- `CLK` stands for Clock pin. Connect it to any digital pin of the microcontroller.

**Output Connector**

The breakout pins on the other end of the module are used to daisy-chain displays.

- `VCC` connects to 5V on the next module.

- `GND` connects to GND on the next module.

- `DOUT` is Data Out and connects to the DIN pin of the next module.

- `CS/LOAD` connects to CS / LOAD on the next module.

- `CLK` connects to CLK on the next module.

</font>

<font size="5" color="white">
Wiring MAX7219 Module with Arduino UNO
</font>

<font size="4">

Now that we know everything about the module, we can start hooking it up to our Arduino!

Let’s start with the module’s power supply connections. Because the display consumes a lot of current, we’ll use an external power supply instead of the Arduino board’s 5V supply. If you are only using a single MAX7219 module, you can power it directly from the Arduino, but you should avoid doing so if possible.

Let’s wire up the SPI pins. Note that each Arduino board has a unique set of SPI pins that must be connected accordingly. For Arduino boards such as the UNO/Nano V3.0, these pins are digital 13 (SCK), 12 (MISO), 11 (MOSI), and 10 (SS).

If you’re using a different Arduino board, check the official documentation for <a href="https://www.arduino.cc/en/reference/SPI" target="_blank" aria-label=" (opens in a new tab)" rel="noreferrer noopener ">SPI pin locations</a> before proceeding.

</font>

<font size="5" color="white">
Library Installation
</font>

<br>

<font size="4">

Controlling the MAX7219 module is a lot of work. Fortunately, the MD Parola library was written to hide the complexities of the MAX7219, allowing us to control the display with simple commands.

To install the library, navigate to Sketch > Include Library > Manage Libraries… Wait for the Library Manager to download the library index and update the list of installed libraries.

<p align="center"> <img src="https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/Manage-Libraries.png"> </p>

Filter your search by entering `‘max72xx’`. Look for `MD_MAX72XX` by `MajicDesigns`. Click on that entry and then choose Install.

<p align="center"> <img src="https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/MD_MAX72XX-Library-Installation.png"> </p>

The `MD_MAX72XX` library is a hardware-specific library that handles lower-level functions. It must be used in conjunction with the `MD_Parola` Library to create a variety of text animations such as scrolling and sprite text effects. Install this library as well.

<p align="center"> <img src="https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/MD_Parola-Library-Installation.png"> </p>
