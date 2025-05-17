#include <iostream>
using namespace std;

class Account {
private:
    int accountNumber;
    double balance;

public:
    Account(int number, double bal = 0) {
        accountNumber = number;
        balance = bal;
    }

    friend class Manager;
    friend void transferFunds(Account& from, Account& to, double amount);
};

class Manager {
public:
    void deposit(Account& acc, double amount) {
        acc.balance += amount;
    }

    void withdraw(Account& acc, double amount) {
        if (acc.balance >= amount)
            acc.balance -= amount;
    }

    void display(const Account& acc) {
        cout << "Account: " << acc.accountNumber << ", Balance: " << acc.balance << endl;
    }
};

void transferFunds(Account& from, Account& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
    }
}

int main() {
    Account usman(101, 5000);
    Account hamza(102, 3000);

    Manager m;

    m.deposit(usman, 2000);
    m.withdraw(hamza, 1000);
    transferFunds(usman, hamza, 1500);

    m.display(usman);
    m.display(hamza);

    return 0;
}
