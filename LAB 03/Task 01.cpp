#include <iostream>
#include <string>
using namespace std;

class Wallet {
    public:
        string ownername;
        int totalBalance=0;
        string transaction[100];
        int count=0;

    void addmoney(int money){
        totalBalance+=money;
        transaction[count++] = "Added: " + to_string(money);
        cout<<  money <<" amount is added to your wallet \n";
    }

    void spendmoney(int money){
        if(totalBalance>=money){
        totalBalance-=money;
        transaction[count++] = "spent " + to_string (money);
        cout<<money<<" amount is spent from you wallet\n";
        }
        else{
            cout << "Transaction failed! Insufficient balance.\n";
            return;
        }
    }
    

    void displaytransactionhistory(){
            
            cout << "transaction histroy of "<< ownername <<endl;
            for(int i=0; i <count; i++ ){
                cout<<transaction[i]<<endl;
            }
            
            cout << "Current Balance = "<<totalBalance;

            if(totalBalance<100){
                cout<<"Warning: Low balance! Current balance: "<<totalBalance;
            }

    }

};

int main() {
    Wallet w1;
    w1.ownername = "Ahmed";

    w1.addmoney(500);
    w1.spendmoney(200);
    w1.spendmoney(400);  
    w1.displaytransactionhistory();

    return 0;
}
