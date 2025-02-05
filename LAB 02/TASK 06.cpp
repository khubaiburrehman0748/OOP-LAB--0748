#include <iostream>
using namespace std;

struct Pupil {
    string fullName;
    string id;
    int scores[3];
    float avgScore = 0;
};

void calculateAverage(Pupil* p, int count) {
    for (int i = 0; i < count; i++) {
        p[i].avgScore = (p[i].scores[0] + p[i].scores[1] + p[i].scores[2]) / 3.0;
    }
}

int main() {
    int totalPupils;
    
    cout << "Enter the number of pupils: ";
    cin >> totalPupils;

    Pupil* classList = new Pupil[totalPupils];

    for (int i = 0; i < totalPupils; i++) {
        cout << "Enter full name of pupil " << i + 1 << ": ";
        cin >> classList[i].fullName;
        cout << "Enter ID of pupil " << i + 1 << ": ";
        cin >> classList[i].id;
        
        for (int j = 0; j < 3; j++) {
            cout << "Enter marks for subject " << j + 1 << ": ";
            cin >> classList[i].scores[j];
        }
    }

    calculateAverage(classList, totalPupils);

    for (int i = 0; i < totalPupils; i++) {
        cout << "Average score of " << classList[i].fullName << " is: " << classList[i].avgScore << endl;
    }

    delete[] classList;
    return 0;
}
