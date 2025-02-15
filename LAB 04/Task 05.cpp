#include <iostream>
#include <string>
using namespace std;


class Car{

    public :
        string brand;
        string model;
        double price=0;
        double totalrev=0;
        bool availability;
        int carid;
    
    Car(){
        brand="Unknown";
        model="generic";
        price=0.0;
        availability=true;
        carid=0;
    }

    Car(int id,string brand,string model,double price){
        this->brand=brand;
        this->model=model;
        this->price=price;
        this->carid=id;
        availability=true;
        }

    Car(const Car &obj){
        this->carid=obj.carid;
        this->brand=obj.brand;
        this->model=obj.model;
        this->price=obj.price;
        this->availability=obj.availability;
    }

    ~Car(){
        cout<<brand<<" "<<model<<" is removed from storage."<<endl;
    }

    void update(string newbrand,string newmodel,double newprice){
            this->brand=newbrand;
            this->model=newmodel;
            this->price=newprice;
        }

    void calculateRevenue(int days){
        if (availability) {
            totalrev += price * days;
            availability = false;
            cout << "Revenue updated: $" << totalrev << " for " << brand << " " << model << endl;
        }
        else {
            cout << brand << " " << model << " is not available for rent." << endl;
        }
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

    void discount(int days){
        if(days>5 && days<11){
            price=price*0.95;
            cout<<"5%"<<"discount is applied ."<<price<<" is the new rental price.";
        }
        else if(days>10){
            price=price*0.90;
            cout<<"10%"<<"discount is applied ."<<price<<" is the new rental price.";
        }
        else{
            cout<<"discount is not applicable ";
        }
    }

    void display(){
        cout<<"Car ID : "<<carid<<endl;
        cout<<"Brand : "<<brand<<endl;
        cout<<"model : "<<model<<endl;
        cout<<"Rental price : $"<<price<<endl;
        cout<<"available :"<<(availability ? "available" : "Rented ")<<endl;
        cout<<"total revenue generated : $"<<totalrev<<endl; 
    }
};

int main() {
    Car car1(15,"Toyota", "Corolla", 50.0);
    cout << "Original Car Details:" << endl;
    car1.checkavailability();

    car1.calculateRevenue(7);  
    car1.checkavailability();

    Car car2 = car1;
    cout << "\nCopied Car Details:" << endl;
    car2.checkavailability();

    car1.update("Honda", "Civic", 60.0);
    cout << "\nModified Original Car Details:" << endl;
    car1.checkavailability();

    cout << "\nCopied Car Details After Modification:" << endl;
    car2.checkavailability();

    return 0;
}
