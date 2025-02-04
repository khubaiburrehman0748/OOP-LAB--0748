
#include <iostream>
using namespace std;

 struct book{
    string title;
    string author;
    int year;
};

int main() {
    int booknum;
    
    cout<<"enter the number of books =";
    cin>>booknum;
    
    book *Book = new book[booknum];
    
    for(int i=0;i<booknum;i++){
        cout<<"BOOK "<<i+1<<endl;
        cout<<"title =";
        cin>>Book[i].title;
        cout<<"author =";
        cin>>Book[i].author;
        cout<<"year =";
        cin>>Book[i].year;
    }
    
    int year;
    cout<<"Enter the year  =";
    cin>>year;
    
    for(int i=0;i<booknum;i++){
        if(Book[i].year>year){
            cout <<"BOOK "<<i+1<<endl;
            cout<<"title = "<<Book[i].title<<endl;
            cout<<"author = "<<Book[i].author<<endl;
            cout<<"year = "<<Book[i].year<<endl<<endl;
       }
    }
    
    delete[] Book;
    
    return 0;
}
