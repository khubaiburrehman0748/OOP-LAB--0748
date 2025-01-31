#include <iostream>
using namespace std;

int main() {
    int aqi[4][7];
    double average[4];
    for(int i=0;i<4;i++){
        average[i]=0;
        for(int j=0;j<7;j++){
            cout<<"AQI of city "<<i+1<<" of day "<<j+1<<" = ";
            cin>>aqi[i][j];
            average[i]+=aqi[i][j];
        }
        average[i]=average[i]/7;
        break;
    }
    int high_aqi=-1,city=0;
    for(int i=0;i<4;i++){
        cout<<"average of city "<<i+1<<" = "<<average[i]<<endl;
        if(average[i]>high_aqi){
           high_aqi=average[i];
           city=i;
        }
    }
    cout<<"city with highest aqi is : "<<city<<" with aqi of : "<<high_aqi<<endl;
    
    //lab task 02
    cout<<"\n Critical pollution days :"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<7;j++){
            if(aqi[i][j]>150){
                cout<<"city : "<<i+1<<" day : "<<j+1<<endl;
            }
        }
    }
    
    //lab task 03
    for(int i=0;i<4;i++){
        cout<<"   CITY  "<<i+1<<endl;
        for(int j=0;j<7;j++){
            
        }
    }
    return 0;
}
