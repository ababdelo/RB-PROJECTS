<h1 align="center"> Arduino Code – Print Text </h1>
</br>
<font  size="3">
Our first experiment involves displaying a simple text without any animation.
But, before you upload the sketch, you must modify the following two variables.<br>
<br>
<p align="center"><img height="400" width="360" src="https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/Changes-to-make.png"></p>

<br>     The first variable, `HARDWARE_TYPE`, informs the Arduino of the module variant.

- Set the `HARDWARE_TYPE` to `GENERIC_HW`, if you’re using a module with a green PCB and a through hole MAX7219 IC like the one shown below.
<br>
<p align="center"><img height="200" width="200" src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQGVeJHCfuEy7PpKIU3eOZfBXDotyr1Hi2vp0biAGFQ-L_0IqnfS2d5hakdzI6IxF2t1j0&usqp=CAU"></p>

- Set the `HARDWARE_TYPE` to `FC16_HW`, if you’re using a module with a blue PCB and an SMD MAX7219 IC like the one shown below.
<br>
<p align="center"><img height="200" width="200" src="https://images-na.ssl-images-amazon.com/images/I/71YOL7EQFBL._AC_UL600_SR600,600_.jpg"></p>

The second variable, `MAX_DEVICES`, specifies the number of MAX7219 ICs being used. A single MAX7219 IC counts as one device, so if you want to control an 8×32 display, set `MAX_DEVICES` to `4` because an `8×32` display has four MAX7219 ICs.

When you’re finished, try out the given sketch `Print_Text.ino`, and then we’ll go over it in detail.
</font>
<p>


<font size="3"> You’ll notice that everything from the beginning of the code to the end of the setup section is the same as the previous example. The only difference is that the displayScroll() function is called at the end of the setup section.</font>

<br>
<font size="6" color="white"> Output :</font>
<font size="3">

To see the output, the display must be properly oriented. If you’re using a generic module, make sure the MAX7219 IC is on top. If you’re using an FC-16 module, make sure the DIN side is on the right side.

If everything goes well, you will see the following output.

<p align="center" ><img src="https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/MAX7219-LED-Display-Arduino-Text-Output.gif" /></p>


<h3> Code Explanation :</h3>

The first step is to include all the necessary Arduino libraries. As previously stated, the MD_MAX72XX library implements the hardware-specific functions of the LED matrix, whereas the `MD_Parola` library implements the text effect. You must also include the SPI library, which is used to communicate with the display via `SPI`.

```c++
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
```

Next, we must specify which hardware is being used. Because we are using an FC-16 module for our experiments, the `HARDWARE_TYPE` is set to `FC16_HW`. We’re using 4 MAX7219 ICs, so `MAX_DEVICES` is set to 4. Finally, the pin to which the display’s CS pin is connected is defined.

```c++
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3
```

The function `MD_Parola()` is then used to create a new instance of the MD_Parola class. The first parameter is the hardware type, the second is the CS pin, and the third is the number of MAX7219 ICs being used.

```c++
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
```

In the setup section of the code, we first use the function `begin()` to initialize the object. The brightness of the display can be adjusted using the function `setIntensity()`, which accepts values ranging from 0 (lowest brightness) to 15 (maximum brightness). The display is cleared using the `displayClear()` function.

```c++
void setup() {
  myDisplay.begin();
  myDisplay.setIntensity(0);
  myDisplay.displayClear();
}
```

In the loop section of the code, we first set the alignment of the text to be printed with the function `setTextAlignment()`, to which the values `PA_LEFT`, `PA_CENTER`, and `PA_RIGHT` can be passed to align the text to the left, center, or right, respectively.

The string ‘Left’ is then printed using `myDisplay.print("Left")`. Please keep in mind that the text string should be enclosed in quotation marks `" "`. When printing numbers, no quotation marks are required; for example, to display 1234, write `myDisplay.print(1234)`. You can also use the `setInvert()` function to invert the display.

```c++
void loop() {
	myDisplay.setTextAlignment(PA_LEFT);
	myDisplay.print("Left");
	delay(2000);
	
	myDisplay.setTextAlignment(PA_CENTER);
	myDisplay.print("Center");
	delay(2000);

	myDisplay.setTextAlignment(PA_RIGHT);
	myDisplay.print("Right");
	delay(2000);

	myDisplay.setTextAlignment(PA_CENTER);
	myDisplay.setInvert(true);
	myDisplay.print("Invert");
	delay(2000);

	myDisplay.setInvert(false);
	myDisplay.print(1234);
	delay(2000);
}
```
