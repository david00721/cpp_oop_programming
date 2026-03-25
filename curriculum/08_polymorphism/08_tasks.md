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
3. Származtass egy `Manager` osztályt. Neki legyen egy privát `double bonus` adattagja. Írd felül a `calculatePay()` metódust úgy, hogy a `baseSalary + bonus` értékkel térjen vissza. **Mivel ez a menedzseri fizetési formula kőbe van vésve, használd a `final` kulcsszót a metóduson, hogy egyetlen jövőbeli alosztály (pl. `SeniorManager`) se tudja ezt a logikát felülírni!**
4. Származtass egy `Intern` (Gyakornok) osztályt. **Mivel a gyakornok a hierarchia legalja, garantáld a `final` kulcsszóval, hogy magából az `Intern` osztályból már ne lehessen tovább származtatni (ne lehessen pl. `JuniorIntern` osztályt létrehozni)!** A gyakornok csak a fizetés felét kapja... *(a többi marad a régi)*.
5. A `main`-ben hozz létre egy `Employee*` tömböt, tegyél bele egy sima alkalmazottat, egy menedzsert és egy gyakornokot, majd hívd meg mindegyikre a fizetés-kalkuláló függvényt!

## 6. Feladat: Űrflotta Szimulátor

**A probléma leírása:**
Egy sci-fi játékhoz kell megtervezned a hajóflottát kezelő alrendszert. Minden űrhajónak (`Starship`) van egy neve (`name`) és egy kapitánya (`captain`). A rendszernek képesnek kell lennie arra, hogy bármilyen típusú hajónak kiadja a küldetés indítása (`launchMission()`) parancsot, valamint le kell tudnia kérdezni a hajó aktuális fenntartási költségét (`calculateMaintenance()`) kreditben.

Tervezz egy objektumorientált hierarchiát, amely az alábbi hajótípusokat kezeli:
1. **Felfedező (`Explorer`):** Rendelkezik egy kutatási bónusz (`researchBonus`) szorzóval. A fenntartási költsége fix 2000 kredit, de a kutatási bónusz (pl. 0.25) arányában ez csökken (vagyis 2000 - 2000 * 0.25). Küldetés indításakor valami felfedezéssel kapcsolatos üzenetet ír ki.
2. **Hadihajó (`Warship`):** Van egy tűzerő (`firepower`) értéke. A fenntartási költsége magas: 5000 kredit alapdíj, plusz a tűzerő minden pontja után további 50 kredit. Küldetéskor a fegyverrendszerek élesítését jelenti be.
3. **Teherszállító (`CargoShip`):** Rendelkezik egy raktér-kapacitás (`capacityTons`) értékkel. A fenntartási költsége az alap 1000 kredit, plusz tonnánként 10 kredit. Küldetéskor a rakomány rögzítését és az indulást jelzi.

**Elvárások a főprogramban (`main`):**
Hozd létre a flotta központi nyilvántartását (egy 3 elemes, dinamikusan allokált objektumokat tároló klasszikus tömböt, például `fleet` néven). Töltsd fel a tömböt egy-egy hajóval a fenti típusokból. Egyetlen közös iteráció (ciklus) segítségével indítsd el az összes hajó küldetését (`launchMission()`), és egyúttal számold ki (majd a végén írd ki) az egész flotta összesített fenntartási költségét (`totalMaintenance`). Ügyelj a memóriaszivárgás elkerülésére a program végén a megfelelő virtuális destruktorok és a `delete` használatával!

## 7. Feladat: Drónraj Szinergia

**A probléma leírása:**
Az űrflotta védelmét autonóm drónok (`Drone`) látják el. Minden drón a gyártáskor kap egy egyedi, megváltoztathatatlan sorozatszámot (`serialNumber`).

Minden drónnak van egy harci ereje, amit a `getCombatPower()` metódussal lehet lekérdezni. 
A rendszernek képesnek kell lennie arra, hogy két drón harci erejét egy egyszerű összeadás operátorral összevonja! 

Két specifikus dróntípust kell leprogramoznod:
1. **Lézer Drón (`LaserDrone`):** Rendelkezik egy akkumulátor szinttel (`double batteryLevel`). A harci ereje a következőképpen számítandó: `batteryLevel * 1.5`.
2. **Plazma Drón (`PlasmaDrone`):** Rendelkezik egy maghőmérséklet adattaggal (`double coreTemperature`). A harci ereje: `coreTemperature * 2.5`.

**Elvárások a főprogramban (`main`):**
Hozd létre a drónrajt (egy 2 elemes tömböt). Dinamikusan példányosíts egy lézer és egy plazma drónt, majd tedd be őket a tömbbe. Írasd ki külön-külön a harci erejüket a virtuális metóduson keresztül. Végül add össze a két objektumot, és írd ki a kombinált harci erőt. Gondoskodj a memóriafelszabadításról!

## 8. Feladat: RPG Varázslatrendszer (Maximumkeresés és Operátor-túlterhelés)

**A probléma leírása:**
Egy fantasy RPG játék varázslatkezelő rendszerét kell megvalósítanod. Minden varázslatnak (`Spell`) van egy neve, ami a létrehozás pillanatában dől el, és utána már **soha nem változhat meg**.

A rendszernek minden varázslat esetén egységesen tudnia kell:
1. Elsütni a varázslatot (egyedi akciót/szöveget végrehajtani).
2. Megmondani, hogy pontosan mennyi manába kerül az adott varázslat elmondása (egész számként).

A játék logikájához elengedhetetlen, hogy két varázslatot közvetlenül össze tudjunk hasonlítani a mana-költségük alapján. Készítsd fel az ősosztályt arra, hogy a **nagyobb-mint (`>`) operátorral** el lehessen dönteni két varázslatról, hogy melyik a drágább! Az összehasonlításnak a leszármazottak által egyedileg (dinamikusan) számolt mana-költségeken kell alapulnia.

Származtass két konkrét varázslat típust:
1. **Tűzlabda (`Fireball`):** Rendelkezik egy sebzés értékkel. A mana-költsége mindig a sebzés értékének a fele. Elsütéskor írja ki a varázslat nevét és a kiosztott sebzést.
2. **Gyógyító Hullám (`HealingWave`):** Rendelkezik egy gyógyító erő értékkel. A mana-költsége a gyógyító erő 80%-a (egész számra csonkítva). Elsütéskor írja ki a varázslat nevét és a visszatöltött életerőt.

**Elvárások a főprogramban (`main`):**
1. Hozz létre egy 3 elemből álló, polimorfikus varázslatkönyvet (tömböt), és töltsd fel dinamikusan létrehozott varázslatokkal vegyesen.
2. Egyetlen ciklus segítségével süsd el a könyvben található összes varázslatot.
3. Egy klasszikus maximumkeresés algoritmussal találd meg a varázslatkönyv legdrágább (legtöbb manát igénylő) varázslatát! Az algoritmusban a feltételvizsgálatnál **kötelező a saját magad által túlterhelt `>` operátort használni** a varázslat-objektumok összehasonlítására. 
4. Írd ki a megtalált legdrágább varázslat nevét és költségét, majd gondoskodj a lefoglalt erőforrások megfelelő takarításáról!
