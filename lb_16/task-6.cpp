#include <iostream>
#include <ctime> // Для функцій часу та дати

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

// Функція для отримання поточної дати
Date today() {
    time_t t = time(0);   //Отримання поточний час
    tm* now = localtime(&t); //Перетворення на місцевий час

    return {now->tm_year + 1900, now->tm_mon + 1, now->tm_mday};
}

int main() {
    Date birthday;

    cout << "Enter your birthday (YYYY MM DD): ";
    cin >> birthday.year >> birthday.month >> birthday.day;

    Date current = today();

    // Обчисліть дні з епохи для обох дат
    tm bday_tm = {0, 0, 0, birthday.day, birthday.month - 1, birthday.year - 1900};
    tm curr_tm = {0, 0, 0, current.day, current.month - 1, current.year - 1900};

    time_t bday_time = mktime(&bday_tm);
    time_t curr_time = mktime(&curr_tm);

    if (bday_time == -1 || curr_time == -1) {
        cerr << "Error: Invalid date" << endl;
        return 1;
    }

    double diff_seconds = difftime(curr_time, bday_time);
    long long diff_days = diff_seconds / (60 * 60 * 24); //Перетворення секунд на дні

    cout << "Days between birthday and today: " << diff_days << endl;

    return 0;
}
