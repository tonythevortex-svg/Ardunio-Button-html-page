# Arduino Button → Browser Interaction

**Press a physical button and make something happen on a computer screen.**

This small beginner-friendly experiment connects an Arduino to a web browser. Press one of up to five buttons and the webpage displays a large number, changes colour and plays a short sound. Release the button and the display returns to `0`.

The aim is to explore a simple connection between **physical inputs** and **screen-based interactions**, without having to build a separate desktop application.

## What it does

- Reads up to **five physical push buttons** connected to an Arduino.
- Sends the button number from the Arduino to the computer over a USB serial connection.
- Displays a large **1, 2, 3, 4 or 5** in the browser.
- Gives each button its own **background colour** and **musical tone**.
- Shows **0** when no button is pressed.

## Files in this project

| File | What it is for |
| --- | --- |
| `buttons.ino` | Code uploaded to the Arduino. It checks which button is pressed and sends a number to the computer. |
| `button_listener.html` | A webpage that listens for these numbers and changes what appears and sounds on screen. |

You do **not** need to understand or edit either file to try the experiment.

## What you need

**Hardware**

- An Arduino with digital pins D2–D6 (for example, an Uno or Nano).
- **One to five** normally-open push buttons. You can start with just **one**.
- A USB **data** cable that fits your Arduino (some charging-only cables will not work).
- Jumper wires and, ideally, a breadboard.
- A computer.

**Software**

- [Arduino IDE](https://www.arduino.cc/en/software) — free software used to upload code to the Arduino.
- **Google Chrome or Microsoft Edge on a desktop computer** — to open the webpage and connect to the Arduino using Web Serial. Not all browsers support this feature.

## Step 1 — Connect a button to the Arduino

**Start with one button.** Connect:

1. One side of the push button to Arduino pin **D2**.
2. The opposite side of the push button to **GND** (ground) on the Arduino.

```text
Arduino D2  -------- [ PUSH BUTTON ] -------- Arduino GND
```

If you are using a common four-legged breadboard push button, be aware that **the two legs on the same side are often already connected together**. Use legs on *opposite sides* of the switch so they connect only when you press it. On a breadboard, it is usually easiest to place the switch across the central gap.

To add more buttons, connect each one between a digital pin and GND:

| Physical button | Digital pin | Other connection |
| --- | --- | --- |
| Button 1 | D2 | GND |
| Button 2 | D3 | GND |
| Button 3 | D4 | GND |
| Button 4 | D5 | GND |
| Button 5 | D6 | GND |

All five buttons can share the Arduino's **GND** connection using a common ground rail on the breadboard.

**No extra resistors are needed:** the Arduino code enables its internal pull-up resistors (`INPUT_PULLUP`). This means the input normally reads **HIGH**, and reads **LOW** when a button connects it to GND. The program translates that into button numbers.

## Step 2 — Upload the Arduino code

1. Download or clone this GitHub repository. If downloading a ZIP file, unzip it first.
2. Connect your Arduino to the computer using its USB cable.
3. Open **Arduino IDE**.
4. Open the downloaded `buttons.ino` file (**File → Open**). If the IDE asks to put it in a sketch folder, choose **OK**.
5. In the IDE, select your Arduino **board** and **port** from the board selector or **Tools** menu. The port might be named `COM...` on Windows or `/dev/cu...` on macOS.
6. Click **Upload** (the right-arrow icon). Wait for the IDE to confirm that uploading is complete.

**Optional quick check:** open **Tools → Serial Monitor**, set it to **9600 baud**, and press your button. You should see `1` when you press button 1 and `0` when you release it. Other buttons produce `2`–`5`. **Close Serial Monitor before the next step** — the browser needs to use the same serial port.

## Step 3 — Open the webpage and connect

1. Find the downloaded `button_listener.html` file on your computer.
2. Open it with **Chrome or Edge** (you can drag the file into the browser window).
3. You should see a large **0**, the message **Not connected**, and a **Connect Arduino** button.
4. Click **Connect Arduino**. The browser should show a list of available serial devices.
5. Select your Arduino's port and confirm **Connect**.
6. The webpage should say **Connected. Press a button.**
7. Press your physical button: the screen changes colour, displays the button number and plays a short tone. Release it and the screen returns to **0**.

You do not need to upload the HTML file to a website or install a special browser plugin. The webpage runs locally. Your browser must allow serial access and you must choose the Arduino when asked.

## How it works (in simple terms)

```text
Press a button
      ↓
Arduino detects the button
      ↓
Arduino sends "1" (or "2", "3", "4", "5") over USB
      ↓
The webpage reads the number
      ↓
The screen changes and a tone plays
```

When you release the button, Arduino sends `0` and the screen returns to its starting appearance. If you hold multiple buttons at once, this version reports only the first in pin order (D2 before D3, and so on).

## Troubleshooting

| Problem | What to try |
| --- | --- |
| **The Arduino doesn't appear in the port list** | Check the USB cable is a **data** cable, that the board is powered, and that the correct port is selected. Try reconnecting the cable. |
| **The webpage says Web Serial is unavailable** | Use a supported **desktop Chrome or Edge** browser. Web Serial is not supported in every browser or environment. |
| **The connection fails or says the port is in use** | Close the Arduino IDE **Serial Monitor** and any other program connected to that port. Then try again. |
| **It connects but pressing a button does nothing** | Check the wiring: the switch must connect **D2 to GND** when pressed (or D3–D6 for other buttons). Try the Serial Monitor test from Step 2, then close it before reconnecting the browser. |
| **A button seems permanently pressed** | Check the button legs: you may have wired two legs that are already connected internally. |
| **The webpage works but there is no sound** | Check your computer volume and browser sound settings. Sound is generated by the webpage, not by the Arduino. |
| **You refreshed the page or unplugged the Arduino** | Reconnect through **Connect Arduino** and select the port again. |

## Things to experiment with

Once you have the basic interaction working, try changing the webpage in a text editor:

- **Change the displayed numbers into words:** find `buttonLabels` in `button_listener.html` and replace the label values, e.g. `'1': 'HELLO'`.
- **Change the sounds:** find `buttonFrequencies` and change the frequency values (measured in hertz, Hz).
- **Change the colours:** find the CSS rules named `body.button-1` to `body.button-5` and change their `background` colours.
- **Make a different interaction:** use the incoming button numbers to trigger an image, animation, text, or another browser-based event.

The Arduino sketch uses **9600 baud** (`Serial.begin(9600)`), which must match the rate set in the webpage (`baudRate: 9600`) if you alter it later.

## AI-assisted development

**The code for this project was generated and refined using generative AI**, through an iterative process of human-directed experimentation, testing and adjustment. It is shared as a simple working study and a starting point for creative exploration of physical buttons, Arduino inputs and browser-based interactions.
