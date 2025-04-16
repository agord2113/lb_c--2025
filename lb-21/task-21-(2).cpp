#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class FlightBooking {

public:
    FlightBooking(int id, int capacity, int reserved) : id(id), capacity(capacity), reserved(reserved) {}

    FlightBooking() : id(0), capacity(0), reserved(0) {}

    void printStatus() {
        cout << "Flight " << id << " " << reserved << "/" << capacity << " (" << (capacity == 0 ? 0 : (reserved * 100) / capacity) << "%) seats reserved" << endl;
    }

    bool reserveSeats(int number_of_seats) {
        if (id == 0) {
            return false; // Flight does not exist
        }
        if (reserved + number_of_seats <= capacity) {
            reserved += number_of_seats;
            return true;
        } else {
            return false; // Capacity reached
        }
    }

    bool cancelReservations(int number_of_seats) {
        if (id == 0) {
            return false; // Flight does not exist
        }
        if (reserved >= number_of_seats) {
            reserved -= number_of_seats;
            return true;
        } else {
            return false; // Cannot cancel more than reserved
        }
    }

    int getId() const { return id; }

private:
    int id;
    int capacity;
    int reserved;
};

int main() {
    FlightBooking booking[10];
    string command;

    while (true) {
        cout << "What would you like to do?: ";
        getline(cin, command);

        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "create") {
            int id, capacity;
            ss >> id >> capacity;
            bool flightCreated = false;
            for (int i = 0; i < 10; ++i) {
                if (booking[i].getId() == 0) {
                    booking[i] = FlightBooking(id, capacity, 0);
                    flightCreated = true;
                    break;
                }
            }
            if (!flightCreated) {
                cout << "Cannot perform this operation: Maximum number of flights reached" << endl;
            }

        } else if (action == "delete") {
            int id;
            ss >> id;
            bool flightDeleted = false;
            for (int i = 0; i < 10; ++i) {
                if (booking[i].getId() == id) {
                    booking[i] = FlightBooking(); // Reset the flight
                    flightDeleted = true;
                    break;
                }
            }
            if (!flightDeleted) {
                cout << "Cannot perform this operation: flight " << id << " not found" << endl;
            }

        } else if (action == "add") {
            int id, num;
            ss >> id >> num;
            bool flightFound = false;
            for (int i = 0; i < 10; ++i) {
                if (booking[i].getId() == id) {
                    if (!booking[i].reserveSeats(num)) {
                        cout << "Cannot perform this operation: capacity reached" << endl;
                    }
                    booking[i].printStatus();
                    flightFound = true;
                    break;
                }
            }
            if (!flightFound) {
                cout << "Cannot perform this operation: flight " << id << " not found" << endl;
            }

        } else if (action == "cancel") {
            int id, num;
            ss >> id >> num;
            bool flightFound = false;
            for (int i = 0; i < 10; ++i) {
                if (booking[i].getId() == id) {
                    if (!booking[i].cancelReservations(num)) {
                        cout << "Cannot perform this operation: cannot cancel more than reserved" << endl;
                    }
                    booking[i].printStatus();
                    flightFound = true;
                    break;
                }
            }
            if (!flightFound) {
                cout << "Cannot perform this operation: flight " << id << " not found" << endl;
            }
        } else if (action == "quit") {
            break;
        } else {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}
