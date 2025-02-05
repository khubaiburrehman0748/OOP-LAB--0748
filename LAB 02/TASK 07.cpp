#include <iostream>
using namespace std;

int main() {
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows and columns for first matrix: ";
    cin >> rowsA >> colsA;
    cout << "Enter rows and columns for second matrix: ";
    cin >> rowsB >> colsB;

    if (colsA != rowsB) {
        cout << "Matrix multiplication not possible!" << endl;
        return 1;
    }

    int** matrixA = new int*[rowsA];
    int** matrixB = new int*[rowsB];
    int** result = new int*[rowsA];

    for (int i = 0; i < rowsA; i++) matrixA[i] = new int[colsA];
    for (int i = 0; i < rowsB; i++) matrixB[i] = new int[colsB];
    for (int i = 0; i < rowsA; i++) result[i] = new int[colsB]{0}; // Initialize result matrix to 0

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsA; j++)
            cin >> matrixA[i][j];

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < rowsB; i++)
        for (int j = 0; j < colsB; j++)
            cin >> matrixB[i][j];

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rowsA; i++) delete[] matrixA[i];
    for (int i = 0; i < rowsB; i++) delete[] matrixB[i];
    for (int i = 0; i < rowsA; i++) delete[] result[i];

    delete[] matrixA;
    delete[] matrixB;
    delete[] result;

    return 0;
}
