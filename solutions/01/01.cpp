#include <iostream>
#include <string>

class Car
{
public:
    std::string brand;
    std::string model;
    int year;
};

int main()
{
    Car carObj1;

    carObj1.brand = "Toyota";
    carObj1.model = "Camry";
    carObj1.year = 2023;

    std::cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";

    return 0;
}