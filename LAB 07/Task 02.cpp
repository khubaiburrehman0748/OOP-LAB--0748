#include <iostream>
using namespace std;

class Product {
public:
    string productID;
    string productName;
    double price;
    int quantity;
    int stockQuantity;

    Product(string id, string name, double p, int q, int stock = 0) {
        productID = id;
        productName = name;
        price = p;
        quantity = q;
        stockQuantity = stock;
    }

    virtual void applyDiscount() {
    }

    virtual double calculateTotalPrice() {
        return price * quantity;
    }

    virtual void displayProductInfo() {
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }

    Product operator+(int extraQty) {
        Product temp = *this;
        temp.quantity += extraQty;
        return temp;
    }

    friend ostream& operator<<(ostream& out, Product& p) {
        out << "Product: " << p.productName << ", Total Price: " << p.calculateTotalPrice();
        return out;
    }
};

class Electronics : public Product {
private:
    int warrantyPeriod;
    string brand;
public:
    Electronics(string id, string name, double p, int q, int wp, string b)
        : Product(id, name, p, q) {
        warrantyPeriod = wp;
        brand = b;
    }

    void displayProductInfo() {
        Product::displayProductInfo();
        cout << "Brand: " << brand << endl;
        cout << "Warranty Period: " << warrantyPeriod << " years" << endl;
    }
};

class Clothing : public Product {
private:
    string size;
    string color;
    string fabricMaterial;
public:
    Clothing(string id, string name, double p, int q, string s, string c, string f)
        : Product(id, name, p, q) {
        size = s;
        color = c;
        fabricMaterial = f;
    }

    void applyDiscount() {
        price = price * 0.9;
    }

    void displayProductInfo() {
        Product::displayProductInfo();
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
        cout << "Fabric: " << fabricMaterial << endl;
    }
};

class FoodItem : public Product {
private:
    int expirationDays;
    double calories;
public:
    FoodItem(string id, string name, double p, int q, int exp, double cal)
        : Product(id, name, p, q) {
        expirationDays = exp;
        calories = cal;
    }

    void applyDiscount() {
        if (expirationDays < 5) {
            price *= 0.85; 
        }
    }

    void displayProductInfo() {
        Product::displayProductInfo();
        cout << "Expires in: " << expirationDays << " days" << endl;
        cout << "Calories: " << calories << " kcal" << endl;
    }
};

class Book : public Product {
private:
    string author;
    string genre;
public:
    Book(string id, string name, double p, int q, string a, string g)
        : Product(id, name, p, q) {
        author = a;
        genre = g;
    }

    void displayProductInfo() {
        Product::displayProductInfo();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    cout << "khubaib ur rehman \n24k-0748" << endl;

    Book b1("B101", "Clean Code", 1500, 2, "Robert C. Martin", "Programming");
    Electronics e1("E101", "Laptop", 95000, 1, 2, "HP");
    Clothing c1("C101", "T-Shirt", 1200, 3, "M", "Black", "Cotton");
    FoodItem f1("F101", "Bread", 200, 5, 3, 150);

    cout << "\n--- Book Details ---" << endl;
    b1.displayProductInfo();
    cout << b1 << endl;

    cout << "\n--- Electronics Details ---" << endl;
    e1.displayProductInfo();
    cout << e1 << endl;

    cout << "\n--- Clothing Details (Before Discount) ---" << endl;
    c1.displayProductInfo();
    c1.applyDiscount();
    cout << c1 << endl;

    cout << "\n--- Food Item Details (Before Discount) ---" << endl;
    f1.displayProductInfo();
    f1.applyDiscount();
    cout << f1 << endl;

    cout << "\n--- Bulk Order ---" << endl;
    Product bulkBread = f1 + 10; 
    cout << bulkBread << endl;

    return 0;
}
