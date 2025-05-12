#include <iostream>
#include <exception>
using namespace std;

class NegativeStockException : public exception {};
class OverCapacityException : public exception {};

template<typename T>
class InventoryItem {
    T stock;
    T maxStock;
public:
    InventoryItem(T maxVal) : maxStock(maxVal), stock(0) {}
    void setStock(T value) {
        if (value < 0)
            throw NegativeStockException();
        if (value > maxStock)
            throw OverCapacityException();
        stock = value;
    }
};

int main() {
    InventoryItem<int> item(100);
    cout << "Attempting to set stock to -5..." << endl;
    try {
        item.setStock(-5);
    }
    catch (const exception& e) {
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    }
    cout << "Attempting to set stock to 120 (max 100)..." << endl;
    try {
        item.setStock(120);
    }
    catch (const exception& e) {
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    }
    return 0;
}
