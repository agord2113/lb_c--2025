#include <iostream>

using namespace std;

// Insert your function here
void increment(int &var) { // [cite: 13] при виклику з одним аргументом (змінною int) збільшує змінну на 1;
    var++;
}

void increment(int &var, int i) { // [cite: 14] при виклику з двома аргументами (змінною int  виразом іnt) збільшує змінну на значення виразу.
    var += i;
}

int main(void) {

    int var = 0;

    for(int i = 0; i < 10; i++)
        if(i % 2)
            increment(var);
        else
            increment(var, i);

    cout << var << endl;

    return 0;
}
