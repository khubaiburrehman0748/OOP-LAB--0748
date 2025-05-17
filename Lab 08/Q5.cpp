#include <iostream>
using namespace std;

class Matrix2x2 {
    int a[2][2];
public:
    Matrix2x2(int x1 = 0, int x2 = 0, int x3 = 0, int x4 = 0) {
        a[0][0] = x1; a[0][1] = x2;
        a[1][0] = x3; a[1][1] = x4;
    }

    Matrix2x2 operator+(Matrix2x2 m) {
        return Matrix2x2(
            a[0][0] + m.a[0][0], a[0][1] + m.a[0][1],
            a[1][0] + m.a[1][0], a[1][1] + m.a[1][1]
        );
    }

    Matrix2x2 operator-(Matrix2x2 m) {
        return Matrix2x2(
            a[0][0] - m.a[0][0], a[0][1] - m.a[0][1],
            a[1][0] - m.a[1][0], a[1][1] - m.a[1][1]
        );
    }

    Matrix2x2 operator*(Matrix2x2 m) {
        return Matrix2x2(
            a[0][0]*m.a[0][0] + a[0][1]*m.a[1][0], a[0][0]*m.a[0][1] + a[0][1]*m.a[1][1],
            a[1][0]*m.a[0][0] + a[1][1]*m.a[1][0], a[1][0]*m.a[0][1] + a[1][1]*m.a[1][1]
        );
    }

    friend int determinant(Matrix2x2);
    friend class MatrixHelper;

    friend ostream& operator<<(ostream &out, Matrix2x2 m) {
        out << m.a[0][0] << " " << m.a[0][1] << endl;
        out << m.a[1][0] << " " << m.a[1][1] << endl;
        return out;
    }
};

int determinant(Matrix2x2 m) {
    return m.a[0][0]*m.a[1][1] - m.a[0][1]*m.a[1][0];
}

class MatrixHelper {
public:
    void updateElement(Matrix2x2 &m, int row, int col, int value) {
        m.a[row][col] = value;
    }
};

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    Matrix2x2 sum = m1 + m2;
    Matrix2x2 diff = m1 - m2;
    Matrix2x2 prod = m1 * m2;

    cout << "Sum:\n" << sum;
    cout << "Difference:\n" << diff;
    cout << "Product:\n" << prod;

    cout << "Determinant of m1: " << determinant(m1) << endl;

    MatrixHelper helper;
    helper.updateElement(m1, 0, 0, 9);

    cout << "Updated m1:\n" << m1;

    return 0;
}
