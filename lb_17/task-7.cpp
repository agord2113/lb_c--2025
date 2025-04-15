#include <iostream>
#include <cmath>

using namespace std;

// Задача 1: Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Задача 2: Main function to print prime numbers from 0 to 21
int main() {
    for (int i = 0; i <= 21; ++i) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
