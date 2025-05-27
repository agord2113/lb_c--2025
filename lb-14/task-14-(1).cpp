#include <iostream>
#include <cstdlib> // генерує випадкове число (rand())
#include <ctime> // випадковість (srand(time(0)))


using namespace std;

int main() {
  const int rows = 3;
  const int cols = 3;

  // 1. Dynamically allocate memory for the 2D array
  int** matrix = new int*[rows]; // Create an array of int pointers (rows)
  for (int i = 0; i < rows; ++i) {
    matrix[i] = new int[cols];   // Allocate memory for each row (cols)
  }

  // 2. Seed the random number generator
  srand(time(0));

  // 3. Fill the array with random integers
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      matrix[i][j] = rand() % 100; // Random numbers between 0 and 99
    }
  }

  // 4. Print the array (for verification)
  cout << "Matrix:\n";
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  // 5. Print main diagonal elements
  cout << "Main diagonal: ";
  for (int i = 0; i < rows; ++i) {
    cout << matrix[i][i] << " ";
  }
  cout << endl;

  // 6. Print secondary diagonal elements
  cout << "Secondary diagonal: ";
  for (int i = 0; i < rows; ++i) {
    cout << matrix[i][cols - 1 - i] << " ";
  }
  cout << endl;

  // 7. Count even and odd elements
  int evenCount = 0;
  int oddCount = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (matrix[i][j] % 2 == 0) {
        evenCount++;
      } else {
        oddCount++;
      }
    }
  }

  // 8. Display the counts
  cout << "Even count: " << evenCount << endl;
  cout << "Odd count: " << oddCount << endl;

  // 9. Deallocate the dynamically allocated memory
  for (int i = 0; i < rows; ++i) {
    delete[] matrix[i]; // Delete each row
  }
  delete[] matrix;       // Delete the array of pointers
  matrix = nullptr;

  return 0;
}
