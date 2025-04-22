#include <iostream>
#include <string>
using namespace std;

class Shipment {
public:
    string trackingNumber;
    double weight;

    virtual double estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
};

class AirFreight : public Shipment {
public:
    AirFreight(string tn, double w) {
        trackingNumber = tn;
        weight = w;
    }

    double estimateDeliveryTime() {
        return weight * 2.0;
    }

    void showDetails() {
        cout << "Shipment Type: Air Freight" << endl;
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string tn, double w) {
        trackingNumber = tn;
        weight = w;
    }

    double estimateDeliveryTime() {
        return weight * 5.0;
    }

    void showDetails() {
        cout << "Shipment Type: Ground Shipment" << endl;
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

int main() {
    cout << "24K-0748\nKHUBAIB UR REHMAN\n" << endl;

    Shipment* s1 = new AirFreight("AIR123", 10.5);
    Shipment* s2 = new GroundShipment("GRD456", 10.5);

    s1->showDetails();
    cout << "Estimated Delivery Time: " << s1->estimateDeliveryTime() << " hours\n" << endl;

    s2->showDetails();
    cout << "Estimated Delivery Time: " << s2->estimateDeliveryTime() << " hours\n" << endl;

    delete s1;
    delete s2;

    return 0;
}
