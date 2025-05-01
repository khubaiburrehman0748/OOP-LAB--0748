#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){
    ifstream in;
    string read;
    in.open("vehicles.txt");
    if(in.is_open()){
    while (in.eof()==0){
        getline(in , read);
        cout<<read<<endl;
        }
    }
    else{
        cout << "Error Opening file "<<endl;
    }
    in.close();
}
