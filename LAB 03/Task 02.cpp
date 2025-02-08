#include <iostream>
#include <string>
using namespace std;

class FitnessTrack {
    public:
        string userName;
        int dailystepGoal;
        int steptaken=0;
        int caloriesburned=0;

    void logSteps(int steps) {
        steptaken += steps;
        caloriecalculate();
    }

    void caloriecalculate() {
        caloriesburned += steptaken * 0.05;
    }

    void displayprogress(){
        cout<<userName<<" record of the day "<<endl;
        cout<<"your daily step goal : "<<dailystepGoal<<endl;
        cout<<"step taken so far : "<<steptaken<<endl;
        cout<<"calorie burnt so far : "<<caloriesburned<<endl;
        if(steptaken>=dailystepGoal){
            cout<<"you have achieved your daily steps goal"<<endl;
        }
        else{
            cout<<dailystepGoal-steptaken<<" remaining steps to compelete your daily goal"<<endl;
        }
    }

        
};

int main() {
    FitnessTrack f1;
    f1.userName="hasan";
    f1.dailystepGoal=10000;
    f1.logSteps(5000);
    f1.displayprogress();
    f1.logSteps(5000);
    f1.displayprogress();
    return 0;
}
