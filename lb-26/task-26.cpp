#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class IPAddress {
private:
    string ipAddress;

public:
    // Constructor
    IPAddress(const string& ip = "0.0.0.0") : ipAddress(ip) {}

    // Copy Constructor
    IPAddress(const IPAddress& other) : ipAddress(other.ipAddress) {}

    // Print method
    virtual void print() const {
        cout << ipAddress << endl;
    }

    string getIPAddress() const {
        return ipAddress;
    }
};

class IPAddressChecked : public IPAddress {
private:
    bool isCorrect;

public:
    // Constructor
    IPAddressChecked(const string& ip = "0.0.0.0") : IPAddress(ip) {
        isCorrect = checkIPAddress(ip);
    }

    // Copy Constructor
    IPAddressChecked(const IPAddressChecked& other) : IPAddress(other), isCorrect(other.isCorrect) {}

    // Print method
    void print() const override {
        IPAddress::print();
        if (isCorrect) {
            cout << "Correct" << endl;
        } else {
            cout << "Not Correct" << endl;
        }
    }

private:
    bool checkIPAddress(const string& ip) {
        vector<int> parts;
        stringstream ss(ip);
        string part;

        while (getline(ss, part, '.')) {
            try {
                int num = stoi(part);
                if (num < 0 || num > 255) {
                    return false;
                }
                parts.push_back(num);
            } catch (const std::invalid_argument& e) {
                return false;
            } catch (const std::out_of_range& e) {
                return false;
            }
        }

        return parts.size() == 4;
    }
};

int main() {
    // Get input from the user
    string ip1, ip2, ip3;
    cout << "Enter IP Address 1: ";
    cin >> ip1;
    cout << "Enter IP Address 2: ";
    cin >> ip2;
    cout << "Enter IP Address 3: ";
    cin >> ip3;

    // Create objects
    IPAddress address1(ip1);
    IPAddressChecked address2(ip2);
    IPAddressChecked address3(ip3);

    // Print values
    address1.print();
    address2.print();
    address3.print();

    return 0;
}
