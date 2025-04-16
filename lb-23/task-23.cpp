#include <iostream>
#include <string>
#include <algorithm> // for std::swap and std::abs

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();
    Fraction plus(Fraction that);
    Fraction minus(Fraction that);
    Fraction times(Fraction that);
    Fraction by(Fraction that);

private:
    int numerator;
    int denominator;
    void reduce();
    int gcd(int a, int b);
};

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    if (denominator == 0) {
        cerr << "Error: Denominator cannot be zero. Setting fraction to 0/1." << endl;
        this->numerator = 0;
        this->denominator = 1;
    }
    reduce();
}

int Fraction::gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::reduce() {
    if (numerator == 0) {
        denominator = 1;
        return;
    }

    int common = gcd(numerator, denominator);
    numerator /= common;
    denominator /= common;

    if (denominator < 0) {  // Ensure denominator is positive
        numerator *= -1;
        denominator *= -1;
    }
}

Fraction Fraction::plus(Fraction that) {
    int num = this->numerator * that.denominator + that.numerator * this->denominator;
    int den = this->denominator * that.denominator;
    Fraction result(num, den);
    return result;
}

Fraction Fraction::minus(Fraction that) {
    int num = this->numerator * that.denominator - that.numerator * this->denominator;
    int den = this->denominator * that.denominator;
    Fraction result(num, den);
    return result;
}

Fraction Fraction::times(Fraction that) {
    int num = this->numerator * that.numerator;
    int den = this->denominator * that.denominator;
    Fraction result(num, den);
    return result;
}

Fraction Fraction::by(Fraction that) {
    if (that.numerator == 0) {
        cerr << "Error: Cannot divide by zero. Returning 0/1." << endl;
        return Fraction(0, 1);
    }
    int num = this->numerator * that.denominator;
    int den = this->denominator * that.numerator;
    Fraction result(num, den);
    return result;
}

string Fraction::toString() {
    int whole = 0;
    int remainingNum = 0;
    if (abs(numerator) >= denominator) {
        whole = numerator / denominator;
        remainingNum = abs(numerator) % denominator;
    }

    string result;
    if (whole != 0) {
        result += to_string(whole);
        if (remainingNum != 0) {
            result += " " + to_string(remainingNum) + "/" + to_string(denominator);
        }
    } else if (numerator != 0) {
        result = to_string(numerator) + "/" + to_string(denominator);
    } else {
        result = "0";
    }
    return result;
}

double Fraction::toDouble() {
    return (double)numerator / denominator;
}

int main() {
    int num1, den1, num2, den2;
    char slash;

    cout << "Enter the first fraction (e.g., 3/4): ";
    cin >> num1 >> slash >> den1;

    cout << "Enter the second fraction (e.g., 1/3): ";
    cin >> num2 >> slash >> den2;

    Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    cout << f1.toString() << " + " << f2.toString() << " = " << (f1.plus(f2)).toString() << endl;
    cout << f1.toString() << " - " << f2.toString() << " = " << (f1.minus(f2)).toString() << endl;
    cout << f1.toString() << " * " << f2.toString() << " = " << (f1.times(f2)).toString() << endl;
    cout << f1.toString() << " / " << f2.toString() << " = " << (f1.by(f2)).toString() << endl;

    return 0;
}
