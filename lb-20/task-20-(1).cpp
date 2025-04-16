#include <iostream>
#include <string>

using namespace std;

class Square {
private: // Hide the data members [cite: 5]
    double side;
    double area;

public:
    Square(double side);
    void set_side(double side); // Add the set_side method [cite: 6]
    void print(); // Change print to a method [cite: 8]
};

Square::Square(double side) {
    this->side = side;
    this->area = side * side;
}

void Square::set_side(double side) {
    if (side > 0) { // Ignore changes if side is less than 0 [cite: 7]
        this->side = side;
        this->area = side * side;
    }
}

void Square::print() { // Method implementation [cite: 8]
    cout << "Square: side=" << side << " area=" << area << endl;
}

int main() {
    Square s(4);
    s.print(); // Use the method
    s.set_side(2.0);
    s.print();
    s.set_side(-33.0); // This should be ignored
    s.print();

    return 0;
}
