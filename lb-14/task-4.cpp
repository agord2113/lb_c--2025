#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iomanip> // Дозволяє форматувати вивід чисел

using namespace std;

int main() {
  int size;

  // 1. Get the size of the array from the user
  cout << "Enter the size of the array: ";
  cin >> size;

  // 2. Dynamically allocate memory for the array
  float* arr = new float[size];

  // 3. Seed the random number generator
  srand(time(0));

  // 4. Fill the array with random floats between -2 and 2
  for (int i = 0; i < size; ++i) {
    arr[i] = -2.0 + (4.0 * rand()) / RAND_MAX; 
  }

  // 5. Print the array (optional, for verification)
  cout << "Array elements:\n";
  for (int i = 0; i < size; ++i) {
    cout << fixed << setprecision(2) << arr[i] << " ";
  }
  cout << endl;

  // 6. Count positive and negative numbers
  int positiveCount = 0;
  int negativeCount = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] > 0) {
      positiveCount++;
    } else if (arr[i] < 0) {
      negativeCount++;
    }
  }

  // 7. Display the counts
  cout << "Positive count: " << positiveCount << endl;
  cout << "Negative count: " << negativeCount << endl;

  // 8. Deallocate the dynamically allocated memory
  delete[] arr;
  arr = nullptr; // Good practice to set the pointer to nullptr after deleting

  return 0;
}
