#include <iostream>
using namespace std;

class Account {
private:
    int accountNumber;
    float balance;

public:
    Account(int accNum = 0, float bal = 0.0f)
        : accountNumber(accNum), balance(bal) {}

    virtual void displayDetails() {
        cout << "Account Number: " << accountNumber
             << "\nBalance: $" << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    float interestRate;

public:
    SavingsAccount(int accNum = 0, float bal = 0.0f, float rate = 0.0f)
        : Account(accNum, bal), interestRate(rate) {}

    void displayDetails() override {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    CheckingAccount(int accNum = 0, float bal = 0.0f, float limit = 0.0f)
        : Account(accNum, bal), overdraftLimit(limit) {}

    void displayDetails() override {
        Account::displayDetails();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

int main() {
    int sAccNum, cAccNum;
    float sBal, sRate, cBal, cLimit;

    cout << "Enter Savings Account Number: ";
    cin >> sAccNum;
    cout << "Enter Balance: ";
    cin >> sBal;
    cout << "Enter Interest Rate: ";
    cin >> sRate;

    SavingsAccount sAccount(sAccNum, sBal, sRate);

    cout << "\nEnter Checking Account Number: ";
    cin >> cAccNum;
    cout << "Enter Balance: ";
    cin >> cBal;
    cout << "Enter Overdraft Limit: ";
    cin >> cLimit;

    CheckingAccount cAccount(cAccNum, cBal, cLimit);

    cout << "\n--- Savings Account Details ---\n";
    sAccount.displayDetails();

    cout << "\n--- Checking Account Details ---\n";
    cAccount.displayDetails();

    return 0;
}
