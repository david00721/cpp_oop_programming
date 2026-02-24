### 1. Feladat: Mutató a konstansra vs. Konstans mutató

Készíts egy `MemoryDebugger` nevű osztályt, amely a mutatók különböző const-viselkedéseit szimulálja!

* Legyen egy `private` adattagja: egy 3 elemű beépített statikus tömb (pl. `int memoryBlocks[3]`), amit a konstruktorban tölts fel tetszőleges számokkal.
* Írj egy `public` metódust `inspectMemory` néven, amely egy "mutató egy konstansra" (`const int*`) típusú paramétert vár. A metódus írja ki a mutatott értéket, de (kommentben jelezve) bizonyítsd be, hogy ezen a mutatón keresztül az érték nem felülírható.
* Írj egy másik `public` metódust `lockAndResetPointer` néven, amely egy "konstans mutatót" (`int* const`) vár paraméterként. Ez a metódus nullázza le a mutatott értéket (írd felül 0-ra), majd (szintén kommentben) jelezd, hogy miért nem lehet ezt a mutatót a függvényen belül a `memoryBlocks` egy másik elemére átirányítani.

### 2. Feladat: Konstans tagváltozók, inicializáló lista és öröklés

Készíts egy `Appliance` (Háztartási gép) nevű alaposztályt és egy ebből `public` módon származtatott `WashingMachine` (Mosógép) osztályt!

* Az `Appliance` osztálynak legyen egy `private const int serialNumber` (sorozatszám) és egy `protected int powerRating` (teljesítmény) adattagja.
* A `WashingMachine` osztály rendelkezzen egy saját `private const int drumCapacity` (dob kapacitása) adattaggal.
* Írd meg mindkét osztály konstruktorát! A `WashingMachine` konstruktora várjon 3 paramétert (sorozatszám, teljesítmény, kapacitás), és a megfelelő módon – az alaposztály konstruktorának hívásával és a saját inicializáló listájának használatával – adjon értéket minden adattagnak. Figyelj arra, hogy a konstansok később már nem kaphatnak értéket a konstruktor törzsében `{ ... }`!

### 3. Feladat: Konstans tagfüggvények és a `mutable` kulcsszó

Készíts egy `UserAccount` osztályt, ami egy bejelentkezési rendszert szimulál!

* Legyen egy `private std::string username` és egy `private std::string password` adattagja.
* Legyen egy `private mutable int failedLoginAttempts` adattagja, ami a sikertelen bejelentkezési kísérleteket számolja, és a konstruktorban 0-ról indul.
* Írj egy `public const` tagfüggvényt `checkPassword` néven, ami egy stringet vár bemenetként.
* A metódus ellenőrizze, hogy a kapott jelszó egyezik-e az elmentett jelszóval. Ha nem egyezik, a metódus növelje meg a `failedLoginAttempts` értékét, és térjen vissza `false`-szal. Ha egyezik, térjen vissza `true`-val. (A tagfüggvény `const` minősítése garantálja, hogy magát a jelszót vagy a felhasználónevet nem írod felül, de a számláló a `mutable` miatt mégis növelhető).

### 4. Feladat: `const_cast` alkalmazása származtatott osztályban

Adott egy régi, nem általad írt, de a rendszerben kötelezően használandó globális C-függvény, aminek a szignatúrája a következő: `void legacyHardwareTest(int* statusPin);` (Feltételezzük, hogy ez a függvény csak kiolvassa a pin állapotát, de a készítője rosszul írta meg, és lehagyta a `const` kulcsszót).

* Hozz létre egy `HardwareComponent` alaposztályt, aminek van egy `protected int pinId` adattagja. Ezt egy konstruktor segítségével lehessen inicializálni.
* Származtass belőle `public` módon egy `Sensor` osztályt.
* A `Sensor` osztálynak írj egy `public void runDiagnostics() const` nevű **konstans tagfüggvényét**.
* A `runDiagnostics` metóduson belül hívd meg a globális `legacyHardwareTest` függvényt, paraméterként átadva a `pinId` memóriacímét. Mivel a metódusod `const`, az osztály adattagjai (így a `pinId` is) `const`-ként viselkednek benne. Használd a `const_cast` operátort, hogy sikeresen át tudd adni a paramétert a régi függvénynek fordítási hiba nélkül!

### 5. Feladat: Okosotthon Szenzorhálózat

Készíts egy rendszert, ami egy okosotthon hőmérséklet-érzékelőjét modellezi! A feladat fókuszában a konstans tagváltozók, a `mutable` kulcsszó és a konstansokra mutató pointerek állnak.

