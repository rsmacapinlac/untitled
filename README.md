# Overview

I love productivity apps. I've been using a lot of keyboard shortcut
applications and macros in my day to day life. It is usually the first thing
that I install on a new computer. However, _that_ is the main drawback: the fact
that you have to install something. There are scenarios where this is not
possible: a corporately owned computer (with strict policies), Citrix or the
simple fact that the productivity tool is not ported for your operating
system (like Ubuntu).

## The goal

To build a device that plugs between a keyboard and a computer (ie uses the
keyboard as its input device) where the computer recognizes it as a keyboard. It
should function as a keyboard passthrough and trap certain keyboard
combinations. There should be multiple combinations available such as ctrl-alt-0
through ctrl-alt-9. When the device traps a valid key combination it will "type
out" an defined template from an external storage device (eg SD card or USB
stick).

# Hardware (so far)

Here is the hardware list that this project is working with:

* Arduino ~~Leonardo~~ ~~Yun~~ back to the [Leonardo](https://store.arduino.cc/usa/arduino-leonardo-with-headers)
* [USB host shield](https://store.arduino.cc/usa/arduino-usb-host-shield)

# Setting it up

So, I'm assuming that you bought the hardware and you want to upload this.

Clone this repository to your local computer.

`git clone https://github.com/rsmacapinlac/untitled.git`

Rename the Templates.h.example file to Templates.h

`cp untitled/Templates.h.example untitled/Templates.h`

Use your favorite editor to update the data in the Templates.h file.

`vim untitled/Templates.h`

Compile and upload using the arduino software.

## Setting up the hardware

You need a USB cable to go from the Leonardo's micro USB port to your computer
and your keyboard should plug into the USB shield's USB.

# Using it

Once everything has been setup correctly, all you need to do is use ctrl-alt-0
to ctrl-alt-9 to activate the templates you've setup.

# Where things are at:

* [x] Keyboard passthrough
* [x] Trapping predefined key combinations
* [x] A way to store the templates
* [x] "typing out" the template on valid key combination
* [ ] Logging (when the key combination gets triggered)
* [ ] Needs to write up some "instructions"

Nice to haves?

* Setting your own key combination
* A nice case
