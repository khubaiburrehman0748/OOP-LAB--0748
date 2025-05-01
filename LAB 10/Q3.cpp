#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream in("vehicles.txt");
    string line;
    
    getline(in, line); 
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
        
        int year = stoi(yearStr);  
        
        cout << "Type: " << type << "\n";
        cout << "ID: " << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Year: " << year << " (converted to integer)\n"; 
        cout << "ExtraData: " << extraData << "\n";
        cout << "Certification: " << certification << "\n";
        cout << "----------------------\n";
    }
    
    in.close();
    return 0;
}
