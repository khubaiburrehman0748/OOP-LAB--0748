#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Doctor {
public:
    string name;
    string specialization;
    int experience;

    Doctor(string name, string specialization, int experience) {
        this->name = name;
        this->specialization = specialization;
        this->experience = experience;
    }
};

class Hospital {
public:
    string name;
    vector<Doctor*> doctors;

    Hospital(string name) {
        this->name = name;
    }

    void addDoctor(Doctor* doctor) {
        doctors.push_back(doctor);
    }

    void display() {
        cout << "Hospital: " << name << endl;
        cout << "Doctors:" << endl;
        for (int i = 0; i < doctors.size(); i++) {
            cout << " - " << doctors[i]->name << " (" << doctors[i]->specialization << ", " << doctors[i]->experience << " years)" << endl;
        }
        cout << "-------------------------" << endl;
    }
};

int main() {
    Doctor doc1("khubaib", "dil ka doctor", 10);
    Doctor doc2("usman", "ankho ka doctor", 8);
    Doctor doc3("usaid", "nurse", 5);

    Hospital hospital("national medical center");
    hospital.addDoctor(&doc1);
    hospital.addDoctor(&doc2);

    hospital.display();

    Hospital hospital2("liaquat national hospital");
    hospital2.addDoctor(&doc3);
    hospital2.addDoctor(&doc1);

    hospital2.display();

    return 0;
}