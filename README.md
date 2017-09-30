# böngésző
Egy alapszintű böngésző, ami a qtwebkiten alapszik.

<i>Linuxra már elkészült egy build, Windows operációs rendszeren is használható ha a qtwebkit csomag telepítése sikeres.</i>

Automatikusan kiegészíti a weboldalak címét (pl.: google.hu -> https://google.hu)
Ha nincs a keresett szövegben pont, akkor a keresett szöveget megnyitja google keresés formájában.
Alt + D kombinációval a szövegdobozra fókuszál.
Alt + balra megnyomásával visszalép az előző meglátogatott oldalra, valamint az Alt + jobbrával továbbmegyünk

<i>Megjegyzés: Mivel a projektet teszt céljából kezdtem, így pl. a projektfájlnak untitled a neve.<i>

Gyors megnyitás:
  ```sh
sudo apt install libqt5webkit5-dev
git clone https://github.com/Sletteon/bongeszo && cd bongeszo/build
./mbrowser
```
<b>Debian/Ubuntu/Linux Mint</b>

<i>Install.sh Debian alapú rendszerekre lett írva (apt), de ha először a libqt5webkit5-dev csomagot telepítjük a disztribúció csomagkezelőjével, akkor is működni fog a szkript.</i>
<b>Telepítés</b>: 
```sh
git clone https://github.com/Sletteon/bongeszo && cd bongeszo
sudo chmod +x install.sh
./install.sh
```
Telepítés után az
```sh
mbrowser
```
parancscsal lehet bármikor elindítani a böngészőt.


<b>Telepítendő csomagok:</b>
<i>Install.sh-ban automatikusan telepíti</i>
libqt5webkit5-dev
