# böngésző
Egy alapszintű böngésző.
<i>Linuxra már elkészült egy build, Windows operációs rendszeren is használható ha a qtwebkitet telepítjük.</i>

Automatikusan kiegészíti a weboldalak címét (pl.: google.hu -> https://google.hu)
Ha nincs a keresett szövegben pont, akkor a keresett szöveget megnyitja google keresés formájában.
Alt + D kombinációra a szövegdobozra fókuszál

<i>Megjegyzés: Mivel a projektet teszt céljából kezdtem, így pl. a projektfájlnak untitled a neve.<i>

Gyors megnyitás:
  ```sh
git clone https://github.com/Sletteon/bongeszo && cd bongeszo
cd build-untitled-Desktop-Release
./mbrowser
```
Telepítés:
```sh
sudo chmod +x install.sh
./install.sh
```
Telepítés után az
```sh
mbrowser
```
parancscsal lehet bármikor elindítani a böngészőt.


<b>Telepítendő szoftverek:</b>

  Debian/Ubuntu/Linux Mint:
  ```sh
sudo apt install libqt5webkit5-dev
```
