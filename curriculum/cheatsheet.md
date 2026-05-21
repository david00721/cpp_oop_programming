## Cheatsheet

### 1. Ősosztály és Leszármaztatás (Polimorfizmus)

A legfontosabb alapszabály: **ha van virtuális függvényed, kötelező a virtuális destruktor**, különben memóriaszivárgás lép fel a polimorf törlésnél! Az adattagok védelmére a `private` (vagy `protected`) használatos, az inicializáláshoz pedig konstruktor inicializáló listát használunk (ez `const` adattagoknál kötelező).

```cpp
#include <iostream>
#include <string>

// --- ŐSOSZTÁLY ---
class Parent {
private:
    const std::string name; // Csak inicializálni lehet, utána nem változhat
    int value;

protected:
    // Konstansok, amiket a gyerekek is elérnek
    static constexpr double MULTIPLIER = 2.5; 

public:
    // Inicializáló lista
    Parent(std::string n, int v) : name(n), value(v) {}

    // VIRTUÁLIS DESTRUKTOR (Kötelező!)
    virtual ~Parent() {
        std::cout << "Os destruktor lefutott." << std::endl;
    }

    // Tisztán virtuális függvény (Absztrakt osztállyá teszi a Parent-et)
    virtual void doSomething() const = 0;

    // Getterek (const: jelzi, hogy nem módosítják az objektumot)
    std::string getName() const { return name; }
    int getValue() const { return value; }
    
    // Setter
    void setValue(int v) { value = v; }
};

// --- GYEREKOSZTÁLY ---
class Child : public Parent {
public:
    // Ős konstruktorának meghívása
    Child(std::string n, int v) : Parent(n, v) {}

    // Az 'override' kulcsszó megvéd az elgépelésektől
    ~Child() override {
        std::cout << "Gyerek destruktor lefutott." << std::endl;
    }

    // A tisztán virtuális függvény egyedi megvalósítása
    void doSomething() const override {
        std::cout << "Gyerek vagyok: " << getName() 
                  << ", ertek: " << (getValue() * MULTIPLIER) << std::endl;
    }
};

```

### 2. Operátortúlterhelések (Operator Overloading)

A leggyakoribb operátorok sablonjai. A `<<` operátort mindig az osztályon kívül kell megírni!

```cpp
class Entity {
private:
    int data;
public:
    Entity(int d) : data(d) {}

    // += operátor (Önmagára mutató referenciát ad vissza a láncolhatóságért)
    Entity& operator+=(const Entity& other) {
        this->data += other.data;
        return *this; 
    }

    // Prefix ++ (++obj)
    Entity& operator++() {
        this->data *= 2; // Feladatfüggő logika (pl. duplázás)
        return *this;
    }

    // Postfix ++ (obj++) -> A paraméterbeli 'int' csak jelzés a fordítónak!
    Entity operator++(int) {
        Entity temp = *this; // Eredeti állapot mentése
        this->data *= 2;     // Módosítás
        return temp;         // Régi állapot visszaadása
    }

    int getData() const { return data; }
};

// Globális << operátor formázott kiíratáshoz
std::ostream& operator<<(std::ostream& os, const Entity& obj) {
    os << "Entity data: " << obj.getData();
    return os;
}

```

### 3. Heterogén Kollekció, `dynamic_cast` és Memóriatakarítás

Mutatókat tároló vektor használata, futásidejű típusellenőrzés, és a legfontosabb: a memóriaszivárgás elkerülése (akár fordított sorrendű törléssel).

```cpp
#include <vector>

void manageCollection() {
    // Őstípust tároló vektor (különböző gyerekeket tehetünk bele)
    std::vector<Parent*> collection;

    // Dinamikus memóriafoglalás
    collection.push_back(new Child("Elso", 10));
    collection.push_back(new Child("Masodik", 20));

    // Iterálás és polimorfizmus
    for (const auto* item : collection) {
        item->doSomething(); 

        // dynamic_cast: Kiderítjük, hogy az ős-mutató valójában egy Child példányra mutat-e
        const Child* childPtr = dynamic_cast<const Child*>(item);
        if (childPtr != nullptr) {
            std::cout << "Ez bizonyitottan egy Child objektum!" << std::endl;
        }
    }

    // MEMÓRIAFELSZABADÍTÁS (Fordított sorrendű törlés, ha a feladat kéri)
    for (auto it = collection.rbegin(); it != collection.rend(); ++it) {
        delete *it;   // Felszabadítjuk a memóriát
        *it = nullptr; // Biztonsági okokból nullázzuk a mutatót
    }
    collection.clear(); // Vektor kiürítése
}

```

### 4. Validáció és Kivételkezelés (`try-catch`)

Ha valamilyen invariáns sérül (pl. negatív kor, 0 nevező), a konstruktorban vagy a setterben dobunk egy kivételt, amit a főprogramban elkapunk.

```cpp
#include <stdexcept>

class ValidatedObject {
private:
    int positiveValue;
public:
    ValidatedObject(int val) {
        if (val < 0) {
            // Kivétel dobása
            throw std::invalid_argument("Az ertek nem lehet negativ!");
        }
        positiveValue = val;
    }
};

int main() {
    try {
        ValidatedObject obj(-5); // Ez azonnal hibát dob
        
    } catch (const std::invalid_argument& e) {
        // Specifikus hiba elkapása
        std::cerr << "Validacios hiba: " << e.what() << std::endl;
        
    } catch (const std::exception& e) {
        // Minden más standard hiba elkapása (jó gyakorlat)
        std::cerr << "Ismeretlen hiba: " << e.what() << std::endl;
    }
    
    return 0;
}

```

### 5. Osztálysablon (Template)

Általános adatszerkezetek (pl. mátrix, halmaz) leírásához, ahol a tárolt adat típusa (T) rugalmas.

```cpp
#include <vector>

// 'T' a tetszőleges típus (pl. int, double, vagy akár egy saját osztály)
template <typename T>
class GenericContainer {
private:
    std::vector<T> elements;
public:
    GenericContainer(std::vector<T> initialElements) : elements(initialElements) {}

    // Visszaadja a legnagyobb elemet (feltételezi, hogy a T típusra működik a < operátor)
    T getMaximum() const {
        if (elements.empty()) throw std::runtime_error("Ures a kontener!");
        
        T maxObj = elements[0];
        for (const auto& item : elements) {
            if (maxObj < item) {
                maxObj = item;
            }
        }
        return maxObj;
    }
};

```

### 6. Trükk: Példányosítás tiltása absztrakció nélkül

Ha a feladat azt kéri, hogy az ősosztályból *ne lehessen objektumot létrehozni, de ne is legyen benne tisztán virtuális ( = 0) függvény*, akkor a konstruktort védetté kell tenni.

```cpp
class NonInstantiableBase {
protected:
    // A protected konstruktort a main() nem éri el, de a leszármazottak igen!
    NonInstantiableBase(int v) : value(v) {}
    
public:
    int value;
    virtual ~NonInstantiableBase() {}
    
    // Nincs tisztán virtuális függvény, mégsem példányosítható!
};

```