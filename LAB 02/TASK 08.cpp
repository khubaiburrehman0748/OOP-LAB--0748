#include <iostream>
using namespace std;

void inputArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void displayArray(int* arr, int size) {
    cout << "You entered: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int totalElements;
    
    cout << "How many numbers do you want to enter? ";
    cin >> totalElements;

    int* values = new int[totalElements];

    inputArray(values, totalElements);
    displayArray(values, totalElements);

    delete[] values; 

    return 0;
}
