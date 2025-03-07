#include <iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status;

public:
    void setDeviceDetails(int id, bool st) {
        deviceID = id;
        status = st;
    }

    void displayDetails() {
        cout << "Device ID: " << deviceID << "\nStatus: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : public Device {
protected:
    float screenSize;

public:
    void setPhoneDetails(float size) {
        screenSize = size;
    }

    void displayDetails() {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : public Device {
protected:
    bool heartRateMonitor;

public:
    void setWatchDetails(bool monitor) {
        heartRateMonitor = monitor;
    }

    void displayDetails() {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int stepCounter;

public:
    void setWearableDetails(int id, bool st, float size, bool monitor, int steps) {
        setDeviceDetails(id, st);
        setPhoneDetails(size);
        setWatchDetails(monitor);
        stepCounter = steps;
    }

    void displayDetails() {
        SmartPhone::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
        cout << "Step Counter: " << stepCounter << endl;
    }
};

int main() {
    SmartWearable device;
    int id, steps;
    bool status, monitor;
    float size;

    cout << "Enter Device ID: ";
    cin >> id;
    cout << "Enter Status (1 for On, 0 for Off): ";
    cin >> status;
    cout << "Enter Screen Size: ";
    cin >> size;
    cout << "Has Heart Rate Monitor? (1 for Yes, 0 for No): ";
    cin >> monitor;
    cout << "Enter Step Counter: ";
    cin >> steps;

    device.setWearableDetails(id, status, size, monitor, steps);

    cout << "\nSmart Wearable Details\n";
    device.displayDetails();

    return 0;
}
