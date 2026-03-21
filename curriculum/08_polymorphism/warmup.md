**Feladat leírása:**
1. Hozz létre egy `Cargo` (Rakomány) ősosztályt. Legyen egy `protected` láthatóságú `int weight` (súly) adattagja, amit a konstruktorán keresztül kap meg.
2. Származtass belőle egy `Crate` (Láda) osztályt.
3. A `Crate` osztályban írd meg (terheld túl) az összeadás operátort (`operator+`). Ez a metódus várjon paraméterként egy másik `Crate` objektumot, és adjon vissza egy **teljesen új** `Crate` objektumot, amelynek a súlya a két összeadott láda súlyának összege.
4. Készíts egy `printWeight()` metódust is a `Crate` osztályba a kiíratáshoz.
5. A `main` függvényben hozz létre két ládát (pl. 50 és 30 kg súllyal), add össze őket a `+` jellel egy harmadik ládába, és írd ki mindhárom láda súlyát.

**Konzolos kimenet futtatáskor:**
```text
--- Warm-up: Operator Overloading ---
First Crate weight: 50 kg
Second Crate weight: 30 kg
Combined (Result of crate1 + crate2) Crate weight: 80 kg
```
