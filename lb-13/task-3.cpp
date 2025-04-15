#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Define the dimensions of the 2D array
    const int ROWS = 5;
    const int COLS = 5;
    int matrix[ROWS][COLS];

    // Populate the matrix with random numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(*(matrix + i) + j) = rand() % 100; // Random numbers between 0 and 99
        }
    }

    // Print the matrix
    cout << "Matrix:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }

    // Print the main diagonal
    cout << "Main Diagonal: ";
    for (int i = 0; i < ROWS; i++) {
        cout << *(*(matrix + i) + i) << " ";
    }
    cout << endl;

    // Print the secondary diagonal
    cout << "Secondary Diagonal: ";
    for (int i = 0; i < ROWS; i++) {
        cout << *(*(matrix + i) + (COLS - 1 - i)) << " ";
    }
    cout << endl;

    // Count even and odd elements
    int evenCount = 0;
    int oddCount = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (*(*(matrix + i) + j) % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
    }

    cout << "Even Elements: " << evenCount << endl;
    cout << "Odd Elements: " << oddCount << endl;

    return 0;
}
