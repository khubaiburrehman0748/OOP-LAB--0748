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

       
        if (type == "AutonomousCar" || type == "ElectricVehicle") {
            cout << "ID: " << id << " | Type: " << type;
            
            size_t colonPos = extraData.find(':');
            if (colonPos != string::npos) {
                string valueStr = extraData.substr(colonPos + 1);
                
                if (type == "AutonomousCar") {
                    try {
                        float softwareVersion = stof(valueStr);
                        cout << " | Software Version: " << softwareVersion << endl;
                    } catch (...) {
                        cout << " | Invalid software version format" << endl;
                    }
                }
                else if (type == "ElectricVehicle") {
                    try {
                        int batteryCapacity = stoi(valueStr);
                        cout << " | Battery Capacity: " << batteryCapacity << " kWh" << endl;
                    } catch (...) {
                        cout << " | Invalid battery capacity format" << endl;
                    }
                }
            } else {
                cout << " | Invalid ExtraData format (missing colon)" << endl;
            }
        }
    }
    
    in.close();
    return 0;
}
