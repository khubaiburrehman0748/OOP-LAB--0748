#include <iostream>
#include <string>

using namespace std;

class AlarmSystem {
public:
    string securityLevel;

    AlarmSystem(string level) {
        securityLevel = level;
    }
};

class SmartHome {
public:
    string homeName;
    AlarmSystem alarm;

    SmartHome(string name, string alarmLevel) : homeName(name), alarm(alarmLevel) {}

    void display() {
        cout << "Smart Home: " << homeName << endl;
        cout << "Alarm Security Level: " << alarm.securityLevel << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    SmartHome home1("Villa", "High");
    SmartHome home2("Apartment", "Medium");

    home1.display();
    home2.display();

    return 0;
}