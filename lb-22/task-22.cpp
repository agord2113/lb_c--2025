#include <iostream>
#include <string>
#include <sstream>  // for stringstream
#include <cmath>    // for std::abs

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    string toString();
    double toDouble();

private:
    int numerator;
    int denominator;
};

string Fraction::toString() {
    // Handle signs
    int sign = 1;
    if (numerator < 0 || denominator < 0) {
        sign = -1;
        numerator = abs(numerator);
        denominator = abs(denominator);
    }

    if (numerator == 0) {
        return "0";
    }

    if (denominator == 1) {
        return to_string(sign * numerator);
    }

    if (numerator > denominator) {
        int whole = numerator / denominator;
        int remainder = numerator % denominator;
        if (remainder == 0) {
            return to_string(sign * whole);
        } else {
            return to_string(sign * whole) + " " + to_string(remainder) + "/" + to_string(denominator);
        }
    } else {
        return to_string(sign * numerator) + "/" + to_string(denominator);
    }
}

double Fraction::toDouble() {
    return (double)numerator / denominator;
}

int main() {
    int num, den;
    string input;

    getline(cin, input);

    // Parse the input string
    char slash;
    stringstream ss(input);
    ss >> num >> slash >> den;

    Fraction fraction(num, den);

    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;

    return 0;
}
