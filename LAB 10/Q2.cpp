#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream in("vehicles.txt");
    string line;
    
    if (!in.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    getline(in, line); //skip comment line ;) 
    
    while (getline(in, line)) {
        if (line.empty()) continue;
        
        istringstream iss(line);
        string type, id, name, year, extraData, certification;
        
        if (getline(iss, type, ',') &&
            getline(iss, id, ',') &&
            getline(iss, name, ',') &&
            getline(iss, year, ',') &&
            getline(iss, extraData, ',') &&
            getline(iss, certification)) {
            
            cout << "Type: " << type << "\n";
            cout << "ID: " << id << "\n";
            cout << "Name: " << name << "\n";
            cout << "Year: " << year << "\n";
            cout << "ExtraData: " << extraData << "\n";
            cout << "Certification: " << certification << "\n";
            cout << "----------------------\n";
        }
    }
    
    in.close();
    return 0;
}
