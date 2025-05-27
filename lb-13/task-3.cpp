#include <iostream>
#include <cstdlib> // генерує випадкове число (rand())
#include <ctime>   // випадковість (srand(time(0)))

using namespace std;

int main() {
    // Ініціалізація генератора випадкових чисел
    srand(time(0));

    //Визначте розміри двовимірного масиву
    const int ROWS = 5;
    const int COLS = 5;
    int matrix[ROWS][COLS];

    // Заповнення матриці випадковими числами
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(*(matrix + i) + j) = rand() % 100; // Випадкові числа від 0 до 99
        }
    }

    // Роздрукування матриці
    cout << "Matrix:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }

    // Виведення головної діагоналі
    cout << "Main Diagonal: ";
    for (int i = 0; i < ROWS; i++) {
        cout << *(*(matrix + i) + i) << " ";
    }
    cout << endl;

    // Вививодимо вторинну діагональ
    cout << "Secondary Diagonal: ";
    for (int i = 0; i < ROWS; i++) {
        cout << *(*(matrix + i) + (COLS - 1 - i)) << " ";
    }
    cout << endl;

    // Рахування парних та непарних елементів
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
