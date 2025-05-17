#include <iostream>
using namespace std;

class Vector2D {
private:
    double x, y;

public:
    Vector2D(double xVal = 0, double yVal = 0) {
        x = xVal;
        y = yVal;
    }

    Vector2D operator+(const Vector2D& v) {
        return Vector2D(x + v.x, y + v.y);
    }

    Vector2D operator-(const Vector2D& v) {
        return Vector2D(x - v.x, y - v.y);
    }

    Vector2D operator*(double scalar) {
        return Vector2D(x * scalar, y * scalar);
    }

    friend double dotProduct(const Vector2D& a, const Vector2D& b);

    friend ostream& operator<<(ostream& out, const Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }
};

double dotProduct(const Vector2D& a, const Vector2D& b) {
    return a.x * b.x + a.y * b.y;
}

int main() {
    Vector2D zain(3, 4);
    Vector2D sajid(1, 2);

    Vector2D sum = zain + sajid;
    Vector2D diff = zain - sajid;
    Vector2D scaled = zain * 2;
    double dot = dotProduct(zain, sajid);

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Scaled (zain * 2): " << scaled << endl;
    cout << "Dot Product: " << dot << endl;

    return 0;
}
