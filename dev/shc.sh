#!/bin/bash
sudo apt-get install build-essential
sudo apt-get install gcc-8 g++-8 -y
sudo apt-get install automake-1.16
#comment dpkg if you need
dpkg -i automake_1.16.1-4ubuntu6_all.deb
cd shc
./configure
make
sudo make install
