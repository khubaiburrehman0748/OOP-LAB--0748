#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Product {
public:
    int id;
    string name;
    int quantity;

    Product(int id, string name, int quantity) {
        this->id = id;
        this->name = name;
        this->quantity = quantity;
    }
};

class Warehouse {
public:
    vector<Product> products;

    void addProduct(int id, string name, int quantity) {
        products.push_back(Product(id, name, quantity));
    }

    void sortProducts() {
        sort(products.begin(), products.end(), [](Product &a, Product &b) {
            return a.name < b.name;
        });
    }

    void searchProduct(int id) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].id == id) {
                cout << "Product ID: " << products[i].id << endl;
                cout << "Name: " << products[i].name << endl;
                cout << "Quantity: " << products[i].quantity << endl;
                cout << "-------------------------" << endl;
                return;
            }
        }
        cout << "Product not found." << endl;
    }

    void displayProducts() {
        for (int i = 0; i < products.size(); i++) {
            cout << "Product ID: " << products[i].id << endl;
            cout << "Name: " << products[i].name << endl;
            cout << "Quantity: " << products[i].quantity << endl;
            cout << "-------------------------" << endl;
        }
    }
};

int main() {
    Warehouse warehouse;
    warehouse.addProduct(101, "Chair", 50);
    warehouse.addProduct(102, "Table", 30);
    warehouse.addProduct(103, "Laptop", 20);

    cout << "Before sorting:" << endl;
    warehouse.displayProducts();

    warehouse.sortProducts();
    cout << "After sorting:" << endl;
    warehouse.displayProducts();

    cout << "Searching for product ID 102:" << endl;
    warehouse.searchProduct(102);

    return 0;
}