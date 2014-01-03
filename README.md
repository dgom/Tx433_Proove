# About

Tx433_proove is adapted for controlling rc remote controlled power sockets (Nexa, Proove, Anslut)
with the Raspberry Pi. Kudos to the projects [Tx433_Proove](https://github.com/JoakimWesslen/Tx433_Proove) and [wiringpi](https://projects.drogon.net/raspberry-pi/wiringpi).
I just adapted the Tx433_Proove code to use the wiringpi library instead ofthe library provided by the arduino.


## Usage

First you have to install the [wiringpi](https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/) library on the Raspberry Pi.
Install the library for accessing the GPIO pins of the Pi by running the following commands on the Pi:

  git clone git://git.drogon.net/wiringPi
  cd wiringPi
  ./build

After that you can compile the example programs *send* and *send2* by executing *make*. 
You may want to change the used GPIO pin before compilation in the send.cpp and send2.cpp source files.

Usage: ./send  <command>
 Command is 0 for OFF and 1 for ON
The send2 program is prepared for taking arguments <transmitterCode> <channelCode> <command>.


