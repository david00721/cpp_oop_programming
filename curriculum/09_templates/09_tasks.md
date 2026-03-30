### 1. Függvénysablonok

**1. Feladat: Küszöbérték-számláló (Szűrés)**
Írj egy `countIfGreater` nevű függvénysablont, amely egy adott típusú elemeket tartalmazó tömbben (vagy memóriaterületen) számol! A függvény várjon három paramétert: egy mutatót a tömb elejére, a tömb méretét (egész számként), és egy `threshold` (küszöb) értéket, ami ugyanolyan típusú, mint a tömb elemei. A függvény térjen vissza azzal, hogy hány olyan elem van a tömbben, ami szigorúan nagyobb, mint a küszöbérték.
*Teszteld a `main`-ben egész számok tömbjével, és tizedestörtek tömbjével is!*

**2. Feladat: Biztonságos Határoló (Clamping)**
Írj egy `clampValue` nevű függvénysablont, amely egy értéket egy megadott minimum és maximum közé szorít! Három azonos típusú paramétert vár: `value`, `min`, `max`. 
Ha a `value` kisebb, mint a `min`, adja vissza a `min`-t. Ha nagyobb, mint a `max`, adja vissza a `max`-ot. Minden más esetben adja vissza magát a `value`-t. 
*Teszteld karakterekkel (pl. szoríts be egy betűt 'A' és 'M' közé) és számokkal is!*

---

### 2. Osztálysablonok

**3. Feladat: Előzmény-naplózó (Sima osztálysablon)**
Készíts egy `HistoryTracker` osztálysablont, ami egyetlen `T` típussal dolgozik. Az osztály feladata, hogy tárolja egy változó legutolsó 3 állapotát (használj egy fix 3 elemű belső tömböt).
Írj hozzá egy `record(T newValue)` metódust, ami betolja az új értéket (a legrégebbi pedig elvész), és egy `printHistory()` metódust, ami kilistázza a mentett értékeket. 
*Példányosítsd a főprogramban egy játékos koordinátáira (`double`) és állapotüzeneteire (`std::string`).*

**4. Feladat: Generikus Feladatkezelő (Polimorf osztálysablon)**
Hozz létre egy `TaskProcessor` osztálysablont (`T` típussal), amely képes feldolgozni és tárolni maximum 5 darab polimorf feladatot. 
Ehhez készíts egy `Task<T>` absztrakt ősosztálysablont is, aminek van egy `virtual T execute() = 0` metódusa. Származtass belőle két konkrét feladatot (pl. `MathTask` és `LogicTask`), amik konkrét értékekkel térnek vissza. A `TaskProcessor` egy tömbben tároljon `Task<T>*` mutatókat, és legyen egy `runAll()` metódusa, ami minden feladatot lefuttat, és kiírja az eredményüket.

**5. Feladat: Eseménykezelő Rendszer (Polimorf + Több sablonparaméter)**
Ez egy igazi szoftverarchitekturális kihívás! Készíts egy `EventHandler` absztrakt ősosztályt, aminek KÉT sablonparamétere van: `EventType` (az esemény típusa) és `ReturnType` (a válasz típusa). Legyen egy tisztán virtuális `ReturnType handle(EventType event)` metódusa.
Származtass belőle egy `KeyboardHandler`-t (pl. `int` esemény, `std::string` válasz) és egy `MouseHandler`-t. Hozz létre a `main`-ben dinamikusan ilyen kezelőket ős-mutatókon keresztül, és hívd meg a `handle` metódusaikat különböző eseményekkel!

---

### 3. Több sablonparaméter és Alapértelmezések

**6. Feladat: Rugalmas Konfigurációs Tároló**
Írj egy `ConfigEntry` osztálysablont, amely egy beállítás nevét (`KeyType`) és értékét (`ValueType`) tárolja. 
A `KeyType` **alapértelmezett típusa legyen `std::string`**.
Írj egy `print()` metódust az adatok kiíratására. A `main`-ben példányosíts egy beállítást úgy, hogy mindkét típust explicit megadod (pl. `int` kulcs, `double` érték), és egyet úgy, hogy csak az értéket adod meg, hagyatkozva a beépített szöveges kulcs alapértelmezésre!

**7. Feladat: Telemetria Csomag**
Készíts egy `SensorData` osztálysablont az IoT (Internet of Things) szenzorok adatainak tárolására. Két paramétert várjon: `MeasurementType` (pl. a hőmérséklet típusa) és `TimestampType` (az időbélyeg típusa). 
A `TimestampType` **alapértelmezett típusa legyen `long`**.
Készíts hozzá megfelelő konstruktort és egy getter metódust. Teszteld az alapértelmezett és a felülírt típusokkal is!

---

### 4. Nem-típus sablonparaméterek

**8. Feladat: Generikus 2D Játéktábla**
Készíts egy `Grid` osztálysablont, amely egy kétdimenziós játéktáblát reprezentál! A sablon várjon egy `T` típust a cellák tartalmához, valamint KÉT nem-típus paramétert: `int Rows` (sorok) és `int Cols` (oszlopok).
Az osztály statikusan (nem dinamikus memóriafoglalással) hozzon létre egy ekkora 2D tömböt. Írj egy `fill(T value)` metódust, ami feltölti a táblát a kapott értékkel, és egy `display()` metódust a rács kirajzolására. 
*Teszteld le egy 3x3-as `char` táblával (pl. amőbához) és egy 5x5-ös `int` táblával!*

---

### 5. Sablonspecializáció

**9. Feladat: Okos Szöveggé Alakító (Függvény specializáció)**
Írj egy `stringify` nevű függvénysablont, ami bármilyen `T` típusú értéket kap, és visszaadja azt szövegként. (Tipp: az általános sablonban használhatod a `std::to_string()` beépített függvényt, ha számokról van szó).
**A csavar:** Készíts egy teljes specializációt a `bool` típusra! Ha a függvény logikai értéket kap, ne "0"-t vagy "1"-et adjon vissza, hanem a "TRUE" vagy "FALSE" szövegeket!

**10. Feladat: Adatszerializáló (Osztály specializáció)**
Készíts egy `DataSerializer` osztálysablont (`T` típussal). Legyen egy `getSize(T data)` metódusa. Az általános sablon térjen vissza egyszerűen a kapott adat memóriában elfoglalt méretével (használd a `sizeof()` operátort).
**A csavar:** Készíts teljes specializációt a `std::string` típusra! Egy C++ string esetén a `sizeof` megtévesztő (csak a vezérlőblokk méretét adja). A specializált osztály metódusa a tényleges karakterek számával (`data.length()`) térjen vissza! 
*Teszteld egész számokkal, struktúrákkal és hosszú szövegekkel is!*