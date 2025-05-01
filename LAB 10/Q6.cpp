#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main() {
    InventoryItem original;
    original.itemID = 1001;
    strncpy(original.itemName, "SampleItem", sizeof(original.itemName));

    ofstream out("inventory.dat", ios::binary);
    out.write(reinterpret_cast<char*>(&original), sizeof(InventoryItem));
    out.close();

    InventoryItem loaded;
    ifstream in("inventory.dat", ios::binary);
    in.read(reinterpret_cast<char*>(&loaded), sizeof(InventoryItem));
    in.close();

    cout << "ID: " << loaded.itemID << "\nName: " << loaded.itemName << endl;

    return 0;
}
