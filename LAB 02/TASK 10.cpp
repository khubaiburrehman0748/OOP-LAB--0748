#include <iostream>
using namespace std;

void allocateArray(int*** &arr, int a, int b, int c) {
    arr = new int**[a];
    for (int i = 0; i < a; i++) {
        arr[i] = new int*[b];
        for (int j = 0; j < b; j++) {
            arr[i][j] = new int[c];
        }
    }
}

void inputArray(int*** arr, int a, int b, int c) {
    cout << "Enter elements for the 3D array:\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                cout << "Element at (" << i+1 << ", " << j+1 << ", " << k+1 << "): ";
                cin >> arr[i][j][k];
            }
        }
    }
}

void displayArray(int*** arr, int a, int b, int c) {
    cout << "\nStored 3D Array Elements:\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                cout << "Element at (" << i+1 << ", " << j+1 << ", " << k+1 << "): " << arr[i][j][k] << endl;
            }
        }
    }
}

void deallocateArray(int*** &arr, int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
}

int main() {
    int dim1, dim2, dim3;

    cout << "Enter the dimensions of the 3D array:\n";
    cout << "Rows: ";
    cin >> dim1;
    cout << "Columns: ";
    cin >> dim2;
    cout << "Depth: ";
    cin >> dim3;

    int*** data;
    allocateArray(data, dim1, dim2, dim3);
    
    inputArray(data, dim1, dim2, dim3);
    displayArray(data, dim1, dim2, dim3);

    deallocateArray(data, dim1, dim2);

    return 0;
}
