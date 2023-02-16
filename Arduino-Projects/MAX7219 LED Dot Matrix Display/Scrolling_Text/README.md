<h1 align="center"> Arduino Code – Scrolling Text </h1>
</br>
<font size="4">When you want to print a message on a dot matrix display, you will often find that the display is too small to fit the whole message. The solution is the scroll text effect.</font>

<font size="3"> After compiling your code to arduino. If everything goes well, you will see the following output.</font>

<p align="center"><img align="center" src="https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/MAX7219-LED-Display-Arduino-Scrolling-Output.gif"></p>

<font size="5">Code Explanation :</font>

<font size="4"> You’ll notice that everything from the beginning of the code to the end of the setup section is the same as the previous example. The only difference is that the displayScroll() function is called at the end of the setup section. </font>

```c++
myDisplay.displayScroll("Hello", PA_CENTER, PA_SCROLL_LEFT, 100);
```
<font size="3">As you can see, this function takes four arguments: **displayScroll(pText, align, textEffect, speed)**

- `pText`  - is the  text sting. Your message goes here.
<br>
- `align` - sets the alignment of text during optional pause. You can use the same alignment options as in the previous example, like `PA_CENTER`, `PA_LEFT`, or `PA_RIGHT`.
<br>
- `tetxtEffect` – specifies the scrolling effects. Setting it to `PA_SCROLL_LEFT` will scroll the text left.
<br>
- `speed` - determines the speed of the animation. The speed is the time in milliseconds between animation frames. Short time results in faster animation.

Only two functions are used to scroll text in the loop section. First, in an if statement, we use the function `displayAnimate()`. This function scrolls the text and returns true when it is finished. When the scrolling is finished, we use the function `displayReset()` to reset the display, resulting in continuous scrolling.

```c++
void loop() {
	if (myDisplay.displayAnimate()) {
		myDisplay.displayReset();
	}
}
```
<br>
<p align="center"><img height="32" width="32"  align="center" src="https://img.icons8.com/office/40/null/info--v1.png"/>
For more text effects, please visit <a align="center" href="https://majicdesigns.github.io/MD_Parola/class_m_d___parola.html">MD_Parola Lirary Reference</a>
</p>
