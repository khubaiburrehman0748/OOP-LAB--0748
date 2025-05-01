#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile("sensor_log.txt");
    
    if (outFile.is_open()) {
        outFile << "Sensor1: 25.5C\n";
        cout << "Position after write 1: " << outFile.tellp() << endl;
        
        outFile << "Sensor2: 72.1F\n";
        cout << "Position after write 2: " << outFile.tellp() << endl;
        
        outFile << "Sensor3: 1013.2hPa\n";
        cout << "Position after write 3: " << outFile.tellp() << endl;
        
        outFile.close();
    } else {
        cerr << "Error opening file" << endl;
    }

    return 0;
}
