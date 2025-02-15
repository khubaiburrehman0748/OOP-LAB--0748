#include <iostream>
#include <string>
using namespace std;


class Car{

    public :
        string brand;
        string model;
        double price;
        bool availability;
        int count=0;
    
    Car(){
        brand="Unknown";
        model="generic";
        price=0.0;
        availability=true;
        count++;
    }

    Car(string brand,string model,double price){
            this->brand=brand;
            this->model=model;
            this->price=price;
            availability=true;
            count++;
        }

    void update(string newbrand,string newmodel,double newprice){
            this->brand=newprice;
            this->model=newmodel;
            this->price=newprice;
        }

    void rentalrequest(){
        if(availability){
            availability=false;
            cout<<brand<<" "<<model<< " has been rented succesfully "<<endl;
        }
        else {
            cout<<brand<<" "<<model<< " has already rented out "<<endl;
        }
    }

    void checkavailability(){
        if(availability){
            cout<<brand<<" "<<model<< " is available for rent "<<endl;
        }
        else{
            cout<<brand<<" "<<model<< " is not available for rent "<<endl;
        }
    }
};

int main(){
    Car car1; 
    car1.checkavailability();

    Car car2("Toyota", "Corolla", 50.0);
    car2.checkavailability();
    car2.rentalrequest();
    car2.checkavailability(); 

    return 0;
}
