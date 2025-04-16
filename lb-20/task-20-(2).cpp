#include <iostream>

class AdHocSquare {
public:
    AdHocSquare(double side) : side(side) {} // [cite: 12]

    void set_side(double side) { // [cite: 13]
        this->side = side;
    }

    double get_area() { // [cite: 13]
        return side * side;
    }

private:
    double side; // [cite: 13]
};

class LazySquare {
public:
    LazySquare(double side) : side(side), area(side * side), side_changed(false) {} // [cite: 13]

    void set_side(double side) { // [cite: 13]
        this->side = side;
        side_changed = true;
    }

    double get_area() { // [cite: 13]
        if (side_changed) { // [cite: 10, 11]
            area = side * side;
            side_changed = false; // [cite: 11]
        }
        return area; // [cite: 11]
    }

private:
    double side; // [cite: 13]
    double area; // [cite: 13]
    bool side_changed; // [cite: 13]
};

int main() {
    AdHocSquare adhocSquare(5.0);
    std::cout << "AdHocSquare Area: " << adhocSquare.get_area() << std::endl; // Output: 25

    adhocSquare.set_side(6.0);
    std::cout << "AdHocSquare Area: " << adhocSquare.get_area() << std::endl; // Output: 36

    LazySquare lazySquare(5.0);
    std::cout << "LazySquare Area: " << lazySquare.get_area() << std::endl;  // Output: 25

    lazySquare.set_side(6.0);
    std::cout << "LazySquare Area: " << lazySquare.get_area() << std::endl;  // Output: 36 (recalculated)

    lazySquare.set_side(7.0); // side_changed is now true
    std::cout << "LazySquare Area: " << lazySquare.get_area() << std::endl;  // Output: 49 (recalculated)

    std::cout << "LazySquare Area: " << lazySquare.get_area() << std::endl;  // Output: 49 (not recalculated)

    return 0;
}
