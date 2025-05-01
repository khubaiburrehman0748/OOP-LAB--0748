#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile("large_log.txt");
    
    if (!inFile) {
        cerr << "Error: Could not open large_log.txt" << endl;
        return 1;
    }

    char buffer[11];
    if (inFile.read(buffer, 10)) {
        buffer[10] = '\0';
        cout << "First 10 chars: " << buffer << endl;
        cout << "Position after first read: " << inFile.tellg() << endl;
    }

    if (inFile.read(buffer, 10)) {
        buffer[10] = '\0';
        cout << "Next 10 chars: " << buffer << endl;
        cout << "Position after second read: " << inFile.tellg() << endl;
    }

    inFile.close();
    return 0;
}
