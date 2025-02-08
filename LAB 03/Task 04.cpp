#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    string model;
    int fuelcapacity;
    int currentfuelcapacity;

    void refuel(int fuel) {
        if (fuel + currentfuelcapacity <= fuelcapacity) {
            currentfuelcapacity += fuel;
            cout << "Refueled " << fuel << " liters. Current fuel level: " << currentfuelcapacity << " liters.\n";
        } else {
            cout << "Fuel tank capacity exceeded! Max capacity is " << fuelcapacity << " liters.\n";
        }
    }

    void checkFuelStatus() {
        cout << "Current fuel level: " << currentfuelcapacity << " liters.\n";
    }

    void drive(int distance) {
        int fuelRequired = distance / 15;
        if (fuelRequired <= currentfuelcapacity) {
            currentfuelcapacity -= fuelRequired;
            cout << "You have driven " << distance << " km. Fuel used: " << fuelRequired << " liters.\n";
        } else {
            cout << "Not enough fuel! You need " << (fuelRequired - currentfuelcapacity) << " more liters for this journey.\n";
        }
    }
};

int main() {
    Car car1;
    car1.brand = "Hyundai";
    car1.model = "Sonata";
    car1.fuelcapacity = 50;
    car1.currentfuelcapacity = 10;

    car1.refuel(30);
    car1.checkFuelStatus();
    car1.drive(200);
    car1.checkFuelStatus();
    car1.drive(500);
    car1.checkFuelStatus();

    return 0;
}
