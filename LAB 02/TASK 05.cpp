#include <iostream>
using namespace std;

int main() {
    int totalElements;
    
    cout << "How many elements would you like to input? ";
    cin >> totalElements;
    
    int *dynamicArray = new int[totalElements];

    for (int i = 0; i < totalElements; i++) {
        cout << "Please enter element " << i + 1 << ": ";
        cin >> dynamicArray[i];
    }

    int *iterator = dynamicArray; 
    int totalSum = 0;

    cout << "The elements entered are:" << endl;

    for (int i = 0; i < totalElements; i++) {
        cout << "Element " << i + 1 << ": " << *iterator << endl;
        totalSum += *iterator;
        iterator++; 
    }

    cout << "The total sum of the entered elements is: " << totalSum << endl;

  
    delete[] dynamicArray;
    
    return 0;
}
