### 1. Feladat: A "Biztonságos" Értékcsere (Swap)
**Cél:** A pointerek és referenciák közötti különbség megértése.
* **Feladat:** Írj két függvényt a két szám megcserélésére!
    * `void swapByPointer(int* a, int* b)`: Használjon pointereket és dereferálást. A main-ben ellenőrizd, hogy a pointer nem `nullptr`, mielőtt hívnád!
    * `void swapByReference(int& a, int& b)`: Használjon referenciákat.
* **Kimenet:** A program írja ki a számokat a csere előtt és után is.

---

### 2. Feladat: Tömbstatisztika Pointer-aritmetikával
**Cél:** Annak megértése, hogy a tömb neve egy pointer, és hogyan lehet rajta "lépegetni".
* **Feladat:** Írj egy függvényt, ami egy egészekből álló tömböt kap meg, de a paramétere egy pointer legyen (`int* start`) és a tömb mérete (`int size`).
    * A függvény számolja ki a tömb elemeinek átlagát és keresse meg a legkisebb elemet.
    * **Kötöttség:** A függvényen belül **tilos** a szögletes zárójel `[]` használata! Minden elérést pointer-aritmetikával oldj meg (pl. `*(start + i)`).
* **Bónusz:** Írasd ki minden elem memóriacímét a main-ben, hogy lássák a 4 bájtos ugrásokat.

---

### 3. Feladat: Dinamikus Névsoroló
**Cél:** A `new` és `delete` operátorok, valamint a futásidejű memóriafoglalás gyakorlása.
* **Feladat:** Kérdezd meg a felhasználótól, hány nevet (string) szeretne rögzíteni.
    * Foglalj le dinamikusan egy pontosan ekkora tömböt a heap-en.
    * Kérd be a neveket, majd írasd ki őket fordított sorrendben.
    * **Fontos:** A program végén szabadítsd fel a memóriát, hogy ne legyen szivárgás!


---

### 4. Feladat: A "Null-terminátor" detektív
**Cél:** A C-stílusú karaktertömbök (char*) és a pointerek kapcsolata.
* **Feladat:** Írj egy saját függvényt, ami megszámolja egy karakterlánc hosszát: `int myStrLen(const char* s)`.
    * A függvény egy pointert kap a szöveg elejére. 
    * Egy `while` ciklussal lépkedj előre a memóriában, amíg el nem éred a lezáró null karaktert (`'\0'`).
    * Add vissza a megtett lépések számát.

---

### 5. Feladat: Dinamikus Tömb Átméretezése (Haladó)
**Cél:** Megérteni, hogyan működnek a háttérben a modern konténerek (mint a `vector`).
* **Feladat:** Hozz létre egy 5 elemű dinamikus tömböt. Töltsd fel adatokkal.
* Írj egy logikát, ami "átméretezi" ezt a tömböt 10 eleműre:
    1.  Foglalj egy új, 10 elemű területet.
    2.  Másold át az eredeti 5 elemet az új helyre.
    3.  Szabadítsd fel a régi, 5 elemű területet (`delete[]`).
    4.  Állítsd az eredeti pointert az új területre.
* Írasd ki az új tömb tartalmát és címeit.

---