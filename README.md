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

* Arduino ~~Leonardo~~ Yun
* USB host shield

# Where things are at:

* [x] Keyboard passthrough
* [x] Trapping predefined key combinations
* [x] Storing and reading templates from external storage (can't seem to get the SD
  card shield to work)
* [x] "typing out" the template on valid key combination
* [ ] Dang sketch needs to wait until the system boots before it does anything!

Nice to haves?

* Setting your own key combination
* A nice case
