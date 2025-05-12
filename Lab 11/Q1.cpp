#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

class DimensionMismatchException : public exception {
    string message;
public:
    DimensionMismatchException(int r1, int c1, int r2, int c2) {
        stringstream ss;
        ss << "DimensionMismatchException - Matrices must have same dimensions (" 
           << r1 << "x" << c1 << " vs " << r2 << "x" << c2 << ")!";
        message = ss.str();
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

template<typename T, int R, int C>
class Matrix {
    T data[R][C];
public:
    void setValue(int r, int c, T val) { data[r][c] = val; }
    Matrix<T, R, C> operator+(const Matrix<T, R, C>& other) {
        Matrix<T, R, C> result;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }
};

template<typename T, int R1, int C1, int R2, int C2>
Matrix<T, R1, C1> addMatrices(const Matrix<T, R1, C1>& a, const Matrix<T, R2, C2>& b) {
    if (R1 != R2 || C1 != C2)
        throw DimensionMismatchException(R1, C1, R2, C2);
    return a + b;
}

int main() {
    cout << "Matrix A (2x2) + Matrix B (3x3):" << endl;
    try {
        Matrix<int, 2, 2> A;
        Matrix<int, 3, 3> B;
        auto C = addMatrices(A, B);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}

