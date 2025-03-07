#include <iostream>
#include <string>

using namespace std;

class vehicle {
    public:
         string brand;
         int speed;

    vehicle(string b,int s){
        brand = b;
        speed = s;
    }

    void displayDetails(){
        cout<<"Brand : "<<brand<<endl;
        cout<<"Speed : "<<speed<<"km/h"<<endl;
    }
};

class Car : public vehicle{
    public : 
    int seats;

    Car(int seat, string b , int s) : vehicle(b,s){
        seats = seat;
    }
    void displayDetails(){
        cout<<"Brand : "<<brand<<endl;
        cout<<"Speed : "<<speed<<"km/h"<<endl;
        cout<<"seats : "<<seats<<endl;
    }

};

class ElectricCar : public Car {
    public :
        int BatteryLife;
    
        ElectricCar(int bl,int seat, string b , int s):Car(seat , b ,s){
            BatteryLife = bl;
        }

    void displayDetails(){
        cout<<"Brand : "<<brand<<endl;
        cout<<"Speed : "<<speed<<"km/h"<<endl;
        cout<<"seats : "<<seats<<endl;
        cout<<"Battery Life : "<<BatteryLife<<endl;
    }
};

int main() {
    string brand;
    int speed, seats, batteryLife;

    cout << "Electric Car Brand: ";
    getline(cin, brand);

    cout << "Speed (km/h): ";
    cin >> speed;

    cout << "Number of Seats: ";
    cin >> seats;

    cout << "Battery Life in hours : ";
    cin >> batteryLife;

    ElectricCar eCar(batteryLife, speed, brand, batteryLife);

    cout << "\nElectric Car Details:\n";
    eCar.displayDetails();

    return 0;
}
