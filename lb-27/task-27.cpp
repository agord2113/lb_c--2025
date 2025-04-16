#include <iostream>
#include <stdexcept> // for std::runtime_error

using namespace std;

int main(void) {
    int a = 8, b = 0, c = 0;

    cout << "Enter the value for b: ";
    cin >> b;

    try {
        if (b == 0) {
            throw runtime_error("Error: Division by zero is not allowed."); // Throw exception if b is 0 [cite: 3, 4]
        }
        c = a / b; // Calculate c = a / b [cite: 4]
        cout << "Result: " << c << endl; // Print the result if no exception [cite: 5]
    } catch (const runtime_error& error) {
        cerr << error.what() << endl; // Print the error message [cite: 5, 6]
    }

    return 0;
}
