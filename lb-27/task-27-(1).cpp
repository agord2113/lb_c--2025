#include <iostream>
#include <stdexcept> // For std::invalid_argument

using namespace std;

// Function to perform division, now throws an exception on invalid input
float internaldiv(float arg1, float arg2) {
    if (arg2 == 0.0) {
        throw invalid_argument("Error: Invalid argument - division by zero!"); // Throw exception if divisor is zero
    }
    return arg1 / arg2;
}

int main() {
    float a, b;

    cout << "Enter pairs of numbers (a b):" << endl;

    while (cin >> a) {
        cin >> b;
        try {
            // Check for invalid input *before* calling the division function
            if (b == 0.0) {
                throw invalid_argument("Error: Invalid input - division by zero!"); // Throw exception if input is invalid
            }
            float result = internaldiv(a, b); // Perform division
            cout << "Result: " << result << endl; // Print the result
        } catch (const invalid_argument& error) {
            cerr << "Error: " << error.what() << endl; // Print the error message to cerr
        }
    }

    cout << "Program finished." << endl;

    return 0;
}
