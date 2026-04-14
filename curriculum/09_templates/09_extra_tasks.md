# Feladatok

## 1. Feladat: Az Univerzális Összehasonlító

Készíts egy olyan rendszert, amely képes különböző típusú adathalmazok "szélsőértékeit" kezelni. A feladatod egy olyan függvény vagy struktúra létrehozása, amely kap egy tömböt (vagy listát) és visszaadja annak a legkisebb elemét.

A rendszernek működnie kell:
1. Egész számokkal (`int`).
2. Lebegőpontos számokkal (`double`).
3. Szöveges tartalommal (`std::string`), ahol az ábécérend szerinti legelső elemet keressük.

**Kiegészítés:** Gondolj bele, mi történik, ha egy saját magad által definiált `Pont(x, y)` osztályt kellene összehasonlítani. Hogyan tennéd alkalmassá a kódodat arra, hogy ilyenkor is helyesen működjön anélkül, hogy magát a kereső algoritmust módosítanád?

---

## 2. Feladat: Az Intelligens Tároló

Készíts egy olyan tároló osztályt (vagy struktúrát), amely pontosan **két** azonos típusú elemet képes befogadni. A tároló célja nemcsak az adatok megőrzése, hanem egy speciális szolgáltatás nyújtása: egy olyan függvény, amely a két elem közül a "nagyobbat" adja vissza.

**A követelmények:**
1. Működjön egész számokkal és tizedes törtekkel is.
2. Legyen képes kezelni egyedi objektumokat is (például egy `Auto` osztályt, ahol a sebesség dönt).
3. Ha a két elem egyenlő, bármelyiket visszaadhatja.
4. Ne használj fix típusokat a belső tárolásnál, hagyd, hogy a felhasználó döntse el a példányosításkor, mit szeretne benne tartani.

---

## 3. Feladat: Az Intelligens Statisztikai Gyűjtő

Készíts egy olyan osztályrendszert, amely képes különböző típusú adatsorokat tárolni egy `std::vector`-ban, és azokról alapvető információkat szolgáltatni. A rendszernek két fő részből kell állnia:

1.  **Egy alaposztály**: Ez felel az adatok tárolásáért (egy belső `std::vector` segítségével) és az elemek hozzáadásáért.
2.  **Származtatott osztályok**: Ezek az alaposztályból örökölnek, de specifikus típusokra rögzítik azt (például egy `IntegerStore` vagy egy `TextStore`).
3.  **Specifikus logika**: A származtatott osztályoknak legyen egy olyan függvénye, amely az adattípusra jellemző összesítést végez (pl. számoknál összegzés, szövegeknél a leghosszabb szó megkeresése).

---
