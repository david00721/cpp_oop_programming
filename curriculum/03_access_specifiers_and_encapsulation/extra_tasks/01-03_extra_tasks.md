# 1. Feladat: Autókölcsönző Rendszer Szimulációja

A feladat egy egyszerűsített autókölcsönző adminisztrációs szoftverének elkészítése C++ nyelven. A rendszer célja az autók nyilvántartása, bérbeadása és a napi bevétel nyomon követése.

## 1. Az `Car` (Autó) osztály megvalósítása

Készítsen egy `Car` osztályt, amely a következő privát adattagokkal rendelkezik:

* `plate` (szöveg): Az autó rendszáma.
* `dailyFee` (lebegőpontos szám): Az autó bérlésének napi díja.
* `rented` (logikai): Jelzi, hogy az autó éppen bérbe van-e adva.

**Elvárt metódusok:**

* **Konstruktorok:** Alapértelmezett konstruktor (üres értékekkel) és paraméteres konstruktor a rendszám és a díj beállításához.
* `rent()`: Ha az autó nem foglalt, állítsa át az állapotát foglaltra és térjen vissza `true` értékkel. Ha már foglalt, írjon hibaüzenetet és térjen vissza `false` értékkel.
* `returnCar()`: Állítsa az autó állapotát bérbe adhatóról szabadra.
* `getFee()`: Térje vissza az autó bérleti díjával, de **csak akkor**, ha az autó jelenleg bérbe van adva (egyébként 0-t adjon vissza).
* `getPlate()` és `isAvailable()`: Getter metódusok az adatok eléréséhez.

## 2. A `RentalService` (Kölcsönző Szolgáltatás) osztály megvalósítása

Az osztály feladata egy fix méretű autópark kezelése (dinamikus memóriafoglalás nélkül). Használjon egy globális konstanst (`MAX_CARS = 5`) a tömb méretének meghatározásához.

**Adattagok:**

* Egy `Car` objektumokból álló fix méretű tömb.
* `carCount`: Egész szám, amely az aktuálisan tárolt autók számát mutatja.

**Elvárt metódusok:**

* `addCar(plate, fee)`: Új autó hozzáadása a parkhoz, amennyiben még nincs tele (ellenőrizze a `MAX_CARS` korlátot).
* `rentCar(plate)`: Keresse meg az autót rendszám alapján, és próbálja meg kikölcsönözni.
* `returnCarByPlate(plate)`: Keresse meg a rendszámot, és állítsa az autót újra szabaddá.
* `calculateDailyIncome()`: Számolja ki az összes éppen bérbe adott autó napi díjának összegét.
