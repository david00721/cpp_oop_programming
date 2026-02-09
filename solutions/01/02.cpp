#include <iostream>

class Car {
public:
    std::string brand;
    std::string color;
    int year;

    // Car(std::string b, std::string c, int y) : brand(b), color(c), year(y) {}

    void honk();
};

void Car::honk() {
    std::cout << "Tuuut, tuuut!" << std::endl;
}

int main() {
    // Car carObj1("Toyota", "red", 2020);

    Car carObj1;
    carObj1.brand = "Toyota";
    carObj1.color = "red";
    carObj1.year = 2020;

    std::cout << "A " << carObj1.brand << " " << carObj1.color << " színű, " << carObj1.year << " évjáratú autó.\n";
    
    carObj1.honk();

    return 0;
}