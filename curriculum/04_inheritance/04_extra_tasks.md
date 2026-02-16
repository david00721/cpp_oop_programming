### 1. Feladat: Hardver Hierarchia és Adatvédelem

**Cél:** A `protected` és `private` öröklődési módok közötti különbség kikényszerítése.

* **Alaposztály (`Component`):** Legyen egy `protected` string `serialNumber` és egy `public` `getSpecs()` metódus.
* **Köztes osztály (`Processor`):** Örököljön **protected** módon a `Component`-ből. Adjon hozzá egy `cores` (magok száma) változót.
* **Végponti osztály (`IntelCPU`):** Örököljön a `Processor`-ból.
* **A kihívás:** 1.  A `main` függvényben próbáld meg elérni az `IntelCPU` objektumon keresztül a `serialNumber`-t. Miért nem sikerül?
2.  Írj egy olyan metódust az `IntelCPU`-ba, ami képes kiírni a sorozatszámot.
3.  Módosítsd a `Processor` öröklődését `private`-ra, és figyeld meg, hogy az `IntelCPU` még látja-e a sorozatszámot!

---

### 2. Feladat: Bankszámlák és Tranzakció-láncolat

**Cél:** Összetett konstruktor-láncolat és paraméterátadás kezelése.

* **`Account`:** Konstruktora várjon egy `accountNumber`-t és egy `owner`-t. Legyen egy `protected` `balance` változója (alapértelmezett: 0).
* **`SavingsAccount`:** Örököljön az `Account`-ból. A konstruktora várjon pluszban egy `interestRate`-et (kamatláb).
* **`TimedSavingsAccount`:** Örököljön a `SavingsAccount`-ból. A konstruktora kapjon még egy `lockDuration` (lekötési idő) paramétert is.
* **A kihívás:** * Implementáld a konstruktorokat úgy, hogy minden adat a megfelelő szinten tárolódjon el.
* Készíts egy `displayAllInfo()` metódust a legalsó osztályban, ami a szülőktől örökölt és a saját adatait is tárolja és kiírja.
* Figyelj arra, hogy a `balance` csak az `Account` metódusain keresztül legyen módosítható (pl. `deposit()`), de a leszármazottak lássák az értékét!

---

### 3. Feladat: Hibrid Autó (A Gyémánt-probléma előszobája)

**Cél:** Többszörös öröklődés kezelése névütközésekkel és specifikus inicializálással.

* **`ElectricMotor`:** Konstruktora várja az `voltage` értéket. Legyen egy `start()` metódusa, ami kiírja: "Electric motor humming...".
* **`CombustionEngine`:** Konstruktora várja a `fuelType` értéket. Legyen egy `start()` metódusa, ami kiírja: "V8 engine roaring...".
* **`HybridCar`:** Örököljön mindkettőből! A konstruktora kapja meg az összes paramétert (`voltage`, `fuelType`, `modelName`).
* **A kihívás:** 1.  Írj a `HybridCar`-ba egy `drive()` metódust, ami meghívja mindkét szülő `start()` metódusát.
2.  Mivel mindkét szülőnek van `start()` neve, a `HybridCar` objektumon keresztül hívva hiba lesz (`ambiguous`). Oldd meg a névfeloldást a `drive()`-on belül a hatókör operátor (`::`) segítségével!

---

### 4. Feladat: Intelligens Fegyverrendszer (Szelektív láthatóság)

**Cél:** A függvényelfedés (Overriding) és a szülői metódusok tudatos használata.

* **`Weapon`:** Legyen egy `fire()` metódusa, ami kiírja: "Lövedék kilőve." és csökkenti a lőszert.
* **`LaserWeapon`:** Örököljön a `Weapon`-ből. Legyen saját `fire()` metódusa ("Lézersugár aktiválva"), ami nem lőszert, hanem `battery` szintet csökkent.
* **`PlasmaRifle`:** Örököljön a `LaserWeapon`-ből.
* **A kihívás:** * Írj egy `overloadFire()` metódust a `PlasmaRifle`-be, ami egyszerre hívja meg a legfelső szülő (`Weapon`) lőszeres lövését ÉS a saját plazma lövését.
* Hogyan éred el a "nagyapa" (`Weapon`) `fire()` metódusát, ha az "apa" (`LaserWeapon`) már elfedte azt?
