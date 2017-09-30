#!/bin/bash
# Saját script
# Frissítésekhez készítettem magamnak, hogy ne kelljen mindig a Projects mappát a cp parancsba beilleszteni
# Valószínüleg csak nálam működik, mivel nekem van Projects mappámban a bongeszo mappa
sudo rm -r /usr/bin/mbrowser
sudo cp ~/Projects/bongeszo/build/mbrowser /usr/bin
sudo chmod +x /usr/bin/mbrowser

