#include <iostream>
#include <climits> // Для INT_MAX

using namespace std;

int main(void) {
    int vector[] = {3, -5, 7, 10, -4, 14, 5, 2, -13};
    int n = sizeof(vector) / sizeof(vector[0]);

    int *ptr = vector; // Вказівник на початок масиву
    int minVal = INT_MAX; // Початкове значення для порівняння
    int *minPtr = vector; // Вказівник на поточний мінімум (спочатку на початок)

    for (int i = 0; i < n; i++) {
        if (*ptr < minVal) {
            minVal = *ptr;
            minPtr = ptr;
        }
        ptr++; // Переміщення вказівника до наступного елементу
    }

    cout << "Найменший елемент: " << minVal << endl;
    cout << "Адреса найменшого елемента: " << minPtr << endl;

    return 0;
}
