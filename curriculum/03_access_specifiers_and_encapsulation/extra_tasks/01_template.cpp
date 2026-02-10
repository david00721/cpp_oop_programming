#include <iostream>
#include <cassert>
#include <sstream>
#include <string>

// Global constants for stack-based array sizes
const int MAX_CARS = 5;

class Car {};

class RentalService {};

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
