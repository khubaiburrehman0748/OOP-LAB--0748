#include <iostream>
#include <vector>
using namespace std;

int main() {
    int stringCount;
    cout << "Enter the number of strings: ";
    cin >> stringCount;

    vector<string> strList(stringCount);

    for (int i = 0; i < stringCount; i++) {
        cout << "Enter string " << i + 1 << ": ";
        cin >> strList[i];
    }

    
    for (int i = 0; i < stringCount - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < stringCount; j++) {
            if (strList[j][0] < strList[minIndex][0]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(strList[i], strList[minIndex]);
        }
    }

    cout << "Sorted strings:" << endl;
    for (const auto& str : strList) {
        cout << str << endl;
    }

    return 0;
}
