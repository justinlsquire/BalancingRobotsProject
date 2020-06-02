#!/bin/sh

# define the laptop screen
xrandr --output LVDS1 --mode 1024x768 --primary

# force a 1024x768 resolution for the projector, right of the laptop screen. With this, notes must be at the left,
# i.e. use \setbeameroption{show notes on secondscreen=left} and \note{}
xrandr --output VGA1 --mode 1024x768 --right-of LVDS1 || (xrandr --addmode VGA1 1024x768 && xrandr --output VGA1 --mode 1024x768 --right-of LVDS1) 

