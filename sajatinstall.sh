#!/bin/bash
# Saját script
# Frissítésekhez készítettem magamnak, hogy ne kelljen mindig a Projects mappát a cp parancsba beilleszteni
# Valószínüleg csak nálam működik, mivel nekem van Projects mappámban a bongeszo mappa
sudo apt update
sudo apt install libqt5webkit5-dev
sudo rm -r /usr/bin/mbrowser
sudo cp ~/home/Projects/bongeszo/build/mbrowser /usr/bin
sudo chmod +x /usr/bin/mbrowser

