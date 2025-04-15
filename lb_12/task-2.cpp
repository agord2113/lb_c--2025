#include <iostream>
#include <iomanip> // Для std::setw

using namespace std;

int main(void) {
    int matrix[10][10] = {};

    int *ptr = &matrix[0][0]; // Вказівник на перший елемент масиву
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            *ptr = (i + 1) * (j + 1); // Обчислюємо значення таблиці множення
            ptr++; // Переміщуємо вказівник до наступного елемента
        }
    }

    cout << "The following table:" << endl;
    ptr = &matrix[0][0]; // Повертаємо вказівник на початок масиву для виводу
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout.width(4);
            cout << *ptr;
            ptr++;
        }
        cout << endl;
    }

    return 0;
}
