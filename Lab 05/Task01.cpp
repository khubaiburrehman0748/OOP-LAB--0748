#include <iostream>
#include <string>

using namespace std;

class Apartment {
private:
    int id;
    string address;
    string* ownerName;

public:
    Apartment(int id, string addr, string owner) {
        this->id = id;
        this->address = addr;
        this->ownerName = new string(owner);
    }

    Apartment( Apartment &other) {
        this->id = other.id;
        this->address = other.address;
        this->ownerName = new string(*other.ownerName);
    }

    void display()  {
        cout << "Apartment ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Owner's Name: " << *ownerName << endl;
        cout << "-------------------------" << endl;
    }

    void changeOwner(string& newOwner) {
        *ownerName = newOwner;
    }
};

int main() {
    Apartment apt1(101, "DHA ph 7 karachi", "khubaib ur rehman");
    cout << "Original Apartment:" << endl;
    apt1.display();

    Apartment apt2 = apt1;
    cout << "Copied Apartment:" << endl;
    apt2.display();

    string newOwner = "khubaib ur rehman";
    apt2.changeOwner(newOwner);
    cout << "Copied Apartment after changing owner:" << endl;
    apt2.display();

    cout << "Original Apartment after copy and change:" << endl;
    apt1.display();

    return 0;
}
