## 1. Feladat: Űrkolónia Erőforrás-kezelő Rendszer

A projektben két osztályt kell létrehoznod, megfelelően szétdarabolva header és source fájlokra (`ResourcePack.h`, `ResourcePack.cpp`, `GuardedResourcePack.h`, `GuardedResourcePack.cpp`, valamint a `main.cpp`).

### 1. Az Alaposztály: `ResourcePack` (Erőforrás csomag)

Ez az osztály egy alapvető nyersanyag-szállítmányt reprezentál.

**Adattagok (szigorú enkapszulációval):**

* `private int energy` (Energia cellák száma)
* `private int minerals` (Ásványok mennyisége)
* `private const int packId` (A csomag egyedi azonosítója. Létrehozáskor kap értéket, utána sosem változhat!)

**Konstruktor:**

* Készíts egy konstruktort, ami 3 paramétert vár: az azonosítót, a kezdő energiát és a kezdő ásványmennyiséget.

**Konstans Tagfüggvények (Gettek):**

* Írj 3 tagfüggvényt, amelyek visszaadják a rejtett adattagok értékeit.

**Függvénytúlterhelés (Function Overloading):**

* Írj egy `public void addResources(int e, int m)` függvényt, ami hozzáadja a paraméterként kapott értékeket a csomaghoz.
* Írj egy ugyanilyen nevű `public void addResources(const ResourcePack& other)` függvényt is, ami egy másik csomag energiáját és ásványait adja hozzá a jelenlegihez!

**Operátor Túlterhelés (Operator Overloading):**
Ezek a metódusok mind `const` függvények legyenek, és új `ResourcePack` objektummal térjenek vissza (érték szerint). A `packId` az új csomagnál mindig legyen `999` (jelezve, hogy ez egy "kevert" csomag).

* **Összeadás:** Adjon össze két csomagot.
* **Kivonás:** Vonja ki a jobb oldali csomag tartalmát a bal oldaliból. (Ha az eredmény 0 alá menne, állítsa be 0-ra).
* **Szorzás:** Szorozza fel a csomag energiáját és ásványait egy skalár egész számmal.


### 2. A Származtatott Osztály: `GuardedResourcePack` (Védett szállítmány)

Ez az osztály a `ResourcePack`-ből öröklődik **public** módon.

**Adattagok:**

* `private const int securityLevel` (Biztonsági szint, 1 és 5 közötti fix érték, sosem változhat).

**Konstruktor:**

* Várjon 4 paramétert: id, energia, ásvány, és biztonsági szint. 

**Biztonsági ellenőrzés metódus:**
Írj egy `public bool securityAudit(...) const` nevű tagfüggvényt, ami a következő két paramétert várja:

1. `expectedEnergy`: Egy **mutató egy konstansra**. Ez a központi adatbázis elvárt energiaszintjére mutat.
2. `const alarmCounter`: Egy **konstans mutató**. Ez a memóriacím be van fagyasztva (mindig a globális riasztás-számlálóra mutat), de az *értékét* módosíthatod rajta keresztül.

**A `securityAudit` logikája:**

* Vizsgálja meg, hogy a csomag energiája eléri-e a mutató által jelzett elvárt energiát (`*expectedEnergy`).
* Ha **NEM** éri el, akkor baj van! Növeld meg a riasztások számát az `alarmCounter` mutatón keresztül és térj vissza `false` értékkel.
* Ha eléri, térj vissza `true` értékkel.

### 3. A `main.cpp` (A Tesztkörnyezet)

A `main`-ben szimuláld a működést!

---


## 2. Feladat: Szigorúan Titkos Kormányzati Archívum

Egy hírszerző ügynökség dokumentumkezelő rendszerének magját kell leprogramoznod. A rendszernek garantálnia kell az adatok sérthetetlenségét, miközben precíz naplózást végez. Három osztályt kell megtervezned:

### 1. Osztály: `Agent` (Ügynök)

Ez az osztály reprezentálja a rendszert használó személyt.

* **Állapot:** Minden ügynök rendelkezik egy névvel és egy biztonsági szinttel (1-től 5-ig).
* **Viselkedés:** Ezeket az adatokat az ügynök regisztrálásakor (példányosításkor) kell megadni. Miután egy ügynök létrejött, az adatai szigorúan megváltoztathatatlanok. A rendszernek képesnek kell lennie lekérdezni (olvasni) az ügynök nevét és szintjét anélkül, hogy fennállna a véletlen módosítás veszélye.

### 2. Osztály: `ClassifiedDocument` (Titkosított Dokumentum)

Ez az osztály tárolja magát a kényes információt és a hozzá tartozó metaadatokat.

* **Állapot:** * Tartalmazza a titkos szöveget (string).
* Rendelkezik egy elvárt biztonsági szinttel, amit a dokumentum létrehozásakor "kőbe vésnek" – ez az érték a dokumentum élettartama alatt soha, semmilyen körülmények között nem változhat meg.
* Rendelkezik egy belső számlálóval, ami a hozzáférési kísérleteket tartja nyilván (kezdetben 0). Képesnek kell lennünk lekérdezni ezt a számot.


* **Viselkedés (A "read" művelet):** * A dokumentumot meg lehet próbálni elolvasni, amihez át kell adni a próbálkozó `Agent` objektumot.
* **Szigorú szabály:** A dokumentum olvasása logikailag egy abszolút módosításmentes művelet. Aki olvassa, semmiképp sem változtathatja meg a dokumentum tartalmát vagy besorolását.
* **Az ellenmondás:** A hírszerzés szabályzata viszont előírja, hogy *minden egyes* olvasási kísérletnek (legyen az sikeres vagy sikertelen) azonnal növelnie kell a belső hozzáférési számlálót 1-gyel. Ennek akkor is meg kell történnie, ha a dokumentumot a rendszer egy olyan részének adjuk át, ahol az *kizárólag csak olvashatóként* van jelen!
* **Visszatérés:** Ha az ügynök biztonsági szintje eléri vagy meghaladja a dokumentumét, a művelet adja vissza a titkos szöveget. Ha a szintje túl alacsony, térjen vissza az `"ACCESS_DENIED"` üzenettel.


### 3. Osztály: `ArchiveVault` (Archívum Széf)

Ez a rendszer legfelső szintje, egy tároló, ami felügyel egy darab titkos dokumentumot.

* **Állapot:** Létrehozáskor kap egy dokumentumot, amit elzár magába.
* **Viselkedés:**
    * **Dokumentum megtekintése:** A széfnek lehetőséget kell biztosítania a külvilág számára, hogy "bepillantsanak" a tárolt dokumentumba. **Kritikus szabály:** A széf nem adhat ki másolatokat (fotókópiákat) a dokumentumról; a rendszer többi részének az eredeti, széfben lévő példánnyal kell interakcióba lépnie, hogy a számláló pontos maradjon. Ugyanakkor a széfnek garantálnia kell, hogy aki ezen a "kémlelőnyíláson" keresztül hozzáfér a dokumentumhoz, az az olvasáson kívül semmilyen módosítást nem tud rajta végrehajtani.
    * **Biztonsági ellenőrzés:** A széf rendelkezik egy funkcióval, ami megmondja, hogy a tárolt adat kompromittálódott-e (igaz/hamis). Egy adat akkor kompromittált, ha az eredeti dokumentumhoz több mint 3-szor próbáltak meg hozzáférni. Ennek az ellenőrzésnek a lefuttatása pusztán egy állapotfelmérés, ami garantáltan nem módosítja a széf vagy a dokumentum állapotát.

### 4. A `main.cpp` (A Tesztkörnyezet)

A `main`-ben szimuláld a működést!

---
