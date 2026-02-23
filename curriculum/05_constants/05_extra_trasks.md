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