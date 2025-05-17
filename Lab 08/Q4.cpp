#include <iostream>
#include <string>
using namespace std;

class Car {
    string model;
    double price;
public:
    Car(string m = "", double p = 0.0) {
        model = m;
        price = p;
    }
    friend class InventoryManager;
    friend void comparePrice(Car, Car);
};

class InventoryManager {
public:
    void updateDetails(Car &c, string newModel, double newPrice) {
        c.model = newModel;
        c.price = newPrice;
    }

    void displayDetails(Car c) {
        cout << "Model: " << c.model << endl;
        cout << "Price: " << c.price << endl;
    }
};

void comparePrice(Car c1, Car c2) {
    if (c1.price > c2.price)
        cout << c1.model << " is more expensive." << endl;
    else if (c2.price > c1.price)
        cout << c2.model << " is more expensive." << endl;
    else
        cout << "Both cars have the same price." << endl;
}

int main() {
    Car car1("Suzuki Mehran", 950000);
    Car car2("Toyota Corolla", 3500000);

    InventoryManager manager;
    manager.displayDetails(car1);
    manager.displayDetails(car2);

    comparePrice(car1, car2);

    manager.updateDetails(car1, "Suzuki Cultus", 1800000);
    manager.updateDetails(car2, "Honda Civic", 4200000);

    comparePrice(car1, car2);

    return 0;
}
