#include <iostream>
using namespace std;

struct Item {
    string itemName;
    string itemID;
    int stock;
    float unitPrice;
};

void inputItems(Item* list, int count, float &inventoryValue) {
    for (int i = 0; i < count; i++) {
        cout << "Enter details for item " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> list[i].itemName;
        cout << "ID: ";
        cin >> list[i].itemID;
        cout << "Quantity: ";
        cin >> list[i].stock;
        cout << "Price per unit: ";
        cin >> list[i].unitPrice;

        inventoryValue += list[i].unitPrice * list[i].stock;
    }
}

int main() {
    int itemCount;
    float totalInventoryValue = 0;

    cout << "How many items are in the inventory? ";
    cin >> itemCount;

    Item* inventory = new Item[itemCount];

    inputItems(inventory, itemCount, totalInventoryValue);

    cout << "Total inventory value: $" << totalInventoryValue << endl;

    delete[] inventory;

    return 0;
}
