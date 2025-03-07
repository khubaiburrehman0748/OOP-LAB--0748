#include <iostream>
#include <string>

using namespace std;

class Employee {
    public:
        string name;
        float salary = 0.0;
        
    Employee(string n, float s){
        name = n;
        salary = s;
    }

    void displayDetails(){
        cout<<"Name : "<<name<<endl;
        cout<<"Salary : $"<<salary<<endl;
    }

}; 

class Manager : public Employee {
    public :
    float bonus = 0.0;

    Manager(string n, float s,float b): Employee(n, s){
        bonus = b;
    }

    void displayDetails(){
        cout<<"Name : "<<name<<endl;
        cout<<"Salary : $"<<salary<<endl;
        cout<<"bonus : $"<<bonus<<endl;
    }
};


int main(){
    string name;
    float salary, bonus;

    cout << "Enter Manager's Name: ";
    getline(cin, name);

    cout << "Enter Salary: ";
    cin >> salary;

    cout << "Enter Bonus: ";
    cin >> bonus;

    Manager mgr(name, salary, bonus);

    cout << "\nManager Details:\n";
    mgr.displayDetails();
}
