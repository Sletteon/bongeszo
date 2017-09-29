#!/bin/bash
sudo apt update
sudo apt install libqt5webkit5-dev
sudo rm -r /usr/bin/mbrowser
sudo cp ~/home/bongeszo/build/mbrowser /usr/bin
sudo chmod +x /usr/bin/mbrowser

