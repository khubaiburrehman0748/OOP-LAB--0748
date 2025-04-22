#include <iostream>
#include <vector>
using namespace std;

class Person {
public:
    string name;
    int age;
    string contactNumber;
    string address;

    Person(string n, int a, string c, string addr = "") {
        name = n;
        age = a;
        contactNumber = c;
        address = addr;
    }

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact Number: " << contactNumber << endl;
        if (!address.empty()) {
            cout << "Address: " << address << endl;
        }
    }

    virtual void updateInfo() {
    }
};

class Patient : public Person {
private:
    string patientID;
    string medicalHistory;
    string doctorAssigned;
public:
    Patient(string n, int a, string c, string addr, string id, string history, string doc)
        : Person(n, a, c, addr) {
        patientID = id;
        medicalHistory = history;
        doctorAssigned = doc;
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << endl;
        cout << "Medical History: " << medicalHistory << endl;
        cout << "Doctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
private:
    string specialization;
    double consultationFee;
    vector<string> patientsList;
public:
    Doctor(string n, int a, string c, string addr, string spec, double fee, vector<string> patients)
        : Person(n, a, c, addr) {
        specialization = spec;
        consultationFee = fee;
        patientsList = patients;
    }

    void updateInfo() {
        cout << "Doctor profile updated" << endl;
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Consultation Fee: " << consultationFee << endl;
        cout << "Patients List: ";
        for (string p : patientsList) {
            cout << p << " ";
        }
        cout << endl;
    }
};

class Nurse : public Person {
private:
    string assignedWard;
    string shiftTimings;
public:
    Nurse(string n, int a, string c, string addr, string ward, string shift)
        : Person(n, a, c, addr) {
        assignedWard = ward;
        shiftTimings = shift;
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
private:
    string department;
    double salary;
public:
    Administrator(string n, int a, string c, string addr, string dept, double s)
        : Person(n, a, c, addr) {
        department = dept;
        salary = s;
    }

    void updateInfo() {
        cout << "Administrator info updated" << endl;
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    cout << "khubaib ur rehman \n24k-0748" << endl;

    Patient p1("Ali", 30, "03001234567", "Lahore", "P101", "Diabetes", "Dr. Zain");
    Doctor d1("Zain", 45, "03007654321", "Karachi", "Cardiologist", 2500, {"P101", "P102"});
    Nurse n1("Mehmod", 28, "03007891234", "Multan", "Ward A", "Morning");
    Administrator a1("Khubaib", 35, "03001239876", "Islamabad", "HR", 60000);

    cout << "\n--- Patient Info ---" << endl;
    p1.displayInfo();

    cout << "\n--- Doctor Info ---" << endl;
    d1.updateInfo();
    d1.displayInfo();

    cout << "\n--- Nurse Info ---" << endl;
    n1.displayInfo();

    cout << "\n--- Administrator Info ---" << endl;
    a1.updateInfo();
    a1.displayInfo();

    return 0;
}
