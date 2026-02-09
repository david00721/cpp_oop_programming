#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string name;
    string color;
    int year;

public:
    // Konstruktor
    Car(string n, string c, int y) : name(n), color(c), year(y) {
        cout << "Car created: " << name << endl;
    }

    // Destruktor
    ~Car() {
        cout << "Goodbye, " << name << "." << endl;
    }

    // Getter metódusok
    string getName() const { return name; }
    string getColor() const { return color; }
    int getYear() const { return year; }
};

int main() {
    Car myCar("Tesla", "Red", 2023);
    cout << "Car details: " << myCar.getName() << ", " 
         << myCar.getColor() << ", " << myCar.getYear() << endl;
    
    return 0;
}