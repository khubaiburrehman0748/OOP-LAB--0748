#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    Complex operator/(const Complex& c) {
        double d = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / d, (imag * c.real - real * c.imag) / d);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << "(" << c.real << " + " << c.imag << "i)";
        return out;
    }

    friend double magnitude(const Complex& c);
};

double magnitude(const Complex& c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

int main() {
    Complex ahmad(3, 4);
    Complex ali(1, 2);

    Complex sum = ahmad + ali;
    Complex diff = ahmad - ali;
    Complex prod = ahmad * ali;
    Complex div = ahmad / ali;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;
    cout << "Division: " << div << endl;
    cout << "Magnitude of Ahmad: " << magnitude(ahmad) << endl;

    return 0;
}
