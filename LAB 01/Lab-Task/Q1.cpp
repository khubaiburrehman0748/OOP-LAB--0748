#include <iostream>
using namespace std;

int main() {
    //lab task 01
    string event1[5];
    string event2[5];
    int numEvent1,numEvent2;
    int total_donations=0;
    
     cout << "Enter number of participants for Event 1 (max 5): ";
    cin >> numEvent1;
    
    while (numEvent1 < 0 || numEvent1 > 5) {
        cout << "Invalid input! Enter a number between 0 and 5: ";
        cin >> numEvent1;
    }
    
    cin.ignore(); 
    cout<< "Enter participants of event 1 (max 5) =\n";
    for(int i = 0; i < numEvent1;i++){
        getline(cin , event1[i]);
        total_donations+=10;
    }
    
      cout << "Enter number of participants for Event 2 (max 5): ";
    cin >> numEvent2;
    
    while (numEvent2 < 0 || numEvent2 > 5) {
        cout << "Invalid input! Enter a number between 0 and 5: ";
        cin >> numEvent2;
    }
    
    cin.ignore(); 
    cout<< "Enter participants of event 2 (max 5) =\n";
    for(int i = 0; i < numEvent2;i++){
        getline(cin , event2[i]);
        total_donations+=10;
    }
    
    cout<< "       Participants of event 1 are \n" ;
    for(int i=0;i<numEvent1;i++){
        cout<<event1[i]<<endl;
    }
    
    cout<< "       Participants of event 2 are \n";
    for(int i=0;i<numEvent2;i++){
        cout<<event2[i]<<endl;
    }
    
    //lab task 02
    string name;
    int check=0;
    cout<<"enter your name =";
    cin>>name;
    
    for(int i=0;i<5;i++){
        if(name == event1[i]){
            cout<< "present in event 1 "<<endl;
            check=1;
            break;
        }
        else if(name == event2[i]){
            cout<< "present in event 2 "<<endl;
            check=2;
            break;
        }
    }
    if(check == 0){
        cout << "not present in any event";
    }
    
    //lab task 03
    cout <<"\n\ntotal donations collected is :" << total_donations<<endl;
    
    //lab task 04
    cout<<"\nparticipants in Event 1 \n";
    for(int i=numEvent1-1 ; i>=0 ; i--){
        cout<<"participant : "<<event1[i]<<endl;
    }
    
    cout<<"\nparticipants in Event 2 \n";
    for(int i=numEvent2-1 ; i>=0 ; i--){
        cout<<"participant : "<<event2[i]<<endl;
    }
    
    //lab task 05
    for(int i=4;i>=0;i--){
        if(i <= numEvent1-1){
            cout<<"*\t\t  ";
        }
        else{
            cout<<"\t\t  ";
        }
        if(i <=numEvent2-1){
            cout<<"*";
        }
        else{
            cout<<"\t";
        }
        cout<<"\n";
    }
    cout<<"---------------"<<endl;
    cout<<"event1  event2";
    return 0;
}
