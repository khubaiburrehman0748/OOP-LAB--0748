#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream in("vehicles.txt");
    string line;
    
    getline(in, line);
    
    while (getline(in, line)) {
        if (line.empty()) continue;
        
        istringstream iss(line);
        string type, id, name, yearStr, extraData, certification;
        
        getline(iss, type, ',');
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, yearStr, ',');
        getline(iss, extraData, ',');
        getline(iss, certification);

        cout << "ID: " << id << " | Type: " << type << endl;
        
        if (type == "AutonomousCar") {
            size_t colonPos = extraData.find(':');
            if (colonPos != string::npos) {
                string valueStr = extraData.substr(colonPos + 1);
                try {
                    float softwareVersion = stof(valueStr);
                    cout << "  Software Version: " << softwareVersion << endl;
                } catch (...) {
                    cout << "  [Error] Invalid software version format" << endl;
                }
            } else {
                cout << "  [Error] Missing colon in ExtraData" << endl;
            }
        }
        else if (type == "ElectricVehicle") {
            size_t colonPos = extraData.find(':');
            if (colonPos != string::npos) {
                string valueStr = extraData.substr(colonPos + 1);
                try {
                    int batteryCapacity = stoi(valueStr);
                    cout << "  Battery Capacity: " << batteryCapacity << " kWh" << endl;
                } catch (...) {
                    cout << "  [Error] Invalid battery capacity format" << endl;
                }
            } else {
                cout << "  [Error] Missing colon in ExtraData" << endl;
            }
        }
        else if (type == "HybridTruck") {
            size_t pipePos = extraData.find('|');
            if (pipePos != string::npos) {
                string cargoPart = extraData.substr(0, pipePos);
                size_t cargoColon = cargoPart.find(':');
                if (cargoColon != string::npos) {
                    try {
                        int cargo = stoi(cargoPart.substr(cargoColon + 1));
                        cout << "  Cargo Capacity: " << cargo << " kg" << endl;
                    } catch (...) {
                        cout << "  [Error] Invalid cargo capacity format" << endl;
                    }
                } else {
                    cout << "  [Error] Missing colon in cargo data" << endl;
                }

                string batteryPart = extraData.substr(pipePos + 1);
                size_t batteryColon = batteryPart.find(':');
                if (batteryColon != string::npos) {
                    try {
                        int battery = stoi(batteryPart.substr(batteryColon + 1));
                        cout << "  Battery Capacity: " << battery << " kWh" << endl;
                    } catch (...) {
                        cout << "  [Error] Invalid battery capacity format" << endl;
                    }
                } else {
                    cout << "  [Error] Missing colon in battery data" << endl;
                }
            } else {
                cout << "  [Error] Missing pipe separator in ExtraData" << endl;
            }
        }
        else {
            cout << "  [Error] Unknown vehicle type" << endl;
        }
        
        cout << "----------------------" << endl;
    }
    
    in.close();
    return 0;
}
