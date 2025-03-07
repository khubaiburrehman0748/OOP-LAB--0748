#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
         string name;
         int age;

    Person(string n,int a){
        name = n;
        age = a;
    }

    void displayDetails(){
        cout<<"Name : "<<name<<endl;
        cout<<"age : "<<age<<endl;
    }
};

class Teacher :virtual public Person{
    public : 
    string subject;

    Teacher(string n,int a, string s)  : Person( n , a){
        subject = s;
    }

    void displayDetails(){
        cout<<"Name : "<<name<<endl;
        cout<<"age : "<<age<<endl;
        cout<<"Subject : "<<subject<<endl;
    }

};

class Reseacher :virtual public Person{
    public : 
        string ResearchArea;

    Reseacher(string n,int a,string RA) : Person ( n , a){
        ResearchArea = RA;
    }

    void displayDetails(){
        cout<<"Name : "<<name<<endl;
        cout<<"age : "<<age<<endl;
        cout<<"Research Area : "<<ResearchArea<<endl;
    }
};

class Professor : public Teacher , public Reseacher{
    public: 
        int publications=0;

    Professor(string n,int a,string RA, string s ,int pub) :Person(n,a), Teacher (n,a,s),Reseacher(n,a,RA){
        publications = pub;
    }

    void displayDetails(){
        cout<<"Name : "<<name<<endl;
        cout<<"age : "<<age<<endl;
        cout<<"Subject : "<<subject<<endl;
        cout<<"Research Area : "<<ResearchArea<<endl;
        cout<<"Publications : "<<publications<<endl;
    }
};

int main(){
    string name,research,subject;
    int age,Public;

    cout << "Enter Professor's Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Subject: ";
    getline(cin, subject);
    cout << "Enter Research Area: ";
    getline(cin, research);
    cout << "Enter Number of Publications: ";
    cin >> Public;

    Professor p1(name,age,research,subject,Public);
    p1.displayDetails();

    return 0;
}
