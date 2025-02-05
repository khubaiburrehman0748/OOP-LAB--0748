#include <iostream>
#include <vector>
using namespace std;

struct Worker {
    string workerName;
    int hoursLogged;
    int payRate;
    int salary;

    void computeSalary() {
        salary = hoursLogged * payRate;
    }
};

int main() {
    int workerCount;
    cout << "Enter the number of workers: ";
    cin >> workerCount;

    vector<Worker> workers(workerCount);

    for (int i = 0; i < workerCount; i++) {
        cout << "Enter the name of worker " << i + 1 << ": ";
        cin >> workers[i].workerName;
        
        cout << "Enter the hours logged by worker " << i + 1 << ": ";
        cin >> workers[i].hoursLogged;
        
        cout << "Enter the pay rate of worker " << i + 1 << ": ";
        cin >> workers[i].payRate;
        
        workers[i].computeSalary();
    }

    cout << "\nResults\n";
    for (const auto& wkr : workers) {
        cout << "Name: " << wkr.workerName << endl;
        cout << "Hours Logged: " << wkr.hoursLogged << endl;
        cout << "Pay Rate: " << wkr.payRate << endl;
        cout << "Salary: " << wkr.salary << endl;
        cout << "\n";
    }

    return 0;
}
