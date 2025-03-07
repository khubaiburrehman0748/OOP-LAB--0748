#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
public:
    string name;
    string designation;

    Employee(string name, string designation) {
        this->name = name;
        this->designation = designation;
    }
};

class Project {
public:
    string title;
    string deadline;
    vector<Employee*> employees;

    Project(string title, string deadline) {
        this->title = title;
        this->deadline = deadline;
    }

    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    void display() {
        cout << "Project: " << title << endl;
        cout << "Deadline: " << deadline << endl;
        cout << "Assigned Employees:" << endl;
        for (Employee* emp : employees) {
            cout << " - " << emp->name << " (" << emp->designation << ")" << endl;
        }
        cout << "-------------------------" << endl;
    }
};

int main() {
    Employee emp1("umair", "Developer");
    Employee emp2("shahid", "Designer");
    Employee emp3("usman", "Tester");

    Project proj1("Website Redesign", "2023-12-01");
    proj1.addEmployee(&emp1);
    proj1.addEmployee(&emp2);

    Project proj2("Mobile App", "2024-02-15");
    proj2.addEmployee(&emp1);
    proj2.addEmployee(&emp3);

    proj1.display();
    proj2.display();

    return 0;
}