
#include <iostream>
#include <string>
using namespace std;

class patient {
    public: 
        string name;
        string id;

    virtual void displayTreatment(string treatment)=0;

    virtual float CalculateCost(int hours)=0;

};

class inpatient : public patient{
    public:

    inpatient(string n,string id){
        name=n;
        this->id=id;
    }

    void displayTreatment(string treatment){
        cout<<"Name = "<<name<<endl;
        cout<<"ID = "<<id<<endl;
        cout<<"Treatment = "<<treatment<<endl;
    }

    float CalculateCost(int hours){
        return 1000*hours;  
    }
};

class outPatient : public patient{
    public:
    
    
    outPatient(string n, string i){
        name = n;
        id = i;
    }

    void displayTreatment(string treatment){
        cout<<"Name = "<<name<<endl;
        cout<<"ID = "<<id<<endl;
        cout<<"Treatment = "<<treatment<<endl;
    }     

    float CalculateCost(int hours){
        return hours*1500;
    }
};


int main(){
    cout<<"24K-0748\nKHUBAIB UR REHMAN "<<endl;
    patient *p1;
    patient *p2;
    inpatient inPatientObj("khubaib","54");
    p1 = &inPatientObj;
    outPatient outPatientObj("ali","70");
    p2 = &outPatientObj;

    p1->displayTreatment("X-RAY");
    cout<<"Total Cost: $"<<p1->CalculateCost(5)<<endl;

    p2->displayTreatment("Daily routine checkup");
    cout<<"Total Cost: $"<<p2->CalculateCost(2)<<endl;

    return 0;
}
