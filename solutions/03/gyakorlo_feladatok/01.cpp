#include <iostream>
#include <cassert>
#include <sstream>
#include <string>

// Global constants for stack-based array sizes
const int MAX_CARS = 5;

class Car {
private:
    std::string plate;
    double dailyFee;
    bool rented;

public:
    // Default constructor
    Car() {
        plate = "";
        dailyFee = 0.0;
        rented = false;
    }

    Car(std::string p, double fee) : plate(p), dailyFee(fee), rented(false) {}

    bool rent() {
        if (rented) {
            std::cout << "Car " << plate << " is already rented!\n";
            return false;
        }
        rented = true;
        return true;
    }

    void returnCar() {
        rented = false;
    }

    bool isAvailable() const {
        return !rented;
    }

    double getFee() const {
        // Only returns fee if the car is currently rented
        return rented ? dailyFee : 0;
    }

    std::string getPlate() const {
        return plate;
    }
};

class RentalService {
private:
    Car cars[MAX_CARS]; // Fixed size array on the stack
    int carCount;

public:
    RentalService() {
        carCount = 0;
    }

    // Add a car to the stack-based array
    void addCar(const std::string& plate, double fee) {
        if (carCount < MAX_CARS) {
            cars[carCount] = Car(plate, fee);
            carCount++;
        } else {
            std::cout << "Service full, cannot add more cars.\n";
        }
    }

    bool rentCar(const std::string plate) {
        for (int i = 0; i < carCount; i++) {
            if (cars[i].getPlate() == plate) {
                std::cout << "Attempting to rent: " << plate << "\n";
                return cars[i].rent();
            }
        }
        std::cout << "Car with plate " << plate << " not found.\n";
        return false;
    }

    void returnCar(const std::string plate) {
        for (int i = 0; i < carCount; i++) {
            if (cars[i].getPlate() == plate) {
                cars[i].returnCar();
                std::cout << "Car " << plate << " has been returned.\n";
                return;
            }
        }
    }

    void returnCarByPlate(const std::string& plate) {
        for (int i = 0; i < carCount; i++) {
            if (cars[i].getPlate() == plate) {
                cars[i].returnCar();
            }
        }
    }

    double calculateDailyIncome() const {
        double total = 0;
        for (int i = 0; i < carCount; i++) {
            total += cars[i].getFee();
        }
        return total;
    }
};

// --- Test Suite Class ---
class RentalServiceTester {
public:
    static void runAllTests() {
        std::cout << "Starting tests...\n";
        
        testBasicRental();
        testDoubleRentalFails();
        testMultipleCars();
        testCarNotFound();
        testEmptyService();
        testReturnCar();
        testMaxCapacity();
        testMultipleIncomes();

        std::cout << "\n==============================\n";
        std::cout << "  ALL TESTS PASSED SUCCESSFULLY\n";
        std::cout << "==============================\n";
    }

private:
    static void testBasicRental() {
        RentalService service;
        service.addCar("ABC-123", 50.0);
        assert(service.rentCar("ABC-123") == true);
        assert(service.calculateDailyIncome() == 50.0);
    }

    static void testDoubleRentalFails() {
        RentalService service;
        service.addCar("ABC-123", 50.0);
        assert(service.rentCar("ABC-123") == true);
        assert(service.rentCar("ABC-123") == false);
    }

    static void testMultipleCars() {
        RentalService service;
        service.addCar("ABC-123", 50.0);
        service.addCar("XYZ-999", 70.0);
        assert(service.rentCar("ABC-123") == true);
        assert(service.rentCar("XYZ-999") == true);
        assert(service.calculateDailyIncome() == 120.0);
    }

    static void testCarNotFound() {
        RentalService service;
        service.addCar("ABC-123", 50.0);
        assert(service.rentCar("UNKNOWN-111") == false);
    }

    static void testEmptyService() {
        RentalService service;
        assert(service.calculateDailyIncome() == 0.0);
    }

    static void testReturnCar() {
        RentalService service;
        service.addCar("ABC-123", 50.0);
        service.rentCar("ABC-123");
        service.returnCarByPlate("ABC-123");
        assert(service.calculateDailyIncome() == 0.0);
        assert(service.rentCar("ABC-123") == true);
    }

    static void testMaxCapacity() {
        RentalService service;
        for (int i = 0; i < MAX_CARS; i++) {
            service.addCar("CAR-" + std::to_string(i), 50.0);
        }
        // This will print the "Service full" message
        service.addCar("OVER-LIMIT", 50.0); 
    }

    static void testMultipleIncomes() {
        RentalService service;
        service.addCar("CAR-1", 30.0);
        service.addCar("CAR-2", 40.0);
        service.addCar("CAR-3", 50.0);
        service.rentCar("CAR-1");
        service.rentCar("CAR-3");
        assert(service.calculateDailyIncome() == 80.0);
    }
};

int main() {
    // Calling the static method of the test class
    RentalServiceTester::runAllTests();
    return 0;
}
