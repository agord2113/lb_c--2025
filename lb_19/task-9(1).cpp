#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string password;
    cout << "Enter your password: ";
    getline(cin, password);

    bool isValid = true;
    string errors = "";

    if (password.length() != 8) {
        isValid = false;
        errors += "The password must be 8 characters long\n";
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (char c : password) {
        if (isupper(c)) hasUpper = true;
        if (islower(c)) hasLower = true;
        if (isdigit(c)) hasDigit = true;
        if (ispunct(c)) hasSpecial = true;
    }

    if (!hasUpper) {
        isValid = false;
        errors += "The password must have at least one upper case letter\n";
    }

    if (!hasLower) {
        isValid = false;
        errors += "The password must have at least one lower case letter\n";
    }

    if (!hasDigit) {
        isValid = false;
        errors += "The password must have at least one digit\n";
    }

    if (!hasSpecial) {
        isValid = false;
        errors += "The password must have at least one special character\n";
    }

    if (isValid) {
        cout << "The password is valid" << endl;
    } else {
        cout << errors;
    }

    return 0;
}
