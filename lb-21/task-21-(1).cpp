#include <iostream>
#include <string>
#include <sstream>  // Needed for stringstream

class FlightBooking {

public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved) : id(id), capacity(capacity) {
    // Ensure reserved is not negative
    if (reserved < 0) {
        this->reserved = 0;
    } else {
        this->reserved = reserved;
    }

    // Limit reserved to 105% of capacity
    if (this->reserved > 1.05 * capacity) {
        this->reserved = static_cast<int>(1.05 * capacity); // Cast to int to truncate
    }
}

void FlightBooking::printStatus() {
    double occupancy = (static_cast<double>(reserved) / capacity) * 100.0;
    std::cout << "Flight " << id << ": " << reserved << "/" << capacity
              << " (" << static_cast<int>(occupancy) << "%) seats reserved" << std::endl;
}

bool FlightBooking::reserveSeats(int number_of_seats) {
    if (reserved + number_of_seats <= 1.05 * capacity) {
        reserved += number_of_seats;
        return true;
    } else {
        return false;
    }
}

bool FlightBooking::cancelReservations(int number_of_seats) {
    if (reserved >= number_of_seats) {
        reserved -= number_of_seats;
        return true;
    } else {
        return false;
    }
}

int main() {
    int capacity = 0;
    int reserved = 0;

    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;

    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;
    std::cin.ignore(); // Consume the newline character

    FlightBooking booking(1, capacity, reserved);
    std::string command;

    while (command != "quit") {
        booking.printStatus();
        std::cout << "What would you like to do?: ";
        std::getline(std::cin, command);

        std::stringstream ss(command);
        std::string action;
        int numSeats;

        ss >> action >> numSeats;

        if (action == "add") {
            if (!booking.reserveSeats(numSeats)) {
                std::cout << "Cannot perform this operation" << std::endl;
            }
        } else if (action == "cancel") {
            if (!booking.cancelReservations(numSeats)) {
                std::cout << "Cannot perform this operation" << std::endl;
            }
        } else if (action == "quit") {
            // Do nothing, the loop will terminate
        } else {
            std::cout << "Invalid command" << std::endl;
        }
    }

    return 0;
}
