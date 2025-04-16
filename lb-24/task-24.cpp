#include <iostream>
#include <string>
#include <numeric> // for std::gcd

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
        reduce();
    }

    string toString() {
        return to_string(numerator) + "/" + to_string(denominator);
    }

    double toDouble() {
        return (double)numerator / denominator;
    }

    bool isGreaterThan(Fraction that) {
        return toDouble() > that.toDouble();
    }

    bool isLessThan(Fraction that) {
        return toDouble() < that.toDouble();
    }

    bool isEqual(Fraction that) {
        return toDouble() == that.toDouble();
    }

private:
    int numerator;
    int denominator;

    void reduce() {
        int common = std::gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
        if (denominator < 0) { // Ensure denominator is positive
            numerator *= -1;
            denominator *= -1;
        }
    }
};

int main() {
    int num1, den1, num2, den2;
    char slash; // To read the '/' character

    cin >> num1 >> slash >> den1;
    cin >> num2 >> slash >> den2;

    Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    if (f1.isGreaterThan(f2)) {
        cout << f1.toString() << ">" << f2.toString() << endl;
    } else if (f1.isLessThan(f2)) {
        cout << f1.toString() << "<" << f2.toString() << endl;
    } else {
        cout << f1.toString() << "==" << f2.toString() << endl;
    }

    return 0;
}
