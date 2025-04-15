#include <iostream>
#include <vector> // for using vector
using namespace std;

bool isLeap(int year) { 
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    return true;
  } else {
    return false;
  }
}

// Solution using switch statement
int monthLength(int year, int month) {
  switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      return 31;
    case 4: case 6: case 9: case 11:
      return 30;
    case 2:
      return isLeap(year) ? 29 : 28;
    default:
      return -1; // Indicate an error
  }
}

//Solution using vector
int monthLengthVector(int year, int month){
    vector<int> daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //index 0 is dummy
    if (month == 2 && isLeap(year)) {
        return 29;
    } else {
        return daysInMonth[month];
    }
}

int main(void) {
  cout << "Solution using switch: " << endl;
  for (int yr = 2000; yr < 2002; yr++) {
    for (int mo = 1; mo <= 12; mo++)
      cout << monthLength(yr, mo) << " ";
    cout << endl;
  }

  cout << "Solution using vector: " << endl;
   for (int yr = 2000; yr < 2002; yr++) {
    for (int mo = 1; mo <= 12; mo++)
      cout << monthLengthVector(yr, mo) << " ";
    cout << endl;
  }
  return 0;
}
