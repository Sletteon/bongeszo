# mbrowser
Ez egy alapszintű böngésző, amelyet a qtwebkit használatával fejlesztettem.
Megoldást kerestem a billentyűzet és az egér közötti gyakori váltás kiküszöbölésére. 

<i>A programot Linuxra terveztem a dependecy-k miatt. (qtwebkit)</i>

Az általam elkészített böngésző automatikusan kiegészíti a weboldalak címét (pl.: google.hu -> https://google.hu).
Ha nincs a keresett szövegben pont, akkor a szöveget megnyitja google keresés formájában.
Alt + D kombinációval a szövegdobozra fókuszál.
Alt + H megnyomásával visszalép az előző meglátogatott oldalra, valamint az Alt + L-el továbbmegyünk.
A J billentyűvel lefele, a K-val meg fölfele is lehet görgetni, vízszintes görgetés a H és az L gombbal történik.
A linkek megnyitása majd az F-el lesz lehetséges.
Választásom azért esett ezekre a betűkre, mert a jobb kezünk itt pihen (tízujjas vakon gépelés).
A Vim szövegszerkesztő mutatta meg számomra ezt a lehetőséget.
Az ötletet a qtbrowsertől és a vimium chrome-plugintól merítettem.

Nehézséget okoztak a billentyűparancsok (pl.: a görgetés megoldása), a feladat legkönnyebb része maga a böngésző volt. :P
(WebView konténer beillesztése a GUI-ba)


<i>Megjegyzés: Mivel a projektet teszt céljából kezdtem, így pl. a projektfájlnak untitled a neve.<i>
  
<b>Az alábbi utasítások Debian/Ubunu/Mint disztribúciókra alkalmazhatók.</b>

Gyors megnyitás:
  ```sh
sudo apt install libqt5webkit5-dev
git clone https://github.com/Sletteon/bongeszo && cd bongeszo/build
./mbrowser
```
<i>Install.sh is Debian alapú rendszerekre lett írva (apt), de ha először a libqt5webkit5-dev csomagot telepítjük a disztribúció csomagkezelőjével, akkor is működni fog a szkript.</i>
Telepítés: 
```sh
git clone https://github.com/Sletteon/bongeszo && cd bongeszo
sudo chmod +x install.sh
./install.sh
```
Telepítés után az
```sh
mbrowser
```
paranccsal lehet bármikor elindítani a böngészőt.


<b>Telepítendő csomagok:</b>
<i>Install.sh-ban automatikusan telepíti</i>
libqt5webkit5-dev
