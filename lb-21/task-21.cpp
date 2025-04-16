#include <iostream>
#include <iomanip> // for setting precision

class FlightBooking {

public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    // Save data to members
    this->id = id;
    this->capacity = capacity;
    this->reserved = reserved;
}

void FlightBooking::printStatus() {
    // print report here
    double percentage = 0.0;
    if (capacity > 0) {
        percentage = (static_cast<double>(reserved) / capacity) * 100.0;
    }
    std::cout << "Flight " << id << ": " << reserved << "/" << capacity
              << " (" << std::fixed << std::setprecision(0) << percentage << "%) seats reserved" << std::endl;
}

int main() {
    int reserved = 0;
    int capacity = 0;
    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;
    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;

    FlightBooking booking(1, capacity, reserved);
    booking.printStatus();

    return 0;
}
