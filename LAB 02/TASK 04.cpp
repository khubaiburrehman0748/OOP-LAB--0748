#include <iostream>
using namespace std;

int main() {
    int totalStrings;
    cout << "Enter the number of strings: ";
    cin >> totalStrings;

    string *dynamicStrings = new string[totalStrings];

    for (int i = 0; i < totalStrings; i++) {
        cout << "Enter string " << i + 1 << ": ";
        cin >> dynamicStrings[i];
    }

    for (int i = 0; i < totalStrings - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < totalStrings; j++) {
            if (dynamicStrings[j][0] < dynamicStrings[minIndex][0]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            string temp = dynamicStrings[i];
            dynamicStrings[i] = dynamicStrings[minIndex];
            dynamicStrings[minIndex] = temp;
        }
    }

    cout << "Sorted strings:" << endl;

    for (int i = 0; i < totalStrings; i++) {
        cout << dynamicStrings[i] << endl;
    }

    delete[] dynamicStrings;

    return 0;
}