* **Alaposztály (`Device`):**
    * Legyen egy `private const int deviceId` (eszköz azonosító) és egy `protected bool isActive` (aktív-e az eszköz) adattagja.
    * A konstruktora inicializálja ezeket (figyelj az inicializáló listára!).
    * Írj egy `public const` tagfüggvényt `getDeviceId()` néven, ami visszaadja az azonosítót.


* **Származtatott osztály (`TemperatureSensor`):**
    * Öröklődjön `public` módon a `Device` osztályból.
    * Legyen egy `private const int criticalTemp` (kritikus hőmérsékleti határ) adattagja.
    * Legyen egy `private mutable int alertCount` (riasztások száma) adattagja, ami 0-ról indul.
    * A konstruktora várja paraméterként az azonosítót és a kritikus hőmérsékletet, majd megfelelően inicializálja a saját és az alaposztály tagjait.


* **Logika és függvények a `TemperatureSensor`-ban:**
    * Írj egy `public void toggleStatus()` függvényt, ami megfordítja az `isActive` állapotát (ha `true` volt, `false` lesz, és fordítva). Ez értelemszerűen nem lehet konstans függvény.
    * Írj egy `public bool analyzeTemperature(const int* currentTemp) const` nevű függvényt! A paraméter egy "mutató egy konstansra".
    * A függvény először ellenőrizze, hogy az eszköz aktív-e. Ha nem, térjen vissza `false`-szal.
    * Ha aktív, nézze meg a mutatott értéket. Ha a `*currentTemp` meghaladja a `criticalTemp` értékét, növelje meg az `alertCount` számlálót (emlékezz, a függvény `const`, a számláló viszont `mutable`!), és térjen vissza `true`-val (riasztás).
    * Egyébként térjen vissza `false`-szal.

### 6. Feladat: Legacy Kriptográfiai Modul

Egy régebbi, C-nyelven írt titkosító könyvtárat kell integrálnod egy új C++ osztályhierarchiába. A feladat fókuszában a referenciák, a "konstans mutató a konstansra" és a `const_cast` állnak.

* **A "Legacy" C-függvény (ezt a kódot kapod, a globális térben kell lennie):**
    * `void legacyEncryptBlock(int* hwKey, int* dataBlock);` (Feltételezzük, hogy ez a függvény a hardverkulcsot csak kiolvassa, a `dataBlock` tartalmát viszont helyben titkosítja/módosítja. A készítője sehol nem használt `const`-ot.)


* **Alaposztály (`SecurityModule`):**
    * Legyen egy `protected const int hardwareKey` adattagja (a titkosításhoz használt fix hardveres kulcs).
    * A konstruktorában kapjon értéket a kulcs.


* **Származtatott osztály (`DataProcessor`):**
    * Öröklődjön `public` módon a `SecurityModule`-ból.
    * Legyen egy `private int& totalProcessedRef` adattagja (egy referencia, ami egy külső, globális vagy `main`-ben lévő számlálóra hivatkozik, ami az összes feldolgozott blokkot számolja a program futása során).
    * Legyen egy `private int dataBuffer[5]` tömbje (fix 5 elemű beépített tömb), amit a konstruktor kinulláz.
    * A konstruktora várja a hardverkulcsot és a számlálóra mutató referenciát, és inicializálja azokat.


* **Logika és függvények a `DataProcessor`-ban:**
    * Írj egy `public void loadData(const int* const inputData)` függvényt! A paraméter egy "konstans mutató egy konstansra" (egy 5 elemű tömbre mutat a memóriában). A függvény másolja át az `inputData` első 5 elemét a belső `dataBuffer` tömbbe. (Ehhez használhatsz egy egyszerű `for` ciklust 0-tól 4-ig).
    * Írj egy `public void executeEncryption() const` függvényt!
    * Mivel ez a metódus `const`, a belső `dataBuffer` is konstansként viselkedik ezen a hatókörön belül (a `hardwareKey` meg amúgy is az).
    * Növeld meg 1-gyel a `totalProcessedRef` referencián keresztül a külső számlálót!
    * Hívd meg a `legacyEncryptBlock` függvényt! Ehhez add át neki a `hardwareKey` memóriacímét és a `dataBuffer` első elemének címét. Mivel a `legacyEncryptBlock` nem `const` pointereket vár, viszont a mi metódusunk `const`, használnod kell a `const_cast` operátort mindkét átadott paraméternél, hogy a kód leforduljon!
