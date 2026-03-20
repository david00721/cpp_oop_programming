# C++ Polimorfizmus Gyakorló Feladatsor

## 1. Feladat: Statikus polimorfizmus (Függvény-túlterhelés)
**Téma:** Statikus kötés megvalósítása öröklődés nélkül.

**Feladat:**
1. Készíts két teljesen független osztályt: `LaserPrinter` és `InkjetPrinter` (ne legyen közös ősük).
2. Mindkét osztálynak legyen egy saját `printDocument()` metódusa, ami kiírja a konzolra, hogy az adott nyomtató épp nyomtat (pl. *"Laser printer is printing super fast"* és *"Inkjet printer is printing slowly"*).
3. Hozz létre az osztályokon kívül két darab azonos nevű, globális függvényt: `startPrinting(...)`. 
4. Az egyik függvény egy `LaserPrinter` referenciát várjon paraméterként, a másik egy `InkjetPrinter` referenciát. A függvények törzsében hívd meg a paraméterként kapott nyomtató `printDocument()` metódusát.
5. A `main` függvényben példányosíts egyet-egyet mindkét nyomtatóból, és hívd meg rájuk a `startPrinting` függvényt.

## 2. Feladat: Átállás Dinamikus Polimorfizmusra
**Téma:** Az 1. feladat átírása futási idejű polimorfizmusra (késői kötés).

**Feladat:**
1. Hozz létre egy `Printer` nevű absztrakt ősosztályt.
2. Definiálj benne egy `printDocument()` tisztán virtuális (pure virtual) függvényt, és ne feledkezz meg a virtuális destruktorról sem!
3. Módosítsd a `LaserPrinter` és az `InkjetPrinter` osztályokat úgy, hogy a `Printer` osztályból származzanak (`public` öröklődés). Használd az `override` kulcsszót a metódusok felülírásakor.
4. A globális `startPrinting` függvényeket **töröld ki**. Helyette a `main` függvényben hozz létre egy 2 elemű `Printer*` (mutató) tömböt.
5. A `new` operátorral dinamikusan hozz létre egy lézer- és egy tintasugaras nyomtatót, és tárold a címeiket a tömbben.
6. Egy `for` ciklussal menj végig a tömbön, és hívd meg mindegyik elemre a `printDocument()` metódust.
7. A program végén egy másik ciklussal szabadítsd fel a lefoglalt memóriát a `delete` segítségével!

## 3. Feladat: Az Okosotthon (A virtuális destruktor próbája)
**Téma:** A memóriaszivárgás elkerülése dinamikus allokáció esetén.

**Feladat:**
1. Készíts egy `SmartDevice` ősosztályt egy virtuális `turnOn()` metódussal és egy virtuális destruktorral. A konstruktor és a destruktor is írjon ki egy üzenetet a konzolra (pl. *"SmartDevice created"*).
2. Származtass belőle egy `SmartSpeaker` (okoshangszóró) osztályt.
3. A `SmartSpeaker` osztálynak legyen egy privát `int*` mutatója (`audioLog`). A konstruktorában a `new` operátorral foglalj le dinamikusan egy 10 elemű egész szám tömböt ennek a mutatónak (szimulálva a hangfelvételek tárolását), és írd ki, hogy *"SmartSpeaker created and memory allocated"*.
4. A `SmartSpeaker` destruktorában szabadítsd fel ezt a tömböt a `delete[]` segítségével, és írj ki egy üzenetet róla.
5. A `main`-ben hozz létre egy `SmartDevice*` mutatót, amely egy új `SmartSpeaker` objektumra mutat.
6. Hívd meg rá a `delete` utasítást. Futtasd le a programot, és ellenőrizd a konzolon, hogy a `SmartSpeaker` destruktora is lefutott-e! *(Opcionális: teszteld le úgy is, hogy leveszed a `virtual` szót az ős destruktoráról, és nézd meg, hogyan marad el a memória felszabadítása!)*

## 4. Feladat: Az Autópálya-fizetőkapu (Interfészek használata)
**Téma:** Szerződés kikényszerítése absztrakt osztályokkal.

**Feladat:**
1. Hozz létre egy `IVehicle` nevű interfészt (csak tisztán virtuális függvényeket és egy virtuális destruktort tartalmazzon). Legyen benne egy `double calculateToll() const = 0;` metódus.
2. Készíts egy `Car` osztályt, ami megvalósítja az interfészt. A `Car` útdíja legyen fixen `1500.0`.
3. Készíts egy `Truck` osztályt, aminek van egy `int weight` (súly tonnában) privát adattagja. Ezt a konstruktorban kapja meg. A kamion útdíja legyen: `weight * 500.0`.
4. A `main` függvényben hozz létre egy `IVehicle*` tömböt 3 elemmel. Töltsd fel dinamikusan létrehozott autókkal és kamionokkal.
5. Egy ciklus segítségével számold ki és add össze az összes jármű útdíját egy `totalToll` nevű változóba, majd írd ki a végösszeget. Végül takaríts ki a memóriában!

## 5. Feladat: Bérszámfejtő Rendszer
**Téma:** Ősosztálybeli adatok elérése és egyedi polimorf viselkedés.

**Feladat:**
1. Készíts egy `Employee` ősosztályt. Legyen egy `protected` (védett) adattagja: `double baseSalary`. Ezt a konstruktorból kapja meg.
2. Írj egy `virtual double calculatePay() const` metódust, ami alapértelmezetten visszaadja a `baseSalary`-t.
3. Származtass egy `Manager` osztályt. Neki legyen egy privát `double bonus` adattagja. Írd felül a `calculatePay()` metódust úgy, hogy a `baseSalary + bonus` értékkel térjen vissza.
4. Származtass egy `Intern` (Gyakornok) osztályt. A gyakornok csak a fizetés felét kapja, így az ő `calculatePay()` metódusa adja vissza a `baseSalary * 0.5` értéket.
5. A `main`-ben hozz létre egy `Employee*` tömböt, tegyél bele egy sima alkalmazottat, egy menedzsert és egy gyakornokot, majd hívd meg mindegyikre a fizetés-kalkuláló függvényt!

---