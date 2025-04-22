#include <iostream>
#include <string>
using namespace std;

class MenuItem {
    public:
        string dishName;
        double price;

        virtual void showDetails() = 0;
        virtual void prepare() = 0;
};

class Appetizer : public MenuItem {
    public:
        Appetizer(string name, double p) {
            dishName = name;
            price = p;
        }

        void showDetails() {
            cout << "Dish Name: " << dishName << endl;
            cout << "Price: $" << price << endl;
        }

        void prepare() {
            cout << "Preparation: Cut vegetables, add dressing, and chill." << endl;
        }
};

class MainCourse : public MenuItem {
    public:
        MainCourse(string name, double p) {
            dishName = name;
            price = p;
        }

        void showDetails() {
            cout << "Dish Name: " << dishName << endl;
            cout << "Price: $" << price << endl;
        }

        void prepare() {
            cout << "Preparation: Cook meat, prepare sauce, and serve hot." << endl;
        }
};

int main() {
    cout << "24K-0748\nKHUBAIB UR REHMAN" << endl;

    MenuItem* item1;
    MenuItem* item2;

    Appetizer appetizerObj("Caesar Salad", 6.99);
    MainCourse mainCourseObj("Grilled Chicken", 12.49);

    item1 = &appetizerObj;
    item2 = &mainCourseObj;

    cout << "\n--- Appetizer ---" << endl;
    item1->showDetails();
    item1->prepare();

    cout << "\n--- Main Course ---" << endl;
    item2->showDetails();
    item2->prepare();

    return 0;
}
